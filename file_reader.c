//
// Created by root on 1/11/23.
//

#include "file_reader.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
//#include "tested_declarations.h"
//#include "rdebug.h"

#define BYTE 0x0f
#define BYTES_PER_ENTRY 32

char *remove_spaces(char *str)
{
    int i = 0, j = 0;
    while (str[i]){
        if (str[i] != ' ' && str[i]!='\n')  str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}

void makename_dot(char *res, char *left, char *right)
{
    left = remove_spaces(left);
    right = remove_spaces(right);
    strcat(res,left);
    if(strlen(right) > 0)   strcat(res,".");
    strcat(res,right);
}

int namecmp(const char *word1, const char *word2) {
    while (*word1)
    {
        if (toupper(*word1) != toupper(*word2)) break;
        word1++;
        word2++;
    }
    return *(const unsigned char*)word1 - *(const unsigned char*)word2;
}


enum fat_meaning get_fat12_meaning(uint16_t value) {
    if (value == 0x000) return FREE_CLUSTER;
    else if (value == 0xFF7) return CORRUPTED_SECTOR_CLUSTER;
    else if (value == 0x001) return ERR_CLUSTER;
    else if (value >= 0x002 && value <= 0xFF6) return USED_CLUSTER;
    else return EOC_CLUSTER;
}


uint16_t get_value(const uint8_t * const buff, uint16_t value) {
    uint16_t first = buff[(int)(1.5 * value)];
    uint16_t next = buff[(int)(1.5 * value + 1)];
    uint16_t result = 0;
    if (value % 2 == 0) {
        result |= ((next << 8) & 0x0f00);
        result |= (first & 0x00ff);
    } else {
        result |= ((next << 4) & 0x0ff0);
        result |= ((first >> 4) & 0x000f);
    }
    return result;
}

struct clusters_chain_t *get_chain_fat12(const void * const buffer, size_t size, uint16_t first_cluster) {
    if (buffer == NULL || size <= 0)
        return NULL;

    const uint8_t * const fat12_buf = buffer;
    if (get_fat12_meaning(first_cluster) == EOC_CLUSTER)
        return NULL;

    struct clusters_chain_t *chain = (struct clusters_chain_t *) calloc(1, sizeof(struct clusters_chain_t));
    if (chain == NULL)
        return NULL;

    uint16_t value = first_cluster;

    while(!0) {
        unsigned char EOC = 0;
        uint16_t *pom = (uint16_t *) realloc(chain->clusters, sizeof(uint16_t) * (chain->size + 1));
        if (pom == NULL) {
            free(chain->clusters);
            free(chain);
            return NULL;
        }
        chain->clusters = pom;
        chain->clusters[chain->size++] = value;
        switch(get_fat12_meaning(get_value(fat12_buf, value))) {
            case USED_CLUSTER: {
                if (value > size) return NULL;
                value = get_value(fat12_buf, value);
                break;
            }
            case EOC_CLUSTER: {
                EOC = 1;
                break;
            }
            default: {
                return NULL;
            }
        }
        if (EOC) return chain;
    }
}
struct disk_t* disk_open_from_file(const char* volume_file_name) {
    if (volume_file_name == NULL) {
        errno = EFAULT;
        return NULL;
    }

    struct disk_t *pdisk = (struct disk_t *) calloc(1, sizeof(struct disk_t));
    if (pdisk == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    pdisk->file = fopen(volume_file_name, "rb");
    if (pdisk->file == NULL) {
        free(pdisk);
        errno = ENOENT;
        return NULL;
    }

    return pdisk;
}

int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read) {
    if (pdisk == NULL || first_sector < 0 || buffer == NULL || sectors_to_read <= 0) {
        errno = EFAULT;
        return -1;
    }

    if (fseek(pdisk->file, first_sector * BYTES_PER_SECTOR, SEEK_SET)) {
        errno = ERANGE;
        return -1;
    }

    if (fread(buffer, BYTES_PER_SECTOR, sectors_to_read, pdisk->file) != (size_t) sectors_to_read) {
        errno = ERANGE;
        return -1;
    }
    return sectors_to_read;
}

int disk_close(struct disk_t* pdisk) {
    if (pdisk == NULL) {
        errno = EFAULT;
        return -1;
    }

    if(pdisk->file) fclose(pdisk->file);
    free(pdisk);
    return 0;
}
struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector) {
    if (pdisk == NULL) {
        errno = EFAULT;
        return NULL;
    }

    struct volume_t* pvolume = (struct volume_t*) calloc(1, sizeof(struct volume_t));
    if (pvolume == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    pvolume->disk = pdisk;

    pvolume->super = (struct super_t *) calloc(1, sizeof(struct super_t));
    if (pvolume->super == NULL) {
        fat_close(pvolume);
        errno = ENOMEM;
        return NULL;
    }

    struct super_t* boot = pvolume->super;

    if(disk_read(pdisk, (int32_t)first_sector, boot, 1) != 1) {
        fat_close(pvolume);
        errno = EINVAL;
        return NULL;
    }

    if (boot->bytes_per_sector <= 0) {
        fat_close(pvolume);
        errno = EINVAL;
        return NULL;
    }

    pvolume->total_sectors = (boot->logical_sectors16 == 0) ? boot->logical_sectors32 : boot->logical_sectors16;
    pvolume->fat_size = boot->sectors_per_fat;
    pvolume->root_dir_sectors = ((boot->root_dir_capacity * 32) + (boot->bytes_per_sector - 1)) / boot->bytes_per_sector;
    pvolume->first_data_sector = boot->reserved_sectors + (boot->fat_count * pvolume->fat_size) + pvolume->root_dir_sectors;
    pvolume->first_fat_sector = boot->reserved_sectors;
    pvolume->data_sectors = pvolume->total_sectors - (boot->reserved_sectors + (boot->fat_count * pvolume->fat_size) + pvolume->root_dir_sectors);
    pvolume->total_clusters = pvolume->data_sectors / boot->sectors_per_cluster;

    int error = check(pvolume);
    if (error == 2) {
        fat_close(pvolume);
        errno = ENOMEM;
        return NULL;
    }
    if (error == 1 || pvolume->super->mag != 0xaa55) {
        fat_close(pvolume);
        errno = EINVAL;
        return NULL;
    }

    pvolume->fat = (uint8_t *) calloc(pvolume->fat_size * pvolume->super->bytes_per_sector, sizeof(uint8_t));
    if (pvolume->fat == NULL) {
        fat_close(pvolume);
        errno = ENOMEM;
        return NULL;
    }

    if (disk_read(pvolume->disk, pvolume->first_fat_sector, pvolume->fat, pvolume->fat_size) != pvolume->fat_size) {
        fat_close(pvolume);
        errno = EINVAL;
        return NULL;
    }

    return pvolume;
}

int fat_close(struct volume_t* pvolume) {
    if (pvolume == NULL) {
        errno = EFAULT;
        return -1;
    }

    if (pvolume->super != NULL) free(pvolume->super);

    if (pvolume->fat != NULL) free(pvolume->fat);

    free(pvolume);
    return 0;
}

int check(struct volume_t* pvolume) {
    if (pvolume == NULL || pvolume->super->fat_count != 2)
        return 1;

    void* fat1 = calloc(pvolume->fat_size * pvolume->super->bytes_per_sector, sizeof(uint8_t));
    if (fat1 == NULL) {
        return 2;
    }

    void* fat2 = calloc(pvolume->fat_size * pvolume->super->bytes_per_sector, sizeof(uint8_t));
    if (fat2 == NULL) {
        free(fat1);
        return 2;
    }

    if (disk_read(pvolume->disk, pvolume->first_fat_sector, fat1, pvolume->fat_size) != pvolume->fat_size) {
        free(fat1);
        free(fat2);
        return 1;
    }

    if (disk_read(pvolume->disk, pvolume->first_fat_sector + pvolume->fat_size, fat2, pvolume->fat_size) != pvolume->fat_size) {
        free(fat1);
        free(fat2);
        return 1;
    }

    if (memcmp(fat1, fat2, pvolume->fat_size * pvolume->super->bytes_per_sector) != 0) {
        free(fat1);
        free(fat2);
        return 1;
    }

    free(fat1);
    free(fat2);
    return 0;
}
struct file_t* file_open(struct volume_t* pvolume, const char* file_name) {
    if (pvolume == NULL || file_name == NULL) {
        errno = EFAULT;
        return NULL;
    }

    if (!strchr(file_name, '\\')) {
        struct dir_t* dir = dir_open(pvolume, "\\");
        struct dir_entry_t entry;
        while(1) {
            int err = dir_read(dir, &entry);
            if (err) {
                dir_close(dir);
                errno = ENOENT;
                return NULL;
            }
            if (namecmp(file_name, entry.name) == 0  || (entry.has_long_name && namecmp(file_name, entry.long_name) == 0)) break;
        }

        dir_close(dir);
        if (entry.is_directory) {
            errno = EISDIR;
            return NULL;
        }

        struct file_t* file = (struct file_t *) calloc(1, sizeof(struct file_t));
        if (file == NULL) {
            errno = ENOMEM;
            return NULL;
        }

        file->load_cluster = (char *) calloc(pvolume->super->sectors_per_cluster * pvolume->super->bytes_per_sector, sizeof(char));
        if (file->load_cluster == NULL) {
            file_close(file);
            errno = ENOMEM;
            return NULL;
        }

        file->cluster_chain = get_chain_fat12(pvolume->fat, pvolume->fat_size*pvolume->super->bytes_per_sector, entry.first_cluster);
        file->offset = 0;
        file->volume = pvolume;
        file->current_cluster = 0;
        file->size = (int32_t) entry.file_size;

        if (disk_read(pvolume->disk, pvolume->first_data_sector + (*file->cluster_chain->clusters - 2) * pvolume->super->sectors_per_cluster, file->load_cluster, pvolume->super->sectors_per_cluster) != pvolume->super->sectors_per_cluster) {
            errno = EFAULT;
            return NULL;
        }
        return file;
    }
    else {
        char* path = strdup(file_name);
        if (path == NULL) {
            errno = ENOMEM;
            return NULL;
        }
        char* actual_file_name;
        char * last_s = strrchr(path, '\\');
        path[last_s - path] = '\0';
        actual_file_name = strrchr(file_name, '\\') + 1;

        struct dir_t* dir = dir_open(pvolume, path);
        if (dir == NULL) {
            free(path);
            errno = ENOENT;
            return NULL;
        }
        free(path);

        struct dir_entry_t entry;
        while(1) {
            int error = dir_read(dir, &entry);
            if (error) {
                dir_close(dir);
                errno = ENOENT;
                return NULL;
            }

            if (namecmp(actual_file_name, entry.name) == 0  || (entry.has_long_name && namecmp(actual_file_name, entry.long_name) == 0)) break;
        }

        dir_close(dir);
        if (entry.is_directory) {
            errno = EISDIR;
            return NULL;
        }

        struct file_t* file = (struct file_t *) calloc(1, sizeof(struct file_t));
        if (file == NULL) {
            errno = ENOMEM;
            return NULL;
        }

        file->load_cluster = (char *) calloc(pvolume->super->sectors_per_cluster * pvolume->super->bytes_per_sector, sizeof(char));
        if (file->load_cluster == NULL) {
            file_close(file);
            errno = ENOMEM;
            return NULL;
        }

        file->cluster_chain = get_chain_fat12(pvolume->fat, pvolume->fat_size*pvolume->super->bytes_per_sector, entry.first_cluster);
        file->offset = 0;
        file->volume = pvolume;
        file->current_cluster = 0;
        file->size = (int32_t) entry.file_size;

        if (disk_read(pvolume->disk, pvolume->first_data_sector + (*file->cluster_chain->clusters - 2) * pvolume->super->sectors_per_cluster, file->load_cluster, pvolume->super->sectors_per_cluster) != pvolume->super->sectors_per_cluster) {
            errno = EFAULT;
            return NULL;
        }

        return file;
    }
}

int file_close(struct file_t* stream) {
    if (stream == NULL) {
        errno = EFAULT;
        return -1;
    }

    if (stream->load_cluster != NULL) {
        free(stream->load_cluster);
    }

    if (stream->cluster_chain != NULL) {
        if (stream->cluster_chain->clusters != NULL)
            free(stream->cluster_chain->clusters);

        free(stream->cluster_chain);
    }

    free(stream);
    return 0;
}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream) {
    if (ptr == NULL || size == 0 || nmemb == 0 || stream == NULL) {
        errno = EFAULT;
        return -1;
    }

    for (size_t i = 0; i < nmemb * size; i++) {
        if (stream->offset + stream->current_cluster * stream->volume->super->sectors_per_cluster * stream->volume->super->bytes_per_sector >= stream->size) {
            return i / size;
        }

        if (stream->offset == stream->volume->super->sectors_per_cluster * stream->volume->super->bytes_per_sector) {
            file_seek(stream, stream->offset + stream->current_cluster * stream->volume->super->sectors_per_cluster * stream->volume->super->bytes_per_sector, SEEK_SET);
        }

        *((char *)ptr + i) = stream->load_cluster[stream->offset];
        stream->offset++;
    }

    return nmemb;
}

int32_t file_seek(struct file_t* stream, int32_t offset, int whence) {
    if (stream == NULL) {
        errno = EFAULT;
        return -1;
    }

    switch (whence) {
        case SEEK_SET: {
            if (offset < 0 || offset > (int32_t) stream->size) {
                errno = ENXIO;
                return -1;
            }

            int num_cluster = offset / (stream->volume->super->sectors_per_cluster * stream->volume->super->bytes_per_sector);
            int num_offset = offset % (stream->volume->super->sectors_per_cluster * stream->volume->super->bytes_per_sector);

            if (disk_read(stream->volume->disk, stream->volume->first_data_sector + (*(stream->cluster_chain->clusters + num_cluster) - 2) * stream->volume->super->sectors_per_cluster, stream->load_cluster, stream->volume->super->sectors_per_cluster) != stream->volume->super->sectors_per_cluster) {
                errno = ENXIO;
                return -1;
            }
            stream->current_cluster = num_cluster;
            stream->offset = num_offset;
            break;
        }

        case SEEK_END: {
            return file_seek(stream, offset + stream->size, SEEK_SET);
        }

        case SEEK_CUR: {
            return file_seek(stream, offset + stream->offset + stream->current_cluster * stream->volume->super->sectors_per_cluster * stream->volume->super->bytes_per_sector, SEEK_SET);
        }
        default: {
            errno = EINVAL;
            return -1;
        }
    }
    return offset;
}
char * handle_path(char * dir_path) {
    struct {
        char * single_path[40];
        int size;
    } stack;

    stack.size = 0;
    for (char * single = strtok(dir_path, "\\"); single; single = strtok(NULL, "\\")) {
        if (strcmp(single, ".") == 0) continue;
        else if (strcmp(single, "..") == 0) {
            if (stack.size == 0) return NULL;
            else {
                stack.size--;
                free(stack.single_path[stack.size]);
            }
        }
        else {
            stack.single_path[stack.size] = strdup(single);
            stack.size++;
        }
    }

    size_t result_len = 2;
    for (int i = 0; i < stack.size; i++) {
        result_len += strlen(stack.single_path[i]) + 2;
    }

    char *result_string = calloc(result_len, sizeof(char));

    for (int i = 0; i < stack.size; i++) {
        strcat(result_string, "\\");
        strcat(result_string, stack.single_path[i]);
        free(stack.single_path[i]);
    }
    return result_string;
}

struct dir_t* open_root_dir(struct volume_t* pvolume) {
    struct dir_t *dir = (struct dir_t *) calloc(1, sizeof(struct dir_t));
    if (dir == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    dir->load_sectors = calloc(pvolume->root_dir_sectors, pvolume->super->bytes_per_sector);
    if (dir->load_sectors == NULL) {
        dir_close(dir);
        errno = ENOMEM;
        return NULL;
    }

    if (disk_read(pvolume->disk, pvolume->first_fat_sector + 2 * pvolume->fat_size, dir->load_sectors, pvolume->root_dir_sectors) != pvolume->root_dir_sectors) {
        dir_close(dir);
        errno = ENOENT;
        return NULL;
    }

    dir->size_in_sectors = pvolume->root_dir_sectors;
    dir->offset = 0;
    dir->volume = pvolume;
    dir->end = 0;
    return dir;
}

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path) {
    if (pvolume == NULL || dir_path == NULL) {
        errno = EFAULT;
        return NULL;
    }

    if (strcmp(dir_path, "\\") == 0) return open_root_dir(pvolume);
    else {
        struct dir_t *dir = NULL;
        char * pom = strdup(dir_path);
        char * dir_path_for_parse = handle_path(pom);
        free(pom);

        for (char * dir_name = strtok(dir_path_for_parse, "\\"); dir_name != NULL; dir_name = strtok(NULL, "\\")) {
            if (dir == NULL) dir = open_root_dir(pvolume);

            struct dir_entry_t entry;
            while(1) {
                int err = dir_read(dir, &entry);
                if (err) {
                    free(dir_path_for_parse);
                    dir_close(dir);
                    errno = ENOENT;
                    return NULL;
                }
                if (namecmp(dir_name, entry.name) == 0  || (entry.has_long_name && namecmp(dir_name, entry.long_name) == 0)) break;
            }
            dir_close(dir);

            if (!entry.is_directory) {
                free(dir_path_for_parse);
                errno = EFAULT;
                return NULL;
            }

            struct clusters_chain_t *clusters_chain = get_chain_fat12(pvolume->fat, pvolume->fat_size * pvolume->super->bytes_per_sector, entry.first_cluster);

            struct dir_t *new_dir = (struct dir_t *) calloc(1, sizeof(struct dir_t));

            new_dir->load_sectors = calloc(clusters_chain->size, pvolume->super->bytes_per_sector * pvolume->super->sectors_per_cluster);

            for (size_t i = 0; i < clusters_chain->size; i++) {
                if (disk_read(pvolume->disk, pvolume->first_data_sector + (*(clusters_chain->clusters + i) - 2) * pvolume->super->sectors_per_cluster, (char *) new_dir->load_sectors + i * pvolume->super->sectors_per_cluster * pvolume->super->bytes_per_sector, pvolume->super->sectors_per_cluster) != pvolume->super->sectors_per_cluster) {
                    errno = EFAULT;
                    return NULL;
                }
            }

            new_dir->offset = 0;
            new_dir->end = 0;
            new_dir->size_in_sectors = (int)(pvolume->super->sectors_per_cluster * clusters_chain->size);
            new_dir->volume = pvolume;

            free(clusters_chain->clusters);
            free(clusters_chain);

            dir = new_dir;
        }
        free(dir_path_for_parse);
        return dir;
    }
}

int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry) {
    if (pdir == NULL || pentry == NULL) {
        errno = EFAULT;
        return -1;
    }

    if (pdir->end == 1) return 1;

    if (pdir->offset * BYTES_PER_ENTRY > pdir->size_in_sectors * pdir->volume->super->bytes_per_sector) {
        errno = ENXIO;
        return -1;
    }

    struct dir_super_t *dir_super;

    do {
        dir_super = (struct dir_super_t *) ((unsigned long) (pdir->load_sectors) + pdir->offset * BYTES_PER_ENTRY);
        if (dir_super == NULL) {
            errno = EIO;
            return -1;
        }

        if ((unsigned char)dir_super->name[0] == 0x00) {
            pdir->end = 1;
            return 1;
        }

        pdir->offset++;
    } while ((unsigned char)dir_super->name[0] == 0xe5 || (unsigned char)dir_super->name[11] == BYTE || dir_super->volume);

    pentry->size = dir_super->size;
    pentry->is_archived = dir_super->archive;
    pentry->is_directory = dir_super->directory;
    pentry->is_hidden = dir_super->hidden;
    pentry->is_readonly = dir_super->read_only;
    pentry->is_system = dir_super->system;
    pentry->first_cluster = dir_super->first_cluster_low_bits;
    pentry->file_size = dir_super->size;
    pentry->has_long_name = 0;
    memset(pentry->long_name, 0, 200);

    int name_len = 0;
    int ext_len = 0;
    while (dir_super->name[name_len] != ' ' && name_len < 8) {
        name_len++;
    }
    while (dir_super->name[8 + ext_len] != ' ' && ext_len < 3) {
        ext_len++;
    }

    memset(pentry->name, 0, 13);
    int j;
    for (j = 0; j < name_len; j++) pentry->name[j] = dir_super->name[j];
    if (ext_len > 0) {
        pentry->name[j] = '.';
        for (int i = 0; i < ext_len; i++) {
            pentry->name[name_len + 1 + i] = dir_super->ext[i];
        }
    }

    struct dir_super_t* dir_prev = (struct dir_super_t *) ((unsigned long) (pdir->load_sectors) + (pdir->offset - 2) * BYTES_PER_ENTRY);
    if (((unsigned char *)dir_prev)[11] == BYTE) {
        pentry->has_long_name = 1;
        int num = 1;

        while (((unsigned char *)dir_prev)[11] == BYTE) {
            dir_prev = (struct dir_super_t *) ((unsigned long) (pdir->load_sectors) + (pdir->offset - (2 + num)) * BYTES_PER_ENTRY);
            num++;
        }
        num--;

        for (int i = 0; i < num; i++) {
            dir_prev = (struct dir_super_t *) ((unsigned long) (pdir->load_sectors) + (pdir->offset - (2 + i)) * BYTES_PER_ENTRY);
            strncat(pentry->long_name, (char *)dir_prev + 1, 1);
            strncat(pentry->long_name, (char *)dir_prev + 3, 1);
            strncat(pentry->long_name, (char *)dir_prev + 5, 1);
            strncat(pentry->long_name, (char *)dir_prev + 7, 1);
            strncat(pentry->long_name, (char *)dir_prev + 9, 1);
            strncat(pentry->long_name, (char *)dir_prev + 14, 1);
            strncat(pentry->long_name, (char *)dir_prev + 16, 1);
            strncat(pentry->long_name, (char *)dir_prev + 18, 1);
            strncat(pentry->long_name, (char *)dir_prev + 20, 1);
            strncat(pentry->long_name, (char *)dir_prev + 22, 1);
            strncat(pentry->long_name, (char *)dir_prev + 24, 1);
            strncat(pentry->long_name, (char *)dir_prev + 28, 1);
            strncat(pentry->long_name, (char *)dir_prev + 30, 1);
        }

        int i = 0;
        while((unsigned char)pentry->long_name[i] != BYTE && i < num * BYTES_PER_ENTRY) i++;
        pentry->long_name[i] = '\0';
    }

    return 0;
}

int dir_close(struct dir_t* pdir) {
    if (pdir == NULL) {
        errno = EFAULT;
        return -1;
    }

    if (pdir->load_sectors != NULL) free(pdir->load_sectors);
    free(pdir);
    return 0;
}



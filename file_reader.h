//
// Created by root on 1/11/23.
//

#ifndef FAT12_FILE_READER_H
#define FAT12_FILE_READER_H

#include <stdint-gcc.h>
#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <errno.h>
#define BYTES_PER_SECTOR 512

int namecmp(const char *word1, const char *word2);

struct clusters_chain_t {
    uint16_t *clusters;
    size_t size;
};

enum fat_meaning {
    FREE_CLUSTER,
    ERR_CLUSTER,
    USED_CLUSTER,
    CORRUPTED_SECTOR_CLUSTER,
    EOC_CLUSTER,
};


enum fat_meaning get_fat12_meaning(uint16_t value);
struct clusters_chain_t *get_chain_fat12(const void * const buffer, size_t size, uint16_t first_cluster);

struct disk_t {
    FILE* file;
};

struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);

int disk_close(struct disk_t* pdisk);
struct super_t {
    uint8_t  jump_code[3];
    char     oem_name[8];
    uint16_t bytes_per_sector;
    uint8_t  sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t  fat_count;
    uint16_t root_dir_capacity;
    uint16_t logical_sectors16;
    uint8_t  media_type;
    uint16_t sectors_per_fat;
    uint16_t sectors_per_track;
    uint16_t tracks_per_cylinder;
    uint32_t hidden_sectors;
    uint32_t logical_sectors32;
    uint8_t  media_id;
    uint8_t  head;
    uint8_t  signature;
    uint32_t serial_number;
    char     volume_label[11];
    char     fsid[8];
    uint8_t  boot_code[448];
    uint16_t mag;
} __attribute__ (( packed ));

struct volume_t {
    struct super_t* super;
    struct disk_t* disk;
    uint8_t *fat;
    uint16_t total_sectors;
    int32_t fat_size;
    uint16_t root_dir_sectors;
    uint16_t first_data_sector;
    uint16_t first_fat_sector;
    uint32_t data_sectors;
    uint32_t total_clusters;
} __attribute__ (( packed ));

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);

int check(struct volume_t* pvolume);

struct file_t {
    char* load_cluster;
    uint16_t offset;
    struct clusters_chain_t* cluster_chain;
    uint8_t current_cluster;
    struct volume_t* volume;
    int32_t size;
};

struct file_t* file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);

struct dir_super_t {
    char name[8];
    char ext[3];
    struct {
        uint8_t read_only: 1;
        uint8_t hidden: 1;
        uint8_t system: 1;
        uint8_t volume: 1;
        uint8_t directory: 1;
        uint8_t archive: 1;
        uint8_t unused: 2;
    } __attribute__ (( packed ));
    uint8_t reserved;
    uint8_t creation_time;
    struct {
        uint8_t hour: 5;
        uint8_t minutes: 6;
        uint8_t seconds: 5;
    } __attribute__ (( packed ));
    struct {
        uint8_t year: 7;
        uint8_t month: 4;
        uint8_t day: 5;
    } __attribute__ (( packed ));
    struct {
        uint8_t year_access: 7;
        uint8_t month_access: 4;
        uint8_t day_access: 5;
    } __attribute__ (( packed ));
    uint16_t first_cluster_high_bits;
    struct {
        uint8_t hour_modified: 5;
        uint8_t minutes_modified: 6;
        uint8_t seconds_modified: 5;
    } __attribute__ (( packed ));
    struct {
        uint8_t year_modified: 7;
        uint8_t month_modified: 4;
        uint8_t day_modified: 5;
    } __attribute__ (( packed ));
    uint16_t first_cluster_low_bits;
    uint32_t size;
} __attribute__ (( packed ));

struct dir_entry_t {
    char name[13];
    uint32_t size;
    unsigned char is_archived: 1;
    unsigned char is_readonly: 1;
    unsigned char is_system: 1;
    unsigned char is_hidden: 1;
    unsigned char is_directory: 1;
    uint16_t first_cluster;
    uint32_t file_size;

    int has_long_name;
    char long_name[200];
};

struct dir_t {
    void* load_sectors;
    int offset;
    int size_in_sectors;
    int end;

    struct volume_t* volume;
};
char * handle_path(char * dir_path);

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);

#endif //FAT12_FILE_READER_H

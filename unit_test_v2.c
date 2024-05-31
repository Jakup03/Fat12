/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Jakub Sońta
 * Test wygenerowano automatycznie o 2023-01-17 15:25:25.686481
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("MOON.TXT");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("band.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(5120, 1);
                char expected_filecontent[5121] = "";
        
                strcat(expected_filecontent, "e eyes are held\nStill in this depth below.  But search around\nThe circles, to the furthest, till thou spy\nSeated in state, the queen, that of this realm\nIs sovran.\"  Straight mine eyes I rais\'d; and bright,\nAs, at the birth of morn, the eastern clime\nAbove th\' horizon, where the sun declines;\nTo mine eyes, that upward, as from vale\nTo mountain sped, at th\' extreme bound, a part\nExcell\'d in lustre all the front oppos\'d.\nAnd as the glow burns ruddiest o\'er the wave,\nThat waits the sloping beam, which Phaeton\nIll knew to guide, and on each part the light\nDiminish\'d fades, intensest in the midst;\nSo burn\'d the peaceful oriflamb, and slack\'d\nOn every side the living flame decay\'d.\nAnd in that midst their sportive pennons wav\'d\nThousands of angels; in resplendence each\nDistinct, and quaint adornment. At their glee\nAnd carol, smil\'d the Lovely One of heav\'n,\nThat joy was in the eyes of all the blest.\n     Had I a tongue in eloquence as rich,\nAs is the colouring in fancy\'s loom,\n\'T were all too poor to utter the least part\nOf that enchantment.  When he saw mine eyes\nIntent on her, that charm\'d him, Bernard gaz\'d\nWith so exceeding fondness, as infus\'d\nArdour into my breast, unfelt before.\n\n\n\nCANTO XXXII\n\nFreely the sage, though wrapt in musings high,\nAssum\'d the teacher\'s part, and mild began:\n\"The wound, that Mary clos\'d, she open\'d first,\nWho sits so beautiful at Mary\'s feet.\nThe third in order, underneath her, lo!\nRachel with Beatrice. Sarah next,\nJudith, Rebecca, and the gleaner maid,\nMeek ancestress of him, who sang the songs\nOf sore repentance in his sorrowful mood.\nAll, as I name them, down from deaf to leaf,\nAre in gradation throned on the rose.\nAnd from the seventh step, successively,\nAdown the breathing tresses of the flow\'r\nStill doth the file of Hebrew dames proceed.\nFor these are a partition wall, whereby\nThe sacred stairs are sever\'d, as the faith\nIn Christ divides them.  On this part, where blooms\nEach leaf in full maturity, are set\nSuch as in Christ, or ere he came, believ\'d.\nOn th\' other, where an intersected space\nYet shows the semicircle void, abide\nAll they, who look\'d to Christ already come.\nAnd as our Lady on her glorious stool,\nAnd they who on their stools beneath her sit,\nThis way distinction make: e\'en so on his,\nThe mighty Baptist that way marks the line\n(He who endur\'d the desert and the pains\nOf martyrdom, and for two years of hell,\nYet still continued holy), and beneath,\nAugustin, Francis, Benedict, and the rest,\nThus far from round to round.  So heav\'n\'s decree\nForecasts, this garden equally to fill.\nWith faith in either view, past or to come,\nLearn too, that downward from the step, which cleaves\nMidway the twain compartments, none there are\nWho place obtain for merit of their own,\nBut have through others\' merit been advanc\'d,\nOn set conditions: spirits all releas\'d,\nEre for themselves they had the power to choose.\nAnd, if thou mark and listen to them well,\nTheir childish looks and voice declare as much.\n     \"Here, silent as thou art, I know thy doubt;\nAnd gladly will I loose the knot, wherein\nThy subtle thoughts have bound thee.  From this realm\nExcluded, chalice no entrance here may find,\nNo more shall hunger, thirst, or sorrow can.\nA law immutable hath establish\'d all;\nNor is there aught thou seest, that doth not fit,\nExactly, as the finger to the ring.\nIt is not therefore without cause, that these,\nO\'erspeedy comers to immortal life,\nAre different in their shares of excellence.\nOur Sovran Lord--that settleth this estate\nIn love and in delight so absolute,\nThat wish can dare no further--every soul,\nCreated in his joyous sight to dwell,\nWith grace at pleasure variously endows.\nAnd for a proof th\' effect may well suffice.\nAnd \'t is moreover most expressly mark\'d\nIn holy scripture, where the twins are said\nTo, have struggled in the womb.  Therefore, as grace\nInweaves the coronet, so every brow\nWeareth its proper hue of orient light.\nAnd merely in respect to his prime gift,\nNot in reward of meritorious deed,\nHath each his several degree assign\'d.\nIn early times with their own innocence\nMore was not ");
    strcat(expected_filecontent, "wanting, than the parents\' faith,\nTo save them: those first ages past, behoov\'d\nThat circumcision in the males should imp\nThe flight of innocent wings:  but since the day\nOf grace hath come, without baptismal rites\nIn Christ accomplish\'d, innocence herself\nMust linger yet below.  Now raise thy view\nUnto the visage most resembling Christ:\nFor, in her splendour only, shalt thou win\nThe pow\'r to look on him.\"  Forthwith I saw\nSuch floods of gladness on her visage shower\'d,\nFrom holy spirits, winging that profound;\nThat, whatsoever I had yet beheld,\nHad not so much suspended me with wonder,\nOr shown me such similitude of God.\nAnd he, who had to her descended, once,\nOn earth, now hail\'d in heav\'n; and on pois\'d wing.\n\"Ave, Maria, Gratia Plena,\" sang:\nTo whose sweet anthem all the blissful court,\nFrom all parts answ\'ring, rang: that holier joy\nBrooded the deep serene.  \"Father rever\'d:\nWho deign\'st, for me, to quit the pleasant place,\nWherein thou sittest, by eternal lot!\nSay, who that angel is, that with such glee\n");
                
        
                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "TAKE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 5120, file);
                test_error(size == 5120, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5120 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5120);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 5120);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(6685, 1);
                char expected_filecontent[6686] = "";
        
                strcat(expected_filecontent, "But who is he observes them?  None; not he,\nWho goes before, the shepherd of the flock,\nWho chews the cud but doth not cleave the hoof.\nTherefore the multitude, who see their guide\nStrike at the very good they covet most,\nFeed there and look no further.  Thus the cause\nIs not corrupted nature in yourselves,\nBut ill-conducting, that hath turn\'d the world\nTo evil.  Rome, that turn\'d it unto good,\nWas wont to boast two suns, whose several beams\nCast light on either way, the world\'s and God\'s.\nOne since hath quench\'d the other; and the sword\nIs grafted on the crook; and so conjoin\'d\nEach must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and the Po\nTheir waters roll, was once the residence\nOf courtesy and velour, ere the day,\nThat frown\'d on Frederick; now secure may pass\nThose limits, whosoe\'er hath left, for shame,\nTo talk with good men, or come near their haunts.\nThree aged ones are still found there, in whom\nThe old time chides the new: these deem it long\nEre God restore them to a better world:\nThe good Gherardo, of Palazzo he\nConrad, and Guido of Castello, nam\'d\nIn Gallic phrase more fitly the plain Lombard.\nOn this at last conclude.  The church of Rome,\nMixing two governments that ill assort,\nHath miss\'d her footing, fall\'n into the mire,\nAnd there herself and burden much defil\'d.\"\n     \"O Marco!\" I replied, shine arguments\nConvince me: and the cause I now discern\nWhy of the heritage no portion came\nTo Levi\'s offspring.  But resolve me this\nWho that Gherardo is, that as thou sayst\nIs left a sample of the perish\'d race,\nAnd for rebuke to this untoward age?\"\n     \"Either thy words,\" said he, \"deceive; or else\nAre meant to try me; that thou, speaking Tuscan,\nAppear\'st not to have heard of good Gherado;\nThe sole addition that, by which I know him;\nUnless I borrow\'d from his daughter Gaia\nAnother name to grace him.  God be with you.\nI bear you company no more.  Behold\nThe dawn with white ray glimm\'ring through the mist.\nI must away--the angel comes--ere he\nAppear.\"  He said, and would not hear me more.\n\n\n\nCANTO XVII\n\nCall to remembrance, reader, if thou e\'er\nHast, on a mountain top, been ta\'en by cloud,\nThrough which thou saw\'st no better, than the mole\nDoth through opacous membrane; then, whene\'er\nThe wat\'ry vapours dense began to melt\nInto thin air, how faintly the sun\'s sphere\nSeem\'d wading through them; so thy nimble thought\nMay image, how at first I re-beheld\nThe sun, that bedward now his couch o\'erhung.\n     Thus with my leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, ");
    strcat(expected_filecontent, "outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing it loves,\nAll fro");
                
        
                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "DESCRIBE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6685, file);
                test_error(size == 6685, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6685 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6685);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6685);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(7242, 1);
                char expected_filecontent[7243] = "";
        
                strcat(expected_filecontent, "roverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye commands\nFor sight no obstacle found here, nor shade, But all sunshine.\nMilton, P. l. b. iii.  616.\n\nv. 135.  Of the great Harry.]  The Emperor Henry VII, who died in\n1313.\n\nv. 141.  He.]  Pope Clement V. See Canto XXVII.  53.\n\nv. 145.  Alagna\'s priest.]  Pope Boniface VIII.  Hell, Canto XIX.\n\n79.\n\nCANTO XXXI\n\nv. 6.  Bees.]  Compare Homer, Iliad, ii.  87. Virg.  Aen. I. 430,\nand Milton, P. L. b. 1.  768.\n\nv. 29.  Helice.]  Callisto, and her son Arcas, changed into the\nconstellations of the Greater Bear and Arctophylax, or Bootes.\nSee Ovid, Met.  l. ii. fab. v. vi.\n\nv. 93.  Bernard.]  St. Bernard, the venerable abbot of Clairvaux,\nand the great promoter of the second crusade, who died A.D. 1153,\nin his sixty-third year.  His sermons are called by Henault,\n\"chefs~d\'oeuvres de sentiment et de force.\"  Abrege Chron. de\nl\'Hist.  de Fr. 1145. They have even been preferred to al1 the\nproductions of the ancients, and the author has been termed the\nlast of the fathers of the church. It is uncertain whether they\nwere not delivered originally in the French tongue.\n\nThat the part he acts in the present Poem should be assigned to\nhim. appears somewhat remarkable, when we consider that he\nseverely censured the new festival established in honour of the\nImmaculate Conception of the virgin, and opposed the doctrine\nitself with the greatest vigour, as it supposed her being\nhonoured with a privilegewhich belonged to Christ Alone Dr.\nMaclaine\'s Mosheim, v. iii. cent. xii. p. ii. c. 3 - 19.\n\nv. 95.  Our Veronica ] The holy handkerchief, then preserved at\nRome, on which the countenance of our Saviour was supposed to\nhave be");
    strcat(expected_filecontent, "en imprest.\n\nv. 101.  Him.]  St. Bernard.\n\nv. 108.  The queen.]  The Virgin Mary.\n\nv. 119.  Oriflamb.]  Menage on this word quotes the Roman des\nRoyau\n-Iignages of Guillaume Ghyart.\nOriflamme est une banniere\nDe cendal roujoyant et simple\nSans portraiture d\'autre affaire,\n\nCANTO XXXII\n\nv. 3.  She.]  Eve.\n\nv. 8.  Ancestress.]  Ruth, the ancestress of David.\n\nv. 60.  In holy scripture.]  Gen. c. xxv.  22.\nv. 123.  Lucia.]  See Hell, Canto II.  97.\n\nCANTO XXXIII\n\nv. 63.  The Sybil\'s sentence.]  Virg.  Aen.  iii. 445.\n\nv. 89.  One moment.]  \"A moment seems to me more tedious, than\nfive-and-twenty ages would have appeared to the Argonauts, when\nthey had resolved on their expedition.\n\nv. 92.  Argo\'s shadow]\nQuae simul ac rostro ventosnm proscidit aequor,\nTortaque remigio spumis incanduit unda,\nEmersere feri candenti e gurgite vultus\nAequoreae monstrum Nereides admirantes.\nCatullus, De Nupt.  Pel.  et Thet.  15.\n\nv. 109.  Three orbs of triple hue, clipt in one bound.]  The\nTrinity.\n\nv. 118.  That circling.]  The second of the circles, \"Light of\nLight,\" in which he dimly beheld the mystery of the incarnation.\n\n\n\n\n\nEnd Paradise.\n\n\n\n\n\nPREFACE\n\nIn the years 1805 and 1806, I published the first part of the\nfollowing translation, with the text of the original.  Since that\nperiod, two impressions of the whole of the Divina Commedia, in\nItalian, have made their appearance in this country.  It is not\nnecessary that I should add a third: and I am induced to hope\nthat the Poem, even in the present version of it, may not be\nwithout interest for the mere English reader.\n\nThe translation of the second and third parts, \"The Purgatory\"\nand \"The Paradise,\" was begun long before the first, and as early\nas the year 1797; but, owing to many interruptions, not concluded\ntill the summer before last.  On a retrospect of the time and\nexertions that have been thus employed, I do not regard those\nhours as the least happy of my  life, during which (to use the\neloquent language of Mr. Coleridge) \"my individual recollections\nhave been suspended, and lulled to sleep amid the music of nobler\nthoughts;\"  nor that study as misapplied, which has familiarized\nme with one of the sublimest efforts of the human invention.\n\nTo those, who shall be at the trouble of examining into the\ndegree of accuracy with which the task has been executed, I may\nbe allowed to suggest, that their judgment should not be formed\non a comparison with any single text of my Author; since, in more\ninstances than I have noticed, I have had to make my choice out\nof a variety of readings and interpretations, presented by\ndifferent editions and commentators.\n\nIn one or two of those editions is to be found the title of \"The\nVision,\" which I have adopted, as more conformable to the genius\nof our language than that of \"The Divine Comedy.\"  Dante himself,\nI believe, termed it simply \"The Comedy;\" in the first place,\nbecause the style was of the middle kind:  and in the next,\nbecause the story (if story it may be called) ends happily.\n\nInstead of a Life of my Author, I have subjoined, in\nchronological order, a view not only of the principal events\nwhich befell him, but");
                
        
                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "DANGER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 7242, file);
                test_error(size == 7242, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7242 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7242);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 7242);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(131, 1);
                char expected_filecontent[132] = "";
        
                strcat(expected_filecontent, "nd\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all");
                
        
                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "TEST.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 131, file);
                test_error(size == 131, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 131 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 131);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 131);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(5979, 1);
                char expected_filecontent[5980] = "";
        
                strcat(expected_filecontent, " Arabian Phoenix, when five hundred years\nHave well nigh circled, dies, and springs forthwith\nRenascent.  Blade nor herb throughout his life\nHe tastes, but tears of frankincense alone\nAnd odorous amomum:  swaths of nard\nAnd myrrh his funeral shroud.  As one that falls,\nHe knows not how, by force demoniac dragg\'d\nTo earth, or through obstruction fettering up\nIn chains invisible the powers of man,\nWho, risen from his trance, gazeth around,\nBewilder\'d with the monstrous agony\nHe hath endur\'d, and wildly staring sighs;\nSo stood aghast the sinner when he rose.\n     Oh!  how severe God\'s judgment, that deals out\nSuch blows in stormy vengeance!  Who he was\nMy teacher next inquir\'d, and thus in few\nHe answer\'d:  \"Vanni Fucci am I call\'d,\nNot long since rained down from Tuscany\nTo this dire gullet.  Me the beastial life\nAnd not the human pleas\'d, mule that I was,\nWho in Pistoia found my worthy den.\"\n     I then to Virgil:  \"Bid him stir not hence,\nAnd ask what crime did thrust him hither:  once\nA man I knew him choleric and bloody.\"\n     The sinner heard and feign\'d not, but towards me\nHis mind directing and his face, wherein\nWas dismal shame depictur\'d, thus he spake:\n\"It grieves me more to have been caught by thee\nIn this sad plight, which thou beholdest, than\nWhen I was taken from the other life.\nI have no power permitted to deny\nWhat thou inquirest.\"  I am doom\'d thus low\nTo dwell, for that the sacristy by me\nWas rifled of its goodly ornaments,\nAnd with the guilt another falsely charged.\nBut that thou mayst not joy to see me thus,\nSo as thou e\'er shalt \'scape this darksome realm\nOpen thine ears and hear what I forebode.\nReft of the Neri first Pistoia pines,\nThen Florence changeth citizens and laws.\nFrom Valdimagra, drawn by wrathful Mars,\nA vapour rises, wrapt in turbid mists,\nAnd sharp and eager driveth on the storm\nWith arrowy hurtling o\'er Piceno\'s field,\nWhence suddenly the cloud shall burst, and strike\nEach helpless Bianco prostrate to the ground.\nThis have I told, that grief may rend thy heart.\"\n\n\n\nCANTO XXV\n\nWHEN he had spoke, the sinner rais\'d his hands\nPointed in mockery, and cried:  \"Take them, God!\nI level them at thee!\"  From that day forth\nThe serpents were my friends; for round his neck\nOne of then rolling twisted, as it said,\n\"Be silent, tongue!\"  Another to his arms\nUpgliding, tied them, riveting itself\nSo close, it took from them the power to move.\n     Pistoia!  Ah Pistoia!  why dost doubt\nTo turn thee into ashes, cumb\'ring earth\nNo longer, since in evil act so far\nThou hast outdone thy seed?  I did not mark,\nThrough all the gloomy circles of the\' abyss,\nSpirit, that swell\'d so proudly \'gainst his God,\nNot him, who headlong fell from Thebes.  He fled,\nNor utter\'d more; and after him there came\nA centaur full of fury, shouting, \"Where\nWhere is the caitiff?\"  On Maremma\'s marsh\nSwarm not the serpent tribe, as on his haunch\nThey swarm\'d, to where the human face begins.\nBehind his head upon the shoulders lay,\nWith open wings, a dragon breathing fire\nOn whomsoe\'er he met.  To me my guide:\n\"Cacus is this, who underneath the rock\nOf Aventine spread oft a lake of blood.\nHe, from his brethren parted, here must tread\nA different journey, for his fraudful theft\nOf the great herd, that near him stall\'d; whence found\nHis felon deeds their end, beneath the mace\nOf stout Alcides, that perchance laid on\nA hundred blows, and not the tenth was felt.\"\n     While yet he spake, the centaur sped away:\nAnd under us three spirits came, of whom\nNor I nor he was ware, till they exclaim\'d;\n\"Say who are ye?\"  We then brake off discourse,\nIntent on these alone.  I knew them not;\nBut, as it chanceth oft, befell, that one\nHad need to name another.  \"Where,\" said he,\n\"Doth Cianfa lurk?\"  I, for a sign my guide\nShould stand attentive, plac\'d against my lips\nThe finger lifted.  If, O reader!  now\nThou be not apt to credit what I tell,\nNo marvel; for myself do scarce allow\nThe witness of mine eyes.  But as I looked\nToward them, lo!  a serpent with six feet\nSprings forth on one, and fastens full upon him:\nHis midmost grasp\'d the belly, a fore");
    strcat(expected_filecontent, "foot\nSeiz\'d on each arm (while deep in either cheek\nHe flesh\'d his fangs); the hinder on the thighs\nWere spread, \'twixt which the tail inserted curl\'d\nUpon the reins behind.  Ivy ne\'er clasp\'d\nA dodder\'d oak, as round the other\'s limbs\nThe hideous monster intertwin\'d his own.\nThen, as they both had been of burning wax,\nEach melted into other, mingling hues,\nThat which was either now was seen no more.\nThus up the shrinking paper, ere it burns,\nA brown tint glides, not turning yet to black,\nAnd the clean white expires.  The other two\nLook\'d on exclaiming:  \"Ah, how dost thou change,\nAgnello!  See!  Thou art nor double now,\nNor only one.\"  The two heads now became\nOne, and two figures blended in one form\nAppear\'d, where both were lost.  Of the four lengths\nTwo arms were made:  the belly and the chest\nThe thighs and legs into such members chang\'d,\nAs never eye hath seen.  Of former shape\nAll trace was vanish\'d.  Two yet neither seem\'d\nThat image miscreate, and so pass\'d on\nWith tardy steps.  As underneath the scourge\nOf the fierce dog-star, that lays bare the fields,\nShifting from brake to brake, the lizard seems\nA flash of lightning, if he thwart the road,\nSo toward th\' entrails of the other two\nApproaching seem\'d, an adder all on fire,\nAs the dark pepper-grain, livid and swart.\nIn that part, whence our life is nourish\'d first,\nOne he transpierc\'d; then down before him fell\nStretch\'d out.  The pierced spirit look\'d on him\nBut spake not; yea stood motionless and yawn\'d,\nAs if by sleep or fev\'rous fit assail\'d.\nHe ey\'d the serpent, and the serpent him.\nOne from the wound, the other from the mouth\nBreath\'d a thick smoke, whose vap\'ry columns join\'d.\n     Lucan in mute attention now may hear,\nNor thy disastrous fate, Sabellus!  tell,\nNor shine, Nasidius!  Ovid now be mute.\nWhat if in warbling fiction he record\nCadmus and Arethusa, to a snake\nHim chang\'d, and ");
                
        
                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "REQUIRE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 5979, file);
                test_error(size == 5979, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5979 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5979);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 5979);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(7696, 1);
                char expected_filecontent[7697] = "";
        
                strcat(expected_filecontent, "it were detained in the snare you\nhave spread for me, so as to be somewhat prolix in my answer.\"\n\nv. 60. I it was.]  Pietro delle Vigne, a native of Capua, who,\nfrom a low condition, raised himself by his eloquence and legal\nknowledge to the office of Chancellor to the Emperor Frederick\nII. whose confidence in him was such, that his influence in the\nempire became unbounded.  The courtiers, envious of his exalted\nsituation, contrived, by means of forged letters, to make\nFrederick believe that he held a secret and traitorous\nintercourse with the Pope, who was then at enmity with the\nEmperor.  In consequence of this supposed crime he was cruelly\ncondemned by his too credulous sovereign to lose his eyes, and,\nbeing driven to despair by his unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n61.\n\nv. 28.  As, in the torrid Indian clime.]  Landino refers to\nAlbertus Magnus for the circumstance here alluded to.\n\nv. 53.  In Mongibello.]\n        More hot than Aetn\' or flaming Mongibell.\n               Spenser, F. Q. b. ii. c. ix. st. 29.\nSee Virg. Aen. 1. viii. 416. and Berni. Orl. Inn 1. i. c. xvi.\nst. 21.  It would be endless to refer to parallel passages in the\nGreek writers.\n\nv. 64.  This of the seven kings was one.]  Compare Aesch.  Seven\nChiefs, 425.  Euripides, Phoen. 1179 and Statius. Theb. l. x.\n821.\n\nv. 76.  Bulicame.]  A warm medicinal spring near Viterbo, the\nwaters of which, as Landino and Vellutelli affirm, passed by a\nplace of ill fame.  Venturi, with less probability, conjectures\nthat Dante would imply, that it was the scene of much licentious\nmerriment among those who frequented its baths.\n\nv. 91.  Under whose monarch.]\n        Credo pudicitiam Saturno rege moratam\n        In terris.\n               Juv. Satir. vi.\n\nv. 102.  His head.]  Daniel, ch. ii. 32, 33.\n\nv. 133.  Whither.] On the other side of Purgatory.\n\nCANTO XV\n\n v. 10.  Chiarentana.]  A part of the Alps where the Brenta\nrises, which river is much ");
    strcat(expected_filecontent, "swoln as soon as the snow begins to\ndissolve on the mountains.\n\nv. 28.  Brunetto.]  \"Ser Brunetto, a Florentine, the secretary or\nchancellor of the city, and Dante\'s preceptor, hath left us a\nwork so little read, that both the subject of it and the language\nof it have been mistaken.  It is in the French spoken in the\nreign of St. Louis,under the title of Tresor, and contains a\nspecies of philosophical course of lectures divided into theory\nand practice, or, as he expresses it, \"un enchaussement des\nchoses divines et humaines,\" &c.  Sir R. Clayton\'s Translation of\nTenhove\'s Memoirs of the  Medici, vol. i.  ch.  ii.  p. 104.  The\nTresor has never been printed in the original language.  There is\na fine manuscript of it in the British Museum, with an\nilluminated portrait of Brunetto in his  study prefixed.  Mus.\nBrit. MSS. 17, E. 1. Tesor.  It is divided into four books, the\nfirst, on Cosmogony and Theology, the second, a translation of\nAristotle\'s Ethics; the third on Virtues and Vices; the fourth,\non Rhetoric.  For an interesting memoir relating to this work,\nsee Hist. de l\'Acad. des Inscriptions, tom. vii. 296.  His\nTesoretto, one of the earliest productions of Italian poetry, is\na curious work, not unlike the writings of Chaucer in style and\nnumbers, though Bembo remarks, that his pupil, however largely he\nhad stolen from it, could not have much enriched himself.  As it\nis perhaps but little known, I will here add a slight sketch of\nit.\n\nBrunetto describes himself as returning from an embassy to the\nKing of Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded b");
                
        
                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "HAT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 7696, file);
                test_error(size == 7696, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7696 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7696);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 7696);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(7607, 1);
                char expected_filecontent[7608] = "";
        
                strcat(expected_filecontent, ",\nOr Africanus\': e\'en the sun\'s itself\nWere poor to this, that chariot of the sun\nErroneous, which in blazing ruin fell\nAt Tellus\' pray\'r devout, by the just doom\nMysterious of all-seeing Jove.  Three nymphs\n,k the right wheel, came circling in smooth dance;\nThe one so ruddy, that her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and keen edge,\nE\'en as I view\'d it with the flood between,\nAppall\'d me.  Next four others I beheld,\nOf humble seeming: and, behind them all,\nOne single old man, sleeping, as he came,\nWith a shrewd visage.  And these seven, each\nLike the first troop were habited, hut wore\nNo braid of lilies on their temples wreath\'d.\nRather with roses and each vermeil flower,\nA sight, but little distant, might have sworn,\nThat they were all on fire above their brow.\n     Whenas the car was o\'er against me, straight.\nWas heard a thund\'ring, at whose voice it seem\'d\nThe chosen multitude were stay\'d; for there,\nWith the first ensigns, made they solemn halt.\n\n\n\nCANTO XXX\n\nSoon as the polar light, which never knows\nSetting nor rising, nor the shadowy veil\nOf other cloud than sin, fair ornament\nOf the first heav\'n, to duty each one there\nSafely convoying, as that lower doth\nThe steersman to his port, stood firmly fix\'d;\nForthwith the saintly tribe, who in the van\nBetween the Gryphon and its radiance came,\nDid turn them to the car, as to their rest:\nAnd one, as if commission\'d from above,\nIn holy chant thrice shorted forth aloud:\n\"Come, spouse, from Libanus!\" and all the rest\nTook up the song--At the last audit so\nThe blest shall rise, from forth his cavern each\nUplifting lightly his new-vested flesh,\nAs, on the sacred litter, at the voice\nAuthoritative of that elder, sprang\nA hundred ministers and messengers\nOf life eternal.  \"Blessed thou!  who com\'st!\"\nAnd, \"O,\" they cried, \"from full hands scatter ye\nUnwith\'ring lilies;\" and, so saying, cast\nFlowers over head and round them on all sides.\n     I have beheld, ere now, at break of day,\nThe eastern clime all roseate, and the sky\nOppos\'d, one deep and beautiful serene,\nAnd the sun\'s face so shaded, and with mists\nAttemper\'d at lids rising, that the eye\nLong while endur\'d the sight: thus in a cloud\nOf flowers, that from those hands angelic rose,\nAnd down, within and outside of the car,\nFell showering, in white veil with olive wreath\'d,\nA virgin in my view appear\'d, beneath\nGreen mantle, rob\'d in hue of living flame:\nAnd o\'er my Spirit, that in former days\nWithin her presence had abode so long,\nNo shudd\'ring terror crept.  Mine eyes no more\nHad knowledge of her; yet there mov\'d from her\nA hidden virtue, at whose touch awak\'d,\nThe power of ancient love was strong within me.\n     No sooner on my vision streaming, smote\nThe heav\'nly influence, which years past, and e\'en\nIn childhood, thrill\'d me, than towards Virgil I\nTurn\'d me to leftward, panting, like a babe,\nThat flees for refuge to his mother\'s breast,\nIf aught have terrified or work\'d him woe:\nAnd would have cried:  \"There is no dram of blood,\nThat doth not quiver in me.  The old flame\nThrows out clear tokens of reviving fire:\"\nBut Virgil had bereav\'d us of himself,\nVirgil, my best-lov\'d father; Virgil, he\nTo whom I gave me up for safety: nor,\nAll, our prime mother lost, avail\'d to save\nMy undew\'d cheeks from blur of soiling tears.\n     \"Dante, weep not, that Virgil leaves thee: nay,\nWeep thou n");
    strcat(expected_filecontent, "ot yet: behooves thee feel the edge\nOf other sword, and thou shalt weep for that.\"\n     As to the prow or stern, some admiral\nPaces the deck, inspiriting his crew,\nWhen \'mid the sail-yards all hands ply aloof;\nThus on the left side of the car I saw,\n(Turning me at the sound of mine own name,\nWhich here I am compell\'d to register)\nThe virgin station\'d, who before appeared\nVeil\'d in that festive shower angelical.\n     Towards me, across the stream, she bent her eyes;\nThough from her brow the veil descending, bound\nWith foliage of Minerva, suffer\'d not\nThat I beheld her clearly; then with act\nFull royal, still insulting o\'er her thrall,\nAdded, as one, who speaking keepeth back\nThe bitterest saying, to conclude the speech:\n\"Observe me well.  I am, in sooth, I am\nBeatrice.  What!  and hast thou deign\'d at last\nApproach the mountain?  knewest not, O man!\nThy happiness is whole?\"  Down fell mine eyes\nOn the clear fount, but there, myself espying,\nRecoil\'d, and sought the greensward: such a weight\nOf shame was on my forehead.  With a mien\nOf that stern majesty, which doth surround\nmother\'s presence to her awe-struck child,\nShe look\'d; a flavour of such bitterness\nWas mingled in her pity.  There her words\nBrake off, and suddenly the angels sang:\n\"In thee, O gracious Lord, my hope hath been:\"\nBut went no farther than, \"Thou Lord, hast set\nMy feet in ample room.\"  As snow, that lies\nAmidst the living rafters on the back\nOf Italy congeal\'d when drifted high\nAnd closely pil\'d by rough Sclavonian blasts,\nBreathe but the land whereon no shadow falls,\nAnd straightway melting it distils away,\nLike a fire-wasted taper: thus was I,\nWithout a sigh or tear, or ever these\nDid sing, that with the chiming of heav\'n\'s sphere,\nStill in their warbling chime: but when the strain\nOf dulcet symphony, express\'d for me\nTheir soft compassion, more than could the words\n\"Virgin, why so consum\'st him?\"  then the ice,\nCongeal\'d about my bosom, turn\'d itself\nTo spirit and water, and with anguish forth\nGush\'d through the lips and eyelids from the heart.\n     Upon the chariot\'s right edge still she stood,\nImmovable, and thus address\'d her words\nTo those bright semblances with pity touch\'d:\n\"Ye in th\' eternal day your vigils keep,\nSo that nor night nor slumber, with close stealth,\nConveys from you a single step in all\nThe goings on of life: thence with more heed\nI shape mine answer, for his ear intended,\nWho there stands weeping, that the sorrow now\nMay equal the transgression.  Not alone\nThrough operation of the mighty orbs,\nThat mark each seed to some predestin\'d aim,\nAs with aspect or fortunate or ill\nThe constellations meet, but through benign\nLargess of heav\'nly graces, which rain down\nFrom such a height, as mocks our vision, this man\nWas in the freshness of his being, such,\nSo gifted virtually, that in him\nAll better habits wond\'rously had thriv\'d.\nThe more of kindly strength is in the soil,\nSo much doth evil seed and lack of culture\nMar it the more, and make it run to wildness.\nThese looks sometime upheld him; for I show\'d\nMy youthful eyes, and led him by their light\nIn upright walking.  Soon as I had reach\'d\nThe threshold of my second age, and chang\'d\nMy mortal for immortal, then he left me,\nAnd gave himself to others.  When from flesh\nTo spirit I had risen, and increase\nOf beauty and of virtue circled me,\nI was less dear to him, and valued less.\nHis steps were turn\'d into deceitful ways,\nFollowing false images of good, that make\nNo promise perfect.  Nor avail\'d me aught\nTo sue fo");
                
        
                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "NATION");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 7607, file);
                test_error(size == 7607, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7607 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7607);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 7607);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(5120, 1);
                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "e eyes are held\nStill in this depth below.  But search around\nThe circles, to the furthest, till thou spy\nSeated in state, the queen, that of this realm\nIs sovran.\"  Straight mine eyes I rais\'d; and bright,\nAs, at the birth of morn, the eastern clime\nAbove th\' horizon, where the sun declines;\nTo mine eyes, that upward, as from vale\nTo mountain sped, at th\' extreme bound, a part\nExcell\'d in lustre all the front oppos\'d.\nAnd as the glow burns ruddiest o\'er the wave,\nThat waits the sloping beam, which Phaeton\nIll knew to guide, and on each part the light\nDiminish\'d fades, intensest in the midst;\nSo burn\'d the peaceful oriflamb, and slack\'d\nOn every side the living flame decay\'d.\nAnd in that midst their sportive pennons wav\'d\nThousands of angels; in resplendence each\nDistinct, and quaint adornment. At their glee\nAnd carol, smil\'d the Lovely One of heav\'n,\nThat joy was in the eyes of all the blest.\n     Had I a tongue in eloquence as rich,\nAs is the colouring in fancy\'s loom,\n\'T were all too poor to utter the least part\nOf that enchantment.  When he saw mine eyes\nIntent on her, that charm\'d him, Bernard gaz\'d\nWith so exceeding fondness, as infus\'d\nArdour into my breast, unfelt before.\n\n\n\nCANTO XXXII\n\nFreely the sage, though wrapt in musings high,\nAssum\'d the teacher\'s part, and mild began:\n\"The wound, that Mary clos\'d, she open\'d first,\nWho sits so beautiful at Mary\'s feet.\nThe third in order, underneath her, lo!\nRachel with Beatrice. Sarah next,\nJudith, Rebecca, and the gleaner maid,\nMeek ancestress of him, who sang the songs\nOf sore repentance in his sorrowful mood.\nAll, as I name them, down from deaf to leaf,\nAre in gradation throned on the rose.\nAnd from the seventh step, successively,\nAdown the breathing tresses of the flow\'r\nStill doth the file of Hebrew dames proceed.\nFor these are a partition wall, whereby\nThe sacred stairs are sever\'d, as the faith\nIn Christ divides them.  On this part, where blooms\nEach leaf in full maturity, are set\nSuch as in Christ, or ere he came, believ\'d.\nOn th\' other, where an intersected space\nYet shows the semicircle void, abide\nAll they, who look\'d to Christ already come.\nAnd as our Lady on her glorious stool,\nAnd they who on their stools beneath her sit,\nThis way distinction make: e\'en so on his,\nThe mighty Baptist that way marks the line\n(He who endur\'d the desert and the pains\nOf martyrdom, and for two years of hell,\nYet still continued holy), and beneath,\nAugustin, Francis, Benedict, and the rest,\nThus far from round to round.  So heav\'n\'s decree\nForecasts, this garden equally to fill.\nWith faith in either view, past or to come,\nLearn too, that downward from the step, which cleaves\nMidway the twain compartments, none there are\nWho place obtain for merit of their own,\nBut have through others\' merit been advanc\'d,\nOn set conditions: spirits all releas\'d,\nEre for themselves they had the power to choose.\nAnd, if thou mark and listen to them well,\nTheir childish looks and voice declare as much.\n     \"Here, silent as thou art, I know thy doubt;\nAnd gladly will I loose the knot, wherein\nThy subtle thoughts have bound thee.  From this realm\nExcluded, chalice no entrance here may find,\nNo more shall hunger, thirst, or sorrow can.\nA law immutable hath establish\'d all;\nNor is there aught thou seest, that doth not fit,\nExactly, as the finger to the ring.\nIt is not therefore without cause, that these,\nO\'erspeedy comers to immortal life,\nAre different in their shares of excellence.\nOur Sovran Lord--that settleth this estate\nIn love and in delight so absolute,\nThat wish can dare no further--every soul,\nCreated in his joyous sight to dwell,\nWith grace at pleasure variously endows.\nAnd for a proof th\' effect may well suffice.\nAnd \'t is moreover most expressly mark\'d\nIn holy scripture, where the twins are said\nTo, have struggled in the womb.  Therefore, as grace\nInweaves the coronet, so every brow\nWeareth its proper hue of orient light.\nAnd merely in respect to his prime gift,\nNot in reward of meritorious deed,\nHath each his several degree assign\'d.\nIn early times with their own innocence\nMore was not ");
    strcat(expected_filecontent, "wanting, than the parents\' faith,\nTo save them: those first ages past, behoov\'d\nThat circumcision in the males should imp\nThe flight of innocent wings:  but since the day\nOf grace hath come, without baptismal rites\nIn Christ accomplish\'d, innocence herself\nMust linger yet below.  Now raise thy view\nUnto the visage most resembling Christ:\nFor, in her splendour only, shalt thou win\nThe pow\'r to look on him.\"  Forthwith I saw\nSuch floods of gladness on her visage shower\'d,\nFrom holy spirits, winging that profound;\nThat, whatsoever I had yet beheld,\nHad not so much suspended me with wonder,\nOr shown me such similitude of God.\nAnd he, who had to her descended, once,\nOn earth, now hail\'d in heav\'n; and on pois\'d wing.\n\"Ave, Maria, Gratia Plena,\" sang:\nTo whose sweet anthem all the blissful court,\nFrom all parts answ\'ring, rang: that holier joy\nBrooded the deep serene.  \"Father rever\'d:\nWho deign\'st, for me, to quit the pleasant place,\nWherein thou sittest, by eternal lot!\nSay, who that angel is, that with such glee\n");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "TAKE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 5249, file);
                test_error(size == 5120, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5120 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5120);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5120);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6685, 1);
                char expected_filecontent[6686] = "";

                strcat(expected_filecontent, "But who is he observes them?  None; not he,\nWho goes before, the shepherd of the flock,\nWho chews the cud but doth not cleave the hoof.\nTherefore the multitude, who see their guide\nStrike at the very good they covet most,\nFeed there and look no further.  Thus the cause\nIs not corrupted nature in yourselves,\nBut ill-conducting, that hath turn\'d the world\nTo evil.  Rome, that turn\'d it unto good,\nWas wont to boast two suns, whose several beams\nCast light on either way, the world\'s and God\'s.\nOne since hath quench\'d the other; and the sword\nIs grafted on the crook; and so conjoin\'d\nEach must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and the Po\nTheir waters roll, was once the residence\nOf courtesy and velour, ere the day,\nThat frown\'d on Frederick; now secure may pass\nThose limits, whosoe\'er hath left, for shame,\nTo talk with good men, or come near their haunts.\nThree aged ones are still found there, in whom\nThe old time chides the new: these deem it long\nEre God restore them to a better world:\nThe good Gherardo, of Palazzo he\nConrad, and Guido of Castello, nam\'d\nIn Gallic phrase more fitly the plain Lombard.\nOn this at last conclude.  The church of Rome,\nMixing two governments that ill assort,\nHath miss\'d her footing, fall\'n into the mire,\nAnd there herself and burden much defil\'d.\"\n     \"O Marco!\" I replied, shine arguments\nConvince me: and the cause I now discern\nWhy of the heritage no portion came\nTo Levi\'s offspring.  But resolve me this\nWho that Gherardo is, that as thou sayst\nIs left a sample of the perish\'d race,\nAnd for rebuke to this untoward age?\"\n     \"Either thy words,\" said he, \"deceive; or else\nAre meant to try me; that thou, speaking Tuscan,\nAppear\'st not to have heard of good Gherado;\nThe sole addition that, by which I know him;\nUnless I borrow\'d from his daughter Gaia\nAnother name to grace him.  God be with you.\nI bear you company no more.  Behold\nThe dawn with white ray glimm\'ring through the mist.\nI must away--the angel comes--ere he\nAppear.\"  He said, and would not hear me more.\n\n\n\nCANTO XVII\n\nCall to remembrance, reader, if thou e\'er\nHast, on a mountain top, been ta\'en by cloud,\nThrough which thou saw\'st no better, than the mole\nDoth through opacous membrane; then, whene\'er\nThe wat\'ry vapours dense began to melt\nInto thin air, how faintly the sun\'s sphere\nSeem\'d wading through them; so thy nimble thought\nMay image, how at first I re-beheld\nThe sun, that bedward now his couch o\'erhung.\n     Thus with my leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, ");
    strcat(expected_filecontent, "outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing it loves,\nAll fro");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DESCRIBE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 7175, file);
                test_error(size == 6685, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6685 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6685);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6685);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(7242, 1);
                char expected_filecontent[7243] = "";

                strcat(expected_filecontent, "roverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye commands\nFor sight no obstacle found here, nor shade, But all sunshine.\nMilton, P. l. b. iii.  616.\n\nv. 135.  Of the great Harry.]  The Emperor Henry VII, who died in\n1313.\n\nv. 141.  He.]  Pope Clement V. See Canto XXVII.  53.\n\nv. 145.  Alagna\'s priest.]  Pope Boniface VIII.  Hell, Canto XIX.\n\n79.\n\nCANTO XXXI\n\nv. 6.  Bees.]  Compare Homer, Iliad, ii.  87. Virg.  Aen. I. 430,\nand Milton, P. L. b. 1.  768.\n\nv. 29.  Helice.]  Callisto, and her son Arcas, changed into the\nconstellations of the Greater Bear and Arctophylax, or Bootes.\nSee Ovid, Met.  l. ii. fab. v. vi.\n\nv. 93.  Bernard.]  St. Bernard, the venerable abbot of Clairvaux,\nand the great promoter of the second crusade, who died A.D. 1153,\nin his sixty-third year.  His sermons are called by Henault,\n\"chefs~d\'oeuvres de sentiment et de force.\"  Abrege Chron. de\nl\'Hist.  de Fr. 1145. They have even been preferred to al1 the\nproductions of the ancients, and the author has been termed the\nlast of the fathers of the church. It is uncertain whether they\nwere not delivered originally in the French tongue.\n\nThat the part he acts in the present Poem should be assigned to\nhim. appears somewhat remarkable, when we consider that he\nseverely censured the new festival established in honour of the\nImmaculate Conception of the virgin, and opposed the doctrine\nitself with the greatest vigour, as it supposed her being\nhonoured with a privilegewhich belonged to Christ Alone Dr.\nMaclaine\'s Mosheim, v. iii. cent. xii. p. ii. c. 3 - 19.\n\nv. 95.  Our Veronica ] The holy handkerchief, then preserved at\nRome, on which the countenance of our Saviour was supposed to\nhave be");
    strcat(expected_filecontent, "en imprest.\n\nv. 101.  Him.]  St. Bernard.\n\nv. 108.  The queen.]  The Virgin Mary.\n\nv. 119.  Oriflamb.]  Menage on this word quotes the Roman des\nRoyau\n-Iignages of Guillaume Ghyart.\nOriflamme est une banniere\nDe cendal roujoyant et simple\nSans portraiture d\'autre affaire,\n\nCANTO XXXII\n\nv. 3.  She.]  Eve.\n\nv. 8.  Ancestress.]  Ruth, the ancestress of David.\n\nv. 60.  In holy scripture.]  Gen. c. xxv.  22.\nv. 123.  Lucia.]  See Hell, Canto II.  97.\n\nCANTO XXXIII\n\nv. 63.  The Sybil\'s sentence.]  Virg.  Aen.  iii. 445.\n\nv. 89.  One moment.]  \"A moment seems to me more tedious, than\nfive-and-twenty ages would have appeared to the Argonauts, when\nthey had resolved on their expedition.\n\nv. 92.  Argo\'s shadow]\nQuae simul ac rostro ventosnm proscidit aequor,\nTortaque remigio spumis incanduit unda,\nEmersere feri candenti e gurgite vultus\nAequoreae monstrum Nereides admirantes.\nCatullus, De Nupt.  Pel.  et Thet.  15.\n\nv. 109.  Three orbs of triple hue, clipt in one bound.]  The\nTrinity.\n\nv. 118.  That circling.]  The second of the circles, \"Light of\nLight,\" in which he dimly beheld the mystery of the incarnation.\n\n\n\n\n\nEnd Paradise.\n\n\n\n\n\nPREFACE\n\nIn the years 1805 and 1806, I published the first part of the\nfollowing translation, with the text of the original.  Since that\nperiod, two impressions of the whole of the Divina Commedia, in\nItalian, have made their appearance in this country.  It is not\nnecessary that I should add a third: and I am induced to hope\nthat the Poem, even in the present version of it, may not be\nwithout interest for the mere English reader.\n\nThe translation of the second and third parts, \"The Purgatory\"\nand \"The Paradise,\" was begun long before the first, and as early\nas the year 1797; but, owing to many interruptions, not concluded\ntill the summer before last.  On a retrospect of the time and\nexertions that have been thus employed, I do not regard those\nhours as the least happy of my  life, during which (to use the\neloquent language of Mr. Coleridge) \"my individual recollections\nhave been suspended, and lulled to sleep amid the music of nobler\nthoughts;\"  nor that study as misapplied, which has familiarized\nme with one of the sublimest efforts of the human invention.\n\nTo those, who shall be at the trouble of examining into the\ndegree of accuracy with which the task has been executed, I may\nbe allowed to suggest, that their judgment should not be formed\non a comparison with any single text of my Author; since, in more\ninstances than I have noticed, I have had to make my choice out\nof a variety of readings and interpretations, presented by\ndifferent editions and commentators.\n\nIn one or two of those editions is to be found the title of \"The\nVision,\" which I have adopted, as more conformable to the genius\nof our language than that of \"The Divine Comedy.\"  Dante himself,\nI believe, termed it simply \"The Comedy;\" in the first place,\nbecause the style was of the middle kind:  and in the next,\nbecause the story (if story it may be called) ends happily.\n\nInstead of a Life of my Author, I have subjoined, in\nchronological order, a view not only of the principal events\nwhich befell him, but");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DANGER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 7565, file);
                test_error(size == 7242, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7242 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7242);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 7242);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(131, 1);
                char expected_filecontent[132] = "";

                strcat(expected_filecontent, "nd\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "TEST.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 416, file);
                test_error(size == 131, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 131 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 131);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 131);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(5979, 1);
                char expected_filecontent[5980] = "";

                strcat(expected_filecontent, " Arabian Phoenix, when five hundred years\nHave well nigh circled, dies, and springs forthwith\nRenascent.  Blade nor herb throughout his life\nHe tastes, but tears of frankincense alone\nAnd odorous amomum:  swaths of nard\nAnd myrrh his funeral shroud.  As one that falls,\nHe knows not how, by force demoniac dragg\'d\nTo earth, or through obstruction fettering up\nIn chains invisible the powers of man,\nWho, risen from his trance, gazeth around,\nBewilder\'d with the monstrous agony\nHe hath endur\'d, and wildly staring sighs;\nSo stood aghast the sinner when he rose.\n     Oh!  how severe God\'s judgment, that deals out\nSuch blows in stormy vengeance!  Who he was\nMy teacher next inquir\'d, and thus in few\nHe answer\'d:  \"Vanni Fucci am I call\'d,\nNot long since rained down from Tuscany\nTo this dire gullet.  Me the beastial life\nAnd not the human pleas\'d, mule that I was,\nWho in Pistoia found my worthy den.\"\n     I then to Virgil:  \"Bid him stir not hence,\nAnd ask what crime did thrust him hither:  once\nA man I knew him choleric and bloody.\"\n     The sinner heard and feign\'d not, but towards me\nHis mind directing and his face, wherein\nWas dismal shame depictur\'d, thus he spake:\n\"It grieves me more to have been caught by thee\nIn this sad plight, which thou beholdest, than\nWhen I was taken from the other life.\nI have no power permitted to deny\nWhat thou inquirest.\"  I am doom\'d thus low\nTo dwell, for that the sacristy by me\nWas rifled of its goodly ornaments,\nAnd with the guilt another falsely charged.\nBut that thou mayst not joy to see me thus,\nSo as thou e\'er shalt \'scape this darksome realm\nOpen thine ears and hear what I forebode.\nReft of the Neri first Pistoia pines,\nThen Florence changeth citizens and laws.\nFrom Valdimagra, drawn by wrathful Mars,\nA vapour rises, wrapt in turbid mists,\nAnd sharp and eager driveth on the storm\nWith arrowy hurtling o\'er Piceno\'s field,\nWhence suddenly the cloud shall burst, and strike\nEach helpless Bianco prostrate to the ground.\nThis have I told, that grief may rend thy heart.\"\n\n\n\nCANTO XXV\n\nWHEN he had spoke, the sinner rais\'d his hands\nPointed in mockery, and cried:  \"Take them, God!\nI level them at thee!\"  From that day forth\nThe serpents were my friends; for round his neck\nOne of then rolling twisted, as it said,\n\"Be silent, tongue!\"  Another to his arms\nUpgliding, tied them, riveting itself\nSo close, it took from them the power to move.\n     Pistoia!  Ah Pistoia!  why dost doubt\nTo turn thee into ashes, cumb\'ring earth\nNo longer, since in evil act so far\nThou hast outdone thy seed?  I did not mark,\nThrough all the gloomy circles of the\' abyss,\nSpirit, that swell\'d so proudly \'gainst his God,\nNot him, who headlong fell from Thebes.  He fled,\nNor utter\'d more; and after him there came\nA centaur full of fury, shouting, \"Where\nWhere is the caitiff?\"  On Maremma\'s marsh\nSwarm not the serpent tribe, as on his haunch\nThey swarm\'d, to where the human face begins.\nBehind his head upon the shoulders lay,\nWith open wings, a dragon breathing fire\nOn whomsoe\'er he met.  To me my guide:\n\"Cacus is this, who underneath the rock\nOf Aventine spread oft a lake of blood.\nHe, from his brethren parted, here must tread\nA different journey, for his fraudful theft\nOf the great herd, that near him stall\'d; whence found\nHis felon deeds their end, beneath the mace\nOf stout Alcides, that perchance laid on\nA hundred blows, and not the tenth was felt.\"\n     While yet he spake, the centaur sped away:\nAnd under us three spirits came, of whom\nNor I nor he was ware, till they exclaim\'d;\n\"Say who are ye?\"  We then brake off discourse,\nIntent on these alone.  I knew them not;\nBut, as it chanceth oft, befell, that one\nHad need to name another.  \"Where,\" said he,\n\"Doth Cianfa lurk?\"  I, for a sign my guide\nShould stand attentive, plac\'d against my lips\nThe finger lifted.  If, O reader!  now\nThou be not apt to credit what I tell,\nNo marvel; for myself do scarce allow\nThe witness of mine eyes.  But as I looked\nToward them, lo!  a serpent with six feet\nSprings forth on one, and fastens full upon him:\nHis midmost grasp\'d the belly, a fore");
    strcat(expected_filecontent, "foot\nSeiz\'d on each arm (while deep in either cheek\nHe flesh\'d his fangs); the hinder on the thighs\nWere spread, \'twixt which the tail inserted curl\'d\nUpon the reins behind.  Ivy ne\'er clasp\'d\nA dodder\'d oak, as round the other\'s limbs\nThe hideous monster intertwin\'d his own.\nThen, as they both had been of burning wax,\nEach melted into other, mingling hues,\nThat which was either now was seen no more.\nThus up the shrinking paper, ere it burns,\nA brown tint glides, not turning yet to black,\nAnd the clean white expires.  The other two\nLook\'d on exclaiming:  \"Ah, how dost thou change,\nAgnello!  See!  Thou art nor double now,\nNor only one.\"  The two heads now became\nOne, and two figures blended in one form\nAppear\'d, where both were lost.  Of the four lengths\nTwo arms were made:  the belly and the chest\nThe thighs and legs into such members chang\'d,\nAs never eye hath seen.  Of former shape\nAll trace was vanish\'d.  Two yet neither seem\'d\nThat image miscreate, and so pass\'d on\nWith tardy steps.  As underneath the scourge\nOf the fierce dog-star, that lays bare the fields,\nShifting from brake to brake, the lizard seems\nA flash of lightning, if he thwart the road,\nSo toward th\' entrails of the other two\nApproaching seem\'d, an adder all on fire,\nAs the dark pepper-grain, livid and swart.\nIn that part, whence our life is nourish\'d first,\nOne he transpierc\'d; then down before him fell\nStretch\'d out.  The pierced spirit look\'d on him\nBut spake not; yea stood motionless and yawn\'d,\nAs if by sleep or fev\'rous fit assail\'d.\nHe ey\'d the serpent, and the serpent him.\nOne from the wound, the other from the mouth\nBreath\'d a thick smoke, whose vap\'ry columns join\'d.\n     Lucan in mute attention now may hear,\nNor thy disastrous fate, Sabellus!  tell,\nNor shine, Nasidius!  Ovid now be mute.\nWhat if in warbling fiction he record\nCadmus and Arethusa, to a snake\nHim chang\'d, and ");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "REQUIRE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6111, file);
                test_error(size == 5979, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5979 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5979);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5979);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(7696, 1);
                char expected_filecontent[7697] = "";

                strcat(expected_filecontent, "it were detained in the snare you\nhave spread for me, so as to be somewhat prolix in my answer.\"\n\nv. 60. I it was.]  Pietro delle Vigne, a native of Capua, who,\nfrom a low condition, raised himself by his eloquence and legal\nknowledge to the office of Chancellor to the Emperor Frederick\nII. whose confidence in him was such, that his influence in the\nempire became unbounded.  The courtiers, envious of his exalted\nsituation, contrived, by means of forged letters, to make\nFrederick believe that he held a secret and traitorous\nintercourse with the Pope, who was then at enmity with the\nEmperor.  In consequence of this supposed crime he was cruelly\ncondemned by his too credulous sovereign to lose his eyes, and,\nbeing driven to despair by his unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n61.\n\nv. 28.  As, in the torrid Indian clime.]  Landino refers to\nAlbertus Magnus for the circumstance here alluded to.\n\nv. 53.  In Mongibello.]\n        More hot than Aetn\' or flaming Mongibell.\n               Spenser, F. Q. b. ii. c. ix. st. 29.\nSee Virg. Aen. 1. viii. 416. and Berni. Orl. Inn 1. i. c. xvi.\nst. 21.  It would be endless to refer to parallel passages in the\nGreek writers.\n\nv. 64.  This of the seven kings was one.]  Compare Aesch.  Seven\nChiefs, 425.  Euripides, Phoen. 1179 and Statius. Theb. l. x.\n821.\n\nv. 76.  Bulicame.]  A warm medicinal spring near Viterbo, the\nwaters of which, as Landino and Vellutelli affirm, passed by a\nplace of ill fame.  Venturi, with less probability, conjectures\nthat Dante would imply, that it was the scene of much licentious\nmerriment among those who frequented its baths.\n\nv. 91.  Under whose monarch.]\n        Credo pudicitiam Saturno rege moratam\n        In terris.\n               Juv. Satir. vi.\n\nv. 102.  His head.]  Daniel, ch. ii. 32, 33.\n\nv. 133.  Whither.] On the other side of Purgatory.\n\nCANTO XV\n\n v. 10.  Chiarentana.]  A part of the Alps where the Brenta\nrises, which river is much ");
    strcat(expected_filecontent, "swoln as soon as the snow begins to\ndissolve on the mountains.\n\nv. 28.  Brunetto.]  \"Ser Brunetto, a Florentine, the secretary or\nchancellor of the city, and Dante\'s preceptor, hath left us a\nwork so little read, that both the subject of it and the language\nof it have been mistaken.  It is in the French spoken in the\nreign of St. Louis,under the title of Tresor, and contains a\nspecies of philosophical course of lectures divided into theory\nand practice, or, as he expresses it, \"un enchaussement des\nchoses divines et humaines,\" &c.  Sir R. Clayton\'s Translation of\nTenhove\'s Memoirs of the  Medici, vol. i.  ch.  ii.  p. 104.  The\nTresor has never been printed in the original language.  There is\na fine manuscript of it in the British Museum, with an\nilluminated portrait of Brunetto in his  study prefixed.  Mus.\nBrit. MSS. 17, E. 1. Tesor.  It is divided into four books, the\nfirst, on Cosmogony and Theology, the second, a translation of\nAristotle\'s Ethics; the third on Virtues and Vices; the fourth,\non Rhetoric.  For an interesting memoir relating to this work,\nsee Hist. de l\'Acad. des Inscriptions, tom. vii. 296.  His\nTesoretto, one of the earliest productions of Italian poetry, is\na curious work, not unlike the writings of Chaucer in style and\nnumbers, though Bembo remarks, that his pupil, however largely he\nhad stolen from it, could not have much enriched himself.  As it\nis perhaps but little known, I will here add a slight sketch of\nit.\n\nBrunetto describes himself as returning from an embassy to the\nKing of Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded b");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HAT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 7876, file);
                test_error(size == 7696, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7696 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7696);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 7696);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(7607, 1);
                char expected_filecontent[7608] = "";

                strcat(expected_filecontent, ",\nOr Africanus\': e\'en the sun\'s itself\nWere poor to this, that chariot of the sun\nErroneous, which in blazing ruin fell\nAt Tellus\' pray\'r devout, by the just doom\nMysterious of all-seeing Jove.  Three nymphs\n,k the right wheel, came circling in smooth dance;\nThe one so ruddy, that her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and keen edge,\nE\'en as I view\'d it with the flood between,\nAppall\'d me.  Next four others I beheld,\nOf humble seeming: and, behind them all,\nOne single old man, sleeping, as he came,\nWith a shrewd visage.  And these seven, each\nLike the first troop were habited, hut wore\nNo braid of lilies on their temples wreath\'d.\nRather with roses and each vermeil flower,\nA sight, but little distant, might have sworn,\nThat they were all on fire above their brow.\n     Whenas the car was o\'er against me, straight.\nWas heard a thund\'ring, at whose voice it seem\'d\nThe chosen multitude were stay\'d; for there,\nWith the first ensigns, made they solemn halt.\n\n\n\nCANTO XXX\n\nSoon as the polar light, which never knows\nSetting nor rising, nor the shadowy veil\nOf other cloud than sin, fair ornament\nOf the first heav\'n, to duty each one there\nSafely convoying, as that lower doth\nThe steersman to his port, stood firmly fix\'d;\nForthwith the saintly tribe, who in the van\nBetween the Gryphon and its radiance came,\nDid turn them to the car, as to their rest:\nAnd one, as if commission\'d from above,\nIn holy chant thrice shorted forth aloud:\n\"Come, spouse, from Libanus!\" and all the rest\nTook up the song--At the last audit so\nThe blest shall rise, from forth his cavern each\nUplifting lightly his new-vested flesh,\nAs, on the sacred litter, at the voice\nAuthoritative of that elder, sprang\nA hundred ministers and messengers\nOf life eternal.  \"Blessed thou!  who com\'st!\"\nAnd, \"O,\" they cried, \"from full hands scatter ye\nUnwith\'ring lilies;\" and, so saying, cast\nFlowers over head and round them on all sides.\n     I have beheld, ere now, at break of day,\nThe eastern clime all roseate, and the sky\nOppos\'d, one deep and beautiful serene,\nAnd the sun\'s face so shaded, and with mists\nAttemper\'d at lids rising, that the eye\nLong while endur\'d the sight: thus in a cloud\nOf flowers, that from those hands angelic rose,\nAnd down, within and outside of the car,\nFell showering, in white veil with olive wreath\'d,\nA virgin in my view appear\'d, beneath\nGreen mantle, rob\'d in hue of living flame:\nAnd o\'er my Spirit, that in former days\nWithin her presence had abode so long,\nNo shudd\'ring terror crept.  Mine eyes no more\nHad knowledge of her; yet there mov\'d from her\nA hidden virtue, at whose touch awak\'d,\nThe power of ancient love was strong within me.\n     No sooner on my vision streaming, smote\nThe heav\'nly influence, which years past, and e\'en\nIn childhood, thrill\'d me, than towards Virgil I\nTurn\'d me to leftward, panting, like a babe,\nThat flees for refuge to his mother\'s breast,\nIf aught have terrified or work\'d him woe:\nAnd would have cried:  \"There is no dram of blood,\nThat doth not quiver in me.  The old flame\nThrows out clear tokens of reviving fire:\"\nBut Virgil had bereav\'d us of himself,\nVirgil, my best-lov\'d father; Virgil, he\nTo whom I gave me up for safety: nor,\nAll, our prime mother lost, avail\'d to save\nMy undew\'d cheeks from blur of soiling tears.\n     \"Dante, weep not, that Virgil leaves thee: nay,\nWeep thou n");
    strcat(expected_filecontent, "ot yet: behooves thee feel the edge\nOf other sword, and thou shalt weep for that.\"\n     As to the prow or stern, some admiral\nPaces the deck, inspiriting his crew,\nWhen \'mid the sail-yards all hands ply aloof;\nThus on the left side of the car I saw,\n(Turning me at the sound of mine own name,\nWhich here I am compell\'d to register)\nThe virgin station\'d, who before appeared\nVeil\'d in that festive shower angelical.\n     Towards me, across the stream, she bent her eyes;\nThough from her brow the veil descending, bound\nWith foliage of Minerva, suffer\'d not\nThat I beheld her clearly; then with act\nFull royal, still insulting o\'er her thrall,\nAdded, as one, who speaking keepeth back\nThe bitterest saying, to conclude the speech:\n\"Observe me well.  I am, in sooth, I am\nBeatrice.  What!  and hast thou deign\'d at last\nApproach the mountain?  knewest not, O man!\nThy happiness is whole?\"  Down fell mine eyes\nOn the clear fount, but there, myself espying,\nRecoil\'d, and sought the greensward: such a weight\nOf shame was on my forehead.  With a mien\nOf that stern majesty, which doth surround\nmother\'s presence to her awe-struck child,\nShe look\'d; a flavour of such bitterness\nWas mingled in her pity.  There her words\nBrake off, and suddenly the angels sang:\n\"In thee, O gracious Lord, my hope hath been:\"\nBut went no farther than, \"Thou Lord, hast set\nMy feet in ample room.\"  As snow, that lies\nAmidst the living rafters on the back\nOf Italy congeal\'d when drifted high\nAnd closely pil\'d by rough Sclavonian blasts,\nBreathe but the land whereon no shadow falls,\nAnd straightway melting it distils away,\nLike a fire-wasted taper: thus was I,\nWithout a sigh or tear, or ever these\nDid sing, that with the chiming of heav\'n\'s sphere,\nStill in their warbling chime: but when the strain\nOf dulcet symphony, express\'d for me\nTheir soft compassion, more than could the words\n\"Virgin, why so consum\'st him?\"  then the ice,\nCongeal\'d about my bosom, turn\'d itself\nTo spirit and water, and with anguish forth\nGush\'d through the lips and eyelids from the heart.\n     Upon the chariot\'s right edge still she stood,\nImmovable, and thus address\'d her words\nTo those bright semblances with pity touch\'d:\n\"Ye in th\' eternal day your vigils keep,\nSo that nor night nor slumber, with close stealth,\nConveys from you a single step in all\nThe goings on of life: thence with more heed\nI shape mine answer, for his ear intended,\nWho there stands weeping, that the sorrow now\nMay equal the transgression.  Not alone\nThrough operation of the mighty orbs,\nThat mark each seed to some predestin\'d aim,\nAs with aspect or fortunate or ill\nThe constellations meet, but through benign\nLargess of heav\'nly graces, which rain down\nFrom such a height, as mocks our vision, this man\nWas in the freshness of his being, such,\nSo gifted virtually, that in him\nAll better habits wond\'rously had thriv\'d.\nThe more of kindly strength is in the soil,\nSo much doth evil seed and lack of culture\nMar it the more, and make it run to wildness.\nThese looks sometime upheld him; for I show\'d\nMy youthful eyes, and led him by their light\nIn upright walking.  Soon as I had reach\'d\nThe threshold of my second age, and chang\'d\nMy mortal for immortal, then he left me,\nAnd gave himself to others.  When from flesh\nTo spirit I had risen, and increase\nOf beauty and of virtue circled me,\nI was less dear to him, and valued less.\nHis steps were turn\'d into deceitful ways,\nFollowing false images of good, that make\nNo promise perfect.  Nor avail\'d me aught\nTo sue fo");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "NATION");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 8069, file);
                test_error(size == 7607, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7607 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7607);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 7607);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "e eyes are held\nStill in this depth below.  But search around\nThe circles, to the furthest, till thou spy\nSeated in state, the queen, that of this realm\nIs sovran.\"  Straight mine eyes I rais\'d; and bright,\nAs, at the birth of morn, the eastern clime\nAbove th\' horizon, where the sun declines;\nTo mine eyes, that upward, as from vale\nTo mountain sped, at th\' extreme bound, a part\nExcell\'d in lustre all the front oppos\'d.\nAnd as the glow burns ruddiest o\'er the wave,\nThat waits the sloping beam, which Phaeton\nIll knew to guide, and on each part the light\nDiminish\'d fades, intensest in the midst;\nSo burn\'d the peaceful oriflamb, and slack\'d\nOn every side the living flame decay\'d.\nAnd in that midst their sportive pennons wav\'d\nThousands of angels; in resplendence each\nDistinct, and quaint adornment. At their glee\nAnd carol, smil\'d the Lovely One of heav\'n,\nThat joy was in the eyes of all the blest.\n     Had I a tongue in eloquence as rich,\nAs is the colouring in fancy\'s loom,\n\'T were all too poor to utter the least part\nOf that enchantment.  When he saw mine eyes\nIntent on her, that charm\'d him, Bernard gaz\'d\nWith so exceeding fondness, as infus\'d\nArdour into my breast, unfelt before.\n\n\n\nCANTO XXXII\n\nFreely the sage, though wrapt in musings high,\nAssum\'d the teacher\'s part, and mild began:\n\"The wound, that Mary clos\'d, she open\'d first,\nWho sits so beautiful at Mary\'s feet.\nThe third in order, underneath her, lo!\nRachel with Beatrice. Sarah next,\nJudith, Rebecca, and the gleaner maid,\nMeek ancestress of him, who sang the songs\nOf sore repentance in his sorrowful mood.\nAll, as I name them, down from deaf to leaf,\nAre in gradation throned on the rose.\nAnd from the seventh step, successively,\nAdown the breathing tresses of the flow\'r\nStill doth the file of Hebrew dames proceed.\nFor these are a partition wall, whereby\nThe sacred stairs are sever\'d, as the faith\nIn Christ divides them.  On this part, where blooms\nEach leaf in full maturity, are set\nSuch as in Christ, or ere he came, believ\'d.\nOn th\' other, where an intersected space\nYet shows the semicircle void, abide\nAll they, who look\'d to Christ already come.\nAnd as our Lady on her glorious stool,\nAnd they who on their stools beneath her sit,\nThis way distinction make: e\'en so on his,\nThe mighty Baptist that way marks the line\n(He who endur\'d the desert and the pains\nOf martyrdom, and for two years of hell,\nYet still continued holy), and beneath,\nAugustin, Francis, Benedict, and the rest,\nThus far from round to round.  So heav\'n\'s decree\nForecasts, this garden equally to fill.\nWith faith in either view, past or to come,\nLearn too, that downward from the step, which cleaves\nMidway the twain compartments, none there are\nWho place obtain for merit of their own,\nBut have through others\' merit been advanc\'d,\nOn set conditions: spirits all releas\'d,\nEre for themselves they had the power to choose.\nAnd, if thou mark and listen to them well,\nTheir childish looks and voice declare as much.\n     \"Here, silent as thou art, I know thy doubt;\nAnd gladly will I loose the knot, wherein\nThy subtle thoughts have bound thee.  From this realm\nExcluded, chalice no entrance here may find,\nNo more shall hunger, thirst, or sorrow can.\nA law immutable hath establish\'d all;\nNor is there aught thou seest, that doth not fit,\nExactly, as the finger to the ring.\nIt is not therefore without cause, that these,\nO\'erspeedy comers to immortal life,\nAre different in their shares of excellence.\nOur Sovran Lord--that settleth this estate\nIn love and in delight so absolute,\nThat wish can dare no further--every soul,\nCreated in his joyous sight to dwell,\nWith grace at pleasure variously endows.\nAnd for a proof th\' effect may well suffice.\nAnd \'t is moreover most expressly mark\'d\nIn holy scripture, where the twins are said\nTo, have struggled in the womb.  Therefore, as grace\nInweaves the coronet, so every brow\nWeareth its proper hue of orient light.\nAnd merely in respect to his prime gift,\nNot in reward of meritorious deed,\nHath each his several degree assign\'d.\nIn early times with their own innocence\nMore was not ");
    strcat(expected_filecontent, "wanting, than the parents\' faith,\nTo save them: those first ages past, behoov\'d\nThat circumcision in the males should imp\nThe flight of innocent wings:  but since the day\nOf grace hath come, without baptismal rites\nIn Christ accomplish\'d, innocence herself\nMust linger yet below.  Now raise thy view\nUnto the visage most resembling Christ:\nFor, in her splendour only, shalt thou win\nThe pow\'r to look on him.\"  Forthwith I saw\nSuch floods of gladness on her visage shower\'d,\nFrom holy spirits, winging that profound;\nThat, whatsoever I had yet beheld,\nHad not so much suspended me with wonder,\nOr shown me such similitude of God.\nAnd he, who had to her descended, once,\nOn earth, now hail\'d in heav\'n; and on pois\'d wing.\n\"Ave, Maria, Gratia Plena,\" sang:\nTo whose sweet anthem all the blissful court,\nFrom all parts answ\'ring, rang: that holier joy\nBrooded the deep serene.  \"Father rever\'d:\nWho deign\'st, for me, to quit the pleasant place,\nWherein thou sittest, by eternal lot!\nSay, who that angel is, that with such glee\n");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "TAKE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6686] = "";

                strcat(expected_filecontent, "But who is he observes them?  None; not he,\nWho goes before, the shepherd of the flock,\nWho chews the cud but doth not cleave the hoof.\nTherefore the multitude, who see their guide\nStrike at the very good they covet most,\nFeed there and look no further.  Thus the cause\nIs not corrupted nature in yourselves,\nBut ill-conducting, that hath turn\'d the world\nTo evil.  Rome, that turn\'d it unto good,\nWas wont to boast two suns, whose several beams\nCast light on either way, the world\'s and God\'s.\nOne since hath quench\'d the other; and the sword\nIs grafted on the crook; and so conjoin\'d\nEach must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and the Po\nTheir waters roll, was once the residence\nOf courtesy and velour, ere the day,\nThat frown\'d on Frederick; now secure may pass\nThose limits, whosoe\'er hath left, for shame,\nTo talk with good men, or come near their haunts.\nThree aged ones are still found there, in whom\nThe old time chides the new: these deem it long\nEre God restore them to a better world:\nThe good Gherardo, of Palazzo he\nConrad, and Guido of Castello, nam\'d\nIn Gallic phrase more fitly the plain Lombard.\nOn this at last conclude.  The church of Rome,\nMixing two governments that ill assort,\nHath miss\'d her footing, fall\'n into the mire,\nAnd there herself and burden much defil\'d.\"\n     \"O Marco!\" I replied, shine arguments\nConvince me: and the cause I now discern\nWhy of the heritage no portion came\nTo Levi\'s offspring.  But resolve me this\nWho that Gherardo is, that as thou sayst\nIs left a sample of the perish\'d race,\nAnd for rebuke to this untoward age?\"\n     \"Either thy words,\" said he, \"deceive; or else\nAre meant to try me; that thou, speaking Tuscan,\nAppear\'st not to have heard of good Gherado;\nThe sole addition that, by which I know him;\nUnless I borrow\'d from his daughter Gaia\nAnother name to grace him.  God be with you.\nI bear you company no more.  Behold\nThe dawn with white ray glimm\'ring through the mist.\nI must away--the angel comes--ere he\nAppear.\"  He said, and would not hear me more.\n\n\n\nCANTO XVII\n\nCall to remembrance, reader, if thou e\'er\nHast, on a mountain top, been ta\'en by cloud,\nThrough which thou saw\'st no better, than the mole\nDoth through opacous membrane; then, whene\'er\nThe wat\'ry vapours dense began to melt\nInto thin air, how faintly the sun\'s sphere\nSeem\'d wading through them; so thy nimble thought\nMay image, how at first I re-beheld\nThe sun, that bedward now his couch o\'erhung.\n     Thus with my leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, ");
    strcat(expected_filecontent, "outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing it loves,\nAll fro");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DESCRIBE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6685; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7243] = "";

                strcat(expected_filecontent, "roverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye commands\nFor sight no obstacle found here, nor shade, But all sunshine.\nMilton, P. l. b. iii.  616.\n\nv. 135.  Of the great Harry.]  The Emperor Henry VII, who died in\n1313.\n\nv. 141.  He.]  Pope Clement V. See Canto XXVII.  53.\n\nv. 145.  Alagna\'s priest.]  Pope Boniface VIII.  Hell, Canto XIX.\n\n79.\n\nCANTO XXXI\n\nv. 6.  Bees.]  Compare Homer, Iliad, ii.  87. Virg.  Aen. I. 430,\nand Milton, P. L. b. 1.  768.\n\nv. 29.  Helice.]  Callisto, and her son Arcas, changed into the\nconstellations of the Greater Bear and Arctophylax, or Bootes.\nSee Ovid, Met.  l. ii. fab. v. vi.\n\nv. 93.  Bernard.]  St. Bernard, the venerable abbot of Clairvaux,\nand the great promoter of the second crusade, who died A.D. 1153,\nin his sixty-third year.  His sermons are called by Henault,\n\"chefs~d\'oeuvres de sentiment et de force.\"  Abrege Chron. de\nl\'Hist.  de Fr. 1145. They have even been preferred to al1 the\nproductions of the ancients, and the author has been termed the\nlast of the fathers of the church. It is uncertain whether they\nwere not delivered originally in the French tongue.\n\nThat the part he acts in the present Poem should be assigned to\nhim. appears somewhat remarkable, when we consider that he\nseverely censured the new festival established in honour of the\nImmaculate Conception of the virgin, and opposed the doctrine\nitself with the greatest vigour, as it supposed her being\nhonoured with a privilegewhich belonged to Christ Alone Dr.\nMaclaine\'s Mosheim, v. iii. cent. xii. p. ii. c. 3 - 19.\n\nv. 95.  Our Veronica ] The holy handkerchief, then preserved at\nRome, on which the countenance of our Saviour was supposed to\nhave be");
    strcat(expected_filecontent, "en imprest.\n\nv. 101.  Him.]  St. Bernard.\n\nv. 108.  The queen.]  The Virgin Mary.\n\nv. 119.  Oriflamb.]  Menage on this word quotes the Roman des\nRoyau\n-Iignages of Guillaume Ghyart.\nOriflamme est une banniere\nDe cendal roujoyant et simple\nSans portraiture d\'autre affaire,\n\nCANTO XXXII\n\nv. 3.  She.]  Eve.\n\nv. 8.  Ancestress.]  Ruth, the ancestress of David.\n\nv. 60.  In holy scripture.]  Gen. c. xxv.  22.\nv. 123.  Lucia.]  See Hell, Canto II.  97.\n\nCANTO XXXIII\n\nv. 63.  The Sybil\'s sentence.]  Virg.  Aen.  iii. 445.\n\nv. 89.  One moment.]  \"A moment seems to me more tedious, than\nfive-and-twenty ages would have appeared to the Argonauts, when\nthey had resolved on their expedition.\n\nv. 92.  Argo\'s shadow]\nQuae simul ac rostro ventosnm proscidit aequor,\nTortaque remigio spumis incanduit unda,\nEmersere feri candenti e gurgite vultus\nAequoreae monstrum Nereides admirantes.\nCatullus, De Nupt.  Pel.  et Thet.  15.\n\nv. 109.  Three orbs of triple hue, clipt in one bound.]  The\nTrinity.\n\nv. 118.  That circling.]  The second of the circles, \"Light of\nLight,\" in which he dimly beheld the mystery of the incarnation.\n\n\n\n\n\nEnd Paradise.\n\n\n\n\n\nPREFACE\n\nIn the years 1805 and 1806, I published the first part of the\nfollowing translation, with the text of the original.  Since that\nperiod, two impressions of the whole of the Divina Commedia, in\nItalian, have made their appearance in this country.  It is not\nnecessary that I should add a third: and I am induced to hope\nthat the Poem, even in the present version of it, may not be\nwithout interest for the mere English reader.\n\nThe translation of the second and third parts, \"The Purgatory\"\nand \"The Paradise,\" was begun long before the first, and as early\nas the year 1797; but, owing to many interruptions, not concluded\ntill the summer before last.  On a retrospect of the time and\nexertions that have been thus employed, I do not regard those\nhours as the least happy of my  life, during which (to use the\neloquent language of Mr. Coleridge) \"my individual recollections\nhave been suspended, and lulled to sleep amid the music of nobler\nthoughts;\"  nor that study as misapplied, which has familiarized\nme with one of the sublimest efforts of the human invention.\n\nTo those, who shall be at the trouble of examining into the\ndegree of accuracy with which the task has been executed, I may\nbe allowed to suggest, that their judgment should not be formed\non a comparison with any single text of my Author; since, in more\ninstances than I have noticed, I have had to make my choice out\nof a variety of readings and interpretations, presented by\ndifferent editions and commentators.\n\nIn one or two of those editions is to be found the title of \"The\nVision,\" which I have adopted, as more conformable to the genius\nof our language than that of \"The Divine Comedy.\"  Dante himself,\nI believe, termed it simply \"The Comedy;\" in the first place,\nbecause the style was of the middle kind:  and in the next,\nbecause the story (if story it may be called) ends happily.\n\nInstead of a Life of my Author, I have subjoined, in\nchronological order, a view not only of the principal events\nwhich befell him, but");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DANGER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7242; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[132] = "";

                strcat(expected_filecontent, "nd\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "TEST.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 131; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5980] = "";

                strcat(expected_filecontent, " Arabian Phoenix, when five hundred years\nHave well nigh circled, dies, and springs forthwith\nRenascent.  Blade nor herb throughout his life\nHe tastes, but tears of frankincense alone\nAnd odorous amomum:  swaths of nard\nAnd myrrh his funeral shroud.  As one that falls,\nHe knows not how, by force demoniac dragg\'d\nTo earth, or through obstruction fettering up\nIn chains invisible the powers of man,\nWho, risen from his trance, gazeth around,\nBewilder\'d with the monstrous agony\nHe hath endur\'d, and wildly staring sighs;\nSo stood aghast the sinner when he rose.\n     Oh!  how severe God\'s judgment, that deals out\nSuch blows in stormy vengeance!  Who he was\nMy teacher next inquir\'d, and thus in few\nHe answer\'d:  \"Vanni Fucci am I call\'d,\nNot long since rained down from Tuscany\nTo this dire gullet.  Me the beastial life\nAnd not the human pleas\'d, mule that I was,\nWho in Pistoia found my worthy den.\"\n     I then to Virgil:  \"Bid him stir not hence,\nAnd ask what crime did thrust him hither:  once\nA man I knew him choleric and bloody.\"\n     The sinner heard and feign\'d not, but towards me\nHis mind directing and his face, wherein\nWas dismal shame depictur\'d, thus he spake:\n\"It grieves me more to have been caught by thee\nIn this sad plight, which thou beholdest, than\nWhen I was taken from the other life.\nI have no power permitted to deny\nWhat thou inquirest.\"  I am doom\'d thus low\nTo dwell, for that the sacristy by me\nWas rifled of its goodly ornaments,\nAnd with the guilt another falsely charged.\nBut that thou mayst not joy to see me thus,\nSo as thou e\'er shalt \'scape this darksome realm\nOpen thine ears and hear what I forebode.\nReft of the Neri first Pistoia pines,\nThen Florence changeth citizens and laws.\nFrom Valdimagra, drawn by wrathful Mars,\nA vapour rises, wrapt in turbid mists,\nAnd sharp and eager driveth on the storm\nWith arrowy hurtling o\'er Piceno\'s field,\nWhence suddenly the cloud shall burst, and strike\nEach helpless Bianco prostrate to the ground.\nThis have I told, that grief may rend thy heart.\"\n\n\n\nCANTO XXV\n\nWHEN he had spoke, the sinner rais\'d his hands\nPointed in mockery, and cried:  \"Take them, God!\nI level them at thee!\"  From that day forth\nThe serpents were my friends; for round his neck\nOne of then rolling twisted, as it said,\n\"Be silent, tongue!\"  Another to his arms\nUpgliding, tied them, riveting itself\nSo close, it took from them the power to move.\n     Pistoia!  Ah Pistoia!  why dost doubt\nTo turn thee into ashes, cumb\'ring earth\nNo longer, since in evil act so far\nThou hast outdone thy seed?  I did not mark,\nThrough all the gloomy circles of the\' abyss,\nSpirit, that swell\'d so proudly \'gainst his God,\nNot him, who headlong fell from Thebes.  He fled,\nNor utter\'d more; and after him there came\nA centaur full of fury, shouting, \"Where\nWhere is the caitiff?\"  On Maremma\'s marsh\nSwarm not the serpent tribe, as on his haunch\nThey swarm\'d, to where the human face begins.\nBehind his head upon the shoulders lay,\nWith open wings, a dragon breathing fire\nOn whomsoe\'er he met.  To me my guide:\n\"Cacus is this, who underneath the rock\nOf Aventine spread oft a lake of blood.\nHe, from his brethren parted, here must tread\nA different journey, for his fraudful theft\nOf the great herd, that near him stall\'d; whence found\nHis felon deeds their end, beneath the mace\nOf stout Alcides, that perchance laid on\nA hundred blows, and not the tenth was felt.\"\n     While yet he spake, the centaur sped away:\nAnd under us three spirits came, of whom\nNor I nor he was ware, till they exclaim\'d;\n\"Say who are ye?\"  We then brake off discourse,\nIntent on these alone.  I knew them not;\nBut, as it chanceth oft, befell, that one\nHad need to name another.  \"Where,\" said he,\n\"Doth Cianfa lurk?\"  I, for a sign my guide\nShould stand attentive, plac\'d against my lips\nThe finger lifted.  If, O reader!  now\nThou be not apt to credit what I tell,\nNo marvel; for myself do scarce allow\nThe witness of mine eyes.  But as I looked\nToward them, lo!  a serpent with six feet\nSprings forth on one, and fastens full upon him:\nHis midmost grasp\'d the belly, a fore");
    strcat(expected_filecontent, "foot\nSeiz\'d on each arm (while deep in either cheek\nHe flesh\'d his fangs); the hinder on the thighs\nWere spread, \'twixt which the tail inserted curl\'d\nUpon the reins behind.  Ivy ne\'er clasp\'d\nA dodder\'d oak, as round the other\'s limbs\nThe hideous monster intertwin\'d his own.\nThen, as they both had been of burning wax,\nEach melted into other, mingling hues,\nThat which was either now was seen no more.\nThus up the shrinking paper, ere it burns,\nA brown tint glides, not turning yet to black,\nAnd the clean white expires.  The other two\nLook\'d on exclaiming:  \"Ah, how dost thou change,\nAgnello!  See!  Thou art nor double now,\nNor only one.\"  The two heads now became\nOne, and two figures blended in one form\nAppear\'d, where both were lost.  Of the four lengths\nTwo arms were made:  the belly and the chest\nThe thighs and legs into such members chang\'d,\nAs never eye hath seen.  Of former shape\nAll trace was vanish\'d.  Two yet neither seem\'d\nThat image miscreate, and so pass\'d on\nWith tardy steps.  As underneath the scourge\nOf the fierce dog-star, that lays bare the fields,\nShifting from brake to brake, the lizard seems\nA flash of lightning, if he thwart the road,\nSo toward th\' entrails of the other two\nApproaching seem\'d, an adder all on fire,\nAs the dark pepper-grain, livid and swart.\nIn that part, whence our life is nourish\'d first,\nOne he transpierc\'d; then down before him fell\nStretch\'d out.  The pierced spirit look\'d on him\nBut spake not; yea stood motionless and yawn\'d,\nAs if by sleep or fev\'rous fit assail\'d.\nHe ey\'d the serpent, and the serpent him.\nOne from the wound, the other from the mouth\nBreath\'d a thick smoke, whose vap\'ry columns join\'d.\n     Lucan in mute attention now may hear,\nNor thy disastrous fate, Sabellus!  tell,\nNor shine, Nasidius!  Ovid now be mute.\nWhat if in warbling fiction he record\nCadmus and Arethusa, to a snake\nHim chang\'d, and ");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "REQUIRE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5979; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7697] = "";

                strcat(expected_filecontent, "it were detained in the snare you\nhave spread for me, so as to be somewhat prolix in my answer.\"\n\nv. 60. I it was.]  Pietro delle Vigne, a native of Capua, who,\nfrom a low condition, raised himself by his eloquence and legal\nknowledge to the office of Chancellor to the Emperor Frederick\nII. whose confidence in him was such, that his influence in the\nempire became unbounded.  The courtiers, envious of his exalted\nsituation, contrived, by means of forged letters, to make\nFrederick believe that he held a secret and traitorous\nintercourse with the Pope, who was then at enmity with the\nEmperor.  In consequence of this supposed crime he was cruelly\ncondemned by his too credulous sovereign to lose his eyes, and,\nbeing driven to despair by his unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n61.\n\nv. 28.  As, in the torrid Indian clime.]  Landino refers to\nAlbertus Magnus for the circumstance here alluded to.\n\nv. 53.  In Mongibello.]\n        More hot than Aetn\' or flaming Mongibell.\n               Spenser, F. Q. b. ii. c. ix. st. 29.\nSee Virg. Aen. 1. viii. 416. and Berni. Orl. Inn 1. i. c. xvi.\nst. 21.  It would be endless to refer to parallel passages in the\nGreek writers.\n\nv. 64.  This of the seven kings was one.]  Compare Aesch.  Seven\nChiefs, 425.  Euripides, Phoen. 1179 and Statius. Theb. l. x.\n821.\n\nv. 76.  Bulicame.]  A warm medicinal spring near Viterbo, the\nwaters of which, as Landino and Vellutelli affirm, passed by a\nplace of ill fame.  Venturi, with less probability, conjectures\nthat Dante would imply, that it was the scene of much licentious\nmerriment among those who frequented its baths.\n\nv. 91.  Under whose monarch.]\n        Credo pudicitiam Saturno rege moratam\n        In terris.\n               Juv. Satir. vi.\n\nv. 102.  His head.]  Daniel, ch. ii. 32, 33.\n\nv. 133.  Whither.] On the other side of Purgatory.\n\nCANTO XV\n\n v. 10.  Chiarentana.]  A part of the Alps where the Brenta\nrises, which river is much ");
    strcat(expected_filecontent, "swoln as soon as the snow begins to\ndissolve on the mountains.\n\nv. 28.  Brunetto.]  \"Ser Brunetto, a Florentine, the secretary or\nchancellor of the city, and Dante\'s preceptor, hath left us a\nwork so little read, that both the subject of it and the language\nof it have been mistaken.  It is in the French spoken in the\nreign of St. Louis,under the title of Tresor, and contains a\nspecies of philosophical course of lectures divided into theory\nand practice, or, as he expresses it, \"un enchaussement des\nchoses divines et humaines,\" &c.  Sir R. Clayton\'s Translation of\nTenhove\'s Memoirs of the  Medici, vol. i.  ch.  ii.  p. 104.  The\nTresor has never been printed in the original language.  There is\na fine manuscript of it in the British Museum, with an\nilluminated portrait of Brunetto in his  study prefixed.  Mus.\nBrit. MSS. 17, E. 1. Tesor.  It is divided into four books, the\nfirst, on Cosmogony and Theology, the second, a translation of\nAristotle\'s Ethics; the third on Virtues and Vices; the fourth,\non Rhetoric.  For an interesting memoir relating to this work,\nsee Hist. de l\'Acad. des Inscriptions, tom. vii. 296.  His\nTesoretto, one of the earliest productions of Italian poetry, is\na curious work, not unlike the writings of Chaucer in style and\nnumbers, though Bembo remarks, that his pupil, however largely he\nhad stolen from it, could not have much enriched himself.  As it\nis perhaps but little known, I will here add a slight sketch of\nit.\n\nBrunetto describes himself as returning from an embassy to the\nKing of Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded b");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HAT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7696; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7608] = "";

                strcat(expected_filecontent, ",\nOr Africanus\': e\'en the sun\'s itself\nWere poor to this, that chariot of the sun\nErroneous, which in blazing ruin fell\nAt Tellus\' pray\'r devout, by the just doom\nMysterious of all-seeing Jove.  Three nymphs\n,k the right wheel, came circling in smooth dance;\nThe one so ruddy, that her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and keen edge,\nE\'en as I view\'d it with the flood between,\nAppall\'d me.  Next four others I beheld,\nOf humble seeming: and, behind them all,\nOne single old man, sleeping, as he came,\nWith a shrewd visage.  And these seven, each\nLike the first troop were habited, hut wore\nNo braid of lilies on their temples wreath\'d.\nRather with roses and each vermeil flower,\nA sight, but little distant, might have sworn,\nThat they were all on fire above their brow.\n     Whenas the car was o\'er against me, straight.\nWas heard a thund\'ring, at whose voice it seem\'d\nThe chosen multitude were stay\'d; for there,\nWith the first ensigns, made they solemn halt.\n\n\n\nCANTO XXX\n\nSoon as the polar light, which never knows\nSetting nor rising, nor the shadowy veil\nOf other cloud than sin, fair ornament\nOf the first heav\'n, to duty each one there\nSafely convoying, as that lower doth\nThe steersman to his port, stood firmly fix\'d;\nForthwith the saintly tribe, who in the van\nBetween the Gryphon and its radiance came,\nDid turn them to the car, as to their rest:\nAnd one, as if commission\'d from above,\nIn holy chant thrice shorted forth aloud:\n\"Come, spouse, from Libanus!\" and all the rest\nTook up the song--At the last audit so\nThe blest shall rise, from forth his cavern each\nUplifting lightly his new-vested flesh,\nAs, on the sacred litter, at the voice\nAuthoritative of that elder, sprang\nA hundred ministers and messengers\nOf life eternal.  \"Blessed thou!  who com\'st!\"\nAnd, \"O,\" they cried, \"from full hands scatter ye\nUnwith\'ring lilies;\" and, so saying, cast\nFlowers over head and round them on all sides.\n     I have beheld, ere now, at break of day,\nThe eastern clime all roseate, and the sky\nOppos\'d, one deep and beautiful serene,\nAnd the sun\'s face so shaded, and with mists\nAttemper\'d at lids rising, that the eye\nLong while endur\'d the sight: thus in a cloud\nOf flowers, that from those hands angelic rose,\nAnd down, within and outside of the car,\nFell showering, in white veil with olive wreath\'d,\nA virgin in my view appear\'d, beneath\nGreen mantle, rob\'d in hue of living flame:\nAnd o\'er my Spirit, that in former days\nWithin her presence had abode so long,\nNo shudd\'ring terror crept.  Mine eyes no more\nHad knowledge of her; yet there mov\'d from her\nA hidden virtue, at whose touch awak\'d,\nThe power of ancient love was strong within me.\n     No sooner on my vision streaming, smote\nThe heav\'nly influence, which years past, and e\'en\nIn childhood, thrill\'d me, than towards Virgil I\nTurn\'d me to leftward, panting, like a babe,\nThat flees for refuge to his mother\'s breast,\nIf aught have terrified or work\'d him woe:\nAnd would have cried:  \"There is no dram of blood,\nThat doth not quiver in me.  The old flame\nThrows out clear tokens of reviving fire:\"\nBut Virgil had bereav\'d us of himself,\nVirgil, my best-lov\'d father; Virgil, he\nTo whom I gave me up for safety: nor,\nAll, our prime mother lost, avail\'d to save\nMy undew\'d cheeks from blur of soiling tears.\n     \"Dante, weep not, that Virgil leaves thee: nay,\nWeep thou n");
    strcat(expected_filecontent, "ot yet: behooves thee feel the edge\nOf other sword, and thou shalt weep for that.\"\n     As to the prow or stern, some admiral\nPaces the deck, inspiriting his crew,\nWhen \'mid the sail-yards all hands ply aloof;\nThus on the left side of the car I saw,\n(Turning me at the sound of mine own name,\nWhich here I am compell\'d to register)\nThe virgin station\'d, who before appeared\nVeil\'d in that festive shower angelical.\n     Towards me, across the stream, she bent her eyes;\nThough from her brow the veil descending, bound\nWith foliage of Minerva, suffer\'d not\nThat I beheld her clearly; then with act\nFull royal, still insulting o\'er her thrall,\nAdded, as one, who speaking keepeth back\nThe bitterest saying, to conclude the speech:\n\"Observe me well.  I am, in sooth, I am\nBeatrice.  What!  and hast thou deign\'d at last\nApproach the mountain?  knewest not, O man!\nThy happiness is whole?\"  Down fell mine eyes\nOn the clear fount, but there, myself espying,\nRecoil\'d, and sought the greensward: such a weight\nOf shame was on my forehead.  With a mien\nOf that stern majesty, which doth surround\nmother\'s presence to her awe-struck child,\nShe look\'d; a flavour of such bitterness\nWas mingled in her pity.  There her words\nBrake off, and suddenly the angels sang:\n\"In thee, O gracious Lord, my hope hath been:\"\nBut went no farther than, \"Thou Lord, hast set\nMy feet in ample room.\"  As snow, that lies\nAmidst the living rafters on the back\nOf Italy congeal\'d when drifted high\nAnd closely pil\'d by rough Sclavonian blasts,\nBreathe but the land whereon no shadow falls,\nAnd straightway melting it distils away,\nLike a fire-wasted taper: thus was I,\nWithout a sigh or tear, or ever these\nDid sing, that with the chiming of heav\'n\'s sphere,\nStill in their warbling chime: but when the strain\nOf dulcet symphony, express\'d for me\nTheir soft compassion, more than could the words\n\"Virgin, why so consum\'st him?\"  then the ice,\nCongeal\'d about my bosom, turn\'d itself\nTo spirit and water, and with anguish forth\nGush\'d through the lips and eyelids from the heart.\n     Upon the chariot\'s right edge still she stood,\nImmovable, and thus address\'d her words\nTo those bright semblances with pity touch\'d:\n\"Ye in th\' eternal day your vigils keep,\nSo that nor night nor slumber, with close stealth,\nConveys from you a single step in all\nThe goings on of life: thence with more heed\nI shape mine answer, for his ear intended,\nWho there stands weeping, that the sorrow now\nMay equal the transgression.  Not alone\nThrough operation of the mighty orbs,\nThat mark each seed to some predestin\'d aim,\nAs with aspect or fortunate or ill\nThe constellations meet, but through benign\nLargess of heav\'nly graces, which rain down\nFrom such a height, as mocks our vision, this man\nWas in the freshness of his being, such,\nSo gifted virtually, that in him\nAll better habits wond\'rously had thriv\'d.\nThe more of kindly strength is in the soil,\nSo much doth evil seed and lack of culture\nMar it the more, and make it run to wildness.\nThese looks sometime upheld him; for I show\'d\nMy youthful eyes, and led him by their light\nIn upright walking.  Soon as I had reach\'d\nThe threshold of my second age, and chang\'d\nMy mortal for immortal, then he left me,\nAnd gave himself to others.  When from flesh\nTo spirit I had risen, and increase\nOf beauty and of virtue circled me,\nI was less dear to him, and valued less.\nHis steps were turn\'d into deceitful ways,\nFollowing false images of good, that make\nNo promise perfect.  Nor avail\'d me aught\nTo sue fo");

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "NATION");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7607; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(5120, 1);
            char expected_filecontent[5121] = "";

            strcat(expected_filecontent, "e eyes are held\nStill in this depth below.  But search around\nThe circles, to the furthest, till thou spy\nSeated in state, the queen, that of this realm\nIs sovran.\"  Straight mine eyes I rais\'d; and bright,\nAs, at the birth of morn, the eastern clime\nAbove th\' horizon, where the sun declines;\nTo mine eyes, that upward, as from vale\nTo mountain sped, at th\' extreme bound, a part\nExcell\'d in lustre all the front oppos\'d.\nAnd as the glow burns ruddiest o\'er the wave,\nThat waits the sloping beam, which Phaeton\nIll knew to guide, and on each part the light\nDiminish\'d fades, intensest in the midst;\nSo burn\'d the peaceful oriflamb, and slack\'d\nOn every side the living flame decay\'d.\nAnd in that midst their sportive pennons wav\'d\nThousands of angels; in resplendence each\nDistinct, and quaint adornment. At their glee\nAnd carol, smil\'d the Lovely One of heav\'n,\nThat joy was in the eyes of all the blest.\n     Had I a tongue in eloquence as rich,\nAs is the colouring in fancy\'s loom,\n\'T were all too poor to utter the least part\nOf that enchantment.  When he saw mine eyes\nIntent on her, that charm\'d him, Bernard gaz\'d\nWith so exceeding fondness, as infus\'d\nArdour into my breast, unfelt before.\n\n\n\nCANTO XXXII\n\nFreely the sage, though wrapt in musings high,\nAssum\'d the teacher\'s part, and mild began:\n\"The wound, that Mary clos\'d, she open\'d first,\nWho sits so beautiful at Mary\'s feet.\nThe third in order, underneath her, lo!\nRachel with Beatrice. Sarah next,\nJudith, Rebecca, and the gleaner maid,\nMeek ancestress of him, who sang the songs\nOf sore repentance in his sorrowful mood.\nAll, as I name them, down from deaf to leaf,\nAre in gradation throned on the rose.\nAnd from the seventh step, successively,\nAdown the breathing tresses of the flow\'r\nStill doth the file of Hebrew dames proceed.\nFor these are a partition wall, whereby\nThe sacred stairs are sever\'d, as the faith\nIn Christ divides them.  On this part, where blooms\nEach leaf in full maturity, are set\nSuch as in Christ, or ere he came, believ\'d.\nOn th\' other, where an intersected space\nYet shows the semicircle void, abide\nAll they, who look\'d to Christ already come.\nAnd as our Lady on her glorious stool,\nAnd they who on their stools beneath her sit,\nThis way distinction make: e\'en so on his,\nThe mighty Baptist that way marks the line\n(He who endur\'d the desert and the pains\nOf martyrdom, and for two years of hell,\nYet still continued holy), and beneath,\nAugustin, Francis, Benedict, and the rest,\nThus far from round to round.  So heav\'n\'s decree\nForecasts, this garden equally to fill.\nWith faith in either view, past or to come,\nLearn too, that downward from the step, which cleaves\nMidway the twain compartments, none there are\nWho place obtain for merit of their own,\nBut have through others\' merit been advanc\'d,\nOn set conditions: spirits all releas\'d,\nEre for themselves they had the power to choose.\nAnd, if thou mark and listen to them well,\nTheir childish looks and voice declare as much.\n     \"Here, silent as thou art, I know thy doubt;\nAnd gladly will I loose the knot, wherein\nThy subtle thoughts have bound thee.  From this realm\nExcluded, chalice no entrance here may find,\nNo more shall hunger, thirst, or sorrow can.\nA law immutable hath establish\'d all;\nNor is there aught thou seest, that doth not fit,\nExactly, as the finger to the ring.\nIt is not therefore without cause, that these,\nO\'erspeedy comers to immortal life,\nAre different in their shares of excellence.\nOur Sovran Lord--that settleth this estate\nIn love and in delight so absolute,\nThat wish can dare no further--every soul,\nCreated in his joyous sight to dwell,\nWith grace at pleasure variously endows.\nAnd for a proof th\' effect may well suffice.\nAnd \'t is moreover most expressly mark\'d\nIn holy scripture, where the twins are said\nTo, have struggled in the womb.  Therefore, as grace\nInweaves the coronet, so every brow\nWeareth its proper hue of orient light.\nAnd merely in respect to his prime gift,\nNot in reward of meritorious deed,\nHath each his several degree assign\'d.\nIn early times with their own innocence\nMore was not ");
    strcat(expected_filecontent, "wanting, than the parents\' faith,\nTo save them: those first ages past, behoov\'d\nThat circumcision in the males should imp\nThe flight of innocent wings:  but since the day\nOf grace hath come, without baptismal rites\nIn Christ accomplish\'d, innocence herself\nMust linger yet below.  Now raise thy view\nUnto the visage most resembling Christ:\nFor, in her splendour only, shalt thou win\nThe pow\'r to look on him.\"  Forthwith I saw\nSuch floods of gladness on her visage shower\'d,\nFrom holy spirits, winging that profound;\nThat, whatsoever I had yet beheld,\nHad not so much suspended me with wonder,\nOr shown me such similitude of God.\nAnd he, who had to her descended, once,\nOn earth, now hail\'d in heav\'n; and on pois\'d wing.\n\"Ave, Maria, Gratia Plena,\" sang:\nTo whose sweet anthem all the blissful court,\nFrom all parts answ\'ring, rang: that holier joy\nBrooded the deep serene.  \"Father rever\'d:\nWho deign\'st, for me, to quit the pleasant place,\nWherein thou sittest, by eternal lot!\nSay, who that angel is, that with such glee\n");

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "TAKE.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 426; ++i)
            {
                int res = file_read(filecontent + 12 * i, 12, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 12 * i, 12, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5120);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 5120);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(5120, 1);
    char *filecontent1 = (char *)calloc(6685, 1);
    char *filecontent2 = (char *)calloc(7242, 1);
    char *filecontent3 = (char *)calloc(131, 1);
    char *filecontent4 = (char *)calloc(5979, 1);
    char *filecontent5 = (char *)calloc(7696, 1);
    char *filecontent6 = (char *)calloc(7607, 1);

            char expected_filecontent0[5121] = "";
    char expected_filecontent1[6686] = "";
    char expected_filecontent2[7243] = "";
    char expected_filecontent3[132] = "";
    char expected_filecontent4[5980] = "";
    char expected_filecontent5[7697] = "";
    char expected_filecontent6[7608] = "";

            strcat(expected_filecontent0, "e eyes are held\nStill in this depth below.  But search around\nThe circles, to the furthest, till thou spy\nSeated in state, the queen, that of this realm\nIs sovran.\"  Straight mine eyes I rais\'d; and bright,\nAs, at the birth of morn, the eastern clime\nAbove th\' horizon, where the sun declines;\nTo mine eyes, that upward, as from vale\nTo mountain sped, at th\' extreme bound, a part\nExcell\'d in lustre all the front oppos\'d.\nAnd as the glow burns ruddiest o\'er the wave,\nThat waits the sloping beam, which Phaeton\nIll knew to guide, and on each part the light\nDiminish\'d fades, intensest in the midst;\nSo burn\'d the peaceful oriflamb, and slack\'d\nOn every side the living flame decay\'d.\nAnd in that midst their sportive pennons wav\'d\nThousands of angels; in resplendence each\nDistinct, and quaint adornment. At their glee\nAnd carol, smil\'d the Lovely One of heav\'n,\nThat joy was in the eyes of all the blest.\n     Had I a tongue in eloquence as rich,\nAs is the colouring in fancy\'s loom,\n\'T were all too poor to utter the least part\nOf that enchantment.  When he saw mine eyes\nIntent on her, that charm\'d him, Bernard gaz\'d\nWith so exceeding fondness, as infus\'d\nArdour into my breast, unfelt before.\n\n\n\nCANTO XXXII\n\nFreely the sage, though wrapt in musings high,\nAssum\'d the teacher\'s part, and mild began:\n\"The wound, that Mary clos\'d, she open\'d first,\nWho sits so beautiful at Mary\'s feet.\nThe third in order, underneath her, lo!\nRachel with Beatrice. Sarah next,\nJudith, Rebecca, and the gleaner maid,\nMeek ancestress of him, who sang the songs\nOf sore repentance in his sorrowful mood.\nAll, as I name them, down from deaf to leaf,\nAre in gradation throned on the rose.\nAnd from the seventh step, successively,\nAdown the breathing tresses of the flow\'r\nStill doth the file of Hebrew dames proceed.\nFor these are a partition wall, whereby\nThe sacred stairs are sever\'d, as the faith\nIn Christ divides them.  On this part, where blooms\nEach leaf in full maturity, are set\nSuch as in Christ, or ere he came, believ\'d.\nOn th\' other, where an intersected space\nYet shows the semicircle void, abide\nAll they, who look\'d to Christ already come.\nAnd as our Lady on her glorious stool,\nAnd they who on their stools beneath her sit,\nThis way distinction make: e\'en so on his,\nThe mighty Baptist that way marks the line\n(He who endur\'d the desert and the pains\nOf martyrdom, and for two years of hell,\nYet still continued holy), and beneath,\nAugustin, Francis, Benedict, and the rest,\nThus far from round to round.  So heav\'n\'s decree\nForecasts, this garden equally to fill.\nWith faith in either view, past or to come,\nLearn too, that downward from the step, which cleaves\nMidway the twain compartments, none there are\nWho place obtain for merit of their own,\nBut have through others\' merit been advanc\'d,\nOn set conditions: spirits all releas\'d,\nEre for themselves they had the power to choose.\nAnd, if thou mark and listen to them well,\nTheir childish looks and voice declare as much.\n     \"Here, silent as thou art, I know thy doubt;\nAnd gladly will I loose the knot, wherein\nThy subtle thoughts have bound thee.  From this realm\nExcluded, chalice no entrance here may find,\nNo more shall hunger, thirst, or sorrow can.\nA law immutable hath establish\'d all;\nNor is there aught thou seest, that doth not fit,\nExactly, as the finger to the ring.\nIt is not therefore without cause, that these,\nO\'erspeedy comers to immortal life,\nAre different in their shares of excellence.\nOur Sovran Lord--that settleth this estate\nIn love and in delight so absolute,\nThat wish can dare no further--every soul,\nCreated in his joyous sight to dwell,\nWith grace at pleasure variously endows.\nAnd for a proof th\' effect may well suffice.\nAnd \'t is moreover most expressly mark\'d\nIn holy scripture, where the twins are said\nTo, have struggled in the womb.  Therefore, as grace\nInweaves the coronet, so every brow\nWeareth its proper hue of orient light.\nAnd merely in respect to his prime gift,\nNot in reward of meritorious deed,\nHath each his several degree assign\'d.\nIn early times with their own innocence\nMore was not ");
    strcat(expected_filecontent0, "wanting, than the parents\' faith,\nTo save them: those first ages past, behoov\'d\nThat circumcision in the males should imp\nThe flight of innocent wings:  but since the day\nOf grace hath come, without baptismal rites\nIn Christ accomplish\'d, innocence herself\nMust linger yet below.  Now raise thy view\nUnto the visage most resembling Christ:\nFor, in her splendour only, shalt thou win\nThe pow\'r to look on him.\"  Forthwith I saw\nSuch floods of gladness on her visage shower\'d,\nFrom holy spirits, winging that profound;\nThat, whatsoever I had yet beheld,\nHad not so much suspended me with wonder,\nOr shown me such similitude of God.\nAnd he, who had to her descended, once,\nOn earth, now hail\'d in heav\'n; and on pois\'d wing.\n\"Ave, Maria, Gratia Plena,\" sang:\nTo whose sweet anthem all the blissful court,\nFrom all parts answ\'ring, rang: that holier joy\nBrooded the deep serene.  \"Father rever\'d:\nWho deign\'st, for me, to quit the pleasant place,\nWherein thou sittest, by eternal lot!\nSay, who that angel is, that with such glee\n");strcat(expected_filecontent1, "But who is he observes them?  None; not he,\nWho goes before, the shepherd of the flock,\nWho chews the cud but doth not cleave the hoof.\nTherefore the multitude, who see their guide\nStrike at the very good they covet most,\nFeed there and look no further.  Thus the cause\nIs not corrupted nature in yourselves,\nBut ill-conducting, that hath turn\'d the world\nTo evil.  Rome, that turn\'d it unto good,\nWas wont to boast two suns, whose several beams\nCast light on either way, the world\'s and God\'s.\nOne since hath quench\'d the other; and the sword\nIs grafted on the crook; and so conjoin\'d\nEach must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and the Po\nTheir waters roll, was once the residence\nOf courtesy and velour, ere the day,\nThat frown\'d on Frederick; now secure may pass\nThose limits, whosoe\'er hath left, for shame,\nTo talk with good men, or come near their haunts.\nThree aged ones are still found there, in whom\nThe old time chides the new: these deem it long\nEre God restore them to a better world:\nThe good Gherardo, of Palazzo he\nConrad, and Guido of Castello, nam\'d\nIn Gallic phrase more fitly the plain Lombard.\nOn this at last conclude.  The church of Rome,\nMixing two governments that ill assort,\nHath miss\'d her footing, fall\'n into the mire,\nAnd there herself and burden much defil\'d.\"\n     \"O Marco!\" I replied, shine arguments\nConvince me: and the cause I now discern\nWhy of the heritage no portion came\nTo Levi\'s offspring.  But resolve me this\nWho that Gherardo is, that as thou sayst\nIs left a sample of the perish\'d race,\nAnd for rebuke to this untoward age?\"\n     \"Either thy words,\" said he, \"deceive; or else\nAre meant to try me; that thou, speaking Tuscan,\nAppear\'st not to have heard of good Gherado;\nThe sole addition that, by which I know him;\nUnless I borrow\'d from his daughter Gaia\nAnother name to grace him.  God be with you.\nI bear you company no more.  Behold\nThe dawn with white ray glimm\'ring through the mist.\nI must away--the angel comes--ere he\nAppear.\"  He said, and would not hear me more.\n\n\n\nCANTO XVII\n\nCall to remembrance, reader, if thou e\'er\nHast, on a mountain top, been ta\'en by cloud,\nThrough which thou saw\'st no better, than the mole\nDoth through opacous membrane; then, whene\'er\nThe wat\'ry vapours dense began to melt\nInto thin air, how faintly the sun\'s sphere\nSeem\'d wading through them; so thy nimble thought\nMay image, how at first I re-beheld\nThe sun, that bedward now his couch o\'erhung.\n     Thus with my leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, ");
    strcat(expected_filecontent1, "outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing it loves,\nAll fro");strcat(expected_filecontent2, "roverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye commands\nFor sight no obstacle found here, nor shade, But all sunshine.\nMilton, P. l. b. iii.  616.\n\nv. 135.  Of the great Harry.]  The Emperor Henry VII, who died in\n1313.\n\nv. 141.  He.]  Pope Clement V. See Canto XXVII.  53.\n\nv. 145.  Alagna\'s priest.]  Pope Boniface VIII.  Hell, Canto XIX.\n\n79.\n\nCANTO XXXI\n\nv. 6.  Bees.]  Compare Homer, Iliad, ii.  87. Virg.  Aen. I. 430,\nand Milton, P. L. b. 1.  768.\n\nv. 29.  Helice.]  Callisto, and her son Arcas, changed into the\nconstellations of the Greater Bear and Arctophylax, or Bootes.\nSee Ovid, Met.  l. ii. fab. v. vi.\n\nv. 93.  Bernard.]  St. Bernard, the venerable abbot of Clairvaux,\nand the great promoter of the second crusade, who died A.D. 1153,\nin his sixty-third year.  His sermons are called by Henault,\n\"chefs~d\'oeuvres de sentiment et de force.\"  Abrege Chron. de\nl\'Hist.  de Fr. 1145. They have even been preferred to al1 the\nproductions of the ancients, and the author has been termed the\nlast of the fathers of the church. It is uncertain whether they\nwere not delivered originally in the French tongue.\n\nThat the part he acts in the present Poem should be assigned to\nhim. appears somewhat remarkable, when we consider that he\nseverely censured the new festival established in honour of the\nImmaculate Conception of the virgin, and opposed the doctrine\nitself with the greatest vigour, as it supposed her being\nhonoured with a privilegewhich belonged to Christ Alone Dr.\nMaclaine\'s Mosheim, v. iii. cent. xii. p. ii. c. 3 - 19.\n\nv. 95.  Our Veronica ] The holy handkerchief, then preserved at\nRome, on which the countenance of our Saviour was supposed to\nhave be");
    strcat(expected_filecontent2, "en imprest.\n\nv. 101.  Him.]  St. Bernard.\n\nv. 108.  The queen.]  The Virgin Mary.\n\nv. 119.  Oriflamb.]  Menage on this word quotes the Roman des\nRoyau\n-Iignages of Guillaume Ghyart.\nOriflamme est une banniere\nDe cendal roujoyant et simple\nSans portraiture d\'autre affaire,\n\nCANTO XXXII\n\nv. 3.  She.]  Eve.\n\nv. 8.  Ancestress.]  Ruth, the ancestress of David.\n\nv. 60.  In holy scripture.]  Gen. c. xxv.  22.\nv. 123.  Lucia.]  See Hell, Canto II.  97.\n\nCANTO XXXIII\n\nv. 63.  The Sybil\'s sentence.]  Virg.  Aen.  iii. 445.\n\nv. 89.  One moment.]  \"A moment seems to me more tedious, than\nfive-and-twenty ages would have appeared to the Argonauts, when\nthey had resolved on their expedition.\n\nv. 92.  Argo\'s shadow]\nQuae simul ac rostro ventosnm proscidit aequor,\nTortaque remigio spumis incanduit unda,\nEmersere feri candenti e gurgite vultus\nAequoreae monstrum Nereides admirantes.\nCatullus, De Nupt.  Pel.  et Thet.  15.\n\nv. 109.  Three orbs of triple hue, clipt in one bound.]  The\nTrinity.\n\nv. 118.  That circling.]  The second of the circles, \"Light of\nLight,\" in which he dimly beheld the mystery of the incarnation.\n\n\n\n\n\nEnd Paradise.\n\n\n\n\n\nPREFACE\n\nIn the years 1805 and 1806, I published the first part of the\nfollowing translation, with the text of the original.  Since that\nperiod, two impressions of the whole of the Divina Commedia, in\nItalian, have made their appearance in this country.  It is not\nnecessary that I should add a third: and I am induced to hope\nthat the Poem, even in the present version of it, may not be\nwithout interest for the mere English reader.\n\nThe translation of the second and third parts, \"The Purgatory\"\nand \"The Paradise,\" was begun long before the first, and as early\nas the year 1797; but, owing to many interruptions, not concluded\ntill the summer before last.  On a retrospect of the time and\nexertions that have been thus employed, I do not regard those\nhours as the least happy of my  life, during which (to use the\neloquent language of Mr. Coleridge) \"my individual recollections\nhave been suspended, and lulled to sleep amid the music of nobler\nthoughts;\"  nor that study as misapplied, which has familiarized\nme with one of the sublimest efforts of the human invention.\n\nTo those, who shall be at the trouble of examining into the\ndegree of accuracy with which the task has been executed, I may\nbe allowed to suggest, that their judgment should not be formed\non a comparison with any single text of my Author; since, in more\ninstances than I have noticed, I have had to make my choice out\nof a variety of readings and interpretations, presented by\ndifferent editions and commentators.\n\nIn one or two of those editions is to be found the title of \"The\nVision,\" which I have adopted, as more conformable to the genius\nof our language than that of \"The Divine Comedy.\"  Dante himself,\nI believe, termed it simply \"The Comedy;\" in the first place,\nbecause the style was of the middle kind:  and in the next,\nbecause the story (if story it may be called) ends happily.\n\nInstead of a Life of my Author, I have subjoined, in\nchronological order, a view not only of the principal events\nwhich befell him, but");strcat(expected_filecontent3, "nd\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all");strcat(expected_filecontent4, " Arabian Phoenix, when five hundred years\nHave well nigh circled, dies, and springs forthwith\nRenascent.  Blade nor herb throughout his life\nHe tastes, but tears of frankincense alone\nAnd odorous amomum:  swaths of nard\nAnd myrrh his funeral shroud.  As one that falls,\nHe knows not how, by force demoniac dragg\'d\nTo earth, or through obstruction fettering up\nIn chains invisible the powers of man,\nWho, risen from his trance, gazeth around,\nBewilder\'d with the monstrous agony\nHe hath endur\'d, and wildly staring sighs;\nSo stood aghast the sinner when he rose.\n     Oh!  how severe God\'s judgment, that deals out\nSuch blows in stormy vengeance!  Who he was\nMy teacher next inquir\'d, and thus in few\nHe answer\'d:  \"Vanni Fucci am I call\'d,\nNot long since rained down from Tuscany\nTo this dire gullet.  Me the beastial life\nAnd not the human pleas\'d, mule that I was,\nWho in Pistoia found my worthy den.\"\n     I then to Virgil:  \"Bid him stir not hence,\nAnd ask what crime did thrust him hither:  once\nA man I knew him choleric and bloody.\"\n     The sinner heard and feign\'d not, but towards me\nHis mind directing and his face, wherein\nWas dismal shame depictur\'d, thus he spake:\n\"It grieves me more to have been caught by thee\nIn this sad plight, which thou beholdest, than\nWhen I was taken from the other life.\nI have no power permitted to deny\nWhat thou inquirest.\"  I am doom\'d thus low\nTo dwell, for that the sacristy by me\nWas rifled of its goodly ornaments,\nAnd with the guilt another falsely charged.\nBut that thou mayst not joy to see me thus,\nSo as thou e\'er shalt \'scape this darksome realm\nOpen thine ears and hear what I forebode.\nReft of the Neri first Pistoia pines,\nThen Florence changeth citizens and laws.\nFrom Valdimagra, drawn by wrathful Mars,\nA vapour rises, wrapt in turbid mists,\nAnd sharp and eager driveth on the storm\nWith arrowy hurtling o\'er Piceno\'s field,\nWhence suddenly the cloud shall burst, and strike\nEach helpless Bianco prostrate to the ground.\nThis have I told, that grief may rend thy heart.\"\n\n\n\nCANTO XXV\n\nWHEN he had spoke, the sinner rais\'d his hands\nPointed in mockery, and cried:  \"Take them, God!\nI level them at thee!\"  From that day forth\nThe serpents were my friends; for round his neck\nOne of then rolling twisted, as it said,\n\"Be silent, tongue!\"  Another to his arms\nUpgliding, tied them, riveting itself\nSo close, it took from them the power to move.\n     Pistoia!  Ah Pistoia!  why dost doubt\nTo turn thee into ashes, cumb\'ring earth\nNo longer, since in evil act so far\nThou hast outdone thy seed?  I did not mark,\nThrough all the gloomy circles of the\' abyss,\nSpirit, that swell\'d so proudly \'gainst his God,\nNot him, who headlong fell from Thebes.  He fled,\nNor utter\'d more; and after him there came\nA centaur full of fury, shouting, \"Where\nWhere is the caitiff?\"  On Maremma\'s marsh\nSwarm not the serpent tribe, as on his haunch\nThey swarm\'d, to where the human face begins.\nBehind his head upon the shoulders lay,\nWith open wings, a dragon breathing fire\nOn whomsoe\'er he met.  To me my guide:\n\"Cacus is this, who underneath the rock\nOf Aventine spread oft a lake of blood.\nHe, from his brethren parted, here must tread\nA different journey, for his fraudful theft\nOf the great herd, that near him stall\'d; whence found\nHis felon deeds their end, beneath the mace\nOf stout Alcides, that perchance laid on\nA hundred blows, and not the tenth was felt.\"\n     While yet he spake, the centaur sped away:\nAnd under us three spirits came, of whom\nNor I nor he was ware, till they exclaim\'d;\n\"Say who are ye?\"  We then brake off discourse,\nIntent on these alone.  I knew them not;\nBut, as it chanceth oft, befell, that one\nHad need to name another.  \"Where,\" said he,\n\"Doth Cianfa lurk?\"  I, for a sign my guide\nShould stand attentive, plac\'d against my lips\nThe finger lifted.  If, O reader!  now\nThou be not apt to credit what I tell,\nNo marvel; for myself do scarce allow\nThe witness of mine eyes.  But as I looked\nToward them, lo!  a serpent with six feet\nSprings forth on one, and fastens full upon him:\nHis midmost grasp\'d the belly, a fore");
    strcat(expected_filecontent4, "foot\nSeiz\'d on each arm (while deep in either cheek\nHe flesh\'d his fangs); the hinder on the thighs\nWere spread, \'twixt which the tail inserted curl\'d\nUpon the reins behind.  Ivy ne\'er clasp\'d\nA dodder\'d oak, as round the other\'s limbs\nThe hideous monster intertwin\'d his own.\nThen, as they both had been of burning wax,\nEach melted into other, mingling hues,\nThat which was either now was seen no more.\nThus up the shrinking paper, ere it burns,\nA brown tint glides, not turning yet to black,\nAnd the clean white expires.  The other two\nLook\'d on exclaiming:  \"Ah, how dost thou change,\nAgnello!  See!  Thou art nor double now,\nNor only one.\"  The two heads now became\nOne, and two figures blended in one form\nAppear\'d, where both were lost.  Of the four lengths\nTwo arms were made:  the belly and the chest\nThe thighs and legs into such members chang\'d,\nAs never eye hath seen.  Of former shape\nAll trace was vanish\'d.  Two yet neither seem\'d\nThat image miscreate, and so pass\'d on\nWith tardy steps.  As underneath the scourge\nOf the fierce dog-star, that lays bare the fields,\nShifting from brake to brake, the lizard seems\nA flash of lightning, if he thwart the road,\nSo toward th\' entrails of the other two\nApproaching seem\'d, an adder all on fire,\nAs the dark pepper-grain, livid and swart.\nIn that part, whence our life is nourish\'d first,\nOne he transpierc\'d; then down before him fell\nStretch\'d out.  The pierced spirit look\'d on him\nBut spake not; yea stood motionless and yawn\'d,\nAs if by sleep or fev\'rous fit assail\'d.\nHe ey\'d the serpent, and the serpent him.\nOne from the wound, the other from the mouth\nBreath\'d a thick smoke, whose vap\'ry columns join\'d.\n     Lucan in mute attention now may hear,\nNor thy disastrous fate, Sabellus!  tell,\nNor shine, Nasidius!  Ovid now be mute.\nWhat if in warbling fiction he record\nCadmus and Arethusa, to a snake\nHim chang\'d, and ");strcat(expected_filecontent5, "it were detained in the snare you\nhave spread for me, so as to be somewhat prolix in my answer.\"\n\nv. 60. I it was.]  Pietro delle Vigne, a native of Capua, who,\nfrom a low condition, raised himself by his eloquence and legal\nknowledge to the office of Chancellor to the Emperor Frederick\nII. whose confidence in him was such, that his influence in the\nempire became unbounded.  The courtiers, envious of his exalted\nsituation, contrived, by means of forged letters, to make\nFrederick believe that he held a secret and traitorous\nintercourse with the Pope, who was then at enmity with the\nEmperor.  In consequence of this supposed crime he was cruelly\ncondemned by his too credulous sovereign to lose his eyes, and,\nbeing driven to despair by his unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n61.\n\nv. 28.  As, in the torrid Indian clime.]  Landino refers to\nAlbertus Magnus for the circumstance here alluded to.\n\nv. 53.  In Mongibello.]\n        More hot than Aetn\' or flaming Mongibell.\n               Spenser, F. Q. b. ii. c. ix. st. 29.\nSee Virg. Aen. 1. viii. 416. and Berni. Orl. Inn 1. i. c. xvi.\nst. 21.  It would be endless to refer to parallel passages in the\nGreek writers.\n\nv. 64.  This of the seven kings was one.]  Compare Aesch.  Seven\nChiefs, 425.  Euripides, Phoen. 1179 and Statius. Theb. l. x.\n821.\n\nv. 76.  Bulicame.]  A warm medicinal spring near Viterbo, the\nwaters of which, as Landino and Vellutelli affirm, passed by a\nplace of ill fame.  Venturi, with less probability, conjectures\nthat Dante would imply, that it was the scene of much licentious\nmerriment among those who frequented its baths.\n\nv. 91.  Under whose monarch.]\n        Credo pudicitiam Saturno rege moratam\n        In terris.\n               Juv. Satir. vi.\n\nv. 102.  His head.]  Daniel, ch. ii. 32, 33.\n\nv. 133.  Whither.] On the other side of Purgatory.\n\nCANTO XV\n\n v. 10.  Chiarentana.]  A part of the Alps where the Brenta\nrises, which river is much ");
    strcat(expected_filecontent5, "swoln as soon as the snow begins to\ndissolve on the mountains.\n\nv. 28.  Brunetto.]  \"Ser Brunetto, a Florentine, the secretary or\nchancellor of the city, and Dante\'s preceptor, hath left us a\nwork so little read, that both the subject of it and the language\nof it have been mistaken.  It is in the French spoken in the\nreign of St. Louis,under the title of Tresor, and contains a\nspecies of philosophical course of lectures divided into theory\nand practice, or, as he expresses it, \"un enchaussement des\nchoses divines et humaines,\" &c.  Sir R. Clayton\'s Translation of\nTenhove\'s Memoirs of the  Medici, vol. i.  ch.  ii.  p. 104.  The\nTresor has never been printed in the original language.  There is\na fine manuscript of it in the British Museum, with an\nilluminated portrait of Brunetto in his  study prefixed.  Mus.\nBrit. MSS. 17, E. 1. Tesor.  It is divided into four books, the\nfirst, on Cosmogony and Theology, the second, a translation of\nAristotle\'s Ethics; the third on Virtues and Vices; the fourth,\non Rhetoric.  For an interesting memoir relating to this work,\nsee Hist. de l\'Acad. des Inscriptions, tom. vii. 296.  His\nTesoretto, one of the earliest productions of Italian poetry, is\na curious work, not unlike the writings of Chaucer in style and\nnumbers, though Bembo remarks, that his pupil, however largely he\nhad stolen from it, could not have much enriched himself.  As it\nis perhaps but little known, I will here add a slight sketch of\nit.\n\nBrunetto describes himself as returning from an embassy to the\nKing of Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded b");strcat(expected_filecontent6, ",\nOr Africanus\': e\'en the sun\'s itself\nWere poor to this, that chariot of the sun\nErroneous, which in blazing ruin fell\nAt Tellus\' pray\'r devout, by the just doom\nMysterious of all-seeing Jove.  Three nymphs\n,k the right wheel, came circling in smooth dance;\nThe one so ruddy, that her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and keen edge,\nE\'en as I view\'d it with the flood between,\nAppall\'d me.  Next four others I beheld,\nOf humble seeming: and, behind them all,\nOne single old man, sleeping, as he came,\nWith a shrewd visage.  And these seven, each\nLike the first troop were habited, hut wore\nNo braid of lilies on their temples wreath\'d.\nRather with roses and each vermeil flower,\nA sight, but little distant, might have sworn,\nThat they were all on fire above their brow.\n     Whenas the car was o\'er against me, straight.\nWas heard a thund\'ring, at whose voice it seem\'d\nThe chosen multitude were stay\'d; for there,\nWith the first ensigns, made they solemn halt.\n\n\n\nCANTO XXX\n\nSoon as the polar light, which never knows\nSetting nor rising, nor the shadowy veil\nOf other cloud than sin, fair ornament\nOf the first heav\'n, to duty each one there\nSafely convoying, as that lower doth\nThe steersman to his port, stood firmly fix\'d;\nForthwith the saintly tribe, who in the van\nBetween the Gryphon and its radiance came,\nDid turn them to the car, as to their rest:\nAnd one, as if commission\'d from above,\nIn holy chant thrice shorted forth aloud:\n\"Come, spouse, from Libanus!\" and all the rest\nTook up the song--At the last audit so\nThe blest shall rise, from forth his cavern each\nUplifting lightly his new-vested flesh,\nAs, on the sacred litter, at the voice\nAuthoritative of that elder, sprang\nA hundred ministers and messengers\nOf life eternal.  \"Blessed thou!  who com\'st!\"\nAnd, \"O,\" they cried, \"from full hands scatter ye\nUnwith\'ring lilies;\" and, so saying, cast\nFlowers over head and round them on all sides.\n     I have beheld, ere now, at break of day,\nThe eastern clime all roseate, and the sky\nOppos\'d, one deep and beautiful serene,\nAnd the sun\'s face so shaded, and with mists\nAttemper\'d at lids rising, that the eye\nLong while endur\'d the sight: thus in a cloud\nOf flowers, that from those hands angelic rose,\nAnd down, within and outside of the car,\nFell showering, in white veil with olive wreath\'d,\nA virgin in my view appear\'d, beneath\nGreen mantle, rob\'d in hue of living flame:\nAnd o\'er my Spirit, that in former days\nWithin her presence had abode so long,\nNo shudd\'ring terror crept.  Mine eyes no more\nHad knowledge of her; yet there mov\'d from her\nA hidden virtue, at whose touch awak\'d,\nThe power of ancient love was strong within me.\n     No sooner on my vision streaming, smote\nThe heav\'nly influence, which years past, and e\'en\nIn childhood, thrill\'d me, than towards Virgil I\nTurn\'d me to leftward, panting, like a babe,\nThat flees for refuge to his mother\'s breast,\nIf aught have terrified or work\'d him woe:\nAnd would have cried:  \"There is no dram of blood,\nThat doth not quiver in me.  The old flame\nThrows out clear tokens of reviving fire:\"\nBut Virgil had bereav\'d us of himself,\nVirgil, my best-lov\'d father; Virgil, he\nTo whom I gave me up for safety: nor,\nAll, our prime mother lost, avail\'d to save\nMy undew\'d cheeks from blur of soiling tears.\n     \"Dante, weep not, that Virgil leaves thee: nay,\nWeep thou n");
    strcat(expected_filecontent6, "ot yet: behooves thee feel the edge\nOf other sword, and thou shalt weep for that.\"\n     As to the prow or stern, some admiral\nPaces the deck, inspiriting his crew,\nWhen \'mid the sail-yards all hands ply aloof;\nThus on the left side of the car I saw,\n(Turning me at the sound of mine own name,\nWhich here I am compell\'d to register)\nThe virgin station\'d, who before appeared\nVeil\'d in that festive shower angelical.\n     Towards me, across the stream, she bent her eyes;\nThough from her brow the veil descending, bound\nWith foliage of Minerva, suffer\'d not\nThat I beheld her clearly; then with act\nFull royal, still insulting o\'er her thrall,\nAdded, as one, who speaking keepeth back\nThe bitterest saying, to conclude the speech:\n\"Observe me well.  I am, in sooth, I am\nBeatrice.  What!  and hast thou deign\'d at last\nApproach the mountain?  knewest not, O man!\nThy happiness is whole?\"  Down fell mine eyes\nOn the clear fount, but there, myself espying,\nRecoil\'d, and sought the greensward: such a weight\nOf shame was on my forehead.  With a mien\nOf that stern majesty, which doth surround\nmother\'s presence to her awe-struck child,\nShe look\'d; a flavour of such bitterness\nWas mingled in her pity.  There her words\nBrake off, and suddenly the angels sang:\n\"In thee, O gracious Lord, my hope hath been:\"\nBut went no farther than, \"Thou Lord, hast set\nMy feet in ample room.\"  As snow, that lies\nAmidst the living rafters on the back\nOf Italy congeal\'d when drifted high\nAnd closely pil\'d by rough Sclavonian blasts,\nBreathe but the land whereon no shadow falls,\nAnd straightway melting it distils away,\nLike a fire-wasted taper: thus was I,\nWithout a sigh or tear, or ever these\nDid sing, that with the chiming of heav\'n\'s sphere,\nStill in their warbling chime: but when the strain\nOf dulcet symphony, express\'d for me\nTheir soft compassion, more than could the words\n\"Virgin, why so consum\'st him?\"  then the ice,\nCongeal\'d about my bosom, turn\'d itself\nTo spirit and water, and with anguish forth\nGush\'d through the lips and eyelids from the heart.\n     Upon the chariot\'s right edge still she stood,\nImmovable, and thus address\'d her words\nTo those bright semblances with pity touch\'d:\n\"Ye in th\' eternal day your vigils keep,\nSo that nor night nor slumber, with close stealth,\nConveys from you a single step in all\nThe goings on of life: thence with more heed\nI shape mine answer, for his ear intended,\nWho there stands weeping, that the sorrow now\nMay equal the transgression.  Not alone\nThrough operation of the mighty orbs,\nThat mark each seed to some predestin\'d aim,\nAs with aspect or fortunate or ill\nThe constellations meet, but through benign\nLargess of heav\'nly graces, which rain down\nFrom such a height, as mocks our vision, this man\nWas in the freshness of his being, such,\nSo gifted virtually, that in him\nAll better habits wond\'rously had thriv\'d.\nThe more of kindly strength is in the soil,\nSo much doth evil seed and lack of culture\nMar it the more, and make it run to wildness.\nThese looks sometime upheld him; for I show\'d\nMy youthful eyes, and led him by their light\nIn upright walking.  Soon as I had reach\'d\nThe threshold of my second age, and chang\'d\nMy mortal for immortal, then he left me,\nAnd gave himself to others.  When from flesh\nTo spirit I had risen, and increase\nOf beauty and of virtue circled me,\nI was less dear to him, and valued less.\nHis steps were turn\'d into deceitful ways,\nFollowing false images of good, that make\nNo promise perfect.  Nor avail\'d me aught\nTo sue fo");


            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "TAKE.TXT");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "DESCRIBE.BIN");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "DANGER");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "TEST.BIN");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "REQUIRE");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "HAT");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "NATION");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 5120, file0);
                test_error(size0 == 5120, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5120 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 5120);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 5120);
            
                size_t size1 = file_read(filecontent1, 1, 6685, file1);
                test_error(size1 == 6685, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6685 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 6685);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 6685);
            
                size_t size2 = file_read(filecontent2, 1, 7242, file2);
                test_error(size2 == 7242, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7242 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 7242);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 7242);
            
                size_t size3 = file_read(filecontent3, 1, 131, file3);
                test_error(size3 == 131, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 131 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 131);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 131);
            
                size_t size4 = file_read(filecontent4, 1, 5979, file4);
                test_error(size4 == 5979, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5979 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 5979);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 5979);
            
                size_t size5 = file_read(filecontent5, 1, 7696, file5);
                test_error(size5 == 7696, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7696 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 7696);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 7696);
            
                size_t size6 = file_read(filecontent6, 1, 7607, file6);
                test_error(size6 == 7607, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7607 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 7607);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 7607);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(7696, 1);
            char expected_filecontent[7697] = "";

            strcat(expected_filecontent, "it were detained in the snare you\nhave spread for me, so as to be somewhat prolix in my answer.\"\n\nv. 60. I it was.]  Pietro delle Vigne, a native of Capua, who,\nfrom a low condition, raised himself by his eloquence and legal\nknowledge to the office of Chancellor to the Emperor Frederick\nII. whose confidence in him was such, that his influence in the\nempire became unbounded.  The courtiers, envious of his exalted\nsituation, contrived, by means of forged letters, to make\nFrederick believe that he held a secret and traitorous\nintercourse with the Pope, who was then at enmity with the\nEmperor.  In consequence of this supposed crime he was cruelly\ncondemned by his too credulous sovereign to lose his eyes, and,\nbeing driven to despair by his unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n61.\n\nv. 28.  As, in the torrid Indian clime.]  Landino refers to\nAlbertus Magnus for the circumstance here alluded to.\n\nv. 53.  In Mongibello.]\n        More hot than Aetn\' or flaming Mongibell.\n               Spenser, F. Q. b. ii. c. ix. st. 29.\nSee Virg. Aen. 1. viii. 416. and Berni. Orl. Inn 1. i. c. xvi.\nst. 21.  It would be endless to refer to parallel passages in the\nGreek writers.\n\nv. 64.  This of the seven kings was one.]  Compare Aesch.  Seven\nChiefs, 425.  Euripides, Phoen. 1179 and Statius. Theb. l. x.\n821.\n\nv. 76.  Bulicame.]  A warm medicinal spring near Viterbo, the\nwaters of which, as Landino and Vellutelli affirm, passed by a\nplace of ill fame.  Venturi, with less probability, conjectures\nthat Dante would imply, that it was the scene of much licentious\nmerriment among those who frequented its baths.\n\nv. 91.  Under whose monarch.]\n        Credo pudicitiam Saturno rege moratam\n        In terris.\n               Juv. Satir. vi.\n\nv. 102.  His head.]  Daniel, ch. ii. 32, 33.\n\nv. 133.  Whither.] On the other side of Purgatory.\n\nCANTO XV\n\n v. 10.  Chiarentana.]  A part of the Alps where the Brenta\nrises, which river is much ");
    strcat(expected_filecontent, "swoln as soon as the snow begins to\ndissolve on the mountains.\n\nv. 28.  Brunetto.]  \"Ser Brunetto, a Florentine, the secretary or\nchancellor of the city, and Dante\'s preceptor, hath left us a\nwork so little read, that both the subject of it and the language\nof it have been mistaken.  It is in the French spoken in the\nreign of St. Louis,under the title of Tresor, and contains a\nspecies of philosophical course of lectures divided into theory\nand practice, or, as he expresses it, \"un enchaussement des\nchoses divines et humaines,\" &c.  Sir R. Clayton\'s Translation of\nTenhove\'s Memoirs of the  Medici, vol. i.  ch.  ii.  p. 104.  The\nTresor has never been printed in the original language.  There is\na fine manuscript of it in the British Museum, with an\nilluminated portrait of Brunetto in his  study prefixed.  Mus.\nBrit. MSS. 17, E. 1. Tesor.  It is divided into four books, the\nfirst, on Cosmogony and Theology, the second, a translation of\nAristotle\'s Ethics; the third on Virtues and Vices; the fourth,\non Rhetoric.  For an interesting memoir relating to this work,\nsee Hist. de l\'Acad. des Inscriptions, tom. vii. 296.  His\nTesoretto, one of the earliest productions of Italian poetry, is\na curious work, not unlike the writings of Chaucer in style and\nnumbers, though Bembo remarks, that his pupil, however largely he\nhad stolen from it, could not have much enriched himself.  As it\nis perhaps but little known, I will here add a slight sketch of\nit.\n\nBrunetto describes himself as returning from an embassy to the\nKing of Spain, on which he had been sent by the Guelph party from\nFlorence.  On the plain of Roncesvalles he meets a scholar on a\nbay mule, who tells him that the Guelfi are driven out of the\ncity with great loss.\n\nStruck with grief at these mournful tidings, and musing with his\nhead bent downwards, he loses his road, and wanders into a wood.\nHere Nature, whose figure is described with sublimity, appears,\nand  discloses to him the secrets of her operations.  After this\nhe wanders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded b");

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "HAT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 5259, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[5259] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[5259], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(7242, 1);
            char expected_filecontent[7243] = "";

            strcat(expected_filecontent, "roverted; and the latter, as Dante thinks,\nhad Scripture on his side.\n\nv. 51.  Pent.]  See Hell, Canto XXXIV. 105.\n\nv. 111.  Of Bindi and of Lapi.]  Common names of men at Florence\n\nv. 112.  The sheep.]  So Milton, Lycidas.\nThe hungry sheep look up and are not fed,\nBut, swoln with wind and the rank mist they draw,\nRot inwardly.\n\nv. 121.  The preacher.] Thus Cowper, Task, b.  ii.\n\n\'Tis pitiful\nTo court a grin, when you should woo a soul, &c.\n\nv. 131.  Saint Anthony.\nFattens with this his swine.]\nOn the sale of these blessings, the brothers of St. Anthony\nsupported themselves and their paramours.  From behind the swine\nof St. Anthony, our Poet levels a blow at the object of his\ninveterate enmity, Boniface VIII, from whom, \"in 1297, they\nobtained the dignity and privileges of an independent\ncongregation.\"  See Mosheim\'s Eccles. History in Dr. Maclaine\'s\nTranslation, v. ii.  cent. xi. p. 2. c. 2.  - 28.\n\nv. 140.  Daniel.]  \"Thousand thousands ministered unto him, and\nten thousand times ten thousand stood before him.\"  Dan. c. vii.\n10.\n\nCANTO XXX\n\nv. 1.  Six thousand miles.]  He compares the vanishing of the\nvision to the fading away of the stars at dawn, when it is\nnoon-day six thousand miles off, and the shadow, formed by the\nearth over the part of it inhabited by the Poet, is about to\ndisappear.\n\nv. 13.  Engirt.]  \" ppearing to be encompassed by these angelic\nbands, which are in reality encompassed by it.\"\n\nv. 18.  This turn.]  Questa vice.\nHence perhaps Milton, P. L. b. viii. 491.\nThis turn hath made amends.\n\nv. 39.  Forth.]  From the ninth sphere to the empyrean, which is\nmore light.\n\nv. 44.  Either mighty host.]  Of angels, that remained faithful,\nand of beatified souls, the latter in that form which they will\nhave at the last day.\nv. 61.  Light flowing.]  \"And he showed me a pure river of water\nof life, clear as crystal, proceeding out of the throne of God\nand of the Lamb.\" Rev. cxxii. I.\n\n--underneath a bright sea flow\'d\nOf jasper, or of liquid pearl.\nMilton, P. L. b. iii.  518.\n\nv. 80.  Shadowy of the truth.]\nSon di lor vero ombriferi prefazii.\nSo Mr. Coleridge, in his Religious Musings, v. 406.\nLife is a vision shadowy of truth.\n\nv. 88.  --the eves\nOf mine eyelids.]\nThus Shakespeare calls the eyelids \"penthouse lids.\" Macbeth, a,\n1. s, 3.\n\nv. 108.  As some cliff.]\nA lake\nThat to the fringed bank with myrtle crown\'d\nHer crystal mirror holds.\nMilton, P. L. b. iv.  263.\n\nv. 118.  My view with ease.]\nFar and wide his eye commands\nFor sight no obstacle found here, nor shade, But all sunshine.\nMilton, P. l. b. iii.  616.\n\nv. 135.  Of the great Harry.]  The Emperor Henry VII, who died in\n1313.\n\nv. 141.  He.]  Pope Clement V. See Canto XXVII.  53.\n\nv. 145.  Alagna\'s priest.]  Pope Boniface VIII.  Hell, Canto XIX.\n\n79.\n\nCANTO XXXI\n\nv. 6.  Bees.]  Compare Homer, Iliad, ii.  87. Virg.  Aen. I. 430,\nand Milton, P. L. b. 1.  768.\n\nv. 29.  Helice.]  Callisto, and her son Arcas, changed into the\nconstellations of the Greater Bear and Arctophylax, or Bootes.\nSee Ovid, Met.  l. ii. fab. v. vi.\n\nv. 93.  Bernard.]  St. Bernard, the venerable abbot of Clairvaux,\nand the great promoter of the second crusade, who died A.D. 1153,\nin his sixty-third year.  His sermons are called by Henault,\n\"chefs~d\'oeuvres de sentiment et de force.\"  Abrege Chron. de\nl\'Hist.  de Fr. 1145. They have even been preferred to al1 the\nproductions of the ancients, and the author has been termed the\nlast of the fathers of the church. It is uncertain whether they\nwere not delivered originally in the French tongue.\n\nThat the part he acts in the present Poem should be assigned to\nhim. appears somewhat remarkable, when we consider that he\nseverely censured the new festival established in honour of the\nImmaculate Conception of the virgin, and opposed the doctrine\nitself with the greatest vigour, as it supposed her being\nhonoured with a privilegewhich belonged to Christ Alone Dr.\nMaclaine\'s Mosheim, v. iii. cent. xii. p. ii. c. 3 - 19.\n\nv. 95.  Our Veronica ] The holy handkerchief, then preserved at\nRome, on which the countenance of our Saviour was supposed to\nhave be");
    strcat(expected_filecontent, "en imprest.\n\nv. 101.  Him.]  St. Bernard.\n\nv. 108.  The queen.]  The Virgin Mary.\n\nv. 119.  Oriflamb.]  Menage on this word quotes the Roman des\nRoyau\n-Iignages of Guillaume Ghyart.\nOriflamme est une banniere\nDe cendal roujoyant et simple\nSans portraiture d\'autre affaire,\n\nCANTO XXXII\n\nv. 3.  She.]  Eve.\n\nv. 8.  Ancestress.]  Ruth, the ancestress of David.\n\nv. 60.  In holy scripture.]  Gen. c. xxv.  22.\nv. 123.  Lucia.]  See Hell, Canto II.  97.\n\nCANTO XXXIII\n\nv. 63.  The Sybil\'s sentence.]  Virg.  Aen.  iii. 445.\n\nv. 89.  One moment.]  \"A moment seems to me more tedious, than\nfive-and-twenty ages would have appeared to the Argonauts, when\nthey had resolved on their expedition.\n\nv. 92.  Argo\'s shadow]\nQuae simul ac rostro ventosnm proscidit aequor,\nTortaque remigio spumis incanduit unda,\nEmersere feri candenti e gurgite vultus\nAequoreae monstrum Nereides admirantes.\nCatullus, De Nupt.  Pel.  et Thet.  15.\n\nv. 109.  Three orbs of triple hue, clipt in one bound.]  The\nTrinity.\n\nv. 118.  That circling.]  The second of the circles, \"Light of\nLight,\" in which he dimly beheld the mystery of the incarnation.\n\n\n\n\n\nEnd Paradise.\n\n\n\n\n\nPREFACE\n\nIn the years 1805 and 1806, I published the first part of the\nfollowing translation, with the text of the original.  Since that\nperiod, two impressions of the whole of the Divina Commedia, in\nItalian, have made their appearance in this country.  It is not\nnecessary that I should add a third: and I am induced to hope\nthat the Poem, even in the present version of it, may not be\nwithout interest for the mere English reader.\n\nThe translation of the second and third parts, \"The Purgatory\"\nand \"The Paradise,\" was begun long before the first, and as early\nas the year 1797; but, owing to many interruptions, not concluded\ntill the summer before last.  On a retrospect of the time and\nexertions that have been thus employed, I do not regard those\nhours as the least happy of my  life, during which (to use the\neloquent language of Mr. Coleridge) \"my individual recollections\nhave been suspended, and lulled to sleep amid the music of nobler\nthoughts;\"  nor that study as misapplied, which has familiarized\nme with one of the sublimest efforts of the human invention.\n\nTo those, who shall be at the trouble of examining into the\ndegree of accuracy with which the task has been executed, I may\nbe allowed to suggest, that their judgment should not be formed\non a comparison with any single text of my Author; since, in more\ninstances than I have noticed, I have had to make my choice out\nof a variety of readings and interpretations, presented by\ndifferent editions and commentators.\n\nIn one or two of those editions is to be found the title of \"The\nVision,\" which I have adopted, as more conformable to the genius\nof our language than that of \"The Divine Comedy.\"  Dante himself,\nI believe, termed it simply \"The Comedy;\" in the first place,\nbecause the style was of the middle kind:  and in the next,\nbecause the story (if story it may be called) ends happily.\n\nInstead of a Life of my Author, I have subjoined, in\nchronological order, a view not only of the principal events\nwhich befell him, but");

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "DANGER");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -2058, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[5184] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[5184], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(6685, 1);
            char expected_filecontent[6686] = "";

            strcat(expected_filecontent, "But who is he observes them?  None; not he,\nWho goes before, the shepherd of the flock,\nWho chews the cud but doth not cleave the hoof.\nTherefore the multitude, who see their guide\nStrike at the very good they covet most,\nFeed there and look no further.  Thus the cause\nIs not corrupted nature in yourselves,\nBut ill-conducting, that hath turn\'d the world\nTo evil.  Rome, that turn\'d it unto good,\nWas wont to boast two suns, whose several beams\nCast light on either way, the world\'s and God\'s.\nOne since hath quench\'d the other; and the sword\nIs grafted on the crook; and so conjoin\'d\nEach must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and the Po\nTheir waters roll, was once the residence\nOf courtesy and velour, ere the day,\nThat frown\'d on Frederick; now secure may pass\nThose limits, whosoe\'er hath left, for shame,\nTo talk with good men, or come near their haunts.\nThree aged ones are still found there, in whom\nThe old time chides the new: these deem it long\nEre God restore them to a better world:\nThe good Gherardo, of Palazzo he\nConrad, and Guido of Castello, nam\'d\nIn Gallic phrase more fitly the plain Lombard.\nOn this at last conclude.  The church of Rome,\nMixing two governments that ill assort,\nHath miss\'d her footing, fall\'n into the mire,\nAnd there herself and burden much defil\'d.\"\n     \"O Marco!\" I replied, shine arguments\nConvince me: and the cause I now discern\nWhy of the heritage no portion came\nTo Levi\'s offspring.  But resolve me this\nWho that Gherardo is, that as thou sayst\nIs left a sample of the perish\'d race,\nAnd for rebuke to this untoward age?\"\n     \"Either thy words,\" said he, \"deceive; or else\nAre meant to try me; that thou, speaking Tuscan,\nAppear\'st not to have heard of good Gherado;\nThe sole addition that, by which I know him;\nUnless I borrow\'d from his daughter Gaia\nAnother name to grace him.  God be with you.\nI bear you company no more.  Behold\nThe dawn with white ray glimm\'ring through the mist.\nI must away--the angel comes--ere he\nAppear.\"  He said, and would not hear me more.\n\n\n\nCANTO XVII\n\nCall to remembrance, reader, if thou e\'er\nHast, on a mountain top, been ta\'en by cloud,\nThrough which thou saw\'st no better, than the mole\nDoth through opacous membrane; then, whene\'er\nThe wat\'ry vapours dense began to melt\nInto thin air, how faintly the sun\'s sphere\nSeem\'d wading through them; so thy nimble thought\nMay image, how at first I re-beheld\nThe sun, that bedward now his couch o\'erhung.\n     Thus with my leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, ");
    strcat(expected_filecontent, "outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing it loves,\nAll fro");

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "DESCRIBE.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 2295, SEEK_SET);
            file_seek(file, 580, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2875] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2875], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WHILE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WHILE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "MONEY");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (MONEY) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SPEED");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SPEED) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "MASS");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (MASS) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "PRODUCT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (PRODUCT) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "GRAND");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (GRAND) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "USESTAND");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (USESTAND) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "MOON.TXT");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie MOON.TXT, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "MOON.TXT");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "TAKE.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[14] = { "TAKE.TXT", "DESCRIBE.BIN", "DANGER", "TEST.BIN", "REQUIRE", "HAT", "NATION", "WHILE", "MONEY", "SPEED", "MASS", "PRODUCT", "GRAND", "USESTAND" };
            int found_names[14] = { 0 };

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 14; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 14; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "TAKE.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "DESCRIBE.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "DANGER");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "TEST.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "REQUIRE");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "HAT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "NATION");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 53: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST53(void)
{
    // informacje o teście
    test_start(53, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("neck_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "year");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
            UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
            UTEST29, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST30, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST31, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST32, // Sprawdzanie poprawności działania funkcji file_open
            UTEST33, // Sprawdzanie poprawności działania funkcji file_open
            UTEST34, // Sprawdzanie poprawności działania funkcji file_open
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_open
            UTEST40, // Sprawdzanie poprawności działania funkcji file_read
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji file_close
            UTEST44, // Sprawdzanie poprawności działania funkcji file_read
            UTEST45, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST46, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST47, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST48, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST53, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(53); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}
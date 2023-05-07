#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <sys/types.h>
#include "shuffle.h"
#include <sys/mman.h>
#include <stdlib.h>

static char* func_got[] = {"17a30", "17a38", "17a40", "17a48", "17a50", "17a58", "17a60", "17a68", "17a70", "17a78", "17a80", "17a88", "17a90", "17a98", "17aa0", "17aa8", "17ab0", "17ab8", "17ac0", "17ac8", "17ad0", "17ad8", "17ae0", "17ae8", "17af0", "17af8", "17b00", "17b08", "17b10", "17b18", "17b20", "17b28", "17b30", "17b38", "17b40", "17b48", "17b50", "17b58", "17b60", "17b68", "17b70", "17b78", "17b80", "17b88", "17b90", "17b98", "17ba0", "17ba8", "17bb0", "17bb8", "17bc0", "17bc8", "17bd0", "17bd8", "17be0", "17be8", "17bf0", "17bf8", "17c00", "17c08", "17c10", "17c18", "17c20", "17c28", "17c30", "17c38", "17c40", "17c48", "17c50", "17c58", "17c60", "17c68", "17c70", "17c78", "17c80", "17c88", "17c90", "17c98", "17ca0", "17ca8", "17cb0", "17cb8", "17cc0", "17cc8", "17cd0", "17cd8", "17ce0", "17ce8", "17cf0", "17cf8", "17d00", "17d08", "17d10", "17d18", "17d20", "17d28", "17d30", "17d38", "17d40", "17d48", "17d50", "17d58", "17d60", "17d68", "17d70", "17d78", "17d80", "17d88", "17d90", "17d98", "17da0", "17da8", "17db0", "17db8", "17dc0", "17dc8", "17dd0", "17dd8", "17de0", "17de8", "17df0", "17df8", "17e00", "17e08", "17e10", "17e18", "17e20", "17e28", "17e30", "17e38", "17e40", "17e48", "17e50", "17e58", "17e60", "17e68", "17e70", "17e78", "17e80", "17e88", "17e90", "17e98", "17ea0", "17ea8", "17eb0", "17eb8", "17ec0", "17ec8", "17ed0", "17ed8", "17ee0", "17ee8", "17ef0", "17ef8", "17f00", "17f08", "17f10", "17f18", "17f20", "17f28", "17f30", "17f38", "17f40", "17f48", "17f50", "17f58", "17f60", "17f68", "17f70", "17f78", "17f80", "17f88", "17f90", "17f98", "17fa0", "17fa8", "17fb0", "17fb8", "17fc8", "17fd0", "17fd8", "17fe0", "17fe8", "17ff0", "17ff8", "18000", "18008", "18010", "18018", "18020", "18028", "18030", "18038", "18040", "18048", "18050", "18058", "18060", "18068", "18070", "18078", "18080", "18088", "18090", "18098", "180a0", "180a8", "180b0", "180b8", "180c0", "180c8", "180d0", "180d8", "180e0", "180e8", "180f0", "180f8", "18100", "18108", "18110", "18118", "18120", "18128", "18130", "18138", "18140", "18148", "18150", "18158", "18160", "18168", "18170", "18178", "18180", "18188", "18190", "18198", "181a0", "181a8", "181b0", "181b8", "181c0", "181c8", "181d0", "181d8", "181e0", "181e8", "181f0", "181f8", "18200", "18208", "18210", "18218", "18220", "18228", "18230", "18238", "18240", "18248", "18250", "18258", "18260", "18268", "18270", "18278", "18280", "18288", "18290", "18298", "182a0", "182a8", "182b0", "182b8", "182c0", "182c8", "182d0", "182d8", "182e0", "182e8", "182f0", "182f8", "18300", "18308", "18310", "18318", "18320", "18328", "18330", "18338", "18340", "18348", "18350", "18358", "18360", "18368", "18370", "18378", "18380", "18388", "18390", "18398", "183a0", "183a8", "183b0", "183b8", "183c0", "183c8", "183d0", "183d8", "183e0", "183e8", "183f0", "183f8", "18400", "18408", "18410", "18418", "18428", "18430", "18438", "18440", "18448", "18450", "18458", "18460", "18468", "18470", "18478", "18480", "18488", "18490", "18498", "184a0", "184a8", "184b0", "184b8", "184c0", "184c8", "184d0", "184d8", "184e0", "184e8", "184f0", "184f8", "18500", "18508", "18510", "18518", "18520", "18528", "18530", "18538", "18540", "18548", "18550", "18558", "18568", "18570", "18578", "18580", "18588", "18590", "18598", "185a0", "185a8", "185b0", "185b8", "185c0", "185c8", "185d0", "185d8", "185e0", "185e8", "185f0", "185f8", "18600", "18608", "18610", "18618", "18620", "18628", "18630", "18638", "18640", "18648", "18650", "18658", "18660", "18668", "18670", "18678", "18680", "18688", "18690", "18698", "186a0", "186a8", "186b0", "186b8", "186c0", "186c8", "186d0", "186d8", "186e0", "186e8", "186f0", "186f8", "18700", "18708", "18710", "18718", "18720", "18728", "18730", "18738", "18740", "18748", "18750", "18758", "18760", "18768", "18770", "18778", "18780", "18788", "18790", "18798", "187a0", "187a8", "187b0", "187b8", "187c0", "187c8", "187d0", "187d8", "187e0", "187e8", "187f0", "187f8", "18800", "18808", "18810", "18818", "18820", "18828", "18830", "18838", "18840", "18848", "18850", "18858", "18860", "18868", "18870", "18878", "18880", "18888", "18890", "18898", "188a0", "188a8", "188b0", "188b8", "188c0", "188c8", "188d0", "188d8", "188e0", "188e8", "188f0", "188f8", "18900", "18908", "18910", "18918", "18920", "18928", "18930", "18938", "18940", "18948", "18950", "18958", "18960", "18968", "18970", "18978", "18980", "18988", "18990", "18998", "189a0", "189a8", "189b0", "189b8", "189c0", "189c8", "189d0", "189d8", "189e0", "189e8", "189f0", "189f8", "18a00", "18a08", "18a10", "18a18", "18a20", "18a28", "18a30", "18a38", "18a40", "18a48", "18a50", "18a58", "18a60", "18a68", "18a70", "18a78", "18a80", "18a88", "18a90", "18a98", "18aa0", "18aa8", "18ab0", "18ab8", "18ac0", "18ac8", "18ad0", "18ad8", "18ae0", "18ae8", "18af0", "18af8", "18b00", "18b08", "18b10", "18b18", "18b20", "18b28", "18b30", "18b38", "18b40", "18b48", "18b50", "18b58", "18b60", "18b68", "18b70", "18b78", "18b80", "18b88", "18b90", "18b98", "18ba0", "18ba8", "18bb0", "18bb8", "18bc0", "18bc8", "18bd0", "18bd8", "18be0", "18be8", "18bf0", "18bf8", "18c00", "18c08", "18c10", "18c18", "18c20", "18c28", "18c30", "18c38", "18c40", "18c48", "18c50", "18c58", "18c60", "18c68", "18c70", "18c78", "18c80", "18c88", "18c90", "18c98", "18ca0", "18ca8", "18cb0", "18cb8", "18cc0", "18cc8", "18cd0", "18cd8", "18ce0", "18ce8", "18cf0", "18cf8", "18d00", "18d08", "18d10", "18d18", "18d20", "18d28", "18d30", "18d38", "18d40", "18d48", "18d50", "18d58", "18d60", "18d68", "18d70", "18d78", "18d80", "18d88", "18d90", "18d98", "18da0", "18da8", "18db0", "18db8", "18dc0", "18dc8", "18dd0", "18dd8", "18de0", "18de8", "18df0", "18df8", "18e00", "18e08", "18e10", "18e18", "18e20", "18e28", "18e30", "18e38", "18e40", "18e48", "18e50", "18e58", "18e60", "18e68", "18e70", "18e78", "18e80", "18e88", "18e90", "18e98", "18ea0", "18ea8", "18eb0", "18eb8", "18ec0", "18ec8", "18ed0", "18ed8", "18ee0", "18ee8", "18ef0", "18ef8", "18f00", "18f08", "18f10", "18f18", "18f20", "18f28", "18f30", "18f38", "18f40", "18f48", "18f50", "18f58", "18f60", "18f68", "18f70", "18f78", "18f80", "18f88", "18f90", "18f98", "18fa0", "18fa8", "18fb0", "18fb8", "18fc0", "18fc8"};
static int  func_num[] = {606, 641, 175, 1272, 1276, 286, 249, 502, 284, 208, 280, 541, 206, 786, 1237, 1008, 788, 704, 741, 1045, 1235, 738, 706, 1239, 1152, 849, 775, 1004, 1193, 1156, 771, 1191, 200, 380, 1309, 1136, 847, 877, 808, 57, 1132, 1134, 841, 1348, 1346, 10, 1291, 884, 1293, 1385, 300, 473, 1250, 304, 949, 1254, 1217, 1446, 1409, 1256, 947, 1219, 1407, 1215, 1448, 945, 908, 906, 943, 96, 986, 1213, 180, 1211, 141, 591, 558, 108, 519, 556, 432, 1186, 597, 147, 1149, 430, 92, 1147, 182, 145, 631, 1188, 149, 186, 1284, 684, 238, 680, 511, 273, 234, 102, 271, 550, 513, 799, 711, 1019, 1421, 28, 26, 782, 1184, 1015, 1011, 1013, 391, 317, 315, 230, 866, 1332, 834, 20, 22, 1082, 871, 873, 1260, 1379, 1338, 1221, 429, 466, 1084, 1373, 427, 313, 311, 1377, 1225, 921, 1418, 1451, 1049, 1414, 953, 1160, 990, 157, 568, 1457, 1121, 155, 566, 67, 153, 114, 529, 527, 112, 562, 460, 61, 421, 1175, 639, 676, 159, 620, 637, 674, 635, 624, 1313, 1179, 261, 226, 224, 1258, 758, 720, 1026, 523, 1067, 756, 265, 754, 719, 1063, 761, 717, 269, 797, 4, 328, 326, 222, 829, 898, 1114, 369, 220, 827, 367, 1321, 825, 851, 814, 2, 1360, 823, 33, 1093, 1232, 862, 864, 1362, 457, 1230, 1097, 860, 1095, 492, 418, 416, 451, 1056, 1423, 1368, 320, 1234, 929, 498, 1099, 927, 925, 1464, 1468, 129, 960, 1110, 164, 577, 76, 538, 575, 160, 573, 70, 412, 1306, 698, 651, 1125, 628, 663, 1300, 1129, 661, 1304, 299, 254, 1266, 1264, 534, 571, 769, 776, 1074, 293, 532, 1406, 291, 1268, 47, 1072, 728, 1035, 1229, 726, 6, 1166, 1400, 374, 339, 337, 801, 1144, 1107, 1356, 857, 1354, 1317, 45, 1142, 805, 1105, 855, 43, 853, 816, 894, 896, 1103, 892, 1391, 1101, 448, 446, 409, 1399, 407, 1434, 1069, 333, 1246, 1395, 331, 989, 901, 1471, 933, 903, 1242, 1203, 489, 1436, 1473, 974, 970, 1475, 583, 133, 548, 581, 546, 84, 1140, 509, 601, 139, 687, 440, 403, 1116, 659, 1331, 642, 607, 657, 176, 1273, 692, 285, 248, 1040, 283, 244, 501, 242, 739, 785, 505, 701, 287, 787, 1279, 58, 1007, 772, 1001, 1151, 50, 1192, 240, 203, 307, 15, 201, 876, 1194, 1345, 1137, 56, 1308, 1133, 1347, 807, 842, 885, 1198, 1388, 1380, 439, 437, 470, 433, 1445, 340, 1255, 1218, 1386, 956, 946, 993, 1212, 944, 995, 97, 1251, 1253, 983, 95, 985, 144, 981, 142, 109, 590, 557, 518, 598, 185, 1148, 630, 183, 648, 632, 189, 634, 646, 1189, 1090, 609, 683, 685, 1283, 1051, 235, 512, 272, 1285, 101, 551, 710, 748, 278, 239, 712, 709, 1287, 25, 744, 707, 1016, 1185, 1012, 783, 396, 318, 355, 27, 1333, 23, 1337, 822, 1370, 1335, 872, 1374, 1085, 870, 469, 467, 351, 919, 1413, 920, 1450, 969, 1415, 999, 952, 954, 117, 567, 1120, 154, 950, 115, 1454, 1419, 152, 528, 563, 113, 111, 561, 62, 424, 461, 1351, 621, 677, 158, 1316, 1353, 569, 660, 199, 1312, 636, 1176, 1310, 262, 520, 260, 757, 1027, 1259, 1021, 718, 753, 716, 751, 1023, 760, 1064, 794, 796, 329, 5, 360, 38, 897, 368, 221, 1115, 828, 366, 1, 1363, 3, 811, 1326, 850, 1361, 1324, 1365, 30, 865, 497, 1231, 321, 1424, 499, 1055, 1422, 930, 1059, 1426, 924, 961, 963, 1469, 77, 1098, 1461, 1111, 163, 126, 539, 576, 1463, 537, 124, 574, 411, 73, 572, 75, 450, 415, 1126, 71, 1467, 169, 413, 697, 1342, 167, 650, 613, 1169, 699, 629, 1128, 662, 1263, 290, 218, 533, 120, 777, 259, 531, 766, 729, 779, 257, 1226, 1032, 764, 1071, 1034, 762, 48, 1401, 1073, 1163, 7, 1167, 1269, 1165, 338, 334, 1318, 1355, 212, 377, 800, 856, 375, 1390, 817, 854, 852, 1143, 1359, 1106, 1398, 44, 1280, 893, 1396, 1282, 1394, 891, 482, 480, 408, 332, 988, 900, 330, 1206, 902, 1247, 1068, 936, 1208, 1433, 1243, 1204, 1437, 932, 1182, 87, 977, 1202, 179, 971, 134, 584, 1180, 1200, 132, 545, 508, 543, 443, 406, 1117, 81, 173, 1476, 171, 688};
int init()
{
    int func_len = sizeof(func_num) / sizeof(int);
    fprintf(stderr, "length: %d\n", func_len);
    void *handle = dlopen("libpoem.so", RTLD_LAZY);
    int (*fptr2)();

    FILE *fp;
    fp = fopen("/proc/self/maps", "r");
    char line[2000];
    long int base = 0, block_head = 0, block_end = 0;
    if(fp != NULL)
    {
        while(fgets(line, 2000,fp))
        {
            if(strstr(line,"chals") != NULL)
            {
                fprintf(stderr, "%s\n", line);
                if(strstr(line, "r-xp") == NULL)
                {
                    strtok(line, "-");
                    sscanf(line, "%lx", &base);
                }
                else
                {
                    strtok(line, " ");
                    sscanf(line, "%lx-%lx", &block_head, &block_end);
                }
            }
            if(base != 0 && block_end != 0 && block_head != 0)break;
            
        }
        
    }
    fprintf(stderr, "%lx %lx %lx\n", base, block_head, block_end);
    fclose(fp);

    char old_fun_name[20];
    char new_fun_name[20];
    //int size = sizeof(func) / sizeof(int);

    fprintf(stderr, "================%d\n", ndat[1310]);
    //sprintf(new_fun_name, "code_%d", ndat[func_num[0]]);
    int idx = 0;
    for(int i =0; i < sizeof(ndat) / sizeof(int); i++)
    {
        if(ndat[i] == func_num[0])
        {
            idx = i;
            break;
        }
    }
    sprintf(new_fun_name, "code_%d", idx);
    fptr2 = dlsym(handle, new_fun_name);

    long int func_got_actAddr = base + strtol(func_got[0], NULL, 16);
    void* f_g_aA = (void*) func_got_actAddr;
    
    long int got_base = func_got_actAddr / 0x1000 * 0x1000;
    void* got_ptr = (void*) got_base;
    //sprintf(got_ptr, "0x%lx", got_base);
    
    fprintf(stderr, "%p %lx\n", f_g_aA, got_ptr);
    mprotect(got_ptr, 2 * 0x1000, PROT_READ | PROT_WRITE);
    memcpy(f_g_aA, &fptr2, 8);
    
    for(int i = 1; i < func_len; i++)
    {
        for(int j =0; j < sizeof(ndat) / sizeof(int); j++)
        {
            
            if(ndat[j] == func_num[i])
            {
                idx = j;
                if(func_num[j] == 498)fprintf(stderr, "F%dF\n", idx);
                break;
            }
        }
        //if(func_num[i] == 498)fprintf(stderr, "%d", idx);
        //sprintf(new_fun_name, "code_%d", ndat[func_num[i]]);
        sprintf(new_fun_name, "code_%d", idx);
        fptr2 = dlsym(handle, new_fun_name);
        func_got_actAddr = base + strtol(func_got[i], NULL, 16);
        f_g_aA = (void*) func_got_actAddr;
        memcpy(f_g_aA, &fptr2, 8);
    }
    return 0;
}
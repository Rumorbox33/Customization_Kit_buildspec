/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   nand_dev_tbl.c
 *
 * Project:
 * --------
 *   FlashTool Download Agent
 *
 * Description:
 * ------------
 *   NAND flash device table
 *
 * Author:
 * -------
 *   Amos Hsu
 *
 *******************************************************************************/
#include "nand_dev_tbl.h"
#include "nand_drv_COMMON_v5.h"
#include "nand_drv_SAMSUNG.h"
#include "nand_drv_TOSHIBA.h"
#include "nand_drv_HYNIX.h"
#include "nand_drv_KINGSTON.h"

#if 0
NAND_MLC_FEATURE g_MICRON_MLC_FEATURE =
{1,1,2,2,2,
0xEF,0xEE,7,0,0x89,0xFF,0x01,0x05,0x14, RTYPE_MICRON,
{{{0,6},{1,7},{2,0xffff},{3,0xffff},{4,10},{5,11},
{8,14},{9,15},{12,18},{13,19},{16,22},{17,23},
{20,26},{21,27},{24,30},{25,31},{28,34},{29,35},
{32,38},{33,39},{36,42},{37,43},{40,46},{41,47},
{44,50},{45,51},{48,54},{49,55},{52,58},{53,59},
{56,62},{57,63},{60,66},{61,67},{64,70},{65,71},
{68,74},{69,75},{72,78},{73,79},{76,82},{77,83},
{80,86},{81,87},{84,90},{85,91},{88,94},{89,95},
{92,98},{93,99},{96,102},{97,103},{100,106},{101,107},
{104,110},{105,111},{108,114},{109,115},{112,118},{113,119},
{116,122},{117,123},{120,126},{121,127},{124,130},{125,131},
{128,134},{129,135},{132,138},{133,139},{136,142},{137,143},
{140,146},{141,147},{144,150},{145,151},{148,154},{149,155},
{152,158},{153,159},{156,162},{157,163},{160,166},{161,167},
{164,170},{165,171},{168,174},{169,175},{172,178},{173,179},
{176,182},{177,183},{180,186},{181,187},{184,190},{185,191},
{188,194},{189,195},{192,198},{193,199},{196,202},{197,203},
{200,206},{201,207},{204,210},{205,211},{208,214},{209,215},
{212,218},{213,219},{216,222},{217,223},{220,226},{221,227},
{224,230},{225,231},{228,234},{229,235},{232,238},{233,239},
{236,242},{237,243},{240,246},{241,247},{244,250},{245,251},
{248,0xffff},{249,0xffff},{252,0xffff},{253,0xffff},{254,0xffff},{255,0xffff}}},
{1,2,3,4,5,6,7}};

NAND_MLC_FEATURE g_MICRON_MLC_16NM_FEATURE =
{1,1,2,2,2,
0xEF,0xEE,7,0,0x89,0xFF,0x01,0x05,0x14, RTYPE_MICRON,
{{{0,0xffff},{1,6},{2,0xffff},{3,0xffff},{4,0xffff},{5,9},
{7,12},{8,13},{10,16},{11,17},{14,20},{15,21},
{18,24},{19,25},{22,28},{23,29},{26,32},{27,33},
{30,36},{31,37},{34,40},{35,41},{38,44},{39,45},
{42,48},{43,49},{46,52},{47,53},{50,56},{51,57},
{54,60},{55,61},{58,64},{59,65},{62,68},{63,69},
{66,72},{67,73},{70,76},{71,77},{74,80},{75,81},
{78,84},{79,85},{82,88},{83,89},{86,92},{87,93},
{90,96},{91,97},{94,100},{95,101},{98,104},{99,105},
{102,108},{103,109},{106,112},{107,113},{110,116},{111,117},
{114,120},{115,121},{118,124},{119,125},{122,128},{123,129},
{126,132},{127,133},{130,136},{131,137},{134,140},{135,141},
{138,144},{139,145},{142,148},{143,149},{146,152},{147,153},
{150,156},{151,157},{154,160},{155,161},{158,164},{159,165},
{162,168},{163,169},{166,172},{167,173},{170,176},{171,177},
{174,180},{175,181},{178,184},{179,185},{182,188},{183,189},
{186,192},{187,193},{190,196},{191,197},{194,200},{195,201},
{198,204},{199,205},{202,208},{203,209},{206,212},{207,213},
{210,216},{211,217},{214,220},{215,221},{218,224},{219,225},
{222,228},{223,229},{226,232},{227,233},{230,236},{231,237},
{234,240},{235,241},{238,244},{239,245},{242,248},{243,249},
{246,252},{247,253},{250,256},{251,257},{254,260},{255,261},
{258,264},{259,265},{262,268},{263,269},{266,272},{267,273},
{270,276},{271,277},{274,280},{275,281},{278,284},{279,285},
{282,288},{283,289},{286,292},{287,293},{290,296},{291,297},
{294,300},{295,301},{298,304},{299,305},{302,308},{303,309},
{306,312},{307,313},{310,316},{311,317},{314,320},{315,321},
{318,324},{319,325},{322,328},{323,329},{326,332},{327,333},
{330,336},{331,337},{334,340},{335,341},{338,344},{339,345},
{342,348},{343,349},{346,352},{347,353},{350,356},{351,357},
{354,360},{355,361},{358,364},{359,365},{362,368},{363,369},
{366,370},{367,371},{370,376},{371,377},{374,380},{375,381},
{378,384},{379,385},{382,388},{383,389},{386,392},{387,393},
{390,396},{391,397},{394,400},{395,401},{398,404},{399,405},
{402,408},{403,409},{406,412},{407,413},{410,416},{411,417},
{414,420},{415,421},{418,424},{419,425},{422,428},{423,429},
{426,432},{427,433},{430,436},{431,437},{434,440},{435,441},
{438,444},{439,445},{442,448},{443,449},{446,452},{447,453},
{450,456},{451,457},{454,460},{455,461},{458,464},{459,465},
{462,468},{463,469},{466,472},{467,473},{470,476},{471,477},
{474,480},{475,481},{478,484},{479,485},{482,488},{483,489},
{486,492},{487,493},{490,496},{491,497},{494,500},{495,501},
{498,504},{499,505},{502,0xffff},{503,508}}},
//{506,0xffff},{507,511},{510,0xffff},{509,0xffff},//skip last 4 pages for 256 table size
{1,2,3,4,5,6,7}};

NAND_MLC_FEATURE g_SANDISK_19NM_MLC_FEATURE =
{1,1,2,2,2,0xEF,0xEE,16,0,0x11,0xFF,0x80,0x01,0x00, RTYPE_SANDISK_19NM,\
{{{0 ,2},{1 ,4},{3 ,6},{5 ,8},{7 ,10},{9 ,12},{11 ,14},{13 ,16},\
{15 ,18},{17 ,20},{19 ,22},{21 ,24},{23 ,26},{25 ,28},{27 ,30},{29 ,32},\
{31 ,34},{33 ,36},{35 ,38},{37 ,40},{39 ,42},{41 ,44},{43 ,46},{45 ,48},\
{47 ,50},{49 ,52},{51 ,54},{53 ,56},{55 ,58},{57 ,60},{59 ,62},{61 ,64},\
{63 ,66},{65 ,68},{67 ,70},{69 ,72},{71 ,74},{73 ,76},{75 ,78},{77 ,80},\
{79 ,82},{81 ,84},{83 ,86},{85 ,88},{87 ,90},{89 ,92},{91 ,94},{93 ,96},\
{95 ,98},{97 ,100},{99 ,102},{101 ,104},{103 ,106},{105 ,108},{107 ,110},{109 ,112},\
{111 ,114},{113 ,116},{115 ,118},{117 ,120},{119 ,122},{121 ,124},{123 ,126},{125 ,128},\
{127 ,130},{129 ,132},{131 ,134},{133 ,136},{135 ,138},{137 ,140},{139 ,142},{141 ,144},\
{143 ,146},{145 ,148},{147 ,150},{149 ,152},{151 ,154},{153 ,156},{155 ,158},{157 ,160},\
{159 ,162},{161 ,164},{163 ,166},{165 ,168},{167 ,170},{169 ,172},{171 ,174},{173 ,176},\
{175 ,178},{177 ,180},{179 ,182},{181 ,184},{183 ,186},{185 ,188},{187 ,190},{189 ,192},\
{191 ,194},{193 ,196},{195 ,198},{197 ,200},{199 ,202},{201 ,204},{203 ,206},{205 ,208},\
{207 ,210},{209 ,212},{211 ,214},{213 ,216},{215 ,218},{217 ,220},{219 ,222},{221 ,224},\
{223 ,226},{225 ,228},{227 ,230},{229 ,232},{231 ,234},{233 ,236},{235 ,238},{237 ,240},\
{239 ,242},{241 ,244},{243 ,246},{245 ,248},{247 ,250},{249 ,252},{251 ,254},{253 ,255}}},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}};


NAND_MLC_FEATURE g_TOSHIBA_MLC_FEATURE =
{1,1,2,2,2,0xEF,0xEE,7,7,0xFF,0xFF,0x80,0x01,0x00, RTYPE_TOSHIBA,\
{{{0 ,2},{1 ,4},{3 ,6},{5 ,8},{7 ,10},{9 ,12},{11 ,14},{13 ,16},\
{15 ,18},{17 ,20},{19 ,22},{21 ,24},{23 ,26},{25 ,28},{27 ,30},{29 ,32},\
{31 ,34},{33 ,36},{35 ,38},{37 ,40},{39 ,42},{41 ,44},{43 ,46},{45 ,48},\
{47 ,50},{49 ,52},{51 ,54},{53 ,56},{55 ,58},{57 ,60},{59 ,62},{61 ,64},\
{63 ,66},{65 ,68},{67 ,70},{69 ,72},{71 ,74},{73 ,76},{75 ,78},{77 ,80},\
{79 ,82},{81 ,84},{83 ,86},{85 ,88},{87 ,90},{89 ,92},{91 ,94},{93 ,96},\
{95 ,98},{97 ,100},{99 ,102},{101 ,104},{103 ,106},{105 ,108},{107 ,110},{109 ,112},\
{111 ,114},{113 ,116},{115 ,118},{117 ,120},{119 ,122},{121 ,124},{123 ,126},{125 ,128},\
{127 ,130},{129 ,132},{131 ,134},{133 ,136},{135 ,138},{137 ,140},{139 ,142},{141 ,144},\
{143 ,146},{145 ,148},{147 ,150},{149 ,152},{151 ,154},{153 ,156},{155 ,158},{157 ,160},\
{159 ,162},{161 ,164},{163 ,166},{165 ,168},{167 ,170},{169 ,172},{171 ,174},{173 ,176},\
{175 ,178},{177 ,180},{179 ,182},{181 ,184},{183 ,186},{185 ,188},{187 ,190},{189 ,192},\
{191 ,194},{193 ,196},{195 ,198},{197 ,200},{199 ,202},{201 ,204},{203 ,206},{205 ,208},\
{207 ,210},{209 ,212},{211 ,214},{213 ,216},{215 ,218},{217 ,220},{219 ,222},{221 ,224},\
{223 ,226},{225 ,228},{227 ,230},{229 ,232},{231 ,234},{233 ,236},{235 ,238},{237 ,240},\
{239 ,242},{241 ,244},{243 ,246},{245 ,248},{247 ,250},{249 ,252},{251 ,254},{253 ,255}}},
{0,1,2,3,4,5,6}};

NAND_MLC_FEATURE g_TOSHIBA_15NM_MLC_FEATURE =
{1,1,2,2,2,0xEF,0xEE,10,0,0xFF,0xFF,0x80,0x01,0x00, RTYPE_TOSHIBA_15NM,\
{{{0 ,2},{1 ,4},{3 ,6},{5 ,8},{7 ,10},{9 ,12},{11 ,14},{13 ,16},\
{15 ,18},{17 ,20},{19 ,22},{21 ,24},{23 ,26},{25 ,28},{27 ,30},{29 ,32},\
{31 ,34},{33 ,36},{35 ,38},{37 ,40},{39 ,42},{41 ,44},{43 ,46},{45 ,48},\
{47 ,50},{49 ,52},{51 ,54},{53 ,56},{55 ,58},{57 ,60},{59 ,62},{61 ,64},\
{63 ,66},{65 ,68},{67 ,70},{69 ,72},{71 ,74},{73 ,76},{75 ,78},{77 ,80},\
{79 ,82},{81 ,84},{83 ,86},{85 ,88},{87 ,90},{89 ,92},{91 ,94},{93 ,96},\
{95 ,98},{97 ,100},{99 ,102},{101 ,104},{103 ,106},{105 ,108},{107 ,110},{109 ,112},\
{111 ,114},{113 ,116},{115 ,118},{117 ,120},{119 ,122},{121 ,124},{123 ,126},{125 ,128},\
{127 ,130},{129 ,132},{131 ,134},{133 ,136},{135 ,138},{137 ,140},{139 ,142},{141 ,144},\
{143 ,146},{145 ,148},{147 ,150},{149 ,152},{151 ,154},{153 ,156},{155 ,158},{157 ,160},\
{159 ,162},{161 ,164},{163 ,166},{165 ,168},{167 ,170},{169 ,172},{171 ,174},{173 ,176},\
{175 ,178},{177 ,180},{179 ,182},{181 ,184},{183 ,186},{185 ,188},{187 ,190},{189 ,192},\
{191 ,194},{193 ,196},{195 ,198},{197 ,200},{199 ,202},{201 ,204},{203 ,206},{205 ,208},\
{207 ,210},{209 ,212},{211 ,214},{213 ,216},{215 ,218},{217 ,220},{219 ,222},{221 ,224},\
{223 ,226},{225 ,228},{227 ,230},{229 ,232},{231 ,234},{233 ,236},{235 ,238},{237 ,240},\
{239 ,242},{241 ,244},{243 ,246},{245 ,248},{247 ,250},{249 ,252},{251 ,254},{253 ,255}}},
{0,1,2,3,4,5,6,7,8,9}};

NAND_MLC_FEATURE g_HYNIX_MLC_FEATURE =
{1,1,2,2,2,
0xEF,0xEE,7,0,0xFF,0xFF,0x01,0x05,0x14, RTYPE_HYNIX, //cmd to be double confirmed  xiaolei
{{{0x0,0x4},{0x1,0x5},
{0x2,0x8},{0x3,0x9},{0x6,0xC},{0x7,0xD}, {0xA,0x10},{0xB,0x11},{0xE,0x14},{0xF,0x15},
{0x12,0x18},{0x13,0x19}, {0x16,0x1C},{0x17,0x1D},{0x1A,0x20},{0x1B,0x21},{0x1E,0x24},{0x1F,0x25},
{0x22,0x28},{0x23,0x29}, {0x26,0x2C},{0x27,0x2D},{0x2A,0x30},{0x2B,0x31},{0x2E,0x34},{0x2F,0x35},
{0x32,0x38},{0x33,0x39}, {0x36,0x3C},{0x37,0x3D},{0x3A,0x40},{0x3B,0x41},{0x3E,0x44},{0x3F,0x45},
{0x42,0x48},{0x43,0x49}, {0x46,0x4C},{0x47,0x4D},{0x4A,0x50},{0x4B,0x51},{0x4E,0x54},{0x4F,0x55},
{0x52,0x58},{0x53,0x59}, {0x56,0x5C},{0x57,0x5D},{0x5A,0x60},{0x5B,0x61},{0x5E,0x64},{0x5F,0x65},
{0x62,0x68},{0x63,0x69}, {0x66,0x6C},{0x67,0x6D},{0x6A,0x70},{0x6B,0x71},{0x6E,0x74},{0x6F,0x75},
{0x72,0x78},{0x73,0x79}, {0x76,0x7C},{0x77,0x7D},{0x7A,0x80},{0x7B,0x81},{0x7E,0x84},{0x7F,0x85},
{0x82,0x88},{0x83,0x89}, {0x86,0x8C},{0x87,0x8D},{0x8A,0x90},{0x8B,0x91},{0x8E,0x94},{0x8F,0x95},
{0x92,0x98},{0x93,0x99}, {0x96,0x9C},{0x97,0x9D},{0x9A,0xA0},{0x9B,0xA1},{0x9E,0xA4},{0x9F,0xA5},
{0xA2,0xA8},{0xA3,0xA9}, {0xA6,0xAC},{0xA7,0xAD},{0xAA,0xB0},{0xAB,0xB1},{0xAE,0xB4},{0xAF,0xB5},
{0xB2,0xB8},{0xB3,0xB9}, {0xB6,0xBC},{0xB7,0xBD},{0xBA,0xC0},{0xBB,0xC1},{0xBE,0xC4},{0xBF,0xC5},
{0xC2,0xC8},{0xC3,0xC9}, {0xC6,0xCC},{0xC7,0xCD},{0xCA,0xD0},{0xCB,0xD1},{0xCE,0xD4},{0xCF,0xD5},
{0xD2,0xD8},{0xD3,0xD9}, {0xD6,0xDC},{0xD7,0xDD},{0xDA,0xE0},{0xDB,0xE1},{0xDE,0xE4},{0xDF,0xE5},
{0xE2,0xE8},{0xE3,0xE9}, {0xE6,0xEC},{0xE7,0xED},{0xEA,0xF0},{0xEB,0xF1},{0xEE,0xF4},{0xEF,0xF5},
{0xF2,0xF8},{0xF3,0xF9}, {0xF6,0xFC},{0xF7,0xFD},{0xFA,0xFE},{0xFB,0xFF}}},
{1,2,3,4,5,6,7}};

NAND_MLC_FEATURE g_HYNIX_16NM_MLC_FEATURE =
{1,1,2,2,2,
0xEF,0xEE,8,0,0xFF,0xFF,0x01,0x05,0x14, RTYPE_HYNIX_16NM, //cmd to be double confirmed  xiaolei
{{{0 ,2},{1 ,4},{3 ,6},{5 ,8},{7 ,10},{9 ,12},{11 ,14},{13 ,16},\
{15 ,18},{17 ,20},{19 ,22},{21 ,24},{23 ,26},{25 ,28},{27 ,30},{29 ,32},\
{31 ,34},{33 ,36},{35 ,38},{37 ,40},{39 ,42},{41 ,44},{43 ,46},{45 ,48},\
{47 ,50},{49 ,52},{51 ,54},{53 ,56},{55 ,58},{57 ,60},{59 ,62},{61 ,64},\
{63 ,66},{65 ,68},{67 ,70},{69 ,72},{71 ,74},{73 ,76},{75 ,78},{77 ,80},\
{79 ,82},{81 ,84},{83 ,86},{85 ,88},{87 ,90},{89 ,92},{91 ,94},{93 ,96},\
{95 ,98},{97 ,100},{99 ,102},{101 ,104},{103 ,106},{105 ,108},{107 ,110},{109 ,112},\
{111 ,114},{113 ,116},{115 ,118},{117 ,120},{119 ,122},{121 ,124},{123 ,126},{125 ,128},\
{127 ,130},{129 ,132},{131 ,134},{133 ,136},{135 ,138},{137 ,140},{139 ,142},{141 ,144},\
{143 ,146},{145 ,148},{147 ,150},{149 ,152},{151 ,154},{153 ,156},{155 ,158},{157 ,160},\
{159 ,162},{161 ,164},{163 ,166},{165 ,168},{167 ,170},{169 ,172},{171 ,174},{173 ,176},\
{175 ,178},{177 ,180},{179 ,182},{181 ,184},{183 ,186},{185 ,188},{187 ,190},{189 ,192},\
{191 ,194},{193 ,196},{195 ,198},{197 ,200},{199 ,202},{201 ,204},{203 ,206},{205 ,208},\
{207 ,210},{209 ,212},{211 ,214},{213 ,216},{215 ,218},{217 ,220},{219 ,222},{221 ,224},\
{223 ,226},{225 ,228},{227 ,230},{229 ,232},{231 ,234},{233 ,236},{235 ,238},{237 ,240},\
{239 ,242},{241 ,244},{243 ,246},{245 ,248},{247 ,250},{249 ,252},{251 ,254},{253 ,255}}},
{1,2,3,4,5,6,7}};
#endif

NAND_MLC_FEATURE g_SANDISK_MLC_FEATURE =
{1,1,2,2,2,0xEF,0xEE,32,0,0x11,0x5D,0x80,0x01,0x00, RTYPE_SANDISK,\
{{{0 ,2},{1 ,4},{3 ,6},{5 ,8},{7 ,10},{9 ,12},{11 ,14},{13 ,16},\
{15 ,18},{17 ,20},{19 ,22},{21 ,24},{23 ,26},{25 ,28},{27 ,30},{29 ,32},\
{31 ,34},{33 ,36},{35 ,38},{37 ,40},{39 ,42},{41 ,44},{43 ,46},{45 ,48},\
{47 ,50},{49 ,52},{51 ,54},{53 ,56},{55 ,58},{57 ,60},{59 ,62},{61 ,64},\
{63 ,66},{65 ,68},{67 ,70},{69 ,72},{71 ,74},{73 ,76},{75 ,78},{77 ,80},\
{79 ,82},{81 ,84},{83 ,86},{85 ,88},{87 ,90},{89 ,92},{91 ,94},{93 ,96},\
{95 ,98},{97 ,100},{99 ,102},{101 ,104},{103 ,106},{105 ,108},{107 ,110},{109 ,112},\
{111 ,114},{113 ,116},{115 ,118},{117 ,120},{119 ,122},{121 ,124},{123 ,126},{125 ,128},\
{127 ,130},{129 ,132},{131 ,134},{133 ,136},{135 ,138},{137 ,140},{139 ,142},{141 ,144},\
{143 ,146},{145 ,148},{147 ,150},{149 ,152},{151 ,154},{153 ,156},{155 ,158},{157 ,160},\
{159 ,162},{161 ,164},{163 ,166},{165 ,168},{167 ,170},{169 ,172},{171 ,174},{173 ,176},\
{175 ,178},{177 ,180},{179 ,182},{181 ,184},{183 ,186},{185 ,188},{187 ,190},{189 ,192},\
{191 ,194},{193 ,196},{195 ,198},{197 ,200},{199 ,202},{201 ,204},{203 ,206},{205 ,208},\
{207 ,210},{209 ,212},{211 ,214},{213 ,216},{215 ,218},{217 ,220},{219 ,222},{221 ,224},\
{223 ,226},{225 ,228},{227 ,230},{229 ,232},{231 ,234},{233 ,236},{235 ,238},{237 ,240},\
{239 ,242},{241 ,244},{243 ,246},{245 ,248},{247 ,250},{249 ,252},{251 ,254},{253 ,255}}},
{0x00000000,0x7C00007C,0x04007C78,0x78007874,
0x087C007C,0x007C7C78,0x7C7C7874,0x007C7470,
0x0078007C,0x00787C78,0x00787874,0x00787470,
0x0078706C,0x00040400,0x0004007C,0x0C047C78,
0x0C047874,0x1008007C,0x10080400,0x78747874,
0x78747470,0x7874706C,0x78746C68,0x78707874,
0x78707470,0x78706C68,0x7870706C,0x786C706C,
0x786C6C68,0x786C6864,0x74686C68,0x74686864}};

#if 0
NFI_TLC_FEATURE g_SANDISK_TLC_FEATURE =
{TRUE, FALSE,TRUE, TRUE, TRUE, 0xA2, 0xFF, 0xA2, 68, TRUE, 9, 8,3, FALSE};
NFI_TLC_FEATURE g_HYNIX_TLC_FEATURE =
{TRUE, FALSE, FALSE, FALSE, TRUE, 0xDA, 0xBE, 0xA2, 72, TRUE, 8, 0,2, FALSE};
NFI_TLC_FEATURE g_HYNIX_MLCTLC_FEATURE =
{FALSE, FALSE, FALSE, FALSE, FALSE, 0xBF, 0xBE, 0xBF, 40, FALSE, 0, 0,8, FALSE};
#endif
NFI_TLC_FEATURE g_TOSHIBA_TLC_FEATURE =
{TRUE, FALSE, FALSE, TRUE, TRUE, 0xA2, 0xFF, 0xA2, 68, TRUE, 8, 0,3};
NFI_TLC_FEATURE g_SANDISK_MLCTLC_FEATURE =
{FALSE, FALSE, FALSE, FALSE, FALSE, 0xA2, 0xFF, 0xA2, 40, FALSE, 0, 0,8};
NFI_TLC_FEATURE g_MICRON_MLCTLC_FEATURE =
{FALSE, FALSE, FALSE, FALSE, FALSE, 0xFF, 0xFF, 0xFF, 40, FALSE, 0, 0,8};

#pragma arm section rodata = "NAND_FLASH_TABLE"

const NAND_Device_S g_NandFlashDevTbl_Internal[] = {
    // NAND_FLASH_ID,          {{DEVICE_ID},                                 Density, Pages/B, Bytes/P, IO, Address Cycle, Spare size/Sector ,   N/A},       Command sets,               Driver sets}
    // TLC NAND	use SLC mode tDensity = PagesPerBlock * PageSize * BlockSize

	//Sandisk 1Znm TLC
	{ TNAND_SDTNSIAMA016G,  { { 0x45, 0x4C, 0x98, 0xA3, 0x76, 0xFF, 0xFF}, (0x169800000)/*B*/, 128, 16384, NAND_IO_8BITS, 5, 122, 0, 1024, 1}, NAND_FLASH_TLC, &g_TOSHIBA_TLC_FEATURE, &g_NAND_TOSHIBA_2048_CMD_SET, NULL}

	//Toshiba 15nm TLC
	,{ TNAND_TC58TEG7THLBA09,  { { 0x98, 0x3A, 0x98, 0xA3, 0x76, 0xFF, 0xFF}, (0x169800000)/*B*/, 128, 16384, NAND_IO_8BITS, 5, 122, 0, 1024, 1}, NAND_FLASH_TLC, &g_TOSHIBA_TLC_FEATURE, &g_NAND_TOSHIBA_2048_CMD_SET, NULL}
	//Sandisk 1Znm MLC
	,{ NAND_SDTNSGAMA008G,   { { 0x45, 0xDE, 0x94, 0x93, 0x76, 0x51, 0xFF},   8192/*MB*/, 256, 16384, NAND_IO_8BITS, 5, 80,0 , 1024, 1}, NAND_FLASH_AMLC, &g_SANDISK_MLCTLC_FEATURE, &g_NAND_SAMSUNG_2048_CMD_SET, &g_SANDISK_MLC_FEATURE}
	// SLC
	,{ NAND_MX30LF4G18AC,   { { 0xC2, 0xDC, 0x90, 0x95, 0x56, 0x0, 0xFF},   512/*MB*/, 64, 2048, NAND_IO_8BITS, 5, 32,0 , 1024, 0}, NAND_FLASH_SLC, NULL, &g_NAND_SAMSUNG_2048_CMD_SET, NULL}
	,{ NAND_TC58NVG2S0HTA00,   { { 0x98, 0xDC, 0x90, 0x26, 0x76, 0x0, 0xFF},   512/*MB*/, 64, 4096, NAND_IO_8BITS, 5, 64,0 , 1024, 0}, NAND_FLASH_SLC, NULL, &g_NAND_SAMSUNG_2048_CMD_SET, NULL}
	,{ NAND_MT29F8G08ABABA,   { { 0x2C, 0x38, 0x00, 0x26, 0x85, 0x0, 0xFF},   1024/*MB*/, 128, 4096, NAND_IO_8BITS, 5, 56,0 , 1024, 0}, NAND_FLASH_SLC, NULL, &g_NAND_SAMSUNG_2048_CMD_SET, NULL}
	,{ NAND_MT29F2G08ABAEA,   { { 0x2C, 0xDA, 0x90, 0x95, 0x06, 0x0, 0xFF},   256/*MB*/, 64, 2048, NAND_IO_8BITS, 5, 32,0 , 1024, 0}, NAND_FLASH_SLC, NULL, &g_NAND_SAMSUNG_2048_CMD_SET, NULL}
    // end of the table
	,{ NAND_UNKNOWN,   { { {0}},   0/*MB*/, 0, 0, 0, 0, 0,0 , 0, 0}, 0, NULL, NULL, NULL}
};
#pragma arm section rodata

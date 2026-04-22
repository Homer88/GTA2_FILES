#pragma once

#include <cstdint>
#include "gta2_types.h"

// Forward declarations
struct Ped;
struct Car;
struct Weapon;
struct Gang;

// Player structure size: 0x8B0 (2224 bytes)
// Fields count: 218
// Based on IDA Pro analysis of gta2.exe
#pragma pack(push, 1)
struct Player {
    char field_0[4];             // 0x0000 - placeholder
    char field_4[4];             // 0x0004 - placeholder
    char field_8[4];             // 0x0008 - placeholder
    char field_C[4];             // 0x000C - placeholder
    char field_10[4];            // 0x0010 - placeholder
    char field_14[4];            // 0x0014 - placeholder
    char field_18[4];            // 0x0018 - placeholder
    char field_1C[4];            // 0x001C - placeholder
    char field_20[4];            // 0x0020 - placeholder
    char field_24[4];            // 0x0024 - placeholder
    char field_28[4];            // 0x0028 - placeholder
    char field_2C[4];            // 0x002C - placeholder
    char field_30[4];            // 0x0030 - placeholder
    char field_34[4];            // 0x0034 - placeholder
    char field_38[4];            // 0x0038 - placeholder
    char field_3C[4];            // 0x003C - placeholder
    char field_40[4];            // 0x0040 - placeholder
    char field_44[4];            // 0x0044 - placeholder
    char field_48[4];            // 0x0048 - placeholder
    char field_4C[4];            // 0x004C - placeholder
    char field_50[4];            // 0x0050 - placeholder
    char field_54[4];            // 0x0054 - placeholder
    char field_58[4];            // 0x0058 - placeholder
    char field_5C[4];            // 0x005C - placeholder
    char field_60[4];            // 0x0060 - placeholder
    char field_64[4];            // 0x0064 - placeholder
    char field_68[4];            // 0x0068 - placeholder
    char field_6C[4];            // 0x006C - placeholder
    char field_70[4];            // 0x0070 - placeholder
    char field_74[4];            // 0x0074 - placeholder
    char field_78[4];            // 0x0078 - placeholder
    char field_7C[4];            // 0x007C - placeholder
    char field_80[4];            // 0x0080 - placeholder
    char field_84[4];            // 0x0084 - placeholder
    char field_88[4];            // 0x0088 - placeholder
    char field_8C[4];            // 0x008C - placeholder
    char field_90[4];            // 0x0090 - placeholder
    char field_94[4];            // 0x0094 - placeholder
    char field_98[4];            // 0x0098 - placeholder
    char field_9C[4];            // 0x009C - placeholder
    char field_A0[4];            // 0x00A0 - placeholder
    char field_A4[4];            // 0x00A4 - placeholder
    char field_A8[4];            // 0x00A8 - placeholder
    char field_AC[4];            // 0x00AC - placeholder
    char field_B0[4];            // 0x00B0 - placeholder
    char field_B4[4];            // 0x00B4 - placeholder
    char field_B8[4];            // 0x00B8 - placeholder
    char field_BC[4];            // 0x00BC - placeholder
    char field_C0[4];            // 0x00C0 - placeholder
    char field_C4[4];            // 0x00C4 - placeholder
    char field_C8[4];            // 0x00C8 - placeholder
    char field_CC[4];            // 0x00CC - placeholder
    char field_D0[4];            // 0x00D0 - placeholder
    char field_D4[4];            // 0x00D4 - placeholder
    char field_D8[4];            // 0x00D8 - placeholder
    char field_DC[4];            // 0x00DC - placeholder
    char field_E0[4];            // 0x00E0 - placeholder
    char field_E4[4];            // 0x00E4 - placeholder
    char field_E8[4];            // 0x00E8 - placeholder
    char field_EC[4];            // 0x00EC - placeholder
    char field_F0[4];            // 0x00F0 - placeholder
    char field_F4[4];            // 0x00F4 - placeholder
    char field_F8[4];            // 0x00F8 - placeholder
    char field_FC[4];            // 0x00FC - placeholder
    char field_100[4];           // 0x0100 - placeholder
    char field_104[4];           // 0x0104 - placeholder
    char field_108[4];           // 0x0108 - placeholder
    char field_10C[4];           // 0x010C - placeholder
    char field_110[4];           // 0x0110 - placeholder
    char field_114[4];           // 0x0114 - placeholder
    char field_118[4];           // 0x0118 - placeholder
    char field_11C[4];           // 0x011C - placeholder
    char field_120[4];           // 0x0120 - placeholder
    char field_124[4];           // 0x0124 - placeholder
    char field_128[4];           // 0x0128 - placeholder
    char field_12C[4];           // 0x012C - placeholder
    char field_130[4];           // 0x0130 - placeholder
    char field_134[4];           // 0x0134 - placeholder
    char field_138[4];           // 0x0138 - placeholder
    char field_13C[4];           // 0x013C - placeholder
    char field_140[4];           // 0x0140 - placeholder
    char field_144[4];           // 0x0144 - placeholder
    char field_148[4];           // 0x0148 - placeholder
    char field_14C[4];           // 0x014C - placeholder
    char field_150[4];           // 0x0150 - placeholder
    char field_154[4];           // 0x0154 - placeholder
    char field_158[4];           // 0x0158 - placeholder
    char field_15C[4];           // 0x015C - placeholder
    char field_160[4];           // 0x0160 - placeholder
    char field_164[4];           // 0x0164 - placeholder
    char field_168[4];           // 0x0168 - placeholder
    char field_16C[4];           // 0x016C - placeholder
    char field_170[4];           // 0x0170 - placeholder
    char field_174[4];           // 0x0174 - placeholder
    char field_178[4];           // 0x0178 - placeholder
    char field_17C[4];           // 0x017C - placeholder
    char field_180[4];           // 0x0180 - placeholder
    char field_184[4];           // 0x0184 - placeholder
    char field_188[4];           // 0x0188 - placeholder
    char field_18C[4];           // 0x018C - placeholder
    char field_190[4];           // 0x0190 - placeholder
    char field_194[4];           // 0x0194 - placeholder
    char field_198[4];           // 0x0198 - placeholder
    char field_19C[4];           // 0x019C - placeholder
    char field_1A0[4];           // 0x01A0 - placeholder
    char field_1A4[4];           // 0x01A4 - placeholder
    char field_1A8[4];           // 0x01A8 - placeholder
    char field_1AC[4];           // 0x01AC - placeholder
    char field_1B0[4];           // 0x01B0 - placeholder
    char field_1B4[4];           // 0x01B4 - placeholder
    char field_1B8[4];           // 0x01B8 - placeholder
    char field_1BC[4];           // 0x01BC - placeholder
    char field_1C0[4];           // 0x01C0 - placeholder
    char field_1C4[4];           // 0x01C4 - placeholder
    char field_1C8[4];           // 0x01C8 - placeholder
    char field_1CC[4];           // 0x01CC - placeholder
    char field_1D0[4];           // 0x01D0 - placeholder
    char field_1D4[4];           // 0x01D4 - placeholder
    char field_1D8[4];           // 0x01D8 - placeholder
    char field_1DC[4];           // 0x01DC - placeholder
    char field_1E0[4];           // 0x01E0 - placeholder
    char field_1E4[4];           // 0x01E4 - placeholder
    char field_1E8[4];           // 0x01E8 - placeholder
    char field_1EC[4];           // 0x01EC - placeholder
    char field_1F0[4];           // 0x01F0 - placeholder
    char field_1F4[4];           // 0x01F4 - placeholder
    char field_1F8[4];           // 0x01F8 - placeholder
    char field_1FC[4];           // 0x01FC - placeholder
    char field_200[4];           // 0x0200 - placeholder
    char field_204[4];           // 0x0204 - placeholder
    char field_208[4];           // 0x0208 - placeholder
    char field_20C[4];           // 0x020C - placeholder
    char field_210[4];           // 0x0210 - placeholder
    char field_214[4];           // 0x0214 - placeholder
    char field_218[4];           // 0x0218 - placeholder
    char field_21C[4];           // 0x021C - placeholder
    char field_220[4];           // 0x0220 - placeholder
    char field_224[4];           // 0x0224 - placeholder
    char field_228[4];           // 0x0228 - placeholder
    char field_22C[4];           // 0x022C - placeholder
    char field_230[4];           // 0x0230 - placeholder
    char field_234[4];           // 0x0234 - placeholder
    char field_238[4];           // 0x0238 - placeholder
    char field_23C[4];           // 0x023C - placeholder
    char field_240[4];           // 0x0240 - placeholder
    char field_244[4];           // 0x0244 - placeholder
    char field_248[4];           // 0x0248 - placeholder
    char field_24C[4];           // 0x024C - placeholder
    char field_250[4];           // 0x0250 - placeholder
    char field_254[4];           // 0x0254 - placeholder
    char field_258[4];           // 0x0258 - placeholder
    char field_25C[4];           // 0x025C - placeholder
    char field_260[4];           // 0x0260 - placeholder
    char field_264[4];           // 0x0264 - placeholder
    char field_268[4];           // 0x0268 - placeholder
    char field_26C[4];           // 0x026C - placeholder
    char field_270[4];           // 0x0270 - placeholder
    char field_274[4];           // 0x0274 - placeholder
    char field_278[4];           // 0x0278 - placeholder
    char field_27C[4];           // 0x027C - placeholder
    char field_280[4];           // 0x0280 - placeholder
    char field_284[4];           // 0x0284 - placeholder
    char field_288[4];           // 0x0288 - placeholder
    char field_28C[4];           // 0x028C - placeholder
    char field_290[4];           // 0x0290 - placeholder
    char field_294[4];           // 0x0294 - placeholder
    char field_298[4];           // 0x0298 - placeholder
    char field_29C[4];           // 0x029C - placeholder
    char field_2A0[4];           // 0x02A0 - placeholder
    char field_2A4[4];           // 0x02A4 - placeholder
    char field_2A8[4];           // 0x02A8 - placeholder
    char field_2AC[4];           // 0x02AC - placeholder
    char field_2B0[4];           // 0x02B0 - placeholder
    char field_2B4[4];           // 0x02B4 - placeholder
    char field_2B8[4];           // 0x02B8 - placeholder
    char field_2BC[4];           // 0x02BC - placeholder
    char field_2C0[4];           // 0x02C0 - placeholder
    char field_2C4[4];           // 0x02C4 - placeholder
    char field_2C8[4];           // 0x02C8 - placeholder
    char field_2CC[4];           // 0x02CC - placeholder
    char field_2D0[4];           // 0x02D0 - placeholder
    char field_2D4[4];           // 0x02D4 - placeholder
    char field_2D8[4];           // 0x02D8 - placeholder
    char field_2DC[4];           // 0x02DC - placeholder
    char field_2E0[4];           // 0x02E0 - placeholder
    char field_2E4[4];           // 0x02E4 - placeholder
    char field_2E8[4];           // 0x02E8 - placeholder
    char field_2EC[4];           // 0x02EC - placeholder
    char field_2F0[4];           // 0x02F0 - placeholder
    char field_2F4[4];           // 0x02F4 - placeholder
    char field_2F8[4];           // 0x02F8 - placeholder
    char field_2FC[4];           // 0x02FC - placeholder
    char field_300[4];           // 0x0300 - placeholder
    char field_304[4];           // 0x0304 - placeholder
    char field_308[4];           // 0x0308 - placeholder
    char field_30C[4];           // 0x030C - placeholder
    char field_310[4];           // 0x0310 - placeholder
    char field_314[4];           // 0x0314 - placeholder
    char field_318[4];           // 0x0318 - placeholder
    char field_31C[4];           // 0x031C - placeholder
    char field_320[4];           // 0x0320 - placeholder
    char field_324[4];           // 0x0324 - placeholder
    char field_328[4];           // 0x0328 - placeholder
    char field_32C[4];           // 0x032C - placeholder
    char field_330[4];           // 0x0330 - placeholder
    char field_334[4];           // 0x0334 - placeholder
    char field_338[4];           // 0x0338 - placeholder
    char field_33C[4];           // 0x033C - placeholder
    char field_340[4];           // 0x0340 - placeholder
    char field_344[4];           // 0x0344 - placeholder
    char field_348[4];           // 0x0348 - placeholder
    char field_34C[4];           // 0x034C - placeholder
    char field_350[4];           // 0x0350 - placeholder
    char field_354[4];           // 0x0354 - placeholder
    char field_358[4];           // 0x0358 - placeholder
    char field_35C[4];           // 0x035C - placeholder
    char field_360[4];           // 0x0360 - placeholder
    char field_364[4];           // 0x0364 - placeholder
    char field_368[4];           // 0x0368 - placeholder
    char field_36C[4];           // 0x036C - placeholder
    char field_370[4];           // 0x0370 - placeholder
    char field_374[4];           // 0x0374 - placeholder
    char field_378[4];           // 0x0378 - placeholder
    char field_37C[4];           // 0x037C - placeholder
    char field_380[4];           // 0x0380 - placeholder
    char field_384[4];           // 0x0384 - placeholder
    char field_388[4];           // 0x0388 - placeholder
    char field_38C[4];           // 0x038C - placeholder
    char field_390[4];           // 0x0390 - placeholder
    char field_394[4];           // 0x0394 - placeholder
    char field_398[4];           // 0x0398 - placeholder
    char field_39C[4];           // 0x039C - placeholder
    char field_3A0[4];           // 0x03A0 - placeholder
    char field_3A4[4];           // 0x03A4 - placeholder
    char field_3A8[4];           // 0x03A8 - placeholder
    char field_3AC[4];           // 0x03AC - placeholder
    char field_3B0[4];           // 0x03B0 - placeholder
    char field_3B4[4];           // 0x03B4 - placeholder
    char field_3B8[4];           // 0x03B8 - placeholder
    char field_3BC[4];           // 0x03BC - placeholder
    char field_3C0[4];           // 0x03C0 - placeholder
    char field_3C4[4];           // 0x03C4 - placeholder
    char field_3C8[4];           // 0x03C8 - placeholder
    char field_3CC[4];           // 0x03CC - placeholder
    char field_3D0[4];           // 0x03D0 - placeholder
    char field_3D4[4];           // 0x03D4 - placeholder
    char field_3D8[4];           // 0x03D8 - placeholder
    char field_3DC[4];           // 0x03DC - placeholder
    char field_3E0[4];           // 0x03E0 - placeholder
    char field_3E4[4];           // 0x03E4 - placeholder
    char field_3E8[4];           // 0x03E8 - placeholder
    char field_3EC[4];           // 0x03EC - placeholder
    char field_3F0[4];           // 0x03F0 - placeholder
    char field_3F4[4];           // 0x03F4 - placeholder
    char field_3F8[4];           // 0x03F8 - placeholder
    char field_3FC[4];           // 0x03FC - placeholder
    char field_400[4];           // 0x0400 - placeholder
    char field_404[4];           // 0x0404 - placeholder
    char field_408[4];           // 0x0408 - placeholder
    char field_40C[4];           // 0x040C - placeholder
    char field_410[4];           // 0x0410 - placeholder
    char field_414[4];           // 0x0414 - placeholder
    char field_418[4];           // 0x0418 - placeholder
    char field_41C[4];           // 0x041C - placeholder
    char field_420[4];           // 0x0420 - placeholder
    char field_424[4];           // 0x0424 - placeholder
    char field_428[4];           // 0x0428 - placeholder
    char field_42C[4];           // 0x042C - placeholder
    char field_430[4];           // 0x0430 - placeholder
    char field_434[4];           // 0x0434 - placeholder
    char field_438[4];           // 0x0438 - placeholder
    char field_43C[4];           // 0x043C - placeholder
    char field_440[4];           // 0x0440 - placeholder
    char field_444[4];           // 0x0444 - placeholder
    char field_448[4];           // 0x0448 - placeholder
    char field_44C[4];           // 0x044C - placeholder
    char field_450[4];           // 0x0450 - placeholder
    char field_454[4];           // 0x0454 - placeholder
    char field_458[4];           // 0x0458 - placeholder
    char field_45C[4];           // 0x045C - placeholder
    char field_460[4];           // 0x0460 - placeholder
    char field_464[4];           // 0x0464 - placeholder
    char field_468[4];           // 0x0468 - placeholder
    char field_46C[4];           // 0x046C - placeholder
    char field_470[4];           // 0x0470 - placeholder
    char field_474[4];           // 0x0474 - placeholder
    char field_478[4];           // 0x0478 - placeholder
    char field_47C[4];           // 0x047C - placeholder
    char field_480[4];           // 0x0480 - placeholder
    char field_484[4];           // 0x0484 - placeholder
    char field_488[4];           // 0x0488 - placeholder
    char field_48C[4];           // 0x048C - placeholder
    char field_490[4];           // 0x0490 - placeholder
    char field_494[4];           // 0x0494 - placeholder
    char field_498[4];           // 0x0498 - placeholder
    char field_49C[4];           // 0x049C - placeholder
    char field_4A0[4];           // 0x04A0 - placeholder
    char field_4A4[4];           // 0x04A4 - placeholder
    char field_4A8[4];           // 0x04A8 - placeholder
    char field_4AC[4];           // 0x04AC - placeholder
    char field_4B0[4];           // 0x04B0 - placeholder
    char field_4B4[4];           // 0x04B4 - placeholder
    char field_4B8[4];           // 0x04B8 - placeholder
    char field_4BC[4];           // 0x04BC - placeholder
    char field_4C0[4];           // 0x04C0 - placeholder
    char field_4C4[4];           // 0x04C4 - placeholder
    char field_4C8[4];           // 0x04C8 - placeholder
    char field_4CC[4];           // 0x04CC - placeholder
    char field_4D0[4];           // 0x04D0 - placeholder
    char field_4D4[4];           // 0x04D4 - placeholder
    char field_4D8[4];           // 0x04D8 - placeholder
    char field_4DC[4];           // 0x04DC - placeholder
    char field_4E0[4];           // 0x04E0 - placeholder
    char field_4E4[4];           // 0x04E4 - placeholder
    char field_4E8[4];           // 0x04E8 - placeholder
    char field_4EC[4];           // 0x04EC - placeholder
    char field_4F0[4];           // 0x04F0 - placeholder
    char field_4F4[4];           // 0x04F4 - placeholder
    char field_4F8[4];           // 0x04F8 - placeholder
    char field_4FC[4];           // 0x04FC - placeholder
    char field_500[4];           // 0x0500 - placeholder
    char field_504[4];           // 0x0504 - placeholder
    char field_508[4];           // 0x0508 - placeholder
    char field_50C[4];           // 0x050C - placeholder
    char field_510[4];           // 0x0510 - placeholder
    char field_514[4];           // 0x0514 - placeholder
    char field_518[4];           // 0x0518 - placeholder
    char field_51C[4];           // 0x051C - placeholder
    char field_520[4];           // 0x0520 - placeholder
    char field_524[4];           // 0x0524 - placeholder
    char field_528[4];           // 0x0528 - placeholder
    char field_52C[4];           // 0x052C - placeholder
    char field_530[4];           // 0x0530 - placeholder
    char field_534[4];           // 0x0534 - placeholder
    char field_538[4];           // 0x0538 - placeholder
    char field_53C[4];           // 0x053C - placeholder
    char field_540[4];           // 0x0540 - placeholder
    char field_544[4];           // 0x0544 - placeholder
    char field_548[4];           // 0x0548 - placeholder
    char field_54C[4];           // 0x054C - placeholder
    char field_550[4];           // 0x0550 - placeholder
    char field_554[4];           // 0x0554 - placeholder
    char field_558[4];           // 0x0558 - placeholder
    char field_55C[4];           // 0x055C - placeholder
    char field_560[4];           // 0x0560 - placeholder
    char field_564[4];           // 0x0564 - placeholder
    char field_568[4];           // 0x0568 - placeholder
    char field_56C[4];           // 0x056C - placeholder
    char field_570[4];           // 0x0570 - placeholder
    char field_574[4];           // 0x0574 - placeholder
    char field_578[4];           // 0x0578 - placeholder
    char field_57C[4];           // 0x057C - placeholder
    char field_580[4];           // 0x0580 - placeholder
    char field_584[4];           // 0x0584 - placeholder
    char field_588[4];           // 0x0588 - placeholder
    char field_58C[4];           // 0x058C - placeholder
    char field_590[4];           // 0x0590 - placeholder
    char field_594[4];           // 0x0594 - placeholder
    char field_598[4];           // 0x0598 - placeholder
    char field_59C[4];           // 0x059C - placeholder
    char field_5A0[4];           // 0x05A0 - placeholder
    char field_5A4[4];           // 0x05A4 - placeholder
    char field_5A8[4];           // 0x05A8 - placeholder
    char field_5AC[4];           // 0x05AC - placeholder
    char field_5B0[4];           // 0x05B0 - placeholder
    char field_5B4[4];           // 0x05B4 - placeholder
    char field_5B8[4];           // 0x05B8 - placeholder
    char field_5BC[4];           // 0x05BC - placeholder
    char field_5C0[4];           // 0x05C0 - placeholder
    char field_5C4[4];           // 0x05C4 - placeholder
    char field_5C8[4];           // 0x05C8 - placeholder
    char field_5CC[4];           // 0x05CC - placeholder
    char field_5D0[4];           // 0x05D0 - placeholder
    char field_5D4[4];           // 0x05D4 - placeholder
    char field_5D8[4];           // 0x05D8 - placeholder
    char field_5DC[4];           // 0x05DC - placeholder
    char field_5E0[4];           // 0x05E0 - placeholder
    char field_5E4[4];           // 0x05E4 - placeholder
    char field_5E8[4];           // 0x05E8 - placeholder
    char field_5EC[4];           // 0x05EC - placeholder
    char field_5F0[4];           // 0x05F0 - placeholder
    char field_5F4[4];           // 0x05F4 - placeholder
    char field_5F8[4];           // 0x05F8 - placeholder
    char field_5FC[4];           // 0x05FC - placeholder
    char field_600[4];           // 0x0600 - placeholder
    char field_604[4];           // 0x0604 - placeholder
    char field_608[4];           // 0x0608 - placeholder
    char field_60C[4];           // 0x060C - placeholder
    char field_610[4];           // 0x0610 - placeholder
    char field_614[4];           // 0x0614 - placeholder
    char field_618[4];           // 0x0618 - placeholder
    char field_61C[4];           // 0x061C - placeholder
    char field_620[4];           // 0x0620 - placeholder
    char field_624[4];           // 0x0624 - placeholder
    char field_628[4];           // 0x0628 - placeholder
    char field_62C[4];           // 0x062C - placeholder
    char field_630[4];           // 0x0630 - placeholder
    char field_634[4];           // 0x0634 - placeholder
    char field_638[4];           // 0x0638 - placeholder
    char field_63C[4];           // 0x063C - placeholder
    char field_640[4];           // 0x0640 - placeholder
    char field_644[4];           // 0x0644 - placeholder
    char field_648[4];           // 0x0648 - placeholder
    char field_64C[4];           // 0x064C - placeholder
    char field_650[4];           // 0x0650 - placeholder
    char field_654[4];           // 0x0654 - placeholder
    char field_658[4];           // 0x0658 - placeholder
    char field_65C[4];           // 0x065C - placeholder
    char field_660[4];           // 0x0660 - placeholder
    char field_664[4];           // 0x0664 - placeholder
    char field_668[4];           // 0x0668 - placeholder
    char field_66C[4];           // 0x066C - placeholder
    char field_670[4];           // 0x0670 - placeholder
    char field_674[4];           // 0x0674 - placeholder
    char field_678[4];           // 0x0678 - placeholder
    char field_67C[4];           // 0x067C - placeholder
    char field_680[4];           // 0x0680 - placeholder
    char field_684[4];           // 0x0684 - placeholder
    char field_688[4];           // 0x0688 - placeholder
    char field_68C[4];           // 0x068C - placeholder
    char field_690[4];           // 0x0690 - placeholder
    char field_694[4];           // 0x0694 - placeholder
    char field_698[4];           // 0x0698 - placeholder
    char field_69C[4];           // 0x069C - placeholder
    char field_6A0[4];           // 0x06A0 - placeholder
    char field_6A4[4];           // 0x06A4 - placeholder
    char field_6A8[4];           // 0x06A8 - placeholder
    char field_6AC[4];           // 0x06AC - placeholder
    char field_6B0[4];           // 0x06B0 - placeholder
    char field_6B4[4];           // 0x06B4 - placeholder
    char field_6B8[4];           // 0x06B8 - placeholder
    char field_6BC[4];           // 0x06BC - placeholder
    char field_6C0[4];           // 0x06C0 - placeholder
    char field_6C4[4];           // 0x06C4 - placeholder
    char field_6C8[4];           // 0x06C8 - placeholder
    char field_6CC[4];           // 0x06CC - placeholder
    char field_6D0[4];           // 0x06D0 - placeholder
    char field_6D4[4];           // 0x06D4 - placeholder
    char field_6D8[4];           // 0x06D8 - placeholder
    char field_6DC[4];           // 0x06DC - placeholder
    char field_6E0[4];           // 0x06E0 - placeholder
    char field_6E4[4];           // 0x06E4 - placeholder
    char field_6E8[4];           // 0x06E8 - placeholder
    char field_6EC[4];           // 0x06EC - placeholder
    char field_6F0[4];           // 0x06F0 - placeholder
    char field_6F4[4];           // 0x06F4 - placeholder
    char field_6F8[4];           // 0x06F8 - placeholder
    char field_6FC[4];           // 0x06FC - placeholder
    char field_700[4];           // 0x0700 - placeholder
    char field_704[4];           // 0x0704 - placeholder
    char field_708[4];           // 0x0708 - placeholder
    char field_70C[4];           // 0x070C - placeholder
    char field_710[4];           // 0x0710 - placeholder
    char field_714[4];           // 0x0714 - placeholder
    char field_718[4];           // 0x0718 - placeholder
    char field_71C[4];           // 0x071C - placeholder
    char field_720[4];           // 0x0720 - placeholder
    char field_724[4];           // 0x0724 - placeholder
    char field_728[4];           // 0x0728 - placeholder
    char field_72C[4];           // 0x072C - placeholder
    char field_730[4];           // 0x0730 - placeholder
    char field_734[4];           // 0x0734 - placeholder
    char field_738[4];           // 0x0738 - placeholder
    char field_73C[4];           // 0x073C - placeholder
    char field_740[4];           // 0x0740 - placeholder
    char field_744[4];           // 0x0744 - placeholder
    char field_748[4];           // 0x0748 - placeholder
    char field_74C[4];           // 0x074C - placeholder
    char field_750[4];           // 0x0750 - placeholder
    char field_754[4];           // 0x0754 - placeholder
    char field_758[4];           // 0x0758 - placeholder
    char field_75C[4];           // 0x075C - placeholder
    char field_760[4];           // 0x0760 - placeholder
    char field_764[4];           // 0x0764 - placeholder
    char field_768[4];           // 0x0768 - placeholder
    char field_76C[4];           // 0x076C - placeholder
    char field_770[4];           // 0x0770 - placeholder
    char field_774[4];           // 0x0774 - placeholder
    char field_778[4];           // 0x0778 - placeholder
    char field_77C[4];           // 0x077C - placeholder
    char field_780[4];           // 0x0780 - placeholder
    char field_784[4];           // 0x0784 - placeholder
    char field_788[4];           // 0x0788 - placeholder
    char field_78C[4];           // 0x078C - placeholder
    char field_790[4];           // 0x0790 - placeholder
    char field_794[4];           // 0x0794 - placeholder
    char field_798[4];           // 0x0798 - placeholder
    char field_79C[4];           // 0x079C - placeholder
    char field_7A0[4];           // 0x07A0 - placeholder
    char field_7A4[4];           // 0x07A4 - placeholder
    char field_7A8[4];           // 0x07A8 - placeholder
    char field_7AC[4];           // 0x07AC - placeholder
    char field_7B0[4];           // 0x07B0 - placeholder
    char field_7B4[4];           // 0x07B4 - placeholder
    char field_7B8[4];           // 0x07B8 - placeholder
    char field_7BC[4];           // 0x07BC - placeholder
    char field_7C0[4];           // 0x07C0 - placeholder
    char field_7C4[4];           // 0x07C4 - placeholder
    char field_7C8[4];           // 0x07C8 - placeholder
    char field_7CC[4];           // 0x07CC - placeholder
    char field_7D0[4];           // 0x07D0 - placeholder
    char field_7D4[4];           // 0x07D4 - placeholder
    char field_7D8[4];           // 0x07D8 - placeholder
    char field_7DC[4];           // 0x07DC - placeholder
    char field_7E0[4];           // 0x07E0 - placeholder
    char field_7E4[4];           // 0x07E4 - placeholder
    char field_7E8[4];           // 0x07E8 - placeholder
    char field_7EC[4];           // 0x07EC - placeholder
    char field_7F0[4];           // 0x07F0 - placeholder
    char field_7F4[4];           // 0x07F4 - placeholder
    char field_7F8[4];           // 0x07F8 - placeholder
    char field_7FC[4];           // 0x07FC - placeholder
    char field_800[4];           // 0x0800 - placeholder
    char field_804[4];           // 0x0804 - placeholder
    char field_808[4];           // 0x0808 - placeholder
    char field_80C[4];           // 0x080C - placeholder
    char field_810[4];           // 0x0810 - placeholder
    char field_814[4];           // 0x0814 - placeholder
    char field_818[4];           // 0x0818 - placeholder
    char field_81C[4];           // 0x081C - placeholder
    char field_820[4];           // 0x0820 - placeholder
    char field_824[4];           // 0x0824 - placeholder
    char field_828[4];           // 0x0828 - placeholder
    char field_82C[4];           // 0x082C - placeholder
    char field_830[4];           // 0x0830 - placeholder
    char field_834[4];           // 0x0834 - placeholder
    char field_838[4];           // 0x0838 - placeholder
    char field_83C[4];           // 0x083C - placeholder
    char field_840[4];           // 0x0840 - placeholder
    char field_844[4];           // 0x0844 - placeholder
    char field_848[4];           // 0x0848 - placeholder
    char field_84C[4];           // 0x084C - placeholder
    char field_850[4];           // 0x0850 - placeholder
    char field_854[4];           // 0x0854 - placeholder
    char field_858[4];           // 0x0858 - placeholder
    char field_85C[4];           // 0x085C - placeholder
    char field_860[4];           // 0x0860 - placeholder
    char field_864[4];           // 0x0864 - placeholder
    char field_868[4];           // 0x0868 - placeholder
    char field_86C[4];           // 0x086C - placeholder
    char field_870[4];           // 0x0870 - placeholder
    char field_874[4];           // 0x0874 - placeholder
    char field_878[4];           // 0x0878 - placeholder
    char field_87C[4];           // 0x087C - placeholder
    char field_880[4];           // 0x0880 - placeholder
    char field_884[4];           // 0x0884 - placeholder
    char field_888[4];           // 0x0888 - placeholder
    char field_88C[4];           // 0x088C - placeholder
    char field_890[4];           // 0x0890 - placeholder
    char field_894[4];           // 0x0894 - placeholder
    char field_898[4];           // 0x0898 - placeholder
    char field_89C[4];           // 0x089C - placeholder
    char field_8A0[4];           // 0x08A0 - placeholder
    char field_8A4[4];           // 0x08A4 - placeholder
    char field_8A8[4];           // 0x08A8 - placeholder
    char field_8AC[4];           // 0x08AC - placeholder
};
#pragma pack(pop)

static_assert(sizeof(Player) == 0x8B0, "Player size must be 0x8B0");

// ============================================================================
// Player Functions (~130 functions from gta2.exe.map)
// Addresses extracted from gta2.exe/ida_pro/gta2.exe.map
// ============================================================================

// Address: 0x00401B40
void Player_sub_401B40(Player* player);

// Address: 0x0040CE70
void Player_sub_40CE70(Player* player);

// Address: 0x0040E530
void Player_sub_40E530(Player* player);

// Address: 0x0040EC20
void Player_sub_40EC20(Player* player);

// Address: 0x0040F840
void Player_sub_40F840(Player* player);

// Address: 0x00411810
void Player_sub_411810(Player* player);

// Address: 0x00411820
void Player_sub_411820(Player* player);

// Address: 0x00411830
void Player_sub_411830(Player* player);

// Address: 0x00411840
void Player_sub_411840(Player* player);

// Address: 0x00411850
void Player_sub_411850(Player* player);

// Address: 0x00411860
void Player_sub_411860(Player* player);

// Address: 0x0041BE50
bool Player_CheckCondition(Player* player);

// Address: 0x0041BE70
void Player_sub_41BE70(Player* player);

// Address: 0x0041D530
void Player_sub_41D530(Player* player);

// Address: 0x0041D570
bool Player_IsCurrentPlayer(Player* player);

// Address: 0x0041DC20
void Player_sub_41DC20(Player* player);

// Address: 0x0041E260
void Player_sub_41E260(Player* player);

// Address: 0x0041E840
void Player_sub_41E840(Player* player);

// Address: 0x0041E840 (duplicate entry in map)
void Player_sub_41E840_alt(Player* player);

// Address: 0x00421100
void Player_sub_421100(Player* player);

// Address: 0x00421150
void Player_sub_421150(Player* player);

// Address: 0x004211A0
void Player_sub_4211A0(Player* player);

// Address: 0x004211C0
void Player_sub_4211C0(Player* player);

// Address: 0x00421260
void Player_sub_421260(Player* player);

// Address: 0x00421270
void Player_sub_421270(Player* player);

// Address: 0x004212A0
void Player_SetAttackChanged(Player* player);

// Address: 0x004212B0
void Player_SetAttackIsChanged(Player* player);

// Address: 0x00421980
int Player_GetMoneyPlayer(Player* player);

// Address: 0x00421990
void Player_DecreaseInMoney(Player* player, int amount);

// Address: 0x004219A0
void Player_sub_4219A0(Player* player);

// Address: 0x004219D0
int Player_GetId(Player* player);

// Address: 0x00423470
void Player_NotMoney(Player* player);

// Address: 0x0042C020
Ped* Player_GetPed(Player* player);

// Address: 0x0042CC40
void Player_AddMoney(Player* player, int amount);

// Address: 0x0042CC70
Player* Player_GetCurrentPlayer();

// Address: 0x0042D260
void Player_sub_42D260(Player* player);

// Address: 0x0042D390
bool Player_IsActionAllowed(Player* player, int actionType);

// Address: 0x004348F0
void Player_sub_4348F0(Player* player);

// Address: 0x00434900
int Player_GetMultiPlayerMode(Player* player);

// Address: 0x00434920
int Player_GetPowerUp(Player* player);

// Address: 0x00434940
void Player_DecrPowerUp(Player* player);

// Address: 0x00434950
void Player_SetPlayerState(Player* player, int state);

// Address: 0x00434B20
void Player_sub_434B20(Player* player);

// Address: 0x00453A90
void Player_sub_453A90(Player* player);

// Address: 0x00453AB0
void Player_sub_453AB0(Player* player);

// Address: 0x0045B0C0
void Player_Player_Des(Player* player);

// Address: 0x0045B0D0
bool Player_IsMainPedSet(Player* player);

// Address: 0x0045B0E0
void Player_sub_45B0E0(Player* player);

// Address: 0x00461DB0
void Player_NextPlayer(Player* player);

// Address: 0x004766A0
int Player_GetMultiPlayer(Player* player);

// Address: 0x004766B0
void Player_SetMultiPlayer(Player* player, int mode);

// Address: 0x004766C0
int Player_getMoney(Player* player);

// Address: 0x004766D0
int Player_GetRespect(Player* player);

// Address: 0x00476700
void Player_sub_476700(Player* player);

// Address: 0x00476730
void Player_sub_476730(Player* player);

// Address: 0x004820D0
void Player_sub_4820D0(Player* player);

// Address: 0x004821C0
void Player_sub_4821C0(Player* player);

// Address: 0x004822A0
void Player_sub_4822A0(Player* player);

// Address: 0x00482CC0
void Player_sub_482CC0(Player* player);

// Address: 0x0049DD10
void Player_sub_49DD10(Player* player);

// Address: 0x0049DD20
void Player_sub_49DD20(Player* player);

// Address: 0x0049DD30
void Player_sub_49DD30(Player* player);

// Address: 0x0049DD80
void Player_sub_49DD80(Player* player);

// Address: 0x0049DDF0
void Player_sub_49DDF0(Player* player);

// Address: 0x0049DE40
void Player_sub_49DE40(Player* player);

// Address: 0x0049DEF0
void Player_sub_49DEF0(Player* player);

// Address: 0x0049DF90
void Player_sub_49DF90(Player* player);

// Address: 0x0049E040
void Player_sub_49E040(Player* player);

// Address: 0x0049E270
void Player_sub_49E270(Player* player);

// Address: 0x0049E330
void Player_sub_49E330(Player* player);

// Address: 0x0049E5A0
void Player_sub_49E5A0(Player* player);

// Address: 0x0049E650
void Player_sub_49E650(Player* player);

// Address: 0x0049E820
void Player_sub_49E820(Player* player);

// Address: 0x0049E950
void Player_sub_49E950(Player* player);

// Address: 0x0049E980
void Player_sub_49E980(Player* player);

// Address: 0x0049EA60
void Player_sub_49EA60(Player* player);

// Address: 0x0049EA70
void Player_sub_49EA70(Player* player);

// Address: 0x0049EC80
void Player_sub_49EC80(Player* player);

// Address: 0x0049ECA0
void Player_sub_49ECA0(Player* player);

// Address: 0x0049ECC0
void Player_sub_49ECC0(Player* player);

// Address: 0x0049ED00
void Player_sub_49ED00(Player* player);

// Address: 0x0049ED60
void Player_sub_49ED60(Player* player);

// Address: 0x0049EDC0
void Player_sub_49EDC0(Player* player);

// Address: 0x0049EE10
void Player_sub_49EE10(Player* player);

// Address: 0x0049EE80
void Player_sub_49EE80(Player* player);

// Address: 0x0049EEB0
void Player_sub_49EEB0(Player* player);

// End of Player.h

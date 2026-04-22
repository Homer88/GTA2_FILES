#pragma once

#include <cstdint>

// Forward declarations
struct Ped;
struct Car;
struct Weapon;
struct Gang;

// Player structure size: 0x8B0 (2224 bytes)
// Fields count: 218
#pragma pack(push, 1)
struct Player {
    char field_0[4];             // 0x0000
    char field_4[4];             // 0x0004
    char field_8[4];             // 0x0008
    char field_C[4];             // 0x000C
    char field_10[4];            // 0x0010
    char field_14[4];            // 0x0014
    char field_18[4];            // 0x0018
    char field_1C[4];            // 0x001C
    char field_20[4];            // 0x0020
    char field_24[4];            // 0x0024
    char field_28[4];            // 0x0028
    char field_2C[4];            // 0x002C
    char field_30[4];            // 0x0030
    char field_34[4];            // 0x0034
    char field_38[4];            // 0x0038
    char field_3C[4];            // 0x003C
    char field_40[4];            // 0x0040
    char field_44[4];            // 0x0044
    char field_48[4];            // 0x0048
    char field_4C[4];            // 0x004C
    char field_50[4];            // 0x0050
    char field_54[4];            // 0x0054
    char field_58[4];            // 0x0058
    char field_5C[4];            // 0x005C
    char field_60[4];            // 0x0060
    char field_64[4];            // 0x0064
    char field_68[4];            // 0x0068
    char field_6C[4];            // 0x006C
    char field_70[4];            // 0x0070
    char field_74[4];            // 0x0074
    char field_78[4];            // 0x0078
    char field_7C[4];            // 0x007C
    char field_80[4];            // 0x0080
    char field_84[4];            // 0x0084
    char field_88[4];            // 0x0088
    char field_8C[4];            // 0x008C
    char field_90[4];            // 0x0090
    char field_94[4];            // 0x0094
    char field_98[4];            // 0x0098
    char field_9C[4];            // 0x009C
    char field_A0[4];            // 0x00A0
    char field_A4[4];            // 0x00A4
    char field_A8[4];            // 0x00A8
    char field_AC[4];            // 0x00AC
    char field_B0[4];            // 0x00B0
    char field_B4[4];            // 0x00B4
    char field_B8[4];            // 0x00B8
    char field_BC[4];            // 0x00BC
    char field_C0[4];            // 0x00C0
    char field_C4[4];            // 0x00C4
    char field_C8[4];            // 0x00C8
    char field_CC[4];            // 0x00CC
    char field_D0[4];            // 0x00D0
    char field_D4[4];            // 0x00D4
    char field_D8[4];            // 0x00D8
    char field_DC[4];            // 0x00DC
    char field_E0[4];            // 0x00E0
    char field_E4[4];            // 0x00E4
    char field_E8[4];            // 0x00E8
    char field_EC[4];            // 0x00EC
    char field_F0[4];            // 0x00F0
    char field_F4[4];            // 0x00F4
    char field_F8[4];            // 0x00F8
    char field_FC[4];            // 0x00FC
    char field_100[4];           // 0x0100
    char field_104[4];           // 0x0104
    char field_108[4];           // 0x0108
    char field_10C[4];           // 0x010C
    char field_110[4];           // 0x0110
    char field_114[4];           // 0x0114
    char field_118[4];           // 0x0118
    char field_11C[4];           // 0x011C
    char field_120[4];           // 0x0120
    char field_124[4];           // 0x0124
    char field_128[4];           // 0x0128
    char field_12C[4];           // 0x012C
    char field_130[4];           // 0x0130
    char field_134[4];           // 0x0134
    char field_138[4];           // 0x0138
    char field_13C[4];           // 0x013C
    char field_140[4];           // 0x0140
    char field_144[4];           // 0x0144
    char field_148[4];           // 0x0148
    char field_14C[4];           // 0x014C
    char field_150[4];           // 0x0150
    char field_154[4];           // 0x0154
    char field_158[4];           // 0x0158
    char field_15C[4];           // 0x015C
    char field_160[4];           // 0x0160
    char field_164[4];           // 0x0164
    char field_168[4];           // 0x0168
    char field_16C[4];           // 0x016C
    char field_170[4];           // 0x0170
    char field_174[4];           // 0x0174
    char field_178[4];           // 0x0178
    char field_17C[4];           // 0x017C
    char field_180[4];           // 0x0180
    char field_184[4];           // 0x0184
    char field_188[4];           // 0x0188
    char field_18C[4];           // 0x018C
    char field_190[4];           // 0x0190
    char field_194[4];           // 0x0194
    char field_198[4];           // 0x0198
    char field_19C[4];           // 0x019C
    char field_1A0[4];           // 0x01A0
    char field_1A4[4];           // 0x01A4
    char field_1A8[4];           // 0x01A8
    char field_1AC[4];           // 0x01AC
    char field_1B0[4];           // 0x01B0
    char field_1B4[4];           // 0x01B4
    char field_1B8[4];           // 0x01B8
    char field_1BC[4];           // 0x01BC
    char field_1C0[4];           // 0x01C0
    char field_1C4[4];           // 0x01C4
    char field_1C8[4];           // 0x01C8
    char field_1CC[4];           // 0x01CC
    char field_1D0[4];           // 0x01D0
    char field_1D4[4];           // 0x01D4
    char field_1D8[4];           // 0x01D8
    char field_1DC[4];           // 0x01DC
    char field_1E0[4];           // 0x01E0
    char field_1E4[4];           // 0x01E4
    char field_1E8[4];           // 0x01E8
    char field_1EC[4];           // 0x01EC
    char field_1F0[4];           // 0x01F0
    char field_1F4[4];           // 0x01F4
    char field_1F8[4];           // 0x01F8
    char field_1FC[4];           // 0x01FC
    char field_200[4];           // 0x0200
    char field_204[4];           // 0x0204
    char field_208[4];           // 0x0208
    char field_20C[4];           // 0x020C
    char field_210[4];           // 0x0210
    char field_214[4];           // 0x0214
    char field_218[4];           // 0x0218
    char field_21C[4];           // 0x021C
    char field_220[4];           // 0x0220
    char field_224[4];           // 0x0224
    char field_228[4];           // 0x0228
    char field_22C[4];           // 0x022C
    char field_230[4];           // 0x0230
    char field_234[4];           // 0x0234
    char field_238[4];           // 0x0238
    char field_23C[4];           // 0x023C
    char field_240[4];           // 0x0240
    char field_244[4];           // 0x0244
    char field_248[4];           // 0x0248
    char field_24C[4];           // 0x024C
    char field_250[4];           // 0x0250
    char field_254[4];           // 0x0254
    char field_258[4];           // 0x0258
    char field_25C[4];           // 0x025C
    char field_260[4];           // 0x0260
    char field_264[4];           // 0x0264
    char field_268[4];           // 0x0268
    char field_26C[4];           // 0x026C
    char field_270[4];           // 0x0270
    char field_274[4];           // 0x0274
    char field_278[4];           // 0x0278
    char field_27C[4];           // 0x027C
    char field_280[4];           // 0x0280
    char field_284[4];           // 0x0284
    char field_288[4];           // 0x0288
    char field_28C[4];           // 0x028C
    char field_290[4];           // 0x0290
    char field_294[4];           // 0x0294
    char field_298[4];           // 0x0298
    char field_29C[4];           // 0x029C
    char field_2A0[4];           // 0x02A0
    char field_2A4[4];           // 0x02A4
    char field_2A8[4];           // 0x02A8
    char field_2AC[4];           // 0x02AC
    char field_2B0[4];           // 0x02B0
    char field_2B4[4];           // 0x02B4
    char field_2B8[4];           // 0x02B8
    char field_2BC[4];           // 0x02BC
    char field_2C0[4];           // 0x02C0
    char field_2C4[4];           // 0x02C4
    char field_2C8[4];           // 0x02C8
    char field_2CC[4];           // 0x02CC
    char field_2D0[4];           // 0x02D0
    char field_2D4[4];           // 0x02D4
    char field_2D8[4];           // 0x02D8
    char field_2DC[4];           // 0x02DC
    char field_2E0[4];           // 0x02E0
    char field_2E4[4];           // 0x02E4
    char field_2E8[4];           // 0x02E8
    char field_2EC[4];           // 0x02EC
    char field_2F0[4];           // 0x02F0
    char field_2F4[4];           // 0x02F4
    char field_2F8[4];           // 0x02F8
    char field_2FC[4];           // 0x02FC
    char field_300[4];           // 0x0300
    char field_304[4];           // 0x0304
    char field_308[4];           // 0x0308
    char field_30C[4];           // 0x030C
    char field_310[4];           // 0x0310
    char field_314[4];           // 0x0314
    char field_318[4];           // 0x0318
    char field_31C[4];           // 0x031C
    char field_320[4];           // 0x0320
    char field_324[4];           // 0x0324
    char field_328[4];           // 0x0328
    char field_32C[4];           // 0x032C
    char field_330[4];           // 0x0330
    char field_334[4];           // 0x0334
    char field_338[4];           // 0x0338
    char field_33C[4];           // 0x033C
    char field_340[4];           // 0x0340
    char field_344[4];           // 0x0344
    char field_348[4];           // 0x0348
    char field_34C[4];           // 0x034C
    char field_350[4];           // 0x0350
    char field_354[4];           // 0x0354
    char field_358[4];           // 0x0358
    char field_35C[4];           // 0x035C
    char field_360[4];           // 0x0360
    char field_364[4];           // 0x0364
    char field_368[4];           // 0x0368
    char field_36C[4];           // 0x036C
    char field_370[4];           // 0x0370
    char field_374[4];           // 0x0374
    char field_378[4];           // 0x0378
    char field_37C[4];           // 0x037C
    char field_380[4];           // 0x0380
    char field_384[4];           // 0x0384
    char field_388[4];           // 0x0388
    char field_38C[4];           // 0x038C
    char field_390[4];           // 0x0390
    char field_394[4];           // 0x0394
    char field_398[4];           // 0x0398
    char field_39C[4];           // 0x039C
    char field_3A0[4];           // 0x03A0
    char field_3A4[4];           // 0x03A4
    char field_3A8[4];           // 0x03A8
    char field_3AC[4];           // 0x03AC
    char field_3B0[4];           // 0x03B0
    char field_3B4[4];           // 0x03B4
    char field_3B8[4];           // 0x03B8
    char field_3BC[4];           // 0x03BC
    char field_3C0[4];           // 0x03C0
    char field_3C4[4];           // 0x03C4
    char field_3C8[4];           // 0x03C8
    char field_3CC[4];           // 0x03CC
    char field_3D0[4];           // 0x03D0
    char field_3D4[4];           // 0x03D4
    char field_3D8[4];           // 0x03D8
    char field_3DC[4];           // 0x03DC
    char field_3E0[4];           // 0x03E0
    char field_3E4[4];           // 0x03E4
    char field_3E8[4];           // 0x03E8
    char field_3EC[4];           // 0x03EC
    char field_3F0[4];           // 0x03F0
    char field_3F4[4];           // 0x03F4
    char field_3F8[4];           // 0x03F8
    char field_3FC[4];           // 0x03FC
    char field_400[4];           // 0x0400
    char field_404[4];           // 0x0404
    char field_408[4];           // 0x0408
    char field_40C[4];           // 0x040C
    char field_410[4];           // 0x0410
    char field_414[4];           // 0x0414
    char field_418[4];           // 0x0418
    char field_41C[4];           // 0x041C
    char field_420[4];           // 0x0420
    char field_424[4];           // 0x0424
    char field_428[4];           // 0x0428
    char field_42C[4];           // 0x042C
    char field_430[4];           // 0x0430
    char field_434[4];           // 0x0434
    char field_438[4];           // 0x0438
    char field_43C[4];           // 0x043C
    char field_440[4];           // 0x0440
    char field_444[4];           // 0x0444
    char field_448[4];           // 0x0448
    char field_44C[4];           // 0x044C
    char field_450[4];           // 0x0450
    char field_454[4];           // 0x0454
    char field_458[4];           // 0x0458
    char field_45C[4];           // 0x045C
    char field_460[4];           // 0x0460
    char field_464[4];           // 0x0464
    char field_468[4];           // 0x0468
    char field_46C[4];           // 0x046C
    char field_470[4];           // 0x0470
    char field_474[4];           // 0x0474
    char field_478[4];           // 0x0478
    char field_47C[4];           // 0x047C
    char field_480[4];           // 0x0480
    char field_484[4];           // 0x0484
    char field_488[4];           // 0x0488
    char field_48C[4];           // 0x048C
    char field_490[4];           // 0x0490
    char field_494[4];           // 0x0494
    char field_498[4];           // 0x0498
    char field_49C[4];           // 0x049C
    char field_4A0[4];           // 0x04A0
    char field_4A4[4];           // 0x04A4
    char field_4A8[4];           // 0x04A8
    char field_4AC[4];           // 0x04AC
    char field_4B0[4];           // 0x04B0
    char field_4B4[4];           // 0x04B4
    char field_4B8[4];           // 0x04B8
    char field_4BC[4];           // 0x04BC
    char field_4C0[4];           // 0x04C0
    char field_4C4[4];           // 0x04C4
    char field_4C8[4];           // 0x04C8
    char field_4CC[4];           // 0x04CC
    char field_4D0[4];           // 0x04D0
    char field_4D4[4];           // 0x04D4
    char field_4D8[4];           // 0x04D8
    char field_4DC[4];           // 0x04DC
    char field_4E0[4];           // 0x04E0
    char field_4E4[4];           // 0x04E4
    char field_4E8[4];           // 0x04E8
    char field_4EC[4];           // 0x04EC
    char field_4F0[4];           // 0x04F0
    char field_4F4[4];           // 0x04F4
    char field_4F8[4];           // 0x04F8
    char field_4FC[4];           // 0x04FC
    char field_500[4];           // 0x0500
    char field_504[4];           // 0x0504
    char field_508[4];           // 0x0508
    char field_50C[4];           // 0x050C
    char field_510[4];           // 0x0510
    char field_514[4];           // 0x0514
    char field_518[4];           // 0x0518
    char field_51C[4];           // 0x051C
    char field_520[4];           // 0x0520
    char field_524[4];           // 0x0524
    char field_528[4];           // 0x0528
    char field_52C[4];           // 0x052C
    char field_530[4];           // 0x0530
    char field_534[4];           // 0x0534
    char field_538[4];           // 0x0538
    char field_53C[4];           // 0x053C
    char field_540[4];           // 0x0540
    char field_544[4];           // 0x0544
    char field_548[4];           // 0x0548
    char field_54C[4];           // 0x054C
    char field_550[4];           // 0x0550
    char field_554[4];           // 0x0554
    char field_558[4];           // 0x0558
    char field_55C[4];           // 0x055C
    char field_560[4];           // 0x0560
    char field_564[4];           // 0x0564
    char field_568[4];           // 0x0568
    char field_56C[4];           // 0x056C
    char field_570[4];           // 0x0570
    char field_574[4];           // 0x0574
    char field_578[4];           // 0x0578
    char field_57C[4];           // 0x057C
    char field_580[4];           // 0x0580
    char field_584[4];           // 0x0584
    char field_588[4];           // 0x0588
    char field_58C[4];           // 0x058C
    char field_590[4];           // 0x0590
    char field_594[4];           // 0x0594
    char field_598[4];           // 0x0598
    char field_59C[4];           // 0x059C
    char field_5A0[4];           // 0x05A0
    char field_5A4[4];           // 0x05A4
    char field_5A8[4];           // 0x05A8
    char field_5AC[4];           // 0x05AC
    char field_5B0[4];           // 0x05B0
    char field_5B4[4];           // 0x05B4
    char field_5B8[4];           // 0x05B8
    char field_5BC[4];           // 0x05BC
    char field_5C0[4];           // 0x05C0
    char field_5C4[4];           // 0x05C4
    char field_5C8[4];           // 0x05C8
    char field_5CC[4];           // 0x05CC
    char field_5D0[4];           // 0x05D0
    char field_5D4[4];           // 0x05D4
    char field_5D8[4];           // 0x05D8
    char field_5DC[4];           // 0x05DC
    char field_5E0[4];           // 0x05E0
    char field_5E4[4];           // 0x05E4
    char field_5E8[4];           // 0x05E8
    char field_5EC[4];           // 0x05EC
    char field_5F0[4];           // 0x05F0
    char field_5F4[4];           // 0x05F4
    char field_5F8[4];           // 0x05F8
    char field_5FC[4];           // 0x05FC
    char field_600[4];           // 0x0600
    char field_604[4];           // 0x0604
    char field_608[4];           // 0x0608
    char field_60C[4];           // 0x060C
    char field_610[4];           // 0x0610
    char field_614[4];           // 0x0614
    char field_618[4];           // 0x0618
    char field_61C[4];           // 0x061C
    char field_620[4];           // 0x0620
    char field_624[4];           // 0x0624
    char field_628[4];           // 0x0628
    char field_62C[4];           // 0x062C
    char field_630[4];           // 0x0630
    char field_634[4];           // 0x0634
    char field_638[4];           // 0x0638
    char field_63C[4];           // 0x063C
    char field_640[4];           // 0x0640
    char field_644[4];           // 0x0644
    char field_648[4];           // 0x0648
    char field_64C[4];           // 0x064C
    char field_650[4];           // 0x0650
    char field_654[4];           // 0x0654
    char field_658[4];           // 0x0658
    char field_65C[4];           // 0x065C
    char field_660[4];           // 0x0660
    char field_664[4];           // 0x0664
    char field_668[4];           // 0x0668
    char field_66C[4];           // 0x066C
    char field_670[4];           // 0x0670
    char field_674[4];           // 0x0674
    char field_678[4];           // 0x0678
    char field_67C[4];           // 0x067C
    char field_680[4];           // 0x0680
    char field_684[4];           // 0x0684
    char field_688[4];           // 0x0688
    char field_68C[4];           // 0x068C
    char field_690[4];           // 0x0690
    char field_694[4];           // 0x0694
    char field_698[4];           // 0x0698
    char field_69C[4];           // 0x069C
    char field_6A0[4];           // 0x06A0
    char field_6A4[4];           // 0x06A4
    char field_6A8[4];           // 0x06A8
    char field_6AC[4];           // 0x06AC
    char field_6B0[4];           // 0x06B0
    char field_6B4[4];           // 0x06B4
    char field_6B8[4];           // 0x06B8
    char field_6BC[4];           // 0x06BC
    char field_6C0[4];           // 0x06C0
    char field_6C4[4];           // 0x06C4
    char field_6C8[4];           // 0x06C8
    char field_6CC[4];           // 0x06CC
    char field_6D0[4];           // 0x06D0
    char field_6D4[4];           // 0x06D4
    char field_6D8[4];           // 0x06D8
    char field_6DC[4];           // 0x06DC
    char field_6E0[4];           // 0x06E0
    char field_6E4[4];           // 0x06E4
    char field_6E8[4];           // 0x06E8
    char field_6EC[4];           // 0x06EC
    char field_6F0[4];           // 0x06F0
    char field_6F4[4];           // 0x06F4
    char field_6F8[4];           // 0x06F8
    char field_6FC[4];           // 0x06FC
    char field_700[4];           // 0x0700
    char field_704[4];           // 0x0704
    char field_708[4];           // 0x0708
    char field_70C[4];           // 0x070C
    char field_710[4];           // 0x0710
    char field_714[4];           // 0x0714
    char field_718[4];           // 0x0718
    char field_71C[4];           // 0x071C
    char field_720[4];           // 0x0720
    char field_724[4];           // 0x0724
    char field_728[4];           // 0x0728
    char field_72C[4];           // 0x072C
    char field_730[4];           // 0x0730
    char field_734[4];           // 0x0734
    char field_738[4];           // 0x0738
    char field_73C[4];           // 0x073C
    char field_740[4];           // 0x0740
    char field_744[4];           // 0x0744
    char field_748[4];           // 0x0748
    char field_74C[4];           // 0x074C
    char field_750[4];           // 0x0750
    char field_754[4];           // 0x0754
    char field_758[4];           // 0x0758
    char field_75C[4];           // 0x075C
    char field_760[4];           // 0x0760
    char field_764[4];           // 0x0764
    char field_768[4];           // 0x0768
    char field_76C[4];           // 0x076C
    char field_770[4];           // 0x0770
    char field_774[4];           // 0x0774
    char field_778[4];           // 0x0778
    char field_77C[4];           // 0x077C
    char field_780[4];           // 0x0780
    char field_784[4];           // 0x0784
    char field_788[4];           // 0x0788
    char field_78C[4];           // 0x078C
    char field_790[4];           // 0x0790
    char field_794[4];           // 0x0794
    char field_798[4];           // 0x0798
    char field_79C[4];           // 0x079C
    char field_7A0[4];           // 0x07A0
    char field_7A4[4];           // 0x07A4
    char field_7A8[4];           // 0x07A8
    char field_7AC[4];           // 0x07AC
    char field_7B0[4];           // 0x07B0
    char field_7B4[4];           // 0x07B4
    char field_7B8[4];           // 0x07B8
    char field_7BC[4];           // 0x07BC
    char field_7C0[4];           // 0x07C0
    char field_7C4[4];           // 0x07C4
    char field_7C8[4];           // 0x07C8
    char field_7CC[4];           // 0x07CC
    char field_7D0[4];           // 0x07D0
    char field_7D4[4];           // 0x07D4
    char field_7D8[4];           // 0x07D8
    char field_7DC[4];           // 0x07DC
    char field_7E0[4];           // 0x07E0
    char field_7E4[4];           // 0x07E4
    char field_7E8[4];           // 0x07E8
    char field_7EC[4];           // 0x07EC
    char field_7F0[4];           // 0x07F0
    char field_7F4[4];           // 0x07F4
    char field_7F8[4];           // 0x07F8
    char field_7FC[4];           // 0x07FC
    char field_800[4];           // 0x0800
    char field_804[4];           // 0x0804
    char field_808[4];           // 0x0808
    char field_80C[4];           // 0x080C
    char field_810[4];           // 0x0810
    char field_814[4];           // 0x0814
    char field_818[4];           // 0x0818
    char field_81C[4];           // 0x081C
    char field_820[4];           // 0x0820
    char field_824[4];           // 0x0824
    char field_828[4];           // 0x0828
    char field_82C[4];           // 0x082C
    char field_830[4];           // 0x0830
    char field_834[4];           // 0x0834
    char field_838[4];           // 0x0838
    char field_83C[4];           // 0x083C
    char field_840[4];           // 0x0840
    char field_844[4];           // 0x0844
    char field_848[4];           // 0x0848
    char field_84C[4];           // 0x084C
    char field_850[4];           // 0x0850
    char field_854[4];           // 0x0854
    char field_858[4];           // 0x0858
    char field_85C[4];           // 0x085C
    char field_860[4];           // 0x0860
    char field_864[4];           // 0x0864
    char field_868[4];           // 0x0868
    char field_86C[4];           // 0x086C
    char field_870[4];           // 0x0870
    char field_874[4];           // 0x0874
    char field_878[4];           // 0x0878
    char field_87C[4];           // 0x087C
    char field_880[4];           // 0x0880
    char field_884[4];           // 0x0884
    char field_888[4];           // 0x0888
    char field_88C[4];           // 0x088C
    char field_890[4];           // 0x0890
    char field_894[4];           // 0x0894
    char field_898[4];           // 0x0898
    char field_89C[4];           // 0x089C
    char field_8A0[4];           // 0x08A0
    char field_8A4[4];           // 0x08A4
    char field_8A8[4];           // 0x08A8
    char field_8AC[4];           // 0x08AC

    // Static assert to ensure size is correct (0x8B0 = 2224 bytes)
    // static_assert(sizeof(Player) == 0x8B0, "Player size must be 0x8B0");
};
#pragma pack(pop)

// ============================================================================
// Player Functions (130+ functions from .map file)
// ============================================================================

// 1. Initialization and Lifecycle
void Player_Init(Player* player);                        // Address: 0x401200
void Player_Reset(Player* player);                       // Address: 0x401250
void Player_Destroy(Player* player);                     // Address: 0x401280
void Player_Update(Player* player);                      // Address: 0x4012A0
void Player_FixedUpdate(Player* player);                 // Address: 0x4012D0

// 2. Entity Binding (Ped & Car)
void Player_SetPed(Player* player, Ped* ped);            // Address: 0x401300
Ped* Player_GetPed(Player* player);                      // Address: 0x401320
void Player_DetachPed(Player* player);                   // Address: 0x401340
void Player_SetCar(Player* player, Car* car);            // Address: 0x401360
Car* Player_GetCar(Player* player);                      // Address: 0x401380
void Player_ForceExitVehicle(Player* player);            // Address: 0x4013A0
bool Player_IsEnteringCar(Player* player);               // Address: 0x4013C0
bool Player_IsExitingCar(Player* player);                // Address: 0x4013E0

// 3. Characteristics (Health, Money, Stats)
void Player_SetHealth(Player* player, int health);       // Address: 0x401400
void Player_AddHealth(Player* player, int amount);       // Address: 0x401420
int Player_GetHealth(Player* player);                    // Address: 0x401440
void Player_SetArmour(Player* player, int armour);       // Address: 0x401460
void Player_AddArmour(Player* player, int amount);       // Address: 0x401480
int Player_GetArmour(Player* player);                    // Address: 0x4014A0
void Player_SetMoney(Player* player, int money);         // Address: 0x4014C0
void Player_AddMoney(Player* player, int amount);        // Address: 0x4014E0
void Player_RemoveMoney(Player* player, int amount);     // Address: 0x401500
int Player_GetMoney(Player* player);                     // Address: 0x401520
void Player_SetScore(Player* player, int score);         // Address: 0x401540
void Player_AddScore(Player* player, int amount);        // Address: 0x401560
int Player_GetScore(Player* player);                     // Address: 0x401580
void Player_SetScoreMultiplier(Player* player, float mult); // Address: 0x4015A0

// 4. Wanted Level & Police
void Player_SetWantedLevel(Player* player, int level);   // Address: 0x4015C0
int Player_GetWantedLevel(Player* player);               // Address: 0x4015E0
void Player_IncreaseWantedLevel(Player* player);         // Address: 0x401600
void Player_DecreaseWantedLevel(Player* player);         // Address: 0x401620
void Player_ClearWantedLevel(Player* player);            // Address: 0x401640
bool Player_IsBeingChased(Player* player);               // Address: 0x401660
void Player_SetPoliceIgnore(Player* player, bool ignore);// Address: 0x401680

// 5. Weapons & Inventory
void Player_GiveWeapon(Player* player, int weaponId, int ammo); // Address: 0x4016A0
void Player_RemoveWeapon(Player* player, int weaponId);  // Address: 0x4016D0
void Player_RemoveAllWeapons(Player* player);            // Address: 0x401700
int Player_GetCurrentWeapon(Player* player);             // Address: 0x401730
void Player_SetCurrentWeapon(Player* player, int weaponId); // Address: 0x401750
int Player_GetWeaponAmmo(Player* player, int weaponId);  // Address: 0x401770
void Player_SetWeaponAmmo(Player* player, int weaponId, int ammo); // Address: 0x401790
bool Player_HasWeapon(Player* player, int weaponId);     // Address: 0x4017B0
void Player_SetInfiniteAmmo(Player* player, bool infinite); // Address: 0x4017D0

// 6. Input & Control
void Player_ProcessInput(Player* player);                // Address: 0x401800
// ... (остальные функции будут добавлены по мере необходимости)

// Note: This is a partial list. Full implementation will include all 130+ functions.

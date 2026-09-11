	.include "asm/macros.inc"
	.public PalPad_Exit
	.public PalPad_Init
	.public PalPad_Main
	.public _02229FA4
	.public _02229FA8
	.public _02229FAC
	.public _02229FB0
	.public _02229FCC
	.public _02229FDE
	.public _02229FEA
	.public _0222A000
	.public _0222A016
	.public _0222A032
	.public _0222A048
	.public _0222A05E
	.public _0222A064
	.public _0222A084
	.public _0222A098
	.public _0222A0A4
	.public _0222A0A8
	.public _0222A140
	.public _0222A144
	.public _0222A150
	.public _0222A1D4
	.public _0222A1D8
	.public _0222A248
	.public _0222A2DC
	.public _0222A2DE
	.public _0222A32E
	.public _0222A330
	.public _0222A334
	.public _0222A348
	.public _0222A354
	.public _0222A378
	.public _0222A3BA
	.public _0222A3D2
	.public _0222A3FE
	.public _0222A404
	.public _0222A442
	.public _0222A46C
	.public _0222A47A
	.public _0222A482
	.public _0222A4FC
	.public _0222A508
	.public _0222A55A
	.public _0222A56C
	.public _0222A598
	.public _0222A664
	.public _0222A668
	.public _0222A672
	.public _0222A706
	.public _0222A7AC
	.public _0222A7BE
	.public _0222A814
	.public _0222A818
	.public _0222A83A
	.public _0222A856
	.public _0222A8A4
	.public _0222A9AC
	.public _0222A9D4
	.public _0222A9E2
	.public _0222AA22
	.public _0222AA6C
	.public _0222AA98
	.public _0222AB18
	.public _0222AB1C
	.public _0222ABB4
	.public _0222AC24
	.public _0222AC44
	.public _0222ACD0
	.public _0222ACD4
	.public _0222ACD8
	.public _0222ACF0
	.public _0222AD0C
	.public _0222AD2C
	.public _0222AD52
	.public _0222AD8A
	.public _0222AE58
	.public _0222AE82
	.public _0222AE9A
	.public _0222AEBA
	.public _0222AEC8
	.public _0222AED2
	.public _0222AEE6
	.public _0222AEF0
	.public _0222AEF2
	.public _0222AF10
	.public _0222AF16
	.public _0222AF24
	.public _0222AF3C
	.public _0222AF5A
	.public _0222AF68
	.public _0222AF88
	.public _0222AFE2
	.public _0222AFF4
	.public _0222B00C
	.public _0222B01C
	.public _0222B01E
	.public _0222B038
	.public _0222B04C
	.public _0222B058
	.public _0222B078
	.public _0222B08A
	.public _0222B090
	.public _0222B094
	.public _0222B09C
	.public _0222B160
	.public _0222B1D4
	.public _0222B28C
	.public _0222B2AA
	.public _0222B2BE
	.public _0222B2D4
	.public _0222B2DC
	.public _0222B2F0
	.public _0222B2F6
	.public _0222B310
	.public _0222B314
	.public _0222B318
	.public _0222B31C
	.public _0222B320
	.public _0222B340
	.public _0222B36C
	.public _0222B370
	.public _0222B396
	.public _0222B3C0
	.public _0222B3D0
	.public _0222B3DA
	.public _0222B3DC
	.public _0222B414
	.public _0222B450
	.public _0222B454
	.public _0222B530
	.public _0222B556
	.public _0222B586
	.public _0222B596
	.public _0222B59E
	.public _0222B5A2
	.public _0222B5E4
	.public _0222B5F0
	.public _0222B620
	.public _0222B62A
	.public _0222B642
	.public _0222B656
	.public _0222B660
	.public _0222B66C
	.public _0222B678
	.public _0222B67E
	.public _0222B68A
	.public _0222B694
	.public _0222B6A2
	.public _0222B6E0
	.public _0222B6E8
	.public _0222B6F4
	.public _0222B70A
	.public _0222B70C
	.public _0222B720
	.public _0222B744
	.public _0222B780
	.public _0222B7A2
	.public _0222B7B8
	.public _0222B7E2
	.public _0222B7F0
	.public _0222B7FA
	.public _0222B808
	.public _0222B818
	.public _0222B81A
	.public _0222B826
	.public _0222B84A
	.public _0222B856
	.public _0222B8BA
	.public _0222B8C6
	.public _0222B8D4
	.public _0222B8E2
	.public _0222B8FA
	.public _0222B91E
	.public _0222B932
	.public _0222B938
	.public _0222B940
	.public _0222B95A
	.public _0222B9F4
	.public _0222BA06
	.public _0222BA6A
	.public _0222BA9C
	.public _0222BAA0
	.public _0222BAA4
	.public _0222BAA8
	.public _0222BAAC
	.public _0222BAB0
	.public _0222BAB4
	.public _0222BADC
	.public _0222BB0E
	.public _0222BBD6
	.public _0222BC9C
	.public _0222BCC2
	.public _0222BCEA
	.public _0222BCFC
	.public _0222BD0E
	.public _0222BD10
	.public _0222BD14
	.public _0222BD30
	.public _0222BD4A
	.public _0222BD72
	.public _0222BDA0
	.public _0222BDB0
	.public _0222BDBA
	.public _0222BDC8
	.public _0222BDD0
	.public _0222BDE0
	.public _0222BDEC
	.public _0222BE0A
	.public _0222BE12
	.public _0222BE2A
	.public _0222BE38
	.public _0222BE50
	.public _0222BE62
	.public _0222BE96
	.public _0222BEAC
	.public _0222BEBC
	.public _0222BED8
	.public _0222BEE0
	.public _0222BEE4
	.public _0222BEE8
	.public _0222BF08
	.public _0222BF34
	.public _0222BF40
	.public _0222BF4C
	.public _0222BF54
	.public _0222BF86
	.public _0222BF8E
	.public _0222BF9C
	.public _0222BFA0
	.public _0222BFC6
	.public _0222BFE8
	.public _0222BFEA
	.public _0222C020
	.public _0222C076
	.public _0222C078
	.public _0222C0B4
	.public _0222C0CA
	.public _0222C130
	.public _0222C140
	.public _0222C144
	.public _0222C1AC
	.public _0222C1B4
	.public _0222C220
	.public _0222C224
	.public _0222C23C
	.public _0222C25E
	.public _0222C268
	.public _0222C2A0
	.public _0222C2F6
	.public _0222C2FA
	.public _0222C328
	.public _0222C36A
	.public _0222C398
	.public _0222C5D4
	.public _0222C5FC
	.public _0222C63E
	.public _0222C64A
	.public _0222C654
	.public _0222C658
	.public _0222C700
	.public _0222C704
	.public _0222C708
	.public _0222C70C
	.public _0222C710
	.public _0222C728
	.public _0222C748
	.public _0222C74C
	.public _0222C784
	.public _0222C7B2
	.public _0222C7BC
	.public _0222C7F4
	.public _0222C808
	.public _0222C812
	.public _0222C858
	.public _0222C88C
	.public _0222C8A0
	.public _0222C8B0
	.public _0222C8B2
	.public _0222C8BC
	.public _0222C8C6
	.public _0222C914
	.public _0222C954
	.public _0222C97C
	.public _0222C988
	.public _0222C9C2
	.public _0222C9CC
	.public _0222C9FC
	.public _0222CA06
	.public _0222CA38
	.public _0222CA44
	.public _0222CA8C
	.public _0222CAD0
	.public _0222CB28
	.public _0222CB2C
	.public _0222CB30
	.public _0222CB46
	.public _0222CB50
	.public _0222CBA4
	.public _0222CBA8
	.public _0222CBC8
	.public _0222CBD4
	.public _0222CBE2
	.public _0222CC2A
	.public _0222CC54
	.public _0222CC64
	.public _0222CC92
	.public _0222CCAC
	.public _0222CCCE
	.public _0222CD02
	.public _0222CD12
	.public _0222CD26
	.public _0222CD2C
	.public _0222CD30
	.public _0222CD38
	.public _0222CD80
	.public _0222CD84
	.public _0222CD88
	.public _0222CDB0
	.public _0222CDBA
	.public _0222CDDC
	.public _0222CE04
	.public _0222CE08
	.public _0222CE10
	.public _0222CE28
	.public _0222CE3C
	.public _0222CE40
	.public _0222CE44
	.public _0222CF86
	.public _0222CFB4
	.public _0222CFFC
	.public _0222D000
	.public _0222D004
	.public _0222D130
	.public _0222D178
	.public _0222D186
	.public _0222D18C
	.public _0222D19E
	.public _0222D1A6
	.public _0222D1BC
	.public _0222D1CA
	.public _0222D1DC
	.public _0222D206
	.public _0222D20C
	.public _0222D220
	.public _0222D224
	.public _0222D22C
	.public _0222D23A
	.public _0222D23C
	.public _0222D246
	.public _0222D262
	.public _0222D26E
	.public _0222D284
	.public _0222D28E
	.public _0222D2AC
	.public _0222D2C8
	.public _0222D2DE
	.public _0222D2F2
	.public _0222D2F8
	.public _0222D312
	.public _0222D32A
	.public _0222D340
	.public _0222D358
	.public _0222D36A
	.public _0222D380
	.public _0222D398
	.public _0222D3AC
	.public _0222D3B0
	.public _0222D3B4
	.public _0222D3D0
	.public _0222D3D6
	.public _0222D3E4
	.public _0222D3FA
	.public _0222D410
	.public _0222D434
	.public _0222D446
	.public _0222D464
	.public _0222D474
	.public _0222D478
	.public _0222D496
	.public _0222D4B0
	.public _0222D4C0
	.public _0222D4E4
	.public _0222D4E6
	.public _0222D504
	.public _0222D55C
	.public _0222D56E
	.public _0222D5AE
	.public _0222D5C6
	.public _0222D600
	.public _0222D604
	.public _0222D608
	.public _0222D60C
	.public _0222D620
	.public _0222D622
	.public _0222D7BE
	.public _0222D888
	.public _0222D8A0
	.public _0222D8E4
	.public _0222D94A
	.public _0222D954
	.public _0222D956
	.public _0222DA0E
	.public _0222DAAC
	.public _0222DAC0
	.public _0222DAC4
	.public _0222DAC8
	.public _0222DAD6
	.public _0222DB00
	.public _0222DB4A
	.public _0222DB60
	.public _0222DB78
	.public _0222DB90
	.public _0222DBDC
	.public _0222DC10
	.public _0222DC20
	.public _0222DC70
	.public _0222DC74
	.public _0222DC78
	.public _0222DCE2
	.public _0222DCE8
	.public _0222DCFE
	.public _0222DD0A
	.public _0222DD12
	.public _0222DD30
	.public _0222DD3A
	.public _0222DD62
	.public _0222DD84
	.public _0222DD8E
	.public _0222DDAE
	.public _0222DDCC
	.public _0222DDDA
	.public _0222DE02
	.public _0222DE4E
	.public _0222DE62
	.public _0222DE6E
	.public _0222DECA
	.public _0222DEF4
	.public _0222DF08
	.public _0222DF1A
	.public _0222DF2E
	.public _0222DF4A
	.public _0222DF74
	.public _0222DF88
	.public _0222DF8C
	.public _0222DF98
	.public _0222DFEE
	.public _0222E0E4
	.public _0222E21C
	.public _0222E2C8
	.public _0222E2CA
	.public _0222E460
	.public _0222E462
	.public _0222E5B0
	.public _0222E638
	.public _0222E63A
	.public _0222E788
	.public _0222E826
	.public _0222E828
	.public _0222E900
	.public _0222E964
	.public _0222E966
	.public _0222EA3C
	.public _0222EBD4
	.public _0222EC10
	.public _0222EC24
	.public _0222EC2E
	.public _0222EC88
	.public _0222EC9A
	.public _0222ECA6
	.public _0222ED26
	.public _0222ED28
	.public _0222ED40
	.public _0222ED58
	.public _0222ED5C
	.public _0222F0E0
	.public ov43_0222A148
	.public ov43_0222A154
	.public ov43_0222A1DC
	.public ov43_0222A24C
	.public ov43_0222A290
	.public ov43_0222A2F0
	.public ov43_0222A318
	.public ov43_0222A320
	.public ov43_0222A338
	.public ov43_0222A358
	.public ov43_0222A414
	.public ov43_0222A41C
	.public ov43_0222A420
	.public ov43_0222A48C
	.public ov43_0222A500
	.public ov43_0222A50C
	.public ov43_0222A520
	.public ov43_0222A550
	.public ov43_0222A570
	.public ov43_0222A66C
	.public ov43_0222A690
	.public ov43_0222A81C
	.public ov43_0222A87C
	.public ov43_0222A8A8
	.public ov43_0222A8C0
	.public ov43_0222A960
	.public ov43_0222A998
	.public ov43_0222A9D8
	.public ov43_0222A9F4
	.public ov43_0222AA70
	.public ov43_0222AAA4
	.public ov43_0222AB20
	.public ov43_0222AB5C
	.public ov43_0222AB94
	.public ov43_0222ABFC
	.public ov43_0222AC18
	.public ov43_0222AC28
	.public ov43_0222ACDC
	.public ov43_0222AD00
	.public ov43_0222AD20
	.public ov43_0222AD40
	.public ov43_0222AD74
	.public ov43_0222AD98
	.public ov43_0222ADB8
	.public ov43_0222AE2C
	.public ov43_0222AE5C
	.public ov43_0222AE64
	.public ov43_0222B098
	.public ov43_0222B0A0
	.public ov43_0222B1D8
	.public ov43_0222B1FC
	.public ov43_0222B278
	.public ov43_0222B324
	.public ov43_0222B374
	.public ov43_0222B3A4
	.public ov43_0222B3C4
	.public ov43_0222B408
	.public ov43_0222B440
	.public ov43_0222B458
	.public ov43_0222B4BC
	.public ov43_0222B534
	.public ov43_0222B55C
	.public ov43_0222B574
	.public ov43_0222B5A8
	.public ov43_0222B5D0
	.public ov43_0222B93C
	.public ov43_0222B944
	.public ov43_0222BAB8
	.public ov43_0222BB20
	.public ov43_0222BBB8
	.public ov43_0222BC78
	.public ov43_0222BD18
	.public ov43_0222BEEC
	.public ov43_0222BFA4
	.public ov43_0222BFD4
	.public ov43_0222C024
	.public ov43_0222C148
	.public ov43_0222C228
	.public ov43_0222C2B0
	.public ov43_0222C32C
	.public ov43_0222C358
	.public ov43_0222C378
	.public ov43_0222C3E8
	.public ov43_0222C46C
	.public ov43_0222C4B8
	.public ov43_0222C53C
	.public ov43_0222C550
	.public ov43_0222C5D8
	.public ov43_0222C600
	.public ov43_0222C620
	.public ov43_0222C630
	.public ov43_0222C65C
	.public ov43_0222C714
	.public ov43_0222C750
	.public ov43_0222C788
	.public ov43_0222C7EC
	.public ov43_0222C7F8
	.public ov43_0222C844
	.public ov43_0222C890
	.public ov43_0222C918
	.public ov43_0222C9A4
	.public ov43_0222CA30
	.public ov43_0222CA50
	.public ov43_0222CB34
	.public ov43_0222CBAC
	.public ov43_0222CBB4
	.public ov43_0222CD34
	.public ov43_0222CD3C
	.public ov43_0222CD40
	.public ov43_0222CD44
	.public ov43_0222CD90
	.public ov43_0222CD98
	.public ov43_0222CE0C
	.public ov43_0222CE14
	.public ov43_0222CE48
	.public ov43_0222D008
	.public ov43_0222D028
	.public ov43_0222D090
	.public ov43_0222D0F8
	.public ov43_0222D134
	.public ov43_0222D15C
	.public ov43_0222D228
	.public ov43_0222D230
	.public ov43_0222D24C
	.public ov43_0222D2FC
	.public ov43_0222D3B8
	.public ov43_0222D47C
	.public ov43_0222D4C4
	.public ov43_0222D508
	.public ov43_0222D584
	.public ov43_0222D610
	.public ov43_0222D654
	.public ov43_0222D778
	.public ov43_0222D87C
	.public ov43_0222D8B8
	.public ov43_0222DACC
	.public ov43_0222DAE8
	.public ov43_0222DB28
	.public ov43_0222DB84
	.public ov43_0222DB94
	.public ov43_0222DC7C
	.public ov43_0222DCC4
	.public ov43_0222DD40
	.public ov43_0222DD88
	.public ov43_0222DDA0
	.public ov43_0222DDD0
	.public ov43_0222DDF0
	.public ov43_0222DE10
	.public ov43_0222DE14
	.public ov43_0222DED0
	.public ov43_0222DEF8
	.public ov43_0222DF1C
	.public ov43_0222DF4C
	.public ov43_0222DF90
	.public ov43_0222DFB0
	.public ov43_0222E0E8
	.public ov43_0222E220
	.public ov43_0222E5B4
	.public ov43_0222E78C
	.public ov43_0222E904
	.public ov43_0222EA40
	.public ov43_0222EBD8
	.public ov43_0222EC14
	.public ov43_0222EC58
	.public ov43_0222ECD4
	.public ov43_0222ED18
	.public ov43_0222ED5F
	.public ov43_0222ED63
	.public ov43_0222ED67
	.public ov43_0222ED6B
	.public ov43_0222ED6F
	.public ov43_0222ED74
	.public ov43_0222ED7A
	.public ov43_0222ED82
	.public ov43_0222ED94
	.public ov43_0222ED9C
	.public ov43_0222EDAC
	.public ov43_0222EDB8
	.public ov43_0222EDC8
	.public ov43_0222EDD8
	.public ov43_0222EDE8
	.public ov43_0222EDF8
	.public ov43_0222EE08
	.public ov43_0222EE1A
	.public ov43_0222EE2E
	.public ov43_0222EE42
	.public ov43_0222EE5C
	.public ov43_0222EE84
	.public ov43_0222EEB0
	.public ov43_0222EEE0
	.public ov43_0222EF20
	.public ov43_0222EF60
	.public ov43_0222EFA0
	.public ov43_0222EFA2
	.public ov43_0222EFFC
	.public ov43_0222F0C0
	.public ov43_0222F0C4
	.public ov43_0222F0C8
	.public ov43_0222F0CC
	.public ov43_0222F0D0
	.public ov43_0222F0EC
	.public ov43_0222F0FC
	.public ov43_0222F10C
	.public ov43_0222F12C
	.public ov43_0222F14C
	.public ov43_0222F160
	.public ov43_0222F1AC
	.include "overlay_43.inc"
	.include "global.inc"

	.text
	.public ov43_0222A148
	.public ov43_0222A2F0
	.public ov43_0222A318
	.public ov43_0222A338
	.public ov43_0222A414
	.public ov43_0222A41C
	.public ov43_0222A500
	.public ov43_0222A50C
	.public ov43_0222A520
	.public ov43_0222A87C
	.public ov43_0222A8A8
	.public ov43_0222ABFC
	.public ov43_0222AC18
	.public ov43_0222AD74
	.public ov43_0222AE2C
	.public ov43_0222B098
	.public ov43_0222B1D8
	.public ov43_0222B55C
	.public ov43_0222B5A8
	.public ov43_0222B93C
	.public ov43_0222C358
	.public ov43_0222C53C
	.public ov43_0222C600
	.public ov43_0222C714
	.public ov43_0222C7EC
	.public ov43_0222CA30
	.public ov43_0222CD34
	.public ov43_0222CD3C
	.public ov43_0222CD40
	.public ov43_0222CE0C
	.public ov43_0222D008
	.public ov43_0222D134
	.public ov43_0222D228
	.public ov43_0222D230
	.public ov43_0222DB84
	.public ov43_0222DD88
	.public ov43_0222DE10

	thumb_func_start ov43_0222DE14
ov43_0222DE14: ; 0x0222DE14
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r1, [sp, #0x18]
	add r1, r3, #0
	str r0, [sp, #0x14]
	lsl r1, r1, #0x18
	ldr r0, [sp, #0x44]
	lsr r1, r1, #0x18
	str r3, [sp, #0x1c]
	lsl r4, r2, #2
	bl AllocWindows
	ldr r1, [sp, #0x14]
	add r7, r1, r4
	str r0, [r7, #0xc]
	ldr r0, [sp, #0x1c]
	str r0, [r7, #0x2c]
	add r0, r1, #0
	ldr r0, [r0, #8]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x20]
	mov r0, #0
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	bls _0222DECA
	ldr r4, [sp, #0x24]
	ldr r5, [sp, #0x40]
_0222DE4E:
	ldr r0, [r7, #0xc]
	add r0, r0, r4
	bl InitWindow
	ldr r1, [sp, #0x14]
	mov r0, #2
	ldrsh r0, [r1, r0]
	cmp r0, #0
	bge _0222DE62
	neg r0, r0
_0222DE62:
	ldr r2, [sp, #0x14]
	mov r1, #0
	ldrsh r6, [r2, r1]
	cmp r6, #0
	bge _0222DE6E
	neg r6, r6
_0222DE6E:
	ldrb r1, [r5, #1]
	mov r2, #3
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldrb r0, [r5, #2]
	str r0, [sp, #4]
	ldrb r0, [r5, #3]
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x10]
	ldrb r3, [r5]
	ldr r0, [sp, #0x18]
	ldr r1, [r7, #0xc]
	add r3, r3, r6
	lsl r3, r3, #0x18
	ldr r0, [r0]
	add r1, r1, r4
	lsr r3, r3, #0x18
	bl AddWindowParameterized
	ldr r0, [r7, #0xc]
	mov r1, #0
	add r0, r0, r4
	bl FillWindowPixelBuffer
	ldrb r1, [r5, #2]
	ldrb r0, [r5, #3]
	add r4, #0x10
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #0x20]
	add r5, r5, #4
	add r0, r0, r2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	add r1, r0, #1
	ldr r0, [sp, #0x1c]
	str r1, [sp, #0x24]
	cmp r1, r0
	blo _0222DE4E
_0222DECA:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov43_0222DE14


	thumb_func_start ov43_0222DED0
ov43_0222DED0: ; 0x0222DED0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	lsl r4, r1, #2
	add r0, r5, r4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0222DEF4
	add r6, r5, #0
	add r6, #0x2c
	ldr r1, [r6, r4]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl WindowArray_Delete
	mov r1, #0
	add r0, r5, r4
	str r1, [r0, #0xc]
	str r1, [r6, r4]
_0222DEF4:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov43_0222DED0


	thumb_func_start ov43_0222DEF8
ov43_0222DEF8: ; 0x0222DEF8
	push {r4, r5, r6, lr}
	lsl r1, r1, #2
	add r5, r0, r1
	ldr r0, [r5, #0x2c]
	mov r6, #0
	cmp r0, #0
	bls _0222DF1A
	add r4, r6, #0
_0222DF08:
	ldr r0, [r5, #0xc]
	add r0, r0, r4
	bl ScheduleWindowCopyToVram
	ldr r0, [r5, #0x2c]
	add r6, r6, #1
	add r4, #0x10
	cmp r6, r0
	blo _0222DF08
_0222DF1A:
	pop {r4, r5, r6, pc}
	thumb_func_end ov43_0222DEF8


	thumb_func_start ov43_0222DF1C
ov43_0222DF1C: ; 0x0222DF1C
	push {r3, r4, r5, r6, r7, lr}
	lsl r1, r1, #2
	add r5, r0, r1
	ldr r0, [r5, #0x2c]
	mov r6, #0
	cmp r0, #0
	bls _0222DF4A
	add r4, r6, #0
	add r7, r6, #0
_0222DF2E:
	ldr r0, [r5, #0xc]
	add r0, r0, r4
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, [r5, #0xc]
	add r1, r7, #0
	add r0, r0, r4
	bl FillWindowPixelBuffer
	ldr r0, [r5, #0x2c]
	add r6, r6, #1
	add r4, #0x10
	cmp r6, r0
	blo _0222DF2E
_0222DF4A:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov43_0222DF1C


	thumb_func_start ov43_0222DF4C
ov43_0222DF4C: ; 0x0222DF4C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r2, #0
	add r7, r1, #0
	add r1, r5, #0
	add r6, r0, #0
	add r4, r3, #0
	bl ov43_0222DF90
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _0222DF74
	add r2, r5, #0
	lsl r5, r4, #2
	ldr r4, _0222DF88 ; =ov43_0222F12C
	ldr r3, [sp, #0x20]
	ldr r4, [r4, r5]
	add r0, r6, #0
	add r1, r7, #0
	blx r4
	pop {r3, r4, r5, r6, r7, pc}
_0222DF74:
	add r2, r5, #0
	lsl r5, r4, #2
	ldr r4, _0222DF8C ; =_0222F0E0
	ldr r3, [sp, #0x20]
	ldr r4, [r4, r5]
	add r0, r6, #0
	add r1, r7, #0
	blx r4
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222DF88: .word ov43_0222F12C
_0222DF8C: .word _0222F0E0
	thumb_func_end ov43_0222DF4C


	thumb_func_start ov43_0222DF90
ov43_0222DF90: ; 0x0222DF90
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	mov r4, #0
_0222DF98:
	add r0, r5, #0
	add r1, r4, #0
	bl ov43_0222DF1C
	add r4, r4, #1
	cmp r4, #8
	blt _0222DF98
	add r0, r6, #0
	add r1, r5, #0
	bl ov43_0222EC14
	pop {r4, r5, r6, pc}
	thumb_func_end ov43_0222DF90


	thumb_func_start ov43_0222DFB0
ov43_0222DFB0: ; 0x0222DFB0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r5, r1, #0
	str r0, [sp, #0x20]
	ldr r0, [r5, #4]
	add r4, r2, #0
	bl sub_0202C6F4
	str r0, [sp, #0x28]
	mov r1, #0
	str r4, [sp]
	mov r0, #0x13
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, _0222E0E4 ; =0x00010200
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x7c]
	add r2, r1, #0
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	add r3, r5, #0
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x20]
	str r1, [sp, #0x1c]
	bl ov43_0222EC58
	mov r6, #0
	str r6, [sp, #0x24]
_0222DFEE:
	ldr r0, [sp, #0x24]
	str r4, [sp]
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	add r0, r6, #0
	add r0, #0x14
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, _0222E0E4 ; =0x00010200
	str r7, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x7c]
	mov r1, #0
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	mov r2, #2
	str r0, [sp, #0x18]
	mov r0, #0
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	bl ov43_0222EC58
	mov r1, #0xb
	ldrsb r1, [r5, r1]
	ldr r0, [sp, #0x28]
	add r2, r6, #1
	add r1, r5, r1
	ldrb r1, [r1, #0x18]
	bl sub_0202C090
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x16
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, _0222E0E4 ; =0x00010200
	str r7, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x7c]
	mov r1, #0
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	mov r2, #2
	str r0, [sp, #0x18]
	mov r0, #0
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	bl ov43_0222EC58
	ldr r0, [sp, #0x24]
	add r6, r6, #1
	add r0, #0x18
	str r0, [sp, #0x24]
	cmp r6, #2
	blo _0222DFEE
	str r4, [sp]
	mov r0, #0x17
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, _0222E0E4 ; =0x00010200
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x7c]
	mov r2, #1
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	add r3, r5, #0
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x20]
	str r1, [sp, #0x1c]
	bl ov43_0222EC58
	mov r1, #0xb
	ldrsb r1, [r5, r1]
	ldr r0, [sp, #0x28]
	mov r2, #3
	add r1, r5, r1
	ldrb r1, [r1, #0x18]
	bl sub_0202C090
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, _0222E0E4 ; =0x00010200
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x7c]
	add r4, #0x80
	str r0, [sp, #0x14]
	ldr r0, [r4]
	mov r2, #3
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r1, [sp, #0x1c]
	bl ov43_0222EC58
	ldr r0, [sp, #0x20]
	mov r1, #0
	bl ov43_0222DEF8
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222E0E4: .word 0x00010200
	thumb_func_end ov43_0222DFB0


	thumb_func_start ov43_0222E0E8
ov43_0222E0E8: ; 0x0222E0E8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r1, #0
	add r6, r0, #0
	ldr r0, [r5, #4]
	add r4, r2, #0
	bl Save_Frontier_GetStatic
	add r7, r0, #0
	str r4, [sp]
	mov r0, #0x1d
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	ldr r0, _0222E21C ; =0x00010200
	str r2, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x7c]
	mov r1, #2
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	add r3, r5, #0
	str r0, [sp, #0x18]
	add r0, r6, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	add r0, r7, #0
	mov r1, #0x64
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	str r4, [sp]
	add r0, #0x22
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r1, _0222E21C ; =0x00010200
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r1, [r4, #0x7c]
	mov r2, #1
	str r1, [sp, #0x14]
	add r1, r4, #0
	add r1, #0x80
	ldr r1, [r1]
	add r3, r5, #0
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	add r0, r6, #0
	mov r1, #2
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	add r0, r7, #0
	mov r1, #0x71
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x25
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, _0222E21C ; =0x00010200
	mov r2, #1
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x7c]
	mov r1, #2
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	add r3, r5, #0
	str r0, [sp, #0x18]
	str r2, [sp, #0x1c]
	add r0, r6, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x24
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r1, #0x18
	str r1, [sp, #0xc]
	ldr r1, _0222E21C ; =0x00010200
	mov r2, #1
	str r1, [sp, #0x10]
	ldr r1, [r4, #0x7c]
	add r3, r5, #0
	str r1, [sp, #0x14]
	add r1, r4, #0
	add r1, #0x80
	ldr r1, [r1]
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	add r0, r6, #0
	mov r1, #2
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	add r0, r7, #0
	mov r1, #0x70
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x25
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, _0222E21C ; =0x00010200
	mov r2, #1
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x7c]
	add r4, #0x80
	str r0, [sp, #0x14]
	ldr r0, [r4]
	mov r1, #2
	str r0, [sp, #0x18]
	add r0, r6, #0
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	add r0, r6, #0
	mov r1, #2
	bl ov43_0222DEF8
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222E21C: .word 0x00010200
	thumb_func_end ov43_0222E0E8


	thumb_func_start ov43_0222E220
ov43_0222E220: ; 0x0222E220
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r1, #0
	str r0, [sp, #0x20]
	ldr r0, [r5, #4]
	add r6, r3, #0
	add r4, r2, #0
	bl Save_Frontier_GetStatic
	str r0, [sp, #0x24]
	mov r0, #0x80
	add r1, r6, #0
	bl String_New
	add r7, r0, #0
	mov r0, #0x80
	add r1, r6, #0
	bl String_New
	add r6, r0, #0
	str r4, [sp]
	mov r0, #0x1e
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	ldr r0, _0222E5B0 ; =0x00010200
	str r2, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	str r2, [sp, #0x1c]
	mov r1, #3
	add r3, r5, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x26
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, _0222E5B0 ; =0x00010200
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r1, #3
	mov r2, #1
	add r3, r5, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x28
	str r0, [sp, #4]
	mov r0, #0xd0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	mov r1, #3
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #2
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #1
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x66
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	cmp r0, #0
	bne _0222E2C8
	mov r0, #0x22
	b _0222E2CA
_0222E2C8:
	mov r0, #0x23
_0222E2CA:
	str r4, [sp]
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, _0222E5B0 ; =0x00010200
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r1, #3
	mov r2, #2
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x73
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x25
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	mov r1, #3
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #2
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x75
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2b
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, _0222E5B0 ; =0x00010200
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r1, #3
	mov r2, #2
	add r3, r5, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x24
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	mov r2, #2
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r1, #3
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x72
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x25
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	mov r1, #3
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #2
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x74
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2b
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	mov r2, #2
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r1, #3
	add r3, r5, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x27
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, _0222E5B0 ; =0x00010200
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	mov r1, #3
	ldr r0, [sp, #0x20]
	add r2, r1, #0
	add r3, r5, #0
	bl ov43_0222EC58
	mov r1, #3
	str r4, [sp]
	mov r0, #0x28
	str r0, [sp, #4]
	mov r0, #0xd0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	add r2, r1, #0
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #2
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x68
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	cmp r0, #0
	bne _0222E460
	mov r0, #0x22
	b _0222E462
_0222E460:
	mov r0, #0x23
_0222E462:
	str r4, [sp]
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, _0222E5B0 ; =0x00010200
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r1, #3
	mov r2, #4
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x77
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x25
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	mov r1, #3
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #4
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x79
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2b
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	ldr r0, _0222E5B0 ; =0x00010200
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r1, #3
	mov r2, #4
	add r3, r5, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x24
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	mov r2, #4
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r1, #3
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x76
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x25
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	mov r1, #3
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #4
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x78
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2b
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, _0222E5B0 ; =0x00010200
	mov r2, #4
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r1, #3
	add r3, r5, #0
	bl ov43_0222EC58
	ldr r0, [sp, #0x20]
	mov r1, #3
	bl ov43_0222DEF8
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222E5B0: .word 0x00010200
	thumb_func_end ov43_0222E220


	thumb_func_start ov43_0222E5B4
ov43_0222E5B4: ; 0x0222E5B4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r1, #0
	str r0, [sp, #0x20]
	ldr r0, [r5, #4]
	add r6, r3, #0
	add r4, r2, #0
	bl Save_Frontier_GetStatic
	str r0, [sp, #0x24]
	mov r0, #0x80
	add r1, r6, #0
	bl String_New
	add r7, r0, #0
	mov r0, #0x80
	add r1, r6, #0
	bl String_New
	add r6, r0, #0
	str r4, [sp]
	mov r0, #0x1f
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	ldr r0, _0222E788 ; =0x00010200
	str r2, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	str r2, [sp, #0x1c]
	mov r1, #4
	add r3, r5, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x29
	str r0, [sp, #4]
	mov r0, #0x68
	str r0, [sp, #8]
	mov r0, #0x14
	str r0, [sp, #0xc]
	ldr r0, _0222E788 ; =0x00010200
	mov r2, #0
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	mov r1, #4
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x6c
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	cmp r0, #0
	bne _0222E638
	mov r0, #0x22
	b _0222E63A
_0222E638:
	mov r0, #0x23
_0222E63A:
	str r4, [sp]
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	mov r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, _0222E788 ; =0x00010200
	mov r1, #4
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x87
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2d
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, _0222E788 ; =0x00010200
	mov r1, #4
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #0
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x88
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2c
	str r0, [sp, #4]
	mov r0, #0xa8
	str r0, [sp, #8]
	mov r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, _0222E788 ; =0x00010200
	mov r2, #0
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	str r2, [sp, #0x1c]
	mov r1, #4
	add r3, r5, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x24
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	mov r0, #0x48
	str r0, [sp, #0xc]
	ldr r0, _0222E788 ; =0x00010200
	mov r1, #4
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x86
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2d
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0x48
	str r0, [sp, #0xc]
	ldr r0, _0222E788 ; =0x00010200
	mov r1, #4
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #0
	add r3, r5, #0
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x8a
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2c
	str r0, [sp, #4]
	mov r0, #0xa8
	str r0, [sp, #8]
	mov r0, #0x48
	str r0, [sp, #0xc]
	ldr r0, _0222E788 ; =0x00010200
	mov r2, #0
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	mov r1, #4
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	ldr r0, [sp, #0x20]
	mov r1, #4
	bl ov43_0222DEF8
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222E788: .word 0x00010200
	thumb_func_end ov43_0222E5B4


	thumb_func_start ov43_0222E78C
ov43_0222E78C: ; 0x0222E78C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	add r5, r1, #0
	str r0, [sp, #0x20]
	ldr r0, [r5, #4]
	str r3, [sp, #0x24]
	add r4, r2, #0
	bl Save_Frontier_GetStatic
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x24]
	mov r0, #0x80
	bl String_New
	add r7, r0, #0
	ldr r1, [sp, #0x24]
	mov r0, #0x80
	bl String_New
	add r6, r0, #0
	str r4, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	ldr r0, _0222E900 ; =0x00010200
	str r2, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	mov r1, #5
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x28]
	mov r1, #0x7c
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	ldr r1, [sp, #0x24]
	bl GetSpeciesName
	str r0, [sp, #0x2c]
	mov r0, #0x18
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0222E900 ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x20]
	str r1, [sp, #0xc]
	ldr r0, [r0, #0x20]
	ldr r2, [sp, #0x2c]
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x2c]
	bl String_Delete
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x28]
	mov r1, #0x6a
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	cmp r0, #0
	bne _0222E826
	mov r0, #0x22
	b _0222E828
_0222E826:
	mov r0, #0x23
_0222E828:
	str r4, [sp]
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	mov r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, _0222E900 ; =0x00010200
	mov r1, #5
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x28]
	mov r1, #0x7b
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x25
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, _0222E900 ; =0x00010200
	mov r1, #5
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #0
	add r3, r5, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x24
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	mov r0, #0x48
	str r0, [sp, #0xc]
	ldr r0, _0222E900 ; =0x00010200
	mov r1, #5
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x28]
	mov r1, #0x7a
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x25
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0x48
	str r0, [sp, #0xc]
	ldr r0, _0222E900 ; =0x00010200
	mov r1, #5
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #0
	add r3, r5, #0
	bl ov43_0222EC58
	ldr r0, [sp, #0x20]
	mov r1, #5
	bl ov43_0222DEF8
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222E900: .word 0x00010200
	thumb_func_end ov43_0222E78C


	thumb_func_start ov43_0222E904
ov43_0222E904: ; 0x0222E904
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r1, #0
	str r0, [sp, #0x20]
	ldr r0, [r5, #4]
	add r6, r3, #0
	add r4, r2, #0
	bl Save_Frontier_GetStatic
	str r0, [sp, #0x24]
	mov r0, #0x80
	add r1, r6, #0
	bl String_New
	add r7, r0, #0
	mov r0, #0x80
	add r1, r6, #0
	bl String_New
	add r6, r0, #0
	str r4, [sp]
	mov r0, #0x21
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	ldr r0, _0222EA3C ; =0x00010200
	str r2, [sp, #0xc]
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	mov r1, #6
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x6e
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	cmp r0, #0
	bne _0222E964
	mov r0, #0x22
	b _0222E966
_0222E964:
	mov r0, #0x23
_0222E966:
	str r4, [sp]
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	mov r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, _0222EA3C ; =0x00010200
	mov r1, #6
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x8f
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2e
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, _0222EA3C ; =0x00010200
	mov r1, #6
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #0
	add r3, r5, #0
	bl ov43_0222EC58
	str r4, [sp]
	mov r0, #0x24
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	mov r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, _0222EA3C ; =0x00010200
	mov r1, #6
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r2, [r5, r2]
	ldr r0, [sp, #0x24]
	mov r1, #0x8e
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	bl FrontierSave_GetStat
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x2e
	str r0, [sp, #4]
	mov r0, #0x70
	str r0, [sp, #8]
	mov r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, _0222EA3C ; =0x00010200
	mov r1, #6
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	mov r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	mov r2, #0
	add r3, r5, #0
	bl ov43_0222EC58
	ldr r0, [sp, #0x20]
	mov r1, #6
	bl ov43_0222DEF8
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222EA3C: .word 0x00010200
	thumb_func_end ov43_0222E904


	thumb_func_start ov43_0222EA40
ov43_0222EA40: ; 0x0222EA40
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r1, #0
	str r0, [sp, #0x20]
	ldr r0, [r5, #4]
	add r4, r2, #0
	add r7, r3, #0
	bl Save_Frontier_GetStatic
	ldr r0, [r5, #4]
	bl sub_0202C6F4
	str r0, [sp, #0x24]
	mov r0, #0x80
	add r1, r7, #0
	bl String_New
	add r6, r0, #0
	mov r0, #0x80
	add r1, r7, #0
	bl String_New
	add r7, r0, #0
	str r4, [sp]
	mov r0, #0x2f
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	ldr r0, _0222EBD4 ; =0x00010200
	str r2, [sp, #0xc]
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r0, [sp, #0x20]
	mov r1, #1
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	add r0, r4, #0
	mov r1, #0
	bl ov43_0222AC18
	str r4, [sp]
	mov r0, #0x30
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	mov r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, _0222EBD4 ; =0x00010200
	mov r1, #1
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r1, #0xb
	ldrsb r1, [r5, r1]
	ldr r0, [sp, #0x24]
	mov r2, #0xa
	add r1, r5, r1
	ldrb r1, [r1, #0x18]
	bl sub_0202C090
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x31
	str r0, [sp, #4]
	mov r0, #0x78
	str r0, [sp, #8]
	mov r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, _0222EBD4 ; =0x00010200
	mov r2, #0
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r0, [sp, #0x20]
	mov r1, #1
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	add r0, r4, #0
	mov r1, #1
	bl ov43_0222AC18
	str r4, [sp]
	mov r0, #0x30
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, _0222EBD4 ; =0x00010200
	mov r1, #1
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r2, #0xb
	ldrsb r1, [r5, r2]
	ldr r0, [sp, #0x24]
	add r1, r5, r1
	ldrb r1, [r1, #0x18]
	bl sub_0202C090
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x31
	str r0, [sp, #4]
	mov r0, #0x78
	str r0, [sp, #8]
	mov r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, _0222EBD4 ; =0x00010200
	mov r2, #0
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r0, [sp, #0x20]
	mov r1, #1
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	add r0, r4, #0
	mov r1, #2
	bl ov43_0222AC18
	str r4, [sp]
	mov r0, #0x30
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	mov r0, #0x48
	str r0, [sp, #0xc]
	ldr r0, _0222EBD4 ; =0x00010200
	mov r1, #1
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	mov r1, #0xb
	ldrsb r1, [r5, r1]
	ldr r0, [sp, #0x24]
	mov r2, #0xc
	add r1, r5, r1
	ldrb r1, [r1, #0x18]
	bl sub_0202C090
	add r1, r0, #0
	add r0, r4, #0
	bl ov43_0222ABFC
	str r4, [sp]
	mov r0, #0x31
	str r0, [sp, #4]
	mov r0, #0x78
	str r0, [sp, #8]
	mov r0, #0x48
	str r0, [sp, #0xc]
	ldr r0, _0222EBD4 ; =0x00010200
	mov r2, #0
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r0, [sp, #0x20]
	mov r1, #1
	add r3, r5, #0
	str r2, [sp, #0x1c]
	bl ov43_0222EC58
	ldr r0, [sp, #0x20]
	mov r1, #1
	bl ov43_0222DEF8
	add r0, r6, #0
	bl String_Delete
	add r0, r7, #0
	bl String_Delete
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222EBD4: .word 0x00010200
	thumb_func_end ov43_0222EA40


	thumb_func_start ov43_0222EBD8
ov43_0222EBD8: ; 0x0222EBD8
	push {r3, r4, r5, lr}
	sub sp, #0x20
	add r3, r1, #0
	str r2, [sp]
	mov r1, #0xe
	str r1, [sp, #4]
	mov r4, #0
	str r4, [sp, #8]
	ldr r1, _0222EC10 ; =0x00010200
	str r4, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r1, [r2, #0x7c]
	add r2, #0x80
	str r1, [sp, #0x14]
	ldr r1, [r2]
	add r5, r0, #0
	str r1, [sp, #0x18]
	mov r1, #7
	add r2, r4, #0
	str r4, [sp, #0x1c]
	bl ov43_0222EC58
	add r0, r5, #0
	mov r1, #7
	bl ov43_0222DEF8
	add sp, #0x20
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222EC10: .word 0x00010200
	thumb_func_end ov43_0222EBD8


	thumb_func_start ov43_0222EC14
ov43_0222EC14: ; 0x0222EC14
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #2
	ldrsh r2, [r1, r0]
	cmp r2, #0
	bge _0222EC24
	neg r2, r2
_0222EC24:
	mov r0, #0
	ldrsh r3, [r1, r0]
	cmp r3, #0
	bge _0222EC2E
	neg r3, r3
_0222EC2E:
	lsl r0, r2, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x18
	lsl r3, r3, #0x18
	str r0, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r0, [r4]
	mov r1, #3
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [r4]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov43_0222EC14


	thumb_func_start ov43_0222EC58
ov43_0222EC58: ; 0x0222EC58
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r6, [sp, #0x30]
	add r7, r0, #0
	str r1, [sp, #0x10]
	str r2, [sp, #0x14]
	ldr r0, [r6, #0x54]
	ldr r1, [sp, #0x34]
	ldr r2, [sp, #0x48]
	ldr r4, [sp, #0x44]
	ldr r5, [sp, #0x38]
	bl ReadMsgDataIntoString
	ldr r0, [r6, #0x50]
	ldr r2, [sp, #0x48]
	add r1, r4, #0
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x4c]
	cmp r0, #1
	beq _0222EC88
	cmp r0, #2
	beq _0222EC9A
	b _0222ECA6
_0222EC88:
	mov r0, #1
	add r1, r4, #0
	mov r2, #0
	bl FontID_String_GetWidth
	add r0, r0, #1
	lsr r0, r0, #1
	sub r5, r5, r0
	b _0222ECA6
_0222EC9A:
	mov r0, #1
	add r1, r4, #0
	mov r2, #0
	bl FontID_String_GetWidth
	sub r5, r5, r0
_0222ECA6:
	ldr r0, [sp, #0x3c]
	add r2, r4, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x40]
	add r3, r5, #0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	lsl r0, r0, #2
	add r0, r7, r0
	ldr r1, [r0, #0xc]
	ldr r0, [sp, #0x14]
	lsl r0, r0, #4
	add r0, r1, r0
	mov r1, #1
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov43_0222EC58


	thumb_func_start ov43_0222ECD4
ov43_0222ECD4: ; 0x0222ECD4
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r2, #0
	add r2, #0x80
	add r5, r0, #0
	ldr r0, [r4, #0x54]
	ldr r2, [r2]
	add r1, r3, #0
	bl ReadMsgDataIntoString
	add r2, r4, #0
	add r2, #0x80
	ldr r0, [r4, #0x50]
	ldr r1, [r4, #0x7c]
	ldr r2, [r2]
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x24]
	ldr r3, [sp, #0x20]
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	mov r1, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x7c]
	add r0, r5, #0
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov43_0222ECD4


	thumb_func_start ov43_0222ED18
ov43_0222ED18: ; 0x0222ED18
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x10]
	cmp r0, #1
	bne _0222ED26
	mov r2, #8
	b _0222ED28
_0222ED26:
	mov r2, #3
_0222ED28:
	cmp r1, #0
	ble _0222ED40
	mov r0, #0
	ldrsh r3, [r4, r0]
	strh r3, [r4, #2]
	ldrsh r0, [r4, r0]
	add r0, r0, r1
	add r1, r2, #0
	bl _s32_div_f
	strh r1, [r4]
	pop {r4, pc}
_0222ED40:
	bge _0222ED58
	mov r0, #0
	ldrsh r3, [r4, r0]
	strh r3, [r4, #2]
	ldrsh r3, [r4, r0]
	add r1, r3, r1
	strh r1, [r4]
	ldrsh r0, [r4, r0]
	cmp r0, #0
	bge _0222ED58
	add r0, r0, r2
	strh r0, [r4]
_0222ED58:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov43_0222ED18

	.rodata

_0222ED5C:
	.byte 0x02, 0x02, 0x09
ov43_0222ED5F:
	.byte 0x02, 0x05, 0x1A, 0x0B
ov43_0222ED63:
	.byte 0x01, 0x05, 0x1B, 0x02
ov43_0222ED67:
	.byte 0x02, 0x05, 0x1A, 0x0B
ov43_0222ED6B:
	.byte 0x02, 0x05, 0x1A, 0x0B
ov43_0222ED6F:
	.byte 0x02, 0x05, 0x16, 0x0B, 0x00

ov43_0222ED74: ; 0x0222ED74
	.byte 0x01, 0x00, 0xBB, 0x01, 0xBB, 0x01

ov43_0222ED7A: ; 0x0222ED7A
	.byte 0xA0, 0xC0, 0x88, 0xF8, 0xFF, 0x00
	.byte 0x00, 0x00

ov43_0222ED82:
	.byte 0x05, 0x05, 0x0B, 0x02, 0x05, 0x09, 0x1A, 0x05, 0x0D, 0x00, 0x0C, 0x00, 0x0A, 0x00
	.byte 0x09, 0x00, 0x00, 0x00

ov43_0222ED94: ; 0x0222ED94
	.byte 0x00, 0x05, 0x06, 0x00, 0x00, 0x03, 0x04, 0x00

ov43_0222ED9C: ; 0x0222ED9C
	.byte 0x00, 0x01, 0x0F, 0x00
	.byte 0x03, 0x04, 0x01, 0x0F, 0x00, 0x00, 0xC7, 0x00, 0xAC, 0x00, 0x88, 0x00

ov43_0222EDAC: ; 0x0222EDAC
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0xF5, 0x01, 0x00, 0x00, 0xF5, 0x01, 0x00, 0x00

ov43_0222EDB8: ; 0x0222EDB8
	.byte 0x00, 0x0E, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C

ov43_0222EDC8: ; 0x0222EDC8
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov43_0222EDD8: ; 0x0222EDD8
	.byte 0x40, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov43_0222EDE8:
	.byte 0x02, 0x05, 0x10, 0x02, 0x02, 0x0C, 0x10, 0x02
	.byte 0x13, 0x05, 0x08, 0x05, 0x17, 0x0C, 0x04, 0x02

ov43_0222EDF8: ; 0x0222EDF8
	.byte 0x0E, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04

ov43_0222EE08: ; 0x0222EE08
	.byte 0x00, 0x00, 0x00, 0x00, 0x20, 0x18, 0x20, 0x00
	.byte 0x00, 0x00, 0x20, 0x18, 0xE0, 0xFF, 0x00, 0x00, 0x20, 0x18

ov43_0222EE1A: ; 0x0222EE1A
	.byte 0x22, 0x3E, 0x12, 0xEE, 0x4A, 0x66
	.byte 0x12, 0xEE, 0x72, 0x8E, 0x12, 0xEE, 0x9A, 0xB6, 0x12, 0xEE, 0xFF, 0x00, 0x00, 0x00

ov43_0222EE2E:
	.byte 0x02, 0x01
	.byte 0x0E, 0x02, 0x02, 0x04, 0x1A, 0x02, 0x02, 0x07, 0x1A, 0x04, 0x02, 0x0C, 0x1A, 0x02, 0x02, 0x0F
	.byte 0x1A, 0x04

ov43_0222EE42: ; 0x0222EE42
	.byte 0x08, 0x28, 0xEC, 0x0C, 0x78, 0x98, 0xEC, 0x0C, 0xA0, 0xC0, 0x00, 0x70, 0xA0, 0xC0
	.byte 0x70, 0xE0, 0xA0, 0xC0, 0xE0, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00

ov43_0222EE5C: ; 0x0222EE5C
	.byte 0x03, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

ov43_0222EE84: ; 0x0222EE84
	.byte 0x08, 0x28, 0xEC, 0x0C, 0x78, 0x98, 0xEC, 0x0C, 0xA0, 0xC0, 0x00, 0x20
	.byte 0xA0, 0xC0, 0x20, 0x40, 0xA0, 0xC0, 0x40, 0x60, 0xA0, 0xC0, 0x60, 0x80, 0xA0, 0xC0, 0x80, 0xA0
	.byte 0xA0, 0xC0, 0xA0, 0xC0, 0xA0, 0xC0, 0xC0, 0xE0, 0xA0, 0xC0, 0xE0, 0x00, 0xFF, 0x00, 0x00, 0x00

ov43_0222EEB0: ; 0x0222EEB0
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov43_0222EEE0: ; 0x0222EEE0
	.byte 0x08, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x0A, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x3D, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x0A, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00

ov43_0222EF20: ; 0x0222EF20
	.byte 0x04, 0x19, 0x01, 0x06, 0x02, 0x0E, 0x01, 0x00, 0x04, 0x01, 0x00, 0x18, 0x03, 0x0E, 0x0D, 0x00
	.byte 0x04, 0x16, 0x06, 0x09, 0x02, 0x0E, 0x55, 0x00, 0x04, 0x09, 0x11, 0x08, 0x02, 0x0E, 0x73, 0x00
	.byte 0x04, 0x13, 0x15, 0x0B, 0x02, 0x0E, 0xA5, 0x00, 0x04, 0x04, 0x04, 0x0A, 0x0A, 0x0F, 0xBB, 0x00
	.byte 0x04, 0x01, 0x11, 0x06, 0x02, 0x0E, 0x67, 0x00, 0x04, 0x01, 0x15, 0x11, 0x02, 0x0E, 0x83, 0x00

ov43_0222EF60: ; 0x0222EF60
	.byte 0x20, 0x40, 0x10, 0x80, 0x40, 0x60, 0x10, 0x80, 0x60, 0x80, 0x10, 0x80, 0x80, 0xA0, 0x10, 0x80
	.byte 0x20, 0x40, 0x80, 0xF0, 0x40, 0x60, 0x80, 0xF0, 0x60, 0x80, 0x80, 0xF0, 0x80, 0xA0, 0x80, 0xF0
	.byte 0xA0, 0xC0, 0x88, 0xF8, 0x58, 0x68, 0x00, 0x10, 0x58, 0x68, 0xF0, 0x00, 0x00, 0x20, 0x80, 0xA0
	.byte 0x00, 0x20, 0xA0, 0xC0, 0x00, 0x20, 0xC0, 0xE0, 0x00, 0x20, 0xE0, 0x00, 0xFF, 0x00, 0x00, 0x00

ov43_0222EFA0: ; 0x0222EFA0
	.byte 0x02, 0x00

ov43_0222EFA2: ; 0x0222EFA2
	.byte 0x04, 0x00, 0x0F, 0x04, 0x02, 0x02, 0x09, 0x00, 0x02, 0x00, 0x08, 0x00, 0x0F, 0x04
	.byte 0x02, 0x02, 0x09, 0x00, 0x02, 0x00, 0x0C, 0x00, 0x0F, 0x04, 0x02, 0x02, 0x09, 0x00, 0x02, 0x00
	.byte 0x10, 0x00, 0x0F, 0x04, 0x02, 0x02, 0x09, 0x00, 0x10, 0x00, 0x04, 0x00, 0x0F, 0x04, 0x02, 0x02
	.byte 0x09, 0x00, 0x10, 0x00, 0x08, 0x00, 0x0F, 0x04, 0x02, 0x02, 0x09, 0x00, 0x10, 0x00, 0x0C, 0x00
	.byte 0x0F, 0x04, 0x02, 0x02, 0x09, 0x00, 0x10, 0x00, 0x10, 0x00, 0x0F, 0x04, 0x02, 0x02, 0x09, 0x00
	.byte 0x11, 0x00, 0x14, 0x00, 0x0E, 0x04, 0x00, 0x01, 0x09, 0x00, 0x00, 0x00

ov43_0222EFFC: ; 0x0222EFFC
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00
	.byte 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x19, 0x01, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x1A, 0x04, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x1C, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1F, 0x04
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x00, 0x00, 0x01, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1D, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov43_0222F0C0: ; 0x0222F0C0
	.byte 0x10, 0x11, 0x00, 0x00

ov43_0222F0C4: ; 0x0222F0C4
	.byte 0x18, 0x10, 0x00, 0x00

ov43_0222F0C8: ; 0x0222F0C8
	.byte 0x00, 0x38, 0x3B, 0x00

ov43_0222F0CC: ; 0x0222F0CC
	.byte 0x01, 0x02, 0x03, 0x05

ov43_0222F0D0: ; 0x0222F0D0
	.byte 0x04, 0x01, 0x02, 0x05, 0x01, 0x01, 0x01, 0x01

	.data

_0222F0E0:
	.word ov43_0222DFB0
	.word ov43_0222EA40
	.word ov43_0222EBD8

ov43_0222F0EC: ; 0x0222F0EC
	.word ov43_0222C46C, 0
	.word ov43_0222C4B8, 0

ov43_0222F0FC: ; 0x0222F0FC
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x10, 0x00, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x00, 0x0C, 0x00

ov43_0222F10C: ; 0x0222F10C
	.word ov43_0222EDE8
	.word ov43_0222ED6F
	.word ov43_0222ED82
	.word ov43_0222EE2E
	.word ov43_0222ED5F
	.word ov43_0222ED6B
	.word ov43_0222ED67
	.word ov43_0222ED63

ov43_0222F12C: ; 0x0222F12C
	.word ov43_0222DFB0
	.word ov43_0222EA40
	.word ov43_0222E0E8
	.word ov43_0222E220
	.word ov43_0222E5B4
	.word ov43_0222E78C
	.word ov43_0222E904
	.word ov43_0222EBD8

ov43_0222F14C: ; 0x0222F14C
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x20, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00

ov43_0222F160: ; 0x0222F160
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x20, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov43_0222F1AC: ; 0x0222F1AC
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x09, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	; 0x0222F1E0

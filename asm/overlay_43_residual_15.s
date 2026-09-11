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

	thumb_func_start ov43_0222B944
ov43_0222B944: ; 0x0222B944
	push {r4, r5, r6, r7, lr}
	sub sp, #0x5c
	str r0, [sp, #0x18]
	ldr r4, [sp, #0x18]
	mov r0, #0
	ldr r5, _0222BA9C ; =ov43_0222ED74
	ldr r6, _0222BAA0 ; =ov43_0222EE08
	add r7, r2, #0
	str r3, [sp, #0x1c]
	str r0, [sp, #0x28]
	add r4, #8
_0222B95A:
	ldr r0, [sp, #0x1c]
	add r1, r7, #0
	str r0, [sp]
	ldrh r3, [r5]
	add r0, r4, #0
	add r2, r6, #0
	bl ov43_0222C788
	ldr r0, [sp, #0x28]
	add r5, r5, #2
	add r0, r0, #1
	add r6, r6, #6
	add r4, #0x38
	str r0, [sp, #0x28]
	cmp r0, #3
	blt _0222B95A
	ldr r0, [r7, #4]
	ldr r3, [sp, #0x1c]
	mov r1, #0
	mov r2, #0x10
	bl ov42_02227060
	ldr r1, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	add r1, #0xb4
	str r0, [r1]
	ldr r0, [sp, #0x18]
	mov r1, #1
	add r0, #0xb4
	ldr r0, [r0]
	mov r2, #2
	bl ov42_02227228
	mov r3, #0x15
	ldr r1, [sp, #0x18]
	str r3, [sp]
	mov r0, #9
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	ldr r0, _0222BAA4 ; =0x0000014F
	add r1, #0xb8
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [r7]
	mov r2, #1
	bl ov43_0222A24C
	ldr r0, [r7, #0x54]
	mov r1, #7
	bl NewString_ReadMsgData
	add r4, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0222BAA8 ; =0x00010F00
	mov r1, #4
	str r0, [sp, #8]
	ldr r0, [sp, #0x18]
	add r2, r4, #0
	add r0, #0xb8
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	mov r0, #0
	str r0, [sp, #0x20]
	ldr r0, _0222BAAC ; =ov43_0222EEE0
	ldr r6, [sp, #0x18]
	str r0, [sp, #0x24]
_0222B9F4:
	ldr r1, [sp, #0x1c]
	mov r0, #4
	bl ListMenuItems_New
	add r1, r6, #0
	add r1, #0xe4
	ldr r5, [sp, #0x24]
	str r0, [r1]
	mov r4, #0
_0222BA06:
	add r0, r6, #0
	add r0, #0xe4
	ldr r0, [r0]
	ldr r1, [r7, #0x54]
	ldr r2, [r5]
	ldr r3, [r5, #4]
	bl ListMenuItems_AppendFromMsgData
	add r4, r4, #1
	add r5, #8
	cmp r4, #4
	blt _0222BA06
	ldr r0, [sp, #0x24]
	add r6, r6, #4
	add r0, #0x20
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x20]
	add r0, r0, #1
	str r0, [sp, #0x20]
	cmp r0, #2
	blt _0222B9F4
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	ldr r0, _0222BAB0 ; =0x00000161
	ldr r1, [sp, #0x18]
	str r0, [sp, #0x10]
	mov r0, #0xf
	str r0, [sp, #0x14]
	ldr r0, [r7]
	add r1, #0xc8
	mov r2, #1
	mov r3, #2
	bl ov43_0222A24C
	ldr r1, [sp, #0x1c]
	mov r0, #0x80
	bl String_New
	ldr r1, [sp, #0x18]
	ldr r4, _0222BAB4 ; =ov43_0222EEB0
	add r1, #0xd8
	str r0, [r1]
	add r3, sp, #0x2c
	mov r2, #6
_0222BA6A:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0222BA6A
	ldr r0, [r7, #4]
	add r7, #0x88
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x1c]
	str r7, [sp, #0x30]
	str r0, [sp, #0x58]
	add r0, sp, #0x2c
	bl Sprite_CreateAffine
	ldr r1, [sp, #0x18]
	add r1, #0xf8
	str r0, [r1]
	ldr r0, [sp, #0x18]
	mov r1, #0
	add r0, #0xf8
	str r0, [sp, #0x18]
	ldr r0, [r0]
	bl Sprite_SetDrawFlag
	add sp, #0x5c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222BA9C: .word ov43_0222ED74
_0222BAA0: .word ov43_0222EE08
_0222BAA4: .word 0x0000014F
_0222BAA8: .word 0x00010F00
_0222BAAC: .word ov43_0222EEE0
_0222BAB0: .word 0x00000161
_0222BAB4: .word ov43_0222EEB0
	thumb_func_end ov43_0222B944


	thumb_func_start ov43_0222BAB8
ov43_0222BAB8: ; 0x0222BAB8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r0, #0xf8
	ldr r0, [r0]
	add r7, r2, #0
	bl Sprite_Delete
	add r0, r5, #0
	add r0, #0xc8
	bl RemoveWindow
	add r0, r5, #0
	add r0, #0xd8
	ldr r0, [r0]
	bl String_Delete
	mov r6, #0
	add r4, r5, #0
_0222BADC:
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	bl ListMenuItems_Delete
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #2
	blt _0222BADC
	add r0, r5, #0
	add r0, #0xb8
	bl RemoveWindow
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	bl ov42_02227274
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	bl ov42_02227114
	mov r4, #0
	add r5, #8
_0222BB0E:
	add r0, r5, #0
	add r1, r7, #0
	bl ov43_0222C7EC
	add r4, r4, #1
	add r5, #0x38
	cmp r4, #3
	blt _0222BB0E
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov43_0222BAB8


	thumb_func_start ov43_0222BB20
ov43_0222BB20: ; 0x0222BB20
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r4, r2, #0
	add r7, r1, #0
	add r1, r4, #0
	add r5, r0, #0
	add r0, r4, #0
	add r1, #0x64
	mov r2, #5
	add r6, r3, #0
	bl ov43_0222A9F4
	mov r0, #0x83
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xe
	str r1, [sp]
	mov r1, #4
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0xc
	str r1, [sp, #8]
	mov r1, #3
	str r1, [sp, #0xc]
	mov r1, #0
	str r1, [sp, #0x10]
	ldrh r2, [r0]
	mov r3, #0x14
	lsl r2, r2, #0x15
	lsr r2, r2, #0x18
	str r2, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r2, #0x11
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r4]
	bl CopyToBgTilemapRect
	add r0, r5, #0
	add r0, #0xb8
	bl ScheduleWindowCopyToVram
	ldr r0, [r4]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	add r0, r4, #0
	mov r1, #1
	bl ov43_0222AD00
	mov r0, #4
	ldrsh r0, [r5, r0]
	mov r3, #0
	add r1, r7, #0
	str r0, [sp]
	str r3, [sp, #4]
	str r6, [sp, #8]
	ldrsh r3, [r5, r3]
	add r0, r5, #0
	add r2, r4, #0
	bl ov43_0222C378
	mov r1, #1
	add r0, r4, #0
	add r2, r1, #0
	bl ov43_0222AD74
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x10
	bl ov43_0222AD98
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov43_0222BB20


	thumb_func_start ov43_0222BBB8
ov43_0222BBB8: ; 0x0222BBB8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r4, r2, #0
	add r5, r0, #0
	add r0, r4, #0
	bl ov43_0222AA70
	add r0, r5, #0
	add r0, #0xb8
	bl ClearWindowTilemapAndScheduleTransfer
	mov r7, #2
	mov r6, #0
	add r5, #8
	lsl r7, r7, #8
_0222BBD6:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r4, r7
	bl ov43_0222C9A4
	add r6, r6, #1
	add r5, #0x38
	cmp r6, #3
	blt _0222BBD6
	add r0, r4, #0
	mov r1, #0
	mov r2, #0xff
	bl ov43_0222AD74
	add r0, r4, #0
	mov r1, #1
	mov r2, #9
	bl ov43_0222AD98
	add r0, r4, #0
	mov r1, #0
	bl ov43_0222AD00
	mov r0, #0x83
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xe
	str r1, [sp]
	mov r1, #4
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0xc
	str r1, [sp, #8]
	mov r2, #0x11
	str r2, [sp, #0xc]
	mov r1, #0
	str r1, [sp, #0x10]
	ldrh r3, [r0]
	lsl r3, r3, #0x15
	lsr r3, r3, #0x18
	str r3, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r3, #0x14
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r4]
	bl CopyToBgTilemapRect
	mov r0, #0x83
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #0x10
	add r1, r0, #0
	str r2, [sp]
	mov r3, #4
	str r3, [sp, #4]
	add r1, #0xc
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldrh r1, [r0]
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r1, #0
	add r3, r1, #0
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r4]
	bl CopyToBgTilemapRect
	ldr r0, [r4]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov43_0222BBB8


	thumb_func_start ov43_0222BC78
ov43_0222BC78: ; 0x0222BC78
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r2, #0
	cmp r3, #0
	bne _0222BC9C
	ldr r0, _0222BD14 ; =0x000005DD
	bl PlaySE
	mov r2, #4
	add r0, r5, #0
	ldrsh r2, [r5, r2]
	add r0, #8
	add r1, r4, #0
	mov r3, #1
	bl ov43_0222C890
	mov r0, #3
	pop {r3, r4, r5, pc}
_0222BC9C:
	cmp r3, #5
	bne _0222BCEA
	mov r0, #4
	ldrsh r2, [r5, r0]
	cmp r2, #8
	bne _0222BCC2
	ldr r0, _0222BD14 ; =0x000005DD
	bl PlaySE
	mov r2, #4
	add r0, r5, #0
	ldrsh r2, [r5, r2]
	add r0, #8
	add r1, r4, #0
	mov r3, #1
	bl ov43_0222C890
	mov r0, #3
	pop {r3, r4, r5, pc}
_0222BCC2:
	mov r0, #0
	ldrsh r3, [r5, r0]
	ldr r1, [r1, #0x10]
	lsl r3, r3, #3
	add r2, r2, r3
	cmp r1, r2
	bls _0222BD10
	ldr r0, _0222BD14 ; =0x000005DD
	bl PlaySE
	mov r2, #4
	add r0, r5, #0
	ldrsh r2, [r5, r2]
	add r0, #8
	add r1, r4, #0
	mov r3, #1
	bl ov43_0222C890
	mov r0, #4
	pop {r3, r4, r5, pc}
_0222BCEA:
	cmp r3, #1
	bne _0222BCFC
	add r0, r4, #0
	mov r1, #0
	mov r2, #1
	bl ov43_0222AD40
	mov r0, #1
	pop {r3, r4, r5, pc}
_0222BCFC:
	cmp r3, #2
	bne _0222BD0E
	mov r1, #1
	add r0, r4, #0
	add r2, r1, #0
	bl ov43_0222AD40
	mov r0, #2
	pop {r3, r4, r5, pc}
_0222BD0E:
	mov r0, #0
_0222BD10:
	pop {r3, r4, r5, pc}
	nop
_0222BD14: .word 0x000005DD
	thumb_func_end ov43_0222BC78


	thumb_func_start ov43_0222BD18
ov43_0222BD18: ; 0x0222BD18
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, _0222BEE0 ; =gSystem
	add r6, r1, #0
	ldr r1, [r0, #0x48]
	ldr r0, _0222BEE4 ; =0x00000CF3
	add r7, r2, #0
	tst r0, r1
	beq _0222BD30
	mov r0, #0
	str r0, [r6]
_0222BD30:
	ldr r0, _0222BEE0 ; =gSystem
	mov r2, #1
	ldr r1, [r0, #0x48]
	tst r2, r1
	beq _0222BD4A
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	mov r3, #5
	bl ov43_0222BC78
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0222BD4A:
	mov r2, #2
	tst r1, r2
	beq _0222BD72
	mov r0, #8
	strh r0, [r5, #4]
	mov r2, #4
	add r0, r5, #0
	ldrsh r2, [r5, r2]
	add r0, #8
	add r1, r7, #0
	bl ov43_0222C844
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	mov r3, #0
	bl ov43_0222BC78
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0222BD72:
	mov r1, #4
	ldrsh r1, [r5, r1]
	mov r4, #0
	lsl r2, r1, #0x10
	lsr r2, r2, #0x10
	str r2, [sp, #8]
	add r2, r4, #0
	str r2, [sp, #4]
	ldr r2, [r0, #0x4c]
	mov r0, #0x40
	tst r0, r2
	beq _0222BDBA
	cmp r1, #8
	bne _0222BDA0
	mov r0, #6
	ldrsh r0, [r5, r0]
	mov r4, #1
	add r1, r4, #0
	strh r0, [r5, #4]
	add r0, r7, #0
	bl ov43_0222AD00
	b _0222BE62
_0222BDA0:
	cmp r1, #4
	bge _0222BDB0
	cmp r1, #0
	ble _0222BE62
	sub r0, r1, #1
	strh r0, [r5, #4]
	mov r4, #1
	b _0222BE62
_0222BDB0:
	ble _0222BE62
	sub r0, r1, #1
	strh r0, [r5, #4]
	mov r4, #1
	b _0222BE62
_0222BDBA:
	mov r0, #0x80
	tst r0, r2
	beq _0222BDEC
	cmp r1, #3
	beq _0222BDC8
	cmp r1, #7
	bne _0222BDD0
_0222BDC8:
	mov r0, #8
	strh r0, [r5, #4]
	mov r4, #1
	b _0222BE62
_0222BDD0:
	cmp r1, #4
	bge _0222BDE0
	cmp r1, #3
	bge _0222BE62
	add r0, r1, #1
	strh r0, [r5, #4]
	mov r4, #1
	b _0222BE62
_0222BDE0:
	cmp r1, #7
	bge _0222BE62
	add r0, r1, #1
	strh r0, [r5, #4]
	mov r4, #1
	b _0222BE62
_0222BDEC:
	mov r0, #0x20
	tst r0, r2
	beq _0222BE12
	cmp r1, #8
	beq _0222BE62
	cmp r1, #4
	bge _0222BE0A
	add r0, r1, #4
	mov r4, #1
	strh r0, [r5, #4]
	add r0, r4, #0
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp]
	b _0222BE62
_0222BE0A:
	sub r0, r1, #4
	strh r0, [r5, #4]
	mov r4, #1
	b _0222BE62
_0222BE12:
	mov r3, #0x10
	add r0, r2, #0
	tst r0, r3
	beq _0222BE38
	cmp r1, #8
	beq _0222BE62
	cmp r1, #4
	bge _0222BE2A
	add r0, r1, #4
	strh r0, [r5, #4]
	mov r4, #1
	b _0222BE62
_0222BE2A:
	sub r0, r1, #4
	mov r4, #1
	strh r0, [r5, #4]
	add r0, r4, #0
	str r0, [sp, #4]
	str r0, [sp]
	b _0222BE62
_0222BE38:
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _0222BE62
	beq _0222BE50
	lsl r1, r3, #5
	tst r1, r2
	beq _0222BE50
	mov r0, #1
	str r0, [sp, #4]
	add r0, r4, #0
	str r0, [sp]
	b _0222BE62
_0222BE50:
	cmp r0, #0
	beq _0222BE62
	mov r0, #1
	lsl r0, r0, #8
	tst r0, r2
	beq _0222BE62
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp]
_0222BE62:
	ldr r0, [sp, #4]
	cmp r0, #1
	bne _0222BEBC
	ldr r0, [sp]
	cmp r0, #0
	beq _0222BE96
	mov r0, #0
	ldrsh r1, [r5, r0]
	mov r3, #2
	strh r1, [r5, #2]
	ldrsh r0, [r5, r0]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	strh r0, [r5]
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	bl ov43_0222BC78
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0222BE96:
	mov r0, #0
	ldrsh r1, [r5, r0]
	strh r1, [r5, #2]
	ldrsh r1, [r5, r0]
	sub r1, r1, #1
	strh r1, [r5]
	ldrsh r0, [r5, r0]
	cmp r0, #0
	bge _0222BEAC
	add r0, r0, #4
	strh r0, [r5]
_0222BEAC:
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	mov r3, #1
	bl ov43_0222BC78
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0222BEBC:
	cmp r4, #1
	bne _0222BED8
	ldr r0, _0222BEE8 ; =0x000005E5
	bl PlaySE
	mov r2, #4
	add r0, r5, #0
	ldrsh r2, [r5, r2]
	add r0, #8
	add r1, r7, #0
	bl ov43_0222C844
	ldr r0, [sp, #8]
	strh r0, [r5, #6]
_0222BED8:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_0222BEE0: .word gSystem
_0222BEE4: .word 0x00000CF3
_0222BEE8: .word 0x000005E5
	thumb_func_end ov43_0222BD18


	thumb_func_start ov43_0222BEEC
ov43_0222BEEC: ; 0x0222BEEC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _0222BF9C ; =ov43_0222EF60
	add r7, r1, #0
	add r4, r2, #0
	add r6, r3, #0
	bl TouchscreenHitbox_FindHitboxAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _0222BF08
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222BF08:
	cmp r0, #8
	bhi _0222BF34
	mov r1, #1
	str r1, [r6]
	strh r0, [r5, #4]
	ldr r0, _0222BFA0 ; =0x000005E5
	bl PlaySE
	mov r2, #4
	add r0, r5, #0
	ldrsh r2, [r5, r2]
	add r0, #8
	add r1, r4, #0
	bl ov43_0222C844
	add r0, r5, #0
	add r1, r7, #0
	add r2, r4, #0
	mov r3, #5
	bl ov43_0222BC78
	pop {r3, r4, r5, r6, r7, pc}
_0222BF34:
	cmp r0, #9
	beq _0222BF4C
	cmp r0, #0xa
	bne _0222BF40
	mov r1, #1
	b _0222BF4C
_0222BF40:
	mov r1, #0
	ldrsh r1, [r5, r1]
	sub r0, #0xb
	sub r0, r0, r1
	lsl r0, r0, #0x18
	asr r1, r0, #0x18
_0222BF4C:
	cmp r1, #0
	bne _0222BF54
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222BF54:
	mov r0, #1
	str r0, [r6]
	mov r0, #0
	ldrsh r2, [r5, r0]
	strh r2, [r5, #2]
	ldrsh r2, [r5, r0]
	add r2, r2, r1
	strh r2, [r5]
	cmp r1, #0
	ldrsh r0, [r5, r0]
	blt _0222BF86
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	strh r0, [r5]
	add r0, r5, #0
	add r1, r7, #0
	add r2, r4, #0
	mov r3, #2
	bl ov43_0222BC78
	pop {r3, r4, r5, r6, r7, pc}
_0222BF86:
	cmp r0, #0
	bge _0222BF8E
	add r0, r0, #4
	strh r0, [r5]
_0222BF8E:
	add r0, r5, #0
	add r1, r7, #0
	add r2, r4, #0
	mov r3, #1
	bl ov43_0222BC78
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222BF9C: .word ov43_0222EF60
_0222BFA0: .word 0x000005E5
	thumb_func_end ov43_0222BEEC


	thumb_func_start ov43_0222BFA4
ov43_0222BFA4: ; 0x0222BFA4
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	mov r3, #0
	str r3, [sp]
	add r3, sp, #0
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	bl ov43_0222BEEC
	ldr r1, [sp]
	cmp r1, #0
	beq _0222BFC6
	mov r1, #1
	add sp, #4
	str r1, [r4]
	pop {r3, r4, r5, r6, pc}
_0222BFC6:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov43_0222BD18
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	thumb_func_end ov43_0222BFA4


	thumb_func_start ov43_0222BFD4
ov43_0222BFD4: ; 0x0222BFD4
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r0, #0xb2
	ldrh r0, [r0]
	add r4, r2, #0
	cmp r0, #2
	bne _0222BFE8
	mov r2, #2
	b _0222BFEA
_0222BFE8:
	mov r2, #1
_0222BFEA:
	mov r0, #4
	ldrsh r0, [r5, r0]
	str r0, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	mov r3, #0
	ldrsh r3, [r5, r3]
	add r0, r5, #0
	add r2, r4, #0
	bl ov43_0222C378
	add r5, #8
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #0xa
	bl ov43_0222C844
	add r0, r4, #0
	mov r1, #0
	bl ov43_0222AD20
	ldr r0, _0222C020 ; =0x000005E1
	bl PlaySE
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_0222C020: .word 0x000005E1
	thumb_func_end ov43_0222BFD4


	thumb_func_start ov43_0222C024
ov43_0222C024: ; 0x0222C024
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	mov r0, #0xb0
	ldrsh r0, [r5, r0]
	str r1, [sp, #0xc]
	add r4, r2, #0
	add r6, r3, #0
	cmp r0, #8
	blt _0222C0B4
	mov r2, #0
	ldr r0, [r4]
	mov r1, #2
	add r3, r2, #0
	bl ScheduleSetBgPosText
	mov r2, #0
	ldr r0, [r4]
	mov r1, #3
	add r3, r2, #0
	bl ScheduleSetBgPosText
	ldr r3, _0222C140 ; =ov43_0222F0FC
	add r2, sp, #0x10
	add r7, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r0, r4, #0
	add r0, #8
	add r1, r7, #0
	bl GF_SetG2dRendererSurface
	add r0, r5, #0
	add r0, #0xb2
	ldrh r0, [r0]
	cmp r0, #2
	bne _0222C076
	mov r2, #2
	b _0222C078
_0222C076:
	mov r2, #1
_0222C078:
	mov r0, #0x38
	add r1, r5, #0
	mul r0, r2
	mov r2, #2
	add r1, #8
	lsl r2, r2, #8
	add r0, r1, r0
	add r1, r4, #0
	add r2, r4, r2
	bl ov43_0222C9A4
	mov r0, #4
	ldrsh r0, [r5, r0]
	mov r3, #0
	ldr r1, [sp, #0xc]
	str r0, [sp]
	str r3, [sp, #4]
	str r6, [sp, #8]
	ldrsh r3, [r5, r3]
	add r0, r5, #0
	add r2, r4, #0
	bl ov43_0222C378
	add r0, r4, #0
	mov r1, #1
	bl ov43_0222AD20
	add sp, #0x20
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0222C0B4:
	lsl r1, r0, #8
	asr r0, r1, #2
	lsr r0, r0, #0x1d
	add r0, r1, r0
	asr r6, r0, #3
	add r0, r5, #0
	add r0, #0xb2
	ldrh r0, [r0]
	cmp r0, #2
	bne _0222C0CA
	neg r6, r6
_0222C0CA:
	ldr r0, [r4]
	mov r1, #2
	mov r2, #0
	add r3, r6, #0
	bl ScheduleSetBgPosText
	ldr r0, [r4]
	mov r1, #3
	mov r2, #0
	add r3, r6, #0
	bl ScheduleSetBgPosText
	ldr r3, _0222C140 ; =ov43_0222F0FC
	add r2, sp, #0x10
	add r7, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r1, [sp, #0x10]
	lsl r0, r6, #0xc
	add r0, r1, r0
	str r0, [sp, #0x10]
	add r0, r4, #0
	add r0, #8
	add r1, r7, #0
	bl GF_SetG2dRendererSurface
	mov r0, #0xb0
	ldrsh r3, [r5, r0]
	mov r0, #0x1f
	lsr r2, r3, #0x1f
	lsl r1, r3, #0x1f
	sub r1, r1, r2
	ror r1, r0
	add r0, r2, r1
	beq _0222C130
	add r2, r3, r2
	asr r0, r2, #1
	lsl r1, r0, #2
	ldr r0, _0222C144 ; =ov43_0222F0EC
	ldr r6, [r0, r1]
	cmp r6, #0
	beq _0222C130
	mov r2, #0
	mov r3, #2
	ldrsh r2, [r5, r2]
	ldrsh r3, [r5, r3]
	add r0, r5, #0
	add r1, r4, #0
	blx r6
_0222C130:
	mov r0, #0xb0
	ldrsh r0, [r5, r0]
	add r5, #0xb0
	add r0, r0, #1
	strh r0, [r5]
	mov r0, #0
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222C140: .word ov43_0222F0FC
_0222C144: .word ov43_0222F0EC
	thumb_func_end ov43_0222C024


	thumb_func_start ov43_0222C148
ov43_0222C148: ; 0x0222C148
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	add r5, r1, #0
	add r6, r0, #0
	ldr r0, [r5, #4]
	add r4, r2, #0
	str r3, [sp, #0x18]
	bl sub_0202C6F4
	str r0, [sp, #0x1c]
	add r0, r6, #0
	bl ov43_0222C620
	str r0, [sp, #0x20]
	add r7, r5, #0
	ldr r1, [sp, #0x20]
	add r7, #0x18
	ldrb r1, [r7, r1]
	ldr r0, [sp, #0x1c]
	mov r2, #8
	bl sub_0202C090
	str r0, [sp, #0x24]
	add r0, sp, #0x28
	mov r1, #0
	mov r2, #0x18
	bl MI_CpuFill8
	ldr r1, _0222C220 ; =ov43_0222ED9C
	add r0, sp, #0x28
	ldrh r2, [r1, #4]
	strh r2, [r0]
	ldrh r2, [r1, #6]
	strh r2, [r0, #2]
	ldrh r2, [r1, #8]
	strh r2, [r0, #4]
	ldrh r2, [r1, #0xa]
	strh r2, [r0, #6]
	ldrh r2, [r1, #0xc]
	ldrh r1, [r1, #0xe]
	strh r2, [r0, #8]
	strh r1, [r0, #0xa]
	ldr r0, [sp, #0x24]
	cmp r0, #2
	bne _0222C1AC
	add r0, r6, #0
	add r0, #0xe8
	ldr r0, [r0]
	str r0, [sp, #0x34]
	b _0222C1B4
_0222C1AC:
	add r0, r6, #0
	add r0, #0xe4
	ldr r0, [r0]
	str r0, [sp, #0x34]
_0222C1B4:
	ldr r0, [r4]
	mov r1, #4
	str r0, [sp, #0x38]
	add r0, sp, #0x28
	strb r1, [r0, #0x14]
	mov r0, #5
	str r0, [sp]
	mov r0, #0x11
	str r0, [sp, #4]
	mov r1, #0
	ldr r0, _0222C224 ; =ov43_0222C630
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r0, #1
	str r0, [sp, #0x14]
	ldr r2, [r5]
	ldr r0, [r4, #0x5c]
	lsl r2, r2, #0x18
	add r1, sp, #0x28
	lsr r2, r2, #0x18
	mov r3, #0xd
	bl TouchscreenListMenu_CreateWithCallback
	add r1, r6, #0
	add r1, #0xec
	str r0, [r1]
	ldr r2, [sp, #0x20]
	ldr r1, [r5, #4]
	ldrb r2, [r7, r2]
	ldr r3, [sp, #0x18]
	add r0, r4, #0
	bl ov43_0222AB20
	ldr r3, [sp, #0x18]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0xc
	bl ov43_0222C550
	add r0, r4, #0
	mov r1, #0
	bl ov43_0222AD00
	mov r0, #1
	str r0, [sp]
	mov r0, #4
	mov r1, #8
	mov r2, #0
	mov r3, #0x3d
	bl StartBrightnessTransition
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222C220: .word ov43_0222ED9C
_0222C224: .word ov43_0222C630
	thumb_func_end ov43_0222C148


	thumb_func_start ov43_0222C228
ov43_0222C228: ; 0x0222C228
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r1, #0
	add r6, r2, #0
	bl ov43_0222C5D8
	cmp r0, #0
	bne _0222C23C
	mov r0, #6
	pop {r3, r4, r5, r6, r7, pc}
_0222C23C:
	add r0, r5, #0
	add r0, #0xec
	ldr r0, [r0]
	bl TouchscreenListMenu_HandleInput
	add r4, r0, #0
	cmp r4, #3
	beq _0222C25E
	mov r0, #1
	mvn r0, r0
	cmp r4, r0
	beq _0222C25E
	add r0, r0, #1
	cmp r4, r0
	bne _0222C268
	mov r0, #6
	pop {r3, r4, r5, r6, r7, pc}
_0222C25E:
	add r0, r6, #0
	mov r1, #1
	bl ov43_0222AD00
	mov r4, #2
_0222C268:
	add r0, r5, #0
	bl ov43_0222C600
	add r0, r5, #0
	add r0, #0xec
	ldr r0, [r0]
	bl TouchscreenListMenu_WasLastInputTouch
	str r0, [r7]
	add r0, r5, #0
	add r0, #0xec
	ldr r0, [r0]
	bl TouchscreenListMenu_Destroy
	cmp r4, #2
	bne _0222C2A0
	add r0, r6, #0
	mov r1, #1
	bl ov43_0222AD00
	mov r2, #4
	add r0, r5, #0
	ldrsh r2, [r5, r2]
	add r0, #8
	add r1, r6, #0
	mov r3, #0
	bl ov43_0222C890
_0222C2A0:
	mov r0, #0
	mov r1, #0x3d
	mov r2, #1
	bl SetBlendBrightness
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov43_0222C228


	thumb_func_start ov43_0222C2B0
ov43_0222C2B0: ; 0x0222C2B0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r1, #0
	str r0, [sp]
	ldr r0, [r5, #4]
	add r4, r2, #0
	str r3, [sp, #4]
	bl sub_0202C6F4
	str r0, [sp, #0x1c]
	ldr r0, [sp]
	bl ov43_0222C620
	add r6, r5, #0
	add r7, r0, #0
	add r6, #0x18
	ldrb r1, [r6, r7]
	ldr r0, [sp, #0x1c]
	bl sub_0202C23C
	bl DWC_GetFriendKey
	str r1, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	mov r2, #0
	eor r0, r2
	ldr r2, [sp, #0x14]
	mov r1, #0
	eor r1, r2
	orr r0, r1
	beq _0222C2F6
	mov r0, #0x3c
	str r0, [sp, #8]
	b _0222C2FA
_0222C2F6:
	mov r0, #0x42
	str r0, [sp, #8]
_0222C2FA:
	ldr r0, _0222C328 ; =0x000005DD
	bl PlaySE
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	add r0, r4, #0
	bl ov43_0222AAA4
	ldrb r2, [r6, r7]
	ldr r1, [r5, #4]
	ldr r3, [sp, #4]
	add r0, r4, #0
	bl ov43_0222AB20
	ldr r0, [sp]
	ldr r2, [sp, #8]
	ldr r3, [sp, #4]
	add r1, r4, #0
	bl ov43_0222C550
	mov r0, #1
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222C328: .word 0x000005DD
	thumb_func_end ov43_0222C2B0


	thumb_func_start ov43_0222C32C
ov43_0222C32C: ; 0x0222C32C
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r1, #0
	add r4, r2, #0
	add r6, r3, #0
	bl ov43_0222C620
	add r2, r0, #0
	add r2, r5, r2
	ldrb r2, [r2, #0x18]
	ldr r1, [r5, #4]
	add r0, r4, #0
	add r3, r6, #0
	bl ov43_0222AB20
	add r0, r7, #0
	add r1, r4, #0
	mov r2, #0x39
	add r3, r6, #0
	bl ov43_0222C550
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov43_0222C32C

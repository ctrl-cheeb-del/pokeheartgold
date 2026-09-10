#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public IncrementGameStat119
	.public IncrementGameStat47
	.public _02254A28
	.public _02254E20
	.public _022577C0
	.public ov45_02229EE0
	.public ov45_02229F70
	.public ov45_02229F94
	.public ov45_02229FE0
	.public ov45_02229FF4
	.public ov45_0222A0F0
	.public ov45_0222A15C
	.public ov45_0222A208
	.public ov45_0222A214
	.public ov45_0222A230
	.public ov45_0222A25C
	.public ov45_0222A288
	.public ov45_0222A2A0
	.public ov45_0222A2CC
	.public ov45_0222A2E0
	.public ov45_0222A2F8
	.public ov45_0222A310
	.public ov45_0222A324
	.public ov45_0222A330
	.public ov45_0222A33C
	.public ov45_0222A35C
	.public ov45_0222A374
	.public ov45_0222A394
	.public ov45_0222A3A0
	.public ov45_0222A3BC
	.public ov45_0222A3D4
	.public ov45_0222A3EC
	.public ov45_0222A43C
	.public ov45_0222A450
	.public ov45_0222A480
	.public ov45_0222A4D0
	.public ov45_0222A520
	.public ov45_0222A53C
	.public ov45_0222A548
	.public ov45_0222A550
	.public ov45_0222A578
	.public ov45_0222A5C0
	.public ov45_0222A5E8
	.public ov45_0222A704
	.public ov45_0222A72C
	.public ov45_0222A770
	.public ov45_0222A7DC
	.public ov45_0222A844
	.public ov45_0222A92C
	.public ov45_0222A964
	.public ov45_0222A9A4
	.public ov45_0222A9CC
	.public ov45_0222AA10
	.public ov45_0222AA28
	.public ov45_0222AA5C
	.public ov45_0222AA84
	.public ov45_0222AAA8
	.public ov45_0222AAC8
	.public ov45_0222AADC
	.public ov45_0222AAEC
	.public ov45_0222AB0C
	.public ov45_0222AB28
	.public ov45_0222AB38
	.public ov45_0222AB48
	.public ov45_0222AB58
	.public ov45_0222AB68
	.public ov45_0222AB78
	.public ov45_0222AB94
	.public ov45_0222ABD0
	.public ov45_0222AC14
	.public ov45_0222AC58
	.public ov45_0222ACB8
	.public ov45_0222AD2C
	.public ov45_0222AD3C
	.public ov45_0222AD4C
	.public ov45_0222AD58
	.public ov45_0222AD70
	.public ov45_0222AD80
	.public ov45_0222AD90
	.public ov45_0222ADA8
	.public ov45_0222ADB8
	.public ov45_0222ADC8
	.public ov45_0222ADD8
	.public ov45_0222ADE8
	.public ov45_0222ADF8
	.public ov45_0222AE08
	.public ov45_0222AE24
	.public ov45_0222AE34
	.public ov45_0222AE44
	.public ov45_0222AE54
	.public ov45_0222AE64
	.public ov45_0222AE74
	.public ov45_0222AED8
	.public ov45_0222AF80
	.public ov45_0222AFC4
	.public ov45_0222AFF8
	.public ov45_0222B00C
	.public ov45_0222B048
	.public ov45_0222B06C
	.public ov45_0222B094
	.public ov45_0222B0BC
	.public ov45_0222B0D8
	.public ov45_0222B0E8
	.public ov45_0222B118
	.public ov45_0222B134
	.public ov45_0222B1B4
	.public ov45_0222B1DC
	.public ov45_0222B1EC
	.public ov45_0222B1FC
	.public ov45_0222B21C
	.public ov45_0222B244
	.public ov45_0222B270
	.public ov45_0222B28C
	.public ov45_0222B2B4
	.public ov45_0222B470
	.public ov45_0222B530
	.public ov45_0222B5A0
	.public ov45_0222B75C
	.public ov45_0222B79C
	.public ov45_0222B840
	.public ov45_0222B8A0
	.public ov45_0222BA3C
	.public ov45_0222BAC4
	.public ov45_0222BADC
	.public ov45_0222BB00
	.public ov45_0222BB60
	.public ov45_0222BC3C
	.public ov45_0222BC84
	.public ov45_0222BCC8
	.public ov45_0222BCD8
	.public ov45_0222BCE4
	.public ov45_0222BD30
	.public ov45_0222BD4C
	.public ov45_0222BD5C
	.public ov45_0222BD74
	.public ov45_0222BD94
	.public ov45_0222BDB0
	.public ov45_0222BDCC
	.public ov45_0222BDE8
	.public ov45_0222BE08
	.public ov45_0222BE28
	.public ov45_0222BE5C
	.public ov45_0222BE74
	.public ov45_0222BE9C
	.public ov45_0222BF18
	.public ov45_0222BF98
	.public ov45_0222C0CC
	.public ov45_0222C130
	.public ov45_0222C1EC
	.public ov45_0222C2A8
	.public ov45_0222C370
	.public ov45_0222C388
	.public ov45_0222C3B0
	.public ov45_0222C408
	.public ov45_0222C480
	.public ov45_0222C4B4
	.public ov45_0222C4E4
	.public ov45_0222C4FC
	.public ov45_0222C514
	.public ov45_0222C54C
	.public ov45_0222C580
	.public ov45_0222C5B4
	.public ov45_0222C5E8
	.public ov45_0222C61C
	.public ov45_0222C658
	.public ov45_0222C688
	.public ov45_0222C73C
	.public ov45_0222C79C
	.public ov45_0222C800
	.public ov45_0222C828
	.public ov45_0222C83C
	.public ov45_0222C858
	.public ov45_0222C88C
	.public ov45_0222C8AC
	.public ov45_0222C8C8
	.public ov45_0222C900
	.public ov45_0222C944
	.public ov45_0222C95C
	.public ov45_0222C978
	.public ov45_0222C994
	.public ov45_0222C9A0
	.public ov45_0222C9D0
	.public ov45_0222C9EC
	.public ov45_0222CA10
	.public ov45_0222CA7C
	.public ov45_0222CA8C
	.public ov45_0222CAA0
	.public ov45_0222CB44
	.public ov45_0222CB74
	.public ov45_0222CBD0
	.public ov45_0222CC00
	.public ov45_0222CC50
	.public ov45_0222CC7C
	.public ov45_0222CCA4
	.public ov45_0222CCB8
	.public ov45_0222CCE4
	.public ov45_0222CD04
	.public ov45_0222CD1C
	.public ov45_0222CD68
	.public ov45_0222CD84
	.public ov45_0222CD90
	.public ov45_0222CDC4
	.public ov45_0222CDE4
	.public ov45_0222CE0C
	.public ov45_0222CE2C
	.public ov45_0222CE54
	.public ov45_0222CE78
	.public ov45_0222CE94
	.public ov45_0222CEB0
	.public ov45_0222CF00
	.public ov45_0222CF24
	.public ov45_0222CF40
	.public ov45_0222CF68
	.public ov45_0222CFF4
	.public ov45_0222D01C
	.public ov45_0222D028
	.public ov45_0222D054
	.public ov45_0222D078
	.public ov45_0222D0BC
	.public ov45_0222D0C8
	.public ov45_0222D0D8
	.public ov45_0222D0FC
	.public ov45_0222D130
	.public ov45_0222D13C
	.public ov45_0222D14C
	.public ov45_0222D164
	.public ov45_0222D19C
	.public ov45_0222D1B0
	.public ov45_0222D1DC
	.public ov45_0222D20C
	.public ov45_0222D23C
	.public ov45_0222D250
	.public ov45_0222D27C
	.public ov45_0222D2AC
	.public ov45_0222D2E4
	.public ov45_0222D2F8
	.public ov45_0222D324
	.public ov45_0222D354
	.public ov45_0222D380
	.public ov45_0222D38C
	.public ov45_0222D3B0
	.public ov45_0222D3C4
	.public ov45_0222D3D8
	.public ov45_0222D410
	.public ov45_0222D41C
	.public ov45_0222D428
	.public ov45_0222D434
	.public ov45_0222D44C
	.public ov45_0222D484
	.public ov45_0222D4C0
	.public ov45_0222D4CC
	.public ov45_0222D4DC
	.public ov45_0222D500
	.public ov45_0222D524
	.public ov45_0222D594
	.public ov45_0222D638
	.public ov45_0222D6B0
	.public ov45_0222D6D4
	.public ov45_0222D6FC
	.public ov45_0222D724
	.public ov45_0222D740
	.public ov45_0222D79C
	.public ov45_0222D7C0
	.public ov45_0222D7CC
	.public ov45_0222D7FC
	.public ov45_0222D844
	.public ov45_0222D860
	.public ov45_0222D890
	.public ov45_0222D8A4
	.public ov45_0222D8C8
	.public ov45_0222D8D4
	.public ov45_0222D8F0
	.public ov45_0222D940
	.public ov45_0222D990
	.public ov45_0222D9EC
	.public ov45_0222DA80
	.public ov45_0222DAE0
	.public ov45_0222DB3C
	.public ov45_0222DB98
	.public ov45_0222DC08
	.public ov45_0222DC64
	.public ov45_0222DD44
	.public ov45_0222DD5C
	.public ov45_0222DD78
	.public ov45_0222DDE4
	.public ov45_0222DE1C
	.public ov45_0222DE3C
	.public ov45_0222DE58
	.public ov45_0222DE74
	.public ov45_0222DE8C
	.public ov45_0222DEA4
	.public ov45_0222DEB8
	.public ov45_0222DECC
	.public ov45_0222DEE0
	.public ov45_0222DEF4
	.public ov45_0222DF14
	.public ov45_0222DF38
	.public ov45_0222DF58
	.public ov45_0222DF78
	.public ov45_0222DFD0
	.public ov45_0222E000
	.public ov45_0222E03C
	.public ov45_0222E04C
	.public ov45_0222E094
	.public ov45_0222E0A4
	.public ov45_0222E0CC
	.public ov45_0222E0E0
	.public ov45_0222E14C
	.public ov45_0222E1A0
	.public ov45_0222E200
	.public ov45_0222E33C
	.public ov45_0222E39C
	.public ov45_0222E414
	.public ov45_0222E484
	.public ov45_0222E4A8
	.public ov45_0222E540
	.public ov45_0222E550
	.public ov45_0222E560
	.public ov45_0222E574
	.public ov45_0222E584
	.public ov45_0222E5A0
	.public ov45_0222E5B4
	.public ov45_0222E5D4
	.public ov45_0222E688
	.public ov45_0222E6C8
	.public ov45_0222E7CC
	.public ov45_0222E804
	.public ov45_0222E810
	.public ov45_0222E8F4
	.public ov45_0222E91C
	.public ov45_0222E944
	.public ov45_0222E96C
	.public ov45_0222E9BC
	.public ov45_0222E9E0
	.public ov45_0222E9F8
	.public ov45_0222EA2C
	.public ov45_0222EA4C
	.public ov45_0222EA78
	.public ov45_0222EAD4
	.public ov45_0222EB38
	.public ov45_0222EB74
	.public ov45_0222EB94
	.public ov45_0222EBC4
	.public ov45_0222EBF0
	.public ov45_0222EC10
	.public ov45_0222EC3C
	.public ov45_0222EC68
	.public ov45_0222EC7C
	.public ov45_0222EC90
	.public ov45_0222ECA4
	.public ov45_0222ECB8
	.public ov45_0222ECDC
	.public ov45_0222ED7C
	.public ov45_0222EDA8
	.public ov45_0222EDC4
	.public ov45_0222EDF0
	.public ov45_0222EE20
	.public ov45_0222EE50
	.public ov45_0222EE80
	.public ov45_0222EEB8
	.public ov45_0222EEF0
	.public ov45_0222EF4C
	.public ov45_0222EFAC
	.public ov45_0222F028
	.public ov45_0222F154
	.public ov45_0222F1BC
	.public ov45_0222F218
	.public ov45_0222F254
	.public ov45_0222F274
	.public ov45_0222F294
	.public ov45_0222F2D4
	.public ov45_0222F314
	.public ov45_0222F350
	.public ov45_0222F3E8
	.public ov45_0222F430
	.public ov45_0222F464
	.public ov45_0222F484
	.public ov45_0222F4AC
	.public ov45_0222F4D4
	.public ov45_0222F524
	.public ov45_0222F544
	.public ov45_0222F628
	.public ov45_0222F6B0
	.public ov45_0222F70C
	.public ov45_0222F74C
	.public ov45_0222F78C
	.public ov45_0222F7B4
	.public ov45_0222F848
	.public ov45_0222F878
	.public ov45_0222F88C
	.public ov45_0222F898
	.public ov45_0222F8D8
	.public ov45_0222F8FC
	.public ov45_0222F928
	.public ov45_0222F954
	.public ov45_0222F978
	.public ov45_0222F9B8
	.public ov45_0222FA10
	.public ov45_0222FA40
	.public ov45_0222FA74
	.public ov45_0222FAF8
	.public ov45_0222FB24
	.public ov45_0222FB5C
	.public ov45_0222FB84
	.public ov45_0222FBD8
	.public ov45_0222FC44
	.public ov45_0222FCE0
	.public ov45_0222FD50
	.public ov45_0222FDD8
	.public ov45_0222FE84
	.public ov45_0222FEC4
	.public ov45_0222FF40
	.public ov45_0222FF7C
	.public ov45_02230008
	.public ov45_02230050
	.public ov45_02230064
	.public ov45_02230090
	.public ov45_022300B0
	.public ov45_022300DC
	.public ov45_02230108
	.public ov45_02230130
	.public ov45_02230144
	.public ov45_02230164
	.public ov45_022301E0
	.public ov45_0223021C
	.public ov45_0223023C
	.public ov45_022302B0
	.public ov45_022302E4
	.public ov45_02230378
	.public ov45_02230384
	.public ov45_02230394
	.public ov45_022303BC
	.public ov45_022303E4
	.public ov45_022303FC
	.public ov45_0223040C
	.public ov45_02230434
	.public ov45_0223045C
	.public ov45_0223048C
	.public ov45_02230498
	.public ov45_02230638
	.public ov45_02230680
	.public ov45_022306B4
	.public ov45_02230700
	.public ov45_0223070C
	.public ov45_02230884
	.public ov45_0223089C
	.public ov45_022308B8
	.public ov45_022308C0
	.public ov45_022308E4
	.public ov45_02230908
	.public ov45_02230920
	.public ov45_0223093C
	.public ov45_02230978
	.public ov45_02230994
	.public ov45_0223099C
	.public ov45_022309D0
	.public ov45_022309E8
	.public ov45_02230A44
	.public ov45_02230A4C
	.public ov45_02230A5C
	.public ov45_02230A6C
	.public ov45_02230AA4
	.public ov45_02230AB4
	.public ov45_02230ACC
	.public ov45_02230B64
	.public ov45_02230B8C
	.public ov45_02230BFC
	.public ov45_02230C40
	.public ov45_02230CB0
	.public ov45_02230CD8
	.public ov45_02230D20
	.public ov45_02230D5C
	.public ov45_02230DC4
	.public ov45_02230DF4
	.public ov45_02230E28
	.public ov45_02230E64
	.public ov45_02230E78
	.public ov45_02230F94
	.public ov45_02231018
	.public ov45_02254A3C
	.public ov45_02254A60
	.public ov45_02254A84
	.public ov45_02254AC4
	.public ov45_02254B04
	.public ov45_02254B14
	.public ov45_02254B24
	.public ov45_02254B34
	.public ov45_02254B44
	.public ov45_02254B54
	.public ov45_02254B64
	.public ov45_02254B74
	.public ov45_02254B84
	.public ov45_02254B94
	.public ov45_02254BA4
	.public ov45_02254BB4
	.public ov45_02254BC8
	.public ov45_02254BCA
	.public ov45_02254BD2
	.public ov45_02254BDC
	.public ov45_02254BE8
	.public ov45_02254C0C
	.public ov45_02254C30
	.public ov45_02254C34
	.public ov45_02254C38
	.public ov45_02254C3C
	.public ov45_02254C48
	.public ov45_02254C98
	.public ov45_02254E54
	.public ov45_02254E88
	.public ov45_02254EBC
	.public ov45_02254EF0
	.public ov45_02254EF4
	.public ov45_02254F04
	.public ov45_02254F14
	.public ov45_02254F1C
	.public ov45_02254F28

	.public ov45_0222A1F8
	.public ov45_0222A1FC
	.public ov45_0222A210
	.public ov45_0222A22C
	.public ov45_0222A2C8
	.public ov45_0222A404
	.public ov45_0222A414
	.public ov45_0222A424
	.public ov45_0222A430
	.public ov45_0222A498
	.public ov45_0222A4A8
	.public ov45_0222A4B8
	.public ov45_0222A4C8
	.public ov45_0222A920
	.public ov45_0222A99C
	.public ov45_0222A9A0
	.public ov45_0222A9C8
	.public ov45_0222AA54
	.public ov45_0222AB1C
	.public ov45_0222ADA0
	.public ov45_0222B020
	.public ov45_0222B028
	.public ov45_0222B034
	.public ov45_0222B040
	.public ov45_0222B0A4
	.public ov45_0222B0B0
	.public ov45_0222BB58
	.public ov45_0222BCA0
	.public ov45_0222BCA8
	.public ov45_0222BCB8
	.public ov45_0222BD24
	.public ov45_0222BD2C
	.public ov45_0222BD40
	.public ov45_0222BE00
	.public ov45_0222BE48
	.public ov45_0222BE54
	.public ov45_0222BE94
	.public ov45_0222C36C
	.public ov45_0222C3A8
	.public ov45_0222CB3C
	.public ov45_0222CB40
	.public ov45_0222CCDC
	.public ov45_0222CDC0
	.public ov45_0222D448
	.public ov45_0222D8BC
	.public ov45_0222DCE8
	.public ov45_0222DCF4
	.public ov45_0222DCFC
	.public ov45_0222DD08
	.public ov45_0222DD14
	.public ov45_0222DD20
	.public ov45_0222DD2C
	.public ov45_0222DD38
	.public ov45_0222DF50
	.public ov45_0222E598
	.public ov45_0222E59C
	.public ov45_0222E7FC
	.public ov45_0222F7A8
	.public ov45_0222F7B0
	.public ov45_0222FDD4
	.public ov45_02230390
	.public ov45_022306F4
	.public ov45_022308B0
	.public ov45_02230968
	.public ov45_02230974
	.public ov45_022309C4
	.public ov45_02230A58
	.public ov45_02230AC0

	thumb_func_start ov45_0222CDC4
ov45_0222CDC4: ; 0x0222CDC4
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	add r6, r2, #0
	cmp r0, #0
	beq _0222CDD6
	bl GF_AssertFail
_0222CDD6:
	ldrh r2, [r5, #0x3a]
	ldr r1, [r4]
	add r0, r6, #0
	bl OverlayManager_New
	str r0, [r5]
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_0222CDC4


	thumb_func_start ov45_0222CDE4
ov45_0222CDE4: ; 0x0222CDE4
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	cmp r4, #0xd
	blo _0222CDF4
	bl GF_AssertFail
_0222CDF4:
	lsl r3, r4, #2
	add r1, r5, #4
	ldr r4, _0222CE08 ; =ov45_02254E88
	add r1, r1, r3
	ldr r3, [r4, r3]
	add r0, r5, #0
	add r2, r6, #0
	blx r3
	pop {r4, r5, r6, pc}
	nop
_0222CE08: .word ov45_02254E88
	thumb_func_end ov45_0222CDE4


	thumb_func_start ov45_0222CE0C
ov45_0222CE0C: ; 0x0222CE0C
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r0, #0
	cmp r5, #0xd
	blo _0222CE1A
	bl GF_AssertFail
_0222CE1A:
	ldr r1, _0222CE28 ; =_02254E20
	lsl r2, r5, #2
	add r0, r4, #4
	ldr r1, [r1, r2]
	add r0, r0, r2
	blx r1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222CE28: .word _02254E20
	thumb_func_end ov45_0222CE0C


	thumb_func_start ov45_0222CE2C
ov45_0222CE2C: ; 0x0222CE2C
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0xd
	blo _0222CE3A
	bl GF_AssertFail
_0222CE3A:
	ldr r2, _0222CE50 ; =ov45_02254E54
	lsl r3, r4, #2
	add r1, r5, #4
	ldr r2, [r2, r3]
	add r0, r5, #0
	add r1, r1, r3
	blx r2
	add r5, #0x38
	strb r4, [r5]
	pop {r3, r4, r5, pc}
	nop
_0222CE50: .word ov45_02254E54
	thumb_func_end ov45_0222CE2C


	thumb_func_start ov45_0222CE54
ov45_0222CE54: ; 0x0222CE54
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r0, #0
	cmp r5, #0xd
	blo _0222CE62
	bl GF_AssertFail
_0222CE62:
	ldr r2, _0222CE74 ; =ov45_02254EBC
	lsl r3, r5, #2
	add r1, r4, #4
	ldr r2, [r2, r3]
	add r0, r4, #0
	add r1, r1, r3
	blx r2
	pop {r3, r4, r5, pc}
	nop
_0222CE74: .word ov45_02254EBC
	thumb_func_end ov45_0222CE54


	thumb_func_start ov45_0222CE78
ov45_0222CE78: ; 0x0222CE78
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	mov r4, #0
_0222CE80:
	add r0, r6, #0
	bl PlayerProfile_New
	str r0, [r5, #0x20]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0222CE80
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov45_0222CE78


	thumb_func_start ov45_0222CE94
ov45_0222CE94: ; 0x0222CE94
	push {r4, r5, r6, lr}
	mov r4, #0
	add r5, r0, #0
	add r6, r4, #0
_0222CE9C:
	ldr r0, [r5, #0x20]
	bl Heap_Free
	str r6, [r5, #0x20]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0222CE9C
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov45_0222CE94


	thumb_func_start ov45_0222CEB0
ov45_0222CEB0: ; 0x0222CEB0
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	add r6, r0, #0
	add r0, r7, #0
	str r2, [sp]
	bl ov45_0222A5C0
	bl ov45_0222AAC8
	add r1, r6, #0
	str r0, [r6]
	add r0, r7, #0
	add r1, #8
	bl ov45_0222AB38
	add r0, r7, #0
	add r1, r6, #4
	bl ov45_0222A498
	str r7, [r6, #0x30]
	mov r4, #0
	str r4, [r6, #0x1c]
	add r5, r6, #0
_0222CEDE:
	add r1, r6, r4
	ldrb r1, [r1, #4]
	add r0, r7, #0
	bl ov45_0222A578
	cmp r0, #0
	beq _0222CEF4
	ldr r1, [r5, #0x20]
	ldr r2, [sp]
	bl ov45_0222A844
_0222CEF4:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0222CEDE
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222CEB0


	thumb_func_start ov45_0222CF00
ov45_0222CF00: ; 0x0222CF00
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r5, r1, #0
	add r0, r2, #0
	mov r1, #0x20
	bl Heap_Alloc
	str r0, [r5]
	mov r1, #0
	mov r2, #0x20
	bl memset
	ldr r1, [r5]
	ldr r0, [r4, #0x40]
	str r0, [r1]
	ldr r0, [r4, #0x3c]
	str r0, [r1, #0x1c]
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222CF00


	thumb_func_start ov45_0222CF24
ov45_0222CF24: ; 0x0222CF24
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	bne _0222CF32
	bl GF_AssertFail
_0222CF32:
	ldr r0, [r4]
	bl Heap_Free
	mov r0, #0
	str r0, [r4]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_0222CF24


	thumb_func_start ov45_0222CF40
ov45_0222CF40: ; 0x0222CF40
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	ldr r4, [r6]
	ldr r0, [r5, #0x3c]
	bl ov45_0222AD2C
	str r0, [r4, #4]
	ldr r0, [r5, #0x3c]
	bl ov45_0222AD3C
	str r0, [r4, #8]
	ldr r2, _0222CF64 ; =ov45_02254B94
	add r0, r5, #0
	add r1, r6, #0
	bl ov45_0222CDC4
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222CF64: .word ov45_02254B94
	thumb_func_end ov45_0222CF40


	thumb_func_start ov45_0222CF68
ov45_0222CF68: ; 0x0222CF68
	push {r3, lr}
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	cmp r1, #0xa
	bhi _0222CFEC
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0222CF7E: ; jump table
	.short _0222CF94 - _0222CF7E - 2 ; case 0
	.short _0222CF9C - _0222CF7E - 2 ; case 1
	.short _0222CFA4 - _0222CF7E - 2 ; case 2
	.short _0222CFBC - _0222CF7E - 2 ; case 3
	.short _0222CFC4 - _0222CF7E - 2 ; case 4
	.short _0222CFCC - _0222CF7E - 2 ; case 5
	.short _0222CFAC - _0222CF7E - 2 ; case 6
	.short _0222CFB4 - _0222CF7E - 2 ; case 7
	.short _0222CFD4 - _0222CF7E - 2 ; case 8
	.short _0222CFDC - _0222CF7E - 2 ; case 9
	.short _0222CFE4 - _0222CF7E - 2 ; case 10
_0222CF94:
	mov r1, #9
	bl ov45_0222CE2C
	b _0222CFF0
_0222CF9C:
	mov r1, #1
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFA4:
	mov r1, #2
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFAC:
	mov r1, #3
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFB4:
	mov r1, #4
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFBC:
	mov r1, #6
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFC4:
	mov r1, #7
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFCC:
	mov r1, #8
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFD4:
	mov r1, #0xa
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFDC:
	mov r1, #0xb
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFE4:
	mov r1, #0xc
	bl ov45_0222CE2C
	b _0222CFF0
_0222CFEC:
	bl GF_AssertFail
_0222CFF0:
	mov r0, #0
	pop {r3, pc}
	thumb_func_end ov45_0222CF68


	thumb_func_start ov45_0222CFF4
ov45_0222CFF4: ; 0x0222CFF4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r0, r2, #0
	mov r1, #0x10
	bl Heap_Alloc
	str r0, [r4]
	mov r2, #0x10
	mov r1, #0
_0222D008:
	strb r1, [r0]
	add r0, r0, #1
	sub r2, r2, #1
	bne _0222D008
	ldr r1, [r4]
	ldr r0, [r5, #0x40]
	str r0, [r1, #4]
	ldr r0, [r5, #0x3c]
	str r0, [r1, #0xc]
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222CFF4


	thumb_func_start ov45_0222D01C
ov45_0222D01C: ; 0x0222D01C
	ldr r3, _0222D024 ; =Heap_Free
	ldr r0, [r0]
	bx r3
	nop
_0222D024: .word Heap_Free
	thumb_func_end ov45_0222D01C


	thumb_func_start ov45_0222D028
ov45_0222D028: ; 0x0222D028
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	ldr r4, [r6]
	ldr r0, [r5, #0x3c]
	bl ov45_0222A214
	str r0, [r4]
	ldr r0, [r5, #0x3c]
	bl ov45_0222A22C
	ldr r0, [r0]
	ldr r2, _0222D050 ; =ov45_02254B84
	str r0, [r4, #8]
	add r0, r5, #0
	add r1, r6, #0
	bl ov45_0222CDC4
	pop {r4, r5, r6, pc}
	nop
_0222D050: .word ov45_02254B84
	thumb_func_end ov45_0222D028


	thumb_func_start ov45_0222D054
ov45_0222D054: ; 0x0222D054
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x3c]
	bl ov45_0222A33C
	cmp r0, #0
	beq _0222D06C
	add r0, r4, #0
	mov r1, #0xa
	bl ov45_0222CE2C
	b _0222D074
_0222D06C:
	add r0, r4, #0
	mov r1, #0
	bl ov45_0222CE2C
_0222D074:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov45_0222D054


	thumb_func_start ov45_0222D078
ov45_0222D078: ; 0x0222D078
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r5, r1, #0
	add r0, r2, #0
	mov r1, #0xc
	bl Heap_Alloc
	str r0, [r5]
	mov r1, #0
	strb r1, [r0]
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	strb r1, [r0, #4]
	strb r1, [r0, #5]
	strb r1, [r0, #6]
	strb r1, [r0, #7]
	strb r1, [r0, #8]
	strb r1, [r0, #9]
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	ldr r5, [r5]
	ldr r0, [r4, #0x3c]
	bl ov45_0222A210
	str r0, [r5]
	ldr r0, [r4, #0x3c]
	bl ov45_0222A22C
	str r0, [r5, #4]
	ldr r0, [r4, #0x3c]
	str r0, [r5, #8]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222D078


	thumb_func_start ov45_0222D0BC
ov45_0222D0BC: ; 0x0222D0BC
	ldr r3, _0222D0C4 ; =Heap_Free
	ldr r0, [r0]
	bx r3
	nop
_0222D0C4: .word Heap_Free
	thumb_func_end ov45_0222D0BC


	thumb_func_start ov45_0222D0C8
ov45_0222D0C8: ; 0x0222D0C8
	ldr r3, _0222D0D0 ; =ov45_0222CDC4
	ldr r2, _0222D0D4 ; =ov45_02254B74
	bx r3
	nop
_0222D0D0: .word ov45_0222CDC4
_0222D0D4: .word ov45_02254B74
	thumb_func_end ov45_0222D0C8


	thumb_func_start ov45_0222D0D8
ov45_0222D0D8: ; 0x0222D0D8
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x3c]
	bl ov45_0222A33C
	cmp r0, #0
	beq _0222D0F0
	add r0, r4, #0
	mov r1, #0xa
	bl ov45_0222CE2C
	b _0222D0F8
_0222D0F0:
	add r0, r4, #0
	mov r1, #0
	bl ov45_0222CE2C
_0222D0F8:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov45_0222D0D8


	thumb_func_start ov45_0222D0FC
ov45_0222D0FC: ; 0x0222D0FC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r0, r2, #0
	mov r1, #0x14
	bl Heap_Alloc
	str r0, [r4]
	mov r2, #0x14
	mov r1, #0
_0222D110:
	strb r1, [r0]
	add r0, r0, #1
	sub r2, r2, #1
	bne _0222D110
	ldr r1, [r4]
	ldr r0, [r5, #0x40]
	str r0, [r1]
	ldr r0, [r5, #0x3c]
	str r0, [r1, #4]
	add r0, r5, #0
	add r0, #0x39
	ldrb r0, [r0]
	str r0, [r1, #8]
	ldr r0, [r5, #0x44]
	str r0, [r1, #0xc]
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222D0FC


	thumb_func_start ov45_0222D130
ov45_0222D130: ; 0x0222D130
	ldr r3, _0222D138 ; =Heap_Free
	ldr r0, [r0]
	bx r3
	nop
_0222D138: .word Heap_Free
	thumb_func_end ov45_0222D130


	thumb_func_start ov45_0222D13C
ov45_0222D13C: ; 0x0222D13C
	ldr r3, _0222D144 ; =ov45_0222CDC4
	ldr r2, _0222D148 ; =ov45_02254B64
	bx r3
	nop
_0222D144: .word ov45_0222CDC4
_0222D148: .word ov45_02254B64
	thumb_func_end ov45_0222D13C


	thumb_func_start ov45_0222D14C
ov45_0222D14C: ; 0x0222D14C
	push {r3, lr}
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	cmp r1, #0
	bne _0222D15A
	mov r0, #1
	pop {r3, pc}
_0222D15A:
	mov r1, #0
	bl ov45_0222CE2C
	mov r0, #0
	pop {r3, pc}
	thumb_func_end ov45_0222D14C


	thumb_func_start ov45_0222D164
ov45_0222D164: ; 0x0222D164
	push {r4, r5, r6, lr}
	add r6, r2, #0
	add r5, r0, #0
	add r4, r1, #0
	add r0, r6, #0
	mov r1, #0x3c
	bl Heap_Alloc
	str r0, [r4]
	mov r1, #0
	mov r2, #0x3c
	bl memset
	ldr r0, [r4]
	mov r2, #0
	add r1, r0, #0
	add r1, #0x38
	strb r2, [r1]
	add r1, r0, #0
	mov r2, #1
	add r1, #0x39
	strb r2, [r1]
	ldr r1, [r5, #0x40]
	str r1, [r0, #0x34]
	add r1, r6, #0
	bl ov45_0222CE78
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_0222D164


	thumb_func_start ov45_0222D19C
ov45_0222D19C: ; 0x0222D19C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	bl ov45_0222CE94
	ldr r0, [r4]
	bl Heap_Free
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_0222D19C


	thumb_func_start ov45_0222D1B0
ov45_0222D1B0: ; 0x0222D1B0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r0, _0222D1D4 ; =FS_OVERLAY_ID(OVY_90)
	mov r1, #2
	bl HandleLoadOverlay
	ldrh r2, [r5, #0x3a]
	ldr r0, [r4]
	ldr r1, [r5, #0x3c]
	bl ov45_0222CEB0
	ldr r2, _0222D1D8 ; =ov45_02254B54
	add r0, r5, #0
	add r1, r4, #0
	bl ov45_0222CDC4
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222D1D4: .word FS_OVERLAY_ID(OVY_90)
_0222D1D8: .word ov45_02254B54
	thumb_func_end ov45_0222D1B0


	thumb_func_start ov45_0222D1DC
ov45_0222D1DC: ; 0x0222D1DC
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, _0222D208 ; =FS_OVERLAY_ID(OVY_90)
	add r5, r1, #0
	bl UnloadOverlayByID
	ldr r5, [r5]
	ldr r0, [r4, #0x3c]
	ldr r1, [r5, #0x1c]
	bl ov45_0222A430
	ldr r0, [r4, #0x3c]
	ldr r1, [r5]
	bl ov45_0222A72C
	add r0, r4, #0
	mov r1, #0
	bl ov45_0222CE2C
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0222D208: .word FS_OVERLAY_ID(OVY_90)
	thumb_func_end ov45_0222D1DC


	thumb_func_start ov45_0222D20C
ov45_0222D20C: ; 0x0222D20C
	push {r4, r5, r6, lr}
	add r6, r2, #0
	add r5, r0, #0
	add r4, r1, #0
	add r0, r6, #0
	mov r1, #0x40
	bl Heap_Alloc
	str r0, [r4]
	mov r1, #0
	mov r2, #0x40
	bl memset
	ldr r0, [r4]
	mov r1, #0
	str r1, [r0, #0x3c]
	mov r1, #1
	str r1, [r0, #0x38]
	ldr r1, [r5, #0x40]
	str r1, [r0, #0x34]
	add r1, r6, #0
	bl ov45_0222CE78
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_0222D20C


	thumb_func_start ov45_0222D23C
ov45_0222D23C: ; 0x0222D23C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	bl ov45_0222CE94
	ldr r0, [r4]
	bl Heap_Free
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_0222D23C


	thumb_func_start ov45_0222D250
ov45_0222D250: ; 0x0222D250
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r0, _0222D274 ; =FS_OVERLAY_ID(OVY_90)
	mov r1, #2
	bl HandleLoadOverlay
	ldrh r2, [r5, #0x3a]
	ldr r0, [r4]
	ldr r1, [r5, #0x3c]
	bl ov45_0222CEB0
	ldr r2, _0222D278 ; =ov45_02254BA4
	add r0, r5, #0
	add r1, r4, #0
	bl ov45_0222CDC4
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222D274: .word FS_OVERLAY_ID(OVY_90)
_0222D278: .word ov45_02254BA4
	thumb_func_end ov45_0222D250


	thumb_func_start ov45_0222D27C
ov45_0222D27C: ; 0x0222D27C
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, _0222D2A8 ; =FS_OVERLAY_ID(OVY_90)
	add r5, r1, #0
	bl UnloadOverlayByID
	ldr r5, [r5]
	ldr r0, [r4, #0x3c]
	ldr r1, [r5, #0x1c]
	bl ov45_0222A430
	ldr r0, [r4, #0x3c]
	ldr r1, [r5]
	bl ov45_0222A72C
	add r0, r4, #0
	mov r1, #0
	bl ov45_0222CE2C
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0222D2A8: .word FS_OVERLAY_ID(OVY_90)
	thumb_func_end ov45_0222D27C


	thumb_func_start ov45_0222D2AC
ov45_0222D2AC: ; 0x0222D2AC
	push {r4, r5, r6, lr}
	add r6, r2, #0
	add r5, r0, #0
	add r4, r1, #0
	add r0, r6, #0
	mov r1, #0x3c
	bl Heap_Alloc
	str r0, [r4]
	mov r1, #0
	mov r2, #0x3c
	bl memset
	ldr r0, [r4]
	mov r2, #0
	add r1, r0, #0
	add r1, #0x38
	strb r2, [r1]
	add r1, r0, #0
	mov r2, #1
	add r1, #0x39
	strb r2, [r1]
	ldr r1, [r5, #0x40]
	str r1, [r0, #0x34]
	add r1, r6, #0
	bl ov45_0222CE78
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_0222D2AC


	thumb_func_start ov45_0222D2E4
ov45_0222D2E4: ; 0x0222D2E4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	bl ov45_0222CE94
	ldr r0, [r4]
	bl Heap_Free
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_0222D2E4


	thumb_func_start ov45_0222D2F8
ov45_0222D2F8: ; 0x0222D2F8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r0, _0222D31C ; =FS_OVERLAY_ID(OVY_90)
	mov r1, #2
	bl HandleLoadOverlay
	ldrh r2, [r5, #0x3a]
	ldr r0, [r4]
	ldr r1, [r5, #0x3c]
	bl ov45_0222CEB0
	ldr r2, _0222D320 ; =ov45_02254B34
	add r0, r5, #0
	add r1, r4, #0
	bl ov45_0222CDC4
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222D31C: .word FS_OVERLAY_ID(OVY_90)
_0222D320: .word ov45_02254B34
	thumb_func_end ov45_0222D2F8


	thumb_func_start ov45_0222D324
ov45_0222D324: ; 0x0222D324
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, _0222D350 ; =FS_OVERLAY_ID(OVY_90)
	add r5, r1, #0
	bl UnloadOverlayByID
	ldr r5, [r5]
	ldr r0, [r4, #0x3c]
	ldr r1, [r5, #0x1c]
	bl ov45_0222A430
	ldr r0, [r4, #0x3c]
	ldr r1, [r5]
	bl ov45_0222A72C
	add r0, r4, #0
	mov r1, #0
	bl ov45_0222CE2C
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0222D350: .word FS_OVERLAY_ID(OVY_90)
	thumb_func_end ov45_0222D324


	thumb_func_start ov45_0222D354
ov45_0222D354: ; 0x0222D354
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r0, r2, #0
	mov r1, #8
	bl Heap_Alloc
	str r0, [r4]
	mov r1, #0
	strb r1, [r0]
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	strb r1, [r0, #4]
	strb r1, [r0, #5]
	strb r1, [r0, #6]
	strb r1, [r0, #7]
	ldr r1, [r5, #0x3c]
	ldr r0, [r4]
	str r1, [r0]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222D354


	thumb_func_start ov45_0222D380
ov45_0222D380: ; 0x0222D380
	ldr r3, _0222D388 ; =Heap_Free
	ldr r0, [r0]
	bx r3
	nop
_0222D388: .word Heap_Free
	thumb_func_end ov45_0222D380


	thumb_func_start ov45_0222D38C
ov45_0222D38C: ; 0x0222D38C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x3c]
	bl ov45_0222A33C
	cmp r0, #0
	beq _0222D3A4
	add r0, r4, #0
	mov r1, #0xa
	bl ov45_0222CE2C
	b _0222D3AC
_0222D3A4:
	add r0, r4, #0
	mov r1, #0
	bl ov45_0222CE2C
_0222D3AC:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov45_0222D38C


	thumb_func_start ov45_0222D3B0
ov45_0222D3B0: ; 0x0222D3B0
	ldr r2, [r1]
	mov r3, #0
	strb r3, [r2, #4]
	ldr r3, _0222D3BC ; =ov45_0222CDC4
	ldr r2, _0222D3C0 ; =ov45_02254B24
	bx r3
	.balign 4, 0
_0222D3BC: .word ov45_0222CDC4
_0222D3C0: .word ov45_02254B24
	thumb_func_end ov45_0222D3B0


	thumb_func_start ov45_0222D3C4
ov45_0222D3C4: ; 0x0222D3C4
	ldr r2, [r1]
	mov r3, #1
	strb r3, [r2, #4]
	ldr r3, _0222D3D0 ; =ov45_0222CDC4
	ldr r2, _0222D3D4 ; =ov45_02254B14
	bx r3
	.balign 4, 0
_0222D3D0: .word ov45_0222CDC4
_0222D3D4: .word ov45_02254B14
	thumb_func_end ov45_0222D3C4


	thumb_func_start ov45_0222D3D8
ov45_0222D3D8: ; 0x0222D3D8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r0, r2, #0
	mov r1, #0xc
	bl Heap_Alloc
	str r0, [r4]
	mov r1, #0
	strb r1, [r0]
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	strb r1, [r0, #4]
	strb r1, [r0, #5]
	strb r1, [r0, #6]
	strb r1, [r0, #7]
	strb r1, [r0, #8]
	strb r1, [r0, #9]
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	ldr r1, [r4]
	ldr r0, [r5, #0x40]
	str r0, [r1]
	ldr r0, [r5, #0x3c]
	str r0, [r1, #4]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222D3D8


	thumb_func_start ov45_0222D410
ov45_0222D410: ; 0x0222D410
	ldr r3, _0222D418 ; =Heap_Free
	ldr r0, [r0]
	bx r3
	nop
_0222D418: .word Heap_Free
	thumb_func_end ov45_0222D410


	thumb_func_start ov45_0222D41C
ov45_0222D41C: ; 0x0222D41C
	ldr r3, _0222D424 ; =ov45_0222D434
	mov r2, #0
	bx r3
	nop
_0222D424: .word ov45_0222D434
	thumb_func_end ov45_0222D41C


	thumb_func_start ov45_0222D428
ov45_0222D428: ; 0x0222D428
	ldr r3, _0222D430 ; =ov45_0222D434
	mov r2, #1
	bx r3
	nop
_0222D430: .word ov45_0222D434
	thumb_func_end ov45_0222D428


	thumb_func_start ov45_0222D434
ov45_0222D434: ; 0x0222D434
	ldr r3, [r1]
	str r2, [r3, #8]
	ldr r3, _0222D440 ; =ov45_0222CDC4
	ldr r2, _0222D444 ; =ov45_02254B04
	bx r3
	nop
_0222D440: .word ov45_0222CDC4
_0222D444: .word ov45_02254B04
	thumb_func_end ov45_0222D434

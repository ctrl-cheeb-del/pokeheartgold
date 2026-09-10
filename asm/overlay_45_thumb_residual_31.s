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

	thumb_func_start ov45_0222DF58
ov45_0222DF58: ; 0x0222DF58
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0x14
	blo _0222DF66
	bl GF_AssertFail
_0222DF66:
	add r5, #0x52
	ldrh r0, [r5]
	cmp r0, r4
	bne _0222DF72
	mov r0, #1
	pop {r3, r4, r5, pc}
_0222DF72:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222DF58


	thumb_func_start ov45_0222DF78
ov45_0222DF78: ; 0x0222DF78
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov r2, #0x75
	add r6, r1, #0
	mov r1, #0
	lsl r2, r2, #2
	str r0, [sp]
	bl memset
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp]
	mov r7, #8
	str r0, [sp, #4]
_0222DF94:
	ldr r5, [sp, #4]
	mov r4, #0
_0222DF98:
	add r0, r7, #0
	add r1, r6, #0
	bl String_New
	str r0, [r5, #0x10]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0222DF98
	ldr r0, [sp, #4]
	add r0, #0x34
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #8
	blt _0222DF94
	mov r2, #0x1a
	lsl r2, r2, #4
	ldr r0, [sp]
	add r1, r2, #0
	add r3, r0, r2
	add r1, #0x2c
	str r3, [r0, r1]
	add r2, #0x30
	str r3, [r0, r2]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222DF78


	thumb_func_start ov45_0222DFD0
ov45_0222DFD0: ; 0x0222DFD0
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	mov r7, #0
	add r6, r0, #0
_0222DFD8:
	mov r4, #0
	add r5, r6, #0
_0222DFDC:
	ldr r0, [r5, #0x10]
	bl String_Delete
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0222DFDC
	add r7, r7, #1
	add r6, #0x34
	cmp r7, #8
	blt _0222DFD8
	mov r2, #0x75
	ldr r0, [sp]
	mov r1, #0
	lsl r2, r2, #2
	bl memset
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222DFD0


	thumb_func_start ov45_0222E000
ov45_0222E000: ; 0x0222E000
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r1, [r6, r0]
	sub r0, #0x2c
	add r4, r6, r0
	cmp r1, r4
	beq _0222E038
	mov r7, #0
_0222E014:
	ldr r5, [r1, #0x2c]
	mov r0, #0x2a
	strh r7, [r1, #0x28]
	ldrsh r0, [r1, r0]
	sub r0, r0, #1
	cmp r0, #0
	ble _0222E02C
	mov r0, #0x2a
	ldrsh r0, [r1, r0]
	sub r0, r0, #1
	strh r0, [r1, #0x2a]
	b _0222E032
_0222E02C:
	add r0, r6, #0
	bl ov45_0222E0CC
_0222E032:
	add r1, r5, #0
	cmp r5, r4
	bne _0222E014
_0222E038:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222E000


	thumb_func_start ov45_0222E03C
ov45_0222E03C: ; 0x0222E03C
	mov r1, #0x73
	lsl r1, r1, #2
	ldr r3, _0222E048 ; =ov45_0222E0CC
	ldr r1, [r0, r1]
	bx r3
	nop
_0222E048: .word ov45_0222E0CC
	thumb_func_end ov45_0222E03C


	thumb_func_start ov45_0222E04C
ov45_0222E04C: ; 0x0222E04C
	push {r3, r4, r5, lr}
	mov r4, #0
	add r3, r4, #0
	add r5, r0, #0
_0222E054:
	ldr r2, [r5, #0x2c]
	cmp r2, #0
	bne _0222E062
	mov r2, #0x34
	mul r2, r3
	add r4, r0, r2
	b _0222E06A
_0222E062:
	add r3, r3, #1
	add r5, #0x34
	cmp r3, #8
	blt _0222E054
_0222E06A:
	cmp r4, #0
	bne _0222E08E
	mov r2, #0
	add r5, r0, #0
_0222E072:
	ldrh r3, [r5, #0x28]
	cmp r3, r1
	blo _0222E086
	mov r1, #0x34
	mul r1, r2
	add r4, r0, r1
	add r1, r4, #0
	bl ov45_0222E0CC
	b _0222E08E
_0222E086:
	add r2, r2, #1
	add r5, #0x34
	cmp r2, #8
	blt _0222E072
_0222E08E:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222E04C


	thumb_func_start ov45_0222E094
ov45_0222E094: ; 0x0222E094
	ldr r2, [r0, #0x2c]
	str r2, [r1, #0x2c]
	str r0, [r1, #0x30]
	str r1, [r0, #0x2c]
	ldr r0, [r1, #0x2c]
	str r1, [r0, #0x30]
	bx lr
	.balign 4, 0
	thumb_func_end ov45_0222E094


	thumb_func_start ov45_0222E0A4
ov45_0222E0A4: ; 0x0222E0A4
	push {r4, lr}
	mov r2, #0x1d
	lsl r2, r2, #4
	ldr r3, [r0, r2]
	sub r2, #0x30
	add r2, r0, r2
	cmp r3, r2
	beq _0222E0C2
	ldrh r4, [r1, #0x28]
_0222E0B6:
	ldrh r0, [r3, #0x28]
	cmp r0, r4
	blo _0222E0C2
	ldr r3, [r3, #0x30]
	cmp r3, r2
	bne _0222E0B6
_0222E0C2:
	add r0, r3, #0
	bl ov45_0222E094
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_0222E0A4


	thumb_func_start ov45_0222E0CC
ov45_0222E0CC: ; 0x0222E0CC
	ldr r2, [r1, #0x2c]
	ldr r0, [r1, #0x30]
	str r2, [r0, #0x2c]
	ldr r2, [r1, #0x30]
	ldr r0, [r1, #0x2c]
	str r2, [r0, #0x30]
	mov r0, #0
	str r0, [r1, #0x30]
	str r0, [r1, #0x2c]
	bx lr
	thumb_func_end ov45_0222E0CC


	thumb_func_start ov45_0222E0E0
ov45_0222E0E0: ; 0x0222E0E0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [sp, #0x40]
	add r4, r1, #0
	add r6, r2, #0
	add r7, r3, #0
	cmp r0, #9
	blo _0222E0F4
	bl GF_AssertFail
_0222E0F4:
	ldr r0, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x38]
	strh r0, [r5, #0x2a]
	ldr r0, [sp, #0x3c]
	strh r0, [r5, #0x28]
	str r4, [r5, #4]
	str r6, [r5, #8]
	str r7, [r5, #0xc]
	add r0, sp, #8
	ldrh r1, [r0, #0x20]
	strh r1, [r5, #0x20]
	ldrh r1, [r0, #0x24]
	strh r1, [r5, #0x22]
	ldrh r1, [r0, #0x28]
	strh r1, [r5, #0x24]
	ldrh r0, [r0, #0x2c]
	strh r0, [r5, #0x26]
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _0222E124
	ldr r1, [r5, #0x10]
	bl PlayerName_FlatToString
_0222E124:
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _0222E130
	ldr r1, [r5, #0x14]
	bl PlayerName_FlatToString
_0222E130:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _0222E13C
	ldr r1, [r5, #0x18]
	bl PlayerName_FlatToString
_0222E13C:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _0222E148
	ldr r1, [r5, #0x1c]
	bl PlayerName_FlatToString
_0222E148:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222E0E0


	thumb_func_start ov45_0222E14C
ov45_0222E14C: ; 0x0222E14C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, _0222E19C ; =gGameLanguage
	add r6, r2, #0
	ldrb r4, [r0]
	mov r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	mov r1, #0
	add r7, r3, #0
	ldr r2, [r5, #0x10]
	add r0, r6, #0
	add r3, r1, #0
	bl BufferString
	mov r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	ldr r2, [r5, #0x14]
	add r0, r6, #0
	mov r3, #0
	bl BufferString
	add r0, r7, #0
	mov r1, #7
	bl NewString_ReadMsgData
	add r4, r0, #0
	ldr r1, [sp, #0x20]
	add r0, r6, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	add r0, r4, #0
	bl String_Delete
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222E19C: .word gGameLanguage
	thumb_func_end ov45_0222E14C


	thumb_func_start ov45_0222E1A0
ov45_0222E1A0: ; 0x0222E1A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, _0222E1FC ; =gGameLanguage
	add r6, r2, #0
	ldrb r4, [r0]
	mov r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	mov r1, #0
	add r7, r3, #0
	ldr r2, [r5, #0x10]
	add r0, r6, #0
	add r3, r1, #0
	bl BufferString
	mov r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	ldr r2, [r5, #0x14]
	add r0, r6, #0
	mov r3, #0
	bl BufferString
	ldr r2, [r5, #4]
	add r0, r6, #0
	mov r1, #2
	bl BufferWiFiPlazaInstrumentName
	add r0, r7, #0
	mov r1, #8
	bl NewString_ReadMsgData
	add r4, r0, #0
	ldr r1, [sp, #0x20]
	add r0, r6, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	add r0, r4, #0
	bl String_Delete
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222E1FC: .word gGameLanguage
	thumb_func_end ov45_0222E1A0


	thumb_func_start ov45_0222E200
ov45_0222E200: ; 0x0222E200
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r4, r2, #0
	ldr r2, [r5, #4]
	add r0, r4, #0
	mov r1, #0
	add r7, r3, #0
	bl BufferWiFiPlazaActivityName
	ldr r0, [r5, #0xc]
	cmp r0, #1
	bne _0222E2EE
	ldr r0, [r5, #8]
	cmp r0, #2
	beq _0222E266
	cmp r0, #3
	beq _0222E22A
	cmp r0, #4
	beq _0222E290
	b _0222E2DE
_0222E22A:
	ldr r0, _0222E338 ; =gGameLanguage
	mov r1, #1
	ldrb r6, [r0]
	str r1, [sp]
	add r0, r4, #0
	str r6, [sp, #4]
	ldr r2, [r5, #0x10]
	mov r3, #0
	bl BufferString
	mov r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r2, [r5, #0x14]
	add r0, r4, #0
	mov r1, #2
	mov r3, #0
	bl BufferString
	mov r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r2, [r5, #0x18]
	add r0, r4, #0
	mov r1, #3
	mov r3, #0
	bl BufferString
	mov r1, #0x12
	b _0222E2E4
_0222E266:
	ldr r0, _0222E338 ; =gGameLanguage
	mov r1, #1
	ldrb r6, [r0]
	str r1, [sp]
	add r0, r4, #0
	str r6, [sp, #4]
	ldr r2, [r5, #0x10]
	mov r3, #0
	bl BufferString
	mov r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r2, [r5, #0x14]
	add r0, r4, #0
	mov r1, #2
	mov r3, #0
	bl BufferString
	mov r1, #0x13
	b _0222E2E4
_0222E290:
	ldr r0, _0222E338 ; =gGameLanguage
	mov r1, #1
	ldrb r6, [r0]
	str r1, [sp]
	add r0, r4, #0
	str r6, [sp, #4]
	ldr r2, [r5, #0x10]
	mov r3, #0
	bl BufferString
	mov r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r2, [r5, #0x14]
	add r0, r4, #0
	mov r1, #2
	mov r3, #0
	bl BufferString
	mov r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r2, [r5, #0x18]
	add r0, r4, #0
	mov r1, #3
	mov r3, #0
	bl BufferString
	mov r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	ldr r2, [r5, #0x1c]
	add r0, r4, #0
	mov r1, #4
	mov r3, #0
	bl BufferString
	mov r1, #6
	b _0222E2E4
_0222E2DE:
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222E2E4:
	add r0, r7, #0
	bl NewString_ReadMsgData
	add r5, r0, #0
	b _0222E320
_0222E2EE:
	ldr r0, _0222E338 ; =gGameLanguage
	mov r1, #1
	ldrb r0, [r0]
	str r1, [sp]
	mov r3, #0
	str r0, [sp, #4]
	ldr r2, [r5, #0x10]
	add r0, r4, #0
	bl BufferString
	mov r3, #1
	str r3, [sp]
	str r3, [sp, #4]
	ldr r5, [r5, #8]
	mov r2, #4
	add r0, r4, #0
	mov r1, #2
	sub r2, r2, r5
	bl BufferIntegerAsString
	add r0, r7, #0
	mov r1, #5
	bl NewString_ReadMsgData
	add r5, r0, #0
_0222E320:
	ldr r1, [sp, #0x20]
	add r0, r4, #0
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222E338: .word gGameLanguage
	thumb_func_end ov45_0222E200


	thumb_func_start ov45_0222E33C
ov45_0222E33C: ; 0x0222E33C
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	add r4, r2, #0
	ldr r2, [r5, #4]
	add r0, r4, #0
	mov r1, #0
	add r6, r3, #0
	bl BufferWiFiPlazaActivityName
	ldr r0, _0222E398 ; =gGameLanguage
	mov r1, #1
	ldrb r0, [r0]
	str r1, [sp]
	mov r3, #0
	str r0, [sp, #4]
	ldr r2, [r5, #0x10]
	add r0, r4, #0
	bl BufferString
	mov r3, #1
	str r3, [sp]
	str r3, [sp, #4]
	ldr r5, [r5, #8]
	mov r2, #8
	add r0, r4, #0
	mov r1, #2
	sub r2, r2, r5
	bl BufferIntegerAsString
	add r0, r6, #0
	mov r1, #9
	bl NewString_ReadMsgData
	add r5, r0, #0
	ldr r1, [sp, #0x18]
	add r0, r4, #0
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	mov r0, #1
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222E398: .word gGameLanguage
	thumb_func_end ov45_0222E33C


	thumb_func_start ov45_0222E39C
ov45_0222E39C: ; 0x0222E39C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r0, #0
	ldr r1, [r6, #4]
	add r7, r2, #0
	mov r4, #0
	str r3, [sp, #8]
	cmp r1, #0
	bls _0222E3D4
	ldr r0, _0222E410 ; =gGameLanguage
	add r5, r6, #0
	ldrb r0, [r0]
	str r0, [sp, #0xc]
_0222E3B6:
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #0xc]
	add r1, r4, #0
	str r0, [sp, #4]
	ldr r2, [r5, #0x10]
	add r0, r7, #0
	mov r3, #0
	bl BufferString
	ldr r1, [r6, #4]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r1
	blo _0222E3B6
_0222E3D4:
	ldrb r0, [r6]
	cmp r0, #4
	bne _0222E3E4
	add r0, r7, #0
	mov r2, #5
	bl BufferWiFiPlazaActivityName
	b _0222E3EC
_0222E3E4:
	add r0, r7, #0
	mov r2, #6
	bl BufferWiFiPlazaActivityName
_0222E3EC:
	ldr r2, [r6, #4]
	mov r1, #0xe
	ldr r0, [sp, #8]
	sub r1, r1, r2
	bl NewString_ReadMsgData
	add r4, r0, #0
	ldr r1, [sp, #0x28]
	add r0, r7, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	add r0, r4, #0
	bl String_Delete
	mov r0, #1
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222E410: .word gGameLanguage
	thumb_func_end ov45_0222E39C


	thumb_func_start ov45_0222E414
ov45_0222E414: ; 0x0222E414
	push {r3, r4, r5, lr}
	ldr r0, [r0, #8]
	add r4, r2, #0
	add r5, r3, #0
	cmp r0, #4
	bhi _0222E464
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222E42C: ; jump table
	.short _0222E436 - _0222E42C - 2 ; case 0
	.short _0222E444 - _0222E42C - 2 ; case 1
	.short _0222E452 - _0222E42C - 2 ; case 2
	.short _0222E464 - _0222E42C - 2 ; case 3
	.short _0222E460 - _0222E42C - 2 ; case 4
_0222E436:
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	bl BufferWiFiPlazaEventName
	mov r1, #0xf
	b _0222E468
_0222E444:
	add r0, r4, #0
	mov r1, #0
	mov r2, #1
	bl BufferWiFiPlazaEventName
	mov r1, #0x14
	b _0222E468
_0222E452:
	add r0, r4, #0
	mov r1, #0
	mov r2, #2
	bl BufferWiFiPlazaEventName
	mov r1, #0x10
	b _0222E468
_0222E460:
	mov r1, #0x11
	b _0222E468
_0222E464:
	mov r0, #0
	pop {r3, r4, r5, pc}
_0222E468:
	add r0, r5, #0
	bl NewString_ReadMsgData
	add r5, r0, #0
	ldr r1, [sp, #0x10]
	add r0, r4, #0
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	mov r0, #1
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222E414


	thumb_func_start ov45_0222E484
ov45_0222E484: ; 0x0222E484
	push {r3, lr}
	ldr r0, [r0, #4]
	cmp r0, #0x14
	blo _0222E490
	mov r0, #0
	pop {r3, pc}
_0222E490:
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _0222E49A
	mov r0, #0
	pop {r3, pc}
_0222E49A:
	ldr r2, [sp, #8]
	add r0, r3, #0
	mov r1, #0x15
	bl ReadMsgDataIntoString
	mov r0, #1
	pop {r3, pc}
	thumb_func_end ov45_0222E484


	thumb_func_start ov45_0222E4A8
ov45_0222E4A8: ; 0x0222E4A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r0, #0
	ldr r0, [r6, #4]
	ldr r1, [r6, #8]
	add r7, r2, #0
	str r3, [sp, #8]
	bl ov45_0222E5B4
	cmp r0, #0
	bne _0222E4C4
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222E4C4:
	ldr r2, [r6, #4]
	add r0, r7, #0
	mov r1, #0
	bl BufferWiFiPlazaActivityName
	ldr r1, [r6, #8]
	mov r4, #0
	cmp r1, #0
	bls _0222E4FC
	ldr r0, _0222E534 ; =gGameLanguage
	add r5, r6, #0
	ldrb r0, [r0]
	str r0, [sp, #0xc]
_0222E4DE:
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #0xc]
	add r1, r4, #1
	str r0, [sp, #4]
	ldr r2, [r5, #0x10]
	add r0, r7, #0
	mov r3, #0
	bl BufferString
	ldr r1, [r6, #8]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r1
	blo _0222E4DE
_0222E4FC:
	ldr r0, [r6, #4]
	cmp r0, #1
	bhi _0222E510
	lsl r2, r1, #1
	ldr r1, _0222E538 ; =ov45_02254BCA
	ldr r0, [sp, #8]
	ldrh r1, [r1, r2]
	bl NewString_ReadMsgData
	b _0222E51C
_0222E510:
	lsl r2, r1, #1
	ldr r1, _0222E53C ; =ov45_02254BD2
	ldr r0, [sp, #8]
	ldrh r1, [r1, r2]
	bl NewString_ReadMsgData
_0222E51C:
	add r4, r0, #0
	ldr r1, [sp, #0x28]
	add r0, r7, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	add r0, r4, #0
	bl String_Delete
	mov r0, #1
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222E534: .word gGameLanguage
_0222E538: .word ov45_02254BCA
_0222E53C: .word ov45_02254BD2
	thumb_func_end ov45_0222E4A8


	thumb_func_start ov45_0222E540
ov45_0222E540: ; 0x0222E540
	cmp r1, #2
	blo _0222E548
	mov r0, #0x14
	bx lr
_0222E548:
	lsl r1, r1, #1
	add r0, r0, r1
	ldrh r0, [r0, #0x20]
	bx lr
	thumb_func_end ov45_0222E540


	thumb_func_start ov45_0222E550
ov45_0222E550: ; 0x0222E550
	cmp r1, #2
	blo _0222E558
	mov r0, #0x14
	bx lr
_0222E558:
	lsl r1, r1, #1
	add r0, r0, r1
	ldrh r0, [r0, #0x20]
	bx lr
	thumb_func_end ov45_0222E550


	thumb_func_start ov45_0222E560
ov45_0222E560: ; 0x0222E560
	ldr r2, [r0, #8]
	cmp r2, r1
	bhi _0222E56A
	mov r0, #0x14
	bx lr
_0222E56A:
	lsl r1, r1, #1
	add r0, r0, r1
	ldrh r0, [r0, #0x20]
	bx lr
	.balign 4, 0
	thumb_func_end ov45_0222E560


	thumb_func_start ov45_0222E574
ov45_0222E574: ; 0x0222E574
	cmp r1, #1
	blo _0222E57C
	mov r0, #0x14
	bx lr
_0222E57C:
	lsl r1, r1, #1
	add r0, r0, r1
	ldrh r0, [r0, #0x20]
	bx lr
	thumb_func_end ov45_0222E574


	thumb_func_start ov45_0222E584
ov45_0222E584: ; 0x0222E584
	ldr r2, [r0, #4]
	cmp r2, r1
	bhi _0222E58E
	mov r0, #0x14
	bx lr
_0222E58E:
	lsl r1, r1, #1
	add r0, r0, r1
	ldrh r0, [r0, #0x20]
	bx lr
	.balign 4, 0
	thumb_func_end ov45_0222E584

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

	thumb_func_start ov45_0222C3B0
ov45_0222C3B0: ; 0x0222C3B0
	push {r4, r5, r6, r7}
	ldr r1, [r0]
	cmp r1, #0
	beq _0222C3FA
	ldr r3, _0222C400 ; =ov45_02254A3C
	mov r2, #0
	add r4, r0, #0
	mov r1, #1
	mov r6, #2
_0222C3C2:
	ldr r7, [r0, #4]
	ldr r5, [r3]
	cmp r7, r5
	bne _0222C3CC
	str r1, [r4, #0x2c]
_0222C3CC:
	ldr r5, [r4, #0x2c]
	cmp r5, #1
	bne _0222C3E4
	ldr r5, [r4, #8]
	add r7, r5, #1
	mov r5, #0x4b
	lsl r5, r5, #4
	cmp r7, r5
	bgt _0222C3E2
	str r7, [r4, #8]
	b _0222C3E4
_0222C3E2:
	str r6, [r4, #0x2c]
_0222C3E4:
	add r2, r2, #1
	add r3, r3, #4
	add r4, r4, #4
	cmp r2, #9
	blt _0222C3C2
	ldr r1, [r0, #4]
	add r2, r1, #1
	ldr r1, _0222C404 ; =0x000010E0
	cmp r2, r1
	bgt _0222C3FA
	str r2, [r0, #4]
_0222C3FA:
	pop {r4, r5, r6, r7}
	bx lr
	nop
_0222C400: .word ov45_02254A3C
_0222C404: .word 0x000010E0
	thumb_func_end ov45_0222C3B0


	thumb_func_start ov45_0222C408
ov45_0222C408: ; 0x0222C408
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	str r1, [sp]
	add r7, r2, #0
	bl ov45_0222C5B4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _0222C476
	mov r5, #0
	str r5, [sp, #4]
_0222C422:
	ldr r1, [sp, #4]
	add r0, r6, #0
	bl ov45_0222C4E4
	cmp r0, #2
	beq _0222C46A
	mov r4, #0
_0222C430:
	add r0, r6, #0
	add r1, r4, r5
	add r2, r7, #0
	bl ov45_0222C61C
	cmp r0, #0
	bne _0222C464
	add r0, r6, #0
	add r1, r4, r5
	bl ov45_0222C4B4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _0222C464
	ldr r0, [sp, #4]
	mov r1, #0xc
	mul r1, r0
	add r1, r6, r1
	lsl r0, r4, #2
	add r1, r1, r0
	ldr r0, [sp]
	add sp, #8
	str r0, [r1, #0x50]
	add r0, r4, r5
	pop {r3, r4, r5, r6, r7, pc}
_0222C464:
	add r4, r4, #1
	cmp r4, #3
	blt _0222C430
_0222C46A:
	ldr r0, [sp, #4]
	add r5, r5, #3
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #9
	blt _0222C422
_0222C476:
	mov r0, #0
	mvn r0, r0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C408


	thumb_func_start ov45_0222C480
ov45_0222C480: ; 0x0222C480
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl ov45_0222C5B4
	mov r1, #0
	add r6, r0, #0
	mvn r1, r1
	cmp r6, r1
	beq _0222C4B2
	mov r1, #3
	bl _u32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _u32_div_f
	mov r2, #0xc
	mul r2, r4
	mov r0, #0
	add r2, r5, r2
	lsl r1, r1, #2
	mvn r0, r0
	add r1, r2, r1
	str r0, [r1, #0x50]
_0222C4B2:
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_0222C480


	thumb_func_start ov45_0222C4B4
ov45_0222C4B4: ; 0x0222C4B4
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0x1b
	blo _0222C4C2
	bl GF_AssertFail
_0222C4C2:
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	mov r0, #0xc
	mul r0, r6
	add r2, r5, r0
	lsl r0, r1, #2
	add r0, r2, r0
	ldr r0, [r0, #0x50]
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C4B4


	thumb_func_start ov45_0222C4E4
ov45_0222C4E4: ; 0x0222C4E4
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r0, #0
	cmp r5, #9
	blo _0222C4F2
	bl GF_AssertFail
_0222C4F2:
	lsl r0, r5, #2
	add r0, r4, r0
	ldr r0, [r0, #0x2c]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C4E4


	thumb_func_start ov45_0222C4FC
ov45_0222C4FC: ; 0x0222C4FC
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r0, #0
	cmp r5, #9
	blo _0222C50A
	bl GF_AssertFail
_0222C50A:
	lsl r0, r5, #2
	add r0, r4, r0
	ldr r0, [r0, #8]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C4FC


	thumb_func_start ov45_0222C514
ov45_0222C514: ; 0x0222C514
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl ov45_0222C5B4
	mov r1, #0
	add r6, r0, #0
	mvn r1, r1
	cmp r6, r1
	beq _0222C548
	mov r1, #3
	bl _u32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _u32_div_f
	mov r2, #0xc
	mul r2, r4
	add r2, r5, r2
	lsl r1, r1, #2
	add r2, r2, r1
	mov r1, #0x4a
	mov r0, #1
	lsl r1, r1, #2
	str r0, [r2, r1]
_0222C548:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C514


	thumb_func_start ov45_0222C54C
ov45_0222C54C: ; 0x0222C54C
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0x1b
	blo _0222C55A
	bl GF_AssertFail
_0222C55A:
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	mov r0, #0xc
	mul r0, r6
	add r2, r5, r0
	lsl r0, r1, #2
	add r1, r2, r0
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C54C


	thumb_func_start ov45_0222C580
ov45_0222C580: ; 0x0222C580
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0x1b
	blo _0222C58E
	bl GF_AssertFail
_0222C58E:
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	mov r2, #0xc
	mul r2, r6
	add r2, r5, r2
	lsl r1, r1, #2
	add r2, r2, r1
	mov r1, #0x4a
	mov r0, #0
	lsl r1, r1, #2
	str r0, [r2, r1]
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_0222C580


	thumb_func_start ov45_0222C5B4
ov45_0222C5B4: ; 0x0222C5B4
	push {r3, r4, r5, r6}
	mov r4, #0
	add r3, r4, #0
_0222C5BA:
	add r5, r3, #0
	add r6, r0, #0
_0222C5BE:
	ldr r2, [r6, #0x50]
	cmp r1, r2
	bne _0222C5CE
	lsl r0, r4, #1
	add r0, r4, r0
	add r0, r5, r0
	pop {r3, r4, r5, r6}
	bx lr
_0222C5CE:
	add r5, r5, #1
	add r6, r6, #4
	cmp r5, #3
	blt _0222C5BE
	add r4, r4, #1
	add r0, #0xc
	cmp r4, #9
	blt _0222C5BA
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6}
	bx lr
	.balign 4, 0
	thumb_func_end ov45_0222C5B4


	thumb_func_start ov45_0222C5E8
ov45_0222C5E8: ; 0x0222C5E8
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	cmp r4, #0x1b
	blo _0222C5F8
	bl GF_AssertFail
_0222C5F8:
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	mov r2, #0xc
	mul r2, r7
	add r2, r5, r2
	lsl r1, r1, #2
	add r1, r2, r1
	add r0, r6, #1
	add r1, #0xbc
	str r0, [r1]
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222C5E8


	thumb_func_start ov45_0222C61C
ov45_0222C61C: ; 0x0222C61C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	cmp r4, #0x1b
	blo _0222C62C
	bl GF_AssertFail
_0222C62C:
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	mov r0, #0xc
	mul r0, r7
	add r2, r5, r0
	lsl r0, r1, #2
	add r0, r2, r0
	add r0, #0xbc
	ldr r0, [r0]
	cmp r0, r6
	bhi _0222C654
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222C654:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222C61C


	thumb_func_start ov45_0222C658
ov45_0222C658: ; 0x0222C658
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0x1b
	blo _0222C666
	bl GF_AssertFail
_0222C666:
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _u32_div_f
	mov r0, #0xc
	mul r0, r6
	add r2, r5, r0
	lsl r0, r1, #2
	add r0, r2, r0
	add r0, #0xbc
	ldr r0, [r0]
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_0222C658


	thumb_func_start ov45_0222C688
ov45_0222C688: ; 0x0222C688
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	str r1, [sp]
	add r5, r3, #0
	bl ov45_0222EC68
	add r6, r0, #0
	mov r0, #0x42
	lsl r0, r0, #2
	ldr r1, [r5]
	add r0, r5, r0
	bl ov45_0222BADC
	cmp r0, #0
	bne _0222C6AC
	ldr r0, _0222C734 ; =0x0000052C
	mov r1, #1
	str r1, [r5, r0]
_0222C6AC:
	mov r0, #0x4a
	lsl r0, r0, #2
	add r0, r5, r0
	bl ov45_0222A920
	add r4, r0, #0
	add r0, r5, #0
	bl ov45_0222AFF8
	cmp r4, #1
	bne _0222C6E2
	mov r1, #0
	mvn r1, r1
	cmp r6, r1
	beq _0222C6E2
	ldr r1, [sp]
	ldrh r1, [r1, #2]
	cmp r1, #1
	bne _0222C6E2
	cmp r0, #1
	beq _0222C6E2
	add r0, r5, #0
	add r1, r6, #0
	bl ov45_0222B048
	cmp r0, #0
	bne _0222C6EE
_0222C6E2:
	add r0, r5, #0
	add r1, r7, #0
	mov r2, #0
	bl ov45_0222BE08
	pop {r3, r4, r5, r6, r7, pc}
_0222C6EE:
	add r0, r5, #0
	add r1, r7, #0
	mov r2, #1
	bl ov45_0222BE08
	mov r0, #7
	lsl r0, r0, #6
	add r0, r5, r0
	add r1, r6, #0
	bl ov45_0222BD74
	cmp r0, #0
	bne _0222C70C
	mov r1, #1
	b _0222C70E
_0222C70C:
	mov r1, #0
_0222C70E:
	ldr r0, _0222C738 ; =0x000001CB
	mov r2, #2
	strb r1, [r5, r0]
	mov r0, #0x71
	lsl r0, r0, #2
	strh r6, [r5, r0]
	add r1, r0, #2
	strb r2, [r5, r1]
	add r1, r0, #6
	strb r2, [r5, r1]
	add r1, r0, #3
	sub r0, r0, #4
	mov r2, #0
	add r0, r5, r0
	strb r2, [r5, r1]
	bl ov45_0222BE48
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222C734: .word 0x0000052C
_0222C738: .word 0x000001CB
	thumb_func_end ov45_0222C688


	thumb_func_start ov45_0222C73C
ov45_0222C73C: ; 0x0222C73C
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r3, #0
	bl ov45_0222EC68
	ldr r2, _0222C790 ; =0x000001CA
	add r1, r0, #0
	ldrb r0, [r4, r2]
	cmp r0, #0
	beq _0222C78E
	sub r0, r2, #6
	ldrh r0, [r4, r0]
	cmp r0, r1
	bne _0222C78E
	ldrh r0, [r5]
	cmp r0, #1
	bne _0222C77C
	sub r2, #0xa
	add r0, r4, r2
	bl ov45_0222BD74
	cmp r0, #0
	bne _0222C76E
	mov r1, #1
	b _0222C770
_0222C76E:
	mov r1, #0
_0222C770:
	ldr r0, _0222C794 ; =0x000001CB
	strb r1, [r4, r0]
	ldr r0, _0222C798 ; =0x000001C6
	mov r1, #2
	strb r1, [r4, r0]
	b _0222C784
_0222C77C:
	sub r2, #0xa
	add r0, r4, r2
	bl ov45_0222BD4C
_0222C784:
	mov r0, #7
	lsl r0, r0, #6
	add r0, r4, r0
	bl ov45_0222BE54
_0222C78E:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222C790: .word 0x000001CA
_0222C794: .word 0x000001CB
_0222C798: .word 0x000001C6
	thumb_func_end ov45_0222C73C


	thumb_func_start ov45_0222C79C
ov45_0222C79C: ; 0x0222C79C
	push {r3, r4, r5, lr}
	add r5, r1, #0
	ldr r1, _0222C7F8 ; =0x000001CA
	add r4, r3, #0
	ldrb r1, [r4, r1]
	cmp r1, #0
	beq _0222C7F4
	bl ov45_0222EC68
	mov r1, #0x71
	lsl r1, r1, #2
	ldrh r2, [r4, r1]
	cmp r2, r0
	bne _0222C7E4
	ldrh r0, [r5, #2]
	ldr r2, _0222C7FC ; =0x0000FFFE
	add r2, r0, r2
	lsl r2, r2, #0x10
	lsr r2, r2, #0x10
	cmp r2, #1
	bhi _0222C7DA
	add r2, r1, #2
	strb r0, [r4, r2]
	ldrh r2, [r5]
	add r0, r1, #4
	strh r2, [r4, r0]
	sub r0, r1, #4
	add r0, r4, r0
	bl ov45_0222BE54
	pop {r3, r4, r5, pc}
_0222C7DA:
	sub r0, r1, #4
	add r0, r4, r0
	bl ov45_0222BD5C
	pop {r3, r4, r5, pc}
_0222C7E4:
	mov r2, #0
	mvn r2, r2
	cmp r0, r2
	bne _0222C7F4
	sub r0, r1, #4
	add r0, r4, r0
	bl ov45_0222BD5C
_0222C7F4:
	pop {r3, r4, r5, pc}
	nop
_0222C7F8: .word 0x000001CA
_0222C7FC: .word 0x0000FFFE
	thumb_func_end ov45_0222C79C


	thumb_func_start ov45_0222C800
ov45_0222C800: ; 0x0222C800
	push {r4, lr}
	ldr r1, _0222C824 ; =0x000001C6
	add r4, r3, #0
	ldrb r1, [r4, r1]
	cmp r1, #0
	beq _0222C822
	bl ov45_0222EC68
	mov r1, #0x71
	lsl r1, r1, #2
	ldrh r2, [r4, r1]
	cmp r2, r0
	bne _0222C822
	sub r0, r1, #4
	add r0, r4, r0
	bl ov45_0222BD4C
_0222C822:
	pop {r4, pc}
	.balign 4, 0
_0222C824: .word 0x000001C6
	thumb_func_end ov45_0222C800


	thumb_func_start ov45_0222C828
ov45_0222C828: ; 0x0222C828
	push {r3, lr}
	ldrb r2, [r1, #0x11]
	add r0, r3, #0
	lsl r3, r2, #2
	ldr r2, _0222C838 ; =ov45_02254A60
	ldr r2, [r2, r3]
	blx r2
	pop {r3, pc}
	.balign 4, 0
_0222C838: .word ov45_02254A60
	thumb_func_end ov45_0222C828


	thumb_func_start ov45_0222C83C
ov45_0222C83C: ; 0x0222C83C
	push {r4, lr}
	add r4, r3, #0
	bl ov45_0222EC68
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222C856
	add r1, r4, r0
	mov r0, #0x7a
	mov r2, #1
	lsl r0, r0, #2
	strb r2, [r1, r0]
_0222C856:
	pop {r4, pc}
	thumb_func_end ov45_0222C83C


	thumb_func_start ov45_0222C858
ov45_0222C858: ; 0x0222C858
	push {r3, r4, r5, r6, r7, lr}
	add r5, r3, #0
	bl ov45_0222EC68
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _0222C888
	mov r7, #0x83
	mov r4, #0
	lsl r7, r7, #2
_0222C870:
	add r0, r5, r7
	add r1, r6, #0
	add r2, r4, #0
	bl ov45_0222C408
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _0222C888
	add r4, r4, #1
	cmp r4, #3
	blt _0222C870
_0222C888:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C858


	thumb_func_start ov45_0222C88C
ov45_0222C88C: ; 0x0222C88C
	push {r4, lr}
	add r4, r3, #0
	bl ov45_0222EC68
	add r1, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	beq _0222C8A8
	mov r0, #0x83
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222C514
_0222C8A8:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C88C


	thumb_func_start ov45_0222C8AC
ov45_0222C8AC: ; 0x0222C8AC
	push {r4, lr}
	mov r1, #0
	mov r2, #0x20
	add r4, r0, #0
	bl memset
	mov r1, #0
	mov r0, #0x64
_0222C8BC:
	strb r0, [r4, r1]
	add r1, r1, #1
	cmp r1, #9
	blt _0222C8BC
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C8AC


	thumb_func_start ov45_0222C8C8
ov45_0222C8C8: ; 0x0222C8C8
	push {r3, r4, r5, r6, r7, lr}
	add r4, r2, #0
	add r5, r0, #0
	add r6, r1, #0
	cmp r4, #0x14
	blo _0222C8D8
	bl GF_AssertFail
_0222C8D8:
	cmp r6, #0x1b
	blo _0222C8E0
	bl GF_AssertFail
_0222C8E0:
	add r7, r5, #0
	add r7, #0xc
	ldrb r0, [r7, r4]
	cmp r0, #0
	bne _0222C8FC
	add r0, r6, #0
	mov r1, #3
	bl _u32_div_f
	ldrb r1, [r5, r0]
	asr r1, r1, #1
	strb r1, [r5, r0]
	mov r0, #1
	strb r0, [r7, r4]
_0222C8FC:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C8C8


	thumb_func_start ov45_0222C900
ov45_0222C900: ; 0x0222C900
	push {r3, r4, r5, lr}
	mov r5, #0
	add r4, r0, #0
	add r1, r5, #0
_0222C908:
	ldrb r0, [r4, r1]
	add r1, r1, #1
	add r5, r5, r0
	cmp r1, #9
	blt _0222C908
	bl MTRandom
	add r1, r5, #0
	bl _u32_div_f
	mov r3, #0
	add r0, r3, #0
_0222C920:
	cmp r3, r1
	bhi _0222C932
	ldrb r2, [r4, r0]
	add r2, r3, r2
	cmp r2, r1
	bls _0222C932
	lsl r1, r0, #1
	add r0, r0, r1
	pop {r3, r4, r5, pc}
_0222C932:
	ldrb r2, [r4, r0]
	add r0, r0, #1
	add r3, r3, r2
	cmp r0, #9
	blt _0222C920
	bl GF_AssertFail
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222C900


	thumb_func_start ov45_0222C944
ov45_0222C944: ; 0x0222C944
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	cmp r4, #0x14
	blo _0222C954
	bl GF_AssertFail
_0222C954:
	cmp r4, #0x14
	bhs _0222C95A
	strb r6, [r5, r4]
_0222C95A:
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_0222C944


	thumb_func_start ov45_0222C95C
ov45_0222C95C: ; 0x0222C95C
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0x14
	blo _0222C96A
	bl GF_AssertFail
_0222C96A:
	cmp r4, #0x14
	bhs _0222C972
	ldrb r0, [r5, r4]
	pop {r3, r4, r5, pc}
_0222C972:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C95C


	thumb_func_start ov45_0222C978
ov45_0222C978: ; 0x0222C978
	push {r3, r4, r5, lr}
	add r4, r1, #0
	mov r1, #0
	mov r2, #0xb8
	add r5, r0, #0
	bl MI_CpuFill8
	add r0, r4, #0
	bl WallpaperPasswordBank_Create
	add r5, #0xb4
	str r0, [r5]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C978


	thumb_func_start ov45_0222C994
ov45_0222C994: ; 0x0222C994
	ldr r3, _0222C99C ; =WallpaperPasswordBank_Delete
	add r0, #0xb4
	ldr r0, [r0]
	bx r3
	.balign 4, 0
_0222C99C: .word WallpaperPasswordBank_Delete
	thumb_func_end ov45_0222C994


	thumb_func_start ov45_0222C9A0
ov45_0222C9A0: ; 0x0222C9A0
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	add r7, r3, #0
	cmp r4, #0x14
	blo _0222C9B2
	bl GF_AssertFail
_0222C9B2:
	cmp r4, #0x14
	bhs _0222C9CE
	strb r6, [r5, r4]
	cmp r6, #1
	bne _0222C9CE
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r5, #0x14
	lsl r2, r4, #3
	add r1, r7, #0
	add r2, r5, r2
	bl ov45_0222CA10
_0222C9CE:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222C9A0


	thumb_func_start ov45_0222C9D0
ov45_0222C9D0: ; 0x0222C9D0
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0x14
	blo _0222C9DE
	bl GF_AssertFail
_0222C9DE:
	cmp r4, #0x14
	bhs _0222C9E6
	ldrb r0, [r5, r4]
	pop {r3, r4, r5, pc}
_0222C9E6:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C9D0


	thumb_func_start ov45_0222C9EC
ov45_0222C9EC: ; 0x0222C9EC
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0x14
	blo _0222C9FA
	bl GF_AssertFail
_0222C9FA:
	cmp r4, #0x14
	bhs _0222CA0C
	ldrb r0, [r5, r4]
	cmp r0, #0
	beq _0222CA0C
	add r5, #0x14
	lsl r0, r4, #3
	add r0, r5, r0
	pop {r3, r4, r5, pc}
_0222CA0C:
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222C9EC


	thumb_func_start ov45_0222CA10
ov45_0222CA10: ; 0x0222CA10
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r1, #0
	add r6, r0, #0
	add r5, r2, #0
	bl WallpaperPasswordBank_GetCount
	add r7, r0, #0
	str r4, [sp, #8]
	add r0, sp, #8
	ldrb r4, [r0]
	ldrb r0, [r0, #3]
	add r1, r7, #0
	str r0, [sp]
	add r0, r0, r4
	bl _u32_div_f
	add r0, r6, #0
	bl WallpaperPasswordBank_GetWordAtIndex
	strh r0, [r5]
	add r0, sp, #8
	ldrb r0, [r0, #1]
	add r1, r7, #0
	str r0, [sp, #4]
	add r0, r4, r0
	bl _u32_div_f
	add r0, r6, #0
	bl WallpaperPasswordBank_GetWordAtIndex
	strh r0, [r5, #2]
	add r0, sp, #8
	ldrb r4, [r0, #2]
	ldr r0, [sp, #4]
	add r1, r7, #0
	add r0, r0, r4
	bl _u32_div_f
	add r0, r6, #0
	bl WallpaperPasswordBank_GetWordAtIndex
	strh r0, [r5, #4]
	ldr r0, [sp]
	add r1, r7, #0
	add r0, r4, r0
	bl _u32_div_f
	add r0, r6, #0
	bl WallpaperPasswordBank_GetWordAtIndex
	strh r0, [r5, #6]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222CA10


	thumb_func_start ov45_0222CA7C
ov45_0222CA7C: ; 0x0222CA7C
	mov r3, #0
	str r3, [r0]
	sub r2, r2, r1
	mov r1, #0x1e
	str r3, [r0, #0xc]
	mul r1, r2
	str r1, [r0, #0x10]
	bx lr
	thumb_func_end ov45_0222CA7C


	thumb_func_start ov45_0222CA8C
ov45_0222CA8C: ; 0x0222CA8C
	mov r1, #1
	str r1, [r0]
	mov r1, #0
	str r1, [r0, #0xc]
	ldr r3, _0222CA9C ; =ov45_0222ECB8
	add r0, r0, #4
	bx r3
	nop
_0222CA9C: .word ov45_0222ECB8
	thumb_func_end ov45_0222CA8C


	thumb_func_start ov45_0222CAA0
ov45_0222CAA0: ; 0x0222CAA0
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	beq _0222CB32
	add r0, sp, #0
	bl ov45_0222ECB8
	ldr r3, [sp]
	ldr r0, [r4, #4]
	ldr r1, [sp, #4]
	ldr r2, [r4, #8]
	sub r0, r3, r0
	sbc r1, r2
	mov r2, #0x1e
	mov r3, #0
	bl _ll_mul
	ldr r2, [r4, #0xc]
	asr r3, r2, #0x1f
	sub r2, r2, r0
	sbc r3, r1
	bge _0222CAD2
	str r0, [r4, #0xc]
_0222CAD2:
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x10]
	cmp r1, r0
	bge _0222CB12
	add r0, r1, #1
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	lsl r0, r0, #8
	bl _s32_div_f
	mov r2, #0
	ldr r5, _0222CB38 ; =_02254A28
	add r3, r2, #0
_0222CAEC:
	ldrh r1, [r5, #2]
	add r2, r2, r1
	cmp r2, r0
	blo _0222CB08
	ldr r0, _0222CB38 ; =_02254A28
	lsl r1, r3, #2
	ldrh r1, [r0, r1]
	ldr r0, [r4, #0x14]
	cmp r0, r1
	beq _0222CB2C
	str r1, [r4, #0x14]
	mov r0, #0
	str r0, [r4, #0x18]
	b _0222CB2C
_0222CB08:
	add r3, r3, #1
	add r5, r5, #4
	cmp r3, #5
	blo _0222CAEC
	b _0222CB2C
_0222CB12:
	ldr r0, [r4, #0x14]
	cmp r0, #5
	beq _0222CB20
	mov r0, #5
	str r0, [r4, #0x14]
	mov r0, #0
	str r0, [r4, #0x18]
_0222CB20:
	ldr r0, [r4, #0x18]
	cmp r0, #0x78
	blo _0222CB2C
	mov r0, #0
	str r0, [r4, #0x14]
	str r0, [r4]
_0222CB2C:
	ldr r0, [r4, #0x18]
	add r0, r0, #1
	str r0, [r4, #0x18]
_0222CB32:
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_0222CB38: .word _02254A28
	thumb_func_end ov45_0222CAA0

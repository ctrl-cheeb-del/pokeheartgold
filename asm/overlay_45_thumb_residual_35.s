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

	thumb_func_start ov45_0222FDD8
ov45_0222FDD8: ; 0x0222FDD8
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r0, _0222FE7C ; =_022577C0
	add r4, r1, #0
	add r5, r2, #0
	ldr r0, [r0]
	add r1, r7, #0
	mov r2, #0
	str r3, [sp]
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FE78
	cmp r4, #5
	bhi _0222FE78
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222FE06: ; jump table
	.short _0222FE12 - _0222FE06 - 2 ; case 0
	.short _0222FE16 - _0222FE06 - 2 ; case 1
	.short _0222FE16 - _0222FE06 - 2 ; case 2
	.short _0222FE16 - _0222FE06 - 2 ; case 3
	.short _0222FE16 - _0222FE06 - 2 ; case 4
	.short _0222FE2C - _0222FE06 - 2 ; case 5
_0222FE12:
	mov r1, #0
	b _0222FE32
_0222FE16:
	add r0, r4, #0
	bl ov45_0222F7A8
	ldr r1, _0222FE7C ; =_022577C0
	ldr r2, [r1]
	ldr r1, _0222FE80 ; =0x0000012D
	ldrb r1, [r2, r1]
	cmp r1, r0
	bne _0222FE78
	mov r1, #1
	b _0222FE32
_0222FE2C:
	mov r1, #0
	b _0222FE32
_0222FE30: ; 0x0222FE30 unreachable
	pop {r3, r4, r5, r6, r7, pc}
_0222FE32:
	add r4, r1, #0
	mov r0, #0xc
	mul r4, r0
	ldr r0, _0222FE7C ; =_022577C0
	mov r1, #0x62
	ldr r0, [r0]
	lsl r1, r1, #2
	add r0, r0, r4
	ldr r2, [r0, r1]
	cmp r2, r5
	bls _0222FE78
	sub r1, r1, #4
	ldr r0, [r0, r1]
	lsl r5, r5, #3
	add r0, r0, r5
	ldr r1, [r0, #4]
	ldr r0, [sp, #0x18]
	cmp r1, r0
	bls _0222FE5C
	bl GF_AssertFail
_0222FE5C:
	ldr r0, _0222FE7C ; =_022577C0
	mov r3, #0x61
	ldr r0, [r0]
	lsl r3, r3, #2
	add r6, r0, r4
	ldr r4, [r6, r3]
	add r3, #8
	add r2, r4, r5
	ldr r1, [sp]
	ldr r2, [r2, #4]
	ldr r3, [r6, r3]
	ldr r4, [r4, r5]
	add r0, r7, #0
	blx r4
_0222FE78:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222FE7C: .word _022577C0
_0222FE80: .word 0x0000012D
	thumb_func_end ov45_0222FDD8


	thumb_func_start ov45_0222FE84
ov45_0222FE84: ; 0x0222FE84
	push {r3, lr}
	ldr r1, _0222FEBC ; =ov45_02254EF0
	ldr r0, [sp, #8]
	ldr r1, [r1]
	bl strcmp
	cmp r0, #0
	bne _0222FEB8
	ldr r0, _0222FEC0 ; =_022577C0
	mov r2, #0x50
	ldr r1, [r0]
	mov r0, #0x4d
	lsl r0, r0, #2
	add r0, r1, r0
	ldr r1, [sp, #0xc]
	bl memcpy
	ldr r0, _0222FEC0 ; =_022577C0
	ldr r2, [r0]
	mov r0, #0x13
	lsl r0, r0, #4
	ldrb r1, [r2, r0]
	cmp r1, #0
	beq _0222FEB8
	mov r1, #0
	strb r1, [r2, r0]
_0222FEB8:
	pop {r3, pc}
	nop
_0222FEBC: .word ov45_02254EF0
_0222FEC0: .word _022577C0
	thumb_func_end ov45_0222FE84


	thumb_func_start ov45_0222FEC4
ov45_0222FEC4: ; 0x0222FEC4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _0222FF38 ; =_022577C0
	add r7, r1, #0
	ldr r0, [r0]
	add r1, r5, #0
	mov r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FF36
	ldr r0, _0222FF38 ; =_022577C0
	ldr r1, _0222FF3C ; =0x0000012D
	ldr r0, [r0]
	ldrb r1, [r0, r1]
	cmp r1, #4
	beq _0222FF2A
	add r1, r5, #0
	bl ov45_0222F954
	ldr r4, [r0, #8]
	ldr r0, _0222FF38 ; =_022577C0
	ldr r6, [r7, #8]
	ldr r1, [r0]
	ldr r0, _0222FF3C ; =0x0000012D
	ldrb r0, [r1, r0]
	bl ov45_0222F7B0
	cmp r4, #5
	bne _0222FF16
	cmp r6, r0
	bne _0222FF16
	ldr r0, _0222FF38 ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #1
	bl ov45_0222FA74
	b _0222FF2A
_0222FF16:
	cmp r4, r0
	bne _0222FF2A
	cmp r6, r0
	beq _0222FF2A
	ldr r0, _0222FF38 ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #1
	bl ov45_0222FAF8
_0222FF2A:
	ldr r0, _0222FF38 ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	add r2, r7, #0
	bl ov45_0222F928
_0222FF36:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222FF38: .word _022577C0
_0222FF3C: .word 0x0000012D
	thumb_func_end ov45_0222FEC4


	thumb_func_start ov45_0222FF40
ov45_0222FF40: ; 0x0222FF40
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0222FF78 ; =_022577C0
	add r4, r1, #0
	ldr r0, [r0]
	add r1, r5, #0
	mov r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FF74
	ldr r0, _0222FF78 ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	add r2, r4, #0
	bl ov45_0222F88C
	ldr r0, _0222FF78 ; =_022577C0
	add r1, r4, #0
	ldr r3, [r0]
	add r0, r5, #0
	ldr r2, [r3, #0x20]
	ldr r3, [r3, #0x14]
	blx r3
_0222FF74:
	pop {r3, r4, r5, pc}
	nop
_0222FF78: .word _022577C0
	thumb_func_end ov45_0222FF40


	thumb_func_start ov45_0222FF7C
ov45_0222FF7C: ; 0x0222FF7C
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, _0222FFFC ; =_022577C0
	add r4, r1, #0
	ldr r0, [r0]
	add r1, r5, #0
	mov r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FFF8
	bl ov45_0222E9E0
	cmp r0, r5
	beq _0222FFEA
	ldr r0, _0222FFFC ; =_022577C0
	ldr r2, _02230000 ; =0x0000069E
	ldr r1, [r0]
	ldrb r0, [r1, r2]
	cmp r0, #0
	beq _0222FFEA
	sub r0, r2, #2
	ldrh r0, [r1, r0]
	ldr r3, [r4]
	cmp r0, r3
	bne _0222FFEA
	sub r2, #0xe6
	add r2, r1, r2
	mov r1, #0x4c
	mul r1, r0
	add r0, r2, r1
	add r1, sp, #8
	bl ov45_02230384
	add r0, r4, #0
	add r1, sp, #0
	bl ov45_02230384
	ldr r3, [sp, #8]
	ldr r2, [sp, #0xc]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	sub r0, r3, r0
	sbc r2, r1
	blt _0222FFF8
	ldr r0, _0222FFFC ; =_022577C0
	mov r2, #1
	ldr r1, [r0]
	ldr r0, _02230004 ; =0x0000069F
	strb r2, [r1, r0]
	bl ov45_0222F154
_0222FFEA:
	ldr r0, _0222FFFC ; =_022577C0
	ldr r1, [r4]
	ldr r0, [r0]
	add r2, r5, #0
	add r3, r4, #0
	bl ov45_02230164
_0222FFF8:
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222FFFC: .word _022577C0
_02230000: .word 0x0000069E
_02230004: .word 0x0000069F
	thumb_func_end ov45_0222FF7C


	thumb_func_start ov45_02230008
ov45_02230008: ; 0x02230008
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _02230048 ; =_022577C0
	add r4, r1, #0
	ldr r0, [r0]
	add r1, r5, #0
	mov r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _02230046
	ldr r0, _02230048 ; =_022577C0
	ldr r1, [r4]
	ldr r0, [r0]
	add r2, r5, #0
	bl ov45_022301E0
	ldr r1, _02230048 ; =_022577C0
	ldr r2, [r4]
	ldr r5, [r1]
	ldr r1, _0223004C ; =0x0000069C
	ldrh r3, [r5, r1]
	cmp r3, r2
	bne _02230046
	cmp r0, #1
	bne _02230046
	mov r2, #1
	add r0, r1, #3
	strb r2, [r5, r0]
_02230046:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02230048: .word _022577C0
_0223004C: .word 0x0000069C
	thumb_func_end ov45_02230008


	thumb_func_start ov45_02230050
ov45_02230050: ; 0x02230050
	push {r3, lr}
	ldr r1, _02230060 ; =_022577C0
	ldr r2, [r1]
	ldr r1, [r2, #0x20]
	ldr r2, [r2, #0x18]
	blx r2
	pop {r3, pc}
	nop
_02230060: .word _022577C0
	thumb_func_end ov45_02230050


	thumb_func_start ov45_02230064
ov45_02230064: ; 0x02230064
	push {r3, lr}
	cmp r0, #0
	beq _02230076
	ldr r0, _02230088 ; =_022577C0
	mov r2, #1
	ldr r1, [r0]
	ldr r0, _0223008C ; =0x00000133
	strb r2, [r1, r0]
	pop {r3, pc}
_02230076:
	ldr r0, _02230088 ; =_022577C0
	ldr r3, [r0]
	add r0, r1, #0
	add r1, r2, #0
	ldr r2, [r3, #0x20]
	ldr r3, [r3, #0x1c]
	blx r3
	pop {r3, pc}
	nop
_02230088: .word _022577C0
_0223008C: .word 0x00000133
	thumb_func_end ov45_02230064


	thumb_func_start ov45_02230090
ov45_02230090: ; 0x02230090
	cmp r0, #0
	bne _02230098
	mov r0, #1
	bx lr
_02230098:
	ldr r0, _022300A8 ; =_022577C0
	mov r2, #1
	ldr r1, [r0]
	ldr r0, _022300AC ; =0x00000132
	strb r2, [r1, r0]
	mov r0, #0
	bx lr
	nop
_022300A8: .word _022577C0
_022300AC: .word 0x00000132
	thumb_func_end ov45_02230090


	thumb_func_start ov45_022300B0
ov45_022300B0: ; 0x022300B0
	push {r3, lr}
	cmp r0, #0
	bne _022300C6
	ldr r0, _022300D4 ; =_022577C0
	ldr r3, [r0]
	mov r0, #0x6a
	lsl r0, r0, #4
	add r0, r3, r0
	bl ov45_0223040C
	pop {r3, pc}
_022300C6:
	ldr r0, _022300D4 ; =_022577C0
	mov r2, #1
	ldr r1, [r0]
	ldr r0, _022300D8 ; =0x00000132
	strb r2, [r1, r0]
	pop {r3, pc}
	nop
_022300D4: .word _022577C0
_022300D8: .word 0x00000132
	thumb_func_end ov45_022300B0


	thumb_func_start ov45_022300DC
ov45_022300DC: ; 0x022300DC
	push {r3, lr}
	cmp r0, #0
	bne _022300F0
	ldr r0, _022300FC ; =_022577C0
	ldr r2, [r0]
	ldr r0, _02230100 ; =0x000006A8
	add r0, r2, r0
	bl ov45_0223048C
	pop {r3, pc}
_022300F0:
	ldr r0, _022300FC ; =_022577C0
	mov r2, #1
	ldr r1, [r0]
	ldr r0, _02230104 ; =0x00000132
	strb r2, [r1, r0]
	pop {r3, pc}
	.balign 4, 0
_022300FC: .word _022577C0
_02230100: .word 0x000006A8
_02230104: .word 0x00000132
	thumb_func_end ov45_022300DC


	thumb_func_start ov45_02230108
ov45_02230108: ; 0x02230108
	push {r3, lr}
	ldr r0, _0223012C ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x26
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	cmp r0, #1
	beq _0223011C
	bl GF_AssertFail
_0223011C:
	ldr r0, _0223012C ; =_022577C0
	mov r2, #2
	ldr r1, [r0]
	mov r0, #0x26
	lsl r0, r0, #6
	str r2, [r1, r0]
	pop {r3, pc}
	nop
_0223012C: .word _022577C0
	thumb_func_end ov45_02230108


	thumb_func_start ov45_02230130
ov45_02230130: ; 0x02230130
	ldr r0, _0223013C ; =_022577C0
	mov r2, #1
	ldr r1, [r0]
	ldr r0, _02230140 ; =0x00000131
	strb r2, [r1, r0]
	bx lr
	.balign 4, 0
_0223013C: .word _022577C0
_02230140: .word 0x00000131
	thumb_func_end ov45_02230130


	thumb_func_start ov45_02230144
ov45_02230144: ; 0x02230144
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0223015C ; =0x000005B8
	mov r1, #0
	add r0, r4, r0
	mov r2, #0xe4
	bl memset
	ldr r0, _02230160 ; =0x0000069C
	mov r1, #3
	strh r1, [r4, r0]
	pop {r4, pc}
	.balign 4, 0
_0223015C: .word 0x000005B8
_02230160: .word 0x0000069C
	thumb_func_end ov45_02230144


	thumb_func_start ov45_02230164
ov45_02230164: ; 0x02230164
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	add r5, r0, #0
	add r7, r3, #0
	str r2, [sp]
	cmp r6, #3
	blt _02230176
	bl GF_AssertFail
_02230176:
	add r0, r5, #0
	add r1, r6, #0
	bl ov45_0223021C
	cmp r0, #1
	bne _02230194
	mov r0, #0x4c
	mul r0, r6
	add r1, r5, r0
	mov r0, #6
	lsl r0, r0, #8
	ldr r1, [r1, r0]
	ldr r0, [sp]
	cmp r0, r1
	bne _022301D2
_02230194:
	mov r0, #0x4c
	add r4, r6, #0
	mul r4, r0
	ldr r0, _022301D4 ; =0x000005B8
	add r1, r5, r4
	add r3, r1, r0
	mov r2, #8
_022301A2:
	ldmia r7!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _022301A2
	ldr r0, [r7]
	str r0, [r3]
	ldr r0, _022301D8 ; =0x000005FC
	add r2, r5, r0
	ldrh r1, [r2, r4]
	cmp r1, #0
	bne _022301D2
	mov r1, #1
	strh r1, [r2, r4]
	add r1, r0, #4
	ldr r0, [sp]
	add r2, r5, r4
	str r0, [r2, r1]
	add r0, r5, #0
	add r1, r6, #0
	bl ov45_0223023C
	ldr r1, _022301DC ; =0x000005FE
	add r2, r5, r4
	strh r0, [r2, r1]
_022301D2:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022301D4: .word 0x000005B8
_022301D8: .word 0x000005FC
_022301DC: .word 0x000005FE
	thumb_func_end ov45_02230164


	thumb_func_start ov45_022301E0
ov45_022301E0: ; 0x022301E0
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	cmp r4, #3
	blt _022301F0
	bl GF_AssertFail
_022301F0:
	add r0, r5, #0
	add r1, r4, #0
	bl ov45_0223021C
	cmp r0, #1
	bne _02230216
	mov r0, #0x4c
	mul r0, r4
	add r2, r5, r0
	mov r0, #6
	lsl r0, r0, #8
	ldr r1, [r2, r0]
	cmp r6, r1
	bne _02230216
	mov r1, #0
	sub r0, r0, #4
	strh r1, [r2, r0]
	mov r0, #1
	pop {r4, r5, r6, pc}
_02230216:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov45_022301E0


	thumb_func_start ov45_0223021C
ov45_0223021C: ; 0x0223021C
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #3
	blt _0223022A
	bl GF_AssertFail
_0223022A:
	mov r0, #0x4c
	mul r0, r4
	add r1, r5, r0
	ldr r0, _02230238 ; =0x000005FC
	ldrh r0, [r1, r0]
	pop {r3, r4, r5, pc}
	nop
_02230238: .word 0x000005FC
	thumb_func_end ov45_0223021C


	thumb_func_start ov45_0223023C
ov45_0223023C: ; 0x0223023C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r0, #0
	add r5, r1, #0
	bl ov45_0223021C
	cmp r0, #0
	bne _02230252
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, pc}
_02230252:
	add r0, r4, #0
	add r1, r5, #0
	bl ov45_022302B0
	add r1, sp, #0
	bl ov45_02230384
	mov r1, #0x67
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r2, [r4, r1]
	ldr r3, [sp]
	ldr r1, [sp, #4]
	sub r0, r0, r3
	sbc r2, r1
	mov r3, #0
	mov r1, #0x1e
	sub r1, r1, r0
	sbc r3, r2
	bge _02230282
	mov r0, #0x1e
	mov r2, #0
	b _02230294
_02230282:
	mov r1, #0
	mov r3, #0
	sub r1, r0, r1
	mov ip, r2
	mov r1, ip
	sbc r1, r3
	bge _02230294
	mov r0, #0
	add r2, r0, #0
_02230294:
	mov r1, #0x3c
	mov r3, #0
	sub r0, r1, r0
	mov ip, r3
	mov r1, ip
	sbc r1, r2
	mov r2, #0x1e
	bl _ll_mul
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0223023C


	thumb_func_start ov45_022302B0
ov45_022302B0: ; 0x022302B0
	push {r4, r5, r6, lr}
	add r6, r1, #0
	add r5, r0, #0
	cmp r6, #3
	blt _022302BE
	bl GF_AssertFail
_022302BE:
	mov r0, #0x4c
	add r4, r6, #0
	mul r4, r0
	ldr r0, _022302DC ; =0x000005FC
	add r1, r5, r4
	ldrh r0, [r1, r0]
	cmp r0, #1
	beq _022302D2
	bl GF_AssertFail
_022302D2:
	ldr r0, _022302E0 ; =0x000005B8
	add r0, r5, r0
	add r0, r0, r4
	pop {r4, r5, r6, pc}
	nop
_022302DC: .word 0x000005FC
_022302E0: .word 0x000005B8
	thumb_func_end ov45_022302B0


	thumb_func_start ov45_022302E4
ov45_022302E4: ; 0x022302E4
	push {r3, r4, r5, r6, r7, lr}
	ldr r0, _02230364 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _02230368 ; =0x0000069E
	ldrb r0, [r1, r0]
	cmp r0, #1
	bne _0223031E
	bl ov00_021E7144
	add r4, r0, #0
	cmp r4, #4
	bls _02230300
	bl GF_AssertFail
_02230300:
	ldr r0, _02230364 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0223036C ; =0x000005B8
	add r2, r1, r0
	add r0, #0xe4
	ldrh r1, [r1, r0]
	mov r0, #0x4c
	mul r0, r1
	add r0, r2, r0
	ldr r1, [r0, #8]
	cmp r1, r4
	beq _0223031E
	str r4, [r0, #8]
	bl ov45_02232BB0
_0223031E:
	mov r4, #0
	ldr r6, _02230364 ; =_022577C0
	ldr r7, _02230370 ; =0x000005FC
	add r5, r4, #0
_02230326:
	ldr r0, [r6]
	add r0, r0, r5
	ldrh r1, [r0, r7]
	cmp r1, #1
	bne _0223035A
	ldr r1, _02230374 ; =0x000005FE
	ldrh r1, [r0, r1]
	cmp r1, #0
	beq _02230342
	ldr r1, _02230374 ; =0x000005FE
	ldrh r1, [r0, r1]
	sub r2, r1, #1
	ldr r1, _02230374 ; =0x000005FE
	strh r2, [r0, r1]
_02230342:
	ldr r0, [r6]
	add r1, r4, #0
	bl ov45_0223023C
	ldr r1, [r6]
	ldr r2, _02230374 ; =0x000005FE
	add r1, r1, r5
	ldrh r2, [r1, r2]
	cmp r0, r2
	bhs _0223035A
	ldr r2, _02230374 ; =0x000005FE
	strh r0, [r1, r2]
_0223035A:
	add r4, r4, #1
	add r5, #0x4c
	cmp r4, #3
	blt _02230326
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02230364: .word _022577C0
_02230368: .word 0x0000069E
_0223036C: .word 0x000005B8
_02230370: .word 0x000005FC
_02230374: .word 0x000005FE
	thumb_func_end ov45_022302E4


	thumb_func_start ov45_02230378
ov45_02230378: ; 0x02230378
	ldr r2, [r1]
	ldr r1, [r1, #4]
	str r2, [r0, #0x10]
	str r1, [r0, #0x14]
	bx lr
	.balign 4, 0
	thumb_func_end ov45_02230378


	thumb_func_start ov45_02230384
ov45_02230384: ; 0x02230384
	ldr r2, [r0, #0x10]
	ldr r0, [r0, #0x14]
	str r2, [r1]
	str r0, [r1, #4]
	bx lr
	.balign 4, 0
	thumb_func_end ov45_02230384

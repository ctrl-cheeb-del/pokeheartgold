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

	thumb_func_start ov45_02230ACC
ov45_02230ACC: ; 0x02230ACC
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	ldrb r0, [r5]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	beq _02230B5C
	ldr r0, [r5, #4]
	mov r1, #5
	bl ov42_02228188
	add r4, r0, #0
	ldr r0, [r5, #4]
	mov r1, #8
	bl ov42_02228188
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0x86
	ldrh r0, [r0]
	cmp r0, r6
	bhi _02230B02
	add r0, r5, #0
	add r0, #0x84
	ldrb r0, [r0]
	cmp r0, r4
	beq _02230B2E
_02230B02:
	add r0, r5, #0
	add r0, #0x84
	ldrb r0, [r0]
	bl ov45_02230DC4
	cmp r0, #1
	bne _02230B28
	ldr r0, [r5, #8]
	bl sub_02023EF4
	add r1, r5, #0
	add r1, #0x85
	strb r0, [r1]
	ldr r0, [r5, #8]
	bl sub_02023F70
	add r1, r5, #0
	add r1, #0x88
	str r0, [r1]
_02230B28:
	add r0, r5, #0
	add r0, #0x84
	strb r4, [r0]
_02230B2E:
	ldr r1, _02230B60 ; =ov45_02254F28
	add r0, r5, #0
	lsl r2, r4, #2
	add r0, #0x86
	strh r6, [r0]
	ldr r1, [r1, r2]
	add r0, r5, #0
	blx r1
	ldr r0, [r5, #4]
	bl ov42_022282F4
	add r2, sp, #0
	strh r0, [r2]
	lsr r0, r0, #0x10
	strh r0, [r2, #2]
	ldrh r0, [r2]
	add r1, sp, #4
	strh r0, [r2, #4]
	ldrh r0, [r2, #2]
	strh r0, [r2, #6]
	add r0, r5, #0
	bl ov45_022308C0
_02230B5C:
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02230B60: .word ov45_02254F28
	thumb_func_end ov45_02230ACC


	thumb_func_start ov45_02230B64
ov45_02230B64: ; 0x02230B64
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #4]
	mov r1, #6
	bl ov42_02228188
	add r1, r0, #0
	mov r0, #1
	bl ov45_022309C4
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl sub_02023EE0
	ldr r0, [r4, #8]
	mov r1, #0
	bl sub_02023F40
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_02230B64


	thumb_func_start ov45_02230B8C
ov45_02230B8C: ; 0x02230B8C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #4]
	mov r1, #6
	bl ov42_02228188
	add r1, r0, #0
	mov r0, #1
	bl ov45_022309C4
	add r4, r0, #0
	ldr r0, [r5, #4]
	mov r1, #9
	bl ov42_02228188
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	ldr r0, [r5, #4]
	mov r1, #8
	bl ov42_02228188
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	add r0, r6, #0
	mov r2, #8
	bl ov45_022309D0
	add r6, r0, #0
	ldr r0, [r5, #8]
	add r1, r4, #0
	bl sub_02023EE0
	add r0, r5, #0
	add r0, #0x85
	ldrb r0, [r0]
	cmp r0, r4
	ldr r0, [r5, #8]
	bne _02230BEC
	mov r1, #0
	bl sub_02023F40
	ldr r0, [r5, #8]
	add r5, #0x88
	ldr r1, [r5]
	add r1, r6, r1
	bl sub_02023F04
	pop {r4, r5, r6, pc}
_02230BEC:
	mov r1, #0
	bl sub_02023F40
	ldr r0, [r5, #8]
	add r1, r6, #0
	bl sub_02023F04
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_02230B8C


	thumb_func_start ov45_02230BFC
ov45_02230BFC: ; 0x02230BFC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #4]
	mov r1, #8
	bl ov42_02228188
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	cmp r0, #4
	bhs _02230C1C
	mov r1, #1
	ldr r0, [r4, #8]
	lsl r1, r1, #0xe
	bl sub_02023F40
	pop {r4, pc}
_02230C1C:
	ldr r0, [r4, #4]
	mov r1, #6
	bl ov42_02228188
	add r1, r0, #0
	mov r0, #1
	bl ov45_022309C4
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl sub_02023EE0
	ldr r0, [r4, #8]
	mov r1, #0
	bl sub_02023F40
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_02230BFC


	thumb_func_start ov45_02230C40
ov45_02230C40: ; 0x02230C40
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #4]
	mov r1, #6
	bl ov42_02228188
	add r1, r0, #0
	mov r0, #0
	bl ov45_022309C4
	add r4, r0, #0
	ldr r0, [r5, #4]
	mov r1, #9
	bl ov42_02228188
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	ldr r0, [r5, #4]
	mov r1, #8
	bl ov42_02228188
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	add r0, r6, #0
	mov r2, #4
	bl ov45_022309D0
	add r6, r0, #0
	ldr r0, [r5, #8]
	add r1, r4, #0
	bl sub_02023EE0
	add r0, r5, #0
	add r0, #0x85
	ldrb r0, [r0]
	cmp r0, r4
	ldr r0, [r5, #8]
	bne _02230CA0
	mov r1, #0
	bl sub_02023F40
	ldr r0, [r5, #8]
	add r5, #0x88
	ldr r1, [r5]
	add r1, r6, r1
	bl sub_02023F04
	pop {r4, r5, r6, pc}
_02230CA0:
	mov r1, #0
	bl sub_02023F40
	ldr r0, [r5, #8]
	add r1, r6, #0
	bl sub_02023F04
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_02230C40


	thumb_func_start ov45_02230CB0
ov45_02230CB0: ; 0x02230CB0
	push {r3, lr}
	ldrb r1, [r0]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	bne _02230CD0
	ldrb r1, [r0, #1]
	lsl r2, r1, #0x1f
	lsr r2, r2, #0x1f
	cmp r2, #1
	bne _02230CD0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x19
	lsl r2, r1, #2
	ldr r1, _02230CD4 ; =ov45_02254F1C
	ldr r1, [r1, r2]
	blx r1
_02230CD0:
	pop {r3, pc}
	nop
_02230CD4: .word ov45_02254F1C
	thumb_func_end ov45_02230CB0


	thumb_func_start ov45_02230CD8
ov45_02230CD8: ; 0x02230CD8
	push {r4, lr}
	add r4, r0, #0
	ldrb r3, [r4, #2]
	mov r0, #0x1e
	lsr r2, r3, #0x1f
	lsl r1, r3, #0x1e
	sub r1, r1, r2
	ror r1, r0
	add r0, r2, r1
	bne _02230D08
	ldr r1, _02230D1C ; =ov45_02254C34
	lsr r2, r3, #2
	ldrb r1, [r1, r2]
	mov r0, #1
	bl ov45_022309C4
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl sub_02023EE0
	ldr r0, [r4, #8]
	mov r1, #0
	bl sub_02023F40
_02230D08:
	ldrb r1, [r4, #3]
	ldrb r0, [r4, #2]
	add r0, r0, r1
	cmp r0, #0x10
	bge _02230D16
	strb r0, [r4, #2]
	pop {r4, pc}
_02230D16:
	mov r0, #0
	strb r0, [r4, #2]
	pop {r4, pc}
	.balign 4, 0
_02230D1C: .word ov45_02254C34
	thumb_func_end ov45_02230CD8


	thumb_func_start ov45_02230D20
ov45_02230D20: ; 0x02230D20
	push {r4, lr}
	add r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _02230D5A
	ldr r0, [r4, #4]
	mov r1, #6
	bl ov42_02228188
	ldr r0, [r4, #4]
	mov r1, #6
	bl ov42_02228188
	add r1, r0, #0
	mov r0, #1
	bl ov45_022309C4
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl sub_02023EE0
	mov r1, #1
	ldr r0, [r4, #8]
	lsl r1, r1, #0xe
	bl sub_02023F40
	ldrb r0, [r4, #2]
	add r0, r0, #1
	strb r0, [r4, #2]
_02230D5A:
	pop {r4, pc}
	thumb_func_end ov45_02230D20


	thumb_func_start ov45_02230D5C
ov45_02230D5C: ; 0x02230D5C
	push {r4, lr}
	add r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _02230D8A
	ldr r0, [r4, #4]
	mov r1, #6
	bl ov42_02228188
	add r1, r0, #0
	mov r0, #1
	bl ov45_022309C4
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl sub_02023EE0
	mov r1, #1
	ldr r0, [r4, #8]
	lsl r1, r1, #0xe
	bl sub_02023F40
	b _02230DB0
_02230D8A:
	cmp r0, #4
	bne _02230DB0
	ldr r0, [r4, #4]
	mov r1, #6
	bl ov42_02228188
	add r1, r0, #0
	mov r0, #1
	bl ov45_022309C4
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl sub_02023EE0
	mov r1, #3
	ldr r0, [r4, #8]
	lsl r1, r1, #0xe
	bl sub_02023F40
_02230DB0:
	ldrb r0, [r4, #2]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1d
	sub r1, r1, r2
	mov r0, #0x1d
	ror r1, r0
	add r0, r2, r1
	strb r0, [r4, #2]
	pop {r4, pc}
	thumb_func_end ov45_02230D5C


	thumb_func_start ov45_02230DC4
ov45_02230DC4: ; 0x02230DC4
	cmp r0, #0xb
	bhi _02230DF0
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02230DD4: ; jump table
	.short _02230DF0 - _02230DD4 - 2 ; case 0
	.short _02230DF0 - _02230DD4 - 2 ; case 1
	.short _02230DEC - _02230DD4 - 2 ; case 2
	.short _02230DEC - _02230DD4 - 2 ; case 3
	.short _02230DF0 - _02230DD4 - 2 ; case 4
	.short _02230DEC - _02230DD4 - 2 ; case 5
	.short _02230DEC - _02230DD4 - 2 ; case 6
	.short _02230DF0 - _02230DD4 - 2 ; case 7
	.short _02230DF0 - _02230DD4 - 2 ; case 8
	.short _02230DF0 - _02230DD4 - 2 ; case 9
	.short _02230DEC - _02230DD4 - 2 ; case 10
	.short _02230DEC - _02230DD4 - 2 ; case 11
_02230DEC:
	mov r0, #1
	bx lr
_02230DF0:
	mov r0, #0
	bx lr
	thumb_func_end ov45_02230DC4


	thumb_func_start ov45_02230DF4
ov45_02230DF4: ; 0x02230DF4
	push {r4, lr}
	add r4, r0, #0
	bl ov45_02230AA4
	cmp r0, #0
	beq _02230E24
	ldr r0, [r4, #8]
	bl ov45_02230E78
	cmp r0, #0
	ldrb r1, [r4]
	bne _02230E18
	mov r0, #0x30
	bic r1, r0
	mov r0, #0x10
	orr r0, r1
	strb r0, [r4]
	b _02230E1E
_02230E18:
	mov r0, #0x30
	bic r1, r0
	strb r1, [r4]
_02230E1E:
	add r0, r4, #0
	bl ov45_02230E28
_02230E24:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_02230DF4


	thumb_func_start ov45_02230E28
ov45_02230E28: ; 0x02230E28
	push {r4, lr}
	add r4, r0, #0
	ldrb r0, [r4]
	lsl r1, r0, #0x1a
	lsr r1, r1, #0x1e
	bne _02230E50
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1e
	cmp r0, #1
	bne _02230E50
	ldr r0, [r4, #8]
	mov r1, #1
	bl sub_02023EA4
	add r4, #0xc
	add r0, r4, #0
	mov r1, #1
	bl sub_020182A0
	pop {r4, pc}
_02230E50:
	ldr r0, [r4, #8]
	mov r1, #0
	bl sub_02023EA4
	add r4, #0xc
	add r0, r4, #0
	mov r1, #0
	bl sub_020182A0
	pop {r4, pc}
	thumb_func_end ov45_02230E28


	thumb_func_start ov45_02230E64
ov45_02230E64: ; 0x02230E64
	push {r4, lr}
	add r4, r1, #0
	bl sub_02023FDC
	add r4, #0x8c
	ldr r1, [r4]
	bl NNS_G3dMdlSetMdlLightEnableFlagAll
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_02230E64


	thumb_func_start ov45_02230E78
ov45_02230E78: ; 0x02230E78
	push {r3, r4, r5, r6, lr}
	sub sp, #0x44
	add r5, r0, #0
	bl sub_02023F90
	cmp r0, #0
	beq _02230E8C
	add r4, r0, #0
	add r4, #0x14
	b _02230E8E
_02230E8C:
	mov r4, #0
_02230E8E:
	add r0, r5, #0
	bl sub_02023E68
	add r3, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x38
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, sp, #0
	str r0, [r2]
	mov r0, #0x1e
	ldrsh r0, [r4, r0]
	strh r0, [r1, #0x24]
	mov r0, #0x20
	ldrsh r2, [r4, r0]
	strh r2, [r1, #0x26]
	ldrsh r0, [r4, r0]
	strh r0, [r1, #0x28]
	ldr r0, [r4, #0x24]
	asr r0, r0, #0xc
	str r0, [sp, #0x2c]
	ldr r0, [r4, #0x24]
	asr r0, r0, #0xc
	str r0, [sp, #0x30]
	ldr r0, [r4, #0x24]
	asr r0, r0, #0xc
	str r0, [sp, #0x34]
	mov r0, #0x18
	ldrsh r0, [r4, r0]
	ldr r2, [r4, #0x24]
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r3, #2
	mov r6, #0
	lsl r3, r3, #0xa
	add r3, r0, r3
	adc r1, r6
	lsl r0, r1, #0x14
	lsr r1, r3, #0xc
	ldr r2, [sp, #0x38]
	orr r1, r0
	add r0, r2, r1
	str r0, [sp, #0x38]
	mov r0, #0x1a
	ldrsh r0, [r4, r0]
	ldr r2, [r4, #0x24]
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r3, #2
	lsl r3, r3, #0xa
	add r3, r0, r3
	adc r1, r6
	lsl r0, r1, #0x14
	lsr r1, r3, #0xc
	ldr r2, [sp, #0x3c]
	orr r1, r0
	add r0, r2, r1
	str r0, [sp, #0x3c]
	mov r0, #0x1c
	ldrsh r0, [r4, r0]
	ldr r2, [r4, #0x24]
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r3, #2
	lsl r3, r3, #0xa
	add r3, r0, r3
	adc r1, r6
	lsl r0, r1, #0x14
	lsr r1, r3, #0xc
	ldr r2, [sp, #0x40]
	orr r1, r0
	add r0, r2, r1
	str r0, [sp, #0x40]
	mov r0, #0x20
	ldrsh r0, [r4, r0]
	ldr r2, [r4, #0x24]
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r3, #2
	add r4, r6, #0
	lsl r3, r3, #0xa
	add r3, r0, r3
	adc r1, r4
	lsl r0, r1, #0x14
	lsr r1, r3, #0xc
	ldr r2, [sp, #0x40]
	orr r1, r0
	sub r0, r2, r1
	str r0, [sp, #0x40]
	add r0, sp, #0
	bl MTX_Identity33_
	ldr r1, _02230F8C ; =NNS_G3dGlb + 0xBC
	add r0, sp, #0
	bl MI_Copy36B
	ldr r1, _02230F90 ; =NNS_G3dGlb + 0x80
	mov r0, #0xa4
	ldr r2, [r1, #0x7c]
	bic r2, r0
	add r0, r5, #0
	str r2, [r1, #0x7c]
	bl sub_02023E94
	bl NNS_G3dGlbSetBaseScale
	add r0, sp, #0x38
	add r1, sp, #0x24
	bl sub_0201FA34
	cmp r0, #0
	bne _02230F84
	add sp, #0x44
	add r0, r6, #0
	pop {r3, r4, r5, r6, pc}
_02230F84:
	mov r0, #1
	add sp, #0x44
	pop {r3, r4, r5, r6, pc}
	nop
_02230F8C: .word NNS_G3dGlb + 0xBC
_02230F90: .word NNS_G3dGlb + 0x80
	thumb_func_end ov45_02230E78


	thumb_func_start ov45_02230F94
ov45_02230F94: ; 0x02230F94
	push {r0, r1, r2, r3}
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r3, #0
	add r5, r0, #0
	add r6, r1, #0
	mov r0, #0x62
	add r1, r7, #0
	bl NARC_New
	add r1, sp, #0xc
	str r1, [sp]
	add r1, r7, #0
	mov r2, #0xdb
	mov r3, #3
	add r4, r0, #0
	bl ov45_02231018
	add r0, sp, #8
	str r0, [sp]
	add r0, r4, #0
	add r1, r7, #0
	add r2, r5, #0
	add r3, r6, #0
	bl ov45_02231018
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #8]
	sub r0, r1, r0
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	mov r0, #0x18
	mul r0, r1
	ldr r1, _02231014 ; =0x0000FFFF
	bl _s32_div_f
	cmp r0, #0
	bge _02230FE2
	add r0, #0x18
_02230FE2:
	cmp r0, #0x18
	blt _02230FEE
	mov r1, #0x18
	bl _s32_div_f
	add r0, r1, #0
_02230FEE:
	add r2, sp, #4
	mov r1, #0
	str r1, [r2]
	add r1, sp, #4
	strb r0, [r1]
	add r0, r2, #0
	add r1, sp, #0x30
	bl ov45_0222D524
	add r0, r4, #0
	bl NARC_Delete
	ldr r0, [sp, #4]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7}
	pop {r3}
	add sp, #0x10
	bx r3
	nop
_02231014: .word 0x0000FFFF
	thumb_func_end ov45_02230F94


	thumb_func_start ov45_02231018
ov45_02231018: ; 0x02231018
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r1, [sp, #0xc]
	str r3, [sp, #0x10]
	mov r7, #0
	add r5, r2, #0
	str r7, [sp]
	add r1, sp, #0x18
	str r1, [sp, #4]
	ldr r3, [sp, #0xc]
	mov r1, #0x12
	add r2, r7, #0
	str r0, [sp, #8]
	ldr r4, [sp, #0x30]
	bl GfGfxLoader_LoadFromOpenNarc_GetSizeOut
	add r6, r0, #0
	ldr r0, [sp, #0x18]
	mov r1, #6
	bl _u32_div_f
	cmp r5, r0
	blt _0223104A
	bl GF_AssertFail
_0223104A:
	mov r0, #6
	add r1, r5, #0
	mul r1, r0
	ldrh r0, [r6, r1]
	cmp r0, #2
	beq _02231060
	add r1, r6, r1
	mov r0, #4
	ldrsh r0, [r1, r0]
	mov r7, #1
	str r0, [r4]
_02231060:
	add r0, r6, #0
	bl Heap_Free
	cmp r7, #0
	bne _022310AC
	add r0, r5, #0
	bl LocationGmmDatIndexGetByCountryMsgNo
	bl LocationGmmDatGetEarthPlaceDatId
	mov r2, #0
	add r1, r0, #0
	str r2, [sp]
	add r0, sp, #0x14
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ldr r3, [sp, #0xc]
	bl GfGfxLoader_LoadFromOpenNarc_GetSizeOut
	add r5, r0, #0
	ldr r0, [sp, #0x14]
	lsr r1, r0, #2
	ldr r0, [sp, #0x10]
	cmp r0, r1
	bge _0223109C
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #2
	ldrsh r0, [r1, r0]
	b _022310A4
_0223109C:
	bl GF_AssertFail
	mov r0, #2
	ldrsh r0, [r5, r0]
_022310A4:
	str r0, [r4]
	add r0, r5, #0
	bl Heap_Free
_022310AC:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov45_02231018

	.rodata

_02254A28:
	.byte 0x02, 0x00, 0x50, 0x00, 0x01, 0x00, 0x02, 0x00
	.byte 0x03, 0x00, 0x8E, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x1E, 0x00

ov45_02254A3C: ; 0x02254A3C
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x68, 0x01, 0x00, 0x00, 0xD0, 0x02, 0x00, 0x00, 0xB0, 0x04, 0x00, 0x00, 0x18, 0x06, 0x00, 0x00
	.byte 0x80, 0x07, 0x00, 0x00, 0x60, 0x09, 0x00, 0x00, 0xC8, 0x0A, 0x00, 0x00, 0x30, 0x0C, 0x00, 0x00

ov45_02254A60: ; 0x02254A60
	.word ov45_0222BE9C
	.word ov45_0222BF18
	.word ov45_0222BF98
	.word ov45_0222C0CC
	.word ov45_0222C130
	.word ov45_0222C1EC
	.word ov45_0222C36C
	.word ov45_0222C36C
	.word ov45_0222C2A8

ov45_02254A84: ; 0x02254A84
	.byte 0x03, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00
	.byte 0x1F, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00
	.byte 0x46, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00, 0x07, 0x00, 0x01, 0x00, 0x0D, 0x00, 0x01, 0x00
	.byte 0x0E, 0x00, 0x01, 0x00, 0x23, 0x00, 0x01, 0x00, 0x25, 0x00, 0x01, 0x00, 0x2A, 0x00, 0x01, 0x00
	.byte 0x3F, 0x00, 0x01, 0x00

ov45_02254AC4: ; 0x02254AC4
	.word ov45_0222C688
	.byte 0x04, 0x00, 0x00, 0x00
	.word ov45_0222C73C
	.byte 0x04, 0x00, 0x00, 0x00
	.word ov45_0222C79C
	.byte 0x04, 0x00, 0x00, 0x00
	.word ov45_0222C800
	.byte 0x04, 0x00, 0x00, 0x00
	.word ov45_0222C828
	.byte 0x14, 0x00, 0x00, 0x00
	.word ov45_0222C83C
	.byte 0x04, 0x00, 0x00, 0x00
	.word ov45_0222C858
	.byte 0x04, 0x00, 0x00, 0x00
	.word ov45_0222C88C
	.byte 0x04, 0x00, 0x00, 0x00

ov45_02254B04: ; 0x02254B04
	.word ov46_02258CB4
	.word ov46_02258DA8
	.word ov46_02258EFC
	.word FS_OVERLAY_ID(OVY_46)

ov45_02254B14: ; 0x02254B14
	.word ov89_02258800
	.word ov89_02258B04
	.word ov89_02258F00
	.word FS_OVERLAY_ID(OVY_89)

ov45_02254B24: ; 0x02254B24
	.word ov89_02258800
	.word ov89_02258B04
	.word ov89_02258F00
	.word FS_OVERLAY_ID(OVY_89)

ov45_02254B34: ; 0x02254B34
	.word ov93_0225C540
	.word ov93_0225C574
	.word ov93_0225C6C0
	.word FS_OVERLAY_ID(OVY_93)

ov45_02254B44: ; 0x02254B44
	.word ov47_02258800
	.word ov47_02258898
	.word ov47_022589A8
	.word FS_OVERLAY_ID(OVY_47)

ov45_02254B54: ; 0x02254B54
	.word ov91_0225C540
	.word ov91_0225C58C
	.word ov91_0225C9EC
	.word FS_OVERLAY_ID(OVY_91)

ov45_02254B64: ; 0x02254B64
	.word ov46_02258800
	.word ov46_0225892C
	.word ov46_02258C38
	.word FS_OVERLAY_ID(OVY_46)

ov45_02254B74: ; 0x02254B74
	.word ov88_02258800
	.word ov88_022588C4
	.word ov88_022589FC
	.word FS_OVERLAY_ID(OVY_88)

ov45_02254B84: ; 0x02254B84
	.word ov48_02258800
	.word ov48_02258920
	.word ov48_022589FC
	.word FS_OVERLAY_ID(OVY_48)

ov45_02254B94: ; 0x02254B94
	.word ov49_02259AA4
	.word ov49_02259C90
	.word ov49_02259EF8
	.word FS_OVERLAY_ID(OVY_49)

ov45_02254BA4: ; 0x02254BA4
	.word ov92_0225CAB4
	.word ov92_0225CDF4
	.word ov92_0225D36C
	.word FS_OVERLAY_ID(OVY_92)

ov45_02254BB4: ; 0x02254BB4
	.byte 0x09, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0A, 0x0B
	.byte 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x00, 0x00

ov45_02254BC8: ; 0x02254BC8
	.byte 0x0B, 0x0A

ov45_02254BCA: ; 0x02254BCA
	.byte 0x09, 0x00, 0x16, 0x00, 0x18, 0x00
	.byte 0x19, 0x00

ov45_02254BD2: ; 0x02254BD2
	.byte 0x1A, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x1C, 0x00, 0x17, 0x00

ov45_02254BDC: ; 0x02254BDC
	.byte 0x04, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00

ov45_02254BE8: ; 0x02254BE8
	.word ov45_0222E540
	.word ov45_0222E550
	.word ov45_0222E560
	.word ov45_0222E574
	.word ov45_0222E584
	.word ov45_0222E584
	.word ov45_0222E598
	.word ov45_0222E59C
	.word ov45_0222E5A0

ov45_02254C0C: ; 0x02254C0C
	.word ov45_0222E14C
	.word ov45_0222E1A0
	.word ov45_0222E200
	.word ov45_0222E33C
	.word ov45_0222E39C
	.word ov45_0222E39C
	.word ov45_0222E414
	.word ov45_0222E484
	.word ov45_0222E4A8

ov45_02254C30: ; 0x02254C30
	.byte 0x08, 0x08, 0x04, 0x04

ov45_02254C34: ; 0x02254C34
	.byte 0x01, 0x02, 0x00, 0x03

ov45_02254C38: ; 0x02254C38
	.byte 0x18, 0x01, 0x19, 0x01

ov45_02254C3C: ; 0x02254C3C
	.byte 0x00, 0x10, 0x00, 0x00
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00

ov45_02254C48: ; 0x02254C48
	.byte 0x00, 0x00, 0x45, 0x80, 0x61, 0x00, 0x46, 0x80
	.byte 0x03, 0x00, 0x02, 0x00, 0x05, 0x00, 0x04, 0x00, 0x0B, 0x00, 0x0A, 0x00, 0x1F, 0x00, 0x24, 0x00
	.byte 0x32, 0x00, 0x2F, 0x00, 0x33, 0x00, 0x30, 0x00, 0x3E, 0x00, 0x1B, 0x00, 0x46, 0x00, 0x21, 0x00
	.byte 0x06, 0x00, 0x05, 0x00, 0x07, 0x00, 0x06, 0x00, 0x0D, 0x00, 0x0D, 0x00, 0x0E, 0x00, 0x0E, 0x00
	.byte 0x23, 0x00, 0x26, 0x00, 0x25, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2B, 0x00, 0x3F, 0x00, 0x1C, 0x00
	.byte 0x1E, 0x01, 0x66, 0x00, 0x1D, 0x01, 0x65, 0x00

ov45_02254C98: ; 0x02254C98
	.byte 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x20, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00
	.byte 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x5F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x60, 0x00, 0x00, 0x00, 0x6F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00
	.byte 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00

	.data

_02254E20:
	.word ov45_0222CF24
	.word ov45_0222D01C
	.word ov45_0222D0BC
	.word ov45_0222D380
	.word ov45_0222D380
	.word ov45_0222D130
	.word ov45_0222D19C
	.word ov45_0222D23C
	.word ov45_0222D2E4
	.word ov45_0222D410
	.word ov45_0222D410
	.word ov45_0222D4C0
	.word ov45_0222D4C0

ov45_02254E54: ; 0x02254E54
	.word ov45_0222CF40
	.word ov45_0222D028
	.word ov45_0222D0C8
	.word ov45_0222D3B0
	.word ov45_0222D3C4
	.word ov45_0222D13C
	.word ov45_0222D1B0
	.word ov45_0222D250
	.word ov45_0222D2F8
	.word ov45_0222D41C
	.word ov45_0222D428
	.word ov45_0222D4CC
	.word ov45_0222D4CC

ov45_02254E88: ; 0x02254E88
	.word ov45_0222CF00
	.word ov45_0222CFF4
	.word ov45_0222D078
	.word ov45_0222D354
	.word ov45_0222D354
	.word ov45_0222D0FC
	.word ov45_0222D164
	.word ov45_0222D20C
	.word ov45_0222D2AC
	.word ov45_0222D3D8
	.word ov45_0222D3D8
	.word ov45_0222D44C
	.word ov45_0222D484

ov45_02254EBC: ; 0x02254EBC
	.word ov45_0222CF68
	.word ov45_0222D054
	.word ov45_0222D0D8
	.word ov45_0222D38C
	.word ov45_0222D38C
	.word ov45_0222D14C
	.word ov45_0222D1DC
	.word ov45_0222D27C
	.word ov45_0222D324
	.word ov45_0222D448
	.word ov45_0222D448
	.word ov45_0222D4DC
	.word ov45_0222D4DC

ov45_02254EF0: ; 0x02254EF0
	.word ov45_02254EF4

	.balign 4, 0
ov45_02254EF4:
	.asciz "b_lby_wlddata"

	.balign 4, 0
ov45_02254F04: ; 0x02254F04
	.asciz "pokemonplatds"

	.balign 4, 0
ov45_02254F14: ; 0x02254F14
	.asciz "IIup73"

	.balign 4, 0
ov45_02254F1C: ; 0x02254F1C
	.word ov45_02230CD8
	.word ov45_02230D20
	.word ov45_02230D5C

ov45_02254F28: ; 0x02254F28
	.word ov45_02230B64
	.word ov45_02230BFC
	.word ov45_02230B8C
	.word ov45_02230C40
	.word ov45_02230B64
	.word ov45_02230B8C
	.word ov45_02230B8C
	.word ov45_02230B8C
	.word ov45_02230B8C
	.word ov45_02230B8C
	.word ov45_02230B8C
	.word 0

	.bss

_022577C0:
	.space 0x4

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

	thumb_func_start ov45_0222F7B4
ov45_0222F7B4: ; 0x0222F7B4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp, #4]
	ldr r0, [r0, #8]
	bl WifiHistory_GetPlayerCountry
	add r4, r0, #0
	ldr r0, [sp, #4]
	ldr r0, [r0, #8]
	bl WiFiHistory_GetPlayerRegion
	cmp r4, #0
	bne _0222F7D4
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222F7D4:
	ldr r7, _0222F840 ; =0x00000136
	ldr r2, [sp, #4]
	mov r1, #0
	sub r3, r7, #2
	add r5, r7, #1
_0222F7DE:
	ldrb r6, [r2, r5]
	cmp r6, #0
	beq _0222F7FE
	ldrh r6, [r2, r3]
	cmp r4, r6
	bne _0222F7F6
	ldrb r6, [r2, r7]
	cmp r0, r6
	bne _0222F7F6
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222F7F6:
	add r1, r1, #1
	add r2, r2, #4
	cmp r1, #0x14
	blt _0222F7DE
_0222F7FE:
	cmp r1, #0x14
	blt _0222F80C
	bl GF_AssertFail
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222F80C:
	lsl r2, r1, #2
	ldr r1, [sp, #4]
	mov r3, #0x4d
	add r2, r1, r2
	lsl r3, r3, #2
	strh r4, [r2, r3]
	add r1, r3, #2
	strb r0, [r2, r1]
	mov r1, #1
	add r0, r3, #3
	strb r1, [r2, r0]
	mov r0, #0x50
	str r0, [sp]
	ldr r2, _0222F844 ; =ov45_02254EF0
	ldr r4, [sp, #4]
	ldr r2, [r2]
	sub r0, #0x51
	mov r1, #0
	add r3, r4, r3
	bl ov45_022322A4
	bl ov45_0222F74C
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222F840: .word 0x00000136
_0222F844: .word ov45_02254EF0
	thumb_func_end ov45_0222F7B4


	thumb_func_start ov45_0222F848
ov45_0222F848: ; 0x0222F848
	push {r3, r4, r5, lr}
	add r5, r1, #0
	mov r0, #0x14
	add r4, r5, #0
	mul r4, r0
	add r0, r2, #0
	add r1, r4, #0
	bl Heap_Alloc
	ldr r1, _0222F874 ; =_022577C0
	ldr r2, [r1]
	str r0, [r2, #0x24]
	ldr r0, [r1]
	mov r1, #0
	ldr r0, [r0, #0x24]
	add r2, r4, #0
	bl memset
	ldr r0, _0222F874 ; =_022577C0
	ldr r0, [r0]
	str r5, [r0, #0x28]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222F874: .word _022577C0
	thumb_func_end ov45_0222F848


	thumb_func_start ov45_0222F878
ov45_0222F878: ; 0x0222F878
	ldr r0, _0222F884 ; =_022577C0
	ldr r3, _0222F888 ; =Heap_Free
	ldr r0, [r0]
	ldr r0, [r0, #0x24]
	bx r3
	nop
_0222F884: .word _022577C0
_0222F888: .word Heap_Free
	thumb_func_end ov45_0222F878


	thumb_func_start ov45_0222F88C
ov45_0222F88C: ; 0x0222F88C
	push {r3, lr}
	ldr r3, [r0, #0x28]
	bl ov45_0222F898
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov45_0222F88C


	thumb_func_start ov45_0222F898
ov45_0222F898: ; 0x0222F898
	push {r3, r4, r5, r6, r7, lr}
	str r2, [sp]
	mov r2, #0
	add r4, r0, #0
	add r6, r3, #0
	bl ov45_0222FB24
	add r7, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r7, r0
	bne _0222F8B4
	bl GF_AssertFail
_0222F8B4:
	ldr r2, [r4, #0x28]
	ldr r5, [r4, #0x24]
	add r4, r2, #0
	mul r4, r7
	cmp r2, r6
	bls _0222F8CA
	add r0, r5, r4
	mov r1, #0
	bl memset
	b _0222F8CC
_0222F8CA:
	add r6, r2, #0
_0222F8CC:
	ldr r1, [sp]
	add r0, r5, r4
	add r2, r6, #0
	bl memcpy
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222F898


	thumb_func_start ov45_0222F8D8
ov45_0222F8D8: ; 0x0222F8D8
	push {r3, r4, r5, lr}
	mov r2, #0
	add r5, r0, #0
	bl ov45_0222FB24
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _0222F8F0
	bl GF_AssertFail
_0222F8F0:
	ldr r0, [r5, #0x28]
	ldr r2, [r5, #0x24]
	add r1, r0, #0
	mul r1, r4
	add r0, r2, r1
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222F8D8


	thumb_func_start ov45_0222F8FC
ov45_0222F8FC: ; 0x0222F8FC
	push {r3, r4, r5, lr}
	mov r2, #0
	add r5, r0, #0
	bl ov45_0222FB24
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _0222F914
	bl GF_AssertFail
_0222F914:
	ldr r2, [r5, #0x28]
	ldr r1, [r5, #0x24]
	add r0, r2, #0
	mul r0, r4
	add r0, r1, r0
	mov r1, #0
	bl memset
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222F8FC


	thumb_func_start ov45_0222F928
ov45_0222F928: ; 0x0222F928
	push {r4, r5, r6, lr}
	add r4, r2, #0
	mov r2, #0
	add r5, r0, #0
	bl ov45_0222FB24
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	bne _0222F942
	bl GF_AssertFail
_0222F942:
	mov r0, #0xc
	mul r0, r6
	add r2, r5, r0
	ldmia r4!, {r0, r1}
	add r2, #0x2c
	stmia r2!, {r0, r1}
	ldr r0, [r4]
	str r0, [r2]
	pop {r4, r5, r6, pc}
	thumb_func_end ov45_0222F928


	thumb_func_start ov45_0222F954
ov45_0222F954: ; 0x0222F954
	push {r3, r4, r5, lr}
	mov r2, #0
	add r5, r0, #0
	bl ov45_0222FB24
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _0222F96C
	bl GF_AssertFail
_0222F96C:
	mov r0, #0xc
	add r5, #0x2c
	mul r0, r4
	add r0, r5, r0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222F954


	thumb_func_start ov45_0222F978
ov45_0222F978: ; 0x0222F978
	push {r3, r4, r5, lr}
	mov r2, #0
	add r5, r0, #0
	bl ov45_0222FB24
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _0222F990
	bl GF_AssertFail
_0222F990:
	mov r0, #0xc
	add r1, r4, #0
	mul r1, r0
	add r5, #0x2c
	mov r0, #0
	add r2, r5, r1
	strb r0, [r5, r1]
	strb r0, [r2, #1]
	strb r0, [r2, #2]
	strb r0, [r2, #3]
	strb r0, [r2, #4]
	strb r0, [r2, #5]
	strb r0, [r2, #6]
	strb r0, [r2, #7]
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	strb r0, [r2, #0xa]
	strb r0, [r2, #0xb]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222F978


	thumb_func_start ov45_0222F9B8
ov45_0222F9B8: ; 0x0222F9B8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	mov r4, #0
	add r5, r7, #0
_0222F9C8:
	mov r0, #0x12
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0222F9D6
	bl GF_AssertFail
_0222F9D6:
	cmp r4, #0
	bne _0222F9DE
	ldr r6, [sp]
	b _0222F9E0
_0222F9DE:
	ldr r6, [sp, #4]
_0222F9E0:
	mov r0, #0x47
	mov r1, #0
	lsl r0, r0, #2
	strh r1, [r5, r0]
	ldr r0, [sp, #8]
	lsl r1, r6, #2
	bl Heap_Alloc
	mov r1, #0x12
	lsl r1, r1, #4
	str r0, [r5, r1]
	sub r0, r1, #2
	strh r6, [r5, r0]
	add r0, r7, #0
	add r1, r4, #0
	bl ov45_0222FA40
	add r4, r4, #1
	add r5, #8
	cmp r4, #2
	blt _0222F9C8
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222F9B8


	thumb_func_start ov45_0222FA10
ov45_0222FA10: ; 0x0222FA10
	push {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	mov r7, #0x12
	add r5, r0, #0
	add r6, r4, #0
	lsl r7, r7, #4
_0222FA1C:
	ldr r0, [r5, r7]
	cmp r0, #0
	bne _0222FA26
	bl GF_AssertFail
_0222FA26:
	mov r0, #0x12
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl Heap_Free
	mov r0, #0x12
	lsl r0, r0, #4
	str r6, [r5, r0]
	add r4, r4, #1
	add r5, #8
	cmp r4, #2
	blt _0222FA1C
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222FA10


	thumb_func_start ov45_0222FA40
ov45_0222FA40: ; 0x0222FA40
	push {r3, r4, r5, r6}
	lsl r2, r1, #3
	add r0, r0, r2
	mov r2, #0x47
	mov r1, #0
	lsl r2, r2, #2
	strh r1, [r0, r2]
	add r2, r2, #2
	ldrh r2, [r0, r2]
	cmp r2, #0
	ble _0222FA6E
	mov r2, #0x12
	lsl r2, r2, #4
	add r6, r1, #0
	sub r5, r1, #1
	sub r3, r2, #2
_0222FA60:
	ldr r4, [r0, r2]
	add r1, r1, #1
	str r5, [r4, r6]
	ldrh r4, [r0, r3]
	add r6, r6, #4
	cmp r1, r4
	blt _0222FA60
_0222FA6E:
	pop {r3, r4, r5, r6}
	bx lr
	.balign 4, 0
	thumb_func_end ov45_0222FA40


	thumb_func_start ov45_0222FA74
ov45_0222FA74: ; 0x0222FA74
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	str r1, [sp]
	add r4, r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _0222FAF0
	ldr r0, _0222FAF4 ; =0x0000011E
	lsl r4, r4, #3
	add r5, r7, r0
	sub r0, r0, #2
	add r1, r7, r0
	add r0, r1, r4
	str r0, [sp, #4]
	ldrsh r1, [r1, r4]
	ldrh r0, [r5, r4]
	cmp r1, r0
	blt _0222FAA4
	bl GF_AssertFail
_0222FAA4:
	ldr r1, [sp, #4]
	mov r0, #0
	ldrh r2, [r5, r4]
	ldrsh r1, [r1, r0]
	cmp r1, r2
	bge _0222FAF0
	cmp r2, #0
	ble _0222FAD4
	mov r1, #0x12
	add r2, r7, r4
	lsl r1, r1, #4
	ldr r1, [r2, r1]
	ldr r3, _0222FAF4 ; =0x0000011E
	sub r5, r0, #1
_0222FAC0:
	ldr r6, [r1]
	cmp r6, r5
	bne _0222FACA
	str r0, [sp, #8]
	b _0222FAD4
_0222FACA:
	ldrh r6, [r2, r3]
	add r0, r0, #1
	add r1, r1, #4
	cmp r0, r6
	blt _0222FAC0
_0222FAD4:
	mov r0, #0x12
	add r1, r7, r4
	lsl r0, r0, #4
	ldr r2, [r1, r0]
	ldr r0, [sp, #8]
	lsl r1, r0, #2
	ldr r0, [sp]
	str r0, [r2, r1]
	ldr r0, [sp, #4]
	mov r1, #0
	ldrsh r0, [r0, r1]
	add r1, r0, #1
	ldr r0, [sp, #4]
	strh r1, [r0]
_0222FAF0:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222FAF4: .word 0x0000011E
	thumb_func_end ov45_0222FA74


	thumb_func_start ov45_0222FAF8
ov45_0222FAF8: ; 0x0222FAF8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FB22
	lsl r2, r4, #3
	mov r3, #0x12
	add r4, r5, r2
	lsl r3, r3, #4
	ldr r4, [r4, r3]
	lsl r0, r0, #2
	str r1, [r4, r0]
	sub r0, r3, #4
	add r1, r5, r0
	ldrsh r0, [r1, r2]
	sub r0, r0, #1
	strh r0, [r1, r2]
_0222FB22:
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222FAF8


	thumb_func_start ov45_0222FB24
ov45_0222FB24: ; 0x0222FB24
	push {r4, r5}
	lsl r2, r2, #3
	add r0, r0, r2
	ldr r2, _0222FB58 ; =0x0000011E
	mov r3, #0
	ldrh r4, [r0, r2]
	cmp r4, #0
	ble _0222FB50
	add r2, r2, #2
	ldr r5, [r0, r2]
	ldr r2, _0222FB58 ; =0x0000011E
_0222FB3A:
	ldr r4, [r5]
	cmp r1, r4
	bne _0222FB46
	add r0, r3, #0
	pop {r4, r5}
	bx lr
_0222FB46:
	ldrh r4, [r0, r2]
	add r3, r3, #1
	add r5, r5, #4
	cmp r3, r4
	blt _0222FB3A
_0222FB50:
	mov r0, #0
	mvn r0, r0
	pop {r4, r5}
	bx lr
	.balign 4, 0
_0222FB58: .word 0x0000011E
	thumb_func_end ov45_0222FB24


	thumb_func_start ov45_0222FB5C
ov45_0222FB5C: ; 0x0222FB5C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	lsl r6, r2, #3
	add r4, r1, #0
	ldr r0, _0222FB80 ; =0x0000011E
	add r1, r5, r6
	ldrh r0, [r1, r0]
	cmp r4, r0
	blt _0222FB72
	bl GF_AssertFail
_0222FB72:
	mov r0, #0x12
	add r1, r5, r6
	lsl r0, r0, #4
	ldr r1, [r1, r0]
	lsl r0, r4, #2
	ldr r0, [r1, r0]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222FB80: .word 0x0000011E
	thumb_func_end ov45_0222FB5C


	thumb_func_start ov45_0222FB84
ov45_0222FB84: ; 0x0222FB84
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r0, r1, #0
	bl ov45_0222F7B0
	add r7, r0, #0
	add r0, r5, #0
	mov r1, #1
	bl ov45_0222FA40
	ldr r0, _0222FBD4 ; =0x0000011E
	mov r4, #0
	ldrh r0, [r5, r0]
	cmp r0, #0
	ble _0222FBD2
	add r6, r5, #0
_0222FBA4:
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #0
	bl ov45_0222FB5C
	add r1, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	beq _0222FBC6
	ldr r0, [r6, #0x34]
	cmp r7, r0
	bne _0222FBC6
	add r0, r5, #0
	mov r2, #1
	bl ov45_0222FA74
_0222FBC6:
	ldr r0, _0222FBD4 ; =0x0000011E
	add r4, r4, #1
	ldrh r0, [r5, r0]
	add r6, #0xc
	cmp r4, r0
	blt _0222FBA4
_0222FBD2:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222FBD4: .word 0x0000011E
	thumb_func_end ov45_0222FB84


	thumb_func_start ov45_0222FBD8
ov45_0222FBD8: ; 0x0222FBD8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	str r1, [sp]
	cmp r1, #4
	blt _0222FBE8
	bl GF_AssertFail
_0222FBE8:
	ldr r0, [sp]
	bl ov45_0222F7B0
	str r0, [sp, #4]
	ldr r0, _0222FC3C ; =0x0000011E
	mov r7, #0
	ldrh r0, [r6, r0]
	add r4, r7, #0
	cmp r0, #0
	ble _0222FC26
	add r5, r6, #0
_0222FBFE:
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0
	bl ov45_0222FB5C
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FC1A
	ldr r1, [r5, #0x34]
	ldr r0, [sp, #4]
	cmp r0, r1
	bne _0222FC1A
	add r7, r7, #1
_0222FC1A:
	ldr r0, _0222FC3C ; =0x0000011E
	add r4, r4, #1
	ldrh r0, [r6, r0]
	add r5, #0xc
	cmp r4, r0
	blt _0222FBFE
_0222FC26:
	ldr r1, _0222FC40 ; =ov45_02254C30
	ldr r0, [sp]
	ldrb r0, [r1, r0]
	cmp r0, r7
	ble _0222FC36
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0222FC36:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222FC3C: .word 0x0000011E
_0222FC40: .word ov45_02254C30
	thumb_func_end ov45_0222FBD8


	thumb_func_start ov45_0222FC44
ov45_0222FC44: ; 0x0222FC44
	push {r3, r4, r5, lr}
	add r5, r0, #0
	cmp r1, #0
	bne _0222FC84
	ldr r0, _0222FCD0 ; =_022577C0
	mov r3, #1
	ldr r2, [r0]
	ldr r1, _0222FCD4 ; =0x000005B4
	lsl r3, r3, #0xa
	str r3, [r2, r1]
	ldr r2, [r0]
	mov r0, #0x6d
	lsl r0, r0, #2
	add r0, r2, r0
	add r1, r2, r1
	bl ov45_02232170
	bl ov45_0222F74C
	cmp r0, #0
	bne _0222FC72
	bl GF_AssertFail
_0222FC72:
	ldr r2, _0222FCD8 ; =ov45_02254EF0
	mov r0, #0
	mov r1, #0
	ldr r2, [r2]
	mvn r0, r0
	add r3, r1, #0
	bl ov45_02232304
	pop {r3, r4, r5, pc}
_0222FC84:
	ldr r0, _0222FCD0 ; =_022577C0
	ldr r4, [r0]
	add r0, r1, #0
	bl ov45_0222F7A8
	ldr r1, _0222FCDC ; =0x0000012D
	ldrb r2, [r4, r1]
	cmp r2, r0
	bne _0222FCC4
	cmp r5, #1
	bne _0222FCBC
	mov r2, #1
	add r0, r1, #2
	strb r2, [r4, r0]
	ldr r0, _0222FCD0 ; =_022577C0
	ldr r0, [r0]
	ldrb r1, [r0, r1]
	bl ov45_0222FB84
	bl ov45_02232580
	add r1, r0, #0
	ldr r0, _0222FCD0 ; =_022577C0
	mov r2, #1
	ldr r0, [r0]
	bl ov45_0222FA74
	pop {r3, r4, r5, pc}
_0222FCBC:
	mov r2, #2
	add r0, r1, #2
	strb r2, [r4, r0]
	pop {r3, r4, r5, pc}
_0222FCC4:
	bl GF_AssertFail
	bl ov45_0222EB94
	pop {r3, r4, r5, pc}
	nop
_0222FCD0: .word _022577C0
_0222FCD4: .word 0x000005B4
_0222FCD8: .word ov45_02254EF0
_0222FCDC: .word 0x0000012D
	thumb_func_end ov45_0222FC44


	thumb_func_start ov45_0222FCE0
ov45_0222FCE0: ; 0x0222FCE0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp]
	bl ov45_02232580
	cmp r5, r0
	bne _0222FD04
	ldr r0, _0222FD4C ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x67
	lsl r0, r0, #2
	add r0, r1, r0
	bl ov45_022320C4
	mov r4, #1
	b _0222FD06
_0222FD04:
	mov r4, #0
_0222FD06:
	ldr r0, _0222FD4C ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #0
	bl ov45_0222FA74
	ldr r0, _0222FD4C ; =_022577C0
	ldr r3, [sp]
	ldr r0, [r0]
	add r1, r5, #0
	add r2, r7, #0
	bl ov45_0222F898
	ldr r0, _0222FD4C ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	add r2, r6, #0
	bl ov45_0222F928
	ldr r0, _0222FD4C ; =_022577C0
	add r1, r5, #0
	ldr r6, [r0]
	add r0, r6, #0
	bl ov45_0222F8D8
	add r3, r4, #0
	ldr r4, _0222FD4C ; =_022577C0
	add r1, r0, #0
	ldr r4, [r4]
	ldr r2, [r6, #0x20]
	ldr r4, [r4, #0xc]
	add r0, r5, #0
	blx r4
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222FD4C: .word _022577C0
	thumb_func_end ov45_0222FCE0


	thumb_func_start ov45_0222FD50
ov45_0222FD50: ; 0x0222FD50
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FDC8
	mov r6, #0
	ldr r7, _0222FDCC ; =_022577C0
	add r4, r6, #0
_0222FD6E:
	ldr r1, [r7]
	mov r0, #6
	add r2, r1, r4
	lsl r0, r0, #8
	ldr r0, [r2, r0]
	cmp r5, r0
	bne _0222FD88
	ldr r2, _0222FDD0 ; =0x000005B8
	add r0, r5, #0
	add r1, r1, r2
	add r1, r1, r4
	bl ov45_02230008
_0222FD88:
	add r6, r6, #1
	add r4, #0x4c
	cmp r6, #3
	blt _0222FD6E
	ldr r0, _0222FDCC ; =_022577C0
	ldr r2, [r0]
	add r0, r5, #0
	ldr r1, [r2, #0x20]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	bl ov45_0222F978
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	bl ov45_0222F8FC
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #0
	bl ov45_0222FAF8
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #1
	bl ov45_0222FAF8
_0222FDC8:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222FDCC: .word _022577C0
_0222FDD0: .word 0x000005B8
	thumb_func_end ov45_0222FD50

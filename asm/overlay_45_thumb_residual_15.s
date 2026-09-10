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

	thumb_func_start ov45_0222B0BC
ov45_0222B0BC: ; 0x0222B0BC
	push {r4, lr}
	add r4, r0, #0
	bl ov45_0222AFF8
	cmp r0, #1
	bne _0222B0D6
	mov r1, #7
	lsl r1, r1, #6
	add r0, r4, r1
	add r1, r1, #4
	ldrh r1, [r4, r1]
	bl ov45_0222BDCC
_0222B0D6:
	pop {r4, pc}
	thumb_func_end ov45_0222B0BC


	thumb_func_start ov45_0222B0D8
ov45_0222B0D8: ; 0x0222B0D8
	mov r2, #7
	lsl r2, r2, #6
	ldr r3, _0222B0E4 ; =ov45_0222BDCC
	add r0, r0, r2
	bx r3
	nop
_0222B0E4: .word ov45_0222BDCC
	thumb_func_end ov45_0222B0D8


	thumb_func_start ov45_0222B0E8
ov45_0222B0E8: ; 0x0222B0E8
	mov r2, #7
	lsl r2, r2, #6
	ldr r3, _0222B0F4 ; =ov45_0222BD94
	add r0, r0, r2
	bx r3
	nop
_0222B0F4: .word ov45_0222BD94
	thumb_func_end ov45_0222B0E8


	thumb_func_start IncrementGameStat47
IncrementGameStat47: ; 0x0222B0F8
	push {r3, lr}
	ldr r0, [r0]
	bl Save_GameStats_Get
	mov r1, #0x2f ; GAME_STAT_UNK47
	bl GameStats_Inc
	pop {r3, pc}
	thumb_func_end IncrementGameStat47


	thumb_func_start IncrementGameStat119
IncrementGameStat119: ; 0x0222B108
	push {r3, lr}
	ldr r0, [r0]
	bl Save_GameStats_Get
	mov r1, #0x77 ; GAME_STAT_UNK119
	bl GameStats_Inc
	pop {r3, pc}
	thumb_func_end IncrementGameStat119


	thumb_func_start ov45_0222B118
ov45_0222B118: ; 0x0222B118
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #8
	blt _0222B126
	bl GF_AssertFail
_0222B126:
	mov r0, #0xe9
	mov r2, #1
	add r1, r5, r4
	lsl r0, r0, #2
	strb r2, [r1, r0]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov45_0222B118


	thumb_func_start ov45_0222B134
ov45_0222B134: ; 0x0222B134
	push {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	mov r6, #0xe9
	add r5, r0, #0
	add r7, r4, #0
	lsl r6, r6, #2
_0222B140:
	add r0, r5, r4
	ldrb r0, [r0, r6]
	cmp r0, #0
	bne _0222B1A8
	cmp r4, #7
	bhi _0222B19E
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222B158: ; jump table
	.short _0222B168 - _0222B158 - 2 ; case 0
	.short _0222B168 - _0222B158 - 2 ; case 1
	.short _0222B168 - _0222B158 - 2 ; case 2
	.short _0222B17A - _0222B158 - 2 ; case 3
	.short _0222B17A - _0222B158 - 2 ; case 4
	.short _0222B17A - _0222B158 - 2 ; case 5
	.short _0222B18C - _0222B158 - 2 ; case 6
	.short _0222B19E - _0222B158 - 2 ; case 7
_0222B168:
	add r0, r5, #0
	bl ov45_0222A394
	cmp r0, #1
	bne _0222B176
	add r0, r7, #0
	b _0222B1A0
_0222B176:
	mov r0, #1
	b _0222B1A0
_0222B17A:
	add r0, r5, #0
	bl ov45_0222A330
	cmp r0, #1
	bne _0222B188
	mov r0, #0
	b _0222B1A0
_0222B188:
	mov r0, #1
	b _0222B1A0
_0222B18C:
	add r0, r5, #0
	bl ov45_0222A3A0
	cmp r0, #1
	bne _0222B19A
	mov r0, #0
	b _0222B1A0
_0222B19A:
	mov r0, #1
	b _0222B1A0
_0222B19E:
	mov r0, #1
_0222B1A0:
	cmp r0, #1
	bne _0222B1A8
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222B1A8:
	add r4, r4, #1
	cmp r4, #8
	blt _0222B140
	mov r0, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222B134


	thumb_func_start ov45_0222B1B4
ov45_0222B1B4: ; 0x0222B1B4
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r0, #0xeb
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222C900
	add r5, r0, #0
	add r0, r4, #0
	bl ov45_0222A53C
	add r1, r0, #0
	add r0, r4, #0
	bl ov45_0222AB28
	cmp r0, #1
	bne _0222B1D8
	add r5, r5, #2
_0222B1D8:
	add r0, r5, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222B1B4


	thumb_func_start ov45_0222B1DC
ov45_0222B1DC: ; 0x0222B1DC
	ldr r1, _0222B1E4 ; =0x0000049C
	ldr r3, _0222B1E8 ; =ov45_0222CB40
	add r0, r0, r1
	bx r3
	.balign 4, 0
_0222B1E4: .word 0x0000049C
_0222B1E8: .word ov45_0222CB40
	thumb_func_end ov45_0222B1DC


	thumb_func_start ov45_0222B1EC
ov45_0222B1EC: ; 0x0222B1EC
	ldr r1, _0222B1F4 ; =0x0000049C
	ldr r3, _0222B1F8 ; =ov45_0222CB3C
	add r0, r0, r1
	bx r3
	.balign 4, 0
_0222B1F4: .word 0x0000049C
_0222B1F8: .word ov45_0222CB3C
	thumb_func_end ov45_0222B1EC


	thumb_func_start ov45_0222B1FC
ov45_0222B1FC: ; 0x0222B1FC
	add r3, r1, #0
	ldr r1, _0222B218 ; =0x00000524
	mov r2, #1
	str r2, [r0, r1]
	sub r1, #0x14
	add r2, r0, r1
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	bx lr
	nop
_0222B218: .word 0x00000524
	thumb_func_end ov45_0222B1FC


	thumb_func_start ov45_0222B21C
ov45_0222B21C: ; 0x0222B21C
	add r3, r1, #0
	ldr r1, _0222B240 ; =0x00000524
	ldr r2, [r0, r1]
	cmp r2, #1
	bne _0222B23A
	sub r1, #0x14
	add r2, r0, r1
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
	mov r0, #1
	bx lr
_0222B23A:
	mov r0, #0
	bx lr
	nop
_0222B240: .word 0x00000524
	thumb_func_end ov45_0222B21C


	thumb_func_start ov45_0222B244
ov45_0222B244: ; 0x0222B244
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222B268 ; =0x000004B8
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222B254
	bl GF_AssertFail
_0222B254:
	ldr r0, [r4]
	bl Save_PlayerData_GetProfile
	ldr r1, _0222B26C ; =0x00000528
	ldr r1, [r4, r1]
	bl sub_02078DD8
	ldr r1, _0222B268 ; =0x000004B8
	str r0, [r4, r1]
	pop {r4, pc}
	.balign 4, 0
_0222B268: .word 0x000004B8
_0222B26C: .word 0x00000528
	thumb_func_end ov45_0222B244


	thumb_func_start ov45_0222B270
ov45_0222B270: ; 0x0222B270
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222B288 ; =0x000004B8
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222B286
	bl sub_02078E28
	ldr r0, _0222B288 ; =0x000004B8
	mov r1, #0
	str r1, [r4, r0]
_0222B286:
	pop {r4, pc}
	.balign 4, 0
_0222B288: .word 0x000004B8
	thumb_func_end ov45_0222B270


	thumb_func_start ov45_0222B28C
ov45_0222B28C: ; 0x0222B28C
	push {r3, r4}
	mov r4, #0
	cmp r1, #0
	bls _0222B2AA
	ldr r2, _0222B2B0 ; =0x0000FFFF
_0222B296:
	ldrh r3, [r0]
	cmp r3, r2
	bne _0222B2A2
	mov r0, #1
	pop {r3, r4}
	bx lr
_0222B2A2:
	add r4, r4, #1
	add r0, r0, #2
	cmp r4, r1
	blo _0222B296
_0222B2AA:
	mov r0, #0
	pop {r3, r4}
	bx lr
	.balign 4, 0
_0222B2B0: .word 0x0000FFFF
	thumb_func_end ov45_0222B28C


	thumb_func_start ov45_0222B2B4
ov45_0222B2B4: ; 0x0222B2B4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r4, r2, #0
	str r1, [sp]
	cmp r3, #0
	beq _0222B38A
	ldr r2, _0222B460 ; =0x00000508
	mov r1, #0x42
	add r0, r4, r2
	add r2, #0x20
	lsl r1, r1, #2
	ldr r2, [r4, r2]
	add r1, r4, r1
	bl ov45_0222BCE4
	mov r0, #0x42
	lsl r0, r0, #2
	ldr r1, [r4]
	add r0, r4, r0
	bl ov45_0222BADC
	cmp r0, #0
	bne _0222B2EA
	ldr r0, _0222B464 ; =0x0000052C
	mov r1, #1
	str r1, [r4, r0]
_0222B2EA:
	add r0, r5, #0
	bl ov45_0222EC68
	mov r2, #0x16
	lsl r2, r2, #4
	add r1, r0, #0
	ldrb r2, [r4, r2]
	ldr r0, [r4, #4]
	mov r3, #3
	bl ov45_0222D8C8
	mov r0, #0x4a
	lsl r0, r0, #2
	str r5, [r4, r0]
	add r0, r5, #0
	add r1, sp, #0xc
	bl ov45_0222EA4C
	mov r0, #5
	lsl r0, r0, #6
	add r0, r4, r0
	add r1, sp, #0xc
	bl ov45_0222D500
	mov r0, #0x4a
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222AA84
	add r6, r0, #0
	mov r0, #0x4a
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222AAA8
	add r7, r0, #0
	mov r0, #0x4a
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222AA28
	cmp r6, #0
	beq _0222B364
	cmp r0, #1
	bne _0222B364
	mov r2, #5
	ldr r3, _0222B468 ; =0x00000528
	lsl r2, r2, #6
	lsl r0, r6, #0x10
	lsl r1, r7, #0x18
	ldr r2, [r4, r2]
	ldr r3, [r4, r3]
	lsr r0, r0, #0x10
	lsr r1, r1, #0x18
	bl ov45_02230F94
	mov r1, #0x51
	lsl r1, r1, #2
	str r0, [sp, #4]
	str r0, [r4, r1]
	b _0222B376
_0222B364:
	mov r0, #0x51
	mov r1, #0xc
	lsl r0, r0, #2
	strb r1, [r4, r0]
	add r1, r0, #1
	mov r2, #0
	strb r2, [r4, r1]
	add r0, r0, #2
	strb r2, [r4, r0]
_0222B376:
	mov r0, #0x42
	lsl r0, r0, #2
	ldr r1, [r4]
	add r0, r4, r0
	bl ov45_0222BAC4
	add r0, r4, #0
	bl ov45_0222BA3C
	b _0222B3CE
_0222B38A:
	bl ov45_0222EA78
	add r6, r0, #0
	add r0, r5, #0
	bl ov45_0222EC68
	add r7, r0, #0
	ldr r0, [sp]
	bl ov45_0222A9CC
	add r2, r0, #0
	ldr r0, [r4, #4]
	add r1, r7, #0
	mov r3, #0
	bl ov45_0222D8C8
	cmp r6, r5
	bne _0222B3B6
	ldr r0, [r4, #4]
	add r1, r7, #0
	bl ov45_0222D8F0
_0222B3B6:
	ldr r0, _0222B46C ; =0x000004BC
	mov r2, #0
	add r0, r4, r0
	add r1, r5, #0
	mvn r2, r2
	bl ov45_0222CBD0
	cmp r0, #0
	beq _0222B3CE
	add r0, r4, #0
	bl ov45_0222BA3C
_0222B3CE:
	add r0, r5, #0
	bl ov45_0222EC68
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xf8
	ldr r1, [r0]
	mov r0, #1
	lsl r0, r6
	orr r1, r0
	add r0, r4, #0
	add r0, #0xf8
	str r1, [r0]
	add r0, r5, #0
	bl ov45_0222F484
	cmp r0, #1
	bne _0222B43E
	mov r0, #0xf3
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r6, #0
	mov r2, #1
	bl ov45_0222C944
	str r6, [sp, #8]
	mov r2, #0xf3
	lsl r2, r2, #2
	ldr r0, [r4, #4]
	add r1, sp, #8
	add r2, r4, r2
	bl ov45_0222DC08
	add r0, r5, #0
	bl ov45_0222F4AC
	add r3, r0, #0
	beq _0222B42C
	mov r0, #0xf9
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r6, #0
	mov r2, #1
	bl ov45_0222C9A0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
_0222B42C:
	mov r0, #0xf9
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r6, #0
	mov r2, #0
	bl ov45_0222C9A0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
_0222B43E:
	mov r0, #0xf3
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r6, #0
	mov r2, #0
	bl ov45_0222C944
	mov r0, #0xf9
	lsl r0, r0, #2
	mov r2, #0
	add r0, r4, r0
	add r1, r6, #0
	add r3, r2, #0
	bl ov45_0222C9A0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222B460: .word 0x00000508
_0222B464: .word 0x0000052C
_0222B468: .word 0x00000528
_0222B46C: .word 0x000004BC
	thumb_func_end ov45_0222B2B4


	thumb_func_start ov45_0222B470
ov45_0222B470: ; 0x0222B470
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r5, r1, #0
	bl ov45_0222E9E0
	cmp r6, r0
	beq _0222B528
	add r0, r6, #0
	bl ov45_0222EC68
	add r4, r0, #0
	add r0, r5, #0
	bl ov45_0222AFF8
	cmp r0, #1
	bne _0222B4A4
	add r0, r5, #0
	bl ov45_0222B020
	cmp r4, r0
	bne _0222B4A4
	mov r0, #7
	lsl r0, r0, #6
	add r0, r5, r0
	bl ov45_0222BD5C
_0222B4A4:
	ldr r0, [r5, #4]
	add r1, r4, #0
	bl ov45_0222D8D4
	cmp r0, #0
	beq _0222B4C2
	add r0, r6, #0
	bl ov45_0222EAD4
	bl ov45_0222EC68
	add r1, r0, #0
	ldr r0, [r5, #4]
	bl ov45_0222D8F0
_0222B4C2:
	mov r0, #0xf3
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, r4, #0
	mov r2, #0
	bl ov45_0222C944
	mov r0, #7
	lsl r0, r0, #6
	add r0, r5, r0
	add r1, r4, #0
	bl ov45_0222BDE8
	mov r0, #7
	lsl r0, r0, #6
	add r0, r5, r0
	add r1, r4, #0
	bl ov45_0222BDB0
	ldr r0, _0222B52C ; =0x000004BC
	mov r2, #0
	add r0, r5, r0
	add r1, r6, #0
	mvn r2, r2
	bl ov45_0222CBD0
	cmp r0, #0
	beq _0222B500
	add r0, r5, #0
	bl ov45_0222BA3C
_0222B500:
	mov r0, #0xf9
	lsl r0, r0, #2
	mov r2, #0
	add r0, r5, r0
	add r1, r4, #0
	add r3, r2, #0
	bl ov45_0222C9A0
	add r0, r6, #0
	bl ov45_0222EC68
	add r1, r5, #0
	add r1, #0xfc
	ldr r2, [r1]
	mov r1, #1
	lsl r1, r0
	add r0, r2, #0
	orr r0, r1
	add r5, #0xfc
	str r0, [r5]
_0222B528:
	pop {r4, r5, r6, pc}
	nop
_0222B52C: .word 0x000004BC
	thumb_func_end ov45_0222B470


	thumb_func_start ov45_0222B530
ov45_0222B530: ; 0x0222B530
	push {r4, r5, r6, lr}
	add r5, r1, #0
	add r4, r2, #0
	bl ov45_0222EC68
	mov r1, #0x41
	add r6, r0, #0
	lsl r1, r1, #2
	mov r2, #1
	ldr r0, [r4, r1]
	lsl r2, r6
	orr r0, r2
	str r0, [r4, r1]
	add r0, r5, #0
	bl ov45_0222A920
	cmp r0, #8
	bhi _0222B57E
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222B560: ; jump table
	.short _0222B57E - _0222B560 - 2 ; case 0
	.short _0222B57E - _0222B560 - 2 ; case 1
	.short _0222B572 - _0222B560 - 2 ; case 2
	.short _0222B572 - _0222B560 - 2 ; case 3
	.short _0222B572 - _0222B560 - 2 ; case 4
	.short _0222B572 - _0222B560 - 2 ; case 5
	.short _0222B572 - _0222B560 - 2 ; case 6
	.short _0222B572 - _0222B560 - 2 ; case 7
	.short _0222B572 - _0222B560 - 2 ; case 8
_0222B572:
	mov r0, #7
	lsl r0, r0, #6
	add r0, r4, r0
	add r1, r6, #0
	bl ov45_0222BDE8
_0222B57E:
	add r0, r5, #0
	bl ov45_0222AADC
	cmp r0, #1
	bne _0222B59C
	add r0, r5, #0
	bl ov45_0222AAC8
	add r1, r0, #0
	mov r0, #0xeb
	lsl r0, r0, #2
	add r0, r4, r0
	add r2, r6, #0
	bl ov45_0222C8C8
_0222B59C:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov45_0222B530


	thumb_func_start ov45_0222B5A0
ov45_0222B5A0: ; 0x0222B5A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r4, r1, #0
	add r0, sp, #0
	mov r6, #0
	bl ov45_022320C4
	add r0, r4, #0
	add r0, #0xd4
	add r1, sp, #0
	bl ov45_0222D500
	add r0, sp, #0
	ldmia r0!, {r2, r3}
	add r0, r4, #0
	add r0, #0xd8
	stmia r0!, {r2, r3}
	cmp r5, #0x13
	bls _0222B5CA
	b _0222B73A
_0222B5CA:
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222B5D6: ; jump table
	.short _0222B5FE - _0222B5D6 - 2 ; case 0
	.short _0222B64A - _0222B5D6 - 2 ; case 1
	.short _0222B634 - _0222B5D6 - 2 ; case 2
	.short _0222B634 - _0222B5D6 - 2 ; case 3
	.short _0222B634 - _0222B5D6 - 2 ; case 4
	.short _0222B634 - _0222B5D6 - 2 ; case 5
	.short _0222B634 - _0222B5D6 - 2 ; case 6
	.short _0222B672 - _0222B5D6 - 2 ; case 7
	.short _0222B65C - _0222B5D6 - 2 ; case 8
	.short _0222B65C - _0222B5D6 - 2 ; case 9
	.short _0222B65C - _0222B5D6 - 2 ; case 10
	.short _0222B69A - _0222B5D6 - 2 ; case 11
	.short _0222B684 - _0222B5D6 - 2 ; case 12
	.short _0222B684 - _0222B5D6 - 2 ; case 13
	.short _0222B684 - _0222B5D6 - 2 ; case 14
	.short _0222B71E - _0222B5D6 - 2 ; case 15
	.short _0222B6AC - _0222B5D6 - 2 ; case 16
	.short _0222B6D6 - _0222B5D6 - 2 ; case 17
	.short _0222B6F4 - _0222B5D6 - 2 ; case 18
	.short _0222B704 - _0222B5D6 - 2 ; case 19
_0222B5FE:
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0xd4
	bl ov45_0222D8BC
	add r0, r4, #0
	add r0, #0xd8
	ldmia r0!, {r2, r3}
	add r0, r4, #0
	mov r1, #0x7f
	add r0, #0xe0
	stmia r0!, {r2, r3}
	lsl r1, r1, #2
	ldrb r3, [r4, r1]
	mov r0, #1
	mov r2, #1
	bic r3, r0
	add r0, r3, #0
	orr r0, r2
	strb r0, [r4, r1]
	add r0, r2, #0
	add r0, #0xff
	ldr r0, [r4, r0]
	orr r0, r2
	add r2, #0xff
	str r0, [r4, r2]
	b _0222B73A
_0222B634:
	ldr r0, [r4, #8]
	cmp r0, #0
	bne _0222B64A
	mov r1, #0x4b
	lsl r1, r1, #2
	mov r6, #1
	add r0, r1, #0
	str r6, [r4, #8]
	add r0, #0xd6
	mov r7, #0
	strh r1, [r4, r0]
_0222B64A:
	ldr r0, _0222B74C ; =0x000001FD
	strb r5, [r4, r0]
	sub r0, #0xfd
	ldr r1, [r4, r0]
	mov r0, #2
	orr r1, r0
	add r0, #0xfe
	str r1, [r4, r0]
	b _0222B73A
_0222B65C:
	ldr r0, [r4, #8]
	cmp r0, #0
	bne _0222B672
	mov r1, #0x4b
	lsl r1, r1, #2
	mov r6, #1
	add r0, r1, #0
	str r6, [r4, #8]
	add r0, #0xd6
	mov r7, #0
	strh r1, [r4, r0]
_0222B672:
	ldr r0, _0222B750 ; =0x000001FE
	strb r5, [r4, r0]
	sub r0, #0xfe
	ldr r1, [r4, r0]
	mov r0, #4
	orr r1, r0
	add r0, #0xfc
	str r1, [r4, r0]
	b _0222B73A
_0222B684:
	ldr r0, [r4, #8]
	cmp r0, #0
	bne _0222B69A
	mov r1, #0x4b
	lsl r1, r1, #2
	mov r6, #1
	add r0, r1, #0
	str r6, [r4, #8]
	add r0, #0xd6
	mov r7, #0
	strh r1, [r4, r0]
_0222B69A:
	ldr r0, _0222B754 ; =0x000001FF
	strb r5, [r4, r0]
	sub r0, #0xff
	ldr r1, [r4, r0]
	mov r0, #8
	orr r1, r0
	add r0, #0xf8
	str r1, [r4, r0]
	b _0222B73A
_0222B6AC:
	mov r6, #1
	mov r0, #6
	add r7, r6, #0
	bl ov45_0222ECDC
	add r5, r0, #0
	mov r0, #7
	bl ov45_0222ECDC
	add r2, r0, #0
	ldr r0, _0222B758 ; =0x0000049C
	add r1, r5, #0
	add r0, r4, r0
	bl ov45_0222CA7C
	mov r1, #0x4b
	lsl r1, r1, #2
	add r0, r1, #0
	add r0, #0xd8
	strh r1, [r4, r0]
	b _0222B73A
_0222B6D6:
	mov r1, #0x7f
	lsl r1, r1, #2
	ldrb r2, [r4, r1]
	mov r0, #0xc
	bic r2, r0
	mov r0, #8
	orr r2, r0
	add r0, #0xf8
	strb r2, [r4, r1]
	ldr r1, [r4, r0]
	mov r0, #0x20
	orr r1, r0
	add r0, #0xe0
	str r1, [r4, r0]
	b _0222B73A
_0222B6F4:
	mov r1, #0x4b
	lsl r1, r1, #2
	add r0, r1, #0
	add r0, #0xda
	mov r6, #1
	mov r7, #2
	strh r1, [r4, r0]
	b _0222B73A
_0222B704:
	mov r1, #0x7f
	lsl r1, r1, #2
	ldrb r2, [r4, r1]
	mov r0, #0x80
	mov r6, #1
	orr r2, r0
	strb r2, [r4, r1]
	mov r1, #0xe1
	lsl r1, r1, #2
	lsl r0, r0, #2
	mov r7, #4
	strh r1, [r4, r0]
	b _0222B73A
_0222B71E:
	mov r1, #0x7f
	lsl r1, r1, #2
	ldrb r2, [r4, r1]
	mov r0, #0x60
	bic r2, r0
	mov r0, #0x20
	orr r2, r0
	add r0, #0xe0
	strb r2, [r4, r1]
	ldr r1, [r4, r0]
	mov r0, #0x10
	orr r1, r0
	add r0, #0xf0
	str r1, [r4, r0]
_0222B73A:
	cmp r6, #0
	beq _0222B746
	add r0, r4, #0
	add r1, r7, #0
	bl ov45_0222C370
_0222B746:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222B74C: .word 0x000001FD
_0222B750: .word 0x000001FE
_0222B754: .word 0x000001FF
_0222B758: .word 0x0000049C
	thumb_func_end ov45_0222B5A0


	thumb_func_start ov45_0222B75C
ov45_0222B75C: ; 0x0222B75C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #0x42
	add r4, r2, #0
	add r6, r1, #0
	lsl r0, r0, #2
	ldr r1, [r4]
	add r0, r4, r0
	bl ov45_0222BADC
	cmp r0, #0
	bne _0222B77C
	ldr r0, _0222B798 ; =0x0000052C
	mov r1, #1
	str r1, [r4, r0]
	pop {r4, r5, r6, pc}
_0222B77C:
	mov r0, #0x42
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r5, #0
	add r2, r6, #0
	bl ov45_0222BB00
	mov r0, #0x42
	lsl r0, r0, #2
	ldr r1, [r4]
	add r0, r4, r0
	bl ov45_0222BAC4
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222B798: .word 0x0000052C
	thumb_func_end ov45_0222B75C


	thumb_func_start ov45_0222B79C
ov45_0222B79C: ; 0x0222B79C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r1, #0
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #0
	mov r2, #0xc8
	bl memset
	add r0, sp, #4
	bl ov45_0222EC10
	add r4, #0x20
	add r0, r4, #0
	bl ov45_0222AA84
	add r6, r0, #0
	add r0, r4, #0
	bl ov45_0222AAA8
	add r2, r0, #0
	lsl r1, r6, #0x10
	lsl r2, r2, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x10
	lsr r2, r2, #0x18
	mov r3, #0
	bl ov45_0222D638
	mov r6, #0
	add r4, r6, #0
_0222B7DA:
	ldr r0, [sp, #8]
	mov r1, #0
	ldr r0, [r0, r4]
	mvn r1, r1
	cmp r0, r1
	beq _0222B80A
	bl ov45_0222EA2C
	str r0, [sp]
	bl ov45_0222AA84
	add r7, r0, #0
	ldr r0, [sp]
	bl ov45_0222AAA8
	add r2, r0, #0
	lsl r1, r7, #0x10
	lsl r2, r2, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x10
	lsr r2, r2, #0x18
	mov r3, #0
	bl ov45_0222D638
_0222B80A:
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #0x14
	blt _0222B7DA
	mov r4, #0
	mov r7, #1
_0222B816:
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	bl ov45_0222EDC4
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	bl ov45_0222EDF0
	add r2, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	add r3, r7, #0
	bl ov45_0222D638
	add r4, r4, #1
	cmp r4, #0x14
	blt _0222B816
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov45_0222B79C


	thumb_func_start ov45_0222B840
ov45_0222B840: ; 0x0222B840
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r0, #0x7f
	lsl r0, r0, #2
	ldrb r0, [r4, r0]
	lsl r1, r0, #0x1f
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _0222B89E
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1f
	bne _0222B89E
	bl ov45_0222E96C
	cmp r0, #2
	bne _0222B89E
	add r0, r4, #0
	bl ov45_0222AD4C
	add r2, r4, #0
	add r2, #0xe0
	ldr r3, [r2]
	add r2, r4, #0
	add r2, #0xe4
	mov r1, #0
	ldr r2, [r2]
	add r5, r0, r3
	adc r1, r2
	add r0, r4, #0
	add r0, #0xd8
	ldr r3, [r0]
	add r0, r4, #0
	add r0, #0xdc
	ldr r2, [r0]
	sub r0, r5, r3
	sbc r1, r2
	bge _0222B89E
	mov r1, #0x7f
	lsl r1, r1, #2
	ldrb r2, [r4, r1]
	mov r0, #0x80
	orr r2, r0
	strb r2, [r4, r1]
	mov r1, #0xe1
	lsl r1, r1, #2
	lsl r0, r0, #2
	strh r1, [r4, r0]
_0222B89E:
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222B840


	thumb_func_start ov45_0222B8A0
ov45_0222B8A0: ; 0x0222B8A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	str r1, [sp]
	add r0, r1, #0
	add r4, r2, #0
	bl Save_PlayerData_GetProfile
	str r0, [sp, #0x18]
	ldr r0, [sp]
	bl SaveArray_Party_Get
	str r0, [sp, #0x14]
	ldr r0, [sp]
	bl Save_Pokedex_Get
	str r0, [sp, #0xc]
	ldr r0, [sp]
	bl Save_WiFiHistory_Get
	str r0, [sp, #0x10]
	ldr r0, [sp]
	bl Save_SysInfo_RTC_Get
	str r0, [sp, #8]
	ldr r0, [sp, #0x18]
	add r1, r4, #0
	bl PlayerProfile_GetPlayerName_NewString
	add r1, r5, #0
	add r4, r0, #0
	add r1, #0x28
	mov r2, #8
	bl CopyStringToU16Array
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #8
	bl CopyStringToU16Array
	add r0, r4, #0
	bl String_Delete
	mov r0, #0
	mvn r0, r0
	str r0, [r5, #0x20]
	ldr r0, [sp, #0x18]
	bl PlayerProfile_GetTrainerID
	str r0, [r5, #0x24]
	ldr r0, [sp, #0x14]
	bl Party_GetCount
	str r0, [sp, #4]
	mov r4, #0
	add r6, r5, #0
_0222B910:
	ldr r0, [sp, #4]
	cmp r4, r0
	bge _0222B950
	ldr r0, [sp, #0x14]
	add r1, r4, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r7, r0, #0
	bl GetMonData
	add r1, r6, #0
	add r1, #0x40
	strh r0, [r1]
	add r0, r7, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	add r1, r5, r4
	add r1, #0x4c
	strb r0, [r1]
	add r0, r7, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	add r1, r5, r4
	add r1, #0x52
	strb r0, [r1]
	b _0222B958
_0222B950:
	add r1, r6, #0
	ldr r0, _0222BA38 ; =0x000001EF
	add r1, #0x40
	strh r0, [r1]
_0222B958:
	add r4, r4, #1
	add r6, r6, #2
	cmp r4, #6
	blt _0222B910
	ldr r0, [sp, #0x18]
	bl PlayerProfile_GetTrainerGender
	add r1, r5, #0
	add r1, #0x58
	strb r0, [r1]
	ldr r0, [sp, #0x18]
	bl PlayerProfile_GetLanguage
	add r1, r5, #0
	add r1, #0x59
	strb r0, [r1]
	ldr r0, [sp, #0x18]
	bl PlayerProfile_GetAvatar
	add r1, r5, #0
	add r1, #0x5a
	strh r0, [r1]
	add r0, r5, #0
	add r0, #0x5a
	ldrh r0, [r0]
	bl ov45_0222CCE4
	add r1, r5, #0
	add r1, #0x5a
	strh r0, [r1]
	ldr r0, [sp, #0x10]
	bl WifiHistory_GetPlayerCountry
	add r1, r5, #0
	add r1, #0x5c
	strh r0, [r1]
	ldr r0, [sp, #0x10]
	bl WiFiHistory_GetPlayerRegion
	add r1, r5, #0
	add r1, #0x5e
	strb r0, [r1]
	ldr r0, [sp, #0xc]
	bl Pokedex_GetNatDexFlag
	add r1, r5, #0
	add r1, #0x5f
	strb r0, [r1]
	ldr r0, [sp, #0x18]
	bl PlayerProfile_GetGameClearFlag
	add r1, r5, #0
	add r1, #0x60
	strb r0, [r1]
	add r0, r5, #0
	mov r1, #0xff
	add r0, #0x61
	strb r1, [r0]
	add r1, r5, #0
	mov r0, #0
	add r1, #0x63
	strb r0, [r1]
	add r1, r5, #0
	mov r2, #GAME_VERSION
	add r1, #0x62
	strb r2, [r1]
	ldr r1, [sp, #8]
	add r4, r5, #0
	add r1, #0x24
	str r1, [sp, #8]
	ldmia r1!, {r2, r3}
	str r1, [sp, #8]
	add r1, r5, #0
	add r1, #0x64
	stmia r1!, {r2, r3}
	mov r3, #0x18
	add r2, r3, #0
	sub r2, #0x19
_0222B9F4:
	add r1, r5, r0
	add r1, #0x6c
	strb r3, [r1]
	str r2, [r4, #0x78]
	add r0, r0, #1
	add r4, r4, #4
	cmp r0, #0xc
	blt _0222B9F4
	mov r2, #0
	add r3, r5, #0
	add r1, r2, #0
_0222BA0A:
	add r0, r3, #0
	add r0, #0xa8
	add r2, r2, #1
	add r3, r3, #2
	strh r1, [r0]
	cmp r2, #2
	blt _0222BA0A
	mov r1, #0
	add r0, r5, #0
	mvn r1, r1
	add r0, #0xac
	str r1, [r0]
	add r0, r5, #0
	mov r1, #3
	add r0, #0xb0
	str r1, [r0]
	ldr r1, [sp]
	add r0, r5, #0
	bl ov45_0222BAC4
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_0222BA38: .word 0x000001EF
	thumb_func_end ov45_0222B8A0


	thumb_func_start ov45_0222BA3C
ov45_0222BA3C: ; 0x0222BA3C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x42
	lsl r0, r0, #2
	ldr r1, [r5]
	add r0, r5, r0
	bl ov45_0222BADC
	cmp r0, #0
	bne _0222BA58
	ldr r0, _0222BABC ; =0x0000052C
	mov r1, #1
	str r1, [r5, r0]
	pop {r3, r4, r5, r6, r7, pc}
_0222BA58:
	ldr r7, _0222BAC0 ; =0x000004BC
	mov r4, #0
	add r6, r5, #0
_0222BA5E:
	add r0, r5, r7
	add r1, r4, #0
	bl ov45_0222CC50
	mov r1, #0x5d
	add r2, r5, r4
	lsl r1, r1, #2
	strb r0, [r2, r1]
	add r0, r5, r7
	add r1, r4, #0
	bl ov45_0222CC7C
	mov r1, #6
	lsl r1, r1, #6
	str r0, [r6, r1]
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #0xc
	blt _0222BA5E
	sub r1, #0x68
	add r0, r5, r1
	add r1, #0x18
	add r1, r5, r1
	mov r2, #0x10
	bl MI_CpuCopy8
	mov r0, #0x4a
	lsl r0, r0, #2
	add r0, r5, r0
	bl ov45_0222E9F8
	mov r1, #0x42
	lsl r1, r1, #2
	add r0, r5, r1
	add r1, #0x28
	add r1, r5, r1
	mov r2, #0x10
	bl MI_CpuCopy8
	mov r0, #0x42
	lsl r0, r0, #2
	ldr r1, [r5]
	add r0, r5, r0
	bl ov45_0222BAC4
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222BABC: .word 0x0000052C
_0222BAC0: .word 0x000004BC
	thumb_func_end ov45_0222BA3C


	thumb_func_start ov45_0222BAC4
ov45_0222BAC4: ; 0x0222BAC4
	push {r4, lr}
	add r4, r0, #0
	add r0, r1, #0
	add r1, r4, #0
	add r1, #0x20
	mov r2, #0x94
	bl SaveArray_CalcCRC16
	add r4, #0xb4
	str r0, [r4]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_0222BAC4


	thumb_func_start ov45_0222BADC
ov45_0222BADC: ; 0x0222BADC
	push {r4, lr}
	add r4, r0, #0
	add r0, r1, #0
	add r1, r4, #0
	add r1, #0x20
	mov r2, #0x94
	bl SaveArray_CalcCRC16
	add r4, #0xb4
	ldr r1, [r4]
	cmp r0, r1
	beq _0222BAFC
	bl GF_AssertFail
	mov r0, #0
	pop {r4, pc}
_0222BAFC:
	mov r0, #1
	pop {r4, pc}
	thumb_func_end ov45_0222BADC


	thumb_func_start ov45_0222BB00
ov45_0222BB00: ; 0x0222BB00
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r3, r5, #0
	add r7, r2, #0
	add r6, r4, #0
	add r3, #0x20
	mov r2, #0x12
_0222BB10:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0222BB10
	ldr r0, [r6]
	cmp r7, #0x94
	str r0, [r3]
	bhi _0222BB2E
	add r1, r5, #0
	add r0, r4, #0
	add r1, #0x20
	add r2, r7, #0
	bl MI_CpuCopy8
	b _0222BB3A
_0222BB2E:
	add r1, r5, #0
	add r0, r4, #0
	add r1, #0x20
	mov r2, #0x94
	bl MI_CpuCopy8
_0222BB3A:
	add r4, #8
	add r1, r5, #0
	add r0, r4, #0
	add r1, #0x10
	mov r2, #0x10
	bl MI_CpuCopy8
	add r0, r5, #0
	add r5, #0x28
	add r1, r5, #0
	mov r2, #0x10
	bl MI_CpuCopy8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222BB00

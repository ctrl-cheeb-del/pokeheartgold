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

	thumb_func_start ov45_0222E804
ov45_0222E804: ; 0x0222E804
	ldr r3, _0222E80C ; =ov45_0222E810
	mov r1, #0
	bx r3
	nop
_0222E80C: .word ov45_0222E810
	thumb_func_end ov45_0222E804


	thumb_func_start ov45_0222E810
ov45_0222E810: ; 0x0222E810
	push {r3, r4, r5, lr}
	sub sp, #0x50
	add r5, r0, #0
	ldr r0, _0222E8A0 ; =_022577C0
	add r4, r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222E824
	bl GF_AssertFail
_0222E824:
	ldr r0, _0222E8A4 ; =ov45_0222FC44
	str r0, [sp, #0xc]
	ldr r0, _0222E8A8 ; =ov45_0222FCE0
	str r0, [sp, #0x10]
	ldr r0, _0222E8AC ; =ov45_0222FD50
	str r0, [sp, #0x14]
	ldr r0, _0222E8B0 ; =ov45_0222FDD4
	str r0, [sp, #0x18]
	ldr r0, _0222E8B4 ; =ov45_0222FDD8
	str r0, [sp, #0x1c]
	ldr r0, _0222E8B8 ; =ov45_0222FE84
	str r0, [sp, #0x20]
	ldr r0, _0222E8BC ; =ov45_0222FEC4
	str r0, [sp, #0x24]
	ldr r0, _0222E8C0 ; =ov45_0222FF40
	str r0, [sp, #0x28]
	ldr r0, _0222E8C4 ; =ov45_0222FF7C
	str r0, [sp, #0x2c]
	ldr r0, _0222E8C8 ; =ov45_02230008
	str r0, [sp, #0x30]
	ldr r0, _0222E8CC ; =ov45_02230050
	str r0, [sp, #0x34]
	ldr r0, _0222E8D0 ; =ov45_02230064
	str r0, [sp, #0x38]
	ldr r0, _0222E8D4 ; =ov45_02230090
	str r0, [sp, #0x3c]
	ldr r0, _0222E8D8 ; =ov45_022300B0
	str r0, [sp, #0x40]
	ldr r0, _0222E8DC ; =ov45_022300DC
	str r0, [sp, #0x44]
	ldr r0, _0222E8E0 ; =ov45_02230108
	str r0, [sp, #0x48]
	ldr r0, _0222E8E4 ; =ov45_02230130
	str r0, [sp, #0x4c]
	ldr r0, _0222E8A0 ; =_022577C0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl sub_0202C08C
	str r0, [sp]
	ldr r0, _0222E8A0 ; =_022577C0
	str r5, [sp, #4]
	ldr r0, [r0]
	ldr r1, _0222E8E8 ; =ov45_02254F14
	ldr r0, [r0, #0x28]
	add r2, r4, #0
	str r0, [sp, #8]
	ldr r0, _0222E8EC ; =ov45_02254F04
	add r3, sp, #0xc
	bl ov45_022310C0
	ldr r2, _0222E8A0 ; =_022577C0
	ldr r1, _0222E8F0 ; =0x00000984
	ldr r3, [r2]
	str r0, [r3, r1]
	ldr r0, [r2]
	ldr r0, [r0, r1]
	bl ov45_0222F74C
	add sp, #0x50
	pop {r3, r4, r5, pc}
	nop
_0222E8A0: .word _022577C0
_0222E8A4: .word ov45_0222FC44
_0222E8A8: .word ov45_0222FCE0
_0222E8AC: .word ov45_0222FD50
_0222E8B0: .word ov45_0222FDD4
_0222E8B4: .word ov45_0222FDD8
_0222E8B8: .word ov45_0222FE84
_0222E8BC: .word ov45_0222FEC4
_0222E8C0: .word ov45_0222FF40
_0222E8C4: .word ov45_0222FF7C
_0222E8C8: .word ov45_02230008
_0222E8CC: .word ov45_02230050
_0222E8D0: .word ov45_02230064
_0222E8D4: .word ov45_02230090
_0222E8D8: .word ov45_022300B0
_0222E8DC: .word ov45_022300DC
_0222E8E0: .word ov45_02230108
_0222E8E4: .word ov45_02230130
_0222E8E8: .word ov45_02254F14
_0222E8EC: .word ov45_02254F04
_0222E8F0: .word 0x00000984
	thumb_func_end ov45_0222E810


	thumb_func_start ov45_0222E8F4
ov45_0222E8F4: ; 0x0222E8F4
	push {r3, lr}
	ldr r0, _0222E918 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222E902
	bl GF_AssertFail
_0222E902:
	ldr r0, _0222E918 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x4b
	lsl r0, r0, #2
	ldrb r0, [r1, r0]
	cmp r0, #2
	bne _0222E914
	mov r0, #1
	pop {r3, pc}
_0222E914:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_0222E918: .word _022577C0
	thumb_func_end ov45_0222E8F4


	thumb_func_start ov45_0222E91C
ov45_0222E91C: ; 0x0222E91C
	push {r3, lr}
	ldr r0, _0222E940 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222E92A
	bl GF_AssertFail
_0222E92A:
	bl ov45_0222F78C
	bl ov45_02231490
	bl ov45_0222F74C
	cmp r0, #0
	bne _0222E93E
	bl GF_AssertFail
_0222E93E:
	pop {r3, pc}
	.balign 4, 0
_0222E940: .word _022577C0
	thumb_func_end ov45_0222E91C


	thumb_func_start ov45_0222E944
ov45_0222E944: ; 0x0222E944
	push {r3, lr}
	ldr r0, _0222E968 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222E952
	bl GF_AssertFail
_0222E952:
	ldr r0, _0222E968 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x4b
	lsl r0, r0, #2
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _0222E964
	mov r0, #1
	pop {r3, pc}
_0222E964:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_0222E968: .word _022577C0
	thumb_func_end ov45_0222E944


	thumb_func_start ov45_0222E96C
ov45_0222E96C: ; 0x0222E96C
	push {r3, lr}
	ldr r0, _0222E9B0 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222E97A
	bl GF_AssertFail
_0222E97A:
	ldr r0, _0222E9B0 ; =_022577C0
	ldr r1, _0222E9B4 ; =0x0000012D
	ldr r0, [r0]
	ldrb r2, [r0, r1]
	cmp r2, #4
	beq _0222E992
	add r1, r1, #1
	ldrb r1, [r0, r1]
	cmp r1, #4
	bne _0222E992
	mov r0, #4
	pop {r3, pc}
_0222E992:
	ldr r2, _0222E9B8 ; =0x00000133
	ldrb r1, [r0, r2]
	cmp r1, #0
	beq _0222E99E
	mov r0, #4
	pop {r3, pc}
_0222E99E:
	sub r1, r2, #1
	ldrb r1, [r0, r1]
	cmp r1, #0
	beq _0222E9AA
	mov r0, #4
	pop {r3, pc}
_0222E9AA:
	sub r1, r2, #7
	ldrb r0, [r0, r1]
	pop {r3, pc}
	.balign 4, 0
_0222E9B0: .word _022577C0
_0222E9B4: .word 0x0000012D
_0222E9B8: .word 0x00000133
	thumb_func_end ov45_0222E96C


	thumb_func_start ov45_0222E9BC
ov45_0222E9BC: ; 0x0222E9BC
	push {r3, lr}
	ldr r0, _0222E9D8 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222E9CA
	bl GF_AssertFail
_0222E9CA:
	ldr r0, _0222E9D8 ; =_022577C0
	ldr r1, _0222E9DC ; =0x00000131
	ldr r3, [r0]
	mov r2, #0
	ldrb r0, [r3, r1]
	strb r2, [r3, r1]
	pop {r3, pc}
	.balign 4, 0
_0222E9D8: .word _022577C0
_0222E9DC: .word 0x00000131
	thumb_func_end ov45_0222E9BC


	thumb_func_start ov45_0222E9E0
ov45_0222E9E0: ; 0x0222E9E0
	push {r3, lr}
	ldr r0, _0222E9F4 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222E9EE
	bl GF_AssertFail
_0222E9EE:
	bl ov45_02232580
	pop {r3, pc}
	.balign 4, 0
_0222E9F4: .word _022577C0
	thumb_func_end ov45_0222E9E0


	thumb_func_start ov45_0222E9F8
ov45_0222E9F8: ; 0x0222E9F8
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222EA28 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EA08
	bl GF_AssertFail
_0222EA08:
	bl ov45_02232580
	add r1, r0, #0
	ldr r0, _0222EA28 ; =_022577C0
	add r2, r4, #0
	ldr r0, [r0]
	bl ov45_0222F88C
	ldr r1, _0222EA28 ; =_022577C0
	add r0, r4, #0
	ldr r1, [r1]
	mov r2, #0
	ldr r1, [r1, #0x28]
	bl ov45_022325B0
	pop {r4, pc}
	.balign 4, 0
_0222EA28: .word _022577C0
	thumb_func_end ov45_0222E9F8


	thumb_func_start ov45_0222EA2C
ov45_0222EA2C: ; 0x0222EA2C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222EA48 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EA3C
	bl GF_AssertFail
_0222EA3C:
	ldr r0, _0222EA48 ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	bl ov45_0222F8D8
	pop {r4, pc}
	.balign 4, 0
_0222EA48: .word _022577C0
	thumb_func_end ov45_0222EA2C


	thumb_func_start ov45_0222EA4C
ov45_0222EA4C: ; 0x0222EA4C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0222EA74 ; =_022577C0
	add r4, r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EA5E
	bl GF_AssertFail
_0222EA5E:
	ldr r0, _0222EA74 ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	bl ov45_0222F954
	ldr r1, [r0]
	ldr r0, [r0, #4]
	str r1, [r4]
	str r0, [r4, #4]
	pop {r3, r4, r5, pc}
	nop
_0222EA74: .word _022577C0
	thumb_func_end ov45_0222EA4C


	thumb_func_start ov45_0222EA78
ov45_0222EA78: ; 0x0222EA78
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov r0, #0
	mvn r0, r0
	str r0, [sp]
	lsr r6, r0, #4
	add r5, r0, #0
	ldr r0, _0222EAD0 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EA92
	bl GF_AssertFail
_0222EA92:
	mov r4, #0
_0222EA94:
	ldr r0, _0222EAD0 ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	mov r2, #0
	bl ov45_0222FB5C
	mov r1, #0
	add r7, r0, #0
	mvn r1, r1
	cmp r7, r1
	beq _0222EAC4
	add r1, sp, #4
	bl ov45_0222EA4C
	ldr r2, [sp, #4]
	ldr r1, [sp, #8]
	sub r0, r2, r5
	mov ip, r1
	mov r0, ip
	sbc r0, r6
	bge _0222EAC4
	add r5, r2, #0
	add r6, r1, #0
	str r7, [sp]
_0222EAC4:
	add r4, r4, #1
	cmp r4, #0x14
	blt _0222EA94
	ldr r0, [sp]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222EAD0: .word _022577C0
	thumb_func_end ov45_0222EA78


	thumb_func_start ov45_0222EAD4
ov45_0222EAD4: ; 0x0222EAD4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #4]
	lsr r7, r0, #4
	add r6, r0, #0
	ldr r0, _0222EB34 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EAF0
	bl GF_AssertFail
_0222EAF0:
	mov r4, #0
_0222EAF2:
	ldr r0, _0222EB34 ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	mov r2, #0
	bl ov45_0222FB5C
	mov r1, #0
	add r5, r0, #0
	mvn r1, r1
	cmp r5, r1
	beq _0222EB28
	ldr r1, [sp]
	cmp r5, r1
	beq _0222EB28
	add r1, sp, #8
	bl ov45_0222EA4C
	ldr r2, [sp, #8]
	ldr r1, [sp, #0xc]
	sub r0, r2, r6
	mov ip, r1
	mov r0, ip
	sbc r0, r7
	bge _0222EB28
	add r6, r2, #0
	add r7, r1, #0
	str r5, [sp, #4]
_0222EB28:
	add r4, r4, #1
	cmp r4, #0x14
	blt _0222EAF2
	ldr r0, [sp, #4]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222EB34: .word _022577C0
	thumb_func_end ov45_0222EAD4


	thumb_func_start ov45_0222EB38
ov45_0222EB38: ; 0x0222EB38
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222EB6C ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EB48
	bl GF_AssertFail
_0222EB48:
	add r0, r4, #0
	bl ov45_0222F7B0
	bl ov45_02231C8C
	bl ov45_0222F74C
	cmp r0, #1
	bne _0222EB6A
	ldr r2, _0222EB6C ; =_022577C0
	ldr r1, _0222EB70 ; =0x0000012D
	ldr r3, [r2]
	strb r4, [r3, r1]
	ldr r2, [r2]
	mov r3, #0
	add r1, r1, #2
	strb r3, [r2, r1]
_0222EB6A:
	pop {r4, pc}
	.balign 4, 0
_0222EB6C: .word _022577C0
_0222EB70: .word 0x0000012D
	thumb_func_end ov45_0222EB38


	thumb_func_start ov45_0222EB74
ov45_0222EB74: ; 0x0222EB74
	push {r3, lr}
	ldr r0, _0222EB8C ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EB82
	bl GF_AssertFail
_0222EB82:
	ldr r0, _0222EB8C ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222EB90 ; =0x0000012F
	ldrb r0, [r1, r0]
	pop {r3, pc}
	.balign 4, 0
_0222EB8C: .word _022577C0
_0222EB90: .word 0x0000012F
	thumb_func_end ov45_0222EB74


	thumb_func_start ov45_0222EB94
ov45_0222EB94: ; 0x0222EB94
	push {r3, lr}
	ldr r0, _0222EBBC ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EBA2
	bl GF_AssertFail
_0222EBA2:
	bl ov45_02231EC0
	bl ov45_0222F74C
	cmp r0, #1
	bne _0222EBB8
	ldr r1, _0222EBBC ; =_022577C0
	mov r3, #3
	ldr r2, [r1]
	ldr r1, _0222EBC0 ; =0x0000012E
	strb r3, [r2, r1]
_0222EBB8:
	pop {r3, pc}
	nop
_0222EBBC: .word _022577C0
_0222EBC0: .word 0x0000012E
	thumb_func_end ov45_0222EB94


	thumb_func_start ov45_0222EBC4
ov45_0222EBC4: ; 0x0222EBC4
	push {r3, lr}
	ldr r0, _0222EBE8 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EBD2
	bl GF_AssertFail
_0222EBD2:
	ldr r0, _0222EBE8 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222EBEC ; =0x0000012E
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _0222EBE2
	mov r0, #1
	pop {r3, pc}
_0222EBE2:
	mov r0, #0
	pop {r3, pc}
	nop
_0222EBE8: .word _022577C0
_0222EBEC: .word 0x0000012E
	thumb_func_end ov45_0222EBC4


	thumb_func_start ov45_0222EBF0
ov45_0222EBF0: ; 0x0222EBF0
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222EC0C ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EC00
	bl GF_AssertFail
_0222EC00:
	ldr r0, _0222EC0C ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	bl ov45_0222FBD8
	pop {r4, pc}
	.balign 4, 0
_0222EC0C: .word _022577C0
	thumb_func_end ov45_0222EBF0


	thumb_func_start ov45_0222EC10
ov45_0222EC10: ; 0x0222EC10
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222EC38 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EC20
	bl GF_AssertFail
_0222EC20:
	ldr r1, _0222EC38 ; =_022577C0
	mov r0, #0x47
	ldr r2, [r1]
	lsl r0, r0, #2
	ldrsh r2, [r2, r0]
	add r0, r0, #4
	str r2, [r4]
	ldr r1, [r1]
	ldr r0, [r1, r0]
	str r0, [r4, #4]
	pop {r4, pc}
	nop
_0222EC38: .word _022577C0
	thumb_func_end ov45_0222EC10


	thumb_func_start ov45_0222EC3C
ov45_0222EC3C: ; 0x0222EC3C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222EC64 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EC4C
	bl GF_AssertFail
_0222EC4C:
	ldr r1, _0222EC64 ; =_022577C0
	mov r0, #0x49
	ldr r2, [r1]
	lsl r0, r0, #2
	ldrsh r2, [r2, r0]
	add r0, r0, #4
	str r2, [r4]
	ldr r1, [r1]
	ldr r0, [r1, r0]
	str r0, [r4, #4]
	pop {r4, pc}
	nop
_0222EC64: .word _022577C0
	thumb_func_end ov45_0222EC3C


	thumb_func_start ov45_0222EC68
ov45_0222EC68: ; 0x0222EC68
	add r1, r0, #0
	ldr r0, _0222EC74 ; =_022577C0
	ldr r3, _0222EC78 ; =ov45_0222FB24
	ldr r0, [r0]
	mov r2, #0
	bx r3
	.balign 4, 0
_0222EC74: .word _022577C0
_0222EC78: .word ov45_0222FB24
	thumb_func_end ov45_0222EC68


	thumb_func_start ov45_0222EC7C
ov45_0222EC7C: ; 0x0222EC7C
	add r1, r0, #0
	ldr r0, _0222EC88 ; =_022577C0
	ldr r3, _0222EC8C ; =ov45_0222FB24
	ldr r0, [r0]
	mov r2, #1
	bx r3
	.balign 4, 0
_0222EC88: .word _022577C0
_0222EC8C: .word ov45_0222FB24
	thumb_func_end ov45_0222EC7C


	thumb_func_start ov45_0222EC90
ov45_0222EC90: ; 0x0222EC90
	add r1, r0, #0
	ldr r0, _0222EC9C ; =_022577C0
	ldr r3, _0222ECA0 ; =ov45_0222FB5C
	ldr r0, [r0]
	mov r2, #0
	bx r3
	.balign 4, 0
_0222EC9C: .word _022577C0
_0222ECA0: .word ov45_0222FB5C
	thumb_func_end ov45_0222EC90


	thumb_func_start ov45_0222ECA4
ov45_0222ECA4: ; 0x0222ECA4
	add r1, r0, #0
	ldr r0, _0222ECB0 ; =_022577C0
	ldr r3, _0222ECB4 ; =ov45_0222FB5C
	ldr r0, [r0]
	mov r2, #1
	bx r3
	.balign 4, 0
_0222ECB0: .word _022577C0
_0222ECB4: .word ov45_0222FB5C
	thumb_func_end ov45_0222ECA4


	thumb_func_start ov45_0222ECB8
ov45_0222ECB8: ; 0x0222ECB8
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222ECD8 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222ECC8
	bl GF_AssertFail
_0222ECC8:
	ldr r0, _0222ECD8 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x67
	lsl r0, r0, #2
	add r0, r1, r0
	ldmia r0!, {r2, r3}
	stmia r4!, {r2, r3}
	pop {r4, pc}
	.balign 4, 0
_0222ECD8: .word _022577C0
	thumb_func_end ov45_0222ECB8


	thumb_func_start ov45_0222ECDC
ov45_0222ECDC: ; 0x0222ECDC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0222ED78 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222ECEC
	bl GF_AssertFail
_0222ECEC:
	ldr r1, _0222ED78 ; =_022577C0
	mov r0, #1
	ldr r2, [r1]
	mov r1, #0x4b
	lsl r1, r1, #2
	ldrb r1, [r2, r1]
	cmp r1, #2
	beq _0222ED02
	cmp r1, #4
	beq _0222ED02
	mov r0, #0
_0222ED02:
	cmp r0, #0
	bne _0222ED0A
	bl GF_AssertFail
_0222ED0A:
	cmp r5, #8
	blt _0222ED12
	bl GF_AssertFail
_0222ED12:
	ldr r0, _0222ED78 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x6d
	lsl r0, r0, #2
	add r0, r1, r0
	cmp r5, #7
	bhi _0222ED74
	add r1, r5, r5
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0222ED2C: ; jump table
	.short _0222ED3C - _0222ED2C - 2 ; case 0
	.short _0222ED40 - _0222ED2C - 2 ; case 1
	.short _0222ED44 - _0222ED2C - 2 ; case 2
	.short _0222ED48 - _0222ED2C - 2 ; case 3
	.short _0222ED4C - _0222ED2C - 2 ; case 4
	.short _0222ED58 - _0222ED2C - 2 ; case 5
	.short _0222ED62 - _0222ED2C - 2 ; case 6
	.short _0222ED6C - _0222ED2C - 2 ; case 7
_0222ED3C:
	ldr r4, [r0]
	b _0222ED74
_0222ED40:
	ldr r4, [r0, #4]
	b _0222ED74
_0222ED44:
	ldrb r4, [r0, #0xc]
	b _0222ED74
_0222ED48:
	ldrb r4, [r0, #0xd]
	b _0222ED74
_0222ED4C:
	ldr r0, [r0, #8]
	mov r4, #1
	tst r0, r4
	bne _0222ED74
	mov r4, #0
	b _0222ED74
_0222ED58:
	mov r1, #0x13
	bl ov45_022303BC
	add r4, r0, #0
	b _0222ED74
_0222ED62:
	mov r1, #0x10
	bl ov45_022303BC
	add r4, r0, #0
	b _0222ED74
_0222ED6C:
	mov r1, #0x11
	bl ov45_022303BC
	add r4, r0, #0
_0222ED74:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222ED78: .word _022577C0
	thumb_func_end ov45_0222ECDC


	thumb_func_start ov45_0222ED7C
ov45_0222ED7C: ; 0x0222ED7C
	push {r3, lr}
	ldr r0, _0222EDA4 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222ED8A
	bl GF_AssertFail
_0222ED8A:
	ldr r0, _0222EDA4 ; =_022577C0
	ldr r0, [r0]
	bl ov45_0222F7B4
	cmp r0, #0
	beq _0222EDA2
	ldr r1, _0222EDA4 ; =_022577C0
	mov r3, #1
	ldr r2, [r1]
	mov r1, #0x13
	lsl r1, r1, #4
	strb r3, [r2, r1]
_0222EDA2:
	pop {r3, pc}
	.balign 4, 0
_0222EDA4: .word _022577C0
	thumb_func_end ov45_0222ED7C


	thumb_func_start ov45_0222EDA8
ov45_0222EDA8: ; 0x0222EDA8
	ldr r0, _0222EDC0 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x13
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _0222EDBA
	mov r0, #1
	bx lr
_0222EDBA:
	mov r0, #0
	bx lr
	nop
_0222EDC0: .word _022577C0
	thumb_func_end ov45_0222EDA8


	thumb_func_start ov45_0222EDC4
ov45_0222EDC4: ; 0x0222EDC4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222EDEC ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EDD4
	bl GF_AssertFail
_0222EDD4:
	cmp r4, #0x14
	blo _0222EDDC
	bl GF_AssertFail
_0222EDDC:
	ldr r0, _0222EDEC ; =_022577C0
	ldr r1, [r0]
	lsl r0, r4, #2
	add r1, r1, r0
	mov r0, #0x4d
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	pop {r4, pc}
	.balign 4, 0
_0222EDEC: .word _022577C0
	thumb_func_end ov45_0222EDC4


	thumb_func_start ov45_0222EDF0
ov45_0222EDF0: ; 0x0222EDF0
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222EE18 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EE00
	bl GF_AssertFail
_0222EE00:
	cmp r4, #0x14
	blo _0222EE08
	bl GF_AssertFail
_0222EE08:
	ldr r0, _0222EE18 ; =_022577C0
	ldr r1, [r0]
	lsl r0, r4, #2
	add r1, r1, r0
	ldr r0, _0222EE1C ; =0x00000136
	ldrb r0, [r1, r0]
	pop {r4, pc}
	nop
_0222EE18: .word _022577C0
_0222EE1C: .word 0x00000136
	thumb_func_end ov45_0222EDF0


	thumb_func_start ov45_0222EE20
ov45_0222EE20: ; 0x0222EE20
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _0222EE4C ; =_022577C0
	add r4, r1, #0
	ldr r0, [r0]
	add r6, r2, #0
	cmp r0, #0
	bne _0222EE34
	bl GF_AssertFail
_0222EE34:
	ldr r2, _0222EE4C ; =_022577C0
	mov r1, #0x61
	ldr r0, [r2]
	lsl r1, r1, #2
	str r5, [r0, r1]
	ldr r3, [r2]
	add r0, r1, #4
	str r4, [r3, r0]
	ldr r0, [r2]
	add r1, #8
	str r6, [r0, r1]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222EE4C: .word _022577C0
	thumb_func_end ov45_0222EE20


	thumb_func_start ov45_0222EE50
ov45_0222EE50: ; 0x0222EE50
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _0222EE7C ; =_022577C0
	add r4, r1, #0
	ldr r0, [r0]
	add r6, r2, #0
	cmp r0, #0
	bne _0222EE64
	bl GF_AssertFail
_0222EE64:
	ldr r2, _0222EE7C ; =_022577C0
	mov r1, #0x19
	ldr r0, [r2]
	lsl r1, r1, #4
	str r5, [r0, r1]
	ldr r3, [r2]
	add r0, r1, #4
	str r4, [r3, r0]
	ldr r0, [r2]
	add r1, #8
	str r6, [r0, r1]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222EE7C: .word _022577C0
	thumb_func_end ov45_0222EE50


	thumb_func_start ov45_0222EE80
ov45_0222EE80: ; 0x0222EE80
	push {r3, lr}
	ldr r0, _0222EEB4 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EE8E
	bl GF_AssertFail
_0222EE8E:
	ldr r0, _0222EEB4 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x61
	lsl r0, r0, #2
	add r1, r1, r0
	mov r0, #0
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	strb r0, [r1, #3]
	strb r0, [r1, #4]
	strb r0, [r1, #5]
	strb r0, [r1, #6]
	strb r0, [r1, #7]
	strb r0, [r1, #8]
	strb r0, [r1, #9]
	strb r0, [r1, #0xa]
	strb r0, [r1, #0xb]
	pop {r3, pc}
	.balign 4, 0
_0222EEB4: .word _022577C0
	thumb_func_end ov45_0222EE80


	thumb_func_start ov45_0222EEB8
ov45_0222EEB8: ; 0x0222EEB8
	push {r3, lr}
	ldr r0, _0222EEEC ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222EEC6
	bl GF_AssertFail
_0222EEC6:
	ldr r0, _0222EEEC ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x19
	lsl r0, r0, #4
	add r1, r1, r0
	mov r0, #0
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	strb r0, [r1, #3]
	strb r0, [r1, #4]
	strb r0, [r1, #5]
	strb r0, [r1, #6]
	strb r0, [r1, #7]
	strb r0, [r1, #8]
	strb r0, [r1, #9]
	strb r0, [r1, #0xa]
	strb r0, [r1, #0xb]
	pop {r3, pc}
	.balign 4, 0
_0222EEEC: .word _022577C0
	thumb_func_end ov45_0222EEB8


	thumb_func_start ov45_0222EEF0
ov45_0222EEF0: ; 0x0222EEF0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _0222EF48 ; =_022577C0
	add r6, r1, #0
	ldr r0, [r0]
	add r4, r2, #0
	cmp r0, #0
	bne _0222EF04
	bl GF_AssertFail
_0222EF04:
	ldr r0, _0222EF48 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	cmp r0, r5
	bhi _0222EF16
	bl GF_AssertFail
_0222EF16:
	ldr r0, _0222EF48 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r1, [r1, r0]
	lsl r0, r5, #3
	add r0, r1, r0
	ldr r0, [r0, #4]
	cmp r4, r0
	beq _0222EF2E
	bl GF_AssertFail
_0222EF2E:
	mov r0, #0
	add r1, r5, #0
	add r2, r6, #0
	add r3, r4, #0
	bl ov45_0223247C
	bl ov45_0222F74C
	cmp r0, #1
	beq _0222EF46
	bl GF_AssertFail
_0222EF46:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222EF48: .word _022577C0
	thumb_func_end ov45_0222EEF0


	thumb_func_start ov45_0222EF4C
ov45_0222EF4C: ; 0x0222EF4C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _0222EFA8 ; =_022577C0
	add r6, r1, #0
	ldr r0, [r0]
	add r7, r2, #0
	add r4, r3, #0
	cmp r0, #0
	bne _0222EF62
	bl GF_AssertFail
_0222EF62:
	ldr r0, _0222EFA8 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	cmp r0, r5
	bhi _0222EF74
	bl GF_AssertFail
_0222EF74:
	ldr r0, _0222EFA8 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r1, [r1, r0]
	lsl r0, r5, #3
	add r0, r1, r0
	ldr r0, [r0, #4]
	cmp r4, r0
	beq _0222EF8C
	bl GF_AssertFail
_0222EF8C:
	add r0, r6, #0
	add r1, r5, #0
	add r2, r7, #0
	add r3, r4, #0
	bl ov45_02232500
	bl ov45_0222F74C
	cmp r0, #1
	beq _0222EFA4
	bl GF_AssertFail
_0222EFA4:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222EFA8: .word _022577C0
	thumb_func_end ov45_0222EF4C


	thumb_func_start ov45_0222EFAC
ov45_0222EFAC: ; 0x0222EFAC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _0222F020 ; =_022577C0
	add r6, r1, #0
	ldr r0, [r0]
	add r4, r2, #0
	cmp r0, #0
	bne _0222EFC0
	bl GF_AssertFail
_0222EFC0:
	ldr r0, _0222F020 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x65
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	cmp r0, r5
	bhi _0222EFD2
	bl GF_AssertFail
_0222EFD2:
	ldr r0, _0222F020 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r1, [r1, r0]
	lsl r0, r5, #3
	add r0, r1, r0
	ldr r0, [r0, #4]
	cmp r4, r0
	beq _0222EFEA
	bl GF_AssertFail
_0222EFEA:
	ldr r0, _0222F020 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F024 ; =0x0000012D
	ldrb r0, [r1, r0]
	cmp r0, #4
	bne _0222EFFA
	bl GF_AssertFail
_0222EFFA:
	ldr r0, _0222F020 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F024 ; =0x0000012D
	ldrb r0, [r1, r0]
	bl ov45_0222F7B0
	add r1, r5, #0
	add r2, r6, #0
	add r3, r4, #0
	bl ov45_0223247C
	bl ov45_0222F74C
	cmp r0, #1
	beq _0222F01C
	bl GF_AssertFail
_0222F01C:
	pop {r4, r5, r6, pc}
	nop
_0222F020: .word _022577C0
_0222F024: .word 0x0000012D
	thumb_func_end ov45_0222EFAC


	thumb_func_start ov45_0222F028
ov45_0222F028: ; 0x0222F028
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	ldr r0, _0222F138 ; =_022577C0
	add r6, r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F03A
	bl GF_AssertFail
_0222F03A:
	ldr r0, _0222F138 ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	bl ov45_0223021C
	cmp r0, #1
	bne _0222F04C
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222F04C:
	ldr r2, _0222F138 ; =_022577C0
	ldr r1, _0222F13C ; =0x0000069C
	ldr r0, [r2]
	ldrh r3, [r0, r1]
	cmp r3, #3
	beq _0222F05C
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222F05C:
	mov r3, #0x4c
	add r5, r4, #0
	mul r5, r3
	add r3, r0, r5
	add r0, r1, #0
	sub r0, #0xe4
	str r4, [r3, r0]
	ldr r0, [r2]
	mov r7, #1
	add r3, r0, r5
	add r0, r1, #0
	sub r0, #0xe0
	str r6, [r3, r0]
	ldr r0, [r2]
	add r3, r0, r5
	add r0, r1, #0
	sub r0, #0xdc
	str r7, [r3, r0]
	ldr r0, [r2]
	mov r7, #0
	add r3, r0, r5
	add r0, r1, #0
	sub r0, #0xd8
	str r7, [r3, r0]
	ldr r2, [r2]
	sub r1, #0xe4
	add r0, r2, r1
	mov r1, #0x67
	lsl r1, r1, #2
	add r0, r0, r5
	add r1, r2, r1
	bl ov45_02230378
	ldr r0, _0222F138 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F140 ; =0x000005B8
	add r0, r1, r0
	add r0, r0, r5
	bl ov45_0223285C
	bl ov45_0222F74C
	cmp r0, #0
	bne _0222F0B8
	bl GF_AssertFail
_0222F0B8:
	ldr r1, _0222F138 ; =_022577C0
	mov r0, #0x4c
	add r5, r4, #0
	mul r5, r0
	ldr r1, [r1]
	mov r0, #1
	add r2, r1, r5
	ldr r1, _0222F144 ; =0x000005FC
	strh r0, [r2, r1]
	bl ov45_02232580
	ldr r1, _0222F138 ; =_022577C0
	mov r7, #6
	ldr r2, [r1]
	lsl r7, r7, #8
	add r2, r2, r5
	str r0, [r2, r7]
	ldr r2, [r1]
	ldr r0, _0222F148 ; =0x00000708
	add r3, r2, r5
	sub r2, r7, #2
	strh r0, [r3, r2]
	add r2, r0, #0
	ldr r3, [r1]
	sub r2, #0x6c
	strh r4, [r3, r2]
	add r2, r0, #0
	ldr r3, [r1]
	mov r4, #1
	sub r2, #0x6a
	strb r4, [r3, r2]
	ldr r2, [r1]
	mov r3, #0
	sub r0, #0x69
	strb r3, [r2, r0]
	ldr r4, [r1]
	sub r0, r7, #2
	add r1, r4, r5
	ldrh r0, [r1, r0]
	mov r1, #0x1e
	bl _s32_div_f
	add r3, r0, #0
	add r0, r7, #0
	sub r0, #0x18
	add r0, r4, r0
	add r0, r0, r5
	add r1, r6, #0
	mov r2, #1
	bl ov00_021E5CEC
	ldr r1, _0222F138 ; =_022577C0
	ldr r0, _0222F14C ; =ov45_02230390
	ldr r1, [r1]
	bl ov00_021E5CD0
	ldr r1, _0222F138 ; =_022577C0
	ldr r0, _0222F150 ; =ov45_02230394
	ldr r1, [r1]
	bl ov00_021E5CA0
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222F138: .word _022577C0
_0222F13C: .word 0x0000069C
_0222F140: .word 0x000005B8
_0222F144: .word 0x000005FC
_0222F148: .word 0x00000708
_0222F14C: .word ov45_02230390
_0222F150: .word ov45_02230394
	thumb_func_end ov45_0222F028


	thumb_func_start ov45_0222F154
ov45_0222F154: ; 0x0222F154
	push {r4, lr}
	ldr r0, _0222F1B0 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F162
	bl GF_AssertFail
_0222F162:
	ldr r0, _0222F1B0 ; =_022577C0
	ldr r2, [r0]
	ldr r0, _0222F1B4 ; =0x0000069C
	ldrh r1, [r2, r0]
	cmp r1, #3
	beq _0222F1AC
	add r0, r0, #2
	ldrb r0, [r2, r0]
	cmp r0, #0
	beq _0222F1AC
	bl ov45_02232CA4
	bl ov45_0222F74C
	cmp r0, #0
	bne _0222F186
	bl GF_AssertFail
_0222F186:
	ldr r0, _0222F1B0 ; =_022577C0
	ldr r4, [r0]
	bl ov45_02232580
	ldr r1, _0222F1B4 ; =0x0000069C
	add r2, r0, #0
	ldrh r1, [r4, r1]
	add r0, r4, #0
	bl ov45_022301E0
	cmp r0, #0
	bne _0222F1A2
	bl GF_AssertFail
_0222F1A2:
	ldr r0, _0222F1B0 ; =_022577C0
	mov r2, #0
	ldr r1, [r0]
	ldr r0, _0222F1B8 ; =0x0000069E
	strb r2, [r1, r0]
_0222F1AC:
	pop {r4, pc}
	nop
_0222F1B0: .word _022577C0
_0222F1B4: .word 0x0000069C
_0222F1B8: .word 0x0000069E
	thumb_func_end ov45_0222F154


	thumb_func_start ov45_0222F1BC
ov45_0222F1BC: ; 0x0222F1BC
	push {r4, r5, r6, lr}
	ldr r0, _0222F210 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F1CA
	bl GF_AssertFail
_0222F1CA:
	ldr r4, _0222F210 ; =_022577C0
	ldr r3, _0222F214 ; =0x0000069E
	ldr r1, [r4]
	ldrb r0, [r1, r3]
	cmp r0, #0
	beq _0222F20C
	sub r2, r3, #2
	ldrh r5, [r1, r2]
	mov r2, #0x4c
	mov r0, #1
	add r6, r5, #0
	mul r6, r2
	add r5, r1, r6
	add r1, r3, #0
	sub r1, #0xda
	str r0, [r5, r1]
	add r0, r3, #0
	ldr r1, [r4]
	sub r0, #0xe6
	add r4, r1, r0
	sub r0, r3, #2
	ldrh r0, [r1, r0]
	add r1, r0, #0
	mul r1, r2
	add r0, r4, r1
	bl ov45_02232BB0
	bl ov45_0222F74C
	cmp r0, #0
	bne _0222F20C
	bl GF_AssertFail
_0222F20C:
	pop {r4, r5, r6, pc}
	nop
_0222F210: .word _022577C0
_0222F214: .word 0x0000069E
	thumb_func_end ov45_0222F1BC


	thumb_func_start ov45_0222F218
ov45_0222F218: ; 0x0222F218
	push {r3, lr}
	ldr r0, _0222F24C ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F226
	bl GF_AssertFail
_0222F226:
	ldr r0, _0222F24C ; =_022577C0
	ldr r1, _0222F250 ; =0x0000069C
	ldr r3, [r0]
	ldrh r2, [r3, r1]
	cmp r2, #3
	bne _0222F236
	mov r0, #0
	pop {r3, pc}
_0222F236:
	mov r0, #0x4c
	mul r0, r2
	add r0, r3, r0
	sub r1, #0xd8
	ldr r0, [r0, r1]
	cmp r0, #1
	bne _0222F248
	mov r0, #1
	pop {r3, pc}
_0222F248:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_0222F24C: .word _022577C0
_0222F250: .word 0x0000069C
	thumb_func_end ov45_0222F218


	thumb_func_start ov45_0222F254
ov45_0222F254: ; 0x0222F254
	push {r3, lr}
	ldr r0, _0222F26C ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F262
	bl GF_AssertFail
_0222F262:
	ldr r0, _0222F26C ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F270 ; =0x0000069F
	ldrb r0, [r1, r0]
	pop {r3, pc}
	.balign 4, 0
_0222F26C: .word _022577C0
_0222F270: .word 0x0000069F
	thumb_func_end ov45_0222F254


	thumb_func_start ov45_0222F274
ov45_0222F274: ; 0x0222F274
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F290 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F284
	bl GF_AssertFail
_0222F284:
	ldr r0, _0222F290 ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	bl ov45_0223021C
	pop {r4, pc}
	.balign 4, 0
_0222F290: .word _022577C0
	thumb_func_end ov45_0222F274


	thumb_func_start ov45_0222F294
ov45_0222F294: ; 0x0222F294
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F2CC ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F2A4
	bl GF_AssertFail
_0222F2A4:
	add r0, r4, #0
	bl ov45_0222F274
	cmp r0, #0
	bne _0222F2B2
	mov r0, #0
	pop {r4, pc}
_0222F2B2:
	ldr r0, _0222F2CC ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x4c
	mul r0, r4
	add r1, r1, r0
	ldr r0, _0222F2D0 ; =0x000005C4
	ldr r0, [r1, r0]
	cmp r0, #0
	bne _0222F2C8
	mov r0, #1
	pop {r4, pc}
_0222F2C8:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_0222F2CC: .word _022577C0
_0222F2D0: .word 0x000005C4
	thumb_func_end ov45_0222F294


	thumb_func_start ov45_0222F2D4
ov45_0222F2D4: ; 0x0222F2D4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F310 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F2E4
	bl GF_AssertFail
_0222F2E4:
	cmp r4, #3
	blt _0222F2EC
	bl GF_AssertFail
_0222F2EC:
	ldr r0, _0222F310 ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	bl ov45_0223021C
	cmp r0, #0
	bne _0222F2FE
	mov r0, #0
	pop {r4, pc}
_0222F2FE:
	ldr r0, _0222F310 ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	bl ov45_022302B0
	ldr r1, [r0, #4]
	ldr r0, [r0, #8]
	sub r0, r1, r0
	pop {r4, pc}
	.balign 4, 0
_0222F310: .word _022577C0
	thumb_func_end ov45_0222F2D4


	thumb_func_start ov45_0222F314
ov45_0222F314: ; 0x0222F314
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F34C ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F324
	bl GF_AssertFail
_0222F324:
	cmp r4, #3
	blt _0222F32C
	bl GF_AssertFail
_0222F32C:
	ldr r0, _0222F34C ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	bl ov45_0223021C
	cmp r0, #0
	bne _0222F33E
	mov r0, #0
	pop {r4, pc}
_0222F33E:
	ldr r0, _0222F34C ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	bl ov45_022302B0
	ldr r0, [r0, #8]
	pop {r4, pc}
	.balign 4, 0
_0222F34C: .word _022577C0
	thumb_func_end ov45_0222F314


	thumb_func_start ov45_0222F350
ov45_0222F350: ; 0x0222F350
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _0222F3D4 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F360
	bl GF_AssertFail
_0222F360:
	ldr r0, _0222F3D4 ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	bl ov45_0223021C
	cmp r0, #0
	bne _0222F372
	mov r0, #0
	pop {r4, r5, r6, pc}
_0222F372:
	ldr r3, _0222F3D4 ; =_022577C0
	ldr r2, _0222F3D8 ; =0x0000069C
	ldr r0, [r3]
	ldrh r1, [r0, r2]
	cmp r1, #3
	beq _0222F382
	mov r0, #0
	pop {r4, r5, r6, pc}
_0222F382:
	mov r1, #0x4c
	add r4, r5, #0
	mul r4, r1
	add r1, r2, #0
	add r6, r0, r4
	sub r1, #0xd8
	ldr r1, [r6, r1]
	cmp r1, #1
	bne _0222F398
	mov r0, #0
	pop {r4, r5, r6, pc}
_0222F398:
	strh r5, [r0, r2]
	ldr r5, [r3]
	sub r2, #0x9e
	add r0, r5, r4
	ldrh r0, [r0, r2]
	mov r1, #0x1e
	bl _s32_div_f
	ldr r1, _0222F3DC ; =0x000005E8
	add r3, r0, #0
	add r0, r5, r1
	add r2, r5, r4
	sub r1, #0x2c
	ldr r1, [r2, r1]
	add r0, r0, r4
	mov r2, #0
	bl ov00_021E5CEC
	ldr r1, _0222F3D4 ; =_022577C0
	ldr r0, _0222F3E0 ; =ov45_02230390
	ldr r1, [r1]
	bl ov00_021E5CD0
	ldr r1, _0222F3D4 ; =_022577C0
	ldr r0, _0222F3E4 ; =ov45_02230394
	ldr r1, [r1]
	bl ov00_021E5CA0
	mov r0, #1
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222F3D4: .word _022577C0
_0222F3D8: .word 0x0000069C
_0222F3DC: .word 0x000005E8
_0222F3E0: .word ov45_02230390
_0222F3E4: .word ov45_02230394
	thumb_func_end ov45_0222F350


	thumb_func_start ov45_0222F3E8
ov45_0222F3E8: ; 0x0222F3E8
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F424 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F3F8
	bl GF_AssertFail
_0222F3F8:
	cmp r4, #3
	blt _0222F400
	bl GF_AssertFail
_0222F400:
	ldr r0, _0222F424 ; =_022577C0
	add r1, r4, #0
	ldr r0, [r0]
	bl ov45_0223021C
	cmp r0, #0
	bne _0222F412
	ldr r0, _0222F428 ; =0x00000708
	pop {r4, pc}
_0222F412:
	ldr r0, _0222F424 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x4c
	mul r0, r4
	add r1, r1, r0
	ldr r0, _0222F42C ; =0x000005FE
	ldrh r0, [r1, r0]
	pop {r4, pc}
	nop
_0222F424: .word _022577C0
_0222F428: .word 0x00000708
_0222F42C: .word 0x000005FE
	thumb_func_end ov45_0222F3E8


	thumb_func_start ov45_0222F430
ov45_0222F430: ; 0x0222F430
	push {r3, lr}
	ldr r0, _0222F45C ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F43E
	bl GF_AssertFail
_0222F43E:
	ldr r0, _0222F45C ; =_022577C0
	ldr r1, _0222F460 ; =0x0000069C
	ldr r3, [r0]
	ldrh r2, [r3, r1]
	cmp r2, #3
	bne _0222F450
	mov r0, #0
	mvn r0, r0
	pop {r3, pc}
_0222F450:
	mov r0, #0x4c
	mul r0, r2
	add r0, r3, r0
	sub r1, #0x9c
	ldr r0, [r0, r1]
	pop {r3, pc}
	.balign 4, 0
_0222F45C: .word _022577C0
_0222F460: .word 0x0000069C
	thumb_func_end ov45_0222F430


	thumb_func_start ov45_0222F464
ov45_0222F464: ; 0x0222F464
	push {r3, lr}
	ldr r0, _0222F47C ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F472
	bl GF_AssertFail
_0222F472:
	ldr r0, _0222F47C ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F480 ; =0x0000069E
	ldrb r0, [r1, r0]
	pop {r3, pc}
	.balign 4, 0
_0222F47C: .word _022577C0
_0222F480: .word 0x0000069E
	thumb_func_end ov45_0222F464


	thumb_func_start ov45_0222F484
ov45_0222F484: ; 0x0222F484
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F4A8 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F494
	bl GF_AssertFail
_0222F494:
	ldr r0, _0222F4A8 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x6a
	lsl r0, r0, #4
	add r0, r1, r0
	add r1, r4, #0
	bl ov45_02230434
	pop {r4, pc}
	nop
_0222F4A8: .word _022577C0
	thumb_func_end ov45_0222F484


	thumb_func_start ov45_0222F4AC
ov45_0222F4AC: ; 0x0222F4AC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F4D0 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F4BC
	bl GF_AssertFail
_0222F4BC:
	ldr r0, _0222F4D0 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x6a
	lsl r0, r0, #4
	add r0, r1, r0
	add r1, r4, #0
	bl ov45_0223045C
	pop {r4, pc}
	nop
_0222F4D0: .word _022577C0
	thumb_func_end ov45_0222F4AC


	thumb_func_start ov45_0222F4D4
ov45_0222F4D4: ; 0x0222F4D4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F520 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F4E4
	bl GF_AssertFail
_0222F4E4:
	cmp r4, #3
	blt _0222F4EC
	bl GF_AssertFail
_0222F4EC:
	ldr r0, _0222F520 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x26
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	cmp r0, #1
	bne _0222F4FE
	bl GF_AssertFail
_0222F4FE:
	add r0, r4, #0
	bl ov45_02232E60
	bl ov45_0222F74C
	cmp r0, #1
	beq _0222F510
	bl GF_AssertFail
_0222F510:
	ldr r0, _0222F520 ; =_022577C0
	mov r2, #1
	ldr r1, [r0]
	mov r0, #0x26
	lsl r0, r0, #6
	str r2, [r1, r0]
	pop {r4, pc}
	nop
_0222F520: .word _022577C0
	thumb_func_end ov45_0222F4D4


	thumb_func_start ov45_0222F524
ov45_0222F524: ; 0x0222F524
	push {r3, lr}
	ldr r0, _0222F540 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F532
	bl GF_AssertFail
_0222F532:
	ldr r0, _0222F540 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x26
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	pop {r3, pc}
	nop
_0222F540: .word _022577C0
	thumb_func_end ov45_0222F524


	thumb_func_start ov45_0222F544
ov45_0222F544: ; 0x0222F544
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F608 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F554
	bl GF_AssertFail
_0222F554:
	cmp r4, #0xb
	blt _0222F55C
	bl GF_AssertFail
_0222F55C:
	cmp r4, #0xa
	bhi _0222F5FE
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222F56C: ; jump table
	.short _0222F582 - _0222F56C - 2 ; case 0
	.short _0222F58C - _0222F56C - 2 ; case 1
	.short _0222F596 - _0222F56C - 2 ; case 2
	.short _0222F5A0 - _0222F56C - 2 ; case 3
	.short _0222F5B8 - _0222F56C - 2 ; case 4
	.short _0222F5C2 - _0222F56C - 2 ; case 5
	.short _0222F5CC - _0222F56C - 2 ; case 6
	.short _0222F5D6 - _0222F56C - 2 ; case 7
	.short _0222F5EE - _0222F56C - 2 ; case 8
	.short _0222F5EE - _0222F56C - 2 ; case 9
	.short _0222F5EE - _0222F56C - 2 ; case 10
_0222F582:
	ldr r0, _0222F608 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F60C ; =0x000006A8
	ldr r0, [r1, r0]
	pop {r4, pc}
_0222F58C:
	ldr r0, _0222F608 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F610 ; =0x000006AC
	ldr r0, [r1, r0]
	pop {r4, pc}
_0222F596:
	ldr r0, _0222F608 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F614 ; =0x00000804
	ldr r0, [r1, r0]
	pop {r4, pc}
_0222F5A0:
	ldr r0, _0222F608 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F610 ; =0x000006AC
	ldr r1, [r1, r0]
	mov r0, #0xfa
	lsl r0, r0, #2
	cmp r1, r0
	blt _0222F5B4
	mov r0, #1
	pop {r4, pc}
_0222F5B4:
	mov r0, #0
	pop {r4, pc}
_0222F5B8:
	ldr r0, _0222F608 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F618 ; =0x00000808
	ldr r0, [r1, r0]
	pop {r4, pc}
_0222F5C2:
	ldr r0, _0222F608 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F61C ; =0x0000080C
	ldr r0, [r1, r0]
	pop {r4, pc}
_0222F5CC:
	ldr r0, _0222F608 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F620 ; =0x00000964
	ldr r0, [r1, r0]
	pop {r4, pc}
_0222F5D6:
	ldr r0, _0222F608 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F61C ; =0x0000080C
	ldr r1, [r1, r0]
	mov r0, #0xfa
	lsl r0, r0, #2
	cmp r1, r0
	blt _0222F5EA
	mov r0, #1
	pop {r4, pc}
_0222F5EA:
	mov r0, #0
	pop {r4, pc}
_0222F5EE:
	ldr r0, _0222F608 ; =_022577C0
	sub r4, #8
	ldr r1, [r0]
	lsl r0, r4, #2
	add r1, r1, r0
	ldr r0, _0222F624 ; =0x00000974
	ldr r0, [r1, r0]
	pop {r4, pc}
_0222F5FE:
	bl GF_AssertFail
	mov r0, #0
	pop {r4, pc}
	nop
_0222F608: .word _022577C0
_0222F60C: .word 0x000006A8
_0222F610: .word 0x000006AC
_0222F614: .word 0x00000804
_0222F618: .word 0x00000808
_0222F61C: .word 0x0000080C
_0222F620: .word 0x00000964
_0222F624: .word 0x00000974
	thumb_func_end ov45_0222F544


	thumb_func_start ov45_0222F628
ov45_0222F628: ; 0x0222F628
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222F6A4 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F638
	bl GF_AssertFail
_0222F638:
	cmp r4, #8
	blt _0222F640
	bl GF_AssertFail
_0222F640:
	cmp r4, #7
	bhi _0222F69C
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222F650: ; jump table
	.short _0222F660 - _0222F650 - 2 ; case 0
	.short _0222F66C - _0222F650 - 2 ; case 1
	.short _0222F66C - _0222F650 - 2 ; case 2
	.short _0222F66C - _0222F650 - 2 ; case 3
	.short _0222F67E - _0222F650 - 2 ; case 4
	.short _0222F68A - _0222F650 - 2 ; case 5
	.short _0222F68A - _0222F650 - 2 ; case 6
	.short _0222F68A - _0222F650 - 2 ; case 7
_0222F660:
	ldr r0, _0222F6A4 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x6b
	lsl r0, r0, #4
	add r0, r1, r0
	pop {r4, pc}
_0222F66C:
	ldr r0, _0222F6A4 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F6A8 ; =0x0000078C
	add r2, r1, r0
	sub r1, r4, #1
	mov r0, #0x24
	mul r0, r1
	add r0, r2, r0
	pop {r4, pc}
_0222F67E:
	ldr r0, _0222F6A4 ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x81
	lsl r0, r0, #4
	add r0, r1, r0
	pop {r4, pc}
_0222F68A:
	ldr r0, _0222F6A4 ; =_022577C0
	ldr r1, [r0]
	ldr r0, _0222F6AC ; =0x000008EC
	add r2, r1, r0
	sub r1, r4, #5
	mov r0, #0x24
	mul r0, r1
	add r0, r2, r0
	pop {r4, pc}
_0222F69C:
	bl GF_AssertFail
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_0222F6A4: .word _022577C0
_0222F6A8: .word 0x0000078C
_0222F6AC: .word 0x000008EC
	thumb_func_end ov45_0222F628


	thumb_func_start ov45_0222F6B0
ov45_0222F6B0: ; 0x0222F6B0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0222F700 ; =_022577C0
	add r4, r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F6C2
	bl GF_AssertFail
_0222F6C2:
	cmp r5, #2
	blt _0222F6CA
	bl GF_AssertFail
_0222F6CA:
	cmp r4, #0xc
	blo _0222F6D2
	bl GF_AssertFail
_0222F6D2:
	cmp r5, #2
	blt _0222F6DA
	mov r0, #0
	pop {r3, r4, r5, pc}
_0222F6DA:
	cmp r4, #0xc
	blo _0222F6E2
	mov r0, #0
	pop {r3, r4, r5, pc}
_0222F6E2:
	cmp r5, #0
	bne _0222F6F2
	ldr r0, _0222F700 ; =_022577C0
	ldr r0, [r0]
	add r1, r0, r4
	ldr r0, _0222F704 ; =0x000007F8
	ldrb r0, [r1, r0]
	pop {r3, r4, r5, pc}
_0222F6F2:
	ldr r0, _0222F700 ; =_022577C0
	ldr r0, [r0]
	add r1, r0, r4
	ldr r0, _0222F708 ; =0x00000958
	ldrb r0, [r1, r0]
	pop {r3, r4, r5, pc}
	nop
_0222F700: .word _022577C0
_0222F704: .word 0x000007F8
_0222F708: .word 0x00000958
	thumb_func_end ov45_0222F6B0


	thumb_func_start ov45_0222F70C
ov45_0222F70C: ; 0x0222F70C
	push {r4, lr}
	ldr r0, _0222F744 ; =_022577C0
	ldr r0, [r0]
	cmp r0, #0
	bne _0222F71A
	bl GF_AssertFail
_0222F71A:
	mov r0, #0
	add r1, r0, #0
	bl ov00_021E5CD0
	mov r0, #0
	add r1, r0, #0
	bl ov00_021E5CA0
	ldr r2, _0222F744 ; =_022577C0
	ldr r0, _0222F748 ; =0x0000069C
	ldr r1, [r2]
	mov r3, #3
	strh r3, [r1, r0]
	add r1, r0, #2
	ldr r3, [r2]
	mov r4, #0
	strb r4, [r3, r1]
	ldr r1, [r2]
	add r0, r0, #3
	strb r4, [r1, r0]
	pop {r4, pc}
	.balign 4, 0
_0222F744: .word _022577C0
_0222F748: .word 0x0000069C
	thumb_func_end ov45_0222F70C


	thumb_func_start ov45_0222F74C
ov45_0222F74C: ; 0x0222F74C
	push {r3, lr}
	mov r1, #1
	cmp r0, #7
	bhi _0222F780
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222F760: ; jump table
	.short _0222F786 - _0222F760 - 2 ; case 0
	.short _0222F770 - _0222F760 - 2 ; case 1
	.short _0222F770 - _0222F760 - 2 ; case 2
	.short _0222F774 - _0222F760 - 2 ; case 3
	.short _0222F770 - _0222F760 - 2 ; case 4
	.short _0222F770 - _0222F760 - 2 ; case 5
	.short _0222F774 - _0222F760 - 2 ; case 6
	.short _0222F77C - _0222F760 - 2 ; case 7
_0222F770:
	mov r1, #0
	b _0222F786
_0222F774:
	bl GF_AssertFail
	mov r1, #0
	b _0222F786
_0222F77C:
	mov r1, #0
	b _0222F786
_0222F780:
	bl GF_AssertFail
	mov r1, #0
_0222F786:
	add r0, r1, #0
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov45_0222F74C


	thumb_func_start ov45_0222F78C
ov45_0222F78C: ; 0x0222F78C
	ldr r1, _0222F7A0 ; =_022577C0
	ldr r0, _0222F7A4 ; =0x00000133
	ldr r2, [r1]
	mov r3, #0
	strb r3, [r2, r0]
	ldr r1, [r1]
	sub r0, r0, #1
	strb r3, [r1, r0]
	bx lr
	nop
_0222F7A0: .word _022577C0
_0222F7A4: .word 0x00000133
	thumb_func_end ov45_0222F78C

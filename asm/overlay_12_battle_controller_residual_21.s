	.include "asm/macros.inc"
	.public BattleControl_EmitPartyStatusHeal
	.public BattleController_EmitBackgroundSlideIn
	.public BattleController_EmitBattleMonToPartyMonCopy
	.public BattleController_EmitBlankMessage
	.public BattleController_EmitChangeForm
	.public BattleController_EmitCopyStatus2Effect
	.public BattleController_EmitDeleteBallGauge
	.public BattleController_EmitDeleteBallGfx
	.public BattleController_EmitDeletePokemon
	.public BattleController_EmitDeleteStartBallGauge
	.public BattleController_EmitDrawYesNoBox
	.public BattleController_EmitFadeOutBattle
	.public BattleController_EmitForefitMessage
	.public BattleController_EmitHealthbarSlideIn
	.public BattleController_EmitHealthbarSlideOut
	.public BattleController_EmitHealthbarStatus
	.public BattleController_EmitHealthbarUpdate
	.public BattleController_EmitIncrementGameStat
	.public BattleController_EmitInitBallGauge
	.public BattleController_EmitInitStartBallGauge
	.public BattleController_EmitLoadBallGfx
	.public BattleController_EmitMonFlicker
	.public BattleController_EmitPlayEncounterAnimation
	.public BattleController_EmitPlayFaintAnimation
	.public BattleController_EmitPlayMosaicAnimation
	.public BattleController_EmitPlayMoveSE
	.public BattleController_EmitPlaySE
	.public BattleController_EmitPlaySong
	.public BattleController_EmitPokemonEncounter
	.public BattleController_EmitPokemonSendOut
	.public BattleController_EmitPokemonSlideIn
	.public BattleController_EmitPrintAttackMessage
	.public BattleController_EmitPrintEncounterMessage
	.public BattleController_EmitPrintFirstSendOutMessage
	.public BattleController_EmitPrintMessage
	.public BattleController_EmitPrintResultMessage
	.public BattleController_EmitPrintReturnMessage
	.public BattleController_EmitPrintSendOutMessage
	.public BattleController_EmitPrintTrainerMessage
	.public BattleController_EmitRecallPokemon
	.public BattleController_EmitRunAwayMessage
	.public BattleController_EmitSetBattleBackground
	.public BattleController_EmitSetBattleResults
	.public BattleController_EmitSetStatus2Effect
	.public BattleController_EmitShowMonList
	.public BattleController_EmitShowWaitMessage
	.public BattleController_EmitSwapToSubstituteSprite
	.public BattleController_EmitThrowPokeball
	.public BattleController_EmitToggleVanish
	.public BattleController_EmitTrainerEncounter
	.public BattleController_EmitTrainerSlideIn
	.public BattleController_EmitTrainerSlideOut
	.public BattleController_RecvData
	.public BattleController_SendData
	.public BattleController_SetMoveAnimation
	.public _022620BE
	.public _022620D2
	.public _022620EC
	.public _02262100
	.public _02262118
	.public _0226212A
	.public _02262160
	.public _02262172
	.public _02262176
	.public _0226218C
	.public _0226219E
	.public _022621A2
	.public _022621BE
	.public _022621C0
	.public _022621EA
	.public _02262206
	.public _0226221A
	.public _0226223C
	.public _0226226E
	.public _02262284
	.public _0226229A
	.public _022622AC
	.public _022622C4
	.public _02262392
	.public _022623E8
	.public _022623EC
	.public _022624C2
	.public _02262518
	.public _0226251C
	.public _02262520
	.public _0226256E
	.public _0226258E
	.public _02262600
	.public _0226260A
	.public _02262622
	.public _02262624
	.public _02262634
	.public _02262680
	.public _022626D6
	.public _022626EA
	.public _02262718
	.public _0226271C
	.public _02262720
	.public _02262724
	.public _02262728
	.public _0226272C
	.public _02262730
	.public _02262752
	.public _02262754
	.public _022627A6
	.public _022627C8
	.public _022627F6
	.public _022627F8
	.public _0226281A
	.public _02262848
	.public _02262852
	.public _02262880
	.public _02262884
	.public _02262888
	.public _0226288C
	.public _02262890
	.public _02262894
	.public _02262898
	.public _0226289C
	.public _022628BE
	.public _022628C0
	.public _0226290E
	.public _02262930
	.public _02262950
	.public _02262954
	.public _022629D8
	.public _02262AAE
	.public _02262AC8
	.public _02262AE2
	.public _02262B50
	.public _02262B54
	.public _02262B58
	.public _02262B5C
	.public _02262B60
	.public _02262BB0
	.public _02262BC4
	.public _02262BD0
	.public _02262C06
	.public _02262C08
	.public _02262C32
	.public _02262C72
	.public _02262C78
	.public _02262C7C
	.public _02262C86
	.public _02262C8C
	.public _02262C90
	.public _02262C9E
	.public _02262CBC
	.public _02262CD2
	.public _02262CDA
	.public _02262CFC
	.public _02262D3C
	.public _02262D42
	.public _02262D46
	.public _02262D48
	.public _02262D56
	.public _02262D6C
	.public _02262D74
	.public _02262D98
	.public _02262DD8
	.public _02262DDE
	.public _02262DE2
	.public _02262DE4
	.public _02262DF4
	.public _02262E20
	.public _02262E60
	.public _02262E66
	.public _02262E6A
	.public _02262E6C
	.public _02262E7A
	.public _02262E82
	.public _02262ED0
	.public _02262ED4
	.public _02262ED8
	.public _02262EDC
	.public _02262EE0
	.public _02262F02
	.public _02262F08
	.public _02262F0E
	.public _02262F7A
	.public _02262FD0
	.public _02262FD4
	.public _02262FD8
	.public _02262FDC
	.public _02263036
	.public _0226303E
	.public _02263044
	.public _02263064
	.public _0226308A
	.public _0226309E
	.public _022630B2
	.public _022630CC
	.public _022630D2
	.public _022630DE
	.public _02263108
	.public _0226310C
	.public _02263110
	.public _02263114
	.public _02263118
	.public _02263162
	.public _02263170
	.public _022631D4
	.public _02263200
	.public _02263216
	.public _0226321A
	.public _02263234
	.public _0226324A
	.public _0226324E
	.public _02263274
	.public _0226328A
	.public _0226328E
	.public _02263298
	.public _022632AC
	.public _022632B0
	.public _022632B4
	.public _022632B8
	.public _022632BC
	.public _02263318
	.public _02263324
	.public _02263354
	.public _02263358
	.public _0226335C
	.public _022633E8
	.public _022633EC
	.public _022634EE
	.public _02263500
	.public _0226350E
	.public _0226354C
	.public _02263550
	.public _02263554
	.public _02263558
	.public _0226355C
	.public _02263560
	.public _022635E0
	.public _022635E4
	.public _02263626
	.public _02263628
	.public _0226363A
	.public _0226363C
	.public _0226365A
	.public _0226366C
	.public _0226367E
	.public _022636AC
	.public _022636B6
	.public _022636E4
	.public _022636E8
	.public _022636EC
	.public _022636F0
	.public _022636F4
	.public _022636F8
	.public _02263760
	.public _02263762
	.public _02263770
	.public _022637B6
	.public _022637C6
	.public _022637F0
	.public _022637F4
	.public _022637F8
	.public _022637FC
	.public _02263800
	.public _02263804
	.public _022638E4
	.public _022638E8
	.public _0226390E
	.public _02263920
	.public _02263934
	.public _0226396C
	.public _02263982
	.public _02263998
	.public _022639D8
	.public _02263A9C
	.public _02263AB6
	.public _02263AD0
	.public _02263B38
	.public _02263B3C
	.public _02263B40
	.public _02263B44
	.public _02263B48
	.public _02263BE6
	.public _02263C1E
	.public _02263C2C
	.public _02263C4A
	.public _02263C4E
	.public _02263C6E
	.public _02263C72
	.public _02263C88
	.public _02263C8C
	.public _02263C90
	.public _02263C94
	.public _02263C98
	.public _02263C9C
	.public _02263CA0
	.public _02263CA4
	.public _02263CA8
	.public _02263CAC
	.public _02263D10
	.public _02263DC0
	.public _02263DD6
	.public _02263DF8
	.public _02263F74
	.public _02263F84
	.public _02263F88
	.public _02263FAE
	.public _02263FE8
	.public _02263FF6
	.public _02264024
	.public _02264028
	.public _0226402C
	.public _02264030
	.public _02264034
	.public _022640B2
	.public _022640C6
	.public _022640D4
	.public _02264104
	.public _02264118
	.public _0226411C
	.public _02264162
	.public _02264178
	.public _0226419E
	.public _022641D8
	.public _022641E6
	.public _02264214
	.public _02264218
	.public _0226421C
	.public _02264220
	.public _02264224
	.public _02264242
	.public _0226424E
	.public _02264252
	.public _02264264
	.public _022642D6
	.public _022642EC
	.public _0226435A
	.public _0226436E
	.public _0226438C
	.public _022643A0
	.public _022643A6
	.public _022643C2
	.public _02264410
	.public _02264422
	.public _02264430
	.public _02264476
	.public _0226447A
	.public _0226449C
	.public _0226449E
	.public _022644BA
	.public _022644E0
	.public _02264524
	.public _02264532
	.public _02264572
	.public _0226459A
	.public _022645A0
	.public _022645A4
	.public _022645A8
	.public _022645AC
	.public _022645B0
	.public _022645B4
	.public _022645B8
	.public _022645BC
	.public _022645C0
	.public _022645C4
	.public _02264636
	.public _02264646
	.public _0226464C
	.public _02264664
	.public _02264672
	.public _0226467C
	.public _0226469C
	.public _022646DE
	.public _022646E6
	.public _022646EC
	.public _022646EE
	.public _022646FC
	.public _02264714
	.public _0226471E
	.public _02264760
	.public _02264768
	.public _0226476E
	.public _02264770
	.public _02264782
	.public _02264796
	.public _022647B6
	.public _022647F8
	.public _02264800
	.public _02264806
	.public _02264808
	.public _02264816
	.public _0226481C
	.public _02264820
	.public ov12_022621C4
	.public ov12_02262240
	.public ov12_022628A0
	.public ov12_02262B80
	.public ov12_02262F24
	.public ov12_02262F40
	.public ov12_02262FE0
	.public ov12_02262FFC
	.public ov12_0226311C
	.public ov12_02263138
	.public ov12_022632C0
	.public ov12_02263360
	.public ov12_0226343C
	.public ov12_02263564
	.public ov12_0226399C
	.public ov12_022639B8
	.public ov12_02263A00
	.public ov12_02263A1C
	.public ov12_02263CCC
	.public ov12_02263D14
	.public ov12_02263E18
	.public ov12_02263F8C
	.public ov12_02264038
	.public ov12_02264054
	.public ov12_0226430C
	.public ov12_02264334
	.public ov12_022643C8
	.public ov12_022645C8
	.public ov12_022645F8
	.include "overlay_12_battle_controller.inc"
	.include "global.inc"

	.text
	.public BattleController_EmitBackgroundSlideIn
	.public BattleController_EmitBlankMessage
	.public BattleController_EmitCopyStatus2Effect
	.public BattleController_EmitDeleteBallGauge
	.public BattleController_EmitDeleteBallGfx
	.public BattleController_EmitDeletePokemon
	.public BattleController_EmitDeleteStartBallGauge
	.public BattleController_EmitFadeOutBattle
	.public BattleController_EmitHealthbarSlideOut
	.public BattleController_EmitHealthbarStatus
	.public BattleController_EmitIncrementGameStat
	.public BattleController_EmitInitBallGauge
	.public BattleController_EmitInitStartBallGauge
	.public BattleController_EmitLoadBallGfx
	.public BattleController_EmitMonFlicker
	.public BattleController_EmitPlayMosaicAnimation
	.public BattleController_EmitPlaySE
	.public BattleController_EmitPlaySong
	.public BattleController_EmitPrintEncounterMessage
	.public BattleController_EmitPrintMessage
	.public BattleController_EmitPrintResultMessage
	.public BattleController_EmitPrintTrainerMessage
	.public BattleController_EmitSetBattleBackground
	.public BattleController_EmitSetStatus2Effect
	.public BattleController_EmitTrainerSlideOut
	.public BattleController_SetMoveAnimation
	.public ov12_02262F24
	.public ov12_02262FE0
	.public ov12_0226311C
	.public ov12_022632C0
	.public ov12_02263360
	.public ov12_0226343C
	.public ov12_0226399C
	.public ov12_02263A00
	.public ov12_02263CCC
	.public ov12_02263D14
	.public ov12_02263E18
	.public ov12_02264038
	.public ov12_02264054
	.public ov12_0226430C
	.public ov12_022645C8

	thumb_func_start ov12_02264334
ov12_02264334: ; 0x02264334
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	mov r1, #1
	ldrb r3, [r5, #3]
	str r1, [sp]
	ldrb r2, [r5]
	ldrb r1, [r5, #2]
	lsl r3, r3, #8
	add r4, r0, #0
	orr r1, r3
	ldrb r6, [r5, #1]
	cmp r2, #0
	bne _0226436E
	mov r2, #0
	cmp r1, #0
	ble _022643C2
	mov r7, #0x23
	lsl r3, r6, #8
	lsl r7, r7, #8
_0226435A:
	add r0, r5, r2
	ldr r6, [r4, #0x30]
	ldrb r0, [r0, #4]
	add r6, r3, r6
	add r6, r2, r6
	add r2, r2, #1
	strb r0, [r6, r7]
	cmp r2, r1
	blt _0226435A
	b _022643C2
_0226436E:
	cmp r2, #1
	bne _022643A6
	lsl r0, r6, #2
	add r0, r4, r0
	mov r3, #0x6a
	ldr r4, [r0, #0x34]
	lsl r3, r3, #2
	ldrb r2, [r4, r3]
	cmp r2, #0
	bne _022643A0
	ldr r2, [sp]
	strb r2, [r4, r3]
	mov r2, #0
	cmp r1, #0
	ble _022643C2
_0226438C:
	add r3, r5, r2
	ldrb r4, [r3, #4]
	ldr r3, [r0, #0x34]
	add r3, r3, r2
	add r3, #0x94
	add r2, r2, #1
	strb r4, [r3]
	cmp r2, r1
	blt _0226438C
	b _022643C2
_022643A0:
	mov r0, #0
	str r0, [sp]
	b _022643C2
_022643A6:
	cmp r2, #2
	bne _022643C2
	ldrb r7, [r5, #4]
	ldrb r5, [r5, #5]
	bl ov12_0223B688
	cmp r0, #0
	beq _022643C2
	ldr r0, [r4, #0x30]
	add r1, r5, #0
	add r2, r6, #0
	add r3, r7, #0
	bl ov12_0224ED00
_022643C2:
	ldr r0, [sp]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov12_02264334


	thumb_func_start ov12_022643C8
ov12_022643C8: ; 0x022643C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r1, [sp, #8]
	ldr r1, [sp, #0x24]
	add r4, r2, #0
	str r1, [sp, #0x24]
	ldr r1, [sp, #0x28]
	str r0, [sp, #4]
	str r1, [sp, #0x28]
	mov r1, #0x16
	strb r1, [r4]
	add r1, sp, #0x10
	ldrh r1, [r1, #0x1c]
	strh r1, [r4, #2]
	ldr r1, [sp, #0x24]
	strh r1, [r4, #0x14]
	ldr r1, [sp, #0x28]
	strh r1, [r4, #0x16]
	ldr r1, [sp, #0x20]
	str r3, [r4, #0x4c]
	str r1, [r4, #0x50]
	bl BattleSystem_GetTerrainId
	str r0, [r4, #0x54]
	ldrh r1, [r4, #0xe]
	mov r0, #4
	bic r1, r0
	strh r1, [r4, #0xe]
	ldrh r1, [r4, #0xe]
	mov r0, #8
	bic r1, r0
	ldr r0, [sp, #8]
	strh r1, [r4, #0xe]
	cmp r0, #0
	bne _02264410
	b _0226459A
_02264410:
	ldr r1, _022645A0 ; =0x00002144
	ldr r0, [r0, r1]
	add r1, #0x10
	str r0, [r4, #4]
	ldr r0, [sp, #8]
	ldr r0, [r0, r1]
	cmp r0, #0
	beq _02264422
	b _02264430
_02264422:
	add r0, sp, #0x10
	ldrh r0, [r0, #0x1c]
	lsl r1, r0, #4
	ldr r0, [sp, #8]
	add r1, r0, r1
	ldr r0, _022645A4 ; =0x000003E1
	ldrb r0, [r1, r0]
_02264430:
	strh r0, [r4, #8]
	ldr r0, [sp, #0x24]
	mov r1, #0xc0
	mul r1, r0
	ldr r0, [sp, #8]
	mov r2, #8
	add r1, r0, r1
	ldr r0, _022645A8 ; =0x00002D75
	mov r3, #0
	ldrb r0, [r1, r0]
	ldr r1, [sp, #8]
	strh r0, [r4, #0xc]
	mov r0, #0xd
	str r0, [sp]
	ldr r0, [sp, #4]
	bl CheckAbilityActive
	cmp r0, #0
	bne _02264476
	mov r0, #0x4c
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	mov r2, #8
	mov r3, #0
	bl CheckAbilityActive
	cmp r0, #0
	bne _02264476
	mov r1, #6
	ldr r0, [sp, #8]
	lsl r1, r1, #6
	ldr r0, [r0, r1]
	str r0, [r4, #0x10]
	b _0226447A
_02264476:
	mov r0, #0
	str r0, [r4, #0x10]
_0226447A:
	ldr r1, _022645AC ; =0x00002164
	ldr r0, [sp, #8]
	ldr r0, [r0, r1]
	ldr r1, _022645B0 ; =0x00002DB0
	strh r0, [r4, #0xa]
	ldr r0, [sp, #8]
	add r2, r0, r1
	ldr r0, [sp, #0x24]
	mov r1, #0xc0
	mul r1, r0
	mov r0, #1
	ldr r3, [r2, r1]
	lsl r0, r0, #0x18
	tst r0, r3
	beq _0226449C
	mov r5, #1
	b _0226449E
_0226449C:
	mov r5, #0
_0226449E:
	ldrh r0, [r4, #0xe]
	mov r3, #1
	bic r0, r3
	lsl r3, r5, #0x10
	lsr r5, r3, #0x10
	mov r3, #1
	and r5, r3
	orr r0, r5
	strh r0, [r4, #0xe]
	ldr r1, [r2, r1]
	lsl r0, r3, #0x15
	tst r0, r1
	bne _022644BA
	mov r3, #0
_022644BA:
	ldrh r0, [r4, #0xe]
	mov r1, #2
	ldr r5, _022645B4 ; =0x00002D66
	bic r0, r1
	lsl r1, r3, #0x10
	lsr r1, r1, #0x10
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1e
	orr r0, r1
	ldr r1, [sp, #8]
	strh r0, [r4, #0xe]
	add r2, r1, #0
	add r6, r2, r5
	add r5, #0x58
	add r3, r1, #0
	mov r0, #0
	mov ip, r4
	add r2, r4, #0
	add r7, r3, r5
_022644E0:
	mov r3, #0xb5
	lsl r3, r3, #6
	ldrh r5, [r1, r3]
	mov r3, ip
	strh r5, [r3, #0x18]
	ldrb r3, [r6]
	lsl r3, r3, #0x1a
	lsr r5, r3, #0x1f
	add r3, r4, r0
	add r3, #0x24
	strb r5, [r3]
	ldrb r3, [r6]
	lsl r3, r3, #0x1b
	lsr r5, r3, #0x1b
	add r3, r4, r0
	add r3, #0x28
	strb r5, [r3]
	mov r3, #0xb7
	lsl r3, r3, #6
	ldr r3, [r1, r3]
	str r3, [r2, #0x3c]
	ldr r3, _022645B0 ; =0x00002DB0
	ldr r5, [r1, r3]
	mov r3, #2
	lsl r3, r3, #0x14
	tst r3, r5
	beq _02264524
	ldr r3, _022645B8 ; =0x00002DFA
	ldrh r5, [r1, r3]
	add r3, r4, r0
	add r3, #0x20
	strb r5, [r3]
	ldr r3, _022645BC ; =0x00002DE4
	b _02264532
_02264524:
	ldrb r3, [r7]
	lsl r3, r3, #0x1c
	lsr r5, r3, #0x1c
	add r3, r4, r0
	add r3, #0x20
	strb r5, [r3]
	ldr r3, _022645C0 ; =0x00002DA8
_02264532:
	ldr r3, [r1, r3]
	add r0, r0, #1
	str r3, [r2, #0x2c]
	mov r3, ip
	add r3, r3, #2
	add r1, #0xc0
	mov ip, r3
	add r6, #0xc0
	add r2, r2, #4
	add r7, #0xc0
	cmp r0, #4
	blt _022644E0
	ldr r0, [sp, #0x24]
	cmp r0, #0xff
	beq _02264572
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x24]
	bl ov12_0223C140
	cmp r0, #0xff
	beq _02264572
	ldr r2, [sp, #8]
	ldr r1, [sp, #0x24]
	add r2, r2, r1
	ldr r1, _022645C4 ; =0x0000219C
	ldrb r1, [r2, r1]
	cmp r0, r1
	bne _02264572
	ldrh r1, [r4, #0xe]
	mov r0, #4
	orr r0, r1
	strh r0, [r4, #0xe]
_02264572:
	ldr r0, [sp, #0x28]
	cmp r0, #0xff
	beq _0226459A
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x28]
	bl ov12_0223C140
	cmp r0, #0xff
	beq _0226459A
	ldr r2, [sp, #8]
	ldr r1, [sp, #0x28]
	add r2, r2, r1
	ldr r1, _022645C4 ; =0x0000219C
	ldrb r1, [r2, r1]
	cmp r0, r1
	bne _0226459A
	ldrh r1, [r4, #0xe]
	mov r0, #8
	orr r0, r1
	strh r0, [r4, #0xe]
_0226459A:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_022645A0: .word 0x00002144
_022645A4: .word 0x000003E1
_022645A8: .word 0x00002D75
_022645AC: .word 0x00002164
_022645B0: .word 0x00002DB0
_022645B4: .word 0x00002D66
_022645B8: .word 0x00002DFA
_022645BC: .word 0x00002DE4
_022645C0: .word 0x00002DA8
_022645C4: .word 0x0000219C
	thumb_func_end ov12_022643C8

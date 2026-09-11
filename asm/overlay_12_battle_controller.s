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

	thumb_func_start BattleController_SendData
BattleController_SendData: ; 0x02262098
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	add r6, r3, #0
	str r1, [sp]
	str r2, [sp, #4]
	cmp r1, #1
	bne _022620BE
	bl BattleSystem_GetRecvBufferPtr
	add r4, r0, #0
	add r0, r7, #0
	bl ov12_0223A984
	add r5, r0, #0
	add r0, r7, #0
	bl ov12_0223A990
	b _022620D2
_022620BE:
	bl BattleSystem_GetSendBufferPtr
	add r4, r0, #0
	add r0, r7, #0
	bl ov12_0223A960
	add r5, r0, #0
	add r0, r7, #0
	bl ov12_0223A96C
_022620D2:
	add r7, r0, #0
	add r0, sp, #0x10
	ldrh r2, [r5]
	ldrb r3, [r0, #0x10]
	add r0, r2, #5
	add r1, r0, r3
	mov r0, #1
	lsl r0, r0, #0xc
	cmp r1, r0
	bls _022620EC
	strh r2, [r7]
	mov r0, #0
	strh r0, [r5]
_022620EC:
	ldr r1, [sp]
	add r0, sp, #8
	strb r1, [r0]
	ldr r1, [sp, #4]
	strb r1, [r0, #1]
	add r1, sp, #0x10
	ldrb r1, [r1, #0x10]
	strh r1, [r0, #2]
	add r1, sp, #8
	mov r0, #0
_02262100:
	ldrb r7, [r1, r0]
	ldrh r2, [r5]
	add r0, r0, #1
	strb r7, [r4, r2]
	ldrh r2, [r5]
	add r2, r2, #1
	strh r2, [r5]
	cmp r0, #4
	blo _02262100
	mov r0, #0
	cmp r3, #0
	ble _0226212A
_02262118:
	ldrb r2, [r6, r0]
	ldrh r1, [r5]
	add r0, r0, #1
	strb r2, [r4, r1]
	ldrh r1, [r5]
	add r1, r1, #1
	strh r1, [r5]
	cmp r0, r3
	blt _02262118
_0226212A:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end BattleController_SendData


	thumb_func_start BattleController_RecvData
BattleController_RecvData: ; 0x02262130
	push {r3, r4, r5, r6, r7, lr}
	add r3, r1, #0
	ldrb r6, [r3, #3]
	ldrb r1, [r3]
	ldrb r7, [r3, #2]
	lsl r6, r6, #8
	add r5, r0, #0
	mov r2, #0
	orr r6, r7
	ldrb r4, [r3, #1]
	cmp r1, #0
	bne _02262176
	ldr r0, [r5, #0x30]
	lsl r1, r4, #8
	add r4, r0, r1
	mov r0, #0x23
	lsl r0, r0, #8
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _022621C0
	cmp r6, #0
	ble _02262172
	mov r4, #0x23
	lsl r4, r4, #8
_02262160:
	add r0, r3, r2
	ldr r7, [r5, #0x30]
	ldrb r0, [r0, #4]
	add r7, r1, r7
	add r7, r2, r7
	add r2, r2, #1
	strb r0, [r7, r4]
	cmp r2, r6
	blt _02262160
_02262172:
	mov r2, #1
	b _022621C0
_02262176:
	cmp r1, #1
	bne _022621A2
	lsl r0, r4, #2
	add r0, r5, r0
	ldr r1, [r0, #0x34]
	add r1, #0x94
	ldrb r1, [r1]
	cmp r1, #0
	bne _022621C0
	cmp r6, #0
	ble _0226219E
_0226218C:
	add r1, r3, r2
	ldrb r4, [r1, #4]
	ldr r1, [r0, #0x34]
	add r1, r1, r2
	add r1, #0x94
	add r2, r2, #1
	strb r4, [r1]
	cmp r2, r6
	blt _0226218C
_0226219E:
	mov r2, #1
	b _022621C0
_022621A2:
	cmp r1, #2
	bne _022621C0
	ldrb r7, [r3, #4]
	ldrb r6, [r3, #5]
	bl ov12_0223B688
	cmp r0, #0
	beq _022621BE
	ldr r0, [r5, #0x30]
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl ov12_0224ED00
_022621BE:
	mov r2, #1
_022621C0:
	add r0, r2, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end BattleController_RecvData


	thumb_func_start ov12_022621C4
ov12_022621C4: ; 0x022621C4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	cmp r1, #1
	bne _022621EA
	bl BattleSystem_GetRecvBufferPtr
	add r6, r0, #0
	add r0, r5, #0
	bl ov12_0223A978
	add r4, r0, #0
	add r0, r5, #0
	bl ov12_0223A984
	add r7, r0, #0
	add r0, r5, #0
	bl ov12_0223A990
	b _02262206
_022621EA:
	bl BattleSystem_GetSendBufferPtr
	add r6, r0, #0
	add r0, r5, #0
	bl ov12_0223A954
	add r4, r0, #0
	add r0, r5, #0
	bl ov12_0223A960
	add r7, r0, #0
	add r0, r5, #0
	bl ov12_0223A96C
_02262206:
	ldrh r1, [r4]
	ldrh r2, [r7]
	cmp r1, r2
	beq _0226223C
	ldrh r2, [r0]
	cmp r1, r2
	bne _0226221A
	mov r1, #0
	strh r1, [r4]
	strh r1, [r0]
_0226221A:
	ldrh r1, [r4]
	add r0, r5, #0
	add r1, r6, r1
	bl BattleController_RecvData
	cmp r0, #1
	bne _0226223C
	ldrh r0, [r4]
	add r1, r0, #2
	ldrb r2, [r6, r1]
	add r1, r0, #3
	ldrb r1, [r6, r1]
	lsl r1, r1, #8
	orr r1, r2
	add r1, r1, #4
	add r0, r0, r1
	strh r0, [r4]
_0226223C:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov12_022621C4


	thumb_func_start ov12_02262240
ov12_02262240: ; 0x02262240
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	str r1, [sp, #4]
	ldr r1, [r5, #0x2c]
	mov r0, #4
	add r7, r2, #0
	add r6, r3, #0
	tst r0, r1
	beq _0226229A
	ldr r0, _022622C4 ; =0x0000240C
	ldr r1, [r5, r0]
	mov r0, #0x10
	tst r0, r1
	bne _0226229A
	ldr r0, [sp, #4]
	cmp r0, #1
	bne _02262284
	mov r4, #0
	bl sub_02037454
	cmp r0, #0
	ble _02262284
_0226226E:
	ldrb r3, [r6]
	ldr r0, [r5, #0x30]
	add r1, r4, #0
	add r2, r7, #0
	bl ov12_0224ECC4
	add r4, r4, #1
	bl sub_02037454
	cmp r4, r0
	blt _0226226E
_02262284:
	add r0, sp, #0x10
	ldrb r0, [r0, #0x10]
	ldr r1, [sp, #4]
	add r2, r7, #0
	str r0, [sp]
	add r0, r5, #0
	add r3, r6, #0
	bl sub_02074F9C
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_0226229A:
	ldr r0, [sp, #4]
	cmp r0, #1
	bne _022622AC
	ldrb r3, [r6]
	ldr r0, [r5, #0x30]
	mov r1, #0
	add r2, r7, #0
	bl ov12_0224ECC4
_022622AC:
	add r0, sp, #0x10
	ldrb r0, [r0, #0x10]
	ldr r1, [sp, #4]
	add r2, r7, #0
	str r0, [sp]
	add r0, r5, #0
	add r3, r6, #0
	bl BattleController_SendData
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022622C4: .word 0x0000240C
	thumb_func_end ov12_02262240


	thumb_func_start BattleController_EmitPlayEncounterAnimation
BattleController_EmitPlayEncounterAnimation: ; 0x022622C8
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r1, #0
	mov r1, #1
	add r5, r0, #0
	str r1, [sp, #4]
	bl BattleSystem_GetRandTemp
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp]
	add r0, r5, #0
	mov r1, #1
	add r2, r4, #0
	add r3, sp, #4
	bl ov12_02262240
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end BattleController_EmitPlayEncounterAnimation


	thumb_func_start BattleController_EmitPokemonEncounter
BattleController_EmitPokemonEncounter: ; 0x022622F0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	add r7, r1, #0
	mov r3, #2
	add r2, sp, #4
	strb r3, [r2]
	mov r2, #0xc0
	add r4, r7, #0
	mul r4, r2
	add r2, sp, #4
	ldrb r5, [r2, #1]
	mov r2, #3
	add r6, r0, #0
	bic r5, r2
	ldr r2, [r6, #0x30]
	add r3, r2, r4
	ldr r2, _022623E8 ; =0x00002DBE
	mov ip, r2
	ldrb r2, [r3, r2]
	lsl r2, r2, #0x1c
	lsr r3, r2, #0x1c
	mov r2, #3
	and r2, r3
	add r3, r5, #0
	orr r3, r2
	add r2, sp, #4
	strb r3, [r2, #1]
	ldrb r5, [r2, #1]
	mov r2, #4
	bic r5, r2
	ldr r2, [r6, #0x30]
	add r3, r2, r4
	mov r2, ip
	sub r2, #0x58
	ldrb r2, [r3, r2]
	add r3, r5, #0
	lsl r2, r2, #0x1a
	lsr r2, r2, #0x1f
	lsl r2, r2, #0x1f
	lsr r2, r2, #0x1d
	orr r3, r2
	add r2, sp, #4
	strb r3, [r2, #1]
	ldr r2, [r6, #0x30]
	add r3, r2, r4
	mov r2, ip
	sub r2, #0x7e
	ldrh r3, [r3, r2]
	add r2, sp, #4
	strh r3, [r2, #2]
	ldr r2, [r6, #0x30]
	add r3, r2, r4
	mov r2, ip
	sub r2, #0x16
	ldr r2, [r3, r2]
	str r2, [sp, #8]
	bl ov12_0223AB0C
	add r2, r0, #0
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	mov r3, #1
	bl ov12_02256748
	add r2, sp, #4
	str r0, [sp, #0xc]
	ldrb r0, [r2, #1]
	mov r1, #0xf8
	add r5, sp, #4
	bic r0, r1
	ldr r1, [r6, #0x30]
	add r3, r1, r4
	ldr r1, _022623EC ; =0x00002D66
	mov r4, #0
	ldrb r1, [r3, r1]
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x1b
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x18
	orr r0, r1
	strb r0, [r2, #1]
_02262392:
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	add r2, r4, #6
	mov r3, #0
	bl GetBattlerVar
	strh r0, [r5, #0xc]
	add r2, r4, #0
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	add r2, #0x1f
	mov r3, #0
	bl GetBattlerVar
	strh r0, [r5, #0x14]
	add r2, r4, #0
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	add r2, #0x27
	mov r3, #0
	bl GetBattlerVar
	strh r0, [r5, #0x1c]
	add r4, r4, #1
	add r5, r5, #2
	cmp r4, #4
	blt _02262392
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	mov r2, #0x2d
	add r3, sp, #0x28
	bl GetBattlerVar
	mov r0, #0x3c
	str r0, [sp]
	add r0, r6, #0
	mov r1, #1
	add r2, r7, #0
	add r3, sp, #4
	bl ov12_02262240
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022623E8: .word 0x00002DBE
_022623EC: .word 0x00002D66
	thumb_func_end BattleController_EmitPokemonEncounter


	thumb_func_start BattleController_EmitPokemonSlideIn
BattleController_EmitPokemonSlideIn: ; 0x022623F0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x78
	add r7, r1, #0
	add r3, sp, #4
	mov r2, #3
	strb r2, [r3]
	mov r2, #0xc0
	add r4, r7, #0
	mul r4, r2
	add r2, r3, #0
	ldrb r5, [r2, #1]
	mov r2, #3
	add r6, r0, #0
	bic r5, r2
	ldr r2, [r6, #0x30]
	add r3, r2, r4
	ldr r2, _02262518 ; =0x00002DBE
	mov ip, r2
	ldrb r2, [r3, r2]
	lsl r2, r2, #0x1c
	lsr r3, r2, #0x1c
	mov r2, #3
	and r2, r3
	add r3, r5, #0
	orr r3, r2
	add r2, sp, #4
	strb r3, [r2, #1]
	ldrb r5, [r2, #1]
	mov r2, #4
	bic r5, r2
	ldr r2, [r6, #0x30]
	add r3, r2, r4
	mov r2, ip
	sub r2, #0x58
	ldrb r2, [r3, r2]
	add r3, r5, #0
	lsl r2, r2, #0x1a
	lsr r2, r2, #0x1f
	lsl r2, r2, #0x1f
	lsr r2, r2, #0x1d
	orr r3, r2
	add r2, sp, #4
	strb r3, [r2, #1]
	ldr r2, [r6, #0x30]
	add r3, r2, r4
	mov r2, ip
	sub r2, #0x7e
	ldrh r3, [r3, r2]
	add r2, sp, #4
	strh r3, [r2, #2]
	ldr r2, [r6, #0x30]
	add r3, r2, r4
	mov r2, ip
	sub r2, #0x16
	ldr r2, [r3, r2]
	str r2, [sp, #8]
	bl ov12_0223AB0C
	add r2, r0, #0
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	mov r3, #1
	bl ov12_02256748
	str r0, [sp, #0xc]
	ldr r0, [r6, #0x30]
	add r2, sp, #4
	add r1, r0, r7
	ldr r0, _0226251C ; =0x0000219C
	ldrb r0, [r1, r0]
	mov r1, #0xf8
	str r0, [sp, #0x10]
	ldrb r0, [r2, #1]
	bic r0, r1
	ldr r1, [r6, #0x30]
	add r3, r1, r4
	ldr r1, _02262520 ; =0x00002D66
	ldrb r3, [r3, r1]
	add r1, #0x59
	lsl r3, r3, #0x1b
	lsr r3, r3, #0x1b
	lsl r3, r3, #0x1b
	lsr r3, r3, #0x18
	orr r0, r3
	strb r0, [r2, #1]
	ldr r0, [r6, #0x30]
	add r0, r0, r4
	ldrb r0, [r0, r1]
	add r1, r7, #0
	str r0, [sp, #0x14]
	add r0, r6, #0
	bl BattleSystem_GetBattlerIdPartner
	ldr r1, [r6, #0x30]
	ldr r2, [sp, #0x10]
	add r1, r1, r0
	ldr r0, _0226251C ; =0x0000219C
	ldrb r0, [r1, r0]
	add r1, r7, #0
	str r0, [sp, #0x4c]
	add r0, r6, #0
	bl ov12_0223B854
	mov r4, #0
	add r5, sp, #4
_022624C2:
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	add r2, r4, #6
	mov r3, #0
	bl GetBattlerVar
	strh r0, [r5, #0x18]
	add r2, r4, #0
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	add r2, #0x1f
	mov r3, #0
	bl GetBattlerVar
	strh r0, [r5, #0x20]
	add r2, r4, #0
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	add r2, #0x27
	mov r3, #0
	bl GetBattlerVar
	strh r0, [r5, #0x28]
	add r4, r4, #1
	add r5, r5, #2
	cmp r4, #4
	blt _022624C2
	ldr r0, [r6, #0x30]
	add r1, r7, #0
	mov r2, #0x2d
	add r3, sp, #0x34
	bl GetBattlerVar
	mov r0, #0x74
	str r0, [sp]
	add r0, r6, #0
	mov r1, #1
	add r2, r7, #0
	add r3, sp, #4
	bl ov12_02262240
	add sp, #0x78
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02262518: .word 0x00002DBE
_0226251C: .word 0x0000219C
_02262520: .word 0x00002D66
	thumb_func_end BattleController_EmitPokemonSlideIn


	thumb_func_start BattleController_EmitPokemonSendOut
BattleController_EmitPokemonSendOut: ; 0x02262524
	push {r4, r5, r6, r7, lr}
	sub sp, #0x84
	add r7, r1, #0
	add r4, r0, #0
	mov r1, #4
	add r6, sp, #0x10
	strb r1, [r6]
	mov r0, #0xc0
	add r5, r7, #0
	mul r5, r0
	ldr r0, [r4, #0x30]
	str r2, [sp, #4]
	add r2, r0, r5
	ldr r0, _02262718 ; =0x00002DB0
	str r3, [sp, #8]
	ldr r3, [r2, r0]
	lsl r1, r1, #0x13
	tst r1, r3
	ldrb r1, [r6, #1]
	beq _0226256E
	mov r3, #3
	bic r1, r3
	add r3, r0, #0
	add r3, #0x4a
	ldrh r2, [r2, r3]
	add r0, #0x34
	lsl r2, r2, #0x18
	lsr r3, r2, #0x18
	mov r2, #3
	and r2, r3
	orr r1, r2
	strb r1, [r6, #1]
	ldr r1, [r4, #0x30]
	add r1, r1, r5
	ldr r0, [r1, r0]
	str r0, [sp, #0x14]
	b _0226258E
_0226256E:
	mov r3, #3
	bic r1, r3
	add r3, r0, #0
	add r3, #0xe
	ldrb r2, [r2, r3]
	sub r0, #8
	lsl r2, r2, #0x1c
	lsr r3, r2, #0x1c
	mov r2, #3
	and r2, r3
	orr r1, r2
	strb r1, [r6, #1]
	ldr r1, [r4, #0x30]
	add r1, r1, r5
	ldr r0, [r1, r0]
	str r0, [sp, #0x14]
_0226258E:
	mov r0, #0xc0
	add r6, r7, #0
	add r3, sp, #0x10
	mul r6, r0
	ldrb r0, [r3, #1]
	mov r1, #4
	bic r0, r1
	ldr r1, [r4, #0x30]
	add r2, r1, r6
	ldr r1, _0226271C ; =0x00002D66
	ldrb r2, [r2, r1]
	sub r1, #0x26
	lsl r2, r2, #0x1a
	lsr r2, r2, #0x1f
	lsl r2, r2, #0x1f
	lsr r2, r2, #0x1d
	orr r0, r2
	strb r0, [r3, #1]
	ldr r0, [r4, #0x30]
	add r0, r0, r6
	ldrh r0, [r0, r1]
	add r1, r7, #0
	strh r0, [r3, #2]
	add r0, r4, #0
	bl ov12_0223AB0C
	add r2, r0, #0
	ldr r0, [r4, #0x30]
	add r1, r7, #0
	mov r3, #0
	bl ov12_02256748
	str r0, [sp, #0x18]
	ldr r0, [r4, #0x30]
	mov r2, #0xf8
	add r1, r0, r7
	ldr r0, _02262720 ; =0x0000219C
	ldrb r0, [r1, r0]
	str r0, [sp, #0x1c]
	add r0, sp, #0x10
	ldrb r1, [r0, #1]
	bic r1, r2
	ldr r2, [r4, #0x30]
	add r3, r2, r6
	ldr r2, _0226271C ; =0x00002D66
	ldrb r3, [r3, r2]
	lsl r3, r3, #0x1b
	lsr r3, r3, #0x1b
	lsl r3, r3, #0x1b
	lsr r3, r3, #0x18
	orr r1, r3
	strb r1, [r0, #1]
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _02262600
	str r0, [sp, #0x20]
	b _0226260A
_02262600:
	ldr r0, [r4, #0x30]
	add r2, #0x59
	add r0, r0, r5
	ldrb r0, [r0, r2]
	str r0, [sp, #0x20]
_0226260A:
	ldr r0, [sp, #8]
	str r0, [sp, #0x24]
	ldr r0, [r4, #0x30]
	add r1, r0, r5
	ldr r0, _02262718 ; =0x00002DB0
	ldr r1, [r1, r0]
	mov r0, #1
	lsl r0, r0, #0x18
	tst r0, r1
	beq _02262622
	mov r0, #1
	b _02262624
_02262622:
	mov r0, #0
_02262624:
	ldr r2, [sp, #0x1c]
	str r0, [sp, #0x5c]
	add r0, r4, #0
	add r1, r7, #0
	bl ov12_0223B854
	mov r6, #0
	add r5, sp, #0x10
_02262634:
	ldr r0, [r4, #0x30]
	add r1, r7, #0
	add r2, r6, #6
	mov r3, #0
	bl GetBattlerVar
	strh r0, [r5, #0x18]
	add r2, r6, #0
	ldr r0, [r4, #0x30]
	add r1, r7, #0
	add r2, #0x1f
	mov r3, #0
	bl GetBattlerVar
	strh r0, [r5, #0x20]
	add r2, r6, #0
	ldr r0, [r4, #0x30]
	add r1, r7, #0
	add r2, #0x27
	mov r3, #0
	bl GetBattlerVar
	strh r0, [r5, #0x28]
	add r6, r6, #1
	add r5, r5, #2
	cmp r6, #4
	blt _02262634
	ldr r0, [r4, #0x30]
	add r1, r7, #0
	mov r2, #0x2d
	add r3, sp, #0x40
	bl GetBattlerVar
	add r3, sp, #0x10
	mov r2, #0
	mov ip, r2
	str r3, [sp, #0xc]
	add r5, r3, #0
_02262680:
	ldr r0, [r4, #0x30]
	add r1, r0, r2
	mov r0, #0xb5
	lsl r0, r0, #6
	ldrh r1, [r1, r0]
	ldr r0, [sp, #0xc]
	add r0, #0x50
	strh r1, [r0]
	ldr r0, [r4, #0x30]
	add r1, r0, r2
	ldr r0, _0226271C ; =0x00002D66
	ldrb r0, [r1, r0]
	lsl r0, r0, #0x1a
	lsr r1, r0, #0x1f
	add r0, r3, #0
	add r0, #0x5c
	strb r1, [r0]
	ldr r0, [r4, #0x30]
	add r1, r0, r2
	ldr r0, _0226271C ; =0x00002D66
	ldrb r0, [r1, r0]
	lsl r0, r0, #0x1b
	lsr r1, r0, #0x1b
	add r0, r3, #0
	add r0, #0x60
	strb r1, [r0]
	ldr r0, [r4, #0x30]
	add r6, r0, r2
	ldr r0, _02262718 ; =0x00002DB0
	ldr r1, [r6, r0]
	mov r0, #2
	lsl r0, r0, #0x14
	tst r0, r1
	beq _022626D6
	ldr r0, _02262724 ; =0x00002DFA
	ldrh r1, [r6, r0]
	add r0, r3, #0
	add r0, #0x58
	strb r1, [r0]
	ldr r0, [r4, #0x30]
	add r1, r0, r2
	ldr r0, _02262728 ; =0x00002DE4
	b _022626EA
_022626D6:
	ldr r0, _0226272C ; =0x00002DBE
	ldrb r0, [r6, r0]
	lsl r0, r0, #0x1c
	lsr r1, r0, #0x1c
	add r0, r3, #0
	add r0, #0x58
	strb r1, [r0]
	ldr r0, [r4, #0x30]
	add r1, r0, r2
	ldr r0, _02262730 ; =0x00002DA8
_022626EA:
	ldr r0, [r1, r0]
	add r2, #0xc0
	str r0, [r5, #0x64]
	ldr r0, [sp, #0xc]
	add r3, r3, #1
	add r0, r0, #2
	str r0, [sp, #0xc]
	mov r0, ip
	add r0, r0, #1
	add r5, r5, #4
	mov ip, r0
	cmp r0, #4
	blt _02262680
	mov r0, #0x74
	str r0, [sp]
	add r0, r4, #0
	mov r1, #1
	add r2, r7, #0
	add r3, sp, #0x10
	bl ov12_02262240
	add sp, #0x84
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02262718: .word 0x00002DB0
_0226271C: .word 0x00002D66
_02262720: .word 0x0000219C
_02262724: .word 0x00002DFA
_02262728: .word 0x00002DE4
_0226272C: .word 0x00002DBE
_02262730: .word 0x00002DA8
	thumb_func_end BattleController_EmitPokemonSendOut


	thumb_func_start BattleController_EmitRecallPokemon
BattleController_EmitRecallPokemon: ; 0x02262734
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	add r4, r1, #0
	lsl r1, r2, #2
	str r0, [sp, #4]
	add r0, r0, r1
	ldr r1, [r0, #0x34]
	ldr r0, _02262880 ; =0x00000195
	str r2, [sp, #8]
	ldrb r1, [r1, r0]
	mov r0, #1
	tst r0, r1
	beq _02262752
	mov r2, #2
	b _02262754
_02262752:
	mov r2, #0
_02262754:
	ldr r1, [sp, #8]
	mov r0, #0xc0
	mul r0, r1
	ldr r1, [sp, #4]
	mov r6, #5
	ldr r1, [r1, #0x30]
	add r5, sp, #0xc
	add r3, r1, r0
	ldr r1, _02262884 ; =0x00002D66
	ldrb r3, [r3, r1]
	strb r6, [r5]
	ldr r5, [sp, #4]
	lsl r3, r3, #0x1b
	ldr r5, [r5, #0x30]
	lsr r3, r3, #0x1b
	add r5, r5, r0
	add r0, r1, #0
	add r0, #0x4a
	ldr r6, [r5, r0]
	mov r0, #2
	lsl r0, r0, #0x14
	tst r0, r6
	beq _022627A6
	add r0, r1, #0
	add r0, #0x7e
	ldr r0, [r5, r0]
	lsl r2, r2, #0x18
	str r0, [sp]
	add r0, r1, #0
	add r1, #0x94
	ldrh r1, [r5, r1]
	sub r0, #0x26
	lsl r3, r3, #0x18
	lsl r1, r1, #0x18
	ldrh r0, [r5, r0]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl GetMonPicHeightBySpeciesGenderForm
	b _022627C8
_022627A6:
	add r0, r1, #0
	add r0, #0x42
	ldr r0, [r5, r0]
	lsl r2, r2, #0x18
	str r0, [sp]
	add r0, r1, #0
	add r1, #0x58
	ldrb r1, [r5, r1]
	sub r0, #0x26
	lsl r3, r3, #0x18
	lsl r1, r1, #0x1c
	ldrh r0, [r5, r0]
	lsr r1, r1, #0x1c
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl GetMonPicHeightBySpeciesGenderForm
_022627C8:
	add r1, sp, #0xc
	strb r0, [r1, #1]
	ldr r1, [sp, #8]
	mov r0, #0xc0
	mul r0, r1
	ldr r1, [sp, #4]
	ldr r2, _02262888 ; =0x00002DBF
	ldr r1, [r1, #0x30]
	add r1, r1, r0
	ldrb r3, [r1, r2]
	add r1, sp, #0xc
	sub r2, #0xf
	strh r3, [r1, #2]
	ldr r1, [sp, #4]
	ldr r1, [r1, #0x30]
	add r0, r1, r0
	ldr r1, [r0, r2]
	mov r0, #1
	lsl r0, r0, #0x18
	tst r0, r1
	beq _022627F6
	mov r0, #1
	b _022627F8
_022627F6:
	mov r0, #0
_022627F8:
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	add r7, sp, #0xc
	ldr r1, [r0, #0x30]
	ldr r0, [sp, #8]
	add r3, r7, #0
	add r1, r1, r0
	ldr r0, _0226288C ; =0x0000219C
	add r5, r7, #0
	ldrb r0, [r1, r0]
	str r0, [sp, #0x38]
	mov r0, #0
	mov ip, r0
	ldr r0, _02262884 ; =0x00002D66
	add r2, r4, r0
	add r0, #0x58
	add r6, r4, r0
_0226281A:
	mov r0, #0xb5
	lsl r0, r0, #6
	ldrh r0, [r4, r0]
	strh r0, [r7, #8]
	ldrb r0, [r2]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1f
	strb r0, [r3, #0x14]
	ldrb r0, [r2]
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1b
	strb r0, [r3, #0x18]
	ldr r0, _02262890 ; =0x00002DB0
	ldr r1, [r4, r0]
	mov r0, #2
	lsl r0, r0, #0x14
	tst r0, r1
	beq _02262848
	ldr r0, _02262894 ; =0x00002DFA
	ldrh r0, [r4, r0]
	strb r0, [r3, #0x10]
	ldr r0, _02262898 ; =0x00002DE4
	b _02262852
_02262848:
	ldrb r0, [r6]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	strb r0, [r3, #0x10]
	ldr r0, _0226289C ; =0x00002DA8
_02262852:
	ldr r0, [r4, r0]
	add r4, #0xc0
	str r0, [r5, #0x1c]
	mov r0, ip
	add r0, r0, #1
	add r7, r7, #2
	add r2, #0xc0
	add r3, r3, #1
	add r5, r5, #4
	add r6, #0xc0
	mov ip, r0
	cmp r0, #4
	blt _0226281A
	mov r0, #0x30
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r2, [sp, #8]
	mov r1, #1
	add r3, sp, #0xc
	bl ov12_02262240
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02262880: .word 0x00000195
_02262884: .word 0x00002D66
_02262888: .word 0x00002DBF
_0226288C: .word 0x0000219C
_02262890: .word 0x00002DB0
_02262894: .word 0x00002DFA
_02262898: .word 0x00002DE4
_0226289C: .word 0x00002DA8
	thumb_func_end BattleController_EmitRecallPokemon


	thumb_func_start ov12_022628A0
ov12_022628A0: ; 0x022628A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r1, #0
	add r4, r0, #0
	lsl r0, r7, #2
	add r0, r4, r0
	ldr r1, [r0, #0x34]
	ldr r0, _02262950 ; =0x00000195
	str r2, [sp, #4]
	ldrb r1, [r1, r0]
	mov r0, #1
	tst r0, r1
	beq _022628BE
	mov r2, #2
	b _022628C0
_022628BE:
	mov r2, #0
_022628C0:
	mov r0, #0xc0
	add r6, r7, #0
	mul r6, r0
	ldr r0, [r4, #0x30]
	ldr r5, _02262954 ; =0x00002D66
	add r0, r0, r6
	ldrb r0, [r0, r5]
	mov r1, #6
	lsl r0, r0, #0x1b
	lsr r3, r0, #0x1b
	add r0, sp, #8
	strb r1, [r0]
	ldr r0, [r4, #0x30]
	add r1, r0, r6
	add r0, r5, #0
	add r0, #0x4a
	ldr r6, [r1, r0]
	mov r0, #2
	lsl r0, r0, #0x14
	tst r0, r6
	beq _0226290E
	add r0, r5, #0
	add r0, #0x7e
	ldr r0, [r1, r0]
	lsl r2, r2, #0x18
	str r0, [sp]
	add r0, r5, #0
	sub r0, #0x26
	add r5, #0x94
	ldrh r0, [r1, r0]
	ldrh r1, [r1, r5]
	lsl r3, r3, #0x18
	lsr r2, r2, #0x18
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl GetMonPicHeightBySpeciesGenderForm
	b _02262930
_0226290E:
	add r0, r5, #0
	add r0, #0x42
	ldr r0, [r1, r0]
	lsl r2, r2, #0x18
	str r0, [sp]
	add r0, r5, #0
	sub r0, #0x26
	add r5, #0x58
	ldrh r0, [r1, r0]
	ldrb r1, [r1, r5]
	lsl r3, r3, #0x18
	lsr r2, r2, #0x18
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	lsr r3, r3, #0x18
	bl GetMonPicHeightBySpeciesGenderForm
_02262930:
	add r1, sp, #8
	strb r0, [r1, #1]
	ldr r0, [sp, #4]
	add r1, sp, #8
	strh r0, [r1, #2]
	mov r0, #4
	str r0, [sp]
	add r0, r4, #0
	mov r1, #1
	add r2, r7, #0
	add r3, sp, #8
	bl ov12_02262240
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_02262950: .word 0x00000195
_02262954: .word 0x00002D66
	thumb_func_end ov12_022628A0

.include "asm/macros.inc"
.include "overlay_12_battle_controller.inc"
.include "global.inc"

.public ov12_02262240

	.text

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

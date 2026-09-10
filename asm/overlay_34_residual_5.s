	.include "asm/macros.inc"
	.public ov34_0225D520
	.public ov34_0225D558
	.public ov34_0225D5A0
	.public ov34_0225D5F8
	.public ov34_0225D650
	.public ov34_0225D77C
	.public ov34_0225D7A8
	.public ov34_0225D87C
	.public ov34_0225D900
	.public ov34_0225D924
	.public ov34_0225DA50
	.public ov34_0225DB20
	.public ov34_0225DC00
	.public ov34_0225DC0C
	.public ov34_0225DC18
	.public ov34_0225DD04
	.public ov34_0225DDB8
	.public ov34_0225DE04
	.public ov34_0225DE94
	.public ov34_0225E020
	.public ov34_0225E0E4
	.public ov34_0225E164
	.public ov34_0225E1C4
	.public ov34_0225E2BC
	.public ov34_0225E348
	.public ov34_0225E428
	.public ov34_0225E4A8
	.public ov34_0225E4F8
	.public ov34_0225E560
	.public ov34_0225E56C
	.public ov34_0225E58C
	.public ov34_0225E5D4
	.public ov34_0225E5DC
	.public ov34_0225E5E4
	.public ov34_0225E5EC
	.public ov34_0225E630
	.public _0225E694
	.public ov34_0225E6A0
	.public ov34_0225E6AC
	.public ov34_0225E6C0
	.public ov34_0225E6DC
	.public ov34_0225E6F8
	.public ov34_0225E714
	.public ov34_0225E730
	.include "overlay_34.inc"
	.include "global.inc"

	.text

	thumb_func_start ov34_0225DE04
ov34_0225DE04: ; 0x0225DE04
	push {r4, lr}
	mov r1, #0x27
	add r4, r0, #0
	lsl r1, r1, #4
	add r0, r1, #0
	ldr r2, [r4, r1]
	add r0, #0xd8
	ldr r2, [r2, r0]
	add r0, r1, #0
	add r0, #0x14
	strh r2, [r4, r0]
	add r0, r1, #0
	add r0, #0x14
	ldrh r0, [r4, r0]
	cmp r0, #3
	bls _0225DE42
	add r0, r1, #0
	add r0, #0x16
	ldrh r0, [r4, r0]
	cmp r0, #3
	bhi _0225DE42
	add r0, r1, #0
	mov r2, #1
	add r0, #0x1a
	strh r2, [r4, r0]
	add r0, r1, #0
	add r0, #0x14
	ldrh r0, [r4, r0]
	add r1, #0x18
	sub r0, r0, #3
	strh r0, [r4, r1]
_0225DE42:
	mov r1, #0x1a
	lsl r1, r1, #4
	ldr r0, [r4, r1]
	add r1, #0xea
	ldrh r1, [r4, r1]
	bl Sprite_SetDrawFlag
	ldr r0, _0225DE90 ; =0x0000028A
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _0225DE84
	add r0, r4, #0
	bl ov34_0225E5E4
	cmp r0, #1
	bne _0225DE84
	mov r1, #0xa2
	lsl r1, r1, #2
	ldrh r2, [r4, r1]
	sub r1, r1, #4
	ldrh r1, [r4, r1]
	mov r0, #0x60
	mul r0, r2
	sub r1, r1, #3
	bl _s32_div_f
	add r1, r0, #0
	mov r0, #0x1a
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r1, #0x30
	bl ov34_0225DDB8
_0225DE84:
	mov r0, #0xa1
	lsl r0, r0, #2
	ldrh r1, [r4, r0]
	add r0, r0, #2
	strh r1, [r4, r0]
	pop {r4, pc}
	.balign 4, 0
_0225DE90: .word 0x0000028A
	thumb_func_end ov34_0225DE04


	thumb_func_start ov34_0225DE94
ov34_0225DE94: ; 0x0225DE94
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	ldr r0, _0225E00C ; =ov34_0225E730
	bl TouchscreenHitbox_FindRectAtTouchHeld
	add r7, r0, #0
	add r0, r4, #0
	bl ov34_0225E5D4
	add r5, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r7, r0
	beq _0225DEDA
	cmp r7, #6
	bhi _0225DF5E
	add r0, r7, r7
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225DEC0: ; jump table
	.short _0225DECE - _0225DEC0 - 2 ; case 0
	.short _0225DF00 - _0225DEC0 - 2 ; case 1
	.short _0225DF5E - _0225DEC0 - 2 ; case 2
	.short _0225DF5E - _0225DEC0 - 2 ; case 3
	.short _0225DF5E - _0225DEC0 - 2 ; case 4
	.short _0225DF36 - _0225DEC0 - 2 ; case 5
	.short _0225DF40 - _0225DEC0 - 2 ; case 6
_0225DECE:
	add r0, r4, #0
	add r1, r7, #0
	bl ov34_0225E5EC
	cmp r5, #1
	beq _0225DEDC
_0225DEDA:
	b _0225E006
_0225DEDC:
	mov r0, #0xa2
	lsl r0, r0, #2
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _0225DEF6
	ldr r0, _0225E010 ; =0x000005E5
	bl PlaySE
	mov r0, #0xa2
	lsl r0, r0, #2
	ldrh r1, [r4, r0]
	sub r1, r1, #1
	strh r1, [r4, r0]
_0225DEF6:
	mov r0, #0x71
	sub r1, r7, #2
	lsl r0, r0, #2
	str r1, [r4, r0]
	b _0225E006
_0225DF00:
	add r0, r4, #0
	add r1, r7, #0
	bl ov34_0225E5EC
	cmp r5, #1
	bne _0225E006
	mov r0, #0xa2
	lsl r0, r0, #2
	ldrh r1, [r4, r0]
	sub r0, r0, #4
	ldrh r0, [r4, r0]
	sub r0, r0, #3
	cmp r1, r0
	bge _0225DF2C
	ldr r0, _0225E010 ; =0x000005E5
	bl PlaySE
	mov r0, #0xa2
	lsl r0, r0, #2
	ldrh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
_0225DF2C:
	mov r0, #0x71
	sub r1, r7, #2
	lsl r0, r0, #2
	str r1, [r4, r0]
	b _0225E006
_0225DF36:
	mov r0, #0x71
	sub r1, r7, #2
	lsl r0, r0, #2
	str r1, [r4, r0]
	b _0225E006
_0225DF40:
	ldr r0, _0225E014 ; =gSystem + 0x40
	ldrh r0, [r0, #0x24]
	cmp r0, #0
	beq _0225E006
	ldr r0, [r4, #0xc]
	bl ov01_021F6B10
	cmp r0, #1
	bne _0225E006
	ldr r0, _0225E018 ; =0x000005FC
	bl PlaySE
	mov r0, #3
	str r0, [r4]
	b _0225E006
_0225DF5E:
	ldr r0, _0225E014 ; =gSystem + 0x40
	ldrh r0, [r0, #0x24]
	cmp r0, #0
	beq _0225E006
	mov r2, #0x27
	lsl r2, r2, #4
	add r1, r2, #0
	ldr r0, [r4, r2]
	add r1, #0xd8
	ldr r3, [r0, r1]
	sub r1, r7, #1
	cmp r3, r1
	blt _0225DFFE
	add r1, r2, #0
	add r1, #0xdc
	add r2, #0x18
	ldr r0, [r0, r1]
	ldrh r1, [r4, r2]
	add r1, r1, r7
	sub r1, r1, #2
	bl ov34_0225DC0C
	mov r1, #0x1c
	mov r5, #0
	mul r1, r0
	add r6, r5, #0
	str r1, [sp]
_0225DF94:
	add r0, r5, #0
	bl sub_02035754
	cmp r0, #0
	beq _0225DFD0
	ldr r1, [r4, #4]
	add r0, #0x50
	add r1, r1, r6
	ldrb r1, [r1, #0xd]
	cmp r1, #2
	bne _0225DFD0
	mov r1, #0x27
	lsl r1, r1, #4
	ldr r2, [r4, r1]
	ldr r1, [sp]
	ldr r0, [r0]
	add r1, r1, r2
	ldr r1, [r1, #0xc]
	cmp r0, r1
	bne _0225DFD0
	ldr r0, _0225E010 ; =0x000005E5
	bl PlaySE
	mov r1, #0x18
	ldr r2, [r4, #4]
	mul r1, r5
	mov r0, #1
	add r1, r2, r1
	strb r0, [r1, #0xf]
	b _0225DFD8
_0225DFD0:
	add r5, r5, #1
	add r6, #0x18
	cmp r5, #0xa
	blt _0225DF94
_0225DFD8:
	bl sub_02035784
	bl PlayerProfile_GetTrainerID
	mov r1, #0x27
	lsl r1, r1, #4
	ldr r2, [r4, r1]
	ldr r1, [sp]
	add r1, r2, r1
	ldr r1, [r1, #0xc]
	cmp r1, r0
	bne _0225DFFE
	ldr r0, _0225E010 ; =0x000005E5
	bl PlaySE
	ldr r1, [r4, #4]
	ldr r0, _0225E01C ; =0x000004BF
	mov r2, #1
	strb r2, [r1, r0]
_0225DFFE:
	mov r0, #0x71
	sub r1, r7, #2
	lsl r0, r0, #2
	str r1, [r4, r0]
_0225E006:
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225E00C: .word ov34_0225E730
_0225E010: .word 0x000005E5
_0225E014: .word gSystem + 0x40
_0225E018: .word 0x000005FC
_0225E01C: .word 0x000004BF
	thumb_func_end ov34_0225DE94


	thumb_func_start ov34_0225E020
ov34_0225E020: ; 0x0225E020
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	ldr r0, _0225E0E0 ; =ov34_0225E6AC
	bl TouchscreenHitbox_FindRectAtTouchHeld
	mov r1, #0
	mvn r1, r1
	str r0, [sp]
	cmp r0, r1
	beq _0225E0D0
	cmp r0, #0
	bne _0225E09A
	add r0, r7, #0
	mov r1, #0
	bl ov34_0225E5DC
	add r0, sp, #8
	add r1, sp, #4
	bl System_GetTouchHeldCoords
	mov r0, #0x1a
	lsl r0, r0, #4
	ldr r0, [r7, r0]
	ldr r1, [sp, #4]
	bl ov34_0225DDB8
	mov r0, #0xa1
	lsl r0, r0, #2
	ldrh r0, [r7, r0]
	cmp r0, #3
	bls _0225E0D8
	sub r4, r0, #2
	mov r0, #0x60
	add r1, r4, #0
	bl _s32_div_f
	mov r1, #0
	cmp r4, #0
	ble _0225E0D8
	ldr r5, [sp, #4]
	add r2, r1, #0
	add r3, r1, #0
_0225E076:
	add r6, r2, #0
	add r6, #0x30
	cmp r5, r6
	blo _0225E08E
	add r6, r3, r0
	add r6, #0x30
	cmp r5, r6
	bhs _0225E08E
	mov r0, #0xa2
	lsl r0, r0, #2
	strh r1, [r7, r0]
	b _0225E0D8
_0225E08E:
	add r1, r1, #1
	add r2, r2, r0
	add r3, r3, r0
	cmp r1, r4
	blt _0225E076
	b _0225E0D8
_0225E09A:
	mov r1, #0x27
	lsl r1, r1, #4
	add r0, r1, #0
	ldr r2, [r7, r1]
	add r0, #0xd8
	ldr r2, [r2, r0]
	ldr r0, [sp]
	cmp r2, r0
	blt _0225E0D8
	add r0, r1, #0
	sub r0, #0xac
	ldr r2, [r7, r0]
	ldr r0, [sp]
	sub r3, r0, #1
	cmp r2, r3
	bne _0225E0D8
	sub r1, #0x74
	add r2, r7, r1
	mov r0, #0x38
	add r1, r3, #0
	mul r1, r0
	ldr r0, [r2, r1]
	cmp r0, #5
	bge _0225E0D8
	add r0, r0, #1
	str r0, [r2, r1]
	b _0225E0D8
_0225E0D0:
	add r0, r7, #0
	mov r1, #1
	bl ov34_0225E5DC
_0225E0D8:
	ldr r0, [sp]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_0225E0E0: .word ov34_0225E6AC
	thumb_func_end ov34_0225E020

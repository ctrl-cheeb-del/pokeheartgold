	.include "asm/macros.inc"
	.include "overlay_97.inc"
	.include "global.inc"

	.text
	.public _0221FC98
	.public ov97_0221E5D4
	.public ov97_0221E700
	.public ov97_0221E898
	.public ov97_0221E91C
	.public ov97_0221E98C
	.public ov97_0221EA88
	.public ov97_0221EB38
	.public ov97_0221EC14
	.public ov97_0221EDE4
	.public ov97_0221EEA4
	.public ov97_0221EFD0
	.public ov97_0221F020
	.public ov97_0221F0E0
	.public ov97_0221F14C
	.public ov97_0221F1D8
	.public ov97_0221F294
	.public ov97_0221F428
	.public ov97_0221F56C
	.public ov97_0221F5F8
	.public ov97_0221F74C
	.public ov97_0221F7DC
	.public ov97_0221F9E0
	.public ov97_0221FAEC
	.public ov97_0221FBDC
	.public ov97_0221FCA8
	.public ov97_0221FCB8
	.public ov97_0221FCCC
	.public ov97_0221FCF4
	.public ov97_0221FCFC
	.public ov97_0221FD04
	.public ov97_0221FD20
	.public ov97_0221FD3C
	.public ov97_0221FD58
	.public ov97_0221E5C0
	.public ov97_0221E69C
	.public ov97_0221E6DC
	.public ov97_0221E7F4
	.public ov97_0221E814
	.public ov97_0221E834
	.public ov97_0221E864
	.public ov97_0221E88C
	.public ov97_0221E97C
	.public ov97_0221EBD8
	.public ov97_0221EE84
	.public ov97_0221F010
	.public ov97_0221FB80
	.public ov97_0221FBA0
	.public ov97_0221FC54

	thumb_func_start ov97_0221E98C
ov97_0221E98C: ; 0x0221E98C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	add r5, r0, #0
	ldr r0, [r5, #0x28]
	add r7, r1, #0
	str r0, [r7, #4]
	ldr r0, [r5, #0x28]
	cmp r0, #0
	bne _0221EA84
	mov r0, #0
	str r0, [sp, #8]
	add r0, r7, #0
	str r0, [sp, #4]
	add r0, #0x1e
	str r0, [sp, #4]
	add r0, r7, #0
	str r0, [sp]
	add r0, #0x14
	add r4, r7, #0
	str r0, [sp]
_0221E9B4:
	ldr r6, [r5, #0x10]
	ldr r0, [r7]
	cmp r6, #0x12
	bne _0221EA20
	ldr r0, [r0]
	bl SaveArray_Party_Get
	ldr r1, [r5, #0x14]
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	mov r1, #0
	strh r0, [r4, #0xc]
	add r0, r6, #0
	add r2, r1, #0
	bl GetMonData
	str r0, [r4, #0x10]
	add r0, r6, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0xe]
	ldr r2, [sp, #4]
	add r0, r6, #0
	mov r1, #0x75
	bl GetMonData
	add r0, r6, #0
	bl MonIsShiny
	strb r0, [r4, #0x1c]
	add r0, r6, #0
	mov r1, #0x6f
	mov r2, #0
	bl GetMonData
	strb r0, [r4, #0x1d]
	ldr r0, [r7]
	ldr r0, [r0]
	bl SaveArray_Party_Get
	ldr r1, [r5, #0x14]
	ldr r2, [sp]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov97_0221EA88
	b _0221EA6A
_0221EA20:
	ldr r0, [r0]
	bl SaveArray_PCStorage_Get
	ldr r2, [r5, #0x14]
	add r1, r6, #0
	add r3, sp, #0xc
	bl ov97_0221E898
	ldr r0, [sp, #0xc]
	add r1, sp, #0x24
	strh r0, [r4, #0xc]
	ldr r0, [sp, #0x10]
	mov r2, #0xb
	str r0, [r4, #0x10]
	add r0, sp, #0xc
	ldrh r0, [r0, #0xa]
	strh r0, [r4, #0xe]
	ldr r0, [sp, #4]
	bl CopyU16StringArrayN
	add r0, sp, #0xc
	ldrh r0, [r0, #0x10]
	strb r0, [r4, #0x1c]
	add r0, sp, #0xc
	ldrh r0, [r0, #0x12]
	strb r0, [r4, #0x1d]
	ldr r0, [r7]
	ldr r0, [r0]
	bl SaveArray_PCStorage_Get
	ldr r1, [r5, #0x10]
	ldr r2, [r5, #0x14]
	bl PCStorage_GetMonByIndexPair
	ldr r1, [sp]
	bl ov97_0221EB38
_0221EA6A:
	ldr r0, [sp, #4]
	add r5, #8
	add r0, #0x28
	str r0, [sp, #4]
	ldr r0, [sp]
	add r4, #0x28
	add r0, #0x28
	str r0, [sp]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #3
	blt _0221E9B4
_0221EA84:
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov97_0221E98C


	thumb_func_start ov97_0221EA88
ov97_0221EA88: ; 0x0221EA88
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r1, #0
	add r4, r2, #0
	add r6, r0, #0
	add r1, sp, #8
	add r2, r5, #0
	bl Party_GetMonAprijuiceModifiers
	add r0, r6, #0
	add r1, r5, #0
	bl Party_GetMonByIndex
	add r1, r0, #0
	add r0, sp, #0
	add r2, sp, #8
	mov r3, #0x5c
	bl CalcMonPokeathlonStars
	add r1, sp, #0
	ldrh r0, [r1]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1d
	strb r0, [r4]
	ldrh r0, [r1]
	lsl r0, r0, #0x11
	lsr r0, r0, #0x1d
	strb r0, [r4, #1]
	ldrh r0, [r1]
	lsl r0, r0, #0x14
	lsr r0, r0, #0x1d
	strb r0, [r4, #2]
	ldrh r0, [r1]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1d
	strb r0, [r4, #3]
	ldrh r0, [r1]
	lsl r0, r0, #0x17
	lsr r0, r0, #0x1d
	strb r0, [r4, #4]
	ldrh r3, [r4, #6]
	mov r0, #7
	ldrb r2, [r1, #2]
	bic r3, r0
	mov r0, #7
	and r0, r2
	orr r0, r3
	strh r0, [r4, #6]
	ldrh r2, [r4, #6]
	mov r0, #0x38
	bic r2, r0
	ldrb r0, [r1, #6]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1a
	orr r0, r2
	strh r0, [r4, #6]
	ldrh r2, [r4, #6]
	ldr r0, _0221EB2C ; =0xFFFFFE3F
	and r2, r0
	ldrb r0, [r1, #5]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x17
	orr r0, r2
	strh r0, [r4, #6]
	ldrh r2, [r4, #6]
	ldr r0, _0221EB30 ; =0xFFFFF1FF
	and r2, r0
	ldrb r0, [r1, #3]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x14
	orr r0, r2
	strh r0, [r4, #6]
	ldrh r2, [r4, #6]
	ldr r0, _0221EB34 ; =0xFFFF8FFF
	and r2, r0
	ldrb r0, [r1, #4]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x11
	orr r0, r2
	strh r0, [r4, #6]
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0221EB2C: .word 0xFFFFFE3F
_0221EB30: .word 0xFFFFF1FF
_0221EB34: .word 0xFFFF8FFF
	thumb_func_end ov97_0221EA88


	thumb_func_start ov97_0221EB38
ov97_0221EB38: ; 0x0221EB38
	push {r4, lr}
	sub sp, #8
	add r2, r0, #0
	add r4, r1, #0
	add r1, r2, #0
	add r0, sp, #0
	mov r2, #0
	mov r3, #0x5c
	bl CalcBoxmonPokeathlonStars
	add r1, sp, #0
	ldrh r0, [r1]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1d
	strb r0, [r4]
	ldrh r0, [r1]
	lsl r0, r0, #0x11
	lsr r0, r0, #0x1d
	strb r0, [r4, #1]
	ldrh r0, [r1]
	lsl r0, r0, #0x14
	lsr r0, r0, #0x1d
	strb r0, [r4, #2]
	ldrh r0, [r1]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1d
	strb r0, [r4, #3]
	ldrh r0, [r1]
	lsl r0, r0, #0x17
	lsr r0, r0, #0x1d
	strb r0, [r4, #4]
	ldrh r3, [r4, #6]
	mov r0, #7
	ldrb r2, [r1, #2]
	bic r3, r0
	mov r0, #7
	and r0, r2
	orr r0, r3
	strh r0, [r4, #6]
	ldrh r2, [r4, #6]
	mov r0, #0x38
	bic r2, r0
	ldrb r0, [r1, #6]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1a
	orr r0, r2
	strh r0, [r4, #6]
	ldrh r2, [r4, #6]
	ldr r0, _0221EBCC ; =0xFFFFFE3F
	and r2, r0
	ldrb r0, [r1, #5]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x17
	orr r0, r2
	strh r0, [r4, #6]
	ldrh r2, [r4, #6]
	ldr r0, _0221EBD0 ; =0xFFFFF1FF
	and r2, r0
	ldrb r0, [r1, #3]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x14
	orr r0, r2
	strh r0, [r4, #6]
	ldrh r2, [r4, #6]
	ldr r0, _0221EBD4 ; =0xFFFF8FFF
	and r2, r0
	ldrb r0, [r1, #4]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x11
	orr r0, r2
	strh r0, [r4, #6]
	add sp, #8
	pop {r4, pc}
	nop
_0221EBCC: .word 0xFFFFFE3F
_0221EBD0: .word 0xFFFFF1FF
_0221EBD4: .word 0xFFFF8FFF
	thumb_func_end ov97_0221EB38

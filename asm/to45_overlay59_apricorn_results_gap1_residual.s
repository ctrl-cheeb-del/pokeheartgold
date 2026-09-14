	.include "asm/macros.inc"
	.public Sprite_SetDrawFlag
	.public Sprite_SetAnimCtrlSeq
	.public ov59_0223BE44
	.text

	thumb_func_start ov59_0223BD4C
ov59_0223BD4C: ; 0x0223BD4C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r1, [sp]
	add r7, r2, #0
	add r1, #0x10
	add r6, r0, #0
	add r0, r1, r7
	str r0, [sp, #4]
	ldrsb r0, [r1, r7]
	cmp r0, #0
	bne _0223BD76
	add r0, r7, #3
	lsl r0, r0, #2
	add r1, r6, r0
	mov r0, #0x26
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _0223BDA2
_0223BD76:
	mov r0, #0x26
	lsl r0, r0, #4
	add r4, r6, r0
	add r0, r7, #3
	lsl r5, r0, #2
	ldr r0, [r4, r5]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [sp, #4]
	mov r1, #0
	ldrsb r0, [r0, r1]
	cmp r0, #0
	ldr r0, [r4, r5]
	ble _0223BD9C
	mov r1, #8
	bl Sprite_SetAnimCtrlSeq
	b _0223BDA2
_0223BD9C:
	mov r1, #9
	bl Sprite_SetAnimCtrlSeq
_0223BDA2:
	lsl r0, r7, #2
	str r0, [sp, #0x10]
	add r5, r7, r0
	ldr r0, [sp]
	mov r4, #0
	str r0, [sp, #0xc]
	add r0, #0x1e
	str r0, [sp, #0xc]
	ldr r0, [sp]
	ldrh r1, [r0, #0x16]
	lsl r0, r7, #1
	add r0, r7, r0
	asr r1, r0
	mov r0, #7
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	ldr r0, [sp]
	add r7, r0, r7
_0223BDCA:
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldrh r0, [r1, r0]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1d
	cmp r4, r0
	ble _0223BDE6
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #0xff
	mov r3, #0
	bl ov59_0223BE44
	b _0223BE0C
_0223BDE6:
	ldr r0, [sp, #8]
	cmp r4, r0
	ble _0223BDFA
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #7
	mov r3, #1
	bl ov59_0223BE44
	b _0223BE0C
_0223BDFA:
	ldrb r2, [r7, #0x18]
	add r0, r6, #0
	add r1, r5, #0
	add r2, r2, #4
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	mov r3, #1
	bl ov59_0223BE44
_0223BE0C:
	add r4, r4, #1
	add r5, r5, #1
	cmp r4, #5
	blt _0223BDCA
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov59_0223BD4C

	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020371C4
sub_020371C4: ; 0x020371C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	str r1, [sp, #4]
	str r2, [sp, #8]
	add r4, r3, #0
	bl sub_02033BC4
	cmp r0, #0
	beq _020372D4
_020371D8:
	ldrb r7, [r4, #0xa]
	cmp r7, #0xee
	bne _020371EA
	add r0, r5, #0
	bl sub_02033B68
	add r7, r0, #0
	cmp r7, #0xee
	beq _020372CA
_020371EA:
	mov r0, #4
	ldrsh r0, [r5, r0]
	strb r7, [r4, #0xa]
	ldrh r6, [r4, #8]
	str r0, [sp, #0x10]
	ldr r0, _020372D8 ; =0x0000FFFF
	cmp r6, r0
	bne _0203723E
	add r0, r7, #0
	bl sub_020341DC
	add r6, r0, #0
	ldr r0, _020372DC ; =_021D4140
	ldr r1, [r0, #8]
	ldr r0, _020372E0 ; =0x000006B8
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _020372D4
	ldr r0, _020372D8 ; =0x0000FFFF
	cmp r6, r0
	bne _0203723C
	add r0, r5, #0
	bl sub_02033BC4
	cmp r0, #1
	bge _02037226
	ldr r0, [sp, #0x10]
	add sp, #0x14
	strh r0, [r5, #4]
	pop {r4, r5, r6, r7, pc}
_02037226:
	add r0, r5, #0
	bl sub_02033B68
	lsl r6, r0, #8
	add r0, r5, #0
	bl sub_02033B68
	add r6, r6, r0
	mov r0, #4
	ldrsh r0, [r5, r0]
	str r0, [sp, #0x10]
_0203723C:
	strh r6, [r4, #8]
_0203723E:
	add r0, r7, #0
	bl sub_02034244
	cmp r0, #0
	beq _0203729A
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _0203725A
	ldrh r2, [r4, #8]
	ldr r1, [sp, #4]
	add r0, r7, #0
	bl sub_02034280
	str r0, [r4, #4]
_0203725A:
	ldr r2, [r4]
	ldr r1, [sp, #8]
	add r0, r5, #0
	sub r2, r6, r2
	bl sub_02033B4C
	ldr r2, [r4, #4]
	str r0, [sp, #0xc]
	cmp r2, #0
	beq _0203727A
	ldr r1, [r4]
	ldr r0, [sp, #8]
	add r1, r2, r1
	ldr r2, [sp, #0xc]
	bl MI_CpuCopy8
_0203727A:
	ldr r1, [r4]
	ldr r0, [sp, #0xc]
	add r0, r1, r0
	str r0, [r4]
	cmp r0, r6
	blt _020372CA
	str r4, [sp]
	ldr r0, [sp, #4]
	ldr r3, [r4, #4]
	add r1, r7, #0
	add r2, r6, #0
	bl sub_020371A8
	cmp r7, #0x11
	beq _020372D4
	b _020372CA
_0203729A:
	add r0, r5, #0
	bl sub_02033BC4
	cmp r0, r6
	blt _020372C2
	ldr r1, [sp, #8]
	add r0, r5, #0
	add r2, r6, #0
	bl sub_02033B4C
	ldr r0, [sp, #4]
	ldr r3, [sp, #8]
	add r1, r7, #0
	add r2, r6, #0
	str r4, [sp]
	bl sub_020371A8
	cmp r7, #0x11
	beq _020372D4
	b _020372CA
_020372C2:
	ldr r0, [sp, #0x10]
	add sp, #0x14
	strh r0, [r5, #4]
	pop {r4, r5, r6, r7, pc}
_020372CA:
	add r0, r5, #0
	bl sub_02033BC4
	cmp r0, #0
	bne _020371D8
_020372D4:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_020372D8: .word 0x0000FFFF
_020372DC: .word _021D4140
_020372E0: .word 0x000006B8
	thumb_func_end sub_020371C4

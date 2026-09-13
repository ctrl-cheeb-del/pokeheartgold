	.include "asm/macros.inc"
	.include "overlay_49.inc"
	.include "global.inc"

	.text
	.public ov49_02266F14
	.extern ov49_02259154
	.extern ov49_0226540C
	.extern ov49_022655F4
	.extern ov49_0226786C
	.extern ov49_0226A450
	.extern ov49_02259154

	thumb_func_start ov49_02266F14
ov49_02266F14: ; 0x02266F14
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	add r5, r1, #0
	str r0, [sp, #0x10]
	ldr r0, [r5, #8]
	add r1, sp, #0x24
	bl ov49_02259154
	ldr r0, _0226705C ; =0x00000955
	ldrsb r0, [r5, r0]
	sub r1, r0, #1
	ldr r0, _02267060 ; =ov49_0226A450
	ldrb r0, [r0, r1]
	cmp r0, #0
	beq _02266F44
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _02266F52
_02266F44:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_02266F52:
	ldr r6, [sp, #0x28]
	ldr r4, [sp, #0x2c]
	ldr r7, [sp, #0x24]
	bl _ffix
	sub r0, r6, r0
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	mov r0, #0xa
	str r0, [sp, #0xc]
	ldr r0, _02267064 ; =0x00000A04
	add r1, r7, #0
	add r0, r5, r0
	add r2, r7, #0
	add r3, r6, #0
	bl ov49_0226540C
	ldr r1, _02267068 ; =0x00000956
	mov r4, #0
	strh r4, [r5, r1]
	sub r0, r1, #2
	strb r4, [r5, r0]
	sub r0, r1, #1
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _02267052
	add r0, r5, #0
	str r0, [sp, #0x14]
	add r0, #0xc
	str r0, [sp, #0x14]
	add r0, r1, #0
	add r0, #0x36
	add r1, #0x12
	add r7, r5, r0
	add r6, r5, r1
_02266F9A:
	ldr r0, [sp, #0x14]
	add r1, sp, #0x24
	add r2, sp, #0x28
	add r3, sp, #0x2c
	bl sub_020182B0
	mov r0, #0x96
	add r1, r5, r4
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	cmp r0, #0
	beq _02266FBC
	cmp r0, #1
	beq _02266FD6
	cmp r0, #2
	beq _02266FF0
	b _02267008
_02266FBC:
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x28]
	str r0, [sp, #0x20]
	mov r0, #1
	lsl r0, r0, #0x12
	add r0, r1, r0
	str r0, [sp, #0x1c]
	mov r0, #1
	ldr r1, [sp, #0x2c]
	lsl r0, r0, #0x12
	sub r0, r1, r0
	str r0, [sp, #0x18]
	b _02267008
_02266FD6:
	mov r0, #1
	ldr r1, [sp, #0x24]
	lsl r0, r0, #0x12
	add r0, r1, r0
	str r0, [sp, #0x20]
	mov r0, #1
	ldr r1, [sp, #0x28]
	lsl r0, r0, #0x12
	add r0, r1, r0
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x18]
	b _02267008
_02266FF0:
	mov r0, #1
	ldr r1, [sp, #0x24]
	lsl r0, r0, #0x12
	sub r0, r1, r0
	str r0, [sp, #0x20]
	mov r0, #1
	ldr r1, [sp, #0x28]
	lsl r0, r0, #0x12
	add r0, r1, r0
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x18]
_02267008:
	ldr r0, [sp, #0x1c]
	ldr r2, [sp, #0x20]
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	str r0, [sp, #8]
	mov r0, #0x1a
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x24]
	ldr r3, [sp, #0x28]
	add r0, r7, #0
	bl ov49_0226540C
	mov r3, #6
	ldr r2, _0226706C ; =0x00000AAA
	add r0, r6, #0
	mov r1, #0
	lsl r3, r3, #0xc
	bl ov49_022655F4
	ldr r0, [sp, #0x10]
	add r1, r5, #0
	add r2, r4, #0
	mov r3, #3
	bl ov49_0226786C
	ldr r0, [sp, #0x14]
	add r4, r4, #1
	add r0, #0x78
	str r0, [sp, #0x14]
	ldr r0, _0226705C ; =0x00000955
	add r7, #0x28
	ldrsb r0, [r5, r0]
	add r6, #0xc
	cmp r4, r0
	blt _02266F9A
_02267052:
	ldr r0, _02267070 ; =0x00000964
	mov r1, #0
	strb r1, [r5, r0]
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0226705C: .word 0x00000955
_02267060: .word ov49_0226A450
_02267064: .word 0x00000A04
_02267068: .word 0x00000956
_0226706C: .word 0x00000AAA
_02267070: .word 0x00000964
	thumb_func_end ov49_02266F14

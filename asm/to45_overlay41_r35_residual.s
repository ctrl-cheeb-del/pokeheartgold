	.include "asm/macros.inc"
	.include "overlay_41.inc"
	.include "global.inc"

	.text
	.extern ov41_02249DB4
	.public ov41_022488D8

	thumb_func_start ov41_022488D8
ov41_022488D8:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	add r5, r0, #0
	ldr r0, [r5, #0x54]
	add r4, r1, #0
	str r0, [sp, #8]
	mov r0, #0x1a
	lsl r1, r4, #1
	str r0, [sp, #0xc]
	add r0, r1, #0
	add r0, #0x81
	str r0, [sp, #0x10]
	mov r0, #0x85
	str r0, [sp, #0x14]
	mov r0, #8
	add r1, #0x82
	str r0, [sp, #0x1c]
	mov r0, #0x81
	str r1, [sp, #0x18]
	str r0, [sp, #0x20]
	mov r0, #3
	mov r1, #2
	str r0, [sp, #0x24]
	mov r0, #1
	str r1, [sp, #0x2c]
	mov r7, #0
	mov r1, #0xe
	str r0, [sp, #0x28]
	str r7, [sp, #0x30]
	str r1, [sp, #0x34]
	tst r0, r2
	beq _0224891A
	mov r7, #0x70
_0224891A:
	mov r0, #2
	tst r0, r2
	beq _02248924
	mov r6, #0x81
	b _02248926
_02248924:
	mov r6, #0
_02248926:
	ldr r0, [sp, #0x50]
	str r3, [sp]
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0x5c
	add r1, sp, #8
	add r2, r7, #0
	add r3, r6, #0
	bl ov41_02249DB4
	str r4, [r5, #0x40]
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov41_022488D8

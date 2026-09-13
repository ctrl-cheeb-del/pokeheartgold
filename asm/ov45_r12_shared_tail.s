#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222AC14
	.public ov45_0222AC58
	.public ov45_0222EC90
	.public ov45_0222EEF0

	thumb_func_start ov45_0222AC14
ov45_0222AC14:
	push {r4, r5, lr}
	sub sp, #0x14
	add r4, r1, #0
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	str r0, [r1, #0xc]
	add r5, r2, #0
	str r0, [r1, #0x10]
	cmp r4, #6
	bhi _0222ACB4
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222AC3A:
	.short _0222AC48 - _0222AC3A - 2
	.short _0222AC48 - _0222AC3A - 2
	.short _0222AC48 - _0222AC3A - 2
	.short _0222AC4C - _0222AC3A - 2
	.short _0222AC4C - _0222AC3A - 2
	.short _0222AC50 - _0222AC3A - 2
	.short _0222AC54 - _0222AC3A - 2
_0222AC48:
	mov r1, #2
	b _0222AC5C
_0222AC4C:
	mov r1, #3
	b _0222AC5C
_0222AC50:
	mov r1, #4
	b _0222AC5C
_0222AC54:
	mov r1, #5
	b _0222AC5C
	thumb_func_end ov45_0222AC14

	thumb_func_start ov45_0222AC58
ov45_0222AC58:
	add sp, #0x14
	pop {r4, r5, pc}
_0222AC5C:
	add r0, sp, #0
	strb r1, [r0, #0x11]
	add r0, r3, #0
	bl ov45_0222EC90
	str r0, [sp]
	ldr r0, [sp, #0x20]
	bl ov45_0222EC90
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	bl ov45_0222EC90
	str r0, [sp, #8]
	ldr r0, [sp, #0x28]
	bl ov45_0222EC90
	str r0, [sp, #0xc]
	add r0, sp, #0
	strb r5, [r0, #0x10]
	ldrb r1, [r0, #0x13]
	mov r2, #0x7f
	bic r1, r2
	lsl r2, r4, #0x18
	lsr r3, r2, #0x18
	mov r2, #0x7f
	and r2, r3
	orr r1, r2
	strb r1, [r0, #0x13]
	ldrb r1, [r0, #0x13]
	mov r2, #0x80
	bic r1, r2
	ldr r2, [sp, #0x2c]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	lsl r2, r2, #0x1f
	lsr r2, r2, #0x18
	orr r1, r2
	strb r1, [r0, #0x13]
	mov r0, #4
	add r1, sp, #0
	mov r2, #0x14
	bl ov45_0222EEF0
_0222ACB4:
	add sp, #0x14
	pop {r4, r5, pc}
	thumb_func_end ov45_0222AC58

#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222C408
	.public ov45_0222C5B4
	.public ov45_0222C4E4
	.public ov45_0222C61C
	.public ov45_0222C4B4

thumb_func_start ov45_0222C408
ov45_0222C408: ; 0x0222C408
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	str r1, [sp]
	add r7, r2, #0
	bl ov45_0222C5B4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _0222C476
	mov r5, #0
	str r5, [sp, #4]
_0222C422:
	ldr r1, [sp, #4]
	add r0, r6, #0
	bl ov45_0222C4E4
	cmp r0, #2
	beq _0222C46A
	mov r4, #0
_0222C430:
	add r0, r6, #0
	add r1, r4, r5
	add r2, r7, #0
	bl ov45_0222C61C
	cmp r0, #0
	bne _0222C464
	add r0, r6, #0
	add r1, r4, r5
	bl ov45_0222C4B4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _0222C464
	ldr r0, [sp, #4]
	mov r1, #0xc
	mul r1, r0
	add r1, r6, r1
	lsl r0, r4, #2
	add r1, r1, r0
	ldr r0, [sp]
	add sp, #8
	str r0, [r1, #0x50]
	add r0, r4, r5
	pop {r3, r4, r5, r6, r7, pc}
_0222C464:
	add r4, r4, #1
	cmp r4, #3
	blt _0222C430
_0222C46A:
	ldr r0, [sp, #4]
	add r5, r5, #3
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #9
	blt _0222C422
_0222C476:
	mov r0, #0
	mvn r0, r0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C408

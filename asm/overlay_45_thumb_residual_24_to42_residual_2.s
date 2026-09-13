#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222C514
	.public ov45_0222C5B4

thumb_func_start ov45_0222C514
ov45_0222C514: ; 0x0222C514
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl ov45_0222C5B4
	mov r1, #0
	add r6, r0, #0
	mvn r1, r1
	cmp r6, r1
	beq _0222C548
	mov r1, #3
	bl _u32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _u32_div_f
	mov r2, #0xc
	mul r2, r4
	add r2, r5, r2
	lsl r1, r1, #2
	add r2, r2, r1
	mov r1, #0x4a
	mov r0, #1
	lsl r1, r1, #2
	str r0, [r2, r1]
_0222C548:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov45_0222C514

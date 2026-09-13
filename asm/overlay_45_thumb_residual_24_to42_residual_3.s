#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222C5B4

thumb_func_start ov45_0222C5B4
ov45_0222C5B4: ; 0x0222C5B4
	push {r3, r4, r5, r6}
	mov r4, #0
	add r3, r4, #0
_0222C5BA:
	add r5, r3, #0
	add r6, r0, #0
_0222C5BE:
	ldr r2, [r6, #0x50]
	cmp r1, r2
	bne _0222C5CE
	lsl r0, r4, #1
	add r0, r4, r0
	add r0, r5, r0
	pop {r3, r4, r5, r6}
	bx lr
_0222C5CE:
	add r5, r5, #1
	add r6, r6, #4
	cmp r5, #3
	blt _0222C5BE
	add r4, r4, #1
	add r0, #0xc
	cmp r4, #9
	blt _0222C5BA
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6}
	bx lr
	.balign 4, 0
	thumb_func_end ov45_0222C5B4

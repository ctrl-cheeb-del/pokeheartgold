	.include "asm/macros.inc"
	.include "overlay_80_022384D8.inc"
	.include "global.inc"
	.public ov80_0223857C


    .text
	.public ov80_022384D8
	.public ov80_022384FC
	.public ov80_02238530
	.public ov80_022385B0
	.public ov80_022385C4
	.public ov80_022385D8
	.public ov80_02238610

	thumb_func_start ov80_0223857C
ov80_0223857C: ; 0x0223857C
	push {r4, r5, r6, r7}
	cmp r1, #0
	bne _02238586
	mov r6, #0xc
	b _02238588
_02238586:
	mov r6, #0xe
_02238588:
	mov r1, #0
	mov r3, #0x60
	add r4, r1, #0
_0223858E:
	lsl r5, r4, #1
	mov r2, #0
	add r5, r0, r5
_02238594:
	add r7, r6, r2
	add r7, r3, r7
	strh r7, [r5]
	add r2, r2, #1
	add r5, r5, #2
	cmp r2, #2
	blo _02238594
	add r1, r1, #1
	add r3, #0x10
	add r4, r4, #2
	cmp r1, #2
	blo _0223858E
	pop {r4, r5, r6, r7}
	bx lr
	thumb_func_end ov80_0223857C

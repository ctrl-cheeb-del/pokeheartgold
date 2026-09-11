	.include "asm/macros.inc"
	.public _02237A86
	.public _02237A8E
	.public _02237A94
	.public _02237A9C
	.public _02237AAA
	.public _02237AB6
	.public _02237AC4
	.public _02237AC8
	.public _02237ACC
	.public _02237AD0
	.public _02237AD4
	.public _02237AD8
	.public _02237AEC
	.public _02237B04
	.public _02237B12
	.public _02237B1A
	.public _02237B36
	.public _02237B3E
	.public _02237B42
	.public _02237B4A
	.public _02237B4E
	.public _02237B6A
	.public _02237B72
	.public _02237B76
	.public _02237B7E
	.public _02237B82
	.public _02237BF0
	.public _02237BF2
	.public _02237C04
	.public _02237C2A
	.public _02237C70
	.public _02237C90
	.public _02237CB0
	.public _02237CC0
	.public _02237D28
	.public _02237D4E
	.public _02237D54
	.public _02237D6C
	.public _02237D74
	.public _02237D78
	.public _02237D7C
	.public _02237D80
	.public _02237D84
	.public _02237D94
	.public _02237D98
	.public _02237DAC
	.public _02237DDE
	.public _02237DEC
	.public _02237DF2
	.public _02237E5A
	.public _02237E7E
	.public _02237EA8
	.public _02237EC0
	.public _02237ECA
	.public _02237ECE
	.public _02237ED0
	.public _02237ED4
	.public _02237EF4
	.public _02237EF8
	.public _02237F4E
	.public _02237F6A
	.public _02237F74
	.public _02237F84
	.public _02237FA2
	.public _0223800E
	.public _02238030
	.public ov80_02237A70
	.public ov80_02237ADC
	.public ov80_02237B24
	.public ov80_02237B58
	.public ov80_02237B8C
	.public ov80_02237D5C
	.public ov80_02237D88
	.public ov80_02237D8C
	.public ov80_02237D9C
	.public ov80_02237DF4
	.public ov80_02237E18
	.public ov80_02237E30
	.public ov80_02237E88
	.public ov80_02237ED8
	.public ov80_02237EFC
	.public ov80_02237F3C
	.public ov80_02237F9C
	.public ov80_02237FA4
	.public ov80_0223D4D4
	.public ov80_0223D4D6
	.public ov80_0223D4D8
	.public ov80_0223D4DA
	.include "overlay_80_02237A70.inc"
	.include "global.inc"

    .text
	.public ov80_02237A70
	.public ov80_02237B24
	.public ov80_02237B58
	.public ov80_02237D5C
	.public ov80_02237D88
	.public ov80_02237D8C
	.public ov80_02237D9C
	.public ov80_02237DF4
	.public ov80_02237E18
	.public ov80_02237E30
	.public ov80_02237E88
	.public ov80_02237ED8
	.public ov80_02237EFC
	.public ov80_02237F9C
	.public ov80_02237FA4

	thumb_func_start ov80_02237F3C
ov80_02237F3C: ; 0x02237F3C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	add r0, r1, #0
	bl ov80_02237F9C
	mov r3, #0
	add r4, sp, #4
	mov r1, #4
_02237F4E:
	strb r3, [r4]
	sub r2, r1, r3
	strb r2, [r4, #5]
	add r3, r3, #1
	add r4, r4, #1
	cmp r3, #5
	blo _02237F4E
	mov r1, #0x60
	mov r7, #0
	mul r1, r0
	mov r5, #1
	add r1, #0x10
	add r2, r7, #0
	lsl r5, r5, #0xa
_02237F6A:
	ldr r4, [sp]
	lsl r6, r2, #1
	mov r0, #0
	add r3, sp, #4
	add r4, r4, r6
_02237F74:
	ldrb r6, [r3]
	add r6, r6, r1
	strh r6, [r4]
	cmp r0, #5
	blo _02237F84
	ldrh r6, [r4]
	orr r6, r5
	strh r6, [r4]
_02237F84:
	add r0, r0, #1
	add r3, r3, #1
	add r4, r4, #2
	cmp r0, #0xa
	blo _02237F74
	add r7, r7, #1
	add r1, #0x20
	add r2, #0xa
	cmp r7, #3
	blo _02237F6A
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov80_02237F3C

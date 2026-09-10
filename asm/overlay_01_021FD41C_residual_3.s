	.include "asm/macros.inc"
	.include "overlay_01_021FD41C.inc"
	.include "global.inc"

	.text
	.public ov01_02208E90
	.public ov01_02208EA0
	.public ov01_02208EB4
	.public ov01_02208EC8
	.public ov01_02208EDC
	.public ov01_02208EF0
	.public ov01_02208F14
	.public ov01_02208F38
	.public ov01_021FD41C
	.public ov01_021FD440
	.public ov01_021FD458
	.public ov01_021FD47C
	.public ov01_021FD488
	.public ov01_021FD498
	.public ov01_021FD4A4
	.public ov01_021FD4D0
	.public ov01_021FD4F4
	.public ov01_021FD5CC
	.public ov01_021FD60C
	.public ov01_021FD624
	.public ov01_021FD640
	.public ov01_021FD684
	.public ov01_021FD6C8
	.public ov01_021FD714
	.public ov01_021FD718
	.public ov01_021FD784
	.public ov01_021FD7D4
	.public ov01_021FD838
	.public ov01_021FD8E8
	.public ov01_021FD92C
	.public ov01_021FD980
	.public ov01_021FD9CC

	.public ov01_021FD41C
	.public ov01_021FD440
	.public ov01_021FD47C
	.public ov01_021FD488
	.public ov01_021FD498
	.public ov01_021FD4A4
	.public ov01_021FD4D0
	.public ov01_021FD4F4
	.public ov01_021FD5CC
	.public ov01_021FD60C
	.public ov01_021FD624
	.public ov01_021FD640
	.public ov01_021FD684
	.public ov01_021FD6C8
	.public ov01_021FD714
	.public ov01_021FD718
	.public ov01_021FD784
	.public ov01_021FD7D4
	.public ov01_021FD8E8
	.public ov01_021FD92C
	.public ov01_021FD9CC

	thumb_func_start ov01_021FD980
ov01_021FD980: ; 0x021FD980
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r4, r1, #0
	ldr r1, [r4, #0xc]
	add r6, r0, #0
	cmp r1, #1
	beq _021FD9C6
	bl sub_02068D90
	ldr r5, [r4, #0x18]
	add r4, r0, #0
	mov r1, #0x54
	mul r4, r1
	add r0, r6, #0
	add r1, sp, #0
	add r5, #0x78
	bl sub_02068DB8
	mov r0, #2
	ldr r1, [sp]
	lsl r0, r0, #0xa
	sub r1, r1, r0
	str r1, [sp]
	lsl r1, r0, #3
	ldr r2, [sp, #4]
	lsl r0, r0, #1
	sub r1, r2, r1
	str r1, [sp, #4]
	ldr r1, [sp, #8]
	add r0, r1, r0
	str r0, [sp, #8]
	add r0, r5, r4
	add r1, sp, #0
	bl sub_020699BC
_021FD9C6:
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov01_021FD980

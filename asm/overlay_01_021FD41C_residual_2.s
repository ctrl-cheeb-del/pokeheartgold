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

	thumb_func_start ov01_021FD838
ov01_021FD838: ; 0x021FD838
	push {r4, r5, r6, lr}
	sub sp, #0x48
	add r2, r1, #0
	add r6, r0, #0
	ldr r0, [r2, #0xc]
	cmp r0, #0
	bne _021FD8E0
	ldr r5, _021FD8E4 ; =ov01_02208EF0
	add r4, sp, #0xc
	mov r3, #4
_021FD84C:
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	sub r3, r3, #1
	bne _021FD84C
	ldr r0, [r5]
	add r1, sp, #0x30
	str r0, [r4]
	ldr r0, [r2, #0x18]
	ldr r4, [r2, #0x1c]
	add r5, r0, #0
	add r5, #0x78
	bl ov01_021FD488
	add r0, r4, #0
	bl ov01_021F8F88
	cmp r0, #0
	add r1, sp, #0x3c
	beq _021FD8A0
	add r0, r6, #0
	bl sub_02068DB8
	mov r0, #2
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0xa
	sub r1, r1, r0
	str r1, [sp, #0x3c]
	lsl r1, r0, #3
	ldr r2, [sp, #0x40]
	lsl r0, r0, #1
	sub r1, r2, r1
	str r1, [sp, #0x40]
	ldr r1, [sp, #0x44]
	add r0, r1, r0
	str r0, [sp, #0x44]
	add r0, r4, #0
	bl MapObject_GetFacingDirection
	add r1, sp, #0x3c
	bl ov01_021FD9CC
	b _021FD8D4
_021FD8A0:
	add r0, r4, #0
	bl MapObject_CopyPositionVector
	add r0, r4, #0
	add r1, sp, #0
	bl ov01_021F8FA0
	ldr r1, [sp, #0x3c]
	ldr r0, [sp]
	ldr r3, [sp, #0x40]
	add r2, r1, r0
	ldr r1, [sp, #0x44]
	ldr r0, [sp, #8]
	str r2, [sp, #0x3c]
	add r0, r1, r0
	mov r1, #2
	lsl r1, r1, #0xa
	sub r2, r2, r1
	str r2, [sp, #0x3c]
	lsl r2, r1, #3
	sub r2, r3, r2
	lsl r1, r1, #1
	str r0, [sp, #0x44]
	add r0, r0, r1
	str r2, [sp, #0x40]
	str r0, [sp, #0x44]
_021FD8D4:
	add r0, r5, #0
	add r1, sp, #0x3c
	add r2, sp, #0x30
	add r3, sp, #0xc
	bl sub_020699AC
_021FD8E0:
	add sp, #0x48
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021FD8E4: .word ov01_02208EF0
	thumb_func_end ov01_021FD838

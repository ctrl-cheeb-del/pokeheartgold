	.include "asm/macros.inc"
	.include "overlay_01_021FEEEC.inc"
	.include "global.inc"

	.text
	.public ov01_021FEEEC
	.public ov01_021FEF08
	.public ov01_021FEF18
	.public ov01_021FEFF8
	.public ov01_021FF070
	.public ov01_021FF0E4
	.public ov01_021FF174
	.public ov01_021FF228
	.public ov01_021FF234
	.public ov01_021FF35C
	.public ov01_021FF394
	.public ov01_021FF418
	.public ov01_021FF424
	.public ov01_021FF44C
	.public ov01_02209138
	.public ov01_0220914C
	.public ov01_02209160
	.public ov01_02209178
	.public ov01_02209190
	.public ov01_022091A8

	.public ov01_021FEEEC
	.public ov01_021FEF08
	.public ov01_021FEF18
	.public ov01_021FEFF8
	.public ov01_021FF070
	.public ov01_021FF174
	.public ov01_021FF228
	.public ov01_021FF234
	.public ov01_021FF35C
	.public ov01_021FF418
	.public ov01_021FF424
	.public ov01_021FF44C

	thumb_func_start ov01_021FF0E4
ov01_021FF0E4: ; 0x021FF0E4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	add r5, r0, #0
	str r1, [sp, #8]
	add r4, r2, #0
	add r6, r3, #0
	bl ov01_021F146C
	add r7, r0, #0
	add r0, r5, #0
	str r4, [sp, #0xc]
	bl MapObject_GetYCoord
	str r0, [sp, #0x10]
	add r0, r5, #0
	str r6, [sp, #0x14]
	bl MapObject_GetXCoord
	sub r1, r0, r4
	add r0, sp, #0xc
	strh r1, [r0, #0x1c]
	add r0, r5, #0
	bl MapObject_GetZCoord
	sub r1, r0, r6
	add r0, sp, #0xc
	strh r1, [r0, #0x1e]
	ldr r0, [sp, #0x50]
	cmp r0, #0
	beq _021FF12C
	add r0, r5, #0
	bl MapObject_GetFacingDirection
	add r1, sp, #0x2c
	strb r0, [r1]
	b _021FF134
_021FF12C:
	mov r1, #0
	mvn r1, r1
	add r0, sp, #0x2c
	strb r1, [r0]
_021FF134:
	add r0, r7, #0
	str r7, [sp, #0x1c]
	bl ov01_021F1468
	str r0, [sp, #0x18]
	add r0, r7, #0
	mov r1, #8
	bl ov01_021F1450
	str r0, [sp, #0x20]
	add r0, r5, #0
	add r1, sp, #0x30
	str r5, [sp, #0x24]
	bl MapObject_CopyPositionVector
	add r0, r5, #0
	mov r1, #2
	bl MapObject_GetPriorityPlusValue
	add r1, sp, #0xc
	str r1, [sp]
	str r0, [sp, #4]
	ldr r1, _021FF170 ; =ov01_02209138
	ldr r3, [sp, #8]
	add r0, r7, #0
	add r2, sp, #0x30
	bl ov01_021F1620
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FF170: .word ov01_02209138
	thumb_func_end ov01_021FF0E4

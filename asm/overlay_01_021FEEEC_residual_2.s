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

	thumb_func_start ov01_021FF394
ov01_021FF394: ; 0x021FF394
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r4, r1, #0
	bl sub_02068D98
	add r3, r0, #0
	add r2, r4, #0
	ldmia r3!, {r0, r1}
	add r2, #0x10
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	add r0, r5, #0
	bl sub_02068D90
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x10]
	lsl r1, r0, #0x10
	mov r0, #2
	lsl r0, r0, #0xe
	add r0, r1, r0
	str r0, [sp]
	ldr r0, [r4, #0x14]
	lsl r1, r0, #0x10
	mov r0, #9
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r4, #0x18]
	add r1, sp, #0
	bl sub_0206121C
	mov r0, #1
	ldr r1, [sp, #4]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, sp, #0
	bl sub_02068DA8
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _021FF3FE
	cmp r0, #1
	beq _021FF402
	cmp r0, #2
	b _021FF406
_021FF3FE:
	mov r1, #5
	b _021FF408
_021FF402:
	mov r1, #6
	b _021FF408
_021FF406:
	mov r1, #7
_021FF408:
	ldr r0, [r4, #0x1c]
	add r2, sp, #0
	bl ov01_021F1740
	str r0, [r4, #0x24]
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end ov01_021FF394

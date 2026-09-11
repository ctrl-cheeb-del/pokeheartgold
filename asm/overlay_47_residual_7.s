	.include "asm/macros.inc"
	.include "overlay_47.inc"
	.include "global.inc"
	.include "overlay47_exact_bank.inc"

	.text
	.public ov47_02258A14
	.public ov47_02258A1C
	.public ov47_02258A60
	.public ov47_02258A80
	.public ov47_02258A8C
	.public ov47_02258B8C
	.public ov47_02258C44
	.public ov47_02258CC0
	.public ov47_02258CEC
	.public ov47_02258D18
	.public ov47_02258D44
	.public ov47_02258D78
	.public ov47_02258DA8
	.public ov47_02258DB4
	.public ov47_022591F8
	.public ov47_0225921C
	.public ov47_02259228
	.public ov47_02259278
	.public ov47_022592B4
	.public ov47_02259318
	.public ov47_02259384
	.public ov47_022593A0
	.public ov47_022593B4
	.public ov47_022593CC
	.public ov47_02259404
	.public ov47_02259430
	.public ov47_02259448
	.public ov47_0225945C
	.public ov47_0225946C
	.public ov47_02259968
	.public ov47_0225999C
	.public ov47_02259B30
	.public ov47_02259D24
	.public ov47_02259D40
	.public ov47_02259D58
	.public ov47_02259DA4
	.public ov47_02259DCC

	thumb_func_start ov47_022599F0
ov47_022599F0: ; 0x022599F0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r6, r0, #0
	str r1, [sp, #0x20]
	add r0, #0x10
	mov r1, #0
	str r2, [sp, #0x10]
	ldr r7, [sp, #0x38]
	ldr r4, [sp, #0x40]
	bl FillWindowPixelBuffer
	add r0, r6, #0
	add r0, #0x50
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x10]
	mov r2, #0
	bl ov47_02259D58
	mov r3, #0
	add r2, r0, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	add r0, r6, #0
	str r4, [sp, #8]
	add r0, #0x10
	mov r1, #1
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x10]
	mov r2, #1
	bl ov47_02259D58
	add r2, r0, #0
	mov r0, #0x18
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	add r0, r6, #0
	str r4, [sp, #8]
	mov r3, #0
	add r0, #0x10
	mov r1, #1
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x10]
	mov r2, #2
	bl ov47_02259D58
	add r2, r0, #0
	mov r0, #0x30
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	add r0, r6, #0
	str r4, [sp, #8]
	mov r3, #0
	add r0, #0x10
	mov r1, #1
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x20]
	ldr r1, [r7]
	ldr r0, [r0, #4]
	cmp r1, r0
	bne _02259B1C
	ldr r0, [r7, #4]
	cmp r0, #3
	bhs _02259B1C
	ldr r0, [sp, #0x48]
	cmp r0, #1
	bne _02259A96
	ldr r0, [sp, #0x44]
	str r0, [sp, #0x14]
	b _02259A98
_02259A96:
	str r4, [sp, #0x14]
_02259A98:
	ldr r0, [sp, #0x10]
	ldr r2, [sp, #0x3c]
	mov r1, #0
	bl ov47_02258D78
	ldr r0, [sp, #0x10]
	mov r1, #0
	mov r2, #0x6e
	bl ov47_02258CEC
	str r0, [sp, #0x18]
	ldr r1, [sp, #0x18]
	mov r0, #1
	mov r2, #0
	bl FontID_String_GetWidth
	str r0, [sp, #0x1c]
	mov r1, #0
	ldr r3, [sp, #0x1c]
	mov r5, #0x60
	sub r5, r5, r3
	lsr r3, r5, #0x1f
	add r3, r5, r3
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x14]
	ldr r2, [sp, #0x18]
	str r0, [sp, #8]
	add r0, r6, #0
	str r1, [sp, #0xc]
	add r0, #0x50
	mov r1, #1
	asr r3, r3, #1
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x10]
	ldr r2, [r7, #4]
	bl ov47_02259D58
	add r5, r0, #0
	mov r0, #1
	add r1, r5, #0
	mov r2, #0
	bl FontID_String_GetWidth
	mov r1, #0
	add r3, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r4, #0x68
	sub r4, r4, r3
	lsr r3, r4, #0x1f
	add r3, r4, r3
	add r0, r6, #0
	asr r3, r3, #1
	str r1, [sp, #0xc]
	add r0, #0x50
	mov r1, #1
	add r2, r5, #0
	add r3, #0x60
	bl AddTextPrinterParameterizedWithColor
_02259B1C:
	add r0, r6, #0
	add r0, #0x50
	bl ScheduleWindowCopyToVram
	add r6, #0x10
	add r0, r6, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov47_022599F0

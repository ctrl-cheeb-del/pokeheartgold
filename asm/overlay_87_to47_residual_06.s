	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.public ov87_021E6F38
	.public ov87_021E6F98

	.text

thumb_func_start ov87_021E6F38
ov87_021E6F38: ; 0x021E6F38
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	add r1, sp, #0x38
	ldrb r1, [r1]
	add r5, r0, #0
	add r0, r4, #0
	add r6, r2, #0
	add r7, r3, #0
	bl FillWindowPixelBuffer
	ldr r0, [r5, #0x38]
	ldr r2, [r5, #0x44]
	add r1, r6, #0
	bl ReadMsgDataIntoString
	ldr r0, [r5, #0x3c]
	ldr r1, [r5, #0x40]
	ldr r2, [r5, #0x44]
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x28]
	add r2, sp, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	add r3, r7, #0
	str r0, [sp, #4]
	add r0, sp, #0x38
	ldrb r1, [r0]
	ldrb r0, [r2, #0x18]
	ldrb r2, [r2, #0x1c]
	lsl r0, r0, #0x18
	lsl r2, r2, #0x18
	lsr r0, r0, #8
	lsr r2, r2, #0x10
	orr r0, r2
	orr r0, r1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r1, sp, #0x3c
	ldrb r1, [r1]
	ldr r2, [r5, #0x40]
	add r0, r4, #0
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov87_021E6F38

	thumb_func_start ov87_021E6F98
ov87_021E6F98: ; 0x021E6F98
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	add r1, sp, #0x38
	ldrb r1, [r1]
	add r5, r0, #0
	add r0, r4, #0
	add r7, r2, #0
	add r6, r3, #0
	bl FillWindowPixelBuffer
	ldr r0, [r5, #0x38]
	ldr r2, [r5, #0x44]
	add r1, r7, #0
	bl ReadMsgDataIntoString
	ldr r0, [r5, #0x3c]
	ldr r1, [r5, #0x40]
	ldr r2, [r5, #0x44]
	bl StringExpandPlaceholders
	add r0, sp, #0x3c
	ldrb r0, [r0]
	ldr r1, [r5, #0x40]
	mov r2, #0
	bl FontID_String_GetWidth
	add r0, r0, #1
	lsr r0, r0, #1
	sub r3, r6, r0
	ldr r0, [sp, #0x28]
	add r2, sp, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	add r0, sp, #0x38
	ldrb r1, [r0]
	ldrb r0, [r2, #0x18]
	ldrb r2, [r2, #0x1c]
	lsl r0, r0, #0x18
	lsl r2, r2, #0x18
	lsr r0, r0, #8
	lsr r2, r2, #0x10
	orr r0, r2
	orr r0, r1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r1, sp, #0x3c
	ldrb r1, [r1]
	ldr r2, [r5, #0x40]
	add r0, r4, #0
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov87_021E6F98

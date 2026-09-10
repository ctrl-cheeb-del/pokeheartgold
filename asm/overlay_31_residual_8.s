	.include "asm/macros.inc"
	.include "overlay_31.inc"
	.include "global.inc"

	.text
	.public _0225EE40
	.public _0225EF40
	.public ov31_0225D520
	.public ov31_0225D684
	.public ov31_0225D7A0
	.public ov31_0225D83C
	.public ov31_0225D9D4
	.public ov31_0225DAC4
	.public ov31_0225DB38
	.public ov31_0225DBD4
	.public ov31_0225DCA8
	.public ov31_0225DD14
	.public ov31_0225DE24
	.public ov31_0225DE84
	.public ov31_0225DF98
	.public ov31_0225E060
	.public ov31_0225E184
	.public ov31_0225E20C
	.public ov31_0225E2D4
	.public ov31_0225E54C
	.public ov31_0225E5FC
	.public ov31_0225E700
	.public ov31_0225E7D4
	.public ov31_0225EA08
	.public ov31_0225EA9C
	.public ov31_0225EB30
	.public ov31_0225EBC4
	.public ov31_0225EC58
	.public ov31_0225EE44
	.public ov31_0225EE60
	.public ov31_0225EE88
	.public ov31_0225EED0
	.public ov31_0225EEEC
	.public ov31_0225EF08
	.public ov31_0225EF48
	.public ov31_0225D60C
	.public ov31_0225D654
	.public ov31_0225D710
	.public ov31_0225D758
	.public ov31_0225D75C
	.public ov31_0225DAA4
	.public ov31_0225DBA0
	.public ov31_0225DCF4
	.public ov31_0225DE00
	.public ov31_0225E0E4
	.public ov31_0225E12C
	.public ov31_0225E474
	.public ov31_0225E4BC
	.public ov31_0225E4EC
	.public ov31_0225E51C
	.public ov31_0225E774
	.public ov31_0225E948
	.public ov31_0225E95C
	.public ov31_0225E9CC
	.public ov31_0225EDA0

	thumb_func_start ov31_0225E184
ov31_0225E184: ; 0x0225E184
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0x29
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r2, [r5, #0x14]
	add r0, r1, #0
	sub r0, #0x1f
	ldr r3, [r2, r1]
	ldrb r0, [r2, r0]
	sub r1, #0x28
	ldr r1, [r2, r1]
	add r6, r3, r0
	lsl r4, r6, #1
	mov r0, #0x57
	lsl r0, r0, #2
	ldrh r1, [r1, r4]
	ldr r0, [r5, r0]
	bl NewString_ReadMsgData
	add r7, r0, #0
	add r1, r5, #0
	add r0, r5, #0
	add r1, #0xe4
	add r2, r7, #0
	add r3, r6, #0
	bl ov31_0225DE00
	add r0, r7, #0
	bl String_Delete
	mov r2, #0x9a
	ldr r0, [r5, #0x14]
	lsl r2, r2, #2
	ldr r2, [r0, r2]
	add r1, r6, #0
	ldrh r2, [r2, r4]
	bl ov31_0225E12C
	cmp r0, #0
	beq _0225E1FE
	ldr r6, [r5, #0x14]
	mov r1, #0x9a
	lsl r1, r1, #2
	ldr r1, [r6, r1]
	add r0, r6, #0
	ldrh r1, [r1, r4]
	bl ov03_02258120
	add r3, r0, #0
	ldr r0, _0225E208 ; =0x00000283
	mov r1, #0x55
	ldrb r0, [r6, r0]
	add r2, r5, #0
	lsl r1, r1, #2
	str r0, [sp]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, #0xe4
	bl ov31_0225DE24
_0225E1FE:
	add r5, #0xe4
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225E208: .word 0x00000283
	thumb_func_end ov31_0225E184


	thumb_func_start ov31_0225E20C
ov31_0225E20C: ; 0x0225E20C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x23
	bl NewString_ReadMsgData
	add r4, r0, #0
	mov r0, #4
	str r0, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _0225E2D0 ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	add r2, #0x25
	add r0, r5, r2
	add r2, r4, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	mov r0, #5
	mov r1, #0xb
	bl String_New
	add r4, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x24
	bl NewString_ReadMsgData
	add r7, r0, #0
	mov r1, #0xa1
	ldr r0, [r5, #0x14]
	lsl r1, r1, #2
	ldrh r1, [r0, r1]
	bl ov03_02257978
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r4, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r6, r0, #0
	mov r0, #0x14
	str r0, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _0225E2D0 ; =0x00010200
	mov r3, #0x40
	add r2, #0x25
	str r0, [sp, #8]
	mov r1, #0
	add r0, r5, r2
	add r2, r4, #0
	sub r3, r3, r6
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add r0, r7, #0
	bl String_Delete
	mov r0, #0x49
	lsl r0, r0, #2
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225E2D0: .word 0x00010200
	thumb_func_end ov31_0225E20C


	thumb_func_start ov31_0225E2D4
ov31_0225E2D4: ; 0x0225E2D4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r4, r1, #0
	mov r0, #2
	mov r1, #0xb
	bl String_New
	add r6, r0, #0
	mov r0, #2
	mov r1, #0xb
	bl String_New
	add r7, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x2c
	bl NewString_ReadMsgData
	str r0, [sp, #0x10]
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x2d
	bl NewString_ReadMsgData
	str r0, [sp, #0x14]
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	mov r3, #1
	add r2, r0, #0
	str r3, [sp]
	mov r0, #0x55
	str r3, [sp, #4]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl BufferIntegerAsString
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r2, r1, #0
	mov r1, #1
	str r1, [sp]
	mov r0, #0x55
	str r1, [sp, #4]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r3, r1, #0
	bl BufferIntegerAsString
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, [sp, #0x10]
	add r1, r6, #0
	bl StringExpandPlaceholders
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, [sp, #0x14]
	add r1, r7, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	add r0, #0xf4
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x41
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #4
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225E470 ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0xf4
	add r2, r6, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	mov r0, #4
	str r0, [sp]
	mov r2, #0xff
	mov r1, #0
	ldr r0, _0225E470 ; =0x00010200
	str r2, [sp, #4]
	str r0, [sp, #8]
	add r0, r2, #5
	add r0, r5, r0
	add r2, r7, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	add r0, r7, #0
	bl String_Delete
	ldr r0, [sp, #0x10]
	bl String_Delete
	ldr r0, [sp, #0x14]
	bl String_Delete
	add r0, r5, #0
	add r0, #0xf4
	bl ScheduleWindowCopyToVram
	mov r0, #0x41
	lsl r0, r0, #2
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	mov r0, #0x4d
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #9
	mov r1, #0xb
	bl String_New
	add r6, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x26
	bl NewString_ReadMsgData
	add r7, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r2, #0xa3
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r3, [r5, #0x14]
	lsl r2, r2, #2
	ldr r3, [r3, r2]
	ldr r0, [r5, r0]
	add r2, r3, #0
	mov r1, #0
	mul r2, r4
	mov r3, #6
	bl BufferIntegerAsString
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r6, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r4, r0, #0
	mov r0, #4
	str r0, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _0225E470 ; =0x00010200
	mov r3, #0x40
	add r2, #0x35
	str r0, [sp, #8]
	mov r1, #0
	add r0, r5, r2
	add r2, r6, #0
	sub r3, r3, r4
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	add r0, r7, #0
	bl String_Delete
	mov r0, #0x4d
	lsl r0, r0, #2
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225E470: .word 0x00010200
	thumb_func_end ov31_0225E2D4

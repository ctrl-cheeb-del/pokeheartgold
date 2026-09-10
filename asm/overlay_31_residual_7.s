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

	thumb_func_start ov31_0225DE24
ov31_0225DE24: ; 0x0225DE24
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [sp, #0x28]
	add r6, r1, #0
	sub r0, r0, #3
	add r7, r2, #0
	mov r4, #0x12
	cmp r0, #1
	bhi _0225DE3A
	mov r4, #0x13
_0225DE3A:
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r2, r3, #0
	add r0, r5, #0
	mov r3, #4
	bl BufferIntegerAsString
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	mov r3, #8
	bl ReadMsgData_ExpandPlaceholders
	add r4, r0, #0
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225DE80 ; =0x00010200
	mov r1, #0
	str r0, [sp, #8]
	add r0, r7, #0
	add r2, r4, #0
	mov r3, #0x24
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225DE80: .word 0x00010200
	thumb_func_end ov31_0225DE24


	thumb_func_start ov31_0225DE84
ov31_0225DE84: ; 0x0225DE84
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r0, #0x74
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r1, [r5, #0x14]
	ldr r0, _0225DF90 ; =0x00000283
	ldrb r0, [r1, r0]
	add r0, #0xfd
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bhi _0225DEB0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x21
	bl NewString_ReadMsgData
	b _0225DEBC
_0225DEB0:
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x1e
	bl NewString_ReadMsgData
_0225DEBC:
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225DF94 ; =0x000F0E00
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x74
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	mov r0, #0x10
	mov r1, #0xb
	bl String_New
	add r4, r0, #0
	ldr r1, [r5, #0x14]
	ldr r0, _0225DF90 ; =0x00000283
	ldrb r0, [r1, r0]
	add r0, #0xfd
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bhi _0225DF12
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x20
	bl NewString_ReadMsgData
	add r7, r0, #0
	mov r0, #0x5b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl PokeathlonSave_GetAthletePoints
	b _0225DF2A
_0225DF12:
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x1f
	bl NewString_ReadMsgData
	add r7, r0, #0
	mov r0, #0x5a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl PlayerProfile_GetMoney
_0225DF2A:
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	mov r3, #6
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
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225DF94 ; =0x000F0E00
	mov r3, #0x48
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #0
	add r0, #0x74
	add r2, r4, #0
	sub r3, r3, r6
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r4, #0
	bl String_Delete
	add r5, #0x74
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225DF90: .word 0x00000283
_0225DF94: .word 0x000F0E00
	thumb_func_end ov31_0225DE84


	thumb_func_start ov31_0225DF98
ov31_0225DF98: ; 0x0225DF98
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r0, #0
	add r0, #0x54
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #6
	mov r1, #0xb
	bl String_New
	add r6, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x2b
	bl NewString_ReadMsgData
	add r7, r0, #0
	ldr r5, [r4, #0x14]
	ldr r0, _0225E058 ; =0x00000271
	mov r1, #6
	ldrb r0, [r5, r0]
	add r0, r0, #6
	bl _s32_div_f
	str r0, [sp, #0x14]
	mov r0, #0x27
	lsl r0, r0, #4
	ldrb r0, [r5, r0]
	mov r1, #6
	str r0, [sp, #0x10]
	bl _s32_div_f
	add r5, r0, #0
	ldr r0, [sp, #0x10]
	mov r1, #6
	bl _s32_div_f
	cmp r1, #0
	beq _0225DFEC
	add r5, r5, #1
_0225DFEC:
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r2, [sp, #0x14]
	mov r1, #0
	mov r3, #2
	bl BufferIntegerAsString
	mov r1, #1
	str r1, [sp]
	mov r0, #0x55
	str r1, [sp, #4]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r2, r5, #0
	mov r3, #2
	bl BufferIntegerAsString
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, r6, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225E05C ; =0x000F0E00
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #0x54
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r4, #0x54
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225E058: .word 0x00000271
_0225E05C: .word 0x000F0E00
	thumb_func_end ov31_0225DF98


	thumb_func_start ov31_0225E060
ov31_0225E060: ; 0x0225E060
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r1, [sp, #0x10]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r6, r0, #0
	add r4, r2, #0
	bl GetBgTilemapBuffer
	str r0, [sp, #0x14]
	cmp r4, #6
	beq _0225E0DA
	ldr r1, _0225E0E0 ; =ov31_0225EF48
	lsl r0, r4, #5
	add r5, r1, r0
	ldr r0, [sp, #0x10]
	mov r7, #0
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_0225E086:
	ldrb r0, [r5]
	cmp r0, #1
	bne _0225E0B2
	ldrb r0, [r5, #4]
	add r1, r4, #0
	str r0, [sp]
	ldrb r0, [r5, #5]
	str r0, [sp, #4]
	ldrb r0, [r5, #6]
	str r0, [sp, #8]
	ldrb r3, [r5, #2]
	ldrb r2, [r5, #1]
	add r0, r6, #0
	lsl r3, r3, #5
	add r2, r2, r3
	lsl r3, r2, #1
	ldr r2, [sp, #0x14]
	add r2, r2, r3
	ldrb r3, [r5, #3]
	bl LoadRectToBgTilemapRect
	b _0225E0D2
_0225E0B2:
	cmp r0, #2
	bne _0225E0D2
	ldrb r0, [r5, #4]
	add r1, r4, #0
	mov r2, #0
	str r0, [sp]
	ldrb r0, [r5, #5]
	str r0, [sp, #4]
	ldrb r0, [r5, #6]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldrb r3, [r5, #3]
	add r0, r6, #0
	bl FillBgTilemapRect
_0225E0D2:
	add r7, r7, #1
	add r5, #8
	cmp r7, #4
	blt _0225E086
_0225E0DA:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225E0E0: .word ov31_0225EF48
	thumb_func_end ov31_0225E060

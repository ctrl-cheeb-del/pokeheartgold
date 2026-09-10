	.include "asm/macros.inc"
	.include "overlay_01_021F3F50.inc"
	.include "global.inc"

	.text
	.public ov01_021F3F50
	.public ov01_021F3F9C
	.public ov01_021F4044
	.public ov01_021F4048
	.public Field_SaveStatsPrinter_Print
	.public Field_SaveStatsPrinter_RemoveFromScreen
	.public Field_SaveStatsPrinter_New
	.public Field_SaveStatsPrinter_Delete
	.public ov01_021F4234
	.public ov01_021F426C
	.public ov01_021F42F8
	.public ov01_021F434C
	.public ov01_021F4360
	.public ov01_021F43D0
	.public Field_SaveGameNormal
	.public ov01_021F4404
	.public ov01_021F4440
	.public ov01_02206AD8
	.public ov01_02206AE4
	.public ov01_02206AF4
	.public ov01_02206B04

	.public Field_SaveGameNormal
	.public Field_SaveStatsPrinter_Delete
	.public Field_SaveStatsPrinter_New
	.public Field_SaveStatsPrinter_Print
	.public Field_SaveStatsPrinter_RemoveFromScreen
	.public ov01_021F3F50
	.public ov01_021F3F9C
	.public ov01_021F4044
	.public ov01_021F4234
	.public ov01_021F426C
	.public ov01_021F42F8
	.public ov01_021F434C
	.public ov01_021F4360
	.public ov01_021F43D0
	.public ov01_021F4404
	.public ov01_021F4440

	thumb_func_start ov01_021F4048
ov01_021F4048: ; 0x021F4048
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	mov r0, #0
	mov r1, #1
	bl GetFontAttribute
	add r4, r0, #0
	mov r0, #0
	mov r1, #3
	bl GetFontAttribute
	add r0, r4, r0
	str r0, [sp, #0x14]
	mov r4, #0
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	ldr r3, [r5, #4]
	add r2, r4, #0
	bl ReadMsgData_ExpandPlaceholders
	add r1, r4, #0
	add r6, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r5, #0x10]
	add r2, r6, #0
	add r3, r1, #0
	bl AddTextPrinterParameterized
	add r0, r6, #0
	bl String_Delete
	mov r0, #1
	str r0, [sp, #0x10]
	ldr r0, _021F4124 ; =ov01_02206AF4
	ldr r7, _021F4128 ; =ov01_02206AE4
	str r0, [sp, #0xc]
_021F4098:
	ldr r0, [sp, #0xc]
	ldr r1, [r0]
	cmp r1, #3
	bne _021F40A6
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq _021F410E
_021F40A6:
	ldr r0, [sp, #0x14]
	add r4, r4, r0
	ldr r0, [r5, #0x18]
	bl NewString_ReadMsgData
	add r6, r0, #0
	mov r1, #0
	str r4, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [r5, #0x10]
	add r2, r6, #0
	add r3, r1, #0
	bl AddTextPrinterParameterized
	add r0, r6, #0
	bl String_Delete
	sub r2, r7, #4
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	ldr r2, [r2]
	ldr r3, [r5, #4]
	bl ReadMsgData_ExpandPlaceholders
	add r6, r0, #0
	mov r0, #0
	mov r1, #2
	bl GetFontAttribute
	add r2, r0, #0
	mov r0, #0
	add r1, r6, #0
	bl FontID_String_GetWidth
	mov r1, #0x68
	sub r3, r1, r0
	str r4, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [r5, #0x10]
	mov r1, #0
	add r2, r6, #0
	bl AddTextPrinterParameterized
	add r0, r6, #0
	bl String_Delete
_021F410E:
	ldr r0, [sp, #0xc]
	add r7, r7, #4
	add r0, r0, #4
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #5
	blo _021F4098
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F4124: .word ov01_02206AF4
_021F4128: .word ov01_02206AE4
	thumb_func_end ov01_021F4048

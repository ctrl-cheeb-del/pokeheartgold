	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public AddTextPrinterParameterizedWithColor
	.public AddWindowParameterized
	.public FillWindowPixelBuffer
	.public InitWindow
	.public NewString_ReadMsgData
	.public ScheduleWindowCopyToVram
	.public String_Delete
	.public ov40_022306C0
	.public ov40_02235DAC
	.public ov40_02235FFC
	.public ov40_02245708
	.text

	thumb_func_start ov40_02235FFC
ov40_02235FFC: ; 0x02235FFC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	str r0, [sp, #0x14]
	mov r0, #1
	str r0, [sp, #0x28]
	mov r1, #0x86
	ldr r0, [sp, #0x14]
	lsl r1, r1, #4
	ldr r4, [r0, r1]
	ldr r5, _02236100 ; =ov40_02245708
	mov r7, #0
	add r4, #0xd0
_02236014:
	ldrb r0, [r5, #2]
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x24]
	ldrb r0, [r5]
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x20]
	ldrb r0, [r5, #3]
	lsr r1, r0, #3
	ldr r0, [sp, #0x24]
	sub r0, r1, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x1c]
	ldrb r0, [r5, #1]
	lsr r1, r0, #3
	ldr r0, [sp, #0x20]
	sub r0, r1, r0
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r4, #0
	bl InitWindow
	ldr r0, [sp, #0x20]
	add r1, r4, #0
	str r0, [sp]
	ldr r0, [sp, #0x1c]
	mov r2, #6
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, #0xe
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ldr r3, [sp, #0x24]
	ldr r0, [r0, #0x24]
	bl AddWindowParameterized
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x14]
	add r1, r7, #0
	ldr r0, [r0, #0x48]
	add r1, #0x44
	bl NewString_ReadMsgData
	str r0, [sp, #0x2c]
	ldr r1, [sp, #0x2c]
	add r0, r4, #0
	bl ov40_022306C0
	lsl r1, r6, #3
	sub r1, #0x10
	str r0, [sp, #0x30]
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r1, r7, #0
	bl ov40_02235DAC
	cmp r0, #1
	bne _022360BE
	ldr r0, [sp, #0x18]
	ldr r2, [sp, #0x2c]
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02236104 ; =0x000F0D00
	ldr r3, [sp, #0x30]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r1, #0
	bl AddTextPrinterParameterizedWithColor
	b _022360DA
_022360BE:
	ldr r0, [sp, #0x18]
	ldr r2, [sp, #0x2c]
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02236108 ; =0x000C0B00
	ldr r3, [sp, #0x30]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r1, #0
	bl AddTextPrinterParameterizedWithColor
_022360DA:
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	ldr r0, [sp, #0x2c]
	bl String_Delete
	ldr r0, [sp, #0x1c]
	add r7, r7, #1
	add r1, r0, #0
	ldr r0, [sp, #0x28]
	mul r1, r6
	add r0, r0, r1
	str r0, [sp, #0x28]
	add r4, #0x10
	add r5, r5, #4
	cmp r7, #9
	blo _02236014
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02236100: .word ov40_02245708
_02236104: .word 0x000F0D00
_02236108: .word 0x000C0B00
	thumb_func_end ov40_02235FFC

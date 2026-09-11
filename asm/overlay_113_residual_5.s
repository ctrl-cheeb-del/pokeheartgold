	.include "asm/macros.inc"
	.include "overlay_113.inc"
	.include "asm/include/overlay_113_split.inc"
	.include "global.inc"

	.text
	.public UnownReport_Exit
	.public ov113_021E59F8
	.public ov113_021E5A48
	.public ov113_021E5B60
	.public ov113_021E5B70
	.public ov113_021E5BB0
	.public ov113_021E5C60
	.public ov113_021E5CF8
	.public ov113_021E5D28
	.public ov113_021E5D4C
	.public ov113_021E5EC4
	.public ov113_021E6274
	.public ov113_021E629C
	.public ov113_021E62E0
	.public ov113_021E64DC
	.public ov113_021E663C
	.public ov113_021E66E4
	.public ov113_021E6754
	.public ov113_021E6930
	.public ov113_021E6988
	.public ov113_021E69A8

	thumb_func_start ov113_021E5D60
ov113_021E5D60: ; 0x021E5D60
	push {r3, r4, lr}
	sub sp, #4
	mov r1, #0
	str r1, [sp]
	add r1, sp, #0
	add r4, r0, #0
	bl ov113_021E5F94
	ldr r1, [sp]
	cmp r1, #0
	bne _021E5D7C
	add r0, r4, #0
	bl ov113_021E5F48
_021E5D7C:
	add sp, #4
	pop {r3, r4, pc}
	thumb_func_end ov113_021E5D60


	thumb_func_start ov113_021E5D80
ov113_021E5D80: ; 0x021E5D80
	add r0, #0x3c
	ldrb r3, [r0]
	ldr r2, _021E5DA0 ; =ov113_021E6BD0
	mov r1, #0
_021E5D88:
	ldrh r0, [r2]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x18
	cmp r0, r3
	bgt _021E5D9A
	add r1, r1, #1
	add r2, r2, #4
	cmp r1, #6
	blt _021E5D88
_021E5D9A:
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	bx lr
	.balign 4, 0
_021E5DA0: .word ov113_021E6BD0
	thumb_func_end ov113_021E5D80


	thumb_func_start ov113_021E5DA4
ov113_021E5DA4: ; 0x021E5DA4
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r0, #0x78
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x88
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x98
	mov r1, #0
	bl FillWindowPixelBuffer
	ldrb r3, [r4, #0x1a]
	cmp r3, #0
	bne _021E5DD4
	add r0, r4, #0
	bl ov113_021E5FC0
	b _021E5DF6
_021E5DD4:
	ldrb r2, [r4, #0x1c]
	sub r1, r3, #1
	cmp r1, r2
	bge _021E5DE8
	lsl r1, r1, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov113_021E6084
	b _021E5DF6
_021E5DE8:
	add r1, r2, #1
	sub r1, r3, r1
	lsl r1, r1, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov113_021E613C
_021E5DF6:
	mov r1, #0
	str r1, [sp]
	mov r3, #1
	str r3, [sp, #4]
	ldrb r2, [r4, #0x1a]
	ldr r0, [r4, #0x48]
	add r2, r2, #1
	bl BufferIntegerAsString
	mov r0, #0
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r2, [r4, #0x1b]
	ldr r0, [r4, #0x48]
	add r3, r1, #0
	bl BufferIntegerAsString
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x50]
	ldr r2, [r4, #0x58]
	bl StringExpandPlaceholders
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E5E60 ; =0x000F0200
	add r3, r1, #0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r4, #0
	ldr r2, [r4, #0x50]
	add r0, #0x98
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	add r0, #0x78
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x88
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x98
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	bl ov113_021E6B1C
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_021E5E60: .word 0x000F0200
	thumb_func_end ov113_021E5DA4


	thumb_func_start ov113_021E5E64
ov113_021E5E64: ; 0x021E5E64
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r0, #0xb8
	ldr r0, [r0]
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	add r0, #0xb8
	ldr r0, [r0]
	bl Sprite_ResetAnimCtrlState
	add r0, r4, #0
	add r0, #0x68
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r1, [r4, #0x54]
	mov r0, #4
	mov r2, #0
	bl FontID_String_GetWidth
	mov r1, #0
	add r3, r0, #0
	mov r5, #0x30
	sub r3, r5, r3
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E5EC0 ; =0x00070F00
	lsr r3, r3, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r4, #0
	ldr r2, [r4, #0x54]
	add r0, #0x68
	mov r1, #4
	bl AddTextPrinterParameterizedWithColor
	add r4, #0x68
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_021E5EC0: .word 0x00070F00
	thumb_func_end ov113_021E5E64


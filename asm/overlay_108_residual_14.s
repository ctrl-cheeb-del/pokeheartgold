	.include "asm/macros.inc"
	.include "overlay_108.inc"
	.include "global.inc"

	.text
	.public _021EA720
	.public ov108_021E5C54
	.public ov108_021E5D0C
	.public ov108_021E5DB8
	.public ov108_021E5E68
	.public ov108_021E5F38
	.public ov108_021E6090
	.public ov108_021E62B4
	.public ov108_021E63B8
	.public ov108_021E6450
	.public ov108_021E64C0
	.public ov108_021E66AC
	.public ov108_021E6894
	.public ov108_021E69A0
	.public ov108_021E6A58
	.public ov108_021E6B00
	.public ov108_021E6BA0
	.public ov108_021E6C68
	.public ov108_021E6D24
	.public ov108_021E6D80
	.public ov108_021E6F74
	.public ov108_021E7014
	.public ov108_021E7080
	.public ov108_021E7224
	.public ov108_021E733C
	.public ov108_021E756C
	.public ov108_021E767C
	.public ov108_021E7700
	.public ov108_021E77D4
	.public ov108_021E78F4
	.public ov108_021E79A8
	.public ov108_021E7ADC
	.public ov108_021E7B74
	.public ov108_021E7BB4
	.public ov108_021E7C5C
	.public ov108_021E7CD8
	.public ov108_021E7EB0
	.public ov108_021E7F7C
	.public ov108_021E80F4
	.public ov108_021E81A8
	.public ov108_021E8270
	.public ov108_021E82E0
	.public ov108_021E84F8
	.public ov108_021E8540
	.public ov108_021E867C
	.public ov108_021E8758
	.public ov108_021EA724
	.public ov108_021EA738
	.public ov108_021EA748
	.public ov108_021EA74A
	.public ov108_021EA760
	.public ov108_021EA780
	.public ov108_021EA7A8
	.public ov108_021EA7D0
	.public ov108_021EA7F8
	.public ov108_021EA820
	.public ov108_021EA848
	.public ov108_021EA870
	.public ov108_021EA898
	.public ov108_021EA978
	.public ov108_021EA97C
	.public ov108_021EA98C
	.public ov108_021EA9A0

	.public SafariAreaCustomizer_Exit
	.public SafariAreaCustomizer_Init
	.public SafariAreaCustomizer_Main
	.public ov108_021E59E4
	.public ov108_021E5A48
	.public ov108_021E5A78
	.public ov108_021E5A8C
	.public ov108_021E5AA0
	.public ov108_021E5AF0
	.public ov108_021E5B48
	.public ov108_021E5B98
	.public ov108_021E5BFC
	.public ov108_021E5D90
	.public ov108_021E5F10
	.public ov108_021E6010
	.public ov108_021E6068
	.public ov108_021E61E8
	.public ov108_021E6238
	.public ov108_021E6240
	.public ov108_021E6804
	.public ov108_021E6850
	.public ov108_021E6C48
	.public ov108_021E6F58
	.public ov108_021E71EC
	.public ov108_021E72A4
	.public ov108_021E72CC
	.public ov108_021E730C
	.public ov108_021E7510
	.public ov108_021E7650
	.public ov108_021E78C0
	.public ov108_021E7BFC
	.public ov108_021E838C
	.public ov108_021E83C8
	.public ov108_021E83F0
	.public ov108_021E844C
	.public ov108_021E846C
	.public ov108_021E8490
	.public ov108_021E84A4
	.public ov108_021E84DC
	.public ov108_021E852C
	.public ov108_021E853C
	.public ov108_021E8674
	.public ov108_021E8718

	thumb_func_start ov108_021E7C5C
ov108_021E7C5C: ; 0x021E7C5C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	ldr r0, _021E7CD0 ; =0x000184E3
	ldrb r0, [r5, r0]
	cmp r0, #0
	beq _021E7CCC
	mov r0, #0xed
	lsl r0, r0, #2
	add r0, r5, r0
	mov r4, #0
	mov r6, #5
	str r0, [sp, #0x10]
_021E7C76:
	mov r0, #0xc1
	mov r2, #0xc3
	lsl r0, r0, #2
	lsl r2, r2, #2
	add r1, r4, #0
	ldr r0, [r5, r0]
	ldr r2, [r5, r2]
	add r1, #0xa
	lsl r7, r6, #4
	bl ReadMsgDataIntoString
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	lsr r2, r4, #0x1f
	lsl r1, r4, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	lsl r1, r0, #2
	ldr r0, _021E7CD4 ; =ov108_021EA724
	mov r2, #0xc3
	ldr r0, [r0, r1]
	mov r1, #0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	lsl r2, r2, #2
	ldr r2, [r5, r2]
	add r0, r0, r7
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x10]
	add r0, r0, r7
	bl CopyWindowToVram
	add r4, r4, #1
	add r6, r6, #2
	cmp r4, #5
	blt _021E7C76
_021E7CCC:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7CD0: .word 0x000184E3
_021E7CD4: .word ov108_021EA724
	thumb_func_end ov108_021E7C5C


	thumb_func_start ov108_021E7CD8
ov108_021E7CD8: ; 0x021E7CD8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r5, r0, #0
	cmp r1, #6
	blo _021E7D3E
	ldr r0, _021E7EA4 ; =0x000184E3
	ldrb r0, [r5, r0]
	cmp r0, #0
	beq _021E7D24
	mov r0, #0xed
	lsl r0, r0, #2
	mov r6, #0
	mov r4, #6
	add r7, r5, r0
_021E7CF4:
	lsr r3, r6, #0x1f
	lsl r2, r6, #0x1f
	sub r2, r2, r3
	mov r1, #0x1f
	ror r2, r1
	add r1, r3, r2
	lsl r2, r1, #2
	ldr r1, _021E7EA8 ; =ov108_021EA724
	lsl r0, r4, #4
	ldr r1, [r1, r2]
	str r0, [sp, #0x20]
	lsl r1, r1, #0x18
	add r0, r7, r0
	lsr r1, r1, #0x18
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x20]
	add r0, r7, r0
	bl ScheduleWindowCopyToVram
	add r6, r6, #1
	add r4, r4, #2
	cmp r6, #5
	blt _021E7CF4
_021E7D24:
	mov r0, #0xfd
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0xc
	bl FillWindowPixelBuffer
	mov r0, #0xfd
	lsl r0, r0, #2
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
_021E7D3E:
	add r3, r5, #0
	mov r6, #0xfd
	mov r0, #0x7a
	add r2, r1, #0
	add r3, #0x1c
	mul r2, r0
	add r0, r3, r2
	ldrb r1, [r3, r2]
	lsl r6, r6, #2
	str r0, [sp, #0x1c]
	add r0, r6, #0
	add r2, r6, #0
	sub r0, #0xf0
	sub r2, #0xe8
	ldr r0, [r5, r0]
	ldr r2, [r5, r2]
	add r1, #0x10
	bl ReadMsgDataIntoString
	add r0, r5, r6
	bl GetWindowWidth
	add r1, r6, #0
	sub r1, #0xe8
	add r4, r0, #0
	mov r0, #0
	ldr r1, [r5, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	lsl r1, r4, #3
	sub r0, r1, r0
	lsl r0, r0, #0x17
	lsr r4, r0, #0x18
	add r0, r5, r6
	mov r1, #0xc
	bl FillWindowPixelBuffer
	mov r0, #4
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E7EAC ; =0x00080B0C
	add r2, r6, #0
	str r0, [sp, #8]
	mov r1, #0
	str r1, [sp, #0xc]
	sub r2, #0xe8
	ldr r2, [r5, r2]
	add r0, r5, r6
	add r3, r4, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, r6
	bl ScheduleWindowCopyToVram
	ldr r0, _021E7EA4 ; =0x000184E3
	ldrb r0, [r5, r0]
	cmp r0, #0
	beq _021E7E9E
	add r0, sp, #0x24
	add r0, #3
	mov r1, #0
	mov r2, #5
	bl MI_CpuFill8
	ldr r0, [sp, #0x1c]
	mov r4, #0
	ldrb r0, [r0, #1]
	cmp r0, #0
	ble _021E7E02
	ldr r6, [sp, #0x1c]
	add r7, sp, #0x24
_021E7DD0:
	ldrb r1, [r6, #2]
	add r0, sp, #0x24
	mov r2, #2
	bl GetSafariObjectConfig
	ldrb r1, [r7, #2]
	cmp r1, #0
	bne _021E7DE8
	ldrb r0, [r7, #7]
	add r0, r0, #1
	strb r0, [r7, #7]
	b _021E7DF6
_021E7DE8:
	add r0, sp, #0x24
	add r0, #3
	add r0, r0, r1
	sub r0, r0, #1
	ldrb r1, [r0]
	add r1, r1, #1
	strb r1, [r0]
_021E7DF6:
	ldr r0, [sp, #0x1c]
	add r4, r4, #1
	ldrb r0, [r0, #1]
	add r6, r6, #4
	cmp r4, r0
	blt _021E7DD0
_021E7E02:
	mov r0, #6
	str r0, [sp, #0x18]
	add r0, sp, #0x24
	add r0, #3
	str r0, [sp, #0x14]
	mov r0, #0xed
	lsl r0, r0, #2
	mov r7, #0
	add r6, r5, r0
_021E7E14:
	ldr r0, [sp, #0x18]
	ldr r2, [sp, #0x14]
	lsl r4, r0, #4
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0xc2
	lsl r0, r0, #2
	ldrb r2, [r2]
	ldr r0, [r5, r0]
	mov r1, #0
	mov r3, #2
	bl BufferIntegerAsString
	mov r0, #0xc2
	mov r1, #0xc3
	mov r2, #0xce
	lsl r0, r0, #2
	lsl r1, r1, #2
	lsl r2, r2, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl StringExpandPlaceholders
	lsr r2, r7, #0x1f
	lsl r1, r7, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	lsl r1, r0, #2
	ldr r0, _021E7EA8 ; =ov108_021EA724
	ldr r0, [r0, r1]
	str r0, [sp, #0x10]
	ldr r1, [sp, #0x10]
	add r0, r6, r4
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl FillWindowPixelBuffer
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	mov r2, #0xc3
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	lsl r2, r2, #2
	mov r1, #0
	ldr r2, [r5, r2]
	add r0, r6, r4
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, r4
	bl ScheduleWindowCopyToVram
	ldr r0, [sp, #0x18]
	add r7, r7, #1
	add r0, r0, #2
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r7, #5
	blt _021E7E14
_021E7E9E:
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	nop
_021E7EA4: .word 0x000184E3
_021E7EA8: .word ov108_021EA724
_021E7EAC: .word 0x00080B0C
	thumb_func_end ov108_021E7CD8


	thumb_func_start ov108_021E7EB0
ov108_021E7EB0: ; 0x021E7EB0
	push {r4, r5, r6, lr}
	sub sp, #0x10
	mov r4, #0xfd
	add r5, r0, #0
	lsl r4, r4, #2
	add r0, r5, r4
	mov r1, #0xc
	bl FillWindowPixelBuffer
	ldr r1, _021E7F70 ; =0x000184DF
	add r2, r4, #0
	ldrb r3, [r5, r1]
	mov r1, #0x7a
	sub r2, #0xf0
	mul r1, r3
	add r1, r5, r1
	ldrb r1, [r1, #0x1c]
	ldr r0, [r5, r2]
	add r2, #8
	ldr r2, [r5, r2]
	add r1, #0x10
	bl ReadMsgDataIntoString
	add r1, r4, #0
	sub r1, #0xe8
	mov r0, #0
	ldr r1, [r5, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0x60
	sub r0, r1, r0
	lsl r0, r0, #0x17
	lsr r3, r0, #0x18
	mov r0, #4
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E7F74 ; =0x00080B0C
	add r2, r4, #0
	str r0, [sp, #8]
	mov r1, #0
	str r1, [sp, #0xc]
	sub r2, #0xe8
	ldr r2, [r5, r2]
	add r0, r5, r4
	bl AddTextPrinterParameterizedWithColor
	ldr r3, _021E7F78 ; =0x000184E0
	ldrb r1, [r5, r3]
	cmp r1, #6
	bhs _021E7F66
	sub r3, r3, #2
	add r2, r4, #0
	ldrb r6, [r5, r3]
	sub r2, #0xf0
	ldr r0, [r5, r2]
	mov r3, #6
	add r2, #8
	add r1, #0x10
	mul r3, r6
	ldr r2, [r5, r2]
	add r1, r1, r3
	bl ReadMsgDataIntoString
	add r1, r4, #0
	sub r1, #0xe8
	mov r0, #0
	ldr r1, [r5, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0x60
	sub r0, r1, r0
	lsl r0, r0, #0x17
	lsr r3, r0, #0x18
	mov r0, #4
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E7F74 ; =0x00080B0C
	add r2, r4, #0
	str r0, [sp, #8]
	mov r1, #0
	str r1, [sp, #0xc]
	sub r2, #0xe8
	ldr r2, [r5, r2]
	add r0, r5, r4
	add r3, #0x90
	bl AddTextPrinterParameterizedWithColor
_021E7F66:
	add r0, r5, r4
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E7F70: .word 0x000184DF
_021E7F74: .word 0x00080B0C
_021E7F78: .word 0x000184E0
	thumb_func_end ov108_021E7EB0


	thumb_func_start ov108_021E7F7C
ov108_021E7F7C: ; 0x021E7F7C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r1, _021E80DC ; =0x000184E2
	add r6, r0, #0
	ldrb r1, [r6, r1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1b
	bne _021E7FF4
	mov r0, #0x15
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0x11
	str r0, [sp, #0xc]
	mov r0, #0xd
	lsl r0, r0, #6
	mov r2, #0
	ldr r0, [r6, r0]
	mov r1, #1
	add r3, r2, #0
	bl FillBgTilemapRect
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0xbf
	ldr r2, _021E80E0 ; =0x000184E6
	mvn r0, r0
	strh r0, [r6, r2]
	sub r0, r2, #4
	ldrb r3, [r6, r0]
	mov r0, #1
	mov r1, #1
	bic r3, r0
	orr r3, r1
	sub r0, r2, #4
	strb r3, [r6, r0]
	sub r0, r2, #6
	mov r3, #0
	strb r3, [r6, r0]
	sub r2, r2, #6
	ldrb r2, [r6, r2]
	add r0, r6, #0
	bl ov108_021E78F4
	ldr r2, _021E80E4 ; =0x000184DF
	add r0, r6, #0
	ldrb r2, [r6, r2]
	mov r1, #2
	bl ov108_021E78F4
	add r0, r6, #0
	bl ov108_021E77D4
	b _021E807E
_021E7FF4:
	mov r1, #1
	mov r2, #0xff
	mov r3, #0
	bl ov108_021E79A8
	mov r2, #0
	add r0, r6, #0
	mov r1, #1
	add r3, r2, #0
	bl ov108_021E78C0
	ldr r0, _021E80DC ; =0x000184E2
	mov r4, #0
	ldrb r0, [r6, r0]
	add r7, r6, #0
	lsl r0, r0, #0x1d
	lsr r1, r0, #0x1f
	mov r0, #6
	mul r0, r1
	str r0, [sp, #0x14]
	lsl r0, r0, #2
	add r5, r6, r0
_021E8020:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	str r1, [sp, #0x10]
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r3, r0, #0
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r2, [sp, #0x10]
	mov r1, #0x48
	mul r1, r2
	mov r2, #0x48
	mul r2, r3
	add r1, #0x38
	sub r2, #0x88
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r5, r0]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #2
	bl ManagedSprite_SetPriority
	ldr r1, [sp, #0x14]
	mov r0, #0xd2
	lsl r0, r0, #2
	add r1, r4, r1
	lsl r1, r1, #0x18
	ldrb r2, [r7, #0x1c]
	ldr r0, [r6, r0]
	lsr r1, r1, #0x18
	bl ov108_021E84F8
	add r4, r4, #1
	add r5, r5, #4
	add r7, #0x7a
	cmp r4, #6
	blt _021E8020
_021E807E:
	ldr r0, _021E80E8 ; =0x000184E1
	mov r1, #0
	strb r1, [r6, r0]
	mov r0, #0xfd
	lsl r0, r0, #2
	add r0, r6, r0
	mov r1, #0xc
	bl FillWindowPixelBuffer
	mov r0, #0xfd
	lsl r0, r0, #2
	add r0, r6, r0
	bl ScheduleWindowCopyToVram
	ldr r0, _021E80EC ; =0x04001040
	mov r1, #0xf0
	strh r1, [r0]
	mov r1, #0x10
	add r4, r0, #0
	strh r1, [r0, #4]
	add r4, #8
	ldrh r3, [r4]
	mov r2, #0x3f
	mov r1, #0xf
	bic r3, r2
	orr r1, r3
	mov r3, #0x20
	orr r1, r3
	strh r1, [r4]
	add r4, r0, #0
	add r4, #0xa
	ldrh r5, [r4]
	mov r1, #0x1f
	sub r0, #0x40
	bic r5, r2
	orr r1, r5
	orr r1, r3
	strh r1, [r4]
	ldr r2, [r0]
	ldr r1, _021E80F0 ; =0xFFFF1FFF
	and r2, r1
	lsl r1, r3, #8
	orr r1, r2
	str r1, [r0]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E80DC: .word 0x000184E2
_021E80E0: .word 0x000184E6
_021E80E4: .word 0x000184DF
_021E80E8: .word 0x000184E1
_021E80EC: .word 0x04001040
_021E80F0: .word 0xFFFF1FFF
	thumb_func_end ov108_021E7F7C


	thumb_func_start ov108_021E80F4
ov108_021E80F4: ; 0x021E80F4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _021E81A0 ; =0x000184E2
	ldrb r1, [r5, r0]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1b
	bne _021E811A
	add r1, r0, #2
	ldrsh r2, [r5, r1]
	mov r7, #0x17
	mvn r7, r7
	add r2, #0x18
	strh r2, [r5, r1]
	add r1, r0, #4
	ldrsh r1, [r5, r1]
	add r0, r0, #4
	add r1, #0x18
	strh r1, [r5, r0]
	b _021E812E
_021E811A:
	add r1, r0, #2
	ldrsh r2, [r5, r1]
	mov r7, #0x18
	sub r2, #0x18
	strh r2, [r5, r1]
	add r1, r0, #4
	ldrsh r1, [r5, r1]
	add r0, r0, #4
	sub r1, #0x18
	strh r1, [r5, r0]
_021E812E:
	ldr r1, _021E81A0 ; =0x000184E2
	mov r0, #1
	ldrb r2, [r5, r1]
	mov r4, #0
	bic r2, r0
	mov r0, #1
	orr r0, r2
	strb r0, [r5, r1]
	lsl r0, r7, #0x10
	asr r6, r0, #0x10
_021E8142:
	ldr r0, _021E81A0 ; =0x000184E2
	add r2, r6, #0
	ldrb r0, [r5, r0]
	lsl r0, r0, #0x1d
	lsr r1, r0, #0x1f
	mov r0, #6
	mul r0, r1
	add r0, r4, r0
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_OffsetPositionXY
	add r4, r4, #1
	cmp r4, #6
	blt _021E8142
	mov r0, #0xd5
	lsl r0, r0, #2
	lsl r2, r7, #0x10
	ldr r0, [r5, r0]
	mov r1, #0
	asr r2, r2, #0x10
	bl Sprite_OffsetPositionXY
	mov r0, #0xd7
	lsl r0, r0, #2
	lsl r2, r7, #0x10
	ldr r0, [r5, r0]
	mov r1, #0
	asr r2, r2, #0x10
	bl Sprite_OffsetPositionXY
	ldr r0, _021E81A4 ; =0x000184E1
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
	ldrb r0, [r5, r0]
	cmp r0, #8
	blo _021E819A
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E819A:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E81A0: .word 0x000184E2
_021E81A4: .word 0x000184E1
	thumb_func_end ov108_021E80F4


	thumb_func_start ov108_021E81A8
ov108_021E81A8: ; 0x021E81A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r1, _021E8264 ; =0x000184E2
	add r6, r0, #0
	ldrb r0, [r6, r1]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	bne _021E81CA
	sub r0, r1, #4
	ldrb r0, [r6, r0]
	add r2, r0, #1
	sub r0, r1, #4
	strb r2, [r6, r0]
	mov r0, #1
	lsl r0, r0, #8
	str r0, [sp]
	b _021E81DA
_021E81CA:
	sub r0, r1, #4
	ldrb r0, [r6, r0]
	sub r2, r0, #1
	sub r0, r1, #4
	strb r2, [r6, r0]
	mov r0, #0xff
	mvn r0, r0
	str r0, [sp]
_021E81DA:
	ldr r0, _021E8264 ; =0x000184E2
	mov r4, #0
	ldrb r0, [r6, r0]
	lsl r0, r0, #0x1d
	lsr r1, r0, #0x1f
	mov r0, #6
	mul r0, r1
	str r0, [sp, #4]
	lsl r0, r0, #2
	add r5, r6, r0
_021E81EE:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r1, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	mov r1, #0x50
	mul r1, r7
	add r2, r0, #0
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r3, [sp]
	add r1, #0x30
	add r1, r3, r1
	mov r3, #0x48
	mul r3, r2
	add r3, #0x38
	lsl r1, r1, #0x10
	lsl r2, r3, #0x10
	ldr r0, [r5, r0]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	ldr r2, _021E8268 ; =0x000184DE
	ldr r1, [sp, #4]
	ldrb r3, [r6, r2]
	mov r2, #6
	mov r0, #0xd2
	mul r2, r3
	lsl r0, r0, #2
	add r1, r4, r1
	add r2, r4, r2
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	ldr r0, [r6, r0]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov108_021E84F8
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl ManagedSprite_SetPriority
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blt _021E81EE
	ldr r0, _021E826C ; =0x000184E1
	mov r1, #0
	strb r1, [r6, r0]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E8264: .word 0x000184E2
_021E8268: .word 0x000184DE
_021E826C: .word 0x000184E1
	thumb_func_end ov108_021E81A8


	thumb_func_start ov108_021E8270
ov108_021E8270: ; 0x021E8270
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r0, _021E82D8 ; =0x000184E2
	ldrb r0, [r7, r0]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	bne _021E8284
	mov r0, #0x1f
	mvn r0, r0
	b _021E8286
_021E8284:
	mov r0, #0x20
_021E8286:
	lsl r0, r0, #0x10
	mov r4, #0
	add r5, r7, #0
	asr r6, r0, #0x10
_021E828E:
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	mov r2, #0
	bl ManagedSprite_OffsetPositionXY
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0xc
	blt _021E828E
	ldr r2, _021E82DC ; =0x000184E1
	ldrb r0, [r7, r2]
	add r0, r0, #1
	strb r0, [r7, r2]
	ldrb r0, [r7, r2]
	cmp r0, #8
	blo _021E82D2
	mov r0, #0
	strb r0, [r7, r2]
	sub r2, r2, #1
	ldrb r2, [r7, r2]
	add r0, r7, #0
	mov r1, #1
	bl ov108_021E78F4
	add r0, r7, #0
	bl ov108_021E7EB0
	add r0, r7, #0
	bl ov108_021E77D4
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E82D2:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E82D8: .word 0x000184E2
_021E82DC: .word 0x000184E1
	thumb_func_end ov108_021E8270


	thumb_func_start ov108_021E82E0
ov108_021E82E0: ; 0x021E82E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r1, [sp]
	ldr r1, _021E837C ; =0x000184E2
	add r6, r0, #0
	ldrb r0, [r6, r1]
	add r3, sp, #8
	lsl r0, r0, #0x1d
	lsr r2, r0, #0x1f
	mov r0, #6
	mul r0, r2
	sub r2, r1, #3
	ldrb r2, [r6, r2]
	add r2, r2, r0
	strb r2, [r3, #2]
	sub r2, r1, #2
	ldrb r2, [r6, r2]
	add r0, r2, r0
	strb r0, [r3, #3]
	sub r0, r1, #3
	ldrb r0, [r6, r0]
	mov r1, #3
	bl _s32_div_f
	add r1, sp, #8
	strb r0, [r1]
	ldr r0, _021E8380 ; =0x000184E0
	mov r1, #3
	ldrb r0, [r6, r0]
	bl _s32_div_f
	add r1, sp, #8
	strb r0, [r1, #1]
	ldr r0, [sp]
	add r5, sp, #8
	ldr r1, _021E8384 ; =_021EA720
	lsl r0, r0, #1
	add r0, r1, r0
	mov r7, #0
	add r4, sp, #8
	add r5, #2
	str r0, [sp, #4]
_021E8334:
	ldrb r3, [r4]
	ldrb r0, [r5]
	ldr r2, [sp, #4]
	ldrsb r3, [r2, r3]
	lsl r0, r0, #2
	add r1, r6, r0
	mov r0, #0xdb
	mov r2, #0xc
	lsl r0, r0, #2
	mul r2, r3
	ldr r0, [r1, r0]
	lsl r2, r2, #0x10
	mov r1, #0
	asr r2, r2, #0x10
	bl ManagedSprite_OffsetPositionXY
	add r7, r7, #1
	add r4, r4, #1
	add r5, r5, #1
	cmp r7, #2
	blt _021E8334
	ldr r0, _021E8388 ; =0x000184E1
	ldrb r1, [r6, r0]
	add r1, r1, #1
	strb r1, [r6, r0]
	ldrb r1, [r6, r0]
	cmp r1, #8
	blo _021E8376
	mov r1, #0
	strb r1, [r6, r0]
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_021E8376:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E837C: .word 0x000184E2
_021E8380: .word 0x000184E0
_021E8384: .word _021EA720
_021E8388: .word 0x000184E1
	thumb_func_end ov108_021E82E0

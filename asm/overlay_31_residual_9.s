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

	thumb_func_start ov31_0225E54C
ov31_0225E54C: ; 0x0225E54C
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0x51
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	mov r1, #0x55
	lsl r1, r1, #2
	ldr r3, [r5, #0x14]
	ldr r2, _0225E5F4 ; =0x00000283
	ldr r1, [r5, r1]
	ldrb r0, [r3, r2]
	add r2, r2, #1
	ldrh r2, [r3, r2]
	mov r3, #0
	bl ov31_0225E4BC
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0xc
	bl NewString_ReadMsgData
	mov r1, #0x55
	add r4, r0, #0
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	add r1, #0x34
	ldr r1, [r5, r1]
	add r2, r4, #0
	bl StringExpandPlaceholders
	add r0, r4, #0
	bl String_Delete
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r1, #4
	str r1, [sp, #4]
	ldr r0, [r5, #4]
	ldr r2, _0225E5F8 ; =0x000001B5
	mov r3, #5
	bl LoadUserFrameGfx2
	mov r2, #0x51
	lsl r2, r2, #2
	add r0, r5, r2
	mov r1, #1
	add r2, #0x71
	mov r3, #5
	bl DrawFrameAndWindow2
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Options_GetTextFrameDelay
	mov r3, #0
	str r3, [sp]
	mov r2, #0x51
	str r0, [sp, #4]
	lsl r2, r2, #2
	add r0, r5, r2
	str r3, [sp, #8]
	add r2, #0x44
	ldr r2, [r5, r2]
	mov r1, #1
	bl AddTextPrinterParameterized
	mov r1, #0xa
	ldr r2, [r5, #0x14]
	lsl r1, r1, #6
	strb r0, [r2, r1]
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_0225E5F4: .word 0x00000283
_0225E5F8: .word 0x000001B5
	thumb_func_end ov31_0225E54C


	thumb_func_start ov31_0225E5FC
ov31_0225E5FC: ; 0x0225E5FC
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r0, #0x51
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	ldr r2, [r4, #0x14]
	ldr r3, _0225E6F8 ; =0x00000283
	ldrb r0, [r2, r3]
	add r1, r0, #0
	add r1, #0xfd
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, #1
	bhi _0225E63E
	mov r1, #0x55
	add r3, r3, #1
	lsl r1, r1, #2
	ldrh r2, [r2, r3]
	ldr r1, [r4, r1]
	mov r3, #0
	bl ov31_0225E51C
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x2e
	bl NewString_ReadMsgData
	b _0225E684
_0225E63E:
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x55
	add r3, r3, #3
	lsl r0, r0, #2
	ldrsh r2, [r2, r3]
	ldr r0, [r4, r0]
	mov r3, #2
	bl BufferIntegerAsString
	mov r5, #0xa3
	ldr r2, [r4, #0x14]
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	mov r0, #0x55
	str r1, [sp, #4]
	lsl r5, r5, #2
	ldr r3, [r2, r5]
	sub r5, r5, #6
	ldrsh r2, [r2, r5]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mul r2, r3
	mov r3, #6
	bl BufferIntegerAsString
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xe
	bl NewString_ReadMsgData
_0225E684:
	mov r1, #0x55
	lsl r1, r1, #2
	add r5, r0, #0
	ldr r0, [r4, r1]
	add r1, #0x34
	ldr r1, [r4, r1]
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r1, #4
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	ldr r2, _0225E6FC ; =0x000001B5
	mov r3, #5
	bl LoadUserFrameGfx2
	mov r2, #0x51
	lsl r2, r2, #2
	add r0, r4, r2
	mov r1, #1
	add r2, #0x71
	mov r3, #5
	bl DrawFrameAndWindow2
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Options_GetTextFrameDelay
	mov r3, #0
	str r3, [sp]
	mov r2, #0x51
	str r0, [sp, #4]
	lsl r2, r2, #2
	add r0, r4, r2
	str r3, [sp, #8]
	add r2, #0x44
	ldr r2, [r4, r2]
	mov r1, #1
	bl AddTextPrinterParameterized
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [r4, r1]
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_0225E6F8: .word 0x00000283
_0225E6FC: .word 0x000001B5
	thumb_func_end ov31_0225E5FC


	thumb_func_start ov31_0225E700
ov31_0225E700: ; 0x0225E700
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r0, #0
	add r0, sp, #0
	mov r1, #0
	mov r2, #0x14
	bl MI_CpuFill8
	ldr r0, [r4, #4]
	mov r2, #0x1a
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #0x60
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	add r0, sp, #0
	strb r2, [r0, #0x10]
	mov r1, #6
	strb r1, [r0, #0x11]
	ldr r0, [r4, #0x1c]
	add r2, #0xf2
	add r0, r0, r2
	bl MenuInputStateMgr_GetState
	add r1, sp, #0
	ldrb r2, [r1, #0x12]
	mov r3, #0xf
	lsl r0, r0, #0x18
	bic r2, r3
	lsr r3, r0, #0x18
	mov r0, #0xf
	and r0, r3
	orr r0, r2
	strb r0, [r1, #0x12]
	ldrb r2, [r1, #0x12]
	mov r0, #0xf0
	bic r2, r0
	strb r2, [r1, #0x12]
	mov r0, #0
	strb r0, [r1, #0x13]
	ldr r0, [r4, #4]
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	mov r0, #8
	bl YesNoPrompt_Create
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	add r1, sp, #0
	bl YesNoPrompt_InitFromTemplate
	add sp, #0x14
	pop {r3, r4, pc}
	thumb_func_end ov31_0225E700

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

	thumb_func_start ov31_0225EA08
ov31_0225EA08: ; 0x0225EA08
	push {r4, r5, lr}
	sub sp, #0xc
	mov r1, #0x56
	add r5, r0, #0
	lsl r1, r1, #2
	ldr r0, [r5, #0x14]
	ldr r1, [r5, r1]
	bl ov31_0225E95C
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
	add r0, r5, #0
	add r0, #0x44
	mov r1, #0xf
	bl FillWindowPixelBuffer
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
	ldr r2, _0225EA98 ; =0x000001B5
	mov r3, #5
	bl LoadUserFrameGfx2
	add r0, r5, #0
	ldr r2, _0225EA98 ; =0x000001B5
	add r0, #0x44
	mov r1, #1
	mov r3, #5
	bl DrawFrameAndWindow2
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Options_GetTextFrameDelay
	mov r3, #0
	str r3, [sp]
	str r0, [sp, #4]
	mov r2, #0x62
	add r0, r5, #0
	str r3, [sp, #8]
	lsl r2, r2, #2
	ldr r2, [r5, r2]
	add r0, #0x44
	mov r1, #1
	bl AddTextPrinterParameterized
	mov r1, #0xa
	ldr r2, [r5, #0x14]
	lsl r1, r1, #6
	strb r0, [r2, r1]
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_0225EA98: .word 0x000001B5
	thumb_func_end ov31_0225EA08


	thumb_func_start ov31_0225EA9C
ov31_0225EA9C: ; 0x0225EA9C
	push {r4, r5, lr}
	sub sp, #0xc
	mov r1, #0x56
	add r5, r0, #0
	lsl r1, r1, #2
	ldr r0, [r5, #0x14]
	ldr r1, [r5, r1]
	bl ov31_0225E9CC
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
	add r0, r5, #0
	add r0, #0x44
	mov r1, #0xf
	bl FillWindowPixelBuffer
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
	ldr r2, _0225EB2C ; =0x000001B5
	mov r3, #5
	bl LoadUserFrameGfx2
	add r0, r5, #0
	ldr r2, _0225EB2C ; =0x000001B5
	add r0, #0x44
	mov r1, #1
	mov r3, #5
	bl DrawFrameAndWindow2
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Options_GetTextFrameDelay
	mov r3, #0
	str r3, [sp]
	str r0, [sp, #4]
	mov r2, #0x62
	add r0, r5, #0
	str r3, [sp, #8]
	lsl r2, r2, #2
	ldr r2, [r5, r2]
	add r0, #0x44
	mov r1, #1
	bl AddTextPrinterParameterized
	mov r1, #0xa
	ldr r2, [r5, #0x14]
	lsl r1, r1, #6
	strb r0, [r2, r1]
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_0225EB2C: .word 0x000001B5
	thumb_func_end ov31_0225EA9C


	thumb_func_start ov31_0225EB30
ov31_0225EB30: ; 0x0225EB30
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x10
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
	add r0, r5, #0
	add r0, #0x44
	mov r1, #0xf
	bl FillWindowPixelBuffer
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
	ldr r2, _0225EBC0 ; =0x000001B5
	mov r3, #5
	bl LoadUserFrameGfx2
	add r0, r5, #0
	ldr r2, _0225EBC0 ; =0x000001B5
	add r0, #0x44
	mov r1, #1
	mov r3, #5
	bl DrawFrameAndWindow2
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Options_GetTextFrameDelay
	mov r3, #0
	str r3, [sp]
	str r0, [sp, #4]
	mov r2, #0x62
	add r0, r5, #0
	str r3, [sp, #8]
	lsl r2, r2, #2
	ldr r2, [r5, r2]
	add r0, #0x44
	mov r1, #1
	bl AddTextPrinterParameterized
	mov r1, #0xa
	ldr r2, [r5, #0x14]
	lsl r1, r1, #6
	strb r0, [r2, r1]
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_0225EBC0: .word 0x000001B5
	thumb_func_end ov31_0225EB30


	thumb_func_start ov31_0225EBC4
ov31_0225EBC4: ; 0x0225EBC4
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x14
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
	add r0, r5, #0
	add r0, #0x44
	mov r1, #0xf
	bl FillWindowPixelBuffer
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
	ldr r2, _0225EC54 ; =0x000001B5
	mov r3, #5
	bl LoadUserFrameGfx2
	add r0, r5, #0
	ldr r2, _0225EC54 ; =0x000001B5
	add r0, #0x44
	mov r1, #1
	mov r3, #5
	bl DrawFrameAndWindow2
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Options_GetTextFrameDelay
	mov r3, #0
	str r3, [sp]
	str r0, [sp, #4]
	mov r2, #0x62
	add r0, r5, #0
	str r3, [sp, #8]
	lsl r2, r2, #2
	ldr r2, [r5, r2]
	add r0, #0x44
	mov r1, #1
	bl AddTextPrinterParameterized
	mov r1, #0xa
	ldr r2, [r5, #0x14]
	lsl r1, r1, #6
	strb r0, [r2, r1]
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_0225EC54: .word 0x000001B5
	thumb_func_end ov31_0225EBC4


	thumb_func_start ov31_0225EC58
ov31_0225EC58: ; 0x0225EC58
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r0, #0
	mov r0, #7
	str r0, [sp]
	mov r0, #0xb
	str r0, [sp, #4]
	mov r2, #4
	add r1, r4, #0
	str r2, [sp, #8]
	mov r3, #0xc
	str r3, [sp, #0xc]
	mov r0, #0xad
	str r0, [sp, #0x10]
	ldr r0, [r4, #4]
	add r1, #0xe4
	bl AddWindowParameterized
	mov r0, #0xe
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0xc
	str r0, [sp, #0xc]
	mov r0, #0xd9
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0xf4
	mov r2, #4
	mov r3, #0x10
	bl AddWindowParameterized
	mov r0, #0xe
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0xc
	str r0, [sp, #0xc]
	mov r1, #0xdf
	str r1, [sp, #0x10]
	add r1, #0x25
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #4
	mov r3, #0x14
	bl AddWindowParameterized
	mov r0, #0x15
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xc
	str r0, [sp, #0xc]
	mov r1, #0xe5
	str r1, [sp, #0x10]
	add r1, #0x2f
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #4
	mov r3, #0xe
	bl AddWindowParameterized
	mov r0, #0xd
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #5
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	mov r1, #0xf3
	str r1, [sp, #0x10]
	add r1, #0x31
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #4
	mov r3, #1
	bl AddWindowParameterized
	mov r0, #0xe
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0xc
	ldr r1, _0225ED98 ; =0x0000011B
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r1, #0x19
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #4
	mov r3, #0x17
	bl AddWindowParameterized
	mov r0, #1
	str r0, [sp]
	mov r0, #0x11
	str r0, [sp, #4]
	mov r2, #4
	str r2, [sp, #8]
	mov r3, #0xc
	ldr r1, _0225ED9C ; =0x00000133
	str r3, [sp, #0xc]
	str r1, [sp, #0x10]
	add r1, #0x11
	ldr r0, [r4, #4]
	add r1, r4, r1
	bl AddWindowParameterized
	add r0, r4, #0
	add r0, #0xe4
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0xf4
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x41
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x45
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x49
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x4d
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x51
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add sp, #0x14
	pop {r3, r4, pc}
	.balign 4, 0
_0225ED98: .word 0x0000011B
_0225ED9C: .word 0x00000133
	thumb_func_end ov31_0225EC58

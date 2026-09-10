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

	thumb_func_start ov31_0225E7D4
ov31_0225E7D4: ; 0x0225E7D4
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldr r3, [r4, #0x14]
	ldr r2, _0225E938 ; =0x00000286
	ldrsh r0, [r3, r2]
	cmp r0, #1
	ble _0225E7FA
	sub r0, r2, #3
	mov r1, #0x55
	sub r2, r2, #2
	lsl r1, r1, #2
	ldrb r0, [r3, r0]
	ldrh r2, [r3, r2]
	ldr r1, [r4, r1]
	mov r3, #0
	bl ov31_0225E4EC
	b _0225E80E
_0225E7FA:
	sub r0, r2, #3
	mov r1, #0x55
	sub r2, r2, #2
	lsl r1, r1, #2
	ldrb r0, [r3, r0]
	ldrh r2, [r3, r2]
	ldr r1, [r4, r1]
	mov r3, #0
	bl ov31_0225E4BC
_0225E80E:
	ldr r1, [r4, #0x14]
	ldr r0, _0225E93C ; =0x00000283
	ldrb r2, [r1, r0]
	cmp r2, #4
	bhi _0225E8CC
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0225E824: ; jump table
	.short _0225E82E - _0225E824 - 2 ; case 0
	.short _0225E8BC - _0225E824 - 2 ; case 1
	.short _0225E8CC - _0225E824 - 2 ; case 2
	.short _0225E85C - _0225E824 - 2 ; case 3
	.short _0225E8AC - _0225E824 - 2 ; case 4
_0225E82E:
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xf
	bl NewString_ReadMsgData
	add r5, r0, #0
	mov r0, #0xa1
	ldr r1, [r4, #0x14]
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	mov r1, #5
	mov r2, #0xb
	bl GetItemAttr
	add r2, r0, #0
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl BufferPocketName
	b _0225E8DA
_0225E85C:
	add r2, r0, #1
	ldrh r2, [r1, r2]
	add r1, r0, #0
	sub r1, #0x9e
	cmp r2, r1
	blo _0225E87E
	sub r0, #0x98
	cmp r2, r0
	bhi _0225E87E
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x31
	bl NewString_ReadMsgData
	add r5, r0, #0
	b _0225E8DA
_0225E87E:
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xf
	bl NewString_ReadMsgData
	add r5, r0, #0
	mov r0, #0xa1
	ldr r1, [r4, #0x14]
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	mov r1, #5
	mov r2, #0xb
	bl GetItemAttr
	add r2, r0, #0
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl BufferPocketName
	b _0225E8DA
_0225E8AC:
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x31
	bl NewString_ReadMsgData
	add r5, r0, #0
	b _0225E8DA
_0225E8BC:
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x15
	bl NewString_ReadMsgData
	add r5, r0, #0
	b _0225E8DA
_0225E8CC:
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x17
	bl NewString_ReadMsgData
	add r5, r0, #0
_0225E8DA:
	mov r1, #0x55
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r1, #0x34
	ldr r1, [r4, r1]
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	add r0, r4, #0
	add r0, #0x44
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add r0, r4, #0
	ldr r2, _0225E940 ; =0x000001B5
	add r0, #0x44
	mov r1, #1
	mov r3, #5
	bl DrawFrameAndWindow2
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Options_GetTextFrameDelay
	mov r3, #0
	str r3, [sp]
	str r0, [sp, #4]
	ldr r0, _0225E944 ; =ov31_0225E948
	mov r2, #0x62
	str r0, [sp, #8]
	lsl r2, r2, #2
	add r0, r4, #0
	ldr r2, [r4, r2]
	add r0, #0x44
	mov r1, #1
	bl AddTextPrinterParameterized
	mov r1, #0xa
	ldr r2, [r4, #0x14]
	lsl r1, r1, #6
	strb r0, [r2, r1]
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_0225E938: .word 0x00000286
_0225E93C: .word 0x00000283
_0225E940: .word 0x000001B5
_0225E944: .word ov31_0225E948
	thumb_func_end ov31_0225E7D4

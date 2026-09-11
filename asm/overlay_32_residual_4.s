	.include "asm/macros.inc"
	.public _0225D5C0
	.public _0225D5C4
	.public _0225D5C8
	.public _0225D62C
	.public _0225D630
	.public _0225D796
	.public _0225D82C
	.public _0225D830
	.public _0225D980
	.public _0225D984
	.public _0225D99C
	.public _0225D9A0
	.public _0225D9D4
	.public _0225DA7C
	.public _0225DA80
	.public _0225DA84
	.public _0225DCB2
	.public _0225DCCC
	.public _0225DCD0
	.public _0225DD64
	.public _0225DDA0
	.public _0225DDA4
	.public _0225DDA8
	.public _0225DDDE
	.public _0225DDE6
	.public _0225DDF4
	.public _0225DE02
	.public _0225DE18
	.public _0225DE22
	.public _0225DE56
	.public _0225DE6C
	.public _0225DE8E
	.public _0225DEA0
	.public _0225DEA8
	.public _0225DEB2
	.public _0225DEBA
	.public _0225DEEA
	.public _0225DF0A
	.public _0225DF2A
	.public _0225DF3A
	.public _0225DF50
	.public _0225DF62
	.public _0225DF68
	.public _0225DF6C
	.public _0225DF70
	.public _0225DF74
	.public _0225DF78
	.public _0225DF7C
	.public _0225DFB0
	.public _0225DFBC
	.public _0225DFC6
	.public _0225DFCA
	.public _0225DFE4
	.public _0225E00C
	.public _0225E05E
	.public _0225E070
	.public _0225E092
	.public _0225E0A2
	.public _0225E0F4
	.public _0225E0F8
	.public _0225E158
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D60C
	.public ov32_0225D788
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.public ov32_0225E168
	.public ov32_0225E178
	.public ov32_0225E188
	.public ov32_0225E1A4
	.public ov32_0225E1C0
	.public ov32_0225E1DC
	.public ov32_0225E204
	.public ov32_0225E24C
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D60C
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D788
	.public ov32_0225D834
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF80
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.include "overlay_32.inc"
	.include "global.inc"

	.text
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D834
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DF80

	thumb_func_start ov32_0225D84C
ov32_0225D84C: ; 0x0225D84C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r0, #0x34
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x1c
	bl NewString_ReadMsgData
	add r6, r0, #0
	mov r0, #0
	add r1, r6, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	lsl r0, r0, #0x10
	lsr r7, r0, #0x10
	add r0, r5, #0
	add r0, #0x34
	bl GetWindowWidth
	lsl r0, r0, #3
	sub r1, r0, r7
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0xf
	lsr r4, r0, #0x10
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225D980 ; =0x00050600
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x34
	add r3, r4, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	mov r0, #4
	mov r1, #8
	bl String_New
	add r6, r0, #0
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x1b
	bl NewString_ReadMsgData
	mov r1, #0
	str r0, [sp, #0x10]
	mov r0, #0x52
	str r1, [sp]
	mov r3, #1
	str r3, [sp, #4]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r2, #4
	bl BufferIntegerAsString
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, [sp, #0x10]
	add r1, r6, #0
	bl StringExpandPlaceholders
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225D980 ; =0x00050600
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x34
	add r3, r4, r7
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x10]
	bl String_Delete
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x1b
	bl NewString_ReadMsgData
	mov r1, #0
	add r7, r0, #0
	mov r0, #0x52
	str r1, [sp]
	mov r3, #1
	ldr r2, _0225D984 ; =0x000002AA
	str r3, [sp, #4]
	ldrsb r2, [r5, r2]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, r2, #1
	bl BufferIntegerAsString
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r6, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	sub r0, r4, r0
	lsl r0, r0, #0x10
	mov r1, #0
	lsr r3, r0, #0x10
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225D980 ; =0x00050600
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x34
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r0, r5, #0
	add r0, #0x34
	bl CopyWindowPixelsToVram_TextMode
	add r5, #0x34
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0225D980: .word 0x00050600
_0225D984: .word 0x000002AA
	thumb_func_end ov32_0225D84C


	thumb_func_start ov32_0225D988
ov32_0225D988: ; 0x0225D988
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r7, r0, #0
	ldr r0, _0225DA7C ; =0x000002AB
	ldrb r0, [r7, r0]
	cmp r0, #0
	bne _0225D99C
	add r5, r7, #0
	add r5, #0x44
	b _0225D9A0
_0225D99C:
	add r5, r7, #0
	add r5, #0xc4
_0225D9A0:
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0x1e
	bl NewString_ReadMsgData
	str r0, [sp, #0x18]
	mov r0, #0x40
	mov r1, #8
	bl String_New
	str r0, [sp, #0x14]
	mov r0, #8
	bl PlayerProfile_New
	str r0, [sp, #0x1c]
	add r0, r5, #0
	bl GetWindowWidth
	lsl r1, r0, #3
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0xf
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	mov r4, #0
_0225D9D4:
	ldr r1, _0225DA80 ; =0x000002AA
	ldr r0, [r7, #0x14]
	ldrsb r1, [r7, r1]
	lsl r1, r1, #3
	add r1, r4, r1
	bl sub_0202C254
	add r1, r0, #0
	ldr r0, [sp, #0x1c]
	bl Save_Profile_PlayerName_Set
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	ldr r2, [sp, #0x1c]
	mov r1, #0
	bl BufferPlayersName
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	bl StringExpandPlaceholders
	lsl r0, r4, #4
	str r0, [sp, #0x20]
	add r0, r5, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	ldr r1, [sp, #0x14]
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225DA84 ; =0x00050600
	lsr r6, r3, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x20]
	ldr r3, [sp, #0x10]
	ldr r2, [sp, #0x14]
	add r0, r5, r0
	mov r1, #4
	sub r3, r3, r6
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x20]
	add r0, r5, r0
	bl CopyWindowPixelsToVram_TextMode
	ldr r0, [sp, #0x20]
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #8
	blo _0225D9D4
	ldr r0, [sp, #0x1c]
	bl Heap_Free
	ldr r0, [sp, #0x14]
	bl String_Delete
	ldr r0, [sp, #0x18]
	bl String_Delete
	ldr r1, _0225DA7C ; =0x000002AB
	mov r0, #1
	ldrb r2, [r7, r1]
	eor r0, r2
	strb r0, [r7, r1]
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_0225DA7C: .word 0x000002AB
_0225DA80: .word 0x000002AA
_0225DA84: .word 0x00050600
	thumb_func_end ov32_0225D988


	thumb_func_start ov32_0225DA88
ov32_0225DA88: ; 0x0225DA88
	push {r3, r4, r5, lr}
	add r4, r1, #0
	mov r1, #0x15
	add r5, r0, #0
	lsl r1, r1, #4
	mov r0, #4
	add r1, r5, r1
	mov r2, #8
	bl G2dRenderer_Init
	mov r1, #0x53
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #4
	mov r2, #1
	add r0, r5, r0
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	add r0, r5, #0
	bl ov32_0225DADC
	add r0, r5, #0
	add r1, r4, #0
	bl ov32_0225DC68
	pop {r3, r4, r5, pc}
	thumb_func_end ov32_0225DA88

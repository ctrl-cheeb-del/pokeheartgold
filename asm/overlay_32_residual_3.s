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

	thumb_func_start ov32_0225D788
ov32_0225D788: ; 0x0225D788
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r6, r5, #0
	ldr r7, _0225D82C ; =ov32_0225E24C
	mov r4, #0
	add r6, #0x24
_0225D796:
	lsl r1, r4, #4
	lsl r2, r4, #3
	ldr r0, [r5]
	add r1, r6, r1
	add r2, r7, r2
	bl AddWindow
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0x12
	blo _0225D796
	add r0, r5, #0
	add r0, #0x24
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x1d
	bl NewString_ReadMsgData
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0x24
	bl GetWindowWidth
	lsl r1, r0, #3
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0xf
	lsr r4, r0, #0x10
	mov r0, #4
	add r1, r6, #0
	mov r2, #0
	bl FontID_String_GetWidth
	lsr r0, r0, #1
	sub r0, r4, r0
	lsl r0, r0, #0x10
	mov r1, #0
	lsr r3, r0, #0x10
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225D830 ; =0x00050600
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #0xc]
	add r0, #0x24
	mov r1, #4
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	add r0, r5, #0
	add r0, #0x24
	bl CopyWindowPixelsToVram_TextMode
	add r0, r5, #0
	add r0, #0x24
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	bl ov32_0225D84C
	add r0, r5, #0
	bl ov32_0225D988
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225D82C: .word ov32_0225E24C
_0225D830: .word 0x00050600
	thumb_func_end ov32_0225D788

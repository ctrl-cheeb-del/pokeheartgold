	.include "asm/macros.inc"
	.public ov29_0225D520
	.public ov29_0225D5EC
	.public ov29_0225D61C
	.public ov29_0225D620
	.public ov29_0225D648
	.public ov29_0225D6B4
	.public ov29_0225D6C8
	.public ov29_0225D714
	.public ov29_0225D7D4
	.public ov29_0225D7F0
	.public ov29_0225D828
	.public ov29_0225D840
	.public ov29_0225D864
	.public ov29_0225D880
	.public ov29_0225D910
	.public ov29_0225D970
	.public ov29_0225D9C8
	.public ov29_0225DB38
	.public ov29_0225DB7C
	.public ov29_0225DB9C
	.public ov29_0225DBF0
	.public ov29_0225DC34
	.public ov29_0225DC44
	.public ov29_0225DC48
	.public ov29_0225DC50
	.public ov29_0225DC84
	.public ov29_0225DCD0
	.public ov29_0225DEB8
	.public ov29_0225DEF4
	.public ov29_0225DF18
	.public ov29_0225DF74
	.public ov29_0225E028
	.public ov29_0225E078
	.public ov29_0225E0E0
	.public ov29_0225E114
	.public ov29_0225E115
	.public ov29_0225E11D
	.public ov29_0225E129
	.public ov29_0225E13C
	.public ov29_0225E14C
	.public ov29_0225E160
	.public ov29_0225E178
	.public ov29_0225E190
	.public ov29_0225E1AC
	.public ov29_0225E1C8
	.public ov29_0225E1E4
	.public ov29_0225E200
	.public ov29_0225E21C
	.public ov29_0225E220
	.public ov29_0225E224
	.public ov29_0225E228
	.public ov29_0225E22C
	.public ov29_0225E230
	.public ov29_0225E234
	.public ov29_0225E238
	.public ov29_0225E23C
	.public ov29_0225E240
	.public ov29_0225E244
	.public ov29_0225E248
	.public ov29_0225E280
	.public ov29_0225E2E8
	.public ov29_0225E2EC
	.public ov29_0225E2F0
	.public ov29_0225E2F4
	.public ov29_0225E2FC
	.include "overlay_29.inc"
	.include "global.inc"

	.text

	thumb_func_start ov29_0225D714
ov29_0225D714: ; 0x0225D714
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r0, [sp, #0x10]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xc4
	mov r3, #8
	bl NewMsgDataFromNarc
	str r0, [sp, #0x18]
	mov r0, #4
	mov r1, #8
	bl FontID_Alloc
	mov r1, #0x1a
	ldr r0, [sp, #0x10]
	lsl r1, r1, #4
	mov r6, #0
	add r5, r0, r1
_0225D73A:
	ldr r0, [sp, #0x10]
	ldr r2, _0225D7CC ; =ov29_0225E178
	lsl r4, r6, #4
	lsl r3, r6, #3
	ldr r0, [r0]
	add r1, r5, r4
	add r2, r2, r3
	bl AddWindow
	add r0, r5, r4
	mov r1, #0
	bl FillWindowPixelBuffer
	add r1, r6, #0
	ldr r0, [sp, #0x18]
	add r1, #0x18
	bl NewString_ReadMsgData
	add r7, r0, #0
	add r0, r5, r4
	bl GetWindowWidth
	lsl r1, r0, #3
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0xf
	lsr r0, r0, #0x10
	str r0, [sp, #0x14]
	mov r0, #4
	add r1, r7, #0
	mov r2, #0
	bl FontID_String_GetWidth
	lsr r1, r0, #1
	ldr r0, [sp, #0x14]
	add r2, r7, #0
	sub r0, r0, r1
	lsl r0, r0, #0x10
	lsr r3, r0, #0x10
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225D7D0 ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r5, r4
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r5, r4
	bl CopyWindowPixelsToVram_TextMode
	add r0, r5, r4
	bl ScheduleWindowCopyToVram
	add r0, r6, #1
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	cmp r6, #3
	blo _0225D73A
	mov r0, #4
	bl FontID_Release
	ldr r0, [sp, #0x18]
	bl DestroyMsgData
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0225D7CC: .word ov29_0225E178
_0225D7D0: .word 0x000F0E00
	thumb_func_end ov29_0225D714

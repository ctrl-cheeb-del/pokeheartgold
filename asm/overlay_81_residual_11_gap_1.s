	.include "asm/macros.inc"
	.public FillWindowPixelBuffer
	.public GetWindowWidth
	.public ov81_022430B4
	.public CopyWindowPixelsToVram_TextMode
	.text

	thumb_func_start ov81_02241524
ov81_02241524: ; 0x02241524
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #1
	lsl r0, r0, #8
	add r0, r4, r0
	mov r1, #2
	bl FillWindowPixelBuffer
	mov r0, #0x11
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #2
	bl FillWindowPixelBuffer
	mov r0, #0x12
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #2
	bl FillWindowPixelBuffer
	mov r0, #0x13
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #2
	bl FillWindowPixelBuffer
	mov r0, #1
	lsl r0, r0, #8
	add r0, r4, r0
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _0224164C ; =0x000F0E02
	lsl r5, r3, #3
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	lsr r3, r5, #0x1f
	add r0, #0xfe
	add r3, r5, r3
	ldr r1, [r4, #0x1c]
	add r0, r4, r0
	mov r2, #5
	asr r3, r3, #1
	bl ov81_022430B4
	mov r0, #0x11
	lsl r0, r0, #4
	add r0, r4, r0
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _0224164C ; =0x000F0E02
	lsl r5, r3, #3
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #0x11
	lsr r3, r5, #0x1f
	lsl r0, r0, #4
	add r3, r5, r3
	ldr r1, [r4, #0x1c]
	add r0, r4, r0
	mov r2, #6
	asr r3, r3, #1
	bl ov81_022430B4
	mov r0, #0x12
	lsl r0, r0, #4
	add r0, r4, r0
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _0224164C ; =0x000F0E02
	lsl r5, r3, #3
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #0x12
	lsr r3, r5, #0x1f
	lsl r0, r0, #4
	add r3, r5, r3
	ldr r1, [r4, #0x1c]
	add r0, r4, r0
	mov r2, #8
	asr r3, r3, #1
	bl ov81_022430B4
	mov r0, #0x13
	lsl r0, r0, #4
	add r0, r4, r0
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _0224164C ; =0x000F0E02
	lsl r5, r3, #3
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #0x13
	lsr r3, r5, #0x1f
	lsl r0, r0, #4
	add r3, r5, r3
	ldr r1, [r4, #0x1c]
	add r0, r4, r0
	mov r2, #7
	asr r3, r3, #1
	bl ov81_022430B4
	mov r0, #1
	lsl r0, r0, #8
	add r0, r4, r0
	bl CopyWindowPixelsToVram_TextMode
	mov r0, #0x11
	lsl r0, r0, #4
	add r0, r4, r0
	bl CopyWindowPixelsToVram_TextMode
	mov r0, #0x12
	lsl r0, r0, #4
	add r0, r4, r0
	bl CopyWindowPixelsToVram_TextMode
	mov r0, #0x13
	lsl r0, r0, #4
	add r0, r4, r0
	bl CopyWindowPixelsToVram_TextMode
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0224164C: .word 0x000F0E02
	thumb_func_end ov81_02241524

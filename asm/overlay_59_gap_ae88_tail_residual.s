	.include "asm/macros.inc"
	.public ov59_0223C954
	.public AddTextPrinterParameterizedWithColor
	.public BeginNormalPaletteFade
	.public ClearWindowTilemapAndScheduleTransfer
	.public FillWindowPixelBuffer
	.public IsPaletteFadeFinished
	.public PlaySE
	.public ReadMsgDataIntoString
	.public ScheduleWindowCopyToVram
	.public Sprite_IsAnimated
	.public Sprite_ResetAnimCtrlState
	.public Sprite_SetAnimCtrlSeq
	.public Sprite_SetDrawFlag
	.public ov59_0223B358
	.public ov59_0223B3B0
	.public ov59_0223BBB0
	.public ov59_0223BBD4
	.public ov59_0223C054
	.public ov59_0223C138
	.text
thumb_func_start ov59_0223AEB0
ov59_0223AEB0: ; 0x0223AEB0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r4, r0, #0
	cmp r1, #3
	bhi _0223AF74
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223AEC6: ; jump table
	.short _0223AF5C - _0223AEC6 - 2 ; case 0
	.short _0223AF5C - _0223AEC6 - 2 ; case 1
	.short _0223AEF4 - _0223AEC6 - 2 ; case 2
	.short _0223AECE - _0223AEC6 - 2 ; case 3
_0223AECE:
	mov r0, #0x71
	lsl r0, r0, #2
	add r0, r4, r0
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #0x26
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0x99
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
_0223AEF4:
	mov r0, #0x71
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r6, _0223AF78 ; =ov59_0223C954
	mov r7, #0
	mov r5, #4
	str r4, [sp, #0x10]
_0223AF08:
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x68]
	add r1, r7, #1
	bl ReadMsgDataIntoString
	str r5, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [r6]
	mov r1, #4
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r0, #0x71
	lsl r0, r0, #2
	ldr r2, [r4, #0x68]
	add r0, r4, r0
	mov r3, #0
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0x26
	ldr r1, [sp, #0x10]
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [sp, #0x10]
	add r7, r7, #1
	add r0, r0, #4
	add r6, r6, #4
	add r5, #0x18
	str r0, [sp, #0x10]
	cmp r7, #2
	blt _0223AF08
	mov r0, #0x71
	lsl r0, r0, #2
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
_0223AF5C:
	mov r0, #0x26
	lsl r0, r0, #4
	add r5, r4, r0
	lsl r4, r1, #2
	lsl r1, r1, #1
	ldr r0, [r5, r4]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [r5, r4]
	bl Sprite_ResetAnimCtrlState
_0223AF74:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0223AF78: .word ov59_0223C954
	thumb_func_end ov59_0223AEB0
	thumb_func_start ov59_0223AF7C
ov59_0223AF7C: ; 0x0223AF7C
	push {r3, r4, lr}
	sub sp, #4
	mov r1, #0
	str r1, [sp]
	add r1, sp, #0
	add r4, r0, #0
	bl ov59_0223B3B0
	ldr r1, [sp]
	cmp r1, #0
	bne _0223AF98
	add r0, r4, #0
	bl ov59_0223B358
_0223AF98:
	add sp, #4
	pop {r3, r4, pc}
	thumb_func_end ov59_0223AF7C

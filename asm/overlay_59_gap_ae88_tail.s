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
	thumb_func_start ov59_0223AF9C
ov59_0223AF9C: ; 0x0223AF9C
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	add r0, #0x42
	ldrh r0, [r0]
	cmp r0, #5
	bls _0223AFAC
	b _0223B0FA
_0223AFAC:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223AFB8: ; jump table
	.short _0223AFC4 - _0223AFB8 - 2 ; case 0
	.short _0223B024 - _0223AFB8 - 2 ; case 1
	.short _0223B05C - _0223AFB8 - 2 ; case 2
	.short _0223B084 - _0223AFB8 - 2 ; case 3
	.short _0223B0B4 - _0223AFB8 - 2 ; case 4
	.short _0223B0CC - _0223AFB8 - 2 ; case 5
_0223AFC4:
	mov r0, #0x26
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl Sprite_IsAnimated
	cmp r0, #0
	beq _0223AFD8
	add sp, #0xc
	mov r0, #0
	pop {r3, r4, pc}
_0223AFD8:
	add r0, r4, #0
	mov r1, #3
	bl ov59_0223AEB0
	add r0, r4, #0
	bl ov59_0223BBB0
	add r0, r4, #0
	mov r1, #0
	bl ov59_0223BBD4
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xa
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_ResetAnimCtrlState
	ldr r0, _0223B114 ; =0x00000921
	bl PlaySE
	add r0, r4, #0
	add r0, #0x42
	ldrh r0, [r0]
	add r4, #0x42
	add r0, r0, #1
	strh r0, [r4]
	b _0223B10E
_0223B024:
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_IsAnimated
	cmp r0, #0
	beq _0223B038
	add sp, #0xc
	mov r0, #0
	pop {r3, r4, pc}
_0223B038:
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xb
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_ResetAnimCtrlState
	add r0, r4, #0
	add r0, #0x42
	ldrh r0, [r0]
	add r4, #0x42
	add r0, r0, #1
	strh r0, [r4]
	b _0223B10E
_0223B05C:
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_IsAnimated
	cmp r0, #0
	beq _0223B070
	add sp, #0xc
	mov r0, #0
	pop {r3, r4, pc}
_0223B070:
	add r0, r4, #0
	bl ov59_0223C054
	add r0, r4, #0
	add r0, #0x42
	ldrh r0, [r0]
	add r4, #0x42
	add r0, r0, #1
	strh r0, [r4]
	b _0223B10E
_0223B084:
	add r0, r4, #0
	add r0, #0x4f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0223B094
	add sp, #0xc
	mov r0, #0
	pop {r3, r4, pc}
_0223B094:
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	bl ov59_0223C138
	add r0, r4, #0
	add r0, #0x42
	ldrh r0, [r0]
	add r4, #0x42
	add r0, r0, #1
	strh r0, [r4]
	b _0223B10E
_0223B0B4:
	add r0, r4, #0
	add r0, #0x4f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0223B0C4
	add sp, #0xc
	mov r0, #0
	pop {r3, r4, pc}
_0223B0C4:
	mov r0, #6
	add r4, #0x42
	strh r0, [r4]
	b _0223B10E
_0223B0CC:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0223B10E
	mov r0, #6
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #1
	str r0, [sp, #8]
	ldr r3, _0223B118 ; =0x00007FFF
	mov r0, #0
	add r2, r1, #0
	bl BeginNormalPaletteFade
	add r0, r4, #0
	add r0, #0x42
	ldrh r0, [r0]
	add r4, #0x42
	add r0, r0, #1
	strh r0, [r4]
	b _0223B10E
_0223B0FA:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0223B10E
	mov r0, #0
	add r4, #0x42
	strh r0, [r4]
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_0223B10E:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_0223B114: .word 0x00000921
_0223B118: .word 0x00007FFF
	thumb_func_end ov59_0223AF9C

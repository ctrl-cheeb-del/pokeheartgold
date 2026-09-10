	.include "asm/macros.inc"
	.include "overlay_64.inc"
	.include "global.inc"
	.public HallOfFameShowcase_Init
	.public HallOfFameShowcase_Main
	.public _021E6E7C
	.public ov64_021E5B10
	.public ov64_021E5CD0
	.public ov64_021E607C
	.public ov64_021E6170
	.public ov64_021E62C8
	.public ov64_021E652C
	.public ov64_021E677C
	.public ov64_021E6B84
	.public ov64_021E6C1C
	.public ov64_021E6E88
	.public ov64_021E6E98
	.public ov64_021E6EA8
	.public ov64_021E6EB8
	.public ov64_021E6ECC
	.public ov64_021E6ECE
	.public ov64_021E6EE4
	.public ov64_021E6EFC
	.public ov64_021E6F18
	.public ov64_021E6F34
	.public ov64_021E6F50
	.public ov64_021E6F6C
	.public ov64_021E6F8C
	.public ov64_021E6FAC
	.public ov64_021E6FD4
	.public ov64_021E7008
	.public ov64_021E7040
	.public ov64_021E70C8
	.public ov64_021E70FC
	.public ov64_021E73A0
	.public ov64_021E73D4
	.public ov64_021E7408
	.public ov64_021E743C


	.text
	.public HallOfFameShowcase_Exit
	.public ov64_021E5A88
	.public ov64_021E5AAC
	.public ov64_021E5AC8
	.public ov64_021E5AE4
	.public ov64_021E5B00
	.public ov64_021E5CA4
	.public ov64_021E6010
	.public ov64_021E602C
	.public ov64_021E605C
	.public ov64_021E6118
	.public ov64_021E620C
	.public ov64_021E622C
	.public ov64_021E6260
	.public ov64_021E6270
	.public ov64_021E6274
	.public ov64_021E6278
	.public ov64_021E6280
	.public ov64_021E6288
	.public ov64_021E62A8
	.public ov64_021E64F8
	.public ov64_021E6754
	.public ov64_021E6BD8
	.public ov64_021E6E30

	thumb_func_start ov64_021E652C
ov64_021E652C: ; 0x021E652C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	mov r2, #0x6d
	add r5, r0, #0
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	add r0, r0, r1
	str r0, [r5, r2]
	ldr r1, [r5, r2]
	cmp r1, #0
	bge _021E6548
	mov r0, #0
	str r0, [r5, r2]
	b _021E6554
_021E6548:
	add r0, r2, #4
	ldr r0, [r5, r0]
	cmp r1, r0
	blt _021E6554
	sub r0, r0, #1
	str r0, [r5, r2]
_021E6554:
	mov r1, #0x6e
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	cmp r0, #1
	bne _021E6576
	sub r1, #0x44
	ldr r0, [r5, r1]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x5e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _021E65BA
_021E6576:
	sub r0, r1, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _021E658A
	sub r1, #0x44
	ldr r0, [r5, r1]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _021E6594
_021E658A:
	sub r1, #0x44
	ldr r0, [r5, r1]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
_021E6594:
	mov r0, #0x6d
	lsl r0, r0, #2
	add r1, r0, #4
	ldr r1, [r5, r1]
	ldr r2, [r5, r0]
	sub r1, r1, #1
	cmp r2, r1
	bne _021E65B0
	sub r0, #0x3c
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _021E65BA
_021E65B0:
	sub r0, #0x3c
	ldr r0, [r5, r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
_021E65BA:
	mov r1, #0x6d
	lsl r1, r1, #2
	ldr r0, [r5]
	ldr r1, [r5, r1]
	bl Save_HOF_TranslateRecordIdx
	mov r1, #0x1b
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r1, r1, #4
	ldr r0, [r5]
	ldr r1, [r5, r1]
	bl Save_HOF_RecordCountMons
	mov r1, #0x6b
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r1, #0x1a
	ldrh r0, [r5, r1]
	cmp r0, #0
	bne _021E65F0
	ldr r0, _021E6744 ; =0x0000DCC2
	mov r7, #2
	str r0, [sp, #0x14]
	mov r0, #7
	str r0, [sp, #0x10]
	b _021E65FA
_021E65F0:
	ldr r0, _021E6748 ; =0x0000DCC8
	mov r7, #8
	str r0, [sp, #0x14]
	mov r0, #0xf
	str r0, [sp, #0x10]
_021E65FA:
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r4, #0
	cmp r0, #0
	bls _021E6656
	lsl r0, r7, #2
	add r6, r5, r0
_021E660A:
	mov r1, #0x6d
	lsl r1, r1, #2
	mov r3, #0x62
	lsl r3, r3, #2
	ldr r0, [r5]
	ldr r1, [r5, r1]
	add r2, r4, #0
	add r3, r5, r3
	bl Save_HOF_GetMonStatsByIndexPair
	ldr r0, [sp, #0x14]
	add r1, r7, #0
	add r3, r0, r4
	add r0, r5, #0
	add r2, r4, #0
	str r3, [sp]
	bl ov64_021E6C1C
	mov r0, #0x4e
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl ManagedSprite_SetAnimationFrame
	mov r0, #0x4e
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r4, r4, #1
	add r7, r7, #1
	add r6, r6, #4
	cmp r4, r0
	blo _021E660A
_021E6656:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl GridInputHandler_GetNextInput
	add r1, r0, #0
	add r0, r5, #0
	bl ov64_021E677C
	ldr r0, [sp, #0x10]
	add r4, r5, #0
	add r4, #8
	lsl r6, r0, #4
	add r0, r4, r6
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r2, #0x46
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	add r2, #0x10
	ldr r2, [r5, r2]
	mov r1, #0
	bl ReadMsgDataIntoString
	mov r1, #0x6d
	lsl r1, r1, #2
	ldr r0, [r5]
	ldr r1, [r5, r1]
	bl Save_HOF_TranslateRecordIdx
	mov r1, #0
	add r2, r0, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r3, #4
	bl BufferIntegerAsString
	mov r1, #0x6d
	lsl r1, r1, #2
	ldr r0, [r5]
	ldr r1, [r5, r1]
	add r2, sp, #0x18
	bl Save_HOF_GetClearDate
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x49
	lsl r0, r0, #2
	mov r2, #0x7d
	ldr r3, [sp, #0x18]
	lsl r2, r2, #4
	add r2, r3, r2
	ldr r0, [r5, r0]
	mov r3, #4
	bl BufferIntegerAsString
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, [sp, #0x1c]
	mov r1, #2
	bl BufferMonthNameAbbr
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, [sp, #0x20]
	mov r1, #3
	mov r3, #2
	bl BufferIntegerAsString
	mov r2, #0x49
	lsl r2, r2, #2
	add r1, r2, #0
	ldr r0, [r5, r2]
	add r1, #8
	add r2, r2, #4
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl StringExpandPlaceholders
	mov r1, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E674C ; =0x000F0200
	add r2, #0x2d
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r4, r6
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, r6
	bl CopyWindowPixelsToVram_TextMode
	add r0, r4, r6
	bl ScheduleWindowCopyToVram
	ldr r1, _021E6750 ; =0x000001C6
	mov r0, #1
	ldrh r2, [r5, r1]
	eor r0, r2
	strh r0, [r5, r1]
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6744: .word 0x0000DCC2
_021E6748: .word 0x0000DCC8
_021E674C: .word 0x000F0200
_021E6750: .word 0x000001C6
	thumb_func_end ov64_021E652C

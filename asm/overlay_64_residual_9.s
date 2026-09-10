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

	thumb_func_start ov64_021E677C
ov64_021E677C: ; 0x021E677C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x60
	ldr r3, _021E6AC0 ; =ov64_021E6E98
	add r2, sp, #0x40
	add r5, r0, #0
	add r6, r1, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	cmp r6, r1
	blo _021E67A4
	add r0, r5, #0
	bl ov64_021E6754
	add sp, #0x60
	pop {r3, r4, r5, r6, r7, pc}
_021E67A4:
	sub r0, #0x74
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x4f
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x71
	lsl r0, r0, #2
	ldrh r0, [r5, r0]
	cmp r0, #0
	bne _021E67CA
	mov r4, #0
	str r4, [sp, #0x1c]
	b _021E67D0
_021E67CA:
	mov r0, #1
	str r0, [sp, #0x1c]
	mov r4, #8
_021E67D0:
	mov r3, #0x6d
	lsl r3, r3, #2
	ldr r1, [r5, r3]
	sub r3, #0x2c
	ldr r0, [r5]
	add r2, r6, #0
	add r3, r5, r3
	bl Save_HOF_GetMonStatsByIndexPair
	mov r1, #0x66
	lsl r1, r1, #2
	ldrh r0, [r5, r1]
	sub r1, #8
	ldr r1, [r5, r1]
	bl GetGenderBySpeciesAndPersonality
	mov r2, #0x61
	lsl r2, r2, #2
	str r0, [sp, #0x20]
	ldr r0, [r5, r2]
	add r2, #0x14
	ldrh r2, [r5, r2]
	add r1, sp, #0x3c
	bl sub_020729D8
	mov r3, #0x19
	lsl r3, r3, #4
	ldr r0, [r5, r3]
	ldr r1, [sp, #0x20]
	str r0, [sp]
	add r0, r3, #0
	add r0, #8
	add r3, #0xb
	lsl r1, r1, #0x18
	ldrh r0, [r5, r0]
	ldrb r3, [r5, r3]
	lsr r1, r1, #0x18
	mov r2, #2
	bl GetMonPicHeightBySpeciesGenderForm
	add r7, r0, #0
	ldr r0, [sp, #0x1c]
	add r3, sp, #0x3c
	mov r2, #0
	lsl r6, r0, #2
	mov r0, #0x4e
	lsl r0, r0, #2
	add r0, r5, r0
	str r0, [sp, #0x24]
	ldrsb r2, [r3, r2]
	add r7, #0x40
	mov r1, #0x40
	sub r2, r7, r2
	lsl r2, r2, #0x10
	ldr r0, [r0, r6]
	asr r2, r2, #0x10
	lsl r3, r1, #0xf
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	mov r1, #0x65
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	sub r1, r1, #4
	ldr r1, [r5, r1]
	bl CalcShininessByOtIdAndPersonality
	cmp r0, #0
	beq _021E685C
	mov r7, #1
	b _021E685E
_021E685C:
	mov r7, #0
_021E685E:
	mov r1, #0x32
	mov r0, #0x3b
	lsl r1, r1, #6
	bl Heap_AllocAtEnd
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #0x28]
	ldr r0, [r5, r1]
	add r1, #8
	str r0, [sp, #0x18]
	ldrh r0, [r5, r1]
	ldr r1, [sp, #0x18]
	bl GetGenderBySpeciesAndPersonality
	add r2, r0, #0
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	ldr r1, _021E6AC4 ; =0x0000019B
	str r0, [sp]
	ldrb r0, [r5, r1]
	sub r1, r1, #3
	mov r3, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	str r0, [sp, #8]
	ldrh r1, [r5, r1]
	add r0, sp, #0x50
	bl GetMonSpriteCharAndPlttNarcIdsEx
	ldr r0, [sp, #0x28]
	mov r2, #0x3b
	str r0, [sp]
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	add r0, #8
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #2
	str r1, [sp, #0xc]
	ldrh r0, [r5, r0]
	add r1, sp, #0x3c
	add r3, sp, #0x40
	str r0, [sp, #0x10]
	ldrh r0, [r1, #0x14]
	ldrh r1, [r1, #0x16]
	bl sub_02014510
	ldr r0, [sp, #0x24]
	ldr r0, [r0, r6]
	ldr r0, [r0]
	bl Sprite_GetImageProxy
	mov r1, #2
	bl NNS_G2dGetImageLocation
	add r1, r0, #0
	mov r2, #0x32
	ldr r0, [sp, #0x28]
	lsl r2, r2, #6
	bl ov64_021E5AC8
	ldr r0, [sp, #0x28]
	bl Heap_Free
	ldr r0, [sp, #0x24]
	ldr r0, [r0, r6]
	ldr r0, [r0]
	bl Sprite_GetPaletteProxy
	mov r1, #2
	bl NNS_G2dGetImagePaletteLocation
	add r3, r0, #0
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x3b
	str r0, [sp, #4]
	add r1, sp, #0x3c
	ldrh r0, [r1, #0x14]
	ldrh r1, [r1, #0x18]
	mov r2, #5
	bl GfGfxLoader_GXLoadPal
	ldr r0, [sp, #0x24]
	mov r1, #1
	ldr r0, [r0, r6]
	bl ManagedSprite_SetDrawFlag
	add r0, r5, #0
	str r0, [sp, #0x2c]
	add r0, #8
	mov r7, #0
	add r6, r4, #0
	str r0, [sp, #0x2c]
_021E6920:
	ldr r0, [sp, #0x2c]
	lsl r1, r6, #4
	add r0, r0, r1
	mov r1, #0
	bl FillWindowPixelBuffer
	add r7, r7, #1
	add r6, r6, #1
	cmp r7, #7
	blo _021E6920
	mov r1, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E6AC8 ; =0x000F0200
	add r3, r5, #0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r2, #0x89
	add r3, #8
	lsl r0, r4, #4
	add r0, r3, r0
	ldr r2, [r5, r2]
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	mov r2, #0x47
	lsl r2, r2, #2
	add r1, r2, #0
	add r1, #0x7c
	ldr r0, [r5, r2]
	add r2, #0xc
	ldrh r1, [r5, r1]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r1, #0
	add r0, r4, #1
	lsl r7, r0, #4
	add r6, r5, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E6AC8 ; =0x000F0200
	add r2, #0x29
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r6, #8
	ldr r2, [r5, r2]
	add r0, r6, r7
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	mov r2, #0x66
	lsl r2, r2, #2
	ldrh r0, [r5, r2]
	cmp r0, #0x1d
	beq _021E6A18
	cmp r0, #0x20
	beq _021E6A18
	ldr r0, [sp, #0x20]
	cmp r0, #0
	bne _021E69DA
	add r0, r2, #0
	sub r0, #0x80
	sub r2, #0x6c
	ldr r0, [r5, r0]
	ldr r2, [r5, r2]
	mov r1, #3
	bl ReadMsgDataIntoString
	mov r1, #0x4a
	lsl r1, r1, #2
	mov r0, #0
	ldr r1, [r5, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r3, r0, #0
	mov r1, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E6AC8 ; =0x000F0200
	add r2, #0x2d
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r6, r7
	add r3, #8
	bl AddTextPrinterParameterizedWithColor
	b _021E6A18
_021E69DA:
	cmp r0, #1
	bne _021E6A18
	add r0, r2, #0
	sub r0, #0x80
	sub r2, #0x6c
	ldr r0, [r5, r0]
	ldr r2, [r5, r2]
	mov r1, #4
	bl ReadMsgDataIntoString
	mov r1, #0x4a
	lsl r1, r1, #2
	mov r0, #0
	ldr r1, [r5, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r3, r0, #0
	mov r1, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E6AC8 ; =0x000F0200
	add r2, #0x2d
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r6, r7
	add r3, #8
	bl AddTextPrinterParameterizedWithColor
_021E6A18:
	mov r2, #0x46
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	add r2, #0x10
	ldr r2, [r5, r2]
	mov r1, #1
	bl ReadMsgDataIntoString
	mov r1, #0
	mov r2, #0x49
	str r1, [sp]
	mov r0, #1
	lsl r2, r2, #2
	str r0, [sp, #4]
	ldr r0, [r5, r2]
	add r2, #0x76
	ldrb r2, [r5, r2]
	mov r3, #3
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
	mov r0, #0x10
	str r0, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E6AC8 ; =0x000F0200
	mov r1, #0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r2, #0x2d
	ldr r2, [r5, r2]
	add r0, r6, r7
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	mov r2, #0x46
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	add r2, #0x10
	ldr r2, [r5, r2]
	mov r1, #2
	bl ReadMsgDataIntoString
	mov r1, #0
	add r0, r4, #2
	lsl r7, r0, #4
	add r6, r5, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E6AC8 ; =0x000F0200
	add r2, #0x29
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r6, #8
	ldr r2, [r5, r2]
	add r0, r6, r7
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	mov r1, #0x4a
	lsl r1, r1, #2
	mov r0, #0
	ldr r1, [r5, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0
	add r3, r0, #0
	str r1, [sp]
	mov r2, #0xff
	str r2, [sp, #4]
	ldr r0, _021E6AC8 ; =0x000F0200
	b _021E6ACC
	nop
_021E6AC0: .word ov64_021E6E98
_021E6AC4: .word 0x0000019B
_021E6AC8: .word 0x000F0200
_021E6ACC:
	add r2, #0x8d
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r6, r7
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0
	str r0, [sp, #0x14]
	add r0, r5, #0
	str r0, [sp, #0x30]
	add r0, #8
	str r5, [sp, #0x38]
	add r7, r4, #3
	str r0, [sp, #0x30]
_021E6AEA:
	mov r1, #0x67
	ldr r0, [sp, #0x38]
	lsl r1, r1, #2
	ldrh r1, [r0, r1]
	cmp r1, #0
	beq _021E6B3E
	mov r0, #0x12
	mov r2, #0x4a
	lsl r0, r0, #4
	lsl r2, r2, #2
	ldr r0, [r5, r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	mov r1, #0x4a
	lsl r1, r1, #2
	mov r0, #0
	ldr r1, [r5, r1]
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E6B80 ; =0x000F0200
	mov r2, #0x4a
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	lsl r2, r2, #2
	lsr r6, r3, #1
	mov r3, #0x38
	ldr r0, [sp, #0x30]
	lsl r1, r7, #4
	add r0, r0, r1
	ldr r2, [r5, r2]
	mov r1, #0
	sub r3, r3, r6
	bl AddTextPrinterParameterizedWithColor
_021E6B3E:
	ldr r0, [sp, #0x38]
	add r7, r7, #1
	add r0, r0, #2
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #4
	blo _021E6AEA
	add r6, r5, #0
	mov r7, #0
	add r6, #8
_021E6B56:
	lsl r0, r4, #4
	str r0, [sp, #0x34]
	add r0, r6, r0
	bl CopyWindowPixelsToVram_TextMode
	ldr r0, [sp, #0x34]
	add r0, r6, r0
	bl ScheduleWindowCopyToVram
	add r7, r7, #1
	add r4, r4, #1
	cmp r7, #7
	blo _021E6B56
	mov r1, #0x71
	lsl r1, r1, #2
	ldrh r2, [r5, r1]
	mov r0, #1
	eor r0, r2
	strh r0, [r5, r1]
	add sp, #0x60
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6B80: .word 0x000F0200
	thumb_func_end ov64_021E677C


	thumb_func_start ov64_021E6B84
ov64_021E6B84: ; 0x021E6B84
	push {r4, lr}
	mov r1, #7
	add r4, r0, #0
	lsl r1, r1, #6
	ldr r0, [r4, r1]
	cmp r0, #0
	bne _021E6BA6
	sub r0, r1, #4
	ldr r0, [r4, r0]
	sub r1, #0x88
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, r1]
	mov r1, #1
	bl ManagedSprite_SetPaletteOverride
	b _021E6BC8
_021E6BA6:
	cmp r0, #4
	bne _021E6BBE
	sub r0, r1, #4
	ldr r0, [r4, r0]
	sub r1, #0x88
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, r1]
	mov r1, #0
	bl ManagedSprite_SetPaletteOverride
	b _021E6BC8
_021E6BBE:
	cmp r0, #6
	bne _021E6BC8
	mov r0, #0
	str r0, [r4, r1]
	pop {r4, pc}
_021E6BC8:
	mov r0, #7
	lsl r0, r0, #6
	ldr r1, [r4, r0]
	add r1, r1, #1
	str r1, [r4, r0]
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov64_021E6B84

	.include "asm/macros.inc"
	.public _02260374
	.public ov115_0225F020
	.public ov115_0225F09C
	.public ov115_0225F0B4
	.public ov115_0225F158
	.public ov115_0225F1BC
	.public ov115_0225F220
	.public ov115_0225F704
	.public ov115_0225F728
	.public ov115_0225F74C
	.public ov115_0225F770
	.public ov115_0225F794
	.public ov115_0225F7B8
	.public ov115_0225F7DC
	.public ov115_0225F800
	.public ov115_0225F824
	.public ov115_0225F848
	.public ov115_0225F86C
	.public ov115_0225F890
	.public ov115_0225F8B4
	.public ov115_0225F8D8
	.public ov115_0225F8FC
	.public ov115_0225F920
	.public ov115_0225F944
	.public ov115_0225F968
	.public ov115_0225F978
	.public ov115_02260254
	.public ov115_022602C0
	.public ov115_022602E4
	.public ov115_02260308
	.public ov115_0226032C
	.public ov115_02260350
	.public ov115_02260388
	.public ov115_02260390
	.public ov115_02260398
	.public ov115_022603A0
	.public ov115_022603A8
	.public ov115_022603B0
	.public ov115_022603C4
	.public ov115_022603D8
	.public ov115_022603EC
	.public ov115_02260400
	.public ov115_02260414
	.public ov115_02260428
	.public ov115_0226043C
	.public ov115_02260450
	.public ov115_02260464
	.public ov115_02260478
	.public ov115_0226048C
	.public ov115_022604A0
	.public ov115_022604B4
	.public ov115_022604C8
	.public ov115_022604DC
	.include "overlay_115.inc"
	.include "global.inc"

	.text
	.public ov115_0225F09C
	.public ov115_0225F158
	.public ov115_0225F1BC
	.public ov115_0225F704
	.public ov115_0225F728
	.public ov115_0225F74C
	.public ov115_0225F770
	.public ov115_0225F794
	.public ov115_0225F7B8
	.public ov115_0225F7DC
	.public ov115_0225F800
	.public ov115_0225F824
	.public ov115_0225F848
	.public ov115_0225F86C
	.public ov115_0225F890
	.public ov115_0225F8B4
	.public ov115_0225F8D8
	.public ov115_0225F8FC
	.public ov115_0225F920
	.public ov115_0225F944
	.public ov115_0225F968
	.public ov115_022602C0
	.public ov115_022602E4
	.public ov115_02260308
	.public ov115_0226032C
	.public ov115_02260350

	thumb_func_start ov115_0225F220
ov115_0225F220: ; 0x0225F220
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	add r7, r1, #0
	ldr r1, [r5]
	add r6, r2, #0
	ldr r4, [r5, #0xc]
	cmp r1, #0xf
	bls _0225F234
	b _0225F6BC
_0225F234:
	add r2, r1, r1
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0225F240: ; jump table
	.short _0225F260 - _0225F240 - 2 ; case 0
	.short _0225F3C0 - _0225F240 - 2 ; case 1
	.short _0225F3D6 - _0225F240 - 2 ; case 2
	.short _0225F3E2 - _0225F240 - 2 ; case 3
	.short _0225F450 - _0225F240 - 2 ; case 4
	.short _0225F470 - _0225F240 - 2 ; case 5
	.short _0225F49E - _0225F240 - 2 ; case 6
	.short _0225F4EA - _0225F240 - 2 ; case 7
	.short _0225F518 - _0225F240 - 2 ; case 8
	.short _0225F536 - _0225F240 - 2 ; case 9
	.short _0225F5A2 - _0225F240 - 2 ; case 10
	.short _0225F5B8 - _0225F240 - 2 ; case 11
	.short _0225F5DE - _0225F240 - 2 ; case 12
	.short _0225F5F6 - _0225F240 - 2 ; case 13
	.short _0225F616 - _0225F240 - 2 ; case 14
	.short _0225F626 - _0225F240 - 2 ; case 15
_0225F260:
	mov r1, #0xa6
	add r0, r7, #0
	lsl r1, r1, #2
	bl Heap_Alloc
	mov r2, #0xa6
	str r0, [r5, #0xc]
	mov r1, #0
	lsl r2, r2, #2
	bl memset
	ldr r4, [r5, #0xc]
	mov r0, #0x20
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x20]
	mov r1, #0x10
	mov r2, #0
	mov r3, #0x40
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0xa
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	mov r2, #2
	str r2, [sp, #8]
	mov r1, #0x9f
	lsl r1, r1, #2
	str r2, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x10]
	add r1, r4, r1
	ldr r0, [r0, #8]
	mov r3, #0
	bl AddWindowParameterized
	mov r0, #0x9f
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldrh r0, [r6, #8]
	cmp r0, #0x17
	bne _0225F2D4
	ldr r0, [r5, #0x10]
	add r1, r7, #0
	ldr r0, [r0, #0xc]
	bl ov115_0225F1BC
	str r0, [sp, #0x14]
	b _0225F2DE
_0225F2D4:
	ldr r0, [r6, #4]
	add r1, r7, #0
	bl ov115_0225F158
	str r0, [sp, #0x14]
_0225F2DE:
	mov r1, #0
	str r1, [sp]
	ldr r0, _0225F62C ; =0x00010200
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x9f
	lsl r0, r0, #2
	ldr r2, [sp, #0x14]
	add r0, r4, r0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x14]
	bl String_Delete
	add r0, r4, #0
	add r0, #0x44
	mov r1, #8
	mov r2, #3
	bl ov01_021F05C4
	mov r0, #1
	str r0, [sp]
	ldrb r0, [r6, #0xd]
	mov r2, #6
	add r1, r4, #0
	str r0, [sp, #4]
	ldrb r0, [r6, #0xe]
	lsl r2, r2, #6
	add r1, #0x44
	str r0, [sp, #8]
	ldrb r0, [r6, #0xf]
	add r2, r4, r2
	str r0, [sp, #0xc]
	ldr r0, _0225F630 ; =0x000927C0
	str r0, [sp, #0x10]
	ldrb r3, [r6, #0xc]
	ldr r0, [r5, #0x20]
	bl ov01_021F0614
	mov r0, #1
	str r0, [sp]
	mov r0, #0x3c
	str r0, [sp, #4]
	mov r0, #0x3d
	str r0, [sp, #8]
	mov r0, #0x3e
	str r0, [sp, #0xc]
	ldr r0, _0225F634 ; =0x000927C1
	mov r2, #0x6d
	str r0, [sp, #0x10]
	add r1, r4, #0
	lsl r2, r2, #2
	ldr r0, [r5, #0x20]
	add r1, #0x44
	add r2, r4, r2
	mov r3, #0x3b
	bl ov01_021F0614
	mov r0, #0
	str r0, [sp]
	mov r1, #6
	str r0, [sp, #4]
	add r0, r4, #0
	lsl r1, r1, #6
	mov r2, #0x11
	mov r3, #0x42
	add r0, #0x44
	add r1, r4, r1
	lsl r2, r2, #0x10
	lsl r3, r3, #0xc
	bl ov01_021F0718
	mov r1, #0x7a
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0x4a
	mov r2, #0x7b
	lsl r0, r0, #0xc
	str r0, [sp]
	lsl r2, r2, #2
	add r0, r4, r2
	add r1, r4, #0
	sub r2, #0x38
	mov r3, #0x12
	add r1, #0x44
	add r2, r4, r2
	lsl r3, r3, #0xe
	str r7, [sp, #4]
	bl ov115_0225F020
	mov r0, #0
	str r0, [sp]
	mov r0, #0x7a
	lsl r0, r0, #2
	ldrb r2, [r6, #0xc]
	ldr r0, [r4, r0]
	add r1, r7, #0
	mov r3, #0xe
	bl ov115_02260254
	bl ov01_021F0B44
	str r0, [r4, #0x40]
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F3C0:
	mov r0, #1
	mov r1, #0x10
	str r0, [sp]
	add r2, r1, #0
	add r3, r5, #4
	bl ov01_021EFCF8
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F3D6:
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _0225F458
	add r0, r1, #1
	str r0, [r5]
	b _0225F6BC
_0225F3E2:
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r5, #0x10]
	ldr r0, [r0, #8]
	str r0, [sp, #8]
	mov r0, #3
	str r0, [sp, #0xc]
	ldrb r1, [r6, #0x12]
	ldrb r2, [r6, #0x11]
	ldrb r3, [r6, #0x10]
	ldr r0, [r5, #0x20]
	bl ov01_021F0454
	mov r0, #0xa3
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0x1f
	str r0, [sp, #4]
	mov r0, #0x17
	str r0, [sp, #8]
	ldr r1, [r4, #0x40]
	add r0, r5, #0
	mov r2, #6
	mov r3, #8
	bl ov01_021F0B78
	mov r0, #2
	mov r1, #0
	bl SetBgPriority
	mov r0, #3
	mov r1, #1
	bl SetBgPriority
	mov r0, #0
	mov r1, #2
	bl SetBgPriority
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F450:
	bl ov01_021EFE30
	cmp r0, #0
	bne _0225F45A
_0225F458:
	b _0225F6BC
_0225F45A:
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	ldr r0, [r4, #0x40]
	bl ov01_021F0B5C
	mov r0, #0xa5
	mov r1, #0xa
	lsl r0, r0, #2
	str r1, [r4, r0]
	b _0225F6BC
_0225F470:
	mov r0, #0xa5
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bge _0225F55E
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x7b
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov115_0225F0B4
	cmp r0, #1
	bne _0225F55E
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F49E:
	mov r0, #4
	str r0, [sp]
	mov r1, #0x11
	ldr r2, [r6]
	ldr r3, _0225F638 ; =0xFFFC0000
	add r0, r4, #0
	lsl r1, r1, #0x10
	bl ov01_021EFEC8
	mov r0, #0x7a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x7a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetPriority
	mov r2, #0x42
	ldr r1, [r4]
	add r0, sp, #0x1c
	lsl r2, r2, #0xc
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x7a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x1c
	bl Sprite_SetMatrix
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F4EA:
	add r0, r4, #0
	bl ov01_021EFF28
	mov r2, #0x42
	add r6, r0, #0
	ldr r1, [r4]
	add r0, sp, #0x1c
	lsl r2, r2, #0xc
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x7a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x1c
	bl Sprite_SetMatrix
	cmp r6, #1
	bne _0225F55E
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F518:
	add r0, r4, #0
	add r0, #0x18
	mov r1, #0
	mov r2, #0x10
	mov r3, #3
	bl ov01_021EFE34
	mov r0, #0xa5
	mov r1, #0xa
	lsl r0, r0, #2
	str r1, [r4, r0]
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F536:
	mov r0, #0xa5
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bge _0225F55E
	add r0, r4, #0
	add r0, #0x18
	bl ov01_021EFE44
	str r0, [sp, #0x18]
	add r0, r4, #0
	add r0, #0x18
	bl ov01_021F0DC8
	ldr r0, [sp, #0x18]
	cmp r0, #1
	beq _0225F560
_0225F55E:
	b _0225F6BC
_0225F560:
	mov r3, #0
	str r3, [sp]
	mov r0, #0x7a
	lsl r0, r0, #2
	ldrb r2, [r6, #0xc]
	ldr r0, [r4, r0]
	add r1, r7, #0
	bl ov115_02260254
	mov r0, #0xd
	mvn r0, r0
	mov r1, #0x21
	mov r2, #1
	bl SetBlendBrightness
	ldr r3, [r4]
	ldr r0, [r5, #0x10]
	asr r3, r3, #0xc
	sub r3, #0x5c
	ldr r0, [r0, #8]
	mov r1, #2
	mov r2, #0
	neg r3, r3
	bl ScheduleSetBgPosText
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F5A2:
	add r0, r4, #0
	add r0, #0x18
	mov r1, #0x10
	mov r2, #0
	mov r3, #3
	bl ov01_021EFE34
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F5B8:
	add r0, r4, #0
	add r0, #0x18
	bl ov01_021EFE44
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0x18
	bl ov01_021F0DC8
	cmp r6, #1
	bne _0225F6BC
	ldr r0, [r5]
	mov r1, #0x1a
	add r0, r0, #1
	str r0, [r5]
	mov r0, #0xa5
	lsl r0, r0, #2
	str r1, [r4, r0]
	b _0225F6BC
_0225F5DE:
	mov r0, #0xa5
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bge _0225F6BC
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F5F6:
	mov r0, #0xf
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #4
	mov r1, #0
	str r0, [sp, #8]
	ldr r3, _0225F63C ; =0x00007FFF
	mov r0, #3
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F616:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0225F6BC
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225F6BC
_0225F626:
	ldr r1, _0225F63C ; =0x00007FFF
	b _0225F640
	nop
_0225F62C: .word 0x00010200
_0225F630: .word 0x000927C0
_0225F634: .word 0x000927C1
_0225F638: .word 0xFFFC0000
_0225F63C: .word 0x00007FFF
_0225F640:
	mov r0, #1
	bl sub_0200FBF4
	ldr r1, [r5, #0x14]
	cmp r1, #0
	beq _0225F650
	mov r0, #1
	str r0, [r1]
_0225F650:
	mov r0, #0x7a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_Delete
	mov r0, #0x7b
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov115_0225F09C
	mov r1, #6
	add r0, r4, #0
	lsl r1, r1, #6
	add r0, #0x44
	add r1, r4, r1
	bl ov01_021F06EC
	mov r1, #0x6d
	add r0, r4, #0
	lsl r1, r1, #2
	add r0, #0x44
	add r1, r4, r1
	bl ov01_021F06EC
	add r0, r4, #0
	add r0, #0x44
	bl ov01_021F05F4
	mov r0, #0x9f
	lsl r0, r0, #2
	add r0, r4, r0
	bl RemoveWindow
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _0225F700 ; =0xFFFF1FFF
	and r0, r1
	str r0, [r2]
	mov r0, #0
	add r1, r0, #0
	mov r2, #1
	bl SetBlendBrightness
	ldr r0, [r5, #0x10]
	mov r2, #0
	ldr r0, [r0, #8]
	mov r1, #2
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add sp, #0x28
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0225F6BC:
	mov r3, #0xa3
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	cmp r0, #1
	bne _0225F6EC
	ldr r0, [r5, #0x10]
	add r3, r3, #4
	ldr r0, [r0, #8]
	ldr r3, [r4, r3]
	mov r1, #3
	mov r2, #0
	bl ScheduleSetBgPosText
	mov r3, #0x29
	lsl r3, r3, #4
	ldr r0, [r4, r3]
	add r0, #0x1e
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x17
	sub r1, r1, r2
	mov r0, #0x17
	ror r1, r0
	add r0, r2, r1
	str r0, [r4, r3]
_0225F6EC:
	ldr r0, [r5]
	cmp r0, #0xf
	beq _0225F6F8
	ldr r0, [r4, #0x44]
	bl SpriteList_RenderAndAnimateSprites
_0225F6F8:
	mov r0, #0
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225F700: .word 0xFFFF1FFF
	thumb_func_end ov115_0225F220

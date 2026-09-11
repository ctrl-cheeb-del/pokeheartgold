	.include "asm/macros.inc"
	.public _0223A05E
	.public _0223A0B4
	.public _0223A0B8
	.public _0223A0BC
	.public _0223A13C
	.public _0223A140
	.public _0223A16C
	.public _0223A170
	.public _0223A188
	.public _0223A194
	.public _0223A1BA
	.public _0223A3AA
	.public _0223A3BA
	.public _0223A3D4
	.public _0223A3E2
	.public _0223A410
	.public _0223A42E
	.public _0223A43E
	.public _0223A458
	.public _0223A468
	.public _0223A476
	.public _0223A48A
	.public _0223A4A6
	.public _0223A4AC
	.public _0223A4C4
	.public _0223A4D0
	.public _0223A4F4
	.public _0223A4FC
	.public _0223A4FE
	.public _0223A50C
	.public _0223A510
	.public _0223A514
	.public _0223A518
	.public _0223A51C
	.public _0223A520
	.public _0223A524
	.public _0223A528
	.public _0223A52C
	.public _0223A530
	.public _0223A534
	.public _0223A57A
	.public _0223A594
	.public _0223A5A8
	.public _0223A5B8
	.public _0223A5D8
	.public _0223A5E8
	.public _0223A5FA
	.public _0223A620
	.public _0223A628
	.public _0223A646
	.public _0223A660
	.public _0223A668
	.public _0223A6A6
	.public _0223A6B2
	.public _0223A6D6
	.public _0223A732
	.public _0223A784
	.public _0223A79E
	.public _0223A7C0
	.public _0223A7FA
	.public _0223A808
	.public _0223A818
	.public _0223A822
	.public _0223A862
	.public _0223A876
	.public _0223A8A8
	.public _0223A8BE
	.public _0223A914
	.public _0223AA3C
	.public _0223AA40
	.public _0223AA44
	.public _0223AA48
	.public _0223AA66
	.public _0223AA7E
	.public _0223AAAE
	.public _0223AAC8
	.public _0223AACC
	.public _0223AB00
	.public _0223AB28
	.public _0223AB60
	.public _0223AB88
	.public _0223ABA8
	.public _0223ABE4
	.public _0223ABFE
	.public _0223AC1C
	.public _0223AC20
	.public ov80_0223A00C
	.public ov80_0223A0C0
	.public ov80_0223A0EC
	.public ov80_0223A144
	.public ov80_0223A174
	.public ov80_0223A62C
	.public ov80_0223A748
	.public ov80_0223A75C
	.public ov80_0223A78C
	.public ov80_0223A81C
	.public ov80_0223A834
	.public ov80_0223A8C4
	.public ov80_0223A8D4
	.public ov80_0223A91C
	.public ov80_0223A938
	.public ov80_0223AA4C
	.public ov80_0223AA80
	.public ov80_0223AAD0
	.public ov80_0223AB34
	.public ov80_0223AB94
	.public ov80_0223DB30
	.public ov80_0223DB64
	.public ov80_0223DB98
	.include "overlay_80_0223A00C.inc"
	.include "global.inc"

    .text
	.public ov80_0223A00C
	.public ov80_0223A0C0
	.public ov80_0223A144
	.public ov80_0223A748
	.public ov80_0223A75C
	.public ov80_0223A78C
	.public ov80_0223A81C
	.public ov80_0223A8C4
	.public ov80_0223A8D4
	.public ov80_0223A91C
	.public ov80_0223AA4C
	.public ov80_0223AA80
	.public ov80_0223AAD0
	.public ov80_0223AB34
	.public ov80_0223AB94

	thumb_func_start ov80_0223A174
ov80_0223A174: ; 0x0223A174
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r4, r0, #0
	add r6, r1, #0
	ldr r1, [r4]
	add r7, r2, #0
	ldr r5, [r4, #0xc]
	cmp r1, #0x12
	bls _0223A188
	b _0223A620
_0223A188:
	add r2, r1, r1
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0223A194: ; jump table
	.short _0223A1BA - _0223A194 - 2 ; case 0
	.short _0223A410 - _0223A194 - 2 ; case 1
	.short _0223A42E - _0223A194 - 2 ; case 2
	.short _0223A43E - _0223A194 - 2 ; case 3
	.short _0223A458 - _0223A194 - 2 ; case 4
	.short _0223A468 - _0223A194 - 2 ; case 5
	.short _0223A476 - _0223A194 - 2 ; case 6
	.short _0223A48A - _0223A194 - 2 ; case 7
	.short _0223A4A6 - _0223A194 - 2 ; case 8
	.short _0223A4AC - _0223A194 - 2 ; case 9
	.short _0223A4C4 - _0223A194 - 2 ; case 10
	.short _0223A4D0 - _0223A194 - 2 ; case 11
	.short _0223A4F4 - _0223A194 - 2 ; case 12
	.short _0223A57A - _0223A194 - 2 ; case 13
	.short _0223A594 - _0223A194 - 2 ; case 14
	.short _0223A5A8 - _0223A194 - 2 ; case 15
	.short _0223A5B8 - _0223A194 - 2 ; case 16
	.short _0223A5D8 - _0223A194 - 2 ; case 17
	.short _0223A5E8 - _0223A194 - 2 ; case 18
_0223A1BA:
	add r0, r6, #0
	mov r1, #0x94
	bl Heap_Alloc
	str r0, [r4, #0xc]
	mov r1, #0
	mov r2, #0x94
	bl memset
	ldr r5, [r4, #0xc]
	ldr r0, [r4, #0x24]
	mov r1, #2
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _0223A50C ; =0x000007D4
	str r0, [sp, #0x14]
	ldr r0, [r4, #0x1c]
	ldr r2, [r4, #0x14]
	ldr r3, [r4, #0x18]
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r3, #0x59
	add r1, r0, #0
	lsl r3, r3, #2
	mov r2, #1
	lsl r2, r1
	ldr r0, [r4, r3]
	mov r1, #0x65
	orr r0, r2
	str r0, [r4, r3]
	mov r0, #4
	bl FontSystem_NewInit
	str r0, [r4, #0x30]
	ldr r2, _0223A510 ; =0x000002D9
	mov r0, #1
	mov r1, #0x1b
	add r3, r6, #0
	bl NewMsgDataFromNarc
	ldr r1, [r7]
	str r0, [sp, #0x20]
	bl NewString_ReadMsgData
	str r0, [sp, #0x24]
	ldr r0, _0223A514 ; =0x00010200
	add r1, r5, #0
	str r0, [sp]
	mov r3, #0
	ldr r0, _0223A50C ; =0x000007D4
	str r3, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x28
	ldrsh r0, [r4, r0]
	ldr r2, [sp, #0x24]
	add r1, #0x7c
	add r0, #0x74
	str r0, [sp, #0xc]
	mov r0, #0x2a
	ldrsh r0, [r4, r0]
	add r0, #0x58
	str r0, [sp, #0x10]
	str r3, [sp, #0x14]
	str r3, [sp, #0x18]
	add r0, r4, #0
	bl ov80_0223A62C
	ldr r0, [r5, #0x7c]
	mov r1, #0
	bl TextOBJ_SetSpritesDrawFlag
	ldr r0, [sp, #0x24]
	bl String_Delete
	ldr r0, [sp, #0x20]
	bl DestroyMsgData
	ldr r0, [r4, #0x24]
	mov r1, #2
	str r0, [sp]
	ldrb r0, [r7, #4]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _0223A518 ; =0x000007D2
	str r0, [sp, #0x14]
	ldr r0, [r4, #0x1c]
	ldr r2, [r4, #0x14]
	ldr r3, [r4, #0x18]
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r3, #0x16
	lsl r3, r3, #4
	str r0, [r4, r3]
	add r0, r3, #4
	ldr r2, [r4, r3]
	mov r1, #1
	ldr r0, [r4, r0]
	lsl r1, r2
	orr r1, r0
	add r0, r3, #4
	str r1, [r4, r0]
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0223A51C ; =0x000007DA
	str r0, [sp, #8]
	ldrb r3, [r7, #5]
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x24]
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0223A518 ; =0x000007D2
	str r0, [sp, #4]
	ldrb r3, [r7, #6]
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x24]
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0223A518 ; =0x000007D2
	str r0, [sp, #4]
	ldrb r3, [r7, #7]
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x24]
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #0xe
	str r0, [sp]
	mov r0, #0
	mov r2, #0x16
	str r0, [sp, #4]
	lsl r2, r2, #4
	ldr r2, [r4, r2]
	ldr r0, [r4, #0x1c]
	lsl r2, r2, #0x14
	mov r1, #2
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl PaletteData_BlendPalette
	ldr r0, [r4, #0x24]
	mov r1, #2
	str r0, [sp]
	mov r0, #0x3b
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _0223A520 ; =0x000007D3
	str r0, [sp, #0x14]
	ldr r0, [r4, #0x1c]
	ldr r2, [r4, #0x14]
	ldr r3, [r4, #0x18]
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	add r3, r0, #0
	mov r7, #0x59
	mov r0, #1
	lsl r7, r7, #2
	add r1, r0, #0
	lsl r1, r3
	ldr r2, [r4, r7]
	mov r3, #0xcc
	orr r1, r2
	str r1, [r4, r7]
	mov r1, #0
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, _0223A524 ; =0x000007DB
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x24]
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0223A520 ; =0x000007D3
	mov r3, #0xcd
	str r0, [sp, #4]
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x24]
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0223A520 ; =0x000007D3
	mov r3, #0xce
	str r0, [sp, #4]
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x24]
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r2, _0223A528 ; =ov80_0223DB30
	bl SpriteSystem_NewSprite
	add r1, r5, #0
	add r1, #0x90
	str r0, [r1]
	add r0, r5, #0
	add r0, #0x90
	ldr r0, [r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r0, r5, #0
	add r0, #0x90
	ldr r0, [r0]
	ldr r0, [r0]
	bl Sprite_TickFrame
	mov r0, #0x2a
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _0223A3AA
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	str r0, [sp, #0x1c]
	b _0223A3BA
_0223A3AA:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
	str r0, [sp, #0x1c]
_0223A3BA:
	mov r0, #0x28
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _0223A3D4
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0223A3E2
_0223A3D4:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0223A3E2:
	bl _ffix
	add r7, r0, #0
	ldr r0, [sp, #0x1c]
	bl _ffix
	add r5, #0x14
	add r1, r5, #0
	mov r2, #0x12
	mov r5, #0x52
	add r3, r0, #0
	lsl r2, r2, #0xe
	lsl r5, r5, #0xc
	str r6, [sp]
	add r0, r4, #0
	add r2, r7, r2
	add r3, r3, r5
	bl ov80_0223A78C
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A410:
	mov r0, #3
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0
	ldr r3, _0223A52C ; =0x00007FFF
	str r6, [sp, #8]
	add r1, r0, #0
	add r2, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A42E:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0223A4FC
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A43E:
	mov r0, #3
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _0223A52C ; =0x00007FFF
	str r6, [sp, #8]
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A458:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0223A4FC
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A468:
	mov r1, #0
	bl ov80_0223AA80
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A476:
	mov r0, #0x53
	lsl r0, r0, #2
	ldrb r0, [r4, r0]
	cmp r0, #1
	bne _0223A4FC
	add r0, r1, #1
	str r0, [r4]
	mov r0, #0xa
	str r0, [r5, #0x78]
	b _0223A620
_0223A48A:
	ldr r0, [r5, #0x78]
	sub r0, r0, #1
	str r0, [r5, #0x78]
	bpl _0223A4FC
	add r5, #0x14
	add r0, r5, #0
	bl ov80_0223A834
	cmp r0, #1
	bne _0223A4FC
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A4A6:
	add r0, r1, #1
	str r0, [r4]
	b _0223A620
_0223A4AC:
	mov r2, #0x56
	lsl r2, r2, #2
	add r1, r5, #0
	add r2, r4, r2
	bl ov80_0223AB94
	cmp r0, #1
	bne _0223A4FC
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A4C4:
	mov r0, #0xa
	str r0, [r5, #0x78]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A4D0:
	ldr r0, [r5, #0x78]
	sub r0, r0, #1
	str r0, [r5, #0x78]
	bpl _0223A4FC
	mov r0, #3
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r1, #0
	ldr r3, _0223A52C ; =0x00007FFF
	str r6, [sp, #8]
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A4F4:
	bl IsPaletteFadeFinished
	cmp r0, #0
	bne _0223A4FE
_0223A4FC:
	b _0223A620
_0223A4FE:
	mov r0, #0
	mov r2, #0x59
	str r0, [sp]
	lsl r2, r2, #2
	ldr r3, [r4, r2]
	ldr r2, _0223A530 ; =0x00003FFF
	b _0223A534
	.balign 4, 0
_0223A50C: .word 0x000007D4
_0223A510: .word 0x000002D9
_0223A514: .word 0x00010200
_0223A518: .word 0x000007D2
_0223A51C: .word 0x000007DA
_0223A520: .word 0x000007D3
_0223A524: .word 0x000007DB
_0223A528: .word ov80_0223DB30
_0223A52C: .word 0x00007FFF
_0223A530: .word 0x00003FFF
_0223A534:
	ldr r0, [r4, #0x1c]
	eor r2, r3
	lsl r2, r2, #0x10
	mov r1, #2
	lsr r2, r2, #0x10
	mov r3, #0xe
	bl PaletteData_BlendPalettes
	mov r0, #0
	str r0, [sp]
	mov r2, #0x16
	str r0, [sp, #4]
	lsl r2, r2, #4
	ldr r2, [r4, r2]
	ldr r0, [r4, #0x1c]
	lsl r2, r2, #0x14
	mov r1, #2
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl PaletteData_BlendPalette
	mov r0, #0xd
	mvn r0, r0
	mov r1, #0x2c
	mov r2, #1
	bl SetBlendBrightness
	ldr r0, [r5, #0x7c]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A57A:
	mov r0, #3
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _0223A628 ; =0x00007FFF
	str r6, [sp, #8]
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A594:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0223A620
	mov r0, #0x1a
	str r0, [r5, #0x78]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A5A8:
	ldr r0, [r5, #0x78]
	sub r0, r0, #1
	str r0, [r5, #0x78]
	bpl _0223A620
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A5B8:
	mov r0, #0xf
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x65
	mov r1, #0
	str r0, [sp, #8]
	ldr r3, _0223A628 ; =0x00007FFF
	mov r0, #3
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A5D8:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0223A620
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _0223A620
_0223A5E8:
	ldr r1, _0223A628 ; =0x00007FFF
	mov r0, #1
	bl sub_0200FBF4
	ldr r1, [r4, #0x20]
	cmp r1, #0
	beq _0223A5FA
	mov r0, #1
	strh r0, [r1]
_0223A5FA:
	add r0, r5, #0
	add r0, #0x7c
	bl ov80_0223A748
	ldr r0, [r4, #0x30]
	bl sub_020135AC
	add r0, r5, #0
	add r0, #0x90
	ldr r0, [r0]
	bl Sprite_DeleteAndFreeResources
	add r5, #0x14
	add r0, r5, #0
	bl ov80_0223A81C
	add sp, #0x28
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0223A620:
	mov r0, #0
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223A628: .word 0x00007FFF
	thumb_func_end ov80_0223A174


	thumb_func_start ov80_0223A62C
ov80_0223A62C: ; 0x0223A62C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x7c
	add r5, r1, #0
	add r7, r0, #0
	ldr r0, [r5]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	ldr r6, [sp, #0x9c]
	ldr r4, [sp, #0xa8]
	cmp r0, #0
	beq _0223A646
	bl GF_AssertFail
_0223A646:
	ldr r0, [r7, #0x10]
	cmp r4, #0
	str r0, [sp, #0x24]
	ldr r0, [r7, #0x18]
	str r0, [sp, #0x20]
	bne _0223A660
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r2, sp, #0x2c
	add r3, sp, #0x28
	bl ov80_0223A75C
	b _0223A668
_0223A660:
	ldrh r0, [r4, #0x12]
	str r0, [sp, #0x2c]
	ldrh r0, [r4, #0x10]
	str r0, [sp, #0x28]
_0223A668:
	cmp r4, #0
	bne _0223A6A6
	add r0, sp, #0x3c
	bl InitWindow
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r2, [sp, #0x28]
	ldr r0, [sp, #0x24]
	lsl r2, r2, #0x18
	add r1, sp, #0x3c
	lsr r2, r2, #0x18
	mov r3, #2
	bl AddTextWindowTopLeftCorner
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x90]
	ldr r1, [sp, #0x1c]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r2, [sp, #0x18]
	add r0, sp, #0x3c
	str r3, [sp, #0x14]
	bl AddTextPrinterParameterizedWithColorAndSpacing
	b _0223A6B2
_0223A6A6:
	add r3, r4, #0
	add r2, sp, #0x3c
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
_0223A6B2:
	add r0, sp, #0x3c
	mov r1, #1
	mov r2, #0x65
	bl sub_02013688
	mov r1, #1
	add r2, r1, #0
	add r3, sp, #0x30
	bl sub_02021AC8
	ldr r0, [sp, #0xa4]
	cmp r0, #1
	bne _0223A6D6
	ldr r1, [sp, #0x2c]
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	sub r6, r6, r0
_0223A6D6:
	ldr r0, [r7, #0x30]
	str r0, [sp, #0x4c]
	add r0, sp, #0x3c
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x20]
	bl SpriteManager_GetSpriteList
	str r0, [sp, #0x54]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x98]
	bl SpriteManager_FindPlttResourceProxy
	mov r1, #0
	str r0, [sp, #0x58]
	ldr r0, [sp, #0x34]
	str r1, [sp, #0x5c]
	str r0, [sp, #0x60]
	ldr r0, [sp, #0xa0]
	str r6, [sp, #0x64]
	sub r0, #8
	str r0, [sp, #0x68]
	mov r0, #0xb
	str r0, [sp, #0x70]
	mov r0, #1
	str r0, [sp, #0x74]
	mov r0, #0x65
	str r0, [sp, #0x78]
	add r0, sp, #0x4c
	str r1, [sp, #0x6c]
	bl sub_020135D8
	ldr r1, [sp, #0x94]
	add r7, r0, #0
	bl sub_020138E0
	ldr r2, [sp, #0xa0]
	add r0, r7, #0
	add r1, r6, #0
	sub r2, #8
	bl sub_020136B4
	cmp r4, #0
	bne _0223A732
	add r0, sp, #0x3c
	bl RemoveWindow
_0223A732:
	str r7, [r5]
	add r3, sp, #0x30
	ldmia r3!, {r0, r1}
	add r2, r5, #4
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #0x10]
	add sp, #0x7c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov80_0223A62C

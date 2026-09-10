	.include "asm/macros.inc"
	.public _020F5C40
	.public _020F5C50
	.public _020F5C60
	.public _020F5C78
	.public sub_0200E398
	.public _0200E3BE
	.public sub_0200E3D8
	.public LoadUserFrameGfx1
	.public _0200E3F2
	.public _0200E3F4
	.public _0200E416
	.public _0200E418
	.public _0200E432
	.public sub_0200E448
	.public DrawFrameAndWindow1
	.public _0200E5D0
	.public sub_0200E5D4
	.public _0200E636
	.public sub_0200E63C
	.public sub_0200E640
	.public LoadUserFrameGfx2
	.public _0200E694
	.public sub_0200E6B4
	.public sub_0200E948
	.public DrawFrameAndWindow2
	.public _0200E9B2
	.public ClearFrameAndWindow2
	.public _0200EA1E
	.public sub_0200EA24
	.public sub_0200EA68
	.public _0200EACA
	.public _0200EB12
	.public sub_0200EB68
	.public sub_0200EB80
	.public _0200EBC6
	.public _0200EBD8
	.public _0200EBDE
	.public LoadMapSignpostFrameAndGraphic
	.public _0200EC80
	.public sub_0200EC84
	.public _0200EC98
	.public _0200EC9C
	.public sub_0200ECBC
	.public sub_0200EF84
	.public _0200EFAE
	.public _0200EFC6
	.public DrawFrameAndWindow3
	.public _0200F062
	.public _0200F094
	.public _0200F0A0
	.public WaitingIcon_New
	.public _0200F12E
	.public _0200F1C4
	.public _0200F1C8
	.public _0200F1CC
	.public _0200F1D0
	.public sub_0200F1D4
	.public _0200F2DE
	.public _0200F3C6
	.public _0200F3CC
	.public sub_0200F3D0
	.public _0200F3EA
	.public _0200F3F2
	.public _0200F434
	.public _0200F438
	.public sub_0200F43C
	.public sub_0200F450
	.public _0200F470
	.public _0200F474
	.public sub_0200F478
	.public _0200F498
	.public _0200F49C
	.public DrawPokemonPicFromSpecies
	.public _0200F4F4
	.public DrawPokemonPicFromMon
	.public _0200F548
	.public sub_0200F54C
	.public _0200F564
	.public _0200F582
	.public _0200F594
	.public _0200F5A8
	.public _0200F5C0
	.public sub_0200F5C4
	.public _0200F5F8
	.public _0200F5FC
	.public sub_0200F600
	.public _0200F628
	.public sub_0200F62C
	.public _0200F680
	.public sub_0200F684
	.public _0200F694
	.public _0200F6D0
	.public sub_0200F6D4
	.public _0200F710
	.public sub_0200F714
	.public _0200F744
	.public sub_0200F748
	.public _0200F81C
	.public _0200F820
	.public _0200F824
	.public _0200F828
	.public sub_0200F82C
	.public _0200F9D8
	.public sub_0200F9DC
	.public _0200FA20
	.public sub_0200E398
	.public sub_0200E3D8
	.public LoadUserFrameGfx1
	.public sub_0200E448
	.public DrawFrameAndWindow1
	.public sub_0200E5D4
	.public sub_0200E63C
	.public sub_0200E640
	.public LoadUserFrameGfx2
	.public sub_0200E6B4
	.public sub_0200E948
	.public DrawFrameAndWindow2
	.public ClearFrameAndWindow2
	.public sub_0200EA24
	.public sub_0200EA68
	.public sub_0200EB68
	.public sub_0200EB80
	.public LoadMapSignpostFrameAndGraphic
	.public sub_0200EC84
	.public sub_0200ECBC
	.public sub_0200EF84
	.public DrawFrameAndWindow3
	.public WaitingIcon_New
	.public sub_0200F1D4
	.public sub_0200F3D0
	.public sub_0200F43C
	.public sub_0200F450
	.public sub_0200F478
	.public DrawPokemonPicFromSpecies
	.public DrawPokemonPicFromMon
	.public sub_0200F54C
	.public sub_0200F5C4
	.public sub_0200F600
	.public sub_0200F62C
	.public sub_0200F684
	.public sub_0200F6D4
	.public sub_0200F714
	.public sub_0200F748
	.public sub_0200F82C
	.public sub_0200F9DC
	.public _020F5C40
	.public _020F5C50
	.public _020F5C60
	.public _020F5C78
	.public _0200E3BE
	.public _0200E3F2
	.public _0200E3F4
	.public _0200E416
	.public _0200E418
	.public _0200E432
	.public _0200E5D0
	.public _0200E636
	.public _0200E694
	.public _0200E9B2
	.public _0200EA1E
	.public _0200EACA
	.public _0200EB12
	.public _0200EBC6
	.public _0200EBD8
	.public _0200EBDE
	.public _0200EC80
	.public _0200EC98
	.public _0200EC9C
	.public _0200EFAE
	.public _0200EFC6
	.public _0200F062
	.public _0200F094
	.public _0200F0A0
	.public _0200F12E
	.public _0200F2DE
	.public _0200F3C6
	.public _0200F3EA
	.public _0200F3F2
	.public _0200F434
	.public _0200F564
	.public _0200F582
	.public _0200F594
	.public _0200F5A8
	.public _0200F694
	.include "render_window.inc"
	.include "global.inc"

	.text
	.public DrawFrameAndWindow2
	.public sub_0200E398
	.public sub_0200E3D8
	.public sub_0200E63C
	.public sub_0200E640
	.public sub_0200EB68
	.public sub_0200F43C
	.public sub_0200F450
	.public sub_0200F478
	.public sub_0200F5C4
	.public sub_0200F6D4
	.public sub_0200F714

	thumb_func_start sub_0200EB80
sub_0200EB80: ; 0x0200EB80
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #0x18
	ldrb r0, [r0, #0x10]
	add r7, r2, #0
	add r5, r3, #0
	bl sub_0200E63C
	add r1, r0, #0
	ldr r0, [sp, #0x2c]
	mov r2, #0
	str r0, [sp]
	mov r0, #0x26
	add r3, sp, #0x10
	bl GfGfxLoader_GetCharData
	str r0, [sp, #0xc]
	mov r1, #9
	ldr r0, [sp, #0x2c]
	lsl r1, r1, #6
	bl Heap_Alloc
	ldr r1, [sp, #0x10]
	mov r2, #9
	ldr r1, [r1, #0x14]
	lsl r2, r2, #6
	add r4, r0, #0
	bl memcpy
	mov r0, #9
	mov r3, #0
	lsl r0, r0, #6
	mov r1, #0xf
_0200EBC6:
	ldrb r2, [r4, r3]
	lsl r6, r2, #0x14
	and r2, r1
	lsl r2, r2, #0x18
	lsr r6, r6, #0x18
	lsr r2, r2, #0x18
	cmp r6, #0
	bne _0200EBD8
	add r6, r5, #0
_0200EBD8:
	cmp r2, #0
	bne _0200EBDE
	add r2, r5, #0
_0200EBDE:
	lsl r6, r6, #4
	orr r2, r6
	strb r2, [r4, r3]
	add r3, r3, #1
	cmp r3, r0
	blo _0200EBC6
	str r7, [sp]
	mov r3, #9
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	add r2, r4, #0
	lsl r3, r3, #6
	bl BG_LoadCharTilesData
	ldr r0, [sp, #0xc]
	bl Heap_Free
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0200EB80


	thumb_func_start LoadMapSignpostFrameAndGraphic
LoadMapSignpostFrameAndGraphic: ; 0x0200EC0C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r0, [sp, #0x10]
	add r5, r2, #0
	mov r0, #0xf
	add r6, r1, #0
	add r7, r3, #0
	str r5, [sp]
	lsl r0, r0, #6
	str r0, [sp, #4]
	mov r1, #0
	ldr r4, [sp, #0x38]
	str r1, [sp, #8]
	ldr r2, [sp, #0x10]
	mov r0, #0x24
	add r3, r6, #0
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadCharData
	mov r0, #0x24
	mov r1, #1
	add r2, r4, #0
	bl AllocAndReadWholeNarcMemberByIdPair
	add r1, sp, #0x18
	str r0, [sp, #0x14]
	bl NNS_G2dGetUnpackedPaletteData
	add r2, sp, #0x20
	ldr r1, [sp, #0x18]
	ldrb r2, [r2, #0x10]
	lsl r3, r7, #0x15
	ldr r1, [r1, #0xc]
	lsl r2, r2, #5
	add r1, r1, r2
	add r0, r6, #0
	mov r2, #0x20
	lsr r3, r3, #0x10
	bl BG_LoadPlttData
	ldr r1, [sp, #0x14]
	add r0, r4, #0
	bl Heap_FreeExplicit
	add r0, sp, #0x20
	ldrb r3, [r0, #0x10]
	cmp r3, #1
	bhi _0200EC80
	ldrh r0, [r0, #0x14]
	add r5, #0x1e
	lsl r2, r5, #0x10
	str r0, [sp]
	ldr r0, [sp, #0x10]
	add r1, r6, #0
	lsr r2, r2, #0x10
	str r4, [sp, #4]
	bl sub_0200EC84
_0200EC80:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end LoadMapSignpostFrameAndGraphic


	thumb_func_start sub_0200EC84
sub_0200EC84: ; 0x0200EC84
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r1, #0
	add r5, r0, #0
	ldr r1, [sp, #0x20]
	cmp r3, #0
	bne _0200EC98
	add r1, #0x21
	lsl r0, r1, #0x10
	b _0200EC9C
_0200EC98:
	add r0, r1, #2
	lsl r0, r0, #0x10
_0200EC9C:
	lsr r1, r0, #0x10
	mov r0, #3
	str r2, [sp]
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x24]
	add r2, r5, #0
	str r0, [sp, #0xc]
	mov r0, #0x24
	add r3, r4, #0
	bl GfGfxLoader_LoadCharData
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_0200EC84


	thumb_func_start sub_0200ECBC
sub_0200ECBC: ; 0x0200ECBC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	ldr r2, [sp, #0x1c]
	ldr r6, [sp, #0x5c]
	sub r7, r2, #1
	ldr r2, [sp, #0x18]
	ldr r5, [sp, #0x60]
	str r2, [sp, #0x34]
	sub r2, #9
	str r2, [sp, #0x34]
	lsl r2, r7, #0x18
	lsr r2, r2, #0x18
	str r2, [sp]
	mov r2, #1
	str r2, [sp, #4]
	str r2, [sp, #8]
	ldr r3, [sp, #0x34]
	str r5, [sp, #0xc]
	add r2, sp, #0x48
	lsl r3, r3, #0x18
	ldrh r2, [r2, #0x1c]
	lsr r3, r3, #0x18
	str r0, [sp, #0x10]
	bl FillBgTilemapRect
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x30]
	sub r0, #8
	str r0, [sp, #0x30]
	add r0, sp, #0x48
	ldrh r4, [r0, #0x1c]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x30]
	str r5, [sp, #0xc]
	add r2, r4, #1
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, sp, #0x48
	ldrb r0, [r0, #0x10]
	add r2, r4, #2
	lsl r2, r2, #0x10
	str r0, [sp, #0x3c]
	add r0, r0, #7
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x18]
	lsr r2, r2, #0x10
	sub r0, r0, #7
	str r0, [sp, #0x20]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x24]
	ldr r3, [sp, #0x20]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r2, r4, #3
	lsl r2, r2, #0x10
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x3c]
	lsr r2, r2, #0x10
	add r0, r1, r0
	str r0, [sp, #0x38]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x38]
	str r5, [sp, #0xc]
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x38]
	add r2, r4, #4
	add r0, r0, #1
	str r0, [sp, #0x2c]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x2c]
	str r5, [sp, #0xc]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x38]
	add r0, r0, #2
	str r0, [sp, #0x28]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x28]
	str r5, [sp, #0xc]
	add r2, r4, #5
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x1c]
	ldr r3, [sp, #0x34]
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	add r2, r4, #6
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x1c]
	ldr r3, [sp, #0x30]
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	add r2, r4, #7
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x1c]
	add r2, r4, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	ldr r3, [sp, #0x18]
	add r2, #8
	sub r3, r3, #1
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x1c]
	add r2, r4, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	ldr r3, [sp, #0x38]
	str r5, [sp, #0xc]
	add r2, #9
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x1c]
	add r2, r4, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	ldr r3, [sp, #0x2c]
	str r5, [sp, #0xc]
	add r2, #0xa
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x1c]
	add r2, r4, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	ldr r3, [sp, #0x28]
	str r5, [sp, #0xc]
	add r2, #0xb
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x1c]
	add r2, r4, #0
	add r6, r0, r6
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x34]
	str r5, [sp, #0xc]
	add r2, #0xc
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r2, r4, #0
	ldr r3, [sp, #0x30]
	str r5, [sp, #0xc]
	add r2, #0xd
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x24]
	add r2, r4, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r3, [sp, #0x20]
	str r5, [sp, #0xc]
	add r2, #0xe
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r2, r4, #0
	ldr r3, [sp, #0x38]
	str r5, [sp, #0xc]
	add r2, #0xf
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r2, r4, #0
	ldr r3, [sp, #0x2c]
	str r5, [sp, #0xc]
	add r2, #0x10
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x28]
	str r5, [sp, #0xc]
	add r4, #0x11
	lsl r2, r4, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0200ECBC


	thumb_func_start sub_0200EF84
sub_0200EF84: ; 0x0200EF84
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r1, [sp, #0x10]
	add r7, r0, #0
	str r2, [sp, #0x14]
	bl GetWindowBgId
	str r0, [sp, #0x20]
	add r0, r7, #0
	bl GetWindowX
	sub r0, r0, #7
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x18]
	add r0, r7, #0
	bl GetWindowY
	str r0, [sp, #0x1c]
	mov r0, #0
	str r0, [sp, #0x24]
_0200EFAE:
	ldr r2, [sp, #0x24]
	ldr r1, [sp, #0x1c]
	ldr r0, [sp, #0x24]
	add r3, r2, #0
	add r0, r1, r0
	mov r1, #6
	mul r3, r1
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0x18
	mov r4, #0
	add r5, r1, r3
	lsr r6, r0, #0x18
_0200EFC6:
	str r6, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [sp, #0x14]
	ldr r3, [sp, #0x18]
	str r0, [sp, #0xc]
	add r2, r4, r5
	add r3, r3, r4
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [r7]
	ldr r1, [sp, #0x20]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #6
	blo _0200EFC6
	ldr r0, [sp, #0x24]
	add r0, r0, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x24]
	cmp r0, #4
	blo _0200EFAE
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0200EF84


	thumb_func_start DrawFrameAndWindow3
DrawFrameAndWindow3: ; 0x0200F004
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r4, r0, #0
	str r1, [sp, #0x10]
	add r6, r2, #0
	add r7, r3, #0
	bl GetWindowBgId
	str r0, [sp, #0x14]
	add r0, sp, #0x30
	ldrb r0, [r0, #0x10]
	cmp r0, #1
	bhi _0200F062
	add r0, r4, #0
	bl GetWindowX
	str r0, [sp, #0x18]
	add r0, r4, #0
	bl GetWindowY
	str r0, [sp, #0x1c]
	add r0, r4, #0
	bl GetWindowWidth
	add r5, r0, #0
	add r0, r4, #0
	bl GetWindowHeight
	str r5, [sp]
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	ldr r0, [r4]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl sub_0200ECBC
	add r1, r6, #0
	add r1, #0x1e
	lsl r1, r1, #0x10
	add r0, r4, #0
	lsr r1, r1, #0x10
	add r2, r7, #0
	bl sub_0200EF84
	b _0200F094
_0200F062:
	add r0, r4, #0
	bl GetWindowX
	str r0, [sp, #0x20]
	add r0, r4, #0
	bl GetWindowY
	str r0, [sp, #0x24]
	add r0, r4, #0
	bl GetWindowWidth
	add r5, r0, #0
	add r0, r4, #0
	bl GetWindowHeight
	str r5, [sp]
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	ldr r0, [r4]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl sub_0200E6B4
_0200F094:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	bne _0200F0A0
	add r0, r4, #0
	bl CopyWindowToVram
_0200F0A0:
	add r0, r6, #0
	bl TextPrinter_SetDownArrowBaseTile
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end DrawFrameAndWindow3


	thumb_func_start WaitingIcon_New
WaitingIcon_New: ; 0x0200F0AC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	str r0, [sp, #0x20]
	ldr r0, [r0]
	str r1, [sp, #0x24]
	bl BgConfig_GetHeapId
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x20]
	bl GetWindowBgId
	bl BgGetCharPtr
	add r5, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, _0200F1C4 ; =0x0000048C
	bl Heap_Alloc
	ldr r1, [sp, #0x24]
	add r4, r0, #0
	ldr r0, _0200F1C8 ; =0x00000404
	add r1, #0x12
	lsl r1, r1, #5
	add r0, r4, r0
	add r1, r5, r1
	mov r2, #0x80
	bl memcpy
	ldr r0, [sp, #0x28]
	mov r1, #0x80
	bl Heap_Alloc
	ldr r1, [sp, #0x24]
	mov r2, #0x20
	add r1, #0xa
	lsl r1, r1, #5
	str r1, [sp, #0x2c]
	add r1, r5, r1
	add r6, r0, #0
	bl memcpy
	ldr r0, [sp, #0x24]
	mov r2, #0x20
	add r0, #0xb
	lsl r7, r0, #5
	add r0, r6, #0
	add r0, #0x20
	add r1, r5, r7
	bl memcpy
	ldr r1, [sp, #0x2c]
	add r0, r6, #0
	add r0, #0x40
	add r1, r5, r1
	mov r2, #0x20
	bl memcpy
	add r0, r6, #0
	add r0, #0x60
	add r1, r5, r7
	mov r2, #0x20
	bl memcpy
	mov r5, #0
	add r7, r4, #4
_0200F12E:
	lsl r0, r5, #7
	add r0, r7, r0
	add r1, r6, #0
	mov r2, #0x80
	bl memcpy
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #8
	blo _0200F12E
	add r0, r6, #0
	bl Heap_Free
	ldr r0, [sp, #0x28]
	mov r1, #0x17
	str r0, [sp]
	mov r0, #0x26
	mov r2, #0
	add r3, sp, #0x30
	bl GfGfxLoader_GetCharData
	mov r2, #0x80
	add r5, r0, #0
	str r2, [sp]
	add r0, r4, #4
	str r0, [sp, #4]
	mov r3, #0x10
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	mov r1, #0
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r3, [sp, #0x18]
	str r2, [sp, #0x1c]
	ldr r0, [sp, #0x30]
	add r2, r1, #0
	ldr r0, [r0, #0x14]
	bl sub_0200EA24
	add r0, r5, #0
	bl Heap_Free
	ldr r0, [sp, #0x20]
	ldr r1, _0200F1CC ; =0x00000484
	str r0, [r4]
	ldr r0, [sp, #0x24]
	mov r2, #0
	strh r0, [r4, r1]
	add r0, r1, #2
	strb r2, [r4, r0]
	add r0, r1, #3
	ldrb r3, [r4, r0]
	mov r0, #0x7f
	bic r3, r0
	add r0, r1, #3
	strb r3, [r4, r0]
	add r0, r1, #4
	ldrb r3, [r4, r0]
	mov r0, #3
	bic r3, r0
	add r0, r1, #4
	strb r3, [r4, r0]
	ldr r0, _0200F1D0 ; =sub_0200F3D0
	add r1, r4, #0
	bl SysTask_CreateOnVBlankQueue
	add r0, r4, #0
	mov r1, #1
	bl sub_0200F1D4
	add r0, r4, #0
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	nop
_0200F1C4: .word 0x0000048C
_0200F1C8: .word 0x00000404
_0200F1CC: .word 0x00000484
_0200F1D0: .word sub_0200F3D0
	thumb_func_end WaitingIcon_New


	thumb_func_start sub_0200F1D4
sub_0200F1D4: ; 0x0200F1D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	ldr r0, [r5]
	add r6, r1, #0
	bl GetWindowBgId
	add r4, r0, #0
	ldr r0, [r5]
	bl GetWindowX
	str r0, [sp, #0x18]
	ldr r0, [r5]
	bl GetWindowY
	str r0, [sp, #0x1c]
	ldr r0, [r5]
	bl GetWindowWidth
	str r0, [sp, #0x20]
	cmp r6, #2
	bne _0200F2DE
	ldr r2, _0200F3CC ; =0x00000484
	add r1, r4, #0
	ldrh r0, [r5, r2]
	sub r2, #0x80
	add r2, r5, r2
	add r0, #0x12
	str r0, [sp]
	ldr r0, [r5]
	mov r3, #0x80
	ldr r0, [r0]
	bl BG_LoadCharTilesData
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x18]
	add r7, r0, #2
	ldr r0, [sp, #0x20]
	ldr r2, _0200F3CC ; =0x00000484
	add r6, r1, r0
	add r0, r6, #1
	str r0, [sp, #0x14]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r2, [r5, r2]
	ldr r0, [r5]
	ldr r3, [sp, #0x14]
	add r2, #0xa
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [r0]
	add r1, r4, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r2, _0200F3CC ; =0x00000484
	ldr r0, [r5]
	ldrh r2, [r5, r2]
	add r6, r6, #2
	lsl r3, r6, #0x18
	add r2, #0xb
	lsl r2, r2, #0x10
	ldr r0, [r0]
	add r1, r4, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x1c]
	ldr r3, [sp, #0x14]
	add r7, r0, #3
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r2, _0200F3CC ; =0x00000484
	ldr r0, [r5]
	ldrh r2, [r5, r2]
	lsl r3, r3, #0x18
	ldr r0, [r0]
	add r2, #0xa
	lsl r2, r2, #0x10
	add r1, r4, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r2, _0200F3CC ; =0x00000484
	ldr r0, [r5]
	ldrh r2, [r5, r2]
	lsl r3, r6, #0x18
	ldr r0, [r0]
	add r2, #0xb
	lsl r2, r2, #0x10
	add r1, r4, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [r5]
	add r1, r4, #0
	ldr r0, [r0]
	bl BgCommitTilemapBufferToVram
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
_0200F2DE:
	ldr r3, _0200F3CC ; =0x00000484
	add r2, r5, #4
	ldrh r0, [r5, r3]
	add r3, r3, #3
	add r1, r4, #0
	add r0, #0x12
	str r0, [sp]
	ldrb r3, [r5, r3]
	ldr r0, [r5]
	lsl r3, r3, #0x19
	lsr r3, r3, #0x19
	lsl r3, r3, #7
	add r2, r2, r3
	ldr r0, [r0]
	mov r3, #0x80
	bl BG_LoadCharTilesData
	cmp r6, #0
	beq _0200F3C6
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x18]
	add r7, r0, #2
	ldr r0, [sp, #0x20]
	ldr r2, _0200F3CC ; =0x00000484
	add r6, r1, r0
	add r0, r6, #1
	str r0, [sp, #0x10]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r2, [r5, r2]
	ldr r0, [r5]
	ldr r3, [sp, #0x10]
	add r2, #0x12
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [r0]
	add r1, r4, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r2, _0200F3CC ; =0x00000484
	ldr r0, [r5]
	ldrh r2, [r5, r2]
	add r6, r6, #2
	lsl r3, r6, #0x18
	add r2, #0x13
	lsl r2, r2, #0x10
	ldr r0, [r0]
	add r1, r4, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x1c]
	ldr r3, [sp, #0x10]
	add r7, r0, #3
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r2, _0200F3CC ; =0x00000484
	ldr r0, [r5]
	ldrh r2, [r5, r2]
	lsl r3, r3, #0x18
	ldr r0, [r0]
	add r2, #0x14
	lsl r2, r2, #0x10
	add r1, r4, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r2, _0200F3CC ; =0x00000484
	ldr r0, [r5]
	ldrh r2, [r5, r2]
	lsl r3, r6, #0x18
	ldr r0, [r0]
	add r2, #0x15
	lsl r2, r2, #0x10
	add r1, r4, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [r5]
	add r1, r4, #0
	ldr r0, [r0]
	bl BgCommitTilemapBufferToVram
_0200F3C6:
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_0200F3CC: .word 0x00000484
	thumb_func_end sub_0200F1D4


	thumb_func_start sub_0200F3D0
sub_0200F3D0: ; 0x0200F3D0
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, _0200F438 ; =0x00000488
	ldrb r2, [r1, r0]
	lsl r2, r2, #0x1e
	lsr r2, r2, #0x1e
	beq _0200F3F2
	cmp r2, #1
	bne _0200F3EA
	add r0, r1, #0
	mov r1, #2
	bl sub_0200F1D4
_0200F3EA:
	add r0, r4, #0
	bl SysTask_Destroy
	pop {r3, r4, r5, pc}
_0200F3F2:
	sub r2, r0, #2
	ldrb r2, [r1, r2]
	add r3, r2, #1
	sub r2, r0, #2
	strb r3, [r1, r2]
	ldrb r2, [r1, r2]
	cmp r2, #0x10
	bne _0200F434
	mov r3, #0
	sub r2, r0, #2
	strb r3, [r1, r2]
	sub r2, r0, #1
	ldrb r2, [r1, r2]
	mov r4, #0x7f
	bic r2, r4
	sub r4, r0, #1
	ldrb r4, [r1, r4]
	sub r0, r0, #1
	lsl r4, r4, #0x19
	lsr r4, r4, #0x19
	add r5, r4, #1
	mov r4, #7
	and r4, r5
	lsl r4, r4, #0x18
	lsr r5, r4, #0x18
	mov r4, #0x7f
	and r4, r5
	orr r2, r4
	strb r2, [r1, r0]
	add r0, r1, #0
	add r1, r3, #0
	bl sub_0200F1D4
_0200F434:
	pop {r3, r4, r5, pc}
	nop
_0200F438: .word 0x00000488
	thumb_func_end sub_0200F3D0

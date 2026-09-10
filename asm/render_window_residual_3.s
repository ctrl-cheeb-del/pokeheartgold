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

	thumb_func_start ClearFrameAndWindow2
ClearFrameAndWindow2: ; 0x0200E9BC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r4, r1, #0
	bl GetWindowBgId
	str r0, [sp, #0x10]
	add r0, r5, #0
	bl GetWindowX
	add r6, r0, #0
	add r0, r5, #0
	bl GetWindowY
	add r7, r0, #0
	add r0, r5, #0
	bl GetWindowWidth
	str r0, [sp, #0x14]
	add r0, r5, #0
	bl GetWindowHeight
	sub r1, r7, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp]
	ldr r1, [sp, #0x14]
	add r0, r0, #2
	add r1, r1, #5
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsl r0, r0, #0x18
	str r1, [sp, #4]
	lsr r0, r0, #0x18
	sub r3, r6, #2
	lsl r3, r3, #0x18
	str r0, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r0, [r5]
	ldr r1, [sp, #0x10]
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	cmp r4, #0
	bne _0200EA1E
	add r0, r5, #0
	bl ClearWindowTilemapAndCopyToVram
_0200EA1E:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ClearFrameAndWindow2


	thumb_func_start sub_0200EA24
sub_0200EA24: ; 0x0200EA24
	push {r4, r5, lr}
	sub sp, #0x24
	add r5, r1, #0
	str r0, [sp, #0x1c]
	add r1, sp, #0x14
	strh r3, [r1, #0xc]
	add r4, r2, #0
	add r0, sp, #0x20
	ldrh r2, [r0, #0x10]
	add r3, r4, #0
	strh r2, [r1, #0xe]
	ldr r2, [sp, #0x34]
	str r2, [sp, #0x14]
	ldrh r2, [r0, #0x18]
	strh r2, [r1, #4]
	ldrh r2, [r0, #0x1c]
	strh r2, [r1, #6]
	ldrh r1, [r0, #0x20]
	add r2, r5, #0
	str r1, [sp]
	ldrh r1, [r0, #0x24]
	str r1, [sp, #4]
	ldrh r1, [r0, #0x28]
	str r1, [sp, #8]
	ldrh r0, [r0, #0x2c]
	add r1, sp, #0x14
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x1c
	bl BlitBitmapRect4Bit
	add sp, #0x24
	pop {r4, r5, pc}
	thumb_func_end sub_0200EA24


	thumb_func_start sub_0200EA68
sub_0200EA68: ; 0x0200EA68
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x48
	str r2, [sp, #0x24]
	str r3, [sp, #0x28]
	str r0, [sp, #0x20]
	ldr r0, [r0]
	add r7, r1, #0
	bl BgConfig_GetHeapId
	add r6, r0, #0
	ldr r0, [sp, #0x20]
	bl GetWindowBgId
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x28]
	lsl r0, r0, #7
	str r0, [sp, #0x30]
	ldr r1, [sp, #0x30]
	add r0, r6, #0
	bl Heap_Alloc
	add r5, r0, #0
	ldr r0, [sp, #0x2c]
	bl BgGetCharPtr
	add r4, r0, #0
	str r6, [sp]
	mov r0, #0x26
	add r1, r7, #0
	mov r2, #0
	add r3, sp, #0x44
	bl GfGfxLoader_GetCharData
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x44]
	mov r7, #0
	ldr r0, [r0, #0x14]
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x28]
	cmp r0, #0
	ble _0200EB12
	ldr r0, [sp, #0x24]
	add r0, #0xa
	lsl r0, r0, #5
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x24]
	add r0, #0xb
	lsl r0, r0, #5
	str r0, [sp, #0x40]
_0200EACA:
	ldr r1, [sp, #0x3c]
	lsl r6, r7, #7
	add r0, r5, r6
	add r1, r4, r1
	mov r2, #0x20
	bl memcpy
	add r0, r6, #0
	ldr r1, [sp, #0x40]
	add r0, #0x20
	add r0, r5, r0
	add r1, r4, r1
	mov r2, #0x20
	bl memcpy
	add r0, r6, #0
	ldr r1, [sp, #0x3c]
	add r0, #0x40
	add r0, r5, r0
	add r1, r4, r1
	mov r2, #0x20
	bl memcpy
	ldr r1, [sp, #0x40]
	add r6, #0x60
	add r0, r5, r6
	add r1, r4, r1
	mov r2, #0x20
	bl memcpy
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x28]
	cmp r7, r0
	blt _0200EACA
_0200EB12:
	add r1, sp, #0x50
	ldrb r2, [r1, #0x14]
	mov r3, #0x10
	ldr r0, [sp, #0x28]
	sub r4, r3, r2
	mul r0, r4
	ldrb r1, [r1, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	sub r3, r3, r1
	lsl r3, r3, #0x18
	str r0, [sp]
	lsr r3, r3, #0x18
	str r5, [sp, #4]
	str r3, [sp, #8]
	str r0, [sp, #0xc]
	mov r4, #0
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	str r3, [sp, #0x18]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x38]
	bl sub_0200EA24
	ldr r0, [sp, #0x24]
	ldr r3, [sp, #0x30]
	add r0, #0x12
	str r0, [sp, #0x24]
	str r0, [sp]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x2c]
	ldr r0, [r0]
	add r2, r5, #0
	bl BG_LoadCharTilesData
	ldr r0, [sp, #0x34]
	bl Heap_Free
	add r0, r5, #0
	bl Heap_Free
	add sp, #0x48
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0200EA68

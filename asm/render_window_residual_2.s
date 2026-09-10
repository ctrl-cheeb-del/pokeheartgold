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

	thumb_func_start LoadUserFrameGfx2
LoadUserFrameGfx2: ; 0x0200E644
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x18
	ldrb r7, [r0, #0x10]
	add r6, r2, #0
	add r5, r1, #0
	add r0, r7, #0
	add r4, r3, #0
	bl sub_0200E63C
	add r1, r0, #0
	str r6, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [sp, #0x2c]
	ldr r2, [sp, #0x10]
	str r0, [sp, #0xc]
	mov r0, #0x26
	add r3, r5, #0
	bl GfGfxLoader_LoadCharData
	cmp r5, #4
	bhs _0200E694
	add r0, r7, #0
	bl sub_0200E640
	add r1, r0, #0
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	mov r2, #0
	str r0, [sp, #4]
	mov r0, #0x26
	lsl r3, r4, #5
	bl GfGfxLoader_GXLoadPal
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
_0200E694:
	add r0, r7, #0
	bl sub_0200E640
	add r1, r0, #0
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	mov r2, #4
	str r0, [sp, #4]
	mov r0, #0x26
	lsl r3, r4, #5
	bl GfGfxLoader_GXLoadPal
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end LoadUserFrameGfx2


	thumb_func_start sub_0200E6B4
sub_0200E6B4: ; 0x0200E6B4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	str r1, [sp, #0x10]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	ldr r2, [sp, #0x4c]
	add r7, r0, #0
	str r2, [sp, #0x4c]
	ldr r2, [sp, #0x18]
	ldr r5, [sp, #0x50]
	sub r6, r2, #1
	ldr r2, [sp, #0x14]
	sub r2, r2, #2
	str r2, [sp, #0x28]
	lsl r2, r6, #0x18
	lsr r2, r2, #0x18
	str r2, [sp]
	mov r2, #1
	str r2, [sp, #4]
	str r2, [sp, #8]
	ldr r3, [sp, #0x28]
	str r5, [sp, #0xc]
	add r2, sp, #0x38
	lsl r3, r3, #0x18
	ldrh r2, [r2, #0x1c]
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x14]
	sub r0, r0, #1
	str r0, [sp, #0x24]
	add r0, sp, #0x38
	ldrh r4, [r0, #0x1c]
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x24]
	str r5, [sp, #0xc]
	add r2, r4, #1
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	add r0, sp, #0x38
	ldrb r0, [r0, #0x10]
	add r2, r4, #2
	lsl r2, r2, #0x10
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r3, [sp, #0x14]
	add r0, r7, #0
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	add r0, sp, #0x38
	ldrb r1, [r0, #0x10]
	ldr r0, [sp, #0x14]
	add r2, r4, #3
	add r0, r0, r1
	str r0, [sp, #0x2c]
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x2c]
	str r5, [sp, #0xc]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x2c]
	add r2, r4, #4
	add r0, r0, #1
	str r0, [sp, #0x20]
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x20]
	str r5, [sp, #0xc]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x2c]
	add r2, r4, #5
	add r0, r0, #2
	str r0, [sp, #0x1c]
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x1c]
	str r5, [sp, #0xc]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x18]
	ldr r3, [sp, #0x28]
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #0x4c]
	add r2, r4, #6
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x18]
	ldr r3, [sp, #0x24]
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #0x4c]
	add r2, r4, #7
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x18]
	add r2, r4, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #0x4c]
	ldr r3, [sp, #0x2c]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	add r2, #9
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x18]
	add r2, r4, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #0x4c]
	ldr r3, [sp, #0x20]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	add r2, #0xa
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x18]
	add r2, r4, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #0x4c]
	ldr r3, [sp, #0x1c]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	add r2, #0xb
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r2, r4, #0
	ldr r3, [sp, #0x28]
	add r2, #0xc
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x4c]
	lsr r2, r2, #0x10
	add r6, r1, r0
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r2, r4, #0
	ldr r3, [sp, #0x24]
	str r5, [sp, #0xc]
	add r2, #0xd
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	add r0, sp, #0x38
	ldrb r0, [r0, #0x10]
	add r2, r4, #0
	add r2, #0xe
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	lsl r2, r2, #0x10
	ldr r1, [sp, #0x10]
	ldr r3, [sp, #0x14]
	add r0, r7, #0
	lsr r2, r2, #0x10
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
	add r2, #0xf
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
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
	ldr r3, [sp, #0x20]
	str r5, [sp, #0xc]
	add r2, #0x10
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r3, [sp, #0x1c]
	str r5, [sp, #0xc]
	add r4, #0x11
	lsl r2, r4, #0x10
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0200E6B4


	thumb_func_start sub_0200E948
sub_0200E948: ; 0x0200E948
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	bl GetWindowBgId
	str r0, [sp, #0x10]
	add r0, r5, #0
	bl GetWindowX
	str r0, [sp, #0x14]
	add r0, r5, #0
	bl GetWindowY
	str r0, [sp, #0x18]
	add r0, r5, #0
	bl GetWindowWidth
	add r4, r0, #0
	add r0, r5, #0
	bl GetWindowHeight
	str r4, [sp]
	str r0, [sp, #4]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	lsl r0, r6, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, [r5]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0x18]
	bl sub_0200E6B4
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0200E948

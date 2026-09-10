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

	thumb_func_start sub_0200F748
sub_0200F748: ; 0x0200F748
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	ldr r0, _0200F81C ; =0x00000162
	add r6, r1, #0
	mov r1, #0x19
	ldrh r0, [r5, r0]
	lsl r1, r1, #8
	bl Heap_Alloc
	add r2, sp, #0x18
	ldr r3, _0200F820 ; =_020F5C50
	add r4, r0, #0
	add r7, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	str r4, [sp]
	ldr r2, _0200F81C ; =0x00000162
	ldrh r0, [r6]
	ldrh r1, [r6, #2]
	ldrh r2, [r5, r2]
	add r3, r7, #0
	bl sub_020143E0
	ldr r3, _0200F824 ; =_020F5C40
	add r2, sp, #8
	add r7, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r0, #0x32
	lsl r0, r0, #6
	add r0, r4, r0
	str r0, [sp]
	ldr r2, _0200F81C ; =0x00000162
	ldrh r0, [r6]
	ldrh r1, [r6, #2]
	ldrh r2, [r5, r2]
	add r3, r7, #0
	bl sub_020143E0
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	ldr r1, _0200F828 ; =0x00015CD5
	bl SpriteResourceCollection_Find
	bl SpriteTransfer_GetCharProxy
	mov r1, #1
	str r0, [sp, #4]
	bl NNS_G2dGetImageLocation
	mov r1, #0x19
	add r7, r0, #0
	add r0, r4, #0
	lsl r1, r1, #8
	bl DC_FlushRange
	mov r2, #0x19
	add r0, r4, #0
	add r1, r7, #0
	lsl r2, r2, #8
	bl GX_LoadOBJ
	add r0, r4, #0
	bl Heap_Free
	ldr r2, _0200F81C ; =0x00000162
	ldrh r0, [r6]
	ldrh r1, [r6, #4]
	ldrh r2, [r5, r2]
	bl sub_02014450
	add r4, r0, #0
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, _0200F828 ; =0x00015CD5
	bl SpriteResourceCollection_Find
	ldr r1, [sp, #4]
	bl SpriteTransfer_GetPaletteProxy
	mov r1, #1
	bl NNS_G2dGetImagePaletteLocation
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0x20
	bl DC_FlushRange
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x20
	bl GX_LoadOBJPltt
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0200F81C: .word 0x00000162
_0200F820: .word _020F5C50
_0200F824: .word _020F5C40
_0200F828: .word 0x00015CD5
	thumb_func_end sub_0200F748


	thumb_func_start sub_0200F82C
sub_0200F82C: ; 0x0200F82C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r3, _0200F9D8 ; =0x0000016E
	add r5, r0, #0
	ldrb r0, [r5, r3]
	add r4, r1, #0
	sub r1, r3, #2
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r3, [r5, r3]
	ldrb r1, [r5, r1]
	ldr r0, [r5, r0]
	sub r3, r3, #1
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	add r6, r2, #0
	bl FillBgTilemapRect
	ldr r3, _0200F9D8 ; =0x0000016E
	add r2, r6, #1
	ldrb r0, [r5, r3]
	sub r1, r3, #2
	lsl r2, r2, #0x10
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r1, [r5, r1]
	ldrb r3, [r5, r3]
	ldr r0, [r5, r0]
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	ldr r3, _0200F9D8 ; =0x0000016E
	add r2, r6, #2
	ldrb r0, [r5, r3]
	lsl r2, r2, #0x10
	sub r1, r3, #2
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r3, [r5, r3]
	ldrb r1, [r5, r1]
	ldr r0, [r5, r0]
	add r3, #0xa
	lsl r3, r3, #0x18
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r3, _0200F9D8 ; =0x0000016E
	add r2, r6, #4
	ldrb r0, [r5, r3]
	lsl r2, r2, #0x10
	sub r1, r3, #2
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r1, [r5, r1]
	ldrb r3, [r5, r3]
	ldr r0, [r5, r0]
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	ldr r3, _0200F9D8 ; =0x0000016E
	add r2, r6, #3
	ldrb r0, [r5, r3]
	lsl r2, r2, #0x10
	sub r1, r3, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0xa
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r3, [r5, r3]
	ldrb r1, [r5, r1]
	ldr r0, [r5, r0]
	sub r3, r3, #1
	lsl r3, r3, #0x18
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r3, _0200F9D8 ; =0x0000016E
	add r2, r6, #5
	ldrb r0, [r5, r3]
	lsl r2, r2, #0x10
	sub r1, r3, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0xa
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r3, [r5, r3]
	ldrb r1, [r5, r1]
	ldr r0, [r5, r0]
	add r3, #0xa
	lsl r3, r3, #0x18
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r3, _0200F9D8 ; =0x0000016E
	add r2, r6, #6
	ldrb r0, [r5, r3]
	lsl r2, r2, #0x10
	sub r1, r3, #2
	add r0, #0xa
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r3, [r5, r3]
	ldrb r1, [r5, r1]
	ldr r0, [r5, r0]
	sub r3, r3, #1
	lsl r3, r3, #0x18
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r3, _0200F9D8 ; =0x0000016E
	add r2, r6, #7
	ldrb r0, [r5, r3]
	sub r1, r3, #2
	lsl r2, r2, #0x10
	add r0, #0xa
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r1, [r5, r1]
	ldrb r3, [r5, r3]
	ldr r0, [r5, r0]
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	ldr r3, _0200F9D8 ; =0x0000016E
	add r6, #8
	ldrb r0, [r5, r3]
	lsl r2, r6, #0x10
	sub r1, r3, #2
	add r0, #0xa
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r3, [r5, r3]
	ldrb r1, [r5, r1]
	ldr r0, [r5, r0]
	add r3, #0xa
	lsl r3, r3, #0x18
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r1, #0x5a
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldrb r1, [r5, r1]
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_0200F9D8: .word 0x0000016E
	thumb_func_end sub_0200F82C


	thumb_func_start sub_0200F9DC
sub_0200F9DC: ; 0x0200F9DC
	push {r4, lr}
	sub sp, #0x10
	ldr r3, _0200FA20 ; =0x0000016E
	add r4, r0, #0
	ldrb r0, [r4, r3]
	mov r2, #0
	sub r1, r3, #2
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xc
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	sub r0, r3, #6
	sub r3, r3, #1
	ldrb r3, [r4, r3]
	ldrb r1, [r4, r1]
	ldr r0, [r4, r0]
	sub r3, r3, #1
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r1, #0x5a
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldrb r1, [r4, r1]
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_0200FA20: .word 0x0000016E
	thumb_func_end sub_0200F9DC

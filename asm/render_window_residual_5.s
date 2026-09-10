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

	thumb_func_start DrawPokemonPicFromSpecies
DrawPokemonPicFromSpecies: ; 0x0200F4A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r2, [sp, #4]
	ldr r5, [sp, #0x30]
	str r3, [sp, #8]
	add r6, r0, #0
	add r7, r1, #0
	str r5, [sp]
	bl sub_0200F5C4
	add r4, r0, #0
	add r1, r5, #0
	bl sub_0200F600
	add r0, r4, #0
	bl sub_0200F62C
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	add r0, r4, #0
	bl sub_0200F684
	add r2, sp, #0x10
	ldrh r1, [r2, #0x18]
	ldrb r2, [r2, #0x1c]
	add r0, r4, #0
	bl sub_0200F6D4
	add r2, sp, #0x10
	ldrb r1, [r2, #0x10]
	ldrh r2, [r2, #0x14]
	add r0, r4, #0
	bl sub_0200F82C
	add r0, r6, #0
	add r1, r7, #0
	bl BgCommitTilemapBufferToVram
	ldr r0, _0200F4F4 ; =0x0000016F
	add r0, r4, r0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0200F4F4: .word 0x0000016F
	thumb_func_end DrawPokemonPicFromSpecies


	thumb_func_start DrawPokemonPicFromMon
DrawPokemonPicFromMon: ; 0x0200F4F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r2, [sp, #4]
	ldr r5, [sp, #0x2c]
	str r3, [sp, #8]
	add r6, r0, #0
	add r7, r1, #0
	str r5, [sp]
	bl sub_0200F5C4
	add r4, r0, #0
	add r1, r5, #0
	bl sub_0200F600
	add r0, r4, #0
	bl sub_0200F62C
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	add r0, r4, #0
	bl sub_0200F684
	ldr r1, [sp, #0x28]
	add r0, r4, #0
	bl sub_0200F714
	add r2, sp, #0x10
	ldrb r1, [r2, #0x10]
	ldrh r2, [r2, #0x14]
	add r0, r4, #0
	bl sub_0200F82C
	add r0, r6, #0
	add r1, r7, #0
	bl BgCommitTilemapBufferToVram
	ldr r0, _0200F548 ; =0x0000016F
	add r0, r4, r0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0200F548: .word 0x0000016F
	thumb_func_end DrawPokemonPicFromMon


	thumb_func_start sub_0200F54C
sub_0200F54C: ; 0x0200F54C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0200F5C0 ; =0x0000016F
	add r4, r1, #0
	ldrb r1, [r4, r0]
	cmp r1, #1
	beq _0200F564
	cmp r1, #2
	beq _0200F582
	cmp r1, #3
	beq _0200F594
	b _0200F5A8
_0200F564:
	add r0, r4, #0
	bl sub_0200F9DC
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_DeleteAndFreeResources
	add r0, r4, #0
	bl FieldSpriteManager_ReleaseWithoutResDat
	add r0, r5, #0
	bl DestroySysTaskAndEnvironment
	pop {r3, r4, r5, pc}
_0200F582:
	mov r1, #3
	strb r1, [r4, r0]
	sub r0, #0xb
	ldr r0, [r4, r0]
	mov r1, #1
	ldr r0, [r0]
	bl Sprite_SetAnimCtrlSeq
	b _0200F5A8
_0200F594:
	sub r0, #0xb
	ldr r0, [r4, r0]
	ldr r0, [r0]
	bl Sprite_GetAnimationFrame
	cmp r0, #6
	bne _0200F5A8
	ldr r0, _0200F5C0 ; =0x0000016F
	mov r1, #0
	strb r1, [r4, r0]
_0200F5A8:
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	ldr r0, [r0]
	lsl r1, r1, #0xc
	bl Sprite_UpdateAnim
	ldr r0, [r4]
	bl SpriteList_RenderAndAnimateSprites
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0200F5C0: .word 0x0000016F
	thumb_func_end sub_0200F54C

	.include "asm/macros.inc"
	.include "overlay_37.inc"
	.include "global.inc"

	.text
	.public _021E7968
	.public ov37_021E5900
	.public ov37_021E5A84
	.public ov37_021E5B94
	.public ov37_021E5CC8
	.public ov37_021E5CF0
	.public ov37_021E5D10
	.public ov37_021E5E30
	.public ov37_021E5F98
	.public ov37_021E6090
	.public ov37_021E60C0
	.public ov37_021E6244
	.public ov37_021E6418
	.public ov37_021E657C
	.public ov37_021E65EC
	.public ov37_021E69DC
	.public ov37_021E6B64
	.public ov37_021E6D14
	.public ov37_021E6F5C
	.public ov37_021E6FC8
	.public ov37_021E70BC
	.public ov37_021E713C
	.public ov37_021E72B4
	.public ov37_021E72E8
	.public ov37_021E73B4
	.public ov37_021E741C
	.public ov37_021E7478
	.public ov37_021E755C
	.public ov37_021E762C
	.public ov37_021E76F0
	.public ov37_021E78E0
	.public ov37_021E7970
	.public ov37_021E7978
	.public ov37_021E7988
	.public ov37_021E7998
	.public ov37_021E79B4
	.public ov37_021E79D0
	.public ov37_021E79EC
	.public ov37_021E7A08
	.public ov37_021E7A24
	.public ov37_021E7A4C
	.public ov37_021E7A80
	.public ov37_021E7AC8
	.public ov37_021E7D20

	.public ov37_021E5F20
	.public ov37_021E5F5C
	.public ov37_021E6540
	.public ov37_021E6818
	.public ov37_021E6848
	.public ov37_021E6860
	.public ov37_021E68AC
	.public ov37_021E68D0
	.public ov37_021E6928
	.public ov37_021E694C
	.public ov37_021E6980
	.public ov37_021E6B40
	.public ov37_021E6BFC
	.public ov37_021E6C38
	.public ov37_021E6C58
	.public ov37_021E6C84
	.public ov37_021E6CC0
	.public ov37_021E6DD0
	.public ov37_021E6E04
	.public ov37_021E6E2C
	.public ov37_021E6E6C
	.public ov37_021E6E70
	.public ov37_021E6E90
	.public ov37_021E6EB4
	.public ov37_021E6F14
	.public ov37_021E745C
	.public ov37_021E75C4
	.public ov37_021E75E0
	.public ov37_021E75E8
	.public ov37_021E76A0
	.public ov37_021E76C0
	.public ov37_021E76D0
	.public ov37_021E7844
	.public ov37_021E784C
	.public ov37_021E7880
	.public ov37_021E78A4
	.public ov37_021E78C4

	thumb_func_start ov37_021E5F98
ov37_021E5F98: ; 0x021E5F98
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r6, r0, #0
	ldr r4, [r6]
	mov r0, #0x40
	add r5, r1, #0
	mov r1, #0
	str r0, [sp]
	mov r0, #0x27
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, r1, #0
	add r3, r1, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0x40
	str r0, [sp]
	mov r0, #0x27
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #1
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r1, #0x1a
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x27
	bl LoadFontPal1
	mov r1, #0x1a
	mov r0, #4
	lsl r1, r1, #4
	mov r2, #0x27
	bl LoadFontPal1
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x27
	mov r1, #2
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r2, r4, #0
	add r3, r1, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x27
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #4
	add r2, r4, #0
	mov r3, #2
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x27
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #3
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x27
	mov r1, #5
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r2, r4, #0
	add r3, r1, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r0, [r6, #8]
	ldr r0, [r0, #4]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x27
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0
	mov r2, #1
	mov r3, #0xa
	bl LoadUserFrameGfx2
	mov r1, #0
	str r1, [sp]
	mov r0, #0x27
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0x1f
	mov r3, #0xb
	bl LoadUserFrameGfx1
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov37_021E5F98


	thumb_func_start ov37_021E6090
ov37_021E6090: ; 0x021E6090
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _021E60BC ; =ov37_021E7988
	add r3, sp, #0
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl ObjCharTransfer_Init
	mov r0, #0x14
	mov r1, #0x27
	bl ObjPlttTransfer_Init
	bl ObjCharTransfer_ClearBuffers
	bl ObjPlttTransfer_Reset
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_021E60BC: .word ov37_021E7988
	thumb_func_end ov37_021E6090


	thumb_func_start ov37_021E60C0
ov37_021E60C0: ; 0x021E60C0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r7, r1, #0
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x7e
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x27
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	add r1, r5, #0
	mov r0, #0x35
	add r1, #0x38
	mov r2, #0x27
	bl G2dRenderer_Init
	str r0, [r5, #0x34]
	add r0, r5, #0
	mov r2, #1
	add r0, #0x38
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	mov r6, #0
	add r4, r5, #0
_021E6104:
	mov r0, #2
	add r1, r6, #0
	mov r2, #0x27
	bl Create2DGfxResObjMan
	mov r1, #0x16
	lsl r1, r1, #4
	str r0, [r4, r1]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #4
	blt _021E6104
	mov r0, #0
	str r0, [sp]
	mov r3, #1
	str r3, [sp, #4]
	mov r0, #0x27
	str r0, [sp, #8]
	add r0, r1, #0
	ldr r0, [r5, r0]
	add r1, r7, #0
	mov r2, #6
	bl AddCharResObjFromOpenNarc
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r5, r1]
	mov r2, #0
	str r2, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #7
	str r0, [sp, #8]
	mov r0, #0x27
	sub r1, #0xc
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r7, #0
	add r3, r2, #0
	bl AddPlttResObjFromOpenNarc
	mov r1, #0x5d
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0xc
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #7
	mov r3, #1
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x5e
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0xc
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #8
	mov r3, #1
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x5f
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r3, #1
	str r3, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0x1c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #6
	bl AddCharResObjFromOpenNarc
	mov r1, #6
	lsl r1, r1, #6
	str r0, [r5, r1]
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0x27
	mov r2, #0
	sub r1, #0x1c
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r7, #0
	add r3, r2, #0
	bl AddPlttResObjFromOpenNarc
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r3, #1
	str r3, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0x1c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #7
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r3, #1
	str r3, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0x1c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #8
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x63
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0x1c
	ldr r0, [r5, r1]
	bl SpriteTransfer_CreateCharTransferTask
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateCharTransferTask
	mov r0, #0x5d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov37_021E60C0


	thumb_func_start ov37_021E6244
ov37_021E6244: ; 0x021E6244
	push {r4, r5, r6, r7, lr}
	sub sp, #0x64
	mov r1, #0
	add r5, r0, #0
	str r1, [sp]
	sub r0, r1, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, #0x16
	str r1, [sp, #0x10]
	lsl r2, r2, #4
	ldr r0, [r5, r2]
	add r3, r1, #0
	str r0, [sp, #0x14]
	add r0, r2, #4
	ldr r0, [r5, r0]
	str r0, [sp, #0x18]
	add r0, r2, #0
	add r0, #8
	ldr r0, [r5, r0]
	str r0, [sp, #0x1c]
	add r0, r2, #0
	add r0, #0xc
	ldr r0, [r5, r0]
	add r2, #0x30
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, r5, r2
	add r2, r1, #0
	str r1, [sp, #0x28]
	bl CreateSpriteResourcesHeader
	mov r1, #1
	mov r3, #0x16
	str r1, [sp]
	sub r0, r1, #2
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	lsl r3, r3, #4
	ldr r2, [r5, r3]
	str r2, [sp, #0x14]
	add r2, r3, #4
	ldr r2, [r5, r2]
	str r2, [sp, #0x18]
	add r2, r3, #0
	add r2, #8
	ldr r2, [r5, r2]
	str r2, [sp, #0x1c]
	add r2, r3, #0
	add r2, #0xc
	ldr r2, [r5, r2]
	add r3, #0x54
	str r2, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, r5, r3
	add r2, r1, #0
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	ldr r0, [r5, #0x34]
	mov r6, #0
	str r0, [sp, #0x34]
	mov r0, #0x19
	lsl r0, r0, #4
	add r0, r5, r0
	str r0, [sp, #0x38]
	mov r0, #1
	lsl r0, r0, #0xc
	str r6, [sp, #0x44]
	str r0, [sp, #0x48]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	add r0, sp, #0x34
	strh r6, [r0, #0x20]
	mov r0, #1
	str r0, [sp, #0x58]
	str r0, [sp, #0x5c]
	mov r0, #0x27
	str r0, [sp, #0x60]
	mov r0, #0x6d
	lsl r0, r0, #2
	add r0, r5, r0
	mov r7, #0x18
	add r4, r5, #0
	str r0, [sp, #0x2c]
_021E62F8:
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x38]
	lsl r0, r7, #0xc
	str r0, [sp, #0x3c]
	mov r0, #1
	lsl r0, r0, #0x12
	str r0, [sp, #0x40]
	mov r0, #2
	str r0, [sp, #0x5c]
	add r0, sp, #0x34
	bl Sprite_CreateAffine
	mov r1, #0x76
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x76
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, r6, #0
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x76
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r6, r6, #1
	add r7, #0x28
	add r4, r4, #4
	cmp r6, #5
	blt _021E62F8
	mov r0, #0x6d
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r6, _021E6414 ; =ov37_021E7A80
	mov r7, #0
	add r4, r5, #0
	str r0, [sp, #0x30]
_021E6350:
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x38]
	ldrh r0, [r6]
	lsl r0, r0, #0xc
	str r0, [sp, #0x3c]
	ldrh r0, [r6, #2]
	lsl r0, r0, #0xc
	str r0, [sp, #0x40]
	add r0, sp, #0x34
	bl Sprite_CreateAffine
	mov r1, #0x92
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x92
	lsl r0, r0, #2
	ldrh r1, [r6, #4]
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	cmp r7, #8
	blt _021E6392
	mov r0, #0x92
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	bl Sprite_SetPriority
_021E6392:
	add r7, r7, #1
	add r6, r6, #6
	add r4, r4, #4
	cmp r7, #0xc
	blt _021E6350
	mov r0, #0x92
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #6
	bl Sprite_SetAnimCtrlSeq
	mov r7, #6
	mov r6, #0
	mov r4, #0x20
	lsl r7, r7, #0xe
_021E63B0:
	mov r0, #1
	lsl r1, r4, #0xc
	lsl r0, r0, #0x14
	add r0, r1, r0
	str r0, [sp, #0x40]
	add r0, sp, #0x34
	str r7, [sp, #0x3c]
	bl Sprite_CreateAffine
	mov r1, #0x21
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x21
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r6, #0
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x21
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawPriority
	mov r0, #0x21
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r6, r6, #1
	add r4, #0x20
	add r5, r5, #4
	cmp r6, #5
	blt _021E63B0
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add sp, #0x64
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6414: .word ov37_021E7A80
	thumb_func_end ov37_021E6244


	thumb_func_start ov37_021E6418
ov37_021E6418: ; 0x021E6418
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x28
	mov r1, #0xb6
	str r0, [sp, #0x10]
	lsl r1, r1, #2
	ldr r0, [r7]
	add r1, r7, r1
	mov r2, #0
	mov r3, #2
	bl AddWindowParameterized
	mov r0, #0xb6
	lsl r0, r0, #2
	add r0, r7, r0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	mov r0, #2
	str r0, [sp]
	mov r0, #0x1e
	str r0, [sp, #4]
	mov r0, #0xf
	str r0, [sp, #8]
	mov r0, #0
	mov r2, #1
	str r0, [sp, #0xc]
	str r2, [sp, #0x10]
	mov r1, #0xb2
	lsl r1, r1, #2
	ldr r0, [r7]
	add r1, r7, r1
	add r3, r2, #0
	bl AddWindowParameterized
	mov r0, #0xb2
	lsl r0, r0, #2
	add r0, r7, r0
	mov r1, #2
	bl FillWindowPixelBuffer
	mov r0, #0x15
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	ldr r0, _021E6534 ; =0x000001C3
	mov r1, #0xba
	str r0, [sp, #0x10]
	lsl r1, r1, #2
	ldr r0, [r7]
	add r1, r7, r1
	mov r2, #1
	mov r3, #0x19
	bl AddWindowParameterized
	mov r0, #0xba
	lsl r0, r0, #2
	add r0, r7, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r1, [r7, #0x28]
	mov r0, #1
	mov r2, #0
	mov r3, #0x30
	bl FontID_String_GetCenterAlignmentX
	add r3, r0, #0
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E6538 ; =0x00070100
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, #0xba
	lsl r0, r0, #2
	ldr r2, [r7, #0x28]
	add r0, r7, r0
	mov r1, #1
	add r3, r3, #2
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0
	str r0, [sp, #0x14]
	mov r0, #0x9e
	lsl r0, r0, #2
	mov r6, #1
	mov r4, #3
	add r5, r7, r0
_021E64E4:
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	lsl r0, r6, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [r7]
	add r1, r5, #0
	mov r2, #4
	mov r3, #5
	bl AddWindowParameterized
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x14]
	add r6, #0x14
	add r0, r0, #1
	add r4, r4, #4
	add r5, #0x10
	str r0, [sp, #0x14]
	cmp r0, #5
	blt _021E64E4
	mov r0, #0x9e
	lsl r0, r0, #2
	ldr r2, _021E653C ; =0x000E0D0F
	add r0, r7, r0
	mov r1, #0
	add r3, r7, #0
	bl ov37_021E7478
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6534: .word 0x000001C3
_021E6538: .word 0x00070100
_021E653C: .word 0x000E0D0F
	thumb_func_end ov37_021E6418

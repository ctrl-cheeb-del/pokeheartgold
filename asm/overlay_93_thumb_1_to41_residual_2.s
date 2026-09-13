	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225C768
	.public ov93_0225CA8C
	.public ov93_0225CD10
	.extern ov93_0225CEA0
	.extern ov93_0225CF14
	.extern ov93_0225CFB8
	.extern ov93_0225CFC0
	.extern ov93_0225D064
	.extern ov93_0225D07C
	.extern ov93_0225D1D8
	.extern ov93_0225D380
	.extern ov93_0225D468
	.extern ov93_0225D4B8
	.extern ov93_0225D4EC
	.extern ov93_0225D5AC
	.extern ov93_0225D674
	.extern ov93_0225D6E0
	.extern ov93_0225D78C
	.extern ov93_0225D9E8
	.extern ov93_0225DA40
	.extern ov93_0225DAF8
	.extern ov93_0225DB2C
	.extern ov93_0225DBC4
	.extern ov93_0225DBC8
	.extern ov93_0225DD28
	.extern ov93_0225DD2C
	.extern ov93_0225DED0
	.extern ov93_0225E10C
	.extern ov93_0225E300
	.extern ov93_0225E370
	.extern ov93_0225E4B0
	.extern ov93_0225E764
	.extern ov93_0225E7AC
	.extern ov93_0225E7B0
	.extern ov93_0225E860
	.extern ov93_02262A7C
	.extern ov93_02262A90
	.extern ov93_02262AA8

	thumb_func_start ov93_0225C768
ov93_0225C768: ; 0x0225C768
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r0, #1
	lsl r0, r0, #0x1a
	ldr r1, [r0]
	ldr r2, _0225CA54 ; =0xFFFFE0FF
	and r1, r2
	str r1, [r0]
	ldr r1, _0225CA58 ; =0x04001000
	ldr r3, [r1]
	and r2, r3
	str r2, [r1]
	ldr r3, [r0]
	ldr r2, _0225CA5C ; =0xFFFF1FFF
	and r3, r2
	str r3, [r0]
	ldr r3, [r1]
	add r0, #0x50
	and r2, r3
	str r2, [r1]
	mov r3, #0x10
	mov r1, #1
	mov r2, #0x3f
	str r3, [sp]
	bl G2x_SetBlendAlpha_
	mov r0, #3
	str r0, [sp]
	ldr r0, _0225CA60 ; =0x04001050
	mov r1, #8
	mov r2, #0x1f
	mov r3, #0xd
	bl G2x_SetBlendAlpha_
	ldr r1, _0225CA64 ; =0x00003850
	add r0, r4, #0
	mov r2, #0x75
	bl OverlayManager_CreateAndGetData
	ldr r2, _0225CA64 ; =0x00003850
	add r5, r0, #0
	mov r1, #0
	bl MI_CpuFill8
	add r0, r5, #0
	add r0, #0xa8
	mov r1, #0x75
	mov r2, #0x20
	bl HeapExp_FndInitAllocator
	mov r0, #0x75
	bl ov93_0225CF14
	add r1, r5, #0
	add r1, #0x98
	str r0, [r1]
	add r0, r4, #0
	bl OverlayManager_GetArgs
	str r0, [r5]
	add r0, r5, #0
	bl ov93_022626FC
	mov r0, #0x75
	bl PaletteData_Init
	add r1, r5, #0
	add r1, #0x8c
	str r0, [r1]
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #1
	bl PaletteData_SetAutoTransparent
	add r0, r5, #0
	add r0, #0x8c
	mov r2, #2
	ldr r0, [r0]
	mov r1, #0
	lsl r2, r2, #8
	mov r3, #0x75
	bl PaletteData_AllocBuffers
	add r0, r5, #0
	add r0, #0x8c
	mov r1, #1
	ldr r0, [r0]
	lsl r2, r1, #9
	mov r3, #0x75
	bl PaletteData_AllocBuffers
	add r0, r5, #0
	add r0, #0x8c
	mov r2, #7
	ldr r0, [r0]
	mov r1, #2
	lsl r2, r2, #6
	mov r3, #0x75
	bl PaletteData_AllocBuffers
	add r0, r5, #0
	add r0, #0x8c
	mov r2, #2
	ldr r0, [r0]
	mov r1, #3
	lsl r2, r2, #8
	mov r3, #0x75
	bl PaletteData_AllocBuffers
	mov r0, #0x75
	bl BgConfig_Alloc
	str r0, [r5, #0x2c]
	mov r0, #0x40
	mov r1, #0x75
	bl GF_CreateVramTransferManager
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	ldr r0, [r5, #0x2c]
	bl ov93_0225D1D8
	bl sub_020210BC
	mov r0, #4
	bl sub_02021148
	add r0, r5, #0
	bl ov93_0225CFC0
	mov r0, #0x75
	bl SpriteSystem_Alloc
	ldr r1, _0225CA68 ; =ov93_02262AA8
	ldr r2, _0225CA6C ; =ov93_02262A7C
	mov r3, #0x20
	str r0, [r5, #0x24]
	bl SpriteSystem_Init
	ldr r1, _0225CA70 ; =0x00100010
	mov r0, #1
	bl G2dRenderer_SetObjCharTransferReservedRegion
	mov r0, #1
	bl G2dRenderer_SetPlttTransferReservedRegion
	ldr r0, [r5, #0x24]
	bl SpriteManager_New
	str r0, [r5, #0x28]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r2, #0xe0
	bl SpriteSystem_InitSprites
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	ldr r2, _0225CA74 ; =ov93_02262A90
	bl SpriteSystem_InitManagerWithCapacities
	ldr r0, [r5, #0x24]
	bl SpriteSystem_GetRenderer
	mov r2, #0x16
	mov r1, #0
	lsl r2, r2, #0x10
	bl G2dRenderer_SetSubSurfaceCoords
	add r0, r5, #0
	bl ov93_0225D674
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xc
	mov r3, #0x75
	bl NewMsgDataFromNarc
	add r1, r5, #0
	add r1, #0x80
	str r0, [r1]
	mov r0, #0x75
	bl MessageFormat_New
	add r1, r5, #0
	add r1, #0x84
	str r0, [r1]
	mov r0, #5
	lsl r0, r0, #6
	mov r1, #0x75
	bl String_New
	add r1, r5, #0
	add r1, #0x88
	str r0, [r1]
	mov r0, #0x13
	mov r1, #0x75
	bl FontSystem_NewInit
	add r1, r5, #0
	add r1, #0x90
	str r0, [r1]
	ldr r1, _0225CA78 ; =0x00001468
	add r0, r5, #0
	add r1, r5, r1
	bl ov93_02261310
	mov r0, #0xc9
	mov r1, #0x75
	bl NARC_New
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl ov93_0225DB2C
	add r0, r5, #0
	add r1, r4, #0
	bl ov93_0225DBC8
	add r0, r5, #0
	bl ov93_0225D380
	add r0, r5, #0
	add r1, r4, #0
	bl ov93_0225D78C
	add r0, r5, #0
	add r1, r4, #0
	bl ov93_0225DA40
	add r0, r5, #0
	add r1, r4, #0
	bl ov93_0225DD2C
	add r0, r4, #0
	bl NARC_Delete
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xe0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #0x10
	mov r2, #7
	mov r3, #0x75
	bl PaletteData_LoadNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x50
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #0x10
	mov r2, #7
	mov r3, #0x75
	bl PaletteData_LoadNarc
	add r0, r5, #0
	bl ov93_0225D4EC
	add r0, r5, #0
	mov r1, #0
	bl ov93_0225D5AC
	add r0, r5, #0
	bl ov93_0225D468
	bl sub_0203A880
	add r0, r5, #0
	bl ov93_0225E7B0
	add r1, r5, #0
	add r1, #0xd4
	str r0, [r1]
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x75
	str r0, [sp, #8]
	mov r0, #0
	mov r1, #0x1b
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, _0225CA7C ; =ov93_0225D07C
	ldr r2, _0225CA80 ; =0x0000EA60
	add r1, r5, #0
	bl SysTask_CreateOnMainQueue
	add r1, r5, #0
	add r1, #0x94
	str r0, [r1]
	ldr r0, _0225CA84 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	bl GfGfx_BothDispOn
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #1
	bl TextFlags_SetAutoScrollParam
	mov r0, #0
	bl TextFlags_SetCanABSpeedUpPrint
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, [r5, #0x28]
	bl SpriteManager_GetSpriteList
	mov r1, #0x75
	bl ov90_02258BD4
	str r0, [r5, #0x1c]
	bl ov90_02258C74
	add r2, r0, #0
	add r0, r5, #0
	add r0, #0x8c
	lsl r2, r2, #0x14
	ldr r0, [r0]
	mov r1, #2
	lsr r2, r2, #0x10
	mov r3, #0x60
	bl PaletteData_LoadPaletteSlotFromHardware
	ldr r0, _0225CA88 ; =ov93_0225CEA0
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	ldr r0, [r5]
	add r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq _0225CA4C
	mov r0, #0x75
	bl ov00_021E69A8
_0225CA4C:
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_0225CA54: .word 0xFFFFE0FF
_0225CA58: .word 0x04001000
_0225CA5C: .word 0xFFFF1FFF
_0225CA60: .word 0x04001050
_0225CA64: .word 0x00003850
_0225CA68: .word ov93_02262AA8
_0225CA6C: .word ov93_02262A7C
_0225CA70: .word 0x00100010
_0225CA74: .word ov93_02262A90
_0225CA78: .word 0x00001468
_0225CA7C: .word ov93_0225D07C
_0225CA80: .word 0x0000EA60
_0225CA84: .word gSystem + 0x60
_0225CA88: .word ov93_0225CEA0
	thumb_func_end ov93_0225C768


	thumb_func_start ov93_0225CA8C
ov93_0225CA8C: ; 0x0225CA8C
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r1, [r4]
	add r2, r1, #0
	add r2, #0x3d
	ldrb r2, [r2]
	cmp r2, #1
	bne _0225CAF6
	add r0, r1, #0
	add r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #0
	beq _0225CAB2
	cmp r0, #1
	b _0225CAE0
_0225CAB2:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0225CABE
	bl sub_0200FB70
_0225CABE:
	mov r0, #0
	bl sub_0200FC20
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _0225CCE0 ; =0xFFFF1FFF
	and r0, r1
	str r0, [r2]
	ldr r1, [r4]
	add r0, r1, #0
	add r0, #0x3e
	ldrb r0, [r0]
	add r1, #0x3e
	add r0, r0, #1
	strb r0, [r1]
	b _0225CAF0
_0225CAE0:
	add r0, r1, #0
	bl ov90_02258B98
	cmp r0, #1
	bne _0225CAF0
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_0225CAF0:
	add sp, #0xc
	mov r0, #0
	pop {r4, r5, pc}
_0225CAF6:
	ldr r2, [r5]
	cmp r2, #6
	bhi _0225CB60
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0225CB08: ; jump table
	.short _0225CB16 - _0225CB08 - 2 ; case 0
	.short _0225CB26 - _0225CB08 - 2 ; case 1
	.short _0225CB34 - _0225CB08 - 2 ; case 2
	.short _0225CB46 - _0225CB08 - 2 ; case 3
	.short _0225CB56 - _0225CB08 - 2 ; case 4
	.short _0225CB6E - _0225CB08 - 2 ; case 5
	.short _0225CCBA - _0225CB08 - 2 ; case 6
_0225CB16:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0225CB60
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225CCC8
_0225CB26:
	mov r0, #0xd3
	bl sub_02037AC0
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225CCC8
_0225CB34:
	mov r0, #0xd3
	bl sub_02037B38
	cmp r0, #1
	bne _0225CB60
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225CCC8
_0225CB46:
	bl ov93_022627A4
	cmp r0, #1
	bne _0225CB60
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225CCC8
_0225CB56:
	add r1, #0x30
	ldrb r1, [r1]
	ldr r2, [r4, #8]
	cmp r2, r1
	bhs _0225CB62
_0225CB60:
	b _0225CCC8
_0225CB62:
	bl ov93_0225E10C
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0225CCC8
_0225CB6E:
	mov r1, #0xbf
	lsl r1, r1, #6
	ldr r1, [r4, r1]
	cmp r1, #1
	bne _0225CB9A
	bl ov93_02262250
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x75
	str r0, [sp, #8]
	mov r0, #0
	mov r1, #0x1a
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
_0225CB9A:
	add r0, r4, #0
	bl ov93_0225E764
	ldr r0, [r4, #0x20]
	cmp r0, #7
	bhi _0225CC78
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225CBB2: ; jump table
	.short _0225CC78 - _0225CBB2 - 2 ; case 0
	.short _0225CBC2 - _0225CBB2 - 2 ; case 1
	.short _0225CC0E - _0225CBB2 - 2 ; case 2
	.short _0225CC28 - _0225CBB2 - 2 ; case 3
	.short _0225CC34 - _0225CBB2 - 2 ; case 4
	.short _0225CC78 - _0225CBB2 - 2 ; case 5
	.short _0225CC5E - _0225CBB2 - 2 ; case 6
	.short _0225CC6A - _0225CBB2 - 2 ; case 7
_0225CBC2:
	mov r0, #1
	lsl r0, r0, #0x1a
	ldr r2, [r0]
	ldr r1, _0225CCE0 ; =0xFFFF1FFF
	add r3, r0, #0
	and r2, r1
	lsr r1, r0, #0xc
	orr r1, r2
	str r1, [r0]
	add r1, r0, #0
	ldr r2, _0225CCE4 ; =0x0000044C
	add r1, #0x42
	strh r2, [r1]
	add r1, r0, #0
	ldr r2, _0225CCE8 ; =0x0000A8B8
	add r1, #0x46
	strh r2, [r1]
	add r3, #0x48
	ldrh r2, [r3]
	ldr r1, _0225CCEC ; =0xFFFFC0FF
	and r2, r1
	lsr r1, r0, #0xe
	orr r1, r2
	strh r1, [r3]
	add r0, #0x4a
	ldrh r2, [r0]
	mov r1, #0x3f
	bic r2, r1
	mov r1, #0x1f
	orr r2, r1
	mov r1, #0x20
	orr r1, r2
	strh r1, [r0]
	add r0, r4, #0
	bl ov93_02262310
	mov r0, #2
	str r0, [r4, #0x20]
_0225CC0E:
	ldr r1, _0225CCF0 ; =0x0000174C
	add r0, r4, #0
	add r1, r4, r1
	bl ov93_02262374
	cmp r0, #1
	bne _0225CC78
	ldr r0, _0225CCF4 ; =0x00001768
	mov r1, #1
	str r1, [r4, r0]
	mov r0, #0
	str r0, [r4, #0x20]
	b _0225CC78
_0225CC28:
	ldr r0, [r4, #0x1c]
	bl ov90_02258C8C
	mov r0, #4
	str r0, [r4, #0x20]
	b _0225CC78
_0225CC34:
	ldr r0, [r4, #0x1c]
	bl ov90_02258CE0
	cmp r0, #1
	bne _0225CC78
	ldr r0, _0225CCF8 ; =0x00002FB8
	mov r1, #1
	str r1, [r4, r0]
	ldr r0, _0225CCFC ; =0x00001559
	mov r1, #0
	strb r1, [r4, r0]
	mov r0, #5
	str r0, [r4, #0x20]
	add r0, r4, #0
	bl ov93_0225D4B8
	add r0, r4, #0
	mov r1, #1
	bl ov93_0225D5AC
	b _0225CC78
_0225CC5E:
	ldr r0, [r4, #0x1c]
	bl ov90_02258CB0
	mov r0, #7
	str r0, [r4, #0x20]
	b _0225CC78
_0225CC6A:
	ldr r0, [r4, #0x1c]
	bl ov90_02258CE0
	cmp r0, #1
	bne _0225CC78
	mov r0, #8
	str r0, [r4, #0x20]
_0225CC78:
	add r0, r4, #0
	bl ov93_0225E4B0
	add r0, r4, #0
	bl ov93_0225E370
	ldr r0, _0225CD00 ; =0x00002FBC
	ldr r0, [r4, r0]
	cmp r0, #1
	beq _0225CCC8
	add r0, r4, #0
	bl ov93_0225E300
	cmp r0, #1
	bne _0225CC9C
	ldr r0, _0225CD04 ; =0x00002FC4
	mov r1, #0xd
	str r1, [r4, r0]
_0225CC9C:
	ldr r1, _0225CCF8 ; =0x00002FB8
	ldr r0, [r4, r1]
	cmp r0, #1
	bne _0225CCC8
	sub r0, r1, #4
	ldr r2, [r4, r0]
	ldr r0, _0225CD08 ; =0x00000516
	cmp r2, r0
	bhi _0225CCC8
	sub r0, r1, #4
	ldr r0, [r4, r0]
	add r2, r0, #1
	sub r0, r1, #4
	str r2, [r4, r0]
	b _0225CCC8
_0225CCBA:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0225CCC8
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_0225CCC8:
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	bl ov93_0225E7AC
	ldr r0, _0225CD0C ; =0x0000384C
	ldr r1, [r4, r0]
	add r1, r1, #1
	str r1, [r4, r0]
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_0225CCE0: .word 0xFFFF1FFF
_0225CCE4: .word 0x0000044C
_0225CCE8: .word 0x0000A8B8
_0225CCEC: .word 0xFFFFC0FF
_0225CCF0: .word 0x0000174C
_0225CCF4: .word 0x00001768
_0225CCF8: .word 0x00002FB8
_0225CCFC: .word 0x00001559
_0225CD00: .word 0x00002FBC
_0225CD04: .word 0x00002FC4
_0225CD08: .word 0x00000516
_0225CD0C: .word 0x0000384C
	thumb_func_end ov93_0225CA8C


	thumb_func_start ov93_0225CD10
ov93_0225CD10: ; 0x0225CD10
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, _0225CE94 ; =0x00002FD0
	ldr r1, [r4, r0]
	ldr r0, [r4]
	str r1, [r0, #0x24]
	ldr r0, [r4, #0x1c]
	bl ov90_02258C38
	add r0, r4, #0
	bl ov93_022602E4
	add r0, r4, #0
	bl ov93_02260608
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	add r0, r4, #0
	bl ov93_0225D6E0
	add r0, r4, #0
	bl ov93_0225D9E8
	add r0, r4, #0
	bl ov93_0225DAF8
	add r0, r4, #0
	bl ov93_0225DBC4
	add r0, r4, #0
	bl ov93_0225DD28
	add r0, r4, #0
	bl ov93_0225DED0
	add r1, r4, #0
	add r1, #0xd4
	ldr r1, [r1]
	add r0, r4, #0
	bl ov93_0225E860
	add r5, r4, #0
	mov r6, #0
	add r5, #0x30
_0225CD72:
	add r0, r5, #0
	bl RemoveWindow
	add r6, r6, #1
	add r5, #0x10
	cmp r6, #5
	blt _0225CD72
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r4, #0x2c]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x2c]
	mov r1, #2
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x2c]
	mov r1, #3
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x2c]
	mov r1, #4
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x2c]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x2c]
	mov r1, #6
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #0x2c]
	mov r1, #7
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	add r0, #0x90
	ldr r0, [r0]
	bl sub_020135AC
	ldr r0, [r4, #0x24]
	ldr r1, [r4, #0x28]
	bl SpriteSystem_FreeResourcesAndManager
	ldr r0, [r4, #0x24]
	bl SpriteSystem_Free
	bl GF_DestroyVramTransferManager
	add r0, r4, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #0
	bl PaletteData_FreeBuffers
	add r0, r4, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #1
	bl PaletteData_FreeBuffers
	add r0, r4, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #2
	bl PaletteData_FreeBuffers
	add r0, r4, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #3
	bl PaletteData_FreeBuffers
	add r0, r4, #0
	add r0, #0x8c
	ldr r0, [r0]
	bl PaletteData_Free
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl String_Delete
	add r0, r4, #0
	add r0, #0x84
	ldr r0, [r0]
	bl MessageFormat_Delete
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	bl DestroyMsgData
	ldr r0, [r4, #0x2c]
	bl Heap_Free
	add r0, r4, #0
	bl ov93_0225D064
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	bl SysTask_Destroy
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _0225CE98 ; =0xFFFF1FFF
	and r1, r0
	str r1, [r2]
	ldr r2, _0225CE9C ; =0x04001000
	add r4, #0x98
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	ldr r0, [r4]
	bl ov93_0225CFB8
	bl sub_02021238
	add r0, r7, #0
	bl OverlayManager_FreeData
	mov r0, #0
	bl TextFlags_SetCanABSpeedUpPrint
	mov r0, #0
	bl TextFlags_SetAutoScrollParam
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	bl sub_0203A914
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225CE94: .word 0x00002FD0
_0225CE98: .word 0xFFFF1FFF
_0225CE9C: .word 0x04001000
	thumb_func_end ov93_0225CD10

	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225D07C
	.public ov93_0225D1D8
	.public ov93_0225D380
	.extern ov93_0225E03C
	.extern ov93_0225E0A4
	.extern ov93_0225E898
	.extern ov93_02262A44
	.extern ov93_02262AC8
	.extern ov93_02262B40
	.extern ov93_02262B94

	thumb_func_start ov93_0225D07C
ov93_0225D07C: ; 0x0225D07C
	push {r4, lr}
	sub sp, #0x40
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #0x34]
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
	mov r0, #0
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	str r0, [sp, #0x30]
	add r0, sp, #4
	add r4, r1, #0
	bl MTX_Identity33_
	ldr r1, _0225D1B0 ; =0x000015A8
	add r0, r4, #0
	add r1, r4, r1
	bl ov93_02262034
	ldr r1, _0225D1B4 ; =0x00001468
	add r0, r4, #0
	add r1, r4, r1
	bl ov93_02261354
	ldr r1, _0225D1B8 ; =0x00001560
	add r0, r4, #0
	add r1, r4, r1
	bl ov93_02261D1C
	add r0, r4, #0
	bl ov93_0225FFF8
	ldr r2, _0225D1BC ; =0x00001428
	ldr r1, [r4, #0x2c]
	add r0, r4, #0
	add r2, r4, r2
	bl ov93_0225FE80
	add r0, r4, #0
	bl ov93_02260660
	add r0, r4, #0
	bl ov93_0225E03C
	add r0, r4, #0
	bl ov93_02260A30
	bl Thunk_G3X_Reset
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	bl Camera_SetStaticPtr
	add r1, r4, #0
	add r1, #0x9c
	ldr r1, [r1]
	mov r0, #1
	bl Camera_ApplyPerspectiveType
	bl Camera_PushLookAtToNNSGlb
	mov r0, #0
	ldr r2, _0225D1C0 ; =0xFFFFF000
	add r1, r0, #0
	add r3, r0, #0
	bl NNS_G3dGlbLightVector
	ldr r1, _0225D1C4 ; =0x0000739C
	mov r0, #0
	bl NNS_G3dGlbLightColor
	ldr r0, _0225D1C8 ; =0x00007FFF
	mov r2, #0
	add r1, r0, #0
	bl NNS_G3dGlbMaterialColorDiffAmb
	ldr r0, _0225D1C8 ; =0x00007FFF
	mov r2, #0
	add r1, r0, #0
	bl NNS_G3dGlbMaterialColorSpecEmi
	add r0, sp, #0x28
	bl NNS_G3dGlbSetBaseTrans
	ldr r1, _0225D1CC ; =NNS_G3dGlb + 0xBC
	add r0, sp, #4
	bl MI_Copy36B
	ldr r1, _0225D1D0 ; =NNS_G3dGlb + 0x80
	mov r0, #0xa4
	ldr r2, [r1, #0x7c]
	bic r2, r0
	add r0, sp, #0x34
	str r2, [r1, #0x7c]
	bl NNS_G3dGlbSetBaseScale
	bl NNS_G3dGlbFlushP
	add r1, r4, #0
	add r1, #0xd4
	ldr r1, [r1]
	add r0, r4, #0
	bl ov93_0225E898
	mov r1, #0
	mov r0, #0x11
	add r2, r1, #0
	bl NNS_G3dGeBufferOP_N
	ldr r0, _0225D1D4 ; =0x000013B0
	add r0, r4, r0
	bl sub_020181EC
	add r0, r4, #0
	add r0, #0xe8
	bl sub_020181EC
	add r0, r4, #0
	bl ov93_0225E0A4
	mov r2, #1
	mov r0, #0x12
	add r1, sp, #0
	str r2, [sp]
	bl NNS_G3dGeBufferOP_N
	bl Thunk_G3X_Reset
	bl sub_0201543C
	cmp r0, #0
	ble _0225D18C
	bl Thunk_G3X_Reset
_0225D18C:
	bl sub_02015460
	ldr r0, [r4, #0x28]
	bl SpriteSystem_DrawSprites
	bl SpriteSystem_UpdateTransfer
	mov r0, #0
	add r1, r0, #0
	bl RequestSwap3DBuffers
	ldr r1, [r4, #0x2c]
	mov r0, #0x75
	bl sub_020399FC
	add sp, #0x40
	pop {r4, pc}
	nop
_0225D1B0: .word 0x000015A8
_0225D1B4: .word 0x00001468
_0225D1B8: .word 0x00001560
_0225D1BC: .word 0x00001428
_0225D1C0: .word 0xFFFFF000
_0225D1C4: .word 0x0000739C
_0225D1C8: .word 0x00007FFF
_0225D1CC: .word NNS_G3dGlb + 0xBC
_0225D1D0: .word NNS_G3dGlb + 0x80
_0225D1D4: .word 0x000013B0
	thumb_func_end ov93_0225D07C


	thumb_func_start ov93_0225D1D8
ov93_0225D1D8: ; 0x0225D1D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x8c
	add r5, r0, #0
	bl GfGfx_DisableEngineAPlanes
	ldr r4, _0225D36C ; =ov93_02262AC8
	add r3, sp, #0x10
	mov r2, #5
_0225D1E8:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0225D1E8
	add r0, sp, #0x10
	bl GfGfx_SetBanks
	mov r1, #6
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x18
	lsl r2, r2, #0x12
	bl MIi_CpuClear32
	mov r1, #0x62
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x14
	lsl r2, r2, #0x10
	bl MIi_CpuClear32
	mov r1, #0x19
	mov r2, #1
	mov r0, #0
	lsl r1, r1, #0x16
	lsl r2, r2, #0x12
	bl MIi_CpuClear32
	mov r1, #0x66
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x14
	lsl r2, r2, #0x10
	bl MIi_CpuClear32
	ldr r4, _0225D370 ; =ov93_02262A44
	add r3, sp, #0
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _0225D374 ; =ov93_02262B40
	add r3, sp, #0x38
	mov r2, #0xa
_0225D248:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0225D248
	ldr r0, [r4]
	mov r1, #1
	str r0, [r3]
	add r0, r5, #0
	add r2, sp, #0x38
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r5, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	mov r2, #0
	add r0, r5, #0
	mov r1, #1
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add r0, r5, #0
	mov r1, #1
	mov r2, #3
	mov r3, #0
	bl BgSetPosTextAndCommit
	add r0, r5, #0
	mov r1, #2
	add r2, sp, #0x54
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r5, #0
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	mov r2, #0
	add r0, r5, #0
	mov r1, #2
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add r0, r5, #0
	mov r1, #2
	mov r2, #3
	mov r3, #0
	bl BgSetPosTextAndCommit
	add r0, r5, #0
	mov r1, #3
	add r2, sp, #0x70
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r5, #0
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	mov r2, #0
	add r0, r5, #0
	mov r1, #3
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	mov r1, #3
	add r0, r5, #0
	add r2, r1, #0
	mov r3, #0
	bl BgSetPosTextAndCommit
	ldr r1, _0225D378 ; =0x04000008
	mov r0, #3
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #2
	orr r0, r2
	strh r0, [r1]
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	mov r4, #0
	ldr r6, _0225D37C ; =ov93_02262B94
	add r7, r4, #0
_0225D2F4:
	cmp r4, #3
	bge _0225D30A
	add r1, r4, #4
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r2, r6, #0
	add r3, r7, #0
	bl InitBgFromTemplate
	b _0225D31A
_0225D30A:
	add r1, r4, #4
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r2, r6, #0
	mov r3, #1
	bl InitBgFromTemplate
_0225D31A:
	add r0, r4, #4
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x75
	bl BG_ClearCharDataRange
	add r1, r4, #4
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl BgClearTilemapBufferAndCommit
	add r1, r4, #4
	lsl r1, r1, #0x18
	mov r2, #0
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add r1, r4, #4
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl BgSetPosTextAndCommit
	add r4, r4, #1
	add r6, #0x1c
	cmp r4, #4
	blo _0225D2F4
	mov r0, #7
	mov r1, #0
	bl ToggleBgLayer
	add sp, #0x8c
	pop {r4, r5, r6, r7, pc}
	nop
_0225D36C: .word ov93_02262AC8
_0225D370: .word ov93_02262A44
_0225D374: .word ov93_02262B40
_0225D378: .word 0x04000008
_0225D37C: .word ov93_02262B94
	thumb_func_end ov93_0225D1D8


	thumb_func_start ov93_0225D380
ov93_0225D380: ; 0x0225D380
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r0, #0
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x14
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xe
	str r0, [sp, #0xc]
	mov r0, #3
	lsl r0, r0, #8
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4, #0x2c]
	add r1, #0x30
	mov r2, #1
	mov r3, #0xb
	bl AddWindowParameterized
	mov r0, #1
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #5
	str r0, [sp, #0xc]
	mov r0, #0xc5
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4, #0x2c]
	add r1, #0x40
	mov r2, #4
	mov r3, #0x12
	bl AddWindowParameterized
	mov r0, #0xe
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #5
	str r0, [sp, #0xc]
	mov r0, #0xca
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4, #0x2c]
	add r1, #0x50
	mov r2, #4
	mov r3, #0x15
	bl AddWindowParameterized
	mov r0, #0xe
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #5
	str r0, [sp, #0xc]
	mov r0, #0xcf
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4, #0x2c]
	add r1, #0x60
	mov r2, #4
	mov r3, #1
	bl AddWindowParameterized
	add r0, r4, #0
	add r0, #0x40
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x50
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x60
	mov r1, #0xf
	bl FillWindowPixelBuffer
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1c
	str r0, [sp, #4]
	mov r2, #4
	add r1, r4, #0
	str r2, [sp, #8]
	mov r0, #5
	str r0, [sp, #0xc]
	ldr r0, _0225D464 ; =0x00000359
	add r1, #0x70
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x2c]
	mov r3, #2
	bl AddWindowParameterized
	add r4, #0x70
	add r0, r4, #0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add sp, #0x14
	pop {r3, r4, pc}
	nop
_0225D464: .word 0x00000359
	thumb_func_end ov93_0225D380

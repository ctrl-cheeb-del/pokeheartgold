	.include "asm/macros.inc"
	.public _02258918
	.public _0225891C
	.public _02258920
	.public _02258924
	.public _02258928
	.public _0225894A
	.public _02258956
	.public _02258976
	.public _02258994
	.public _022589A4
	.public _022589CA
	.public _022589D0
	.public _022589EC
	.public _022589F0
	.public _022589F2
	.public _02258A0A
	.public _02258A32
	.public _02258A42
	.public _02258A4E
	.public _02258A64
	.public _02258A74
	.public _02258A80
	.public _02258AB2
	.public _02258ACE
	.public _02258ADC
	.public _02258B0E
	.public _02258B20
	.public _02258B22
	.public _02258B40
	.public _02258B46
	.public _02258B4C
	.public _02258B74
	.public _02258B94
	.public _02258BA6
	.public _02258BB4
	.public _02258BD8
	.public _02258BF6
	.public _02258C16
	.public _02258C24
	.public _02258C28
	.public _02258C30
	.public _02258C34
	.public _02258C68
	.public _02258CB0
	.public _02258D98
	.public _02258D9C
	.public _02258DA0
	.public _02258DA4
	.public _02258DC6
	.public _02258DD2
	.public _02258DE8
	.public _02258E06
	.public _02258E14
	.public _02258E2E
	.public _02258E3C
	.public _02258E4A
	.public _02258E5A
	.public _02258E6E
	.public _02258E74
	.public _02258E7E
	.public _02258E9A
	.public _02258EAE
	.public _02258EBC
	.public _02258EDC
	.public _02258EF2
	.public _02258EF8
	.public _02258F2C
	.public _02258F6C
	.public _02258FAE
	.public _02259126
	.public _02259138
	.public _02259142
	.public _0225915A
	.public _022591A6
	.public _022591F4
	.public _022591F8
	.public _022591FC
	.public _02259200
	.public _02259204
	.public _02259208
	.public _0225920C
	.public _02259246
	.public _02259254
	.public _0225926A
	.public _02259292
	.public _022592AE
	.public _022592B0
	.public _022592B4
	.public _02259598
	.public ov46_02258800
	.public ov46_0225892C
	.public ov46_02258C38
	.public ov46_02258CB4
	.public ov46_02258DA8
	.public ov46_02258EFC
	.public ov46_02258F78
	.public ov46_02259210
	.public ov46_022595A4
	.public ov46_022595B4
	.public ov46_022595DC
	.public _02259598
	.public ov46_02258800
	.public ov46_0225892C
	.public ov46_02258C38
	.public ov46_02258CB4
	.public ov46_02258DA8
	.public ov46_02258EFC
	.public ov46_02258F70
	.public ov46_02258F78
	.public ov46_02259210
	.public ov46_022592B8
	.public ov46_022592E0
	.public ov46_022592EC
	.public ov46_02259374
	.public ov46_022593F8
	.public ov46_02259450
	.public ov46_02259474
	.public ov46_02259494
	.public ov46_022594E0
	.public ov46_02259534
	.public ov46_02259550
	.include "overlay_46.inc"
	.include "global.inc"

	.text
	.public ov46_02258F70
	.public ov46_022592B8
	.public ov46_022592E0
	.public ov46_022592EC
	.public ov46_02259374
	.public ov46_022593F8
	.public ov46_02259450
	.public ov46_02259474
	.public ov46_02259494
	.public ov46_022594E0
	.public ov46_02259534
	.public ov46_02259550

	thumb_func_start ov46_02258F78
ov46_02258F78: ; 0x02258F78
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	str r0, [sp, #0x10]
	add r6, r1, #0
	ldr r0, _022591F4 ; =0x04000050
	mov r1, #0
	strh r1, [r0]
	ldr r0, _022591F8 ; =0x04001050
	strh r1, [r0]
	ldr r0, _022591FC ; =ov46_022595B4
	bl GfGfx_SetBanks
	mov r0, #0
	add r1, r0, #0
	bl BG_SetMaskColor
	ldr r0, _02259200 ; =ov46_022595A4
	bl SetBothScreensModesAndDisable
	add r0, r6, #0
	bl BgConfig_Alloc
	ldr r1, [sp, #0x10]
	ldr r4, _02259204 ; =ov46_022595DC
	ldr r5, _02259208 ; =_02259598
	str r0, [r1, #0xc]
	mov r7, #0
_02258FAE:
	ldr r0, [sp, #0x10]
	ldr r1, [r5]
	ldr r0, [r0, #0xc]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r2, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r5]
	mov r1, #0x20
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r2, #0
	add r3, r6, #0
	bl BG_ClearCharDataRange
	ldr r0, [sp, #0x10]
	ldr r1, [r5]
	ldr r0, [r0, #0xc]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl BgClearTilemapBufferAndCommit
	add r7, r7, #1
	add r4, #0x1c
	add r5, r5, #4
	cmp r7, #3
	blt _02258FAE
	ldr r0, [sp, #0x10]
	ldr r0, [r0]
	bl Save_PlayerData_GetOptionsAddr
	bl Options_GetFrame
	lsl r0, r0, #0x18
	mov r1, #5
	lsr r4, r0, #0x18
	mov r0, #0
	lsl r1, r1, #6
	add r2, r6, #0
	bl LoadFontPal0
	mov r1, #0x12
	mov r0, #0
	lsl r1, r1, #4
	add r2, r6, #0
	bl LoadFontPal1
	mov r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x10]
	str r6, [sp, #4]
	ldr r0, [r0, #0xc]
	mov r1, #1
	mov r2, #0x1f
	mov r3, #0xc
	bl LoadUserFrameGfx1
	str r4, [sp]
	mov r1, #1
	ldr r0, [sp, #0x10]
	str r6, [sp, #4]
	ldr r0, [r0, #0xc]
	add r2, r1, #0
	mov r3, #0xb
	bl LoadUserFrameGfx2
	mov r0, #0x12
	lsl r0, r0, #4
	str r0, [sp]
	mov r2, #0
	mov r0, #0x58
	mov r1, #3
	add r3, r2, #0
	str r6, [sp, #4]
	bl GfGfxLoader_GXLoadPal
	mov r0, #0x12
	lsl r0, r0, #4
	str r0, [sp]
	mov r0, #0x58
	mov r1, #3
	mov r2, #4
	mov r3, #0
	str r6, [sp, #4]
	bl GfGfxLoader_GXLoadPal
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r2, [sp, #0x10]
	str r6, [sp, #0xc]
	ldr r2, [r2, #0xc]
	mov r0, #0x58
	mov r1, #2
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r2, [sp, #0x10]
	str r6, [sp, #0xc]
	ldr r2, [r2, #0xc]
	mov r0, #0x58
	mov r1, #0xb
	mov r3, #4
	bl GfGfxLoader_LoadCharData
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r2, [sp, #0x10]
	str r6, [sp, #0xc]
	ldr r2, [r2, #0xc]
	mov r0, #0x58
	mov r1, #6
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r2, [sp, #0x10]
	str r6, [sp, #0xc]
	ldr r2, [r2, #0xc]
	mov r0, #0x58
	mov r1, #0xc
	mov r3, #4
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x58
	add r1, r6, #0
	bl NARC_New
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x10]
	mov r2, #0x33
	add r0, #0xd4
	mov r1, #0
	lsl r2, r2, #4
	bl MI_CpuFill8
	ldr r0, [sp, #0x2c]
	mov r1, #5
	add r2, sp, #0x38
	add r3, r6, #0
	bl GfGfxLoader_GetPlttDataFromOpenNarc
	add r4, r0, #0
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x10]
	ldr r0, [r0, #0xc]
	add r1, #0xdc
	mov r2, #0x80
	bl MIi_CpuCopy16
	ldr r0, [sp, #0x38]
	mov r2, #0x57
	ldr r1, [sp, #0x10]
	lsl r2, r2, #2
	add r1, r1, r2
	ldr r0, [r0, #0xc]
	mov r2, #0x80
	bl MIi_CpuCopy16
	add r0, r4, #0
	bl Heap_Free
	mov r0, #0
	mov r1, #0x57
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x10]
	lsl r1, r1, #2
	add r0, r0, r1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, #0xdc
	str r0, [sp, #0x14]
_02259126:
	mov r0, #0
	str r0, [sp, #0x20]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	lsl r1, r0, #5
	ldr r0, [sp, #0x10]
	add r0, r0, r1
	str r0, [sp, #0x30]
_02259138:
	ldr r0, [sp, #0x24]
	cmp r0, #0x15
	blt _02259142
	bl GF_AssertFail
_02259142:
	ldr r0, [sp, #0x30]
	mov r7, #1
	add r6, r0, #2
	ldr r0, [sp, #0x18]
	add r4, r0, #2
	ldr r0, [sp, #0x14]
	add r5, r0, #2
	ldr r0, [sp, #0x20]
	asr r0, r0, #8
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x34]
_0225915A:
	add r0, r6, #0
	add r0, #0xdc
	ldrh r0, [r0]
	ldr r3, [sp, #0x34]
	add r1, r4, #0
	str r0, [sp]
	add r0, r5, #0
	mov r2, #1
	bl BlendPalette
	add r7, r7, #1
	add r6, r6, #2
	add r4, r4, #2
	add r5, r5, #2
	cmp r7, #0x10
	blt _0225915A
	ldr r0, [sp, #0x18]
	add r0, #0x20
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x24]
	add r0, r0, #1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x1c]
	cmp r0, #1
	beq _022591A6
	mov r0, #3
	ldr r1, [sp, #0x20]
	lsl r0, r0, #8
	add r1, r1, r0
	mov r0, #1
	lsl r0, r0, #0xc
	str r1, [sp, #0x20]
	cmp r1, r0
	blt _02259138
	str r0, [sp, #0x20]
	mov r0, #1
	str r0, [sp, #0x1c]
	b _02259138
_022591A6:
	ldr r0, [sp, #0x14]
	add r0, #0x20
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	str r0, [sp, #0x28]
	cmp r0, #3
	blt _02259126
	mov r1, #0x57
	ldr r0, [sp, #0x10]
	lsl r1, r1, #2
	add r0, r0, r1
	mov r1, #0x2a
	lsl r1, r1, #4
	bl DC_FlushRange
	ldr r0, [sp, #0x10]
	mov r1, #1
	add r0, #0xd8
	str r1, [r0]
	ldr r0, [sp, #0x10]
	mov r2, #0
	lsl r1, r1, #0xa
	str r2, [r0, r1]
	ldr r1, [sp, #0x10]
	ldr r0, _0225920C ; =ov46_02259210
	add r1, #0xd4
	mov r2, #0x14
	bl SysTask_CreateOnVBlankQueue
	ldr r1, [sp, #0x10]
	add r1, #0xd4
	str r0, [r1]
	ldr r0, [sp, #0x2c]
	str r1, [sp, #0x10]
	bl NARC_Delete
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022591F4: .word 0x04000050
_022591F8: .word 0x04001050
_022591FC: .word ov46_022595B4
_02259200: .word ov46_022595A4
_02259204: .word ov46_022595DC
_02259208: .word _02259598
_0225920C: .word ov46_02259210
	thumb_func_end ov46_02258F78


	thumb_func_start ov46_02259210
ov46_02259210: ; 0x02259210
	push {r4, lr}
	add r4, r1, #0
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _022592AE
	ldr r1, _022592B0 ; =0x0000032B
	mov r0, #1
	ldrb r2, [r4, r1]
	eor r2, r0
	strb r2, [r4, r1]
	ldrb r2, [r4, r1]
	tst r0, r2
	bne _022592AE
	add r0, r1, #1
	ldr r0, [r4, r0]
	cmp r0, #1
	bhi _02259246
	sub r0, r1, #3
	ldrsh r0, [r4, r0]
	add r2, r4, #0
	add r2, #0x88
	lsl r0, r0, #5
	add r0, r2, r0
	mov r1, #0
	mov r2, #0x20
	bl GX_LoadBGPltt
_02259246:
	mov r0, #0xcb
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02259254
	cmp r0, #2
	bne _0225926A
_02259254:
	mov r0, #0xca
	lsl r0, r0, #2
	ldrsh r0, [r4, r0]
	add r1, r4, #0
	add r1, #0x88
	lsl r0, r0, #5
	add r0, r1, r0
	mov r1, #0
	mov r2, #0x20
	bl GXS_LoadBGPltt
_0225926A:
	ldr r0, _022592B4 ; =0x0000032A
	ldrsb r1, [r4, r0]
	cmp r1, #0
	bne _02259292
	sub r1, r0, #2
	ldrsh r1, [r4, r1]
	add r2, r1, #1
	sub r1, r0, #2
	strh r2, [r4, r1]
	ldrsh r1, [r4, r1]
	cmp r1, #0x15
	blt _022592AE
	mov r2, #0x13
	sub r1, r0, #2
	strh r2, [r4, r1]
	ldrsb r2, [r4, r0]
	mov r1, #1
	eor r1, r2
	strb r1, [r4, r0]
	pop {r4, pc}
_02259292:
	sub r1, r0, #2
	ldrsh r1, [r4, r1]
	sub r2, r1, #1
	sub r1, r0, #2
	strh r2, [r4, r1]
	ldrsh r1, [r4, r1]
	cmp r1, #0
	bge _022592AE
	mov r2, #1
	sub r1, r0, #2
	strh r2, [r4, r1]
	ldrsb r1, [r4, r0]
	eor r1, r2
	strb r1, [r4, r0]
_022592AE:
	pop {r4, pc}
	.balign 4, 0
_022592B0: .word 0x0000032B
_022592B4: .word 0x0000032A
	thumb_func_end ov46_02259210

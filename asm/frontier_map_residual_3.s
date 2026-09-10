
	.public FrontierMap_Free
	.public FrontierMap_Init
	.public FrontierMap_LoadPaletteData
	.public FrontierMap_Scroll
	.public FrontierMap_SetVramBank
	.public FrontierMap_Update
	.public ov80_02238A18
	.public ov80_02238B7C
	.public ov80_02238C78
	.public ov80_02238FA0
	.public ov80_02239004
	.public ov80_022392F8
	.public ov80_022393E8
	.public ov80_0223947C
	.public ov80_02239510
	.public ov80_02239740
	.public ov80_02239828
	.public ov80_02239914
	.public ov80_0223D554
	.public ov80_0223D560
	.public ov80_0223D570
	.public ov80_0223D584
	.public ov80_0223D59C
	.public ov80_0223D5B8
	.public ov80_0223D5D8
	.public ov80_0223D600
	.public ov80_0223D654
	.include "asm/macros.inc"
	.include "overlay_80_02238648.inc"
	.include "global.inc"

    .text
	.public FrontierMap_VBlank
	.public ov80_022389C4
	.public ov80_02238AAC
	.public ov80_02238AB0
	.public ov80_02238ABC
	.public ov80_0223927C
	.public ov80_022392DC
	.public ov80_0223937C
	.public ov80_02239384
	.public ov80_022394D8
	.public ov80_02239590
	.public ov80_022395E8
	.public ov80_0223962C
	.public ov80_0223965C
	.public ov80_0223968C
	.public ov80_022396D8
	.public ov80_02239700
	.public ov80_02239708
	.public ov80_02239734
	.public ov80_022398E4
	.public ov80_02239900
	.public ov80_02239938

	thumb_func_start FrontierMap_Update
FrontierMap_Update: ; 0x02238AC8
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	ldr r0, [r7, #8]
	mov r1, #0x1f
	bl sub_0209686C
	ldr r1, [r0]
	cmp r1, #0
	beq _02238AE2
	add r0, r7, #0
	add r0, #0x1c
	bl ov42_02229358
_02238AE2:
	add r0, r7, #0
	bl FrontierMap_Scroll
	ldr r0, [r7, #0x20]
	bl ov42_022290DC
	ldr r4, [r7, #0x6c]
	mov r6, #0
	add r5, r7, #0
_02238AF4:
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	beq _02238B04
	mov r1, #1
	tst r1, r4
	beq _02238B04
	bl ManagedSprite_TickFrame
_02238B04:
	add r6, r6, #1
	lsr r4, r4, #1
	add r5, r5, #4
	cmp r6, #8
	blt _02238AF4
	ldr r0, [r7, #0x38]
	bl SpriteSystem_DrawSprites
	bl SpriteSystem_UpdateTransfer
	bl ov80_02239A38
	mov r0, #1
	mov r1, #0
	bl RequestSwap3DBuffers
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end FrontierMap_Update


	thumb_func_start FrontierMap_Scroll
FrontierMap_Scroll: ; 0x02238B28
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5, #8]
	bl Frontier_GetLaunchArgs
	add r4, r0, #0
	add r0, #0x20
	ldrb r0, [r0]
	mov r1, #0xc
	bl ov80_0222ACA0
	cmp r0, #0
	beq _02238B46
	cmp r0, #1
	beq _02238B74
_02238B46:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _02238B54
	add r1, r5, #0
	add r1, #0x1c
	bl ov42_02229420
_02238B54:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _02238B7A
	add r4, #0x20
	ldrb r0, [r4]
	mov r1, #0xd
	bl ov80_0222ACA0
	cmp r0, #1
	bne _02238B7A
	ldr r0, [r5, #0x28]
	add r5, #0x1c
	add r1, r5, #0
	bl ov42_02229420
	pop {r3, r4, r5, pc}
_02238B74:
	add r0, r5, #0
	bl ov80_02238B7C
_02238B7A:
	pop {r3, r4, r5, pc}
	thumb_func_end FrontierMap_Scroll


	thumb_func_start ov80_02238B7C
ov80_02238B7C: ; 0x02238B7C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #8]
	bl Frontier_GetLaunchArgs
	add r7, r0, #0
	add r0, r5, #0
	add r0, #0x1c
	bl ov42_022293A8
	mov r1, #0xaa
	ldrsh r1, [r5, r1]
	add r0, r1, r0
	lsl r0, r0, #0x10
	asr r4, r0, #0x10
	add r0, r5, #0
	add r0, #0x1c
	bl ov42_022293B0
	mov r1, #0xa8
	ldrsh r1, [r5, r1]
	add r0, r1, r0
	lsl r0, r0, #0x10
	asr r6, r0, #0x10
	cmp r4, #0
	ble _02238BC6
	lsl r0, r4, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	str r0, [sp, #4]
	b _02238BD6
_02238BC6:
	lsl r0, r4, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
	str r0, [sp, #4]
_02238BD6:
	cmp r6, #0
	ble _02238BEE
	lsl r0, r6, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	str r0, [sp]
	b _02238BFE
_02238BEE:
	lsl r0, r6, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
	str r0, [sp]
_02238BFE:
	ldr r0, [r5, #0x34]
	bl SpriteSystem_GetRenderer
	str r0, [sp, #8]
	ldr r0, [sp]
	bl _ffix
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	bl _ffix
	add r2, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	bl G2dRenderer_SetMainSurfaceCoords
	ldr r0, [r5]
	mov r1, #3
	mov r2, #0
	add r3, r6, #0
	bl ScheduleSetBgPosText
	mov r1, #3
	ldr r0, [r5]
	add r2, r1, #0
	add r3, r4, #0
	bl ScheduleSetBgPosText
	add r0, r7, #0
	add r0, #0x20
	ldrb r0, [r0]
	mov r1, #9
	bl ov80_0222ACA0
	ldr r1, _02238C74 ; =0x0000FFFF
	cmp r0, r1
	beq _02238C6E
	add r7, #0x20
	ldrb r0, [r7]
	mov r1, #0xd
	bl ov80_0222ACA0
	cmp r0, #1
	bne _02238C6E
	ldr r0, [r5]
	mov r1, #2
	mov r2, #0
	add r3, r6, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5]
	mov r1, #2
	mov r2, #3
	add r3, r4, #0
	bl ScheduleSetBgPosText
_02238C6E:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02238C74: .word 0x0000FFFF
	thumb_func_end ov80_02238B7C


	thumb_func_start ov80_02238C78
ov80_02238C78: ; 0x02238C78
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, [r5, #0x30]
	add r1, sp, #0
	bl ov42_02229A08
	cmp r0, #1
	bne _02238CA0
	add r4, sp, #0
_02238C8C:
	ldr r0, [r5, #0x14]
	add r1, r4, #0
	bl ov42_02228068
	ldr r0, [r5, #0x30]
	add r1, r4, #0
	bl ov42_02229A08
	cmp r0, #1
	beq _02238C8C
_02238CA0:
	ldr r0, [r5, #0x2c]
	add r1, sp, #8
	bl ov42_02229AC8
	cmp r0, #1
	bne _02238CD4
	add r6, sp, #0
	add r4, sp, #8
_02238CB0:
	ldr r0, [r5, #0x18]
	ldr r1, [r5, #0x14]
	add r2, r4, #0
	add r3, r6, #0
	bl ov42_02228C80
	cmp r0, #1
	bne _02238CC8
	ldr r0, [r5, #0x14]
	add r1, r6, #0
	bl ov42_02228068
_02238CC8:
	ldr r0, [r5, #0x2c]
	add r1, r4, #0
	bl ov42_02229AC8
	cmp r0, #1
	beq _02238CB0
_02238CD4:
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	thumb_func_end ov80_02238C78


	thumb_func_start FrontierMap_SetVramBank
FrontierMap_SetVramBank: ; 0x02238CD8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa8
	add r7, r1, #0
	add r5, r0, #0
	add r0, r7, #0
	mov r1, #0
	bl ov80_0222ACA0
	add r4, r0, #0
	bl GfGfx_DisableEngineAPlanes
	ldr r6, _02238EF8 ; =ov80_0223D5D8
	add r3, sp, #0x2c
	mov r2, #5
_02238CF4:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02238CF4
	add r0, sp, #0x2c
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
	ldr r6, _02238EFC ; =ov80_0223D560
	add r3, sp, #0x1c
	add r2, r3, #0
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	str r4, [sp, #0x20]
	bl SetBothScreensModesAndDisable
	ldr r6, _02238F00 ; =ov80_0223D600
	add r3, sp, #0x54
	mov r2, #0xa
_02238D56:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02238D56
	ldr r0, [r6]
	cmp r4, #0
	str r0, [r3]
	bne _02238D74
	mov r2, #0
	add r1, sp, #0x74
	strb r2, [r1, #0xd]
	add r0, sp, #0x94
	strb r2, [r0, #9]
	strb r2, [r1, #0x10]
	strb r2, [r0, #0xc]
_02238D74:
	add r0, r7, #0
	mov r1, #4
	bl ov80_0222ACA0
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	add r0, sp, #0x94
	strb r6, [r0, #8]
	add r0, r7, #0
	mov r1, #9
	bl ov80_0222ACA0
	ldr r1, _02238F04 ; =0x0000FFFF
	cmp r0, r1
	beq _02238D96
	add r0, sp, #0x74
	strb r6, [r0, #0xc]
_02238D96:
	cmp r4, #0
	add r2, sp, #0x54
	bne _02238E20
	add r0, r5, #0
	mov r1, #1
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
	add r2, sp, #0x70
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
	add r2, sp, #0x8c
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
	b _02238EA2
_02238E20:
	add r0, r5, #0
	mov r1, #1
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
	mov r1, #2
	add r0, r5, #0
	add r2, sp, #0x70
	add r3, r1, #0
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
	add r2, sp, #0x8c
	mov r3, #2
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
_02238EA2:
	ldr r1, _02238F08 ; =0x04000008
	mov r0, #3
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #1
	strh r2, [r1]
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	ldr r4, _02238F0C ; =ov80_0223D59C
	add r3, sp, #0
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	mov r1, #4
	str r0, [r3]
	add r0, r5, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r5, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	mov r2, #0
	add r0, r5, #0
	mov r1, #4
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add r0, r5, #0
	mov r1, #4
	mov r2, #3
	mov r3, #0
	bl BgSetPosTextAndCommit
	add sp, #0xa8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02238EF8: .word ov80_0223D5D8
_02238EFC: .word ov80_0223D560
_02238F00: .word ov80_0223D600
_02238F04: .word 0x0000FFFF
_02238F08: .word 0x04000008
_02238F0C: .word ov80_0223D59C
	thumb_func_end FrontierMap_SetVramBank


	thumb_func_start FrontierMap_LoadPaletteData
FrontierMap_LoadPaletteData: ; 0x02238F10
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xe0
	str r0, [sp, #8]
	ldr r0, [r4, #4]
	mov r1, #0x10
	mov r2, #7
	mov r3, #0x65
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xd0
	str r0, [sp, #8]
	ldr r0, [r4, #4]
	mov r1, #0x10
	mov r2, #8
	mov r3, #0x65
	bl PaletteData_LoadNarc
	ldr r0, [r4, #8]
	bl Frontier_GetLaunchArgs
	ldr r0, [r0, #4]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x65
	str r0, [sp, #4]
	ldr r0, [r4]
	ldr r2, _02238F98 ; =0x000003E2
	mov r1, #1
	mov r3, #0xb
	bl LoadUserFrameGfx2
	ldr r0, [r4, #4]
	mov r1, #0
	mov r2, #0xb0
	mov r3, #0x20
	bl PaletteData_LoadPaletteSlotFromHardware
	mov r0, #0
	str r0, [sp]
	mov r0, #0x65
	str r0, [sp, #4]
	ldr r0, [r4]
	ldr r2, _02238F9C ; =0x000003D9
	mov r1, #1
	mov r3, #0xc
	bl LoadUserFrameGfx1
	ldr r0, [r4, #4]
	mov r1, #0
	mov r2, #0xc0
	mov r3, #0x20
	bl PaletteData_LoadPaletteSlotFromHardware
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_02238F98: .word 0x000003E2
_02238F9C: .word 0x000003D9
	thumb_func_end FrontierMap_LoadPaletteData


	thumb_func_start ov80_02238FA0
ov80_02238FA0: ; 0x02238FA0
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0xb7
	mov r1, #0x65
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	mov r1, #0x65
	str r1, [sp, #0xc]
	ldr r2, [r5]
	mov r1, #0x81
	mov r3, #4
	add r4, r0, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x65
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #0x82
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [r5, #4]
	mov r1, #0xb7
	mov r2, #0xbe
	mov r3, #0x65
	bl PaletteData_LoadNarc
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov80_02238FA0


	thumb_func_start ov80_02239004
ov80_02239004: ; 0x02239004
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r5, r0, #0
	add r4, r1, #0
	mov r0, #0x20
	mov r1, #0x65
	add r6, r2, #0
	bl ov42_02228010
	str r0, [r5, #0x14]
	mov r0, #0x10
	add r1, r0, #0
	mov r2, #0x65
	bl ov42_02227EE0
	str r0, [r5, #0x18]
	add r0, r5, #0
	add r0, #0x1c
	bl ov42_02229394
	ldr r0, [r5, #0x38]
	bl SpriteManager_GetSpriteList
	add r7, r0, #0
	add r0, r6, #0
	bl ov80_0222A7EC
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x65
	str r0, [sp, #8]
	ldr r1, [r5, #4]
	add r0, r7, #0
	mov r2, #0x20
	bl ov42_02228F24
	ldr r3, _02239270 ; =ov80_0223D554
	str r0, [r5, #0x20]
	add r2, sp, #0x20
	mov r1, #0xb
_0223905A:
	ldrb r0, [r3]
	add r3, r3, #1
	strb r0, [r2]
	add r2, r2, #1
	sub r1, r1, #1
	bne _0223905A
	add r0, r4, #0
	mov r1, #5
	bl ov80_0222ACA0
	add r1, sp, #0x18
	strb r0, [r1, #0x10]
	add r0, r4, #0
	mov r1, #6
	bl ov80_0222ACA0
	add r1, sp, #0x18
	strb r0, [r1, #0x11]
	add r0, r4, #0
	mov r1, #0xc
	bl ov80_0222ACA0
	add r6, r0, #0
	bne _0223909C
	ldr r0, [r5, #0x34]
	bl SpriteSystem_GetRenderer
	ldr r1, [r5]
	add r2, sp, #0x20
	mov r3, #0x65
	bl ov42_022293B8
	str r0, [r5, #0x24]
_0223909C:
	add r0, r4, #0
	mov r1, #9
	bl ov80_0222ACA0
	ldr r1, _02239274 ; =0x0000FFFF
	cmp r0, r1
	beq _022390DA
	add r0, r4, #0
	mov r1, #9
	bl ov80_0222ACA0
	add r1, sp, #0x18
	strb r0, [r1, #0x11]
	mov r0, #2
	strb r0, [r1, #9]
	mov r2, #1
	mov r0, #8
	strb r2, [r1, #0xb]
	strb r0, [r1, #0xc]
	strb r2, [r1, #0xe]
	cmp r6, #0
	bne _022390DA
	ldr r0, [r5, #0x34]
	bl SpriteSystem_GetRenderer
	ldr r1, [r5]
	add r2, sp, #0x20
	mov r3, #0x65
	bl ov42_022293B8
	str r0, [r5, #0x28]
_022390DA:
	mov r0, #0x80
	mov r1, #0x65
	bl ov42_02229A40
	str r0, [r5, #0x2c]
	mov r0, #0x80
	mov r1, #0x65
	bl ov42_02229974
	str r0, [r5, #0x30]
	ldr r0, [r5, #0x18]
	ldr r1, _02239278 ; =ov80_0223D654
	bl ov42_02227F48
	add r0, r4, #0
	mov r1, #0
	bl ov80_0222ACA0
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #5
	bl ov80_0222ACA0
	mov r1, #0x65
	str r0, [sp, #0x10]
	bl NARC_New
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #7
	bl ov80_0222ACA0
	add r1, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x65
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r6, #0
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	cmp r7, #0
	bne _0223915A
	add r0, r4, #0
	mov r1, #8
	bl ov80_0222ACA0
	add r2, r0, #0
	mov r1, #0
	mov r0, #0x16
	str r1, [sp]
	lsl r0, r0, #4
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r5, #4]
	ldr r1, [sp, #0x10]
	mov r3, #0x65
	bl PaletteData_LoadNarc
	b _02239198
_0223915A:
	add r0, r4, #0
	mov r1, #8
	bl ov80_0222ACA0
	add r1, r0, #0
	add r0, r6, #0
	add r2, sp, #0x1c
	mov r3, #0x65
	bl GfGfxLoader_GetPlttDataFromOpenNarc
	ldr r1, [sp, #0x1c]
	str r0, [sp, #0x14]
	ldr r0, [r1, #0xc]
	ldr r1, [r1, #8]
	bl DC_FlushRange
	bl GX_BeginLoadBGExtPltt
	ldr r0, [sp, #0x1c]
	mov r1, #6
	mov r2, #2
	ldr r0, [r0, #0xc]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	bl GX_LoadBGExtPltt
	bl GX_EndLoadBGExtPltt
	ldr r0, [sp, #0x14]
	bl Heap_Free
_02239198:
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r5, #4]
	mov r2, #2
	add r3, r1, #0
	bl PaletteData_FillPaletteInBuffer
	add r0, r4, #0
	mov r1, #6
	bl ov80_0222ACA0
	add r1, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x65
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r6, #0
	mov r3, #3
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r0, r4, #0
	mov r1, #9
	bl ov80_0222ACA0
	ldr r1, _02239274 ; =0x0000FFFF
	cmp r0, r1
	beq _0223925E
	add r0, r4, #0
	mov r1, #0xa
	bl ov80_0222ACA0
	add r1, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x65
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r6, #0
	mov r3, #2
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	add r0, r4, #0
	mov r1, #9
	bl ov80_0222ACA0
	add r1, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x65
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r6, #0
	mov r3, #2
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	cmp r7, #0
	beq _0223925E
	add r0, r4, #0
	mov r1, #0xb
	bl ov80_0222ACA0
	add r1, r0, #0
	add r0, r6, #0
	add r2, sp, #0x18
	mov r3, #0x65
	bl GfGfxLoader_GetPlttDataFromOpenNarc
	ldr r1, [sp, #0x18]
	add r4, r0, #0
	ldr r0, [r1, #0xc]
	ldr r1, [r1, #8]
	bl DC_FlushRange
	bl GX_BeginLoadBGExtPltt
	ldr r0, [sp, #0x18]
	mov r1, #1
	lsl r1, r1, #0xe
	ldr r0, [r0, #0xc]
	lsr r2, r1, #1
	bl GX_LoadBGExtPltt
	bl GX_EndLoadBGExtPltt
	add r0, r4, #0
	bl Heap_Free
_0223925E:
	ldr r0, [r5]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
	add r0, r6, #0
	bl NARC_Delete
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02239270: .word ov80_0223D554
_02239274: .word 0x0000FFFF
_02239278: .word ov80_0223D654
	thumb_func_end ov80_02239004

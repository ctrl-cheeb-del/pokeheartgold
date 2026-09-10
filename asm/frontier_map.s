
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

	thumb_func_start FrontierMap_Init
FrontierMap_Init: ; 0x02238648
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl Frontier_GetLaunchArgs
	add r4, r0, #0
	ldr r0, [r4, #8]
	bl Save_PlayerData_GetProfile
	add r7, r0, #0
	mov r0, #0
	add r4, #0x20
	add r1, r0, #0
	ldrb r5, [r4]
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r1, #1
	lsl r1, r1, #0x1a
	ldr r0, [r1]
	ldr r2, _02238828 ; =0xFFFFE0FF
	and r0, r2
	str r0, [r1]
	ldr r0, _0223882C ; =0x04001000
	ldr r3, [r0]
	and r2, r3
	str r2, [r0]
	ldr r3, [r1]
	ldr r2, _02238830 ; =0xFFFF1FFF
	and r3, r2
	str r3, [r1]
	ldr r3, [r0]
	add r1, #0x50
	and r2, r3
	str r2, [r0]
	mov r2, #0
	strh r2, [r1]
	add r0, #0x50
	strh r2, [r0]
	ldr r2, _02238834 ; =0x04000304
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	mov r2, #9
	mov r0, #3
	mov r1, #0x65
	lsl r2, r2, #0x10
	bl Heap_Create
	mov r0, #0x65
	mov r1, #0xc4
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0xc4
	add r4, r0, #0
	bl MI_CpuFill8
	add r0, r4, #0
	str r6, [r4, #8]
	add r0, #0xc1
	ldr r1, _02238838 ; =0x0000FFFF
	strb r5, [r0]
	mov r2, #0
	add r3, r4, #0
_022386D4:
	add r0, r3, #0
	add r0, #0x70
	add r2, r2, #1
	add r3, r3, #2
	strh r1, [r0]
	cmp r2, #8
	blt _022386D4
	mov r0, #0x65
	bl ov80_022392DC
	str r0, [r4, #0xc]
	mov r0, #0x65
	bl PaletteData_Init
	str r0, [r4, #4]
	mov r1, #1
	bl PaletteData_SetAutoTransparent
	mov r2, #2
	ldr r0, [r4, #4]
	mov r1, #0
	lsl r2, r2, #8
	mov r3, #0x65
	bl PaletteData_AllocBuffers
	mov r1, #1
	ldr r0, [r4, #4]
	lsl r2, r1, #9
	mov r3, #0x65
	bl PaletteData_AllocBuffers
	mov r2, #7
	ldr r0, [r4, #4]
	mov r1, #2
	lsl r2, r2, #6
	mov r3, #0x65
	bl PaletteData_AllocBuffers
	mov r2, #2
	ldr r0, [r4, #4]
	mov r1, #3
	lsl r2, r2, #8
	mov r3, #0x65
	bl PaletteData_AllocBuffers
	mov r0, #0x65
	bl BgConfig_Alloc
	str r0, [r4]
	mov r0, #0x40
	mov r1, #0x65
	bl GF_CreateVramTransferManager
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	ldr r0, [r4]
	add r1, r5, #0
	bl FrontierMap_SetVramBank
	add r0, r4, #0
	bl FrontierMap_LoadPaletteData
	add r0, r4, #0
	bl ov80_02238FA0
	bl sub_020210BC
	mov r0, #4
	bl sub_02021148
	add r0, r4, #0
	bl ov80_02239384
	mov r0, #0x65
	bl ov80_02239960
	str r0, [r4, #0x10]
	add r0, r4, #0
	add r1, r5, #0
	add r2, r7, #0
	bl ov80_02239004
	ldr r0, _0223883C ; =ov80_02238AB0
	ldr r2, _02238840 ; =0x0000EA60
	add r1, r4, #0
	bl SysTask_CreateOnMainQueue
	add r1, r4, #0
	add r1, #0x94
	str r0, [r1]
	ldr r0, _02238844 ; =ov80_02238ABC
	ldr r2, _02238848 ; =0x0000EE48
	add r1, r4, #0
	bl SysTask_CreateOnMainQueue
	add r1, r4, #0
	add r1, #0x98
	str r0, [r1]
	ldr r0, _0223884C ; =FrontierMap_Update
	ldr r2, _02238850 ; =0x00013880
	add r1, r4, #0
	bl SysTask_CreateOnMainQueue
	add r1, r4, #0
	add r1, #0x9c
	str r0, [r1]
	bl GfGfx_BothDispOn
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add r0, r5, #0
	mov r1, #3
	bl ov80_0222ACA0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl Sound_SetFieldBGM
	add r0, r5, #0
	mov r1, #3
	bl ov80_0222ACA0
	add r1, r0, #0
	lsl r1, r1, #0x10
	mov r0, #0
	lsr r1, r1, #0x10
	bl sub_02055198
	mov r0, #1
	bl TextFlags_SetAutoScrollParam
	mov r0, #0
	bl TextFlags_SetCanABSpeedUpPrint
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, _02238854 ; =FrontierMap_VBlank
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	ldr r0, _02238858 ; =ov80_02238AAC
	add r1, r4, #0
	mov r2, #0xa
	bl SysTask_CreateOnVBlankQueue
	add r1, r4, #0
	add r1, #0xa0
	str r0, [r1]
	add r2, r4, #0
	add r2, #0xc1
	add r1, r4, #0
	ldrb r2, [r2]
	add r0, r4, #0
	add r1, #0x90
	bl ov80_0222AD9C
	bl sub_0203A880
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02238828: .word 0xFFFFE0FF
_0223882C: .word 0x04001000
_02238830: .word 0xFFFF1FFF
_02238834: .word 0x04000304
_02238838: .word 0x0000FFFF
_0223883C: .word ov80_02238AB0
_02238840: .word 0x0000EA60
_02238844: .word ov80_02238ABC
_02238848: .word 0x0000EE48
_0223884C: .word FrontierMap_Update
_02238850: .word 0x00013880
_02238854: .word FrontierMap_VBlank
_02238858: .word ov80_02238AAC
	thumb_func_end FrontierMap_Init


	thumb_func_start FrontierMap_Free
FrontierMap_Free: ; 0x0223885C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #8]
	bl Frontier_GetLaunchArgs
	add r2, r4, #0
	add r2, #0xc1
	add r1, r4, #0
	ldrb r2, [r2]
	add r0, r4, #0
	add r1, #0x90
	bl ov80_0222ADB4
	add r0, r4, #0
	bl ov80_0223927C
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r4]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #2
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #3
	bl FreeBgTilemapBuffer
	mov r0, #4
	mov r1, #0
	bl ToggleBgLayer
	ldr r0, [r4]
	mov r1, #4
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	bl ov80_022393E8
	ldr r0, [r4, #0x10]
	bl ov80_02239980
	bl GF_DestroyVramTransferManager
	ldr r0, [r4, #4]
	mov r1, #0
	bl PaletteData_FreeBuffers
	ldr r0, [r4, #4]
	mov r1, #1
	bl PaletteData_FreeBuffers
	ldr r0, [r4, #4]
	mov r1, #2
	bl PaletteData_FreeBuffers
	ldr r0, [r4, #4]
	mov r1, #3
	bl PaletteData_FreeBuffers
	ldr r0, [r4, #4]
	bl PaletteData_Free
	ldr r0, [r4]
	bl Heap_Free
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	bl SysTask_Destroy
	add r0, r4, #0
	add r0, #0x98
	ldr r0, [r0]
	bl SysTask_Destroy
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	bl SysTask_Destroy
	add r0, r4, #0
	add r0, #0xa0
	ldr r0, [r0]
	bl SysTask_Destroy
	ldr r0, [r4, #0xc]
	bl ov80_0223937C
	bl sub_02021238
	add r0, r4, #0
	bl Heap_Free
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _022389A4 ; =0xFFFF1FFF
	and r1, r0
	str r1, [r2]
	ldr r2, _022389A8 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	mov r0, #0x65
	bl Heap_Destroy
	mov r0, #0
	bl TextFlags_SetCanABSpeedUpPrint
	mov r0, #0
	bl TextFlags_SetAutoScrollParam
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	bl sub_0203A914
	mov r1, #5
	mov r2, #2
	ldr r0, _022389AC ; =0x00007FFF
	lsl r1, r1, #0x18
	lsl r2, r2, #8
	bl MIi_CpuClear16
	mov r2, #2
	ldr r0, _022389AC ; =0x00007FFF
	ldr r1, _022389B0 ; =0x05000200
	lsl r2, r2, #8
	bl MIi_CpuClear16
	mov r2, #2
	ldr r0, _022389AC ; =0x00007FFF
	ldr r1, _022389B4 ; =0x05000400
	lsl r2, r2, #8
	bl MIi_CpuClear16
	mov r2, #2
	ldr r0, _022389AC ; =0x00007FFF
	ldr r1, _022389B8 ; =0x05000600
	lsl r2, r2, #8
	bl MIi_CpuClear16
	ldr r0, _022389BC ; =0x04000050
	mov r1, #0
	strh r1, [r0]
	ldr r0, _022389C0 ; =0x04001050
	strh r1, [r0]
	pop {r4, pc}
	nop
_022389A4: .word 0xFFFF1FFF
_022389A8: .word 0x04001000
_022389AC: .word 0x00007FFF
_022389B0: .word 0x05000200
_022389B4: .word 0x05000400
_022389B8: .word 0x05000600
_022389BC: .word 0x04000050
_022389C0: .word 0x04001050
	thumb_func_end FrontierMap_Free

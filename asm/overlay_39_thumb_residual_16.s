#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_39_thumb.inc"
	.include "global.inc"

	.text
	.public _0222AB80
	.public ov39_02227088
	.public ov39_022271CC
	.public ov39_02227208
	.public ov39_022272EC
	.public ov39_022273B0
	.public ov39_02227420
	.public ov39_022274D4
	.public ov39_02227534
	.public ov39_02227590
	.public ov39_022275E8
	.public ov39_02227648
	.public ov39_02227778
	.public ov39_022278D4
	.public ov39_02227A5C
	.public ov39_02227B24
	.public ov39_02227B5C
	.public ov39_02227D5C
	.public ov39_02227DE4
	.public ov39_02227DEC
	.public ov39_02227E8C
	.public ov39_02227F14
	.public ov39_02227FEC
	.public ov39_0222801C
	.public ov39_022280D4
	.public ov39_02228140
	.public ov39_02228308
	.public ov39_02228370
	.public ov39_02228418
	.public ov39_02228440
	.public ov39_022285CC
	.public ov39_022287F8
	.public ov39_022288A0
	.public ov39_02228964
	.public ov39_0222899C
	.public ov39_022289D0
	.public ov39_02228A34
	.public ov39_02228AC0
	.public ov39_02228B04
	.public ov39_02228BAC
	.public ov39_02228C78
	.public ov39_02228D0C
	.public ov39_02228DA0
	.public ov39_02228E54
	.public ov39_02228EC8
	.public ov39_02228F18
	.public ov39_02228F54
	.public ov39_02228FC8
	.public ov39_022290A4
	.public ov39_0222915C
	.public ov39_02229224
	.public ov39_0222A8B0
	.public ov39_0222A8B4
	.public ov39_0222A8C0
	.public ov39_0222A8D4
	.public ov39_0222A8E4
	.public ov39_0222A90C
	.public ov39_0222A944
	.public ov39_0222AA20
	.public ov39_02227060
	.public ov39_02227080
	.public ov39_02227188
	.public ov39_022271A4
	.public ov39_022271C0
	.public ov39_02227334
	.public ov39_02227348
	.public ov39_02227364
	.public ov39_0222738C
	.public ov39_022273F8
	.public ov39_0222748C
	.public ov39_022274B4
	.public ov39_022276A4
	.public ov39_022276E0
	.public ov39_02227720
	.public ov39_0222774C
	.public ov39_02227B1C
	.public ov39_02227B20
	.public ov39_02227B50
	.public ov39_02227B54
	.public ov39_02227B58
	.public ov39_02227D44
	.public ov39_02227D50
	.public ov39_02227DB8
	.public ov39_02227E3C
	.public ov39_02227E48
	.public ov39_02227E6C
	.public ov39_02227ECC
	.public ov39_02227EF4
	.public ov39_02227F60
	.public ov39_02227F74
	.public ov39_02227F84
	.public ov39_02227FA8
	.public ov39_02227FC4
	.public ov39_02227FFC
	.public ov39_022280B4
	.public ov39_02228120
	.public ov39_022285A8
	.public ov39_02228948
	.public ov39_02228A70
	.public ov39_02228A8C
	.public ov39_02228AA8
	.public ov39_02228B6C
	.public ov39_02228B74
	.public ov39_02228D90
	.public ov39_02228EA4
	.public ov39_0222908C

	thumb_func_start ov39_02228140
ov39_02228140: ; 0x02228140
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r1, #1
	lsl r1, r1, #0x1a
	ldr r0, [r1]
	ldr r2, _022282EC ; =0xFFFFE0FF
	and r0, r2
	str r0, [r1]
	ldr r0, _022282F0 ; =0x04001000
	ldr r3, [r0]
	and r2, r3
	str r2, [r0]
	ldr r3, [r1]
	ldr r2, _022282F4 ; =0xFFFF1FFF
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
	mov r2, #5
	mov r0, #3
	mov r1, #0x7c
	lsl r2, r2, #0x10
	bl Heap_Create
	mov r1, #0xf6
	add r0, r4, #0
	lsl r1, r1, #2
	mov r2, #0x7c
	bl OverlayManager_CreateAndGetData
	mov r2, #0xf6
	mov r1, #0
	lsl r2, r2, #2
	add r5, r0, #0
	bl MI_CpuFill8
	add r0, r4, #0
	bl OverlayManager_GetArgs
	str r0, [r5]
	mov r0, #0x7c
	bl BgConfig_Alloc
	str r0, [r5, #4]
	mov r0, #0x40
	mov r1, #0x7c
	bl GF_CreateVramTransferManager
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	ldr r0, [r5, #4]
	bl ov39_02228440
	bl sub_020210BC
	mov r0, #4
	bl sub_02021148
	mov r0, #0xb
	mov r1, #0x40
	mov r2, #0x7c
	bl MessageFormat_New_Custom
	str r0, [r5, #0x20]
	ldr r2, _022282F8 ; =0x00000307
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x7c
	bl NewMsgDataFromNarc
	str r0, [r5, #0x24]
	ldr r2, _022282FC ; =0x0000030A
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x7c
	bl NewMsgDataFromNarc
	mov r2, #0x32
	str r0, [r5, #0x28]
	mov r0, #0
	mov r1, #0x1b
	lsl r2, r2, #4
	mov r3, #0x7c
	bl NewMsgDataFromNarc
	str r0, [r5, #0x2c]
	mov r0, #0xb4
	mov r1, #0x7c
	bl String_New
	str r0, [r5, #0x34]
	mov r0, #1
	lsl r0, r0, #8
	mov r1, #0x7c
	bl String_New
	str r0, [r5, #0x3c]
	ldr r0, [r5, #0x24]
	mov r1, #0x1f
	bl NewString_ReadMsgData
	str r0, [r5, #0x38]
	add r0, r5, #0
	bl ov39_022285CC
	add r0, r5, #0
	bl ov39_022288A0
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x7c
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, _02228300 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #1
	bl TextFlags_SetCanABSpeedUpPrint
	mov r0, #0
	bl TextFlags_SetAutoScrollParam
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, _02228304 ; =ov39_02228418
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	ldr r1, [r5]
	ldr r0, [r1, #4]
	cmp r0, #0
	beq _022282B8
	bl sub_0203A880
	add r0, r5, #0
	mov r1, #0xd
	mov r2, #8
	bl ov39_02228B6C
	b _022282CA
_022282B8:
	ldr r0, [r1]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _022282C6
	mov r0, #1
	str r0, [r5, #8]
	b _022282CA
_022282C6:
	mov r0, #0
	str r0, [r5, #8]
_022282CA:
	ldr r0, [r5]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl Save_PlayerData_GetOptionsAddr
	bl Options_GetTextFrameDelay
	add r1, r5, #0
	add r1, #0x90
	str r0, [r1]
	ldr r0, [r5]
	mov r1, #0
	str r1, [r0, #0x7c]
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_022282EC: .word 0xFFFFE0FF
_022282F0: .word 0x04001000
_022282F4: .word 0xFFFF1FFF
_022282F8: .word 0x00000307
_022282FC: .word 0x0000030A
_02228300: .word gSystem + 0x60
_02228304: .word ov39_02228418
	thumb_func_end ov39_02228140


	thumb_func_start ov39_02228308
ov39_02228308: ; 0x02228308
	push {r4, r5, r6, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	cmp r1, #0
	beq _02228322
	cmp r1, #1
	beq _02228330
	cmp r1, #2
	beq _0222835C
	b _02228368
_02228322:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _02228368
	mov r0, #1
	str r0, [r5]
	b _02228368
_02228330:
	ldr r6, [r4, #8]
	ldr r1, _0222836C ; =ov39_0222AA20
	lsl r2, r6, #2
	ldr r1, [r1, r2]
	blx r1
	ldr r1, [r4, #8]
	cmp r6, r1
	beq _02228352
	add r1, r4, #0
	mov r2, #0
	add r1, #0x94
	str r2, [r1]
	add r1, r4, #0
	add r1, #0x9c
	str r2, [r1]
	add r4, #0x98
	str r2, [r4]
_02228352:
	cmp r0, #1
	bne _02228368
	mov r0, #2
	str r0, [r5]
	b _02228368
_0222835C:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _02228368
	mov r0, #1
	pop {r4, r5, r6, pc}
_02228368:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222836C: .word ov39_0222AA20
	thumb_func_end ov39_02228308


	thumb_func_start ov39_02228370
ov39_02228370: ; 0x02228370
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _02228394
	bl SysTask_Destroy
	add r0, r4, #0
	mov r1, #0
	add r0, #0xa8
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xac
	str r1, [r0]
_02228394:
	ldr r0, [r4, #0x2c]
	bl DestroyMsgData
	ldr r0, [r4, #0x28]
	bl DestroyMsgData
	ldr r0, [r4, #0x24]
	bl DestroyMsgData
	ldr r0, [r4, #0x20]
	bl MessageFormat_Delete
	ldr r0, [r4, #0x38]
	bl String_Delete
	ldr r0, [r4, #0x3c]
	bl String_Delete
	ldr r0, [r4, #0x34]
	bl String_Delete
	add r0, r4, #0
	bl ov39_02228948
	ldr r0, [r4, #4]
	bl Heap_Free
	ldr r0, [r4, #4]
	bl ov39_022285A8
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GF_DestroyVramTransferManager
	bl sub_02021238
	mov r0, #0
	bl TextFlags_SetCanABSpeedUpPrint
	mov r0, #0
	bl TextFlags_SetAutoScrollParam
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	bl sub_0203A914
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x7c
	bl Heap_Destroy
	ldr r0, _02228414 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02228414: .word gSystem + 0x60
	thumb_func_end ov39_02228370


	thumb_func_start ov39_02228418
ov39_02228418: ; 0x02228418
	push {r4, lr}
	add r4, r0, #0
	bl GF_RunVramTransferTasks
	bl OamManager_ApplyAndResetBuffers
	ldr r0, [r4, #4]
	bl DoScheduledBgGpuUpdates
	ldr r3, _02228438 ; =0x027E0000
	ldr r1, _0222843C ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_02228438: .word 0x027E0000
_0222843C: .word 0x00003FF8
	thumb_func_end ov39_02228418


	thumb_func_start ov39_02228440
ov39_02228440: ; 0x02228440
	push {r3, r4, r5, lr}
	sub sp, #0xa8
	add r4, r0, #0
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	ldr r5, _02228598 ; =ov39_0222A8E4
	add r3, sp, #0x80
	mov r2, #5
_02228454:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02228454
	add r0, sp, #0x80
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
	ldr r5, _0222859C ; =ov39_0222A8D4
	add r3, sp, #0x70
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _022285A0 ; =ov39_0222A90C
	add r3, sp, #0x38
	mov r2, #7
_022284B4:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _022284B4
	mov r1, #0
	add r0, r4, #0
	add r2, sp, #0x38
	add r3, r1, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	add r3, r1, #0
	bl BgSetPosTextAndCommit
	mov r1, #0
	add r0, r4, #0
	mov r2, #3
	add r3, r1, #0
	bl BgSetPosTextAndCommit
	add r0, r4, #0
	mov r1, #1
	add r2, sp, #0x54
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	mov r2, #0
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add r0, r4, #0
	mov r1, #1
	mov r2, #3
	mov r3, #0
	bl BgSetPosTextAndCommit
	ldr r5, _022285A4 ; =ov39_0222A944
	add r3, sp, #0
	mov r2, #7
_0222851A:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0222851A
	add r0, r4, #0
	mov r1, #4
	add r2, sp, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	mov r2, #0
	add r0, r4, #0
	mov r1, #4
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add r0, r4, #0
	mov r1, #4
	mov r2, #3
	mov r3, #0
	bl BgSetPosTextAndCommit
	add r0, r4, #0
	mov r1, #5
	add r2, sp, #0x1c
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	mov r2, #0
	add r0, r4, #0
	mov r1, #5
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add r0, r4, #0
	mov r1, #5
	mov r2, #3
	mov r3, #0
	bl BgSetPosTextAndCommit
	mov r0, #0
	mov r1, #0x20
	add r2, r0, #0
	mov r3, #0x7c
	bl BG_ClearCharDataRange
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x7c
	bl BG_ClearCharDataRange
	add sp, #0xa8
	pop {r3, r4, r5, pc}
	nop
_02228598: .word ov39_0222A8E4
_0222859C: .word ov39_0222A8D4
_022285A0: .word ov39_0222A90C
_022285A4: .word ov39_0222A944
	thumb_func_end ov39_02228440

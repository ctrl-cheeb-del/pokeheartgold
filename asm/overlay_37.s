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

	thumb_func_start ov37_021E5900
ov37_021E5900: ; 0x021E5900
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r1, #0
	ldr r1, [r5]
	add r6, r0, #0
	cmp r1, #0
	beq _021E5916
	cmp r1, #1
	bne _021E5914
	b _021E5A56
_021E5914:
	b _021E5A64
_021E5916:
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _021E5A6C ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021E5A70 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	mov r0, #3
	mov r1, #0x27
	lsl r2, r2, #6
	bl Heap_Create
	ldr r1, _021E5A74 ; =0x0000940C
	add r0, r6, #0
	mov r2, #0x27
	bl OverlayManager_CreateAndGetData
	ldr r2, _021E5A74 ; =0x0000940C
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x27
	bl BgConfig_Alloc
	str r0, [r4]
	mov r0, #0x27
	bl MessageFormat_New
	str r0, [r4, #0xc]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xfc
	mov r3, #0x27
	bl NewMsgDataFromNarc
	str r0, [r4, #0x10]
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	bl ov37_021E5CF0
	ldr r0, [r4]
	bl ov37_021E5D10
	mov r0, #0
	add r1, r0, #0
	bl sub_0200FBF4
	mov r0, #1
	mov r1, #0
	bl sub_0200FBF4
	mov r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x27
	str r0, [sp, #8]
	mov r0, #0
	mov r1, #0x11
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	add r0, r6, #0
	bl OverlayManager_GetArgs
	str r0, [r4, #8]
	mov r0, #0x4e
	mov r1, #0x27
	bl NARC_New
	add r7, r0, #0
	add r0, r4, #0
	add r1, r7, #0
	bl ov37_021E5F98
	bl sub_020210BC
	mov r0, #2
	bl sub_02021148
	ldr r0, _021E5A78 ; =ov37_021E5CC8
	ldr r1, [r4]
	bl Main_SetVBlankIntrCB
	add r0, r4, #0
	bl ov37_021E5E30
	bl ov37_021E6090
	add r0, r4, #0
	add r1, r7, #0
	bl ov37_021E60C0
	add r0, r4, #0
	bl ov37_021E6244
	add r0, r4, #0
	add r1, r6, #0
	bl ov37_021E6418
	mov r1, #0
	mov r0, #0x34
	add r2, r1, #0
	bl Sound_SetSceneAndPlayBGM
	ldr r2, _021E5A7C ; =0x04000304
	ldr r0, _021E5A80 ; =0xFFFF7FFF
	ldrh r1, [r2]
	and r0, r1
	strh r0, [r2]
	add r0, r4, #0
	bl sub_0208F814
	mov r0, #0
	mov r1, #1
	bl sub_020398D4
	bl sub_0203769C
	cmp r0, #0
	bne _021E5A30
	mov r0, #3
	bl sub_02038C1C
_021E5A30:
	bl sub_0203A880
	bl sub_0203769C
	cmp r0, #0
	bne _021E5A48
	mov r0, #1
	bl sub_0205A904
	mov r0, #1
	bl sub_020356EC
_021E5A48:
	add r0, r7, #0
	bl NARC_Delete
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _021E5A64
_021E5A56:
	bl OverlayManager_GetData
	mov r0, #0
	str r0, [r5]
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_021E5A64:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021E5A6C: .word 0xFFFFE0FF
_021E5A70: .word 0x04001000
_021E5A74: .word 0x0000940C
_021E5A78: .word ov37_021E5CC8
_021E5A7C: .word 0x04000304
_021E5A80: .word 0xFFFF7FFF
	thumb_func_end ov37_021E5900


	thumb_func_start ov37_021E5A84
ov37_021E5A84: ; 0x021E5A84
	push {r3, r4, r5, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	bl sub_0203769C
	cmp r0, #0
	bne _021E5AAA
	ldr r0, _021E5B80 ; =0x000093B4
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E5AAA
	bl sub_02033250
	ldr r1, _021E5B80 ; =0x000093B4
	ldr r2, [r4, r1]
	and r0, r2
	str r0, [r4, r1]
_021E5AAA:
	mov r0, #3
	ldr r1, [r5]
	lsl r0, r0, #8
	str r1, [r4, r0]
	ldr r1, [r5]
	add r0, r4, #0
	bl ov37_021E784C
	ldr r1, [r5]
	cmp r1, #3
	bhi _021E5B74
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E5ACC: ; jump table
	.short _021E5AD4 - _021E5ACC - 2 ; case 0
	.short _021E5B02 - _021E5ACC - 2 ; case 1
	.short _021E5B48 - _021E5ACC - 2 ; case 2
	.short _021E5B68 - _021E5ACC - 2 ; case 3
_021E5AD4:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5B74
	bl sub_0203769C
	cmp r0, #0
	beq _021E5AFC
	bl ov37_021E75C4
	cmp r0, #2
	blt _021E5B74
	mov r1, #0
	mov r0, #0x80
	add r2, r1, #0
	bl sub_02037030
	mov r0, #1
	str r0, [r5]
	b _021E5B74
_021E5AFC:
	mov r0, #1
	str r0, [r5]
	b _021E5B74
_021E5B02:
	mov r0, #0xc1
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r2, r0, #3
	ldr r0, _021E5B84 ; =ov37_021E7D20
	ldr r2, [r0, r2]
	cmp r2, #0
	beq _021E5B18
	add r0, r4, #0
	blx r2
	str r0, [r5]
_021E5B18:
	mov r0, #0x9e
	lsl r0, r0, #2
	ldr r2, _021E5B88 ; =0x000E0D0F
	add r0, r4, r0
	mov r1, #0
	add r3, r4, #0
	bl ov37_021E7478
	bl sub_0203769C
	cmp r0, #0
	bne _021E5B3E
	add r0, r4, #0
	bl ov37_021E76F0
	ldr r1, [r5]
	cmp r1, #1
	bne _021E5B3E
	str r0, [r5]
_021E5B3E:
	ldr r0, _021E5B8C ; =0x00004374
	add r0, r4, r0
	bl ov37_021E741C
	b _021E5B74
_021E5B48:
	mov r0, #0xc1
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r3, r0, #3
	ldr r0, _021E5B84 ; =ov37_021E7D20
	ldr r2, [r0, r3]
	cmp r2, #0
	beq _021E5B74
	ldr r0, _021E5B90 ; =ov37_021E7D20 + 4
	ldr r0, [r0, r3]
	cmp r0, #0
	beq _021E5B74
	add r0, r4, #0
	blx r2
	str r0, [r5]
	b _021E5B74
_021E5B68:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5B74
	mov r0, #1
	pop {r3, r4, r5, pc}
_021E5B74:
	ldr r0, [r4, #0x34]
	bl SpriteList_RenderAndAnimateSprites
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_021E5B80: .word 0x000093B4
_021E5B84: .word ov37_021E7D20
_021E5B88: .word 0x000E0D0F
_021E5B8C: .word 0x00004374
_021E5B90: .word ov37_021E7D20 + 4
	thumb_func_end ov37_021E5A84


	thumb_func_start ov37_021E5B94
ov37_021E5B94: ; 0x021E5B94
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	add r7, r1, #0
	bl OverlayManager_GetData
	add r6, r0, #0
	add r0, r4, #0
	bl OverlayManager_GetArgs
	add r5, r0, #0
	ldr r0, [r7]
	cmp r0, #3
	bls _021E5BB0
	b _021E5CBE
_021E5BB0:
	add r1, r0, r0
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E5BBC: ; jump table
	.short _021E5BC4 - _021E5BBC - 2 ; case 0
	.short _021E5C40 - _021E5BBC - 2 ; case 1
	.short _021E5C6E - _021E5BBC - 2 ; case 2
	.short _021E5C8E - _021E5BBC - 2 ; case 3
_021E5BC4:
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeleteCharTransferTask
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeleteCharTransferTask
	mov r0, #0x5d
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r4, #0
	add r5, r6, #0
_021E5BF8:
	mov r0, #0x16
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl Destroy2DGfxResObjMan
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _021E5BF8
	ldr r0, [r6, #0x34]
	bl SpriteList_Delete
	bl OamManager_Free
	bl ObjCharTransfer_Destroy
	bl ObjPlttTransfer_Destroy
	add r0, r6, #0
	bl ov37_021E6540
	ldr r0, [r6]
	bl ov37_021E5F5C
	bl sub_02021238
	ldr r0, [r6, #0x10]
	bl DestroyMsgData
	ldr r0, [r6, #0xc]
	bl MessageFormat_Delete
	ldr r0, [r7]
	add r0, r0, #1
	str r0, [r7]
	b _021E5CBE
_021E5C40:
	mov r0, #1
	bl sub_02038C1C
	bl sub_02037FF0
	ldr r0, [r5]
	bl sub_0205AD24
	ldr r2, _021E5CC4 ; =0x04000304
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	mov r0, #0
	bl sub_0205A904
	mov r0, #0
	bl sub_020356EC
	ldr r0, [r7]
	add r0, r0, #1
	str r0, [r7]
	b _021E5CBE
_021E5C6E:
	mov r1, #0x25
	lsl r1, r1, #0xa
	ldr r1, [r6, r1]
	cmp r1, #0
	beq _021E5C88
	bl sub_02033250
	cmp r0, #1
	bne _021E5CBE
	ldr r0, [r7]
	add r0, r0, #1
	str r0, [r7]
	b _021E5CBE
_021E5C88:
	add r0, r0, #1
	str r0, [r7]
	b _021E5CBE
_021E5C8E:
	mov r0, #2
	bl sub_02038C1C
	add r0, r6, #0
	bl ov37_021E5F20
	ldr r0, [r6, #8]
	bl Heap_Free
	add r0, r4, #0
	bl OverlayManager_FreeData
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x27
	bl Heap_Destroy
	mov r0, #2
	bl sub_02038C1C
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E5CBE:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E5CC4: .word 0x04000304
	thumb_func_end ov37_021E5B94


	thumb_func_start ov37_021E5CC8
ov37_021E5CC8: ; 0x021E5CC8
	push {r4, lr}
	add r4, r0, #0
	bl GF_RunVramTransferTasks
	bl OamManager_ApplyAndResetBuffers
	add r0, r4, #0
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E5CE8 ; =0x027E0000
	ldr r1, _021E5CEC ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E5CE8: .word 0x027E0000
_021E5CEC: .word 0x00003FF8
	thumb_func_end ov37_021E5CC8


	thumb_func_start ov37_021E5CF0
ov37_021E5CF0: ; 0x021E5CF0
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _021E5D0C ; =ov37_021E7A24
	add r3, sp, #0
	mov r2, #5
_021E5CFA:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E5CFA
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_021E5D0C: .word ov37_021E7A24
	thumb_func_end ov37_021E5CF0


	thumb_func_start ov37_021E5D10
ov37_021E5D10: ; 0x021E5D10
	push {r4, r5, lr}
	sub sp, #0x9c
	ldr r5, _021E5E18 ; =ov37_021E7978
	add r3, sp, #0x8c
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _021E5E1C ; =ov37_021E7998
	add r3, sp, #0x70
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0
	str r0, [r3]
	add r0, r4, #0
	add r3, r1, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E5E20 ; =ov37_021E79D0
	add r3, sp, #0x54
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #1
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E5E24 ; =ov37_021E79EC
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #2
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldr r5, _021E5E28 ; =ov37_021E7A08
	add r3, sp, #0x1c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #4
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E5E2C ; =ov37_021E79B4
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	str r0, [r3]
	add r0, r4, #0
	mov r1, #5
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #0
	mov r1, #0x20
	add r2, r0, #0
	mov r3, #0x27
	bl BG_ClearCharDataRange
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x27
	bl BG_ClearCharDataRange
	mov r0, #1
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x27
	bl BG_ClearCharDataRange
	mov r0, #5
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x27
	bl BG_ClearCharDataRange
	add sp, #0x9c
	pop {r4, r5, pc}
	nop
_021E5E18: .word ov37_021E7978
_021E5E1C: .word ov37_021E7998
_021E5E20: .word ov37_021E79D0
_021E5E24: .word ov37_021E79EC
_021E5E28: .word ov37_021E7A08
_021E5E2C: .word ov37_021E79B4
	thumb_func_end ov37_021E5D10


	thumb_func_start ov37_021E5E30
ov37_021E5E30: ; 0x021E5E30
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021E5F04 ; =0x0000438A
	add r6, r7, #0
	add r4, r7, r0
	mov r0, #0x38
	add r5, r7, #0
	str r0, [sp, #4]
_021E5E46:
	mov r0, #8
	mov r1, #0x27
	bl String_New
	str r0, [r6, #0x14]
	ldrb r1, [r4]
	ldr r0, [sp, #4]
	bic r1, r0
	strb r1, [r4]
	ldr r0, _021E5F08 ; =0x000043B6
	mov r1, #0
	strh r1, [r6, r0]
	mov r0, #0xcd
	lsl r0, r0, #2
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
	ldr r0, [sp]
	add r6, r6, #4
	add r0, r0, #1
	add r4, #0xa
	add r5, #8
	str r0, [sp]
	cmp r0, #5
	blt _021E5E46
	mov r0, #0xa
	mov r1, #0x27
	bl String_New
	str r0, [r7, #0x28]
	mov r0, #0x50
	mov r1, #0x27
	bl String_New
	str r0, [r7, #0x2c]
	ldr r0, _021E5F0C ; =0x00004376
	mov r2, #0
	strb r2, [r7, r0]
	mov r1, #1
	add r0, r0, #1
	strb r1, [r7, r0]
	ldr r0, _021E5F10 ; =0x000093F4
	str r1, [r7, r0]
	add r0, r0, #4
	str r2, [r7, r0]
	mov r0, #0xc6
	mov r1, #2
	lsl r0, r0, #2
	str r1, [r7, r0]
	bl sub_02033250
	mov r1, #0xc7
	lsl r1, r1, #2
	str r0, [r7, r1]
	ldr r2, _021E5F14 ; =0x000093FC
	mov r3, #0
	str r3, [r7, r2]
	add r0, r2, #4
	str r3, [r7, r0]
	add r0, r2, #0
	sub r1, #0x18
	str r3, [r7, r1]
	add r0, #8
	str r3, [r7, r0]
	add r2, #0xc
	str r3, [r7, r2]
	bl sub_0203769C
	add r0, r7, #0
	mov r1, #4
	bl ov37_021E7844
	ldr r0, [r7, #0x10]
	ldr r2, [r7, #0x28]
	mov r1, #7
	bl ReadMsgDataIntoString
	mov r1, #0xf
	mov r0, #0x27
	lsl r1, r1, #0xa
	bl Heap_Alloc
	ldr r1, _021E5F18 ; =0x000043C8
	str r0, [r7, r1]
	mov r0, #0x27
	bl YesNoPrompt_Create
	ldr r1, _021E5F1C ; =0x000093F0
	str r0, [r7, r1]
	mov r0, #0xc5
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r7, r0]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E5F04: .word 0x0000438A
_021E5F08: .word 0x000043B6
_021E5F0C: .word 0x00004376
_021E5F10: .word 0x000093F4
_021E5F14: .word 0x000093FC
_021E5F18: .word 0x000043C8
_021E5F1C: .word 0x000093F0
	thumb_func_end ov37_021E5E30

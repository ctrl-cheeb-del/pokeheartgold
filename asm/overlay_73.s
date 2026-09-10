#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_73.inc"
	.include "global.inc"

	.text
	.public _021EA51C
	.public _021EA7C0
	.public _021EA940
	.public ov73_021E5900
	.public ov73_021E5AB8
	.public ov73_021E5BAC
	.public ov73_021E5C74
	.public ov73_021E5CD8
	.public ov73_021E5D00
	.public ov73_021E5D20
	.public ov73_021E5E0C
	.public ov73_021E5ED4
	.public ov73_021E5F38
	.public ov73_021E6060
	.public ov73_021E6090
	.public ov73_021E6184
	.public ov73_021E629C
	.public ov73_021E63BC
	.public ov73_021E6444
	.public ov73_021E6484
	.public ov73_021E64B0
	.public ov73_021E6508
	.public ov73_021E66F4
	.public ov73_021E671C
	.public ov73_021E6778
	.public ov73_021E67A8
	.public ov73_021E6830
	.public ov73_021E6890
	.public ov73_021E68AC
	.public ov73_021E69E8
	.public ov73_021E6A70
	.public ov73_021E6A90
	.public ov73_021E6AAC
	.public ov73_021E6B6C
	.public ov73_021E6BC8
	.public ov73_021E6C50
	.public ov73_021E6CC0
	.public ov73_021E6CDC
	.public ov73_021E6CFC
	.public ov73_021E6D38
	.public ov73_021E6D54
	.public ov73_021E6DF8
	.public ov73_021E6E48
	.public ov73_021E6E6C
	.public ov73_021E6E8C
	.public ov73_021E6ECC
	.public ov73_021E6EF8
	.public ov73_021E6F1C
	.public ov73_021E6FAC
	.public ov73_021E6FE8
	.public ov73_021E705C
	.public ov73_021E7120
	.public ov73_021E71E4
	.public ov73_021E7230
	.public ov73_021E72F4
	.public ov73_021E735C
	.public ov73_021E7490
	.public ov73_021E756C
	.public ov73_021E762C
	.public ov73_021E7740
	.public ov73_021E77A4
	.public ov73_021E781C
	.public ov73_021E7870
	.public ov73_021E7964
	.public ov73_021E79A8
	.public ov73_021E79F4
	.public ov73_021E7A8C
	.public ov73_021E7AC0
	.public ov73_021E7B3C
	.public ov73_021E7B84
	.public ov73_021E7BC8
	.public ov73_021E7C0C
	.public ov73_021E7C50
	.public ov73_021E7C94
	.public ov73_021E7CD8
	.public ov73_021E7D74
	.public ov73_021E7E24
	.public ov73_021E7E4C
	.public ov73_021E7FB8
	.public ov73_021E808C
	.public ov73_021E8100
	.public ov73_021E8128
	.public ov73_021E8168
	.public ov73_021E8198
	.public ov73_021E82D4
	.public ov73_021E8390
	.public ov73_021E847C
	.public ov73_021E84D0
	.public ov73_021E85AC
	.public ov73_021E85DC
	.public ov73_021E8628
	.public ov73_021E8730
	.public ov73_021E8960
	.public ov73_021E8A08
	.public ov73_021E8B20
	.public ov73_021E8B64
	.public ov73_021E8BBC
	.public ov73_021E8CBC
	.public ov73_021E8D2C
	.public ov73_021E8DC8
	.public ov73_021E8E7C
	.public ov73_021E8ED8
	.public ov73_021E8FE4
	.public ov73_021E9144
	.public ov73_021E9224
	.public ov73_021E926C
	.public ov73_021E9378
	.public ov73_021E944C
	.public ov73_021E95CC
	.public ov73_021E9618
	.public ov73_021E9758
	.public ov73_021E97A8
	.public ov73_021E98AC
	.public ov73_021E98FC
	.public ov73_021E9A6C
	.public ov73_021E9D14
	.public ov73_021E9D6C
	.public ov73_021E9DE0
	.public ov73_021E9ECC
	.public ov73_021E9F34
	.public ov73_021E9F9C
	.public ov73_021E9FC8
	.public ov73_021E9FF8
	.public ov73_021EA050
	.public ov73_021EA088
	.public ov73_021EA0BC
	.public ov73_021EA0F0
	.public ov73_021EA19C
	.public ov73_021EA218
	.public ov73_021EA268
	.public ov73_021EA2B4
	.public ov73_021EA2E0
	.public ov73_021EA324
	.public ov73_021EA374
	.public ov73_021EA3D0
	.public ov73_021EA520
	.public ov73_021EA52A
	.public ov73_021EA52B
	.public ov73_021EA534
	.public ov73_021EA540
	.public ov73_021EA550
	.public ov73_021EA560
	.public ov73_021EA578
	.public ov73_021EA594
	.public ov73_021EA5B0
	.public ov73_021EA5CC
	.public ov73_021EA5E8
	.public ov73_021EA610
	.public ov73_021EA618
	.public ov73_021EA624
	.public ov73_021EA630
	.public ov73_021EA640
	.public ov73_021EA650
	.public ov73_021EA664
	.public ov73_021EA684
	.public ov73_021EA68C
	.public ov73_021EA69C
	.public ov73_021EA6AC
	.public ov73_021EA6D4
	.public ov73_021EA6F0
	.public ov73_021EA70C
	.public ov73_021EA728
	.public ov73_021EA744
	.public ov73_021EA83C
	.public ov73_021EA840
	.public ov73_021EA844
	.public ov73_021EA848

	.public ov73_021E5F0C
	.public ov73_021E6048
	.public ov73_021E6400
	.public ov73_021E66F0
	.public ov73_021E670C
	.public ov73_021E69D0
	.public ov73_021E6B98
	.public ov73_021E6BF8
	.public ov73_021E6C20
	.public ov73_021E7340
	.public ov73_021E7468
	.public ov73_021E746C
	.public ov73_021E7488
	.public ov73_021E75FC
	.public ov73_021E761C
	.public ov73_021E77E8
	.public ov73_021E7818
	.public ov73_021E795C
	.public ov73_021E7960
	.public ov73_021E7A74
	.public ov73_021E7A7C
	.public ov73_021E7A84
	.public ov73_021E7D54
	.public ov73_021E8148
	.public ov73_021E8164
	.public ov73_021E82A8
	.public ov73_021E83D4
	.public ov73_021E83EC
	.public ov73_021E83F4
	.public ov73_021E841C
	.public ov73_021E8440
	.public ov73_021E844C
	.public ov73_021E8454
	.public ov73_021E870C
	.public ov73_021E8BFC
	.public ov73_021E8C2C
	.public ov73_021E8C8C
	.public ov73_021E8D0C
	.public ov73_021E8DB8
	.public ov73_021E8EBC
	.public ov73_021E8FB0
	.public ov73_021E9120
	.public ov73_021E91F4
	.public ov73_021E93EC
	.public ov73_021E941C
	.public ov73_021E955C
	.public ov73_021E9598
	.public ov73_021E96EC
	.public ov73_021E9728
	.public ov73_021E987C
	.public ov73_021E99D4
	.public ov73_021E9A3C
	.public ov73_021E9B58
	.public ov73_021E9B94
	.public ov73_021E9B9C
	.public ov73_021E9BB4
	.public ov73_021E9BD4
	.public ov73_021E9C04
	.public ov73_021E9C30
	.public ov73_021E9C60
	.public ov73_021E9C8C
	.public ov73_021E9CBC
	.public ov73_021E9CD8
	.public ov73_021E9D10
	.public ov73_021E9D44
	.public ov73_021E9EAC
	.public ov73_021E9F00
	.public ov73_021EA12C
	.public ov73_021EA134
	.public ov73_021EA15C
	.public ov73_021EA180
	.public ov73_021EA25C
	.public ov73_021EA290
	.public ov73_021EA2A8
	.public ov73_021EA2FC
	.public ov73_021EA31C
	.public ov73_021EA348
	.public ov73_021EA370

	thumb_func_start ov73_021E5900
ov73_021E5900: ; 0x021E5900
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r1, #0
	ldr r1, [r5]
	add r7, r0, #0
	cmp r1, #0
	beq _021E5916
	cmp r1, #1
	bne _021E5914
	b _021E5A80
_021E5914:
	b _021E5A8E
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
	ldr r0, _021E5A94 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021E5A98 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	mov r2, #0x41
	mov r0, #3
	mov r1, #0x32
	lsl r2, r2, #0xc
	bl Heap_Create
	mov r0, #0x54
	mov r1, #0x32
	bl NARC_New
	add r6, r0, #0
	ldr r1, _021E5A9C ; =0x00004A8C
	add r0, r7, #0
	mov r2, #0x32
	bl OverlayManager_CreateAndGetData
	ldr r2, _021E5A9C ; =0x00004A8C
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x32
	bl BgConfig_Alloc
	str r0, [r4]
	add r0, r7, #0
	bl OverlayManager_GetArgs
	str r0, [r4, #8]
	ldr r1, [r0]
	ldr r0, _021E5AA0 ; =0x00004A0C
	str r1, [r4, r0]
	ldr r0, [r4, #8]
	ldr r0, [r0, #0x10]
	bl MenuInputStateMgr_GetState
	mov r1, #0xc5
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0x32
	bl MessageFormat_New
	str r0, [r4, #0x24]
	ldr r2, _021E5AA4 ; =0x000001A6
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x32
	bl NewMsgDataFromNarc
	str r0, [r4, #0x28]
	mov r0, #4
	mov r1, #0x32
	bl FontID_Alloc
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	bl ov73_021E5D00
	ldr r0, [r4]
	bl ov73_021E5D20
	mov r0, #0
	bl SetMasterBrightnessNeutral
	mov r0, #1
	bl SetMasterBrightnessNeutral
	mov r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x32
	str r0, [sp, #8]
	mov r0, #0
	mov r1, #0x11
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	add r0, r4, #0
	add r1, r6, #0
	bl ov73_021E5F38
	bl sub_020210BC
	mov r0, #2
	bl sub_02021148
	ldr r0, _021E5AA8 ; =ov73_021E5CD8
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	add r0, r4, #0
	add r1, r6, #0
	bl ov73_021E5E0C
	bl ov73_021E6060
	add r0, r4, #0
	add r1, r6, #0
	bl ov73_021E6090
	add r0, r4, #0
	bl ov73_021E6184
	add r0, r4, #0
	add r1, r7, #0
	bl ov73_021E629C
	add r0, r4, #0
	bl ov73_021E7230
	mov r1, #0
	mov r0, #0x34
	add r2, r1, #0
	bl Sound_SetSceneAndPlayBGM
	ldr r2, _021E5AAC ; =0x04000304
	ldr r0, _021E5AB0 ; =0xFFFF7FFF
	ldrh r1, [r2]
	and r0, r1
	strh r0, [r2]
	add r0, r4, #0
	bl sub_0208FB64
	bl sub_0203893C
	mov r0, #3
	bl sub_02038C1C
	bl sub_0203769C
	cmp r0, #0
	bne _021E5A54
	mov r0, #2
	bl sub_0205A904
_021E5A54:
	bl sub_0203A880
	ldr r0, _021E5AA0 ; =0x00004A0C
	mov r1, #0xe2
	lsl r1, r1, #2
	ldr r0, [r4, r0]
	add r1, r4, r1
	bl ov73_021EA374
	ldr r0, _021E5AB4 ; =ov73_021E5C74
	add r1, r4, #0
	mov r2, #5
	bl SysTask_CreateOnVBlankQueue
	str r0, [r4, #0x20]
	add r0, r6, #0
	bl NARC_Delete
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _021E5A8E
_021E5A80:
	bl OverlayManager_GetData
	mov r0, #0
	str r0, [r5]
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_021E5A8E:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E5A94: .word 0xFFFFE0FF
_021E5A98: .word 0x04001000
_021E5A9C: .word 0x00004A8C
_021E5AA0: .word 0x00004A0C
_021E5AA4: .word 0x000001A6
_021E5AA8: .word ov73_021E5CD8
_021E5AAC: .word 0x04000304
_021E5AB0: .word 0xFFFF7FFF
_021E5AB4: .word ov73_021E5C74
	thumb_func_end ov73_021E5900


	thumb_func_start ov73_021E5AB8
ov73_021E5AB8: ; 0x021E5AB8
	push {r3, r4, r5, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	bl sub_0203769C
	cmp r0, #0
	bne _021E5ADE
	ldr r0, _021E5B9C ; =0x00004A24
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E5ADE
	bl sub_02033250
	ldr r1, _021E5B9C ; =0x00004A24
	ldr r2, [r4, r1]
	and r0, r2
	str r0, [r4, r1]
_021E5ADE:
	ldr r1, [r5]
	cmp r1, #3
	bhi _021E5B92
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E5AF0: ; jump table
	.short _021E5AF8 - _021E5AF0 - 2 ; case 0
	.short _021E5B20 - _021E5AF0 - 2 ; case 1
	.short _021E5B6E - _021E5AF0 - 2 ; case 2
	.short _021E5B86 - _021E5AF0 - 2 ; case 3
_021E5AF8:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5B92
	mov r0, #1
	str r0, [r5]
	bl sub_0203769C
	cmp r0, #0
	beq _021E5B92
	bl ov73_021E746C
	cmp r0, #2
	ble _021E5B92
	mov r1, #0
	mov r0, #0x72
	add r2, r1, #0
	bl sub_02037030
	b _021E5B92
_021E5B20:
	mov r0, #0xc6
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r2, r0, #2
	ldr r0, _021E5BA0 ; =_021EA7C0
	ldr r2, [r0, r2]
	cmp r2, #0
	beq _021E5B36
	add r0, r4, #0
	blx r2
	str r0, [r5]
_021E5B36:
	ldr r0, _021E5BA4 ; =0x00004A14
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _021E5B4E
	mov r0, #0xa6
	lsl r0, r0, #2
	ldr r2, _021E5BA8 ; =0x00010300
	add r0, r4, r0
	mov r1, #0
	add r3, r4, #0
	bl ov73_021E735C
_021E5B4E:
	add r0, r4, #0
	bl ov73_021E762C
	bl sub_0203769C
	cmp r0, #0
	bne _021E5B92
	add r0, r4, #0
	mov r1, #1
	bl ov73_021E7870
	ldr r1, [r5]
	cmp r1, #1
	bne _021E5B92
	str r0, [r5]
	b _021E5B92
_021E5B6E:
	mov r0, #0xc6
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r2, r0, #2
	ldr r0, _021E5BA0 ; =_021EA7C0
	ldr r2, [r0, r2]
	cmp r2, #0
	beq _021E5B92
	add r0, r4, #0
	blx r2
	str r0, [r5]
	b _021E5B92
_021E5B86:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5B92
	mov r0, #1
	pop {r3, r4, r5, pc}
_021E5B92:
	ldr r0, [r4, #0x50]
	bl SpriteList_RenderAndAnimateSprites
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E5B9C: .word 0x00004A24
_021E5BA0: .word _021EA7C0
_021E5BA4: .word 0x00004A14
_021E5BA8: .word 0x00010300
	thumb_func_end ov73_021E5AB8


	thumb_func_start ov73_021E5BAC
ov73_021E5BAC: ; 0x021E5BAC
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	bl OverlayManager_GetData
	add r6, r0, #0
	ldr r0, [r6, #0x20]
	bl SysTask_Destroy
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeleteCharTransferTask
	mov r0, #0x1b
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r7, #0x5f
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_021E5BD8:
	ldr r0, [r5, r7]
	bl Destroy2DGfxResObjMan
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _021E5BD8
	ldr r0, [r6, #0x50]
	bl SpriteList_Delete
	bl OamManager_Free
	bl ObjCharTransfer_Destroy
	bl ObjPlttTransfer_Destroy
	add r0, r6, #0
	bl ov73_021E6400
	add r0, r6, #0
	bl ov73_021E6048
	ldr r0, [r6]
	bl ov73_021E5F0C
	mov r0, #2
	bl sub_02038C1C
	bl sub_02037FF0
	ldr r0, [r6, #8]
	ldr r0, [r0, #4]
	bl sub_0205AD24
	bl sub_02021238
	mov r0, #4
	bl FontID_Release
	ldr r0, [r6, #0x28]
	bl DestroyMsgData
	ldr r0, [r6, #0x24]
	bl MessageFormat_Delete
	ldr r0, [r6, #8]
	mov r1, #0xc5
	lsl r1, r1, #2
	ldr r0, [r0, #0x10]
	ldr r1, [r6, r1]
	bl MenuInputStateMgr_SetState
	add r0, r6, #0
	bl ov73_021E5ED4
	ldr r0, [sp]
	bl OverlayManager_FreeData
	ldr r2, _021E5C70 ; =0x04000304
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	mov r0, #0
	bl sub_0205A904
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x32
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E5C70: .word 0x04000304
	thumb_func_end ov73_021E5BAC


	thumb_func_start ov73_021E5C74
ov73_021E5C74: ; 0x021E5C74
	push {r4, lr}
	add r4, r1, #0
	ldr r0, [r4, #0xc]
	add r1, #0xc
	cmp r0, #0
	beq _021E5CCE
	ldr r0, [r1, #4]
	ldr r3, [r1, #8]
	lsl r2, r0, #1
	ldr r0, _021E5CD0 ; =ov73_021EA52A
	ldrb r0, [r0, r2]
	cmp r3, r0
	ble _021E5CBE
	mov r0, #0
	str r0, [r1, #8]
	ldr r2, [r1, #4]
	add r2, r2, #1
	str r2, [r1, #4]
	lsl r3, r2, #1
	ldr r2, _021E5CD4 ; =ov73_021EA52B
	ldrb r2, [r2, r3]
	cmp r2, #0xff
	bne _021E5CA4
	str r0, [r1, #4]
_021E5CA4:
	ldr r0, [r1, #0x10]
	ldr r1, [r1, #4]
	ldr r0, [r0, #0xc]
	lsl r2, r1, #1
	ldr r1, _021E5CD4 ; =ov73_021EA52B
	ldrb r1, [r1, r2]
	mov r2, #0x20
	lsl r1, r1, #5
	add r0, r0, r1
	mov r1, #0
	bl GX_LoadOBJPltt
	b _021E5CC4
_021E5CBE:
	ldr r0, [r4, #0x14]
	add r0, r0, #1
	str r0, [r4, #0x14]
_021E5CC4:
	mov r0, #0xde
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov73_021E72F4
_021E5CCE:
	pop {r4, pc}
	.balign 4, 0
_021E5CD0: .word ov73_021EA52A
_021E5CD4: .word ov73_021EA52B
	thumb_func_end ov73_021E5C74


	thumb_func_start ov73_021E5CD8
ov73_021E5CD8: ; 0x021E5CD8
	push {r4, lr}
	add r4, r0, #0
	bl GF_RunVramTransferTasks
	bl OamManager_ApplyAndResetBuffers
	ldr r0, [r4]
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E5CF8 ; =0x027E0000
	ldr r1, _021E5CFC ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E5CF8: .word 0x027E0000
_021E5CFC: .word 0x00003FF8
	thumb_func_end ov73_021E5CD8


	thumb_func_start ov73_021E5D00
ov73_021E5D00: ; 0x021E5D00
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _021E5D1C ; =ov73_021EA5E8
	add r3, sp, #0
	mov r2, #5
_021E5D0A:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E5D0A
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_021E5D1C: .word ov73_021EA5E8
	thumb_func_end ov73_021E5D00


	thumb_func_start ov73_021E5D20
ov73_021E5D20: ; 0x021E5D20
	push {r3, r4, r5, lr}
	sub sp, #0x80
	ldr r5, _021E5DF8 ; =ov73_021EA540
	add r3, sp, #0x70
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _021E5DFC ; =ov73_021EA5B0
	add r3, sp, #0x54
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
	ldr r5, _021E5E00 ; =ov73_021EA5CC
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #5
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E5E04 ; =ov73_021EA578
	add r3, sp, #0x1c
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
	ldr r5, _021E5E08 ; =ov73_021EA594
	add r3, sp, #0
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
	mov r0, #0
	mov r1, #0x20
	add r2, r0, #0
	mov r3, #0x32
	bl BG_ClearCharDataRange
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x32
	bl BG_ClearCharDataRange
	add sp, #0x80
	pop {r3, r4, r5, pc}
	nop
_021E5DF8: .word ov73_021EA540
_021E5DFC: .word ov73_021EA5B0
_021E5E00: .word ov73_021EA5CC
_021E5E04: .word ov73_021EA578
_021E5E08: .word ov73_021EA594
	thumb_func_end ov73_021E5D20


	thumb_func_start ov73_021E5E0C
ov73_021E5E0C: ; 0x021E5E0C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp]
	str r1, [sp, #4]
	mov r7, #0
	add r6, r0, #0
	add r4, r0, #0
	add r5, r0, #0
_021E5E1C:
	mov r0, #8
	mov r1, #0x32
	bl String_New
	str r0, [r6, #0x2c]
	mov r0, #0xce
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r0, #4
	str r1, [r4, r0]
	ldr r0, _021E5EC8 ; =0x00004A3C
	add r7, r7, #1
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
	ldr r0, _021E5ECC ; =0x00004A44
	add r4, #8
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
	mov r0, #0x36
	lsl r0, r0, #4
	str r1, [r6, r0]
	add r6, r6, #4
	add r5, #0x10
	cmp r7, #5
	blt _021E5E1C
	mov r0, #0xb4
	mov r1, #0x32
	bl String_New
	ldr r1, [sp]
	str r0, [r1, #0x44]
	mov r0, #0x28
	mov r1, #0x32
	bl String_New
	ldr r1, [sp]
	mov r2, #0
	str r0, [r1, #0x48]
	mov r1, #0xc6
	ldr r0, [sp]
	lsl r1, r1, #2
	str r2, [r0, r1]
	ldr r2, [sp]
	ldr r0, [r0, #0x28]
	ldr r2, [r2, #0x48]
	mov r1, #0x11
	bl ReadMsgDataIntoString
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl ov73_021E7740
	mov r0, #0x32
	bl sub_0205B4A4
	mov r2, #0xdf
	ldr r1, [sp]
	lsl r2, r2, #2
	str r0, [r1, r2]
	ldr r2, [sp]
	ldr r0, [sp]
	mov r1, #0
	str r1, [r0, #0xc]
	str r1, [r0, #0x14]
	str r1, [r0, #0x10]
	ldr r0, [sp, #4]
	mov r1, #7
	add r2, #0x1c
	mov r3, #0x32
	bl GfGfxLoader_GetPlttDataFromOpenNarc
	ldr r1, [sp]
	ldr r2, _021E5ED0 ; =0x00004A18
	str r0, [r1, #0x18]
	mov r0, #0
	str r0, [r1, r2]
	add r3, r2, #4
	mov r4, #2
	str r4, [r1, r3]
	sub r2, r2, #3
	strb r0, [r1, r2]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E5EC8: .word 0x00004A3C
_021E5ECC: .word 0x00004A44
_021E5ED0: .word 0x00004A18
	thumb_func_end ov73_021E5E0C


	thumb_func_start ov73_021E5ED4
ov73_021E5ED4: ; 0x021E5ED4
	push {r4, r5, r6, lr}
	add r6, r0, #0
	bl ov73_021E77E8
	ldr r0, [r6, #0x18]
	bl Heap_Free
	mov r0, #0xdf
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl Heap_Free
	mov r4, #0
	add r5, r6, #0
_021E5EF0:
	ldr r0, [r5, #0x2c]
	bl String_Delete
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #5
	blt _021E5EF0
	ldr r0, [r6, #0x48]
	bl String_Delete
	ldr r0, [r6, #0x44]
	bl String_Delete
	pop {r4, r5, r6, pc}
	thumb_func_end ov73_021E5ED4

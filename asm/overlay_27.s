	.include "asm/macros.inc"
	.include "overlay_27.inc"
	.include "global.inc"

	.text
	.public _0225CEBC
	.public ov27_02259F80
	.public ov27_0225A19C
	.public ov27_0225A320
	.public ov27_0225A4D0
	.public ov27_0225A530
	.public ov27_0225A594
	.public ov27_0225A61C
	.public ov27_0225A690
	.public ov27_0225A714
	.public ov27_0225A7FC
	.public ov27_0225A89C
	.public ov27_0225A8E8
	.public ov27_0225A9C0
	.public ov27_0225AA7C
	.public ov27_0225AAD4
	.public ov27_0225AC00
	.public ov27_0225AD0C
	.public ov27_0225AEA8
	.public ov27_0225B010
	.public ov27_0225B360
	.public ov27_0225B398
	.public ov27_0225B404
	.public ov27_0225B4D8
	.public ov27_0225B630
	.public ov27_0225BB6C
	.public ov27_0225BC34
	.public ov27_0225BC84
	.public ov27_0225BCE8
	.public ov27_0225BD50
	.public ov27_0225BDFC
	.public ov27_0225BED8
	.public ov27_0225BF84
	.public ov27_0225BFCC
	.public ov27_0225C088
	.public ov27_0225C10C
	.public ov27_0225C170
	.public ov27_0225C1AC
	.public ov27_0225C1EC
	.public ov27_0225C250
	.public ov27_0225C398
	.public ov27_0225C434
	.public ov27_0225C4AC
	.public ov27_0225C540
	.public ov27_0225C618
	.public ov27_0225C72C
	.public ov27_0225C80C
	.public ov27_0225C9F8
	.public ov27_0225CA14
	.public ov27_0225CA98
	.public ov27_0225CD18
	.public ov27_0225CD94
	.public ov27_0225CEAC
	.public ov27_0225CEC4
	.public ov27_0225CECC
	.public ov27_0225CED8
	.public ov27_0225CEEC
	.public ov27_0225CEF0
	.public ov27_0225CEF4
	.public ov27_0225CF10
	.public ov27_0225CF3C
	.public ov27_0225CF68
	.public ov27_0225CF94
	.public ov27_0225CFC8
	.public ov27_0225D000
	.public ov27_0225D01C
	.public ov27_0225D038
	.public ov27_0225D05C
	.public ov27_0225D074
	.public ov27_0225D0B4
	.public ov27_0225D108
	.public ov27_0225D110
	.public ov27_0225D118
	.public ov27_0225D11A
	.public ov27_0225D120
	.public ov27_0225D12C
	.public ov27_0225D138
	.public ov27_0225D144
	.public ov27_0225D154
	.public ov27_0225D164
	.public ov27_0225D174
	.public ov27_0225D188
	.public ov27_0225D19C
	.public ov27_0225D1B4
	.public ov27_0225D1CC
	.public ov27_0225D1E4
	.public ov27_0225D200
	.public ov27_0225D21C
	.public ov27_0225D23C
	.public ov27_0225D25C
	.public ov27_0225D27C
	.public ov27_0225D2A0
	.public ov27_0225D2C8
	.public ov27_0225D2F8
	.public ov27_0225D330
	.public ov27_0225D370
	.public ov27_0225D38C
	.public ov27_0225D3A8
	.public ov27_0225D3C4
	.public ov27_0225D3C5
	.public ov27_0225D3C6
	.public ov27_0225D480
	.public ov27_0225D49C
	.public ov27_0225D4B8
	.public ov27_0225D4D4

	.public ov27_0225A2C8
	.public ov27_0225A2CC
	.public ov27_0225A2EC
	.public ov27_0225A468
	.public ov27_0225A48C
	.public ov27_0225A4B8
	.public ov27_0225A66C
	.public ov27_0225A7B0
	.public ov27_0225A7DC
	.public ov27_0225A86C
	.public ov27_0225AA60
	.public ov27_0225AE8C
	.public ov27_0225B4AC
	.public ov27_0225BB38
	.public ov27_0225BD44
	.public ov27_0225BDAC
	.public ov27_0225BDC8
	.public ov27_0225BDDC
	.public ov27_0225BEB0
	.public ov27_0225C01C
	.public ov27_0225C044
	.public ov27_0225C06C
	.public ov27_0225C0E0
	.public ov27_0225C238
	.public ov27_0225C248
	.public ov27_0225C24C
	.public ov27_0225C418
	.public ov27_0225C41C
	.public ov27_0225C5E4
	.public ov27_0225C6F8
	.public ov27_0225C8D0
	.public ov27_0225C914
	.public ov27_0225C930
	.public ov27_0225C944
	.public ov27_0225C94C
	.public ov27_0225C988
	.public ov27_0225C994
	.public ov27_0225C9CC
	.public ov27_0225C9E4
	.public ov27_0225CA68
	.public ov27_0225CC90
	.public ov27_0225CCBC
	.public ov27_0225CCE0
	.public ov27_0225CD74

	thumb_func_start ov27_02259F80
ov27_02259F80: ; 0x02259F80
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r2, #0
	add r6, r0, #0
	str r1, [sp, #0x10]
	ldr r2, _0225A170 ; =0x00018D00
	mov r0, #3
	mov r1, #8
	bl Heap_Create
	mov r0, #0
	bl GXS_SetGraphicsMode
	mov r0, #0x80
	bl GX_SetBankForSubBG
	mov r0, #1
	lsl r0, r0, #8
	bl GX_SetBankForSubOBJ
	ldr r2, _0225A174 ; =0x04001000
	ldr r0, _0225A178 ; =0xFFCFFFEF
	ldr r1, [r2]
	mov r3, #0
	and r1, r0
	mov r0, #0x10
	orr r0, r1
	str r0, [r2]
	ldr r2, _0225A17C ; =ov27_0225D000
	add r0, r6, #0
	mov r1, #4
	bl InitBgFromTemplate
	ldr r2, _0225A180 ; =ov27_0225D01C
	add r0, r6, #0
	mov r1, #5
	mov r3, #0
	bl InitBgFromTemplate
	mov r1, #0x15
	ldr r0, _0225A184 ; =ov27_0225A320
	lsl r1, r1, #6
	mov r2, #0xa
	mov r3, #8
	bl CreateSysTaskAndEnvironment
	add r7, r0, #0
	bl SysTask_GetData
	add r4, r0, #0
	str r7, [r4, #8]
	mov r0, #0
	str r0, [r4]
	ldr r0, [sp, #0x10]
	str r6, [r4, #4]
	str r0, [r4, #0xc]
	add r0, r5, #0
	str r5, [r4, #0x10]
	bl ov27_0225BD50
	ldr r3, _0225A188 ; =0x0000051C
	add r2, r0, #0
	ldr r1, [r4, r3]
	mov r0, #0x1e
	bic r1, r0
	lsl r0, r2, #0x1c
	lsr r0, r0, #0x1b
	orr r0, r1
	str r0, [r4, r3]
	ldr r1, [r4, r3]
	mov r0, #0x20
	bic r1, r0
	str r1, [r4, r3]
	mov r3, #0x3f
	lsl r3, r3, #4
	add r0, r4, r3
	str r0, [sp]
	add r2, r3, #0
	sub r2, #0x20
	sub r3, #0x10
	ldr r1, [r4]
	add r0, r6, #0
	add r2, r4, r2
	add r3, r4, r3
	bl ov27_0225AC00
	mov r0, #4
	mov r1, #8
	bl FontID_Alloc
	mov r0, #8
	bl MessageFormat_New
	ldr r1, _0225A18C ; =0x000004AC
	mov r2, #0xc4
	str r0, [r4, r1]
	mov r0, #0
	mov r1, #0x1b
	mov r3, #8
	bl NewMsgDataFromNarc
	ldr r1, _0225A190 ; =0x000004A8
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov27_0225C10C
	add r1, r5, #0
	add r1, #0xd3
	ldrb r1, [r1]
	add r0, r4, #0
	bl ov27_0225C1AC
	str r0, [r4, #0x14]
	add r0, r4, #0
	bl ov27_0225C1EC
	add r0, r4, #0
	bl ov27_0225AD0C
	add r0, r4, #0
	bl ov27_0225B010
	ldr r1, [r4, #0x10]
	add r0, r4, #0
	add r1, #0xd2
	ldrb r1, [r1]
	lsl r1, r1, #0x1a
	lsr r1, r1, #0x1a
	bl ov27_0225BB6C
	mov r3, #0
	str r3, [sp]
	mov r2, #0x3d
	ldr r0, _0225A194 ; =0x000F0100
	str r3, [sp, #4]
	str r0, [sp, #8]
	lsl r2, r2, #4
	add r0, r4, r2
	str r3, [sp, #0xc]
	add r2, #0xe4
	ldr r2, [r4, r2]
	mov r1, #4
	bl AddTextPrinterParameterizedWithColor
	mov r1, #0
	mov r2, #0x3e
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225A194 ; =0x000F0100
	lsl r2, r2, #4
	str r0, [sp, #8]
	add r0, r4, r2
	str r1, [sp, #0xc]
	add r2, #0xe4
	ldr r2, [r4, r2]
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl ov27_0225BCE8
	add r0, r4, #0
	bl ov27_0225BC84
	add r0, r4, #0
	mov r1, #1
	bl ov27_0225A690
	add r0, r4, #0
	bl ov27_0225C0E0
	mov r0, #0x52
	lsl r0, r0, #4
	add r0, r4, r0
	add r1, r4, #0
	bl ov27_0225BDDC
	mov r0, #0x43
	lsl r0, r0, #2
	add r0, r5, r0
	bl MenuInputStateMgr_GetState
	cmp r0, #0
	bne _0225A102
	add r0, r5, #0
	add r0, #0xd2
	ldrb r1, [r0]
	mov r0, #0x80
	add r5, #0xd2
	bic r1, r0
	strb r1, [r5]
	b _0225A11A
_0225A102:
	add r0, r5, #0
	bl FieldSystem_TaskIsRunning
	cmp r0, #0
	bne _0225A11A
	add r0, r5, #0
	add r0, #0xd2
	ldrb r1, [r0]
	mov r0, #0x80
	add r5, #0xd2
	orr r0, r1
	strb r0, [r5]
_0225A11A:
	add r0, r4, #0
	bl ov27_0225A714
	cmp r0, #0
	bne _0225A12A
	add sp, #0x14
	add r0, r7, #0
	pop {r4, r5, r6, r7, pc}
_0225A12A:
	add r0, r4, #0
	bl ov27_0225A7FC
	ldr r0, [r4, #0x18]
	bl SpriteList_RenderAndAnimateSprites
	ldr r2, _0225A174 ; =0x04001000
	ldr r0, _0225A198 ; =0xFFFF1FFF
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add r0, r7, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_0225A170: .word 0x00018D00
_0225A174: .word 0x04001000
_0225A178: .word 0xFFCFFFEF
_0225A17C: .word ov27_0225D000
_0225A180: .word ov27_0225D01C
_0225A184: .word ov27_0225A320
_0225A188: .word 0x0000051C
_0225A18C: .word 0x000004AC
_0225A190: .word 0x000004A8
_0225A194: .word 0x000F0100
_0225A198: .word 0xFFFF1FFF
	thumb_func_end ov27_02259F80


	thumb_func_start ov27_0225A19C
ov27_0225A19C: ; 0x0225A19C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp]
	add r0, r1, #0
	str r1, [sp, #4]
	bl SysTask_GetData
	add r6, r0, #0
	ldr r1, _0225A2B0 ; =FS_OVERLAY_ID(ds_protect)
	mov r0, #0
	bl FS_LoadOverlay
	ldr r0, _0225A2B4 ; =ov27_0225C238
	bl DSProt_DetectFlashcart
	cmp r0, #0
	beq _0225A1C8
	mov r1, #0xfa
	mov r0, #3
	lsl r1, r1, #2
	bl Heap_AllocAtEnd
_0225A1C8:
	mov r0, #0x52
	lsl r0, r0, #4
	add r0, r6, r0
	bl ov27_0225BEB0
	ldr r0, _0225A2B8 ; =0x000004A8
	ldr r0, [r6, r0]
	bl DestroyMsgData
	ldr r0, _0225A2BC ; =0x000004AC
	ldr r0, [r6, r0]
	bl MessageFormat_Delete
	mov r7, #0x55
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_0225A1EA:
	ldr r0, [r5, r7]
	bl SpriteTransfer_DeleteCharTransferTask
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #0xb
	blt _0225A1EA
	mov r7, #0x56
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #2
_0225A200:
	ldr r0, [r4, r7]
	bl SpriteTransfer_DeletePlttTransferTask
	add r5, r5, #1
	add r4, #0x10
	cmp r5, #0xb
	blt _0225A200
	mov r7, #0x51
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #2
_0225A216:
	ldr r0, [r4, r7]
	bl Destroy2DGfxResObjMan
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #4
	blt _0225A216
	ldr r0, _0225A2C0 ; =ov27_0225C248
	bl DSProt_DetectNotEmulator
	cmp r0, #0
	bne _0225A238
	mov r1, #0xfa
	mov r0, #3
	lsl r1, r1, #2
	bl Heap_AllocAtEnd
_0225A238:
	ldr r0, [r6, #0x18]
	bl SpriteList_Delete
	mov r0, #0x3f
	lsl r0, r0, #4
	mov r5, #0
	add r4, r6, r0
_0225A246:
	add r0, r4, #0
	bl RemoveWindow
	add r5, r5, #1
	add r4, #0x10
	cmp r5, #8
	blt _0225A246
	mov r0, #0x3e
	lsl r0, r0, #4
	add r0, r6, r0
	bl RemoveWindow
	mov r0, #0x3d
	lsl r0, r0, #4
	add r0, r6, r0
	bl RemoveWindow
	add r0, r6, #0
	bl ov27_0225BC34
	mov r0, #4
	bl FontID_Release
	ldr r0, [sp, #4]
	bl DestroySysTaskAndEnvironment
	ldr r0, [sp]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [sp]
	mov r1, #4
	bl FreeBgTilemapBuffer
	mov r0, #8
	bl Heap_Destroy
	ldr r0, _0225A2C4 ; =ov27_0225C24C
	bl DSProt_DetectNotDummy
	cmp r0, #0
	bne _0225A2A4
	mov r1, #0xfa
	mov r0, #3
	lsl r1, r1, #2
	bl Heap_AllocAtEnd
_0225A2A4:
	ldr r1, _0225A2B0 ; =FS_OVERLAY_ID(ds_protect)
	mov r0, #0
	bl FS_UnloadOverlay
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225A2B0: .word FS_OVERLAY_ID(ds_protect)
_0225A2B4: .word ov27_0225C238
_0225A2B8: .word 0x000004A8
_0225A2BC: .word 0x000004AC
_0225A2C0: .word ov27_0225C248
_0225A2C4: .word ov27_0225C24C
	thumb_func_end ov27_0225A19C

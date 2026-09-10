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

	thumb_func_start ov27_0225C250
ov27_0225C250: ; 0x0225C250
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r7, r1, #0
	mov r0, #3
	str r2, [sp]
	mov r1, #8
	lsl r2, r0, #0xf
	str r3, [sp, #4]
	bl Heap_Create
	mov r0, #0
	bl GXS_SetGraphicsMode
	mov r0, #0x80
	bl GX_SetBankForSubBG
	mov r0, #1
	lsl r0, r0, #8
	bl GX_SetBankForSubOBJ
	ldr r2, _0225C37C ; =0x04001000
	ldr r0, _0225C380 ; =0xFFCFFFEF
	ldr r1, [r2]
	mov r3, #0
	and r1, r0
	mov r0, #0x10
	orr r0, r1
	str r0, [r2]
	ldr r2, _0225C384 ; =ov27_0225D370
	add r0, r5, #0
	mov r1, #4
	bl InitBgFromTemplate
	ldr r2, _0225C388 ; =ov27_0225D38C
	add r0, r5, #0
	mov r1, #5
	mov r3, #0
	bl InitBgFromTemplate
	ldr r2, _0225C38C ; =ov27_0225D3A8
	add r0, r5, #0
	mov r1, #6
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	add r3, r0, #0
	bl BG_ClearCharDataRange
	mov r0, #5
	mov r1, #0x20
	mov r2, #0
	mov r3, #4
	bl BG_ClearCharDataRange
	mov r0, #6
	mov r1, #0x20
	mov r2, #0
	mov r3, #4
	bl BG_ClearCharDataRange
	add r0, r5, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	add r0, r5, #0
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	mov r1, #0xe9
	ldr r0, _0225C390 ; =ov27_0225C434
	lsl r1, r1, #2
	mov r2, #0xa
	mov r3, #8
	bl CreateSysTaskAndEnvironment
	add r6, r0, #0
	bl SysTask_GetData
	add r4, r0, #0
	str r6, [r4, #0x1c]
	mov r0, #0
	str r0, [r4, #0x14]
	str r5, [r4, #0x18]
	ldr r1, [sp]
	str r7, [r4, #0x20]
	str r1, [r4, #0x24]
	str r0, [r4, #0x48]
	ldr r1, [sp, #4]
	str r0, [r4]
	str r1, [r4, #4]
	mov r1, #0xe7
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r1, r1, #4
	str r0, [r4, r1]
	str r0, [r4, #0x34]
	str r0, [r4, #0x44]
	mov r0, #4
	mov r1, #8
	bl FontID_Alloc
	ldr r1, [r4, #0x24]
	add r0, r4, #0
	add r1, #0xd2
	ldrb r1, [r1]
	lsl r1, r1, #0x1a
	lsr r1, r1, #0x1a
	bl ov27_0225C914
	add r0, r4, #0
	bl ov27_0225C4AC
	add r0, r4, #0
	bl ov27_0225C72C
	add r0, r4, #0
	mov r1, #0
	bl ov27_0225C80C
	ldr r2, _0225C37C ; =0x04001000
	ldr r0, _0225C394 ; =0xFFFF1FFF
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
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	add r0, r6, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225C37C: .word 0x04001000
_0225C380: .word 0xFFCFFFEF
_0225C384: .word ov27_0225D370
_0225C388: .word ov27_0225D38C
_0225C38C: .word ov27_0225D3A8
_0225C390: .word ov27_0225C434
_0225C394: .word 0xFFFF1FFF
	thumb_func_end ov27_0225C250


	thumb_func_start ov27_0225C398
ov27_0225C398: ; 0x0225C398
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp]
	add r0, r1, #0
	str r1, [sp, #4]
	bl SysTask_GetData
	add r7, r0, #0
	mov r0, #0xd5
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	bl SpriteTransfer_DeleteCharTransferTask
	mov r0, #0xd6
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r6, #0xd1
	mov r4, #0
	add r5, r7, #0
	lsl r6, r6, #2
_0225C3C4:
	ldr r0, [r5, r6]
	bl Destroy2DGfxResObjMan
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0225C3C4
	mov r0, #0x86
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	bl SpriteList_Delete
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	add r0, r7, #0
	bl ov27_0225C930
	mov r0, #4
	bl FontID_Release
	ldr r0, [sp, #4]
	bl DestroySysTaskAndEnvironment
	ldr r0, [sp]
	mov r1, #6
	bl FreeBgTilemapBuffer
	ldr r0, [sp]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [sp]
	mov r1, #4
	bl FreeBgTilemapBuffer
	mov r0, #8
	bl Heap_Destroy
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov27_0225C398

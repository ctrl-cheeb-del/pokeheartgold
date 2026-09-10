	.include "asm/macros.inc"
	.include "overlay_72.inc"
	.include "global.inc"

	.text
	.public NintendoWfc_Exit
	.public NintendoWfc_Init
	.public NintendoWfc_Main
	.public _0223B330
	.public _0223B4E0
	.public _0223B820
	.public ov72_022378DC
	.public ov72_02237B54
	.public ov72_02237B80
	.public ov72_02237BD0
	.public ov72_02237C30
	.public ov72_02237CB0
	.public ov72_02237CF4
	.public ov72_02237D50
	.public ov72_02237D88
	.public ov72_022380FC
	.public ov72_02238124
	.public ov72_02238164
	.public ov72_02238194
	.public ov72_02238408
	.public ov72_02238688
	.public ov72_022386F4
	.public ov72_02238730
	.public ov72_02238750
	.public ov72_02238778
	.public ov72_022387D8
	.public ov72_02238800
	.public ov72_0223886C
	.public ov72_0223894C
	.public ov72_0223897C
	.public ov72_022389C8
	.public ov72_02238B18
	.public ov72_02238BEC
	.public ov72_02238E3C
	.public ov72_02238EE4
	.public ov72_02239040
	.public ov72_02239108
	.public ov72_02239198
	.public ov72_022391E8
	.public ov72_02239220
	.public ov72_022392BC
	.public ov72_02239370
	.public ov72_022393CC
	.public ov72_022394A4
	.public ov72_022394D8
	.public ov72_02239638
	.public ov72_022396E8
	.public ov72_02239760
	.public ov72_02239784
	.public ov72_022397E8
	.public ov72_022398BC
	.public ov72_02239A3C
	.public ov72_02239A88
	.public ov72_02239BEC
	.public ov72_02239C14
	.public ov72_02239CB4
	.public ov72_02239CD8
	.public ov72_02239D6C
	.public ov72_02239E58
	.public ov72_02239F04
	.public ov72_02239F60
	.public ov72_02239F8C
	.public ov72_02239FD8
	.public ov72_0223A014
	.public ov72_0223A044
	.public ov72_0223A06C
	.public ov72_0223A0E0
	.public ov72_0223A1AC
	.public ov72_0223A1CC
	.public ov72_0223A200
	.public ov72_0223A280
	.public ov72_0223A2E8
	.public ov72_0223A314
	.public ov72_0223A350
	.public ov72_0223A3A8
	.public ov72_0223A3E0
	.public ov72_0223A420
	.public ov72_0223A460
	.public ov72_0223A4DC
	.public ov72_0223A520
	.public ov72_0223A588
	.public ov72_0223A5B4
	.public ov72_0223A5E0
	.public ov72_0223A680
	.public ov72_0223A738
	.public ov72_0223A760
	.public ov72_0223A7F4
	.public ov72_0223A8A0
	.public ov72_0223A8F0
	.public ov72_0223AA9C
	.public ov72_0223AB84
	.public ov72_0223ABB0
	.public ov72_0223AC00
	.public ov72_0223AC2C
	.public ov72_0223ACA8
	.public ov72_0223AD20
	.public ov72_0223AD64
	.public ov72_0223AD94
	.public ov72_0223AE20
	.public ov72_0223AE6C
	.public ov72_0223AED0
	.public ov72_0223AF1C
	.public ov72_0223AF48
	.public ov72_0223AF7C
	.public ov72_0223B088
	.public ov72_0223B0C4
	.public ov72_0223B1C8
	.public ov72_0223B2C0
	.public ov72_0223B2FC
	.public ov72_0223B338
	.public ov72_0223B344
	.public ov72_0223B354
	.public ov72_0223B364
	.public ov72_0223B366
	.public ov72_0223B37C
	.public ov72_0223B3A4
	.public ov72_0223B3A6
	.public ov72_0223B3D8
	.public ov72_0223B3F4
	.public ov72_0223B410
	.public ov72_0223B42C
	.public ov72_0223B448
	.public ov72_0223B464
	.public ov72_0223B466
	.public ov72_0223B468
	.public ov72_0223B46A
	.public ov72_0223B46C
	.public ov72_0223B478
	.public ov72_0223B479
	.public ov72_0223B48C
	.public ov72_0223B4C0
	.public ov72_0223B4C2
	.public ov72_0223B4C8
	.public ov72_0223B52C
	.public ov72_0223B578
	.public ov72_0223B5C4
	.public ov72_0223B60C
	.public ov72_0223B654
	.public ov72_0223B658
	.public ov72_0223B65C
	.public ov72_0223B660
	.public ov72_0223B744
	.public ov72_0223B774
	.public ov72_0223B7B8
	.public ov72_0223B7FC
	.public ov72_0223B82C
	.public ov72_0223B834
	.public ov72_0223B900
	.public ov72_0223B91B
	.public ov72_0223B920
	.public ov72_0223B923
	.public ov72_0223B92C

	.public ov72_022378C0
	.public ov72_02237B74
	.public ov72_02238144
	.public ov72_02238160
	.public ov72_022383DC
	.public ov72_02238668
	.public ov72_02238680
	.public ov72_022387A0
	.public ov72_022387C4
	.public ov72_022387D0
	.public ov72_02238AEC
	.public ov72_02238FFC
	.public ov72_02239098
	.public ov72_022390D8
	.public ov72_02239168
	.public ov72_022392AC
	.public ov72_022393B0
	.public ov72_02239614
	.public ov72_0223985C
	.public ov72_0223988C
	.public ov72_022399CC
	.public ov72_02239A08
	.public ov72_02239B5C
	.public ov72_02239B98
	.public ov72_02239BC8
	.public ov72_02239C8C
	.public ov72_02239D3C
	.public ov72_02239E94
	.public ov72_02239E9C
	.public ov72_02239EB4
	.public ov72_02239ED4
	.public ov72_02239F30
	.public ov72_02239FBC
	.public ov72_0223A010
	.public ov72_0223A414
	.public ov72_0223A41C
	.public ov72_0223A444
	.public ov72_0223A71C
	.public ov72_0223A8DC
	.public ov72_0223ABF4
	.public ov72_0223ABF8
	.public ov72_0223ABFC
	.public ov72_0223AC6C
	.public ov72_0223AC88
	.public ov72_0223ACA4
	.public ov72_0223AF70
	.public ov72_0223B084
	.public ov72_0223B2E4

	thumb_func_start ov72_022387D8
ov72_022387D8: ; 0x022387D8
	push {r4, lr}
	add r4, r0, #0
	bl ov72_02238124
	bl ov72_02238164
	add r0, r4, #0
	bl ov72_02238194
	add r0, r4, #0
	bl ov72_02238408
	ldr r0, _022387FC ; =ov72_022380FC
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	pop {r4, pc}
	nop
_022387FC: .word ov72_022380FC
	thumb_func_end ov72_022387D8


	thumb_func_start ov72_02238800
ov72_02238800: ; 0x02238800
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r0, _02238854 ; =0x00000D34
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeleteCharTransferTask
	ldr r0, _02238858 ; =0x00000D44
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeleteCharTransferTask
	ldr r0, _0223885C ; =0x00000D38
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeletePlttTransferTask
	ldr r0, _02238860 ; =0x00000D48
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeletePlttTransferTask
	ldr r7, _02238864 ; =0x00000D24
	mov r4, #0
	add r5, r6, #0
_0223882A:
	ldr r0, [r5, r7]
	bl Destroy2DGfxResObjMan
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0223882A
	ldr r0, _02238868 ; =0x00000BF8
	ldr r0, [r6, r0]
	bl SpriteList_Delete
	ldr r0, _02238868 ; =0x00000BF8
	mov r1, #0
	str r1, [r6, r0]
	bl OamManager_Free
	bl ObjCharTransfer_Destroy
	bl ObjPlttTransfer_Destroy
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02238854: .word 0x00000D34
_02238858: .word 0x00000D44
_0223885C: .word 0x00000D38
_02238860: .word 0x00000D48
_02238864: .word 0x00000D24
_02238868: .word 0x00000BF8
	thumb_func_end ov72_02238800


	thumb_func_start ov72_0223886C
ov72_0223886C: ; 0x0223886C
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	bl ov72_02239040
	mov r0, #8
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x43
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4, #4]
	bl ov72_022389C8
	add r0, r4, #0
	bl ov72_02238BEC
	add r0, r4, #0
	bl ov72_02238EE4
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
	ldr r0, [r4]
	mov r1, #0
	ldr r0, [r0]
	bl sub_0202D488
	add r1, r4, #0
	add r1, #0x90
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x90
	ldr r1, [r0]
	add r0, r4, #0
	add r0, #0x94
	str r1, [r0]
	add r0, r4, #0
	mov r1, #1
	add r0, #0x9c
	str r1, [r0]
	ldr r0, _02238940 ; =0x00000F4C
	mov r1, #0
	str r1, [r4, r0]
	bl ov00_021EC5B4
	cmp r0, #0
	bne _0223892E
	ldr r1, [r4]
	ldr r0, [r1, #0x24]
	cmp r0, #0
	beq _02238922
	ldr r0, [r1, #0xc]
	bl sub_02039418
	ldr r0, _02238944 ; =0x00000F0F
	mov r2, #1
	str r0, [sp]
	ldr r1, _02238948 ; =0x00000BD8
	add r0, r4, #0
	ldr r1, [r4, r1]
	add r3, r2, #0
	bl ov72_0223A350
	add r0, r4, #0
	mov r1, #0x2f
	mov r2, #2
	bl ov72_02238680
	add r0, r4, #0
	bl ov72_0223A420
	b _0223893A
_02238922:
	mov r0, #4
	bl Sys_ClearSleepDisableFlag
	mov r0, #0
	str r0, [r4, #0x1c]
	b _0223893A
_0223892E:
	ldr r0, [r4]
	ldr r0, [r0, #0xc]
	bl sub_02039418
	mov r0, #0x33
	str r0, [r4, #0x1c]
_0223893A:
	mov r0, #2
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_02238940: .word 0x00000F4C
_02238944: .word 0x00000F0F
_02238948: .word 0x00000BD8
	thumb_func_end ov72_0223886C


	thumb_func_start ov72_0223894C
ov72_0223894C: ; 0x0223894C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl ov72_022387C4
	bl sub_0203A930
	ldr r4, [r5, #0x1c]
	ldr r1, _02238978 ; =ov72_0223B660
	lsl r2, r4, #2
	ldr r1, [r1, r2]
	add r0, r5, #0
	blx r1
	ldr r1, [r5, #0x1c]
	cmp r4, r1
	beq _02238976
	mov r1, #0xfd
	mov r2, #0
	lsl r1, r1, #4
	strh r2, [r5, r1]
	add r1, r1, #2
	strh r2, [r5, r1]
_02238976:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02238978: .word ov72_0223B660
	thumb_func_end ov72_0223894C


	thumb_func_start ov72_0223897C
ov72_0223897C: ; 0x0223897C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _022389C0 ; =0x00000FD8
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02238996
	bl SysTask_Destroy
	ldr r0, _022389C0 ; =0x00000FD8
	mov r1, #0
	str r1, [r4, r0]
	add r0, r0, #4
	str r1, [r4, r0]
_02238996:
	add r0, r4, #0
	bl ov72_02239098
	add r0, r4, #0
	bl ov72_02238FFC
	ldr r0, [r4, #4]
	bl ov72_02238AEC
	ldr r0, _022389C4 ; =0x00000FDC
	mov r1, #0
	str r1, [r4, r0]
	ldr r0, [r4, #0x14]
	str r0, [r4, #0x10]
	cmp r0, #0
	bne _022389BA
	mov r0, #5
	pop {r4, pc}
_022389BA:
	mov r0, #1
	pop {r4, pc}
	nop
_022389C0: .word 0x00000FD8
_022389C4: .word 0x00000FDC
	thumb_func_end ov72_0223897C


	thumb_func_start ov72_022389C8
ov72_022389C8: ; 0x022389C8
	push {r4, r5, lr}
	sub sp, #0x8c
	ldr r5, _02238AD8 ; =ov72_0223B42C
	add r4, r0, #0
	ldmia r5!, {r0, r1}
	add r3, sp, #0x70
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
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add r0, r4, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02238ADC ; =ov72_0223B410
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
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r5, _02238AE0 ; =ov72_0223B448
	add r3, sp, #0x38
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
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02238AE4 ; =ov72_0223B3D8
	add r3, sp, #0x1c
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
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r5, _02238AE8 ; =ov72_0223B3F4
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #6
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add r0, r4, #0
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	mov r0, #0
	mov r1, #0x20
	add r2, r0, #0
	mov r3, #0x43
	bl BG_ClearCharDataRange
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x43
	bl BG_ClearCharDataRange
	mov r0, #6
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x43
	bl BG_ClearCharDataRange
	add sp, #0x8c
	pop {r4, r5, pc}
	nop
_02238AD8: .word ov72_0223B42C
_02238ADC: .word ov72_0223B410
_02238AE0: .word ov72_0223B448
_02238AE4: .word ov72_0223B3D8
_02238AE8: .word ov72_0223B3F4
	thumb_func_end ov72_022389C8

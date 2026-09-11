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
	.public ov72_02237B80
	.public ov72_02237BD0
	.public ov72_02237CB0
	.public ov72_02237CF4
	.public ov72_02237D50
	.public ov72_022380FC
	.public ov72_02238124
	.public NintendoWfc_Exit
	.public NintendoWfc_Main
	.public ov72_02237D88




	thumb_func_start NintendoWfc_Init
NintendoWfc_Init: ; 0x02237E20
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r1, #0
	add r6, r0, #0
	ldr r0, [r5]
	cmp r0, #0
	beq _02237E36
	cmp r0, #1
	bne _02237E34
	b _02237F4A
_02237E34:
	b _02237F60
_02237E36:
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _02237F68 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _02237F6C ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	mov r2, #5
	mov r0, #3
	mov r1, #0x43
	lsl r2, r2, #0x10
	bl Heap_Create
	bl LoadDwcOverlay
	bl LoadOVY38
	mov r0, #0x43
	bl sub_02039FD8
	ldr r1, _02237F70 ; =0x000013A4
	add r0, r6, #0
	mov r2, #0x43
	bl OverlayManager_CreateAndGetData
	ldr r2, _02237F70 ; =0x000013A4
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x43
	bl BgConfig_Alloc
	str r0, [r4, #4]
	ldr r0, _02237F74 ; =ov72_0223B92C
	add r2, sp, #0
	ldr r3, _02237F78 ; =ov72_0223B354
	str r4, [r0, #4]
	add r7, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r0, r7, #0
	bl SetBothScreensModesAndDisable
	mov r0, #0xb
	mov r1, #0x20
	mov r2, #0x43
	bl MessageFormat_New_Custom
	mov r1, #0xbd
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r2, _02237F7C ; =0x00000306
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x43
	bl NewMsgDataFromNarc
	ldr r1, _02237F80 ; =0x00000BD4
	ldr r2, _02237F84 ; =0x0000030A
	str r0, [r4, r1]
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x43
	bl NewMsgDataFromNarc
	ldr r1, _02237F88 ; =0x00000BD8
	str r0, [r4, r1]
	mov r2, #0x32
	mov r0, #0
	mov r1, #0x1b
	lsl r2, r2, #4
	mov r3, #0x43
	bl NewMsgDataFromNarc
	ldr r1, _02237F8C ; =0x00000BDC
	str r0, [r4, r1]
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	add r0, r4, #0
	add r1, r6, #0
	bl ov72_02238144
	add r0, r4, #0
	bl ov72_022387D8
	mov r1, #0
	mov r0, #0x34
	add r2, r1, #0
	bl Sound_SetSceneAndPlayBGM
	ldr r1, _02237F90 ; =0x00020020
	mov r0, #0x43
	bl Heap_Alloc
	str r0, [r4, #0x24]
	add r0, #0x1f
	mov r1, #0x1f
	bic r0, r1
	mov r1, #2
	lsl r1, r1, #0x10
	mov r2, #0
	bl NNS_FndCreateExpHeapEx
	str r0, [r4, #0x28]
	ldr r1, _02237F94 ; =0x0000047D
	mov r0, #0xb
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r2, _02237F98 ; =0x04000304
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	mov r0, #1
	str r0, [r5]
	b _02237F60
_02237F4A:
	bl sub_02034D8C
	mov r0, #4
	mov r1, #0x43
	bl FontID_Alloc
	mov r0, #0
	str r0, [r5]
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02237F60:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02237F68: .word 0xFFFFE0FF
_02237F6C: .word 0x04001000
_02237F70: .word 0x000013A4
_02237F74: .word ov72_0223B92C
_02237F78: .word ov72_0223B354
_02237F7C: .word 0x00000306
_02237F80: .word 0x00000BD4
_02237F84: .word 0x0000030A
_02237F88: .word 0x00000BD8
_02237F8C: .word 0x00000BDC
_02237F90: .word 0x00020020
_02237F94: .word 0x0000047D
_02237F98: .word 0x04000304
	thumb_func_end NintendoWfc_Init

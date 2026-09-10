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

	thumb_func_start ov72_02238164
ov72_02238164: ; 0x02238164
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _02238190 ; =ov72_0223B344
	add r3, sp, #0
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl ObjCharTransfer_Init
	mov r0, #0x14
	mov r1, #0x43
	bl ObjPlttTransfer_Init
	bl ObjCharTransfer_ClearBuffers
	bl ObjPlttTransfer_Reset
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_02238190: .word ov72_0223B344
	thumb_func_end ov72_02238164


	thumb_func_start ov72_02238194
ov72_02238194: ; 0x02238194
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	mov r0, #0xef
	mov r1, #0x43
	bl NARC_New
	str r0, [sp, #0x14]
	mov r0, #0xee
	mov r1, #0x43
	bl NARC_New
	add r7, r0, #0
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x7e
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x43
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	ldr r1, _022383AC ; =0x00000BFC
	mov r0, #0x14
	add r1, r5, r1
	mov r2, #0x43
	bl G2dRenderer_Init
	ldr r1, _022383B0 ; =0x00000BF8
	mov r2, #1
	str r0, [r5, r1]
	add r0, r1, #4
	add r0, r5, r0
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	mov r6, #0
	add r4, r5, #0
_022381EC:
	mov r0, #3
	add r1, r6, #0
	mov r2, #0x43
	bl Create2DGfxResObjMan
	ldr r1, _022383B4 ; =0x00000D24
	add r6, r6, #1
	str r0, [r4, r1]
	add r4, r4, #4
	cmp r6, #4
	blt _022381EC
	mov r3, #0
	str r3, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x43
	str r0, [sp, #8]
	add r0, r1, #0
	ldr r0, [r5, r0]
	add r1, r7, #0
	mov r2, #1
	bl AddCharResObjFromOpenNarc
	ldr r1, _022383B8 ; =0x00000D34
	mov r2, #0
	str r0, [r5, r1]
	str r2, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0x43
	sub r1, #0xc
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r7, #0
	add r3, r2, #0
	bl AddPlttResObjFromOpenNarc
	ldr r1, _022383BC ; =0x00000D38
	mov r3, #0
	str r0, [r5, r1]
	str r3, [sp]
	mov r2, #2
	str r2, [sp, #4]
	mov r0, #0x43
	sub r1, #0xc
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	bl AddCellOrAnimResObjFromOpenNarc
	ldr r1, _022383C0 ; =0x00000D3C
	mov r3, #0
	str r0, [r5, r1]
	str r3, [sp]
	mov r2, #3
	str r2, [sp, #4]
	mov r0, #0x43
	sub r1, #0xc
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x35
	lsl r1, r1, #6
	str r0, [r5, r1]
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x43
	sub r1, #0x1c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #5
	mov r3, #0
	bl AddCharResObjFromOpenNarc
	ldr r1, _022383C4 ; =0x00000D44
	mov r2, #4
	str r0, [r5, r1]
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0x43
	sub r1, #0x1c
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r3, #0
	bl AddPlttResObjFromOpenNarc
	ldr r1, _022383C8 ; =0x00000D48
	mov r2, #6
	str r0, [r5, r1]
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x43
	sub r1, #0x1c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	ldr r1, _022383CC ; =0x00000D4C
	mov r2, #7
	str r0, [r5, r1]
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x43
	sub r1, #0x1c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0xd5
	lsl r1, r1, #4
	str r0, [r5, r1]
	mov r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x43
	sub r1, #0x2c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	ldr r1, [sp, #0x14]
	mov r2, #0xc
	mov r3, #0
	bl AddCharResObjFromOpenNarc
	ldr r1, _022383D0 ; =0x00000D54
	mov r2, #0xb
	str r0, [r5, r1]
	mov r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x43
	sub r1, #0x2c
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	ldr r1, [sp, #0x14]
	mov r3, #0
	bl AddPlttResObjFromOpenNarc
	ldr r1, _022383D4 ; =0x00000D58
	mov r2, #0xd
	str r0, [r5, r1]
	mov r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x43
	sub r1, #0x2c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	ldr r1, [sp, #0x14]
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	ldr r1, _022383D8 ; =0x00000D5C
	mov r2, #0xe
	str r0, [r5, r1]
	mov r0, #2
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x43
	sub r1, #0x2c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	ldr r1, [sp, #0x14]
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0xd6
	lsl r1, r1, #4
	str r0, [r5, r1]
	sub r1, #0x2c
	ldr r0, [r5, r1]
	bl SpriteTransfer_CreateCharTransferTask
	ldr r0, _022383C4 ; =0x00000D44
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateCharTransferTask
	ldr r0, _022383D0 ; =0x00000D54
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateCharTransferTask
	ldr r0, _022383BC ; =0x00000D38
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	ldr r0, _022383C8 ; =0x00000D48
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	ldr r0, _022383D4 ; =0x00000D58
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	add r0, r7, #0
	bl NARC_Delete
	ldr r0, [sp, #0x14]
	bl NARC_Delete
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022383AC: .word 0x00000BFC
_022383B0: .word 0x00000BF8
_022383B4: .word 0x00000D24
_022383B8: .word 0x00000D34
_022383BC: .word 0x00000D38
_022383C0: .word 0x00000D3C
_022383C4: .word 0x00000D44
_022383C8: .word 0x00000D48
_022383CC: .word 0x00000D4C
_022383D0: .word 0x00000D54
_022383D4: .word 0x00000D58
_022383D8: .word 0x00000D5C
	thumb_func_end ov72_02238194

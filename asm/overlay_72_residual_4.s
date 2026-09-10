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

	thumb_func_start ov72_02238408
ov72_02238408: ; 0x02238408
	push {r4, r5, r6, r7, lr}
	sub sp, #0x5c
	mov r1, #0
	add r6, r0, #0
	str r1, [sp]
	sub r0, r1, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _02238638 ; =0x00000D24
	str r1, [sp, #0x10]
	ldr r0, [r6, r2]
	add r3, r1, #0
	str r0, [sp, #0x14]
	add r0, r2, #4
	ldr r0, [r6, r0]
	str r0, [sp, #0x18]
	add r0, r2, #0
	add r0, #8
	ldr r0, [r6, r0]
	str r0, [sp, #0x1c]
	add r0, r2, #0
	add r0, #0xc
	ldr r0, [r6, r0]
	add r2, #0x40
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, r6, r2
	add r2, r1, #0
	str r1, [sp, #0x28]
	bl CreateSpriteResourcesHeader
	mov r1, #1
	str r1, [sp]
	sub r0, r1, #2
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r3, _02238638 ; =0x00000D24
	str r0, [sp, #0x10]
	ldr r2, [r6, r3]
	str r2, [sp, #0x14]
	add r2, r3, #4
	ldr r2, [r6, r2]
	str r2, [sp, #0x18]
	add r2, r3, #0
	add r2, #8
	ldr r2, [r6, r2]
	str r2, [sp, #0x1c]
	add r2, r3, #0
	add r2, #0xc
	ldr r2, [r6, r2]
	add r3, #0x64
	str r2, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, r6, r3
	add r2, r1, #0
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #2
	str r1, [sp]
	sub r0, r1, #3
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r3, _02238638 ; =0x00000D24
	str r0, [sp, #0x10]
	ldr r2, [r6, r3]
	str r2, [sp, #0x14]
	add r2, r3, #4
	ldr r2, [r6, r2]
	str r2, [sp, #0x18]
	add r2, r3, #0
	add r2, #8
	ldr r2, [r6, r2]
	str r2, [sp, #0x1c]
	add r2, r3, #0
	add r2, #0xc
	ldr r2, [r6, r2]
	add r3, #0x88
	str r2, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, r6, r3
	add r2, r1, #0
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	ldr r2, _0223863C ; =0x00000D64
	add r0, sp, #0x2c
	add r1, r6, #0
	add r2, r6, r2
	mov r3, #2
	bl ov72_022383DC
	ldr r4, _02238640 ; =ov72_0223B364
	mov r7, #0
	add r5, r6, #0
_022384D4:
	ldrh r0, [r4]
	lsl r0, r0, #0xc
	str r0, [sp, #0x34]
	ldrh r0, [r4, #2]
	lsl r1, r0, #0xc
	mov r0, #1
	lsl r0, r0, #0x14
	add r0, r1, r0
	str r0, [sp, #0x38]
	add r0, sp, #0x2c
	bl Sprite_CreateAffine
	ldr r1, _02238644 ; =0x00000DF4
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	ldr r0, _02238644 ; =0x00000DF4
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _02238644 ; =0x00000DF4
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	add r7, r7, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r7, #3
	blt _022384D4
	ldr r2, _02238648 ; =0x00000D88
	add r0, sp, #0x2c
	add r1, r6, #0
	add r2, r6, r2
	mov r3, #2
	bl ov72_022383DC
	mov r0, #2
	lsl r0, r0, #0x10
	str r0, [sp, #0x34]
	ldr r0, _0223864C ; =0x00151000
	str r0, [sp, #0x38]
	add r0, sp, #0x2c
	bl Sprite_CreateAffine
	mov r1, #0xe
	lsl r1, r1, #8
	str r0, [r6, r1]
	ldr r0, [r6, r1]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0xe
	lsl r0, r0, #8
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0xe
	lsl r0, r0, #8
	ldr r0, [r6, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #6
	lsl r0, r0, #0x10
	str r0, [sp, #0x34]
	ldr r0, _02238650 ; =0x00129000
	str r0, [sp, #0x38]
	add r0, sp, #0x2c
	bl Sprite_CreateAffine
	ldr r1, _02238654 ; =0x00000E04
	str r0, [r6, r1]
	ldr r0, [r6, r1]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	ldr r0, _02238654 ; =0x00000E04
	mov r1, #0
	ldr r0, [r6, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _02238654 ; =0x00000E04
	mov r1, #0
	ldr r0, [r6, r0]
	bl Sprite_SetDrawFlag
	ldr r4, _02238658 ; =ov72_0223B338
	mov r7, #0
	add r5, r6, #0
_02238592:
	ldrh r0, [r4]
	lsl r0, r0, #0xc
	str r0, [sp, #0x34]
	ldrh r0, [r4, #2]
	lsl r1, r0, #0xc
	mov r0, #1
	lsl r0, r0, #0x14
	add r0, r1, r0
	str r0, [sp, #0x38]
	add r0, sp, #0x2c
	bl Sprite_CreateAffine
	ldr r1, _0223865C ; =0x00000E08
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	ldr r0, _0223865C ; =0x00000E08
	mov r1, #3
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _0223865C ; =0x00000E08
	mov r1, #1
	ldr r0, [r5, r0]
	bl Sprite_SetPriority
	ldr r0, _0223865C ; =0x00000E08
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	add r7, r7, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r7, #3
	blt _02238592
	ldr r2, _02238660 ; =0x00000DAC
	add r0, sp, #0x2c
	add r1, r6, #0
	add r2, r6, r2
	mov r3, #2
	bl ov72_022383DC
	mov r0, #2
	lsl r0, r0, #0x12
	str r0, [sp, #0x34]
	ldr r0, _0223864C ; =0x00151000
	str r0, [sp, #0x38]
	add r0, sp, #0x2c
	bl Sprite_CreateAffine
	ldr r1, _02238664 ; =0x00000E14
	str r0, [r6, r1]
	ldr r0, [r6, r1]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	ldr r0, _02238664 ; =0x00000E14
	mov r1, #1
	ldr r0, [r6, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _02238664 ; =0x00000E14
	mov r1, #0
	ldr r0, [r6, r0]
	bl Sprite_SetDrawFlag
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	bl sub_0203A880
	add sp, #0x5c
	pop {r4, r5, r6, r7, pc}
	nop
_02238638: .word 0x00000D24
_0223863C: .word 0x00000D64
_02238640: .word ov72_0223B364
_02238644: .word 0x00000DF4
_02238648: .word 0x00000D88
_0223864C: .word 0x00151000
_02238650: .word 0x00129000
_02238654: .word 0x00000E04
_02238658: .word ov72_0223B338
_0223865C: .word 0x00000E08
_02238660: .word 0x00000DAC
_02238664: .word 0x00000E14
	thumb_func_end ov72_02238408

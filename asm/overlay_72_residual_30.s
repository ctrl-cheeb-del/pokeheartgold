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

	thumb_func_start ov72_0223B088
ov72_0223B088: ; 0x0223B088
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #4]
	bl Sprite_IsAnimated
	cmp r0, #0
	beq _0223B09A
	mov r0, #0
	pop {r4, pc}
_0223B09A:
	add r0, r4, #0
	add r0, #0x2f
	ldrb r0, [r0]
	mov r1, #0
	bl ToggleBgLayer
	add r0, r4, #0
	add r0, #0x32
	ldrb r0, [r0]
	mov r1, #0
	bl ToggleBgLayer
	add r0, r4, #0
	bl ov72_0223B2C0
	ldr r0, [r4, #4]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #1
	pop {r4, pc}
	thumb_func_end ov72_0223B088


	thumb_func_start ov72_0223B0C4
ov72_0223B0C4: ; 0x0223B0C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r4, r0, #0
	ldr r1, [r4, #0x28]
	mov r0, #0xef
	bl NARC_New
	add r1, r4, #0
	add r1, #0x2f
	ldrb r1, [r1]
	str r0, [sp, #0x14]
	cmp r1, #3
	bhi _0223B108
	mov r1, #0x20
	str r1, [sp]
	ldr r1, [r4, #0x28]
	add r3, r4, #0
	str r1, [sp, #4]
	add r3, #0x2e
	ldrb r3, [r3]
	mov r1, #0
	add r2, r1, #0
	lsl r3, r3, #5
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	add r1, r4, #0
	add r1, #0x30
	ldrb r1, [r1]
	ldr r2, [r4, #0x28]
	mov r0, #0
	lsl r1, r1, #5
	bl LoadFontPal0
	b _0223B130
_0223B108:
	mov r1, #0x20
	str r1, [sp]
	ldr r1, [r4, #0x28]
	add r3, r4, #0
	str r1, [sp, #4]
	add r3, #0x2e
	ldrb r3, [r3]
	mov r1, #0
	mov r2, #4
	lsl r3, r3, #5
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	add r1, r4, #0
	add r1, #0x30
	ldrb r1, [r1]
	ldr r2, [r4, #0x28]
	mov r0, #4
	lsl r1, r1, #5
	bl LoadFontPal0
_0223B130:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x28]
	add r3, r4, #0
	str r0, [sp, #0xc]
	add r3, #0x2f
	ldrb r3, [r3]
	ldr r0, [sp, #0x14]
	ldr r2, [r4]
	mov r1, #1
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	ldr r0, [r4, #0x28]
	mov r1, #0xa
	str r0, [sp]
	ldr r0, [sp, #0x14]
	mov r2, #0
	add r3, sp, #0x18
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	add r1, r4, #0
	add r1, #0x2f
	str r0, [sp, #0x10]
	ldrb r1, [r1]
	ldr r0, [r4]
	bl GetBgTilemapBuffer
	ldr r2, [sp, #0x18]
	mov r5, #3
	ldr r7, _0223B1C4 ; =0x00000FFF
	add r3, r0, #0
	mov r1, #0
	add r2, #0xc
	lsl r5, r5, #8
_0223B178:
	add r0, r4, #0
	add r0, #0x2e
	ldrh r6, [r2]
	ldrb r0, [r0]
	add r1, r1, #1
	and r6, r7
	lsl r0, r0, #0xc
	orr r0, r6
	strh r0, [r3]
	add r2, r2, #2
	add r3, r3, #2
	cmp r1, r5
	blt _0223B178
	add r1, r4, #0
	add r1, #0x2f
	ldrb r1, [r1]
	ldr r0, [r4]
	bl BgCommitTilemapBufferToVram
	ldr r0, [sp, #0x10]
	bl Heap_Free
	ldr r0, [sp, #0x14]
	bl NARC_Delete
	add r0, r4, #0
	add r0, #0x2f
	ldrb r0, [r0]
	mov r1, #1
	bl ToggleBgLayer
	add r4, #0x32
	ldrb r0, [r4]
	mov r1, #1
	bl ToggleBgLayer
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0223B1C4: .word 0x00000FFF
	thumb_func_end ov72_0223B0C4


	thumb_func_start ov72_0223B1C8
ov72_0223B1C8: ; 0x0223B1C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	ldr r3, [r5, #0x28]
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xbf
	bl NewMsgDataFromNarc
	add r4, r0, #0
	mov r0, #8
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x30
	ldrb r0, [r0]
	add r2, r5, #0
	add r1, r5, #0
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r0, #0x31
	ldrb r0, [r0]
	add r2, #0x32
	add r1, #8
	str r0, [sp, #0x10]
	ldrb r2, [r2]
	ldr r0, [r5]
	mov r3, #0xc
	bl AddWindowParameterized
	add r0, r5, #0
	add r0, #8
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0xe
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x30
	ldrb r0, [r0]
	add r2, r5, #0
	add r1, r5, #0
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r0, #0x31
	ldrb r0, [r0]
	add r2, #0x32
	add r1, #0x18
	add r0, #0x10
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldrb r2, [r2]
	ldr r0, [r5]
	mov r3, #0xc
	bl AddWindowParameterized
	add r0, r5, #0
	add r0, #0x18
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	mov r1, #0x2e
	bl NewString_ReadMsgData
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #0x2f
	bl NewString_ReadMsgData
	mov r3, #0
	add r7, r0, #0
	str r3, [sp]
	ldr r0, _0223B2BC ; =0x000F0100
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #8
	mov r1, #4
	add r2, r6, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	mov r3, #0
	str r3, [sp]
	ldr r0, _0223B2BC ; =0x000F0100
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x18
	mov r1, #4
	add r2, r7, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #8
	bl CopyWindowToVram
	add r5, #0x18
	add r0, r5, #0
	bl CopyWindowToVram
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #0
	bl DestroyMsgData
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_0223B2BC: .word 0x000F0100
	thumb_func_end ov72_0223B1C8


	thumb_func_start ov72_0223B2C0
ov72_0223B2C0: ; 0x0223B2C0
	push {r4, lr}
	add r4, r0, #0
	add r0, #0x18
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	add r0, #8
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	add r0, #0x18
	bl RemoveWindow
	add r4, #8
	add r0, r4, #0
	bl RemoveWindow
	pop {r4, pc}
	thumb_func_end ov72_0223B2C0

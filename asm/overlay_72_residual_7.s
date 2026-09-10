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

	thumb_func_start ov72_02238B18
ov72_02238B18: ; 0x02238B18
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r4, [r5, #4]
	cmp r1, #0
	bne _02238B86
	mov r0, #0x58
	mov r1, #0x43
	bl NARC_New
	mov r1, #1
	lsl r1, r1, #8
	str r1, [sp]
	mov r1, #0x43
	str r1, [sp, #4]
	mov r1, #3
	mov r2, #4
	mov r3, #0
	add r6, r0, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x43
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #0xb
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r1, #0
	mov r0, #6
	str r1, [sp]
	lsl r0, r0, #8
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, #0x43
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #0xc
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r0, _02238BE8 ; =0x00001304
	mov r1, #0
	str r1, [r5, r0]
	add r0, r6, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r4, r5, r6, pc}
_02238B86:
	mov r0, #0xee
	mov r1, #0x43
	bl NARC_New
	ldr r1, _02238BE8 ; =0x00001304
	mov r2, #1
	str r2, [r5, r1]
	mov r1, #0x40
	str r1, [sp]
	mov r1, #0x43
	str r1, [sp, #4]
	mov r1, #8
	mov r2, #4
	mov r3, #0
	add r6, r0, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x43
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #9
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r1, #0
	mov r0, #6
	str r1, [sp]
	lsl r0, r0, #8
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, #0x43
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #0xa
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r0, r6, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_02238BE8: .word 0x00001304
	thumb_func_end ov72_02238B18


	thumb_func_start ov72_02238BEC
ov72_02238BEC: ; 0x02238BEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	str r0, [sp, #0x10]
	ldr r4, [r0, #4]
	mov r0, #0x58
	mov r1, #0x43
	bl NARC_New
	mov r2, #0
	str r2, [sp]
	mov r1, #0x43
	str r1, [sp, #4]
	mov r1, #3
	add r3, r2, #0
	str r0, [sp, #0x2c]
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r3, #0
	str r3, [sp]
	mov r0, #0x43
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	mov r1, #3
	mov r2, #4
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r1, #0x1a
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x43
	bl LoadFontPal1
	mov r1, #0x1a
	mov r0, #4
	lsl r1, r1, #4
	mov r2, #0x43
	bl LoadFontPal1
	ldr r0, [sp, #0x10]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x43
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0
	mov r2, #1
	mov r3, #0xe
	bl LoadUserFrameGfx2
	ldr r0, [sp, #0x10]
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x43
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #4
	mov r2, #1
	mov r3, #0xe
	bl LoadUserFrameGfx2
	mov r1, #0
	str r1, [sp]
	mov r0, #0x43
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0x1f
	mov r3, #0xb
	bl LoadUserFrameGfx1
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x43
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x2c]
	mov r1, #2
	add r2, r4, #0
	mov r3, #1
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r1, #0
	mov r0, #6
	str r1, [sp]
	lsl r0, r0, #8
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, #0x43
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x2c]
	mov r1, #6
	add r2, r4, #0
	mov r3, #1
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x43
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x2c]
	mov r1, #0xb
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r1, #0
	mov r0, #6
	str r1, [sp]
	lsl r0, r0, #8
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, #0x43
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x2c]
	mov r1, #0xc
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	add r1, r0, #0
	bl BG_SetMaskColor
	mov r0, #4
	mov r1, #0
	bl BG_SetMaskColor
	mov r2, #0x33
	ldr r1, _02238E28 ; =0x00000FD8
	ldr r0, [sp, #0x10]
	lsl r2, r2, #4
	add r0, r0, r1
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [sp, #0x2c]
	mov r1, #5
	add r2, sp, #0x38
	mov r3, #0x43
	bl GfGfxLoader_GetPlttDataFromOpenNarc
	add r4, r0, #0
	ldr r0, [sp, #0x38]
	mov r2, #0xfe
	ldr r1, [sp, #0x10]
	lsl r2, r2, #4
	add r1, r1, r2
	ldr r0, [r0, #0xc]
	mov r2, #0x80
	bl MIi_CpuCopy16
	ldr r0, [sp, #0x38]
	ldr r2, _02238E2C ; =0x00001060
	ldr r1, [sp, #0x10]
	ldr r0, [r0, #0xc]
	add r1, r1, r2
	mov r2, #0x80
	bl MIi_CpuCopy16
	add r0, r4, #0
	bl Heap_Free
	mov r0, #0
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	ldr r1, _02238E2C ; =0x00001060
	ldr r0, [sp, #0x10]
	add r0, r0, r1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	sub r1, #0x80
	add r0, r0, r1
	str r0, [sp, #0x14]
_02238D5E:
	mov r0, #0
	str r0, [sp, #0x20]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	lsl r1, r0, #5
	ldr r0, [sp, #0x10]
	add r0, r0, r1
	str r0, [sp, #0x30]
_02238D70:
	ldr r0, [sp, #0x24]
	cmp r0, #0x15
	blt _02238D7A
	bl GF_AssertFail
_02238D7A:
	ldr r0, [sp, #0x30]
	mov r7, #1
	add r4, r0, #2
	ldr r0, [sp, #0x18]
	add r6, r0, #2
	ldr r0, [sp, #0x14]
	add r5, r0, #2
	ldr r0, [sp, #0x20]
	asr r0, r0, #8
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x34]
_02238D92:
	mov r0, #0xfe
	lsl r0, r0, #4
	ldrh r0, [r4, r0]
	ldr r3, [sp, #0x34]
	add r1, r6, #0
	str r0, [sp]
	add r0, r5, #0
	mov r2, #1
	bl BlendPalette
	add r7, r7, #1
	add r4, r4, #2
	add r6, r6, #2
	add r5, r5, #2
	cmp r7, #0x10
	blt _02238D92
	ldr r0, [sp, #0x18]
	add r0, #0x20
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x24]
	add r0, r0, #1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x1c]
	cmp r0, #1
	beq _02238DDE
	mov r0, #3
	ldr r1, [sp, #0x20]
	lsl r0, r0, #8
	add r1, r1, r0
	mov r0, #1
	lsl r0, r0, #0xc
	str r1, [sp, #0x20]
	cmp r1, r0
	blt _02238D70
	str r0, [sp, #0x20]
	mov r0, #1
	str r0, [sp, #0x1c]
	b _02238D70
_02238DDE:
	ldr r0, [sp, #0x14]
	add r0, #0x20
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	str r0, [sp, #0x28]
	cmp r0, #3
	blt _02238D5E
	ldr r1, _02238E2C ; =0x00001060
	ldr r0, [sp, #0x10]
	add r0, r0, r1
	mov r1, #0x2a
	lsl r1, r1, #4
	bl DC_FlushRange
	ldr r1, _02238E30 ; =0x00000FDC
	ldr r0, [sp, #0x10]
	mov r2, #1
	str r2, [r0, r1]
	ldr r2, _02238E34 ; =0x00001304
	mov r3, #0
	str r3, [r0, r2]
	sub r2, r1, #4
	ldr r1, [sp, #0x10]
	ldr r0, _02238E38 ; =ov72_02238E3C
	add r1, r1, r2
	mov r2, #0x14
	bl SysTask_CreateOnVBlankQueue
	ldr r2, _02238E28 ; =0x00000FD8
	ldr r1, [sp, #0x10]
	str r0, [r1, r2]
	ldr r0, [sp, #0x2c]
	bl NARC_Delete
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02238E28: .word 0x00000FD8
_02238E2C: .word 0x00001060
_02238E30: .word 0x00000FDC
_02238E34: .word 0x00001304
_02238E38: .word ov72_02238E3C
	thumb_func_end ov72_02238BEC


	thumb_func_start ov72_02238E3C
ov72_02238E3C: ; 0x02238E3C
	push {r4, lr}
	add r4, r1, #0
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _02238EDA
	ldr r1, _02238EDC ; =0x0000032B
	mov r0, #1
	ldrb r2, [r4, r1]
	eor r2, r0
	strb r2, [r4, r1]
	ldrb r2, [r4, r1]
	tst r0, r2
	bne _02238EDA
	add r0, r1, #1
	ldr r0, [r4, r0]
	cmp r0, #1
	bhi _02238E72
	sub r0, r1, #3
	ldrsh r0, [r4, r0]
	add r2, r4, #0
	add r2, #0x88
	lsl r0, r0, #5
	add r0, r2, r0
	mov r1, #0
	mov r2, #0x20
	bl GX_LoadBGPltt
_02238E72:
	mov r0, #0xcb
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02238E80
	cmp r0, #2
	bne _02238E96
_02238E80:
	mov r0, #0xca
	lsl r0, r0, #2
	ldrsh r0, [r4, r0]
	add r1, r4, #0
	add r1, #0x88
	lsl r0, r0, #5
	add r0, r1, r0
	mov r1, #0
	mov r2, #0x20
	bl GXS_LoadBGPltt
_02238E96:
	ldr r0, _02238EE0 ; =0x0000032A
	ldrsb r1, [r4, r0]
	cmp r1, #0
	bne _02238EBE
	sub r1, r0, #2
	ldrsh r1, [r4, r1]
	add r2, r1, #1
	sub r1, r0, #2
	strh r2, [r4, r1]
	ldrsh r1, [r4, r1]
	cmp r1, #0x15
	blt _02238EDA
	mov r2, #0x13
	sub r1, r0, #2
	strh r2, [r4, r1]
	ldrsb r2, [r4, r0]
	mov r1, #1
	eor r1, r2
	strb r1, [r4, r0]
	pop {r4, pc}
_02238EBE:
	sub r1, r0, #2
	ldrsh r1, [r4, r1]
	sub r2, r1, #1
	sub r1, r0, #2
	strh r2, [r4, r1]
	ldrsh r1, [r4, r1]
	cmp r1, #0
	bge _02238EDA
	mov r2, #1
	sub r1, r0, #2
	strh r2, [r4, r1]
	ldrsb r1, [r4, r0]
	eor r1, r2
	strb r1, [r4, r0]
_02238EDA:
	pop {r4, pc}
	.balign 4, 0
_02238EDC: .word 0x0000032B
_02238EE0: .word 0x0000032A
	thumb_func_end ov72_02238E3C


	thumb_func_start ov72_02238EE4
ov72_02238EE4: ; 0x02238EE4
	push {r3, r4, lr}
	sub sp, #0x14
	mov r3, #4
	add r4, r0, #0
	str r3, [sp]
	mov r0, #0x17
	str r0, [sp, #4]
	mov r0, #0x10
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0xa4
	ldr r1, _02238FE0 ; =0x00000E58
	str r0, [sp, #0x10]
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #0
	bl AddWindowParameterized
	ldr r0, _02238FE0 ; =0x00000E58
	mov r1, #0
	add r0, r4, r0
	bl FillWindowPixelBuffer
	mov r0, #0xe
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x94
	ldr r1, _02238FE4 ; =0x00000E38
	str r0, [sp, #0x10]
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #0
	mov r3, #0x1a
	bl AddWindowParameterized
	ldr r0, _02238FE4 ; =0x00000E38
	mov r1, #0xf
	add r0, r4, r0
	bl FillWindowPixelBuffer
	mov r0, #0xe
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x9c
	ldr r1, _02238FE8 ; =0x00000E28
	str r0, [sp, #0x10]
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #0
	mov r3, #0x1a
	bl AddWindowParameterized
	ldr r0, _02238FE8 ; =0x00000E28
	mov r1, #0xf
	add r0, r4, r0
	bl FillWindowPixelBuffer
	mov r0, #1
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x85
	lsl r0, r0, #2
	ldr r1, _02238FEC ; =0x00000E48
	str r0, [sp, #0x10]
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #0
	mov r3, #4
	bl AddWindowParameterized
	ldr r0, _02238FEC ; =0x00000E48
	mov r1, #0
	add r0, r4, r0
	bl FillWindowPixelBuffer
	mov r3, #1
	ldr r0, _02238FF0 ; =0x000F0E00
	str r3, [sp]
	str r0, [sp, #4]
	ldr r1, _02238FF4 ; =0x00000BE4
	ldr r0, _02238FEC ; =0x00000E48
	ldr r1, [r4, r1]
	add r0, r4, r0
	mov r2, #0
	bl ov72_0223A3E0
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x28
	ldr r1, _02238FF8 ; =0x00000E18
	str r0, [sp, #0x10]
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #0
	mov r3, #2
	bl AddWindowParameterized
	ldr r0, _02238FF8 ; =0x00000E18
	mov r1, #0xf
	add r0, r4, r0
	bl FillWindowPixelBuffer
	add sp, #0x14
	pop {r3, r4, pc}
	.balign 4, 0
_02238FE0: .word 0x00000E58
_02238FE4: .word 0x00000E38
_02238FE8: .word 0x00000E28
_02238FEC: .word 0x00000E48
_02238FF0: .word 0x000F0E00
_02238FF4: .word 0x00000BE4
_02238FF8: .word 0x00000E18
	thumb_func_end ov72_02238EE4

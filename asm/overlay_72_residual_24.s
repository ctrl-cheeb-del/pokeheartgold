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

	thumb_func_start ov72_0223A460
ov72_0223A460: ; 0x0223A460
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #1
	add r6, r1, #0
	lsl r0, r0, #8
	mov r1, #0x43
	bl String_New
	add r4, r0, #0
	ldr r0, _0223A4D0 ; =0x00000BDC
	add r1, r6, #0
	ldr r0, [r5, r0]
	add r2, r4, #0
	bl ReadMsgDataIntoString
	mov r1, #0xbd
	lsl r1, r1, #4
	ldr r0, [r5, r1]
	add r1, #0x20
	ldr r1, [r5, r1]
	add r2, r4, #0
	bl StringExpandPlaceholders
	ldr r0, _0223A4D4 ; =0x00000E58
	mov r1, #0xf
	add r0, r5, r0
	bl FillWindowPixelBuffer
	ldr r0, _0223A4D4 ; =0x00000E58
	mov r1, #1
	add r0, r5, r0
	mov r2, #0x1f
	mov r3, #0xb
	bl DrawFrameAndWindow1
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r2, #0xbf
	ldr r0, _0223A4D4 ; =0x00000E58
	str r3, [sp, #8]
	lsl r2, r2, #4
	ldr r2, [r5, r2]
	add r0, r5, r0
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _0223A4D8 ; =0x00000BF4
	str r0, [r5, r1]
	add r0, r4, #0
	bl String_Delete
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	nop
_0223A4D0: .word 0x00000BDC
_0223A4D4: .word 0x00000E58
_0223A4D8: .word 0x00000BF4
	thumb_func_end ov72_0223A460


	thumb_func_start ov72_0223A4DC
ov72_0223A4DC: ; 0x0223A4DC
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #0
	add r4, r1, #0
	mvn r0, r0
	cmp r4, r0
	bne _0223A4EE
	mov r4, #0xb
_0223A4EE:
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0xbd
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	mov r3, #5
	bl BufferIntegerAsString
	ldr r0, _0223A51C ; =0x00000E18
	mov r1, #1
	add r0, r5, r0
	bl ClearFrameAndWindow2
	add r0, r5, #0
	add r1, r4, #0
	bl ov72_0223A460
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_0223A51C: .word 0x00000E18
	thumb_func_end ov72_0223A4DC


	thumb_func_start ov72_0223A520
ov72_0223A520: ; 0x0223A520
	push {r4, lr}
	ldr r3, _0223A580 ; =0x0000130C
	mov r4, #0
	strb r1, [r0, r3]
	add r1, r3, #1
	strb r2, [r0, r1]
	add r1, r3, #2
	strb r4, [r0, r1]
	add r1, r3, #3
	strb r4, [r0, r1]
	cmp r2, #0x64
	beq _0223A544
	add r1, r3, #4
	mov r2, #1
	strh r2, [r0, r1]
	add r3, #0x5c
	str r2, [r0, r3]
	b _0223A54C
_0223A544:
	add r1, r3, #4
	strh r4, [r0, r1]
	add r3, #0x5c
	str r4, [r0, r3]
_0223A54C:
	ldr r3, _0223A584 ; =0x00001312
	mov r1, #0
	strb r1, [r0, r3]
	sub r4, r1, #1
	add r2, r3, #2
	strb r4, [r0, r2]
	add r2, r3, #3
	strb r4, [r0, r2]
	add r2, r3, #4
	strb r4, [r0, r2]
	add r2, r3, #0
	add r2, #0x52
	strh r1, [r0, r2]
	mov r2, #1
	add r3, #0x54
	strh r2, [r0, r3]
	mov r2, #0xe
	lsl r2, r2, #8
	ldr r0, [r0, r2]
	cmp r0, #0
	beq _0223A57A
	bl ov72_022386F4
_0223A57A:
	mov r0, #1
	pop {r4, pc}
	nop
_0223A580: .word 0x0000130C
_0223A584: .word 0x00001312
	thumb_func_end ov72_0223A520


	thumb_func_start ov72_0223A588
ov72_0223A588: ; 0x0223A588
	push {r4, lr}
	ldr r1, _0223A5A8 ; =0x00001312
	add r4, r0, #0
	ldrb r1, [r4, r1]
	lsl r2, r1, #2
	ldr r1, _0223A5AC ; =ov72_0223B744
	ldr r1, [r1, r2]
	blx r1
	cmp r0, #1
	bne _0223A5A2
	ldr r0, _0223A5B0 ; =0x0000130E
	ldrsb r0, [r4, r0]
	pop {r4, pc}
_0223A5A2:
	mov r0, #0
	pop {r4, pc}
	nop
_0223A5A8: .word 0x00001312
_0223A5AC: .word ov72_0223B744
_0223A5B0: .word 0x0000130E
	thumb_func_end ov72_0223A588


	thumb_func_start ov72_0223A5B4
ov72_0223A5B4: ; 0x0223A5B4
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r0, #4
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r1, #0x43
	str r1, [sp, #8]
	mov r1, #0
	add r2, r1, #0
	add r3, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, _0223A5DC ; =0x00001312
	mov r1, #1
	strb r1, [r4, r0]
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_0223A5DC: .word 0x00001312
	thumb_func_end ov72_0223A5B4


	thumb_func_start ov72_0223A5E0
ov72_0223A5E0: ; 0x0223A5E0
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0223A65E
	add r0, r4, #0
	bl ov72_0223A680
	ldr r2, _0223A664 ; =0x00001310
	ldr r0, _0223A668 ; =0x00000E04
	ldrsh r1, [r4, r2]
	add r2, #0x58
	ldr r0, [r4, r0]
	ldr r2, [r4, r2]
	bl ov72_02238730
	add r0, r4, #0
	mov r1, #1
	bl ov72_02238B18
	add r0, r4, #0
	bl ov72_0223ACA8
	ldr r1, _0223A66C ; =0x00000BD4
	ldr r0, _0223A670 ; =0x00001328
	ldr r1, [r4, r1]
	add r0, r4, r0
	mov r2, #0x14
	bl ov72_0223AD20
	ldr r1, _0223A66C ; =0x00000BD4
	ldr r0, _0223A674 ; =0x00001338
	ldr r1, [r4, r1]
	add r0, r4, r0
	mov r2, #0x15
	bl ov72_0223AD20
	ldr r1, _0223A66C ; =0x00000BD4
	ldr r0, _0223A678 ; =0x00001348
	ldr r1, [r4, r1]
	add r0, r4, r0
	mov r2, #0x16
	bl ov72_0223AD20
	mov r0, #4
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #4
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r2, #0x43
	str r2, [sp, #8]
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	ldr r0, _0223A67C ; =0x00001312
	mov r1, #2
	strb r1, [r4, r0]
_0223A65E:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_0223A664: .word 0x00001310
_0223A668: .word 0x00000E04
_0223A66C: .word 0x00000BD4
_0223A670: .word 0x00001328
_0223A674: .word 0x00001338
_0223A678: .word 0x00001348
_0223A67C: .word 0x00001312
	thumb_func_end ov72_0223A5E0


	thumb_func_start ov72_0223A680
ov72_0223A680: ; 0x0223A680
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r0, _0223A6FC ; =0x0000130D
	ldrb r0, [r6, r0]
	cmp r0, #0x64
	bne _0223A696
	ldr r0, _0223A700 ; =0x00000DF4
	mov r1, #1
	ldr r0, [r6, r0]
	bl Sprite_SetDrawFlag
_0223A696:
	ldr r0, _0223A704 ; =0x00000DF8
	mov r1, #1
	ldr r0, [r6, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0223A708 ; =0x00000DFC
	mov r1, #1
	ldr r0, [r6, r0]
	bl Sprite_SetDrawFlag
	ldr r7, _0223A70C ; =0x00001368
	mov r4, #0
	add r5, r6, #0
_0223A6B0:
	ldr r0, _0223A700 ; =0x00000DF4
	ldr r2, [r6, r7]
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ov72_02238750
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _0223A6B0
	mov r0, #0xe
	lsl r0, r0, #8
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, _0223A710 ; =0x00000E04
	mov r1, #1
	ldr r0, [r6, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0223A714 ; =0x00000E08
	mov r1, #1
	ldr r0, [r6, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0223A718 ; =0x00000E0C
	mov r1, #1
	ldr r0, [r6, r0]
	bl Sprite_SetDrawFlag
	mov r0, #0xe1
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0223A6FC: .word 0x0000130D
_0223A700: .word 0x00000DF4
_0223A704: .word 0x00000DF8
_0223A708: .word 0x00000DFC
_0223A70C: .word 0x00001368
_0223A710: .word 0x00000E04
_0223A714: .word 0x00000E08
_0223A718: .word 0x00000E0C
	thumb_func_end ov72_0223A680

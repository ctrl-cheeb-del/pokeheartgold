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

	thumb_func_start ov72_0223ACA8
ov72_0223ACA8: ; 0x0223ACA8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r1, _0223AD14 ; =0x00001328
	ldr r5, _0223AD18 ; =ov72_0223B46C
	str r0, [sp, #0x14]
	mov r7, #0
	mov r4, #0x1f
	add r6, r0, r1
_0223ACB8:
	mov r0, #0x15
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ldr r3, [r5]
	ldr r0, [r0, #4]
	lsl r3, r3, #0x18
	add r1, r6, #0
	mov r2, #4
	lsr r3, r3, #0x18
	bl AddWindowParameterized
	add r7, r7, #1
	add r4, #0x40
	add r5, r5, #4
	add r6, #0x10
	cmp r7, #3
	blt _0223ACB8
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r2, #4
	str r2, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x4f
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ldr r3, _0223AD1C ; =0x00001318
	ldr r1, [sp, #0x14]
	ldr r0, [r0, #4]
	add r1, r1, r3
	mov r3, #2
	bl AddWindowParameterized
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0223AD14: .word 0x00001328
_0223AD18: .word ov72_0223B46C
_0223AD1C: .word 0x00001318
	thumb_func_end ov72_0223ACA8


	thumb_func_start ov72_0223AD20
ov72_0223AD20: ; 0x0223AD20
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r0, r1, #0
	add r1, r2, #0
	bl NewString_ReadMsgData
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r3, #0
	str r3, [sp]
	ldr r0, _0223AD60 ; =0x000F0200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #4
	add r2, r4, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl CopyWindowToVram
	add r0, r4, #0
	bl String_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0223AD60: .word 0x000F0200
	thumb_func_end ov72_0223AD20


	thumb_func_start ov72_0223AD64
ov72_0223AD64: ; 0x0223AD64
	push {r4, r5, r6, lr}
	add r6, r0, #0
	ldr r0, _0223AD8C ; =0x00001328
	mov r4, #0
	add r5, r6, r0
_0223AD6E:
	add r0, r5, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	bl RemoveWindow
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #3
	blt _0223AD6E
	ldr r0, _0223AD90 ; =0x00001318
	add r0, r6, r0
	bl RemoveWindow
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0223AD8C: .word 0x00001328
_0223AD90: .word 0x00001318
	thumb_func_end ov72_0223AD64


	thumb_func_start ov72_0223AD94
ov72_0223AD94: ; 0x0223AD94
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl ov72_0223AD64
	ldr r0, _0223AE08 ; =0x00000DF4
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0223AE0C ; =0x00000DF8
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0223AE10 ; =0x00000DFC
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	mov r0, #0xe
	lsl r0, r0, #8
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0223AE14 ; =0x00000E04
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0223AE18 ; =0x00000E08
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0223AE1C ; =0x00000E0C
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	mov r0, #0xe1
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r4, #0
	ldr r6, _0223AE08 ; =0x00000DF4
	add r7, r4, #0
_0223ADF6:
	ldr r0, [r5, r6]
	add r1, r7, #0
	bl Sprite_SetAnimCtrlSeq
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _0223ADF6
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0223AE08: .word 0x00000DF4
_0223AE0C: .word 0x00000DF8
_0223AE10: .word 0x00000DFC
_0223AE14: .word 0x00000E04
_0223AE18: .word 0x00000E08
_0223AE1C: .word 0x00000E0C
	thumb_func_end ov72_0223AD94


	thumb_func_start ov72_0223AE20
ov72_0223AE20: ; 0x0223AE20
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, _0223AE64 ; =0x00001358
	add r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _0223AE42
	ldrb r0, [r4, #2]
	lsl r0, r0, #2
	add r2, r5, r0
	ldr r0, _0223AE68 ; =0x00000DF4
	ldr r0, [r2, r0]
	bl Sprite_SetAnimCtrlSeq
	add sp, #0xc
	pop {r4, r5, pc}
_0223AE42:
	ldrb r0, [r4, #4]
	str r0, [sp]
	ldrb r0, [r4, #5]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrb r1, [r4, #2]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #7]
	ldr r0, [r5, #4]
	bl BgTilemapRectChangePalette
	ldrb r1, [r4, #2]
	ldr r0, [r5, #4]
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_0223AE64: .word 0x00001358
_0223AE68: .word 0x00000DF4
	thumb_func_end ov72_0223AE20


	thumb_func_start ov72_0223AE6C
ov72_0223AE6C: ; 0x0223AE6C
	push {r4, lr}
	ldr r1, _0223AECC ; =0x00001358
	add r4, r0, r1
	ldrb r1, [r4, #1]
	cmp r1, #0
	beq _0223AE82
	cmp r1, #1
	beq _0223AE94
	cmp r1, #2
	beq _0223AEB6
	b _0223AEC6
_0223AE82:
	ldrh r1, [r4, #8]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov72_0223AE20
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
	b _0223AEC6
_0223AE94:
	ldrb r1, [r4, #3]
	add r1, r1, #1
	strb r1, [r4, #3]
	ldrb r1, [r4, #3]
	cmp r1, #4
	bne _0223AEC6
	ldrh r1, [r4, #0xa]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov72_0223AE20
	mov r0, #0
	strb r0, [r4, #3]
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
	b _0223AEC6
_0223AEB6:
	ldrb r0, [r4, #3]
	add r0, r0, #1
	strb r0, [r4, #3]
	ldrb r0, [r4, #3]
	cmp r0, #2
	bne _0223AEC6
	mov r0, #0
	pop {r4, pc}
_0223AEC6:
	mov r0, #1
	pop {r4, pc}
	nop
_0223AECC: .word 0x00001358
	thumb_func_end ov72_0223AE6C


	thumb_func_start ov72_0223AED0
ov72_0223AED0: ; 0x0223AED0
	push {r4, r5, r6, r7}
	ldr r4, _0223AF18 ; =0x00001358
	mov r5, #1
	strb r5, [r0, r4]
	mov r5, #0
	add r6, r4, #3
	strb r5, [r0, r6]
	add r6, r4, #1
	strb r5, [r0, r6]
	mov r7, #5
	add r6, r4, #2
	strb r7, [r0, r6]
	add r7, r4, #0
	add r7, #8
	mov r6, #1
	strh r6, [r0, r7]
	add r6, r4, #0
	add r6, #0xa
	strh r5, [r0, r6]
	add r5, r4, #6
	strb r1, [r0, r5]
	add r1, r4, #7
	strb r2, [r0, r1]
	mov r2, #6
	add r1, r4, #4
	strb r2, [r0, r1]
	add r1, r4, #5
	strb r2, [r0, r1]
	add r1, r4, #0
	sub r1, #0x45
	strb r3, [r0, r1]
	mov r1, #0xa
	sub r4, #0x46
	strb r1, [r0, r4]
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
_0223AF18: .word 0x00001358
	thumb_func_end ov72_0223AED0


	thumb_func_start ov72_0223AF1C
ov72_0223AF1C: ; 0x0223AF1C
	push {r4, lr}
	add r4, r0, #0
	add r1, r4, #0
	mov r2, #0
	add r1, #0x2d
	strb r2, [r1]
	add r1, r4, #0
	add r1, #0x2c
	ldrb r2, [r1]
	add r1, r4, #0
	add r1, #0x33
	strb r2, [r1]
	bl ov72_0223B0C4
	add r0, r4, #0
	bl ov72_0223B1C8
	add r0, r4, #0
	bl ov72_0223B2E4
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov72_0223AF1C


	thumb_func_start ov72_0223AF48
ov72_0223AF48: ; 0x0223AF48
	push {r4, lr}
	add r4, r0, #0
	add r1, r4, #0
	add r1, #0x2d
	ldrb r1, [r1]
	lsl r2, r1, #2
	ldr r1, _0223AF6C ; =ov72_0223B7FC
	ldr r1, [r1, r2]
	blx r1
	cmp r0, #1
	bne _0223AF66
	add r4, #0x33
	ldrb r0, [r4]
	add r0, r0, #1
	pop {r4, pc}
_0223AF66:
	mov r0, #0
	pop {r4, pc}
	nop
_0223AF6C: .word ov72_0223B7FC
	thumb_func_end ov72_0223AF48

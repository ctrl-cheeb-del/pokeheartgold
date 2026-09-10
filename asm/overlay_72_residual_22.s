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

	thumb_func_start ov72_0223A014
ov72_0223A014: ; 0x0223A014
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	bl sub_0203A914
	bl sub_0203946C
	mov r0, #8
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x43
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #0
	str r0, [r4, #0x1c]
	mov r0, #4
	add sp, #0xc
	pop {r3, r4, pc}
	thumb_func_end ov72_0223A014


	thumb_func_start ov72_0223A044
ov72_0223A044: ; 0x0223A044
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0223A068 ; =0x00001308
	ldr r0, [r4, r0]
	bl ov72_02238668
	cmp r0, #0
	beq _0223A062
	cmp r0, #2
	bne _0223A05E
	mov r0, #0
	str r0, [r4, #0x1c]
	b _0223A062
_0223A05E:
	mov r0, #0x29
	str r0, [r4, #0x1c]
_0223A062:
	mov r0, #3
	pop {r4, pc}
	nop
_0223A068: .word 0x00001308
	thumb_func_end ov72_0223A044


	thumb_func_start ov72_0223A06C
ov72_0223A06C: ; 0x0223A06C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0223A0D4 ; =0x00000F5C
	mov r4, #0
	ldr r0, [r5, r0]
	add r0, r0, #7
	cmp r0, #9
	bhi _0223A0AE
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223A088: ; jump table
	.short _0223A0A8 - _0223A088 - 2 ; case 0
	.short _0223A09C - _0223A088 - 2 ; case 1
	.short _0223A0AE - _0223A088 - 2 ; case 2
	.short _0223A0A8 - _0223A088 - 2 ; case 3
	.short _0223A0AC - _0223A088 - 2 ; case 4
	.short _0223A09C - _0223A088 - 2 ; case 5
	.short _0223A0A4 - _0223A088 - 2 ; case 6
	.short _0223A0AE - _0223A088 - 2 ; case 7
	.short _0223A0A0 - _0223A088 - 2 ; case 8
	.short _0223A0A4 - _0223A088 - 2 ; case 9
_0223A09C:
	mov r4, #0xf
	b _0223A0AE
_0223A0A0:
	mov r4, #0xd
	b _0223A0AE
_0223A0A4:
	mov r4, #0xe
	b _0223A0AE
_0223A0A8:
	mov r4, #0x10
	b _0223A0AE
_0223A0AC:
	mov r4, #0x11
_0223A0AE:
	add r0, r5, #0
	bl ov72_0223A444
	ldr r0, _0223A0D8 ; =0x00000F0F
	ldr r1, _0223A0DC ; =0x00000BD4
	str r0, [sp]
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r2, r4, #0
	mov r3, #1
	bl ov72_0223A350
	add r0, r5, #0
	mov r1, #0x2f
	mov r2, #0x36
	bl ov72_02238680
	mov r0, #3
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0223A0D4: .word 0x00000F5C
_0223A0D8: .word 0x00000F0F
_0223A0DC: .word 0x00000BD4
	thumb_func_end ov72_0223A06C


	thumb_func_start ov72_0223A0E0
ov72_0223A0E0: ; 0x0223A0E0
	push {r3, r4, lr}
	sub sp, #4
	mov r1, #0xfd
	add r4, r0, #0
	lsl r1, r1, #4
	ldrsh r2, [r4, r1]
	cmp r2, #3
	bhi _0223A17C
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0223A0FC: ; jump table
	.short _0223A104 - _0223A0FC - 2 ; case 0
	.short _0223A120 - _0223A0FC - 2 ; case 1
	.short _0223A144 - _0223A0FC - 2 ; case 2
	.short _0223A160 - _0223A0FC - 2 ; case 3
_0223A104:
	sub r1, #0xc1
	str r1, [sp]
	ldr r1, _0223A1A0 ; =0x00000BD4
	mov r2, #0x12
	ldr r1, [r4, r1]
	mov r3, #1
	bl ov72_0223A350
	mov r0, #0xfd
	lsl r0, r0, #4
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	b _0223A198
_0223A120:
	ldr r0, _0223A1A4 ; =0x00000BF4
	ldr r0, [r4, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _0223A198
	bl sub_0203946C
	bl ov00_021EC8D8
	mov r0, #0xfd
	lsl r0, r0, #4
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	b _0223A198
_0223A144:
	sub r1, #0xc1
	str r1, [sp]
	ldr r1, _0223A1A0 ; =0x00000BD4
	mov r2, #0x13
	ldr r1, [r4, r1]
	mov r3, #1
	bl ov72_0223A350
	mov r0, #0xfd
	lsl r0, r0, #4
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	b _0223A198
_0223A160:
	ldr r0, _0223A1A4 ; =0x00000BF4
	ldr r0, [r4, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _0223A198
	mov r0, #0xfd
	lsl r0, r0, #4
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	b _0223A198
_0223A17C:
	ldr r0, _0223A1A8 ; =0x00000FD2
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	ldrsh r0, [r4, r0]
	cmp r0, #0x1e
	ble _0223A198
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	bl ov72_022387D0
	mov r0, #0x2e
	str r0, [r4, #0x1c]
_0223A198:
	mov r0, #3
	add sp, #4
	pop {r3, r4, pc}
	nop
_0223A1A0: .word 0x00000BD4
_0223A1A4: .word 0x00000BF4
_0223A1A8: .word 0x00000FD2
	thumb_func_end ov72_0223A0E0


	thumb_func_start ov72_0223A1AC
ov72_0223A1AC: ; 0x0223A1AC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0223A1C8 ; =0x00000BF4
	ldr r0, [r4, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _0223A1C4
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x1c]
_0223A1C4:
	mov r0, #3
	pop {r4, pc}
	.balign 4, 0
_0223A1C8: .word 0x00000BF4
	thumb_func_end ov72_0223A1AC


	thumb_func_start ov72_0223A1CC
ov72_0223A1CC: ; 0x0223A1CC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0223A1FC ; =0x00000BF4
	ldr r0, [r4, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _0223A1F8
	mov r0, #0xf6
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	cmp r0, #0x1e
	ble _0223A1EE
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x1c]
_0223A1EE:
	mov r0, #0xf6
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	add r1, r1, #1
	str r1, [r4, r0]
_0223A1F8:
	mov r0, #3
	pop {r4, pc}
	.balign 4, 0
_0223A1FC: .word 0x00000BF4
	thumb_func_end ov72_0223A1CC


	thumb_func_start ov72_0223A200
ov72_0223A200: ; 0x0223A200
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0223A274 ; =0x00000BF4
	ldr r0, [r4, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _0223A26E
	ldr r0, _0223A278 ; =0x00000E14
	ldr r1, [r4, r0]
	ldr r0, _0223A27C ; =0x00001370
	str r1, [r4, r0]
	ldr r2, [r4, #4]
	sub r1, r0, #4
	str r2, [r4, r1]
	add r1, r0, #0
	mov r2, #0x43
	add r1, #0x24
	str r2, [r4, r1]
	add r1, r0, #0
	mov r2, #0
	add r1, #0x28
	strb r2, [r4, r1]
	add r1, r0, #0
	mov r2, #0xa
	add r1, #0x2a
	strb r2, [r4, r1]
	add r1, r0, #0
	mov r2, #6
	add r1, #0x2b
	strb r2, [r4, r1]
	add r1, r0, #0
	mov r2, #4
	add r1, #0x2e
	strb r2, [r4, r1]
	add r1, r0, #0
	mov r2, #0xb
	add r1, #0x2c
	strb r2, [r4, r1]
	add r1, r0, #0
	mov r2, #1
	add r1, #0x2d
	strb r2, [r4, r1]
	add r1, r0, #0
	sub r0, r0, #4
	add r2, #0xff
	add r1, #0x30
	add r0, r4, r0
	str r2, [r4, r1]
	bl ov72_0223AF1C
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x1c]
_0223A26E:
	mov r0, #3
	pop {r4, pc}
	nop
_0223A274: .word 0x00000BF4
_0223A278: .word 0x00000E14
_0223A27C: .word 0x00001370
	thumb_func_end ov72_0223A200


	thumb_func_start ov72_0223A280
ov72_0223A280: ; 0x0223A280
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r0, r1, #0
	add r1, r2, #0
	add r4, r3, #0
	bl NewString_ReadMsgData
	mov r1, #0xbd
	add r6, r0, #0
	lsl r1, r1, #4
	ldr r0, [r5, r1]
	add r1, #0x10
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl StringExpandPlaceholders
	ldr r0, _0223A2E0 ; =0x00000E18
	mov r1, #0xf
	add r0, r5, r0
	bl FillWindowPixelBuffer
	ldr r0, _0223A2E0 ; =0x00000E18
	mov r1, #0
	add r0, r5, r0
	mov r2, #1
	mov r3, #0xe
	bl DrawFrameAndWindow2
	mov r3, #0
	str r3, [sp]
	str r4, [sp, #4]
	mov r2, #0xbe
	ldr r0, _0223A2E0 ; =0x00000E18
	str r3, [sp, #8]
	lsl r2, r2, #4
	ldr r2, [r5, r2]
	add r0, r5, r0
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _0223A2E4 ; =0x00000BF4
	str r0, [r5, r1]
	add r0, r6, #0
	bl String_Delete
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0223A2E0: .word 0x00000E18
_0223A2E4: .word 0x00000BF4
	thumb_func_end ov72_0223A280


	thumb_func_start ov72_0223A2E8
ov72_0223A2E8: ; 0x0223A2E8
	push {r4, lr}
	ldr r1, _0223A310 ; =0x00000F54
	add r4, r0, #0
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	neg r0, r0
	bl ov00_021E6A70
	ldr r2, _0223A310 ; =0x00000F54
	add r1, r0, #0
	ldr r2, [r4, r2]
	add r0, r4, #0
	neg r2, r2
	bl ov72_0223A4DC
	mov r0, #0x38
	str r0, [r4, #0x1c]
	mov r0, #3
	pop {r4, pc}
	.balign 4, 0
_0223A310: .word 0x00000F54
	thumb_func_end ov72_0223A2E8


	thumb_func_start ov72_0223A314
ov72_0223A314: ; 0x0223A314
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0223A344 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	bne _0223A330
	mov r0, #2
	tst r0, r1
	bne _0223A330
	ldr r0, _0223A348 ; =gSystem + 0x40
	ldrh r0, [r0, #0x24]
	cmp r0, #0
	beq _0223A33E
_0223A330:
	ldr r0, _0223A34C ; =0x00000E58
	mov r1, #0
	add r0, r4, r0
	bl sub_0200E5D4
	mov r0, #0
	str r0, [r4, #0x1c]
_0223A33E:
	mov r0, #3
	pop {r4, pc}
	nop
_0223A344: .word gSystem
_0223A348: .word gSystem + 0x40
_0223A34C: .word 0x00000E58
	thumb_func_end ov72_0223A314


	thumb_func_start ov72_0223A350
ov72_0223A350: ; 0x0223A350
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r0, r1, #0
	add r1, r2, #0
	mov r2, #0xbe
	lsl r2, r2, #4
	ldr r2, [r5, r2]
	add r4, r3, #0
	bl ReadMsgDataIntoString
	ldr r0, _0223A3A0 ; =0x00000E18
	mov r1, #0xf
	add r0, r5, r0
	bl FillWindowPixelBuffer
	ldr r0, _0223A3A0 ; =0x00000E18
	mov r1, #0
	add r0, r5, r0
	mov r2, #1
	mov r3, #0xe
	bl DrawFrameAndWindow2
	mov r3, #0
	str r3, [sp]
	str r4, [sp, #4]
	mov r2, #0xbe
	ldr r0, _0223A3A0 ; =0x00000E18
	str r3, [sp, #8]
	lsl r2, r2, #4
	ldr r2, [r5, r2]
	add r0, r5, r0
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _0223A3A4 ; =0x00000BF4
	str r0, [r5, r1]
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_0223A3A0: .word 0x00000E18
_0223A3A4: .word 0x00000BF4
	thumb_func_end ov72_0223A350


	thumb_func_start ov72_0223A3A8
ov72_0223A3A8: ; 0x0223A3A8
	push {r4, lr}
	add r4, r0, #0
	cmp r3, #1
	beq _0223A3B6
	cmp r3, #2
	beq _0223A3CC
	b _0223A3DA
_0223A3B6:
	ldr r0, [sp, #0xc]
	mov r2, #0
	bl FontID_String_GetWidth
	ldrb r1, [r4, #7]
	lsl r1, r1, #3
	sub r1, r1, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r2, r0, #1
	b _0223A3DA
_0223A3CC:
	ldr r0, [sp, #0xc]
	mov r2, #0
	bl FontID_String_GetWidth
	ldrb r1, [r4, #7]
	lsl r1, r1, #3
	sub r2, r1, r0
_0223A3DA:
	add r0, r2, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov72_0223A3A8


	thumb_func_start ov72_0223A3E0
ov72_0223A3E0: ; 0x0223A3E0
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r4, r3, #0
	ldr r3, [sp, #0x24]
	add r5, r0, #0
	str r3, [sp]
	mov r3, #1
	str r3, [sp, #4]
	ldr r3, [sp, #0x20]
	add r6, r1, #0
	bl ov72_0223A3A8
	add r3, r0, #0
	str r4, [sp]
	mov r1, #0
	ldr r0, [sp, #0x24]
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r5, #0
	mov r1, #1
	add r2, r6, #0
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x10
	pop {r4, r5, r6, pc}
	thumb_func_end ov72_0223A3E0

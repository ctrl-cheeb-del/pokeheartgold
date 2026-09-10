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

	thumb_func_start ov72_0223AF7C
ov72_0223AF7C: ; 0x0223AF7C
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, _0223B078 ; =ov72_0223B4C8
	bl TouchscreenHitbox_FindRectAtTouchNew
	add r5, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r5, r0
	beq _0223AFE6
	ldr r0, _0223B07C ; =0x000005DC
	bl PlaySE
	cmp r5, #0
	bne _0223AFBE
	add r0, r4, #0
	mov r1, #0
	add r0, #0x33
	strb r1, [r0]
	add r1, r4, #0
	add r1, #0x33
	ldrb r1, [r1]
	add r0, r4, #0
	bl ov72_0223B2FC
	ldr r0, [r4, #4]
	mov r1, #3
	bl Sprite_SetAnimCtrlSeq
	mov r0, #3
	add r4, #0x2d
	strb r0, [r4]
	b _0223B074
_0223AFBE:
	cmp r5, #1
	bne _0223B074
	add r0, r4, #0
	mov r1, #1
	add r0, #0x33
	strb r1, [r0]
	add r1, r4, #0
	add r1, #0x33
	ldrb r1, [r1]
	add r0, r4, #0
	bl ov72_0223B2FC
	ldr r0, [r4, #4]
	mov r1, #3
	bl Sprite_SetAnimCtrlSeq
	mov r0, #3
	add r4, #0x2d
	strb r0, [r4]
	b _0223B074
_0223AFE6:
	ldr r0, _0223B080 ; =gSystem
	mov r1, #0x40
	ldr r0, [r0, #0x48]
	tst r1, r0
	beq _0223B00A
	add r0, r4, #0
	mov r1, #0
	add r0, #0x33
	strb r1, [r0]
	add r0, r4, #0
	add r4, #0x33
	ldrb r1, [r4]
	bl ov72_0223B2FC
	ldr r0, _0223B07C ; =0x000005DC
	bl PlaySE
	b _0223B074
_0223B00A:
	mov r1, #0x80
	tst r1, r0
	beq _0223B02A
	add r0, r4, #0
	mov r1, #1
	add r0, #0x33
	strb r1, [r0]
	add r0, r4, #0
	add r4, #0x33
	ldrb r1, [r4]
	bl ov72_0223B2FC
	ldr r0, _0223B07C ; =0x000005DC
	bl PlaySE
	b _0223B074
_0223B02A:
	mov r2, #1
	add r1, r0, #0
	tst r1, r2
	beq _0223B048
	ldr r0, [r4, #4]
	mov r1, #3
	bl Sprite_SetAnimCtrlSeq
	mov r0, #3
	add r4, #0x2d
	strb r0, [r4]
	ldr r0, _0223B07C ; =0x000005DC
	bl PlaySE
	b _0223B074
_0223B048:
	mov r1, #2
	tst r0, r1
	beq _0223B074
	add r0, r4, #0
	add r0, #0x33
	add r1, r4, #0
	strb r2, [r0]
	add r1, #0x33
	ldrb r1, [r1]
	add r0, r4, #0
	bl ov72_0223B2FC
	add r0, r4, #0
	mov r1, #3
	add r0, #0x2d
	strb r1, [r0]
	ldr r0, [r4, #4]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _0223B07C ; =0x000005DC
	bl PlaySE
_0223B074:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0223B078: .word ov72_0223B4C8
_0223B07C: .word 0x000005DC
_0223B080: .word gSystem
	thumb_func_end ov72_0223AF7C

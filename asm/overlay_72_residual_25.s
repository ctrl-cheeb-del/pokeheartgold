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

	thumb_func_start ov72_0223A738
ov72_0223A738: ; 0x0223A738
	push {r3, lr}
	ldr r1, _0223A754 ; =0x0000130D
	ldrb r0, [r0, r1]
	cmp r0, #0x64
	bne _0223A74A
	ldr r0, _0223A758 ; =ov72_0223B774
	bl TouchscreenHitbox_FindRectAtTouchNew
	pop {r3, pc}
_0223A74A:
	ldr r0, _0223A75C ; =ov72_0223B7B8
	bl TouchscreenHitbox_FindRectAtTouchNew
	pop {r3, pc}
	nop
_0223A754: .word 0x0000130D
_0223A758: .word ov72_0223B774
_0223A75C: .word ov72_0223B7B8
	thumb_func_end ov72_0223A738


	thumb_func_start ov72_0223A760
ov72_0223A760: ; 0x0223A760
	push {r3, r4}
	ldr r3, _0223A7E0 ; =ov72_0223B48C
	lsl r4, r0, #2
	add r3, r3, r4
	ldrb r1, [r1, r3]
	cmp r1, #0xd
	bne _0223A776
	ldrh r1, [r2]
	ldr r0, _0223A7E4 ; =ov72_0223B464
	ldrb r1, [r0, r1]
	b _0223A7D8
_0223A776:
	cmp r1, #0xe
	bne _0223A782
	ldrh r1, [r2]
	ldr r0, _0223A7E8 ; =ov72_0223B466
	ldrb r1, [r0, r1]
	b _0223A7D8
_0223A782:
	cmp r1, #0xf
	bne _0223A78E
	ldrh r1, [r2, #2]
	ldr r0, _0223A7EC ; =ov72_0223B468
	ldrb r1, [r0, r1]
	b _0223A7D8
_0223A78E:
	cmp r1, #0x10
	bne _0223A79A
	ldrh r1, [r2, #2]
	ldr r0, _0223A7F0 ; =ov72_0223B46A
	ldrb r1, [r0, r1]
	b _0223A7D8
_0223A79A:
	cmp r1, #0xa
	bne _0223A7BA
	cmp r0, #5
	beq _0223A7A6
	cmp r0, #0
	bne _0223A7AC
_0223A7A6:
	mov r0, #0
	strh r0, [r2]
	b _0223A7D8
_0223A7AC:
	cmp r0, #1
	beq _0223A7B4
	cmp r0, #6
	bne _0223A7D8
_0223A7B4:
	mov r0, #1
	strh r0, [r2]
	b _0223A7D8
_0223A7BA:
	cmp r1, #0xc
	bne _0223A7D8
	cmp r0, #3
	beq _0223A7C6
	cmp r0, #8
	bne _0223A7CC
_0223A7C6:
	mov r0, #0
	strh r0, [r2, #2]
	b _0223A7D8
_0223A7CC:
	cmp r0, #4
	beq _0223A7D4
	cmp r0, #9
	bne _0223A7D8
_0223A7D4:
	mov r0, #1
	strh r0, [r2, #2]
_0223A7D8:
	add r0, r1, #0
	pop {r3, r4}
	bx lr
	nop
_0223A7E0: .word ov72_0223B48C
_0223A7E4: .word ov72_0223B464
_0223A7E8: .word ov72_0223B466
_0223A7EC: .word ov72_0223B468
_0223A7F0: .word ov72_0223B46A
	thumb_func_end ov72_0223A760


	thumb_func_start ov72_0223A7F4
ov72_0223A7F4: ; 0x0223A7F4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r7, r0, #0
	add r6, r1, #0
	mov r0, #0x64
	mov r4, #3
	mov r1, #0
	add r2, sp, #0x18
	mov r3, #8
_0223A806:
	add r5, r7, r1
	ldrsb r5, [r5, r3]
	add r1, r1, #1
	cmp r1, #3
	stmia r2!, {r5}
	blt _0223A806
	mov r1, #0
	mvn r1, r1
	cmp r6, r1
	beq _0223A824
	mov r1, #4
	ldrsh r1, [r7, r1]
	lsl r2, r1, #2
	add r1, sp, #0x18
	str r6, [r1, r2]
_0223A824:
	mov r1, #0
	str r1, [sp, #4]
	str r1, [sp, #8]
	add r5, r1, #0
	add r6, sp, #0x18
_0223A82E:
	add r2, r7, r5
	mov r1, #8
	ldrsb r1, [r2, r1]
	cmp r1, #0
	bne _0223A83E
	ldr r1, [sp, #8]
	cmp r1, #0
	beq _0223A844
_0223A83E:
	ldr r2, [r6]
	cmp r2, #0
	bge _0223A84E
_0223A844:
	mov r1, #0xa
	bl _s32_div_f
	sub r4, r4, #1
	b _0223A860
_0223A84E:
	mov r1, #1
	ldr r3, [sp, #4]
	str r1, [sp, #8]
	ldr r1, [sp, #4]
	add r3, r3, #1
	str r3, [sp, #4]
	lsl r1, r1, #2
	add r3, sp, #0xc
	str r2, [r3, r1]
_0223A860:
	add r5, r5, #1
	add r6, r6, #4
	cmp r5, #3
	blt _0223A82E
	mov r6, #0
	str r6, [sp]
	cmp r4, #0
	ble _0223A88A
	add r5, sp, #0xc
_0223A872:
	ldr r1, [r5]
	mul r1, r0
	add r6, r6, r1
	mov r1, #0xa
	bl _s32_div_f
	ldr r1, [sp]
	add r5, r5, #4
	add r1, r1, #1
	str r1, [sp]
	cmp r1, r4
	blt _0223A872
_0223A88A:
	ldrb r0, [r7, #1]
	cmp r6, r0
	ble _0223A898
	mov r0, #0
	add sp, #0x24
	mvn r0, r0
	pop {r4, r5, r6, r7, pc}
_0223A898:
	add r0, r6, #0
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov72_0223A7F4


	thumb_func_start ov72_0223A8A0
ov72_0223A8A0: ; 0x0223A8A0
	ldrb r1, [r0, #1]
	cmp r1, #0x64
	beq _0223A8BA
	mov r1, #9
	ldrsb r1, [r0, r1]
	cmp r1, #0
	blt _0223A8D6
	mov r1, #0xa
	ldrsb r0, [r0, r1]
	cmp r0, #0
	blt _0223A8D6
	mov r0, #1
	bx lr
_0223A8BA:
	mov r1, #8
	ldrsb r1, [r0, r1]
	cmp r1, #0
	blt _0223A8D6
	mov r1, #9
	ldrsb r1, [r0, r1]
	cmp r1, #0
	blt _0223A8D6
	mov r1, #0xa
	ldrsb r0, [r0, r1]
	cmp r0, #0
	blt _0223A8D6
	mov r0, #1
	bx lr
_0223A8D6:
	mov r0, #0
	bx lr
	.balign 4, 0
	thumb_func_end ov72_0223A8A0

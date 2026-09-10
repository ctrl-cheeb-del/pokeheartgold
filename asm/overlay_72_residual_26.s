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

	thumb_func_start ov72_0223A8F0
ov72_0223A8F0: ; 0x0223A8F0
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r0, #0
	cmp r5, #0xf
	bls _0223A8FC
	b _0223AA6A
_0223A8FC:
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223A908: ; jump table
	.short _0223AA6A - _0223A908 - 2 ; case 0
	.short _0223AA6A - _0223A908 - 2 ; case 1
	.short _0223AA6A - _0223A908 - 2 ; case 2
	.short _0223A928 - _0223A908 - 2 ; case 3
	.short _0223A928 - _0223A908 - 2 ; case 4
	.short _0223A928 - _0223A908 - 2 ; case 5
	.short _0223A928 - _0223A908 - 2 ; case 6
	.short _0223A928 - _0223A908 - 2 ; case 7
	.short _0223A928 - _0223A908 - 2 ; case 8
	.short _0223A928 - _0223A908 - 2 ; case 9
	.short _0223A928 - _0223A908 - 2 ; case 10
	.short _0223A928 - _0223A908 - 2 ; case 11
	.short _0223A928 - _0223A908 - 2 ; case 12
	.short _0223A9A2 - _0223A908 - 2 ; case 13
	.short _0223A9F4 - _0223A908 - 2 ; case 14
	.short _0223AA38 - _0223A908 - 2 ; case 15
_0223A928:
	ldr r0, _0223AA6C ; =0x0000130C
	sub r1, r5, #3
	add r0, r4, r0
	bl ov72_0223A7F4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0223A99A
	ldr r1, _0223AA70 ; =0x00001310
	sub r3, r5, #3
	ldrsh r0, [r4, r1]
	add r2, r4, r0
	add r0, r1, #4
	strb r3, [r2, r0]
	ldrsh r0, [r4, r1]
	cmp r0, #2
	bge _0223A950
	add r0, r0, #1
	strh r0, [r4, r1]
_0223A950:
	ldr r2, _0223AA70 ; =0x00001310
	ldr r0, _0223AA74 ; =0x00000E04
	ldrsh r1, [r4, r2]
	add r2, #0x58
	ldr r0, [r4, r0]
	ldr r2, [r4, r2]
	bl ov72_02238730
	ldr r0, _0223AA78 ; =0x0000130F
	sub r1, r5, #3
	strb r1, [r4, r0]
	sub r0, r0, #3
	add r0, r4, r0
	bl ov72_0223A8DC
	ldr r1, _0223AA78 ; =0x0000130F
	strb r0, [r4, r1]
	mov r0, #0xe
	lsl r0, r0, #8
	ldrb r1, [r4, r1]
	ldr r0, [r4, r0]
	bl ov72_022386F4
	ldr r0, _0223AA7C ; =0x000005DC
	bl PlaySE
	sub r0, r5, #3
	lsl r3, r0, #1
	ldr r1, _0223AA80 ; =ov72_0223B478
	ldr r2, _0223AA84 ; =ov72_0223B479
	ldrb r1, [r1, r3]
	ldrb r2, [r2, r3]
	add r0, r4, #0
	mov r3, #3
	bl ov72_0223AED0
	pop {r3, r4, r5, pc}
_0223A99A:
	ldr r0, _0223AA88 ; =0x000005F2
	bl PlaySE
	pop {r3, r4, r5, pc}
_0223A9A2:
	ldr r1, _0223AA70 ; =0x00001310
	mov r3, #0
	ldrsh r0, [r4, r1]
	mvn r3, r3
	add r2, r4, r0
	add r0, r1, #4
	strb r3, [r2, r0]
	ldrsh r0, [r4, r1]
	sub r0, r0, #1
	strh r0, [r4, r1]
	sub r0, r1, #3
	ldrb r0, [r4, r0]
	cmp r0, #0x64
	ldrsh r0, [r4, r1]
	bne _0223A9CA
	cmp r0, #0
	bge _0223A9D2
	mov r0, #0
	strh r0, [r4, r1]
	b _0223A9D2
_0223A9CA:
	cmp r0, #1
	bge _0223A9D2
	mov r0, #1
	strh r0, [r4, r1]
_0223A9D2:
	ldr r0, _0223AA7C ; =0x000005DC
	bl PlaySE
	ldr r2, _0223AA70 ; =0x00001310
	ldr r0, _0223AA74 ; =0x00000E04
	ldrsh r1, [r4, r2]
	add r2, #0x58
	ldr r0, [r4, r0]
	ldr r2, [r4, r2]
	bl ov72_02238730
	ldr r0, _0223AA8C ; =0x00000E08
	mov r1, #5
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	pop {r3, r4, r5, pc}
_0223A9F4:
	ldr r1, _0223AA78 ; =0x0000130F
	sub r0, r5, #3
	strb r0, [r4, r1]
	mov r0, #0xe
	lsl r0, r0, #8
	ldrb r1, [r4, r1]
	ldr r0, [r4, r0]
	bl ov72_022386F4
	ldr r0, _0223AA6C ; =0x0000130C
	mov r1, #0
	add r0, r4, r0
	mvn r1, r1
	bl ov72_0223A7F4
	ldr r1, _0223AA90 ; =0x0000130E
	strb r0, [r4, r1]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _0223AA20
	mov r0, #1
	strb r0, [r4, r1]
_0223AA20:
	ldr r0, _0223AA94 ; =0x00001312
	mov r1, #7
	strb r1, [r4, r0]
	ldr r0, _0223AA7C ; =0x000005DC
	bl PlaySE
	ldr r0, _0223AA98 ; =0x00000E0C
	mov r1, #5
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	pop {r3, r4, r5, pc}
_0223AA38:
	ldr r1, _0223AA78 ; =0x0000130F
	sub r0, r5, #3
	mov r2, #0
	strb r0, [r4, r1]
	mvn r2, r2
	sub r0, r1, #1
	strb r2, [r4, r0]
	mov r0, #0xe
	lsl r0, r0, #8
	ldrb r1, [r4, r1]
	ldr r0, [r4, r0]
	bl ov72_022386F4
	ldr r0, _0223AA94 ; =0x00001312
	mov r1, #7
	strb r1, [r4, r0]
	ldr r0, _0223AA7C ; =0x000005DC
	bl PlaySE
	mov r0, #0xe1
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #5
	bl Sprite_SetAnimCtrlSeq
_0223AA6A:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0223AA6C: .word 0x0000130C
_0223AA70: .word 0x00001310
_0223AA74: .word 0x00000E04
_0223AA78: .word 0x0000130F
_0223AA7C: .word 0x000005DC
_0223AA80: .word ov72_0223B478
_0223AA84: .word ov72_0223B479
_0223AA88: .word 0x000005F2
_0223AA8C: .word 0x00000E08
_0223AA90: .word 0x0000130E
_0223AA94: .word 0x00001312
_0223AA98: .word 0x00000E0C
	thumb_func_end ov72_0223A8F0


	thumb_func_start ov72_0223AA9C
ov72_0223AA9C: ; 0x0223AA9C
	push {r4, lr}
	ldr r1, _0223AB78 ; =gSystem
	mov r3, #0x40
	ldr r2, [r1, #0x4c]
	add r4, r0, #0
	tst r3, r2
	beq _0223AAD0
	ldr r2, _0223AB7C ; =0x0000130F
	mov r1, #0
	ldrb r0, [r4, r2]
	add r2, #0x55
	add r2, r4, r2
	bl ov72_0223A760
	ldr r1, _0223AB7C ; =0x0000130F
	strb r0, [r4, r1]
	mov r0, #0xe
	lsl r0, r0, #8
	ldrb r1, [r4, r1]
	ldr r0, [r4, r0]
	bl ov72_022386F4
	ldr r0, _0223AB80 ; =0x000005DC
	bl PlaySE
	b _0223AB74
_0223AAD0:
	mov r3, #0x80
	tst r3, r2
	beq _0223AAFC
	ldr r2, _0223AB7C ; =0x0000130F
	mov r1, #1
	ldrb r0, [r4, r2]
	add r2, #0x55
	add r2, r4, r2
	bl ov72_0223A760
	ldr r1, _0223AB7C ; =0x0000130F
	strb r0, [r4, r1]
	mov r0, #0xe
	lsl r0, r0, #8
	ldrb r1, [r4, r1]
	ldr r0, [r4, r0]
	bl ov72_022386F4
	ldr r0, _0223AB80 ; =0x000005DC
	bl PlaySE
	b _0223AB74
_0223AAFC:
	mov r3, #0x20
	tst r3, r2
	beq _0223AB28
	ldr r2, _0223AB7C ; =0x0000130F
	mov r1, #2
	ldrb r0, [r4, r2]
	add r2, #0x55
	add r2, r4, r2
	bl ov72_0223A760
	ldr r1, _0223AB7C ; =0x0000130F
	strb r0, [r4, r1]
	mov r0, #0xe
	lsl r0, r0, #8
	ldrb r1, [r4, r1]
	ldr r0, [r4, r0]
	bl ov72_022386F4
	ldr r0, _0223AB80 ; =0x000005DC
	bl PlaySE
	b _0223AB74
_0223AB28:
	mov r3, #0x10
	tst r2, r3
	beq _0223AB54
	ldr r2, _0223AB7C ; =0x0000130F
	mov r1, #3
	ldrb r0, [r4, r2]
	add r2, #0x55
	add r2, r4, r2
	bl ov72_0223A760
	ldr r1, _0223AB7C ; =0x0000130F
	strb r0, [r4, r1]
	mov r0, #0xe
	lsl r0, r0, #8
	ldrb r1, [r4, r1]
	ldr r0, [r4, r0]
	bl ov72_022386F4
	ldr r0, _0223AB80 ; =0x000005DC
	bl PlaySE
	b _0223AB74
_0223AB54:
	ldr r2, [r1, #0x48]
	mov r1, #1
	tst r1, r2
	beq _0223AB68
	ldr r1, _0223AB7C ; =0x0000130F
	ldrb r1, [r4, r1]
	add r1, r1, #3
	bl ov72_0223A8F0
	b _0223AB74
_0223AB68:
	mov r1, #2
	tst r1, r2
	beq _0223AB74
	mov r1, #0xd
	bl ov72_0223A8F0
_0223AB74:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_0223AB78: .word gSystem
_0223AB7C: .word 0x0000130F
_0223AB80: .word 0x000005DC
	thumb_func_end ov72_0223AA9C


	thumb_func_start ov72_0223AB84
ov72_0223AB84: ; 0x0223AB84
	push {r4, lr}
	add r4, r0, #0
	bl ov72_0223A738
	add r1, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	bne _0223AB9E
	add r0, r4, #0
	bl ov72_0223AA9C
	b _0223ABA4
_0223AB9E:
	add r0, r4, #0
	bl ov72_0223A8F0
_0223ABA4:
	add r0, r4, #0
	bl ov72_0223ABB0
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov72_0223AB84


	thumb_func_start ov72_0223ABB0
ov72_0223ABB0: ; 0x0223ABB0
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r4, #0
	add r5, r6, #0
	sub r7, r4, #1
_0223ABBA:
	ldr r0, _0223ABEC ; =0x00001314
	add r1, r6, r4
	ldrsb r1, [r1, r0]
	cmp r1, r7
	bne _0223ABD0
	ldr r0, _0223ABF0 ; =0x00000DF4
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
	b _0223ABE2
_0223ABD0:
	cmp r1, #0
	blt _0223ABE2
	cmp r1, #9
	bgt _0223ABE2
	ldr r0, _0223ABF0 ; =0x00000DF4
	add r1, r1, #1
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
_0223ABE2:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _0223ABBA
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0223ABEC: .word 0x00001314
_0223ABF0: .word 0x00000DF4
	thumb_func_end ov72_0223ABB0

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
	.public ov72_02237B54

	thumb_func_start ov72_022378DC
ov72_022378DC: ; 0x022378DC
	push {r3, lr}
	ldr r1, _02237B48 ; =_0223B820
	ldr r0, [r1]
	cmp r0, #0xc
	bls _022378E8
	b _02237B44
_022378E8:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022378F4: ; jump table
	.short _02237B44 - _022378F4 - 2 ; case 0
	.short _02237B44 - _022378F4 - 2 ; case 1
	.short _0223790E - _022378F4 - 2 ; case 2
	.short _02237B38 - _022378F4 - 2 ; case 3
	.short _02237958 - _022378F4 - 2 ; case 4
	.short _02237B38 - _022378F4 - 2 ; case 5
	.short _022379C8 - _022378F4 - 2 ; case 6
	.short _02237B38 - _022378F4 - 2 ; case 7
	.short _02237A3A - _022378F4 - 2 ; case 8
	.short _02237B38 - _022378F4 - 2 ; case 9
	.short _02237AAC - _022378F4 - 2 ; case 10
	.short _02237B38 - _022378F4 - 2 ; case 11
	.short _02237B44 - _022378F4 - 2 ; case 12
_0223790E:
	bl ov38_0221BF48
	cmp r0, #1
	beq _0223791C
	cmp r0, #7
	beq _02237934
	pop {r3, pc}
_0223791C:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	bl ov38_0221C014
	bl ov72_02237D88
	ldr r1, _02237B48 ; =_0223B820
	str r0, [r1, #4]
	bl ov38_0221BFEC
	pop {r3, pc}
_02237934:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	bl ov38_0221C020
	cmp r0, #0
	ble _0223794A
	ldr r0, _02237B4C ; =ov72_0223B920
	ldrb r1, [r0, #3]
	ldr r0, _02237B48 ; =_0223B820
	b _02237950
_0223794A:
	mov r1, #1
	ldr r0, _02237B48 ; =_0223B820
	mvn r1, r1
_02237950:
	str r1, [r0, #4]
	bl ov38_0221BFEC
	pop {r3, pc}
_02237958:
	bl ov38_0221BF48
	cmp r0, #1
	beq _02237966
	cmp r0, #7
	beq _0223797E
	pop {r3, pc}
_02237966:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	bl ov38_0221C014
	bl ov72_02237D88
	ldr r1, _02237B48 ; =_0223B820
	str r0, [r1, #4]
	bl ov38_0221BFEC
	pop {r3, pc}
_0223797E:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	bl ov38_0221C020
	ldr r1, _02237B50 ; =0x00000A38
	cmp r0, r1
	bne _02237996
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0
	str r1, [r0, #4]
	b _022379C2
_02237996:
	ldr r0, _02237B4C ; =ov72_0223B920
	ldr r0, [r0, #8]
	ldrb r0, [r0]
	cmp r0, #2
	beq _022379A6
	cmp r0, #5
	beq _022379B0
	b _022379BA
_022379A6:
	mov r1, #2
	ldr r0, _02237B48 ; =_0223B820
	mvn r1, r1
	str r1, [r0, #4]
	b _022379C2
_022379B0:
	mov r1, #1
	ldr r0, _02237B48 ; =_0223B820
	mvn r1, r1
	str r1, [r0, #4]
	b _022379C2
_022379BA:
	mov r1, #4
	ldr r0, _02237B48 ; =_0223B820
	mvn r1, r1
	str r1, [r0, #4]
_022379C2:
	bl ov38_0221BFEC
	pop {r3, pc}
_022379C8:
	bl ov38_0221BF48
	cmp r0, #1
	beq _022379D6
	cmp r0, #7
	beq _022379EE
	pop {r3, pc}
_022379D6:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	bl ov38_0221C014
	bl ov72_02237D88
	ldr r1, _02237B48 ; =_0223B820
	str r0, [r1, #4]
	bl ov38_0221BFEC
	pop {r3, pc}
_022379EE:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	ldr r2, _02237B4C ; =ov72_0223B920
	str r1, [r0]
	ldrb r2, [r2, #3]
	cmp r2, #5
	bhi _02237A2C
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_02237A08: ; jump table
	.short _02237A2C - _02237A08 - 2 ; case 0
	.short _02237A14 - _02237A08 - 2 ; case 1
	.short _02237A1A - _02237A08 - 2 ; case 2
	.short _02237A2C - _02237A08 - 2 ; case 3
	.short _02237A20 - _02237A08 - 2 ; case 4
	.short _02237A26 - _02237A08 - 2 ; case 5
_02237A14:
	mov r1, #0
	str r1, [r0, #4]
	b _02237A34
_02237A1A:
	sub r1, #0xf
	str r1, [r0, #4]
	b _02237A34
_02237A20:
	sub r1, #0xd
	str r1, [r0, #4]
	b _02237A34
_02237A26:
	sub r1, #0xe
	str r1, [r0, #4]
	b _02237A34
_02237A2C:
	mov r1, #4
	ldr r0, _02237B48 ; =_0223B820
	mvn r1, r1
	str r1, [r0, #4]
_02237A34:
	bl ov38_0221BFEC
	pop {r3, pc}
_02237A3A:
	bl ov38_0221BF48
	cmp r0, #1
	beq _02237A48
	cmp r0, #7
	beq _02237A60
	pop {r3, pc}
_02237A48:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	bl ov38_0221C014
	bl ov72_02237D88
	ldr r1, _02237B48 ; =_0223B820
	str r0, [r1, #4]
	bl ov38_0221BFEC
	pop {r3, pc}
_02237A60:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	ldr r2, _02237B4C ; =ov72_0223B920
	str r1, [r0]
	ldrb r2, [r2, #3]
	cmp r2, #5
	bhi _02237A9E
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_02237A7A: ; jump table
	.short _02237A9E - _02237A7A - 2 ; case 0
	.short _02237A86 - _02237A7A - 2 ; case 1
	.short _02237A9E - _02237A7A - 2 ; case 2
	.short _02237A8C - _02237A7A - 2 ; case 3
	.short _02237A92 - _02237A7A - 2 ; case 4
	.short _02237A98 - _02237A7A - 2 ; case 5
_02237A86:
	mov r1, #0
	str r1, [r0, #4]
	b _02237AA6
_02237A8C:
	mov r1, #1
	str r1, [r0, #4]
	b _02237AA6
_02237A92:
	mov r1, #2
	str r1, [r0, #4]
	b _02237AA6
_02237A98:
	sub r1, #0xe
	str r1, [r0, #4]
	b _02237AA6
_02237A9E:
	mov r1, #4
	ldr r0, _02237B48 ; =_0223B820
	mvn r1, r1
	str r1, [r0, #4]
_02237AA6:
	bl ov38_0221BFEC
	pop {r3, pc}
_02237AAC:
	bl ov38_0221BF48
	cmp r0, #1
	beq _02237ABA
	cmp r0, #7
	beq _02237AD2
	pop {r3, pc}
_02237ABA:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	bl ov38_0221C014
	bl ov72_02237D88
	ldr r1, _02237B48 ; =_0223B820
	str r0, [r1, #4]
	bl ov38_0221BFEC
	pop {r3, pc}
_02237AD2:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0xc
	str r1, [r0]
	bl ov38_0221C020
	cmp r0, #8
	bne _02237AE8
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0
	str r1, [r0, #4]
	b _02237B32
_02237AE8:
	ldr r0, _02237B4C ; =ov72_0223B920
	ldrb r0, [r0, #3]
	cmp r0, #5
	bhi _02237B2A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02237AFC: ; jump table
	.short _02237B2A - _02237AFC - 2 ; case 0
	.short _02237B08 - _02237AFC - 2 ; case 1
	.short _02237B2A - _02237AFC - 2 ; case 2
	.short _02237B10 - _02237AFC - 2 ; case 3
	.short _02237B18 - _02237AFC - 2 ; case 4
	.short _02237B20 - _02237AFC - 2 ; case 5
_02237B08:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #0
	str r1, [r0, #4]
	b _02237B32
_02237B10:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #1
	str r1, [r0, #4]
	b _02237B32
_02237B18:
	ldr r0, _02237B48 ; =_0223B820
	mov r1, #2
	str r1, [r0, #4]
	b _02237B32
_02237B20:
	mov r1, #1
	ldr r0, _02237B48 ; =_0223B820
	mvn r1, r1
	str r1, [r0, #4]
	b _02237B32
_02237B2A:
	mov r1, #4
	ldr r0, _02237B48 ; =_0223B820
	mvn r1, r1
	str r1, [r0, #4]
_02237B32:
	bl ov38_0221BFEC
	pop {r3, pc}
_02237B38:
	mov r0, #0xc
	str r0, [r1]
	sub r0, #0x10
	str r0, [r1, #4]
	bl ov38_0221BFEC
_02237B44:
	pop {r3, pc}
	nop
_02237B48: .word _0223B820
_02237B4C: .word ov72_0223B920
_02237B50: .word 0x00000A38
	thumb_func_end ov72_022378DC

	.include "asm/macros.inc"
	.include "overlay_48.inc"
	.include "global.inc"

	.text
	.public _0225B164
	.public ov48_02258800
	.public ov48_02258920
	.public ov48_022589FC
	.public ov48_02258A80
	.public ov48_02258B7C
	.public ov48_02258BF4
	.public ov48_02258C6C
	.public ov48_02258CE4
	.public ov48_02258D54
	.public ov48_02258F0C
	.public ov48_02258F64
	.public ov48_0225909C
	.public ov48_02259130
	.public ov48_02259188
	.public ov48_022591D8
	.public ov48_0225932C
	.public ov48_022593B4
	.public ov48_022593F4
	.public ov48_02259464
	.public ov48_022594F0
	.public ov48_02259650
	.public ov48_02259688
	.public ov48_02259750
	.public ov48_02259798
	.public ov48_022598EC
	.public ov48_022599A0
	.public ov48_02259A68
	.public ov48_02259B10
	.public ov48_02259BC0
	.public ov48_02259C78
	.public ov48_02259D00
	.public ov48_02259DA0
	.public ov48_02259EAC
	.public ov48_02259F48
	.public ov48_02259F8C
	.public ov48_0225A00C
	.public ov48_0225A108
	.public ov48_0225A158
	.public ov48_0225A20C
	.public ov48_0225A2A0
	.public ov48_0225A338
	.public ov48_0225A354
	.public ov48_0225A428
	.public ov48_0225A43C
	.public ov48_0225A4C0
	.public ov48_0225A57C
	.public ov48_0225A5C4
	.public ov48_0225A680
	.public ov48_0225A6DC
	.public ov48_0225A768
	.public ov48_0225A790
	.public ov48_0225A868
	.public ov48_0225A894
	.public ov48_0225A928
	.public ov48_0225A95C
	.public ov48_0225AA38
	.public ov48_0225AA5C
	.public ov48_0225AAAC
	.public ov48_0225AC34
	.public ov48_0225ACAC
	.public ov48_0225ACD8
	.public ov48_0225AD54
	.public ov48_0225ADBC
	.public ov48_0225ADF8
	.public ov48_0225AEDC
	.public ov48_0225AFB4
	.public ov48_0225B010
	.public ov48_0225B16C
	.public ov48_0225B178
	.public ov48_0225B184
	.public ov48_0225B190
	.public ov48_0225B1A0
	.public ov48_0225B1B0
	.public ov48_0225B1C4
	.public ov48_0225B1D8
	.public ov48_0225B1EC
	.public ov48_0225B210
	.public ov48_0225B238
	.public ov48_0225B239
	.public ov48_0225B268
	.public ov48_0225B2A4
	.public ov48_0225B330
	.public ov48_02259030
	.public ov48_02259050
	.public ov48_02259090
	.public ov48_022592E0
	.public ov48_022594A8
	.public ov48_022594D0
	.public ov48_022594DC
	.public ov48_02259724
	.public ov48_02259788
	.public ov48_02259824
	.public ov48_02259868
	.public ov48_02259874
	.public ov48_022598AC
	.public ov48_022598BC
	.public ov48_022598CC
	.public ov48_022598DC
	.public ov48_02259984
	.public ov48_02259AD0
	.public ov48_02259B3C
	.public ov48_02259B68
	.public ov48_02259B84
	.public ov48_02259BA0
	.public ov48_02259BBC
	.public ov48_02259C38
	.public ov48_02259C44
	.public ov48_02259C4C
	.public ov48_02259CFC
	.public ov48_02259D94
	.public ov48_02259E5C
	.public ov48_02259E78
	.public ov48_02259E90
	.public ov48_02259F14
	.public ov48_02259FEC
	.public ov48_0225A1D0
	.public ov48_0225A1EC
	.public ov48_0225A244
	.public ov48_0225A288
	.public ov48_0225A294
	.public ov48_0225A2EC
	.public ov48_0225A30C
	.public ov48_0225A41C
	.public ov48_0225A430
	.public ov48_0225A4B4
	.public ov48_0225A634
	.public ov48_0225A650
	.public ov48_0225A668
	.public ov48_0225A834
	.public ov48_0225A858
	.public ov48_0225AA50
	.public ov48_0225AD38
	.public ov48_0225AE3C
	.public ov48_0225AE58
	.public ov48_0225AE5C
	.public ov48_0225AE60
	.public ov48_0225AEA8
	.public ov48_0225AEC4
	.public ov48_0225B038
	.public ov48_0225B050
	.public ov48_0225B068
	.public ov48_0225B0A4
	.public ov48_0225B0C4
	.public ov48_0225B0D4
	.public ov48_0225B0E0
	.public ov48_0225B108
	.public ov48_0225B13C

	thumb_func_start ov48_02258D54
ov48_02258D54: ; 0x02258D54
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r0, #0
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #0x5e
	lsl r0, r0, #2
	str r1, [sp]
	add r0, r4, r0
	add r1, sp, #0xc
	add r7, r2, #0
	bl ov48_022598CC
	ldr r0, _02258EF4 ; =0x0000C3E0
	mov r1, #0
	add r0, r4, r0
	bl ov48_02259E5C
	add r6, r0, #0
	ldr r0, _02258EF4 ; =0x0000C3E0
	mov r1, #1
	add r0, r4, r0
	bl ov48_02259E5C
	str r0, [sp, #4]
	ldr r0, _02258EF4 ; =0x0000C3E0
	mov r1, #2
	add r0, r4, r0
	bl ov48_02259E5C
	add r5, r0, #0
	ldr r0, _02258EF8 ; =0x0000C3CC
	add r0, r4, r0
	bl ov48_02259CFC
	ldr r2, [sp, #0x10]
	add r1, r0, #0
	lsl r2, r2, #0x10
	ldr r0, [sp, #0xc]
	asr r2, r2, #0x10
	mov ip, r2
	lsl r0, r0, #0x10
	ldr r2, [sp]
	mov r3, #1
	asr r0, r0, #0x10
	tst r2, r3
	bne _02258DB8
	add r2, r6, #0
	tst r2, r3
	beq _02258DCC
_02258DB8:
	ldr r0, [r4, #4]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _02258DC6
	mov r0, #1
	str r0, [sp, #8]
_02258DC6:
	ldr r0, [sp, #8]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
_02258DCC:
	cmp r1, #0
	bne _02258DF4
	ldr r1, [sp, #4]
	cmp r1, #0
	bne _02258DDA
	cmp r5, #0
	beq _02258DEE
_02258DDA:
	ldr r2, [sp, #4]
	mov r1, #0x55
	mul r1, r2
	lsl r1, r1, #0x10
	lsr r3, r1, #0x10
	mov r1, #0x55
	mul r1, r5
	lsl r1, r1, #0x10
	lsr r5, r1, #0x10
	b _02258E16
_02258DEE:
	lsl r3, r3, #9
	add r5, r3, #0
	b _02258E16
_02258DF4:
	ldr r1, [sp, #4]
	cmp r1, #0
	bne _02258DFE
	cmp r5, #0
	beq _02258E12
_02258DFE:
	ldr r2, [sp, #4]
	mov r1, #0xa
	mul r1, r2
	lsl r1, r1, #0x10
	lsr r3, r1, #0x10
	mov r1, #0xa
	mul r1, r5
	lsl r1, r1, #0x10
	lsr r5, r1, #0x10
	b _02258E16
_02258E12:
	mov r3, #0x20
	add r5, r3, #0
_02258E16:
	mov r2, #0x20
	add r1, r7, #0
	tst r1, r2
	bne _02258E24
	add r1, r6, #0
	tst r1, r2
	beq _02258E44
_02258E24:
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _02258E36
	ldr r1, [sp, #0x10]
	add r1, r1, r3
	str r1, [sp, #0x10]
	b _02258E44
_02258E36:
	ldr r2, _02258EFC ; =0xFFFFD820
	mov r1, ip
	cmp r1, r2
	bge _02258E44
	ldr r1, [sp, #0x10]
	add r1, r1, r3
	str r1, [sp, #0x10]
_02258E44:
	mov r2, #0x10
	add r1, r7, #0
	tst r1, r2
	bne _02258E52
	add r1, r6, #0
	tst r1, r2
	beq _02258E72
_02258E52:
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _02258E64
	ldr r1, [sp, #0x10]
	sub r1, r1, r3
	str r1, [sp, #0x10]
	b _02258E72
_02258E64:
	ldr r2, _02258F00 ; =0xFFFFCC80
	mov r1, ip
	cmp r1, r2
	ble _02258E72
	ldr r1, [sp, #0x10]
	sub r1, r1, r3
	str r1, [sp, #0x10]
_02258E72:
	mov r1, #0x40
	add r2, r7, #0
	tst r2, r1
	bne _02258E7E
	tst r1, r6
	beq _02258EAA
_02258E7E:
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _02258E9E
	mov r1, #0x3e
	add r2, r0, r5
	lsl r1, r1, #8
	cmp r2, r1
	bge _02258E9A
	ldr r1, [sp, #0xc]
	add r1, r1, r5
	str r1, [sp, #0xc]
	b _02258EAA
_02258E9A:
	str r1, [sp, #0xc]
	b _02258EAA
_02258E9E:
	ldr r1, _02258F04 ; =0x00002020
	cmp r0, r1
	bge _02258EAA
	ldr r1, [sp, #0xc]
	add r1, r1, r5
	str r1, [sp, #0xc]
_02258EAA:
	mov r1, #0x80
	add r2, r7, #0
	tst r2, r1
	bne _02258EB6
	tst r1, r6
	beq _02258EE2
_02258EB6:
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _02258ED4
	sub r1, r0, r5
	ldr r0, _02258F08 ; =0xFFFFC200
	cmp r1, r0
	ble _02258ED0
	ldr r0, [sp, #0xc]
	sub r0, r0, r5
	str r0, [sp, #0xc]
	b _02258EE2
_02258ED0:
	str r0, [sp, #0xc]
	b _02258EE2
_02258ED4:
	mov r1, #0x13
	lsl r1, r1, #8
	cmp r0, r1
	ble _02258EE2
	ldr r0, [sp, #0xc]
	sub r0, r0, r5
	str r0, [sp, #0xc]
_02258EE2:
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, sp, #0xc
	bl ov48_022598DC
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02258EF4: .word 0x0000C3E0
_02258EF8: .word 0x0000C3CC
_02258EFC: .word 0xFFFFD820
_02258F00: .word 0xFFFFCC80
_02258F04: .word 0x00002020
_02258F08: .word 0xFFFFC200
	thumb_func_end ov48_02258D54

	thumb_func_start ov48_02258F0C
ov48_02258F0C: ; 0x02258F0C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	blt _02258F20
	ldr r1, _02258F60 ; =0x0000FFFF
	bl _s32_div_f
	str r1, [r4]
	b _02258F36
_02258F20:
	bge _02258F24
	neg r0, r0
_02258F24:
	ldr r1, _02258F60 ; =0x0000FFFF
	bl _s32_div_f
	add r1, r0, #1
	ldr r0, _02258F60 ; =0x0000FFFF
	ldr r2, [r4]
	mul r0, r1
	add r0, r2, r0
	str r0, [r4]
_02258F36:
	ldr r0, [r4, #4]
	cmp r0, #0
	blt _02258F46
	ldr r1, _02258F60 ; =0x0000FFFF
	bl _s32_div_f
	str r1, [r4, #4]
	pop {r4, pc}
_02258F46:
	bge _02258F4A
	neg r0, r0
_02258F4A:
	ldr r1, _02258F60 ; =0x0000FFFF
	bl _s32_div_f
	add r1, r0, #1
	ldr r0, _02258F60 ; =0x0000FFFF
	ldr r2, [r4, #4]
	mul r0, r1
	add r0, r2, r0
	str r0, [r4, #4]
	pop {r4, pc}
	nop
_02258F60: .word 0x0000FFFF
	thumb_func_end ov48_02258F0C

	thumb_func_start ov48_02258F64
ov48_02258F64: ; 0x02258F64
	push {r4, lr}
	add r4, r0, #0
	ldrh r1, [r4]
	cmp r1, #3
	bhi _0225901C
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02258F7A: ; jump table
	.short _02258F82 - _02258F7A - 2 ; case 0
	.short _02258FA8 - _02258F7A - 2 ; case 1
	.short _02258FC0 - _02258F7A - 2 ; case 2
	.short _02258FE2 - _02258F7A - 2 ; case 3
_02258F82:
	bl ov48_0225909C
	cmp r0, #0
	beq _02259020
	cmp r0, #1
	beq _02258F94
	cmp r0, #2
	beq _02258FA2
	b _02259020
_02258F94:
	ldr r0, _02259024 ; =0x0000C3CC
	add r0, r4, r0
	bl ov48_02259C4C
	mov r0, #1
	strh r0, [r4]
	b _02259020
_02258FA2:
	mov r0, #2
	strh r0, [r4]
	b _02259020
_02258FA8:
	ldr r0, _02259024 ; =0x0000C3CC
	mov r1, #0x89
	lsl r1, r1, #2
	add r0, r4, r0
	add r1, r4, r1
	bl ov48_02259C78
	cmp r0, #1
	bne _02259020
	mov r0, #0
	strh r0, [r4]
	b _02259020
_02258FC0:
	mov r0, #0xc7
	lsl r0, r0, #8
	add r0, r4, r0
	bl ov48_02259F48
	ldr r0, _02259028 ; =0x0000C40C
	add r0, r4, r0
	bl ov48_0225A1D0
	ldr r0, _0225902C ; =0x0000C3E0
	add r0, r4, r0
	bl ov48_02259E78
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	b _02259020
_02258FE2:
	mov r0, #0xc7
	lsl r0, r0, #8
	add r0, r4, r0
	bl ov48_02259F8C
	cmp r0, #0
	beq _02259020
	cmp r0, #1
	beq _02259018
	cmp r0, #2
	bne _02259018
	ldr r0, _02259028 ; =0x0000C40C
	add r0, r4, r0
	bl ov48_0225A1EC
	mov r0, #0xc7
	lsl r0, r0, #8
	add r0, r4, r0
	bl ov48_02259FEC
	ldr r0, _0225902C ; =0x0000C3E0
	add r0, r4, r0
	bl ov48_02259E90
	mov r0, #0
	strh r0, [r4]
	b _02259020
_02259018:
	mov r0, #1
	pop {r4, pc}
_0225901C:
	bl GF_AssertFail
_02259020:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_02259024: .word 0x0000C3CC
_02259028: .word 0x0000C40C
_0225902C: .word 0x0000C3E0
	thumb_func_end ov48_02258F64

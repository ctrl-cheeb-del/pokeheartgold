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

	thumb_func_start ov48_0225909C
ov48_0225909C: ; 0x0225909C
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, _0225911C ; =0x0000C3E0
	add r0, r5, r0
	bl ov48_02259DA0
	ldr r0, _0225911C ; =0x0000C3E0
	ldr r1, [r5, r0]
	mov r0, #2
	tst r1, r0
	beq _022590C0
	ldr r0, _02259120 ; =0x000005DD
	bl PlaySE
	add sp, #0xc
	mov r0, #2
	pop {r4, r5, pc}
_022590C0:
	ldr r2, _02259124 ; =gSystem
	lsl r0, r0, #9
	ldr r1, [r2, #0x48]
	tst r0, r1
	beq _0225910C
	add r0, r5, #0
	add r1, sp, #0
	bl ov48_02259188
	cmp r0, #1
	bne _02259116
	ldr r0, _02259128 ; =0x0000C40C
	add r1, sp, #0
	add r0, r5, r0
	bl ov48_0225A244
	cmp r0, #0
	bne _02259116
	ldr r0, _02259128 ; =0x0000C40C
	add r1, sp, #0
	add r0, r5, r0
	bl ov48_0225A20C
	cmp r0, #0
	beq _02259116
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov48_022593B4
	ldr r0, _0225912C ; =0x000005D6
	bl PlaySE
	b _02259116
_0225910C:
	ldr r2, [r2, #0x44]
	add r0, r5, #0
	bl ov48_02258D54
	add r4, r0, #0
_02259116:
	add r0, r4, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_0225911C: .word 0x0000C3E0
_02259120: .word 0x000005DD
_02259124: .word gSystem
_02259128: .word 0x0000C40C
_0225912C: .word 0x000005D6
	thumb_func_end ov48_0225909C


	thumb_func_start ov48_02259130
ov48_02259130: ; 0x02259130
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r1, [r5, #0x14]
	ldr r2, [r5, #0x18]
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov48_022593B4
	cmp r0, #0
	bne _02259184
	ldr r0, [r4]
	bl ov48_0225B13C
	add r6, r0, #0
	cmp r6, #0x32
	beq _02259184
	lsl r1, r6, #0x18
	ldr r0, [r4]
	lsr r1, r1, #0x18
	bl ov45_0222D6B0
	add r7, r0, #0
	lsl r1, r6, #0x18
	ldr r0, [r4]
	lsr r1, r1, #0x18
	bl ov45_0222D6D4
	add r2, r0, #0
	lsl r1, r7, #0x18
	lsl r2, r2, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov48_022593B4
	cmp r0, #1
	beq _02259184
	bl GF_AssertFail
_02259184:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov48_02259130


	thumb_func_start ov48_02259188
ov48_02259188: ; 0x02259188
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl ov48_022591D8
	add r6, r0, #0
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	bl ov48_02259BBC
	cmp r6, r0
	blo _022591A6
	mov r0, #0
	pop {r4, r5, r6, pc}
_022591A6:
	add r2, r5, #0
	add r2, #0x1c
	ldr r2, [r2]
	add r0, r5, #0
	add r1, r6, #0
	bl ov48_0225932C
	str r0, [r4]
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, r6, #0
	bl ov48_02259B84
	str r0, [r4, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, r6, #0
	bl ov48_02259BA0
	str r0, [r4, #8]
	mov r0, #1
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov48_02259188


	thumb_func_start ov48_022591D8
ov48_022591D8: ; 0x022591D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r5, r0, #0
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	bl ov48_02259BBC
	str r0, [sp, #0xc]
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, sp, #0x28
	bl ov48_022598CC
	ldr r1, [sp, #0x28]
	add r0, r1, #0
	sub r0, #0x80
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add r1, #0x80
	str r0, [sp, #4]
	lsl r0, r1, #0x10
	asr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	add r1, r0, #0
	sub r1, #0x80
	lsl r1, r1, #0x10
	asr r6, r1, #0x10
	add r1, r0, #0
	add r1, #0x80
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	str r1, [sp, #0x18]
	sub r2, r1, r6
	bpl _02259224
	neg r2, r2
_02259224:
	mov r1, #1
	lsl r1, r1, #8
	cmp r2, r1
	ble _0225925E
	lsl r0, r0, #0x10
	asr r6, r0, #0x10
	str r6, [sp, #0x18]
	cmp r6, #0
	ble _02259240
	lsl r0, r1, #8
	sub r0, r6, r0
	str r0, [sp, #0x14]
	str r0, [sp, #0x10]
	b _02259248
_02259240:
	lsl r0, r1, #8
	add r0, r6, r0
	str r0, [sp, #0x14]
	str r0, [sp, #0x10]
_02259248:
	ldr r0, [sp, #0x18]
	sub r6, #0x80
	add r0, #0x80
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	sub r0, #0x80
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, #0x80
	str r0, [sp, #0x10]
	b _02259264
_0225925E:
	ldr r0, [sp, #0x18]
	str r6, [sp, #0x14]
	str r0, [sp, #0x10]
_02259264:
	ldr r0, [sp, #0xc]
	mov r7, #1
	lsl r7, r7, #8
	mov r4, #0
	str r0, [sp, #8]
	cmp r0, #0
	bls _022592DA
_02259272:
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, sp, #0x1c
	add r2, r4, #0
	bl ov48_02259B3C
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, r4, #0
	bl ov48_02259B68
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #4]
	cmp r1, r2
	ble _022592D2
	ldr r2, [sp]
	cmp r1, r2
	bge _022592D2
	ldr r1, [sp, #0x20]
	cmp r1, r6
	ble _022592A6
	ldr r2, [sp, #0x18]
	cmp r1, r2
	blt _022592B2
_022592A6:
	ldr r2, [sp, #0x14]
	cmp r1, r2
	ble _022592D2
	ldr r2, [sp, #0x10]
	cmp r1, r2
	bge _022592D2
_022592B2:
	cmp r0, #3
	beq _022592D2
	add r0, sp, #0x28
	bl ov48_02258F0C
	add r0, sp, #0x1c
	bl ov48_02258F0C
	add r0, sp, #0x28
	add r1, sp, #0x1c
	bl ov48_022592E0
	cmp r0, r7
	bhs _022592D2
	add r7, r0, #0
	str r4, [sp, #8]
_022592D2:
	ldr r0, [sp, #0xc]
	add r4, r4, #1
	cmp r4, r0
	blo _02259272
_022592DA:
	ldr r0, [sp, #8]
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov48_022591D8

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

	thumb_func_start ov48_0225AEDC
ov48_0225AEDC: ; 0x0225AEDC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldrh r0, [r5, #0xa]
	ldr r2, [r5, #0xc]
	cmp r0, #0
	bne _0225AEF4
	mov r0, #6
	ldrsh r0, [r2, r0]
	sub r0, #0x10
	lsl r0, r0, #0x10
	asr r7, r0, #0x10
	b _0225AEF8
_0225AEF4:
	mov r0, #6
	ldrsh r7, [r2, r0]
_0225AEF8:
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _0225AF0A
	mov r0, #2
	ldrsh r0, [r2, r0]
	add r0, #0x10
	lsl r0, r0, #0x10
	asr r4, r0, #0x10
	b _0225AF0E
_0225AF0A:
	mov r0, #2
	ldrsh r4, [r2, r0]
_0225AF0E:
	mov r0, #0
	ldrsh r6, [r2, r0]
	mov r0, #4
	ldrsh r1, [r5, r0]
	ldrsh r0, [r2, r0]
	sub r0, r0, r6
	mul r0, r1
	mov r1, #8
	ldrsh r1, [r2, r1]
	bl _s32_div_f
	add r0, r6, r0
	strh r0, [r5]
	mov r0, #4
	ldrsh r1, [r5, r0]
	sub r0, r7, r4
	ldr r2, [r5, #0xc]
	mul r0, r1
	mov r1, #8
	ldrsh r1, [r2, r1]
	bl _s32_div_f
	add r0, r4, r0
	strh r0, [r5, #2]
	mov r0, #6
	ldrsh r1, [r5, r0]
	ldr r0, _0225AFAC ; =0x0000FFFF
	ldr r4, [r5, #0xc]
	mul r0, r1
	mov r1, #0xc
	ldrsh r1, [r4, r1]
	bl _s32_div_f
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r1, r0, #2
	ldr r0, _0225AFB0 ; =FX_SinCosTable_
	ldrsh r6, [r0, r1]
	mov r0, #0xa
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _0225AF76
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0225AF84
_0225AF76:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0225AF84:
	bl _ffix
	asr r1, r0, #0x1f
	asr r3, r6, #0x1f
	add r2, r6, #0
	bl _ll_mul
	mov r3, #2
	mov r4, #0
	lsl r3, r3, #0xa
	add r3, r0, r3
	adc r1, r4
	lsl r0, r1, #0x14
	lsr r1, r3, #0xc
	orr r1, r0
	ldrsh r2, [r5, r4]
	asr r0, r1, #0xc
	add r0, r2, r0
	strh r0, [r5]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225AFAC: .word 0x0000FFFF
_0225AFB0: .word FX_SinCosTable_
	thumb_func_end ov48_0225AEDC


	thumb_func_start ov48_0225AFB4
ov48_0225AFB4: ; 0x0225AFB4
	push {r3, r4, r5, lr}
	add r4, r1, #0
	mov r1, #0
	add r5, r0, #0
	add r0, r4, #0
	add r2, r1, #0
	bl ov48_0225A650
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _0225AFE8
	ldr r1, [r5, #0xc]
	mov r0, #2
	ldrsh r1, [r1, r0]
	ldrsh r2, [r5, r0]
	add r0, r1, #0
	sub r0, #0x10
	cmp r2, r0
	ble _0225AFE8
	add r2, r1, #0
	add r2, #0x20
	lsl r2, r2, #0x10
	add r0, r4, #0
	asr r2, r2, #0x10
	bl ov48_0225A650
_0225AFE8:
	ldrh r0, [r5, #0xa]
	cmp r0, #0
	bne _0225B00C
	ldr r1, [r5, #0xc]
	mov r0, #6
	ldrsh r2, [r1, r0]
	mov r0, #2
	ldrsh r0, [r5, r0]
	sub r0, #0x10
	cmp r0, r2
	bgt _0225B00C
	add r1, r2, #0
	sub r1, #0x20
	lsl r1, r1, #0x10
	add r0, r4, #0
	asr r1, r1, #0x10
	bl ov48_0225A650
_0225B00C:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov48_0225AFB4


	thumb_func_start ov48_0225B010
ov48_0225B010: ; 0x0225B010
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r1, #0
	add r5, r0, #0
	lsl r0, r4, #4
	add r0, r5, r0
	add r1, sp, #0
	bl ov48_0225AEC4
	add r0, r5, r4
	add r0, #0x38
	ldrb r0, [r0]
	add r1, sp, #0
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x3c]
	bl Sprite_SetMatrix
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end ov48_0225B010

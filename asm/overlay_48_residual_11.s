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

	thumb_func_start ov48_02259C78
ov48_02259C78: ; 0x02259C78
	push {r3, lr}
	add r2, r0, #0
	ldrh r0, [r2, #0x12]
	cmp r0, #0
	bne _02259C86
	mov r0, #1
	pop {r3, pc}
_02259C86:
	ldrh r0, [r2, #0x10]
	cmp r0, #0
	beq _02259CBE
	cmp r0, #1
	bne _02259CEA
	mov r0, #0x16
	ldr r3, [r2, #0xc]
	lsl r0, r0, #0xe
	cmp r3, r0
	ble _02259CB2
	mov r0, #2
	lsl r0, r0, #0xe
	sub r0, r3, r0
	str r0, [r2, #0xc]
	ldr r0, _02259CF8 ; =0x0000C004
	ldr r3, [r1, r0]
	sub r3, #0x80
	str r3, [r1, r0]
	ldr r3, [r1, r0]
	add r0, r0, #4
	str r3, [r1, r0]
	b _02259CEA
_02259CB2:
	mov r0, #5
	lsl r0, r0, #0x10
	str r0, [r2, #0xc]
	mov r0, #0
	strh r0, [r2, #0x12]
	b _02259CEA
_02259CBE:
	mov r0, #0x12
	ldr r3, [r2, #0xc]
	lsl r0, r0, #0x10
	cmp r3, r0
	bge _02259CE0
	mov r0, #2
	lsl r0, r0, #0xe
	add r0, r3, r0
	str r0, [r2, #0xc]
	ldr r0, _02259CF8 ; =0x0000C004
	ldr r3, [r1, r0]
	add r3, #0x80
	str r3, [r1, r0]
	ldr r3, [r1, r0]
	add r0, r0, #4
	str r3, [r1, r0]
	b _02259CEA
_02259CE0:
	mov r0, #0x4a
	lsl r0, r0, #0xe
	str r0, [r2, #0xc]
	mov r0, #0
	strh r0, [r2, #0x12]
_02259CEA:
	ldr r0, [r2, #0xc]
	ldr r1, [r2]
	bl Camera_SetDistance
	mov r0, #0
	pop {r3, pc}
	nop
_02259CF8: .word 0x0000C004
	thumb_func_end ov48_02259C78

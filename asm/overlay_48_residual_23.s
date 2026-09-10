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

	thumb_func_start ov48_0225A680
ov48_0225A680: ; 0x0225A680
	push {r4, r5}
	mov r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	beq _0225A6A8
	mov r0, #6
	ldrsh r2, [r1, r0]
	mov r0, #4
	ldrsh r5, [r1, r0]
	ldr r0, _0225A6D4 ; =0x04001040
	mov r3, #0xff
	strh r3, [r0]
	lsl r2, r2, #0x18
	lsl r5, r5, #8
	lsl r3, r3, #8
	and r3, r5
	lsr r2, r2, #0x18
	orr r2, r3
	strh r2, [r0, #4]
	strh r4, [r1]
_0225A6A8:
	mov r0, #2
	ldrsh r0, [r1, r0]
	cmp r0, #0
	beq _0225A6D0
	mov r0, #0xa
	ldrsh r2, [r1, r0]
	mov r0, #8
	ldrsh r4, [r1, r0]
	ldr r0, _0225A6D8 ; =0x04001042
	mov r3, #0xff
	strh r3, [r0]
	lsl r2, r2, #0x18
	lsl r4, r4, #8
	lsl r3, r3, #8
	and r3, r4
	lsr r2, r2, #0x18
	orr r2, r3
	strh r2, [r0, #4]
	mov r0, #0
	strh r0, [r1, #2]
_0225A6D0:
	pop {r4, r5}
	bx lr
	.balign 4, 0
_0225A6D4: .word 0x04001040
_0225A6D8: .word 0x04001042
	thumb_func_end ov48_0225A680


	thumb_func_start ov48_0225A6DC
ov48_0225A6DC: ; 0x0225A6DC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	mov r6, #0x94
	str r1, [sp, #0x18]
	add r1, r6, #0
	mov r7, #0
	add r1, #0xd4
	str r0, [sp, #0x14]
	add r4, r7, #0
	add r5, r0, r1
_0225A6F0:
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	mov r0, #0xe
	str r0, [sp, #0xc]
	lsl r0, r6, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x18]
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #5
	mov r3, #0
	bl AddWindowParameterized
	add r0, r5, #0
	mov r1, #0
	add r6, #0xa2
	bl FillWindowPixelBuffer
	add r0, r5, #0
	bl CopyWindowToVram
	add r7, r7, #1
	add r4, r4, #6
	add r5, #0x10
	cmp r7, #3
	blt _0225A6F0
	mov r3, #0
	str r3, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	mov r0, #0xe
	str r0, [sp, #0xc]
	mov r0, #0x94
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x18]
	mov r2, #0x66
	ldr r1, [sp, #0x14]
	lsl r2, r2, #2
	add r1, r1, r2
	ldr r0, [r0]
	mov r2, #5
	bl AddWindowParameterized
	mov r1, #0x66
	ldr r0, [sp, #0x14]
	lsl r1, r1, #2
	add r0, r0, r1
	mov r1, #0
	bl FillWindowPixelBuffer
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov48_0225A6DC


	thumb_func_start ov48_0225A768
ov48_0225A768: ; 0x0225A768
	push {r4, r5, r6, lr}
	add r6, r0, #0
	mov r0, #0x5a
	lsl r0, r0, #2
	mov r4, #0
	add r5, r6, r0
_0225A774:
	add r0, r5, #0
	bl RemoveWindow
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #3
	blt _0225A774
	mov r0, #0x66
	lsl r0, r0, #2
	add r0, r6, r0
	bl RemoveWindow
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov48_0225A768


	thumb_func_start ov48_0225A790
ov48_0225A790: ; 0x0225A790
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	add r7, r3, #0
	cmp r4, #3
	blo _0225A7A4
	bl GF_AssertFail
_0225A7A4:
	mov r0, #0x5a
	lsl r0, r0, #2
	add r5, r5, r0
	lsl r4, r4, #4
	add r0, r5, r4
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	bl ov48_0225B038
	str r0, [sp, #0x10]
	add r0, r7, #0
	mov r1, #2
	bl ov48_0225B0C4
	mov r3, #0
	add r2, r0, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	lsl r1, r0, #2
	ldr r0, _0225A82C ; =ov48_0225B1D8
	ldr r0, [r0, r1]
	mov r1, #1
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r5, r4
	bl AddTextPrinterParameterizedWithColor
	ldr r1, [r6, #4]
	add r0, r7, #0
	bl ov48_0225B0E0
	add r2, r0, #0
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225A830 ; =0x00010200
	mov r3, #0
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r5, r4
	mov r1, #1
	bl AddTextPrinterParameterizedWithColor
	ldr r1, [r6, #4]
	ldr r2, [r6, #8]
	add r0, r7, #0
	bl ov48_0225B108
	add r2, r0, #0
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0225A830 ; =0x00010200
	mov r3, #0
	str r0, [sp, #8]
	add r0, r5, r4
	mov r1, #1
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0225A82C: .word ov48_0225B1D8
_0225A830: .word 0x00010200
	thumb_func_end ov48_0225A790

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

	thumb_func_start ov48_0225A4C0
ov48_0225A4C0: ; 0x0225A4C0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r2, [sp]
	add r5, r0, #0
	lsl r2, r1, #2
	add r0, r5, r2
	add r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _0225A4DA
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0225A4DA:
	add r0, r5, #0
	add r0, #0x41
	ldrsb r4, [r0, r2]
	add r6, r0, r2
	cmp r4, #2
	blt _0225A4EC
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0225A4EC:
	mov r0, #0x11
	sub r7, r0, r1
	add r0, r7, #0
	mov r1, #6
	bl _u32_div_f
	str r0, [sp, #0xc]
	add r0, r7, #0
	mov r1, #6
	bl _u32_div_f
	ldr r0, [sp, #0xc]
	str r1, [sp, #4]
	lsl r0, r0, #2
	add r0, r5, r0
	add r0, #0x88
	ldr r0, [r0]
	cmp r4, #0
	str r0, [sp, #8]
	beq _0225A51A
	cmp r4, #1
	beq _0225A548
	b _0225A570
_0225A51A:
	add r0, r5, #0
	bl ov48_0225A858
	add r3, r0, #0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #4]
	add r0, r5, #0
	bl ov48_0225A868
	ldr r2, [sp]
	add r0, r5, #0
	add r1, r7, #0
	bl ov48_0225A57C
	mov r0, #0xb9
	lsl r0, r0, #2
	lsl r1, r7, #0x13
	add r0, r5, r0
	asr r1, r1, #0x10
	mov r2, #0x90
	bl ov48_0225A668
	b _0225A570
_0225A548:
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #4]
	add r0, r5, #0
	bl ov48_0225A834
	add r3, r0, #0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #4]
	add r0, r5, #0
	bl ov48_0225A868
	ldr r0, [sp, #8]
	mov r1, #0x28
	add r5, #0xa0
	mul r1, r0
	add r0, r5, r1
	ldr r2, [sp]
	add r1, r7, #0
	bl ov48_0225AA5C
_0225A570:
	mov r0, #0
	ldrsb r1, [r6, r0]
	add r1, r1, #1
	strb r1, [r6]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov48_0225A4C0


	thumb_func_start ov48_0225A57C
ov48_0225A57C: ; 0x0225A57C
	push {r3, r4, lr}
	sub sp, #0x1c
	add r0, #0x98
	ldr r0, [r0]
	add r4, r2, #0
	mov r2, #0x20
	str r2, [sp]
	mov r2, #1
	str r2, [sp, #4]
	add r2, r0, #0
	add r2, #0xc
	str r2, [sp, #8]
	mov r2, #0
	lsl r1, r1, #0x18
	str r2, [sp, #0xc]
	lsr r3, r1, #0x18
	str r3, [sp, #0x10]
	ldrh r1, [r0]
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r1, #6
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r4]
	bl CopyToBgTilemapRect
	ldr r0, [r4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x1c
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov48_0225A57C


	thumb_func_start ov48_0225A5C4
ov48_0225A5C4: ; 0x0225A5C4
	push {r4, r5, r6, lr}
	ldr r1, _0225A624 ; =0x04001000
	ldr r2, _0225A628 ; =0xFFFF1FFF
	ldr r3, [r1]
	add r5, r1, #0
	and r3, r2
	mov r2, #6
	lsl r2, r2, #0xc
	orr r2, r3
	str r2, [r1]
	add r5, #0x4a
	ldrh r6, [r5]
	mov r3, #0x3f
	mov r2, #0x1f
	bic r6, r3
	orr r2, r6
	strh r2, [r5]
	add r1, #0x48
	ldrh r5, [r1]
	mov r2, #0xf
	add r4, r0, #0
	bic r5, r3
	add r3, r5, #0
	orr r3, r2
	strh r3, [r1]
	ldrh r5, [r1]
	ldr r3, _0225A62C ; =0xFFFFC0FF
	lsl r2, r2, #8
	and r3, r5
	orr r2, r3
	strh r2, [r1]
	mov r1, #0
	add r2, r1, #0
	bl ov48_0225A650
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	bl ov48_0225A668
	ldr r0, _0225A630 ; =ov48_0225A680
	add r1, r4, #0
	mov r2, #0
	bl SysTask_CreateOnVWaitQueue
	str r0, [r4, #0xc]
	pop {r4, r5, r6, pc}
	nop
_0225A624: .word 0x04001000
_0225A628: .word 0xFFFF1FFF
_0225A62C: .word 0xFFFFC0FF
_0225A630: .word ov48_0225A680
	thumb_func_end ov48_0225A5C4

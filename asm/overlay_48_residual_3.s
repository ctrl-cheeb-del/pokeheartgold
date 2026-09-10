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

	thumb_func_start ov48_0225932C
ov48_0225932C: ; 0x0225932C
	push {r0, r1, r2, r3}
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r0, sp, #0x30
	ldrb r0, [r0, #8]
	add r7, r1, #0
	mov r1, #0xdb
	sub r4, r0, #4
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	mov r2, #3
	bl ov48_02259B10
	add r6, r0, #0
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	bl ov48_02259BBC
	cmp r6, r0
	blo _0225935E
	bl GF_AssertFail
_0225935E:
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, sp, #0xc
	add r2, r6, #0
	bl ov48_02259B3C
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, sp, #0
	add r2, r7, #0
	bl ov48_02259B3C
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #4]
	sub r0, r1, r0
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	mov r0, #0x18
	mul r0, r1
	ldr r1, _022593B0 ; =0x0000FFFF
	bl _s32_div_f
	add r4, r4, r0
	bpl _02259394
	add r4, #0x18
_02259394:
	cmp r4, #0x18
	blt _022593A2
	add r0, r4, #0
	mov r1, #0x18
	bl _s32_div_f
	add r4, r1, #0
_022593A2:
	add r0, r4, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7}
	pop {r3}
	add sp, #0x10
	bx r3
	nop
_022593B0: .word 0x0000FFFF
	thumb_func_end ov48_0225932C


	thumb_func_start ov48_022593B4
ov48_022593B4: ; 0x022593B4
	push {r4, lr}
	sub sp, #0x18
	add r4, r0, #0
	mov r0, #0x89
	lsl r0, r0, #2
	add r0, r4, r0
	add r3, sp, #0xc
	bl ov48_02259AD0
	cmp r0, #3
	beq _022593EC
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, sp, #0
	bl ov48_022598CC
	ldr r0, [sp, #8]
	add r1, sp, #0xc
	str r0, [sp, #0x14]
	mov r0, #0x5e
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov48_022598DC
	add sp, #0x18
	mov r0, #1
	pop {r4, pc}
_022593EC:
	mov r0, #0
	add sp, #0x18
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov48_022593B4


	thumb_func_start ov48_022593F4
ov48_022593F4: ; 0x022593F4
	push {r4, r5, r6, r7}
	ldr r4, [r0, #4]
	mov r2, #2
	bic r4, r2
	mov r3, #1
	bic r4, r3
	ldr r3, _02259460 ; =gGameLanguage
	str r4, [r0, #4]
	ldrb r3, [r3]
	cmp r3, #1
	ldr r3, [r0, #4]
	bne _02259414
	mov r2, #2
	orr r2, r3
	str r2, [r0, #4]
	b _02259418
_02259414:
	bic r3, r2
	str r3, [r0, #4]
_02259418:
	ldr r2, [r0, #4]
	lsl r3, r2, #0x1e
	lsr r3, r3, #0x1f
	cmp r3, #1
	bne _02259452
	mov r3, #0
	add r4, r3, #0
	mov r5, #1
	mov r6, #1
_0225942A:
	ldr r2, [r1]
	add r7, r2, r4
	ldrb r7, [r7, #3]
	lsl r7, r7, #0x18
	lsr r7, r7, #0x1c
	cmp r7, #1
	bne _02259446
	ldrh r2, [r2, r4]
	cmp r2, #0x67
	beq _02259446
	ldr r2, [r0, #4]
	bic r2, r5
	orr r2, r6
	str r2, [r0, #4]
_02259446:
	add r3, r3, #1
	add r4, r4, #4
	cmp r3, #0x32
	blt _0225942A
	pop {r4, r5, r6, r7}
	bx lr
_02259452:
	mov r1, #1
	bic r2, r1
	mov r1, #1
	orr r1, r2
	str r1, [r0, #4]
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
_02259460: .word gGameLanguage
	thumb_func_end ov48_022593F4


	thumb_func_start ov48_02259464
ov48_02259464: ; 0x02259464
	push {r4, r5, r6, lr}
	add r4, r2, #0
	add r5, r0, #0
	add r6, r1, #0
	mov r0, #0xc0
	add r1, r4, #0
	bl NARC_New
	mov r1, #0x51
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0x40
	add r1, r4, #0
	bl GF_CreateVramTransferManager
	ldr r0, _022594A4 ; =ov48_0225B210
	bl GfGfx_SetBanks
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	bl ov48_022594F0
	add r0, r5, #0
	add r1, r4, #0
	bl ov48_02259688
	add r0, r5, #0
	add r1, r4, #0
	bl ov48_02259750
	pop {r4, r5, r6, pc}
	.balign 4, 0
_022594A4: .word ov48_0225B210
	thumb_func_end ov48_02259464

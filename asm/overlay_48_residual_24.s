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

	thumb_func_start ov48_0225A868
ov48_0225A868: ; 0x0225A868
	push {r3, r4, r5, lr}
	add r5, r2, #0
	mov r2, #0x5a
	lsl r2, r2, #2
	add r2, r0, r2
	lsl r0, r1, #4
	add r0, r2, r0
	add r4, r3, #0
	bl GetWindowBaseTile
	mov r3, #0x1b
	add r1, r5, #0
	mul r1, r3
	add r0, r0, r1
	lsl r1, r0, #0x10
	mov r0, #0x15
	lsr r1, r1, #0xb
	add r2, r4, #0
	lsl r3, r3, #5
	bl GF_CreateNewVramTransferTask
	pop {r3, r4, r5, pc}
	thumb_func_end ov48_0225A868


	thumb_func_start ov48_0225A894
ov48_0225A894: ; 0x0225A894
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r1, [sp, #4]
	ldr r1, [sp, #0x28]
	str r2, [sp, #8]
	str r1, [sp, #0x28]
	mov r1, #0
	mov r2, #0x28
	add r7, r0, #0
	add r4, r3, #0
	bl memset
	ldr r0, [sp, #8]
	strh r4, [r7, #2]
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _0225A8F4
	strh r0, [r7, #0x18]
	mov r0, #0
	str r0, [sp, #0xc]
	ldrh r0, [r7, #0x18]
	cmp r0, #0
	ble _0225A8F4
	add r6, r7, #0
	ldr r4, [sp, #8]
	add r6, #0x10
	add r5, r7, #0
_0225A8CA:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #4]
	str r0, [sp]
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldrh r1, [r4]
	mov r2, #0
	add r3, r6, #0
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	str r0, [r5, #8]
	ldr r0, [sp, #0xc]
	ldrh r1, [r7, #0x18]
	add r0, r0, #1
	add r6, r6, #4
	add r4, r4, #2
	add r5, r5, #4
	str r0, [sp, #0xc]
	cmp r0, r1
	blt _0225A8CA
_0225A8F4:
	ldr r0, [sp, #8]
	ldrh r1, [r0, #8]
	cmp r1, #0
	beq _0225A924
	add r0, r7, #0
	add r0, #0x24
	strb r1, [r0]
	ldr r0, [sp, #8]
	add r2, r7, #0
	ldrh r1, [r0, #0xa]
	add r0, r7, #0
	add r0, #0x26
	strb r1, [r0]
	mov r1, #0x51
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	ldr r1, [sp, #8]
	ldr r3, [sp, #0x28]
	ldrh r1, [r1, #6]
	add r2, #0x20
	bl GfGfxLoader_GetPlttDataFromOpenNarc
	str r0, [r7, #0x1c]
_0225A924:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov48_0225A894


	thumb_func_start ov48_0225A928
ov48_0225A928: ; 0x0225A928
	push {r4, r5, r6, lr}
	add r6, r0, #0
	ldrh r0, [r6, #0x18]
	cmp r0, #0
	beq _0225A94A
	mov r4, #0
	cmp r0, #0
	ble _0225A94A
	add r5, r6, #0
_0225A93A:
	ldr r0, [r5, #8]
	bl Heap_Free
	ldrh r0, [r6, #0x18]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r0
	blt _0225A93A
_0225A94A:
	add r0, r6, #0
	add r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0225A95A
	ldr r0, [r6, #0x1c]
	bl Heap_Free
_0225A95A:
	pop {r4, r5, r6, pc}
	thumb_func_end ov48_0225A928


	thumb_func_start ov48_0225A95C
ov48_0225A95C: ; 0x0225A95C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	ldrh r4, [r5]
	ldrh r0, [r5, #0x18]
	ldrh r6, [r5, #2]
	add r7, r1, #0
	mul r0, r4
	add r1, r6, #0
	bl _s32_div_f
	str r0, [sp, #0x20]
	add r0, r5, #0
	add r0, #0x24
	ldrb r0, [r0]
	add r1, r6, #0
	mul r0, r4
	bl _s32_div_f
	str r0, [sp, #0x1c]
	add r0, r4, #1
	add r1, r6, #0
	bl _s32_div_f
	strh r1, [r5]
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	beq _0225A9F4
	ldrh r1, [r5, #0x1a]
	ldr r0, [sp, #0x20]
	cmp r0, r1
	beq _0225A9F4
	mov r6, #0
	strh r0, [r5, #0x1a]
	add r4, r6, #0
_0225A9A2:
	add r0, r5, r6
	ldrb r0, [r0, #4]
	cmp r0, #1
	bne _0225A9EC
	ldrh r0, [r5, #0x1a]
	mov r1, #0x20
	mov r2, #0
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x10]
	str r1, [sp]
	mov r1, #6
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0xc
	str r1, [sp, #8]
	mov r1, #0
	str r1, [sp, #0xc]
	lsl r1, r4, #0x18
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
	ldr r0, [r7]
	bl CopyToBgTilemapRect
	ldr r0, [r7]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
_0225A9EC:
	add r6, r6, #1
	add r4, r4, #6
	cmp r6, #3
	blt _0225A9A2
_0225A9F4:
	add r0, r5, #0
	add r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0225AA34
	add r0, r5, #0
	add r0, #0x25
	ldrb r1, [r0]
	ldr r0, [sp, #0x1c]
	cmp r0, r1
	beq _0225AA34
	add r1, r5, #0
	add r1, #0x25
	strb r0, [r1]
	ldr r2, [r5, #0x20]
	add r1, r5, #0
	add r1, #0x26
	ldrb r1, [r1]
	add r5, #0x25
	ldr r3, [r2, #0xc]
	ldrb r2, [r5]
	mov r0, #0x1f
	lsl r1, r1, #5
	lsl r2, r2, #5
	add r2, r3, r2
	mov r3, #0x20
	bl GF_CreateNewVramTransferTask
	cmp r0, #0
	bne _0225AA34
	bl GF_AssertFail
_0225AA34:
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov48_0225A95C


	thumb_func_start ov48_0225AA38
ov48_0225AA38: ; 0x0225AA38
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	cmp r4, #3
	blo _0225AA48
	bl GF_AssertFail
_0225AA48:
	add r0, r5, r4
	strb r6, [r0, #4]
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov48_0225AA38

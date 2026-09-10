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

	thumb_func_start ov48_0225AA5C
ov48_0225AA5C: ; 0x0225AA5C
	push {r3, r4, lr}
	sub sp, #0x1c
	add r4, r2, #0
	ldrh r2, [r0, #0x18]
	cmp r2, #0
	beq _0225AAA8
	ldrh r2, [r0, #0x1a]
	lsl r1, r1, #0x18
	lsr r3, r1, #0x18
	lsl r2, r2, #2
	add r0, r0, r2
	ldr r0, [r0, #0x10]
	mov r2, #0x20
	str r2, [sp]
	mov r2, #1
	str r2, [sp, #4]
	add r2, r0, #0
	add r2, #0xc
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
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
_0225AAA8:
	add sp, #0x1c
	pop {r3, r4, pc}
	thumb_func_end ov48_0225AA5C


	thumb_func_start ov48_0225AAAC
ov48_0225AAAC: ; 0x0225AAAC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x88
	str r0, [sp, #0x2c]
	str r2, [sp, #0x30]
	mov r0, #0
	add r5, r1, #0
	add r2, sp, #0x44
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r2, #0x4b
	ldr r0, [sp, #0x2c]
	lsl r2, r2, #2
	str r3, [sp, #0x34]
	bl memset
	ldr r0, [sp, #0x2c]
	mov r2, #2
	strh r2, [r0, #0x30]
	mov r1, #0x80
	strh r1, [r0, #0x32]
	ldr r0, [r5, #4]
	ldr r3, [sp, #0x34]
	str r0, [sp, #0x44]
	add r0, sp, #0x64
	str r0, [sp, #0x48]
	mov r0, #0x40
	str r0, [sp, #0x58]
	str r3, [sp, #0x60]
	str r2, [sp, #0x5c]
	mov r3, #0
	str r3, [sp]
	str r2, [sp, #4]
	mov r2, #0xc
	str r2, [sp, #8]
	ldr r2, [sp, #0x34]
	add r0, #0xf4
	str r2, [sp, #0xc]
	add r1, #0xc4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	mov r2, #0x14
	bl AddPlttResObjFromOpenNarc
	ldr r1, [sp, #0x2c]
	str r0, [r1, #0x70]
	bl SpriteTransfer_CreatePlttTransferTask
	cmp r0, #0
	bne _0225AB18
	bl GF_AssertFail
_0225AB18:
	ldr r0, [sp, #0x2c]
	ldr r0, [r0, #0x70]
	bl sub_0200A740
	mov r0, #0x15
	str r0, [sp, #0x40]
	ldr r4, [sp, #0x2c]
	mov r0, #0x16
	str r0, [sp, #0x3c]
	mov r0, #0x17
	mov r6, #0
	str r0, [sp, #0x38]
	add r7, r4, #0
_0225AB32:
	str r6, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	mov r1, #0x51
	str r0, [sp, #8]
	mov r0, #0x13
	lsl r0, r0, #4
	lsl r1, r1, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [sp, #0x40]
	mov r3, #0
	bl AddCharResObjFromOpenNarc
	str r0, [r4, #0x6c]
	mov r1, #0x51
	str r6, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	lsl r1, r1, #2
	str r0, [sp, #8]
	mov r0, #0x4e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [sp, #0x3c]
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	str r0, [r4, #0x74]
	mov r1, #0x51
	str r6, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	lsl r1, r1, #2
	str r0, [sp, #8]
	mov r0, #0x4f
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [sp, #0x38]
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	str r0, [r4, #0x78]
	ldr r0, [r4, #0x6c]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	cmp r0, #0
	bne _0225ABA0
	bl GF_AssertFail
_0225ABA0:
	ldr r0, [r4, #0x6c]
	bl sub_0200A740
	mov r0, #0
	str r6, [sp]
	mvn r0, r0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r6, #0
	str r0, [sp, #0x14]
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r2, #0
	str r0, [sp, #0x18]
	mov r0, #0x4e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r3, r6, #0
	str r0, [sp, #0x1c]
	mov r0, #0x4f
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	str r0, [sp, #0x20]
	mov r0, #0
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, sp, #0x64
	bl CreateSpriteResourcesHeader
	add r0, sp, #0x44
	bl Sprite_Create
	str r0, [r7, #0x3c]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r1, #1
	ldr r0, [r7, #0x3c]
	lsl r1, r1, #0xc
	bl Sprite_SetAnimSpeed
	ldr r0, [sp, #0x40]
	add r6, r6, #1
	add r0, r0, #3
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x3c]
	add r4, #0x10
	add r0, r0, #3
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x38]
	add r7, r7, #4
	add r0, r0, #3
	str r0, [sp, #0x38]
	cmp r6, #0xc
	blt _0225AB32
	ldr r0, [sp, #0x2c]
	bl ov48_0225AD38
	mov r1, #0
	ldr r0, [sp, #0x30]
	add r2, r1, #0
	bl ov48_0225A668
	add sp, #0x88
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov48_0225AAAC


	thumb_func_start ov48_0225AC34
ov48_0225AC34: ; 0x0225AC34
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _0225ACA8 ; =0x000005D8
	mov r1, #0
	bl StopSE
	mov r0, #0
	ldr r7, [sp]
	str r0, [sp, #8]
_0225AC4A:
	ldr r0, [sp]
	ldr r0, [r0, #0x3c]
	bl Sprite_Delete
	ldr r0, [r7, #0x6c]
	bl SpriteTransfer_DeleteCharTransferTask
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _0225AC72
	ldr r0, [r7, #0x70]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r0, #0x4d
	ldr r1, [sp, #4]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r1, [r7, #0x70]
	bl DestroySingle2DGfxResObj
_0225AC72:
	ldr r5, [sp, #4]
	mov r4, #0
	add r6, r7, #0
_0225AC78:
	cmp r4, #1
	beq _0225AC88
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	ldr r1, [r6, #0x6c]
	bl DestroySingle2DGfxResObj
_0225AC88:
	add r4, r4, #1
	add r6, r6, #4
	add r5, r5, #4
	cmp r4, #4
	blt _0225AC78
	ldr r0, [sp]
	add r7, #0x10
	add r0, r0, #4
	str r0, [sp]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #0xc
	blt _0225AC4A
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0225ACA8: .word 0x000005D8
	thumb_func_end ov48_0225AC34


	thumb_func_start ov48_0225ACAC
ov48_0225ACAC: ; 0x0225ACAC
	add r1, r0, #0
	add r2, r0, #0
	mov r3, #0
	add r1, #0x34
	strb r3, [r1]
	add r2, #0x34
	strb r3, [r2, #1]
	strb r3, [r2, #2]
	add r1, r0, #0
	strb r3, [r2, #3]
	add r2, r0, #0
	add r1, #0x38
	strb r3, [r1]
	add r2, #0x38
	strb r3, [r2, #1]
	strb r3, [r2, #2]
	strb r3, [r2, #3]
	mov r1, #2
	strh r1, [r0, #0x30]
	mov r1, #0x80
	strh r1, [r0, #0x32]
	bx lr
	thumb_func_end ov48_0225ACAC


	thumb_func_start ov48_0225ACD8
ov48_0225ACD8: ; 0x0225ACD8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r0, r5, r4
	add r6, r5, #0
	str r3, [sp]
	mov r1, #1
	add r0, #0x34
	strb r1, [r0]
	add r6, #0x38
	add r0, r2, #0
	bl ov48_0225B050
	strb r0, [r6, r4]
	lsl r7, r4, #4
	ldrb r2, [r6, r4]
	mov r1, #0x30
	ldr r3, _0225AD34 ; =ov48_0225B330
	mul r1, r2
	add r1, r3, r1
	add r0, r5, r7
	add r1, r1, r7
	bl ov48_0225AE3C
	ldr r0, [sp]
	cmp r0, #0x18
	bhs _0225AD30
	bl ov48_0225B050
	ldrb r1, [r6, r4]
	cmp r0, r1
	bne _0225AD30
	cmp r4, #2
	bhs _0225AD30
	add r0, r4, #1
	lsl r0, r0, #4
	add r0, r5, r0
	mov r1, #1
	bl ov48_0225AE5C
	add r0, r5, r7
	mov r1, #1
	bl ov48_0225AE58
_0225AD30:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225AD34: .word ov48_0225B330
	thumb_func_end ov48_0225ACD8

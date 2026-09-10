	.include "asm/macros.inc"
	.include "overlay_27.inc"
	.include "global.inc"

	.text
	.public _0225CEBC
	.public ov27_02259F80
	.public ov27_0225A19C
	.public ov27_0225A320
	.public ov27_0225A4D0
	.public ov27_0225A530
	.public ov27_0225A594
	.public ov27_0225A61C
	.public ov27_0225A690
	.public ov27_0225A714
	.public ov27_0225A7FC
	.public ov27_0225A89C
	.public ov27_0225A8E8
	.public ov27_0225A9C0
	.public ov27_0225AA7C
	.public ov27_0225AAD4
	.public ov27_0225AC00
	.public ov27_0225AD0C
	.public ov27_0225AEA8
	.public ov27_0225B010
	.public ov27_0225B360
	.public ov27_0225B398
	.public ov27_0225B404
	.public ov27_0225B4D8
	.public ov27_0225B630
	.public ov27_0225BB6C
	.public ov27_0225BC34
	.public ov27_0225BC84
	.public ov27_0225BCE8
	.public ov27_0225BD50
	.public ov27_0225BDFC
	.public ov27_0225BED8
	.public ov27_0225BF84
	.public ov27_0225BFCC
	.public ov27_0225C088
	.public ov27_0225C10C
	.public ov27_0225C170
	.public ov27_0225C1AC
	.public ov27_0225C1EC
	.public ov27_0225C250
	.public ov27_0225C398
	.public ov27_0225C434
	.public ov27_0225C4AC
	.public ov27_0225C540
	.public ov27_0225C618
	.public ov27_0225C72C
	.public ov27_0225C80C
	.public ov27_0225C9F8
	.public ov27_0225CA14
	.public ov27_0225CA98
	.public ov27_0225CD18
	.public ov27_0225CD94
	.public ov27_0225CEAC
	.public ov27_0225CEC4
	.public ov27_0225CECC
	.public ov27_0225CED8
	.public ov27_0225CEEC
	.public ov27_0225CEF0
	.public ov27_0225CEF4
	.public ov27_0225CF10
	.public ov27_0225CF3C
	.public ov27_0225CF68
	.public ov27_0225CF94
	.public ov27_0225CFC8
	.public ov27_0225D000
	.public ov27_0225D01C
	.public ov27_0225D038
	.public ov27_0225D05C
	.public ov27_0225D074
	.public ov27_0225D0B4
	.public ov27_0225D108
	.public ov27_0225D110
	.public ov27_0225D118
	.public ov27_0225D11A
	.public ov27_0225D120
	.public ov27_0225D12C
	.public ov27_0225D138
	.public ov27_0225D144
	.public ov27_0225D154
	.public ov27_0225D164
	.public ov27_0225D174
	.public ov27_0225D188
	.public ov27_0225D19C
	.public ov27_0225D1B4
	.public ov27_0225D1CC
	.public ov27_0225D1E4
	.public ov27_0225D200
	.public ov27_0225D21C
	.public ov27_0225D23C
	.public ov27_0225D25C
	.public ov27_0225D27C
	.public ov27_0225D2A0
	.public ov27_0225D2C8
	.public ov27_0225D2F8
	.public ov27_0225D330
	.public ov27_0225D370
	.public ov27_0225D38C
	.public ov27_0225D3A8
	.public ov27_0225D3C4
	.public ov27_0225D3C5
	.public ov27_0225D3C6
	.public ov27_0225D480
	.public ov27_0225D49C
	.public ov27_0225D4B8
	.public ov27_0225D4D4

	.public ov27_0225A2C8
	.public ov27_0225A2CC
	.public ov27_0225A2EC
	.public ov27_0225A468
	.public ov27_0225A48C
	.public ov27_0225A4B8
	.public ov27_0225A66C
	.public ov27_0225A7B0
	.public ov27_0225A7DC
	.public ov27_0225A86C
	.public ov27_0225AA60
	.public ov27_0225AE8C
	.public ov27_0225B4AC
	.public ov27_0225BB38
	.public ov27_0225BD44
	.public ov27_0225BDAC
	.public ov27_0225BDC8
	.public ov27_0225BDDC
	.public ov27_0225BEB0
	.public ov27_0225C01C
	.public ov27_0225C044
	.public ov27_0225C06C
	.public ov27_0225C0E0
	.public ov27_0225C238
	.public ov27_0225C248
	.public ov27_0225C24C
	.public ov27_0225C418
	.public ov27_0225C41C
	.public ov27_0225C5E4
	.public ov27_0225C6F8
	.public ov27_0225C8D0
	.public ov27_0225C914
	.public ov27_0225C930
	.public ov27_0225C944
	.public ov27_0225C94C
	.public ov27_0225C988
	.public ov27_0225C994
	.public ov27_0225C9CC
	.public ov27_0225C9E4
	.public ov27_0225CA68
	.public ov27_0225CC90
	.public ov27_0225CCBC
	.public ov27_0225CCE0
	.public ov27_0225CD74

	thumb_func_start ov27_0225AEA8
ov27_0225AEA8: ; 0x0225AEA8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	mov ip, r0
	ldr r0, [sp, #0x44]
	str r1, [sp, #0x10]
	lsl r1, r0, #3
	ldr r0, _0225B004 ; =ov27_0225CFC8
	add r5, r3, #0
	add r0, r0, r1
	ldrb r1, [r5, r0]
	mov r0, #1
	mov r6, #0xe ; NARC_a_0_1_4
	add r4, r2, #0
	mov r2, #0x12
	ldr r7, [sp, #0x40]
	str r6, [sp, #0x20]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x18]
	cmp r1, #0xd
	beq _0225AF22
	cmp r1, #2
	bne _0225AEDE
	ldr r0, [sp, #0x3c]
	cmp r0, #1
	bne _0225AEDE
	mov r2, #0x1b
	b _0225AF22
_0225AEDE:
	ldr r0, _0225B008 ; =ov27_0225CF94
	lsl r1, r1, #2
	ldrh r2, [r0, r1]
	ldr r0, _0225B00C ; =0x0000FFFF
	cmp r2, r0
	bne _0225AF22
	mov r0, ip
	bl FieldSystem_BugContest_Get
	str r0, [sp, #0x14]
	cmp r0, #0
	bne _0225AEFA
	bl GF_AssertFail
_0225AEFA:
	ldr r0, [sp, #0x14]
	ldrb r0, [r0, #0x17]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _0225AF20
	mov r0, #0
	str r0, [sp, #0x1c]
	mov r0, #3
	mov r6, #0x14 ; NARC_poketool_icongra_poke_icon
	str r0, [sp, #0x18]
	bl sub_02074490
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x14]
	ldr r0, [r0, #0x10]
	bl Pokemon_GetIconNaix
	add r2, r0, #0
	b _0225AF22
_0225AF20:
	mov r2, #0x12
_0225AF22:
	cmp r5, #7
	bne _0225AF4A
	mov r0, #0
	str r0, [sp, #0x1c]
	add r0, r7, #0
	mov r6, #0x12 ; NARC_itemtool_itemdata_item_icon
	bl Bag_GetRegisteredItem1
	mov r1, #2
	bl GetItemIndexMapping
	str r0, [sp, #0x20]
	add r0, r7, #0
	bl Bag_GetRegisteredItem1
	mov r1, #1
	bl GetItemIndexMapping
	add r2, r0, #0
	b _0225AFAC
_0225AF4A:
	cmp r5, #8
	bne _0225AF72
	mov r0, #0
	str r0, [sp, #0x1c]
	add r0, r7, #0
	mov r6, #0x12 ; NARC_itemtool_itemdata_item_icon
	bl Bag_GetRegisteredItem2
	mov r1, #2
	bl GetItemIndexMapping
	str r0, [sp, #0x20]
	add r0, r7, #0
	bl Bag_GetRegisteredItem2
	mov r1, #1
	bl GetItemIndexMapping
	add r2, r0, #0
	b _0225AFAC
_0225AF72:
	cmp r5, #9
	bne _0225AF82
	mov r0, #7
	str r0, [sp, #0x20]
	mov r0, #4
	mov r2, #0x46
	str r0, [sp, #0x18]
	b _0225AFAC
_0225AF82:
	cmp r5, #0xa
	bne _0225AFAC
	ldr r0, [sp, #0x44]
	bl ov27_0225AE8C
	add r5, r0, #0
	mov r0, #0
	str r0, [sp, #0x1c]
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	mov r1, #2
	mov r6, #0x12 ; NARC_itemtool_itemdata_item_icon
	bl GetItemIndexMapping
	str r0, [sp, #0x20]
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	mov r1, #1
	bl GetItemIndexMapping
	add r2, r0, #0
_0225AFAC:
	ldr r0, [sp, #0x38]
	ldr r3, [sp, #0x1c]
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	ldr r0, [sp, #0x10]
	add r1, r6, #0
	ldr r0, [r0]
	bl AddCharResObjFromNarc
	str r0, [r4]
	ldr r0, [sp, #0x38]
	ldr r2, [sp, #0x20]
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	add r1, r6, #0
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	mov r3, #0
	ldr r0, [r0, #4]
	bl AddPlttResObjFromNarc
	str r0, [r4, #4]
	ldr r0, [r4]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	ldr r0, [r4]
	bl sub_0200A740
	ldr r0, [r4, #4]
	bl SpriteTransfer_CreatePlttTransferTask
	ldr r0, [r4, #4]
	bl sub_0200A740
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_0225B004: .word ov27_0225CFC8
_0225B008: .word ov27_0225CF94
_0225B00C: .word 0x0000FFFF
	thumb_func_end ov27_0225AEA8


	thumb_func_start ov27_0225B010
ov27_0225B010: ; 0x0225B010
	push {r4, r5, r6, r7, lr}
	sub sp, #0x6c
	add r5, r0, #0
	mov r0, #0x81
	lsl r0, r0, #2
	ldr r4, _0225B350 ; =ov27_0225CF3C
	mov r7, #0
	add r6, r5, r0
_0225B020:
	ldr r3, [r4]
	mov r0, #0
	str r3, [sp]
	mvn r0, r0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r7, #0
	str r0, [sp, #0x14]
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, #0x64
	str r0, [sp, #0x18]
	mov r0, #0x53
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, r1, #0
	str r0, [sp, #0x1c]
	mov r0, #0x15
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	str r0, [sp, #0x20]
	mov r0, #0
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, r6, #0
	bl CreateSpriteResourcesHeader
	add r7, r7, #1
	add r4, r4, #4
	add r6, #0x24
	cmp r7, #0xb
	blt _0225B020
	ldr r0, [r5, #0x18]
	add r1, sp, #0x3c
	str r0, [sp, #0x3c]
	mov r0, #0x81
	lsl r0, r0, #2
	add r7, r5, r0
	mov r0, #0
	str r0, [sp, #0x2c]
	str r0, [sp, #0x4c]
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	str r0, [sp, #0x58]
	ldr r0, [sp, #0x2c]
	str r7, [sp, #0x40]
	strh r0, [r1, #0x20]
	mov r0, #1
	str r0, [sp, #0x60]
	mov r0, #2
	str r0, [sp, #0x64]
	mov r0, #8
	ldr r6, _0225B354 ; =ov27_0225D038
	str r0, [sp, #0x68]
	add r4, r5, #0
_0225B0A0:
	ldrh r0, [r6]
	str r7, [sp, #0x40]
	cmp r0, #0
	beq _0225B0BA
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0225B0C8
_0225B0BA:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0225B0C8:
	bl _ffix
	str r0, [sp, #0x44]
	ldrh r0, [r6, #2]
	cmp r0, #0
	beq _0225B0E6
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0225B0F4
_0225B0E6:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0225B0F4:
	bl _ffix
	mov r1, #1
	lsl r1, r1, #0x14
	add r0, r0, r1
	str r0, [sp, #0x48]
	add r0, sp, #0x3c
	bl Sprite_CreateAffine
	mov r1, #0x39
	lsl r1, r1, #4
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetPriority
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAffineOverwriteMode
	ldr r0, [sp, #0x2c]
	add r7, #0x24
	add r0, r0, #1
	add r6, r6, #4
	add r4, r4, #4
	str r0, [sp, #0x2c]
	cmp r0, #9
	blt _0225B0A0
	mov r0, #9
	str r0, [sp, #0x30]
	mov r0, #0xd2
	lsl r0, r0, #2
	add r4, r5, #0
	mov r7, #0x3f
	add r0, r5, r0
	ldr r6, _0225B358 ; =ov27_0225D05C
	add r4, #0x24
	lsl r7, r7, #0x18
	str r0, [sp, #0x38]
_0225B154:
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x40]
	ldrh r0, [r6]
	cmp r0, #0
	beq _0225B16E
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _0225B17A
_0225B16E:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_0225B17A:
	bl _ffix
	str r0, [sp, #0x44]
	ldrh r0, [r6, #2]
	cmp r0, #0
	beq _0225B196
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _0225B1A2
_0225B196:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_0225B1A2:
	bl _ffix
	mov r1, #1
	lsl r1, r1, #0x14
	add r0, r0, r1
	str r0, [sp, #0x48]
	add r0, sp, #0x3c
	bl Sprite_CreateAffine
	mov r1, #0x39
	lsl r1, r1, #4
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #2
	bl Sprite_SetPriority
	ldr r0, [sp, #0x30]
	add r6, r6, #4
	add r0, r0, #1
	add r4, r4, #4
	str r0, [sp, #0x30]
	cmp r0, #0xf
	blt _0225B154
	ldr r0, _0225B35C ; =0x0000051C
	ldr r0, [r5, r0]
	lsl r0, r0, #0x1b
	lsr r1, r0, #0x1c
	sub r0, r1, #1
	cmp r0, #2
	bhi _0225B27E
	cmp r1, #1
	bne _0225B1F6
	mov r0, #0x90
	str r0, [sp, #0x34]
	b _0225B200
_0225B1F6:
	sub r0, r1, #2
	cmp r0, #1
	bhi _0225B200
	mov r0, #0x68
	str r0, [sp, #0x34]
_0225B200:
	mov r0, #0xdb
	lsl r0, r0, #2
	add r0, r5, r0
	str r0, [sp, #0x40]
	mov r0, #0x19
	lsl r0, r0, #0xe
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	bl _ffix
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x34]
	cmp r0, #0
	ble _0225B238
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0225B246
_0225B238:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0225B246:
	bl _ffix
	mov r1, #1
	lsl r1, r1, #0x14
	add r0, r0, r1
	str r0, [sp, #0x48]
	add r0, sp, #0x3c
	bl Sprite_CreateAffine
	mov r1, #0xf3
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0xf3
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetPriority
	mov r0, #0xf3
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #6
	bl Sprite_SetAnimCtrlSeq
_0225B27E:
	ldr r0, _0225B35C ; =0x0000051C
	ldr r0, [r5, r0]
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1c
	cmp r0, #2
	bne _0225B2D2
	ldr r0, [r5, #0x10]
	bl FieldSystem_BugContest_Get
	add r4, r0, #0
	bne _0225B298
	bl GF_AssertFail
_0225B298:
	ldrb r0, [r4, #0x17]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _0225B2E2
	mov r0, #0xea
	lsl r0, r0, #2
	mov r3, #1
	ldr r0, [r5, r0]
	mov r1, #0x68
	mov r2, #0x88
	lsl r3, r3, #0x14
	bl Sprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r4, #0x10]
	bl Pokemon_GetIconPalette
	add r1, r0, #0
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Sprite_SetPalOffsetRespectVramOffset
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #6
	bl Sprite_SetAnimCtrlSeq
	b _0225B2E2
_0225B2D2:
	cmp r0, #3
	bne _0225B2E2
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0225B2E2:
	mov r0, #0xed
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0xee
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #8
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0xef
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0xf
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #5
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0xc
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0xf1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetPriority
	add r0, r5, #0
	bl ov27_0225A4B8
	add r0, r5, #0
	mov r1, #1
	bl ov27_0225A9C0
	add r0, r5, #0
	bl ov27_0225AA7C
	add sp, #0x6c
	pop {r4, r5, r6, r7, pc}
	nop
_0225B350: .word ov27_0225CF3C
_0225B354: .word ov27_0225D038
_0225B358: .word ov27_0225D05C
_0225B35C: .word 0x0000051C
	thumb_func_end ov27_0225B010


	thumb_func_start ov27_0225B360
ov27_0225B360: ; 0x0225B360
	push {r3, r4, r5, r6}
	mov r5, #0xc
	mul r5, r0
	ldr r6, _0225B394 ; =ov27_0225D0B4
	lsl r0, r1, #1
	mov r4, #0
	add r5, r6, r5
	add r0, r1, r0
	mvn r4, r4
	mov r3, #0
	add r5, r5, r0
_0225B376:
	ldrb r1, [r5]
	lsl r0, r1, #3
	ldrb r0, [r2, r0]
	cmp r0, #0
	beq _0225B384
	add r4, r1, #0
	b _0225B38C
_0225B384:
	add r3, r3, #1
	add r5, r5, #1
	cmp r3, #3
	blt _0225B376
_0225B38C:
	add r0, r4, #0
	pop {r3, r4, r5, r6}
	bx lr
	nop
_0225B394: .word ov27_0225D0B4
	thumb_func_end ov27_0225B360


	thumb_func_start ov27_0225B398
ov27_0225B398: ; 0x0225B398
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	str r1, [sp]
	cmp r1, #7
	blt _0225B3A6
	bl GF_AssertFail
_0225B3A6:
	ldr r0, _0225B3F0 ; =0x000004CC
	mov r4, #0
	add r5, r4, #0
	add r7, r6, r0
_0225B3AE:
	ldr r0, _0225B3F4 ; =0x0000051C
	ldr r0, [r6, r0]
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1c
	lsl r1, r0, #3
	ldr r0, _0225B3F8 ; =ov27_0225CFC8
	add r0, r0, r1
	ldrb r1, [r4, r0]
	ldr r0, _0225B3FC ; =ov27_0225CF94
	lsl r2, r1, #2
	ldrh r0, [r0, r2]
	mov r2, #0
	cmp r1, #0xd
	beq _0225B3E4
	ldr r1, _0225B400 ; =0x0000FFFF
	cmp r0, r1
	beq _0225B3E4
	ldr r0, [sp]
	cmp r4, r0
	bne _0225B3D8
	mov r2, #0x10
_0225B3D8:
	lsl r0, r2, #1
	add r0, r7, r0
	add r1, r5, #0
	mov r2, #0x20
	bl GXS_LoadOBJPltt
_0225B3E4:
	add r4, r4, #1
	add r5, #0x20
	cmp r4, #7
	blt _0225B3AE
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225B3F0: .word 0x000004CC
_0225B3F4: .word 0x0000051C
_0225B3F8: .word ov27_0225CFC8
_0225B3FC: .word ov27_0225CF94
_0225B400: .word 0x0000FFFF
	thumb_func_end ov27_0225B398


	thumb_func_start ov27_0225B404
ov27_0225B404: ; 0x0225B404
	push {r3, r4, r5, lr}
	ldr r1, _0225B4A8 ; =gSystem
	add r5, r0, #0
	ldr r1, [r1, #0x48]
	mov r4, #0
	mov r2, #0x40
	mvn r4, r4
	ldr r0, [r5, #0x14]
	tst r2, r1
	beq _0225B41C
	mov r4, #0
	b _0225B438
_0225B41C:
	mov r2, #0x80
	tst r2, r1
	beq _0225B426
	mov r4, #1
	b _0225B438
_0225B426:
	mov r2, #0x20
	tst r2, r1
	beq _0225B430
	mov r4, #2
	b _0225B438
_0225B430:
	mov r2, #0x10
	tst r1, r2
	beq _0225B438
	mov r4, #3
_0225B438:
	cmp r4, #0
	blt _0225B448
	mov r2, #0x47
	lsl r2, r2, #4
	add r1, r4, #0
	add r2, r5, r2
	bl ov27_0225B360
_0225B448:
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0225B4A6
	ldr r1, [r5, #0x14]
	cmp r1, r0
	beq _0225B4A6
	str r0, [r5, #0x14]
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
	cmp r4, #1
	bhi _0225B478
	ldr r0, [r5, #0x14]
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #3
	bl Sprite_SetAnimCtrlSeq
	b _0225B490
_0225B478:
	sub r0, r4, #2
	cmp r0, #1
	bhi _0225B490
	ldr r0, [r5, #0x14]
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0x39
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #1
	bl Sprite_SetAnimCtrlSeq
_0225B490:
	ldr r1, [r5, #0x14]
	add r0, r5, #0
	bl ov27_0225B398
	ldr r1, [r5, #0x14]
	add r0, r5, #0
	bl ov27_0225C170
	ldr r1, [r5, #0x10]
	add r1, #0xd3
	strb r0, [r1]
_0225B4A6:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0225B4A8: .word gSystem
	thumb_func_end ov27_0225B404

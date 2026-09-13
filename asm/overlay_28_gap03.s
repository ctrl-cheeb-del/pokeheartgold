	.include "asm/macros.inc"
	.include "overlay_28.inc"
	.include "global.inc"

	.public ov28_0225D520
	.public ov28_0225D5EC
	.public ov28_0225D624
	.public ov28_0225D628
	.public ov28_0225D650
	.public ov28_0225D6E0
	.public ov28_0225D6FC
	.public ov28_0225D764
	.public ov28_0225D7C4
	.public ov28_0225D7E0
	.public ov28_0225D878
	.public ov28_0225D898
	.public ov28_0225D8D0
	.public ov28_0225D8EC
	.public ov28_0225D910
	.public ov28_0225D92C
	.public ov28_0225D9BC
	.public ov28_0225DA1C
	.public ov28_0225DA74
	.public ov28_0225DB54
	.public ov28_0225DB8C
	.public ov28_0225DBFC
	.public ov28_0225DC2C
	.public DowsingMchn_GetHiddenItemLocs
	.public DowsingMchn_FreeHiddenItemLocs
	.public ov28_0225DD58
	.public ov28_0225DE04
	.public ov28_0225DE64
	.public ov28_0225DE78
	.public ov28_0225DE88
	.public ov28_0225DE98
	.public ov28_0225DEB0
	.public ov28_0225DF04
	.public ov28_0225DF14
	.public ov28_0225DFA4
	.public ov28_0225DFBC
	.public ov28_0225E054
	.public ov28_0225E060
	.public ov28_0225E0DC
	.public ov28_0225E0F4
	.public ov28_0225E1A4
	.public ov28_0225E31C
	.public ov28_0225E374
	.public ov28_0225E3BC
	.public ov28_0225E424
	.public ov28_0225E43C
	.public ov28_0225E51C
	.public ov28_0225E578
	.public ov28_0225E730
	.public ov28_0225E7D4
	.public ov28_0225E810
	.public ov28_0225E8B8
	.public ov28_0225E900
	.public ov28_0225E938
	.public ov28_0225E9E0
	.public ov28_0225EA58
	.public _0225EA7C
	.public ov28_0225EA80
	.public ov28_0225EA84
	.public ov28_0225EA88
	.public ov28_0225EA90
	.public ov28_0225EA91
	.public ov28_0225EA9A
	.public ov28_0225EA9E
	.public ov28_0225EAA2
	.public ov28_0225EAA6
	.public ov28_0225EAAC
	.public ov28_0225EAC0
	.public ov28_0225EADC
	.public ov28_0225EAF8
	.public ov28_0225EB14
	.public ov28_0225EB32
	.public ov28_0225EB52
	.public ov28_0225EB7C
	.public ov28_0225EB84

	.text

thumb_func_start ov28_0225D92C
ov28_0225D92C: ; 0x0225D92C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [sp, #0x30]
	add r6, r2, #0
	str r0, [sp]
	mov r0, #2
	add r4, r1, #0
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	add r2, r3, #0
	ldr r0, [r4]
	add r1, r6, #0
	mov r3, #1
	bl AddCharResObjFromOpenNarc
	str r0, [r5]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	ldr r0, [r5]
	bl sub_0200A740
	ldr r0, [sp, #0x34]
	ldr r2, [sp, #0x20]
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	add r1, r6, #0
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	mov r3, #0
	bl AddPlttResObjFromOpenNarc
	str r0, [r5, #4]
	bl SpriteTransfer_CreatePlttTransferTask
	ldr r0, [r5, #4]
	bl sub_0200A740
	ldr r0, [sp, #0x38]
	ldr r2, [sp, #0x24]
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	ldr r0, [r4, #8]
	add r1, r6, #0
	mov r3, #1
	bl AddCellOrAnimResObjFromOpenNarc
	str r0, [r5, #8]
	ldr r0, [sp, #0x3c]
	ldr r2, [sp, #0x28]
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	add r1, r6, #0
	mov r3, #1
	bl AddCellOrAnimResObjFromOpenNarc
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov28_0225D92C

thumb_func_start ov28_0225D9BC
ov28_0225D9BC: ; 0x0225D9BC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	add r7, r2, #0
	add r6, r3, #0
	bl GF2DGfxResObj_GetResID
	str r0, [sp, #0x2c]
	ldr r0, [r5, #4]
	bl GF2DGfxResObj_GetResID
	str r0, [sp, #0x30]
	ldr r0, [r5, #8]
	bl GF2DGfxResObj_GetResID
	str r0, [sp, #0x34]
	ldr r0, [r5, #0xc]
	bl GF2DGfxResObj_GetResID
	str r0, [sp]
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	ldr r1, [r4]
	ldr r2, [sp, #0x30]
	str r1, [sp, #0x14]
	ldr r1, [r4, #4]
	ldr r3, [sp, #0x34]
	str r1, [sp, #0x18]
	ldr r1, [r4, #8]
	str r1, [sp, #0x1c]
	ldr r1, [r4, #0xc]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	add r0, r7, #0
	bl CreateSpriteResourcesHeader
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov28_0225D9BC

thumb_func_start ov28_0225DA1C
ov28_0225DA1C: ; 0x0225DA1C
	push {r4, r5, r6, lr}
	sub sp, #0x30
	add r5, r3, #0
	ldr r3, [r0, #0x24]
	lsl r6, r1, #2
	str r3, [sp]
	str r2, [sp, #4]
	ldrb r2, [r5]
	lsl r2, r2, #0xc
	str r2, [sp, #8]
	ldrb r2, [r5, #1]
	lsl r3, r2, #0xc
	mov r2, #1
	lsl r2, r2, #0x14
	add r3, r3, r2
	lsr r2, r2, #8
	str r3, [sp, #0xc]
	mov r3, #0
	str r3, [sp, #0x10]
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	str r2, [sp, #0x1c]
	add r2, sp, #0
	strh r3, [r2, #0x20]
	ldrb r2, [r5, #2]
	str r2, [sp, #0x24]
	mov r2, #2
	str r2, [sp, #0x28]
	mov r2, #8
	str r2, [sp, #0x2c]
	mov r2, #6
	lsl r2, r2, #6
	add r4, r0, r2
	add r0, sp, #0
	bl Sprite_CreateAffine
	str r0, [r4, r6]
	ldrb r1, [r5, #3]
	ldr r0, [r4, r6]
	bl Sprite_SetAnimCtrlSeq
	add sp, #0x30
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov28_0225DA1C

thumb_func_start ov28_0225DA74
ov28_0225DA74: ; 0x0225DA74
	push {r4, r5, lr}
	sub sp, #0x44
	add r5, r0, #0
	mov r0, #0xe
	mov r1, #8
	bl NARC_New
	add r4, r0, #0
	mov r0, #7
	str r0, [sp]
	mov r0, #0x44
	str r0, [sp, #4]
	mov r0, #0x45
	str r0, [sp, #8]
	mov r0, #4
	ldr r1, _0225DB40 ; =0x000001F2
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	add r0, r1, #0
	str r1, [sp, #0x1c]
	sub r0, #0x92
	sub r1, #0xa2
	add r0, r5, r0
	add r1, r5, r1
	add r2, r4, #0
	mov r3, #0x46
	bl ov28_0225D92C
	add r0, r4, #0
	bl NARC_Delete
	mov r1, #0x16
	lsl r1, r1, #4
	add r0, r5, r1
	sub r1, #0x10
	add r1, r5, r1
	add r2, sp, #0x20
	mov r3, #1
	bl ov28_0225D9BC
	ldr r3, _0225DB44 ; =ov28_0225EA9A
	add r0, r5, #0
	mov r1, #0
	add r2, sp, #0x20
	bl ov28_0225DA1C
	ldr r3, _0225DB48 ; =ov28_0225EA9E
	add r0, r5, #0
	mov r1, #1
	add r2, sp, #0x20
	bl ov28_0225DA1C
	ldr r3, _0225DB4C ; =ov28_0225EAA2
	add r0, r5, #0
	mov r1, #2
	add r2, sp, #0x20
	bl ov28_0225DA1C
	ldr r3, _0225DB50 ; =ov28_0225EAA6
	add r0, r5, #0
	mov r1, #3
	add r2, sp, #0x20
	bl ov28_0225DA1C
	ldr r0, [r5, #0x18]
	bl FieldSystem_GetPlayerAvatar
	bl PlayerAvatar_CheckRunningShoesLock
	cmp r0, #0
	bne _0225DB22
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0xb
	bl Sprite_SetAnimCtrlSeq
	add sp, #0x44
	pop {r4, r5, pc}
_0225DB22:
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #4
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #7
	bl Sprite_SetAnimCtrlSeq
	add sp, #0x44
	pop {r4, r5, pc}
	nop
_0225DB40: .word 0x000001F2
_0225DB44: .word ov28_0225EA9A
_0225DB48: .word ov28_0225EA9E
_0225DB4C: .word ov28_0225EAA2
_0225DB50: .word ov28_0225EAA6
	thumb_func_end ov28_0225DA74

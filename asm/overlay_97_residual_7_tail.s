	.include "asm/macros.inc"
	.include "overlay_97.inc"
	.include "global.inc"

	.text
	.public _0221FC98
	.public ov97_0221E5D4
	.public ov97_0221E700
	.public ov97_0221E898
	.public ov97_0221E91C
	.public ov97_0221E98C
	.public ov97_0221EA88
	.public ov97_0221EB38
	.public ov97_0221EC14
	.public ov97_0221EDE4
	.public ov97_0221EEA4
	.public ov97_0221EFD0
	.public ov97_0221F020
	.public ov97_0221F0E0
	.public ov97_0221F14C
	.public ov97_0221F1D8
	.public ov97_0221F294
	.public ov97_0221F428
	.public ov97_0221F56C
	.public ov97_0221F5F8
	.public ov97_0221F74C
	.public ov97_0221F7DC
	.public ov97_0221F9E0
	.public ov97_0221FAEC
	.public ov97_0221FBDC
	.public ov97_0221FCA8
	.public ov97_0221FCB8
	.public ov97_0221FCCC
	.public ov97_0221FCF4
	.public ov97_0221FCFC
	.public ov97_0221FD04
	.public ov97_0221FD20
	.public ov97_0221FD3C
	.public ov97_0221FD58
	.public ov97_0221E5C0
	.public ov97_0221E69C
	.public ov97_0221E6DC
	.public ov97_0221E7F4
	.public ov97_0221E814
	.public ov97_0221E834
	.public ov97_0221E864
	.public ov97_0221E88C
	.public ov97_0221E97C
	.public ov97_0221EBD8
	.public ov97_0221EE84
	.public ov97_0221F010
	.public ov97_0221FB80
	.public ov97_0221FBA0
	.public ov97_0221FC54


	thumb_func_start ov97_0221F5F8
ov97_0221F5F8: ; 0x0221F5F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
_0221F604:
	ldr r0, [sp, #8]
	lsl r1, r0, #3
	ldr r0, [sp, #4]
	add r7, r0, r1
	mov r0, #0x28
	ldrsb r0, [r7, r0]
	cmp r0, #0
	ble _0221F638
	ldr r0, [sp, #8]
	mov r1, #0x18
	mul r1, r0
	ldr r0, [sp]
	add r4, r0, r1
	mov r0, #0x77
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x77
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #4
	bl Sprite_SetAnimCtrlSeq
	b _0221F674
_0221F638:
	bge _0221F65E
	ldr r0, [sp, #8]
	mov r1, #0x18
	mul r1, r0
	ldr r0, [sp]
	add r4, r0, r1
	mov r0, #0x77
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x77
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #5
	bl Sprite_SetAnimCtrlSeq
	b _0221F674
_0221F65E:
	ldr r0, [sp, #8]
	mov r1, #0x18
	mul r1, r0
	ldr r0, [sp]
	add r1, r0, r1
	mov r0, #0x77
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0221F674:
	ldr r0, [sp, #8]
	mov r1, #0x18
	mul r1, r0
	ldr r0, [sp]
	mov r4, #0
	add r5, r0, r1
_0221F680:
	add r0, r7, r4
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #4
	bhi _0221F72A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0221F696: ; jump table
	.short _0221F6A0 - _0221F696 - 2 ; case 0
	.short _0221F6B2 - _0221F696 - 2 ; case 1
	.short _0221F6D0 - _0221F696 - 2 ; case 2
	.short _0221F6EE - _0221F696 - 2 ; case 3
	.short _0221F70C - _0221F696 - 2 ; case 4
_0221F6A0:
	lsl r0, r4, #2
	add r1, r5, r0
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _0221F72E
_0221F6B2:
	lsl r0, r4, #2
	add r6, r5, r0
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #3
	bl Sprite_SetAnimCtrlSeq
	b _0221F72E
_0221F6D0:
	lsl r0, r4, #2
	add r6, r5, r0
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	b _0221F72E
_0221F6EE:
	lsl r0, r4, #2
	add r6, r5, r0
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetAnimCtrlSeq
	b _0221F72E
_0221F70C:
	lsl r0, r4, #2
	add r6, r5, r0
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #2
	bl Sprite_SetAnimCtrlSeq
	b _0221F72E
_0221F72A:
	bl GF_AssertFail
_0221F72E:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _0221F680
	ldr r0, [sp, #8]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #5
	bhs _0221F748
	b _0221F604
_0221F748:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov97_0221F5F8


	thumb_func_start ov97_0221F74C
ov97_0221F74C: ; 0x0221F74C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	mov r7, #0x6d
	lsl r7, r7, #2
	str r0, [sp, #4]
	add r0, #0x78
	add r6, r7, #0
	str r0, [sp, #4]
	mov r4, #0
	add r6, #0x14
_0221F760:
	ldr r0, [sp, #4]
	lsl r1, r4, #2
	add r5, r0, r1
	ldr r0, [r5, r7]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r5, r6]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _0221F760
	mov r0, #0
	mov r6, #0x1e
	str r0, [sp]
	add r7, r0, #0
	lsl r6, r6, #4
_0221F78A:
	ldr r1, [sp]
	mov r0, #0x18
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #4]
	mov r1, #0
	add r5, r0, r2
	mov r0, #0x77
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	mov r4, #0
_0221F7A4:
	lsl r0, r4, #2
	add r0, r5, r0
	ldr r0, [r0, r6]
	add r1, r7, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _0221F7A4
	ldr r0, [sp]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	cmp r0, #5
	blo _0221F78A
	mov r1, #0x95
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov97_0221F74C


	thumb_func_start ov97_0221F7DC
ov97_0221F7DC: ; 0x0221F7DC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r1, r5, #0
	ldr r2, [r5]
	mov r0, #0x42
	add r1, #8
	bl G2dRenderer_Init
	str r0, [r5, #4]
	add r0, r5, #0
	mov r2, #1
	add r0, #8
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r7, #0x13
	mov r6, #0
	add r4, r5, #0
	lsl r7, r7, #4
_0221F80E:
	ldr r2, [r5]
	mov r0, #3
	add r1, r6, #0
	bl Create2DGfxResObjMan
	str r0, [r4, r7]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #6
	blt _0221F80E
	mov r3, #1
	str r3, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5]
	mov r1, #0xf3
	str r0, [sp, #8]
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r2, #7
	bl AddCharResObjFromNarc
	mov r1, #0x52
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r2, #4
	str r2, [sp, #8]
	ldr r0, [r5]
	sub r1, #0x14
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	mov r1, #0xf3
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0x53
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r3, #1
	str r3, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5]
	sub r1, #0x14
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xf3
	mov r2, #6
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x15
	lsl r1, r1, #4
	str r0, [r5, r1]
	mov r3, #1
	str r3, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r5]
	sub r1, #0x14
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xf3
	mov r2, #5
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x55
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0xc
	ldr r0, [r5, r1]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	mov r0, #0x53
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	mov r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5]
	mov r1, #0xa2
	str r0, [sp, #8]
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r2, #0x42
	mov r3, #0
	bl AddCharResObjFromNarc
	mov r1, #0x16
	lsl r1, r1, #4
	str r0, [r5, r1]
	mov r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	ldr r0, [r5]
	sub r1, #0x2c
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	mov r1, #0xa2
	mov r2, #0x41
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0x59
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5]
	sub r1, #0x2c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xa2
	mov r2, #0x43
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5a
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #2
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r5]
	sub r1, #0x2c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xa2
	mov r2, #0x44
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5b
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0xc
	ldr r0, [r5, r1]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	mov r0, #3
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5]
	mov r1, #0x5d
	str r0, [sp, #8]
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r2, #9
	mov r3, #0
	bl AddCharResObjFromNarc
	mov r1, #0x5e
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #3
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	ldr r0, [r5]
	sub r1, #0x44
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	mov r1, #0x5d
	mov r2, #6
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0x5f
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #3
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5]
	sub r1, #0x44
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0x5d
	mov r2, #0xa
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #6
	lsl r1, r1, #6
	str r0, [r5, r1]
	mov r0, #3
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5]
	sub r1, #0x44
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0x5d
	mov r2, #0xa
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0xc
	ldr r0, [r5, r1]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	mov r0, #0x5f
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov97_0221F7DC


	thumb_func_start ov97_0221F9E0
ov97_0221F9E0: ; 0x0221F9E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	mov r4, #0
_0221F9E8:
	lsl r6, r4, #5
	add r6, #0x68
	lsl r0, r4, #2
	add r7, r5, r0
	str r6, [sp]
	mov r0, #0xa8
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #1
	mov r2, #2
	mov r3, #0
	bl ov97_0221FAEC
	mov r1, #0x6d
	lsl r1, r1, #2
	str r0, [r7, r1]
	mov r1, #1
	str r6, [sp]
	mov r0, #0xa8
	str r0, [sp, #4]
	mov r0, #5
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r2, r1, #0
	mov r3, #0
	bl ov97_0221FAEC
	mov r1, #0x72
	lsl r1, r1, #2
	str r0, [r7, r1]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _0221F9E8
	mov r0, #0
	str r0, [sp, #0x10]
_0221FA3C:
	ldr r1, _0221FAE8 ; =ov97_0221FCF4
	ldr r0, [sp, #0x10]
	mov r2, #1
	ldrb r0, [r1, r0]
	mov r1, #0x18
	mov r3, #0
	lsl r6, r0, #4
	ldr r0, [sp, #0x10]
	add r6, #0x30
	mul r1, r0
	mov r0, #0x60
	str r0, [sp]
	add r7, r5, r1
	str r6, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #2
	bl ov97_0221FAEC
	mov r1, #0x77
	lsl r1, r1, #2
	str r0, [r7, r1]
	mov r4, #0
_0221FA70:
	lsl r0, r4, #4
	add r0, #0xa8
	str r0, [sp]
	str r6, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0
	mov r1, #2
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r2, r1, #0
	mov r3, #0
	bl ov97_0221FAEC
	lsl r1, r4, #2
	add r2, r7, r1
	mov r1, #0x1e
	lsl r1, r1, #4
	str r0, [r2, r1]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _0221FA70
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	cmp r0, #5
	blo _0221FA3C
	mov r0, #0x30
	str r0, [sp]
	mov r0, #0x48
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	add r0, r5, #0
	mov r1, #3
	add r3, r2, #0
	str r2, [sp, #0xc]
	bl ov97_0221FAEC
	mov r1, #0x95
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r1, #0x32
	ldr r0, [r5]
	lsl r1, r1, #6
	bl Heap_Alloc
	mov r1, #0x96
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r5, #0
	bl ov97_0221FBA0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_0221FAE8: .word ov97_0221FCF4
	thumb_func_end ov97_0221F9E0


	thumb_func_start ov97_0221FAEC
ov97_0221FAEC: ; 0x0221FAEC
	push {r3, r4, r5, lr}
	sub sp, #0x80
	add r4, r0, #0
	mov r0, #0
	str r1, [sp]
	mvn r0, r0
	str r0, [sp, #4]
	add r5, r2, #0
	str r0, [sp, #8]
	mov r2, #0
	mov r0, #0x13
	str r2, [sp, #0xc]
	lsl r0, r0, #4
	str r3, [sp, #0x10]
	ldr r3, [r4, r0]
	str r3, [sp, #0x14]
	add r3, r0, #4
	ldr r3, [r4, r3]
	str r3, [sp, #0x18]
	add r3, r0, #0
	add r3, #8
	ldr r3, [r4, r3]
	add r0, #0xc
	str r3, [sp, #0x1c]
	ldr r0, [r4, r0]
	add r3, r1, #0
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x2c
	add r2, r1, #0
	bl CreateSpriteResourcesHeader
	ldr r0, [r4]
	add r2, sp, #0x2c
	str r0, [sp]
	ldr r1, [r4, #4]
	add r0, sp, #0x50
	mov r3, #2
	bl ov97_0221FB80
	ldr r0, [sp, #0x90]
	str r5, [sp, #0x74]
	lsl r0, r0, #0xc
	str r0, [sp, #0x58]
	ldr r0, [sp, #0x94]
	lsl r1, r0, #0xc
	mov r0, #1
	lsl r0, r0, #0x14
	add r0, r1, r0
	str r0, [sp, #0x5c]
	add r0, sp, #0x50
	bl Sprite_CreateAffine
	mov r1, #1
	add r4, r0, #0
	bl Sprite_SetAnimActiveFlag
	ldr r1, [sp, #0x98]
	add r0, r4, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetPriority
	ldr r1, [sp, #0x9c]
	add r0, r4, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x80
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov97_0221FAEC

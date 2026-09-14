	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E7EF0
	.extern ov87_021E8394
	.public ov87_021E7A44
	.public ov87_021E7AF8
	.public ov87_021E7DF8

	.text

thumb_func_start ov87_021E7A44
ov87_021E7A44: ; 0x021E7A44
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r0, #0
	mov r0, #2
	mvn r0, r0
	add r7, r1, #0
	str r2, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
_021E7A56:
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	ldr r4, [sp, #0xc]
	add r5, r1, r0
_021E7A5E:
	add r1, r7, r4
	cmp r1, #0
	ble _021E7A7C
	mov r0, #1
	lsl r0, r0, #8
	cmp r1, r0
	bge _021E7A7C
	cmp r5, #0
	ble _021E7A7C
	cmp r5, #0xc0
	bge _021E7A7C
	add r0, r6, #0
	add r2, r5, #0
	bl ov87_021E7AB0
_021E7A7C:
	add r4, r4, #1
	cmp r4, #3
	blt _021E7A5E
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #3
	blt _021E7A56
	mov r1, #0
	mov r3, #0xe3
	str r1, [sp]
	lsl r3, r3, #2
	ldr r2, [r6, r3]
	sub r3, r3, #4
	ldr r3, [r6, r3]
	ldr r0, [r6, #0x58]
	ldr r3, [r3, #0x10]
	bl BG_LoadCharTilesData
	ldr r0, [r6, #0x58]
	mov r1, #0
	bl BgCommitTilemapBufferToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov87_021E7A44

	thumb_func_start ov87_021E7AB0
ov87_021E7AB0: ; 0x021E7AB0
	push {r3, r4, r5, r6}
	mov r3, #1
	mov r4, #0xff
	tst r3, r1
	bne _021E7ABE
	mov r3, #0xf
	b _021E7AC0
_021E7ABE:
	mov r3, #0xf0
_021E7AC0:
	eor r3, r4
	lsl r3, r3, #0x18
	lsr r4, r1, #3
	mov r6, #7
	lsr r5, r2, #3
	and r1, r6
	lsr r3, r3, #0x18
	lsl r4, r4, #5
	lsl r5, r5, #0xa
	lsr r1, r1, #1
	cmp r2, #8
	bhs _021E7ADC
	lsl r2, r2, #2
	b _021E7AE0
_021E7ADC:
	lsl r2, r2, #0x1d
	lsr r2, r2, #0x1b
_021E7AE0:
	mov r6, #0xe3
	lsl r6, r6, #2
	add r4, r5, r4
	add r1, r1, r4
	ldr r0, [r0, r6]
	add r2, r2, r1
	ldrb r1, [r0, r2]
	and r1, r3
	strb r1, [r0, r2]
	pop {r3, r4, r5, r6}
	bx lr
	.balign 4, 0
	thumb_func_end ov87_021E7AB0

	thumb_func_start ov87_021E7AF8
ov87_021E7AF8: ; 0x021E7AF8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	mov r0, #0x20
	mov r1, #0x7a
	bl GF_CreateVramTransferManager
	bl ov87_021E7EF0
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x80
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x7a
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	mov r0, #0x28
	add r1, r5, #4
	mov r2, #0x7a
	bl G2dRenderer_Init
	mov r2, #2
	str r0, [r5]
	add r0, r5, #4
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	ldr r4, _021E7BC0 ; =ov87_021E8394
	mov r7, #0
	add r6, r5, #0
_021E7B44:
	ldrb r0, [r4]
	add r1, r7, #0
	mov r2, #0x7a
	bl Create2DGfxResObjMan
	mov r1, #0x4b
	lsl r1, r1, #2
	str r0, [r6, r1]
	add r7, r7, #1
	add r4, r4, #1
	add r6, r6, #4
	cmp r7, #4
	blt _021E7B44
	add r0, r5, #0
	mov r1, #1
	bl ov87_021E7BC4
	mov r1, #1
	add r0, r5, #0
	add r2, r1, #0
	add r3, r1, #0
	bl ov87_021E7C50
	add r0, r5, #0
	mov r1, #1
	bl ov87_021E7CE0
	add r0, r5, #0
	mov r1, #1
	bl ov87_021E7D6C
	mov r1, #0
	add r0, r5, #0
	add r2, r1, #0
	mov r3, #2
	bl ov87_021E7C50
	mov r7, #0x4f
	lsl r7, r7, #2
	mov r4, #0
	add r6, r7, #4
_021E7B96:
	ldr r0, [r5, r7]
	bl SpriteTransfer_CreateCharTransferTask
	ldr r0, [r5, r6]
	bl SpriteTransfer_CreateExtPlttTransferTask
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #5
	blt _021E7B96
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_021E7BC0: .word ov87_021E8394
	thumb_func_end ov87_021E7AF8

	thumb_func_start ov87_021E7BC4
ov87_021E7BC4: ; 0x021E7BC4
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xb2
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0xc
	mov r3, #0
	bl AddCharResObjFromNarc
	mov r1, #0x57
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0x7a
	str r0, [sp, #0xc]
	add r0, #0xb6
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0xd
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0x16
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xba
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0xb
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x59
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #2
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xbe
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0xa
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5a
	lsl r1, r1, #2
	str r0, [r4, r1]
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov87_021E7BC4

	thumb_func_start ov87_021E7C50
ov87_021E7C50: ; 0x021E7C50
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r2, #0
	add r7, r3, #0
	str r6, [sp]
	add r5, r0, #0
	str r7, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xb2
	lsl r4, r1, #4
	ldr r0, [r5, r0]
	mov r1, #0xcf
	mov r2, #0x20
	mov r3, #0
	bl AddCharResObjFromNarc
	mov r1, #0x4f
	add r2, r5, r4
	lsl r1, r1, #2
	str r0, [r2, r1]
	str r6, [sp]
	str r7, [sp, #4]
	mov r0, #5
	str r0, [sp, #8]
	mov r0, #0x7a
	str r0, [sp, #0xc]
	add r0, #0xb6
	ldr r0, [r5, r0]
	mov r1, #0xcf
	mov r2, #0x21
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #5
	add r2, r5, r4
	lsl r1, r1, #6
	str r0, [r2, r1]
	str r6, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xba
	ldr r0, [r5, r0]
	mov r1, #0xcf
	mov r2, #0x1f
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x51
	add r2, r5, r4
	lsl r1, r1, #2
	str r0, [r2, r1]
	str r6, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xbe
	ldr r0, [r5, r0]
	mov r1, #0xcf
	mov r2, #0x1e
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x52
	add r2, r5, r4
	lsl r1, r1, #2
	str r0, [r2, r1]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov87_021E7C50

	thumb_func_start ov87_021E7CE0
ov87_021E7CE0: ; 0x021E7CE0
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #3
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xb2
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0x10
	mov r3, #0
	bl AddCharResObjFromNarc
	mov r1, #0x5b
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #3
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0x7a
	str r0, [sp, #0xc]
	add r0, #0xb6
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0x11
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #3
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xba
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0xf
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5d
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #3
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xbe
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0xe
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5e
	lsl r1, r1, #2
	str r0, [r4, r1]
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov87_021E7CE0

	thumb_func_start ov87_021E7D6C
ov87_021E7D6C: ; 0x021E7D6C
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xb2
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0x14
	mov r3, #0
	bl AddCharResObjFromNarc
	mov r1, #0x5f
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x7a
	str r0, [sp, #0xc]
	add r0, #0xb6
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0x15
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #6
	lsl r1, r1, #6
	str r0, [r4, r1]
	mov r0, #4
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xba
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0x13
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #4
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x7a
	str r0, [sp, #8]
	add r0, #0xbe
	ldr r0, [r4, r0]
	mov r1, #0xcf
	mov r2, #0x12
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [r4, r1]
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov87_021E7D6C

	thumb_func_start ov87_021E7DF8
ov87_021E7DF8: ; 0x021E7DF8
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
	mov r0, #0x4b
	str r2, [sp, #0xc]
	lsl r0, r0, #2
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
	add r0, sp, #0x5c
	add r2, r1, #0
	bl CreateSpriteResourcesHeader
	ldr r0, [r4]
	mov r1, #0
	str r0, [sp, #0x2c]
	add r0, sp, #0x5c
	str r0, [sp, #0x30]
	mov r0, #1
	lsl r0, r0, #0xc
	str r1, [sp, #0x34]
	str r1, [sp, #0x38]
	str r1, [sp, #0x3c]
	str r0, [sp, #0x40]
	str r0, [sp, #0x44]
	str r0, [sp, #0x48]
	add r0, sp, #0x2c
	strh r1, [r0, #0x20]
	ldr r0, [sp, #0x90]
	str r0, [sp, #0x50]
	mov r0, #0x7a
	str r0, [sp, #0x58]
	add r0, sp, #0x80
	ldrb r0, [r0, #0x14]
	cmp r0, #0
	bne _021E7E6E
	mov r0, #1
	str r0, [sp, #0x54]
	b _021E7E72
_021E7E6E:
	mov r0, #2
	str r0, [sp, #0x54]
_021E7E72:
	add r0, sp, #0x2c
	bl Sprite_CreateAffine
	mov r1, #0
	add r4, r0, #0
	bl Sprite_SetAnimActiveFlag
	mov r1, #1
	add r0, r4, #0
	lsl r1, r1, #0xc
	bl Sprite_SetAnimSpeed
	add r0, r4, #0
	add r1, r5, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	add sp, #0x80
	pop {r3, r4, r5, pc}
	thumb_func_end ov87_021E7DF8

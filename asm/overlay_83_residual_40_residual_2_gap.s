	.include "asm/macros.inc"
	.public GF_CreateVramTransferManager
	.public ov83_022472DC
	.public NNS_G2dInitOamManagerModule
	.public OamManager_Create
	.public G2dRenderer_Init
	.public Create2DGfxResObjMan
	.public ov83_022473BC
	.public AddCharResObjFromNarc
	.public AddPlttResObjFromNarc
	.public AddCellOrAnimResObjFromNarc
	.public AddCellOrAnimResObjFromOpenNarc
	.public NARC_New
	.public GetItemIndexMapping
	.public AddCharResObjFromOpenNarc
	.public GetItemIconCell
	.public GetItemIconAnim
	.public NARC_Delete
	.public ov83_02247314
	.public sub_02074490
	.public sub_02074498
	.public sub_020744A4
	.public Party_GetMonByIndex
	.public Pokemon_GetIconNaix
	.public SpriteTransfer_CreateCharTransferTask
	.public SpriteTransfer_CreateExtPlttTransferTask
	.public GfGfx_EngineBTogglePlanes
	.public GfGfx_EngineATogglePlanes
	.public ov83_02248178
	.text
	thumb_func_start ov83_02246E08
ov83_02246E08: ; 0x02246E08
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	str r1, [sp, #0x14]
	mov r0, #0x20
	mov r1, #0x6b
	str r2, [sp, #0x18]
	bl GF_CreateVramTransferManager
	bl ov83_022472DC
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x80
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x6b
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	mov r0, #0x28
	add r1, r5, #4
	mov r2, #0x6b
	bl G2dRenderer_Init
	ldr r4, _02247148 ; =ov83_02248178
	str r0, [r5]
	mov r7, #0
	add r6, r5, #0
_02246E4C:
	ldrb r0, [r4]
	add r1, r7, #0
	mov r2, #0x6b
	bl Create2DGfxResObjMan
	mov r1, #0x4b
	lsl r1, r1, #2
	str r0, [r6, r1]
	add r7, r7, #1
	add r4, r4, #1
	add r6, r6, #4
	cmp r7, #4
	blt _02246E4C
	add r0, r5, #0
	bl ov83_022473BC
	mov r0, #0
	str r0, [sp]
	mov r3, #1
	str r3, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xc1
	ldr r0, [r5, r0]
	mov r1, #0xb8
	mov r2, #0xf
	bl AddCharResObjFromNarc
	mov r1, #0x4f
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r3, #0
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0x6b
	str r0, [sp, #0xc]
	add r0, #0xc5
	ldr r0, [r5, r0]
	mov r1, #0xb8
	mov r2, #0x37
	bl AddPlttResObjFromNarc
	mov r1, #5
	lsl r1, r1, #6
	str r0, [r5, r1]
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xc9
	ldr r0, [r5, r0]
	mov r1, #0xb8
	mov r2, #0x11
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x51
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xcd
	ldr r0, [r5, r0]
	mov r1, #0xb8
	mov r2, #0x10
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x52
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0x12
	mov r1, #0x6b
	bl NARC_New
	add r6, r5, #0
	add r7, r0, #0
	mov r4, #4
	add r6, #0x40
_02246EFC:
	mov r0, #0
	mov r1, #1
	bl GetItemIndexMapping
	add r2, r0, #0
	str r4, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xc1
	ldr r0, [r5, r0]
	add r1, r7, #0
	mov r3, #0
	bl AddCharResObjFromOpenNarc
	mov r1, #0x4f
	lsl r1, r1, #2
	str r0, [r6, r1]
	mov r0, #0
	mov r1, #2
	bl GetItemIndexMapping
	add r2, r0, #0
	str r4, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6b
	str r0, [sp, #0xc]
	add r0, #0xc5
	ldr r0, [r5, r0]
	mov r1, #0x12
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #5
	lsl r1, r1, #6
	str r0, [r6, r1]
	add r4, r4, #1
	add r6, #0x10
	cmp r4, #9
	ble _02246EFC
	bl GetItemIconCell
	add r2, r0, #0
	mov r0, #4
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xc9
	ldr r0, [r5, r0]
	add r1, r7, #0
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [r5, r1]
	bl GetItemIconAnim
	add r2, r0, #0
	mov r0, #4
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xcd
	ldr r0, [r5, r0]
	add r1, r7, #0
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0
	mov r1, #2
	bl GetItemIndexMapping
	add r2, r0, #0
	mov r0, #3
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x6b
	str r0, [sp, #0xc]
	add r0, #0xc5
	ldr r0, [r5, r0]
	mov r1, #0x12
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r7, #0
	bl NARC_Delete
	mov r0, #3
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xc1
	ldr r0, [r5, r0]
	mov r1, #0xb8
	mov r2, #0x24
	mov r3, #1
	bl AddCharResObjFromNarc
	mov r1, #0x5b
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #3
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xc9
	ldr r0, [r5, r0]
	mov r1, #0xb8
	mov r2, #0x26
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5d
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #3
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xcd
	ldr r0, [r5, r0]
	mov r1, #0xb8
	mov r2, #0x25
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5e
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r5, #0
	bl ov83_02247314
	mov r0, #0x14
	mov r1, #0x6b
	bl NARC_New
	add r7, r0, #0
	bl sub_02074490
	add r2, r0, #0
	mov r0, #0xa
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0x6b
	str r0, [sp, #0xc]
	add r0, #0xc5
	ldr r0, [r5, r0]
	mov r1, #0x14
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0x1e
	lsl r1, r1, #4
	str r0, [r5, r1]
	bl sub_02074498
	add r2, r0, #0
	mov r0, #5
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xc9
	ldr r0, [r5, r0]
	add r1, r7, #0
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x79
	lsl r1, r1, #2
	str r0, [r5, r1]
	bl sub_020744A4
	add r2, r0, #0
	mov r0, #5
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xcd
	ldr r0, [r5, r0]
	add r1, r7, #0
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x7a
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r4, #0
	add r6, r5, #0
_022470AE:
	cmp r4, #3
	bne _022470CC
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _022470C2
	ldr r0, [sp, #0x14]
	mov r1, #0
	bl Party_GetMonByIndex
	b _022470D4
_022470C2:
	ldr r0, [sp, #0x14]
	add r1, r4, #0
	bl Party_GetMonByIndex
	b _022470D4
_022470CC:
	ldr r0, [sp, #0x14]
	add r1, r4, #0
	bl Party_GetMonByIndex
_022470D4:
	bl Pokemon_GetIconNaix
	add r2, r0, #0
	add r0, r4, #0
	add r0, #0xa
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, #0xc1
	ldr r0, [r5, r0]
	add r1, r7, #0
	mov r3, #0
	bl AddCharResObjFromOpenNarc
	mov r1, #0x77
	lsl r1, r1, #2
	str r0, [r6, r1]
	add r4, r4, #1
	add r6, #0x10
	cmp r4, #4
	blt _022470AE
	add r0, r7, #0
	bl NARC_Delete
	mov r7, #0x4f
	mov r6, #0
	add r4, r5, #0
	lsl r7, r7, #2
_02247110:
	ldr r0, [r4, r7]
	bl SpriteTransfer_CreateCharTransferTask
	add r6, r6, #1
	add r4, #0x10
	cmp r6, #0xe
	blt _02247110
	mov r6, #5
	mov r4, #0
	lsl r6, r6, #6
_02247124:
	ldr r0, [r5, r6]
	bl SpriteTransfer_CreateExtPlttTransferTask
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #0xb
	blt _02247124
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_02247148: .word ov83_02248178
	thumb_func_end ov83_02246E08

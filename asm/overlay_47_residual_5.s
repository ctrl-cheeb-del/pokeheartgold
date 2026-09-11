	.include "asm/macros.inc"
	.include "overlay_47.inc"
	.include "global.inc"
	.include "overlay47_exact_bank.inc"

	.text
	.public ov47_02258A14
	.public ov47_02258A1C
	.public ov47_02258A60
	.public ov47_02258A80
	.public ov47_02258A8C
	.public ov47_02258B8C
	.public ov47_02258C44
	.public ov47_02258CC0
	.public ov47_02258CEC
	.public ov47_02258D18
	.public ov47_02258D44
	.public ov47_02258D78
	.public ov47_02258DA8
	.public ov47_02258DB4
	.public ov47_022591F8
	.public ov47_0225921C
	.public ov47_02259228
	.public ov47_02259278
	.public ov47_022592B4
	.public ov47_02259318
	.public ov47_02259384
	.public ov47_022593A0
	.public ov47_022593B4
	.public ov47_022593CC
	.public ov47_02259404
	.public ov47_02259430
	.public ov47_02259448
	.public ov47_0225945C
	.public ov47_0225946C
	.public ov47_02259968
	.public ov47_0225999C
	.public ov47_02259B30
	.public ov47_02259D24
	.public ov47_02259D40
	.public ov47_02259D58
	.public ov47_02259DA4
	.public ov47_02259DCC
	.public ov47_02258DC8
	.public ov47_0225912C


	thumb_func_start ov47_02258DD0
ov47_02258DD0: ; 0x02258DD0
	push {r4, r5, r6, lr}
	sub sp, #0x70
	add r5, r0, #0
	mov r0, #0x80
	str r0, [sp]
	add r6, r3, #0
	add r4, r2, #0
	mov r2, #0
	str r6, [sp, #4]
	add r0, #0xc0
	ldr r0, [r4, r0]
	mov r1, #0xc7
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	mov r0, #5
	str r6, [sp, #0xc]
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	ldr r2, [r4]
	mov r1, #0xc8
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	mov r0, #5
	str r6, [sp, #0xc]
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	ldr r2, [r4]
	mov r1, #0xc9
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0x14
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r1, #0x13
	str r6, [sp, #8]
	lsl r1, r1, #4
	ldr r0, [r4, r1]
	add r1, #0x10
	ldr r1, [r4, r1]
	mov r2, #0xcd
	mov r3, #0
	bl AddCharResObjFromOpenNarc
	str r0, [r5, #0x18]
	mov r0, #0x14
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r1, #0x4d
	str r6, [sp, #0xc]
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r1, #0xc
	ldr r1, [r4, r1]
	mov r2, #0xcc
	mov r3, #0
	bl AddPlttResObjFromOpenNarc
	str r0, [r5, #0x1c]
	ldr r0, [r5, #0x18]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	cmp r0, #0
	bne _02258E6C
	bl GF_AssertFail
_02258E6C:
	ldr r0, [r5, #0x1c]
	bl SpriteTransfer_CreatePlttTransferTask
	cmp r0, #0
	bne _02258E7A
	bl GF_AssertFail
_02258E7A:
	ldr r0, [r5, #0x18]
	bl sub_0200A740
	ldr r0, [r5, #0x1c]
	bl sub_0200A740
	mov r0, #0x14
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r1, #0x4e
	str r6, [sp, #8]
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r1, #8
	ldr r1, [r4, r1]
	mov r2, #0xce
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	str r0, [r5, #0x20]
	mov r0, #0x14
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r1, #0x4f
	str r6, [sp, #8]
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	mov r2, #0xcf
	mov r3, #0
	bl AddCellOrAnimResObjFromOpenNarc
	str r0, [r5, #0x24]
	mov r0, #0
	add r2, sp, #0x2c
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r1, #0x14
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x15
	str r2, [sp, #4]
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	mov r2, #0x13
	str r0, [sp, #0x10]
	lsl r2, r2, #4
	ldr r3, [r4, r2]
	str r3, [sp, #0x14]
	add r3, r2, #4
	ldr r3, [r4, r3]
	str r3, [sp, #0x18]
	add r3, r2, #0
	add r3, #8
	ldr r3, [r4, r3]
	add r2, #0xc
	str r3, [sp, #0x1c]
	ldr r2, [r4, r2]
	add r3, r1, #0
	str r2, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, sp, #0x4c
	add r2, r1, #0
	bl CreateSpriteResourcesHeader
	ldr r0, [r4, #4]
	str r0, [sp, #0x2c]
	add r0, sp, #0x4c
	str r0, [sp, #0x30]
	mov r0, #0
	str r0, [sp, #0x40]
	mov r0, #1
	str r0, [sp, #0x44]
	add r0, sp, #0x2c
	str r6, [sp, #0x48]
	bl Sprite_Create
	mov r1, #0
	str r0, [r5, #0x14]
	bl Sprite_SetDrawFlag
	ldr r0, [r4]
	ldr r2, _02258F44 ; =ov47_02259E40
	add r1, r5, #0
	bl AddWindow
	add r5, #0x2c
	add r0, r5, #0
	mov r1, #1
	add r2, r6, #0
	bl ov47_02259C8C
	add sp, #0x70
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02258F44: .word ov47_02259E40
	thumb_func_end ov47_02258DD0




	thumb_func_start ov47_02258F48
ov47_02258F48: ; 0x02258F48
	push {r4, r5, r6, lr}
	add r4, r0, #0
	add r5, r3, #0
	ldrh r3, [r4, #0x28]
	add r6, r1, #0
	cmp r3, #0xa
	bls _02258F58
	b _02259114
_02258F58:
	add r3, r3, r3
	add r3, pc
	ldrh r3, [r3, #6]
	lsl r3, r3, #0x10
	asr r3, r3, #0x10
	add pc, r3
_02258F64: ; jump table
	.short _02258F7A - _02258F64 - 2 ; case 0
	.short _02258F96 - _02258F64 - 2 ; case 1
	.short _02258FA6 - _02258F64 - 2 ; case 2
	.short _02258FC8 - _02258F64 - 2 ; case 3
	.short _02258FEE - _02258F64 - 2 ; case 4
	.short _02259016 - _02258F64 - 2 ; case 5
	.short _0225906E - _02258F64 - 2 ; case 6
	.short _022590A4 - _02258F64 - 2 ; case 7
	.short _022590D4 - _02258F64 - 2 ; case 8
	.short _022590FA - _02258F64 - 2 ; case 9
	.short _02259104 - _02258F64 - 2 ; case 10
_02258F7A:
	add r0, r6, #0
	mov r1, #0
	mov r2, #0x5e
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	mov r0, #1
	strh r0, [r4, #0x2a]
	mov r0, #0xa
	strh r0, [r4, #0x28]
	b _02259118
_02258F96:
	add r1, r2, #0
	ldr r2, [sp, #0x14]
	add r0, r5, #0
	bl ov47_02259404
	mov r0, #2
	strh r0, [r4, #0x28]
	b _02259118
_02258FA6:
	ldr r1, [sp, #0x14]
	add r0, r5, #0
	bl ov47_02259430
	cmp r0, #0
	beq _02258FBC
	mov r1, #1
	mvn r1, r1
	cmp r0, r1
	beq _02258FC2
	b _02259118
_02258FBC:
	mov r0, #3
	strh r0, [r4, #0x28]
	b _02259118
_02258FC2:
	mov r0, #9
	strh r0, [r4, #0x28]
	b _02259118
_02258FC8:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	bne _02258FD2
	mov r2, #0x5c
	b _02258FD4
_02258FD2:
	mov r2, #0x5d
_02258FD4:
	add r0, r6, #0
	mov r1, #0
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	mov r0, #4
	strh r0, [r4, #0x2a]
	mov r0, #0xa
	strh r0, [r4, #0x28]
	b _02259118
_02258FEE:
	bl ov47_0225916C
	add r0, r4, #0
	add r0, #0x2c
	add r1, r6, #0
	bl ov47_02259D40
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_02259318
	add r0, r4, #0
	bl ov47_022591F8
	add r0, r4, #0
	bl ov47_0225921C
	mov r0, #5
	strh r0, [r4, #0x28]
	b _02259118
_02259016:
	ldr r0, _0225911C ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _0225902E
	ldr r0, _02259120 ; =0x000005DC
	bl PlaySE
	ldrh r0, [r4, #0x28]
	add r0, r0, #1
	strh r0, [r4, #0x28]
	b _02259118
_0225902E:
	mov r0, #0x40
	tst r0, r1
	beq _0225904A
	ldr r0, [r4, #0x10]
	sub r0, r0, #1
	bmi _02259066
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
	ldr r0, [r4, #0x10]
	sub r0, r0, #1
	str r0, [r4, #0x10]
	b _02259066
_0225904A:
	mov r0, #0x80
	tst r0, r1
	beq _02259066
	ldr r0, [r4, #0x10]
	add r0, r0, #1
	cmp r0, #3
	bge _02259066
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
	ldr r0, [r4, #0x10]
	add r0, r0, #1
	str r0, [r4, #0x10]
_02259066:
	add r0, r4, #0
	bl ov47_022591F8
	b _02259118
_0225906E:
	ldr r0, [sp, #0x10]
	ldr r1, [r4, #0x30]
	ldr r0, [r0, #4]
	ldr r2, [r4, #0x10]
	bl ov45_0222A7DC
	ldr r0, [r4, #0x10]
	bl ov45_0222F4D4
	add r0, r6, #0
	mov r1, #0
	mov r2, #0x60
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_02259318
	add r0, r5, #0
	bl ov47_02259384
	ldr r0, _02259124 ; =0x0000057D
	bl PlaySE
	mov r0, #7
	strh r0, [r4, #0x28]
	b _02259118
_022590A4:
	bl ov45_0222F524
	cmp r0, #1
	beq _02259118
	ldr r0, _02259128 ; =0x000005E4
	bl PlaySE
	add r0, r5, #0
	bl ov47_022593A0
	add r0, r6, #0
	mov r1, #0
	mov r2, #0x61
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	mov r0, #8
	strh r0, [r4, #0x2a]
	mov r0, #0xa
	strh r0, [r4, #0x28]
	b _02259118
_022590D4:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	bne _022590DE
	mov r2, #0x62
	b _022590E0
_022590DE:
	mov r2, #0x63
_022590E0:
	add r0, r6, #0
	mov r1, #0
	bl ov47_02258CEC
	add r1, r0, #0
	add r0, r5, #0
	bl ov47_022592B4
	mov r0, #9
	strh r0, [r4, #0x2a]
	mov r0, #0xa
	strh r0, [r4, #0x28]
	b _02259118
_022590FA:
	add r0, r5, #0
	bl ov47_022593CC
	mov r0, #1
	pop {r4, r5, r6, pc}
_02259104:
	add r0, r5, #0
	bl ov47_022593B4
	cmp r0, #1
	bne _02259118
	ldrh r0, [r4, #0x2a]
	strh r0, [r4, #0x28]
	b _02259118
_02259114:
	bl GF_AssertFail
_02259118:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0225911C: .word gSystem
_02259120: .word 0x000005DC
_02259124: .word 0x0000057D
_02259128: .word 0x000005E4
	thumb_func_end ov47_02258F48

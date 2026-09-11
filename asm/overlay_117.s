	.include "asm/macros.inc"
	.public _0225F034
	.public _0225F040
	.public _0225F050
	.public _0225F0A2
	.public _0225F0E0
	.public _0225F100
	.public _0225F124
	.public _0225F134
	.public _0225F136
	.public _0225F256
	.public _0225F262
	.public _0225F274
	.public _0225F2A4
	.public _0225F2B8
	.public _0225F2BC
	.public _0225F2C0
	.public _0225F2C4
	.public _0225F2C8
	.public _0225F2CC
	.public _0225F2D0
	.public _0225F2D4
	.public _0225F2D8
	.public _0225F2DC
	.public _0225F2E0
	.public _0225F300
	.public _0225F308
	.public _0225F330
	.public _0225F358
	.public _0225F394
	.public _0225F3E4
	.public _0225F41A
	.public _0225F53A
	.public _0225F546
	.public _0225F560
	.public _0225F72E
	.public _0225F744
	.public _0225F76A
	.public _0225F79C
	.public _0225F7DC
	.public _0225F806
	.public _0225F816
	.public _0225F818
	.public _0225F820
	.public _0225F860
	.public _0225F87C
	.public _0225F892
	.public _0225F8D8
	.public _0225F8DC
	.public _0225F8E0
	.public _0225F8E4
	.public _0225F8E8
	.public _0225F8EC
	.public _0225F8F0
	.public _0225F8F4
	.public _0225F8F8
	.public _0225F90C
	.public _0225F91E
	.public _0225F944
	.public _0225F95E
	.public _0225F96E
	.public _0225F970
	.public _0225F99E
	.public _0225F9C4
	.public _0225F9CC
	.public _0225FA16
	.public _0225FA26
	.public _0225FA30
	.public _0225FA98
	.public _0225FAAC
	.public _0225FAB8
	.public _0225FABC
	.public _0225FAC0
	.public _0225FAC4
	.public _0225FAC8
	.public _0225FACC
	.public ov117_0225F020
	.public ov117_0225F524
	.public ov117_0225FAD4
	.public ov117_0225FADC
	.public ov117_0225FAE4
	.public ov117_0225FAEC
	.public ov117_0225FAF4
	.public ov117_0225FAF8
	.public ov117_0225FAFC
	.public ov117_0225FB00
	.public ov117_0225FB04
	.public ov117_0225FB08
	.public ov117_0225FB0C
	.public ov117_0225FB10
	.public _0225FACC
	.public ov117_0225F020
	.public ov117_0225F420
	.public ov117_0225F470
	.public ov117_0225F4D4
	.public ov117_0225F4E4
	.public ov117_0225F4F4
	.public ov117_0225F504
	.public ov117_0225F514
	.public ov117_0225F524
	.include "overlay_117.inc"
	.include "global.inc"

	.text
	.public ov117_0225F420
	.public ov117_0225F470
	.public ov117_0225F4D4
	.public ov117_0225F4E4
	.public ov117_0225F4F4
	.public ov117_0225F504
	.public ov117_0225F514

	thumb_func_start ov117_0225F020
ov117_0225F020: ; 0x0225F020
	push {r4, r5, r6, r7, lr}
	sub sp, #0x4c
	str r0, [sp, #0x14]
	add r0, r1, #0
	ldr r0, [r0]
	str r1, [sp, #0x18]
	ldr r4, [r1, #0xc]
	cmp r0, #7
	bls _0225F034
	b _0225F330
_0225F034:
	add r1, r0, r0
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0225F040: ; jump table
	.short _0225F050 - _0225F040 - 2 ; case 0
	.short _0225F0E0 - _0225F040 - 2 ; case 1
	.short _0225F100 - _0225F040 - 2 ; case 2
	.short _0225F124 - _0225F040 - 2 ; case 3
	.short _0225F262 - _0225F040 - 2 ; case 4
	.short _0225F274 - _0225F040 - 2 ; case 5
	.short _0225F2A4 - _0225F040 - 2 ; case 6
	.short _0225F2E0 - _0225F040 - 2 ; case 7
_0225F050:
	mov r1, #0x3d
	mov r0, #4
	lsl r1, r1, #4
	bl Heap_Alloc
	ldr r1, [sp, #0x18]
	mov r2, #0x3d
	str r0, [r1, #0xc]
	mov r1, #0
	lsl r2, r2, #4
	bl memset
	ldr r0, [sp, #0x18]
	mov r1, #6
	ldr r4, [r0, #0xc]
	mov r2, #1
	add r0, r4, #0
	bl ov01_021F05C4
	mov r0, #1
	str r0, [sp]
	mov r0, #0x9c
	str r0, [sp, #4]
	mov r0, #0x9e
	str r0, [sp, #8]
	mov r2, #0x9d
	str r2, [sp, #0xc]
	ldr r0, _0225F2B8 ; =0x000927C0
	add r2, #0x9f
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x18]
	add r1, r4, #0
	ldr r0, [r0, #0x20]
	add r2, r4, r2
	mov r3, #3
	bl ov01_021F0614
	mov r7, #0x4f
	mov r6, #0
	add r5, r4, #0
	lsl r7, r7, #2
_0225F0A2:
	mov r0, #0
	str r0, [sp]
	mov r2, #0
	str r0, [sp, #4]
	add r0, r4, #0
	add r1, r4, r7
	add r3, r2, #0
	bl ov01_021F0718
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #6
	blt _0225F0A2
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _0225F330
_0225F0E0:
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	add r1, r0, #0
	ldr r3, [sp, #0x18]
	sub r1, #0x11
	add r2, r1, #0
	add r3, r3, #4
	bl ov01_021EFCF8
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _0225F330
_0225F100:
	ldr r1, [sp, #0x18]
	ldr r1, [r1, #4]
	cmp r1, #0
	beq _0225F134
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	mov r0, #0xf2
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	ldr r1, [r4, r0]
	add r0, r0, #4
	lsl r2, r1, #5
	ldr r1, _0225F2BC ; =ov117_0225FB0C
	ldr r1, [r1, r2]
	str r1, [r4, r0]
	b _0225F330
_0225F124:
	mov r0, #0xf3
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r1, [r4, r0]
	cmp r1, #0
	blt _0225F136
_0225F134:
	b _0225F330
_0225F136:
	sub r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #8
	str r1, [sp]
	mov r1, #0x86
	lsl r1, r1, #2
	add r2, r4, r1
	mov r1, #0x18
	mul r1, r0
	lsl r3, r0, #5
	add r0, r2, r1
	ldr r1, _0225F2C0 ; =ov117_0225FAF4
	ldr r2, _0225F2C4 ; =ov117_0225FAF8
	ldr r5, _0225F2C8 ; =ov117_0225FAFC
	ldr r1, [r1, r3]
	ldr r2, [r2, r3]
	ldr r3, [r5, r3]
	bl ov01_021EFEC8
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #8
	str r1, [sp]
	mov r1, #0xaa
	lsl r1, r1, #2
	add r2, r4, r1
	mov r1, #0x18
	mul r1, r0
	lsl r3, r0, #5
	add r0, r2, r1
	ldr r1, _0225F2CC ; =ov117_0225FB00
	ldr r2, _0225F2D0 ; =ov117_0225FB04
	ldr r5, _0225F2D4 ; =ov117_0225FB08
	ldr r1, [r1, r3]
	ldr r2, [r2, r3]
	ldr r3, [r5, r3]
	bl ov01_021EFEC8
	mov r0, #0x62
	lsl r0, r0, #2
	mov r1, #8
	add r3, r4, r0
	mov r0, #0xf2
	str r1, [sp]
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	mov r0, #0x18
	mul r0, r2
	add r0, r3, r0
	ldr r3, _0225F2D8 ; =0xFFFFF99A
	lsl r1, r1, #0xa
	mov r2, #0x29
	bl ov01_021EFEC8
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	sub r0, #0x90
	add r1, r4, r0
	mov r0, #0x14
	mul r0, r2
	lsl r3, r2, #5
	ldr r2, _0225F2DC ; =ov117_0225FB10
	add r0, r1, r0
	ldr r2, [r2, r3]
	mov r1, #0
	mov r3, #8
	bl ov01_021EFE34
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r0, r0, #2
	add r1, r4, r0
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, _0225F2C0 ; =ov117_0225FAF4
	lsl r3, r0, #5
	ldr r2, _0225F2CC ; =ov117_0225FB00
	ldr r1, [r1, r3]
	ldr r2, [r2, r3]
	add r0, sp, #0x40
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r0, r0, #2
	add r1, r4, r0
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	add r1, sp, #0x40
	bl Sprite_SetMatrix
	mov r1, #2
	lsl r1, r1, #0xc
	add r0, sp, #0x34
	add r2, r1, #0
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #2
	lsl r0, r0, #2
	add r1, r4, r0
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	add r1, sp, #0x34
	bl Sprite_SetScaleAndAffineType
	mov r1, #0xf2
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	mov r3, #1
	lsl r0, r0, #2
	add r2, r4, r0
	add r0, r1, #0
	sub r0, #0x18
	str r3, [r2, r0]
	ldr r0, [r4, r1]
	add r0, r0, #1
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	cmp r0, #6
	blt _0225F256
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _0225F330
_0225F256:
	lsl r2, r0, #5
	ldr r0, _0225F2BC ; =ov117_0225FB0C
	ldr r2, [r0, r2]
	add r0, r1, #4
	str r2, [r4, r0]
	b _0225F330
_0225F262:
	mov r1, #0xf1
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	cmp r1, #0
	bne _0225F330
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _0225F330
_0225F274:
	ldr r0, [sp, #0x18]
	ldr r0, [r0, #0x10]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x1c]
	bl HBlankSystem_Stop
	mov r0, #0xc
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #4
	mov r2, #0
	str r0, [sp, #8]
	mov r0, #3
	mov r1, #0x22
	add r3, r2, #0
	bl BeginNormalPaletteFade
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _0225F330
_0225F2A4:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0225F330
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _0225F330
	.balign 4, 0
_0225F2B8: .word 0x000927C0
_0225F2BC: .word ov117_0225FB0C
_0225F2C0: .word ov117_0225FAF4
_0225F2C4: .word ov117_0225FAF8
_0225F2C8: .word ov117_0225FAFC
_0225F2CC: .word ov117_0225FB00
_0225F2D0: .word ov117_0225FB04
_0225F2D4: .word ov117_0225FB08
_0225F2D8: .word 0xFFFFF99A
_0225F2DC: .word ov117_0225FB10
_0225F2E0:
	mov r0, #1
	mov r1, #0
	bl sub_0200FBF4
	ldr r0, [sp, #0x18]
	ldr r0, [r0, #0x10]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x1c]
	bl HBlankSystem_Start
	ldr r0, [sp, #0x18]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq _0225F300
	mov r0, #1
	str r0, [r1]
_0225F300:
	mov r7, #0x17
	mov r6, #0
	add r5, r4, #0
	lsl r7, r7, #4
_0225F308:
	ldr r0, [r5, r7]
	bl Sprite_Delete
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #6
	blt _0225F308
	mov r1, #0x4f
	lsl r1, r1, #2
	add r0, r4, #0
	add r1, r4, r1
	bl ov01_021F06EC
	add r0, r4, #0
	bl ov01_021F05F4
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x14]
	bl ov01_021EFCDC
_0225F330:
	mov r1, #0x86
	mov r0, #0
	lsl r1, r1, #2
	str r0, [sp, #0x1c]
	add r0, r4, r1
	str r0, [sp, #0x2c]
	add r0, r1, #0
	add r0, #0x90
	add r0, r4, r0
	sub r1, #0x90
	str r0, [sp, #0x28]
	add r0, r4, r1
	str r0, [sp, #0x24]
	mov r0, #0xce
	lsl r0, r0, #2
	add r0, r4, r0
	add r5, r4, #0
	str r0, [sp, #0x20]
	add r6, r4, #0
	add r7, r4, #0
_0225F358:
	mov r0, #0x3b
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _0225F3E4
	ldr r0, [sp, #0x2c]
	bl ov01_021EFF28
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x28]
	bl ov01_021EFF28
	ldr r0, [sp, #0x24]
	bl ov01_021EFF28
	ldr r0, [sp, #0x20]
	bl ov01_021EFE44
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _0225F394
	mov r0, #0x3b
	mov r1, #0
	lsl r0, r0, #4
	str r1, [r5, r0]
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
_0225F394:
	mov r1, #0x86
	mov r2, #0xaa
	lsl r1, r1, #2
	lsl r2, r2, #2
	ldr r1, [r6, r1]
	ldr r2, [r6, r2]
	add r0, sp, #0x40
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, sp, #0x40
	bl Sprite_SetMatrix
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r1, [r6, r0]
	add r0, sp, #0x34
	add r2, r1, #0
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, sp, #0x34
	bl Sprite_SetAffineScale
	mov r1, #0xce
	lsl r1, r1, #2
	mov r0, #0x17
	ldr r1, [r7, r1]
	lsl r0, r0, #4
	lsl r1, r1, #0x10
	ldr r0, [r5, r0]
	lsr r1, r1, #0x10
	bl Sprite_SetAffineZRotation
_0225F3E4:
	ldr r0, [sp, #0x2c]
	add r5, r5, #4
	add r0, #0x18
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x28]
	add r6, #0x18
	add r0, #0x18
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x24]
	add r7, #0x14
	add r0, #0x18
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x20]
	add r0, #0x14
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #6
	blt _0225F358
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	cmp r0, #7
	beq _0225F41A
	ldr r0, [r4]
	bl SpriteList_RenderAndAnimateSprites
_0225F41A:
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov117_0225F020

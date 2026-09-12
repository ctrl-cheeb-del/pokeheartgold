.include "asm/macros.inc"

	.public SpriteSystem_LoadAnimResObjFromOpenNarc
	.public SpriteSystem_LoadCellResObjFromOpenNarc
	.public SpriteSystem_LoadCharResObjFromOpenNarc
	.public SpriteSystem_LoadPaletteBufferFromOpenNarc
	.public sub_02074490
	.public sub_0207449C
	.public sub_020744A8

	.text

	thumb_func_start ov18_021F3E24
ov18_021F3E24: ; 0x021F3E24
	push {r4, lr}
	sub sp, #0x18
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _021F3FB0 ; =0x0000C550
	ldr r1, _021F3FB4 ; =0x00000668
	str r0, [sp, #8]
	ldr r2, _021F3FB8 ; =0x00000854
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #0x4c
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	bl sub_02074490
	ldr r2, _021F3FBC ; =0x00000858
	ldr r3, _021F3FB4 ; =0x00000668
	ldr r1, [r4, r2]
	sub r2, #8
	str r1, [sp]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r1, #3
	str r1, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	ldr r0, _021F3FC0 ; =0x0000C551
	str r0, [sp, #0x14]
	ldr r0, [r4, r2]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r3, [r4, r3]
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	bl sub_0207449C
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021F3FB0 ; =0x0000C550
	ldr r1, _021F3FB4 ; =0x00000668
	str r0, [sp, #4]
	ldr r2, _021F3FBC ; =0x00000858
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	bl sub_020744A8
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021F3FB0 ; =0x0000C550
	ldr r1, _021F3FB4 ; =0x00000668
	str r0, [sp, #4]
	ldr r2, _021F3FBC ; =0x00000858
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _021F3FC4 ; =0x0000C59C
	ldr r1, _021F3FB4 ; =0x00000668
	str r0, [sp, #8]
	ldr r2, _021F3FB8 ; =0x00000854
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #0x73
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r0, _021F3FB8 ; =0x00000854
	ldr r3, _021F3FB4 ; =0x00000668
	ldr r1, [r4, r0]
	sub r0, r0, #4
	str r1, [sp]
	mov r1, #0x76
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #1
	str r1, [sp, #0xc]
	mov r1, #2
	str r1, [sp, #0x10]
	ldr r1, _021F3FC8 ; =0x0000C55E
	str r1, [sp, #0x14]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #3
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021F3FCC ; =0x0000C55A
	ldr r1, _021F3FB4 ; =0x00000668
	str r0, [sp, #4]
	ldr r2, _021F3FB8 ; =0x00000854
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #0x74
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021F3FCC ; =0x0000C55A
	ldr r1, _021F3FB4 ; =0x00000668
	str r0, [sp, #4]
	ldr r2, _021F3FB8 ; =0x00000854
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #0x75
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _021F3FD0 ; =0x0000C59A
	ldr r1, _021F3FB4 ; =0x00000668
	str r0, [sp, #8]
	ldr r2, _021F3FB8 ; =0x00000854
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #0x77
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r0, _021F3FB8 ; =0x00000854
	ldr r3, _021F3FB4 ; =0x00000668
	ldr r1, [r4, r0]
	sub r0, r0, #4
	str r1, [sp]
	mov r1, #0x7a
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #2
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r1, _021F3FD4 ; =0x0000C55C
	str r1, [sp, #0x14]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #3
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021F3FD8 ; =0x0000C559
	ldr r1, _021F3FB4 ; =0x00000668
	str r0, [sp, #4]
	ldr r2, _021F3FB8 ; =0x00000854
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #0x78
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021F3FD8 ; =0x0000C559
	ldr r1, _021F3FB4 ; =0x00000668
	str r0, [sp, #4]
	ldr r2, _021F3FB8 ; =0x00000854
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #0x79
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add sp, #0x18
	pop {r4, pc}
	nop
_021F3FB0: .word 0x0000C550
_021F3FB4: .word 0x00000668
_021F3FB8: .word 0x00000854
_021F3FBC: .word 0x00000858
_021F3FC0: .word 0x0000C551
_021F3FC4: .word 0x0000C59C
_021F3FC8: .word 0x0000C55E
_021F3FCC: .word 0x0000C55A
_021F3FD0: .word 0x0000C59A
_021F3FD4: .word 0x0000C55C
_021F3FD8: .word 0x0000C559
	thumb_func_end ov18_021F3E24

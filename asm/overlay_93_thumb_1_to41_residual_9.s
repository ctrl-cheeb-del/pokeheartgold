	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225DA40

	thumb_func_start ov93_0225DA40
ov93_0225DA40: ; 0x0225DA40
	push {r3, r4, r5, lr}
	sub sp, #0x18
	add r4, r1, #0
	add r5, r0, #0
	str r4, [sp]
	mov r0, #0x17
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	ldr r0, _0225DAE4 ; =0x00002716
	mov r1, #3
	str r0, [sp, #0x14]
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	ldr r2, [r5, #0x24]
	ldr r3, [r5, #0x28]
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _0225DAE8 ; =0x00002714
	add r2, r4, #0
	str r0, [sp, #8]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r3, #0x14
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0225DAE8 ; =0x00002714
	add r2, r4, #0
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r3, #0x16
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0225DAE8 ; =0x00002714
	add r2, r4, #0
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r3, #0x15
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r5, #0
	bl ov93_022609E0
	ldr r1, _0225DAEC ; =0x00001458
	add r0, r5, #0
	add r1, r5, r1
	bl ov93_022610B0
	ldr r1, _0225DAF0 ; =0x00001468
	add r0, r5, #0
	add r1, r5, r1
	bl ov93_02261164
	ldr r1, _0225DAF4 ; =0x00001560
	add r0, r5, #0
	add r1, r5, r1
	bl ov93_02261BBC
	add r0, r5, #0
	bl ov93_02260CF8
	add r0, r5, #0
	bl ov93_02260E1C
	add sp, #0x18
	pop {r3, r4, r5, pc}
	nop
_0225DAE4: .word 0x00002716
_0225DAE8: .word 0x00002714
_0225DAEC: .word 0x00001458
_0225DAF0: .word 0x00001468
_0225DAF4: .word 0x00001560
	thumb_func_end ov93_0225DA40

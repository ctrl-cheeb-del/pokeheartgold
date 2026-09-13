	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225D78C

	thumb_func_start ov93_0225D78C
ov93_0225D78C: ; 0x0225D78C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	add r5, r0, #0
	str r1, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _0225D9C4 ; =0x00002713
	str r1, [sp, #0x2c]
	str r0, [sp, #0x14]
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	ldr r2, [r5, #0x24]
	ldr r3, [r5, #0x28]
	mov r1, #2
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	add r0, r5, #0
	add r0, #0x80
	ldr r0, [r0]
	mov r1, #2
	bl NewString_ReadMsgData
	add r6, r0, #0
	mov r0, #0
	add r1, r6, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0x1e
	sub r0, r1, r0
	lsr r0, r0, #1
	add r4, r0, #6
	add r2, r5, #0
	ldr r3, _0225D9C8 ; =0x0000169C
	str r6, [sp]
	mov r0, #0
	ldr r1, _0225D9CC ; =0x000E0F00
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r1, _0225D9C4 ; =0x00002713
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r1, r4, #0
	add r1, #0x24
	str r1, [sp, #0x14]
	mov r1, #0xa8
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	mov r0, #1
	str r0, [sp, #0x20]
	mov r0, #0xc
	str r0, [sp, #0x24]
	mov r0, #2
	str r0, [sp, #0x28]
	add r2, #0x90
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x28]
	ldr r2, [r2]
	add r3, r5, r3
	bl ov93_02261EB8
	add r0, r6, #0
	bl String_Delete
	add r0, r5, #0
	add r0, #0x80
	ldr r0, [r0]
	mov r1, #0
	bl NewString_ReadMsgData
	str r0, [sp, #0x30]
	add r0, r5, #0
	add r0, #0x80
	ldr r0, [r0]
	mov r1, #1
	bl NewString_ReadMsgData
	str r0, [sp, #0x38]
	mov r0, #0
	str r0, [sp, #0x34]
	ldr r0, _0225D9D0 ; =0x000015AC
	add r7, r5, r0
	add r0, #0x14
	add r6, r5, r0
_0225D840:
	ldr r0, [sp, #0x30]
	add r2, r5, #0
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, _0225D9CC ; =0x000E0F00
	add r2, #0x90
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, _0225D9C4 ; =0x00002713
	add r3, r7, #0
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	mov r0, #0xa8
	str r0, [sp, #0x18]
	mov r0, #0
	str r0, [sp, #0x1c]
	mov r0, #3
	str r0, [sp, #0x20]
	mov r0, #0xc
	str r0, [sp, #0x24]
	mov r0, #0xa
	str r0, [sp, #0x28]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x28]
	ldr r2, [r2]
	bl ov93_02261EB8
	ldr r0, [sp, #0x38]
	add r2, r5, #0
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, _0225D9CC ; =0x000E0F00
	add r2, #0x90
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, _0225D9C4 ; =0x00002713
	add r3, r6, #0
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	mov r0, #0xa8
	str r0, [sp, #0x18]
	mov r0, #0
	str r0, [sp, #0x1c]
	mov r0, #3
	str r0, [sp, #0x20]
	mov r0, #0xc
	str r0, [sp, #0x24]
	mov r0, #0xa
	str r0, [sp, #0x28]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x28]
	ldr r2, [r2]
	bl ov93_02261EB8
	ldr r0, [sp, #0x34]
	add r4, r4, #6
	add r0, r0, #1
	add r7, #0x28
	add r6, #0x28
	str r0, [sp, #0x34]
	cmp r0, #6
	blt _0225D840
	ldr r0, [sp, #0x30]
	bl String_Delete
	ldr r0, [sp, #0x38]
	bl String_Delete
	ldr r0, _0225D9D4 ; =0x000015A8
	add r0, r5, r0
	bl ov93_02261FC8
	add r0, r5, #0
	bl ov93_02262250
	ldr r0, [sp, #0x2c]
	mov r1, #2
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _0225D9D8 ; =0x00002714
	str r0, [sp, #0x14]
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	ldr r2, [r5, #0x24]
	ldr r3, [r5, #0x28]
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0225D9DC ; =0x00002712
	ldr r2, [sp, #0x2c]
	str r0, [sp, #8]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r3, #0x18
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0225D9DC ; =0x00002712
	ldr r2, [sp, #0x2c]
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r3, #0x1a
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0225D9DC ; =0x00002712
	ldr r2, [sp, #0x2c]
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r3, #0x19
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r5, #0
	bl ov93_02262230
	ldr r1, _0225D9D4 ; =0x000015A8
	str r0, [r5, r1]
	mov r0, #0xc8
	str r0, [sp]
	mov r0, #0x14
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _0225D9DC ; =0x00002712
	mov r1, #2
	str r0, [sp, #0x14]
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	ldr r2, [r5, #0x24]
	ldr r3, [r5, #0x28]
	bl SpriteSystem_LoadPaletteBuffer
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0225D9E0 ; =0x00002711
	mov r2, #0xc8
	str r0, [sp, #8]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r3, #0x15
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _0225D9E0 ; =0x00002711
	mov r2, #0xc8
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r3, #0x16
	bl SpriteSystem_LoadCellResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _0225D9E0 ; =0x00002711
	mov r2, #0xc8
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	mov r3, #0x17
	bl SpriteSystem_LoadAnimResObj
	add r0, r5, #0
	bl ov93_02262344
	ldr r1, _0225D9E4 ; =0x0000174C
	str r0, [r5, r1]
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	nop
_0225D9C4: .word 0x00002713
_0225D9C8: .word 0x0000169C
_0225D9CC: .word 0x000E0F00
_0225D9D0: .word 0x000015AC
_0225D9D4: .word 0x000015A8
_0225D9D8: .word 0x00002714
_0225D9DC: .word 0x00002712
_0225D9E0: .word 0x00002711
_0225D9E4: .word 0x0000174C
	thumb_func_end ov93_0225D78C

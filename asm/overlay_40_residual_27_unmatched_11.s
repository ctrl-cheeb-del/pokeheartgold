	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public GfGfxLoader_LoadCharDataFromOpenNarc
	.public GfGfxLoader_LoadScrnDataFromOpenNarc
	.public SpriteSystem_LoadAnimResObj
	.public SpriteSystem_LoadAnimResObjFromOpenNarc
	.public SpriteSystem_LoadCellResObj
	.public SpriteSystem_LoadCellResObjFromOpenNarc
	.public SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType
	.public SpriteSystem_LoadCharResObjFromOpenNarc
	.public SpriteSystem_LoadPaletteBuffer
	.public SpriteSystem_LoadPaletteBufferFromOpenNarc
	.public ov40_0222DB30
	.public ov40_02233238
	.public ov40_02245188
	.public ov40_0224519C
	.public sub_020315D0
	.text

	thumb_func_start ov40_02233238
ov40_02233238: ; 0x02233238
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x50
	ldr r5, [r0, #0x24]
	str r0, [sp, #0x18]
	ldr r7, [r0, #0x14]
	ldr r6, [r0, #0x18]
	ldr r4, [r0, #0x1c]
	ldr r0, [r0, #0x28]
	mov r1, #0x3e
	str r0, [sp, #0x24]
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	add r0, r7, #0
	add r2, r5, #0
	mov r3, #6
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	add r0, r7, #0
	mov r1, #0x44
	add r2, r5, #0
	mov r3, #6
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r0, [sp, #0x18]
	mov r1, #0
	bl ov40_0222DB30
	str r7, [sp]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	ldr r0, _022334D8 ; =0x0000726C
	mov r1, #3
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x24]
	add r2, r6, #0
	add r3, r4, #0
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _022334D8 ; =0x0000726C
	add r1, r4, #0
	str r0, [sp, #8]
	add r0, r6, #0
	add r2, r7, #0
	mov r3, #0x42
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334D8 ; =0x0000726C
	add r1, r4, #0
	str r0, [sp, #4]
	add r0, r6, #0
	add r2, r7, #0
	mov r3, #0x47
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334D8 ; =0x0000726C
	add r1, r4, #0
	str r0, [sp, #4]
	add r0, r6, #0
	add r2, r7, #0
	mov r3, #0x48
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	ldr r0, [sp, #0x18]
	mov r1, #1
	bl ov40_0222DB30
	str r7, [sp]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #6
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	ldr r0, _022334DC ; =0x00006E7A
	mov r1, #2
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x24]
	add r2, r6, #0
	add r3, r4, #0
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _022334DC ; =0x00006E7A
	add r1, r4, #0
	str r0, [sp, #8]
	add r0, r6, #0
	add r2, r7, #0
	mov r3, #0x40
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334DC ; =0x00006E7A
	add r1, r4, #0
	str r0, [sp, #4]
	add r0, r6, #0
	add r2, r7, #0
	mov r3, #0x26
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334DC ; =0x00006E7A
	add r1, r4, #0
	str r0, [sp, #4]
	add r0, r6, #0
	add r2, r7, #0
	mov r3, #0x27
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	ldr r3, _022334E0 ; =ov40_0224519C
	add r2, sp, #0x3c
	ldmia r3!, {r0, r1}
	str r2, [sp, #0x20]
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _022334E4 ; =ov40_02245188
	str r0, [r2]
	add r2, sp, #0x28
	ldmia r3!, {r0, r1}
	str r2, [sp, #0x1c]
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r5, #0
	str r0, [r2]
_02233370:
	cmp r5, #3
	bne _022333B2
	str r7, [sp]
	mov r0, #0x5c
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _022334E8 ; =0x00004705
	mov r1, #2
	add r0, r5, r0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x24]
	add r2, r6, #0
	add r3, r4, #0
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _022334E8 ; =0x00004705
	add r1, r4, #0
	add r0, r5, r0
	str r0, [sp, #8]
	add r0, r6, #0
	add r2, r7, #0
	mov r3, #0x5b
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	b _022333F4
_022333B2:
	mov r0, #0xb3
	str r0, [sp]
	ldr r0, [sp, #0x20]
	mov r1, #2
	ldr r0, [r0]
	add r2, r6, #0
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _022334E8 ; =0x00004705
	add r3, r4, #0
	add r0, r5, r0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x24]
	bl SpriteSystem_LoadPaletteBuffer
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _022334E8 ; =0x00004705
	ldr r3, [sp, #0x1c]
	add r0, r5, r0
	str r0, [sp, #8]
	ldr r3, [r3]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0xb3
	bl SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType
_022333F4:
	ldr r0, [sp, #0x20]
	add r5, r5, #1
	add r0, r0, #4
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	add r0, r0, #4
	str r0, [sp, #0x1c]
	cmp r5, #5
	blt _02233370
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334E8 ; =0x00004705
	add r1, r4, #0
	str r0, [sp, #4]
	add r0, r6, #0
	mov r2, #0xb3
	mov r3, #9
	bl SpriteSystem_LoadCellResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334E8 ; =0x00004705
	add r1, r4, #0
	str r0, [sp, #4]
	add r0, r6, #0
	mov r2, #0xb3
	mov r3, #0xa
	bl SpriteSystem_LoadAnimResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334EC ; =0x00004706
	add r1, r4, #0
	str r0, [sp, #4]
	add r0, r6, #0
	add r2, r7, #0
	mov r3, #0x59
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334EC ; =0x00004706
	add r1, r4, #0
	str r0, [sp, #4]
	add r0, r6, #0
	add r2, r7, #0
	mov r3, #0x5a
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	ldr r1, _022334F0 ; =0x0000088C
	ldr r0, [sp, #0x18]
	mov r6, #0xd
	ldr r0, [r0, r1]
	mov r7, #0xe
	bl sub_020315D0
	ldr r1, [sp, #0x18]
	cmp r0, #0
	ldr r4, [r1, #0x18]
	ldr r5, [r1, #0x1c]
	ldr r1, [r1, #0x28]
	beq _02233474
	mov r6, #0xf
	mov r7, #0x10
_02233474:
	mov r0, #0xb3
	str r0, [sp]
	str r6, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _022334F4 ; =0x0002869F
	add r2, r4, #0
	str r0, [sp, #0x14]
	add r0, r1, #0
	mov r1, #2
	add r3, r5, #0
	bl SpriteSystem_LoadPaletteBuffer
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334F4 ; =0x0002869F
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xb3
	mov r3, #9
	bl SpriteSystem_LoadCellResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, _022334F4 ; =0x0002869F
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xb3
	mov r3, #0xa
	bl SpriteSystem_LoadAnimResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _022334F4 ; =0x0002869F
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r2, #0xb3
	add r3, r7, #0
	bl SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType
	add sp, #0x50
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022334D8: .word 0x0000726C
_022334DC: .word 0x00006E7A
_022334E0: .word ov40_0224519C
_022334E4: .word ov40_02245188
_022334E8: .word 0x00004705
_022334EC: .word 0x00004706
_022334F0: .word 0x0000088C
_022334F4: .word 0x0002869F
	thumb_func_end ov40_02233238

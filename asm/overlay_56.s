	.include "asm/macros.inc"
	.public ov56_021E5C20
	.public ov56_021E5C9C
	.public ov56_021E5CB4
	.public ov56_021E5CE0
	.public ov56_021E5D08
	.public ov56_021E5D34
	.public ov56_021E5D40
	.public ov56_021E5D44
	.public ov56_021E5DA4
	.public ov56_021E5DDC
	.public ov56_021E5EFC
	.public ov56_021E5FB4
	.public ov56_021E5FDC
	.public ov56_021E609C
	.public ov56_021E60F4
	.public ov56_021E614C
	.public ov56_021E6228
	.public ov56_021E63C0
	.public ov56_021E63FC
	.public ov56_021E647C
	.public ov56_021E64C8
	.public ov56_021E64F4
	.public ov56_021E6514
	.public ov56_021E660C
	.public ov56_021E6650
	.public ov56_021E692C
	.public ov56_021E696C
	.public ov56_021E6A7C
	.public ov56_021E6AA4
	.public ov56_021E6BB4
	.public ov56_021E6D90
	.public _021E6DD4
	.public ov56_021E6DE4
	.public ov56_021E6DF4
	.public ov56_021E6E08
	.public ov56_021E6E20
	.public ov56_021E6E38
	.public ov56_021E6E58
	.public ov56_021E6E80
	.include "overlay_56.inc"
	.include "global.inc"

	.text

	thumb_func_start ov56_021E6650
ov56_021E6650: ; 0x021E6650
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r5, r0, #0
	ldr r0, [r5, #0x1c]
	ldr r1, [r5]
	ldrb r7, [r0, #0x13]
	add r0, r7, #0
	str r0, [sp, #0x20]
	add r0, #0x18
	str r0, [sp, #0x20]
	mov r0, #0x4f
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	add r4, r0, #0
	ldr r0, [r5]
	mov r2, #1
	str r0, [sp, #4]
	ldr r0, [r5, #0x18]
	mov r3, #4
	bl LoadUserFrameGfx1
	ldrb r0, [r5, #0xb]
	mov r1, #0
	mov r2, #0xa
	str r0, [sp]
	ldr r0, [r5]
	mov r3, #6
	str r0, [sp, #4]
	ldr r0, [r5, #0x18]
	bl LoadUserFrameGfx2
	add r0, r7, #0
	str r0, [sp, #0x1c]
	add r0, #0xc
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x1c]
	add r0, r4, #0
	bl NARC_GetMemberSize
	add r1, r0, #0
	ldr r0, [r5]
	bl Heap_AllocAtEnd
	add r6, r0, #0
	ldr r1, [sp, #0x1c]
	add r0, r4, #0
	add r2, r6, #0
	bl NARC_ReadWholeMember
	add r0, r6, #0
	add r1, sp, #0x28
	bl NNS_G2dGetUnpackedCharacterData
	ldr r3, [sp, #0x28]
	mov r0, #0
	str r0, [sp]
	ldr r2, [r3, #0x14]
	ldr r0, [r5, #0x18]
	ldr r3, [r3, #0x10]
	mov r1, #1
	bl BG_LoadCharTilesData
	ldr r3, [sp, #0x28]
	mov r0, #0
	str r0, [sp]
	ldr r2, [r3, #0x14]
	ldr r0, [r5, #0x18]
	ldr r3, [r3, #0x10]
	mov r1, #4
	bl BG_LoadCharTilesData
	add r0, r6, #0
	bl Heap_Free
	add r0, r4, #0
	add r1, r7, #0
	bl NARC_GetMemberSize
	add r1, r0, #0
	ldr r0, [r5]
	bl Heap_AllocAtEnd
	add r6, r0, #0
	add r0, r4, #0
	add r1, r7, #0
	add r2, r6, #0
	bl NARC_ReadWholeMember
	add r0, r6, #0
	add r1, sp, #0x24
	bl NNS_G2dGetUnpackedPaletteData
	ldr r2, [sp, #0x24]
	mov r0, #4
	ldr r1, [r2, #0xc]
	ldr r2, [r2, #8]
	mov r3, #0
	lsl r2, r2, #0x10
	lsr r2, r2, #0x10
	bl BG_LoadPlttData
	ldr r0, [r5]
	bl PaletteData_Init
	str r0, [r5, #0x30]
	ldr r3, [r5]
	mov r1, #0
	mov r2, #0xe0
	bl PaletteData_AllocBuffers
	ldr r0, [r5, #0x30]
	ldr r3, [r5]
	mov r1, #2
	mov r2, #0x60
	bl PaletteData_AllocBuffers
	mov r0, #0x60
	str r0, [sp]
	ldr r1, [sp, #0x24]
	mov r2, #0
	ldr r0, [r5, #0x30]
	ldr r1, [r1, #0xc]
	add r3, r2, #0
	bl PaletteData_LoadPalette
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bne _021E6768
	mov r0, #0x20
	str r0, [sp]
	ldr r1, [sp, #0x24]
	ldr r0, [r5, #0x30]
	ldr r1, [r1, #0xc]
	mov r2, #0
	add r1, #0x60
	mov r3, #0x10
	bl PaletteData_LoadPalette
_021E6768:
	mov r0, #2
	str r0, [sp]
	mov r0, #0x60
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	ldr r0, [r5, #0x30]
	ldr r3, [r5]
	mov r1, #0x14
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x30
	str r0, [sp, #8]
	ldr r0, [r5, #0x30]
	ldr r3, [r5]
	mov r1, #0x10
	mov r2, #7
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x50
	str r0, [sp, #8]
	ldr r0, [r5, #0x30]
	ldr r3, [r5]
	mov r1, #0x10
	mov r2, #8
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x40
	str r0, [sp, #8]
	ldr r0, [r5, #0x30]
	ldr r3, [r5]
	mov r1, #0x26
	mov r2, #0x19
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x60
	str r0, [sp, #8]
	ldrb r2, [r5, #0xb]
	ldr r0, [r5, #0x30]
	ldr r3, [r5]
	mov r1, #0x26
	add r2, #0x1a
	bl PaletteData_LoadNarc
	mov r0, #0x10
	mov r1, #0
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r5, #0x30]
	add r2, r1, #0
	mov r3, #0x70
	bl PaletteData_BlendPalette
	mov r0, #0x10
	str r0, [sp]
	mov r2, #0
	str r2, [sp, #4]
	ldr r0, [r5, #0x30]
	mov r1, #2
	mov r3, #0x30
	bl PaletteData_BlendPalette
	ldr r0, [r5, #0x30]
	mov r1, #1
	bl PaletteData_SetAutoTransparent
	ldr r0, [r5, #0x30]
	bl PaletteData_PushTransparentBuffers
	add r0, r6, #0
	bl Heap_Free
	ldr r1, [sp, #0x20]
	add r0, r4, #0
	bl NARC_GetMemberSize
	add r1, r0, #0
	ldr r0, [r5]
	bl Heap_Alloc
	str r0, [r5, #0x3c]
	ldr r1, [sp, #0x20]
	ldr r2, [r5, #0x3c]
	add r0, r4, #0
	bl NARC_ReadWholeMember
	add r1, r5, #0
	ldr r0, [r5, #0x3c]
	add r1, #0x44
	bl NNS_G2dGetUnpackedScreenData
	add r0, r4, #0
	mov r1, #0x24
	bl NARC_GetMemberSize
	add r1, r0, #0
	ldr r0, [r5]
	bl Heap_Alloc
	str r0, [r5, #0x40]
	ldr r2, [r5, #0x40]
	add r0, r4, #0
	mov r1, #0x24
	bl NARC_ReadWholeMember
	add r1, r5, #0
	ldr r0, [r5, #0x40]
	add r1, #0x48
	bl NNS_G2dGetUnpackedScreenData
	add r0, r4, #0
	bl NARC_Delete
	mov r3, #0
	str r3, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x11
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x18]
	ldr r2, _021E691C ; =0x00002001
	mov r1, #4
	bl FillBgTilemapRect
	mov r2, #0
	ldr r0, [r5, #0x44]
	mov r1, #0x20
	str r1, [sp]
	mov r1, #0x18
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0xc
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r2, [sp, #0x10]
	ldrh r1, [r0]
	add r3, r2, #0
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r1, #3
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x18]
	bl CopyToBgTilemapRect
	ldr r0, [r5, #0x18]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, [r5, #0x18]
	mov r1, #4
	bl ScheduleBgTilemapBufferTransfer
	ldrb r0, [r5, #0xc]
	cmp r0, #0
	beq _021E6916
	ldr r0, [r5, #0x48]
	mov r1, #0x20
	str r1, [sp]
	mov r1, #0x18
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0xc
	mov r2, #0
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r2, [sp, #0x10]
	ldrh r1, [r0]
	add r3, r2, #0
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	mov r1, #2
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x18]
	bl CopyToBgTilemapRect
	ldr r0, [r5, #0x18]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	mov r2, #0
	strb r2, [r5, #0x14]
	ldr r0, _021E6920 ; =ov56_021E63FC
	add r1, r5, #0
	strb r2, [r5, #0x15]
	bl SysTask_CreateOnMainQueue
	ldr r0, _021E6924 ; =ov56_021E5D40
	str r0, [r5, #0x34]
	ldr r0, _021E6928 ; =ov56_021E5D34
	str r0, [r5, #0x38]
_021E6916:
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	nop
_021E691C: .word 0x00002001
_021E6920: .word ov56_021E63FC
_021E6924: .word ov56_021E5D40
_021E6928: .word ov56_021E5D34
	thumb_func_end ov56_021E6650

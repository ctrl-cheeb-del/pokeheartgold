	.include "asm/macros.inc"
	.include "overlay_113.inc"
	.include "asm/include/overlay_113_split.inc"
	.include "global.inc"

	.text
	.public UnownReport_Exit
	.public ov113_021E59F8
	.public ov113_021E5A48
	.public ov113_021E5B60
	.public ov113_021E5B70
	.public ov113_021E5BB0
	.public ov113_021E5C60
	.public ov113_021E5CF8
	.public ov113_021E5D28
	.public ov113_021E5D4C
	.public ov113_021E5EC4
	.public ov113_021E6274
	.public ov113_021E629C
	.public ov113_021E62E0
	.public ov113_021E64DC
	.public ov113_021E663C
	.public ov113_021E66E4
	.public ov113_021E6754
	.public ov113_021E6930
	.public ov113_021E6988
	.public ov113_021E69A8

	thumb_func_start ov113_021E650C
ov113_021E650C: ; 0x021E650C
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0xf1
	bl NARC_New
	mov r2, #0
	str r2, [sp]
	ldr r1, [r5]
	add r3, r2, #0
	str r1, [sp, #4]
	mov r1, #5
	add r4, r0, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5]
	mov r1, #7
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x40]
	add r0, r4, #0
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5]
	mov r1, #9
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x40]
	add r0, r4, #0
	mov r3, #3
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5]
	mov r1, #4
	str r0, [sp, #4]
	add r0, r4, #0
	add r2, r1, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5]
	mov r1, #6
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x40]
	add r0, r4, #0
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5]
	mov r1, #8
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x40]
	add r0, r4, #0
	mov r3, #7
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r3, [r5]
	add r0, r5, r0
	add r1, r4, #0
	mov r2, #0xa
	bl ov113_021E64DC
	mov r0, #5
	lsl r0, r0, #6
	ldr r3, [r5]
	add r0, r5, r0
	add r1, r4, #0
	mov r2, #0xc
	bl ov113_021E64DC
	mov r0, #0x15
	lsl r0, r0, #4
	ldr r3, [r5]
	add r0, r5, r0
	add r1, r4, #0
	mov r2, #0xe
	bl ov113_021E64DC
	mov r0, #1
	lsl r0, r0, #8
	ldr r3, [r5]
	add r0, r5, r0
	add r1, r4, #0
	mov r2, #0xb
	bl ov113_021E64DC
	mov r0, #0x11
	lsl r0, r0, #4
	ldr r3, [r5]
	add r0, r5, r0
	add r1, r4, #0
	mov r2, #0xd
	bl ov113_021E64DC
	mov r0, #0x12
	lsl r0, r0, #4
	ldr r3, [r5]
	add r0, r5, r0
	add r1, r4, #0
	mov r2, #0xf
	bl ov113_021E64DC
	add r0, r4, #0
	bl NARC_Delete
	ldrb r0, [r5, #0x19]
	mov r1, #1
	add r2, r1, #0
	str r0, [sp]
	ldr r0, [r5]
	mov r3, #0xd
	str r0, [sp, #4]
	ldr r0, [r5, #0x40]
	bl LoadUserFrameGfx2
	mov r1, #6
	ldr r2, [r5]
	mov r0, #0
	lsl r1, r1, #6
	bl LoadFontPal1
	mov r1, #6
	ldr r2, [r5]
	mov r0, #4
	lsl r1, r1, #6
	bl LoadFontPal1
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov113_021E650C


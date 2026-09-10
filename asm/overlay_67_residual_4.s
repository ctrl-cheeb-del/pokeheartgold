	.include "asm/macros.inc"
	.include "overlay_67.inc"
	.include "global.inc"

	.public ov67_021E6D50
	.public ov67_021E6D5C
	.public ov67_021E6D6C
	.public ov67_021E6D7C
	.public ov67_021E6D90
	.public ov67_021E6DA8
	.public ov67_021E6DC4
	.public ov67_021E6DE0
	.public ov67_021E6DFC
	.public ov67_021E6E18
	.public ov67_021E6E38
	.public ov67_021E6E60
	.public ov67_021E6E98
	.public ov67_021E6EE8
	.public ov67_021E6F50
	.public ov67_021E7020

	.public _021E6D4C

	.text
	.public ov67_021E5900
	.public ov67_021E5968
	.public ov67_021E5984
	.public ov67_021E5A6C
	.public ov67_021E5B44
	.public ov67_021E5BC0
	.public ov67_021E5BE0
	.public ov67_021E5C04
	.public ov67_021E5C44
	.public ov67_021E5DA0
	.public ov67_021E5E84
	.public ov67_021E5EB0
	.public ov67_021E6008
	.public ov67_021E6080
	.public ov67_021E60B4
	.public ov67_021E60F4
	.public ov67_021E6118
	.public ov67_021E6164
	.public ov67_021E61A0
	.public ov67_021E61E8
	.public ov67_021E6220
	.public ov67_021E63E8
	.public ov67_021E6474
	.public ov67_021E6490
	.public ov67_021E6530
	.public ov67_021E65C0
	.public ov67_021E6688
	.public ov67_021E681C
	.public ov67_021E6820
	.public ov67_021E6990
	.public ov67_021E69D8
	.public ov67_021E6A00
	.public ov67_021E6A08
	.public ov67_021E6A28
	.public ov67_021E6A40
	.public ov67_021E6B6C
	.public ov67_021E6BB8
	.public ov67_021E6BC4
	.public ov67_021E6C04
	.public ov67_021E6C14
	.public ov67_021E6C5C
	.public ov67_021E6C60
	.public ov67_021E6D20
	thumb_func_start ov67_021E5EB0
ov67_021E5EB0: ; 0x021E5EB0
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _021E5F68
	ldr r1, [r4]
	mov r0, #0x76
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r1, [r4]
	add r5, r0, #0
	str r1, [sp, #0xc]
	ldr r2, [r4, #0x10]
	mov r1, #4
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r4]
	mov r2, #0
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #7
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r4]
	mov r1, #6
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x10]
	add r0, r5, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r0, r5, #0
	bl NARC_Delete
	ldr r1, [r4]
	mov r0, #0xb7
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	ldr r1, [r4]
	mov r3, #5
	str r1, [sp, #0xc]
	ldr r2, [r4, #0x10]
	mov r1, #0x8e
	add r5, r0, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #0xc4
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #0x8d
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x10]
	add r0, r5, #0
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r0, r5, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
_021E5F68:
	ldr r1, [r4]
	mov r0, #0x76
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r1, [r4]
	add r5, r0, #0
	str r1, [sp, #0xc]
	ldr r2, [r4, #0x10]
	mov r1, #4
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r4]
	mov r2, #0
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #7
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r4]
	mov r1, #5
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x10]
	add r0, r5, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #8
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x10]
	add r0, r5, #0
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #0xa
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #9
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x10]
	add r0, r5, #0
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r0, r5, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov67_021E5EB0


	thumb_func_start ov67_021E6008
ov67_021E6008: ; 0x021E6008
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _021E6030
	add r5, r6, #0
	ldr r4, _021E6078 ; =ov67_021E6E98
	mov r7, #0
	add r5, #0x6c
_021E601A:
	ldr r0, [r6, #0x10]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r7, r7, #1
	add r4, #8
	add r5, #0x10
	cmp r7, #0xa
	blt _021E601A
	b _021E6054
_021E6030:
	add r5, r6, #0
	ldr r4, _021E607C ; =ov67_021E7020
	mov r7, #0
	add r5, #0x6c
_021E6038:
	ldr r0, [r6, #0x10]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r7, r7, #1
	add r4, #8
	add r5, #0x10
	cmp r7, #0x23
	blt _021E6038
_021E6054:
	ldr r1, [r6]
	mov r0, #4
	bl FontID_Alloc
	mov r1, #0x1e
	ldr r2, [r6]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	mov r1, #0x1e
	ldr r2, [r6]
	mov r0, #4
	lsl r1, r1, #4
	bl LoadFontPal0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6078: .word ov67_021E6E98
_021E607C: .word ov67_021E7020
	thumb_func_end ov67_021E6008


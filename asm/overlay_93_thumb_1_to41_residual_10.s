	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225DB2C

	thumb_func_start ov93_0225DB2C
ov93_0225DB2C: ; 0x0225DB2C
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x8c
	add r4, r1, #0
	ldr r0, [r0]
	mov r1, #0xc9
	mov r2, #4
	mov r3, #0x75
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #2
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	mov r1, #3
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	add r3, r1, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r3, #2
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #1
	mov r3, #2
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	add r5, #0x8c
	str r0, [sp, #4]
	ldr r0, [r5]
	mov r2, #2
	add r3, r1, #0
	bl PaletteData_FillPaletteInBuffer
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov93_0225DB2C

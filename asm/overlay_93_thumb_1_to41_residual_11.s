	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225DBC8

	thumb_func_start ov93_0225DBC8
ov93_0225DBC8: ; 0x0225DBC8
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #0xa0
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x8c
	add r4, r1, #0
	ldr r0, [r0]
	mov r1, #0xc9
	mov r2, #5
	mov r3, #0x75
	bl PaletteData_LoadNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #5
	lsl r0, r0, #6
	str r0, [sp, #4]
	mov r0, #0x60
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #0xc9
	mov r2, #6
	mov r3, #0x75
	bl PaletteData_LoadFromNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #0xd
	mov r3, #6
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #0xe
	mov r3, #6
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #0x12
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	ldr r0, [r5]
	add r0, #0x30
	ldrb r0, [r0]
	cmp r0, #2
	beq _0225DC64
	cmp r0, #3
	beq _0225DC7E
	b _0225DC98
_0225DC64:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #0xf
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	b _0225DCB0
_0225DC7E:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #0x10
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	b _0225DCB0
_0225DC98:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #0x11
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
_0225DCB0:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #0x12
	mov r3, #4
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x75
	str r0, [sp, #0xc]
	ldr r2, [r5, #0x2c]
	add r0, r4, #0
	mov r1, #0x13
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r0, r5, #0
	bl ov93_02260BF0
	add r0, r5, #0
	bl ov93_02260BB0
	mov r0, #0
	str r0, [sp]
	mov r0, #0x75
	str r0, [sp, #4]
	mov r2, #0x35
	ldr r0, [r5, #0x2c]
	mov r1, #4
	lsl r2, r2, #4
	mov r3, #6
	bl LoadUserFrameGfx1
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0x60
	mov r3, #0x20
	bl PaletteData_LoadPaletteSlotFromHardware
	mov r3, #0
	str r3, [sp]
	mov r1, #1
	str r1, [sp, #4]
	add r5, #0x8c
	ldr r0, [r5]
	mov r2, #2
	bl PaletteData_FillPaletteInBuffer
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov93_0225DBC8

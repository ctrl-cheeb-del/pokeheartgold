	.include "asm/macros.inc"
	.public ov98_0221E5C0
	.public ov98_0221E5D0
	.public ov98_0221E5E0
	.public ov98_0221E684
	.public ov98_0221E6CC
	.public ov98_0221E6E0
	.public ov98_0221E6F0
	.public ov98_0221E784
	.public ov98_0221E7E8
	.public ov98_0221E8A8
	.public ov98_0221E970
	.public ov98_0221E9FC
	.public ov98_0221EA4C
	.public ov98_0221EAA8
	.public ov98_0221EABC
	.public ov98_0221EB84
	.public ov98_0221EBD8
	.public ov98_0221EBEC
	.public ov98_0221EC08
	.public ov98_0221EC24
	.public ov98_0221EC3C
	.public ov98_0221ECD0
	.public ov98_0221ED3C
	.public ov98_0221ED48
	.public ov98_0221EDA4
	.public ov98_0221EDC4
	.public ov98_0221EE28
	.public ov98_0221EE84
	.public ov98_0221EE9C
	.public ov98_0221EEDC
	.public ov98_0221EEEC
	.public ov98_0221EEFC
	.public ov98_0221EF14
	.public ov98_0221EF24
	.public ov98_0221EF64
	.public ov98_0221EF80
	.public ov98_0221EFA4
	.public ov98_0221EFB4
	.public ov98_0221EFE8
	.public ov98_0221F01C
	.public ov98_0221F024
	.public ov98_0221F058
	.public ov98_0221F090
	.public ov98_0221F0EC
	.public ov98_0221F120
	.public ov98_0221F150
	.public ov98_0221F174
	.public _0221F194
	.public ov98_0221F19C
	.public ov98_0221F1AC
	.public ov98_0221F1C0
	.public ov98_0221F1E0
	.public ov98_0221F1E4
	.public ov98_0221F1F8
	.public ov98_0221F220
	.public ov98_0221F248
	.include "overlay_98.inc"
	.include "global.inc"

	.text

	thumb_func_start ov98_0221EABC
ov98_0221EABC: ; 0x0221EABC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	str r1, [sp, #4]
	ldr r1, [sp]
	mov r0, #4
	str r2, [sp, #8]
	add r6, r3, #0
	bl FontID_Alloc
	ldr r0, [sp]
	mov r1, #0x1c
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x1c
	add r4, r0, #0
	bl MI_CpuFill8
	ldr r0, [sp, #8]
	lsl r5, r0, #4
	ldr r0, [sp]
	add r1, r5, #0
	bl Heap_Alloc
	mov r1, #0
	add r2, r5, #0
	str r0, [r4, #4]
	bl MI_CpuFill8
	mov r1, #6
	ldr r2, [sp]
	mov r0, #0
	lsl r1, r1, #6
	bl LoadFontPal0
	mov r1, #6
	ldr r2, [sp]
	mov r0, #4
	lsl r1, r1, #6
	bl LoadFontPal0
	ldr r0, [sp, #8]
	mov r7, #0
	cmp r0, #0
	ble _0221EB44
	add r5, r7, #0
_0221EB1A:
	ldr r1, [r4, #4]
	ldr r0, [sp, #4]
	add r1, r1, r5
	add r2, r6, #0
	bl AddWindow
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, r0, r5
	bl FillWindowPixelBuffer
	ldr r0, [r4, #4]
	add r0, r0, r5
	bl ClearWindowTilemap
	ldr r0, [sp, #8]
	add r7, r7, #1
	add r6, #8
	add r5, #0x10
	cmp r7, r0
	blt _0221EB1A
_0221EB44:
	ldr r3, [sp]
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xed
	bl NewMsgDataFromNarc
	str r0, [r4, #0xc]
	ldr r2, [sp, #0x20]
	ldr r3, [sp]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	str r0, [r4, #8]
	ldr r0, [sp]
	bl MessageFormat_New
	str r0, [r4, #0x10]
	mov r0, #1
	ldr r1, [sp]
	lsl r0, r0, #0xa
	bl String_New
	str r0, [r4, #0x14]
	ldr r0, [sp]
	str r0, [r4]
	ldr r0, [sp, #8]
	str r0, [r4, #0x18]
	add r0, r4, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov98_0221EABC

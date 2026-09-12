	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public BeginNormalPaletteFade
	.public IsPaletteFadeFinished
	.public PaletteData_BlendPalettes
	.public ov40_0222DAF0
	.public ov40_02230964
	.public ov40_02231748
	.public sub_020879E0
	.text

	thumb_func_start ov40_02231748
ov40_02231748: ; 0x02231748
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _0223175E
	cmp r1, #1
	beq _02231788
	cmp r1, #2
	beq _0223180E
	b _0223183A
_0223175E:
	mov r1, #0
	str r1, [r4, #0x54]
	mov r0, #0x6f
	str r1, [r4, #0xc]
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl sub_020879E0
	ldr r0, _02231858 ; =0x000006F4
	mov r1, #0
	ldr r0, [r4, r0]
	bl sub_020879E0
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02231850
_02231788:
	ldr r1, [r4, #0xc]
	cmp r1, #0x10
	beq _02231802
	add r1, r1, #2
	str r1, [r4, #0xc]
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	ldr r2, _0223185C ; =0x0000FFFE
	mov r1, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	ldr r2, _02231860 ; =0x0000FFFF
	mov r1, #0
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	ldr r2, _02231864 ; =0x00003FFE
	mov r1, #3
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	ldr r2, _02231860 ; =0x0000FFFF
	mov r1, #1
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02231850
_02231802:
	mov r0, #0x10
	str r0, [r4, #0xc]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02231850
_0223180E:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0223181A
	sub r0, r0, #4
	str r0, [r4, #0xc]
	b _02231850
_0223181A:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x6d
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02231850
_0223183A:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _02231850
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_02231850:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	nop
_02231858: .word 0x000006F4
_0223185C: .word 0x0000FFFE
_02231860: .word 0x0000FFFF
_02231864: .word 0x00003FFE
	thumb_func_end ov40_02231748

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

	thumb_func_start ov113_021E5C68
ov113_021E5C68: ; 0x021E5C68
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldrh r0, [r4, #0x10]
	cmp r0, #3
	bhi _021E5CF2
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E5C80: ; jump table
	.short _021E5C88 - _021E5C80 - 2 ; case 0
	.short _021E5CA8 - _021E5C80 - 2 ; case 1
	.short _021E5CC0 - _021E5C80 - 2 ; case 2
	.short _021E5CE0 - _021E5C80 - 2 ; case 3
_021E5C88:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #4
	str r0, [sp, #8]
	mov r0, #0
	mov r2, #2
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldrh r0, [r4, #0x10]
	add r0, r0, #1
	strh r0, [r4, #0x10]
	b _021E5CF2
_021E5CA8:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5CF2
	ldrb r1, [r4, #0x1a]
	add r0, r4, #0
	bl ov113_021E5DA4
	ldrh r0, [r4, #0x10]
	add r0, r0, #1
	strh r0, [r4, #0x10]
	b _021E5CF2
_021E5CC0:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #0
	mov r2, #5
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldrh r0, [r4, #0x10]
	add r0, r0, #1
	strh r0, [r4, #0x10]
	b _021E5CF2
_021E5CE0:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5CF2
	mov r0, #0
	strh r0, [r4, #0x10]
	add sp, #0xc
	mov r0, #2
	pop {r3, r4, pc}
_021E5CF2:
	mov r0, #3
	add sp, #0xc
	pop {r3, r4, pc}
	thumb_func_end ov113_021E5C68


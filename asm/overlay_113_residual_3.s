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

	thumb_func_start ov113_021E5BC4
ov113_021E5BC4: ; 0x021E5BC4
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldrh r0, [r4, #0x10]
	cmp r0, #0
	beq _021E5BD6
	cmp r0, #1
	beq _021E5BF4
	b _021E5C06
_021E5BD6:
	mov r0, #6
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r4]
	add r2, r1, #0
	str r0, [sp, #8]
	mov r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldrh r0, [r4, #0x10]
	add r0, r0, #1
	strh r0, [r4, #0x10]
	b _021E5C06
_021E5BF4:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5C06
	mov r0, #0
	strh r0, [r4, #0x10]
	add sp, #0xc
	mov r0, #2
	pop {r3, r4, pc}
_021E5C06:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	thumb_func_end ov113_021E5BC4


	thumb_func_start ov113_021E5C0C
ov113_021E5C0C: ; 0x021E5C0C
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldrh r1, [r4, #0x10]
	cmp r1, #0
	beq _021E5C1E
	cmp r1, #1
	beq _021E5C46
	b _021E5C58
_021E5C1E:
	bl ov113_021E5EC4
	cmp r0, #0
	bne _021E5C58
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldrh r0, [r4, #0x10]
	add r0, r0, #1
	strh r0, [r4, #0x10]
	b _021E5C58
_021E5C46:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5C58
	mov r0, #0
	strh r0, [r4, #0x10]
	add sp, #0xc
	mov r0, #4
	pop {r3, r4, pc}
_021E5C58:
	mov r0, #1
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov113_021E5C0C


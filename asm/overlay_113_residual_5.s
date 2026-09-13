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
	.public ov113_021E5D80
	.public ov113_021E5DA4
	.public ov113_021E5E64

	thumb_func_start ov113_021E5D60
ov113_021E5D60: ; 0x021E5D60
	push {r3, r4, lr}
	sub sp, #4
	mov r1, #0
	str r1, [sp]
	add r1, sp, #0
	add r4, r0, #0
	bl ov113_021E5F94
	ldr r1, [sp]
	cmp r1, #0
	bne _021E5D7C
	add r0, r4, #0
	bl ov113_021E5F48
_021E5D7C:
	add sp, #4
	pop {r3, r4, pc}
	thumb_func_end ov113_021E5D60

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

	thumb_func_start ov113_021E671C
ov113_021E671C: ; 0x021E671C
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r7, #0
	ldr r4, _021E6750 ; =ov113_021E6C90
	mov r6, #0
	add r5, #0x68
_021E6728:
	ldr r0, [r7, #0x40]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r6, r6, #1
	add r4, #8
	add r5, #0x10
	cmp r6, #4
	blt _021E6728
	ldr r0, [r7]
	bl YesNoPrompt_Create
	add r7, #0xa8
	str r0, [r7]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6750: .word ov113_021E6C90
	thumb_func_end ov113_021E671C


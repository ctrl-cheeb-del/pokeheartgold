	.include "asm/macros.inc"
	.include "render_window.inc"
	.include "global.inc"

	.text
	.public sub_0200E948
	.public sub_0200E6B4

	thumb_func_start sub_0200E948
sub_0200E948: ; 0x0200E948
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	bl GetWindowBgId
	str r0, [sp, #0x10]
	add r0, r5, #0
	bl GetWindowX
	str r0, [sp, #0x14]
	add r0, r5, #0
	bl GetWindowY
	str r0, [sp, #0x18]
	add r0, r5, #0
	bl GetWindowWidth
	add r4, r0, #0
	add r0, r5, #0
	bl GetWindowHeight
	str r4, [sp]
	str r0, [sp, #4]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	lsl r0, r6, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, [r5]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0x18]
	bl sub_0200E6B4
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0200E948

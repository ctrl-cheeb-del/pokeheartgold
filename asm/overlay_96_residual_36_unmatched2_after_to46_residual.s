	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text
	thumb_func_start ov96_021ECA70
ov96_021ECA70: ; 0x021ECA70
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	mov r7, #0
	mov r4, #1
	mov r5, #2
_021ECA84:
	lsl r1, r4, #0x18
	ldr r0, [r6, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	str r0, [sp, #8]
	lsl r1, r5, #0x18
	ldr r0, [r6, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	mov r1, #0
	bl ov96_021EAB38
	ldr r0, [sp, #0xc]
	mov r1, #0
	bl ov96_021EAB38
	add r7, r7, #1
	add r4, r4, #3
	add r5, r5, #3
	cmp r7, #4
	blt _021ECA84
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl ov96_021EC790
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021ECA70

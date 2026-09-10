	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020109D8
sub_020109D8: ; 0x020109D8
	push {r4, lr}
	add r4, r1, #0
	bl sub_020109BC
	lsl r2, r4, #0xc
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r1, r2, #0xc
	orr r1, r0
	asr r0, r1, #0xc
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_020109D8
	thumb_func_start sub_02010A00
sub_02010A00: ; 0x02010A00
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	add r7, r2, #0
	add r6, r3, #0
	bl sub_020109BC
	cmp r6, r7
	bge _02010A4A
	lsl r1, r6, #2
	str r0, [sp]
	asr r0, r0, #0x1f
	lsl r4, r6, #0xc
	add r5, r5, r1
	str r0, [sp, #4]
_02010A1E:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	asr r3, r4, #0x1f
	add r2, r4, #0
	bl _ll_mul
	mov r2, #2
	lsl r2, r2, #0xa
	add r0, r0, r2
	ldr r2, _02010A50 ; =0x00000000
	adc r1, r2
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	asr r0, r0, #0xc
	stmia r5!, {r0}
	mov r0, #1
	lsl r0, r0, #0xc
	add r6, r6, #1
	add r4, r4, r0
	cmp r6, r7
	blt _02010A1E
_02010A4A:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02010A50: .word 0x00000000
	thumb_func_end sub_02010A00

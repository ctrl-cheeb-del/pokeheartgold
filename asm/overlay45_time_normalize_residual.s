#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222D524
	.public ov45_0222D594

	thumb_func_start ov45_0222D524
ov45_0222D524: ; 0x0222D524
	push {r4, lr}
	sub sp, #8
	ldr r0, [r0]
	add r4, r2, #0
	str r0, [sp, #4]
	ldr r0, [r1]
	str r0, [sp]
	add r0, sp, #0
	ldrb r2, [r0, #6]
	ldrb r1, [r0, #2]
	add r1, r2, r1
	strb r1, [r0, #6]
	ldrb r0, [r0, #6]
	mov r1, #0x3c
	bl _s32_div_f
	add r1, sp, #0
	ldrb r2, [r1, #5]
	add r0, r2, r0
	strb r0, [r1, #5]
	ldrb r0, [r1, #6]
	mov r1, #0x3c
	bl _s32_div_f
	strb r1, [r4, #2]
	add r0, sp, #0
	ldrb r2, [r0, #5]
	ldrb r1, [r0, #1]
	add r1, r2, r1
	strb r1, [r0, #5]
	ldrb r0, [r0, #5]
	mov r1, #0x3c
	bl _s32_div_f
	add r1, sp, #0
	ldrb r2, [r1, #4]
	add r0, r2, r0
	strb r0, [r1, #4]
	ldrb r0, [r1, #5]
	mov r1, #0x3c
	bl _s32_div_f
	strb r1, [r4, #1]
	add r0, sp, #0
	ldrb r2, [r0, #4]
	ldrb r1, [r0]
	add r1, r2, r1
	strb r1, [r0, #4]
	ldrb r0, [r0, #4]
	mov r1, #0x18
	bl _s32_div_f
	strb r1, [r4]
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov45_0222D524


	thumb_func_start ov45_0222D594
ov45_0222D594: ; 0x0222D594
	push {r3, r4, r5, lr}
	sub sp, #8
	ldr r0, [r0]
	add r4, r2, #0
	str r0, [sp, #4]
	ldr r0, [r1]
	add r1, sp, #0
	str r0, [sp]
	ldrb r5, [r1, #2]
	mov r0, #6
	ldrsb r1, [r1, r0]
	lsl r0, r5, #0x18
	asr r0, r0, #0x18
	sub r0, r1, r0
	bpl _0222D5CE
	neg r0, r0
	mov r1, #0x3c
	bl _s32_div_f
	add r2, sp, #0
	ldrb r3, [r2, #6]
	add r0, r0, #1
	mov r1, #0x3c
	mul r1, r0
	add r1, r3, r1
	strb r1, [r2, #6]
	ldrb r1, [r2, #5]
	sub r0, r1, r0
	strb r0, [r2, #5]
_0222D5CE:
	add r1, sp, #0
	ldrb r0, [r1, #6]
	sub r0, r0, r5
	strb r0, [r4, #2]
	ldrb r5, [r1, #1]
	mov r0, #5
	ldrsb r1, [r1, r0]
	lsl r0, r5, #0x18
	asr r0, r0, #0x18
	sub r0, r1, r0
	bpl _0222D600
	neg r0, r0
	mov r1, #0x3c
	bl _s32_div_f
	add r2, sp, #0
	ldrb r3, [r2, #5]
	add r0, r0, #1
	mov r1, #0x3c
	mul r1, r0
	add r1, r3, r1
	strb r1, [r2, #5]
	ldrb r1, [r2, #4]
	sub r0, r1, r0
	strb r0, [r2, #4]
_0222D600:
	add r1, sp, #0
	ldrb r0, [r1, #5]
	sub r0, r0, r5
	strb r0, [r4, #1]
	mov r0, #4
	ldrsb r2, [r1, r0]
	mov r0, #0
	ldrsb r0, [r1, r0]
	sub r0, r2, r0
	bpl _0222D62A
	neg r0, r0
	mov r1, #0x18
	bl _s32_div_f
	add r1, sp, #0
	add r2, r0, #1
	mov r0, #0x18
	ldrb r3, [r1, #4]
	mul r0, r2
	add r0, r3, r0
	strb r0, [r1, #4]
_0222D62A:
	add r0, sp, #0
	ldrb r1, [r0, #4]
	ldrb r0, [r0]
	sub r0, r1, r0
	strb r0, [r4]
	add sp, #8
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222D594

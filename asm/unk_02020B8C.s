	.include "asm/macros.inc"
	.include "unk_02020B8C.inc"
	.include "global.inc"

	.text
	.public CalcAngleBetweenVecs
	.public GetDistanceFromPointToLine
	.public sub_02020B8C
	.public sub_02020B94
	.public sub_02020D2C
	.public sub_02020DA4
	.public sub_02020EB0

	thumb_func_start sub_02020E10
sub_02020E10: ; 0x02020E10
	push {r3, r4, r5, r6, r7, lr}
	asr r0, r0, #4
	add r7, r2, #0
	lsl r2, r0, #1
	add r6, r1, #0
	lsl r0, r2, #1
	ldr r1, _02020E7C ; =FX_SinCosTable_
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r0, [r1, r0]
	ldrsh r1, [r1, r2]
	add r5, r3, #0
	ldr r4, [sp, #0x18]
	bl FX_Div
	add r2, r0, #0
	asr r1, r6, #0x1f
	add r0, r6, #0
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r6, #2
	mov r2, #0
	lsl r6, r6, #0xa
	add r0, r0, r6
	adc r1, r2
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	asr r3, r0, #0x1f
	lsr r1, r0, #0x13
	lsl r3, r3, #0xd
	orr r3, r1
	lsl r0, r0, #0xd
	add r0, r0, r6
	adc r3, r2
	lsl r1, r3, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	asr r1, r0, #0x1f
	asr r3, r7, #0x1f
	add r2, r7, #0
	str r0, [r4]
	bl _ll_mul
	mov r3, #0
	add r2, r6, #0
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r1, r2, #0xc
	orr r1, r0
	str r1, [r5]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02020E7C: .word FX_SinCosTable_
	thumb_func_end sub_02020E10


	thumb_func_start sub_02020E80
sub_02020E80: ; 0x02020E80
	push {r4, r5, r6, r7}
	ldr r6, [r2, #4]
	ldr r7, [r1]
	ldr r4, [r0, #4]
	ldr r5, [r1, #4]
	sub r1, r6, r4
	add r3, r7, #0
	mul r3, r1
	ldr r2, [r2]
	sub r1, r4, r5
	mul r1, r2
	ldr r2, [r0]
	sub r0, r5, r6
	mul r0, r2
	add r0, r1, r0
	add r0, r3, r0
	bmi _02020EA8
	mov r0, #1
	pop {r4, r5, r6, r7}
	bx lr
_02020EA8:
	mov r0, #0
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
	thumb_func_end sub_02020E80

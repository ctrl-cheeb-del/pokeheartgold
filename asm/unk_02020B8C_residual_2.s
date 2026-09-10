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

	thumb_func_start sub_02020EF4
sub_02020EF4: ; 0x02020EF4
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	add r4, r1, #0
	sub r1, r3, r4
	ldr r0, [sp, #0x18]
	add r6, r2, #0
	sub r0, r0, r6
	lsl r0, r0, #0x10
	lsl r1, r1, #0x10
	asr r0, r0, #0x10
	asr r1, r1, #0x10
	beq _02020F1A
	lsl r0, r0, #0xc
	lsl r1, r1, #0xc
	bl FX_Div
	str r0, [sp]
	b _02020F20
_02020F1A:
	mov r0, #0xff
	lsl r0, r0, #0xc
	str r0, [sp]
_02020F20:
	ldr r0, [sp]
	lsl r2, r4, #0xc
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r3, #2
	mov r4, #0
	lsl r3, r3, #0xa
	lsl r2, r6, #0xc
	add r3, r0, r3
	adc r1, r4
	lsl r0, r1, #0x14
	lsr r1, r3, #0xc
	orr r1, r0
	ldr r0, [sp]
	sub r1, r2, r1
	str r0, [r5]
	str r1, [sp, #4]
	str r1, [r5, #4]
	add sp, #8
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02020EF4


	thumb_func_start sub_02020F4C
sub_02020F4C: ; 0x02020F4C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	ldr r4, [sp, #0x48]
	add r7, r0, #0
	add r5, r1, #0
	add r6, r3, #0
	str r2, [sp, #4]
	cmp r4, #0
	beq _02020F64
	ldr r0, _0202109C ; =0x0000FFFF
	str r0, [r4]
	str r0, [r4, #4]
_02020F64:
	ldr r2, [sp, #4]
	add r0, r7, #0
	add r1, r5, #0
	add r3, r6, #0
	bl sub_02020EB0
	cmp r0, #0
	bne _02020F7A
	add sp, #0x34
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_02020F7A:
	ldr r0, [r5, #4]
	str r0, [sp]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	ldr r3, [r5]
	add r0, sp, #0x24
	bl sub_02020EF4
	ldr r0, [r6, #4]
	ldr r1, [sp, #4]
	str r0, [sp]
	ldr r2, [sp, #4]
	ldr r1, [r1]
	ldr r2, [r2, #4]
	ldr r3, [r6]
	add r0, sp, #0x1c
	bl sub_02020EF4
	ldr r1, [sp, #0x1c]
	ldr r3, [sp, #0x24]
	cmp r3, r1
	bne _02020FAC
	add sp, #0x34
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_02020FAC:
	ldr r2, [sp, #0x20]
	ldr r0, [sp, #0x28]
	sub r1, r3, r1
	sub r0, r2, r0
	bl FX_Div
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x1c]
	ldr r2, [sp, #0xc]
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	add r2, r0, #0
	ldr r0, [sp, #0x20]
	mov r3, #0
	str r0, [sp, #0x10]
	mov r0, #2
	lsl r0, r0, #0xa
	add r0, r2, r0
	adc r1, r3
	lsr r0, r0, #0xc
	lsl r1, r1, #0x14
	str r0, [sp, #0x14]
	orr r0, r1
	str r0, [sp, #0x14]
	ldr r0, [sp, #0xc]
	add r1, sp, #0x30
	bl FX_Modf
	mov r1, #2
	lsl r1, r1, #0xa
	cmp r0, r1
	blt _02020FF8
	ldr r2, [sp, #0x30]
	lsl r0, r1, #1
	add r0, r2, r0
	str r0, [sp, #0x30]
_02020FF8:
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x10]
	asr r0, r0, #0xc
	str r0, [r4]
	ldr r0, [sp, #0x14]
	add r0, r1, r0
	add r1, sp, #0x2c
	bl FX_Modf
	mov r1, #2
	lsl r1, r1, #0xa
	cmp r0, r1
	blt _0202101A
	ldr r2, [sp, #0x2c]
	lsl r0, r1, #1
	add r0, r2, r0
	str r0, [sp, #0x2c]
_0202101A:
	ldr r0, [sp, #0x2c]
	asr r0, r0, #0xc
	str r0, [r4, #4]
	ldr r1, [r5]
	ldr r0, [r7]
	cmp r0, r1
	blt _0202102C
	mov ip, r0
	b _02021030
_0202102C:
	mov ip, r1
	add r1, r0, #0
_02021030:
	ldr r2, [r5, #4]
	ldr r0, [r7, #4]
	cmp r0, r2
	blt _0202103C
	str r0, [sp, #8]
	b _02021040
_0202103C:
	str r2, [sp, #8]
	add r2, r0, #0
_02021040:
	ldr r0, [sp, #4]
	ldr r3, [r6]
	ldr r0, [r0]
	cmp r0, r3
	blt _0202104E
	str r0, [sp, #0x18]
	b _02021052
_0202104E:
	str r3, [sp, #0x18]
	add r3, r0, #0
_02021052:
	ldr r0, [sp, #4]
	ldr r5, [r6, #4]
	ldr r0, [r0, #4]
	cmp r0, r5
	blt _02021060
	add r7, r0, #0
	b _02021064
_02021060:
	add r7, r5, #0
	add r5, r0, #0
_02021064:
	ldr r0, [r4]
	mov r6, ip
	cmp r6, r0
	blt _02021094
	cmp r1, r0
	bgt _02021094
	ldr r1, [r4, #4]
	ldr r4, [sp, #8]
	cmp r4, r1
	blt _02021094
	cmp r2, r1
	bgt _02021094
	ldr r2, [sp, #0x18]
	cmp r2, r0
	blt _02021094
	cmp r3, r0
	bgt _02021094
	cmp r7, r1
	blt _02021094
	cmp r5, r1
	bgt _02021094
	add sp, #0x34
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02021094:
	mov r0, #0
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	nop
_0202109C: .word 0x0000FFFF
	thumb_func_end sub_02020F4C

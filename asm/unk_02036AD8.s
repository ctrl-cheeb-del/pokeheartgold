	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	.public sub_02036D14
	thumb_func_start sub_02036AD8
sub_02036AD8: ; 0x02036AD8
	push {r4, lr}
	ldr r0, _02036BD0 ; =_021D4140
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02036BCE
	bl sub_0203993C
	bl sub_02034044
	cmp r0, #0
	bne _02036BCE
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_0203772C
	add r4, r0, #0
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	bl sub_02033298
	cmp r0, #4
	bne _02036BCE
	bl sub_0203769C
	bl sub_020373B4
	cmp r0, #0
	bne _02036B22
	bl sub_0203769C
	pop {r4, pc}
_02036B22:
	ldr r0, _02036BD4 ; =_0210F900
	ldrb r1, [r0, #1]
	cmp r1, #2
	beq _02036B30
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne _02036BCE
_02036B30:
	bl sub_0203769C
	cmp r0, #0
	beq _02036B84
	ldr r0, _02036BD4 ; =_0210F900
	ldr r3, _02036BD8 ; =sub_02036AA0
	ldrb r1, [r0, #1]
	mov r2, #0xe
	add r1, r1, #1
	strb r1, [r0, #1]
	ldr r0, _02036BD0 ; =_021D4140
	ldr r1, [r0, #8]
	ldr r0, _02036BDC ; =0x000006AF
	ldrb r0, [r1, r0]
	lsl r0, r0, #6
	add r0, r1, r0
	lsl r1, r4, #0x10
	lsr r1, r1, #0x10
	bl sub_02033800
	cmp r0, #0
	bne _02036B66
	ldr r0, _02036BD4 ; =_0210F900
	ldrb r1, [r0, #1]
	sub r1, r1, #1
	strb r1, [r0, #1]
	pop {r4, pc}
_02036B66:
	ldr r2, _02036BD0 ; =_021D4140
	ldr r1, _02036BDC ; =0x000006AF
	ldr r4, [r2, #8]
	mov r0, #1
	ldrb r3, [r4, r1]
	sub r0, r0, r3
	strb r0, [r4, r1]
	add r0, r1, #0
	ldr r2, [r2, #8]
	sub r0, #0x47
	ldr r0, [r2, r0]
	sub r1, #0x47
	add r0, r0, #1
	str r0, [r2, r1]
	pop {r4, pc}
_02036B84:
	bl sub_02033250
	ldr r1, _02036BE0 ; =0x0000FFFE
	tst r0, r1
	beq _02036BCE
	ldr r0, _02036BD4 ; =_0210F900
	ldrb r1, [r0, #1]
	add r1, r1, #1
	strb r1, [r0, #1]
	mov r0, #1
	bl sub_02036AA0
	ldr r0, _02036BD0 ; =_021D4140
	ldr r1, _02036BDC ; =0x000006AF
	ldr r2, [r0, #8]
	mov r0, #0
	ldrb r1, [r2, r1]
	lsl r1, r1, #6
	add r1, r2, r1
	lsl r2, r4, #0x10
	lsr r2, r2, #0x10
	bl sub_0203690C
	ldr r2, _02036BD0 ; =_021D4140
	ldr r1, _02036BDC ; =0x000006AF
	ldr r4, [r2, #8]
	mov r0, #1
	ldrb r3, [r4, r1]
	sub r0, r0, r3
	strb r0, [r4, r1]
	add r0, r1, #0
	ldr r2, [r2, #8]
	sub r0, #0x47
	ldr r0, [r2, r0]
	sub r1, #0x47
	add r0, r0, #1
	str r0, [r2, r1]
_02036BCE:
	pop {r4, pc}
	.balign 4, 0
_02036BD0: .word _021D4140
_02036BD4: .word _0210F900
_02036BD8: .word sub_02036AA0
_02036BDC: .word 0x000006AF
_02036BE0: .word 0x0000FFFE
	thumb_func_end sub_02036AD8
	thumb_func_start sub_02036BE4
sub_02036BE4: ; 0x02036BE4
	push {r3, r4, r5, r6, r7, lr}
	ldr r7, _02036D08 ; =_021D4140
	mov r2, #0x66
	ldr r5, [r7, #8]
	lsl r2, r2, #4
	ldrb r0, [r5, r2]
	mov r6, #0
	add r4, r6, #0
	cmp r0, #0
	beq _02036C02
	sub r1, r2, #4
	ldrh r1, [r5, r1]
	mov r3, #0xf0
	tst r3, r1
	bne _02036C04
_02036C02:
	b _02036D06
_02036C04:
	cmp r0, #2
	bne _02036C42
	mov r0, #0x20
	tst r0, r1
	beq _02036C16
	mov r0, #0x10
	orr r0, r6
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
_02036C16:
	mov r0, #0x10
	tst r0, r1
	beq _02036C24
	mov r0, #0x20
	orr r0, r4
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
_02036C24:
	mov r0, #0x40
	tst r0, r1
	beq _02036C32
	mov r0, #0x80
	orr r0, r4
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
_02036C32:
	mov r0, #0x80
	tst r0, r1
	beq _02036CF0
	mov r0, #0x40
	orr r0, r4
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	b _02036CF0
_02036C42:
	add r0, r2, #2
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _02036C64
	add r4, r0, #0
	add r0, r2, #1
	ldrsb r0, [r5, r0]
	sub r1, r0, #1
	add r0, r2, #1
	strb r1, [r5, r0]
	ldr r1, [r7, #8]
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _02036CF0
	add r0, r2, #2
	strh r6, [r1, r0]
	b _02036CF0
_02036C64:
	add r0, r2, #0
	sub r0, #0x34
	add r6, r5, r0
	sub r2, #0x34
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	ldr r2, [r5, r2]
	ldr r3, [r6, #4]
	bl _ll_mul
	add r3, r0, #0
	add r2, r1, #0
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	add r0, r0, r3
	adc r1, r2
	ldr r2, _02036D0C ; =0x0000062C
	str r0, [r5, r2]
	mov r2, #0
	str r1, [r6, #4]
	lsr r0, r1, #0x1e
	lsl r1, r2, #2
	orr r1, r0
	cmp r1, #3
	bhi _02036CB8
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02036CA2: ; jump table
	.short _02036CAA - _02036CA2 - 2 ; case 0
	.short _02036CAE - _02036CA2 - 2 ; case 1
	.short _02036CB2 - _02036CA2 - 2 ; case 2
	.short _02036CB6 - _02036CA2 - 2 ; case 3
_02036CAA:
	mov r4, #0x20
	b _02036CB8
_02036CAE:
	mov r4, #0x10
	b _02036CB8
_02036CB2:
	mov r4, #0x40
	b _02036CB8
_02036CB6:
	mov r4, #0x80
_02036CB8:
	ldr r0, _02036D08 ; =_021D4140
	ldr r5, [r0, #8]
	ldr r0, _02036D0C ; =0x0000062C
	add r6, r5, r0
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	ldr r2, [r6]
	ldr r3, [r6, #4]
	bl _ll_mul
	ldr r3, [r6, #0x10]
	ldr r2, [r6, #0x14]
	add r0, r3, r0
	adc r2, r1
	ldr r1, _02036D0C ; =0x0000062C
	mov r3, #0
	str r0, [r5, r1]
	str r2, [r6, #4]
	lsr r0, r2, #0x1c
	lsl r2, r3, #4
	orr r2, r0
	add r0, r1, #0
	add r0, #0x35
	strb r2, [r5, r0]
	ldr r0, _02036D08 ; =_021D4140
	add r1, #0x36
	ldr r0, [r0, #8]
	strh r4, [r0, r1]
_02036CF0:
	ldr r2, _02036D08 ; =_021D4140
	ldr r1, _02036D10 ; =0x0000065C
	ldr r5, [r2, #8]
	mov r0, #0xf0
	ldrh r3, [r5, r1]
	bic r3, r0
	strh r3, [r5, r1]
	ldr r2, [r2, #8]
	ldrh r0, [r2, r1]
	add r0, r0, r4
	strh r0, [r2, r1]
_02036D06:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02036D08: .word _021D4140
_02036D0C: .word 0x0000062C
_02036D10: .word 0x0000065C
	thumb_func_end sub_02036BE4

	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	.public sub_02036298
	.public sub_02036438
	.public sub_02036508
	.public sub_02036438
	thumb_func_start sub_02036508
sub_02036508: ; 0x02036508
	push {r3, r4, r5, r6, r7, lr}
	ldr r0, _02036620 ; =_021D4140
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _02036514
	b _0203661C
_02036514:
	bl sub_0203993C
	bl sub_02034044
	cmp r0, #0
	bne _0203661C
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_0203772C
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r6, r0, #1
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	cmp r1, #2
	beq _02036548
	ldrb r0, [r0]
	cmp r0, #0
	bne _0203661C
_02036548:
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	add r1, r1, #1
	strb r1, [r0]
	bl sub_02035FF0
	cmp r0, #1
	bne _02036572
	ldr r0, _02036620 ; =_021D4140
	ldrb r1, [r0]
	cmp r1, #0
	bne _02036572
	ldr r1, [r0, #8]
	mov r0, #0x6b
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	bl sub_02036438
	ldr r0, _02036620 ; =_021D4140
	mov r1, #1
	strb r1, [r0]
_02036572:
	bl sub_02033298
	cmp r0, #4
	bne _020365A4
	ldr r0, _02036620 ; =_021D4140
	ldr r1, [r0, #8]
	mov r0, #0x6b
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	add r3, r1, #0
	mov r1, #0xc0
	add r2, r0, #0
	add r3, #0x80
	mul r2, r1
	add r0, r3, r2
	ldr r3, _02036628 ; =sub_02036ABC
	mov r2, #0xe
	bl sub_02033800
	cmp r0, #0
	bne _020365A4
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	sub r1, r1, #1
	strb r1, [r0]
_020365A4:
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	cmp r1, #1
	beq _020365B2
	ldrb r0, [r0]
	cmp r0, #3
	bne _0203660C
_020365B2:
	ldr r7, _02036620 ; =_021D4140
	mov r4, #0
	strb r4, [r7]
	cmp r6, #0
	ble _020365E0
	add r5, r4, #0
_020365BE:
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #0
	beq _020365D8
	ldr r0, [r7, #8]
	ldr r1, _0203662C ; =0x0000066C
	add r0, r0, r5
	ldr r1, [r0, r1]
	add r2, r1, #1
	ldr r1, _0203662C ; =0x0000066C
	str r2, [r0, r1]
_020365D8:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r6
	blt _020365BE
_020365E0:
	ldr r0, _02036620 ; =_021D4140
	mov r1, #0x6b
	ldr r2, [r0, #8]
	lsl r1, r1, #4
	ldrb r1, [r2, r1]
	add r4, r2, #0
	mov r2, #0xc0
	add r3, r1, #0
	add r4, #0x80
	mul r3, r2
	mov r0, #0
	add r1, r4, r3
	bl sub_020367B0
	ldr r0, _02036620 ; =_021D4140
	mov r1, #0x6b
	ldr r3, [r0, #8]
	lsl r1, r1, #4
	ldrb r2, [r3, r1]
	mov r0, #1
	sub r0, r0, r2
	strb r0, [r3, r1]
_0203660C:
	bl sub_02033298
	cmp r0, #4
	beq _0203661C
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	add r1, r1, #1
	strb r1, [r0]
_0203661C:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02036620: .word _021D4140
_02036624: .word _0210F900
_02036628: .word sub_02036ABC
_0203662C: .word 0x0000066C
	thumb_func_end sub_02036508

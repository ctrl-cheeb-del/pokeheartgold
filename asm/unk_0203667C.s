	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0203667C
sub_0203667C: ; 0x0203667C
	push {r3, r4, r5, r6, r7, lr}
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r6, r0, #1
	bl sub_0203993C
	bl sub_02034044
	cmp r0, #0
	beq _02036738
	mov r0, #0
	bl sub_020373B4
	cmp r0, #0
	beq _02036796
	ldr r0, _02036798 ; =_021D4140
	ldr r1, [r0, #8]
	ldr r0, _0203679C ; =0x00000664
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _020366D4
	bl sub_02036630
	cmp r0, #0
	beq _02036796
	ldr r0, _020367A0 ; =_0210F900
	ldrb r0, [r0]
	cmp r0, #4
	bne _020366F4
	bl sub_02035FF0
	cmp r0, #1
	bne _020366CC
	mov r0, #0
	bl sub_02036438
_020366CC:
	ldr r0, _020367A0 ; =_0210F900
	mov r1, #2
	strb r1, [r0]
	b _020366F4
_020366D4:
	ldr r0, _020367A0 ; =_0210F900
	ldrb r0, [r0]
	cmp r0, #4
	bne _020366EE
	bl sub_02035FF0
	cmp r0, #1
	bne _020366EE
	mov r0, #0
	bl sub_02036438
	cmp r0, #0
	beq _02036796
_020366EE:
	ldr r0, _020367A0 ; =_0210F900
	mov r1, #2
	strb r1, [r0]
_020366F4:
	ldr r0, _02036798 ; =_021D4140
	mov r1, #0xc0
	ldr r0, [r0, #8]
	add r0, #0x80
	bl ov00_021E602C
	cmp r0, #0
	beq _02036796
	ldr r0, _020367A0 ; =_0210F900
	mov r1, #4
	mov r4, #0
	strb r1, [r0]
	cmp r6, #0
	ble _02036796
	ldr r7, _02036798 ; =_021D4140
	add r5, r4, #0
_02036714:
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #0
	beq _0203672E
	ldr r0, [r7, #8]
	ldr r1, _020367A4 ; =0x0000066C
	add r0, r0, r5
	ldr r1, [r0, r1]
	add r2, r1, #1
	ldr r1, _020367A4 ; =0x0000066C
	str r2, [r0, r1]
_0203672E:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r6
	blt _02036714
	pop {r3, r4, r5, r6, r7, pc}
_02036738:
	bl sub_02033298
	cmp r0, #4
	bne _02036796
	ldr r0, _020367A0 ; =_0210F900
	ldrb r0, [r0]
	cmp r0, #4
	bne _02036796
	bl sub_02036630
	cmp r0, #0
	beq _02036796
	bl sub_02035FF0
	cmp r0, #0
	bne _0203678C
	ldr r0, _02036798 ; =_021D4140
	ldr r1, [r0, #8]
	mov r0, #0x6b
	add r2, r1, #0
	lsl r0, r0, #4
	ldrb r1, [r1, r0]
	mov r0, #0xc0
	add r2, #0x80
	mul r0, r1
	add r0, r2, r0
	bl sub_02036F30
	ldr r0, _02036798 ; =_021D4140
	ldr r1, [r0, #8]
	mov r0, #0x6b
	add r2, r1, #0
	lsl r0, r0, #4
	ldrb r1, [r1, r0]
	mov r0, #1
	add r2, #0x80
	sub r1, r0, r1
	mov r0, #0xc0
	mul r0, r1
	add r0, r2, r0
	bl sub_02036F30
_0203678C:
	ldr r0, _020367A0 ; =_0210F900
	mov r1, #0
	strb r1, [r0]
	bl sub_02036508
_02036796:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02036798: .word _021D4140
_0203679C: .word 0x00000664
_020367A0: .word _0210F900
_020367A4: .word 0x0000066C
	thumb_func_end sub_0203667C

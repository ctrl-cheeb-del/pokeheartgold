	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02037334
sub_02037334: ; 0x02037334
	push {r3, r4, r5, r6, r7, lr}
	ldr r0, _020373A4 ; =_021D4140
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _020373A0
	ldr r0, _020373A8 ; =0x000006BA
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _020373A0
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r0, r0, #1
	mov r4, #0
	str r0, [sp]
	cmp r0, #0
	ble _020373A0
	ldr r7, _020373A4 ; =_021D4140
	add r5, r4, #0
_02037360:
	ldr r1, [r7, #8]
	ldr r0, _020373AC ; =0x0000051C
	add r0, r1, r0
	add r0, r0, r5
	bl sub_02033C28
	ldr r1, [r7, #8]
	ldr r0, _020373AC ; =0x0000051C
	add r0, r1, r0
	add r0, r0, r5
	bl sub_02033BC4
	cmp r0, #0
	ble _02037396
	mov r3, #0x17
	ldr r6, [r7, #8]
	ldr r0, _020373AC ; =0x0000051C
	ldr r2, _020373B0 ; =0x00000494
	lsl r3, r3, #6
	add r0, r6, r0
	add r3, r6, r3
	ldr r2, [r6, r2]
	add r0, r0, r5
	add r1, r4, #0
	add r3, r3, r5
	bl sub_020371C4
_02037396:
	ldr r0, [sp]
	add r4, r4, #1
	add r5, #0xc
	cmp r4, r0
	blt _02037360
_020373A0:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_020373A4: .word _021D4140
_020373A8: .word 0x000006BA
_020373AC: .word 0x0000051C
_020373B0: .word 0x00000494
	thumb_func_end sub_02037334

	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02037FF0
sub_02037FF0: ; 0x02037FF0
	push {r3, lr}
	mov r0, #0
	bl sub_02033AA4
	ldr r0, _02038064 ; =_021D4150
	ldr r1, [r0]
	add r0, r1, #0
	add r0, #0x53
	ldrb r0, [r0]
	cmp r0, #1
	bne _02038018
	add r0, r1, #0
	add r0, #0x54
	ldrb r0, [r0]
	cmp r0, #1
	bne _02038018
	add r1, #0x4e
	ldrb r0, [r1]
	cmp r0, #9
	bne _02038020
_02038018:
	mov r0, #0
	add r1, r0, #0
	bl sub_020398D4
_02038020:
	bl sub_0203A914
	ldr r0, _02038064 ; =_021D4150
	mov r2, #9
	ldr r1, [r0]
	add r1, #0x4e
	strb r2, [r1]
	ldr r1, [r0]
	mov r2, #0
	add r1, #0x57
	strb r2, [r1]
	ldr r0, [r0]
	add r0, #0x4a
	ldrb r0, [r0]
	bl sub_02033908
	bl sub_0203769C
	cmp r0, #0
	bne _02038058
	mov r0, #1
	bl sub_02033ACC
	ldr r0, _02038068 ; =sub_02038418
	mov r1, #0xf
	bl sub_020381C0
	pop {r3, pc}
_02038058:
	ldr r0, _0203806C ; =sub_02038460
	mov r1, #5
	bl sub_020381C0
	pop {r3, pc}
	nop
_02038064: .word _021D4150
_02038068: .word sub_02038418
_0203806C: .word sub_02038460
	thumb_func_end sub_02037FF0

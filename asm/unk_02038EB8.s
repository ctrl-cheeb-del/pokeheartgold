	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02038EB8
sub_02038EB8: ; 0x02038EB8
	push {r3, lr}
	mov r0, #1
	bl sub_0203786C
	mov r0, #0
	bl ov00_021E5E54
	cmp r0, #0xa
	blt _02038ED8
	cmp r0, #0x14
	bge _02038ED8
	ldr r0, _02038F60 ; =sub_02038EB4
	mov r1, #0
	bl sub_020381C0
	b _02038F3A
_02038ED8:
	cmp r0, #0
	bge _02038EE6
	ldr r0, _02038F64 ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
	b _02038F3A
_02038EE6:
	cmp r0, #0x17
	bne _02038EF4
	ldr r0, _02038F68 ; =sub_02038E94
	mov r1, #0
	bl sub_020381C0
	b _02038F3A
_02038EF4:
	cmp r0, #0x18
	bne _02038F18
	ldr r0, _02038F6C ; =_021D4150
	ldr r0, [r0]
	add r0, #0x53
	ldrb r0, [r0]
	cmp r0, #0
	beq _02038F0E
	ldr r0, _02038F64 ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
	b _02038F3A
_02038F0E:
	ldr r0, _02038F70 ; =sub_02038EB0
	mov r1, #0
	bl sub_020381C0
	b _02038F3A
_02038F18:
	cmp r0, #0x15
	bne _02038F3A
	ldr r0, _02038F6C ; =_021D4150
	ldr r0, [r0]
	add r0, #0x53
	ldrb r0, [r0]
	cmp r0, #0
	beq _02038F32
	ldr r0, _02038F64 ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
	b _02038F3A
_02038F32:
	ldr r0, _02038F70 ; =sub_02038EB0
	mov r1, #0
	bl sub_020381C0
_02038F3A:
	ldr r0, _02038F6C ; =_021D4150
	ldr r0, [r0]
	add r0, #0x53
	ldrb r0, [r0]
	cmp r0, #0
	beq _02038F5E
	bl sub_02037454
	ldr r1, _02038F6C ; =_021D4150
	ldr r1, [r1]
	add r1, #0x4b
	ldrb r1, [r1]
	cmp r1, r0
	beq _02038F5E
	ldr r0, _02038F64 ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
_02038F5E:
	pop {r3, pc}
	.balign 4, 0
_02038F60: .word sub_02038EB4
_02038F64: .word sub_02038E90
_02038F68: .word sub_02038E94
_02038F6C: .word _021D4150
_02038F70: .word sub_02038EB0
	thumb_func_end sub_02038EB8
	thumb_func_start sub_02038F74
sub_02038F74: ; 0x02038F74
	push {r3, r4}
	ldr r3, _02038F98 ; =_021D4150
	ldr r4, [r3]
	cmp r4, #0
	beq _02038F94
	add r3, r0, #0
	sub r3, #0x19
	cmp r3, #1
	bls _02038F88
	neg r0, r0
_02038F88:
	str r0, [r4, #0x34]
	ldr r0, _02038F98 ; =_021D4150
	ldr r3, [r0]
	str r1, [r3, #0x38]
	ldr r0, [r0]
	str r2, [r0, #0x3c]
_02038F94:
	pop {r3, r4}
	bx lr
	.balign 4, 0
_02038F98: .word _021D4150
	thumb_func_end sub_02038F74
	thumb_func_start sub_02038F9C
sub_02038F9C: ; 0x02038F9C
	push {r3, lr}
	mov r0, #0
	bl ov00_021E5E54
	cmp r0, #0xa
	blt _02038FB6
	cmp r0, #0x14
	bge _02038FB6
	ldr r0, _02038FFC ; =sub_02038EB4
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038FB6:
	cmp r0, #0
	bge _02038FC4
	ldr r0, _02039000 ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038FC4:
	cmp r0, #0x14
	bne _02038FD2
	ldr r0, _02039004 ; =sub_02038EB8
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038FD2:
	cmp r0, #0x15
	bne _02038FE0
	ldr r0, _02039008 ; =sub_02038EB0
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038FE0:
	cmp r0, #0x16
	bne _02038FEE
	ldr r0, _02038FFC ; =sub_02038EB4
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038FEE:
	cmp r0, #0x18
	bne _02038FFA
	ldr r0, _02039008 ; =sub_02038EB0
	mov r1, #0
	bl sub_020381C0
_02038FFA:
	pop {r3, pc}
	.balign 4, 0
_02038FFC: .word sub_02038EB4
_02039000: .word sub_02038E90
_02039004: .word sub_02038EB8
_02039008: .word sub_02038EB0
	thumb_func_end sub_02038F9C
	thumb_func_start sub_0203900C
sub_0203900C: ; 0x0203900C
	push {r3, lr}
	mov r0, #1
	bl ov00_021E5E54
	cmp r0, #0
	bge _02039022
	ldr r0, _02039074 ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02039022:
	ldr r0, _02039078 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x4e
	ldrb r0, [r0]
	bl sub_02033FC4
	add r2, r0, #0
	ldr r0, _02039078 ; =_021D4150
	ldr r1, [r0]
	mov r0, #0x51
	ldrsb r0, [r1, r0]
	add r1, r2, #1
	mov r2, #0
	bl ov00_021E6D7C
	add r0, r0, #3
	cmp r0, #3
	bhi _02039070
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02039052: ; jump table
	.short _02039068 - _02039052 - 2 ; case 0
	.short _02039070 - _02039052 - 2 ; case 1
	.short _02039070 - _02039052 - 2 ; case 2
	.short _0203905A - _02039052 - 2 ; case 3
_0203905A:
	bl sub_0203622C
	ldr r0, _0203907C ; =sub_02038F9C
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02039068:
	ldr r0, _02039074 ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
_02039070:
	pop {r3, pc}
	nop
_02039074: .word sub_02038E90
_02039078: .word _021D4150
_0203907C: .word sub_02038F9C
	thumb_func_end sub_0203900C

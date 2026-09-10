	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020390C4
sub_020390C4: ; 0x020390C4
	ldr r0, _02039120 ; =_021D4150
	ldr r1, _02039124 ; =sub_02038F9C
	ldr r0, [r0]
	ldr r0, [r0, #0x24]
	cmp r0, r1
	bne _020390D4
	mov r0, #0
	bx lr
_020390D4:
	ldr r1, _02039128 ; =sub_02038EB8
	cmp r0, r1
	bne _020390DE
	mov r0, #1
	bx lr
_020390DE:
	ldr r1, _0203912C ; =sub_02038E94
	cmp r0, r1
	bne _020390E8
	mov r0, #3
	bx lr
_020390E8:
	ldr r1, _02039130 ; =sub_02038EB0
	cmp r0, r1
	bne _020390F2
	mov r0, #4
	bx lr
_020390F2:
	ldr r1, _02039134 ; =sub_02038EB4
	cmp r0, r1
	bne _020390FC
	mov r0, #5
	bx lr
_020390FC:
	ldr r1, _02039138 ; =sub_02039DE4
	cmp r0, r1
	bne _02039106
	mov r0, #0
	bx lr
_02039106:
	ldr r1, _0203913C ; =sub_02039DC4
	cmp r0, r1
	bne _02039110
	mov r0, #1
	bx lr
_02039110:
	ldr r1, _02039140 ; =sub_02039E7C
	cmp r0, r1
	bne _0203911A
	mov r0, #3
	bx lr
_0203911A:
	mov r0, #2
	bx lr
	nop
_02039120: .word _021D4150
_02039124: .word sub_02038F9C
_02039128: .word sub_02038EB8
_0203912C: .word sub_02038E94
_02039130: .word sub_02038EB0
_02039134: .word sub_02038EB4
_02039138: .word sub_02039DE4
_0203913C: .word sub_02039DC4
_02039140: .word sub_02039E7C
	thumb_func_end sub_020390C4
	thumb_func_start sub_02039144
sub_02039144: ; 0x02039144
	push {r3, lr}
	ldr r0, _020391BC ; =sub_02036904
	ldr r1, _020391C0 ; =sub_020367A8
	bl ov00_021E5C84
	mov r0, #0
	mvn r0, r0
	mov r1, #4
	mov r2, #1
	bl ov00_021E6D7C
	add r0, r0, #4
	cmp r0, #4
	bhi _0203919A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0203916C: ; jump table
	.short _02039198 - _0203916C - 2 ; case 0
	.short _0203918E - _0203916C - 2 ; case 1
	.short _0203919A - _0203916C - 2 ; case 2
	.short _0203919A - _0203916C - 2 ; case 3
	.short _02039176 - _0203916C - 2 ; case 4
_02039176:
	ldr r0, _020391C4 ; =_021D4150
	mov r1, #0
	ldr r0, [r0]
	add r0, #0x5c
	strb r1, [r0]
	bl sub_0203622C
	ldr r0, _020391C8 ; =sub_02038F9C
	mov r1, #0
	bl sub_020381C0
	b _0203919A
_0203918E:
	ldr r0, _020391CC ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
	b _0203919A
_02039198:
	pop {r3, pc}
_0203919A:
	bl ov00_021E6690
	cmp r0, #0
	bge _020391AC
	ldr r0, _020391CC ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_020391AC:
	cmp r0, #0x1a
	bne _020391B8
	ldr r0, _020391CC ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
_020391B8:
	pop {r3, pc}
	nop
_020391BC: .word sub_02036904
_020391C0: .word sub_020367A8
_020391C4: .word _021D4150
_020391C8: .word sub_02038F9C
_020391CC: .word sub_02038E90
	thumb_func_end sub_02039144
	thumb_func_start sub_020391D0
sub_020391D0: ; 0x020391D0
	push {r3, lr}
	mov r0, #0
	bl sub_0203786C
	ldr r0, _02039214 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x50
	ldrb r0, [r0]
	bl ov00_021E6BE4
	cmp r0, #0
	beq _020391FE
	bl ov00_021E6C68
	cmp r0, #0
	beq _020391FE
	bl sub_020343E4
	ldr r0, _02039218 ; =sub_02039144
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_020391FE:
	mov r0, #0
	bl ov00_021E5E54
	cmp r0, #0
	bge _02039210
	ldr r0, _0203921C ; =sub_02038E90
	mov r1, #0
	bl sub_020381C0
_02039210:
	pop {r3, pc}
	nop
_02039214: .word _021D4150
_02039218: .word sub_02039144
_0203921C: .word sub_02038E90
	thumb_func_end sub_020391D0

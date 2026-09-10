	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02039378
sub_02039378: ; 0x02039378
	push {r3, lr}
	ldr r0, _020393AC ; =_021D4150
	ldr r0, [r0]
	cmp r0, #0
	beq _020393AA
	mov r0, #0
	mov r1, #1
	bl sub_020398D4
	bl sub_0203769C
	cmp r0, #0
	bne _02039398
	mov r1, #0
	ldr r0, _020393AC ; =_021D4150
	b _0203939C
_02039398:
	ldr r0, _020393AC ; =_021D4150
	mov r1, #1
_0203939C:
	ldr r0, [r0]
	add r0, #0x50
	strb r1, [r0]
	ldr r0, _020393B0 ; =sub_020391D0
	mov r1, #0
	bl sub_020381C0
_020393AA:
	pop {r3, pc}
	.balign 4, 0
_020393AC: .word _021D4150
_020393B0: .word sub_020391D0
	thumb_func_end sub_02039378

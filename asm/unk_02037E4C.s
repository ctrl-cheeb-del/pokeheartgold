	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02037E4C
sub_02037E4C: ; 0x02037E4C
	push {r3, lr}
	ldr r0, _02037E94 ; =_021D4150
	ldr r1, [r0]
	ldr r0, [r1, #0x40]
	cmp r0, #0
	ble _02037E5E
	sub r0, r0, #1
	str r0, [r1, #0x40]
	b _02037E64
_02037E5E:
	bne _02037E64
	bl sub_020399EC
_02037E64:
	ldr r0, _02037E94 ; =_021D4150
	ldr r1, [r0]
	ldr r0, [r1, #0x44]
	cmp r0, #0
	beq _02037E72
	sub r0, r0, #1
	str r0, [r1, #0x44]
_02037E72:
	bl sub_02034FE8
	cmp r0, #0
	beq _02037E90
	ldr r0, _02037E94 ; =_021D4150
	ldr r0, [r0]
	ldr r0, [r0, #0x44]
	cmp r0, #0
	bne _02037E90
	bl sub_02036024
	ldr r0, _02037E98 ; =sub_02038408
	mov r1, #0
	bl sub_020381C0
_02037E90:
	pop {r3, pc}
	nop
_02037E94: .word _021D4150
_02037E98: .word sub_02038408
	thumb_func_end sub_02037E4C

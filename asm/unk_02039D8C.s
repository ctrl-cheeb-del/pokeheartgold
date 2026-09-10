	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02039D8C
sub_02039D8C: ; 0x02039D8C
	push {r3, lr}
	mov r0, #0
	bl ov00_021E5E54
	bl sub_02039D08
	bl ov45_0222E944
	cmp r0, #0
	beq _02039DB8
	mov r0, #1
	bl sub_0201A738
	bl sub_020343E4
	ldr r0, _02039DBC ; =sub_0203847C
	mov r1, #5
	bl sub_020381C0
	mov r0, #0
	bl sub_0203786C
_02039DB8:
	pop {r3, pc}
	nop
_02039DBC: .word sub_0203847C
	thumb_func_end sub_02039D8C

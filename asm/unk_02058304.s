	.include "asm/macros.inc"
	.include "unk_02058034.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02058304
sub_02058304: ; 0x02058304
	push {r3, lr}
	bl sub_0203769C
	bl sub_020373B4
	cmp r0, #0
	beq _02058322
	bl ov03_02255C54
	bl sub_02034434
	ldr r0, _02058324 ; =sub_02058328
	mov r1, #0
	bl sub_020582F4
_02058322:
	pop {r3, pc}
	.balign 4, 0
_02058324: .word sub_02058328
	thumb_func_end sub_02058304

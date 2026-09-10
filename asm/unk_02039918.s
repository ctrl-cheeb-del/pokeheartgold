	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02039918
sub_02039918: ; 0x02039918
	ldr r0, _02039938 ; =_021D4150
	ldr r1, [r0]
	cmp r1, #0
	beq _02039934
	add r0, r1, #0
	add r0, #0x5d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0203992E
	mov r0, #1
	bx lr
_0203992E:
	add r1, #0x54
	ldrb r0, [r1]
	bx lr
_02039934:
	mov r0, #0
	bx lr
	.balign 4, 0
_02039938: .word _021D4150
	thumb_func_end sub_02039918

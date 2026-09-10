	.include "asm/macros.inc"
	.include "unk_02034B0C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0203569C
sub_0203569C: ; 0x0203569C
	ldr r0, _020356B8 ; =_021D4134
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _020356B2
	ldr r0, _020356BC ; =0x00000D95
	ldrb r0, [r1, r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _020356B2
	mov r0, #1
	bx lr
_020356B2:
	mov r0, #0
	bx lr
	nop
_020356B8: .word _021D4134
_020356BC: .word 0x00000D95
	thumb_func_end sub_0203569C

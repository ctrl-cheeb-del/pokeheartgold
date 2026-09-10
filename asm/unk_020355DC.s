	.include "asm/macros.inc"
	.include "unk_02034B0C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020355DC
sub_020355DC: ; 0x020355DC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0203560C ; =_021D4134
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _020355EC
	mov r0, #0
	pop {r4, pc}
_020355EC:
	bl sub_02033298
	cmp r0, #4
	beq _020355F8
	mov r0, #0
	pop {r4, pc}
_020355F8:
	bl sub_02033250
	mov r2, #1
	add r1, r2, #0
	lsl r1, r4
	tst r0, r1
	bne _02035608
	mov r2, #0
_02035608:
	add r0, r2, #0
	pop {r4, pc}
	.balign 4, 0
_0203560C: .word _021D4134
	thumb_func_end sub_020355DC

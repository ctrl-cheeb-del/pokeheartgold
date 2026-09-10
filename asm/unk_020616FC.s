	.include "asm/macros.inc"
	.include "unk_02061284.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020616FC
sub_020616FC: ; 0x020616FC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl sub_0205F394
	ldr r6, _0206171C ; =_020FD5D0
	add r4, r0, #0
	mov r7, #2
_0206170A:
	ldrsb r2, [r4, r7]
	add r0, r5, #0
	add r1, r4, #0
	lsl r2, r2, #2
	ldr r2, [r6, r2]
	blx r2
	cmp r0, #1
	beq _0206170A
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0206171C: .word _020FD5D0
	thumb_func_end sub_020616FC

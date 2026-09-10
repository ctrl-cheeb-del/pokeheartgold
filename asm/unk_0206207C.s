	.include "asm/macros.inc"
	.include "unk_02061284.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0206207C
sub_0206207C: ; 0x0206207C
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r1, #0
	bl MapObject_GetFacingDirection
	mov r4, #0
	add r6, r0, #0
	add r1, r4, #0
	ldr r0, _020620F4 ; =_020FD7E0
	mov r2, #1
	b _02062096
_02062092:
	add r1, r1, #4
	add r4, r4, #1
_02062096:
	cmp r4, #4
	bge _020620A6
	ldrsb r3, [r5, r2]
	lsl r3, r3, #4
	add r3, r0, r3
	ldr r3, [r1, r3]
	cmp r6, r3
	bne _02062092
_020620A6:
	cmp r4, #4
	blt _020620AE
	bl GF_AssertFail
_020620AE:
	add r0, r4, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	strb r6, [r5]
	mov r0, #1
	add r1, r2, r1
	ldrsb r0, [r5, r0]
	lsl r1, r1, #2
	lsl r2, r0, #4
	ldr r0, _020620F4 ; =_020FD7E0
	add r0, r0, r2
	ldr r4, [r1, r0]
	add r0, r7, #0
	mov r1, #0x80
	bl MapObject_GetFlagsBitsMask
	cmp r0, #0
	beq _020620DC
	mov r0, #1
	b _020620DE
_020620DC:
	mov r0, #0
_020620DE:
	strb r0, [r5, #2]
	add r0, r7, #0
	add r1, r4, #0
	bl MapObject_SetFacingDirection
	add r0, r7, #0
	mov r1, #0x80
	bl MapObject_SetFlagsBits
	pop {r3, r4, r5, r6, r7, pc}
	nop
_020620F4: .word _020FD7E0
	thumb_func_end sub_0206207C

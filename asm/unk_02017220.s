	.include "asm/macros.inc"
	.include "unk_02016EDC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02017220
sub_02017220: ; 0x02017220
	push {r3, r4, r5, lr}
	add r5, r1, #0
	mov r3, #0
	add r0, #0x7c
	mov r2, #0x54
_0201722A:
	add r1, r3, #0
	mul r1, r2
	add r4, r0, r1
	ldr r1, [r0, r1]
	cmp r1, #0
	bne _02017254
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x54
	bl MI_CpuFill8
	mov r0, #1
	str r0, [r4]
	mov r0, #0xc
	add r1, r5, #0
	mul r1, r0
	ldr r0, _02017268 ; =_020F61BC
	ldr r0, [r0, r1]
	str r0, [r4, #0x50]
	add r0, r4, #0
	pop {r3, r4, r5, pc}
_02017254:
	add r1, r3, #1
	lsl r1, r1, #0x18
	lsr r3, r1, #0x18
	cmp r3, #4
	blo _0201722A
	bl GF_AssertFail
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02017268: .word _020F61BC
	thumb_func_end sub_02017220

	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02035DE0
sub_02035DE0: ; 0x02035DE0
	push {r3, r4, r5, r6, r7, lr}
	ldr r4, _02035E84 ; =_021D4140
	add r5, r0, #0
	ldr r0, [r4, #8]
	ldr r3, _02035E88 ; =0x00000696
	mov r1, #0
	add r0, r0, r5
	strb r1, [r0, r3]
	ldr r2, [r4, #8]
	mov r0, #1
	add r6, r2, r5
	add r2, r3, #0
	add r2, #8
	strb r0, [r6, r2]
	ldr r2, [r4, #8]
	lsl r0, r5, #2
	add r0, r2, r0
	sub r3, #0x2a
	str r1, [r0, r3]
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r1, r0, #0
	add r0, r4, #0
	ldr r6, [r0, #8]
	ldr r0, _02035E8C ; =0x0000068C
	add r1, r1, #1
	ldr r0, [r6, r0]
	bl _s32_div_f
	add r7, r5, #0
	mov r1, #0x4b
	str r0, [sp]
	mul r7, r0
	mov r0, #0xc
	add r4, r5, #0
	lsl r1, r1, #4
	mul r4, r0
	add r0, r6, r1
	sub r1, #0x28
	ldr r1, [r6, r1]
	ldr r2, [sp]
	add r0, r0, r4
	add r1, r1, r7
	bl sub_02033AE0
	ldr r0, _02035E84 ; =_021D4140
	ldr r1, _02035E90 ; =0x0000051C
	ldr r2, [r0, #8]
	add r0, r2, r1
	sub r1, #0x90
	ldr r1, [r2, r1]
	ldr r2, [sp]
	add r0, r0, r4
	add r1, r1, r7
	bl sub_02033AE0
	ldr r3, _02035E84 ; =_021D4140
	ldr r2, _02035E94 ; =0x000005CA
	ldr r0, [r3, #8]
	mov r1, #0xee
	add r0, r0, r4
	strb r1, [r0, r2]
	ldr r0, [r3, #8]
	ldr r5, _02035E98 ; =0x0000FFFF
	add r1, r0, r4
	sub r0, r2, #2
	strh r5, [r1, r0]
	ldr r1, [r3, #8]
	mov r0, #0
	add r5, r1, r4
	sub r1, r2, #6
	str r0, [r5, r1]
	ldr r1, [r3, #8]
	sub r2, #0xa
	add r1, r1, r4
	str r0, [r1, r2]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02035E84: .word _021D4140
_02035E88: .word 0x00000696
_02035E8C: .word 0x0000068C
_02035E90: .word 0x0000051C
_02035E94: .word 0x000005CA
_02035E98: .word 0x0000FFFF
	thumb_func_end sub_02035DE0

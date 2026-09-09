	.include "asm/macros.inc"
	.include "unk_0202C034.inc"
	.include "global.inc"

	.bss

	.public _021D2230
_021D2230:
	.space 0x8C0

	.text

	thumb_func_start sub_0202C4F0
sub_0202C4F0: ; 0x0202C4F0
	push {r4, r5, r6, lr}
	add r4, r0, #0
	cmp r1, #0
	blt _0202C548
	cmp r1, #0x20
	bge _0202C548
	mov r5, #0x79
	mov r0, #0x38
	lsl r5, r5, #2
	mul r0, r1
	add r5, r4, r5
	ldrh r6, [r5, r0]
	add r2, r6, r2
	strh r2, [r5, r0]
	ldrh r6, [r5, r0]
	ldr r2, _0202C54C ; =0x0000270F
	cmp r6, r2
	bls _0202C516
	strh r2, [r5, r0]
_0202C516:
	ldr r2, _0202C550 ; =0x000001E6
	add r2, r4, r2
	ldrh r5, [r2, r0]
	add r3, r5, r3
	strh r3, [r2, r0]
	ldrh r5, [r2, r0]
	ldr r3, _0202C54C ; =0x0000270F
	cmp r5, r3
	bls _0202C52A
	strh r3, [r2, r0]
_0202C52A:
	mov r2, #0x7a
	lsl r2, r2, #2
	add r2, r4, r2
	ldrh r5, [r2, r0]
	ldr r3, [sp, #0x10]
	add r3, r5, r3
	strh r3, [r2, r0]
	ldrh r5, [r2, r0]
	ldr r3, _0202C54C ; =0x0000270F
	cmp r5, r3
	bls _0202C542
	strh r3, [r2, r0]
_0202C542:
	add r0, r4, #0
	bl sub_0202C4B0
_0202C548:
	pop {r4, r5, r6, pc}
	nop
_0202C54C: .word 0x0000270F
_0202C550: .word 0x000001E6
	thumb_func_end sub_0202C4F0

	thumb_func_start sub_0202C554
sub_0202C554: ; 0x0202C554
	push {r3, r4, r5, lr}
	cmp r1, #0
	blt _0202C57A
	cmp r1, #0x20
	bge _0202C57A
	ldr r3, _0202C57C ; =0x000001F2
	add r4, r0, r3
	mov r3, #0x38
	mul r3, r1
	ldrh r5, [r4, r3]
	add r2, r5, r2
	strh r2, [r4, r3]
	ldrh r5, [r4, r3]
	ldr r2, _0202C580 ; =0x0000270F
	cmp r5, r2
	bls _0202C576
	strh r2, [r4, r3]
_0202C576:
	bl sub_0202C4B0
_0202C57A:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0202C57C: .word 0x000001F2
_0202C580: .word 0x0000270F
	thumb_func_end sub_0202C554

	thumb_func_start sub_0202C584
sub_0202C584: ; 0x0202C584
	push {r3, r4, r5, lr}
	cmp r1, #0
	blt _0202C5AC
	cmp r1, #0x20
	bge _0202C5AC
	mov r3, #0x7d
	lsl r3, r3, #2
	add r4, r0, r3
	mov r3, #0x38
	mul r3, r1
	ldrh r5, [r4, r3]
	add r2, r5, r2
	strh r2, [r4, r3]
	ldrh r5, [r4, r3]
	ldr r2, _0202C5B0 ; =0x0000270F
	cmp r5, r2
	bls _0202C5A8
	strh r2, [r4, r3]
_0202C5A8:
	bl sub_0202C4B0
_0202C5AC:
	pop {r3, r4, r5, pc}
	nop
_0202C5B0: .word 0x0000270F
	thumb_func_end sub_0202C584

	thumb_func_start sub_0202C5B4
sub_0202C5B4: ; 0x0202C5B4
	push {r3, r4, r5, lr}
	cmp r1, #0
	blt _0202C5DA
	cmp r1, #0x20
	bge _0202C5DA
	ldr r3, _0202C5DC ; =0x000001F6
	add r4, r0, r3
	mov r3, #0x38
	mul r3, r1
	ldrh r5, [r4, r3]
	add r2, r5, r2
	strh r2, [r4, r3]
	ldrh r5, [r4, r3]
	ldr r2, _0202C5E0 ; =0x0000270F
	cmp r5, r2
	bls _0202C5D6
	strh r2, [r4, r3]
_0202C5D6:
	bl sub_0202C4B0
_0202C5DA:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0202C5DC: .word 0x000001F6
_0202C5E0: .word 0x0000270F
	thumb_func_end sub_0202C5B4

	thumb_func_start sub_0202C5E4
sub_0202C5E4: ; 0x0202C5E4
	push {r4, r5, r6, lr}
	add r5, r0, #0
	cmp r2, #0
	blt _0202C6DE
	cmp r2, #0x20
	bge _0202C6DE
	cmp r1, #0
	blt _0202C6DE
	cmp r1, #0x20
	bge _0202C6DE
	add r4, r1, #0
	mov r0, #0x38
	mov r3, #0x79
	mul r4, r0
	add r1, r2, #0
	lsl r3, r3, #2
	mul r1, r0
	add r2, r5, r3
	add r6, r5, r4
	ldrh r0, [r2, r1]
	ldrh r3, [r6, r3]
	add r0, r0, r3
	strh r0, [r2, r1]
	ldrh r3, [r2, r1]
	ldr r0, _0202C6E0 ; =0x0000270F
	cmp r3, r0
	bls _0202C61C
	strh r0, [r2, r1]
_0202C61C:
	ldr r3, _0202C6E4 ; =0x000001E6
	add r6, r5, r4
	add r2, r5, r3
	ldrh r0, [r2, r1]
	ldrh r3, [r6, r3]
	add r0, r0, r3
	strh r0, [r2, r1]
	ldrh r3, [r2, r1]
	ldr r0, _0202C6E0 ; =0x0000270F
	cmp r3, r0
	bls _0202C634
	strh r0, [r2, r1]
_0202C634:
	mov r3, #0x7a
	lsl r3, r3, #2
	add r2, r5, r3
	add r6, r5, r4
	ldrh r0, [r2, r1]
	ldrh r3, [r6, r3]
	add r0, r0, r3
	strh r0, [r2, r1]
	ldrh r3, [r2, r1]
	ldr r0, _0202C6E0 ; =0x0000270F
	cmp r3, r0
	bls _0202C64E
	strh r0, [r2, r1]
_0202C64E:
	mov r3, #0x1f
	lsl r3, r3, #4
	add r2, r5, r3
	add r6, r5, r4
	ldrh r0, [r2, r1]
	ldrh r3, [r6, r3]
	add r0, r0, r3
	strh r0, [r2, r1]
	ldrh r3, [r2, r1]
	ldr r0, _0202C6E0 ; =0x0000270F
	cmp r3, r0
	bls _0202C668
	strh r0, [r2, r1]
_0202C668:
	ldr r3, _0202C6E8 ; =0x000001F2
	add r6, r5, r4
	add r2, r5, r3
	ldrh r0, [r2, r1]
	ldrh r3, [r6, r3]
	add r0, r0, r3
	strh r0, [r2, r1]
	ldrh r3, [r2, r1]
	ldr r0, _0202C6E0 ; =0x0000270F
	cmp r3, r0
	bls _0202C680
	strh r0, [r2, r1]
_0202C680:
	mov r3, #0x7d
	lsl r3, r3, #2
	add r2, r5, r3
	add r6, r5, r4
	ldrh r0, [r2, r1]
	ldrh r3, [r6, r3]
	add r0, r0, r3
	strh r0, [r2, r1]
	ldrh r3, [r2, r1]
	ldr r0, _0202C6E0 ; =0x0000270F
	cmp r3, r0
	bls _0202C69A
	strh r0, [r2, r1]
_0202C69A:
	ldr r3, _0202C6EC ; =0x000001F6
	add r6, r5, r4
	add r2, r5, r3
	ldrh r0, [r2, r1]
	ldrh r3, [r6, r3]
	add r0, r0, r3
	strh r0, [r2, r1]
	ldrh r3, [r2, r1]
	ldr r0, _0202C6E0 ; =0x0000270F
	cmp r3, r0
	bls _0202C6B2
	strh r0, [r2, r1]
_0202C6B2:
	mov r0, #7
	lsl r0, r0, #6
	add r6, r5, r0
	add r0, r6, r4
	add r1, r6, r1
	mov r2, #0x10
	bl MIi_CpuCopyFast
	mov r0, #0
	add r1, r6, r4
	mov r2, #0x38
	bl MIi_CpuClearFast
	mov r0, #0x1d
	ldr r1, _0202C6F0 ; =0x0000FFFF
	add r2, r5, r4
	lsl r0, r0, #4
	strh r1, [r2, r0]
	strh r1, [r6, r4]
	mov r1, #2
	add r0, #0x1e
	strb r1, [r2, r0]
_0202C6DE:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0202C6E0: .word 0x0000270F
_0202C6E4: .word 0x000001E6
_0202C6E8: .word 0x000001F2
_0202C6EC: .word 0x000001F6
_0202C6F0: .word 0x0000FFFF
	thumb_func_end sub_0202C5E4

	thumb_func_start sub_0202C6F4
sub_0202C6F4: ; 0x0202C6F4
	ldr r0, _0202C6F8 ; =_021D2230
	bx lr
	.balign 4, 0
_0202C6F8: .word _021D2230
	thumb_func_end sub_0202C6F4

	thumb_func_start sub_0202C6FC
sub_0202C6FC: ; 0x0202C6FC
	push {r3, lr}
	mov r1, #0x19
	bl SaveArray_Get
	mov r2, #0x23
	ldr r1, _0202C710 ; =_021D2230
	lsl r2, r2, #6
	bl MI_CpuCopy8
	pop {r3, pc}
	.balign 4, 0
_0202C710: .word _021D2230
	thumb_func_end sub_0202C6FC

	thumb_func_start sub_0202C714
sub_0202C714: ; 0x0202C714
	push {r3, lr}
	mov r1, #0x19
	bl SaveArray_Get
	add r1, r0, #0
	mov r2, #0x23
	ldr r0, _0202C72C ; =_021D2230
	lsl r2, r2, #6
	bl MI_CpuCopy8
	pop {r3, pc}
	nop
_0202C72C: .word _021D2230
	thumb_func_end sub_0202C714

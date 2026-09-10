	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020596F0
sub_020596F0: ; 0x020596F0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, #0x89
	ldrb r1, [r0]
	mov r0, #1
	tst r1, r0
	bne _02059734
	ldr r4, [r5, #0x4c]
	bl sub_02059B08
	add r2, r0, #0
	add r0, r5, #0
	add r0, #0x86
	ldrh r0, [r0]
	cmp r0, #0
	bne _0205971A
	mov r0, #0x6a
	add r1, r4, #0
	bl sub_02037088
	b _02059722
_0205971A:
	mov r0, #0x6a
	add r1, r4, #0
	bl sub_02036FD8
_02059722:
	cmp r0, #0
	beq _02059734
	add r1, r5, #0
	add r1, #0x89
	ldrb r2, [r1]
	mov r1, #1
	add r5, #0x89
	orr r1, r2
	strb r1, [r5]
_02059734:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_020596F0

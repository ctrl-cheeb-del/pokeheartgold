	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020597A8
sub_020597A8: ; 0x020597A8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl sub_02070D90
	add r6, r0, #0
	ldr r0, [r5, #0x50]
	mov r1, #3
	bl Party_InitWithMaxSize
	mov r4, #0
_020597BC:
	add r1, r4, #0
	ldr r2, [r5, #0x48]
	mul r1, r6
	ldr r0, [r5, #0x50]
	add r1, r2, r1
	bl Party_AddMon
	add r4, r4, #1
	cmp r4, #3
	blt _020597BC
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_020597A8

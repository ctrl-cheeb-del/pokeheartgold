	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205975C
sub_0205975C: ; 0x0205975C
	push {r4, lr}
	add r4, r0, #0
	add r0, #0x86
	ldrh r0, [r0]
	cmp r0, #0
	bne _02059776
	add r1, r4, #0
	mov r0, #0x6b
	add r1, #0x84
	mov r2, #1
	bl sub_02037108
	b _02059782
_02059776:
	add r1, r4, #0
	mov r0, #0x6b
	add r1, #0x84
	mov r2, #1
	bl sub_02037030
_02059782:
	cmp r0, #0
	beq _02059794
	add r1, r4, #0
	add r1, #0x89
	ldrb r2, [r1]
	mov r1, #1
	add r4, #0x89
	orr r1, r2
	strb r1, [r4]
_02059794:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_0205975C

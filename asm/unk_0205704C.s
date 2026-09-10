	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205704C
sub_0205704C: ; 0x0205704C
	push {r3, r4, r5, lr}
	sub sp, #8
	ldrh r2, [r1]
	mov r4, #0xf
	lsl r4, r4, #0xc
	ldrh r3, [r1, #2]
	cmp r2, r4
	blo _0205705E
	sub r2, r4, #1
_0205705E:
	mov r4, #0xf
	lsl r4, r4, #0xc
	cmp r3, r4
	blo _02057068
	sub r3, r4, #1
_02057068:
	mov r4, #0xf
	and r0, r4
	add r4, sp, #0
	strb r0, [r4]
	strb r2, [r4, #1]
	asr r2, r2, #8
	add r5, r2, #0
	mov r0, #1
	and r5, r0
	asr r2, r3, #7
	mov r0, #2
	and r0, r2
	add r0, r5, r0
	strb r0, [r4, #2]
	strb r3, [r4, #3]
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _02057094
	ldrb r2, [r4, #2]
	mov r0, #0x80
	orr r0, r2
	strb r0, [r4, #2]
_02057094:
	mov r2, #4
	ldrsb r2, [r1, r2]
	add r5, sp, #0
	ldrb r0, [r5]
	lsr r4, r2, #0x1f
	lsl r3, r2, #0x1e
	sub r3, r3, r4
	mov r2, #0x1e
	ror r3, r2
	add r2, r4, r3
	lsl r2, r2, #4
	add r0, r0, r2
	strb r0, [r5]
	ldrb r0, [r1, #5]
	ldrb r2, [r5]
	add r1, sp, #0
	lsl r0, r0, #6
	add r0, r2, r0
	strb r0, [r5]
	mov r0, #0x17
	mov r2, #0
	bl sub_02037108
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0205704C

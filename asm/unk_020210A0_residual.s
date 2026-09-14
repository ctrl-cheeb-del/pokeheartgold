	.include "asm/macros.inc"
	.include "unk_020210A0.inc"
	.include "global.inc"

	.text
	thumb_func_start sub_020213F8
sub_020213F8: ; 0x020213F8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r5, _020214A8 ; =_021D2198
	str r1, [sp, #4]
	ldr r1, [r5, #8]
	str r0, [sp]
	add r7, r2, #0
	mov r4, #0
	cmp r1, #0
	bls _0202149E
_0202140C:
	ldr r0, [sp, #4]
	sub r0, r0, r1
	add r0, r4, r0
	add r0, r0, #1
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	bpl _02021420
	add r0, #9
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
_02021420:
	lsl r1, r0, #3
	ldr r0, _020214AC ; =_021D2198
	add r1, r0, r1
	ldrh r0, [r1, #0x10]
	cmp r0, #1
	bne _02021496
	ldrh r0, [r1, #0x12]
	cmp r0, #0
	bne _02021496
	ldr r2, [r5, #0x54]
	ldr r0, [r5]
	lsl r2, r2, #3
	add r2, r0, r2
	add r0, r2, #0
	sub r0, #8
	ldrh r3, [r1, #0xc]
	ldrh r0, [r0]
	cmp r0, r3
	blt _0202144A
	sub r3, r0, r3
	b _0202144C
_0202144A:
	sub r3, r3, r0
_0202144C:
	sub r6, r2, #6
	ldrh r0, [r1, #0xe]
	ldrh r6, [r6]
	cmp r6, r0
	blt _0202145A
	sub r0, r6, r0
	b _0202145C
_0202145A:
	sub r0, r0, r6
_0202145C:
	cmp r3, r7
	bhs _02021464
	cmp r0, r7
	blo _02021496
_02021464:
	ldrh r0, [r1, #0xc]
	strh r0, [r2]
	ldrh r0, [r1, #0xe]
	strh r0, [r2, #2]
	ldrh r0, [r1, #0x10]
	strh r0, [r2, #4]
	ldrh r0, [r1, #0x12]
	strh r0, [r2, #6]
	ldr r0, [r5, #0x54]
	add r0, r0, #1
	str r0, [r5, #0x54]
	ldr r1, [r5, #4]
	cmp r0, r1
	blo _02021496
	ldr r2, [sp]
	cmp r2, #1
	bne _0202148E
	bl _u32_div_f
	str r1, [r5, #0x54]
	b _02021496
_0202148E:
	mov r0, #0
	add sp, #8
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_02021496:
	ldr r1, [r5, #8]
	add r4, r4, #1
	cmp r4, r1
	blo _0202140C
_0202149E:
	ldr r0, _020214A8 ; =_021D2198
	ldr r0, [r0, #0x54]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_020214A8: .word _021D2198
_020214AC: .word _021D2198
	thumb_func_end sub_020213F8

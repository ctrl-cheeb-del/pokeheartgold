	.include "asm/macros.inc"
	.include "unk_020210A0.inc"
	.include "global.inc"

	.text
	thumb_func_start sub_02021540
sub_02021540: ; 0x02021540
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl sub_02021528
	ldr r0, _02021598 ; =_021D2198
	mov r6, #0
	ldr r1, [r0, #8]
	cmp r1, #0
	bls _02021596
	ldr r2, _0202159C ; =_021D2198
_02021556:
	sub r1, r4, r1
	add r1, r6, r1
	add r1, r1, #1
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	bpl _02021568
	add r1, #9
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
_02021568:
	lsl r1, r1, #3
	add r3, r2, r1
	ldrh r1, [r3, #0x12]
	cmp r1, #0
	bne _0202158E
	ldrh r1, [r5]
	ldrh r7, [r3, #0xc]
	lsl r1, r1, #3
	add r1, r5, r1
	strh r7, [r1, #2]
	ldrh r7, [r3, #0xe]
	strh r7, [r1, #4]
	ldrh r7, [r3, #0x10]
	strh r7, [r1, #6]
	ldrh r3, [r3, #0x12]
	strh r3, [r1, #8]
	ldrh r1, [r5]
	add r1, r1, #1
	strh r1, [r5]
_0202158E:
	ldr r1, [r0, #8]
	add r6, r6, #1
	cmp r6, r1
	blo _02021556
_02021596:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02021598: .word _021D2198
_0202159C: .word _021D2198
	thumb_func_end sub_02021540

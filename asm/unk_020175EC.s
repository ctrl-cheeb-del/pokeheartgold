	.include "asm/macros.inc"
	.include "unk_02016EDC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020175EC
sub_020175EC: ; 0x020175EC
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r1, sp, #0
	add r5, r0, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0]
	cmp r0, #0x14
	bne _02017620
	add r1, sp, #0
	add r0, r5, #0
	add r1, #3
	bl sub_02017294
	add r0, sp, #0
	ldrb r0, [r0, #3]
	add r1, sp, #8
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [sp, #0xc]
	add r0, r5, #0
	bl sub_0201726C
	b _0201764E
_02017620:
	cmp r0, #0x15
	bne _0201764A
	add r1, sp, #0
	add r2, sp, #0
	add r0, r5, #0
	add r1, #3
	add r2, #2
	bl sub_020172B4
	add r0, sp, #0
	ldrb r1, [r0, #3]
	lsl r1, r1, #2
	add r1, r5, r1
	ldr r1, [r1, #0x24]
	str r1, [sp, #0xc]
	ldrb r0, [r0, #2]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [sp, #8]
	b _0201764E
_0201764A:
	bl GF_AssertFail
_0201764E:
	add r1, sp, #0
	add r0, r5, #0
	add r1, #1
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0, #1]
	cmp r0, #0x11
	bls _02017664
	bl GF_AssertFail
_02017664:
	add r0, sp, #0xc
	add r1, sp, #8
	bl sub_02017470
	add r4, r0, #0
	add r0, r5, #0
	add r1, sp, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0]
	cmp r0, #0x14
	bne _02017692
	add r1, sp, #0
	add r0, r5, #0
	add r1, #3
	bl sub_02017294
	add r0, r5, #0
	add r1, sp, #4
	bl sub_0201726C
	b _020176B6
_02017692:
	cmp r0, #0x15
	bne _020176B2
	add r1, sp, #0
	add r2, sp, #0
	add r0, r5, #0
	add r1, #3
	add r2, #2
	bl sub_020172B4
	add r0, sp, #0
	ldrb r0, [r0, #2]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [sp, #4]
	b _020176B6
_020176B2:
	bl GF_AssertFail
_020176B6:
	add r0, sp, #0
	ldrb r1, [r0, #1]
	cmp r1, r4
	bne _020176C8
	ldrb r0, [r0, #3]
	ldr r1, [sp, #4]
	lsl r0, r0, #2
	add r0, r5, r0
	str r1, [r0, #0x24]
_020176C8:
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_020175EC

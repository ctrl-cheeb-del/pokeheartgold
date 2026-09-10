#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.include "unk_0202B614.inc"
	.include "global.inc"

	.text

	thumb_func_start sub_0202BCAC
sub_0202BCAC: ; 0x0202BCAC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r4, r1, #0
	add r5, r0, #0
	ldr r0, [r4, #4]
	add r6, r2, #0
	bl sub_02015FCC
	add r1, sp, #0xc
	strh r0, [r1]
	lsr r0, r0, #0x10
	strh r0, [r1, #2]
	ldrh r0, [r1]
	strh r0, [r1, #4]
	ldrh r0, [r1, #2]
	strh r0, [r1, #6]
	ldr r0, [r4, #4]
	bl sub_02015FF8
	add r7, r0, #0
	cmp r6, #0xa
	blt _0202BCDC
	bl GF_AssertFail
_0202BCDC:
	add r1, sp, #0xc
	mov r0, #4
	ldrsh r1, [r1, r0]
	add r0, #0xfc
	cmp r1, r0
	blt _0202BCEC
	bl GF_AssertFail
_0202BCEC:
	add r0, sp, #0xc
	mov r1, #6
	ldrsh r0, [r0, r1]
	add r1, #0xfa
	str r0, [sp, #8]
	ldr r0, [sp, #8]
	cmp r0, r1
	blt _0202BD00
	bl GF_AssertFail
_0202BD00:
	mov r0, #0x7f
	mvn r0, r0
	cmp r7, r0
	bgt _0202BD0C
	bl GF_AssertFail
_0202BD0C:
	mov r0, #1
	lsl r0, r6
	ldr r1, [r5, #0x3c]
	str r0, [sp, #4]
	tst r0, r1
	beq _0202BD1C
	bl GF_AssertFail
_0202BD1C:
	ldr r0, [r5]
	bl sub_0202B614
	cmp r0, #0
	bne _0202BD2A
	bl GF_AssertFail
_0202BD2A:
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	add r1, r5, #0
	add r3, sp, #0xc
	mov r2, #4
	ldrsh r2, [r3, r2]
	ldr r3, [sp, #8]
	add r1, #0x48
	lsl r0, r6, #2
	add r0, r1, r0
	ldr r1, [r4]
	lsl r2, r2, #0x18
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl sub_0202B770
	ldr r1, [r5, #0x3c]
	ldr r0, [sp, #4]
	orr r0, r1
	str r0, [r5, #0x3c]
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0202BCAC

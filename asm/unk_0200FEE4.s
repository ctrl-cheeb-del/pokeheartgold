	.include "asm/macros.inc"
	.include "unk_0200FA24.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0200FEE4
sub_0200FEE4: ; 0x0200FEE4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #1
	str r0, [sp, #4]
	add r0, r5, #0
	str r0, [sp, #8]
	add r0, #0x10
	lsl r4, r3, #2
	str r0, [sp, #8]
	ldr r0, [r0, r4]
	add r7, r2, #0
	str r1, [sp]
	cmp r0, #0
	beq _0200FF06
	bl GF_AssertFail
_0200FF06:
	add r6, r5, #0
	add r6, #8
	ldr r0, [r6, r4]
	cmp r0, #0
	bne _0200FF14
	bl GF_AssertFail
_0200FF14:
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _0200FF2E
	ldr r0, [r5, #0x14]
	cmp r0, #0
	bne _0200FF2E
	ldr r0, _0200FF54 ; =sub_0200FECC
	add r1, r5, #0
	bl Main_SetHBlankIntrCB
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
_0200FF2E:
	ldr r0, [sp, #4]
	cmp r0, #1
	beq _0200FF38
	bl GF_AssertFail
_0200FF38:
	ldr r0, [sp]
	cmp r7, #0
	str r0, [r5, r4]
	beq _0200FF44
	str r7, [r6, r4]
	b _0200FF48
_0200FF44:
	ldr r0, _0200FF58 ; =sub_02010014
	str r0, [r6, r4]
_0200FF48:
	ldr r0, [sp, #8]
	mov r1, #1
	str r1, [r0, r4]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_0200FF54: .word sub_0200FECC
_0200FF58: .word sub_02010014
	thumb_func_end sub_0200FEE4

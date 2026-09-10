	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02057550
sub_02057550: ; 0x02057550
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov r5, #0
	ldr r6, _020576B8 ; =_021D41C4
	str r5, [sp]
_0205755A:
	ldr r0, [r6]
	add r1, r0, r5
	add r1, #0x24
	ldrb r1, [r1]
	cmp r1, #0
	beq _02057570
	add r1, r0, r5
	add r1, #0xb4
	ldrb r1, [r1]
	cmp r1, #0
	bne _02057572
_02057570:
	b _020576A4
_02057572:
	add r2, r0, #0
	ldr r1, [sp]
	add r2, #0x34
	add r4, r2, r1
	add r1, r0, r5
	add r1, #0xd4
	ldrb r1, [r1]
	cmp r1, #0
	beq _02057592
	add r1, r0, r5
	add r1, #0xd4
	ldrb r1, [r1]
	add r0, r0, r5
	add r0, #0xd4
	sub r1, r1, #1
	strb r1, [r0]
_02057592:
	ldr r0, [r6]
	add r0, r0, r5
	add r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	beq _020575A2
	mov r7, #0
	b _020575AA
_020575A2:
	add r0, r5, #0
	bl sub_020374C0
	add r7, r0, #0
_020575AA:
	add r0, r5, #0
	bl sub_020374AC
	strb r0, [r4, #5]
	ldr r0, [r6]
	add r1, r0, r5
	add r1, #0xd4
	ldrb r1, [r1]
	cmp r1, #0
	bne _020576A4
	ldrb r1, [r4, #7]
	cmp r1, #1
	bne _020575CC
	add r1, r0, r5
	add r1, #0xcc
	mov r0, #1
	strb r0, [r1]
_020575CC:
	mov r0, #0
	strb r0, [r4, #7]
	ldr r1, [r6]
	add r0, r1, r5
	add r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #2
	bne _020575E6
	add r1, r1, r5
	add r1, #0xc4
	mov r0, #1
	strb r0, [r1]
	b _020576A4
_020575E6:
	add r0, r7, #0
	add r1, r7, #0
	bl sub_02057454
	add r7, r0, #0
	add r0, r5, #0
	bl sub_02057BEC
	str r0, [sp, #4]
	add r0, r5, #0
	bl sub_02057C24
	str r0, [sp, #8]
	ldr r1, [sp, #4]
	ldr r0, _020576BC ; =0x0000FFFF
	cmp r1, r0
	beq _020576A4
	ldr r1, [sp, #8]
	cmp r1, r0
	beq _020576A4
	mov r0, #0
	mvn r0, r0
	cmp r7, r0
	beq _020576A4
	mov r0, #4
	ldrsb r0, [r4, r0]
	cmp r0, r7
	beq _02057650
	strb r7, [r4, #4]
	ldr r0, [r6]
	add r1, r0, r5
	add r1, #0xd4
	mov r0, #4
	strb r0, [r1]
	ldr r0, [r6]
	add r1, r0, r5
	add r1, #0xcc
	mov r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	add r1, r0, r5
	add r1, #0xc4
	ldrb r1, [r1]
	cmp r1, #2
	bls _020576A4
	add r1, r0, r5
	add r1, #0xc4
	ldrb r1, [r1]
	add r0, r0, r5
	add r0, #0xc4
	sub r1, r1, #1
	strb r1, [r0]
	b _020576A4
_02057650:
	ldr r0, [r6]
	add r0, r0, r5
	add r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	bne _020576A4
	ldr r0, [sp, #4]
	add r2, r5, #0
	bl sub_020574C4
	cmp r0, #0
	beq _02057682
	mov r0, #1
	strb r0, [r4, #7]
	ldr r0, [r6]
	add r1, r0, r5
	add r1, #0xcc
	mov r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	add r1, r0, r5
	add r1, #0xd4
	mov r0, #4
	strb r0, [r1]
	b _020576A4
_02057682:
	ldr r0, [r6]
	add r1, r0, r5
	add r1, #0xcc
	mov r0, #1
	strb r0, [r1]
	ldr r0, [sp, #4]
	strh r0, [r4]
	ldr r0, [sp, #8]
	strh r0, [r4, #2]
	strb r7, [r4, #4]
	ldrb r0, [r4, #5]
	bl sub_02057524
	ldr r1, [r6]
	add r1, r1, r5
	add r1, #0xd4
	strb r0, [r1]
_020576A4:
	ldr r0, [sp]
	add r5, r5, #1
	add r0, #8
	str r0, [sp]
	cmp r5, #8
	bge _020576B2
	b _0205755A
_020576B2:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_020576B8: .word _021D41C4
_020576BC: .word 0x0000FFFF
	thumb_func_end sub_02057550
	thumb_func_start sub_020576C0
sub_020576C0: ; 0x020576C0
	push {r4, r5, r6, lr}
	ldr r3, _02057768 ; =_021D41C4
	add r1, r0, #0
	ldr r4, [r3]
	add r0, r2, #0
	cmp r4, #0
	beq _02057764
	add r5, r4, #0
	ldrb r6, [r0, #4]
	add r5, #0x34
	lsl r2, r1, #3
	add r2, r5, r2
	mov r5, #0x80
	tst r5, r6
	beq _020576E6
	mov r0, #1
	add r4, #0xec
	strb r0, [r4]
	pop {r4, r5, r6, pc}
_020576E6:
	mov r4, #4
	ldrsb r5, [r2, r4]
	sub r4, r4, #5
	cmp r5, r4
	bne _02057702
	mov r5, #0
	mov r4, #1
_020576F4:
	ldr r6, [r3]
	add r6, r6, r5
	add r6, #0xcc
	add r5, r5, #1
	strb r4, [r6]
	cmp r5, #8
	blt _020576F4
_02057702:
	mov r3, #0
	strh r3, [r2]
	strh r3, [r2, #2]
	ldrh r4, [r2]
	ldrb r3, [r0]
	add r3, r4, r3
	strh r3, [r2]
	ldrb r4, [r0, #1]
	ldrh r3, [r2]
	lsl r5, r4, #8
	mov r4, #0xff
	lsl r4, r4, #8
	and r5, r4
	add r3, r3, r5
	strh r3, [r2]
	ldrh r5, [r2, #2]
	ldrb r3, [r0, #2]
	add r3, r5, r3
	strh r3, [r2, #2]
	ldrb r5, [r0, #3]
	ldrh r3, [r2, #2]
	lsl r5, r5, #8
	and r4, r5
	add r3, r3, r4
	strh r3, [r2, #2]
	ldrb r3, [r0, #4]
	mov r0, #0xf
	ldr r4, _02057768 ; =_021D41C4
	and r0, r3
	strb r0, [r2, #4]
	ldr r3, [r4]
	mov r0, #1
	add r3, r3, r1
	add r3, #0x24
	strb r0, [r3]
	ldr r3, [r4]
	add r1, r3, r1
	add r1, #0xcc
	strb r0, [r1]
	ldr r0, [r4]
	ldrh r1, [r2]
	ldrh r2, [r2, #2]
	ldr r0, [r0, #0x30]
	bl sub_020548C0
	cmp r0, #0
	beq _02057764
	bl GF_AssertFail
_02057764:
	pop {r4, r5, r6, pc}
	nop
_02057768: .word _021D41C4
	thumb_func_end sub_020576C0

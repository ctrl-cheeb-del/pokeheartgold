	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02036144
sub_02036144: ; 0x02036144
	push {r4, lr}
	bl sub_0203817C
	ldr r3, _02036214 ; =_021D4140
	ldr r0, [r3, #8]
	cmp r0, #0
	beq _020361FE
	ldr r2, _02036218 ; =0x000006B9
	ldrb r1, [r0, r2]
	cmp r1, #0
	bne _020361E0
	add r1, r2, #3
	ldrb r1, [r0, r1]
	add r4, r1, #1
	add r1, r2, #3
	strb r4, [r0, r1]
	mov r0, #0
	strb r0, [r3, #1]
	bl sub_02035F4C
	ldr r0, _02036214 ; =_021D4140
	ldr r1, _0203621C ; =gSystem
	ldr r0, [r0, #8]
	ldr r2, _02036220 ; =0x0000065C
	ldr r3, [r1, #0x44]
	ldr r1, _02036224 ; =0x00007FFF
	ldrh r4, [r0, r2]
	and r1, r3
	orr r1, r4
	strh r1, [r0, r2]
	bl sub_02036BE4
	bl sub_02036298
	ldr r0, _02036214 ; =_021D4140
	ldr r1, _02036220 ; =0x0000065C
	ldr r3, [r0, #8]
	mov r0, #2
	ldrh r2, [r3, r1]
	lsl r0, r0, #0xe
	and r0, r2
	strh r0, [r3, r1]
	bl sub_02035FF0
	cmp r0, #0
	bne _020361A4
	bl sub_020372E4
_020361A4:
	bl sub_0203769C
	cmp r0, #0
	bne _020361C6
	mov r0, #0
	bl sub_020373B4
	cmp r0, #0
	beq _020361C6
	bl sub_0203993C
	bl sub_02034084
	cmp r0, #0
	bne _020361C6
	bl sub_0203667C
_020361C6:
	bl sub_0203769C
	cmp r0, #0
	beq _020361D6
	bl sub_02035FF0
	cmp r0, #1
	bne _020361DA
_020361D6:
	bl sub_02037334
_020361DA:
	ldr r0, _02036214 ; =_021D4140
	mov r1, #1
	strb r1, [r0, #1]
_020361E0:
	ldr r0, _02036214 ; =_021D4140
	ldr r1, [r0, #8]
	ldr r0, _02036228 ; =0x00000694
	ldrh r0, [r1, r0]
	bl sub_020355C8
	bl sub_0203769C
	cmp r0, #0
	bne _020361F8
	bl sub_02035E9C
_020361F8:
	bl sub_0203611C
	b _02036204
_020361FE:
	mov r0, #0
	bl sub_020355C8
_02036204:
	mov r0, #0
	bl sub_02039A00
	bl sub_02037ADC
	mov r0, #1
	pop {r4, pc}
	nop
_02036214: .word _021D4140
_02036218: .word 0x000006B9
_0203621C: .word gSystem
_02036220: .word 0x0000065C
_02036224: .word 0x00007FFF
_02036228: .word 0x00000694
	thumb_func_end sub_02036144

	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02038550
sub_02038550: ; 0x02038550
	push {r3, r4, r5, lr}
	bl sub_02035664
	cmp r0, #0
	beq _020385A8
	ldr r1, _020385AC ; =_021D4150
	mov r2, #2
	ldr r1, [r1]
	mov r0, #0
	add r1, #0x52
	ldrb r1, [r1]
	lsl r2, r2, #8
	mov r3, #1
	bl sub_02035ED8
	cmp r0, #0
	beq _020385A8
	ldr r0, _020385AC ; =_021D4150
	ldr r4, [r0]
	add r5, r4, #0
	add r5, #0xc
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r2, [r4, #0xc]
	ldr r3, [r5, #4]
	bl _ll_mul
	ldr r2, [r5, #0x10]
	ldr r3, [r5, #0x14]
	add r0, r2, r0
	adc r3, r1
	str r0, [r4, #0xc]
	str r3, [r5, #4]
	bl sub_02035FD8
	ldr r0, _020385AC ; =_021D4150
	mov r1, #0
	ldr r0, [r0]
	add r0, #0x52
	strb r1, [r0]
	ldr r0, _020385B0 ; =sub_020385B8
	ldr r1, _020385B4 ; =0x00002710
	bl sub_020381C0
_020385A8:
	pop {r3, r4, r5, pc}
	nop
_020385AC: .word _021D4150
_020385B0: .word sub_020385B8
_020385B4: .word 0x00002710
	thumb_func_end sub_02038550
	thumb_func_start sub_020385B8
sub_020385B8: ; 0x020385B8
	push {r3, lr}
	bl sub_020358B0
	cmp r0, #0
	bne _020385F2
	bl sub_020376F8
	cmp r0, #0
	beq _020385E2
	ldr r0, _02038604 ; =_021D4150
	mov r1, #1
	ldr r0, [r0]
	add r0, #0x52
	strb r1, [r0]
	bl sub_0203A880
	ldr r0, _02038608 ; =sub_02038854
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_020385E2:
	ldr r0, _02038604 ; =_021D4150
	ldr r1, [r0]
	ldr r0, [r1, #0x44]
	cmp r0, #0
	beq _020385F2
	sub r0, r0, #1
	str r0, [r1, #0x44]
	pop {r3, pc}
_020385F2:
	bl sub_02034FE8
	cmp r0, #0
	beq _02038602
	ldr r0, _0203860C ; =sub_02038610
	mov r1, #0
	bl sub_020381C0
_02038602:
	pop {r3, pc}
	.balign 4, 0
_02038604: .word _021D4150
_02038608: .word sub_02038854
_0203860C: .word sub_02038610
	thumb_func_end sub_020385B8
	thumb_func_start sub_02038610
sub_02038610: ; 0x02038610
	push {r3, r4, r5, lr}
	bl sub_02035664
	cmp r0, #0
	beq _0203865C
	mov r0, #0
	mov r2, #2
	add r1, r0, #0
	lsl r2, r2, #8
	bl sub_02035F14
	cmp r0, #0
	beq _0203865C
	bl sub_02035FD8
	ldr r0, _02038660 ; =_021D4150
	ldr r4, [r0]
	add r5, r4, #0
	add r5, #0xc
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r2, [r4, #0xc]
	ldr r3, [r5, #4]
	bl _ll_mul
	ldr r2, [r5, #0x10]
	ldr r3, [r5, #0x14]
	add r0, r2, r0
	adc r3, r1
	str r0, [r4, #0xc]
	mov r1, #0
	ldr r0, _02038664 ; =sub_02038508
	lsr r2, r3, #0x1b
	lsl r1, r1, #5
	orr r1, r2
	str r3, [r5, #4]
	bl sub_020381C0
_0203865C:
	pop {r3, r4, r5, pc}
	nop
_02038660: .word _021D4150
_02038664: .word sub_02038508
	thumb_func_end sub_02038610

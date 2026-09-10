	.include "asm/macros.inc"
	.include "unk_02033AE0.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02033CB0
sub_02033CB0: ; 0x02033CB0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldrb r0, [r5, #0xe]
	add r4, r1, #0
	bl sub_020341DC
	add r6, r0, #0
	ldr r0, _02033D24 ; =0x0000FFFF
	cmp r6, r0
	ldr r0, [r4, #4]
	bne _02033CD6
	cmp r0, #3
	bge _02033CE6
	ldrb r1, [r5, #0xf]
	mov r0, #1
	bic r1, r0
	strb r1, [r5, #0xf]
	mov r0, #1
	pop {r4, r5, r6, pc}
_02033CD6:
	cmp r0, #1
	bge _02033CE6
	ldrb r1, [r5, #0xf]
	mov r0, #1
	bic r1, r0
	strb r1, [r5, #0xf]
	mov r0, #1
	pop {r4, r5, r6, pc}
_02033CE6:
	ldrb r1, [r5, #0xe]
	add r0, r4, #0
	bl sub_02033C94
	ldr r0, _02033D24 ; =0x0000FFFF
	cmp r6, r0
	bne _02033D10
	ldrh r1, [r5, #0xc]
	add r0, r4, #0
	asr r1, r1, #8
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl sub_02033C94
	ldrh r1, [r5, #0xc]
	add r0, r4, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl sub_02033C94
	b _02033D12
_02033D10:
	strh r6, [r5, #0xc]
_02033D12:
	ldrb r1, [r5, #0xf]
	mov r0, #1
	bic r1, r0
	mov r0, #1
	orr r0, r1
	strb r0, [r5, #0xf]
	mov r0, #0
	pop {r4, r5, r6, pc}
	nop
_02033D24: .word 0x0000FFFF
	thumb_func_end sub_02033CB0
	thumb_func_start sub_02033D28
sub_02033D28: ; 0x02033D28
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldrb r0, [r5, #0xe]
	add r4, r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl sub_020341DC
	ldr r1, _02033DEC ; =0x0000FFFF
	cmp r0, r1
	bne _02033D42
	mov r2, #3
	b _02033D44
_02033D42:
	mov r2, #1
_02033D44:
	ldrh r0, [r5, #0xc]
	ldr r1, [r4, #4]
	add r0, r0, r2
	cmp r1, r0
	bge _02033D56
	cmp r7, #0
	bne _02033D56
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02033D56:
	ldrb r0, [r5, #0xf]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r0, #1
	beq _02033D70
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02033CB0
	cmp r0, #0
	beq _02033D70
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02033D70:
	ldrh r3, [r5, #0xc]
	ldr r2, [r4, #4]
	cmp r2, r3
	ldrb r0, [r5, #0xf]
	bge _02033DBA
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	beq _02033D8A
	ldr r1, [r4]
	add r0, r6, #0
	bl sub_02033B4C
	b _02033DA0
_02033D8A:
	mov r3, #0
	cmp r2, #0
	ble _02033DA0
_02033D90:
	ldr r0, [r5]
	ldrb r1, [r0, r3]
	ldr r0, [r4]
	strb r1, [r0, r3]
	ldr r0, [r4, #4]
	add r3, r3, #1
	cmp r3, r0
	blt _02033D90
_02033DA0:
	ldr r1, [r5]
	ldr r0, [r4, #4]
	add r0, r1, r0
	str r0, [r5]
	ldrh r1, [r5, #0xc]
	ldr r0, [r4, #4]
	sub r0, r1, r0
	strh r0, [r5, #0xc]
	mov r0, #0
	mvn r0, r0
	str r0, [r4, #4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02033DBA:
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	beq _02033DCC
	ldr r1, [r4]
	add r0, r6, #0
	add r2, r3, #0
	bl sub_02033B4C
	b _02033DD6
_02033DCC:
	ldr r0, [r5]
	ldr r1, [r4]
	add r2, r3, #0
	bl MI_CpuCopy8
_02033DD6:
	ldrh r0, [r5, #0xc]
	ldr r1, [r4]
	add r0, r1, r0
	str r0, [r4]
	ldrh r0, [r5, #0xc]
	ldr r1, [r4, #4]
	sub r0, r1, r0
	str r0, [r4, #4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02033DEC: .word 0x0000FFFF
	thumb_func_end sub_02033D28
	thumb_func_start sub_02033DF0
sub_02033DF0: ; 0x02033DF0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	add r7, r3, #0
	bl sub_02033C30
	add r4, r0, #0
	bne _02033E0A
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02033E0A:
	ldr r0, _02033E7C ; =0x0000FFFE
	cmp r7, r0
	blt _02033E14
	bl GF_AssertFail
_02033E14:
	ldr r0, [sp]
	bl sub_020341DC
	add r6, r0, #0
	ldr r0, _02033E80 ; =0x0000FFFF
	cmp r6, r0
	bne _02033E24
	add r6, r7, #0
_02033E24:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _02033E56
	ldr r0, [r5, #0x14]
	bl sub_02033BE4
	add r1, r6, #3
	cmp r1, r0
	blt _02033E3C
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02033E3C:
	ldr r0, [r5, #0x14]
	ldr r1, [sp, #4]
	ldr r3, _02033E84 ; =0x00000109
	add r2, r6, #0
	bl sub_02033AF0
	ldr r0, [r5, #0x14]
	bl sub_02033C28
	ldrb r1, [r4, #0xf]
	mov r0, #2
	orr r0, r1
	strb r0, [r4, #0xf]
_02033E56:
	ldr r0, [sp]
	strh r6, [r4, #0xc]
	strb r0, [r4, #0xe]
	ldr r0, [sp, #4]
	str r0, [r4]
	ldr r0, [r5, #4]
	cmp r0, #0
	bne _02033E6C
	str r4, [r5, #4]
	str r4, [r5]
	b _02033E74
_02033E6C:
	str r4, [r0, #8]
	ldr r0, [r5, #4]
	str r0, [r4, #4]
	str r4, [r5, #4]
_02033E74:
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02033E7C: .word 0x0000FFFE
_02033E80: .word 0x0000FFFF
_02033E84: .word 0x00000109
	thumb_func_end sub_02033DF0
	thumb_func_start sub_02033E88
sub_02033E88: ; 0x02033E88
	ldr r1, [r0, #0x10]
	cmp r1, #0
	beq _02033E92
	add r0, r1, #0
	bx lr
_02033E92:
	ldr r1, [r0]
	cmp r1, #0
	beq _02033E9C
	add r0, r1, #0
	bx lr
_02033E9C:
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _02033EA4
	mov r0, #0
_02033EA4:
	bx lr
	.balign 4, 0
	thumb_func_end sub_02033E88
	thumb_func_start sub_02033EA8
sub_02033EA8: ; 0x02033EA8
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x10]
	cmp r1, #0
	beq _02033EB8
	mov r0, #0
	str r0, [r4, #0x10]
	pop {r4, pc}
_02033EB8:
	bl sub_02033C70
	cmp r0, #0
	bne _02033EC8
	add r4, #8
	add r0, r4, #0
	bl sub_02033C70
_02033EC8:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02033EA8
	thumb_func_start sub_02033ECC
sub_02033ECC: ; 0x02033ECC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldr r0, [r4, #4]
	mov r7, #1
	str r2, [sp]
	cmp r0, #0
	ble _02033F22
_02033EDC:
	add r0, r5, #0
	bl sub_02033E88
	add r6, r0, #0
	beq _02033F22
	add r0, r5, #0
	bl sub_02033EA8
	ldr r2, [r5, #0x14]
	add r0, r6, #0
	add r1, r4, #0
	add r3, r7, #0
	bl sub_02033D28
	cmp r0, #0
	bne _02033F00
	str r6, [r5, #0x10]
	b _02033F22
_02033F00:
	mov r0, #0
	ldr r1, [r4, #4]
	mvn r0, r0
	cmp r1, r0
	bne _02033F10
	str r6, [r5, #0x10]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02033F10:
	add r0, r6, #0
	mov r1, #0
	mov r2, #0x10
	bl MI_CpuFill8
	ldr r0, [r4, #4]
	ldr r7, [sp]
	cmp r0, #0
	bgt _02033EDC
_02033F22:
	ldr r0, [r4, #4]
	mov r2, #0
	cmp r0, #0
	ble _02033F3E
	mov r1, #0xee
_02033F2C:
	ldr r0, [r4]
	add r2, r2, #1
	strb r1, [r0]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	ldr r0, [r4, #4]
	cmp r2, r0
	blt _02033F2C
_02033F3E:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02033ECC

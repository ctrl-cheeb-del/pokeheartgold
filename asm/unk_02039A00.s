	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02039A00
sub_02039A00: ; 0x02039A00
	push {r3, lr}
	bl sub_02039918
	cmp r0, #0
	beq _02039A98
	bl sub_02037700
	cmp r0, #0
	bne _02039A36
	bl sub_020393C8
	cmp r0, #0
	bne _02039A36
	bl sub_020395B0
	cmp r0, #0
	bne _02039A36
	ldr r0, _02039A9C ; =_021D4150
	ldr r0, [r0]
	add r0, #0x5d
	ldrb r0, [r0]
	cmp r0, #0
	bne _02039A36
	bl sub_020397FC
	cmp r0, #0
	beq _02039A98
_02039A36:
	bl sub_0201A79C
	cmp r0, #0
	bne _02039A98
	bl sub_020399B8
	cmp r0, #0
	bne _02039A98
	bl Sound_Stop
	ldr r0, _02039A9C ; =_021D4150
	ldr r0, [r0]
	ldr r0, [r0, #0x28]
	bl Save_Cancel
	ldr r1, _02039AA0 ; =gSystem + 0x60
	mov r0, #1
	strb r0, [r1, #8]
	ldr r1, _02039A9C ; =_021D4150
	ldr r2, [r1]
	add r1, r2, #0
	add r1, #0x5d
	ldrb r1, [r1]
	cmp r1, #3
	bne _02039A70
	mov r0, #3
	bl sub_020399A4
	pop {r3, pc}
_02039A70:
	cmp r1, #5
	bne _02039A7C
	mov r0, #5
	bl sub_020399A4
	pop {r3, pc}
_02039A7C:
	add r2, #0x4e
	ldrb r1, [r2]
	cmp r1, #0x19
	beq _02039A8C
	cmp r1, #0xf
	beq _02039A8C
	cmp r1, #0x24
	bne _02039A94
_02039A8C:
	mov r0, #2
	bl sub_020399A4
	pop {r3, pc}
_02039A94:
	bl sub_020399A4
_02039A98:
	pop {r3, pc}
	nop
_02039A9C: .word _021D4150
_02039AA0: .word gSystem + 0x60
	thumb_func_end sub_02039A00

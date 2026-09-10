	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"

	.bss

	.public _021D41C4
_021D41C4:
	.space 0x4

	.rodata

	.public _020FC7A0
_020FC7A0:
	.byte 0x04, 0x00, 0x07, 0x00, 0x0B, 0x00, 0x07, 0x00
	.public _020FC7A8
_020FC7A8:
	.byte 0x04, 0x00, 0x06, 0x00, 0x0B, 0x00, 0x06, 0x00
	.byte 0x04, 0x00, 0x08, 0x00, 0x0B, 0x00, 0x08, 0x00
	.data

	.public _0210FAB4
_0210FAB4:
	.byte 0x04, 0x00, 0x07, 0x00, 0x0B, 0x00, 0x07, 0x00
	.public _0210FABC
_0210FABC:
	.byte 0x04, 0x00, 0x06, 0x00, 0x0B, 0x00, 0x06, 0x00
	.public _0210FAC4
_0210FAC4:
	.byte 0x04, 0x00, 0x08, 0x00, 0x0B, 0x00, 0x08, 0x00

	.text

	thumb_func_start sub_02056D7C
sub_02056D7C: ; 0x02056D7C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	ldr r1, _02056E2C ; =_021D41C4
	ldr r2, [r1]
	cmp r2, #0
	beq _02056D8C
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02056D8C:
	bne _02056D98
	str r0, [r1]
	mov r1, #0
	mov r2, #0xf4
	bl MI_CpuFill8
_02056D98:
	ldr r0, _02056E2C ; =_021D41C4
	ldr r2, _02056E30 ; =0x0000FFFF
	ldr r1, [r0]
	mov r7, #2
	str r4, [r1, #0x30]
	mov r4, #0
	add r5, r4, #0
	sub r3, r4, #1
	add r1, r4, #0
_02056DAA:
	ldr r6, [r0]
	add r6, r6, r5
	add r6, #0x78
	strb r3, [r6]
	ldr r6, [r0]
	add r6, r6, r5
	add r6, #0x74
	strh r2, [r6]
	ldr r6, [r0]
	add r6, r6, r5
	add r6, #0x76
	strh r2, [r6]
	ldr r6, [r0]
	add r6, r6, r5
	add r6, #0x79
	strb r7, [r6]
	ldr r6, [r0]
	add r6, r6, r5
	add r6, #0x38
	strb r3, [r6]
	ldr r6, [r0]
	add r6, r6, r5
	strh r2, [r6, #0x34]
	ldr r6, [r0]
	add r6, r6, r5
	strh r2, [r6, #0x36]
	ldr r6, [r0]
	add r6, r6, r5
	add r6, #0x39
	strb r7, [r6]
	ldr r6, [r0]
	add r5, #8
	add r6, r6, r4
	add r6, #0xb4
	strb r1, [r6]
	ldr r6, [r0]
	add r6, r6, r4
	add r6, #0xbc
	add r4, r4, #1
	strb r1, [r6]
	cmp r4, #8
	blt _02056DAA
	ldr r2, _02056E2C ; =_021D41C4
	ldr r0, [r2]
	add r0, #0xed
	strb r1, [r0]
	ldr r0, [r2]
	add r0, #0xef
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, _02056E34 ; =sub_020572DC
	ldr r1, [r1, #0x30]
	mov r2, #0xc8
	bl SysTask_CreateOnMainQueue
	ldr r1, _02056E2C ; =_021D41C4
	ldr r1, [r1]
	str r0, [r1, #0x2c]
	bl sub_020374E4
	bl sub_02056EF4
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02056E2C: .word _021D41C4
_02056E30: .word 0x0000FFFF
_02056E34: .word sub_020572DC
	thumb_func_end sub_02056D7C

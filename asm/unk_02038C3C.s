	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02038C3C
sub_02038C3C: ; 0x02038C3C
	ldr r2, _02038CB4 ; =0x00400131
	cmp r0, r2
	bhi _02038C4C
	bhs _02038C8A
	ldr r2, _02038CB8 ; =0x00000333
	cmp r0, r2
	beq _02038C5E
	bx lr
_02038C4C:
	ldr r1, _02038CBC ; =0x00400286
	cmp r0, r1
	bhi _02038C56
	beq _02038C9E
	bx lr
_02038C56:
	add r1, #0x92
	cmp r0, r1
	beq _02038C76
	bx lr
_02038C5E:
	cmp r1, #0xf
	bne _02038CB0
	ldr r0, _02038CC0 ; =_021D4150
	ldr r2, [r0]
	add r0, r2, #0
	add r0, #0x58
	ldrb r1, [r0]
	mov r0, #1
	add r2, #0x58
	orr r0, r1
	strb r0, [r2]
	bx lr
_02038C76:
	ldr r0, _02038CC0 ; =_021D4150
	ldr r2, [r0]
	add r0, r2, #0
	add r0, #0x58
	ldrb r1, [r0]
	mov r0, #1
	add r2, #0x58
	orr r0, r1
	strb r0, [r2]
	bx lr
_02038C8A:
	ldr r0, _02038CC0 ; =_021D4150
	ldr r2, [r0]
	add r0, r2, #0
	add r0, #0x58
	ldrb r1, [r0]
	mov r0, #2
	add r2, #0x58
	orr r0, r1
	strb r0, [r2]
	bx lr
_02038C9E:
	ldr r0, _02038CC0 ; =_021D4150
	ldr r2, [r0]
	add r0, r2, #0
	add r0, #0x58
	ldrb r1, [r0]
	mov r0, #4
	add r2, #0x58
	orr r0, r1
	strb r0, [r2]
_02038CB0:
	bx lr
	nop
_02038CB4: .word 0x00400131
_02038CB8: .word 0x00000333
_02038CBC: .word 0x00400286
_02038CC0: .word _021D4150
	thumb_func_end sub_02038C3C
	thumb_func_start sub_02038CC4
sub_02038CC4: ; 0x02038CC4
	push {r3, lr}
	mov r0, #1
	add r1, r0, #0
	mov r2, #0x20
	bl sub_02035F14
	cmp r0, #0
	beq _02038CE0
	bl sub_02035FD8
	ldr r0, _02038CE4 ; =sub_02038C34
	mov r1, #0
	bl sub_020381C0
_02038CE0:
	pop {r3, pc}
	nop
_02038CE4: .word sub_02038C34
	thumb_func_end sub_02038CC4

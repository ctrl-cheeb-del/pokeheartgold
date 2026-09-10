	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020393C8
sub_020393C8: ; 0x020393C8
	ldr r0, _02039408 ; =_021D4150
	ldr r2, [r0]
	cmp r2, #0
	beq _02039402
	ldr r1, [r2, #0x24]
	ldr r0, _0203940C ; =sub_02038E90
	cmp r1, r0
	bne _020393DC
	mov r0, #1
	bx lr
_020393DC:
	ldr r0, _02039410 ; =sub_02038E94
	cmp r1, r0
	bne _020393F0
	add r0, r2, #0
	add r0, #0x53
	ldrb r0, [r0]
	cmp r0, #0
	beq _020393F0
	mov r0, #1
	bx lr
_020393F0:
	ldr r0, _02039414 ; =sub_02039E7C
	cmp r1, r0
	bne _02039402
	add r2, #0x53
	ldrb r0, [r2]
	cmp r0, #0
	beq _02039402
	mov r0, #1
	bx lr
_02039402:
	mov r0, #0
	bx lr
	nop
_02039408: .word _021D4150
_0203940C: .word sub_02038E90
_02039410: .word sub_02038E94
_02039414: .word sub_02039E7C
	thumb_func_end sub_020393C8
	thumb_func_start sub_02039418
sub_02039418: ; 0x02039418
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _02039468 ; =_021D4150
	ldr r0, [r0]
	cmp r0, #0
	bne _02039466
	mov r1, #0xf
	add r2, r1, #0
	mov r0, #3
	add r2, #0xf1
	bl Heap_CreateAtEnd
	mov r0, #0xf
	mov r1, #0x68
	bl Heap_Alloc
	ldr r1, _02039468 ; =_021D4150
	mov r2, #0x68
	str r0, [r1]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _02039468 ; =_021D4150
	mov r2, #0x18
	ldr r1, [r0]
	add r1, #0x4e
	strb r2, [r1]
	ldr r2, [r0]
	mov r1, #1
	add r2, #0x55
	strb r1, [r2]
	ldr r0, [r0]
	str r4, [r0, #0x28]
	mov r0, #0
	bl sub_020398D4
	mov r0, #1
	bl sub_0201A728
_02039466:
	pop {r4, pc}
	.balign 4, 0
_02039468: .word _021D4150
	thumb_func_end sub_02039418

	.include "asm/macros.inc"
	.include "unk_02058034.inc"
	.include "global.inc"

	.bss

	.public _021D41C8
_021D41C8:
	.space 0x4

	.text

	thumb_func_start sub_02058190
sub_02058190: ; 0x02058190
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl sub_0200FC60
	mov r0, #1
	mov r1, #0
	bl sub_0200FC60
	mov r0, #1
	add r1, r0, #0
	bl sub_020398D4
	bl sub_02037D78
	cmp r0, #0
	beq _02058248
	ldr r0, _0205824C ; =_021D41C8
	ldr r1, [r0]
	cmp r1, #0
	bne _020581D0
	add r0, r4, #0
	bl sub_02058038
	ldr r0, _0205824C ; =_021D41C8
	mov r1, #1
	ldr r0, [r0]
	add r0, #0x3e
	strb r1, [r0]
	b _020581D6
_020581D0:
	mov r0, #0
	add r1, #0x3e
	strb r0, [r1]
_020581D6:
	ldr r0, _0205824C ; =_021D41C8
	mov r1, #0
	ldr r0, [r0]
	add r0, #0x3f
	strb r1, [r0]
	bl sub_0203769C
	str r0, [sp, #8]
	bl sub_0203769C
	bl sub_02034818
	mov r4, #0
	bl sub_02037454
	cmp r0, #0
	ble _0205821E
	ldr r6, _0205824C ; =_021D41C8
	add r5, r4, #0
	add r7, r4, #0
_020581FE:
	ldr r0, [r6]
	ldr r0, [r0, r5]
	cmp r0, #0
	bne _02058212
	ldr r1, _02058250 ; =0x0000066C
	add r0, r7, #0
	bl Heap_Alloc
	ldr r1, [r6]
	str r0, [r1, r5]
_02058212:
	add r5, r5, #4
	add r4, r4, #1
	bl sub_02037454
	cmp r4, r0
	blt _020581FE
_0205821E:
	ldr r0, _0205824C ; =_021D41C8
	mov r3, #0xff
	ldr r1, [r0]
	ldr r0, [r1, #0x14]
	str r0, [sp]
	ldr r0, [sp, #8]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	str r0, [sp, #4]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	bl sub_02068FC8
	mov r0, #0x5f
	bl sub_02037AC0
	ldr r0, _02058254 ; =sub_020588F8
	mov r1, #0
	bl sub_020582F4
_02058248:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0205824C: .word _021D41C8
_02058250: .word 0x0000066C
_02058254: .word sub_020588F8
	thumb_func_end sub_02058190

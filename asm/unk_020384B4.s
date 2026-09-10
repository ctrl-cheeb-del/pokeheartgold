	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020384B4
sub_020384B4: ; 0x020384B4
	push {r3, lr}
	bl sub_02034DB8
	cmp r0, #0
	beq _020384FC
	ldr r0, _02038500 ; =_021D4150
	mov r1, #1
	ldr r0, [r0]
	ldr r0, [r0, #0x2c]
	bl sub_02034B0C
	ldr r0, _02038500 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x4a
	ldrb r0, [r0]
	bl sub_02033908
	ldr r0, _02038500 ; =_021D4150
	mov r1, #0
	ldr r0, [r0]
	ldr r0, [r0, #0x28]
	bl sub_02034354
	mov r0, #1
	add r1, r0, #0
	lsl r2, r0, #9
	bl sub_02035F14
	cmp r0, #0
	beq _020384FC
	bl sub_02035FD8
	ldr r0, _02038504 ; =sub_02038508
	mov r1, #0x40
	bl sub_020381C0
_020384FC:
	pop {r3, pc}
	nop
_02038500: .word _021D4150
_02038504: .word sub_02038508
	thumb_func_end sub_020384B4

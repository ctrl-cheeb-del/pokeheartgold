	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020394A0
sub_020394A0: ; 0x020394A0
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _020394F0 ; =_021D4150
	ldr r0, [r0]
	cmp r0, #0
	bne _020394EE
	mov r1, #0xf
	add r2, r1, #0
	mov r0, #3
	add r2, #0xf1
	bl Heap_CreateAtEnd
	mov r0, #0xf
	mov r1, #0x68
	bl Heap_Alloc
	ldr r1, _020394F0 ; =_021D4150
	mov r2, #0x68
	str r0, [r1]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _020394F0 ; =_021D4150
	mov r2, #0x19
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
_020394EE:
	pop {r4, pc}
	.balign 4, 0
_020394F0: .word _021D4150
	thumb_func_end sub_020394A0

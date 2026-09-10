	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"

	.bss

	.public _021D4150
_021D4150:
	.space 0x4

	.rodata

	.public _020F6A90
_020F6A90:
	.word sub_0203827C
	.word sub_02038398
	.word 0

	.data

	.balign 4, 0
	.public _0210F904
_0210F904:
	.asciz " GAME"
	.balign 4, 0
	.public _0210F90C
_0210F90C:
	.asciz "FREAK"
	.balign 4, 0
	.public _0210F914
_0210F914:
	.asciz " FULL"

	.text

	thumb_func_start sub_02037C98
sub_02037C98: ; 0x02037C98
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _02037D28 ; =_021D4150
	add r4, r1, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _02037D24
	cmp r5, #0
	bne _02037CAE
	bl GF_AssertFail
_02037CAE:
	bl sub_02034D8C
	mov r0, #0xf
	mov r1, #0x68
	bl Heap_Alloc
	ldr r1, _02037D28 ; =_021D4150
	mov r2, #0x68
	str r0, [r1]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _02037D28 ; =_021D4150
	mov r2, #0x32
	ldr r1, [r0]
	str r2, [r1, #0x44]
	ldr r1, [r0]
	mov r2, #1
	add r1, #0x52
	strb r2, [r1]
	ldr r0, [r0]
	str r5, [r0, #0x28]
	add r0, r5, #0
	bl Save_PlayerData_GetProfile
	ldr r1, _02037D28 ; =_021D4150
	ldr r2, [r1]
	str r0, [r2, #0x2c]
	ldr r0, [r1]
	mov r2, #2
	add r0, #0x4a
	strb r2, [r0]
	ldr r0, [r1]
	mov r2, #0
	add r0, #0x4c
	strb r2, [r0]
	ldr r0, [r1]
	add r0, #0x57
	strb r2, [r0]
	ldr r0, [r1]
	add r0, #0x4e
	strb r4, [r0]
	ldr r0, [r1]
	add r0, #0xc
	bl sub_0203778C
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	bl sub_0203410C
	cmp r4, #9
	beq _02037D24
	cmp r4, #0x11
	beq _02037D24
	cmp r4, #0xf
	beq _02037D24
	bl sub_0203A880
_02037D24:
	pop {r3, r4, r5, pc}
	nop
_02037D28: .word _021D4150
	thumb_func_end sub_02037C98

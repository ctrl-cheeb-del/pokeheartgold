	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"

	.data

	.public _0210F900
_0210F900:
	.byte 0x04, 0x04

	.bss

	.public _021D4140
_021D4140:
	.space 0xC

	.text

	thumb_func_start sub_02035900
sub_02035900: ; 0x02035900
	push {r4, r5, r6, lr}
	add r5, r1, #0
	mov r4, #0
	ldr r1, _02035AB8 ; =_021D4140
	cmp r0, #0
	strb r4, [r1, #1]
	bne _02035910
	b _02035A58
_02035910:
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r6, r0, #1
	ldr r0, _02035AB8 ; =_021D4140
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0203592A
	mov r0, #1
	pop {r4, r5, r6, pc}
_0203592A:
	mov r0, #0xf
	bl sub_020379A0
	mov r1, #0x6e
	mov r0, #0xf
	lsl r1, r1, #4
	bl Heap_Alloc
	ldr r2, _02035AB8 ; =_021D4140
	mov r1, #0x1f
	add r3, r0, #0
	and r3, r1
	mov r1, #0x20
	sub r1, r1, r3
	str r0, [r2, #4]
	add r0, r1, r0
	str r0, [r2, #8]
	mov r2, #0x1b
	add r1, r4, #0
	lsl r2, r2, #6
	bl MI_CpuFill8
	bl sub_0203993C
	bl sub_02034044
	cmp r0, #0
	beq _02035972
	ldr r0, _02035AB8 ; =_021D4140
	lsl r2, r5, #1
	ldr r1, [r0, #8]
	mov r0, #0x69
	add r2, #0x40
	lsl r0, r0, #4
	str r2, [r1, r0]
	b _0203597E
_02035972:
	ldr r0, _02035AB8 ; =_021D4140
	add r5, #0x40
	ldr r1, [r0, #8]
	mov r0, #0x69
	lsl r0, r0, #4
	str r5, [r1, r0]
_0203597E:
	ldr r2, _02035AB8 ; =_021D4140
	mov r1, #0x69
	ldr r0, [r2, #8]
	lsl r1, r1, #4
	ldr r3, [r0, r1]
	add r5, r3, #0
	mul r5, r6
	sub r3, r1, #4
	str r5, [r0, r3]
	add r0, r1, #0
	ldr r3, [r2, #8]
	mov r5, #0
	add r0, #0x1d
	strb r5, [r3, r0]
	add r0, r1, #0
	ldr r3, [r2, #8]
	mov r5, #0x2a
	add r0, #0x1e
	strb r5, [r3, r0]
	ldr r2, [r2, #8]
	mov r0, #0xf
	ldr r1, [r2, r1]
	lsl r1, r1, #1
	bl Heap_Alloc
	ldr r2, _02035AB8 ; =_021D4140
	mov r1, #0x49
	ldr r3, [r2, #8]
	lsl r1, r1, #4
	str r0, [r3, r1]
	mov r1, #0x69
	ldr r2, [r2, #8]
	lsl r1, r1, #4
	ldr r1, [r2, r1]
	mov r0, #0xf
	bl Heap_Alloc
	ldr r2, _02035AB8 ; =_021D4140
	ldr r1, _02035ABC ; =0x00000494
	ldr r3, [r2, #8]
	str r0, [r3, r1]
	ldr r2, [r2, #8]
	ldr r1, _02035AC0 ; =0x0000068C
	mov r0, #0xf
	ldr r1, [r2, r1]
	bl Heap_Alloc
	ldr r2, _02035AB8 ; =_021D4140
	ldr r1, _02035AC4 ; =0x0000048C
	ldr r3, [r2, #8]
	str r0, [r3, r1]
	ldr r2, [r2, #8]
	ldr r1, _02035AC0 ; =0x0000068C
	mov r0, #0xf
	ldr r1, [r2, r1]
	bl Heap_Alloc
	ldr r1, _02035AB8 ; =_021D4140
	ldr r2, [r1, #8]
	ldr r1, _02035AC8 ; =0x00000488
	str r0, [r2, r1]
	bl sub_0203993C
	cmp r0, #0xa
	bne _02035A2C
	ldr r0, _02035AB8 ; =_021D4140
	mov r2, #0x16
	ldr r3, [r0, #8]
	lsl r2, r2, #6
	add r0, r3, r2
	sub r2, #0xe8
	mov r1, #0x64
	add r2, r3, r2
	bl sub_02033F44
	ldr r0, _02035AB8 ; =_021D4140
	mov r2, #0x5a
	mov r1, #0x32
	ldr r3, [r0, #8]
	lsl r2, r2, #4
	add r0, r3, r2
	sub r2, #0x90
	lsl r1, r1, #4
	add r2, r3, r2
	bl sub_02033F44
	b _02035A64
_02035A2C:
	ldr r0, _02035AB8 ; =_021D4140
	mov r2, #0x16
	ldr r3, [r0, #8]
	lsl r2, r2, #6
	add r0, r3, r2
	sub r2, #0xe8
	mov r1, #0x14
	add r2, r3, r2
	bl sub_02033F44
	ldr r0, _02035AB8 ; =_021D4140
	mov r2, #0x5a
	add r1, r5, #0
	ldr r3, [r0, #8]
	lsl r2, r2, #4
	add r0, r3, r2
	sub r2, #0x90
	add r1, #0xee
	add r2, r3, r2
	bl sub_02033F44
	b _02035A64
_02035A58:
	ldr r0, [r1, #8]
	mov r4, #1
	cmp r0, #0
	bne _02035A64
	bl GF_AssertFail
_02035A64:
	ldr r2, _02035AB8 ; =_021D4140
	ldr r1, _02035ACC ; =0x00000694
	ldr r3, [r2, #8]
	mov r0, #0
	strh r0, [r3, r1]
	mov r5, #0xff
	add r1, #0x12
_02035A72:
	ldr r3, [r2, #8]
	add r3, r3, r0
	add r0, r0, #1
	strb r5, [r3, r1]
	cmp r0, #4
	blt _02035A72
	cmp r4, #0
	bne _02035A86
	bl sub_02035DA4
_02035A86:
	ldr r0, _02035AB8 ; =_021D4140
	ldr r1, [r0, #8]
	ldr r0, _02035AD0 ; =0x0000062C
	add r0, r1, r0
	bl sub_0203778C
	cmp r4, #0
	bne _02035AA8
	mov r1, #0
	ldr r0, _02035AD4 ; =sub_020360EC
	add r2, r1, #0
	bl SysTask_CreateOnVBlankQueue
	ldr r1, _02035AB8 ; =_021D4140
	ldr r2, [r1, #8]
	ldr r1, _02035AD8 ; =0x0000057C
	str r0, [r2, r1]
_02035AA8:
	ldr r0, _02035AB8 ; =_021D4140
	mov r2, #0
	ldr r1, [r0, #8]
	ldr r0, _02035ADC ; =0x000006B6
	strb r2, [r1, r0]
	mov r0, #1
	pop {r4, r5, r6, pc}
	nop
_02035AB8: .word _021D4140
_02035ABC: .word 0x00000494
_02035AC0: .word 0x0000068C
_02035AC4: .word 0x0000048C
_02035AC8: .word 0x00000488
_02035ACC: .word 0x00000694
_02035AD0: .word 0x0000062C
_02035AD4: .word sub_020360EC
_02035AD8: .word 0x0000057C
_02035ADC: .word 0x000006B6
	thumb_func_end sub_02035900
	thumb_func_start sub_02035AE0
sub_02035AE0: ; 0x02035AE0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	mov r2, #0x66
	ldr r3, _02035D5C ; =_021D4140
	add r7, r0, #1
	ldr r0, [r3, #8]
	mov r1, #0
	lsl r2, r2, #4
	strb r1, [r0, r2]
	add r0, r2, #1
	ldr r4, [r3, #8]
	add r2, #0x2c
	strb r1, [r4, r0]
	ldr r3, [r3, #8]
	ldr r0, _02035D60 ; =0x0000048C
	ldr r2, [r3, r2]
	ldr r0, [r3, r0]
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	mov r2, #0x60
	ldr r1, [r0, #8]
	ldr r0, _02035D64 ; =0x0000051C
	add r0, r1, r0
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	ldr r1, [r0, #8]
	ldr r0, _02035D68 ; =0x0000068C
	ldr r0, [r1, r0]
	add r1, r7, #0
	bl _s32_div_f
	add r4, r0, #0
	mov r0, #0
	str r0, [sp, #4]
	cmp r7, #0
	ble _02035B62
	add r6, r0, #0
	add r5, r0, #0
_02035B3E:
	ldr r0, _02035D5C ; =_021D4140
	ldr r2, _02035D60 ; =0x0000048C
	ldr r1, [r0, #8]
	ldr r0, _02035D64 ; =0x0000051C
	add r0, r1, r0
	ldr r1, [r1, r2]
	add r0, r0, r5
	add r1, r1, r6
	add r2, r4, #0
	bl sub_02033AE0
	ldr r0, [sp, #4]
	add r6, r6, r4
	add r0, r0, #1
	add r5, #0xc
	str r0, [sp, #4]
	cmp r0, r7
	blt _02035B3E
_02035B62:
	ldr r0, _02035D5C ; =_021D4140
	ldr r2, _02035D68 ; =0x0000068C
	ldr r3, [r0, #8]
	ldr r0, _02035D6C ; =0x00000488
	ldr r2, [r3, r2]
	ldr r0, [r3, r0]
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	mov r2, #0x60
	ldr r1, [r0, #8]
	mov r0, #0x4b
	lsl r0, r0, #4
	add r0, r1, r0
	mov r1, #0
	bl MI_CpuFill8
	mov r0, #0
	str r0, [sp]
	cmp r7, #0
	ble _02035BB8
	add r6, r0, #0
	add r5, r0, #0
_02035B92:
	ldr r0, _02035D5C ; =_021D4140
	ldr r2, _02035D6C ; =0x00000488
	ldr r1, [r0, #8]
	mov r0, #0x4b
	lsl r0, r0, #4
	add r0, r1, r0
	ldr r1, [r1, r2]
	add r0, r0, r5
	add r1, r1, r6
	add r2, r4, #0
	bl sub_02033AE0
	ldr r0, [sp]
	add r6, r6, r4
	add r0, r0, #1
	add r5, #0xc
	str r0, [sp]
	cmp r0, r7
	blt _02035B92
_02035BB8:
	ldr r0, _02035D5C ; =_021D4140
	mov r2, #6
	ldr r1, [r0, #8]
	mov r0, #0xc2
	lsl r0, r0, #2
	add r0, r1, r0
	mov r1, #0
	lsl r2, r2, #6
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	mov r1, #0xc2
	ldr r2, [r0, #8]
	mov r0, #0x51
	lsl r0, r0, #4
	lsl r1, r1, #2
	add r0, r2, r0
	add r1, r2, r1
	mov r2, #6
	lsl r2, r2, #6
	bl sub_02033AE0
	ldr r0, _02035D5C ; =_021D4140
	mov r1, #0xee
	ldr r0, [r0, #8]
	add r2, r1, #0
	add r0, #0x80
	add r2, #0x92
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	ldr r1, [r0, #8]
	mov r0, #5
	lsl r0, r0, #6
	add r0, r1, r0
	mov r1, #0xee
	add r2, r1, #0
	add r2, #0x92
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	mov r2, #2
	ldr r0, [r0, #8]
	lsl r2, r2, #8
	add r0, r0, r2
	mov r1, #0
	sub r2, #0xf8
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	mov r2, #2
	ldr r1, [r0, #8]
	ldr r0, _02035D70 ; =0x00000498
	lsl r2, r2, #8
	add r0, r1, r0
	add r1, r1, r2
	sub r2, #0xf8
	bl sub_02033AE0
	ldr r0, _02035D5C ; =_021D4140
	mov r1, #0xee
	ldr r0, [r0, #8]
	mov r2, #0x26
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	mov r1, #0xee
	ldr r0, [r0, #8]
	mov r2, #0x26
	add r0, #0x40
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	mov r2, #0xff
	ldr r1, [r0, #8]
	strb r2, [r1]
	ldr r1, [r0, #8]
	add r1, #0x40
	strb r2, [r1]
	ldr r3, [r0, #8]
	mov r2, #0x69
	mov r0, #0x49
	lsl r2, r2, #4
	lsl r0, r0, #4
	ldr r2, [r3, r2]
	ldr r0, [r3, r0]
	mov r1, #0
	lsl r2, r2, #1
	bl MI_CpuFill8
	ldr r0, _02035D5C ; =_021D4140
	mov r2, #0x69
	ldr r3, [r0, #8]
	ldr r1, _02035D74 ; =0x000004A4
	lsl r2, r2, #4
	add r0, r3, r1
	sub r1, #0x14
	ldr r2, [r3, r2]
	ldr r1, [r3, r1]
	lsl r2, r2, #1
	bl sub_02033AE0
	ldr r0, _02035D5C ; =_021D4140
	mov r2, #0
	ldr r3, [r0, #8]
	ldr r1, _02035D78 ; =0x000006B4
	mov ip, r2
	strb r2, [r3, r1]
	ldr r3, [r0, #8]
	add r1, r1, #1
	strb r2, [r3, r1]
	add r1, r2, #0
	add r7, r2, #0
	add r6, r2, #0
_02035C9C:
	ldr r3, [r0, #8]
	add r4, r3, r2
	ldr r3, _02035D7C ; =0x00000696
	strb r6, [r4, r3]
	ldr r3, [r0, #8]
	ldr r4, _02035D80 ; =0x0000069E
	add r5, r3, r2
	mov r3, #1
	strb r3, [r5, r4]
	ldr r4, [r0, #8]
	mov r3, ip
	add r4, r4, r3
	ldr r3, _02035D84 ; =0x00000644
	add r2, r2, #1
	strh r6, [r4, r3]
	ldr r3, [r0, #8]
	mov r4, #0xee
	add r5, r3, r1
	ldr r3, _02035D88 ; =0x000005CA
	strb r4, [r5, r3]
	ldr r3, [r0, #8]
	ldr r4, _02035D8C ; =0x0000FFFF
	add r5, r3, r1
	ldr r3, _02035D90 ; =0x000005C8
	strh r4, [r5, r3]
	ldr r3, [r0, #8]
	add r4, r3, r1
	ldr r3, _02035D94 ; =0x000005C4
	str r6, [r4, r3]
	ldr r3, [r0, #8]
	add r4, r3, r1
	mov r3, #0x17
	lsl r3, r3, #6
	str r6, [r4, r3]
	ldr r3, [r0, #8]
	add r1, #0xc
	add r4, r3, r7
	ldr r3, _02035D98 ; =0x0000066C
	add r7, r7, #4
	str r6, [r4, r3]
	mov r3, ip
	add r3, r3, #2
	mov ip, r3
	cmp r2, #8
	blt _02035C9C
	ldr r1, _02035D5C ; =_021D4140
	ldr r0, _02035D9C ; =0x00000668
	ldr r2, [r1, #8]
	add r3, r0, #0
	str r6, [r2, r0]
	ldr r4, [r1, #8]
	sub r3, #0x3e
	mov r2, #0xee
	strb r2, [r4, r3]
	add r3, r0, #0
	ldr r4, [r1, #8]
	ldr r2, _02035D8C ; =0x0000FFFF
	sub r3, #0x40
	strh r2, [r4, r3]
	add r2, r0, #0
	ldr r3, [r1, #8]
	sub r2, #0x44
	str r6, [r3, r2]
	add r2, r0, #0
	ldr r3, [r1, #8]
	sub r2, #0x48
	str r6, [r3, r2]
	add r3, r0, #0
	ldr r4, [r1, #8]
	add r3, #0x4a
	mov r2, #1
	strb r2, [r4, r3]
	add r3, r0, #0
	ldr r4, [r1, #8]
	add r3, #0x4b
	strb r2, [r4, r3]
	strb r6, [r1]
	ldr r1, [r1, #8]
	sub r0, #0xe8
	add r0, r1, r0
	bl sub_02033F70
	ldr r0, _02035D5C ; =_021D4140
	ldr r1, [r0, #8]
	mov r0, #0x5a
	lsl r0, r0, #4
	add r0, r1, r0
	bl sub_02033F70
	ldr r0, _02035D5C ; =_021D4140
	mov r2, #0
	ldr r1, [r0, #8]
	ldr r0, _02035DA0 ; =0x000006B7
	strb r2, [r1, r0]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02035D5C: .word _021D4140
_02035D60: .word 0x0000048C
_02035D64: .word 0x0000051C
_02035D68: .word 0x0000068C
_02035D6C: .word 0x00000488
_02035D70: .word 0x00000498
_02035D74: .word 0x000004A4
_02035D78: .word 0x000006B4
_02035D7C: .word 0x00000696
_02035D80: .word 0x0000069E
_02035D84: .word 0x00000644
_02035D88: .word 0x000005CA
_02035D8C: .word 0x0000FFFF
_02035D90: .word 0x000005C8
_02035D94: .word 0x000005C4
_02035D98: .word 0x0000066C
_02035D9C: .word 0x00000668
_02035DA0: .word 0x000006B7
	thumb_func_end sub_02035AE0

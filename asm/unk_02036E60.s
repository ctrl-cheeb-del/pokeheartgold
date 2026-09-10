	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02036E60
sub_02036E60: ; 0x02036E60
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r0, #0
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_0203772C
	add r5, r0, #0
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	ldr r0, _02036F24 ; =_021D4140
	ldr r1, [r0, #8]
	ldr r0, _02036F28 ; =0x000006B4
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _02036E90
	mov r0, #0
	b _02036E92
_02036E90:
	mov r0, #1
_02036E92:
	strb r0, [r4]
	bl sub_02035FF0
	cmp r0, #0
	bne _02036EA2
	add r0, r4, #0
	bl sub_02036DA0
_02036EA2:
	ldr r1, _02036F24 ; =_021D4140
	ldr r0, _02036F28 ; =0x000006B4
	ldr r2, [r1, #8]
	mov r3, #0
	strb r3, [r2, r0]
	mov r0, #0x16
	ldr r1, [r1, #8]
	lsl r0, r0, #6
	add r0, r1, r0
	bl sub_02033C50
	cmp r0, #0
	beq _02036ED0
	ldrb r1, [r4]
	mov r0, #2
	orr r0, r1
	strb r0, [r4]
	ldrb r0, [r4]
	cmp r0, #2
	bne _02036F1C
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, pc}
_02036ED0:
	sub r0, r5, #1
	str r0, [sp, #4]
	add r0, r4, #1
	str r0, [sp]
	ldr r0, _02036F24 ; =_021D4140
	mov r2, #1
	ldr r1, [r0, #8]
	mov r0, #0x16
	lsl r0, r0, #6
	add r0, r1, r0
	add r1, sp, #0
	bl sub_02033ECC
	cmp r0, #0
	bne _02036EF8
	ldr r0, _02036F24 ; =_021D4140
	mov r2, #1
	ldr r1, [r0, #8]
	ldr r0, _02036F28 ; =0x000006B4
	strb r2, [r1, r0]
_02036EF8:
	bl sub_02035FF0
	cmp r0, #1
	bne _02036F1C
	ldr r2, _02036F24 ; =_021D4140
	ldr r1, _02036F2C ; =0x000006AA
	ldr r3, [r2, #8]
	ldrb r0, [r3, r1]
	add r0, r0, #1
	strb r0, [r3, r1]
	ldr r2, [r2, #8]
	ldrb r0, [r4]
	ldrb r1, [r2, r1]
	lsl r2, r1, #4
	mov r1, #0xf0
	and r1, r2
	orr r0, r1
	strb r0, [r4]
_02036F1C:
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_02036F24: .word _021D4140
_02036F28: .word 0x000006B4
_02036F2C: .word 0x000006AA
	thumb_func_end sub_02036E60
	thumb_func_start sub_02036F30
sub_02036F30: ; 0x02036F30
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	mov r0, #0xb
	strb r0, [r4]
	ldr r0, _02036FA0 ; =_021D4140
	ldr r1, [r0, #8]
	ldr r0, _02036FA4 ; =0x000006B5
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _02036F4A
	mov r0, #0
	b _02036F4C
_02036F4A:
	mov r0, #1
_02036F4C:
	strb r0, [r4, #1]
	bl sub_02033250
	asr r1, r0, #8
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	mov r0, #0xbb
	str r0, [sp, #4]
	add r0, r4, #5
	str r0, [sp]
	ldr r0, _02036FA0 ; =_021D4140
	mov r2, #0
	ldr r1, [r0, #8]
	mov r0, #0x5a
	lsl r0, r0, #4
	add r0, r1, r0
	add r1, sp, #0
	bl sub_02033ECC
	cmp r0, #0
	beq _02036F8C
	ldr r0, _02036FA0 ; =_021D4140
	mov r2, #0
	ldr r1, [r0, #8]
	ldr r0, _02036FA4 ; =0x000006B5
	strb r2, [r1, r0]
	ldr r1, [sp, #4]
	mov r0, #0xbb
	sub r0, r0, r1
	add sp, #8
	strb r0, [r4, #4]
	pop {r4, pc}
_02036F8C:
	ldr r0, _02036FA0 ; =_021D4140
	mov r2, #1
	ldr r1, [r0, #8]
	ldr r0, _02036FA4 ; =0x000006B5
	strb r2, [r1, r0]
	mov r0, #0xbb
	strb r0, [r4, #4]
	add sp, #8
	pop {r4, pc}
	nop
_02036FA0: .word _021D4140
_02036FA4: .word 0x000006B5
	thumb_func_end sub_02036F30

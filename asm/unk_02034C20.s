	.include "asm/macros.inc"
	.include "unk_02034B0C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02034C20
sub_02034C20: ; 0x02034C20
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl sub_0203993C
	add r5, r0, #0
	bl sub_02039954
	add r4, r6, #0
	add r7, r0, #0
	add r4, #0x50
	cmp r5, #0xe
	beq _02034C62
	ldrb r0, [r4, #4]
	bl sub_0203401C
	cmp r0, #0
	beq _02034C4C
	add r0, r5, #0
	bl sub_0203401C
	cmp r0, #0
	bne _02034C62
_02034C4C:
	add r0, r4, #0
	add r0, #0x54
	ldrb r0, [r0]
	cmp r0, #0
	beq _02034C5C
	ldrb r0, [r4, #4]
	cmp r0, #0xa
	beq _02034C88
_02034C5C:
	ldrb r0, [r4, #4]
	cmp r0, r5
	bne _02034C88
_02034C62:
	cmp r5, #0xe
	beq _02034C6C
	ldrb r0, [r4, #5]
	cmp r0, r7
	bne _02034C88
_02034C6C:
	ldr r1, _02034C8C ; =_021D4134
	add r0, r6, #0
	ldr r1, [r1, #8]
	mov r2, #0xc0
	add r1, #0x54
	bl MI_CpuCopy8
	ldr r0, _02034C8C ; =_021D4134
	ldr r1, _02034C90 ; =0x00000D95
	ldr r3, [r0, #8]
	mov r0, #0x40
	ldrb r2, [r3, r1]
	orr r0, r2
	strb r0, [r3, r1]
_02034C88:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02034C8C: .word _021D4134
_02034C90: .word 0x00000D95
	thumb_func_end sub_02034C20
	thumb_func_start sub_02034C94
sub_02034C94: ; 0x02034C94
	push {r3, r4, r5, r6, r7, lr}
	ldr r0, _02034D50 ; =_021D4134
	ldr r1, _02034D54 ; =0x00000D95
	ldr r3, [r0, #8]
	ldrb r2, [r3, r1]
	add r7, r3, #0
	add r7, #0x54
	lsl r0, r2, #0x19
	lsr r0, r0, #0x1f
	beq _02034D4E
	mov r0, #0x40
	mov r6, #0
	bic r2, r0
	strb r2, [r3, r1]
	add r4, r6, #0
	add r5, r6, #0
_02034CB4:
	ldr r0, _02034D50 ; =_021D4134
	ldr r1, _02034D58 ; =0x00000D44
	ldr r0, [r0, #8]
	add r2, r0, r4
	ldrh r1, [r2, r1]
	cmp r1, #0
	beq _02034CFC
	mov r1, #0x46
	lsl r1, r1, #2
	add r0, r0, r1
	add r0, r0, r5
	add r1, r7, #4
	mov r2, #6
	bl sub_02034BF8
	cmp r0, #0
	beq _02034CFC
	ldr r2, _02034D50 ; =_021D4134
	mov r1, #0x4b
	ldr r3, [r2, #8]
	lsl r0, r6, #1
	add r3, r3, r0
	ldr r0, _02034D58 ; =0x00000D44
	lsl r1, r1, #2
	strh r1, [r3, r0]
	ldr r2, [r2, #8]
	sub r1, #0x18
	add r3, r2, r1
	mov r2, #0xc0
	add r1, r6, #0
	mul r1, r2
	add r0, r7, #0
	add r1, r3, r1
	bl MI_CpuCopy8
	pop {r3, r4, r5, r6, r7, pc}
_02034CFC:
	add r6, r6, #1
	add r4, r4, #2
	add r5, #0xc0
	cmp r6, #0x10
	blt _02034CB4
	ldr r0, _02034D50 ; =_021D4134
	ldr r1, _02034D58 ; =0x00000D44
	ldr r0, [r0, #8]
	mov r3, #0
	add r4, r0, #0
_02034D10:
	ldrh r2, [r4, r1]
	cmp r2, #0
	beq _02034D1E
	add r3, r3, #1
	add r4, r4, #2
	cmp r3, #0x10
	blt _02034D10
_02034D1E:
	cmp r3, #0x10
	bge _02034D4E
	lsl r2, r3, #1
	mov r1, #0x4b
	add r2, r0, r2
	ldr r0, _02034D58 ; =0x00000D44
	lsl r1, r1, #2
	strh r1, [r2, r0]
	ldr r2, _02034D50 ; =_021D4134
	sub r1, #0x18
	ldr r2, [r2, #8]
	add r0, r7, #0
	add r4, r2, r1
	mov r2, #0xc0
	add r1, r3, #0
	mul r1, r2
	add r1, r4, r1
	bl MI_CpuCopy8
	ldr r0, _02034D50 ; =_021D4134
	mov r2, #1
	ldr r1, [r0, #8]
	ldr r0, _02034D5C ; =0x00000D74
	strb r2, [r1, r0]
_02034D4E:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02034D50: .word _021D4134
_02034D54: .word 0x00000D95
_02034D58: .word 0x00000D44
_02034D5C: .word 0x00000D74
	thumb_func_end sub_02034C94

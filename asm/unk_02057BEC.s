	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02057BEC
sub_02057BEC: ; 0x02057BEC
	push {r4, lr}
	add r4, r0, #0
	bl sub_02057B4C
	ldr r1, _02057C1C ; =0x0000FFFF
	cmp r0, r1
	bne _02057BFE
	add r0, r1, #0
	pop {r4, pc}
_02057BFE:
	ldr r0, _02057C20 ; =_021D41C4
	lsl r4, r4, #3
	ldr r0, [r0]
	add r1, r0, r4
	mov r0, #0x38
	ldrsb r0, [r1, r0]
	bl GetDeltaXByFacingDirection
	ldr r1, _02057C20 ; =_021D41C4
	ldr r1, [r1]
	add r1, r1, r4
	ldrh r1, [r1, #0x34]
	add r0, r1, r0
	pop {r4, pc}
	nop
_02057C1C: .word 0x0000FFFF
_02057C20: .word _021D41C4
	thumb_func_end sub_02057BEC
	thumb_func_start sub_02057C24
sub_02057C24: ; 0x02057C24
	push {r4, lr}
	add r4, r0, #0
	bl sub_02057B9C
	ldr r1, _02057C54 ; =0x0000FFFF
	cmp r0, r1
	bne _02057C36
	add r0, r1, #0
	pop {r4, pc}
_02057C36:
	ldr r0, _02057C58 ; =_021D41C4
	lsl r4, r4, #3
	ldr r0, [r0]
	add r1, r0, r4
	mov r0, #0x38
	ldrsb r0, [r1, r0]
	bl GetDeltaYByFacingDirection
	ldr r1, _02057C58 ; =_021D41C4
	ldr r1, [r1]
	add r1, r1, r4
	ldrh r1, [r1, #0x36]
	add r0, r1, r0
	pop {r4, pc}
	nop
_02057C54: .word 0x0000FFFF
_02057C58: .word _021D41C4
	thumb_func_end sub_02057C24
	thumb_func_start sub_02057C5C
sub_02057C5C: ; 0x02057C5C
	push {r3, r4}
	ldr r3, _02057C90 ; =_021D41C4
	ldr r4, [r3]
	add r4, #0xb4
	ldrb r2, [r4, r0]
	cmp r1, r2
	beq _02057C8C
	strb r1, [r4, r0]
	ldr r2, [r3]
	lsl r1, r0, #3
	add r2, r2, r1
	mov r4, #0
	add r2, #0x3b
	strb r4, [r2]
	ldr r2, [r3]
	mov r4, #1
	add r0, r2, r0
	add r0, #0xcc
	strb r4, [r0]
	ldr r0, [r3]
	mov r2, #2
	add r0, r0, r1
	add r0, #0x39
	strb r2, [r0]
_02057C8C:
	pop {r3, r4}
	bx lr
	.balign 4, 0
_02057C90: .word _021D41C4
	thumb_func_end sub_02057C5C
	thumb_func_start sub_02057C94
sub_02057C94: ; 0x02057C94
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	ldr r1, _02057D48 ; =_020FC7A0
	add r0, sp, #8
	ldrh r2, [r1]
	ldr r3, _02057D4C ; =_020FC7A8
	strh r2, [r0]
	ldrh r2, [r1, #2]
	strh r2, [r0, #2]
	ldrh r2, [r1, #4]
	ldrh r1, [r1, #6]
	strh r2, [r0, #4]
	strh r1, [r0, #6]
	add r2, sp, #0x20
	mov r1, #8
_02057CB2:
	ldrh r0, [r3]
	add r3, r3, #2
	strh r0, [r2]
	add r2, r2, #2
	sub r1, r1, #1
	bne _02057CB2
	bl sub_0203993C
	bl sub_0203774C
	add r6, r0, #0
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp]
	cmp r6, #2
	bne _02057CD6
	add r5, sp, #8
	b _02057CD8
_02057CD6:
	add r5, sp, #0x20
_02057CD8:
	mov r7, #0
	cmp r6, #0
	ble _02057D24
_02057CDE:
	mov r4, #0
	cmp r6, #0
	ble _02057D1C
_02057CE4:
	add r0, r4, #0
	bl sub_02057A34
	ldrh r1, [r5]
	cmp r1, r0
	bne _02057D16
	add r0, r4, #0
	bl sub_02057A88
	ldrh r1, [r5, #2]
	cmp r1, r0
	bne _02057D16
	ldr r0, [sp, #4]
	lsl r1, r4, #2
	add r0, r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x10
	str r7, [r0, r1]
	bl sub_0203769C
	cmp r4, r0
	bne _02057D1C
	mov r0, #1
	str r0, [sp]
	b _02057D1C
_02057D16:
	add r4, r4, #1
	cmp r4, r6
	blt _02057CE4
_02057D1C:
	add r7, r7, #1
	add r5, r5, #4
	cmp r7, r6
	blt _02057CDE
_02057D24:
	ldr r0, [sp, #4]
	cmp r0, r6
	bne _02057D42
	mov r5, #0
	cmp r6, #0
	ble _02057D42
	add r4, sp, #0x10
_02057D32:
	ldr r0, [r4]
	add r1, r5, #0
	bl sub_02037894
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, r6
	blt _02057D32
_02057D42:
	ldr r0, [sp]
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02057D48: .word _020FC7A0
_02057D4C: .word _020FC7A8
	thumb_func_end sub_02057C94

	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02057D74
sub_02057D74: ; 0x02057D74
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	bl sub_0203993C
	bl sub_0203774C
	add r7, r0, #0
	cmp r7, #2
	bne _02057D8C
	ldr r0, _02057DFC ; =_0210FAB4
	str r0, [sp]
	b _02057D90
_02057D8C:
	ldr r0, _02057E00 ; =_0210FABC
	str r0, [sp]
_02057D90:
	mov r1, #0
	add r0, sp, #4
	strb r1, [r0]
	cmp r7, #0
	ble _02057DF8
_02057D9A:
	ldr r0, _02057E04 ; =_021D41C4
	add r6, sp, #4
	ldr r1, [r0]
	ldrb r0, [r6]
	add r0, r1, r0
	add r0, #0xe6
	ldrb r0, [r0]
	cmp r0, #0
	beq _02057DEA
	mov r4, #0
	cmp r7, #0
	ble _02057DEA
	ldr r5, [sp]
_02057DB4:
	ldrb r0, [r6]
	bl sub_02057B4C
	ldrh r1, [r5]
	cmp r1, r0
	bne _02057DE2
	ldrb r0, [r6]
	bl sub_02057B9C
	ldrh r1, [r5, #2]
	cmp r1, r0
	bne _02057DE2
	ldr r0, _02057E04 ; =_021D41C4
	ldr r1, [r0]
	ldrb r0, [r6]
	add r1, r1, r0
	add r1, #0xbc
	mov r0, #1
	strb r0, [r1]
	mov r0, #0x5f
	add r1, sp, #4
	bl sub_02037184
_02057DE2:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r7
	blt _02057DB4
_02057DEA:
	add r0, sp, #4
	ldrb r1, [r0]
	add r1, r1, #1
	strb r1, [r0]
	ldrb r0, [r0]
	cmp r0, r7
	blt _02057D9A
_02057DF8:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02057DFC: .word _0210FAB4
_02057E00: .word _0210FABC
_02057E04: .word _021D41C4
	thumb_func_end sub_02057D74
	thumb_func_start sub_02057E08
sub_02057E08: ; 0x02057E08
	push {r4, lr}
	bl sub_0203769C
	add r4, r0, #0
	bl sub_02057A34
	cmp r0, #8
	ble _02057E28
	mov r0, #2
	bl sub_02057F28
	mov r0, #2
	mov r1, #0x24
	bl sub_0206234C
	b _02057E36
_02057E28:
	mov r0, #3
	bl sub_02057F28
	mov r0, #3
	mov r1, #0x24
	bl sub_0206234C
_02057E36:
	add r1, r0, #0
	ldr r0, _02057E4C ; =_021D41C4
	ldr r2, [r0]
	lsl r0, r4, #2
	add r0, r2, r0
	ldr r0, [r0, #4]
	bl sub_0205DFD4
	bl sub_02058024
	pop {r4, pc}
	.balign 4, 0
_02057E4C: .word _021D41C4
	thumb_func_end sub_02057E08
	thumb_func_start sub_02057E50
sub_02057E50: ; 0x02057E50
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	bl sub_0203993C
	bl sub_0203774C
	str r0, [sp]
	ldr r1, [sp]
	mov r0, #0
	cmp r1, #0
	ble _02057E8E
	ldr r1, _02057EE8 ; =_021D41C4
	ldr r2, [r1]
_02057E6A:
	add r1, r2, #0
	add r1, #0x24
	ldrb r1, [r1]
	cmp r1, #0
	beq _02057E7E
	add r1, r2, #0
	add r1, #0xcc
	ldrb r1, [r1]
	cmp r1, #1
	bne _02057E84
_02057E7E:
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02057E84:
	ldr r1, [sp]
	add r0, r0, #1
	add r2, r2, #1
	cmp r0, r1
	blt _02057E6A
_02057E8E:
	ldr r0, [sp]
	mov r5, #0
	cmp r0, #0
	ble _02057EE2
	add r4, r5, #0
_02057E98:
	ldr r0, _02057EE8 ; =_021D41C4
	ldr r7, [r0]
	mov r0, #4
	add r7, #0x34
	add r6, r7, r4
	ldrsb r0, [r6, r0]
	bl sub_02057EEC
	str r0, [sp, #4]
	bl GetDeltaXByFacingDirection
	ldrh r1, [r7, r4]
	add r0, r1, r0
	strh r0, [r7, r4]
	ldr r0, [sp, #4]
	bl GetDeltaYByFacingDirection
	ldrh r1, [r6, #2]
	add r0, r1, r0
	strh r0, [r6, #2]
	mov r0, #2
	strb r0, [r6, #5]
	ldr r0, _02057EE8 ; =_021D41C4
	ldr r0, [r0]
	add r1, r0, r5
	add r1, #0xcc
	mov r0, #1
	strb r0, [r1]
	add r0, r5, #0
	mov r1, #1
	bl sub_02057C5C
	ldr r0, [sp]
	add r5, r5, #1
	add r4, #8
	cmp r5, r0
	blt _02057E98
_02057EE2:
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02057EE8: .word _021D41C4
	thumb_func_end sub_02057E50

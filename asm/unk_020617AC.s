	.include "asm/macros.inc"
	.include "unk_02061284.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020617AC
sub_020617AC: ; 0x020617AC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	ldr r3, _0206183C ; =_020FD754
	add r2, sp, #0x14
	add r7, r0, #0
	add r6, r1, #0
	ldmia r3!, {r0, r1}
	add r5, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r4, _02061840 ; =_020FD768
	str r0, [r2]
	add r3, sp, #0
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	str r0, [r3]
	mov r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #2
	beq _020617E2
	add r5, r2, #0
_020617E2:
	add r0, r7, #0
	bl MapObject_GetFacingDirection
	mov r4, #0
	ldr r2, [r5]
	sub r1, r4, #1
	cmp r2, r1
	beq _02061806
	add r1, r5, #0
	sub r2, r4, #1
_020617F6:
	ldr r3, [r1]
	cmp r0, r3
	beq _02061806
	add r1, r1, #4
	ldr r3, [r1]
	add r4, r4, #1
	cmp r3, r2
	bne _020617F6
_02061806:
	lsl r0, r4, #2
	ldr r1, [r5, r0]
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	bne _02061816
	bl GF_AssertFail
_02061816:
	add r4, r4, #1
	lsl r0, r4, #2
	ldr r1, [r5, r0]
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	bne _02061826
	mov r4, #0
_02061826:
	lsl r1, r4, #2
	ldr r1, [r5, r1]
	add r0, r7, #0
	bl MapObject_SetFacingDirection
	mov r0, #0
	strb r0, [r6, #2]
	mov r0, #1
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0206183C: .word _020FD754
_02061840: .word _020FD768
	thumb_func_end sub_020617AC

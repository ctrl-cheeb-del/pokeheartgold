	.include "asm/macros.inc"
	.include "unk_02061284.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020618C8
sub_020618C8: ; 0x020618C8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	ldr r3, _02061974 ; =_020FD77C
	add r2, sp, #0x14
	add r7, r0, #0
	add r6, r1, #0
	ldmia r3!, {r0, r1}
	add r5, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _02061978 ; =_020FD7A4
	str r0, [r2]
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	add r4, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	mov r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #2
	beq _020618FE
	add r5, r4, #0
_020618FE:
	add r0, r7, #0
	bl MapObject_GetFacingDirection
	mov r4, #0
	ldr r2, [r5]
	sub r1, r4, #1
	cmp r2, r1
	beq _02061922
	add r1, r5, #0
	sub r2, r4, #1
_02061912:
	ldr r3, [r1]
	cmp r0, r3
	beq _02061922
	add r1, r1, #4
	ldr r3, [r1]
	add r4, r4, #1
	cmp r3, r2
	bne _02061912
_02061922:
	lsl r0, r4, #2
	ldr r1, [r5, r0]
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	bne _02061932
	bl GF_AssertFail
_02061932:
	add r4, r4, #1
	lsl r0, r4, #2
	ldr r1, [r5, r0]
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	bne _02061942
	mov r4, #0
_02061942:
	lsl r1, r4, #2
	ldr r1, [r5, r1]
	add r0, r7, #0
	bl MapObject_SetFacingDirection
	add r0, r7, #0
	bl MapObject_GetFacingDirection
	add r4, r0, #0
	add r0, r7, #0
	bl MapObject_GetInitialFacingDirection
	cmp r4, r0
	bne _02061968
	mov r0, #0
	ldrsb r0, [r6, r0]
	bl sub_020611F4
	strb r0, [r6]
_02061968:
	mov r0, #0
	strb r0, [r6, #2]
	mov r0, #1
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02061974: .word _020FD77C
_02061978: .word _020FD7A4
	thumb_func_end sub_020618C8

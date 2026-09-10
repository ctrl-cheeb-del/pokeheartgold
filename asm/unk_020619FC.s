	.include "asm/macros.inc"
	.include "unk_02061284.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020619FC
sub_020619FC: ; 0x020619FC
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	mov r1, #2
	ldrsh r1, [r6, r1]
	add r5, r0, #0
	cmp r1, #0
	beq _02061A5A
	bl MapObject_GetInitialX
	add r7, r0, #0
	add r0, r5, #0
	bl MapObject_GetInitialZ
	str r0, [sp]
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_GetZCoord
	cmp r7, r4
	bne _02061A5A
	ldr r1, [sp]
	cmp r1, r0
	bne _02061A5A
	add r0, r5, #0
	bl MapObject_GetNextFacingDirection
	bl sub_020611F4
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl MapObject_SetNextFacingDirection
	add r0, r5, #0
	bl sub_02062050
	cmp r0, #0
	bne _02061A56
	add r0, r5, #0
	add r1, r4, #0
	bl MapObject_SetFacingDirection
_02061A56:
	mov r0, #0
	strh r0, [r6, #2]
_02061A5A:
	add r0, r5, #0
	bl MapObject_GetNextFacingDirection
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060BB8
	mov r1, #1
	add r2, r0, #0
	tst r2, r1
	beq _02061A84
	add r0, r4, #0
	strh r1, [r6, #2]
	bl sub_020611F4
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060BB8
_02061A84:
	mov r1, #0xc
	cmp r0, #0
	beq _02061A8C
	mov r1, #0x20
_02061A8C:
	add r0, r4, #0
	bl sub_0206234C
	add r1, r0, #0
	add r0, r5, #0
	bl MapObject_ForceSetHeldMovement
	add r0, r5, #0
	bl sub_02062050
	cmp r0, #1
	bne _02061AAC
	add r0, r5, #0
	add r1, r6, #4
	bl sub_0206207C
_02061AAC:
	add r0, r5, #0
	bl MapObject_SetSingleMovement
	mov r0, #2
	strh r0, [r6]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020619FC

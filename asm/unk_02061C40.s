	.include "asm/macros.inc"
	.include "unk_02061284.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02061C40
sub_02061C40: ; 0x02061C40
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	ldrb r2, [r4, #1]
	ldrb r1, [r4, #2]
	add r6, r0, #0
	cmp r2, r1
	bne _02061C82
	ldrb r1, [r4, #3]
	cmp r1, #0
	bne _02061C6C
	bl MapObject_GetInitialX
	add r5, r0, #0
	add r0, r6, #0
	bl MapObject_GetXCoord
	cmp r5, r0
	bne _02061C82
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
	b _02061C82
_02061C6C:
	bl MapObject_GetInitialZ
	add r5, r0, #0
	add r0, r6, #0
	bl MapObject_GetZCoord
	cmp r5, r0
	bne _02061C82
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
_02061C82:
	ldrb r0, [r4, #1]
	cmp r0, #3
	bne _02061CB4
	add r0, r6, #0
	bl MapObject_GetInitialX
	add r7, r0, #0
	add r0, r6, #0
	bl MapObject_GetInitialZ
	str r0, [sp]
	add r0, r6, #0
	bl MapObject_GetXCoord
	add r5, r0, #0
	add r0, r6, #0
	bl MapObject_GetZCoord
	cmp r7, r5
	bne _02061CB4
	ldr r1, [sp]
	cmp r1, r0
	bne _02061CB4
	mov r0, #0
	strb r0, [r4, #1]
_02061CB4:
	ldr r0, [r4, #4]
	bl sub_02061E6C
	add r7, r0, #0
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	ldr r5, [r7, r0]
	add r0, r6, #0
	add r1, r5, #0
	bl MapObject_SetNextFacingDirection
	add r0, r6, #0
	bl sub_02062050
	cmp r0, #0
	bne _02061CDC
	add r0, r6, #0
	add r1, r5, #0
	bl MapObject_SetFacingDirection
_02061CDC:
	add r0, r6, #0
	add r1, r5, #0
	bl sub_02060BB8
	mov r1, #1
	tst r1, r0
	beq _02061D18
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	ldr r5, [r7, r0]
	add r0, r6, #0
	add r1, r5, #0
	bl MapObject_SetNextFacingDirection
	add r0, r6, #0
	bl sub_02062050
	cmp r0, #0
	bne _02061D10
	add r0, r6, #0
	add r1, r5, #0
	bl MapObject_SetFacingDirection
_02061D10:
	add r0, r6, #0
	add r1, r5, #0
	bl sub_02060BB8
_02061D18:
	mov r1, #0xc
	cmp r0, #0
	beq _02061D20
	mov r1, #0x20
_02061D20:
	add r0, r5, #0
	bl sub_0206234C
	add r1, r0, #0
	add r0, r6, #0
	bl MapObject_ForceSetHeldMovement
	add r0, r6, #0
	bl sub_02062050
	cmp r0, #1
	bne _02061D42
	add r1, r4, #0
	add r0, r6, #0
	add r1, #8
	bl sub_0206207C
_02061D42:
	add r0, r6, #0
	bl MapObject_SetSingleMovement
	mov r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02061C40

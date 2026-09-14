	.include "asm/macros.inc"
	.include "unk_02061284.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02061E90
sub_02061E90: ; 0x02061E90
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl MapObject_GetType
	cmp r0, #1
	beq _02061EA6
	cmp r0, #2
	beq _02061EA6
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_02061EA6:
	add r0, r5, #0
	bl MapObject_GetFieldSystem
	bl FieldSystem_GetPlayerAvatar
	add r6, r0, #0
	bl sub_0205DE98
	cmp r0, #0
	bne _02061EC0
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_02061EC0:
	add r0, r5, #0
	mov r4, #0
	bl MapObject_GetMovement
	ldr r1, _02061F58 ; =_020FD800
_02061ECA:
	lsl r2, r4, #2
	ldr r2, [r1, r2]
	add r4, r4, #1
	cmp r2, r0
	beq _02061ED8
	cmp r2, #0xff
	bne _02061ECA
_02061ED8:
	cmp r0, r2
	beq _02061EE2
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_02061EE2:
	add r0, r6, #0
	bl PlayerAvatar_GetMapObject
	bl MapObject_GetPositionVectorYCoordUInt
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_GetPositionVectorYCoordUInt
	cmp r4, r0
	beq _02061EFE
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
_02061EFE:
	add r0, r6, #0
	bl PlayerAvatar_GetXCoord
	add r4, r0, #0
	add r0, r6, #0
	bl PlayerAvatar_GetZCoord
	add r6, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl MapObject_GetParam
	str r0, [sp]
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r7, r0, #0
	add r0, r5, #0
	bl MapObject_GetZCoord
	add r2, r0, #0
	ldr r3, [sp]
	ldr r0, [sp]
	add r5, r2, r3
	sub r1, r7, r0
	sub r3, r2, r3
	add r0, r7, r0
	cmp r3, r6
	bgt _02061F52
	cmp r5, r6
	blt _02061F52
	cmp r1, r4
	bgt _02061F52
	cmp r0, r4
	blt _02061F52
	add r1, r2, #0
	add r0, r7, #0
	add r2, r4, #0
	add r3, r6, #0
	bl sub_02061200
	pop {r3, r4, r5, r6, r7, pc}
_02061F52:
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02061F58: .word _020FD800
	thumb_func_end sub_02061E90

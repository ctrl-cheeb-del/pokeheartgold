	.include "asm/macros.inc"
	.include "unk_02061284.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02061E6C
sub_02061E6C: ; 0x02061E6C
	push {r3, lr}
	ldr r1, _02061E8C ; =_020FD838
	mov r2, #0
_02061E72:
	cmp r2, r0
	bne _02061E7A
	ldr r0, [r1, #4]
	pop {r3, pc}
_02061E7A:
	add r1, #8
	ldr r2, [r1]
	cmp r2, #0x27
	bne _02061E72
	bl GF_AssertFail
	mov r0, #0
	pop {r3, pc}
	nop
_02061E8C: .word _020FD838
	thumb_func_end sub_02061E6C
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
	thumb_func_start sub_02061F5C
sub_02061F5C: ; 0x02061F5C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r0, [sp]
	add r4, r2, #0
	add r0, r1, #0
	bl sub_02061E6C
	add r1, r4, #0
	add r5, r0, #0
	bl sub_02061E00
	add r4, r0, #0
	cmp r4, #1
	bne _02061F80
	mov r0, #0
	add sp, #0x14
	mvn r0, r0
	pop {r4, r5, r6, r7, pc}
_02061F80:
	ldr r0, [sp]
	bl sub_02061E90
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0206204A
	mov r2, #0
	add r3, r5, #0
_02061F92:
	ldr r1, [r3]
	cmp r0, r1
	beq _0206204A
	add r2, r2, #1
	add r3, r3, #4
	cmp r2, r4
	blt _02061F92
	mov r7, #0
	mvn r7, r7
	ldr r0, [sp]
	add r6, r7, #0
	bl MapObject_GetXCoord
	str r0, [sp, #8]
	ldr r0, [sp]
	bl MapObject_GetZCoord
	str r0, [sp, #4]
	ldr r0, [sp]
	bl MapObject_GetFieldSystem
	bl FieldSystem_GetPlayerAvatar
	str r0, [sp, #0xc]
	bl PlayerAvatar_GetXCoord
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	bl PlayerAvatar_GetZCoord
	ldr r2, [sp, #8]
	ldr r1, [sp, #0x10]
	cmp r2, r1
	ble _02061FDA
	mov r7, #2
	b _02061FE0
_02061FDA:
	cmp r2, r1
	bge _02061FE0
	mov r7, #3
_02061FE0:
	ldr r1, [sp, #4]
	cmp r1, r0
	ble _02061FEA
	mov r6, #0
	b _02061FF0
_02061FEA:
	cmp r1, r0
	bge _02061FF0
	mov r6, #1
_02061FF0:
	mov r0, #0
	sub r1, r0, #1
	cmp r7, r1
	bne _0206200E
_02061FF8:
	ldr r1, [r5]
	cmp r6, r1
	bne _02062004
	add sp, #0x14
	add r0, r6, #0
	pop {r4, r5, r6, r7, pc}
_02062004:
	add r0, r0, #1
	add r5, r5, #4
	cmp r0, r4
	blt _02061FF8
	b _02062046
_0206200E:
	cmp r6, r1
	bne _02062028
_02062012:
	ldr r1, [r5]
	cmp r7, r1
	bne _0206201E
	add sp, #0x14
	add r0, r7, #0
	pop {r4, r5, r6, r7, pc}
_0206201E:
	add r0, r0, #1
	add r5, r5, #4
	cmp r0, r4
	blt _02062012
	b _02062046
_02062028:
	ldr r1, [r5]
	cmp r7, r1
	bne _02062034
	add sp, #0x14
	add r0, r7, #0
	pop {r4, r5, r6, r7, pc}
_02062034:
	cmp r6, r1
	bne _0206203E
	add sp, #0x14
	add r0, r6, #0
	pop {r4, r5, r6, r7, pc}
_0206203E:
	add r0, r0, #1
	add r5, r5, #4
	cmp r0, r4
	blt _02062028
_02062046:
	mov r0, #0
	mvn r0, r0
_0206204A:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02061F5C

	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start CommPlayerManager_ForcePosition
CommPlayerManager_ForcePosition: ; 0x02057FA4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r0, _02058020 ; =_021D41C4
	ldr r0, [r0]
	cmp r0, #0
	beq _0205801A
	mov r6, #0
	add r4, r6, #0
	add r5, r6, #0
_02057FB6:
	ldr r0, _02058020 ; =_021D41C4
	ldr r0, [r0]
	add r0, r0, r4
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _02058010
	bl sub_0203769C
	cmp r6, r0
	beq _02058010
	ldr r0, _02058020 ; =_021D41C4
	ldr r0, [r0]
	add r0, r0, r4
	ldr r0, [r0, #4]
	bl PlayerAvatar_GetMapObject
	ldr r1, _02058020 ; =_021D41C4
	str r0, [sp, #0xc]
	ldr r1, [r1]
	add r1, r1, r5
	add r2, r1, #0
	add r2, #0x74
	ldrh r2, [r2]
	str r2, [sp, #8]
	add r2, r1, #0
	add r2, #0x76
	ldrh r7, [r2]
	mov r2, #0x78
	ldrsb r1, [r1, r2]
	str r1, [sp, #4]
	ldr r1, [sp, #8]
	bl MapObject_SetCurrentX
	ldr r0, [sp, #0xc]
	add r1, r7, #0
	bl MapObject_SetCurrentZ
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [sp]
	ldr r0, [sp, #0xc]
	mov r2, #0
	add r3, r7, #0
	bl MapObject_SetPositionFromXYZAndDirection
_02058010:
	add r6, r6, #1
	add r4, r4, #4
	add r5, #8
	cmp r6, #8
	blt _02057FB6
_0205801A:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02058020: .word _021D41C4
	thumb_func_end CommPlayerManager_ForcePosition

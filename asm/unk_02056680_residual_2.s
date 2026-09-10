	.include "asm/macros.inc"
	.include "unk_02056680.inc"
	.include "global.inc"

	.text
	.public sub_02056680
	.public sub_020566F8
	.public sub_020567B4
	.public sub_0205681C
	.public sub_02056938
	.public sub_02056A54
	.public sub_02056AEC
	.public sub_02056BC8
	.public sub_02056C64
	.public sub_02056D00
	.public sub_02056D30
	.public sub_020566F8
	.public sub_020567B4
	.public sub_0205681C
	.public sub_02056938
	.public sub_02056BC8
	.public sub_02056C64
	.public sub_02056D00
	.public sub_02056D30

	thumb_func_start sub_02056A54
sub_02056A54: ; 0x02056A54
	push {r3, r4, r5, r6, lr}
	sub sp, #0x34
	add r4, r0, #0
	ldr r0, [r4, #0x24]
	bl Camera_GetCurrentTarget
	add r5, r0, #0
	ldr r1, [r4, #0x24]
	add r0, sp, #4
	bl Camera_GetLookAtCamTarget
	add r6, sp, #4
	add r3, sp, #0x10
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	add r1, r5, #0
	str r0, [r3]
	add r0, r2, #0
	add r2, sp, #0x1c
	bl VEC_Subtract
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetFacingDirection
	add r5, r0, #0
	ldr r0, [r4, #0x40]
	add r1, sp, #0x28
	bl PlayerAvatar_CopyPositionVector
	cmp r5, #3
	bne _02056AA2
	mov r0, #1
	ldr r1, [sp, #0x28]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x28]
	b _02056AAC
_02056AA2:
	mov r0, #1
	ldr r1, [sp, #0x28]
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [sp, #0x28]
_02056AAC:
	mov r0, #0
	str r0, [sp]
	ldr r1, [sp, #0x2c]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x30]
	add r0, r4, #0
	bl sub_02054940
	str r0, [sp, #0x2c]
	ldr r0, [r4, #0x40]
	add r1, sp, #0x28
	add r2, r5, #0
	bl sub_0205C810
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetPositionVector
	ldr r1, [r4, #0x24]
	bl Camera_SetLookAtTargetAndRecalcPos
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetPositionVector
	ldr r1, [r4, #0x24]
	bl Camera_SetFixedTarget
	ldr r1, [r4, #0x24]
	add r0, sp, #0x1c
	bl Camera_OffsetLookAtPosAndTarget
	add sp, #0x34
	pop {r3, r4, r5, r6, pc}
	thumb_func_end sub_02056A54


	thumb_func_start sub_02056AEC
sub_02056AEC: ; 0x02056AEC
	push {r3, r4, r5, r6, lr}
	sub sp, #0x34
	add r5, r0, #0
	ldr r0, [r5, #0x24]
	bl Camera_GetCurrentTarget
	add r4, r0, #0
	ldr r1, [r5, #0x24]
	add r0, sp, #4
	bl Camera_GetLookAtCamTarget
	add r6, sp, #4
	add r3, sp, #0x10
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	add r1, r4, #0
	str r0, [r3]
	add r0, r2, #0
	add r2, sp, #0x1c
	bl VEC_Subtract
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetFacingDirection
	add r4, r0, #0
	ldr r0, [r5, #0x40]
	add r1, sp, #0x28
	bl PlayerAvatar_CopyPositionVector
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetXCoord
	add r6, r0, #0
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetZCoord
	add r2, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	bl GetMetatileBehavior
	add r6, r0, #0
	bl MetatileBehavior_IsWarpStairsEast
	cmp r0, #0
	beq _02056B5A
	mov r0, #1
	ldr r1, [sp, #0x28]
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [sp, #0x28]
	mov r4, #2
	b _02056B70
_02056B5A:
	add r0, r6, #0
	bl MetatileBehavior_IsWarpStairsWest
	cmp r0, #0
	beq _02056B70
	mov r0, #1
	ldr r1, [sp, #0x28]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x28]
	mov r4, #3
_02056B70:
	mov r0, #0
	str r0, [sp]
	ldr r1, [sp, #0x2c]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x30]
	add r0, r5, #0
	bl sub_02054940
	str r0, [sp, #0x2c]
	ldr r0, [r5, #0x40]
	add r1, sp, #0x28
	add r2, r4, #0
	bl sub_0205C810
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetPositionVector
	ldr r1, [r5, #0x24]
	bl Camera_SetLookAtTargetAndRecalcPos
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetPositionVector
	ldr r1, [r5, #0x24]
	bl Camera_SetFixedTarget
	ldr r1, [r5, #0x24]
	add r0, sp, #0x1c
	bl Camera_OffsetLookAtPosAndTarget
	add r0, r5, #0
	bl FollowMon_IsActive
	cmp r0, #0
	beq _02056BC2
	add r0, r5, #0
	bl FollowMon_GetMapObject
	add r1, r4, #0
	bl MapObject_SetFacingDirectionDirect
_02056BC2:
	add sp, #0x34
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_02056AEC

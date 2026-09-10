	.include "asm/macros.inc"
	.include "unk_0205AC88.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205AF78
sub_0205AF78: ; 0x0205AF78
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	ldr r0, [r0, #8]
	str r1, [sp, #4]
	cmp r0, #0
	bne _0205AF8A
	bl GF_AssertFail
_0205AF8A:
	ldr r0, [sp]
	ldr r0, [r0, #8]
	bl PlayerAvatar_GetXCoord
	str r0, [sp, #0xc]
	ldr r0, [sp]
	ldr r0, [r0, #8]
	bl PlayerAvatar_GetZCoord
	ldr r4, [sp]
	str r0, [sp, #8]
	add r6, r4, #0
	mov r7, #0
	add r6, #0xc
_0205AFA6:
	ldr r0, [sp, #4]
	add r1, r7, #1
	bl MapObjectManager_GetFirstActiveObjectByID
	add r5, r0, #0
	bne _0205AFB6
	bl GF_AssertFail
_0205AFB6:
	ldrb r0, [r4, #0xd]
	cmp r0, #4
	bhi _0205B0AA
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0205AFC8: ; jump table
	.short _0205AFD2 - _0205AFC8 - 2 ; case 0
	.short _0205AFF2 - _0205AFC8 - 2 ; case 1
	.short _0205B052 - _0205AFC8 - 2 ; case 2
	.short _0205B07A - _0205AFC8 - 2 ; case 3
	.short _0205B0A6 - _0205AFC8 - 2 ; case 4
_0205AFD2:
	add r0, r5, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _0205B0AA
	ldrb r0, [r4, #0xc]
	sub r0, r0, #1
	cmp r0, #1
	bhi _0205B0AA
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #8]
	add r0, r6, #0
	add r1, r5, #0
	bl sub_0205B13C
	b _0205B0AA
_0205AFF2:
	add r0, r5, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _0205B0AA
	ldrb r0, [r4, #0xc]
	cmp r0, #3
	bne _0205B012
	mov r0, #0
	strb r0, [r4, #0xd]
	strb r0, [r4, #0xc]
	add r0, r6, #0
	mov r1, #1
	bl sub_0205B0DC
	b _0205B0AA
_0205B012:
	add r0, r5, #0
	bl MapObject_ClearHeldMovementIfActive
	add r0, r5, #0
	mov r1, #0
	bl MapObject_SetFlag19
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bne _0205B048
	ldrb r0, [r4, #0x15]
	cmp r0, #0
	bne _0205B048
	add r0, r5, #0
	mov r1, #3
	bl sub_0205FC94
	add r0, r5, #0
	mov r1, #1
	bl MapObject_SetXRange
	add r0, r5, #0
	mov r1, #1
	bl MapObject_SetYRange
	mov r0, #1
	strb r0, [r4, #0x15]
_0205B048:
	mov r0, #2
	strb r0, [r4, #0xd]
	mov r0, #0
	strb r0, [r4, #0xc]
	b _0205B0AA
_0205B052:
	add r0, r5, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _0205B0AA
	add r0, r6, #0
	add r1, r5, #0
	bl sub_0205B218
	ldrb r0, [r4, #0xc]
	cmp r0, #3
	bne _0205B072
	add r0, r6, #0
	add r1, r5, #0
	bl sub_0205B1E4
_0205B072:
	add r0, r6, #0
	bl sub_0205B118
	b _0205B0AA
_0205B07A:
	add r0, r5, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _0205B0AA
	add r0, r5, #0
	bl MapObject_ClearHeldMovementIfActive
	mov r0, #4
	strb r0, [r4, #0xd]
	mov r0, #0
	strb r0, [r4, #0xc]
	strb r0, [r4, #0x15]
	add r0, r5, #0
	mov r1, #1
	bl MapObject_SetVisible
	add r0, r5, #0
	mov r1, #0
	bl MapObject_ClearFlag18
	b _0205B0AA
_0205B0A6:
	mov r0, #0
	strb r0, [r4, #0xd]
_0205B0AA:
	add r7, r7, #1
	add r4, #0x18
	add r6, #0x18
	cmp r7, #0x32
	bge _0205B0B6
	b _0205AFA6
_0205B0B6:
	ldr r0, [sp]
	ldr r0, [r0, #8]
	bl PlayerAvatar_GetMapObject
	add r1, r0, #0
	ldr r2, _0205B0D8 ; =0x000004BC
	ldr r0, [sp]
	add r0, r0, r2
	bl sub_0205B218
	ldr r1, _0205B0D8 ; =0x000004BC
	ldr r0, [sp]
	add r0, r0, r1
	bl sub_0205B118
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0205B0D8: .word 0x000004BC
	thumb_func_end sub_0205AF78

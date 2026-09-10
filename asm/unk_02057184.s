	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02057184
sub_02057184: ; 0x02057184
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r1, _02057248 ; =_021D41C4
	add r5, r0, #0
	ldr r2, [r1]
	lsl r4, r5, #2
	add r1, r2, r4
	ldr r1, [r1, #4]
	cmp r1, #0
	bne _02057242
	add r2, #0xee
	ldrb r1, [r2]
	cmp r1, #0
	bne _02057242
	bl sub_02034818
	str r0, [sp, #0x14]
	cmp r0, #0
	beq _02057242
	bl sub_0203769C
	cmp r5, r0
	beq _020571CC
	ldr r0, _02057248 ; =_021D41C4
	mov r1, #1
	ldr r0, [r0]
	lsl r1, r1, #8
	ldr r0, [r0, #0x30]
	add r1, r5, r1
	ldr r0, [r0, #0x3c]
	bl MapObjectManager_GetFirstActiveObjectByID
	cmp r0, #0
	beq _020571CC
	bl MapObject_Remove
_020571CC:
	ldr r0, [sp, #0x14]
	mov r7, #2
	bl PlayerProfile_GetVersion
	cmp r0, #0
	bne _020571DC
	mov r7, #1
	b _020571E2
_020571DC:
	cmp r0, #0xc
	bne _020571E2
	mov r7, #0
_020571E2:
	lsl r0, r5, #3
	str r0, [sp, #0x10]
	ldr r0, _02057248 ; =_021D41C4
	ldr r6, [r0]
	ldr r0, [sp, #0x14]
	bl PlayerProfile_GetTrainerGender
	mov r1, #0
	str r1, [sp]
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r0, [r6, #0x30]
	add r3, r6, r1
	add r1, r3, #0
	add r2, r3, #0
	add r1, #0x74
	add r2, #0x76
	mov r6, #0x78
	ldrh r1, [r1]
	ldrh r2, [r2]
	ldrsb r3, [r3, r6]
	ldr r0, [r0, #0x3c]
	bl PlayerAvatar_CreateWithParams
	add r6, r0, #0
	bne _0205721E
	bl GF_AssertFail
_0205721E:
	ldr r0, _02057248 ; =_021D41C4
	ldr r0, [r0]
	add r0, r0, r4
	str r6, [r0, #4]
	add r0, r6, #0
	bl PlayerAvatar_GetMapObject
	mov r1, #1
	lsl r1, r1, #8
	add r1, r5, r1
	bl MapObject_SetID
	ldr r0, _02057248 ; =_021D41C4
	mov r1, #1
	ldr r0, [r0]
	add r0, r0, r5
	add r0, #0x24
	strb r1, [r0]
_02057242:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02057248: .word _021D41C4
	thumb_func_end sub_02057184
	thumb_func_start sub_0205724C
sub_0205724C: ; 0x0205724C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _020572A8 ; =_021D41C4
	add r6, r1, #0
	ldr r1, [r0]
	cmp r1, #0
	beq _020572A4
	lsl r4, r5, #2
	add r0, r1, r4
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _02057284
	ldr r1, [r1, #0x30]
	ldr r1, [r1, #0x40]
	cmp r1, r0
	beq _0205727A
	cmp r2, #0
	beq _02057276
	bl PlayerAvatar_DeleteFromMap
	b _0205727A
_02057276:
	bl PlayerAvatar_FreeToHeap
_0205727A:
	ldr r0, _020572A8 ; =_021D41C4
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, r4
	str r1, [r0, #4]
_02057284:
	ldr r0, _020572A8 ; =_021D41C4
	ldr r1, [r0]
	add r1, #0x24
	ldrb r0, [r1, r5]
	cmp r0, #0
	beq _02057298
	cmp r6, #0
	bne _02057298
	mov r0, #0
	strb r0, [r1, r5]
_02057298:
	ldr r0, _020572A8 ; =_021D41C4
	mov r1, #1
	ldr r0, [r0]
	add r0, r0, r5
	add r0, #0xcc
	strb r1, [r0]
_020572A4:
	pop {r4, r5, r6, pc}
	nop
_020572A8: .word _021D41C4
	thumb_func_end sub_0205724C

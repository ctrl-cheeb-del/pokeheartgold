	.include "asm/macros.inc"
	.public ov34_0225D520
	.public ov34_0225D558
	.public ov34_0225D5A0
	.public ov34_0225D5F8
	.public ov34_0225D650
	.public ov34_0225D77C
	.public ov34_0225D7A8
	.public ov34_0225D87C
	.public ov34_0225D900
	.public ov34_0225D924
	.public ov34_0225DA50
	.public ov34_0225DB20
	.public ov34_0225DC00
	.public ov34_0225DC0C
	.public ov34_0225DC18
	.public ov34_0225DD04
	.public ov34_0225DDB8
	.public ov34_0225DE04
	.public ov34_0225DE94
	.public ov34_0225E020
	.public ov34_0225E0E4
	.public ov34_0225E164
	.public ov34_0225E1C4
	.public ov34_0225E2BC
	.public ov34_0225E348
	.public ov34_0225E428
	.public ov34_0225E4A8
	.public ov34_0225E4F8
	.public ov34_0225E560
	.public ov34_0225E56C
	.public ov34_0225E58C
	.public ov34_0225E5D4
	.public ov34_0225E5DC
	.public ov34_0225E5E4
	.public ov34_0225E5EC
	.public ov34_0225E630
	.public _0225E694
	.public ov34_0225E6A0
	.public ov34_0225E6AC
	.public ov34_0225E6C0
	.public ov34_0225E6DC
	.public ov34_0225E6F8
	.public ov34_0225E714
	.public ov34_0225E730
	.include "overlay_34.inc"
	.include "global.inc"

	.text

	thumb_func_start ov34_0225E164
ov34_0225E164: ; 0x0225E164
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r4, #0
	mvn r4, r4
	bl FieldSystem_TaskIsRunning
	cmp r0, #0
	bne _0225E19A
	add r0, r5, #0
	bl ov34_0225DE94
	add r6, r0, #0
	add r0, r5, #0
	bl ov34_0225E020
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	bne _0225E19A
	cmp r4, r0
	bne _0225E19A
	add r0, r5, #0
	bl ov34_0225E0E4
_0225E19A:
	mov r2, #0x27
	lsl r2, r2, #4
	add r0, r2, #0
	ldr r1, [r5, r2]
	add r0, #0xd8
	ldr r0, [r1, r0]
	sub r3, r4, #1
	str r0, [sp]
	add r0, r2, #0
	add r0, #0x20
	add r0, r5, r0
	str r0, [sp, #4]
	sub r2, #0xa8
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x24]
	add r2, r5, r2
	bl ov34_0225E1C4
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov34_0225E164


	thumb_func_start ov34_0225E1C4
ov34_0225E1C4: ; 0x0225E1C4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x40]
	str r1, [sp, #0x20]
	add r5, r2, #0
	mov r1, #0
	str r0, [sp, #0x40]
	ldr r4, [sp, #0x44]
	cmp r0, #3
	ble _0225E1DE
	mov r0, #3
	str r0, [sp, #0x40]
_0225E1DE:
	ldr r2, [sp, #0x40]
	mov r0, #0
	cmp r2, #0
	ble _0225E204
	add r2, r5, #0
_0225E1E8:
	cmp r3, r0
	beq _0225E1F6
	ldr r6, [r2, #0x34]
	cmp r6, #0
	beq _0225E1F6
	sub r6, r6, #1
	str r6, [r2, #0x34]
_0225E1F6:
	ldr r6, [r2, #0x34]
	add r0, r0, #1
	add r1, r1, r6
	ldr r6, [sp, #0x40]
	add r2, #0x38
	cmp r0, r6
	blt _0225E1E8
_0225E204:
	cmp r1, #0
	bne _0225E214
	ldr r0, [r4]
	cmp r0, #0
	bne _0225E214
	add sp, #0x28
	str r1, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_0225E214:
	ldr r0, [sp, #0x40]
	str r1, [r4]
	mov r4, #0
	cmp r0, #0
	ble _0225E28A
	ldr r0, [sp, #0x20]
	mov r7, #2
	add r0, #0xc
	str r0, [sp, #0x20]
_0225E226:
	ldr r1, [r5, #0x34]
	lsl r3, r7, #0x18
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	str r0, [sp, #0x24]
	mov r0, #0x20
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	ldr r0, [sp, #0x20]
	lsr r3, r3, #0x18
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	ldr r1, [r5, #0x30]
	lsl r2, r0, #3
	mov r0, #0x18
	mul r0, r1
	add r0, r2, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	mov r0, #0x20
	str r0, [sp, #0x14]
	mov r0, #0x30
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	mov r1, #7
	mov r2, #0
	bl CopyToBgTilemapRect
	ldr r3, [sp, #0x24]
	add r1, r4, #4
	lsl r6, r3, #2
	ldr r3, _0225E2B8 ; =_0225E694
	lsl r1, r1, #0x18
	ldr r0, [sp, #0x1c]
	ldr r3, [r3, r6]
	lsr r1, r1, #0x18
	mov r2, #3
	bl BgSetPosTextAndCommit
	ldr r0, [sp, #0x40]
	add r4, r4, #1
	add r5, #0x38
	add r7, r7, #7
	cmp r4, r0
	blt _0225E226
_0225E28A:
	ldr r0, [sp, #0x1c]
	mov r1, #7
	bl GetBgTilemapBuffer
	mov r1, #6
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [sp, #0x1c]
	mov r1, #7
	bl GetBgTilemapBuffer
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r3, #6
	ldr r0, [sp, #0x1c]
	mov r1, #7
	lsl r3, r3, #8
	bl BgCopyOrUncompressTilemapBufferRangeToVram
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225E2B8: .word _0225E694
	thumb_func_end ov34_0225E1C4


	thumb_func_start ov34_0225E2BC
ov34_0225E2BC: ; 0x0225E2BC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r0, #0
	mov r4, #0
	ldr r0, [sp, #0x28]
	add r5, r1, #0
	add r7, r2, #0
	str r3, [sp, #8]
	str r4, [sp, #0xc]
	bl PlayerProfile_GetTrainerID
	cmp r5, r0
	beq _0225E2E0
	add r0, r6, #0
	add r1, r5, #0
	bl PalPad_PlayerIdIsFriendOrMutual
	add r4, r0, #0
_0225E2E0:
	cmp r4, #0
	ble _0225E340
	cmp r4, #1
	bne _0225E2F4
	ldr r2, [sp, #0x28]
	add r0, r7, #0
	mov r1, #0
	bl BufferPlayersName
	b _0225E332
_0225E2F4:
	cmp r4, #2
	blt _0225E332
	sub r5, r4, #2
	mov r0, #0xa
	mov r1, #0x57
	bl String_New
	add r4, r0, #0
	add r0, r6, #0
	add r1, r5, #0
	bl PalPad_GetNthEntry
	add r1, r0, #0
	add r0, r4, #0
	bl CopyU16ArrayToString
	add r0, r6, #0
	add r1, r5, #0
	bl PalPadEntry_GetFromUnk68Array
	mov r1, #0
	str r1, [sp]
	str r0, [sp, #4]
	add r0, r7, #0
	add r2, r4, #0
	add r3, r1, #0
	bl BufferString
	add r0, r4, #0
	bl String_Delete
_0225E332:
	ldr r1, [sp, #8]
	add r0, r7, #0
	mov r2, #0xd0
	mov r3, #0x57
	bl ReadMsgData_ExpandPlaceholders
	str r0, [sp, #0xc]
_0225E340:
	ldr r0, [sp, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov34_0225E2BC


	thumb_func_start ov34_0225E348
ov34_0225E348: ; 0x0225E348
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r0, #0
	add r6, r2, #0
	ldr r2, [r7, #4]
	ldr r0, _0225E424 ; =0x000004D8
	str r1, [sp, #4]
	mov r1, #0x27
	ldr r0, [r2, r0]
	lsl r1, r1, #4
	str r0, [sp, #0xc]
	add r0, r1, #0
	ldr r4, [r7, r1]
	add r0, #0xd8
	ldr r0, [r4, r0]
	str r3, [sp, #8]
	cmp r0, #0x1e
	bne _0225E370
	add r1, #0xdc
	b _0225E372
_0225E370:
	add r1, #0xd8
_0225E372:
	add r5, r4, r1
	ldr r1, [r5]
	mov r0, #0x1c
	mul r0, r1
	add r0, r4, r0
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _0225E386
	bl String_Delete
_0225E386:
	ldr r1, [r5]
	mov r0, #0x1c
	mul r0, r1
	add r0, r4, r0
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0225E398
	bl String_Delete
_0225E398:
	ldr r0, [sp, #8]
	bl PlayerProfile_GetNamePtr
	add r1, r0, #0
	ldr r2, [r5]
	mov r0, #0x1c
	mul r0, r2
	ldr r0, [r4, r0]
	bl CopyU16ArrayToString
	ldr r0, [r5]
	mov r1, #0x1c
	add r2, r0, #0
	mul r2, r1
	add r0, r4, r2
	ldrh r2, [r6]
	strh r2, [r0, #0x14]
	ldrh r2, [r6, #2]
	strh r2, [r0, #0x16]
	ldrh r2, [r6, #4]
	strh r2, [r0, #0x18]
	ldrh r2, [r6, #6]
	strh r2, [r0, #0x1a]
	ldr r0, [r5]
	mul r1, r0
	ldr r0, [sp, #4]
	add r1, r4, r1
	str r0, [r1, #0xc]
	ldr r0, [sp, #8]
	bl PlayerProfile_GetTrainerGender
	ldr r2, [r5]
	mov r1, #0x1c
	mul r1, r2
	add r1, r4, r1
	str r0, [r1, #0x10]
	add r0, r6, #0
	mov r1, #0x57
	bl MailMsg_GetExpandedString
	ldr r2, [r5]
	mov r1, #0x1c
	mul r1, r2
	add r1, r4, r1
	str r0, [r1, #4]
	ldr r0, [r7, #0x10]
	ldr r1, [sp, #4]
	str r0, [sp]
	ldr r0, [sp, #0xc]
	ldr r2, [r7, #0x18]
	ldr r3, [r7, #0x1c]
	bl ov34_0225E2BC
	ldr r2, [r5]
	mov r1, #0x1c
	mul r1, r2
	add r1, r4, r1
	str r0, [r1, #8]
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	mov r0, #0xd3
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	cmp r1, #0x1e
	bne _0225E420
	mov r1, #0
	str r1, [r4, r0]
_0225E420:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225E424: .word 0x000004D8
	thumb_func_end ov34_0225E348


	thumb_func_start ov34_0225E428
ov34_0225E428: ; 0x0225E428
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r0, r1, #0
	str r1, [sp]
	add r7, r2, #0
	bl MailMsg_IsInit
	cmp r0, #0
	bne _0225E43E
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0225E43E:
	mov r1, #0x27
	lsl r1, r1, #4
	ldr r0, [r6, r1]
	add r1, #0xd8
	ldr r1, [r0, r1]
	mov r4, #0
	cmp r1, #0
	ble _0225E478
	add r5, r4, #0
_0225E450:
	add r1, r0, r5
	ldr r0, [r1, #0xc]
	cmp r7, r0
	bne _0225E464
	ldr r0, [sp]
	add r1, #0x14
	bl MailMsg_Compare
	cmp r0, #0
	bne _0225E478
_0225E464:
	mov r0, #0x27
	lsl r0, r0, #4
	mov r1, #0xd2
	ldr r0, [r6, r0]
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	add r4, r4, #1
	add r5, #0x1c
	cmp r4, r1
	blt _0225E450
_0225E478:
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r1, [r6, r0]
	add r0, #0xd8
	ldr r0, [r1, r0]
	cmp r4, r0
	beq _0225E48E
	cmp r0, #0
	beq _0225E48E
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0225E48E:
	mov r0, #0x1c
	mul r0, r4
	add r1, r1, r0
	ldr r0, [r1, #0xc]
	cmp r7, r0
	beq _0225E4A2
	ldr r0, [sp]
	add r1, #0x14
	bl MailMsg_Compare
_0225E4A2:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov34_0225E428


	thumb_func_start ov34_0225E4A8
ov34_0225E4A8: ; 0x0225E4A8
	push {r4, r5, r6, lr}
	add r6, r1, #0
	mov r1, #0xa2
	add r4, r0, #0
	lsl r1, r1, #2
	ldrh r0, [r4, r1]
	sub r1, r1, #4
	ldrh r1, [r4, r1]
	mov r5, #0
	sub r1, r1, #3
	cmp r0, r1
	bne _0225E4C2
	mov r5, #1
_0225E4C2:
	add r1, r3, #0
	add r0, r4, #0
	add r3, r6, #0
	bl ov34_0225E348
	ldr r1, _0225E4F4 ; =0x0000028A
	ldrh r0, [r4, r1]
	cmp r0, #0
	beq _0225E4EA
	cmp r5, #0
	beq _0225E4EA
	add r0, r1, #0
	sub r0, #0x1a
	ldr r2, [r4, r0]
	add r0, r1, #0
	add r0, #0xbe
	ldr r0, [r2, r0]
	sub r2, r0, #3
	sub r0, r1, #2
	strh r2, [r4, r0]
_0225E4EA:
	add r0, r4, #0
	bl ov34_0225E560
	pop {r4, r5, r6, pc}
	nop
_0225E4F4: .word 0x0000028A
	thumb_func_end ov34_0225E4A8


	thumb_func_start ov34_0225E4F8
ov34_0225E4F8: ; 0x0225E4F8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	bl FieldSystem_TaskIsRunning
	cmp r0, #0
	bne _0225E55C
	mov r4, #0
_0225E508:
	add r0, r4, #0
	bl sub_02035754
	add r2, r0, #0
	beq _0225E53A
	add r6, r2, #0
	add r6, #0x50
	add r7, r6, #0
	add r7, #8
	ldr r2, [r2, #0x50]
	add r0, r5, #0
	add r1, r7, #0
	bl ov34_0225E428
	cmp r0, #0
	beq _0225E53A
	add r0, r4, #0
	bl sub_02035798
	add r1, r0, #0
	ldr r3, [r6]
	add r0, r5, #0
	add r2, r7, #0
	bl ov34_0225E4A8
_0225E53A:
	add r4, r4, #1
	cmp r4, #0x10
	blt _0225E508
	ldr r0, [r5, #8]
	bl sub_0205AA84
	add r4, r0, #0
	beq _0225E55C
	ldr r0, [r5, #0x10]
	bl PlayerProfile_GetTrainerID
	add r3, r0, #0
	ldr r1, [r5, #0x10]
	add r0, r5, #0
	add r2, r4, #0
	bl ov34_0225E4A8
_0225E55C:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov34_0225E4F8

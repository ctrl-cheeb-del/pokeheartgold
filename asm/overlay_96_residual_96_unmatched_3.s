	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	.extern PokeathlonCourse_RunSubStateLoop
	.extern PokeathlonCourse_InitStateInfo
	.extern PokeathlonCourse_InitPlayerProfiles
	.extern PokeathlonCourse_GetPlayerProfile
	.extern PokeathlonCourse_GetParticipantCount
	.extern PokeathlonCourse_GetParticipantData
	.extern PokeathlonCourse_GetParticipantUnk04
	.extern PokeathlonCourse_GetSaveData
	.extern PokeathlonCourse_GetFieldData
	.extern PokeathlonCourse_GetFieldData_AtIndex
	.extern PokeathlonCourse_GetFieldBA4
	.extern PokeathlonCourse_AllocPtr4FromHeap
	.extern PokeathlonCourse_FreePtr4HeapAlloc
	.extern PokeathlonCourse_GetHeapAllocPtr4
	.extern PokeathlonCourse_GetHeapID
	.extern PokeathlonCourse_GetField1ED
	.extern PokeathlonCourse_SetField1ED
	.extern PokeathlonCourse_IncrementField1ED
	.extern PokeathlonCourse_SetField1F4
	.extern ov96_021E5E04
	.extern PokeathlonCourse_GetField3D8_ForCurrentParticipant
	.extern PokeathlonCourse_GetField3D8_AtIndex
	.extern ov96_021E5E7C
	.extern PokeathlonCourse_GetCurrentParticipantIndex
	.extern PokeathlonCourse_GetMode
	.extern PokeathlonCourse_GetField1EF
	.extern PokeathlonCourse_IncrementField1EF
	.extern PokeathlonCourse_ResetField1EF
	.extern PokeathlonCourse_GetSystem
	.extern ov96_021E5F24
	.extern PokeathlonCourse_GetPlayerProfileFromData
	.extern PokeathlonCourse_GetField974_AtIndex
	.extern PokeathlonCourse_GetDataCopyArea
	.extern PokeathlonCourse_ResetDataCopyArea
	.extern PokeathlonCourse_SetField3A4
	.extern PokeathlonCourse_ResetField3A4
	.extern PokeathlonCourse_GetField3A4
	.extern PokeathlonCourse_GetUnkConstant4
	.extern PokeathlonCourse_SetField5E0_AtIndex
	.extern PokeathlonCourse_GetField5F0_AtIndex
	.extern PokeathlonCourse_SetStateField07
	.extern PokeathlonCourse_SetStateField07_IfDifferent
	.extern PokeathlonCourse_SetStateTransitionType
	.extern PokeathlonCourse_SetVBlankIntrCB
	.extern PokeathlonCourse_GetGraphicsSystem
	.public ov96_021E60C0
	.public ov96_021E6104
	.public ov96_021E6670
	.public ov96_021E679C
	.public ov96_021E6F18
	.public ov96_021E75B8
	.public ov96_021E7F98
	.public ov96_021E8318
	.public ov96_021E87B0
	.public ov96_021E8828
	.public ov96_021E8A20
	.public ov96_021E8A24
	.public ov96_021E8A2C
	.public ov96_021E8A30
	.public ov96_021E8B88
	.public ov96_021E8BAC
	.public ov96_021E8BB0
	.public ov96_021E90FC
	.public ov96_021E92AC
	.public ov96_021E92D0
	.public ov96_021E9510
	.public ov96_021E9524
	.public ov96_021E9528
	.public ov96_021E99F4
	.public ov96_021E99F8
	.public ov96_021E99FC
	.public ov96_021E9A04
	.public ov96_021E9A10
	.public ov96_021E9A14
	.public ov96_021E9A18
	.public ov96_021E9A1C
	.public ov96_021E9A24
	.public ov96_021E9A2C
	.public ov96_021E9A38
	.public ov96_021E9A48
	.public ov96_021E9A54
	.public ov96_021E9A68
	.public ov96_021E9CF4
	.public ov96_021E9D08
	.public ov96_021EA894
	.public ov96_021EAA00
	.public ov96_021EAA20
	.public ov96_021EAB94
	.public ov96_021EABDC
	.public ov96_021EABE0
	.public ov96_021EABF4
	.public ov96_021EAC08
	.public ov96_021EAD78
	.public ov96_021EAEC8
	.public ov96_021EAF6C
	.public ov96_021EAF70
	.public ov96_021EAF8C
	.public ov96_021EAF90
	.public ov96_021EB10C
	.public ov96_021EB138
	.public ov96_021EB564
	.public ov96_021EB570
	.public ov96_021EB57C
	.public ov96_021EB588
	.public ov96_021EB594
	.public ov96_021EB5A0
	.public ov96_021EB5AC
	.public ov96_021EB5B8
	.public ov96_021EB5BC
	.public ov96_021EB5E8
	.public ov96_021EB630
	.public ov96_021EB678
	.public ov96_021EB680
	.public ov96_021EB688
	.public ov96_021EB690
	.public ov96_021EB698
	.public ov96_021EB6A0
	.public ov96_021EC2E0
	.public ov96_021ECBF4
	.public ov96_021ECC38
	.public ov96_021ECC4C
	.public ov96_021ECDC4
	.public ov96_021ECDD4
	.public ov96_021ED47C
	.public ov96_021ED6E8
	.public ov96_021ED748
	.public ov96_021ED74C
	.public ov96_021ED750
	.public ov96_021EDF7C
	.public ov96_021EEA80
	.public ov96_021EED64
	.public ov96_021EEEBC
	.public ov96_021EEEC0
	.public ov96_021EEF98
	.public ov96_021EF18C
	.public ov96_021EF2A0
	.public ov96_021EF2AC
	.public ov96_021EF98C
	.public ov96_021EFA28
	.public ov96_021EFB50
	.public ov96_021F08E4
	.public ov96_021F27A8
	.public ov96_021F30BC
	.public ov96_021F3424
	.public ov96_021F3E58
	.public ov96_021F46B4
	.public ov96_021F54C0
	.public ov96_021F74C8
	.public ov96_021F75D4
	.public ov96_021F75E0
	.public ov96_021F7738
	.public ov96_021F8094
	.public ov96_021F81C0
	.public ov96_021F8354
	.public ov96_021F83BC
	.public ov96_021F83D0
	.public ov96_021F87D0
	.public ov96_021F893C
	.public ov96_021F8948
	.public ov96_021F8978
	.public ov96_021F9234
	.public ov96_021FA340
	.public ov96_021FBE3C
	.public ov96_021FBE44
	.public ov96_021FBE4C
	.public ov96_021FBE9C
	.public ov96_021FBEA0
	.public ov96_021FC0D0
	.public ov96_021FC0E4
	.public ov96_021FC0E8
	.public ov96_021FC0F4
	.public ov96_021FC314
	.public ov96_021FC690
	.public ov96_021FCD74
	.public ov96_021FDE6C
	.public ov96_021FE538
	.public ov96_02200BC8
	.public ov96_02200E78
	.public ov96_02200EEC
	.public ov96_02203BC0
	.public ov96_02203CC4
	.public ov96_02203CD4
	.public ov96_022043AC
	.public ov96_022043B8
	.public ov96_02204DE8
	.public ov96_02206368
	.public ov96_02207400
	.public ov96_022077F4
	.public ov96_02207BD4
	.public ov96_02207BD8
	.public ov96_02208AE8
	.public ov96_02208AF0
	.public ov96_02208B2C
	.public ov96_02209738
	.public ov96_0220AD4C
	.public ov96_0220B730
	.public ov96_0220B774
	.public ov96_0220B788
	.public ov96_0220C998
	.public ov96_0220D408
	.public ov96_0220D420
	.public ov96_0220E850
	.public ov96_0220E888
	.public ov96_0220E960
	.public ov96_0220F3B4
	.public ov96_0220FF64
	.public ov96_0221022C
	.public ov96_0221031C
	.public ov96_022104C4
	.public ov96_02210850
	.public ov96_02211650
	.public ov96_02213354
	.public ov96_02214904
	.public ov96_02214B74
	.public ov96_02214B7C
	.public ov96_02215864
	.public ov96_0221587C
	.public ov96_022158D4
	.public ov96_02215944
	.public ov96_02215DBC
	.public ov96_02215FA0
	.public ov96_02217890
	.public ov96_02217DBC
	.public ov96_022186B8
	.public ov96_02218A50
	.public ov96_022193E4
	.public ov96_0221978C
	.public ov96_02219FDC
	.public ov96_0221A670
	.public ov96_0221A680
	.public ov96_0221A690
	.public ov96_0221A69C
	.public ov96_0221A720

	.public ov96_0220B79C
	.public ov96_0220B7B4
	.public ov96_0220B7CC
	.public ov96_0220B7F4
	.public ov96_0220B8A0
	.public ov96_0220B8D8
	.public ov96_0220B8F0
	.public ov96_0220B940
	.public ov96_0220B95C
	.public ov96_0220B988
	.public ov96_0220B9A8
	.public ov96_0220BD38
	.public ov96_0220BE28
	.public ov96_0220BFB4
	.public ov96_0220C004
	.public ov96_0220C0DC
	.public ov96_0220C15C
	.public ov96_0220C3E0
	.public ov96_0220C40C
	.public ov96_0220C490
	.public ov96_0220C54C
	.public ov96_0220C578
	.public ov96_0220C680
	.public ov96_0220C714
	.public ov96_0220C768
	.public ov96_0220C7C4
	.public ov96_0220C7FC
	.public ov96_0220C844
	.public ov96_0220C8B8
	.public ov96_0220C90C
	.public ov96_0220C93C



	thumb_func_start ov96_0220C15C
ov96_0220C15C: ; 0x0220C15C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r1, #0
	ldr r1, [r4, #0x38]
	lsl r2, r1, #0x1a
	lsr r2, r2, #0x1c
	cmp r2, #6
	bls _0220C16E
	b _0220C3CA
_0220C16E:
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0220C17A: ; jump table
	.short _0220C188 - _0220C17A - 2 ; case 0
	.short _0220C1B2 - _0220C17A - 2 ; case 1
	.short _0220C216 - _0220C17A - 2 ; case 2
	.short _0220C274 - _0220C17A - 2 ; case 3
	.short _0220C2B2 - _0220C17A - 2 ; case 4
	.short _0220C33E - _0220C17A - 2 ; case 5
	.short _0220C3B6 - _0220C17A - 2 ; case 6
_0220C188:
	ldr r5, [r4, #0x2c]
	add r0, r5, #0
	bl ManagedSprite_ResetSpriteAnimCtrlState
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r2, [r4, #0x38]
	mov r1, #0x3c
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x1a
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C1B2:
	ldr r0, _0220C3D4 ; =0xFFFFC03F
	and r0, r1
	lsl r1, r1, #0x12
	lsr r1, r1, #0x18
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x12
	orr r1, r0
	lsl r0, r1, #0x12
	lsr r0, r0, #0x18
	str r1, [r4, #0x38]
	cmp r0, #2
	blo _0220C294
	lsl r0, r1, #7
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r5, [r4, #0x30]
	ldr r0, [r0, #4]
	mov r1, #0
	bl ov96_021EAB38
	add r0, r5, #0
	mov r1, #0x1b
	bl ManagedSprite_SetAnim
	add r0, r5, #0
	mov r1, #0
	bl ManagedSprite_SetAnimateFlag
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r1, [r4, #0x38]
	ldr r0, _0220C3D4 ; =0xFFFFC03F
	add r2, r1, #0
	and r2, r0
	mov r0, #0x3c
	add r1, r2, #0
	bic r1, r0
	lsl r0, r2, #0x1a
	lsr r0, r0, #0x1c
	add r0, r0, #1
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C216:
	add r1, sp, #4
	ldr r0, [r4, #0x30]
	add r1, #2
	add r2, sp, #4
	bl ManagedSprite_GetPositionXY
	mov r3, #4
	add r1, sp, #0
	add r0, r3, #0
	ldrsh r5, [r1, r3]
	sub r0, #0x44
	sub r2, r0, r5
	asr r0, r2, #1
	lsr r0, r0, #0x1e
	add r0, r2, r0
	lsl r0, r0, #0xe
	asr r2, r0, #0x10
	add r0, r3, #0
	sub r0, #0x44
	cmp r5, r0
	ble _0220C244
	cmp r2, #0
	bne _0220C25E
_0220C244:
	ldr r2, [r4, #0x38]
	mov r1, #0x3c
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x1a
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C25E:
	ldr r0, [r4, #0x30]
	mov r4, #6
	add r2, r5, r2
	lsl r2, r2, #0x10
	ldrsh r1, [r1, r4]
	asr r2, r2, #0x10
	lsl r3, r3, #0x12
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add sp, #8
	pop {r3, r4, r5, pc}
_0220C274:
	add r0, r1, #0
	lsl r1, r1, #0x12
	lsr r1, r1, #0x18
	ldr r3, _0220C3D4 ; =0xFFFFC03F
	add r1, r1, #1
	lsl r1, r1, #0x18
	and r0, r3
	lsr r1, r1, #0x12
	orr r0, r1
	str r0, [r4, #0x38]
	lsl r0, r0, #0x12
	add r2, r4, #0
	lsr r0, r0, #0x18
	add r2, #0x38
	cmp r0, #4
	bhs _0220C296
_0220C294:
	b _0220C3CE
_0220C296:
	ldr r0, [r2]
	add sp, #8
	and r3, r0
	mov r0, #0x3c
	add r1, r3, #0
	bic r1, r0
	lsl r0, r3, #0x1a
	lsr r0, r0, #0x1c
	add r0, r0, #1
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1a
	orr r0, r1
	str r0, [r2]
	pop {r3, r4, r5, pc}
_0220C2B2:
	add r1, sp, #0
	ldr r0, [r4, #0x30]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	add r1, sp, #0
	mov r0, #0
	ldrsh r1, [r1, r0]
	sub r0, #0x18
	sub r0, r0, r1
	bpl _0220C2CC
	neg r0, r0
_0220C2CC:
	lsl r0, r0, #0x10
	asr r1, r0, #0x10
	beq _0220C2DA
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0xf
	asr r1, r0, #0x10
_0220C2DA:
	add r5, sp, #0
	mov r0, #0
	ldrsh r2, [r5, r0]
	add r1, r1, #2
	add r1, r2, r1
	strh r1, [r5]
	ldrsh r2, [r5, r0]
	cmp r2, #0x30
	blt _0220C32E
	ldr r0, [r4, #0x38]
	mov r2, #0x30
	lsl r0, r0, #3
	lsr r0, r0, #0x1e
	lsl r0, r0, #6
	add r0, #0x48
	strh r0, [r5, #2]
	strh r2, [r5]
	mov r1, #2
	ldrsh r1, [r5, r1]
	ldr r0, [r4, #0x30]
	bl ManagedSprite_SetPositionXY
	ldr r0, [r4, #0x30]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [r4, #0x2c]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r2, [r4, #0x38]
	mov r1, #0x3c
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x1a
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C32E:
	mov r3, #2
	ldrsh r1, [r5, r3]
	ldr r0, [r4, #0x30]
	lsl r3, r3, #0x13
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add sp, #8
	pop {r3, r4, r5, pc}
_0220C33E:
	ldr r0, _0220C3D4 ; =0xFFFFC03F
	and r0, r1
	lsl r1, r1, #0x12
	lsr r1, r1, #0x18
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x12
	orr r0, r1
	str r0, [r4, #0x38]
	lsl r0, r0, #0x12
	lsr r0, r0, #0x18
	cmp r0, #2
	blo _0220C3CE
	ldr r0, [r4, #0x30]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x38]
	mov r1, #1
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #4]
	bl ov96_021EAB38
	ldr r0, [r4, #0x38]
	mov r1, #0
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #4]
	bl ov96_021EAB74
	ldr r1, [r4, #0x38]
	ldr r0, _0220C3D8 ; =0xFE7FFFFF
	add r2, r1, #0
	and r2, r0
	lsl r0, r1, #0x1e
	lsr r0, r0, #0x1e
	lsl r0, r0, #0x1e
	lsr r0, r0, #7
	add r1, r2, #0
	orr r1, r0
	ldr r0, _0220C3D4 ; =0xFFFFC03F
	add r2, r1, #0
	and r2, r0
	mov r0, #0x3c
	add r1, r2, #0
	bic r1, r0
	lsl r0, r2, #0x1a
	lsr r0, r0, #0x1c
	add r0, r0, #1
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C3B6:
	mov r1, #0
	str r1, [r4, #0x34]
	ldr r2, [r4, #0x38]
	ldr r1, _0220C3DC ; =0xFFFFBFFF
	and r1, r2
	str r1, [r4, #0x38]
	bl SysTask_Destroy
	add sp, #8
	pop {r3, r4, r5, pc}
_0220C3CA:
	bl GF_AssertFail
_0220C3CE:
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_0220C3D4: .word 0xFFFFC03F
_0220C3D8: .word 0xFE7FFFFF
_0220C3DC: .word 0xFFFFBFFF
	thumb_func_end ov96_0220C15C

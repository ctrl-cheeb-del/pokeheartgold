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


	thumb_func_start ov96_0220AAEC
ov96_0220AAEC: ; 0x0220AAEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	mov r0, #0
	str r1, [sp, #4]
	add r6, r2, #0
	add r4, r3, #0
	str r0, [sp, #8]
	cmp r5, #0
	bne _0220AB04
	bl GF_AssertFail
_0220AB04:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	bne _0220AB16
	add sp, #0x24
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_0220AB16:
	add r0, sp, #0x20
	add r1, sp, #0x1c
	bl System_GetTouchNewCoords
	ldr r1, [sp, #0x20]
	ldr r2, [sp, #0x1c]
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r5, #0xc]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	mov r7, #7
	bl ManagedSprite_SetPositionXY
	cmp r4, #0
	bne _0220AB3C
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _0220AB3E
_0220AB3C:
	mov r7, #0x12
_0220AB3E:
	ldr r0, [r5, #0xc]
	add r1, r7, #0
	bl ManagedSprite_SetAnim
	ldr r0, [r5, #0xc]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _0220AB62
	add r6, #0x96
	lsl r0, r6, #0x10
	asr r6, r0, #0x10
	ldr r0, _0220AD24 ; =0x000008BB
	bl PlaySE
	b _0220AB72
_0220AB62:
	cmp r4, #0
	beq _0220AB72
	add r6, #0xa0
	lsl r0, r6, #0x10
	asr r6, r0, #0x10
	ldr r0, _0220AD24 ; =0x000008BB
	bl PlaySE
_0220AB72:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r7, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	str r0, [sp, #0xc]
	cmp r0, #0
	ble _0220AC6A
	add r0, r5, #0
	str r0, [sp, #0x10]
	add r0, #0x14
	str r0, [sp, #0x10]
	mov r0, #0xf0
	str r0, [sp, #0x14]
_0220AB90:
	ldr r0, [sp, #0xc]
	add r1, r7, #1
	sub r0, r0, r1
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r4, [r1, r0]
	cmp r6, #0
	ble _0220AC6A
	mov r0, #8
	ldrsh r0, [r4, r0]
	sub r0, r0, r6
	strh r0, [r4, #8]
	mov r0, #8
	ldrsh r0, [r4, r0]
	cmp r0, #0
	bgt _0220AC6A
	bgt _0220AC62
	mov r0, #6
	lsl r0, r0, #6
	ldr r2, [r5, r0]
	ldr r1, [sp, #0x14]
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x1c
	sub r1, r1, #1
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x18
	orr r1, r0
	mov r0, #6
	lsl r0, r0, #6
	str r1, [r5, r0]
	sub r0, r0, #4
	ldr r1, [r5, r0]
	lsl r0, r1, #0x10
	lsr r1, r1, #0x10
	add r1, r1, #1
	lsr r0, r0, #0x10
	lsl r1, r1, #0x10
	orr r1, r0
	mov r0, #0x5f
	lsl r0, r0, #2
	str r1, [r5, r0]
	ldr r0, [r5, r0]
	lsr r0, r0, #0x10
	cmp r0, #0xc8
	bls _0220AC08
	mov r0, #0x5f
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	mov r0, #0x32
	lsl r0, r0, #0x12
	orr r1, r0
	mov r0, #0x5f
	lsl r0, r0, #2
	str r1, [r5, r0]
_0220AC08:
	ldr r0, [r4]
	mov r1, #0
	bl ManagedSprite_SetAnim
	add r1, sp, #0x18
	ldr r0, [r4]
	add r1, #2
	add r2, sp, #0x18
	bl ManagedSprite_GetPositionXY
	ldr r0, [r4, #4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #8
	ldrsh r0, [r4, r0]
	add r3, sp, #0x18
	mov r2, #2
	neg r0, r0
	lsl r0, r0, #0x10
	asr r6, r0, #0x10
	ldr r0, [sp, #8]
	ldrsh r2, [r3, r2]
	add r4, r3, #0
	mov r3, #0
	add r0, r0, #1
	str r0, [sp, #8]
	ldrsh r3, [r4, r3]
	ldr r0, [sp, #0x10]
	mov r1, #4
	bl ov96_0220B1D8
	ldr r0, [r5]
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldr r0, [r5]
	ldr r2, [sp, #4]
	lsr r1, r1, #0x18
	mov r3, #3
	bl ov96_021E8228
_0220AC62:
	ldr r0, [sp, #0xc]
	add r7, r7, #1
	cmp r7, r0
	blt _0220AB90
_0220AC6A:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _0220AC78
	ldr r0, _0220AD28 ; =0x000008B9
	bl PlaySE
	b _0220ACA0
_0220AC78:
	ldr r0, _0220AD2C ; =0x000008B8
	bl PlaySE
	ldr r1, [sp, #0x20]
	ldr r2, [sp, #0x1c]
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r5, #0x10]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	ldr r0, [r5, #0x10]
	mov r1, #6
	bl ManagedSprite_SetAnim
	ldr r0, [r5, #0x10]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
_0220ACA0:
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _0220ACFC
	mov r0, #6
	lsl r0, r0, #6
	ldr r1, [r5, r0]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	beq _0220ACFC
	lsl r1, r1, #2
	add r1, r5, r1
	sub r0, #0x30
	ldr r1, [r1, r0]
	mov r0, #8
	ldrsh r0, [r1, r0]
	cmp r0, #0x14
	bgt _0220ACCC
	ldr r0, [r1]
	mov r1, #3
	bl ManagedSprite_SetAnim
	b _0220ACFC
_0220ACCC:
	cmp r0, #0x3c
	bgt _0220ACFC
	ldr r0, [r1]
	mov r1, #2
	bl ManagedSprite_SetAnim
	ldr r0, _0220AD2C ; =0x000008B8
	bl PlaySE
	bl LCRandom
	add r2, r0, #0
	lsr r4, r2, #0x1f
	lsl r3, r2, #0x19
	sub r3, r3, r4
	mov r2, #0x19
	ror r3, r2
	ldr r0, _0220AD2C ; =0x000008B8
	ldr r1, _0220AD30 ; =0x0000FFFF
	add r3, r4, r3
	mov r2, #0x40
	sub r2, r2, r3
	bl sub_0200592C
_0220ACFC:
	ldr r0, [sp, #8]
	cmp r0, #0
	ble _0220AD12
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	bne _0220AD12
	mov r1, #1
	b _0220AD14
_0220AD12:
	mov r1, #0
_0220AD14:
	ldr r0, [sp, #0x3c]
	str r1, [r0]
	ldr r0, [sp, #8]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_0220AD24: .word 0x000008BB
_0220AD28: .word 0x000008B9
_0220AD2C: .word 0x000008B8
_0220AD30: .word 0x0000FFFF
	thumb_func_end ov96_0220AAEC

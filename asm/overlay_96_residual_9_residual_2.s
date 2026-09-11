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
	.public ov96_021E8324
	.public ov96_021E839C
	.public ov96_021E86FC
	.public ov96_021E8770
	.public ov96_021E8424
	.public ov96_021E8448
	.public ov96_021E860C




	thumb_func_start ov96_021E8484
ov96_021E8484: ; 0x021E8484
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	str r0, [sp]
	add r4, r1, #0
	bl PokeathlonCourse_GetHeapID
	add r3, r0, #0
	ldr r2, _021E8608 ; =0x00000136
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	str r0, [sp, #0x14]
	mov r0, #4
	sub r0, r0, r4
	str r0, [sp, #4]
	mov r1, #0x7e
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r2, [r0, r1]
	add r0, r4, #0
	ldrb r1, [r2, #0xc]
	ldrb r2, [r2, #0xf]
	add r3, sp, #0x2c
	bl ov96_021E860C
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapID
	add r1, r0, #0
	mov r0, #0xa9
	bl NARC_New
	str r0, [sp, #0x10]
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapID
	add r1, r0, #0
	mov r0, #0x41
	lsl r0, r0, #2
	bl NARC_New
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x1c]
	ldr r0, [sp, #4]
	cmp r0, #4
	bge _021E84E6
	blt _021E84E8
_021E84E6:
	b _021E85F0
_021E84E8:
	add r0, sp, #0x2c
	str r0, [sp, #8]
_021E84EC:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl PokeathlonCourse_GetParticipantData
	add r5, r0, #0
	ldr r0, [sp, #8]
	ldrb r0, [r0]
	str r0, [r5]
	cmp r0, #0
	bne _021E8504
	bl GF_AssertFail
_021E8504:
	ldr r1, [r5]
	ldr r0, [sp, #0xc]
	sub r1, r1, #1
	add r2, sp, #0x24
	bl NARC_ReadWholeMember
	add r1, sp, #0x24
	ldrb r1, [r1, #6]
	ldr r0, [sp, #0x14]
	bl NewString_ReadMsgData
	add r4, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl PokeathlonCourse_GetPlayerProfileFromData
	add r6, r0, #0
	add r0, r4, #0
	bl String_cstr
	add r1, r0, #0
	add r0, r6, #0
	bl Save_Profile_PlayerName_Set
	add r0, r4, #0
	bl String_Delete
	mov r0, #0
	add r6, r5, #0
	str r0, [sp, #0x18]
	add r4, sp, #0x24
	add r6, #0x16
	add r7, sp, #0x24
_021E8546:
	ldrh r0, [r4]
	mov r1, #0x12
	strh r0, [r5, #4]
	mov r0, #0
	strh r0, [r5, #6]
	strb r0, [r5, #0x14]
	str r0, [r5, #8]
	ldrh r0, [r5, #4]
	bl GetMonBaseStat
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _021E856A
	cmp r0, #0xfe
	beq _021E856E
	cmp r0, #0xff
	beq _021E8572
	b _021E8576
_021E856A:
	mov r0, #0
	b _021E8578
_021E856E:
	mov r0, #1
	b _021E8578
_021E8572:
	mov r0, #2
	b _021E8578
_021E8576:
	mov r0, #0
_021E8578:
	strb r0, [r5, #0x15]
	ldrh r0, [r5, #4]
	mov r1, #0
	bl ov96_021E679C
	add r1, r0, #0
	add r2, sp, #0x2c
	ldr r0, [sp, #0x10]
	add r2, #3
	bl NARC_ReadWholeMember
	ldrb r0, [r7, #0xb]
	strb r0, [r5, #0xc]
	ldrb r0, [r7, #0xc]
	strb r0, [r5, #0xd]
	ldrb r0, [r7, #0xd]
	strb r0, [r5, #0xe]
	ldrb r0, [r7, #0xe]
	strb r0, [r5, #0xf]
	ldrb r0, [r7, #0xf]
	strb r0, [r5, #0x10]
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapID
	add r1, r0, #0
	ldrh r0, [r4]
	bl GetSpeciesName
	str r0, [sp, #0x20]
	bl String_cstr
	add r1, r0, #0
	add r0, r6, #0
	mov r2, #0xb
	bl CopyU16StringArrayN
	ldr r0, [sp, #0x20]
	bl String_Delete
	ldr r0, [sp, #0x18]
	add r4, r4, #2
	add r0, r0, #1
	add r5, #0x28
	add r6, #0x28
	str r0, [sp, #0x18]
	cmp r0, #3
	blt _021E8546
	ldr r0, [sp, #4]
	add r0, r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #4]
	cmp r0, #4
	bge _021E85F0
	b _021E84EC
_021E85F0:
	ldr r0, [sp, #0xc]
	bl NARC_Delete
	ldr r0, [sp, #0x10]
	bl NARC_Delete
	ldr r0, [sp, #0x14]
	bl DestroyMsgData
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_021E8608: .word 0x00000136
	thumb_func_end ov96_021E8484

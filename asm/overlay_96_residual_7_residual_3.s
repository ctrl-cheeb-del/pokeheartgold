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
	.public ov96_021E75BC
	.public ov96_021E7C94
	.public ov96_021E7D18
	.public ov96_021E7D30


	thumb_func_start ov96_021E7D6C
ov96_021E7D6C: ; 0x021E7D6C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	str r1, [sp]
	ldr r1, _021E7F3C ; =0x0000072C
	add r5, r0, #0
	add r7, r5, r1
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, _021E7F40 ; =0x0098967F
	ldr r0, [r0, #4]
	cmp r0, #1
	bne _021E7DCE
	ldr r2, [sp]
	mov r0, #1
	add r2, #0x38
	bl ov96_021E7F98
	mov r0, #0x1d
	lsl r0, r0, #4
	ldrh r0, [r7, r0]
	lsl r1, r0, #0x1f
	lsr r1, r1, #0x1f
	beq _021E7DBA
	ldr r2, [sp]
	ldr r1, _021E7F40 ; =0x0098967F
	mov r0, #1
	add r2, #0x3c
	bl ov96_021E7F98
	add r0, r5, #0
	bl ov96_021E7F48
	b _021E7E0A
_021E7DBA:
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	beq _021E7E0A
	ldr r2, [sp]
	ldr r1, _021E7F40 ; =0x0098967F
	mov r0, #1
	add r2, #0x40
	bl ov96_021E7F98
	b _021E7E0A
_021E7DCE:
	ldr r2, [sp]
	mov r0, #1
	add r2, r2, #4
	bl ov96_021E7F98
	mov r0, #0x1d
	lsl r0, r0, #4
	ldrh r0, [r7, r0]
	lsl r1, r0, #0x1f
	lsr r1, r1, #0x1f
	beq _021E7DF8
	ldr r2, [sp]
	ldr r1, _021E7F40 ; =0x0098967F
	mov r0, #1
	add r2, #8
	bl ov96_021E7F98
	add r0, r5, #0
	bl ov96_021E7F48
	b _021E7E0A
_021E7DF8:
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	beq _021E7E0A
	ldr r2, [sp]
	ldr r1, _021E7F40 ; =0x0098967F
	mov r0, #1
	add r2, #0xc
	bl ov96_021E7F98
_021E7E0A:
	ldr r0, _021E7F44 ; =0x0000072A
	mov r4, #0
	ldrb r0, [r5, r0]
	cmp r0, #0
	bls _021E7E68
	ldr r0, [sp]
	ldr r6, [sp]
	str r0, [sp, #0xc]
	add r0, #0x6c
	str r0, [sp, #0xc]
	add r6, #0x44
_021E7E20:
	mov r1, #0x72
	add r0, r7, r4
	lsl r1, r1, #2
	ldrb r1, [r0, r1]
	cmp r1, #0
	beq _021E7E46
	lsl r2, r4, #2
	add r3, r5, r2
	mov r2, #0xf6
	lsl r2, r2, #2
	ldr r2, [r3, r2]
	ldr r1, _021E7F40 ; =0x0098967F
	lsl r2, r2, #0x18
	lsr r2, r2, #0x16
	mov r0, #1
	add r2, r6, r2
	bl ov96_021E7F98
	b _021E7E5A
_021E7E46:
	mov r1, #0x73
	lsl r1, r1, #2
	ldrb r0, [r0, r1]
	cmp r0, #0
	beq _021E7E5A
	ldr r1, _021E7F40 ; =0x0098967F
	ldr r2, [sp, #0xc]
	mov r0, #1
	bl ov96_021E7F98
_021E7E5A:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, _021E7F44 ; =0x0000072A
	ldrb r0, [r5, r0]
	cmp r4, r0
	blo _021E7E20
_021E7E68:
	ldr r0, [sp, #8]
	mov r1, #0x60
	mul r1, r0
	add r0, r7, r1
	str r0, [sp, #4]
	ldr r0, [sp]
	ldr r4, _021E7F40 ; =0x0098967F
	str r0, [sp, #0x10]
	add r0, #0x18
	str r0, [sp, #0x10]
	ldr r0, [sp]
	mov r6, #0
	str r0, [sp, #0x14]
	add r0, #0x1c
	str r0, [sp, #0x14]
	ldr r0, [sp]
	str r0, [sp, #0x18]
	add r0, #0x20
	str r0, [sp, #0x18]
	ldr r0, [sp]
	str r0, [sp, #0x1c]
	add r0, #0x24
	str r0, [sp, #0x1c]
	ldr r0, [sp]
	str r0, [sp, #0x20]
	add r0, #0x28
	str r0, [sp, #0x20]
	ldr r0, [sp]
	str r0, [sp, #0x24]
	add r0, #0x2c
	str r0, [sp, #0x24]
	ldr r0, [sp]
	str r0, [sp, #0x28]
	add r0, #0x30
	str r0, [sp, #0x28]
	ldr r0, [sp]
	str r0, [sp, #0x2c]
	add r0, #0x34
	str r0, [sp, #0x2c]
_021E7EB6:
	ldr r0, [sp, #4]
	lsl r1, r6, #5
	add r5, r0, r1
	ldr r0, [r0, r1]
	ldr r2, [sp, #0x10]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #4]
	ldr r2, [sp, #0x14]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #8]
	ldr r2, [sp, #0x18]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0xc]
	ldr r2, [sp, #0x1c]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0x10]
	ldr r2, [sp, #0x20]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0x14]
	ldr r2, [sp, #0x24]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0x18]
	ldr r2, [sp, #0x28]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0x1c]
	ldr r2, [sp, #0x2c]
	add r1, r4, #0
	bl ov96_021E7F98
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #3
	blo _021E7EB6
	mov r0, #6
	lsl r0, r0, #6
	ldr r2, [sp]
	ldr r0, [r7, r0]
	ldr r1, _021E7F40 ; =0x0098967F
	add r2, #0x10
	bl ov96_021E7F98
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r2, [sp]
	ldr r0, [r7, r0]
	add r2, #0x14
	ldr r1, _021E7F40 ; =0x0098967F
	str r2, [sp]
	bl ov96_021E7F98
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7F3C: .word 0x0000072C
_021E7F40: .word 0x0098967F
_021E7F44: .word 0x0000072A
	thumb_func_end ov96_021E7D6C




	thumb_func_start ov96_021E7F48
ov96_021E7F48: ; 0x021E7F48
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0]
	bl Save_Pokeathlon_FriendshipRecords_Get
	add r4, r0, #0
	add r0, r5, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	mov r0, #0x3f
	lsl r0, r0, #4
	add r1, r5, r0
	mov r0, #0x7c
	mul r0, r2
	add r3, r1, r0
	mov r2, #0
	mov r5, #0x28
_021E7F74:
	add r6, r2, #0
	mul r6, r5
	add r1, r3, r6
	ldrh r6, [r3, r6]
	lsl r7, r2, #2
	add r0, r4, r7
	strh r6, [r4, r7]
	ldrh r6, [r1, #2]
	strb r6, [r0, #3]
	ldrb r1, [r1, #0x11]
	strb r1, [r0, #2]
	add r0, r2, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r2, #3
	blo _021E7F74
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E7F48

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

	thumb_func_start ov96_021ED754
ov96_021ED754: ; 0x021ED754
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r6, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r5, #0
	bne _021ED76E
	bl GF_AssertFail
_021ED76E:
	cmp r6, #0
	bne _021ED776
	bl GF_AssertFail
_021ED776:
	cmp r4, #0
	bne _021ED77E
	bl GF_AssertFail
_021ED77E:
	ldr r0, [r4, #4]
	lsl r0, r0, #5
	lsr r0, r0, #0x14
	bl MATH_CountPopulation
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021ED754


	thumb_func_start ov96_021ED78C
ov96_021ED78C: ; 0x021ED78C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r6, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r5, #0
	bne _021ED7A6
	bl GF_AssertFail
_021ED7A6:
	cmp r6, #0
	bne _021ED7AE
	bl GF_AssertFail
_021ED7AE:
	cmp r4, #0
	bne _021ED7B6
	bl GF_AssertFail
_021ED7B6:
	ldr r0, [r4, #8]
	lsl r0, r0, #4
	lsr r0, r0, #0x14
	bl MATH_CountPopulation
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021ED78C


	thumb_func_start ov96_021ED7C4
ov96_021ED7C4: ; 0x021ED7C4
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r6, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r5, #0
	bne _021ED7DE
	bl GF_AssertFail
_021ED7DE:
	cmp r6, #0
	bne _021ED7E6
	bl GF_AssertFail
_021ED7E6:
	cmp r4, #0
	bne _021ED7EE
	bl GF_AssertFail
_021ED7EE:
	ldr r0, [r4, #4]
	lsl r0, r0, #0x11
	lsr r0, r0, #0x14
	bl MATH_CountPopulation
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021ED7C4


	thumb_func_start ov96_021ED7FC
ov96_021ED7FC: ; 0x021ED7FC
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r5, r1, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r7, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r6, #0
	bne _021ED818
	bl GF_AssertFail
_021ED818:
	cmp r7, #0
	bne _021ED820
	bl GF_AssertFail
_021ED820:
	cmp r4, #0
	bne _021ED828
	bl GF_AssertFail
_021ED828:
	mov r1, #0
_021ED82A:
	add r0, r4, r1
	ldrb r0, [r0, #0xd]
	strb r0, [r5, r1]
	add r1, r1, #1
	cmp r1, #4
	blt _021ED82A
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021ED7FC


	thumb_func_start ov96_021ED838
ov96_021ED838: ; 0x021ED838
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r7, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r5, #0
	bne _021ED854
	bl GF_AssertFail
_021ED854:
	cmp r7, #0
	bne _021ED85C
	bl GF_AssertFail
_021ED85C:
	cmp r4, #0
	bne _021ED864
	bl GF_AssertFail
_021ED864:
	lsl r0, r6, #3
	ldr r0, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021ED838


	thumb_func_start ov96_021ED86C
ov96_021ED86C: ; 0x021ED86C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r7, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r5, #0
	bne _021ED888
	bl GF_AssertFail
_021ED888:
	cmp r7, #0
	bne _021ED890
	bl GF_AssertFail
_021ED890:
	cmp r4, #0
	bne _021ED898
	bl GF_AssertFail
_021ED898:
	lsl r0, r6, #3
	add r0, r4, r0
	ldr r0, [r0, #4]
	lsl r0, r0, #8
	lsr r0, r0, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021ED86C


	thumb_func_start ov96_021ED8A4
ov96_021ED8A4: ; 0x021ED8A4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r7, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r5, #0
	bne _021ED8C0
	bl GF_AssertFail
_021ED8C0:
	cmp r7, #0
	bne _021ED8C8
	bl GF_AssertFail
_021ED8C8:
	cmp r4, #0
	bne _021ED8D0
	bl GF_AssertFail
_021ED8D0:
	lsl r0, r6, #3
	add r0, r4, r0
	ldr r0, [r0, #4]
	lsr r0, r0, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021ED8A4


	thumb_func_start ov96_021ED8DC
ov96_021ED8DC: ; 0x021ED8DC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0x28
	bl ov96_021E8A20
	add r4, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetMode
	cmp r0, #0
	bne _021ED922
	mov r6, #0
_021ED8F8:
	add r0, r5, #0
	bl ov96_021E5F24
	cmp r6, r0
	bne _021ED90C
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_021EE0AC
	b _021ED918
_021ED90C:
	lsl r2, r6, #0x18
	add r0, r4, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	bl ov96_021EE1D8
_021ED918:
	add r6, r6, #1
	add r4, #8
	cmp r6, #4
	blt _021ED8F8
	pop {r4, r5, r6, pc}
_021ED922:
	mov r6, #0
_021ED924:
	add r0, r5, #0
	bl PokeathlonCourse_GetParticipantCount
	cmp r0, r6
	ble _021ED93C
	lsl r2, r6, #0x18
	add r0, r4, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	bl ov96_021EE144
	b _021ED948
_021ED93C:
	lsl r2, r6, #0x18
	add r0, r4, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	bl ov96_021EE1D8
_021ED948:
	add r6, r6, #1
	add r4, #8
	cmp r6, #4
	blt _021ED924
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021ED8DC


	thumb_func_start ov96_021ED954
ov96_021ED954: ; 0x021ED954
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r0, #0
	add r5, r1, #0
	mov r6, #0x4b
	bl PokeathlonCourse_GetHeapID
	add r1, r0, #0
	mov r0, #0xa9
	bl NARC_New
	str r0, [sp]
	add r0, r4, #0
	add r1, r5, #0
	bl PokeathlonCourse_GetParticipantUnk04
	add r5, r0, #0
	mov r7, #0
	add r4, sp, #4
_021ED97A:
	ldrh r0, [r5]
	ldrh r1, [r5, #2]
	bl ov96_021E679C
	add r1, r0, #0
	ldr r0, [sp]
	add r2, sp, #4
	bl NARC_ReadWholeMember
	ldrb r0, [r4]
	add r7, r7, #1
	add r5, #0x28
	add r0, r0, #1
	sub r1, r6, r0
	ldrb r0, [r4, #1]
	add r0, r0, #1
	sub r1, r1, r0
	ldrb r0, [r4, #2]
	add r0, r0, #1
	sub r1, r1, r0
	ldrb r0, [r4, #3]
	add r0, r0, #1
	sub r1, r1, r0
	ldrb r0, [r4, #4]
	add r0, r0, #1
	sub r6, r1, r0
	cmp r7, #3
	blt _021ED97A
	cmp r6, #0x4b
	ble _021ED9BA
	mov r6, #0x4b
	b _021ED9C0
_021ED9BA:
	cmp r6, #0
	bge _021ED9C0
	mov r6, #0
_021ED9C0:
	ldr r0, [sp]
	bl NARC_Delete
	add r0, r6, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021ED954


	thumb_func_start ov96_021ED9CC
ov96_021ED9CC: ; 0x021ED9CC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r0, #0
	mov r0, #0
	str r0, [sp, #4]
	bl MTRandom
	mov r1, #3
	and r0, r1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #0xc]
_021ED9E4:
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp]
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
_021ED9EE:
	ldr r0, [sp, #8]
	mov r5, #0
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_021ED9F6:
	lsl r3, r5, #0x18
	add r0, r7, #0
	add r1, r6, #0
	add r2, r4, #0
	lsr r3, r3, #0x18
	bl ov96_021EDCEC
	cmp r0, #0
	beq _021EDA0E
	mov r0, #1
	str r0, [sp, #4]
	b _021EDA14
_021EDA0E:
	add r5, r5, #1
	cmp r5, #3
	blt _021ED9F6
_021EDA14:
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _021EDA24
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #4
	blt _021ED9EE
_021EDA24:
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _021EDA46
	ldr r0, [sp]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	str r0, [sp]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #4
	blt _021ED9E4
_021EDA46:
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _021EDA50
	mov r0, #4
	str r0, [sp]
_021EDA50:
	ldr r0, [sp]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021ED9CC


	thumb_func_start ov96_021EDA58
ov96_021EDA58: ; 0x021EDA58
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	str r0, [sp]
	bl PokeathlonCourse_GetFieldData
	str r0, [sp, #0x10]
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0x28
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r1, [r4, #4]
	ldr r0, _021EDC28 ; =0xF8007FFF
	mov r5, #0
	and r1, r0
	asr r0, r0, #0xc
	and r0, r1
	str r0, [r4, #4]
	ldr r1, [r4, #8]
	ldr r0, _021EDC2C ; =0xF000FFFF
	and r0, r1
	str r0, [r4, #8]
_021EDA88:
	lsl r1, r5, #0x18
	ldr r0, [sp]
	lsr r1, r1, #0x18
	bl ov96_021ED954
	strb r0, [r4, r5]
	add r5, r5, #1
	cmp r5, #4
	blt _021EDA88
	ldr r0, [sp]
	bl ov96_021ED9CC
	ldr r2, [r4, #4]
	mov r1, #7
	bic r2, r1
	mov r1, #7
	and r0, r1
	add r1, r2, #0
	orr r1, r0
	mov r0, #0
	str r0, [sp, #0x20]
	str r0, [sp, #0xc]
	lsl r0, r1, #0x1d
	lsr r0, r0, #0x1d
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	str r1, [r4, #4]
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x10]
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x28]
_021EDACC:
	ldr r0, [sp, #0x24]
	ldr r5, [sp, #8]
	lsl r0, r0, #0x18
	mov r6, #0
	lsr r7, r0, #0x18
_021EDAD6:
	ldr r0, [sp, #0x1c]
	cmp r0, #4
	beq _021EDAF2
	lsl r3, r6, #0x18
	ldr r0, [sp]
	ldr r1, [sp, #0x28]
	add r2, r7, #0
	lsr r3, r3, #0x18
	bl ov96_021EDCEC
	ldr r1, [sp, #0x20]
	cmp r1, r0
	bge _021EDAF2
	str r0, [sp, #0x20]
_021EDAF2:
	ldr r1, [r5, #8]
	ldr r0, [sp, #0xc]
	cmp r0, r1
	bhs _021EDAFC
	str r1, [sp, #0xc]
_021EDAFC:
	add r6, r6, #1
	add r5, #0x20
	cmp r6, #3
	blt _021EDAD6
	ldr r0, [sp, #8]
	add r0, #0x60
	str r0, [sp, #8]
	ldr r0, [sp, #0x24]
	add r0, r0, #1
	str r0, [sp, #0x24]
	cmp r0, #4
	blt _021EDACC
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #0x14]
_021EDB1A:
	add r0, r4, #0
	str r0, [sp, #0x2c]
	add r0, #8
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x1c]
	ldr r5, [sp, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x30]
	ldr r0, [sp, #4]
	mov r6, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x34]
_021EDB36:
	ldr r0, [sp, #0x14]
	add r0, r6, r0
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [r5]
	cmp r0, #0
	bne _021EDB6A
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _021EDB6A
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	bne _021EDB6A
	ldr r2, [r4, #4]
	ldr r0, _021EDC28 ; =0xF8007FFF
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #5
	mov r2, #1
	lsl r2, r7
	lsr r0, r0, #0x14
	add r0, r0, r2
	lsl r0, r0, #0x14
	lsr r0, r0, #5
	orr r0, r1
	str r0, [r4, #4]
_021EDB6A:
	ldr r1, [r5, #8]
	ldr r0, [sp, #0xc]
	cmp r0, r1
	bne _021EDB90
	ldr r0, [sp, #0x2c]
	ldr r2, [r0]
	ldr r0, _021EDC2C ; =0xF000FFFF
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #4
	mov r2, #1
	lsl r2, r7
	lsr r0, r0, #0x14
	add r0, r0, r2
	lsl r0, r0, #0x14
	lsr r0, r0, #4
	orr r1, r0
	ldr r0, [sp, #0x2c]
	str r1, [r0]
_021EDB90:
	ldr r0, [sp, #0x1c]
	cmp r0, #4
	beq _021EDBD2
	lsl r3, r6, #0x18
	ldr r0, [sp]
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	lsr r3, r3, #0x18
	bl ov96_021EDCEC
	ldr r1, [sp, #0x20]
	str r0, [sp, #0x18]
	cmp r0, r1
	ble _021EDBB0
	bl GF_AssertFail
_021EDBB0:
	ldr r1, [sp, #0x20]
	ldr r0, [sp, #0x18]
	cmp r1, r0
	bne _021EDBD2
	ldr r2, [r4, #4]
	ldr r0, _021EDC30 ; =0xFFFF8007
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #0x11
	mov r2, #1
	lsl r2, r7
	lsr r0, r0, #0x14
	add r0, r0, r2
	lsl r0, r0, #0x14
	lsr r0, r0, #0x11
	orr r0, r1
	str r0, [r4, #4]
_021EDBD2:
	add r6, r6, #1
	add r5, #0x20
	cmp r6, #3
	blt _021EDB36
	ldr r0, [sp, #0x14]
	add r0, r0, #3
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, #0x60
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #4
	blt _021EDB1A
	ldr r1, [r4, #8]
	ldr r0, _021EDC34 ; =0xFFFF0000
	and r1, r0
	ldr r0, [sp, #0x20]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	orr r0, r1
	str r0, [r4, #8]
	bl MTRandom
	add r2, r0, #0
	mov r1, #3
	and r2, r1
	mov r3, #0
	mov r0, #0x1e
_021EDC0E:
	add r1, r4, r2
	strb r3, [r1, #0xd]
	add r1, r2, #1
	lsr r2, r1, #0x1f
	lsl r1, r1, #0x1e
	sub r1, r1, r2
	ror r1, r0
	add r3, r3, #1
	add r2, r2, r1
	cmp r3, #4
	blt _021EDC0E
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021EDC28: .word 0xF8007FFF
_021EDC2C: .word 0xF000FFFF
_021EDC30: .word 0xFFFF8007
_021EDC34: .word 0xFFFF0000
	thumb_func_end ov96_021EDA58


	thumb_func_start ov96_021EDC38
ov96_021EDC38: ; 0x021EDC38
	cmp r0, #0xa
	bhi _021EDCB0
	add r2, r0, r0
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021EDC48: ; jump table
	.short _021EDCB0 - _021EDC48 - 2 ; case 0
	.short _021EDCB0 - _021EDC48 - 2 ; case 1
	.short _021EDCB0 - _021EDC48 - 2 ; case 2
	.short _021EDCB0 - _021EDC48 - 2 ; case 3
	.short _021EDCB0 - _021EDC48 - 2 ; case 4
	.short _021EDC62 - _021EDC48 - 2 ; case 5
	.short _021EDC72 - _021EDC48 - 2 ; case 6
	.short _021EDC82 - _021EDC48 - 2 ; case 7
	.short _021EDC92 - _021EDC48 - 2 ; case 8
	.short _021EDCA2 - _021EDC48 - 2 ; case 9
	.short _021EDC5E - _021EDC48 - 2 ; case 10
_021EDC5E:
	mov r0, #0
	bx lr
_021EDC62:
	cmp r1, #0
	beq _021EDC6A
	mov r0, #4
	b _021EDC6C
_021EDC6A:
	mov r0, #0
_021EDC6C:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bx lr
_021EDC72:
	cmp r1, #0
	beq _021EDC7A
	mov r0, #2
	b _021EDC7C
_021EDC7A:
	mov r0, #4
_021EDC7C:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bx lr
_021EDC82:
	cmp r1, #0
	beq _021EDC8A
	mov r0, #1
	b _021EDC8C
_021EDC8A:
	mov r0, #2
_021EDC8C:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bx lr
_021EDC92:
	cmp r1, #0
	beq _021EDC9A
	mov r0, #3
	b _021EDC9C
_021EDC9A:
	mov r0, #1
_021EDC9C:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bx lr
_021EDCA2:
	cmp r1, #0
	beq _021EDCAA
	mov r0, #0
	b _021EDCAC
_021EDCAA:
	mov r0, #3
_021EDCAC:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
_021EDCB0:
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021EDC38


	thumb_func_start ov96_021EDCB4
ov96_021EDCB4: ; 0x021EDCB4
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r6, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r5, #0
	bne _021EDCCE
	bl GF_AssertFail
_021EDCCE:
	cmp r6, #0
	bne _021EDCD6
	bl GF_AssertFail
_021EDCD6:
	cmp r4, #0
	bne _021EDCDE
	bl GF_AssertFail
_021EDCDE:
	ldr r0, [r4, #4]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1d
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021EDCB4


	thumb_func_start ov96_021EDCEC
ov96_021EDCEC: ; 0x021EDCEC
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	add r4, r2, #0
	add r5, r3, #0
	bl PokeathlonCourse_GetFieldData
	add r6, r0, #0
	cmp r4, #4
	blo _021EDD02
	bl GF_AssertFail
_021EDD02:
	cmp r5, #3
	blo _021EDD0A
	bl GF_AssertFail
_021EDD0A:
	cmp r7, #3
	bhi _021EDD58
	add r0, r7, r7
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021EDD1A: ; jump table
	.short _021EDD22 - _021EDD1A - 2 ; case 0
	.short _021EDD30 - _021EDD1A - 2 ; case 1
	.short _021EDD3E - _021EDD1A - 2 ; case 2
	.short _021EDD4A - _021EDD1A - 2 ; case 3
_021EDD22:
	mov r0, #0x60
	mul r0, r4
	add r1, r6, r0
	lsl r0, r5, #5
	add r0, r1, r0
	ldr r0, [r0, #4]
	pop {r3, r4, r5, r6, r7, pc}
_021EDD30:
	mov r0, #0x60
	mul r0, r4
	add r1, r6, r0
	lsl r0, r5, #5
	add r0, r1, r0
	ldr r0, [r0, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
_021EDD3E:
	mov r0, #0x60
	mul r0, r4
	lsl r1, r5, #5
	add r0, r6, r0
	ldr r0, [r1, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021EDD4A:
	mov r0, #0x60
	mul r0, r4
	add r1, r6, r0
	lsl r0, r5, #5
	add r0, r1, r0
	ldr r0, [r0, #0x14]
	pop {r3, r4, r5, r6, r7, pc}
_021EDD58:
	bl GF_AssertFail
	bl GF_AssertFail
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EDCEC


	thumb_func_start ov96_021EDD64
ov96_021EDD64: ; 0x021EDD64
	add r1, r0, #0
	add r1, #0xb3
	ldrb r1, [r1]
	add r2, r1, #1
	add r1, r0, #0
	add r1, #0xb3
	strb r2, [r1]
	add r1, r0, #0
	add r1, #0xb3
	ldrb r1, [r1]
	cmp r1, #3
	blo _021EDD92
	add r1, r0, #0
	mov r2, #0
	add r1, #0xb3
	strb r2, [r1]
	add r1, r0, #0
	add r1, #0xb2
	ldrb r1, [r1]
	add r2, r1, #1
	add r1, r0, #0
	add r1, #0xb2
	strb r2, [r1]
_021EDD92:
	add r0, #0xb2
	ldrb r0, [r0]
	cmp r0, #4
	bne _021EDD9E
	mov r0, #1
	bx lr
_021EDD9E:
	mov r0, #0
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021EDD64


	thumb_func_start ov96_021EDDA4
ov96_021EDDA4: ; 0x021EDDA4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
_021EDDB2:
	add r1, r4, #0
	add r2, r4, #0
	add r1, #0xb2
	add r2, #0xb3
	ldrb r1, [r1]
	ldrb r2, [r2]
	add r0, r5, #0
	blx r6
	cmp r0, #0
	bne _021EDDD0
	add r0, r4, #0
	bl ov96_021EDD64
	cmp r0, #0
	beq _021EDDB2
_021EDDD0:
	add r0, r4, #0
	add r0, #0xb2
	ldrb r1, [r0]
	cmp r1, #4
	bhs _021EDE5E
	add r0, r4, #0
	add r0, #0xb3
	ldrb r2, [r0]
	lsl r0, r1, #1
	add r0, r1, r0
	add r6, r2, r0
	add r0, r4, #0
	add r0, #0xac
	ldrb r2, [r0, r1]
	add r2, r2, #1
	strb r2, [r0, r1]
	add r0, r4, #0
	add r0, #0xb4
	ldrb r0, [r0]
	add r2, r4, #0
	add r2, #0xb3
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xb4
	strb r1, [r0]
	add r1, r4, #0
	add r1, #0xb2
	ldrb r1, [r1]
	ldrb r2, [r2]
	add r0, r5, #0
	bl ov96_021ED5AC
	add r1, r4, #0
	add r0, r4, #0
	add r1, #0xb2
	add r0, #0x8c
	lsl r2, r7, #0x10
	ldrb r1, [r1]
	ldr r0, [r0]
	lsr r2, r2, #0x10
	bl ov96_021ECC38
	lsl r1, r6, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_021EC298
	lsl r1, r6, #0x18
	ldr r0, [r4, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	bl ov96_021EAA20
	bl ov96_021E8BB0
	add r5, r0, #0
	mov r0, #1
	bl sub_02006E3C
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl PlayCry
	add r0, r4, #0
	bl ov96_021EDD64
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021EDE5E:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EDDA4


	thumb_func_start ov96_021EDE64
ov96_021EDE64: ; 0x021EDE64
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r0, #0
	add r6, r1, #0
	bl ov96_021E5F24
	str r0, [sp, #4]
	add r0, r4, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp]
	add r0, r4, #0
	bl PokeathlonCourse_GetFieldData
	add r7, r0, #0
	ldr r0, [sp]
	add r0, #0x9c
	ldr r0, [r0]
	lsl r0, r0, #4
	lsr r1, r0, #0x1c
	ldr r0, [sp, #4]
	cmp r1, r0
	bne _021EDEA2
	mov r1, #0x1d
	lsl r1, r1, #4
	ldrh r2, [r7, r1]
	mov r0, #1
	bic r2, r0
	mov r0, #1
	orr r0, r2
	strh r0, [r7, r1]
_021EDEA2:
	ldr r5, _021EDF34 ; =0x000003E7
	mov r4, #0
_021EDEA6:
	lsl r1, r4, #0x18
	add r0, r6, #0
	lsr r1, r1, #0x18
	bl ov96_021ECC4C
	cmp r5, r0
	blt _021EDEB6
	add r5, r0, #0
_021EDEB6:
	add r4, r4, #1
	cmp r4, #4
	blt _021EDEA6
	ldr r1, [sp, #4]
	add r0, r6, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021ECC4C
	cmp r0, r5
	bne _021EDED8
	mov r1, #0x1d
	lsl r1, r1, #4
	ldrh r2, [r7, r1]
	mov r0, #2
	orr r0, r2
	strh r0, [r7, r1]
_021EDED8:
	ldr r1, [sp]
	ldr r0, [sp, #4]
	add r0, r1, r0
	add r0, #0xac
	ldrb r1, [r0]
	mov r0, #6
	lsl r0, r0, #6
	str r1, [r7, r0]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	add r0, #0x8c
	lsl r1, r1, #0x18
	ldr r0, [r0]
	lsr r1, r1, #0x18
	bl ov96_021ECC4C
	ldr r1, _021EDF38 ; =0x000001D2
	strh r0, [r7, r1]
	ldr r1, [sp, #4]
	ldr r0, [sp]
	lsl r1, r1, #0x18
	add r0, #0x9c
	lsr r1, r1, #0x18
	str r0, [sp]
	bl ov96_021EE264
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _021EDF1A
	bl GF_AssertFail
_021EDF1A:
	mov r2, #0x1d
	lsl r2, r2, #4
	ldrh r0, [r7, r2]
	mov r1, #0xc
	bic r0, r1
	lsl r1, r4, #0x10
	lsr r1, r1, #0x10
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1c
	orr r0, r1
	strh r0, [r7, r2]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021EDF34: .word 0x000003E7
_021EDF38: .word 0x000001D2
	thumb_func_end ov96_021EDE64


	thumb_func_start ov96_021EDF3C
ov96_021EDF3C: ; 0x021EDF3C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r1, #0
	mov r1, #0
	add r4, r2, #0
	str r1, [sp]
	mov r1, #1
	str r1, [sp, #4]
	add r1, r3, #0
	add r2, r5, #0
	add r3, r4, #0
	bl BufferIntegerAsString
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021EDF3C


	thumb_func_start ov96_021EDF5C
ov96_021EDF5C: ; 0x021EDF5C
	ldr r3, _021EDF78 ; =ov96_0221B058
	mov r2, #0
_021EDF60:
	ldr r1, [r3]
	cmp r1, r0
	ble _021EDF6A
	add r0, r2, #0
	bx lr
_021EDF6A:
	add r2, r2, #1
	add r3, r3, #4
	cmp r2, #0xc
	blt _021EDF60
	add r0, r2, #0
	bx lr
	nop
_021EDF78: .word ov96_0221B058
	thumb_func_end ov96_021EDF5C

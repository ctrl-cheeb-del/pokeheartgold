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
	.public ov96_021ED754
	.public ov96_021ED78C
	.public ov96_021ED7C4
	.public ov96_021ED7FC
	.public ov96_021ED838
	.public ov96_021ED86C
	.public ov96_021ED8A4
	.public ov96_021ED8DC
	.public ov96_021ED954
	.public ov96_021EDC38
	.public ov96_021EDCB4
	.public ov96_021EDCEC
	.public ov96_021EDD64
	.public ov96_021EDF3C
	.public ov96_021EDF5C


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

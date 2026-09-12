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


	thumb_func_start ov96_02218B1C
ov96_02218B1C: ; 0x02218B1C
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r2, #0x5d
	ldrsb r0, [r4, r2]
	cmp r0, #0
	ble _02218B3A
	sub r3, r0, #1
	add r0, r4, #0
	add r0, #0x5d
	strb r3, [r0]
	ldrsb r0, [r4, r2]
	cmp r0, #0
	ble _02218B3A
	b _02218DEA
_02218B3A:
	ldr r0, [r4, #0x14]
	cmp r0, #0xc
	bhi _02218B6E
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02218B4C: ; jump table
	.short _02218B6E - _02218B4C - 2 ; case 0
	.short _02218B6E - _02218B4C - 2 ; case 1
	.short _02218B6E - _02218B4C - 2 ; case 2
	.short _02218B6E - _02218B4C - 2 ; case 3
	.short _02218B6E - _02218B4C - 2 ; case 4
	.short _02218B74 - _02218B4C - 2 ; case 5
	.short _02218B66 - _02218B4C - 2 ; case 6
	.short _02218B74 - _02218B4C - 2 ; case 7
	.short _02218B74 - _02218B4C - 2 ; case 8
	.short _02218B6E - _02218B4C - 2 ; case 9
	.short _02218B74 - _02218B4C - 2 ; case 10
	.short _02218B74 - _02218B4C - 2 ; case 11
	.short _02218B74 - _02218B4C - 2 ; case 12
_02218B66:
	add r0, r4, #0
	bl ov96_02218F18
	b _02218B74
_02218B6E:
	add r0, r4, #0
	bl ov96_022187A8
_02218B74:
	ldr r0, [r4, #0x14]
	cmp r0, #0xc
	bls _02218B7C
	b _02218DE0
_02218B7C:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02218B88: ; jump table
	.short _02218DE0 - _02218B88 - 2 ; case 0
	.short _02218C4E - _02218B88 - 2 ; case 1
	.short _02218C20 - _02218B88 - 2 ; case 2
	.short _02218BFE - _02218B88 - 2 ; case 3
	.short _02218BA2 - _02218B88 - 2 ; case 4
	.short _02218D62 - _02218B88 - 2 ; case 5
	.short _02218D84 - _02218B88 - 2 ; case 6
	.short _02218DC6 - _02218B88 - 2 ; case 7
	.short _02218C88 - _02218B88 - 2 ; case 8
	.short _02218CAC - _02218B88 - 2 ; case 9
	.short _02218CEA - _02218B88 - 2 ; case 10
	.short _02218D0E - _02218B88 - 2 ; case 11
	.short _02218D46 - _02218B88 - 2 ; case 12
_02218BA2:
	ldr r0, [r4, #0x60]
	lsl r0, r0, #4
	lsr r0, r0, #0x1f
	beq _02218BAE
	bl GF_AssertFail
_02218BAE:
	add r0, r4, #0
	bl ov96_02218934
	cmp r0, #0
	beq _02218BC0
	add r0, r4, #0
	bl ov96_02219030
	b _02218DE4
_02218BC0:
	ldr r0, [r4, #0x60]
	lsl r1, r0, #2
	lsr r1, r1, #0x1f
	beq _02218BD0
	add r0, r4, #0
	bl ov96_02218F58
	b _02218DE4
_02218BD0:
	lsl r0, r0, #1
	lsr r0, r0, #0x1f
	beq _02218BE2
	add r1, r4, #0
	add r0, r4, #0
	add r1, #0x1c
	bl ov96_02218DF8
	b _02218DE4
_02218BE2:
	mov r1, #0x5e
	ldrsb r0, [r4, r1]
	sub r2, r0, #1
	add r0, r4, #0
	add r0, #0x5e
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _02218CD8
	add r0, r4, #0
	mov r1, #1
	bl ov96_02218578
	b _02218DE4
_02218BFE:
	mov r1, #0x5b
	ldrsb r0, [r4, r1]
	sub r2, r0, #1
	add r0, r4, #0
	add r0, #0x5b
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _02218CD8
	add r0, r4, #0
	bl ov96_02218A50
	add r0, r4, #0
	mov r1, #4
	bl ov96_02218578
	b _02218DE4
_02218C20:
	add r0, r4, #0
	bl ov96_02218934
	cmp r0, #0
	beq _02218C32
	add r0, r4, #0
	bl ov96_02219030
	b _02218DE4
_02218C32:
	mov r1, #0x58
	ldrsb r0, [r4, r1]
	sub r2, r0, #1
	add r0, r4, #0
	add r0, #0x58
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _02218CD8
	add r0, r4, #0
	mov r1, #1
	bl ov96_02218578
	b _02218DE4
_02218C4E:
	add r0, r4, #0
	bl ov96_02218934
	cmp r0, #0
	beq _02218C60
	add r0, r4, #0
	bl ov96_02219030
	b _02218DE4
_02218C60:
	ldr r1, [r4, #0x60]
	lsl r0, r1, #4
	lsr r0, r0, #0x1f
	bne _02218CD8
	lsl r0, r1, #2
	lsr r0, r0, #0x1f
	beq _02218C76
	add r0, r4, #0
	bl ov96_02218F58
	b _02218DE4
_02218C76:
	lsl r0, r1, #1
	lsr r0, r0, #0x1f
	beq _02218CD8
	add r1, r4, #0
	add r0, r4, #0
	add r1, #0x1c
	bl ov96_02218DF8
	b _02218DE4
_02218C88:
	mov r1, #0x5a
	ldrsb r0, [r4, r1]
	sub r2, r0, #1
	add r0, r4, #0
	add r0, #0x5a
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _02218CD8
	add r0, r4, #0
	mov r1, #0
	add r0, #0x5a
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #9
	bl ov96_02218578
	b _02218DE4
_02218CAC:
	ldr r0, [r4, #4]
	ldr r3, _02218DF0 ; =ov96_0221D7D0
	ldr r0, [r0, #4]
	ldrb r1, [r0, #0x18]
	mov r0, #0x14
	add r5, r1, #0
	mov r1, #0x5a
	mul r5, r0
	ldrsb r0, [r4, r1]
	lsl r2, r0, #1
	add r0, r3, r5
	ldrsh r0, [r2, r0]
	lsl r0, r0, #0xc
	str r0, [r4, #0x50]
	ldrsb r0, [r4, r1]
	add r2, r0, #1
	add r0, r4, #0
	add r0, #0x5a
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0xa
	bge _02218CDA
_02218CD8:
	b _02218DE4
_02218CDA:
	add r0, r4, #0
	mov r1, #0xa
	add r0, #0x5a
	strb r1, [r0]
	add r0, r4, #0
	bl ov96_02218578
	b _02218DE4
_02218CEA:
	mov r1, #0x5a
	ldrsb r0, [r4, r1]
	sub r2, r0, #1
	add r0, r4, #0
	add r0, #0x5a
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _02218DE4
	add r0, r4, #0
	mov r1, #0
	add r0, #0x5a
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #0xb
	bl ov96_02218578
	b _02218DE4
_02218D0E:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bne _02218D2C
	add r0, r4, #0
	bl ov96_02218FD4
	add r0, r4, #0
	bl ov96_02218934
	cmp r0, #0
	beq _02218DE4
	add r0, r4, #0
	bl ov96_02219030
	b _02218DE4
_02218D2C:
	ldr r1, [r4, #4]
	ldr r1, [r1, #4]
	ldrb r2, [r1, #0x18]
	ldr r1, _02218DF4 ; =ov96_0221D69C
	ldrb r1, [r1, r2]
	lsl r1, r1, #0xc
	sub r0, r0, r1
	str r0, [r4, #0x50]
	cmp r0, #0
	bgt _02218DE4
	mov r0, #0
	str r0, [r4, #0x50]
	b _02218DE4
_02218D46:
	mov r1, #0x5a
	ldrsb r0, [r4, r1]
	sub r2, r0, #1
	add r0, r4, #0
	add r0, #0x5a
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _02218DE4
	add r0, r4, #0
	mov r1, #1
	bl ov96_02218578
	b _02218DE4
_02218D62:
	mov r1, #0x59
	ldrsb r0, [r4, r1]
	sub r2, r0, #1
	add r0, r4, #0
	add r0, #0x59
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _02218DE4
	add r0, r4, #0
	mov r1, #6
	add r0, #0x59
	strb r1, [r0]
	add r0, r4, #0
	bl ov96_02218578
	b _02218DE4
_02218D84:
	mov r1, #0x59
	ldrsb r0, [r4, r1]
	sub r2, r0, #1
	add r0, r4, #0
	add r0, #0x59
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _02218DE4
	add r3, r4, #0
	add r3, #0x2c
	add r2, r4, #0
	ldmia r3!, {r0, r1}
	add r2, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r3, sp, #0
	str r0, [r2]
	mov r0, #0
	str r0, [r3]
	str r0, [r3, #4]
	str r0, [r3, #8]
	add r2, r4, #0
	ldmia r3!, {r0, r1}
	add r2, #0x44
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #7
	str r0, [r2]
	add r0, r4, #0
	bl ov96_02218578
	b _02218DE4
_02218DC6:
	mov r1, #0x59
	ldrsb r0, [r4, r1]
	sub r2, r0, #1
	add r0, r4, #0
	add r0, #0x59
	strb r2, [r0]
	ldrsb r0, [r4, r1]
	cmp r0, #0
	bgt _02218DE4
	add r0, r4, #0
	bl ov96_02218EB8
	b _02218DE4
_02218DE0:
	bl GF_AssertFail
_02218DE4:
	add r0, r4, #0
	bl ov96_02218AF0
_02218DEA:
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_02218DF0: .word ov96_0221D7D0
_02218DF4: .word ov96_0221D69C
	thumb_func_end ov96_02218B1C





	thumb_func_start ov96_02218DF8
ov96_02218DF8: ; 0x02218DF8
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r4, r1, #0
	add r0, sp, #0
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [r5, #0x14]
	mov r2, #1
	cmp r0, #1
	beq _02218E18
	cmp r0, #4
	beq _02218E18
	add r2, r1, #0
_02218E18:
	cmp r2, #0
	bne _02218E20
	bl GF_AssertFail
_02218E20:
	ldr r0, [r5, #0x60]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	beq _02218E2C
	bl GF_AssertFail
_02218E2C:
	ldr r0, [r5, #0x60]
	lsl r0, r0, #5
	lsr r0, r0, #0x1f
	beq _02218E38
	bl GF_AssertFail
_02218E38:
	ldr r1, [r5, #0x60]
	ldr r0, _02218EB0 ; =0xBFFFFFFF
	add r2, r5, #0
	and r0, r1
	str r0, [r5, #0x60]
	mov r0, #0
	ldrsh r0, [r4, r0]
	add r1, r5, #0
	add r1, #0x2c
	lsl r0, r0, #0xc
	str r0, [sp]
	mov r0, #2
	ldrsh r0, [r4, r0]
	add r2, #0x38
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	add r0, sp, #0
	bl VEC_Subtract
	add r0, r5, #0
	add r0, #0x38
	add r1, r0, #0
	bl VEC_Normalize
	add r1, r5, #0
	mov r0, #1
	add r1, #0x38
	add r3, r5, #0
	lsl r0, r0, #0xe
	add r2, r1, #0
	add r3, #0x44
	bl VEC_MultAdd
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne _02218E86
	ldr r0, [r5, #0x48]
	cmp r0, #0
	beq _02218EAC
_02218E86:
	add r0, r5, #0
	add r0, #0x38
	bl ov96_022186CC
	lsl r0, r0, #0x1c
	ldr r2, [r5, #0x60]
	ldr r1, _02218EB4 ; =0xFFF0FFFF
	lsr r0, r0, #0xc
	and r1, r2
	orr r0, r1
	str r0, [r5, #0x60]
	add r0, r5, #0
	mov r1, #4
	add r0, #0x59
	strb r1, [r0]
	add r0, r5, #0
	mov r1, #5
	bl ov96_02218578
_02218EAC:
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_02218EB0: .word 0xBFFFFFFF
_02218EB4: .word 0xFFF0FFFF
	thumb_func_end ov96_02218DF8

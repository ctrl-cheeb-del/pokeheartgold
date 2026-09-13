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


	thumb_func_start ov96_021FF764
ov96_021FF764: ; 0x021FF764
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa0
	str r0, [sp, #8]
	mov r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r0, [sp, #0x24]
	str r0, [sp, #0x9c]
	str r0, [sp, #0x90]
	str r0, [sp, #0x18]
	add r4, r1, #0
_021FF77A:
	add r0, r4, #0
	add r0, #0x8b
	ldrb r0, [r0]
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x9d
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FF796
	add r0, r4, #0
	add r0, #0xa9
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FF798
_021FF796:
	b _021FFAC8
_021FF798:
	ldr r0, [sp, #0x14]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	str r0, [sp, #0x2c]
	add r0, sp, #0x3c
	str r0, [sp]
	ldr r2, [r4, #0x7c]
	ldr r0, [sp, #0x2c]
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	add r2, r4, #0
	add r2, #0x80
	ldr r3, [r2]
	asr r1, r1, #0xc
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r2, r2, #0xc
	add r3, sp, #0x40
	bl ov96_021EB0A4
	add r0, r4, #0
	str r0, [sp, #0x30]
	add r0, #0x8c
	ldr r5, [sp, #0xc]
	mov r6, #0
	str r0, [sp, #0x30]
_021FF7D0:
	ldr r0, [sp, #0x18]
	cmp r0, r6
	bne _021FF7D8
	b _021FFABE
_021FF7D8:
	add r0, r5, #0
	add r0, #0x9d
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FF8E0
	add r0, r5, #0
	add r0, #0x8b
	ldrb r0, [r0]
	ldr r7, [sp, #0x40]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	str r0, [sp, #0x28]
	add r0, sp, #0x34
	str r0, [sp]
	ldr r1, [r5, #0x7c]
	ldr r0, [sp, #0x28]
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	add r2, r5, #0
	add r2, #0x80
	ldr r3, [r2]
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r2, r2, #0xc
	add r3, sp, #0x38
	bl ov96_021EB0A4
	ldr r0, [r4, #0x7c]
	str r0, [sp, #0x1c]
	bl _dflt
	ldr r3, _021FFADC ; =0x41480000
	mov r2, #0
	bl _dgr
	bls _021FF846
	mov r0, #1
	ldr r1, [r5, #0x7c]
	lsl r0, r0, #0x14
	cmp r1, r0
	bge _021FF846
	ldr r0, [sp, #0x38]
	bl _dflt
	ldr r3, _021FFAE0 ; =0x40900000
	mov r2, #0
	bl _dadd
	bl _dfix
	str r0, [sp, #0x38]
	b _021FF874
_021FF846:
	ldr r0, [r5, #0x7c]
	bl _dflt
	ldr r3, _021FFADC ; =0x41480000
	mov r2, #0
	bl _dgr
	bls _021FF874
	mov r0, #1
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #0x14
	cmp r1, r0
	bge _021FF874
	add r0, r7, #0
	bl _dflt
	ldr r3, _021FFAE0 ; =0x40900000
	mov r2, #0
	bl _dadd
	bl _dfix
	add r7, r0, #0
_021FF874:
	add r0, sp, #0x8c
	str r0, [sp]
	add r0, sp, #0x44
	str r0, [sp, #4]
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x34]
	ldr r0, [sp, #0x28]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x88
	bl ov96_021EAF78
	add r0, sp, #0x98
	str r0, [sp]
	add r0, sp, #0x48
	str r0, [sp, #4]
	ldr r2, [sp, #0x3c]
	ldr r0, [sp, #0x2c]
	lsl r1, r7, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x94
	bl ov96_021EAF78
	add r0, sp, #0x88
	add r1, sp, #0x94
	add r2, sp, #0x7c
	bl VEC_Subtract
	add r0, sp, #0x7c
	bl VEC_Mag
	ldr r2, [sp, #0x44]
	ldr r1, [sp, #0x48]
	add r1, r2, r1
	lsl r1, r1, #0xc
	cmp r0, r1
	blt _021FF8C0
	b _021FFAAC
_021FF8C0:
	add r0, r4, r6
	add r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FF8E0
	mov r1, #0
	add r0, sp, #0x70
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r1, [sp, #0x30]
	add r0, sp, #0x7c
	bl VEC_DotProduct
	cmp r0, #0
	bgt _021FF8E2
_021FF8E0:
	b _021FFABE
_021FF8E2:
	add r0, r4, #0
	add r0, #0x8c
	bl VEC_Mag
	cmp r0, #0
	beq _021FF94C
	add r0, r4, #0
	add r0, #0x8b
	ldrb r0, [r0]
	mov r2, #0x1c
	str r0, [sp, #0x20]
	ldr r1, [sp, #0x20]
	ldr r0, _021FFAE4 ; =0x45800000
	mul r2, r1
	add r1, r4, r2
	ldr r1, [r1, #0x20]
	bl _fmul
	bl _ffix
	add r1, r4, #0
	add r3, r5, #0
	add r1, #0x8c
	add r2, sp, #0x70
	add r3, #0x8c
	bl VEC_MultAdd
	add r0, r5, #0
	add r0, #0x8c
	bl VEC_Mag
	mov r1, #0xb
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _021FF94C
	add r1, sp, #0x64
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r0, r5, #0
	add r0, #0x8c
	add r1, r0, #0
	bl VEC_Normalize
	add r1, r5, #0
	mov r0, #0xb
	add r1, #0x8c
	lsl r0, r0, #0xc
	add r2, sp, #0x64
	add r3, r1, #0
	bl VEC_MultAdd
_021FF94C:
	ldr r0, [sp, #0x14]
	mov r1, #0x1c
	mul r1, r0
	add r0, r5, r1
	add r1, r0, #0
	add r1, #0x30
	ldrb r1, [r1]
	cmp r1, #1
	bne _021FF98A
	mov r1, #0
	str r1, [r0, #0x24]
	add r1, r0, #0
	mov r2, #2
	add r1, #0x30
	strb r2, [r1]
	add r0, #0x2f
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0xa4
	strb r1, [r0]
	mov r3, #1
	add r1, r5, #0
	add r2, r5, #0
	str r3, [sp]
	add r1, #0xd0
	add r2, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [sp, #8]
	bl ov96_021E8228
_021FF98A:
	add r3, sp, #0x58
	mov r7, #0
	str r7, [r3]
	str r7, [r3, #4]
	str r7, [r3, #8]
	add r2, r4, #0
	ldmia r3!, {r0, r1}
	add r2, #0x8c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0x1c
	str r0, [r2]
	ldr r0, [sp, #0x20]
	mul r1, r0
	add r0, r4, r1
	add r1, r0, #0
	add r1, #0x30
	ldrb r1, [r1]
	cmp r1, #1
	bne _021FF9DC
	add r1, r0, #0
	str r7, [r0, #0x24]
	mov r2, #2
	add r1, #0x30
	strb r2, [r1]
	add r0, #0x2f
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0xa4
	strb r1, [r0]
	mov r3, #1
	add r1, r4, #0
	add r2, r4, #0
	str r3, [sp]
	add r1, #0xd0
	add r2, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [sp, #8]
	bl ov96_021E8228
_021FF9DC:
	add r0, r4, r6
	add r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FF9EA
	bl GF_AssertFail
_021FF9EA:
	ldr r0, [sp, #0x18]
	add r0, r5, r0
	add r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FF9FA
	bl GF_AssertFail
_021FF9FA:
	add r1, r5, r6
	mov r0, #1
	add r1, #0x98
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	add r1, r4, r1
	add r1, #0x98
	strb r0, [r1]
	ldr r1, [sp, #0x24]
	cmp r1, #0
	bne _021FFA6C
	add r2, sp, #0x4c
	mov r1, #0
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [r2, #8]
	str r0, [sp, #0x24]
	add r0, sp, #0x88
	add r1, sp, #0x94
	bl VEC_Subtract
	add r0, sp, #0x4c
	add r1, r0, #0
	bl VEC_Normalize
	ldr r0, [sp, #0x48]
	add r1, sp, #0x4c
	lsl r0, r0, #0xc
	add r2, sp, #0x94
	add r3, r1, #0
	bl VEC_MultAdd
	ldr r6, [sp, #0x4c]
	add r0, r6, #0
	bl _dflt
	ldr r3, _021FFAE8 ; =0x41500000
	mov r2, #0
	bl _dgeq
	blo _021FFA60
	add r0, r6, #0
	bl _dflt
	ldr r3, _021FFAE8 ; =0x41500000
	mov r2, #0
	bl _dsub
	bl _dfix
	str r0, [sp, #0x4c]
_021FFA60:
	add r3, sp, #0x4c
	ldr r2, [sp, #0x10]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
_021FFA6C:
	add r0, r5, #0
	mov r1, #6
	add r0, #0xa9
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #0x12
	add r0, #0xa9
	strb r1, [r0]
	add r1, r5, #0
	mov r0, #1
	str r0, [sp]
	add r1, #0xd0
	add r5, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r5]
	ldr r0, [sp, #8]
	mov r3, #4
	bl ov96_021E8228
	mov r0, #1
	add r1, r4, #0
	add r2, r4, #0
	str r0, [sp]
	add r1, #0xd0
	add r2, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [sp, #8]
	mov r3, #4
	bl ov96_021E8228
	b _021FFAC8
_021FFAAC:
	add r1, r4, r6
	add r1, #0x98
	mov r0, #0
	strb r0, [r1]
	ldr r0, [sp, #0x18]
	add r1, r0, r5
	add r1, #0x98
	mov r0, #0
	strb r0, [r1]
_021FFABE:
	add r6, r6, #1
	add r5, #0xd4
	cmp r6, #4
	bge _021FFAC8
	b _021FF7D0
_021FFAC8:
	ldr r0, [sp, #0x18]
	add r4, #0xd4
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #4
	bge _021FFAD6
	b _021FF77A
_021FFAD6:
	ldr r0, [sp, #0x24]
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FFADC: .word 0x41480000
_021FFAE0: .word 0x40900000
_021FFAE4: .word 0x45800000
_021FFAE8: .word 0x41500000
	thumb_func_end ov96_021FF764

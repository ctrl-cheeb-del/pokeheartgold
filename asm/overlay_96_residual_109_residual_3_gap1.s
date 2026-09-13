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
	.public ov96_0221341C
	.public ov96_02213514
	.public ov96_02213534
	.public ov96_02213558
	.public ov96_022141F8
	.public ov96_02214234
	.public ov96_022143FC
	.public ov96_02214490
	.public ov96_0221454C
	.public ov96_02214618
	.public ov96_02214690
	.public ov96_022148E8


	thumb_func_start ov96_02213728
ov96_02213728: ; 0x02213728
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xb8
	add r7, r0, #0
	str r2, [sp, #4]
	add r0, sp, #0xac
	mov r2, #0
	str r2, [r0]
	str r2, [r0, #4]
	str r2, [r0, #8]
	add r0, sp, #0xa0
	str r2, [r0]
	str r2, [r0, #4]
	str r2, [r0, #8]
	add r0, sp, #0x7c
	str r2, [r0]
	str r2, [r0, #4]
	str r2, [r0, #8]
	add r0, sp, #0x70
	str r3, [sp, #8]
	str r2, [r0]
	str r2, [r0, #4]
	ldr r3, _02213928 ; =ov96_0221D214
	add r5, r1, #0
	str r2, [r0, #8]
	ldmia r3!, {r0, r1}
	add r6, sp, #0x64
	stmia r6!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _0221392C ; =ov96_0221D274
	str r0, [r6]
	ldmia r3!, {r0, r1}
	add r6, sp, #0x58
	stmia r6!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _02213930 ; =ov96_0221D244
	str r0, [r6]
	ldmia r3!, {r0, r1}
	add r6, sp, #0x4c
	stmia r6!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _02213934 ; =ov96_0221D22C
	str r0, [r6]
	ldmia r3!, {r0, r1}
	add r6, sp, #0x40
	stmia r6!, {r0, r1}
	ldr r0, [r3]
	ldr r4, [sp, #0xd0]
	str r0, [r6]
	str r2, [r4]
	str r2, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r5]
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	str r0, [sp, #0x28]
	ldr r0, [r5, #4]
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	str r0, [sp, #0x2c]
	ldr r0, [r7]
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	str r0, [sp, #0x20]
	ldr r0, [r7, #4]
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	str r0, [sp, #0x24]
	mov r0, #7
	ldr r1, [r7, #4]
	lsl r0, r0, #0x10
	cmp r1, r0
	ldr r1, [r7]
	bge _022137D6
	mov r0, #2
	lsl r0, r0, #0x12
	cmp r1, r0
	blt _022137E4
	mov r2, #1
	b _022137E4
_022137D6:
	mov r0, #2
	lsl r0, r0, #0x12
	cmp r1, r0
	bge _022137E2
	mov r2, #2
	b _022137E4
_022137E2:
	mov r2, #3
_022137E4:
	mov r6, #0
	ldr r0, [sp, #8]
	str r6, [sp, #0x14]
	str r6, [sp, #0x10]
	cmp r0, #0
	bne _022137F2
	b _02213942
_022137F2:
	cmp r2, #3
	bhi _0221388E
	add r0, r2, r2
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02213802: ; jump table
	.short _0221380A - _02213802 - 2 ; case 0
	.short _0221382A - _02213802 - 2 ; case 1
	.short _0221384C - _02213802 - 2 ; case 2
	.short _0221386A - _02213802 - 2 ; case 3
_0221380A:
	mov r0, #7
	lsl r0, r0, #0x10
	ldr r1, _02213938 ; =0xFFFE0000
	str r0, [sp, #0x80]
	mov r0, #6
	lsl r0, r0, #0x10
	str r0, [sp, #0x70]
	asr r0, r1, #1
	str r1, [sp, #0x7c]
	str r0, [sp, #0x74]
	add r0, sp, #0x64
	add r1, sp, #0x88
	bl VEC_Normalize
	mov r6, #5
	b _02213892
_0221382A:
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r0, [sp, #0x7c]
	ldr r0, _0221393C ; =0xFFFF0000
	add r1, sp, #0x88
	str r0, [sp, #0x80]
	mov r0, #0x12
	lsl r0, r0, #0x10
	str r0, [sp, #0x70]
	mov r0, #7
	lsl r0, r0, #0x10
	str r0, [sp, #0x74]
	add r0, sp, #0x58
	bl VEC_Normalize
	mov r6, #6
	b _02213892
_0221384C:
	mov r0, #0xe
	lsl r0, r0, #0x10
	mov r1, #6
	lsl r1, r1, #0x10
	str r0, [sp, #0x80]
	ldr r0, _02213938 ; =0xFFFE0000
	str r1, [sp, #0x7c]
	str r0, [sp, #0x70]
	str r1, [sp, #0x74]
	add r0, sp, #0x4c
	add r1, sp, #0x88
	bl VEC_Normalize
	mov r6, #7
	b _02213892
_0221386A:
	mov r0, #0x12
	lsl r0, r0, #0x10
	str r0, [sp, #0x7c]
	mov r0, #6
	lsl r0, r0, #0x10
	str r0, [sp, #0x80]
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r0, [sp, #0x70]
	mov r0, #0xe
	lsl r0, r0, #0x10
	str r0, [sp, #0x74]
	add r0, sp, #0x40
	add r1, sp, #0x88
	bl VEC_Normalize
	mov r6, #8
	b _02213892
_0221388E:
	bl GF_AssertFail
_02213892:
	cmp r6, #0
	beq _02213942
	ldr r0, [sp, #4]
	add r2, sp, #0x7c
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	add r1, sp, #0x88
	add r3, r2, #0
	bl VEC_MultAdd
	add r2, sp, #0x70
	ldr r0, [sp, #0xc]
	add r1, sp, #0x88
	add r3, r2, #0
	bl VEC_MultAdd
	ldr r1, [sp, #0x7c]
	add r2, sp, #0x28
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [sp, #0x80]
	str r0, [sp, #0x38]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [sp, #0x70]
	str r0, [sp, #0x3c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [sp, #0x74]
	str r0, [sp, #0x30]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x34]
	add r0, sp, #0x18
	str r0, [sp]
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r3, sp, #0x20
	bl sub_02020F4C
	cmp r0, #0
	beq _02213940
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x18
	bl sub_02020E80
	cmp r0, #0
	bne _02213916
	add r2, r5, #0
	ldmia r2!, {r0, r1}
	add r3, r4, #0
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
	mov r0, #1
	str r0, [sp, #0x14]
	b _02213922
_02213916:
	ldr r0, [sp, #0x18]
	lsl r0, r0, #0xc
	str r0, [r4]
	ldr r0, [sp, #0x1c]
	lsl r0, r0, #0xc
	str r0, [r4, #4]
_02213922:
	mov r0, #1
	str r0, [sp, #0x10]
	b _02213942
	.balign 4, 0
_02213928: .word ov96_0221D214
_0221392C: .word ov96_0221D274
_02213930: .word ov96_0221D244
_02213934: .word ov96_0221D22C
_02213938: .word 0xFFFE0000
_0221393C: .word 0xFFFF0000
_02213940:
	mov r6, #0
_02213942:
	mov r1, #7
	ldr r0, [r7, #4]
	lsl r1, r1, #0x10
	cmp r0, r1
	blt _0221394E
	b _02213B28
_0221394E:
	ldr r1, [sp, #4]
	add r1, #0x10
	lsl r2, r1, #0xc
	cmp r0, r2
	bge _02213974
	ldr r0, [sp, #4]
	mov r1, #0x10
	sub r0, r1, r0
	ldr r3, [r5, #4]
	lsl r0, r0, #0xc
	cmp r3, r0
	bne _02213974
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_02213974:
	mov r0, #2
	lsl r0, r0, #0xe
	str r0, [sp, #0xac]
	mov r0, #0xf7
	lsl r0, r0, #0xc
	str r0, [sp, #0xa0]
	str r2, [sp, #0xb0]
	str r2, [sp, #0xa4]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _022139EC
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _022139A4
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_022139A4:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _022139B8
	ldr r1, [r4, #4]
	ldr r0, [sp, #0x98]
	cmp r1, r0
	blt _022139B8
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_022139B8:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _022139DC
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _022139DC
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_022139DC:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_022139EC:
	mov r1, #2
	ldr r0, [r7]
	lsl r1, r1, #0x12
	cmp r0, r1
	bge _02213A8E
	ldr r1, [sp, #4]
	add r1, #8
	str r1, [sp, #4]
	lsl r1, r1, #0xc
	cmp r0, r1
	bge _02213A16
	ldr r0, [r5]
	cmp r0, r1
	bne _02213A16
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213A16:
	mov r0, #0xb7
	lsl r0, r0, #0xc
	str r0, [sp, #0xb0]
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0xa4]
	str r1, [sp, #0xac]
	str r1, [sp, #0xa0]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _02213AD2
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213A46
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213A46:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213A5A
	ldr r1, [r4]
	ldr r0, [sp, #0x94]
	cmp r1, r0
	blt _02213A5A
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213A5A:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213A7E
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213A7E
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213A7E:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213A8E:
	ldr r1, [sp, #4]
	mov r2, #0xf7
	sub r1, r2, r1
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _02213AAE
	ldr r0, [r5]
	cmp r0, r1
	bne _02213AAE
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213AAE:
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0xb0]
	mov r0, #0xb7
	lsl r0, r0, #0xc
	str r0, [sp, #0xa4]
	str r1, [sp, #0xac]
	str r1, [sp, #0xa0]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	bne _02213AD4
_02213AD2:
	b _02213CFA
_02213AD4:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213AE0
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213AE0:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213AF4
	ldr r1, [r4]
	ldr r0, [sp, #0x94]
	cmp r1, r0
	bgt _02213AF4
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213AF4:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213B18
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213B18
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213B18:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213B28:
	ldr r1, [sp, #4]
	mov r2, #0xb7
	sub r1, r2, r1
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _02213B48
	ldr r0, [r5, #4]
	cmp r0, r1
	bne _02213B48
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_02213B48:
	mov r0, #0xf7
	lsl r0, r0, #0xc
	str r0, [sp, #0xac]
	mov r0, #2
	lsl r0, r0, #0xe
	str r0, [sp, #0xa0]
	str r1, [sp, #0xb0]
	str r1, [sp, #0xa4]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _02213BC0
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213B78
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213B78:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213B8C
	ldr r1, [r4, #4]
	ldr r0, [sp, #0x98]
	cmp r1, r0
	bgt _02213B8C
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213B8C:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213BB0
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213BB0
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_02213BB0:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_02213BC0:
	mov r1, #2
	ldr r0, [r7]
	lsl r1, r1, #0x12
	cmp r0, r1
	bge _02213C62
	ldr r1, [sp, #4]
	add r1, #8
	str r1, [sp, #4]
	lsl r1, r1, #0xc
	cmp r0, r1
	bge _02213BEA
	ldr r0, [r5]
	cmp r0, r1
	bne _02213BEA
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213BEA:
	mov r0, #0xb7
	lsl r0, r0, #0xc
	str r0, [sp, #0xb0]
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0xa4]
	str r1, [sp, #0xac]
	str r1, [sp, #0xa0]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _02213CFA
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213C1A
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213C1A:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213C2E
	ldr r1, [r4]
	ldr r0, [sp, #0x94]
	cmp r1, r0
	blt _02213C2E
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213C2E:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213C52
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213C52
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213C52:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213C62:
	ldr r1, [sp, #4]
	mov r2, #0xf7
	sub r1, r2, r1
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _02213C82
	ldr r0, [r5]
	cmp r0, r1
	bne _02213C82
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213C82:
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0xb0]
	mov r0, #0xb7
	lsl r0, r0, #0xc
	str r0, [sp, #0xa4]
	str r1, [sp, #0xac]
	str r1, [sp, #0xa0]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _02213CFA
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213CB2
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213CB2:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213CC6
	ldr r1, [r4]
	ldr r0, [sp, #0x94]
	cmp r1, r0
	bgt _02213CC6
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213CC6:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213CEA
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213CEA
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213CEA:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213CFA:
	add r0, r6, #0
	add sp, #0xb8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02213728

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
	.public ov96_0220CBC0
	.public ov96_0220CBEC
	.public ov96_0220CC18
	.public ov96_0220CCBC
	.public ov96_0220D33C

	thumb_func_start ov96_0220C9A0
ov96_0220C9A0: ; 0x0220C9A0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x74]
	mov r6, #0
	cmp r0, #0
	bls _0220C9CA
	add r4, r5, #0
	add r4, #8
_0220C9B0:
	add r0, r4, #0
	bl ov96_0220CA28
	add r1, r0, #0
	ldr r2, [r5, #4]
	add r0, r4, #0
	bl ov96_0220CF50
	ldr r0, [r5, #0x74]
	add r6, r6, #1
	add r4, #0x24
	cmp r6, r0
	blo _0220C9B0
_0220C9CA:
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_0220C9A0




	thumb_func_start ov96_0220C9CC
ov96_0220C9CC: ; 0x0220C9CC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x74]
	mov r6, #0
	cmp r0, #0
	bls _0220C9F2
	add r4, r5, #0
	add r4, #8
	add r7, r6, #0
_0220C9DE:
	ldr r2, [r5, #4]
	add r0, r4, #0
	add r1, r7, #0
	bl ov96_0220CF50
	ldr r0, [r5, #0x74]
	add r6, r6, #1
	add r4, #0x24
	cmp r6, r0
	blo _0220C9DE
_0220C9F2:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220C9CC




	thumb_func_start ov96_0220C9F4
ov96_0220C9F4: ; 0x0220C9F4
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r6, r2, #0
	add r5, r0, #0
	mov r1, #0
	mov r2, #0x24
	bl MI_CpuFill8
	str r6, [r5]
	ldr r1, [r5, #0x18]
	ldr r0, _0220CA24 ; =0x3FFFFFFF
	add r2, r6, #0
	and r1, r0
	lsl r0, r4, #0x1e
	orr r0, r1
	str r0, [r5, #0x18]
	mov r0, #0x64
	str r0, [r5, #0x10]
	add r0, r5, #4
	add r1, r4, #0
	bl ov96_0220D200
	pop {r4, r5, r6, pc}
	nop
_0220CA24: .word 0x3FFFFFFF
	thumb_func_end ov96_0220C9F4




	thumb_func_start ov96_0220CA28
ov96_0220CA28: ; 0x0220CA28
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r5, _0220CABC ; =0x00000000
	bne _0220CA34
	bl GF_AssertFail
_0220CA34:
	ldr r0, [r4, #0x14]
	lsl r0, r0, #2
	lsr r0, r0, #0x1a
	cmp r0, #3
	bhi _0220CA7A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0220CA4A: ; jump table
	.short _0220CA52 - _0220CA4A - 2 ; case 0
	.short _0220CA5C - _0220CA4A - 2 ; case 1
	.short _0220CA66 - _0220CA4A - 2 ; case 2
	.short _0220CA70 - _0220CA4A - 2 ; case 3
_0220CA52:
	add r0, r4, #0
	bl ov96_0220CAC4
	add r5, r0, #0
	b _0220CA7E
_0220CA5C:
	add r0, r4, #0
	bl ov96_0220CBC0
	add r5, r0, #0
	b _0220CA7E
_0220CA66:
	add r0, r4, #0
	bl ov96_0220CC18
	add r5, r0, #0
	b _0220CA7E
_0220CA70:
	add r0, r4, #0
	bl ov96_0220CBEC
	add r5, r0, #0
	b _0220CA7E
_0220CA7A:
	bl GF_AssertFail
_0220CA7E:
	ldr r0, [r4, #0x14]
	lsl r0, r0, #2
	lsr r0, r0, #0x1a
	cmp r0, #3
	beq _0220CA8E
	add r0, r4, #0
	bl ov96_0220D07C
_0220CA8E:
	ldr r2, [r4, #0x14]
	ldr r1, [r4, #0x18]
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x15
	lsl r2, r2, #0x18
	add r0, r4, #4
	lsr r1, r1, #0x15
	lsr r2, r2, #0x18
	bl ov96_0220D2AC
	ldr r2, [r4, #0x18]
	ldr r1, _0220CAC0 ; =0xFFFFF800
	add r0, r2, #0
	lsl r2, r2, #0x15
	lsr r2, r2, #0x15
	and r0, r1
	add r2, r2, #1
	lsr r1, r1, #0x15
	and r1, r2
	orr r0, r1
	str r0, [r4, #0x18]
	add r0, r5, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0220CABC: .word 0x00000000
_0220CAC0: .word 0xFFFFF800
	thumb_func_end ov96_0220CA28




	thumb_func_start ov96_0220CAC4
ov96_0220CAC4: ; 0x0220CAC4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r2, [r5, #0x14]
	ldr r1, _0220CBB4 ; =0xFFFF00FF
	mov r4, #0
	and r1, r2
	lsl r2, r2, #0x10
	lsr r2, r2, #0x18
	add r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x10
	orr r1, r2
	str r1, [r5, #0x14]
	lsl r1, r1, #0x10
	lsr r2, r1, #0x18
	ldr r1, [r5, #0x18]
	lsl r1, r1, #2
	lsr r1, r1, #0x18
	cmp r2, r1
	blo _0220CB7E
	bl ov96_0220CD00
	cmp r0, #0
	beq _0220CB20
	add r0, r5, #0
	bl ov96_0220D0F8
	mov r0, #1
	str r0, [sp]
	ldr r1, [r5, #0x18]
	ldr r2, [r5, #0x14]
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	ldr r0, [r5]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #7
	bl ov96_021E8228
	add r0, r5, #0
	mov r1, #1
	bl ov96_0220CD84
	b _0220CB5C
_0220CB20:
	add r0, r5, #0
	bl ov96_0220CCBC
	cmp r0, #0
	beq _0220CB2C
	add r4, r4, #2
_0220CB2C:
	ldr r0, [r5, #0x1c]
	lsl r1, r0, #0x17
	lsr r1, r1, #0x1f
	beq _0220CB52
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #2
	blo _0220CB5C
	add r0, r5, #0
	bl ov96_0220CC38
	cmp r0, #0
	beq _0220CB5C
	mov r1, #2
	add r0, r5, #0
	and r1, r4
	bl ov96_0220CE04
	b _0220CB5C
_0220CB52:
	mov r1, #2
	add r0, r5, #0
	and r1, r4
	bl ov96_0220CE04
_0220CB5C:
	ldr r1, [r5, #0x14]
	ldr r0, _0220CBB4 ; =0xFFFF00FF
	and r0, r1
	str r0, [r5, #0x14]
	bl MTRandom
	mov r1, #3
	bl _u32_div_f
	ldr r2, [r5, #0x18]
	ldr r0, _0220CBB8 ; =0xC03FFFFF
	and r2, r0
	add r0, r1, #4
	lsl r0, r0, #0x18
	lsr r0, r0, #2
	orr r0, r2
	str r0, [r5, #0x18]
_0220CB7E:
	ldr r3, [r5, #0x1c]
	lsl r0, r3, #0x17
	lsr r0, r0, #0x1f
	beq _0220CBB0
	add r0, r3, #0
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	add r3, r3, #1
	mov r2, #0xff
	lsl r3, r3, #0x18
	bic r0, r2
	lsr r3, r3, #0x18
	orr r0, r3
	str r0, [r5, #0x1c]
	lsl r0, r0, #0x18
	add r1, r5, #0
	lsr r0, r0, #0x18
	add r1, #0x1c
	cmp r0, #0xa
	blo _0220CBB0
	ldr r3, [r1]
	ldr r0, _0220CBBC ; =0xFFFFFEFF
	bic r3, r2
	and r0, r3
	str r0, [r1]
_0220CBB0:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0220CBB4: .word 0xFFFF00FF
_0220CBB8: .word 0xC03FFFFF
_0220CBBC: .word 0xFFFFFEFF
	thumb_func_end ov96_0220CAC4

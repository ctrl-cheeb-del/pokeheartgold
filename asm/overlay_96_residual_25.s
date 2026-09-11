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

	thumb_func_start ov96_021EAC0C
ov96_021EAC0C: ; 0x021EAC0C
	push {r4, lr}
	add r4, r1, #0
	str r4, [r0, #0x34]
	beq _021EAC5A
	ldr r0, [r0]
	bl ov96_021E8BAC
	cmp r4, #6
	bhi _021EAC50
	add r1, r4, r4
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021EAC2A: ; jump table
	.short _021EAC50 - _021EAC2A - 2 ; case 0
	.short _021EAC38 - _021EAC2A - 2 ; case 1
	.short _021EAC3C - _021EAC2A - 2 ; case 2
	.short _021EAC40 - _021EAC2A - 2 ; case 3
	.short _021EAC44 - _021EAC2A - 2 ; case 4
	.short _021EAC48 - _021EAC2A - 2 ; case 5
	.short _021EAC4C - _021EAC2A - 2 ; case 6
_021EAC38:
	mov r1, #0
	b _021EAC56
_021EAC3C:
	mov r1, #1
	b _021EAC56
_021EAC40:
	mov r1, #2
	b _021EAC56
_021EAC44:
	mov r1, #3
	b _021EAC56
_021EAC48:
	mov r1, #4
	b _021EAC56
_021EAC4C:
	mov r1, #8
	b _021EAC56
_021EAC50:
	bl GF_AssertFail
	pop {r4, pc}
_021EAC56:
	bl Sprite_TryChangeAnimSeq
_021EAC5A:
	pop {r4, pc}
	thumb_func_end ov96_021EAC0C


	thumb_func_start ov96_021EAC5C
ov96_021EAC5C: ; 0x021EAC5C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	bl ov96_021E8BAC
	cmp r4, #8
	bgt _021EAC7E
	bge _021EACAE
	cmp r4, #4
	bgt _021EAD04
	cmp r4, #0
	blt _021EAD04
	beq _021EACAE
	cmp r4, #4
	beq _021EACAE
	pop {r3, r4, r5, pc}
_021EAC7E:
	cmp r4, #0x16
	bgt _021EACAA
	add r1, r4, #0
	sub r1, #0xc
	bmi _021EAD04
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021EAC94: ; jump table
	.short _021EACAE - _021EAC94 - 2 ; case 0
	.short _021EACB2 - _021EAC94 - 2 ; case 1
	.short _021EACB2 - _021EAC94 - 2 ; case 2
	.short _021EACB2 - _021EAC94 - 2 ; case 3
	.short _021EACAE - _021EAC94 - 2 ; case 4
	.short _021EACB2 - _021EAC94 - 2 ; case 5
	.short _021EACB2 - _021EAC94 - 2 ; case 6
	.short _021EACB2 - _021EAC94 - 2 ; case 7
	.short _021EACAE - _021EAC94 - 2 ; case 8
	.short _021EACAE - _021EAC94 - 2 ; case 9
	.short _021EACAE - _021EAC94 - 2 ; case 10
_021EACAA:
	cmp r4, #0x1a
	bne _021EAD04
_021EACAE:
	str r4, [r5, #0x38]
	b _021EACB4
_021EACB2:
	pop {r3, r4, r5, pc}
_021EACB4:
	cmp r4, #0x14
	beq _021EACFC
	cmp r4, #0x15
	beq _021EACFC
	ldr r1, [r5, #0x34]
	cmp r1, #4
	bhi _021EACF6
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021EACCE: ; jump table
	.short _021EACF6 - _021EACCE - 2 ; case 0
	.short _021EACD8 - _021EACCE - 2 ; case 1
	.short _021EACDE - _021EACCE - 2 ; case 2
	.short _021EACE6 - _021EACCE - 2 ; case 3
	.short _021EACEE - _021EACCE - 2 ; case 4
_021EACD8:
	lsl r1, r4, #0x18
	lsr r1, r1, #0x18
	b _021EAD00
_021EACDE:
	add r1, r4, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	b _021EAD00
_021EACE6:
	add r1, r4, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	b _021EAD00
_021EACEE:
	add r1, r4, #3
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	b _021EAD00
_021EACF6:
	bl GF_AssertFail
	pop {r3, r4, r5, pc}
_021EACFC:
	lsl r1, r4, #0x18
	lsr r1, r1, #0x18
_021EAD00:
	bl Sprite_TryChangeAnimSeq
_021EAD04:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021EAC5C


	thumb_func_start ov96_021EAD08
ov96_021EAD08: ; 0x021EAD08
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, [r4]
	add r5, r1, #0
	bl ov96_021E8BAC
	cmp r5, #0
	beq _021EAD22
	cmp r5, #0x14
	beq _021EAD28
	cmp r5, #0x15
	beq _021EAD2E
	pop {r3, r4, r5, pc}
_021EAD22:
	mov r1, #0
	str r1, [r4, #0x38]
	b _021EAD32
_021EAD28:
	mov r1, #4
	str r1, [r4, #0x38]
	b _021EAD32
_021EAD2E:
	mov r1, #5
	str r1, [r4, #0x38]
_021EAD32:
	cmp r5, #0x14
	beq _021EAD6C
	cmp r5, #0x15
	beq _021EAD6C
	ldr r1, [r4, #0x34]
	cmp r1, #4
	bhi _021EAD66
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021EAD4C: ; jump table
	.short _021EAD66 - _021EAD4C - 2 ; case 0
	.short _021EAD56 - _021EAD4C - 2 ; case 1
	.short _021EAD5A - _021EAD4C - 2 ; case 2
	.short _021EAD5E - _021EAD4C - 2 ; case 3
	.short _021EAD62 - _021EAD4C - 2 ; case 4
_021EAD56:
	mov r1, #0
	b _021EAD72
_021EAD5A:
	mov r1, #1
	b _021EAD72
_021EAD5E:
	mov r1, #2
	b _021EAD72
_021EAD62:
	mov r1, #3
	b _021EAD72
_021EAD66:
	bl GF_AssertFail
	pop {r3, r4, r5, pc}
_021EAD6C:
	ldr r1, [r4, #0x38]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
_021EAD72:
	bl Sprite_TryChangeAnimSeq
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021EAD08

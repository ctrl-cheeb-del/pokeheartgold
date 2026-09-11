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

	thumb_func_start ov96_02218A68
ov96_02218A68: ; 0x02218A68
	push {r4, lr}
	sub sp, #0x18
	add r4, r0, #0
	ldr r0, [r4, #0x60]
	ldr r1, _02218AD8 ; =ov96_0221D6E4
	lsl r0, r0, #0xa
	lsr r0, r0, #0x1e
	lsl r2, r0, #2
	add r0, sp, #4
	str r0, [sp]
	ldr r0, [r4, #4]
	ldr r3, _02218ADC ; =ov96_0221D6E6
	ldrsh r1, [r1, r2]
	ldrsh r2, [r3, r2]
	ldr r0, [r0]
	add r3, sp, #8
	bl ov96_021EB0A4
	ldr r0, [sp, #8]
	add r2, r4, #0
	lsl r0, r0, #0xc
	str r0, [r4, #0x2c]
	ldr r0, [sp, #4]
	add r3, sp, #0xc
	lsl r0, r0, #0xc
	str r0, [r4, #0x30]
	ldr r0, [sp, #8]
	add r2, #0x44
	lsl r0, r0, #0xc
	str r0, [r4, #0x20]
	ldr r0, [sp, #4]
	lsl r0, r0, #0xc
	str r0, [r4, #0x24]
	mov r0, #0
	str r0, [r3]
	str r0, [r3, #4]
	str r0, [r3, #8]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r1, [r4, #0x60]
	ldr r0, _02218AE0 ; =0xFFF0FFFF
	and r1, r0
	mov r0, #2
	lsl r0, r0, #0x10
	orr r1, r0
	ldr r0, _02218AE4 ; =0xF7FFFFFF
	and r1, r0
	ldr r0, _02218AE8 ; =0xDFFFFFFF
	and r1, r0
	ldr r0, _02218AEC ; =0xBFFFFFFF
	and r0, r1
	str r0, [r4, #0x60]
	add sp, #0x18
	pop {r4, pc}
	.balign 4, 0
_02218AD8: .word ov96_0221D6E4
_02218ADC: .word ov96_0221D6E6
_02218AE0: .word 0xFFF0FFFF
_02218AE4: .word 0xF7FFFFFF
_02218AE8: .word 0xDFFFFFFF
_02218AEC: .word 0xBFFFFFFF
	thumb_func_end ov96_02218A68


	thumb_func_start ov96_02218AF0
ov96_02218AF0: ; 0x02218AF0
	ldr r1, [r0, #0x14]
	sub r1, #9
	cmp r1, #2
	bls _02218B1A
	ldr r2, [r0, #0x50]
	cmp r2, #0
	bgt _02218B04
	mov r1, #0
	str r1, [r0, #0x54]
	bx lr
_02218B04:
	ldr r1, [r0, #0x54]
	sub r1, r2, r1
	str r1, [r0, #0x50]
	bpl _02218B10
	mov r1, #0
	str r1, [r0, #0x50]
_02218B10:
	mov r1, #2
	ldr r2, [r0, #0x54]
	lsl r1, r1, #0xc
	add r1, r2, r1
	str r1, [r0, #0x54]
_02218B1A:
	bx lr
	thumb_func_end ov96_02218AF0


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


	thumb_func_start ov96_02218EB8
ov96_02218EB8: ; 0x02218EB8
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldr r0, [r4, #0x14]
	mov r1, #1
	cmp r0, #7
	beq _02218ECC
	cmp r0, #6
	beq _02218ECC
	mov r1, #0
_02218ECC:
	cmp r1, #0
	bne _02218ED4
	bl GF_AssertFail
_02218ED4:
	add r3, sp, #0
	mov r0, #0
	str r0, [r3]
	str r0, [r3, #4]
	str r0, [r3, #8]
	add r2, r4, #0
	ldmia r3!, {r0, r1}
	add r2, #0x44
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r3, r4, #0
	str r0, [r2]
	add r3, #0x2c
	add r2, r4, #0
	ldmia r3!, {r0, r1}
	add r2, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #1
	str r0, [r2]
	add r0, r4, #0
	bl ov96_02218578
	add r0, r4, #0
	bl ov96_02218934
	cmp r0, #0
	beq _02218F12
	add r0, r4, #0
	bl ov96_02219030
_02218F12:
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02218EB8


	thumb_func_start ov96_02218F18
ov96_02218F18: ; 0x02218F18
	push {r4, lr}
	sub sp, #0x18
	add r4, r0, #0
	add r2, sp, #0
	mov r0, #0
	str r0, [r2]
	str r0, [r2, #4]
	str r0, [r2, #8]
	add r1, r4, #0
	ldr r0, _02218F54 ; =0x00000B33
	add r1, #0x38
	add r3, sp, #0xc
	bl VEC_MultAdd
	add r0, r4, #0
	add r0, #0x44
	add r1, sp, #0xc
	add r2, r0, #0
	bl VEC_Add
	add r0, r4, #0
	add r0, #0x2c
	add r4, #0x44
	add r1, r4, #0
	add r2, r0, #0
	bl VEC_Add
	add sp, #0x18
	pop {r4, pc}
	nop
_02218F54: .word 0x00000B33
	thumb_func_end ov96_02218F18


	thumb_func_start ov96_02218F58
ov96_02218F58: ; 0x02218F58
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x14]
	mov r1, #1
	cmp r0, #1
	beq _02218F6C
	cmp r0, #4
	beq _02218F6C
	mov r1, #0
_02218F6C:
	cmp r1, #0
	bne _02218F74
	bl GF_AssertFail
_02218F74:
	ldr r0, [r4, #0x60]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	beq _02218F80
	bl GF_AssertFail
_02218F80:
	ldr r0, [r4, #0x60]
	lsl r0, r0, #5
	lsr r0, r0, #0x1f
	beq _02218F8C
	bl GF_AssertFail
_02218F8C:
	ldr r1, [r4, #0x60]
	ldr r0, _02218FD0 ; =0xDFFFFFFF
	and r0, r1
	str r0, [r4, #0x60]
	add r0, r4, #0
	mov r1, #5
	add r0, #0x5a
	strb r1, [r0]
	ldr r0, [r4, #4]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x18]
	cmp r0, #0
	beq _02218FC4
	mov r0, #1
	str r0, [sp]
	ldr r2, [r4, #0x60]
	ldr r0, [r4]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #2
	bl ov96_021E8228
_02218FC4:
	add r0, r4, #0
	mov r1, #8
	bl ov96_02218578
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02218FD0: .word 0xDFFFFFFF
	thumb_func_end ov96_02218F58


	thumb_func_start ov96_02218FD4
ov96_02218FD4: ; 0x02218FD4
	push {r4, lr}
	add r4, r0, #0
	mov r1, #0xc
	bl ov96_02218578
	add r0, r4, #0
	add r2, r4, #0
	mov r1, #0xa
	add r0, #0x5a
	strb r1, [r0]
	mov r0, #0
	str r0, [r4, #0x50]
	add r2, #0x2c
	ldmia r2!, {r0, r1}
	add r4, #0x20
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	str r0, [r4]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02218FD4


	thumb_func_start ov96_02218FFC
ov96_02218FFC: ; 0x02218FFC
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #4]
	ldr r0, [r1, #8]
	ldr r1, [r1, #4]
	ldr r1, [r1, #8]
	bl FX_Div
	mov r1, #1
	lsl r1, r1, #0xc
	sub r1, r1, r0
	mov r0, #0xa
	mul r0, r1
	sub r0, r0, #3
	bpl _0221901C
	mov r0, #0
_0221901C:
	asr r1, r0, #0xc
	add r0, r4, #0
	add r0, #0x58
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #2
	bl ov96_02218578
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02218FFC


	thumb_func_start ov96_02219030
ov96_02219030: ; 0x02219030
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	mov r1, #0x3c
	add r0, #0x5b
	strb r1, [r0]
	add r0, r4, #0
	mov r2, #0
	add r0, #0x58
	strb r2, [r0]
	ldr r1, [r4, #0x10]
	cmp r1, #0
	bne _02219084
	ldr r0, [r4, #0x60]
	lsl r0, r0, #0x14
	lsr r3, r0, #0x14
	sub r3, #0xa
	bpl _02219056
	add r3, r2, #0
_02219056:
	ldr r1, [r4, #0x60]
	ldr r0, _02219108 ; =0xFFFFF000
	and r1, r0
	lsr r0, r0, #0x14
	and r0, r3
	orr r0, r1
	str r0, [r4, #0x60]
	mov r0, #1
	str r0, [sp]
	ldr r2, [r4, #0x60]
	ldr r0, [r4]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #8
	bl ov96_021E8228
	b _022190C2
_02219084:
	ldr r0, [r1, #0x60]
	lsl r0, r0, #0x14
	lsr r3, r0, #0x14
	add r3, #0xa
	cmp r3, #0xc8
	ble _02219092
	mov r3, #0xc8
_02219092:
	ldr r2, [r1, #0x60]
	ldr r0, _02219108 ; =0xFFFFF000
	and r2, r0
	lsr r0, r0, #0x14
	and r0, r3
	orr r0, r2
	str r0, [r1, #0x60]
	mov r0, #1
	str r0, [sp]
	ldr r2, [r1, #0x60]
	ldr r0, [r1]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #3
	bl ov96_021E8228
	mov r0, #0
	str r0, [r4, #0x10]
_022190C2:
	mov r0, #1
	str r0, [sp]
	ldr r2, [r4, #0x60]
	ldr r0, [r4]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #5
	bl ov96_021E8228
	mov r3, #1
	str r3, [sp]
	ldr r2, [r4, #0x60]
	ldr r0, [r4]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021E8228
	add r0, r4, #0
	mov r1, #3
	bl ov96_02218578
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02219108: .word 0xFFFFF000
	thumb_func_end ov96_02219030


	thumb_func_start ov96_0221910C
ov96_0221910C: ; 0x0221910C
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #0x60]
	lsl r0, r0, #5
	lsr r0, r0, #0x1f
	beq _0221911E
	bl GF_AssertFail
_0221911E:
	ldr r0, [r4, #0x60]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	beq _0221912A
	bl GF_AssertFail
_0221912A:
	ldr r1, [r4, #0x60]
	mov r0, #1
	add r2, r1, #0
	lsl r0, r0, #0x1a
	orr r2, r0
	ldr r1, _02219170 ; =0xFCFFFFFF
	add r3, r4, #0
	and r1, r2
	lsr r0, r0, #2
	orr r0, r1
	add r2, r4, #0
	add r3, #0x2c
	str r0, [r4, #0x60]
	ldmia r3!, {r0, r1}
	add r2, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r3, #7
	str r0, [r2]
	mov r0, #1
	str r0, [sp]
	ldr r2, [r4, #0x60]
	ldr r0, [r4]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021E8228
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02219170: .word 0xFCFFFFFF
	thumb_func_end ov96_0221910C


	thumb_func_start ov96_02219174
ov96_02219174: ; 0x02219174
	ldr r3, [r0, #4]
	ldr r2, [r3, #8]
	sub r1, r2, r1
	str r1, [r3, #8]
	ldr r1, [r0, #4]
	ldr r0, [r1, #8]
	cmp r0, #0
	bge _02219188
	mov r0, #0
	str r0, [r1, #8]
_02219188:
	bx lr
	.balign 4, 0
	thumb_func_end ov96_02219174


	thumb_func_start ov96_0221918C
ov96_0221918C: ; 0x0221918C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x84
	str r0, [sp]
	mov r0, #0
	add r3, sp, #0xc
	add r1, r0, #0
	mov r2, #7
_0221919A:
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0221919A
	stmia r3!, {r0, r1}
	add r0, sp, #0xc
	mov r1, #0xaa
	mov r2, #9
	bl ReadWholeNarcMemberByIdPair
	mov r0, #0
	str r0, [sp, #4]
_022191B2:
	ldr r0, [sp, #4]
	mov r6, #0x3f
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r7, #0
	lsl r6, r6, #0x18
	str r0, [sp, #8]
_022191C0:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	add r2, r7, #0
	bl ov96_021E60D8
	add r4, r0, #0
	lsl r2, r7, #0x18
	ldr r0, [sp]
	ldr r1, [sp, #8]
	lsr r2, r2, #0x18
	bl ov96_0221935C
	add r5, r0, #0
	ldrb r0, [r4]
	cmp r0, #5
	blo _022191E4
	bl GF_AssertFail
_022191E4:
	ldrb r0, [r4, #3]
	cmp r0, #5
	blo _022191EE
	bl GF_AssertFail
_022191EE:
	ldrb r0, [r4, #1]
	cmp r0, #5
	blo _022191F8
	bl GF_AssertFail
_022191F8:
	ldrb r0, [r4, #2]
	cmp r0, #5
	blo _02219202
	bl GF_AssertFail
_02219202:
	ldrb r0, [r4]
	lsl r1, r0, #2
	add r0, sp, #0xc
	ldr r0, [r0, r1]
	cmp r0, #0
	ble _0221921E
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r6, #0
	bl _fadd
	b _0221922A
_0221921E:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r6, #0
	bl _fsub
_0221922A:
	bl _ffix
	mov r1, #0xa
	bl _s32_div_f
	str r0, [r5]
	ldrb r0, [r4]
	lsl r1, r0, #2
	add r0, sp, #0xc
	add r0, r0, r1
	ldr r0, [r0, #0x14]
	cmp r0, #0
	ble _02219254
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r6, #0
	bl _fadd
	b _02219260
_02219254:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r6, #0
	bl _fsub
_02219260:
	bl _ffix
	mov r1, #0xa
	bl _s32_div_f
	str r0, [r5, #4]
	ldrb r0, [r4, #3]
	lsl r1, r0, #2
	add r0, sp, #0xc
	add r0, r0, r1
	ldr r0, [r0, #0x28]
	cmp r0, #0
	ble _0221928A
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r6, #0
	bl _fadd
	b _02219296
_0221928A:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r6, #0
	bl _fsub
_02219296:
	bl _ffix
	str r0, [r5, #8]
	ldrb r0, [r4, #1]
	lsl r1, r0, #2
	add r0, sp, #0xc
	add r0, r0, r1
	ldr r0, [r0, #0x3c]
	cmp r0, #0
	ble _022192BA
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r6, #0
	bl _fadd
	b _022192C6
_022192BA:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r6, #0
	bl _fsub
_022192C6:
	bl _ffix
	mov r1, #0xa
	bl _s32_div_f
	str r0, [r5, #0xc]
	ldrb r0, [r4, #2]
	lsl r1, r0, #2
	add r0, sp, #0xc
	add r0, r0, r1
	ldr r0, [r0, #0x64]
	cmp r0, #0
	ble _022192F0
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r6, #0
	bl _fadd
	b _022192FC
_022192F0:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r6, #0
	bl _fsub
_022192FC:
	bl _ffix
	mov r1, #0xa
	bl _s32_div_f
	str r0, [r5, #0x10]
	ldrb r0, [r4, #2]
	lsl r1, r0, #2
	add r0, sp, #0xc
	add r0, r0, r1
	ldr r0, [r0, #0x64]
	cmp r0, #0
	ble _02219326
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r6, #0
	bl _fadd
	b _02219332
_02219326:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r6, #0
	bl _fsub
_02219332:
	bl _ffix
	mov r1, #0xa
	bl _s32_div_f
	str r0, [r5, #0x14]
	ldrb r0, [r4, #2]
	add r7, r7, #1
	cmp r7, #3
	strb r0, [r5, #0x18]
	bge _0221934A
	b _022191C0
_0221934A:
	ldr r0, [sp, #4]
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #4
	bge _02219356
	b _022191B2
_02219356:
	add sp, #0x84
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221918C


	thumb_func_start ov96_0221935C
ov96_0221935C: ; 0x0221935C
	push {r4, r5, r6, lr}
	add r5, r1, #0
	add r6, r2, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	bne _0221936E
	bl GF_AssertFail
_0221936E:
	cmp r5, #4
	blo _02219376
	bl GF_AssertFail
_02219376:
	cmp r6, #3
	blo _0221937E
	bl GF_AssertFail
_0221937E:
	lsl r0, r5, #1
	add r0, r5, r0
	add r1, r6, r0
	mov r0, #0x1c
	add r4, #0x30
	mul r0, r1
	add r4, r4, r0
	bne _02219392
	bl GF_AssertFail
_02219392:
	add r0, r4, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_0221935C


	thumb_func_start ov96_02219398
ov96_02219398: ; 0x02219398
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x60]
	mov r1, #3
	lsl r0, r0, #8
	lsr r0, r0, #0x1e
	add r0, r0, #1
	bl _u32_div_f
	ldr r2, [r4, #0x60]
	ldr r0, _022193C8 ; =0xFF3FFFFF
	and r2, r0
	lsl r0, r1, #0x1e
	lsr r0, r0, #8
	orr r0, r2
	str r0, [r4, #0x60]
	ldr r1, [r4, #8]
	lsl r0, r0, #8
	lsr r0, r0, #0x1e
	add r1, #0x74
	lsl r0, r0, #4
	add r0, r1, r0
	str r0, [r4, #4]
	pop {r4, pc}
	.balign 4, 0
_022193C8: .word 0xFF3FFFFF
	thumb_func_end ov96_02219398


	thumb_func_start ov96_022193CC
ov96_022193CC: ; 0x022193CC
	cmp r1, #0
	beq _022193D4
	mov r1, #3
	b _022193D6
_022193D4:
	mov r1, #4
_022193D6:
	ldr r3, _022193E0 ; =sub_0200606C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bx r3
	nop
_022193E0: .word sub_0200606C
	thumb_func_end ov96_022193CC

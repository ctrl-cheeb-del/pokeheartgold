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


	thumb_func_start ov96_021FA83C
ov96_021FA83C: ; 0x021FA83C
	push {r3, r4, r5, r6, lr}
	sub sp, #0x24
	add r4, r1, #0
	add r5, r0, #0
	ldr r0, [r4, #4]
	cmp r0, #3
	bhi _021FA8F2
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021FA856: ; jump table
	.short _021FAA64 - _021FA856 - 2 ; case 0
	.short _021FA85E - _021FA856 - 2 ; case 1
	.short _021FA9AE - _021FA856 - 2 ; case 2
	.short _021FAA1E - _021FA856 - 2 ; case 3
_021FA85E:
	ldrb r0, [r4, #0xc]
	add r0, r0, #1
	strb r0, [r4, #0xc]
	ldr r0, [r4, #8]
	cmp r0, #1
	beq _021FA874
	cmp r0, #2
	beq _021FA8D8
	cmp r0, #3
	beq _021FA912
	b _021FA9A8
_021FA874:
	add r0, r4, #0
	add r0, #0x34
	ldrb r0, [r0]
	ldr r3, _021FAAC8 ; =ov96_0221C55C
	lsl r1, r0, #3
	add r5, r0, r1
	ldrb r1, [r4, #0xc]
	sub r2, r1, #1
	add r1, r3, r5
	ldrsb r1, [r2, r1]
	ldr r2, [r4, #0x14]
	sub r5, r2, r1
	cmp r0, #0
	bne _021FA8A4
	add r0, r4, #0
	mov r1, #0
	bl ov96_021FB8FC
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	add r2, r5, #0
	bl ov96_021EAE4C
	b _021FA8B6
_021FA8A4:
	add r0, r4, #0
	bl ov96_021FB8B4
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	add r2, r5, #0
	mov r3, #0
	bl ov96_021EAD88
_021FA8B6:
	ldrb r1, [r4, #0xc]
	ldrh r0, [r4, #0x38]
	cmp r1, r0
	blt _021FA8F2
	mov r0, #2
	str r0, [r4, #8]
	mov r1, #0
	add r0, r4, #0
	strb r1, [r4, #0xc]
	add r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FA8F2
	ldr r0, [r4]
	bl ov96_021EAB94
	b _021FAA6A
_021FA8D8:
	ldrb r1, [r4, #0xc]
	ldrh r0, [r4, #0x3a]
	cmp r1, r0
	blt _021FA8F2
	mov r0, #3
	str r0, [r4, #8]
	mov r0, #0
	strb r0, [r4, #0xc]
	add r0, r4, #0
	add r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FA8F4
_021FA8F2:
	b _021FAA6A
_021FA8F4:
	ldr r0, [r4]
	mov r1, #1
	bl ov96_021EAB94
	ldr r6, _021FAACC ; =ov96_0221DC2C
	ldr r0, _021FAAD0 ; =0x000008AA
	ldrb r1, [r6, r5]
	bl sub_0200606C
	ldr r1, _021FAAD4 ; =ov96_0221DC28
	ldrb r0, [r6, r5]
	ldrsb r1, [r1, r5]
	bl sub_020061D0
	b _021FAA6A
_021FA912:
	add r0, r4, #0
	add r0, #0x34
	ldrb r0, [r0]
	ldr r3, _021FAAD8 ; =ov96_0221C589
	lsl r1, r0, #3
	add r6, r0, r1
	ldrb r1, [r4, #0xc]
	sub r2, r1, #1
	add r1, r3, r6
	ldrsb r1, [r2, r1]
	ldr r2, [r4, #0x14]
	sub r6, r2, r1
	cmp r0, #0
	bne _021FA942
	add r0, r4, #0
	mov r1, #1
	bl ov96_021FB8FC
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	add r2, r6, #0
	bl ov96_021EAE4C
	b _021FA954
_021FA942:
	add r0, r4, #0
	bl ov96_021FB8B4
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	add r2, r6, #0
	mov r3, #0
	bl ov96_021EAD88
_021FA954:
	ldrh r0, [r4, #0x38]
	ldrb r1, [r4, #0xc]
	cmp r1, r0
	blt _021FA99C
	mov r3, #0
	str r3, [r4, #4]
	str r3, [r4, #8]
	strb r3, [r4, #0xc]
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	ldr r2, [r4, #0x14]
	bl ov96_021EAD88
	add r0, r4, #0
	add r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FA98C
	ldr r6, _021FAACC ; =ov96_0221DC2C
	ldr r0, _021FAADC ; =0x000008A8
	ldrb r1, [r6, r5]
	bl sub_0200606C
	ldr r1, _021FAAD4 ; =ov96_0221DC28
	ldrb r0, [r6, r5]
	ldrsb r1, [r1, r5]
	bl sub_020061D0
_021FA98C:
	add r0, r4, #0
	mov r1, #0
	bl ov96_021FB8B4
	mov r0, #0
	strh r0, [r4, #0x3c]
	strh r0, [r4, #0x3e]
	b _021FAA6A
_021FA99C:
	sub r0, r0, #5
	cmp r1, r0
	bge _021FAA6A
	mov r0, #0
	strh r0, [r4, #0x3c]
	b _021FAA6A
_021FA9A8:
	bl GF_AssertFail
	b _021FAA6A
_021FA9AE:
	ldrb r0, [r4, #0xc]
	add r0, r0, #1
	strb r0, [r4, #0xc]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _021FA9F4
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bhi _021FA9EC
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021FA9CC: ; jump table
	.short _021FA9EC - _021FA9CC - 2 ; case 0
	.short _021FA9D6 - _021FA9CC - 2 ; case 1
	.short _021FA9E2 - _021FA9CC - 2 ; case 2
	.short _021FA9DC - _021FA9CC - 2 ; case 3
	.short _021FA9E8 - _021FA9CC - 2 ; case 4
_021FA9D6:
	mov r0, #3
	strb r0, [r4, #0xe]
	b _021FA9EC
_021FA9DC:
	mov r0, #2
	strb r0, [r4, #0xe]
	b _021FA9EC
_021FA9E2:
	mov r0, #4
	strb r0, [r4, #0xe]
	b _021FA9EC
_021FA9E8:
	mov r0, #1
	strb r0, [r4, #0xe]
_021FA9EC:
	ldrb r1, [r4, #0xe]
	ldr r0, [r4]
	bl ov96_021EAC0C
_021FA9F4:
	ldrb r0, [r4, #0xd]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xc]
	cmp r0, #0x1e
	bls _021FAA6A
	mov r0, #0
	strb r0, [r4, #0xc]
	str r0, [r4, #4]
	str r0, [r4, #8]
	ldr r0, [r4]
	mov r1, #1
	bl ov96_021EAC0C
	b _021FAA6A
_021FAA1E:
	ldr r1, [r4, #0x18]
	mov r0, #0
	cmp r1, #0x78
	bge _021FAA36
	add r0, r1, #1
	mov r2, #1
	cmp r0, #0x78
	ble _021FAA32
	add r2, r1, #0
	sub r2, #0x78
_021FAA32:
	mov r0, #1
	b _021FAA46
_021FAA36:
	ble _021FAA46
	sub r2, r0, #1
	sub r0, r1, #1
	cmp r0, #0x78
	bge _021FAA44
	mov r0, #0x78
	sub r2, r0, r1
_021FAA44:
	mov r0, #1
_021FAA46:
	cmp r0, #0
	beq _021FAA6A
	ldr r0, [r4, #0x18]
	mov r3, #1
	add r0, r0, r2
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x1c]
	mov r1, #0
	add r0, r0, r2
	str r0, [r4, #0x1c]
	str r3, [sp]
	ldr r0, [r4]
	bl ov96_021EAED4
	b _021FAA6A
_021FAA64:
	mov r0, #0
	strh r0, [r4, #0x3c]
	strh r0, [r4, #0x3e]
_021FAA6A:
	ldr r0, [r4, #0x20]
	bl ov96_021EB5B8
	add r5, r0, #0
	bl Sprite_GetMatrixPtr
	add r6, r0, #0
	add r3, sp, #0x18
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r4, #0x1c]
	lsl r0, r0, #0xc
	str r0, [sp, #0x1c]
	add r0, r5, #0
	bl Sprite_SetMatrix
	ldr r0, [r4]
	add r1, sp, #8
	add r2, sp, #4
	bl ov96_021EAE9C
	ldr r0, [r4, #0x28]
	bl ov96_021EB5B8
	add r4, r0, #0
	bl Sprite_GetMatrixPtr
	add r5, r0, #0
	add r3, sp, #0xc
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [sp, #4]
	lsl r0, r0, #0xc
	str r0, [sp, #0x10]
	add r0, r4, #0
	bl Sprite_SetMatrix
	add sp, #0x24
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021FAAC8: .word ov96_0221C55C
_021FAACC: .word ov96_0221DC2C
_021FAAD0: .word 0x000008AA
_021FAAD4: .word ov96_0221DC28
_021FAAD8: .word ov96_0221C589
_021FAADC: .word 0x000008A8
	thumb_func_end ov96_021FA83C

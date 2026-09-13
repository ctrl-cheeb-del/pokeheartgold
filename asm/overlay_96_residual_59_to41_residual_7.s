	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text
	.public ov96_021F6600
	.extern ov96_021F6060
	.extern ov96_021F64A0
	.extern ov96_021F65D8
	.extern ov96_021F6B28
	.extern ov96_021F6BE4
	.extern ov96_021F7130

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


	thumb_func_start ov96_021F6600
ov96_021F6600: ; 0x021F6600
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	str r0, [sp, #8]
	add r5, r1, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	mov r4, #0
_021F6614:
	lsl r2, r4, #0x18
	ldr r0, [sp, #8]
	add r1, r5, #0
	lsr r2, r2, #0x18
	bl ov96_021F6798
	add r4, r4, #1
	cmp r4, #3
	blt _021F6614
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r5, #0
	str r0, [sp, #0x14]
	add r0, #0x90
	ldr r7, _021F6780 ; =ov96_0221DC18
	str r5, [sp, #0x1c]
	str r5, [sp, #0x18]
	str r0, [sp, #0x14]
_021F6638:
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x1c]
	add r0, #0x90
	ldr r4, [r0]
	add r0, sp, #0x24
	str r0, [sp]
	add r1, #0xac
	ldr r2, [r1]
	ldr r3, _021F6784 ; =0x00000FB4
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r2, [sp, #0x18]
	add r0, r4, #0
	ldr r2, [r2, r3]
	asr r1, r1, #0xc
	lsl r3, r2, #6
	mov r2, #0x12
	lsl r2, r2, #0x10
	sub r2, r2, r3
	asr r3, r2, #0xb
	lsr r3, r3, #0x14
	add r3, r2, r3
	asr r2, r3, #0xc
	add r3, sp, #0x28
	bl ov96_021EB0A4
	add r0, sp, #0x34
	str r0, [sp]
	add r0, sp, #0x2c
	str r0, [sp, #4]
	ldr r1, [sp, #0x28]
	ldr r2, [sp, #0x24]
	add r0, r4, #0
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x30
	bl ov96_021EAF78
	ldr r0, [sp, #0xc]
	mov r4, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r4, [sp, #0x38]
	str r0, [sp, #0x20]
_021F6692:
	add r0, r5, #0
	add r0, #0x8c
	lsl r1, r4, #0x18
	ldr r0, [r0]
	lsr r1, r1, #0x18
	bl ov96_021F75E0
	cmp r0, #0
	beq _021F671C
	add r0, r5, #0
	add r0, #0x8c
	lsl r1, r4, #0x18
	ldr r0, [r0]
	lsr r1, r1, #0x18
	bl ov96_021F75D4
	ldr r1, [sp, #0x2c]
	mov r3, #2
	add r2, r0, #0
	add r0, sp, #0x30
	lsl r1, r1, #0xc
	lsl r3, r3, #0xe
	bl ov96_021F6060
	cmp r0, #0
	beq _021F671C
	add r0, r5, #0
	add r0, #0x8c
	lsl r1, r4, #0x18
	ldr r0, [r0]
	lsr r1, r1, #0x18
	bl ov96_021F75BC
	ldr r0, [sp, #0x14]
	bl ov96_021F65D8
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0x8c
	lsl r1, r4, #0x18
	ldr r0, [r0]
	lsr r1, r1, #0x18
	add r2, r6, #0
	bl ov96_021F75E8
	ldr r0, _021F6788 ; =0x00000142
	mov r1, #1
	strb r1, [r5, r0]
	ldrb r1, [r7]
	ldr r0, _021F678C ; =0x0000088D
	bl sub_0200606C
	ldr r2, _021F6790 ; =ov96_0221C110
	lsl r3, r6, #2
	add r2, r2, r3
	sub r2, r2, #4
	ldrb r0, [r7]
	ldr r1, _021F6794 ; =0x0000FFFF
	ldr r2, [r2]
	bl sub_02005944
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x20]
	mov r3, #3
	bl ov96_021E8228
_021F671C:
	add r4, r4, #1
	cmp r4, #0x1d
	blt _021F6692
	ldr r0, [sp, #0x1c]
	add r7, r7, #1
	add r0, #0x38
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	add r0, #0x1c
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r0, #0x38
	str r0, [sp, #0x14]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #3
	bge _021F6742
	b _021F6638
_021F6742:
	mov r1, #0
	add r0, r1, #0
_021F6746:
	add r2, r5, #0
	add r2, #0xb6
	ldrb r2, [r2]
	cmp r2, #0
	beq _021F6774
	add r2, r5, #0
	add r2, #0xb7
	ldrb r2, [r2]
	sub r3, r2, #1
	add r2, r5, #0
	add r2, #0xb7
	strb r3, [r2]
	add r2, r5, #0
	add r2, #0xb7
	ldrb r2, [r2]
	cmp r2, #0
	bne _021F6774
	add r2, r5, #0
	add r2, #0xb7
	strb r0, [r2]
	add r2, r5, #0
	add r2, #0xb6
	strb r0, [r2]
_021F6774:
	add r1, r1, #1
	add r5, #0x38
	cmp r1, #3
	blt _021F6746
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021F6780: .word ov96_0221DC18
_021F6784: .word 0x00000FB4
_021F6788: .word 0x00000142
_021F678C: .word 0x0000088D
_021F6790: .word ov96_0221C110
_021F6794: .word 0x0000FFFF
	thumb_func_end ov96_021F6600




	thumb_func_start ov96_021F6798
ov96_021F6798: ; 0x021F6798
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x20
	add r6, r1, #0
	ldr r1, _021F6A5C ; =0x00000FAC
	add r5, r2, #0
	add r2, r6, r1
	mov r1, #0x1c
	mul r1, r5
	add r4, r2, r1
	ldr r1, [r4, #0x14]
	str r0, [sp, #4]
	cmp r1, #0
	bne _021F67B6
	b _021F6B20
_021F67B6:
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	lsl r0, r5, #2
	add r1, r6, r0
	mov r0, #0xfa
	lsl r0, r0, #4
	ldr r7, [r1, r0]
	cmp r5, #0
	beq _021F67D8
	cmp r5, #1
	beq _021F67DC
	cmp r5, #2
	beq _021F67E0
	b _021F67E4
_021F67D8:
	mov r1, #6
	b _021F67EE
_021F67DC:
	mov r1, #5
	b _021F67EE
_021F67E0:
	mov r1, #3
	b _021F67EE
_021F67E4:
	bl GF_AssertFail
	add sp, #0x1fc
	add sp, #0x20
	pop {r4, r5, r6, r7, pc}
_021F67EE:
	mov r0, #0x1a
	lsl r0, r0, #4
	add r0, r6, r0
	add r2, sp, #0x1c
	bl ov96_021F64A0
	ldr r0, [r4, #0x10]
	cmp r0, #0
	ldr r0, [r4, #0x18]
	bne _021F6804
	b _021F6908
_021F6804:
	cmp r0, #0
	bgt _021F683C
	bl GF_AssertFail
	mov r3, #0
	str r3, [r4, #0x10]
	lsl r1, r7, #2
	add r0, sp, #0x1c
	ldr r0, [r0, r1]
	mov r1, #0x38
	str r0, [r4, #8]
	str r3, [r4, #0x18]
	mul r1, r5
	str r3, [r4, #0x14]
	add r1, r6, r1
	lsl r2, r7, #0x18
	str r3, [r4]
	mov r0, #1
	add r1, #0xb8
	strb r0, [r1]
	add r0, r6, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	bl ov96_021F6BE4
	add sp, #0x1fc
	add sp, #0x20
	pop {r4, r5, r6, r7, pc}
_021F683C:
	ldr r1, [r4, #8]
	ldr r0, [r4]
	add r0, r1, r0
	str r0, [r4, #8]
	mov r0, #0x38
	mul r0, r5
	str r0, [sp, #8]
	add r0, r6, r0
	add r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _021F6862
	add r1, r6, #0
	ldr r0, [sp, #8]
	add r1, #0x90
	add r0, r1, r0
	add r1, r4, #0
	bl ov96_021F6B28
_021F6862:
	add r3, sp, #0x1c
	lsl r2, r7, #2
	ldr r1, [r3, r2]
	ldr r0, [r4, #8]
	cmp r0, r1
	ble _021F6890
	ldr r0, [r4]
	bl _dflt
	ldr r3, _021F6A60 ; =0x40600000
	mov r2, #0
	bl _dsub
	bl _dfix
	str r0, [r4]
	ldr r1, [r4, #0x18]
	neg r0, r0
	cmp r0, r1
	ble _021F6894
	neg r0, r1
	str r0, [r4]
	b _021F6AD6
_021F6890:
	cmp r0, r1
	ble _021F6896
_021F6894:
	b _021F6AD6
_021F6896:
	ldr r0, [r4]
	cmp r0, #0
	bne _021F68BA
	mov r0, #0
	str r0, [r4, #0x10]
	ldr r0, [r3, r2]
	lsl r2, r7, #0x18
	str r0, [r4, #8]
	mov r0, #0
	str r0, [r4, #0x18]
	str r0, [r4, #0x14]
	add r0, r6, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	mov r3, #0
	bl ov96_021F6BE4
	b _021F6AD6
_021F68BA:
	bge _021F68E8
	mov r0, #0
	str r0, [r4, #0x10]
	add r1, r6, #0
	ldr r0, [sp, #8]
	add r1, #0x90
	add r0, r1, r0
	bl ov96_021F7130
	ldr r0, [r4]
	bl _dflt
	ldr r3, _021F6A64 ; =0xC0600000
	mov r2, #0
	bl _dgr
	bls _021F68E2
	mov r0, #0x7f
	mvn r0, r0
	str r0, [r4]
_021F68E2:
	ldr r0, [r4]
	str r0, [r4, #0x18]
	b _021F6AD6
_021F68E8:
	mov r0, #0
	str r0, [r4, #0x10]
	ldr r0, [r3, r2]
	lsl r2, r7, #0x18
	str r0, [r4, #8]
	mov r0, #0
	str r0, [r4, #0x18]
	str r0, [r4, #0x14]
	str r0, [r4]
	add r0, r6, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	mov r3, #0
	bl ov96_021F6BE4
	b _021F6AD6
_021F6908:
	cmp r0, #0
	ble _021F6910
	bl GF_AssertFail
_021F6910:
	ldr r1, [r4, #8]
	ldr r0, [r4]
	add r0, r1, r0
	str r0, [r4, #8]
	bl _dflt
	ldr r3, _021F6A68 ; =0xC0B80000
	mov r2, #0
	bl _dls
	bhs _021F692E
	ldr r0, _021F6A6C ; =0xFFFFE800
	str r0, [r4, #8]
	mov r0, #0
	str r0, [r4]
_021F692E:
	lsl r0, r7, #2
	add r1, sp, #0x1c
	str r0, [sp, #0x10]
	ldr r1, [r1, r0]
	ldr r0, [r4, #8]
	cmp r0, r1
	blt _021F6A28
	lsl r2, r7, #0x18
	add r0, r6, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	mov r3, #0
	bl ov96_021F6BE4
	mov r0, #0x38
	add r1, r6, #0
	mul r0, r5
	str r1, [sp, #0x18]
	add r1, #0xb8
	str r0, [sp, #0x14]
	ldrb r0, [r1, r0]
	str r1, [sp, #0x18]
	cmp r0, #0
	beq _021F6972
	ldr r0, [sp, #0x14]
	ldr r1, [r4]
	add r0, r6, r0
	add r0, #0xbc
	ldr r0, [r0]
	mul r0, r1
	mov r1, #0xc
	bl _s32_div_f
	str r0, [r4]
_021F6972:
	ldr r1, [r4]
	ldr r0, _021F6A70 ; =0x00000898
	cmp r1, r0
	ble _021F697C
	str r0, [r4]
_021F697C:
	ldr r1, [r4]
	lsl r0, r1, #3
	add r0, r1, r0
	mov r1, #0xa
	bl _s32_div_f
	str r0, [r4]
	cmp r0, #0
	bne _021F69C0
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x14]
	ldrb r0, [r1, r0]
	cmp r0, #0
	beq _021F69A2
	ldr r1, _021F6A74 ; =ov96_0221DC18
	ldr r0, _021F6A78 ; =0x000005F3
	ldrb r1, [r1, #3]
	bl sub_0200606C
_021F69A2:
	mov r3, #0
	ldr r0, [sp, #0x10]
	str r3, [r4, #0x10]
	add r1, sp, #0x1c
	ldr r0, [r1, r0]
	lsl r2, r7, #0x18
	str r0, [r4, #8]
	str r3, [r4, #0x18]
	add r0, r6, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	str r3, [r4, #0x14]
	bl ov96_021F6BE4
	b _021F6AD6
_021F69C0:
	bgt _021F69C4
	b _021F6AD6
_021F69C4:
	bl _dflt
	ldr r3, _021F6A7C ; =0x40960000
	mov r2, #0
	bl _dleq
	bhi _021F69FC
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x14]
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _021F69FC
	mov r3, #0
	ldr r0, [sp, #0x10]
	str r3, [r4, #0x10]
	add r1, sp, #0x1c
	ldr r0, [r1, r0]
	lsl r2, r7, #0x18
	str r0, [r4, #8]
	str r3, [r4, #0x18]
	str r3, [r4]
	add r0, r6, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	str r3, [r4, #0x14]
	bl ov96_021F6BE4
	b _021F6AD6
_021F69FC:
	mov r0, #1
	str r0, [r4, #0x10]
	ldr r0, [r4]
	ldr r1, [sp, #0x18]
	str r0, [r4, #0x18]
	ldr r0, [sp, #0x14]
	mov r2, #0
	strb r2, [r1, r0]
	ldr r1, _021F6A74 ; =ov96_0221DC18
	ldr r0, _021F6A80 ; =0x00000656
	ldrb r1, [r1, #3]
	bl sub_0200606C
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, [sp, #0xc]
	add r2, r5, #0
	mov r3, #2
	bl ov96_021E8228
	b _021F6AD6
_021F6A28:
	cmp r0, r1
	bge _021F6AD6
	ldr r0, [r4]
	cmp r0, #0
	bge _021F6A4E
	bl _dflt
	ldr r2, _021F6A84 ; =0x9999999A
	ldr r3, _021F6A88 ; =0x40899999
	bl _dadd
	bl _dfix
	str r0, [r4]
	cmp r0, #0
	blt _021F6AD6
	mov r0, #0
	str r0, [r4]
	b _021F6AD6
_021F6A4E:
	blt _021F6AD6
	bl _dflt
	ldr r2, _021F6A8C ; =0x55555555
	ldr r3, _021F6A90 ; =0x40755555
	b _021F6A94
	nop
_021F6A5C: .word 0x00000FAC
_021F6A60: .word 0x40600000
_021F6A64: .word 0xC0600000
_021F6A68: .word 0xC0B80000
_021F6A6C: .word 0xFFFFE800
_021F6A70: .word 0x00000898
_021F6A74: .word ov96_0221DC18
_021F6A78: .word 0x000005F3
_021F6A7C: .word 0x40960000
_021F6A80: .word 0x00000656
_021F6A84: .word 0x9999999A
_021F6A88: .word 0x40899999
_021F6A8C: .word 0x55555555
_021F6A90: .word 0x40755555
_021F6A94:
	bl _dadd
	bl _dfix
	str r0, [r4]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	blt _021F6ACC
	bl GF_AssertFail
	mov r3, #0
	lsl r2, r7, #0x18
	ldr r0, [sp, #0x10]
	str r3, [r4, #0x10]
	add r1, sp, #0x1c
	ldr r0, [r1, r0]
	add r1, r5, #0
	str r0, [r4, #8]
	str r3, [r4, #0x18]
	str r3, [r4, #0x14]
	add r0, r6, #0
	lsr r2, r2, #0x18
	str r3, [r4]
	bl ov96_021F6BE4
	add sp, #0x1fc
	add sp, #0x20
	pop {r4, r5, r6, r7, pc}
_021F6ACC:
	neg r1, r0
	ldr r0, [r4]
	cmp r0, r1
	ble _021F6AD6
	str r1, [r4]
_021F6AD6:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _021F6AE8
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _021F6AE8
	ldr r0, [r4]
	cmp r0, #0
	bne _021F6AF4
_021F6AE8:
	mov r1, #0x38
	mul r1, r5
	add r1, r6, r1
	mov r0, #0
	add r1, #0xb4
	strh r0, [r1]
_021F6AF4:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _021F6B0E
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _021F6B0E
	lsl r2, r7, #0x18
	ldr r3, [r4, #8]
	add r0, r6, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	bl ov96_021F6BE4
_021F6B0E:
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne _021F6B20
	mov r0, #0x38
	mul r0, r5
	add r0, r6, r0
	mov r1, #1
	add r0, #0xb8
	strb r1, [r0]
_021F6B20:
	add sp, #0x1fc
	add sp, #0x20
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F6798

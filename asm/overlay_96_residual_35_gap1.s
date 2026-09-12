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

	thumb_func_start ov96_021EB730
ov96_021EB730: ; 0x021EB730
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r0, [sp, #0xc]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r0, [sp, #0xc]
	mov r5, #0
	bl PokeathlonCourse_GetMode
	cmp r0, #1
	bne _021EB750
	ldr r0, [sp, #0xc]
	bl ov96_021EE324
	add r5, r0, #0
_021EB750:
	ldr r0, [r4, #0xc]
	bl ov96_021EE830
	ldr r0, [r4, #0xc]
	bl ov96_021EEA80
	cmp r0, #0
	bne _021EB764
	cmp r5, #0
	beq _021EB766
_021EB764:
	b _021EB9AE
_021EB766:
	ldr r0, [r4, #0xc]
	bl ov96_021EE97C
	add r1, r4, #0
	add r1, #0xb5
	mov r5, #0
	ldrb r1, [r1]
	add r6, r0, #0
	mvn r5, r5
	cmp r1, #8
	bls _021EB77E
	b _021EB98C
_021EB77E:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021EB78A: ; jump table
	.short _021EB79C - _021EB78A - 2 ; case 0
	.short _021EB7B4 - _021EB78A - 2 ; case 1
	.short _021EB7CA - _021EB78A - 2 ; case 2
	.short _021EB7F6 - _021EB78A - 2 ; case 3
	.short _021EB816 - _021EB78A - 2 ; case 4
	.short _021EB82A - _021EB78A - 2 ; case 5
	.short _021EB882 - _021EB78A - 2 ; case 6
	.short _021EB918 - _021EB78A - 2 ; case 7
	.short _021EB94A - _021EB78A - 2 ; case 8
_021EB79C:
	add r2, r4, #0
	add r2, #0xb1
	ldrb r2, [r2]
	mov r5, #0
	add r1, r5, #0
	bl BufferPokeathlonCourseName
	add r0, r4, #0
	mov r1, #1
	add r0, #0xb5
	strb r1, [r0]
	b _021EB990
_021EB7B4:
	lsr r0, r5, #0x11
	bl sub_0200FC20
	ldr r0, _021EBA8C ; =0x000008DC
	bl PlaySE
	add r0, r4, #0
	mov r1, #2
	add r0, #0xb5
	strb r1, [r0]
	b _021EB990
_021EB7CA:
	add r0, r4, #0
	add r0, #0xb4
	ldrb r0, [r0]
	cmp r0, #4
	bhs _021EB7E4
	add r0, r4, #0
	add r0, #0xb4
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xb4
	strb r1, [r0]
	b _021EB990
_021EB7E4:
	add r0, r4, #0
	mov r1, #0
	add r0, #0xb4
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #3
	add r0, #0xb5
	strb r1, [r0]
	b _021EB990
_021EB7F6:
	mov r0, #0x18
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r4]
	add r2, r1, #0
	str r0, [sp, #8]
	mov r0, #0
	lsr r3, r5, #0x11
	bl BeginNormalPaletteFade
	add r0, r4, #0
	mov r1, #4
	add r0, #0xb5
	strb r1, [r0]
	b _021EB990
_021EB816:
	bl IsPaletteFadeFinished
	cmp r0, #0
	bne _021EB820
	b _021EB990
_021EB820:
	add r0, r4, #0
	mov r1, #5
	add r0, #0xb5
	strb r1, [r0]
	b _021EB990
_021EB82A:
	add r1, r4, #0
	add r1, #0xb2
	ldrb r1, [r1]
	ldr r0, [sp, #0xc]
	bl PokeathlonCourse_GetParticipantData
	ldr r0, [r0]
	cmp r0, #0
	ble _021EB852
	add r1, r4, #0
	add r1, #0xb2
	ldrb r1, [r1]
	ldr r0, [sp, #0xc]
	bl ov96_021ED838
	add r1, r0, #0
	ldr r0, [r4, #0xc]
	bl ov96_021EE908
	b _021EB878
_021EB852:
	add r1, r4, #0
	add r1, #0xb2
	ldrb r1, [r1]
	ldr r0, [sp, #0xc]
	bl ov96_021ED838
	add r1, r4, #0
	add r1, #0xb2
	add r5, r0, #0
	ldrb r1, [r1]
	ldr r0, [sp, #0xc]
	bl ov96_021ED86C
	add r1, r0, #0
	add r0, r6, #0
	mov r2, #7
	mov r3, #1
	bl ov96_021EDF3C
_021EB878:
	add r0, r4, #0
	mov r1, #6
	add r0, #0xb5
	strb r1, [r0]
	b _021EB990
_021EB882:
	add r1, r4, #0
	add r1, #0xb2
	ldrb r1, [r1]
	ldr r0, [sp, #0xc]
	bl PokeathlonCourse_GetPlayerProfileFromData
	add r2, r0, #0
	add r0, r6, #0
	mov r1, #0
	bl BufferPlayersName
	mov r5, #0
_021EB89A:
	add r1, r4, #0
	add r1, #0xb2
	ldrb r1, [r1]
	lsl r2, r5, #0x18
	ldr r0, [sp, #0xc]
	lsr r2, r2, #0x18
	add r3, r5, #1
	bl ov96_021ED524
	add r5, r5, #1
	cmp r5, #3
	blt _021EB89A
	ldr r0, [r4]
	add r2, r4, #0
	str r0, [sp]
	add r2, #0xb2
	add r0, r4, #0
	ldrb r2, [r2]
	ldr r1, [sp, #0xc]
	add r0, #0x20
	mov r3, #2
	bl ov96_021ECB38
	add r0, r4, #0
	add r0, #0xb2
	ldrb r0, [r0]
	mov r1, #1
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #0x20]
	bl ManagedSprite_SetAnim
	add r1, r4, #0
	add r1, #0xb2
	ldrb r1, [r1]
	ldr r0, [sp, #0xc]
	bl ov96_021ED8A4
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	cmp r1, #5
	bhs _021EB8F2
	ldr r0, _021EBA8C ; =0x000008DC
	b _021EB8F4
_021EB8F2:
	ldr r0, _021EBA90 ; =0x000008DD
_021EB8F4:
	lsl r2, r1, #2
	ldr r1, _021EBA94 ; =ov96_0221B088
	lsl r0, r0, #0x10
	ldr r1, [r1, r2]
	lsr r0, r0, #0x10
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	bl PlaySE_SetPitch
	add r0, r4, #0
	mov r5, #1
	add r0, #0xb0
	strb r5, [r0]
	add r0, r4, #0
	mov r1, #7
	add r0, #0xb5
	strb r1, [r0]
	b _021EB990
_021EB918:
	add r0, r4, #0
	add r0, #0xb0
	ldrb r0, [r0]
	cmp r0, #0
	bne _021EB990
	add r0, r4, #0
	add r0, #0xb2
	ldrb r0, [r0]
	cmp r0, #4
	blo _021EB940
	add r0, r4, #0
	mov r1, #1
	add r0, #0xb8
	str r1, [r0]
	add r0, r4, #0
	mov r1, #8
	add r0, #0xb5
	mov r5, #2
	strb r1, [r0]
	b _021EB990
_021EB940:
	add r0, r4, #0
	mov r1, #5
	add r0, #0xb5
	strb r1, [r0]
	b _021EB990
_021EB94A:
	ldr r0, [sp, #0xc]
	bl PokeathlonCourse_GetMode
	cmp r0, #0
	beq _021EB95E
	ldr r0, [sp, #0xc]
	bl ov96_021EE54C
	cmp r0, #0
	beq _021EB990
_021EB95E:
	add r0, r4, #0
	bl ov96_021EC2E0
	cmp r0, #0
	beq _021EB978
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl Heap_Free
	ldr r0, [r4, #8]
	bl SysTask_Destroy
_021EB978:
	ldr r0, [r4, #0xc]
	bl ov96_021EE944
	ldr r0, [sp, #0xc]
	mov r1, #2
	bl PokeathlonCourse_SetStateField07
	add sp, #0x14
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_021EB98C:
	bl GF_AssertFail
_021EB990:
	mov r0, #0
	mvn r0, r0
	cmp r5, r0
	beq _021EB9AE
	ldr r0, [r4, #0xc]
	add r1, r5, #0
	bl ov96_021EE8CC
	add r0, r4, #0
	add r0, #0xb7
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xb7
	strb r1, [r0]
_021EB9AE:
	add r0, r4, #0
	add r0, #0xb0
	ldrb r0, [r0]
	cmp r0, #0
	beq _021EBA86
	add r0, r4, #0
	add r0, #0xb2
	ldrb r1, [r0]
	add r2, r4, #0
	add r2, #0x94
	lsl r0, r1, #1
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r4, #0
	ldr r2, [r2]
	add r0, #0x94
	ldr r1, [r0]
	add r3, r2, #1
	add r2, r4, #0
	add r0, r4, #0
	add r2, #0x94
	add r0, #0x94
	str r3, [r2]
	cmp r1, #0
	bne _021EBA08
	mov r5, #0
_021EB9E4:
	lsl r1, r6, #0x18
	ldr r0, [r4, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r7, r0, #0
	mov r1, #2
	bl ov96_021EAC0C
	add r0, r7, #0
	mov r1, #0x10
	bl ov96_021EAC5C
	add r5, r5, #1
	add r6, r6, #1
	cmp r5, #3
	blt _021EB9E4
	b _021EBA86
_021EBA08:
	add r1, r4, #0
	add r1, #0x94
	ldr r2, [r1]
	ldr r1, [r0]
	add r1, r1, #1
	str r1, [r0]
	cmp r2, #0x3c
	blt _021EBA86
	mov r5, #0
	str r5, [sp, #0x10]
_021EBA1C:
	lsl r1, r6, #0x18
	ldr r0, [r4, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r7, r0, #0
	mov r1, #1
	bl ov96_021EAC0C
	add r0, r7, #0
	mov r1, #0
	bl ov96_021EAC5C
	add r0, r7, #0
	bl ov96_021EAA20
	bl ov96_021E8BAC
	bl Sprite_GetCellAnim
	lsl r1, r5, #0xc
	str r1, [r0, #0x10]
	ldr r0, [sp, #0x10]
	add r6, r6, #1
	add r0, r0, #1
	add r5, r5, #3
	str r0, [sp, #0x10]
	cmp r0, #3
	blt _021EBA1C
	ldr r0, [r4]
	add r2, r4, #0
	str r0, [sp]
	add r2, #0xb2
	add r0, r4, #0
	ldrb r2, [r2]
	ldr r1, [sp, #0xc]
	add r0, #0x20
	mov r3, #1
	bl ov96_021ECB38
	add r0, r4, #0
	mov r2, #0
	add r0, #0xb0
	strb r2, [r0]
	add r0, r4, #0
	add r0, #0xb2
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xb2
	strb r1, [r0]
	add r4, #0x94
	str r2, [r4]
_021EBA86:
	mov r0, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021EBA8C: .word 0x000008DC
_021EBA90: .word 0x000008DD
_021EBA94: .word ov96_0221B088
	thumb_func_end ov96_021EB730

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

	thumb_func_start ov96_021F7E74
ov96_021F7E74: ; 0x021F7E74
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	mov r4, #0
	add r6, r0, #0
	add r7, r1, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x14]
	add r0, r4, #0
	str r0, [sp, #0x18]
	bl IsFanfarePlaying
	add r0, r6, #0
	bl PokeathlonCourse_GetMode
	cmp r0, #1
	bne _021F7E9E
	add r0, r6, #0
	bl ov96_021F85F4
	add r4, r0, #0
_021F7E9E:
	ldr r0, [sp, #0x14]
	ldr r0, [r0, #0x18]
	bl ov96_021EE830
	ldr r0, [sp, #0x14]
	ldr r0, [r0, #0x18]
	bl ov96_021EEA80
	cmp r0, #0
	bne _021F7EB6
	cmp r4, #0
	beq _021F7EB8
_021F7EB6:
	b _021F8080
_021F7EB8:
	ldr r0, [sp, #0x14]
	ldr r0, [r0, #0x18]
	bl ov96_021EE97C
	str r0, [sp, #0x10]
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0xc]
	ldrb r0, [r7]
	cmp r0, #8
	bhi _021F7F0A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021F7EDA: ; jump table
	.short _021F7EEC - _021F7EDA - 2 ; case 0
	.short _021F7EFC - _021F7EDA - 2 ; case 1
	.short _021F7F56 - _021F7EDA - 2 ; case 2
	.short _021F7F7E - _021F7EDA - 2 ; case 3
	.short _021F7F94 - _021F7EDA - 2 ; case 4
	.short _021F7FE0 - _021F7EDA - 2 ; case 5
	.short _021F7FF2 - _021F7EDA - 2 ; case 6
	.short _021F800A - _021F7EDA - 2 ; case 7
	.short _021F8048 - _021F7EDA - 2 ; case 8
_021F7EEC:
	add r0, r6, #0
	bl ov96_021F83DC
	str r0, [sp, #0xc]
	ldrb r0, [r7]
	add r0, r0, #1
	strb r0, [r7]
	b _021F805C
_021F7EFC:
	ldr r0, [sp, #0x14]
	add r1, r6, #0
	add r0, #0x1c
	bl ov96_021F81CC
	cmp r0, #0
	bne _021F7F0C
_021F7F0A:
	b _021F805C
_021F7F0C:
	mov r4, #0
	add r5, sp, #0x1c
_021F7F10:
	add r0, r6, #0
	bl PokeathlonCourse_GetGraphicsSystem
	lsl r1, r4, #0x18
	lsr r1, r1, #0x18
	bl ov96_021E94EC
	add r4, r4, #1
	stmia r5!, {r0}
	cmp r4, #4
	blt _021F7F10
	ldr r2, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ldrb r1, [r2, #9]
	ldrb r0, [r0, #9]
	cmp r1, r0
	bne _021F7F38
	mov r0, #0xfe
	str r0, [sp, #0xc]
	b _021F7F4E
_021F7F38:
	ldr r1, [r2]
	add r0, r6, #0
	bl PokeathlonCourse_GetPlayerProfileFromData
	add r2, r0, #0
	ldr r0, [sp, #0x10]
	mov r1, #0
	bl BufferPlayersName
	mov r0, #0xfd
	str r0, [sp, #0xc]
_021F7F4E:
	ldrb r0, [r7]
	add r0, r0, #1
	strb r0, [r7]
	b _021F805C
_021F7F56:
	mov r0, #1
	str r0, [sp]
	mov r0, #0x10
	add r1, r0, #0
	sub r1, #0x18
	mov r2, #0
	mov r3, #0x3f
	bl StartBrightnessTransition
	mov r0, #0x3f
	add r1, r0, #0
	bl UpdateMainScreenBrightnessSurface
	ldr r0, _021F8088 ; =0x04000052
	mov r1, #0x10
	strh r1, [r0]
	ldrb r0, [r7]
	add r0, r0, #1
	strb r0, [r7]
	b _021F805C
_021F7F7E:
	mov r0, #1
	bl IsBrightnessTransitionActive
	cmp r0, #0
	beq _021F805C
	mov r0, #0xff
	str r0, [sp, #0xc]
	ldrb r0, [r7]
	add r0, r0, #1
	strb r0, [r7]
	b _021F805C
_021F7F94:
	mov r5, #0
_021F7F96:
	add r0, r6, #0
	bl PokeathlonCourse_GetField3D8_ForCurrentParticipant
	add r4, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetGraphicsSystem
	add r1, r4, #0
	add r2, r5, #0
	bl ov96_021E95D8
	add r1, r0, #0
	ldr r0, _021F808C ; =0x000003E7
	cmp r1, r0
	ble _021F7FB6
	add r1, r0, #0
_021F7FB6:
	ldr r0, [sp, #0x14]
	lsl r2, r5, #0x18
	ldr r0, [r0, #0x14]
	lsr r2, r2, #0x18
	bl ov96_021F910C
	add r5, r5, #1
	cmp r5, #4
	blt _021F7F96
	mov r0, #2
	str r0, [sp]
	mov r0, #0x10
	mov r1, #0
	add r2, r0, #0
	mov r3, #0x3f
	bl StartBrightnessTransition
	ldrb r0, [r7]
	add r0, r0, #1
	strb r0, [r7]
	b _021F805C
_021F7FE0:
	mov r0, #2
	bl IsBrightnessTransitionActive
	cmp r0, #0
	beq _021F805C
	ldrb r0, [r7]
	add r0, r0, #1
	strb r0, [r7]
	b _021F805C
_021F7FF2:
	add r0, r6, #0
	bl ov96_021F83FC
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	mov r1, #1
	add r0, #0xa8
	str r1, [r0]
	ldrb r0, [r7]
	add r0, r0, #1
	strb r0, [r7]
	b _021F805C
_021F800A:
	add r0, r6, #0
	bl PokeathlonCourse_GetMode
	cmp r0, #0
	beq _021F801E
	add r0, r6, #0
	bl ov96_021F7E64
	cmp r0, #0
	beq _021F805C
_021F801E:
	mov r0, #0xc
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #0x14]
	ldr r3, _021F8090 ; =0x00007FFF
	ldr r0, [r0]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #0
	mov r1, #0xc
	bl GF_SndStartFadeOutBGM
	ldrb r0, [r7]
	add r0, r0, #1
	strb r0, [r7]
	b _021F805C
_021F8048:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021F805C
	ldr r0, [sp, #0x14]
	ldr r0, [r0, #0x18]
	bl ov96_021EE944
	mov r0, #1
	str r0, [sp, #0x18]
_021F805C:
	mov r1, #0
	ldr r0, [sp, #0xc]
	mvn r1, r1
	cmp r0, r1
	beq _021F8080
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0xc]
	ldr r0, [r0, #0x18]
	bl ov96_021EE8CC
	ldr r0, [sp, #0x14]
	add r0, #0xa4
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x14]
	add r0, #0xa4
	str r0, [sp, #0x14]
	str r1, [r0]
_021F8080:
	ldr r0, [sp, #0x18]
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	nop
_021F8088: .word 0x04000052
_021F808C: .word 0x000003E7
_021F8090: .word 0x00007FFF
	thumb_func_end ov96_021F7E74

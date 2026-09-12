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


	thumb_func_start ov96_021FAB24
ov96_021FAB24: ; 0x021FAB24
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	ldr r1, [r4, #0x1c]
	add r5, r0, #0
	cmp r1, #0
	beq _021FAB42
	cmp r1, #1
	bne _021FAB38
	b _021FAC6C
_021FAB38:
	cmp r1, #2
	bne _021FAB3E
	b _021FADBE
_021FAB3E:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_021FAB42:
	ldrh r1, [r4]
	cmp r1, #0x70
	bhs _021FAB4A
	b _021FAF10
_021FAB4A:
	mov r2, #2
	lsl r1, r2, #9
	add r1, r2, r1
	lsl r1, r1, #0x10
	lsr r7, r1, #0x10
	mov r1, #0x32
	str r1, [sp]
	mov r1, #1
	str r1, [sp, #4]
	str r2, [sp, #8]
	mov r1, #0x10
	str r1, [sp, #0xc]
	ldrh r1, [r4, #0x14]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, r3, #2
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x14]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, r3, #3
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x14]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, #9
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r2, r7, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r2, #2
	str r2, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x16]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, r3, #2
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x16]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, r3, #3
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x16]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, #9
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r2, r7, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #1
	str r0, [r4, #0x1c]
	mov r0, #0xff
	add sp, #0x10
	strb r0, [r4, #0x1a]
	pop {r3, r4, r5, r6, r7, pc}
_021FAC6C:
	ldrh r1, [r4]
	ldr r0, _021FAF14 ; =0x00000E48
	sub r1, #0x10
	cmp r1, r0
	bge _021FAC78
	b _021FAF10
_021FAC78:
	asr r0, r1, #2
	lsr r0, r0, #0x1d
	add r0, r1, r0
	asr r0, r0, #3
	lsr r1, r0, #0x1f
	lsl r0, r0, #0x1a
	sub r0, r0, r1
	mov r2, #0x1a
	ror r0, r2
	add r1, r1, r0
	mov r0, #0x40
	sub r0, r0, r1
	lsr r1, r0, #0x1f
	lsl r0, r0, #0x1a
	sub r0, r0, r1
	ror r0, r2
	add r0, r1, r0
	sub r0, r0, #2
	bpl _021FACA0
	add r0, #0x40
_021FACA0:
	strb r0, [r4, #0x1b]
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x60
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #2
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x61
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #3
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x62
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, #9
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x60
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #2
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x61
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #3
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x62
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, #9
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #2
	add sp, #0x10
	str r0, [r4, #0x1c]
	pop {r3, r4, r5, r6, r7, pc}
_021FADBE:
	ldrh r1, [r4]
	ldr r0, _021FAF18 ; =0x00001048
	sub r1, #0x10
	cmp r1, r0
	bge _021FADCA
	b _021FAF10
_021FADCA:
	asr r0, r1, #2
	lsr r0, r0, #0x1d
	add r0, r1, r0
	asr r0, r0, #3
	lsr r1, r0, #0x1f
	lsl r0, r0, #0x1a
	sub r0, r0, r1
	mov r2, #0x1a
	ror r0, r2
	add r1, r1, r0
	mov r0, #0x40
	sub r0, r0, r1
	lsr r1, r0, #0x1f
	lsl r0, r0, #0x1a
	sub r0, r0, r1
	ror r0, r2
	add r0, r1, r0
	sub r0, r0, #2
	bpl _021FADF2
	add r0, #0x40
_021FADF2:
	mov r2, #2
	strb r0, [r4, #0x1b]
	lsl r0, r2, #9
	add r0, r2, r0
	lsl r0, r0, #0x10
	lsr r7, r0, #0x10
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r2, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #2
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #3
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #3
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	add r2, r7, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, #9
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r2, #2
	mov r3, #0xa
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r2, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #2
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #3
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #3
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	add r2, r7, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, #9
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #3
	str r0, [r4, #0x1c]
_021FAF10:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FAF14: .word 0x00000E48
_021FAF18: .word 0x00001048
	thumb_func_end ov96_021FAB24


	thumb_func_start ov96_021FAF1C
ov96_021FAF1C: ; 0x021FAF1C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r5, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r4, r0, #0
	bl ov96_021E8A20
	mov r7, #0x23
	add r3, r0, #0
	mov r1, #0
	add r2, r5, #0
	mov r0, #1
	lsl r7, r7, #4
_021FAF40:
	add r6, r2, #0
	add r6, #0xe0
	ldrh r6, [r6]
	strh r6, [r3]
	add r6, r2, #0
	add r6, #0xe8
	ldrb r6, [r6]
	cmp r6, #0
	beq _021FAF5E
	ldrh r6, [r3, #0x10]
	cmp r6, #0
	bne _021FAF5E
	strh r0, [r3, #0x10]
	ldr r6, [r5, r7]
	strh r6, [r3, #0xa]
_021FAF5E:
	add r1, r1, #1
	add r2, #0x6c
	add r3, r3, #2
	cmp r1, #3
	blt _021FAF40
	ldr r0, [sp]
	bl ov96_021E5F24
	cmp r0, #0
	bne _021FAFF0
	add r0, r4, #0
	add r0, #0x28
	mov r7, #0
	bl ov96_021E8A20
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #0x50
	bl ov96_021E8A20
	add r5, r0, #0
	add r0, r4, #0
	bl ov96_021E8A20
	mov r2, #0x12
_021FAF90:
	ldrh r1, [r0]
	add r0, r0, #2
	strh r1, [r5]
	add r5, r5, #2
	sub r2, r2, #1
	bne _021FAF90
	mov r0, #0
	ldr r5, [sp, #8]
	str r0, [sp, #4]
	add r4, #0x50
_021FAFA4:
	add r0, r4, #0
	bl ov96_021E8A20
	add r6, r0, #0
	mov r1, #0
	add r2, r6, #0
	add r3, r5, #0
_021FAFB2:
	ldrh r0, [r2]
	add r1, r1, #1
	add r2, r2, #2
	strh r0, [r3, #4]
	add r3, r3, #2
	cmp r1, #3
	blt _021FAFB2
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _021FAFCC
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
_021FAFCC:
	ldr r0, [sp, #4]
	add r4, #0x28
	add r0, r0, #1
	add r5, r5, #6
	str r0, [sp, #4]
	cmp r0, #4
	blt _021FAFA4
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantCount
	cmp r7, r0
	bne _021FAFEA
	ldr r0, [sp, #8]
	mov r1, #1
	str r1, [r0]
_021FAFEA:
	ldr r0, [sp]
	bl ov96_021FB400
_021FAFF0:
	ldr r0, [sp]
	bl ov96_021FB0F4
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021FAF1C


	thumb_func_start ov96_021FAFFC
ov96_021FAFFC: ; 0x021FAFFC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa0
	str r0, [sp]
	add r7, r1, #0
	mov r0, #0
	add r1, sp, #0x10
	str r1, [sp, #8]
	str r0, [sp, #4]
	add r1, sp, #4
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
_021FB012:
	add r2, r0, #1
	mov r1, #0xc
	add r3, sp, #4
	mul r1, r2
	add r2, r3, r1
	lsr r1, r0, #0x1f
	add r1, r0, r1
	lsl r1, r1, #0x17
	lsr r1, r1, #0x18
	add r1, r7, r1
	ldrb r6, [r1, #0x1c]
	lsr r5, r0, #0x1f
	lsl r4, r0, #0x1f
	sub r4, r4, r5
	mov r1, #0x1f
	ror r4, r1
	add r1, r5, r4
	lsl r1, r1, #0x18
	lsr r1, r1, #0x16
	add r4, r6, #0
	asr r4, r1
	mov r1, #0xf
	and r1, r4
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	strh r1, [r2, #8]
	mov r1, #0
	strh r0, [r2, #0xa]
	str r1, [r2, #4]
	cmp r0, #0
	ble _021FB088
	ldrh r4, [r2, #8]
	ldrh r5, [r2, #0xa]
_021FB054:
	ldr r3, [r3, #4]
	ldrh r6, [r3, #8]
	cmp r6, r4
	bls _021FB06A
	ldr r4, [r3]
	str r2, [r4, #4]
	ldr r4, [r3]
	str r4, [r2]
	str r3, [r2, #4]
	str r2, [r3]
	b _021FB088
_021FB06A:
	cmp r6, r4
	bne _021FB082
	ldrh r6, [r3, #0xa]
	cmp r6, r5
	bls _021FB082
	ldr r4, [r3]
	str r2, [r4, #4]
	ldr r4, [r3]
	str r4, [r2]
	str r3, [r2, #4]
	str r2, [r3]
	b _021FB088
_021FB082:
	add r1, r1, #1
	cmp r1, r0
	blt _021FB054
_021FB088:
	cmp r1, r0
	bne _021FB090
	str r2, [r3, #4]
	str r3, [r2]
_021FB090:
	add r0, r0, #1
	cmp r0, #0xc
	blt _021FB012
	mov r1, #0x8a
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	mov r1, #1
	bl ov96_021FC2B4
	add r4, sp, #4
	mov r7, #0
	mov r5, #0x10
_021FB0AA:
	ldr r4, [r4, #4]
	ldrh r0, [r4, #8]
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #8
	bls _021FB0B8
	mov r6, #8
_021FB0B8:
	mov r0, #0x8a
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldrh r1, [r4, #0xa]
	add r2, r5, #0
	bl ov96_021FC248
	mov r0, #0x8a
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldrh r1, [r4, #0xa]
	add r2, r6, #0
	bl ov96_021FC28C
	mov r0, #0x8a
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldrh r1, [r4, #0xa]
	mov r2, #1
	bl ov96_021FC2E0
	add r7, r7, #1
	add r5, #0x20
	cmp r7, #0xc
	blt _021FB0AA
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021FAFFC


	thumb_func_start ov96_021FB0F4
ov96_021FB0F4: ; 0x021FB0F4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #4]
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #8]
	ldr r2, _021FB3EC ; =0x000003C7
	ldr r0, [sp, #4]
	ldrb r0, [r0, r2]
	cmp r0, #0
	beq _021FB124
	ldr r0, [sp, #4]
	sub r1, r2, #3
	ldrh r0, [r0, r1]
	add r3, r0, #1
	ldr r0, [sp, #4]
	strh r3, [r0, r1]
_021FB124:
	ldr r0, _021FB3F0 ; =0x000003C6
	ldr r1, [sp, #4]
	ldrb r1, [r1, r0]
	cmp r1, #0
	bne _021FB21E
	ldr r1, [sp, #4]
	sub r2, r0, #2
	ldrh r1, [r1, r2]
	cmp r1, #0x96
	blo _021FB21C
	ldr r1, [sp, #4]
	mov r3, #0
	strh r3, [r1, r2]
	mov r2, #1
	strb r2, [r1, r0]
	add r0, r1, #0
	ldr r1, [sp, #8]
	bl ov96_021FAFFC
	mov r4, #0
_021FB14C:
	mov r0, #0x6c
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #4]
	add r5, r0, r1
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl ov96_021EB5B8
	add r7, r0, #0
	mov r0, #0x4a
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r1, r0, #1
	add r0, r0, r1
	add r1, r4, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0x17
	lsr r6, r0, #0x18
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r1, r0, #1
	add r0, r0, r1
	add r0, r4, r0
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	lsl r1, r0, #0x18
	ldr r0, [sp, #8]
	add r0, r0, r6
	ldrb r2, [r0, #0x1c]
	lsr r0, r1, #0x16
	add r1, r2, #0
	asr r1, r0
	mov r0, #0xf
	and r0, r1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	beq _021FB1B8
	cmp r6, #0xc
	bls _021FB1BC
_021FB1B8:
	bl GF_AssertFail
_021FB1BC:
	mov r1, #0xff
	mov r0, #0x51
	lsl r1, r1, #0x16
	lsl r0, r0, #2
	str r1, [r5, r0]
	mov r1, #0x51
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r5, r1]
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x30]
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r5, r1]
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x34]
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r5, r1]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x38]
	mov r0, #0x52
	lsl r0, r0, #2
	strh r6, [r5, r0]
	add r0, r7, #0
	add r1, sp, #0x30
	bl Sprite_SetAffineScale
	add r0, r7, #0
	sub r1, r6, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021FB14C
_021FB21C:
	b _021FB348
_021FB21E:
	ldr r1, [sp, #4]
	sub r2, r0, #2
	ldrh r1, [r1, r2]
	cmp r1, #0x1e
	bhs _021FB22A
	b _021FB348
_021FB22A:
	sub r1, r0, #2
	ldr r0, [sp, #4]
	mov r2, #0
	strh r2, [r0, r1]
	ldr r1, [sp, #8]
	bl ov96_021FAFFC
	mov r7, #0
_021FB23A:
	mov r0, #0x6c
	add r1, r7, #0
	mul r1, r0
	ldr r0, [sp, #4]
	add r4, r0, r1
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB5B8
	add r6, r0, #0
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r1, r0, #1
	add r0, r0, r1
	add r1, r7, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0x17
	lsr r5, r0, #0x18
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r1, r0, #1
	add r0, r0, r1
	add r0, r7, r0
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	lsl r1, r0, #0x18
	ldr r0, [sp, #8]
	add r0, r0, r5
	ldrb r2, [r0, #0x1c]
	lsr r0, r1, #0x16
	add r1, r2, #0
	asr r1, r0
	mov r0, #0xf
	and r0, r1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	beq _021FB298
	cmp r5, #0xc
	bls _021FB29C
_021FB298:
	bl GF_AssertFail
_021FB29C:
	add r0, r4, #0
	add r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FB2D2
	add r0, r6, #0
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	add r2, sp, #0x24
	ldmia r3!, {r0, r1}
	mov ip, r2
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, ip
	str r0, [r2]
	mov r0, #0x4e
	lsl r0, r0, #0xe
	str r0, [sp, #0x28]
	add r0, r6, #0
	bl Sprite_SetMatrix
	add r1, r5, #0
	add r0, r6, #0
	add r1, #0xb
	bl Sprite_SetAnimCtrlSeq
_021FB2D2:
	mov r0, #0x52
	lsl r0, r0, #2
	ldrsh r0, [r4, r0]
	cmp r5, r0
	beq _021FB33C
	mov r0, #0x52
	lsl r0, r0, #2
	strh r5, [r4, r0]
	add r0, r4, #0
	add r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FB33C
	mov r1, #0xff
	mov r0, #0x51
	lsl r1, r1, #0x16
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r1, #0x51
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r4, r1]
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x18]
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r4, r1]
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x1c]
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r4, r1]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x20]
	add r0, r6, #0
	add r1, sp, #0x18
	bl Sprite_SetAffineScale
	add r0, r6, #0
	sub r1, r5, #1
	bl Sprite_SetAnimCtrlSeq
_021FB33C:
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #3
	bhs _021FB348
	b _021FB23A
_021FB348:
	ldr r7, _021FB3F4 ; =0x45800000
	mov r5, #0
_021FB34C:
	mov r0, #0x6c
	add r1, r5, #0
	mul r1, r0
	ldr r0, [sp, #4]
	add r4, r0, r1
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB5B8
	add r6, r0, #0
	bl Sprite_GetScalePtr
	ldr r1, [r0]
	mov r0, #1
	lsl r0, r0, #0xc
	cmp r1, r0
	ble _021FB38E
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl _f2d
	ldr r2, _021FB3F8 ; =0x9999999A
	ldr r3, _021FB3FC ; =0x3FB99999
	bl _dsub
	bl _d2f
	mov r1, #0x51
	lsl r1, r1, #2
	str r0, [r4, r1]
	b _021FB398
_021FB38E:
	mov r1, #0xfe
	mov r0, #0x51
	lsl r1, r1, #0x16
	lsl r0, r0, #2
	str r1, [r4, r0]
_021FB398:
	mov r1, #0x51
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r7, #0
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0xc]
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r7, #0
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x10]
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r7, #0
	bl _fmul
	bl _ffix
	str r0, [sp, #0x14]
	add r0, r6, #0
	add r1, sp, #0xc
	bl Sprite_SetAffineScale
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #3
	blo _021FB34C
	ldr r0, [sp, #4]
	bl ov96_021FB994
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	nop
_021FB3EC: .word 0x000003C7
_021FB3F0: .word 0x000003C6
_021FB3F4: .word 0x45800000
_021FB3F8: .word 0x9999999A
_021FB3FC: .word 0x3FB99999
	thumb_func_end ov96_021FB0F4


	thumb_func_start ov96_021FB400
ov96_021FB400: ; 0x021FB400
	push {r4, r5, r6, r7, lr}
	sub sp, #0x11c
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #8]
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #0x14]
	mov r0, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0x18]
	add r0, sp, #0x2c
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	add r1, sp, #0x18
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	str r0, [sp, #0x28]
	ldr r0, [sp, #8]
	add r0, #0x50
	str r0, [sp, #8]
	ldr r0, [sp, #0x10]
	str r0, [sp, #4]
_021FB434:
	ldr r0, [sp, #8]
	bl ov96_021E8A20
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #0xc]
_021FB440:
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #4]
	add r5, sp, #0x18
	add r7, r1, r0
	add r1, r7, #1
	mov r0, #0x14
	add r2, r1, #0
	mul r2, r0
	add r0, sp, #0x18
	add r4, r0, r2
	ldr r0, [sp]
	ldrh r0, [r0]
	strh r0, [r4, #8]
	ldr r0, [sp]
	ldrh r0, [r0, #0xa]
	strh r0, [r4, #0xc]
	ldr r0, [sp]
	strh r7, [r4, #0xa]
	ldrh r0, [r0, #0x10]
	strh r0, [r4, #0xe]
	mov r0, #0
	str r0, [r4, #0x10]
	add r6, r0, #0
	str r0, [r4, #4]
	cmp r7, #0
	ble _021FB498
_021FB474:
	ldrh r0, [r4, #0xe]
	ldr r5, [r5, #4]
	cmp r0, #0
	beq _021FB486
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_021FB514
	b _021FB48E
_021FB486:
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_021FB56C
_021FB48E:
	cmp r0, #0
	bne _021FB498
	add r6, r6, #1
	cmp r6, r7
	blt _021FB474
_021FB498:
	cmp r6, r7
	bne _021FB4A0
	str r4, [r5, #4]
	str r5, [r4]
_021FB4A0:
	ldr r0, [sp]
	add r0, r0, #2
	str r0, [sp]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #3
	blt _021FB440
	ldr r0, [sp, #8]
	add r0, #0x28
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r0, r0, #3
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #4
	blt _021FB434
	mov r7, #0
	add r5, sp, #0x18
	mov r4, #1
	add r1, r7, #0
	add r6, r7, #0
_021FB4D0:
	ldr r0, [sp, #0x14]
	add r0, r0, r1
	add r1, r1, #1
	strb r6, [r0, #0x1c]
	cmp r1, #6
	blt _021FB4D0
_021FB4DC:
	ldr r5, [r5, #4]
	cmp r5, #0
	bne _021FB4E6
	bl GF_AssertFail
_021FB4E6:
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _021FB4F6
	add r0, r7, r4
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	mov r4, #1
	b _021FB4FC
_021FB4F6:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_021FB4FC:
	ldrh r1, [r5, #0xa]
	ldr r0, [sp, #0x14]
	add r2, r7, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021FB5C8
	add r6, r6, #1
	cmp r6, #0xc
	blt _021FB4DC
	add sp, #0x11c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021FB400

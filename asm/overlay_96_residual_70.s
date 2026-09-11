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

	thumb_func_start ov96_021F9240
ov96_021F9240: ; 0x021F9240
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r1, #0
	add r7, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	ldrb r1, [r6]
	add r4, r0, #0
	cmp r1, #4
	bls _021F9256
	b _021F9370
_021F9256:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021F9262: ; jump table
	.short _021F926C - _021F9262 - 2 ; case 0
	.short _021F9284 - _021F9262 - 2 ; case 1
	.short _021F92D2 - _021F9262 - 2 ; case 2
	.short _021F9306 - _021F9262 - 2 ; case 3
	.short _021F9340 - _021F9262 - 2 ; case 4
_021F926C:
	add r0, r7, #0
	bl ov96_021E637C
	cmp r0, #0
	beq _021F9370
	ldr r0, _021F937C ; =0x000003C7
	mov r1, #1
	strb r1, [r4, r0]
	ldrb r0, [r6]
	add r0, r0, #1
	strb r0, [r6]
	b _021F9370
_021F9284:
	bl ov96_021FBDBC
	add r0, r7, #0
	add r1, r4, #0
	bl ov96_021FA6D0
	add r5, r0, #0
	add r0, r7, #0
	bl ov96_021FB630
	cmp r5, #0
	beq _021F9370
	mov r5, #0
	add r0, r5, #0
	mov r1, #0x6c
_021F92A2:
	add r2, r0, #0
	mul r2, r1
	add r2, r4, r2
	add r2, #0xe2
	ldrh r2, [r2]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r5, r5, r2
	cmp r0, #3
	blo _021F92A2
	lsl r1, r5, #0x10
	add r0, r7, #0
	lsr r1, r1, #0x10
	bl ov96_021E8318
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_021FB808
	ldrb r0, [r6]
	add r0, r0, #1
	strb r0, [r6]
	b _021F9370
_021F92D2:
	add r0, r7, #0
	bl ov96_021E667C
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	add r0, r4, #0
	bl ov96_021FB60C
	cmp r0, #0
	beq _021F92F0
	cmp r5, #0
	beq _021F92F0
	ldrb r0, [r6]
	add r0, r0, #1
	strb r0, [r6]
_021F92F0:
	add r0, r4, #0
	bl ov96_021FBDBC
	add r0, r7, #0
	add r1, r4, #0
	bl ov96_021FA6D0
	add r0, r7, #0
	bl ov96_021FB630
	b _021F9370
_021F9306:
	bl ov96_021FBDBC
	add r0, r7, #0
	bl ov96_021FB630
	add r0, r7, #0
	bl PokeathlonCourse_GetDataCopyArea
	bl ov96_021E8A20
	mov r1, #1
	strb r1, [r0, #9]
	add r0, r7, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	ldr r0, [r0]
	cmp r0, #0
	beq _021F9370
	ldrb r0, [r6]
	mov r1, #0
	add r0, r0, #1
	strb r0, [r6]
	mov r0, #0x8d
	lsl r0, r0, #2
	str r1, [r4, r0]
	b _021F9370
_021F9340:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	add r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0x5a
	bls _021F9370
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	add r0, r7, #0
	mov r1, #2
	bl PokeathlonCourse_SetStateField07
_021F9370:
	add r0, r7, #0
	bl ov96_021FAF1C
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021F937C: .word 0x000003C7
	thumb_func_end ov96_021F9240


	thumb_func_start ov96_021F9380
ov96_021F9380: ; 0x021F9380
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r1, #0
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r7, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	bne _021F93A6
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021F93A0
	mov r0, #1
	strb r0, [r4]
_021F93A0:
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021F93A6:
	ldr r0, [sp]
	bl ov96_021E5F24
	add r4, r0, #0
	mov r0, #0
	add r2, r0, #0
	add r3, r7, #0
_021F93B4:
	add r1, r3, #0
	add r1, #0xe2
	ldrh r1, [r1]
	add r2, r2, #1
	add r3, #0x6c
	add r0, r0, r1
	cmp r2, #3
	blt _021F93B4
	bl ov96_021FBDEC
	add r2, r0, #0
	lsl r1, r4, #0x18
	lsl r2, r2, #0x10
	ldr r0, [sp]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x10
	bl PokeathlonCourse_SetField5E0_AtIndex
	cmp r4, #0
	bne _021F94A0
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantCount
	str r0, [sp, #8]
	str r0, [sp, #0x10]
	cmp r0, #4
	bge _021F94A0
_021F93EA:
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #8]
	sub r1, r1, r0
	lsl r0, r1, #1
	add r6, r1, r0
_021F93FA:
	mov r0, #0x28
	mul r0, r6
	add r5, r7, r0
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _021F9466
	mov r0, #9
	lsl r0, r0, #6
	mov r1, #0x92
	ldr r4, [r5, r0]
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r0, r4, #0
	bl _fls
	bhs _021F9424
	mov r0, #0x92
	lsl r0, r0, #2
	ldr r4, [r5, r0]
_021F9424:
	mov r0, #0x96
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r0, #1
	lsl r0, r0, #0xc
	sub r0, r0, r1
	bl _fflt
	add r1, r4, #0
	bl _fdiv
	str r0, [sp, #0x14]
	bl _ffix
	add r4, r0, #0
	bl _fflt
	add r1, r0, #0
	ldr r0, [sp, #0x14]
	bl _fsub
	mov r1, #0
	bl _fgr
	bls _021F9458
	add r4, r4, #1
_021F9458:
	mov r0, #0x23
	lsl r0, r0, #4
	ldr r0, [r7, r0]
	add r1, r0, r4
	mov r0, #0x95
	lsl r0, r0, #2
	str r1, [r5, r0]
_021F9466:
	mov r0, #0x95
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #3
	blt _021F93FA
	ldr r0, [sp, #4]
	bl ov96_021FBDEC
	add r2, r0, #0
	ldr r1, [sp, #0x10]
	lsl r2, r2, #0x10
	lsl r1, r1, #0x18
	ldr r0, [sp]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x10
	bl PokeathlonCourse_SetField5E0_AtIndex
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #4
	blt _021F93EA
_021F94A0:
	mov r0, #1
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F9380


	thumb_func_start ov96_021F94A8
ov96_021F94A8: ; 0x021F94A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x180
	add r6, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetField1ED
	cmp r0, #8
	bls _021F94C0
	b _021F9C8A
_021F94C0:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021F94CC: ; jump table
	.short _021F94DE - _021F94CC - 2 ; case 0
	.short _021F95E8 - _021F94CC - 2 ; case 1
	.short _021F9884 - _021F94CC - 2 ; case 2
	.short _021F9A94 - _021F94CC - 2 ; case 3
	.short _021F9ABA - _021F94CC - 2 ; case 4
	.short _021F9AE2 - _021F94CC - 2 ; case 5
	.short _021F9B1E - _021F94CC - 2 ; case 6
	.short _021F9B38 - _021F94CC - 2 ; case 7
	.short _021F9C7C - _021F94CC - 2 ; case 8
_021F94DE:
	mov r2, #0x12
	mov r0, #0x5c
	mov r1, #0x8a
	lsl r2, r2, #0xe
	bl Heap_Create
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _021F986C ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021F9870 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	bl ov96_021F9E3C
	mov r1, #0xf2
	add r0, r6, #0
	lsl r1, r1, #2
	bl PokeathlonCourse_AllocPtr4FromHeap
	mov r2, #0xf2
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x8a
	bl BgConfig_Alloc
	str r0, [r4, #4]
	ldr r0, [r4]
	bl ov96_021FC028
	add r1, r4, #0
	add r1, #0xd8
	str r0, [r1]
	ldr r0, [r4]
	bl ov96_021FC618
	add r1, r4, #0
	add r1, #0xdc
	str r0, [r1]
	add r0, r4, #0
	add r0, #0xd8
	ldr r0, [r0]
	bl ov96_021FC0E4
	add r5, r0, #0
	add r0, r4, #0
	add r0, #0xd8
	ldr r0, [r0]
	bl ov96_021FC0E8
	add r7, r0, #0
	add r0, r4, #0
	add r0, #0xd8
	ldr r0, [r0]
	bl ov96_021FC0F4
	add r3, r0, #0
	add r0, r6, #0
	add r1, r5, #0
	add r2, r7, #0
	bl PokeathlonCourse_SetField3A4
	add r0, r6, #0
	mov r1, #8
	bl ov96_021E6670
	mov r0, #0x6b
	str r0, [sp, #0xdc]
	mov r0, #1
	lsl r0, r0, #0x12
	str r0, [sp, #0xe0]
	lsr r0, r0, #4
	mov r2, #0x8a
	str r0, [sp, #0xe4]
	ldr r3, _021F9874 ; =0x00300010
	str r2, [sp, #0xe8]
	add r0, sp, #0xdc
	mov r1, #0x12
	str r3, [sp]
	bl ov96_021E92B0
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x7e
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x8a
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	mov r1, #0x8a
	str r1, [r4]
	mov r0, #4
	bl FontID_Alloc
	ldr r0, [r4, #4]
	bl ov96_021F9E5C
	add r0, r4, #0
	bl ov96_021FB7C8
	ldr r0, _021F9878 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F95E8:
	ldr r5, _021F987C ; =ov96_0221C404
	add r3, sp, #0xd0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r4]
	bl ov96_021EB180
	mov r2, #0x89
	lsl r2, r2, #2
	mov r1, #0
	str r0, [r4, r2]
	str r1, [sp]
	ldr r0, [r4, r2]
	mov r2, #0x11
	lsl r2, r2, #0x10
	add r3, r1, #0
	bl ov96_021EB5C8
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	mov r2, #0x65
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	mov r2, #0x66
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	mov r2, #0x67
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #3
	mov r2, #0x68
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #4
	mov r2, #0x69
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #5
	mov r2, #0x6a
	bl ov96_021EB29C
	mov r0, #3
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #9
	mov r3, #0x65
	bl ov96_021EB2BC
	mov r0, #3
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #6
	mov r3, #0x65
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #8
	mov r3, #0x65
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #7
	mov r3, #0x65
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x10
	mov r3, #0x66
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xd
	mov r3, #0x66
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xf
	mov r3, #0x66
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xe
	mov r3, #0x66
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xc
	mov r3, #0x67
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #6
	mov r3, #0x67
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xb
	mov r3, #0x67
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xa
	mov r3, #0x67
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x14
	mov r3, #0x69
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x11
	mov r3, #0x69
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x13
	mov r3, #0x69
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x12
	mov r3, #0x69
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1c
	mov r3, #0x68
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x19
	mov r3, #0x68
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1b
	mov r3, #0x68
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1a
	mov r3, #0x68
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x20
	mov r3, #0x6a
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1d
	mov r3, #0x6a
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1f
	mov r3, #0x6a
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1e
	mov r3, #0x6a
	bl ov96_021EB36C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB3A4
	ldr r0, [r4]
	ldr r1, _021F9880 ; =0x000002E7
	mov r2, #1
	bl ov96_021E9A78
	mov r1, #0x3a
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB5E8
	mov r3, #0x3a
	str r0, [sp]
	lsl r3, r3, #4
	ldr r0, [r4]
	ldr r3, [r4, r3]
	mov r1, #3
	mov r2, #4
	bl ov96_021EA854
	mov r1, #0xe9
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
	nop
_021F986C: .word 0xFFFFE0FF
_021F9870: .word 0x04001000
_021F9874: .word 0x00300010
_021F9878: .word gSystem + 0x60
_021F987C: .word ov96_0221C404
_021F9880: .word 0x000002E7
_021F9884:
	mov r5, #0
	mov r7, #2
_021F9888:
	mov r0, #0x89
	str r7, [sp]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	mov r2, #3
	mov r3, #0x65
	bl ov96_021EB408
	mov r1, #0x1b
	bl Sprite_SetDrawPriority
	mov r0, #6
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x67
	bl ov96_021EB408
	mov r1, #0x1b
	bl Sprite_SetDrawPriority
	add r5, r5, #1
	cmp r5, #0xc
	blt _021F9888
	mov r5, #0
	mov r7, #5
_021F98C4:
	mov r0, #0x89
	str r7, [sp]
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x66
	bl ov96_021EB408
	mov r0, #7
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x68
	bl ov96_021EB408
	mov r0, #8
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x69
	bl ov96_021EB408
	add r5, r5, #1
	cmp r5, #3
	blt _021F98C4
	mov r0, #9
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	mov r1, #0xea
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0
	bl ov96_021EB564
	mov r0, #0
	str r0, [sp, #0xcc]
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r0, [sp, #0xc4]
	mov r0, #0x72
	lsl r0, r0, #0xe
	str r0, [sp, #0xc8]
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0xc4
	bl ov96_021EB588
	mov r0, #0xea
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov96_021EB630
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, _021F9C90 ; =ov96_0221C3F4
	ldr r7, _021F9C94 ; =ov96_0221C3EC
	add r5, r4, #0
	str r0, [sp, #0x18]
_021F9968:
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB5E8
	add r1, r0, #0
	mov r0, #0x3a
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	ldr r3, [r4]
	mov r2, #0
	bl ov96_021EA374
	mov r1, #0xeb
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [sp, #0x18]
	add r1, sp, #0xb8
	ldrb r0, [r0]
	lsl r0, r0, #0xc
	str r0, [sp, #0xb8]
	mov r0, #0x72
	lsl r0, r0, #0xe
	str r0, [sp, #0xbc]
	mov r0, #0
	str r0, [sp, #0xc0]
	mov r0, #0xeb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Sprite_SetMatrix
	mov r0, #0xeb
	lsl r0, r0, #2
	ldrb r1, [r7]
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [sp, #0x18]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r7, r7, #1
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #6
	blt _021F9968
	add r0, r4, #0
	mov r1, #0x89
	add r0, #0xdc
	lsl r1, r1, #2
	ldr r0, [r0]
	ldr r1, [r4, r1]
	mov r2, #1
	bl ov96_021FC630
	ldr r0, [r4]
	bl ov96_021FC188
	mov r1, #0x8a
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r7, #0
	add r5, sp, #0x88
_021F99F2:
	add r0, r6, #0
	add r1, r7, #0
	bl PokeathlonCourse_GetParticipantUnk04
	mov r1, #0
_021F99FC:
	ldrh r2, [r0]
	add r1, r1, #1
	strh r2, [r5]
	ldrh r2, [r0, #2]
	add r0, #0x28
	strh r2, [r5, #2]
	add r5, r5, #4
	cmp r1, #3
	blt _021F99FC
	add r7, r7, #1
	cmp r7, #4
	blt _021F99F2
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x88
	bl ov96_021FC214
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov96_021FC2B4
	add r0, sp, #0x58
	mov r5, #0
	str r0, [sp, #0x1c]
	add r7, sp, #0x13c
_021F9A34:
	add r0, r6, #0
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r3, [sp, #0x1c]
	add r0, r6, #0
	add r2, r5, #0
	bl ov96_021E6168
	add r0, r6, #0
	bl ov96_021E5F24
	add r1, r0, #0
	add r0, r6, #0
	add r2, r5, #0
	bl ov96_021E60C0
	bl ov96_021E6108
	str r0, [r7, #0x14]
	ldr r0, [sp, #0x1c]
	add r5, r5, #1
	add r0, #0x10
	add r7, r7, #4
	str r0, [sp, #0x1c]
	cmp r5, #3
	blt _021F9A34
	mov r0, #1
	mov r1, #0
	str r1, [sp, #0x13c]
	str r0, [sp, #0x140]
	str r1, [sp, #0x144]
	str r0, [sp, #0x148]
	str r0, [sp, #0x14c]
	str r1, [sp]
	mov r0, #0xe9
	str r1, [sp, #4]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #3
	add r2, sp, #0x58
	add r3, sp, #0x13c
	bl ov96_021EA8A8
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9A94:
	mov r0, #0xe9
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EAA00
	cmp r0, #0
	bne _021F9AA4
	b _021F9C8A
_021F9AA4:
	ldr r0, [r4, #4]
	bl PokeathlonCourse_SetVBlankIntrCB
	ldr r0, [r4, #4]
	ldr r1, [r4]
	bl ov96_021F9FE8
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9ABA:
	ldr r0, [r4, #4]
	ldr r1, [r4]
	bl ov96_021FA020
	mov r1, #5
	ldr r0, _021F9C98 ; =0x04000010
	lsl r1, r1, #0x16
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	mov r1, #3
	ldr r0, _021F9C9C ; =0x04001010
	lsl r1, r1, #0x14
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9AE2:
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add r0, r6, #0
	mov r1, #1
	bl PokeathlonCourse_SetField1F4
	mov r7, #0xe9
	mov r5, #0
	lsl r7, r7, #2
_021F9B00:
	lsl r1, r5, #0x18
	ldr r0, [r4, r7]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	mov r1, #1
	bl ov96_021EAB38
	add r5, r5, #1
	cmp r5, #3
	blt _021F9B00
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9B1E:
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021F9B30
	add r4, #0xd8
	ldr r0, [r4]
	bl ov96_021FC144
_021F9B30:
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9B38:
	add r0, r4, #0
	mov r1, #0x89
	add r0, #0xd8
	lsl r1, r1, #2
	ldr r0, [r0]
	ldr r1, [r4, r1]
	bl ov96_021FC07C
	mov r2, #0x3a
	mov r3, #0x89
	lsl r2, r2, #4
	lsl r3, r3, #2
	mov r1, #0x11
	ldr r2, [r4, r2]
	ldr r3, [r4, r3]
	add r0, r6, #0
	lsl r1, r1, #4
	bl ov96_021E6290
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_SetDrawPriority
	ldr r3, _021F9CA0 ; =ov96_0221C410
	add r2, sp, #0x4c
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0xaa
	str r0, [r2]
	add r0, sp, #0x28
	mov r2, #0xa
	bl ReadWholeNarcMemberByIdPair
	add r0, sp, #0xec
	mov r1, #0xaa
	mov r2, #0
	bl ReadWholeNarcMemberByIdPair
	mov r0, #0
	str r0, [sp, #0x24]
	add r0, r4, #0
	str r0, [sp, #0x20]
	add r0, #0xe0
	str r0, [sp, #0x20]
	add r7, sp, #0x4c
	add r5, sp, #0x40
_021F9B96:
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r3, r4, #0
	str r0, [sp]
	mov r0, #0xe9
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r3, #0xd8
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	add r1, sp, #0xec
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	ldr r0, [sp, #0x20]
	add r2, sp, #0x28
	str r0, [sp, #0xc]
	ldr r3, [r3]
	add r0, r6, #0
	bl ov96_021FA0E8
	ldr r0, [r7]
	add r7, r7, #4
	strh r0, [r5]
	mov r0, #0x62
	lsl r0, r0, #2
	strh r0, [r5, #2]
	ldr r0, [sp, #0x20]
	add r5, r5, #4
	add r0, #0x6c
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	add r0, r0, #1
	str r0, [sp, #0x24]
	cmp r0, #3
	blt _021F9B96
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	add r0, sp, #0x40
	mov r2, #0x3a
	mov r3, #0x89
	str r0, [sp, #8]
	lsl r2, r2, #4
	lsl r3, r3, #2
	ldr r2, [r4, r2]
	ldr r3, [r4, r3]
	add r0, r6, #0
	mov r1, #0
	bl ov96_021E634C
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021F9C12
	add r0, r6, #0
	add r1, sp, #0xec
	bl ov96_021FBBB4
_021F9C12:
	add r0, r6, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r5, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	mov r3, #0
	mov r1, #0x11
_021F9C24:
	add r2, r0, r3
	strb r1, [r2, #0x1c]
	add r2, r3, #1
	lsl r2, r2, #0x18
	lsr r3, r2, #0x18
	cmp r3, #6
	blo _021F9C24
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021F9C56
	add r5, #0x28
	add r0, r5, #0
	bl ov96_021E8A20
	mov r3, #0
	mov r2, #0x11
_021F9C48:
	add r1, r0, r3
	strb r2, [r1, #0x1c]
	add r1, r3, #1
	lsl r1, r1, #0x18
	lsr r3, r1, #0x18
	cmp r3, #6
	blo _021F9C48
_021F9C56:
	mov r0, #1
	bl sub_0203A994
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9C7C:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021F9C8A
	add sp, #0x180
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021F9C8A:
	mov r0, #0
	add sp, #0x180
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F9C90: .word ov96_0221C3F4
_021F9C94: .word ov96_0221C3EC
_021F9C98: .word 0x04000010
_021F9C9C: .word 0x04001010
_021F9CA0: .word ov96_0221C410
	thumb_func_end ov96_021F94A8


	thumb_func_start ov96_021F9CA4
ov96_021F9CA4: ; 0x021F9CA4
	push {r4, lr}
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021FC314
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB5BC
	mov r0, #1
	pop {r4, pc}
	thumb_func_end ov96_021F9CA4


	thumb_func_start ov96_021F9CC4
ov96_021F9CC4: ; 0x021F9CC4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r6, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r0, r6, #0
	bl PokeathlonCourse_GetGraphicsSystem
	str r0, [sp, #0x1c]
	bl ov96_021E9510
	mov r5, #0
_021F9CDC:
	lsl r1, r5, #0x18
	add r0, r6, #0
	lsr r1, r1, #0x18
	bl PokeathlonCourse_GetField5F0_AtIndex
	add r4, r0, #0
	mov r1, #0x1e
	bl _s32_div_f
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #0x1e
	bl _s32_div_f
	mov r0, #0xa
	mul r0, r1
	mov r1, #0x1e
	bl _s32_div_f
	str r7, [sp]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	mov r0, #3
	str r0, [sp, #0x10]
	mov r0, #1
	str r0, [sp, #0x14]
	ldr r0, _021F9D54 ; =0x00000123
	lsl r3, r4, #0x10
	str r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r0, r6, #0
	add r2, r5, #0
	lsr r3, r3, #0x10
	bl ov96_021E966C
	add r5, r5, #1
	cmp r5, #4
	blt _021F9CDC
	ldr r0, [sp, #0x1c]
	mov r1, #2
	bl ov96_021E93B4
	ldr r0, [sp, #0x1c]
	mov r1, #0
	bl ov96_0221A56C
	ldr r0, [sp, #0x1c]
	bl ov96_021E952C
	ldr r0, [sp, #0x1c]
	mov r1, #0
	bl ov96_021E9570
	mov r0, #1
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F9D54: .word 0x00000123
	thumb_func_end ov96_021F9CC4


	thumb_func_start ov96_021F9D58
ov96_021F9D58: ; 0x021F9D58
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	bl sub_0203A914
	add r0, r5, #0
	bl PokeathlonCourse_GetSystem
	mov r1, #0
	bl ov96_021E87B0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021FC1A8
	add r0, r5, #0
	bl PokeathlonCourse_ResetField3A4
	add r0, r4, #0
	add r0, #0xdc
	ldr r0, [r0]
	bl ov96_021FC690
	add r0, r4, #0
	add r0, #0xd8
	ldr r0, [r0]
	bl ov96_021FC05C
	ldr r0, [r4, #4]
	mov r1, #0
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #2
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #3
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #4
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #6
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #7
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	add r0, #8
	bl RemoveWindow
	ldr r0, [r4, #4]
	bl Heap_Free
	mov r0, #0xe9
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EA894
	mov r0, #0x3a
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_021E9C0C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB21C
	bl ov96_021E92D0
	mov r0, #4
	bl FontID_Release
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	add r0, r5, #0
	bl PokeathlonCourse_FreePtr4HeapAlloc
	ldr r0, _021F9E38 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #0x8a
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_021F9E38: .word gSystem + 0x60
	thumb_func_end ov96_021F9D58


	thumb_func_start ov96_021F9E3C
ov96_021F9E3C: ; 0x021F9E3C
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _021F9E58 ; =ov96_0221C534
	add r3, sp, #0
	mov r2, #5
_021F9E46:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021F9E46
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_021F9E58: .word ov96_0221C534
	thumb_func_end ov96_021F9E3C


	thumb_func_start ov96_021F9E5C
ov96_021F9E5C: ; 0x021F9E5C
	push {r3, r4, r5, lr}
	sub sp, #0xf0
	ldr r5, _021F9FC4 ; =ov96_0221C434
	add r3, sp, #0xe0
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _021F9FC8 ; =ov96_0221C48C
	add r3, sp, #0xc4
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0
	str r0, [r3]
	add r0, r4, #0
	add r3, r1, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021F9FCC ; =ov96_0221C4A8
	add r3, sp, #0xa8
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #1
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021F9FD0 ; =ov96_0221C4C4
	add r3, sp, #0x8c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #2
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021F9FD4 ; =ov96_0221C4E0
	add r3, sp, #0x70
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #3
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021F9FD8 ; =ov96_0221C454
	add r3, sp, #0x54
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #4
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021F9FDC ; =ov96_0221C470
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #5
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021F9FE0 ; =ov96_0221C518
	add r3, sp, #0x1c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #6
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021F9FE4 ; =ov96_0221C4FC
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #7
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add sp, #0xf0
	pop {r3, r4, r5, pc}
	nop
_021F9FC4: .word ov96_0221C434
_021F9FC8: .word ov96_0221C48C
_021F9FCC: .word ov96_0221C4A8
_021F9FD0: .word ov96_0221C4C4
_021F9FD4: .word ov96_0221C4E0
_021F9FD8: .word ov96_0221C454
_021F9FDC: .word ov96_0221C470
_021F9FE0: .word ov96_0221C518
_021F9FE4: .word ov96_0221C4FC
	thumb_func_end ov96_021F9E5C


	thumb_func_start ov96_021F9FE8
ov96_021F9FE8: ; 0x021F9FE8
	push {r3, r4, r5, lr}
	sub sp, #0x10
	mov r3, #0
	str r3, [sp]
	add r5, r0, #0
	str r3, [sp, #4]
	add r4, r1, #0
	str r3, [sp, #8]
	mov r0, #0x9c
	mov r1, #1
	add r2, r5, #0
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x9c
	mov r1, #1
	add r2, r5, #0
	mov r3, #4
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadCharData
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021F9FE8


	thumb_func_start ov96_021FA020
ov96_021FA020: ; 0x021FA020
	push {r3, r4, r5, lr}
	sub sp, #0x10
	mov r3, #0
	str r3, [sp]
	add r5, r0, #0
	str r3, [sp, #4]
	add r4, r1, #0
	str r3, [sp, #8]
	mov r0, #0x9c
	mov r1, #2
	add r2, r5, #0
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x9c
	mov r1, #3
	add r2, r5, #0
	mov r3, #1
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x9c
	mov r1, #4
	add r2, r5, #0
	mov r3, #2
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x9c
	mov r1, #2
	add r2, r5, #0
	mov r3, #4
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x9c
	mov r1, #3
	add r2, r5, #0
	mov r3, #5
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x9c
	mov r1, #4
	add r2, r5, #0
	mov r3, #6
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x9c
	mov r1, #5
	add r2, r5, #0
	mov r3, #7
	str r4, [sp, #0xc]
	bl GfGfxLoader_LoadScrnData
	mov r1, #0
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x9c
	add r2, r1, #0
	add r3, r1, #0
	str r4, [sp, #4]
	bl GfGfxLoader_GXLoadPal
	mov r0, #0x20
	str r0, [sp]
	mov r1, #0
	mov r0, #0x9c
	mov r2, #4
	add r3, r1, #0
	str r4, [sp, #4]
	bl GfGfxLoader_GXLoadPal
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021FA020


	thumb_func_start ov96_021FA0E8
ov96_021FA0E8: ; 0x021FA0E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	ldr r5, [sp, #0x60]
	str r0, [sp]
	ldr r4, [sp, #0x64]
	mov r0, #0
	strh r0, [r4]
	add r6, r1, #0
	strh r0, [r4, #2]
	mov r1, #0x30
	strh r1, [r4, #4]
	mov r1, #5
	lsl r1, r1, #6
	strh r1, [r4, #6]
	add r1, r4, #0
	str r2, [sp, #4]
	strb r5, [r4, #0x18]
	mov r2, #1
	add r1, #0x68
	strh r2, [r1]
	mov r1, #0xfe
	lsl r1, r1, #0x16
	str r1, [r4, #0x64]
	strb r0, [r4, #8]
	add r0, r3, #0
	add r1, r5, #0
	bl ov96_021FC0D0
	str r0, [r4, #0x20]
	cmp r5, #0
	beq _021FA130
	cmp r5, #1
	beq _021FA13A
	cmp r5, #2
	beq _021FA144
	b _021FA14C
_021FA130:
	mov r0, #0
	strh r0, [r4, #0x14]
	mov r0, #4
	strh r0, [r4, #0x16]
	b _021FA14C
_021FA13A:
	mov r0, #1
	strh r0, [r4, #0x14]
	mov r0, #5
	strh r0, [r4, #0x16]
	b _021FA14C
_021FA144:
	mov r0, #2
	strh r0, [r4, #0x14]
	mov r0, #6
	strh r0, [r4, #0x16]
_021FA14C:
	cmp r5, #0
	beq _021FA15A
	cmp r5, #1
	beq _021FA162
	cmp r5, #2
	beq _021FA16A
	b _021FA172
_021FA15A:
	mov r0, #0x30
	mov r1, #0
	str r0, [sp, #8]
	b _021FA17A
_021FA162:
	mov r0, #0x80
	mov r1, #1
	str r0, [sp, #8]
	b _021FA17A
_021FA16A:
	mov r0, #0xd0
	mov r1, #2
	str r0, [sp, #8]
	b _021FA17A
_021FA172:
	bl GF_AssertFail
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
_021FA17A:
	lsl r1, r1, #0x18
	ldr r0, [sp, #0x5c]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	str r0, [sp, #0xc]
	bl ov96_021EAA20
	ldr r1, [sp, #0xc]
	str r1, [r4, #0x24]
	bl ov96_021E8BB0
	str r0, [sp, #0x10]
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	add r2, r5, #0
	bl ov96_021E60D8
	add r7, r0, #0
	ldrb r0, [r7, #2]
	lsl r0, r0, #2
	ldr r1, [r6, r0]
	add r0, r4, #0
	add r0, #0x5c
	strh r1, [r0]
	ldrb r0, [r7, #2]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r1, [r0, #0x14]
	add r0, r4, #0
	add r0, #0x5e
	strh r1, [r0]
	add r0, r4, #0
	ldrb r1, [r7, #2]
	add r0, #0x58
	strb r1, [r0]
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	add r2, r5, #0
	bl ov96_021E60C0
	bl ov96_021E6138
	sub r0, r0, #1
	lsl r2, r0, #3
	ldr r1, [sp, #4]
	ldr r3, [sp, #4]
	ldr r1, [r1, r2]
	add r2, r3, r2
	ldr r0, [sp, #0xc]
	ldr r2, [r2, #4]
	bl ov96_021EAF70
	bl ov96_021E6104
	add r1, r0, #0
	ldr r0, [sp, #0xc]
	bl ov96_021EAF6C
	ldrb r0, [r7, #1]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r0, [r0, #0x3c]
	bl _fflt
	ldr r1, _021FA338 ; =0x41200000
	bl _fdiv
	str r0, [r4, #0x50]
	ldrb r0, [r7, #4]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r0, [r0, #0x28]
	bl _fflt
	ldr r1, _021FA33C ; =0x42C80000
	bl _fdiv
	str r0, [r4, #0x54]
	ldr r0, [sp, #0x10]
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _021FA236
	mov r0, #2
	lsl r0, r0, #0x10
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
	b _021FA23E
_021FA236:
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
_021FA23E:
	mov r3, #0x78
	str r3, [r4, #0x3c]
	add r2, r3, #0
	add r3, #0x98
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #8]
	add r2, r2, r3
	bl ov96_021EAF94
	ldr r0, [sp, #0xc]
	mov r1, #1
	bl ov96_021EAC0C
	ldr r0, [sp, #0xc]
	mov r1, #4
	bl ov96_021EABA8
	ldr r0, [sp, #0xc]
	mov r1, #2
	bl ov96_021EABE0
	ldr r0, [sp, #0xc]
	add r1, sp, #0x38
	bl ov96_021EABF4
	ldr r0, [sp, #0x58]
	mov r1, #0x66
	mov r2, #5
	bl ov96_021EB4F4
	str r0, [r4, #0x44]
	bl ov96_021EB5B8
	mov r1, #0x12
	ldr r2, [r4, #0x3c]
	lsl r1, r1, #4
	add r1, r2, r1
	str r1, [r4, #0x40]
	mov r1, #0
	str r1, [sp, #0x34]
	ldr r1, [sp, #8]
	add r6, r0, #0
	lsl r5, r1, #0xc
	str r5, [sp, #0x2c]
	ldr r1, [r4, #0x40]
	lsl r1, r1, #0xc
	str r1, [sp, #0x30]
	add r1, sp, #0x2c
	bl Sprite_SetMatrix
	ldr r0, [r4, #0x44]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	add r0, r6, #0
	mov r1, #3
	bl Sprite_SetDrawPriority
	ldr r0, [sp, #0x58]
	mov r1, #0x68
	mov r2, #7
	bl ov96_021EB4F4
	str r0, [r4, #0x48]
	bl ov96_021EB5B8
	mov r1, #0
	add r6, r0, #0
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0
	str r0, [sp, #0x28]
	mov r0, #0x6b
	lsl r0, r0, #0xe
	str r0, [sp, #0x24]
	add r0, r6, #0
	add r1, sp, #0x20
	str r5, [sp, #0x20]
	bl Sprite_SetMatrix
	add r0, r6, #0
	mov r1, #4
	bl Sprite_SetDrawPriority
	add r0, r6, #0
	mov r1, #2
	bl Sprite_SetAffineOverwriteMode
	ldr r0, [sp, #0x58]
	mov r1, #0x69
	mov r2, #8
	bl ov96_021EB4F4
	str r0, [r4, #0x4c]
	bl ov96_021EB5B8
	mov r1, #0
	add r6, r0, #0
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0
	str r0, [sp, #0x1c]
	mov r0, #0x62
	lsl r0, r0, #0xe
	str r0, [sp, #0x18]
	str r5, [sp, #0x14]
	add r0, r6, #0
	add r1, sp, #0x14
	bl Sprite_SetMatrix
	mov r1, #1
	ldr r0, [r4, #0x4c]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r6, #0
	mov r1, #2
	bl Sprite_SetDrawPriority
	mov r0, #0xfe
	lsl r0, r0, #0x16
	str r0, [r4, #0xc]
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FA338: .word 0x41200000
_021FA33C: .word 0x42C80000
	thumb_func_end ov96_021FA0E8

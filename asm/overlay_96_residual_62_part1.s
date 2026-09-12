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

	thumb_func_start ov96_021F7934
ov96_021F7934: ; 0x021F7934
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetField1ED
	cmp r0, #5
	bls _021F794C
	b _021F7C2E
_021F794C:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021F7958: ; jump table
	.short _021F7964 - _021F7958 - 2 ; case 0
	.short _021F7A04 - _021F7958 - 2 ; case 1
	.short _021F7AA0 - _021F7958 - 2 ; case 2
	.short _021F7B90 - _021F7958 - 2 ; case 3
	.short _021F7BFC - _021F7958 - 2 ; case 4
	.short _021F7C20 - _021F7958 - 2 ; case 5
_021F7964:
	mov r2, #1
	mov r0, #0x5c
	mov r1, #0x89
	lsl r2, r2, #0x12
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
	ldr r0, _021F7C38 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021F7C3C ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	bl ov96_021F7D10
	add r0, r5, #0
	mov r1, #0xac
	bl PokeathlonCourse_AllocPtr4FromHeap
	mov r1, #0
	mov r2, #0xac
	add r4, r0, #0
	bl MI_CpuFill8
	mov r1, #0x89
	mov r0, #4
	str r1, [r4]
	bl FontID_Alloc
	mov r0, #0x89
	bl BgConfig_Alloc
	str r0, [r4, #0xc]
	ldr r0, [r4]
	bl ov96_021EE740
	str r0, [r4, #0x18]
	add r0, r4, #0
	ldr r2, [r4, #0xc]
	add r0, #0x1c
	mov r1, #0x89
	add r3, r5, #0
	bl ov96_021F8094
	add r0, r5, #0
	bl PokeathlonCourse_GetField3D8_ForCurrentParticipant
	ldr r1, [r4]
	bl ov96_021EE5B4
	add r1, r4, #0
	add r1, #0x80
	str r0, [r1]
	add r0, r4, #0
	bl ov96_021F8448
	ldr r0, _021F7C40 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	add r0, r5, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F7C32
_021F7A04:
	ldr r6, _021F7C44 ; =ov96_0221C2A8
	add r3, sp, #0x1c
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r4]
	bl ov96_021EB180
	mov r1, #0
	str r0, [r4, #0x10]
	mov r0, #0x4b
	lsl r0, r0, #0xe
	str r0, [sp]
	ldr r0, [r4, #0x10]
	add r2, r1, #0
	add r3, r1, #0
	bl ov96_021EB5C8
	add r0, r5, #0
	bl PokeathlonCourse_GetGraphicsSystem
	add r7, r0, #0
	bl ov96_021E9524
	add r6, r0, #0
	add r0, r7, #0
	bl ov96_021E9528
	add r3, r0, #0
	add r0, r4, #0
	lsl r2, r6, #0x18
	add r0, #0x1c
	add r1, r5, #0
	lsr r2, r2, #0x18
	bl ov96_021F80A8
	ldr r0, [r4]
	ldr r1, [r4, #0xc]
	ldr r2, [r4, #0x10]
	bl ov96_021F8EB0
	str r0, [r4, #0x14]
	mov r1, #2
	bl ov96_021F8F44
	ldr r0, [r4, #0x10]
	bl ov96_021EB3A4
	mov r2, #0x4b
	ldr r0, [r4, #0x14]
	add r1, r5, #0
	lsl r2, r2, #2
	bl ov96_021F8F94
	add r0, r4, #0
	bl ov96_021F8528
	add r0, r4, #0
	bl ov96_021F85A0
	mov r0, #2
	bl ov96_021EEBC8
	add r1, r0, #0
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	ldr r3, [r4]
	mov r2, #0xb
	bl ov96_021EEA88
	add r0, r5, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F7C32
_021F7AA0:
	ldr r0, [r4, #0xc]
	bl PokeathlonCourse_SetVBlankIntrCB
	ldr r0, [r4, #0xc]
	ldr r1, [r4]
	bl ov96_021F7D30
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	ldr r1, [r4, #0xc]
	bl ov96_021EE60C
	add r0, r4, #0
	bl ov96_021F7DA8
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	bl ov96_021EE644
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	add r0, r5, #0
	bl PokeathlonCourse_GetMode
	add r6, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetSaveData
	str r0, [sp]
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0xc]
	mov r2, #5
	add r3, r6, #0
	bl ov96_021EE75C
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	bl ov96_021EE6A0
	mov r0, #0
	mov r1, #1
	lsl r1, r1, #0xc
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	bl OS_WaitVBlankIntr
	add r0, sp, #0xc
	str r0, [sp]
	mov r0, #0x80
	str r0, [sp, #4]
	mov r0, #0x60
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #7
	mov r2, #1
	mov r3, #0
	bl Bg_SetTextDimAndAffineParams
	add r0, sp, #0xc
	str r0, [sp]
	mov r0, #0x80
	str r0, [sp, #4]
	mov r0, #0x60
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #7
	mov r2, #5
	mov r3, #0x10
	bl Bg_SetTextDimAndAffineParams
	add r0, sp, #0xc
	str r0, [sp]
	mov r0, #0x80
	str r0, [sp, #4]
	mov r0, #0x60
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #6
	mov r2, #1
	mov r3, #0
	bl Bg_SetTextDimAndAffineParams
	add r0, sp, #0xc
	str r0, [sp]
	mov r0, #0x80
	str r0, [sp, #4]
	mov r0, #0x60
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #6
	mov r2, #5
	mov r3, #0x10
	bl Bg_SetTextDimAndAffineParams
	add r0, r4, #0
	ldr r1, [r4, #0xc]
	ldr r2, [r4]
	add r0, #0x84
	bl ov96_021F7878
	add r0, r4, #0
	ldr r1, [r4]
	add r0, #0x84
	bl ov96_021F78C4
	add r0, r5, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F7C32
_021F7B90:
	add r0, r5, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021F7BB4
	add r0, r5, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0x28
	bl ov96_021E8A20
	add r4, r0, #0
	bl MTRandom
	mov r1, #5
	bl _u32_div_f
	strb r1, [r4]
_021F7BB4:
	add r0, r5, #0
	bl PokeathlonCourse_GetMode
	cmp r0, #1
	bne _021F7BCC
	mov r0, #1
	bl sub_0203A994
	bl sub_0203A9C8
	bl sub_0203A86C
_021F7BCC:
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add r0, r5, #0
	mov r1, #1
	bl PokeathlonCourse_SetField1F4
	add r0, r5, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F7C32
_021F7BFC:
	ldr r0, _021F7C48 ; =0x00000473
	bl PlayBGM
	mov r0, #6
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r4]
	add r2, r1, #0
	str r0, [sp, #8]
	mov r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	add r0, r5, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F7C32
_021F7C20:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021F7C32
	add sp, #0x28
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021F7C2E:
	bl GF_AssertFail
_021F7C32:
	mov r0, #0
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F7C38: .word 0xFFFFE0FF
_021F7C3C: .word 0x04001000
_021F7C40: .word gSystem + 0x60
_021F7C44: .word ov96_0221C2A8
_021F7C48: .word 0x00000473
	thumb_func_end ov96_021F7934

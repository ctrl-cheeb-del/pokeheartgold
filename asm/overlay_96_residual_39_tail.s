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

	thumb_func_start ov96_021ED17C
ov96_021ED17C: ; 0x021ED17C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	str r1, [sp]
	ldr r7, _021ED1CC ; =0x00000000
	bne _021ED18C
	bl GF_AssertFail
_021ED18C:
	mov r0, #0
	add r4, r6, #0
	str r0, [sp, #4]
	add r4, #0x18
	add r5, r6, #4
_021ED196:
	ldr r0, [r4]
	lsl r0, r0, #0xb
	lsr r0, r0, #0x1f
	bne _021ED1B8
	mov r1, #0x5b
	mov r2, #0x17
	lsl r1, r1, #2
	lsl r2, r2, #4
	ldr r1, [r6, r1]
	ldr r2, [r6, r2]
	add r0, r5, #0
	bl ov96_021ECDEC
	ldr r0, [sp]
	add r7, r7, #1
	cmp r7, r0
	bge _021ED1C6
_021ED1B8:
	ldr r0, [sp, #4]
	add r4, #0x18
	add r0, r0, #1
	add r5, #0x18
	str r0, [sp, #4]
	cmp r0, #0xf
	blt _021ED196
_021ED1C6:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021ED1CC: .word 0x00000000
	thumb_func_end ov96_021ED17C


	thumb_func_start ov96_021ED1D0
ov96_021ED1D0: ; 0x021ED1D0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x118
	str r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetField1ED
	cmp r0, #3
	bls _021ED1E8
	b _021ED462
_021ED1E8:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021ED1F4: ; jump table
	.short _021ED1FC - _021ED1F4 - 2 ; case 0
	.short _021ED296 - _021ED1F4 - 2 ; case 1
	.short _021ED336 - _021ED1F4 - 2 ; case 2
	.short _021ED39A - _021ED1F4 - 2 ; case 3
_021ED1FC:
	mov r2, #6
	mov r0, #0x5c
	mov r1, #0x87
	lsl r2, r2, #0x10
	bl Heap_Create
	ldr r0, _021ED46C ; =FS_OVERLAY_ID(OVY_98)
	mov r1, #2
	bl HandleLoadOverlay
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
	ldr r0, _021ED470 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021ED474 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	bl ov96_021EB6A8
	ldr r0, [sp, #8]
	mov r1, #0xbc
	bl PokeathlonCourse_AllocPtr4FromHeap
	mov r1, #0
	mov r2, #0xbc
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x87
	str r0, [r4]
	ldr r0, [sp, #8]
	bl ov96_021E5E7C
	add r1, r4, #0
	add r1, #0xb1
	strb r0, [r1]
	ldr r0, [r4]
	bl BgConfig_Alloc
	str r0, [r4, #4]
	ldr r0, [r4]
	bl ov96_021EE740
	str r0, [r4, #0xc]
	add r0, r4, #0
	bl ov96_021EC490
	ldr r0, [r4]
	mov r1, #6
	mov r2, #1
	bl ov96_021E9A78
	str r0, [r4, #0x10]
	ldr r0, _021ED478 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	ldr r0, [sp, #8]
	bl PokeathlonCourse_IncrementField1ED
	b _021ED466
_021ED296:
	mov r0, #0
	add r2, sp, #0x14
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [r2]
	ldr r0, [sp, #0xc]
	ldr r0, [r0, #0x1c]
	bl SpriteManager_GetSpriteList
	str r0, [sp]
	ldr r0, [sp, #0xc]
	ldr r3, [sp, #0xc]
	ldr r0, [r0]
	ldr r3, [r3, #0x10]
	mov r1, #0xc
	mov r2, #3
	bl ov96_021EA854
	ldr r1, [sp, #0xc]
	mov r4, #0
	str r0, [r1, #0x14]
	add r6, sp, #0x58
	add r5, sp, #0x14
_021ED2D2:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r1, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x10]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x10]
	add r2, r7, #0
	add r3, r6, #0
	bl ov96_021E6168
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x10]
	add r2, r7, #0
	bl ov96_021E60C0
	bl ov96_021E6108
	str r0, [r5, #0x14]
	add r4, r4, #1
	add r6, #0x10
	add r5, r5, #4
	cmp r4, #0xc
	blt _021ED2D2
	mov r0, #3
	mov r1, #0
	str r0, [sp, #0x18]
	mov r0, #1
	str r1, [sp, #0x14]
	str r1, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #0xc]
	mov r1, #0xc
	ldr r0, [r0, #0x14]
	add r2, sp, #0x58
	add r3, sp, #0x14
	bl ov96_021EA8A8
	ldr r0, [sp, #8]
	bl PokeathlonCourse_IncrementField1ED
	b _021ED466
_021ED336:
	ldr r0, [sp, #0xc]
	ldr r0, [r0, #0x14]
	bl ov96_021EAA00
	cmp r0, #0
	bne _021ED344
	b _021ED466
_021ED344:
	ldr r0, [sp, #8]
	bl ov96_021EC82C
	ldr r0, [sp, #0xc]
	bl ov96_021EC550
	ldr r0, [sp, #0xc]
	bl ov96_021EC5C0
	ldr r0, [sp, #0xc]
	bl ov96_021EC68C
	ldr r0, [sp, #0xc]
	bl ov96_021EC70C
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0xc]
	ldr r0, [r0]
	add r1, #0x20
	bl ov96_021ECBB8
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0xc]
	add r1, #0x8c
	str r0, [r1]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0xc]
	ldr r0, [r0]
	ldr r1, [r1, #0x18]
	ldr r2, [r2, #0x1c]
	bl ov96_021ED054
	ldr r1, [sp, #0xc]
	add r1, #0x90
	str r0, [r1]
	ldr r0, [sp, #8]
	str r1, [sp, #0xc]
	bl ov96_021ECAC4
	ldr r0, [sp, #8]
	bl PokeathlonCourse_IncrementField1ED
	b _021ED466
_021ED39A:
	ldr r0, [sp, #0xc]
	ldr r0, [r0, #4]
	bl PokeathlonCourse_SetVBlankIntrCB
	ldr r0, [sp, #8]
	mov r1, #1
	bl PokeathlonCourse_SetField1F4
	mov r5, #0
	add r6, r5, #0
_021ED3AE:
	ldr r0, [sp, #0xc]
	lsl r1, r5, #0x18
	ldr r0, [r0, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r4, r0, #0
	mov r1, #1
	bl ov96_021EAB38
	add r0, r4, #0
	bl ov96_021EAA20
	bl ov96_021E8BAC
	bl Sprite_GetCellAnim
	lsl r1, r6, #0xc
	str r1, [r0, #0x10]
	add r0, r4, #0
	mov r1, #1
	bl ov96_021EAC0C
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r0, #0
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	lsl r1, r7, #6
	add r3, r2, #1
	mov r2, #0x30
	add r0, r4, #0
	add r1, #0x20
	mul r2, r3
	bl ov96_021EAF94
	add r5, r5, #1
	add r6, r6, #3
	cmp r5, #0xc
	blt _021ED3AE
	ldr r0, [sp, #0xc]
	ldr r0, [r0, #4]
	bl ov96_021EC2E8
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0xc]
	ldr r0, [r0, #4]
	ldr r1, [r1]
	bl ov96_021EC3D8
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetMode
	add r4, r0, #0
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetSaveData
	str r0, [sp]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0xc]
	ldr r0, [r0, #0xc]
	ldr r1, [r1, #4]
	mov r2, #4
	add r3, r4, #0
	bl ov96_021EE75C
	mov r0, #2
	bl sub_0203A994
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, [sp, #0xc]
	mov r1, #0
	add r0, #0xb5
	str r0, [sp, #0xc]
	strb r1, [r0]
	add sp, #0x118
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021ED462:
	bl GF_AssertFail
_021ED466:
	mov r0, #0
	add sp, #0x118
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021ED46C: .word FS_OVERLAY_ID(OVY_98)
_021ED470: .word 0xFFFFE0FF
_021ED474: .word 0x04001000
_021ED478: .word gSystem + 0x60
	thumb_func_end ov96_021ED1D0

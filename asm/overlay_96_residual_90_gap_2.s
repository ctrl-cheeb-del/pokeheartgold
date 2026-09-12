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

	thumb_func_start ov96_02207DDC
ov96_02207DDC: ; 0x02207DDC
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #5
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xe2
	add r3, r1, #0
	bl GfGfxLoader_LoadCharData
	mov r1, #0
	mov r0, #2
	str r1, [sp]
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4]
	mov r1, #6
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xe2
	add r3, r1, #0
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #7
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xe2
	mov r3, #5
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #8
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xe2
	mov r3, #6
	bl GfGfxLoader_LoadScrnData
	ldr r0, [r4]
	add r3, r4, #0
	str r0, [sp]
	mov r0, #0xe2
	mov r1, #9
	mov r2, #0
	add r3, #0x28
	bl GfGfxLoader_GetScrnData
	str r0, [r4, #0x24]
	mov r0, #0x40
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #4
	str r0, [sp, #4]
	mov r0, #0xe2
	add r2, r1, #0
	mov r3, #0
	bl GfGfxLoader_GXLoadPal
	add r0, r4, #0
	mov r1, #0
	bl ov96_02208374
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02207DDC


	thumb_func_start ov96_02207E7C
ov96_02207E7C: ; 0x02207E7C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r0, _02207F14 ; =ov96_0221CBCC
	add r5, r1, #0
	ldr r1, [r0, #8]
	ldr r0, [r0, #0xc]
	add r4, sp, #8
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	mov r6, #0
	mov r7, #2
_02207E92:
	str r7, [sp]
	ldr r3, [r4]
	add r0, r5, #0
	mov r1, #0x5d
	mov r2, #9
	bl ov96_021EB2BC
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r3, [r4]
	add r0, r5, #0
	mov r1, #0x5d
	mov r2, #6
	bl ov96_021EB2F4
	ldr r3, [r4]
	add r0, r5, #0
	mov r1, #0x5d
	mov r2, #0xa
	bl ov96_021EB334
	ldr r3, [r4]
	add r0, r5, #0
	mov r1, #0x5d
	mov r2, #0xa
	bl ov96_021EB36C
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #2
	blt _02207E92
	mov r0, #2
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0xe2
	mov r2, #0xd
	mov r3, #0x65
	bl ov96_021EB2BC
	mov r0, #2
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #0xe2
	mov r2, #0xa
	mov r3, #0x65
	bl ov96_021EB2F4
	add r0, r5, #0
	mov r1, #0xe2
	mov r2, #0xc
	mov r3, #0x65
	bl ov96_021EB334
	add r0, r5, #0
	mov r1, #0xe2
	mov r2, #0xb
	mov r3, #0x65
	bl ov96_021EB36C
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02207F14: .word ov96_0221CBCC
	thumb_func_end ov96_02207E7C


	thumb_func_start ov96_02207F18
ov96_02207F18: ; 0x02207F18
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	str r0, [sp, #4]
	mov r0, #0
	add r5, r1, #0
	str r0, [sp, #0x18]
	ldr r0, [sp, #4]
	mov r1, #0x4f
	lsl r1, r1, #2
	add r7, r0, r1
	add r1, #0x40
	str r0, [sp, #0x14]
	add r0, r0, r1
	str r2, [sp, #8]
	str r0, [sp, #0x10]
_02207F36:
	mov r2, #2
	add r0, r5, #0
	mov r1, #3
	mov r3, #0x65
	str r2, [sp]
	bl ov96_021EB3E4
	ldr r1, [sp, #0x14]
	mov r2, #2
	str r0, [r1, #0x38]
	mov r1, #3
	add r0, r5, #0
	mov r3, #0x65
	str r1, [sp]
	bl ov96_021EB3E4
	ldr r1, [sp, #0x14]
	mov r2, #2
	str r0, [r1, #0x40]
	mov r0, #0xa
	str r0, [sp]
	add r0, r5, #0
	mov r1, #3
	mov r3, #0x65
	bl ov96_021EB3E4
	ldr r1, [sp, #0x14]
	mov r3, #0x65
	str r0, [r1, #0x3c]
	mov r0, #0x13
	mov r1, #2
	str r0, [sp]
	add r0, r5, #0
	add r2, r1, #0
	bl ov96_021EB3E4
	str r0, [r7, #8]
	mov r1, #0
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r7, #8]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r0, #0x15
	mov r1, #2
	str r0, [sp]
	add r0, r5, #0
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	str r0, [r7, #4]
	mov r1, #9
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r7, #4]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r0, #0x14
	mov r1, #2
	str r0, [sp]
	add r0, r5, #0
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	str r0, [r7]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ldr r0, [r0, #0x38]
	add r1, #0x13
	bl ov96_021EB564
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	ldr r0, [r0, #0x40]
	add r1, r1, #5
	bl ov96_021EB564
	ldr r0, [r7]
	mov r1, #3
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r7]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r4, [sp, #0x10]
	mov r6, #0
_02207FF2:
	mov r0, #0x18
	mov r1, #2
	str r0, [sp]
	add r0, r5, #0
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	mov r1, #2
	stmia r4!, {r0}
	bl ov96_021EB564
	add r6, r6, #1
	cmp r6, #2
	blt _02207FF2
	ldr r0, [sp, #0x14]
	add r7, #0x10
	add r0, #0x1c
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, #8
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #4
	blt _02207F36
	ldr r3, _022080E8 ; =ov96_0221CBF4
	add r2, sp, #0x1c
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #3
	str r0, [r2]
	mov r0, #0x16
	str r0, [sp]
	add r0, r5, #0
	mov r2, #2
	mov r3, #0x65
	bl ov96_021EB3E4
	mov r2, #0x4e
	ldr r1, [sp, #4]
	lsl r2, r2, #2
	str r0, [r1, r2]
	add r0, r1, #0
	ldr r0, [r0, r2]
	mov r1, #4
	bl ov96_021EB564
	mov r1, #0x4e
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	mov r1, #1
	add r2, r1, #0
	bl ov96_021EB52C
	mov r1, #0x4e
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	add r1, sp, #0x1c
	bl ov96_021EB588
	ldr r1, [sp, #4]
	add r0, r5, #0
	bl ov96_02208914
	mov r0, #0
	ldr r4, [sp, #4]
	ldr r7, _022080EC ; =ov96_0221CBC4
	ldr r6, _022080F0 ; =ov96_0221CBC8
	str r0, [sp, #0xc]
_02208086:
	add r0, r5, #0
	bl ov96_021EB5E8
	ldr r3, [sp, #4]
	add r1, r0, #0
	ldr r0, [sp, #8]
	ldr r3, [r3]
	mov r2, #3
	bl ov96_021EA2C4
	mov r1, #0x6d
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldrb r0, [r7]
	add r1, sp, #0x28
	lsl r0, r0, #0xc
	str r0, [sp, #0x28]
	mov r0, #0xb1
	lsl r0, r0, #0xe
	str r0, [sp, #0x2c]
	mov r0, #0
	str r0, [sp, #0x30]
	mov r0, #0x6d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_SetMatrix
	mov r0, #0x6d
	lsl r0, r0, #2
	ldrb r1, [r6]
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [sp, #0xc]
	add r4, r4, #4
	add r0, r0, #1
	add r7, r7, #1
	add r6, r6, #1
	str r0, [sp, #0xc]
	cmp r0, #2
	blt _02208086
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	nop
_022080E8: .word ov96_0221CBF4
_022080EC: .word ov96_0221CBC4
_022080F0: .word ov96_0221CBC8
	thumb_func_end ov96_02207F18


	thumb_func_start ov96_022080F4
ov96_022080F4: ; 0x022080F4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	str r0, [sp, #8]
	add r5, r1, #0
	ldr r1, [sp, #8]
	mov r0, #0x14
	ldr r1, [r1]
	bl NARC_New
	str r0, [sp, #0x20]
	bl sub_02074490
	add r1, r0, #0
	mov r0, #0x60
	str r0, [sp]
	ldr r0, [sp, #8]
	mov r2, #5
	ldr r0, [r0]
	mov r3, #0xc0
	str r0, [sp, #4]
	mov r0, #0x14
	bl GfGfxLoader_GXLoadPal
	ldr r4, [sp, #8]
	mov r7, #0
	add r6, r4, #0
	add r6, #0xcc
_0220812A:
	ldr r0, [sp, #8]
	mov r1, #1
	ldr r0, [r0]
	lsl r1, r1, #0xc
	bl Heap_AllocAtEnd
	add r1, r4, #0
	add r1, #0x9c
	str r0, [r1]
	ldrh r0, [r5, #2]
	mov r1, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x14]
	ldrh r0, [r5]
	ldr r2, [sp, #0x14]
	str r0, [sp, #0x10]
	bl GetMonIconNaixEx
	add r2, r4, #0
	add r2, #0x9c
	add r1, r0, #0
	ldr r0, [sp, #0x20]
	ldr r2, [r2]
	bl NARC_ReadWholeMember
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	add r1, r6, #0
	bl NNS_G2dGetUnpackedBGCharacterData
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	mov r2, #0
	bl GetMonIconPaletteEx
	add r1, r0, #6
	ldr r0, [sp, #8]
	add r4, r4, #4
	add r0, r0, r7
	add r0, #0xfc
	add r7, r7, #1
	strb r1, [r0]
	add r5, r5, #4
	add r6, r6, #4
	cmp r7, #0xc
	blt _0220812A
	ldr r0, [sp, #0x20]
	bl NARC_Delete
	mov r0, #0
	ldr r6, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, #0x70
	str r0, [sp, #0x1c]
	add r0, r6, #0
	str r0, [sp, #0x18]
	add r7, r6, #0
_022081A0:
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #8]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	mov r2, #0
	bl ov96_0220831C
	mov r1, #1
	ldr r0, [r6, #0x38]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r1, #1
	ldr r0, [r6, #0x40]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r0, #0
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x1c]
	add r1, sp, #0x24
	lsl r0, r0, #0xc
	str r0, [sp, #0x24]
	mov r0, #0x35
	lsl r0, r0, #0x10
	str r0, [sp, #0x28]
	ldr r0, [r6, #0x38]
	bl ov96_021EB588
	ldr r0, [r6, #0x40]
	add r1, sp, #0x24
	bl ov96_021EB588
	ldr r0, [r6, #0x3c]
	add r1, sp, #0x24
	bl ov96_021EB588
	ldr r5, [sp, #0x18]
	mov r4, #0
_022081EE:
	mov r0, #0x5f
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, sp, #0x24
	bl ov96_021EB588
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _022081EE
	mov r0, #2
	ldr r1, [sp, #0x28]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x28]
	mov r0, #0x4f
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	add r1, sp, #0x24
	bl ov96_021EB588
	mov r0, #5
	lsl r0, r0, #6
	ldr r0, [r7, r0]
	add r1, sp, #0x24
	bl ov96_021EB588
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	add r1, sp, #0x24
	bl ov96_021EB588
	ldr r0, [sp, #0x1c]
	add r6, #0x1c
	add r0, #0x28
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	add r7, #0x10
	add r0, #8
	str r0, [sp, #0x18]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #4
	blt _022081A0
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_022080F4

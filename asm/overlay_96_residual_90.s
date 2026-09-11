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

	thumb_func_start ov96_02207BE4
ov96_02207BE4: ; 0x02207BE4
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _02207C30 ; =0x00000512
	ldrb r1, [r5, r0]
	cmp r1, #4
	blo _02207C2A
	sub r0, r0, #1
	ldr r1, [r5, #0x1c]
	ldrb r0, [r5, r0]
	ldr r4, [r1, #0x14]
	mov r1, #2
	lsl r6, r0, #0xb
	add r0, r4, r6
	lsl r1, r1, #0xa
	bl DC_FlushRange
	mov r1, #6
	mov r2, #2
	add r0, r4, r6
	lsl r1, r1, #0xa
	lsl r2, r2, #0xa
	bl GX_LoadBG0Char
	ldr r0, _02207C30 ; =0x00000512
	mov r1, #0
	strb r1, [r5, r0]
	sub r0, r0, #1
	ldrb r0, [r5, r0]
	mov r1, #6
	add r0, r0, #1
	bl _s32_div_f
	ldr r0, _02207C34 ; =0x00000511
	strb r1, [r5, r0]
	pop {r4, r5, r6, pc}
_02207C2A:
	add r1, r1, #1
	strb r1, [r5, r0]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02207C30: .word 0x00000512
_02207C34: .word 0x00000511
	thumb_func_end ov96_02207BE4


	thumb_func_start ov96_02207C38
ov96_02207C38: ; 0x02207C38
	push {r4, lr}
	cmp r0, #0
	blt _02207C60
	mov r4, #1
	lsl r4, r4, #8
	cmp r0, r4
	bge _02207C60
	cmp r1, #0
	blt _02207C60
	cmp r1, #0xc0
	bge _02207C60
	cmp r3, #0
	beq _02207C56
	mov r1, #3
	b _02207C58
_02207C56:
	mov r1, #4
_02207C58:
	lsl r0, r2, #0x10
	lsr r0, r0, #0x10
	bl sub_0200606C
_02207C60:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02207C38


	thumb_func_start ov96_02207C64
ov96_02207C64: ; 0x02207C64
	push {r4, r5, r6, lr}
	add r4, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	add r5, r0, #0
	add r0, r4, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	add r0, r4, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	lsl r0, r1, #2
	lsl r1, r1, #1
	add r1, r5, r1
	ldrh r1, [r1, #0x18]
	ldr r0, [r5, r0]
	ldr r2, _02207CC8 ; =0x000003FF
	lsr r0, r0, #0x12
	asr r3, r1, #0xb
	mov r1, #0x1f
	and r0, r2
	and r1, r3
	lsl r0, r0, #0x10
	lsl r1, r1, #0x18
	lsr r0, r0, #0x10
	lsr r1, r1, #0x18
	add r0, r0, r1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	add r0, r2, #0
	sub r0, #0x18
	cmp r5, r0
	bls _02207CB6
	add r5, r2, #0
	sub r5, #0x18
_02207CB6:
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_021E8318
	add r0, r6, #0
	add r1, r5, #0
	bl ov96_02207774
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02207CC8: .word 0x000003FF
	thumb_func_end ov96_02207C64


	thumb_func_start ov96_02207CCC
ov96_02207CCC: ; 0x02207CCC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	mov r1, #0x72
	lsl r1, r1, #2
	add r6, r0, #0
	str r2, [sp]
	bl Heap_Alloc
	mov r2, #0x72
	add r7, r0, #0
	mov r1, #0
	lsl r2, r2, #2
	bl MI_CpuFill8
	str r6, [r7]
	ldr r0, [sp]
	str r4, [r7, #8]
	str r0, [r7, #4]
	add r0, r7, #0
	bl ov96_02208A4C
	ldr r2, _02207D60 ; =0x00000135
	mov r0, #1
	mov r1, #0x1b
	add r3, r6, #0
	bl NewMsgDataFromNarc
	str r0, [r7, #0x1c]
	add r0, r6, #0
	bl MessageFormat_New
	str r0, [r7, #0x20]
	mov r4, #0
	add r5, r7, #0
_02207D10:
	mov r0, #0xb
	add r1, r6, #0
	bl String_New
	mov r1, #0x6a
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _02207D10
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantUnk04
	add r4, r0, #0
	mov r6, #0
	add r5, r7, #0
_02207D3A:
	mov r0, #0x6a
	lsl r0, r0, #2
	add r1, r4, #0
	ldr r0, [r5, r0]
	add r1, #0x12
	bl CopyU16ArrayToString
	add r6, r6, #1
	add r4, #0x28
	add r5, r5, #4
	cmp r6, #3
	blt _02207D3A
	add r0, r7, #0
	mov r1, #1
	bl ov96_022088AC
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02207D60: .word 0x00000135
	thumb_func_end ov96_02207CCC


	thumb_func_start ov96_02207D64
ov96_02207D64: ; 0x02207D64
	push {r3, r4, r5, r6, r7, lr}
	mov r7, #0x42
	lsl r7, r7, #2
	str r0, [sp]
	mov r4, #0
	add r5, r0, #0
	add r6, r7, #4
_02207D72:
	ldr r0, [r5, r7]
	bl Heap_Free
	ldr r0, [r5, r6]
	bl Heap_Free
	add r4, r4, #1
	add r5, #8
	cmp r4, #3
	blt _02207D72
	ldr r4, [sp]
	mov r5, #0
_02207D8A:
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	bl Heap_Free
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #0xc
	blt _02207D8A
	ldr r0, [sp]
	ldr r0, [r0, #0x24]
	bl Heap_Free
	mov r6, #0x6a
	ldr r4, [sp]
	mov r5, #0
	lsl r6, r6, #2
_02207DAC:
	ldr r0, [r4, r6]
	bl String_Delete
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #3
	blt _02207DAC
	ldr r0, [sp]
	ldr r0, [r0, #0x20]
	bl MessageFormat_Delete
	ldr r0, [sp]
	ldr r0, [r0, #0x1c]
	bl DestroyMsgData
	ldr r0, [sp]
	add r0, #0xc
	bl RemoveWindow
	ldr r0, [sp]
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02207D64


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


	thumb_func_start ov96_02208250
ov96_02208250: ; 0x02208250
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r6, r0, #0
	mov r0, #0
	add r5, r1, #0
	str r0, [sp, #0xc]
	add r4, r6, #0
	add r7, sp, #0x10
_02208260:
	ldrb r0, [r5, #6]
	mov r3, #2
	str r0, [sp]
	ldrh r0, [r5, #2]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	str r0, [sp, #8]
	ldrh r1, [r5]
	ldrb r2, [r5, #7]
	add r0, sp, #0x10
	bl GetMonSpriteCharAndPlttNarcIdsEx
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	ldrh r0, [r7]
	ldrh r1, [r7, #2]
	ldr r2, [r6]
	ldr r3, [r5, #0xc]
	bl sub_0201457C
	mov r1, #0x42
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldrh r0, [r7]
	ldrh r1, [r7, #4]
	ldr r2, [r6]
	bl sub_02014450
	mov r1, #0x43
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [sp, #0xc]
	add r5, #0x10
	add r0, r0, #1
	add r4, #8
	str r0, [sp, #0xc]
	cmp r0, #3
	blt _02208260
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02208250


	thumb_func_start ov96_022082BC
ov96_022082BC: ; 0x022082BC
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	add r5, r0, #0
	add r4, r2, #0
	cmp r6, #2
	blo _022082CC
	bl GF_AssertFail
_022082CC:
	cmp r4, #3
	blo _022082D4
	bl GF_AssertFail
_022082D4:
	mov r0, #0x42
	lsl r0, r0, #2
	lsl r4, r4, #3
	add r7, r5, r0
	mov r1, #0x32
	ldr r0, [r7, r4]
	lsl r1, r1, #6
	bl DC_FlushRange
	lsl r6, r6, #2
	mov r1, #0x12
	add r2, r5, r6
	lsl r1, r1, #4
	ldr r1, [r2, r1]
	mov r2, #0x32
	ldr r0, [r7, r4]
	lsl r2, r2, #6
	bl GXS_LoadOBJ
	mov r0, #0x43
	lsl r0, r0, #2
	add r7, r5, r0
	ldr r0, [r7, r4]
	mov r1, #0x20
	bl DC_FlushRange
	mov r1, #0x4a
	add r2, r5, r6
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	ldr r0, [r7, r4]
	mov r2, #0x20
	bl GXS_LoadOBJPltt
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_022082BC


	thumb_func_start ov96_0220831C
ov96_0220831C: ; 0x0220831C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r4, r1, #0
	mov r0, #0x1c
	mul r0, r4
	add r0, r5, r0
	ldr r0, [r0, #0x38]
	add r6, r2, #0
	bl ov96_021EB5B8
	str r0, [sp]
	lsl r0, r4, #1
	add r0, r4, r0
	add r6, r6, r0
	add r7, r5, #0
	lsl r0, r6, #2
	mov r1, #2
	add r7, #0xcc
	str r0, [sp, #4]
	ldr r0, [r7, r0]
	lsl r1, r1, #8
	ldr r0, [r0, #0x14]
	bl DC_FlushRange
	ldr r0, [sp, #4]
	mov r1, #6
	ldr r0, [r7, r0]
	lsl r2, r4, #9
	lsl r1, r1, #0xa
	add r1, r2, r1
	mov r2, #2
	ldr r0, [r0, #0x14]
	lsl r2, r2, #8
	bl GXS_LoadOBJ
	add r1, r5, r6
	add r1, #0xfc
	ldrb r1, [r1]
	ldr r0, [sp]
	bl Sprite_SetPaletteOverride
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220831C


	thumb_func_start ov96_02208374
ov96_02208374: ; 0x02208374
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r6, r1, #0
	add r5, r0, #0
	add r0, r6, #0
	mov r1, #0x64
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #3]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0]
	mov r0, #0x64
	mul r0, r4
	sub r0, r6, r0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #4]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0, #1]
	add r0, r6, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #5]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0, #2]
	mov r4, #0
	mov r6, #4
	mov r7, #8
_022083FE:
	str r6, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x28]
	lsl r2, r4, #2
	add r0, #0xc
	str r0, [sp, #8]
	add r0, sp, #0x1c
	add r0, #3
	ldrb r0, [r0, r4]
	add r2, #0xe
	lsl r2, r2, #0x18
	str r0, [sp, #0xc]
	add r0, sp, #0x1c
	ldrb r0, [r0, r4]
	mov r1, #5
	lsr r2, r2, #0x18
	str r0, [sp, #0x10]
	mov r0, #0x14
	str r0, [sp, #0x14]
	mov r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [r5, #8]
	mov r3, #3
	bl CopyRectToBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _022083FE
	ldr r0, [r5, #8]
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02208374


	thumb_func_start ov96_02208448
ov96_02208448: ; 0x02208448
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	mov r5, #0x67
	add r4, r0, #0
	lsl r5, r5, #2
	add r6, r1, #0
	ldr r1, [r4, r5]
	cmp r1, #3
	bhi _022084B4
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02208466: ; jump table
	.short _0220846E - _02208466 - 2 ; case 0
	.short _022084D6 - _02208466 - 2 ; case 1
	.short _02208500 - _02208466 - 2 ; case 2
	.short _02208576 - _02208466 - 2 ; case 3
_0220846E:
	add r0, r5, #4
	ldrh r0, [r4, r0]
	lsl r0, r0, #2
	add r1, r4, r0
	add r0, r5, #0
	sub r0, #0x6c
	ldr r0, [r1, r0]
	bl ov96_021EB594
	add r6, r0, #0
	add r3, sp, #0x18
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	mov r0, #2
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [sp, #0x1c]
	add r0, r5, #4
	ldrh r1, [r4, r0]
	sub r0, #0x70
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r2, #0
	bl ov96_021EB588
	mov r0, #0xe7
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #0xe
	cmp r1, r0
	bge _022084B6
_022084B4:
	b _02208600
_022084B6:
	mov r0, #0xa5
	lsl r0, r0, #0xe
	str r0, [sp, #0x1c]
	add r0, r5, #4
	ldrh r1, [r4, r0]
	sub r0, #0x70
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, sp, #0x18
	bl ov96_021EB588
	ldr r0, [r4, r5]
	add r0, r0, #1
	str r0, [r4, r5]
	b _02208600
_022084D6:
	add r1, r5, #4
	ldrh r1, [r4, r1]
	add r2, r6, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_022082BC
	add r3, r5, #4
	ldrh r0, [r4, r3]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	strh r0, [r4, r3]
	ldr r0, [r4, r5]
	add r0, r0, #1
	str r0, [r4, r5]
	b _02208600
_02208500:
	add r0, r5, #4
	ldrh r0, [r4, r0]
	lsl r0, r0, #2
	add r1, r4, r0
	add r0, r5, #0
	sub r0, #0x6c
	ldr r0, [r1, r0]
	bl ov96_021EB594
	add r6, r0, #0
	add r3, sp, #0xc
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	mov r0, #2
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [sp, #0x10]
	add r0, r5, #4
	ldrh r1, [r4, r0]
	sub r0, #0x70
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r2, #0
	bl ov96_021EB588
	mov r0, #0xd1
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0xe
	cmp r1, r0
	blt _02208600
	str r0, [sp, #0x10]
	add r0, r5, #4
	ldrh r1, [r4, r0]
	sub r0, #0x70
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, sp, #0xc
	bl ov96_021EB588
	add r3, r5, #4
	ldrh r0, [r4, r3]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	strh r0, [r4, r3]
	ldr r0, [r4, r5]
	add r0, r0, #1
	str r0, [r4, r5]
	b _02208600
_02208576:
	add r0, r5, #4
	ldrh r0, [r4, r0]
	lsl r0, r0, #2
	add r1, r4, r0
	add r0, r5, #0
	sub r0, #0x6c
	ldr r0, [r1, r0]
	bl ov96_021EB594
	add r3, r0, #0
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	add r7, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	mov r0, #2
	ldr r1, [sp, #4]
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [sp, #4]
	add r0, r5, #4
	ldrh r1, [r4, r0]
	sub r0, #0x70
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r7, #0
	bl ov96_021EB588
	mov r0, #0xbb
	ldr r1, [sp, #4]
	lsl r0, r0, #0xe
	cmp r1, r0
	blt _02208600
	str r0, [sp, #4]
	add r0, r5, #4
	ldrh r1, [r4, r0]
	sub r0, #0x70
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r7, #0
	bl ov96_021EB588
	add r3, r5, #4
	ldrh r0, [r4, r3]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	strh r0, [r4, r3]
	add r0, r6, #2
	mov r1, #3
	bl _s32_div_f
	lsl r1, r1, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_022088AC
	mov r0, #0
	str r0, [r4, r5]
	add sp, #0x24
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02208600:
	mov r0, #0
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02208448


	thumb_func_start ov96_02208608
ov96_02208608: ; 0x02208608
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r5, r1, #0
	beq _02208614
	cmp r5, #4
	blo _02208618
_02208614:
	bl GF_AssertFail
_02208618:
	mov r1, #0x6f
	sub r0, r5, #1
	lsl r1, r1, #2
	lsl r0, r0, #2
	add r3, r4, r1
	ldrh r2, [r3, r0]
	add r2, #0x20
	strh r2, [r3, r0]
	ldrh r2, [r3, r0]
	cmp r2, #0x58
	blo _0220863C
	mov r2, #0
	add r1, r1, #2
	strh r2, [r3, r0]
	add r2, r4, r1
	ldrh r1, [r2, r0]
	add r1, r1, #1
	strh r1, [r2, r0]
_0220863C:
	ldr r1, _02208654 ; =0x000001BE
	add r2, r4, r1
	ldrh r1, [r2, r0]
	cmp r1, #3
	blo _0220864E
	mov r1, #0
	strh r1, [r2, r0]
	mov r0, #1
	pop {r3, r4, r5, pc}
_0220864E:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02208654: .word 0x000001BE
	thumb_func_end ov96_02208608


	thumb_func_start ov96_02208658
ov96_02208658: ; 0x02208658
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r7, r3, #0
	mov r3, #0x69
	add r5, r0, #0
	lsl r3, r3, #2
	add r4, r1, #0
	add r6, r5, r3
	ldrb r3, [r6, r4]
	cmp r2, r3
	beq _02208674
	strb r2, [r6, r4]
	bl ov96_0220831C
_02208674:
	cmp r7, #0
	beq _022086B6
	mov r0, #0
	str r0, [sp, #0x18]
	mov r0, #0x28
	mul r0, r4
	add r0, #0x70
	lsl r0, r0, #0xc
	str r0, [sp, #0x10]
	ldr r0, _0220873C ; =0x00350004
	add r6, r4, #0
	str r0, [sp, #0x14]
	mov r0, #0x1c
	mul r6, r0
	add r0, r5, r6
	ldr r0, [r0, #0x38]
	add r1, sp, #0x10
	bl ov96_021EB588
	add r0, r5, r6
	ldr r0, [r0, #0x40]
	add r1, sp, #0x10
	bl ov96_021EB588
	mov r0, #0x4f
	lsl r0, r0, #2
	add r1, r5, r0
	lsl r0, r4, #4
	add r0, r1, r0
	mov r1, #0
	bl ov96_02208A80
	b _02208730
_022086B6:
	mov r0, #0
	str r0, [sp, #0xc]
	mov r0, #0x28
	mul r0, r4
	add r0, #0x70
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	mov r0, #0x35
	lsl r0, r0, #0x10
	str r0, [sp, #8]
	mov r0, #0x1c
	add r6, r4, #0
	mul r6, r0
	add r0, r5, r6
	ldr r0, [r0, #0x38]
	add r1, sp, #4
	bl ov96_021EB588
	add r0, r5, r6
	ldr r0, [r0, #0x40]
	add r1, sp, #4
	bl ov96_021EB588
	mov r0, #0x4f
	lsl r0, r0, #2
	add r1, r5, r0
	lsl r0, r4, #4
	add r0, r1, r0
	mov r1, #1
	bl ov96_02208A80
	ldr r1, [sp, #0x30]
	cmp r1, #1
	bne _02208724
	add r0, r5, r6
	add r0, #0x44
	ldrb r0, [r0]
	cmp r1, r0
	beq _02208730
	add r7, r5, #0
	mov r0, #0x1c
	mul r0, r4
	mov r1, #1
	add r7, #0x3c
	str r0, [sp]
	ldr r0, [r7, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [sp]
	mov r1, #1
	ldr r0, [r7, r0]
	bl ov96_021EB564
	b _02208730
_02208724:
	add r0, r5, r6
	ldr r0, [r0, #0x3c]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_02208730:
	add r0, r5, r6
	ldr r1, [sp, #0x30]
	add r0, #0x44
	strb r1, [r0]
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0220873C: .word 0x00350004
	thumb_func_end ov96_02208658


	thumb_func_start ov96_02208740
ov96_02208740: ; 0x02208740
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, r1, #0
	mov r1, #0x1e
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r1, r0, #0
	mov r0, #0x6d
	lsl r0, r0, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	mov r0, #0x6e
	lsl r0, r0, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02208740


	thumb_func_start ov96_02208784
ov96_02208784: ; 0x02208784
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r7, r1, #0
	mov r6, #0
	add r4, r5, #0
_02208790:
	mov r0, #0x6d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	bl Sprite_SetDrawPriority
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #2
	blt _02208790
	mov r6, #0
	add r4, r5, #0
_022087A8:
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_021EB5B8
	mov r1, #2
	bl Sprite_SetDrawPriority
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #2
	blt _022087A8
	mov r0, #1
	mov r2, #0
	add r1, sp, #4
_022087C6:
	cmp r2, r7
	bne _022087CC
	strb r2, [r1]
_022087CC:
	add r2, r2, #1
	cmp r2, #4
	blt _022087C6
	mov r2, #0
	add r4, sp, #4
	add r3, sp, #4
_022087D8:
	ldrb r1, [r3]
	cmp r1, r2
	beq _022087E8
	add r1, r0, #0
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	strb r2, [r4, r1]
_022087E8:
	add r2, r2, #1
	cmp r2, #4
	blt _022087D8
	mov r0, #3
	mov r6, #0
	str r0, [sp]
	add r4, sp, #4
	mov r7, #4
_022087F8:
	ldrb r1, [r4]
	mov r0, #0x1c
	mul r0, r1
	add r0, r5, r0
	ldr r0, [r0, #0x3c]
	ldr r1, [sp]
	bl ov96_021EB630
	ldrb r1, [r4]
	mov r0, #0x1c
	mul r0, r1
	add r0, r5, r0
	ldr r0, [r0, #0x38]
	add r1, r7, #0
	bl ov96_021EB630
	ldrb r1, [r4]
	mov r0, #0x1c
	mul r0, r1
	add r0, r5, r0
	add r1, r6, #0
	ldr r0, [r0, #0x40]
	add r1, #0xb
	bl ov96_021EB630
	ldr r0, [sp]
	add r6, r6, #1
	add r0, r0, #2
	str r0, [sp]
	add r4, r4, #1
	add r7, r7, #2
	cmp r6, #4
	blt _022087F8
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02208784


	thumb_func_start ov96_02208840
ov96_02208840: ; 0x02208840
	push {r4, r5, r6, lr}
	add r6, r2, #0
	add r5, r0, #0
	add r4, r1, #0
	cmp r6, #9
	bls _02208850
	bl GF_AssertFail
_02208850:
	lsl r0, r4, #4
	add r1, r5, r0
	mov r0, #5
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	add r6, #9
	add r1, r6, #0
	bl ov96_021EB564
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_02208840


	thumb_func_start ov96_02208864
ov96_02208864: ; 0x02208864
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0x5f
	lsl r0, r0, #2
	add r2, r5, r0
	add r0, #0x26
	ldrh r0, [r5, r0]
	lsl r1, r1, #3
	add r4, r2, r1
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	bl ov96_021EB564
	ldr r0, _022088A8 ; =0x000001A2
	mov r1, #1
	ldrh r0, [r5, r0]
	add r2, r1, #0
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB52C
	ldr r3, _022088A8 ; =0x000001A2
	ldrh r0, [r5, r3]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	strh r0, [r5, r3]
	pop {r3, r4, r5, pc}
	nop
_022088A8: .word 0x000001A2
	thumb_func_end ov96_02208864


	thumb_func_start ov96_022088AC
ov96_022088AC: ; 0x022088AC
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r5, r1, #0
	add r0, #0xc
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #1
	lsl r2, r5, #2
	add r5, r4, r2
	mov r2, #0x6a
	str r0, [sp]
	mov r3, #2
	str r3, [sp, #4]
	lsl r2, r2, #2
	ldr r0, [r4, #0x20]
	ldr r2, [r5, r2]
	mov r1, #0
	bl BufferString
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x1c]
	ldr r3, [r4]
	mov r2, #0x9a
	bl ReadMsgData_ExpandPlaceholders
	mov r1, #0
	add r5, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02208910 ; =0x000F0E00
	add r2, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #0xc
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl String_Delete
	add r4, #0xc
	add r0, r4, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02208910: .word 0x000F0E00
	thumb_func_end ov96_022088AC


	thumb_func_start ov96_02208914
ov96_02208914: ; 0x02208914
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #4]
	ldr r0, _022089CC ; =ov96_0221CBCC
	str r1, [sp, #8]
	ldr r2, [r0]
	ldr r1, [r0, #4]
	str r2, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, [r0, #0x10]
	ldr r0, [r0, #0x14]
	add r5, sp, #0x14
	add r4, sp, #0xc
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r6, #0
	mov r7, #3
_02208936:
	ldr r0, [r4]
	add r1, r7, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r3, [r5]
	ldr r0, [sp, #4]
	lsl r3, r3, #0x18
	mov r2, #2
	lsr r3, r3, #0x18
	bl ov96_021EB408
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r6, #2
	blt _02208936
	ldr r4, [sp, #8]
	mov r5, #0
	add r7, sp, #0xc
	add r6, sp, #0x14
_02208960:
	ldr r1, [r6]
	ldr r2, [r7]
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021EB4F4
	mov r1, #0x13
	lsl r1, r1, #4
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	bl ov96_021EB5B8
	mov r1, #0
	str r1, [sp, #0x24]
	mov r1, #0xa
	lsl r1, r1, #0xe
	str r1, [sp, #0x1c]
	mov r1, #1
	sub r2, r1, r5
	mov r1, #0x58
	mul r1, r2
	add r1, #0x30
	lsl r2, r1, #0xc
	mov r1, #0xaf
	lsl r1, r1, #0xe
	add r1, r2, r1
	str r1, [sp, #0x20]
	add r1, sp, #0x1c
	bl Sprite_SetMatrix
	mov r0, #0x13
	lsl r0, r0, #4
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	add r5, r5, #1
	add r7, r7, #4
	add r6, r6, #4
	add r4, r4, #4
	cmp r5, #2
	blt _02208960
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	bl ov96_022089D0
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022089CC: .word ov96_0221CBCC
	thumb_func_end ov96_02208914


	thumb_func_start ov96_022089D0
ov96_022089D0: ; 0x022089D0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r7, r0, #0
	ldr r0, _02208A48 ; =ov96_0221CBCC
	str r1, [sp]
	ldr r1, [r0, #0x18]
	ldr r0, [r0, #0x1c]
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r4, #0
_022089E4:
	lsl r0, r4, #2
	add r1, sp, #0xc
	ldr r5, [r1, r0]
	str r0, [sp, #4]
	add r0, r7, #0
	add r1, r5, #0
	mov r2, #0
	bl ov96_021EB5EC
	ldr r6, [r0]
	add r0, r7, #0
	add r1, r5, #0
	mov r2, #1
	bl ov96_021EB5EC
	ldr r5, [r0]
	add r0, r6, #0
	bl SpriteTransfer_GetCharProxy
	add r6, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	bl SpriteTransfer_GetPaletteProxy
	str r0, [sp, #8]
	ldr r1, [sp]
	ldr r0, [sp, #4]
	add r5, r1, r0
	add r0, r6, #0
	mov r1, #2
	bl NNS_G2dGetImageLocation
	mov r1, #0x12
	lsl r1, r1, #4
	str r0, [r5, r1]
	ldr r0, [sp, #8]
	mov r1, #2
	bl NNS_G2dGetImagePaletteLocation
	mov r1, #0x4a
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _022089E4
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_02208A48: .word ov96_0221CBCC
	thumb_func_end ov96_022089D0


	thumb_func_start ov96_02208A4C
ov96_02208A4C: ; 0x02208A4C
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r1, r4, #0
	ldr r0, [r4, #8]
	ldr r2, _02208A7C ; =ov96_0221CBEC
	add r1, #0xc
	bl AddWindow
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #8]
	mov r1, #4
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r4]
	mov r0, #4
	lsl r1, r1, #4
	bl LoadFontPal0
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02208A7C: .word ov96_0221CBEC
	thumb_func_end ov96_02208A4C


	thumb_func_start ov96_02208A80
ov96_02208A80: ; 0x02208A80
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r0, [r5]
	mov r1, #1
	add r2, r4, #0
	bl ov96_021EB52C
	ldr r0, [r5, #8]
	mov r1, #1
	add r2, r4, #0
	bl ov96_021EB52C
	ldr r0, [r5, #4]
	mov r1, #1
	add r2, r4, #0
	bl ov96_021EB52C
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02208A80


	thumb_func_start ov96_02208AA8
ov96_02208AA8: ; 0x02208AA8
	push {r3, r4, r5, lr}
	add r5, r1, #0
	ldr r1, _02208AE0 ; =0x0000055C
	bl Heap_Alloc
	ldr r2, _02208AE0 ; =0x0000055C
	mov r1, #0
	add r4, r0, #0
	bl MI_CpuFill8
	ldr r0, _02208AE4 ; =0x00000554
	mov r1, #4
	sub r2, r1, r5
	strb r5, [r4, r0]
	add r1, r0, #5
	strb r2, [r4, r1]
	ldrb r2, [r4, r1]
	add r1, r0, #4
	strb r2, [r4, r1]
	add r1, r0, #3
	mov r2, #6
	strb r2, [r4, r1]
	ldrb r1, [r4, r1]
	add r0, r0, #2
	strb r1, [r4, r0]
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	nop
_02208AE0: .word 0x0000055C
_02208AE4: .word 0x00000554
	thumb_func_end ov96_02208AA8

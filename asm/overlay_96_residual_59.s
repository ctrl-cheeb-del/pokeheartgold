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

	thumb_func_start ov96_021F54D4
ov96_021F54D4: ; 0x021F54D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r0, r5, #0
	bl PokeathlonCourse_GetGraphicsSystem
	add r6, r0, #0
	bl ov96_021E9510
	mov r4, #0
	add r7, r4, #0
_021F54EE:
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl PokeathlonCourse_GetField5F0_AtIndex
	add r3, r0, #0
	str r7, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x4a
	lsl r0, r0, #2
	str r0, [sp, #8]
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	bl ov96_021E95F8
	add r4, r4, #1
	cmp r4, #4
	blt _021F54EE
	add r0, r6, #0
	mov r1, #1
	bl ov96_021E93B4
	add r0, r6, #0
	mov r1, #5
	bl ov96_0221A56C
	add r0, r6, #0
	bl ov96_021E952C
	add r0, r6, #0
	mov r1, #5
	bl ov96_021E9570
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F54D4


	thumb_func_start ov96_021F553C
ov96_021F553C: ; 0x021F553C
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	bl sub_0203A914
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl Camera_Delete
	add r0, r4, #0
	add r0, #0x8c
	ldr r0, [r0]
	bl ov96_021F74C8
	ldr r0, [r4, #0x58]
	bl Heap_Free
	ldr r0, [r4]
	mov r1, #2
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #3
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #4
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #6
	bl FreeBgTilemapBuffer
	mov r6, #0
	add r5, r4, #4
_021F5598:
	add r0, r5, #0
	bl RemoveWindow
	add r6, r6, #1
	add r5, #0x10
	cmp r6, #5
	blt _021F5598
	ldr r0, [r4]
	bl Heap_Free
	add r0, r7, #0
	bl PokeathlonCourse_ResetField3A4
	ldr r0, [r4, #0x60]
	bl ov96_021EB21C
	mov r0, #0x63
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EA894
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021E9C0C
	mov r0, #0x4e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021F7738
	mov r0, #4
	bl FontID_Release
	bl OamManager_Free
	bl ObjCharTransfer_Destroy
	bl ObjPlttTransfer_Destroy
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	ldr r0, _021F5628 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #1
	lsl r0, r0, #0xc
	ldr r0, [r4, r0]
	bl sub_0202067C
	bl GF_DestroyVramTransferManager
	add r0, r7, #0
	bl PokeathlonCourse_FreePtr4HeapAlloc
	ldr r0, _021F562C ; =0x04000050
	mov r1, #0
	strh r1, [r0]
	mov r0, #0x8f
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F5628: .word gSystem + 0x60
_021F562C: .word 0x04000050
	thumb_func_end ov96_021F553C


	thumb_func_start ov96_021F5630
ov96_021F5630: ; 0x021F5630
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _021F564C ; =ov96_0221C1F4
	add r3, sp, #0
	mov r2, #5
_021F563A:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021F563A
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_021F564C: .word ov96_0221C1F4
	thumb_func_end ov96_021F5630


	thumb_func_start ov96_021F5650
ov96_021F5650: ; 0x021F5650
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r4, r1, #0
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	ldrb r0, [r4]
	cmp r0, #5
	bhi _021F5728
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021F5670: ; jump table
	.short _021F567C - _021F5670 - 2 ; case 0
	.short _021F5692 - _021F5670 - 2 ; case 1
	.short _021F56B8 - _021F5670 - 2 ; case 2
	.short _021F56CE - _021F5670 - 2 ; case 3
	.short _021F56E6 - _021F5670 - 2 ; case 4
	.short _021F56FE - _021F5670 - 2 ; case 5
_021F567C:
	add r0, r5, #0
	bl ov96_021F5B60
	add r0, r5, #0
	mov r1, #0x14
	bl PokeathlonCourse_SetStateTransitionType
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _021F5728
_021F5692:
	add r0, r5, #0
	bl ov96_021F5B60
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x54]
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _021F5728
_021F56B8:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021F56C6
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
_021F56C6:
	add r0, r5, #0
	bl ov96_021F5B60
	b _021F5728
_021F56CE:
	add r0, r5, #0
	bl ov96_021F5B60
	add r0, r5, #0
	bl ov96_021E637C
	cmp r0, #0
	beq _021F5728
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _021F5728
_021F56E6:
	add r0, r5, #0
	bl ov96_021F5BA0
	add r0, r5, #0
	bl ov96_021F5A88
	cmp r0, #0
	beq _021F5728
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _021F5728
_021F56FE:
	add r0, r5, #0
	bl ov96_021E667C
	cmp r0, #0
	beq _021F5728
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x54]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	add r0, r5, #0
	mov r1, #1
	bl PokeathlonCourse_SetStateField07
_021F5728:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021F5650


	thumb_func_start ov96_021F5730
ov96_021F5730: ; 0x021F5730
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r1, #0
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldrb r0, [r6]
	cmp r0, #0
	bne _021F5756
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021F5750
	mov r0, #1
	strb r0, [r6]
_021F5750:
	add sp, #0xc
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_021F5756:
	add r0, r5, #0
	bl ov96_021E5F24
	mov r2, #0
	add r6, r0, #0
	add r1, r2, #0
_021F5762:
	add r0, r4, #0
	add r0, #0xb0
	ldrh r0, [r0]
	add r1, r1, #1
	add r4, #0x38
	add r2, r2, r0
	cmp r1, #3
	blt _021F5762
	ldr r0, _021F5848 ; =0x000003E7
	cmp r2, r0
	ble _021F577A
	add r2, r0, #0
_021F577A:
	lsl r1, r6, #0x18
	lsl r2, r2, #0x10
	add r0, r5, #0
	lsr r1, r1, #0x18
	lsr r2, r2, #0x10
	bl PokeathlonCourse_SetField5E0_AtIndex
	cmp r6, #0
	bne _021F5842
	add r0, r5, #0
	bl PokeathlonCourse_GetParticipantCount
	str r0, [sp, #8]
	cmp r0, #4
	bge _021F5842
_021F5798:
	ldr r0, [sp, #8]
	mov r4, #0
	lsl r0, r0, #0x18
	str r4, [sp, #4]
	lsr r7, r0, #0x18
_021F57A2:
	ldr r1, [sp, #8]
	add r0, r5, #0
	add r2, r4, #0
	bl ov96_021E60D8
	add r6, r0, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _021F57E0
	bl LCRandom
	mov r1, #0x15
	bl _s32_div_f
	add r3, r1, #0
	ldrb r0, [r6, #3]
	ldrb r2, [r6, #2]
	mov r1, #6
	lsl r0, r0, #1
	mul r1, r2
	ldrb r2, [r6, #4]
	add r1, #0x50
	lsl r2, r2, #1
	add r1, r1, r2
	add r0, r0, r1
	add r1, r0, r3
	ldr r0, [sp, #4]
	add r0, r0, r1
	str r0, [sp, #4]
	bl LCRandom
_021F57E0:
	mov r0, #0
	lsl r2, r4, #0x18
	str r0, [sp]
	add r0, r5, #0
	add r1, r7, #0
	lsr r2, r2, #0x18
	mov r3, #2
	bl ov96_021E8228
	bl LCRandom
	mov r1, #0x15
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	lsl r2, r4, #0x18
	add r0, r5, #0
	add r1, r7, #0
	lsr r2, r2, #0x18
	mov r3, #4
	str r6, [sp]
	bl ov96_021E8228
	lsl r2, r4, #0x18
	add r0, r5, #0
	add r1, r7, #0
	lsr r2, r2, #0x18
	mov r3, #1
	str r6, [sp]
	bl ov96_021E8228
	add r4, r4, #1
	cmp r4, #3
	blt _021F57A2
	ldr r1, [sp, #8]
	ldr r2, [sp, #4]
	lsl r1, r1, #0x18
	lsl r2, r2, #0x10
	add r0, r5, #0
	lsr r1, r1, #0x18
	lsr r2, r2, #0x10
	bl PokeathlonCourse_SetField5E0_AtIndex
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #4
	blt _021F5798
_021F5842:
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021F5848: .word 0x000003E7
	thumb_func_end ov96_021F5730


	thumb_func_start ov96_021F584C
ov96_021F584C: ; 0x021F584C
	push {r3, r4, r5, lr}
	sub sp, #0xb8
	ldr r5, _021F5964 ; =ov96_0221C100
	add r3, sp, #0xa8
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _021F5968 ; =ov96_0221C124
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
	ldr r5, _021F596C ; =ov96_0221C140
	add r3, sp, #0x70
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
	ldr r5, _021F5970 ; =ov96_0221C15C
	add r3, sp, #0x54
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
	ldr r5, _021F5974 ; =ov96_0221C178
	add r3, sp, #0x38
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
	ldr r5, _021F5978 ; =ov96_0221C194
	add r3, sp, #0x1c
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
	ldr r5, _021F597C ; =ov96_0221C1B0
	add r3, sp, #0
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
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add sp, #0xb8
	pop {r3, r4, r5, pc}
	nop
_021F5964: .word ov96_0221C100
_021F5968: .word ov96_0221C124
_021F596C: .word ov96_0221C140
_021F5970: .word ov96_0221C15C
_021F5974: .word ov96_0221C178
_021F5978: .word ov96_0221C194
_021F597C: .word ov96_0221C1B0
	thumb_func_end ov96_021F584C


	thumb_func_start ov96_021F5980
ov96_021F5980: ; 0x021F5980
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	mov r1, #7
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xa8
	mov r3, #2
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	mov r1, #5
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xa8
	mov r3, #1
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	mov r1, #0xa
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xa8
	mov r3, #4
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	mov r1, #0xc
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xa8
	mov r3, #5
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	mov r1, #8
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xa8
	mov r3, #2
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	mov r1, #6
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xa8
	mov r3, #1
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	mov r1, #0xb
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xa8
	mov r3, #4
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x54]
	mov r1, #0xd
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xa8
	mov r3, #5
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r4, #0x54]
	mov r2, #0
	str r0, [sp, #4]
	mov r0, #0xa8
	mov r1, #4
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPal
	mov r0, #0x40
	str r0, [sp]
	ldr r0, [r4, #0x54]
	mov r1, #9
	str r0, [sp, #4]
	mov r0, #0xa8
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPal
	ldr r0, [r4, #0x54]
	add r3, r4, #0
	str r0, [sp]
	mov r0, #0xa8
	mov r1, #0xe
	mov r2, #0
	add r3, #0x5c
	bl GfGfxLoader_GetScrnData
	str r0, [r4, #0x58]
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F5980


	thumb_func_start ov96_021F5A88
ov96_021F5A88: ; 0x021F5A88
	push {r4, r5, r6, lr}
	add r6, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetDataCopyArea
	bl ov96_021E8A20
	add r5, r0, #0
	ldr r1, _021F5B58 ; =0x00000142
	mov r0, #0
	strb r0, [r4, r1]
	sub r0, r1, #6
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021F5AB6
	sub r0, r1, #6
	ldr r0, [r4, r0]
	sub r2, r0, #1
	sub r0, r1, #6
	str r2, [r4, r0]
_021F5AB6:
	mov r0, #0x4f
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	bgt _021F5AC4
	mov r0, #1
	b _021F5AC6
_021F5AC4:
	mov r0, #0
_021F5AC6:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _021F5B1C
	ldr r0, [r4, #0x60]
	mov r1, #1
	mov r5, #0
	bl ov96_021EB63C
	mov r0, #0x63
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov96_021EB144
	add r1, r5, #0
	add r2, r4, #0
_021F5AE6:
	add r0, r2, #0
	add r0, #0xb0
	ldrh r0, [r0]
	add r1, r1, #1
	add r2, #0x38
	add r5, r5, r0
	cmp r1, #3
	blt _021F5AE6
	ldr r0, _021F5B5C ; =0x000003E7
	cmp r5, r0
	ble _021F5AFE
	add r5, r0, #0
_021F5AFE:
	lsl r1, r5, #0x10
	add r0, r6, #0
	lsr r1, r1, #0x10
	bl ov96_021E8318
	lsl r1, r5, #0x10
	add r0, r4, #0
	lsr r1, r1, #0x10
	bl ov96_021F70AC
	add r0, r6, #0
	bl ov96_021F5B60
	mov r0, #1
	pop {r4, r5, r6, pc}
_021F5B1C:
	add r0, r6, #0
	add r1, r4, #0
	bl ov96_021F6600
	mov r0, #0x1a
	lsl r0, r0, #4
	add r0, r4, r0
	bl ov96_021F6424
	add r0, r4, #0
	bl ov96_021F6BB0
	add r0, r6, #0
	add r1, r4, #0
	bl ov96_021F7194
	add r0, r4, #0
	add r0, #0x8c
	ldr r0, [r0]
	bl ov96_021F7598
	add r0, r6, #0
	bl ov96_021F5B60
	ldr r0, _021F5B58 ; =0x00000142
	ldrb r0, [r4, r0]
	str r0, [r5]
	mov r0, #0
	pop {r4, r5, r6, pc}
	nop
_021F5B58: .word 0x00000142
_021F5B5C: .word 0x000003E7
	thumb_func_end ov96_021F5A88


	thumb_func_start ov96_021F5B60
ov96_021F5B60: ; 0x021F5B60
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	add r0, r5, #0
	bl ov96_021F5D3C
	mov r1, #0x4f
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	bl ov96_021F6F3C
	add r0, r4, #0
	bl ov96_021F6E38
	add r0, r5, #0
	bl ov96_021F5EC4
	mov r1, #0x4f
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r5, #0
	bl ov96_021E6454
	add r0, r4, #0
	bl ov96_021F637C
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021F5B60


	thumb_func_start ov96_021F5BA0
ov96_021F5BA0: ; 0x021F5BA0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #8]
	bl PokeathlonCourse_GetDataCopyArea
	add r4, r0, #0
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r5, r0, #0
	bl System_GetTouchNew
	cmp r0, #0
	beq _021F5C10
	ldr r0, [sp, #8]
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl ov96_021E8228
	ldr r2, _021F5D38 ; =gSystem + 0x40
	add r0, r5, #0
	ldrh r1, [r2, #0x20]
	ldrh r2, [r2, #0x22]
	bl ov96_021F5F68
	cmp r0, #3
	bhs _021F5CC2
	mov r1, #5
	lsl r1, r1, #6
	ldr r2, _021F5D38 ; =gSystem + 0x40
	strb r0, [r5, r1]
	ldrh r0, [r2, #0x20]
	lsl r3, r0, #0xc
	add r0, r1, #0
	add r0, #0x2c
	str r3, [r5, r0]
	ldrh r0, [r2, #0x22]
	lsl r2, r0, #0xc
	mov r0, #3
	lsl r0, r0, #0x12
	add r2, r2, r0
	add r0, r1, #0
	add r0, #0x30
	str r2, [r5, r0]
	mov r0, #0
	add r1, #0x34
	str r0, [r5, r1]
	b _021F5CC2
_021F5C10:
	bl System_GetTouchHeld
	cmp r0, #0
	beq _021F5C74
	mov r2, #5
	lsl r2, r2, #6
	ldrb r0, [r5, r2]
	cmp r0, #3
	bhs _021F5CC2
	add r0, r2, #1
	ldrb r0, [r5, r0]
	cmp r0, #7
	bhs _021F5C36
	add r0, r2, #1
	ldrb r0, [r5, r0]
	add r1, r0, #1
	add r0, r2, #1
	strb r1, [r5, r0]
	b _021F5CC2
_021F5C36:
	add r3, sp, #0x1c
	mov r0, #0
	str r0, [r3]
	str r0, [r3, #4]
	ldr r1, _021F5D38 ; =gSystem + 0x40
	str r0, [r3, #8]
	ldrh r0, [r1, #0x20]
	ldrh r1, [r1, #0x22]
	add r2, #0x2c
	lsl r0, r0, #0x18
	lsl r1, r1, #0x18
	lsr r0, r0, #0x18
	lsr r1, r1, #0x18
	add r2, r5, r2
	bl ov96_021F5F34
	mov r1, #5
	lsl r1, r1, #6
	ldrb r1, [r5, r1]
	add r0, r5, #0
	add r2, sp, #0x1c
	bl ov96_021F6088
	mov r0, #5
	mov r1, #3
	lsl r0, r0, #6
	strb r1, [r5, r0]
	mov r1, #0
	add r0, r0, #1
	strb r1, [r5, r0]
	b _021F5CC2
_021F5C74:
	mov r2, #5
	lsl r2, r2, #6
	ldrb r0, [r5, r2]
	cmp r0, #3
	bhs _021F5CB4
	add r0, r2, #1
	ldrb r0, [r5, r0]
	cmp r0, #7
	bhs _021F5CB4
	add r3, sp, #0x10
	mov r0, #0
	str r0, [r3]
	str r0, [r3, #4]
	ldr r1, _021F5D38 ; =gSystem + 0x40
	str r0, [r3, #8]
	ldrh r0, [r1, #0x20]
	ldrh r1, [r1, #0x22]
	add r2, #0x2c
	lsl r0, r0, #0x18
	lsl r1, r1, #0x18
	lsr r0, r0, #0x18
	lsr r1, r1, #0x18
	add r2, r5, r2
	bl ov96_021F5F34
	mov r1, #5
	lsl r1, r1, #6
	ldrb r1, [r5, r1]
	add r0, r5, #0
	add r2, sp, #0x10
	bl ov96_021F6088
_021F5CB4:
	mov r0, #5
	mov r1, #3
	lsl r0, r0, #6
	strb r1, [r5, r0]
	mov r1, #0
	add r0, r0, #1
	strb r1, [r5, r0]
_021F5CC2:
	ldr r0, [sp, #8]
	bl ov96_021E5F24
	cmp r0, #0
	bne _021F5D32
	add r0, r4, #0
	add r0, #0x28
	bl ov96_021E8A20
	add r7, r0, #0
	add r0, r4, #0
	add r0, #0x50
	bl ov96_021E8A20
	str r0, [sp, #4]
	add r0, r4, #0
	bl ov96_021E8A20
	add r3, r0, #0
	mov r6, #4
_021F5CEA:
	ldr r2, [sp, #4]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	str r2, [sp, #4]
	sub r6, r6, #1
	bne _021F5CEA
	ldr r1, [r3]
	add r0, r2, #0
	str r1, [r0]
	mov r1, #0x4e
	lsl r1, r1, #2
	ldr r0, [sp, #8]
	ldr r1, [r5, r1]
	bl ov96_021F7740
	mov r6, #0
	add r4, #0x50
	add r5, sp, #0xc
_021F5D0E:
	add r0, r4, #0
	bl ov96_021E8A20
	ldr r0, [r0]
	add r6, r6, #1
	strb r0, [r5]
	add r4, #0x28
	add r5, r5, #1
	cmp r6, #4
	blt _021F5D0E
	mov r2, #0
	add r1, sp, #0xc
_021F5D26:
	ldrb r0, [r1]
	add r1, r1, #1
	strb r0, [r7, r2]
	add r2, r2, #1
	cmp r2, #4
	blt _021F5D26
_021F5D32:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F5D38: .word gSystem + 0x40
	thumb_func_end ov96_021F5BA0


	thumb_func_start ov96_021F5D3C
ov96_021F5D3C: ; 0x021F5D3C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #4]
	ldr r4, [sp, #4]
	ldr r6, [sp, #4]
	mov r0, #0
	ldr r5, _021F5EBC ; =ov96_0221DC18
	str r0, [sp, #0x10]
	add r4, #0x90
	add r7, r6, #0
_021F5D56:
	ldr r0, _021F5EC0 ; =0x00000FB4
	ldr r0, [r6, r0]
	lsl r1, r0, #6
	mov r0, #0x12
	lsl r0, r0, #0x10
	sub r0, r0, r1
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x1c]
	mov r0, #2
	lsl r0, r0, #0x10
	str r1, [r4, #8]
	cmp r1, r0
	bge _021F5D74
	str r0, [r4, #8]
	b _021F5D7E
_021F5D74:
	mov r0, #0xdf
	lsl r0, r0, #0xc
	cmp r1, r0
	ble _021F5D7E
	str r0, [r4, #8]
_021F5D7E:
	ldr r1, [r4, #8]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r0, #0xc
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0x17
	lsr r1, r0, #0x18
	mov r0, #0xfa
	lsl r0, r0, #4
	str r1, [r7, r0]
	ldr r1, [r4, #8]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [r4, #0xc]
	str r0, [sp, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #8]
	ldr r0, [r4]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #8]
	bl ov96_021EAF94
	mov r1, #0
	add r0, sp, #0x14
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [sp, #0xc]
	lsl r0, r0, #0xc
	str r0, [sp, #0x14]
	ldr r0, [sp, #8]
	lsl r0, r0, #0xc
	str r0, [sp, #0x18]
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	ldr r2, [sp, #0x10]
	bl ov96_021E60C0
	ldrb r0, [r0, #5]
	cmp r0, #0
	beq _021F5DF0
	mov r0, #6
	ldr r1, [sp, #0x18]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #0x18]
	b _021F5DFA
_021F5DF0:
	mov r0, #1
	ldr r1, [sp, #0x18]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x18]
_021F5DFA:
	ldr r0, [r4, #4]
	add r1, sp, #0x14
	bl ov96_021EB588
	add r0, r4, #0
	add r0, #0x26
	ldrb r0, [r0]
	cmp r0, #0
	ldr r0, [r4, #4]
	beq _021F5E34
	mov r1, #1
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r4]
	mov r1, #0x14
	bl ov96_021EAD08
	ldrb r0, [r5]
	bl sub_02006190
	cmp r0, #0
	bne _021F5E5E
	ldrb r1, [r5]
	mov r0, #0x89
	lsl r0, r0, #4
	bl sub_0200606C
	b _021F5E5E
_021F5E34:
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, [r4]
	mov r1, #0
	bl ov96_021EAD08
	mov r0, #0x3f
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	cmp r0, #0
	ldr r0, [r4]
	beq _021F5E58
	mov r1, #1
	bl ov96_021EAC0C
	b _021F5E5E
_021F5E58:
	mov r1, #2
	bl ov96_021EAC0C
_021F5E5E:
	ldr r0, [sp, #0x10]
	add r4, #0x38
	add r0, r0, #1
	add r6, #0x1c
	add r7, r7, #4
	add r5, r5, #1
	str r0, [sp, #0x10]
	cmp r0, #3
	bge _021F5E72
	b _021F5D56
_021F5E72:
	ldr r4, [sp, #4]
	mov r1, #0x51
	mov r5, #0
	lsl r1, r1, #2
	add r0, r4, #0
	add r6, r0, r1
	add r7, r5, #0
_021F5E80:
	ldr r0, [sp, #4]
	mov r1, #0x5a
	add r0, r0, r5
	lsl r1, r1, #2
	ldrb r1, [r0, r1]
	cmp r1, #0
	beq _021F5EAE
	mov r1, #0x5a
	lsl r1, r1, #2
	strb r7, [r0, r1]
	mov r1, #1
	ldr r0, [r4, #0x78]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r4, #0x78]
	add r1, r6, #0
	bl ov96_021EB588
	ldr r0, [r4, #0x78]
	mov r1, #9
	bl ov96_021EB564
_021F5EAE:
	add r5, r5, #1
	add r4, r4, #4
	add r6, #0xc
	cmp r5, #3
	blt _021F5E80
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F5EBC: .word ov96_0221DC18
_021F5EC0: .word 0x00000FB4
	thumb_func_end ov96_021F5D3C


	thumb_func_start ov96_021F5EC4
ov96_021F5EC4: ; 0x021F5EC4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	add r7, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp]
	mov r4, #0
	add r5, r0, #0
_021F5EE0:
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r4, r0
	bne _021F5F0A
	ldr r1, [sp]
	ldr r0, _021F5F30 ; =0x00000142
	ldrb r0, [r1, r0]
	cmp r0, #0
	beq _021F5F24
	ldr r0, [r5, #0x68]
	bl ov96_021EB57C
	cmp r0, #0
	bne _021F5F24
	add r1, r4, #0
	ldr r0, [r5, #0x68]
	add r1, #0xd
	bl ov96_021EB564
	b _021F5F24
_021F5F0A:
	ldrb r0, [r7, r4]
	cmp r0, #0
	beq _021F5F24
	ldr r0, [r5, #0x68]
	bl ov96_021EB57C
	cmp r0, #0
	bne _021F5F24
	add r1, r4, #0
	ldr r0, [r5, #0x68]
	add r1, #0xd
	bl ov96_021EB564
_021F5F24:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _021F5EE0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F5F30: .word 0x00000142
	thumb_func_end ov96_021F5EC4


	thumb_func_start ov96_021F5F34
ov96_021F5F34: ; 0x021F5F34
	push {r3, r4, lr}
	sub sp, #0xc
	lsl r0, r0, #0xc
	str r0, [sp]
	mov r0, #3
	lsl r1, r1, #0xc
	lsl r0, r0, #0x12
	add r0, r1, r0
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	add r4, r3, #0
	add r1, r2, #0
	add r0, sp, #0
	add r2, r4, #0
	bl VEC_Subtract
	mov r0, #7
	ldr r1, [r4, #4]
	lsl r0, r0, #0x10
	cmp r1, r0
	ble _021F5F62
	str r0, [r4, #4]
_021F5F62:
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F5F34


	thumb_func_start ov96_021F5F68
ov96_021F5F68: ; 0x021F5F68
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	str r1, [sp, #0xc]
	str r0, [sp, #8]
	str r2, [sp, #0x10]
	bl ov96_021E6104
	lsl r6, r0, #0xc
	ldr r0, [sp, #8]
	mov r5, #0
	str r0, [sp, #0x14]
	add r0, #0x90
	add r4, r5, #0
	add r7, sp, #0x24
	str r0, [sp, #0x14]
_021F5F86:
	mov r0, #0x38
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #0x14]
	add r1, r0, r1
	add r0, r1, #0
	add r0, #0x26
	ldrb r0, [r0]
	cmp r0, #0
	beq _021F5FA8
	mov r0, #0
	strb r0, [r7, r4]
	add r1, r0, #0
	lsl r2, r4, #2
	add r0, sp, #0x28
	str r1, [r0, r2]
	b _021F6014
_021F5FA8:
	add r0, sp, #0x18
	str r0, [sp]
	ldr r0, [r1]
	ldr r1, [r1, #0x1c]
	add r3, r4, #0
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	mov r2, #0x1c
	mul r3, r2
	ldr r2, [sp, #8]
	add r3, r2, r3
	ldr r2, _021F605C ; =0x00000FB4
	ldr r2, [r3, r2]
	lsl r3, r2, #6
	mov r2, #6
	lsl r2, r2, #0x10
	sub r2, r2, r3
	asr r3, r2, #0xb
	lsr r3, r3, #0x14
	add r3, r2, r3
	asr r2, r3, #0xc
	add r3, sp, #0x1c
	bl ov96_021EB0A4
	bl ov96_021E6104
	str r0, [sp]
	add r0, sp, #0x20
	str r0, [sp, #4]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	bl ov96_021E872C
	cmp r0, #0
	add r0, sp, #0x28
	beq _021F600A
	ldr r2, [sp, #0x20]
	lsl r1, r4, #2
	str r2, [r0, r1]
	mov r0, #1
	strb r0, [r7, r4]
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	b _021F6014
_021F600A:
	lsl r2, r4, #2
	mov r1, #0
	str r1, [r0, r2]
	add r0, r1, #0
	strb r0, [r7, r4]
_021F6014:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021F5F86
	cmp r5, #0
	bne _021F6028
	add sp, #0x34
	mov r0, #3
	pop {r4, r5, r6, r7, pc}
_021F6028:
	mov r0, #3
	mov r3, #0
	add r1, sp, #0x28
	add r2, sp, #0x24
_021F6030:
	ldrb r4, [r2, r3]
	cmp r4, #0
	beq _021F6042
	lsl r4, r3, #2
	ldr r4, [r1, r4]
	cmp r4, r6
	bge _021F6042
	add r0, r3, #0
	add r6, r4, #0
_021F6042:
	add r3, r3, #1
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	cmp r3, #3
	blo _021F6030
	cmp r0, #3
	bne _021F6056
	bl GF_AssertFail
	mov r0, #3
_021F6056:
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	nop
_021F605C: .word 0x00000FB4
	thumb_func_end ov96_021F5F68


	thumb_func_start ov96_021F6060
ov96_021F6060: ; 0x021F6060
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	add r1, r2, #0
	add r2, sp, #0
	add r4, r3, #0
	bl VEC_Subtract
	add r0, sp, #0
	bl VEC_Mag
	add r1, r5, r4
	cmp r0, r1
	bgt _021F6082
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_021F6082:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end ov96_021F6060


	thumb_func_start ov96_021F6088
ov96_021F6088: ; 0x021F6088
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r2, #0
	add r6, r0, #0
	ldr r0, [r4, #4]
	add r5, r1, #0
	cmp r0, #0
	ble _021F6120
	ldr r1, _021F6124 ; =0x00000FAC
	add r2, r6, r1
	mov r1, #0x1c
	mul r1, r5
	add r7, r2, r1
	ldr r1, [r7, #0x14]
	cmp r1, #0
	bne _021F6120
	asr r1, r0, #5
	lsr r1, r1, #0x1a
	add r1, r0, r1
	asr r0, r1, #6
	bl _dflt
	ldr r3, _021F6128 ; =0x40040000
	mov r2, #0
	bl _ddiv
	bl _dfix
	str r0, [sp]
	ldr r0, [r4]
	neg r1, r0
	asr r0, r1, #1
	lsr r0, r0, #0x1e
	add r0, r1, r0
	asr r0, r0, #2
	bmi _021F60DC
	mov r1, #0xa
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _021F60E4
	add r0, r1, #0
	b _021F60E4
_021F60DC:
	ldr r1, _021F612C ; =0xFFFF6000
	cmp r0, r1
	bge _021F60E4
	add r0, r1, #0
_021F60E4:
	mov r1, #0x38
	add r4, r5, #0
	mul r4, r1
	add r1, r6, #0
	str r1, [sp, #4]
	add r1, #0xa8
	str r0, [r1, r4]
	add r0, r1, #0
	str r1, [sp, #4]
	ldr r1, [r0, r4]
	add r0, r6, r4
	add r0, #0xc4
	ldr r0, [r0]
	mul r0, r1
	mov r1, #0xc
	bl _s32_div_f
	ldr r1, [sp, #4]
	str r0, [r1, r4]
	ldr r0, [sp]
	ldr r1, _021F6130 ; =ov96_0221DC18
	neg r0, r0
	str r0, [r7]
	str r0, [r7, #0x18]
	mov r0, #1
	str r0, [r7, #0x14]
	ldrb r1, [r1, r5]
	ldr r0, _021F6134 ; =0x000008C2
	bl sub_0200606C
_021F6120:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F6124: .word 0x00000FAC
_021F6128: .word 0x40040000
_021F612C: .word 0xFFFF6000
_021F6130: .word ov96_0221DC18
_021F6134: .word 0x000008C2
	thumb_func_end ov96_021F6088


	thumb_func_start ov96_021F6138
ov96_021F6138: ; 0x021F6138
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl NNS_G3dInit
	bl G3X_InitMtxStack
	ldr r0, _021F61B0 ; =0x04000540
	mov r3, #2
	str r3, [r0]
	ldr r0, _021F61B4 ; =0x04000008
	mov r1, #3
	ldrh r2, [r0]
	bic r2, r1
	add r1, r2, #0
	orr r1, r3
	strh r1, [r0]
	add r0, #0x58
	ldrh r1, [r0]
	ldr r2, _021F61B8 ; =0xFFFFCFFD
	ldr r3, _021F61BC ; =0x0000CFEF
	and r1, r2
	strh r1, [r0]
	ldrh r1, [r0]
	lsr r2, r2, #0x11
	and r1, r3
	strh r1, [r0]
	add r1, r3, #0
	ldrh r5, [r0]
	add r1, #0xc
	and r1, r5
	strh r1, [r0]
	add r1, r3, #0
	ldrh r5, [r0]
	add r1, #8
	sub r3, #0x10
	and r1, r5
	strh r1, [r0]
	ldrh r1, [r0]
	and r1, r3
	strh r1, [r0]
	mov r0, #0
	add r1, r0, #0
	mov r3, #0x3f
	str r0, [sp]
	bl G3X_SetClearColor
	ldr r1, _021F61C0 ; =0xBFFF0000
	ldr r0, _021F61C4 ; =0x04000580
	str r1, [r0]
	ldr r0, [r4, #0x54]
	bl Camera_New
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov96_021F6398
	pop {r3, r4, r5, pc}
	nop
_021F61B0: .word 0x04000540
_021F61B4: .word 0x04000008
_021F61B8: .word 0xFFFFCFFD
_021F61BC: .word 0x0000CFEF
_021F61C0: .word 0xBFFF0000
_021F61C4: .word 0x04000580
	thumb_func_end ov96_021F6138


	thumb_func_start ov96_021F61C8
ov96_021F61C8: ; 0x021F61C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x4c
	ldr r5, _021F6358 ; =ov96_0221C0E8
	add r4, r0, #0
	ldmia r5!, {r0, r1}
	add r3, sp, #0x40
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [r3]
	mov r0, #0x1b
	mov r2, #3
	bl NNS_G3dGeBufferOP_N
	ldr r0, _021F635C ; =0x00310081
	add r1, sp, #0x3c
	str r0, [sp, #0x3c]
	mov r0, #0x29
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	mov r0, #0xbf
	str r0, [sp, #0x38]
	mov r0, #0x20
	add r1, sp, #0x38
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	bl NNS_G3dGlbFlushP
	mov r0, #3
	str r0, [sp, #0x34]
	mov r0, #0x40
	add r1, sp, #0x34
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	ldr r0, _021F6360 ; =ov96_0221E5A0
	mov r2, #0
	str r2, [r0]
	ldr r0, _021F6364 ; =ov96_0221DC10
	mov r1, #0xa
	str r1, [r0, #4]
	mov r1, #0x14
	str r1, [r0]
	mov r0, #0xe
	lsl r0, r0, #0xc
	str r0, [sp, #0x2c]
	str r2, [sp, #0x30]
	mov r0, #0x23
	add r1, sp, #0x2c
	mov r2, #2
	bl NNS_G3dGeBufferOP_N
	ldr r0, _021F6368 ; =0xE800E000
	add r1, sp, #0x24
	str r0, [sp, #0x24]
	mov r0, #0
	str r0, [sp, #0x28]
	mov r0, #0x23
	mov r2, #2
	bl NNS_G3dGeBufferOP_N
	add r5, r4, #4
	ldr r4, _021F6364 ; =ov96_0221DC10
	mov r6, #1
_021F624E:
	add r0, r6, #0
	bl _fflt
	bl _f2d
	ldr r3, _021F636C ; =0x40500000
	mov r2, #0
	bl _dsub
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021F6370 ; =0x40100000
	mov r0, #0
	bl _dmul
	ldr r3, _021F6374 ; =0x40600000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r7, r0, #0
	ldr r0, _021F6378 ; =0x45800000
	add r1, r7, #0
	bl _fmul
	bl _ffix
	mov r1, #0x67
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	lsl r0, r0, #0x10
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	lsr r0, r0, #0x10
	lsl r1, r1, #0x10
	orr r0, r1
	str r0, [sp, #0x1c]
	mov r0, #0
	str r0, [sp, #0x20]
	mov r0, #0x23
	add r1, sp, #0x1c
	mov r2, #2
	bl NNS_G3dGeBufferOP_N
	ldr r0, _021F6378 ; =0x45800000
	add r1, r7, #0
	bl _fmul
	bl _ffix
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	mov r0, #0x3a
	lsl r0, r0, #0x1a
	orr r0, r1
	str r0, [sp, #0x14]
	mov r0, #0
	str r0, [sp, #0x18]
	mov r0, #0x23
	add r1, sp, #0x14
	mov r2, #2
	bl NNS_G3dGeBufferOP_N
	ldr r1, _021F6360 ; =ov96_0221E5A0
	ldr r0, [r4]
	ldr r2, [r1]
	ldr r1, [r4, #4]
	lsl r0, r0, #0xa
	lsl r1, r1, #5
	orr r1, r2
	orr r0, r1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	mov r0, #0x20
	add r1, sp, #0x10
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	ldr r0, _021F6360 ; =ov96_0221E5A0
	mov r1, #0x1f
	ldr r0, [r0]
	add r0, r0, #1
	bl _s32_div_f
	ldr r0, _021F6360 ; =ov96_0221E5A0
	str r1, [r0]
	ldr r0, [r4, #4]
	mov r1, #0x1f
	add r0, r0, #1
	bl _s32_div_f
	str r1, [r4, #4]
	ldr r0, [r4]
	mov r1, #0x1f
	add r0, r0, #1
	bl _s32_div_f
	add r6, r6, #1
	add r5, r5, #4
	str r1, [r4]
	cmp r6, #0x80
	ble _021F624E
	mov r0, #0xe
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r0, #0x23
	add r1, sp, #8
	mov r2, #2
	bl NNS_G3dGeBufferOP_N
	ldr r0, _021F6368 ; =0xE800E000
	add r1, sp, #0
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0x23
	mov r2, #2
	bl NNS_G3dGeBufferOP_N
	mov r1, #0
	mov r0, #0x41
	add r2, r1, #0
	bl NNS_G3dGeBufferOP_N
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
	nop
_021F6358: .word ov96_0221C0E8
_021F635C: .word 0x00310081
_021F6360: .word ov96_0221E5A0
_021F6364: .word ov96_0221DC10
_021F6368: .word 0xE800E000
_021F636C: .word 0x40500000
_021F6370: .word 0x40100000
_021F6374: .word 0x40600000
_021F6378: .word 0x45800000
	thumb_func_end ov96_021F61C8


	thumb_func_start ov96_021F637C
ov96_021F637C: ; 0x021F637C
	push {r4, lr}
	add r4, r0, #0
	bl Thunk_G3X_Reset
	bl Camera_PushLookAtToNNSGlb
	add r0, r4, #0
	bl ov96_021F61C8
	mov r0, #0
	add r1, r0, #0
	bl RequestSwap3DBuffers
	pop {r4, pc}
	thumb_func_end ov96_021F637C


	thumb_func_start ov96_021F6398
ov96_021F6398: ; 0x021F6398
	push {r3, r4, lr}
	sub sp, #0x2c
	ldr r3, _021F6420 ; =ov96_0221C0F4
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x14
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0x65
	str r0, [r2]
	lsl r1, r1, #2
	mov r2, #0
	str r2, [r4, r1]
	add r0, r1, #4
	str r2, [r4, r0]
	add r0, r1, #0
	add r0, #8
	str r2, [r4, r0]
	add r0, sp, #0xc
	strh r2, [r0]
	strh r2, [r0, #2]
	strh r2, [r0, #4]
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	sub r0, r1, #4
	ldr r0, [r4, r0]
	add r2, sp, #0xc
	str r0, [sp, #8]
	add r0, r4, r1
	mov r1, #0x19
	lsl r1, r1, #0xe
	mov r3, #0xa4
	bl Camera_Init_FromTargetDistanceAndAngle
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	add r0, sp, #0x14
	bl Camera_OffsetLookAtPosAndTarget
	mov r2, #0x19
	mov r0, #1
	lsl r2, r2, #4
	lsl r0, r0, #0xe
	ldr r2, [r4, r2]
	lsl r1, r0, #6
	bl Camera_SetPerspectiveClippingPlane
	mov r1, #0
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #0x24]
	str r1, [sp, #0x20]
	str r1, [sp, #0x28]
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	add r0, sp, #0x20
	bl Camera_SetLookAtCamUp
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl Camera_SetStaticPtr
	add sp, #0x2c
	pop {r3, r4, pc}
	.balign 4, 0
_021F6420: .word ov96_0221C0F4
	thumb_func_end ov96_021F6398


	thumb_func_start ov96_021F6424
ov96_021F6424: ; 0x021F6424
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0
	add r2, r1, #0
	mov r3, #1
	add r4, r0, #0
	bl ov96_021F6524
	mov r1, #1
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #2
	bl ov96_021F6524
	mov r1, #2
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0
	bl ov96_021F6524
	mov r2, #2
	lsl r2, r2, #0xa
	mov r3, #6
	mov r0, #0
	lsl r3, r3, #8
	lsr r5, r2, #2
	lsr r6, r2, #1
_021F6458:
	ldr r7, [r4, r5]
	str r7, [r4]
	ldr r1, [r4, r6]
	cmp r7, r1
	ble _021F6464
	str r1, [r4]
_021F6464:
	ldr r7, [r4, r3]
	ldr r1, [r4]
	cmp r1, r7
	ble _021F646E
	str r7, [r4]
_021F646E:
	ldr r7, [r4, r2]
	ldr r1, [r4]
	cmp r1, r7
	ble _021F6478
	str r7, [r4]
_021F6478:
	mov r1, #0xa
	lsl r1, r1, #8
	ldr r7, [r4, r1]
	ldr r1, [r4]
	cmp r1, r7
	ble _021F6486
	str r7, [r4]
_021F6486:
	mov r1, #3
	lsl r1, r1, #0xa
	ldr r7, [r4, r1]
	ldr r1, [r4]
	cmp r1, r7
	ble _021F6494
	str r7, [r4]
_021F6494:
	add r0, r0, #1
	add r4, r4, #4
	cmp r0, #0x80
	blt _021F6458
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F6424


	thumb_func_start ov96_021F64A0
ov96_021F64A0: ; 0x021F64A0
	push {r4, r5, r6, r7}
	mov r4, #1
	mov r5, #2
	mov r6, #4
	mov r3, #0
	and r4, r1
	and r5, r1
	and r1, r6
_021F64B0:
	mov r6, #0
	str r6, [r2]
	cmp r4, #0
	beq _021F64D4
	mov r6, #2
	lsl r6, r6, #8
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F64C6
	str r7, [r2]
_021F64C6:
	mov r6, #2
	lsl r6, r6, #0xa
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F64D4
	str r7, [r2]
_021F64D4:
	cmp r5, #0
	beq _021F64F4
	mov r6, #1
	lsl r6, r6, #0xa
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F64E6
	str r7, [r2]
_021F64E6:
	mov r6, #0xa
	lsl r6, r6, #8
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F64F4
	str r7, [r2]
_021F64F4:
	cmp r1, #0
	beq _021F6514
	mov r6, #6
	lsl r6, r6, #8
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F6506
	str r7, [r2]
_021F6506:
	mov r6, #3
	lsl r6, r6, #0xa
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F6514
	str r7, [r2]
_021F6514:
	add r3, r3, #1
	add r2, r2, #4
	add r0, r0, #4
	cmp r3, #0x80
	blt _021F64B0
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021F64A0


	thumb_func_start ov96_021F6524
ov96_021F6524: ; 0x021F6524
	push {r0, r1, r2, r3}
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r3, sp, #0x20
	ldrb r4, [r3, #0xc]
	add r2, r0, #0
	add r0, r1, #0
	mov r1, #0xe
	lsl r1, r1, #8
	ldrb r3, [r3, #8]
	lsl r5, r4, #2
	add r1, r2, r1
	lsl r4, r3, #2
	add r7, r1, r5
	ldr r3, [r1, r4]
	ldr r5, [r1, r5]
	cmp r3, r5
	bgt _021F6550
	add r6, r1, r4
	add r5, sp, #0x28
	add r1, sp, #0x2c
	b _021F6558
_021F6550:
	add r6, r7, #0
	add r7, r1, r4
	add r5, sp, #0x2c
	add r1, sp, #0x28
_021F6558:
	lsl r0, r0, #9
	add r3, r2, r0
	mov ip, r1
	mov r1, #0
	mov r0, #2
	str r3, [sp]
	add r4, r1, #0
	lsl r0, r0, #0xa
_021F6568:
	add r1, r1, #1
	str r4, [r3, r0]
	add r3, r3, #4
	cmp r1, #0x80
	blt _021F6568
	ldrb r1, [r5]
	ldr r0, [r6]
	lsl r1, r1, #9
	add r3, r2, r1
	lsl r1, r0, #2
	add r3, r3, r1
	mov r1, #2
	lsl r1, r1, #8
	ldr r5, [r3, r1]
	mov r3, ip
	ldrb r3, [r3]
	ldr r1, [r7]
	lsl r3, r3, #9
	add r3, r2, r3
	lsl r2, r1, #2
	add r3, r3, r2
	mov r2, #2
	lsl r2, r2, #8
	ldr r2, [r3, r2]
	sub r0, r1, r0
	str r0, [sp, #4]
	sub r0, r0, #1
	sub r7, r2, r5
	str r0, [sp, #8]
	cmp r0, #0
	ble _021F65C8
_021F65A6:
	add r0, r4, #1
	ldr r1, [sp, #4]
	mul r0, r7
	bl _s32_div_f
	ldr r1, [r6]
	add r0, r5, r0
	add r1, r1, r4
	lsl r2, r1, #2
	ldr r1, [sp]
	add r4, r4, #1
	add r2, r1, r2
	ldr r1, _021F65D4 ; =0x00000804
	str r0, [r2, r1]
	ldr r0, [sp, #8]
	cmp r4, r0
	blt _021F65A6
_021F65C8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r3}
	add sp, #0x10
	bx r3
	nop
_021F65D4: .word 0x00000804
	thumb_func_end ov96_021F6524


	thumb_func_start ov96_021F65D8
ov96_021F65D8: ; 0x021F65D8
	ldrh r1, [r0, #0x24]
	cmp r1, #5
	bhs _021F65E2
	add r1, r1, #1
	strh r1, [r0, #0x24]
_021F65E2:
	ldrh r2, [r0, #0x20]
	ldrh r1, [r0, #0x24]
	add r1, r2, r1
	strh r1, [r0, #0x20]
	ldrh r2, [r0, #0x20]
	ldr r1, _021F65FC ; =0x000003E7
	cmp r2, r1
	bls _021F65F4
	strh r1, [r0, #0x20]
_021F65F4:
	ldrh r0, [r0, #0x24]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bx lr
	.balign 4, 0
_021F65FC: .word 0x000003E7
	thumb_func_end ov96_021F65D8


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


	thumb_func_start ov96_021F6B28
ov96_021F6B28: ; 0x021F6B28
	ldr r1, [r1, #8]
	cmp r1, #0
	ble _021F6B4C
	ldr r2, [r0, #8]
	ldr r1, [r0, #0x18]
	add r2, r2, r1
	mov r1, #2
	lsl r1, r1, #0x10
	str r2, [r0, #0x1c]
	cmp r2, r1
	bge _021F6B42
	str r1, [r0, #0x1c]
	bx lr
_021F6B42:
	mov r1, #0xdf
	lsl r1, r1, #0xc
	cmp r2, r1
	ble _021F6B4C
	str r1, [r0, #0x1c]
_021F6B4C:
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021F6B28


	thumb_func_start ov96_021F6B50
ov96_021F6B50: ; 0x021F6B50
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	neg r0, r1
	str r0, [sp, #4]
	mov r0, #0x7f
	str r2, [sp]
	sub r4, r0, r7
	mov r6, #0
	cmp r7, #0
	ble _021F6B82
	add r5, r2, #0
_021F6B68:
	add r0, r6, #1
	lsl r0, r0, #0x18
	ldr r1, [sp, #4]
	lsr r0, r0, #0x18
	mul r0, r1
	add r1, r7, #1
	bl _s32_div_f
	neg r0, r0
	add r6, r6, #1
	stmia r5!, {r0}
	cmp r6, r7
	blt _021F6B68
_021F6B82:
	mov r5, #0
	cmp r4, #0
	ble _021F6BAC
	add r6, r7, #1
_021F6B8A:
	sub r0, r4, r5
	lsl r0, r0, #0x18
	ldr r1, [sp, #4]
	lsr r0, r0, #0x18
	mul r0, r1
	add r1, r4, #1
	bl _s32_div_f
	add r1, r6, r5
	lsl r1, r1, #0x18
	lsr r2, r1, #0x16
	ldr r1, [sp]
	neg r0, r0
	add r5, r5, #1
	str r0, [r1, r2]
	cmp r5, r4
	blt _021F6B8A
_021F6BAC:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F6B50


	thumb_func_start ov96_021F6BB0
ov96_021F6BB0: ; 0x021F6BB0
	push {r4, r5}
	mov r1, #0x1a
	lsl r1, r1, #4
	add r2, r0, r1
	ldr r3, _021F6BE0 ; =0x00000FAC
	mov r4, #0xe
	add r0, r0, r3
	mov r1, #0
	add r3, r2, #0
	lsl r4, r4, #8
_021F6BC4:
	ldr r5, [r0, #0x14]
	cmp r5, #0
	bne _021F6BD2
	ldr r5, [r3, r4]
	lsl r5, r5, #2
	ldr r5, [r2, r5]
	str r5, [r0, #8]
_021F6BD2:
	add r1, r1, #1
	add r0, #0x1c
	add r3, r3, #4
	cmp r1, #3
	blt _021F6BC4
	pop {r4, r5}
	bx lr
	.balign 4, 0
_021F6BE0: .word 0x00000FAC
	thumb_func_end ov96_021F6BB0


	thumb_func_start ov96_021F6BE4
ov96_021F6BE4: ; 0x021F6BE4
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	lsl r6, r1, #9
	add r7, r3, #0
	mov r1, #0x3a
	mov r3, #0
	add r0, r2, #0
	add r5, r4, r6
	add r2, r3, #0
	lsl r1, r1, #4
_021F6BF8:
	add r3, r3, #1
	str r2, [r5, r1]
	add r5, r5, #4
	cmp r3, #0x80
	blt _021F6BF8
	mov r1, #0x3a
	lsl r1, r1, #4
	add r1, r4, r1
	add r2, r1, r6
	lsl r1, r0, #2
	str r7, [r2, r1]
	ldr r1, [r2, r1]
	bl ov96_021F6B50
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F6BE4


	thumb_func_start ov96_021F6C18
ov96_021F6C18: ; 0x021F6C18
	push {r4, lr}
	sub sp, #8
	mov r2, #3
	mov r1, #0xa8
	mov r3, #0x65
	add r4, r0, #0
	str r2, [sp]
	bl ov96_021EB2BC
	mov r0, #3
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xa8
	mov r2, #0
	mov r3, #0x65
	bl ov96_021EB2F4
	add r0, r4, #0
	mov r1, #0xa8
	mov r2, #2
	mov r3, #0x65
	bl ov96_021EB334
	add r0, r4, #0
	mov r1, #0xa8
	mov r2, #1
	mov r3, #0x65
	bl ov96_021EB36C
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F6C18


	thumb_func_start ov96_021F6C5C
ov96_021F6C5C: ; 0x021F6C5C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp, #4]
	add r0, #0x8c
	ldr r0, [r0]
	add r5, r1, #0
	mov r2, #2
	bl ov96_021F74D0
	mov r2, #3
	add r0, r5, #0
	mov r1, #1
	mov r3, #0x65
	str r2, [sp]
	bl ov96_021EB3E4
	ldr r1, [sp, #4]
	str r0, [r1, #0x64]
	mov r1, #0xc
	bl ov96_021EB564
	ldr r0, [sp, #4]
	mov r1, #1
	ldr r0, [r0, #0x64]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r4, [sp, #4]
	mov r6, #0
	mov r7, #4
_021F6C98:
	add r0, r5, #0
	mov r1, #1
	mov r2, #3
	mov r3, #0x65
	str r7, [sp]
	bl ov96_021EB3E4
	add r1, r6, #0
	str r0, [r4, #0x68]
	add r1, #0xd
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r4, #0x68]
	add r2, r1, #0
	bl ov96_021EB52C
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #4
	blt _021F6C98
	ldr r4, [sp, #4]
	mov r6, #0
	mov r7, #7
_021F6CC8:
	add r0, r5, #0
	mov r1, #1
	mov r2, #3
	mov r3, #0x65
	str r7, [sp]
	bl ov96_021EB3E4
	add r1, r4, #0
	add r1, #0x94
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0xb
	bl ov96_021EB564
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #9
	bl ov96_021EB630
	add r6, r6, #1
	add r4, #0x38
	cmp r6, #4
	blt _021F6CC8
	ldr r4, [sp, #4]
	mov r6, #0
	mov r7, #8
_021F6D02:
	str r7, [sp]
	add r0, r5, #0
	mov r1, #1
	mov r2, #3
	mov r3, #0x65
	bl ov96_021EB3E4
	str r0, [r4, #0x78]
	mov r1, #9
	bl ov96_021EB564
	ldr r0, [r4, #0x78]
	mov r1, #6
	bl ov96_021EB630
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #4
	blt _021F6D02
	mov r0, #0
	ldr r4, [sp, #4]
	ldr r7, _021F6D9C ; =ov96_0221C0B0
	ldr r6, _021F6DA0 ; =ov96_0221C0B4
	str r0, [sp, #8]
_021F6D32:
	add r0, r5, #0
	bl ov96_021EB5E8
	add r1, r0, #0
	mov r0, #0x62
	ldr r3, [sp, #4]
	ldr r2, [sp, #4]
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	ldr r3, [r3, #0x54]
	mov r2, #1
	bl ov96_021EA634
	add r1, r4, #0
	add r1, #0x84
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x84
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldrb r0, [r7]
	add r1, sp, #0xc
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	mov r0, #2
	lsl r0, r0, #0xe
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x84
	ldr r0, [r0]
	bl Sprite_SetMatrix
	add r0, r4, #0
	add r0, #0x84
	ldrb r1, [r6]
	ldr r0, [r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [sp, #8]
	add r4, r4, #4
	add r0, r0, #1
	add r7, r7, #1
	add r6, r6, #1
	str r0, [sp, #8]
	cmp r0, #2
	blt _021F6D32
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F6D9C: .word ov96_0221C0B0
_021F6DA0: .word ov96_0221C0B4
	thumb_func_end ov96_021F6C5C


	thumb_func_start ov96_021F6DA4
ov96_021F6DA4: ; 0x021F6DA4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r5, r0, #0
	str r1, [sp]
	add r0, #0x8c
	ldr r0, [r0]
	bl ov96_021F7544
	ldr r4, _021F6E2C ; =ov96_0221C0C4
	add r3, sp, #0x28
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r5, #0x64]
	bl ov96_021EB588
	ldr r4, _021F6E30 ; =ov96_0221C0DC
	add r3, sp, #0x1c
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [sp]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x68]
	bl ov96_021EB588
	ldr r3, _021F6E34 ; =ov96_0221C0D0
	mov r4, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #4
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r6, r4, #0
	str r0, [r2]
_021F6DF6:
	add r3, sp, #4
	ldmia r3!, {r0, r1}
	add r2, sp, #0x10
	add r7, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [sp]
	cmp r6, r0
	beq _021F6E20
	ldr r1, [sp, #0x14]
	lsl r0, r4, #0x10
	add r0, r1, r0
	str r0, [sp, #0x14]
	ldr r0, [r5, #0x68]
	add r1, r7, #0
	bl ov96_021EB588
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_021F6E20:
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #4
	blt _021F6DF6
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021F6E2C: .word ov96_0221C0C4
_021F6E30: .word ov96_0221C0DC
_021F6E34: .word ov96_0221C0D0
	thumb_func_end ov96_021F6DA4


	thumb_func_start ov96_021F6E38
ov96_021F6E38: ; 0x021F6E38
	push {r4, lr}
	mov r1, #0
	add r2, r1, #0
	add r3, r0, #0
_021F6E40:
	add r4, r3, #0
	add r4, #0xb0
	ldrh r4, [r4]
	add r2, r2, #1
	add r3, #0x38
	add r1, r1, r4
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	cmp r2, #3
	blt _021F6E40
	ldr r2, _021F6E64 ; =0x000003E7
	cmp r1, r2
	bls _021F6E5C
	add r1, r2, #0
_021F6E5C:
	bl ov96_021F6E68
	pop {r4, pc}
	nop
_021F6E64: .word 0x000003E7
	thumb_func_end ov96_021F6E38


	thumb_func_start ov96_021F6E68
ov96_021F6E68: ; 0x021F6E68
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
_021F6EF2:
	str r6, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x5c]
	lsl r2, r4, #2
	add r0, #0xc
	str r0, [sp, #8]
	add r0, sp, #0x1c
	add r0, #3
	ldrb r0, [r0, r4]
	add r2, r2, #1
	lsl r2, r2, #0x18
	str r0, [sp, #0xc]
	add r0, sp, #0x1c
	ldrb r0, [r0, r4]
	add r1, r6, #0
	lsr r2, r2, #0x18
	str r0, [sp, #0x10]
	mov r0, #0x14
	str r0, [sp, #0x14]
	mov r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [r5]
	mov r3, #0
	bl CopyRectToBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021F6EF2
	ldr r0, [r5]
	mov r1, #4
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F6E68


	thumb_func_start ov96_021F6F3C
ov96_021F6F3C: ; 0x021F6F3C
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
	add r0, r5, #0
	add r0, #0x84
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r5, #0x88
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021F6F3C


	thumb_func_start ov96_021F6F80
ov96_021F6F80: ; 0x021F6F80
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r7, r1, #0
	mov r4, #0
	str r0, [sp, #0x10]
	add r5, r7, #4
	add r6, r4, #0
_021F6F8E:
	lsl r0, r4, #4
	add r0, r5, r0
	add r1, r6, #0
	bl FillWindowPixelBuffer
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _021F6F8E
	ldr r0, [sp, #0x10]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r7, #0x54]
	bl PlayerProfile_GetPlayerName_NewString
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021F704C ; =0x000F0E00
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r7, #4
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add r0, r7, #4
	mov r4, #1
	mov r5, #0
	str r0, [sp, #0x18]
_021F6FE4:
	ldr r0, [sp, #0x14]
	cmp r5, r0
	beq _021F7026
	ldr r0, [sp, #0x10]
	add r1, r5, #0
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r7, #0x54]
	bl PlayerProfile_GetPlayerName_NewString
	add r6, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021F704C ; =0x000F0E00
	lsl r1, r4, #4
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x18]
	add r2, r6, #0
	add r0, r0, r1
	mov r1, #0
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_021F7026:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #4
	blo _021F6FE4
	mov r4, #0
	add r5, r7, #4
_021F7034:
	lsl r0, r4, #4
	add r0, r5, r0
	bl CopyWindowToVram
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _021F7034
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_021F704C: .word 0x000F0E00
	thumb_func_end ov96_021F6F80


	thumb_func_start ov96_021F7050
ov96_021F7050: ; 0x021F7050
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r7, _021F70A8 ; =ov96_0221C1CC
	mov r4, #0
	add r6, r5, #4
_021F705A:
	lsl r1, r4, #4
	lsl r2, r4, #3
	ldr r0, [r5]
	add r1, r6, r1
	add r2, r7, r2
	bl AddWindow
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _021F705A
	mov r2, #0
	str r2, [sp]
	ldr r0, [r5]
	mov r1, #6
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r5, #0x54]
	mov r0, #4
	lsl r1, r1, #4
	bl LoadFontPal0
	mov r2, #0
	str r2, [sp]
	ldr r0, [r5]
	mov r1, #3
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r5, #0x54]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F70A8: .word ov96_0221C1CC
	thumb_func_end ov96_021F7050


	thumb_func_start ov96_021F70AC
ov96_021F70AC: ; 0x021F70AC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	add r0, #0x44
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r2, _021F7128 ; =0x00000135
	ldr r3, [r5, #0x54]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	add r4, r0, #0
	ldr r0, [r5, #0x54]
	bl MessageFormat_New
	mov r1, #1
	str r1, [sp]
	str r1, [sp, #4]
	mov r1, #0
	add r2, r7, #0
	mov r3, #3
	add r6, r0, #0
	bl BufferIntegerAsString
	ldr r3, [r5, #0x54]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0xa1
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021F712C ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x44
	add r2, r7, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl MessageFormat_Delete
	add r0, r4, #0
	bl DestroyMsgData
	add r5, #0x44
	add r0, r5, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F7128: .word 0x00000135
_021F712C: .word 0x000F0E00
	thumb_func_end ov96_021F70AC


	thumb_func_start ov96_021F7130
ov96_021F7130: ; 0x021F7130
	ldr r2, [r0, #0x18]
	cmp r2, #0
	beq _021F715A
	ble _021F7148
	mov r1, #2
	lsl r1, r1, #0xc
	sub r1, r2, r1
	str r1, [r0, #0x18]
	bpl _021F715A
	mov r1, #0
	str r1, [r0, #0x18]
	bx lr
_021F7148:
	bge _021F715A
	mov r1, #2
	lsl r1, r1, #0xc
	add r1, r2, r1
	str r1, [r0, #0x18]
	cmp r1, #0
	ble _021F715A
	mov r1, #0
	str r1, [r0, #0x18]
_021F715A:
	bx lr
	thumb_func_end ov96_021F7130


	thumb_func_start ov96_021F715C
ov96_021F715C: ; 0x021F715C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r5, r1, #0
	add r7, r2, #0
	add r4, r3, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	add r0, r6, #0
	add r2, r7, #0
	bl ov96_021E60D8
	ldrb r1, [r0, #2]
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	str r1, [r4, #0x2c]
	ldrb r1, [r0, #3]
	lsl r1, r1, #2
	add r1, r5, r1
	ldr r1, [r1, #0x14]
	str r1, [r4, #0x30]
	ldrb r0, [r0, #4]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x28]
	str r0, [r4, #0x34]
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F715C


	thumb_func_start ov96_021F7194
ov96_021F7194: ; 0x021F7194
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x60
	str r0, [sp, #8]
	mov r0, #0
	add r4, r1, #0
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r1, _021F7494 ; =0x00000FAC
	ldr r0, [sp, #0xc]
	add r4, #0x90
	add r0, r0, r1
	str r0, [sp, #0x14]
_021F71AC:
	ldr r1, _021F7494 ; =0x00000FAC
	ldr r0, [sp, #0xc]
	ldr r5, [sp, #0xc]
	add r6, r0, r1
	ldr r0, [sp, #0x10]
	mov r7, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x24]
	add r0, r4, #0
	str r0, [sp, #0x28]
	add r0, #0x1c
	add r5, #0x90
	str r0, [sp, #0x28]
_021F71C8:
	ldr r0, [sp, #0x10]
	cmp r0, r7
	beq _021F72A0
	ldr r0, [sp, #8]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r4]
	str r0, [sp, #0x20]
	ldr r0, [r5]
	str r0, [sp, #0x1c]
	add r0, sp, #0x2c
	str r0, [sp]
	ldr r1, [r4, #0x1c]
	ldr r0, [sp, #0x20]
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	ldr r2, [sp, #0x14]
	ldr r2, [r2, #8]
	lsl r3, r2, #6
	mov r2, #0x12
	lsl r2, r2, #0x10
	sub r3, r2, r3
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r2, r2, #0xc
	add r3, sp, #0x30
	bl ov96_021EB0A4
	add r0, sp, #0x58
	str r0, [sp]
	add r0, sp, #0x38
	str r0, [sp, #4]
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x2c]
	ldr r0, [sp, #0x20]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x54
	bl ov96_021EAF78
	mov r0, #0
	str r0, [sp, #0x5c]
	add r0, sp, #0x2c
	str r0, [sp]
	ldr r1, [r5, #0x1c]
	ldr r0, [sp, #0x1c]
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	ldr r2, [r6, #8]
	lsl r3, r2, #6
	mov r2, #0x12
	lsl r2, r2, #0x10
	sub r3, r2, r3
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r2, r2, #0xc
	add r3, sp, #0x30
	bl ov96_021EB0A4
	add r0, sp, #0x4c
	str r0, [sp]
	add r0, sp, #0x34
	str r0, [sp, #4]
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x2c]
	ldr r0, [sp, #0x1c]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x48
	bl ov96_021EAF78
	ldr r1, [sp, #0x38]
	ldr r3, [sp, #0x34]
	mov r0, #0
	str r0, [sp, #0x50]
	add r0, sp, #0x54
	lsl r1, r1, #0xc
	add r2, sp, #0x48
	lsl r3, r3, #0xc
	bl ov96_021F6060
	cmp r0, #0
	bne _021F7294
	add r1, r4, r7
	add r1, #0x29
	mov r0, #0
	strb r0, [r1]
	ldr r0, [sp, #0x10]
	add r1, r0, r5
	add r1, #0x29
	mov r0, #0
	strb r0, [r1]
	b _021F746C
_021F7294:
	ldr r0, [sp, #0x10]
	add r0, r0, r5
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	beq _021F72A2
_021F72A0:
	b _021F746C
_021F72A2:
	add r1, r4, #0
	add r1, #0x26
	mov r0, #1
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x26
	strb r0, [r1]
	ldr r1, [r4, #0x30]
	mov r0, #0x1e
	mul r0, r1
	mov r1, #0x1e
	bl _s32_div_f
	add r1, r4, #0
	add r1, #0x27
	strb r0, [r1]
	ldr r1, [r5, #0x30]
	mov r0, #0x1e
	mul r0, r1
	mov r1, #0x1e
	bl _s32_div_f
	add r1, r5, #0
	add r1, #0x27
	strb r0, [r1]
	mov r1, #0
	add r0, sp, #0x3c
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	add r0, sp, #0x48
	add r1, sp, #0x54
	add r2, sp, #0x3c
	bl VEC_Subtract
	add r0, sp, #0x3c
	add r1, r0, #0
	bl VEC_Normalize
	ldr r0, [sp, #0x38]
	add r1, sp, #0x3c
	lsl r0, r0, #0xc
	add r2, sp, #0x54
	add r3, r1, #0
	bl VEC_MultAdd
	ldr r1, [sp, #0xc]
	ldr r0, _021F7498 ; =0x00000143
	ldrb r1, [r1, r0]
	mov r0, #0xc
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #0xc]
	add r1, r0, r2
	mov r0, #0x51
	lsl r0, r0, #2
	add r2, sp, #0x3c
	add r3, r1, r0
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	ldr r1, [sp, #0xc]
	str r0, [r3]
	ldr r0, _021F7498 ; =0x00000143
	ldrb r1, [r1, r0]
	ldr r0, [sp, #0xc]
	add r2, r0, r1
	mov r0, #0x5a
	mov r1, #1
	lsl r0, r0, #2
	strb r1, [r2, r0]
	ldr r1, [sp, #0xc]
	sub r0, #0x25
	ldrb r0, [r1, r0]
	mov r1, #3
	add r0, r0, #1
	bl _s32_div_f
	ldr r2, [sp, #0xc]
	ldr r0, _021F7498 ; =0x00000143
	strb r1, [r2, r0]
	ldr r1, _021F749C ; =ov96_0221DC18
	ldr r0, _021F74A0 ; =0x000008A3
	ldrb r1, [r1, #3]
	bl sub_0200606C
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x24]
	mov r3, #4
	bl ov96_021E8228
	mov r0, #1
	str r0, [sp]
	lsl r2, r7, #0x18
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x18]
	lsr r2, r2, #0x18
	mov r3, #4
	bl ov96_021E8228
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x24]
	mov r3, #1
	bl ov96_021E8228
	mov r0, #1
	str r0, [sp]
	lsl r2, r7, #0x18
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x18]
	lsr r2, r2, #0x18
	mov r3, #1
	bl ov96_021E8228
	ldr r0, [sp, #0x14]
	ldr r0, [r0, #0x10]
	cmp r0, #0
	beq _021F7404
	ldr r0, [r6, #0x10]
	cmp r0, #0
	beq _021F7404
	ldr r0, [sp, #0x14]
	ldr r0, [r0, #8]
	cmp r0, #0
	ble _021F7404
	ldr r0, [r6, #8]
	cmp r0, #0
	ble _021F7404
	add r0, r4, r7
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _021F746C
	ldr r0, [sp, #0x10]
	add r0, r0, r5
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _021F746C
	add r1, r4, r7
	add r1, #0x29
	mov r0, #1
	strb r0, [r1]
	ldr r0, [sp, #0x10]
	add r1, r0, r5
	add r1, #0x29
	mov r0, #1
	strb r0, [r1]
	ldr r1, [sp, #0x14]
	ldr r0, [r6]
	ldr r1, [r1]
	str r1, [r6]
	ldr r1, [sp, #0x14]
	str r0, [r1]
	ldr r1, [r5, #0x18]
	ldr r0, [r4, #0x18]
	str r0, [r5, #0x18]
	ldr r0, [sp, #0x14]
	str r1, [r4, #0x18]
	ldr r0, [r0]
	cmp r0, #0
	bge _021F73F8
	ldr r0, [sp, #0x14]
	mov r1, #0
	str r1, [r0]
_021F73F8:
	ldr r0, [r6]
	cmp r0, #0
	bge _021F746C
	mov r0, #0
	str r0, [r6]
	b _021F746C
_021F7404:
	ldr r1, [r4, #0x1c]
	ldr r0, [r5, #0x1c]
	cmp r1, r0
	bgt _021F7424
	ldr r0, [sp, #0x28]
	ldr r1, [r0]
	mov r0, #1
	lsl r0, r0, #0x10
	sub r1, r1, r0
	ldr r0, [sp, #0x28]
	str r1, [r0]
	mov r0, #1
	ldr r1, [r5, #0x1c]
	lsl r0, r0, #0x10
	add r0, r1, r0
	b _021F743A
_021F7424:
	ldr r0, [sp, #0x28]
	ldr r1, [r0]
	mov r0, #1
	lsl r0, r0, #0x10
	add r1, r1, r0
	ldr r0, [sp, #0x28]
	str r1, [r0]
	mov r0, #1
	ldr r1, [r5, #0x1c]
	lsl r0, r0, #0x10
	sub r0, r1, r0
_021F743A:
	str r0, [r5, #0x1c]
	mov r0, #2
	ldr r1, [r4, #0x1c]
	lsl r0, r0, #0x10
	cmp r1, r0
	bge _021F744A
	str r0, [r4, #0x1c]
	b _021F7454
_021F744A:
	mov r0, #0xdf
	lsl r0, r0, #0xc
	cmp r1, r0
	ble _021F7454
	str r0, [r4, #0x1c]
_021F7454:
	mov r0, #2
	ldr r1, [r5, #0x1c]
	lsl r0, r0, #0x10
	cmp r1, r0
	bge _021F7462
	str r0, [r5, #0x1c]
	b _021F746C
_021F7462:
	mov r0, #0xdf
	lsl r0, r0, #0xc
	cmp r1, r0
	ble _021F746C
	str r0, [r5, #0x1c]
_021F746C:
	add r7, r7, #1
	add r5, #0x38
	add r6, #0x1c
	cmp r7, #3
	bge _021F7478
	b _021F71C8
_021F7478:
	ldr r0, [sp, #0x14]
	add r4, #0x38
	add r0, #0x1c
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #3
	bge _021F748C
	b _021F71AC
_021F748C:
	mov r0, #0
	add sp, #0x60
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F7494: .word 0x00000FAC
_021F7498: .word 0x00000143
_021F749C: .word ov96_0221DC18
_021F74A0: .word 0x000008A3
	thumb_func_end ov96_021F7194


	thumb_func_start ov96_021F74A4
ov96_021F74A4: ; 0x021F74A4
	push {r4, lr}
	mov r1, #0x33
	lsl r1, r1, #4
	bl Heap_Alloc
	mov r2, #0x33
	mov r1, #0
	lsl r2, r2, #4
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0xcb
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r4, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F74A4

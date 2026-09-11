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

	thumb_func_start ov96_02209748
ov96_02209748: ; 0x02209748
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	bl PokeathlonCourse_GetGraphicsSystem
	add r6, r0, #0
	bl ov96_021E9510
	mov r4, #0
	add r7, r4, #0
_0220975C:
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl PokeathlonCourse_GetField5F0_AtIndex
	add r3, r0, #0
	str r7, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, _022097A8 ; =0x00000126
	add r1, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r2, r4, #0
	bl ov96_021E95F8
	add r4, r4, #1
	cmp r4, #4
	blt _0220975C
	add r0, r6, #0
	mov r1, #1
	bl ov96_021E93B4
	add r0, r6, #0
	mov r1, #3
	bl ov96_0221A56C
	add r0, r6, #0
	bl ov96_021E952C
	add r0, r6, #0
	mov r1, #3
	bl ov96_021E9570
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_022097A8: .word 0x00000126
	thumb_func_end ov96_02209748


	thumb_func_start ov96_022097AC
ov96_022097AC: ; 0x022097AC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	bl ov96_0220A0E0
	add r0, r5, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _022097CA
	ldr r0, [r4, #0x48]
	bl ov96_0220C998
_022097CA:
	ldr r0, [r4, #0x40]
	bl ov96_0220A7F8
	ldr r0, [r4, #0x44]
	bl ov96_0220B8A0
	ldr r0, [r4, #0x4c]
	bl ov96_0220B500
	add r0, r4, #0
	bl ov96_022099EC
	add r0, r4, #0
	bl ov96_022098E8
	add r0, r4, #0
	bl ov96_02209CA8
	bl sub_0203A914
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	add r0, r5, #0
	bl PokeathlonCourse_FreePtr4HeapAlloc
	ldr r0, _0220981C ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #0x8d
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0220981C: .word gSystem + 0x60
	thumb_func_end ov96_022097AC


	thumb_func_start ov96_02209820
ov96_02209820: ; 0x02209820
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _0220983C ; =ov96_0221CCA0
	add r3, sp, #0
	mov r2, #5
_0220982A:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220982A
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_0220983C: .word ov96_0221CCA0
	thumb_func_end ov96_02209820


	thumb_func_start ov96_02209840
ov96_02209840: ; 0x02209840
	push {r3, r4, lr}
	sub sp, #0x4c
	ldr r3, _022098D8 ; =ov96_0221CC30
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x34
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _022098DC ; =ov96_0221CC80
	add r2, sp, #0x14
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _022098E0 ; =ov96_0221CC1C
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	mov r0, #0x80
	str r0, [sp]
	ldr r0, [r4]
	bl SpriteSystem_Alloc
	str r0, [r4, #8]
	bl SpriteManager_New
	str r0, [r4, #0xc]
	ldr r0, [r4, #8]
	add r1, sp, #0x14
	add r2, sp, #0
	mov r3, #0x20
	bl SpriteSystem_Init
	mov r2, #1
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	lsl r2, r2, #8
	bl SpriteSystem_InitSprites
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	add r2, sp, #0x34
	bl SpriteSystem_InitManagerWithCapacities
	ldr r0, [r4, #8]
	bl SpriteSystem_GetRenderer
	mov r2, #1
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	ldr r0, [r4]
	ldr r1, _022098E4 ; =0x000002E7
	mov r2, #1
	bl ov96_021E9A78
	str r0, [r4, #0x14]
	ldr r1, [r4]
	mov r0, #0x14
	bl NARC_New
	str r0, [r4, #0x50]
	add sp, #0x4c
	pop {r3, r4, pc}
	.balign 4, 0
_022098D8: .word ov96_0221CC30
_022098DC: .word ov96_0221CC80
_022098E0: .word ov96_0221CC1C
_022098E4: .word 0x000002E7
	thumb_func_end ov96_02209840


	thumb_func_start ov96_022098E8
ov96_022098E8: ; 0x022098E8
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x50]
	bl NARC_Delete
	ldr r0, [r4, #0x10]
	bl ov96_021EA894
	ldr r0, [r4, #0x14]
	bl ov96_021E9C0C
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	bl SpriteSystem_FreeResourcesAndManager
	ldr r0, [r4, #8]
	bl SpriteSystem_Free
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_022098E8


	thumb_func_start ov96_02209910
ov96_02209910: ; 0x02209910
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	mov r7, #0
	add r0, sp, #0x14
	str r7, [r0]
	str r7, [r0, #4]
	mov r6, #2
	str r7, [r0, #8]
	lsl r6, r6, #0xe
	add r4, r5, #0
_02209926:
	mov r0, #0xb
	lsl r0, r0, #0x10
	str r6, [sp, #0x14]
	str r0, [sp, #0x18]
	ldr r0, [r5, #0xc]
	bl SpriteManager_GetSpriteList
	add r1, r0, #0
	ldr r0, [r5, #0x14]
	ldr r3, [r5]
	mov r2, #0
	bl ov96_021EA584
	str r0, [r4, #0x2c]
	add r1, sp, #0x14
	bl Sprite_SetMatrix
	ldr r0, [r4, #0x2c]
	mov r1, #2
	bl Sprite_SetDrawPriority
	ldr r0, [r4, #0x2c]
	mov r1, #1
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [r4, #0x2c]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #1
	lsl r0, r0, #0x10
	add r7, r7, #1
	add r6, r6, r0
	add r4, r4, #4
	cmp r7, #3
	blt _02209926
	mov r0, #0x19
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	mov r2, #0xc0
	mov r3, #0xb8
	bl ov96_0220D13C
	str r0, [r5, #0x24]
	mov r7, #0
	add r4, r5, #0
	mov r6, #0xd4
_0220998A:
	mov r1, #0
	add r0, sp, #8
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [r5, #0xc]
	bl SpriteManager_GetSpriteList
	add r1, r0, #0
	ldr r0, [r5, #0x14]
	ldr r3, [r5]
	mov r2, #2
	bl ov96_021EA374
	str r0, [r4, #0x38]
	lsl r0, r6, #0xc
	str r0, [sp, #8]
	mov r0, #0x2e
	lsl r0, r0, #0xe
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x38]
	add r1, sp, #8
	bl Sprite_SetMatrix
	ldr r0, [r4, #0x38]
	mov r1, #1
	bl Sprite_SetDrawFlag
	add r7, r7, #1
	add r4, r4, #4
	add r6, #0x10
	cmp r7, #2
	blt _0220998A
	mov r0, #0x13
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	mov r2, #0x20
	mov r3, #0x10
	bl ov96_0220D13C
	str r0, [r5, #0x28]
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02209910


	thumb_func_start ov96_022099EC
ov96_022099EC: ; 0x022099EC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bne _022099F6
	bl GF_AssertFail
_022099F6:
	mov r4, #0
_022099F8:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	bne _02209A02
	bl GF_AssertFail
_02209A02:
	ldr r0, [r5, #0x24]
	bl Sprite_DeleteAndFreeResources
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _022099F8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_022099EC


	thumb_func_start ov96_02209A14
ov96_02209A14: ; 0x02209A14
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r0, #0
	ldr r5, [r6, #0xc]
	ldr r4, [r6, #8]
	mov r7, #1
	str r7, [sp]
	ldr r0, _02209AF8 ; =0x00002710
	str r7, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xea
	mov r3, #8
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _02209AF8 ; =0x00002710
	str r7, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xea
	mov r3, #7
	bl SpriteSystem_LoadPlttResObj
	add r0, r7, #0
	str r0, [sp]
	ldr r0, _02209AF8 ; =0x00002710
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xea
	mov r3, #9
	bl SpriteSystem_LoadCellResObj
	add r0, r7, #0
	str r0, [sp]
	ldr r0, _02209AF8 ; =0x00002710
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xea
	mov r3, #0xa
	bl SpriteSystem_LoadAnimResObj
	mov r0, #1
	str r0, [sp]
	mov r7, #2
	ldr r0, _02209AFC ; =0x00002711
	str r7, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xea
	mov r3, #0xc
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, _02209AFC ; =0x00002711
	str r7, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xea
	mov r3, #0xb
	bl SpriteSystem_LoadPlttResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _02209AFC ; =0x00002711
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xea
	mov r3, #0xd
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _02209AFC ; =0x00002711
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xea
	mov r3, #0xe
	bl SpriteSystem_LoadAnimResObj
	bl sub_02074490
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, _02209B00 ; =0x00002712
	str r7, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x14
	bl SpriteSystem_LoadPlttResObj
	mov r1, #0x85
	lsl r1, r1, #2
	strh r0, [r6, r1]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02209AF8: .word 0x00002710
_02209AFC: .word 0x00002711
_02209B00: .word 0x00002712
	thumb_func_end ov96_02209A14


	thumb_func_start ov96_02209B04
ov96_02209B04: ; 0x02209B04
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov r4, #1
	str r4, [sp]
	ldr r2, _02209BA4 ; =0x00002712
	str r4, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0xea
	mov r3, #0x10
	add r5, r0, #0
	add r6, r1, #0
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	add r0, r4, #0
	str r0, [sp, #4]
	ldr r0, _02209BA8 ; =0x00002713
	str r4, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #0xea
	mov r3, #0xf
	bl SpriteSystem_LoadPlttResObj
	mov r7, #2
	mov r4, #0
_02209B3C:
	mov r0, #1
	str r0, [sp]
	ldr r0, _02209BA8 ; =0x00002713
	str r7, [sp, #4]
	add r0, r4, r0
	str r0, [sp, #8]
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #0xea
	mov r3, #0x10
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _02209BAC ; =0x00002714
	str r7, [sp, #8]
	add r0, r4, r0
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #0xea
	mov r3, #0xf
	bl SpriteSystem_LoadPlttResObj
	add r4, r4, #1
	cmp r4, #2
	blt _02209B3C
	mov r0, #1
	str r0, [sp]
	ldr r0, _02209BA4 ; =0x00002712
	add r1, r6, #0
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #0xea
	mov r3, #0x11
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _02209BA4 ; =0x00002712
	add r1, r6, #0
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #0xea
	mov r3, #0x12
	bl SpriteSystem_LoadAnimResObj
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02209BA4: .word 0x00002712
_02209BA8: .word 0x00002713
_02209BAC: .word 0x00002714
	thumb_func_end ov96_02209B04


	thumb_func_start ov96_02209BB0
ov96_02209BB0: ; 0x02209BB0
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bne _02209BBA
	bl GF_AssertFail
_02209BBA:
	ldr r0, [r6, #0x40]
	bl ov96_0220AD4C
	add r5, r0, #0
	mov r4, #0
	mov r7, #2
_02209BC6:
	add r0, r5, #0
	mov r1, #0xa
	bl _s32_div_f
	sub r0, r7, r4
	lsl r0, r0, #2
	add r0, r6, r0
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	ldr r0, [r0, #0x2c]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	cmp r5, #0xa
	blo _02209BF6
	add r0, r5, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r0, #0x10
	add r4, r4, #1
	lsr r5, r0, #0x10
	cmp r4, #3
	blt _02209BC6
_02209BF6:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02209BB0


	thumb_func_start ov96_02209BF8
ov96_02209BF8: ; 0x02209BF8
	push {r4, r5, r6, lr}
	mov r4, #0
	add r5, r0, #0
	add r6, r4, #0
_02209C00:
	ldr r0, [r5, #0x24]
	add r1, r6, #0
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _02209C00
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_02209BF8


	thumb_func_start ov96_02209C14
ov96_02209C14: ; 0x02209C14
	push {r4, r5, r6, r7, lr}
	sub sp, #0xbc
	ldr r4, _02209C9C ; =ov96_0221CC0C
	add r3, sp, #4
	add r6, r0, #0
	str r1, [sp]
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _02209CA0 ; =ov96_0221CCF8
	add r3, sp, #0x14
	mov r2, #0x15
_02209C36:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02209C36
	ldr r5, _02209CA4 ; =ov96_0221CC48
	mov r7, #0
	add r4, sp, #0x14
_02209C44:
	ldr r1, [r5]
	add r0, r6, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r2, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldr r1, [r5]
	add r0, r6, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5]
	ldr r3, [sp]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	add r7, r7, #1
	add r4, #0x1c
	add r5, r5, #4
	cmp r7, #6
	blt _02209C44
	ldr r1, [sp]
	mov r0, #4
	bl FontID_Alloc
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add r0, r6, #0
	mov r1, #0
	mov r2, #3
	mov r3, #0x10
	bl BgSetPosTextAndCommit
	add sp, #0xbc
	pop {r4, r5, r6, r7, pc}
	nop
_02209C9C: .word ov96_0221CC0C
_02209CA0: .word ov96_0221CCF8
_02209CA4: .word ov96_0221CC48
	thumb_func_end ov96_02209C14


	thumb_func_start ov96_02209CA8
ov96_02209CA8: ; 0x02209CA8
	push {r4, r5, r6, lr}
	add r6, r0, #0
	mov r4, #0
	add r5, r6, #0
_02209CB0:
	ldr r0, [r5, #0x18]
	bl String_Delete
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _02209CB0
	mov r0, #0x97
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl MessageFormat_Delete
	mov r0, #0x96
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl DestroyMsgData
	mov r0, #0x86
	lsl r0, r0, #2
	mov r5, #0
	add r4, r6, r0
_02209CDA:
	add r0, r4, #0
	bl RemoveWindow
	add r5, r5, #1
	add r4, #0x10
	cmp r5, #4
	blt _02209CDA
	ldr r4, _02209D10 ; =ov96_0221CC48
	mov r5, #0
_02209CEC:
	ldr r1, [r4]
	ldr r0, [r6, #4]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl FreeBgTilemapBuffer
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #6
	blt _02209CEC
	mov r0, #4
	bl FontID_Release
	ldr r0, [r6, #4]
	bl Heap_Free
	pop {r4, r5, r6, pc}
	nop
_02209D10: .word ov96_0221CC48
	thumb_func_end ov96_02209CA8


	thumb_func_start ov96_02209D14
ov96_02209D14: ; 0x02209D14
	push {r4, lr}
	sub sp, #0x10
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, #1
	add r4, r0, #0
	str r1, [sp, #8]
	ldr r0, [r4]
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xea
	bl GfGfxLoader_LoadCharData
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #2
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xea
	bl GfGfxLoader_LoadScrnData
	mov r1, #0
	str r1, [sp]
	ldr r0, [r4]
	add r2, r1, #0
	str r0, [sp, #4]
	mov r0, #0xea
	add r3, r1, #0
	bl GfGfxLoader_GXLoadPal
	mov r1, #0x1e
	ldr r2, [r4]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #4
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xea
	add r3, r1, #0
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #4
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xea
	mov r3, #5
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #5
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xea
	mov r3, #4
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #6
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xea
	mov r3, #5
	bl GfGfxLoader_LoadScrnData
	mov r3, #0
	str r3, [sp]
	ldr r0, [r4]
	mov r1, #3
	str r0, [sp, #4]
	mov r0, #0xea
	mov r2, #4
	bl GfGfxLoader_GXLoadPal
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov96_02209D14


	thumb_func_start ov96_02209DE4
ov96_02209DE4: ; 0x02209DE4
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	ldr r2, _02209E68 ; =0x00000135
	ldr r3, [r6]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	mov r1, #0x96
	lsl r1, r1, #2
	str r0, [r6, r1]
	ldr r0, [r6]
	bl MessageFormat_New
	mov r1, #0x97
	lsl r1, r1, #2
	str r0, [r6, r1]
	sub r1, #0x44
	ldr r4, _02209E6C ; =ov96_0221CC60
	mov r7, #0
	add r5, r6, r1
_02209E14:
	ldr r0, [r6, #4]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	bl ClearWindowTilemap
	add r7, r7, #1
	add r4, #8
	add r5, #0x10
	cmp r7, #4
	blt _02209E14
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantUnk04
	add r5, r0, #0
	mov r7, #0
	add r4, r6, #0
_02209E4A:
	ldr r1, [r6]
	mov r0, #0xb
	bl String_New
	add r1, r5, #0
	add r1, #0x12
	str r0, [r4, #0x18]
	bl CopyU16ArrayToString
	add r7, r7, #1
	add r4, r4, #4
	add r5, #0x28
	cmp r7, #3
	blt _02209E4A
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02209E68: .word 0x00000135
_02209E6C: .word ov96_0221CC60
	thumb_func_end ov96_02209DE4


	thumb_func_start ov96_02209E70
ov96_02209E70: ; 0x02209E70
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	bne _02209E7C
	bl GF_AssertFail
_02209E7C:
	ldr r0, [r5, #0x4c]
	cmp r0, #0
	bne _02209E86
	bl GF_AssertFail
_02209E86:
	mov r0, #0x26
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x1e
	bl _s32_div_f
	cmp r0, #0
	bge _02209E98
	mov r0, #0
_02209E98:
	mov r1, #0x64
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r1, r0, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, #0x38]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, #0x3c]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [r5, #0x4c]
	bl ov96_0220B7B4
	add r0, r0, #1
	mov r1, #3
	bl _s32_div_f
	lsl r2, r1, #0x18
	mov r0, #1
	str r0, [sp]
	mov r3, #2
	mov r0, #0x97
	lsr r2, r2, #0x16
	str r3, [sp, #4]
	lsl r0, r0, #2
	add r2, r5, r2
	ldr r0, [r5, r0]
	ldr r2, [r2, #0x18]
	mov r1, #0
	bl BufferString
	mov r2, #0x92
	ldr r0, [r5]
	lsl r2, r2, #2
	add r1, r2, #0
	str r0, [sp]
	add r0, r5, r2
	add r1, #0x14
	add r2, #0x10
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	mov r3, #0x9a
	bl ov96_02209F40
	add sp, #8
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02209E70


	thumb_func_start ov96_02209F14
ov96_02209F14: ; 0x02209F14
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	mov r3, #0x86
	lsl r3, r3, #2
	ldr r0, [r4]
	add r1, r3, #0
	add r2, r3, #0
	str r0, [sp]
	add r1, #0x44
	add r2, #0x40
	add r0, r4, r3
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	sub r3, #0xeb
	bl ov96_02209F40
	add r0, r4, #0
	bl ov96_02209E70
	add sp, #4
	pop {r3, r4, pc}
	thumb_func_end ov96_02209F14


	thumb_func_start ov96_02209F40
ov96_02209F40: ; 0x02209F40
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	mov r1, #0
	add r5, r0, #0
	add r6, r2, #0
	add r7, r3, #0
	bl FillWindowPixelBuffer
	ldr r3, [sp, #0x28]
	add r0, r4, #0
	add r1, r6, #0
	add r2, r7, #0
	bl ReadMsgData_ExpandPlaceholders
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02209F88 ; =0x000F0E00
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add r0, r5, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02209F88: .word 0x000F0E00
	thumb_func_end ov96_02209F40


	thumb_func_start ov96_02209F8C
ov96_02209F8C: ; 0x02209F8C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	str r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r7, r0, #0
	bne _02209F9E
	bl GF_AssertFail
_02209F9E:
	ldr r0, [r7, #8]
	cmp r0, #0
	bne _02209FA8
	bl GF_AssertFail
_02209FA8:
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bne _02209FB2
	bl GF_AssertFail
_02209FB2:
	ldr r0, [r7, #0x44]
	cmp r0, #0
	bne _02209FBC
	bl GF_AssertFail
_02209FBC:
	mov r0, #0
	str r0, [sp, #0x1c]
	add r0, r7, #0
	str r0, [sp, #0x18]
	add r0, #0x54
	str r0, [sp, #0x18]
	mov r0, #0x78
	str r0, [sp, #0x14]
	ldr r0, _0220A0DC ; =ov96_0221CCC8
	str r0, [sp, #0x10]
_02209FD0:
	ldr r0, [sp, #0x14]
	mov r3, #0x98
	lsl r0, r0, #0x10
	asr r4, r0, #0x10
	ldr r0, [sp, #0x1c]
	add r2, r4, #0
	add r0, #0xd
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	bl ov96_0220D1A0
	ldr r1, [sp, #0x18]
	mov r2, #0
	str r0, [r1, #4]
	ldr r1, [sp, #0x1c]
	ldr r0, [sp, #8]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_0220A254
	mov r0, #0x12
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	add r2, r4, #0
	mov r3, #0x98
	bl ov96_0220D1A0
	ldr r1, [sp, #0x18]
	str r0, [r1, #8]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [sp, #0x14]
	mov r6, #0
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add r0, r0, #6
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	ldr r5, [sp, #0x18]
	add r4, r6, #0
	str r0, [sp, #0x20]
_0220A034:
	ldr r0, [sp, #0x10]
	mov r3, #0x88
	ldr r0, [r0, #8]
	sub r3, r3, r4
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #0x2c
	sub r0, r0, r6
	lsl r0, r0, #0x18
	lsl r3, r3, #0x10
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	asr r3, r3, #0x10
	sub r3, #0x14
	lsl r3, r3, #0x10
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	ldr r2, [sp, #0x20]
	asr r3, r3, #0x10
	bl ov96_0220D1A0
	mov r1, #0
	str r0, [r5, #0x5c]
	bl ManagedSprite_SetDrawFlag
	add r6, r6, #1
	add r4, #0x10
	add r5, r5, #4
	cmp r6, #5
	blt _0220A034
	ldr r0, [sp, #0x14]
	mov r5, #0
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	ldr r4, [sp, #0x18]
	str r0, [sp, #0xc]
	add r6, r5, #0
_0220A080:
	ldr r0, [sp, #0x10]
	mov r3, #0x88
	ldr r0, [r0, #4]
	sub r3, r3, r6
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #0x18
	sub r0, r0, r5
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	lsl r3, r3, #0x10
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	ldr r2, [sp, #0xc]
	asr r3, r3, #0x10
	bl ov96_0220D1A0
	mov r1, #0
	str r0, [r4, #0xc]
	bl ManagedSprite_SetDrawFlag
	add r5, r5, #1
	add r6, r6, #4
	add r4, r4, #4
	cmp r5, #0x14
	blt _0220A080
	ldr r0, [sp, #0x18]
	add r0, #0x70
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r0, #0x20
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, #0xc
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #4
	bge _0220A0D6
	b _02209FD0
_0220A0D6:
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_0220A0DC: .word ov96_0221CCC8
	thumb_func_end ov96_02209F8C


	thumb_func_start ov96_0220A0E0
ov96_0220A0E0: ; 0x0220A0E0
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r7, #0
	add r6, #0x54
_0220A0E8:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _0220A0F2
	bl GF_AssertFail
_0220A0F2:
	ldr r0, [r6, #4]
	bl Sprite_DeleteAndFreeResources
	ldr r0, [r6, #8]
	cmp r0, #0
	bne _0220A102
	bl GF_AssertFail
_0220A102:
	ldr r0, [r6, #8]
	bl Sprite_DeleteAndFreeResources
	mov r4, #0
	add r5, r6, #0
_0220A10C:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne _0220A116
	bl GF_AssertFail
_0220A116:
	ldr r0, [r5, #0xc]
	bl Sprite_DeleteAndFreeResources
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0x14
	blt _0220A10C
	mov r5, #0
	add r4, r6, #0
_0220A128:
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	bne _0220A132
	bl GF_AssertFail
_0220A132:
	ldr r0, [r4, #0x5c]
	bl Sprite_DeleteAndFreeResources
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #5
	blt _0220A128
	add r7, r7, #1
	add r6, #0x70
	cmp r7, #4
	blt _0220A0E8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220A0E0


	thumb_func_start ov96_0220A14C
ov96_0220A14C: ; 0x0220A14C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	cmp r0, #0
	bne _0220A15A
	bl GF_AssertFail
_0220A15A:
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r7, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	add r7, #0x54
_0220A176:
	ldr r0, [sp, #4]
	mov r1, #5
	ldr r0, [r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl _u32_div_f
	add r6, r0, #0
	cmp r6, #0x14
	ble _0220A1BE
	ldr r0, [r7, #0x5c]
	bl ManagedSprite_GetDrawFlag
	cmp r0, #0
	bne _0220A1BC
	mov r4, #0
	add r5, r7, #0
_0220A198:
	ldr r0, [r5, #0x5c]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #5
	blt _0220A198
	mov r5, #0
	add r4, r7, #0
_0220A1AC:
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #0x14
	blt _0220A1AC
_0220A1BC:
	sub r6, #0x14
_0220A1BE:
	cmp r6, #0x14
	ble _0220A1C4
	mov r6, #0x14
_0220A1C4:
	mov r4, #0
	cmp r6, #0
	ble _0220A1EC
	add r5, r7, #0
_0220A1CC:
	ldr r0, [r5, #0xc]
	bl ManagedSprite_GetDrawFlag
	cmp r0, #0
	bne _0220A1E4
	ldr r0, [r5, #0xc]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r0, [r5, #0xc]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
_0220A1E4:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r6
	blt _0220A1CC
_0220A1EC:
	ldr r0, [sp, #4]
	ldr r0, [r0]
	lsl r1, r0, #4
	lsr r1, r1, #0x1f
	beq _0220A22C
	lsl r0, r0, #6
	lsr r2, r0, #0x1e
	ldrb r0, [r7]
	cmp r2, r0
	beq _0220A21A
	ldr r1, [sp, #8]
	lsl r2, r2, #0x18
	lsl r1, r1, #0x18
	ldr r0, [sp]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_0220A254
	ldr r0, [sp, #4]
	ldr r0, [r0]
	lsl r0, r0, #6
	lsr r0, r0, #0x1e
	strb r0, [r7]
_0220A21A:
	ldr r0, [r7, #4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r7, #8]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	b _0220A23C
_0220A22C:
	ldr r0, [r7, #8]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r7, #4]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
_0220A23C:
	ldr r0, [sp, #4]
	add r7, #0x70
	add r0, r0, #4
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #4
	blt _0220A176
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220A14C


	thumb_func_start ov96_0220A254
ov96_0220A254: ; 0x0220A254
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r2, [sp, #8]
	add r7, r0, #0
	add r5, r1, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	add r4, r6, #0
	ldr r2, [sp, #8]
	add r0, r7, #0
	add r1, r5, #0
	add r3, sp, #0xc
	add r4, #0x50
	bl ov96_021E6168
	lsl r0, r5, #9
	str r0, [sp]
	ldr r0, [r6]
	mov r2, #0x71
	str r0, [sp, #4]
	mov r0, #0x70
	mul r0, r5
	lsl r2, r2, #2
	add r0, r4, r0
	ldrh r2, [r4, r2]
	ldr r0, [r0, #8]
	ldr r3, [r6, #0x50]
	add r1, sp, #0xc
	bl ov96_021EECB8
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220A254


	thumb_func_start ov96_0220A298
ov96_0220A298: ; 0x0220A298
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x4c]
	add r6, r1, #0
	bl ov96_0220B730
	mov r4, #0x99
	lsl r4, r4, #2
	bl System_GetTouchNew
	cmp r0, #0
	beq _0220A322
	add r0, sp, #0xc
	add r1, sp, #8
	bl System_GetTouchNewCoords
	mov r1, #0
	ldr r0, [sp, #0xc]
	add r2, r1, #0
	add r3, r1, #0
	cmp r0, #0x60
	blo _0220A2CC
	cmp r0, #0xb0
	bhi _0220A2CC
	mov r3, #1
_0220A2CC:
	cmp r3, #0
	beq _0220A2D8
	ldr r0, [sp, #8]
	cmp r0, #0x48
	blo _0220A2D8
	mov r2, #1
_0220A2D8:
	cmp r2, #0
	beq _0220A2E4
	ldr r0, [sp, #8]
	cmp r0, #0x98
	bhi _0220A2E4
	mov r1, #1
_0220A2E4:
	cmp r6, #0
	bne _0220A2EC
	cmp r1, #0
	beq _0220A3A2
_0220A2EC:
	ldr r1, [r5, r4]
	ldr r0, _0220A40C ; =0xFFFF00FF
	and r1, r0
	ldr r0, [sp, #8]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x10
	orr r0, r1
	str r0, [r5, r4]
	ldr r1, [r5, r4]
	ldr r0, _0220A410 ; =0xFF00FFFF
	and r1, r0
	ldr r0, [sp, #8]
	lsl r0, r0, #0x18
	lsr r0, r0, #8
	orr r0, r1
	str r0, [r5, r4]
	ldr r1, [r5, r4]
	mov r0, #0xff
	bic r1, r0
	mov r0, #1
	orr r1, r0
	str r1, [r5, r4]
	ldr r1, [r5, r4]
	lsl r0, r0, #0x18
	orr r0, r1
	str r0, [r5, r4]
	b _0220A3A2
_0220A322:
	ldr r0, [r5, r4]
	lsl r0, r0, #7
	lsr r0, r0, #0x1f
	beq _0220A35C
	bl System_GetTouchHeld
	cmp r0, #0
	bne _0220A35C
	ldr r0, [r5, r4]
	lsl r1, r0, #0x10
	lsl r0, r0, #8
	lsr r1, r1, #0x18
	lsr r0, r0, #0x18
	sub r0, r1, r0
	cmp r0, #0x20
	blt _0220A352
	ldr r0, [r5, #0x4c]
	bl ov96_0220B744
	cmp r0, #0
	beq _0220A352
	ldr r0, [r5, #0x4c]
	bl ov96_0220B6EC
_0220A352:
	ldr r1, [r5, r4]
	ldr r0, _0220A414 ; =0xFEFFFFFF
	and r0, r1
	str r0, [r5, r4]
	b _0220A3A2
_0220A35C:
	ldr r0, [r5, r4]
	lsl r0, r0, #7
	lsr r0, r0, #0x1f
	beq _0220A3A2
	add r0, sp, #4
	add r1, sp, #0
	bl System_GetTouchHeldCoords
	ldr r1, [r5, r4]
	ldr r0, _0220A410 ; =0xFF00FFFF
	and r1, r0
	ldr r0, [sp]
	lsl r0, r0, #0x18
	lsr r0, r0, #8
	orr r0, r1
	str r0, [r5, r4]
	ldr r2, [r5, r4]
	mov r1, #0xff
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	orr r0, r1
	str r0, [r5, r4]
	ldr r1, [r5, r4]
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	cmp r0, #0xa
	blo _0220A3A2
	ldr r0, _0220A414 ; =0xFEFFFFFF
	and r0, r1
	str r0, [r5, r4]
_0220A3A2:
	bl System_GetTouchNew
	cmp r0, #0
	bne _0220A3B2
	bl System_GetTouchHeld
	cmp r0, #0
	bgt _0220A408
_0220A3B2:
	ldr r0, _0220A418 ; =ov96_0221CC04
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	ldr r0, [r5, #0x4c]
	beq _0220A3E4
	bl ov96_0220B744
	cmp r0, #0
	beq _0220A3DA
	ldr r0, _0220A41C ; =0x0000089B
	mov r4, #0x14
	bl PlaySE
	ldr r0, [r5, #0x4c]
	bl ov96_0220B6EC
	b _0220A400
_0220A3DA:
	ldr r0, _0220A420 ; =0x0000089C
	mov r4, #0x16
	bl PlaySE
	b _0220A400
_0220A3E4:
	bl ov96_0220B744
	cmp r0, #0
	bne _0220A3F0
	mov r4, #0x15
	b _0220A400
_0220A3F0:
	ldr r0, [r5, #0x4c]
	bl ov96_0220B788
	cmp r0, #0
	beq _0220A3FE
	mov r4, #0x17
	b _0220A400
_0220A3FE:
	mov r4, #0x13
_0220A400:
	ldr r0, [r5, #0x28]
	add r1, r4, #0
	bl ManagedSprite_SetAnimNoRestart
_0220A408:
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0220A40C: .word 0xFFFF00FF
_0220A410: .word 0xFF00FFFF
_0220A414: .word 0xFEFFFFFF
_0220A418: .word ov96_0221CC04
_0220A41C: .word 0x0000089B
_0220A420: .word 0x0000089C
	thumb_func_end ov96_0220A298


	thumb_func_start ov96_0220A424
ov96_0220A424: ; 0x0220A424
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetDataCopyArea
	bl ov96_021E8A20
	add r5, r0, #0
	ldr r0, [r4, #0x4c]
	bl ov96_0220B758
	add r6, r0, #0
	ldr r0, [r4, #0x4c]
	bl ov96_0220B730
	add r7, r0, #0
	ldr r0, [r4, #0x40]
	bl ov96_0220AD4C
	lsl r0, r0, #0x18
	ldr r1, [r5]
	mov r2, #0xff
	bic r1, r2
	lsr r0, r0, #0x18
	orr r1, r0
	ldr r0, _0220A4C8 ; =0xFFFF00FF
	str r1, [r5]
	and r0, r1
	ldr r1, [r6]
	lsl r1, r1, #6
	lsr r1, r1, #0x18
	lsl r1, r1, #0x18
	lsr r1, r1, #0x10
	orr r0, r1
	str r0, [r5]
	ldr r0, [r4, #0x4c]
	bl ov96_0220B79C
	lsl r0, r0, #0x18
	ldr r2, [r5]
	ldr r1, _0220A4CC ; =0xFF00FFFF
	lsr r0, r0, #8
	and r1, r2
	orr r0, r1
	str r0, [r5]
	ldr r0, [r4, #0x4c]
	bl ov96_0220B774
	lsl r0, r0, #0x1f
	ldr r2, [r5]
	ldr r1, _0220A4D0 ; =0xFBFFFFFF
	lsr r0, r0, #5
	and r1, r2
	orr r0, r1
	str r0, [r5]
	cmp r7, #3
	bne _0220A4A0
	mov r2, #1
	b _0220A4A2
_0220A4A0:
	mov r2, #0
_0220A4A2:
	ldr r1, [r5]
	ldr r0, _0220A4D4 ; =0xEFFFFFFF
	and r1, r0
	lsl r0, r2, #0x1f
	lsr r0, r0, #3
	orr r0, r1
	str r0, [r5]
	ldr r0, [r4, #0x4c]
	bl ov96_0220B7B4
	lsl r0, r0, #0x1e
	ldr r2, [r5]
	ldr r1, _0220A4D8 ; =0xFCFFFFFF
	lsr r0, r0, #6
	and r1, r2
	orr r0, r1
	str r0, [r5]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220A4C8: .word 0xFFFF00FF
_0220A4CC: .word 0xFF00FFFF
_0220A4D0: .word 0xFBFFFFFF
_0220A4D4: .word 0xEFFFFFFF
_0220A4D8: .word 0xFCFFFFFF
	thumb_func_end ov96_0220A424


	thumb_func_start ov96_0220A4DC
ov96_0220A4DC: ; 0x0220A4DC
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	bl ov96_021E5F24
	add r6, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r5, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r4, r0, #0
	cmp r5, #0
	bne _0220A4FE
	bl GF_AssertFail
_0220A4FE:
	ldr r0, [r5, #0x4c]
	cmp r0, #0
	bne _0220A508
	bl GF_AssertFail
_0220A508:
	ldr r0, [r5, #0x40]
	cmp r0, #0
	bne _0220A512
	bl GF_AssertFail
_0220A512:
	cmp r6, #0
	bne _0220A5C0
	add r0, r4, #0
	add r0, #0x28
	bl ov96_021E8A20
	add r5, r0, #0
	add r0, r4, #0
	add r0, #0x50
	bl ov96_021E8A20
	add r6, r0, #0
	add r0, r4, #0
	bl ov96_021E8A20
	add r3, r0, #0
	mov r2, #4
_0220A534:
	ldmia r3!, {r0, r1}
	stmia r6!, {r0, r1}
	sub r2, r2, #1
	bne _0220A534
	ldr r0, [r3]
	add r4, #0x50
	str r0, [r6]
	mov r6, #0
	mov r7, #0xff
_0220A546:
	add r0, r4, #0
	bl ov96_021E8A20
	ldr r2, [r0]
	ldr r1, [r5]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	lsl r2, r2, #0x18
	bic r1, r7
	lsr r2, r2, #0x18
	orr r2, r1
	ldr r1, _0220A5C8 ; =0xFFFF00FF
	str r2, [r5]
	and r1, r2
	ldr r2, [r0]
	add r6, r6, #1
	lsl r2, r2, #0x10
	lsr r2, r2, #0x18
	lsl r2, r2, #0x18
	lsr r2, r2, #0x10
	orr r2, r1
	ldr r1, _0220A5CC ; =0xFF00FFFF
	str r2, [r5]
	and r1, r2
	ldr r2, [r0]
	add r4, #0x28
	lsl r2, r2, #8
	lsr r2, r2, #0x18
	lsl r2, r2, #0x18
	lsr r2, r2, #8
	orr r2, r1
	ldr r1, _0220A5D0 ; =0xFCFFFFFF
	str r2, [r5]
	and r1, r2
	ldr r2, [r0]
	lsl r2, r2, #6
	lsr r2, r2, #0x1e
	lsl r2, r2, #0x1e
	lsr r2, r2, #6
	orr r2, r1
	ldr r1, _0220A5D4 ; =0xFBFFFFFF
	str r2, [r5]
	and r1, r2
	ldr r2, [r0]
	lsl r2, r2, #5
	lsr r2, r2, #0x1f
	lsl r2, r2, #0x1f
	lsr r2, r2, #5
	orr r2, r1
	str r2, [r5]
	ldr r0, [r0]
	ldr r1, _0220A5D8 ; =0xF7FFFFFF
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	lsl r0, r0, #0x1f
	and r1, r2
	lsr r0, r0, #4
	orr r0, r1
	stmia r5!, {r0}
	cmp r6, #4
	blt _0220A546
_0220A5C0:
	ldr r0, [sp]
	bl ov96_0220A424
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220A5C8: .word 0xFFFF00FF
_0220A5CC: .word 0xFF00FFFF
_0220A5D0: .word 0xFCFFFFFF
_0220A5D4: .word 0xFBFFFFFF
_0220A5D8: .word 0xF7FFFFFF
	thumb_func_end ov96_0220A4DC


	thumb_func_start ov96_0220A5DC
ov96_0220A5DC: ; 0x0220A5DC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r0, [sp, #0x10]
	add r5, r1, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	mov r0, #0x97
	lsl r0, r0, #2
	ldr r6, [r4, r0]
	sub r0, r0, #4
	ldr r7, [r4, r0]
	lsl r1, r5, #0x10
	ldr r0, [sp, #0x10]
	lsr r1, r1, #0x10
	bl ov96_021E8318
	mov r0, #0x8e
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r6, #0
	add r2, r5, #0
	mov r3, #3
	bl BufferIntegerAsString
	ldr r3, [r4]
	add r0, r6, #0
	add r1, r7, #0
	mov r2, #0x9f
	bl ReadMsgData_ExpandPlaceholders
	add r5, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0220A65C ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	mov r0, #0x8e
	lsl r0, r0, #2
	add r0, r4, r0
	add r2, r5, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl String_Delete
	mov r0, #0x8e
	lsl r0, r0, #2
	add r0, r4, r0
	bl CopyWindowToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_0220A65C: .word 0x000F0E00
	thumb_func_end ov96_0220A5DC


	thumb_func_start ov96_0220A660
ov96_0220A660: ; 0x0220A660
	push {r4, r5, r6, lr}
	add r6, r0, #0
	ldr r0, _0220A700 ; =0x0000026E
	add r5, r1, #0
	ldrb r0, [r5, r0]
	cmp r0, #0
	beq _0220A672
	mov r1, #1
	b _0220A676
_0220A672:
	mov r1, #0
	mvn r1, r1
_0220A676:
	mov r0, #0x9b
	lsl r0, r0, #2
	ldrsb r0, [r5, r0]
	mov r2, #3
	add r4, r0, #0
	mul r4, r1
	ldr r0, [r5, #4]
	mov r1, #0
	add r3, r4, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #4]
	mov r1, #1
	mov r2, #3
	add r3, r4, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #8]
	bl SpriteSystem_GetRenderer
	neg r2, r4
	mov r1, #0
	lsl r2, r2, #0xc
	bl G2dRenderer_SetMainSurfaceCoords
	mov r1, #0x9b
	lsl r1, r1, #2
	add r0, r1, #1
	ldrsb r2, [r5, r1]
	ldrb r0, [r5, r0]
	sub r0, r2, r0
	strb r0, [r5, r1]
	add r0, r1, #2
	ldrb r2, [r5, r0]
	mov r0, #1
	eor r2, r0
	add r0, r1, #2
	strb r2, [r5, r0]
	ldrsb r0, [r5, r1]
	cmp r0, #0
	bgt _0220A6FC
	ldr r0, [r5, #4]
	mov r1, #0
	mov r2, #3
	mov r3, #0x10
	bl ScheduleSetBgPosText
	ldr r0, [r5, #4]
	mov r1, #1
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #8]
	bl SpriteSystem_GetRenderer
	mov r1, #0
	add r2, r1, #0
	bl G2dRenderer_SetMainSurfaceCoords
	mov r0, #0x9a
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r5, r0]
	add r0, r6, #0
	bl SysTask_Destroy
_0220A6FC:
	pop {r4, r5, r6, pc}
	nop
_0220A700: .word 0x0000026E
	thumb_func_end ov96_0220A660


	thumb_func_start ov96_0220A704
ov96_0220A704: ; 0x0220A704
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r4, r1, #0
	add r6, r2, #0
	cmp r0, #0
	beq _0220A71A
	bl SysTask_Destroy
_0220A71A:
	ldr r0, _0220A73C ; =0x0000026E
	mov r1, #0
	strb r1, [r5, r0]
	sub r1, r0, #2
	strb r4, [r5, r1]
	sub r0, r0, #1
	strb r6, [r5, r0]
	ldr r0, _0220A740 ; =ov96_0220A660
	add r1, r5, #0
	mov r2, #2
	bl SysTask_CreateOnMainQueue
	mov r1, #0x9a
	lsl r1, r1, #2
	str r0, [r5, r1]
	pop {r4, r5, r6, pc}
	nop
_0220A73C: .word 0x0000026E
_0220A740: .word ov96_0220A660
	thumb_func_end ov96_0220A704


	thumb_func_start ov96_0220A744
ov96_0220A744: ; 0x0220A744
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r1, #0
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [sp, #8]
	add r7, r2, #0
	add r4, r3, #0
	bl Heap_Alloc
	mov r2, #0x61
	str r0, [sp, #0xc]
	mov r1, #0
	lsl r2, r2, #2
	bl MI_CpuFill8
	mov r0, #6
	ldr r1, [sp, #0xc]
	lsl r0, r0, #6
	ldr r2, [r1, r0]
	mov r1, #0xf
	bic r2, r1
	add r3, r2, #0
	mov r1, #1
	ldr r2, [sp, #0xc]
	orr r3, r1
	str r3, [r2, r0]
	ldr r2, [r2, r0]
	mov r3, #0xf0
	bic r2, r3
	ldr r3, [sp, #0xc]
	str r2, [r3, r0]
	add r0, r3, #0
	str r6, [r0, #4]
	str r7, [r0, #8]
	str r4, [r0]
	mov r0, #7
	str r0, [sp]
	mov r2, #0
	str r1, [sp, #4]
	add r0, r6, #0
	add r1, r7, #0
	add r3, r2, #0
	bl ov96_0220D13C
	ldr r1, [sp, #0xc]
	str r0, [r1, #0xc]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x12
	str r0, [sp]
	mov r0, #1
	mov r2, #0
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r7, #0
	add r3, r2, #0
	bl ov96_0220D13C
	ldr r1, [sp, #0xc]
	str r0, [r1, #0x10]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r5, [sp, #0xc]
	mov r4, #0
_0220A7CA:
	lsl r3, r4, #0x10
	ldr r0, [sp, #8]
	add r1, r6, #0
	add r2, r7, #0
	lsr r3, r3, #0x10
	bl ov96_0220AE40
	mov r1, #0x55
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0xa
	blt _0220A7CA
	ldr r0, [sp, #0xc]
	add r1, r6, #0
	add r0, #0x14
	add r2, r7, #0
	bl ov96_0220B178
	ldr r0, [sp, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220A744


	thumb_func_start ov96_0220A7F8
ov96_0220A7F8: ; 0x0220A7F8
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bne _0220A802
	bl GF_AssertFail
_0220A802:
	ldr r0, [r6, #0xc]
	cmp r0, #0
	bne _0220A80C
	bl GF_AssertFail
_0220A80C:
	ldr r0, [r6, #0xc]
	bl Sprite_DeleteAndFreeResources
	ldr r0, [r6, #0x10]
	bl Sprite_DeleteAndFreeResources
	mov r7, #0x55
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_0220A820:
	ldr r0, [r5, r7]
	bl ov96_0220AF30
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0xa
	blt _0220A820
	add r0, r6, #0
	add r0, #0x14
	bl ov96_0220B1B8
	add r0, r6, #0
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220A7F8


	thumb_func_start ov96_0220A840
ov96_0220A840: ; 0x0220A840
	push {r4, lr}
	add r4, r0, #0
	bne _0220A84A
	bl GF_AssertFail
_0220A84A:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	cmp r0, #1
	beq _0220A85E
	cmp r0, #2
	beq _0220A866
	b _0220A86E
_0220A85E:
	add r0, r4, #0
	bl ov96_0220AD64
	b _0220A872
_0220A866:
	add r0, r4, #0
	bl ov96_0220AE28
	b _0220A872
_0220A86E:
	bl GF_AssertFail
_0220A872:
	add r4, #0x14
	add r0, r4, #0
	bl ov96_0220B324
	pop {r4, pc}
	thumb_func_end ov96_0220A840


	thumb_func_start ov96_0220A87C
ov96_0220A87C: ; 0x0220A87C
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	ldr r0, [r0, #0x10]
	mov r1, #0
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [sp]
	mov r1, #0
	ldr r0, [r0, #0xc]
	bl ManagedSprite_SetAnimateFlag
	mov r7, #0x55
	lsl r7, r7, #2
	ldr r5, [sp]
	mov r4, #0
	add r6, r7, #0
_0220A89C:
	ldr r0, [r5, r6]
	ldr r1, [r0, #0x10]
	lsl r1, r1, #4
	lsr r1, r1, #0x1f
	beq _0220A8B8
	ldr r0, [r0]
	mov r1, #0
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [r5, r7]
	mov r1, #0
	ldr r0, [r0, #4]
	bl ManagedSprite_SetAnimateFlag
_0220A8B8:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0xa
	blt _0220A89C
	ldr r0, [sp]
	add r0, #0x14
	str r0, [sp]
	bl ov96_0220B354
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220A87C


	thumb_func_start ov96_0220A8CC
ov96_0220A8CC: ; 0x0220A8CC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	cmp r5, #0
	bne _0220A8DA
	bl GF_AssertFail
_0220A8DA:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	bne _0220A8EA
	bl GF_AssertFail
_0220A8EA:
	mov r0, #6
	lsl r0, r0, #6
	ldr r1, [r5, r0]
	sub r0, #0x30
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	lsl r1, r1, #2
	add r1, r5, r1
	ldr r0, [r1, r0]
	add r1, r4, #0
	bl ov96_0220B0A4
	cmp r0, #0
	beq _0220A90A
	mov r0, #1
	pop {r3, r4, r5, pc}
_0220A90A:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_0220A8CC


	thumb_func_start ov96_0220A910
ov96_0220A910: ; 0x0220A910
	push {r4, r5, r6, r7, lr}
	sub sp, #0x4c
	add r4, r0, #0
	bne _0220A91C
	bl GF_AssertFail
_0220A91C:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	lsl r1, r0, #0x1c
	lsr r1, r1, #0x1c
	cmp r1, #1
	bne _0220A930
	add sp, #0x4c
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_0220A930:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	bne _0220A93A
	bl GF_AssertFail
_0220A93A:
	mov r0, #6
	lsl r0, r0, #6
	ldr r1, [r4, r0]
	sub r0, #0x30
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, sp, #0x10
	add r1, #2
	add r2, sp, #0x10
	bl ov96_0220B148
	add r0, sp, #0x18
	add r1, sp, #0x14
	bl System_GetTouchNewCoords
	add r1, sp, #0x10
	mov r0, #0
	ldrsh r0, [r1, r0]
	str r0, [sp]
	ldr r0, [sp]
	ldr r4, [sp, #0x14]
	sub r0, #0x12
	cmp r4, r0
	blo _0220A978
	ldr r0, [sp]
	add r0, #0xc
	cmp r4, r0
	bls _0220A97A
_0220A978:
	b _0220AAE2
_0220A97A:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _0220A992
	lsl r0, r0, #0xc
	bl _ffltu
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0220A9A0
_0220A992:
	lsl r0, r0, #0xc
	bl _ffltu
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0220A9A0:
	bl _ffix
	str r0, [sp, #0xc]
	cmp r4, #0
	beq _0220A9BC
	lsl r0, r4, #0xc
	bl _ffltu
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0220A9CA
_0220A9BC:
	lsl r0, r4, #0xc
	bl _ffltu
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0220A9CA:
	bl _ffix
	str r0, [sp, #8]
	mov r6, #0x3f
	add r1, sp, #0x10
	mov r0, #2
	ldrsh r0, [r1, r0]
	ldr r4, _0220AAE8 ; =ov96_0221CDD8
	mov r7, #0
	add r5, sp, #0x1c
	str r0, [sp, #4]
	lsl r6, r6, #0x18
_0220A9E2:
	mov r0, #0
	ldrsh r1, [r4, r0]
	ldr r0, [sp, #4]
	add r0, r0, r1
	cmp r0, #0
	ble _0220A9FE
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r6, #0
	bl _fadd
	b _0220AA0A
_0220A9FE:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r6, #0
	bl _fsub
_0220AA0A:
	bl _ffix
	str r0, [r5]
	mov r0, #2
	ldrsh r1, [r4, r0]
	ldr r0, [sp]
	add r0, r0, r1
	cmp r0, #0
	ble _0220AA2C
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r6, #0
	bl _fadd
	b _0220AA38
_0220AA2C:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r6, #0
	bl _fsub
_0220AA38:
	bl _ffix
	str r0, [r5, #4]
	add r7, r7, #1
	add r4, r4, #4
	add r5, #0xc
	cmp r7, #4
	blt _0220A9E2
	ldr r4, [sp, #0x1c]
	ldr r2, [sp, #0xc]
	ldr r1, [sp, #0x2c]
	ldr r0, [sp, #0x20]
	sub r2, r2, r4
	sub r0, r1, r0
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r0, r0, r2
	adc r1, r3
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	ldr r1, [sp, #0x28]
	sub r1, r1, r4
	bl FX_Div
	ldr r1, [sp, #0x20]
	ldr r5, [sp, #0x34]
	add r4, r0, r1
	ldr r2, [sp, #0xc]
	ldr r1, [sp, #0x44]
	ldr r0, [sp, #0x38]
	sub r2, r2, r5
	sub r0, r1, r0
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r0, r0, r2
	adc r1, r3
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	ldr r1, [sp, #0x40]
	sub r1, r1, r5
	bl FX_Div
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0xc]
	add r0, r0, r1
	ldr r1, [sp, #0x28]
	cmp r2, r1
	blt _0220AAB6
	ldr r3, [sp, #0x34]
	cmp r2, r3
	ble _0220AADC
_0220AAB6:
	ldr r2, [sp, #8]
	cmp r2, r4
	blt _0220AAC8
	ldr r3, [sp, #0x1c]
	ldr r2, [sp, #0xc]
	cmp r2, r3
	blt _0220AAC8
	cmp r2, r1
	ble _0220AADC
_0220AAC8:
	ldr r1, [sp, #8]
	cmp r1, r0
	bgt _0220AAE2
	ldr r1, [sp, #0x34]
	ldr r0, [sp, #0xc]
	cmp r0, r1
	blt _0220AAE2
	ldr r1, [sp, #0x40]
	cmp r0, r1
	bgt _0220AAE2
_0220AADC:
	add sp, #0x4c
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0220AAE2:
	mov r0, #0
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0220AAE8: .word ov96_0221CDD8
	thumb_func_end ov96_0220A910


	thumb_func_start ov96_0220AAEC
ov96_0220AAEC: ; 0x0220AAEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	mov r0, #0
	str r1, [sp, #4]
	add r6, r2, #0
	add r4, r3, #0
	str r0, [sp, #8]
	cmp r5, #0
	bne _0220AB04
	bl GF_AssertFail
_0220AB04:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	bne _0220AB16
	add sp, #0x24
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_0220AB16:
	add r0, sp, #0x20
	add r1, sp, #0x1c
	bl System_GetTouchNewCoords
	ldr r1, [sp, #0x20]
	ldr r2, [sp, #0x1c]
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r5, #0xc]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	mov r7, #7
	bl ManagedSprite_SetPositionXY
	cmp r4, #0
	bne _0220AB3C
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _0220AB3E
_0220AB3C:
	mov r7, #0x12
_0220AB3E:
	ldr r0, [r5, #0xc]
	add r1, r7, #0
	bl ManagedSprite_SetAnim
	ldr r0, [r5, #0xc]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _0220AB62
	add r6, #0x96
	lsl r0, r6, #0x10
	asr r6, r0, #0x10
	ldr r0, _0220AD24 ; =0x000008BB
	bl PlaySE
	b _0220AB72
_0220AB62:
	cmp r4, #0
	beq _0220AB72
	add r6, #0xa0
	lsl r0, r6, #0x10
	asr r6, r0, #0x10
	ldr r0, _0220AD24 ; =0x000008BB
	bl PlaySE
_0220AB72:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r7, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	str r0, [sp, #0xc]
	cmp r0, #0
	ble _0220AC6A
	add r0, r5, #0
	str r0, [sp, #0x10]
	add r0, #0x14
	str r0, [sp, #0x10]
	mov r0, #0xf0
	str r0, [sp, #0x14]
_0220AB90:
	ldr r0, [sp, #0xc]
	add r1, r7, #1
	sub r0, r0, r1
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r4, [r1, r0]
	cmp r6, #0
	ble _0220AC6A
	mov r0, #8
	ldrsh r0, [r4, r0]
	sub r0, r0, r6
	strh r0, [r4, #8]
	mov r0, #8
	ldrsh r0, [r4, r0]
	cmp r0, #0
	bgt _0220AC6A
	bgt _0220AC62
	mov r0, #6
	lsl r0, r0, #6
	ldr r2, [r5, r0]
	ldr r1, [sp, #0x14]
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x1c
	sub r1, r1, #1
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x18
	orr r1, r0
	mov r0, #6
	lsl r0, r0, #6
	str r1, [r5, r0]
	sub r0, r0, #4
	ldr r1, [r5, r0]
	lsl r0, r1, #0x10
	lsr r1, r1, #0x10
	add r1, r1, #1
	lsr r0, r0, #0x10
	lsl r1, r1, #0x10
	orr r1, r0
	mov r0, #0x5f
	lsl r0, r0, #2
	str r1, [r5, r0]
	ldr r0, [r5, r0]
	lsr r0, r0, #0x10
	cmp r0, #0xc8
	bls _0220AC08
	mov r0, #0x5f
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	mov r0, #0x32
	lsl r0, r0, #0x12
	orr r1, r0
	mov r0, #0x5f
	lsl r0, r0, #2
	str r1, [r5, r0]
_0220AC08:
	ldr r0, [r4]
	mov r1, #0
	bl ManagedSprite_SetAnim
	add r1, sp, #0x18
	ldr r0, [r4]
	add r1, #2
	add r2, sp, #0x18
	bl ManagedSprite_GetPositionXY
	ldr r0, [r4, #4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #8
	ldrsh r0, [r4, r0]
	add r3, sp, #0x18
	mov r2, #2
	neg r0, r0
	lsl r0, r0, #0x10
	asr r6, r0, #0x10
	ldr r0, [sp, #8]
	ldrsh r2, [r3, r2]
	add r4, r3, #0
	mov r3, #0
	add r0, r0, #1
	str r0, [sp, #8]
	ldrsh r3, [r4, r3]
	ldr r0, [sp, #0x10]
	mov r1, #4
	bl ov96_0220B1D8
	ldr r0, [r5]
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldr r0, [r5]
	ldr r2, [sp, #4]
	lsr r1, r1, #0x18
	mov r3, #3
	bl ov96_021E8228
_0220AC62:
	ldr r0, [sp, #0xc]
	add r7, r7, #1
	cmp r7, r0
	blt _0220AB90
_0220AC6A:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _0220AC78
	ldr r0, _0220AD28 ; =0x000008B9
	bl PlaySE
	b _0220ACA0
_0220AC78:
	ldr r0, _0220AD2C ; =0x000008B8
	bl PlaySE
	ldr r1, [sp, #0x20]
	ldr r2, [sp, #0x1c]
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r5, #0x10]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	ldr r0, [r5, #0x10]
	mov r1, #6
	bl ManagedSprite_SetAnim
	ldr r0, [r5, #0x10]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
_0220ACA0:
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _0220ACFC
	mov r0, #6
	lsl r0, r0, #6
	ldr r1, [r5, r0]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	beq _0220ACFC
	lsl r1, r1, #2
	add r1, r5, r1
	sub r0, #0x30
	ldr r1, [r1, r0]
	mov r0, #8
	ldrsh r0, [r1, r0]
	cmp r0, #0x14
	bgt _0220ACCC
	ldr r0, [r1]
	mov r1, #3
	bl ManagedSprite_SetAnim
	b _0220ACFC
_0220ACCC:
	cmp r0, #0x3c
	bgt _0220ACFC
	ldr r0, [r1]
	mov r1, #2
	bl ManagedSprite_SetAnim
	ldr r0, _0220AD2C ; =0x000008B8
	bl PlaySE
	bl LCRandom
	add r2, r0, #0
	lsr r4, r2, #0x1f
	lsl r3, r2, #0x19
	sub r3, r3, r4
	mov r2, #0x19
	ror r3, r2
	ldr r0, _0220AD2C ; =0x000008B8
	ldr r1, _0220AD30 ; =0x0000FFFF
	add r3, r4, r3
	mov r2, #0x40
	sub r2, r2, r3
	bl sub_0200592C
_0220ACFC:
	ldr r0, [sp, #8]
	cmp r0, #0
	ble _0220AD12
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	bne _0220AD12
	mov r1, #1
	b _0220AD14
_0220AD12:
	mov r1, #0
_0220AD14:
	ldr r0, [sp, #0x3c]
	str r1, [r0]
	ldr r0, [sp, #8]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_0220AD24: .word 0x000008BB
_0220AD28: .word 0x000008B9
_0220AD2C: .word 0x000008B8
_0220AD30: .word 0x0000FFFF
	thumb_func_end ov96_0220AAEC


	thumb_func_start ov96_0220AD34
ov96_0220AD34: ; 0x0220AD34
	push {r4, lr}
	add r4, r0, #0
	bne _0220AD3E
	bl GF_AssertFail
_0220AD3E:
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220AD34

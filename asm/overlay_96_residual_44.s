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

	thumb_func_start ov96_021EEA88
ov96_021EEA88: ; 0x021EEA88
	push {r3, lr}
	ldr r0, [r0]
	bl ov96_021EEA94
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov96_021EEA88


	thumb_func_start ov96_021EEA94
ov96_021EEA94: ; 0x021EEA94
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r1, #0
	str r3, [sp, #0xc]
	mov r1, #0
	add r6, r0, #0
	add r4, r2, #0
	bl thunk_Sprite_SetDrawFlag
	ldr r1, [sp, #0xc]
	mov r0, #0x51
	bl NARC_New
	ldr r2, [sp, #0xc]
	add r1, r5, #0
	str r0, [sp, #0x14]
	bl NARC_AllocAndReadWholeMember
	str r0, [sp, #0x10]
	bl NNS_G3dGetTex
	add r5, r0, #0
	beq _021EEAE8
	add r0, #0x3c
	beq _021EEAE4
	add r1, r5, #0
	add r1, #0x3d
	ldrb r1, [r1]
	cmp r4, r1
	bhs _021EEAE4
	add r1, r5, #0
	add r1, #0x42
	ldrh r1, [r1]
	add r2, r0, r1
	ldrh r0, [r0, r1]
	add r2, r2, #4
	add r1, r0, #0
	mul r1, r4
	add r0, r2, r1
	b _021EEAEA
_021EEAE4:
	mov r0, #0
	b _021EEAEA
_021EEAE8:
	mov r0, #0
_021EEAEA:
	ldr r0, [r0]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r4, r0, #0xd
	ldr r0, [r5, #0x14]
	lsl r1, r1, #8
	add r7, r5, r0
	ldr r0, [sp, #0xc]
	bl Heap_AllocAtEnd
	mov r1, #4
	str r1, [sp]
	str r1, [sp, #4]
	mov r2, #0
	str r0, [sp, #0x18]
	str r0, [sp, #8]
	add r0, r7, r4
	add r3, r2, #0
	bl sub_020145B4
	mov r2, #2
	ldr r1, [sp, #0x18]
	add r0, r6, #0
	lsl r2, r2, #8
	bl ov96_021EED64
	ldr r0, [sp, #0x18]
	bl Heap_Free
	add r0, r6, #0
	bl Sprite_GetVramType
	ldr r4, [r5, #0x38]
	add r7, r0, #0
	add r0, r5, r4
	mov r1, #0x20
	bl DC_FlushRange
	add r0, r6, #0
	bl Sprite_GetPaletteProxy
	add r1, r7, #0
	bl NNS_G2dGetImagePaletteLocation
	add r1, r0, #0
	cmp r7, #1
	bne _021EEB52
	add r0, r5, r4
	mov r2, #0x20
	bl GX_LoadOBJPltt
	b _021EEB5A
_021EEB52:
	add r0, r5, r4
	mov r2, #0x20
	bl GXS_LoadOBJPltt
_021EEB5A:
	ldr r0, [sp, #0x10]
	bl Heap_Free
	ldr r0, [sp, #0x14]
	bl NARC_Delete
	add r0, r6, #0
	mov r1, #1
	bl thunk_Sprite_SetDrawFlag
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EEA94


	thumb_func_start ov96_021EEB74
ov96_021EEB74: ; 0x021EEB74
	push {r4, lr}
	lsl r4, r2, #2
	ldr r0, [r0, r4]
	ldr r0, [r0]
	bl ov96_021EEB84
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021EEB74


	thumb_func_start ov96_021EEB84
ov96_021EEB84: ; 0x021EEB84
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r6, r0, #0
	add r0, r4, #0
	add r1, r2, #0
	add r5, r3, #0
	bl PokeathlonCourse_GetPlayerProfileFromData
	add r7, r0, #0
	add r0, r4, #0
	bl PokeathlonCourse_GetHeapID
	add r4, r0, #0
	add r0, r7, #0
	bl PlayerProfile_GetTrainerGender
	cmp r0, #0
	bne _021EEBB0
	mov r0, #0
	bl ov96_021EEBC8
	b _021EEBB6
_021EEBB0:
	mov r0, #1
	bl ov96_021EEBC8
_021EEBB6:
	lsl r2, r5, #0x18
	add r1, r0, #0
	add r0, r6, #0
	lsr r2, r2, #0x18
	add r3, r4, #0
	bl ov96_021EEA94
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EEB84


	thumb_func_start ov96_021EEBC8
ov96_021EEBC8: ; 0x021EEBC8
	push {r4, lr}
	add r4, r0, #0
	cmp r4, #6
	blo _021EEBD4
	bl GF_AssertFail
_021EEBD4:
	ldr r0, _021EEBE0 ; =ov96_0221B1BC
	lsl r1, r4, #2
	ldr r0, [r0, r1]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	pop {r4, pc}
	.balign 4, 0
_021EEBE0: .word ov96_0221B1BC
	thumb_func_end ov96_021EEBC8


	thumb_func_start ov96_021EEBE4
ov96_021EEBE4: ; 0x021EEBE4
	push {r4, lr}
	sub sp, #8
	ldr r4, [sp, #0x10]
	str r4, [sp]
	mov r4, #1
	str r4, [sp, #4]
	bl ov96_021EEC0C
	add sp, #8
	pop {r4, pc}
	thumb_func_end ov96_021EEBE4


	thumb_func_start ov96_021EEBF8
ov96_021EEBF8: ; 0x021EEBF8
	push {r4, lr}
	sub sp, #8
	ldr r4, [sp, #0x10]
	str r4, [sp]
	ldr r4, [sp, #0x14]
	str r4, [sp, #4]
	bl ov96_021EEC0C
	add sp, #8
	pop {r4, pc}
	thumb_func_end ov96_021EEBF8


	thumb_func_start ov96_021EEC0C
ov96_021EEC0C: ; 0x021EEC0C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	add r4, r1, #0
	ldrh r1, [r4]
	add r5, r0, #0
	add r6, r3, #0
	str r2, [sp, #0x14]
	cmp r1, #0
	bne _021EEC28
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
_021EEC28:
	ldrb r0, [r4, #6]
	mov r3, #2
	str r0, [sp]
	ldrh r0, [r4, #2]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r4, #0xc]
	str r0, [sp, #8]
	ldrb r2, [r4, #7]
	add r0, sp, #0x28
	bl GetMonSpriteCharAndPlttNarcIdsEx
	ldr r3, _021EECB4 ; =ov96_0221B1AC
	add r2, sp, #0x18
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r1, #0x32
	ldr r0, [sp, #0x50]
	lsl r1, r1, #6
	bl Heap_AllocAtEnd
	add r7, r0, #0
	str r7, [sp]
	ldr r0, [r4, #0xc]
	add r1, sp, #0x18
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	ldrh r0, [r4]
	ldr r2, [sp, #0x50]
	add r3, sp, #0x18
	str r0, [sp, #0x10]
	ldrh r0, [r1, #0x10]
	ldrh r1, [r1, #0x12]
	bl sub_02014510
	mov r2, #0x32
	ldr r0, [r5]
	add r1, r7, #0
	lsl r2, r2, #6
	bl ov96_021EED64
	ldr r0, [sp, #0x54]
	cmp r0, #0
	beq _021EECA0
	ldr r0, [sp, #0x50]
	str r6, [sp]
	str r0, [sp, #4]
	add r2, sp, #0x18
	ldrh r1, [r2, #0x10]
	ldrh r2, [r2, #0x14]
	ldr r3, [sp, #0x14]
	add r0, r5, #0
	bl ov96_021EED70
_021EECA0:
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r0, r7, #0
	bl Heap_Free
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021EECB4: .word ov96_0221B1AC
	thumb_func_end ov96_021EEC0C


	thumb_func_start ov96_021EECB8
ov96_021EECB8: ; 0x021EECB8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	ldrh r0, [r4]
	ldrh r2, [r4, #2]
	mov r1, #0
	add r7, r3, #0
	bl GetMonIconNaixEx
	add r1, r0, #0
	ldr r0, [sp, #0x24]
	mov r2, #0
	str r0, [sp]
	add r0, r7, #0
	add r3, sp, #4
	bl GfGfxLoader_GetCharDataFromOpenNarc
	add r7, r0, #0
	bne _021EECE6
	bl GF_AssertFail
_021EECE6:
	ldr r1, [sp, #4]
	mov r2, #2
	ldr r0, [r5]
	ldr r1, [r1, #0x14]
	ldr r3, [sp, #0x20]
	lsl r2, r2, #8
	bl ov96_021EED14
	add r0, r7, #0
	bl Heap_Free
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	mov r2, #0
	bl GetMonIconPaletteEx
	add r1, r0, #0
	add r0, r5, #0
	add r1, r6, r1
	bl ManagedSprite_SetPaletteOverride
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EECB8


	thumb_func_start ov96_021EED14
ov96_021EED14: ; 0x021EED14
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r7, r1, #0
	str r2, [sp]
	add r5, r3, #0
	bl Sprite_GetVramType
	add r4, r0, #0
	add r0, r6, #0
	bl Sprite_GetImageProxy
	add r1, r4, #0
	bl NNS_G2dGetImageLocation
	add r6, r0, #0
	ldr r1, [sp]
	add r0, r7, #0
	bl DC_FlushRange
	cmp r4, #1
	beq _021EED44
	cmp r4, #2
	beq _021EED50
	b _021EED5C
_021EED44:
	ldr r2, [sp]
	add r0, r7, #0
	add r1, r6, r5
	bl GX_LoadOBJ
	pop {r3, r4, r5, r6, r7, pc}
_021EED50:
	ldr r2, [sp]
	add r0, r7, #0
	add r1, r6, r5
	bl GXS_LoadOBJ
	pop {r3, r4, r5, r6, r7, pc}
_021EED5C:
	bl GF_AssertFail
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EED14

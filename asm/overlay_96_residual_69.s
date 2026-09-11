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

	thumb_func_start ov96_021F8980
ov96_021F8980: ; 0x021F8980
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r1, #6
	lsl r1, r1, #6
	ldr r2, [r5]
	mov r0, #0x37
	add r1, r5, r1
	bl G2dRenderer_Init
	mov r1, #0x5f
	lsl r1, r1, #2
	mov r7, #0xaa
	str r0, [r5, r1]
	mov r6, #0
	add r4, r5, #0
	lsl r7, r7, #2
_021F89A2:
	ldr r2, [r5]
	mov r0, #1
	add r1, r6, #0
	bl Create2DGfxResObjMan
	str r0, [r4, r7]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #6
	blt _021F89A2
	mov r0, #0x67
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r5]
	mov r1, #0xa0
	str r0, [sp, #8]
	mov r0, #0xaa
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r2, #9
	mov r3, #0
	bl AddCharResObjFromNarc
	mov r1, #0xb
	lsl r1, r1, #6
	str r0, [r5, r1]
	mov r0, #0x67
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r2, #6
	str r2, [sp, #8]
	ldr r0, [r5]
	sub r1, #0x14
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	mov r1, #0xa0
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0xb1
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0x67
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5]
	sub r1, #0x14
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xa0
	mov r2, #8
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0xb2
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0x67
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r5]
	sub r1, #0x14
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	mov r1, #0xa0
	mov r2, #7
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0xb3
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0xc
	ldr r0, [r5, r1]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	mov r0, #0xb1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F8980


	thumb_func_start ov96_021F8A50
ov96_021F8A50: ; 0x021F8A50
	push {r3, r4, lr}
	sub sp, #0x2c
	mov r1, #0x67
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x68
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	mov r4, #0xaa
	str r2, [sp, #0x10]
	lsl r4, r4, #2
	ldr r3, [r0, r4]
	str r3, [sp, #0x14]
	add r3, r4, #4
	ldr r3, [r0, r3]
	str r3, [sp, #0x18]
	add r3, r4, #0
	add r3, #8
	ldr r3, [r0, r3]
	str r3, [sp, #0x1c]
	add r3, r4, #0
	add r3, #0xc
	ldr r3, [r0, r3]
	add r4, #0x30
	str r3, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, r0, r4
	add r2, r1, #0
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	add sp, #0x2c
	pop {r3, r4, pc}
	thumb_func_end ov96_021F8A50


	thumb_func_start ov96_021F8A98
ov96_021F8A98: ; 0x021F8A98
	push {r3, r4}
	mov r2, #0x5f
	lsl r2, r2, #2
	ldr r2, [r1, r2]
	mov r4, #0
	str r2, [r0]
	mov r2, #0xb6
	lsl r2, r2, #2
	add r2, r1, r2
	str r2, [r0, #4]
	str r4, [r0, #8]
	str r4, [r0, #0xc]
	mov r2, #1
	str r4, [r0, #0x10]
	lsl r2, r2, #0xc
	str r2, [r0, #0x14]
	str r2, [r0, #0x18]
	str r2, [r0, #0x1c]
	strh r4, [r0, #0x20]
	mov r2, #2
	str r2, [r0, #0x24]
	str r3, [r0, #0x28]
	ldr r1, [r1]
	str r1, [r0, #0x2c]
	pop {r3, r4}
	bx lr
	thumb_func_end ov96_021F8A98


	thumb_func_start ov96_021F8ACC
ov96_021F8ACC: ; 0x021F8ACC
	push {r4, r5, r6, lr}
	add r5, r1, #0
	add r6, r2, #0
	bl Sprite_CreateAffine
	add r4, r0, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	add r1, r5, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add r1, r6, #0
	bl Sprite_SetDrawPriority
	add r0, r4, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021F8ACC


	thumb_func_start ov96_021F8AFC
ov96_021F8AFC: ; 0x021F8AFC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r4, r2, #0
	mov r2, #0xb6
	add r3, r0, #0
	lsl r2, r2, #2
	add r5, r1, #0
	add r0, sp, #0x14
	add r1, r3, #0
	add r2, r3, r2
	mov r3, #1
	bl ov96_021F8A98
	add r0, sp, #0x14
	mov r1, #0x11
	mov r2, #4
	bl ov96_021F8ACC
	str r0, [r4]
	add r0, sp, #0x14
	mov r1, #5
	mov r2, #0
	bl ov96_021F8ACC
	str r0, [r4, #4]
	add r0, sp, #0x14
	mov r1, #0x12
	mov r2, #1
	bl ov96_021F8ACC
	str r0, [r4, #8]
	add r0, sp, #0x14
	mov r1, #0
	mov r2, #2
	bl ov96_021F8ACC
	str r0, [r4, #0xc]
	add r4, r0, #0
	bl Sprite_GetVramType
	add r6, r0, #0
	add r0, r4, #0
	bl Sprite_GetImageProxy
	add r7, r0, #0
	add r0, r4, #0
	bl Sprite_GetPaletteProxy
	str r0, [sp]
	add r0, r7, #0
	add r1, r6, #0
	bl NNS_G2dGetImageLocation
	str r0, [sp, #4]
	lsl r0, r5, #9
	str r0, [sp, #8]
	add r0, r7, #0
	bl NNS_G2dInitImageProxy
	ldr r3, [sp, #4]
	ldr r2, [sp, #8]
	add r0, r7, #0
	add r1, r6, #0
	add r2, r3, r2
	bl NNS_G2dSetImageLocation
	ldr r0, [sp]
	add r1, r6, #0
	bl NNS_G2dGetImagePaletteLocation
	str r0, [sp, #0xc]
	add r0, r5, #6
	lsl r0, r0, #5
	str r0, [sp, #0x10]
	ldr r0, [sp]
	bl NNS_G2dInitImagePaletteProxy
	ldr r3, [sp, #0xc]
	ldr r2, [sp, #0x10]
	ldr r0, [sp]
	add r1, r6, #0
	add r2, r3, r2
	bl NNS_G2dSetImagePaletteLocation
	add r0, r4, #0
	add r1, r7, #0
	bl Sprite_SetImageProxy
	ldr r1, [sp]
	add r0, r4, #0
	bl Sprite_SetPaletteProxy
	add r0, r4, #0
	add r1, r5, #0
	bl Sprite_SetPalOffset
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F8AFC


	thumb_func_start ov96_021F8BC0
ov96_021F8BC0: ; 0x021F8BC0
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #4]
	add r4, r2, #0
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r5]
	bl PlayerProfile_GetPlayerName_NewString
	add r6, r0, #0
	mov r0, #0x37
	mvn r0, r0
	str r0, [sp]
	add r0, #0x28
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0xbf
	lsl r1, r1, #2
	str r0, [sp, #8]
	add r4, #0x10
	add r0, r5, #0
	add r1, r5, r1
	add r2, r6, #0
	mov r3, #0
	str r4, [sp, #0xc]
	bl ov96_021F8DF4
	add r0, r6, #0
	bl String_Delete
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021F8BC0


	thumb_func_start ov96_021F8C04
ov96_021F8C04: ; 0x021F8C04
	push {r4, lr}
	sub sp, #0x10
	add r4, r1, #0
	mov r1, #0x37
	mvn r1, r1
	str r1, [sp]
	mov r3, #0
	str r3, [sp, #4]
	ldr r1, [r2]
	add r2, #0x20
	str r1, [sp, #8]
	mov r1, #0xc5
	lsl r1, r1, #2
	str r2, [sp, #0xc]
	add r1, r0, r1
	add r2, r4, #0
	bl ov96_021F8DF4
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov96_021F8C04


	thumb_func_start ov96_021F8C2C
ov96_021F8C2C: ; 0x021F8C2C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	add r2, r4, #0
	bl ov96_021F8C88
	ldr r1, [r4, #0x40]
	ldr r0, [r4]
	add r1, r1, #2
	bl Sprite_SetPaletteOverride
	ldr r0, [r4, #4]
	add r4, #0x44
	ldrh r1, [r4]
	add r1, r1, #5
	bl Sprite_SetAnimCtrlSeq
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F8C2C


	thumb_func_start ov96_021F8C54
ov96_021F8C54: ; 0x021F8C54
	push {r4, r5, r6, lr}
	add r4, r2, #0
	add r6, r0, #0
	ldr r0, [r4]
	add r5, r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r4, #4]
	add r1, r5, #0
	bl Sprite_SetDrawFlag
	cmp r6, #0
	beq _021F8C76
	ldr r0, [r4, #8]
	add r1, r5, #0
	bl Sprite_SetDrawFlag
_021F8C76:
	ldr r0, [r4, #0x10]
	add r1, r5, #0
	bl TextOBJ_SetSpritesDrawFlag
	ldr r0, [r4, #0x20]
	add r1, r5, #0
	bl TextOBJ_SetSpritesDrawFlag
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021F8C54


	thumb_func_start ov96_021F8C88
ov96_021F8C88: ; 0x021F8C88
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r6, _021F8CF8 ; =ov96_0221C3E0
	add r5, r2, #0
	add r4, r0, #0
	add r3, r1, #0
	add r2, sp, #0
	ldmia r6!, {r0, r1}
	add r7, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r6]
	str r0, [r2]
	ldr r1, [sp, #4]
	lsl r0, r3, #0xc
	add r0, r1, r0
	str r0, [sp, #4]
	add r0, r4, #0
	add r0, #0x80
	lsl r0, r0, #0xc
	str r0, [sp]
	ldr r0, [r5]
	add r1, r7, #0
	bl Sprite_SetMatrix
	add r0, r4, #0
	add r0, #0x10
	lsl r0, r0, #0xc
	str r0, [sp]
	ldr r0, [r5, #4]
	add r1, r7, #0
	bl Sprite_SetMatrix
	add r4, #0x30
	lsl r0, r4, #0xc
	str r0, [sp]
	ldr r0, [r5, #8]
	add r1, r7, #0
	bl Sprite_SetMatrix
	mov r0, #1
	ldr r1, [sp, #4]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	add r1, r7, #0
	bl Sprite_SetMatrix
	ldr r0, [r5, #0x10]
	bl sub_02013728
	ldr r0, [r5, #0x20]
	bl sub_02013728
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021F8CF8: .word ov96_0221C3E0
	thumb_func_end ov96_021F8C88


	thumb_func_start ov96_021F8CFC
ov96_021F8CFC: ; 0x021F8CFC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r2, #0
	add r5, r0, #0
	ldr r0, [r4]
	add r7, r1, #0
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	add r2, sp, #0
	lsl r6, r5, #0xc
	ldmia r3!, {r0, r1}
	mov ip, r2
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	lsl r5, r7, #0xc
	str r0, [r2]
	ldr r0, [sp]
	mov r1, ip
	add r0, r0, r6
	str r0, [sp]
	ldr r0, [sp, #4]
	add r0, r0, r5
	str r0, [sp, #4]
	ldr r0, [r4]
	bl Sprite_SetMatrix
	ldr r0, [r4, #4]
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	add r7, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, r7, #0
	str r0, [r2]
	ldr r0, [sp]
	add r0, r0, r6
	str r0, [sp]
	ldr r0, [sp, #4]
	add r0, r0, r5
	str r0, [sp, #4]
	ldr r0, [r4, #4]
	bl Sprite_SetMatrix
	ldr r0, [r4, #0xc]
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	ldmia r3!, {r0, r1}
	add r2, r7, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, r7, #0
	str r0, [r2]
	ldr r0, [sp]
	add r0, r0, r6
	str r0, [sp]
	ldr r0, [sp, #4]
	add r0, r0, r5
	str r0, [sp, #4]
	ldr r0, [r4, #0xc]
	bl Sprite_SetMatrix
	ldr r0, [r4, #8]
	add r1, r7, #0
	bl Sprite_SetMatrix
	ldr r0, [r4, #0x10]
	bl sub_02013728
	ldr r0, [r4, #0x20]
	bl sub_02013728
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F8CFC


	thumb_func_start ov96_021F8D98
ov96_021F8D98: ; 0x021F8D98
	push {r4, r5, r6, lr}
	sub sp, #8
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #0
	add r6, r2, #0
	bl InitWindow
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	lsl r2, r6, #0x18
	ldr r0, [r5, #8]
	add r1, r4, #0
	lsr r2, r2, #0x18
	mov r3, #2
	bl AddTextWindowTopLeftCorner
	ldr r1, [r5]
	add r0, r4, #0
	bl sub_02013910
	mov r1, #1
	str r0, [r4, #0x10]
	bl sub_02013948
	str r0, [r4, #0x14]
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021F8D98


	thumb_func_start ov96_021F8DD4
ov96_021F8DD4: ; 0x021F8DD4
	push {r4, lr}
	mov r1, #0xbf
	add r4, r0, #0
	lsl r1, r1, #2
	add r1, r4, r1
	mov r2, #8
	bl ov96_021F8D98
	mov r1, #0xc5
	lsl r1, r1, #2
	add r0, r4, #0
	add r1, r4, r1
	mov r2, #0x18
	bl ov96_021F8D98
	pop {r4, pc}
	thumb_func_end ov96_021F8DD4


	thumb_func_start ov96_021F8DF4
ov96_021F8DF4: ; 0x021F8DF4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x58
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0
	add r7, r2, #0
	str r3, [sp, #0x18]
	ldr r6, [sp, #0x7c]
	bl FillWindowPixelBufferText_AssumeTileSize32
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021F8E90 ; =0x00010200
	ldr r3, [sp, #0x18]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	add r0, r4, #0
	add r2, r7, #0
	bl AddTextPrinterParameterizedWithColorAndSpacing
	mov r1, #1
	ldr r0, [r4, #0x14]
	add r2, r1, #0
	add r3, sp, #0x1c
	bl sub_02021AC8
	ldr r0, [r5, #0x10]
	mov r1, #0
	str r0, [sp, #0x28]
	mov r0, #0x5f
	str r4, [sp, #0x2c]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	str r0, [sp, #0x30]
	mov r0, #0xb1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_GetPaletteProxy
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x78]
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x70]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x74]
	str r0, [sp, #0x44]
	mov r0, #0
	str r0, [sp, #0x48]
	mov r0, #3
	str r0, [sp, #0x4c]
	mov r0, #1
	str r0, [sp, #0x50]
	ldr r0, [r5]
	str r0, [sp, #0x54]
	add r0, sp, #0x28
	bl sub_020135D8
	add r4, r0, #0
	mov r1, #0
	bl TextOBJ_SetPaletteNum
	str r4, [r6]
	add r3, sp, #0x1c
	ldmia r3!, {r0, r1}
	add r2, r6, #4
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	add sp, #0x58
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F8E90: .word 0x00010200
	thumb_func_end ov96_021F8DF4


	thumb_func_start ov96_021F8E94
ov96_021F8E94: ; 0x021F8E94
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	beq _021F8EAC
	bl TextOBJ_Destroy
	add r0, r4, #4
	bl sub_02021B5C
	mov r0, #0
	str r0, [r4]
_021F8EAC:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F8E94


	thumb_func_start ov96_021F8EB0
ov96_021F8EB0: ; 0x021F8EB0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r1, #0
	mov r1, #0xc4
	add r6, r0, #0
	add r5, r2, #0
	bl Heap_Alloc
	add r4, r0, #0
	mov r1, #0
	mov r2, #0xc4
	bl MI_CpuFill8
	str r6, [r4]
	mov r0, #4
	add r1, r6, #0
	bl FontSystem_NewInit
	str r0, [r4, #8]
	str r5, [r4, #4]
	add r5, r4, #0
	add r5, #0xc
	add r0, r5, #0
	bl InitWindow
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r7, #0
	add r1, r5, #0
	mov r2, #8
	mov r3, #2
	bl AddTextWindowTopLeftCorner
	ldr r1, [r4]
	add r0, r5, #0
	bl sub_02013910
	mov r1, #2
	str r0, [r5, #0x10]
	bl sub_02013948
	str r0, [r5, #0x14]
	add r0, r4, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F8EB0


	thumb_func_start ov96_021F8F0C
ov96_021F8F0C: ; 0x021F8F0C
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r5, r6, #0
	mov r4, #0
	add r5, #0x34
_021F8F16:
	add r0, r5, #0
	bl ov96_021F91CC
	add r4, r4, #1
	add r5, #0x28
	cmp r4, #4
	blt _021F8F16
	add r4, r6, #0
	add r4, #0xc
	ldr r0, [r4, #0x10]
	bl sub_02013938
	add r0, r4, #0
	bl RemoveWindow
	ldr r0, [r6, #8]
	bl sub_020135AC
	add r0, r6, #0
	bl Heap_Free
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021F8F0C


	thumb_func_start ov96_021F8F44
ov96_021F8F44: ; 0x021F8F44
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	ldr r0, [r4, #4]
	mov r2, #0x68
	bl ov96_021EB29C
	mov r0, #2
	str r0, [sp]
	ldr r0, [r4, #4]
	mov r1, #0xa1
	mov r2, #3
	mov r3, #0x68
	bl ov96_021EB2BC
	mov r0, #2
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	ldr r0, [r4, #4]
	mov r1, #0xa1
	mov r2, #0
	mov r3, #0x68
	bl ov96_021EB2F4
	ldr r0, [r4, #4]
	mov r1, #0xa1
	mov r2, #2
	mov r3, #0x68
	bl ov96_021EB334
	ldr r0, [r4, #4]
	mov r1, #0xa1
	mov r2, #1
	mov r3, #0x68
	bl ov96_021EB36C
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F8F44


	thumb_func_start ov96_021F8F94
ov96_021F8F94: ; 0x021F8F94
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r6, r0, #0
	mov r0, #0
	str r0, [sp, #0x34]
	str r0, [sp, #0x28]
	mov r0, #8
	str r0, [sp, #0x24]
	add r0, r2, #0
	add r0, #0x10
	lsl r0, r0, #0xc
	str r0, [sp, #0x20]
	add r0, r2, #0
	add r0, #0x18
	lsl r0, r0, #0xc
	str r1, [sp, #0x10]
	str r2, [sp, #0x14]
	str r0, [sp, #0x1c]
_021F8FB8:
	mov r0, #3
	str r0, [sp]
	ldr r0, [r6, #4]
	mov r1, #0
	mov r2, #2
	mov r3, #0x68
	bl ov96_021EB408
	mov r1, #0
	str r1, [sp, #0x40]
	ldr r1, [sp, #0x28]
	add r4, r0, #0
	lsl r1, r1, #0xc
	str r1, [sp, #0x38]
	ldr r1, [sp, #0x20]
	str r1, [sp, #0x3c]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	ldr r1, [sp, #0x34]
	add r0, r4, #0
	bl Sprite_SetPalIndexRespectVramOffset
	add r0, r4, #0
	mov r1, #2
	bl Sprite_SetDrawPriority
	ldr r5, [sp, #0x24]
	mov r7, #0
_021F9002:
	mov r0, #4
	str r0, [sp]
	ldr r0, [r6, #4]
	mov r1, #0
	mov r2, #2
	mov r3, #0x68
	bl ov96_021EB408
	mov r1, #0
	str r1, [sp, #0x40]
	lsl r1, r5, #0xc
	str r1, [sp, #0x38]
	ldr r1, [sp, #0x1c]
	add r4, r0, #0
	str r1, [sp, #0x3c]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetDrawPriority
	add r7, r7, #1
	add r5, #0x10
	cmp r7, #3
	blt _021F9002
	ldr r0, [sp, #0x28]
	add r0, #0x40
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x24]
	add r0, #0x40
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x34]
	add r0, r0, #1
	str r0, [sp, #0x34]
	cmp r0, #4
	blt _021F8FB8
	mov r0, #0
	str r0, [sp, #0x18]
	add r0, r6, #0
	str r0, [sp, #0x30]
	add r0, #0x24
	str r0, [sp, #0x30]
	add r0, r6, #0
	str r0, [sp, #0x2c]
	add r0, #0x34
	add r7, r6, #0
	str r0, [sp, #0x2c]
_021F9072:
	ldr r0, [r6, #4]
	mov r1, #0x68
	mov r2, #3
	bl ov96_021EB4F4
	ldr r1, [sp, #0x30]
	str r0, [r1]
	mov r1, #1
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r4, [sp, #0x30]
	mov r5, #0
_021F908C:
	ldr r0, [r6, #4]
	mov r1, #0x68
	mov r2, #4
	bl ov96_021EB4F4
	mov r1, #1
	add r2, r1, #0
	str r0, [r4, #4]
	bl ov96_021EB52C
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #3
	blt _021F908C
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x18]
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r6]
	bl PlayerProfile_GetPlayerName_NewString
	add r4, r0, #0
	ldr r0, [r7, #0x24]
	bl ov96_021EB5B8
	mov r1, #0
	str r1, [sp]
	sub r1, #0x10
	str r1, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [sp, #0x2c]
	add r1, r6, #0
	str r0, [sp, #0xc]
	add r0, r6, #0
	add r1, #0xc
	add r2, r4, #0
	mov r3, #2
	bl ov96_021F9134
	add r0, r4, #0
	bl String_Delete
	ldr r0, [r7, #0x34]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	ldr r0, [sp, #0x14]
	add r0, #0x10
	str r0, [r7, #0x48]
	ldr r0, [sp, #0x30]
	add r7, #0x28
	add r0, #0x28
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x2c]
	add r0, #0x28
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #4
	blt _021F9072
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F8F94


	thumb_func_start ov96_021F910C
ov96_021F910C: ; 0x021F910C
	push {r4, r5, r6, lr}
	add r6, r2, #0
	add r5, r0, #0
	add r4, r1, #0
	cmp r6, #4
	blo _021F911C
	bl GF_AssertFail
_021F911C:
	mov r0, #0x28
	add r1, r6, #0
	mul r1, r0
	add r0, r5, r1
	add r5, #0x24
	str r4, [r0, #0x44]
	add r0, r5, r1
	add r1, r4, #0
	bl ov96_021F91E8
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021F910C


	thumb_func_start ov96_021F9134
ov96_021F9134: ; 0x021F9134
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x58
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0
	add r7, r2, #0
	str r3, [sp, #0x18]
	ldr r6, [sp, #0x7c]
	bl FillWindowPixelBufferText_AssumeTileSize32
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021F91C8 ; =0x00010200
	ldr r3, [sp, #0x18]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	add r0, r4, #0
	add r2, r7, #0
	bl AddTextPrinterParameterizedWithColorAndSpacing
	ldr r0, [r4, #0x14]
	mov r1, #1
	mov r2, #2
	add r3, sp, #0x1c
	bl sub_02021AC8
	ldr r0, [r5, #8]
	str r4, [sp, #0x2c]
	str r0, [sp, #0x28]
	ldr r0, [r5, #4]
	bl ov96_021EB5E8
	str r0, [sp, #0x30]
	mov r0, #0x68
	bl ObjPlttTransfer_GetPlttProxyByID
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x78]
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x70]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x74]
	str r0, [sp, #0x44]
	mov r0, #0
	str r0, [sp, #0x48]
	str r0, [sp, #0x4c]
	mov r0, #2
	str r0, [sp, #0x50]
	ldr r0, [r5]
	str r0, [sp, #0x54]
	add r0, sp, #0x28
	bl sub_020135D8
	add r4, r0, #0
	mov r1, #4
	bl sub_02013880
	str r4, [r6]
	add r3, sp, #0x1c
	ldmia r3!, {r0, r1}
	add r2, r6, #4
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	add sp, #0x58
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F91C8: .word 0x00010200
	thumb_func_end ov96_021F9134


	thumb_func_start ov96_021F91CC
ov96_021F91CC: ; 0x021F91CC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	beq _021F91E4
	bl TextOBJ_Destroy
	add r0, r4, #4
	bl sub_02021B5C
	mov r0, #0
	str r0, [r4]
_021F91E4:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F91CC


	thumb_func_start ov96_021F91E8
ov96_021F91E8: ; 0x021F91E8
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0x64
	bl _s32_div_f
	add r7, r0, #0
	mov r0, #0x64
	mul r0, r7
	sub r6, r4, r0
	add r0, r6, #0
	mov r1, #0xa
	bl _s32_div_f
	add r4, r0, #0
	ldr r0, [r5, #4]
	bl ov96_021EB5B8
	add r1, r7, #1
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [r5, #8]
	bl ov96_021EB5B8
	add r1, r4, #1
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [r5, #0xc]
	bl ov96_021EB5B8
	mov r1, #0xa
	mul r1, r4
	sub r1, r6, r1
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F91E8

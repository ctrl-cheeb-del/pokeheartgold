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

	thumb_func_start ov96_021EC490
ov96_021EC490: ; 0x021EC490
	push {r3, r4, lr}
	sub sp, #0x4c
	ldr r3, _021EC510 ; =ov96_0221AF88
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x34
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _021EC514 ; =ov96_0221B010
	add r2, sp, #0x14
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _021EC518 ; =ov96_0221AF74
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
	str r0, [r4, #0x18]
	bl SpriteManager_New
	str r0, [r4, #0x1c]
	ldr r0, [r4, #0x18]
	add r1, sp, #0x14
	add r2, sp, #0
	mov r3, #0x20
	bl SpriteSystem_Init
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	mov r2, #0x80
	bl SpriteSystem_InitSprites
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1c]
	add r2, sp, #0x34
	bl SpriteSystem_InitManagerWithCapacities
	ldr r0, [r4, #0x18]
	bl SpriteSystem_GetRenderer
	mov r2, #0x83
	mov r1, #0
	lsl r2, r2, #0xe
	bl G2dRenderer_SetSubSurfaceCoords
	add sp, #0x4c
	pop {r3, r4, pc}
	.balign 4, 0
_021EC510: .word ov96_0221AF88
_021EC514: .word ov96_0221B010
_021EC518: .word ov96_0221AF74
	thumb_func_end ov96_021EC490


	thumb_func_start ov96_021EC51C
ov96_021EC51C: ; 0x021EC51C
	push {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	add r6, r0, #0
	add r7, r4, #0
_021EC524:
	lsl r0, r4, #2
	add r5, r6, r0
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _021EC534
	bl Sprite_DeleteAndFreeResources
	str r7, [r5, #0x20]
_021EC534:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #0x1a
	blo _021EC524
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	bl SpriteSystem_FreeResourcesAndManager
	ldr r0, [r6, #0x18]
	bl SpriteSystem_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EC51C


	thumb_func_start ov96_021EC550
ov96_021EC550: ; 0x021EC550
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	mov r4, #0
	add r7, r0, #0
	add r2, sp, #0
	add r0, r4, #0
	add r1, r4, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [r2]
	mov r5, #0x20
	add r6, r7, #0
_021EC570:
	add r0, r4, #0
	add r0, #0x64
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	mov r0, #0x64
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	mov r0, #2
	str r0, [sp, #0x10]
	mov r0, #1
	mov r1, #0x88
	str r0, [sp, #0x2c]
	str r0, [sp, #8]
	add r0, sp, #0
	strh r5, [r0]
	strh r1, [r0, #2]
	cmp r4, #4
	bne _021EC59C
	mov r1, #0x80
	strh r1, [r0]
	mov r1, #0x70
	strh r1, [r0, #2]
_021EC59C:
	mov r3, #0x83
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	add r2, sp, #0
	lsl r3, r3, #0xe
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	str r0, [r6, #0x20]
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r5, #0x40
	add r6, r6, #4
	cmp r4, #5
	blt _021EC570
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EC550


	thumb_func_start ov96_021EC5C0
ov96_021EC5C0: ; 0x021EC5C0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	add r5, r0, #0
	mov r0, #0
	add r2, sp, #0xc
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [sp, #8]
	str r0, [r2]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #0x20
	str r0, [sp]
_021EC5E4:
	mov r0, #0x69
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	mov r0, #0x65
	mov r1, #2
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	mov r0, #1
	str r0, [sp, #0x38]
	ldr r0, [sp]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x14]
	add r1, sp, #0xc
	strh r0, [r1]
	mov r0, #0x48
	strh r0, [r1, #2]
	mov r0, #0
	strh r0, [r1, #6]
	ldr r0, [sp, #8]
	mov r3, #0x83
	add r0, r0, #1
	str r0, [sp, #0x18]
	ldr r0, [sp, #4]
	ldr r1, [r5, #0x1c]
	lsl r0, r0, #2
	add r4, r5, r0
	ldr r0, [r5, #0x18]
	add r2, sp, #0xc
	lsl r3, r3, #0xe
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	str r0, [r4, #0x20]
	bl ManagedSprite_SetAnimateFlag
	mov r2, #1
	mov r4, #0
	str r4, [sp, #0x18]
	str r2, [sp, #0x38]
	str r2, [sp, #0x14]
	add r0, sp, #0xc
	ldrsh r1, [r0, r4]
	sub r1, #0x10
	strh r1, [r0]
	strh r2, [r0, #6]
	ldr r0, [sp, #4]
	add r7, r0, #1
_021EC642:
	add r0, r7, r4
	lsl r0, r0, #2
	add r6, r5, r0
	mov r3, #0x83
	ldr r0, [r5, #0x18]
	ldr r1, [r5, #0x1c]
	add r2, sp, #0xc
	lsl r3, r3, #0xe
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	str r0, [r6, #0x20]
	bl ManagedSprite_SetAnimateFlag
	add r1, sp, #0xc
	mov r0, #0
	ldrsh r1, [r1, r0]
	add r0, sp, #0xc
	add r4, r4, #1
	add r1, #0x10
	strh r1, [r0]
	cmp r4, #3
	blt _021EC642
	ldr r0, [sp, #4]
	add r0, r0, #4
	str r0, [sp, #4]
	ldr r0, [sp]
	add r0, #0x40
	str r0, [sp]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #4
	blt _021EC5E4
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EC5C0


	thumb_func_start ov96_021EC68C
ov96_021EC68C: ; 0x021EC68C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	mov r4, #0
	add r7, r0, #0
	add r2, sp, #4
	add r0, r4, #0
	add r1, r4, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [r2]
	mov r0, #2
	mov r5, #0x30
	str r0, [sp]
_021EC6AE:
	add r0, r4, #0
	add r0, #0x6d
	str r0, [sp, #0x18]
	mov r0, #0x6a
	str r0, [sp, #0x1c]
	mov r0, #0x68
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	mov r0, #1
	str r0, [sp, #0x14]
	add r0, sp, #4
	strh r5, [r0]
	mov r1, #0x70
	strh r1, [r0, #2]
	mov r0, #0
	str r0, [sp, #0x30]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r0, #0x15
	lsl r0, r0, #2
	add r6, r7, r0
	mov r3, #0x83
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	add r2, sp, #4
	lsl r3, r3, #0xe
	bl SpriteSystem_NewSpriteWithYOffset
	ldr r1, [sp]
	str r0, [r6, #0x20]
	bl ManagedSprite_SetPaletteOverride
	ldr r0, [r6, #0x20]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [sp]
	add r4, r4, #1
	add r0, r0, #3
	add r5, #0x50
	str r0, [sp]
	cmp r4, #3
	blt _021EC6AE
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EC68C


	thumb_func_start ov96_021EC70C
ov96_021EC70C: ; 0x021EC70C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	mov r7, #0
	add r5, r0, #0
	add r2, sp, #0
	add r0, r7, #0
	add r1, r7, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [r2]
	mov r4, #0x60
_021EC72A:
	add r1, r7, #0
	add r1, #0x6b
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	mov r1, #0x67
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	mov r1, #1
	str r1, [sp, #0x10]
	mov r1, #0
	str r1, [sp, #0x2c]
	mov r1, #2
	str r1, [sp, #8]
	add r1, sp, #0
	add r0, r7, #0
	strh r4, [r1]
	mov r2, #0x38
	strh r2, [r1, #2]
	add r1, r5, #0
	add r1, #0xb1
	ldrb r1, [r1]
	add r0, #0x18
	cmp r1, #5
	bhs _021EC760
	mov r2, #0x80
	add r1, sp, #0
	strh r2, [r1]
_021EC760:
	lsl r0, r0, #2
	add r6, r5, r0
	mov r3, #0x83
	ldr r0, [r5, #0x18]
	ldr r1, [r5, #0x1c]
	add r2, sp, #0
	lsl r3, r3, #0xe
	bl SpriteSystem_NewSpriteWithYOffset
	str r0, [r6, #0x20]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [r6, #0x20]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r7, r7, #1
	add r4, #0x40
	cmp r7, #2
	blt _021EC72A
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EC70C


	thumb_func_start ov96_021EC790
ov96_021EC790: ; 0x021EC790
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	bl PokeathlonCourse_GetParticipantUnk04
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	bl PokeathlonCourse_GetParticipantData
	mov r0, #0
	str r0, [sp, #0x14]
	add r6, r4, #0
	mov r5, #1
	add r7, sp, #0x1c
_021EC7B8:
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	add r3, sp, #0x30
	bl ov96_021E6168
	ldr r0, [r4]
	add r1, sp, #0x30
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r6, #0x74]
	mov r2, #1
	mov r3, #0
	bl ov96_021EEBF8
	ldrb r0, [r7, #0x1a]
	mov r3, #2
	str r0, [sp]
	ldrh r0, [r7, #0x16]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #8]
	ldrh r1, [r7, #0x14]
	ldrb r2, [r7, #0x1b]
	add r0, sp, #0x20
	bl GetMonSpriteCharAndPlttNarcIdsEx
	ldrh r0, [r7, #4]
	ldrh r1, [r7, #8]
	ldr r3, [r4]
	add r2, sp, #0x1c
	bl GfGfxLoader_GetPlttData
	ldr r3, [sp, #0x1c]
	str r0, [sp, #0x18]
	lsl r1, r5, #0x18
	ldr r0, [r4, #0x14]
	ldr r3, [r3, #0xc]
	lsr r1, r1, #0x18
	mov r2, #1
	bl ov96_021EAF60
	ldr r0, [sp, #0x18]
	bl Heap_Free
	ldr r0, [sp, #0x14]
	add r6, r6, #4
	add r0, r0, #1
	add r5, r5, #3
	str r0, [sp, #0x14]
	cmp r0, #3
	blt _021EC7B8
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EC790


	thumb_func_start ov96_021EC82C
ov96_021EC82C: ; 0x021EC82C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	bl PokeathlonCourse_GetHeapAllocPtr4
	ldr r6, [r0, #0x18]
	ldr r4, [r0, #0x1c]
	str r0, [sp, #0x10]
	mov r7, #0
_021EC83C:
	mov r0, #1
	add r5, r7, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r5, #0x64
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #9
	str r5, [sp, #8]
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #8
	str r5, [sp, #0xc]
	bl SpriteSystem_LoadPlttResObj
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #5
	blo _021EC83C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x64
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0xa
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0x64
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0xb
	bl SpriteSystem_LoadAnimResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x69
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0xd
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x69
	str r0, [sp, #0xc]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0xc
	bl SpriteSystem_LoadPlttResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0x65
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0xe
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0x65
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0xf
	bl SpriteSystem_LoadAnimResObj
	ldr r0, [sp, #0x10]
	bl ov96_021ECA18
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x6a
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0x10
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6a
	str r0, [sp, #0xc]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0xc
	bl SpriteSystem_LoadPlttResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0x66
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0x11
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0x66
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0x12
	bl SpriteSystem_LoadAnimResObj
	ldr r0, [sp, #0x10]
	mov r1, #0
	add r0, #0xb1
	ldrb r5, [r0]
	str r0, [sp, #0x10]
	add r0, r5, #0
	bl ov96_021EDC38
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6b
	str r0, [sp, #0xc]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	add r3, #0x17
	bl SpriteSystem_LoadPlttResObj
	add r0, r5, #0
	mov r1, #1
	bl ov96_021EDC38
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6c
	str r0, [sp, #0xc]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	add r3, #0x17
	bl SpriteSystem_LoadPlttResObj
	add r0, r5, #0
	mov r1, #0
	bl ov96_021EDC38
	add r3, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x6b
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	add r3, #0x1c
	bl SpriteSystem_LoadCharResObj
	add r0, r5, #0
	mov r1, #1
	bl ov96_021EDC38
	add r3, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x6c
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	add r3, #0x1c
	bl SpriteSystem_LoadCharResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0x67
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0x21
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0x67
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9a
	mov r3, #0x22
	bl SpriteSystem_LoadAnimResObj
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EC82C


	thumb_func_start ov96_021ECA18
ov96_021ECA18: ; 0x021ECA18
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r6, [r0, #0x18]
	ldr r5, [r0, #0x1c]
	mov r7, #1
	mov r4, #0
_021ECA24:
	mov r0, #1
	str r0, [sp]
	add r0, r4, #0
	str r7, [sp, #4]
	add r0, #0x6d
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #0x9a
	mov r3, #0x14
	bl SpriteSystem_LoadCharResObj
	add r4, r4, #1
	cmp r4, #3
	blt _021ECA24
	mov r0, #1
	str r0, [sp]
	mov r0, #0x68
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #0x9a
	mov r3, #0x15
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0x68
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #0x9a
	mov r3, #0x16
	bl SpriteSystem_LoadAnimResObj
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021ECA18


	thumb_func_start ov96_021ECA70
ov96_021ECA70: ; 0x021ECA70
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	mov r7, #0
	mov r4, #1
	mov r5, #2
_021ECA84:
	lsl r1, r4, #0x18
	ldr r0, [r6, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	str r0, [sp, #8]
	lsl r1, r5, #0x18
	ldr r0, [r6, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	mov r1, #0
	bl ov96_021EAB38
	ldr r0, [sp, #0xc]
	mov r1, #0
	bl ov96_021EAB38
	add r7, r7, #1
	add r4, r4, #3
	add r5, r5, #3
	cmp r7, #4
	blt _021ECA84
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl ov96_021EC790
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021ECA70


	thumb_func_start ov96_021ECAC4
ov96_021ECAC4: ; 0x021ECAC4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r7, r0, #0
	str r0, [sp]
	add r0, #0x20
	mov r4, #0
	add r5, r7, #0
	str r0, [sp]
_021ECAD8:
	add r0, r6, #0
	bl PokeathlonCourse_GetParticipantCount
	cmp r4, #4
	bne _021ECAF6
	mov r0, #2
	bl ov96_021EEBC8
	add r1, r0, #0
	ldr r0, [r5, #0x20]
	ldr r3, [r7]
	mov r2, #0xb
	bl ov96_021EEA88
	b _021ECB2C
_021ECAF6:
	cmp r4, r0
	bge _021ECB0A
	lsl r2, r4, #0x18
	ldr r0, [sp]
	add r1, r6, #0
	lsr r2, r2, #0x18
	mov r3, #0
	bl ov96_021EEB74
	b _021ECB2C
_021ECB0A:
	add r0, r6, #0
	add r1, r4, #0
	bl PokeathlonCourse_GetParticipantData
	ldr r0, [r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl ov96_021E8424
	bl ov96_021EEDCC
	add r1, r0, #0
	ldr r0, [r5, #0x20]
	ldr r3, [r7]
	mov r2, #0
	bl ov96_021EEA88
_021ECB2C:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #5
	blt _021ECAD8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021ECAC4


	thumb_func_start ov96_021ECB38
ov96_021ECB38: ; 0x021ECB38
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r2, #0
	str r0, [sp]
	str r1, [sp, #4]
	add r0, r1, #0
	add r1, r5, #0
	add r7, r3, #0
	bl PokeathlonCourse_GetParticipantData
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECB56
	mov r6, #1
	b _021ECB58
_021ECB56:
	mov r6, #0
_021ECB58:
	cmp r7, #1
	beq _021ECB62
	cmp r7, #2
	beq _021ECB66
	b _021ECB72
_021ECB62:
	mov r4, #0
	b _021ECB76
_021ECB66:
	cmp r6, #0
	beq _021ECB6E
	mov r4, #0xb
	b _021ECB76
_021ECB6E:
	mov r4, #0x1b
	b _021ECB76
_021ECB72:
	bl GF_AssertFail
_021ECB76:
	cmp r6, #0
	beq _021ECBA6
	ldr r0, [sp, #4]
	add r1, r5, #0
	bl PokeathlonCourse_GetParticipantData
	ldr r0, [r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl ov96_021E8424
	bl ov96_021EEDCC
	add r1, r0, #0
	ldr r0, [sp]
	lsl r2, r5, #2
	ldr r0, [r0, r2]
	lsl r2, r4, #0x18
	ldr r3, [sp, #0x20]
	lsr r2, r2, #0x18
	bl ov96_021EEA88
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021ECBA6:
	lsl r2, r5, #0x18
	ldr r0, [sp]
	ldr r1, [sp, #4]
	lsr r2, r2, #0x18
	add r3, r4, #0
	bl ov96_021EEB74
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021ECB38


	thumb_func_start ov96_021ECBB8
ov96_021ECBB8: ; 0x021ECBB8
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	mov r1, #0x70
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x70
	str r0, [sp]
	bl MI_CpuFill8
	ldr r3, [sp]
	mov r1, #0
	mov r4, #5
_021ECBD2:
	lsl r0, r4, #2
	mov r2, #0
	add r5, r7, r0
	add r6, r3, #0
_021ECBDA:
	ldr r0, [r5]
	add r2, r2, #1
	add r5, r5, #4
	stmia r6!, {r0}
	cmp r2, #4
	blt _021ECBDA
	add r1, r1, #1
	add r3, #0x1c
	add r4, r4, #4
	cmp r1, #4
	blt _021ECBD2
	ldr r0, [sp]
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021ECBB8

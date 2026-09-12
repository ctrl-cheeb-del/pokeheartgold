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

	thumb_func_start ov96_0220EAC4
ov96_0220EAC4: ; 0x0220EAC4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	ldr r0, [r0, #0x20]
	mov r1, #1
	bl ov96_021EB144
	ldr r0, [sp]
	add r0, #0xc4
	ldr r0, [r0]
	bl ov96_0221031C
	mov r4, #0
	ldr r5, [sp]
	ldr r6, _0220EB34 ; =0x0000054C
	add r7, r4, #0
_0220EAE4:
	ldr r0, [r5, r6]
	add r1, r7, #0
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r5, #0x1c
	cmp r4, #0xc
	blt _0220EAE4
	mov r0, #0
	str r0, [sp, #4]
	ldr r1, _0220EB38 ; =0x00000514
	ldr r0, [sp]
	mov r6, #0
	add r0, r0, r1
	str r0, [sp, #8]
	add r7, r6, #0
_0220EB04:
	ldr r5, [sp, #8]
	mov r4, #0
_0220EB08:
	ldr r0, [r5]
	add r1, r6, #0
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [r5, #8]
	add r1, r7, #0
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _0220EB08
	ldr r0, [sp, #8]
	add r0, #0x1c
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #2
	blt _0220EB04
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0220EB34: .word 0x0000054C
_0220EB38: .word 0x00000514
	thumb_func_end ov96_0220EAC4


	thumb_func_start ov96_0220EB3C
ov96_0220EB3C: ; 0x0220EB3C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r4, [r0, #0xc]
	ldr r5, [r0, #0x10]
	cmp r4, #0
	bne _0220EB4C
	bl GF_AssertFail
_0220EB4C:
	cmp r5, #0
	bne _0220EB54
	bl GF_AssertFail
_0220EB54:
	mov r6, #1
	str r6, [sp]
	ldr r0, _0220EC94 ; =0x00002710
	str r6, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xed
	mov r3, #0x16
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _0220EC94 ; =0x00002710
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xed
	mov r3, #0x13
	bl SpriteSystem_LoadPlttResObj
	add r0, r6, #0
	str r0, [sp]
	ldr r0, _0220EC94 ; =0x00002710
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xed
	mov r3, #0x15
	bl SpriteSystem_LoadCellResObj
	add r0, r6, #0
	str r0, [sp]
	ldr r0, _0220EC94 ; =0x00002710
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xed
	mov r3, #0x14
	bl SpriteSystem_LoadAnimResObj
	mov r0, #1
	str r0, [sp]
	mov r6, #2
	ldr r0, _0220EC98 ; =0x00002711
	str r6, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xed
	mov r3, #0x1a
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _0220EC98 ; =0x00002711
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xed
	mov r3, #0x17
	bl SpriteSystem_LoadPlttResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _0220EC98 ; =0x00002711
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xed
	mov r3, #0x19
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _0220EC98 ; =0x00002711
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xed
	mov r3, #0x18
	bl SpriteSystem_LoadAnimResObj
	mov r6, #1
	str r6, [sp]
	ldr r0, _0220EC9C ; =0x00002712
	str r6, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xed
	mov r3, #0x12
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	add r0, r6, #0
	str r0, [sp, #4]
	ldr r0, _0220EC9C ; =0x00002712
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xed
	mov r3, #0xf
	bl SpriteSystem_LoadPlttResObj
	mov r0, #1
	str r0, [sp]
	mov r6, #2
	ldr r0, _0220ECA0 ; =0x00002713
	str r6, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xed
	mov r3, #0x12
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0220ECA0 ; =0x00002713
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0xed
	mov r3, #0xf
	bl SpriteSystem_LoadPlttResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _0220EC9C ; =0x00002712
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xed
	mov r3, #0x11
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _0220EC9C ; =0x00002712
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0xed
	mov r3, #0x10
	bl SpriteSystem_LoadAnimResObj
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0220EC94: .word 0x00002710
_0220EC98: .word 0x00002711
_0220EC9C: .word 0x00002712
_0220ECA0: .word 0x00002713
	thumb_func_end ov96_0220EB3C


	thumb_func_start ov96_0220ECA4
ov96_0220ECA4: ; 0x0220ECA4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x6c
	ldr r4, _0220ED2C ; =ov96_0221CFEC
	add r7, r2, #0
	str r3, [sp]
	add r5, r0, #0
	add r6, r1, #0
	add r3, sp, #0x38
	mov r2, #6
_0220ECB6:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220ECB6
	ldr r0, [r4]
	ldr r4, _0220ED30 ; =ov96_0221D020
	str r0, [r3]
	add r3, sp, #4
	mov r2, #6
_0220ECC8:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220ECC8
	ldr r0, [r4]
	str r0, [r3]
	ldr r0, [sp, #0x88]
	cmp r0, #0
	beq _0220ECDE
	add r4, sp, #4
	b _0220ECE0
_0220ECDE:
	add r4, sp, #0x38
_0220ECE0:
	cmp r5, #0
	bne _0220ECE8
	bl GF_AssertFail
_0220ECE8:
	cmp r6, #0
	bne _0220ECF0
	bl GF_AssertFail
_0220ECF0:
	strh r7, [r4]
	ldr r0, [sp]
	mov r3, #0x1e
	strh r0, [r4, #2]
	add r0, sp, #0x70
	ldrh r1, [r0, #0x10]
	add r2, r4, #0
	lsl r3, r3, #0x10
	strh r1, [r4, #6]
	ldrh r0, [r0, #0x14]
	add r1, r6, #0
	str r0, [r4, #8]
	add r0, r5, #0
	bl SpriteSystem_NewSpriteWithYOffset
	add r4, r0, #0
	mov r1, #2
	bl ManagedSprite_SetAffineOverwriteMode
	add r0, r4, #0
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x6c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0220ED2C: .word ov96_0221CFEC
_0220ED30: .word ov96_0221D020
	thumb_func_end ov96_0220ECA4


	thumb_func_start ov96_0220ED34
ov96_0220ED34: ; 0x0220ED34
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r6, _0220ED98 ; =ov96_0221D054
	add r7, r2, #0
	str r3, [sp]
	add r5, r0, #0
	add r4, r1, #0
	add r3, sp, #4
	mov r2, #6
_0220ED46:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220ED46
	ldr r0, [r6]
	cmp r5, #0
	str r0, [r3]
	bne _0220ED5A
	bl GF_AssertFail
_0220ED5A:
	cmp r4, #0
	bne _0220ED62
	bl GF_AssertFail
_0220ED62:
	add r1, sp, #4
	strh r7, [r1]
	ldr r0, [sp]
	mov r3, #0x1e
	strh r0, [r1, #2]
	add r0, sp, #0x40
	ldrh r2, [r0, #0x10]
	lsl r3, r3, #0x10
	strh r2, [r1, #6]
	ldrh r0, [r0, #0x14]
	add r1, r4, #0
	add r2, sp, #4
	str r0, [sp, #0xc]
	add r0, r5, #0
	bl SpriteSystem_NewSpriteWithYOffset
	add r4, r0, #0
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220ED98: .word ov96_0221D054
	thumb_func_end ov96_0220ED34


	thumb_func_start ov96_0220ED9C
ov96_0220ED9C: ; 0x0220ED9C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xdc
	str r0, [sp]
	ldr r6, [r0, #8]
	ldr r0, [r0]
	add r3, sp, #8
	ldr r4, _0220EE3C ; =ov96_0221CF0C
	str r0, [sp, #4]
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _0220EE40 ; =ov96_0221D088
	add r3, sp, #0x18
	mov r2, #0x18
_0220EDC2:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220EDC2
	ldr r0, [r4]
	ldr r5, _0220EE44 ; =ov96_0221CF58
	str r0, [r3]
	mov r7, #0
	add r4, sp, #0x18
_0220EDD4:
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
	ldr r3, [sp, #4]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	add r7, r7, #1
	add r4, #0x1c
	add r5, r5, #4
	cmp r7, #7
	blt _0220EDD4
	ldr r3, [sp]
	ldr r2, _0220EE48 ; =0x00000135
	ldr r3, [r3]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	ldr r1, [sp]
	str r0, [r1, #0x18]
	add r0, r1, #0
	ldr r0, [r0]
	bl MessageFormat_New
	ldr r1, [sp]
	str r0, [r1, #0x14]
	ldr r1, [r1]
	mov r0, #4
	bl FontID_Alloc
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add sp, #0xdc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0220EE3C: .word ov96_0221CF0C
_0220EE40: .word ov96_0221D088
_0220EE44: .word ov96_0221CF58
_0220EE48: .word 0x00000135
	thumb_func_end ov96_0220ED9C

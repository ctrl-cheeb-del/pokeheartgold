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

	thumb_func_start ov96_0220E974
ov96_0220E974: ; 0x0220E974
	ldr r2, [r0]
	neg r3, r1
	cmp r2, #0
	ble _0220E984
	cmp r2, r1
	ble _0220E98A
	str r1, [r0]
	b _0220E98A
_0220E984:
	cmp r2, r3
	bge _0220E98A
	str r3, [r0]
_0220E98A:
	ldr r2, [r0, #4]
	cmp r2, #0
	ble _0220E998
	cmp r2, r1
	ble _0220E99E
	str r1, [r0, #4]
	bx lr
_0220E998:
	cmp r2, r3
	bge _0220E99E
	str r3, [r0, #4]
_0220E99E:
	bx lr
	thumb_func_end ov96_0220E974


	thumb_func_start ov96_0220E9A0
ov96_0220E9A0: ; 0x0220E9A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r1, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r5, [r4, #0x14]
	ldr r6, [r4, #0x18]
	add r0, #0x24
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, r7, #0
	mov r3, #3
	bl BufferIntegerAsString
	ldr r3, [r4]
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #0xa0
	bl ReadMsgData_ExpandPlaceholders
	add r5, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0220EA04 ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #0x24
	add r2, r5, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl String_Delete
	add r4, #0x24
	add r0, r4, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220EA04: .word 0x000F0E00
	thumb_func_end ov96_0220E9A0


	thumb_func_start ov96_0220EA08
ov96_0220EA08: ; 0x0220EA08
	push {r3, r4, lr}
	sub sp, #0x4c
	ldr r3, _0220EA94 ; =ov96_0221CF40
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x34
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _0220EA98 ; =ov96_0221CF74
	add r2, sp, #0x14
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _0220EA9C ; =ov96_0221CF2C
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
	str r0, [r4, #0xc]
	bl SpriteManager_New
	str r0, [r4, #0x10]
	ldr r0, [r4, #0xc]
	add r1, sp, #0x14
	add r2, sp, #0
	mov r3, #0x20
	bl SpriteSystem_Init
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	mov r2, #0x80
	bl SpriteSystem_InitSprites
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	add r2, sp, #0x34
	bl SpriteSystem_InitManagerWithCapacities
	ldr r0, [r4, #0xc]
	bl SpriteSystem_GetRenderer
	mov r2, #0x1e
	mov r1, #0
	lsl r2, r2, #0x10
	bl G2dRenderer_SetSubSurfaceCoords
	ldr r0, [r4]
	ldr r1, _0220EAA0 ; =0x00000AA7
	mov r2, #1
	bl ov96_021E9A78
	str r0, [r4, #0x1c]
	add sp, #0x4c
	pop {r3, r4, pc}
	.balign 4, 0
_0220EA94: .word ov96_0221CF40
_0220EA98: .word ov96_0221CF74
_0220EA9C: .word ov96_0221CF2C
_0220EAA0: .word 0x00000AA7
	thumb_func_end ov96_0220EA08


	thumb_func_start ov96_0220EAA4
ov96_0220EAA4: ; 0x0220EAA4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x20]
	bl ov96_021EA894
	ldr r0, [r4, #0x1c]
	bl ov96_021E9C0C
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	bl SpriteSystem_FreeResourcesAndManager
	ldr r0, [r4, #0xc]
	bl SpriteSystem_Free
	pop {r4, pc}
	thumb_func_end ov96_0220EAA4


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


	thumb_func_start ov96_0220EE4C
ov96_0220EE4C: ; 0x0220EE4C
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r0, #0x24
	bl RemoveWindow
	ldr r0, [r6, #0x14]
	bl MessageFormat_Delete
	ldr r0, [r6, #0x18]
	bl DestroyMsgData
	ldr r5, _0220EE88 ; =ov96_0221CF58
	mov r4, #0
_0220EE66:
	ldr r1, [r5]
	ldr r0, [r6, #8]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl FreeBgTilemapBuffer
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #7
	blt _0220EE66
	mov r0, #4
	bl FontID_Release
	ldr r0, [r6, #8]
	bl Heap_Free
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0220EE88: .word ov96_0221CF58
	thumb_func_end ov96_0220EE4C


	thumb_func_start ov96_0220EE8C
ov96_0220EE8C: ; 0x0220EE8C
	push {r4, lr}
	sub sp, #0x10
	mov r3, #0
	str r3, [sp]
	add r4, r0, #0
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #4
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xed
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r4]
	mov r1, #2
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xed
	bl GfGfxLoader_LoadCharData
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #5
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xed
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4]
	add r3, r1, #0
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xed
	bl GfGfxLoader_LoadScrnData
	mov r1, #0
	str r1, [sp]
	ldr r0, [r4]
	add r2, r1, #0
	str r0, [sp, #4]
	mov r0, #0xed
	add r3, r1, #0
	bl GfGfxLoader_GXLoadPal
	ldr r0, [r4, #8]
	mov r1, #1
	mov r2, #4
	mov r3, #8
	bl ScheduleSetBgPosText
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
	ldr r2, [r4, #8]
	mov r0, #0xed
	add r3, r1, #0
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #0xb
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xed
	mov r3, #5
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #0xb
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xed
	mov r3, #6
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #5
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xed
	mov r3, #4
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #0xc
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xed
	mov r3, #5
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #0xd
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xed
	mov r3, #6
	bl GfGfxLoader_LoadScrnData
	mov r3, #0
	str r3, [sp]
	ldr r0, [r4]
	mov r1, #3
	str r0, [sp, #4]
	mov r0, #0xed
	mov r2, #4
	bl GfGfxLoader_GXLoadPal
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220EE8C


	thumb_func_start ov96_0220EFD0
ov96_0220EFD0: ; 0x0220EFD0
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	cmp r5, #0
	bne _0220EFE2
	bl GF_AssertFail
_0220EFE2:
	cmp r4, #0
	bne _0220EFEA
	bl GF_AssertFail
_0220EFEA:
	ldrb r0, [r5]
	add r0, r0, #1
	strb r0, [r5]
	ldrb r0, [r5]
	cmp r0, #4
	blo _0220F038
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	ldrb r1, [r5, #1]
	mov r0, #0xed
	add r2, r4, #0
	add r1, r1, #5
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	ldrb r1, [r5, #1]
	mov r0, #0xed
	add r2, r4, #0
	add r1, r1, #5
	mov r3, #4
	bl GfGfxLoader_LoadScrnData
	ldrb r0, [r5, #1]
	mov r1, #6
	add r0, r0, #1
	bl _s32_div_f
	strb r1, [r5, #1]
	mov r0, #0
	strb r0, [r5]
_0220F038:
	add sp, #0x10
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_0220EFD0


	thumb_func_start ov96_0220F03C
ov96_0220F03C: ; 0x0220F03C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r7, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #0xc]
	ldr r0, [sp]
	bl ov96_021E5F24
	cmp r0, #0
	beq _0220F05C
	b _0220F1A4
_0220F05C:
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #4]
	ldr r0, [r0, #0x20]
	lsr r0, r0, #0x1f
	beq _0220F07E
	add r7, #0xcc
	ldr r1, [sp]
	add r0, r7, #0
	bl ov96_0220FA18
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0220F07E:
	ldr r0, _0220F1A8 ; =0x0000050C
	ldr r1, [r7, r0]
	cmp r1, #0
	ble _0220F0AA
	sub r1, r1, #1
	str r1, [r7, r0]
	ldr r0, [r7, r0]
	mov r1, #0x1e
	add r0, #0x1e
	bl _s32_div_f
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	ldr r1, [r0, #0x1c]
	ldr r0, _0220F1AC ; =0xC0FFFFFF
	and r1, r0
	ldr r0, [sp, #8]
	lsl r0, r0, #0x1a
	lsr r0, r0, #2
	orr r1, r0
	ldr r0, [sp, #4]
	str r1, [r0, #0x1c]
_0220F0AA:
	ldr r0, [sp, #0xc]
	add r0, #0x50
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [sp, #0xc]
	bl ov96_021E8A20
	add r3, r0, #0
	mov r2, #4
_0220F0BE:
	ldmia r3!, {r0, r1}
	stmia r4!, {r0, r1}
	sub r2, r2, #1
	bne _0220F0BE
	ldr r0, [r3]
	mov r6, #0
	str r0, [r4]
	ldr r4, [sp, #0xc]
	mov r0, #0x57
	lsl r0, r0, #2
	add r4, #0x50
	add r5, r7, r0
_0220F0D6:
	add r0, r4, #0
	bl ov96_021E8A20
	add r2, r0, #0
	ldr r0, [r2]
	ldr r1, [r5, #4]
	lsl r0, r0, #0xf
	lsr r0, r0, #0x1f
	beq _0220F13A
	lsl r0, r1, #0x11
	lsr r3, r0, #0x1f
	beq _0220F0FC
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1f
	beq _0220F0FC
	ldr r0, _0220F1B0 ; =0xFFFFBFFF
	and r0, r1
	str r0, [r5, #4]
	b _0220F114
_0220F0FC:
	cmp r3, #0
	bne _0220F114
	ldr r1, [r5, #4]
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1f
	bne _0220F114
	mov r0, #1
	lsl r0, r0, #0xe
	orr r1, r0
	lsl r0, r0, #1
	orr r0, r1
	str r0, [r5, #4]
_0220F114:
	ldr r0, [r2]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	strh r0, [r5]
	ldr r0, [r2]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x18
	strh r0, [r5, #2]
	ldr r1, [r5, #4]
	ldr r0, _0220F1B4 ; =0xFFFFC000
	and r0, r1
	lsl r1, r1, #0x12
	lsr r1, r1, #0x12
	add r2, r1, #1
	ldr r1, _0220F1B8 ; =0x00003FFF
	and r1, r2
	orr r0, r1
	str r0, [r5, #4]
	b _0220F156
_0220F13A:
	ldr r0, _0220F1BC ; =0xE000FFFF
	and r0, r1
	lsl r1, r1, #0x12
	lsr r1, r1, #0x12
	lsl r1, r1, #0x13
	lsr r1, r1, #3
	orr r1, r0
	ldr r0, _0220F1B4 ; =0xFFFFC000
	and r1, r0
	sub r0, r0, #1
	and r1, r0
	ldr r0, _0220F1C0 ; =0xFFFF7FFF
	and r0, r1
	str r0, [r5, #4]
_0220F156:
	add r6, r6, #1
	add r4, #0x28
	add r5, #0xe4
	cmp r6, #4
	blt _0220F0D6
	add r0, r7, #0
	add r0, #0xc8
	ldr r0, [r0]
	bl ov96_02210858
	ldr r0, _0220F1C4 ; =0x000004EC
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #8]
	add r0, r7, r0
	bl ov96_02210030
	mov r0, #0x57
	lsl r0, r0, #2
	ldr r1, [sp]
	add r0, r7, r0
	bl ov96_0220F8C8
	ldr r0, _0220F1A8 ; =0x0000050C
	ldr r0, [r7, r0]
	cmp r0, #0
	bgt _0220F19A
	ldr r0, [sp, #4]
	ldr r1, [r0, #0x20]
	ldr r0, _0220F1C8 ; =0x7FFFFFFF
	and r1, r0
	add r0, r0, #1
	orr r1, r0
	ldr r0, [sp, #4]
	str r1, [r0, #0x20]
_0220F19A:
	add r7, #0xcc
	ldr r1, [sp]
	add r0, r7, #0
	bl ov96_0220FA18
_0220F1A4:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220F1A8: .word 0x0000050C
_0220F1AC: .word 0xC0FFFFFF
_0220F1B0: .word 0xFFFFBFFF
_0220F1B4: .word 0xFFFFC000
_0220F1B8: .word 0x00003FFF
_0220F1BC: .word 0xE000FFFF
_0220F1C0: .word 0xFFFF7FFF
_0220F1C4: .word 0x000004EC
_0220F1C8: .word 0x7FFFFFFF
	thumb_func_end ov96_0220F03C


	thumb_func_start ov96_0220F1CC
ov96_0220F1CC: ; 0x0220F1CC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r4, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r7, r0, #0
	add r0, r4, #0
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [r7, #0x20]
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0220F20C
	add r0, r6, #0
	bl ov96_0220EAC4
	add r0, r5, #0
	bl ov96_021E65A4
	add r0, r5, #0
	bl ov96_0220E2A8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0220F20C:
	bl System_GetTouchNew
	cmp r0, #0
	beq _0220F22E
	add r0, r5, #0
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	lsl r1, r1, #0x18
	str r0, [sp]
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl ov96_021E8228
_0220F22E:
	bl System_GetTouchHeld
	cmp r0, #0
	ldr r1, [r4]
	beq _0220F25C
	mov r0, #0xff
	bic r1, r0
	ldr r0, _0220F274 ; =gSystem + 0x40
	ldrh r2, [r0, #0x20]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	orr r2, r1
	str r2, [r4]
	ldrh r0, [r0, #0x22]
	ldr r1, _0220F278 ; =0xFFFF00FF
	lsl r0, r0, #0x18
	and r1, r2
	lsr r0, r0, #0x10
	orr r1, r0
	mov r0, #1
	lsl r0, r0, #0x10
	orr r0, r1
	b _0220F260
_0220F25C:
	ldr r0, _0220F27C ; =0xFFFEFFFF
	and r0, r1
_0220F260:
	str r0, [r4]
	mov r0, #0x51
	lsl r0, r0, #4
	add r0, r6, r0
	add r1, r5, #0
	bl ov96_0221013C
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220F274: .word gSystem + 0x40
_0220F278: .word 0xFFFF00FF
_0220F27C: .word 0xFFFEFFFF
	thumb_func_end ov96_0220F1CC


	thumb_func_start ov96_0220F280
ov96_0220F280: ; 0x0220F280
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x58
	add r7, r0, #0
	add r0, sp, #8
	mov r1, #0xaa
	mov r2, #7
	bl ReadWholeNarcMemberByIdPair
	mov r0, #0
	str r0, [sp]
_0220F294:
	ldr r0, [sp]
	mov r6, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
_0220F29E:
	ldr r1, [sp]
	add r0, r7, #0
	add r2, r6, #0
	bl ov96_021E60D8
	lsl r2, r6, #0x18
	add r4, r0, #0
	ldr r1, [sp, #4]
	add r0, r7, #0
	lsr r2, r2, #0x18
	bl ov96_0220F378
	add r5, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #5
	blo _0220F2C2
	bl GF_AssertFail
_0220F2C2:
	ldrb r0, [r4]
	cmp r0, #5
	blo _0220F2CC
	bl GF_AssertFail
_0220F2CC:
	ldrb r0, [r4, #1]
	cmp r0, #5
	blo _0220F2D6
	bl GF_AssertFail
_0220F2D6:
	ldrb r0, [r4, #2]
	strb r0, [r5, #2]
	ldrb r0, [r4, #2]
	lsl r1, r0, #2
	add r0, sp, #8
	ldr r0, [r0, r1]
	strb r0, [r5]
	ldrb r0, [r4, #2]
	lsl r1, r0, #2
	add r0, sp, #8
	add r0, r0, r1
	ldr r0, [r0, #0x14]
	strb r0, [r5, #1]
	ldrb r0, [r4]
	lsl r1, r0, #2
	add r0, sp, #8
	add r0, r0, r1
	ldr r0, [r0, #0x28]
	cmp r0, #0
	ble _0220F310
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0220F31E
_0220F310:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0220F31E:
	bl _ffix
	mov r1, #0xa
	bl _s32_div_f
	str r0, [r5, #4]
	ldrb r0, [r4, #1]
	lsl r1, r0, #2
	add r0, sp, #8
	add r0, r0, r1
	ldr r0, [r0, #0x3c]
	cmp r0, #0
	ble _0220F34A
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0220F358
_0220F34A:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0220F358:
	bl _ffix
	mov r1, #0xa
	bl _s32_div_f
	add r6, r6, #1
	str r0, [r5, #8]
	cmp r6, #3
	blt _0220F29E
	ldr r0, [sp]
	add r0, r0, #1
	str r0, [sp]
	cmp r0, #4
	blt _0220F294
	add sp, #0x58
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220F280


	thumb_func_start ov96_0220F378
ov96_0220F378: ; 0x0220F378
	push {r4, r5, r6, lr}
	add r5, r1, #0
	add r6, r2, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	bne _0220F38A
	bl GF_AssertFail
_0220F38A:
	cmp r5, #4
	blo _0220F392
	bl GF_AssertFail
_0220F392:
	cmp r6, #3
	blo _0220F39A
	bl GF_AssertFail
_0220F39A:
	lsl r0, r5, #1
	add r0, r5, r0
	add r1, r6, r0
	mov r0, #0xc
	add r4, #0x34
	mul r0, r1
	add r4, r4, r0
	bne _0220F3AE
	bl GF_AssertFail
_0220F3AE:
	add r0, r4, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_0220F378

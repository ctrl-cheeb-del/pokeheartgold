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

	thumb_func_start ov96_021F83DC
ov96_021F83DC: ; 0x021F83DC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetCurrentParticipantIndex
	add r4, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetMode
	cmp r0, #0
	bne _021F83F4
	add r4, #0xf6
	b _021F83F6
_021F83F4:
	add r4, #0xf9
_021F83F6:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021F83DC


	thumb_func_start ov96_021F83FC
ov96_021F83FC: ; 0x021F83FC
	push {r4, r5, r6, lr}
	add r6, r0, #0
	bl PokeathlonCourse_GetCurrentParticipantIndex
	add r4, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	add r5, r0, #0
	ldrb r0, [r5]
	cmp r0, #5
	blo _021F841E
	bl GF_AssertFail
_021F841E:
	add r0, r6, #0
	bl PokeathlonCourse_GetMode
	cmp r0, #0
	ldrb r2, [r5]
	bne _021F8438
	lsl r0, r4, #2
	add r1, r4, r0
	mov r0, #1
	lsl r0, r0, #8
	add r0, r1, r0
	add r0, r2, r0
	pop {r4, r5, r6, pc}
_021F8438:
	lsl r0, r4, #2
	add r1, r4, r0
	ldr r0, _021F8444 ; =0x0000010F
	add r0, r1, r0
	add r0, r2, r0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021F8444: .word 0x0000010F
	thumb_func_end ov96_021F83FC


	thumb_func_start ov96_021F8448
ov96_021F8448: ; 0x021F8448
	push {r3, r4, lr}
	sub sp, #0x4c
	ldr r3, _021F84D8 ; =ov96_0221C2D8
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x34
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _021F84DC ; =ov96_0221C2F0
	add r2, sp, #0x14
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _021F84E0 ; =ov96_0221C2C4
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	mov r0, #0x1a
	str r0, [sp]
	ldr r0, [r4]
	bl SpriteSystem_Alloc
	add r1, r4, #0
	add r1, #0x94
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	bl SpriteManager_New
	add r1, r4, #0
	add r1, #0x98
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	add r1, sp, #0x14
	add r2, sp, #0
	mov r3, #0x20
	bl SpriteSystem_Init
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x94
	add r1, #0x98
	ldr r0, [r0]
	ldr r1, [r1]
	mov r2, #2
	bl SpriteSystem_InitSprites
	add r0, r4, #0
	add r0, #0x94
	add r4, #0x98
	ldr r0, [r0]
	ldr r1, [r4]
	add r2, sp, #0x34
	bl SpriteSystem_InitManagerWithCapacities
	add sp, #0x4c
	pop {r3, r4, pc}
	.balign 4, 0
_021F84D8: .word ov96_0221C2D8
_021F84DC: .word ov96_0221C2F0
_021F84E0: .word ov96_0221C2C4
	thumb_func_end ov96_021F8448


	thumb_func_start ov96_021F84E4
ov96_021F84E4: ; 0x021F84E4
	push {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	add r5, r0, #0
	add r7, r4, #0
_021F84EC:
	lsl r6, r4, #2
	add r0, r5, r6
	add r0, #0x9c
	ldr r0, [r0]
	cmp r0, #0
	beq _021F8502
	bl Sprite_DeleteAndFreeResources
	add r0, r5, r6
	add r0, #0x9c
	str r7, [r0]
_021F8502:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _021F84EC
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0x94
	add r1, #0x98
	ldr r0, [r0]
	ldr r1, [r1]
	bl SpriteSystem_FreeResourcesAndManager
	add r5, #0x94
	ldr r0, [r5]
	bl SpriteSystem_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F84E4


	thumb_func_start ov96_021F8528
ov96_021F8528: ; 0x021F8528
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r1, r0, #0
	add r1, #0x94
	add r0, #0x98
	ldr r5, [r0]
	ldr r4, [r1]
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0xfa
	lsl r0, r0, #2
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x9a
	mov r3, #9
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xfa
	lsl r0, r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x9a
	mov r3, #8
	bl SpriteSystem_LoadPlttResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0xfa
	lsl r0, r0, #2
	str r0, [sp, #4]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x9a
	mov r3, #0xa
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	mov r0, #0xfa
	lsl r0, r0, #2
	str r0, [sp, #4]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x9a
	mov r3, #0xb
	bl SpriteSystem_LoadAnimResObj
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021F8528


	thumb_func_start ov96_021F85A0
ov96_021F85A0: ; 0x021F85A0
	push {r3, r4, lr}
	sub sp, #0x34
	add r4, r0, #0
	add r2, sp, #0
	mov r0, #0
	add r3, r2, #0
	add r1, r0, #0
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	str r0, [r3]
	mov r0, #0xfa
	lsl r0, r0, #2
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	mov r0, #2
	str r0, [sp, #0x10]
	mov r0, #1
	str r0, [sp, #0x2c]
	mov r1, #0xe0
	add r0, sp, #0
	strh r1, [r0]
	mov r1, #0x70
	strh r1, [r0, #2]
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x94
	add r1, #0x98
	ldr r0, [r0]
	ldr r1, [r1]
	bl SpriteSystem_NewSprite
	add r4, #0x9c
	str r0, [r4]
	add sp, #0x34
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F85A0


	thumb_func_start ov96_021F85F4
ov96_021F85F4: ; 0x021F85F4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x14]
	add r0, r7, #0
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #0x10]
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #8]
	add r0, r7, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0x14]
	add r0, #0xa4
	ldr r0, [r0]
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	mov r0, #0
	str r0, [sp, #4]
	cmp r1, #0
	bne _021F86AC
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #0xc]
	strb r6, [r0, #1]
	ldr r0, [sp, #0x10]
	add r0, #0x50
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [sp, #0x10]
	bl ov96_021E8A20
	mov r2, #0x24
_021F8650:
	ldrb r1, [r0]
	add r0, r0, #1
	strb r1, [r4]
	add r4, r4, #1
	sub r2, r2, #1
	bne _021F8650
	add r0, r7, #0
	mov r4, #0
	bl PokeathlonCourse_GetParticipantCount
	cmp r0, #0
	ble _021F869A
	ldr r5, [sp, #0x10]
	add r5, #0x50
_021F866C:
	add r0, r5, #0
	bl ov96_021E8A20
	ldrb r1, [r0]
	cmp r1, r6
	blo _021F867E
	ldrb r1, [r0, #1]
	cmp r1, #1
	bne _021F8682
_021F867E:
	mov r1, #1
	str r1, [sp, #4]
_021F8682:
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne _021F868C
	mov r0, #0
	str r0, [sp]
_021F868C:
	add r0, r7, #0
	add r5, #0x28
	add r4, r4, #1
	bl PokeathlonCourse_GetParticipantCount
	cmp r4, r0
	blt _021F866C
_021F869A:
	ldr r0, [sp]
	cmp r0, #0
	beq _021F86A6
	ldr r0, [sp, #0xc]
	mov r1, #1
	strb r1, [r0, #2]
_021F86A6:
	ldr r1, [sp, #4]
	ldr r0, [sp, #0xc]
	strb r1, [r0, #3]
_021F86AC:
	ldr r0, [sp, #0x10]
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [sp, #0x14]
	strb r6, [r4]
	ldr r0, [r0, #0x18]
	bl ov96_021EEA80
	strb r0, [r4, #1]
	ldr r0, [sp, #0x14]
	add r0, #0xa8
	str r0, [sp, #0x14]
	ldr r0, [r0]
	strb r0, [r4, #2]
	ldr r0, [sp, #8]
	ldrb r0, [r0, #3]
	cmp r0, #0
	beq _021F86E0
	ldr r0, [sp, #8]
	ldrb r0, [r0, #1]
	cmp r6, r0
	blo _021F86E0
	add sp, #0x18
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021F86E0:
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F85F4


	thumb_func_start ov96_021F86E8
ov96_021F86E8: ; 0x021F86E8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	mov r1, #0xcd
	lsl r1, r1, #2
	add r7, r0, #0
	add r6, r2, #0
	bl Heap_Alloc
	mov r2, #0xcd
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0xa
	add r1, r7, #0
	str r7, [r4]
	bl FontSystem_NewInit
	str r0, [r4, #0x10]
	str r5, [r4, #8]
	str r6, [r4, #4]
	mov r0, #0
	add r1, r4, #0
_021F8718:
	str r0, [r1, #0x48]
	add r0, r0, #1
	add r1, #0x48
	cmp r0, #5
	blt _021F8718
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F86E8


	thumb_func_start ov96_021F8728
ov96_021F8728: ; 0x021F8728
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r4, r0, #0
	str r0, [sp]
	mov r7, #0
	add r6, #0x24
	add r4, #0x34
	add r5, r0, #0
_021F8738:
	add r0, r6, #0
	bl ov96_021F8E94
	add r0, r4, #0
	bl ov96_021F8E94
	ldr r0, [r5, #0x14]
	bl Sprite_Delete
	ldr r0, [r5, #0x18]
	bl Sprite_Delete
	ldr r0, [r5, #0x1c]
	bl Sprite_Delete
	ldr r0, [r5, #0x20]
	bl Sprite_Delete
	add r7, r7, #1
	add r6, #0x48
	add r4, #0x48
	add r5, #0x48
	cmp r7, #5
	blt _021F8738
	mov r1, #0xbf
	ldr r0, [sp]
	lsl r1, r1, #2
	mov r4, #0
	add r5, r0, r1
_021F8772:
	ldr r0, [r5, #0x10]
	bl sub_02013938
	add r0, r5, #0
	bl RemoveWindow
	add r4, r4, #1
	add r5, #0x18
	cmp r4, #2
	blt _021F8772
	ldr r0, [sp]
	ldr r0, [r0, #0x10]
	bl sub_020135AC
	mov r1, #0xb
	ldr r0, [sp]
	lsl r1, r1, #6
	ldr r0, [r0, r1]
	bl SpriteTransfer_DeleteCharTransferTask
	mov r1, #0xb1
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r6, #0xaa
	ldr r4, [sp]
	mov r5, #0
	lsl r6, r6, #2
_021F87AE:
	ldr r0, [r4, r6]
	bl Destroy2DGfxResObjMan
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #6
	blt _021F87AE
	mov r1, #0x5f
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl SpriteList_Delete
	ldr r0, [sp]
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F8728

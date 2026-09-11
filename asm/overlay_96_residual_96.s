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

	thumb_func_start ov96_0220B79C
ov96_0220B79C: ; 0x0220B79C
	push {r4, lr}
	add r4, r0, #0
	bne _0220B7A6
	bl GF_AssertFail
_0220B7A6:
	ldr r0, [r4, #0x44]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B79C


	thumb_func_start ov96_0220B7B4
ov96_0220B7B4: ; 0x0220B7B4
	push {r4, lr}
	add r4, r0, #0
	bne _0220B7BE
	bl GF_AssertFail
_0220B7BE:
	ldr r0, [r4, #0x40]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B7B4


	thumb_func_start ov96_0220B7CC
ov96_0220B7CC: ; 0x0220B7CC
	push {r4, lr}
	add r4, r0, #0
	bne _0220B7D6
	bl GF_AssertFail
_0220B7D6:
	ldr r1, [r4, #0x40]
	mov r0, #1
	lsl r1, r1, #0x16
	lsr r1, r1, #0x18
	beq _0220B7F0
	cmp r1, #1
	bne _0220B7EE
	ldr r1, [r4, #0x44]
	lsl r1, r1, #8
	lsr r1, r1, #0x18
	cmp r1, #2
	bhs _0220B7F0
_0220B7EE:
	mov r0, #0
_0220B7F0:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B7CC


	thumb_func_start ov96_0220B7F4
ov96_0220B7F4: ; 0x0220B7F4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x68
	add r7, r3, #0
	add r4, r0, #0
	add r0, r7, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x14]
	add r0, sp, #0x2c
	mov r1, #0xaa
	mov r2, #5
	bl ReadWholeNarcMemberByIdPair
	add r0, r4, #0
	mov r1, #0xc8
	bl Heap_Alloc
	str r0, [sp, #0x1c]
	mov r1, #0
	mov r2, #0xc8
	bl MI_CpuFill8
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0xc]
	str r4, [r0]
	str r1, [r0, #4]
	ldr r1, [sp, #0x10]
	str r1, [r0, #8]
	str r7, [r0, #0xc]
	ldr r0, [sp, #0x80]
	ldr r1, [sp, #0x1c]
	str r0, [r1, #0x10]
	ldr r1, [sp, #0x14]
	bl ov96_0220C844
	ldr r0, [sp, #0x1c]
	mov r6, #0
	str r0, [sp, #0x18]
	add r0, #0x14
	str r0, [sp, #0x18]
_0220B84C:
	ldr r0, [sp, #0x14]
	cmp r6, r0
	beq _0220B892
	mov r4, #0
	add r5, sp, #0x20
_0220B856:
	add r0, r7, #0
	add r1, r6, #0
	add r2, r4, #0
	bl ov96_021E60D8
	ldrb r0, [r0, #3]
	add r4, r4, #1
	lsl r1, r0, #2
	add r0, sp, #0x2c
	add r0, r0, r1
	ldr r0, [r0, #0x14]
	cmp r4, #3
	stmia r5!, {r0}
	blt _0220B856
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	str r7, [sp, #4]
	add r0, sp, #0x20
	str r0, [sp, #8]
	ldr r3, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	ldr r3, [r3, #0x10]
	bl ov96_0220BE28
	ldr r0, [sp, #0x18]
	add r0, #0x3c
	str r0, [sp, #0x18]
_0220B892:
	add r6, r6, #1
	cmp r6, #4
	blt _0220B84C
	ldr r0, [sp, #0x1c]
	add sp, #0x68
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B7F4


	thumb_func_start ov96_0220B8A0
ov96_0220B8A0: ; 0x0220B8A0
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	cmp r0, #0
	bne _0220B8AC
	bl GF_AssertFail
_0220B8AC:
	ldr r6, [sp]
	mov r7, #0
_0220B8B0:
	mov r4, #0
	add r5, r6, #0
_0220B8B4:
	ldr r0, [r5, #0x30]
	cmp r0, #0
	beq _0220B8BE
	bl Sprite_DeleteAndFreeResources
_0220B8BE:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blt _0220B8B4
	add r7, r7, #1
	add r6, #0x3c
	cmp r7, #3
	blt _0220B8B0
	ldr r0, [sp]
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B8A0


	thumb_func_start ov96_0220B8D8
ov96_0220B8D8: ; 0x0220B8D8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r4, #0
	add r5, #0x14
_0220B8E0:
	add r0, r5, #0
	bl ov96_0220C40C
	add r4, r4, #1
	add r5, #0x3c
	cmp r4, #3
	blt _0220B8E0
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_0220B8D8


	thumb_func_start ov96_0220B8F0
ov96_0220B8F0: ; 0x0220B8F0
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0
	add r6, r0, #0
	str r1, [sp]
	add r6, #0x14
	add r7, r1, #0
_0220B8FC:
	ldr r0, [r6, #0x38]
	mov r1, #0xc
	lsl r0, r0, #7
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r0, [r0, #4]
	bl ov96_021EAC5C
	ldr r0, [r6, #0x34]
	cmp r0, #0
	beq _0220B91C
	bl SysTask_Destroy
	mov r0, #0
	str r0, [r6, #0x34]
_0220B91C:
	mov r4, #0
	add r5, r6, #0
_0220B920:
	ldr r0, [r5, #0x1c]
	add r1, r7, #0
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blt _0220B920
	ldr r0, [sp]
	add r6, #0x3c
	add r0, r0, #1
	str r0, [sp]
	cmp r0, #3
	blt _0220B8FC
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B8F0


	thumb_func_start ov96_0220B940
ov96_0220B940: ; 0x0220B940
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #0
	bne _0220B95A
	ldr r0, [r4, #0x10]
	bl ManagedSprite_IsAnimated
	cmp r0, #0
	bne _0220B95A
	ldr r0, [r4, #0x10]
	mov r1, #1
	bl ManagedSprite_SetAnim
_0220B95A:
	pop {r4, pc}
	thumb_func_end ov96_0220B940


	thumb_func_start ov96_0220B95C
ov96_0220B95C: ; 0x0220B95C
	push {r3, lr}
	ldr r2, [r0, #0x44]
	ldr r1, _0220B984 ; =0xFF00FFFF
	and r1, r2
	lsl r2, r2, #8
	lsr r2, r2, #0x18
	add r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #8
	orr r1, r2
	str r1, [r0, #0x44]
	lsl r1, r1, #8
	lsr r1, r1, #0x18
	cmp r1, #0xa
	blo _0220B980
	mov r1, #0
	bl ov96_0220C578
_0220B980:
	pop {r3, pc}
	nop
_0220B984: .word 0xFF00FFFF
	thumb_func_end ov96_0220B95C


	thumb_func_start ov96_0220B988
ov96_0220B988: ; 0x0220B988
	push {r3, lr}
	ldr r1, [r0, #0x40]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #2
	add r1, r0, r1
	ldr r1, [r1, #0x34]
	lsl r1, r1, #6
	lsr r1, r1, #0x18
	cmp r1, #8
	blo _0220B9A4
	mov r1, #0
	bl ov96_0220C578
_0220B9A4:
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B988


	thumb_func_start ov96_0220B9A8
ov96_0220B9A8: ; 0x0220B9A8
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r1, [r4, #0x44]
	lsl r2, r1, #0x10
	lsr r2, r2, #0x1a
	cmp r2, #6
	bls _0220B9BA
	b _0220BD1A
_0220B9BA:
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0220B9C6: ; jump table
	.short _0220B9D4 - _0220B9C6 - 2 ; case 0
	.short _0220BA02 - _0220B9C6 - 2 ; case 1
	.short _0220BA68 - _0220B9C6 - 2 ; case 2
	.short _0220BB4E - _0220B9C6 - 2 ; case 3
	.short _0220BC2E - _0220B9C6 - 2 ; case 4
	.short _0220BCB0 - _0220B9C6 - 2 ; case 5
	.short _0220BD10 - _0220B9C6 - 2 ; case 6
_0220B9D4:
	ldr r0, [r4, #0x1c]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r0, [r4, #0x1c]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, _0220BD24 ; =0x000008B4
	bl PlaySE
	ldr r1, [r4, #0x44]
	ldr r0, _0220BD28 ; =0xFFFF03FF
	add r2, r1, #0
	and r2, r0
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1a
	add r0, r0, #1
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x10
	orr r0, r2
	add sp, #0x10
	str r0, [r4, #0x44]
	pop {r4, r5, r6, pc}
_0220BA02:
	ldr r0, _0220BD2C ; =0x00FFFFFF
	add r2, r1, #0
	and r2, r0
	lsr r0, r1, #0x18
	add r0, r0, #1
	lsl r0, r0, #0x18
	orr r0, r2
	str r0, [r4, #0x44]
	lsr r0, r0, #0x18
	cmp r0, #2
	bhs _0220BA1A
	b _0220BD1E
_0220BA1A:
	ldr r0, [r4, #0x20]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r0, [r4, #0x20]
	mov r1, #0
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [r4, #0x20]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x10]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x14]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x18]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r1, [r4, #0x44]
	ldr r0, _0220BD2C ; =0x00FFFFFF
	add r2, r1, #0
	and r2, r0
	ldr r0, _0220BD28 ; =0xFFFF03FF
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #0x10
	lsr r0, r0, #0x1a
	add r0, r0, #1
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x10
	orr r0, r1
	add sp, #0x10
	str r0, [r4, #0x44]
	pop {r4, r5, r6, pc}
_0220BA68:
	add r1, sp, #0xc
	ldr r0, [r4, #0x20]
	add r1, #2
	add r2, sp, #0xc
	bl ManagedSprite_GetPositionXY
	mov r3, #8
	add r1, sp, #4
	add r0, r3, #0
	ldrsh r5, [r1, r3]
	sub r0, #0x48
	sub r2, r0, r5
	asr r0, r2, #1
	lsr r0, r0, #0x1e
	add r0, r2, r0
	lsl r0, r0, #0xe
	asr r2, r0, #0x10
	add r0, r3, #0
	sub r0, #0x3c
	cmp r5, r0
	ble _0220BA96
	cmp r2, #0
	bne _0220BAF0
_0220BA96:
	ldr r0, [r4, #0x40]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	sub r0, r0, #1
	lsl r0, r0, #0x18
	asr r5, r0, #0x18
	bpl _0220BAA6
	mov r5, #2
_0220BAA6:
	ldr r0, [r4, #0xc]
	bl ov96_021E5F24
	add r2, r0, #0
	mov r0, #0
	lsl r2, r2, #0x18
	lsl r3, r5, #0x18
	str r0, [sp]
	add r0, r4, #0
	mov r1, #6
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl ov96_0220C54C
	mov r2, #0x28
	add r0, sp, #4
	add r3, r2, #0
	strh r2, [r0, #0xa]
	sub r3, #0x50
	strh r3, [r0, #8]
	add r0, r4, #0
	mov r1, #6
	bl ov96_0220C90C
	ldr r1, [r4, #0x44]
	ldr r0, _0220BD28 ; =0xFFFF03FF
	add r2, r1, #0
	and r2, r0
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1a
	add r0, r0, #1
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x10
	orr r0, r2
	add sp, #0x10
	str r0, [r4, #0x44]
	pop {r4, r5, r6, pc}
_0220BAF0:
	mov r6, #0xa
	add r2, r5, r2
	lsl r2, r2, #0x10
	ldrsh r1, [r1, r6]
	ldr r0, [r4, #0x20]
	asr r2, r2, #0x10
	lsl r3, r3, #0x11
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add r1, sp, #0xc
	mov r3, #1
	ldr r0, [r4, #0x28]
	add r1, #2
	add r2, sp, #0xc
	lsl r3, r3, #0x14
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #4
	mov r0, #8
	ldrsh r1, [r1, r0]
	mov r0, #0x11
	lsl r0, r0, #4
	sub r2, r0, r1
	bpl _0220BB22
	neg r2, r2
_0220BB22:
	add r1, sp, #4
	mov r0, #8
	ldrsh r3, [r1, r0]
	asr r2, r2, #2
	add r2, r3, r2
	strh r2, [r1, #8]
	ldrsh r0, [r1, r0]
	cmp r0, #0xd8
	ble _0220BB36
	mov r0, #0xd8
_0220BB36:
	add r5, sp, #4
	strh r0, [r5, #8]
	mov r2, #0xa
	mov r3, #8
	ldrsh r2, [r5, r2]
	ldrsh r3, [r5, r3]
	add r0, r4, #0
	mov r1, #6
	bl ov96_0220C90C
	add sp, #0x10
	pop {r4, r5, r6, pc}
_0220BB4E:
	add r1, sp, #8
	mov r3, #1
	ldr r0, [r4, #0x24]
	add r1, #2
	add r2, sp, #8
	lsl r3, r3, #0x14
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #4
	mov r0, #4
	ldrsh r1, [r1, r0]
	mov r0, #0x88
	sub r0, r0, r1
	bpl _0220BB6C
	neg r0, r0
_0220BB6C:
	lsl r0, r0, #0xf
	asr r5, r0, #0x10
	cmp r1, #0x88
	bge _0220BBB6
	cmp r5, #0
	bne _0220BB7A
	mov r5, #1
_0220BB7A:
	add r6, sp, #4
	mov r3, #4
	ldrsh r0, [r6, r3]
	mov r2, #6
	mov r1, #5
	add r0, r0, r5
	strh r0, [r6, #4]
	ldrsh r2, [r6, r2]
	ldrsh r3, [r6, r3]
	add r0, r4, #0
	bl ov96_0220C90C
	add r1, sp, #8
	mov r3, #1
	ldr r0, [r4, #0x28]
	add r1, #2
	add r2, sp, #8
	lsl r3, r3, #0x14
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	mov r3, #4
	ldrsh r0, [r6, r3]
	mov r1, #6
	add r0, r0, r5
	strh r0, [r6, #4]
	ldrsh r2, [r6, r1]
	ldrsh r3, [r6, r3]
	add r0, r4, #0
	bl ov96_0220C90C
_0220BBB6:
	ldr r1, [r4, #0x44]
	ldr r0, _0220BD2C ; =0x00FFFFFF
	add r2, r1, #0
	and r2, r0
	lsr r0, r1, #0x18
	add r0, r0, #1
	lsl r0, r0, #0x18
	orr r0, r2
	str r0, [r4, #0x44]
	lsr r0, r0, #0x18
	cmp r0, #4
	bhs _0220BBD0
	b _0220BD1E
_0220BBD0:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x28]
	mov r2, #0x28
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x30]
	mov r3, #0x30
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	add r0, r4, #0
	mov r1, #5
	bl ov96_0220C90C
	add r0, r4, #0
	mov r1, #6
	mov r2, #0x28
	mov r3, #0x88
	bl ov96_0220C90C
	mov r1, #0x88
	add r2, r1, #0
	mov r3, #1
	ldr r0, [r4, #0x20]
	sub r2, #0x90
	lsl r3, r3, #0x14
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, _0220BD30 ; =0x000008B5
	bl PlaySE
	ldr r1, [r4, #0x44]
	ldr r0, _0220BD2C ; =0x00FFFFFF
	add r2, r1, #0
	and r2, r0
	ldr r0, _0220BD28 ; =0xFFFF03FF
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #0x10
	lsr r0, r0, #0x1a
	add r0, r0, #1
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x10
	orr r0, r1
	add sp, #0x10
	str r0, [r4, #0x44]
	pop {r4, r5, r6, pc}
_0220BC2E:
	add r1, sp, #4
	ldr r0, [r4, #0x20]
	add r1, #2
	add r2, sp, #4
	bl ManagedSprite_GetPositionXY
	add r1, sp, #4
	mov r0, #0
	ldrsh r1, [r1, r0]
	sub r0, #0x18
	sub r0, r0, r1
	bpl _0220BC48
	neg r0, r0
_0220BC48:
	lsl r0, r0, #0x10
	asr r2, r0, #0x10
	beq _0220BC56
	lsr r0, r2, #0x1f
	add r0, r2, r0
	lsl r0, r0, #0xf
	asr r2, r0, #0x10
_0220BC56:
	add r1, sp, #4
	mov r0, #0
	ldrsh r3, [r1, r0]
	add r2, r2, #2
	add r2, r3, r2
	strh r2, [r1]
	ldrsh r2, [r1, r0]
	cmp r2, #0x70
	blt _0220BCA0
	ldr r0, _0220BD34 ; =0x000008B6
	bl PlaySE
	ldr r0, [r4, #0x20]
	mov r1, #0x88
	mov r2, #0x70
	bl ManagedSprite_SetPositionXY
	ldr r0, [r4, #0x20]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [r4, #0x1c]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r1, [r4, #0x44]
	ldr r0, _0220BD28 ; =0xFFFF03FF
	add r2, r1, #0
	and r2, r0
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1a
	add r0, r0, #1
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x10
	orr r0, r2
	add sp, #0x10
	str r0, [r4, #0x44]
	pop {r4, r5, r6, pc}
_0220BCA0:
	mov r3, #2
	ldrsh r1, [r1, r3]
	ldr r0, [r4, #0x20]
	lsl r3, r3, #0x13
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add sp, #0x10
	pop {r4, r5, r6, pc}
_0220BCB0:
	ldr r0, _0220BD2C ; =0x00FFFFFF
	add r2, r1, #0
	and r2, r0
	lsr r0, r1, #0x18
	add r0, r0, #1
	lsl r0, r0, #0x18
	orr r0, r2
	str r0, [r4, #0x44]
	lsr r0, r0, #0x18
	cmp r0, #2
	blo _0220BD1E
	ldr r0, [r4, #0x20]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0xc]
	bl ov96_021E5F24
	add r2, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r3, [r4, #0x40]
	lsl r2, r2, #0x18
	lsl r3, r3, #0x1e
	lsr r3, r3, #0x1e
	lsl r3, r3, #0x18
	add r0, r4, #0
	mov r1, #0
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl ov96_0220C54C
	ldr r1, [r4, #0x44]
	ldr r0, _0220BD2C ; =0x00FFFFFF
	add r2, r1, #0
	and r2, r0
	ldr r0, _0220BD28 ; =0xFFFF03FF
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #0x10
	lsr r0, r0, #0x1a
	add r0, r0, #1
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x10
	orr r0, r1
	add sp, #0x10
	str r0, [r4, #0x44]
	pop {r4, r5, r6, pc}
_0220BD10:
	mov r1, #0
	bl ov96_0220C578
	add sp, #0x10
	pop {r4, r5, r6, pc}
_0220BD1A:
	bl GF_AssertFail
_0220BD1E:
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_0220BD24: .word 0x000008B4
_0220BD28: .word 0xFFFF03FF
_0220BD2C: .word 0x00FFFFFF
_0220BD30: .word 0x000008B5
_0220BD34: .word 0x000008B6
	thumb_func_end ov96_0220B9A8


	thumb_func_start ov96_0220BD38
ov96_0220BD38: ; 0x0220BD38
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r0, #0
	ldr r0, [r6, #0x40]
	lsl r0, r0, #0x16
	lsr r0, r0, #0x18
	cmp r0, #3
	beq _0220BE20
	add r0, r6, #0
	str r0, [sp]
	add r0, #0x34
	add r7, r6, #0
	mov r5, #0
	str r0, [sp]
	add r7, #0x44
_0220BD56:
	ldr r0, [r6, #0x40]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	cmp r5, r0
	bne _0220BD74
	mov r0, #0x1a
	str r0, [sp, #8]
	mov r0, #0x18
	str r0, [sp, #4]
	ldr r1, [r7]
	ldr r0, _0220BE24 ; =0xFFFFFDFF
	ldr r4, [r6, #0x18]
	and r0, r1
	str r0, [r7]
	b _0220BD90
_0220BD74:
	add r0, r0, #1
	cmp r0, #3
	blt _0220BD7C
	mov r0, #0
_0220BD7C:
	cmp r0, r5
	bne _0220BD84
	mov r0, #1
	b _0220BD86
_0220BD84:
	mov r0, #0
_0220BD86:
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r4, [r0, #0x2c]
	mov r0, #0x11
	str r0, [sp, #4]
_0220BD90:
	ldr r0, [sp]
	ldr r2, [r0]
	lsl r0, r2, #6
	lsr r1, r0, #0x18
	bne _0220BDCA
	ldr r1, [sp, #8]
	add r0, r4, #0
	bl ManagedSprite_SetAnimNoRestart
	add r0, r4, #0
	bl ManagedSprite_GetDrawFlag
	cmp r0, #0
	bne _0220BDB4
	add r0, r4, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
_0220BDB4:
	mov r0, #0x89
	lsl r0, r0, #4
	bl IsSEPlaying
	cmp r0, #0
	bne _0220BE14
	mov r0, #0x89
	lsl r0, r0, #4
	bl PlaySE
	b _0220BE14
_0220BDCA:
	lsl r2, r2, #0xe
	lsr r2, r2, #0x17
	add r0, r4, #0
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	bl ov96_0220C768
	cmp r0, #0
	beq _0220BE02
	ldr r1, [sp, #4]
	add r0, r4, #0
	bl ManagedSprite_SetAnimNoRestart
	add r0, r4, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r6, #0x40]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	cmp r5, r0
	bne _0220BE14
	mov r0, #2
	ldr r1, [r7]
	lsl r0, r0, #8
	orr r0, r1
	str r0, [r7]
	b _0220BE14
_0220BE02:
	add r0, r4, #0
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r1, #1
	add r0, r4, #0
	lsl r1, r1, #0xc
	bl ManagedSprite_SetAnimSpeed
_0220BE14:
	ldr r0, [sp]
	add r5, r5, #1
	add r0, r0, #4
	str r0, [sp]
	cmp r5, #3
	blt _0220BD56
_0220BE20:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0220BE24: .word 0xFFFFFDFF
	thumb_func_end ov96_0220BD38


	thumb_func_start ov96_0220BE28
ov96_0220BE28: ; 0x0220BE28
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	mov r1, #0
	mov r2, #0x3c
	add r5, r0, #0
	str r3, [sp, #0x10]
	bl MI_CpuFill8
	add r0, sp, #0x20
	ldrb r0, [r0, #0x10]
	ldr r1, [r5, #0x38]
	str r0, [sp, #0x14]
	ldr r0, _0220BFA4 ; =0xF9FFFFFF
	and r1, r0
	ldr r0, [sp, #0x14]
	lsl r3, r0, #0x1e
	lsr r0, r3, #5
	orr r0, r1
	str r0, [r5, #0x38]
	ldr r0, [sp, #0x34]
	ldr r1, _0220BFA8 ; =0xE7FFFFFF
	str r0, [r5]
	ldr r2, [r5, #0x38]
	and r2, r1
	lsr r1, r3, #3
	orr r1, r2
	str r1, [r5, #0x38]
	bl ov96_021E5F24
	ldr r2, [r5, #0x38]
	lsl r1, r2, #5
	lsr r1, r1, #0x1e
	cmp r1, r0
	bls _0220BE84
	ldr r0, _0220BFA8 ; =0xE7FFFFFF
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #3
	lsr r0, r0, #0x1e
	sub r0, r0, #1
	lsl r0, r0, #0x1e
	lsr r0, r0, #3
	orr r0, r1
	str r0, [r5, #0x38]
_0220BE84:
	ldr r6, [sp, #0x38]
	mov r7, #0
	add r4, r5, #0
_0220BE8A:
	ldr r1, [r5, #0x38]
	ldr r0, [sp, #0x10]
	lsl r1, r1, #3
	lsr r2, r1, #0x1e
	lsl r1, r2, #1
	add r1, r2, r1
	add r1, r7, r1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	str r0, [r4, #4]
	ldr r0, [r6]
	add r7, r7, #1
	str r0, [r4, #0x10]
	add r4, r4, #4
	add r6, r6, #4
	cmp r7, #3
	blt _0220BE8A
	ldr r0, [sp, #0x34]
	bl PokeathlonCourse_GetDataCopyArea
	ldr r1, [sp, #0x14]
	mov r2, #0x28
	add r0, #0x50
	mul r2, r1
	add r0, r0, r2
	bl ov96_021E8A20
	ldr r2, [r0]
	ldr r1, _0220BFAC ; =0xFFFF00FF
	mov r3, #0x38
	and r2, r1
	ldr r1, [sp, #0x38]
	ldr r1, [r1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x10
	orr r1, r2
	str r1, [r0]
	ldr r0, [r5, #0x38]
	ldr r1, [sp, #0xc]
	lsl r0, r0, #3
	lsr r0, r0, #0x1e
	lsl r4, r0, #6
	mov r0, #0xc
	add r4, #0x48
	str r0, [sp]
	mov r0, #0x1d
	str r0, [sp, #4]
	lsl r2, r4, #0x10
	ldr r0, [sp, #8]
	asr r2, r2, #0x10
	bl ov96_0220D13C
	str r0, [r5, #0x1c]
	mov r0, #5
	str r0, [sp]
	mov r0, #0x1c
	str r0, [sp, #4]
	lsl r2, r4, #0x10
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	asr r2, r2, #0x10
	mov r3, #0x38
	bl ov96_0220D13C
	mov r1, #0
	str r0, [r5, #0x20]
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0x1f
	str r0, [sp, #4]
	lsl r2, r4, #0x10
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	asr r2, r2, #0x10
	mov r3, #0x28
	bl ov96_0220D13C
	mov r1, #1
	str r0, [r5, #0x28]
	bl ManagedSprite_SetAffineOverwriteMode
	ldr r1, _0220BFB0 ; =0x3F333333
	ldr r0, [r5, #0x28]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	ldr r0, [r5, #0x28]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x18
	str r0, [sp]
	mov r0, #0x1f
	str r0, [sp, #4]
	lsl r2, r4, #0x10
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	asr r2, r2, #0x10
	mov r3, #0x28
	bl ov96_0220D13C
	mov r1, #0
	str r0, [r5, #0x24]
	bl ManagedSprite_SetDrawFlag
	mov r0, #0xe
	str r0, [sp]
	mov r0, #0x1e
	str r0, [sp, #4]
	lsl r2, r4, #0x10
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	asr r2, r2, #0x10
	mov r3, #0x28
	bl ov96_0220D13C
	mov r1, #0
	str r0, [r5, #0x2c]
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x1b
	str r0, [sp]
	mov r0, #0x1e
	str r0, [sp, #4]
	lsl r2, r4, #0x10
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	asr r2, r2, #0x10
	mov r3, #0x28
	bl ov96_0220D13C
	mov r1, #0
	str r0, [r5, #0x30]
	bl ManagedSprite_SetDrawFlag
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220BFA4: .word 0xF9FFFFFF
_0220BFA8: .word 0xE7FFFFFF
_0220BFAC: .word 0xFFFF00FF
_0220BFB0: .word 0x3F333333
	thumb_func_end ov96_0220BE28


	thumb_func_start ov96_0220BFB4
ov96_0220BFB4: ; 0x0220BFB4
	push {r3, r4, r5, r6, r7, lr}
	ldr r2, [r0, #0x38]
	add r7, r1, #0
	lsl r1, r2, #3
	lsr r1, r1, #0x1e
	lsl r1, r1, #6
	add r1, #0x48
	lsl r1, r1, #0x10
	asr r6, r1, #0x10
	lsl r1, r2, #7
	lsr r1, r1, #0x1e
	lsl r1, r1, #2
	ldr r5, [r0, #0x24]
	add r0, r0, r1
	ldr r0, [r0, #4]
	mov r4, #0x28
	bl ov96_021EAA20
	bl ov96_021E8BB0
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _0220BFE8
	sub r4, #0x10
	lsl r0, r4, #0x10
	asr r4, r0, #0x10
_0220BFE8:
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	bl ManagedSprite_SetPositionXY
	add r0, r5, #0
	add r1, r7, #0
	bl ManagedSprite_SetAnimNoRestart
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220BFB4


	thumb_func_start ov96_0220C004
ov96_0220C004: ; 0x0220C004
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldr r0, [r4]
	lsl r1, r0, #5
	lsr r1, r1, #0x1f
	beq _0220C024
	ldr r0, [r5, #0x28]
	mov r1, #0x10
	bl ManagedSprite_SetAnimNoRestart
	ldr r0, [r5, #0x28]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	b _0220C040
_0220C024:
	lsl r0, r0, #8
	lsr r1, r0, #0x18
	cmp r1, #0x32
	ldr r0, [r5, #0x28]
	blo _0220C03A
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	mov r2, #0
	bl ov96_0220C8B8
	b _0220C040
_0220C03A:
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_0220C040:
	ldr r0, [r4]
	lsl r0, r0, #0x10
	lsr r1, r0, #0x18
	bne _0220C06C
	add r0, r5, #0
	mov r1, #0x1a
	bl ov96_0220BFB4
	ldr r0, [r5, #0x28]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x38]
	mov r1, #0xc
	lsl r0, r0, #7
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #4]
	bl ov96_021EAC5C
	pop {r3, r4, r5, pc}
_0220C06C:
	ldr r2, [r5, #0x38]
	ldr r0, [r5, #0x24]
	lsl r2, r2, #7
	lsr r2, r2, #0x1e
	lsl r2, r2, #2
	add r2, r5, r2
	ldr r2, [r2, #0x10]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	bl ov96_0220C768
	cmp r0, #0
	beq _0220C0A2
	add r0, r5, #0
	mov r1, #0x18
	bl ov96_0220BFB4
	ldr r0, [r5, #0x38]
	mov r1, #0
	lsl r0, r0, #7
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #4]
	bl ov96_021EAC5C
	pop {r3, r4, r5, pc}
_0220C0A2:
	ldr r0, [r4]
	lsl r0, r0, #5
	lsr r0, r0, #0x1f
	beq _0220C0BE
	ldr r0, [r5, #0x38]
	mov r1, #8
	lsl r0, r0, #7
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #4]
	bl ov96_021EAC5C
	pop {r3, r4, r5, pc}
_0220C0BE:
	ldr r0, [r5, #0x24]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x38]
	mov r1, #4
	lsl r0, r0, #7
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #4]
	bl ov96_021EAC5C
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_0220C004


	thumb_func_start ov96_0220C0DC
ov96_0220C0DC: ; 0x0220C0DC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	ldr r0, [r6]
	ldr r1, [r5, #0x38]
	lsl r0, r0, #0x18
	lsl r1, r1, #9
	lsr r0, r0, #0x18
	lsr r1, r1, #0x18
	cmp r1, r0
	beq _0220C154
	mov r1, #0xa
	bl _u32_div_f
	lsr r4, r1, #1
	mov r0, #0xc
	sub r2, r0, r4
	cmp r1, #0
	ldr r0, [r5, #0x1c]
	beq _0220C10C
	add r1, r2, #0
	bl ManagedSprite_SetAnimNoRestart
	b _0220C112
_0220C10C:
	mov r1, #0xd
	bl ManagedSprite_SetAnimNoRestart
_0220C112:
	ldr r1, [r5, #0x38]
	lsl r2, r4, #1
	lsl r1, r1, #3
	lsr r1, r1, #0x1e
	lsl r1, r1, #6
	add r2, r4, r2
	add r1, #0x48
	add r2, #0x30
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r5, #0x20]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	ldr r0, [r5, #0x20]
	mov r1, #5
	bl ManagedSprite_SetAnim
	ldr r0, [r5, #0x20]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r1, [r5, #0x38]
	ldr r0, _0220C158 ; =0xFF807FFF
	and r1, r0
	ldr r0, [r6]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #9
	orr r0, r1
	str r0, [r5, #0x38]
_0220C154:
	pop {r4, r5, r6, pc}
	nop
_0220C158: .word 0xFF807FFF
	thumb_func_end ov96_0220C0DC


	thumb_func_start ov96_0220C15C
ov96_0220C15C: ; 0x0220C15C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r1, #0
	ldr r1, [r4, #0x38]
	lsl r2, r1, #0x1a
	lsr r2, r2, #0x1c
	cmp r2, #6
	bls _0220C16E
	b _0220C3CA
_0220C16E:
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0220C17A: ; jump table
	.short _0220C188 - _0220C17A - 2 ; case 0
	.short _0220C1B2 - _0220C17A - 2 ; case 1
	.short _0220C216 - _0220C17A - 2 ; case 2
	.short _0220C274 - _0220C17A - 2 ; case 3
	.short _0220C2B2 - _0220C17A - 2 ; case 4
	.short _0220C33E - _0220C17A - 2 ; case 5
	.short _0220C3B6 - _0220C17A - 2 ; case 6
_0220C188:
	ldr r5, [r4, #0x2c]
	add r0, r5, #0
	bl ManagedSprite_ResetSpriteAnimCtrlState
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r2, [r4, #0x38]
	mov r1, #0x3c
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x1a
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C1B2:
	ldr r0, _0220C3D4 ; =0xFFFFC03F
	and r0, r1
	lsl r1, r1, #0x12
	lsr r1, r1, #0x18
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x12
	orr r1, r0
	lsl r0, r1, #0x12
	lsr r0, r0, #0x18
	str r1, [r4, #0x38]
	cmp r0, #2
	blo _0220C294
	lsl r0, r1, #7
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r5, [r4, #0x30]
	ldr r0, [r0, #4]
	mov r1, #0
	bl ov96_021EAB38
	add r0, r5, #0
	mov r1, #0x1b
	bl ManagedSprite_SetAnim
	add r0, r5, #0
	mov r1, #0
	bl ManagedSprite_SetAnimateFlag
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r1, [r4, #0x38]
	ldr r0, _0220C3D4 ; =0xFFFFC03F
	add r2, r1, #0
	and r2, r0
	mov r0, #0x3c
	add r1, r2, #0
	bic r1, r0
	lsl r0, r2, #0x1a
	lsr r0, r0, #0x1c
	add r0, r0, #1
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C216:
	add r1, sp, #4
	ldr r0, [r4, #0x30]
	add r1, #2
	add r2, sp, #4
	bl ManagedSprite_GetPositionXY
	mov r3, #4
	add r1, sp, #0
	add r0, r3, #0
	ldrsh r5, [r1, r3]
	sub r0, #0x44
	sub r2, r0, r5
	asr r0, r2, #1
	lsr r0, r0, #0x1e
	add r0, r2, r0
	lsl r0, r0, #0xe
	asr r2, r0, #0x10
	add r0, r3, #0
	sub r0, #0x44
	cmp r5, r0
	ble _0220C244
	cmp r2, #0
	bne _0220C25E
_0220C244:
	ldr r2, [r4, #0x38]
	mov r1, #0x3c
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x1a
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C25E:
	ldr r0, [r4, #0x30]
	mov r4, #6
	add r2, r5, r2
	lsl r2, r2, #0x10
	ldrsh r1, [r1, r4]
	asr r2, r2, #0x10
	lsl r3, r3, #0x12
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add sp, #8
	pop {r3, r4, r5, pc}
_0220C274:
	add r0, r1, #0
	lsl r1, r1, #0x12
	lsr r1, r1, #0x18
	ldr r3, _0220C3D4 ; =0xFFFFC03F
	add r1, r1, #1
	lsl r1, r1, #0x18
	and r0, r3
	lsr r1, r1, #0x12
	orr r0, r1
	str r0, [r4, #0x38]
	lsl r0, r0, #0x12
	add r2, r4, #0
	lsr r0, r0, #0x18
	add r2, #0x38
	cmp r0, #4
	bhs _0220C296
_0220C294:
	b _0220C3CE
_0220C296:
	ldr r0, [r2]
	add sp, #8
	and r3, r0
	mov r0, #0x3c
	add r1, r3, #0
	bic r1, r0
	lsl r0, r3, #0x1a
	lsr r0, r0, #0x1c
	add r0, r0, #1
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1a
	orr r0, r1
	str r0, [r2]
	pop {r3, r4, r5, pc}
_0220C2B2:
	add r1, sp, #0
	ldr r0, [r4, #0x30]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	add r1, sp, #0
	mov r0, #0
	ldrsh r1, [r1, r0]
	sub r0, #0x18
	sub r0, r0, r1
	bpl _0220C2CC
	neg r0, r0
_0220C2CC:
	lsl r0, r0, #0x10
	asr r1, r0, #0x10
	beq _0220C2DA
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0xf
	asr r1, r0, #0x10
_0220C2DA:
	add r5, sp, #0
	mov r0, #0
	ldrsh r2, [r5, r0]
	add r1, r1, #2
	add r1, r2, r1
	strh r1, [r5]
	ldrsh r2, [r5, r0]
	cmp r2, #0x30
	blt _0220C32E
	ldr r0, [r4, #0x38]
	mov r2, #0x30
	lsl r0, r0, #3
	lsr r0, r0, #0x1e
	lsl r0, r0, #6
	add r0, #0x48
	strh r0, [r5, #2]
	strh r2, [r5]
	mov r1, #2
	ldrsh r1, [r5, r1]
	ldr r0, [r4, #0x30]
	bl ManagedSprite_SetPositionXY
	ldr r0, [r4, #0x30]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	ldr r0, [r4, #0x2c]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r2, [r4, #0x38]
	mov r1, #0x3c
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x1a
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C32E:
	mov r3, #2
	ldrsh r1, [r5, r3]
	ldr r0, [r4, #0x30]
	lsl r3, r3, #0x13
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add sp, #8
	pop {r3, r4, r5, pc}
_0220C33E:
	ldr r0, _0220C3D4 ; =0xFFFFC03F
	and r0, r1
	lsl r1, r1, #0x12
	lsr r1, r1, #0x18
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x12
	orr r0, r1
	str r0, [r4, #0x38]
	lsl r0, r0, #0x12
	lsr r0, r0, #0x18
	cmp r0, #2
	blo _0220C3CE
	ldr r0, [r4, #0x30]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x38]
	mov r1, #1
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #4]
	bl ov96_021EAB38
	ldr r0, [r4, #0x38]
	mov r1, #0
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #4]
	bl ov96_021EAB74
	ldr r1, [r4, #0x38]
	ldr r0, _0220C3D8 ; =0xFE7FFFFF
	add r2, r1, #0
	and r2, r0
	lsl r0, r1, #0x1e
	lsr r0, r0, #0x1e
	lsl r0, r0, #0x1e
	lsr r0, r0, #7
	add r1, r2, #0
	orr r1, r0
	ldr r0, _0220C3D4 ; =0xFFFFC03F
	add r2, r1, #0
	and r2, r0
	mov r0, #0x3c
	add r1, r2, #0
	bic r1, r0
	lsl r0, r2, #0x1a
	lsr r0, r0, #0x1c
	add r0, r0, #1
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1a
	orr r0, r1
	add sp, #8
	str r0, [r4, #0x38]
	pop {r3, r4, r5, pc}
_0220C3B6:
	mov r1, #0
	str r1, [r4, #0x34]
	ldr r2, [r4, #0x38]
	ldr r1, _0220C3DC ; =0xFFFFBFFF
	and r1, r2
	str r1, [r4, #0x38]
	bl SysTask_Destroy
	add sp, #8
	pop {r3, r4, r5, pc}
_0220C3CA:
	bl GF_AssertFail
_0220C3CE:
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_0220C3D4: .word 0xFFFFC03F
_0220C3D8: .word 0xFE7FFFFF
_0220C3DC: .word 0xFFFFBFFF
	thumb_func_end ov96_0220C15C


	thumb_func_start ov96_0220C3E0
ov96_0220C3E0: ; 0x0220C3E0
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x38]
	mov r0, #0x3c
	bic r1, r0
	ldr r0, _0220C404 ; =0xFFFFC03F
	mov r2, #1
	and r1, r0
	mov r0, #1
	lsl r0, r0, #0xe
	orr r0, r1
	str r0, [r4, #0x38]
	ldr r0, _0220C408 ; =ov96_0220C15C
	add r1, r4, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #0x34]
	pop {r4, pc}
	.balign 4, 0
_0220C404: .word 0xFFFFC03F
_0220C408: .word ov96_0220C15C
	thumb_func_end ov96_0220C3E0


	thumb_func_start ov96_0220C40C
ov96_0220C40C: ; 0x0220C40C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	add r6, r0, #0
	ldr r0, [r5, #0x38]
	lsl r1, r0, #5
	lsr r1, r1, #0x1e
	lsl r4, r1, #2
	lsl r0, r0, #7
	lsr r1, r0, #0x1e
	ldr r0, [r6, r4]
	lsl r0, r0, #6
	lsr r0, r0, #0x1e
	cmp r1, r0
	bne _0220C43E
	add r0, r5, #0
	add r1, r6, r4
	bl ov96_0220C004
	b _0220C44E
_0220C43E:
	ldr r0, [r5, #0x24]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x28]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_0220C44E:
	add r0, r5, #0
	add r1, r6, r4
	bl ov96_0220C0DC
	ldr r2, [r5, #0x38]
	lsl r0, r2, #0x11
	lsr r0, r0, #0x1f
	bne _0220C48E
	ldr r0, [r6, r4]
	lsl r0, r0, #6
	lsr r1, r0, #0x1e
	lsl r0, r2, #7
	lsr r0, r0, #0x1e
	cmp r0, r1
	beq _0220C48E
	cmp r1, #3
	blo _0220C474
	bl GF_AssertFail
_0220C474:
	ldr r0, [r5, #0x38]
	mov r1, #3
	bic r0, r1
	ldr r1, [r6, r4]
	lsl r1, r1, #6
	lsr r2, r1, #0x1e
	mov r1, #3
	and r1, r2
	orr r0, r1
	str r0, [r5, #0x38]
	add r0, r5, #0
	bl ov96_0220C3E0
_0220C48E:
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_0220C40C


	thumb_func_start ov96_0220C490
ov96_0220C490: ; 0x0220C490
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	add r5, r0, #0
	str r2, [sp]
	mov r0, #0
	add r7, r1, #0
	add r1, r0, #0
	add r2, sp, #4
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [r2]
	cmp r7, #0
	bne _0220C4B6
	bl GF_AssertFail
_0220C4B6:
	ldr r0, [sp]
	cmp r0, #0
	bne _0220C4C0
	bl GF_AssertFail
_0220C4C0:
	ldr r1, _0220C540 ; =0x00002712
	mov r3, #2
	add r0, r1, #1
	str r0, [sp, #0x1c]
	mov r0, #1
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	mov r1, #0x88
	add r0, sp, #4
	strh r1, [r0]
	mov r1, #0x70
	strh r1, [r0, #2]
	mov r0, #0x1b
	str r0, [sp, #0xc]
	str r3, [sp, #0x30]
	ldr r1, [sp]
	add r0, r7, #0
	add r2, sp, #4
	lsl r3, r3, #0x13
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	str r0, [r5]
	bl ManagedSprite_SetAnimateFlag
	mov r4, #0
	mov r6, #0x30
_0220C4FA:
	ldr r0, _0220C544 ; =0x00002713
	mov r3, #1
	add r0, r4, r0
	str r0, [sp, #0x18]
	ldr r0, _0220C548 ; =0x00002714
	mov r1, #0x28
	add r0, r4, r0
	str r0, [sp, #0x1c]
	ldr r0, _0220C540 ; =0x00002712
	add r2, sp, #4
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	mov r0, #2
	str r0, [sp, #0x14]
	add r0, sp, #4
	strh r1, [r0]
	strh r6, [r0, #2]
	add r0, r4, #1
	str r0, [sp, #0xc]
	ldr r1, [sp]
	add r0, r7, #0
	lsl r3, r3, #0x14
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	str r0, [r5, #0x14]
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r6, #0x58
	add r5, r5, #4
	cmp r4, #2
	blt _0220C4FA
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220C540: .word 0x00002712
_0220C544: .word 0x00002713
_0220C548: .word 0x00002714
	thumb_func_end ov96_0220C490


	thumb_func_start ov96_0220C54C
ov96_0220C54C: ; 0x0220C54C
	push {r4, r5, lr}
	sub sp, #0x14
	lsl r1, r1, #2
	add r1, r0, r1
	ldr r4, [r0]
	ldr r5, [r1, #0x10]
	add r1, r2, #0
	add r2, r3, #0
	ldr r0, [r0, #0xc]
	add r3, sp, #4
	bl ov96_021E6168
	ldr r2, [sp, #0x20]
	add r0, r5, #0
	add r1, sp, #4
	mov r3, #0
	str r4, [sp]
	bl ov96_021EEBE4
	add sp, #0x14
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_0220C54C


	thumb_func_start ov96_0220C578
ov96_0220C578: ; 0x0220C578
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #2
	beq _0220C58A
	cmp r4, #3
	beq _0220C5C8
	b _0220C648
_0220C58A:
	ldr r0, [r5, #0xc]
	bl ov96_021E5F24
	mov r3, #1
	str r3, [sp]
	add r1, r0, #0
	ldr r2, [r5, #0x40]
	lsl r1, r1, #0x18
	lsl r2, r2, #0x1e
	lsr r2, r2, #0x1e
	lsl r2, r2, #0x18
	ldr r0, [r5, #0xc]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021E8228
	ldr r1, [r5, #0x40]
	add r0, r5, #0
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r3, r1, #2
	add r0, #0x34
	ldr r2, [r0, r3]
	ldr r1, _0220C668 ; =0xFC03FFFF
	and r1, r2
	str r1, [r0, r3]
	ldr r1, [r5, #0x40]
	ldr r0, _0220C66C ; =0xFFE003FF
	and r0, r1
	str r0, [r5, #0x40]
	b _0220C648
_0220C5C8:
	ldr r0, [r5, #0xc]
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r2, [r5, #0x40]
	lsl r1, r1, #0x18
	lsl r2, r2, #0x1e
	lsr r2, r2, #0x1e
	lsl r2, r2, #0x18
	ldr r0, [r5, #0xc]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #7
	bl ov96_021E8228
	ldr r1, [r5, #0x44]
	ldr r0, _0220C670 ; =0x00FFFFFF
	and r0, r1
	str r0, [r5, #0x44]
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	sub r2, #0xa
	cmp r2, #0x64
	ble _0220C600
	mov r2, #0x64
	b _0220C606
_0220C600:
	cmp r2, #0
	bge _0220C606
	mov r2, #0
_0220C606:
	ldr r1, [r5, #0x44]
	mov r0, #0xff
	bic r1, r0
	lsl r0, r2, #0x18
	lsr r0, r0, #0x18
	orr r0, r1
	str r0, [r5, #0x44]
	lsl r0, r0, #0x17
	lsr r0, r0, #0x1f
	beq _0220C620
	add r0, r5, #0
	bl ov96_0220C7FC
_0220C620:
	ldr r3, [r5, #0x40]
	add r1, r5, #0
	add r0, r3, #0
	lsl r3, r3, #0x1e
	lsr r3, r3, #0x1e
	mov r2, #3
	add r6, r3, #1
	mov r3, #3
	bic r0, r2
	and r3, r6
	orr r0, r3
	str r0, [r5, #0x40]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	add r1, #0x40
	cmp r0, #3
	blo _0220C648
	ldr r0, [r1]
	bic r0, r2
	str r0, [r1]
_0220C648:
	ldr r1, [r5, #0x40]
	ldr r0, _0220C674 ; =0xFFFFFC03
	and r1, r0
	lsl r0, r4, #0x18
	lsr r0, r0, #0x16
	orr r0, r1
	str r0, [r5, #0x40]
	ldr r1, [r5, #0x44]
	ldr r0, _0220C678 ; =0xFFFF03FF
	and r1, r0
	ldr r0, _0220C67C ; =0xFF00FFFF
	and r0, r1
	str r0, [r5, #0x44]
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_0220C668: .word 0xFC03FFFF
_0220C66C: .word 0xFFE003FF
_0220C670: .word 0x00FFFFFF
_0220C674: .word 0xFFFFFC03
_0220C678: .word 0xFFFF03FF
_0220C67C: .word 0xFF00FFFF
	thumb_func_end ov96_0220C578


	thumb_func_start ov96_0220C680
ov96_0220C680: ; 0x0220C680
	push {r4, lr}
	ldr r3, [r0, #0x40]
	lsl r1, r3, #0x16
	lsr r1, r1, #0x18
	cmp r1, #3
	beq _0220C70C
	ldr r1, [r0, #0x44]
	lsl r2, r1, #0x17
	lsr r2, r2, #0x1f
	beq _0220C6B0
	ldr r1, _0220C710 ; =0x001FFFFF
	add r2, r3, #0
	and r2, r1
	lsr r1, r3, #0x15
	add r1, r1, #1
	lsl r1, r1, #0x15
	orr r1, r2
	str r1, [r0, #0x40]
	lsr r1, r1, #0x15
	cmp r1, #0x5a
	blo _0220C70C
	bl ov96_0220C7FC
	pop {r4, pc}
_0220C6B0:
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	beq _0220C704
	add r1, r3, #0
	ldr r4, _0220C710 ; =0x001FFFFF
	lsr r3, r3, #0x15
	add r3, r3, #1
	add r2, r0, #0
	and r1, r4
	lsl r3, r3, #0x15
	orr r1, r3
	str r1, [r0, #0x40]
	lsr r1, r1, #0x15
	add r2, #0x40
	cmp r1, #2
	blo _0220C6EC
	ldr r1, [r2]
	and r1, r4
	str r1, [r2]
	ldr r3, [r0, #0x44]
	mov r2, #0xff
	add r1, r3, #0
	bic r1, r2
	lsl r2, r3, #0x18
	lsr r2, r2, #0x18
	sub r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	orr r1, r2
	str r1, [r0, #0x44]
_0220C6EC:
	ldr r1, [r0, #0x44]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, #0x32
	blo _0220C70C
	lsl r1, r1, #0x10
	ldr r0, [r0, #0x14]
	lsr r1, r1, #0x10
	mov r2, #1
	bl ov96_0220C8B8
	pop {r4, pc}
_0220C704:
	ldr r0, [r0, #0x14]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_0220C70C:
	pop {r4, pc}
	nop
_0220C710: .word 0x001FFFFF
	thumb_func_end ov96_0220C680


	thumb_func_start ov96_0220C714
ov96_0220C714: ; 0x0220C714
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x44]
	add r5, r1, #0
	lsl r0, r0, #0x17
	lsr r0, r0, #0x1f
	beq _0220C726
	bl GF_AssertFail
_0220C726:
	cmp r5, #0
	beq _0220C740
	ldr r2, [r4, #0x44]
	mov r1, #0xff
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	add r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	orr r0, r1
	str r0, [r4, #0x44]
_0220C740:
	ldr r1, [r4, #0x44]
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	cmp r0, #0x64
	bls _0220C754
	mov r0, #0xff
	bic r1, r0
	mov r0, #0x64
	orr r0, r1
	str r0, [r4, #0x44]
_0220C754:
	ldr r0, [r4, #0x44]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #0x64
	blo _0220C764
	add r0, r4, #0
	bl ov96_0220C7C4
_0220C764:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_0220C714


	thumb_func_start ov96_0220C768
ov96_0220C768: ; 0x0220C768
	push {r4, lr}
	add r4, r0, #0
	add r0, r1, #0
	add r1, r2, #0
	bl FX_Div
	mov r1, #0x64
	add r2, r0, #0
	mul r2, r1
	asr r0, r2, #0xc
	cmp r0, #0x28
	bgt _0220C7BE
	sub r0, r1, r0
	lsl r0, r0, #1
	cmp r0, #0
	ble _0220C79A
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0220C7A8
_0220C79A:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0220C7A8:
	bl _ffix
	mov r1, #0x64
	bl _s32_div_f
	add r1, r0, #0
	add r0, r4, #0
	bl ManagedSprite_SetAnimSpeed
	mov r0, #1
	pop {r4, pc}
_0220C7BE:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220C768


	thumb_func_start ov96_0220C7C4
ov96_0220C7C4: ; 0x0220C7C4
	push {r4, lr}
	add r4, r0, #0
	mov r0, #1
	ldr r1, [r4, #0x44]
	lsl r0, r0, #8
	orr r0, r1
	str r0, [r4, #0x44]
	ldr r1, [r4, #0x40]
	ldr r0, _0220C7F4 ; =0x001FFFFF
	and r0, r1
	str r0, [r4, #0x40]
	ldr r0, [r4, #0x14]
	mov r1, #0x10
	bl ManagedSprite_SetAnim
	mov r1, #1
	ldr r0, [r4, #0x14]
	lsl r1, r1, #0xc
	bl ManagedSprite_SetAnimSpeed
	ldr r0, _0220C7F8 ; =0x000008BF
	bl PlaySE
	pop {r4, pc}
	.balign 4, 0
_0220C7F4: .word 0x001FFFFF
_0220C7F8: .word 0x000008BF
	thumb_func_end ov96_0220C7C4


	thumb_func_start ov96_0220C7FC
ov96_0220C7FC: ; 0x0220C7FC
	push {r4, lr}
	ldr r2, [r0, #0x44]
	ldr r1, _0220C83C ; =0xFFFFFEFF
	ldr r3, _0220C840 ; =0xFC03FFFF
	and r2, r1
	str r2, [r0, #0x44]
	ldr r2, [r0, #0x40]
	lsr r1, r1, #0xb
	and r1, r2
	str r1, [r0, #0x40]
	ldr r2, [r0, #0x44]
	mov r1, #0xff
	bic r2, r1
	str r2, [r0, #0x44]
	ldr r1, [r0, #0x40]
	add r2, r0, #0
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	add r2, #0x34
	lsl r1, r1, #2
	ldr r4, [r2, r1]
	and r4, r3
	mov r3, #0xa
	lsl r3, r3, #0x12
	orr r3, r4
	str r3, [r2, r1]
	ldr r0, [r0, #0x14]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	pop {r4, pc}
	nop
_0220C83C: .word 0xFFFFFEFF
_0220C840: .word 0xFC03FFFF
	thumb_func_end ov96_0220C7FC


	thumb_func_start ov96_0220C844
ov96_0220C844: ; 0x0220C844
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov r5, #0
	str r0, [sp]
	str r1, [sp, #4]
	str r5, [sp, #8]
	mov r7, #0x48
_0220C852:
	ldr r1, [sp, #8]
	ldr r0, [sp, #4]
	cmp r1, r0
	beq _0220C8A8
	mov r6, #0
_0220C85C:
	add r1, r6, r5
	lsl r1, r1, #0x18
	ldr r0, [sp]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r4, r0, #0
	mov r1, #0x20
	bl ov96_021EABA8
	add r0, r4, #0
	add r1, r7, #0
	mov r2, #0x30
	bl ov96_021EAF94
	add r0, r4, #0
	mov r1, #2
	bl ov96_021EAC0C
	cmp r6, #0
	bne _0220C88A
	mov r1, #1
	b _0220C88C
_0220C88A:
	mov r1, #0
_0220C88C:
	lsl r1, r1, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_021EAB38
	add r0, r4, #0
	mov r1, #0
	bl ov96_021EAB74
	add r6, r6, #1
	cmp r6, #3
	blt _0220C85C
	add r5, r5, #3
	add r7, #0x40
_0220C8A8:
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #4
	blt _0220C852
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220C844


	thumb_func_start ov96_0220C8B8
ov96_0220C8B8: ; 0x0220C8B8
	push {r3, r4, r5, lr}
	add r4, r2, #0
	add r5, r0, #0
	mov r2, #0
	sub r1, #0x32
	beq _0220C8CE
	lsl r0, r1, #0xc
	mov r1, #0xa
	bl _s32_div_f
	add r2, r0, #0
_0220C8CE:
	ldr r0, _0220C908 ; =0x0000099A
	cmp r2, r0
	bge _0220C8D6
	add r2, r0, #0
_0220C8D6:
	add r0, r5, #0
	add r1, r2, #0
	bl ManagedSprite_SetAnimSpeed
	add r0, r5, #0
	mov r1, #0x11
	bl ManagedSprite_SetAnimNoRestart
	cmp r4, #0
	beq _0220C8FC
	add r0, r5, #0
	bl ManagedSprite_GetDrawFlag
	cmp r0, #0
	bne _0220C8FC
	mov r0, #0x23
	lsl r0, r0, #6
	bl PlaySE
_0220C8FC:
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	pop {r3, r4, r5, pc}
	nop
_0220C908: .word 0x0000099A
	thumb_func_end ov96_0220C8B8


	thumb_func_start ov96_0220C90C
ov96_0220C90C: ; 0x0220C90C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	lsl r6, r1, #2
	add r0, r5, r6
	add r7, r2, #0
	add r4, r3, #0
	mov r3, #1
	ldr r0, [r0, #0x10]
	add r1, r7, #0
	add r2, r4, #0
	lsl r3, r3, #0x14
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add r0, r5, r6
	sub r4, #0x18
	lsl r2, r4, #0x10
	mov r3, #1
	ldr r0, [r0, #0x18]
	add r1, r7, #0
	asr r2, r2, #0x10
	lsl r3, r3, #0x14
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220C90C


	thumb_func_start ov96_0220C93C
ov96_0220C93C: ; 0x0220C93C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	str r0, [sp]
	bl PokeathlonCourse_GetParticipantCount
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0x78
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x78
	add r6, r0, #0
	bl MI_CpuFill8
	ldr r0, [sp]
	str r4, [r6]
	str r0, [r6, #4]
	mov r0, #4
	sub r0, r0, r5
	str r0, [r6, #0x74]
	cmp r0, #3
	bls _0220C96E
	bl GF_AssertFail
_0220C96E:
	ldr r0, [r6, #0x74]
	mov r7, #0
	cmp r0, #0
	bls _0220C992
	add r4, r6, #0
	add r4, #8
_0220C97A:
	lsl r1, r5, #0x18
	ldr r2, [sp]
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_0220C9F4
	ldr r0, [r6, #0x74]
	add r7, r7, #1
	add r5, r5, #1
	add r4, #0x24
	cmp r7, r0
	blo _0220C97A
_0220C992:
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220C93C

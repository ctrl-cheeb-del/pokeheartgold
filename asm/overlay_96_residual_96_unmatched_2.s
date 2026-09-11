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

	.public ov96_0220B79C
	.public ov96_0220B7B4
	.public ov96_0220B7CC
	.public ov96_0220B7F4
	.public ov96_0220B8A0
	.public ov96_0220B8D8
	.public ov96_0220B8F0
	.public ov96_0220B940
	.public ov96_0220B95C
	.public ov96_0220B988
	.public ov96_0220B9A8
	.public ov96_0220BD38
	.public ov96_0220BE28
	.public ov96_0220BFB4
	.public ov96_0220C004
	.public ov96_0220C0DC
	.public ov96_0220C15C
	.public ov96_0220C3E0
	.public ov96_0220C40C
	.public ov96_0220C490
	.public ov96_0220C54C
	.public ov96_0220C578
	.public ov96_0220C680
	.public ov96_0220C714
	.public ov96_0220C768
	.public ov96_0220C7C4
	.public ov96_0220C7FC
	.public ov96_0220C844
	.public ov96_0220C8B8
	.public ov96_0220C90C
	.public ov96_0220C93C



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

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

	thumb_func_start ov96_021E75BC
ov96_021E75BC: ; 0x021E75BC
	push {r4, lr}
	add r4, r0, #0
	bl OamManager_ApplyAndResetBuffers
	add r0, r4, #0
	bl DoScheduledBgGpuUpdates
	bl GF_RunVramTransferTasks
	ldr r3, _021E75DC ; =0x027E0000
	ldr r1, _021E75E0 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E75DC: .word 0x027E0000
_021E75E0: .word 0x00003FF8
	thumb_func_end ov96_021E75BC


	thumb_func_start ov96_021E75E4
ov96_021E75E4: ; 0x021E75E4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp]
	add r0, r7, #0
	bl ov96_021E5F24
	cmp r0, #0
	beq _021E7604
	bl GF_AssertFail
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E7604:
	mov r0, #0x5e
	lsl r0, r0, #4
	add r5, r7, r0
	ldr r0, [sp]
	mov r4, #0
	str r0, [sp, #4]
	add r0, #0x28
	str r0, [sp, #4]
_021E7614:
	add r0, r7, #0
	bl PokeathlonCourse_GetUnkConstant4
	add r6, r0, #0
	ldr r0, [sp, #4]
	bl ov96_021E8A20
	add r1, r4, #0
	mul r1, r6
	add r0, r0, r1
	add r1, r5, #0
	add r2, r6, #0
	bl memcpy
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _021E7614
	bl ov96_021E9A14
	add r4, r0, #0
	add r0, r7, #0
	bl PokeathlonCourse_GetSystem
	ldr r1, [sp]
	add r3, r0, #0
	add r1, #0x28
	mov r0, #0x1e
	add r2, r4, #0
	str r1, [sp]
	bl ov96_021E87B4
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021E75E4


	thumb_func_start ov96_021E7658
ov96_021E7658: ; 0x021E7658
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	str r1, [sp]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp]
	mov r4, #0
	lsl r0, r0, #1
	add r6, r5, r0
_021E766E:
	ldr r0, _021E7708 ; =0x00000614
	add r1, r4, #0
	ldr r0, [r5, r0]
	bl ov96_021E9370
	add r3, r0, #0
	lsl r0, r4, #3
	add r2, r6, r0
	ldrh r1, [r3, #0xa]
	ldr r0, _021E770C ; =0x000008B4
	strh r1, [r2, r0]
	ldr r1, [r3, #0xc]
	add r0, #0x20
	strh r1, [r2, r0]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021E766E
	mov r4, #0
_021E7696:
	ldr r0, _021E7708 ; =0x00000614
	add r1, r4, #0
	ldr r0, [r5, r0]
	bl ov96_021E94EC
	add r6, r0, #0
	ldr r0, [r6]
	cmp r0, r7
	beq _021E76B2
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021E7696
_021E76B2:
	cmp r4, #4
	bne _021E76BC
	bl GF_AssertFail
	pop {r3, r4, r5, r6, r7, pc}
_021E76BC:
	ldrb r0, [r6, #9]
	cmp r0, #0
	bne _021E76D4
	ldr r0, [sp]
	mov r1, #1
	add r2, r5, r0
	ldr r0, _021E7710 ; =0x000008F4
	strb r1, [r2, r0]
	mov r1, #0
	add r0, r0, #4
	strb r1, [r2, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021E76D4:
	ldr r0, [sp]
	mov r2, #0
	add r1, r5, r0
	ldr r0, _021E7710 ; =0x000008F4
	strb r2, [r1, r0]
	ldr r0, _021E7708 ; =0x00000614
	mov r1, #3
	ldr r0, [r5, r0]
	bl ov96_021E94EC
	ldrb r1, [r0, #9]
	ldrb r0, [r6, #9]
	cmp r1, r0
	bne _021E76FC
	ldr r0, [sp]
	mov r2, #1
	add r1, r5, r0
	ldr r0, _021E7714 ; =0x000008F8
	strb r2, [r1, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021E76FC:
	ldr r0, [sp]
	mov r2, #0
	add r1, r5, r0
	ldr r0, _021E7714 ; =0x000008F8
	strb r2, [r1, r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7708: .word 0x00000614
_021E770C: .word 0x000008B4
_021E7710: .word 0x000008F4
_021E7714: .word 0x000008F8
	thumb_func_end ov96_021E7658


	thumb_func_start ov96_021E7718
ov96_021E7718: ; 0x021E7718
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0]
	bl Save_Pokeathlon_Get
	add r6, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetFieldData
	add r4, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0]
	bl Save_VarsFlags_Get
	str r0, [sp]
	mov r0, #0x1d
	lsl r0, r0, #4
	ldrh r0, [r4, r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _021E7772
	add r0, r5, #0
	bl ov96_021E7FA8
	ldr r0, [sp]
	mov r1, #0xf0
	bl Save_VarsFlags_CheckFlagInArray
	cmp r0, #0
	bne _021E7772
	add r0, r5, #0
	bl ov96_021E8084
	cmp r0, #0
	beq _021E7772
	ldr r0, [sp]
	mov r1, #0xf0
	bl Save_VarsFlags_SetFlagInArray
_021E7772:
	ldr r0, _021E7868 ; =0x000001D2
	ldrh r7, [r4, r0]
	add r0, #0x26
	ldr r0, [r5, r0]
	ldrb r0, [r0, #0xc]
	cmp r0, #0xa
	bne _021E7784
	lsl r0, r7, #0x11
	lsr r7, r0, #0x10
_021E7784:
	add r0, r6, #0
	add r1, r7, #0
	bl PokeathlonSave_AddAthletePoints
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0, #4]
	cmp r0, #1
	bne _021E77A8
	add r0, r6, #0
	bl PokeathlonSave_GetRecordsLink2
	add r1, r0, #0
	add r0, r5, #0
	bl ov96_021E7A2C
	b _021E780A
_021E77A8:
	add r0, r6, #0
	bl PokeathlonSave_GetRecordsSolo
	str r0, [sp, #4]
	add r0, r6, #0
	bl PokeathlonSave_GetUnkAEC
	add r2, r0, #0
	ldr r1, [sp, #4]
	add r0, r5, #0
	bl ov96_021E7BA8
	mov r0, #0x1d
	lsl r0, r0, #4
	ldrh r0, [r4, r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _021E77FC
	add r0, r6, #0
	bl PokeathlonSave_dummy2
	add r1, r0, #0
	add r0, r5, #0
	bl ov96_021E786C
	ldr r0, [sp]
	mov r1, #0xef
	bl Save_VarsFlags_CheckFlagInArray
	cmp r0, #0
	bne _021E77FC
	add r0, r6, #0
	bl PokeathlonSave_dummy2
	bl ov96_021E8060
	cmp r0, #0
	beq _021E77FC
	ldr r0, [sp]
	mov r1, #0xef
	bl Save_VarsFlags_SetFlagInArray
_021E77FC:
	add r0, r6, #0
	bl PokeathlonSave_GetRecordsSolo2
	add r1, r0, #0
	add r0, r5, #0
	bl ov96_021E7938
_021E780A:
	add r0, r6, #0
	bl PokeathlonSave_GetAgainUnkB00
	add r1, r0, #0
	add r0, r5, #0
	bl ov96_021E7D6C
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0, #4]
	cmp r0, #0
	bne _021E7842
	ldr r0, [sp]
	mov r1, #0xf1
	bl Save_VarsFlags_CheckFlagInArray
	cmp r0, #0
	bne _021E7842
	add r0, r5, #0
	bl ov96_021E80C4
	cmp r0, #0
	beq _021E7842
	ldr r0, [sp]
	mov r1, #0xf1
	bl Save_VarsFlags_SetFlagInArray
_021E7842:
	ldr r1, _021E7868 ; =0x000001D2
	add r0, r1, #0
	add r0, #0x26
	ldrh r2, [r4, r1]
	ldr r0, [r5, r0]
	strh r2, [r0, #0xa]
	add r0, r1, #0
	add r0, #0x26
	ldr r0, [r5, r0]
	strh r7, [r0, #8]
	sub r0, r1, #2
	ldrh r0, [r4, r0]
	add r1, #0x26
	lsl r0, r0, #0x1c
	lsr r2, r0, #0x1e
	ldr r0, [r5, r1]
	strb r2, [r0, #0xd]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7868: .word 0x000001D2
	thumb_func_end ov96_021E7718


	thumb_func_start ov96_021E786C
ov96_021E786C: ; 0x021E786C
	push {r3, r4, r5, r6, r7, lr}
	mov r2, #0x7e
	lsl r2, r2, #2
	str r0, [sp]
	ldr r0, [r0, r2]
	ldrb r2, [r0, #0xc]
	mov r0, #0x2c
	mul r0, r2
	add r4, r1, r0
	ldr r1, _021E7918 ; =0x000008FE
	ldr r0, [sp]
	ldrh r1, [r0, r1]
	ldrh r0, [r4, #6]
	cmp r1, r0
	bls _021E7914
	strh r1, [r4, #6]
	ldrh r1, [r4, #6]
	ldr r0, _021E791C ; =0x000003E7
	cmp r1, r0
	bls _021E7896
	strh r0, [r4, #6]
_021E7896:
	ldr r1, _021E791C ; =0x000003E7
	ldr r5, [sp]
	ldr r7, _021E7920 ; =0x000008B4
	mov r3, #0
	add r6, r4, #0
	add r0, r1, #0
_021E78A2:
	ldrh r2, [r5, r7]
	strh r2, [r6]
	cmp r2, r0
	bls _021E78AC
	strh r1, [r6]
_021E78AC:
	add r3, r3, #1
	add r5, r5, #2
	add r6, r6, #2
	cmp r3, #3
	blt _021E78A2
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantUnk04
	add r1, r4, #0
	ldr r3, _021E7924 ; =0xFFFEFFFF
	mov r2, #0
	add r1, #8
_021E78CC:
	ldr r6, [r1]
	ldr r5, _021E7928 ; =0xFFFFFE00
	ldrh r7, [r0]
	and r5, r6
	ldr r6, _021E792C ; =0x000001FF
	add r2, r2, #1
	and r6, r7
	orr r6, r5
	ldr r5, _021E7930 ; =0xFFFFC1FF
	str r6, [r1]
	and r5, r6
	ldrh r6, [r0, #2]
	lsl r6, r6, #0x1b
	lsr r6, r6, #0x12
	orr r6, r5
	ldr r5, _021E7934 ; =0xFFFF3FFF
	str r6, [r1]
	and r5, r6
	ldrb r6, [r0, #0x11]
	lsl r6, r6, #0x1e
	lsr r6, r6, #0x10
	orr r5, r6
	str r5, [r1]
	ldrb r6, [r0, #0x10]
	and r5, r3
	lsl r6, r6, #0x1f
	lsr r6, r6, #0xf
	orr r5, r6
	str r5, [r1]
	ldr r5, [r0, #4]
	add r0, #0x28
	str r5, [r4, #0xc]
	add r1, #0xc
	add r4, #0xc
	cmp r2, #3
	blt _021E78CC
_021E7914:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7918: .word 0x000008FE
_021E791C: .word 0x000003E7
_021E7920: .word 0x000008B4
_021E7924: .word 0xFFFEFFFF
_021E7928: .word 0xFFFFFE00
_021E792C: .word 0x000001FF
_021E7930: .word 0xFFFFC1FF
_021E7934: .word 0xFFFF3FFF
	thumb_func_end ov96_021E786C


	thumb_func_start ov96_021E7938
ov96_021E7938: ; 0x021E7938
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xd0
	str r0, [sp]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
_021E7944:
	ldr r0, [sp, #8]
	lsl r1, r0, #2
	ldr r0, [sp]
	add r1, r0, r1
	mov r0, #0xf6
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0x2c
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r2, r0, #0
	mul r2, r1
	ldr r1, [sp, #4]
	add r7, r1, r2
	ldr r2, [r7, #0x28]
	ldr r1, _021E7A20 ; =0x0098967F
	cmp r2, r1
	bhs _021E796C
	add r1, r2, #1
	str r1, [r7, #0x28]
_021E796C:
	ldr r1, _021E7A24 ; =_0221A7D8
	mov r3, #0
	ldrb r0, [r1, r0]
	add r2, sp, #0x30
	str r0, [sp, #0xc]
_021E7976:
	lsl r0, r3, #3
	add r5, r7, r0
	ldrh r0, [r7, r0]
	lsl r1, r3, #5
	add r6, r2, r1
	strh r0, [r2, r1]
	mov r4, #0
_021E7984:
	lsl r1, r4, #1
	add r0, r5, r1
	ldrh r0, [r0, #2]
	add r1, r6, r1
	strh r0, [r1, #2]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E7984
	add r0, r3, #1
	lsl r0, r0, #0x18
	lsr r3, r0, #0x18
	cmp r3, #5
	blo _021E7976
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r2, r0, #0x15
	ldr r0, [sp, #8]
	lsl r1, r0, #1
	ldr r0, [sp]
	add r0, r0, r2
	add r1, r1, r0
	ldr r0, _021E7A28 ; =0x000008D4
	ldrh r1, [r1, r0]
	add r0, sp, #0x10
	strh r1, [r0]
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	mov r1, #0x3f
	ldr r0, [sp]
	lsl r1, r1, #4
	add r1, r0, r1
	mov r0, #0x7c
	mul r0, r2
	add r0, r1, r0
	mov r1, #0
	add r3, sp, #0x10
	mov r2, #0x28
_021E79DC:
	add r5, r1, #0
	mul r5, r2
	add r4, r0, r5
	ldrh r4, [r4, #2]
	ldrh r5, [r0, r5]
	lsl r4, r4, #0xa
	add r4, r4, r5
	lsl r5, r1, #1
	add r1, r1, #1
	lsl r1, r1, #0x18
	add r5, r3, r5
	lsr r1, r1, #0x18
	strh r4, [r5, #2]
	cmp r1, #3
	blo _021E79DC
	ldr r0, [sp, #0xc]
	add r1, r3, #0
	add r2, sp, #0x30
	bl ov96_021E7C04
	ldr r0, [sp]
	add r1, r7, #0
	add r2, sp, #0x30
	bl ov96_021E7C94
	ldr r0, [sp, #8]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #3
	blo _021E7944
	add sp, #0xd0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7A20: .word 0x0098967F
_021E7A24: .word _0221A7D8
_021E7A28: .word 0x000008D4
	thumb_func_end ov96_021E7938


	thumb_func_start ov96_021E7A2C
ov96_021E7A2C: ; 0x021E7A2C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xe0
	str r0, [sp]
	str r1, [sp, #4]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #8]
_021E7A42:
	ldr r0, [sp, #8]
	lsl r1, r0, #2
	ldr r0, [sp]
	add r1, r0, r1
	mov r0, #0xf6
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0xa4
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r2, r0, #0
	mul r2, r1
	ldr r1, [sp, #4]
	add r1, r1, r2
	str r1, [sp, #0x14]
	ldr r2, [r1, #0x28]
	ldr r1, _021E7B9C ; =0x0098967F
	cmp r2, r1
	bhs _021E7A6E
	ldr r1, [sp, #0x14]
	add r2, r2, #1
	str r2, [r1, #0x28]
_021E7A6E:
	ldr r1, _021E7BA0 ; =_0221A7D8
	add r4, sp, #0x40
	ldrb r0, [r1, r0]
	mov r1, #0
	mov r7, #0x18
	str r0, [sp, #0x18]
_021E7A7A:
	ldr r2, [sp, #0x14]
	lsl r3, r1, #3
	add r6, r2, r3
	ldrh r2, [r2, r3]
	lsl r5, r1, #5
	add r0, r4, r5
	strh r2, [r4, r5]
	mov r5, #0
_021E7A8A:
	lsl r3, r5, #1
	add r2, r6, r3
	ldrh r2, [r2, #2]
	add r3, r0, r3
	strh r2, [r3, #2]
	add r2, r5, #1
	lsl r2, r2, #0x18
	lsr r5, r2, #0x18
	cmp r5, #3
	blo _021E7A8A
	add r3, r1, #0
	ldr r2, [sp, #0x14]
	mul r3, r7
	add r6, r2, r3
	ldr r2, [r6, #0x2c]
	mov r5, #0
	str r2, [r0, #8]
_021E7AAC:
	lsl r3, r5, #1
	add r2, r6, r3
	ldrh r2, [r2, #0x30]
	add r3, r0, r3
	strh r2, [r3, #0xc]
	add r2, r5, #1
	lsl r2, r2, #0x18
	lsr r5, r2, #0x18
	cmp r5, #8
	blo _021E7AAC
	add r6, #0x40
	ldrb r2, [r6]
	strb r2, [r0, #0x1c]
	add r0, r1, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	cmp r1, #5
	blo _021E7A7A
	ldr r0, [sp, #8]
	mov r7, #0
	lsl r1, r0, #1
	ldr r0, [sp]
	add r5, sp, #0x20
	add r0, r0, r1
	str r0, [sp, #0xc]
	mov r1, #0x3f
	ldr r0, [sp]
	lsl r1, r1, #4
	add r0, r0, r1
	str r0, [sp, #0x1c]
	mov r4, #0x28
_021E7AEA:
	ldr r0, [sp, #0x10]
	add r0, r0, r7
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0xc]
	lsl r2, r1, #3
	add r2, r0, r2
	ldr r0, _021E7BA4 ; =0x000008D4
	ldrh r2, [r2, r0]
	add r0, sp, #0x20
	strh r2, [r0]
	mov r0, #0x7c
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #0x1c]
	add r0, r0, r2
	mov r2, #0
_021E7B18:
	add r6, r2, #0
	mul r6, r4
	add r3, r0, r6
	ldrh r3, [r3, #2]
	ldrh r6, [r0, r6]
	lsl r3, r3, #0xa
	add r3, r3, r6
	lsl r6, r2, #1
	add r2, r2, #1
	lsl r2, r2, #0x18
	add r6, r5, r6
	lsr r2, r2, #0x18
	strh r3, [r6, #2]
	cmp r2, #3
	blo _021E7B18
	ldr r0, [sp]
	bl PokeathlonCourse_GetPlayerProfileFromData
	add r6, r0, #0
	bl PlayerProfile_GetTrainerID
	str r0, [sp, #0x28]
	add r0, r6, #0
	bl PlayerProfile_GetNamePtr
	mov r1, #0
_021E7B4C:
	lsl r2, r1, #1
	ldrh r3, [r0, r2]
	add r1, r1, #1
	lsl r1, r1, #0x18
	add r2, r5, r2
	lsr r1, r1, #0x18
	strh r3, [r2, #0xc]
	cmp r1, #8
	blo _021E7B4C
	add r0, r6, #0
	bl PlayerProfile_GetLanguage
	add r1, sp, #0x20
	strb r0, [r1, #0x1c]
	ldr r0, [sp, #0x18]
	add r1, r5, #0
	add r2, sp, #0x40
	bl ov96_021E7C04
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #4
	blo _021E7AEA
	ldr r0, [sp]
	ldr r1, [sp, #0x14]
	add r2, sp, #0x40
	bl ov96_021E7CC8
	ldr r0, [sp, #8]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #4
	bhs _021E7B96
	b _021E7A42
_021E7B96:
	add sp, #0xe0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7B9C: .word 0x0098967F
_021E7BA0: .word _0221A7D8
_021E7BA4: .word 0x000008D4
	thumb_func_end ov96_021E7A2C


	thumb_func_start ov96_021E7BA8
ov96_021E7BA8: ; 0x021E7BA8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	mov r4, #0
_021E7BB4:
	lsl r0, r4, #2
	add r1, r7, r0
	mov r0, #0xf6
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r2, _021E7BF8 ; =_0221A7D8
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	lsl r0, r4, #1
	add r6, r7, r0
	mov r0, #0x2c
	add r1, r5, #0
	mul r1, r0
	ldr r0, [sp]
	ldrb r2, [r2, r5]
	ldrh r0, [r0, r1]
	ldr r1, _021E7BFC ; =0x000008D4
	ldrh r1, [r6, r1]
	bl ov96_021E7D18
	cmp r0, #0
	beq _021E7BEA
	ldr r0, _021E7C00 ; =0x000008B4
	lsl r1, r5, #1
	ldrh r2, [r6, r0]
	ldr r0, [sp, #4]
	strh r2, [r0, r1]
_021E7BEA:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E7BB4
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7BF8: .word _0221A7D8
_021E7BFC: .word 0x000008D4
_021E7C00: .word 0x000008B4
	thumb_func_end ov96_021E7BA8


	thumb_func_start ov96_021E7C04
ov96_021E7C04: ; 0x021E7C04
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r6, r2, #0
	add r7, r0, #0
	add r0, r6, #0
	add r4, r1, #0
	add r0, #0x80
	ldrh r0, [r0]
	ldrh r1, [r4]
	add r2, r7, #0
	bl ov96_021E7D18
	cmp r0, #0
	beq _021E7C90
	add r6, #0x80
	ldmia r4!, {r0, r1}
	add r5, r6, #0
	stmia r6!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r6!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r6!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r6!, {r0, r1}
	mov r4, #4
_021E7C36:
	add r0, r5, #0
	sub r0, #0x20
	ldrh r0, [r0]
	ldrh r1, [r5]
	add r2, r7, #0
	bl ov96_021E7D18
	cmp r0, #0
	beq _021E7C90
	add r3, r5, #0
	sub r3, #0x20
	add r2, sp, #0
	add r6, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r2, r5, #0
	add r3, r5, #0
	sub r2, #0x20
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r2, r5, #0
	ldmia r6!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r6!, {r0, r1}
	sub r4, r4, #1
	sub r5, #0x20
	stmia r2!, {r0, r1}
	cmp r4, #0
	bgt _021E7C36
_021E7C90:
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021E7C04


	thumb_func_start ov96_021E7C94
ov96_021E7C94: ; 0x021E7C94
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	add r4, r2, #0
	bl ov96_021E5F24
	mov r2, #0
	add r1, r2, #0
_021E7CA2:
	ldrh r0, [r4]
	add r3, r1, #0
	add r6, r4, #0
	strh r0, [r5]
	add r7, r5, #0
_021E7CAC:
	ldrh r0, [r6, #2]
	add r3, r3, #1
	add r6, r6, #2
	strh r0, [r7, #2]
	add r7, r7, #2
	cmp r3, #3
	blt _021E7CAC
	add r2, r2, #1
	add r4, #0x20
	add r5, #8
	cmp r2, #5
	blt _021E7CA2
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E7C94


	thumb_func_start ov96_021E7CC8
ov96_021E7CC8: ; 0x021E7CC8
	push {r4, r5, r6, r7}
	mov r0, #0
	add r3, r1, #0
_021E7CCE:
	ldrh r4, [r2]
	mov r5, #0
	add r6, r2, #0
	strh r4, [r1]
	add r7, r1, #0
_021E7CD8:
	ldrh r4, [r6, #2]
	add r5, r5, #1
	add r6, r6, #2
	strh r4, [r7, #2]
	add r7, r7, #2
	cmp r5, #3
	blt _021E7CD8
	ldr r4, [r2, #8]
	mov r5, #0
	str r4, [r3, #0x2c]
	add r6, r2, #0
	add r7, r3, #0
_021E7CF0:
	ldrh r4, [r6, #0xc]
	add r5, r5, #1
	add r6, r6, #2
	strh r4, [r7, #0x30]
	add r7, r7, #2
	cmp r5, #8
	blt _021E7CF0
	ldrb r5, [r2, #0x1c]
	add r4, r3, #0
	add r4, #0x40
	add r0, r0, #1
	strb r5, [r4]
	add r2, #0x20
	add r1, #8
	add r3, #0x18
	cmp r0, #5
	blt _021E7CCE
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021E7CC8


	thumb_func_start ov96_021E7D18
ov96_021E7D18: ; 0x021E7D18
	push {r3, lr}
	ldr r3, _021E7D2C ; =0x0000FFFF
	cmp r0, r3
	bne _021E7D24
	mov r0, #1
	pop {r3, pc}
_021E7D24:
	bl ov96_021E7D30
	pop {r3, pc}
	nop
_021E7D2C: .word 0x0000FFFF
	thumb_func_end ov96_021E7D18


	thumb_func_start ov96_021E7D30
ov96_021E7D30: ; 0x021E7D30
	push {r4, lr}
	mov r4, #0
	cmp r2, #0
	bne _021E7D4A
	ldr r2, _021E7D68 ; =0x0000FFFF
	cmp r0, r2
	bne _021E7D42
	mov r4, #1
	b _021E7D64
_021E7D42:
	cmp r0, r1
	bge _021E7D64
	mov r4, #1
	b _021E7D64
_021E7D4A:
	cmp r2, #1
	bne _021E7D60
	ldr r2, _021E7D68 ; =0x0000FFFF
	cmp r0, r2
	bne _021E7D58
	mov r4, #1
	b _021E7D64
_021E7D58:
	cmp r0, r1
	ble _021E7D64
	mov r4, #1
	b _021E7D64
_021E7D60:
	bl GF_AssertFail
_021E7D64:
	add r0, r4, #0
	pop {r4, pc}
	.balign 4, 0
_021E7D68: .word 0x0000FFFF
	thumb_func_end ov96_021E7D30


	thumb_func_start ov96_021E7D6C
ov96_021E7D6C: ; 0x021E7D6C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	str r1, [sp]
	ldr r1, _021E7F3C ; =0x0000072C
	add r5, r0, #0
	add r7, r5, r1
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, _021E7F40 ; =0x0098967F
	ldr r0, [r0, #4]
	cmp r0, #1
	bne _021E7DCE
	ldr r2, [sp]
	mov r0, #1
	add r2, #0x38
	bl ov96_021E7F98
	mov r0, #0x1d
	lsl r0, r0, #4
	ldrh r0, [r7, r0]
	lsl r1, r0, #0x1f
	lsr r1, r1, #0x1f
	beq _021E7DBA
	ldr r2, [sp]
	ldr r1, _021E7F40 ; =0x0098967F
	mov r0, #1
	add r2, #0x3c
	bl ov96_021E7F98
	add r0, r5, #0
	bl ov96_021E7F48
	b _021E7E0A
_021E7DBA:
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	beq _021E7E0A
	ldr r2, [sp]
	ldr r1, _021E7F40 ; =0x0098967F
	mov r0, #1
	add r2, #0x40
	bl ov96_021E7F98
	b _021E7E0A
_021E7DCE:
	ldr r2, [sp]
	mov r0, #1
	add r2, r2, #4
	bl ov96_021E7F98
	mov r0, #0x1d
	lsl r0, r0, #4
	ldrh r0, [r7, r0]
	lsl r1, r0, #0x1f
	lsr r1, r1, #0x1f
	beq _021E7DF8
	ldr r2, [sp]
	ldr r1, _021E7F40 ; =0x0098967F
	mov r0, #1
	add r2, #8
	bl ov96_021E7F98
	add r0, r5, #0
	bl ov96_021E7F48
	b _021E7E0A
_021E7DF8:
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	beq _021E7E0A
	ldr r2, [sp]
	ldr r1, _021E7F40 ; =0x0098967F
	mov r0, #1
	add r2, #0xc
	bl ov96_021E7F98
_021E7E0A:
	ldr r0, _021E7F44 ; =0x0000072A
	mov r4, #0
	ldrb r0, [r5, r0]
	cmp r0, #0
	bls _021E7E68
	ldr r0, [sp]
	ldr r6, [sp]
	str r0, [sp, #0xc]
	add r0, #0x6c
	str r0, [sp, #0xc]
	add r6, #0x44
_021E7E20:
	mov r1, #0x72
	add r0, r7, r4
	lsl r1, r1, #2
	ldrb r1, [r0, r1]
	cmp r1, #0
	beq _021E7E46
	lsl r2, r4, #2
	add r3, r5, r2
	mov r2, #0xf6
	lsl r2, r2, #2
	ldr r2, [r3, r2]
	ldr r1, _021E7F40 ; =0x0098967F
	lsl r2, r2, #0x18
	lsr r2, r2, #0x16
	mov r0, #1
	add r2, r6, r2
	bl ov96_021E7F98
	b _021E7E5A
_021E7E46:
	mov r1, #0x73
	lsl r1, r1, #2
	ldrb r0, [r0, r1]
	cmp r0, #0
	beq _021E7E5A
	ldr r1, _021E7F40 ; =0x0098967F
	ldr r2, [sp, #0xc]
	mov r0, #1
	bl ov96_021E7F98
_021E7E5A:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, _021E7F44 ; =0x0000072A
	ldrb r0, [r5, r0]
	cmp r4, r0
	blo _021E7E20
_021E7E68:
	ldr r0, [sp, #8]
	mov r1, #0x60
	mul r1, r0
	add r0, r7, r1
	str r0, [sp, #4]
	ldr r0, [sp]
	ldr r4, _021E7F40 ; =0x0098967F
	str r0, [sp, #0x10]
	add r0, #0x18
	str r0, [sp, #0x10]
	ldr r0, [sp]
	mov r6, #0
	str r0, [sp, #0x14]
	add r0, #0x1c
	str r0, [sp, #0x14]
	ldr r0, [sp]
	str r0, [sp, #0x18]
	add r0, #0x20
	str r0, [sp, #0x18]
	ldr r0, [sp]
	str r0, [sp, #0x1c]
	add r0, #0x24
	str r0, [sp, #0x1c]
	ldr r0, [sp]
	str r0, [sp, #0x20]
	add r0, #0x28
	str r0, [sp, #0x20]
	ldr r0, [sp]
	str r0, [sp, #0x24]
	add r0, #0x2c
	str r0, [sp, #0x24]
	ldr r0, [sp]
	str r0, [sp, #0x28]
	add r0, #0x30
	str r0, [sp, #0x28]
	ldr r0, [sp]
	str r0, [sp, #0x2c]
	add r0, #0x34
	str r0, [sp, #0x2c]
_021E7EB6:
	ldr r0, [sp, #4]
	lsl r1, r6, #5
	add r5, r0, r1
	ldr r0, [r0, r1]
	ldr r2, [sp, #0x10]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #4]
	ldr r2, [sp, #0x14]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #8]
	ldr r2, [sp, #0x18]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0xc]
	ldr r2, [sp, #0x1c]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0x10]
	ldr r2, [sp, #0x20]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0x14]
	ldr r2, [sp, #0x24]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0x18]
	ldr r2, [sp, #0x28]
	add r1, r4, #0
	bl ov96_021E7F98
	ldr r0, [r5, #0x1c]
	ldr r2, [sp, #0x2c]
	add r1, r4, #0
	bl ov96_021E7F98
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #3
	blo _021E7EB6
	mov r0, #6
	lsl r0, r0, #6
	ldr r2, [sp]
	ldr r0, [r7, r0]
	ldr r1, _021E7F40 ; =0x0098967F
	add r2, #0x10
	bl ov96_021E7F98
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r2, [sp]
	ldr r0, [r7, r0]
	add r2, #0x14
	ldr r1, _021E7F40 ; =0x0098967F
	str r2, [sp]
	bl ov96_021E7F98
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7F3C: .word 0x0000072C
_021E7F40: .word 0x0098967F
_021E7F44: .word 0x0000072A
	thumb_func_end ov96_021E7D6C


	thumb_func_start ov96_021E7F48
ov96_021E7F48: ; 0x021E7F48
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0]
	bl Save_Pokeathlon_FriendshipRecords_Get
	add r4, r0, #0
	add r0, r5, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	mov r0, #0x3f
	lsl r0, r0, #4
	add r1, r5, r0
	mov r0, #0x7c
	mul r0, r2
	add r3, r1, r0
	mov r2, #0
	mov r5, #0x28
_021E7F74:
	add r6, r2, #0
	mul r6, r5
	add r1, r3, r6
	ldrh r6, [r3, r6]
	lsl r7, r2, #2
	add r0, r4, r7
	strh r6, [r4, r7]
	ldrh r6, [r1, #2]
	strb r6, [r0, #3]
	ldrb r1, [r1, #0x11]
	strb r1, [r0, #2]
	add r0, r2, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r2, #3
	blo _021E7F74
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E7F48

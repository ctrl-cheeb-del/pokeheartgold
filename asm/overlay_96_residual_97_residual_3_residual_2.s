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
	.public ov96_0220CBC0
	.public ov96_0220CBEC
	.public ov96_0220CC18
	.public ov96_0220CCBC
	.public ov96_0220D33C
	.public ov96_0220D13C




	thumb_func_start ov96_0220D1A0
ov96_0220D1A0: ; 0x0220D1A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r6, _0220D1FC ; =ov96_0221CEB8
	add r7, r2, #0
	str r3, [sp]
	add r5, r0, #0
	add r4, r1, #0
	add r3, sp, #4
	mov r2, #6
_0220D1B2:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220D1B2
	ldr r0, [r6]
	cmp r5, #0
	str r0, [r3]
	bne _0220D1C6
	bl GF_AssertFail
_0220D1C6:
	cmp r4, #0
	bne _0220D1CE
	bl GF_AssertFail
_0220D1CE:
	add r1, sp, #4
	strh r7, [r1]
	ldr r0, [sp]
	mov r3, #1
	strh r0, [r1, #2]
	add r0, sp, #0x40
	ldrh r2, [r0, #0x10]
	lsl r3, r3, #0x14
	strh r2, [r1, #6]
	ldrh r0, [r0, #0x14]
	add r1, r4, #0
	add r2, sp, #4
	str r0, [sp, #0xc]
	add r0, r5, #0
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	add r4, r0, #0
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220D1FC: .word ov96_0221CEB8
	thumb_func_end ov96_0220D1A0








	thumb_func_start ov96_0220D200
ov96_0220D200: ; 0x0220D200
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r5, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	add r0, sp, #8
	mov r1, #0xaa
	mov r2, #5
	bl ReadWholeNarcMemberByIdPair
	mov r6, #0
	add r7, sp, #8
_0220D218:
	ldr r0, [sp, #4]
	ldr r1, [sp]
	add r2, r6, #0
	bl ov96_021E60D8
	add r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #5
	blo _0220D22E
	bl GF_AssertFail
_0220D22E:
	ldrb r0, [r4, #3]
	cmp r0, #5
	blo _0220D238
	bl GF_AssertFail
_0220D238:
	ldrb r0, [r4, #4]
	cmp r0, #5
	blo _0220D242
	bl GF_AssertFail
_0220D242:
	ldr r1, [r5]
	ldr r0, _0220D298 ; =0xFFFFFE00
	add r6, r6, #1
	and r0, r1
	ldrb r1, [r4]
	lsl r1, r1, #2
	ldr r2, [r7, r1]
	ldr r1, _0220D29C ; =0x000001FF
	and r1, r2
	orr r1, r0
	ldr r0, _0220D2A0 ; =0xFFFC01FF
	str r1, [r5]
	and r0, r1
	ldrb r1, [r4, #3]
	lsl r1, r1, #2
	add r1, r7, r1
	ldr r1, [r1, #0x14]
	lsl r1, r1, #0x17
	lsr r1, r1, #0xe
	orr r1, r0
	ldr r0, _0220D2A4 ; =0x03FFFFFF
	str r1, [r5]
	and r0, r1
	ldrb r1, [r4, #4]
	lsl r1, r1, #2
	add r1, r7, r1
	ldr r1, [r1, #0x28]
	lsl r1, r1, #0x1a
	orr r1, r0
	ldr r0, _0220D2A8 ; =0xFC03FFFF
	str r1, [r5]
	and r0, r1
	lsl r1, r1, #0xe
	lsr r1, r1, #0x17
	lsl r1, r1, #0x18
	lsr r1, r1, #6
	orr r0, r1
	stmia r5!, {r0}
	cmp r6, #3
	blt _0220D218
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_0220D298: .word 0xFFFFFE00
_0220D29C: .word 0x000001FF
_0220D2A0: .word 0xFFFC01FF
_0220D2A4: .word 0x03FFFFFF
_0220D2A8: .word 0xFC03FFFF
	thumb_func_end ov96_0220D200








	thumb_func_start ov96_0220D2AC
ov96_0220D2AC: ; 0x0220D2AC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r1, #0
	add r5, r0, #0
	add r0, r7, #0
	mov r1, #0x3c
	str r2, [sp]
	mov r4, #0
	bl _u32_div_f
	str r1, [sp, #4]
	add r0, r7, #0
	mov r1, #0x1e
	bl _u32_div_f
	add r6, r1, #0
_0220D2CC:
	ldr r1, [r5]
	lsl r0, r1, #6
	lsl r3, r1, #0xe
	lsr r2, r0, #0x18
	lsr r3, r3, #0x17
	lsl r0, r2, #0x10
	lsl r3, r3, #0x10
	lsr r0, r0, #0x10
	lsr r3, r3, #0x10
	cmp r7, #0
	beq _0220D32A
	cmp r0, r3
	bhs _0220D32A
	ldr r0, [sp]
	cmp r4, r0
	bne _0220D302
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0220D314
	ldr r0, _0220D338 ; =0xFC03FFFF
	add r2, #8
	and r0, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #6
	orr r0, r1
	str r0, [r5]
	b _0220D314
_0220D302:
	cmp r6, #0
	bne _0220D314
	ldr r0, _0220D338 ; =0xFC03FFFF
	and r0, r1
	add r1, r2, #5
	lsl r1, r1, #0x18
	lsr r1, r1, #6
	orr r0, r1
	str r0, [r5]
_0220D314:
	ldr r1, [r5]
	lsl r0, r1, #6
	lsr r0, r0, #0x18
	cmp r0, r3
	bls _0220D32A
	ldr r0, _0220D338 ; =0xFC03FFFF
	and r0, r1
	lsl r1, r3, #0x18
	lsr r1, r1, #6
	orr r0, r1
	str r0, [r5]
_0220D32A:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _0220D2CC
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220D338: .word 0xFC03FFFF
	thumb_func_end ov96_0220D2AC



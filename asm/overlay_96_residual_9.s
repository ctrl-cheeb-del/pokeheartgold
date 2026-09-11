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

	thumb_func_start ov96_021E8324
ov96_021E8324: ; 0x021E8324
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021E833C ; =0x00000D6C
	add r4, r1, #0
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021E8336
	bl GF_AssertFail
_021E8336:
	ldr r0, _021E833C ; =0x00000D6C
	str r4, [r5, r0]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E833C: .word 0x00000D6C
	thumb_func_end ov96_021E8324


	thumb_func_start ov96_021E8340
ov96_021E8340: ; 0x021E8340
	push {r3, lr}
	cmp r0, #8
	bhi _021E8382
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E8352: ; jump table
	.short _021E8382 - _021E8352 - 2 ; case 0
	.short _021E8364 - _021E8352 - 2 ; case 1
	.short _021E8366 - _021E8352 - 2 ; case 2
	.short _021E836A - _021E8352 - 2 ; case 3
	.short _021E836E - _021E8352 - 2 ; case 4
	.short _021E8372 - _021E8352 - 2 ; case 5
	.short _021E8376 - _021E8352 - 2 ; case 6
	.short _021E837A - _021E8352 - 2 ; case 7
	.short _021E837E - _021E8352 - 2 ; case 8
_021E8364:
	b _021E8388
_021E8366:
	add r2, r2, #4
	b _021E8388
_021E836A:
	add r2, #8
	b _021E8388
_021E836E:
	add r2, #0xc
	b _021E8388
_021E8372:
	add r2, #0x10
	b _021E8388
_021E8376:
	add r2, #0x14
	b _021E8388
_021E837A:
	add r2, #0x18
	b _021E8388
_021E837E:
	add r2, #0x1c
	b _021E8388
_021E8382:
	bl GF_AssertFail
	pop {r3, pc}
_021E8388:
	ldr r0, [r2]
	add r1, r0, r1
	ldr r0, _021E8398 ; =0x0000270F
	str r1, [r2]
	cmp r1, r0
	bls _021E8396
	str r0, [r2]
_021E8396:
	pop {r3, pc}
	.balign 4, 0
_021E8398: .word 0x0000270F
	thumb_func_end ov96_021E8340


	thumb_func_start ov96_021E839C
ov96_021E839C: ; 0x021E839C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0]
	bl Save_Pokeathlon_Get
	add r6, r0, #0
	ldr r0, _021E8418 ; =0x00000D2A
	ldrh r1, [r5, r0]
	ldr r0, _021E841C ; =0x0000FFFF
	cmp r1, r0
	bne _021E83C0
	bl GF_AssertFail
	mov r0, #0
	pop {r4, r5, r6, pc}
_021E83C0:
	add r0, r5, #0
	bl PokeathlonCourse_GetField3D8_ForCurrentParticipant
	add r4, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0, #4]
	cmp r0, #1
	bne _021E83DE
	add r0, r6, #0
	bl PokeathlonSave_GetRecordsLink2
	mov r1, #0xa4
	b _021E83E6
_021E83DE:
	add r0, r6, #0
	bl PokeathlonSave_GetRecordsSolo2
	mov r1, #0x2c
_021E83E6:
	mul r1, r4
	add r0, r0, r1
	ldrh r0, [r0]
	ldr r1, _021E841C ; =0x0000FFFF
	cmp r0, r1
	bne _021E83F6
	mov r0, #1
	pop {r4, r5, r6, pc}
_021E83F6:
	ldr r1, _021E8420 ; =_0221A7D8
	ldrb r1, [r1, r4]
	cmp r1, #0
	ldr r1, _021E8418 ; =0x00000D2A
	bne _021E840A
	ldrh r1, [r5, r1]
	cmp r0, r1
	bhs _021E8414
	mov r0, #1
	pop {r4, r5, r6, pc}
_021E840A:
	ldrh r1, [r5, r1]
	cmp r0, r1
	bls _021E8414
	mov r0, #1
	pop {r4, r5, r6, pc}
_021E8414:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E8418: .word 0x00000D2A
_021E841C: .word 0x0000FFFF
_021E8420: .word _0221A7D8
	thumb_func_end ov96_021E839C


	thumb_func_start ov96_021E8424
ov96_021E8424: ; 0x021E8424
	push {r3, lr}
	cmp r0, #0
	beq _021E843A
	cmp r0, #0x64
	bhi _021E843A
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x17
	ldr r0, _021E8444 ; =ov96_0221AA20
	ldrh r0, [r0, r1]
	pop {r3, pc}
_021E843A:
	bl GF_AssertFail
	mov r0, #0
	pop {r3, pc}
	nop
_021E8444: .word ov96_0221AA20
	thumb_func_end ov96_021E8424


	thumb_func_start ov96_021E8448
ov96_021E8448: ; 0x021E8448
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r1, #0
	beq _021E847A
	cmp r5, #0x64
	bhi _021E847A
	bl PokeathlonCourse_GetHeapID
	add r1, r0, #0
	mov r0, #0x41
	lsl r0, r0, #2
	bl NARC_New
	add r4, r0, #0
	sub r1, r5, #1
	add r2, sp, #0
	bl NARC_ReadWholeMember
	add r0, r4, #0
	bl NARC_Delete
	add r0, sp, #0
	add sp, #8
	ldrb r0, [r0, #7]
	pop {r3, r4, r5, pc}
_021E847A:
	bl GF_AssertFail
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021E8448


	thumb_func_start ov96_021E8484
ov96_021E8484: ; 0x021E8484
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	str r0, [sp]
	add r4, r1, #0
	bl PokeathlonCourse_GetHeapID
	add r3, r0, #0
	ldr r2, _021E8608 ; =0x00000136
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	str r0, [sp, #0x14]
	mov r0, #4
	sub r0, r0, r4
	str r0, [sp, #4]
	mov r1, #0x7e
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r2, [r0, r1]
	add r0, r4, #0
	ldrb r1, [r2, #0xc]
	ldrb r2, [r2, #0xf]
	add r3, sp, #0x2c
	bl ov96_021E860C
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapID
	add r1, r0, #0
	mov r0, #0xa9
	bl NARC_New
	str r0, [sp, #0x10]
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapID
	add r1, r0, #0
	mov r0, #0x41
	lsl r0, r0, #2
	bl NARC_New
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x1c]
	ldr r0, [sp, #4]
	cmp r0, #4
	bge _021E84E6
	blt _021E84E8
_021E84E6:
	b _021E85F0
_021E84E8:
	add r0, sp, #0x2c
	str r0, [sp, #8]
_021E84EC:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl PokeathlonCourse_GetParticipantData
	add r5, r0, #0
	ldr r0, [sp, #8]
	ldrb r0, [r0]
	str r0, [r5]
	cmp r0, #0
	bne _021E8504
	bl GF_AssertFail
_021E8504:
	ldr r1, [r5]
	ldr r0, [sp, #0xc]
	sub r1, r1, #1
	add r2, sp, #0x24
	bl NARC_ReadWholeMember
	add r1, sp, #0x24
	ldrb r1, [r1, #6]
	ldr r0, [sp, #0x14]
	bl NewString_ReadMsgData
	add r4, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl PokeathlonCourse_GetPlayerProfileFromData
	add r6, r0, #0
	add r0, r4, #0
	bl String_cstr
	add r1, r0, #0
	add r0, r6, #0
	bl Save_Profile_PlayerName_Set
	add r0, r4, #0
	bl String_Delete
	mov r0, #0
	add r6, r5, #0
	str r0, [sp, #0x18]
	add r4, sp, #0x24
	add r6, #0x16
	add r7, sp, #0x24
_021E8546:
	ldrh r0, [r4]
	mov r1, #0x12
	strh r0, [r5, #4]
	mov r0, #0
	strh r0, [r5, #6]
	strb r0, [r5, #0x14]
	str r0, [r5, #8]
	ldrh r0, [r5, #4]
	bl GetMonBaseStat
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _021E856A
	cmp r0, #0xfe
	beq _021E856E
	cmp r0, #0xff
	beq _021E8572
	b _021E8576
_021E856A:
	mov r0, #0
	b _021E8578
_021E856E:
	mov r0, #1
	b _021E8578
_021E8572:
	mov r0, #2
	b _021E8578
_021E8576:
	mov r0, #0
_021E8578:
	strb r0, [r5, #0x15]
	ldrh r0, [r5, #4]
	mov r1, #0
	bl ov96_021E679C
	add r1, r0, #0
	add r2, sp, #0x2c
	ldr r0, [sp, #0x10]
	add r2, #3
	bl NARC_ReadWholeMember
	ldrb r0, [r7, #0xb]
	strb r0, [r5, #0xc]
	ldrb r0, [r7, #0xc]
	strb r0, [r5, #0xd]
	ldrb r0, [r7, #0xd]
	strb r0, [r5, #0xe]
	ldrb r0, [r7, #0xe]
	strb r0, [r5, #0xf]
	ldrb r0, [r7, #0xf]
	strb r0, [r5, #0x10]
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapID
	add r1, r0, #0
	ldrh r0, [r4]
	bl GetSpeciesName
	str r0, [sp, #0x20]
	bl String_cstr
	add r1, r0, #0
	add r0, r6, #0
	mov r2, #0xb
	bl CopyU16StringArrayN
	ldr r0, [sp, #0x20]
	bl String_Delete
	ldr r0, [sp, #0x18]
	add r4, r4, #2
	add r0, r0, #1
	add r5, #0x28
	add r6, #0x28
	str r0, [sp, #0x18]
	cmp r0, #3
	blt _021E8546
	ldr r0, [sp, #4]
	add r0, r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #4]
	cmp r0, #4
	bge _021E85F0
	b _021E84EC
_021E85F0:
	ldr r0, [sp, #0xc]
	bl NARC_Delete
	ldr r0, [sp, #0x10]
	bl NARC_Delete
	ldr r0, [sp, #0x14]
	bl DestroyMsgData
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_021E8608: .word 0x00000136
	thumb_func_end ov96_021E8484


	thumb_func_start ov96_021E860C
ov96_021E860C: ; 0x021E860C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	add r0, r1, #0
	mov r1, #0
	str r2, [sp]
	add r4, r3, #0
	add r2, r1, #0
_021E861C:
	strb r2, [r4, r1]
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, #3
	blo _021E861C
	cmp r0, #0xa
	bne _021E8678
	add r1, sp, #0xc
	mov r7, #0x19
	add r1, #1
_021E8632:
	add r0, r2, #1
	lsl r0, r0, #0x18
	strb r2, [r1, r2]
	lsr r2, r0, #0x18
	cmp r2, #0x19
	blo _021E8632
	mov r6, #0
	cmp r5, #0
	bls _021E86C4
_021E8644:
	bl LCRandom
	add r1, r7, #0
	bl _s32_div_f
	lsl r0, r1, #0x18
	add r1, sp, #0xc
	lsr r0, r0, #0x18
	add r1, #1
	ldrb r1, [r1, r0]
	strb r1, [r4, r6]
	add r1, #0x19
	strb r1, [r4, r6]
	sub r1, r7, #1
	lsl r1, r1, #0x18
	lsr r7, r1, #0x18
	add r1, sp, #0xc
	add r1, #1
	ldrb r2, [r1, r7]
	strb r2, [r1, r0]
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, r5
	blo _021E8644
	b _021E86C4
_021E8678:
	mov r7, #5
	add r1, sp, #8
_021E867C:
	strb r2, [r1, r2]
	add r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	cmp r2, #5
	blo _021E867C
	mov r6, #0
	cmp r5, #0
	bls _021E86C4
	lsl r1, r0, #2
	add r0, r0, r1
	str r0, [sp, #4]
_021E8694:
	bl LCRandom
	add r1, r7, #0
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	add r1, sp, #8
	ldrb r2, [r1, r0]
	ldr r1, [sp, #4]
	strb r2, [r4, r6]
	add r1, r2, r1
	strb r1, [r4, r6]
	sub r1, r7, #1
	lsl r1, r1, #0x18
	lsr r7, r1, #0x18
	add r1, sp, #8
	ldrb r2, [r1, r7]
	strb r2, [r1, r0]
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, r5
	blo _021E8694
_021E86C4:
	ldr r0, [sp]
	cmp r0, #0
	beq _021E86E0
	mov r1, #0
	cmp r5, #0
	bls _021E86E0
_021E86D0:
	ldrb r0, [r4, r1]
	add r0, #0x32
	strb r0, [r4, r1]
	add r0, r1, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	cmp r1, r5
	blo _021E86D0
_021E86E0:
	mov r1, #0
	cmp r5, #0
	bls _021E86F6
_021E86E6:
	ldrb r0, [r4, r1]
	add r0, r0, #1
	strb r0, [r4, r1]
	add r0, r1, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	cmp r1, r5
	blo _021E86E6
_021E86F6:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E860C


	thumb_func_start ov96_021E86FC
ov96_021E86FC: ; 0x021E86FC
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #4
	blo _021E870A
	bl GF_AssertFail
_021E870A:
	ldr r0, _021E8728 ; =0x00000D68
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _021E8716
	bl GF_AssertFail
_021E8716:
	bl sub_02031B10
	ldr r1, _021E8728 ; =0x00000D68
	ldr r2, [r5, r1]
	add r1, r0, #0
	mul r1, r4
	add r0, r2, r1
	pop {r3, r4, r5, pc}
	nop
_021E8728: .word 0x00000D68
	thumb_func_end ov96_021E86FC


	thumb_func_start ov96_021E872C
ov96_021E872C: ; 0x021E872C
	push {lr}
	sub sp, #0x24
	lsl r0, r0, #0xc
	str r0, [sp, #0x18]
	lsl r0, r1, #0xc
	mov r1, #0
	str r0, [sp, #0x1c]
	lsl r0, r2, #0xc
	str r0, [sp, #0xc]
	lsl r0, r3, #0xc
	str r0, [sp, #0x10]
	str r1, [sp, #0x20]
	str r1, [sp, #0x14]
	add r0, sp, #0x18
	add r1, sp, #0xc
	add r2, sp, #0
	bl VEC_Subtract
	add r0, sp, #0
	bl VEC_Mag
	ldr r1, [sp, #0x2c]
	str r0, [r1]
	ldr r1, [sp, #0x28]
	lsl r1, r1, #0xc
	cmp r0, r1
	bge _021E8768
	add sp, #0x24
	mov r0, #1
	pop {pc}
_021E8768:
	mov r0, #0
	add sp, #0x24
	pop {pc}
	.balign 4, 0
	thumb_func_end ov96_021E872C


	thumb_func_start ov96_021E8770
ov96_021E8770: ; 0x021E8770
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r7, r1, #0
	ldr r0, [sp, #0x18]
	mov r1, #8
	str r2, [sp]
	add r5, r3, #0
	bl Heap_Alloc
	add r4, r0, #0
	mov r0, #0
	strh r5, [r4]
	strh r0, [r4, #2]
	str r0, [r4, #4]
	cmp r5, #1
	bne _021E879C
	ldr r2, [sp]
	add r0, r6, #0
	add r1, r7, #0
	bl sub_0203410C
	b _021E87AA
_021E879C:
	ldr r2, [sp]
	ldr r3, [sp, #0x18]
	add r0, r6, #0
	add r1, r7, #0
	bl ov96_021E883C
	str r0, [r4, #4]
_021E87AA:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E8770

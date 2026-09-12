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

	thumb_func_start ov96_02208B34
ov96_02208B34: ; 0x02208B34
	push {r3, r4, r5, lr}
	ldr r1, _02208BB0 ; =0x00000559
	add r4, r0, #0
	ldrb r2, [r4, r1]
	mov r0, #4
	cmp r2, #4
	bne _02208B46
	mov r0, #0
	pop {r3, r4, r5, pc}
_02208B46:
	sub r2, r1, #3
	ldrb r2, [r4, r2]
	add r3, r2, #1
	sub r2, r1, #3
	strb r3, [r4, r2]
	ldrb r3, [r4, r2]
	sub r2, r1, #2
	ldrb r2, [r4, r2]
	cmp r3, r2
	blo _02208B68
	add r2, r1, #0
	mov r3, #1
	sub r2, #9
	str r3, [r4, r2]
	mov r2, #0
	sub r1, r1, #3
	strb r2, [r4, r1]
_02208B68:
	mov r1, #0x55
	lsl r1, r1, #4
	ldr r2, [r4, r1]
	cmp r2, #0
	beq _02208BAE
	add r0, r1, #0
	add r0, #8
	ldrb r2, [r4, r0]
	add r0, r1, #5
	ldrb r0, [r4, r0]
	add r5, r2, r0
	cmp r5, r2
	bge _02208B86
	bl GF_AssertFail
_02208B86:
	lsl r1, r5, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_02208BB8
	ldr r1, _02208BB4 ; =0x00000555
	lsl r0, r5, #0x18
	ldrb r2, [r4, r1]
	lsr r0, r0, #0x18
	add r2, r2, #1
	strb r2, [r4, r1]
	sub r2, r1, #1
	ldrb r3, [r4, r1]
	ldrb r2, [r4, r2]
	cmp r3, r2
	blo _02208BAE
	mov r2, #0
	strb r2, [r4, r1]
	sub r1, r1, #5
	str r2, [r4, r1]
_02208BAE:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02208BB0: .word 0x00000559
_02208BB4: .word 0x00000555
	thumb_func_end ov96_02208B34


	thumb_func_start ov96_02208BB8
ov96_02208BB8: ; 0x02208BB8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x1c0
	str r0, [sp, #4]
	lsl r0, r1, #3
	str r1, [sp, #8]
	ldr r1, [sp, #4]
	str r0, [sp, #0x10]
	ldr r0, [r1, r0]
	str r0, [sp, #0x14]
	add r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _02208BE6
	ldr r0, [sp, #0x14]
	add r0, #0xa6
	ldrb r0, [r0]
	cmp r0, #1
	beq _02208BE6
	ldr r0, [sp, #0x14]
	add r0, #0xa4
	ldrb r0, [r0]
	cmp r0, #0
	beq _02208BE8
_02208BE6:
	b _02208FAC
_02208BE8:
	mov r7, #0
	add r6, r1, #0
	add r5, sp, #0x38
_02208BEE:
	ldr r1, [r6]
	ldr r0, [r6, #4]
	str r1, [r5]
	str r0, [r5, #4]
	ldr r4, [r5]
	add r0, sp, #0x30
	str r0, [sp]
	ldr r1, [r4, #0x58]
	add r0, r4, #0
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r0, #0xb1
	add r2, r1, r2
	ldrb r0, [r0]
	asr r1, r2, #0xc
	ldr r2, [r4, #0x5c]
	lsl r0, r0, #2
	asr r3, r2, #0xb
	lsr r3, r3, #0x14
	add r3, r2, r3
	asr r2, r3, #0xc
	ldr r0, [r4, r0]
	add r3, sp, #0x34
	bl ov96_021EB0A4
	add r0, sp, #0x28
	str r0, [sp]
	add r0, r4, #0
	add r0, #0xb1
	ldrb r0, [r0]
	ldr r1, [sp, #0x34]
	ldr r2, [sp, #0x30]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x2c
	bl ov96_021EB03C
	ldr r1, [sp, #0x2c]
	add r7, r7, #1
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [sp, #0x28]
	strh r0, [r5, #4]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	strh r0, [r5, #6]
	add r6, #8
	add r5, #8
	cmp r7, #4
	blt _02208BEE
	ldr r0, [sp, #0x10]
	add r1, sp, #0x38
	add r0, r1, r0
	ldr r2, [sp, #4]
	str r0, [sp, #0x1c]
	mov r4, #0
	add r3, sp, #0xd0
_02208C6C:
	add r6, r2, #0
	add r6, #0x20
	ldmia r6!, {r0, r1}
	add r5, r3, #0
	stmia r5!, {r0, r1}
	ldr r0, [r6]
	add r4, r4, #1
	str r0, [r5]
	add r2, #0xc
	add r3, #0xc
	cmp r4, #0x14
	blt _02208C6C
	mov r7, #0x11
	ldr r4, [sp, #4]
	mov r6, #0
	add r5, sp, #0x58
	lsl r7, r7, #4
_02208C8E:
	add r3, r4, r7
	ldmia r3!, {r0, r1}
	add r2, r5, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r6, r6, #1
	str r0, [r2]
	add r4, #0xc
	add r5, #0xc
	cmp r6, #0xa
	blt _02208C8E
	mov r1, #0x62
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	ldr r4, [sp, #4]
	str r0, [sp, #0x18]
	mov r5, #0
_02208CB2:
	ldr r0, _02208FB0 ; =0x000001A2
	mov r1, #6
	strh r5, [r4, r0]
	add r0, r5, #0
	bl _s32_div_f
	ldr r0, [sp, #0x1c]
	lsl r7, r1, #5
	ldrh r0, [r0, #4]
	sub r0, #0x50
	add r1, r0, r7
	mov r0, #0x19
	lsl r0, r0, #4
	str r1, [r4, r0]
	add r0, r5, #0
	mov r1, #6
	bl _s32_div_f
	lsl r6, r0, #5
	ldr r0, [sp, #0x1c]
	ldrh r0, [r0, #6]
	sub r0, #0x30
	add r1, r0, r6
	mov r0, #0x65
	lsl r0, r0, #2
	str r1, [r4, r0]
	bl LCRandom
	ldr r1, [sp, #0x1c]
	lsl r3, r0, #0x1b
	ldrh r1, [r1, #4]
	sub r1, #0x60
	add r2, r1, r7
	lsr r1, r0, #0x1f
	sub r3, r3, r1
	mov r0, #0x1b
	ror r3, r0
	add r0, r1, r3
	add r1, r2, r0
	mov r0, #0x66
	lsl r0, r0, #2
	str r1, [r4, r0]
	bl LCRandom
	ldr r1, [sp, #0x1c]
	lsr r3, r0, #0x1f
	lsl r2, r0, #0x1b
	ldrh r1, [r1, #6]
	sub r2, r2, r3
	mov r0, #0x1b
	sub r1, #0x80
	ror r2, r0
	add r1, r1, r6
	add r0, r3, r2
	add r1, r1, r0
	mov r0, #0x67
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r5, r5, #1
	add r4, #0x14
	cmp r5, #0x30
	blt _02208CB2
	mov r2, #0
	ldr r1, [sp, #4]
	add r5, r2, #0
	add r0, r0, #4
_02208D36:
	add r2, r2, #1
	strh r5, [r1, r0]
	add r1, #0x14
	cmp r2, #0x30
	blt _02208D36
	mov r1, #0x1a
	lsl r1, r1, #4
	mov r7, #0
	mov r0, #0x14
	add r2, r1, #0
_02208D4A:
	add r4, r7, #0
_02208D4C:
	add r3, r4, #0
	add r3, #0x13
	lsl r3, r3, #0x18
	lsr r6, r3, #0x18
	add r3, r6, #0
	ldr r6, [sp, #4]
	mul r3, r0
	add r3, r6, r3
	ldrsh r6, [r3, r1]
	add r4, r4, #1
	add r6, r6, #2
	strh r6, [r3, r2]
	cmp r4, #4
	blt _02208D4C
	add r5, r5, #1
	cmp r5, #2
	blt _02208D4A
	mov r0, #0
	str r0, [sp, #0xc]
	mov r1, #0x19
	ldr r0, [sp, #4]
	lsl r1, r1, #4
	add r4, r0, r1
_02208D7A:
	add r6, r4, #0
	ldr r5, [sp, #0x18]
	mov r7, #0
	add r6, #0x10
_02208D82:
	ldr r0, [r5]
	cmp r0, #0
	beq _02208D9E
	ldrh r1, [r5, #0x10]
	ldrh r2, [r5, #0x12]
	add r0, r4, #0
	bl ov96_022090A8
	cmp r0, #0
	beq _02208D9E
	mov r0, #0
	ldrsh r0, [r6, r0]
	add r0, r0, #7
	strh r0, [r6]
_02208D9E:
	add r7, r7, #1
	add r5, #0x14
	cmp r7, #5
	blt _02208D82
	add r7, r4, #0
	mov r5, #0
	add r6, sp, #0x38
	add r7, #0x10
_02208DAE:
	ldr r0, [sp, #8]
	cmp r5, r0
	beq _02208DCA
	ldrh r1, [r6, #4]
	ldrh r2, [r6, #6]
	add r0, r4, #0
	bl ov96_022090A8
	cmp r0, #0
	beq _02208DCA
	mov r0, #0
	ldrsh r0, [r7, r0]
	sub r0, r0, #3
	strh r0, [r7]
_02208DCA:
	add r5, r5, #1
	add r6, #8
	cmp r5, #4
	blt _02208DAE
	add r6, r4, #0
	mov r7, #0
	add r5, sp, #0xd0
	add r6, #0x10
_02208DDA:
	ldr r0, [r5]
	cmp r0, #0
	beq _02208E06
	ldr r1, [r5, #4]
	ldr r2, [r5, #8]
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	add r0, r4, #0
	lsr r1, r1, #0x10
	lsr r2, r2, #0x10
	bl ov96_022090A8
	cmp r0, #0
	beq _02208DFE
	mov r0, #0
	ldrsh r0, [r6, r0]
	sub r0, r0, #2
	strh r0, [r6]
_02208DFE:
	add r7, r7, #1
	add r5, #0xc
	cmp r7, #0x14
	blt _02208DDA
_02208E06:
	add r6, r4, #0
	mov r7, #0
	add r5, sp, #0x58
	add r6, #0x10
_02208E0E:
	ldr r0, [r5]
	cmp r0, #0
	beq _02208E3A
	ldr r1, [r5, #4]
	ldr r2, [r5, #8]
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	add r0, r4, #0
	lsr r1, r1, #0x10
	lsr r2, r2, #0x10
	bl ov96_022090A8
	cmp r0, #0
	beq _02208E32
	mov r0, #0
	ldrsh r0, [r6, r0]
	add r0, r0, #2
	strh r0, [r6]
_02208E32:
	add r7, r7, #1
	add r5, #0xc
	cmp r7, #0xa
	blt _02208E0E
_02208E3A:
	add r0, r4, #0
	bl ov96_022090D8
	cmp r0, #0
	bne _02208E4C
	mov r0, #0x10
	ldrsh r0, [r4, r0]
	sub r0, #0x64
	strh r0, [r4, #0x10]
_02208E4C:
	ldr r0, [sp, #0xc]
	add r4, #0x14
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0x30
	blt _02208D7A
	ldr r0, [sp, #0x14]
	ldr r1, [r0, #0x5c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	lsl r0, r0, #4
	lsr r1, r0, #0x10
	mov r0, #1
	lsl r0, r0, #8
	cmp r1, r0
	bls _02208E8E
	mov r4, #0x96
	add r3, r0, #0
	lsl r4, r4, #2
	ldr r1, [sp, #4]
	mov r2, #0
	add r3, #0xa0
	add r5, r4, #0
_02208E7C:
	add r0, r1, r3
	ldrsh r6, [r0, r4]
	add r2, r2, #1
	add r1, #0x14
	add r6, r6, #3
	strh r6, [r0, r5]
	cmp r2, #6
	blt _02208E7C
	b _02208EA8
_02208E8E:
	bhs _02208EA8
	mov r1, #0x1a
	ldr r3, [sp, #4]
	mov r4, #0
	add r0, #0xa0
	lsl r1, r1, #4
_02208E9A:
	ldrsh r2, [r3, r0]
	add r4, r4, #1
	add r2, r2, #3
	strh r2, [r3, r1]
	add r3, #0x14
	cmp r4, #6
	blt _02208E9A
_02208EA8:
	ldr r0, [sp, #0x14]
	add r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _02208F2E
	mov r7, #0x1a
	lsl r7, r7, #4
	add r4, r7, #0
	add r6, r7, #0
	ldr r2, [sp, #4]
	mov r3, #0
	add r4, #0xb8
	add r6, #0xb8
_02208EC2:
	ldr r5, [sp, #0x14]
	add r1, r2, r7
	add r5, #0xaa
	ldrsh r0, [r1, r4]
	ldrb r5, [r5]
	add r3, r3, #1
	add r2, #0x14
	add r0, r0, r5
	strh r0, [r1, r6]
	cmp r3, #6
	blt _02208EC2
	ldr r0, [sp, #0x14]
	ldr r1, [r0, #0x58]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	lsl r0, r0, #4
	lsr r1, r0, #0x10
	mov r0, #1
	lsl r0, r0, #8
	cmp r1, r0
	bls _02208F0E
	mov r4, #0x96
	add r3, r0, #0
	lsl r4, r4, #2
	ldr r1, [sp, #4]
	mov r2, #0
	add r3, #0xa0
	add r5, r4, #0
_02208EFC:
	add r0, r1, r3
	ldrsh r6, [r0, r4]
	add r2, r2, #1
	add r1, #0x14
	add r6, r6, #2
	strh r6, [r0, r5]
	cmp r2, #3
	blt _02208EFC
	b _02208F2E
_02208F0E:
	bhs _02208F2E
	mov r4, #0xa5
	add r3, r0, #0
	lsl r4, r4, #2
	ldr r1, [sp, #4]
	mov r2, #0
	add r3, #0xa0
	add r5, r4, #0
_02208F1E:
	add r0, r1, r3
	ldrsh r6, [r0, r4]
	add r2, r2, #1
	add r1, #0x14
	add r6, r6, #2
	strh r6, [r0, r5]
	cmp r2, #3
	blt _02208F1E
_02208F2E:
	ldr r0, [sp, #4]
	bl ov96_02208FB8
	add r4, r0, #0
	ldr r1, _02208FB4 ; =0x00000558
	ldr r0, [sp, #4]
	ldrb r1, [r0, r1]
	ldr r0, [sp, #8]
	cmp r0, r1
	blo _02208FAC
	ldr r0, [sp, #0x1c]
	ldr r2, [sp, #0x1c]
	ldr r1, [r0]
	add r0, sp, #0x20
	str r0, [sp]
	add r0, r1, #0
	add r0, #0xb1
	ldrb r0, [r0]
	ldrh r2, [r2, #6]
	add r3, sp, #0x24
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r1, [sp, #0x1c]
	ldrh r1, [r1, #4]
	bl ov96_021EB0A4
	ldr r0, [sp, #0x24]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0x1c]
	ldr r0, [r0]
	str r1, [r0, #0x7c]
	ldr r0, [sp, #0x20]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0x1c]
	ldr r0, [r0]
	add r0, #0x80
	str r1, [r0]
	ldr r1, [sp, #0x1c]
	mov r0, #0
	ldr r1, [r1]
	add r1, #0x84
	str r0, [r1]
	ldr r1, [r4, #8]
	lsl r2, r1, #0xc
	ldr r1, [sp, #0x1c]
	ldr r1, [r1]
	add r1, #0x88
	str r2, [r1]
	ldr r1, [r4, #0xc]
	lsl r2, r1, #0xc
	ldr r1, [sp, #0x1c]
	ldr r1, [r1]
	add r1, #0x8c
	str r2, [r1]
	ldr r1, [sp, #0x1c]
	ldr r1, [r1]
	add r1, #0x90
	str r0, [r1]
	ldr r0, [sp, #0x1c]
	mov r1, #1
	ldr r0, [r0]
	add r0, #0xa5
	strb r1, [r0]
_02208FAC:
	add sp, #0x1c0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02208FB0: .word 0x000001A2
_02208FB4: .word 0x00000558
	thumb_func_end ov96_02208BB8

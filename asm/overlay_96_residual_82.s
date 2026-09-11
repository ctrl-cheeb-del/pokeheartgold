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

	thumb_func_start ov96_02200EF4
ov96_02200EF4: ; 0x02200EF4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r0, _02200F7C ; =0x000003E5
	add r5, r1, #0
	ldrb r1, [r5, r0]
	add r7, r2, #0
	mov r2, #4
	cmp r1, #4
	bne _02200F0A
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02200F0A:
	sub r1, r0, #3
	ldrb r1, [r5, r1]
	add r3, r1, #1
	sub r1, r0, #3
	strb r3, [r5, r1]
	sub r3, r0, #2
	ldrb r1, [r5, r1]
	ldrb r3, [r5, r3]
	cmp r1, r3
	blo _02200F2C
	add r1, r0, #0
	mov r3, #1
	sub r1, #9
	str r3, [r5, r1]
	mov r1, #0
	sub r0, r0, #3
	strb r1, [r5, r0]
_02200F2C:
	mov r1, #0xf7
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	cmp r0, #0
	beq _02200F76
	add r0, r1, #0
	add r0, #8
	add r1, r1, #5
	ldrb r0, [r5, r0]
	ldrb r1, [r5, r1]
	add r4, r0, r1
	cmp r4, r0
	bge _02200F4A
	bl GF_AssertFail
_02200F4A:
	lsl r2, r4, #0x18
	add r0, r6, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	add r3, r7, #0
	bl ov96_02200F84
	lsl r0, r4, #0x18
	lsr r2, r0, #0x18
	ldr r0, _02200F80 ; =0x000003E1
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
	sub r1, r0, #1
	ldrb r3, [r5, r0]
	ldrb r1, [r5, r1]
	cmp r3, r1
	blo _02200F76
	mov r1, #0
	strb r1, [r5, r0]
	sub r0, r0, #5
	str r1, [r5, r0]
_02200F76:
	add r0, r2, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02200F7C: .word 0x000003E5
_02200F80: .word 0x000003E1
	thumb_func_end ov96_02200EF4




	thumb_func_start ov96_02200F84
ov96_02200F84: ; 0x02200F84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0xf8
	str r2, [sp, #0xc]
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	str r1, [sp, #8]
	lsl r0, r0, #4
	str r0, [sp, #0x14]
	ldr r0, [r1, r0]
	str r3, [sp, #0x10]
	add r1, r0, #0
	add r1, #0x9d
	ldrb r1, [r1]
	cmp r1, #0
	bne _02200FC0
	add r1, r0, #0
	add r1, #0x8b
	ldrb r2, [r1]
	mov r1, #0x1c
	mul r1, r2
	add r1, r0, r1
	add r1, #0x30
	ldrb r1, [r1]
	cmp r1, #2
	beq _02200FC0
	add r0, #0xa9
	ldrb r0, [r0]
	cmp r0, #0
	beq _02200FC2
_02200FC0:
	b _02201444
_02200FC2:
	mov r1, #0
	add r0, r1, #0
	add r2, sp, #0x4c
	str r0, [sp, #0x2c]
_02200FCA:
	ldr r0, [sp, #0x2c]
	add r1, r1, #1
	stmia r2!, {r0}
	cmp r1, #4
	blt _02200FCA
	ldr r7, [sp, #8]
	add r6, r0, #0
	add r5, sp, #0x5c
_02200FDA:
	add r3, r7, #0
	add r2, r5, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r4, [r5]
	add r0, sp, #0x44
	str r0, [sp]
	ldr r1, [r4, #0x7c]
	add r0, r4, #0
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	add r2, r4, #0
	add r0, #0x8b
	add r2, #0x80
	ldrb r0, [r0]
	ldr r3, [r2]
	asr r2, r3, #0xb
	lsl r0, r0, #2
	lsr r2, r2, #0x14
	add r2, r3, r2
	ldr r0, [r4, r0]
	asr r2, r2, #0xc
	add r3, sp, #0x48
	bl ov96_021EB0A4
	add r0, sp, #0x3c
	str r0, [sp]
	add r0, r4, #0
	add r0, #0x8b
	ldrb r0, [r0]
	ldr r1, [sp, #0x48]
	ldr r2, [sp, #0x44]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x40
	bl ov96_021EB03C
	ldr r1, [sp, #0x40]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [sp, #0x3c]
	str r0, [r5, #8]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	ldr r1, [sp, #8]
	asr r0, r0, #0xc
	str r0, [r5, #0xc]
	add r4, r1, r6
	sub r0, #0x20
	mov r1, #0x28
	bl _s32_div_f
	mov r1, #0xa6
	lsl r1, r1, #2
	strb r0, [r4, r1]
	add r0, r1, #0
	ldrb r0, [r4, r0]
	cmp r0, #4
	bls _02201066
	bl GF_AssertFail
_02201066:
	add r6, r6, #1
	add r7, #0x10
	add r5, #0x10
	cmp r6, #4
	blt _02200FDA
	ldr r0, [sp, #0x14]
	add r1, sp, #0x5c
	add r0, r1, r0
	ldr r2, [sp, #8]
	str r0, [sp, #0x28]
	mov r4, #0
	add r3, sp, #0x9c
_0220107E:
	add r6, r2, #0
	add r6, #0x40
	ldmia r6!, {r0, r1}
	add r5, r3, #0
	stmia r5!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r5!, {r0, r1}
	ldr r0, [r6]
	add r4, r4, #1
	str r0, [r5]
	add r2, #0x14
	add r3, #0x14
	cmp r4, #0x1e
	blt _0220107E
	ldr r0, [sp, #0x28]
	ldr r1, [r0, #8]
	mov r0, #0x36
	lsl r0, r0, #4
	cmp r1, r0
	blt _022010D6
	mov r5, #0
	add r6, r5, #0
	add r4, sp, #0x5c
	sub r6, #0xa0
_022010AE:
	add r0, r4, #0
	add r0, #8
	add r1, r6, #0
	bl ov96_0220144C
	add r5, r5, #1
	add r4, #0x10
	cmp r5, #4
	blt _022010AE
	mov r5, #0
	add r4, sp, #0x9c
	mov r6, #0x50
_022010C6:
	add r0, r4, #4
	add r1, r6, #0
	bl ov96_0220144C
	add r5, r5, #1
	add r4, #0x14
	cmp r5, #0x1e
	blt _022010C6
_022010D6:
	ldr r4, [sp, #8]
	mov r5, #0
_022010DA:
	ldr r0, _02201308 ; =0x000002AE
	lsr r2, r5, #0x1f
	lsl r1, r5, #0x1e
	strh r5, [r4, r0]
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r1, r2, r1
	mov r0, #0x28
	add r6, r1, #0
	mul r6, r0
	ldr r0, [sp, #0x28]
	ldr r0, [r0, #8]
	add r0, #0x14
	add r1, r0, r6
	mov r0, #0xa7
	lsl r0, r0, #2
	str r1, [r4, r0]
	asr r0, r5, #1
	lsr r0, r0, #0x1e
	add r0, r5, r0
	asr r1, r0, #2
	mov r0, #0x28
	add r7, r1, #0
	mul r7, r0
	add r1, r7, #0
	mov r0, #0x2a
	add r1, #0x34
	lsl r0, r0, #4
	str r1, [r4, r0]
	bl LCRandom
	mov r1, #0x28
	bl _s32_div_f
	ldr r0, [sp, #0x28]
	ldr r0, [r0, #8]
	add r0, r0, r6
	add r1, r0, r1
	mov r0, #0xa9
	lsl r0, r0, #2
	str r1, [r4, r0]
	bl LCRandom
	mov r1, #0x28
	bl _s32_div_f
	add r7, #0x20
	mov r0, #0xaa
	add r1, r7, r1
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r5, r5, #1
	add r4, #0x14
	cmp r5, #0x10
	blt _022010DA
	ldr r2, _0220130C ; =ov96_0221C770
	ldr r3, [sp, #8]
	mov r4, #0
	add r0, r0, #4
_02201152:
	ldr r1, [r2]
	add r4, r4, #1
	strh r1, [r3, r0]
	add r2, r2, #4
	add r3, #0x14
	cmp r4, #0x10
	blt _02201152
	mov r0, #0x20
	str r0, [sp, #0x20]
	ldr r1, [sp, #8]
	ldr r0, [sp, #0xc]
	mov r6, #0
	add r0, r1, r0
	add r4, sp, #0x4c
	str r6, [sp, #0x24]
	str r0, [sp, #0x1c]
_02201172:
	ldr r0, [sp, #0x24]
	mov r1, #0x14
	mul r1, r0
	ldr r0, [sp, #8]
	mov r5, #0
	add r0, r0, r1
	add r7, sp, #0x5c
	str r0, [sp, #0x18]
_02201182:
	ldr r0, [sp, #0xc]
	cmp r5, r0
	beq _0220121A
	ldr r1, [sp, #0x28]
	ldr r0, [r7, #8]
	ldr r2, [r1, #8]
	add r1, r2, #0
	add r1, #0xa0
	cmp r1, r0
	blt _0220121A
	sub r0, r0, r2
	bmi _022011F2
	cmp r0, #0xa0
	bge _022011F2
	ldr r1, [sp, #8]
	add r2, r1, r5
	mov r1, #0xa6
	lsl r1, r1, #2
	ldrb r1, [r2, r1]
	cmp r6, r1
	bne _022011C4
	mov r1, #0xa6
	ldr r2, [sp, #0x1c]
	lsl r1, r1, #2
	ldrb r1, [r2, r1]
	cmp r6, r1
	ldr r1, [r4]
	bne _022011C0
	sub r1, r1, #4
	str r1, [r4]
	b _022011C4
_022011C0:
	sub r1, r1, #2
	str r1, [r4]
_022011C4:
	mov r1, #0x28
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r2, #4
	blo _022011D8
	bl GF_AssertFail
	b _0220121A
_022011D8:
	mov r0, #0x14
	add r1, r2, #0
	mul r1, r0
	ldr r0, [sp, #0x18]
	add r0, r0, r1
	mov r1, #0xab
	lsl r1, r1, #2
	ldrsh r1, [r0, r1]
	sub r2, r1, #3
	mov r1, #0xab
	lsl r1, r1, #2
	strh r2, [r0, r1]
	b _0220121A
_022011F2:
	mov r1, #0x4f
	mvn r1, r1
	cmp r0, r1
	blt _0220121A
	ldr r0, [sp, #8]
	add r1, r0, r5
	mov r0, #0xa6
	lsl r0, r0, #2
	ldrb r0, [r1, r0]
	cmp r6, r0
	bne _0220121A
	mov r0, #0xa6
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #2
	ldrb r0, [r1, r0]
	cmp r6, r0
	bne _0220121A
	ldr r0, [r4]
	add r0, r0, #2
	str r0, [r4]
_0220121A:
	add r5, r5, #1
	add r7, #0x10
	cmp r5, #4
	blt _02201182
	mov r0, #0
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x20]
	add r2, sp, #0x9c
	add r0, #0x28
	mov ip, r0
	ldr r0, [sp, #0x28]
	add r3, sp, #0x4c
	ldr r5, [r0, #8]
_02201234:
	ldr r0, [r2]
	cmp r0, #0
	beq _02201280
	add r0, r5, #0
	ldr r1, [r2, #4]
	add r0, #0xa0
	cmp r0, r1
	blt _02201272
	sub r0, r1, r5
	cmp r0, #0
	ble _02201272
	cmp r0, #0xa0
	bgt _02201272
	ldr r7, [r2, #8]
	ldr r0, [r2, #0x10]
	add r1, r7, r0
	ldr r0, [sp, #0x20]
	cmp r0, r1
	bge _02201272
	mov r0, ip
	cmp r7, r0
	bge _02201272
	ldr r0, [r2, #0xc]
	cmp r0, #3
	ldr r0, [r3]
	bne _0220126E
	sub r0, r0, #1
	str r0, [r3]
	b _02201272
_0220126E:
	sub r0, r0, #6
	str r0, [r3]
_02201272:
	ldr r0, [sp, #0x30]
	add r2, #0x14
	add r0, r0, #1
	add r3, r3, #4
	str r0, [sp, #0x30]
	cmp r0, #0x1e
	blt _02201234
_02201280:
	ldr r0, [sp, #0x24]
	add r6, r6, #1
	add r0, r0, #4
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x20]
	add r4, r4, #4
	add r0, #0x28
	str r0, [sp, #0x20]
	cmp r6, #4
	bge _02201296
	b _02201172
_02201296:
	mov r5, #0xab
	lsl r5, r5, #2
	ldr r3, [sp, #8]
	mov r4, #0
	add r1, sp, #0x4c
	add r0, r5, #0
_022012A2:
	asr r6, r4, #1
	lsr r6, r6, #0x1e
	add r6, r4, r6
	asr r6, r6, #2
	lsl r6, r6, #2
	ldrsh r2, [r3, r5]
	ldr r6, [r1, r6]
	add r4, r4, #1
	add r2, r2, r6
	strh r2, [r3, r0]
	add r3, #0x14
	cmp r4, #0x10
	blt _022012A2
	ldr r1, _02201310 ; =0x00000A8C
	ldr r0, [sp, #0x10]
	cmp r0, r1
	bge _022012F0
	mov r2, #0
	mov r3, #0xab
	add r1, r2, #0
	mov r7, #0x14
	lsl r3, r3, #2
	mov r4, #0x28
	mov r5, #0x3c
_022012D2:
	add r6, r1, #0
	ldr r0, [sp, #8]
	mul r6, r7
	add r0, r0, r6
	add r0, r0, r3
	ldrsh r6, [r0, r4]
	add r2, r2, #1
	add r1, r1, #4
	add r6, r6, #3
	strh r6, [r0, #0x28]
	ldrsh r6, [r0, r5]
	add r6, r6, #3
	strh r6, [r0, #0x3c]
	cmp r2, #4
	blt _022012D2
_022012F0:
	ldr r0, [sp, #0x28]
	ldr r2, [r0]
	add r0, r2, #0
	add r0, #0x8b
	ldrb r1, [r0]
	mov r0, #0x1c
	mul r0, r1
	add r0, r2, r0
	ldr r0, [r0, #0x24]
	ldr r1, _02201314 ; =0x41A00000
	b _02201318
	nop
_02201308: .word 0x000002AE
_0220130C: .word ov96_0221C770
_02201310: .word 0x00000A8C
_02201314: .word 0x41A00000
_02201318:
	bl _fleq
	bhi _02201350
	mov r2, #0
	mov r3, #0xab
	add r1, r2, #0
	mov r7, #0x14
	lsl r3, r3, #2
	mov r4, #0x28
	mov r5, #0x3c
_0220132C:
	add r6, r1, #0
	ldr r0, [sp, #8]
	mul r6, r7
	add r0, r0, r6
	add r0, r0, r3
	ldrsh r6, [r0, r4]
	add r2, r2, #1
	add r1, r1, #4
	sub r6, r6, #2
	strh r6, [r0, #0x28]
	ldrsh r6, [r0, r5]
	sub r6, r6, #2
	strh r6, [r0, #0x3c]
	cmp r2, #4
	blt _0220132C
	ldr r0, [sp, #0x2c]
	add r0, #8
	str r0, [sp, #0x2c]
_02201350:
	ldr r0, [sp, #0x28]
	mov r1, #3
	ldr r4, [r0]
	add r0, r4, #0
	add r0, #0x8b
	ldrb r0, [r0]
	add r0, r0, #1
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x1c
	mul r0, r1
	add r0, r4, r0
	add r0, #0x30
	ldrb r0, [r0]
	cmp r0, #1
	bne _0220137A
	ldr r0, [sp, #0x2c]
	sub r0, r0, #5
	str r0, [sp, #0x2c]
_0220137A:
	ldr r0, [sp, #8]
	bl ov96_0220146C
	add r4, r0, #0
	mov r0, #0x10
	ldrsh r1, [r4, r0]
	ldr r0, [sp, #0x2c]
	cmp r1, r0
	blt _0220140C
	mov r1, #0xf9
	ldr r0, [sp, #8]
	lsl r1, r1, #2
	ldrb r1, [r0, r1]
	ldr r0, [sp, #0xc]
	cmp r0, r1
	blo _02201444
	ldr r0, [sp, #0x28]
	ldr r2, [sp, #0x28]
	ldr r1, [r0]
	add r0, sp, #0x34
	str r0, [sp]
	add r0, r1, #0
	add r0, #0x8b
	ldrb r0, [r0]
	ldr r2, [r2, #0xc]
	add r3, sp, #0x38
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r1, [sp, #0x28]
	ldr r1, [r1, #8]
	bl ov96_021EB0A4
	ldr r0, [sp, #0x38]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0x28]
	ldr r0, [r0]
	add r0, #0xb0
	str r1, [r0]
	ldr r0, [sp, #0x34]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0x28]
	ldr r0, [r0]
	add r0, #0xb4
	str r1, [r0]
	ldr r1, [sp, #0x28]
	mov r0, #0
	ldr r1, [r1]
	add r1, #0xb8
	str r0, [r1]
	ldr r1, [r4, #8]
	lsl r2, r1, #0xc
	ldr r1, [sp, #0x28]
	ldr r1, [r1]
	add r1, #0xbc
	str r2, [r1]
	ldr r1, [r4, #0xc]
	lsl r2, r1, #0xc
	ldr r1, [sp, #0x28]
	ldr r1, [r1]
	add r1, #0xc0
	str r2, [r1]
	ldr r1, [sp, #0x28]
	ldr r1, [r1]
	add r1, #0xc4
	str r0, [r1]
	ldr r0, [sp, #0x28]
	add sp, #0x1fc
	ldr r0, [r0]
	mov r1, #1
	add r0, #0xaa
	strb r1, [r0]
	add sp, #0xf8
	pop {r4, r5, r6, r7, pc}
_0220140C:
	mov r1, #0xf9
	ldr r0, [sp, #8]
	lsl r1, r1, #2
	ldrb r1, [r0, r1]
	ldr r0, [sp, #0xc]
	cmp r0, r1
	blo _02201444
	ldr r0, [sp, #0x28]
	mov r1, #1
	ldr r0, [r0]
	mov r3, #7
	add r0, #0x9d
	strb r1, [r0]
	ldr r0, [sp, #0x28]
	ldr r0, [r0]
	add r0, #0x9e
	strb r1, [r0]
	ldr r0, [sp, #0x28]
	ldr r2, [r0]
	ldr r0, [sp, #4]
	str r1, [sp]
	add r1, r2, #0
	add r1, #0xd0
	add r2, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r2]
	bl ov96_021E8228
_02201444:
	add sp, #0x1fc
	add sp, #0xf8
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02200F84




	thumb_func_start ov96_0220144C
ov96_0220144C: ; 0x0220144C
	ldr r2, [r0]
	add r2, r2, r1
	mov r1, #1
	lsl r1, r1, #0xa
	str r2, [r0]
	cmp r2, r1
	blt _02201460
	sub r1, r2, r1
	str r1, [r0]
	bx lr
_02201460:
	cmp r2, #0
	bge _02201468
	add r1, r2, r1
	str r1, [r0]
_02201468:
	bx lr
	.balign 4, 0
	thumb_func_end ov96_0220144C




	thumb_func_start ov96_0220146C
ov96_0220146C: ; 0x0220146C
	push {r4, lr}
	sub sp, #0x80
	mov r1, #0xa7
	lsl r1, r1, #2
	add r0, r0, r1
	mov r2, #0
	add r1, sp, #0
_0220147A:
	add r2, r2, #1
	stmia r1!, {r0}
	add r0, #0x14
	cmp r2, #0x10
	blt _0220147A
	add r0, sp, #0
	add r1, sp, #0x40
	bl ov96_022014A4
	add r4, r0, #0
	bl LCRandom
	add r1, r4, #0
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x16
	add r0, sp, #0x40
	ldr r0, [r0, r1]
	add sp, #0x80
	pop {r4, pc}
	thumb_func_end ov96_0220146C




	thumb_func_start ov96_022014A4
ov96_022014A4: ; 0x022014A4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xd0
	mov ip, r0
	add r0, sp, #0x10
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #0xc]
	ldr r0, [sp]
	add r7, r1, #0
_022014BA:
	add r2, r0, #1
	mov r1, #0xc
	mul r1, r2
	add r2, sp, #4
	lsl r4, r0, #2
	mov r3, ip
	ldr r3, [r3, r4]
	add r2, r2, r1
	str r3, [r2, #8]
	mov r3, #0
	str r3, [r2, #4]
	add r4, r3, #0
	add r3, sp, #4
	str r4, [r3, r1]
	add r1, r4, #0
	cmp r0, #0
	bls _02201506
	ldr r5, [r2, #8]
	mov r4, #0x10
	ldrsh r4, [r5, r4]
	mov r6, #0x10
_022014E4:
	ldr r3, [r3, #4]
	ldr r5, [r3, #8]
	ldrsh r5, [r5, r6]
	cmp r5, r4
	bge _022014FC
	ldr r4, [r3]
	str r2, [r4, #4]
	ldr r4, [r3]
	str r4, [r2]
	str r3, [r2, #4]
	str r2, [r3]
	b _02201506
_022014FC:
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, r0
	blo _022014E4
_02201506:
	cmp r1, r0
	bne _0220150E
	str r2, [r3, #4]
	str r3, [r2]
_0220150E:
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #0x10
	blo _022014BA
	ldr r0, [sp, #8]
	mov r3, #0
	ldr r1, [r0, #8]
	mov r0, #0x10
	ldrsh r2, [r1, r0]
	add r1, sp, #4
_02201524:
	ldr r1, [r1, #4]
	lsl r5, r3, #2
	ldr r4, [r1, #8]
	str r4, [r7, r5]
	ldr r4, [r7, r5]
	ldrsh r4, [r4, r0]
	cmp r2, r4
	bne _0220153E
	ldr r4, [sp]
	add r4, r4, #1
	lsl r4, r4, #0x18
	lsr r4, r4, #0x18
	str r4, [sp]
_0220153E:
	add r3, r3, #1
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	cmp r3, #0x10
	blo _02201524
	ldr r0, [sp]
	cmp r0, #0
	bne _02201552
	bl GF_AssertFail
_02201552:
	ldr r0, [sp]
	add sp, #0xd0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_022014A4




	thumb_func_start ov96_02201558
ov96_02201558: ; 0x02201558
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	add r6, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r7, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetField1ED
	cmp r0, #5
	bls _02201570
	b _02201AFE
_02201570:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0220157C: ; jump table
	.short _02201588 - _0220157C - 2 ; case 0
	.short _0220166C - _0220157C - 2 ; case 1
	.short _022016A2 - _0220157C - 2 ; case 2
	.short _0220175C - _0220157C - 2 ; case 3
	.short _02201874 - _0220157C - 2 ; case 4
	.short _02201AE2 - _0220157C - 2 ; case 5
_02201588:
	mov r2, #1
	mov r0, #0x5c
	mov r1, #0x92
	lsl r2, r2, #0x12
	bl Heap_Create
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _022018CC ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _022018D0 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	bl ov96_02201C90
	ldr r1, _022018D4 ; =0x000005F4
	add r0, r6, #0
	bl PokeathlonCourse_AllocPtr4FromHeap
	ldr r2, _022018D4 ; =0x000005F4
	mov r1, #0
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x92
	mov r1, #0x28
	bl Heap_Alloc
	ldr r1, _022018D8 ; =0x00000598
	mov r2, #0x28
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0
	bl MI_CpuFill8
	mov r0, #0x92
	bl BgConfig_Alloc
	str r0, [r4]
	add r0, r6, #0
	mov r1, #8
	bl ov96_021E6670
	mov r0, #0x73
	str r0, [sp, #0x98]
	mov r0, #1
	lsl r0, r0, #0x12
	str r0, [sp, #0x9c]
	lsr r0, r0, #4
	str r0, [sp, #0xa0]
	add r0, r6, #0
	bl PokeathlonCourse_GetHeapID
	str r0, [sp, #0xa4]
	ldr r3, _022018DC ; =0x00300010
	add r0, sp, #0x98
	mov r1, #0x16
	mov r2, #0x92
	str r3, [sp]
	bl ov96_021E92B0
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x7e
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x92
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	mov r1, #0x92
	str r1, [r4, #0x44]
	mov r0, #4
	bl FontID_Alloc
	ldr r0, [r4]
	bl ov96_02201CB0
	add r0, r4, #0
	bl ov96_02203310
	add r0, r4, #0
	add r1, r6, #0
	bl ov96_0220382C
	ldr r0, _022018E0 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _02201AFE
_0220166C:
	ldr r0, [r7, #0x44]
	ldr r1, [r7]
	add r2, r6, #0
	bl ov96_02203A00
	mov r1, #0x5e
	lsl r1, r1, #4
	str r0, [r7, r1]
	add r0, r6, #0
	bl PokeathlonCourse_GetParticipantCount
	add r4, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetMode
	add r2, r0, #0
	mov r1, #4
	ldr r0, [r7, #0x44]
	sub r1, r1, r4
	bl ov96_02204364
	ldr r1, _022018E4 ; =0x000005DC
	str r0, [r7, r1]
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _02201AFE
_022016A2:
	ldr r4, _022018E8 ; =ov96_0221C7B8
	add r3, sp, #0x8c
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r7, #0x44]
	bl ov96_021EB180
	mov r1, #0
	str r0, [r7, #0x48]
	mov r0, #0x12
	lsl r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r7, #0x48]
	add r2, r1, #0
	add r3, r1, #0
	bl ov96_021EB5C8
	ldr r0, [r7, #0x48]
	mov r1, #0
	mov r2, #0x6a
	bl ov96_021EB29C
	ldr r0, [r7, #0x48]
	mov r1, #1
	mov r2, #0x65
	bl ov96_021EB29C
	ldr r0, [r7, #0x48]
	mov r1, #2
	mov r2, #0x69
	bl ov96_021EB29C
	ldr r0, [r7, #0x48]
	bl ov96_02201E70
	mov r0, #0x5e
	lsl r0, r0, #4
	ldr r0, [r7, r0]
	ldr r1, [r7, #0x48]
	bl ov96_02203B44
	ldr r0, [r7, #0x48]
	bl ov96_021EB3A4
	ldr r0, [r7, #0x44]
	ldr r1, _022018EC ; =0x000004E7
	mov r2, #1
	bl ov96_021E9A78
	ldr r1, _022018F0 ; =0x000005D4
	str r0, [r7, r1]
	ldr r0, [r7, #0x48]
	bl ov96_021EB5E8
	str r0, [sp]
	ldr r3, _022018F0 ; =0x000005D4
	ldr r0, [r7, #0x44]
	ldr r3, [r7, r3]
	mov r1, #9
	mov r2, #0x20
	bl ov96_021EA854
	ldr r2, _022018F4 ; =0x000005D8
	mov r1, #0
	str r0, [r7, r2]
	sub r2, r2, #4
	ldr r2, [r7, r2]
	ldr r3, [r7, #0x48]
	add r0, r6, #0
	bl ov96_021E6290
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_SetDrawPriority
	add r0, r6, #0
	bl ov96_021E5F24
	add r2, r0, #0
	lsl r2, r2, #0x18
	ldr r1, [r7, #0x48]
	add r0, r7, #0
	lsr r2, r2, #0x18
	bl ov96_02201EF0
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _02201AFE
_0220175C:
	add r0, r6, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x1c]
	mov r0, #0
	str r0, [sp, #0x54]
	ldr r0, [sp, #0x1c]
	add r1, r0, #1
	lsl r0, r1, #1
	add r0, r1, r0
	mov r1, #0xc
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x24]
	add r5, sp, #0x13c
	add r4, sp, #0xf8
_02201784:
	ldr r0, [sp, #0x24]
	mov r1, #0xc
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x20]
	mov r1, #3
	bl _s32_div_f
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x20]
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x58]
	ldr r1, [sp, #0x58]
	ldr r2, [sp, #0x14]
	add r0, r6, #0
	add r3, r5, #0
	bl ov96_021E6168
	ldr r1, [sp, #0x58]
	ldr r2, [sp, #0x14]
	add r0, r6, #0
	bl ov96_021E60C0
	bl ov96_021E6108
	str r0, [r4, #0x14]
	ldr r0, [sp, #0x24]
	add r5, #0x10
	add r0, r0, #1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x54]
	add r4, r4, #4
	add r0, r0, #1
	str r0, [sp, #0x54]
	cmp r0, #0xc
	blt _02201784
	mov r0, #0x5e
	lsl r0, r0, #4
	ldr r0, [r7, r0]
	ldr r1, [r7, #0x48]
	add r2, sp, #0x1cc
	bl ov96_02203B8C
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	mov r5, #0x10
	lsl r1, r0, #1
	add r0, r0, r1
	lsl r0, r0, #5
	add r4, r7, r0
_022017F2:
	mov r1, #0
	add r0, sp, #0x80
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [sp, #0x18]
	add r1, sp, #0x13c
	add r0, #9
	lsl r0, r0, #4
	add r3, r1, r0
	ldr r1, [r3, #0xc]
	mov r2, #0
	str r1, [sp]
	add r1, sp, #0x13c
	ldrh r0, [r1, r0]
	ldrb r1, [r3, #7]
	ldrh r3, [r3, #2]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl GetMonPicHeightBySpeciesGenderForm
	lsl r1, r5, #0xc
	str r1, [sp, #0x80]
	mov r1, #0x5e
	lsl r1, r1, #2
	add r0, r0, r1
	lsl r1, r0, #0xc
	mov r0, #1
	lsl r0, r0, #0x10
	str r1, [sp, #0x84]
	sub r0, r1, r0
	str r0, [sp, #0x84]
	ldr r0, _022018F8 ; =0x00000418
	add r1, sp, #0x80
	ldr r0, [r4, r0]
	bl ov96_021EB588
	ldr r0, [sp, #0x18]
	add r5, #0x32
	add r0, r0, #1
	add r4, #0x20
	str r0, [sp, #0x18]
	cmp r0, #3
	blt _022017F2
	mov r0, #3
	mov r1, #0
	str r0, [sp, #0xfc]
	mov r0, #1
	str r1, [sp, #0xf8]
	str r1, [sp, #0x100]
	str r0, [sp, #0x104]
	str r0, [sp, #0x108]
	str r1, [sp]
	str r1, [sp, #4]
	ldr r0, _022018F4 ; =0x000005D8
	mov r1, #9
	ldr r0, [r7, r0]
	add r2, sp, #0x13c
	add r3, sp, #0xf8
	bl ov96_021EA8A8
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _02201AFE
_02201874:
	ldr r0, _022018F4 ; =0x000005D8
	ldr r0, [r7, r0]
	bl ov96_021EAA00
	cmp r0, #0
	bne _02201882
	b _02201AFE
_02201882:
	ldr r3, _022018FC ; =ov96_0221C7D0
	add r2, sp, #0x74
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r7]
	bl PokeathlonCourse_SetVBlankIntrCB
	add r0, r6, #0
	mov r1, #1
	bl PokeathlonCourse_SetField1F4
	add r0, r6, #0
	bl ov96_021E5F24
	mov r1, #0
	str r1, [sp, #0x50]
	add r1, r0, #1
	lsl r0, r1, #1
	add r0, r1, r0
	mov r1, #0xc
	add r5, r7, #0
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x34]
	ldr r0, _02201900 ; =ov96_0221C8C8
	str r0, [sp, #0x30]
	ldr r0, _02201904 ; =ov96_0221C8EC
	str r0, [sp, #0x2c]
	ldr r0, _02201908 ; =ov96_0221CA1C
	str r0, [sp, #0x28]
_022018C6:
	ldr r0, _022018F4 ; =0x000005D8
	b _0220190C
	nop
_022018CC: .word 0xFFFFE0FF
_022018D0: .word 0x04001000
_022018D4: .word 0x000005F4
_022018D8: .word 0x00000598
_022018DC: .word 0x00300010
_022018E0: .word gSystem + 0x60
_022018E4: .word 0x000005DC
_022018E8: .word ov96_0221C7B8
_022018EC: .word 0x000004E7
_022018F0: .word 0x000005D4
_022018F4: .word 0x000005D8
_022018F8: .word 0x00000418
_022018FC: .word ov96_0221C7D0
_02201900: .word ov96_0221C8C8
_02201904: .word ov96_0221C8EC
_02201908: .word ov96_0221CA1C
_0220190C:
	ldr r1, [sp, #0x50]
	ldr r0, [r7, r0]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r1, r5, #0
	add r1, #0x94
	str r0, [r1]
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #1
	str r0, [sp, #0x4c]
	bl ov96_021EAB38
	ldr r0, [sp, #0x34]
	mov r1, #0xc
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x30]
	mov r1, #3
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x2c]
	ldr r4, [r0]
	ldr r0, [sp, #0x50]
	bl _s32_div_f
	add r1, r0, #0
	lsl r2, r1, #2
	add r1, sp, #0x74
	ldr r0, [sp, #0x4c]
	ldr r1, [r1, r2]
	bl ov96_021EAC0C
	ldr r0, [sp, #0x4c]
	ldr r1, [sp, #0x44]
	add r2, r4, #0
	bl ov96_021EAF94
	mov r1, #0
	add r0, sp, #0x68
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [sp, #0x4c]
	bl ov96_021EAA20
	bl ov96_021E8BB0
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _0220198C
	ldr r0, [sp, #0x44]
	sub r4, #0x28
	lsl r0, r0, #0xc
	str r0, [sp, #0x68]
	lsl r0, r4, #0xc
	str r0, [sp, #0x6c]
	b _02201998
_0220198C:
	ldr r0, [sp, #0x44]
	sub r4, #0x19
	lsl r0, r0, #0xc
	str r0, [sp, #0x68]
	lsl r0, r4, #0xc
	str r0, [sp, #0x6c]
_02201998:
	ldr r0, [sp, #0x48]
	lsl r0, r0, #5
	add r1, r7, r0
	ldr r0, _02201B04 ; =0x00000418
	ldr r0, [r1, r0]
	add r1, sp, #0x68
	bl ov96_021EB588
	ldr r0, [r5, #0x70]
	add r1, sp, #0x68
	bl ov96_021EB588
	ldr r1, [sp, #0x28]
	ldr r0, [sp, #0x4c]
	ldrb r1, [r1]
	add r1, #0x20
	bl ov96_021EABA8
	ldr r0, [sp, #0x34]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x30]
	add r0, r0, #4
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x2c]
	add r0, r0, #4
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x50]
	add r0, r0, #1
	str r0, [sp, #0x50]
	cmp r0, #9
	bge _022019E2
	b _022018C6
_022019E2:
	add r0, sp, #0xa8
	mov r1, #0xaa
	mov r2, #3
	bl ReadWholeNarcMemberByIdPair
	ldr r1, _02201B08 ; =0x00000708
	ldr r0, _02201B0C ; =0x000005E8
	strh r1, [r7, r0]
	mov r0, #0
	str r0, [sp, #0x40]
	str r0, [sp, #0x38]
	add r0, r7, #0
	str r0, [sp, #0x64]
	add r0, #0xb8
	str r0, [sp, #0x64]
	ldr r0, _02201B04 ; =0x00000418
	add r0, r7, r0
	str r0, [sp, #0x5c]
_02201A06:
	ldr r0, [sp, #0x40]
	mov r1, #0xc
	add r2, r7, r0
	ldr r0, _02201B10 ; =0x000005CC
	mov r4, #0
	strb r1, [r2, r0]
	ldr r0, [sp, #0x40]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x60]
_02201A1A:
	ldr r0, [sp, #0x38]
	lsl r3, r4, #0x18
	add r5, r4, r0
	ldr r0, [sp, #0x5c]
	lsl r1, r5, #5
	add r0, r0, r1
	ldr r2, [sp, #0x60]
	str r0, [sp, #0x3c]
	str r0, [sp]
	add r0, r6, #0
	add r1, sp, #0xa8
	lsr r3, r3, #0x18
	bl ov96_0220329C
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _02201A56
	ldr r0, _02201B14 ; =0x000005DC
	mov r3, #0x48
	lsl r1, r5, #0x18
	mul r3, r5
	ldr r5, [sp, #0x64]
	ldr r0, [r7, r0]
	ldr r2, [sp, #0x3c]
	lsr r1, r1, #0x18
	add r3, r5, r3
	bl ov96_022043AC
_02201A56:
	add r4, r4, #1
	cmp r4, #3
	blt _02201A1A
	ldr r0, [sp, #0x38]
	add r0, r0, #3
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x40]
	add r0, r0, #1
	str r0, [sp, #0x40]
	cmp r0, #4
	blt _02201A06
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _02201A8A
	add r0, r6, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0x28
	bl ov96_021E8A20
	add r1, r0, #0
	add r0, r7, #0
	bl ov96_02202738
_02201A8A:
	mov r2, #0x5e
	lsl r2, r2, #4
	ldr r0, [r7, r2]
	sub r2, #0xc
	ldr r1, [r7, #0x48]
	ldr r2, [r7, r2]
	bl ov96_02203D74
	add r0, r6, #0
	bl ov96_021E5F24
	add r1, r0, #0
	lsl r1, r1, #0x18
	add r0, r7, #0
	lsr r1, r1, #0x18
	bl ov96_02201E10
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #1
	bl sub_0203A994
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r7, #0x44]
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _02201AFE
_02201AE2:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02201AFE
	mov r0, #0x5c
	bl GF_heap_c_dummy_return_true
	cmp r0, #0
	bne _02201AF8
	bl GF_AssertFail
_02201AF8:
	add sp, #0x1fc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02201AFE:
	mov r0, #0
	add sp, #0x1fc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02201B04: .word 0x00000418
_02201B08: .word 0x00000708
_02201B0C: .word 0x000005E8
_02201B10: .word 0x000005CC
_02201B14: .word 0x000005DC
	thumb_func_end ov96_02201558




	thumb_func_start ov96_02201B18
ov96_02201B18: ; 0x02201B18
	push {r4, lr}
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	mov r0, #0x5e
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_02203CE4
	ldr r0, [r4, #0x48]
	bl ov96_021EB5BC
	mov r0, #1
	pop {r4, pc}
	thumb_func_end ov96_02201B18




	thumb_func_start ov96_02201B34
ov96_02201B34: ; 0x02201B34
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	bl PokeathlonCourse_GetGraphicsSystem
	add r6, r0, #0
	bl ov96_021E9510
	mov r4, #0
	add r7, r4, #0
_02201B48:
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl PokeathlonCourse_GetField5F0_AtIndex
	add r3, r0, #0
	str r7, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, _02201B94 ; =0x0000012B
	add r1, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r2, r4, #0
	bl ov96_021E95F8
	add r4, r4, #1
	cmp r4, #4
	blt _02201B48
	add r0, r6, #0
	mov r1, #1
	bl ov96_021E93B4
	add r0, r6, #0
	mov r1, #8
	bl ov96_0221A56C
	add r0, r6, #0
	bl ov96_021E952C
	add r0, r6, #0
	mov r1, #8
	bl ov96_021E9570
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_02201B94: .word 0x0000012B
	thumb_func_end ov96_02201B34




	thumb_func_start ov96_02201B98
ov96_02201B98: ; 0x02201B98
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	bl sub_0203A914
	add r0, r7, #0
	bl PokeathlonCourse_ResetField3A4
	ldr r0, [r4]
	mov r1, #0
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #3
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #4
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #6
	bl FreeBgTilemapBuffer
	ldr r0, [r4]
	mov r1, #7
	bl FreeBgTilemapBuffer
	add r0, r4, #4
	bl RemoveWindow
	add r5, r4, #0
	mov r6, #0
	add r5, #0x14
_02201BF0:
	add r0, r5, #0
	bl RemoveWindow
	add r6, r6, #1
	add r5, #0x10
	cmp r6, #3
	blt _02201BF0
	ldr r0, [r4]
	bl Heap_Free
	ldr r0, [r4, #0x48]
	bl ov96_021EB21C
	ldr r0, _02201C78 ; =0x000005D8
	ldr r0, [r4, r0]
	bl ov96_021EA894
	ldr r0, _02201C7C ; =0x000005D4
	ldr r0, [r4, r0]
	bl ov96_021E9C0C
	bl OamManager_Free
	bl ObjCharTransfer_Destroy
	bl ObjPlttTransfer_Destroy
	ldr r0, _02201C80 ; =0x000005DC
	ldr r0, [r4, r0]
	bl ov96_022043B8
	mov r0, #0x5e
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_02203A30
	mov r0, #4
	bl FontID_Release
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	ldr r0, _02201C84 ; =0x00000598
	ldr r0, [r4, r0]
	bl Heap_Free
	add r0, r7, #0
	bl PokeathlonCourse_FreePtr4HeapAlloc
	ldr r0, _02201C88 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	ldr r0, _02201C8C ; =0x04000050
	mov r1, #0
	strh r1, [r0]
	mov r0, #0x92
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02201C78: .word 0x000005D8
_02201C7C: .word 0x000005D4
_02201C80: .word 0x000005DC
_02201C84: .word 0x00000598
_02201C88: .word gSystem + 0x60
_02201C8C: .word 0x04000050
	thumb_func_end ov96_02201B98




	thumb_func_start ov96_02201C90
ov96_02201C90: ; 0x02201C90
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _02201CAC ; =ov96_0221C934
	add r3, sp, #0
	mov r2, #5
_02201C9A:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02201C9A
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_02201CAC: .word ov96_0221C934
	thumb_func_end ov96_02201C90




	thumb_func_start ov96_02201CB0
ov96_02201CB0: ; 0x02201CB0
	push {r4, r5, lr}
	sub sp, #0xd4
	ldr r5, _02201DF0 ; =ov96_0221C7DC
	add r3, sp, #0xc4
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _02201DF4 ; =ov96_0221C83C
	add r3, sp, #0xa8
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0
	str r0, [r3]
	add r0, r4, #0
	add r3, r1, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02201DF8 ; =ov96_0221C858
	add r3, sp, #0x8c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #1
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02201DFC ; =ov96_0221C890
	add r3, sp, #0x70
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #3
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02201E00 ; =ov96_0221C8AC
	add r3, sp, #0x54
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #4
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02201E04 ; =ov96_0221C804
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #5
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02201E08 ; =ov96_0221C820
	add r3, sp, #0x1c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #6
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02201E0C ; =ov96_0221C874
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #7
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add sp, #0xd4
	pop {r4, r5, pc}
	nop
_02201DF0: .word ov96_0221C7DC
_02201DF4: .word ov96_0221C83C
_02201DF8: .word ov96_0221C858
_02201DFC: .word ov96_0221C890
_02201E00: .word ov96_0221C8AC
_02201E04: .word ov96_0221C804
_02201E08: .word ov96_0221C820
_02201E0C: .word ov96_0221C874
	thumb_func_end ov96_02201CB0




	thumb_func_start ov96_02201E10
ov96_02201E10: ; 0x02201E10
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r4, r1, #0
	mov r1, #0
	mov r0, #1
	str r1, [sp]
	lsl r0, r0, #0xe
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r5, #0x44]
	mov r1, #1
	str r0, [sp, #0xc]
	ldr r2, [r5]
	mov r0, #0xdb
	add r3, r1, #0
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5, #0x44]
	mov r1, #2
	str r0, [sp, #0xc]
	ldr r2, [r5]
	mov r0, #0xdb
	mov r3, #1
	bl GfGfxLoader_LoadScrnData
	mov r1, #0
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r5, #0x44]
	add r2, r1, #0
	str r0, [sp, #4]
	mov r0, #0xdb
	add r3, r1, #0
	bl GfGfxLoader_GXLoadPal
	mov r0, #0x5e
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ov96_02203A64
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02201E10




	thumb_func_start ov96_02201E70
ov96_02201E70: ; 0x02201E70
	push {r4, lr}
	sub sp, #8
	mov r1, #3
	str r1, [sp]
	mov r1, #0xdb
	mov r2, #0x15
	mov r3, #0x6a
	add r4, r0, #0
	bl ov96_021EB2BC
	mov r0, #3
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xdb
	mov r2, #0x12
	mov r3, #0x6a
	bl ov96_021EB2F4
	add r0, r4, #0
	mov r1, #0xdb
	mov r2, #0x14
	mov r3, #0x6a
	bl ov96_021EB334
	add r0, r4, #0
	mov r1, #0xdb
	mov r2, #0x13
	mov r3, #0x6a
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0xdb
	mov r2, #0x11
	mov r3, #0x69
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xdb
	mov r2, #0xe
	mov r3, #0x69
	bl ov96_021EB2F4
	add r0, r4, #0
	mov r1, #0xdb
	mov r2, #0x10
	mov r3, #0x69
	bl ov96_021EB334
	add r0, r4, #0
	mov r1, #0xdb
	mov r2, #0xf
	mov r3, #0x69
	bl ov96_021EB36C
	add sp, #8
	pop {r4, pc}
	thumb_func_end ov96_02201E70




	thumb_func_start ov96_02201EF0
ov96_02201EF0: ; 0x02201EF0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x5c
	add r6, r0, #0
	mov r0, #0
	add r4, r1, #0
	str r2, [sp, #4]
	str r0, [sp, #0x10]
	add r5, r6, #0
	add r7, r0, #0
_02201F02:
	add r0, r4, #0
	bl ov96_021EB5E8
	add r1, r0, #0
	ldr r0, _02202148 ; =0x000005D4
	ldr r3, [r6, #0x44]
	ldr r0, [r6, r0]
	mov r2, #3
	bl ov96_021EA374
	mov r1, #1
	str r0, [r5, #0x50]
	bl Sprite_SetDrawFlag
	mov r0, #6
	lsl r1, r7, #0xc
	lsl r0, r0, #0xe
	add r0, r1, r0
	str r0, [sp, #0x50]
	mov r0, #2
	lsl r0, r0, #0xe
	str r0, [sp, #0x54]
	mov r0, #0
	str r0, [sp, #0x58]
	ldr r0, [r5, #0x50]
	add r1, sp, #0x50
	bl Sprite_SetMatrix
	ldr r0, [r5, #0x50]
	mov r1, #2
	bl Sprite_SetDrawPriority
	ldr r0, [sp, #0x10]
	add r5, r5, #4
	add r0, r0, #1
	add r7, #0x10
	str r0, [sp, #0x10]
	cmp r0, #2
	blt _02201F02
	add r0, r6, #0
	mov r1, #0x3c
	bl ov96_022038A0
	mov r7, #0
	add r5, r6, #0
_02201F5C:
	add r0, r5, #0
	add r0, #0xf9
	strb r7, [r0]
	mov r0, #3
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	add r1, r5, #0
	add r1, #0xb8
	str r0, [r1]
	mov r0, #4
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	add r1, r5, #0
	add r1, #0xbc
	str r0, [r1]
	mov r0, #6
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	add r1, r5, #0
	add r1, #0xc0
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	mov r1, #1
	bl ov96_021EB564
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	mov r1, #0x14
	bl ov96_021EB630
	add r0, r5, #0
	add r0, #0xbc
	mov r1, #0xfa
	ldr r0, [r0]
	lsl r1, r1, #2
	bl ov96_021EB630
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #5
	bl ov96_021EB630
	add r7, r7, #1
	add r5, #0x48
	cmp r7, #0xc
	blt _02201F5C
	mov r7, #0
	add r5, r6, #0
_02201FE2:
	mov r0, #9
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	ldr r1, _0220214C ; =0x00000418
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #2
	bl ov96_021EB564
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #0x44]
	str r0, [sp, #0x48]
	mov r0, #0
	str r0, [sp, #0x4c]
	ldr r0, _0220214C ; =0x00000418
	add r1, sp, #0x44
	ldr r0, [r5, r0]
	bl ov96_021EB588
	ldr r0, _0220214C ; =0x00000418
	mov r1, #4
	ldr r0, [r5, r0]
	bl ov96_021EB630
	add r7, r7, #1
	add r5, #0x20
	cmp r7, #0xc
	blt _02201FE2
	mov r7, #0
	add r5, r6, #0
_0220202C:
	mov r0, #0xb
	str r0, [sp]
	add r0, r4, #0
	mov r1, #2
	mov r2, #1
	mov r3, #0x69
	bl ov96_021EB3E4
	str r0, [r5, #0x64]
	mov r1, #6
	bl ov96_021EB564
	ldr r0, [r5, #0x64]
	mov r1, #2
	bl ov96_021EB630
	add r7, r7, #1
	add r5, r5, #4
	cmp r7, #3
	blt _0220202C
	mov r0, #7
	str r0, [sp]
	add r0, r4, #0
	mov r1, #3
	mov r2, #1
	mov r3, #0x69
	bl ov96_021EB3E4
	str r0, [r6, #0x4c]
	mov r0, #2
	lsl r0, r0, #0xe
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
	mov r0, #0
	str r0, [sp, #0x40]
	ldr r0, [r6, #0x4c]
	add r1, sp, #0x38
	bl ov96_021EB588
	ldr r0, [r6, #0x4c]
	mov r1, #5
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r6, #0x4c]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r6, #0x4c]
	mov r1, #2
	bl ov96_021EB630
	ldr r5, _02202150 ; =ov96_0221C910
	add r3, sp, #0x14
	mov r2, #4
_0220209A:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220209A
	ldr r0, [r5]
	add r5, r6, #0
	str r0, [r3]
	ldr r0, [sp, #4]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	mov r0, #0
	str r0, [sp, #8]
	add r0, sp, #0x14
	str r0, [sp, #0xc]
_022020C4:
	mov r0, #8
	str r0, [sp]
	add r0, r4, #0
	mov r1, #3
	mov r2, #1
	mov r3, #0x69
	bl ov96_021EB3E4
	ldr r1, [sp, #0xc]
	str r0, [r5, #0x58]
	bl ov96_021EB588
	ldr r0, [r5, #0x58]
	add r1, r7, #1
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r5, #0x58]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r7, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [r5, #0x58]
	mov r1, #3
	bl ov96_021EB630
	ldr r0, [sp, #0xc]
	add r5, r5, #4
	add r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #3
	blt _022020C4
	mov r5, #0
	mov r7, #0xa
_0220211E:
	str r7, [sp]
	add r0, r4, #0
	mov r1, #3
	mov r2, #1
	mov r3, #0x69
	bl ov96_021EB3E4
	str r0, [r6, #0x70]
	mov r1, #0
	bl ov96_021EB564
	ldr r0, [r6, #0x70]
	mov r1, #4
	bl ov96_021EB630
	add r5, r5, #1
	add r6, r6, #4
	cmp r5, #9
	blt _0220211E
	add sp, #0x5c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02202148: .word 0x000005D4
_0220214C: .word 0x00000418
_02202150: .word ov96_0221C910
	thumb_func_end ov96_02201EF0




	thumb_func_start ov96_02202154
ov96_02202154: ; 0x02202154
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r4, r1, #0
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _02202172
	cmp r0, #1
	beq _02202184
	cmp r0, #2
	beq _0220219C
	b _022021CC
_02202172:
	add r0, r5, #0
	bl ov96_021E637C
	cmp r0, #0
	beq _022021CC
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _022021CC
_02202184:
	add r0, r5, #0
	bl ov96_0220223C
	add r0, r5, #0
	bl ov96_022028BC
	cmp r0, #0
	beq _022021CC
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	b _022021CC
_0220219C:
	add r0, r5, #0
	bl ov96_0220223C
	add r0, r5, #0
	bl ov96_021E667C
	cmp r0, #0
	beq _022021CC
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x44]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	add r0, r5, #0
	mov r1, #1
	bl PokeathlonCourse_SetStateField07
_022021CC:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_02202154




	thumb_func_start ov96_022021D4
ov96_022021D4: ; 0x022021D4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r4, r1, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r5, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	ldrb r0, [r4]
	cmp r0, #0
	bne _022021FC
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _022021F8
	mov r0, #1
	strb r0, [r4]
_022021F8:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_022021FC:
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r0, #0
	beq _0220220A
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0220220A:
	add r5, #0x28
	add r0, r5, #0
	bl ov96_021E8A20
	ldr r7, _02202238 ; =0x000003FF
	add r5, r0, #0
	mov r4, #0
_02202218:
	ldrh r2, [r5]
	lsl r1, r4, #0x18
	add r0, r6, #0
	and r2, r7
	lsl r2, r2, #0x10
	lsr r1, r1, #0x18
	lsr r2, r2, #0x10
	bl PokeathlonCourse_SetField5E0_AtIndex
	add r4, r4, #1
	add r5, r5, #2
	cmp r4, #4
	blt _02202218
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02202238: .word 0x000003FF
	thumb_func_end ov96_022021D4




	thumb_func_start ov96_0220223C
ov96_0220223C: ; 0x0220223C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa0
	str r0, [sp, #4]
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #0x24]
	ldr r0, [sp, #4]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r0, [sp, #4]
	bl ov96_021E5F24
	cmp r0, #0
	beq _0220225C
	b _02202706
_0220225C:
	mov r0, #0x5d
	lsl r0, r0, #4
	ldrb r0, [r4, r0]
	cmp r0, #0
	beq _0220227C
	ldr r0, [sp, #0x24]
	add r0, #0x28
	str r0, [sp, #0x24]
	bl ov96_021E8A20
	add r1, r0, #0
	add r0, r4, #0
	bl ov96_02202738
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
_0220227C:
	ldr r0, [sp, #0x24]
	add r0, #0x50
	bl ov96_021E8A20
	add r5, r0, #0
	ldr r0, [sp, #0x24]
	bl ov96_021E8A20
	add r3, r0, #0
	mov r2, #4
_02202290:
	ldmia r3!, {r0, r1}
	stmia r5!, {r0, r1}
	sub r2, r2, #1
	bne _02202290
	ldr r0, [r3]
	str r0, [r5]
	ldr r0, _02202598 ; =0x000005E8
	ldrh r1, [r4, r0]
	cmp r1, #0
	beq _022022A8
	sub r1, r1, #1
	strh r1, [r4, r0]
_022022A8:
	ldr r0, [sp, #0x24]
	add r0, #0x28
	bl ov96_021E8A20
	mov r0, #0
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x24]
	add r5, r4, #0
	str r0, [sp, #0x1c]
	add r0, #0x50
	str r0, [sp, #0x1c]
	add r0, r4, #0
	str r0, [sp, #0x34]
	add r0, #0xd4
	str r0, [sp, #0x34]
	add r0, r4, #0
	str r0, [sp, #0x2c]
	add r0, #0xe0
	str r0, [sp, #0x2c]
	add r0, r4, #0
	str r0, [sp, #0x30]
	add r0, #0xec
	str r0, [sp, #0x30]
_022022D6:
	ldr r0, [sp, #0x1c]
	bl ov96_021E8A20
	add r7, r0, #0
	ldr r0, [r7]
	cmp r0, #0
	ldr r0, _0220259C ; =0x0000059C
	beq _02202316
	ldr r1, [r5, r0]
	cmp r1, #0
	beq _022022FC
	add r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _022022FC
	ldr r0, _0220259C ; =0x0000059C
	mov r1, #0
	str r1, [r5, r0]
	b _0220231E
_022022FC:
	cmp r1, #0
	bne _0220231E
	mov r0, #0x5a
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _0220231E
	ldr r0, _0220259C ; =0x0000059C
	mov r1, #1
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
	b _0220231E
_02202316:
	mov r1, #0
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
_0220231E:
	ldr r0, _0220259C ; =0x0000059C
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _022023EA
	add r0, sp, #0x94
	str r0, [sp]
	ldr r1, [sp, #0x28]
	ldrb r2, [r7, #4]
	lsl r1, r1, #0x18
	ldrb r3, [r7, #5]
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_022031A8
	add r6, r0, #0
	cmp r6, #0xc
	beq _022023E2
	lsl r0, r6, #5
	add r1, r4, r0
	mov r0, #0x43
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _02202412
	mov r0, #0x48
	mul r0, r6
	add r0, r4, r0
	add r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	beq _02202360
	cmp r0, #2
	bne _022023E2
_02202360:
	ldr r0, [sp, #0x28]
	add r3, r6, #0
	add r1, r4, r0
	ldr r0, _022025A0 ; =0x000005CC
	strb r6, [r1, r0]
	mov r0, #0x48
	mul r3, r0
	add r0, sp, #0x94
	mov ip, r0
	add r0, r4, r3
	str r0, [sp, #0x48]
	add r0, #0xe0
	mov r2, ip
	str r0, [sp, #0x48]
	ldmia r2!, {r0, r1}
	mov ip, r2
	ldr r2, [sp, #0x48]
	stmia r2!, {r0, r1}
	mov r0, ip
	ldr r1, [r0]
	add r0, r2, #0
	str r1, [r0]
	ldrb r0, [r7, #4]
	str r2, [sp, #0x48]
	add r2, r4, r3
	lsl r0, r0, #0xc
	str r0, [sp, #0x88]
	ldrb r0, [r7, #5]
	add r7, sp, #0x88
	add r2, #0xec
	lsl r0, r0, #0xc
	str r0, [sp, #0x90]
	mov r0, #0
	str r0, [sp, #0x8c]
	ldmia r7!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r7]
	str r0, [r2]
	add r0, r4, r3
	add r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	bne _022023E2
	mov r0, #0xc
	add r1, r6, #0
	mul r1, r0
	ldr r0, _022025A4 ; =ov96_0221C98C
	add r2, r4, r3
	add r6, r0, r1
	ldmia r6!, {r0, r1}
	add r2, #0xc8
	stmia r2!, {r0, r1}
	ldr r0, [r6]
	add r1, r4, r3
	str r0, [r2]
	add r1, #0xc4
	mov r0, #2
	str r0, [r1]
	add r1, r4, r3
	add r1, #0xfc
	mov r0, #0
	strh r0, [r1]
	add r1, r4, r3
	add r1, #0xfe
	strh r0, [r1]
_022023E2:
	ldr r0, _022025A8 ; =0x000005EA
	mov r1, #0
	strb r1, [r4, r0]
	b _022026A4
_022023EA:
	mov r0, #0x5a
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02202420
	ldr r0, [sp, #0x28]
	add r1, r4, r0
	ldr r0, _022025A0 ; =0x000005CC
	ldrb r0, [r1, r0]
	cmp r0, #0xc
	beq _02202412
	ldr r0, _022025A8 ; =0x000005EA
	ldrb r0, [r4, r0]
	bl _dfltu
	ldr r3, _022025AC ; =0x403E0000
	mov r2, #0
	bl _dls
	blo _02202414
_02202412:
	b _022026A4
_02202414:
	ldr r0, _022025A8 ; =0x000005EA
	ldrb r0, [r4, r0]
	add r1, r0, #1
	ldr r0, _022025A8 ; =0x000005EA
	strb r1, [r4, r0]
	b _022026A4
_02202420:
	ldr r0, [sp, #0x28]
	add r1, r4, r0
	ldr r0, _022025A0 ; =0x000005CC
	str r1, [sp, #0x18]
	ldrb r0, [r1, r0]
	cmp r0, #0xc
	bne _02202430
	b _0220269E
_02202430:
	add r0, sp, #0x7c
	str r0, [sp]
	ldr r1, [sp, #0x28]
	ldrb r2, [r7, #4]
	lsl r1, r1, #0x18
	ldrb r3, [r7, #5]
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_022031A8
	cmp r0, #0xc
	beq _022024A8
	ldr r2, [sp, #0x18]
	ldr r1, _022025A0 ; =0x000005CC
	ldrb r1, [r2, r1]
	cmp r0, r1
	bne _022024A8
	mov r1, #0x48
	mul r1, r0
	add r0, r4, r1
	add r0, #0xfc
	ldrh r0, [r0]
	cmp r0, #4
	bhs _022024EE
	add r0, r4, r1
	add r0, #0xfc
	ldrh r0, [r0]
	add r2, r0, #1
	add r0, r4, r1
	add r0, #0xfc
	strh r2, [r0]
	add r0, r4, r1
	add r0, #0xfc
	ldrh r0, [r0]
	cmp r0, #1
	bhi _02202482
	add r1, r4, r1
	add r1, #0xfe
	mov r0, #0
	strh r0, [r1]
	b _02202696
_02202482:
	cmp r0, #2
	bhi _02202490
	add r1, r4, r1
	add r1, #0xfe
	mov r0, #1
	strh r0, [r1]
	b _02202696
_02202490:
	cmp r0, #3
	bhi _0220249E
	add r1, r4, r1
	add r1, #0xfe
	mov r0, #2
	strh r0, [r1]
	b _02202696
_0220249E:
	add r1, r4, r1
	add r1, #0xfe
	mov r0, #3
	strh r0, [r1]
	b _02202696
_022024A8:
	mov r1, #0
	add r0, sp, #0x70
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r1, [sp, #0x18]
	ldr r0, _022025A0 ; =0x000005CC
	add r2, sp, #0x64
	ldrb r1, [r1, r0]
	mov r0, #0x48
	add r6, r1, #0
	str r1, [sp, #0x10]
	mul r6, r0
	ldr r1, [sp, #0x2c]
	add r0, sp, #0x7c
	add r1, r1, r6
	bl VEC_Subtract
	ldrb r0, [r7, #4]
	ldr r1, [sp, #0x30]
	add r2, sp, #0x58
	lsl r0, r0, #0xc
	str r0, [sp, #0x4c]
	ldrb r0, [r7, #5]
	add r1, r1, r6
	lsl r0, r0, #0xc
	str r0, [sp, #0x54]
	mov r0, #0
	str r0, [sp, #0x50]
	add r0, sp, #0x4c
	bl VEC_Subtract
	ldr r0, [sp, #0x60]
	cmp r0, #0
	ble _022024F0
_022024EE:
	b _02202696
_022024F0:
	add r3, sp, #0x64
	add r2, r4, r6
	ldmia r3!, {r0, r1}
	add r2, #0xd4
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [sp, #0x10]
	lsl r0, r0, #5
	add r1, r4, r0
	ldr r0, _022025B0 ; =0x0000042E
	str r1, [sp, #0x14]
	ldrsh r0, [r1, r0]
	cmp r0, #0x3c
	bgt _02202516
	mov r0, #0x3f
	lsl r0, r0, #0x18
	str r0, [sp, #0x20]
	b _0220253A
_02202516:
	cmp r0, #0x46
	bgt _02202520
	ldr r0, _022025B4 ; =0x3F19999A
	str r0, [sp, #0x20]
	b _0220253A
_02202520:
	cmp r0, #0x50
	bgt _0220252A
	ldr r0, _022025B8 ; =0x3F333333
	str r0, [sp, #0x20]
	b _0220253A
_0220252A:
	cmp r0, #0x5a
	bgt _02202534
	ldr r0, _022025BC ; =0x3F4CCCCD
	str r0, [sp, #0x20]
	b _0220253A
_02202534:
	mov r0, #0xfe
	lsl r0, r0, #0x16
	str r0, [sp, #0x20]
_0220253A:
	ldr r0, [sp, #0x34]
	add r0, r0, r6
	bl VEC_Mag
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	bl _fflt
	add r7, r0, #0
	bl _f2d
	mov r3, #1
	mov r2, #0
	lsl r3, r3, #0x1e
	bl _dgr
	bls _02202566
	mov r7, #1
	lsl r7, r7, #0x1e
	b _0220257A
_02202566:
	add r0, r7, #0
	bl _f2d
	ldr r3, _022025C0 ; =0x3FF00000
	mov r2, #0
	bl _dls
	bhs _0220257A
	mov r7, #0xfe
	lsl r7, r7, #0x16
_0220257A:
	ldr r0, _022025A8 ; =0x000005EA
	ldrb r0, [r4, r0]
	bl _ffltu
	bl _f2d
	ldr r3, _022025AC ; =0x403E0000
	mov r2, #0
	bl _ddiv
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _022025C0 ; =0x3FF00000
	b _022025C4
	nop
_02202598: .word 0x000005E8
_0220259C: .word 0x0000059C
_022025A0: .word 0x000005CC
_022025A4: .word ov96_0221C98C
_022025A8: .word 0x000005EA
_022025AC: .word 0x403E0000
_022025B0: .word 0x0000042E
_022025B4: .word 0x3F19999A
_022025B8: .word 0x3F333333
_022025BC: .word 0x3F4CCCCD
_022025C0: .word 0x3FF00000
_022025C4:
	mov r0, #0
	bl _dadd
	bl _d2f
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x20]
	bl _f2d
	str r0, [sp, #0x3c]
	add r0, r7, #0
	str r1, [sp, #0xc]
	bl _f2d
	str r0, [sp, #0x40]
	add r7, r1, #0
	ldr r1, [sp, #0x14]
	ldr r0, _0220270C ; =0x0000041C
	ldr r0, [r1, r0]
	bl _f2d
	add r3, r1, #0
	mov r1, #1
	add r2, r0, #0
	mov r0, #0
	lsl r1, r1, #0x1e
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x40]
	add r1, r7, #0
	bl _dmul
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x3c]
	ldr r1, [sp, #0xc]
	bl _dmul
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x38]
	add r7, r1, #0
	bl _f2d
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x44]
	add r1, r7, #0
	bl _ddiv
	bl _d2f
	add r7, r0, #0
	bl _f2d
	ldr r3, _02202710 ; =0x40080000
	mov r2, #0
	bl _dgr
	bls _02202642
	ldr r7, _02202714 ; =0x40400000
	b _02202656
_02202642:
	add r0, r7, #0
	bl _f2d
	ldr r3, _02202718 ; =0x3FF00000
	mov r2, #0
	bl _dls
	bhs _02202656
	mov r7, #0xfe
	lsl r7, r7, #0x16
_02202656:
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x34]
	add r0, r0, r6
	add r1, r1, r6
	bl VEC_Normalize
	ldr r0, _0220271C ; =0x45800000
	add r1, r7, #0
	bl _fmul
	bl _ffix
	ldr r1, [sp, #0x34]
	ldr r3, [sp, #0x34]
	add r1, r1, r6
	add r2, sp, #0x70
	add r3, r3, r6
	bl VEC_MultAdd
	ldr r1, [sp, #0x14]
	ldr r0, _02202720 ; =0x00000428
	ldr r0, [r1, r0]
	ldr r1, [sp, #0x34]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r1, r1, r6
	bl ov96_02204320
	add r1, r4, r6
	add r1, #0xc4
	mov r0, #1
	str r0, [r1]
_02202696:
	ldr r1, [sp, #0x18]
	ldr r0, _02202724 ; =0x000005CC
	mov r2, #0xc
	strb r2, [r1, r0]
_0220269E:
	ldr r0, _02202728 ; =0x000005EA
	mov r1, #0
	strb r1, [r4, r0]
_022026A4:
	ldr r0, [sp, #0x1c]
	add r5, #0xc
	add r0, #0x28
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	str r0, [sp, #0x28]
	cmp r0, #4
	bge _022026B8
	b _022022D6
_022026B8:
	ldr r1, _0220272C ; =0x000005DC
	ldr r0, [r4, r1]
	add r1, #0xc
	ldrh r2, [r4, r1]
	ldr r1, _02202730 ; =0x00000708
	sub r1, r1, r2
	bl ov96_022043C0
	ldr r0, [sp, #4]
	bl ov96_022033FC
	ldr r0, [sp, #4]
	bl ov96_02203468
	add r0, r4, #0
	bl ov96_02203754
	ldr r0, [sp, #4]
	add r1, r4, #0
	bl ov96_02203544
	ldr r0, _02202734 ; =0x000005E8
	ldrh r1, [r4, r0]
	cmp r1, #0
	bne _022026EE
	mov r1, #1
	b _022026F0
_022026EE:
	mov r1, #0
_022026F0:
	sub r0, #0x18
	strb r1, [r4, r0]
	ldr r0, [sp, #0x24]
	add r0, #0x28
	str r0, [sp, #0x24]
	bl ov96_021E8A20
	add r1, r0, #0
	add r0, r4, #0
	bl ov96_02202738
_02202706:
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220270C: .word 0x0000041C
_02202710: .word 0x40080000
_02202714: .word 0x40400000
_02202718: .word 0x3FF00000
_0220271C: .word 0x45800000
_02202720: .word 0x00000428
_02202724: .word 0x000005CC
_02202728: .word 0x000005EA
_0220272C: .word 0x000005DC
_02202730: .word 0x00000708
_02202734: .word 0x000005E8
	thumb_func_end ov96_0220223C




	thumb_func_start ov96_02202738
ov96_02202738: ; 0x02202738
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	str r0, [sp]
	str r1, [sp, #4]
	mov r1, #0
	add r0, sp, #0x2c
	strb r1, [r0]
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	add r0, sp, #0x24
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	strh r1, [r0, #6]
	add r0, r1, #0
	ldr r4, [sp]
	str r0, [sp, #0x1c]
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	str r1, [sp, #0x18]
	add r5, r4, #0
	str r0, [sp, #8]
_02202766:
	add r0, r4, #0
	add r0, #0xc4
	ldr r1, [r0]
	ldr r0, [sp, #0xc]
	lsl r1, r0
	ldr r0, [sp, #0x18]
	orr r0, r1
	str r0, [sp, #0x18]
	ldr r0, _022028AC ; =0x00000433
	ldrb r0, [r5, r0]
	str r0, [sp, #0x10]
	add r0, r4, #0
	add r0, #0xfb
	ldrb r0, [r0]
	cmp r0, #0
	beq _0220278A
	mov r0, #1
	b _0220278C
_0220278A:
	mov r0, #0
_0220278C:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r1, r4, #0
	str r0, [sp, #0x14]
	add r1, #0xfb
	mov r0, #0
	strb r0, [r1]
	add r0, r4, #0
	add r0, #0xc8
	ldr r1, [r0]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r7, r0, #0xc
	add r0, r4, #0
	add r0, #0xd0
	ldr r1, [r0]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r6, r0, #0xc
	cmp r7, #1
	bge _022027BE
	mov r7, #1
	b _022027C4
_022027BE:
	cmp r7, #0x40
	ble _022027C4
	mov r7, #0x40
_022027C4:
	cmp r6, #1
	bge _022027CC
	mov r6, #1
	b _022027D2
_022027CC:
	cmp r6, #0x40
	ble _022027D2
	mov r6, #0x40
_022027D2:
	ldr r0, [sp, #0x1c]
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	mov r1, #3
	bl _s32_div_f
	ldr r0, [sp, #0x20]
	add r2, sp, #0x2c
	ldrb r2, [r2, r0]
	add r0, r4, #0
	add r0, #0xfe
	sub r3, r6, #1
	ldrh r0, [r0]
	lsl r1, r1, #1
	lsl r3, r3, #6
	lsl r0, r1
	add r2, r2, r0
	ldr r0, [sp, #0x20]
	add r1, sp, #0x2c
	strb r2, [r1, r0]
	ldr r0, [sp, #0x14]
	lsl r2, r0, #0xd
	ldr r0, [sp, #0x10]
	lsl r1, r0, #0xc
	sub r0, r7, #1
	add r0, r0, r3
	add r0, r1, r0
	add r1, r2, r0
	ldr r0, _022028B0 ; =0x00000431
	ldrb r0, [r5, r0]
	lsl r0, r0, #0xe
	add r1, r1, r0
	ldr r0, [sp, #8]
	strh r1, [r0, #8]
	ldr r0, [sp, #0x20]
	add r1, sp, #0x24
	lsl r0, r0, #1
	ldrh r2, [r1, r0]
	ldr r1, _022028B4 ; =0x0000042C
	ldrh r1, [r5, r1]
	add r2, r2, r1
	add r1, sp, #0x24
	strh r2, [r1, r0]
	ldrh r2, [r1, r0]
	ldr r1, _022028B8 ; =0x000003E7
	cmp r2, r1
	bls _0220283C
	add r2, r1, #0
	add r1, sp, #0x24
	strh r2, [r1, r0]
_0220283C:
	ldr r0, [sp, #0xc]
	add r4, #0x48
	add r0, r0, #2
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r5, #0x20
	add r0, r0, #2
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #0xc
	blt _02202766
	ldr r2, [sp, #4]
	mov r3, #0
	add r0, sp, #0x24
	add r1, sp, #0x2c
_0220285E:
	ldrb r4, [r1]
	add r3, r3, #1
	add r1, r1, #1
	lsl r5, r4, #0xa
	ldrh r4, [r0]
	add r0, r0, #2
	add r4, r5, r4
	strh r4, [r2]
	add r2, r2, #2
	cmp r3, #4
	blt _0220285E
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #4]
	str r1, [r0, #0x20]
	mov r1, #0x5d
	ldr r0, [sp]
	lsl r1, r1, #4
	ldrb r0, [r0, r1]
	add r1, #0x18
	lsl r2, r0, #0x18
	ldr r0, [sp, #0x18]
	add r2, r0, r2
	ldr r0, [sp, #4]
	str r2, [r0, #0x20]
	ldr r0, [sp]
	ldrh r0, [r0, r1]
	mov r1, #0x1e
	add r0, #0x1e
	bl _s32_div_f
	ldr r1, [sp, #4]
	lsl r0, r0, #0x19
	ldr r1, [r1, #0x20]
	add r1, r1, r0
	ldr r0, [sp, #4]
	str r1, [r0, #0x20]
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022028AC: .word 0x00000433
_022028B0: .word 0x00000431
_022028B4: .word 0x0000042C
_022028B8: .word 0x000003E7
	thumb_func_end ov96_02202738




	thumb_func_start ov96_022028BC
ov96_022028BC: ; 0x022028BC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r7, r0, #0
	bl ov96_021E8A20
	add r4, r0, #0
	mov r0, #0
	add r7, #0xf0
	str r0, [r4]
	add r0, r7, #0
	bl ov96_021E8A20
	ldr r0, [r0, #0x20]
	mov r1, #1
	asr r0, r0, #0x18
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _0220290A
	ldr r0, [r6, #0x48]
	bl ov96_021EB63C
	ldr r0, _0220294C ; =0x000005D8
	mov r1, #1
	ldr r0, [r6, r0]
	bl ov96_021EB144
	ldr r1, _02202950 ; =ov96_022038D4
	add r0, r5, #0
	bl ov96_021E8324
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0220290A:
	bl System_GetTouchNew
	cmp r0, #0
	beq _0220292C
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
_0220292C:
	bl System_GetTouchHeld
	cmp r0, #0
	beq _02202942
	ldr r0, _02202954 ; =gSystem + 0x40
	ldrh r1, [r0, #0x20]
	strb r1, [r4, #4]
	ldrh r0, [r0, #0x22]
	strb r0, [r4, #5]
	mov r0, #1
	str r0, [r4]
_02202942:
	add r0, r5, #0
	bl ov96_02202958
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220294C: .word 0x000005D8
_02202950: .word ov96_022038D4
_02202954: .word gSystem + 0x40
	thumb_func_end ov96_022028BC




	thumb_func_start ov96_02202958
ov96_02202958: ; 0x02202958
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14c
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #0x58]
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x58]
	ldr r0, [r0, #0x20]
	asr r1, r0, #0x19
	mov r0, #0x7f
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x54]
	bne _02202994
	mov r1, #0
	b _0220299C
_02202994:
	ldr r0, [sp, #0x54]
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
_0220299C:
	add r0, r4, #0
	bl ov96_022038A0
	ldr r1, [sp, #0x2c]
	mov r0, #0x5e
	lsl r2, r1, #1
	ldr r1, [sp, #0x58]
	lsl r0, r0, #4
	ldrh r2, [r1, r2]
	ldr r1, _02202CE8 ; =0x000003FF
	ldr r0, [r4, r0]
	and r1, r2
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	bl ov96_02203BD0
	ldr r0, [sp, #0x2c]
	mov r1, #4
	sub r0, r1, r0
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x1c]
	ldr r0, _02202CEC ; =FX_SinCosTable_
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsl r1, r1, #0xe
	asr r1, r1, #4
	lsl r1, r1, #2
	add r0, r0, r1
	ldr r5, [sp, #0x58]
	mov r6, #0
	str r0, [sp, #0x5c]
_022029DA:
	ldrh r0, [r5, #8]
	asr r1, r0, #0xd
	mov r0, #1
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _02202AD2
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	ldr r1, [sp, #0x2c]
	cmp r1, r0
	bne _02202AD2
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x16
	add r0, r4, r0
	str r0, [sp, #0x30]
	mov r1, #1
	ldr r0, [r0, #0x64]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [sp, #0x30]
	mov r1, #6
	ldr r0, [r0, #0x64]
	bl ov96_021EB564
	ldrh r1, [r5, #8]
	mov r0, #0x3f
	add r2, r1, #0
	asr r1, r1, #6
	and r1, r0
	add r7, r1, #1
	and r2, r0
	ldr r1, [sp, #0x2c]
	add r0, r2, #1
	cmp r1, #0
	beq _02202A8A
	mov r2, #0
	str r2, [sp, #0x108]
	lsl r1, r0, #0xc
	mov r2, #0x21
	lsl r0, r7, #0xc
	lsl r2, r2, #0xc
	str r1, [sp, #0x104]
	sub r1, r1, r2
	str r1, [sp, #0x104]
	add r1, r2, #0
	ldr r2, [sp, #0x5c]
	str r0, [sp, #0x10c]
	sub r0, r0, r1
	mov r1, #0
	str r0, [sp, #0x10c]
	ldrsh r1, [r2, r1]
	add r3, r2, #0
	mov r2, #2
	ldrsh r2, [r3, r2]
	add r0, sp, #0x110
	bl MTX_RotY43_
	add r0, sp, #0x104
	add r1, sp, #0x110
	add r2, sp, #0xf8
	bl MTX_MultVec43
	mov r0, #0x21
	ldr r1, [sp, #0xf8]
	lsl r0, r0, #0xc
	add r0, r1, r0
	mov r1, #0x21
	ldr r2, [sp, #0x100]
	lsl r1, r1, #0xc
	add r1, r2, r1
	asr r2, r0, #0xb
	lsr r2, r2, #0x14
	add r2, r0, r2
	str r0, [sp, #0xf8]
	asr r0, r2, #0xc
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	str r1, [sp, #0x100]
	asr r7, r2, #0xc
_02202A8A:
	bl _fflt
	str r0, [sp, #0x60]
	add r0, r7, #0
	bl _fflt
	add r1, r0, #0
	ldr r0, [sp, #0x60]
	add r2, sp, #0x88
	add r3, sp, #0x84
	bl ov96_02204134
	ldr r0, [sp, #0x88]
	ldr r7, [sp, #0x84]
	lsl r0, r0, #0xc
	str r0, [sp, #0x140]
	lsl r0, r7, #0xc
	str r0, [sp, #0x144]
	mov r0, #0
	str r0, [sp, #0x148]
	add r0, r7, #0
	mov r1, #0x14
	bl _s32_div_f
	sub r7, #8
	sub r0, r7, r0
	lsl r0, r0, #0xc
	str r0, [sp, #0x144]
	ldr r0, [sp, #0x30]
	add r1, sp, #0x140
	ldr r0, [r0, #0x64]
	bl ov96_021EB588
	ldr r0, _02202CF0 ; =0x0000088F
	bl PlaySE
_02202AD2:
	add r6, r6, #1
	add r5, r5, #2
	cmp r6, #0xc
	bge _02202ADC
	b _022029DA
_02202ADC:
	ldr r0, [sp, #0x2c]
	mov r5, #0
	lsl r1, r0, #1
	add r0, r0, r1
	str r0, [sp, #0x34]
_02202AE6:
	ldr r0, [sp, #0x34]
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x58]
	lsl r1, r7, #1
	add r0, r0, r1
	str r0, [sp, #0x28]
	ldrh r0, [r0, #8]
	asr r1, r0, #0xe
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x50]
	cmp r0, #1
	bne _02202B28
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _02202CF4 ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #0
	bl ov96_02203BC0
	b _02202B70
_02202B28:
	ldr r0, [sp, #0x50]
	cmp r0, #2
	bne _02202B50
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _02202CF4 ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	mov r2, #0
	bl ov96_021EB52C
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #1
	bl ov96_02203BC0
	b _02202B70
_02202B50:
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _02202CF4 ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	mov r2, #0
	bl ov96_021EB52C
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #0
	bl ov96_02203BC0
_02202B70:
	ldr r0, [sp, #0x28]
	ldrh r0, [r0, #8]
	asr r1, r0, #0xc
	mov r0, #1
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x4c]
	ldr r0, [sp, #0x58]
	ldr r1, [r0, #0x20]
	lsl r0, r7, #1
	asr r1, r0
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x50]
	cmp r0, #1
	bne _02202BD2
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #0xa
	bl ov96_02203CA4
	ldr r0, _02202CF8 ; =0x00000434
	mov r1, #0xa
	strh r1, [r6, r0]
	mov r0, #0x89
	lsl r0, r0, #4
	bl IsSEPlaying
	cmp r0, #0
	bne _02202BC2
	mov r0, #0x89
	lsl r0, r0, #4
	bl PlaySE
_02202BC2:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _02202C88
	mov r0, #0x8b
	lsl r0, r0, #4
	bl PlaySE
	b _02202C88
_02202BD2:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _02202C02
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #7
	bl ov96_02203CA4
	ldr r0, _02202CF8 ; =0x00000434
	mov r1, #7
	strh r1, [r6, r0]
	mov r0, #0x8b
	lsl r0, r0, #4
	bl PlaySE
	mov r0, #0x5e
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_02203CD4
	b _02202C88
_02202C02:
	ldr r0, [sp, #0x48]
	cmp r0, #1
	bne _02202C4C
	ldr r0, _02202CFC ; =0x00000436
	ldrh r0, [r6, r0]
	cmp r0, #0
	bne _02202C4C
	ldr r0, [sp, #0x50]
	cmp r0, #1
	bne _02202C1A
	bl GF_AssertFail
_02202C1A:
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #4
	bl ov96_02203CA4
	lsl r0, r7, #5
	ldr r1, _02202CF8 ; =0x00000434
	add r0, r4, r0
	mov r2, #4
	strh r2, [r0, r1]
	mov r2, #1
	add r1, r1, #2
	strh r2, [r0, r1]
	ldr r0, _02202D00 ; =0x000005EF
	add r1, r4, r5
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _02202C88
	ldr r0, _02202D04 ; =0x000008AC
	bl PlaySE
	b _02202C88
_02202C4C:
	ldr r0, _02202CF8 ; =0x00000434
	mov r7, #0
	ldrh r0, [r6, r0]
	cmp r0, #0xa
	bne _02202C5A
	mov r7, #1
	b _02202C6E
_02202C5A:
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	bl ov96_02203CC4
	cmp r0, #0
	bne _02202C6E
	mov r7, #1
_02202C6E:
	cmp r7, #0
	beq _02202C88
	mov r0, #0x5e
	lsl r0, r0, #4
	lsl r1, r5, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	mov r2, #1
	bl ov96_02203CA4
	ldr r0, _02202CF8 ; =0x00000434
	mov r1, #1
	strh r1, [r6, r0]
_02202C88:
	ldr r0, [sp, #0x48]
	cmp r0, #1
	beq _02202C94
	ldr r0, _02202CFC ; =0x00000436
	mov r1, #0
	strh r1, [r6, r0]
_02202C94:
	ldr r0, [sp, #0x34]
	add r5, r5, #1
	add r0, r0, #1
	str r0, [sp, #0x34]
	cmp r5, #3
	bge _02202CA2
	b _02202AE6
_02202CA2:
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x2c]
	add r1, r0, #1
	lsl r0, r1, #1
	add r0, r1, r0
	mov r1, #0xc
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x38]
	add r5, r4, #0
_02202CBC:
	ldr r0, [sp, #0x38]
	mov r1, #0xc
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x58]
	lsl r1, r7, #1
	add r0, r0, r1
	ldrh r0, [r0, #8]
	asr r1, r0, #0xe
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	cmp r0, #1
	bne _02202D1E
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _02202CF4 ; =0x00000418
	b _02202D08
	.balign 4, 0
_02202CE8: .word 0x000003FF
_02202CEC: .word FX_SinCosTable_
_02202CF0: .word 0x0000088F
_02202CF4: .word 0x00000418
_02202CF8: .word 0x00000434
_02202CFC: .word 0x00000436
_02202D00: .word 0x000005EF
_02202D04: .word 0x000008AC
_02202D08:
	mov r1, #1
	ldr r0, [r6, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x70]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	b _02202D5A
_02202D1E:
	ldr r0, [sp, #0x10]
	cmp r0, #2
	bne _02202D40
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _0220305C ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	mov r2, #0
	bl ov96_021EB52C
	mov r1, #1
	ldr r0, [r5, #0x70]
	add r2, r1, #0
	bl ov96_021EB52C
	b _02202D5A
_02202D40:
	lsl r0, r7, #5
	add r6, r4, r0
	ldr r0, _0220305C ; =0x00000418
	mov r1, #1
	ldr r0, [r6, r0]
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x70]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_02202D5A:
	ldr r0, [sp, #0x58]
	lsl r2, r7, #1
	add r0, r0, r2
	ldrh r0, [r0, #8]
	str r0, [sp, #0x64]
	asr r1, r0, #0xc
	mov r0, #1
	and r0, r1
	ldr r1, [sp, #0x58]
	lsl r0, r0, #0x18
	ldr r1, [r1, #0x20]
	lsr r0, r0, #0x18
	asr r1, r2
	mov r2, #3
	and r1, r2
	lsl r1, r1, #0x18
	lsr r3, r1, #0x18
	ldr r2, [sp, #0x64]
	mov r1, #0x3f
	and r1, r2
	str r1, [sp, #0x78]
	add r1, r2, #0
	asr r2, r1, #6
	mov r1, #0x3f
	and r1, r2
	mov ip, r1
	ldr r1, [sp, #0x10]
	cmp r1, #1
	bne _02202DBC
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0x14
	bl ov96_021EAC5C
	ldr r0, _02203060 ; =0x00000434
	mov r1, #0x14
	strh r1, [r6, r0]
	mov r0, #0x89
	lsl r0, r0, #4
	bl IsSEPlaying
	cmp r0, #0
	bne _02202E58
	mov r0, #0x89
	lsl r0, r0, #4
	bl PlaySE
	b _02202E58
_02202DBC:
	cmp r0, #0
	beq _02202DD4
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0x16
	bl ov96_021EAC5C
	ldr r0, _02203060 ; =0x00000434
	mov r1, #0x16
	strh r1, [r6, r0]
	b _02202E58
_02202DD4:
	cmp r3, #1
	bne _02202E24
	ldr r2, [sp, #0x78]
	mov r0, #0xc
	add r3, r2, #1
	ldr r2, _02203064 ; =ov96_0221C98C
	mul r0, r7
	ldr r1, _02203064 ; =ov96_0221C98C
	ldr r2, [r2, r0]
	add r1, r1, r0
	asr r0, r2, #0xb
	lsr r0, r0, #0x14
	add r0, r2, r0
	asr r0, r0, #0xc
	cmp r3, r0
	bne _02202E24
	ldr r2, [r1, #8]
	mov r0, ip
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	add r0, r0, #1
	asr r1, r1, #0xc
	cmp r0, r1
	bne _02202E24
	ldr r0, [sp, #0x10]
	cmp r0, #1
	bne _02202E10
	bl GF_AssertFail
_02202E10:
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0x10
	bl ov96_021EAC5C
	ldr r0, _02203060 ; =0x00000434
	mov r1, #0x10
	strh r1, [r6, r0]
	b _02202E58
_02202E24:
	ldr r0, _02203060 ; =0x00000434
	mov r7, #0
	ldrh r0, [r6, r0]
	cmp r0, #0x14
	bne _02202E32
	mov r7, #1
	b _02202E42
_02202E32:
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	bl ov96_021EAD78
	cmp r0, #0
	bne _02202E42
	mov r7, #1
_02202E42:
	cmp r7, #0
	beq _02202E58
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0
	bl ov96_021EAC5C
	ldr r0, _02203060 ; =0x00000434
	mov r1, #0
	strh r1, [r6, r0]
_02202E58:
	ldr r0, [sp, #0x38]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #9
	bge _02202E6C
	b _02202CBC
_02202E6C:
	ldr r0, [sp, #0x58]
	ldr r3, _02203068 ; =ov96_0221C7C4
	str r0, [sp, #0x3c]
	add r2, sp, #0x8c
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r1, [sp, #0x1c]
	ldr r0, [r3]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsl r1, r1, #0xe
	str r0, [r2]
	asr r1, r1, #4
	mov r6, #0
	ldr r0, _0220306C ; =FX_SinCosTable_
	lsl r1, r1, #2
	add r0, r0, r1
	str r6, [sp, #0x40]
	add r5, r4, #0
	str r0, [sp, #0x68]
_02202E94:
	ldr r0, [sp, #0x58]
	ldr r1, [r0, #0x20]
	ldr r0, [sp, #0x40]
	asr r1, r0
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	add r0, r7, #0
	add r0, #0xff
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bls _02202EB2
	b _022030DE
_02202EB2:
	add r1, r5, #0
	add r1, #0xfa
	mov r0, #0
	strb r0, [r1]
	cmp r7, #2
	beq _02202ECE
	add r0, r5, #0
	add r0, #0xbc
	mov r1, #1
	ldr r0, [r0]
	add r2, r1, #0
	bl ov96_021EB52C
	b _02202EDC
_02202ECE:
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_02202EDC:
	add r0, r5, #0
	add r0, #0xb8
	mov r1, #1
	ldr r0, [r0]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x24]
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	ldr r0, [sp, #0x24]
	str r1, [sp, #0xc]
	lsl r1, r0, #1
	ldr r0, [sp, #0x58]
	ldrh r0, [r0, r1]
	asr r1, r0, #0xa
	mov r0, #0x3f
	and r0, r1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0xc]
	lsl r0, r0, #1
	asr r1, r0
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x3c]
	ldrh r1, [r0, #8]
	mov r0, #0x3f
	and r0, r1
	asr r2, r1, #6
	mov r1, #0x3f
	and r1, r2
	add r1, r1, #1
	str r1, [sp, #0x44]
	ldr r1, [sp, #0x2c]
	add r0, r0, #1
	cmp r1, #0
	beq _02202F96
	mov r2, #0
	str r2, [sp, #0xb4]
	lsl r1, r0, #0xc
	mov r2, #0x21
	ldr r0, [sp, #0x44]
	lsl r2, r2, #0xc
	str r1, [sp, #0xb0]
	sub r1, r1, r2
	lsl r0, r0, #0xc
	str r1, [sp, #0xb0]
	add r1, r2, #0
	ldr r2, [sp, #0x68]
	str r0, [sp, #0xb8]
	sub r0, r0, r1
	mov r1, #0
	str r0, [sp, #0xb8]
	ldrsh r1, [r2, r1]
	add r3, r2, #0
	mov r2, #2
	ldrsh r2, [r3, r2]
	add r0, sp, #0xbc
	bl MTX_RotY43_
	add r0, sp, #0xb0
	add r1, sp, #0xbc
	add r2, sp, #0xa4
	bl MTX_MultVec43
	mov r0, #0x21
	ldr r1, [sp, #0xa4]
	lsl r0, r0, #0xc
	add r0, r1, r0
	mov r1, #0x21
	ldr r2, [sp, #0xac]
	lsl r1, r1, #0xc
	add r1, r2, r1
	asr r2, r0, #0xb
	lsr r2, r2, #0x14
	add r2, r0, r2
	str r0, [sp, #0xa4]
	asr r0, r2, #0xc
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	str r1, [sp, #0xac]
	asr r1, r2, #0xc
	str r1, [sp, #0x44]
_02202F96:
	bl _fflt
	str r0, [sp, #0x6c]
	ldr r0, [sp, #0x44]
	bl _fflt
	add r1, r0, #0
	ldr r0, [sp, #0x6c]
	add r2, sp, #0x80
	add r3, sp, #0x7c
	bl ov96_02204134
	ldr r0, [sp, #0x80]
	add r1, sp, #0xec
	lsl r0, r0, #0xc
	str r0, [sp, #0xec]
	ldr r0, [sp, #0x7c]
	lsl r0, r0, #0xc
	str r0, [sp, #0xf0]
	mov r0, #0
	str r0, [sp, #0xf4]
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	bl ov96_021EB588
	ldr r0, [sp, #0x7c]
	mov r1, #0x14
	str r0, [sp, #0x18]
	bl _s32_div_f
	ldr r1, [sp, #0x18]
	sub r1, #8
	sub r0, r1, r0
	lsl r0, r0, #0xc
	str r0, [sp, #0xf0]
	add r0, r5, #0
	add r0, #0xb8
	str r1, [sp, #0x18]
	ldr r0, [r0]
	add r1, sp, #0xec
	bl ov96_021EB588
	add r3, sp, #0x8c
	ldmia r3!, {r0, r1}
	add r2, sp, #0x98
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [sp, #0x7c]
	bl _fflt
	bl _f2d
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _02203070 ; =0x40738000
	mov r0, #0
	bl _dadd
	ldr r3, _02203074 ; =0x40878000
	mov r2, #0
	bl _ddiv
	str r0, [sp, #0x70]
	add r0, r7, #0
	str r1, [sp, #8]
	bl _ffltu
	bl _f2d
	ldr r3, _02203078 ; =0x40080000
	mov r2, #0
	bl _ddiv
	add r2, r0, #0
	add r3, r1, #0
	ldr r1, _0220307C ; =0x3FF00000
	mov r0, #0
	bl _dadd
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x70]
	ldr r1, [sp, #8]
	bl _dmul
	bl _d2f
	str r0, [sp, #0x74]
	ldr r0, _02203080 ; =0x45800000
	ldr r1, [sp, #0x74]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x98]
	ldr r0, _02203080 ; =0x45800000
	b _02203084
	.balign 4, 0
_0220305C: .word 0x00000418
_02203060: .word 0x00000434
_02203064: .word ov96_0221C98C
_02203068: .word ov96_0221C7C4
_0220306C: .word FX_SinCosTable_
_02203070: .word 0x40738000
_02203074: .word 0x40878000
_02203078: .word 0x40080000
_0220307C: .word 0x3FF00000
_02203080: .word 0x45800000
_02203084:
	ldr r1, [sp, #0x74]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x9c]
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	add r1, sp, #0x98
	mov r2, #2
	bl ov96_021EB5A0
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	add r1, sp, #0x98
	mov r2, #2
	bl ov96_021EB5A0
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	add r1, sp, #0x98
	mov r2, #2
	bl ov96_021EB5A0
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x2c]
	cmp r1, r0
	bne _02203168
	ldr r0, [sp, #0xc]
	add r1, r4, r0
	ldr r0, _02203198 ; =0x000005EC
	str r1, [sp, #0x20]
	ldrb r0, [r1, r0]
	cmp r7, r0
	beq _02203168
	ldr r0, _0220319C ; =0x000008B1
	bl PlaySE
	ldr r1, [sp, #0x20]
	ldr r0, _02203198 ; =0x000005EC
	strb r7, [r1, r0]
	b _02203168
_022030DE:
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	cmp r7, #3
	bne _02203168
	add r0, r5, #0
	add r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _02203168
	add r1, r5, #0
	add r1, #0xfa
	mov r0, #1
	strb r0, [r1]
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	bl ov96_021EB594
	add r1, r0, #0
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	bl ov96_021EB588
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #3
	bl ov96_021EB564
	add r0, r5, #0
	add r0, #0xc0
	mov r1, #1
	ldr r0, [r0]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	ldr r1, [sp, #0x2c]
	cmp r0, r1
	bne _02203168
	ldr r0, _022031A0 ; =0x000008B3
	bl PlaySE
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r0, r4, r1
	ldr r1, _022031A4 ; =0x000005EF
	mov r2, #0
	strb r2, [r0, r1]
	sub r1, r1, #3
	strb r2, [r0, r1]
_02203168:
	ldr r0, [sp, #0x40]
	add r6, r6, #1
	add r0, r0, #2
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x3c]
	add r5, #0x48
	add r0, r0, #2
	str r0, [sp, #0x3c]
	cmp r6, #0xc
	bge _0220317E
	b _02202E94
_0220317E:
	ldr r1, [sp, #0x2c]
	add r0, r4, #0
	bl ov96_02203970
	ldr r2, [sp, #0x54]
	mov r1, #0x1e
	ldr r0, [sp]
	mul r1, r2
	bl ov96_021E6454
	add sp, #0x14c
	pop {r4, r5, r6, r7, pc}
	nop
_02203198: .word 0x000005EC
_0220319C: .word 0x000008B1
_022031A0: .word 0x000008B3
_022031A4: .word 0x000005EF
	thumb_func_end ov96_02202958




	thumb_func_start ov96_022031A8
ov96_022031A8: ; 0x022031A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x68
	add r5, r1, #0
	mov r1, #0x12
	lsl r1, r1, #4
	add r0, r2, #0
	add r1, r3, r1
	add r2, sp, #4
	add r3, sp, #0
	bl ov96_0220404C
	ldr r0, _02203290 ; =0x45800000
	ldr r1, [sp, #4]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x5c]
	ldr r0, _02203290 ; =0x45800000
	ldr r1, [sp]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x64]
	mov r0, #0
	str r0, [sp, #0x60]
	cmp r5, #0
	beq _0220323C
	add r3, sp, #0x5c
	ldmia r3!, {r0, r1}
	add r2, sp, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _02203294 ; =FX_SinCosTable_
	str r0, [r2]
	mov r0, #0x21
	ldr r1, [sp, #0x20]
	lsl r0, r0, #0xc
	sub r1, r1, r0
	str r1, [sp, #0x20]
	ldr r1, [sp, #0x28]
	sub r0, r1, r0
	str r0, [sp, #0x28]
	lsl r0, r5, #0xe
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0x2c
	bl MTX_RotY43_
	add r0, sp, #0x20
	add r1, sp, #0x2c
	add r2, sp, #0x14
	bl MTX_MultVec43
	mov r0, #0x21
	ldr r1, [sp, #0x14]
	lsl r0, r0, #0xc
	add r1, r1, r0
	str r1, [sp, #0x14]
	ldr r1, [sp, #0x1c]
	add r3, sp, #0x14
	add r0, r1, r0
	str r0, [sp, #0x1c]
	ldmia r3!, {r0, r1}
	add r2, sp, #0x5c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
_0220323C:
	add r2, sp, #0x5c
	ldr r3, [sp, #0x80]
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	add r1, r5, #1
	str r0, [r3]
	lsl r0, r5, #1
	add r4, r5, r0
	lsl r0, r1, #1
	add r6, r1, r0
	cmp r4, r6
	bge _02203288
	mov r0, #0xc
	ldr r1, _02203298 ; =ov96_0221C98C
	mul r0, r4
	add r5, r1, r0
	add r7, sp, #8
_02203260:
	add r0, r5, #0
	add r1, sp, #0x5c
	add r2, r7, #0
	bl VEC_Subtract
	add r0, r7, #0
	bl VEC_Mag
	mov r1, #1
	lsl r1, r1, #0xe
	cmp r0, r1
	bgt _02203280
	lsl r0, r4, #0x18
	add sp, #0x68
	lsr r0, r0, #0x18
	pop {r3, r4, r5, r6, r7, pc}
_02203280:
	add r4, r4, #1
	add r5, #0xc
	cmp r4, r6
	blt _02203260
_02203288:
	mov r0, #0xc
	add sp, #0x68
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02203290: .word 0x45800000
_02203294: .word FX_SinCosTable_
_02203298: .word ov96_0221C98C
	thumb_func_end ov96_022031A8




	thumb_func_start ov96_0220329C
ov96_0220329C: ; 0x0220329C
	push {r4, r5, r6, lr}
	add r5, r1, #0
	add r1, r2, #0
	add r2, r3, #0
	ldr r4, [sp, #0x10]
	bl ov96_021E60D8
	add r6, r0, #0
	ldrb r0, [r6, #4]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl _fflt
	bl _f2d
	ldr r3, _0220330C ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	str r0, [r4, #4]
	ldrb r0, [r6]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x14]
	bl _fflt
	bl _f2d
	ldr r3, _0220330C ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	str r0, [r4, #8]
	ldrb r0, [r6, #4]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x28]
	str r0, [r4, #0x10]
	ldrb r0, [r6, #3]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x3c]
	bl _fflt
	str r0, [r4, #0xc]
	mov r0, #0
	strh r0, [r4, #0x14]
	strb r0, [r4, #0x18]
	strb r0, [r4, #0x19]
	mov r0, #0x78
	strh r0, [r4, #0x16]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0220330C: .word 0x40240000
	thumb_func_end ov96_0220329C




	thumb_func_start ov96_02203310
ov96_02203310: ; 0x02203310
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r0, [r6]
	ldr r2, _02203374 ; =ov96_0221C7B0
	add r1, r6, #4
	bl AddWindow
	mov r2, #0
	str r2, [sp]
	ldr r0, [r6]
	mov r1, #3
	mov r3, #1
	bl BG_FillCharDataRange
	add r0, r6, #4
	mov r1, #0
	bl FillWindowPixelBuffer
	add r5, r6, #0
	ldr r4, _02203378 ; =ov96_0221C7EC
	mov r7, #0
	add r5, #0x14
_0220333C:
	ldr r0, [r6]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r7, r7, #1
	add r4, #8
	add r5, #0x10
	cmp r7, #3
	blt _0220333C
	mov r1, #0
	str r1, [sp]
	ldr r0, [r6]
	add r2, r1, #0
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r6, #0x44]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02203374: .word ov96_0221C7B0
_02203378: .word ov96_0221C7EC
	thumb_func_end ov96_02203310




	thumb_func_start ov96_0220337C
ov96_0220337C: ; 0x0220337C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	add r0, r5, #4
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r2, _022033F4 ; =0x00000135
	ldr r3, [r5, #0x44]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	add r4, r0, #0
	ldr r0, [r5, #0x44]
	bl MessageFormat_New
	mov r1, #0
	str r1, [sp]
	mov r2, #1
	str r2, [sp, #4]
	add r2, r7, #0
	mov r3, #3
	add r6, r0, #0
	bl BufferIntegerAsString
	ldr r3, [r5, #0x44]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0xa4
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _022033F8 ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	add r0, r5, #4
	add r2, r7, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl MessageFormat_Delete
	add r0, r4, #0
	bl DestroyMsgData
	add r0, r5, #4
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022033F4: .word 0x00000135
_022033F8: .word 0x000F0E00
	thumb_func_end ov96_0220337C




	thumb_func_start ov96_022033FC
ov96_022033FC: ; 0x022033FC
	push {r3, r4, r5, r6, r7, lr}
	bl PokeathlonCourse_GetHeapAllocPtr4
	mov r5, #0
	mov r1, #0x43
	add r2, r5, #0
	mov r3, #2
	mov r4, #1
	lsl r1, r1, #4
_0220340E:
	ldrb r6, [r0, r1]
	cmp r6, #0
	beq _02203422
	mov r6, #0x43
	lsl r6, r6, #4
	ldrb r6, [r0, r6]
	sub r7, r6, #1
	mov r6, #0x43
	lsl r6, r6, #4
	strb r7, [r0, r6]
_02203422:
	ldr r6, _02203460 ; =0x0000042E
	ldrsh r6, [r0, r6]
	cmp r6, #0x78
	bge _02203434
	ldr r6, _02203460 ; =0x0000042E
	ldrsh r6, [r0, r6]
	add r7, r6, #1
	ldr r6, _02203460 ; =0x0000042E
	strh r7, [r0, r6]
_02203434:
	mov r6, #0x43
	lsl r6, r6, #4
	ldrb r6, [r0, r6]
	cmp r6, #0
	beq _02203444
	ldr r6, _02203464 ; =0x00000431
	strb r4, [r0, r6]
	b _02203454
_02203444:
	ldr r6, _02203460 ; =0x0000042E
	ldrsh r6, [r0, r6]
	cmp r6, #0x64
	ldr r6, _02203464 ; =0x00000431
	bgt _02203452
	strb r3, [r0, r6]
	b _02203454
_02203452:
	strb r2, [r0, r6]
_02203454:
	add r5, r5, #1
	add r0, #0x20
	cmp r5, #0xc
	blt _0220340E
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02203460: .word 0x0000042E
_02203464: .word 0x00000431
	thumb_func_end ov96_022033FC




	thumb_func_start ov96_02203468
ov96_02203468: ; 0x02203468
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	mov r0, #0
	add r5, r4, #0
	str r5, [sp]
	add r5, #0xc8
	add r7, r4, #0
	str r0, [sp, #8]
	str r5, [sp]
	add r7, #0xd4
	add r6, r0, #0
_02203484:
	mov r0, #0
	str r0, [sp, #4]
	add r0, r4, #0
	add r0, #0xc4
	ldr r0, [r0]
	cmp r0, #1
	bne _022034A2
	mov r0, #1
	ldr r3, [sp]
	lsl r0, r0, #0xc
	add r1, r7, #0
	add r2, r5, #0
	bl VEC_MultAdd
	b _022034CC
_022034A2:
	cmp r0, #3
	bne _022034CC
	add r0, r4, #0
	add r0, #0xf8
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xf8
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0xf8
	ldrb r0, [r0]
	cmp r0, #8
	blo _022034CC
	add r1, r4, #0
	add r1, #0xf8
	mov r0, #0
	strb r0, [r1]
	add r1, r4, #0
	add r1, #0xc4
	str r0, [r1]
_022034CC:
	add r0, r4, #0
	add r0, #0xc8
	ldr r1, [r0]
	mov r0, #1
	lsl r0, r0, #0xc
	cmp r1, r0
	blt _022034F4
	lsl r0, r0, #6
	cmp r1, r0
	bgt _022034F4
	add r0, r4, #0
	add r0, #0xd0
	ldr r1, [r0]
	mov r0, #1
	lsl r0, r0, #0xc
	cmp r1, r0
	blt _022034F4
	lsl r0, r0, #6
	cmp r1, r0
	ble _022034F8
_022034F4:
	mov r0, #1
	str r0, [sp, #4]
_022034F8:
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _02203528
	add r0, r4, #0
	add r0, #0xc4
	str r6, [r0]
	add r0, r4, #0
	add r0, #0xd4
	str r6, [r0]
	add r0, r4, #0
	add r0, #0xdc
	str r6, [r0]
	add r0, r4, #0
	add r0, #0xd8
	str r6, [r0]
	add r0, r4, #0
	add r0, #0xe0
	str r6, [r0]
	add r0, r4, #0
	add r0, #0xe8
	str r6, [r0]
	add r0, r4, #0
	add r0, #0xe4
	str r6, [r0]
_02203528:
	ldr r0, [sp]
	add r4, #0x48
	add r0, #0x48
	str r0, [sp]
	ldr r0, [sp, #8]
	add r5, #0x48
	add r0, r0, #1
	add r7, #0x48
	str r0, [sp, #8]
	cmp r0, #0xc
	blt _02203484
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02203468




	thumb_func_start ov96_02203544
ov96_02203544: ; 0x02203544
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #0x20]
	ldr r0, _02203730 ; =ov96_0221C98C
	str r1, [sp, #8]
	add r4, r1, #0
	str r0, [sp, #0x18]
_02203556:
	ldr r5, [sp, #8]
	mov r0, #0
	ldr r1, _02203734 ; =0x00000433
	str r0, [sp, #0x1c]
	strb r0, [r4, r1]
	add r0, r5, #0
	str r0, [sp, #0x14]
	add r0, #0xc8
	str r0, [sp, #0x14]
	add r0, r5, #0
	str r0, [sp, #0x10]
	add r0, #0xd4
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x20]
	mov r1, #3
	add r6, r5, #0
	bl _s32_div_f
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x20]
	mov r1, #3
	bl _s32_div_f
	ldr r0, [sp, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x24]
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x28]
_02203592:
	add r0, r5, #0
	add r0, #0xc4
	ldr r0, [r0]
	cmp r0, #1
	bne _022035C4
	ldr r0, [sp, #0x1c]
	mov r1, #3
	bl _s32_div_f
	add r7, r0, #0
	ldr r0, [sp, #0xc]
	cmp r7, r0
	beq _022035C4
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x14]
	add r2, sp, #0x2c
	bl VEC_Subtract
	add r0, sp, #0x2c
	bl VEC_Mag
	mov r1, #3
	lsl r1, r1, #0xc
	cmp r0, r1
	blt _022035C6
_022035C4:
	b _022036FA
_022035C6:
	add r1, r5, #0
	add r1, #0xc4
	mov r0, #3
	str r0, [r1]
	ldr r0, [sp, #0x1c]
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r7, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #3
	bl ov96_021E8228
	ldr r0, _02203738 ; =0x0000042C
	ldrh r0, [r6, r0]
	add r1, r0, #1
	ldr r0, _02203738 ; =0x0000042C
	strh r1, [r6, r0]
	ldrh r1, [r6, r0]
	sub r0, #0x45
	cmp r1, r0
	bls _02203606
	ldr r1, _0220373C ; =0x000003E7
	add r0, r1, #0
	add r0, #0x45
	strh r1, [r6, r0]
_02203606:
	add r1, r5, #0
	add r1, #0xfb
	mov r0, #1
	strb r0, [r1]
	add r1, r0, #0
	ldr r0, _02203734 ; =0x00000433
	strb r1, [r4, r0]
	add r0, r5, #0
	add r0, #0xfe
	ldrh r0, [r0]
	cmp r0, #3
	bhi _02203644
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0220362A: ; jump table
	.short _02203632 - _0220362A - 2 ; case 0
	.short _02203638 - _0220362A - 2 ; case 1
	.short _0220363C - _0220362A - 2 ; case 2
	.short _02203640 - _0220362A - 2 ; case 3
_02203632:
	mov r7, #0xfe
	lsl r7, r7, #0x16
	b _0220364C
_02203638:
	ldr r7, _02203740 ; =0x41A00000
	b _0220364C
_0220363C:
	ldr r7, _02203744 ; =0x42480000
	b _0220364C
_02203640:
	ldr r7, _02203748 ; =0x42C80000
	b _0220364C
_02203644:
	bl GF_AssertFail
	mov r7, #0xfe
	lsl r7, r7, #0x16
_0220364C:
	add r1, r5, #0
	add r1, #0xfe
	mov r0, #0
	strh r0, [r1]
	add r1, r5, #0
	add r1, #0xfc
	strh r0, [r1]
	ldr r0, [sp, #0x10]
	bl VEC_Mag
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fmul
	mov r1, #0x42
	lsl r1, r1, #4
	ldr r1, [r6, r1]
	bl _fmul
	add r1, r0, #0
	ldr r0, _0220374C ; =0x00000424
	ldr r0, [r4, r0]
	bl _fmul
	bl _ffix
	add r7, r0, #0
	bpl _02203692
	bl GF_AssertFail
_02203692:
	ldr r0, _02203750 ; =0x0000042E
	ldrsh r0, [r4, r0]
	sub r1, r0, r7
	ldr r0, _02203750 ; =0x0000042E
	sub r1, #0x1e
	strh r1, [r4, r0]
	ldrsh r0, [r4, r0]
	cmp r0, #0
	bge _022036AA
	ldr r0, _02203750 ; =0x0000042E
	mov r1, #0
	strh r1, [r4, r0]
_022036AA:
	ldr r0, _02203750 ; =0x0000042E
	ldrsh r1, [r4, r0]
	mov r0, #0x78
	sub r0, r0, r1
	mov r1, #0x43
	lsl r1, r1, #4
	ldrb r1, [r4, r1]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r1, #0
	bne _022036DC
	cmp r0, #0x28
	bls _022036FA
	mov r1, #0x43
	lsl r1, r1, #4
	strb r0, [r4, r1]
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x24]
	ldr r2, [sp, #0x28]
	mov r3, #1
	bl ov96_021E8228
	b _022036FA
_022036DC:
	mov r1, #0x43
	lsl r1, r1, #4
	ldrb r1, [r4, r1]
	ldr r2, [sp, #0x28]
	mov r3, #1
	add r1, r1, r0
	mov r0, #0x43
	lsl r0, r0, #4
	strb r1, [r4, r0]
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x24]
	bl ov96_021E8228
_022036FA:
	ldr r0, [sp, #0x14]
	add r5, #0x48
	add r0, #0x48
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r6, #0x20
	add r0, #0x48
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #0xc
	bge _02203716
	b _02203592
_02203716:
	ldr r0, [sp, #0x18]
	add r4, #0x20
	add r0, #0xc
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r0, r0, #1
	str r0, [sp, #0x20]
	cmp r0, #0xc
	bge _0220372A
	b _02203556
_0220372A:
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02203730: .word ov96_0221C98C
_02203734: .word 0x00000433
_02203738: .word 0x0000042C
_0220373C: .word 0x000003E7
_02203740: .word 0x41A00000
_02203744: .word 0x42480000
_02203748: .word 0x42C80000
_0220374C: .word 0x00000424
_02203750: .word 0x0000042E
	thumb_func_end ov96_02203544

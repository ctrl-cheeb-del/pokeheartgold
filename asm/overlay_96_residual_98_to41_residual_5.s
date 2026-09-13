	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text
	.extern ov96_0220D52C
	.extern ov96_0220D554
	.extern ov96_0220DE90

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


	thumb_func_start ov96_0220DEAC
ov96_0220DEAC: ; 0x0220DEAC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa0
	add r5, r0, #0
	str r2, [sp, #8]
	mov r0, #0
	str r1, [sp, #4]
	add r3, sp, #0x40
	add r1, r0, #0
	mov r2, #6
_0220DEBE:
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220DEBE
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x1c]
	add r0, sp, #0x40
	mov r6, #0
	str r0, [sp, #0x14]
	mov r0, #0xff
	add r5, #0x3c
	str r6, [sp, #0x10]
	str r0, [sp, #0x28]
	str r0, [sp, #0x24]
_0220DEDE:
	ldr r0, [sp, #0x1c]
	lsl r1, r6, #0x18
	ldr r0, [r0, #0x20]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r4, r0, #0
	cmp r5, #0
	bne _0220DEF4
	bl GF_AssertFail
_0220DEF4:
	cmp r4, #0
	bne _0220DEFC
	bl GF_AssertFail
_0220DEFC:
	ldr r0, [sp, #4]
	add r3, sp, #0x3c
	add r0, r0, r6
	ldrb r7, [r0, #0x10]
	str r0, [sp, #0xc]
	add r0, sp, #0x38
	str r0, [sp]
	ldr r1, [sp, #0xc]
	add r0, r4, #0
	ldrb r1, [r1, #4]
	add r2, r7, #0
	bl ov96_021EB0A4
	ldr r0, [sp, #0x14]
	strb r7, [r0]
	str r4, [r0, #4]
	ldr r0, [sp, #4]
	ldr r0, [r0, #0x20]
	lsl r0, r0, #0xd
	lsr r0, r0, #0x14
	add r1, r0, #0
	lsr r1, r6
	mov r0, #1
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	cmp r0, #1
	bne _0220DF68
	ldr r0, [r5, #0x18]
	lsl r0, r0, #0xc
	lsr r0, r0, #0x1f
	bne _0220DF68
	add r0, r4, #0
	mov r1, #1
	bl ov96_0220D554
	mov r0, #1
	ldr r1, [r5, #0x18]
	lsl r0, r0, #0x12
	orr r1, r0
	ldr r0, _0220E1FC ; =0xFFFF00FF
	and r1, r0
	mov r0, #6
	lsl r0, r0, #8
	orr r0, r1
	str r0, [r5, #0x18]
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [r5, #0x14]
	ldr r0, _0220E200 ; =0x0000089E
	bl PlaySE
	b _0220DFC6
_0220DF68:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _0220DFC6
	ldr r0, [r5, #0x18]
	lsl r0, r0, #0xc
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0220DFC6
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x38]
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	mov r3, #0x1e
	ldr r0, [r5]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r5]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	add r0, r4, #0
	mov r1, #0
	bl ov96_0220D554
	mov r1, #0xfe
	lsl r1, r1, #0x16
	add r0, r4, #0
	add r2, r1, #0
	bl ov96_021EB10C
	add r0, r4, #0
	mov r1, #1
	bl ov96_021EAB38
	ldr r1, [r5, #0x18]
	ldr r0, _0220E204 ; =0xFFFBFFFF
	and r0, r1
	str r0, [r5, #0x18]
	ldr r0, _0220E208 ; =0x000008B6
	bl PlaySE
_0220DFC6:
	ldr r2, [r5, #0x18]
	ldr r1, _0220E20C ; =0xFFF7FFFF
	add r0, r5, #0
	and r1, r2
	ldr r2, [sp, #0x18]
	add r0, #0x18
	lsl r2, r2, #0x1f
	lsr r2, r2, #0xc
	orr r1, r2
	str r1, [r5, #0x18]
	lsl r1, r1, #0xd
	lsr r1, r1, #0x1f
	beq _0220E058
	ldr r1, [r0]
	ldr r2, _0220E1FC ; =0xFFFF00FF
	and r2, r1
	lsl r1, r1, #0x10
	lsr r1, r1, #0x18
	sub r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x10
	orr r1, r2
	str r1, [r0]
	ldr r0, [r5, #0x18]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x18
	bne _0220E006
	add r0, r4, #0
	mov r1, #0
	bl ov96_021EAB38
	b _0220E1B4
_0220E006:
	ldr r1, [r5, #0x14]
	ldr r0, _0220E210 ; =0x0000019A
	sub r0, r1, r0
	str r0, [r5, #0x14]
	bl _fflt
	ldr r1, _0220E214 ; =0x45800000
	bl _fdiv
	add r1, r0, #0
	add r0, r4, #0
	add r2, r1, #0
	bl ov96_021EB10C
	add r0, sp, #0x30
	str r0, [sp]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0xc]
	ldrb r1, [r1, #4]
	ldrb r2, [r2, #0x10]
	add r0, r4, #0
	add r3, sp, #0x34
	bl ov96_021EB06C
	ldr r0, [sp, #0x30]
	cmp r0, #0xb4
	bge _0220E03E
	b _0220E1B4
_0220E03E:
	ldr r0, [r5, #0x18]
	mov r3, #1
	lsl r0, r0, #0x10
	lsr r1, r0, #0x18
	mov r0, #6
	sub r0, r0, r1
	lsl r2, r0, #2
	ldr r1, [sp, #0x3c]
	add r0, r4, #0
	add r2, r7, r2
	bl ov96_021EB01C
	b _0220E1B4
_0220E058:
	ldr r0, [sp, #4]
	ldr r2, [sp, #0x38]
	ldr r0, [r0, #0x1c]
	mov r3, #1
	lsl r0, r0, #8
	lsr r1, r0, #8
	ldr r0, [sp, #0x10]
	lsr r1, r0
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r1, [sp, #0x3c]
	add r0, r4, #0
	bl ov96_021EB01C
	add r0, r4, #0
	add r1, r7, #1
	bl ov96_021EAC0C
	ldr r0, [sp, #4]
	ldr r0, [r0, #0x20]
	lsl r0, r0, #1
	lsr r0, r0, #0x14
	add r1, r0, #0
	lsr r1, r6
	mov r0, #1
	tst r0, r1
	beq _0220E10C
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x20]
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	ldr r1, [sp, #0x20]
	lsl r2, r2, #0x18
	lsl r1, r1, #0x18
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_0220F378
	add r7, r0, #0
	ldr r0, [sp, #8]
	bl ov96_021E5F24
	ldr r1, [sp, #0x20]
	cmp r1, r0
	bne _0220E0E6
	ldr r0, [r5, #0x18]
	lsl r1, r0, #0xf
	lsr r1, r1, #0x1f
	bne _0220E0E6
	lsl r0, r0, #0xe
	lsr r0, r0, #0x1f
	bne _0220E0E6
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _0220E0E0
	ldr r0, _0220E218 ; =0x000005F3
	bl PlaySE
	b _0220E0E6
_0220E0E0:
	ldr r0, _0220E21C ; =0x000008C5
	bl PlaySE
_0220E0E6:
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _0220E100
	add r0, r5, #4
	add r1, r4, #0
	bl ov96_0220D52C
	mov r0, #2
	ldr r1, [r5, #0x18]
	lsl r0, r0, #0x10
	orr r0, r1
	str r0, [r5, #0x18]
	b _0220E114
_0220E100:
	mov r0, #1
	ldr r1, [r5, #0x18]
	lsl r0, r0, #0x10
	orr r0, r1
	str r0, [r5, #0x18]
	b _0220E114
_0220E10C:
	ldr r1, [r5, #0x18]
	ldr r0, _0220E220 ; =0xFFFDFFFF
	and r0, r1
	str r0, [r5, #0x18]
_0220E114:
	ldr r0, [r5, #0x18]
	lsl r0, r0, #0xf
	lsr r0, r0, #0x1f
	beq _0220E1B4
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	lsl r1, r7, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_0220F378
	ldr r1, [r5, #0x18]
	add r2, sp, #0x2c
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r7, r0, #0
	bl ov96_0220E8C0
	add r3, r0, #0
	ldr r2, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	add r2, r2, r3
	add r0, r4, #0
	mov r3, #0
	bl ov96_021EB01C
	ldr r1, [sp, #0x2c]
	add r0, r4, #0
	add r2, r1, #0
	bl ov96_021EB10C
	add r0, r7, #0
	bl ov96_0220F3B4
	ldr r7, [r5, #0x18]
	add r3, r0, #0
	add r2, r5, #0
	ldr r0, [sp, #0x24]
	add r1, r7, #0
	bic r1, r0
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	orr r0, r1
	str r0, [r5, #0x18]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r2, #0x18
	cmp r0, r3
	bls _0220E1B4
	ldr r1, [r2]
	ldr r0, _0220E224 ; =0xFFFEFFFF
	mov r3, #0
	and r1, r0
	ldr r0, [sp, #0x28]
	bic r1, r0
	str r1, [r2]
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x38]
	add r0, r4, #0
	bl ov96_021EB01C
	mov r1, #0xfe
	lsl r1, r1, #0x16
	add r0, r4, #0
	add r2, r1, #0
	bl ov96_021EB10C
_0220E1B4:
	ldr r0, [sp, #0x14]
	add r6, r6, #1
	add r0, #8
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r5, #0x1c
	add r0, r0, #2
	str r0, [sp, #0x10]
	cmp r6, #0xc
	bge _0220E1CA
	b _0220DEDE
_0220E1CA:
	mov r0, #0
	str r0, [sp]
	ldr r3, _0220E228 ; =ov96_0220DE90
	add r0, sp, #0x40
	mov r1, #0xc
	mov r2, #8
	bl MATH_QSort
	mov r5, #0
	add r4, sp, #0x40
_0220E1DE:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _0220E1E8
	bl GF_AssertFail
_0220E1E8:
	ldr r0, [r4, #4]
	add r1, r5, #7
	bl ov96_021EABA8
	add r5, r5, #1
	add r4, #8
	cmp r5, #0xc
	blt _0220E1DE
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220E1FC: .word 0xFFFF00FF
_0220E200: .word 0x0000089E
_0220E204: .word 0xFFFBFFFF
_0220E208: .word 0x000008B6
_0220E20C: .word 0xFFF7FFFF
_0220E210: .word 0x0000019A
_0220E214: .word 0x45800000
_0220E218: .word 0x000005F3
_0220E21C: .word 0x000008C5
_0220E220: .word 0xFFFDFFFF
_0220E224: .word 0xFFFEFFFF
_0220E228: .word ov96_0220DE90
	thumb_func_end ov96_0220DEAC

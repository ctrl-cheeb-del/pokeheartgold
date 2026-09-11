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

	thumb_func_start ov96_02219794
ov96_02219794: ; 0x02219794
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r2, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	add r0, r4, #1
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	add r0, r5, #0
	add r0, #0xc0
	ldrb r0, [r0]
	cmp r0, #0
	beq _022197C8
	cmp r0, #1
	beq _02219856
	cmp r0, #2
	bne _022197C6
	b _0221992A
_022197C6:
	b _02219936
_022197C8:
	add r0, r5, #0
	add r0, #0x9c
	add r1, sp, #8
	mov r3, #0x1e
	ldr r0, [r0]
	add r1, #2
	add r2, sp, #8
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r0, sp, #4
	mov r1, #4
	ldrsh r1, [r0, r1]
	cmp r1, #0xd8
	bge _0221981C
	mov r0, #0x11
	lsl r0, r0, #4
	sub r0, r0, r1
	bpl _022197F0
	neg r0, r0
_022197F0:
	add r2, sp, #4
	mov r1, #4
	lsl r0, r0, #0xe
	ldrsh r3, [r2, r1]
	asr r0, r0, #0x10
	add r0, r3, r0
	strh r0, [r2, #4]
	ldrsh r0, [r2, r1]
	cmp r0, #0xd8
	ble _02219808
	mov r0, #0xd8
	strh r0, [r2, #4]
_02219808:
	add r4, sp, #4
	mov r2, #6
	mov r3, #4
	ldrsh r2, [r4, r2]
	ldrsh r3, [r4, r3]
	add r0, r5, #0
	mov r1, #0xf
	bl ov96_02219F20
	b _0221993A
_0221981C:
	mov r2, #0x28
	add r3, r2, #0
	strh r2, [r0, #6]
	sub r3, #0x50
	strh r3, [r0, #4]
	add r0, r5, #0
	mov r1, #0xf
	bl ov96_02219F20
	str r4, [sp]
	add r2, r5, #0
	add r2, #0x9c
	ldr r0, [r5]
	ldr r1, [r5, #4]
	ldr r2, [r2]
	add r3, r7, #0
	bl ov96_02219DA8
	add r0, r5, #0
	add r1, r6, #0
	bl ov96_02219EE0
	add r0, r5, #0
	add r0, #0xc0
	ldrb r0, [r0]
	add r5, #0xc0
	add r0, r0, #1
	strb r0, [r5]
	b _0221993A
_02219856:
	add r0, r5, #0
	add r0, #0x98
	add r1, sp, #4
	mov r3, #0x1e
	ldr r0, [r0]
	add r1, #2
	add r2, sp, #4
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #4
	mov r0, #0
	ldrsh r0, [r1, r0]
	mov r1, #0x88
	sub r2, r1, r0
	bpl _02219878
	neg r2, r2
_02219878:
	lsl r1, r2, #1
	add r2, r2, r1
	asr r1, r2, #1
	lsr r1, r1, #0x1e
	add r1, r2, r1
	lsl r1, r1, #0xe
	asr r4, r1, #0x10
	cmp r0, #0x88
	bgt _022198D4
	cmp r4, #0
	bne _02219890
	mov r4, #1
_02219890:
	add r6, sp, #4
	mov r3, #0
	ldrsh r0, [r6, r3]
	mov r2, #2
	mov r1, #0xe
	add r0, r0, r4
	strh r0, [r6]
	ldrsh r2, [r6, r2]
	ldrsh r3, [r6, r3]
	add r0, r5, #0
	bl ov96_02219F20
	add r0, r5, #0
	add r0, #0x9c
	add r1, sp, #4
	mov r3, #0x1e
	ldr r0, [r0]
	add r1, #2
	add r2, sp, #4
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	mov r3, #0
	ldrsh r0, [r6, r3]
	mov r2, #2
	mov r1, #0xf
	add r0, r0, r4
	strh r0, [r6]
	ldrsh r2, [r6, r2]
	ldrsh r3, [r6, r3]
	add r0, r5, #0
	bl ov96_02219F20
	b _0221993A
_022198D4:
	add r0, r5, #0
	add r0, #0x98
	ldr r2, [r0]
	add r0, r5, #0
	add r0, #0x9c
	ldr r1, [r0]
	add r0, r5, #0
	add r0, #0x98
	str r1, [r0]
	add r0, r5, #0
	add r0, #0x9c
	str r2, [r0]
	add r0, r5, #0
	add r0, #0xa0
	ldr r2, [r0]
	add r0, r5, #0
	add r0, #0xa4
	ldr r1, [r0]
	add r0, r5, #0
	add r0, #0xa0
	str r1, [r0]
	add r0, r5, #0
	add r0, #0xa4
	str r2, [r0]
	add r0, r5, #0
	mov r1, #0xe
	mov r2, #0x28
	mov r3, #0x30
	bl ov96_02219F20
	add r0, r5, #0
	mov r1, #0xf
	mov r2, #0x28
	mov r3, #0x88
	bl ov96_02219F20
	add r0, r5, #0
	add r0, #0xc0
	ldrb r0, [r0]
	add r5, #0xc0
	add r0, r0, #1
	strb r0, [r5]
	b _0221993A
_0221992A:
	mov r0, #0
	add r5, #0xc0
	strb r0, [r5]
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02219936:
	bl GF_AssertFail
_0221993A:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_02219794


	thumb_func_start ov96_02219940
ov96_02219940: ; 0x02219940
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	beq _0221994C
	cmp r4, #4
	blo _02219950
_0221994C:
	bl GF_AssertFail
_02219950:
	add r5, #0xbc
	ldrsb r0, [r5, r4]
	add r0, r0, #1
	strb r0, [r5, r4]
	ldrsb r0, [r5, r4]
	cmp r0, #0xc
	ble _02219966
	mov r0, #0
	strb r0, [r5, r4]
	mov r0, #1
	pop {r3, r4, r5, pc}
_02219966:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02219940


	thumb_func_start ov96_0221996C
ov96_0221996C: ; 0x0221996C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	add r7, r3, #0
	cmp r5, #0
	bne _0221997E
	bl GF_AssertFail
_0221997E:
	cmp r4, #4
	blo _02219986
	bl GF_AssertFail
_02219986:
	cmp r6, #3
	blo _0221998E
	bl GF_AssertFail
_0221998E:
	cmp r7, #0
	bne _0221999C
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov96_02219DD0
_0221999C:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r7, #0
	bl ov96_02219F50
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0221996C


	thumb_func_start ov96_022199A8
ov96_022199A8: ; 0x022199A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r6, _02219A04 ; =ov96_0221D910
	add r7, r2, #0
	str r3, [sp]
	add r5, r0, #0
	add r4, r1, #0
	add r3, sp, #4
	mov r2, #6
_022199BA:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _022199BA
	ldr r0, [r6]
	cmp r5, #0
	str r0, [r3]
	bne _022199CE
	bl GF_AssertFail
_022199CE:
	cmp r4, #0
	bne _022199D6
	bl GF_AssertFail
_022199D6:
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
	mov r1, #1
	add r4, r0, #0
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02219A04: .word ov96_0221D910
	thumb_func_end ov96_022199A8


	thumb_func_start ov96_02219A08
ov96_02219A08: ; 0x02219A08
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bne _02219A12
	bl GF_AssertFail
_02219A12:
	ldr r0, [r5, #0x14]
	cmp r0, #0
	bne _02219A1C
	bl GF_AssertFail
_02219A1C:
	add r6, r5, #0
	ldr r7, _02219A58 ; =ov96_0221D8F8
	mov r4, #0
	add r6, #0x30
_02219A24:
	lsl r1, r4, #4
	lsl r2, r4, #3
	ldr r0, [r5, #0x14]
	add r1, r6, r1
	add r2, r7, r2
	bl AddWindow
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _02219A24
	mov r2, #0
	str r2, [sp]
	ldr r0, [r5, #0x14]
	mov r1, #5
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r5, #4]
	mov r0, #4
	lsl r1, r1, #4
	bl LoadFontPal0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02219A58: .word ov96_0221D8F8
	thumb_func_end ov96_02219A08


	thumb_func_start ov96_02219A5C
ov96_02219A5C: ; 0x02219A5C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r6, r1, #0
	add r5, r0, #0
	add r0, r6, #0
	mov r1, #0x64
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #3]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0]
	mov r0, #0x64
	mul r0, r4
	sub r0, r6, r0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #4]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0, #1]
	add r0, r6, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #5]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0, #2]
	mov r4, #0
	mov r6, #4
	mov r7, #8
_02219AE6:
	str r6, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x2c]
	lsl r2, r4, #2
	add r0, #0xc
	str r0, [sp, #8]
	add r0, sp, #0x1c
	add r0, #3
	ldrb r0, [r0, r4]
	add r2, #0x10
	lsl r2, r2, #0x18
	str r0, [sp, #0xc]
	add r0, sp, #0x1c
	ldrb r0, [r0, r4]
	mov r1, #6
	lsr r2, r2, #0x18
	str r0, [sp, #0x10]
	mov r0, #0x14
	str r0, [sp, #0x14]
	mov r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x14]
	mov r3, #0xb
	bl CopyRectToBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _02219AE6
	ldr r0, [r5, #0x14]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02219A5C


	thumb_func_start ov96_02219B30
ov96_02219B30: ; 0x02219B30
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r0, #0x30
	mov r1, #0
	bl FillWindowPixelBuffer
	add r1, r5, #0
	add r1, #0x22
	ldrb r1, [r1]
	ldr r0, [r5]
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r5, #4]
	bl PlayerProfile_GetPlayerName_NewString
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02219BC0 ; =0x000F0E00
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #0xc]
	add r0, #0x30
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [r5, #4]
	mov r3, #0x13
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	ldr r1, [r5, #0x1c]
	ldr r2, [r5, #0x18]
	add r0, #0x50
	lsl r3, r3, #4
	bl ov96_02219BDC
	add r0, r4, #0
	bl String_Delete
	add r0, r5, #0
	add r0, #0x30
	bl CopyWindowToVram
	mov r0, #1
	add r2, r5, #0
	str r0, [sp]
	mov r3, #2
	str r3, [sp, #4]
	add r2, #0xb4
	ldr r0, [r5, #0x1c]
	ldr r2, [r2]
	mov r1, #0
	bl BufferString
	ldr r0, [r5, #4]
	mov r3, #0x9a
	str r0, [sp]
	add r0, r5, #0
	ldr r1, [r5, #0x1c]
	ldr r2, [r5, #0x18]
	add r0, #0x40
	bl ov96_02219BC4
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02219BC0: .word 0x000F0E00
	thumb_func_end ov96_02219B30


	thumb_func_start ov96_02219BC4
ov96_02219BC4: ; 0x02219BC4
	push {r3, r4, lr}
	sub sp, #0xc
	ldr r4, [sp, #0x18]
	str r4, [sp]
	mov r4, #0
	str r4, [sp, #4]
	str r4, [sp, #8]
	bl ov96_02219BDC
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02219BC4


	thumb_func_start ov96_02219BDC
ov96_02219BDC: ; 0x02219BDC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	mov r1, #0
	add r5, r0, #0
	add r6, r2, #0
	add r7, r3, #0
	bl FillWindowPixelBuffer
	ldr r3, [sp, #0x28]
	add r0, r4, #0
	add r1, r6, #0
	add r2, r7, #0
	bl ReadMsgData_ExpandPlaceholders
	add r4, r0, #0
	add r3, sp, #0x18
	mov r0, #0x18
	ldrsh r0, [r3, r0]
	mov r1, #0
	mov r6, #0x14
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02219C2C ; =0x000F0E00
	add r2, r4, #0
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrsh r3, [r3, r6]
	add r0, r5, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add r0, r5, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02219C2C: .word 0x000F0E00
	thumb_func_end ov96_02219BDC


	thumb_func_start ov96_02219C30
ov96_02219C30: ; 0x02219C30
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	add r5, r0, #0
	mov r0, #0
	add r2, sp, #0xc
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [r2]
	add r0, r5, #0
	add r0, #0x22
	ldrb r0, [r0]
	mov r2, #0x86
	mov r3, #0xa0
	add r0, #0xc
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	bl ov96_022199A8
	mov r1, #1
	str r0, [r5, #0x60]
	bl ManagedSprite_SetPaletteOverride
	mov r7, #0
	mov r6, #0x78
	add r4, r5, #0
_02219C76:
	lsl r0, r6, #0x10
	asr r0, r0, #0x10
	str r0, [sp, #8]
	add r0, r7, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r2, [sp, #8]
	mov r3, #0x24
	bl ov96_022199A8
	lsl r1, r7, #0x18
	str r0, [r4, #0x68]
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #0
	bl ov96_02219DD0
	mov r0, #0xa
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r2, [sp, #8]
	mov r3, #0x24
	bl ov96_022199A8
	mov r1, #0
	str r0, [r4, #0x78]
	bl ManagedSprite_SetDrawFlag
	mov r0, #6
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	lsl r2, r6, #0x10
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	asr r2, r2, #0x10
	mov r3, #0x18
	bl ov96_022199A8
	add r1, r4, #0
	add r1, #0x88
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r7, r7, #1
	add r6, #0x20
	add r4, r4, #4
	cmp r7, #4
	blt _02219C76
	mov r4, #0
	mov r7, #0x30
	add r6, r5, #0
_02219CF6:
	ldr r0, _02219DA4 ; =0x00002712
	mov r3, #0x1e
	add r0, r4, r0
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	ldr r0, _02219DA4 ; =0x00002712
	mov r1, #0x28
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	mov r0, #2
	str r0, [sp, #0x1c]
	add r0, sp, #0xc
	strh r1, [r0]
	strh r7, [r0, #2]
	add r0, r4, #2
	str r0, [sp, #0x14]
	mov r0, #2
	str r0, [sp, #0x38]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	add r2, sp, #0xc
	lsl r3, r3, #0x10
	bl SpriteSystem_NewSpriteWithYOffset
	add r1, r6, #0
	add r1, #0x98
	str r0, [r1]
	add r0, r6, #0
	add r0, #0x98
	ldr r0, [r0]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r7, #0x58
	add r6, r6, #4
	cmp r4, #2
	blt _02219CF6
	mov r6, #0
	add r4, r5, #0
	mov r7, #0x18
_02219D48:
	mov r0, #2
	sub r0, r0, r6
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	add r3, r5, #0
	add r2, r4, #0
	add r3, #0x22
	add r2, #0x98
	ldrb r3, [r3]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	ldr r2, [r2]
	bl ov96_02219DA8
	mov r0, #5
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	lsl r3, r7, #0x10
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	mov r2, #0x28
	asr r3, r3, #0x10
	bl ov96_022199A8
	add r1, r4, #0
	add r1, #0xa0
	str r0, [r1]
	add r0, r4, #0
	add r0, #0xa0
	ldr r0, [r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r6, r6, #1
	add r4, r4, #4
	add r7, #0x58
	cmp r6, #2
	blt _02219D48
	add r0, r5, #0
	bl ov96_02219E60
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02219DA4: .word 0x00002712
	thumb_func_end ov96_02219C30


	thumb_func_start ov96_02219DA8
ov96_02219DA8: ; 0x02219DA8
	push {r4, r5, lr}
	sub sp, #0x14
	add r4, r2, #0
	add r2, sp, #0x10
	ldrb r2, [r2, #0x10]
	add r5, r1, #0
	add r1, r3, #0
	add r3, sp, #4
	bl ov96_021E6168
	mov r2, #0
	add r0, r4, #0
	add r1, sp, #4
	add r3, r2, #0
	str r5, [sp]
	bl ov96_021EEBE4
	add sp, #0x14
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02219DA8


	thumb_func_start ov96_02219DD0
ov96_02219DD0: ; 0x02219DD0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #2
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r6, [r0, #0x60]
	ldr r0, [r5]
	add r3, sp, #8
	bl ov96_021E6168
	lsl r0, r4, #9
	str r0, [sp]
	ldr r0, [r5, #4]
	add r1, sp, #8
	str r0, [sp, #4]
	ldrh r2, [r5, #0x20]
	ldr r3, [r5, #0x24]
	add r0, r6, #0
	bl ov96_021EECB8
	add sp, #0x18
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_02219DD0


	thumb_func_start ov96_02219E00
ov96_02219E00: ; 0x02219E00
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r6, _02219E5C ; =ov96_0221D944
	add r7, r2, #0
	str r3, [sp]
	add r5, r0, #0
	add r4, r1, #0
	add r3, sp, #4
	mov r2, #6
_02219E12:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02219E12
	ldr r0, [r6]
	cmp r5, #0
	str r0, [r3]
	bne _02219E26
	bl GF_AssertFail
_02219E26:
	cmp r4, #0
	bne _02219E2E
	bl GF_AssertFail
_02219E2E:
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
	mov r1, #1
	add r4, r0, #0
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02219E5C: .word ov96_0221D944
	thumb_func_end ov96_02219E00


	thumb_func_start ov96_02219E60
ov96_02219E60: ; 0x02219E60
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r0, #0
	mov r0, #0x14
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	mov r2, #0x72
	mov r3, #0xb4
	bl ov96_02219E00
	mov r1, #0xe
	str r0, [r6, #0x64]
	bl ManagedSprite_SetPaletteOverride
	mov r7, #0
	add r4, r6, #0
	mov r5, #0x86
_02219E88:
	mov r1, #0
	add r0, sp, #8
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [r6, #0xc]
	bl SpriteManager_GetSpriteList
	add r1, r0, #0
	ldr r0, [r6, #0x10]
	ldr r3, [r6, #4]
	mov r2, #1
	bl ov96_021EA374
	add r1, r4, #0
	add r1, #0xa8
	str r0, [r1]
	lsl r0, r5, #0xc
	str r0, [sp, #8]
	mov r0, #0x2d
	lsl r0, r0, #0xe
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	add r0, r4, #0
	add r0, #0xa8
	ldr r0, [r0]
	add r1, sp, #8
	bl Sprite_SetMatrix
	add r0, r4, #0
	add r0, #0xa8
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	add r7, r7, #1
	add r4, r4, #4
	add r5, #0x10
	cmp r7, #2
	blt _02219E88
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02219E60


	thumb_func_start ov96_02219EE0
ov96_02219EE0: ; 0x02219EE0
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	add r0, r1, #1
	mov r1, #3
	bl _s32_div_f
	lsl r2, r1, #0x18
	mov r0, #1
	lsr r2, r2, #0x16
	add r2, r4, r2
	str r0, [sp]
	mov r3, #2
	str r3, [sp, #4]
	add r2, #0xb0
	ldr r0, [r4, #0x1c]
	ldr r2, [r2]
	mov r1, #0
	bl BufferString
	ldr r0, [r4, #4]
	mov r3, #0x9a
	str r0, [sp]
	add r0, r4, #0
	ldr r1, [r4, #0x1c]
	ldr r2, [r4, #0x18]
	add r0, #0x40
	bl ov96_02219BC4
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02219EE0


	thumb_func_start ov96_02219F20
ov96_02219F20: ; 0x02219F20
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	lsl r6, r1, #2
	add r0, r5, r6
	add r7, r2, #0
	add r4, r3, #0
	mov r3, #0x1e
	ldr r0, [r0, #0x60]
	add r1, r7, #0
	add r2, r4, #0
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add r0, r5, r6
	sub r4, #0x18
	lsl r2, r4, #0x10
	mov r3, #0x1e
	ldr r0, [r0, #0x68]
	add r1, r7, #0
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02219F20


	thumb_func_start ov96_02219F50
ov96_02219F50: ; 0x02219F50
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	bne _02219F5E
	mov r1, #1
	b _02219F60
_02219F5E:
	mov r1, #0
_02219F60:
	add r0, r4, #2
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x60]
	bl ManagedSprite_SetDrawFlag
	add r0, r4, #6
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x60]
	add r1, r6, #0
	bl ManagedSprite_SetDrawFlag
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_02219F50


	thumb_func_start ov96_02219F7C
ov96_02219F7C: ; 0x02219F7C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	str r0, [sp]
	bl PokeathlonCourse_GetParticipantCount
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0x30
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x30
	add r7, r0, #0
	bl MI_CpuFill8
	str r4, [r7]
	ldr r0, [sp]
	mov r4, #0
	str r0, [r7, #4]
	mov r0, #4
	sub r1, r0, r5
	add r0, r7, #0
	add r0, #0x2c
	strb r1, [r0]
	add r0, r7, #0
	add r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #0
	ble _02219FD6
	add r6, r7, #0
	add r6, #8
_02219FBA:
	lsl r1, r5, #0x18
	ldr r2, [sp]
	add r0, r6, #0
	lsr r1, r1, #0x18
	bl ov96_0221A00C
	add r0, r7, #0
	add r0, #0x2c
	ldrb r0, [r0]
	add r4, r4, #1
	add r5, r5, #1
	add r6, #0xc
	cmp r4, r0
	blt _02219FBA
_02219FD6:
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02219F7C

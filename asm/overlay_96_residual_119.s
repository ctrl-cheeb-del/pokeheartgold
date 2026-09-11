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

	thumb_func_start ov96_022186CC
ov96_022186CC: ; 0x022186CC
	push {r3, r4, r5, lr}
	sub sp, #0x18
	ldr r5, _02218740 ; =ov96_0221D6B8
	add r3, r0, #0
	ldmia r5!, {r0, r1}
	add r4, sp, #0xc
	add r2, r4, #0
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add r1, sp, #0
	str r0, [r4]
	mov r4, #0
	str r4, [r1]
	str r4, [r1, #4]
	str r4, [r1, #8]
	ldr r0, [r3, #4]
	str r0, [sp]
	ldr r0, [r3]
	str r0, [sp, #8]
	add r0, r2, #0
	str r4, [sp, #4]
	bl CalcAngleBetweenVecs
	mov r2, #2
	lsl r2, r2, #0xc
	cmp r0, r2
	bls _0221870A
	mov r1, #0xe
	lsl r1, r1, #0xc
	cmp r0, r1
	blo _02218710
_0221870A:
	add sp, #0x18
	mov r0, #4
	pop {r3, r4, r5, pc}
_02218710:
	cmp r0, r2
	bls _02218722
	mov r1, #6
	lsl r1, r1, #0xc
	cmp r0, r1
	bhs _02218722
	add sp, #0x18
	mov r0, #2
	pop {r3, r4, r5, pc}
_02218722:
	mov r1, #6
	lsl r1, r1, #0xc
	cmp r0, r1
	blo _02218738
	mov r1, #0xa
	lsl r1, r1, #0xc
	cmp r0, r1
	bhi _02218738
	add sp, #0x18
	mov r0, #3
	pop {r3, r4, r5, pc}
_02218738:
	mov r0, #1
	add sp, #0x18
	pop {r3, r4, r5, pc}
	nop
_02218740: .word ov96_0221D6B8
	thumb_func_end ov96_022186CC


	thumb_func_start ov96_02218744
ov96_02218744: ; 0x02218744
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bne _0221874E
	bl GF_AssertFail
_0221874E:
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne _02218758
	bl GF_AssertFail
_02218758:
	ldr r5, [r4, #0x14]
	mov r0, #0
	add r2, r0, #0
	add r3, r0, #0
	cmp r5, #0xa
	beq _0221876E
	ldr r1, [r4, #0x60]
	lsl r1, r1, #5
	lsr r1, r1, #0x1f
	bne _0221876E
	mov r3, #1
_0221876E:
	cmp r3, #0
	beq _02218778
	cmp r5, #4
	beq _02218778
	mov r2, #1
_02218778:
	cmp r2, #0
	beq _02218782
	cmp r5, #3
	beq _02218782
	mov r0, #1
_02218782:
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02218744


	thumb_func_start ov96_02218784
ov96_02218784: ; 0x02218784
	push {r4, lr}
	add r4, r1, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	mov r1, #0x62
	lsl r1, r1, #2
	add r1, r0, r1
	lsl r0, r4, #2
	mov r2, #0
	add r1, r1, r0
	add r0, r2, #0
_0221879A:
	add r2, r2, #1
	strb r0, [r1]
	add r1, r1, #1
	cmp r2, #4
	blt _0221879A
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02218784


	thumb_func_start ov96_022187A8
ov96_022187A8: ; 0x022187A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x58
	add r5, r0, #0
	str r1, [sp]
	add r1, r5, #0
	add r0, #0x20
	add r1, #0x2c
	add r2, sp, #0x4c
	bl VEC_Subtract
	add r0, sp, #0x4c
	bl VEC_Mag
	add r7, r0, #0
	cmp r7, #0
	ble _022187CC
	mov r4, #1
	b _022187CE
_022187CC:
	mov r4, #0
_022187CE:
	ldr r0, [r5, #0x60]
	lsl r0, r0, #4
	lsr r0, r0, #0x1f
	beq _02218884
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _022187E0
	bl GF_AssertFail
_022187E0:
	ldr r0, [r5, #0x18]
	cmp r0, #6
	beq _022187EA
	cmp r0, #9
	bne _022187F0
_022187EA:
	mov r6, #1
	lsl r6, r6, #0xc
	b _022187F2
_022187F0:
	ldr r6, _02218928 ; =0x00000B33
_022187F2:
	mov r0, #0x58
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bgt _0221883E
	mov r2, #0
	add r0, sp, #0x10
	str r2, [r0]
	add r1, sp, #0x1c
	str r2, [r0, #4]
	str r2, [r1]
	str r2, [r0, #8]
	add r0, r5, #0
	str r2, [r1, #4]
	add r0, #0x44
	str r2, [r1, #8]
	bl VEC_Normalize
	add r0, r6, #0
	add r1, sp, #0x1c
	add r2, sp, #0x10
	add r3, sp, #0x28
	bl VEC_MultAdd
	ldr r0, [sp, #0x28]
	cmp r0, #0
	bge _02218828
	neg r0, r0
_02218828:
	ldr r2, [sp, #0x2c]
	str r0, [sp, #0x28]
	cmp r2, #0
	bge _02218832
	neg r2, r2
_02218832:
	add r0, r5, #0
	ldr r1, [sp, #0x28]
	add r0, #0x44
	str r2, [sp, #0x2c]
	bl ov96_02215944
_0221883E:
	add r0, r5, #0
	add r0, #0x2c
	add r1, r5, #0
	add r1, #0x44
	add r2, r0, #0
	bl VEC_Add
	add r3, r5, #0
	add r3, #0x2c
	add r2, r5, #0
	ldmia r3!, {r0, r1}
	add r2, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne _02218922
	ldr r0, [r5, #0x48]
	cmp r0, #0
	bne _02218922
	ldr r1, [r5, #0x60]
	ldr r0, [sp]
	lsl r1, r1, #0xa
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02218784
	mov r0, #0
	str r0, [r5, #0x10]
	ldr r1, [r5, #0x60]
	ldr r0, _0221892C ; =0xF7FFFFFF
	and r0, r1
	str r0, [r5, #0x60]
_02218884:
	ldr r0, [r5, #0x60]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	bne _02218922
	mov r0, #0x58
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bgt _02218922
	cmp r4, #0
	beq _02218922
	add r0, sp, #0x4c
	add r1, sp, #0x40
	bl VEC_Normalize
	ldr r0, [r5, #0x60]
	lsl r0, r0, #4
	lsr r0, r0, #0x1f
	bne _022188BC
	add r0, sp, #0x40
	bl ov96_022186CC
	lsl r0, r0, #0x1c
	ldr r2, [r5, #0x60]
	ldr r1, _02218930 ; =0xFFF0FFFF
	lsr r0, r0, #0xc
	and r1, r2
	orr r0, r1
	str r0, [r5, #0x60]
_022188BC:
	ldr r1, [r5, #4]
	ldr r0, [r1, #4]
	ldr r2, [r1, #8]
	mov r1, #0x1e
	lsl r1, r1, #0xc
	ldr r0, [r0, #0xc]
	cmp r2, r1
	bge _022188E6
	asr r1, r0, #0x1f
	lsr r2, r0, #0x15
	lsl r1, r1, #0xb
	lsl r3, r0, #0xb
	mov r0, #2
	orr r1, r2
	mov r2, #0
	lsl r0, r0, #0xa
	add r0, r3, r0
	adc r1, r2
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
_022188E6:
	cmp r7, r0
	bgt _022188F8
	add r3, sp, #0x4c
	ldmia r3!, {r0, r1}
	add r2, sp, #0x34
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	b _0221890A
_022188F8:
	add r2, sp, #4
	mov r1, #0
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [r2, #8]
	add r1, sp, #0x40
	add r3, sp, #0x34
	bl VEC_MultAdd
_0221890A:
	add r0, r5, #0
	add r0, #0x2c
	add r1, sp, #0x34
	add r2, r0, #0
	bl VEC_Add
	add r2, sp, #0x40
	ldmia r2!, {r0, r1}
	add r5, #0x38
	stmia r5!, {r0, r1}
	ldr r0, [r2]
	str r0, [r5]
_02218922:
	add sp, #0x58
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02218928: .word 0x00000B33
_0221892C: .word 0xF7FFFFFF
_02218930: .word 0xFFF0FFFF
	thumb_func_end ov96_022187A8


	thumb_func_start ov96_02218934
ov96_02218934: ; 0x02218934
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	ldr r3, [r0, #0x2c]
	cmp r3, #0
	ble _02218944
	ldr r2, [r0, #0x30]
	cmp r2, #0
	bgt _0221894A
_02218944:
	add sp, #0x3c
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0221894A:
	add r1, sp, #4
	str r1, [sp]
	ldr r0, [r0, #4]
	asr r1, r3, #0xc
	ldr r0, [r0]
	asr r2, r2, #0xc
	add r3, sp, #8
	bl ov96_021EB06C
	ldr r4, [sp, #4]
	cmp r4, #0x40
	blt _02218A46
	cmp r4, #0xa0
	bgt _02218A46
	ldr r0, [sp, #8]
	cmp r0, #0
	ble _0221897E
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0221898C
_0221897E:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0221898C:
	bl _ffix
	add r7, r0, #0
	cmp r4, #0
	ble _022189A8
	lsl r0, r4, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _022189B6
_022189A8:
	lsl r0, r4, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_022189B6:
	bl _ffix
	add r4, r0, #0
	mov r0, #0
	ldr r1, _02218A4C ; =ov96_0221D6D4
	add r2, sp, #0xc
	add r3, r0, #0
	mov r5, #2
_022189C6:
	ldrsh r6, [r1, r3]
	add r0, r0, #1
	lsl r6, r6, #0xc
	str r6, [r2]
	ldrsh r6, [r1, r5]
	add r1, r1, #4
	lsl r6, r6, #0xc
	str r6, [r2, #4]
	add r2, #0xc
	cmp r0, #4
	blt _022189C6
	ldr r5, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	sub r2, r7, r5
	sub r0, r1, r0
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r0, r0, r2
	adc r1, r3
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	ldr r1, [sp, #0x18]
	sub r1, r1, r5
	bl FX_Div
	ldr r1, [sp, #0x10]
	ldr r5, [sp, #0x24]
	add r6, r0, r1
	sub r2, r7, r5
	ldr r1, [sp, #0x34]
	ldr r0, [sp, #0x28]
	asr r3, r2, #0x1f
	sub r0, r1, r0
	asr r1, r0, #0x1f
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r0, r0, r2
	adc r1, r3
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	ldr r1, [sp, #0x30]
	sub r1, r1, r5
	bl FX_Div
	ldr r1, [sp, #0x28]
	add r0, r0, r1
	cmp r4, r6
	blt _02218A46
	cmp r4, r0
	blt _02218A46
	add sp, #0x3c
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_02218A46:
	mov r0, #1
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02218A4C: .word ov96_0221D6D4
	thumb_func_end ov96_02218934

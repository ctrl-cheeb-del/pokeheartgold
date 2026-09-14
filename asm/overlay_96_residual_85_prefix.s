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


	thumb_func_start ov96_022044A0
ov96_022044A0: ; 0x022044A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x94
	str r1, [sp]
	str r2, [sp, #4]
	add r7, r0, #0
	ldr r0, [sp, #4]
	str r3, [sp, #8]
	lsl r0, r0, #2
	str r0, [sp, #0x14]
	bl LCRandom
	mov r1, #0x33
	bl _s32_div_f
	ldr r0, [sp, #0x14]
	ldr r2, [r7, r0]
	mov r0, #0x16
	ldrsh r0, [r2, r0]
	add r0, r0, r1
	cmp r0, #0x78
	bgt _02204564
	ldr r0, [sp, #0x14]
	add r0, r7, r0
	ldr r0, [r0, #0x30]
	add r1, r0, #0
	add r1, #0x44
	ldrh r1, [r1]
	cmp r1, #4
	bhs _02204564
	ldr r1, [r0, #0xc]
	cmp r1, #0
	bne _0220450C
	ldr r1, [sp, #4]
	add r7, #0x30
	lsl r2, r1, #2
	mov r1, #1
	add r0, #0x44
	strh r1, [r0]
	ldr r0, [r7, r2]
	mov r1, #2
	str r1, [r0, #0xc]
	ldr r0, [sp, #4]
	mov r1, #0xc
	mul r1, r0
	ldr r0, _02204718 ; =ov96_0221CA30
	ldr r2, [r7, r2]
	add r3, r0, r1
	ldmia r3!, {r0, r1}
	add r2, #0x10
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add sp, #0x94
	str r0, [r2]
	pop {r4, r5, r6, r7, pc}
_0220450C:
	cmp r1, #2
	beq _02204514
	bl GF_AssertFail
_02204514:
	ldr r0, [sp, #0x14]
	add r7, #0x30
	ldr r1, [r7, r0]
	add r0, r1, #0
	add r0, #0x44
	ldrh r0, [r0]
	add r1, #0x44
	add r0, r0, #1
	strh r0, [r1]
	ldr r0, [sp, #0x14]
	ldr r1, [r7, r0]
	add r0, r1, #0
	add r0, #0x44
	ldrh r0, [r0]
	cmp r0, #1
	bhi _0220453E
	mov r0, #0
	add r1, #0x46
	strh r0, [r1]
	add sp, #0x94
	pop {r4, r5, r6, r7, pc}
_0220453E:
	cmp r0, #2
	bhi _0220454C
	mov r0, #1
	add r1, #0x46
	strh r0, [r1]
	add sp, #0x94
	pop {r4, r5, r6, r7, pc}
_0220454C:
	cmp r0, #3
	bhi _0220455A
	mov r0, #2
	add r1, #0x46
	strh r0, [r1]
	add sp, #0x94
	pop {r4, r5, r6, r7, pc}
_0220455A:
	mov r0, #3
	add r1, #0x46
	strh r0, [r1]
	add sp, #0x94
	pop {r4, r5, r6, r7, pc}
_02204564:
	mov r6, #0
	add r4, r7, #0
	add r5, r7, #0
_0220456A:
	ldr r0, [r4]
	str r0, [r5, #0x60]
	add r0, r5, #0
	add r0, #0x64
	strh r6, [r0]
	bl LCRandom
	str r0, [sp, #0x18]
	ldr r0, [r4]
	mov r1, #0x14
	ldrh r0, [r0, #0x14]
	bl _s32_div_f
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	mov r1, #0x15
	bl _s32_div_f
	ldr r0, [sp, #0x1c]
	add r1, r0, r1
	add r0, r5, #0
	add r0, #0x66
	strh r1, [r0]
	ldr r0, [r4]
	ldrb r0, [r0, #0x19]
	cmp r0, #1
	bne _022045AE
	add r0, r5, #0
	add r0, #0x66
	ldrh r0, [r0]
	add r1, r0, #1
	add r0, r5, #0
	add r0, #0x66
	strh r1, [r0]
_022045AE:
	ldr r1, [r4]
	mov r0, #0x16
	ldrsh r1, [r1, r0]
	mov r0, #0x78
	sub r0, r0, r1
	mov r1, #0x14
	bl _s32_div_f
	add r1, r5, #0
	add r1, #0x66
	ldrh r1, [r1]
	add r6, r6, #1
	add r4, r4, #4
	add r1, r1, r0
	add r0, r5, #0
	add r0, #0x66
	add r5, #8
	strh r1, [r0]
	cmp r6, #0xc
	blt _0220456A
	add r0, r7, #0
	mov r2, #0
	add r0, #0x60
	add r1, sp, #0x64
_022045DE:
	add r2, r2, #1
	stmia r1!, {r0}
	add r0, #8
	cmp r2, #0xc
	blt _022045DE
	ldr r0, [sp]
	add r1, sp, #0x64
	add r2, sp, #0x40
	bl ov96_0220472C
	add r4, r0, #0
	bl LCRandom
	add r1, r4, #0
	bl _s32_div_f
	lsl r2, r1, #0x18
	add r1, sp, #0x28
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r1, [sp, #4]
	lsr r2, r2, #0x16
	add r4, r1, #0
	add r1, sp, #0x40
	ldr r1, [r1, r2]
	mov r3, #0xc
	ldrh r1, [r1, #4]
	ldr r0, _02204718 ; =ov96_0221CA30
	mul r4, r3
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r2, r1, #0
	add r4, r0, r4
	mul r2, r3
	add r0, r0, r2
	add r1, r4, #0
	add r2, sp, #0x34
	bl VEC_Subtract
	add r0, sp, #0x34
	add r1, r0, #0
	bl VEC_Normalize
	mov r0, #3
	add r1, sp, #0x34
	bl ov96_02204320
	ldr r0, [sp, #4]
	add r1, sp, #0x34
	lsl r5, r0, #2
	ldr r0, [r7, r5]
	ldr r0, [r0, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl ov96_02204320
	bl LCRandom
	add r6, r0, #0
	ldr r0, [sp, #8]
	bl _fflt
	bl _f2d
	ldr r3, _0220471C ; =0x40440000
	mov r2, #0
	bl _ddiv
	str r1, [sp, #0x10]
	str r0, [sp, #0x20]
	ldr r1, [r7, r5]
	mov r0, #0x16
	ldrsh r0, [r1, r0]
	bl _fflt
	bl _f2d
	ldr r3, _02204720 ; =0x40490000
	mov r2, #0
	bl _ddiv
	str r0, [sp, #0x24]
	add r5, r1, #0
	add r0, r6, #0
	mov r1, #0x33
	bl _s32_div_f
	add r0, r1, #0
	bl _fflt
	bl _f2d
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x24]
	add r1, r5, #0
	bl _dadd
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x10]
	bl _dadd
	bl _d2f
	add r5, r0, #0
	bl _f2d
	mov r3, #1
	mov r2, #0
	lsl r3, r3, #0x1e
	bl _dgr
	bls _022046CE
	mov r5, #1
	lsl r5, r5, #0x1e
	b _022046E2
_022046CE:
	add r0, r5, #0
	bl _f2d
	ldr r3, _02204724 ; =0x3FF00000
	mov r2, #0
	bl _dls
	bhs _022046E2
	mov r5, #0xfe
	lsl r5, r5, #0x16
_022046E2:
	ldr r0, _02204728 ; =0x45800000
	add r1, r5, #0
	add r7, #0x30
	bl _fmul
	bl _ffix
	ldr r3, [sp, #0x14]
	add r1, sp, #0x34
	ldr r3, [r7, r3]
	add r2, sp, #0x28
	add r3, #0x1c
	bl VEC_MultAdd
	ldr r0, [sp, #0x14]
	mov r1, #1
	ldr r0, [r7, r0]
	str r1, [r0, #0xc]
	ldr r0, [sp, #0x14]
	ldr r2, [r7, r0]
	ldmia r4!, {r0, r1}
	add r2, #0x10
	stmia r2!, {r0, r1}
	ldr r0, [r4]
	str r0, [r2]
	add sp, #0x94
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02204718: .word ov96_0221CA30
_0220471C: .word 0x40440000
_02204720: .word 0x40490000
_02204724: .word 0x3FF00000
_02204728: .word 0x45800000
	thumb_func_end ov96_022044A0

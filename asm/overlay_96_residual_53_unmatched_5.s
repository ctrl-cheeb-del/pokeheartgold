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


	thumb_func_start ov96_021F234C
ov96_021F234C: ; 0x021F234C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x198
	mov r5, #0
	add r6, r0, #0
	str r0, [sp]
	str r5, [sp, #0x14]
	add r7, sp, #0x70
	add r6, #0x20
_021F236A:
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x1b
	lsl r0, r0, #4
	mul r0, r4
	add r2, r6, r0
	mov r0, #0x90
	mul r0, r1
	add r1, r2, r0
	add r0, r1, #0
	add r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	beq _021F23A8
	ldr r0, [r1, #0x18]
	cmp r0, #1
	bne _021F23A8
	ldr r0, [sp, #0x14]
	add r2, r0, #0
	add r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	str r2, [sp, #0x14]
	strb r5, [r7, r0]
_021F23A8:
	mov r2, #0xc
	add r0, r1, #0
	add r3, r5, #0
	mul r3, r2
	add r2, sp, #0x7c
	add r0, #0x1c
	add r1, #0x28
	add r2, r2, r3
	bl VEC_Subtract
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #0xc
	blo _021F236A
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bne _021F23CE
	b _021F276E
_021F23CE:
	mov r2, #0x1b
	mov r0, #0
	add r1, sp, #0x10c
	lsl r2, r2, #6
	bl MIi_CpuClear32
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bhi _021F23E6
	b _021F25D4
_021F23E6:
	ldr r1, _021F26AC ; =FX_SinCosTable_ + 0x800
	mov r0, #2
	ldrsh r0, [r1, r0]
	str r0, [sp, #0xc]
_021F23EE:
	ldr r0, [sp, #0x10]
	add r1, sp, #0x70
	ldrb r7, [r1, r0]
	ldr r0, _021F26B0 ; =0x000007CC
	mov r1, #0
	mov r2, #0x7b
	str r1, [sp, #0x60]
	add r0, sp
	lsl r2, r2, #4
	bl MI_CpuFill8
	ldr r0, [sp, #0x10]
	mov r1, #0x90
	mul r1, r0
	add r2, sp, #0x10c
	add r4, r2, r1
	ldr r1, _021F26B0 ; =0x000007CC
	mov r5, #0
	add r1, sp
	mov r6, #0xc
	mov r0, #0xa4
_021F2418:
	add r2, r5, #0
	mul r2, r6
	add r3, r4, r2
	add r2, r5, #0
	mul r2, r0
	str r3, [r1, r2]
	add r2, r5, #1
	lsl r2, r2, #0x18
	lsr r5, r2, #0x18
	cmp r5, #0xc
	blo _021F2418
	add r0, sp, #0x64
	mov r1, #0
	mov r2, #0xc
	bl MI_CpuFill8
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	add r4, r0, #0
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x1b
	lsl r0, r0, #4
	add r3, r4, #0
	mul r3, r0
	mov r0, #0x90
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp]
	mov r5, #1
	add r0, r0, r3
	add r3, r2, r0
	add r3, #0x54
	add r2, sp, #0x48
	ldmia r3!, {r0, r1}
	str r2, [sp, #0x18]
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [sp]
	str r0, [sp, #0x20]
	add r0, #0x48
	str r0, [sp, #0x20]
_021F2476:
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	add r4, r0, #0
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x1b
	lsl r0, r0, #4
	add r2, r4, #0
	mul r2, r0
	ldr r0, [sp, #0x20]
	add r0, r0, r2
	str r0, [sp, #0x1c]
	mov r0, #0x90
	mul r0, r1
	str r0, [sp, #0x24]
	mov r1, #1
	add r0, sp, #0x64
	strb r1, [r0, r7]
	cmp r5, #0
	beq _021F2532
	mov r0, #0xa4
	add r1, r7, #0
	mul r1, r0
	ldr r0, _021F26B0 ; =0x000007CC
	add r0, sp
	add r4, r0, r1
	mov r0, #0
	strh r0, [r4, #0x10]
	add r6, r4, #0
	strh r0, [r4, #0x12]
	add r5, r0, #0
	mov r0, #0xc0
	add r1, r7, #0
	mul r1, r0
	ldr r0, _021F26B4 ; =_0221DCA0
	add r6, #0x10
	add r0, r0, r1
	str r0, [sp, #8]
_021F24CA:
	ldr r1, [sp, #8]
	lsl r0, r5, #4
	ldr r2, [sp, #8]
	add r1, r1, r0
	ldr r0, [r2, r0]
	cmp r0, #0
	beq _021F2514
	ldr r0, [r1, #8]
	ldr r2, [sp, #0x1c]
	ldr r1, [sp, #0x24]
	add r0, #0x28
	add r1, r2, r1
	add r2, sp, #0x3c
	bl VEC_Subtract
	ldr r0, [sp, #0x18]
	add r1, sp, #0x3c
	bl VEC_DotProduct
	cmp r0, #0
	ble _021F2514
	ldrh r0, [r4, #0x10]
	add r3, sp, #0x3c
	add r0, r4, r0
	strb r5, [r0, #4]
	ldrh r1, [r4, #0x10]
	mov r0, #0xc
	mul r0, r1
	add r2, r4, r0
	ldmia r3!, {r0, r1}
	add r2, #0x14
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldrh r0, [r6]
	add r0, r0, #1
	strh r0, [r6]
_021F2514:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #0xc
	blo _021F24CA
	mov r0, #0xa4
	add r1, r7, #0
	mul r1, r0
	ldr r0, _021F26B0 ; =0x000007CC
	add r0, sp
	ldr r0, [r0, r1]
	ldr r1, [sp, #0x18]
	add r2, r0, #0
	bl VEC_Add
_021F2532:
	mov r0, #0xa4
	add r1, r7, #0
	mul r1, r0
	ldr r0, _021F26B0 ; =0x000007CC
	mov r5, #0
	add r0, sp
	add r4, r0, r1
	ldrh r0, [r4, #0x12]
	ldrh r1, [r4, #0x10]
	cmp r0, r1
	blo _021F2558
	add r1, r5, #0
	add r0, sp, #0x64
	strb r1, [r0, r7]
	add r0, sp, #0x54
	bl ov96_021F27A8
	add r7, r0, #0
	b _021F25BC
_021F2558:
	add r1, r4, r0
	ldrb r2, [r1, #4]
	add r1, sp, #0x64
	ldrb r1, [r1, r2]
	cmp r1, #0
	beq _021F256A
	add r0, r0, #1
	strh r0, [r4, #0x12]
	b _021F25BC
_021F256A:
	add r0, sp, #0x54
	add r1, r7, #0
	bl ov96_021F2780
	cmp r0, #0xff
	beq _021F25C2
	ldrh r2, [r4, #0x12]
	add r3, r4, #0
	mov r1, #0xc
	ldr r0, [r4]
	add r3, #0x14
	mul r1, r2
	add r1, r3, r1
	bl ov96_021F2814
	ldr r1, [sp, #0xc]
	cmp r0, r1
	blt _021F259C
	ldr r3, [r4]
	add r2, sp, #0x48
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	b _021F25B0
_021F259C:
	ldrh r2, [r4, #0x12]
	add r3, r4, #0
	mov r1, #0xc
	mul r1, r2
	add r3, #0x14
	ldr r0, [r4]
	ldr r2, [sp, #0x18]
	add r1, r3, r1
	bl ov96_021F27B8
_021F25B0:
	ldrh r1, [r4, #0x12]
	mov r5, #1
	add r0, r1, #1
	strh r0, [r4, #0x12]
	add r0, r4, r1
	ldrb r7, [r0, #4]
_021F25BC:
	cmp r7, #0xff
	beq _021F25C2
	b _021F2476
_021F25C2:
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	cmp r1, r0
	bhs _021F25D4
	b _021F23EE
_021F25D4:
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bhi _021F25E0
	b _021F2704
_021F25E0:
	ldr r0, [sp, #4]
	mov r1, #0x90
	mul r1, r0
	ldr r0, [sp]
	add r2, sp, #0x10c
	str r0, [sp, #0x28]
	add r0, #0x20
	mov r5, #0
	add r7, r2, r1
	str r0, [sp, #0x28]
_021F25F4:
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x1b
	lsl r0, r0, #4
	add r2, r4, #0
	mul r2, r0
	ldr r0, [sp, #0x28]
	add r6, r1, #0
	add r4, r0, r2
	mov r0, #0x90
	mul r6, r0
	mov r0, #0xc
	mul r0, r5
	str r0, [sp, #0x2c]
	add r0, r4, r6
	ldr r1, [sp, #0x2c]
	add r0, #0x28
	add r1, r7, r1
	add r2, r0, #0
	bl VEC_Add
	ldr r0, [sp, #0x2c]
	add r0, r7, r0
	bl VEC_Mag
	cmp r0, #0
	beq _021F2652
	add r0, r4, r6
	add r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	bne _021F2652
	add r2, r4, r6
	add r2, #0x28
	add r3, r4, r6
	ldmia r2!, {r0, r1}
	add r3, #0x1c
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
_021F2652:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #0xc
	blo _021F25F4
	ldr r0, [sp, #4]
	add r1, sp, #0x70
	ldrb r4, [r1, r0]
	mov r1, #3
	add r0, r4, #0
	bl _s32_div_f
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	ldr r2, [sp]
	mov r0, #0x1b
	lsl r0, r0, #4
	add r2, #0x20
	mul r0, r5
	add r2, r2, r0
	mov r0, #0x90
	mul r0, r1
	add r5, r2, r0
	add r0, r5, #0
	add r0, #0x8e
	ldrh r0, [r0]
	cmp r0, #0
	bne _021F26F2
	mov r1, #0x72
	mov r3, #0
	lsl r1, r1, #4
_021F2696:
	ldr r0, [sp]
	add r2, r0, r3
	ldrb r0, [r2, r1]
	cmp r4, r0
	bne _021F26B8
	mov r0, #0x72
	mov r1, #0xc
	lsl r0, r0, #4
	strb r1, [r2, r0]
	b _021F26BE
	nop
_021F26AC: .word FX_SinCosTable_ + 0x800
_021F26B0: .word 0x000007CC
_021F26B4: .word _0221DCA0
_021F26B8:
	add r3, r3, #1
	cmp r3, #4
	blt _021F2696
_021F26BE:
	ldr r0, [r5, #0x18]
	cmp r0, #1
	beq _021F26C8
	bl GF_AssertFail
_021F26C8:
	add r0, r5, #0
	mov r1, #1
	add r0, #0x44
	strb r1, [r0]
	add r0, r5, #0
	add r3, r5, #0
	add r2, r5, #0
	mov r1, #0x3c
	add r0, #0x45
	add r3, #0x28
	strb r1, [r0]
	ldmia r3!, {r0, r1}
	add r2, #0x1c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	mov r0, #0
	str r0, [r5, #0x34]
	str r0, [r5, #0x38]
	add r5, #0x41
	strb r0, [r5]
_021F26F2:
	ldr r0, [sp, #4]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	str r1, [sp, #4]
	ldr r0, [sp, #0x14]
	cmp r1, r0
	bhs _021F2704
	b _021F25E0
_021F2704:
	ldr r0, [sp]
	mov r5, #0
	add r0, #0x20
	str r0, [sp]
	add r7, sp, #0x30
_021F270E:
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x1b
	lsl r0, r0, #4
	add r2, r4, #0
	mul r2, r0
	ldr r0, [sp]
	add r6, r1, #0
	add r4, r0, r2
	mov r0, #0x90
	mul r6, r0
	add r0, r4, r6
	add r1, r4, r6
	add r0, #0x1c
	add r1, #0x28
	add r2, r7, #0
	bl VEC_Subtract
	mov r0, #0xc
	add r1, r5, #0
	mul r1, r0
	add r0, sp, #0x7c
	add r0, r0, r1
	add r1, r7, #0
	bl VEC_DotProduct
	cmp r0, #0
	bge _021F2764
	add r2, r4, r6
	add r2, #0x28
	add r3, r4, r6
	ldmia r2!, {r0, r1}
	add r3, #0x1c
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
_021F2764:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #0xc
	blo _021F270E
_021F276E:
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x198
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F234C

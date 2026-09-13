	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text
	.public ov96_02203468
	.public ov96_02203544

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

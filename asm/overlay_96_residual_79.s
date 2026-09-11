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

	thumb_func_start ov96_021FE550
ov96_021FE550: ; 0x021FE550
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x88
	str r0, [sp, #0x18]
	add r0, r3, #0
	add r0, #0xf0
	str r1, [sp, #0x1c]
	add r5, r2, #0
	str r3, [sp, #0x20]
	bl ov96_021E8A20
	str r0, [sp, #0x58]
	ldr r0, [sp, #0x18]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x5c]
	ldr r0, [sp, #0x1c]
	lsl r1, r0, #1
	ldr r0, [sp, #0x58]
	ldrh r0, [r0, r1]
	add r1, sp, #0x7c
	str r0, [sp, #0x60]
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [sp, #0x58]
	ldr r0, [r0, #0x14]
	asr r1, r0, #0x19
	mov r0, #1
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _021FE64E
	ldr r0, [sp, #0x58]
	ldrh r1, [r0, #0x1a]
	ldr r0, [sp, #0x60]
	sub r4, r0, r1
	add r0, r4, #0
	bl _dflt
	ldr r3, _021FE8C4 ; =0x40880000
	mov r2, #0
	bl _dgeq
	blo _021FE5D0
	add r0, r4, #0
	bl _dflt
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FE8C8 ; =0x40900000
	mov r0, #0
	bl _dsub
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FE8CC ; =0x40540000
	mov r0, #0
	bl _dadd
	bl _dfix
	add r4, r0, #0
	b _021FE5D4
_021FE5D0:
	mov r0, #0x50
	sub r4, r0, r4
_021FE5D4:
	lsl r0, r4, #0xc
	str r0, [sp, #0x7c]
	ldr r0, [sp, #0x58]
	ldr r1, _021FE8D0 ; =0x000003C3
	ldrb r0, [r0, #0x1c]
	lsl r0, r0, #0xc
	str r0, [sp, #0x80]
	ldr r0, [sp, #0x5c]
	ldrb r0, [r0, r1]
	add r1, #9
	lsl r2, r0, #2
	ldr r0, [sp, #0x5c]
	add r0, r0, r2
	ldr r0, [r0, r1]
	add r1, sp, #0x7c
	bl ov96_021EB588
	ldr r1, _021FE8D0 ; =0x000003C3
	ldr r0, [sp, #0x5c]
	ldrb r0, [r0, r1]
	add r1, #9
	lsl r2, r0, #2
	ldr r0, [sp, #0x5c]
	add r0, r0, r2
	ldr r0, [r0, r1]
	mov r1, #1
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r1, _021FE8D0 ; =0x000003C3
	ldr r0, [sp, #0x5c]
	ldrb r0, [r0, r1]
	add r1, #9
	lsl r2, r0, #2
	ldr r0, [sp, #0x5c]
	add r0, r0, r2
	ldr r0, [r0, r1]
	mov r1, #9
	bl ov96_021EB564
	ldr r0, _021FE8D0 ; =0x000003C3
	ldr r1, [sp, #0x5c]
	mov r2, #0x1e
	ldrb r1, [r1, r0]
	add r1, r1, #1
	lsr r3, r1, #0x1f
	lsl r1, r1, #0x1e
	sub r1, r1, r3
	ror r1, r2
	add r3, r3, r1
	ldr r1, [sp, #0x5c]
	cmp r4, #0
	strb r3, [r1, r0]
	blt _021FE64E
	add r2, #0xe2
	cmp r4, r2
	bge _021FE64E
	ldr r0, _021FE8D4 ; =0x000008A3
	mov r1, #5
	bl sub_0200606C
_021FE64E:
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	bne _021FE65A
	mov r0, #1
	str r0, [sp, #0x28]
	b _021FE65E
_021FE65A:
	mov r0, #0
	str r0, [sp, #0x28]
_021FE65E:
	mov r0, #0
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x3c]
	add r0, #0x50
	str r0, [sp, #0x3c]
_021FE672:
	ldr r1, [sp, #0x1c]
	ldr r0, [sp, #0x30]
	cmp r1, r0
	bne _021FE680
	mov r0, #1
	str r0, [sp, #0x24]
	b _021FE684
_021FE680:
	mov r0, #0
	str r0, [sp, #0x24]
_021FE684:
	ldr r1, [sp, #0x58]
	ldr r0, [sp, #0x30]
	add r0, r1, r0
	str r0, [sp, #0x2c]
	ldrb r0, [r0, #0xc]
	mov r1, #3
	str r0, [sp, #0x38]
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x44]
	ldrh r4, [r0]
	ldr r0, [sp, #0x60]
	sub r6, r4, r0
	bl _dflt
	ldr r3, _021FE8D8 ; =0x4086A000
	mov r2, #0
	bl _dgr
	bls _021FE6E8
	mov r0, #0x4b
	lsl r0, r0, #2
	cmp r4, r0
	bhs _021FE738
	ldr r0, [sp, #0x60]
	bl _dflt
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FE8C8 ; =0x40900000
	mov r0, #0
	bl _dsub
	add r7, r0, #0
	add r6, r1, #0
	add r0, r4, #0
	bl _dfltu
	add r2, r0, #0
	add r3, r1, #0
	add r0, r7, #0
	add r1, r6, #0
	bl _dadd
	bl _dfix
	add r6, r0, #0
	b _021FE738
_021FE6E8:
	ldr r0, [sp, #0x60]
	cmp r0, #0x64
	bge _021FE738
	add r0, r4, #0
	bl _dfltu
	ldr r3, _021FE8DC ; =0x408CE000
	mov r2, #0
	bl _dgr
	bls _021FE738
	ldr r0, [sp, #0x60]
	bl _dflt
	add r7, r0, #0
	add r0, r4, #0
	add r6, r1, #0
	bl _dfltu
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FE8C8 ; =0x40900000
	mov r0, #0
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	add r0, r7, #0
	add r1, r6, #0
	bl _dadd
	add r2, r0, #0
	mov r0, #0
	add r3, r1, #0
	add r1, r0, #0
	bl _dsub
	bl _dfix
	add r6, r0, #0
_021FE738:
	ldr r1, [sp, #0x58]
	ldr r0, [sp, #0x30]
	add r6, #0x50
	add r1, r1, r0
	ldrb r0, [r1, #0x10]
	asr r2, r0, #7
	mov r0, #1
	and r0, r2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x58]
	ldr r3, [sp, #0x34]
	ldr r2, [sp, #0x40]
	ldr r0, [r0, #0x14]
	add r2, r3, r2
	lsl r2, r2, #0x18
	lsr r2, r2, #0x17
	asr r0, r2
	mov r2, #3
	and r0, r2
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x38]
	asr r0, r0, #2
	and r0, r2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x4c]
	ldr r0, [sp, #0x34]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	str r0, [sp, #0x54]
	lsl r0, r6, #0xc
	str r0, [sp, #0x70]
	ldrb r0, [r1, #8]
	lsl r0, r0, #0xc
	str r0, [sp, #0x74]
	mov r0, #0
	str r0, [sp, #0x78]
	ldr r0, [sp, #0x18]
	bl PokeathlonCourse_GetParticipantCount
	ldr r1, [sp, #0x30]
	cmp r0, r1
	bgt _021FE79C
	ldr r0, [sp, #0x3c]
	mov r4, #1
	bl ov96_021E8A20
	b _021FE7A4
_021FE79C:
	ldr r0, [sp, #0x20]
	mov r4, #0
	bl ov96_021E8A20
_021FE7A4:
	ldr r2, [sp, #0x1c]
	ldr r1, [sp, #0x30]
	cmp r2, r1
	add r2, sp, #0x70
	bne _021FE7D8
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp]
	ldr r1, [sp, #0x34]
	ldr r3, [sp, #0x58]
	str r1, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [sp, #0x28]
	mov r1, #0x3e
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x5c]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	add r1, r5, #0
	bl ov96_021FEECC
	b _021FE7FE
_021FE7D8:
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp]
	ldr r1, [sp, #0x34]
	ldr r3, [sp, #0x58]
	str r1, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [sp, #0x28]
	mov r1, #0x3e
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x5c]
	str r4, [sp, #0x14]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	add r1, r5, #0
	bl ov96_021FEECC
_021FE7FE:
	ldr r0, [sp, #0x48]
	mov r1, #0x3e
	str r0, [sp]
	ldr r0, [sp, #0x5c]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	lsl r1, r1, #0x18
	ldr r3, [sp, #0x50]
	lsr r1, r1, #0x18
	bl ov96_02200950
	add r0, r5, #0
	add r0, #0xc8
	ldr r0, [r0]
	cmp r0, #0
	bne _021FE83C
	mov r0, #0x1f
	mvn r0, r0
	cmp r6, r0
	blt _021FE83C
	mov r0, #0x12
	lsl r0, r0, #4
	cmp r6, r0
	bgt _021FE83C
	ldr r0, [sp, #0x54]
	mov r1, #1
	bl ov96_021EAB38
	b _021FE844
_021FE83C:
	ldr r0, [sp, #0x54]
	mov r1, #0
	bl ov96_021EAB38
_021FE844:
	mov r7, #0
	add r4, r5, #0
_021FE848:
	ldr r2, [sp, #0x2c]
	ldr r0, [r4]
	ldrb r2, [r2, #8]
	add r1, r6, #0
	bl ov96_021EAF94
	add r7, r7, #1
	add r4, r4, #4
	cmp r7, #3
	blt _021FE848
	ldr r0, [sp, #0x18]
	bl ov96_021E5F24
	ldr r1, [sp, #0x30]
	cmp r1, r0
	bne _021FE86C
	mov r2, #1
	b _021FE86E
_021FE86C:
	mov r2, #0
_021FE86E:
	ldr r1, [sp, #0x2c]
	add r0, r5, #0
	ldrb r1, [r1, #8]
	bl ov96_021FFB7C
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	bl ov96_021E60C0
	ldr r2, [r5, #0x6c]
	add r1, sp, #0x70
	bl ov96_021FFAEC
	add r4, sp, #0x70
	add r3, sp, #0x64
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	str r0, [r3]
	mov r0, #6
	ldr r1, [sp, #0x68]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #0x68]
	ldr r0, [r5, #0x78]
	add r1, r2, #0
	bl ov96_021EB588
	ldr r0, [sp, #0x50]
	cmp r0, #0
	beq _021FE8B2
	b _021FEA44
_021FE8B2:
	ldr r0, [sp, #0x4c]
	mov r4, #0
	add r7, r4, #0
	cmp r0, #2
	beq _021FE8E0
	cmp r0, #3
	beq _021FE938
	b _021FE990
	nop
_021FE8C4: .word 0x40880000
_021FE8C8: .word 0x40900000
_021FE8CC: .word 0x40540000
_021FE8D0: .word 0x000003C3
_021FE8D4: .word 0x000008A3
_021FE8D8: .word 0x4086A000
_021FE8DC: .word 0x408CE000
_021FE8E0:
	add r0, r5, #0
	add r0, #0xa7
	ldrb r1, [r0]
	ldr r0, [sp, #0x4c]
	cmp r0, r1
	beq _021FE8FE
	mov r1, #1
	ldr r0, [r5, #0x78]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x78]
	mov r1, #4
	bl ov96_021EB564
_021FE8FE:
	ldr r0, [sp, #0x54]
	mov r1, #8
	bl ov96_021EAC5C
	add r0, r5, #0
	add r0, #0xd2
	ldrb r0, [r0]
	mov r4, #1
	cmp r0, #1
	bhi _021FE9AA
	add r0, r5, #0
	add r0, #0xd3
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FE9AA
	ldr r1, _021FEAE8 ; =0x000008A7
	ldr r2, [sp, #0x24]
	add r0, r6, #0
	bl ov96_021FFE38
	add r0, r5, #0
	mov r1, #2
	add r0, #0xd2
	strb r1, [r0]
	add r0, r5, #0
	add r1, r4, #0
	add r0, #0xd3
	strb r1, [r0]
	b _021FE9AA
_021FE938:
	add r0, r5, #0
	add r0, #0xa7
	ldrb r1, [r0]
	ldr r0, [sp, #0x4c]
	cmp r0, r1
	beq _021FE956
	mov r1, #1
	ldr r0, [r5, #0x78]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x78]
	mov r1, #5
	bl ov96_021EB564
_021FE956:
	ldr r0, [sp, #0x54]
	mov r1, #8
	bl ov96_021EAC5C
	add r0, r5, #0
	add r0, #0xd2
	ldrb r0, [r0]
	mov r4, #1
	cmp r0, #1
	bhi _021FE9AA
	add r0, r5, #0
	add r0, #0xd3
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FE9AA
	ldr r1, _021FEAE8 ; =0x000008A7
	ldr r2, [sp, #0x24]
	add r0, r6, #0
	bl ov96_021FFE38
	add r0, r5, #0
	mov r1, #3
	add r0, #0xd2
	strb r1, [r0]
	add r0, r5, #0
	add r1, r4, #0
	add r0, #0xd3
	strb r1, [r0]
	b _021FE9AA
_021FE990:
	ldr r0, [r5, #0x78]
	mov r1, #1
	add r2, r4, #0
	bl ov96_021EB52C
	add r1, r5, #0
	ldr r0, [sp, #0x4c]
	add r1, #0xd2
	strb r0, [r1]
	add r0, r5, #0
	add r1, r4, #0
	add r0, #0xd3
	strb r1, [r0]
_021FE9AA:
	ldr r0, [sp, #0x48]
	cmp r0, #1
	beq _021FE9B6
	cmp r0, #2
	beq _021FE9CA
	b _021FEA28
_021FE9B6:
	mov r1, #1
	ldr r0, [r5, #0x6c]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x6c]
	mov r1, #6
	bl ov96_021EB570
	b _021FEA32
_021FE9CA:
	add r0, r5, #0
	add r0, #0xa6
	ldrb r1, [r0]
	ldr r0, [sp, #0x48]
	cmp r0, r1
	beq _021FE9E8
	mov r1, #1
	ldr r0, [r5, #0x6c]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x6c]
	mov r1, #7
	bl ov96_021EB564
_021FE9E8:
	ldr r0, [sp, #0x54]
	mov r1, #0x15
	bl ov96_021EAC5C
	ldr r0, [sp, #0x24]
	mov r7, #1
	cmp r0, #0
	beq _021FEA10
	mov r0, #3
	bl sub_02006190
	cmp r0, #0
	bne _021FEA32
	mov r1, #0x89
	ldr r2, [sp, #0x24]
	add r0, r6, #0
	lsl r1, r1, #4
	bl ov96_021FFE38
	b _021FEA32
_021FEA10:
	mov r0, #4
	bl sub_02006190
	cmp r0, #0
	bne _021FEA32
	mov r1, #0x89
	ldr r2, [sp, #0x24]
	add r0, r6, #0
	lsl r1, r1, #4
	bl ov96_021FFE38
	b _021FEA32
_021FEA28:
	ldr r0, [r5, #0x6c]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_021FEA32:
	cmp r4, #0
	bne _021FEA58
	cmp r7, #0
	bne _021FEA58
	ldr r0, [sp, #0x54]
	mov r1, #0
	bl ov96_021EAC5C
	b _021FEA58
_021FEA44:
	ldr r0, [r5, #0x78]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x6c]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_021FEA58:
	add r1, r5, #0
	ldr r0, [sp, #0x4c]
	add r1, #0xa7
	strb r0, [r1]
	add r1, r5, #0
	ldr r0, [sp, #0x48]
	add r1, #0xa6
	strb r0, [r1]
	ldr r0, [sp, #0x44]
	add r5, #0xd4
	add r0, r0, #2
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x40]
	add r0, r0, #3
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x3c]
	add r0, #0x28
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x30]
	add r0, r0, #1
	str r0, [sp, #0x30]
	cmp r0, #4
	bge _021FEA88
	b _021FE672
_021FEA88:
	mov r1, #0x3e
	ldr r0, [sp, #0x5c]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	mov r1, #0
	bl ov96_02200BC8
	add r4, r0, #0
	mov r1, #0x3e
	ldr r0, [sp, #0x5c]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	mov r1, #1
	bl ov96_02200BC8
	add r6, r0, #0
	ldr r0, [sp, #0x58]
	mov r2, #3
	ldr r5, [r0, #0x14]
	ldr r0, [sp, #0x1c]
	lsl r1, r0, #1
	add r3, r0, r1
	mov r1, #0x3e
	ldr r0, [sp, #0x5c]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	add r1, r4, r3
	lsl r1, r1, #0x18
	add r3, r6, r3
	lsl r3, r3, #0x18
	lsr r1, r1, #0x17
	add r4, r5, #0
	asr r4, r1
	add r1, r4, #0
	and r1, r2
	lsl r1, r1, #0x18
	lsr r3, r3, #0x17
	add r4, r5, #0
	asr r4, r3
	and r2, r4
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_02200A18
	add sp, #0x88
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FEAE8: .word 0x000008A7
	thumb_func_end ov96_021FE550


	thumb_func_start ov96_021FEAEC
ov96_021FEAEC: ; 0x021FEAEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r0, [sp]
	str r1, [sp, #4]
	mov r6, #0
_021FEAF6:
	mov r0, #0xc
	add r1, r6, #0
	mul r1, r0
	ldr r0, [sp]
	add r4, r0, r1
	ldr r0, _021FEBD4 ; =0x000004D4
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021FEBD0
	ldr r0, _021FEBD8 ; =0x000004DE
	ldrb r7, [r4, r0]
	sub r0, r0, #2
	ldrh r1, [r4, r0]
	ldr r0, [sp, #4]
	sub r5, r0, r1
	add r0, r5, #0
	bl _dflt
	ldr r3, _021FEBDC ; =0x40880000
	mov r2, #0
	bl _dgeq
	blo _021FEB4A
	add r0, r5, #0
	bl _dflt
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FEBE0 ; =0x40900000
	mov r0, #0
	bl _dsub
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FEBE4 ; =0x40540000
	mov r0, #0
	bl _dadd
	bl _dfix
	add r5, r0, #0
	b _021FEB84
_021FEB4A:
	add r0, r5, #0
	bl _dflt
	ldr r3, _021FEBE8 ; =0xC0880000
	mov r2, #0
	bl _dleq
	bhi _021FEB80
	add r0, r5, #0
	bl _dflt
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FEBE0 ; =0x40900000
	mov r0, #0
	bl _dadd
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FEBE4 ; =0x40540000
	mov r0, #0
	bl _dsub
	bl _dfix
	add r5, r0, #0
	b _021FEB84
_021FEB80:
	mov r0, #0x50
	sub r5, r0, r5
_021FEB84:
	mov r0, #0
	str r0, [sp, #0x10]
	lsl r0, r5, #0xc
	add r7, #0x20
	str r0, [sp, #8]
	lsl r0, r7, #0xc
	str r0, [sp, #0xc]
	ldr r0, _021FEBEC ; =0x000004D8
	add r1, sp, #8
	ldr r0, [r4, r0]
	bl ov96_021EB588
	mov r0, #0x1f
	mvn r0, r0
	cmp r5, r0
	blt _021FEBBA
	mov r0, #0x12
	lsl r0, r0, #4
	cmp r5, r0
	bgt _021FEBBA
	ldr r0, _021FEBEC ; =0x000004D8
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	b _021FEBC6
_021FEBBA:
	ldr r0, _021FEBEC ; =0x000004D8
	mov r1, #1
	ldr r0, [r4, r0]
	mov r2, #0
	bl ov96_021EB52C
_021FEBC6:
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #0x1e
	blo _021FEAF6
_021FEBD0:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FEBD4: .word 0x000004D4
_021FEBD8: .word 0x000004DE
_021FEBDC: .word 0x40880000
_021FEBE0: .word 0x40900000
_021FEBE4: .word 0x40540000
_021FEBE8: .word 0xC0880000
_021FEBEC: .word 0x000004D8
	thumb_func_end ov96_021FEAEC


	thumb_func_start ov96_021FEBF0
ov96_021FEBF0: ; 0x021FEBF0
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r4, r1, #0
	add r1, #0xa0
	ldrb r1, [r1]
	add r5, r2, #0
	ldr r6, [sp, #0x24]
	cmp r1, #3
	bls _021FEC04
	b _021FED34
_021FEC04:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021FEC10: ; jump table
	.short _021FEC18 - _021FEC10 - 2 ; case 0
	.short _021FEC84 - _021FEC10 - 2 ; case 1
	.short _021FECDE - _021FEC10 - 2 ; case 2
	.short _021FED34 - _021FEC10 - 2 ; case 3
_021FEC18:
	ldr r0, [r4, #0x74]
	add r1, r5, #0
	bl ov96_021EB588
	ldr r0, [r4, #0x70]
	add r1, r5, #0
	bl ov96_021EB588
	mov r1, #1
	ldr r0, [r4, #0x70]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r4, #0x70]
	mov r1, #8
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r4, #0x74]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, sp, #0x10
	ldrb r0, [r0, #0x10]
	mov r1, #0
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EAB38
	add r0, r4, #0
	mov r1, #1
	add r0, #0xc8
	str r1, [r0]
	add r0, r4, #0
	mov r1, #0
	add r0, #0xa1
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, [sp, #0x2c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	ldr r1, _021FED38 ; =0x000008B4
	asr r0, r0, #0xc
	bl ov96_021FFE38
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r4, #0xa0
	add sp, #0xc
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, r6, pc}
_021FEC84:
	ldr r0, [r4, #0x74]
	bl ov96_021EB594
	add r6, r0, #0
	add r3, sp, #0
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	mov r0, #5
	ldr r1, [sp, #4]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #4]
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [sp]
	ldr r0, [r4, #0x74]
	bl ov96_021EB588
	ldr r0, [r4, #0x70]
	add r1, r5, #0
	bl ov96_021EB588
	add r0, r4, #0
	add r0, #0xa1
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xa1
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #0x14
	blo _021FED34
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r4, #0xa0
	add sp, #0xc
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, r6, pc}
_021FECDE:
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _021FED04
	add r1, sp, #0x10
	ldrb r1, [r1, #0x10]
	bl ov96_022006BC
	cmp r0, #0
	beq _021FED34
	mov r0, #1
	strb r0, [r6, #8]
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r4, #0xa0
	add sp, #0xc
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, r6, pc}
_021FED04:
	ldr r1, [sp, #0x28]
	cmp r1, #0
	beq _021FED28
	add r1, r3, #0
	bl ov96_02200900
	cmp r0, #0
	beq _021FED34
	mov r0, #1
	strb r0, [r6, #8]
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r4, #0xa0
	add sp, #0xc
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, r6, pc}
_021FED28:
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r4, #0xa0
	add r0, r0, #1
	strb r0, [r4]
_021FED34:
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021FED38: .word 0x000008B4
	thumb_func_end ov96_021FEBF0


	thumb_func_start ov96_021FED3C
ov96_021FED3C: ; 0x021FED3C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r0, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r5, r1, #0
	add r6, r3, #0
	cmp r0, #3
	bls _021FED50
	b _021FEE56
_021FED50:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021FED5C: ; jump table
	.short _021FED64 - _021FED5C - 2 ; case 0
	.short _021FEDC2 - _021FED5C - 2 ; case 1
	.short _021FEE1C - _021FED5C - 2 ; case 2
	.short _021FEE46 - _021FED5C - 2 ; case 3
_021FED64:
	add r3, r5, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0xc
	add r7, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	mov r0, #0x19
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x74]
	add r1, r7, #0
	bl ov96_021EB588
	mov r1, #1
	ldr r0, [r4, #0x74]
	add r2, r1, #0
	bl ov96_021EB52C
	lsl r0, r6, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov96_021EAB38
	add r0, r4, #0
	mov r1, #0
	add r0, #0xa1
	strb r1, [r0]
	ldr r1, [r5]
	ldr r2, [sp, #0x38]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	ldr r1, _021FEE5C ; =0x000008B5
	asr r0, r0, #0xc
	bl ov96_021FFE38
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r4, #0xa0
	add sp, #0x18
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_021FEDC2:
	ldr r0, [r4, #0x74]
	bl ov96_021EB594
	add r6, r0, #0
	add r3, sp, #0
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	mov r0, #5
	ldr r1, [sp, #4]
	lsl r0, r0, #0xe
	add r0, r1, r0
	str r0, [sp, #4]
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [sp]
	ldr r0, [r4, #0x74]
	bl ov96_021EB588
	add r0, r4, #0
	add r0, #0xa1
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xa1
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #0x14
	blo _021FEE56
	ldr r0, [r4, #0x70]
	add r1, r5, #0
	bl ov96_021EB588
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r4, #0xa0
	add sp, #0x18
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_021FEE1C:
	ldr r0, [sp, #0x34]
	cmp r0, #0
	beq _021FEE28
	ldr r0, [sp, #0x30]
	mov r1, #2
	strb r1, [r0, #8]
_021FEE28:
	ldr r0, [r4, #0x74]
	add r1, r5, #0
	bl ov96_021EB588
	ldr r0, [r4, #0x70]
	add r1, r5, #0
	bl ov96_021EB588
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xa0
	strb r1, [r0]
_021FEE46:
	ldr r0, [r4, #0x74]
	add r1, r5, #0
	bl ov96_021EB588
	ldr r0, [r4, #0x70]
	add r1, r5, #0
	bl ov96_021EB588
_021FEE56:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FEE5C: .word 0x000008B5
	thumb_func_end ov96_021FED3C


	thumb_func_start ov96_021FEE60
ov96_021FEE60: ; 0x021FEE60
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	lsl r0, r2, #2
	ldr r0, [r5, r0]
	mov r1, #1
	add r4, r3, #0
	bl ov96_021EAB38
	add r0, r5, #0
	mov r1, #0
	add r0, #0xc8
	str r1, [r0]
	mov r1, #1
	ldr r0, [r5, #0x70]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x70]
	mov r1, #8
	bl ov96_021EB564
	ldr r0, [r5, #0x74]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _021FEEA0
	mov r0, #0
	strb r0, [r4, #8]
_021FEEA0:
	ldr r0, [r5, #0x70]
	bl ov96_021EB594
	add r3, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r1, [sp]
	ldr r2, [sp, #0x1c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	ldr r1, _021FEEC8 ; =0x000008B6
	asr r0, r0, #0xc
	bl ov96_021FFE38
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_021FEEC8: .word 0x000008B6
	thumb_func_end ov96_021FEE60


	thumb_func_start ov96_021FEECC
ov96_021FEECC: ; 0x021FEECC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	ldr r7, [sp, #0x40]
	str r0, [sp, #0x10]
	ldr r6, [sp, #0x44]
	mov r0, #0
	str r0, [sp, #0x14]
	add r4, r1, #0
	ldrb r0, [r3, #0x1d]
	lsl r1, r7, #1
	mov ip, r2
	asr r0, r1
	mov r1, #3
	and r0, r1
	add r1, r4, #0
	add r1, #0x9f
	lsl r0, r0, #0x18
	ldrb r1, [r1]
	lsr r0, r0, #0x18
	ldr r5, [sp, #0x50]
	cmp r1, r0
	beq _021FEF0A
	add r1, r4, #0
	add r1, #0x9f
	strb r0, [r1]
	add r1, r4, #0
	ldr r0, [sp, #0x14]
	add r1, #0xa0
	strb r0, [r1]
	mov r0, #1
	str r0, [sp, #0x14]
_021FEF0A:
	add r0, sp, #0x18
	str r0, [sp]
	mov r1, ip
	ldr r2, [r1]
	lsl r0, r6, #2
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	mov r2, ip
	ldr r3, [r2, #4]
	ldr r0, [r4, r0]
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r1, r1, #0xc
	asr r2, r2, #0xc
	add r3, sp, #0x1c
	bl ov96_021EB0A4
	ldr r0, [sp, #0x1c]
	lsl r0, r0, #0xc
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x18]
	lsl r0, r0, #0xc
	str r0, [sp, #0x24]
	mov r0, #0
	str r0, [sp, #0x28]
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FEFB0
	cmp r0, #1
	beq _021FEF56
	cmp r0, #2
	beq _021FEF82
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
_021FEF56:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _021FEF66
	ldr r0, [sp, #0x54]
	cmp r0, #0
	beq _021FEF66
	mov r1, #1
	b _021FEF68
_021FEF66:
	mov r1, #0
_021FEF68:
	ldr r0, [sp, #0x48]
	str r6, [sp]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0x10]
	add r1, r4, #0
	add r2, sp, #0x20
	add r3, r7, #0
	str r5, [sp, #0xc]
	bl ov96_021FEBF0
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
_021FEF82:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _021FEF92
	ldr r0, [sp, #0x54]
	cmp r0, #0
	beq _021FEF92
	mov r1, #1
	b _021FEF94
_021FEF92:
	mov r1, #0
_021FEF94:
	ldr r0, [sp, #0x48]
	add r2, r7, #0
	str r0, [sp]
	add r0, r1, #0
	orr r0, r5
	str r0, [sp, #4]
	add r0, r4, #0
	add r1, sp, #0x20
	add r3, r6, #0
	str r5, [sp, #8]
	bl ov96_021FED3C
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
_021FEFB0:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _021FEFDA
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _021FEFC6
	ldr r0, [sp, #0x54]
	cmp r0, #0
	beq _021FEFC6
	mov r0, #1
	b _021FEFC8
_021FEFC6:
	mov r0, #0
_021FEFC8:
	orr r0, r5
	str r0, [sp]
	ldr r3, [sp, #0x48]
	add r0, r4, #0
	add r1, r7, #0
	add r2, r6, #0
	str r5, [sp, #4]
	bl ov96_021FEE60
_021FEFDA:
	ldr r0, [r4, #0x70]
	add r1, sp, #0x20
	bl ov96_021EB588
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021FEECC


	thumb_func_start ov96_021FEFE8
ov96_021FEFE8: ; 0x021FEFE8
	push {r3, r4, r5, r6, r7, lr}
	str r3, [sp]
	add r5, r1, #0
	add r1, r2, #0
	ldr r2, [sp]
	ldr r6, [sp, #0x18]
	bl ov96_021E60D8
	add r4, r0, #0
	ldr r0, [sp]
	mov r1, #0x1c
	add r7, r0, #0
	ldrb r0, [r4]
	mul r7, r1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl _fflt
	bl _f2d
	ldr r3, _021FF0B8 ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r6, r7
	str r0, [r1, #0x20]
	ldrb r0, [r4, #3]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x14]
	bl _fflt
	add r1, r6, r7
	str r0, [r1, #0x28]
	ldrb r0, [r4, #3]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x14]
	bl _fflt
	add r1, r6, r7
	str r0, [r1, #0x24]
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r2, [r0, #0x64]
	add r0, r1, #0
	add r0, #0x2e
	strb r2, [r0]
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	add r0, #0x8c
	ldr r2, [r0]
	add r0, r1, #0
	add r0, #0x2c
	strb r2, [r0]
	ldrb r0, [r4, #1]
	add r1, #0x2d
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x78]
	strb r0, [r1]
	ldrb r0, [r4, #4]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x28]
	bl _fflt
	bl _f2d
	ldr r3, _021FF0B8 ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r6, r7
	str r0, [r1, #0x18]
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x3c]
	bl _fflt
	bl _f2d
	ldr r3, _021FF0B8 ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r6, r7
	str r0, [r1, #0x1c]
	ldrb r0, [r4, #3]
	add r1, #0x2f
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x50]
	strb r0, [r1]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FF0B8: .word 0x40240000
	thumb_func_end ov96_021FEFE8


	thumb_func_start ov96_021FF0BC
ov96_021FF0BC: ; 0x021FF0BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	ldr r0, [sp, #0x28]
	str r2, [sp]
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x2c]
	str r3, [sp, #4]
	str r0, [sp, #0x2c]
	mov r0, #0
	add r7, r0, #0
_021FF0D2:
	stmia r2!, {r7}
	add r0, r0, #1
	stmia r3!, {r7}
	cmp r0, #0x1e
	blt _021FF0D2
	ldr r0, [sp, #0x28]
	str r5, [sp, #8]
	strb r7, [r0]
	ldr r0, [sp, #0x2c]
	strb r7, [r0]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x10]
	ldr r0, _021FF1C4 ; =0x0000045C
	add r6, r5, r0
_021FF0F4:
	ldr r0, _021FF1C8 ; =0x000004D4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021FF1C0
	ldr r1, [sp, #8]
	ldr r0, _021FF1C4 ; =0x0000045C
	ldr r0, [r1, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, _021FF1CC ; =0x000004DC
	ldrh r1, [r5, r0]
	ldr r0, [sp, #0x10]
	sub r4, r0, r1
	add r0, r4, #0
	bl _dflt
	ldr r3, _021FF1D0 ; =0x40880000
	mov r2, #0
	bl _dgeq
	blo _021FF144
	add r0, r4, #0
	bl _dflt
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FF1D4 ; =0x40900000
	mov r0, #0
	bl _dsub
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FF1D8 ; =0x40540000
	mov r0, #0
	bl _dadd
	bl _dfix
	b _021FF17C
_021FF144:
	add r0, r4, #0
	bl _dflt
	ldr r3, _021FF1DC ; =0xC0880000
	mov r2, #0
	bl _dleq
	bhi _021FF178
	add r0, r4, #0
	bl _dflt
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FF1D4 ; =0x40900000
	mov r0, #0
	bl _dadd
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FF1D8 ; =0x40540000
	mov r0, #0
	bl _dsub
	bl _dfix
	b _021FF17C
_021FF178:
	mov r0, #0x50
	sub r0, r0, r4
_021FF17C:
	mov r1, #0x1f
	mvn r1, r1
	cmp r0, r1
	blt _021FF1B0
	mov r1, #0x12
	lsl r1, r1, #4
	cmp r0, r1
	bgt _021FF1B0
	ldr r0, [sp, #0xc]
	cmp r0, #3
	bne _021FF1A2
	ldr r0, [sp, #0x2c]
	ldrb r2, [r0]
	add r1, r2, #1
	strb r1, [r0]
	ldr r0, [sp, #4]
	lsl r1, r2, #2
	str r6, [r0, r1]
	b _021FF1B0
_021FF1A2:
	ldr r0, [sp, #0x28]
	ldrb r2, [r0]
	add r1, r2, #1
	strb r1, [r0]
	ldr r0, [sp]
	lsl r1, r2, #2
	str r6, [r0, r1]
_021FF1B0:
	ldr r0, [sp, #8]
	add r7, r7, #1
	add r0, r0, #4
	add r5, #0xc
	add r6, r6, #4
	str r0, [sp, #8]
	cmp r7, #0x1e
	blt _021FF0F4
_021FF1C0:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FF1C4: .word 0x0000045C
_021FF1C8: .word 0x000004D4
_021FF1CC: .word 0x000004DC
_021FF1D0: .word 0x40880000
_021FF1D4: .word 0x40900000
_021FF1D8: .word 0x40540000
_021FF1DC: .word 0xC0880000
	thumb_func_end ov96_021FF0BC


	thumb_func_start ov96_021FF1E0
ov96_021FF1E0: ; 0x021FF1E0
	push {r4, r5}
	ldr r3, [r1]
	lsl r1, r3, #0x18
	lsr r4, r1, #0x18
	asr r1, r3, #8
	lsl r1, r1, #0x18
	asr r3, r3, #0x10
	lsr r1, r1, #0x18
	lsl r3, r3, #0x10
	lsr r5, r3, #0x10
	add r1, #0x20
	str r4, [r2]
	cmp r4, #3
	bne _021FF208
	sub r5, #0x20
	str r5, [r2, #4]
	sub r1, #0x20
	str r1, [r2, #8]
	pop {r4, r5}
	bx lr
_021FF208:
	cmp r4, #1
	bne _021FF210
	mov r3, #0x30
	b _021FF212
_021FF210:
	mov r3, #0x20
_021FF212:
	lsr r4, r3, #1
	sub r5, r5, r4
	sub r4, r1, r4
	str r5, [r2, #4]
	str r4, [r2, #8]
	add r1, r5, r3
	str r1, [r2, #0xc]
	str r4, [r2, #0x10]
	str r1, [r2, #0x14]
	add r1, r4, r3
	str r1, [r2, #0x18]
	str r5, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r3, [r2, #4]
	ldr r1, [r2, #8]
	str r3, [r2, #0x24]
	str r1, [r2, #0x28]
	ldr r3, [r2, #0xc]
	ldr r1, [r2, #0x10]
	str r3, [r2, #0x2c]
	str r1, [r2, #0x30]
	ldr r3, [r2, #0xc]
	ldr r1, [r2, #0x10]
	str r3, [r2, #0x34]
	str r1, [r2, #0x38]
	ldr r3, [r2, #0x14]
	ldr r1, [r2, #0x18]
	str r3, [r2, #0x3c]
	str r1, [r2, #0x40]
	ldr r3, [r2, #0x14]
	ldr r1, [r2, #0x18]
	str r3, [r2, #0x44]
	str r1, [r2, #0x48]
	ldr r3, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r3, [r2, #0x4c]
	str r1, [r2, #0x50]
	ldr r3, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r3, [r2, #0x54]
	str r1, [r2, #0x58]
	ldr r3, [r2, #4]
	ldr r1, [r2, #8]
	str r3, [r2, #0x5c]
	str r1, [r2, #0x60]
	ldr r1, [r2, #0x28]
	sub r1, r1, r0
	str r1, [r2, #0x28]
	ldr r1, [r2, #0x30]
	sub r1, r1, r0
	str r1, [r2, #0x30]
	ldr r1, [r2, #0x34]
	add r1, r1, r0
	str r1, [r2, #0x34]
	ldr r1, [r2, #0x3c]
	add r1, r1, r0
	str r1, [r2, #0x3c]
	ldr r1, [r2, #0x48]
	add r1, r1, r0
	str r1, [r2, #0x48]
	ldr r1, [r2, #0x50]
	add r1, r1, r0
	str r1, [r2, #0x50]
	ldr r1, [r2, #0x54]
	sub r1, r1, r0
	str r1, [r2, #0x54]
	ldr r1, [r2, #0x5c]
	sub r0, r1, r0
	str r0, [r2, #0x5c]
	pop {r4, r5}
	bx lr
	thumb_func_end ov96_021FF1E0


	thumb_func_start ov96_021FF2A0
ov96_021FF2A0: ; 0x021FF2A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xa4
	str r0, [sp, #4]
	ldr r0, [sp, #0xb8]
	str r1, [sp, #8]
	str r0, [sp, #0xb8]
	add r0, r3, #0
	ldr r0, [r0]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	cmp r0, #3
	bne _021FF2BE
	add sp, #0xa4
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_021FF2BE:
	ldr r0, [sp, #4]
	add r7, r3, #0
	ldr r1, [r0]
	add r6, r3, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x24]
	ldr r0, [sp, #4]
	add r5, r3, #0
	ldr r1, [r0, #4]
	ldr r2, _021FF56C ; =ov96_0221C5FC
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x28]
	ldr r0, [sp, #8]
	add r3, sp, #0x34
	ldr r1, [r0]
	mov r4, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	add r7, #0x2c
	ldr r1, [r0, #4]
	add r6, #0x24
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x20]
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
_021FF30E:
	add r3, sp, #0x34
	add r2, sp, #0x94
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r0, sp, #0x2c
	str r0, [sp]
	add r0, r6, #0
	add r1, r7, #0
	add r2, sp, #0x24
	add r3, sp, #0x1c
	bl sub_02020F4C
	cmp r0, #0
	beq _021FF34C
	ldr r0, [sp, #0x2c]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0xb8]
	str r1, [r0]
	ldr r0, [sp, #0x30]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0xb8]
	str r1, [r0, #4]
	mov r1, #0
	str r1, [r0, #8]
	add r0, sp, #0x94
	lsl r1, r4, #2
	add sp, #0xa4
	ldr r0, [r0, r1]
	pop {r4, r5, r6, r7, pc}
_021FF34C:
	mov r0, #0
	cmp r4, #0
	bne _021FF37C
	cmp r4, #2
	bne _021FF37C
	ldr r2, [sp, #0x28]
	ldr r1, [r5, #0x28]
	cmp r2, r1
	bne _021FF3A0
	ldr r2, [r5, #0x2c]
	ldr r3, [r5, #0x24]
	cmp r3, r2
	bge _021FF36A
	add r1, r3, #0
	b _021FF36E
_021FF36A:
	add r1, r2, #0
	add r2, r3, #0
_021FF36E:
	ldr r3, [sp, #0x24]
	cmp r1, r3
	bgt _021FF3A0
	cmp r3, r2
	bgt _021FF3A0
	mov r0, #1
	b _021FF3A0
_021FF37C:
	ldr r2, [sp, #0x24]
	ldr r1, [r5, #0x24]
	cmp r2, r1
	bne _021FF3A0
	ldr r2, [r5, #0x30]
	ldr r3, [r5, #0x28]
	cmp r3, r2
	bge _021FF390
	add r1, r3, #0
	b _021FF394
_021FF390:
	add r1, r2, #0
	add r2, r3, #0
_021FF394:
	ldr r3, [sp, #0x28]
	cmp r1, r3
	bgt _021FF3A0
	cmp r3, r2
	bgt _021FF3A0
	mov r0, #1
_021FF3A0:
	cmp r0, #0
	beq _021FF3C2
	ldr r2, [sp, #4]
	ldmia r2!, {r0, r1}
	str r2, [sp, #4]
	ldr r2, [sp, #0xb8]
	stmia r2!, {r0, r1}
	ldr r0, [sp, #4]
	str r2, [sp, #0xb8]
	ldr r1, [r0]
	add r0, r2, #0
	str r1, [r0]
	add r0, sp, #0x94
	lsl r1, r4, #2
	add sp, #0xa4
	ldr r0, [r0, r1]
	pop {r4, r5, r6, r7, pc}
_021FF3C2:
	add r4, r4, #1
	add r7, #0x10
	add r6, #0x10
	add r5, #0x10
	cmp r4, #4
	blt _021FF30E
	ldr r3, _021FF570 ; =ov96_0221C60C
	add r2, sp, #0x44
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [sp, #0xc]
	ldr r4, [sp, #0x10]
	mov r5, #0
	lsl r6, r0, #0xc
	add r7, sp, #0x6c
_021FF3E4:
	add r3, sp, #0x44
	add r2, sp, #0x84
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r4, #4]
	add r1, sp, #0x78
	lsl r0, r0, #0xc
	str r0, [sp, #0x78]
	ldr r0, [r4, #8]
	add r2, r7, #0
	lsl r0, r0, #0xc
	str r0, [sp, #0x7c]
	mov r0, #0
	str r0, [sp, #0x80]
	ldr r0, [sp, #8]
	bl VEC_Subtract
	add r0, r7, #0
	bl VEC_Mag
	cmp r0, r6
	bgt _021FF452
	ldr r3, [sp, #0xc]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	add r2, sp, #0x78
	lsl r3, r3, #0xc
	bl ov96_021FF67C
	add r4, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #4]
	add r2, sp, #0x60
	bl VEC_Subtract
	ldr r2, [sp, #4]
	add r0, r4, #0
	add r1, sp, #0x60
	add r3, sp, #0x54
	bl VEC_MultAdd
	ldr r1, [sp, #0x54]
	ldr r0, [sp, #0xb8]
	str r1, [r0]
	ldr r1, [sp, #0x58]
	str r1, [r0, #4]
	mov r1, #0
	str r1, [r0, #8]
	add r0, sp, #0x84
	lsl r1, r5, #2
	add sp, #0xa4
	ldr r0, [r0, r1]
	pop {r4, r5, r6, r7, pc}
_021FF452:
	add r5, r5, #1
	add r4, #8
	cmp r5, #4
	blt _021FF3E4
	ldr r0, [sp, #8]
	ldr r1, [r0]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #4]
	lsl r0, r0, #0xc
	cmp r0, r1
	bgt _021FF564
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x14]
	lsl r0, r0, #0xc
	cmp r1, r0
	bgt _021FF564
	ldr r0, [sp, #8]
	ldr r1, [r0, #4]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #8]
	lsl r0, r0, #0xc
	cmp r0, r1
	bgt _021FF564
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x18]
	lsl r0, r0, #0xc
	cmp r1, r0
	bgt _021FF564
	ldr r3, [sp, #8]
	ldr r2, [sp, #0xb8]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0
	str r0, [r2]
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x10]
	ldr r0, [r0, #4]
	ldr r3, [r3, #0x14]
	str r0, [sp, #0x18]
	ldr r0, [sp, #8]
	str r3, [sp, #0x14]
	ldr r2, [r0]
	ldr r0, [sp, #0x18]
	lsl r3, r3, #0xc
	lsl r0, r0, #0xc
	sub r0, r0, r2
	sub r3, r3, r2
	mov ip, r1
	cmp r0, #0
	bge _021FF4BC
	sub r2, r1, #1
	mul r0, r2
_021FF4BC:
	cmp r3, #0
	bge _021FF4C6
	mov r2, #0
	mvn r2, r2
	mul r3, r2
_021FF4C6:
	cmp r0, r3
	bge _021FF4CE
	mov r6, #0xd
	b _021FF4D2
_021FF4CE:
	add r0, r3, #0
	mov r6, #0xb
_021FF4D2:
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #8]
	ldr r4, [sp, #0x10]
	ldr r2, [r2, #8]
	ldr r5, [r3, #4]
	ldr r7, [r4, #0x18]
	lsl r3, r2, #0xc
	lsl r4, r7, #0xc
	sub r3, r3, r5
	sub r4, r4, r5
	cmp r3, #0
	bge _021FF4F0
	mov r5, #0
	mvn r5, r5
	mul r3, r5
_021FF4F0:
	cmp r4, #0
	bge _021FF4FA
	mov r5, #0
	mvn r5, r5
	mul r4, r5
_021FF4FA:
	cmp r3, r4
	bge _021FF502
	mov r4, #0xa
	b _021FF506
_021FF502:
	add r3, r4, #0
	mov r4, #0xc
_021FF506:
	cmp r0, r3
	bgt _021FF512
	mov r0, #1
	mov ip, r0
	add r0, r6, #0
	b _021FF516
_021FF512:
	mov r1, #1
	add r0, r4, #0
_021FF516:
	mov r3, ip
	cmp r3, #0
	beq _021FF540
	cmp r6, #0xd
	bne _021FF530
	ldr r2, [sp, #0x18]
	ldr r1, [sp, #0xc]
	sub r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1]
	pop {r4, r5, r6, r7, pc}
_021FF530:
	ldr r2, [sp, #0x14]
	ldr r1, [sp, #0xc]
	add r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1]
	pop {r4, r5, r6, r7, pc}
_021FF540:
	cmp r1, #0
	beq _021FF566
	cmp r4, #0xa
	bne _021FF556
	ldr r1, [sp, #0xc]
	sub r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1, #4]
	pop {r4, r5, r6, r7, pc}
_021FF556:
	ldr r1, [sp, #0xc]
	add r1, r7, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1, #4]
	pop {r4, r5, r6, r7, pc}
_021FF564:
	mov r0, #0
_021FF566:
	add sp, #0xa4
	pop {r4, r5, r6, r7, pc}
	nop
_021FF56C: .word ov96_0221C5FC
_021FF570: .word ov96_0221C60C
	thumb_func_end ov96_021FF2A0


	thumb_func_start ov96_021FF574
ov96_021FF574: ; 0x021FF574
	push {r3, r4}
	ldr r3, [r1, #4]
	ldr r2, [r0]
	ldr r1, [r1, #8]
	lsl r3, r3, #0xc
	ldr r0, [r0, #4]
	lsl r4, r1, #0xc
	cmp r3, r2
	bge _021FF5A0
	mov r1, #1
	lsl r1, r1, #0x12
	add r3, r3, r1
	cmp r2, r3
	bge _021FF5A0
	cmp r4, r0
	bge _021FF5A0
	add r1, r4, r1
	cmp r0, r1
	bge _021FF5A0
	mov r0, #1
	pop {r3, r4}
	bx lr
_021FF5A0:
	mov r0, #0
	pop {r3, r4}
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021FF574


	thumb_func_start ov96_021FF5A8
ov96_021FF5A8: ; 0x021FF5A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1dc
	str r1, [sp, #8]
	ldr r1, [sp, #0x1f0]
	add r7, r3, #0
	str r1, [sp, #0x1f0]
	ldr r1, [sp, #0x1f4]
	add r6, r2, #0
	str r1, [sp, #0x1f4]
	add r1, sp, #0x14
	add r1, #1
	str r1, [sp]
	add r1, sp, #0x14
	str r1, [sp, #4]
	ldr r1, [r7]
	add r2, sp, #0x164
	add r3, sp, #0xec
	bl ov96_021FF0BC
	mov r4, #0
	str r4, [sp, #0x10]
	add r0, sp, #0x14
	ldrb r0, [r0]
	cmp r0, #0
	ble _021FF604
	add r5, sp, #0xec
_021FF5DC:
	ldr r1, [r5]
	add r0, r6, #0
	add r2, sp, #0x88
	bl ov96_021FF1E0
	add r0, r7, #0
	add r1, sp, #0x88
	bl ov96_021FF574
	cmp r0, #0
	beq _021FF5F8
	mov r0, #1
	str r0, [sp, #0x10]
	b _021FF604
_021FF5F8:
	add r0, sp, #0x14
	ldrb r0, [r0]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r0
	blt _021FF5DC
_021FF604:
	mov r5, #0
	str r5, [sp, #0xc]
	add r0, sp, #0x14
	ldrb r0, [r0, #1]
	cmp r0, #0
	ble _021FF66C
	add r4, sp, #0x164
_021FF612:
	ldr r1, [r4]
	add r0, r6, #0
	add r2, sp, #0x24
	bl ov96_021FF1E0
	add r0, sp, #0x18
	str r0, [sp]
	ldr r1, [sp, #0x1f0]
	add r0, r7, #0
	add r2, r6, #0
	add r3, sp, #0x24
	bl ov96_021FF2A0
	cmp r0, #0
	beq _021FF660
	cmp r0, #0xa
	blt _021FF644
	ldr r2, [sp, #0x18]
	ldr r1, [sp, #0x1f4]
	str r2, [r1]
	ldr r2, [sp, #0x1c]
	str r2, [r1, #4]
	mov r2, #0
	str r2, [r1, #8]
	b _021FF658
_021FF644:
	ldr r1, [sp, #8]
	cmp r0, r1
	beq _021FF658
	ldr r2, [sp, #0x18]
	ldr r1, [sp, #0x1f4]
	str r2, [r1]
	ldr r2, [sp, #0x1c]
	str r2, [r1, #4]
	mov r2, #0
	str r2, [r1, #8]
_021FF658:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	b _021FF66C
_021FF660:
	add r0, sp, #0x14
	ldrb r0, [r0, #1]
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, r0
	blt _021FF612
_021FF66C:
	ldr r0, [sp, #0x10]
	lsl r1, r0, #8
	ldr r0, [sp, #0xc]
	add r0, r1, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	add sp, #0x1dc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021FF5A8


	thumb_func_start ov96_021FF67C
ov96_021FF67C: ; 0x021FF67C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r0, #0
	add r6, r2, #0
	add r0, r1, #0
	add r1, r4, #0
	add r2, sp, #0
	add r7, r3, #0
	bl VEC_Subtract
	add r0, sp, #0
	bl VEC_Mag
	add r5, r0, #0
	mul r5, r0
	add r0, sp, #0
	add r1, r6, #0
	bl VEC_DotProduct
	add r4, r0, #0
	add r0, r6, #0
	bl VEC_Mag
	add r1, r0, #0
	mul r1, r0
	add r0, r7, #0
	mul r0, r7
	sub r0, r1, r0
	mul r0, r5
	sub r0, r4, r0
	bl FX_Sqrt
	add r7, r0, #0
	sub r0, r7, r4
	add r1, r5, #0
	bl FX_Div
	add r6, r0, #0
	add r0, r4, r7
	neg r0, r0
	add r1, r5, #0
	bl FX_Div
	cmp r6, r0
	bgt _021FF6D8
	add r0, r6, #0
_021FF6D8:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021FF67C


	thumb_func_start ov96_021FF6DC
ov96_021FF6DC: ; 0x021FF6DC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, #0xa5
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FF6F8
	mov r0, #0x1c
	mul r0, r1
	add r0, r5, r0
	add r0, #0x2c
	ldrb r0, [r0]
	bl _ffltu
	pop {r3, r4, r5, pc}
_021FF6F8:
	mov r0, #0x1c
	add r4, r1, #0
	mul r4, r0
	add r0, r5, r4
	ldr r0, [r0, #0x24]
	bl _f2d
	ldr r3, _021FF728 ; =0x40440000
	mov r2, #0
	bl _dleq
	bhi _021FF71C
	add r0, r5, r4
	add r0, #0x2d
	ldrb r0, [r0]
	bl _ffltu
	pop {r3, r4, r5, pc}
_021FF71C:
	add r0, r5, r4
	add r0, #0x2e
	ldrb r0, [r0]
	bl _ffltu
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021FF728: .word 0x40440000
	thumb_func_end ov96_021FF6DC


	thumb_func_start ov96_021FF72C
ov96_021FF72C: ; 0x021FF72C
	push {r4, r5, r6, lr}
	add r5, r2, #0
	ldr r3, [r0]
	ldr r2, [r1]
	add r2, r3, r2
	str r2, [r5]
	ldr r4, [r1, #4]
	ldr r6, [r0, #4]
	asr r3, r4, #0x1f
	asr r1, r6, #0x1f
	add r0, r6, #0
	add r2, r4, #0
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r1, r2, #0xc
	orr r1, r0
	bmi _021FF760
	add r0, r6, r4
	str r0, [r5, #4]
	pop {r4, r5, r6, pc}
_021FF760:
	str r4, [r5, #4]
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021FF72C


	thumb_func_start ov96_021FF764
ov96_021FF764: ; 0x021FF764
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa0
	str r0, [sp, #8]
	mov r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r0, [sp, #0x24]
	str r0, [sp, #0x9c]
	str r0, [sp, #0x90]
	str r0, [sp, #0x18]
	add r4, r1, #0
_021FF77A:
	add r0, r4, #0
	add r0, #0x8b
	ldrb r0, [r0]
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r0, #0x9d
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FF796
	add r0, r4, #0
	add r0, #0xa9
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FF798
_021FF796:
	b _021FFAC8
_021FF798:
	ldr r0, [sp, #0x14]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	str r0, [sp, #0x2c]
	add r0, sp, #0x3c
	str r0, [sp]
	ldr r2, [r4, #0x7c]
	ldr r0, [sp, #0x2c]
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	add r2, r4, #0
	add r2, #0x80
	ldr r3, [r2]
	asr r1, r1, #0xc
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r2, r2, #0xc
	add r3, sp, #0x40
	bl ov96_021EB0A4
	add r0, r4, #0
	str r0, [sp, #0x30]
	add r0, #0x8c
	ldr r5, [sp, #0xc]
	mov r6, #0
	str r0, [sp, #0x30]
_021FF7D0:
	ldr r0, [sp, #0x18]
	cmp r0, r6
	bne _021FF7D8
	b _021FFABE
_021FF7D8:
	add r0, r5, #0
	add r0, #0x9d
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FF8E0
	add r0, r5, #0
	add r0, #0x8b
	ldrb r0, [r0]
	ldr r7, [sp, #0x40]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	str r0, [sp, #0x28]
	add r0, sp, #0x34
	str r0, [sp]
	ldr r1, [r5, #0x7c]
	ldr r0, [sp, #0x28]
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	add r2, r5, #0
	add r2, #0x80
	ldr r3, [r2]
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r2, r2, #0xc
	add r3, sp, #0x38
	bl ov96_021EB0A4
	ldr r0, [r4, #0x7c]
	str r0, [sp, #0x1c]
	bl _dflt
	ldr r3, _021FFADC ; =0x41480000
	mov r2, #0
	bl _dgr
	bls _021FF846
	mov r0, #1
	ldr r1, [r5, #0x7c]
	lsl r0, r0, #0x14
	cmp r1, r0
	bge _021FF846
	ldr r0, [sp, #0x38]
	bl _dflt
	ldr r3, _021FFAE0 ; =0x40900000
	mov r2, #0
	bl _dadd
	bl _dfix
	str r0, [sp, #0x38]
	b _021FF874
_021FF846:
	ldr r0, [r5, #0x7c]
	bl _dflt
	ldr r3, _021FFADC ; =0x41480000
	mov r2, #0
	bl _dgr
	bls _021FF874
	mov r0, #1
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #0x14
	cmp r1, r0
	bge _021FF874
	add r0, r7, #0
	bl _dflt
	ldr r3, _021FFAE0 ; =0x40900000
	mov r2, #0
	bl _dadd
	bl _dfix
	add r7, r0, #0
_021FF874:
	add r0, sp, #0x8c
	str r0, [sp]
	add r0, sp, #0x44
	str r0, [sp, #4]
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x34]
	ldr r0, [sp, #0x28]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x88
	bl ov96_021EAF78
	add r0, sp, #0x98
	str r0, [sp]
	add r0, sp, #0x48
	str r0, [sp, #4]
	ldr r2, [sp, #0x3c]
	ldr r0, [sp, #0x2c]
	lsl r1, r7, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x94
	bl ov96_021EAF78
	add r0, sp, #0x88
	add r1, sp, #0x94
	add r2, sp, #0x7c
	bl VEC_Subtract
	add r0, sp, #0x7c
	bl VEC_Mag
	ldr r2, [sp, #0x44]
	ldr r1, [sp, #0x48]
	add r1, r2, r1
	lsl r1, r1, #0xc
	cmp r0, r1
	blt _021FF8C0
	b _021FFAAC
_021FF8C0:
	add r0, r4, r6
	add r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FF8E0
	mov r1, #0
	add r0, sp, #0x70
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r1, [sp, #0x30]
	add r0, sp, #0x7c
	bl VEC_DotProduct
	cmp r0, #0
	bgt _021FF8E2
_021FF8E0:
	b _021FFABE
_021FF8E2:
	add r0, r4, #0
	add r0, #0x8c
	bl VEC_Mag
	cmp r0, #0
	beq _021FF94C
	add r0, r4, #0
	add r0, #0x8b
	ldrb r0, [r0]
	mov r2, #0x1c
	str r0, [sp, #0x20]
	ldr r1, [sp, #0x20]
	ldr r0, _021FFAE4 ; =0x45800000
	mul r2, r1
	add r1, r4, r2
	ldr r1, [r1, #0x20]
	bl _fmul
	bl _ffix
	add r1, r4, #0
	add r3, r5, #0
	add r1, #0x8c
	add r2, sp, #0x70
	add r3, #0x8c
	bl VEC_MultAdd
	add r0, r5, #0
	add r0, #0x8c
	bl VEC_Mag
	mov r1, #0xb
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _021FF94C
	add r1, sp, #0x64
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r0, r5, #0
	add r0, #0x8c
	add r1, r0, #0
	bl VEC_Normalize
	add r1, r5, #0
	mov r0, #0xb
	add r1, #0x8c
	lsl r0, r0, #0xc
	add r2, sp, #0x64
	add r3, r1, #0
	bl VEC_MultAdd
_021FF94C:
	ldr r0, [sp, #0x14]
	mov r1, #0x1c
	mul r1, r0
	add r0, r5, r1
	add r1, r0, #0
	add r1, #0x30
	ldrb r1, [r1]
	cmp r1, #1
	bne _021FF98A
	mov r1, #0
	str r1, [r0, #0x24]
	add r1, r0, #0
	mov r2, #2
	add r1, #0x30
	strb r2, [r1]
	add r0, #0x2f
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0xa4
	strb r1, [r0]
	mov r3, #1
	add r1, r5, #0
	add r2, r5, #0
	str r3, [sp]
	add r1, #0xd0
	add r2, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [sp, #8]
	bl ov96_021E8228
_021FF98A:
	add r3, sp, #0x58
	mov r7, #0
	str r7, [r3]
	str r7, [r3, #4]
	str r7, [r3, #8]
	add r2, r4, #0
	ldmia r3!, {r0, r1}
	add r2, #0x8c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0x1c
	str r0, [r2]
	ldr r0, [sp, #0x20]
	mul r1, r0
	add r0, r4, r1
	add r1, r0, #0
	add r1, #0x30
	ldrb r1, [r1]
	cmp r1, #1
	bne _021FF9DC
	add r1, r0, #0
	str r7, [r0, #0x24]
	mov r2, #2
	add r1, #0x30
	strb r2, [r1]
	add r0, #0x2f
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0xa4
	strb r1, [r0]
	mov r3, #1
	add r1, r4, #0
	add r2, r4, #0
	str r3, [sp]
	add r1, #0xd0
	add r2, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [sp, #8]
	bl ov96_021E8228
_021FF9DC:
	add r0, r4, r6
	add r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FF9EA
	bl GF_AssertFail
_021FF9EA:
	ldr r0, [sp, #0x18]
	add r0, r5, r0
	add r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FF9FA
	bl GF_AssertFail
_021FF9FA:
	add r1, r5, r6
	mov r0, #1
	add r1, #0x98
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	add r1, r4, r1
	add r1, #0x98
	strb r0, [r1]
	ldr r1, [sp, #0x24]
	cmp r1, #0
	bne _021FFA6C
	add r2, sp, #0x4c
	mov r1, #0
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [r2, #8]
	str r0, [sp, #0x24]
	add r0, sp, #0x88
	add r1, sp, #0x94
	bl VEC_Subtract
	add r0, sp, #0x4c
	add r1, r0, #0
	bl VEC_Normalize
	ldr r0, [sp, #0x48]
	add r1, sp, #0x4c
	lsl r0, r0, #0xc
	add r2, sp, #0x94
	add r3, r1, #0
	bl VEC_MultAdd
	ldr r6, [sp, #0x4c]
	add r0, r6, #0
	bl _dflt
	ldr r3, _021FFAE8 ; =0x41500000
	mov r2, #0
	bl _dgeq
	blo _021FFA60
	add r0, r6, #0
	bl _dflt
	ldr r3, _021FFAE8 ; =0x41500000
	mov r2, #0
	bl _dsub
	bl _dfix
	str r0, [sp, #0x4c]
_021FFA60:
	add r3, sp, #0x4c
	ldr r2, [sp, #0x10]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
_021FFA6C:
	add r0, r5, #0
	mov r1, #6
	add r0, #0xa9
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #0x12
	add r0, #0xa9
	strb r1, [r0]
	add r1, r5, #0
	mov r0, #1
	str r0, [sp]
	add r1, #0xd0
	add r5, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r5]
	ldr r0, [sp, #8]
	mov r3, #4
	bl ov96_021E8228
	mov r0, #1
	add r1, r4, #0
	add r2, r4, #0
	str r0, [sp]
	add r1, #0xd0
	add r2, #0x8b
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [sp, #8]
	mov r3, #4
	bl ov96_021E8228
	b _021FFAC8
_021FFAAC:
	add r1, r4, r6
	add r1, #0x98
	mov r0, #0
	strb r0, [r1]
	ldr r0, [sp, #0x18]
	add r1, r0, r5
	add r1, #0x98
	mov r0, #0
	strb r0, [r1]
_021FFABE:
	add r6, r6, #1
	add r5, #0xd4
	cmp r6, #4
	bge _021FFAC8
	b _021FF7D0
_021FFAC8:
	ldr r0, [sp, #0x18]
	add r4, #0xd4
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #4
	bge _021FFAD6
	b _021FF77A
_021FFAD6:
	ldr r0, [sp, #0x24]
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FFADC: .word 0x41480000
_021FFAE0: .word 0x40900000
_021FFAE4: .word 0x45800000
_021FFAE8: .word 0x41500000
	thumb_func_end ov96_021FF764


	thumb_func_start ov96_021FFAEC
ov96_021FFAEC: ; 0x021FFAEC
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	add r3, r0, #0
	add r4, r2, #0
	ldmia r5!, {r0, r1}
	add r2, sp, #0
	stmia r2!, {r0, r1}
	ldr r0, [r5]
	str r0, [r2]
	ldrb r0, [r3, #8]
	cmp r0, #1
	beq _021FFB10
	cmp r0, #2
	beq _021FFB1C
	cmp r0, #3
	beq _021FFB28
	b _021FFB34
_021FFB10:
	mov r0, #5
	ldr r1, [sp, #4]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #4]
	b _021FFB38
_021FFB1C:
	mov r0, #2
	ldr r1, [sp, #4]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #4]
	b _021FFB38
_021FFB28:
	mov r0, #0xa
	ldr r1, [sp, #4]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #4]
	b _021FFB38
_021FFB34:
	bl GF_AssertFail
_021FFB38:
	add r0, r4, #0
	add r1, sp, #0
	bl ov96_021EB588
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end ov96_021FFAEC


	thumb_func_start ov96_021FFB44
ov96_021FFB44: ; 0x021FFB44
	push {r3, lr}
	ldrb r1, [r0, #0xb]
	cmp r1, #3
	bne _021FFB58
	mov r1, #0x96
	ldr r0, [r0, #4]
	lsl r1, r1, #2
	bl ov96_021EB630
	pop {r3, pc}
_021FFB58:
	ldrb r2, [r0, #0xa]
	mov r1, #0xa0
	add r2, #0x20
	sub r2, r1, r2
	bpl _021FFB64
	mov r2, #0
_021FFB64:
	asr r1, r2, #2
	lsr r1, r1, #0x1d
	add r1, r2, r1
	asr r1, r1, #3
	add r2, r1, #1
	mov r1, #0x1e
	mul r1, r2
	ldr r0, [r0, #4]
	add r1, r1, #3
	bl ov96_021EB630
	pop {r3, pc}
	thumb_func_end ov96_021FFB44


	thumb_func_start ov96_021FFB7C
ov96_021FFB7C: ; 0x021FFB7C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #0xa8
	sub r1, r0, r1
	bpl _021FFB88
	mov r1, #0
_021FFB88:
	asr r0, r1, #2
	lsr r0, r0, #0x1d
	add r0, r1, r0
	asr r1, r0, #3
	cmp r2, #0
	beq _021FFB9C
	mov r0, #0x1e
	mul r0, r1
	add r4, r0, #4
	b _021FFBA2
_021FFB9C:
	mov r0, #0x1e
	mul r0, r1
	add r4, r0, #7
_021FFBA2:
	ldr r0, [r5, #0x70]
	add r1, r4, #0
	bl ov96_021EB630
	ldr r0, [r5, #0x78]
	add r1, r4, #1
	bl ov96_021EB630
	ldr r0, [r5, #0x6c]
	add r1, r4, #1
	bl ov96_021EB630
	ldr r0, [r5, #0x74]
	add r1, r4, #2
	bl ov96_021EB630
	mov r6, #0
_021FFBC4:
	ldr r0, [r5]
	add r1, r4, #2
	bl ov96_021EABA8
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #3
	blt _021FFBC4
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021FFB7C


	thumb_func_start ov96_021FFBD8
ov96_021FFBD8: ; 0x021FFBD8
	push {r4, lr}
	sub sp, #0x10
	mov r2, #0x11
	lsl r2, r2, #4
	add r4, r0, #0
	cmp r1, r2
	ble _021FFC0A
	mov r2, #3
	lsl r2, r2, #8
	cmp r1, r2
	bge _021FFC0A
	mov r1, #3
	str r1, [sp]
	mov r1, #2
	str r1, [sp, #4]
	mov r1, #0x15
	str r1, [sp, #8]
	mov r1, #0x10
	str r1, [sp, #0xc]
	mov r1, #0
	mov r2, #1
	mov r3, #0xa
	bl FillBgTilemapRect
	b _021FFC26
_021FFC0A:
	mov r0, #3
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x15
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x20
	mov r3, #0xa
	bl FillBgTilemapRect
_021FFC26:
	add r0, r4, #0
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021FFBD8


	thumb_func_start ov96_021FFC34
ov96_021FFC34: ; 0x021FFC34
	push {r3, r4, r5, r6, lr}
	sub sp, #0x24
	ldr r3, _021FFD3C ; =ov96_0221C5CC
	add r4, r0, #0
	add r5, r1, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x18
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _021FFD40 ; =ov96_0221C5D8
	str r0, [r2]
	ldmia r3!, {r0, r1}
	add r2, sp, #0xc
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _021FFD44 ; =ov96_0221C5F0
	str r0, [r2]
	ldmia r3!, {r0, r1}
	add r2, sp, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	cmp r0, r5
	bge _021FFC6C
	strh r5, [r4, #0xe]
	mov r0, #1
	b _021FFC6E
_021FFC6C:
	mov r0, #0
_021FFC6E:
	cmp r0, #0
	beq _021FFD0E
	add r0, r5, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r5, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r5, r0, #0x18
	cmp r6, #0
	beq _021FFCB2
	mov r0, #6
	lsl r0, r0, #0x10
	str r0, [sp, #0x18]
	mov r0, #9
	lsl r0, r0, #0x10
	str r0, [sp, #0xc]
	mov r0, #0xb
	lsl r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r4]
	add r1, r6, #1
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [r4, #4]
	add r1, r5, #1
	bl Sprite_SetAnimCtrlSeq
	b _021FFCCE
_021FFCB2:
	mov r0, #7
	lsl r0, r0, #0x10
	str r0, [sp, #0x18]
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, [r4]
	add r1, r5, #1
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [r4, #4]
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
_021FFCCE:
	ldr r0, [r4, #8]
	add r1, sp, #0x18
	bl ov96_021EB588
	ldr r0, [r4]
	add r1, sp, #0xc
	bl Sprite_SetMatrix
	ldr r0, [r4, #4]
	add r1, sp, #0
	bl Sprite_SetMatrix
	mov r1, #1
	ldr r0, [r4, #8]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r4]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [r4, #4]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x3c
	strh r0, [r4, #0xc]
	ldr r0, _021FFD48 ; =0x0000088F
	bl PlaySE
	add sp, #0x24
	pop {r3, r4, r5, r6, pc}
_021FFD0E:
	ldrh r0, [r4, #0xc]
	sub r0, r0, #1
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _021FFD36
	mov r2, #0
	strh r2, [r4, #0xc]
	ldr r0, [r4, #8]
	mov r1, #1
	bl ov96_021EB52C
	ldr r0, [r4]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r4, #4]
	mov r1, #0
	bl Sprite_SetDrawFlag
_021FFD36:
	add sp, #0x24
	pop {r3, r4, r5, r6, pc}
	nop
_021FFD3C: .word ov96_0221C5CC
_021FFD40: .word ov96_0221C5D8
_021FFD44: .word ov96_0221C5F0
_021FFD48: .word 0x0000088F
	thumb_func_end ov96_021FFC34


	thumb_func_start ov96_021FFD4C
ov96_021FFD4C: ; 0x021FFD4C
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4]
	ldr r2, _021FFD7C ; =ov96_0221C5C4
	add r1, r4, #4
	bl AddWindow
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4]
	mov r1, #3
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r4, #0x14]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	add sp, #4
	pop {r3, r4, pc}
	nop
_021FFD7C: .word ov96_0221C5C4
	thumb_func_end ov96_021FFD4C


	thumb_func_start ov96_021FFD80
ov96_021FFD80: ; 0x021FFD80
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	str r1, [sp, #0x10]
	add r0, r5, #4
	mov r1, #0
	add r4, r2, #0
	bl FillWindowPixelBuffer
	mov r0, #0xa
	mul r0, r4
	bl _dflt
	ldr r3, _021FFE2C ; =0x40900000
	mov r2, #0
	bl _ddiv
	bl _dfix
	add r7, r0, #0
	cmp r7, #9
	ble _021FFDB0
	bl GF_AssertFail
_021FFDB0:
	ldr r2, _021FFE30 ; =0x00000135
	ldr r3, [r5, #0x14]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	add r6, r0, #0
	ldr r0, [r5, #0x14]
	bl MessageFormat_New
	mov r3, #2
	str r3, [sp]
	mov r1, #1
	str r1, [sp, #4]
	ldr r2, [sp, #0x10]
	mov r1, #0
	add r4, r0, #0
	bl BufferIntegerAsString
	mov r0, #2
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	add r0, r4, #0
	add r2, r7, #0
	add r3, r1, #0
	bl BufferIntegerAsString
	ldr r3, [r5, #0x14]
	add r0, r4, #0
	add r1, r6, #0
	mov r2, #0xa2
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FFE34 ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	add r0, r5, #4
	add r2, r7, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r4, #0
	bl MessageFormat_Delete
	add r0, r6, #0
	bl DestroyMsgData
	add r0, r5, #4
	bl CopyWindowToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_021FFE2C: .word 0x40900000
_021FFE30: .word 0x00000135
_021FFE34: .word 0x000F0E00
	thumb_func_end ov96_021FFD80


	thumb_func_start ov96_021FFE38
ov96_021FFE38: ; 0x021FFE38
	push {r3, lr}
	cmp r0, #0
	blt _021FFE5A
	mov r3, #1
	lsl r3, r3, #8
	cmp r0, r3
	bge _021FFE5A
	cmp r2, #0
	beq _021FFE4E
	mov r2, #3
	b _021FFE50
_021FFE4E:
	mov r2, #4
_021FFE50:
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
	add r1, r2, #0
	bl sub_0200606C
_021FFE5A:
	pop {r3, pc}
	thumb_func_end ov96_021FFE38


	thumb_func_start ov96_021FFE5C
ov96_021FFE5C: ; 0x021FFE5C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	ldr r1, _021FFEE4 ; =0x00000644
	add r7, r2, #0
	add r3, r0, r1
	mov r1, #0xd4
	mul r1, r5
	add r2, r0, r1
	add r1, r2, #0
	add r1, #0xbb
	ldrb r6, [r1]
	mov r1, #0x1c
	mov r4, #0
	mul r1, r6
	add r6, r2, #0
	add r6, #0xcd
	add r1, r2, r1
	add r1, #0x60
	ldrb r6, [r6]
	ldrb r1, [r1]
	cmp r6, #0
	beq _021FFE8C
	mov r4, #3
	b _021FFEA6
_021FFE8C:
	add r2, #0xd9
	ldrb r2, [r2]
	cmp r2, #0
	beq _021FFE98
	mov r4, #3
	b _021FFEA6
_021FFE98:
	cmp r1, #2
	bne _021FFEA0
	mov r4, #3
	b _021FFEA6
_021FFEA0:
	cmp r1, #1
	bne _021FFEA6
	mov r4, #1
_021FFEA6:
	cmp r7, #0
	bne _021FFEAE
	strb r4, [r3, r5]
	pop {r3, r4, r5, r6, r7, pc}
_021FFEAE:
	mov r1, #0xc
	mul r1, r5
	add r2, r0, r1
	mov r0, #0xe
	lsl r0, r0, #6
	ldr r1, [r2, r0]
	cmp r1, #0
	beq _021FFED8
	cmp r4, #1
	bhi _021FFEC8
	mov r0, #2
	strb r0, [r3, r5]
	pop {r3, r4, r5, r6, r7, pc}
_021FFEC8:
	cmp r4, #3
	bne _021FFED2
	mov r0, #4
	strb r0, [r3, r5]
	pop {r3, r4, r5, r6, r7, pc}
_021FFED2:
	bl GF_AssertFail
	pop {r3, r4, r5, r6, r7, pc}
_021FFED8:
	add r0, r0, #4
	ldr r0, [r2, r0]
	cmp r0, #0
	bne _021FFEE2
	strb r4, [r3, r5]
_021FFEE2:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FFEE4: .word 0x00000644
	thumb_func_end ov96_021FFE5C


	thumb_func_start ov96_021FFEE8
ov96_021FFEE8: ; 0x021FFEE8
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r7, r0, #0
	add r0, r6, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r1, r4, r0
	ldrb r2, [r1, #0x10]
	mov r1, #0x7f
	lsl r0, r0, #1
	and r1, r2
	lsl r1, r1, #0x18
	lsr r5, r1, #0x18
	ldrh r4, [r4, r0]
	cmp r5, #0x3c
	bls _021FFF20
	mov r5, #0x3c
_021FFF20:
	lsl r1, r5, #0xa
	add r1, r4, r1
	lsl r1, r1, #0x10
	add r0, r6, #0
	lsr r1, r1, #0x10
	bl ov96_021E8318
	add r0, r7, #0
	add r1, r5, #0
	add r2, r4, #0
	bl ov96_021FFD80
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021FFEE8


	thumb_func_start ov96_021FFF3C
ov96_021FFF3C: ; 0x021FFF3C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	mov r1, #0x1a
	lsl r1, r1, #4
	add r6, r0, #0
	str r2, [sp]
	bl Heap_Alloc
	mov r2, #0x1a
	add r7, r0, #0
	mov r1, #0
	lsl r2, r2, #4
	bl MI_CpuFill8
	str r6, [r7]
	ldr r0, [sp]
	str r4, [r7, #8]
	str r0, [r7, #4]
	add r0, r7, #0
	bl ov96_02200DF8
	ldr r2, _021FFFE4 ; =0x00000135
	mov r0, #1
	mov r1, #0x1b
	add r3, r6, #0
	bl NewMsgDataFromNarc
	str r0, [r7, #0x2c]
	add r0, r6, #0
	bl MessageFormat_New
	str r0, [r7, #0x30]
	mov r4, #0
	add r5, r7, #0
_021FFF80:
	mov r0, #0xb
	add r1, r6, #0
	bl String_New
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _021FFF80
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantUnk04
	add r4, r0, #0
	mov r6, #0
	add r5, r7, #0
_021FFFAA:
	mov r0, #0x17
	lsl r0, r0, #4
	add r1, r4, #0
	ldr r0, [r5, r0]
	add r1, #0x12
	bl CopyU16ArrayToString
	add r6, r6, #1
	add r4, #0x28
	add r5, r5, #4
	cmp r6, #3
	blt _021FFFAA
	add r0, r7, #0
	mov r1, #1
	bl ov96_02200BD8
	add r0, r7, #0
	bl ov96_02200C40
	mov r0, #0x16
	mov r1, #1
	lsl r0, r0, #4
	strh r1, [r7, r0]
	mov r1, #2
	add r0, r0, #2
	strh r1, [r7, r0]
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FFFE4: .word 0x00000135
	thumb_func_end ov96_021FFF3C


	thumb_func_start ov96_021FFFE8
ov96_021FFFE8: ; 0x021FFFE8
	push {r3, r4, r5, r6, r7, lr}
	mov r7, #0x4a
	lsl r7, r7, #2
	str r0, [sp]
	mov r4, #0
	add r5, r0, #0
	add r6, r7, #4
_021FFFF6:
	ldr r0, [r5, r7]
	bl Heap_Free
	ldr r0, [r5, r6]
	bl Heap_Free
	add r4, r4, #1
	add r5, #8
	cmp r4, #3
	blt _021FFFF6
	ldr r4, [sp]
	mov r5, #0
_0220000E:
	add r0, r4, #0
	add r0, #0xbc
	ldr r0, [r0]
	bl Heap_Free
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #0xc
	blt _0220000E
	ldr r0, [sp]
	ldr r0, [r0, #0x34]
	bl Heap_Free
	mov r6, #0x17
	ldr r4, [sp]
	mov r5, #0
	lsl r6, r6, #4
_02200030:
	ldr r0, [r4, r6]
	bl String_Delete
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #3
	blt _02200030
	ldr r0, [sp]
	ldr r0, [r0, #0x30]
	bl MessageFormat_Delete
	ldr r0, [sp]
	ldr r0, [r0, #0x2c]
	bl DestroyMsgData
	ldr r0, [sp]
	add r0, #0xc
	bl RemoveWindow
	ldr r0, [sp]
	add r0, #0x1c
	bl RemoveWindow
	ldr r0, [sp]
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021FFFE8


	thumb_func_start ov96_02200068
ov96_02200068: ; 0x02200068
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #6
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xb2
	add r3, r1, #0
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #7
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xb2
	mov r3, #6
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #8
	str r0, [sp, #0xc]
	ldr r2, [r4, #8]
	mov r0, #0xb2
	mov r3, #5
	bl GfGfxLoader_LoadScrnData
	ldr r0, [r4]
	add r3, r4, #0
	str r0, [sp]
	mov r0, #0xb2
	mov r1, #9
	mov r2, #0
	add r3, #0x38
	bl GfGfxLoader_GetScrnData
	str r0, [r4, #0x34]
	mov r0, #0x40
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #5
	str r0, [sp, #4]
	mov r0, #0xb2
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPal
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02200068


	thumb_func_start ov96_022000E4
ov96_022000E4: ; 0x022000E4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r0, _0220017C ; =ov96_0221C728
	add r5, r1, #0
	ldr r1, [r0, #0x10]
	ldr r0, [r0, #0x14]
	add r4, sp, #8
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	mov r6, #0
	mov r7, #2
_022000FA:
	str r7, [sp]
	ldr r3, [r4]
	add r0, r5, #0
	mov r1, #0x5d
	mov r2, #9
	bl ov96_021EB2BC
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r3, [r4]
	add r0, r5, #0
	mov r1, #0x5d
	mov r2, #6
	bl ov96_021EB2F4
	ldr r3, [r4]
	add r0, r5, #0
	mov r1, #0x5d
	mov r2, #0xa
	bl ov96_021EB334
	ldr r3, [r4]
	add r0, r5, #0
	mov r1, #0x5d
	mov r2, #0xa
	bl ov96_021EB36C
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #2
	blt _022000FA
	mov r0, #2
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0xb2
	mov r2, #0xd
	mov r3, #0x65
	bl ov96_021EB2BC
	mov r0, #2
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #0xb2
	mov r2, #0xa
	mov r3, #0x65
	bl ov96_021EB2F4
	add r0, r5, #0
	mov r1, #0xb2
	mov r2, #0xc
	mov r3, #0x65
	bl ov96_021EB334
	add r0, r5, #0
	mov r1, #0xb2
	mov r2, #0xb
	mov r3, #0x65
	bl ov96_021EB36C
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220017C: .word ov96_0221C728
	thumb_func_end ov96_022000E4


	thumb_func_start ov96_02200180
ov96_02200180: ; 0x02200180
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #4]
	add r5, r1, #0
	str r2, [sp, #8]
	mov r4, #0
	mov r6, #8
	mov r7, #0xa
_02200190:
	mov r0, #2
	str r0, [sp]
	add r0, r5, #0
	mov r1, #3
	mov r2, #2
	mov r3, #0x65
	bl ov96_021EB408
	mov r0, #3
	str r0, [sp]
	add r0, r5, #0
	mov r1, #3
	mov r2, #2
	mov r3, #0x65
	bl ov96_021EB408
	add r0, r5, #0
	mov r1, #3
	mov r2, #2
	mov r3, #0x65
	str r6, [sp]
	bl ov96_021EB408
	add r0, r5, #0
	mov r1, #3
	mov r2, #2
	mov r3, #0x65
	str r7, [sp]
	bl ov96_021EB408
	add r4, r4, #1
	cmp r4, #4
	blt _02200190
	mov r4, #0
	mov r6, #0x10
	mov r7, #3
_022001D8:
	add r0, r5, #0
	add r1, r7, #0
	mov r2, #2
	mov r3, #0x65
	str r6, [sp]
	bl ov96_021EB408
	add r4, r4, #1
	cmp r4, #2
	blt _022001D8
	ldr r4, [sp, #4]
	mov r6, #0
	mov r7, #0x65
_022001F2:
	add r0, r5, #0
	add r1, r7, #0
	mov r2, #2
	bl ov96_021EB4F4
	str r0, [r4, #0x48]
	add r0, r5, #0
	mov r1, #0x65
	mov r2, #3
	bl ov96_021EB4F4
	str r0, [r4, #0x54]
	add r0, r5, #0
	mov r1, #0x65
	mov r2, #8
	bl ov96_021EB4F4
	str r0, [r4, #0x50]
	add r0, r5, #0
	mov r1, #0x65
	mov r2, #0xa
	bl ov96_021EB4F4
	str r0, [r4, #0x4c]
	ldr r0, [r4, #0x48]
	add r1, r6, #0
	bl ov96_021EB564
	ldr r0, [r4, #0x54]
	add r1, r6, #4
	bl ov96_021EB564
	ldr r0, [r4, #0x50]
	mov r1, #0xa
	bl ov96_021EB564
	add r6, r6, #1
	add r4, #0x20
	cmp r6, #4
	blt _022001F2
	mov r0, #0x11
	str r0, [sp]
	add r0, r5, #0
	mov r1, #3
	mov r2, #2
	mov r3, #0x65
	bl ov96_021EB3E4
	mov r1, #1
	add r4, r0, #0
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r4, #0
	mov r1, #0xb
	bl ov96_021EB564
	mov r0, #0
	str r0, [sp, #0x18]
	mov r0, #2
	lsl r0, r0, #0x12
	str r0, [sp, #0x10]
	mov r0, #0x8e
	lsl r0, r0, #0xe
	str r0, [sp, #0x14]
	add r0, r4, #0
	add r1, sp, #0x10
	bl ov96_021EB588
	ldr r1, [sp, #4]
	add r0, r5, #0
	bl ov96_02200C8C
	mov r0, #0
	ldr r4, [sp, #4]
	ldr r7, _022002F0 ; =ov96_0221C718
	ldr r6, _022002F4 ; =ov96_0221C720
	str r0, [sp, #0xc]
_0220028E:
	add r0, r5, #0
	bl ov96_021EB5E8
	ldr r3, [sp, #4]
	add r1, r0, #0
	ldr r0, [sp, #8]
	ldr r3, [r3]
	mov r2, #3
	bl ov96_021EA2C4
	mov r1, #0x5f
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldrb r0, [r7]
	add r1, sp, #0x1c
	lsl r0, r0, #0xc
	str r0, [sp, #0x1c]
	mov r0, #0x8e
	lsl r0, r0, #0xe
	str r0, [sp, #0x20]
	mov r0, #0
	str r0, [sp, #0x24]
	mov r0, #0x5f
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_SetMatrix
	mov r0, #0x5f
	lsl r0, r0, #2
	ldrb r1, [r6]
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [sp, #0xc]
	add r4, r4, #4
	add r0, r0, #1
	add r7, r7, #1
	add r6, r6, #1
	str r0, [sp, #0xc]
	cmp r0, #6
	blt _0220028E
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022002F0: .word ov96_0221C718
_022002F4: .word ov96_0221C720
	thumb_func_end ov96_02200180


	thumb_func_start ov96_022002F8
ov96_022002F8: ; 0x022002F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r6, r0, #0
	add r5, r1, #0
	ldr r1, [r6]
	mov r0, #0x14
	bl NARC_New
	str r0, [sp, #0x14]
	bl sub_02074490
	add r1, r0, #0
	mov r0, #0x60
	str r0, [sp]
	ldr r0, [r6]
	mov r2, #5
	str r0, [sp, #4]
	mov r0, #0x14
	mov r3, #0x20
	bl GfGfxLoader_GXLoadPal
	add r0, r6, #0
	str r0, [sp, #0x10]
	add r0, #0xec
	mov r7, #0
	add r4, r6, #0
	str r0, [sp, #0x10]
_0220032E:
	mov r1, #1
	ldr r0, [r6]
	lsl r1, r1, #0xc
	bl Heap_AllocAtEnd
	add r1, r4, #0
	add r1, #0xbc
	str r0, [r1]
	ldrh r0, [r5, #2]
	mov r1, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldrh r0, [r5]
	ldr r2, [sp, #0xc]
	str r0, [sp, #8]
	bl GetMonIconNaixEx
	add r2, r4, #0
	add r2, #0xbc
	add r1, r0, #0
	ldr r0, [sp, #0x14]
	ldr r2, [r2]
	bl NARC_ReadWholeMember
	add r0, r4, #0
	add r0, #0xbc
	ldr r0, [r0]
	ldr r1, [sp, #0x10]
	bl NNS_G2dGetUnpackedBGCharacterData
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	mov r2, #0
	bl GetMonIconPaletteEx
	add r2, r0, #1
	mov r0, #0x47
	add r1, r6, r7
	lsl r0, r0, #2
	strb r2, [r1, r0]
	ldr r0, [sp, #0x10]
	add r7, r7, #1
	add r0, r0, #4
	add r4, r4, #4
	add r5, r5, #4
	str r0, [sp, #0x10]
	cmp r7, #0xc
	blt _0220032E
	ldr r0, [sp, #0x14]
	bl NARC_Delete
	mov r5, #0
	add r4, r6, #0
	add r7, sp, #0x18
_0220039C:
	lsl r1, r5, #0x18
	add r0, r6, #0
	lsr r1, r1, #0x18
	mov r2, #0
	bl ov96_022004B4
	mov r1, #1
	ldr r0, [r4, #0x48]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r1, #1
	ldr r0, [r4, #0x54]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r0, #0
	str r0, [sp, #0x20]
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r0, [sp, #0x18]
	mov r0, #0x2b
	lsl r0, r0, #0x10
	str r0, [sp, #0x1c]
	ldr r0, [r4, #0x48]
	add r1, r7, #0
	bl ov96_021EB588
	ldr r0, [r4, #0x54]
	add r1, r7, #0
	bl ov96_021EB588
	add r5, r5, #1
	add r4, #0x20
	cmp r5, #4
	blt _0220039C
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_022002F8


	thumb_func_start ov96_022003E8
ov96_022003E8: ; 0x022003E8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r6, r0, #0
	mov r0, #0
	add r5, r1, #0
	str r0, [sp, #0xc]
	add r4, r6, #0
	add r7, sp, #0x10
_022003F8:
	ldrb r0, [r5, #6]
	mov r3, #2
	str r0, [sp]
	ldrh r0, [r5, #2]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	str r0, [sp, #8]
	ldrh r1, [r5]
	ldrb r2, [r5, #7]
	add r0, sp, #0x10
	bl GetMonSpriteCharAndPlttNarcIdsEx
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	ldrh r0, [r7]
	ldrh r1, [r7, #2]
	ldr r2, [r6]
	ldr r3, [r5, #0xc]
	bl sub_0201457C
	mov r1, #0x4a
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldrh r0, [r7]
	ldrh r1, [r7, #4]
	ldr r2, [r6]
	bl sub_02014450
	mov r1, #0x4b
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [sp, #0xc]
	add r5, #0x10
	add r0, r0, #1
	add r4, #8
	str r0, [sp, #0xc]
	cmp r0, #3
	blt _022003F8
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_022003E8


	thumb_func_start ov96_02200454
ov96_02200454: ; 0x02200454
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	add r5, r0, #0
	add r4, r2, #0
	cmp r6, #2
	blo _02200464
	bl GF_AssertFail
_02200464:
	cmp r4, #3
	blo _0220046C
	bl GF_AssertFail
_0220046C:
	mov r0, #0x4a
	lsl r0, r0, #2
	lsl r4, r4, #3
	add r7, r5, r0
	mov r1, #0x32
	ldr r0, [r7, r4]
	lsl r1, r1, #6
	bl DC_FlushRange
	lsl r6, r6, #2
	mov r1, #5
	add r2, r5, r6
	lsl r1, r1, #6
	ldr r1, [r2, r1]
	mov r2, #0x32
	ldr r0, [r7, r4]
	lsl r2, r2, #6
	bl GXS_LoadOBJ
	mov r0, #0x4b
	lsl r0, r0, #2
	add r7, r5, r0
	ldr r0, [r7, r4]
	mov r1, #0x20
	bl DC_FlushRange
	mov r1, #0x52
	add r2, r5, r6
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	ldr r0, [r7, r4]
	mov r2, #0x20
	bl GXS_LoadOBJPltt
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02200454


	thumb_func_start ov96_022004B4
ov96_022004B4: ; 0x022004B4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r1, #0
	add r5, r0, #0
	lsl r0, r4, #5
	add r0, r5, r0
	ldr r0, [r0, #0x48]
	add r6, r2, #0
	bl ov96_021EB5B8
	str r0, [sp]
	lsl r0, r4, #1
	add r0, r4, r0
	add r6, r6, r0
	add r7, r5, #0
	lsl r0, r6, #2
	mov r1, #2
	add r7, #0xec
	str r0, [sp, #4]
	ldr r0, [r7, r0]
	lsl r1, r1, #8
	ldr r0, [r0, #0x14]
	bl DC_FlushRange
	ldr r0, [sp, #4]
	mov r1, #6
	ldr r0, [r7, r0]
	lsl r2, r4, #9
	lsl r1, r1, #8
	add r1, r2, r1
	mov r2, #2
	ldr r0, [r0, #0x14]
	lsl r2, r2, #8
	bl GXS_LoadOBJ
	mov r1, #0x47
	add r2, r5, r6
	lsl r1, r1, #2
	ldrb r1, [r2, r1]
	ldr r0, [sp]
	bl Sprite_SetPaletteOverride
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_022004B4


	thumb_func_start ov96_0220050C
ov96_0220050C: ; 0x0220050C
	push {r4, r5, r6, lr}
	sub sp, #0x48
	add r4, r1, #0
	add r5, r0, #0
	lsr r3, r2, #0x1f
	lsl r1, r2, #0x16
	sub r1, r1, r3
	mov r0, #0x16
	ror r1, r0
	add r0, r3, r1
	lsl r1, r0, #0x10
	asr r0, r1, #9
	lsr r0, r0, #0x16
	add r0, r1, r0
	lsl r0, r0, #6
	lsr r1, r0, #0x10
	mov r0, #1
	lsl r0, r0, #0x10
	sub r0, r0, r1
	lsl r0, r0, #0x10
	ldr r6, _022005A8 ; =ov96_0221C748
	lsr r2, r0, #0x10
	ldmia r6!, {r0, r1}
	add r3, sp, #0x30
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	ldr r6, _022005AC ; =ov96_0221C754
	str r0, [r3]
	ldmia r6!, {r0, r1}
	add r3, sp, #0x24
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	asr r0, r2, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	ldr r3, _022005B0 ; =FX_SinCosTable_
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotZ33_
	add r0, sp, #0x30
	add r1, sp, #0
	add r2, r0, #0
	bl MTX_MultVec33
	add r0, sp, #0x24
	add r1, sp, #0x30
	add r2, sp, #0x3c
	bl VEC_Add
	lsl r4, r4, #5
	add r0, r5, r4
	ldr r0, [r0, #0x48]
	add r1, sp, #0x3c
	bl ov96_021EB588
	add r0, r5, r4
	ldr r0, [r0, #0x54]
	add r1, sp, #0x3c
	bl ov96_021EB588
	add r0, r5, r4
	ldr r0, [r0, #0x4c]
	add r1, sp, #0x3c
	bl ov96_021EB588
	add r0, r5, r4
	ldr r0, [r0, #0x50]
	add r1, sp, #0x3c
	bl ov96_021EB588
	add sp, #0x48
	pop {r4, r5, r6, pc}
	nop
_022005A8: .word ov96_0221C748
_022005AC: .word ov96_0221C754
_022005B0: .word FX_SinCosTable_
	thumb_func_end ov96_0220050C


	thumb_func_start ov96_022005B4
ov96_022005B4: ; 0x022005B4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	add r0, r2, #0
	add r4, r1, #0
	bl _ffltu
	bl _f2d
	ldr r2, _022006B4 ; =0x9999999A
	ldr r3, _022006B8 ; =0x40599999
	bl _ddiv
	bl _dfixu
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x1c]
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r6, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x20
	strb r1, [r0, #2]
	add r0, r6, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x20
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x20
	strb r1, [r0, #3]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x20
	strb r1, [r0, #1]
	mov r4, #0
	mov r7, #4
	mov r6, #8
_0220062E:
	str r7, [sp]
	str r6, [sp, #4]
	ldr r0, [r5, #0x38]
	lsl r2, r4, #2
	add r0, #0xc
	str r0, [sp, #8]
	add r0, sp, #0x20
	add r0, #2
	ldrb r0, [r0, r4]
	add r2, #0xe
	lsl r2, r2, #0x18
	str r0, [sp, #0xc]
	add r0, sp, #0x20
	ldrb r0, [r0, r4]
	mov r1, #5
	lsr r2, r2, #0x18
	str r0, [sp, #0x10]
	mov r0, #0x14
	str r0, [sp, #0x14]
	mov r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [r5, #8]
	add r3, r6, #0
	bl CopyRectToBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _0220062E
	ldr r0, [sp, #0x1c]
	mov r1, #5
	bl _s32_div_f
	add r4, r1, #0
	ldr r0, [sp, #0x1c]
	mov r1, #5
	bl _s32_div_f
	mov r1, #4
	lsl r0, r0, #0x1b
	str r1, [sp]
	mov r3, #8
	str r3, [sp, #4]
	ldr r1, [r5, #0x38]
	lsr r0, r0, #0x18
	add r1, #0xc
	str r1, [sp, #8]
	lsl r1, r4, #0x1a
	lsr r1, r1, #0x18
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0x14
	str r0, [sp, #0x14]
	mov r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [r5, #8]
	mov r1, #5
	mov r2, #0x18
	bl CopyRectToBgTilemapRect
	ldr r0, [r5, #8]
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022006B4: .word 0x9999999A
_022006B8: .word 0x40599999
	thumb_func_end ov96_022005B4


	thumb_func_start ov96_022006BC
ov96_022006BC: ; 0x022006BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	mov r5, #0x59
	add r4, r0, #0
	lsl r5, r5, #2
	add r6, r1, #0
	ldr r1, [r4, r5]
	cmp r1, #3
	bhi _0220073A
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_022006DA: ; jump table
	.short _022006E2 - _022006DA - 2 ; case 0
	.short _0220076E - _022006DA - 2 ; case 1
	.short _022007B2 - _022006DA - 2 ; case 2
	.short _0220084C - _022006DA - 2 ; case 3
_022006E2:
	add r0, r5, #4
	ldr r0, [r4, r0]
	lsl r0, r0, #2
	add r1, r4, r0
	add r0, r5, #0
	sub r0, #0x14
	ldr r0, [r1, r0]
	bl ov96_021EB594
	add r6, r0, #0
	add r3, sp, #0x18
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	mov r0, #2
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [sp, #0x1c]
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x18
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r2, #0
	bl ov96_021EB588
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x10
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, sp, #0x18
	bl ov96_021EB588
	mov r0, #0x2e
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #0x10
	cmp r1, r0
	bge _0220073C
_0220073A:
	b _022008FA
_0220073C:
	mov r0, #0x76
	lsl r0, r0, #0xe
	str r0, [sp, #0x1c]
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x18
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, sp, #0x18
	bl ov96_021EB588
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x10
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, sp, #0x18
	bl ov96_021EB588
	ldr r0, [r4, r5]
	add r0, r0, #1
	str r0, [r4, r5]
	b _022008FA
_0220076E:
	add r1, r5, #4
	ldr r1, [r4, r1]
	add r2, r6, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02200454
	sub r1, r5, #4
	add r0, r4, r1
	add r1, #8
	ldr r1, [r4, r1]
	lsl r2, r1, #1
	ldrh r1, [r0, r2]
	cmp r1, #0
	bne _02200790
	mov r1, #2
	b _02200792
_02200790:
	sub r1, r1, #1
_02200792:
	mov r3, #0x5a
	lsl r3, r3, #2
	strh r1, [r0, r2]
	ldr r0, [r4, r3]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	str r0, [r4, r3]
	ldr r0, [r4, r5]
	add r0, r0, #1
	str r0, [r4, r5]
	b _022008FA
_022007B2:
	add r0, r5, #4
	ldr r0, [r4, r0]
	lsl r0, r0, #2
	add r1, r4, r0
	add r0, r5, #0
	sub r0, #0x14
	ldr r0, [r1, r0]
	bl ov96_021EB594
	add r6, r0, #0
	add r3, sp, #0xc
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	mov r0, #2
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [sp, #0x10]
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x18
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r2, #0
	bl ov96_021EB588
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x10
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, sp, #0xc
	bl ov96_021EB588
	mov r0, #0xa2
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0xe
	cmp r1, r0
	blt _022008FA
	str r0, [sp, #0x10]
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x18
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, sp, #0xc
	bl ov96_021EB588
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x10
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, sp, #0xc
	bl ov96_021EB588
	add r3, r5, #4
	ldr r0, [r4, r3]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	str r0, [r4, r3]
	ldr r0, [r4, r5]
	add r0, r0, #1
	str r0, [r4, r5]
	b _022008FA
_0220084C:
	add r0, r5, #4
	ldr r0, [r4, r0]
	lsl r0, r0, #2
	add r1, r4, r0
	add r0, r5, #0
	sub r0, #0x14
	ldr r0, [r1, r0]
	bl ov96_021EB594
	add r3, r0, #0
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	add r7, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	mov r0, #2
	ldr r1, [sp, #4]
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [sp, #4]
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x18
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r7, #0
	bl ov96_021EB588
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x10
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r7, #0
	bl ov96_021EB588
	mov r0, #0x23
	ldr r1, [sp, #4]
	lsl r0, r0, #0x10
	cmp r1, r0
	blt _022008FA
	str r0, [sp, #4]
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x18
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r7, #0
	bl ov96_021EB588
	add r0, r5, #4
	ldr r1, [r4, r0]
	sub r0, #0x10
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r0, [r1, r0]
	add r1, r7, #0
	bl ov96_021EB588
	add r3, r5, #4
	ldr r0, [r4, r3]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	str r0, [r4, r3]
	add r0, r6, #2
	mov r1, #3
	bl _s32_div_f
	lsl r1, r1, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_02200BD8
	mov r0, #0
	str r0, [r4, r5]
	add sp, #0x24
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_022008FA:
	mov r0, #0
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_022006BC


	thumb_func_start ov96_02200900
ov96_02200900: ; 0x02200900
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r5, r1, #0
	beq _0220090C
	cmp r5, #4
	blo _02200910
_0220090C:
	bl GF_AssertFail
_02200910:
	mov r1, #0x65
	sub r0, r5, #1
	lsl r1, r1, #2
	lsl r0, r0, #2
	add r3, r4, r1
	ldrh r2, [r3, r0]
	add r2, #0x20
	strh r2, [r3, r0]
	ldrh r2, [r3, r0]
	cmp r2, #0x58
	blo _02200934
	mov r2, #0
	add r1, r1, #2
	strh r2, [r3, r0]
	add r2, r4, r1
	ldrh r1, [r2, r0]
	add r1, r1, #1
	strh r1, [r2, r0]
_02200934:
	ldr r1, _0220094C ; =0x00000196
	add r2, r4, r1
	ldrh r1, [r2, r0]
	cmp r1, #3
	blo _02200946
	mov r1, #0
	strh r1, [r2, r0]
	mov r0, #1
	pop {r3, r4, r5, pc}
_02200946:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0220094C: .word 0x00000196
	thumb_func_end ov96_02200900


	thumb_func_start ov96_02200950
ov96_02200950: ; 0x02200950
	push {r3, r4, r5, r6, r7, lr}
	str r3, [sp]
	mov r3, #0x5b
	add r5, r0, #0
	lsl r3, r3, #2
	add r4, r1, #0
	add r7, r5, r3
	ldrb r3, [r7, r4]
	ldr r6, [sp, #0x18]
	cmp r2, r3
	beq _0220096C
	strb r2, [r7, r4]
	bl ov96_022004B4
_0220096C:
	ldr r0, [sp]
	cmp r0, #0
	beq _0220099A
	lsl r4, r4, #5
	add r0, r5, r4
	ldr r0, [r0, #0x48]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	add r0, r5, r4
	mov r1, #1
	ldr r0, [r0, #0x50]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r5, r4
	ldr r0, [r0, #0x4c]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	b _02200A0E
_0220099A:
	lsl r4, r4, #5
	add r0, r5, r4
	mov r1, #1
	ldr r0, [r0, #0x48]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r5, r4
	ldr r0, [r0, #0x50]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	cmp r6, #1
	beq _022009BE
	cmp r6, #2
	beq _022009E0
	b _02200A02
_022009BE:
	add r0, r5, r4
	add r0, #0x58
	ldrb r0, [r0]
	cmp r6, r0
	beq _02200A0E
	add r7, r5, #0
	add r7, #0x4c
	mov r1, #1
	ldr r0, [r7, r4]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r7, r4]
	mov r1, #8
	bl ov96_021EB564
	b _02200A0E
_022009E0:
	add r0, r5, r4
	add r0, #0x58
	ldrb r0, [r0]
	cmp r6, r0
	beq _02200A0E
	add r7, r5, #0
	add r7, #0x4c
	mov r1, #1
	ldr r0, [r7, r4]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r7, r4]
	mov r1, #9
	bl ov96_021EB564
	b _02200A0E
_02200A02:
	add r0, r5, r4
	ldr r0, [r0, #0x4c]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_02200A0E:
	add r0, r5, r4
	add r0, #0x58
	strb r6, [r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02200950


	thumb_func_start ov96_02200A18
ov96_02200A18: ; 0x02200A18
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r2, #0
	cmp r1, #1
	bne _02200A32
	mov r0, #0x56
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	b _02200A40
_02200A32:
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_02200A40:
	cmp r4, #1
	bne _02200A54
	mov r0, #0x57
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	pop {r3, r4, r5, pc}
_02200A54:
	mov r0, #0x57
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02200A18


	thumb_func_start ov96_02200A64
ov96_02200A64: ; 0x02200A64
	push {r4, r5, r6, lr}
	add r6, r1, #0
	add r5, r0, #0
	add r0, r6, #0
	mov r1, #0x1e
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r6, #0
	mov r1, #0x1e
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x64
	mul r0, r1
	mov r1, #0x1e
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r4, #0
	mov r1, #0x3c
	bl _s32_div_f
	add r1, r0, #0
	mov r0, #0x5f
	lsl r0, r0, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0x3c
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r1, r0, #0
	mov r0, #0x61
	lsl r0, r0, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	mov r0, #0x62
	lsl r0, r0, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r6, #0
	mov r1, #0xa
	bl _s32_div_f
	add r1, r0, #0
	mov r0, #0x19
	lsl r0, r0, #4
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_02200A64


	thumb_func_start ov96_02200B04
ov96_02200B04: ; 0x02200B04
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r7, r1, #0
	mov r6, #0
	add r4, r5, #0
_02200B10:
	mov r0, #0x5f
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	bl Sprite_SetDrawPriority
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #6
	blt _02200B10
	mov r6, #0
	add r4, r5, #0
_02200B28:
	mov r0, #0x15
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_021EB5B8
	mov r1, #2
	bl Sprite_SetDrawPriority
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #2
	blt _02200B28
	mov r0, #1
	mov r2, #0
	add r1, sp, #4
_02200B46:
	cmp r2, r7
	bne _02200B4C
	strb r2, [r1]
_02200B4C:
	add r2, r2, #1
	cmp r2, #4
	blt _02200B46
	mov r2, #0
	add r4, sp, #4
	add r3, sp, #4
_02200B58:
	ldrb r1, [r3]
	cmp r1, r2
	beq _02200B68
	add r1, r0, #0
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	strb r2, [r4, r1]
_02200B68:
	add r2, r2, #1
	cmp r2, #4
	blt _02200B58
	mov r0, #4
	mov r7, #0
	mov r6, #3
	add r4, sp, #4
	str r0, [sp]
_02200B78:
	ldrb r0, [r4]
	add r1, r6, #0
	lsl r0, r0, #5
	add r0, r5, r0
	ldr r0, [r0, #0x4c]
	bl ov96_021EB630
	ldrb r0, [r4]
	add r1, r6, #0
	lsl r0, r0, #5
	add r0, r5, r0
	ldr r0, [r0, #0x50]
	bl ov96_021EB630
	ldrb r0, [r4]
	ldr r1, [sp]
	lsl r0, r0, #5
	add r0, r5, r0
	ldr r0, [r0, #0x48]
	bl ov96_021EB630
	ldrb r0, [r4]
	add r1, r7, #0
	add r1, #0xb
	lsl r0, r0, #5
	add r0, r5, r0
	ldr r0, [r0, #0x54]
	bl ov96_021EB630
	ldr r0, [sp]
	add r7, r7, #1
	add r0, r0, #2
	add r6, r6, #2
	add r4, r4, #1
	str r0, [sp]
	cmp r7, #4
	blt _02200B78
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02200B04

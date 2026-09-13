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

	thumb_func_start ov96_02206380
ov96_02206380: ; 0x02206380
	push {r4, r5, r6, r7, lr}
	sub sp, #0x9c
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	add r4, r2, #0
	str r3, [sp, #0x1c]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x1c]
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #0x5c]
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x60]
	ldr r0, [sp, #0x18]
	lsl r1, r0, #2
	ldr r0, [sp, #0x5c]
	ldr r2, [r0, r1]
	ldr r0, _022066F4 ; =0x000001FF
	add r1, r2, #0
	and r1, r0
	str r1, [sp, #0x68]
	lsr r1, r2, #9
	and r1, r0
	str r1, [sp, #0x64]
	ldr r1, [sp, #0x5c]
	ldr r2, [r1, #0x14]
	mov r1, #1
	lsr r3, r2, #0x12
	and r3, r1
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	beq _02206454
	add r6, r2, #0
	lsr r2, r2, #9
	add r5, r2, #0
	and r6, r0
	and r5, r0
	ldr r0, _022066F8 ; =0x00000518
	ldr r2, [sp, #0x60]
	ldrb r2, [r2, r0]
	lsl r3, r2, #2
	ldr r2, [sp, #0x60]
	add r3, r2, r3
	add r2, r0, #0
	add r2, #0xc
	str r6, [r3, r2]
	ldr r2, [sp, #0x60]
	ldrb r2, [r2, r0]
	lsl r3, r2, #2
	ldr r2, [sp, #0x60]
	add r3, r2, r3
	add r2, r0, #0
	add r2, #0x1c
	str r5, [r3, r2]
	ldr r2, [sp, #0x60]
	ldrb r0, [r2, r0]
	lsl r2, r0, #2
	ldr r0, [sp, #0x60]
	add r2, r0, r2
	mov r0, #0xd3
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r1, _022066F8 ; =0x00000518
	ldr r0, [sp, #0x60]
	ldrb r0, [r0, r1]
	lsl r1, r0, #2
	ldr r0, [sp, #0x60]
	add r1, r0, r1
	mov r0, #0xd3
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #7
	bl ov96_021EB564
	ldr r0, _022066F8 ; =0x00000518
	ldr r1, [sp, #0x60]
	add r6, #0x80
	ldrb r1, [r1, r0]
	add r5, #0x60
	add r1, r1, #1
	lsr r3, r1, #0x1f
	lsl r2, r1, #0x1e
	sub r2, r2, r3
	mov r1, #0x1e
	ror r2, r1
	add r2, r3, r2
	ldr r1, [sp, #0x60]
	mov r3, #1
	strb r2, [r1, r0]
	ldr r0, [sp, #0x68]
	ldr r1, [sp, #0x64]
	ldr r2, _022066FC ; =0x000008A3
	sub r0, r6, r0
	sub r1, r5, r1
	bl ov96_02207C38
_02206454:
	ldr r0, [sp, #0x5c]
	ldr r0, [r0, #0x14]
	lsr r1, r0, #0x13
	mov r0, #0xf
	and r0, r1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0x34]
	asr r1, r0
	mov r0, #1
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _02206478
	ldr r0, _02206700 ; =0x000008CE
	mov r1, #3
	bl sub_0200606C
_02206478:
	ldr r0, [sp, #0x5c]
	mov r1, #1
	ldr r0, [r0, #0x10]
	lsr r2, r0, #0x12
	and r2, r1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	beq _02206510
	add r6, r0, #0
	ldr r2, _022066F4 ; =0x000001FF
	lsr r0, r0, #9
	add r5, r0, #0
	and r6, r2
	and r5, r2
	ldr r0, _02206704 ; =0x0000051A
	ldr r2, [sp, #0x60]
	ldrb r2, [r2, r0]
	lsl r3, r2, #2
	ldr r2, [sp, #0x60]
	add r3, r2, r3
	add r2, r0, #0
	add r2, #0x2a
	str r6, [r3, r2]
	ldr r2, [sp, #0x60]
	ldrb r2, [r2, r0]
	lsl r3, r2, #2
	ldr r2, [sp, #0x60]
	add r3, r2, r3
	add r2, r0, #0
	add r2, #0x3a
	str r5, [r3, r2]
	ldr r2, [sp, #0x60]
	ldrb r0, [r2, r0]
	lsl r2, r0, #2
	ldr r0, [sp, #0x60]
	add r2, r0, r2
	mov r0, #0xd7
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r1, _02206704 ; =0x0000051A
	ldr r0, [sp, #0x60]
	ldrb r0, [r0, r1]
	lsl r1, r0, #2
	ldr r0, [sp, #0x60]
	add r1, r0, r1
	mov r0, #0xd7
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #4
	bl ov96_021EB564
	ldr r0, _02206704 ; =0x0000051A
	ldr r1, [sp, #0x60]
	add r6, #0x80
	ldrb r1, [r1, r0]
	add r5, #0x60
	add r1, r1, #1
	lsr r3, r1, #0x1f
	lsl r2, r1, #0x1e
	sub r2, r2, r3
	mov r1, #0x1e
	ror r2, r1
	add r2, r3, r2
	ldr r1, [sp, #0x60]
	mov r3, #1
	strb r2, [r1, r0]
	ldr r0, [sp, #0x68]
	ldr r1, [sp, #0x64]
	ldr r2, _02206708 ; =0x000008CD
	sub r0, r6, r0
	sub r1, r5, r1
	bl ov96_02207C38
_02206510:
	ldr r5, [sp, #0x60]
	mov r7, #0
	add r6, sp, #0x90
_02206516:
	mov r0, #0
	str r0, [r6]
	str r0, [r6, #4]
	str r0, [r6, #8]
	ldr r0, _0220670C ; =0x00000534
	ldr r1, [r5, r0]
	ldr r0, [sp, #0x64]
	add r1, #0x60
	sub r0, r1, r0
	ldr r1, _02206710 ; =0x00000524
	lsl r0, r0, #0xc
	ldr r2, [r5, r1]
	ldr r1, [sp, #0x68]
	add r2, #0x80
	sub r1, r2, r1
	lsl r1, r1, #0xc
	str r0, [sp, #0x94]
	mov r0, #0xd3
	str r1, [sp, #0x90]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	bl ov96_021EB588
	add r7, r7, #1
	add r5, r5, #4
	cmp r7, #4
	blt _02206516
	ldr r5, [sp, #0x60]
	mov r7, #0
	add r6, sp, #0x84
_02206554:
	mov r0, #0
	str r0, [r6]
	str r0, [r6, #4]
	str r0, [r6, #8]
	ldr r0, _02206714 ; =0x00000554
	ldr r1, [r5, r0]
	ldr r0, [sp, #0x64]
	add r1, #0x60
	sub r0, r1, r0
	ldr r1, _02206718 ; =0x00000544
	lsl r0, r0, #0xc
	ldr r2, [r5, r1]
	ldr r1, [sp, #0x68]
	add r2, #0x80
	sub r1, r2, r1
	lsl r1, r1, #0xc
	str r0, [sp, #0x88]
	mov r0, #0xd7
	str r1, [sp, #0x84]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	bl ov96_021EB588
	add r7, r7, #1
	add r5, r5, #4
	cmp r7, #4
	blt _02206554
	ldr r0, [sp, #0x60]
	bl ov96_022076E4
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _0220659E
	mov r0, #1
	str r0, [sp, #0x20]
	b _022065A2
_0220659E:
	mov r0, #0
	str r0, [sp, #0x20]
_022065A2:
	ldr r0, [sp, #0x5c]
	mov r6, #0
	str r0, [sp, #0x44]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x3c]
	add r0, #0x50
	str r0, [sp, #0x3c]
_022065B2:
	ldr r0, [sp, #0x44]
	mov r2, #3
	ldr r1, [r0]
	ldr r0, _022066F4 ; =0x000001FF
	add r7, r1, #0
	lsr r1, r1, #9
	and r7, r0
	and r0, r1
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x40]
	ldrh r0, [r0, #0x18]
	asr r1, r0, #5
	and r1, r2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #0x30]
	asr r1, r0, #7
	and r1, r2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #0x54]
	asr r1, r0, #9
	mov r0, #1
	and r1, r0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #0x4c]
	ldr r1, [sp, #0x5c]
	ldr r1, [r1, #0x10]
	lsr r2, r1, #0x13
	mov r1, #0xf
	and r1, r2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	asr r1, r6
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x30]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	str r0, [sp, #0x58]
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetParticipantCount
	cmp r0, r6
	bgt _02206622
	ldr r0, [sp, #0x3c]
	mov r5, #1
	bl ov96_021E8A20
	b _0220662A
_02206622:
	ldr r0, [sp, #0x1c]
	mov r5, #0
	bl ov96_021E8A20
_0220662A:
	ldr r1, [sp, #0x18]
	cmp r1, r6
	bne _02206658
	ldr r1, [sp, #0x30]
	lsl r3, r6, #0x18
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [sp, #0x20]
	mov r1, #0x37
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x60]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	ldr r2, [sp, #0x5c]
	add r1, r4, #0
	lsr r3, r3, #0x18
	bl ov96_02206DEC
	b _0220667C
_02206658:
	ldr r1, [sp, #0x30]
	lsl r3, r6, #0x18
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [sp, #0x20]
	mov r1, #0x37
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x60]
	str r5, [sp, #0x10]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	ldr r2, [sp, #0x5c]
	add r1, r4, #0
	lsr r3, r3, #0x18
	bl ov96_02206DEC
_0220667C:
	ldr r0, [sp, #0x68]
	ldr r1, [sp, #0x48]
	sub r0, r7, r0
	str r0, [sp, #0x38]
	add r0, #0x80
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x64]
	sub r1, r1, r0
	mov r0, #0x70
	ldrsh r0, [r4, r0]
	add r1, #0x60
	add r0, r1, r0
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x38]
	mov r1, #0x37
	lsl r0, r0, #0xc
	str r0, [sp, #0x2c]
	str r0, [sp, #0x78]
	ldr r0, [sp, #0x24]
	lsl r1, r1, #4
	lsl r0, r0, #0xc
	str r0, [sp, #0x28]
	str r0, [sp, #0x7c]
	mov r0, #0
	str r0, [sp, #0x80]
	ldr r0, [sp, #0x4c]
	str r0, [sp]
	ldr r0, [sp, #0x60]
	ldr r2, [sp, #0x30]
	ldr r0, [r0, r1]
	lsl r1, r6, #0x18
	ldr r3, [sp, #0x50]
	lsr r1, r1, #0x18
	bl ov96_02208658
	ldr r0, [sp, #0x50]
	cmp r0, #0
	bne _02206724
	mov r1, #0x1f
	ldr r0, [sp, #0x38]
	mvn r1, r1
	cmp r0, r1
	blt _022066DA
	mov r1, #0x12
	lsl r1, r1, #4
	cmp r0, r1
	ble _022066E8
_022066DA:
	mov r1, #0x1f
	ldr r0, [sp, #0x24]
	mvn r1, r1
	cmp r0, r1
	blt _0220671C
	cmp r0, #0xe0
	bgt _0220671C
_022066E8:
	ldr r0, [sp, #0x58]
	mov r1, #1
	bl ov96_021EAB38
	b _02206724
	nop
_022066F4: .word 0x000001FF
_022066F8: .word 0x00000518
_022066FC: .word 0x000008A3
_02206700: .word 0x000008CE
_02206704: .word 0x0000051A
_02206708: .word 0x000008CD
_0220670C: .word 0x00000534
_02206710: .word 0x00000524
_02206714: .word 0x00000554
_02206718: .word 0x00000544
_0220671C:
	ldr r0, [sp, #0x58]
	mov r1, #0
	bl ov96_021EAB38
_02206724:
	mov r7, #0
	add r5, r4, #0
_02206728:
	ldr r0, [r5]
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x24]
	bl ov96_021EAF94
	add r7, r7, #1
	add r5, r5, #4
	cmp r7, #3
	blt _02206728
	add r1, sp, #0x6c
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [sp, #0x2c]
	add r1, r6, #0
	str r0, [sp, #0x6c]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0x70]
	ldr r0, [sp, #0x14]
	ldr r2, [sp, #0x30]
	bl ov96_021E60C0
	ldrb r0, [r0, #5]
	cmp r0, #0
	beq _02206768
	mov r0, #6
	ldr r1, [sp, #0x70]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #0x70]
	b _02206772
_02206768:
	mov r0, #1
	ldr r1, [sp, #0x70]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x70]
_02206772:
	ldr r0, [r4, #0x48]
	add r1, sp, #0x6c
	bl ov96_021EB588
	ldr r1, [sp, #0x24]
	add r0, r4, #0
	bl ov96_02207718
	ldr r0, [sp, #0x50]
	cmp r0, #0
	bne _02206854
	ldr r0, [sp, #0x4c]
	mov r5, #0
	cmp r0, #1
	bne _02206812
	add r0, r4, #0
	add r0, #0xa3
	ldrb r1, [r0]
	ldr r0, [sp, #0x4c]
	cmp r0, r1
	beq _022067A6
	mov r1, #1
	ldr r0, [r4, #0x48]
	add r2, r1, #0
	bl ov96_021EB52C
_022067A6:
	ldr r0, [sp, #0x58]
	mov r1, #0x15
	bl ov96_021EAC5C
	add r0, r4, #0
	mov r1, #0
	add r0, #0x72
	strb r1, [r0]
	ldr r0, [sp, #0x34]
	mov r5, #1
	cmp r0, r6
	bne _022067E8
	mov r0, #3
	bl sub_02006190
	cmp r0, #0
	bne _0220681C
	ldr r1, [sp, #0x78]
	ldr r2, [sp, #0x7c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	mov r2, #0x89
	asr r0, r0, #0xc
	asr r1, r1, #0xc
	lsl r2, r2, #4
	add r3, r5, #0
	bl ov96_02207C38
	b _0220681C
_022067E8:
	mov r0, #4
	bl sub_02006190
	cmp r0, #0
	bne _0220681C
	ldr r1, [sp, #0x78]
	ldr r2, [sp, #0x7c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	mov r2, #0x89
	asr r0, r0, #0xc
	asr r1, r1, #0xc
	lsl r2, r2, #4
	mov r3, #0
	bl ov96_02207C38
	b _0220681C
_02206812:
	ldr r0, [r4, #0x48]
	mov r1, #1
	add r2, r5, #0
	bl ov96_021EB52C
_0220681C:
	cmp r5, #0
	bne _02206866
	ldr r0, [sp, #0x58]
	ldr r1, [sp, #0x54]
	bl ov96_021EAC08
	add r0, r4, #0
	add r0, #0x72
	ldrb r0, [r0]
	cmp r0, #0
	beq _0220684A
	ldr r0, [sp, #0x58]
	mov r1, #0x1a
	bl ov96_021EAC5C
	add r0, r4, #0
	add r0, #0x72
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x72
	strb r1, [r0]
	b _02206866
_0220684A:
	ldr r0, [sp, #0x58]
	mov r1, #0
	bl ov96_021EAC5C
	b _02206866
_02206854:
	ldr r0, [r4, #0x48]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, [sp, #0x58]
	ldr r1, [sp, #0x54]
	bl ov96_021EAC0C
_02206866:
	add r1, r4, #0
	ldr r0, [sp, #0x4c]
	add r1, #0xa3
	strb r0, [r1]
	ldr r0, [sp, #0x44]
	ldr r0, [r0]
	lsr r1, r0, #0x1c
	mov r0, #0xf
	and r0, r1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	mov r1, #0x37
	ldr r0, [sp, #0x60]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	add r1, r6, #0
	add r2, r5, #0
	bl ov96_02208840
	add r0, r4, #0
	add r0, #0x73
	ldrb r1, [r0]
	cmp r1, r5
	bhs _022068F2
	add r0, r4, #0
	mov r1, #0xa
	add r0, #0x72
	strb r1, [r0]
	ldr r0, [r4, #0x54]
	mov r1, #8
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r4, #0x54]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [sp, #0x34]
	cmp r0, r6
	bne _022068D4
	ldr r1, [sp, #0x78]
	ldr r2, [sp, #0x7c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r2, _02206A14 ; =0x000005E2
	asr r0, r0, #0xc
	asr r1, r1, #0xc
	mov r3, #1
	bl ov96_02207C38
	b _0220690E
_022068D4:
	ldr r1, [sp, #0x78]
	ldr r2, [sp, #0x7c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r2, _02206A18 ; =0x000005EB
	asr r0, r0, #0xc
	asr r1, r1, #0xc
	mov r3, #0
	bl ov96_02207C38
	b _0220690E
_022068F2:
	ldr r0, [sp, #0x50]
	cmp r0, #0
	bne _0220690E
	cmp r1, r5
	bls _0220690E
	ldr r0, [r4, #0x54]
	mov r1, #9
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r4, #0x54]
	add r2, r1, #0
	bl ov96_021EB52C
_0220690E:
	add r0, r4, #0
	add r0, #0x73
	strb r5, [r0]
	ldr r0, [r4, #0x54]
	add r1, sp, #0x78
	bl ov96_021EB588
	ldr r0, [sp, #0x44]
	ldr r1, _02206A1C ; =0x000003FF
	ldr r0, [r0]
	lsr r0, r0, #0x12
	and r0, r1
	lsl r0, r0, #0x10
	lsr r7, r0, #0x10
	ldr r0, [sp, #0x18]
	cmp r0, r6
	bne _0220693C
	ldr r0, [sp, #0x60]
	sub r1, #0x8f
	ldr r0, [r0, r1]
	add r1, r7, #0
	bl ov96_02208374
_0220693C:
	add r0, r4, #0
	add r0, #0xae
	ldrh r0, [r0]
	cmp r0, r7
	bhs _022069D4
	add r0, r4, #0
	add r0, #0x78
	ldrh r0, [r0]
	mov r1, #3
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #0x4c]
	bl ov96_021EB564
	add r0, r4, #0
	add r0, #0x78
	ldrh r0, [r0]
	mov r1, #1
	add r2, r1, #0
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #0x4c]
	bl ov96_021EB52C
	add r0, r4, #0
	add r0, #0x78
	ldrh r0, [r0]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r4, #0
	add r1, r2, r1
	add r0, #0x78
	strh r1, [r0]
	mov r1, #0x37
	ldr r0, [sp, #0x60]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	add r1, r6, #0
	bl ov96_02208864
	ldr r0, [sp, #0x34]
	cmp r0, r6
	bne _022069B8
	ldr r1, [sp, #0x78]
	ldr r2, [sp, #0x7c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r2, _02206A20 ; =0x0000088F
	asr r0, r0, #0xc
	asr r1, r1, #0xc
	mov r3, #1
	bl ov96_02207C38
	b _022069D4
_022069B8:
	ldr r1, [sp, #0x78]
	ldr r2, [sp, #0x7c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r2, _02206A20 ; =0x0000088F
	asr r0, r0, #0xc
	asr r1, r1, #0xc
	mov r3, #0
	bl ov96_02207C38
_022069D4:
	mov r5, #0
_022069D6:
	lsl r0, r5, #2
	add r0, r4, r0
	ldr r0, [r0, #0x4c]
	add r1, sp, #0x78
	bl ov96_021EB588
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #2
	blo _022069D6
	add r0, r4, #0
	add r0, #0xae
	strh r7, [r0]
	ldr r0, [sp, #0x44]
	add r6, r6, #1
	add r0, r0, #4
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x40]
	add r4, #0xb8
	add r0, r0, #2
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x3c]
	add r0, #0x28
	str r0, [sp, #0x3c]
	cmp r6, #4
	bge _02206A0E
	b _022065B2
_02206A0E:
	add sp, #0x9c
	pop {r4, r5, r6, r7, pc}
	nop
_02206A14: .word 0x000005E2
_02206A18: .word 0x000005EB
_02206A1C: .word 0x000003FF
_02206A20: .word 0x0000088F
	thumb_func_end ov96_02206380

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


	thumb_func_start ov96_02206A24
ov96_02206A24: ; 0x02206A24
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	mov r7, #0
_02206A30:
	mov r0, #0xc
	add r1, r7, #0
	mul r1, r0
	ldr r0, [sp]
	add r5, r0, r1
	mov r0, #0xdf
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02206AB6
	mov r0, #0xe1
	lsl r0, r0, #2
	ldrh r1, [r5, r0]
	ldr r0, [sp, #4]
	sub r6, r1, r0
	ldr r0, _02206ABC ; =0x00000386
	add r6, #0x80
	ldrh r1, [r5, r0]
	ldr r0, [sp, #8]
	sub r4, r1, r0
	mov r0, #0
	str r0, [sp, #0x14]
	lsl r0, r6, #0xc
	add r4, #0x60
	str r0, [sp, #0xc]
	lsl r0, r4, #0xc
	str r0, [sp, #0x10]
	mov r0, #0xe
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r1, sp, #0xc
	bl ov96_021EB588
	mov r0, #0x1f
	mvn r0, r0
	cmp r6, r0
	blt _02206A9E
	mov r0, #0x12
	lsl r0, r0, #4
	cmp r6, r0
	bgt _02206A9E
	mov r0, #0x1f
	mvn r0, r0
	cmp r4, r0
	blt _02206A9E
	cmp r4, #0xe0
	bgt _02206A9E
	mov r0, #0xe
	lsl r0, r0, #6
	mov r1, #1
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	b _02206AAC
_02206A9E:
	mov r0, #0xe
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_02206AAC:
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #0x14
	blo _02206A30
_02206AB6:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02206ABC: .word 0x00000386
	thumb_func_end ov96_02206A24


	thumb_func_start ov96_02206AC0
ov96_02206AC0: ; 0x02206AC0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	mov r7, #0
_02206ACC:
	ldr r0, [sp]
	lsl r1, r7, #4
	add r5, r0, r1
	ldr r0, _02206B70 ; =0x0000046C
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02206B6C
	ldr r0, _02206B74 ; =0x00000478
	ldrh r1, [r5, r0]
	ldr r0, [sp, #4]
	sub r6, r1, r0
	ldr r0, _02206B78 ; =0x0000047A
	add r6, #0x80
	ldrh r1, [r5, r0]
	ldr r0, [sp, #8]
	sub r4, r1, r0
	mov r0, #0
	str r0, [sp, #0x14]
	lsl r0, r6, #0xc
	add r4, #0x60
	str r0, [sp, #0xc]
	lsl r0, r4, #0xc
	str r0, [sp, #0x10]
	mov r0, #0x47
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, sp, #0xc
	bl ov96_021EB588
	ldr r0, _02206B7C ; =0x00000474
	add r1, sp, #0xc
	ldr r0, [r5, r0]
	bl ov96_021EB588
	mov r0, #0x1f
	mvn r0, r0
	cmp r6, r0
	blt _02206B48
	mov r0, #0x12
	lsl r0, r0, #4
	cmp r6, r0
	bgt _02206B48
	mov r0, #0x1f
	mvn r0, r0
	cmp r4, r0
	blt _02206B48
	cmp r4, #0xe0
	bgt _02206B48
	mov r0, #0x47
	lsl r0, r0, #4
	mov r1, #1
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, _02206B7C ; =0x00000474
	mov r1, #1
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	b _02206B62
_02206B48:
	mov r0, #0x47
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, _02206B7C ; =0x00000474
	mov r1, #1
	ldr r0, [r5, r0]
	mov r2, #0
	bl ov96_021EB52C
_02206B62:
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #0xa
	blo _02206ACC
_02206B6C:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02206B70: .word 0x0000046C
_02206B74: .word 0x00000478
_02206B78: .word 0x0000047A
_02206B7C: .word 0x00000474
	thumb_func_end ov96_02206AC0


	thumb_func_start ov96_02206B80
ov96_02206B80: ; 0x02206B80
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	ldr r0, _02206C78 ; =0x00000564
	str r1, [sp]
	add r0, r5, r0
	str r2, [sp, #4]
	str r3, [sp, #8]
	mov r4, #0
	str r0, [sp, #0x18]
_02206B94:
	ldr r0, [sp]
	lsl r1, r4, #1
	add r0, r0, r1
	ldrh r1, [r0, #0x18]
	mov r0, #0x1f
	and r0, r1
	str r0, [sp, #0x14]
	lsl r0, r0, #2
	ldr r1, _02206C7C ; =0x000005C8
	add r0, r5, r0
	ldrh r2, [r0, r1]
	ldr r1, [sp, #4]
	sub r7, r2, r1
	ldr r1, _02206C80 ; =0x000005CA
	add r7, #0x80
	ldrh r1, [r0, r1]
	ldr r0, [sp, #8]
	sub r6, r1, r0
	mov r0, #0
	str r0, [sp, #0x24]
	lsl r0, r7, #0xc
	add r6, #0x60
	str r0, [sp, #0x1c]
	lsl r0, r6, #0xc
	str r0, [sp, #0x20]
	mov r0, #0x14
	mul r0, r4
	add r1, r5, r0
	str r0, [sp, #0x10]
	ldr r0, _02206C84 ; =0x00000568
	str r1, [sp, #0xc]
	ldr r0, [r1, r0]
	add r1, sp, #0x1c
	bl ov96_021EB588
	ldr r1, [sp, #0xc]
	ldr r0, _02206C88 ; =0x0000056C
	ldr r0, [r1, r0]
	add r1, sp, #0x1c
	bl ov96_021EB588
	mov r0, #0x1f
	mvn r0, r0
	cmp r7, r0
	blt _02206C22
	mov r0, #0x12
	lsl r0, r0, #4
	cmp r7, r0
	bgt _02206C22
	mov r0, #0x1f
	mvn r0, r0
	cmp r6, r0
	blt _02206C22
	cmp r6, #0xe0
	bgt _02206C22
	mov r0, #0x14
	mul r0, r4
	add r7, r5, r0
	ldr r0, _02206C84 ; =0x00000568
	mov r1, #1
	ldr r0, [r7, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, _02206C88 ; =0x0000056C
	mov r1, #1
	ldr r0, [r7, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	b _02206C40
_02206C22:
	mov r0, #0x14
	mul r0, r4
	add r7, r5, r0
	ldr r0, _02206C84 ; =0x00000568
	mov r1, #1
	ldr r0, [r7, r0]
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, _02206C88 ; =0x0000056C
	mov r1, #1
	ldr r0, [r7, r0]
	mov r2, #0
	bl ov96_021EB52C
_02206C40:
	ldr r0, _02206C8C ; =0x00000513
	add r7, r5, r4
	ldrb r1, [r7, r0]
	ldr r0, [sp, #0x14]
	cmp r0, r1
	beq _02206C5E
	ldr r1, [sp, #0xc]
	ldr r0, _02206C88 ; =0x0000056C
	ldr r0, [r1, r0]
	mov r1, #4
	bl ov96_021EB564
	ldr r1, [sp, #0x14]
	ldr r0, _02206C8C ; =0x00000513
	strb r1, [r7, r0]
_02206C5E:
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x10]
	add r0, r1, r0
	add r1, r6, #0
	bl ov96_022076C0
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #5
	blo _02206B94
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02206C78: .word 0x00000564
_02206C7C: .word 0x000005C8
_02206C80: .word 0x000005CA
_02206C84: .word 0x00000568
_02206C88: .word 0x0000056C
_02206C8C: .word 0x00000513
	thumb_func_end ov96_02206B80


	thumb_func_start ov96_02206C90
ov96_02206C90: ; 0x02206C90
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r1, #0x9f
	ldrb r1, [r1]
	ldr r5, [sp, #0x10]
	cmp r1, #3
	bhi _02206D54
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02206CAA: ; jump table
	.short _02206CB2 - _02206CAA - 2 ; case 0
	.short _02206CC8 - _02206CAA - 2 ; case 1
	.short _02206D04 - _02206CAA - 2 ; case 2
	.short _02206D54 - _02206CAA - 2 ; case 3
_02206CB2:
	add r0, r4, #0
	mov r1, #0
	add r0, #0xa0
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	add r4, #0x9f
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, pc}
_02206CC8:
	mov r0, #0x70
	ldrsh r1, [r4, r0]
	add r0, r4, #0
	add r0, #0x70
	add r1, #8
	strh r1, [r0]
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xa0
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #0x20
	blo _02206D54
	lsl r0, r3, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov96_021EAB38
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	add r4, #0x9f
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, pc}
_02206D04:
	ldr r1, [sp, #0x18]
	cmp r1, #0
	beq _02206D26
	add r1, r3, #0
	bl ov96_02208448
	cmp r0, #0
	beq _02206D54
	mov r0, #1
	strb r0, [r5, #8]
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	add r4, #0x9f
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, pc}
_02206D26:
	ldr r1, [sp, #0x14]
	cmp r1, #0
	beq _02206D48
	add r1, r2, #0
	bl ov96_02208608
	cmp r0, #0
	beq _02206D54
	mov r0, #1
	strb r0, [r5, #8]
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	add r4, #0x9f
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, pc}
_02206D48:
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	add r4, #0x9f
	add r0, r0, #1
	strb r0, [r4]
_02206D54:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02206C90


	thumb_func_start ov96_02206D58
ov96_02206D58: ; 0x02206D58
	push {r4, lr}
	add r4, r0, #0
	add r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #3
	bhi _02206DE8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02206D70: ; jump table
	.short _02206D78 - _02206D70 - 2 ; case 0
	.short _02206D98 - _02206D70 - 2 ; case 1
	.short _02206DD2 - _02206D70 - 2 ; case 2
	.short _02206DE8 - _02206D70 - 2 ; case 3
_02206D78:
	add r0, r4, #0
	mov r1, #0
	add r0, #0xa0
	strb r1, [r0]
	lsl r0, r2, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov96_021EAB38
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	add r4, #0x9f
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02206D98:
	mov r0, #0x70
	ldrsh r1, [r4, r0]
	add r0, r4, #0
	add r0, #0x70
	sub r1, #8
	strh r1, [r0]
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xa0
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #0x20
	blo _02206DE8
	add r0, r4, #0
	mov r1, #0
	add r0, #0x70
	strh r1, [r0]
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	add r4, #0x9f
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02206DD2:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02206DDC
	mov r0, #2
	strb r0, [r3, #8]
_02206DDC:
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	add r4, #0x9f
	add r0, r0, #1
	strb r0, [r4]
_02206DE8:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02206D58


	thumb_func_start ov96_02206DEC
ov96_02206DEC: ; 0x02206DEC
	push {r3, r4, lr}
	sub sp, #0xc
	ldr r2, [r2, #0x10]
	lsr r2, r2, #0x17
	lsl r2, r2, #0x18
	lsr r4, r2, #0x18
	lsl r2, r3, #1
	asr r4, r2
	mov r2, #3
	and r2, r4
	lsl r2, r2, #0x18
	lsr r4, r2, #0x18
	add r2, r1, #0
	add r2, #0x9e
	ldrb r2, [r2]
	cmp r2, r4
	beq _02206E1C
	add r2, r1, #0
	add r2, #0x9e
	strb r4, [r2]
	add r2, r1, #0
	mov r4, #0
	add r2, #0x9f
	strb r4, [r2]
_02206E1C:
	add r2, r1, #0
	add r2, #0x9e
	ldrb r2, [r2]
	cmp r2, #0
	beq _02206E82
	cmp r2, #1
	beq _02206E32
	cmp r2, #2
	beq _02206E5C
	add sp, #0xc
	pop {r3, r4, pc}
_02206E32:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq _02206E42
	ldr r2, [sp, #0x28]
	cmp r2, #0
	beq _02206E42
	mov r4, #1
	b _02206E44
_02206E42:
	mov r4, #0
_02206E44:
	ldr r2, [sp, #0x1c]
	str r2, [sp]
	ldr r2, [sp, #0x24]
	str r4, [sp, #4]
	str r2, [sp, #8]
	add r2, r3, #0
	add r3, sp, #8
	ldrb r3, [r3, #0x10]
	bl ov96_02206C90
	add sp, #0xc
	pop {r3, r4, pc}
_02206E5C:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _02206E6C
	ldr r0, [sp, #0x28]
	cmp r0, #0
	beq _02206E6C
	mov r2, #1
	b _02206E6E
_02206E6C:
	mov r2, #0
_02206E6E:
	ldr r0, [sp, #0x24]
	orr r0, r2
	str r0, [sp]
	add r2, sp, #8
	add r0, r1, #0
	add r1, r3, #0
	ldrb r2, [r2, #0x10]
	ldr r3, [sp, #0x1c]
	bl ov96_02206D58
_02206E82:
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02206DEC


	thumb_func_start ov96_02206E88
ov96_02206E88: ; 0x02206E88
	push {r3, r4, r5, r6, r7, lr}
	str r3, [sp]
	add r5, r1, #0
	add r1, r2, #0
	ldr r2, [sp]
	ldr r6, [sp, #0x18]
	bl ov96_021E60D8
	add r4, r0, #0
	ldr r0, [sp]
	mov r1, #0x14
	add r7, r0, #0
	ldrb r0, [r4]
	mul r7, r1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl _fflt
	bl _f2d
	ldr r3, _02206F18 ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r6, r7
	str r0, [r1, #0x14]
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x50]
	strb r0, [r1, #0x1c]
	ldrb r0, [r4, #4]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x14]
	bl _fflt
	bl _f2d
	ldr r3, _02206F18 ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r6, r7
	str r0, [r1, #0xc]
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x28]
	bl _fflt
	bl _f2d
	ldr r3, _02206F18 ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r6, r7
	str r0, [r1, #0x10]
	ldrb r0, [r4, #3]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x3c]
	str r0, [r1, #0x18]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02206F18: .word 0x40240000
	thumb_func_end ov96_02206E88


	thumb_func_start ov96_02206F1C
ov96_02206F1C: ; 0x02206F1C
	push {r3, r4, r5, r6, r7, lr}
	mov ip, r3
	mov r3, #0
	ldr r6, [sp, #0x18]
	mov r5, ip
	add r4, r3, #0
_02206F28:
	add r3, r3, #1
	stmia r5!, {r4}
	cmp r3, #0x14
	blt _02206F28
	asr r3, r1, #0xb
	lsr r3, r3, #0x14
	add r3, r1, r3
	asr r1, r3, #0xc
	mov lr, r1
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	asr r7, r1, #0xc
	ldr r1, _02206F9C ; =0x0000061C
	strb r4, [r6]
	add r3, r0, r1
_02206F48:
	mov r1, #0xdf
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	cmp r1, #0
	beq _02206F98
	mov r1, #0xe1
	lsl r1, r1, #2
	ldrh r2, [r0, r1]
	mov r1, lr
	mov r5, #0x1f
	sub r2, r2, r1
	ldr r1, _02206FA0 ; =0x00000386
	add r2, #0x80
	ldrh r1, [r0, r1]
	mvn r5, r5
	sub r1, r1, r7
	add r1, #0x60
	cmp r2, r5
	blt _02206F8E
	mov r5, #0x12
	lsl r5, r5, #4
	cmp r2, r5
	bgt _02206F8E
	mov r2, #0x1f
	mvn r2, r2
	cmp r1, r2
	blt _02206F8E
	cmp r1, #0xe0
	bgt _02206F8E
	ldrb r2, [r6]
	add r1, r2, #1
	strb r1, [r6]
	lsl r2, r2, #2
	mov r1, ip
	str r3, [r1, r2]
_02206F8E:
	add r4, r4, #1
	add r0, #0xc
	add r3, r3, #4
	cmp r4, #0x14
	blt _02206F48
_02206F98:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02206F9C: .word 0x0000061C
_02206FA0: .word 0x00000386
	thumb_func_end ov96_02206F1C


	thumb_func_start ov96_02206FA4
ov96_02206FA4: ; 0x02206FA4
	push {r4, r5}
	ldrh r5, [r1]
	ldrh r4, [r1, #2]
	add r3, r5, #0
	add r1, r4, #0
	sub r3, #0x10
	str r3, [r2]
	sub r1, #0x10
	str r1, [r2, #4]
	add r5, #0x10
	str r5, [r2, #8]
	str r1, [r2, #0xc]
	str r5, [r2, #0x10]
	add r4, #0x10
	str r4, [r2, #0x14]
	str r3, [r2, #0x18]
	str r4, [r2, #0x1c]
	ldr r3, [r2]
	ldr r1, [r2, #4]
	str r3, [r2, #0x20]
	str r1, [r2, #0x24]
	ldr r3, [r2, #8]
	ldr r1, [r2, #0xc]
	str r3, [r2, #0x28]
	str r1, [r2, #0x2c]
	ldr r3, [r2, #8]
	ldr r1, [r2, #0xc]
	str r3, [r2, #0x30]
	str r1, [r2, #0x34]
	ldr r3, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r3, [r2, #0x38]
	str r1, [r2, #0x3c]
	ldr r3, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r3, [r2, #0x40]
	str r1, [r2, #0x44]
	ldr r3, [r2, #0x18]
	ldr r1, [r2, #0x1c]
	str r3, [r2, #0x48]
	str r1, [r2, #0x4c]
	ldr r3, [r2, #0x18]
	ldr r1, [r2, #0x1c]
	str r3, [r2, #0x50]
	str r1, [r2, #0x54]
	ldr r3, [r2]
	ldr r1, [r2, #4]
	str r3, [r2, #0x58]
	str r1, [r2, #0x5c]
	ldr r1, [r2, #0x24]
	sub r1, r1, r0
	str r1, [r2, #0x24]
	ldr r1, [r2, #0x2c]
	sub r1, r1, r0
	str r1, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	add r1, r1, r0
	str r1, [r2, #0x30]
	ldr r1, [r2, #0x38]
	add r1, r1, r0
	str r1, [r2, #0x38]
	ldr r1, [r2, #0x44]
	add r1, r1, r0
	str r1, [r2, #0x44]
	ldr r1, [r2, #0x4c]
	add r1, r1, r0
	str r1, [r2, #0x4c]
	ldr r1, [r2, #0x50]
	sub r1, r1, r0
	str r1, [r2, #0x50]
	add r2, #0x58
	ldr r1, [r2]
	sub r0, r1, r0
	str r0, [r2]
	pop {r4, r5}
	bx lr
	thumb_func_end ov96_02206FA4


	thumb_func_start ov96_0220703C
ov96_0220703C: ; 0x0220703C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xa4
	str r0, [sp, #4]
	ldr r0, [sp, #0xb8]
	str r2, [sp, #0xc]
	str r0, [sp, #0xb8]
	ldr r0, [sp, #4]
	str r1, [sp, #8]
	ldr r1, [r0]
	add r7, r3, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x24]
	ldr r0, [sp, #4]
	add r6, r3, #0
	ldr r1, [r0, #4]
	ldr r2, _022072F8 ; =ov96_0221CB00
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x28]
	ldr r0, [sp, #8]
	str r3, [sp, #0x10]
	ldr r1, [r0]
	add r5, r3, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	add r3, sp, #0x34
	ldr r1, [r0, #4]
	mov r4, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x20]
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	add r7, #0x28
	add r6, #0x20
_0220709C:
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
	beq _022070DA
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
_022070DA:
	mov r0, #0
	cmp r4, #0
	bne _0220710A
	cmp r4, #2
	bne _0220710A
	ldr r2, [sp, #0x28]
	ldr r1, [r5, #0x24]
	cmp r2, r1
	bne _0220712E
	ldr r2, [r5, #0x28]
	ldr r3, [r5, #0x20]
	cmp r3, r2
	bge _022070F8
	add r1, r3, #0
	b _022070FC
_022070F8:
	add r1, r2, #0
	add r2, r3, #0
_022070FC:
	ldr r3, [sp, #0x24]
	cmp r1, r3
	bgt _0220712E
	cmp r3, r2
	bgt _0220712E
	mov r0, #1
	b _0220712E
_0220710A:
	ldr r2, [sp, #0x24]
	ldr r1, [r5, #0x20]
	cmp r2, r1
	bne _0220712E
	ldr r2, [r5, #0x2c]
	ldr r3, [r5, #0x24]
	cmp r3, r2
	bge _0220711E
	add r1, r3, #0
	b _02207122
_0220711E:
	add r1, r2, #0
	add r2, r3, #0
_02207122:
	ldr r3, [sp, #0x28]
	cmp r1, r3
	bgt _0220712E
	cmp r3, r2
	bgt _0220712E
	mov r0, #1
_0220712E:
	cmp r0, #0
	beq _02207150
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
_02207150:
	add r4, r4, #1
	add r7, #0x10
	add r6, #0x10
	add r5, #0x10
	cmp r4, #4
	blt _0220709C
	ldr r3, _022072FC ; =ov96_0221CAE0
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
_02207172:
	add r3, sp, #0x44
	add r2, sp, #0x84
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r4]
	add r1, sp, #0x78
	lsl r0, r0, #0xc
	str r0, [sp, #0x78]
	ldr r0, [r4, #4]
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
	bgt _022071E0
	ldr r3, [sp, #0xc]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	add r2, sp, #0x78
	lsl r3, r3, #0xc
	bl ov96_02207390
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
_022071E0:
	add r5, r5, #1
	add r4, #8
	cmp r5, #4
	blt _02207172
	ldr r0, [sp, #8]
	ldr r1, [r0]
	ldr r0, [sp, #0x10]
	ldr r0, [r0]
	lsl r0, r0, #0xc
	cmp r0, r1
	bgt _022072F2
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x10]
	lsl r0, r0, #0xc
	cmp r1, r0
	bgt _022072F2
	ldr r0, [sp, #8]
	ldr r1, [r0, #4]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #4]
	lsl r0, r0, #0xc
	cmp r0, r1
	bgt _022072F2
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x14]
	lsl r0, r0, #0xc
	cmp r1, r0
	bgt _022072F2
	ldr r3, [sp, #8]
	ldr r2, [sp, #0xb8]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0
	str r0, [r2]
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x10]
	ldr r0, [r0]
	ldr r3, [r3, #0x10]
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
	bge _0220724A
	sub r2, r1, #1
	mul r0, r2
_0220724A:
	cmp r3, #0
	bge _02207254
	mov r2, #0
	mvn r2, r2
	mul r3, r2
_02207254:
	cmp r0, r3
	bge _0220725C
	mov r6, #0xc
	b _02207260
_0220725C:
	add r0, r3, #0
	mov r6, #0xa
_02207260:
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #8]
	ldr r4, [sp, #0x10]
	ldr r2, [r2, #4]
	ldr r5, [r3, #4]
	ldr r7, [r4, #0x14]
	lsl r3, r2, #0xc
	lsl r4, r7, #0xc
	sub r3, r3, r5
	sub r4, r4, r5
	cmp r3, #0
	bge _0220727E
	mov r5, #0
	mvn r5, r5
	mul r3, r5
_0220727E:
	cmp r4, #0
	bge _02207288
	mov r5, #0
	mvn r5, r5
	mul r4, r5
_02207288:
	cmp r3, r4
	bge _02207290
	mov r4, #9
	b _02207294
_02207290:
	add r3, r4, #0
	mov r4, #0xb
_02207294:
	cmp r0, r3
	bgt _022072A0
	mov r0, #1
	mov ip, r0
	add r0, r6, #0
	b _022072A4
_022072A0:
	mov r1, #1
	add r0, r4, #0
_022072A4:
	mov r3, ip
	cmp r3, #0
	beq _022072CE
	cmp r6, #0xc
	bne _022072BE
	ldr r2, [sp, #0x18]
	ldr r1, [sp, #0xc]
	sub r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1]
	pop {r4, r5, r6, r7, pc}
_022072BE:
	ldr r2, [sp, #0x14]
	ldr r1, [sp, #0xc]
	add r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1]
	pop {r4, r5, r6, r7, pc}
_022072CE:
	cmp r1, #0
	beq _022072F4
	cmp r4, #9
	bne _022072E4
	ldr r1, [sp, #0xc]
	sub r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1, #4]
	pop {r4, r5, r6, r7, pc}
_022072E4:
	ldr r1, [sp, #0xc]
	add r1, r7, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1, #4]
	pop {r4, r5, r6, r7, pc}
_022072F2:
	mov r0, #0
_022072F4:
	add sp, #0xa4
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022072F8: .word ov96_0221CB00
_022072FC: .word ov96_0221CAE0
	thumb_func_end ov96_0220703C


	thumb_func_start ov96_02207300
ov96_02207300: ; 0x02207300
	push {r4, r5, r6, r7, lr}
	sub sp, #0xcc
	str r1, [sp, #4]
	ldr r1, [sp, #0xe0]
	add r7, r3, #0
	str r1, [sp, #0xe0]
	ldr r1, [sp, #0xe4]
	add r6, r2, #0
	str r1, [sp, #0xe4]
	add r1, sp, #0xc
	str r1, [sp]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	add r3, sp, #0x7c
	bl ov96_02206F1C
	mov r4, #0
	str r4, [sp, #8]
	add r0, sp, #0xc
	ldrb r0, [r0]
	cmp r0, #0
	ble _02207388
	add r5, sp, #0x7c
_0220732E:
	ldr r1, [r5]
	add r0, r6, #0
	add r2, sp, #0x1c
	bl ov96_02206FA4
	add r0, sp, #0x10
	str r0, [sp]
	ldr r1, [sp, #0xe0]
	add r0, r7, #0
	add r2, r6, #0
	add r3, sp, #0x1c
	bl ov96_0220703C
	cmp r0, #0
	beq _0220737C
	cmp r0, #9
	blt _02207360
	ldr r2, [sp, #0x10]
	ldr r1, [sp, #0xe4]
	str r2, [r1]
	ldr r2, [sp, #0x14]
	str r2, [r1, #4]
	mov r2, #0
	str r2, [r1, #8]
	b _02207374
_02207360:
	ldr r1, [sp, #4]
	cmp r0, r1
	beq _02207374
	ldr r2, [sp, #0x10]
	ldr r1, [sp, #0xe4]
	str r2, [r1]
	ldr r2, [sp, #0x14]
	str r2, [r1, #4]
	mov r2, #0
	str r2, [r1, #8]
_02207374:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	b _02207388
_0220737C:
	add r0, sp, #0xc
	ldrb r0, [r0]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r0
	blt _0220732E
_02207388:
	ldr r0, [sp, #8]
	add sp, #0xcc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02207300


	thumb_func_start ov96_02207390
ov96_02207390: ; 0x02207390
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
	bgt _022073EC
	add r0, r6, #0
_022073EC:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_02207390


	thumb_func_start ov96_022073F0
ov96_022073F0: ; 0x022073F0
	mov r2, #0x14
	mul r2, r1
	add r0, r0, r2
	ldr r3, _022073FC ; =_ffltu
	ldrb r0, [r0, #0x1c]
	bx r3
	.balign 4, 0
_022073FC: .word _ffltu
	thumb_func_end ov96_022073F0

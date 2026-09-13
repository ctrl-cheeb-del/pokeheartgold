	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text
	.public ov96_021F5BA0
	.extern ov96_021F5F34
	.extern ov96_021F5F68
	.extern ov96_021F6088

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


	thumb_func_start ov96_021F5BA0
ov96_021F5BA0: ; 0x021F5BA0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #8]
	bl PokeathlonCourse_GetDataCopyArea
	add r4, r0, #0
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r5, r0, #0
	bl System_GetTouchNew
	cmp r0, #0
	beq _021F5C10
	ldr r0, [sp, #8]
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl ov96_021E8228
	ldr r2, _021F5D38 ; =gSystem + 0x40
	add r0, r5, #0
	ldrh r1, [r2, #0x20]
	ldrh r2, [r2, #0x22]
	bl ov96_021F5F68
	cmp r0, #3
	bhs _021F5CC2
	mov r1, #5
	lsl r1, r1, #6
	ldr r2, _021F5D38 ; =gSystem + 0x40
	strb r0, [r5, r1]
	ldrh r0, [r2, #0x20]
	lsl r3, r0, #0xc
	add r0, r1, #0
	add r0, #0x2c
	str r3, [r5, r0]
	ldrh r0, [r2, #0x22]
	lsl r2, r0, #0xc
	mov r0, #3
	lsl r0, r0, #0x12
	add r2, r2, r0
	add r0, r1, #0
	add r0, #0x30
	str r2, [r5, r0]
	mov r0, #0
	add r1, #0x34
	str r0, [r5, r1]
	b _021F5CC2
_021F5C10:
	bl System_GetTouchHeld
	cmp r0, #0
	beq _021F5C74
	mov r2, #5
	lsl r2, r2, #6
	ldrb r0, [r5, r2]
	cmp r0, #3
	bhs _021F5CC2
	add r0, r2, #1
	ldrb r0, [r5, r0]
	cmp r0, #7
	bhs _021F5C36
	add r0, r2, #1
	ldrb r0, [r5, r0]
	add r1, r0, #1
	add r0, r2, #1
	strb r1, [r5, r0]
	b _021F5CC2
_021F5C36:
	add r3, sp, #0x1c
	mov r0, #0
	str r0, [r3]
	str r0, [r3, #4]
	ldr r1, _021F5D38 ; =gSystem + 0x40
	str r0, [r3, #8]
	ldrh r0, [r1, #0x20]
	ldrh r1, [r1, #0x22]
	add r2, #0x2c
	lsl r0, r0, #0x18
	lsl r1, r1, #0x18
	lsr r0, r0, #0x18
	lsr r1, r1, #0x18
	add r2, r5, r2
	bl ov96_021F5F34
	mov r1, #5
	lsl r1, r1, #6
	ldrb r1, [r5, r1]
	add r0, r5, #0
	add r2, sp, #0x1c
	bl ov96_021F6088
	mov r0, #5
	mov r1, #3
	lsl r0, r0, #6
	strb r1, [r5, r0]
	mov r1, #0
	add r0, r0, #1
	strb r1, [r5, r0]
	b _021F5CC2
_021F5C74:
	mov r2, #5
	lsl r2, r2, #6
	ldrb r0, [r5, r2]
	cmp r0, #3
	bhs _021F5CB4
	add r0, r2, #1
	ldrb r0, [r5, r0]
	cmp r0, #7
	bhs _021F5CB4
	add r3, sp, #0x10
	mov r0, #0
	str r0, [r3]
	str r0, [r3, #4]
	ldr r1, _021F5D38 ; =gSystem + 0x40
	str r0, [r3, #8]
	ldrh r0, [r1, #0x20]
	ldrh r1, [r1, #0x22]
	add r2, #0x2c
	lsl r0, r0, #0x18
	lsl r1, r1, #0x18
	lsr r0, r0, #0x18
	lsr r1, r1, #0x18
	add r2, r5, r2
	bl ov96_021F5F34
	mov r1, #5
	lsl r1, r1, #6
	ldrb r1, [r5, r1]
	add r0, r5, #0
	add r2, sp, #0x10
	bl ov96_021F6088
_021F5CB4:
	mov r0, #5
	mov r1, #3
	lsl r0, r0, #6
	strb r1, [r5, r0]
	mov r1, #0
	add r0, r0, #1
	strb r1, [r5, r0]
_021F5CC2:
	ldr r0, [sp, #8]
	bl ov96_021E5F24
	cmp r0, #0
	bne _021F5D32
	add r0, r4, #0
	add r0, #0x28
	bl ov96_021E8A20
	add r7, r0, #0
	add r0, r4, #0
	add r0, #0x50
	bl ov96_021E8A20
	str r0, [sp, #4]
	add r0, r4, #0
	bl ov96_021E8A20
	add r3, r0, #0
	mov r6, #4
_021F5CEA:
	ldr r2, [sp, #4]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	str r2, [sp, #4]
	sub r6, r6, #1
	bne _021F5CEA
	ldr r1, [r3]
	add r0, r2, #0
	str r1, [r0]
	mov r1, #0x4e
	lsl r1, r1, #2
	ldr r0, [sp, #8]
	ldr r1, [r5, r1]
	bl ov96_021F7740
	mov r6, #0
	add r4, #0x50
	add r5, sp, #0xc
_021F5D0E:
	add r0, r4, #0
	bl ov96_021E8A20
	ldr r0, [r0]
	add r6, r6, #1
	strb r0, [r5]
	add r4, #0x28
	add r5, r5, #1
	cmp r6, #4
	blt _021F5D0E
	mov r2, #0
	add r1, sp, #0xc
_021F5D26:
	ldrb r0, [r1]
	add r1, r1, #1
	strb r0, [r7, r2]
	add r2, r2, #1
	cmp r2, #4
	blt _021F5D26
_021F5D32:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F5D38: .word gSystem + 0x40
	thumb_func_end ov96_021F5BA0




	thumb_func_start ov96_021F5D3C
ov96_021F5D3C: ; 0x021F5D3C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #4]
	ldr r4, [sp, #4]
	ldr r6, [sp, #4]
	mov r0, #0
	ldr r5, _021F5EBC ; =ov96_0221DC18
	str r0, [sp, #0x10]
	add r4, #0x90
	add r7, r6, #0
_021F5D56:
	ldr r0, _021F5EC0 ; =0x00000FB4
	ldr r0, [r6, r0]
	lsl r1, r0, #6
	mov r0, #0x12
	lsl r0, r0, #0x10
	sub r0, r0, r1
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x1c]
	mov r0, #2
	lsl r0, r0, #0x10
	str r1, [r4, #8]
	cmp r1, r0
	bge _021F5D74
	str r0, [r4, #8]
	b _021F5D7E
_021F5D74:
	mov r0, #0xdf
	lsl r0, r0, #0xc
	cmp r1, r0
	ble _021F5D7E
	str r0, [r4, #8]
_021F5D7E:
	ldr r1, [r4, #8]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r0, #0xc
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0x17
	lsr r1, r0, #0x18
	mov r0, #0xfa
	lsl r0, r0, #4
	str r1, [r7, r0]
	ldr r1, [r4, #8]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [r4, #0xc]
	str r0, [sp, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #8]
	ldr r0, [r4]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #8]
	bl ov96_021EAF94
	mov r1, #0
	add r0, sp, #0x14
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [sp, #0xc]
	lsl r0, r0, #0xc
	str r0, [sp, #0x14]
	ldr r0, [sp, #8]
	lsl r0, r0, #0xc
	str r0, [sp, #0x18]
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	ldr r2, [sp, #0x10]
	bl ov96_021E60C0
	ldrb r0, [r0, #5]
	cmp r0, #0
	beq _021F5DF0
	mov r0, #6
	ldr r1, [sp, #0x18]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #0x18]
	b _021F5DFA
_021F5DF0:
	mov r0, #1
	ldr r1, [sp, #0x18]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x18]
_021F5DFA:
	ldr r0, [r4, #4]
	add r1, sp, #0x14
	bl ov96_021EB588
	add r0, r4, #0
	add r0, #0x26
	ldrb r0, [r0]
	cmp r0, #0
	ldr r0, [r4, #4]
	beq _021F5E34
	mov r1, #1
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r4]
	mov r1, #0x14
	bl ov96_021EAD08
	ldrb r0, [r5]
	bl sub_02006190
	cmp r0, #0
	bne _021F5E5E
	ldrb r1, [r5]
	mov r0, #0x89
	lsl r0, r0, #4
	bl sub_0200606C
	b _021F5E5E
_021F5E34:
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, [r4]
	mov r1, #0
	bl ov96_021EAD08
	mov r0, #0x3f
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	cmp r0, #0
	ldr r0, [r4]
	beq _021F5E58
	mov r1, #1
	bl ov96_021EAC0C
	b _021F5E5E
_021F5E58:
	mov r1, #2
	bl ov96_021EAC0C
_021F5E5E:
	ldr r0, [sp, #0x10]
	add r4, #0x38
	add r0, r0, #1
	add r6, #0x1c
	add r7, r7, #4
	add r5, r5, #1
	str r0, [sp, #0x10]
	cmp r0, #3
	bge _021F5E72
	b _021F5D56
_021F5E72:
	ldr r4, [sp, #4]
	mov r1, #0x51
	mov r5, #0
	lsl r1, r1, #2
	add r0, r4, #0
	add r6, r0, r1
	add r7, r5, #0
_021F5E80:
	ldr r0, [sp, #4]
	mov r1, #0x5a
	add r0, r0, r5
	lsl r1, r1, #2
	ldrb r1, [r0, r1]
	cmp r1, #0
	beq _021F5EAE
	mov r1, #0x5a
	lsl r1, r1, #2
	strb r7, [r0, r1]
	mov r1, #1
	ldr r0, [r4, #0x78]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r4, #0x78]
	add r1, r6, #0
	bl ov96_021EB588
	ldr r0, [r4, #0x78]
	mov r1, #9
	bl ov96_021EB564
_021F5EAE:
	add r5, r5, #1
	add r4, r4, #4
	add r6, #0xc
	cmp r5, #3
	blt _021F5E80
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F5EBC: .word ov96_0221DC18
_021F5EC0: .word 0x00000FB4
	thumb_func_end ov96_021F5D3C




	thumb_func_start ov96_021F5EC4
ov96_021F5EC4: ; 0x021F5EC4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	add r7, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp]
	mov r4, #0
	add r5, r0, #0
_021F5EE0:
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r4, r0
	bne _021F5F0A
	ldr r1, [sp]
	ldr r0, _021F5F30 ; =0x00000142
	ldrb r0, [r1, r0]
	cmp r0, #0
	beq _021F5F24
	ldr r0, [r5, #0x68]
	bl ov96_021EB57C
	cmp r0, #0
	bne _021F5F24
	add r1, r4, #0
	ldr r0, [r5, #0x68]
	add r1, #0xd
	bl ov96_021EB564
	b _021F5F24
_021F5F0A:
	ldrb r0, [r7, r4]
	cmp r0, #0
	beq _021F5F24
	ldr r0, [r5, #0x68]
	bl ov96_021EB57C
	cmp r0, #0
	bne _021F5F24
	add r1, r4, #0
	ldr r0, [r5, #0x68]
	add r1, #0xd
	bl ov96_021EB564
_021F5F24:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _021F5EE0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F5F30: .word 0x00000142
	thumb_func_end ov96_021F5EC4

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

	thumb_func_start ov96_02217DC8
ov96_02217DC8: ; 0x02217DC8
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #3
	bhi _02217E00
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02217DDC: ; jump table
	.short _02217E04 - _02217DDC - 2 ; case 0
	.short _02217DE4 - _02217DDC - 2 ; case 1
	.short _02217DEC - _02217DDC - 2 ; case 2
	.short _02217DFA - _02217DDC - 2 ; case 3
_02217DE4:
	mov r1, #1
	bl ov96_02218578
	pop {r4, pc}
_02217DEC:
	mov r1, #7
	bl ov96_02218578
	mov r0, #1
	add r4, #0x59
	strb r0, [r4]
	pop {r4, pc}
_02217DFA:
	bl ov96_02218FFC
	pop {r4, pc}
_02217E00:
	bl GF_AssertFail
_02217E04:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02217DC8


	thumb_func_start ov96_02217E08
ov96_02217E08: ; 0x02217E08
	push {r4, lr}
	ldr r2, [r0, #0x14]
	ldr r1, [r0, #0x18]
	ldr r0, [r0, #0x60]
	mov r4, #0
	lsl r0, r0, #4
	lsr r0, r0, #0x1f
	bne _02217E1C
	add r0, r4, #0
	pop {r4, pc}
_02217E1C:
	cmp r2, #0xc
	bhi _02217E72
	add r0, r2, r2
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02217E2C: ; jump table
	.short _02217E6C - _02217E2C - 2 ; case 0
	.short _02217E60 - _02217E2C - 2 ; case 1
	.short _02217E60 - _02217E2C - 2 ; case 2
	.short _02217E6C - _02217E2C - 2 ; case 3
	.short _02217E6C - _02217E2C - 2 ; case 4
	.short _02217E48 - _02217E2C - 2 ; case 5
	.short _02217E48 - _02217E2C - 2 ; case 6
	.short _02217E48 - _02217E2C - 2 ; case 7
	.short _02217E48 - _02217E2C - 2 ; case 8
	.short _02217E60 - _02217E2C - 2 ; case 9
	.short _02217E6C - _02217E2C - 2 ; case 10
	.short _02217E46 - _02217E2C - 2 ; case 11
	.short _02217E48 - _02217E2C - 2 ; case 12
_02217E46:
	b _02217E76
_02217E48:
	cmp r1, #0xb
	beq _02217E50
	cmp r1, #6
	bne _02217E54
_02217E50:
	mov r4, #3
	b _02217E76
_02217E54:
	cmp r2, #6
	bne _02217E5C
	mov r4, #2
	b _02217E76
_02217E5C:
	mov r4, #1
	b _02217E76
_02217E60:
	cmp r1, #0xb
	beq _02217E68
	cmp r1, #6
	bne _02217E76
_02217E68:
	mov r4, #3
	b _02217E76
_02217E6C:
	bl GF_AssertFail
	b _02217E76
_02217E72:
	bl GF_AssertFail
_02217E76:
	add r0, r4, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02217E08


	thumb_func_start ov96_02217E7C
ov96_02217E7C: ; 0x02217E7C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	bl PokeathlonCourse_GetHeapAllocPtr4
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [sp, #8]
	add r0, r0, r1
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r1, #0x1c
	ldr r7, [sp, #4]
	add r4, r0, r1
_02217E9A:
	add r0, r4, #0
	bl ov96_02218744
	cmp r0, #0
	beq _02217EB4
	mov r0, #0x5d
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bgt _02217EB4
	ldr r0, [sp, #0xc]
	add r6, r0, #1
	cmp r6, #4
	blt _02217EB6
_02217EB4:
	b _02217FBC
_02217EB6:
	mov r1, #0x69
	ldr r0, [sp, #8]
	lsl r1, r1, #2
	add r1, r0, r1
	mov r0, #0xa8
	mul r0, r6
	add r5, r1, r0
	ldr r1, [sp, #4]
	ldr r0, [sp, #0xc]
	add r1, r1, r0
	lsl r0, r6, #2
	add r0, r1, r0
	str r0, [sp]
	add r0, r4, #0
	str r0, [sp, #0x10]
	add r0, #0x2c
	str r0, [sp, #0x10]
_02217ED8:
	add r0, r5, #0
	bl ov96_02218744
	cmp r0, #0
	beq _02217FAE
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_02218598
	cmp r0, #0
	beq _02217FAE
	mov r1, #0
	add r0, sp, #0x24
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldrb r0, [r7, r6]
	cmp r0, #0
	beq _02217F0E
	ldr r0, [r4, #0x60]
	lsl r0, r0, #4
	lsr r0, r0, #0x1f
	bne _02217F0E
	ldr r0, [sp]
	strb r1, [r0]
	ldrb r0, [r0]
	strb r0, [r7, r6]
_02217F0E:
	ldrb r0, [r7, r6]
	cmp r0, #0
	bne _02217FAE
	add r1, r5, #0
	ldr r0, [sp, #0x10]
	add r1, #0x2c
	add r2, sp, #0x24
	bl VEC_Subtract
	ldr r0, [sp, #0x24]
	cmp r0, #0
	bne _02217F44
	ldr r0, [sp, #0x28]
	cmp r0, #0
	bne _02217F44
	bl MTRandom
	mov r1, #0x3f
	and r0, r1
	sub r0, #0x20
	str r0, [sp, #0x24]
	bl MTRandom
	mov r1, #0x3f
	and r0, r1
	sub r0, #0x20
	str r0, [sp, #0x28]
_02217F44:
	add r0, sp, #0x24
	add r1, r0, #0
	bl VEC_Normalize
	add r0, r4, #0
	add r1, r5, #0
	add r2, sp, #0x24
	bl ov96_022178A0
	str r0, [sp, #0x14]
	mov r0, #0
	ldr r1, [sp, #0x24]
	mvn r0, r0
	mul r0, r1
	str r0, [sp, #0x24]
	mov r0, #0
	ldr r1, [sp, #0x28]
	mvn r0, r0
	mul r0, r1
	str r0, [sp, #0x28]
	add r0, r5, #0
	add r1, r4, #0
	add r2, sp, #0x24
	bl ov96_022178A0
	str r0, [sp, #0x18]
	add r0, r4, #0
	bl ov96_02217E08
	str r0, [sp, #0x1c]
	add r0, r5, #0
	bl ov96_02217E08
	str r0, [sp, #0x20]
	ldr r1, [sp, #0x1c]
	add r0, r4, #0
	bl ov96_02217DC8
	ldr r1, [sp, #0x20]
	add r0, r5, #0
	bl ov96_02217DC8
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bne _02217FA4
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _02217FAE
_02217FA4:
	ldr r0, [sp]
	mov r1, #1
	strb r1, [r0]
	ldrb r0, [r0]
	strb r0, [r7, r6]
_02217FAE:
	ldr r0, [sp]
	add r6, r6, #1
	add r0, r0, #4
	add r5, #0xa8
	str r0, [sp]
	cmp r6, #4
	blt _02217ED8
_02217FBC:
	ldr r0, [sp, #0xc]
	add r4, #0xa8
	add r0, r0, #1
	add r7, r7, #4
	str r0, [sp, #0xc]
	cmp r0, #4
	bge _02217FCC
	b _02217E9A
_02217FCC:
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02217E7C


	thumb_func_start ov96_02217FD0
ov96_02217FD0: ; 0x02217FD0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #0x10]
_02217FDA:
	ldr r6, [sp, #4]
	ldr r5, [sp, #4]
	add r6, #0xc
	add r0, r6, #0
	add r4, r6, #0
	str r0, [sp, #0x14]
	add r0, #0x5c
	mov r7, #0
	add r5, #0x74
	add r4, #0x60
	str r0, [sp, #0x14]
_02217FF0:
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [r5, #4]
	ldr r0, [r0, #8]
	str r0, [sp, #0xc]
	ldr r0, [r6, #0x60]
	lsl r1, r0, #8
	lsr r1, r1, #0x1e
	cmp r1, r7
	bne _0221807E
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	beq _0221803E
	ldr r1, [sp, #0x14]
	mov r0, #0
	ldrsb r0, [r1, r0]
	sub r1, r0, #1
	ldr r0, [sp, #0x14]
	strb r1, [r0]
	mov r0, #0x5c
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bgt _02218082
	mov r0, #5
	add r3, r6, #0
	lsl r0, r0, #0xe
	add r2, r6, #0
	add r3, #0x2c
	str r0, [r5, #8]
	ldmia r3!, {r0, r1}
	add r2, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r1, [r4]
	ldr r0, _022180BC ; =0xEFFFFFFF
	and r0, r1
	str r0, [r4]
	b _02218082
_0221803E:
	ldr r0, [r5, #8]
	cmp r0, #0
	bgt _02218082
	add r1, r6, #0
	add r1, #0x5c
	mov r0, #0x3c
	strb r0, [r1]
	mov r0, #1
	ldr r1, [r4]
	lsl r0, r0, #0x1c
	orr r1, r0
	ldr r0, _022180C0 ; =0xDFFFFFFF
	mov r3, #1
	and r1, r0
	ldr r0, _022180C4 ; =0xBFFFFFFF
	and r0, r1
	str r0, [r4]
	mov r0, #1
	str r0, [sp]
	ldr r2, [r6, #0x60]
	ldr r0, [r6]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021E8228
	b _02218082
_0221807E:
	ldr r0, _022180C8 ; =0x444CC000
	str r0, [sp, #8]
_02218082:
	ldr r0, [r5, #8]
	bl _fflt
	ldr r1, [sp, #8]
	bl _fadd
	bl _ffix
	ldr r1, [sp, #0xc]
	str r0, [r5, #8]
	cmp r0, r1
	ble _0221809E
	add r0, r1, #0
	str r0, [r5, #8]
_0221809E:
	add r7, r7, #1
	add r5, #0x10
	cmp r7, #3
	blt _02217FF0
	ldr r0, [sp, #4]
	add r0, #0xa8
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #4
	blt _02217FDA
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022180BC: .word 0xEFFFFFFF
_022180C0: .word 0xDFFFFFFF
_022180C4: .word 0xBFFFFFFF
_022180C8: .word 0x444CC000
	thumb_func_end ov96_02217FD0


	thumb_func_start ov96_022180CC
ov96_022180CC: ; 0x022180CC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	str r0, [sp]
	mov r0, #0
	mov r7, #0x3f
	ldr r5, [sp]
	str r1, [sp, #4]
	str r0, [sp, #8]
	lsl r7, r7, #0x18
_022180DE:
	mov r1, #0
	add r0, sp, #0x18
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	add r0, sp, #0xc
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	add r0, r1, #0
	add r6, r5, #0
	add r4, r5, #0
	ldrsh r0, [r5, r0]
	add r6, #8
	add r4, #0xc
	cmp r0, #0
	ble _02218110
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _0221811C
_02218110:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_0221811C:
	bl _ffix
	str r0, [sp, #0x18]
	mov r0, #2
	ldrsh r0, [r5, r0]
	cmp r0, #0
	ble _0221813A
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _02218146
_0221813A:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_02218146:
	bl _ffix
	str r0, [sp, #0x1c]
	mov r0, #4
	ldrsh r0, [r5, r0]
	cmp r0, #0
	ble _02218164
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _02218170
_02218164:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_02218170:
	bl _ffix
	str r0, [sp, #0xc]
	mov r0, #6
	ldrsh r0, [r5, r0]
	cmp r0, #0
	ble _0221818E
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _0221819A
_0221818E:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_0221819A:
	bl _ffix
	str r0, [sp, #0x10]
	ldr r1, [r6]
	lsl r0, r1, #0x11
	lsr r0, r0, #0x1f
	beq _02218226
	mov r0, #0
	mov r1, #2
	ldrsh r0, [r5, r0]
	ldrsh r1, [r5, r1]
	bl ov96_022158D4
	cmp r0, #0
	beq _022181CC
	add r0, r4, #0
	bl ov96_0221862C
	cmp r0, #0
	bne _022181C4
	b _022182FC
_022181C4:
	add r0, r4, #0
	bl ov96_0221910C
	b _022182FC
_022181CC:
	bl ov96_021E6104
	cmp r0, #0
	ble _022181E8
	bl ov96_021E6104
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _022181F8
_022181E8:
	bl ov96_021E6104
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_022181F8:
	bl _ffix
	add r2, r0, #0
	ldr r0, [r4, #0x60]
	lsl r0, r0, #5
	lsr r0, r0, #0x1f
	bne _022182FC
	ldr r0, [r4, #0x14]
	cmp r0, #3
	beq _022182FC
	add r4, #0x2c
	add r0, r4, #0
	add r1, sp, #0x18
	bl ov96_022158EC
	cmp r0, #0
	beq _022182FC
	mov r0, #2
	ldr r1, [r6]
	lsl r0, r0, #0x1c
	orr r0, r1
	str r0, [r6]
	b _022182FC
_02218226:
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1f
	beq _02218274
	lsl r0, r1, #2
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _022182FC
	ldr r0, [r4, #0x2c]
	lsl r0, r0, #4
	asr r3, r0, #0x10
	ldr r0, [r4, #0x30]
	lsl r0, r0, #4
	asr r2, r0, #0x10
	ldr r0, [r4, #0x14]
	cmp r0, #3
	bne _0221824E
	ldr r0, _02218328 ; =0xDFFFFFFF
	and r0, r1
	str r0, [r6]
	b _022182FC
_0221824E:
	mov r0, #0
	ldrsh r0, [r5, r0]
	sub r0, r0, r3
	bpl _02218258
	neg r0, r0
_02218258:
	cmp r0, #1
	bgt _0221826A
	mov r0, #2
	ldrsh r0, [r5, r0]
	sub r0, r0, r2
	bpl _02218266
	neg r0, r0
_02218266:
	cmp r0, #1
	ble _022182FC
_0221826A:
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_022186B8
	b _022182FC
_02218274:
	lsl r0, r1, #3
	lsr r0, r0, #0x13
	beq _022182FC
	lsl r0, r1, #2
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _022182F4
	ldr r0, [r4, #0x14]
	cmp r0, #1
	beq _0221828C
	cmp r0, #4
	bne _022182F4
_0221828C:
	ldr r0, [r4, #0x60]
	lsl r1, r0, #3
	lsr r1, r1, #0x1f
	bne _022182F4
	lsl r0, r0, #5
	lsr r0, r0, #0x1f
	bne _022182F4
	mov r2, #1
	add r0, sp, #0xc
	add r1, sp, #0x18
	lsl r2, r2, #0xe
	bl ov96_022158EC
	cmp r0, #0
	beq _022182C4
	ldr r0, [r6]
	lsl r0, r0, #3
	lsr r0, r0, #0x13
	cmp r0, #7
	bhi _022182F4
	ldr r1, [r4, #0x60]
	ldr r0, _0221832C ; =0xBFFFFFFF
	and r1, r0
	mov r0, #2
	lsl r0, r0, #0x1c
	orr r0, r1
	str r0, [r4, #0x60]
	b _022182F4
_022182C4:
	mov r2, #3
	add r0, sp, #0xc
	add r1, sp, #0x18
	lsl r2, r2, #0xe
	bl ov96_022158EC
	cmp r0, #0
	bne _022182F4
	ldr r0, [r6]
	lsl r0, r0, #3
	lsr r0, r0, #0x13
	cmp r0, #7
	bhi _022182F4
	mov r0, #1
	ldr r1, [r4, #0x60]
	lsl r0, r0, #0x1e
	orr r1, r0
	ldr r0, _02218328 ; =0xDFFFFFFF
	and r0, r1
	str r0, [r4, #0x60]
	ldrh r0, [r5]
	strh r0, [r4, #0x1c]
	ldrh r0, [r5, #2]
	strh r0, [r4, #0x1e]
_022182F4:
	ldr r1, [r6]
	ldr r0, _02218328 ; =0xDFFFFFFF
	and r0, r1
	str r0, [r6]
_022182FC:
	add r0, r5, #0
	ldr r1, [sp, #4]
	add r0, #0xc
	bl ov96_02218B1C
	ldr r0, [sp, #8]
	add r5, #0xa8
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #4
	bge _02218314
	b _022180DE
_02218314:
	ldr r0, [sp, #4]
	bl ov96_02217E7C
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl ov96_02217FD0
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_02218328: .word 0xDFFFFFFF
_0221832C: .word 0xBFFFFFFF
	thumb_func_end ov96_022180CC


	thumb_func_start ov96_02218330
ov96_02218330: ; 0x02218330
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	add r0, r1, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #8]
	mov r2, #0x30
	str r2, [sp, #0x14]
	mov r2, #0xc0
	ldr r0, [sp]
	str r2, [sp, #0x10]
	str r2, [sp, #0xc]
	mov r2, #0x3f
	mov ip, r2
	mov r2, #0xf
	str r2, [sp, #0x20]
	mov r2, #0x60
	str r2, [sp, #0x1c]
	mov r2, #7
	ldr r1, [sp, #8]
	mov r6, #0
	add r0, #0x1c
	mov r7, #0x18
	str r2, [sp, #0x18]
_0221836C:
	ldr r2, [r0, #0x2c]
	ldr r3, [r0, #0x30]
	lsl r2, r2, #4
	lsl r3, r3, #4
	ldr r4, [r0, #0x64]
	asr r2, r2, #0x10
	asr r3, r3, #0x10
	cmp r4, #0
	beq _02218384
	sub r4, r4, #1
	str r4, [r0, #0x64]
	b _02218392
_02218384:
	bne _02218392
	ldr r5, [r0, #0x60]
	ldr r4, _02218504 ; =0xFFFFCFFF
	and r5, r4
	ldr r4, _02218508 ; =0xFFFF3FFF
	and r4, r5
	str r4, [r0, #0x60]
_02218392:
	ldrb r4, [r1, #4]
	ldr r5, [sp, #0x14]
	bic r4, r5
	ldr r5, [r0, #0x60]
	lsl r5, r5, #0x12
	lsr r5, r5, #0x1e
	lsl r5, r5, #0x18
	lsr r5, r5, #0x18
	lsl r5, r5, #0x1e
	lsr r5, r5, #0x1a
	orr r4, r5
	strb r4, [r1, #4]
	ldrb r4, [r1, #2]
	ldr r5, [sp, #0x10]
	bic r4, r5
	ldr r5, [r0, #0x60]
	lsl r5, r5, #0x10
	lsr r5, r5, #0x1e
	lsl r5, r5, #0x18
	lsr r5, r5, #0x18
	lsl r5, r5, #0x1e
	lsr r5, r5, #0x18
	orr r4, r5
	strb r4, [r1, #2]
	ldrb r4, [r1, #4]
	ldr r5, [sp, #0xc]
	bic r4, r5
	ldr r5, [r0, #0x60]
	lsl r5, r5, #8
	lsr r5, r5, #0x1e
	lsl r5, r5, #0x18
	lsr r5, r5, #0x18
	lsl r5, r5, #0x1e
	lsr r5, r5, #0x18
	orr r4, r5
	strb r4, [r1, #4]
	ldr r5, [r0, #0x60]
	ldrb r4, [r1, #5]
	lsl r5, r5, #0xc
	lsr r5, r5, #0x1c
	sub r5, r5, #1
	lsl r5, r5, #0x18
	lsr r5, r5, #0x18
	lsl r5, r5, #0x1e
	bic r4, r7
	lsr r5, r5, #0x1b
	orr r4, r5
	strb r4, [r1, #5]
	cmp r2, #0xff
	ble _022183FA
	mov r2, #0xff
	b _02218400
_022183FA:
	cmp r2, #0
	bge _02218400
	mov r2, #0
_02218400:
	strb r2, [r1]
	cmp r3, #0xff
	ble _0221840A
	mov r3, #0xff
	b _02218410
_0221840A:
	cmp r3, #0
	bge _02218410
	mov r3, #0
_02218410:
	strb r3, [r1, #1]
	ldrb r4, [r1, #2]
	mov r2, ip
	bic r4, r2
	ldr r2, [r0, #0x50]
	asr r2, r2, #0xc
	lsl r2, r2, #0x18
	lsr r3, r2, #0x18
	mov r2, #0x3f
	and r2, r3
	orr r2, r4
	strb r2, [r1, #2]
	ldrb r4, [r1, #4]
	ldr r2, [sp, #0x20]
	bic r4, r2
	ldr r2, [r0, #0x14]
	lsl r2, r2, #0x18
	lsr r3, r2, #0x18
	mov r2, #0xf
	and r2, r3
	orr r2, r4
	strb r2, [r1, #4]
	ldr r2, [r0, #0x60]
	ldr r3, [sp, #0x1c]
	lsl r2, r2, #0x14
	lsr r2, r2, #0x14
	strb r2, [r1, #3]
	ldrb r2, [r1, #5]
	bic r2, r3
	ldr r3, [r0, #0x60]
	lsl r3, r3, #6
	lsr r3, r3, #0x1e
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	lsl r3, r3, #0x1e
	lsr r3, r3, #0x19
	orr r2, r3
	strb r2, [r1, #5]
	ldrb r4, [r1, #5]
	ldr r2, [sp, #0x18]
	bic r4, r2
	add r2, r0, #0
	add r2, #0x5f
	ldrb r3, [r2]
	mov r2, #7
	and r2, r3
	orr r2, r4
	strb r2, [r1, #5]
	ldr r2, [r0, #0x60]
	lsr r3, r2, #0x1f
	beq _02218480
	mov r3, #1
	str r3, [sp, #4]
	ldr r3, _0221850C ; =0x7FFFFFFF
	and r2, r3
	str r2, [r0, #0x60]
_02218480:
	add r6, r6, #1
	add r0, #0xa8
	add r1, r1, #6
	cmp r6, #4
	bge _0221848C
	b _0221836C
_0221848C:
	ldr r0, [sp, #8]
	ldr r6, [sp, #8]
	ldr r1, [r0, #0x1c]
	mov r0, #0x80
	bic r1, r0
	ldr r0, [sp, #4]
	mov r5, #0
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x18
	orr r1, r0
	ldr r0, [sp, #8]
	add r6, #0x1c
	str r1, [r0, #0x1c]
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #8]
	add r4, r5, #0
	str r1, [r0, #0x1c]
_022184B0:
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r0, #0
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0xa8
	lsl r2, r1, #4
	ldr r1, [sp]
	mul r0, r7
	add r0, r1, r0
	add r0, r2, r0
	add r0, #0x8c
	ldr r0, [r0]
	asr r0, r0, #0xc
	bne _022184DA
	mov r1, #2
	b _022184E4
_022184DA:
	cmp r0, #0x1e
	bge _022184E2
	mov r1, #1
	b _022184E4
_022184E2:
	mov r1, #0
_022184E4:
	ldr r2, [r6]
	lsl r1, r4
	lsl r0, r2, #0x18
	lsr r2, r2, #8
	add r1, r2, r1
	lsr r0, r0, #0x18
	lsl r1, r1, #8
	orr r0, r1
	add r5, r5, #1
	add r4, r4, #2
	str r0, [r6]
	cmp r5, #0xc
	blt _022184B0
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_02218504: .word 0xFFFFCFFF
_02218508: .word 0xFFFF3FFF
_0221850C: .word 0x7FFFFFFF
	thumb_func_end ov96_02218330


	thumb_func_start ov96_02218510

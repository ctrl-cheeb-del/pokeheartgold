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

	thumb_func_start ov96_021EDF84
ov96_021EDF84: ; 0x021EDF84
	push {r4, r5}
	mov r4, #0
	add r3, r4, #0
	add r5, r1, #0
_021EDF8C:
	ldr r2, [r5, #0x44]
	add r3, r3, #1
	add r4, r4, r2
	add r5, r5, #4
	cmp r3, #0xa
	blt _021EDF8C
	ldr r2, [r1, #4]
	mov r5, #0
	str r2, [r0]
	ldr r2, [r1, #8]
	add r3, r1, #0
	str r2, [r0, #4]
	ldr r2, [r1, #0xc]
	str r2, [r0, #8]
	str r4, [r0, #0xc]
	ldr r2, [r1, #0x6c]
	add r4, r0, #0
	str r2, [r0, #0x10]
	ldr r2, [r1, #0x10]
	str r2, [r0, #0x14]
	ldr r2, [r1, #0x14]
	str r2, [r0, #0x18]
	ldr r2, [r1, #0x18]
	str r2, [r0, #0x1c]
	ldr r2, [r1, #0x1c]
	str r2, [r0, #0x20]
	ldr r2, [r1, #0x20]
	str r2, [r0, #0x24]
	ldr r2, [r1, #0x24]
	str r2, [r0, #0x28]
	ldr r2, [r1, #0x28]
	str r2, [r0, #0x2c]
	ldr r2, [r1, #0x2c]
	str r2, [r0, #0x30]
	ldr r2, [r1, #0x30]
	str r2, [r0, #0x34]
	ldr r2, [r1, #0x38]
	str r2, [r0, #0x38]
	ldr r2, [r1, #0x3c]
	str r2, [r0, #0x3c]
	ldr r2, [r1, #0x40]
	str r2, [r0, #0x40]
_021EDFE0:
	ldr r2, [r3, #0x44]
	add r5, r5, #1
	str r2, [r4, #0x44]
	add r3, r3, #4
	add r4, r4, #4
	cmp r5, #0xa
	blt _021EDFE0
	ldr r2, [r1, #0x34]
	str r2, [r0, #0x6c]
	ldr r1, [r1, #0x70]
	str r1, [r0, #0x70]
	pop {r4, r5}
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021EDF84


	thumb_func_start ov96_021EDFFC
ov96_021EDFFC: ; 0x021EDFFC
	push {r3, r4, r5, r6, r7, lr}
	ldr r5, _021EE03C ; =ov96_0221B124
	add r6, r0, #0
	add r7, r1, #0
	mov r4, #0
_021EE006:
	ldr r0, [r5]
	cmp r0, #0
	bne _021EE010
	bl GF_AssertFail
_021EE010:
	bl MTRandom
	mov r1, #3
	bl _u32_div_f
	strb r1, [r6, r4]
	ldr r0, [r7]
	cmp r0, #0
	beq _021EE02E
	ldr r1, [r5]
	bl _u32_div_f
	ldrb r1, [r6, r4]
	add r0, r1, r0
	strb r0, [r6, r4]
_021EE02E:
	add r4, r4, #1
	add r5, r5, #4
	add r7, r7, #4
	cmp r4, #0x1d
	blt _021EE006
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021EE03C: .word ov96_0221B124
	thumb_func_end ov96_021EDFFC


	thumb_func_start ov96_021EE040
ov96_021EE040: ; 0x021EE040
	push {r4, r5, r6, lr}
	sub sp, #0x20
	add r4, sp, #0
	mov r3, #0x1d
	mov r2, #0
_021EE04A:
	strb r2, [r4]
	add r4, r4, #1
	sub r3, r3, #1
	bne _021EE04A
	mov r2, #0
	add r4, r2, #0
	add r5, r2, #0
_021EE058:
	ldrb r3, [r0, r5]
	cmp r2, r3
	bhs _021EE060
	add r2, r3, #0
_021EE060:
	add r5, r5, #1
	cmp r5, #0x1d
	blt _021EE058
	mov r6, #0
	add r5, sp, #0
_021EE06A:
	ldrb r3, [r0, r6]
	cmp r2, r3
	bne _021EE076
	strb r6, [r5]
	add r5, r5, #1
	add r4, r4, #1
_021EE076:
	add r6, r6, #1
	cmp r6, #0x1d
	blt _021EE06A
	ldr r3, _021EE0A8 ; =ov96_0221AF54
	mov r5, #0
_021EE080:
	ldr r0, [r3]
	cmp r2, r0
	blo _021EE08E
	mov r0, #3
	sub r0, r0, r5
	strb r0, [r1]
	b _021EE096
_021EE08E:
	add r5, r5, #1
	add r3, r3, #4
	cmp r5, #4
	blt _021EE080
_021EE096:
	bl MTRandom
	add r1, r4, #0
	bl _u32_div_f
	add r0, sp, #0
	ldrb r0, [r0, r1]
	add sp, #0x20
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021EE0A8: .word ov96_0221AF54
	thumb_func_end ov96_021EE040


	thumb_func_start ov96_021EE0AC
ov96_021EE0AC: ; 0x021EE0AC
	push {r3, r4, r5, r6, lr}
	sub sp, #0x94
	add r5, r0, #0
	mov r0, #0
	add r2, r1, #0
	add r4, sp, #0x20
	add r1, r0, #0
	mov r3, #7
_021EE0BC:
	stmia r4!, {r0, r1}
	stmia r4!, {r0, r1}
	sub r3, r3, #1
	bne _021EE0BC
	add r3, sp, #0
	str r0, [r4]
	add r3, #1
	mov r1, #0x1d
	mov r0, #0
_021EE0CE:
	strb r0, [r3]
	add r3, r3, #1
	sub r1, r1, #1
	bne _021EE0CE
	add r0, r2, #0
	bl PokeathlonCourse_GetSaveData
	bl Save_Pokeathlon_Get
	bl PokeathlonSave_GetAgainUnkB00
	add r6, r0, #0
	add r0, sp, #0x20
	add r1, r6, #0
	bl ov96_021EDF84
	add r0, sp, #0
	add r0, #1
	add r1, sp, #0x20
	bl ov96_021EDFFC
	add r0, sp, #0
	add r0, #1
	add r1, sp, #0
	bl ov96_021EE040
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	bl ov96_021EDF7C
	add r1, sp, #0
	ldrb r1, [r1]
	lsl r2, r4, #2
	add r0, r1, r0
	str r0, [r5]
	mov r0, #0xff
	ldr r1, [r5, #4]
	lsl r0, r0, #0x18
	and r0, r1
	add r1, sp, #0x20
	ldr r2, [r1, r2]
	ldr r1, _021EE140 ; =0x00FFFFFF
	and r1, r2
	orr r0, r1
	str r0, [r5, #4]
	ldr r0, [r6, #0x70]
	bl ov96_021EDF5C
	ldr r2, [r5, #4]
	ldr r1, _021EE140 ; =0x00FFFFFF
	lsl r0, r0, #0x18
	and r1, r2
	orr r0, r1
	str r0, [r5, #4]
	add sp, #0x94
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021EE140: .word 0x00FFFFFF
	thumb_func_end ov96_021EE0AC


	thumb_func_start ov96_021EE144
ov96_021EE144: ; 0x021EE144
	push {r3, r4, r5, r6, lr}
	sub sp, #0x94
	add r5, r0, #0
	mov r0, #0
	add r3, r1, #0
	add r6, sp, #0x20
	add r1, r0, #0
	mov r4, #7
_021EE154:
	stmia r6!, {r0, r1}
	stmia r6!, {r0, r1}
	sub r4, r4, #1
	bne _021EE154
	add r4, sp, #0
	str r0, [r6]
	add r4, #1
	mov r1, #0x1d
	mov r0, #0
_021EE166:
	strb r0, [r4]
	add r4, r4, #1
	sub r1, r1, #1
	bne _021EE166
	add r0, r3, #0
	add r1, r2, #0
	bl PokeathlonCourse_GetField974_AtIndex
	add r6, r0, #0
	add r0, sp, #0x20
	add r1, r6, #0
	bl ov96_021EDF84
	add r0, sp, #0
	add r0, #1
	add r1, sp, #0x20
	bl ov96_021EDFFC
	add r0, sp, #0
	add r0, #1
	add r1, sp, #0
	bl ov96_021EE040
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	bl ov96_021EDF7C
	add r1, sp, #0
	ldrb r1, [r1]
	lsl r2, r4, #2
	add r0, r1, r0
	str r0, [r5]
	mov r0, #0xff
	ldr r1, [r5, #4]
	lsl r0, r0, #0x18
	and r0, r1
	add r1, sp, #0x20
	ldr r2, [r1, r2]
	ldr r1, _021EE1D4 ; =0x00FFFFFF
	and r1, r2
	orr r0, r1
	str r0, [r5, #4]
	ldr r0, [r6, #0x70]
	bl ov96_021EDF5C
	ldr r2, [r5, #4]
	ldr r1, _021EE1D4 ; =0x00FFFFFF
	lsl r0, r0, #0x18
	and r1, r2
	orr r0, r1
	str r0, [r5, #4]
	add sp, #0x94
	pop {r3, r4, r5, r6, pc}
	nop
_021EE1D4: .word 0x00FFFFFF
	thumb_func_end ov96_021EE144


	thumb_func_start ov96_021EE1D8
ov96_021EE1D8: ; 0x021EE1D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r2, [sp, #4]
	add r7, r1, #0
	str r0, [sp]
	ldr r1, [sp, #4]
	add r0, r7, #0
	mov r5, #0
	bl PokeathlonCourse_GetParticipantData
	str r0, [sp, #8]
	add r4, r5, #0
_021EE1F0:
	ldr r1, [sp, #4]
	add r0, r7, #0
	add r2, r4, #0
	bl ov96_021E60D8
	ldrb r6, [r0, #4]
	ldrb r3, [r0, #3]
	ldrb r2, [r0, #1]
	ldrb r1, [r0, #2]
	ldrb r0, [r0]
	add r4, r4, #1
	add r0, r1, r0
	add r0, r2, r0
	add r0, r3, r0
	add r0, r6, r0
	add r0, r0, #5
	add r5, r5, r0
	cmp r4, #3
	blt _021EE1F0
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	add r4, r0, #0
	sub r4, #8
	cmp r4, #0xc
	ble _021EE22A
	mov r4, #0xc
	b _021EE230
_021EE22A:
	cmp r4, #0
	bge _021EE230
	mov r4, #0
_021EE230:
	ldr r1, [sp, #8]
	add r0, r7, #0
	ldr r1, [r1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021E8448
	ldr r1, [sp]
	str r0, [r1]
	add r0, r1, #0
	ldr r1, [r0, #4]
	mov r0, #0xff
	lsl r0, r0, #0x18
	and r1, r0
	ldr r0, [sp]
	str r1, [r0, #4]
	ldr r0, _021EE260 ; =0x00FFFFFF
	and r1, r0
	lsl r0, r4, #0x18
	orr r1, r0
	ldr r0, [sp]
	str r1, [r0, #4]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021EE260: .word 0x00FFFFFF
	thumb_func_end ov96_021EE1D8


	thumb_func_start ov96_021EE264
ov96_021EE264: ; 0x021EE264
	push {r3, r4}
	mov r3, #0
	add r4, r0, #0
_021EE26A:
	ldr r2, [r4]
	lsl r2, r2, #4
	lsr r2, r2, #0x1c
	cmp r1, r2
	bne _021EE280
	lsl r1, r3, #2
	ldr r0, [r0, r1]
	lsl r0, r0, #8
	lsr r0, r0, #0x18
	pop {r3, r4}
	bx lr
_021EE280:
	add r3, r3, #1
	add r4, r4, #4
	cmp r3, #4
	blt _021EE26A
	mov r0, #0
	mvn r0, r0
	pop {r3, r4}
	bx lr
	thumb_func_end ov96_021EE264


	thumb_func_start ov96_021EE290
ov96_021EE290: ; 0x021EE290
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	mov r3, #0
	ldr r7, _021EE318 ; =0xFF00FFFF
	add r2, r3, #0
	add r6, r4, #0
_021EE29C:
	ldr r0, [r6]
	lsl r1, r0, #8
	lsr r1, r1, #0x18
	bne _021EE2BA
	add r1, r1, #1
	lsl r1, r1, #0x18
	and r0, r7
	lsr r1, r1, #8
	orr r0, r1
	str r0, [r6]
	lsr r0, r0, #0x1c
	cmp r0, r3
	bls _021EE2BA
	add r3, r0, #0
	add r5, r2, #0
_021EE2BA:
	add r2, r2, #1
	add r6, r6, #4
	cmp r2, #4
	blt _021EE29C
	lsl r1, r5, #2
	ldr r3, [r4, r1]
	ldr r2, _021EE318 ; =0xFF00FFFF
	add r0, r3, #0
	lsl r3, r3, #8
	lsr r3, r3, #0x18
	sub r3, r3, #1
	lsl r3, r3, #0x18
	and r0, r2
	lsr r3, r3, #8
	orr r0, r3
	str r0, [r4, r1]
	ldr r3, [r4, r1]
	lsl r0, r2, #0x10
	lsl r2, r3, #0x10
	lsr r2, r2, #0x10
	add r2, r2, #1
	lsl r2, r2, #0x10
	and r0, r3
	lsr r2, r2, #0x10
	orr r0, r2
	str r0, [r4, r1]
	mov r0, #0
	mov r1, #4
	str r0, [sp]
	ldr r3, _021EE31C ; =ov96_021ECC58
	add r0, r4, #0
	add r2, r1, #0
	bl MATH_QSort
	ldr r1, [r4]
	ldr r0, _021EE320 ; =0xFFFF0000
	add r2, r1, #0
	and r2, r0
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
	sub r0, r0, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	orr r0, r2
	str r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021EE318: .word 0xFF00FFFF
_021EE31C: .word ov96_021ECC58
_021EE320: .word 0xFFFF0000
	thumb_func_end ov96_021EE290


	thumb_func_start ov96_021EE324
ov96_021EE324: ; 0x021EE324
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x14]
	add r0, r7, #0
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #0x10]
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #8]
	add r0, r7, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0x14]
	add r0, #0xb7
	ldrb r6, [r0]
	mov r0, #0
	str r0, [sp, #4]
	cmp r1, #0
	bne _021EE3FC
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #0xc]
	add r0, #0x20
	strb r6, [r0]
	ldr r0, [sp, #0x10]
	add r0, #0x50
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [sp, #0x10]
	bl ov96_021E8A20
	mov r2, #0x24
_021EE37E:
	ldrb r1, [r0]
	add r0, r0, #1
	strb r1, [r4]
	add r4, r4, #1
	sub r2, r2, #1
	bne _021EE37E
	add r0, r7, #0
	mov r4, #0
	bl PokeathlonCourse_GetParticipantCount
	cmp r0, #0
	ble _021EE3C8
	ldr r5, [sp, #0x10]
	add r5, #0x50
_021EE39A:
	add r0, r5, #0
	bl ov96_021E8A20
	ldrb r1, [r0]
	cmp r1, r6
	blo _021EE3AC
	ldrb r1, [r0, #1]
	cmp r1, #1
	bne _021EE3B0
_021EE3AC:
	mov r1, #1
	str r1, [sp, #4]
_021EE3B0:
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne _021EE3BA
	mov r0, #0
	str r0, [sp]
_021EE3BA:
	add r0, r7, #0
	add r5, #0x28
	add r4, r4, #1
	bl PokeathlonCourse_GetParticipantCount
	cmp r4, r0
	blt _021EE39A
_021EE3C8:
	ldr r0, [sp]
	cmp r0, #0
	beq _021EE3DE
	ldr r0, [sp, #0xc]
	add r0, #0x21
	ldrb r1, [r0]
	mov r0, #2
	orr r1, r0
	ldr r0, [sp, #0xc]
	add r0, #0x21
	strb r1, [r0]
_021EE3DE:
	ldr r0, [sp, #0xc]
	mov r1, #1
	add r0, #0x21
	ldrb r0, [r0]
	bic r0, r1
	ldr r1, [sp, #4]
	lsl r1, r1, #0x18
	lsr r2, r1, #0x18
	mov r1, #1
	and r1, r2
	orr r1, r0
	ldr r0, [sp, #0xc]
	add r0, #0x21
	str r0, [sp, #0xc]
	strb r1, [r0]
_021EE3FC:
	ldr r0, [sp, #0x10]
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [sp, #0x14]
	strb r6, [r4]
	ldr r0, [r0, #0xc]
	bl ov96_021EEA80
	strb r0, [r4, #1]
	ldr r0, [sp, #0x14]
	add r0, #0xb8
	str r0, [sp, #0x14]
	ldr r0, [r0]
	strb r0, [r4, #2]
	ldr r0, [sp, #8]
	add r0, #0x21
	ldrb r0, [r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _021EE438
	ldr r0, [sp, #8]
	add r0, #0x20
	str r0, [sp, #8]
	ldrb r0, [r0]
	cmp r6, r0
	blo _021EE438
	add sp, #0x18
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021EE438:
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EE324


	thumb_func_start ov96_021EE440
ov96_021EE440: ; 0x021EE440
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x14]
	add r0, r7, #0
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #0x10]
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #8]
	add r0, r7, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0x14]
	add r0, #0xb7
	ldrb r6, [r0]
	mov r0, #0
	str r0, [sp, #4]
	cmp r1, #0
	bne _021EE50A
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #0xc]
	strb r6, [r0, #0xc]
	ldr r0, [sp, #0x10]
	add r0, #0x50
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [sp, #0x10]
	bl ov96_021E8A20
	mov r2, #0x24
_021EE498:
	ldrb r1, [r0]
	add r0, r0, #1
	strb r1, [r4]
	add r4, r4, #1
	sub r2, r2, #1
	bne _021EE498
	add r0, r7, #0
	mov r4, #0
	bl PokeathlonCourse_GetParticipantCount
	cmp r0, #0
	ble _021EE4E2
	ldr r5, [sp, #0x10]
	add r5, #0x50
_021EE4B4:
	add r0, r5, #0
	bl ov96_021E8A20
	ldrb r1, [r0]
	cmp r1, r6
	blo _021EE4C6
	ldrb r1, [r0, #1]
	cmp r1, #1
	bne _021EE4CA
_021EE4C6:
	mov r1, #1
	str r1, [sp, #4]
_021EE4CA:
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne _021EE4D4
	mov r0, #0
	str r0, [sp]
_021EE4D4:
	add r0, r7, #0
	add r5, #0x28
	add r4, r4, #1
	bl PokeathlonCourse_GetParticipantCount
	cmp r4, r0
	blt _021EE4B4
_021EE4E2:
	ldr r0, [sp]
	cmp r0, #0
	beq _021EE4F6
	ldr r0, [sp, #0xc]
	ldr r1, [r0, #8]
	mov r0, #2
	lsl r0, r0, #0x1c
	orr r1, r0
	ldr r0, [sp, #0xc]
	str r1, [r0, #8]
_021EE4F6:
	ldr r0, [sp, #0xc]
	ldr r1, [r0, #8]
	ldr r0, _021EE548 ; =0xEFFFFFFF
	and r1, r0
	ldr r0, [sp, #4]
	lsl r0, r0, #0x1f
	lsr r0, r0, #3
	orr r1, r0
	ldr r0, [sp, #0xc]
	str r1, [r0, #8]
_021EE50A:
	ldr r0, [sp, #0x10]
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [sp, #0x14]
	strb r6, [r4]
	ldr r0, [r0, #0xc]
	bl ov96_021EEA80
	strb r0, [r4, #1]
	ldr r0, [sp, #0x14]
	add r0, #0xb8
	str r0, [sp, #0x14]
	ldr r0, [r0]
	strb r0, [r4, #2]
	ldr r0, [sp, #8]
	ldr r0, [r0, #8]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	beq _021EE540
	ldr r0, [sp, #8]
	ldrb r0, [r0, #0xc]
	cmp r6, r0
	blo _021EE540
	add sp, #0x18
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021EE540:
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021EE548: .word 0xEFFFFFFF
	thumb_func_end ov96_021EE440


	thumb_func_start ov96_021EE54C
ov96_021EE54C: ; 0x021EE54C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r6, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r5, #0
	bne _021EE566
	bl GF_AssertFail
_021EE566:
	cmp r6, #0
	bne _021EE56E
	bl GF_AssertFail
_021EE56E:
	cmp r4, #0
	bne _021EE576
	bl GF_AssertFail
_021EE576:
	add r4, #0x21
	ldrb r0, [r4]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021EE54C


	thumb_func_start ov96_021EE580
ov96_021EE580: ; 0x021EE580
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r6, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	cmp r5, #0
	bne _021EE59A
	bl GF_AssertFail
_021EE59A:
	cmp r6, #0
	bne _021EE5A2
	bl GF_AssertFail
_021EE5A2:
	cmp r4, #0
	bne _021EE5AA
	bl GF_AssertFail
_021EE5AA:
	ldr r0, [r4, #8]
	lsl r0, r0, #2
	lsr r0, r0, #0x1f
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021EE580


	thumb_func_start ov96_021EE5B4
ov96_021EE5B4: ; 0x021EE5B4
	push {r4, r5, r6, lr}
	add r6, r1, #0
	add r5, r0, #0
	add r0, r6, #0
	mov r1, #0x30
	bl Heap_Alloc
	add r4, r0, #0
	mov r1, #0
	mov r2, #0x30
	bl MI_CpuFill8
	str r6, [r4]
	mov r0, #0xdd
	add r1, r6, #0
	str r5, [r4, #8]
	bl NARC_New
	str r0, [r4, #0xc]
	add r0, r4, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021EE5B4


	thumb_func_start ov96_021EE5E0
ov96_021EE5E0: ; 0x021EE5E0
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r5, r6, #0
	mov r4, #0
	add r5, #0x10
_021EE5EA:
	add r0, r5, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	bl RemoveWindow
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #2
	blt _021EE5EA
	ldr r0, [r6, #0xc]
	bl NARC_Delete
	add r0, r6, #0
	bl Heap_Free
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021EE5E0


	thumb_func_start ov96_021EE60C
ov96_021EE60C: ; 0x021EE60C
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r7, #0
	ldr r4, _021EE640 ; =ov96_0221B19A
	str r1, [r7, #4]
	mov r6, #0
	add r5, #0x10
_021EE61A:
	ldr r0, [r7, #4]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	bl ClearWindowTilemap
	add r6, r6, #1
	add r4, #8
	add r5, #0x10
	cmp r6, #2
	blt _021EE61A
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021EE640: .word ov96_0221B19A
	thumb_func_end ov96_021EE60C


	thumb_func_start ov96_021EE644
ov96_021EE644: ; 0x021EE644
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #8]
	mov r2, #6
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	mov r0, #0
	str r0, [sp]
	ldr r0, [r5]
	mov r1, #0xb
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	lsl r3, r2, #0xc
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5]
	add r1, r4, #0
	str r0, [sp, #0xc]
	ldr r0, [r5, #0xc]
	ldr r2, [r5, #4]
	add r1, #0xc
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5]
	add r4, #0x16
	str r0, [sp, #0xc]
	ldr r0, [r5, #0xc]
	ldr r2, [r5, #4]
	add r1, r4, #0
	mov r3, #7
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021EE644


	thumb_func_start ov96_021EE6A0
ov96_021EE6A0: ; 0x021EE6A0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #8]
	ldr r2, _021EE6FC ; =0x00000135
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r3, [r5]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	add r6, r0, #0
	mov r0, #1
	ldr r1, [r5]
	lsl r0, r0, #8
	bl String_New
	add r7, r0, #0
	mov r0, #4
	str r0, [sp]
	add r0, r5, #0
	add r3, r4, #0
	add r0, #0x10
	add r1, r6, #0
	add r2, r7, #0
	add r3, #0xa6
	bl ov96_021EE700
	mov r0, #0
	add r4, #0xbb
	add r5, #0x20
	str r0, [sp]
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	add r3, r4, #0
	bl ov96_021EE700
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl DestroyMsgData
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021EE6FC: .word 0x00000135
	thumb_func_end ov96_021EE6A0


	thumb_func_start ov96_021EE700
ov96_021EE700: ; 0x021EE700
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r0, r1, #0
	add r1, r3, #0
	add r4, r2, #0
	bl ReadMsgDataIntoString
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021EE73C ; =0x00010200
	ldr r1, [sp, #0x20]
	str r0, [sp, #8]
	add r0, r5, #0
	add r2, r4, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_021EE73C: .word 0x00010200
	thumb_func_end ov96_021EE700


	thumb_func_start ov96_021EE740
ov96_021EE740: ; 0x021EE740
	push {r3, r4, r5, lr}
	mov r1, #0x38
	add r5, r0, #0
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x38
	add r4, r0, #0
	bl MI_CpuFill8
	str r5, [r4, #0x14]
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021EE740


	thumb_func_start ov96_021EE75C
ov96_021EE75C: ; 0x021EE75C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	add r7, r3, #0
	ldr r0, _021EE7F4 ; =0x00000004
	bne _021EE774
	ldr r0, [sp, #0x18]
	bl Save_PlayerData_GetOptionsAddr
	bl Options_GetTextFrameDelay
_021EE774:
	mov r1, #0
	str r4, [r5]
	mvn r1, r1
	str r1, [r5, #0x2c]
	ldr r2, [r5, #0x34]
	ldr r1, _021EE7F8 ; =0xF8FFFFFF
	lsl r0, r0, #0x18
	and r2, r1
	lsl r1, r6, #0x1d
	lsr r1, r1, #5
	orr r1, r2
	str r1, [r5, #0x34]
	str r7, [r5, #0x28]
	ldr r2, [r5, #0x34]
	ldr r1, _021EE7FC ; =0xFF00FFFF
	lsr r0, r0, #8
	and r1, r2
	orr r0, r1
	str r0, [r5, #0x34]
	ldr r2, _021EE800 ; =0x00000135
	ldr r3, [r5, #0x14]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	str r0, [r5, #8]
	ldr r2, _021EE804 ; =0x00000137
	ldr r3, [r5, #0x14]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	str r0, [r5, #0xc]
	ldr r0, [r5, #0x14]
	bl MessageFormat_New
	str r0, [r5, #4]
	bl ResetAllTextPrinters
	ldr r1, [r5, #0x34]
	ldr r0, [r5]
	lsl r1, r1, #5
	lsr r1, r1, #0x1d
	lsl r1, r1, #0x18
	ldr r2, [r5, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EE9D8
	mov r1, #0x1e
	ldr r2, [r5, #0x14]
	mov r0, #4
	lsl r1, r1, #4
	bl LoadFontPal0
	mov r2, #0
	str r2, [sp]
	ldr r1, [r5, #0x34]
	ldr r0, [r5]
	lsl r1, r1, #5
	lsr r1, r1, #0x1d
	mov r3, #1
	bl BG_FillCharDataRange
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021EE7F4: .word 0x00000004
_021EE7F8: .word 0xF8FFFFFF
_021EE7FC: .word 0xFF00FFFF
_021EE800: .word 0x00000135
_021EE804: .word 0x00000137
	thumb_func_end ov96_021EE75C


	thumb_func_start ov96_021EE808
ov96_021EE808: ; 0x021EE808
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #8]
	bl DestroyMsgData
	ldr r0, [r4, #0xc]
	bl DestroyMsgData
	ldr r0, [r4, #4]
	bl MessageFormat_Delete
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _021EE828
	bl String_Delete
_021EE828:
	add r0, r4, #0
	bl Heap_Free
	pop {r4, pc}
	thumb_func_end ov96_021EE808


	thumb_func_start ov96_021EE830
ov96_021EE830: ; 0x021EE830
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0
	ldr r1, [r4, #0x2c]
	mvn r0, r0
	cmp r1, r0
	beq _021EE870
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _021EE864
	ldr r1, [r4, #0x34]
	ldr r0, _021EE8C4 ; =0xFFFF0000
	and r1, r0
	mov r0, #0x14
	orr r0, r1
	str r0, [r4, #0x34]
	ldr r0, [r4, #0x10]
	bl String_Delete
	mov r0, #0
	str r0, [r4, #0x10]
	sub r0, r0, #1
	str r0, [r4, #0x2c]
_021EE864:
	mov r0, #1
	ldr r1, [r4, #0x34]
	lsl r0, r0, #0x1c
	orr r0, r1
	str r0, [r4, #0x34]
	b _021EE8BC
_021EE870:
	beq _021EE876
	bl GF_AssertFail
_021EE876:
	ldr r1, [r4, #0x34]
	lsl r0, r1, #0x10
	lsr r2, r0, #0x10
	beq _021EE8B6
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _021EE88C
	ldr r0, _021EE8C8 ; =0xEFFFFFFF
	and r0, r1
	str r0, [r4, #0x34]
	b _021EE8BC
_021EE88C:
	ldr r0, _021EE8C4 ; =0xFFFF0000
	and r1, r0
	sub r0, r2, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	orr r0, r1
	str r0, [r4, #0x34]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	beq _021EE8A4
	mov r2, #1
	b _021EE8A6
_021EE8A4:
	mov r2, #0
_021EE8A6:
	ldr r1, [r4, #0x34]
	ldr r0, _021EE8C8 ; =0xEFFFFFFF
	and r1, r0
	lsl r0, r2, #0x1f
	lsr r0, r0, #3
	orr r0, r1
	str r0, [r4, #0x34]
	b _021EE8BC
_021EE8B6:
	ldr r0, _021EE8C8 ; =0xEFFFFFFF
	and r0, r1
	str r0, [r4, #0x34]
_021EE8BC:
	ldr r0, [r4, #0x34]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	pop {r4, pc}
	.balign 4, 0
_021EE8C4: .word 0xFFFF0000
_021EE8C8: .word 0xEFFFFFFF
	thumb_func_end ov96_021EE830


	thumb_func_start ov96_021EE8CC
ov96_021EE8CC: ; 0x021EE8CC
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r0, #0
	ldr r0, [r4, #4]
	add r2, r4, #0
	str r0, [sp]
	ldr r0, [r4, #8]
	add r2, #0x10
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0x34]
	add r1, r4, #0
	lsl r0, r0, #5
	lsr r0, r0, #0x1d
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	add r1, #0x18
	str r0, [sp, #0x10]
	ldr r3, [r4, #0x34]
	ldr r0, [r4]
	lsl r3, r3, #8
	lsr r3, r3, #0x18
	bl ov96_021EEA08
	str r0, [r4, #0x2c]
	add sp, #0x14
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021EE8CC


	thumb_func_start ov96_021EE908
ov96_021EE908: ; 0x021EE908
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r0, #0
	ldr r0, [r4, #4]
	add r2, r4, #0
	str r0, [sp]
	ldr r0, [r4, #0xc]
	add r2, #0x10
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0x34]
	add r1, r4, #0
	lsl r0, r0, #5
	lsr r0, r0, #0x1d
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	add r1, #0x18
	str r0, [sp, #0x10]
	ldr r3, [r4, #0x34]
	ldr r0, [r4]
	lsl r3, r3, #8
	lsr r3, r3, #0x18
	bl ov96_021EEA08
	str r0, [r4, #0x2c]
	add sp, #0x14
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021EE908


	thumb_func_start ov96_021EE944
ov96_021EE944: ; 0x021EE944
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0
	ldr r1, [r4, #0x2c]
	mvn r0, r0
	cmp r1, r0
	beq _021EE95A
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	bl RemoveTextPrinter
_021EE95A:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _021EE97A
	add r0, r4, #0
	add r0, #0x18
	mov r1, #0
	bl ClearFrameAndWindow2
	add r0, r4, #0
	add r0, #0x18
	bl ClearWindowTilemapAndCopyToVram
	add r4, #0x18
	add r0, r4, #0
	bl RemoveWindow
_021EE97A:
	pop {r4, pc}
	thumb_func_end ov96_021EE944


	thumb_func_start ov96_021EE97C
ov96_021EE97C: ; 0x021EE97C
	push {r4, lr}
	add r4, r0, #0
	bne _021EE986
	bl GF_AssertFail
_021EE986:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _021EE990
	bl GF_AssertFail
_021EE990:
	ldr r0, [r4, #4]
	pop {r4, pc}
	thumb_func_end ov96_021EE97C


	thumb_func_start ov96_021EE994
ov96_021EE994: ; 0x021EE994
	push {r4, lr}
	add r4, r0, #0
	bne _021EE99E
	bl GF_AssertFail
_021EE99E:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _021EE9A8
	bl GF_AssertFail
_021EE9A8:
	add r0, r4, #0
	ldr r1, _021EE9B8 ; =0x000003D2
	add r0, #0x18
	bl WaitingIcon_New
	str r0, [r4, #0x30]
	pop {r4, pc}
	nop
_021EE9B8: .word 0x000003D2
	thumb_func_end ov96_021EE994


	thumb_func_start ov96_021EE9BC
ov96_021EE9BC: ; 0x021EE9BC
	push {r4, lr}
	add r4, r0, #0
	bne _021EE9C6
	bl GF_AssertFail
_021EE9C6:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	bne _021EE9D0
	bl GF_AssertFail
_021EE9D0:
	ldr r0, [r4, #0x30]
	bl sub_0200F450
	pop {r4, pc}
	thumb_func_end ov96_021EE9BC


	thumb_func_start ov96_021EE9D8
ov96_021EE9D8: ; 0x021EE9D8
	push {r4, r5, r6, lr}
	sub sp, #8
	add r6, r1, #0
	mov r1, #7
	add r5, r0, #0
	mov r0, #4
	lsl r1, r1, #6
	add r4, r2, #0
	bl LoadFontPal0
	mov r0, #0
	str r0, [sp]
	ldr r2, _021EEA04 ; =0x000003D2
	add r0, r5, #0
	add r1, r6, #0
	mov r3, #0xd
	str r4, [sp, #4]
	bl LoadUserFrameGfx2
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_021EEA04: .word 0x000003D2
	thumb_func_end ov96_021EE9D8


	thumb_func_start ov96_021EEA08
ov96_021EEA08: ; 0x021EEA08
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r5, r1, #0
	add r4, r2, #0
	ldr r2, [r5]
	add r6, r3, #0
	cmp r2, #0
	bne _021EEA36
	mov r2, #0x13
	str r2, [sp]
	mov r2, #0x1b
	str r2, [sp, #4]
	mov r2, #4
	str r2, [sp, #8]
	mov r2, #0xf
	str r2, [sp, #0xc]
	mov r2, #1
	str r2, [sp, #0x10]
	add r2, sp, #0x18
	ldrb r2, [r2, #0x1c]
	mov r3, #2
	bl AddWindowParameterized
_021EEA36:
	add r0, r5, #0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	ldr r2, [sp, #0x30]
	ldr r3, [sp, #0x38]
	bl ReadMsgData_ExpandPlaceholders
	str r0, [r4]
	mov r3, #0
	str r3, [sp]
	ldr r0, _021EEA78 ; =0x0001020F
	str r6, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	ldr r2, [r4]
	add r0, r5, #0
	mov r1, #1
	bl AddTextPrinterParameterizedWithColor
	add r4, r0, #0
	ldr r2, _021EEA7C ; =0x000003D2
	add r0, r5, #0
	mov r1, #0
	mov r3, #0xd
	bl DrawFrameAndWindow2
	add r0, r4, #0
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	nop
_021EEA78: .word 0x0001020F
_021EEA7C: .word 0x000003D2
	thumb_func_end ov96_021EEA08

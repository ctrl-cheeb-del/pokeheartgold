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

	thumb_func_start ov96_021EAF94
ov96_021EAF94: ; 0x021EAF94
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	add r4, r1, #0
	add r1, sp, #4
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [r5]
	add r6, r2, #0
	bl ov96_021E8BAC
	add r2, sp, #0x10
	add r3, sp, #4
	str r0, [sp]
	ldmia r3!, {r0, r1}
	add r7, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	lsl r0, r4, #0xc
	str r0, [sp, #0x10]
	lsl r0, r6, #0xc
	str r0, [sp, #0x14]
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _021EAFD2
	add r1, r7, #0
	bl Sprite_SetMatrix
_021EAFD2:
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _021EAFDE
	add r1, sp, #0x10
	bl Sprite_SetMatrix
_021EAFDE:
	ldr r0, [r5, #0x10]
	add r1, r6, r0
	ldr r0, [r5, #0x18]
	lsl r0, r0, #1
	sub r0, r1, r0
	ldr r1, [r5, #0x14]
	str r4, [r5, #0x20]
	sub r2, r4, r1
	ldr r1, [r5, #0x18]
	add r1, r0, r1
	str r1, [r5, #0x24]
	lsl r1, r2, #0xc
	lsl r0, r0, #0xc
	str r1, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5]
	bl ov96_021E92AC
	cmp r0, #0
	beq _021EB010
	mov r0, #2
	ldr r1, [sp, #8]
	lsl r0, r0, #0xe
	add r0, r1, r0
	str r0, [sp, #8]
_021EB010:
	ldr r0, [sp]
	add r1, sp, #4
	bl Sprite_SetMatrix
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EAF94


	thumb_func_start ov96_021EB01C
ov96_021EB01C: ; 0x021EB01C
	push {r4, r5, r6, lr}
	ldr r5, [r0, #0x14]
	ldr r4, [r0, #0x28]
	sub r1, r1, r5
	ldr r5, [r0, #0x18]
	lsl r5, r5, #1
	sub r6, r5, r4
	lsr r5, r6, #0x1f
	add r5, r6, r5
	asr r5, r5, #1
	add r4, r4, r5
	sub r2, r2, r4
	bl ov96_021EAD88
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB01C


	thumb_func_start ov96_021EB03C
ov96_021EB03C: ; 0x021EB03C
	push {r4, r5, r6, r7}
	add r4, r0, #0
	add r7, r1, #0
	ldr r1, [r4, #0x18]
	add r6, r3, #0
	ldr r3, [r4, #0x28]
	lsl r5, r1, #1
	add r0, r2, #0
	sub r2, r5, r3
	lsr r1, r2, #0x1f
	add r1, r2, r1
	asr r1, r1, #1
	add r1, r3, r1
	lsl r1, r1, #0xc
	sub r0, r0, r1
	ldr r1, [r4, #0x2c]
	sub r1, r5, r1
	lsl r1, r1, #0xc
	add r1, r0, r1
	ldr r0, [sp, #0x10]
	str r7, [r6]
	str r1, [r0]
	pop {r4, r5, r6, r7}
	bx lr
	thumb_func_end ov96_021EB03C


	thumb_func_start ov96_021EB06C
ov96_021EB06C: ; 0x021EB06C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	add r7, r1, #0
	ldr r1, [r4, #4]
	add r0, r2, #0
	add r6, r3, #0
	cmp r1, #0
	bne _021EB082
	bl GF_AssertFail
	pop {r3, r4, r5, r6, r7, pc}
_021EB082:
	ldr r1, [r4, #0x18]
	ldr r3, [r4, #0x28]
	lsl r5, r1, #1
	sub r2, r5, r3
	lsr r1, r2, #0x1f
	add r1, r2, r1
	asr r1, r1, #1
	add r1, r3, r1
	sub r0, r0, r1
	add r1, r0, r5
	ldr r0, [r4, #0x10]
	sub r1, r1, r0
	ldr r0, [sp, #0x18]
	str r7, [r6]
	str r1, [r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB06C


	thumb_func_start ov96_021EB0A4
ov96_021EB0A4: ; 0x021EB0A4
	push {r3, r4}
	ldr r4, [r0, #0x10]
	add r4, r2, r4
	ldr r2, [r0, #0x18]
	str r1, [r3]
	ldr r1, [r0, #0x28]
	ldr r0, [r0, #0x18]
	lsl r2, r2, #1
	lsl r0, r0, #1
	sub r3, r0, r1
	lsr r0, r3, #0x1f
	add r0, r3, r0
	sub r2, r4, r2
	asr r0, r0, #1
	add r0, r2, r0
	add r1, r1, r0
	ldr r0, [sp, #8]
	str r1, [r0]
	pop {r3, r4}
	bx lr
	thumb_func_end ov96_021EB0A4


	thumb_func_start ov96_021EB0CC
ov96_021EB0CC: ; 0x021EB0CC
	push {r3, r4, lr}
	sub sp, #0x24
	add r4, r0, #0
	lsl r0, r3, #0xc
	str r0, [sp]
	ldr r0, [sp, #0x30]
	str r1, [sp, #0xc]
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	mov r0, #0
	str r2, [sp, #0x10]
	str r0, [sp, #8]
	str r0, [sp, #0x14]
	add r0, sp, #0
	add r1, sp, #0xc
	add r2, sp, #0x18
	bl VEC_Subtract
	add r0, sp, #0x18
	bl VEC_Mag
	ldr r1, [r4, #0x1c]
	lsl r1, r1, #0xc
	cmp r0, r1
	bge _021EB104
	add sp, #0x24
	mov r0, #1
	pop {r3, r4, pc}
_021EB104:
	mov r0, #0
	add sp, #0x24
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB0CC

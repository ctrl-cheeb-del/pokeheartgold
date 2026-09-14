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
	.extern ov96_02216770
	.extern ov96_02216934
	.extern ov96_02216A54
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




	thumb_func_start ov96_02216AA4
ov96_02216AA4: ; 0x02216AA4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	mov r0, #0
	str r0, [sp, #0x18]
	add r0, r3, #0
	add r7, r1, #0
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r4, [sp, #0x40]
	bl PokeathlonCourse_GetDataCopyArea
	add r6, r0, #0
	ldrb r1, [r5]
	add r0, sp, #0x24
	strh r1, [r0]
	ldrb r1, [r5, #1]
	strh r1, [r0, #2]
	ldr r0, [sp, #0x10]
	bl PokeathlonCourse_GetParticipantCount
	cmp r0, r4
	bhi _02216AE6
	mov r0, #1
	str r0, [sp, #0x1c]
	mov r0, #0x28
	add r6, #0x50
	mul r0, r4
	add r0, r6, r0
	bl ov96_021E8A20
	str r0, [sp, #0x20]
	b _02216AF2
_02216AE6:
	mov r0, #0
	str r0, [sp, #0x1c]
	add r0, r6, #0
	bl ov96_021E8A20
	str r0, [sp, #0x20]
_02216AF2:
	ldr r0, [sp, #0x10]
	bl ov96_021E5F24
	cmp r0, #0
	bne _02216B00
	mov r0, #1
	b _02216B02
_02216B00:
	mov r0, #0
_02216B02:
	cmp r0, #0
	beq _02216B12
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _02216B12
	mov r0, #1
	str r0, [sp, #0x14]
	b _02216B16
_02216B12:
	mov r0, #0
	str r0, [sp, #0x14]
_02216B16:
	ldr r0, [sp, #0x10]
	bl ov96_021E5F24
	cmp r4, r0
	bne _02216B24
	mov r6, #1
	b _02216B26
_02216B24:
	mov r6, #0
_02216B26:
	ldr r0, [sp, #0x14]
	add r1, r7, #0
	add r3, r0, #0
	ldrb r0, [r5, #5]
	add r1, #0xe4
	ldr r1, [r1]
	lsl r0, r0, #0x19
	lsl r1, r1, #0x12
	lsr r0, r0, #0x1e
	lsr r1, r1, #0x1e
	orr r3, r6
	cmp r0, r1
	beq _02216B70
	add r0, r7, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _02216BF8 ; =0xFFFFF0FF
	and r1, r0
	add r0, r7, #0
	add r0, #0xe4
	str r1, [r0]
	add r0, r7, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _02216BFC ; =0xFFFFCFFF
	and r0, r1
	ldrb r1, [r5, #5]
	lsl r1, r1, #0x19
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x12
	orr r1, r0
	add r0, r7, #0
	add r0, #0xe4
	str r1, [r0]
	mov r0, #1
	str r0, [sp, #0x18]
_02216B70:
	add r0, r7, #0
	add r0, #0xe4
	ldr r0, [r0]
	lsl r0, r0, #0x12
	lsr r0, r0, #0x1e
	beq _02216BD0
	cmp r0, #1
	beq _02216B88
	cmp r0, #2
	beq _02216BB8
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
_02216B88:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _02216B9E
	ldrb r2, [r5, #4]
	ldr r0, [sp, #0xc]
	add r1, r4, #0
	lsl r2, r2, #0x18
	lsr r2, r2, #0x1e
	mov r3, #1
	bl ov96_0221996C
_02216B9E:
	ldr r0, [sp, #0x20]
	ldr r2, [sp, #0xc]
	str r0, [sp]
	ldr r0, [sp, #0x14]
	add r1, sp, #0x24
	str r0, [sp, #4]
	add r0, r7, #0
	add r3, r4, #0
	str r6, [sp, #8]
	bl ov96_02216770
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
_02216BB8:
	ldr r0, [sp, #0x20]
	ldr r2, [sp, #0xc]
	str r0, [sp]
	str r3, [sp, #4]
	add r0, r7, #0
	add r1, sp, #0x24
	add r3, r4, #0
	str r6, [sp, #8]
	bl ov96_02216934
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
_02216BD0:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _02216BF2
	ldr r2, [sp, #0x20]
	str r6, [sp]
	add r0, r7, #0
	add r1, sp, #0x24
	bl ov96_02216A54
	ldrb r2, [r5, #4]
	ldr r0, [sp, #0xc]
	add r1, r4, #0
	lsl r2, r2, #0x18
	lsr r2, r2, #0x1e
	mov r3, #0
	bl ov96_0221996C
_02216BF2:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02216BF8: .word 0xFFFFF0FF
_02216BFC: .word 0xFFFFCFFF
	thumb_func_end ov96_02216AA4

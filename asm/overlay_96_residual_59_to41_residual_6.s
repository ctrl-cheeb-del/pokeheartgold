	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text
	.public ov96_021F6398
	.public ov96_021F6424
	.public ov96_021F64A0

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


	thumb_func_start ov96_021F6398
ov96_021F6398: ; 0x021F6398
	push {r3, r4, lr}
	sub sp, #0x2c
	ldr r3, _021F6420 ; =ov96_0221C0F4
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x14
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0x65
	str r0, [r2]
	lsl r1, r1, #2
	mov r2, #0
	str r2, [r4, r1]
	add r0, r1, #4
	str r2, [r4, r0]
	add r0, r1, #0
	add r0, #8
	str r2, [r4, r0]
	add r0, sp, #0xc
	strh r2, [r0]
	strh r2, [r0, #2]
	strh r2, [r0, #4]
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	sub r0, r1, #4
	ldr r0, [r4, r0]
	add r2, sp, #0xc
	str r0, [sp, #8]
	add r0, r4, r1
	mov r1, #0x19
	lsl r1, r1, #0xe
	mov r3, #0xa4
	bl Camera_Init_FromTargetDistanceAndAngle
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	add r0, sp, #0x14
	bl Camera_OffsetLookAtPosAndTarget
	mov r2, #0x19
	mov r0, #1
	lsl r2, r2, #4
	lsl r0, r0, #0xe
	ldr r2, [r4, r2]
	lsl r1, r0, #6
	bl Camera_SetPerspectiveClippingPlane
	mov r1, #0
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #0x24]
	str r1, [sp, #0x20]
	str r1, [sp, #0x28]
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	add r0, sp, #0x20
	bl Camera_SetLookAtCamUp
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl Camera_SetStaticPtr
	add sp, #0x2c
	pop {r3, r4, pc}
	.balign 4, 0
_021F6420: .word ov96_0221C0F4
	thumb_func_end ov96_021F6398




	thumb_func_start ov96_021F6424
ov96_021F6424: ; 0x021F6424
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0
	add r2, r1, #0
	mov r3, #1
	add r4, r0, #0
	bl ov96_021F6524
	mov r1, #1
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #2
	bl ov96_021F6524
	mov r1, #2
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0
	bl ov96_021F6524
	mov r2, #2
	lsl r2, r2, #0xa
	mov r3, #6
	mov r0, #0
	lsl r3, r3, #8
	lsr r5, r2, #2
	lsr r6, r2, #1
_021F6458:
	ldr r7, [r4, r5]
	str r7, [r4]
	ldr r1, [r4, r6]
	cmp r7, r1
	ble _021F6464
	str r1, [r4]
_021F6464:
	ldr r7, [r4, r3]
	ldr r1, [r4]
	cmp r1, r7
	ble _021F646E
	str r7, [r4]
_021F646E:
	ldr r7, [r4, r2]
	ldr r1, [r4]
	cmp r1, r7
	ble _021F6478
	str r7, [r4]
_021F6478:
	mov r1, #0xa
	lsl r1, r1, #8
	ldr r7, [r4, r1]
	ldr r1, [r4]
	cmp r1, r7
	ble _021F6486
	str r7, [r4]
_021F6486:
	mov r1, #3
	lsl r1, r1, #0xa
	ldr r7, [r4, r1]
	ldr r1, [r4]
	cmp r1, r7
	ble _021F6494
	str r7, [r4]
_021F6494:
	add r0, r0, #1
	add r4, r4, #4
	cmp r0, #0x80
	blt _021F6458
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F6424




	thumb_func_start ov96_021F64A0
ov96_021F64A0: ; 0x021F64A0
	push {r4, r5, r6, r7}
	mov r4, #1
	mov r5, #2
	mov r6, #4
	mov r3, #0
	and r4, r1
	and r5, r1
	and r1, r6
_021F64B0:
	mov r6, #0
	str r6, [r2]
	cmp r4, #0
	beq _021F64D4
	mov r6, #2
	lsl r6, r6, #8
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F64C6
	str r7, [r2]
_021F64C6:
	mov r6, #2
	lsl r6, r6, #0xa
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F64D4
	str r7, [r2]
_021F64D4:
	cmp r5, #0
	beq _021F64F4
	mov r6, #1
	lsl r6, r6, #0xa
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F64E6
	str r7, [r2]
_021F64E6:
	mov r6, #0xa
	lsl r6, r6, #8
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F64F4
	str r7, [r2]
_021F64F4:
	cmp r1, #0
	beq _021F6514
	mov r6, #6
	lsl r6, r6, #8
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F6506
	str r7, [r2]
_021F6506:
	mov r6, #3
	lsl r6, r6, #0xa
	ldr r7, [r0, r6]
	ldr r6, [r2]
	cmp r6, r7
	ble _021F6514
	str r7, [r2]
_021F6514:
	add r3, r3, #1
	add r2, r2, #4
	add r0, r0, #4
	cmp r3, #0x80
	blt _021F64B0
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021F64A0




	thumb_func_start ov96_021F6524
ov96_021F6524: ; 0x021F6524
	push {r0, r1, r2, r3}
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r3, sp, #0x20
	ldrb r4, [r3, #0xc]
	add r2, r0, #0
	add r0, r1, #0
	mov r1, #0xe
	lsl r1, r1, #8
	ldrb r3, [r3, #8]
	lsl r5, r4, #2
	add r1, r2, r1
	lsl r4, r3, #2
	add r7, r1, r5
	ldr r3, [r1, r4]
	ldr r5, [r1, r5]
	cmp r3, r5
	bgt _021F6550
	add r6, r1, r4
	add r5, sp, #0x28
	add r1, sp, #0x2c
	b _021F6558
_021F6550:
	add r6, r7, #0
	add r7, r1, r4
	add r5, sp, #0x2c
	add r1, sp, #0x28
_021F6558:
	lsl r0, r0, #9
	add r3, r2, r0
	mov ip, r1
	mov r1, #0
	mov r0, #2
	str r3, [sp]
	add r4, r1, #0
	lsl r0, r0, #0xa
_021F6568:
	add r1, r1, #1
	str r4, [r3, r0]
	add r3, r3, #4
	cmp r1, #0x80
	blt _021F6568
	ldrb r1, [r5]
	ldr r0, [r6]
	lsl r1, r1, #9
	add r3, r2, r1
	lsl r1, r0, #2
	add r3, r3, r1
	mov r1, #2
	lsl r1, r1, #8
	ldr r5, [r3, r1]
	mov r3, ip
	ldrb r3, [r3]
	ldr r1, [r7]
	lsl r3, r3, #9
	add r3, r2, r3
	lsl r2, r1, #2
	add r3, r3, r2
	mov r2, #2
	lsl r2, r2, #8
	ldr r2, [r3, r2]
	sub r0, r1, r0
	str r0, [sp, #4]
	sub r0, r0, #1
	sub r7, r2, r5
	str r0, [sp, #8]
	cmp r0, #0
	ble _021F65C8
_021F65A6:
	add r0, r4, #1
	ldr r1, [sp, #4]
	mul r0, r7
	bl _s32_div_f
	ldr r1, [r6]
	add r0, r5, r0
	add r1, r1, r4
	lsl r2, r1, #2
	ldr r1, [sp]
	add r4, r4, #1
	add r2, r1, r2
	ldr r1, _021F65D4 ; =0x00000804
	str r0, [r2, r1]
	ldr r0, [sp, #8]
	cmp r4, r0
	blt _021F65A6
_021F65C8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r3}
	add sp, #0x10
	bx r3
	nop
_021F65D4: .word 0x00000804
	thumb_func_end ov96_021F6524

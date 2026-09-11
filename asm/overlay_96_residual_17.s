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

	thumb_func_start ov96_021E92E0
ov96_021E92E0: ; 0x021E92E0
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0x85
	lsl r1, r1, #2
	add r5, r0, #0
	bl Heap_Alloc
	mov r2, #0x85
	mov r1, #0
	lsl r2, r2, #2
	str r0, [sp]
	bl MI_CpuFill8
	ldr r4, [sp]
	mov r6, #0
	mov r7, #0x25
_021E92FE:
	add r0, r7, #0
	add r1, r5, #0
	bl String_New
	str r0, [r4, #0x34]
	mov r0, #0xb
	add r1, r5, #0
	bl String_New
	str r0, [r4, #0x38]
	add r6, r6, #1
	add r4, #0x18
	cmp r6, #0xc
	blt _021E92FE
	ldr r0, [sp]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E92E0


	thumb_func_start ov96_021E9320
ov96_021E9320: ; 0x021E9320
	push {r4, r5, r6, lr}
	add r6, r0, #0
	mov r4, #0
	add r5, r6, #0
_021E9328:
	ldr r0, [r5, #0x34]
	bl String_Delete
	ldr r0, [r5, #0x38]
	bl String_Delete
	add r4, r4, #1
	add r5, #0x18
	cmp r4, #0xc
	blt _021E9328
	add r0, r6, #0
	bl Heap_Free
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021E9320


	thumb_func_start ov96_021E9344
ov96_021E9344: ; 0x021E9344
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #8]
	cmp r0, #4
	blt _021E9352
	bl GF_AssertFail
_021E9352:
	ldr r1, [r4, #8]
	ldr r0, [r4]
	cmp r1, r0
	blt _021E935E
	bl GF_AssertFail
_021E935E:
	ldr r1, [r4, #8]
	add r0, r1, #1
	str r0, [r4, #8]
	mov r0, #0x18
	add r4, #0x24
	mul r0, r1
	add r0, r4, r0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021E9344


	thumb_func_start ov96_021E9370
ov96_021E9370: ; 0x021E9370
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #4
	blo _021E937E
	bl GF_AssertFail
_021E937E:
	ldr r0, [r5]
	cmp r4, r0
	blt _021E9388
	bl GF_AssertFail
_021E9388:
	mov r0, #0x18
	add r5, #0x24
	mul r0, r4
	add r0, r5, r0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021E9370


	thumb_func_start ov96_021E9394
ov96_021E9394: ; 0x021E9394
	mov r3, #0
	str r3, [r0]
	str r3, [r0, #4]
	str r3, [r0, #8]
	str r3, [r0, #0xc]
	mov r1, #0x51
	str r3, [r0, #0x10]
	add r2, r3, #0
	lsl r1, r1, #2
_021E93A6:
	add r3, r3, #1
	str r2, [r0, r1]
	add r0, r0, #4
	cmp r3, #0xc
	blt _021E93A6
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021E9394


	thumb_func_start ov96_021E93B4
ov96_021E93B4: ; 0x021E93B4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xa4
	str r0, [sp]
	add r0, sp, #0x14
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	cmp r1, #0
	beq _021E93D2
	cmp r1, #1
	beq _021E93D8
	cmp r1, #2
	beq _021E93DE
	b _021E93E4
_021E93D2:
	mov r0, #1
	str r0, [sp, #4]
	b _021E93E8
_021E93D8:
	mov r0, #1
	str r0, [sp, #4]
	b _021E93E8
_021E93DE:
	mov r0, #2
	str r0, [sp, #4]
	b _021E93E8
_021E93E4:
	bl GF_AssertFail
_021E93E8:
	ldr r1, [sp, #4]
	ldr r0, [sp]
	mov r6, #0
	str r1, [r0, #0xc]
	ldr r4, [r0]
	cmp r4, #0
	ble _021E949E
	add r0, #0x24
	mov ip, r0
_021E93FA:
	add r3, r6, #1
	add r2, r3, #0
	mov r0, #0xc
	add r1, sp, #8
	mul r2, r0
	add r0, r1, r2
	mov r3, ip
	mov r7, #0
	str r3, [r0, #8]
	str r7, [r0, #4]
	str r7, [r1, r2]
	cmp r6, #0
	ble _021E9486
_021E9414:
	ldr r2, [sp, #4]
	ldr r1, [r1, #4]
	cmp r2, #1
	ldr r5, [r0, #8]
	bne _021E9450
	ldr r3, [r1, #8]
	ldr r4, [r5, #0xc]
	ldr r2, [r3, #0xc]
	cmp r2, r4
	bge _021E9436
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
	b _021E9486
_021E9436:
	cmp r2, r4
	bne _021E9480
	ldr r2, [r3]
	ldr r3, [r5]
	cmp r2, r3
	ble _021E9480
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
	b _021E9480
_021E9450:
	ldr r3, [r1, #8]
	ldr r4, [r5, #0xc]
	ldr r2, [r3, #0xc]
	cmp r2, r4
	ble _021E9468
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
	b _021E9486
_021E9468:
	cmp r2, r4
	bne _021E9480
	ldr r2, [r3]
	ldr r3, [r5]
	cmp r2, r3
	ble _021E9480
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
_021E9480:
	add r7, r7, #1
	cmp r7, r6
	blt _021E9414
_021E9486:
	cmp r7, r6
	bne _021E948E
	str r0, [r1, #4]
	str r1, [r0]
_021E948E:
	mov r0, ip
	add r0, #0x18
	mov ip, r0
	ldr r0, [sp]
	add r6, r6, #1
	ldr r4, [r0]
	cmp r6, r4
	blt _021E93FA
_021E949E:
	mov r1, #0
	mvn r1, r1
	mov r3, #0
	add r0, sp, #8
	add r2, r1, #0
	add r5, r3, #0
	cmp r4, #0
	ble _021E94E8
	mov r7, #0x51
	ldr r4, [sp]
	lsl r7, r7, #2
_021E94B4:
	ldr r0, [r0, #4]
	ldr r6, [r0, #8]
	str r6, [r4, r7]
	ldr r6, [r0, #8]
	ldr r6, [r6, #0xc]
	cmp r1, r6
	beq _021E94D2
	add r1, r6, #0
	cmp r3, #0
	beq _021E94CE
	add r2, r5, #0
	mov r3, #0
	b _021E94D4
_021E94CE:
	add r2, r2, #1
	b _021E94D4
_021E94D2:
	mov r3, #1
_021E94D4:
	mov r6, #0x51
	lsl r6, r6, #2
	ldr r6, [r4, r6]
	add r5, r5, #1
	strb r2, [r6, #9]
	ldr r6, [sp]
	add r4, r4, #4
	ldr r6, [r6]
	cmp r5, r6
	blt _021E94B4
_021E94E8:
	add sp, #0xa4
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021E93B4


	thumb_func_start ov96_021E94EC
ov96_021E94EC: ; 0x021E94EC
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #4
	blo _021E94FA
	bl GF_AssertFail
_021E94FA:
	ldr r0, [r5]
	cmp r4, r0
	blt _021E9504
	bl GF_AssertFail
_021E9504:
	lsl r0, r4, #2
	add r1, r5, r0
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021E94EC

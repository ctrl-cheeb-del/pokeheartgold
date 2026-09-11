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
	.public absent
	.public exact
	.public partial

	thumb_func_start ov96_021E883C
ov96_021E883C: ; 0x021E883C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	mov r1, #0x1d
	add r5, r0, #0
	add r0, r3, #0
	lsl r1, r1, #4
	add r7, r2, #0
	bl Heap_Alloc
	mov r2, #0x1d
	mov r1, #0
	lsl r2, r2, #4
	add r4, r0, #0
	bl memset
	mov r1, #7
	lsl r1, r1, #6
	str r5, [r4, r1]
	add r0, r1, #4
	str r6, [r4, r0]
	add r1, #8
	str r7, [r4, r1]
	ldr r0, _021E887C ; =ov96_021E8884
	ldr r2, _021E8880 ; =0x00001388
	add r1, r4, #0
	bl SysTask_CreateOnVWaitQueue
	mov r1, #0x73
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E887C: .word ov96_021E8884
_021E8880: .word 0x00001388
	thumb_func_end ov96_021E883C




	thumb_func_start ov96_021E8884
ov96_021E8884: ; 0x021E8884
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r1, #0
	mov r0, #0
	str r0, [sp]
	add r6, r7, #0
_021E8890:
	ldr r0, [r6]
	cmp r0, #1
	bne _021E88EA
	ldr r1, [r6, #0x30]
	cmp r1, #0x26
	bgt _021E88BE
	mov r4, #7
	lsl r4, r4, #6
	ldr r4, [r7, r4]
	mov r3, #0x72
	str r4, [sp, #4]
	ldr r4, [r6, #4]
	mov r5, #0xc
	mul r5, r4
	ldr r4, [sp, #4]
	lsl r3, r3, #2
	add r2, r6, #0
	ldr r3, [r7, r3]
	ldr r4, [r4, r5]
	mov r0, #0
	add r2, #8
	blx r4
	b _021E88E0
_021E88BE:
	mov r4, #7
	lsl r4, r4, #6
	ldr r4, [r7, r4]
	mov r3, #0x72
	mov ip, r4
	ldr r4, [r6, #4]
	mov r5, #0xc
	mul r5, r4
	str r5, [sp, #8]
	lsl r3, r3, #2
	ldr r4, [sp, #8]
	mov r5, ip
	ldr r2, [r6, #0x34]
	ldr r3, [r7, r3]
	ldr r4, [r5, r4]
	mov r0, #0
	blx r4
_021E88E0:
	add r0, r6, #0
	mov r1, #0
	mov r2, #0x38
	bl memset
_021E88EA:
	ldr r0, [sp]
	add r6, #0x38
	add r0, r0, #1
	str r0, [sp]
	cmp r0, #8
	blt _021E8890
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E8884




	thumb_func_start ov96_021E88FC
ov96_021E88FC: ; 0x021E88FC
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl SysTask_Destroy
	add r0, r4, #0
	bl Heap_Free
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021E88FC




	thumb_func_start ov96_021E8914
ov96_021E8914: ; 0x021E8914
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r4, #0
	str r2, [sp]
	add r7, r1, #0
	add r5, r3, #0
	add r0, r4, #0
	add r2, r6, #0
_021E8924:
	ldr r1, [r2]
	cmp r1, #0
	bne _021E8932
	mov r1, #0x38
	mul r1, r0
	add r4, r6, r1
	b _021E893A
_021E8932:
	add r0, r0, #1
	add r2, #0x38
	cmp r0, #8
	blt _021E8924
_021E893A:
	cmp r4, #0
	bne _021E8942
	bl GF_AssertFail
_021E8942:
	mov r0, #7
	lsl r0, r0, #6
	add r1, r7, #0
	ldr r2, [r6, r0]
	sub r1, #0x16
	mov r0, #0xc
	mul r0, r1
	add r0, r2, r0
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _021E8962
	blx r0
	cmp r0, r5
	beq _021E8962
	bl GF_AssertFail
_021E8962:
	cmp r5, #0x26
	ble _021E896A
	bl GF_AssertFail
_021E896A:
	sub r7, #0x16
	str r7, [r4, #4]
	cmp r5, #0
	ble _021E897E
	add r0, r4, #0
	ldr r1, [sp]
	add r0, #8
	add r2, r5, #0
	bl memcpy
_021E897E:
	str r5, [r4, #0x30]
	mov r0, #1
	str r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E8914




	thumb_func_start ov96_021E8988
ov96_021E8988: ; 0x021E8988
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	str r2, [sp, #4]
	mov r4, #0
	str r1, [sp]
	add r6, r3, #0
	add r1, r4, #0
	add r2, r5, #0
_021E899A:
	ldr r0, [r2]
	cmp r0, #0
	bne _021E89A8
	mov r0, #0x38
	mul r0, r1
	add r4, r5, r0
	b _021E89B0
_021E89A8:
	add r1, r1, #1
	add r2, #0x38
	cmp r1, #8
	blt _021E899A
_021E89B0:
	cmp r4, #0
	bne _021E89B8
	bl GF_AssertFail
_021E89B8:
	ldr r1, [sp]
	mov r0, #0xc
	sub r1, #0x16
	add r7, r1, #0
	mul r7, r0
	mov r0, #7
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r0, r0, r7
	ldr r0, [r0, #4]
	blx r0
	ldr r1, _021E8A1C ; =0x0000FFFF
	cmp r0, r1
	beq _021E89DC
	cmp r0, r6
	beq _021E89DC
	bl GF_AssertFail
_021E89DC:
	mov r1, #7
	lsl r1, r1, #6
	ldr r0, [r5, r1]
	add r0, r0, r7
	ldr r3, [r0, #8]
	cmp r3, #0
	beq _021E8A06
	add r1, #8
	ldr r1, [r5, r1]
	mov r0, #0
	add r2, r6, #0
	blx r3
	add r5, r0, #0
	cmp r6, #0
	ble _021E8A02
	ldr r1, [sp, #4]
	add r2, r6, #0
	bl memcpy
_021E8A02:
	str r5, [r4, #0x34]
	b _021E8A0A
_021E8A06:
	ldr r0, [sp, #4]
	str r0, [r4, #0x34]
_021E8A0A:
	ldr r0, [sp]
	sub r0, #0x16
	str r0, [r4, #4]
	str r0, [sp]
	str r6, [r4, #0x30]
	mov r0, #1
	str r0, [r4]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E8A1C: .word 0x0000FFFF
	thumb_func_end ov96_021E8988

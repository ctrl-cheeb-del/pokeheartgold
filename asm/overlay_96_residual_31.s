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

	thumb_func_start ov96_021EB144
ov96_021EB144: ; 0x021EB144
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #4]
	mov r4, #0
	cmp r0, #0
	ble _021EB17C
	cmp r1, #0
	bne _021EB158
	mov r6, #1
	b _021EB15A
_021EB158:
	add r6, r4, #0
_021EB15A:
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_021EAA04
	bl ov96_021EAA20
	bl ov96_021E8BAC
	add r1, r6, #0
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, [r5, #4]
	cmp r4, r0
	blt _021EB15A
_021EB17C:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB144


	thumb_func_start ov96_021EB180
ov96_021EB180: ; 0x021EB180
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	mov r1, #0x56
	lsl r1, r1, #2
	add r6, r0, #0
	bl Heap_Alloc
	add r4, r0, #0
	mov r2, #0x56
	mov r0, #0
	add r1, r4, #0
	lsl r2, r2, #2
	bl MIi_CpuClearFast
	str r6, [r4]
	add r2, r4, #0
	ldmia r5!, {r0, r1}
	add r2, #8
	stmia r2!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0x14
	str r0, [r2]
	ldr r2, [r4, #0xc]
	add r0, r6, #0
	mul r1, r2
	bl Heap_Alloc
	mov r1, #0x15
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r3, [r4, #0xc]
	mov r2, #0x14
	ldr r1, [r4, r1]
	mov r0, #0
	mul r2, r3
	bl MIi_CpuClear32
	ldr r2, [r4, #8]
	mov r1, #0xc
	ldr r0, [r4]
	mul r1, r2
	bl Heap_Alloc
	mov r1, #0x55
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r3, [r4, #8]
	mov r2, #0xc
	ldr r1, [r4, r1]
	mov r0, #0
	mul r2, r3
	bl MIi_CpuClear32
	add r1, r4, #0
	ldr r0, [r4, #8]
	ldr r2, [r4]
	add r1, #0x18
	bl G2dRenderer_Init
	mov r7, #5
	str r0, [r4, #0x14]
	mov r5, #0
	add r6, r4, #0
	lsl r7, r7, #6
_021EB200:
	add r0, r4, r5
	ldrb r0, [r0, #0x10]
	ldr r2, [r4]
	add r1, r5, #0
	bl Create2DGfxResObjMan
	str r0, [r6, r7]
	add r5, r5, #1
	add r6, r6, #4
	cmp r5, #4
	blt _021EB200
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB180


	thumb_func_start ov96_021EB21C
ov96_021EB21C: ; 0x021EB21C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r4, #0
	cmp r0, #0
	ble _021EB25E
	mov r7, #0x15
	lsl r7, r7, #4
_021EB22C:
	mov r0, #0x14
	add r6, r4, #0
	mul r6, r0
	ldr r0, [r5, r7]
	add r0, r0, r6
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _021EB240
	bl SpriteTransfer_DeleteCharTransferTask
_021EB240:
	mov r0, #0x15
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r0, r0, r6
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021EB252
	bl SpriteTransfer_DeletePlttTransferTask
_021EB252:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, [r5, #0xc]
	cmp r4, r0
	blt _021EB22C
_021EB25E:
	mov r6, #5
	mov r4, #0
	lsl r6, r6, #6
_021EB264:
	lsl r0, r4, #2
	add r0, r5, r0
	ldr r0, [r0, r6]
	bl Destroy2DGfxResObjMan
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021EB264
	ldr r0, [r5, #0x14]
	bl SpriteList_Delete
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Heap_Free
	mov r0, #0x15
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl Heap_Free
	add r0, r5, #0
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB21C


	thumb_func_start ov96_021EB29C
ov96_021EB29C: ; 0x021EB29C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	add r4, r1, #0
	add r6, r2, #0
	cmp r4, r0
	blt _021EB2AE
	bl GF_AssertFail
_021EB2AE:
	mov r0, #0x15
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	mov r0, #0x14
	mul r0, r4
	str r6, [r1, r0]
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021EB29C


	thumb_func_start ov96_021EB2BC
ov96_021EB2BC: ; 0x021EB2BC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #0xc]
	add r1, r3, #0
	mov r2, #0
	add r5, r0, #0
	bl ov96_021EB5EC
	add r4, r0, #0
	ldr r0, [sp, #0xc]
	add r1, r6, #0
	str r0, [sp]
	ldr r0, [sp, #0x28]
	add r2, r7, #0
	str r0, [sp, #4]
	ldr r0, [r5]
	mov r3, #0
	str r0, [sp, #8]
	mov r0, #5
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl AddCharResObjFromNarc
	str r0, [r4]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EB2BC


	thumb_func_start ov96_021EB2F4
ov96_021EB2F4: ; 0x021EB2F4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #0x10]
	add r1, r3, #0
	mov r2, #1
	add r5, r0, #0
	bl ov96_021EB5EC
	add r4, r0, #0
	ldr r0, [sp, #0x10]
	add r1, r6, #0
	str r0, [sp]
	ldr r0, [sp, #0x28]
	add r2, r7, #0
	str r0, [sp, #4]
	add r0, sp, #0x18
	ldrb r0, [r0, #0x14]
	mov r3, #0
	str r0, [sp, #8]
	ldr r0, [r5]
	str r0, [sp, #0xc]
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl AddPlttResObjFromNarc
	str r0, [r4]
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB2F4


	thumb_func_start ov96_021EB334
ov96_021EB334: ; 0x021EB334
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #0xc]
	add r1, r3, #0
	mov r2, #2
	add r5, r0, #0
	bl ov96_021EB5EC
	add r4, r0, #0
	ldr r0, [sp, #0xc]
	add r1, r6, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5]
	add r2, r7, #0
	str r0, [sp, #8]
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EB334


	thumb_func_start ov96_021EB36C
ov96_021EB36C: ; 0x021EB36C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #0xc]
	add r1, r3, #0
	mov r2, #3
	add r5, r0, #0
	bl ov96_021EB5EC
	add r4, r0, #0
	ldr r0, [sp, #0xc]
	add r1, r6, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r5]
	add r2, r7, #0
	str r0, [sp, #8]
	mov r0, #0x53
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EB36C


	thumb_func_start ov96_021EB3A4
ov96_021EB3A4: ; 0x021EB3A4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r6, #0
	cmp r0, #0
	ble _021EB3E0
	mov r7, #0x15
	add r4, r6, #0
	lsl r7, r7, #4
_021EB3B6:
	ldr r0, [r5, r7]
	add r0, r0, r4
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _021EB3C4
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021EB3C4:
	mov r0, #0x15
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r0, r0, r4
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021EB3D6
	bl SpriteTransfer_CreateExtPlttTransferTask
_021EB3D6:
	ldr r0, [r5, #0xc]
	add r6, r6, #1
	add r4, #0x14
	cmp r6, r0
	blt _021EB3B6
_021EB3E0:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB3A4


	thumb_func_start ov96_021EB3E4
ov96_021EB3E4: ; 0x021EB3E4
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r6, sp, #8
	ldrb r6, [r6, #0x10]
	add r5, r0, #0
	add r4, r3, #0
	str r6, [sp]
	bl ov96_021EB408
	add r2, sp, #8
	ldrb r2, [r2, #0x10]
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_021EB4F4
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB3E4


	thumb_func_start ov96_021EB408
ov96_021EB408: ; 0x021EB408
	push {r4, r5, r6, r7, lr}
	sub sp, #0x84
	add r5, r0, #0
	str r3, [sp, #0x2c]
	add r4, r1, #0
	ldr r1, [r5, #4]
	ldr r0, [r5, #8]
	add r6, r2, #0
	cmp r1, r0
	blt _021EB420
	bl GF_AssertFail
_021EB420:
	ldr r0, [sp, #0x2c]
	mov r2, #5
	str r0, [sp]
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	lsl r2, r2, #6
	ldr r1, [r5, r2]
	str r1, [sp, #0x14]
	add r1, r2, #4
	ldr r1, [r5, r1]
	str r1, [sp, #0x18]
	add r1, r2, #0
	add r1, #8
	ldr r1, [r5, r1]
	add r2, #0xc
	str r1, [sp, #0x1c]
	ldr r1, [r5, r2]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	add r0, sp, #0x60
	add r2, r1, #0
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	ldr r0, [r5, #0x14]
	mov r1, #0
	str r0, [sp, #0x30]
	add r0, sp, #0x60
	str r0, [sp, #0x34]
	ldr r0, [r5]
	str r0, [sp, #0x5c]
	mov r0, #1
	lsl r0, r0, #0xc
	str r1, [sp, #0x38]
	str r1, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r0, [sp, #0x44]
	str r0, [sp, #0x48]
	str r0, [sp, #0x4c]
	add r0, sp, #0x30
	strh r1, [r0, #0x20]
	add r0, sp, #0x30
	str r1, [sp, #0x54]
	str r6, [sp, #0x58]
	bl Sprite_CreateAffine
	add r4, r0, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r7, #0x55
	ldr r1, [r5, #4]
	lsl r7, r7, #2
	ldr r3, [r5, r7]
	mov r0, #0xc
	add r2, r1, #0
	mov r6, #0
	mul r2, r0
	strh r6, [r3, r2]
	ldr r1, [r5, #4]
	ldr r3, [r5, r7]
	add r2, r1, #0
	mul r2, r0
	add r1, r3, r2
	strh r6, [r1, #2]
	ldr r1, [r5, #4]
	ldr r3, [r5, r7]
	add r2, r1, #0
	mul r2, r0
	add r1, r3, r2
	str r4, [r1, #4]
	add r1, sp, #0x88
	ldrb r6, [r1, #0x10]
	ldr r1, [r5, #4]
	ldr r3, [r5, r7]
	add r2, r1, #0
	mul r2, r0
	add r1, r3, r2
	strh r6, [r1, #8]
	ldr r1, [r5, #4]
	ldr r2, [r5, r7]
	mul r0, r1
	add r1, r2, r0
	ldr r0, [sp, #0x2c]
	strh r0, [r1, #0xa]
	ldr r0, [r5, #4]
	add r0, r0, #1
	str r0, [r5, #4]
	add r0, r4, #0
	add sp, #0x84
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EB408


	thumb_func_start ov96_021EB4F4
ov96_021EB4F4: ; 0x021EB4F4
	push {r3, r4, r5, lr}
	ldr r4, [r0, #8]
	mov r3, #0
	cmp r4, #0
	ble _021EB524
	mov r5, #0x55
	lsl r5, r5, #2
	ldr r0, [r0, r5]
_021EB504:
	ldrh r5, [r0]
	cmp r5, #0
	bne _021EB51C
	ldrh r5, [r0, #0xa]
	cmp r5, r1
	bne _021EB51C
	ldrh r5, [r0, #8]
	cmp r5, r2
	bne _021EB51C
	mov r1, #1
	strh r1, [r0]
	pop {r3, r4, r5, pc}
_021EB51C:
	add r3, r3, #1
	add r0, #0xc
	cmp r3, r4
	blt _021EB504
_021EB524:
	bl GF_AssertFail
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021EB4F4


	thumb_func_start ov96_021EB52C
ov96_021EB52C: ; 0x021EB52C
	push {r3, lr}
	ldrh r3, [r0]
	cmp r3, #0
	beq _021EB55C
	cmp r1, #0
	beq _021EB550
	mov r1, #1
	strh r1, [r0, #2]
	cmp r2, #0
	ldr r0, [r0, #4]
	beq _021EB548
	bl Sprite_SetDrawFlag
	pop {r3, pc}
_021EB548:
	mov r1, #0
	bl Sprite_SetDrawFlag
	pop {r3, pc}
_021EB550:
	mov r1, #0
	strh r1, [r0, #2]
	ldr r0, [r0, #4]
	bl Sprite_SetDrawFlag
	pop {r3, pc}
_021EB55C:
	bl GF_AssertFail
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov96_021EB52C

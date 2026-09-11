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

	thumb_func_start ov96_021E8BB4
ov96_021E8BB4: ; 0x021E8BB4
	push {r4, r5, r6, lr}
	add r4, r0, #0
	add r5, r1, #0
	add r6, r2, #0
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldrb r2, [r4, #7]
	bl ov96_021E91B8
	add r1, r0, #0
	mov r0, #0x51
	add r2, r5, #0
	bl AllocAndReadWholeNarcMemberByIdPair
	add r5, r0, #0
	bl NNS_G3dGetTex
	ldr r1, [r0, #0x38]
	add r0, r0, r1
	ldrb r1, [r4, #6]
	cmp r1, #0
	beq _021E8BE2
	add r0, #0x20
_021E8BE2:
	add r1, r6, #0
	mov r2, #0x20
	bl MI_CpuCopy8
	add r0, r5, #0
	bl Heap_Free
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021E8BB4


	thumb_func_start ov96_021E8BF4
ov96_021E8BF4: ; 0x021E8BF4
	push {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	add r6, r0, #0
	add r7, r3, #0
	str r4, [sp]
	cmp r2, #3
	bne _021E8C08
	mov r4, #1
	str r4, [sp]
	b _021E8C14
_021E8C08:
	cmp r2, #1
	bne _021E8C12
	mov r0, #1
	str r0, [sp]
	b _021E8C14
_021E8C12:
	mov r4, #1
_021E8C14:
	mov r0, #0x2c
	add r5, r1, #0
	mul r5, r0
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	ldr r0, [r0, r5]
	bl SpriteTransfer_GetCharProxy
	add r1, r0, #0
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	add r0, r0, r5
	ldr r0, [r0, #4]
	bl SpriteTransfer_GetPaletteProxy
	add r5, r0, #0
	add r0, r7, #0
	mov r1, #0x20
	bl DC_FlushRange
	ldr r0, [sp]
	cmp r0, #0
	beq _021E8C58
	add r0, r5, #0
	mov r1, #1
	bl NNS_G2dGetImagePaletteLocation
	add r1, r0, #0
	add r0, r7, #0
	mov r2, #0x20
	bl GX_LoadOBJPltt
_021E8C58:
	cmp r4, #0
	beq _021E8C6E
	add r0, r5, #0
	mov r1, #2
	bl NNS_G2dGetImagePaletteLocation
	add r1, r0, #0
	add r0, r7, #0
	mov r2, #0x20
	bl GXS_LoadOBJPltt
_021E8C6E:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021E8BF4


	thumb_func_start ov96_021E8C70
ov96_021E8C70: ; 0x021E8C70
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x48
	add r5, r0, #0
	ldr r0, [sp, #0x64]
	add r4, r1, #0
	add r6, r3, #0
	str r2, [sp, #0x10]
	str r0, [sp, #0x64]
	cmp r0, #0
	beq _021E8CA4
	add r0, r2, #0
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _021E8C98
	mov r0, #0xa
	str r0, [sp, #0x44]
	mov r0, #9
	mov r2, #0xb
	str r0, [sp, #0x40]
	b _021E8CC2
_021E8C98:
	mov r0, #7
	str r0, [sp, #0x44]
	mov r0, #6
	mov r2, #8
	str r0, [sp, #0x40]
	b _021E8CC2
_021E8CA4:
	add r0, r2, #0
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _021E8CB8
	mov r0, #4
	str r0, [sp, #0x44]
	mov r0, #3
	mov r2, #5
	str r0, [sp, #0x40]
	b _021E8CC2
_021E8CB8:
	mov r0, #1
	str r0, [sp, #0x44]
	mov r0, #0
	mov r2, #2
	str r0, [sp, #0x40]
_021E8CC2:
	add r0, sp, #0x50
	ldrb r7, [r0, #0x10]
	mov r1, #0x95
	mov r3, #0
	str r7, [sp]
	str r6, [sp, #4]
	ldr r0, [r5]
	str r0, [sp, #8]
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl AddCharResObjFromNarc
	str r0, [r4]
	str r7, [sp]
	str r6, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5]
	mov r1, #0x31
	str r0, [sp, #0xc]
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r2, #0x1e
	mov r3, #0
	bl AddPlttResObjFromNarc
	str r0, [r4, #4]
	str r7, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5]
	ldr r2, [sp, #0x44]
	str r0, [sp, #8]
	mov r0, #0x53
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x95
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #8]
	str r7, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r5]
	ldr r2, [sp, #0x40]
	str r0, [sp, #8]
	mov r0, #0x15
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x95
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0xc]
	ldr r0, [r4]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	ldr r0, [r4, #4]
	bl SpriteTransfer_CreateExtPlttTransferTask
	mov r0, #0
	str r0, [sp, #0x1c]
	str r0, [sp, #0x18]
	ldr r0, [r4]
	bl SpriteTransfer_GetCharProxy
	str r0, [sp, #0x24]
	ldr r0, [r4, #4]
	ldr r1, [sp, #0x24]
	bl SpriteTransfer_GetPaletteProxy
	str r0, [sp, #0x28]
	ldr r0, [r4]
	bl GF2DGfxResObj_GetCharDataPtr
	str r0, [sp, #0x20]
	cmp r6, #3
	bne _021E8D6C
	mov r0, #1
	str r0, [sp, #0x1c]
	str r0, [sp, #0x18]
	b _021E8D7A
_021E8D6C:
	cmp r6, #1
	bne _021E8D76
	mov r0, #1
	str r0, [sp, #0x1c]
	b _021E8D7A
_021E8D76:
	mov r0, #1
	str r0, [sp, #0x18]
_021E8D7A:
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x10]
	ldrh r0, [r0]
	ldrh r1, [r1, #2]
	ldrb r2, [r2, #7]
	bl ov96_021E91B8
	add r1, r0, #0
	ldr r2, [r5]
	mov r0, #0x51
	bl AllocAndReadWholeNarcMemberByIdPair
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x10]
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _021E8DAA
	mov r0, #2
	lsl r0, r0, #0xa
	str r0, [sp, #0x14]
	mov r0, #8
	str r0, [sp, #0x3c]
	b _021E8DB4
_021E8DAA:
	mov r0, #2
	lsl r0, r0, #8
	str r0, [sp, #0x14]
	mov r0, #4
	str r0, [sp, #0x3c]
_021E8DB4:
	ldr r0, [sp, #0x34]
	bl NNS_G3dGetTex
	ldr r1, [r0, #0x14]
	str r0, [sp, #0x2c]
	add r0, r0, r1
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x3c]
	mov r4, #0
	lsl r1, r0, #5
	mov r0, #2
	lsl r0, r0, #0xa
	str r4, [sp, #0x38]
	sub r7, r0, r1
	add r6, r5, r1
_021E8DD2:
	ldr r0, [sp, #0x3c]
	mov r2, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x56
	lsl r0, r0, #2
	add r0, r5, r0
	str r0, [sp, #8]
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x3c]
	add r0, r0, r4
	add r3, r2, #0
	bl sub_020145B4
	ldr r0, [sp, #0x64]
	cmp r0, #0
	bne _021E8E72
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _021E8E2A
	ldr r0, [sp, #0x10]
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _021E8E2A
	mov r0, #0
_021E8E04:
	cmp r0, r7
	bge _021E8E16
	mov r1, #0x56
	add r2, r6, r0
	lsl r1, r1, #2
	ldrb r3, [r2, r1]
	add r2, r5, r0
	strb r3, [r2, r1]
	b _021E8E20
_021E8E16:
	mov r2, #0x56
	add r3, r5, r0
	lsl r2, r2, #2
	mov r1, #0
	strb r1, [r3, r2]
_021E8E20:
	mov r1, #2
	add r0, r0, #1
	lsl r1, r1, #0xa
	cmp r0, r1
	blt _021E8E04
_021E8E2A:
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r1, [sp, #0x14]
	add r0, r5, r0
	bl DC_FlushRange
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _021E8E54
	ldr r0, [sp, #0x24]
	mov r1, #1
	bl NNS_G2dGetImageLocation
	add r1, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r2, [sp, #0x14]
	add r0, r5, r0
	add r1, r1, r4
	bl GX_LoadOBJ
_021E8E54:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _021E8E72
	ldr r0, [sp, #0x24]
	mov r1, #2
	bl NNS_G2dGetImageLocation
	add r1, r0, #0
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r2, [sp, #0x14]
	add r0, r5, r0
	add r1, r1, r4
	bl GXS_LoadOBJ
_021E8E72:
	ldr r1, [sp, #0x20]
	mov r0, #0x56
	ldr r1, [r1, #0x14]
	lsl r0, r0, #2
	ldr r2, [sp, #0x14]
	add r0, r5, r0
	add r1, r1, r4
	bl MIi_CpuCopyFast
	ldr r0, [sp, #0x14]
	add r4, r4, r0
	ldr r0, [sp, #0x38]
	add r0, r0, #1
	str r0, [sp, #0x38]
	cmp r0, #8
	blt _021E8DD2
	ldr r0, [sp, #0x2c]
	ldr r1, [r0, #0x38]
	add r4, r0, r1
	ldr r0, [sp, #0x10]
	ldrb r0, [r0, #6]
	cmp r0, #0
	beq _021E8EA2
	add r4, #0x20
_021E8EA2:
	add r0, r4, #0
	mov r1, #0x20
	bl DC_FlushRange
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _021E8EC2
	ldr r0, [sp, #0x28]
	mov r1, #1
	bl NNS_G2dGetImagePaletteLocation
	add r1, r0, #0
	add r0, r4, #0
	mov r2, #0x20
	bl GX_LoadOBJPltt
_021E8EC2:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _021E8EDA
	ldr r0, [sp, #0x28]
	mov r1, #2
	bl NNS_G2dGetImagePaletteLocation
	add r1, r0, #0
	add r0, r4, #0
	mov r2, #0x20
	bl GXS_LoadOBJPltt
_021E8EDA:
	ldr r0, [sp, #0x34]
	bl Heap_Free
	add sp, #0x48
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021E8C70


	thumb_func_start ov96_021E8EE4
ov96_021E8EE4: ; 0x021E8EE4
	push {r3, r4, r5, lr}
	sub sp, #0x80
	add r4, r0, #0
	add r0, sp, #0x80
	add r5, r3, #0
	ldrb r3, [r0, #0x10]
	mov r0, #0
	mvn r0, r0
	str r3, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r1, #0x51
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r2, r3, #0
	str r0, [sp, #0x14]
	add r0, r1, #4
	ldr r0, [r4, r0]
	str r0, [sp, #0x18]
	add r0, r1, #0
	add r0, #8
	ldr r0, [r4, r0]
	add r1, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [r4, r1]
	add r1, r3, #0
	str r0, [sp, #0x20]
	mov r0, #0
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, sp, #0x5c
	bl CreateSpriteResourcesHeader
	cmp r5, #3
	bne _021E8F30
	mov r5, #1
_021E8F30:
	ldr r0, [r4, #0x18]
	mov r1, #0
	str r0, [sp, #0x2c]
	add r0, sp, #0x5c
	str r0, [sp, #0x30]
	ldr r0, [r4]
	str r0, [sp, #0x58]
	mov r0, #1
	lsl r0, r0, #0xc
	str r1, [sp, #0x34]
	str r1, [sp, #0x38]
	str r1, [sp, #0x3c]
	str r0, [sp, #0x40]
	str r0, [sp, #0x44]
	str r0, [sp, #0x48]
	add r0, sp, #0x2c
	strh r1, [r0, #0x20]
	str r5, [sp, #0x54]
	add r0, sp, #0x80
	str r1, [sp, #0x50]
	ldrb r1, [r0, #0x14]
	mov r0, #0x2c
	add r5, r1, #0
	mul r5, r0
	add r0, sp, #0x2c
	bl Sprite_CreateAffine
	mov r1, #0x55
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	add r2, r2, r5
	str r0, [r2, #0x10]
	ldr r0, [r4, r1]
	add r0, r0, r5
	ldr r0, [r0, #0x10]
	cmp r0, #0
	bne _021E8F7E
	bl GF_AssertFail
_021E8F7E:
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	add r0, r0, r5
	ldr r0, [r0, #0x10]
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, r0, r5
	ldr r0, [r0, #0x10]
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, r0, r5
	ldr r0, [r0, #0x10]
	bl Sprite_SetDrawFlag
	add sp, #0x80
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021E8EE4


	thumb_func_start ov96_021E8FB4
ov96_021E8FB4: ; 0x021E8FB4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
_021E8FBA:
	add r0, r4, #0
	bl ov96_021E8FE0
	cmp r0, #0
	beq _021E8FD8
	ldr r0, [r4, #0xc]
	mov r1, #1
	str r1, [r0, #0xc]
	add r0, r4, #0
	bl Heap_Free
	add r0, r5, #0
	bl SysTask_Destroy
	pop {r3, r4, r5, pc}
_021E8FD8:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _021E8FBA
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021E8FB4


	thumb_func_start ov96_021E8FE0
ov96_021E8FE0: ; 0x021E8FE0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _021E8FF2
	cmp r0, #1
	beq _021E90BE
	b _021E90F4
_021E8FF2:
	ldrh r0, [r5, #2]
	ldr r1, [r5, #4]
	add r2, r5, #0
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	mov r0, #0x2c
	add r4, r7, #0
	mul r4, r0
	ldr r0, [r5, #0xc]
	lsl r6, r7, #4
	str r7, [sp]
	ldr r1, [r5, #0x18]
	add r2, #0x54
	str r1, [sp, #4]
	mov r1, #0x55
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	ldr r3, [r5, #0x1c]
	add r1, r1, r4
	add r2, r2, r6
	bl ov96_021E8C70
	mov r0, #0x55
	add r3, r5, r6
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r3, #0x54
	add r2, r0, r4
	add r2, #0x14
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r0, #0x55
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r0, r0, r4
	bl ov96_021E9104
	mov r1, #0x55
	ldr r2, [r5, #0xc]
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	add r1, r1, r4
	str r0, [r1, #0x24]
	ldr r2, [r5, #0xc]
	mov r1, #0
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _021E9068
	add r0, r5, r6
	add r0, #0x58
	ldrh r0, [r0]
	cmp r0, #0
	beq _021E9068
	mov r1, #1
_021E9068:
	mov r3, #0x55
	lsl r3, r3, #2
	mov r0, #0x2c
	ldr r2, [r2, r3]
	mul r0, r7
	add r2, r2, r0
	str r1, [r2, #0x28]
	ldr r1, [r5, #0xc]
	ldr r1, [r1, r3]
	add r0, r1, r0
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _021E908A
	add r1, #0x24
	ldr r0, [r1, r4]
	add r0, #8
	str r0, [r1, r4]
_021E908A:
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _021E90A6
	mov r0, #0x55
	ldr r1, [r5, #0xc]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r6, r0, r4
	ldr r0, [r0, r4]
	bl sub_0200A740
	ldr r0, [r6, #4]
	bl sub_0200A740
_021E90A6:
	ldrh r0, [r5, #2]
	add r0, r0, #1
	strh r0, [r5, #2]
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	cmp r1, r0
	blo _021E90F4
	mov r0, #0
	strh r0, [r5, #2]
	mov r0, #1
	str r0, [r5, #8]
	b _021E90F4
_021E90BE:
	ldrh r0, [r5, #2]
	ldr r1, [r5, #4]
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #0x14]
	ldr r2, [r5, #0x18]
	ldr r3, [r5, #0x20]
	bl ov96_021E8EE4
	ldrh r0, [r5, #2]
	add r0, r0, #1
	strh r0, [r5, #2]
	ldr r1, [r5, #0xc]
	ldrh r0, [r1, #6]
	add r0, r0, #1
	strh r0, [r1, #6]
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	cmp r1, r0
	blo _021E90F4
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E90F4:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E8FE0

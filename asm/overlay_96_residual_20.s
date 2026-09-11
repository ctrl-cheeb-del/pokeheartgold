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

	thumb_func_start ov96_021E9D10
ov96_021E9D10: ; 0x021E9D10
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r1, [r4, #4]
	mov r0, #1
	tst r1, r0
	beq _021E9D6E
	mov r1, #0x14
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r2, #3
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x1c]
	mov r0, #0x14
	str r0, [sp]
	mov r2, #2
	str r2, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x4c]
	mov r0, #0x14
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #1
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x7c]
	ldr r0, [r4, #0x1c]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021E9D6E:
	ldr r1, [r4, #4]
	mov r0, #4
	tst r0, r1
	beq _021E9DCE
	mov r0, #0x15
	str r0, [sp]
	ldr r0, [r4, #8]
	mov r1, #0x99
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r2, #6
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x20]
	mov r0, #0x15
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #5
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x50]
	mov r0, #0x15
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #4
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0x80
	str r0, [r1]
	ldr r0, [r4, #0x20]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021E9DCE:
	ldr r1, [r4, #4]
	mov r0, #2
	tst r0, r1
	beq _021E9E2E
	mov r0, #0x16
	str r0, [sp]
	ldr r0, [r4, #8]
	mov r1, #0x99
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r2, #9
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x24]
	mov r0, #0x16
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #8
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x54]
	mov r0, #0x16
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #7
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0x84
	str r0, [r1]
	ldr r0, [r4, #0x24]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021E9E2E:
	ldr r0, [r4, #4]
	mov r2, #0x10
	tst r0, r2
	beq _021E9E8C
	mov r0, #0x1a
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x2c]
	mov r0, #0x1a
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #0xf
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x5c]
	mov r0, #0x1a
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #0xe
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0x8c
	str r0, [r1]
	ldr r0, [r4, #0x2c]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021E9E8C:
	ldr r1, [r4, #4]
	mov r0, #0x20
	tst r0, r1
	beq _021E9EEC
	mov r0, #0x1b
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r2, #0x13
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x30]
	mov r0, #0x1b
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #0x12
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x60]
	mov r0, #0x1b
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #0x11
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0x90
	str r0, [r1]
	ldr r0, [r4, #0x30]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021E9EEC:
	ldr r1, [r4, #4]
	mov r0, #8
	tst r0, r1
	beq _021E9F4C
	mov r0, #0x19
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r2, #0xd
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x28]
	mov r0, #0x19
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #0xc
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x58]
	mov r0, #0x19
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #0xb
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0x88
	str r0, [r1]
	ldr r0, [r4, #0x28]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021E9F4C:
	ldr r1, [r4, #4]
	mov r0, #0x40
	tst r0, r1
	beq _021E9FAC
	mov r0, #0x1c
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r2, #0x16
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x34]
	mov r0, #0x1c
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #0x15
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x64]
	mov r0, #0x1c
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #0x14
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0x94
	str r0, [r1]
	ldr r0, [r4, #0x34]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021E9FAC:
	ldr r1, [r4, #4]
	mov r0, #0x80
	tst r0, r1
	beq _021EA00C
	mov r0, #0x1d
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r2, #0x19
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x38]
	mov r0, #0x1d
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #0x18
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x68]
	mov r0, #0x1d
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #0x17
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0x98
	str r0, [r1]
	ldr r0, [r4, #0x38]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021EA00C:
	mov r0, #1
	ldr r1, [r4, #4]
	lsl r0, r0, #8
	tst r0, r1
	beq _021EA06E
	mov r0, #0x1e
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r2, #0x1c
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x3c]
	mov r0, #0x1e
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #0x1b
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x6c]
	mov r0, #0x1e
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #0x1a
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0x9c
	str r0, [r1]
	ldr r0, [r4, #0x3c]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021EA06E:
	mov r0, #2
	ldr r1, [r4, #4]
	lsl r0, r0, #8
	tst r0, r1
	beq _021EA0CE
	mov r2, #0x1f
	str r2, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x40]
	mov r0, #0x1f
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #0x1e
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x70]
	mov r0, #0x1f
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #0x1d
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0xa0
	str r0, [r1]
	ldr r0, [r4, #0x40]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021EA0CE:
	mov r0, #1
	ldr r1, [r4, #4]
	lsl r0, r0, #0xa
	tst r0, r1
	beq _021EA130
	mov r0, #0x1f
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r2, #0x22
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x44]
	mov r0, #0x1f
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #0x21
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x74]
	mov r0, #0x1f
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #0x20
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0xa4
	str r0, [r1]
	ldr r0, [r4, #0x44]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021EA130:
	mov r0, #2
	ldr r1, [r4, #4]
	lsl r0, r0, #0xa
	tst r0, r1
	beq _021EA192
	mov r0, #0x20
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r2, #0x25
	mov r3, #0
	bl AddCharResObjFromNarc
	str r0, [r4, #0x48]
	mov r0, #0x20
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r2, #0x24
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x78]
	mov r0, #0x20
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #8]
	ldr r0, [r4, #0x18]
	mov r2, #0x23
	mov r3, #0
	bl AddCellOrAnimResObjFromNarc
	add r1, r4, #0
	add r1, #0xa8
	str r0, [r1]
	ldr r0, [r4, #0x48]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
_021EA192:
	ldr r1, [r4, #8]
	cmp r1, #2
	bne _021EA19A
	mov r1, #3
_021EA19A:
	mov r0, #0x17
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r2, #0
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x10]
	mov r1, #0x99
	add r3, r2, #0
	bl AddPlttResObjFromNarc
	add r1, r4, #0
	add r1, #0xac
	str r0, [r1]
	add r0, r4, #0
	add r0, #0xac
	ldr r0, [r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	add r0, r4, #0
	mov r1, #0
	add r0, #0xb0
	str r1, [r0]
	ldr r2, [r4, #4]
	mov r1, #8
	add r0, r2, #0
	tst r0, r1
	bne _021EA1E4
	add r0, r1, #0
	add r0, #0xf8
	tst r0, r2
	bne _021EA1E4
	lsl r0, r1, #7
	tst r0, r2
	beq _021EA20E
_021EA1E4:
	mov r0, #0x18
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #0x99
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x10]
	mov r2, #0xa
	mov r3, #0
	bl AddPlttResObjFromNarc
	add r1, r4, #0
	add r1, #0xb0
	add r4, #0xb0
	str r0, [r1]
	ldr r0, [r4]
	bl SpriteTransfer_CreateExtPlttTransferTask
_021EA20E:
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021E9D10


	thumb_func_start ov96_021EA214
ov96_021EA214: ; 0x021EA214
	push {r4, r5, r6, r7, lr}
	sub sp, #0x8c
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl ov96_021E9D08
	str r0, [sp, #0x2c]
	add r0, r5, #0
	mov r1, #1
	bl ov96_021E9D08
	str r0, [sp, #0x30]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021E9D08
	str r0, [sp, #0x34]
	add r0, r5, #0
	mov r1, #3
	bl ov96_021E9D08
	mov r1, #0x14
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x15
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r3, [sp, #0x2c]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r3, [sp, #0x30]
	str r3, [sp, #0x18]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x68
	mov r2, #0x17
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #0
	add r0, sp, #0x68
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0xa0]
	str r4, [sp, #0x38]
	str r0, [sp, #0x64]
	mov r0, #1
	lsl r0, r0, #0xc
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	add r0, sp, #0x38
	strh r1, [r0, #0x20]
	add r0, sp, #0x38
	str r1, [sp, #0x5c]
	str r7, [sp, #0x60]
	bl Sprite_CreateAffine
	add r4, r0, #0
	bne _021EA2A4
	bl GF_AssertFail
_021EA2A4:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x8c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EA214


	thumb_func_start ov96_021EA2C4
ov96_021EA2C4: ; 0x021EA2C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x8c
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl ov96_021E9D08
	str r0, [sp, #0x2c]
	add r0, r5, #0
	mov r1, #1
	bl ov96_021E9D08
	str r0, [sp, #0x30]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021E9D08
	str r0, [sp, #0x34]
	add r0, r5, #0
	mov r1, #3
	bl ov96_021E9D08
	mov r1, #0x19
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x1a
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r3, [sp, #0x2c]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r3, [sp, #0x30]
	str r3, [sp, #0x18]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x68
	mov r2, #0x18
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #0
	add r0, sp, #0x68
	str r0, [sp, #0x3c]
	mov r0, #1
	lsl r0, r0, #0xc
	str r4, [sp, #0x38]
	str r7, [sp, #0x64]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	add r0, sp, #0x38
	strh r1, [r0, #0x20]
	mov r0, #2
	str r0, [sp, #0x60]
	add r0, sp, #0x38
	str r1, [sp, #0x5c]
	bl Sprite_CreateAffine
	add r4, r0, #0
	bne _021EA354
	bl GF_AssertFail
_021EA354:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x8c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EA2C4


	thumb_func_start ov96_021EA374
ov96_021EA374: ; 0x021EA374
	push {r4, r5, r6, r7, lr}
	sub sp, #0x8c
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl ov96_021E9D08
	str r0, [sp, #0x2c]
	add r0, r5, #0
	mov r1, #1
	bl ov96_021E9D08
	str r0, [sp, #0x30]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021E9D08
	str r0, [sp, #0x34]
	add r0, r5, #0
	mov r1, #3
	bl ov96_021E9D08
	mov r1, #0x1c
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x1d
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r3, [sp, #0x2c]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r3, [sp, #0x30]
	str r3, [sp, #0x18]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x68
	mov r2, #0x17
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #0
	add r0, sp, #0x68
	str r0, [sp, #0x3c]
	mov r0, #1
	lsl r0, r0, #0xc
	str r4, [sp, #0x38]
	str r7, [sp, #0x64]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	add r0, sp, #0x38
	strh r1, [r0, #0x20]
	mov r0, #1
	str r0, [sp, #0x60]
	add r0, sp, #0x38
	str r1, [sp, #0x5c]
	bl Sprite_CreateAffine
	add r4, r0, #0
	bne _021EA404
	bl GF_AssertFail
_021EA404:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x8c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EA374


	thumb_func_start ov96_021EA424
ov96_021EA424: ; 0x021EA424
	push {r4, r5, r6, r7, lr}
	sub sp, #0x8c
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl ov96_021E9D08
	str r0, [sp, #0x2c]
	add r0, r5, #0
	mov r1, #1
	bl ov96_021E9D08
	str r0, [sp, #0x30]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021E9D08
	str r0, [sp, #0x34]
	add r0, r5, #0
	mov r1, #3
	bl ov96_021E9D08
	mov r1, #0x1a
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x1b
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r3, [sp, #0x2c]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r3, [sp, #0x30]
	str r3, [sp, #0x18]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x68
	mov r2, #0x17
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #0
	add r0, sp, #0x68
	str r0, [sp, #0x3c]
	mov r0, #1
	lsl r0, r0, #0xc
	str r4, [sp, #0x38]
	str r7, [sp, #0x64]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	add r0, sp, #0x38
	strh r1, [r0, #0x20]
	mov r0, #1
	str r0, [sp, #0x60]
	add r0, sp, #0x38
	str r1, [sp, #0x5c]
	bl Sprite_CreateAffine
	add r4, r0, #0
	bne _021EA4B4
	bl GF_AssertFail
_021EA4B4:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x8c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EA424


	thumb_func_start ov96_021EA4D4
ov96_021EA4D4: ; 0x021EA4D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x8c
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl ov96_021E9D08
	str r0, [sp, #0x2c]
	add r0, r5, #0
	mov r1, #1
	bl ov96_021E9D08
	str r0, [sp, #0x30]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021E9D08
	str r0, [sp, #0x34]
	add r0, r5, #0
	mov r1, #3
	bl ov96_021E9D08
	mov r1, #0x1b
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x1c
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r3, [sp, #0x2c]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r3, [sp, #0x30]
	str r3, [sp, #0x18]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x68
	mov r2, #0x17
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #0
	add r0, sp, #0x68
	str r0, [sp, #0x3c]
	mov r0, #1
	lsl r0, r0, #0xc
	str r4, [sp, #0x38]
	str r7, [sp, #0x64]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	add r0, sp, #0x38
	strh r1, [r0, #0x20]
	mov r0, #1
	str r0, [sp, #0x60]
	add r0, sp, #0x38
	str r1, [sp, #0x5c]
	bl Sprite_CreateAffine
	add r4, r0, #0
	bne _021EA564
	bl GF_AssertFail
_021EA564:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x8c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EA4D4


	thumb_func_start ov96_021EA584
ov96_021EA584: ; 0x021EA584
	push {r4, r5, r6, r7, lr}
	sub sp, #0x8c
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl ov96_021E9D08
	str r0, [sp, #0x2c]
	add r0, r5, #0
	mov r1, #1
	bl ov96_021E9D08
	str r0, [sp, #0x30]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021E9D08
	str r0, [sp, #0x34]
	add r0, r5, #0
	mov r1, #3
	bl ov96_021E9D08
	mov r1, #0x1d
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x1e
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r3, [sp, #0x2c]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r3, [sp, #0x30]
	str r3, [sp, #0x18]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x68
	mov r2, #0x17
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #0
	add r0, sp, #0x68
	str r0, [sp, #0x3c]
	mov r0, #1
	lsl r0, r0, #0xc
	str r4, [sp, #0x38]
	str r7, [sp, #0x64]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	add r0, sp, #0x38
	strh r1, [r0, #0x20]
	mov r0, #1
	str r0, [sp, #0x60]
	add r0, sp, #0x38
	str r1, [sp, #0x5c]
	bl Sprite_CreateAffine
	add r4, r0, #0
	bne _021EA614
	bl GF_AssertFail
_021EA614:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x8c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EA584


	thumb_func_start ov96_021EA634
ov96_021EA634: ; 0x021EA634
	push {r4, r5, r6, r7, lr}
	sub sp, #0x8c
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl ov96_021E9D08
	str r0, [sp, #0x2c]
	add r0, r5, #0
	mov r1, #1
	bl ov96_021E9D08
	str r0, [sp, #0x30]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021E9D08
	str r0, [sp, #0x34]
	add r0, r5, #0
	mov r1, #3
	bl ov96_021E9D08
	mov r1, #0x1e
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x1f
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r3, [sp, #0x2c]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r3, [sp, #0x30]
	str r3, [sp, #0x18]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x68
	mov r2, #0x18
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #0
	add r0, sp, #0x68
	str r0, [sp, #0x3c]
	mov r0, #1
	lsl r0, r0, #0xc
	str r4, [sp, #0x38]
	str r7, [sp, #0x64]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	add r0, sp, #0x38
	strh r1, [r0, #0x20]
	mov r0, #2
	str r0, [sp, #0x60]
	add r0, sp, #0x38
	str r1, [sp, #0x5c]
	bl Sprite_CreateAffine
	add r4, r0, #0
	bne _021EA6C4
	bl GF_AssertFail
_021EA6C4:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x8c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EA634


	thumb_func_start ov96_021EA6E4
ov96_021EA6E4: ; 0x021EA6E4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x90
	add r4, r2, #0
	add r5, r0, #0
	add r7, r1, #0
	str r3, [sp, #0x2c]
	cmp r4, #1
	bne _021EA6F8
	mov r6, #0x17
	b _021EA6FA
_021EA6F8:
	mov r6, #0x18
_021EA6FA:
	add r0, r5, #0
	mov r1, #0
	bl ov96_021E9D08
	str r0, [sp, #0x30]
	add r0, r5, #0
	mov r1, #1
	bl ov96_021E9D08
	str r0, [sp, #0x34]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021E9D08
	str r0, [sp, #0x38]
	add r0, r5, #0
	mov r1, #3
	bl ov96_021E9D08
	mov r1, #0x1f
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x20
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	ldr r3, [sp, #0x2c]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r3, [sp, #0x30]
	str r3, [sp, #0x14]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x18]
	ldr r3, [sp, #0x38]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x6c
	add r2, r6, #0
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #0
	add r0, sp, #0x6c
	str r0, [sp, #0x40]
	ldr r0, [sp, #0xa8]
	str r7, [sp, #0x3c]
	str r0, [sp, #0x68]
	mov r0, #1
	lsl r0, r0, #0xc
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	str r1, [sp, #0x4c]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	str r0, [sp, #0x58]
	add r0, sp, #0x3c
	strh r1, [r0, #0x20]
	mov r0, #1
	str r0, [sp, #0x60]
	add r0, sp, #0x3c
	str r4, [sp, #0x64]
	bl Sprite_CreateAffine
	add r4, r0, #0
	bne _021EA784
	bl GF_AssertFail
_021EA784:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x90
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021EA6E4


	thumb_func_start ov96_021EA7A4
ov96_021EA7A4: ; 0x021EA7A4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x8c
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl ov96_021E9D08
	str r0, [sp, #0x2c]
	add r0, r5, #0
	mov r1, #1
	bl ov96_021E9D08
	str r0, [sp, #0x30]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021E9D08
	str r0, [sp, #0x34]
	add r0, r5, #0
	mov r1, #3
	bl ov96_021E9D08
	mov r1, #0x20
	add r2, r1, #0
	str r1, [sp]
	sub r2, #0x21
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r3, [sp, #0x2c]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r3, [sp, #0x30]
	str r3, [sp, #0x18]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	str r2, [sp, #0x28]
	add r0, sp, #0x68
	mov r2, #0x17
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	mov r1, #0
	add r0, sp, #0x68
	str r0, [sp, #0x3c]
	mov r0, #1
	lsl r0, r0, #0xc
	str r4, [sp, #0x38]
	str r7, [sp, #0x64]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	add r0, sp, #0x38
	strh r1, [r0, #0x20]
	mov r0, #2
	str r0, [sp, #0x5c]
	mov r0, #1
	str r0, [sp, #0x60]
	add r0, sp, #0x38
	bl Sprite_CreateAffine
	add r4, r0, #0
	bne _021EA836
	bl GF_AssertFail
_021EA836:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x8c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EA7A4


	thumb_func_start ov96_021EA854
ov96_021EA854: ; 0x021EA854
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	mov r1, #0xd3
	lsl r1, r1, #2
	add r5, r0, #0
	add r7, r2, #0
	str r3, [sp]
	bl Heap_Alloc
	mov r2, #0xd3
	add r4, r0, #0
	mov r1, #0
	lsl r2, r2, #2
	bl MI_CpuFill8
	str r5, [r4]
	ldr r0, [sp]
	str r6, [r4, #4]
	str r0, [r4, #0x18]
	ldr r0, [sp, #0x18]
	str r0, [r4, #0x10]
	add r0, r5, #0
	str r7, [r4, #8]
	bl ov96_021E8A30
	ldr r2, [sp, #0x18]
	add r1, r6, #0
	str r0, [r4, #0x14]
	bl ov96_021E8A44
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021EA854

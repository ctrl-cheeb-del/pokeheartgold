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

	thumb_func_start ov96_021FA34C
ov96_021FA34C: ; 0x021FA34C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r4, r2, #0
	add r5, r0, #0
	ldrb r0, [r4, #8]
	add r6, r3, #0
	str r1, [sp, #4]
	cmp r0, #1
	beq _021FA38A
	ldr r0, [r4, #0x28]
	cmp r0, #2
	beq _021FA38A
	ldrb r0, [r4, #9]
	cmp r0, #0
	bne _021FA38A
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x50]
	bl _fls
	bhs _021FA38A
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x54]
	bl _fadd
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x50]
	bl _fgr
	bls _021FA38A
	ldr r0, [r4, #0x50]
	str r0, [r4, #0xc]
_021FA38A:
	cmp r6, #0
	beq _021FA422
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _021FA422
	ldrb r2, [r4, #0x18]
	add r3, r4, #0
	ldr r1, [r6, #4]
	add r0, r5, #0
	add r3, #0x24
	bl ov96_021FA7BC
	mov r0, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FA3FA
	ldr r6, [sp, #8]
_021FA3B2:
	add r0, r4, #0
	add r1, r6, #0
	bl ov96_021FA340
	add r7, r0, #0
	bl ov96_021FBEA0
	cmp r0, #0
	beq _021FA3F4
	add r0, r7, #0
	add r1, sp, #0x1c
	bl ov96_021FBF5C
	ldr r0, [r4, #0x24]
	bl ov96_021EAF8C
	mov r1, #0x11
	ldr r2, [r4, #0x3c]
	lsl r1, r1, #4
	add r1, r2, r1
	sub r0, r1, r0
	add r1, sp, #0x1c
	bl ov96_021FAB04
	cmp r0, #0
	beq _021FA3F4
	mov r0, #1
	str r0, [sp, #8]
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_021FBCB8
	b _021FA3FA
_021FA3F4:
	add r6, r6, #1
	cmp r6, #4
	blt _021FA3B2
_021FA3FA:
	ldr r0, [r4, #0x44]
	bl ov96_021EB5B8
	mov r1, #1
	add r6, r0, #0
	bl Sprite_SetDrawFlag
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _021FA418
	add r0, r6, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	b _021FA452
_021FA418:
	add r0, r6, #0
	mov r1, #1
	bl Sprite_SetAnimCtrlSeq
	b _021FA452
_021FA422:
	cmp r6, #0
	beq _021FA452
	ldr r0, [r4, #0x28]
	cmp r0, #1
	bne _021FA452
	ldr r0, [r4, #0x2c]
	cmp r0, #3
	bne _021FA452
	add r0, r4, #0
	add r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FA452
	add r0, r4, #0
	mov r1, #1
	add r0, #0x60
	strh r1, [r0]
	add r0, r4, #0
	add r0, #0x62
	ldrh r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x62
	strh r1, [r0]
_021FA452:
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	bl _fadd
	add r6, r0, #0
	bl _ffix
	add r7, r0, #0
	bl _fflt
	add r1, r0, #0
	add r0, r6, #0
	bl _fsub
	str r0, [r4, #0x10]
	ldrh r0, [r4]
	add r0, r0, r7
	strh r0, [r4]
	ldrh r1, [r4]
	ldrb r2, [r4, #0x18]
	ldr r0, [sp, #4]
	bl ov96_021FB6B4
	ldr r0, [sp, #4]
	add r1, r4, #0
	bl ov96_021FB6C8
	ldrh r0, [r4, #4]
	sub r0, r0, r7
	strh r0, [r4, #4]
	mov r0, #2
	ldrh r1, [r4, #4]
	lsl r0, r0, #8
	add r0, r1, r0
	cmp r0, #0
	bgt _021FA49C
	strh r0, [r4, #4]
_021FA49C:
	ldrh r1, [r4, #4]
	mov r0, #0x11
	lsl r0, r0, #4
	add r1, r1, r0
	strh r1, [r4, #6]
	ldrh r1, [r4, #6]
	add r0, #0xf0
	add r0, r1, r0
	cmp r0, #0
	bgt _021FA4B2
	strh r0, [r4, #6]
_021FA4B2:
	mov r6, #0
_021FA4B4:
	add r0, r4, #0
	add r1, r6, #0
	bl ov96_021FA340
	add r1, r7, #0
	bl ov96_021FBEFC
	add r6, r6, #1
	cmp r6, #4
	blt _021FA4B4
	ldr r0, [sp, #4]
	ldrb r1, [r4, #0x18]
	add r0, #0xdc
	ldr r0, [r0]
	add r2, r7, #0
	bl ov96_021FC6EC
	add r1, r4, #0
	add r2, r4, #0
	ldrb r0, [r4, #0x18]
	add r1, #0x24
	add r2, #0xc
	bl ov96_021FA83C
	ldrb r0, [r4, #8]
	cmp r0, #1
	bne _021FA54C
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _021FA4F6
	mov r0, #3
	str r0, [r4, #0x28]
	b _021FA53E
_021FA4F6:
	cmp r0, #3
	beq _021FA4FE
	cmp r0, #1
	bne _021FA53E
_021FA4FE:
	ldrh r1, [r4]
	mov r0, #0x42
	lsl r0, r0, #6
	ldr r2, [r4, #0x3c]
	cmp r1, r0
	blo _021FA51A
	cmp r2, #0x78
	bne _021FA53E
	mov r0, #4
	str r0, [r4, #0x28]
	mov r0, #0
	str r0, [r4, #0xc]
	str r0, [r4, #0x10]
	b _021FA53E
_021FA51A:
	sub r0, #0x80
	cmp r1, r0
	blo _021FA53E
	mov r0, #0xfe
	lsl r0, r0, #0x16
	str r0, [r4, #0xc]
	mov r0, #0
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x24]
	mov r1, #1
	bl ov96_021EAC0C
	ldr r0, [r4, #0x4c]
	bl ov96_021EB5B8
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
_021FA53E:
	ldr r0, [sp, #4]
	add r1, r4, #0
	ldr r0, [r0, #4]
	bl ov96_021FAB24
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
_021FA54C:
	ldr r1, [r4, #0x28]
	mov r0, #1
	cmp r1, #1
	bne _021FA556
	mov r0, #0
_021FA556:
	add r1, r4, #0
	add r1, #0x60
	ldrh r1, [r1]
	cmp r1, #1
	bne _021FA56C
	add r1, r4, #0
	add r1, #0x62
	ldrh r1, [r1]
	cmp r1, #1
	bne _021FA56C
	mov r0, #1
_021FA56C:
	cmp r0, #0
	bne _021FA572
	b _021FA67C
_021FA572:
	mov r6, #0
_021FA574:
	add r0, r4, #0
	add r1, r6, #0
	bl ov96_021FA340
	str r0, [sp, #0xc]
	bl ov96_021FBEA0
	cmp r0, #0
	beq _021FA674
	ldr r7, [r4, #0x24]
	ldr r0, [sp, #0xc]
	add r1, sp, #0x14
	bl ov96_021FBF5C
	add r0, r7, #0
	bl ov96_021EAF90
	str r0, [sp, #0x10]
	add r0, r7, #0
	bl ov96_021EAF8C
	add r1, r0, #0
	mov r0, #0x11
	lsl r1, r1, #0x18
	ldr r2, [r4, #0x3c]
	lsl r0, r0, #4
	add r2, r2, r0
	ldr r0, [sp, #0x10]
	lsr r1, r1, #0x18
	sub r0, r2, r0
	add r2, sp, #0x14
	bl ov96_021FAAE0
	cmp r0, #0
	beq _021FA674
	ldr r0, [sp, #0xc]
	bl ov96_021FBEA4
	ldrb r2, [r4, #0x18]
	ldr r1, _021FA6C0 ; =ov96_0221DC2C
	ldr r0, _021FA6C4 ; =0x000008A5
	ldrb r1, [r1, r2]
	bl sub_0200606C
	ldrb r2, [r4, #0x18]
	ldr r0, _021FA6C0 ; =ov96_0221DC2C
	ldr r1, _021FA6C8 ; =ov96_0221DC28
	ldrb r0, [r0, r2]
	ldrsb r1, [r1, r2]
	bl sub_020061D0
	add r0, r4, #0
	add r0, #0x60
	ldrh r0, [r0]
	cmp r0, #1
	bne _021FA61E
	add r0, r4, #0
	add r0, #0x62
	ldrh r0, [r0]
	cmp r0, #1
	bne _021FA61E
	add r0, r5, #0
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldrb r2, [r4, #0x18]
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r3, #2
	bl ov96_021E8228
	add r1, r4, #0
	add r1, #0x30
	mov r0, #3
	strb r0, [r1]
	mov r0, #1
	str r0, [r4, #0x2c]
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_021FBCB8
	b _021FA666
_021FA61E:
	mov r0, #0x3f
	lsl r0, r0, #0x18
	str r0, [r4, #0xc]
	mov r0, #0
	strb r0, [r4, #9]
	mov r0, #2
	add r1, r4, #0
	str r0, [r4, #0x28]
	add r1, #0x31
	mov r0, #0
	strb r0, [r1]
	add r1, r4, #0
	add r1, #0x32
	mov r0, #1
	strb r0, [r1]
	mov r0, #4
	str r0, [r4, #0x2c]
	ldr r0, [r4, #0x4c]
	bl ov96_021EB5B8
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r5, #0
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldrb r2, [r4, #0x18]
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r3, #1
	bl ov96_021E8228
_021FA666:
	add r1, r4, #0
	add r1, #0x60
	mov r0, #0
	strh r0, [r1]
	add r1, r4, #0
	add r1, #0x62
	strh r0, [r1]
_021FA674:
	add r6, r6, #1
	cmp r6, #4
	bge _021FA67C
	b _021FA574
_021FA67C:
	ldrb r0, [r4, #8]
	cmp r0, #1
	beq _021FA6B0
	ldrh r1, [r4]
	mov r0, #1
	lsl r0, r0, #0xc
	cmp r1, r0
	blo _021FA6B0
	mov r0, #1
	strb r0, [r4, #8]
	mov r1, #0x23
	ldr r0, [sp, #4]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	ldr r1, _021FA6C0 ; =ov96_0221DC2C
	strh r0, [r4, #2]
	ldrb r2, [r4, #0x18]
	ldr r0, _021FA6CC ; =0x000008AB
	ldrb r1, [r1, r2]
	bl sub_0200606C
	mov r1, #0xf1
	ldr r0, [sp, #4]
	mov r2, #0x1e
	lsl r1, r1, #2
	strh r2, [r0, r1]
_021FA6B0:
	ldr r0, [sp, #4]
	add r1, r4, #0
	ldr r0, [r0, #4]
	bl ov96_021FAB24
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_021FA6C0: .word ov96_0221DC2C
_021FA6C4: .word 0x000008A5
_021FA6C8: .word ov96_0221DC28
_021FA6CC: .word 0x000008AB
	thumb_func_end ov96_021FA34C


	thumb_func_start ov96_021FA6D0
ov96_021FA6D0: ; 0x021FA6D0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #0xc]
	sub r0, r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r6, r1, #0
	str r0, [sp, #0x14]
	bl System_GetTouchNew
	cmp r0, #0
	beq _021FA71C
	ldr r0, [sp, #4]
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl ov96_021E8228
	ldr r2, _021FA7A8 ; =gSystem + 0x40
	add r0, r6, #0
	ldrh r1, [r2, #0x20]
	ldrh r2, [r2, #0x22]
	bl ov96_021FB784
	str r0, [sp, #8]
	cmp r0, #3
	bge _021FA71C
	str r0, [sp, #0x10]
_021FA71C:
	mov r7, #0
	add r5, r6, #0
	add r4, r7, #0
	add r5, #0xe0
_021FA724:
	ldrb r0, [r5, #8]
	mov r3, #0
	cmp r0, #0
	bne _021FA736
	ldr r0, [sp, #8]
	cmp r0, r4
	bne _021FA73C
	add r3, sp, #0x10
	b _021FA73C
_021FA736:
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
_021FA73C:
	ldr r0, [sp, #4]
	add r1, r6, #0
	add r2, r5, #0
	bl ov96_021FA34C
	add r4, r4, #1
	add r5, #0x6c
	cmp r4, #3
	blt _021FA724
	add r0, r6, #0
	add r0, #0xe6
	ldrh r0, [r0]
	ldr r1, _021FA7AC ; =0x01FF0000
	ldr r2, _021FA7B0 ; =0x04000010
	lsl r0, r0, #0x10
	and r0, r1
	str r0, [r2]
	ldr r0, _021FA7B4 ; =0x00000152
	ldrh r3, [r6, r0]
	lsl r3, r3, #0x10
	and r3, r1
	str r3, [r2, #4]
	add r3, r0, #0
	add r3, #0x6c
	ldrh r3, [r6, r3]
	lsl r3, r3, #0x10
	and r3, r1
	str r3, [r2, #8]
	add r2, r6, #0
	add r2, #0xe4
	ldrh r2, [r2]
	lsl r2, r2, #0x10
	add r3, r2, #0
	ldr r2, _021FA7B8 ; =0x04001010
	and r3, r1
	str r3, [r2]
	sub r3, r0, #2
	ldrh r3, [r6, r3]
	add r0, #0x6a
	lsl r3, r3, #0x10
	and r3, r1
	str r3, [r2, #4]
	ldrh r0, [r6, r0]
	lsl r0, r0, #0x10
	and r0, r1
	str r0, [r2, #8]
	cmp r7, #3
	blo _021FA7A0
	mov r0, #1
	str r0, [sp, #0xc]
_021FA7A0:
	ldr r0, [sp, #0xc]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FA7A8: .word gSystem + 0x40
_021FA7AC: .word 0x01FF0000
_021FA7B0: .word 0x04000010
_021FA7B4: .word 0x00000152
_021FA7B8: .word 0x04001010
	thumb_func_end ov96_021FA6D0


	thumb_func_start ov96_021FA7BC
ov96_021FA7BC: ; 0x021FA7BC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r3, #0
	add r7, r0, #0
	ldr r0, [r4, #4]
	add r5, r2, #0
	cmp r0, #0
	bne _021FA82A
	add r0, r4, #0
	add r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FA7FC
	ldr r1, _021FA82C ; =ov96_0221DC2C
	ldr r0, _021FA830 ; =0x0000060A
	add r6, r1, r5
	ldrb r1, [r1, r5]
	bl sub_0200606C
	add r0, r7, #0
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	lsl r1, r1, #0x18
	str r0, [sp]
	add r0, r7, #0
	lsr r1, r1, #0x18
	add r2, r5, #0
	mov r3, #2
	bl ov96_021E8228
	b _021FA808
_021FA7FC:
	ldr r1, _021FA82C ; =ov96_0221DC2C
	ldr r0, _021FA834 ; =0x000008AA
	add r6, r1, r5
	ldrb r1, [r1, r5]
	bl sub_0200606C
_021FA808:
	ldr r1, _021FA838 ; =ov96_0221DC28
	ldrb r0, [r6]
	ldrsb r1, [r1, r5]
	bl sub_020061D0
	mov r1, #1
	str r1, [r4, #4]
	mov r0, #0
	strb r0, [r4, #0xc]
	str r1, [r4, #8]
	add r1, r4, #0
	ldr r0, [r4]
	add r4, #0x14
	add r1, #0x10
	add r2, r4, #0
	bl ov96_021EAE9C
_021FA82A:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FA82C: .word ov96_0221DC2C
_021FA830: .word 0x0000060A
_021FA834: .word 0x000008AA
_021FA838: .word ov96_0221DC28
	thumb_func_end ov96_021FA7BC


	thumb_func_start ov96_021FA83C
ov96_021FA83C: ; 0x021FA83C
	push {r3, r4, r5, r6, lr}
	sub sp, #0x24
	add r4, r1, #0
	add r5, r0, #0
	ldr r0, [r4, #4]
	cmp r0, #3
	bhi _021FA8F2
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021FA856: ; jump table
	.short _021FAA64 - _021FA856 - 2 ; case 0
	.short _021FA85E - _021FA856 - 2 ; case 1
	.short _021FA9AE - _021FA856 - 2 ; case 2
	.short _021FAA1E - _021FA856 - 2 ; case 3
_021FA85E:
	ldrb r0, [r4, #0xc]
	add r0, r0, #1
	strb r0, [r4, #0xc]
	ldr r0, [r4, #8]
	cmp r0, #1
	beq _021FA874
	cmp r0, #2
	beq _021FA8D8
	cmp r0, #3
	beq _021FA912
	b _021FA9A8
_021FA874:
	add r0, r4, #0
	add r0, #0x34
	ldrb r0, [r0]
	ldr r3, _021FAAC8 ; =ov96_0221C55C
	lsl r1, r0, #3
	add r5, r0, r1
	ldrb r1, [r4, #0xc]
	sub r2, r1, #1
	add r1, r3, r5
	ldrsb r1, [r2, r1]
	ldr r2, [r4, #0x14]
	sub r5, r2, r1
	cmp r0, #0
	bne _021FA8A4
	add r0, r4, #0
	mov r1, #0
	bl ov96_021FB8FC
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	add r2, r5, #0
	bl ov96_021EAE4C
	b _021FA8B6
_021FA8A4:
	add r0, r4, #0
	bl ov96_021FB8B4
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	add r2, r5, #0
	mov r3, #0
	bl ov96_021EAD88
_021FA8B6:
	ldrb r1, [r4, #0xc]
	ldrh r0, [r4, #0x38]
	cmp r1, r0
	blt _021FA8F2
	mov r0, #2
	str r0, [r4, #8]
	mov r1, #0
	add r0, r4, #0
	strb r1, [r4, #0xc]
	add r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FA8F2
	ldr r0, [r4]
	bl ov96_021EAB94
	b _021FAA6A
_021FA8D8:
	ldrb r1, [r4, #0xc]
	ldrh r0, [r4, #0x3a]
	cmp r1, r0
	blt _021FA8F2
	mov r0, #3
	str r0, [r4, #8]
	mov r0, #0
	strb r0, [r4, #0xc]
	add r0, r4, #0
	add r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FA8F4
_021FA8F2:
	b _021FAA6A
_021FA8F4:
	ldr r0, [r4]
	mov r1, #1
	bl ov96_021EAB94
	ldr r6, _021FAACC ; =ov96_0221DC2C
	ldr r0, _021FAAD0 ; =0x000008AA
	ldrb r1, [r6, r5]
	bl sub_0200606C
	ldr r1, _021FAAD4 ; =ov96_0221DC28
	ldrb r0, [r6, r5]
	ldrsb r1, [r1, r5]
	bl sub_020061D0
	b _021FAA6A
_021FA912:
	add r0, r4, #0
	add r0, #0x34
	ldrb r0, [r0]
	ldr r3, _021FAAD8 ; =ov96_0221C589
	lsl r1, r0, #3
	add r6, r0, r1
	ldrb r1, [r4, #0xc]
	sub r2, r1, #1
	add r1, r3, r6
	ldrsb r1, [r2, r1]
	ldr r2, [r4, #0x14]
	sub r6, r2, r1
	cmp r0, #0
	bne _021FA942
	add r0, r4, #0
	mov r1, #1
	bl ov96_021FB8FC
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	add r2, r6, #0
	bl ov96_021EAE4C
	b _021FA954
_021FA942:
	add r0, r4, #0
	bl ov96_021FB8B4
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	add r2, r6, #0
	mov r3, #0
	bl ov96_021EAD88
_021FA954:
	ldrh r0, [r4, #0x38]
	ldrb r1, [r4, #0xc]
	cmp r1, r0
	blt _021FA99C
	mov r3, #0
	str r3, [r4, #4]
	str r3, [r4, #8]
	strb r3, [r4, #0xc]
	ldr r0, [r4]
	ldr r1, [r4, #0x10]
	ldr r2, [r4, #0x14]
	bl ov96_021EAD88
	add r0, r4, #0
	add r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FA98C
	ldr r6, _021FAACC ; =ov96_0221DC2C
	ldr r0, _021FAADC ; =0x000008A8
	ldrb r1, [r6, r5]
	bl sub_0200606C
	ldr r1, _021FAAD4 ; =ov96_0221DC28
	ldrb r0, [r6, r5]
	ldrsb r1, [r1, r5]
	bl sub_020061D0
_021FA98C:
	add r0, r4, #0
	mov r1, #0
	bl ov96_021FB8B4
	mov r0, #0
	strh r0, [r4, #0x3c]
	strh r0, [r4, #0x3e]
	b _021FAA6A
_021FA99C:
	sub r0, r0, #5
	cmp r1, r0
	bge _021FAA6A
	mov r0, #0
	strh r0, [r4, #0x3c]
	b _021FAA6A
_021FA9A8:
	bl GF_AssertFail
	b _021FAA6A
_021FA9AE:
	ldrb r0, [r4, #0xc]
	add r0, r0, #1
	strb r0, [r4, #0xc]
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	bne _021FA9F4
	ldrb r0, [r4, #0xe]
	cmp r0, #4
	bhi _021FA9EC
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021FA9CC: ; jump table
	.short _021FA9EC - _021FA9CC - 2 ; case 0
	.short _021FA9D6 - _021FA9CC - 2 ; case 1
	.short _021FA9E2 - _021FA9CC - 2 ; case 2
	.short _021FA9DC - _021FA9CC - 2 ; case 3
	.short _021FA9E8 - _021FA9CC - 2 ; case 4
_021FA9D6:
	mov r0, #3
	strb r0, [r4, #0xe]
	b _021FA9EC
_021FA9DC:
	mov r0, #2
	strb r0, [r4, #0xe]
	b _021FA9EC
_021FA9E2:
	mov r0, #4
	strb r0, [r4, #0xe]
	b _021FA9EC
_021FA9E8:
	mov r0, #1
	strb r0, [r4, #0xe]
_021FA9EC:
	ldrb r1, [r4, #0xe]
	ldr r0, [r4]
	bl ov96_021EAC0C
_021FA9F4:
	ldrb r0, [r4, #0xd]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xc]
	cmp r0, #0x1e
	bls _021FAA6A
	mov r0, #0
	strb r0, [r4, #0xc]
	str r0, [r4, #4]
	str r0, [r4, #8]
	ldr r0, [r4]
	mov r1, #1
	bl ov96_021EAC0C
	b _021FAA6A
_021FAA1E:
	ldr r1, [r4, #0x18]
	mov r0, #0
	cmp r1, #0x78
	bge _021FAA36
	add r0, r1, #1
	mov r2, #1
	cmp r0, #0x78
	ble _021FAA32
	add r2, r1, #0
	sub r2, #0x78
_021FAA32:
	mov r0, #1
	b _021FAA46
_021FAA36:
	ble _021FAA46
	sub r2, r0, #1
	sub r0, r1, #1
	cmp r0, #0x78
	bge _021FAA44
	mov r0, #0x78
	sub r2, r0, r1
_021FAA44:
	mov r0, #1
_021FAA46:
	cmp r0, #0
	beq _021FAA6A
	ldr r0, [r4, #0x18]
	mov r3, #1
	add r0, r0, r2
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x1c]
	mov r1, #0
	add r0, r0, r2
	str r0, [r4, #0x1c]
	str r3, [sp]
	ldr r0, [r4]
	bl ov96_021EAED4
	b _021FAA6A
_021FAA64:
	mov r0, #0
	strh r0, [r4, #0x3c]
	strh r0, [r4, #0x3e]
_021FAA6A:
	ldr r0, [r4, #0x20]
	bl ov96_021EB5B8
	add r5, r0, #0
	bl Sprite_GetMatrixPtr
	add r6, r0, #0
	add r3, sp, #0x18
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r4, #0x1c]
	lsl r0, r0, #0xc
	str r0, [sp, #0x1c]
	add r0, r5, #0
	bl Sprite_SetMatrix
	ldr r0, [r4]
	add r1, sp, #8
	add r2, sp, #4
	bl ov96_021EAE9C
	ldr r0, [r4, #0x28]
	bl ov96_021EB5B8
	add r4, r0, #0
	bl Sprite_GetMatrixPtr
	add r5, r0, #0
	add r3, sp, #0xc
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [sp, #4]
	lsl r0, r0, #0xc
	str r0, [sp, #0x10]
	add r0, r4, #0
	bl Sprite_SetMatrix
	add sp, #0x24
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021FAAC8: .word ov96_0221C55C
_021FAACC: .word ov96_0221DC2C
_021FAAD0: .word 0x000008AA
_021FAAD4: .word ov96_0221DC28
_021FAAD8: .word ov96_0221C589
_021FAADC: .word 0x000008A8
	thumb_func_end ov96_021FA83C


	thumb_func_start ov96_021FAAE0
ov96_021FAAE0: ; 0x021FAAE0
	push {r4, r5}
	add r4, r0, r1
	mov r3, #2
	sub r1, r0, r1
	mov r0, #6
	ldrsh r3, [r2, r3]
	ldrsh r0, [r2, r0]
	mov r5, #0
	add r0, r3, r0
	cmp r1, r0
	bgt _021FAAFC
	cmp r3, r4
	bgt _021FAAFC
	mov r5, #1
_021FAAFC:
	add r0, r5, #0
	pop {r4, r5}
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021FAAE0


	thumb_func_start ov96_021FAB04
ov96_021FAB04: ; 0x021FAB04
	push {r3, r4}
	mov r2, #2
	ldrsh r3, [r1, r2]
	mov r2, #6
	ldrsh r1, [r1, r2]
	mov r4, #0
	add r1, r3, r1
	cmp r0, r1
	blt _021FAB1E
	sub r0, #0x18
	cmp r0, r1
	bge _021FAB1E
	mov r4, #1
_021FAB1E:
	add r0, r4, #0
	pop {r3, r4}
	bx lr
	thumb_func_end ov96_021FAB04


	thumb_func_start ov96_021FAB24
ov96_021FAB24: ; 0x021FAB24
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	ldr r1, [r4, #0x1c]
	add r5, r0, #0
	cmp r1, #0
	beq _021FAB42
	cmp r1, #1
	bne _021FAB38
	b _021FAC6C
_021FAB38:
	cmp r1, #2
	bne _021FAB3E
	b _021FADBE
_021FAB3E:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_021FAB42:
	ldrh r1, [r4]
	cmp r1, #0x70
	bhs _021FAB4A
	b _021FAF10
_021FAB4A:
	mov r2, #2
	lsl r1, r2, #9
	add r1, r2, r1
	lsl r1, r1, #0x10
	lsr r7, r1, #0x10
	mov r1, #0x32
	str r1, [sp]
	mov r1, #1
	str r1, [sp, #4]
	str r2, [sp, #8]
	mov r1, #0x10
	str r1, [sp, #0xc]
	ldrh r1, [r4, #0x14]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, r3, #2
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x14]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, r3, #3
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x14]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, #9
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r2, r7, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r2, #2
	str r2, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x16]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, r3, #2
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x16]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, r3, #3
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	mov r0, #0x32
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrh r1, [r4, #0x16]
	ldrb r6, [r4, #0x18]
	mov r3, #0xa
	lsl r1, r1, #0x18
	mul r3, r6
	add r3, #9
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r2, r7, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #1
	str r0, [r4, #0x1c]
	mov r0, #0xff
	add sp, #0x10
	strb r0, [r4, #0x1a]
	pop {r3, r4, r5, r6, r7, pc}
_021FAC6C:
	ldrh r1, [r4]
	ldr r0, _021FAF14 ; =0x00000E48
	sub r1, #0x10
	cmp r1, r0
	bge _021FAC78
	b _021FAF10
_021FAC78:
	asr r0, r1, #2
	lsr r0, r0, #0x1d
	add r0, r1, r0
	asr r0, r0, #3
	lsr r1, r0, #0x1f
	lsl r0, r0, #0x1a
	sub r0, r0, r1
	mov r2, #0x1a
	ror r0, r2
	add r1, r1, r0
	mov r0, #0x40
	sub r0, r0, r1
	lsr r1, r0, #0x1f
	lsl r0, r0, #0x1a
	sub r0, r0, r1
	ror r0, r2
	add r0, r1, r0
	sub r0, r0, #2
	bpl _021FACA0
	add r0, #0x40
_021FACA0:
	strb r0, [r4, #0x1b]
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x60
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #2
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x61
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #3
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x62
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, #9
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x60
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #2
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x61
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #3
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #0x62
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, #9
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #2
	add sp, #0x10
	str r0, [r4, #0x1c]
	pop {r3, r4, r5, r6, r7, pc}
_021FADBE:
	ldrh r1, [r4]
	ldr r0, _021FAF18 ; =0x00001048
	sub r1, #0x10
	cmp r1, r0
	bge _021FADCA
	b _021FAF10
_021FADCA:
	asr r0, r1, #2
	lsr r0, r0, #0x1d
	add r0, r1, r0
	asr r0, r0, #3
	lsr r1, r0, #0x1f
	lsl r0, r0, #0x1a
	sub r0, r0, r1
	mov r2, #0x1a
	ror r0, r2
	add r1, r1, r0
	mov r0, #0x40
	sub r0, r0, r1
	lsr r1, r0, #0x1f
	lsl r0, r0, #0x1a
	sub r0, r0, r1
	ror r0, r2
	add r0, r1, r0
	sub r0, r0, #2
	bpl _021FADF2
	add r0, #0x40
_021FADF2:
	mov r2, #2
	strb r0, [r4, #0x1b]
	lsl r0, r2, #9
	add r0, r2, r0
	lsl r0, r0, #0x10
	lsr r7, r0, #0x10
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r2, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #2
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #3
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #3
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	add r2, r7, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	mul r3, r6
	add r3, #9
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r2, #2
	mov r3, #0xa
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r2, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #2
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	mov r2, #3
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, r3, #3
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrb r0, [r4, #0x1b]
	mov r3, #0xa
	add r2, r7, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldrb r6, [r4, #0x18]
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	mul r3, r6
	add r3, #9
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldrh r1, [r4, #0x14]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	ldrh r1, [r4, #0x16]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #3
	str r0, [r4, #0x1c]
_021FAF10:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FAF14: .word 0x00000E48
_021FAF18: .word 0x00001048
	thumb_func_end ov96_021FAB24


	thumb_func_start ov96_021FAF1C
ov96_021FAF1C: ; 0x021FAF1C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r5, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r4, r0, #0
	bl ov96_021E8A20
	mov r7, #0x23
	add r3, r0, #0
	mov r1, #0
	add r2, r5, #0
	mov r0, #1
	lsl r7, r7, #4
_021FAF40:
	add r6, r2, #0
	add r6, #0xe0
	ldrh r6, [r6]
	strh r6, [r3]
	add r6, r2, #0
	add r6, #0xe8
	ldrb r6, [r6]
	cmp r6, #0
	beq _021FAF5E
	ldrh r6, [r3, #0x10]
	cmp r6, #0
	bne _021FAF5E
	strh r0, [r3, #0x10]
	ldr r6, [r5, r7]
	strh r6, [r3, #0xa]
_021FAF5E:
	add r1, r1, #1
	add r2, #0x6c
	add r3, r3, #2
	cmp r1, #3
	blt _021FAF40
	ldr r0, [sp]
	bl ov96_021E5F24
	cmp r0, #0
	bne _021FAFF0
	add r0, r4, #0
	add r0, #0x28
	mov r7, #0
	bl ov96_021E8A20
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #0x50
	bl ov96_021E8A20
	add r5, r0, #0
	add r0, r4, #0
	bl ov96_021E8A20
	mov r2, #0x12
_021FAF90:
	ldrh r1, [r0]
	add r0, r0, #2
	strh r1, [r5]
	add r5, r5, #2
	sub r2, r2, #1
	bne _021FAF90
	mov r0, #0
	ldr r5, [sp, #8]
	str r0, [sp, #4]
	add r4, #0x50
_021FAFA4:
	add r0, r4, #0
	bl ov96_021E8A20
	add r6, r0, #0
	mov r1, #0
	add r2, r6, #0
	add r3, r5, #0
_021FAFB2:
	ldrh r0, [r2]
	add r1, r1, #1
	add r2, r2, #2
	strh r0, [r3, #4]
	add r3, r3, #2
	cmp r1, #3
	blt _021FAFB2
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _021FAFCC
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
_021FAFCC:
	ldr r0, [sp, #4]
	add r4, #0x28
	add r0, r0, #1
	add r5, r5, #6
	str r0, [sp, #4]
	cmp r0, #4
	blt _021FAFA4
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantCount
	cmp r7, r0
	bne _021FAFEA
	ldr r0, [sp, #8]
	mov r1, #1
	str r1, [r0]
_021FAFEA:
	ldr r0, [sp]
	bl ov96_021FB400
_021FAFF0:
	ldr r0, [sp]
	bl ov96_021FB0F4
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021FAF1C


	thumb_func_start ov96_021FAFFC
ov96_021FAFFC: ; 0x021FAFFC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa0
	str r0, [sp]
	add r7, r1, #0
	mov r0, #0
	add r1, sp, #0x10
	str r1, [sp, #8]
	str r0, [sp, #4]
	add r1, sp, #4
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
_021FB012:
	add r2, r0, #1
	mov r1, #0xc
	add r3, sp, #4
	mul r1, r2
	add r2, r3, r1
	lsr r1, r0, #0x1f
	add r1, r0, r1
	lsl r1, r1, #0x17
	lsr r1, r1, #0x18
	add r1, r7, r1
	ldrb r6, [r1, #0x1c]
	lsr r5, r0, #0x1f
	lsl r4, r0, #0x1f
	sub r4, r4, r5
	mov r1, #0x1f
	ror r4, r1
	add r1, r5, r4
	lsl r1, r1, #0x18
	lsr r1, r1, #0x16
	add r4, r6, #0
	asr r4, r1
	mov r1, #0xf
	and r1, r4
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	strh r1, [r2, #8]
	mov r1, #0
	strh r0, [r2, #0xa]
	str r1, [r2, #4]
	cmp r0, #0
	ble _021FB088
	ldrh r4, [r2, #8]
	ldrh r5, [r2, #0xa]
_021FB054:
	ldr r3, [r3, #4]
	ldrh r6, [r3, #8]
	cmp r6, r4
	bls _021FB06A
	ldr r4, [r3]
	str r2, [r4, #4]
	ldr r4, [r3]
	str r4, [r2]
	str r3, [r2, #4]
	str r2, [r3]
	b _021FB088
_021FB06A:
	cmp r6, r4
	bne _021FB082
	ldrh r6, [r3, #0xa]
	cmp r6, r5
	bls _021FB082
	ldr r4, [r3]
	str r2, [r4, #4]
	ldr r4, [r3]
	str r4, [r2]
	str r3, [r2, #4]
	str r2, [r3]
	b _021FB088
_021FB082:
	add r1, r1, #1
	cmp r1, r0
	blt _021FB054
_021FB088:
	cmp r1, r0
	bne _021FB090
	str r2, [r3, #4]
	str r3, [r2]
_021FB090:
	add r0, r0, #1
	cmp r0, #0xc
	blt _021FB012
	mov r1, #0x8a
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	mov r1, #1
	bl ov96_021FC2B4
	add r4, sp, #4
	mov r7, #0
	mov r5, #0x10
_021FB0AA:
	ldr r4, [r4, #4]
	ldrh r0, [r4, #8]
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #8
	bls _021FB0B8
	mov r6, #8
_021FB0B8:
	mov r0, #0x8a
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldrh r1, [r4, #0xa]
	add r2, r5, #0
	bl ov96_021FC248
	mov r0, #0x8a
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldrh r1, [r4, #0xa]
	add r2, r6, #0
	bl ov96_021FC28C
	mov r0, #0x8a
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldrh r1, [r4, #0xa]
	mov r2, #1
	bl ov96_021FC2E0
	add r7, r7, #1
	add r5, #0x20
	cmp r7, #0xc
	blt _021FB0AA
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021FAFFC


	thumb_func_start ov96_021FB0F4
ov96_021FB0F4: ; 0x021FB0F4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #4]
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #8]
	ldr r2, _021FB3EC ; =0x000003C7
	ldr r0, [sp, #4]
	ldrb r0, [r0, r2]
	cmp r0, #0
	beq _021FB124
	ldr r0, [sp, #4]
	sub r1, r2, #3
	ldrh r0, [r0, r1]
	add r3, r0, #1
	ldr r0, [sp, #4]
	strh r3, [r0, r1]
_021FB124:
	ldr r0, _021FB3F0 ; =0x000003C6
	ldr r1, [sp, #4]
	ldrb r1, [r1, r0]
	cmp r1, #0
	bne _021FB21E
	ldr r1, [sp, #4]
	sub r2, r0, #2
	ldrh r1, [r1, r2]
	cmp r1, #0x96
	blo _021FB21C
	ldr r1, [sp, #4]
	mov r3, #0
	strh r3, [r1, r2]
	mov r2, #1
	strb r2, [r1, r0]
	add r0, r1, #0
	ldr r1, [sp, #8]
	bl ov96_021FAFFC
	mov r4, #0
_021FB14C:
	mov r0, #0x6c
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #4]
	add r5, r0, r1
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl ov96_021EB5B8
	add r7, r0, #0
	mov r0, #0x4a
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r1, r0, #1
	add r0, r0, r1
	add r1, r4, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0x17
	lsr r6, r0, #0x18
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r1, r0, #1
	add r0, r0, r1
	add r0, r4, r0
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	lsl r1, r0, #0x18
	ldr r0, [sp, #8]
	add r0, r0, r6
	ldrb r2, [r0, #0x1c]
	lsr r0, r1, #0x16
	add r1, r2, #0
	asr r1, r0
	mov r0, #0xf
	and r0, r1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	beq _021FB1B8
	cmp r6, #0xc
	bls _021FB1BC
_021FB1B8:
	bl GF_AssertFail
_021FB1BC:
	mov r1, #0xff
	mov r0, #0x51
	lsl r1, r1, #0x16
	lsl r0, r0, #2
	str r1, [r5, r0]
	mov r1, #0x51
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r5, r1]
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x30]
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r5, r1]
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x34]
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r5, r1]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x38]
	mov r0, #0x52
	lsl r0, r0, #2
	strh r6, [r5, r0]
	add r0, r7, #0
	add r1, sp, #0x30
	bl Sprite_SetAffineScale
	add r0, r7, #0
	sub r1, r6, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021FB14C
_021FB21C:
	b _021FB348
_021FB21E:
	ldr r1, [sp, #4]
	sub r2, r0, #2
	ldrh r1, [r1, r2]
	cmp r1, #0x1e
	bhs _021FB22A
	b _021FB348
_021FB22A:
	sub r1, r0, #2
	ldr r0, [sp, #4]
	mov r2, #0
	strh r2, [r0, r1]
	ldr r1, [sp, #8]
	bl ov96_021FAFFC
	mov r7, #0
_021FB23A:
	mov r0, #0x6c
	add r1, r7, #0
	mul r1, r0
	ldr r0, [sp, #4]
	add r4, r0, r1
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB5B8
	add r6, r0, #0
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r1, r0, #1
	add r0, r0, r1
	add r1, r7, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0x17
	lsr r5, r0, #0x18
	ldr r0, [sp]
	bl ov96_021E5F24
	lsl r1, r0, #1
	add r0, r0, r1
	add r0, r7, r0
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	lsl r1, r0, #0x18
	ldr r0, [sp, #8]
	add r0, r0, r5
	ldrb r2, [r0, #0x1c]
	lsr r0, r1, #0x16
	add r1, r2, #0
	asr r1, r0
	mov r0, #0xf
	and r0, r1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	beq _021FB298
	cmp r5, #0xc
	bls _021FB29C
_021FB298:
	bl GF_AssertFail
_021FB29C:
	add r0, r4, #0
	add r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FB2D2
	add r0, r6, #0
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	add r2, sp, #0x24
	ldmia r3!, {r0, r1}
	mov ip, r2
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, ip
	str r0, [r2]
	mov r0, #0x4e
	lsl r0, r0, #0xe
	str r0, [sp, #0x28]
	add r0, r6, #0
	bl Sprite_SetMatrix
	add r1, r5, #0
	add r0, r6, #0
	add r1, #0xb
	bl Sprite_SetAnimCtrlSeq
_021FB2D2:
	mov r0, #0x52
	lsl r0, r0, #2
	ldrsh r0, [r4, r0]
	cmp r5, r0
	beq _021FB33C
	mov r0, #0x52
	lsl r0, r0, #2
	strh r5, [r4, r0]
	add r0, r4, #0
	add r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	bne _021FB33C
	mov r1, #0xff
	mov r0, #0x51
	lsl r1, r1, #0x16
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r1, #0x51
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r4, r1]
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x18]
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r4, r1]
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x1c]
	lsl r1, r1, #2
	ldr r0, _021FB3F4 ; =0x45800000
	ldr r1, [r4, r1]
	bl _fmul
	bl _ffix
	str r0, [sp, #0x20]
	add r0, r6, #0
	add r1, sp, #0x18
	bl Sprite_SetAffineScale
	add r0, r6, #0
	sub r1, r5, #1
	bl Sprite_SetAnimCtrlSeq
_021FB33C:
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #3
	bhs _021FB348
	b _021FB23A
_021FB348:
	ldr r7, _021FB3F4 ; =0x45800000
	mov r5, #0
_021FB34C:
	mov r0, #0x6c
	add r1, r5, #0
	mul r1, r0
	ldr r0, [sp, #4]
	add r4, r0, r1
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB5B8
	add r6, r0, #0
	bl Sprite_GetScalePtr
	ldr r1, [r0]
	mov r0, #1
	lsl r0, r0, #0xc
	cmp r1, r0
	ble _021FB38E
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl _f2d
	ldr r2, _021FB3F8 ; =0x9999999A
	ldr r3, _021FB3FC ; =0x3FB99999
	bl _dsub
	bl _d2f
	mov r1, #0x51
	lsl r1, r1, #2
	str r0, [r4, r1]
	b _021FB398
_021FB38E:
	mov r1, #0xfe
	mov r0, #0x51
	lsl r1, r1, #0x16
	lsl r0, r0, #2
	str r1, [r4, r0]
_021FB398:
	mov r1, #0x51
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r7, #0
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0xc]
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r7, #0
	bl _fmul
	bl _ffix
	mov r1, #0x51
	str r0, [sp, #0x10]
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r7, #0
	bl _fmul
	bl _ffix
	str r0, [sp, #0x14]
	add r0, r6, #0
	add r1, sp, #0xc
	bl Sprite_SetAffineScale
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #3
	blo _021FB34C
	ldr r0, [sp, #4]
	bl ov96_021FB994
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	nop
_021FB3EC: .word 0x000003C7
_021FB3F0: .word 0x000003C6
_021FB3F4: .word 0x45800000
_021FB3F8: .word 0x9999999A
_021FB3FC: .word 0x3FB99999
	thumb_func_end ov96_021FB0F4


	thumb_func_start ov96_021FB400
ov96_021FB400: ; 0x021FB400
	push {r4, r5, r6, r7, lr}
	sub sp, #0x11c
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #8]
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #0x14]
	mov r0, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0x18]
	add r0, sp, #0x2c
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	add r1, sp, #0x18
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	str r0, [sp, #0x28]
	ldr r0, [sp, #8]
	add r0, #0x50
	str r0, [sp, #8]
	ldr r0, [sp, #0x10]
	str r0, [sp, #4]
_021FB434:
	ldr r0, [sp, #8]
	bl ov96_021E8A20
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #0xc]
_021FB440:
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #4]
	add r5, sp, #0x18
	add r7, r1, r0
	add r1, r7, #1
	mov r0, #0x14
	add r2, r1, #0
	mul r2, r0
	add r0, sp, #0x18
	add r4, r0, r2
	ldr r0, [sp]
	ldrh r0, [r0]
	strh r0, [r4, #8]
	ldr r0, [sp]
	ldrh r0, [r0, #0xa]
	strh r0, [r4, #0xc]
	ldr r0, [sp]
	strh r7, [r4, #0xa]
	ldrh r0, [r0, #0x10]
	strh r0, [r4, #0xe]
	mov r0, #0
	str r0, [r4, #0x10]
	add r6, r0, #0
	str r0, [r4, #4]
	cmp r7, #0
	ble _021FB498
_021FB474:
	ldrh r0, [r4, #0xe]
	ldr r5, [r5, #4]
	cmp r0, #0
	beq _021FB486
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_021FB514
	b _021FB48E
_021FB486:
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_021FB56C
_021FB48E:
	cmp r0, #0
	bne _021FB498
	add r6, r6, #1
	cmp r6, r7
	blt _021FB474
_021FB498:
	cmp r6, r7
	bne _021FB4A0
	str r4, [r5, #4]
	str r5, [r4]
_021FB4A0:
	ldr r0, [sp]
	add r0, r0, #2
	str r0, [sp]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #3
	blt _021FB440
	ldr r0, [sp, #8]
	add r0, #0x28
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r0, r0, #3
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #4
	blt _021FB434
	mov r7, #0
	add r5, sp, #0x18
	mov r4, #1
	add r1, r7, #0
	add r6, r7, #0
_021FB4D0:
	ldr r0, [sp, #0x14]
	add r0, r0, r1
	add r1, r1, #1
	strb r6, [r0, #0x1c]
	cmp r1, #6
	blt _021FB4D0
_021FB4DC:
	ldr r5, [r5, #4]
	cmp r5, #0
	bne _021FB4E6
	bl GF_AssertFail
_021FB4E6:
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _021FB4F6
	add r0, r7, r4
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	mov r4, #1
	b _021FB4FC
_021FB4F6:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_021FB4FC:
	ldrh r1, [r5, #0xa]
	ldr r0, [sp, #0x14]
	add r2, r7, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021FB5C8
	add r6, r6, #1
	cmp r6, #0xc
	blt _021FB4DC
	add sp, #0x11c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021FB400


	thumb_func_start ov96_021FB514
ov96_021FB514: ; 0x021FB514
	ldrh r2, [r1, #0xe]
	cmp r2, #0
	beq _021FB556
	ldrh r3, [r0, #0xc]
	ldrh r2, [r1, #0xc]
	cmp r2, r3
	bls _021FB532
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
	mov r0, #1
	bx lr
_021FB532:
	cmp r2, r3
	bne _021FB566
	ldrh r3, [r1, #0xa]
	ldrh r2, [r0, #0xa]
	cmp r3, r2
	bls _021FB550
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
	mov r0, #1
	str r0, [r1, #0x10]
	bx lr
_021FB550:
	mov r1, #1
	str r1, [r0, #0x10]
	b _021FB566
_021FB556:
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
	mov r0, #1
	bx lr
_021FB566:
	mov r0, #0
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021FB514


	thumb_func_start ov96_021FB56C
ov96_021FB56C: ; 0x021FB56C
	ldrh r3, [r0, #8]
	ldrh r2, [r1, #8]
	cmp r2, r3
	bhs _021FB584
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
	mov r0, #1
	bx lr
_021FB584:
	cmp r2, r3
	bne _021FB5C2
	ldrh r3, [r0, #0xc]
	ldrh r2, [r1, #0xc]
	cmp r2, r3
	bls _021FB5A0
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
	mov r0, #1
	bx lr
_021FB5A0:
	cmp r2, r3
	bne _021FB5C2
	ldrh r3, [r1, #0xa]
	ldrh r2, [r0, #0xa]
	cmp r3, r2
	bls _021FB5BE
	ldr r2, [r1]
	str r0, [r2, #4]
	ldr r2, [r1]
	str r2, [r0]
	str r1, [r0, #4]
	str r0, [r1]
	mov r0, #1
	str r0, [r1, #0x10]
	bx lr
_021FB5BE:
	mov r1, #1
	str r1, [r0, #0x10]
_021FB5C2:
	mov r0, #0
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021FB56C


	thumb_func_start ov96_021FB5C8
ov96_021FB5C8: ; 0x021FB5C8
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	cmp r4, #0xc
	blo _021FB5D8
	bl GF_AssertFail
_021FB5D8:
	cmp r6, #0
	beq _021FB5E0
	cmp r6, #0xc
	bls _021FB5E4
_021FB5E0:
	bl GF_AssertFail
_021FB5E4:
	lsr r7, r4, #0x1f
	lsl r3, r4, #0x1f
	sub r3, r3, r7
	mov r2, #0x1f
	ror r3, r2
	add r2, r7, r3
	lsl r2, r2, #0x18
	lsl r0, r4, #0x17
	lsr r2, r2, #0x16
	add r3, r6, #0
	lsl r3, r2
	lsl r2, r3, #0x18
	add r5, #0x1c
	lsr r1, r0, #0x18
	ldrb r0, [r5, r1]
	lsr r2, r2, #0x18
	orr r0, r2
	strb r0, [r5, r1]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021FB5C8


	thumb_func_start ov96_021FB60C
ov96_021FB60C: ; 0x021FB60C
	push {r3, r4}
	mov r4, #0
	mov r1, #0x42
	add r3, r4, #0
	lsl r1, r1, #2
_021FB616:
	ldr r2, [r0, r1]
	cmp r2, #4
	bne _021FB624
	add r3, r3, #1
	add r0, #0x6c
	cmp r3, #3
	blt _021FB616
_021FB624:
	cmp r3, #3
	bne _021FB62A
	mov r4, #1
_021FB62A:
	add r0, r4, #0
	pop {r3, r4}
	bx lr
	thumb_func_end ov96_021FB60C


	thumb_func_start ov96_021FB630
ov96_021FB630: ; 0x021FB630
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r0, [sp, #8]
	bl ov96_021E5F24
	cmp r0, #0
	bne _021FB6B0
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetDataCopyArea
	add r4, r0, #0
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x18]
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetParticipantCount
	str r0, [sp, #0x14]
	str r0, [sp, #0x10]
	cmp r0, #4
	bge _021FB6B0
	mov r1, #0x28
	add r4, #0x50
	mul r1, r0
	add r0, r4, r1
	str r0, [sp, #0xc]
_021FB666:
	ldr r0, [sp, #0xc]
	bl ov96_021E8A20
	add r7, r0, #0
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	mov r4, #0
	sub r1, r1, r0
	lsl r0, r1, #1
	add r5, r1, r0
	ldr r0, [sp, #0x10]
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
_021FB680:
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x18]
	add r2, r7, #0
	add r3, r6, #0
	bl ov96_021FBA3C
	add r4, r4, #1
	add r5, r5, #1
	cmp r4, #3
	blt _021FB680
	ldr r0, [sp, #0xc]
	add r0, #0x28
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #4
	blt _021FB666
_021FB6B0:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_021FB630


	thumb_func_start ov96_021FB6B4
ov96_021FB6B4: ; 0x021FB6B4
	mov r3, #0x15
	lsl r3, r3, #4
	add r1, r1, r3
	add r0, #0xd8
	ldr r3, _021FB6C4 ; =ov96_021FC0FC
	ldr r0, [r0]
	bx r3
	nop
_021FB6C4: .word ov96_021FC0FC
	thumb_func_end ov96_021FB6B4


	thumb_func_start ov96_021FB6C8
ov96_021FB6C8: ; 0x021FB6C8
	push {r3, r4, r5, lr}
	sub sp, #0x18
	ldr r3, _021FB780 ; =ov96_0221C428
	add r5, r0, #0
	add r4, r1, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0xc
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r1, [r4, #0x28]
	cmp r1, #1
	beq _021FB77A
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _021FB77A
	cmp r1, #2
	bne _021FB6F0
	mov r0, #0x18
	b _021FB726
_021FB6F0:
	ldrb r0, [r4, #9]
	cmp r0, #4
	bhi _021FB720
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021FB702: ; jump table
	.short _021FB70C - _021FB702 - 2 ; case 0
	.short _021FB710 - _021FB702 - 2 ; case 1
	.short _021FB714 - _021FB702 - 2 ; case 2
	.short _021FB718 - _021FB702 - 2 ; case 3
	.short _021FB71C - _021FB702 - 2 ; case 4
_021FB70C:
	mov r0, #8
	b _021FB726
_021FB710:
	mov r0, #6
	b _021FB726
_021FB714:
	mov r0, #6
	b _021FB726
_021FB718:
	mov r0, #6
	b _021FB726
_021FB71C:
	mov r0, #4
	b _021FB726
_021FB720:
	bl GF_AssertFail
	mov r0, #8
_021FB726:
	add r1, r4, #0
	add r1, #0x6a
	ldrh r1, [r1]
	add r2, r1, #1
	add r1, r4, #0
	add r1, #0x6a
	strh r2, [r1]
	add r1, r4, #0
	add r1, #0x6a
	ldrh r1, [r1]
	cmp r1, r0
	blt _021FB77A
	add r0, sp, #0
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	add r0, r4, #0
	add r0, #0x6a
	strh r1, [r0]
	bl LCRandom
	mov r1, #7
	bl _s32_div_f
	ldrb r0, [r4, #0x18]
	add r5, #0xdc
	lsl r2, r0, #2
	add r0, sp, #0xc
	ldr r2, [r0, r2]
	sub r0, r1, #3
	add r0, r2, r0
	lsl r0, r0, #0xc
	str r0, [sp]
	mov r0, #0x62
	lsl r0, r0, #0xe
	str r0, [sp, #4]
	ldrb r1, [r4, #0x18]
	ldr r0, [r5]
	add r2, sp, #0
	bl ov96_021FC698
_021FB77A:
	add sp, #0x18
	pop {r3, r4, r5, pc}
	nop
_021FB780: .word ov96_0221C428
	thumb_func_end ov96_021FB6C8


	thumb_func_start ov96_021FB784
ov96_021FB784: ; 0x021FB784
	push {r4, r5, r6}
	sub sp, #0xc
	ldr r6, _021FB7C4 ; =ov96_0221C41C
	add r4, r1, #0
	ldmia r6!, {r0, r1}
	add r5, sp, #0
	add r3, r5, #0
	stmia r5!, {r0, r1}
	ldr r0, [r6]
	str r0, [r5]
	mov r0, #0
_021FB79A:
	lsl r1, r0, #2
	ldr r1, [r3, r1]
	sub r1, #0x18
	cmp r1, r4
	bge _021FB7B2
	add r1, #0x30
	cmp r4, r1
	bge _021FB7B2
	cmp r2, #0x58
	ble _021FB7B2
	cmp r2, #0xa8
	blt _021FB7BE
_021FB7B2:
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #3
	blo _021FB79A
	mov r0, #3
_021FB7BE:
	add sp, #0xc
	pop {r4, r5, r6}
	bx lr
	.balign 4, 0
_021FB7C4: .word ov96_0221C41C
	thumb_func_end ov96_021FB784


	thumb_func_start ov96_021FB7C8
ov96_021FB7C8: ; 0x021FB7C8
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r1, r4, #0
	ldr r0, [r4, #4]
	ldr r2, _021FB804 ; =ov96_0221C3FC
	add r1, #8
	bl AddWindow
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #4]
	mov r1, #3
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r4]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	add r4, #8
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add sp, #4
	pop {r3, r4, pc}
	nop
_021FB804: .word ov96_0221C3FC
	thumb_func_end ov96_021FB7C8


	thumb_func_start ov96_021FB808
ov96_021FB808: ; 0x021FB808
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r2, _021FB8AC ; =0x00000135
	add r6, r1, #0
	ldr r3, [r5]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	add r7, r0, #0
	ldr r0, [r5]
	bl MessageFormat_New
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #0x1e
	bl _s32_div_f
	mov r1, #0
	add r2, r0, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r4, #0
	mov r3, #3
	bl BufferIntegerAsString
	add r0, r6, #0
	mov r1, #0x1e
	bl _s32_div_f
	mov r0, #0xa
	mul r0, r1
	mov r1, #0x1e
	bl _s32_div_f
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	add r0, r4, #0
	add r3, r1, #0
	bl BufferIntegerAsString
	ldr r3, [r5]
	add r0, r4, #0
	add r1, r7, #0
	mov r2, #0x9c
	bl ReadMsgData_ExpandPlaceholders
	add r6, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FB8B0 ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #8
	add r2, r6, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #0
	bl MessageFormat_Delete
	add r0, r7, #0
	bl DestroyMsgData
	add r5, #8
	add r0, r5, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FB8AC: .word 0x00000135
_021FB8B0: .word 0x000F0E00
	thumb_func_end ov96_021FB808


	thumb_func_start ov96_021FB8B4
ov96_021FB8B4: ; 0x021FB8B4
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #0
	bge _021FB8BE
	mov r1, #0
_021FB8BE:
	add r0, r1, #0
	bl _dflt
	add r3, r1, #0
	mov r1, #1
	add r2, r0, #0
	mov r0, #0
	lsl r1, r1, #0x1e
	bl _dmul
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FB8F8 ; =0x40590000
	mov r0, #0
	bl _dadd
	ldr r3, _021FB8F8 ; =0x40590000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r0, #0
	ldr r0, [r4]
	add r2, r1, #0
	bl ov96_021EB10C
	pop {r4, pc}
	nop
_021FB8F8: .word 0x40590000
	thumb_func_end ov96_021FB8B4


	thumb_func_start ov96_021FB8FC
ov96_021FB8FC: ; 0x021FB8FC
	push {r3, r4, r5, lr}
	add r4, r0, #0
	cmp r1, #0
	beq _021FB934
	ldrb r0, [r4, #0xc]
	ldrh r1, [r4, #0x38]
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	sub r0, r1, r0
	bl _dflt
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FB988 ; =0x40240000
	mov r0, #0
	bl _dmul
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FB98C ; =0x40590000
	mov r0, #0
	bl _dsub
	bl _d2f
	add r5, r0, #0
	b _021FB968
_021FB934:
	ldrb r0, [r4, #0xc]
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl _dfltu
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FB988 ; =0x40240000
	mov r0, #0
	bl _dmul
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FB98C ; =0x40590000
	mov r0, #0
	bl _dsub
	bl _d2f
	mov r1, #0
	add r5, r0, #0
	bl _fls
	bhs _021FB968
	ldr r5, _021FB990 ; =0x41200000
_021FB968:
	add r0, r5, #0
	bl _f2d
	ldr r3, _021FB98C ; =0x40590000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r0, #0
	ldr r0, [r4]
	add r2, r1, #0
	bl ov96_021EB10C
	pop {r3, r4, r5, pc}
	nop
_021FB988: .word 0x40240000
_021FB98C: .word 0x40590000
_021FB990: .word 0x41200000
	thumb_func_end ov96_021FB8FC


	thumb_func_start ov96_021FB994
ov96_021FB994: ; 0x021FB994
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x1e
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	add r0, r6, #0
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r6, #0
	mov r1, #0x1e
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x64
	mul r0, r1
	mov r1, #0x1e
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r4, #0
	mov r1, #0x3c
	bl _s32_div_f
	add r1, r0, #0
	mov r0, #0xeb
	lsl r0, r0, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0x3c
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r1, r0, #0
	mov r0, #0xed
	lsl r0, r0, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	mov r0, #0xee
	lsl r0, r0, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r6, #0
	mov r1, #0xa
	bl _s32_div_f
	add r1, r0, #0
	mov r0, #0xf
	lsl r0, r0, #6
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021FB994


	thumb_func_start ov96_021FBA3C
ov96_021FBA3C: ; 0x021FBA3C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r1, #0
	str r3, [sp, #8]
	add r7, r0, #0
	mov r0, #0x8e
	lsl r0, r0, #2
	add r1, sp, #0x18
	str r2, [sp, #4]
	ldrb r2, [r1, #0x14]
	mov r1, #0x28
	add r0, r6, r0
	mul r1, r2
	add r4, r0, r1
	ldr r0, [r4, #0x18]
	ldr r5, [sp, #0x28]
	cmp r0, #1
	beq _021FBA8C
	ldrb r0, [r4]
	cmp r0, #2
	beq _021FBA8C
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _021FBA8C
	ldr r0, [r4, #8]
	ldr r1, [r4, #0x10]
	bl _fls
	bhs _021FBA8C
	ldr r0, [r4, #8]
	ldr r1, [r4, #0x14]
	bl _fadd
	str r0, [r4, #8]
	ldr r1, [r4, #0x10]
	bl _fgr
	bls _021FBA8C
	ldr r0, [r4, #0x10]
	str r0, [r4, #8]
_021FBA8C:
	ldrb r0, [r4]
	cmp r0, #2
	bne _021FBAA4
	ldrb r0, [r4, #1]
	sub r0, r0, #1
	strb r0, [r4, #1]
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _021FBB50
	mov r0, #0
	strb r0, [r4]
	b _021FBB50
_021FBAA4:
	add r0, r6, #0
	add r0, #0xd8
	ldr r0, [r0]
	ldr r2, [r4, #0x20]
	add r1, r5, #0
	bl ov96_021FC164
	mov r1, #0
	mvn r1, r1
	str r0, [sp, #0xc]
	cmp r0, r1
	beq _021FBB50
	ldr r1, [r4, #0x24]
	cmp r1, r0
	beq _021FBB50
	bl LCRandom
	mov r1, #0x64
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	ldrb r0, [r4, #3]
	cmp r1, r0
	bhs _021FBB14
	ldrb r0, [r4, #2]
	cmp r0, #4
	bhs _021FBAF2
	add r0, r0, #1
	strb r0, [r4, #2]
	ldrb r1, [r4, #2]
	ldr r0, [r4, #0x10]
	sub r1, r1, #1
	lsl r2, r1, #2
	ldr r1, _021FBBAC ; =ov96_0221C444
	ldr r1, [r1, r2]
	bl _fadd
	str r0, [r4, #8]
_021FBAF2:
	mov r0, #1
	str r0, [sp]
	ldr r1, [sp, #8]
	add r0, r7, #0
	add r2, r5, #0
	mov r3, #6
	bl ov96_021E8228
	mov r0, #1
	str r0, [sp]
	ldr r1, [sp, #8]
	add r0, r7, #0
	add r2, r5, #0
	mov r3, #2
	bl ov96_021E8228
	b _021FBB4C
_021FBB14:
	ldrb r0, [r4, #4]
	cmp r1, r0
	bhs _021FBB3C
	mov r0, #2
	strb r0, [r4]
	mov r0, #0x1e
	strb r0, [r4, #1]
	mov r0, #0
	strb r0, [r4, #2]
	mov r0, #0x3f
	lsl r0, r0, #0x18
	str r0, [r4, #8]
	mov r3, #1
	str r3, [sp]
	ldr r1, [sp, #8]
	add r0, r7, #0
	add r2, r5, #0
	bl ov96_021E8228
	b _021FBB4C
_021FBB3C:
	mov r0, #1
	str r0, [sp]
	ldr r1, [sp, #8]
	add r0, r7, #0
	add r2, r5, #0
	mov r3, #2
	bl ov96_021E8228
_021FBB4C:
	ldr r0, [sp, #0xc]
	str r0, [r4, #0x24]
_021FBB50:
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	bl _fadd
	str r0, [sp, #0x10]
	bl _ffix
	add r7, r0, #0
	bl _fflt
	add r1, r0, #0
	ldr r0, [sp, #0x10]
	bl _fsub
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x20]
	lsl r1, r5, #1
	add r2, r0, r7
	ldr r0, [sp, #4]
	str r2, [r4, #0x20]
	strh r2, [r0, r1]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	bne _021FBBA6
	mov r0, #1
	ldr r2, [r4, #0x20]
	lsl r0, r0, #0xc
	cmp r2, r0
	blt _021FBBA6
	ldr r2, [sp, #4]
	mov r0, #1
	add r3, r2, r1
	mov r1, #0x23
	strh r0, [r3, #0x10]
	lsl r1, r1, #4
	ldr r2, [r6, r1]
	strh r2, [r3, #0xa]
	ldr r1, [r6, r1]
	str r1, [r4, #0x1c]
	str r0, [r4, #0x18]
	ldr r0, _021FBBB0 ; =0x000008A1
	bl PlaySE
_021FBBA6:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_021FBBAC: .word ov96_0221C444
_021FBBB0: .word 0x000008A1
	thumb_func_end ov96_021FBA3C


	thumb_func_start ov96_021FBBB4
ov96_021FBBB4: ; 0x021FBBB4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp]
	add r6, r1, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x10]
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantCount
	str r0, [sp, #4]
	cmp r0, #4
	bhs _021FBCAC
	str r0, [sp, #0xc]
_021FBBD0:
	ldr r1, [sp, #4]
	ldr r0, [sp, #0xc]
	mov r5, #0
	sub r1, r1, r0
	lsl r0, r1, #1
	add r0, r1, r0
	str r0, [sp, #8]
	mov r1, #0x8e
	ldr r0, [sp, #0x10]
	lsl r1, r1, #2
	add r0, r0, r1
	str r0, [sp, #0x14]
_021FBBE8:
	ldr r0, [sp, #8]
	add r0, r5, r0
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	add r2, r1, #0
	mov r0, #0x28
	mul r2, r0
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #4]
	add r4, r0, r2
	ldr r0, [sp]
	add r2, r5, #0
	bl ov96_021E60D8
	add r7, r0, #0
	ldrb r0, [r7, #1]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r0, [r0, #0x3c]
	bl _fflt
	ldr r1, _021FBCB0 ; =0x41200000
	bl _fdiv
	str r0, [r4, #0x10]
	ldrb r0, [r7, #4]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r0, [r0, #0x28]
	bl _fflt
	ldr r1, _021FBCB4 ; =0x42C80000
	bl _fdiv
	str r0, [r4, #0x14]
	bl LCRandom
	mov r1, #6
	bl _s32_div_f
	cmp r1, #5
	bhi _021FBC90
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021FBC48: ; jump table
	.short _021FBC54 - _021FBC48 - 2 ; case 0
	.short _021FBC5E - _021FBC48 - 2 ; case 1
	.short _021FBC68 - _021FBC48 - 2 ; case 2
	.short _021FBC72 - _021FBC48 - 2 ; case 3
	.short _021FBC7C - _021FBC48 - 2 ; case 4
	.short _021FBC86 - _021FBC48 - 2 ; case 5
_021FBC54:
	mov r0, #0xa
	strb r0, [r4, #3]
	mov r0, #0x32
	strb r0, [r4, #4]
	b _021FBC94
_021FBC5E:
	mov r0, #0x14
	strb r0, [r4, #3]
	mov r0, #0x32
	strb r0, [r4, #4]
	b _021FBC94
_021FBC68:
	mov r0, #0x1e
	strb r0, [r4, #3]
	mov r0, #0x3c
	strb r0, [r4, #4]
	b _021FBC94
_021FBC72:
	mov r0, #0x14
	strb r0, [r4, #3]
	mov r0, #0x46
	strb r0, [r4, #4]
	b _021FBC94
_021FBC7C:
	mov r0, #0x1e
	strb r0, [r4, #3]
	mov r0, #0x46
	strb r0, [r4, #4]
	b _021FBC94
_021FBC86:
	mov r0, #0x28
	strb r0, [r4, #3]
	mov r0, #0x50
	strb r0, [r4, #4]
	b _021FBC94
_021FBC90:
	bl GF_AssertFail
_021FBC94:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #3
	blo _021FBBE8
	ldr r0, [sp, #4]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	cmp r0, #4
	blo _021FBBD0
_021FBCAC:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FBCB0: .word 0x41200000
_021FBCB4: .word 0x42C80000
	thumb_func_end ov96_021FBBB4


	thumb_func_start ov96_021FBCB8
ov96_021FBCB8: ; 0x021FBCB8
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r4, r1, #0
	add r5, r0, #0
	ldrb r0, [r4, #9]
	cmp r0, #4
	bhs _021FBD82
	ldr r0, [r4, #0x4c]
	bl ov96_021EB5B8
	add r6, r0, #0
	ldrb r0, [r4, #9]
	add r0, r0, #1
	strb r0, [r4, #9]
	ldrb r0, [r4, #9]
	cmp r0, #1
	bne _021FBD06
	ldrb r2, [r4, #0x18]
	ldr r1, _021FBDA0 ; =ov96_0221DC2C
	ldr r0, _021FBDA4 ; =0x000008A6
	ldrb r1, [r1, r2]
	bl sub_0200606C
	ldrb r2, [r4, #0x18]
	ldr r0, _021FBDA0 ; =ov96_0221DC2C
	ldr r1, _021FBDA8 ; =ov96_0221DC28
	ldrb r0, [r0, r2]
	ldrsb r1, [r1, r2]
	bl sub_020061D0
	ldr r0, [r4, #0x24]
	mov r1, #5
	bl ov96_021EAC0C
	add r0, r6, #0
	mov r1, #1
	bl Sprite_SetAnimCtrlSeq
	b _021FBD5A
_021FBD06:
	cmp r0, #4
	bne _021FBD36
	ldrb r2, [r4, #0x18]
	ldr r1, _021FBDA0 ; =ov96_0221DC2C
	ldr r0, _021FBDAC ; =0x000008A9
	ldrb r1, [r1, r2]
	bl sub_0200606C
	ldrb r2, [r4, #0x18]
	ldr r0, _021FBDA0 ; =ov96_0221DC2C
	ldr r1, _021FBDA8 ; =ov96_0221DC28
	ldrb r0, [r0, r2]
	ldrsb r1, [r1, r2]
	bl sub_020061D0
	ldr r0, [r4, #0x24]
	mov r1, #6
	bl ov96_021EAC0C
	add r0, r6, #0
	mov r1, #2
	bl Sprite_SetAnimCtrlSeq
	b _021FBD5A
_021FBD36:
	add r0, #0xfe
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bhi _021FBD5A
	ldrb r2, [r4, #0x18]
	ldr r1, _021FBDA0 ; =ov96_0221DC2C
	ldr r0, _021FBDB0 ; =0x000008A7
	ldrb r1, [r1, r2]
	bl sub_0200606C
	ldrb r2, [r4, #0x18]
	ldr r0, _021FBDA0 ; =ov96_0221DC2C
	ldr r1, _021FBDA8 ; =ov96_0221DC28
	ldrb r0, [r0, r2]
	ldrsb r1, [r1, r2]
	bl sub_020061D0
_021FBD5A:
	ldr r0, [r4, #0xc]
	bl _f2d
	ldr r3, _021FBDB4 ; =0x40240000
	mov r2, #0
	bl _dls
	bhs _021FBD7E
	ldrb r1, [r4, #9]
	ldr r0, [r4, #0x50]
	sub r1, r1, #1
	lsl r2, r1, #2
	ldr r1, _021FBDB8 ; =ov96_0221C444
	ldr r1, [r1, r2]
	bl _fadd
	str r0, [r4, #0xc]
	b _021FBD82
_021FBD7E:
	bl GF_AssertFail
_021FBD82:
	add r0, r5, #0
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldrb r2, [r4, #0x18]
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r3, #6
	bl ov96_021E8228
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021FBDA0: .word ov96_0221DC2C
_021FBDA4: .word 0x000008A6
_021FBDA8: .word ov96_0221DC28
_021FBDAC: .word 0x000008A9
_021FBDB0: .word 0x000008A7
_021FBDB4: .word 0x40240000
_021FBDB8: .word ov96_0221C444
	thumb_func_end ov96_021FBCB8


	thumb_func_start ov96_021FBDBC
ov96_021FBDBC: ; 0x021FBDBC
	mov r1, #0x23
	lsl r1, r1, #4
	ldr r2, [r0, r1]
	add r3, r0, #0
	add r2, r2, #1
	str r2, [r0, r1]
	mov r2, #0
_021FBDCA:
	add r1, r3, #0
	add r1, #0xe8
	ldrb r1, [r1]
	cmp r1, #0
	bne _021FBDE0
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r2, [r0, r1]
	add r2, r2, #1
	str r2, [r0, r1]
	bx lr
_021FBDE0:
	add r2, r2, #1
	add r3, #0x6c
	cmp r2, #3
	blt _021FBDCA
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021FBDBC


	thumb_func_start ov96_021FBDEC
ov96_021FBDEC: ; 0x021FBDEC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r1, #0x1e
	bl _s32_div_f
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #0x1e
	bl _s32_div_f
	mov r0, #0xa
	mul r0, r1
	mov r1, #0x1e
	bl _s32_div_f
	mov r1, #0x1e
	mul r1, r0
	add r0, r1, #0
	mov r1, #0xa
	bl _s32_div_f
	mov r1, #0x1e
	mul r1, r4
	add r0, r1, r0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021FBDEC


	thumb_func_start ov96_021FBE20
ov96_021FBE20: ; 0x021FBE20
	push {r3, r4, r5, lr}
	lsl r5, r0, #4
	add r0, r1, #0
	add r1, r5, #0
	bl Heap_Alloc
	add r4, r0, #0
	mov r0, #0
	add r1, r4, #0
	add r2, r5, #0
	bl MIi_CpuClearFast
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021FBE20

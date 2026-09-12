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

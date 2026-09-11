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

	thumb_func_start ov96_0220F3BC
ov96_0220F3BC: ; 0x0220F3BC
	push {r3, lr}
	ldr r0, [r0, #4]
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1d
	cmp r0, #6
	bhi _0220F3F2
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0220F3D4: ; jump table
	.short _0220F3F2 - _0220F3D4 - 2 ; case 0
	.short _0220F3F2 - _0220F3D4 - 2 ; case 1
	.short _0220F3F2 - _0220F3D4 - 2 ; case 2
	.short _0220F3E2 - _0220F3D4 - 2 ; case 3
	.short _0220F3E6 - _0220F3D4 - 2 ; case 4
	.short _0220F3EA - _0220F3D4 - 2 ; case 5
	.short _0220F3EE - _0220F3D4 - 2 ; case 6
_0220F3E2:
	mov r0, #1
	pop {r3, pc}
_0220F3E6:
	mov r0, #2
	pop {r3, pc}
_0220F3EA:
	mov r0, #3
	pop {r3, pc}
_0220F3EE:
	mov r0, #5
	pop {r3, pc}
_0220F3F2:
	bl GF_AssertFail
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov96_0220F3BC


	thumb_func_start ov96_0220F3FC
ov96_0220F3FC: ; 0x0220F3FC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x118
	str r0, [sp, #8]
	ldr r0, [r0, #0x10]
	bl SpriteManager_GetSpriteList
	str r0, [sp]
	ldr r0, [sp, #8]
	ldr r3, [sp, #8]
	ldr r0, [r0]
	ldr r3, [r3, #0x1c]
	mov r1, #0xc
	mov r2, #7
	bl ov96_021EA854
	ldr r1, [sp, #8]
	str r0, [r1, #0x20]
	bl ov96_021EB138
	mov r4, #0
	add r5, sp, #0x14
	add r2, r5, #0
	add r0, r4, #0
	add r1, r4, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	str r0, [r2]
	ldr r0, [sp, #8]
	add r6, sp, #0x58
	ldr r0, [r0, #4]
	str r0, [sp, #0xc]
_0220F446:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r1, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	add r2, r7, #0
	add r3, r6, #0
	bl ov96_021E6168
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	add r2, r7, #0
	bl ov96_021E60C0
	bl ov96_021E6108
	str r0, [r5, #0x14]
	add r4, r4, #1
	add r6, #0x10
	add r5, r5, #4
	cmp r4, #0xc
	blt _0220F446
	mov r0, #1
	str r0, [sp, #0x18]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	mov r1, #0xc
	ldr r0, [r0, #0x20]
	add r2, sp, #0x58
	add r3, sp, #0x14
	bl ov96_021EA8A8
	add sp, #0x118
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220F3FC


	thumb_func_start ov96_0220F4A0
ov96_0220F4A0: ; 0x0220F4A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x58
	str r0, [sp, #0xc]
	add r0, sp, #0x40
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	str r1, [r0, #0xc]
	str r1, [r0, #0x10]
	str r1, [r0, #0x14]
	mov r1, #0xaa
	mov r2, #0x11
	bl ReadWholeNarcMemberByIdPair
	ldr r0, [sp, #0xc]
	cmp r0, #0
	bne _0220F4C8
	bl GF_AssertFail
_0220F4C8:
	ldr r0, [sp, #0xc]
	ldr r0, [r0, #4]
	cmp r0, #0
	bne _0220F4D4
	bl GF_AssertFail
_0220F4D4:
	ldr r0, [sp, #0xc]
	ldr r7, [r0, #4]
	add r0, r7, #0
	bl ov96_0220F280
	mov r2, #0x8f
	ldr r1, [sp, #0xc]
	lsl r2, r2, #2
	add r1, r1, r2
	mov r0, #0
	mov r2, #3
	mov r3, #3
_0220F4EC:
	ldr r5, [r1]
	add r4, r0, #0
	bic r5, r2
	and r4, r3
	orr r4, r5
	str r4, [r1]
	add r0, r0, #1
	add r1, #0xe4
	cmp r0, #4
	blt _0220F4EC
	mov r1, #0x59
	ldr r0, [sp, #0xc]
	lsl r1, r1, #2
	add r0, r0, r1
	mov r6, #0
	str r0, [sp, #0x20]
_0220F50C:
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	str r1, [sp, #0x10]
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	mov r1, #0xe4
	str r0, [sp, #0x1c]
	mul r1, r0
	ldr r0, [sp, #0x20]
	add r2, r0, r1
	ldr r1, [sp, #0x10]
	mov r0, #0x48
	mul r0, r1
	add r5, r2, r0
	ldr r0, [sp, #0xc]
	lsl r1, r6, #0x18
	ldr r0, [r0, #0x20]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	mov r1, #1
	str r0, [sp, #0x24]
	bl ov96_021EAB38
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	add r0, r7, #0
	add r1, r4, #0
	bl ov96_021E60C0
	bl ov96_021E6138
	lsl r1, r0, #3
	add r0, sp, #0x40
	add r2, r0, r1
	add r1, r2, #0
	sub r1, #8
	sub r2, r2, #4
	ldr r0, [sp, #0x24]
	ldr r1, [r1]
	ldr r2, [r2]
	bl ov96_021EAF70
	ldr r0, [sp, #0xc]
	lsl r1, r6, #0x18
	ldr r0, [r0, #0x20]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r4, r0, #0
	bl ov96_021EAA20
	bl ov96_021E8BB0
	str r0, [sp, #0x28]
	add r0, r4, #0
	mov r1, #0
	bl ov96_0220D554
	mov r1, #0xfe
	lsl r1, r1, #0x16
	add r0, r4, #0
	add r2, r1, #0
	bl ov96_021EB10C
	ldr r1, [sp, #0x1c]
	mov r0, #0xc
	add r2, r1, #0
	mul r2, r0
	ldr r0, _0220F700 ; =ov96_0221CFBC
	add r1, r0, r2
	ldr r0, [sp, #0x10]
	lsl r0, r0, #2
	add r0, r1, r0
	mov r1, #0
	ldrsh r1, [r0, r1]
	str r1, [sp, #0x18]
	mov r1, #2
	ldrsh r0, [r0, r1]
	str r0, [sp, #0x14]
	add r0, r4, #0
	bl ov96_021EAC0C
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x14]
	add r0, r4, #0
	bl ov96_021EAF94
	bl ov96_021E6104
	add r1, r0, #0
	add r0, r4, #0
	bl ov96_021EAF6C
	add r0, sp, #0x2c
	str r0, [sp]
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x14]
	add r0, r4, #0
	add r3, sp, #0x30
	bl ov96_021EB0A4
	str r7, [r5]
	ldr r1, [r5, #0x40]
	ldr r0, _0220F704 ; =0xFFF0FFFF
	and r1, r0
	lsl r0, r6, #0x1c
	lsr r0, r0, #0xc
	orr r0, r1
	str r0, [r5, #0x40]
	ldr r0, [sp, #0x1c]
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	add r0, r5, #0
	add r0, #0x45
	strb r1, [r0]
	ldr r0, [sp, #0x10]
	lsl r0, r0, #0x18
	lsr r3, r0, #0x18
	add r0, r5, #0
	add r0, #0x46
	strb r3, [r0]
	str r4, [r5, #4]
	ldr r2, [r5, #0x40]
	ldr r0, _0220F708 ; =0xFCFFFFFF
	and r0, r2
	ldr r2, [sp, #0x28]
	ldrh r2, [r2, #4]
	lsl r2, r2, #0x1e
	lsr r2, r2, #6
	orr r0, r2
	str r0, [r5, #0x40]
	add r0, r7, #0
	add r2, r3, #0
	bl ov96_0220F378
	str r0, [r5, #8]
	mov r0, #2
	str r0, [r5, #0xc]
	ldr r1, [r5, #0x40]
	ldr r0, _0220F70C ; =0xFF0FFFFF
	and r1, r0
	mov r0, #2
	lsl r0, r0, #0x14
	orr r0, r1
	str r0, [r5, #0x40]
	ldr r0, [sp, #0x30]
	lsl r0, r0, #0xc
	str r0, [r5, #0x1c]
	ldr r0, [sp, #0x2c]
	lsl r0, r0, #0xc
	str r0, [r5, #0x20]
	ldr r0, [sp, #0x30]
	lsl r0, r0, #0xc
	str r0, [r5, #0x10]
	ldr r0, [sp, #0x2c]
	lsl r0, r0, #0xc
	str r0, [r5, #0x14]
	add r0, r7, #0
	bl ov96_021E5F24
	ldr r1, [sp, #0x1c]
	cmp r1, r0
	bne _0220F6A8
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x18]
	lsl r0, r0, #2
	add r1, sp, #0x34
	add r2, sp, #0x34
	add r1, r1, r0
	strh r3, [r2, r0]
	ldr r0, [sp, #0x14]
	strh r0, [r1, #2]
	ldr r0, [sp, #0xc]
	ldr r0, [r0, #0x10]
	bl SpriteManager_GetSpriteList
	add r3, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r2, [sp, #0xc]
	add r0, r7, #0
	ldr r2, [r2, #0x1c]
	add r1, r4, #0
	bl ov96_021E64F8
	mov r1, #4
	bl Sprite_SetDrawPriority
	add r0, r4, #0
	mov r1, #6
	bl ov96_021EABA8
	b _0220F6B0
_0220F6A8:
	add r0, r4, #0
	mov r1, #7
	bl ov96_021EABA8
_0220F6B0:
	add r0, r7, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _0220F6D0
	add r0, r7, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0x28
	bl ov96_021E8A20
	add r1, r0, r6
	ldr r0, [sp, #0x30]
	strb r0, [r1, #4]
	ldr r0, [sp, #0x2c]
	strb r0, [r1, #0x10]
_0220F6D0:
	add r6, r6, #1
	cmp r6, #0xc
	bge _0220F6D8
	b _0220F50C
_0220F6D8:
	ldr r0, [sp, #0xc]
	ldr r0, [r0, #0x10]
	bl SpriteManager_GetSpriteList
	add r3, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	add r0, sp, #0x34
	str r0, [sp, #8]
	ldr r2, [sp, #0xc]
	add r0, r7, #0
	ldr r2, [r2, #0x1c]
	mov r1, #0
	bl ov96_021E62AC
	add sp, #0x58
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220F700: .word ov96_0221CFBC
_0220F704: .word 0xFFF0FFFF
_0220F708: .word 0xFCFFFFFF
_0220F70C: .word 0xFF0FFFFF
	thumb_func_end ov96_0220F4A0


	thumb_func_start ov96_0220F710
ov96_0220F710: ; 0x0220F710
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #8]
	str r0, [sp, #4]
	add r0, #0xcc
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	str r0, [sp]
_0220F728:
	ldr r0, [sp, #0xc]
	mov r1, #3
	bl _s32_div_f
	add r4, r0, #0
	ldr r0, [sp, #0xc]
	mov r1, #3
	bl _s32_div_f
	mov r2, #0x59
	ldr r0, [sp, #8]
	lsl r2, r2, #2
	add r0, r0, r2
	str r0, [sp, #0x10]
	mov r0, #0xe4
	add r2, r4, #0
	mul r2, r0
	ldr r0, [sp, #0x10]
	add r2, r0, r2
	mov r0, #0x48
	mul r0, r1
	add r7, r2, r0
	ldr r0, [sp, #0xc]
	add r4, r0, #1
	cmp r4, #0xc
	blt _0220F75E
	b _0220F8AE
_0220F75E:
	ldr r1, [sp, #4]
	add r1, r1, r0
	mov r0, #0xc
	mul r0, r4
	add r6, r1, r0
	add r0, r7, #0
	str r0, [sp, #0x14]
	add r0, #0x1c
	str r0, [sp, #0x14]
	add r0, r7, #0
	str r0, [sp, #0x18]
	add r0, #0x28
	str r0, [sp, #0x18]
	add r0, r7, #0
	str r0, [sp, #0x1c]
	add r0, #0x34
	str r0, [sp, #0x1c]
	add r0, r7, #0
	str r0, [sp, #0x20]
	add r0, #0x40
	str r0, [sp, #0x20]
_0220F788:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0xe4
	add r2, r5, #0
	mul r2, r0
	ldr r0, [sp, #0x10]
	add r2, r0, r2
	mov r0, #0x48
	mul r0, r1
	add r5, r2, r0
	add r0, r7, #0
	bl ov96_0220D694
	cmp r0, #0
	beq _0220F89A
	add r0, r5, #0
	bl ov96_0220D694
	cmp r0, #0
	beq _0220F89A
	add r0, r7, #0
	add r1, r5, #0
	bl ov96_0220D5D0
	cmp r0, #0
	beq _0220F89A
	ldr r0, [sp]
	ldrb r0, [r0, r4]
	cmp r0, #0
	bne _0220F89A
	mov r1, #0
	add r0, sp, #0x24
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	mov r0, #1
	strb r0, [r6]
	ldrb r1, [r6]
	ldr r0, [sp]
	add r2, sp, #0x24
	strb r1, [r0, r4]
	add r1, r5, #0
	ldr r0, [sp, #0x14]
	add r1, #0x1c
	bl VEC_Subtract
	add r0, sp, #0x24
	add r1, r0, #0
	bl VEC_Normalize
	ldr r0, [r5, #8]
	ldr r1, [r0, #4]
	ldr r0, [r7, #0x40]
	lsl r0, r0, #6
	lsr r0, r0, #0x1e
	bne _0220F812
	mov r0, #6
	mul r0, r1
	mov r1, #5
	bl _s32_div_f
	add r1, r0, #0
_0220F812:
	ldr r2, [sp, #0x18]
	add r0, r1, #0
	ldr r3, [sp, #0x1c]
	add r1, sp, #0x24
	bl VEC_MultAdd
	ldr r0, [r7, #8]
	ldr r1, [r0, #4]
	ldr r0, [r5, #0x40]
	lsl r0, r0, #6
	lsr r0, r0, #0x1e
	bne _0220F836
	mov r0, #6
	mul r0, r1
	mov r1, #5
	bl _s32_div_f
	add r1, r0, #0
_0220F836:
	add r2, r5, #0
	add r3, r5, #0
	add r0, r1, #0
	add r1, sp, #0x24
	add r2, #0x28
	add r3, #0x34
	bl VEC_MultAdd
	mov r0, #0
	ldr r1, [r5, #0x34]
	mvn r0, r0
	mul r0, r1
	str r0, [r5, #0x34]
	mov r0, #0
	ldr r1, [r5, #0x38]
	mvn r0, r0
	mul r0, r1
	str r0, [r5, #0x38]
	mov r1, #2
	ldr r0, [sp, #0x1c]
	lsl r1, r1, #0xe
	bl ov96_0220E974
	add r0, r5, #0
	mov r1, #2
	add r0, #0x34
	lsl r1, r1, #0xe
	bl ov96_0220E974
	add r0, sp, #0x24
	bl ov96_0220D6CC
	lsl r0, r0, #0x1c
	ldr r2, [r5, #0x40]
	ldr r1, _0220F8C4 ; =0xFF0FFFFF
	lsr r0, r0, #8
	and r1, r2
	orr r1, r0
	mov r0, #1
	lsl r0, r0, #0x1a
	orr r0, r1
	str r0, [r5, #0x40]
	ldr r0, [sp, #0x20]
	ldr r1, [r0]
	mov r0, #1
	lsl r0, r0, #0x1a
	orr r1, r0
	ldr r0, [sp, #0x20]
	str r1, [r0]
	b _0220F8A4
_0220F89A:
	mov r0, #0
	strb r0, [r6]
	ldrb r1, [r6]
	ldr r0, [sp]
	strb r1, [r0, r4]
_0220F8A4:
	add r4, r4, #1
	add r6, #0xc
	cmp r4, #0xc
	bge _0220F8AE
	b _0220F788
_0220F8AE:
	ldr r0, [sp]
	add r0, #0xc
	str r0, [sp]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0xc
	bge _0220F8C0
	b _0220F728
_0220F8C0:
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220F8C4: .word 0xFF0FFFFF
	thumb_func_end ov96_0220F710


	thumb_func_start ov96_0220F8C8
ov96_0220F8C8: ; 0x0220F8C8
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	add r5, r0, #0
	add r0, r7, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0x28
	bl ov96_021E8A20
	mov r0, #0
	str r0, [sp]
_0220F8DE:
	ldr r0, [r5, #4]
	add r1, r5, #0
	lsr r3, r0, #0x1e
	add r0, r3, #0
	mov r2, #0x48
	add r1, #0x48
	mul r0, r2
	ldr r4, [r1, r0]
	ldr r3, _0220FA0C ; =0xF7FFFFFF
	and r3, r4
	str r3, [r1, r0]
	ldr r1, [r5, #4]
	lsl r0, r1, #0x11
	lsr r0, r0, #0x1f
	beq _0220F928
	mov r1, #0
	mov r2, #2
	add r0, r5, #0
	ldrsh r1, [r5, r1]
	ldrsh r2, [r5, r2]
	add r0, #8
	bl ov96_0220DAA0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #0xc
	beq _0220F9DE
	mov r1, #2
	ldr r2, [r5, #4]
	lsl r1, r1, #0x1c
	orr r2, r1
	ldr r1, _0220FA10 ; =0x3FFFFFFF
	lsl r0, r0, #0x1e
	and r1, r2
	orr r0, r1
	str r0, [r5, #4]
	b _0220F9DE
_0220F928:
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1f
	beq _0220F998
	lsl r0, r1, #2
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0220F9DE
	add r3, r5, #0
	lsr r0, r1, #0x1e
	add r3, #8
	mul r2, r0
	add r4, r3, r2
	ldr r0, [r4, #0x1c]
	ldr r2, [r4, #0x20]
	lsl r0, r0, #4
	lsl r2, r2, #4
	ldr r3, [r4, #0xc]
	asr r0, r0, #0x10
	asr r2, r2, #0x10
	cmp r3, #3
	bne _0220F95A
	ldr r0, _0220FA14 ; =0xDFFFFFFF
	and r0, r1
	str r0, [r5, #4]
	b _0220F9DE
_0220F95A:
	mov r1, #0
	ldrsh r1, [r5, r1]
	sub r0, r1, r0
	bpl _0220F964
	neg r0, r0
_0220F964:
	cmp r0, #8
	bgt _0220F976
	mov r0, #2
	ldrsh r0, [r5, r0]
	sub r0, r0, r2
	bpl _0220F972
	neg r0, r0
_0220F972:
	cmp r0, #8
	ble _0220F9DE
_0220F976:
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_0220D6B0
	ldr r1, [r4, #0x10]
	ldr r2, [r4, #0x14]
	add r0, r4, #0
	bl ov96_0220D8C4
	lsl r0, r0, #0x1f
	ldr r2, [r4, #0x40]
	ldr r1, _0220FA14 ; =0xDFFFFFFF
	lsr r0, r0, #2
	and r1, r2
	orr r0, r1
	str r0, [r4, #0x40]
	b _0220F9DE
_0220F998:
	lsl r0, r1, #2
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0220F9D6
	add r0, r5, #0
	lsr r1, r1, #0x1e
	mul r2, r1
	add r0, #8
	add r4, r0, r2
	mov r1, #0
	mov r2, #2
	ldrsh r1, [r5, r1]
	ldrsh r2, [r5, r2]
	bl ov96_0220DAA0
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	ldr r0, [r4, #0xc]
	cmp r0, #2
	bne _0220F9D6
	ldr r0, [r5, #4]
	lsr r1, r0, #0x1e
	cmp r2, r1
	bne _0220F9D6
	lsl r0, r0, #3
	lsr r0, r0, #0x13
	cmp r0, #5
	bhi _0220F9D6
	add r0, r4, #0
	bl ov96_0220D630
_0220F9D6:
	ldr r1, [r5, #4]
	ldr r0, _0220FA14 ; =0xDFFFFFFF
	and r0, r1
	str r0, [r5, #4]
_0220F9DE:
	add r4, r5, #0
	mov r6, #0
	add r4, #8
_0220F9E4:
	add r0, r4, #0
	add r1, r7, #0
	bl ov96_0220D9A4
	add r6, r6, #1
	add r4, #0x48
	cmp r6, #3
	blt _0220F9E4
	ldr r0, [sp]
	add r5, #0xe4
	add r0, r0, #1
	str r0, [sp]
	cmp r0, #4
	bge _0220FA02
	b _0220F8DE
_0220FA02:
	add r0, r7, #0
	bl ov96_0220F710
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220FA0C: .word 0xF7FFFFFF
_0220FA10: .word 0x3FFFFFFF
_0220FA14: .word 0xDFFFFFFF
	thumb_func_end ov96_0220F8C8


	thumb_func_start ov96_0220FA18
ov96_0220FA18: ; 0x0220FA18
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp, #4]
	add r0, r1, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, #0x1c
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	mov r4, #0
	ldr r1, [r0, #0x1c]
	ldr r0, _0220FB84 ; =0x3FFFFFFF
	add r2, r1, #0
	and r2, r0
	lsr r0, r1, #0x1e
	add r0, r0, #1
	lsl r0, r0, #0x1e
	orr r2, r0
	ldr r0, [sp, #8]
	mov r1, #0x7f
	add r6, r0, #0
	str r2, [r0, #0x1c]
	ldr r0, [r0, #0x20]
	add r6, #0x20
	bic r0, r1
	lsr r1, r2, #0x1e
	add r3, r1, #0
	mov r2, #0xe4
	mul r3, r2
	ldr r1, [sp, #4]
	add r2, #0x8c
	add r1, r1, r3
	ldr r1, [r1, r2]
	add r7, r4, #0
	lsl r1, r1, #0xe
	lsr r2, r1, #0x10
	mov r1, #0x7f
	and r2, r1
	and r1, r2
	add r2, r0, #0
	orr r2, r1
	ldr r1, _0220FB88 ; =0x8007FFFF
	ldr r0, [sp, #8]
	and r2, r1
	str r2, [r0, #0x20]
	ldr r2, [r0, #0x1c]
	lsl r0, r1, #0x18
	and r2, r0
	ldr r0, [sp, #8]
	str r2, [r0, #0x1c]
	ldr r2, [r0, #0x20]
	asr r0, r1, #0xc
	add r1, r2, #0
	and r1, r0
	ldr r0, [sp, #8]
	str r1, [r0, #0x20]
	ldr r0, [sp, #4]
	add r0, #0x98
	str r0, [sp, #4]
_0220FA98:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0xe4
	add r2, r5, #0
	mul r2, r0
	ldr r0, [sp, #4]
	add r3, sp, #0x14
	add r2, r0, r2
	mov r0, #0x48
	mul r0, r1
	add r5, r2, r0
	add r0, sp, #0x10
	str r0, [sp]
	ldr r1, [r5, #0x1c]
	ldr r2, [r5, #0x20]
	lsl r1, r1, #4
	lsl r2, r2, #4
	ldr r0, [r5, #4]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	bl ov96_021EB06C
	ldr r1, [sp, #0x14]
	cmp r1, #0xff
	ble _0220FADC
	mov r1, #0xff
	b _0220FAE2
_0220FADC:
	cmp r1, #0
	bge _0220FAE2
	mov r1, #0
_0220FAE2:
	ldr r0, [sp, #8]
	add r0, r0, r4
	strb r1, [r0, #4]
	ldr r1, [sp, #0x10]
	cmp r1, #0xff
	ble _0220FAF2
	mov r1, #0xff
	b _0220FAF8
_0220FAF2:
	cmp r1, #0
	bge _0220FAF8
	mov r1, #0
_0220FAF8:
	strb r1, [r0, #0x10]
	ldr r0, [r5, #0x40]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x18
	beq _0220FB30
	ldr r2, [r6]
	ldr r0, _0220FB88 ; =0x8007FFFF
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #1
	mov r2, #1
	lsl r2, r4
	lsr r0, r0, #0x14
	orr r0, r2
	lsl r0, r0, #0x14
	lsr r0, r0, #1
	orr r0, r1
	str r0, [r6]
	ldr r1, [r5, #0x40]
	ldr r0, _0220FB8C ; =0xFFFF00FF
	and r0, r1
	lsl r1, r1, #0x10
	lsr r1, r1, #0x18
	sub r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x10
	orr r0, r1
	str r0, [r5, #0x40]
_0220FB30:
	ldr r0, [r5, #0xc]
	cmp r0, #3
	bne _0220FB50
	ldr r2, [r6]
	ldr r0, _0220FB90 ; =0xFFF8007F
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #0xd
	mov r2, #1
	lsl r2, r4
	lsr r0, r0, #0x14
	orr r0, r2
	lsl r0, r0, #0x14
	lsr r0, r0, #0xd
	orr r0, r1
	str r0, [r6]
_0220FB50:
	ldr r0, [sp, #0xc]
	add r4, r4, #1
	ldr r2, [r0]
	mov r0, #0xff
	lsl r0, r0, #0x18
	add r1, r2, #0
	and r1, r0
	lsl r0, r2, #8
	ldr r2, [r5, #0x40]
	lsr r0, r0, #8
	lsl r2, r2, #8
	lsr r2, r2, #0x1c
	sub r2, r2, #1
	lsl r2, r7
	add r2, r0, r2
	ldr r0, _0220FB94 ; =0x00FFFFFF
	add r7, r7, #2
	and r0, r2
	orr r1, r0
	ldr r0, [sp, #0xc]
	cmp r4, #0xc
	str r1, [r0]
	blt _0220FA98
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220FB84: .word 0x3FFFFFFF
_0220FB88: .word 0x8007FFFF
_0220FB8C: .word 0xFFFF00FF
_0220FB90: .word 0xFFF8007F
_0220FB94: .word 0x00FFFFFF
	thumb_func_end ov96_0220FA18


	thumb_func_start ov96_0220FB98
ov96_0220FB98: ; 0x0220FB98
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r1, [r5, #4]
	mov r0, #0x20
	orr r0, r1
	str r0, [r5, #4]
	mov r0, #0x80
	strh r0, [r5]
	mov r0, #0
	strh r0, [r5, #2]
	strh r0, [r5]
	ldr r1, [r5, #4]
	mov r0, #0x1c
	bic r1, r0
	mov r0, #4
	orr r0, r1
	str r0, [r5, #4]
	strb r2, [r5, #8]
	bl MTRandom
	mov r1, #0xf
	bl _u32_div_f
	strb r1, [r5, #9]
	ldr r1, [r5, #4]
	ldr r0, _0220FBD8 ; =0xFFFFC03F
	and r0, r1
	str r0, [r5, #4]
	strb r4, [r5, #0xa]
	pop {r3, r4, r5, pc}
	nop
_0220FBD8: .word 0xFFFFC03F
	thumb_func_end ov96_0220FB98


	thumb_func_start ov96_0220FBDC
ov96_0220FBDC: ; 0x0220FBDC
	ldr r2, [r0, #4]
	mov r1, #0x20
	bic r2, r1
	mov r1, #0x1c
	bic r2, r1
	str r2, [r0, #4]
	bx lr
	.balign 4, 0
	thumb_func_end ov96_0220FBDC


	thumb_func_start ov96_0220FBEC
ov96_0220FBEC: ; 0x0220FBEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	str r1, [sp, #8]
	mov r1, #2
	ldrsh r1, [r0, r1]
	str r0, [sp, #4]
	mov r0, #0x12
	lsl r0, r0, #4
	str r2, [sp, #0xc]
	cmp r1, r0
	bge _0220FC08
	add sp, #0x2c
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_0220FC08:
	sub r0, r1, r0
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	mov r4, #0
	str r0, [sp, #0x10]
_0220FC12:
	mov r1, #0
	add r0, sp, #0x20
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r6, r1, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	mov r1, #0xe4
	str r0, [sp, #0x14]
	mul r1, r0
	ldr r0, [sp, #8]
	add r1, r0, r1
	mov r0, #0x48
	add r1, #8
	mul r0, r6
	add r5, r1, r0
	ldr r0, [r5, #0xc]
	cmp r0, #1
	bne _0220FCA2
	add r0, sp, #0x18
	str r0, [sp]
	ldr r1, [r5, #0x1c]
	ldr r2, [r5, #0x20]
	ldr r0, [r5, #4]
	asr r1, r1, #0xc
	asr r2, r2, #0xc
	add r3, sp, #0x1c
	bl ov96_021EB06C
	ldr r1, [sp, #4]
	mov r0, #0
	ldrsh r0, [r1, r0]
	ldr r2, [sp, #0x1c]
	ldr r1, [sp, #0x18]
	sub r2, r2, r0
	ldr r0, [sp, #0x10]
	str r2, [sp, #0x20]
	sub r1, r1, r0
	lsl r0, r2, #0xc
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	lsl r0, r1, #0xc
	str r0, [sp, #0x24]
	add r0, sp, #0x20
	bl VEC_Mag
	add r7, r0, #0
	ldr r0, [r5, #4]
	bl ov96_021EAF8C
	add r0, #0xe
	lsl r0, r0, #0xc
	cmp r7, r0
	bgt _0220FCA2
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0xc]
	strb r1, [r0, #4]
	strb r6, [r0, #5]
	ldr r1, [sp, #0x1c]
	strh r1, [r0]
	ldr r1, [sp, #0x18]
	add sp, #0x2c
	strh r1, [r0, #2]
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0220FCA2:
	add r4, r4, #1
	cmp r4, #0xc
	blt _0220FC12
	mov r0, #0
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220FBEC


	thumb_func_start ov96_0220FCB0
ov96_0220FCB0: ; 0x0220FCB0
	push {r4, r5, r6, r7}
	mov r5, #2
	ldrsh r5, [r0, r5]
	mov r2, #1
	sub r6, r1, #1
	add r3, r2, #0
	mov r4, #0
	cmp r5, r6
	bne _0220FCD6
	ldrsh r6, [r0, r4]
	add r7, r2, #0
	cmp r6, #8
	blt _0220FCD0
	cmp r6, #0x17
	bgt _0220FCD0
	add r7, r4, #0
_0220FCD0:
	cmp r7, #0
	beq _0220FCD6
	mov r4, #1
_0220FCD6:
	cmp r4, #0
	bne _0220FCFC
	sub r4, r1, #2
	mov r6, #0
	cmp r5, r4
	bne _0220FCF6
	ldrsh r4, [r0, r6]
	mov r7, #1
	cmp r4, #5
	blt _0220FCF0
	cmp r4, #0x1a
	bgt _0220FCF0
	add r7, r6, #0
_0220FCF0:
	cmp r7, #0
	beq _0220FCF6
	mov r6, #1
_0220FCF6:
	cmp r6, #0
	bne _0220FCFC
	mov r3, #0
_0220FCFC:
	cmp r3, #0
	bne _0220FD22
	sub r1, r1, #3
	mov r3, #0
	cmp r5, r1
	bne _0220FD1C
	ldrsh r0, [r0, r3]
	mov r1, #1
	cmp r0, #2
	blt _0220FD16
	cmp r0, #0x1d
	bgt _0220FD16
	add r1, r3, #0
_0220FD16:
	cmp r1, #0
	beq _0220FD1C
	mov r3, #1
_0220FD1C:
	cmp r3, #0
	bne _0220FD22
	mov r2, #0
_0220FD22:
	add r0, r2, #0
	pop {r4, r5, r6, r7}
	bx lr
	thumb_func_end ov96_0220FCB0


	thumb_func_start ov96_0220FD28
ov96_0220FD28: ; 0x0220FD28
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r4, r2, #0
	mov r0, #0
	add r6, r1, #0
	ldrsh r1, [r4, r0]
	asr r0, r1, #2
	lsr r0, r0, #0x1d
	add r0, r1, r0
	asr r0, r0, #3
	add r1, sp, #4
	strh r0, [r1]
	mov r0, #2
	ldrsh r2, [r4, r0]
	asr r3, r2, #2
	lsr r3, r3, #0x1d
	add r3, r2, r3
	asr r2, r3, #3
	strh r2, [r1, #2]
	ldrsh r0, [r1, r0]
	cmp r0, #9
	bge _0220FD7C
	ldr r1, [r5, #4]
	mov r0, #0x1c
	bic r1, r0
	mov r0, #0xc
	orr r0, r1
	str r0, [r5, #4]
	add r0, sp, #4
	mov r1, #9
	bl ov96_0220FCB0
	cmp r0, #0
	beq _0220FDDC
	ldr r1, [r5, #4]
	mov r0, #0x1c
	bic r1, r0
	mov r0, #0x10
	orr r0, r1
	str r0, [r5, #4]
	b _0220FDDC
_0220FD7C:
	cmp r0, #0xf
	bge _0220FDA6
	ldr r1, [r5, #4]
	mov r0, #0x1c
	bic r1, r0
	mov r0, #0x10
	orr r0, r1
	str r0, [r5, #4]
	add r0, sp, #4
	mov r1, #0xf
	bl ov96_0220FCB0
	cmp r0, #0
	beq _0220FDDC
	ldr r1, [r5, #4]
	mov r0, #0x1c
	bic r1, r0
	mov r0, #0x14
	orr r0, r1
	str r0, [r5, #4]
	b _0220FDDC
_0220FDA6:
	cmp r0, #0x14
	bge _0220FDD0
	ldr r2, [r5, #4]
	mov r0, #0x1c
	bic r2, r0
	mov r1, #0x14
	add r0, r2, #0
	orr r0, r1
	str r0, [r5, #4]
	add r0, sp, #4
	bl ov96_0220FCB0
	cmp r0, #0
	beq _0220FDDC
	ldr r1, [r5, #4]
	mov r0, #0x1c
	bic r1, r0
	mov r0, #0x18
	orr r0, r1
	str r0, [r5, #4]
	b _0220FDDC
_0220FDD0:
	ldr r1, [r5, #4]
	mov r0, #0x1c
	bic r1, r0
	mov r0, #0x18
	orr r0, r1
	str r0, [r5, #4]
_0220FDDC:
	ldrb r1, [r4, #4]
	mov r0, #0xe4
	mul r0, r1
	add r6, r6, r0
	add r0, r5, #0
	ldr r7, [r6, #8]
	bl ov96_0220F3BC
	add r1, r6, #0
	add r1, #0xe0
	ldr r1, [r1]
	lsl r1, r1, #0xe
	lsr r1, r1, #0x10
	add r1, r1, r0
	cmp r1, #0xc8
	ble _0220FDFE
	mov r1, #0xc8
_0220FDFE:
	add r0, r6, #0
	add r0, #0xe0
	ldr r2, [r0]
	ldr r0, _0220FE34 ; =0xFFFC0003
	lsl r1, r1, #0x10
	and r0, r2
	lsr r1, r1, #0xe
	orr r0, r1
	add r6, #0xe0
	str r0, [r6]
	ldr r0, [r5, #4]
	mov r1, #3
	bic r0, r1
	ldrb r1, [r4, #4]
	mov r3, #3
	and r1, r3
	orr r0, r1
	str r0, [r5, #4]
	mov r0, #1
	str r0, [sp]
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	add r0, r7, #0
	bl ov96_021E8228
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220FE34: .word 0xFFFC0003
	thumb_func_end ov96_0220FD28


	thumb_func_start ov96_0220FE38
ov96_0220FE38: ; 0x0220FE38
	push {r4, r5, r6, lr}
	sub sp, #8
	add r4, r0, #0
	add r6, r2, #0
	ldr r2, [r4, #4]
	add r5, r1, #0
	lsl r1, r2, #0x1a
	lsr r1, r1, #0x1f
	bne _0220FE4C
	b _0220FF4E
_0220FE4C:
	lsl r1, r2, #0x1b
	lsr r1, r1, #0x1d
	cmp r1, #6
	bhi _0220FEEC
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0220FE60: ; jump table
	.short _0220FEEC - _0220FE60 - 2 ; case 0
	.short _0220FE6E - _0220FE60 - 2 ; case 1
	.short _0220FEB6 - _0220FE60 - 2 ; case 2
	.short _0220FECC - _0220FE60 - 2 ; case 3
	.short _0220FECC - _0220FE60 - 2 ; case 4
	.short _0220FECC - _0220FE60 - 2 ; case 5
	.short _0220FECC - _0220FE60 - 2 ; case 6
_0220FE6E:
	add r1, r6, #0
	add r2, sp, #0
	bl ov96_0220FBEC
	cmp r0, #0
	beq _0220FE86
	add r0, r4, #0
	add r1, r6, #0
	add r2, sp, #0
	bl ov96_0220FD28
	b _0220FEF0
_0220FE86:
	mov r0, #2
	ldrsh r2, [r4, r0]
	mov r1, #0x1e
	lsl r1, r1, #4
	cmp r2, r1
	blt _0220FEA4
	mov r0, #0
	strh r0, [r4, #2]
	ldr r1, [r4, #4]
	mov r0, #0x1c
	bic r1, r0
	mov r0, #8
	orr r0, r1
	str r0, [r4, #4]
	b _0220FEF0
_0220FEA4:
	ldrb r1, [r4, #0xa]
	add r1, r2, r1
	strh r1, [r4, #2]
	ldrsh r0, [r4, r0]
	ldrb r1, [r4, #9]
	bl ov96_0220E6DC
	strh r0, [r4]
	b _0220FEF0
_0220FEB6:
	mov r1, #2
	ldrsh r3, [r4, r1]
	ldrb r2, [r4, #0xa]
	add r2, r3, r2
	strh r2, [r4, #2]
	ldrsh r1, [r4, r1]
	cmp r1, #0x30
	blt _0220FEF0
	bl ov96_0220FBDC
	b _0220FEF0
_0220FECC:
	ldr r1, _0220FF54 ; =0xFFFFC03F
	and r1, r2
	lsl r2, r2, #0x12
	lsr r2, r2, #0x18
	add r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x12
	orr r1, r2
	str r1, [r4, #4]
	lsl r1, r1, #0x12
	lsr r1, r1, #0x18
	cmp r1, #0x14
	blo _0220FEF0
	bl ov96_0220FBDC
	b _0220FEF0
_0220FEEC:
	bl GF_AssertFail
_0220FEF0:
	ldrh r0, [r5]
	mov r1, #0x7f
	bic r0, r1
	mov r1, #2
	ldrsh r1, [r4, r1]
	lsl r2, r1, #1
	asr r1, r2, #2
	lsr r1, r1, #0x1d
	add r1, r2, r1
	lsl r1, r1, #0xd
	lsr r2, r1, #0x10
	mov r1, #0x7f
	and r1, r2
	orr r0, r1
	strh r0, [r5]
	ldrh r1, [r5]
	ldr r0, _0220FF58 ; =0xFFFFF87F
	and r1, r0
	ldrb r0, [r4, #9]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x15
	orr r0, r1
	strh r0, [r5]
	ldrh r1, [r5]
	ldr r0, _0220FF5C ; =0xFFFFC7FF
	and r0, r1
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x1d
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	lsl r1, r1, #0x1d
	lsr r1, r1, #0x12
	orr r0, r1
	strh r0, [r5]
	ldrh r1, [r5]
	ldr r0, _0220FF60 ; =0xFFFF3FFF
	and r0, r1
	ldr r1, [r4, #4]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x10
	orr r0, r1
	strh r0, [r5]
_0220FF4E:
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_0220FF54: .word 0xFFFFC03F
_0220FF58: .word 0xFFFFF87F
_0220FF5C: .word 0xFFFFC7FF
_0220FF60: .word 0xFFFF3FFF
	thumb_func_end ov96_0220FE38

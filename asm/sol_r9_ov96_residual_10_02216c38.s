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




	thumb_func_start ov96_02216C38
ov96_02216C38: ; 0x02216C38
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa8
	str r0, [sp, #4]
	str r2, [sp, #0xc]
	mov r0, #0
	str r1, [sp, #8]
	add r2, sp, #0x88
	add r1, r0, #0
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [sp, #0xc]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x58]
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x1c]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1f
	beq _02216C74
	ldr r1, _02216F60 ; =0x000003B9
	ldr r0, [sp, #4]
	ldrb r0, [r0, r1]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	bne _02216C74
	ldr r0, _02216F64 ; =0x000008D4
	bl PlaySE
_02216C74:
	ldr r0, _02216F60 ; =0x000003B9
	ldr r1, [sp, #4]
	mov r6, #0
	ldrb r1, [r1, r0]
	mov r2, #1
	ldr r5, [sp, #8]
	bic r1, r2
	ldr r2, [sp, #8]
	str r6, [sp, #0x3c]
	ldr r2, [r2, #0x1c]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x1f
	lsl r2, r2, #0x18
	lsr r3, r2, #0x18
	mov r2, #1
	and r2, r3
	orr r2, r1
	ldr r1, [sp, #4]
	strb r2, [r1, r0]
	mov r0, #0xff
	add r4, r1, #0
	add r4, #0x10
	str r0, [sp, #0x68]
	str r0, [sp, #0x6c]
	str r0, [sp, #0x70]
_02216CA6:
	ldr r0, [sp, #0xc]
	bl PokeathlonCourse_GetParticipantCount
	cmp r0, r6
	bgt _02216CB4
	mov r7, #1
	b _02216CB6
_02216CB4:
	mov r7, #0
_02216CB6:
	ldr r0, [sp, #0xc]
	bl ov96_021E5F24
	cmp r0, #0
	bne _02216CC4
	mov r1, #1
	b _02216CC6
_02216CC4:
	mov r1, #0
_02216CC6:
	mov r0, #0
	str r0, [sp, #0x48]
	cmp r1, #0
	beq _02216CD6
	cmp r7, #0
	beq _02216CD6
	mov r0, #1
	str r0, [sp, #0x48]
_02216CD6:
	cmp r5, #0
	bne _02216CDE
	bl GF_AssertFail
_02216CDE:
	cmp r4, #0
	bne _02216CE6
	bl GF_AssertFail
_02216CE6:
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1e
	str r0, [sp, #0x34]
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _02216F68 ; =0xFFFF3FFF
	and r1, r0
	ldr r0, [sp, #0x34]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x10
	orr r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x18
	lsr r1, r0, #0x1e
	ldr r0, [sp, #0x3c]
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x58]
	ldr r1, [sp, #0x30]
	ldr r0, [r0, #0x1c]
	bl ov96_021EAA04
	str r0, [sp, #0x54]
	str r0, [r4]
	cmp r0, #0
	bne _02216D2C
	bl GF_AssertFail
_02216D2C:
	ldr r0, [sp, #0xc]
	bl ov96_021E5F24
	cmp r6, r0
	bne _02216D9A
	ldrb r0, [r5, #4]
	mov r1, #3
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1e
	str r0, [sp, #0x38]
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x1c]
	lsr r7, r0, #8
	ldr r0, [sp, #0x38]
	add r0, r0, #2
	bl _s32_div_f
	ldr r0, [sp, #0x3c]
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x17
	add r1, r7, #0
	lsr r1, r0
	mov r0, #3
	and r0, r1
	cmp r0, #1
	bne _02216D68
	mov r0, #1
	str r0, [sp, #0x28]
	b _02216D6C
_02216D68:
	mov r0, #0
	str r0, [sp, #0x28]
_02216D6C:
	ldr r0, [sp, #0x38]
	mov r1, #3
	add r0, r0, #1
	bl _s32_div_f
	ldr r0, [sp, #0x3c]
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x17
	add r1, r7, #0
	lsr r1, r0
	mov r0, #3
	and r0, r1
	cmp r0, #1
	bne _02216D8E
	mov r2, #1
	b _02216D90
_02216D8E:
	mov r2, #0
_02216D90:
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x28]
	ldr r0, [r0]
	bl ov96_02219770
_02216D9A:
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	lsl r0, r0, #7
	lsr r0, r0, #0x1e
	beq _02216E82
	ldrb r0, [r5, #2]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1e
	beq _02216E82
	ldrb r1, [r5, #4]
	lsl r1, r1, #0x1a
	lsr r7, r1, #0x1e
	mov r1, #0
	str r1, [sp, #0x50]
	cmp r7, r6
	bgt _02216DBE
	sub r7, r7, #1
_02216DBE:
	cmp r0, #1
	bne _02216DE8
	ldr r0, [sp, #0xc]
	bl ov96_021E5F24
	cmp r7, r0
	bne _02216DDA
	ldr r1, [sp, #0x58]
	ldr r0, _02216F6C ; =0x000007F8
	mov r2, #0xa
	add r0, r1, r0
	mov r1, #4
	bl ov96_02215884
_02216DDA:
	mov r0, #1
	str r0, [sp, #0x50]
	mov r0, #0x8d
	lsl r0, r0, #4
	bl PlaySE
	b _02216E0E
_02216DE8:
	cmp r0, #2
	bne _02216E0E
	ldr r0, [sp, #0xc]
	bl ov96_021E5F24
	cmp r7, r0
	bne _02216E04
	ldr r1, [sp, #0x58]
	ldr r0, _02216F6C ; =0x000007F8
	mov r2, #0xf
	add r0, r1, r0
	mov r1, #0xa
	bl ov96_02215884
_02216E04:
	mov r0, #1
	str r0, [sp, #0x50]
	ldr r0, _02216F70 ; =0x000008D2
	bl PlaySE
_02216E0E:
	ldr r0, [sp, #0x50]
	cmp r0, #0
	beq _02216E82
	mov r0, #6
	mul r0, r7
	ldr r1, [sp, #8]
	ldrb r7, [r5]
	add r1, r1, r0
	ldrb r2, [r1, #1]
	ldr r1, [sp, #8]
	ldrb r3, [r5, #1]
	ldrb r0, [r1, r0]
	str r0, [sp, #0x74]
	sub r1, r7, r0
	bpl _02216E2E
	neg r1, r1
_02216E2E:
	lsr r0, r1, #0x1f
	str r0, [sp, #0x64]
	add r0, r1, r0
	str r0, [sp, #0x64]
	lsl r0, r0, #0xf
	asr r0, r0, #0x10
	str r0, [sp, #0x44]
	sub r1, r3, r2
	bpl _02216E42
	neg r1, r1
_02216E42:
	lsr r0, r1, #0x1f
	add r0, r1, r0
	lsl r0, r0, #0xf
	asr r0, r0, #0x10
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x74]
	cmp r7, r0
	ble _02216E54
	add r7, r0, #0
_02216E54:
	ldr r0, [sp, #0x44]
	add r0, r0, r7
	lsl r0, r0, #0x10
	asr r1, r0, #0x10
	cmp r3, r2
	ble _02216E62
	add r3, r2, #0
_02216E62:
	ldr r2, [sp, #0x40]
	ldr r0, [r4, #0x14]
	add r2, r2, r3
	lsl r2, r2, #0x10
	mov r3, #0x1e
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r4, #0x14]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r0, [r4, #0x14]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
_02216E82:
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _02216F74 ; =0xFE7FFFFF
	and r0, r1
	ldrb r1, [r5, #2]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x1e
	lsr r1, r1, #7
	orr r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _02216F78 ; =0xFFFCFFFF
	and r0, r1
	ldrb r1, [r5, #4]
	lsl r1, r1, #0x1a
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x1e
	lsr r1, r1, #0xe
	orr r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	ldrb r1, [r5, #5]
	ldr r0, [sp, #0x54]
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x1e
	add r1, r1, #1
	bl ov96_021EAC0C
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r1, r0, #0x1c
	cmp r1, #4
	bne _02216EF0
	ldr r0, [r4, #0x18]
	cmp r0, #4
	beq _02216EF0
	ldr r0, [sp, #0x58]
	ldr r3, [sp, #0x34]
	add r7, r4, #0
	ldr r0, [r0, #0x1c]
	ldr r1, [sp, #0x30]
	add r7, #0x3c
	lsl r3, r3, #6
	mov r2, #1
	add r3, r7, r3
	bl ov96_021EAF60
	b _02216F10
_02216EF0:
	ldr r0, [r4, #0x18]
	cmp r0, #4
	bne _02216F10
	cmp r1, #4
	beq _02216F10
	ldr r0, [sp, #0x58]
	ldr r3, [sp, #0x34]
	add r7, r4, #0
	ldr r0, [r0, #0x1c]
	ldr r1, [sp, #0x30]
	add r7, #0x1c
	lsl r3, r3, #6
	mov r2, #1
	add r3, r7, r3
	bl ov96_021EAF60
_02216F10:
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r1, r0, #0x1c
	cmp r1, #5
	bne _02216F40
	ldr r0, [r4, #0x18]
	cmp r0, #5
	beq _02216F40
	ldr r0, [sp, #0xc]
	bl ov96_021E5F24
	cmp r6, r0
	bne _02216F36
	mov r1, #1
	ldr r0, _02216F7C ; =0x000008D1
	lsl r1, r1, #8
	bl PlaySE_SetPitch
	b _02216F8C
_02216F36:
	ldr r0, _02216F80 ; =0x000008D5
	mov r1, #0x40
	bl sub_02006118
	b _02216F8C
_02216F40:
	cmp r1, #0xc
	bne _02216F8C
	ldr r0, [r4, #0x18]
	cmp r0, #0xc
	beq _02216F8C
	lsl r1, r6, #0x18
	ldr r0, [sp, #0xc]
	ldr r2, [sp, #0x34]
	lsr r1, r1, #0x18
	bl ov96_0221935C
	ldrb r0, [r0, #0x18]
	cmp r0, #0
	beq _02216F8C
	ldr r0, _02216F84 ; =0x000008D3
	b _02216F88
	.balign 4, 0
_02216F60: .word 0x000003B9
_02216F64: .word 0x000008D4
_02216F68: .word 0xFFFF3FFF
_02216F6C: .word 0x000007F8
_02216F70: .word 0x000008D2
_02216F74: .word 0xFE7FFFFF
_02216F78: .word 0xFFFCFFFF
_02216F7C: .word 0x000008D1
_02216F80: .word 0x000008D5
_02216F84: .word 0x000008D3
_02216F88:
	bl PlaySE
_02216F8C:
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r1, r0, #0x1c
	cmp r1, #6
	bne _02216FB8
	ldr r0, [r4, #0x18]
	cmp r0, #6
	beq _02216FB8
	ldrb r1, [r5, #5]
	ldr r0, [r4, #4]
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x1e
	add r1, #0xb
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	bl ManagedSprite_SetAnimNoRestart
	ldr r0, [r4, #4]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	b _02216FE6
_02216FB8:
	cmp r1, #6
	beq _02216FC2
	ldr r0, [r4, #0x18]
	cmp r0, #6
	beq _02216FCC
_02216FC2:
	cmp r1, #7
	bne _02216FE6
	ldr r0, [r4, #0x18]
	cmp r0, #5
	bne _02216FE6
_02216FCC:
	ldrb r1, [r5, #5]
	ldr r0, [r4, #4]
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x1e
	add r1, #0xf
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	bl ManagedSprite_SetAnim
	ldr r0, [r4, #4]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
_02216FE6:
	ldr r0, [r4, #4]
	bl ManagedSprite_IsAnimated
	cmp r0, #1
	bne _02216FFE
	ldrb r1, [r5]
	mov r3, #0x1e
	ldrb r2, [r5, #1]
	ldr r0, [r4, #4]
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
_02216FFE:
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	cmp r0, #6
	bne _02217010
	ldr r0, [sp, #0x54]
	mov r1, #0xc
	bl ov96_021EAC5C
_02217010:
	ldrb r1, [r5]
	cmp r1, #0
	beq _02217024
	cmp r1, #0xff
	beq _02217024
	ldrb r3, [r5, #1]
	cmp r3, #0
	beq _02217024
	cmp r3, #0xff
	bne _0221703E
_02217024:
	ldr r0, [sp, #0x54]
	mov r1, #0
	bl ov96_021EAB38
	ldr r0, [r4, #4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #8]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _022170DE
_0221703E:
	ldrb r0, [r5, #5]
	lsl r0, r0, #0x19
	lsr r0, r0, #0x1e
	beq _0221704C
	mov r0, #1
	str r0, [sp, #0x24]
	b _02217050
_0221704C:
	mov r0, #0
	str r0, [sp, #0x24]
_02217050:
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	cmp r0, #3
	bne _02217060
	mov r0, #1
	str r0, [sp, #0x20]
	b _02217064
_02217060:
	mov r0, #0
	str r0, [sp, #0x20]
_02217064:
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x1c]
	lsr r2, r0, #8
	ldr r0, [sp, #0x30]
	lsl r0, r0, #1
	lsr r2, r0
	mov r0, #3
	and r0, r2
	ldrb r2, [r5, #2]
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	lsl r2, r2, #0x1a
	lsr r2, r2, #0x1a
	sub r2, r3, r2
	sub r2, #0x18
	lsl r2, r2, #0x10
	mov r3, #0x1e
	ldr r0, [r4, #8]
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [sp, #0x20]
	cmp r0, #0
	bne _0221709C
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _022170A0
_0221709C:
	mov r7, #0
	b _022170CE
_022170A0:
	cmp r7, #2
	bne _022170C2
	ldr r0, [r4, #8]
	mov r1, #1
	bl ManagedSprite_SetAnimNoRestart
	mov r0, #0x89
	lsl r0, r0, #4
	bl IsSEPlaying
	cmp r0, #0
	bne _022170CE
	mov r0, #0x89
	lsl r0, r0, #4
	bl PlaySE
	b _022170CE
_022170C2:
	cmp r7, #1
	bne _022170CE
	ldr r0, [r4, #8]
	mov r1, #9
	bl ManagedSprite_SetAnimNoRestart
_022170CE:
	cmp r7, #0
	beq _022170D6
	mov r1, #1
	b _022170D8
_022170D6:
	mov r1, #0
_022170D8:
	ldr r0, [r4, #8]
	bl ManagedSprite_SetDrawFlag
_022170DE:
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r2, [sp, #4]
	ldr r3, [sp, #0xc]
	ldr r2, [r2]
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_02216AA4
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	cmp r0, #3
	bne _02217100
	mov r0, #1
	b _02217102
_02217100:
	mov r0, #0
_02217102:
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #1
	bne _02217174
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	lsl r0, r0, #0xb
	lsr r0, r0, #0x1f
	bne _02217174
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	mov r0, #2
	lsl r0, r0, #0x12
	orr r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	add r1, r4, #0
	add r1, #0xe1
	mov r0, #6
	strb r0, [r1]
	add r1, r4, #0
	mov r0, #1
	add r1, #0xdc
	lsl r0, r0, #0xc
	str r0, [r1]
	ldr r0, _02217468 ; =0x0000089E
	bl PlaySE
	ldr r0, [sp, #4]
	lsl r1, r6, #0x18
	ldr r0, [r0]
	ldr r2, [sp, #0x34]
	lsr r1, r1, #0x18
	mov r3, #1
	bl ov96_0221996C
	ldr r0, [sp, #0xc]
	bl ov96_021E5F24
	cmp r6, r0
	beq _02217160
	ldr r0, [sp, #0x48]
	cmp r0, #0
	beq _022171E0
_02217160:
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	mov r0, #2
	lsl r0, r0, #0x14
	orr r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	b _022171E0
_02217174:
	cmp r7, #0
	bne _022171E0
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	lsl r0, r0, #0xb
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _022171E0
	ldrb r1, [r5]
	mov r3, #0x1e
	ldrb r2, [r5, #1]
	ldr r0, [r4, #0x10]
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r4, #0x10]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x10]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r0, [sp, #0xc]
	bl ov96_021E5F24
	cmp r6, r0
	bne _022171B0
	mov r1, #1
	b _022171B2
_022171B0:
	mov r1, #0
_022171B2:
	ldr r0, _0221746C ; =0x000008B6
	bl ov96_022193CC
	ldr r0, [sp, #4]
	lsl r1, r6, #0x18
	ldr r0, [r0]
	ldr r2, [sp, #0x34]
	lsr r1, r1, #0x18
	mov r3, #0
	bl ov96_0221996C
	ldr r0, [sp, #0x54]
	mov r1, #1
	bl ov96_021EAB38
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _02217470 ; =0xFFF7FFFF
	and r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
_022171E0:
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _02217474 ; =0xFFEFFFFF
	mov r3, #1
	and r1, r0
	lsl r0, r7, #0x1f
	lsr r0, r0, #0xb
	orr r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	ldr r0, [sp, #0x54]
	bl ov96_021EB01C
	ldrb r3, [r5, #2]
	ldrb r2, [r5, #1]
	ldrb r1, [r5]
	lsl r3, r3, #0x1a
	lsr r3, r3, #0x1a
	sub r2, r2, r3
	ldr r0, [sp, #0x54]
	mov r3, #0
	bl ov96_021EB01C
	add r0, r4, #0
	add r0, #0xe4
	ldr r2, [r0]
	lsl r0, r2, #0xc
	lsr r0, r0, #0x1f
	beq _0221730A
	lsl r0, r2, #0xa
	lsr r0, r0, #0x1f
	beq _02217288
	ldr r0, [sp, #0x48]
	cmp r0, #0
	beq _0221725C
	mov r0, #6
	lsl r2, r2, #0x10
	lsr r2, r2, #0x1e
	lsl r2, r2, #0x18
	ldr r1, [sp, #0x58]
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	lsl r1, r6, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_02219940
	cmp r0, #0
	beq _02217288
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _02217478 ; =0xFFDFFFFF
	and r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	b _02217288
_0221725C:
	mov r0, #6
	lsl r2, r2, #0x10
	lsr r2, r2, #0x1e
	lsl r2, r2, #0x18
	ldr r1, [sp, #0x58]
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	lsl r1, r6, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_02219794
	cmp r0, #0
	beq _02217288
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, _02217478 ; =0xFFDFFFFF
	and r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
_02217288:
	mov r0, #0xe1
	ldrsb r0, [r4, r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0xe1
	strb r1, [r0]
	mov r0, #0xe1
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bgt _022172A6
	ldr r0, [sp, #0x54]
	mov r1, #0
	bl ov96_021EAB38
	b _022174AE
_022172A6:
	ldrb r0, [r5]
	str r0, [sp, #0x84]
	ldrb r0, [r5, #1]
	str r0, [sp, #0x80]
	add r0, r4, #0
	add r0, #0xdc
	ldr r1, [r0]
	ldr r0, _0221747C ; =0x0000019A
	sub r1, r1, r0
	add r0, r4, #0
	add r0, #0xdc
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xdc
	ldr r0, [r0]
	bl _fflt
	ldr r1, _02217480 ; =0x45800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, [sp, #0x54]
	add r2, r1, #0
	bl ov96_021EB10C
	add r0, sp, #0x80
	str r0, [sp]
	ldr r0, [sp, #0x54]
	ldr r1, [sp, #0x84]
	ldr r2, [sp, #0x80]
	add r3, sp, #0x84
	bl ov96_021EB06C
	ldr r0, [sp, #0x80]
	cmp r0, #0xa0
	bge _022172F0
	b _022174AE
_022172F0:
	mov r0, #0xe1
	ldrsb r1, [r4, r0]
	mov r0, #6
	ldrb r3, [r5, #1]
	sub r0, r0, r1
	lsl r2, r0, #2
	add r2, r3, r2
	ldrb r1, [r5]
	ldr r0, [sp, #0x54]
	mov r3, #1
	bl ov96_021EB01C
	b _022174AE
_0221730A:
	ldrb r1, [r5, #1]
	mov r0, #0xa0
	sub r1, r0, r1
	mov r0, #0xc
	mul r0, r1
	bl _fflt
	ldr r1, _02217480 ; =0x45800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, _02217484 ; =0x3F99999A
	bl _fsub
	ldrb r1, [r5, #4]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x2c]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	cmp r1, #5
	bne _02217392
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	lsl r1, r1, #0x18
	lsr r7, r1, #0x18
	bl _f2d
	str r0, [sp, #0x5c]
	add r0, r7, #0
	str r1, [sp, #0x1c]
	bl _dfltu
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _02217488 ; =0x9999999A
	ldr r1, _0221748C ; =0x3FB99999
	bl _dmul
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _02217488 ; =0x9999999A
	ldr r1, _02217490 ; =0x3FE99999
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x1c]
	bl _dmul
	bl _d2f
	str r0, [sp, #0x4c]
	cmp r7, #4
	bhs _02217392
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	ldr r1, [sp, #0x68]
	bic r0, r1
	add r1, r7, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	orr r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
_02217392:
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	cmp r0, #8
	bne _02217432
	lsl r1, r6, #0x18
	ldr r0, [sp, #0xc]
	ldr r2, [sp, #0x34]
	lsr r1, r1, #0x18
	bl ov96_0221935C
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bne _022173D2
	ldrb r0, [r0, #0x18]
	cmp r0, #0
	bne _022173CC
	ldr r0, [sp, #0xc]
	bl ov96_021E5F24
	cmp r6, r0
	bne _022173D2
	ldr r0, _02217494 ; =0x000005F3
	bl PlaySE
	b _022173D2
_022173CC:
	ldr r0, _02217498 ; =0x0000060A
	bl PlaySE
_022173D2:
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x2c]
	bl _f2d
	str r0, [sp, #0x60]
	add r0, r7, #0
	str r1, [sp, #0x14]
	bl _dfltu
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _02217488 ; =0x9999999A
	ldr r1, _0221748C ; =0x3FB99999
	bl _dmul
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _02217488 ; =0x9999999A
	ldr r1, _02217490 ; =0x3FE99999
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x60]
	ldr r1, [sp, #0x14]
	bl _dmul
	bl _d2f
	str r0, [sp, #0x2c]
	cmp r7, #5
	bhs _02217432
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	ldr r1, [sp, #0x6c]
	bic r0, r1
	add r1, r7, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	orr r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
_02217432:
	ldrb r0, [r5, #4]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	cmp r0, #8
	beq _0221749C
	cmp r0, #5
	beq _0221749C
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _022174A4
	ldr r0, [sp, #0x54]
	mov r1, #1
	bl ov96_02218510
	add r0, r4, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, [sp, #0x70]
	bic r1, r0
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	b _022174A4
	nop
_02217468: .word 0x0000089E
_0221746C: .word 0x000008B6
_02217470: .word 0xFFF7FFFF
_02217474: .word 0xFFEFFFFF
_02217478: .word 0xFFDFFFFF
_0221747C: .word 0x0000019A
_02217480: .word 0x45800000
_02217484: .word 0x3F99999A
_02217488: .word 0x9999999A
_0221748C: .word 0x3FB99999
_02217490: .word 0x3FE99999
_02217494: .word 0x000005F3
_02217498: .word 0x0000060A
_0221749C:
	ldr r0, [sp, #0x54]
	mov r1, #0
	bl ov96_02218510
_022174A4:
	ldr r0, [sp, #0x54]
	ldr r1, [sp, #0x4c]
	ldr r2, [sp, #0x2c]
	bl ov96_021EB10C
_022174AE:
	ldrb r0, [r5, #4]
	add r6, r6, #1
	add r5, r5, #6
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	str r0, [r4, #0x18]
	ldr r0, [sp, #0x3c]
	add r4, #0xe8
	add r0, r0, #3
	str r0, [sp, #0x3c]
	cmp r6, #4
	bge _022174CA
	bl _02216CA6
_022174CA:
	mov r6, #0
	add r4, r6, #0
	add r5, sp, #0x88
_022174D0:
	ldr r1, [sp, #8]
	ldr r0, [sp, #0x58]
	ldrb r1, [r1, #4]
	ldr r0, [r0, #0x1c]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1e
	add r1, r1, r4
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	ldr r1, [sp, #8]
	add r3, sp, #0x7c
	ldrb r1, [r1]
	add r7, r0, #0
	str r1, [sp, #0x7c]
	ldr r1, [sp, #8]
	ldrb r1, [r1, #1]
	str r1, [sp, #0x78]
	add r1, sp, #0x78
	str r1, [sp]
	ldr r1, [sp, #0x7c]
	ldr r2, [sp, #0x78]
	bl ov96_021EB06C
	ldr r0, [sp, #0x78]
	add r6, r6, #1
	strb r0, [r5]
	ldr r0, [sp, #8]
	str r7, [r5, #4]
	add r0, r0, #6
	str r0, [sp, #8]
	add r4, r4, #3
	add r5, #8
	cmp r6, #4
	blt _022174D0
	mov r0, #0
	str r0, [sp]
	ldr r3, _02217540 ; =ov96_02216C00
	add r0, sp, #0x88
	mov r1, #4
	mov r2, #8
	bl MATH_QSort
	mov r5, #0
	add r4, sp, #0x88
_0221752C:
	ldr r0, [r4, #4]
	add r1, r5, #7
	bl ov96_021EABA8
	add r5, r5, #1
	add r4, #8
	cmp r5, #4
	blt _0221752C
	add sp, #0xa8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02217540: .word ov96_02216C00
	thumb_func_end ov96_02216C38



	thumb_func_start ov96_02217544
ov96_02217544: ; 0x02217544
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	str r0, [sp, #8]
	ldr r0, [sp, #0x38]
	str r1, [sp, #0xc]
	str r0, [sp, #0x38]
	ldr r0, [sp, #8]
	str r2, [sp, #0x10]
	str r3, [r0]
	str r1, [r0, #4]
	add r1, r2, #0
	str r1, [r0, #8]
	mov r0, #3
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	mov r2, #0x80
	mov r3, #0x10
	bl ov96_022164EC
	ldr r1, [sp, #8]
	str r0, [r1, #0xc]
	mov r0, #0
	str r0, [sp, #0x1c]
	add r0, r1, #0
	add r0, #0x10
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0x14]
_02217584:
	ldr r0, [sp, #0x18]
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	ldr r0, [sp, #0x38]
	add r1, r6, #0
	bl ov96_021EAA04
	ldr r1, [sp, #8]
	mov r7, #0
	add r4, r1, #0
	add r5, r1, #0
	str r0, [r1]
	add r4, #0x1c
	add r5, #0x3c
_022175A0:
	lsl r1, r6, #0x18
	ldr r0, [sp, #0x38]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	bl ov96_021EAA20
	bl ov96_021E8BB0
	ldr r1, [sp, #0x14]
	add r2, r4, #0
	bl ov96_021E8BB4
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x20
	bl MI_CpuCopy8
	add r0, r5, #0
	mov r1, #0x10
	bl TintPalette_GrayScale
	add r7, r7, #1
	add r6, r6, #1
	add r4, #0x40
	add r5, #0x40
	cmp r7, #3
	blt _022175A0
	mov r0, #7
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r2, #0
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	add r3, r2, #0
	bl ov96_022164EC
	ldr r1, [sp, #8]
	str r0, [r1, #0x14]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #1
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	mov r2, #0
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	add r3, r2, #0
	bl ov96_022164EC
	ldr r1, [sp, #8]
	str r0, [r1, #8]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0xb
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r2, #0
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	add r3, r2, #0
	bl ov96_022164EC
	ldr r1, [sp, #8]
	str r0, [r1, #4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x15
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r2, #0
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	add r3, r2, #0
	bl ov96_022164EC
	ldr r1, [sp, #8]
	str r0, [r1, #0xc]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #8
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r2, #0
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	add r3, r2, #0
	bl ov96_022164EC
	ldr r1, [sp, #8]
	str r0, [r1, #0x10]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [sp, #8]
	add r0, #0xe8
	str r0, [sp, #8]
	ldr r0, [sp, #0x18]
	add r0, r0, #3
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #4
	bge _02217686
	b _02217584
_02217686:
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02217544



	thumb_func_start ov96_0221768C
ov96_0221768C: ; 0x0221768C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r4, r1, #0
	add r7, r0, #0
	add r0, r4, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	str r0, [sp, #8]
	add r0, r4, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #4]
	ldr r1, [sp, #8]
	add r0, r7, #0
	add r2, r4, #0
	bl ov96_02216C38
	ldr r1, [sp, #8]
	add r0, r4, #0
	ldr r1, [r1, #0x20]
	lsl r1, r1, #0xd
	lsr r1, r1, #0x10
	bl ov96_021E6454
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x20]
	lsl r0, r0, #0xd
	lsr r1, r0, #0x10
	ldr r0, _022177C4 ; =0x000001C2
	cmp r1, r0
	bne _022176D6
	ldr r0, _022177C8 ; =0x000006D7
	bl PlaySE
_022176D6:
	add r0, r4, #0
	bl ov96_021E5F24
	add r2, r0, #0
	mov r1, #6
	ldr r0, [sp, #8]
	mul r2, r1
	add r0, r0, r2
	ldrb r0, [r0, #5]
	lsl r0, r0, #0x1d
	lsr r4, r0, #0x1d
	cmp r4, #4
	bhi _0221771A
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022176FC: ; jump table
	.short _02217706 - _022176FC - 2 ; case 0
	.short _02217716 - _022176FC - 2 ; case 1
	.short _0221770E - _022176FC - 2 ; case 2
	.short _0221770A - _022176FC - 2 ; case 3
	.short _02217712 - _022176FC - 2 ; case 4
_02217706:
	mov r5, #2
	b _0221771E
_0221770A:
	mov r5, #3
	b _0221771E
_0221770E:
	mov r5, #4
	b _0221771E
_02217712:
	mov r5, #5
	b _0221771E
_02217716:
	add r5, r1, #0
	b _0221771E
_0221771A:
	bl GF_AssertFail
_0221771E:
	ldr r0, [r7, #0xc]
	add r1, r5, #0
	bl ManagedSprite_SetAnimNoRestart
	mov r0, #0xee
	lsl r0, r0, #2
	ldrb r0, [r7, r0]
	cmp r4, r0
	beq _02217746
	cmp r4, #2
	bne _0221773C
	ldr r0, _022177CC ; =0x0000089B
	bl PlaySE
	b _02217746
_0221773C:
	cmp r4, #4
	bne _02217746
	ldr r0, _022177D0 ; =0x0000089C
	bl PlaySE
_02217746:
	mov r0, #0xee
	lsl r0, r0, #2
	ldr r3, [sp, #8]
	strb r4, [r7, r0]
	mov r1, #0
	add r2, sp, #0xc
_02217752:
	strb r1, [r2, #1]
	ldrb r0, [r3, #3]
	add r1, r1, #1
	add r3, r3, #6
	strb r0, [r2]
	add r2, r2, #2
	cmp r1, #4
	blt _02217752
	mov r0, #0
	str r0, [sp]
	ldr r3, _022177D4 ; =ov96_02216C1C
	add r0, sp, #0xc
	mov r1, #4
	mov r2, #2
	bl MATH_QSort
	ldr r5, [sp, #8]
	mov r6, #0
	add r4, r7, #0
_02217778:
	mov r0, #0x3b
	lsl r0, r0, #4
	ldrb r2, [r5, #3]
	ldrh r0, [r4, r0]
	cmp r2, r0
	beq _02217790
	lsl r1, r6, #0x18
	ldr r0, [r7]
	lsr r1, r1, #0x18
	add r3, sp, #0xc
	bl ov96_0221966C
_02217790:
	ldrb r1, [r5, #3]
	mov r0, #0x3b
	lsl r0, r0, #4
	strh r1, [r4, r0]
	add r6, r6, #1
	add r4, r4, #2
	add r5, r5, #6
	cmp r6, #4
	blt _02217778
	ldr r0, [sp, #8]
	mov r1, #0x1e
	ldr r0, [r0, #0x20]
	lsl r0, r0, #0xd
	lsr r0, r0, #0x10
	bl _u32_div_f
	add r1, r0, #0
	mov r2, #6
	ldr r0, [sp, #4]
	lsl r2, r2, #6
	ldr r0, [r0, r2]
	bl ov96_022196E4
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_022177C4: .word 0x000001C2
_022177C8: .word 0x000006D7
_022177CC: .word 0x0000089B
_022177D0: .word 0x0000089C
_022177D4: .word ov96_02216C1C
	thumb_func_end ov96_0221768C

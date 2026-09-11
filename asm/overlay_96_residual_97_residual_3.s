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
	.public ov96_0220CBC0
	.public ov96_0220CBEC
	.public ov96_0220CC18
	.public ov96_0220CCBC
	.public ov96_0220D33C


	thumb_func_start ov96_0220CD00
ov96_0220CD00: ; 0x0220CD00
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r4, #0
	bl MTRandom
	mov r1, #0x64
	bl _u32_div_f
	lsl r0, r1, #0x18
	lsr r6, r0, #0x18
	cmp r5, #0
	bne _0220CD1C
	bl GF_AssertFail
_0220CD1C:
	ldr r2, [r5, #0x14]
	ldr r1, _0220CD74 ; =ov96_0221CDF4
	lsr r2, r2, #0x1e
	lsl r2, r2, #2
	add r2, r5, r2
	ldr r2, [r2, #4]
	mov r0, #0
	lsl r2, r2, #6
	lsr r3, r2, #0x18
_0220CD2E:
	ldrh r2, [r1]
	cmp r3, r2
	bhs _0220CD3E
	lsl r1, r0, #1
	ldr r0, _0220CD78 ; =ov96_0221CDFE
	ldrsh r0, [r0, r1]
	add r4, r4, r0
	b _0220CD46
_0220CD3E:
	add r0, r0, #1
	add r1, r1, #2
	cmp r0, #5
	blt _0220CD2E
_0220CD46:
	ldr r1, [r5, #0x14]
	ldr r2, _0220CD7C ; =ov96_0221CDE8
	lsl r1, r1, #8
	mov r0, #0
	lsr r3, r1, #0x18
_0220CD50:
	ldrh r1, [r2]
	cmp r3, r1
	blo _0220CD60
	lsl r1, r0, #1
	ldr r0, _0220CD80 ; =ov96_0221CDEE
	ldrsh r0, [r0, r1]
	add r4, r4, r0
	b _0220CD68
_0220CD60:
	add r0, r0, #1
	add r2, r2, #2
	cmp r0, #3
	blt _0220CD50
_0220CD68:
	cmp r6, r4
	bge _0220CD70
	mov r0, #1
	pop {r4, r5, r6, pc}
_0220CD70:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0220CD74: .word ov96_0221CDF4
_0220CD78: .word ov96_0221CDFE
_0220CD7C: .word ov96_0221CDE8
_0220CD80: .word ov96_0221CDEE
	thumb_func_end ov96_0220CD00




	thumb_func_start ov96_0220CD84
ov96_0220CD84: ; 0x0220CD84
	push {r4, r5}
	cmp r1, #1
	beq _0220CD98
	cmp r1, #2
	bne _0220CDDA
	ldr r3, [r0, #0x18]
	ldr r2, _0220CDF0 ; =0xFFFFF800
	and r2, r3
	str r2, [r0, #0x18]
	b _0220CDDA
_0220CD98:
	ldr r2, [r0, #0x14]
	lsl r2, r2, #8
	lsr r5, r2, #0x18
	sub r5, #0xa
	cmp r5, #0x64
	ble _0220CDA8
	mov r5, #0x64
	b _0220CDAE
_0220CDA8:
	cmp r5, #0
	bge _0220CDAE
	mov r5, #0
_0220CDAE:
	ldr r4, [r0, #0x14]
	ldr r3, _0220CDF4 ; =0xFF00FFFF
	add r2, r0, #0
	and r4, r3
	lsl r3, r5, #0x18
	lsr r3, r3, #8
	orr r4, r3
	add r5, r4, #0
	ldr r3, _0220CDF8 ; =0x3FFFFFFF
	lsr r4, r4, #0x1e
	add r4, r4, #1
	and r5, r3
	lsl r4, r4, #0x1e
	orr r4, r5
	str r4, [r0, #0x14]
	lsr r4, r4, #0x1e
	add r2, #0x14
	cmp r4, #3
	blo _0220CDDA
	ldr r4, [r2]
	and r3, r4
	str r3, [r2]
_0220CDDA:
	ldr r3, [r0, #0x14]
	ldr r2, _0220CDFC ; =0xC0FFFFFF
	lsl r1, r1, #0x1a
	and r2, r3
	lsr r1, r1, #2
	orr r2, r1
	ldr r1, _0220CE00 ; =0xFFFF00FF
	and r1, r2
	str r1, [r0, #0x14]
	pop {r4, r5}
	bx lr
	.balign 4, 0
_0220CDF0: .word 0xFFFFF800
_0220CDF4: .word 0xFF00FFFF
_0220CDF8: .word 0x3FFFFFFF
_0220CDFC: .word 0xC0FFFFFF
_0220CE00: .word 0xFFFF00FF
	thumb_func_end ov96_0220CD84




	thumb_func_start ov96_0220CE04
ov96_0220CE04: ; 0x0220CE04
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	str r1, [sp, #4]
	ldr r6, _0220CF48 ; =0x00000000
	bne _0220CE14
	bl GF_AssertFail
_0220CE14:
	add r0, r5, #4
	str r0, [sp, #8]
	ldr r0, [r5, #0x14]
	ldr r1, [sp, #8]
	lsr r0, r0, #0x1e
	lsl r0, r0, #2
	str r0, [sp, #0xc]
	ldr r0, [r1, r0]
	lsl r0, r0, #0x17
	lsr r7, r0, #0x17
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _0220CE34
	add r7, #0xa0
	lsl r0, r7, #0x10
	asr r7, r0, #0x10
_0220CE34:
	add r4, r5, #0
	add r4, #0x10
_0220CE38:
	ldr r0, [r4]
	sub r0, r0, r7
	str r0, [r4]
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bgt _0220CE72
	neg r0, r0
	lsl r0, r0, #0x10
	asr r7, r0, #0x10
	mov r0, #0x64
	str r0, [r5, #0x10]
	mov r0, #1
	str r0, [sp]
	ldr r1, [r5, #0x18]
	ldr r2, [r5, #0x14]
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	ldr r0, [r5]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #3
	bl ov96_021E8228
	add r0, r6, #1
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	b _0220CE38
_0220CE72:
	ldr r2, [r5, #0x14]
	mov r1, #0xff
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	add r1, r1, r6
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	orr r0, r1
	str r0, [r5, #0x14]
	ldr r1, [r5, #0x1c]
	lsl r0, r1, #0x16
	lsr r0, r0, #0x1f
	bne _0220CEFC
	lsl r0, r1, #0x17
	lsr r0, r0, #0x1f
	beq _0220CEF2
	ldr r2, [sp, #8]
	ldr r0, [sp, #0xc]
	lsl r1, r1, #0x18
	ldr r0, [r2, r0]
	lsr r1, r1, #0x18
	lsl r0, r0, #6
	lsl r1, r1, #0x10
	lsr r0, r0, #0x18
	lsr r1, r1, #0x10
	bl ov96_0220D33C
	lsl r0, r0, #0x18
	ldr r2, [sp, #8]
	ldr r1, [sp, #0xc]
	lsr r0, r0, #6
	ldr r2, [r2, r1]
	ldr r1, _0220CF4C ; =0xFC03FFFF
	and r1, r2
	add r2, r1, #0
	orr r2, r0
	ldr r1, [sp, #8]
	ldr r0, [sp, #0xc]
	str r2, [r1, r0]
	ldr r0, [r1, r0]
	lsl r0, r0, #6
	lsr r0, r0, #0x18
	bne _0220CEF2
	mov r3, #1
	str r3, [sp]
	ldr r1, [r5, #0x18]
	ldr r2, [r5, #0x14]
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	ldr r0, [r5]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021E8228
	add r0, r5, #0
	mov r1, #2
	bl ov96_0220CD84
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0220CEF2:
	ldr r1, [sp, #4]
	add r0, r5, #0
	add r2, r6, #0
	bl ov96_0220D014
_0220CEFC:
	cmp r6, #0
	beq _0220CF1A
	ldr r0, [r5, #0x14]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _0220CF1A
	mov r1, #0xa
	bl _u32_div_f
	cmp r1, #0
	bne _0220CF1A
	add r0, r5, #0
	mov r1, #3
	bl ov96_0220CD84
_0220CF1A:
	mov r0, #1
	ldr r1, [r5, #0x1c]
	lsl r0, r0, #8
	orr r1, r0
	mov r0, #0xff
	bic r1, r0
	str r1, [r5, #0x1c]
	mov r0, #1
	str r0, [sp]
	ldr r1, [r5, #0x18]
	ldr r2, [r5, #0x14]
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	ldr r0, [r5]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #4
	bl ov96_021E8228
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220CF48: .word 0x00000000
_0220CF4C: .word 0xFC03FFFF
	thumb_func_end ov96_0220CE04




	thumb_func_start ov96_0220CF50
ov96_0220CF50: ; 0x0220CF50
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r0, r2, #0
	add r4, r1, #0
	bl PokeathlonCourse_GetDataCopyArea
	ldr r1, [r5, #0x18]
	add r0, #0x50
	lsr r2, r1, #0x1e
	mov r1, #0x28
	mul r1, r2
	add r0, r0, r1
	bl ov96_021E8A20
	ldr r7, [r5, #0x14]
	mov r6, #0xff
	lsr r1, r7, #0x1e
	lsl r2, r1, #2
	ldr r1, [r0]
	add r3, r5, #4
	bic r1, r6
	lsl r6, r7, #0x18
	lsr r6, r6, #0x18
	lsl r6, r6, #0x18
	lsr r6, r6, #0x18
	orr r6, r1
	str r6, [r0]
	ldr r2, [r3, r2]
	ldr r1, _0220CFFC ; =0xFFFF00FF
	lsl r2, r2, #6
	lsr r2, r2, #0x18
	lsl r2, r2, #0x18
	and r1, r6
	lsr r2, r2, #0x10
	orr r2, r1
	ldr r1, _0220D000 ; =0xFF00FFFF
	str r2, [r0]
	and r1, r2
	ldr r2, [r5, #0x14]
	lsl r2, r2, #8
	lsr r2, r2, #0x18
	lsl r2, r2, #0x18
	lsr r2, r2, #8
	orr r2, r1
	ldr r1, _0220D004 ; =0xFBFFFFFF
	str r2, [r0]
	and r1, r2
	ldr r2, [r5, #0x1c]
	lsl r2, r2, #0x16
	lsr r2, r2, #0x1f
	lsl r2, r2, #0x1f
	lsr r2, r2, #5
	orr r2, r1
	ldr r1, _0220D008 ; =0xF7FFFFFF
	and r2, r1
	mov r1, #2
	and r1, r4
	lsl r1, r1, #0x1f
	lsr r1, r1, #4
	orr r2, r1
	ldr r1, _0220D00C ; =0xFCFFFFFF
	str r2, [r0]
	and r2, r1
	ldr r1, [r5, #0x14]
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x1e
	lsr r1, r1, #6
	orr r1, r2
	str r1, [r0]
	ldr r1, [r5, #0x14]
	lsl r1, r1, #2
	lsr r1, r1, #0x1a
	cmp r1, #1
	bne _0220CFE8
	mov r3, #1
	b _0220CFEA
_0220CFE8:
	mov r3, #0
_0220CFEA:
	ldr r2, [r0]
	ldr r1, _0220D010 ; =0xEFFFFFFF
	and r2, r1
	lsl r1, r3, #0x1f
	lsr r1, r1, #3
	orr r1, r2
	str r1, [r0]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220CFFC: .word 0xFFFF00FF
_0220D000: .word 0xFF00FFFF
_0220D004: .word 0xFBFFFFFF
_0220D008: .word 0xF7FFFFFF
_0220D00C: .word 0xFCFFFFFF
_0220D010: .word 0xEFFFFFFF
	thumb_func_end ov96_0220CF50




	thumb_func_start ov96_0220D014
ov96_0220D014: ; 0x0220D014
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x1c]
	add r4, r1, #0
	lsl r0, r0, #0x16
	lsr r0, r0, #0x1f
	beq _0220D026
	bl GF_AssertFail
_0220D026:
	cmp r4, #0
	beq _0220D040
	ldr r1, [r5, #0x14]
	ldr r0, _0220D074 ; =0xFF00FFFF
	add r2, r1, #0
	and r2, r0
	lsl r0, r1, #8
	lsr r0, r0, #0x18
	add r0, #0x1e
	lsl r0, r0, #0x18
	lsr r0, r0, #8
	orr r0, r2
	str r0, [r5, #0x14]
_0220D040:
	ldr r1, [r5, #0x14]
	lsl r0, r1, #8
	lsr r0, r0, #0x18
	cmp r0, #0x64
	bls _0220D056
	ldr r0, _0220D074 ; =0xFF00FFFF
	and r1, r0
	mov r0, #0x19
	lsl r0, r0, #0x12
	orr r0, r1
	str r0, [r5, #0x14]
_0220D056:
	ldr r0, [r5, #0x14]
	lsl r0, r0, #8
	lsr r0, r0, #0x18
	cmp r0, #0x64
	blo _0220D072
	mov r0, #2
	ldr r1, [r5, #0x1c]
	lsl r0, r0, #8
	orr r0, r1
	str r0, [r5, #0x1c]
	ldr r1, [r5, #0x18]
	ldr r0, _0220D078 ; =0xFFC007FF
	and r0, r1
	str r0, [r5, #0x18]
_0220D072:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0220D074: .word 0xFF00FFFF
_0220D078: .word 0xFFC007FF
	thumb_func_end ov96_0220D014




	thumb_func_start ov96_0220D07C
ov96_0220D07C: ; 0x0220D07C
	push {r4, lr}
	ldr r1, [r0, #0x1c]
	lsl r1, r1, #0x16
	lsr r1, r1, #0x1f
	beq _0220D0A8
	ldr r2, [r0, #0x18]
	ldr r1, _0220D0F0 ; =0xFFC007FF
	and r1, r2
	lsl r2, r2, #0xa
	lsr r2, r2, #0x15
	add r2, r2, #1
	lsl r2, r2, #0x15
	lsr r2, r2, #0xa
	orr r1, r2
	str r1, [r0, #0x18]
	lsl r1, r1, #0xa
	lsr r1, r1, #0x15
	cmp r1, #0x5a
	blo _0220D0EE
	bl ov96_0220D0F8
	pop {r4, pc}
_0220D0A8:
	ldr r1, [r0, #0x14]
	lsl r1, r1, #8
	lsr r1, r1, #0x18
	beq _0220D0EE
	ldr r4, [r0, #0x18]
	add r2, r0, #0
	add r1, r4, #0
	lsl r4, r4, #0xa
	lsr r4, r4, #0x15
	ldr r3, _0220D0F0 ; =0xFFC007FF
	add r4, r4, #1
	lsl r4, r4, #0x15
	and r1, r3
	lsr r4, r4, #0xa
	orr r1, r4
	str r1, [r0, #0x18]
	lsl r1, r1, #0xa
	lsr r1, r1, #0x15
	add r2, #0x18
	cmp r1, #2
	blo _0220D0EE
	ldr r1, [r2]
	and r1, r3
	str r1, [r2]
	ldr r2, [r0, #0x14]
	ldr r1, _0220D0F4 ; =0xFF00FFFF
	add r3, r2, #0
	and r3, r1
	lsl r1, r2, #8
	lsr r1, r1, #0x18
	sub r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #8
	orr r1, r3
	str r1, [r0, #0x14]
_0220D0EE:
	pop {r4, pc}
	.balign 4, 0
_0220D0F0: .word 0xFFC007FF
_0220D0F4: .word 0xFF00FFFF
	thumb_func_end ov96_0220D07C




	thumb_func_start ov96_0220D0F8
ov96_0220D0F8: ; 0x0220D0F8
	push {r3, r4}
	ldr r4, [r0, #0x1c]
	ldr r3, _0220D12C ; =0xFFFFFDFF
	ldr r1, [r0, #0x14]
	and r3, r4
	str r3, [r0, #0x1c]
	ldr r4, [r0, #0x18]
	ldr r3, _0220D130 ; =0xFFC007FF
	lsr r1, r1, #0x1e
	and r3, r4
	str r3, [r0, #0x18]
	ldr r4, [r0, #0x14]
	ldr r3, _0220D134 ; =0xFF00FFFF
	add r2, r0, #4
	and r3, r4
	str r3, [r0, #0x14]
	lsl r1, r1, #2
	ldr r3, [r2, r1]
	ldr r0, _0220D138 ; =0xFC03FFFF
	and r3, r0
	mov r0, #0xa
	lsl r0, r0, #0x12
	orr r0, r3
	str r0, [r2, r1]
	pop {r3, r4}
	bx lr
	.balign 4, 0
_0220D12C: .word 0xFFFFFDFF
_0220D130: .word 0xFFC007FF
_0220D134: .word 0xFF00FFFF
_0220D138: .word 0xFC03FFFF
	thumb_func_end ov96_0220D0F8




	thumb_func_start ov96_0220D13C
ov96_0220D13C: ; 0x0220D13C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r6, _0220D19C ; =ov96_0221CE84
	add r7, r2, #0
	str r3, [sp]
	add r5, r0, #0
	add r4, r1, #0
	add r3, sp, #4
	mov r2, #6
_0220D14E:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220D14E
	ldr r0, [r6]
	cmp r5, #0
	str r0, [r3]
	bne _0220D162
	bl GF_AssertFail
_0220D162:
	cmp r4, #0
	bne _0220D16A
	bl GF_AssertFail
_0220D16A:
	add r1, sp, #4
	strh r7, [r1]
	ldr r0, [sp]
	mov r3, #1
	strh r0, [r1, #2]
	add r0, sp, #0x40
	ldrh r2, [r0, #0x10]
	strh r2, [r1, #6]
	ldrh r0, [r0, #0x14]
	add r1, r4, #0
	add r2, sp, #4
	str r0, [sp, #0xc]
	str r3, [sp, #0x30]
	add r0, r5, #0
	lsl r3, r3, #0x14
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	add r4, r0, #0
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220D19C: .word ov96_0221CE84
	thumb_func_end ov96_0220D13C




	thumb_func_start ov96_0220D1A0
ov96_0220D1A0: ; 0x0220D1A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r6, _0220D1FC ; =ov96_0221CEB8
	add r7, r2, #0
	str r3, [sp]
	add r5, r0, #0
	add r4, r1, #0
	add r3, sp, #4
	mov r2, #6
_0220D1B2:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220D1B2
	ldr r0, [r6]
	cmp r5, #0
	str r0, [r3]
	bne _0220D1C6
	bl GF_AssertFail
_0220D1C6:
	cmp r4, #0
	bne _0220D1CE
	bl GF_AssertFail
_0220D1CE:
	add r1, sp, #4
	strh r7, [r1]
	ldr r0, [sp]
	mov r3, #1
	strh r0, [r1, #2]
	add r0, sp, #0x40
	ldrh r2, [r0, #0x10]
	lsl r3, r3, #0x14
	strh r2, [r1, #6]
	ldrh r0, [r0, #0x14]
	add r1, r4, #0
	add r2, sp, #4
	str r0, [sp, #0xc]
	add r0, r5, #0
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	add r4, r0, #0
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220D1FC: .word ov96_0221CEB8
	thumb_func_end ov96_0220D1A0




	thumb_func_start ov96_0220D200
ov96_0220D200: ; 0x0220D200
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r5, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	add r0, sp, #8
	mov r1, #0xaa
	mov r2, #5
	bl ReadWholeNarcMemberByIdPair
	mov r6, #0
	add r7, sp, #8
_0220D218:
	ldr r0, [sp, #4]
	ldr r1, [sp]
	add r2, r6, #0
	bl ov96_021E60D8
	add r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #5
	blo _0220D22E
	bl GF_AssertFail
_0220D22E:
	ldrb r0, [r4, #3]
	cmp r0, #5
	blo _0220D238
	bl GF_AssertFail
_0220D238:
	ldrb r0, [r4, #4]
	cmp r0, #5
	blo _0220D242
	bl GF_AssertFail
_0220D242:
	ldr r1, [r5]
	ldr r0, _0220D298 ; =0xFFFFFE00
	add r6, r6, #1
	and r0, r1
	ldrb r1, [r4]
	lsl r1, r1, #2
	ldr r2, [r7, r1]
	ldr r1, _0220D29C ; =0x000001FF
	and r1, r2
	orr r1, r0
	ldr r0, _0220D2A0 ; =0xFFFC01FF
	str r1, [r5]
	and r0, r1
	ldrb r1, [r4, #3]
	lsl r1, r1, #2
	add r1, r7, r1
	ldr r1, [r1, #0x14]
	lsl r1, r1, #0x17
	lsr r1, r1, #0xe
	orr r1, r0
	ldr r0, _0220D2A4 ; =0x03FFFFFF
	str r1, [r5]
	and r0, r1
	ldrb r1, [r4, #4]
	lsl r1, r1, #2
	add r1, r7, r1
	ldr r1, [r1, #0x28]
	lsl r1, r1, #0x1a
	orr r1, r0
	ldr r0, _0220D2A8 ; =0xFC03FFFF
	str r1, [r5]
	and r0, r1
	lsl r1, r1, #0xe
	lsr r1, r1, #0x17
	lsl r1, r1, #0x18
	lsr r1, r1, #6
	orr r0, r1
	stmia r5!, {r0}
	cmp r6, #3
	blt _0220D218
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_0220D298: .word 0xFFFFFE00
_0220D29C: .word 0x000001FF
_0220D2A0: .word 0xFFFC01FF
_0220D2A4: .word 0x03FFFFFF
_0220D2A8: .word 0xFC03FFFF
	thumb_func_end ov96_0220D200




	thumb_func_start ov96_0220D2AC
ov96_0220D2AC: ; 0x0220D2AC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r1, #0
	add r5, r0, #0
	add r0, r7, #0
	mov r1, #0x3c
	str r2, [sp]
	mov r4, #0
	bl _u32_div_f
	str r1, [sp, #4]
	add r0, r7, #0
	mov r1, #0x1e
	bl _u32_div_f
	add r6, r1, #0
_0220D2CC:
	ldr r1, [r5]
	lsl r0, r1, #6
	lsl r3, r1, #0xe
	lsr r2, r0, #0x18
	lsr r3, r3, #0x17
	lsl r0, r2, #0x10
	lsl r3, r3, #0x10
	lsr r0, r0, #0x10
	lsr r3, r3, #0x10
	cmp r7, #0
	beq _0220D32A
	cmp r0, r3
	bhs _0220D32A
	ldr r0, [sp]
	cmp r4, r0
	bne _0220D302
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0220D314
	ldr r0, _0220D338 ; =0xFC03FFFF
	add r2, #8
	and r0, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #6
	orr r0, r1
	str r0, [r5]
	b _0220D314
_0220D302:
	cmp r6, #0
	bne _0220D314
	ldr r0, _0220D338 ; =0xFC03FFFF
	and r0, r1
	add r1, r2, #5
	lsl r1, r1, #0x18
	lsr r1, r1, #6
	orr r0, r1
	str r0, [r5]
_0220D314:
	ldr r1, [r5]
	lsl r0, r1, #6
	lsr r0, r0, #0x18
	cmp r0, r3
	bls _0220D32A
	ldr r0, _0220D338 ; =0xFC03FFFF
	and r0, r1
	lsl r1, r3, #0x18
	lsr r1, r1, #6
	orr r0, r1
	str r0, [r5]
_0220D32A:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _0220D2CC
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220D338: .word 0xFC03FFFF
	thumb_func_end ov96_0220D2AC



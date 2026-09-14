	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.public GF_AssertFail
	.public VEC_MultAdd
	.public _ffix
	.public _fflt
	.public _fmul
	.public ov96_021E8228
	.public ov96_02215958
	.public ov96_0221785C
	.public ov96_02217868
	.public ov96_02219174
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

	thumb_func_start ov96_022178A0
ov96_022178A0: ; 0x022178A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r1, #0
	add r5, r0, #0
	ldr r0, [r4, #4]
	ldr r1, [r4, #0x14]
	ldr r0, [r0, #4]
	str r2, [sp, #4]
	ldr r7, [r0]
	ldr r6, [r0, #4]
	ldr r0, [r5, #0x14]
	bl ov96_0221785C
	cmp r0, #0
	bne _022178C0
	b _02217AC6
_022178C0:
	ldr r0, [r4, #0x14]
	cmp r0, #6
	bne _0221794A
	add r0, r7, #0
	bl _fflt
	add r1, r0, #0
	ldr r0, _02217ACC ; =0x40400000
	bl _fmul
	bl _ffix
	add r7, r0, #0
	add r0, r6, #0
	bl _fflt
	add r1, r0, #0
	mov r0, #1
	lsl r0, r0, #0x1e
	bl _fmul
	bl _ffix
	add r6, r0, #0
	ldr r0, [r4, #0x60]
	lsl r0, r0, #0x14
	lsr r0, r0, #0x14
	add r1, r0, #1
	cmp r1, #0xc8
	ble _022178FE
	mov r1, #0xc8
_022178FE:
	ldr r0, [r4, #0x60]
	ldr r2, _02217AD0 ; =0xFFFFF000
	mov r3, #3
	and r0, r2
	lsr r2, r2, #0x14
	and r1, r2
	orr r0, r1
	str r0, [r4, #0x60]
	mov r0, #1
	str r0, [sp]
	ldr r2, [r4, #0x60]
	ldr r0, [r4]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021E8228
	mov r0, #1
	str r0, [sp]
	ldr r2, [r4, #0x60]
	ldr r0, [r4]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #4
	bl ov96_021E8228
	b _022179B4
_0221794A:
	cmp r0, #0xb
	bne _022179B0
	ldr r0, [r4, #4]
	ldr r0, [r0, #4]
	ldr r7, [r0, #0x10]
	ldr r6, [r0, #0x14]
	ldr r0, [r4, #0x60]
	lsl r0, r0, #0x14
	lsr r0, r0, #0x14
	add r1, r0, #2
	cmp r1, #0xc8
	ble _02217964
	mov r1, #0xc8
_02217964:
	ldr r0, [r4, #0x60]
	ldr r2, _02217AD0 ; =0xFFFFF000
	mov r3, #3
	and r0, r2
	lsr r2, r2, #0x14
	and r1, r2
	orr r0, r1
	str r0, [r4, #0x60]
	mov r0, #1
	str r0, [sp]
	ldr r2, [r4, #0x60]
	ldr r0, [r4]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021E8228
	mov r0, #1
	str r0, [sp]
	ldr r2, [r4, #0x60]
	ldr r0, [r4]
	lsl r1, r2, #0xa
	lsl r2, r2, #8
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #4
	bl ov96_021E8228
	b _022179B4
_022179B0:
	mov r7, #3
	lsl r7, r7, #0xc
_022179B4:
	add r2, r5, #0
	add r2, #0x44
	ldr r1, [sp, #4]
	add r0, r7, #0
	add r3, r2, #0
	bl VEC_MultAdd
	add r0, r5, #0
	mov r1, #3
	add r0, #0x44
	lsl r1, r1, #0xe
	bl ov96_02215958
	ldr r1, [sp, #4]
	add r0, r4, #0
	bl ov96_02217868
	ldr r0, [r4, #0x14]
	bl ov96_02217890
	cmp r0, #0
	beq _022179F6
	add r0, r5, #0
	mov r1, #4
	add r0, #0x5d
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x5d
	strb r1, [r0]
	add r0, r5, #0
	add r1, r6, #0
	bl ov96_02219174
_022179F6:
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _02217A06
	ldr r0, [r4, #0x14]
	bl ov96_02217890
	cmp r0, #0
	beq _02217A14
_02217A06:
	str r4, [r5, #0x10]
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _02217A14
	cmp r0, r5
	beq _02217A14
	str r0, [r5, #0x10]
_02217A14:
	mov r0, #2
	ldr r1, [r5, #0x60]
	lsl r0, r0, #0x1a
	orr r0, r1
	str r0, [r5, #0x60]
	ldr r0, [r4, #0x14]
	str r0, [r5, #0x18]
	ldr r0, [r4, #0x14]
	bl ov96_02217890
	cmp r0, #0
	ldr r1, [r5, #0x60]
	beq _02217A82
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1e
	cmp r0, #2
	beq _02217A5C
	ldr r0, [r4, #0x14]
	cmp r0, #6
	beq _02217A42
	cmp r0, #0xb
	beq _02217A50
	b _02217A5C
_02217A42:
	ldr r0, _02217AD4 ; =0xFFFF3FFF
	and r1, r0
	mov r0, #1
	lsl r0, r0, #0xe
	orr r0, r1
	str r0, [r5, #0x60]
	b _02217A5C
_02217A50:
	ldr r0, _02217AD4 ; =0xFFFF3FFF
	and r1, r0
	mov r0, #2
	lsl r0, r0, #0xe
	orr r0, r1
	str r0, [r5, #0x60]
_02217A5C:
	ldr r0, [r4, #0x60]
	ldr r1, [r5, #0x60]
	lsl r0, r0, #0xa
	lsl r1, r1, #0xa
	lsr r0, r0, #0x1e
	lsr r1, r1, #0x1e
	cmp r0, r1
	bhs _02217A6E
	add r0, r0, #1
_02217A6E:
	ldr r2, [r5, #0x60]
	ldr r1, _02217AD8 ; =0xFFFFCFFF
	lsl r0, r0, #0x1e
	and r1, r2
	lsr r0, r0, #0x12
	orr r0, r1
	str r0, [r5, #0x60]
	mov r0, #4
	str r0, [r5, #0x64]
	b _02217A8C
_02217A82:
	ldr r0, _02217ADC ; =0x7FFFFFFF
	and r1, r0
	add r0, r0, #1
	orr r0, r1
	str r0, [r5, #0x60]
_02217A8C:
	ldr r0, [r4, #0x14]
	mov r1, #0
	cmp r0, #3
	beq _02217A9A
	cmp r0, #4
	beq _02217A9A
	mov r1, #1
_02217A9A:
	cmp r1, #0
	bne _02217AA2
	bl GF_AssertFail
_02217AA2:
	ldr r0, [r5, #0x14]
	mov r2, #1
	sub r0, r0, #3
	cmp r0, #8
	bhi _02217AB8
	add r1, r2, #0
	lsl r1, r0
	ldr r0, _02217AE0 ; =0x00000103
	tst r0, r1
	beq _02217AB8
	mov r2, #0
_02217AB8:
	cmp r2, #0
	bne _02217AC0
	bl GF_AssertFail
_02217AC0:
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02217AC6:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02217ACC: .word 0x40400000
_02217AD0: .word 0xFFFFF000
_02217AD4: .word 0xFFFF3FFF
_02217AD8: .word 0xFFFFCFFF
_02217ADC: .word 0x7FFFFFFF
_02217AE0: .word 0x00000103
	thumb_func_end ov96_022178A0

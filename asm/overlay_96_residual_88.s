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

	thumb_func_start ov96_02207418
ov96_02207418: ; 0x02207418
	push {r4, r5, r6, r7, lr}
	sub sp, #0x84
	str r0, [sp, #8]
	mov r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r0, [sp, #0x18]
	str r0, [sp, #0x80]
	str r0, [sp, #0x74]
	add r7, r0, #0
	add r6, r1, #0
_0220742E:
	add r0, r6, #0
	add r0, #0xb1
	ldrb r1, [r0]
	add r0, r6, #0
	add r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _02207440
	b _0220763C
_02207440:
	lsl r0, r1, #2
	ldr r0, [r6, r0]
	str r0, [sp, #0x20]
	add r0, sp, #0x2c
	str r0, [sp]
	ldr r2, [r6, #0x58]
	ldr r3, [r6, #0x5c]
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	ldr r0, [sp, #0x20]
	asr r1, r1, #0xc
	asr r2, r2, #0xc
	add r3, sp, #0x30
	bl ov96_021EB0A4
	ldr r5, [sp, #0xc]
	mov r4, #0
_0220746A:
	cmp r7, r4
	beq _02207500
	add r0, r5, #0
	add r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _02207500
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x14]
	add r0, r5, #0
	add r0, #0xb1
	ldrb r0, [r0]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	str r0, [sp, #0x1c]
	add r0, sp, #0x24
	str r0, [sp]
	ldr r1, [r5, #0x58]
	ldr r3, [r5, #0x5c]
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	ldr r0, [sp, #0x1c]
	asr r2, r2, #0xc
	add r3, sp, #0x28
	bl ov96_021EB0A4
	add r0, sp, #0x70
	str r0, [sp]
	add r0, sp, #0x34
	str r0, [sp, #4]
	ldr r1, [sp, #0x28]
	ldr r2, [sp, #0x24]
	ldr r0, [sp, #0x1c]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x6c
	bl ov96_021EAF78
	add r0, sp, #0x7c
	str r0, [sp]
	add r0, sp, #0x38
	str r0, [sp, #4]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x2c]
	ldr r0, [sp, #0x20]
	lsl r1, r1, #0xc
	lsl r2, r2, #0xc
	add r3, sp, #0x78
	bl ov96_021EAF78
	add r0, sp, #0x78
	add r1, sp, #0x6c
	add r2, sp, #0x60
	bl VEC_Subtract
	add r0, sp, #0x60
	bl VEC_Mag
	ldr r2, [sp, #0x34]
	ldr r1, [sp, #0x38]
	add r1, r2, r1
	lsl r1, r1, #0xc
	cmp r0, r1
	blt _022074F6
	b _02207624
_022074F6:
	add r0, r6, r4
	add r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _02207502
_02207500:
	b _02207632
_02207502:
	ldr r0, [sp, #8]
	add r1, r6, #0
	add r2, r5, #0
	bl ov96_02207A34
	cmp r0, #0
	bne _0220751E
	add r0, r6, #0
	mov r1, #6
	add r0, #0xa4
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0xa4
	strb r1, [r0]
_0220751E:
	add r0, r6, #0
	add r0, #0x64
	bl VEC_Mag
	mov r1, #0xb
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _02207552
	add r1, sp, #0x54
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r0, r6, #0
	add r0, #0x64
	add r1, r0, #0
	bl VEC_Normalize
	add r1, r6, #0
	mov r0, #0xb
	add r1, #0x64
	lsl r0, r0, #0xc
	add r2, sp, #0x54
	add r3, r1, #0
	bl VEC_MultAdd
_02207552:
	add r0, r5, #0
	add r0, #0x64
	bl VEC_Mag
	mov r1, #0xb
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _02207586
	add r1, sp, #0x48
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r0, r5, #0
	add r0, #0x64
	add r1, r0, #0
	bl VEC_Normalize
	add r1, r5, #0
	mov r0, #0xb
	add r1, #0x64
	lsl r0, r0, #0xc
	add r2, sp, #0x48
	add r3, r1, #0
	bl VEC_MultAdd
_02207586:
	add r0, r6, r4
	add r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _02207594
	bl GF_AssertFail
_02207594:
	add r0, r5, r7
	add r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _022075A2
	bl GF_AssertFail
_022075A2:
	add r1, r6, r4
	mov r0, #1
	add r1, #0x94
	strb r0, [r1]
	add r1, r5, r7
	add r1, #0x94
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	cmp r1, #0
	bne _022075EC
	add r2, sp, #0x3c
	mov r1, #0
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [r2, #8]
	str r0, [sp, #0x18]
	add r0, sp, #0x6c
	add r1, sp, #0x78
	bl VEC_Subtract
	add r0, sp, #0x3c
	add r1, r0, #0
	bl VEC_Normalize
	ldr r0, [sp, #0x38]
	add r1, sp, #0x3c
	lsl r0, r0, #0xc
	add r2, sp, #0x78
	add r3, r1, #0
	bl VEC_MultAdd
	add r3, sp, #0x3c
	ldr r2, [sp, #0x10]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
_022075EC:
	mov r0, #1
	add r1, r6, #0
	str r0, [sp]
	add r1, #0x98
	add r2, r6, #0
	ldr r1, [r1]
	add r2, #0xb1
	lsl r1, r1, #0x18
	ldrb r2, [r2]
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	mov r3, #4
	bl ov96_021E8228
	add r1, r5, #0
	mov r0, #1
	str r0, [sp]
	add r1, #0x98
	ldr r1, [r1]
	add r5, #0xb1
	lsl r1, r1, #0x18
	ldrb r2, [r5]
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	mov r3, #4
	bl ov96_021E8228
	b _0220763C
_02207624:
	add r1, r6, r4
	add r1, #0x94
	mov r0, #0
	strb r0, [r1]
	add r1, r7, r5
	add r1, #0x94
	strb r0, [r1]
_02207632:
	add r4, r4, #1
	add r5, #0xb8
	cmp r4, #4
	bge _0220763C
	b _0220746A
_0220763C:
	add r7, r7, #1
	add r6, #0xb8
	cmp r7, #4
	bge _02207646
	b _0220742E
_02207646:
	ldr r0, [sp, #0x18]
	add sp, #0x84
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_02207418


	thumb_func_start ov96_0220764C
ov96_0220764C: ; 0x0220764C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r7, #0x47
	mov r6, #0
	add r4, r5, #0
	lsl r7, r7, #4
_02207658:
	ldr r0, _022076BC ; =0x00000474
	mov r1, #3
	ldr r0, [r4, r0]
	bl ov96_021EB630
	mov r0, #0x47
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_021EB594
	ldr r1, [r0, #4]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	bl ov96_02207BD8
	add r1, r0, #0
	ldr r0, [r4, r7]
	add r1, r1, #7
	bl ov96_021EB630
	add r6, r6, #1
	add r4, #0x10
	cmp r6, #0xa
	blt _02207658
	mov r7, #0xe
	lsl r7, r7, #6
	mov r4, #0
	add r6, r7, #0
_02207694:
	ldr r0, [r5, r7]
	bl ov96_021EB594
	ldr r1, [r0, #4]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	bl ov96_02207BD8
	add r1, r0, #0
	ldr r0, [r5, r6]
	add r1, r1, #1
	bl ov96_021EB630
	add r4, r4, #1
	add r5, #0xc
	cmp r4, #0x14
	blt _02207694
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022076BC: .word 0x00000474
	thumb_func_end ov96_0220764C


	thumb_func_start ov96_022076C0
ov96_022076C0: ; 0x022076C0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, r1, #0
	bl ov96_02207BD8
	add r4, r0, #0
	add r1, r4, #0
	ldr r0, [r5, #4]
	add r1, #9
	bl ov96_021EB630
	add r4, #8
	ldr r0, [r5, #8]
	add r1, r4, #0
	bl ov96_021EB630
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_022076C0


	thumb_func_start ov96_022076E4
ov96_022076E4: ; 0x022076E4
	push {r3, r4, r5, r6, r7, lr}
	mov r7, #0xd7
	lsl r7, r7, #2
	add r5, r0, #0
	mov r4, #0
	add r6, r7, #0
_022076F0:
	ldr r0, [r5, r7]
	bl ov96_021EB594
	ldr r1, [r0, #4]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	bl ov96_02207BD8
	add r1, r0, #0
	ldr r0, [r5, r6]
	add r1, r1, #2
	bl ov96_021EB630
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _022076F0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_022076E4


	thumb_func_start ov96_02207718
ov96_02207718: ; 0x02207718
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r0, r1, #0
	bl ov96_02207BD8
	add r6, r0, #0
	ldr r0, [r5, #0x48]
	add r1, r6, #3
	bl ov96_021EB630
	mov r4, #0
_0220772E:
	ldr r0, [r5]
	add r1, r6, #4
	bl ov96_021EABA8
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _0220772E
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_02207718


	thumb_func_start ov96_02207740
ov96_02207740: ; 0x02207740
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4]
	ldr r2, _02207770 ; =ov96_0221CAC0
	add r1, r4, #4
	bl AddWindow
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4]
	mov r1, #3
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r4, #0x14]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	add sp, #4
	pop {r3, r4, pc}
	nop
_02207770: .word ov96_0221CAC0
	thumb_func_end ov96_02207740


	thumb_func_start ov96_02207774
ov96_02207774: ; 0x02207774
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	add r0, r5, #4
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r2, _022077EC ; =0x00000135
	ldr r3, [r5, #0x14]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	add r4, r0, #0
	ldr r0, [r5, #0x14]
	bl MessageFormat_New
	mov r1, #0
	str r1, [sp]
	mov r2, #1
	str r2, [sp, #4]
	add r2, r7, #0
	mov r3, #3
	add r6, r0, #0
	bl BufferIntegerAsString
	ldr r3, [r5, #0x14]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x9d
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _022077F0 ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	add r0, r5, #4
	add r2, r7, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl MessageFormat_Delete
	add r0, r4, #0
	bl DestroyMsgData
	add r0, r5, #4
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022077EC: .word 0x00000135
_022077F0: .word 0x000F0E00
	thumb_func_end ov96_02207774

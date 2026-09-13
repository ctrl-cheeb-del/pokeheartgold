	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text
	.public ov96_021FEECC
	.public ov96_021FF0BC
	.public ov96_021FF1E0
	.public ov96_021FF2A0
	.extern ov96_021FEBF0
	.extern ov96_021FED3C
	.extern ov96_021FEE60
	.extern ov96_021FF67C

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


	thumb_func_start ov96_021FEECC
ov96_021FEECC: ; 0x021FEECC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	ldr r7, [sp, #0x40]
	str r0, [sp, #0x10]
	ldr r6, [sp, #0x44]
	mov r0, #0
	str r0, [sp, #0x14]
	add r4, r1, #0
	ldrb r0, [r3, #0x1d]
	lsl r1, r7, #1
	mov ip, r2
	asr r0, r1
	mov r1, #3
	and r0, r1
	add r1, r4, #0
	add r1, #0x9f
	lsl r0, r0, #0x18
	ldrb r1, [r1]
	lsr r0, r0, #0x18
	ldr r5, [sp, #0x50]
	cmp r1, r0
	beq _021FEF0A
	add r1, r4, #0
	add r1, #0x9f
	strb r0, [r1]
	add r1, r4, #0
	ldr r0, [sp, #0x14]
	add r1, #0xa0
	strb r0, [r1]
	mov r0, #1
	str r0, [sp, #0x14]
_021FEF0A:
	add r0, sp, #0x18
	str r0, [sp]
	mov r1, ip
	ldr r2, [r1]
	lsl r0, r6, #2
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	mov r2, ip
	ldr r3, [r2, #4]
	ldr r0, [r4, r0]
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r1, r1, #0xc
	asr r2, r2, #0xc
	add r3, sp, #0x1c
	bl ov96_021EB0A4
	ldr r0, [sp, #0x1c]
	lsl r0, r0, #0xc
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x18]
	lsl r0, r0, #0xc
	str r0, [sp, #0x24]
	mov r0, #0
	str r0, [sp, #0x28]
	add r0, r4, #0
	add r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FEFB0
	cmp r0, #1
	beq _021FEF56
	cmp r0, #2
	beq _021FEF82
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
_021FEF56:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _021FEF66
	ldr r0, [sp, #0x54]
	cmp r0, #0
	beq _021FEF66
	mov r1, #1
	b _021FEF68
_021FEF66:
	mov r1, #0
_021FEF68:
	ldr r0, [sp, #0x48]
	str r6, [sp]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0x10]
	add r1, r4, #0
	add r2, sp, #0x20
	add r3, r7, #0
	str r5, [sp, #0xc]
	bl ov96_021FEBF0
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
_021FEF82:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _021FEF92
	ldr r0, [sp, #0x54]
	cmp r0, #0
	beq _021FEF92
	mov r1, #1
	b _021FEF94
_021FEF92:
	mov r1, #0
_021FEF94:
	ldr r0, [sp, #0x48]
	add r2, r7, #0
	str r0, [sp]
	add r0, r1, #0
	orr r0, r5
	str r0, [sp, #4]
	add r0, r4, #0
	add r1, sp, #0x20
	add r3, r6, #0
	str r5, [sp, #8]
	bl ov96_021FED3C
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
_021FEFB0:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _021FEFDA
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _021FEFC6
	ldr r0, [sp, #0x54]
	cmp r0, #0
	beq _021FEFC6
	mov r0, #1
	b _021FEFC8
_021FEFC6:
	mov r0, #0
_021FEFC8:
	orr r0, r5
	str r0, [sp]
	ldr r3, [sp, #0x48]
	add r0, r4, #0
	add r1, r7, #0
	add r2, r6, #0
	str r5, [sp, #4]
	bl ov96_021FEE60
_021FEFDA:
	ldr r0, [r4, #0x70]
	add r1, sp, #0x20
	bl ov96_021EB588
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021FEECC




	thumb_func_start ov96_021FEFE8
ov96_021FEFE8: ; 0x021FEFE8
	push {r3, r4, r5, r6, r7, lr}
	str r3, [sp]
	add r5, r1, #0
	add r1, r2, #0
	ldr r2, [sp]
	ldr r6, [sp, #0x18]
	bl ov96_021E60D8
	add r4, r0, #0
	ldr r0, [sp]
	mov r1, #0x1c
	add r7, r0, #0
	ldrb r0, [r4]
	mul r7, r1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl _fflt
	bl _f2d
	ldr r3, _021FF0B8 ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r6, r7
	str r0, [r1, #0x20]
	ldrb r0, [r4, #3]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x14]
	bl _fflt
	add r1, r6, r7
	str r0, [r1, #0x28]
	ldrb r0, [r4, #3]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x14]
	bl _fflt
	add r1, r6, r7
	str r0, [r1, #0x24]
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r2, [r0, #0x64]
	add r0, r1, #0
	add r0, #0x2e
	strb r2, [r0]
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	add r0, #0x8c
	ldr r2, [r0]
	add r0, r1, #0
	add r0, #0x2c
	strb r2, [r0]
	ldrb r0, [r4, #1]
	add r1, #0x2d
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x78]
	strb r0, [r1]
	ldrb r0, [r4, #4]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x28]
	bl _fflt
	bl _f2d
	ldr r3, _021FF0B8 ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r6, r7
	str r0, [r1, #0x18]
	ldrb r0, [r4, #1]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x3c]
	bl _fflt
	bl _f2d
	ldr r3, _021FF0B8 ; =0x40240000
	mov r2, #0
	bl _ddiv
	bl _d2f
	add r1, r6, r7
	str r0, [r1, #0x1c]
	ldrb r0, [r4, #3]
	add r1, #0x2f
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x50]
	strb r0, [r1]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FF0B8: .word 0x40240000
	thumb_func_end ov96_021FEFE8




	thumb_func_start ov96_021FF0BC
ov96_021FF0BC: ; 0x021FF0BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	ldr r0, [sp, #0x28]
	str r2, [sp]
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x2c]
	str r3, [sp, #4]
	str r0, [sp, #0x2c]
	mov r0, #0
	add r7, r0, #0
_021FF0D2:
	stmia r2!, {r7}
	add r0, r0, #1
	stmia r3!, {r7}
	cmp r0, #0x1e
	blt _021FF0D2
	ldr r0, [sp, #0x28]
	str r5, [sp, #8]
	strb r7, [r0]
	ldr r0, [sp, #0x2c]
	strb r7, [r0]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x10]
	ldr r0, _021FF1C4 ; =0x0000045C
	add r6, r5, r0
_021FF0F4:
	ldr r0, _021FF1C8 ; =0x000004D4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021FF1C0
	ldr r1, [sp, #8]
	ldr r0, _021FF1C4 ; =0x0000045C
	ldr r0, [r1, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, _021FF1CC ; =0x000004DC
	ldrh r1, [r5, r0]
	ldr r0, [sp, #0x10]
	sub r4, r0, r1
	add r0, r4, #0
	bl _dflt
	ldr r3, _021FF1D0 ; =0x40880000
	mov r2, #0
	bl _dgeq
	blo _021FF144
	add r0, r4, #0
	bl _dflt
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FF1D4 ; =0x40900000
	mov r0, #0
	bl _dsub
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FF1D8 ; =0x40540000
	mov r0, #0
	bl _dadd
	bl _dfix
	b _021FF17C
_021FF144:
	add r0, r4, #0
	bl _dflt
	ldr r3, _021FF1DC ; =0xC0880000
	mov r2, #0
	bl _dleq
	bhi _021FF178
	add r0, r4, #0
	bl _dflt
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FF1D4 ; =0x40900000
	mov r0, #0
	bl _dadd
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021FF1D8 ; =0x40540000
	mov r0, #0
	bl _dsub
	bl _dfix
	b _021FF17C
_021FF178:
	mov r0, #0x50
	sub r0, r0, r4
_021FF17C:
	mov r1, #0x1f
	mvn r1, r1
	cmp r0, r1
	blt _021FF1B0
	mov r1, #0x12
	lsl r1, r1, #4
	cmp r0, r1
	bgt _021FF1B0
	ldr r0, [sp, #0xc]
	cmp r0, #3
	bne _021FF1A2
	ldr r0, [sp, #0x2c]
	ldrb r2, [r0]
	add r1, r2, #1
	strb r1, [r0]
	ldr r0, [sp, #4]
	lsl r1, r2, #2
	str r6, [r0, r1]
	b _021FF1B0
_021FF1A2:
	ldr r0, [sp, #0x28]
	ldrb r2, [r0]
	add r1, r2, #1
	strb r1, [r0]
	ldr r0, [sp]
	lsl r1, r2, #2
	str r6, [r0, r1]
_021FF1B0:
	ldr r0, [sp, #8]
	add r7, r7, #1
	add r0, r0, #4
	add r5, #0xc
	add r6, r6, #4
	str r0, [sp, #8]
	cmp r7, #0x1e
	blt _021FF0F4
_021FF1C0:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FF1C4: .word 0x0000045C
_021FF1C8: .word 0x000004D4
_021FF1CC: .word 0x000004DC
_021FF1D0: .word 0x40880000
_021FF1D4: .word 0x40900000
_021FF1D8: .word 0x40540000
_021FF1DC: .word 0xC0880000
	thumb_func_end ov96_021FF0BC




	thumb_func_start ov96_021FF1E0
ov96_021FF1E0: ; 0x021FF1E0
	push {r4, r5}
	ldr r3, [r1]
	lsl r1, r3, #0x18
	lsr r4, r1, #0x18
	asr r1, r3, #8
	lsl r1, r1, #0x18
	asr r3, r3, #0x10
	lsr r1, r1, #0x18
	lsl r3, r3, #0x10
	lsr r5, r3, #0x10
	add r1, #0x20
	str r4, [r2]
	cmp r4, #3
	bne _021FF208
	sub r5, #0x20
	str r5, [r2, #4]
	sub r1, #0x20
	str r1, [r2, #8]
	pop {r4, r5}
	bx lr
_021FF208:
	cmp r4, #1
	bne _021FF210
	mov r3, #0x30
	b _021FF212
_021FF210:
	mov r3, #0x20
_021FF212:
	lsr r4, r3, #1
	sub r5, r5, r4
	sub r4, r1, r4
	str r5, [r2, #4]
	str r4, [r2, #8]
	add r1, r5, r3
	str r1, [r2, #0xc]
	str r4, [r2, #0x10]
	str r1, [r2, #0x14]
	add r1, r4, r3
	str r1, [r2, #0x18]
	str r5, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r3, [r2, #4]
	ldr r1, [r2, #8]
	str r3, [r2, #0x24]
	str r1, [r2, #0x28]
	ldr r3, [r2, #0xc]
	ldr r1, [r2, #0x10]
	str r3, [r2, #0x2c]
	str r1, [r2, #0x30]
	ldr r3, [r2, #0xc]
	ldr r1, [r2, #0x10]
	str r3, [r2, #0x34]
	str r1, [r2, #0x38]
	ldr r3, [r2, #0x14]
	ldr r1, [r2, #0x18]
	str r3, [r2, #0x3c]
	str r1, [r2, #0x40]
	ldr r3, [r2, #0x14]
	ldr r1, [r2, #0x18]
	str r3, [r2, #0x44]
	str r1, [r2, #0x48]
	ldr r3, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r3, [r2, #0x4c]
	str r1, [r2, #0x50]
	ldr r3, [r2, #0x1c]
	ldr r1, [r2, #0x20]
	str r3, [r2, #0x54]
	str r1, [r2, #0x58]
	ldr r3, [r2, #4]
	ldr r1, [r2, #8]
	str r3, [r2, #0x5c]
	str r1, [r2, #0x60]
	ldr r1, [r2, #0x28]
	sub r1, r1, r0
	str r1, [r2, #0x28]
	ldr r1, [r2, #0x30]
	sub r1, r1, r0
	str r1, [r2, #0x30]
	ldr r1, [r2, #0x34]
	add r1, r1, r0
	str r1, [r2, #0x34]
	ldr r1, [r2, #0x3c]
	add r1, r1, r0
	str r1, [r2, #0x3c]
	ldr r1, [r2, #0x48]
	add r1, r1, r0
	str r1, [r2, #0x48]
	ldr r1, [r2, #0x50]
	add r1, r1, r0
	str r1, [r2, #0x50]
	ldr r1, [r2, #0x54]
	sub r1, r1, r0
	str r1, [r2, #0x54]
	ldr r1, [r2, #0x5c]
	sub r0, r1, r0
	str r0, [r2, #0x5c]
	pop {r4, r5}
	bx lr
	thumb_func_end ov96_021FF1E0




	thumb_func_start ov96_021FF2A0
ov96_021FF2A0: ; 0x021FF2A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xa4
	str r0, [sp, #4]
	ldr r0, [sp, #0xb8]
	str r1, [sp, #8]
	str r0, [sp, #0xb8]
	add r0, r3, #0
	ldr r0, [r0]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	cmp r0, #3
	bne _021FF2BE
	add sp, #0xa4
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_021FF2BE:
	ldr r0, [sp, #4]
	add r7, r3, #0
	ldr r1, [r0]
	add r6, r3, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x24]
	ldr r0, [sp, #4]
	add r5, r3, #0
	ldr r1, [r0, #4]
	ldr r2, _021FF56C ; =ov96_0221C5FC
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x28]
	ldr r0, [sp, #8]
	add r3, sp, #0x34
	ldr r1, [r0]
	mov r4, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	add r7, #0x2c
	ldr r1, [r0, #4]
	add r6, #0x24
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x20]
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
_021FF30E:
	add r3, sp, #0x34
	add r2, sp, #0x94
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r0, sp, #0x2c
	str r0, [sp]
	add r0, r6, #0
	add r1, r7, #0
	add r2, sp, #0x24
	add r3, sp, #0x1c
	bl sub_02020F4C
	cmp r0, #0
	beq _021FF34C
	ldr r0, [sp, #0x2c]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0xb8]
	str r1, [r0]
	ldr r0, [sp, #0x30]
	lsl r1, r0, #0xc
	ldr r0, [sp, #0xb8]
	str r1, [r0, #4]
	mov r1, #0
	str r1, [r0, #8]
	add r0, sp, #0x94
	lsl r1, r4, #2
	add sp, #0xa4
	ldr r0, [r0, r1]
	pop {r4, r5, r6, r7, pc}
_021FF34C:
	mov r0, #0
	cmp r4, #0
	bne _021FF37C
	cmp r4, #2
	bne _021FF37C
	ldr r2, [sp, #0x28]
	ldr r1, [r5, #0x28]
	cmp r2, r1
	bne _021FF3A0
	ldr r2, [r5, #0x2c]
	ldr r3, [r5, #0x24]
	cmp r3, r2
	bge _021FF36A
	add r1, r3, #0
	b _021FF36E
_021FF36A:
	add r1, r2, #0
	add r2, r3, #0
_021FF36E:
	ldr r3, [sp, #0x24]
	cmp r1, r3
	bgt _021FF3A0
	cmp r3, r2
	bgt _021FF3A0
	mov r0, #1
	b _021FF3A0
_021FF37C:
	ldr r2, [sp, #0x24]
	ldr r1, [r5, #0x24]
	cmp r2, r1
	bne _021FF3A0
	ldr r2, [r5, #0x30]
	ldr r3, [r5, #0x28]
	cmp r3, r2
	bge _021FF390
	add r1, r3, #0
	b _021FF394
_021FF390:
	add r1, r2, #0
	add r2, r3, #0
_021FF394:
	ldr r3, [sp, #0x28]
	cmp r1, r3
	bgt _021FF3A0
	cmp r3, r2
	bgt _021FF3A0
	mov r0, #1
_021FF3A0:
	cmp r0, #0
	beq _021FF3C2
	ldr r2, [sp, #4]
	ldmia r2!, {r0, r1}
	str r2, [sp, #4]
	ldr r2, [sp, #0xb8]
	stmia r2!, {r0, r1}
	ldr r0, [sp, #4]
	str r2, [sp, #0xb8]
	ldr r1, [r0]
	add r0, r2, #0
	str r1, [r0]
	add r0, sp, #0x94
	lsl r1, r4, #2
	add sp, #0xa4
	ldr r0, [r0, r1]
	pop {r4, r5, r6, r7, pc}
_021FF3C2:
	add r4, r4, #1
	add r7, #0x10
	add r6, #0x10
	add r5, #0x10
	cmp r4, #4
	blt _021FF30E
	ldr r3, _021FF570 ; =ov96_0221C60C
	add r2, sp, #0x44
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [sp, #0xc]
	ldr r4, [sp, #0x10]
	mov r5, #0
	lsl r6, r0, #0xc
	add r7, sp, #0x6c
_021FF3E4:
	add r3, sp, #0x44
	add r2, sp, #0x84
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r4, #4]
	add r1, sp, #0x78
	lsl r0, r0, #0xc
	str r0, [sp, #0x78]
	ldr r0, [r4, #8]
	add r2, r7, #0
	lsl r0, r0, #0xc
	str r0, [sp, #0x7c]
	mov r0, #0
	str r0, [sp, #0x80]
	ldr r0, [sp, #8]
	bl VEC_Subtract
	add r0, r7, #0
	bl VEC_Mag
	cmp r0, r6
	bgt _021FF452
	ldr r3, [sp, #0xc]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	add r2, sp, #0x78
	lsl r3, r3, #0xc
	bl ov96_021FF67C
	add r4, r0, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #4]
	add r2, sp, #0x60
	bl VEC_Subtract
	ldr r2, [sp, #4]
	add r0, r4, #0
	add r1, sp, #0x60
	add r3, sp, #0x54
	bl VEC_MultAdd
	ldr r1, [sp, #0x54]
	ldr r0, [sp, #0xb8]
	str r1, [r0]
	ldr r1, [sp, #0x58]
	str r1, [r0, #4]
	mov r1, #0
	str r1, [r0, #8]
	add r0, sp, #0x84
	lsl r1, r5, #2
	add sp, #0xa4
	ldr r0, [r0, r1]
	pop {r4, r5, r6, r7, pc}
_021FF452:
	add r5, r5, #1
	add r4, #8
	cmp r5, #4
	blt _021FF3E4
	ldr r0, [sp, #8]
	ldr r1, [r0]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #4]
	lsl r0, r0, #0xc
	cmp r0, r1
	bgt _021FF564
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x14]
	lsl r0, r0, #0xc
	cmp r1, r0
	bgt _021FF564
	ldr r0, [sp, #8]
	ldr r1, [r0, #4]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #8]
	lsl r0, r0, #0xc
	cmp r0, r1
	bgt _021FF564
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x18]
	lsl r0, r0, #0xc
	cmp r1, r0
	bgt _021FF564
	ldr r3, [sp, #8]
	ldr r2, [sp, #0xb8]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0
	str r0, [r2]
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x10]
	ldr r0, [r0, #4]
	ldr r3, [r3, #0x14]
	str r0, [sp, #0x18]
	ldr r0, [sp, #8]
	str r3, [sp, #0x14]
	ldr r2, [r0]
	ldr r0, [sp, #0x18]
	lsl r3, r3, #0xc
	lsl r0, r0, #0xc
	sub r0, r0, r2
	sub r3, r3, r2
	mov ip, r1
	cmp r0, #0
	bge _021FF4BC
	sub r2, r1, #1
	mul r0, r2
_021FF4BC:
	cmp r3, #0
	bge _021FF4C6
	mov r2, #0
	mvn r2, r2
	mul r3, r2
_021FF4C6:
	cmp r0, r3
	bge _021FF4CE
	mov r6, #0xd
	b _021FF4D2
_021FF4CE:
	add r0, r3, #0
	mov r6, #0xb
_021FF4D2:
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #8]
	ldr r4, [sp, #0x10]
	ldr r2, [r2, #8]
	ldr r5, [r3, #4]
	ldr r7, [r4, #0x18]
	lsl r3, r2, #0xc
	lsl r4, r7, #0xc
	sub r3, r3, r5
	sub r4, r4, r5
	cmp r3, #0
	bge _021FF4F0
	mov r5, #0
	mvn r5, r5
	mul r3, r5
_021FF4F0:
	cmp r4, #0
	bge _021FF4FA
	mov r5, #0
	mvn r5, r5
	mul r4, r5
_021FF4FA:
	cmp r3, r4
	bge _021FF502
	mov r4, #0xa
	b _021FF506
_021FF502:
	add r3, r4, #0
	mov r4, #0xc
_021FF506:
	cmp r0, r3
	bgt _021FF512
	mov r0, #1
	mov ip, r0
	add r0, r6, #0
	b _021FF516
_021FF512:
	mov r1, #1
	add r0, r4, #0
_021FF516:
	mov r3, ip
	cmp r3, #0
	beq _021FF540
	cmp r6, #0xd
	bne _021FF530
	ldr r2, [sp, #0x18]
	ldr r1, [sp, #0xc]
	sub r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1]
	pop {r4, r5, r6, r7, pc}
_021FF530:
	ldr r2, [sp, #0x14]
	ldr r1, [sp, #0xc]
	add r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1]
	pop {r4, r5, r6, r7, pc}
_021FF540:
	cmp r1, #0
	beq _021FF566
	cmp r4, #0xa
	bne _021FF556
	ldr r1, [sp, #0xc]
	sub r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1, #4]
	pop {r4, r5, r6, r7, pc}
_021FF556:
	ldr r1, [sp, #0xc]
	add r1, r7, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1, #4]
	pop {r4, r5, r6, r7, pc}
_021FF564:
	mov r0, #0
_021FF566:
	add sp, #0xa4
	pop {r4, r5, r6, r7, pc}
	nop
_021FF56C: .word ov96_0221C5FC
_021FF570: .word ov96_0221C60C
	thumb_func_end ov96_021FF2A0

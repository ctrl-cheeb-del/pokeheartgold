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

	thumb_func_start ov96_021F27B8
ov96_021F27B8: ; 0x021F27B8
	push {r3, r4, r5, r6, lr}
	sub sp, #0x24
	add r5, r1, #0
	add r1, sp, #0x18
	add r4, r0, #0
	add r6, r2, #0
	bl VEC_Normalize
	add r0, r5, #0
	add r1, sp, #0xc
	bl VEC_Normalize
	add r0, sp, #0x18
	add r1, sp, #0xc
	bl VEC_DotProduct
	add r5, r0, #0
	add r0, r4, #0
	bl VEC_Mag
	add r2, r0, #0
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	asr r1, r5, #0x1f
	add r0, r5, #0
	asr r3, r2, #0x1f
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r0, r0, r2
	adc r1, r3
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	add r1, sp, #0xc
	add r2, sp, #0
	add r3, r6, #0
	bl VEC_MultAdd
	add sp, #0x24
	pop {r3, r4, r5, r6, pc}
	thumb_func_end ov96_021F27B8


	thumb_func_start ov96_021F2814
ov96_021F2814: ; 0x021F2814
	push {r4, lr}
	sub sp, #0x18
	add r4, r1, #0
	add r1, sp, #0xc
	bl VEC_Normalize
	add r0, r4, #0
	add r1, sp, #0
	bl VEC_Normalize
	add r0, sp, #0xc
	add r1, sp, #0
	bl VEC_DotProduct
	add sp, #0x18
	pop {r4, pc}
	thumb_func_end ov96_021F2814


	thumb_func_start ov96_021F2834
ov96_021F2834: ; 0x021F2834
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x48
	add r4, r0, #0
	ldr r0, _021F2950 ; =0x0000072B
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _021F2844
	b _021F294A
_021F2844:
	mov r0, #0
	add r1, sp, #0x10
	add r5, r0, #0
_021F284A:
	add r0, r0, #1
	strb r5, [r1]
	add r1, r1, #1
	cmp r0, #4
	blt _021F284A
	ldr r1, _021F2950 ; =0x0000072B
	add r7, r4, #0
	add r0, r1, #0
	strb r5, [r4, r1]
	add r0, #0x23
	strb r5, [r4, r0]
	add r1, #0x24
	strb r5, [r4, r1]
	add r7, #0x20
_021F2866:
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	add r6, r0, #0
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x1b
	lsl r0, r0, #4
	mul r0, r6
	add r2, r7, r0
	mov r0, #0x90
	mul r0, r1
	add r6, r2, r0
	ldr r0, [r6, #0x18]
	cmp r0, #1
	bne _021F28F6
	add r0, sp, #8
	str r0, [sp]
	ldr r1, [r6, #0x28]
	ldr r0, [r6]
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	ldr r2, [r6, #0x2c]
	asr r3, r2, #0xb
	lsr r3, r3, #0x14
	add r3, r2, r3
	asr r2, r3, #0xc
	add r3, sp, #0xc
	bl ov96_021EB06C
	mov r0, #0x73
	lsl r0, r0, #4
	ldrh r0, [r4, r0]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #8]
	lsl r0, r0, #0x18
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	lsr r0, r0, #0x18
	lsr r1, r1, #0x10
	lsr r2, r2, #0x10
	add r3, sp, #4
	bl ov96_021F3180
	add r2, r0, #0
	beq _021F28F6
	add r0, r6, #0
	add r0, #0x42
	ldrh r0, [r0]
	add r6, #0x42
	add r3, sp, #0x10
	add r0, r0, r2
	strh r0, [r6]
	add r0, sp, #4
	ldrb r1, [r0]
	add r0, sp, #0x10
	ldrb r0, [r0, r1]
	add r6, r0, #1
	strb r6, [r3, r1]
	mov r3, #0xc
	add r6, r1, #0
	mul r6, r3
	add r3, sp, #0x18
	add r3, r3, r6
	strb r5, [r0, r3]
	add r0, sp, #0x14
	strb r2, [r0, r1]
_021F28F6:
	add r5, r5, #1
	cmp r5, #0xc
	blt _021F2866
	mov r0, #0
	mov ip, r0
	add r7, sp, #0x18
	add r1, sp, #0x14
	add r2, sp, #0x10
_021F2906:
	ldrb r3, [r2]
	mov r0, #0
	cmp r3, #0
	ble _021F293A
_021F290E:
	ldr r3, _021F2954 ; =0x0000074E
	ldrb r6, [r7, r0]
	ldrb r3, [r4, r3]
	add r0, r0, #1
	add r5, r4, r3
	mov r3, #0x75
	lsl r3, r3, #4
	strb r6, [r5, r3]
	sub r3, r3, #2
	ldrb r3, [r4, r3]
	ldrb r6, [r1]
	add r5, r4, r3
	ldr r3, _021F2958 ; =0x0000075C
	strb r6, [r5, r3]
	sub r3, #0xe
	ldrb r3, [r4, r3]
	add r5, r3, #1
	ldr r3, _021F2954 ; =0x0000074E
	strb r5, [r4, r3]
	ldrb r3, [r2]
	cmp r0, r3
	blt _021F290E
_021F293A:
	mov r0, ip
	add r0, r0, #1
	add r7, #0xc
	add r1, r1, #1
	add r2, r2, #1
	mov ip, r0
	cmp r0, #4
	blt _021F2906
_021F294A:
	add sp, #0x48
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F2950: .word 0x0000072B
_021F2954: .word 0x0000074E
_021F2958: .word 0x0000075C
	thumb_func_end ov96_021F2834


	thumb_func_start ov96_021F295C
ov96_021F295C: ; 0x021F295C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	mov r4, #1
	cmp r5, #1
	blt _021F2978
_021F2968:
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	add r1, r6, #0
	bl ov96_021F2984
	add r4, r4, #1
	cmp r4, r5
	ble _021F2968
_021F2978:
	add r0, r6, #0
	mov r1, #1
	bl ScheduleBgTilemapBufferTransfer
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021F295C


	thumb_func_start ov96_021F2984
ov96_021F2984: ; 0x021F2984
	push {r3, lr}
	sub sp, #0x10
	cmp r0, #1
	blo _021F299A
	cmp r0, #6
	bhi _021F299A
	sub r0, r0, #1
	lsl r3, r0, #1
	add r3, #0x12
	mov r0, #2
	b _021F29DC
_021F299A:
	cmp r0, #0x10
	blo _021F29AE
	cmp r0, #0x1c
	bhi _021F29AE
	sub r0, #0x10
	lsl r2, r0, #1
	mov r0, #0x1a
	sub r3, r0, r2
	mov r0, #0x14
	b _021F29DC
_021F29AE:
	cmp r0, #0x26
	blo _021F29C0
	cmp r0, #0x2b
	bhs _021F29C0
	sub r0, #0x26
	lsl r0, r0, #1
	add r3, r0, #4
	mov r0, #2
	b _021F29DC
_021F29C0:
	cmp r0, #7
	blo _021F29D2
	cmp r0, #0xf
	bhi _021F29D2
	sub r0, r0, #7
	lsl r0, r0, #1
	mov r3, #0x1c
	add r0, r0, #4
	b _021F29DC
_021F29D2:
	sub r0, #0x1d
	lsl r2, r0, #1
	mov r0, #0x12
	mov r3, #2
	sub r0, r0, r2
_021F29DC:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	lsl r3, r3, #0x18
	str r0, [sp, #0xc]
	add r0, r1, #0
	mov r1, #1
	mov r2, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add sp, #0x10
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov96_021F2984


	thumb_func_start ov96_021F2A00
ov96_021F2A00: ; 0x021F2A00
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp, #8]
	add r0, #0x20
	str r0, [sp, #8]
	ldr r0, _021F2A80 ; =ov96_0221BDD4
	mov r1, #0
	str r1, [sp, #0xc]
	str r0, [sp, #4]
	mov r7, #2
_021F2A14:
	ldr r4, [sp, #8]
	ldr r5, [sp, #4]
	mov r6, #0
_021F2A1A:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	bne _021F2A56
	str r7, [r4, #0x18]
	add r0, sp, #0x10
	str r0, [sp]
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	ldr r0, [r4]
	add r3, sp, #0x14
	bl ov96_021EB0A4
	ldr r0, [sp, #0x14]
	add r3, r4, #0
	lsl r0, r0, #0xc
	str r0, [r4, #0x28]
	ldr r0, [sp, #0x10]
	add r2, r4, #0
	lsl r0, r0, #0xc
	add r3, #0x28
	str r0, [r4, #0x2c]
	ldmia r3!, {r0, r1}
	add r2, #0x1c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, r4, #0
	str r0, [r2]
	add r1, #0x40
	mov r0, #2
	strb r0, [r1]
_021F2A56:
	add r6, r6, #1
	add r4, #0x90
	add r5, r5, #4
	cmp r6, #3
	blt _021F2A1A
	mov r1, #0x1b
	ldr r0, [sp, #8]
	lsl r1, r1, #4
	add r0, r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r0, #0xc
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #4
	blt _021F2A14
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021F2A80: .word ov96_0221BDD4
	thumb_func_end ov96_021F2A00


	thumb_func_start ov96_021F2A84
ov96_021F2A84: ; 0x021F2A84
	mov r2, #0x1b
	lsl r2, r2, #4
	mul r2, r1
	mov r3, #0
	add r1, r0, r2
_021F2A8E:
	ldr r0, [r1, #0x38]
	cmp r0, #0
	beq _021F2A98
	mov r0, #0
	bx lr
_021F2A98:
	add r3, r3, #1
	add r1, #0x90
	cmp r3, #3
	blt _021F2A8E
	mov r0, #1
	bx lr
	thumb_func_end ov96_021F2A84


	thumb_func_start ov96_021F2AA4
ov96_021F2AA4: ; 0x021F2AA4
	add r1, r0, #0
	add r1, #0x44
	ldrb r1, [r1]
	cmp r1, #0
	beq _021F2AE0
	add r1, r0, #0
	add r1, #0x45
	ldrb r1, [r1]
	sub r2, r1, #1
	add r1, r0, #0
	add r1, #0x45
	strb r2, [r1]
	add r1, r0, #0
	add r1, #0x45
	ldrb r1, [r1]
	cmp r1, #0
	bne _021F2B20
	add r1, r0, #0
	mov r2, #0
	add r1, #0x45
	strb r2, [r1]
	add r1, r0, #0
	add r1, #0x44
	strb r2, [r1]
	add r1, r0, #0
	add r1, #0x8c
	ldrh r1, [r1]
	add r0, #0x8e
	strh r1, [r0]
	bx lr
_021F2AE0:
	add r1, r0, #0
	add r1, #0x8e
	ldrh r1, [r1]
	add r2, r1, #2
	add r1, r0, #0
	add r1, #0x8e
	strh r2, [r1]
	add r1, r0, #0
	add r1, #0x8c
	ldrh r2, [r1]
	add r1, r0, #0
	add r1, #0x8e
	ldrh r1, [r1]
	cmp r1, r2
	bls _021F2B04
	add r1, r0, #0
	add r1, #0x8e
	strh r2, [r1]
_021F2B04:
	add r1, r0, #0
	add r1, #0x8e
	ldrh r2, [r1]
	add r1, r0, #0
	add r1, #0x8c
	ldrh r1, [r1]
	cmp r2, r1
	bne _021F2B20
	add r1, r0, #0
	mov r2, #0
	add r1, #0x45
	strb r2, [r1]
	add r0, #0x44
	strb r2, [r0]
_021F2B20:
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021F2AA4


	thumb_func_start ov96_021F2B24
ov96_021F2B24: ; 0x021F2B24
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r1, r2, #0
	add r2, r3, #0
	ldr r4, [sp, #0x10]
	bl ov96_021E60D8
	ldrb r1, [r0]
	lsl r1, r1, #2
	ldr r2, [r5, r1]
	add r1, r4, #0
	add r1, #0x8a
	strh r2, [r1]
	ldrb r1, [r0, #3]
	lsl r1, r1, #2
	add r1, r5, r1
	ldr r2, [r1, #0x14]
	add r1, r4, #0
	add r1, #0x8c
	strh r2, [r1]
	ldrb r1, [r0, #3]
	lsl r1, r1, #2
	add r1, r5, r1
	ldr r2, [r1, #0x14]
	add r1, r4, #0
	add r1, #0x8e
	strh r2, [r1]
	ldrb r0, [r0, #1]
	add r4, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x28]
	strb r0, [r4]
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021F2B24


	thumb_func_start ov96_021F2B68
ov96_021F2B68: ; 0x021F2B68
	push {r3, r4, r5, lr}
	add r4, r0, #0
	strh r1, [r4, #0x1c]
	strh r2, [r4, #0x1e]
	mov r2, #0
	ldr r0, _021F2BA4 ; =ov96_021F2BB4
	strb r2, [r4]
	add r1, r4, #0
	add r5, r3, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #4]
	ldr r0, _021F2BA8 ; =ov96_021F2C04
	add r1, r4, #0
	mov r2, #1
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #0xc]
	mov r1, #2
	ldr r0, _021F2BAC ; =0x04000018
	str r5, [r4, #0x30]
	lsl r1, r1, #0x16
	str r1, [r0]
	ldr r0, _021F2BB0 ; =ov96_021F2CD0
	add r1, r4, #0
	mov r2, #2
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #8]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021F2BA4: .word ov96_021F2BB4
_021F2BA8: .word ov96_021F2C04
_021F2BAC: .word 0x04000018
_021F2BB0: .word ov96_021F2CD0
	thumb_func_end ov96_021F2B68


	thumb_func_start ov96_021F2BB4
ov96_021F2BB4: ; 0x021F2BB4
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _021F2BC6
	cmp r0, #1
	beq _021F2BDE
	pop {r3, r4, r5, pc}
_021F2BC6:
	ldr r0, [r4, #8]
	cmp r0, #0
	bne _021F2BFE
	ldr r0, _021F2C00 ; =ov96_021F2D68
	mov r2, #3
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #0x10]
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, pc}
_021F2BDE:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _021F2BFE
	mov r0, #0
	str r0, [r4, #4]
	strb r0, [r4]
	ldr r0, [r4, #0x30]
	bl PokeathlonCourse_GetDataCopyArea
	bl ov96_021E8A20
	mov r1, #1
	strb r1, [r0, #8]
	add r0, r5, #0
	bl SysTask_Destroy
_021F2BFE:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021F2C00: .word ov96_021F2D68
	thumb_func_end ov96_021F2BB4


	thumb_func_start ov96_021F2C04
ov96_021F2C04: ; 0x021F2C04
	push {r3, r4, lr}
	sub sp, #4
	add r4, r1, #0
	ldrb r1, [r4, #1]
	cmp r1, #0
	beq _021F2C1C
	cmp r1, #1
	beq _021F2C5A
	cmp r1, #2
	beq _021F2C86
	add sp, #4
	pop {r3, r4, pc}
_021F2C1C:
	ldrh r0, [r4, #0x18]
	add r0, r0, #1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x18]
	cmp r0, #5
	bhi _021F2C50
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	mov r0, #0xc
	mul r0, r1
	mov r1, #5
	bl _s32_div_f
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	add r0, r4, #4
	str r0, [sp]
	mov r3, #0xc
	ldr r0, _021F2CC8 ; =0x04000050
	mov r1, #0
	mov r2, #1
	sub r3, r3, r4
	bl G2x_SetBlendAlpha_
	add sp, #4
	pop {r3, r4, pc}
_021F2C50:
	ldrb r0, [r4, #1]
	add sp, #4
	add r0, r0, #1
	strb r0, [r4, #1]
	pop {r3, r4, pc}
_021F2C5A:
	ldrh r1, [r4, #0x1e]
	ldr r0, [r4, #0x20]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021F31F0
	ldrh r1, [r4, #0x1c]
	ldr r0, [r4, #0x20]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021F3298
	mov r0, #0
	strh r0, [r4, #0x18]
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
	ldr r0, _021F2CCC ; =0x0000089F
	bl PlaySE
	add sp, #4
	pop {r3, r4, pc}
_021F2C86:
	ldrh r1, [r4, #0x18]
	add r1, r1, #1
	strh r1, [r4, #0x18]
	ldrh r1, [r4, #0x18]
	cmp r1, #5
	bhi _021F2CB8
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	mov r0, #0xc
	mul r0, r1
	mov r1, #5
	bl _s32_div_f
	lsl r0, r0, #0x10
	lsr r3, r0, #0x10
	mov r0, #0x10
	sub r0, r0, r3
	str r0, [sp]
	ldr r0, _021F2CC8 ; =0x04000050
	mov r1, #0
	mov r2, #1
	bl G2x_SetBlendAlpha_
	add sp, #4
	pop {r3, r4, pc}
_021F2CB8:
	mov r1, #0
	str r1, [r4, #0xc]
	strh r1, [r4, #0x18]
	strb r1, [r4, #1]
	bl SysTask_Destroy
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_021F2CC8: .word 0x04000050
_021F2CCC: .word 0x0000089F
	thumb_func_end ov96_021F2C04


	thumb_func_start ov96_021F2CD0
ov96_021F2CD0: ; 0x021F2CD0
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _021F2CE6
	cmp r0, #1
	beq _021F2D16
	cmp r0, #2
	beq _021F2D2E
	pop {r3, r4, r5, pc}
_021F2CE6:
	ldrh r0, [r4, #0x1a]
	mov r1, #5
	add r0, r0, #1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x1a]
	lsl r0, r0, #7
	bl _s32_div_f
	mov r1, #0x80
	sub r0, r1, r0
	lsl r1, r0, #0x10
	ldr r0, _021F2D60 ; =0x01FF0000
	and r1, r0
	ldr r0, _021F2D64 ; =0x04000018
	str r1, [r0]
	ldrh r0, [r4, #0x1a]
	cmp r0, #5
	blo _021F2D5E
	mov r0, #0
	strh r0, [r4, #0x1a]
	ldrb r0, [r4, #2]
	add r0, r0, #1
	strb r0, [r4, #2]
	pop {r3, r4, r5, pc}
_021F2D16:
	ldrh r0, [r4, #0x1a]
	add r0, r0, #1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x1a]
	cmp r0, #0x14
	blo _021F2D5E
	mov r0, #0
	strh r0, [r4, #0x1a]
	ldrb r0, [r4, #2]
	add r0, r0, #1
	strb r0, [r4, #2]
	pop {r3, r4, r5, pc}
_021F2D2E:
	ldrh r0, [r4, #0x1a]
	mov r1, #5
	add r0, r0, #1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x1a]
	lsl r0, r0, #7
	neg r0, r0
	bl _s32_div_f
	lsl r1, r0, #0x10
	ldr r0, _021F2D60 ; =0x01FF0000
	and r1, r0
	ldr r0, _021F2D64 ; =0x04000018
	str r1, [r0]
	ldrh r0, [r4, #0x1a]
	cmp r0, #5
	blo _021F2D5E
	mov r0, #0
	strh r0, [r4, #0x1a]
	str r0, [r4, #8]
	strb r0, [r4, #2]
	add r0, r5, #0
	bl SysTask_Destroy
_021F2D5E:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021F2D60: .word 0x01FF0000
_021F2D64: .word 0x04000018
	thumb_func_end ov96_021F2CD0


	thumb_func_start ov96_021F2D68
ov96_021F2D68: ; 0x021F2D68
	push {r4, lr}
	mov r2, #0x24
	ldrsh r4, [r1, r2]
	ldrh r2, [r1, #0x26]
	lsl r3, r2, #2
	ldr r2, _021F2D94 ; =ov96_0221DB70
	ldr r2, [r2, r3]
	add r2, r4, r2
	strh r2, [r1, #0x24]
	ldrh r2, [r1, #0x26]
	add r2, r2, #1
	strh r2, [r1, #0x26]
	ldrh r2, [r1, #0x26]
	cmp r2, #0x12
	blo _021F2D92
	mov r2, #0
	strh r2, [r1, #0x24]
	str r2, [r1, #0x10]
	strh r2, [r1, #0x26]
	bl SysTask_Destroy
_021F2D92:
	pop {r4, pc}
	.balign 4, 0
_021F2D94: .word ov96_0221DB70
	thumb_func_end ov96_021F2D68


	thumb_func_start ov96_021F2D98
ov96_021F2D98: ; 0x021F2D98
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	mov r0, #0
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _021F2DC0
	ldr r0, [r4, #0x30]
	bl PokeathlonCourse_GetDataCopyArea
	bl ov96_021E8A20
	mov r1, #1
	strb r1, [r0, #8]
	ldr r0, [r4, #4]
	bl SysTask_Destroy
	mov r0, #0
	str r0, [r4, #4]
_021F2DC0:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _021F2DCE
	bl SysTask_Destroy
	mov r0, #0
	str r0, [r4, #8]
_021F2DCE:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _021F2DDC
	bl SysTask_Destroy
	mov r0, #0
	str r0, [r4, #0xc]
_021F2DDC:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _021F2DEA
	bl SysTask_Destroy
	mov r0, #0
	str r0, [r4, #0x10]
_021F2DEA:
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _021F2DF8
	bl SysTask_Destroy
	mov r0, #0
	str r0, [r4, #0x14]
_021F2DF8:
	mov r1, #2
	ldr r0, _021F2E28 ; =0x04000018
	lsl r1, r1, #0x16
	str r1, [r0]
	mov r1, #0
	strb r1, [r4]
	strb r1, [r4, #1]
	strb r1, [r4, #2]
	strh r1, [r4, #0x18]
	strh r1, [r4, #0x1a]
	strh r1, [r4, #0x26]
	strh r1, [r4, #0x2e]
	strh r1, [r4, #0x24]
	strh r1, [r4, #0x2c]
	mov r3, #0xc
	str r3, [r4, #0x28]
	mov r2, #4
	str r2, [sp]
	add r0, #0x38
	mov r2, #1
	bl G2x_SetBlendAlpha_
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_021F2E28: .word 0x04000018
	thumb_func_end ov96_021F2D98


	thumb_func_start ov96_021F2E2C
ov96_021F2E2C: ; 0x021F2E2C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne _021F2E44
	ldr r0, _021F2E48 ; =ov96_021F2E4C
	str r1, [r4, #0x28]
	add r1, r4, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #0x14]
_021F2E44:
	pop {r4, pc}
	nop
_021F2E48: .word ov96_021F2E4C
	thumb_func_end ov96_021F2E2C


	thumb_func_start ov96_021F2E4C
ov96_021F2E4C: ; 0x021F2E4C
	push {r4, lr}
	mov r2, #0x2c
	ldrsh r4, [r1, r2]
	ldrh r2, [r1, #0x2e]
	lsl r3, r2, #2
	ldr r2, _021F2E7C ; =ov96_0221DB5C
	ldr r2, [r2, r3]
	add r2, r4, r2
	strh r2, [r1, #0x2c]
	ldrh r2, [r1, #0x2e]
	add r2, r2, #1
	strh r2, [r1, #0x2e]
	ldrh r2, [r1, #0x2e]
	cmp r2, #5
	blo _021F2E7A
	mov r2, #0
	strh r2, [r1, #0x2c]
	str r2, [r1, #0x14]
	strh r2, [r1, #0x2e]
	mov r2, #0xc
	str r2, [r1, #0x28]
	bl SysTask_Destroy
_021F2E7A:
	pop {r4, pc}
	.balign 4, 0
_021F2E7C: .word ov96_0221DB5C
	thumb_func_end ov96_021F2E4C


	thumb_func_start ov96_021F2E80
ov96_021F2E80: ; 0x021F2E80
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	add r6, r0, #0
	ldr r0, [r5, #0x28]
	add r4, r3, #0
	add r7, r2, #0
	cmp r0, r4
	bne _021F2EC4
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	ldr r1, [sp, #4]
	add r0, r6, #0
	bl ov96_021E60D8
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _021F2EC4
	mov r1, #0
	str r1, [sp]
	mov r2, #0x2c
	ldrsh r2, [r5, r2]
	ldr r3, [sp, #0x20]
	add r0, r7, #0
	bl ov96_021EAED4
_021F2EC4:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F2E80


	thumb_func_start ov96_021F2EC8
ov96_021F2EC8: ; 0x021F2EC8
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4]
	ldr r2, _021F2EF8 ; =ov96_0221BC5C
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
_021F2EF8: .word ov96_0221BC5C
	thumb_func_end ov96_021F2EC8


	thumb_func_start ov96_021F2EFC
ov96_021F2EFC: ; 0x021F2EFC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	add r0, r5, #4
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r2, _021F2F74 ; =0x00000135
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
	mov r2, #0x9e
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021F2F78 ; =0x000F0E00
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
_021F2F74: .word 0x00000135
_021F2F78: .word 0x000F0E00
	thumb_func_end ov96_021F2EFC


	thumb_func_start ov96_021F2F7C
ov96_021F2F7C: ; 0x021F2F7C
	push {lr}
	sub sp, #0xc
	add r3, sp, #4
	str r3, [sp]
	asr r3, r1, #0xb
	lsr r3, r3, #0x14
	add r3, r1, r3
	asr r1, r3, #0xc
	asr r3, r2, #0xb
	lsr r3, r3, #0x14
	add r3, r2, r3
	asr r2, r3, #0xc
	add r3, sp, #8
	bl ov96_021EB06C
	ldr r0, [sp, #8]
	cmp r0, #0x10
	blt _021F2FAE
	cmp r0, #0xf0
	bge _021F2FAE
	ldr r0, [sp, #4]
	cmp r0, #0x10
	blt _021F2FAE
	cmp r0, #0xb0
	blt _021F2FB4
_021F2FAE:
	add sp, #0xc
	mov r0, #1
	pop {pc}
_021F2FB4:
	mov r0, #0
	add sp, #0xc
	pop {pc}
	.balign 4, 0
	thumb_func_end ov96_021F2F7C


	thumb_func_start ov96_021F2FBC
ov96_021F2FBC: ; 0x021F2FBC
	ldrh r3, [r1, #2]
	ldrh r2, [r0, #2]
	cmp r2, r3
	bls _021F2FCA
	mov r0, #0
	mvn r0, r0
	bx lr
_021F2FCA:
	cmp r2, r3
	bhs _021F2FD2
	mov r0, #1
	bx lr
_021F2FD2:
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r0, r1
	bhs _021F2FE0
	mov r0, #0
	mvn r0, r0
	bx lr
_021F2FE0:
	cmp r0, r1
	bls _021F2FE8
	mov r0, #1
	bx lr
_021F2FE8:
	mov r0, #0
	bx lr
	thumb_func_end ov96_021F2FBC


	thumb_func_start ov96_021F2FEC
ov96_021F2FEC: ; 0x021F2FEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r5, r0, #0
	add r6, r1, #0
	mov r4, #0
_021F2FF6:
	lsl r1, r4, #2
	add r0, sp, #0x14
	add r7, r0, r1
	strh r4, [r0, r1]
	add r0, r6, r4
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r0, sp, #0xc
	str r0, [sp]
	mov r0, #0x1b
	ldr r2, [sp, #8]
	lsl r0, r0, #4
	mul r0, r2
	mov r2, #0x90
	mul r2, r1
	add r0, r5, r0
	add r0, r2, r0
	ldr r2, [sp, #4]
	ldrb r1, [r6, r4]
	ldrb r2, [r2, #0xc]
	ldr r0, [r0, #0x20]
	add r3, sp, #0x10
	bl ov96_021EB06C
	ldr r0, [sp, #0xc]
	strh r0, [r7, #2]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #0xc
	blo _021F2FF6
	mov r0, #0x7f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	ldr r3, _021F30A0 ; =ov96_021F2FBC
	str r0, [sp]
	add r0, sp, #0x14
	mov r1, #0xc
	mov r2, #4
	bl MATH_QSort
	mov r4, #0
_021F305A:
	lsl r1, r4, #2
	add r0, sp, #0x14
	ldrh r0, [r0, r1]
	mov r1, #3
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	add r0, r7, #0
	bl _s32_div_f
	add r6, r0, #0
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x1b
	add r2, r1, #0
	lsl r0, r0, #4
	add r3, r6, #0
	mul r3, r0
	mov r0, #0x90
	mul r2, r0
	add r0, r5, r3
	add r0, r2, r0
	ldr r0, [r0, #0x20]
	add r1, r4, #6
	bl ov96_021EABA8
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #0xc
	blo _021F305A
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_021F30A0: .word ov96_021F2FBC
	thumb_func_end ov96_021F2FEC


	thumb_func_start ov96_021F30A4
ov96_021F30A4: ; 0x021F30A4
	push {r4, lr}
	mov r1, #0x84
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x84
	add r4, r0, #0
	bl MI_CpuFill8
	add r0, r4, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021F30A4

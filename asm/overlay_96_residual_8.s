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

	thumb_func_start ov96_021E7FA8
ov96_021E7FA8: ; 0x021E7FA8
	push {r3, lr}
	mov r1, #0x7e
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	ldrb r1, [r1, #0xc]
	cmp r1, #9
	bhi _021E8024
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E7FC2: ; jump table
	.short _021E7FD6 - _021E7FC2 - 2 ; case 0
	.short _021E7FDE - _021E7FC2 - 2 ; case 1
	.short _021E7FE6 - _021E7FC2 - 2 ; case 2
	.short _021E7FEE - _021E7FC2 - 2 ; case 3
	.short _021E7FF6 - _021E7FC2 - 2 ; case 4
	.short _021E7FFE - _021E7FC2 - 2 ; case 5
	.short _021E8006 - _021E7FC2 - 2 ; case 6
	.short _021E800E - _021E7FC2 - 2 ; case 7
	.short _021E8016 - _021E7FC2 - 2 ; case 8
	.short _021E801E - _021E7FC2 - 2 ; case 9
_021E7FD6:
	mov r1, #1
	bl ov96_021E8028
	pop {r3, pc}
_021E7FDE:
	mov r1, #2
	bl ov96_021E8028
	pop {r3, pc}
_021E7FE6:
	mov r1, #4
	bl ov96_021E8028
	pop {r3, pc}
_021E7FEE:
	mov r1, #8
	bl ov96_021E8028
	pop {r3, pc}
_021E7FF6:
	mov r1, #0x10
	bl ov96_021E8028
	pop {r3, pc}
_021E7FFE:
	mov r1, #0x11
	bl ov96_021E8028
	pop {r3, pc}
_021E8006:
	mov r1, #0x14
	bl ov96_021E8028
	pop {r3, pc}
_021E800E:
	mov r1, #6
	bl ov96_021E8028
	pop {r3, pc}
_021E8016:
	mov r1, #0xa
	bl ov96_021E8028
	pop {r3, pc}
_021E801E:
	mov r1, #9
	bl ov96_021E8028
_021E8024:
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov96_021E7FA8


	thumb_func_start ov96_021E8028
ov96_021E8028: ; 0x021E8028
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r6, r1, #0
	ldr r0, [r0]
	bl Save_Pokeathlon_Get
	add r7, r0, #0
	mov r4, #0
_021E803E:
	mov r2, #0x28
	mul r2, r4
	add r3, r5, r2
	mov r2, #0x81
	lsl r2, r2, #2
	ldrh r2, [r3, r2]
	add r0, r7, #0
	add r1, r6, #0
	bl PokeathlonSave_SetUnkDC_AtIndex
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E803E
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E8028


	thumb_func_start ov96_021E8060
ov96_021E8060: ; 0x021E8060
	mov r3, #0
	mov r2, #0x2c
_021E8064:
	add r1, r3, #0
	mul r1, r2
	add r1, r0, r1
	ldrh r1, [r1, #6]
	cmp r1, #0
	bne _021E8074
	mov r0, #0
	bx lr
_021E8074:
	add r1, r3, #1
	lsl r1, r1, #0x18
	lsr r3, r1, #0x18
	cmp r3, #5
	blo _021E8064
	mov r0, #1
	bx lr
	.balign 4, 0
	thumb_func_end ov96_021E8060


	thumb_func_start ov96_021E8084
ov96_021E8084: ; 0x021E8084
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	ldr r0, [r0]
	bl Save_Pokeathlon_Get
	add r7, r0, #0
	mov r4, #0
_021E8098:
	mov r0, #0x28
	mul r0, r4
	add r1, r6, r0
	mov r0, #0x81
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	sub r5, r0, #1
	add r0, r7, #0
	bl PokeathlonSave_GetUnkDC
	ldrb r0, [r0, r5]
	cmp r0, #0x1f
	bne _021E80B6
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E80B6:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E8098
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021E8084


	thumb_func_start ov96_021E80C4
ov96_021E80C4: ; 0x021E80C4
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0x7e
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	ldr r0, [r0]
	bl Save_Pokeathlon_Get
	bl PokeathlonSave_GetRecordsSolo2
	ldr r6, _021E8110 ; =ov96_0221A894
	ldr r7, _021E8114 ; =_0221A7D8
	add r5, r0, #0
	mov r4, #0
_021E80DE:
	mov r0, #0x2c
	mul r0, r4
	ldrh r1, [r5, r0]
	ldr r0, _021E8118 ; =0x0000FFFF
	cmp r1, r0
	bne _021E80EE
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E80EE:
	lsl r0, r4, #1
	ldrh r0, [r6, r0]
	ldrb r2, [r7, r4]
	bl ov96_021E7D30
	cmp r0, #0
	bne _021E8100
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E8100:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #0xa
	blo _021E80DE
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E8110: .word ov96_0221A894
_021E8114: .word _0221A7D8
_021E8118: .word 0x0000FFFF
	thumb_func_end ov96_021E80C4


	thumb_func_start ov96_021E811C
ov96_021E811C: ; 0x021E811C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r2, #0
	mov r1, #0xa
	strb r1, [r5]
	ldrb r6, [r0, #0xc]
	ldr r0, [r0, #4]
	mov r7, #0
	cmp r0, #1
	bne _021E8160
	cmp r6, #0xa
	bhi _021E815A
	add r0, r6, r6
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E8140: ; jump table
	.short _021E815A - _021E8140 - 2 ; case 0
	.short _021E815A - _021E8140 - 2 ; case 1
	.short _021E815A - _021E8140 - 2 ; case 2
	.short _021E815A - _021E8140 - 2 ; case 3
	.short _021E815A - _021E8140 - 2 ; case 4
	.short _021E8156 - _021E8140 - 2 ; case 5
	.short _021E8156 - _021E8140 - 2 ; case 6
	.short _021E8156 - _021E8140 - 2 ; case 7
	.short _021E8156 - _021E8140 - 2 ; case 8
	.short _021E8156 - _021E8140 - 2 ; case 9
	.short _021E8156 - _021E8140 - 2 ; case 10
_021E8156:
	mov r7, #1
	b _021E8182
_021E815A:
	bl GF_AssertFail
	b _021E8182
_021E8160:
	cmp r6, #4
	bhi _021E817E
	add r0, r6, r6
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E8170: ; jump table
	.short _021E817A - _021E8170 - 2 ; case 0
	.short _021E817A - _021E8170 - 2 ; case 1
	.short _021E817A - _021E8170 - 2 ; case 2
	.short _021E817A - _021E8170 - 2 ; case 3
	.short _021E817A - _021E8170 - 2 ; case 4
_021E817A:
	mov r7, #1
	b _021E8182
_021E817E:
	bl GF_AssertFail
_021E8182:
	cmp r7, #0
	beq _021E81CE
	cmp r6, #0xa
	bne _021E81B4
	bl LCRandom
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	mov r2, #0
	cmp r4, #0
	bls _021E81CE
	ldr r1, _021E81D0 ; =ov96_0221A95C
	lsl r0, r0, #2
	add r1, r1, r0
_021E81A4:
	ldrb r0, [r1, r2]
	strb r0, [r5, r2]
	add r0, r2, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r2, r4
	blo _021E81A4
	pop {r3, r4, r5, r6, r7, pc}
_021E81B4:
	mov r2, #0
	cmp r4, #0
	bls _021E81CE
	ldr r1, _021E81D4 ; =ov96_0221A934
	lsl r0, r6, #2
	add r1, r1, r0
_021E81C0:
	ldrb r0, [r1, r2]
	strb r0, [r5, r2]
	add r0, r2, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r2, r4
	blo _021E81C0
_021E81CE:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E81D0: .word ov96_0221A95C
_021E81D4: .word ov96_0221A934
	thumb_func_end ov96_021E811C


	thumb_func_start ov96_021E81D8
ov96_021E81D8: ; 0x021E81D8
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r1, #0
	ldr r0, [r4, #4]
	add r1, sp, #4
	add r2, sp, #0
	bl ov96_021EAEC8
	ldr r0, [r4, #8]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	add r1, sp, #8
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	ldr r0, [sp]
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	bl Sprite_SetMatrix
	ldr r0, [r4, #4]
	bl ov96_021EB120
	cmp r0, #0
	ldr r0, [r4, #8]
	beq _021E821E
	mov r1, #1
	bl Sprite_SetDrawFlag
	add sp, #0x14
	pop {r3, r4, pc}
_021E821E:
	mov r1, #0
	bl Sprite_SetDrawFlag
	add sp, #0x14
	pop {r3, r4, pc}
	thumb_func_end ov96_021E81D8


	thumb_func_start ov96_021E8228
ov96_021E8228: ; 0x021E8228
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r7, r2, #0
	str r3, [sp]
	ldr r6, [sp, #0x18]
	add r1, r3, #0
	bne _021E825E
	bl ov96_021E5F24
	cmp r4, r0
	beq _021E8244
	bl GF_AssertFail
_021E8244:
	cmp r6, #1
	beq _021E824C
	bl GF_AssertFail
_021E824C:
	mov r0, #0x8b
	lsl r0, r0, #4
	ldr r2, [r5, r0]
	ldr r1, _021E830C ; =0x0000270F
	cmp r2, r1
	bhs _021E830A
	add r1, r2, #1
	str r1, [r5, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021E825E:
	cmp r7, #3
	blo _021E8266
	bl GF_AssertFail
_021E8266:
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	ldr r0, [r0, #0x10]
	cmp r0, #0
	bne _021E829A
	add r0, r5, #0
	bl ov96_021E5F24
	cmp r0, #0
	beq _021E8280
	bl GF_AssertFail
_021E8280:
	ldr r2, _021E8310 ; =0x0000072C
	lsl r1, r6, #0x18
	add r3, r5, r2
	mov r2, #0x60
	mul r2, r4
	add r3, r3, r2
	lsl r2, r7, #5
	ldr r0, [sp]
	lsr r1, r1, #0x18
	add r2, r3, r2
	bl ov96_021E8340
	pop {r3, r4, r5, r6, r7, pc}
_021E829A:
	add r0, r5, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E82EA
	add r0, r5, #0
	bl PokeathlonCourse_GetParticipantCount
	cmp r4, r0
	blo _021E82C8
	ldr r2, _021E8310 ; =0x0000072C
	lsl r1, r6, #0x18
	add r3, r5, r2
	mov r2, #0x60
	mul r2, r4
	add r3, r3, r2
	lsl r2, r7, #5
	ldr r0, [sp]
	lsr r1, r1, #0x18
	add r2, r3, r2
	bl ov96_021E8340
	pop {r3, r4, r5, r6, r7, pc}
_021E82C8:
	add r0, r5, #0
	bl ov96_021E5F24
	cmp r4, r0
	beq _021E82D6
	bl GF_AssertFail
_021E82D6:
	ldr r2, _021E8314 ; =0x00000B44
	lsl r1, r6, #0x18
	add r3, r5, r2
	lsl r2, r7, #5
	ldr r0, [sp]
	lsr r1, r1, #0x18
	add r2, r3, r2
	bl ov96_021E8340
	pop {r3, r4, r5, r6, r7, pc}
_021E82EA:
	add r0, r5, #0
	bl ov96_021E5F24
	cmp r4, r0
	beq _021E82F8
	bl GF_AssertFail
_021E82F8:
	ldr r2, _021E8314 ; =0x00000B44
	lsl r1, r6, #0x18
	add r3, r5, r2
	lsl r2, r7, #5
	ldr r0, [sp]
	lsr r1, r1, #0x18
	add r2, r3, r2
	bl ov96_021E8340
_021E830A:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E830C: .word 0x0000270F
_021E8310: .word 0x0000072C
_021E8314: .word 0x00000B44
	thumb_func_end ov96_021E8228

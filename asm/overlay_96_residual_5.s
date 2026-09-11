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

	thumb_func_start ov96_021E67AC
ov96_021E67AC: ; 0x021E67AC
	push {r3, lr}
	mov r2, #0x7d
	lsl r2, r2, #2
	ldr r1, [r0, r2]
	cmp r1, #0
	beq _021E67C2
	sub r2, #0x14
	ldr r2, [r0, r2]
	mov r1, #0
	ldr r2, [r2, #4]
	blx r2
_021E67C2:
	pop {r3, pc}
	thumb_func_end ov96_021E67AC


	thumb_func_start ov96_021E67C4
ov96_021E67C4: ; 0x021E67C4
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r5, #1
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E67FC
	ldr r1, _021E6810 ; =0x0000072A
	mov r2, #0x7e
	lsl r2, r2, #2
	ldr r0, [r4, r2]
	sub r2, #0x10
	ldrb r1, [r4, r1]
	add r2, r4, r2
	bl ov96_021E811C
	bl ov96_021E99F4
	mov r3, #0x7a
	lsl r3, r3, #2
	add r1, r4, r3
	add r3, #0xa0
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x16
	bl ov96_021E87B4
	add r5, r0, #0
_021E67FC:
	cmp r5, #0
	beq _021E680A
	add r0, r4, #0
	mov r1, #0x26
	mov r2, #1
	bl PokeathlonCourse_SetStateField07_IfDifferent
_021E680A:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_021E6810: .word 0x0000072A
	thumb_func_end ov96_021E67C4


	thumb_func_start ov96_021E6814
ov96_021E6814: ; 0x021E6814
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0xa
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl OverlayManager_Run
	cmp r0, #0
	beq _021E686C
	mov r0, #0xa
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl OverlayManager_Delete
	mov r1, #0x7e
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	ldr r2, [r0, #4]
	cmp r2, #0
	bne _021E6860
	add r1, r1, #4
	ldr r1, [r4, r1]
	cmp r1, #0
	beq _021E6852
	mov r1, #1
	strb r1, [r0, #0xe]
	add r0, r4, #0
	mov r1, #0x25
	bl PokeathlonCourse_SetStateField07
	b _021E686C
_021E6852:
	mov r1, #0
	strb r1, [r0, #0xe]
	add r0, r4, #0
	mov r1, #3
	bl PokeathlonCourse_SetStateField07
	b _021E686C
_021E6860:
	mov r1, #0
	strb r1, [r0, #0xe]
	add r0, r4, #0
	mov r1, #2
	bl PokeathlonCourse_SetStateField07
_021E686C:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov96_021E6814


	thumb_func_start ov96_021E6870
ov96_021E6870: ; 0x021E6870
	push {r3, r4, r5, lr}
	add r5, r1, #0
	ldrb r2, [r5]
	add r4, r0, #0
	cmp r2, #3
	bhi _021E694C
	add r1, r2, r2
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E6888: ; jump table
	.short _021E6890 - _021E6888 - 2 ; case 0
	.short _021E68B2 - _021E6888 - 2 ; case 1
	.short _021E68C2 - _021E6888 - 2 ; case 2
	.short _021E692A - _021E6888 - 2 ; case 3
_021E6890:
	mov r0, #0x1e
	ldr r1, _021E6950 ; =ov96_0221A8BC
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r1, #0
	add r0, #0xd
	strb r1, [r4, r0]
	mov r1, #0xf3
	lsl r1, r1, #2
	ldr r0, _021E6954 ; =ov96_0221DA68
	add r1, r4, r1
	bl PokeathlonCourse_InitStateInfo
	ldrb r0, [r5]
	add r0, r0, #1
	strb r0, [r5]
	b _021E694C
_021E68B2:
	bl PokeathlonCourse_RunSubStateLoop
	cmp r0, #0
	beq _021E694C
	ldrb r0, [r5]
	add r0, r0, #1
	strb r0, [r5]
	b _021E694C
_021E68C2:
	mov r0, #0xf3
	lsl r0, r0, #2
	add r1, r4, r0
	ldr r3, [r1]
	cmp r3, #0
	bne _021E68D4
	add r0, r2, #1
	strb r0, [r5]
	b _021E694C
_021E68D4:
	add r2, r0, #0
	sub r2, #0x18
	ldr r3, [r4, r2]
	add r2, r0, #0
	sub r2, #8
	add r2, r4, r2
	cmp r3, r2
	bne _021E68F0
	add r2, r0, #0
	sub r2, #0x18
	str r1, [r4, r2]
	mov r1, #0
	sub r0, #0xc
	str r1, [r4, r0]
_021E68F0:
	ldr r3, _021E6958 ; =0x000003D1
	add r0, r4, #0
	sub r2, r3, #5
	add r1, r4, r3
	add r3, r3, #1
	ldrb r3, [r4, r3]
	ldr r2, [r4, r2]
	lsl r3, r3, #2
	ldr r2, [r2, r3]
	blx r2
	cmp r0, #0
	beq _021E694C
	add r0, r4, #0
	mov r1, #0
	bl PokeathlonCourse_SetField1F4
	mov r0, #0xf1
	lsl r0, r0, #2
	add r1, r0, #0
	add r2, r4, r0
	sub r1, #0x10
	str r2, [r4, r1]
	mov r1, #0
	sub r0, r0, #4
	str r1, [r4, r0]
	ldrb r0, [r5]
	add r0, r0, #1
	strb r0, [r5]
	b _021E694C
_021E692A:
	mov r2, #0x1e
	lsl r2, r2, #4
	ldr r2, [r4, r2]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r0, #0x79
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E6944
	bl GF_AssertFail
_021E6944:
	add r0, r4, #0
	mov r1, #3
	bl PokeathlonCourse_SetStateField07
_021E694C:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E6950: .word ov96_0221A8BC
_021E6954: .word ov96_0221DA68
_021E6958: .word 0x000003D1
	thumb_func_end ov96_021E6870


	thumb_func_start ov96_021E695C
ov96_021E695C: ; 0x021E695C
	push {r4, lr}
	add r4, r0, #0
	mov r0, #2
	mov r1, #0
	lsl r0, r0, #8
	str r1, [r4, r0]
	bl ov96_021E99F8
	mov r3, #2
	lsl r3, r3, #8
	add r1, r4, r3
	add r3, #0x88
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x17
	bl ov96_021E87EC
	cmp r0, #0
	beq _021E698A
	add r0, r4, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
_021E698A:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021E695C


	thumb_func_start ov96_021E6990
ov96_021E6990: ; 0x021E6990
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r1, #0
	bl PokeathlonCourse_GetParticipantData
	add r4, r0, #0
	bl ov96_021E99FC
	add r6, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetSystem
	add r3, r0, #0
	mov r0, #0x18
	add r1, r4, #0
	add r2, r6, #0
	bl ov96_021E87EC
	cmp r0, #0
	beq _021E69C0
	add r0, r5, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
_021E69C0:
	mov r0, #0
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021E6990


	thumb_func_start ov96_021E69C4
ov96_021E69C4: ; 0x021E69C4
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r5, #1
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E69EA
	bl ov96_021E9A04
	ldr r1, _021E69FC ; =0x000005DC
	mov r3, #0xa2
	lsl r3, r3, #2
	add r2, r0, #0
	ldr r1, [r4, r1]
	ldr r3, [r4, r3]
	mov r0, #0x19
	bl ov96_021E87EC
	add r5, r0, #0
_021E69EA:
	cmp r5, #0
	beq _021E69F8
	add r0, r4, #0
	mov r1, #0x26
	mov r2, #6
	bl PokeathlonCourse_SetStateField07_IfDifferent
_021E69F8:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E69FC: .word 0x000005DC
	thumb_func_end ov96_021E69C4


	thumb_func_start ov96_021E6A00
ov96_021E6A00: ; 0x021E6A00
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r0, [r0]
	bl Save_Pokeathlon_Get
	bl PokeathlonSave_GetAgainUnkB00
	add r5, r0, #0
	mov r0, #9
	lsl r0, r0, #8
	add r3, r4, r0
	mov r2, #0xe
_021E6A1E:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E6A1E
	ldr r0, [r5]
	str r0, [r3]
	bl ov96_021E9A10
	mov r3, #0xa2
	mov r1, #9
	lsl r3, r3, #2
	lsl r1, r1, #8
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x1a
	add r1, r4, r1
	bl ov96_021E87EC
	cmp r0, #0
	beq _021E6A4E
	add r0, r4, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
_021E6A4E:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021E6A00


	thumb_func_start ov96_021E6A54
ov96_021E6A54: ; 0x021E6A54
	push {r4, lr}
	ldr r1, _021E6A88 ; =0x00000D2C
	add r4, r0, #0
	mov r2, #1
	str r2, [r4, r1]
	bl PokeathlonCourse_ResetDataCopyArea
	mov r0, #0x1e
	ldr r1, _021E6A8C ; =ov96_0221A808
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r1, #0
	add r0, #0xd
	strb r1, [r4, r0]
	mov r1, #0xf3
	lsl r1, r1, #2
	ldr r0, _021E6A90 ; =ov96_0221DA50
	add r1, r4, r1
	bl PokeathlonCourse_InitStateInfo
	add r0, r4, #0
	mov r1, #8
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_021E6A88: .word 0x00000D2C
_021E6A8C: .word ov96_0221A808
_021E6A90: .word ov96_0221DA50
	thumb_func_end ov96_021E6A54


	thumb_func_start ov96_021E6A94
ov96_021E6A94: ; 0x021E6A94
	push {r4, lr}
	add r4, r0, #0
	bl PokeathlonCourse_RunSubStateLoop
	cmp r0, #0
	beq _021E6AE0
	add r0, r4, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r1, r0, #0
	mov r2, #0
	add r1, #0x24
	strb r2, [r1]
	mov r1, #1
	add r0, #0x4c
	strb r1, [r0]
	add r0, r4, #0
	bl PokeathlonCourse_GetSystem
	mov r1, #1
	bl ov96_021E87B0
	add r0, r4, #0
	mov r1, #6
	bl PokeathlonCourse_SetStateTransitionType
	add r0, r4, #0
	mov r1, #9
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	bl Sound_SetScene
	ldr r1, _021E6AE4 ; =0x0000046F
	mov r0, #0x19
	mov r2, #0
	bl Sound_SetSceneAndPlayBGM
_021E6AE0:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_021E6AE4: .word 0x0000046F
	thumb_func_end ov96_021E6A94


	thumb_func_start ov96_021E6AE8
ov96_021E6AE8: ; 0x021E6AE8
	push {r3, r4, r5, lr}
	mov r1, #0xf3
	add r4, r0, #0
	lsl r1, r1, #2
	add r2, r4, r1
	ldr r3, [r2]
	cmp r3, #0
	bne _021E6B02
	mov r1, #0xa
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E6B02:
	add r0, r1, #0
	sub r0, #0x18
	ldr r3, [r4, r0]
	add r0, r1, #0
	sub r0, #8
	add r0, r4, r0
	cmp r3, r0
	bne _021E6B1E
	add r0, r1, #0
	sub r0, #0x18
	str r2, [r4, r0]
	mov r0, #0
	sub r1, #0xc
	str r0, [r4, r1]
_021E6B1E:
	ldr r3, _021E6BBC ; =0x000003D1
	add r0, r4, #0
	sub r2, r3, #5
	add r1, r4, r3
	add r3, r3, #1
	ldrb r3, [r4, r3]
	ldr r2, [r4, r2]
	lsl r3, r3, #2
	ldr r2, [r2, r3]
	blx r2
	cmp r0, #0
	beq _021E6B5A
	add r0, r4, #0
	mov r1, #0
	bl PokeathlonCourse_SetField1F4
	mov r0, #0xf1
	lsl r0, r0, #2
	add r1, r0, #0
	add r2, r4, r0
	sub r1, #0x10
	str r2, [r4, r1]
	mov r1, #0
	sub r0, r0, #4
	str r1, [r4, r0]
	add r0, r4, #0
	mov r1, #0xa
	bl PokeathlonCourse_SetStateField07
	b _021E6BB6
_021E6B5A:
	add r0, r4, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E6BA0
	bl ov96_021E9A14
	mov r3, #0xad
	lsl r3, r3, #2
	add r1, r4, r3
	sub r3, #0x2c
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x1b
	bl ov96_021E87B4
	mov r0, #0xb7
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov96_021E8A20
	add r5, r0, #0
	mov r0, #0xa3
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov96_021E8A20
	mov r2, #0x28
_021E6B92:
	ldrb r1, [r0]
	add r0, r0, #1
	strb r1, [r5]
	add r5, r5, #1
	sub r2, r2, #1
	bne _021E6B92
	b _021E6BB6
_021E6BA0:
	bl ov96_021E9A14
	mov r3, #0xa3
	lsl r3, r3, #2
	add r1, r4, r3
	sub r3, r3, #4
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x1b
	bl ov96_021E87B4
_021E6BB6:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_021E6BBC: .word 0x000003D1
	thumb_func_end ov96_021E6AE8


	thumb_func_start ov96_021E6BC0
ov96_021E6BC0: ; 0x021E6BC0
	push {r4, lr}
	mov r2, #0x1e
	add r4, r0, #0
	lsl r2, r2, #4
	ldr r2, [r4, r2]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r0, #0x79
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E6BDE
	bl GF_AssertFail
_021E6BDE:
	add r0, r4, #0
	mov r1, #0xb
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021E6BC0


	thumb_func_start ov96_021E6BEC
ov96_021E6BEC: ; 0x021E6BEC
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x1e
	ldr r1, _021E6C18 ; =ov96_0221A8E4
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r1, #0
	add r0, #0xd
	strb r1, [r4, r0]
	mov r1, #0xf3
	lsl r1, r1, #2
	ldr r0, _021E6C1C ; =ov96_0221DA6C
	add r1, r4, r1
	bl PokeathlonCourse_InitStateInfo
	add r0, r4, #0
	mov r1, #0xc
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, pc}
	nop
_021E6C18: .word ov96_0221A8E4
_021E6C1C: .word ov96_0221DA6C
	thumb_func_end ov96_021E6BEC


	thumb_func_start ov96_021E6C20
ov96_021E6C20: ; 0x021E6C20
	push {r4, lr}
	add r4, r0, #0
	bl PokeathlonCourse_RunSubStateLoop
	cmp r0, #0
	beq _021E6C3C
	add r0, r4, #0
	mov r1, #7
	bl PokeathlonCourse_SetStateTransitionType
	add r0, r4, #0
	mov r1, #0xd
	bl PokeathlonCourse_SetStateField07
_021E6C3C:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov96_021E6C20


	thumb_func_start ov96_021E6C40
ov96_021E6C40: ; 0x021E6C40
	push {r4, lr}
	mov r1, #0xf3
	add r4, r0, #0
	lsl r1, r1, #2
	add r2, r4, r1
	ldr r3, [r2]
	cmp r3, #0
	bne _021E6C5A
	mov r1, #0xe
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, pc}
_021E6C5A:
	add r0, r1, #0
	sub r0, #0x18
	ldr r3, [r4, r0]
	add r0, r1, #0
	sub r0, #8
	add r0, r4, r0
	cmp r3, r0
	bne _021E6C76
	add r0, r1, #0
	sub r0, #0x18
	str r2, [r4, r0]
	mov r0, #0
	sub r1, #0xc
	str r0, [r4, r1]
_021E6C76:
	ldr r3, _021E6CB4 ; =0x000003D1
	add r0, r4, #0
	sub r2, r3, #5
	add r1, r4, r3
	add r3, r3, #1
	ldrb r3, [r4, r3]
	ldr r2, [r4, r2]
	lsl r3, r3, #2
	ldr r2, [r2, r3]
	blx r2
	cmp r0, #0
	beq _021E6CB0
	add r0, r4, #0
	mov r1, #0
	bl PokeathlonCourse_SetField1F4
	mov r0, #0xf1
	lsl r0, r0, #2
	add r1, r0, #0
	add r2, r4, r0
	sub r1, #0x10
	str r2, [r4, r1]
	mov r1, #0
	sub r0, r0, #4
	str r1, [r4, r0]
	add r0, r4, #0
	mov r1, #0xe
	bl PokeathlonCourse_SetStateField07
_021E6CB0:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_021E6CB4: .word 0x000003D1
	thumb_func_end ov96_021E6C40


	thumb_func_start ov96_021E6CB8
ov96_021E6CB8: ; 0x021E6CB8
	push {r4, lr}
	mov r2, #0x1e
	add r4, r0, #0
	lsl r2, r2, #4
	ldr r2, [r4, r2]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r0, #0x79
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E6CD6
	bl GF_AssertFail
_021E6CD6:
	add r0, r4, #0
	mov r1, #0xf
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021E6CB8


	thumb_func_start ov96_021E6CE4
ov96_021E6CE4: ; 0x021E6CE4
	push {r4, r5, r6, lr}
	mov r1, #0x1f
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	ldr r6, _021E6D40 ; =0x0000FFFF
	lsl r1, r1, #2
	add r2, r4, r1
	mov r1, #0xf6
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	ldr r2, _021E6D44 ; =0x00000728
	lsl r5, r1, #0x18
	mov r1, #0
	strb r1, [r4, r2]
	ldr r3, _021E6D48 ; =0x00000D2A
	add r2, r2, #3
	strh r6, [r4, r3]
	strb r1, [r4, r2]
	add r3, #0x42
	str r1, [r4, r3]
	bl PokeathlonCourse_ResetDataCopyArea
	ldr r0, _021E6D4C ; =ov96_0221DA28
	lsr r2, r5, #0x16
	ldr r1, [r0, r2]
	mov r0, #0x1e
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r1, #0
	add r0, #0xd
	strb r1, [r4, r0]
	ldr r0, _021E6D50 ; =_0221DA00
	mov r1, #0xf3
	lsl r1, r1, #2
	ldr r0, [r0, r2]
	add r1, r4, r1
	bl PokeathlonCourse_InitStateInfo
	add r0, r4, #0
	mov r1, #0x10
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, r5, r6, pc}
	nop
_021E6D40: .word 0x0000FFFF
_021E6D44: .word 0x00000728
_021E6D48: .word 0x00000D2A
_021E6D4C: .word ov96_0221DA28
_021E6D50: .word _0221DA00
	thumb_func_end ov96_021E6CE4


	thumb_func_start ov96_021E6D54
ov96_021E6D54: ; 0x021E6D54
	push {r4, lr}
	add r4, r0, #0
	bl PokeathlonCourse_RunSubStateLoop
	cmp r0, #0
	beq _021E6DD8
	add r0, r4, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r1, r0, #0
	mov r2, #0
	add r1, #0x24
	strb r2, [r1]
	mov r1, #1
	add r0, #0x4c
	strb r1, [r0]
	add r0, r4, #0
	bl PokeathlonCourse_GetSystem
	mov r1, #1
	bl ov96_021E87B0
	add r0, r4, #0
	mov r1, #8
	bl PokeathlonCourse_SetStateTransitionType
	mov r0, #0x1f
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	ldr r0, _021E6DDC ; =0x0000072A
	ldrb r0, [r4, r0]
	sub r0, r0, #1
	cmp r1, r0
	bne _021E6DAA
	mov r0, #0
	bl Sound_SetScene
	ldr r1, _021E6DE0 ; =0x00000472
	mov r0, #0x18
	mov r2, #0
	bl Sound_SetSceneAndPlayBGM
	b _021E6DBA
_021E6DAA:
	mov r0, #0
	bl Sound_SetScene
	ldr r1, _021E6DE4 ; =0x00000471
	mov r0, #0x18
	mov r2, #0
	bl Sound_SetSceneAndPlayBGM
_021E6DBA:
	mov r0, #7
	mov r1, #1
	bl sub_020053A8
	add r0, r4, #0
	mov r1, #0x11
	bl PokeathlonCourse_SetStateField07
	mov r0, #0x5c
	bl GF_heap_c_dummy_return_true
	cmp r0, #0
	bne _021E6DD8
	bl GF_AssertFail
_021E6DD8:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_021E6DDC: .word 0x0000072A
_021E6DE0: .word 0x00000472
_021E6DE4: .word 0x00000471
	thumb_func_end ov96_021E6D54


	thumb_func_start ov96_021E6DE8
ov96_021E6DE8: ; 0x021E6DE8
	push {r4, lr}
	mov r1, #0x3b
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	cmp r1, #0
	beq _021E6E2C
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E6E22
	mov r2, #0xe9
	lsl r2, r2, #2
	mov r3, #0xa2
	ldr r1, [r4, r2]
	add r2, #8
	lsl r3, r3, #2
	ldr r2, [r4, r2]
	ldr r3, [r4, r3]
	mov r0, #0x1c
	bl ov96_021E87EC
	cmp r0, #0
	beq _021E6E32
	add r0, r4, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
	b _021E6E32
_021E6E22:
	add r0, r4, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
	b _021E6E32
_021E6E2C:
	mov r1, #0x12
	bl PokeathlonCourse_SetStateField07
_021E6E32:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021E6DE8


	thumb_func_start ov96_021E6E38
ov96_021E6E38: ; 0x021E6E38
	push {r3, r4, r5, lr}
	mov r1, #0xf3
	add r4, r0, #0
	lsl r1, r1, #2
	add r2, r4, r1
	ldr r3, [r2]
	cmp r3, #0
	bne _021E6E52
	mov r1, #0x18
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E6E52:
	add r0, r1, #0
	sub r0, #0x18
	ldr r3, [r4, r0]
	add r0, r1, #0
	sub r0, #8
	add r0, r4, r0
	cmp r3, r0
	bne _021E6E6E
	add r0, r1, #0
	sub r0, #0x18
	str r2, [r4, r0]
	mov r0, #0
	sub r1, #0xc
	str r0, [r4, r1]
_021E6E6E:
	ldr r3, _021E6F14 ; =0x000003D1
	add r0, r4, #0
	sub r2, r3, #5
	add r1, r4, r3
	add r3, r3, #1
	ldrb r3, [r4, r3]
	ldr r2, [r4, r2]
	lsl r3, r3, #2
	ldr r2, [r2, r3]
	blx r2
	cmp r0, #0
	beq _021E6EB2
	add r0, r4, #0
	mov r1, #0
	bl PokeathlonCourse_SetField1F4
	mov r0, #0xf1
	lsl r0, r0, #2
	add r1, r0, #0
	add r2, r4, r0
	sub r1, #0x10
	str r2, [r4, r1]
	mov r1, #0
	sub r0, r0, #4
	str r1, [r4, r0]
	add r0, r4, #0
	mov r1, #0x10
	bl PokeathlonCourse_SetStateTransitionType
	add r0, r4, #0
	mov r1, #0x13
	bl PokeathlonCourse_SetStateField07
	b _021E6F0E
_021E6EB2:
	add r0, r4, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E6EF8
	bl ov96_021E9A14
	mov r3, #0xad
	lsl r3, r3, #2
	add r1, r4, r3
	sub r3, #0x2c
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x1b
	bl ov96_021E87B4
	mov r0, #0xb7
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov96_021E8A20
	add r5, r0, #0
	mov r0, #0xa3
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov96_021E8A20
	mov r2, #0x28
_021E6EEA:
	ldrb r1, [r0]
	add r0, r0, #1
	strb r1, [r5]
	add r5, r5, #1
	sub r2, r2, #1
	bne _021E6EEA
	b _021E6F0E
_021E6EF8:
	bl ov96_021E9A14
	mov r3, #0xa3
	lsl r3, r3, #2
	add r1, r4, r3
	sub r3, r3, #4
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x1b
	bl ov96_021E87B4
_021E6F0E:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_021E6F14: .word 0x000003D1
	thumb_func_end ov96_021E6E38

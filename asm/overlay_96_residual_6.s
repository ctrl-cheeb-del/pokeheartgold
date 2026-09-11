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

	thumb_func_start ov96_021E6F2C
ov96_021E6F2C: ; 0x021E6F2C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	mov r1, #0x1e
	add r7, r0, #0
	lsl r1, r1, #4
	ldr r2, [r7, r1]
	ldr r2, [r2, #0x10]
	cmp r2, #0
	beq _021E6FD0
	add r1, #0xac
	add r0, r7, r1
	bl ov96_021E8A20
	add r4, r0, #0
	add r0, r7, #0
	bl ov96_021E5F24
	lsl r0, r0, #2
	add r2, r7, r0
	mov r0, #0x5e
	lsl r0, r0, #4
	ldrh r1, [r2, r0]
	add r0, r0, #2
	strh r1, [r4]
	ldrh r0, [r2, r0]
	strh r0, [r4, #2]
	bl ov96_021E9A14
	mov r3, #0xa3
	lsl r3, r3, #2
	add r1, r7, r3
	sub r3, r3, #4
	add r2, r0, #0
	ldr r3, [r7, r3]
	mov r0, #0x1d
	bl ov96_021E87B4
	str r0, [sp, #4]
	cmp r0, #0
	beq _021E6FE6
	add r0, r7, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E6FE6
	add r0, r7, #0
	bl PokeathlonCourse_GetUnkConstant4
	add r6, r0, #0
	add r0, r7, #0
	bl PokeathlonCourse_GetParticipantCount
	str r0, [sp]
	cmp r0, #4
	bge _021E6FE6
	mov r0, #0x5e
	lsl r0, r0, #4
	add r1, r7, r0
	ldr r0, [sp]
	lsl r0, r0, #2
	add r4, r1, r0
	ldr r0, [sp]
	add r5, r0, #0
	mul r5, r6
_021E6FAC:
	mov r0, #0xad
	lsl r0, r0, #2
	add r0, r7, r0
	bl ov96_021E8A20
	add r0, r0, r5
	add r1, r4, #0
	add r2, r6, #0
	bl memcpy
	ldr r0, [sp]
	add r4, r4, #4
	add r0, r0, #1
	add r5, r5, r6
	str r0, [sp]
	cmp r0, #4
	blt _021E6FAC
	b _021E6FE6
_021E6FD0:
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E6FE2
	add r0, r7, #0
	bl ov96_021E75E4
	str r0, [sp, #4]
	b _021E6FE6
_021E6FE2:
	mov r0, #1
	str r0, [sp, #4]
_021E6FE6:
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _021E6FF4
	add r0, r7, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
_021E6FF4:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021E6F2C


	thumb_func_start ov96_021E6FFC
ov96_021E6FFC: ; 0x021E6FFC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r4, r0, #0
	bl ov96_021E9A14
	add r6, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetSystem
	add r4, #0x28
	add r3, r0, #0
	mov r0, #0x1e
	add r1, r4, #0
	add r2, r6, #0
	bl ov96_021E87B4
	cmp r0, #0
	beq _021E702C
	add r0, r5, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
_021E702C:
	mov r0, #0
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021E6FFC


	thumb_func_start ov96_021E7030
ov96_021E7030: ; 0x021E7030
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0xdf
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov96_021E8A20
	mov r1, #0x5f
	lsl r1, r1, #4
	add r3, r4, r1
	mov r2, #0x12
_021E7046:
	ldrh r1, [r0]
	add r0, r0, #2
	strh r1, [r3]
	add r3, r3, #2
	sub r2, r2, #1
	bne _021E7046
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	ldr r2, [r0, #8]
	cmp r2, #0
	beq _021E7064
	add r0, r4, #0
	mov r1, #0
	blx r2
_021E7064:
	mov r1, #0x1f
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	add r0, r4, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021E7658
	add r0, r4, #0
	mov r1, #0x17
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov96_021E7030


	thumb_func_start ov96_021E7080
ov96_021E7080: ; 0x021E7080
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x5c
	bl GF_heap_c_dummy_return_true
	cmp r0, #0
	bne _021E7092
	bl GF_AssertFail
_021E7092:
	mov r2, #0x1e
	lsl r2, r2, #4
	ldr r2, [r4, r2]
	add r0, r4, #0
	ldr r2, [r2, #0xc]
	mov r1, #0
	blx r2
	mov r0, #0x79
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E70AE
	bl GF_AssertFail
_021E70AE:
	ldr r1, _021E70EC ; =0x0000072A
	mov r0, #0x1f
	lsl r0, r0, #4
	ldrb r1, [r4, r1]
	ldr r2, [r4, r0]
	cmp r2, r1
	bge _021E70DA
	sub r0, #0x10
	ldr r0, [r4, r0]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021E70D0
	add r0, r4, #0
	mov r1, #0x19
	bl PokeathlonCourse_SetStateField07
	b _021E70E6
_021E70D0:
	add r0, r4, #0
	mov r1, #0x18
	bl PokeathlonCourse_SetStateField07
	b _021E70E6
_021E70DA:
	add r1, r2, #1
	str r1, [r4, r0]
	add r0, r4, #0
	mov r1, #0x1d
	bl PokeathlonCourse_SetStateField07
_021E70E6:
	mov r0, #0
	pop {r4, pc}
	nop
_021E70EC: .word 0x0000072A
	thumb_func_end ov96_021E7080


	thumb_func_start ov96_021E70F0
ov96_021E70F0: ; 0x021E70F0
	push {r3, lr}
	mov r1, #0x1f
	lsl r1, r1, #4
	ldr r2, [r0, r1]
	add r2, r2, #1
	str r2, [r0, r1]
	ldr r2, [r0, r1]
	ldr r1, _021E7118 ; =0x0000072A
	ldrb r1, [r0, r1]
	cmp r2, r1
	blt _021E710E
	mov r1, #0x1d
	bl PokeathlonCourse_SetStateField07
	b _021E7114
_021E710E:
	mov r1, #0xb
	bl PokeathlonCourse_SetStateField07
_021E7114:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_021E7118: .word 0x0000072A
	thumb_func_end ov96_021E70F0


	thumb_func_start ov96_021E711C
ov96_021E711C: ; 0x021E711C
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x1e
	ldr r1, _021E7148 ; =ov96_0221A86C
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r1, #0
	add r0, #0xd
	strb r1, [r4, r0]
	mov r1, #0xf3
	lsl r1, r1, #2
	ldr r0, _021E714C ; =ov96_0221DC24
	add r1, r4, r1
	bl PokeathlonCourse_InitStateInfo
	add r0, r4, #0
	mov r1, #0x1a
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, pc}
	nop
_021E7148: .word ov96_0221A86C
_021E714C: .word ov96_0221DC24
	thumb_func_end ov96_021E711C


	thumb_func_start ov96_021E7150
ov96_021E7150: ; 0x021E7150
	push {r4, lr}
	add r4, r0, #0
	bl PokeathlonCourse_RunSubStateLoop
	cmp r0, #0
	beq _021E718C
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
	mov r1, #0xb
	bl PokeathlonCourse_SetStateTransitionType
	add r0, r4, #0
	mov r1, #0x1b
	bl PokeathlonCourse_SetStateField07
_021E718C:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov96_021E7150


	thumb_func_start ov96_021E7190
ov96_021E7190: ; 0x021E7190
	push {r3, r4, r5, lr}
	mov r1, #0xf3
	add r4, r0, #0
	lsl r1, r1, #2
	add r2, r4, r1
	ldr r3, [r2]
	cmp r3, #0
	bne _021E71AA
	mov r1, #0x1c
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E71AA:
	add r0, r1, #0
	sub r0, #0x18
	ldr r3, [r4, r0]
	add r0, r1, #0
	sub r0, #8
	add r0, r4, r0
	cmp r3, r0
	bne _021E71C6
	add r0, r1, #0
	sub r0, #0x18
	str r2, [r4, r0]
	mov r0, #0
	sub r1, #0xc
	str r0, [r4, r1]
_021E71C6:
	ldr r3, _021E7264 ; =0x000003D1
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
	beq _021E7202
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
	mov r1, #0x1c
	bl PokeathlonCourse_SetStateField07
	b _021E725E
_021E7202:
	add r0, r4, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E7248
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
_021E723A:
	ldrb r1, [r0]
	add r0, r0, #1
	strb r1, [r5]
	add r5, r5, #1
	sub r2, r2, #1
	bne _021E723A
	b _021E725E
_021E7248:
	bl ov96_021E9A14
	mov r3, #0xa3
	lsl r3, r3, #2
	add r1, r4, r3
	sub r3, r3, #4
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x1b
	bl ov96_021E87B4
_021E725E:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_021E7264: .word 0x000003D1
	thumb_func_end ov96_021E7190


	thumb_func_start ov96_021E7268
ov96_021E7268: ; 0x021E7268
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
	beq _021E7286
	bl GF_AssertFail
_021E7286:
	add r0, r4, #0
	mov r1, #0x18
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021E7268


	thumb_func_start ov96_021E7294
ov96_021E7294: ; 0x021E7294
	push {r4, lr}
	add r4, r0, #0
	bl PokeathlonCourse_ResetDataCopyArea
	mov r0, #0x1e
	ldr r1, _021E72C4 ; =ov96_0221A844
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r1, #0
	add r0, #0xd
	strb r1, [r4, r0]
	mov r1, #0xf3
	lsl r1, r1, #2
	ldr r0, _021E72C8 ; =ov96_0221DA5C
	add r1, r4, r1
	bl PokeathlonCourse_InitStateInfo
	add r0, r4, #0
	mov r1, #0x20
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, pc}
	nop
_021E72C4: .word ov96_0221A844
_021E72C8: .word ov96_0221DA5C
	thumb_func_end ov96_021E7294


	thumb_func_start ov96_021E72CC
ov96_021E72CC: ; 0x021E72CC
	push {r4, lr}
	add r4, r0, #0
	bl PokeathlonCourse_RunSubStateLoop
	cmp r0, #0
	beq _021E7318
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
	mov r1, #0xc
	bl PokeathlonCourse_SetStateTransitionType
	add r0, r4, #0
	mov r1, #0x21
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	bl Sound_SetScene
	ldr r1, _021E731C ; =0x00000474
	mov r0, #0x19
	mov r2, #0
	bl Sound_SetSceneAndPlayBGM
_021E7318:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_021E731C: .word 0x00000474
	thumb_func_end ov96_021E72CC


	thumb_func_start ov96_021E7320
ov96_021E7320: ; 0x021E7320
	push {r3, r4, r5, lr}
	mov r1, #0xf3
	add r4, r0, #0
	lsl r1, r1, #2
	add r2, r4, r1
	ldr r3, [r2]
	cmp r3, #0
	bne _021E733A
	mov r1, #0x22
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E733A:
	add r0, r1, #0
	sub r0, #0x18
	ldr r3, [r4, r0]
	add r0, r1, #0
	sub r0, #8
	add r0, r4, r0
	cmp r3, r0
	bne _021E7356
	add r0, r1, #0
	sub r0, #0x18
	str r2, [r4, r0]
	mov r0, #0
	sub r1, #0xc
	str r0, [r4, r1]
_021E7356:
	ldr r3, _021E73F4 ; =0x000003D1
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
	beq _021E7392
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
	mov r1, #0x22
	bl PokeathlonCourse_SetStateField07
	b _021E73EE
_021E7392:
	add r0, r4, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021E73D8
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
_021E73CA:
	ldrb r1, [r0]
	add r0, r0, #1
	strb r1, [r5]
	add r5, r5, #1
	sub r2, r2, #1
	bne _021E73CA
	b _021E73EE
_021E73D8:
	bl ov96_021E9A14
	mov r3, #0xa3
	lsl r3, r3, #2
	add r1, r4, r3
	sub r3, r3, #4
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x1b
	bl ov96_021E87B4
_021E73EE:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_021E73F4: .word 0x000003D1
	thumb_func_end ov96_021E7320


	thumb_func_start ov96_021E73F8
ov96_021E73F8: ; 0x021E73F8
	push {r3, r4, r5, r6, r7, lr}
	mov r2, #0x1e
	add r5, r0, #0
	lsl r2, r2, #4
	ldr r2, [r5, r2]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r0, #0x79
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021E7416
	bl GF_AssertFail
_021E7416:
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0]
	bl Save_ApricornBox_Get
	add r7, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0]
	bl Save_PlayerData_GetProfile
	str r0, [sp]
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0]
	bl Save_Pokeathlon_Get
	bl PokeathlonSave_GetUnkB00
	add r6, r0, #0
	bl sub_02031B10
	lsl r4, r0, #2
	mov r0, #0xa1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl Heap_AllocAtEnd
	ldr r1, _021E74A4 ; =0x00000D68
	add r2, r4, #0
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	mov r1, #0
	bl memset
	mov r3, #0xa1
	lsl r3, r3, #2
	ldr r1, [sp]
	ldr r2, [r6, #0x70]
	ldr r3, [r5, r3]
	add r0, r7, #0
	bl sub_020320E0
	ldr r1, _021E74A8 ; =0x00000D64
	str r0, [r5, r1]
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0, #4]
	cmp r0, #1
	bne _021E7496
	add r0, r5, #0
	mov r1, #0xe
	bl PokeathlonCourse_SetStateTransitionType
	add r0, r5, #0
	mov r1, #0x23
	bl PokeathlonCourse_SetStateField07
	b _021E749E
_021E7496:
	add r0, r5, #0
	mov r1, #0x25
	bl PokeathlonCourse_SetStateField07
_021E749E:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E74A4: .word 0x00000D68
_021E74A8: .word 0x00000D64
	thumb_func_end ov96_021E73F8


	thumb_func_start ov96_021E74AC
ov96_021E74AC: ; 0x021E74AC
	push {r4, lr}
	add r4, r0, #0
	bl ov96_021E5F24
	bl ov96_021E9A18
	mov r3, #0xa2
	ldr r1, _021E74DC ; =0x00000B44
	lsl r3, r3, #2
	add r2, r0, #0
	ldr r3, [r4, r3]
	mov r0, #0x1f
	add r1, r4, r1
	bl ov96_021E87EC
	cmp r0, #0
	beq _021E74D6
	add r0, r4, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
_021E74D6:
	mov r0, #0
	pop {r4, pc}
	nop
_021E74DC: .word 0x00000B44
	thumb_func_end ov96_021E74AC


	thumb_func_start ov96_021E74E0
ov96_021E74E0: ; 0x021E74E0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r1, #0
	bl PokeathlonCourse_GetFieldData_AtIndex
	add r4, r0, #0
	bl ov96_021E9A1C
	add r6, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetSystem
	add r3, r0, #0
	mov r0, #0x20
	add r1, r4, #0
	add r2, r6, #0
	bl ov96_021E87EC
	cmp r0, #0
	beq _021E7510
	add r0, r5, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
_021E7510:
	mov r0, #0
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021E74E0


	thumb_func_start ov96_021E7514
ov96_021E7514: ; 0x021E7514
	push {r4, lr}
	add r4, r0, #0
	bl sub_02031B10
	ldr r1, _021E7540 ; =0x00000D64
	mov r3, #0xa2
	lsl r3, r3, #2
	add r2, r0, #0
	ldr r1, [r4, r1]
	ldr r3, [r4, r3]
	mov r0, #0x21
	bl ov96_021E87EC
	cmp r0, #0
	beq _021E753A
	add r0, r4, #0
	mov r1, #0x26
	bl PokeathlonCourse_SetStateField07
_021E753A:
	mov r0, #0
	pop {r4, pc}
	nop
_021E7540: .word 0x00000D64
	thumb_func_end ov96_021E7514


	thumb_func_start ov96_021E7544
ov96_021E7544: ; 0x021E7544
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r0, [r0]
	bl Save_ApricornBox_Get
	add r4, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetParticipantCount
	add r6, r0, #0
	bl sub_0203769C
	ldr r1, _021E758C ; =0x00000D68
	add r3, r0, #0
	ldr r1, [r5, r1]
	add r0, r4, #0
	add r2, r6, #0
	bl sub_020321A0
	mov r0, #0x5c
	bl GF_heap_c_dummy_return_true
	cmp r0, #0
	bne _021E757E
	bl GF_AssertFail
_021E757E:
	add r0, r5, #0
	mov r1, #0x25
	bl PokeathlonCourse_SetStateField07
	mov r0, #0
	pop {r4, r5, r6, pc}
	nop
_021E758C: .word 0x00000D68
	thumb_func_end ov96_021E7544


	thumb_func_start ov96_021E7590
ov96_021E7590: ; 0x021E7590
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x5c
	bl GF_heap_c_dummy_return_true
	cmp r0, #0
	bne _021E75A2
	bl GF_AssertFail
_021E75A2:
	mov r0, #0x7e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	bne _021E75B4
	add r0, r4, #0
	bl ov96_021E7718
_021E75B4:
	mov r0, #1
	pop {r4, pc}
	thumb_func_end ov96_021E7590

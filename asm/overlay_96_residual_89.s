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

	thumb_func_start ov96_02207800
ov96_02207800: ; 0x02207800
	push {r4, lr}
	add r4, r0, #0
	add r0, #0xb4
	ldrh r0, [r0]
	mov r1, #0x14
	add r0, r0, #1
	bl _s32_div_f
	add r4, #0xb4
	strh r1, [r4]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_02207800


	thumb_func_start ov96_02207818
ov96_02207818: ; 0x02207818
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r1, #0
	add r2, r5, #0
_02207820:
	ldr r0, [r2]
	cmp r0, #0
	bne _02207862
	mov r0, #0x14
	add r4, r1, #0
	mul r4, r0
	add r0, r5, #0
	add r0, #0xb4
	ldrh r1, [r0]
	add r0, r5, r4
	str r1, [r0, #0xc]
	add r1, r5, #0
	add r1, #0xb4
	ldrh r1, [r1]
	lsl r1, r1, #2
	add r1, r5, r1
	add r1, #0x64
	ldrh r1, [r1]
	strh r1, [r0, #0x10]
	add r1, r5, #0
	add r1, #0xb4
	ldrh r1, [r1]
	lsl r1, r1, #2
	add r1, r5, r1
	add r1, #0x66
	ldrh r1, [r1]
	strh r1, [r0, #0x12]
	add r0, r5, #0
	bl ov96_02207800
	mov r0, #1
	str r0, [r5, r4]
	pop {r3, r4, r5, pc}
_02207862:
	add r1, r1, #1
	add r2, #0x14
	cmp r1, #5
	blt _02207820
	bl GF_AssertFail
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02207818


	thumb_func_start ov96_02207870
ov96_02207870: ; 0x02207870
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _022078A8 ; =0x0000061A
	mov r4, #0
	ldrh r1, [r5, r0]
	mov r0, #5
	sub r6, r0, r1
	cmp r6, #0
	ble _022078A4
	ldr r7, _022078A8 ; =0x0000061A
_02207884:
	ldr r0, _022078AC ; =0x00000564
	add r0, r5, r0
	bl ov96_02207818
	ldrh r0, [r5, r7]
	add r0, r0, #1
	strh r0, [r5, r7]
	ldr r0, _022078A8 ; =0x0000061A
	ldrh r0, [r5, r0]
	cmp r0, #5
	bls _0220789E
	bl GF_AssertFail
_0220789E:
	add r4, r4, #1
	cmp r4, r6
	blt _02207884
_022078A4:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022078A8: .word 0x0000061A
_022078AC: .word 0x00000564
	thumb_func_end ov96_02207870


	thumb_func_start ov96_022078B0
ov96_022078B0: ; 0x022078B0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r7, r0, #0
	add r5, r1, #0
	mov r6, #0
	add r0, r2, #0
	strb r6, [r0]
	add r0, r5, #0
	str r0, [sp, #4]
	add r0, #0x58
	str r2, [sp]
	add r4, r7, #0
	str r0, [sp, #4]
_022078CA:
	ldr r0, [r4]
	cmp r0, #0
	beq _02207978
	ldr r0, [r4, #0xc]
	lsl r0, r0, #2
	add r0, r7, r0
	add r0, #0x64
	ldrh r0, [r0]
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	lsl r0, r0, #2
	add r0, r7, r0
	add r0, #0x66
	ldrh r0, [r0]
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	add r0, r5, #0
	add r0, #0xb1
	ldrb r0, [r0]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl ov96_021EAF8C
	add r2, r0, #0
	mov r3, #2
	ldr r0, [sp, #4]
	add r1, sp, #8
	lsl r2, r2, #0xc
	lsl r3, r3, #0xe
	bl ov96_02207990
	cmp r0, #0
	beq _0220796E
	add r0, r5, #0
	add r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #9
	blo _02207932
	add r5, #0xb3
	ldrb r0, [r5, r6]
	cmp r0, #0
	bne _0220792C
	ldr r0, [sp]
	mov r1, #1
	strb r1, [r0]
	strb r1, [r5, r6]
_0220792C:
	add sp, #0x14
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_02207932:
	add r0, r5, r6
	mov r1, #1
	add r0, #0xb3
	strb r1, [r0]
	mov r0, #0x14
	mov r1, #0
	mul r0, r6
	str r1, [r7, r0]
	add r0, r5, #0
	add r0, #0xaa
	ldrb r0, [r0]
	add r5, #0xaa
	add r0, r0, #1
	strb r0, [r5]
	add r0, r7, #0
	add r0, #0xb6
	ldrh r0, [r0]
	cmp r0, #0
	bne _0220795C
	bl GF_AssertFail
_0220795C:
	add r0, r7, #0
	add r0, #0xb6
	ldrh r0, [r0]
	add r7, #0xb6
	add sp, #0x14
	sub r0, r0, #1
	strh r0, [r7]
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0220796E:
	add r1, r5, r6
	add r1, #0xb3
	mov r0, #0
	strb r0, [r1]
	b _02207980
_02207978:
	add r1, r5, r6
	add r1, #0xb3
	mov r0, #0
	strb r0, [r1]
_02207980:
	add r6, r6, #1
	add r4, #0x14
	cmp r6, #5
	blt _022078CA
	mov r0, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_022078B0


	thumb_func_start ov96_02207990
ov96_02207990: ; 0x02207990
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r2, #0
	add r2, sp, #0
	add r4, r3, #0
	bl VEC_Subtract
	add r0, sp, #0
	bl VEC_Mag
	add r1, r5, r4
	cmp r0, r1
	bge _022079B0
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_022079B0:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02207990


	thumb_func_start ov96_022079B8
ov96_022079B8: ; 0x022079B8
	push {r3, r4, lr}
	sub sp, #0x24
	add r1, sp, #0x18
	mov r4, #1
	bl VEC_Normalize
	add r0, sp, #0x18
	bl VEC_Mag
	cmp r0, #0
	beq _02207A2A
	ldr r4, _02207A30 ; =ov96_0221CAC8
	add r3, sp, #0xc
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	add r1, sp, #0
	str r0, [r3]
	ldr r0, [sp, #0x1c]
	str r0, [sp]
	ldr r0, [sp, #0x18]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #4]
	add r0, r2, #0
	bl CalcAngleBetweenVecs
	mov r2, #2
	lsl r2, r2, #0xc
	cmp r0, r2
	bls _02207A00
	mov r1, #0xe
	lsl r1, r1, #0xc
	cmp r0, r1
	blo _02207A04
_02207A00:
	mov r4, #4
	b _02207A2A
_02207A04:
	cmp r0, r2
	bls _02207A14
	mov r1, #6
	lsl r1, r1, #0xc
	cmp r0, r1
	bhs _02207A14
	mov r4, #2
	b _02207A2A
_02207A14:
	mov r1, #6
	lsl r1, r1, #0xc
	cmp r0, r1
	blo _02207A28
	mov r1, #0xa
	lsl r1, r1, #0xc
	cmp r0, r1
	bhi _02207A28
	mov r4, #3
	b _02207A2A
_02207A28:
	mov r4, #1
_02207A2A:
	add r0, r4, #0
	add sp, #0x24
	pop {r3, r4, pc}
	.balign 4, 0
_02207A30: .word ov96_0221CAC8
	thumb_func_end ov96_022079B8


	thumb_func_start ov96_02207A34
ov96_02207A34: ; 0x02207A34
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	add r7, r0, #0
	add r0, r4, #0
	add r5, r2, #0
	add r0, #0x64
	bl VEC_Mag
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0x64
	bl VEC_Mag
	cmp r6, r0
	ble _02207A58
	add r6, r4, #0
	b _02207A68
_02207A58:
	cmp r6, r0
	bge _02207A62
	add r6, r5, #0
	add r5, r4, #0
	b _02207A68
_02207A62:
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02207A68:
	add r0, r6, #0
	add r0, #0xb0
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0xb0
	ldrb r0, [r0]
	cmp r1, r0
	beq _02207A7E
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02207A7E:
	add r0, r6, #0
	add r0, #0x64
	bl ov96_022079B8
	add r1, r6, #0
	add r1, #0xb0
	ldrb r1, [r1]
	cmp r1, r0
	beq _02207A96
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02207A96:
	add r0, r6, #0
	add r0, #0xa6
	ldrb r0, [r0]
	cmp r0, #1
	bne _02207AA6
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02207AA6:
	add r0, r5, #0
	add r0, #0xaa
	ldrb r1, [r0]
	cmp r1, #2
	blo _02207ACA
	add r0, r5, #0
	add r0, #0xaa
	ldrb r0, [r0]
	sub r1, r0, #2
	add r0, r5, #0
	add r0, #0xaa
	strb r1, [r0]
	add r0, r6, #0
	add r0, #0xaa
	ldrb r0, [r0]
	add r1, r0, #2
	add r0, r6, #0
	b _02207ADC
_02207ACA:
	add r0, r6, #0
	add r0, #0xaa
	ldrb r0, [r0]
	add r1, r0, r1
	add r0, r6, #0
	add r0, #0xaa
	strb r1, [r0]
	mov r1, #0
	add r0, r5, #0
_02207ADC:
	add r0, #0xaa
	strb r1, [r0]
	add r0, r6, #0
	add r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #9
	bls _02207AF2
	add r0, r6, #0
	mov r1, #9
	add r0, #0xaa
	strb r1, [r0]
_02207AF2:
	add r0, r5, #0
	mov r3, #1
	add r0, #0xa6
	strb r3, [r0]
	add r1, r5, #0
	add r2, r5, #0
	str r3, [sp]
	add r1, #0x98
	ldr r1, [r1]
	add r2, #0xb1
	lsl r1, r1, #0x18
	ldrb r2, [r2]
	add r0, r7, #0
	lsr r1, r1, #0x18
	bl ov96_021E8228
	add r0, r5, #0
	add r0, #0xb1
	ldrb r4, [r0]
	add r0, r6, #0
	add r0, #0x64
	bl VEC_Mag
	asr r3, r0, #0xb
	lsr r3, r3, #0x14
	add r3, r0, r3
	mov r1, #0x14
	add r2, r4, #0
	mul r2, r1
	add r2, r5, r2
	ldr r2, [r2, #0x18]
	asr r0, r3, #0xc
	add r2, r2, r0
	add r0, r5, #0
	add r0, #0xa2
	strb r2, [r0]
	add r2, sp, #4
	mov r0, #0
	str r0, [r2]
	str r0, [r2, #4]
	str r0, [r2, #8]
	add r2, r6, #0
	add r2, #0xb1
	ldrb r2, [r2]
	ldr r0, _02207B88 ; =0x45800000
	mul r1, r2
	add r1, r6, r1
	ldr r1, [r1, #0x14]
	bl _fmul
	bl _ffix
	add r1, r6, #0
	add r3, r5, #0
	add r1, #0x64
	add r2, sp, #4
	add r3, #0x64
	bl VEC_MultAdd
	add r2, r6, #0
	add r3, sp, #4
	ldmia r3!, {r0, r1}
	add r2, #0x64
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r6, #0xa4
	str r0, [r2]
	mov r0, #0x12
	strb r0, [r6]
	mov r0, #6
	add r5, #0xa4
	strb r0, [r5]
	mov r0, #1
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02207B88: .word 0x45800000
	thumb_func_end ov96_02207A34


	thumb_func_start ov96_02207B8C
ov96_02207B8C: ; 0x02207B8C
	mov r1, #0x66
	ldr r2, [r0, #0x5c]
	lsl r1, r1, #0xe
	mov r3, #0
	cmp r2, r1
	ble _02207BAC
	mov r1, #0xd
	ldr r2, [r0, #0x58]
	lsl r1, r1, #0x10
	cmp r2, r1
	blt _02207BAC
	mov r1, #0x13
	lsl r1, r1, #0x10
	cmp r2, r1
	bgt _02207BAC
	mov r3, #1
_02207BAC:
	cmp r3, #0
	bne _02207BB4
	mov r0, #0
	bx lr
_02207BB4:
	add r1, r0, #0
	add r1, #0xaa
	ldrb r1, [r1]
	cmp r1, #0
	bne _02207BC2
	mov r0, #0
	bx lr
_02207BC2:
	add r0, #0xa6
	ldrb r0, [r0]
	cmp r0, #0
	bne _02207BCE
	mov r0, #1
	bx lr
_02207BCE:
	mov r0, #0
	bx lr
	.balign 4, 0
	thumb_func_end ov96_02207B8C

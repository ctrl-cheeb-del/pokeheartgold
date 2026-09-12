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




	thumb_func_start ov96_02215FC8
ov96_02215FC8: ; 0x02215FC8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0xc]
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #4]
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #8]
	ldr r0, [sp]
	bl ov96_021E5F24
	cmp r0, #0
	beq _02215FF0
	b _022161C4
_02215FF0:
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x20]
	lsr r0, r0, #0x1f
	beq _0221600A
	mov r1, #0x62
	ldr r0, [sp, #0xc]
	lsl r1, r1, #2
	add r0, r0, r1
	ldr r1, [sp]
	bl ov96_02218330
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
_0221600A:
	ldr r1, _022161D4 ; =0x00000438
	ldr r0, [sp, #0xc]
	ldr r0, [r0, r1]
	cmp r0, #0
	ble _02216032
	sub r2, r0, #1
	ldr r0, [sp, #0xc]
	str r2, [r0, r1]
	ldr r0, [sp, #8]
	ldr r2, [r0, #0x20]
	ldr r0, _022161D8 ; =0xFFF80007
	and r2, r0
	ldr r0, [sp, #0xc]
	ldr r0, [r0, r1]
	add r1, r2, #0
	lsl r0, r0, #0x10
	lsr r0, r0, #0xd
	orr r1, r0
	ldr r0, [sp, #8]
	str r1, [r0, #0x20]
_02216032:
	ldr r0, [sp, #4]
	add r0, #0x50
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [sp, #4]
	bl ov96_021E8A20
	add r3, r0, #0
	mov r2, #4
_02216046:
	ldmia r3!, {r0, r1}
	stmia r4!, {r0, r1}
	sub r2, r2, #1
	bne _02216046
	ldr r0, [r3]
	mov r1, #0x66
	str r0, [r4]
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	add r0, #0x50
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	add r6, r0, r1
_02216064:
	ldr r0, [sp, #4]
	bl ov96_021E8A20
	add r7, r0, #0
	ldr r0, [r7]
	add r4, r6, #0
	add r5, r6, #0
	lsl r0, r0, #0xf
	add r4, #8
	add r5, #0xc
	lsr r0, r0, #0x1f
	beq _022160E0
	ldr r0, [r4]
	lsl r1, r0, #0x11
	lsr r1, r1, #0x1f
	beq _02216092
	lsl r2, r0, #0x10
	lsr r2, r2, #0x1f
	beq _02216092
	ldr r1, _022161DC ; =0xFFFFBFFF
	and r0, r1
	str r0, [r4]
	b _022160BA
_02216092:
	cmp r1, #0
	bne _022160BA
	ldr r1, [r4]
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1f
	bne _022160BA
	mov r0, #1
	lsl r0, r0, #0xe
	orr r1, r0
	lsl r0, r0, #1
	orr r0, r1
	str r0, [r4]
	ldr r0, [r7]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	strh r0, [r6, #4]
	ldr r0, [r7]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x18
	strh r0, [r6, #6]
_022160BA:
	ldr r0, [r7]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	strh r0, [r6]
	ldr r0, [r7]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x18
	strh r0, [r6, #2]
	ldr r1, [r4]
	ldr r0, _022161E0 ; =0xFFFFC000
	and r0, r1
	lsl r1, r1, #0x12
	lsr r1, r1, #0x12
	add r2, r1, #1
	ldr r1, _022161E4 ; =0x00003FFF
	and r1, r2
	orr r0, r1
	str r0, [r4]
	b _02216104
_022160E0:
	ldr r1, [r4]
	lsl r0, r1, #0x10
	lsr r0, r0, #0x1f
	beq _02216104
	ldr r0, _022161E8 ; =0xE000FFFF
	and r0, r1
	lsl r1, r1, #0x12
	lsr r1, r1, #0x12
	lsl r1, r1, #0x13
	lsr r1, r1, #3
	orr r1, r0
	ldr r0, _022161E0 ; =0xFFFFC000
	and r1, r0
	sub r0, r0, #1
	and r1, r0
	ldr r0, _022161EC ; =0xFFFF7FFF
	and r0, r1
	str r0, [r4]
_02216104:
	mov r0, #0
	mov r1, #2
	ldrsh r0, [r6, r0]
	ldrsh r1, [r6, r1]
	bl ov96_022158D4
	add r2, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_02219460
	ldr r0, [r5, #0x60]
	lsl r1, r0, #5
	lsr r1, r1, #0x1f
	beq _02216172
	lsl r0, r0, #6
	lsr r1, r0, #0x1e
	cmp r1, #1
	bne _02216150
	ldr r0, [r7]
	lsl r0, r0, #0xd
	lsr r0, r0, #0x1e
	cmp r0, #1
	bne _02216150
	add r0, r5, #0
	bl ov96_02219398
	add r0, r5, #0
	bl ov96_02218A68
	ldr r1, [r5, #0x60]
	ldr r0, _022161F0 ; =0xFCFFFFFF
	and r1, r0
	mov r0, #2
	lsl r0, r0, #0x18
	orr r0, r1
	str r0, [r5, #0x60]
	b _02216172
_02216150:
	cmp r1, #2
	bne _02216172
	ldr r0, [r7]
	lsl r0, r0, #0xd
	lsr r0, r0, #0x1e
	cmp r0, #2
	bne _02216172
	ldr r1, [r5, #0x60]
	ldr r0, _022161F4 ; =0xFBFFFFFF
	and r1, r0
	ldr r0, _022161F0 ; =0xFCFFFFFF
	and r0, r1
	str r0, [r5, #0x60]
	add r0, r5, #0
	mov r1, #4
	bl ov96_02218578
_02216172:
	ldr r0, [sp, #4]
	add r6, #0xa8
	add r0, #0x28
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #4
	bge _02216186
	b _02216064
_02216186:
	mov r1, #0x61
	ldr r0, [sp, #0xc]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl ov96_02219FE4
	mov r1, #0x66
	ldr r0, [sp, #0xc]
	lsl r1, r1, #2
	add r0, r0, r1
	ldr r1, [sp]
	bl ov96_022180CC
	ldr r0, [sp, #8]
	ldr r1, [r0, #0x20]
	lsl r0, r1, #0xd
	lsr r0, r0, #0x10
	bne _022161B6
	ldr r0, _022161F8 ; =0x7FFFFFFF
	and r1, r0
	add r0, r0, #1
	orr r1, r0
	ldr r0, [sp, #8]
	str r1, [r0, #0x20]
_022161B6:
	mov r1, #0x62
	ldr r0, [sp, #0xc]
	lsl r1, r1, #2
	add r0, r0, r1
	ldr r1, [sp]
	bl ov96_02218330
_022161C4:
	ldr r1, _022161FC ; =0x0000043C
	ldr r0, [sp, #0xc]
	add r0, r0, r1
	ldr r1, [sp]
	bl ov96_0221768C
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022161D4: .word 0x00000438
_022161D8: .word 0xFFF80007
_022161DC: .word 0xFFFFBFFF
_022161E0: .word 0xFFFFC000
_022161E4: .word 0x00003FFF
_022161E8: .word 0xE000FFFF
_022161EC: .word 0xFFFF7FFF
_022161F0: .word 0xFCFFFFFF
_022161F4: .word 0xFBFFFFFF
_022161F8: .word 0x7FFFFFFF
_022161FC: .word 0x0000043C
	thumb_func_end ov96_02215FC8

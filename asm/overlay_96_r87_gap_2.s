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


	thumb_func_start ov96_02206FA4
ov96_02206FA4: ; 0x02206FA4
	push {r4, r5}
	ldrh r5, [r1]
	ldrh r4, [r1, #2]
	add r3, r5, #0
	add r1, r4, #0
	sub r3, #0x10
	str r3, [r2]
	sub r1, #0x10
	str r1, [r2, #4]
	add r5, #0x10
	str r5, [r2, #8]
	str r1, [r2, #0xc]
	str r5, [r2, #0x10]
	add r4, #0x10
	str r4, [r2, #0x14]
	str r3, [r2, #0x18]
	str r4, [r2, #0x1c]
	ldr r3, [r2]
	ldr r1, [r2, #4]
	str r3, [r2, #0x20]
	str r1, [r2, #0x24]
	ldr r3, [r2, #8]
	ldr r1, [r2, #0xc]
	str r3, [r2, #0x28]
	str r1, [r2, #0x2c]
	ldr r3, [r2, #8]
	ldr r1, [r2, #0xc]
	str r3, [r2, #0x30]
	str r1, [r2, #0x34]
	ldr r3, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r3, [r2, #0x38]
	str r1, [r2, #0x3c]
	ldr r3, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r3, [r2, #0x40]
	str r1, [r2, #0x44]
	ldr r3, [r2, #0x18]
	ldr r1, [r2, #0x1c]
	str r3, [r2, #0x48]
	str r1, [r2, #0x4c]
	ldr r3, [r2, #0x18]
	ldr r1, [r2, #0x1c]
	str r3, [r2, #0x50]
	str r1, [r2, #0x54]
	ldr r3, [r2]
	ldr r1, [r2, #4]
	str r3, [r2, #0x58]
	str r1, [r2, #0x5c]
	ldr r1, [r2, #0x24]
	sub r1, r1, r0
	str r1, [r2, #0x24]
	ldr r1, [r2, #0x2c]
	sub r1, r1, r0
	str r1, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	add r1, r1, r0
	str r1, [r2, #0x30]
	ldr r1, [r2, #0x38]
	add r1, r1, r0
	str r1, [r2, #0x38]
	ldr r1, [r2, #0x44]
	add r1, r1, r0
	str r1, [r2, #0x44]
	ldr r1, [r2, #0x4c]
	add r1, r1, r0
	str r1, [r2, #0x4c]
	ldr r1, [r2, #0x50]
	sub r1, r1, r0
	str r1, [r2, #0x50]
	add r2, #0x58
	ldr r1, [r2]
	sub r0, r1, r0
	str r0, [r2]
	pop {r4, r5}
	bx lr
	thumb_func_end ov96_02206FA4




	thumb_func_start ov96_0220703C
ov96_0220703C: ; 0x0220703C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xa4
	str r0, [sp, #4]
	ldr r0, [sp, #0xb8]
	str r2, [sp, #0xc]
	str r0, [sp, #0xb8]
	ldr r0, [sp, #4]
	str r1, [sp, #8]
	ldr r1, [r0]
	add r7, r3, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x24]
	ldr r0, [sp, #4]
	add r6, r3, #0
	ldr r1, [r0, #4]
	ldr r2, _022072F8 ; =ov96_0221CB00
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x28]
	ldr r0, [sp, #8]
	str r3, [sp, #0x10]
	ldr r1, [r0]
	add r5, r3, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [sp, #8]
	add r3, sp, #0x34
	ldr r1, [r0, #4]
	mov r4, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x20]
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	add r7, #0x28
	add r6, #0x20
_0220709C:
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
	beq _022070DA
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
_022070DA:
	mov r0, #0
	cmp r4, #0
	bne _0220710A
	cmp r4, #2
	bne _0220710A
	ldr r2, [sp, #0x28]
	ldr r1, [r5, #0x24]
	cmp r2, r1
	bne _0220712E
	ldr r2, [r5, #0x28]
	ldr r3, [r5, #0x20]
	cmp r3, r2
	bge _022070F8
	add r1, r3, #0
	b _022070FC
_022070F8:
	add r1, r2, #0
	add r2, r3, #0
_022070FC:
	ldr r3, [sp, #0x24]
	cmp r1, r3
	bgt _0220712E
	cmp r3, r2
	bgt _0220712E
	mov r0, #1
	b _0220712E
_0220710A:
	ldr r2, [sp, #0x24]
	ldr r1, [r5, #0x20]
	cmp r2, r1
	bne _0220712E
	ldr r2, [r5, #0x2c]
	ldr r3, [r5, #0x24]
	cmp r3, r2
	bge _0220711E
	add r1, r3, #0
	b _02207122
_0220711E:
	add r1, r2, #0
	add r2, r3, #0
_02207122:
	ldr r3, [sp, #0x28]
	cmp r1, r3
	bgt _0220712E
	cmp r3, r2
	bgt _0220712E
	mov r0, #1
_0220712E:
	cmp r0, #0
	beq _02207150
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
_02207150:
	add r4, r4, #1
	add r7, #0x10
	add r6, #0x10
	add r5, #0x10
	cmp r4, #4
	blt _0220709C
	ldr r3, _022072FC ; =ov96_0221CAE0
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
_02207172:
	add r3, sp, #0x44
	add r2, sp, #0x84
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r4]
	add r1, sp, #0x78
	lsl r0, r0, #0xc
	str r0, [sp, #0x78]
	ldr r0, [r4, #4]
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
	bgt _022071E0
	ldr r3, [sp, #0xc]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	add r2, sp, #0x78
	lsl r3, r3, #0xc
	bl ov96_02207390
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
_022071E0:
	add r5, r5, #1
	add r4, #8
	cmp r5, #4
	blt _02207172
	ldr r0, [sp, #8]
	ldr r1, [r0]
	ldr r0, [sp, #0x10]
	ldr r0, [r0]
	lsl r0, r0, #0xc
	cmp r0, r1
	bgt _022072F2
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x10]
	lsl r0, r0, #0xc
	cmp r1, r0
	bgt _022072F2
	ldr r0, [sp, #8]
	ldr r1, [r0, #4]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #4]
	lsl r0, r0, #0xc
	cmp r0, r1
	bgt _022072F2
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x14]
	lsl r0, r0, #0xc
	cmp r1, r0
	bgt _022072F2
	ldr r3, [sp, #8]
	ldr r2, [sp, #0xb8]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0
	str r0, [r2]
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x10]
	ldr r0, [r0]
	ldr r3, [r3, #0x10]
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
	bge _0220724A
	sub r2, r1, #1
	mul r0, r2
_0220724A:
	cmp r3, #0
	bge _02207254
	mov r2, #0
	mvn r2, r2
	mul r3, r2
_02207254:
	cmp r0, r3
	bge _0220725C
	mov r6, #0xc
	b _02207260
_0220725C:
	add r0, r3, #0
	mov r6, #0xa
_02207260:
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #8]
	ldr r4, [sp, #0x10]
	ldr r2, [r2, #4]
	ldr r5, [r3, #4]
	ldr r7, [r4, #0x14]
	lsl r3, r2, #0xc
	lsl r4, r7, #0xc
	sub r3, r3, r5
	sub r4, r4, r5
	cmp r3, #0
	bge _0220727E
	mov r5, #0
	mvn r5, r5
	mul r3, r5
_0220727E:
	cmp r4, #0
	bge _02207288
	mov r5, #0
	mvn r5, r5
	mul r4, r5
_02207288:
	cmp r3, r4
	bge _02207290
	mov r4, #9
	b _02207294
_02207290:
	add r3, r4, #0
	mov r4, #0xb
_02207294:
	cmp r0, r3
	bgt _022072A0
	mov r0, #1
	mov ip, r0
	add r0, r6, #0
	b _022072A4
_022072A0:
	mov r1, #1
	add r0, r4, #0
_022072A4:
	mov r3, ip
	cmp r3, #0
	beq _022072CE
	cmp r6, #0xc
	bne _022072BE
	ldr r2, [sp, #0x18]
	ldr r1, [sp, #0xc]
	sub r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1]
	pop {r4, r5, r6, r7, pc}
_022072BE:
	ldr r2, [sp, #0x14]
	ldr r1, [sp, #0xc]
	add r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1]
	pop {r4, r5, r6, r7, pc}
_022072CE:
	cmp r1, #0
	beq _022072F4
	cmp r4, #9
	bne _022072E4
	ldr r1, [sp, #0xc]
	sub r1, r2, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1, #4]
	pop {r4, r5, r6, r7, pc}
_022072E4:
	ldr r1, [sp, #0xc]
	add r1, r7, r1
	lsl r2, r1, #0xc
	ldr r1, [sp, #0xb8]
	add sp, #0xa4
	str r2, [r1, #4]
	pop {r4, r5, r6, r7, pc}
_022072F2:
	mov r0, #0
_022072F4:
	add sp, #0xa4
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022072F8: .word ov96_0221CB00
_022072FC: .word ov96_0221CAE0
	thumb_func_end ov96_0220703C




	thumb_func_start ov96_02207300
ov96_02207300: ; 0x02207300
	push {r4, r5, r6, r7, lr}
	sub sp, #0xcc
	str r1, [sp, #4]
	ldr r1, [sp, #0xe0]
	add r7, r3, #0
	str r1, [sp, #0xe0]
	ldr r1, [sp, #0xe4]
	add r6, r2, #0
	str r1, [sp, #0xe4]
	add r1, sp, #0xc
	str r1, [sp]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	add r3, sp, #0x7c
	bl ov96_02206F1C
	mov r4, #0
	str r4, [sp, #8]
	add r0, sp, #0xc
	ldrb r0, [r0]
	cmp r0, #0
	ble _02207388
	add r5, sp, #0x7c
_0220732E:
	ldr r1, [r5]
	add r0, r6, #0
	add r2, sp, #0x1c
	bl ov96_02206FA4
	add r0, sp, #0x10
	str r0, [sp]
	ldr r1, [sp, #0xe0]
	add r0, r7, #0
	add r2, r6, #0
	add r3, sp, #0x1c
	bl ov96_0220703C
	cmp r0, #0
	beq _0220737C
	cmp r0, #9
	blt _02207360
	ldr r2, [sp, #0x10]
	ldr r1, [sp, #0xe4]
	str r2, [r1]
	ldr r2, [sp, #0x14]
	str r2, [r1, #4]
	mov r2, #0
	str r2, [r1, #8]
	b _02207374
_02207360:
	ldr r1, [sp, #4]
	cmp r0, r1
	beq _02207374
	ldr r2, [sp, #0x10]
	ldr r1, [sp, #0xe4]
	str r2, [r1]
	ldr r2, [sp, #0x14]
	str r2, [r1, #4]
	mov r2, #0
	str r2, [r1, #8]
_02207374:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	b _02207388
_0220737C:
	add r0, sp, #0xc
	ldrb r0, [r0]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r0
	blt _0220732E
_02207388:
	ldr r0, [sp, #8]
	add sp, #0xcc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02207300

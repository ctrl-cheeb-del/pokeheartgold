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

	thumb_func_start ov96_02214C3C
ov96_02214C3C: ; 0x02214C3C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x38]
	str r2, [sp, #0x10]
	add r6, r3, #0
	str r0, [sp, #0x38]
	ldr r0, [r6, #0x78]
	cmp r0, #0
	beq _02214C58
	add sp, #0x24
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_02214C58:
	ldr r0, [r6, #0x48]
	cmp r0, #0
	beq _02214C64
	add sp, #0x24
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_02214C64:
	ldr r3, [r6, #0x30]
	ldr r4, [r6, #0x34]
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r3, r4, #0xb
	lsr r3, r3, #0x14
	add r3, r4, r3
	mov r0, #0x80
	mov r1, #0x60
	asr r2, r2, #0xc
	asr r3, r3, #0xc
	bl ov96_02215614
	str r0, [sp, #0x14]
	add r0, r6, #0
	str r0, [sp, #0x1c]
	add r0, #0x30
	mov r4, #0
	str r0, [sp, #0x1c]
_02214C8C:
	mov r0, #0x4c
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #0x38]
	add r5, r0, r1
	add r0, r5, #0
	add r0, #0x39
	ldrb r0, [r0]
	cmp r0, #0
	bne _02214CCA
	add r0, r5, #0
	add r0, #0x38
	ldrb r0, [r0]
	cmp r0, #0
	beq _02214CCA
	ldr r2, [r5, #8]
	ldr r7, [r5, #0xc]
	asr r3, r2, #0xb
	lsr r3, r3, #0x14
	add r3, r2, r3
	asr r2, r3, #0xc
	asr r3, r7, #0xb
	lsr r3, r3, #0x14
	add r3, r7, r3
	mov r0, #0x80
	mov r1, #0x60
	asr r3, r3, #0xc
	bl ov96_02215614
	add r7, r0, #0
	b _02214CCC
_02214CCA:
	mov r7, #4
_02214CCC:
	cmp r7, #4
	beq _02214D68
	mov r0, #0
	str r0, [sp, #0x18]
	add r0, r5, #0
	add r0, #0x38
	ldrb r0, [r0]
	cmp r0, #1
	bne _02214CE4
	mov r0, #8
	str r0, [sp, #0x18]
	b _02214CF2
_02214CE4:
	cmp r0, #2
	bne _02214CEE
	mov r0, #0xc
	str r0, [sp, #0x18]
	b _02214CF2
_02214CEE:
	bl GF_AssertFail
_02214CF2:
	ldr r0, [r6]
	bl ov96_021EAF8C
	add r1, r0, #0
	ldr r3, [sp, #0x18]
	add r2, r5, #0
	ldr r0, [sp, #0x1c]
	lsl r1, r1, #0xc
	add r2, #8
	lsl r3, r3, #0xc
	bl ov96_022156E8
	cmp r0, #0
	beq _02214D16
	mov r1, #1
	add r0, sp, #0x20
	strb r1, [r0, r4]
	b _02214D6E
_02214D16:
	ldr r0, [sp, #0x14]
	cmp r0, r7
	bne _02214D60
	str r0, [sp]
	ldr r0, [sp, #0xc]
	str r0, [sp, #4]
	ldr r1, [r5, #8]
	ldr r2, [r5, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r3, [r6, #0x30]
	asr r0, r0, #0xc
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	ldr r3, [r6, #0x34]
	asr r1, r1, #0xc
	asr r5, r3, #0xb
	lsr r5, r5, #0x14
	add r5, r3, r5
	asr r2, r2, #0xc
	asr r3, r5, #0xc
	bl ov96_02215650
	cmp r0, #0
	add r0, sp, #0x20
	beq _02214D5A
	mov r1, #4
	strb r1, [r0, r4]
	b _02214D6E
_02214D5A:
	mov r1, #3
	strb r1, [r0, r4]
	b _02214D6E
_02214D60:
	mov r1, #2
	add r0, sp, #0x20
	strb r1, [r0, r4]
	b _02214D6E
_02214D68:
	mov r1, #0
	add r0, sp, #0x20
	strb r1, [r0, r4]
_02214D6E:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _02214C8C
	add r0, sp, #0x20
	ldrb r3, [r0, #1]
	ldrb r2, [r0]
	cmp r2, r3
	blo _02214D8E
	ldr r1, [sp, #0x38]
	ldr r3, [sp, #0x14]
	add r0, r6, #0
	bl ov96_02214DBC
	b _02214D9E
_02214D8E:
	ldr r1, [sp, #0x38]
	add r2, r3, #0
	add r1, #0x4c
	ldr r3, [sp, #0x14]
	add r0, r6, #0
	str r1, [sp, #0x38]
	bl ov96_02214DBC
_02214D9E:
	add r4, r0, #0
	ldr r0, [r6, #0x78]
	cmp r0, #1
	bne _02214DB6
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	mov r3, #6
	bl ov96_021E8228
_02214DB6:
	add r0, r4, #0
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_02214C3C


	thumb_func_start ov96_02214DBC
ov96_02214DBC: ; 0x02214DBC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl LCRandom
	mov r1, #0x64
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	cmp r6, #0xd
	bhi _02214EA2
	add r1, r6, r6
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02214DE4: ; jump table
	.short _02214EA6 - _02214DE4 - 2 ; case 0
	.short _02214E78 - _02214DE4 - 2 ; case 1
	.short _02214E00 - _02214DE4 - 2 ; case 2
	.short _02214E32 - _02214DE4 - 2 ; case 3
	.short _02214E64 - _02214DE4 - 2 ; case 4
	.short _02214EA2 - _02214DE4 - 2 ; case 5
	.short _02214EA2 - _02214DE4 - 2 ; case 6
	.short _02214EA2 - _02214DE4 - 2 ; case 7
	.short _02214EA6 - _02214DE4 - 2 ; case 8
	.short _02214E78 - _02214DE4 - 2 ; case 9
	.short _02214EA2 - _02214DE4 - 2 ; case 10
	.short _02214EA2 - _02214DE4 - 2 ; case 11
	.short _02214EA2 - _02214DE4 - 2 ; case 12
	.short _02214E64 - _02214DE4 - 2 ; case 13
_02214E00:
	cmp r0, #0x3c
	bhs _02214E08
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02214E08:
	cmp r0, #0x50
	bhs _02214E1C
	add r4, #8
	ldmia r4!, {r0, r1}
	add r5, #0x24
	stmia r5!, {r0, r1}
	ldr r0, [r4]
	str r0, [r5]
	mov r0, #0xa
	pop {r3, r4, r5, r6, r7, pc}
_02214E1C:
	add r4, #8
	add r2, r5, #0
	ldmia r4!, {r0, r1}
	add r2, #0x24
	stmia r2!, {r0, r1}
	ldr r0, [r4]
	str r0, [r2]
	mov r0, #1
	str r0, [r5, #0x78]
	mov r0, #0xa
	pop {r3, r4, r5, r6, r7, pc}
_02214E32:
	cmp r0, #0x14
	bhs _02214E3A
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02214E3A:
	cmp r0, #0x5a
	bhs _02214E4E
	add r4, #8
	ldmia r4!, {r0, r1}
	add r5, #0x24
	stmia r5!, {r0, r1}
	ldr r0, [r4]
	str r0, [r5]
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_02214E4E:
	add r4, #8
	add r2, r5, #0
	ldmia r4!, {r0, r1}
	add r2, #0x24
	stmia r2!, {r0, r1}
	ldr r0, [r4]
	str r0, [r2]
	mov r0, #1
	str r0, [r5, #0x78]
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_02214E64:
	add r4, #8
	add r2, r5, #0
	ldmia r4!, {r0, r1}
	add r2, #0x24
	stmia r2!, {r0, r1}
	ldr r0, [r4]
	str r0, [r2]
	mov r0, #1
	str r0, [r5, #0x78]
	b _02214EA6
_02214E78:
	cmp r7, #4
	beq _02214E9C
	mov r0, #3
	sub r0, r0, r7
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	mov r0, #0xc
	add r2, r1, #0
	mul r2, r0
	ldr r0, _02214EAC ; =ov96_0221D678
	ldrh r0, [r0, r2]
	lsl r0, r0, #0xc
	str r0, [r5, #0x24]
	ldr r0, _02214EB0 ; =ov96_0221D67A
	ldrh r0, [r0, r2]
	lsl r0, r0, #0xc
	str r0, [r5, #0x28]
	b _02214EA6
_02214E9C:
	bl GF_AssertFail
	b _02214EA6
_02214EA2:
	bl GF_AssertFail
_02214EA6:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02214EAC: .word ov96_0221D678
_02214EB0: .word ov96_0221D67A
	thumb_func_end ov96_02214DBC


	thumb_func_start ov96_02214EB4
ov96_02214EB4: ; 0x02214EB4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x40]
	str r2, [sp, #0x10]
	add r6, r3, #0
	str r0, [sp, #0x40]
	ldr r0, [r6, #0x78]
	cmp r0, #0
	beq _02214ED0
	add sp, #0x28
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02214ED0:
	ldr r0, [r6, #0x48]
	cmp r0, #0
	beq _02214EDC
	add sp, #0x28
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02214EDC:
	ldr r3, [r6, #0x30]
	ldr r4, [r6, #0x34]
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r3, r4, #0xb
	lsr r3, r3, #0x14
	add r3, r4, r3
	mov r0, #0x80
	mov r1, #0x60
	asr r2, r2, #0xc
	asr r3, r3, #0xc
	bl ov96_02215614
	str r0, [sp, #0x14]
	mov r4, #0
_02214EFC:
	mov r0, #0x4c
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #0x40]
	add r5, r0, r1
	add r0, r5, #0
	add r0, #0x39
	ldrb r0, [r0]
	cmp r0, #0
	bne _02214F38
	add r0, r5, #0
	add r0, #0x38
	ldrb r0, [r0]
	cmp r0, #0
	beq _02214F38
	ldr r2, [r5, #8]
	ldr r7, [r5, #0xc]
	asr r3, r2, #0xb
	lsr r3, r3, #0x14
	add r3, r2, r3
	asr r2, r3, #0xc
	asr r3, r7, #0xb
	lsr r3, r3, #0x14
	add r3, r7, r3
	mov r0, #0x80
	mov r1, #0x60
	asr r3, r3, #0xc
	bl ov96_02215614
	b _02214F3A
_02214F38:
	mov r0, #4
_02214F3A:
	cmp r0, #4
	beq _02214F92
	ldr r1, [sp, #0xc]
	cmp r1, r0
	bne _02214F8A
	ldr r0, [sp, #0x14]
	str r0, [sp]
	ldr r0, [sp, #0xc]
	str r0, [sp, #4]
	ldr r1, [r5, #8]
	ldr r2, [r5, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r3, [r6, #0x30]
	asr r0, r0, #0xc
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	ldr r3, [r6, #0x34]
	asr r1, r1, #0xc
	asr r5, r3, #0xb
	lsr r5, r5, #0x14
	add r5, r3, r5
	asr r2, r2, #0xc
	asr r3, r5, #0xc
	bl ov96_0221567C
	cmp r0, #0
	add r0, sp, #0x18
	beq _02214F84
	mov r1, #7
	strb r1, [r0, r4]
	b _02214F98
_02214F84:
	mov r1, #6
	strb r1, [r0, r4]
	b _02214F98
_02214F8A:
	mov r1, #6
	add r0, sp, #0x18
	strb r1, [r0, r4]
	b _02214F98
_02214F92:
	mov r1, #5
	add r0, sp, #0x18
	strb r1, [r0, r4]
_02214F98:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _02214EFC
	add r0, sp, #0x18
	ldrb r4, [r0, #1]
	ldrb r0, [r0]
	cmp r0, #7
	bne _02214FB0
	mov r0, #1
	b _02214FB2
_02214FB0:
	mov r0, #0
_02214FB2:
	cmp r4, #7
	bne _02214FBA
	mov r1, #1
	b _02214FBC
_02214FBA:
	mov r1, #0
_02214FBC:
	cmp r0, r1
	bne _02215014
	ldr r1, [sp, #0x40]
	add r0, r6, #0
	add r0, #0x30
	add r1, #8
	add r2, sp, #0x1c
	bl VEC_Subtract
	add r0, sp, #0x1c
	bl VEC_Mag
	ldr r1, [sp, #0x40]
	add r5, r0, #0
	add r0, r6, #0
	add r0, #0x30
	add r1, #0x54
	add r2, sp, #0x1c
	bl VEC_Subtract
	add r0, sp, #0x1c
	bl VEC_Mag
	cmp r5, r0
	blt _02215000
	add r2, sp, #0x18
	ldrb r2, [r2]
	ldr r1, [sp, #0x40]
	ldr r3, [sp, #0xc]
	add r0, r6, #0
	bl ov96_02215058
	add r4, r0, #0
	b _0221503C
_02215000:
	ldr r1, [sp, #0x40]
	ldr r3, [sp, #0xc]
	add r1, #0x4c
	add r0, r6, #0
	add r2, r4, #0
	str r1, [sp, #0x40]
	bl ov96_02215058
	add r4, r0, #0
	b _0221503C
_02215014:
	add r0, sp, #0x18
	ldrb r2, [r0]
	cmp r2, r4
	blo _0221502A
	ldr r1, [sp, #0x40]
	ldr r3, [sp, #0xc]
	add r0, r6, #0
	bl ov96_02215058
	add r4, r0, #0
	b _0221503C
_0221502A:
	ldr r1, [sp, #0x40]
	ldr r3, [sp, #0xc]
	add r1, #0x4c
	add r0, r6, #0
	add r2, r4, #0
	str r1, [sp, #0x40]
	bl ov96_02215058
	add r4, r0, #0
_0221503C:
	ldr r0, [r6, #0x78]
	cmp r0, #1
	bne _02215052
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	mov r3, #6
	bl ov96_021E8228
_02215052:
	add r0, r4, #0
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02214EB4


	thumb_func_start ov96_02215058
ov96_02215058: ; 0x02215058
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r4, r0, #0
	cmp r2, #0xc
	bls _02215064
	b _0221516E
_02215064:
	add r0, r2, r2
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02215070: ; jump table
	.short _0221516E - _02215070 - 2 ; case 0
	.short _0221516E - _02215070 - 2 ; case 1
	.short _0221516E - _02215070 - 2 ; case 2
	.short _0221516E - _02215070 - 2 ; case 3
	.short _0221516E - _02215070 - 2 ; case 4
	.short _02215172 - _02215070 - 2 ; case 5
	.short _0221508A - _02215070 - 2 ; case 6
	.short _02215146 - _02215070 - 2 ; case 7
	.short _02215172 - _02215070 - 2 ; case 8
	.short _0221516E - _02215070 - 2 ; case 9
	.short _0221516E - _02215070 - 2 ; case 10
	.short _0221508A - _02215070 - 2 ; case 11
	.short _02215146 - _02215070 - 2 ; case 12
_0221508A:
	sub r1, r3, #1
	add r6, r1, #0
	mov r0, #0xc
	mul r6, r0
	ldr r0, _02215178 ; =ov96_0221D678
	ldr r1, [r4, #0x30]
	add r5, r0, r6
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	ldr r2, [r4, #0x34]
	asr r0, r0, #0xc
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	asr r1, r1, #0xc
	add r2, r5, #0
	bl ov96_022156A8
	cmp r0, #0
	beq _022150BA
	add sp, #4
	mov r0, #0
	pop {r3, r4, r5, r6, pc}
_022150BA:
	bl LCRandom
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	bne _022150D8
	ldrh r1, [r5]
	add r0, sp, #0
	strh r1, [r0]
	ldrh r1, [r5, #2]
	strh r1, [r0, #2]
	b _02215108
_022150D8:
	bl LCRandom
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	bne _022150FA
	ldr r0, _0221517C ; =ov96_0221D67C
	ldrh r1, [r0, r6]
	add r2, r0, r6
	add r0, sp, #0
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r0, #2]
	b _02215108
_022150FA:
	ldr r0, _02215180 ; =ov96_0221D680
	ldrh r1, [r0, r6]
	add r2, r0, r6
	add r0, sp, #0
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r0, #2]
_02215108:
	bl LCRandom
	mov r1, #0x11
	bl _s32_div_f
	add r2, sp, #0
	mov r0, #8
	ldrh r3, [r2]
	sub r0, r0, r1
	add r0, r3, r0
	strh r0, [r2]
	bl LCRandom
	mov r1, #0x11
	bl _s32_div_f
	add r2, sp, #0
	mov r0, #8
	ldrh r3, [r2, #2]
	sub r0, r0, r1
	add sp, #4
	add r0, r3, r0
	strh r0, [r2, #2]
	ldrh r0, [r2]
	lsl r0, r0, #0xc
	str r0, [r4, #0x24]
	ldrh r0, [r2, #2]
	lsl r0, r0, #0xc
	str r0, [r4, #0x28]
	mov r0, #6
	pop {r3, r4, r5, r6, pc}
_02215146:
	add r3, r1, #0
	add r3, #8
	add r2, r4, #0
	ldmia r3!, {r0, r1}
	add r2, #0x24
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	bl LCRandom
	mov r1, #0x64
	bl _s32_div_f
	cmp r1, #0x50
	bge _02215168
	mov r0, #1
	str r0, [r4, #0x78]
_02215168:
	add sp, #4
	mov r0, #0xa
	pop {r3, r4, r5, r6, pc}
_0221516E:
	bl GF_AssertFail
_02215172:
	mov r0, #0
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_02215178: .word ov96_0221D678
_0221517C: .word ov96_0221D67C
_02215180: .word ov96_0221D680
	thumb_func_end ov96_02215058


	thumb_func_start ov96_02215184
ov96_02215184: ; 0x02215184
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	str r0, [sp, #8]
	ldr r0, [sp, #0x48]
	str r1, [sp, #0xc]
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x4c]
	str r2, [sp, #0x10]
	add r5, r3, #0
	str r0, [sp, #0x4c]
	ldr r0, [r5, #0x78]
	cmp r0, #0
	beq _022151A4
	add sp, #0x30
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_022151A4:
	ldr r0, [r5, #0x48]
	cmp r0, #0
	beq _022151B0
	add sp, #0x30
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_022151B0:
	ldr r3, [r5, #0x30]
	ldr r4, [r5, #0x34]
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r3, r4, #0xb
	lsr r3, r3, #0x14
	add r3, r4, r3
	mov r0, #0x80
	mov r1, #0x60
	asr r2, r2, #0xc
	asr r3, r3, #0xc
	bl ov96_02215614
	str r0, [sp, #0x14]
	mov r4, #0
	add r7, sp, #0x20
_022151D2:
	mov r0, #0x4c
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #0x48]
	add r3, r0, r1
	add r0, r3, #0
	add r0, #0x39
	ldrb r0, [r0]
	cmp r0, #0
	bne _02215210
	add r0, r3, #0
	add r0, #0x38
	ldrb r0, [r0]
	cmp r0, #0
	beq _02215210
	ldr r2, [r3, #8]
	ldr r3, [r3, #0xc]
	asr r6, r2, #0xb
	lsr r6, r6, #0x14
	add r6, r2, r6
	asr r2, r6, #0xc
	asr r6, r3, #0xb
	lsr r6, r6, #0x14
	add r6, r3, r6
	mov r0, #0x80
	mov r1, #0x60
	asr r3, r6, #0xc
	bl ov96_02215614
	strb r0, [r7, r4]
	b _02215214
_02215210:
	mov r0, #4
	strb r0, [r7, r4]
_02215214:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _022151D2
	add r0, r5, #0
	str r0, [sp, #0x1c]
	add r0, #0x30
	mov r4, #0
	str r0, [sp, #0x1c]
_02215228:
	mov r0, #0x4c
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #0x48]
	add r6, r0, r1
	add r0, sp, #0x20
	mov r1, #8
	add r0, #2
	strb r1, [r0, r4]
	add r0, sp, #0x20
	ldrb r0, [r0, r4]
	str r0, [sp, #0x18]
	cmp r0, #4
	beq _022152CC
	add r0, r6, #0
	add r0, #0x38
	ldrb r0, [r0]
	mov r7, #0
	cmp r0, #1
	bne _02215254
	add r7, r1, #0
	b _02215260
_02215254:
	cmp r0, #2
	bne _0221525C
	mov r7, #0xc
	b _02215260
_0221525C:
	bl GF_AssertFail
_02215260:
	ldr r0, [r5]
	bl ov96_021EAF8C
	add r1, r0, #0
	add r2, r6, #0
	ldr r0, [sp, #0x1c]
	lsl r1, r1, #0xc
	add r2, #8
	lsl r3, r7, #0xc
	bl ov96_022156E8
	cmp r0, #0
	beq _02215284
	add r0, sp, #0x20
	mov r1, #8
	add r0, #2
	strb r1, [r0, r4]
	b _022152CC
_02215284:
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	cmp r1, r0
	bne _022152CC
	add r0, r1, #0
	str r0, [sp]
	ldr r0, [sp, #0xc]
	str r0, [sp, #4]
	ldr r1, [r6, #8]
	ldr r2, [r6, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r3, [r5, #0x30]
	asr r0, r0, #0xc
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	ldr r3, [r5, #0x34]
	asr r1, r1, #0xc
	asr r6, r3, #0xb
	lsr r6, r6, #0x14
	add r6, r3, r6
	asr r2, r2, #0xc
	asr r3, r6, #0xc
	bl ov96_02215650
	cmp r0, #0
	beq _022152CC
	add r0, sp, #0x20
	mov r1, #0xd
	add r0, #2
	strb r1, [r0, r4]
_022152CC:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _02215228
	add r0, sp, #0x20
	ldrb r2, [r0, #2]
	cmp r2, #0xd
	bne _022152EC
	ldr r1, [sp, #0x48]
	ldr r3, [sp, #0x14]
	add r0, r5, #0
	bl ov96_02214DBC
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
_022152EC:
	ldrb r2, [r0, #3]
	cmp r2, #0xd
	bne _02215304
	ldr r1, [sp, #0x48]
	ldr r3, [sp, #0x14]
	add r1, #0x4c
	add r0, r5, #0
	str r1, [sp, #0x48]
	bl ov96_02214DBC
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
_02215304:
	ldr r0, [sp, #0xc]
	mov r1, #0x24
	mul r1, r0
	ldr r0, [sp, #0x4c]
	add r0, r0, r1
	ldr r0, [r0, #4]
	add r0, #0x71
	ldrb r0, [r0]
	cmp r0, #0x32
	blo _02215326
	ldr r1, [sp, #0x4c]
	ldr r2, [sp, #0xc]
	add r0, r5, #0
	bl ov96_02215478
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
_02215326:
	add r6, sp, #0x20
	mov r4, #0
	add r6, #2
_0221532C:
	mov r0, #0x4c
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #0x48]
	add r1, r0, r1
	add r0, sp, #0x20
	ldrb r2, [r0, r4]
	cmp r2, #4
	beq _0221538E
	ldr r0, [sp, #0xc]
	cmp r0, r2
	bne _02215388
	ldr r0, [sp, #0x14]
	str r0, [sp]
	ldr r0, [sp, #0xc]
	str r0, [sp, #4]
	ldr r2, [r1, #8]
	ldr r7, [r5, #0x34]
	asr r0, r2, #0xb
	lsr r0, r0, #0x14
	add r0, r2, r0
	ldr r2, [r1, #0xc]
	asr r0, r0, #0xc
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r2, [r5, #0x30]
	asr r1, r1, #0xc
	asr r3, r2, #0xb
	lsr r3, r3, #0x14
	add r3, r2, r3
	asr r2, r3, #0xc
	asr r3, r7, #0xb
	lsr r3, r3, #0x14
	add r3, r7, r3
	asr r3, r3, #0xc
	bl ov96_02215650
	cmp r0, #0
	beq _02215382
	mov r0, #0xc
	strb r0, [r6, r4]
	b _02215392
_02215382:
	mov r0, #0xb
	strb r0, [r6, r4]
	b _02215392
_02215388:
	mov r0, #0xb
	strb r0, [r6, r4]
	b _02215392
_0221538E:
	mov r0, #0xa
	strb r0, [r6, r4]
_02215392:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _0221532C
	add r0, sp, #0x20
	ldrb r2, [r0, #2]
	ldrb r4, [r0, #3]
	cmp r2, #7
	bne _022153AA
	mov r0, #1
	b _022153AC
_022153AA:
	mov r0, #0
_022153AC:
	cmp r4, #7
	bne _022153B4
	mov r1, #1
	b _022153B6
_022153B4:
	mov r1, #0
_022153B6:
	cmp r0, r1
	bne _02215416
	ldr r1, [sp, #0x48]
	add r0, r5, #0
	add r0, #0x30
	add r1, #8
	add r2, sp, #0x24
	bl VEC_Subtract
	add r0, sp, #0x24
	bl VEC_Mag
	ldr r1, [sp, #0x48]
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0x30
	add r1, #0x54
	add r2, sp, #0x24
	bl VEC_Subtract
	add r0, sp, #0x24
	bl VEC_Mag
	cmp r6, r0
	blt _022153FE
	ldr r0, [sp, #0x4c]
	add r2, sp, #0x20
	str r0, [sp]
	ldrb r2, [r2, #2]
	ldr r1, [sp, #0x48]
	ldr r3, [sp, #0xc]
	add r0, r5, #0
	bl ov96_02215460
	add r4, r0, #0
	b _02215442
_022153FE:
	ldr r0, [sp, #0x4c]
	ldr r1, [sp, #0x48]
	str r0, [sp]
	ldr r3, [sp, #0xc]
	add r1, #0x4c
	add r0, r5, #0
	add r2, r4, #0
	str r1, [sp, #0x48]
	bl ov96_02215460
	add r4, r0, #0
	b _02215442
_02215416:
	cmp r2, r4
	blo _0221542C
	ldr r0, [sp, #0x4c]
	ldr r1, [sp, #0x48]
	str r0, [sp]
	ldr r3, [sp, #0xc]
	add r0, r5, #0
	bl ov96_02215460
	add r4, r0, #0
	b _02215442
_0221542C:
	ldr r0, [sp, #0x4c]
	ldr r1, [sp, #0x48]
	str r0, [sp]
	ldr r3, [sp, #0xc]
	add r1, #0x4c
	add r0, r5, #0
	add r2, r4, #0
	str r1, [sp, #0x48]
	bl ov96_02215460
	add r4, r0, #0
_02215442:
	ldr r0, [r5, #0x78]
	cmp r0, #1
	bne _02215458
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	mov r3, #6
	bl ov96_021E8228
_02215458:
	add r0, r4, #0
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02215184

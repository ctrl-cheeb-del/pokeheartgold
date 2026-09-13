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

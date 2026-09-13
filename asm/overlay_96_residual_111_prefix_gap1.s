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

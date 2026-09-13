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

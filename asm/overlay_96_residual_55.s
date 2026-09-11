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

	thumb_func_start ov96_021F30C4
ov96_021F30C4: ; 0x021F30C4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r1, #0
	mov r4, #0
_021F30CC:
	add r0, r7, #0
	mov r1, #0x65
	mov r2, #2
	bl ov96_021EB4F4
	str r0, [r5, #0xc]
	bl ov96_021EB5B8
	add r6, r0, #0
	mov r1, #1
	bl Sprite_SetOamMode
	add r0, r6, #0
	mov r1, #0x64
	bl Sprite_SetDrawPriority
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #8
	blt _021F30CC
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F30C4


	thumb_func_start ov96_021F30F8
ov96_021F30F8: ; 0x021F30F8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	cmp r5, #0xf
	bne _021F3104
	mov r0, #0
	pop {r4, r5, r6, pc}
_021F3104:
	cmp r5, #1
	bhs _021F310C
	mov r0, #0
	b _021F311E
_021F310C:
	cmp r5, #6
	bhs _021F3114
	mov r0, #1
	b _021F311E
_021F3114:
	cmp r5, #0xa
	bhs _021F311C
	mov r0, #2
	b _021F311E
_021F311C:
	mov r0, #3
_021F311E:
	cmp r1, #1
	bne _021F3128
	mov r4, #1
	mov r6, #5
	b _021F3136
_021F3128:
	cmp r1, #2
	bne _021F3132
	mov r4, #6
	mov r6, #4
	b _021F3136
_021F3132:
	mov r4, #0xa
	mov r6, #5
_021F3136:
	cmp r1, r0
	bne _021F316C
	cmp r5, r4
	bhs _021F3142
	bl GF_AssertFail
_021F3142:
	bl LCRandom
	sub r1, r6, #1
	bl _s32_div_f
	sub r0, r5, r4
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r0, r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r1, r6, #0
	bl _u32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	add r0, r0, r4
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	pop {r4, r5, r6, pc}
_021F316C:
	bl LCRandom
	add r1, r6, #0
	bl _s32_div_f
	add r0, r4, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021F30F8


	thumb_func_start ov96_021F3180
ov96_021F3180: ; 0x021F3180
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #4]
	cmp r0, #0xf
	bne _021F3194
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021F3194:
	mov r5, #0
	str r5, [sp, #0xc]
	lsl r4, r0, #2
_021F319A:
	ldr r0, _021F31E8 ; =ov96_0221DBC8
	ldr r1, [r0, r4]
	lsl r0, r5, #3
	add r3, r1, r0
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _021F31E2
	lsl r1, r0, #2
	ldr r0, _021F31EC ; =ov96_0221DBB8
	add r0, r0, r1
	sub r0, r0, #4
	ldr r0, [r0]
	add r1, r7, #0
	str r0, [sp, #8]
	ldrh r0, [r0]
	str r0, [sp]
	ldrh r2, [r3, #4]
	ldrh r3, [r3, #6]
	add r0, r6, #0
	bl ov96_021F32FC
	cmp r0, #0
	beq _021F31D8
	ldr r0, [sp, #8]
	ldrh r0, [r0, #2]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	strb r5, [r0]
	b _021F31E2
_021F31D8:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #4
	blo _021F319A
_021F31E2:
	ldr r0, [sp, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F31E8: .word ov96_0221DBC8
_021F31EC: .word ov96_0221DBB8
	thumb_func_end ov96_021F3180


	thumb_func_start ov96_021F31F0
ov96_021F31F0: ; 0x021F31F0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r1, [sp]
	add r5, r0, #0
	ldr r0, [sp]
	mov r7, #0
	lsl r1, r0, #2
	ldr r0, _021F3294 ; =ov96_0221DBC8
	ldr r4, [r0, r1]
_021F3202:
	ldr r0, [r4]
	cmp r0, #0
	beq _021F3288
	add r0, r5, #0
	add r0, #0x80
	ldr r0, [r0]
	lsl r0, r0, #4
	add r6, r5, r0
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _021F321C
	bl GF_AssertFail
_021F321C:
	mov r0, #1
	str r0, [r6]
	ldr r0, [sp]
	str r0, [r6, #8]
	add r0, r5, #0
	str r4, [r6, #4]
	add r0, #0x80
	ldr r0, [r0]
	lsl r0, r0, #4
	add r0, r5, r0
	ldr r0, [r0, #0xc]
	bl ov96_021EB5B8
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0x80
	ldr r0, [r0]
	mov r1, #1
	lsl r0, r0, #4
	add r0, r5, r0
	ldr r0, [r0, #0xc]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r1, [r4]
	add r0, r6, #0
	sub r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0
	str r0, [sp, #0xc]
	ldrh r0, [r4, #4]
	add r1, sp, #4
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	ldrh r0, [r4, #6]
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	add r0, r6, #0
	bl Sprite_SetMatrix
	add r0, r5, #0
	add r0, #0x80
	ldr r0, [r0]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1d
	sub r1, r1, r2
	mov r0, #0x1d
	ror r1, r0
	add r0, r5, #0
	add r1, r2, r1
	add r0, #0x80
	str r1, [r0]
_021F3288:
	add r7, r7, #1
	add r4, #8
	cmp r7, #4
	blt _021F3202
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F3294: .word ov96_0221DBC8
	thumb_func_end ov96_021F31F0


	thumb_func_start ov96_021F3298
ov96_021F3298: ; 0x021F3298
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	mov r4, #0
	mov r7, #0xf
_021F32A2:
	ldr r0, [r5, #8]
	cmp r6, r0
	bne _021F32BA
	str r7, [r5, #8]
	mov r0, #0
	str r0, [r5, #4]
	str r0, [r5]
	mov r1, #0
	ldr r0, [r5, #0xc]
	add r2, r1, #0
	bl ov96_021EB52C
_021F32BA:
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #8
	blt _021F32A2
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021F3298


	thumb_func_start ov96_021F32C4
ov96_021F32C4: ; 0x021F32C4
	push {r4, lr}
	mov r4, #0
	cmp r0, #5
	bhi _021F32F4
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021F32D8: ; jump table
	.short _021F32F4 - _021F32D8 - 2 ; case 0
	.short _021F32E4 - _021F32D8 - 2 ; case 1
	.short _021F32E8 - _021F32D8 - 2 ; case 2
	.short _021F32EC - _021F32D8 - 2 ; case 3
	.short _021F32F4 - _021F32D8 - 2 ; case 4
	.short _021F32F0 - _021F32D8 - 2 ; case 5
_021F32E4:
	mov r4, #1
	b _021F32F8
_021F32E8:
	mov r4, #2
	b _021F32F8
_021F32EC:
	mov r4, #3
	b _021F32F8
_021F32F0:
	mov r4, #4
	b _021F32F8
_021F32F4:
	bl GF_AssertFail
_021F32F8:
	add r0, r4, #0
	pop {r4, pc}
	thumb_func_end ov96_021F32C4


	thumb_func_start ov96_021F32FC
ov96_021F32FC: ; 0x021F32FC
	push {r3, lr}
	sub sp, #0x18
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	lsl r0, r1, #0xc
	str r0, [sp, #0x10]
	mov r1, #0
	lsl r0, r2, #0xc
	str r0, [sp]
	lsl r0, r3, #0xc
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r1, [sp, #0x14]
	str r1, [sp, #8]
	add r1, sp, #0
	add r2, r0, #0
	bl VEC_Subtract
	add r0, sp, #0xc
	bl VEC_Mag
	add r1, sp, #0x10
	ldrh r1, [r1, #0x10]
	lsl r1, r1, #0xc
	cmp r1, r0
	ble _021F3336
	add sp, #0x18
	mov r0, #1
	pop {r3, pc}
_021F3336:
	mov r0, #0
	add sp, #0x18
	pop {r3, pc}
	thumb_func_end ov96_021F32FC


	thumb_func_start ov96_021F333C
ov96_021F333C: ; 0x021F333C
	push {r4, r5, r6, r7}
	mov r4, #0
	add r3, r4, #0
	add r5, r4, #0
	lsl r2, r0, #2
_021F3346:
	ldr r0, _021F3388 ; =ov96_0221DBC8
	ldr r6, [r0, r2]
	add r0, r6, r5
	ldr r6, [r6, r5]
	cmp r6, #0
	bne _021F335C
	mov r0, #0
	str r0, [r1]
	strh r0, [r1, #4]
	strh r0, [r1, #6]
	b _021F3378
_021F335C:
	lsl r7, r6, #2
	ldr r6, _021F338C ; =ov96_0221DBB8
	add r6, r6, r7
	sub r6, r6, #4
	ldr r6, [r6]
	ldrh r6, [r6]
	str r6, [r1]
	ldrh r6, [r0, #4]
	strh r6, [r1, #4]
	ldrh r0, [r0, #6]
	strh r0, [r1, #6]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_021F3378:
	add r3, r3, #1
	add r5, #8
	add r1, #8
	cmp r3, #4
	blt _021F3346
	add r0, r4, #0
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
_021F3388: .word ov96_0221DBC8
_021F338C: .word ov96_0221DBB8
	thumb_func_end ov96_021F333C


	thumb_func_start ov96_021F3390
ov96_021F3390: ; 0x021F3390
	push {r4, r5, r6, lr}
	add r5, r1, #0
	ldr r1, _021F33D4 ; =0x000004EC
	add r6, r2, #0
	bl Heap_Alloc
	ldr r2, _021F33D4 ; =0x000004EC
	mov r1, #0
	add r4, r0, #0
	bl MI_CpuFill8
	ldr r0, _021F33D8 ; =0x000004E4
	mov r1, #4
	sub r2, r1, r5
	strb r5, [r4, r0]
	add r1, r0, #6
	strb r2, [r4, r1]
	ldrb r2, [r4, r1]
	add r1, r0, #5
	cmp r6, #0
	strb r2, [r4, r1]
	bne _021F33C0
	mov r1, #0x14
	b _021F33C2
_021F33C0:
	mov r1, #0xa
_021F33C2:
	add r0, r0, #3
	strb r1, [r4, r0]
	ldr r0, _021F33DC ; =0x000004E7
	ldrb r1, [r4, r0]
	sub r0, r0, #1
	strb r1, [r4, r0]
	add r0, r4, #0
	pop {r4, r5, r6, pc}
	nop
_021F33D4: .word 0x000004EC
_021F33D8: .word 0x000004E4
_021F33DC: .word 0x000004E7
	thumb_func_end ov96_021F3390


	thumb_func_start ov96_021F33E0
ov96_021F33E0: ; 0x021F33E0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	lsl r4, r1, #5
	add r0, r5, r4
	str r2, [r0, #4]
	ldr r2, [sp, #0x10]
	str r3, [r0, #8]
	str r2, [r0, #0xc]
	ldr r2, [sp, #0x14]
	str r2, [r0, #0x10]
	mov r2, #0
	mvn r2, r2
	str r2, [r5, r4]
	ldr r2, [sp, #0x1c]
	str r1, [r0, #0x14]
	str r2, [r0, #0x1c]
	add r0, r1, #0
	mov r1, #3
	bl _s32_div_f
	ldr r1, _021F3420 ; =0x000004E9
	ldrb r1, [r5, r1]
	cmp r0, r1
	blt _021F3418
	ldr r1, [sp, #0x18]
	add r0, r5, r4
	str r1, [r0, #0x18]
	pop {r3, r4, r5, pc}
_021F3418:
	mov r1, #0
	add r0, r5, r4
	str r1, [r0, #0x18]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021F3420: .word 0x000004E9
	thumb_func_end ov96_021F33E0

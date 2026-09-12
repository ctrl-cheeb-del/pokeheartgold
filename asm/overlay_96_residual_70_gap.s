	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	.public ov96_021F9380
	.public ov96_021F94A8

	thumb_func_start ov96_021F9380
ov96_021F9380: ; 0x021F9380
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r1, #0
	str r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r7, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	bne _021F93A6
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021F93A0
	mov r0, #1
	strb r0, [r4]
_021F93A0:
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021F93A6:
	ldr r0, [sp]
	bl ov96_021E5F24
	add r4, r0, #0
	mov r0, #0
	add r2, r0, #0
	add r3, r7, #0
_021F93B4:
	add r1, r3, #0
	add r1, #0xe2
	ldrh r1, [r1]
	add r2, r2, #1
	add r3, #0x6c
	add r0, r0, r1
	cmp r2, #3
	blt _021F93B4
	bl ov96_021FBDEC
	add r2, r0, #0
	lsl r1, r4, #0x18
	lsl r2, r2, #0x10
	ldr r0, [sp]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x10
	bl PokeathlonCourse_SetField5E0_AtIndex
	cmp r4, #0
	bne _021F94A0
	ldr r0, [sp]
	bl PokeathlonCourse_GetParticipantCount
	str r0, [sp, #8]
	str r0, [sp, #0x10]
	cmp r0, #4
	bge _021F94A0
_021F93EA:
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #8]
	sub r1, r1, r0
	lsl r0, r1, #1
	add r6, r1, r0
_021F93FA:
	mov r0, #0x28
	mul r0, r6
	add r5, r7, r0
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _021F9466
	mov r0, #9
	lsl r0, r0, #6
	mov r1, #0x92
	ldr r4, [r5, r0]
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r0, r4, #0
	bl _fls
	bhs _021F9424
	mov r0, #0x92
	lsl r0, r0, #2
	ldr r4, [r5, r0]
_021F9424:
	mov r0, #0x96
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	mov r0, #1
	lsl r0, r0, #0xc
	sub r0, r0, r1
	bl _fflt
	add r1, r4, #0
	bl _fdiv
	str r0, [sp, #0x14]
	bl _ffix
	add r4, r0, #0
	bl _fflt
	add r1, r0, #0
	ldr r0, [sp, #0x14]
	bl _fsub
	mov r1, #0
	bl _fgr
	bls _021F9458
	add r4, r4, #1
_021F9458:
	mov r0, #0x23
	lsl r0, r0, #4
	ldr r0, [r7, r0]
	add r1, r0, r4
	mov r0, #0x95
	lsl r0, r0, #2
	str r1, [r5, r0]
_021F9466:
	mov r0, #0x95
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r0, r0, r1
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #3
	blt _021F93FA
	ldr r0, [sp, #4]
	bl ov96_021FBDEC
	add r2, r0, #0
	ldr r1, [sp, #0x10]
	lsl r2, r2, #0x10
	lsl r1, r1, #0x18
	ldr r0, [sp]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x10
	bl PokeathlonCourse_SetField5E0_AtIndex
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #4
	blt _021F93EA
_021F94A0:
	mov r0, #1
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F9380

	thumb_func_start ov96_021F94A8
ov96_021F94A8: ; 0x021F94A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x180
	add r6, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetField1ED
	cmp r0, #8
	bls _021F94C0
	b _021F9C8A
_021F94C0:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021F94CC: ; jump table
	.short _021F94DE - _021F94CC - 2 ; case 0
	.short _021F95E8 - _021F94CC - 2 ; case 1
	.short _021F9884 - _021F94CC - 2 ; case 2
	.short _021F9A94 - _021F94CC - 2 ; case 3
	.short _021F9ABA - _021F94CC - 2 ; case 4
	.short _021F9AE2 - _021F94CC - 2 ; case 5
	.short _021F9B1E - _021F94CC - 2 ; case 6
	.short _021F9B38 - _021F94CC - 2 ; case 7
	.short _021F9C7C - _021F94CC - 2 ; case 8
_021F94DE:
	mov r2, #0x12
	mov r0, #0x5c
	mov r1, #0x8a
	lsl r2, r2, #0xe
	bl Heap_Create
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _021F986C ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021F9870 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	bl ov96_021F9E3C
	mov r1, #0xf2
	add r0, r6, #0
	lsl r1, r1, #2
	bl PokeathlonCourse_AllocPtr4FromHeap
	mov r2, #0xf2
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x8a
	bl BgConfig_Alloc
	str r0, [r4, #4]
	ldr r0, [r4]
	bl ov96_021FC028
	add r1, r4, #0
	add r1, #0xd8
	str r0, [r1]
	ldr r0, [r4]
	bl ov96_021FC618
	add r1, r4, #0
	add r1, #0xdc
	str r0, [r1]
	add r0, r4, #0
	add r0, #0xd8
	ldr r0, [r0]
	bl ov96_021FC0E4
	add r5, r0, #0
	add r0, r4, #0
	add r0, #0xd8
	ldr r0, [r0]
	bl ov96_021FC0E8
	add r7, r0, #0
	add r0, r4, #0
	add r0, #0xd8
	ldr r0, [r0]
	bl ov96_021FC0F4
	add r3, r0, #0
	add r0, r6, #0
	add r1, r5, #0
	add r2, r7, #0
	bl PokeathlonCourse_SetField3A4
	add r0, r6, #0
	mov r1, #8
	bl ov96_021E6670
	mov r0, #0x6b
	str r0, [sp, #0xdc]
	mov r0, #1
	lsl r0, r0, #0x12
	str r0, [sp, #0xe0]
	lsr r0, r0, #4
	mov r2, #0x8a
	str r0, [sp, #0xe4]
	ldr r3, _021F9874 ; =0x00300010
	str r2, [sp, #0xe8]
	add r0, sp, #0xdc
	mov r1, #0x12
	str r3, [sp]
	bl ov96_021E92B0
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x7e
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x8a
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	mov r1, #0x8a
	str r1, [r4]
	mov r0, #4
	bl FontID_Alloc
	ldr r0, [r4, #4]
	bl ov96_021F9E5C
	add r0, r4, #0
	bl ov96_021FB7C8
	ldr r0, _021F9878 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F95E8:
	ldr r5, _021F987C ; =ov96_0221C404
	add r3, sp, #0xd0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r4]
	bl ov96_021EB180
	mov r2, #0x89
	lsl r2, r2, #2
	mov r1, #0
	str r0, [r4, r2]
	str r1, [sp]
	ldr r0, [r4, r2]
	mov r2, #0x11
	lsl r2, r2, #0x10
	add r3, r1, #0
	bl ov96_021EB5C8
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	mov r2, #0x65
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	mov r2, #0x66
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	mov r2, #0x67
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #3
	mov r2, #0x68
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #4
	mov r2, #0x69
	bl ov96_021EB29C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #5
	mov r2, #0x6a
	bl ov96_021EB29C
	mov r0, #3
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #9
	mov r3, #0x65
	bl ov96_021EB2BC
	mov r0, #3
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #6
	mov r3, #0x65
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #8
	mov r3, #0x65
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #7
	mov r3, #0x65
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x10
	mov r3, #0x66
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xd
	mov r3, #0x66
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xf
	mov r3, #0x66
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xe
	mov r3, #0x66
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xc
	mov r3, #0x67
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #6
	mov r3, #0x67
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xb
	mov r3, #0x67
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0xa
	mov r3, #0x67
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x14
	mov r3, #0x69
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x11
	mov r3, #0x69
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x13
	mov r3, #0x69
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x12
	mov r3, #0x69
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1c
	mov r3, #0x68
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x19
	mov r3, #0x68
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1b
	mov r3, #0x68
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1a
	mov r3, #0x68
	bl ov96_021EB36C
	mov r0, #1
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x20
	mov r3, #0x6a
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1d
	mov r3, #0x6a
	bl ov96_021EB2F4
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1f
	mov r3, #0x6a
	bl ov96_021EB334
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x9c
	mov r2, #0x1e
	mov r3, #0x6a
	bl ov96_021EB36C
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB3A4
	ldr r0, [r4]
	ldr r1, _021F9880 ; =0x000002E7
	mov r2, #1
	bl ov96_021E9A78
	mov r1, #0x3a
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB5E8
	mov r3, #0x3a
	str r0, [sp]
	lsl r3, r3, #4
	ldr r0, [r4]
	ldr r3, [r4, r3]
	mov r1, #3
	mov r2, #4
	bl ov96_021EA854
	mov r1, #0xe9
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
	nop
_021F986C: .word 0xFFFFE0FF
_021F9870: .word 0x04001000
_021F9874: .word 0x00300010
_021F9878: .word gSystem + 0x60
_021F987C: .word ov96_0221C404
_021F9880: .word 0x000002E7
_021F9884:
	mov r5, #0
	mov r7, #2
_021F9888:
	mov r0, #0x89
	str r7, [sp]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	mov r2, #3
	mov r3, #0x65
	bl ov96_021EB408
	mov r1, #0x1b
	bl Sprite_SetDrawPriority
	mov r0, #6
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x67
	bl ov96_021EB408
	mov r1, #0x1b
	bl Sprite_SetDrawPriority
	add r5, r5, #1
	cmp r5, #0xc
	blt _021F9888
	mov r5, #0
	mov r7, #5
_021F98C4:
	mov r0, #0x89
	str r7, [sp]
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x66
	bl ov96_021EB408
	mov r0, #7
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x68
	bl ov96_021EB408
	mov r0, #8
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x69
	bl ov96_021EB408
	add r5, r5, #1
	cmp r5, #3
	blt _021F98C4
	mov r0, #9
	str r0, [sp]
	mov r0, #0x89
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	mov r1, #0xea
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0
	bl ov96_021EB564
	mov r0, #0
	str r0, [sp, #0xcc]
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r0, [sp, #0xc4]
	mov r0, #0x72
	lsl r0, r0, #0xe
	str r0, [sp, #0xc8]
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0xc4
	bl ov96_021EB588
	mov r0, #0xea
	lsl r0, r0, #2
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov96_021EB630
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, _021F9C90 ; =ov96_0221C3F4
	ldr r7, _021F9C94 ; =ov96_0221C3EC
	add r5, r4, #0
	str r0, [sp, #0x18]
_021F9968:
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EB5E8
	add r1, r0, #0
	mov r0, #0x3a
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	ldr r3, [r4]
	mov r2, #0
	bl ov96_021EA374
	mov r1, #0xeb
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [sp, #0x18]
	add r1, sp, #0xb8
	ldrb r0, [r0]
	lsl r0, r0, #0xc
	str r0, [sp, #0xb8]
	mov r0, #0x72
	lsl r0, r0, #0xe
	str r0, [sp, #0xbc]
	mov r0, #0
	str r0, [sp, #0xc0]
	mov r0, #0xeb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Sprite_SetMatrix
	mov r0, #0xeb
	lsl r0, r0, #2
	ldrb r1, [r7]
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [sp, #0x18]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r7, r7, #1
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #6
	blt _021F9968
	add r0, r4, #0
	mov r1, #0x89
	add r0, #0xdc
	lsl r1, r1, #2
	ldr r0, [r0]
	ldr r1, [r4, r1]
	mov r2, #1
	bl ov96_021FC630
	ldr r0, [r4]
	bl ov96_021FC188
	mov r1, #0x8a
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r7, #0
	add r5, sp, #0x88
_021F99F2:
	add r0, r6, #0
	add r1, r7, #0
	bl PokeathlonCourse_GetParticipantUnk04
	mov r1, #0
_021F99FC:
	ldrh r2, [r0]
	add r1, r1, #1
	strh r2, [r5]
	ldrh r2, [r0, #2]
	add r0, #0x28
	strh r2, [r5, #2]
	add r5, r5, #4
	cmp r1, #3
	blt _021F99FC
	add r7, r7, #1
	cmp r7, #4
	blt _021F99F2
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x88
	bl ov96_021FC214
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov96_021FC2B4
	add r0, sp, #0x58
	mov r5, #0
	str r0, [sp, #0x1c]
	add r7, sp, #0x13c
_021F9A34:
	add r0, r6, #0
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r3, [sp, #0x1c]
	add r0, r6, #0
	add r2, r5, #0
	bl ov96_021E6168
	add r0, r6, #0
	bl ov96_021E5F24
	add r1, r0, #0
	add r0, r6, #0
	add r2, r5, #0
	bl ov96_021E60C0
	bl ov96_021E6108
	str r0, [r7, #0x14]
	ldr r0, [sp, #0x1c]
	add r5, r5, #1
	add r0, #0x10
	add r7, r7, #4
	str r0, [sp, #0x1c]
	cmp r5, #3
	blt _021F9A34
	mov r0, #1
	mov r1, #0
	str r1, [sp, #0x13c]
	str r0, [sp, #0x140]
	str r1, [sp, #0x144]
	str r0, [sp, #0x148]
	str r0, [sp, #0x14c]
	str r1, [sp]
	mov r0, #0xe9
	str r1, [sp, #4]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #3
	add r2, sp, #0x58
	add r3, sp, #0x13c
	bl ov96_021EA8A8
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9A94:
	mov r0, #0xe9
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EAA00
	cmp r0, #0
	bne _021F9AA4
	b _021F9C8A
_021F9AA4:
	ldr r0, [r4, #4]
	bl PokeathlonCourse_SetVBlankIntrCB
	ldr r0, [r4, #4]
	ldr r1, [r4]
	bl ov96_021F9FE8
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9ABA:
	ldr r0, [r4, #4]
	ldr r1, [r4]
	bl ov96_021FA020
	mov r1, #5
	ldr r0, _021F9C98 ; =0x04000010
	lsl r1, r1, #0x16
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	mov r1, #3
	ldr r0, _021F9C9C ; =0x04001010
	lsl r1, r1, #0x14
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9AE2:
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add r0, r6, #0
	mov r1, #1
	bl PokeathlonCourse_SetField1F4
	mov r7, #0xe9
	mov r5, #0
	lsl r7, r7, #2
_021F9B00:
	lsl r1, r5, #0x18
	ldr r0, [r4, r7]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	mov r1, #1
	bl ov96_021EAB38
	add r5, r5, #1
	cmp r5, #3
	blt _021F9B00
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9B1E:
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021F9B30
	add r4, #0xd8
	ldr r0, [r4]
	bl ov96_021FC144
_021F9B30:
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9B38:
	add r0, r4, #0
	mov r1, #0x89
	add r0, #0xd8
	lsl r1, r1, #2
	ldr r0, [r0]
	ldr r1, [r4, r1]
	bl ov96_021FC07C
	mov r2, #0x3a
	mov r3, #0x89
	lsl r2, r2, #4
	lsl r3, r3, #2
	mov r1, #0x11
	ldr r2, [r4, r2]
	ldr r3, [r4, r3]
	add r0, r6, #0
	lsl r1, r1, #4
	bl ov96_021E6290
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_SetDrawPriority
	ldr r3, _021F9CA0 ; =ov96_0221C410
	add r2, sp, #0x4c
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #0xaa
	str r0, [r2]
	add r0, sp, #0x28
	mov r2, #0xa
	bl ReadWholeNarcMemberByIdPair
	add r0, sp, #0xec
	mov r1, #0xaa
	mov r2, #0
	bl ReadWholeNarcMemberByIdPair
	mov r0, #0
	str r0, [sp, #0x24]
	add r0, r4, #0
	str r0, [sp, #0x20]
	add r0, #0xe0
	str r0, [sp, #0x20]
	add r7, sp, #0x4c
	add r5, sp, #0x40
_021F9B96:
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r3, r4, #0
	str r0, [sp]
	mov r0, #0xe9
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r3, #0xd8
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	add r1, sp, #0xec
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	ldr r0, [sp, #0x20]
	add r2, sp, #0x28
	str r0, [sp, #0xc]
	ldr r3, [r3]
	add r0, r6, #0
	bl ov96_021FA0E8
	ldr r0, [r7]
	add r7, r7, #4
	strh r0, [r5]
	mov r0, #0x62
	lsl r0, r0, #2
	strh r0, [r5, #2]
	ldr r0, [sp, #0x20]
	add r5, r5, #4
	add r0, #0x6c
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	add r0, r0, #1
	str r0, [sp, #0x24]
	cmp r0, #3
	blt _021F9B96
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	add r0, sp, #0x40
	mov r2, #0x3a
	mov r3, #0x89
	str r0, [sp, #8]
	lsl r2, r2, #4
	lsl r3, r3, #2
	ldr r2, [r4, r2]
	ldr r3, [r4, r3]
	add r0, r6, #0
	mov r1, #0
	bl ov96_021E634C
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021F9C12
	add r0, r6, #0
	add r1, sp, #0xec
	bl ov96_021FBBB4
_021F9C12:
	add r0, r6, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r5, r0, #0
	add r0, #0xf0
	bl ov96_021E8A20
	mov r3, #0
	mov r1, #0x11
_021F9C24:
	add r2, r0, r3
	strb r1, [r2, #0x1c]
	add r2, r3, #1
	lsl r2, r2, #0x18
	lsr r3, r2, #0x18
	cmp r3, #6
	blo _021F9C24
	add r0, r6, #0
	bl ov96_021E5F24
	cmp r0, #0
	bne _021F9C56
	add r5, #0x28
	add r0, r5, #0
	bl ov96_021E8A20
	mov r3, #0
	mov r2, #0x11
_021F9C48:
	add r1, r0, r3
	strb r2, [r1, #0x1c]
	add r1, r3, #1
	lsl r1, r1, #0x18
	lsr r3, r1, #0x18
	cmp r3, #6
	blo _021F9C48
_021F9C56:
	mov r0, #1
	bl sub_0203A994
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	add r0, r6, #0
	bl PokeathlonCourse_IncrementField1ED
	b _021F9C8A
_021F9C7C:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021F9C8A
	add sp, #0x180
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021F9C8A:
	mov r0, #0
	add sp, #0x180
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F9C90: .word ov96_0221C3F4
_021F9C94: .word ov96_0221C3EC
_021F9C98: .word 0x04000010
_021F9C9C: .word 0x04001010
_021F9CA0: .word ov96_0221C410
	thumb_func_end ov96_021F94A8

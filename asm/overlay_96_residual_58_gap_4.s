	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.public ov96_021F46BC
	.public ov96_021F4700
	.public ov96_021F4724
	.public ov96_021F4790
	.public ov96_021F47F0
	.public ov96_021F480C
	.public ov96_021F48A8
	.public ov96_021F48FC
	.public ov96_021F4990
	.public ov96_021F4A60
	.public ov96_021F4A9C
	.public ov96_021F4AE0
	.public ov96_021F4B34
	.public ov96_021F4BB4
	.public ov96_021F4CAC
	.public ov96_021F4DAC
	.public ov96_021F4E5C
	.public ov96_021F4E9C
	.public ov96_021F4EF8
	.public ov96_021F4FD8
	.public ov96_021F5018

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

	thumb_func_start ov96_021F4E9C
ov96_021F4E9C: ; 0x021F4E9C
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r2, #0
	cmp r0, #0xf
	bhi _021F4EB8
	ldr r5, [r1]
	ldr r1, [r1, #4]
	sub r1, r1, r5
	mul r0, r1
	mov r1, #0xf
	bl _s32_div_f
	add r5, r5, r0
	b _021F4ED8
_021F4EB8:
	bls _021F4EC2
	cmp r0, #0x3c
	bhi _021F4EC2
	ldr r5, [r1, #4]
	b _021F4ED8
_021F4EC2:
	ldr r5, [r1, #4]
	ldr r1, [r1, #8]
	sub r0, #0x3c
	lsl r0, r0, #0x18
	sub r1, r1, r5
	lsr r0, r0, #0x18
	mul r0, r1
	mov r1, #0xa
	bl _s32_div_f
	add r5, r5, r0
_021F4ED8:
	add r0, r4, #0
	bl ov96_021EB5B8
	mov r1, #2
	lsl r1, r1, #0x12
	str r1, [sp]
	lsl r1, r1, #2
	add r1, r5, r1
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	add r1, sp, #0
	bl Sprite_SetMatrix
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end ov96_021F4E9C
	thumb_func_start ov96_021F4EF8
ov96_021F4EF8: ; 0x021F4EF8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	add r0, #0xe8
	ldrb r7, [r0]
	add r6, r1, #0
	mov r1, #0x64
	add r0, r7, #0
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #3]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0]
	add r0, r7, #0
	mov r1, #0xa
	bl _s32_div_f
	mov r1, #0xa
	mul r1, r4
	sub r0, r0, r1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #4]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0, #1]
	add r0, r7, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #5]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0, #2]
	mov r4, #0
	mov r7, #4
_021F4F86:
	str r7, [sp]
	mov r0, #8
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #0xb0
	ldr r0, [r0]
	lsl r2, r4, #2
	add r0, #0xc
	str r0, [sp, #8]
	add r0, sp, #0x1c
	add r0, #3
	ldrb r0, [r0, r4]
	add r2, r2, #3
	lsl r2, r2, #0x18
	str r0, [sp, #0xc]
	add r0, sp, #0x1c
	ldrb r0, [r0, r4]
	mov r1, #6
	lsr r2, r2, #0x18
	str r0, [sp, #0x10]
	mov r0, #0x14
	str r0, [sp, #0x14]
	mov r0, #0x10
	str r0, [sp, #0x18]
	add r0, r6, #0
	mov r3, #7
	bl CopyRectToBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021F4F86
	add r0, r5, #0
	add r0, #0xe8
	ldrb r0, [r0]
	add r5, #0xe9
	strb r0, [r5]
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F4EF8
	thumb_func_start ov96_021F4FD8
ov96_021F4FD8: ; 0x021F4FD8
	push {r3, r4, r5, r6}
	add r5, r0, #0
	ldr r0, [r1, #8]
	add r3, r1, #0
	lsl r0, r0, #0xf
	lsr r4, r0, #0x10
	add r3, #0xc
	mov r2, #0
	cmp r4, #0
	ble _021F5010
	ldr r6, _021F5014 ; =0x00000FFF
_021F4FEE:
	ldrh r0, [r3]
	add r2, r2, #1
	add r1, r0, #0
	and r1, r6
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	sub r0, r0, r1
	add r1, r1, r5
	lsl r0, r0, #0x18
	lsl r1, r1, #0x10
	lsr r0, r0, #0x18
	lsr r1, r1, #0x10
	add r0, r0, r1
	strh r0, [r3]
	add r3, r3, #2
	cmp r2, r4
	blt _021F4FEE
_021F5010:
	pop {r3, r4, r5, r6}
	bx lr
	.balign 4, 0
_021F5014: .word 0x00000FFF
	thumb_func_end ov96_021F4FD8
	thumb_func_start ov96_021F5018
ov96_021F5018: ; 0x021F5018
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x120
	str r0, [sp, #0x14]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetField1ED
	cmp r0, #6
	bls _021F5030
	b _021F54AE
_021F5030:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021F503C: ; jump table
	.short _021F504A - _021F503C - 2 ; case 0
	.short _021F5128 - _021F503C - 2 ; case 1
	.short _021F516A - _021F503C - 2 ; case 2
	.short _021F51CA - _021F503C - 2 ; case 3
	.short _021F522C - _021F503C - 2 ; case 4
	.short _021F5374 - _021F503C - 2 ; case 5
	.short _021F54A2 - _021F503C - 2 ; case 6
_021F504A:
	mov r2, #5
	mov r0, #0x5c
	mov r1, #0x8f
	lsl r2, r2, #0x10
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
	ldr r0, _021F53C0 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021F53C4 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	bl ov96_021F5630
	ldr r0, [sp, #0x14]
	ldr r1, _021F53C8 ; =0x00001004
	bl PokeathlonCourse_AllocPtr4FromHeap
	ldr r2, _021F53C8 ; =0x00001004
	mov r1, #0
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x8f
	bl BgConfig_Alloc
	str r0, [r4]
	ldr r0, [sp, #0x14]
	mov r1, #8
	bl ov96_021E6670
	mov r0, #0xd5
	str r0, [sp, #0xcc]
	mov r0, #1
	lsl r0, r0, #0x12
	str r0, [sp, #0xd0]
	lsr r0, r0, #4
	str r0, [sp, #0xd4]
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetHeapID
	str r0, [sp, #0xd8]
	ldr r3, _021F53CC ; =0x00300010
	add r0, sp, #0xcc
	mov r1, #0xf
	mov r2, #0x8f
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
	mov r2, #0x8f
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	mov r0, #0x8f
	str r0, [r4, #0x54]
	ldr r1, [r4, #0x54]
	mov r0, #4
	bl FontID_Alloc
	ldr r0, [r4]
	bl ov96_021F584C
	add r0, r4, #0
	bl ov96_021F6138
	ldr r0, _021F53D0 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	ldr r1, [r4, #0x54]
	mov r0, #0xc
	bl GF_CreateVramTransferManager
	ldr r1, [r4, #0x54]
	mov r0, #0xc
	bl sub_02020654
	mov r1, #1
	lsl r1, r1, #0xc
	str r0, [r4, r1]
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	b _021F54AE
_021F5128:
	ldr r0, [r4, #0x54]
	bl ov96_021F74A4
	add r1, r4, #0
	add r1, #0x8c
	str r0, [r1]
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetParticipantCount
	add r5, r0, #0
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetMode
	add r6, r0, #0
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetDataCopyArea
	add r3, r0, #0
	ldr r0, [sp, #0x14]
	mov r1, #4
	str r0, [sp]
	ldr r0, [r4, #0x54]
	sub r1, r1, r5
	add r2, r6, #0
	bl ov96_021F7684
	mov r1, #0x4e
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	b _021F54AE
_021F516A:
	ldr r5, _021F53D4 ; =ov96_0221C0B8
	add r3, sp, #0xc0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r4, #0x54]
	bl ov96_021EB180
	mov r1, #0
	str r0, [r4, #0x60]
	str r1, [sp]
	mov r2, #3
	ldr r0, [r4, #0x60]
	lsl r2, r2, #0x12
	add r3, r1, #0
	bl ov96_021EB5C8
	ldr r0, [r4, #0x60]
	bl ov96_021EB5E8
	str r0, [sp]
	ldr r0, [r4, #0x54]
	mov r1, #3
	mov r2, #0xa
	mov r3, #0
	bl ov96_021EA854
	mov r1, #0x63
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, #0x60]
	mov r1, #0
	mov r2, #0x65
	bl ov96_021EB29C
	ldr r0, [r4, #0x60]
	bl ov96_021F6C18
	ldr r0, [r4, #0x60]
	bl ov96_021EB3A4
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	b _021F54AE
_021F51CA:
	ldr r0, [sp, #0x14]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	mov r5, #0
	add r7, sp, #0x90
	add r6, sp, #0xdc
_021F51DC:
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_021E6168
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	add r2, r5, #0
	bl ov96_021E60C0
	bl ov96_021E6108
	str r0, [r6, #0x14]
	add r5, r5, #1
	add r7, #0x10
	add r6, r6, #4
	cmp r5, #3
	blt _021F51DC
	mov r0, #1
	mov r1, #3
	mov r2, #0
	str r2, [sp, #0xdc]
	str r0, [sp, #0xe0]
	str r0, [sp, #0xe4]
	mov r0, #0x63
	str r1, [sp, #0xe8]
	str r1, [sp, #0xec]
	str r2, [sp]
	str r2, [sp, #4]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r2, sp, #0x90
	add r3, sp, #0xdc
	bl ov96_021EA8A8
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	b _021F54AE
_021F522C:
	mov r0, #0x63
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov96_021EAA00
	cmp r0, #0
	bne _021F523C
	b _021F54AE
_021F523C:
	ldr r0, [r4, #0x54]
	ldr r1, _021F53D8 ; =0x000003A1
	mov r2, #1
	bl ov96_021E9A78
	mov r2, #0x62
	lsl r2, r2, #2
	str r0, [r4, r2]
	ldr r0, [sp, #0x14]
	ldr r2, [r4, r2]
	ldr r3, [r4, #0x60]
	mov r1, #0xc0
	bl ov96_021E6290
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_SetDrawPriority
	ldr r0, [r4]
	bl PokeathlonCourse_SetVBlankIntrCB
	ldr r0, [sp, #0x14]
	mov r1, #1
	bl PokeathlonCourse_SetField1F4
	add r0, sp, #0x78
	mov r1, #0xaa
	mov r2, #0x10
	bl ReadWholeNarcMemberByIdPair
	mov r0, #0
	str r0, [sp, #0x24]
	add r0, r4, #0
	str r0, [sp, #0x1c]
	add r0, #0x90
	str r0, [sp, #0x1c]
	mov r6, #0x40
	add r7, sp, #0x6c
_021F5288:
	mov r0, #0x63
	ldr r1, [sp, #0x24]
	lsl r0, r0, #2
	lsl r1, r1, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	mov r1, #1
	add r5, r0, #0
	bl ov96_021EAB38
	ldr r0, [sp, #0x1c]
	ldr r2, [sp, #0x24]
	str r5, [r0]
	ldr r0, [sp, #0x14]
	mov r1, #0
	bl ov96_021E60C0
	bl ov96_021E6138
	lsl r1, r0, #3
	add r0, sp, #0x78
	add r2, r0, r1
	add r1, r2, #0
	sub r1, #8
	sub r2, r2, #4
	ldr r1, [r1]
	ldr r2, [r2]
	add r0, r5, #0
	bl ov96_021EAF70
	add r0, r5, #0
	mov r1, #2
	bl ov96_021EAC0C
	mov r2, #0x12
	add r0, r5, #0
	add r1, r6, #0
	lsl r2, r2, #4
	bl ov96_021EAF94
	bl ov96_021E6104
	add r1, r0, #0
	add r0, r5, #0
	bl ov96_021EAF6C
	mov r2, #0x12
	ldr r1, [sp, #0x1c]
	lsl r0, r6, #0xc
	str r0, [r1, #8]
	lsl r2, r2, #0x10
	str r2, [r1, #0xc]
	str r0, [r1, #0x1c]
	add r0, sp, #0x28
	str r0, [sp]
	add r0, r5, #0
	add r1, r6, #0
	lsr r2, r2, #0xc
	add r3, sp, #0x2c
	bl ov96_021EB0A4
	ldr r0, [sp, #0x2c]
	add r6, #0x40
	strh r0, [r7]
	ldr r0, [sp, #0x28]
	strh r0, [r7, #2]
	ldr r0, [sp, #0x1c]
	add r7, r7, #4
	add r0, #0x38
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x24]
	add r0, r0, #1
	str r0, [sp, #0x24]
	cmp r0, #3
	blt _021F5288
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	add r0, sp, #0x6c
	str r0, [sp, #8]
	mov r2, #0x62
	lsl r2, r2, #2
	ldr r0, [sp, #0x14]
	ldr r2, [r4, r2]
	ldr r3, [r4, #0x60]
	mov r1, #0
	bl ov96_021E634C
	mov r0, #5
	mov r1, #3
	lsl r0, r0, #6
	strb r1, [r4, r0]
	add r0, r4, #0
	bl ov96_021F5980
	ldr r1, [r4, #0x60]
	add r0, r4, #0
	bl ov96_021F6C5C
	add r0, r4, #0
	bl ov96_021F7050
	ldr r0, [sp, #0x14]
	bl ov96_021E5F24
	add r1, r0, #0
	lsl r1, r1, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_021F6DA4
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	b _021F54AE
_021F5374:
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add r0, sp, #0x30
	mov r1, #0xaa
	mov r2, #6
	bl ReadWholeNarcMemberByIdPair
	add r6, r4, #0
	mov r5, #0
	add r6, #0x90
	add r7, sp, #0x30
_021F539E:
	lsl r2, r5, #0x18
	ldr r0, [sp, #0x14]
	add r1, r7, #0
	lsr r2, r2, #0x18
	add r3, r6, #0
	bl ov96_021F715C
	add r5, r5, #1
	add r6, #0x38
	cmp r5, #3
	blt _021F539E
	ldr r0, [sp, #0x14]
	bl ov96_021E5F24
	mov r1, #0x4f
	ldr r0, _021F53DC ; =0x00000708
	b _021F53E0
	.balign 4, 0
_021F53C0: .word 0xFFFFE0FF
_021F53C4: .word 0x04001000
_021F53C8: .word 0x00001004
_021F53CC: .word 0x00300010
_021F53D0: .word gSystem + 0x60
_021F53D4: .word ov96_0221C0B8
_021F53D8: .word 0x000003A1
_021F53DC: .word 0x00000708
_021F53E0:
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r1, [r4, r1]
	add r0, r4, #0
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	bl ov96_021F6F3C
	ldr r0, [sp, #0x14]
	add r1, r4, #0
	bl ov96_021F6F80
	mov r2, #0
	mov r7, #0x9a
	mov r0, #0xba
	mov r1, #0xda
	add r3, r4, #0
	add r5, r2, #0
	lsl r7, r7, #4
	lsl r0, r0, #4
	lsl r1, r1, #4
_021F540A:
	mov r6, #0x1a
	lsl r6, r6, #4
	str r5, [r3, r6]
	mov r6, #0x3a
	lsl r6, r6, #4
	str r5, [r3, r6]
	mov r6, #0x5a
	lsl r6, r6, #4
	str r5, [r3, r6]
	mov r6, #0x7a
	lsl r6, r6, #4
	str r5, [r3, r6]
	str r5, [r3, r7]
	str r5, [r3, r0]
	str r5, [r3, r1]
	add r2, r2, #1
	add r3, r3, #4
	cmp r2, #0x80
	blt _021F540A
	mov r6, #0x40
	add r7, r4, #0
	str r4, [sp, #0x20]
_021F5436:
	ldr r0, _021F54B4 ; =0x00000FB4
	mov r1, #0
	str r1, [r4, r0]
	lsr r0, r6, #0x1f
	add r0, r6, r0
	asr r1, r0, #1
	mov r0, #0xfa
	lsl r0, r0, #4
	str r1, [r7, r0]
	add r0, r6, #0
	bl _fflt
	bl _f2d
	ldr r3, _021F54B8 ; =0x40500000
	mov r2, #0
	bl _ddiv
	mov r3, #1
	mov r2, #0
	lsl r3, r3, #0x1e
	bl _dsub
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021F54BC ; =0x40B00000
	mov r0, #0
	bl _dmul
	bl _dfix
	mov r1, #0xfb
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r1, [sp, #0x20]
	mov r0, #1
	add r1, #0xb8
	strb r0, [r1]
	ldr r0, [sp, #0x20]
	add r5, r5, #1
	add r0, #0x38
	add r4, #0x1c
	add r6, #0x40
	add r7, r7, #4
	str r0, [sp, #0x20]
	cmp r5, #3
	blt _021F5436
	mov r0, #1
	bl sub_0203A994
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	b _021F54AE
_021F54A2:
	add r0, r4, #0
	bl ov96_021F6E38
	add sp, #0x120
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021F54AE:
	mov r0, #0
	add sp, #0x120
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F54B4: .word 0x00000FB4
_021F54B8: .word 0x40500000
_021F54BC: .word 0x40B00000
	thumb_func_end ov96_021F5018

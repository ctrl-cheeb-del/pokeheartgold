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

	thumb_func_start ov96_021EF2C0
ov96_021EF2C0: ; 0x021EF2C0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	mov r2, #1
	mov r0, #0x5c
	mov r1, #0x88
	lsl r2, r2, #0x12
	bl Heap_Create
	ldr r0, _021EF390 ; =FS_OVERLAY_ID(OVY_98)
	mov r1, #2
	mov r6, #0x88
	bl HandleLoadOverlay
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
	ldr r0, _021EF394 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _021EF398 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	bl ov96_021EF260
	add r0, r5, #0
	mov r1, #0x48
	bl PokeathlonCourse_AllocPtr4FromHeap
	mov r1, #0
	mov r2, #0x48
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0xdd
	add r1, r6, #0
	bl NARC_New
	str r0, [r4, #8]
	add r0, r6, #0
	bl BgConfig_Alloc
	str r0, [r4, #4]
	add r0, r5, #0
	bl ov96_021EF2A0
	add r1, r4, #0
	add r1, #0x20
	strb r0, [r1]
	add r0, r5, #0
	bl PokeathlonCourse_GetCurrentParticipantIndex
	add r1, r4, #0
	add r1, #0x22
	strb r0, [r1]
	add r0, r5, #0
	bl PokeathlonCourse_GetMode
	cmp r0, #1
	bne _021EF358
	mov r0, #1
	b _021EF35A
_021EF358:
	mov r0, #0
_021EF35A:
	str r0, [r4, #0x24]
	str r5, [r4]
	mov r0, #0x88
	str r0, [r4, #0xc]
	ldr r0, _021EF39C ; =ov96_021EF23C
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	ldr r0, _021EF3A0 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	ldr r0, _021EF3A4 ; =0x00007FFF
	bl sub_0200FC20
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _021EF386
	mov r0, #0
	str r0, [r4, #0x28]
	pop {r4, r5, r6, pc}
_021EF386:
	add r0, r5, #0
	bl ov96_021EF2AC
	str r0, [r4, #0x28]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021EF390: .word FS_OVERLAY_ID(OVY_98)
_021EF394: .word 0xFFFFE0FF
_021EF398: .word 0x04001000
_021EF39C: .word ov96_021EF23C
_021EF3A0: .word gSystem + 0x60
_021EF3A4: .word 0x00007FFF
	thumb_func_end ov96_021EF2C0


	thumb_func_start ov96_021EF3A8
ov96_021EF3A8: ; 0x021EF3A8
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r1, #1
	ldr r2, [r4, #0xc]
	mov r0, #6
	lsl r1, r1, #0xe
	bl LoadFontPal0
	ldr r0, [r4, #0x34]
	bl ov96_021EE644
	mov r3, #0
	str r3, [sp]
	ldr r0, [r4, #0xc]
	mov r1, #4
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	add r2, r1, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #5
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #4
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _021EF410
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #0xa
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add sp, #0x10
	pop {r4, pc}
_021EF410:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #9
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021EF3A8


	thumb_func_start ov96_021EF430
ov96_021EF430: ; 0x021EF430
	push {r3, r4, r5, lr}
	sub sp, #0x20
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0xa
	blt _021EF440
	bl GF_AssertFail
_021EF440:
	mov r0, #0
	str r0, [sp]
	ldr r0, [r5, #0xc]
	add r1, r4, #0
	str r0, [sp, #4]
	mov r2, #6
	ldr r0, [r5, #8]
	add r1, #0x20
	lsl r3, r2, #0xc
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5, #0xc]
	add r1, r4, #0
	str r0, [sp, #0xc]
	ldr r0, [r5, #8]
	ldr r2, [r5, #4]
	add r1, #0x2a
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5, #0xc]
	add r4, #0x34
	str r0, [sp, #0xc]
	ldr r0, [r5, #8]
	ldr r2, [r5, #4]
	add r1, r4, #0
	mov r3, #7
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #4
	mov r1, #0
	bl BG_SetMaskColor
	mov r0, #0
	mov r1, #1
	lsl r1, r1, #0xc
	str r1, [sp, #0x10]
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	bl OS_WaitVBlankIntr
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #4]
	mov r1, #7
	add r2, sp, #0x10
	bl SetBgAffine
	add r0, sp, #0x10
	str r0, [sp]
	mov r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [r5, #4]
	mov r1, #7
	mov r2, #3
	bl Bg_SetTextDimAndAffineParams
	add sp, #0x20
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_021EF430


	thumb_func_start ov96_021EF4D0
ov96_021EF4D0: ; 0x021EF4D0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xdc
	ldr r4, _021EF53C ; =ov96_0221BA44
	add r3, sp, #8
	add r7, r0, #0
	str r1, [sp]
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _021EF540 ; =ov96_0221BB98
	add r3, sp, #0x18
	mov r2, #0x18
_021EF4F2:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021EF4F2
	ldr r0, [r4]
	ldr r4, _021EF544 ; =ov96_0221BA10
	str r0, [r3]
	mov r0, #0
	ldr r5, _021EF548 ; =ov96_0221BA18
	str r0, [sp, #4]
	add r6, sp, #0x18
_021EF508:
	ldrb r1, [r5]
	ldrb r3, [r4]
	add r0, r7, #0
	add r2, r6, #0
	bl InitBgFromTemplate
	ldrb r1, [r5]
	add r0, r7, #0
	bl BgClearTilemapBufferAndCommit
	ldrb r0, [r5]
	ldr r3, [sp]
	mov r1, #0x40
	mov r2, #0
	bl BG_ClearCharDataRange
	ldr r0, [sp, #4]
	add r4, r4, #1
	add r0, r0, #1
	add r6, #0x1c
	add r5, r5, #1
	str r0, [sp, #4]
	cmp r0, #7
	blt _021EF508
	add sp, #0xdc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021EF53C: .word ov96_0221BA44
_021EF540: .word ov96_0221BB98
_021EF544: .word ov96_0221BA10
_021EF548: .word ov96_0221BA18
	thumb_func_end ov96_021EF4D0


	thumb_func_start ov96_021EF54C
ov96_021EF54C: ; 0x021EF54C
	push {r4, lr}
	sub sp, #0x10
	mov r2, #0
	add r4, r0, #0
	str r2, [sp]
	ldr r0, [r4, #0xc]
	mov r1, #4
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #5
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #6
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bne _021EF5CA
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #5
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r4, #0xc]
	mov r1, #8
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r2, [r4, #4]
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
_021EF5CA:
	add r0, r4, #0
	bl ov96_021EF3A8
	ldr r0, _021EF5EC ; =0x00000135
	ldr r3, _021EF5F0 ; =ov96_0221BB38
	str r0, [sp]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #4]
	mov r2, #0xc
	bl ov98_0221EABC
	str r0, [r4, #0x30]
	add r0, r4, #0
	bl ov96_021EF610
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_021EF5EC: .word 0x00000135
_021EF5F0: .word ov96_0221BB38
	thumb_func_end ov96_021EF54C

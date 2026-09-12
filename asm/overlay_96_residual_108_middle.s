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

	thumb_func_start ov96_022118C4
ov96_022118C4: ; 0x022118C4
	push {r4, r5, lr}
	sub sp, #0xd4
	ldr r5, _02211A04 ; =ov96_0221D28C
	add r3, sp, #0xc4
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _02211A08 ; =ov96_0221D30C
	add r3, sp, #0xa8
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0
	str r0, [r3]
	add r0, r4, #0
	add r3, r1, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02211A0C ; =ov96_0221D328
	add r3, sp, #0x8c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #1
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02211A10 ; =ov96_0221D344
	add r3, sp, #0x70
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #2
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02211A14 ; =ov96_0221D29C
	add r3, sp, #0x54
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #3
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02211A18 ; =ov96_0221D2B8
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #4
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02211A1C ; =ov96_0221D2D4
	add r3, sp, #0x1c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #5
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	ldr r5, _02211A20 ; =ov96_0221D2F0
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #6
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add sp, #0xd4
	pop {r4, r5, pc}
	nop
_02211A04: .word ov96_0221D28C
_02211A08: .word ov96_0221D30C
_02211A0C: .word ov96_0221D328
_02211A10: .word ov96_0221D344
_02211A14: .word ov96_0221D29C
_02211A18: .word ov96_0221D2B8
_02211A1C: .word ov96_0221D2D4
_02211A20: .word ov96_0221D2F0
	thumb_func_end ov96_022118C4


	thumb_func_start ov96_02211A24
ov96_02211A24: ; 0x02211A24
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	mov r1, #1
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xec
	add r3, r1, #0
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	mov r1, #3
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xec
	mov r3, #2
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	mov r1, #6
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xec
	mov r3, #5
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	mov r1, #7
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xec
	mov r3, #6
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	mov r1, #2
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xec
	mov r3, #1
	bl GfGfxLoader_LoadScrnData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x58]
	mov r1, #4
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0xec
	mov r3, #2
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x75
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_022146C0
	mov r1, #0
	mov r0, #0x80
	str r0, [sp]
	ldr r0, [r4, #0x58]
	add r2, r1, #0
	str r0, [sp, #4]
	mov r0, #0xec
	add r3, r1, #0
	bl GfGfxLoader_GXLoadPal
	mov r0, #0x40
	str r0, [sp]
	ldr r0, [r4, #0x58]
	mov r1, #5
	str r0, [sp, #4]
	mov r0, #0xec
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPal
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov96_02211A24


	thumb_func_start ov96_02211AF0
ov96_02211AF0: ; 0x02211AF0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r7, r0, #0
	bl ov96_021E8A20
	add r4, r0, #0
	mov r0, #0
	add r7, #0xf0
	str r0, [r4]
	add r0, r7, #0
	bl ov96_021E8A20
	ldr r0, [r0, #0x20]
	mov r1, #1
	asr r0, r0, #0x18
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _02211B44
	ldr r0, [r6]
	bl ov96_021EB63C
	ldr r0, _02211B88 ; =0x00000748
	mov r1, #1
	ldr r0, [r6, r0]
	bl ov96_021EB144
	add r0, r5, #0
	bl ov96_021E65A4
	ldr r1, _02211B8C ; =ov96_02214618
	add r0, r5, #0
	bl ov96_021E8324
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02211B44:
	bl System_GetTouchNew
	cmp r0, #0
	beq _02211B66
	add r0, r5, #0
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	lsl r1, r1, #0x18
	str r0, [sp]
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl ov96_021E8228
_02211B66:
	bl System_GetTouchHeld
	cmp r0, #0
	beq _02211B7C
	ldr r0, _02211B90 ; =gSystem + 0x40
	ldrh r1, [r0, #0x20]
	strb r1, [r4, #4]
	ldrh r0, [r0, #0x22]
	strb r0, [r4, #5]
	mov r0, #1
	str r0, [r4]
_02211B7C:
	add r0, r5, #0
	bl ov96_02211F38
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02211B88: .word 0x00000748
_02211B8C: .word ov96_02214618
_02211B90: .word gSystem + 0x40
	thumb_func_end ov96_02211AF0


	thumb_func_start ov96_02211B94
ov96_02211B94: ; 0x02211B94
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r0, [sp, #4]
	bl PokeathlonCourse_GetDataCopyArea
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r0, _02211DC8 ; =0x00000738
	ldr r1, [r4, r0]
	cmp r1, #0
	ble _02211BB4
	sub r1, r1, #1
	str r1, [r4, r0]
_02211BB4:
	ldr r0, [sp, #4]
	bl ov96_021E5F24
	cmp r0, #0
	beq _02211BC0
	b _02211DC4
_02211BC0:
	ldr r0, _02211DCC ; =0x0000073E
	ldrb r0, [r4, r0]
	cmp r0, #0
	beq _02211BDE
	ldr r0, [sp, #0xc]
	add r0, #0x28
	str r0, [sp, #0xc]
	bl ov96_021E8A20
	add r1, r0, #0
	add r0, r4, #0
	bl ov96_02211DE4
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
_02211BDE:
	ldr r0, [sp, #0xc]
	add r0, #0x28
	bl ov96_021E8A20
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r0, #0x50
	bl ov96_021E8A20
	add r5, r0, #0
	ldr r0, [sp, #0xc]
	bl ov96_021E8A20
	add r3, r0, #0
	mov r2, #4
_02211BFC:
	ldmia r3!, {r0, r1}
	stmia r5!, {r0, r1}
	sub r2, r2, #1
	bne _02211BFC
	ldr r0, [r3]
	mov r6, #0
	str r0, [r5]
	ldr r0, [sp, #0xc]
	add r5, r4, #0
	add r0, #0x50
	str r0, [sp, #0xc]
	add r0, r4, #0
	str r0, [sp, #8]
	add r0, #0x5c
	str r0, [sp, #8]
_02211C1A:
	ldr r0, [sp, #0xc]
	bl ov96_021E8A20
	add r7, r0, #0
	ldr r0, [r7]
	cmp r0, #0
	ldr r0, _02211DD0 ; =0x00000704
	beq _02211C58
	ldr r1, [r5, r0]
	cmp r1, #0
	beq _02211C40
	add r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02211C40
	ldr r0, _02211DD0 ; =0x00000704
	mov r1, #0
	str r1, [r5, r0]
	b _02211C60
_02211C40:
	cmp r1, #0
	bne _02211C60
	ldr r0, _02211DD4 ; =0x00000708
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _02211C60
	ldr r0, _02211DD0 ; =0x00000704
	mov r1, #1
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
	b _02211C60
_02211C58:
	mov r1, #0
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
_02211C60:
	ldr r0, _02211DD0 ; =0x00000704
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02211CAA
	ldrb r2, [r7, #4]
	lsl r1, r6, #0x18
	ldrb r3, [r7, #5]
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_02213364
	add r7, r0, #0
	cmp r7, #0xc
	beq _02211D68
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x7c
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #8]
	add r1, r0, r2
	ldr r0, [r1, #0x78]
	cmp r0, #2
	beq _02211D68
	cmp r0, #1
	beq _02211D68
	ldr r0, [r1, #0x48]
	cmp r0, #0
	bne _02211D68
	ldr r0, _02211DD8 ; =0x00000734
	add r1, r4, r6
	strb r7, [r1, r0]
	mov r1, #0
	add r0, #0xe
	strb r1, [r4, r0]
	b _02211D68
_02211CAA:
	ldr r0, _02211DD4 ; =0x00000708
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02211CF2
	ldr r1, _02211DD8 ; =0x00000734
	add r0, r4, r6
	ldrb r1, [r0, r1]
	cmp r1, #0xc
	beq _02211D68
	ldr r1, _02211DDC ; =0x00000742
	ldrb r1, [r4, r1]
	cmp r1, #0x14
	bhs _02211CCE
	ldr r1, _02211DDC ; =0x00000742
	ldrb r1, [r4, r1]
	add r2, r1, #1
	ldr r1, _02211DDC ; =0x00000742
	strb r2, [r4, r1]
_02211CCE:
	ldr r1, _02211DD8 ; =0x00000734
	ldrb r0, [r0, r1]
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	mov r3, #0x7c
	mul r3, r2
	ldr r2, [sp, #8]
	ldrb r0, [r7, #4]
	add r2, r2, r3
	ldrb r1, [r7, #5]
	add r2, #0x24
	bl ov96_02213354
	b _02211D68
_02211CF2:
	ldr r0, _02211DD8 ; =0x00000734
	add r7, r4, r6
	ldrb r0, [r7, r0]
	cmp r0, #0xc
	beq _02211D68
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x7c
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #8]
	add r0, r0, r2
	ldr r1, [r0, #0x78]
	cmp r1, #3
	beq _02211D5C
	cmp r1, #2
	beq _02211D5C
	ldr r1, _02211DDC ; =0x00000742
	ldrb r1, [r4, r1]
	cmp r1, #8
	bhi _02211D58
	ldr r2, [r0, #0x24]
	ldr r1, [r0, #0x30]
	cmp r2, r1
	bne _02211D32
	ldr r2, [r0, #0x28]
	ldr r1, [r0, #0x34]
	cmp r2, r1
	beq _02211D5C
_02211D32:
	mov r1, #1
	str r1, [r0, #0x78]
	ldr r0, _02211DD8 ; =0x00000734
	mov r1, #3
	ldrb r0, [r7, r0]
	bl _s32_div_f
	add r2, r1, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r6, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #6
	bl ov96_021E8228
	b _02211D5C
_02211D58:
	mov r1, #0
	str r1, [r0, #0x78]
_02211D5C:
	ldr r0, _02211DDC ; =0x00000742
	mov r1, #0
	strb r1, [r4, r0]
	mov r1, #0xc
	sub r0, #0xe
	strb r1, [r7, r0]
_02211D68:
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #8]
	add r0, #0x28
	str r0, [sp, #0xc]
	mov r0, #0x5d
	lsl r0, r0, #2
	add r0, r1, r0
	add r6, r6, #1
	add r5, #0xc
	str r0, [sp, #8]
	cmp r6, #4
	bge _02211D82
	b _02211C1A
_02211D82:
	ldr r1, _02211DE0 ; =0x0000074C
	ldr r0, [sp, #4]
	ldr r1, [r4, r1]
	bl ov96_02214B84
	ldr r0, [sp, #4]
	bl ov96_022124F8
	ldr r0, [sp, #4]
	bl ov96_02212B94
	ldr r0, [sp, #4]
	bl ov96_022127F4
	ldr r0, [sp, #4]
	bl ov96_022130EC
	ldr r0, [sp, #4]
	bl ov96_022132FC
	ldr r0, _02211DC8 ; =0x00000738
	ldr r1, [r4, r0]
	cmp r1, #0
	bgt _02211DB6
	mov r1, #1
	b _02211DB8
_02211DB6:
	mov r1, #0
_02211DB8:
	add r0, r0, #6
	strb r1, [r4, r0]
	ldr r1, [sp, #0x10]
	add r0, r4, #0
	bl ov96_02211DE4
_02211DC4:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02211DC8: .word 0x00000738
_02211DCC: .word 0x0000073E
_02211DD0: .word 0x00000704
_02211DD4: .word 0x00000708
_02211DD8: .word 0x00000734
_02211DDC: .word 0x00000742
_02211DE0: .word 0x0000074C
	thumb_func_end ov96_02211B94


	thumb_func_start ov96_02211DE4
ov96_02211DE4: ; 0x02211DE4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #8]
	str r0, [sp, #4]
	add r4, r0, #0
	add r6, r0, #0
	ldr r0, [sp]
	add r5, r1, #0
	str r0, [sp, #0x10]
	add r0, #0x5c
	str r0, [sp, #0x10]
_02211E00:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x5d
	lsl r0, r0, #2
	add r2, r7, #0
	mul r2, r0
	ldr r0, [sp, #0x10]
	add r2, r0, r2
	mov r0, #0x7c
	mul r0, r1
	add r0, r2, r0
	add r3, r0, #0
	add r3, #0x5c
	ldrh r3, [r3]
	ldr r2, [r0, #0x34]
	sub r3, r3, #1
	lsl r3, r3, #0x18
	asr r1, r2, #0xb
	lsr r7, r3, #0x18
	add r3, r5, r4
	lsr r1, r1, #0x14
	mov ip, r3
	add r1, r2, r1
	asr r2, r1, #0xc
	ldr r1, [r0, #0x78]
	ldr r3, [r0, #0x30]
	lsl r1, r1, #0x18
	asr r0, r3, #0xb
	lsr r0, r0, #0x14
	add r0, r3, r0
	asr r0, r0, #0xc
	strb r0, [r5, r4]
	mov r0, ip
	strb r2, [r0, #0xc]
	add r2, r7, #0
	lsr r1, r1, #0x18
	lsl r2, r6
	ldr r0, [sp, #0xc]
	lsl r1, r6
	add r0, r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r4, r4, #1
	add r0, r0, r1
	add r6, r6, #2
	str r0, [sp, #8]
	cmp r4, #0xc
	blt _02211E00
	ldr r1, _02211F2C ; =0x0000062C
	ldr r0, [sp]
	mov r6, #0
	add r4, r0, r1
	add r7, r6, #0
_02211E78:
	ldr r1, [r4, #8]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x14]
	add r0, r4, #0
	bl ov96_02213EC4
	add r2, r5, r6
	ldr r1, [sp, #0x14]
	add r6, r6, #1
	strb r1, [r2, #0x18]
	strb r0, [r2, #0x1a]
	add r0, r4, #0
	add r0, #0x39
	ldrb r0, [r0]
	add r4, #0x4c
	add r1, r0, #0
	lsl r1, r7
	ldr r0, [sp, #4]
	add r7, r7, #2
	add r0, r0, r1
	str r0, [sp, #4]
	cmp r6, #2
	blt _02211E78
	ldr r0, _02211F30 ; =0x0000073C
	ldr r1, [sp]
	ldrb r2, [r1, r0]
	lsl r3, r2, #2
	add r3, r1, r3
	add r1, r0, #0
	sub r1, #0x48
	ldr r1, [r3, r1]
	lsl r1, r1, #0x18
	lsr r3, r1, #0x18
	add r1, r2, #1
	lsr r6, r1, #0x1f
	lsl r4, r1, #0x1e
	sub r4, r4, r6
	mov r1, #0x1e
	ror r4, r1
	ldr r1, [sp]
	add r4, r6, r4
	strb r4, [r1, r0]
	ldr r4, [sp, #4]
	lsl r2, r2, #0x1c
	lsl r6, r4, #0x18
	ldr r4, [sp, #0xc]
	add r1, r5, #0
	add r4, r4, r6
	add r2, r4, r2
	str r2, [r5, #0x1c]
	ldr r2, [sp]
	sub r0, #0xd8
	ldrb r0, [r2, r0]
	add r1, #0x1c
	cmp r0, #2
	bne _02211EF8
	mov r0, #1
	ldr r2, [r1]
	lsl r0, r0, #0x1e
	add r0, r2, r0
	str r0, [r1]
_02211EF8:
	mov r1, #0x6b
	ldr r0, [sp]
	lsl r1, r1, #4
	ldrb r0, [r0, r1]
	cmp r0, #0
	beq _02211F0E
	mov r0, #2
	ldr r1, [r5, #0x1c]
	lsl r0, r0, #0x1e
	sub r0, r1, r0
	str r0, [r5, #0x1c]
_02211F0E:
	ldr r0, [sp, #8]
	mov r1, #0
	add r2, r1, r0
	ldr r1, _02211F34 ; =0x0000073E
	ldr r0, [sp]
	str r2, [r5, #0x20]
	ldrb r0, [r0, r1]
	lsl r0, r0, #0x18
	add r1, r2, r0
	lsl r0, r3, #0x19
	add r0, r1, r0
	str r0, [r5, #0x20]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02211F2C: .word 0x0000062C
_02211F30: .word 0x0000073C
_02211F34: .word 0x0000073E
	thumb_func_end ov96_02211DE4


	thumb_func_start ov96_02211F38
ov96_02211F38: ; 0x02211F38
	push {r4, r5, r6, r7, lr}
	sub sp, #0x74
	str r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x38]
	ldr r0, [sp, #8]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	add r6, r0, #0
	ldr r0, [sp, #0x38]
	bl ov96_02214418
	ldr r0, [sp, #0x38]
	mov r4, #0
	str r0, [sp, #0x40]
	add r0, #0x5c
	add r7, r4, #0
	str r0, [sp, #0x40]
_02211F70:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x18]
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	ldr r2, [sp, #0x18]
	mov r0, #0x5d
	add r3, r2, #0
	lsl r0, r0, #2
	mul r3, r0
	ldr r0, [sp, #0x40]
	mov r2, #0x7c
	add r0, r0, r3
	mul r2, r1
	add r5, r0, r2
	ldr r0, [r0, r2]
	bl ov96_021EAA20
	bl ov96_021E8BAC
	ldr r0, [r6, #0x20]
	add r1, r0, #0
	asr r1, r7
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x28]
	cmp r0, #3
	bne _02211FC8
	mov r1, #1
	ldr r0, [r5, #4]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r5, #4]
	mov r1, #0xc
	bl ov96_021EB570
	b _02211FFE
_02211FC8:
	ldr r0, [sp, #0x28]
	cmp r0, #2
	ldr r0, [r5, #4]
	bne _02211FF6
	mov r1, #1
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r5, #4]
	mov r1, #0x10
	bl ov96_021EB570
	mov r0, #0x89
	lsl r0, r0, #4
	bl IsSEPlaying
	cmp r0, #0
	bne _02211FFE
	mov r0, #0x89
	lsl r0, r0, #4
	bl PlaySE
	b _02211FFE
_02211FF6:
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_02211FFE:
	add r0, r6, r4
	str r0, [sp, #0xc]
	ldrb r0, [r6, r4]
	str r0, [sp, #0x34]
	ldr r0, [sp, #0xc]
	ldrb r0, [r0, #0xc]
	str r0, [sp, #0x30]
	ldr r0, [r6, #0x1c]
	add r1, r0, #0
	asr r1, r7
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x2c]
	mov r1, #0
	add r0, sp, #0x68
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [sp, #0x34]
	mov r1, #3
	lsl r0, r0, #0xc
	str r0, [sp, #0x68]
	ldr r0, [sp, #0x30]
	lsl r0, r0, #0xc
	str r0, [sp, #0x6c]
	add r0, r4, #0
	bl _s32_div_f
	str r0, [sp, #0x44]
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x44]
	bl ov96_021E60C0
	ldrb r0, [r0, #7]
	cmp r0, #1
	beq _0221205E
	cmp r0, #2
	beq _0221206A
	cmp r0, #3
	beq _02212076
	b _02212082
_0221205E:
	mov r0, #2
	ldr r1, [sp, #0x6c]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #0x6c]
	b _02212086
_0221206A:
	mov r0, #2
	ldr r1, [sp, #0x6c]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #0x6c]
	b _02212086
_02212076:
	mov r0, #1
	ldr r1, [sp, #0x6c]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x6c]
	b _02212086
_02212082:
	bl GF_AssertFail
_02212086:
	ldr r0, [r5, #4]
	add r1, sp, #0x68
	bl ov96_021EB588
	ldr r0, [sp, #0x28]
	cmp r0, #1
	bne _02212138
	add r0, r5, #0
	add r0, #0x63
	ldrb r0, [r0]
	cmp r0, #0
	bne _0221212C
	mov r1, #0
	add r0, sp, #0x5c
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r1, [sp, #0x38]
	ldr r0, _02212358 ; =0x00000748
	ldr r0, [r1, r0]
	lsl r1, r4, #0x18
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r1, r5, #0
	add r1, #0x62
	ldrb r1, [r1]
	ldr r2, [sp, #0xc]
	add r3, sp, #0x4c
	str r1, [sp, #0x24]
	add r1, sp, #0x48
	str r1, [sp]
	ldr r1, [sp, #0xc]
	ldrb r2, [r2, #0xc]
	ldrb r1, [r1]
	bl ov96_021EB06C
	ldr r0, [sp, #0x4c]
	add r1, sp, #0x5c
	lsl r0, r0, #0xc
	str r0, [sp, #0x5c]
	ldr r0, [sp, #0x48]
	lsl r0, r0, #0xc
	str r0, [sp, #0x60]
	ldr r0, [sp, #0x24]
	lsl r0, r0, #2
	add r0, r5, r0
	str r0, [sp, #0x14]
	ldr r0, [r0, #8]
	bl ov96_021EB588
	ldr r0, [sp, #0x14]
	mov r1, #1
	ldr r0, [r0, #8]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [sp, #0x14]
	mov r1, #0xe
	ldr r0, [r0, #8]
	bl ov96_021EB564
	add r0, r5, #0
	add r0, #0x62
	ldrb r0, [r0]
	mov r1, #3
	add r0, r0, #1
	bl _s32_div_f
	add r0, r5, #0
	add r0, #0x62
	strb r1, [r0]
	add r5, #0x63
	mov r0, #5
	strb r0, [r5]
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x10]
	cmp r1, r0
	bne _02212138
	ldr r0, _0221235C ; =0x000008CC
	bl PlaySE
	b _02212138
_0221212C:
	add r0, r5, #0
	add r0, #0x63
	ldrb r0, [r0]
	add r5, #0x63
	sub r0, r0, #1
	strb r0, [r5]
_02212138:
	ldr r1, [sp, #0x38]
	ldr r0, _02212358 ; =0x00000748
	ldr r0, [r1, r0]
	lsl r1, r4, #0x18
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	ldr r1, [sp, #0x28]
	add r5, r0, #0
	cmp r1, #2
	bne _02212156
	mov r1, #0x14
	bl ov96_021EAC5C
	b _02212162
_02212156:
	ldr r1, [sp, #0x2c]
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021EAC0C
_02212162:
	ldr r1, [sp, #0x34]
	ldr r2, [sp, #0x30]
	add r0, r5, #0
	mov r3, #1
	bl ov96_021EB01C
	add r4, r4, #1
	add r7, r7, #2
	cmp r4, #0xc
	bge _02212178
	b _02211F70
_02212178:
	ldr r2, [sp, #0x38]
	mov r1, #0x5d
	ldr r0, [sp, #0x10]
	lsl r1, r1, #2
	add r2, #0x5c
	mul r1, r0
	add r0, r2, r1
	ldr r1, [sp, #0x10]
	add r3, r6, #0
	lsl r2, r1, #1
	add r3, #0xc
	add r1, r1, r2
	add r1, r3, r1
	bl ov96_022144C0
	ldr r0, [sp, #0x38]
	ldr r2, [sp, #0x10]
	add r1, r6, #0
	bl ov96_0221457C
	ldr r2, [r6, #0x1c]
	mov r5, #0
	asr r0, r2, #0x1e
	mov r1, #1
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x1c]
	asr r0, r2, #0x1f
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x3c]
	ldr r1, _02212360 ; =0x0000062C
	ldr r0, [sp, #0x38]
	str r5, [sp, #0x20]
	add r4, r0, r1
_022121C2:
	mov r1, #0
	add r0, sp, #0x50
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r0, [r6, #0x1c]
	asr r0, r0, #0x18
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0x20]
	asr r1, r0
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	cmp r7, #1
	bne _02212220
	ldr r0, [r4]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, [r4, #4]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	cmp r5, #0
	bne _02212206
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _02212206
	mov r2, #1
	b _02212208
_02212206:
	mov r2, #0
_02212208:
	add r3, r6, r5
	ldrb r0, [r3, #0x1a]
	lsl r1, r5, #0x18
	lsr r1, r1, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x10]
	str r0, [sp, #4]
	ldrb r3, [r3, #0x18]
	ldr r0, [sp, #0x38]
	bl ov96_022123B0
	b _02212296
_02212220:
	add r1, r4, #0
	add r1, #0x3f
	mov r0, #0
	strb r0, [r1]
	cmp r5, #1
	bne _02212248
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	ldr r0, [r4]
	beq _0221223E
	mov r1, #1
	add r2, r1, #0
	bl ov96_021EB52C
	b _02212252
_0221223E:
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	b _02212252
_02212248:
	mov r1, #1
	ldr r0, [r4]
	add r2, r1, #0
	bl ov96_021EB52C
_02212252:
	cmp r7, #2
	ldr r0, [r4, #4]
	bne _02212272
	mov r1, #1
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r4, #0
	add r0, #0x44
	ldrb r0, [r0]
	cmp r0, #2
	beq _0221227A
	ldr r0, _02212364 ; =0x000008C7
	bl PlaySE
	b _0221227A
_02212272:
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_0221227A:
	cmp r5, #0
	bne _0221228E
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _0221228E
	ldr r0, [r4]
	mov r1, #0xb
	bl ov96_021EB570
	b _02212296
_0221228E:
	ldr r0, [r4]
	mov r1, #0xa
	bl ov96_021EB570
_02212296:
	add r0, r4, #0
	add r0, #0x44
	strb r7, [r0]
	add r7, r6, r5
	ldrb r0, [r7, #0x18]
	lsl r0, r0, #0xc
	str r0, [sp, #0x50]
	ldrb r0, [r7, #0x1a]
	bl ov96_02213F5C
	str r0, [sp, #0x54]
	lsl r1, r5, #0x18
	ldrb r3, [r7, #0x1a]
	ldr r0, [sp, #0x38]
	ldr r2, [sp, #0x1c]
	lsr r1, r1, #0x18
	bl ov96_02213FF4
	ldr r0, [r4]
	add r1, sp, #0x50
	bl ov96_021EB588
	ldr r0, [r4, #4]
	add r1, sp, #0x50
	bl ov96_021EB588
	ldrb r0, [r7, #0x1a]
	cmp r0, #0xc0
	ldr r0, [r4]
	bhs _022122DA
	mov r1, #0x2e
	bl ov96_021EB630
	b _022122E0
_022122DA:
	mov r1, #4
	bl ov96_021EB630
_022122E0:
	ldr r0, [sp, #0x20]
	add r5, r5, #1
	add r0, r0, #2
	add r4, #0x4c
	str r0, [sp, #0x20]
	cmp r5, #2
	bge _022122F0
	b _022121C2
_022122F0:
	ldr r7, _02212368 ; =0x000006E4
	ldr r4, [sp, #0x38]
	add r6, r7, #0
	mov r5, #0
	sub r6, #0x10
_022122FA:
	ldr r0, [r4, r6]
	bl ov96_021EB57C
	cmp r0, #0
	bne _0221230E
	ldr r0, [r4, r7]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_0221230E:
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #4
	blt _022122FA
	ldr r0, [sp, #8]
	bl ov96_0221236C
	mov r1, #0x75
	ldr r0, [sp, #0x38]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	bl ov96_02214904
	add r2, r0, #0
	mov r1, #0x75
	ldr r0, [sp, #0x38]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	bl ov96_0221497C
	mov r2, #0x75
	ldr r0, [sp, #0x38]
	lsl r2, r2, #4
	ldr r0, [r0, r2]
	ldr r1, [sp, #0x38]
	sub r2, #0x18
	ldr r1, [r1, r2]
	bl ov96_0221490C
	ldr r0, [sp, #0x38]
	bl ov96_02214490
	add sp, #0x74
	pop {r4, r5, r6, r7, pc}
	nop
_02212358: .word 0x00000748
_0221235C: .word 0x000008CC
_02212360: .word 0x0000062C
_02212364: .word 0x000008C7
_02212368: .word 0x000006E4
	thumb_func_end ov96_02211F38


	thumb_func_start ov96_0221236C
ov96_0221236C: ; 0x0221236C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	ldr r1, [r0, #0x1c]
	ldr r0, [r0, #0x20]
	asr r2, r1, #0x1c
	mov r1, #3
	and r1, r2
	lsl r1, r1, #0x18
	lsr r2, r1, #0x18
	asr r1, r0, #0x19
	mov r0, #0x7f
	and r0, r1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, _022123AC ; =0x00000814
	add r3, r4, r2
	strb r1, [r3, r0]
	sub r0, #0xc4
	ldr r0, [r4, r0]
	bl ov96_022148E8
	pop {r3, r4, r5, pc}
	nop
_022123AC: .word 0x00000814
	thumb_func_end ov96_0221236C


	thumb_func_start ov96_022123B0
ov96_022123B0: ; 0x022123B0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r0, #0
	add r0, sp, #0x10
	ldrb r3, [r0, #0x10]
	str r2, [sp]
	cmp r3, #0xd8
	blo _022123D2
	ldr r0, _022124E0 ; =0x0000062C
	add r2, r4, r0
	mov r0, #0x4c
	mul r0, r1
	add r1, r2, r0
	add r1, #0x3f
	ldrb r1, [r1]
	cmp r1, #0
	beq _022123D4
_022123D2:
	b _022124DA
_022123D4:
	add r0, r2, r0
	mov r1, #1
	add r0, #0x3f
	sub r3, #0xd8
	strb r1, [r0]
	lsl r0, r3, #0x18
	lsr r7, r0, #0x18
	cmp r7, #0x10
	blo _022123EA
	bl GF_AssertFail
_022123EA:
	lsl r0, r7, #0x16
	lsr r5, r0, #0x18
	lsl r6, r5, #2
	ldr r0, _022124E4 ; =0x000006C4
	add r1, r4, r6
	ldr r0, [r1, r0]
	mov r1, #0xf
	bl ov96_021EB564
	lsr r1, r7, #0x1f
	lsl r2, r7, #0x1e
	sub r2, r2, r1
	mov r0, #0x1e
	ror r2, r0
	add r0, r1, r2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	cmp r0, r5
	beq _02212434
	ldr r0, [sp]
	mov r3, #0
	cmp r0, #0
	beq _0221241C
	mov r3, #1
_0221241C:
	ldr r1, [sp, #4]
	add r0, r4, #0
	mov r2, #1
	bl ov96_02214258
	mov r2, #0
	add r0, r4, #0
	add r1, r5, #0
	add r3, r2, #0
	bl ov96_02214258
	b _02212440
_02212434:
	mov r2, #0
	add r0, r4, #0
	add r1, r5, #0
	add r3, r2, #0
	bl ov96_02214258
_02212440:
	add r0, r7, #0
	mov r1, #5
	bl _s32_div_f
	cmp r1, #0
	bne _02212466
	add r0, r7, #0
	mov r1, #5
	bl _s32_div_f
	add r1, sp, #0x10
	ldrb r1, [r1, #0x14]
	cmp r1, r0
	bne _02212466
	ldr r0, _022124E8 ; =0x000008C6
	bl PlaySE
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_02212466:
	add r0, sp, #0x10
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #4]
	cmp r1, r0
	bne _022124D4
	cmp r5, #3
	bhi _02212490
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02212480: ; jump table
	.short _02212488 - _02212480 - 2 ; case 0
	.short _0221248C - _02212480 - 2 ; case 1
	.short _02212488 - _02212480 - 2 ; case 2
	.short _0221248C - _02212480 - 2 ; case 3
_02212488:
	mov r7, #0x11
	b _02212498
_0221248C:
	mov r7, #0x12
	b _02212498
_02212490:
	bl GF_AssertFail
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_02212498:
	ldr r0, _022124EC ; =0x000006D4
	mov r1, #1
	add r0, r4, r0
	str r0, [sp, #8]
	ldr r0, [r0, r6]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [sp, #8]
	add r1, r7, #0
	ldr r0, [r0, r6]
	bl ov96_021EB564
	ldr r0, _022124F0 ; =0x000006E4
	mov r1, #1
	add r4, r4, r0
	ldr r0, [r4, r6]
	add r2, r1, #0
	bl ov96_021EB52C
	add r5, #0x13
	ldr r0, [r4, r6]
	add r1, r5, #0
	bl ov96_021EB564
	ldr r0, _022124F4 ; =0x000008CB
	bl PlaySE
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_022124D4:
	ldr r0, _022124E8 ; =0x000008C6
	bl PlaySE
_022124DA:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_022124E0: .word 0x0000062C
_022124E4: .word 0x000006C4
_022124E8: .word 0x000008C6
_022124EC: .word 0x000006D4
_022124F0: .word 0x000006E4
_022124F4: .word 0x000008CB
	thumb_func_end ov96_022123B0


	thumb_func_start ov96_022124F8
ov96_022124F8: ; 0x022124F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10c
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #8]
	add r0, sp, #0x70
	mov r4, #0
	str r4, [r0]
	str r4, [r0, #4]
	ldr r3, _022127F0 ; =ov96_0221D25C
	str r4, [r0, #8]
	ldmia r3!, {r0, r1}
	add r2, sp, #0x10
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r7, sp, #0x7c
	str r0, [r2]
	ldr r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, #0x5c
	str r0, [sp, #0xc]
_02212522:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x5d
	lsl r0, r0, #2
	add r2, r5, #0
	mul r2, r0
	ldr r0, [sp, #0xc]
	add r3, sp, #0x70
	add r2, r0, r2
	mov r0, #0x7c
	mul r0, r1
	add r5, r2, r0
	add r2, r5, #0
	ldmia r3!, {r0, r1}
	add r2, #0x3c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r3, r5, #0
	str r0, [r2]
	add r3, #0x30
	ldmia r3!, {r0, r1}
	add r2, r7, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r3, r5, #0
	str r0, [r2]
	add r3, #0x30
	ldmia r3!, {r0, r1}
	add r2, sp, #0x4c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r5, #0x48]
	cmp r0, #0
	beq _022125FC
	sub r0, r0, #2
	cmp r0, #1
	bhi _02212590
	mov r0, #0x5a
	ldrsh r0, [r5, r0]
	cmp r0, #0
	ble _02212590
	mov r0, #0x5a
	ldrsh r0, [r5, r0]
	sub r1, r0, #1
	add r0, r5, #0
	add r0, #0x5a
	strh r1, [r0]
_02212590:
	mov r0, #0x58
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bne _022125AC
	mov r0, #0x5a
	ldrsh r0, [r5, r0]
	cmp r0, #0
	bgt _022125AC
	mov r0, #0
	add r1, r5, #0
	str r0, [r5, #0x48]
	add r1, #0x5a
	strh r0, [r1]
	b _022125FC
_022125AC:
	lsl r0, r1, #0xc
	add r1, r5, #0
	add r2, sp, #0x4c
	add r1, #0x4c
	add r3, r2, #0
	bl VEC_MultAdd
	add r6, sp, #0x4c
	add r3, r5, #0
	add r3, #0x30
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	add r3, r5, #0
	ldmia r2!, {r0, r1}
	add r3, #0x24
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
	mov r0, #0x58
	ldrsh r0, [r5, r0]
	cmp r0, #0
	ble _022125EA
	mov r0, #0x58
	ldrsh r0, [r5, r0]
	sub r1, r0, #1
	add r0, r5, #0
	add r0, #0x58
	strh r1, [r0]
_022125EA:
	ldr r0, [r5, #0x78]
	cmp r0, #2
	beq _022125FC
	ldr r0, [r5, #0x48]
	cmp r0, #3
	bne _022125FC
	add r0, r5, #0
	bl ov96_02213FB4
_022125FC:
	ldr r0, [r5, #0x78]
	cmp r0, #2
	beq _0221260C
	add r0, r5, #0
	add r0, #0x60
	ldrb r0, [r0]
	cmp r0, #0
	beq _02212634
_0221260C:
	add r0, r5, #0
	add r0, #0x60
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r5, #0
	add r0, #0x60
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x60
	ldrb r0, [r0]
	cmp r0, #0
	bne _0221263A
	mov r0, #0
	str r0, [r5, #0x78]
	add r0, r5, #0
	add r0, #0x70
	ldrb r0, [r0]
	add r5, #0x71
	strb r0, [r5]
	b _02212742
_02212634:
	ldr r0, [r5, #0x48]
	cmp r0, #0
	beq _0221263C
_0221263A:
	b _02212742
_0221263C:
	add r0, r5, #0
	add r0, #0x24
	add r1, sp, #0x4c
	add r2, sp, #0x64
	bl VEC_Subtract
	add r0, sp, #0x64
	bl VEC_Mag
	add r6, r0, #0
	cmp r6, #0
	bgt _0221265C
	add r0, r5, #0
	bl ov96_02213558
	b _02212742
_0221265C:
	add r0, sp, #0x64
	add r1, sp, #0x58
	bl VEC_Normalize
	add r3, sp, #0x58
	add r2, r5, #0
	ldmia r3!, {r0, r1}
	add r2, #0x3c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r5, #0x78]
	cmp r0, #1
	bne _0221267C
	ldr r0, [r5, #0x68]
	b _02212688
_0221267C:
	cmp r0, #3
	bne _02212686
	mov r0, #2
	lsl r0, r0, #0xc
	b _02212688
_02212686:
	ldr r0, [r5, #0x64]
_02212688:
	cmp r6, r0
	bgt _0221269C
	add r3, r5, #0
	add r3, #0x24
	ldmia r3!, {r0, r1}
	add r2, sp, #0x4c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	b _022126BA
_0221269C:
	mov r2, #0
	add r1, sp, #0x40
	str r2, [r1]
	str r2, [r1, #4]
	str r2, [r1, #8]
	add r1, sp, #0x58
	add r2, sp, #0x40
	add r3, sp, #0x64
	bl VEC_MultAdd
	add r1, sp, #0x4c
	add r0, sp, #0x64
	add r2, r1, #0
	bl VEC_Add
_022126BA:
	cmp r6, #0
	beq _02212736
	add r6, sp, #0x10
	ldmia r6!, {r0, r1}
	add r3, sp, #0x34
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	add r1, sp, #0x28
	str r0, [r3]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x30]
	mov r0, #0
	str r0, [sp, #0x2c]
	add r0, r2, #0
	bl CalcAngleBetweenVecs
	mov r1, #2
	lsl r1, r1, #0xc
	cmp r0, r1
	bls _022126F0
	mov r1, #0xe
	lsl r1, r1, #0xc
	cmp r0, r1
	blo _022126FA
_022126F0:
	add r1, r5, #0
	add r1, #0x5c
	mov r0, #4
	strh r0, [r1]
	b _02212736
_022126FA:
	mov r1, #2
	lsl r1, r1, #0xc
	cmp r0, r1
	bls _02212714
	mov r1, #6
	lsl r1, r1, #0xc
	cmp r0, r1
	bhs _02212714
	add r1, r5, #0
	add r1, #0x5c
	mov r0, #2
	strh r0, [r1]
	b _02212736
_02212714:
	mov r1, #6
	lsl r1, r1, #0xc
	cmp r0, r1
	blo _0221272E
	mov r1, #0xa
	lsl r1, r1, #0xc
	cmp r0, r1
	bhi _0221272E
	add r1, r5, #0
	add r1, #0x5c
	mov r0, #3
	strh r0, [r1]
	b _02212736
_0221272E:
	add r1, r5, #0
	add r1, #0x5c
	mov r0, #1
	strh r0, [r1]
_02212736:
	add r2, sp, #0x4c
	ldmia r2!, {r0, r1}
	add r5, #0x30
	stmia r5!, {r0, r1}
	ldr r0, [r2]
	str r0, [r5]
_02212742:
	add r4, r4, #1
	add r7, #0xc
	cmp r4, #0xc
	bge _0221274C
	b _02212522
_0221274C:
	ldr r0, [sp, #8]
	add r5, sp, #0x7c
	add r0, #0x5c
	mov r6, #0
	str r5, [sp, #4]
	str r0, [sp, #8]
_02212758:
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x5d
	lsl r0, r0, #2
	add r2, r4, #0
	mul r2, r0
	ldr r0, [sp, #8]
	add r2, r0, r2
	mov r0, #0x7c
	mul r0, r1
	add r4, r2, r0
	ldr r1, [r4, #0x30]
	ldr r0, [r5]
	cmp r1, r0
	bne _0221278C
	ldr r1, [r4, #0x34]
	ldr r0, [r5, #4]
	cmp r1, r0
	beq _022127BE
_0221278C:
	add r0, sp, #0x1c
	str r0, [sp]
	add r0, r4, #0
	ldr r1, [sp, #4]
	ldr r2, [r4, #0x20]
	add r0, #0x30
	mov r3, #1
	bl ov96_02213728
	cmp r0, #0
	beq _022127BE
	add r7, sp, #0x1c
	add r3, r4, #0
	add r3, #0x30
	ldmia r7!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r7]
	str r0, [r3]
	add r3, r4, #0
	ldmia r2!, {r0, r1}
	add r3, #0x24
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
_022127BE:
	ldr r1, [r4, #0x30]
	ldr r0, [r4, #0x24]
	cmp r1, r0
	bne _022127DC
	ldr r1, [r4, #0x34]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	bne _022127DC
	ldr r0, [r4, #0x78]
	cmp r0, #3
	beq _022127DC
	cmp r0, #2
	beq _022127DC
	mov r0, #0
	str r0, [r4, #0x78]
_022127DC:
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r0, #0xc
	add r5, #0xc
	str r0, [sp, #4]
	cmp r6, #0xc
	blt _02212758
	add sp, #0x10c
	pop {r4, r5, r6, r7, pc}
	nop
_022127F0: .word ov96_0221D25C
	thumb_func_end ov96_022124F8


	thumb_func_start ov96_022127F4
ov96_022127F4: ; 0x022127F4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x60
	str r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x1c]
	mov r0, #0
	str r0, [sp, #0x20]
	ldr r1, _02212B08 ; =0x0000062C
	ldr r0, [sp, #0x1c]
	add r5, r0, r1
_0221280A:
	add r0, r5, #0
	add r0, #0x38
	ldrb r1, [r0]
	cmp r1, #0
	beq _02212822
	add r0, r5, #0
	add r0, #0x39
	ldrb r0, [r0]
	cmp r0, #0
	beq _02212824
	cmp r0, #2
	beq _02212824
_02212822:
	b _02212B82
_02212824:
	cmp r1, #1
	bne _0221282E
	mov r0, #8
	str r0, [sp, #0x18]
	b _02212836
_0221282E:
	cmp r1, #2
	bne _02212836
	mov r0, #0xc
	str r0, [sp, #0x18]
_02212836:
	ldr r0, [sp, #0x18]
	mov r6, #0
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	add r0, r5, #0
	str r0, [sp, #0x28]
	add r0, #8
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x24]
	add r0, #0x5c
	str r0, [sp, #0x24]
_0221284E:
	mov r1, #0
	add r0, sp, #0x54
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	str r1, [sp, #0x34]
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	mov r1, #0x5d
	lsl r1, r1, #2
	str r0, [sp, #0x10]
	mul r1, r0
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x34]
	add r1, r0, r1
	mov r0, #0x7c
	mul r0, r2
	add r2, sp, #0x58
	str r2, [sp]
	add r2, sp, #0x38
	add r4, r1, r0
	str r2, [sp, #4]
	ldr r0, [r1, r0]
	ldr r1, [r4, #0x30]
	ldr r2, [r4, #0x34]
	add r3, sp, #0x54
	bl ov96_021EAF78
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0xc]
	add r0, sp, #0x54
	lsl r1, r1, #0xc
	bl ov96_0221341C
	cmp r0, #0
	bne _022128A6
	b _02212ADC
_022128A6:
	add r0, r5, r6
	add r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #0
	beq _022128B6
	ldr r0, [r5, #0x48]
	cmp r0, #0
	bne _022128E6
_022128B6:
	ldr r0, [r4, #0x48]
	cmp r0, #3
	beq _022128E6
	cmp r0, #2
	beq _022128E6
	ldr r0, [sp, #0x28]
	add r1, sp, #0x54
	add r2, sp, #0x48
	bl VEC_Subtract
	add r0, sp, #0x48
	add r1, r0, #0
	bl VEC_Normalize
	add r0, r5, #0
	add r0, #0x39
	ldrb r0, [r0]
	cmp r0, #2
	bne _022129A6
	add r0, r5, #0
	add r0, #0x3b
	ldrb r0, [r0]
	cmp r0, r6
	bne _022128E8
_022128E6:
	b _02212AE4
_022128E8:
	add r0, r4, #0
	add r0, #0x71
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x45
	ldrb r0, [r0]
	sub r1, r1, r0
	cmp r1, #0
	bgt _02212966
	add r1, r4, #0
	add r1, #0x71
	mov r0, #0
	strb r0, [r1]
	mov r0, #2
	add r1, r4, #0
	str r0, [r4, #0x78]
	add r3, r4, #0
	add r3, #0x4c
	add r1, #0x60
	mov r0, #0x5a
	strb r0, [r1]
	mov r0, #3
	add r1, r4, #0
	str r0, [r4, #0x48]
	add r1, #0x5a
	mov r0, #0x1e
	strh r0, [r1]
	add r0, sp, #0x48
	add r2, r0, #0
	str r0, [sp, #0x2c]
	ldmia r2!, {r0, r1}
	add r7, r3, #0
	stmia r3!, {r0, r1}
	add r0, r2, #0
	ldr r0, [r0]
	str r2, [sp, #0x2c]
	str r0, [r3]
	mov r0, #0
	ldr r2, [sp, #0x34]
	ldr r1, [r7]
	mvn r0, r0
	mul r0, r1
	str r0, [r7]
	mov r0, #0
	lsl r2, r2, #0x18
	ldr r1, [r4, #0x50]
	mvn r0, r0
	mul r0, r1
	str r0, [r4, #0x50]
	ldr r1, [sp, #0x10]
	add r4, #0x58
	mov r0, #7
	strh r0, [r4]
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #1
	bl ov96_021E8228
	b _02212AD2
_02212966:
	add r0, r4, #0
	add r0, #0x71
	strb r1, [r0]
	mov r0, #3
	add r1, r4, #0
	str r0, [r4, #0x48]
	add r3, r4, #0
	add r3, #0x4c
	add r1, #0x5a
	mov r0, #0x1e
	strh r0, [r1]
	add r1, r4, #0
	add r1, #0x58
	mov r0, #7
	add r7, sp, #0x48
	strh r0, [r1]
	ldmia r7!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r7]
	str r0, [r3]
	mov r0, #0
	ldr r1, [r2]
	mvn r0, r0
	mul r0, r1
	str r0, [r2]
	mov r0, #0
	ldr r1, [r4, #0x50]
	mvn r0, r0
	mul r0, r1
	str r0, [r4, #0x50]
	b _02212AD2
_022129A6:
	add r0, r4, #0
	add r0, #0x3c
	bl VEC_Mag
	cmp r0, #0
	bne _022129B4
	b _02212AC2
_022129B4:
	add r0, r4, #0
	add r0, #0x6c
	ldrh r0, [r0]
	mov r1, #0x5a
	lsl r1, r1, #2
	lsl r0, r0, #0x10
	bl _s32_div_f
	add r2, r0, #0
	add r0, r4, #0
	lsl r2, r2, #0x10
	add r0, #0x3c
	add r1, sp, #0x48
	lsr r2, r2, #0x10
	bl ov96_02213534
	ldr r1, [r4, #0x78]
	cmp r1, #1
	bne _02212A86
	cmp r0, #0
	beq _02212A86
	add r1, r5, #0
	add r1, #0x39
	mov r0, #2
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x3e
	strb r0, [r1]
	add r0, r4, #0
	add r0, #0x73
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x41
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x72
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x45
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x75
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x46
	strh r1, [r0]
	add r0, r5, #0
	add r0, #0x41
	ldrb r1, [r0]
	mov r0, #0x1e
	add r2, r1, #0
	mul r2, r0
	ldr r0, _02212B0C ; =ov96_0221D514
	ldrb r0, [r0, r2]
	add r2, r4, #0
	add r2, #0x4c
	str r0, [sp, #0x14]
	mov r0, #1
	str r0, [r4, #0x48]
	add r0, sp, #0x48
	mov ip, r0
	mov r3, ip
	ldmia r3!, {r0, r1}
	add r7, r2, #0
	stmia r2!, {r0, r1}
	add r0, r3, #0
	ldr r0, [r0]
	mov r3, #4
	str r0, [r2]
	mov r0, #0
	ldr r2, [sp, #0x34]
	ldr r1, [r7]
	mvn r0, r0
	mul r0, r1
	str r0, [r7]
	mov r0, #0
	lsl r2, r2, #0x18
	ldr r1, [r4, #0x50]
	mvn r0, r0
	mul r0, r1
	add r1, r4, #0
	str r0, [r4, #0x50]
	add r1, #0x58
	mov r0, #3
	strh r0, [r1]
	mov r0, #0
	add r1, r5, #0
	str r0, [r4, #0x78]
	add r1, #0x3c
	mov r0, #1
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x3d
	mov r0, #0x1e
	strb r0, [r1]
	ldr r1, [sp, #0x10]
	mov r0, #1
	str r0, [sp]
	lsl r1, r1, #0x18
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021E8228
	b _02212ABA
_02212A86:
	add r1, r5, #0
	add r1, #0x3e
	mov r0, #1
	strb r0, [r1]
	add r4, #0x73
	add r0, r5, #0
	ldrb r1, [r4]
	add r0, #0x41
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x41
	ldrb r1, [r0]
	mov r0, #0x1e
	add r2, r1, #0
	mul r2, r0
	ldr r0, _02212B10 ; =ov96_0221D5AA
	add r1, r5, #0
	ldrb r0, [r0, r2]
	add r1, #0x3c
	str r0, [sp, #0x14]
	mov r0, #1
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x3d
	mov r0, #0x1e
	strb r0, [r1]
_02212ABA:
	add r1, r5, #0
	ldr r0, [sp, #0x14]
	add r1, #0x40
	strb r0, [r1]
_02212AC2:
	ldr r0, [sp, #0x1c]
	add r1, r5, #0
	add r2, sp, #0x48
	bl ov96_022134D4
	add r0, r5, #0
	add r0, #0x3b
	strb r6, [r0]
_02212AD2:
	add r1, r5, r6
	add r1, #0x2c
	mov r0, #1
	strb r0, [r1]
	b _02212AE4
_02212ADC:
	add r1, r5, r6
	add r1, #0x2c
	mov r0, #0
	strb r0, [r1]
_02212AE4:
	add r6, r6, #1
	cmp r6, #0xc
	bge _02212AEC
	b _0221284E
_02212AEC:
	add r7, r5, #0
	mov r4, #0
	add r7, #8
_02212AF2:
	lsr r2, r4, #0x1f
	lsl r1, r4, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r1, r2, r1
	mov r0, #0x18
	add r2, r1, #0
	mul r2, r0
	ldr r0, _02212B14 ; =ov96_0221D4B4
	b _02212B18
	.balign 4, 0
_02212B08: .word 0x0000062C
_02212B0C: .word ov96_0221D514
_02212B10: .word ov96_0221D5AA
_02212B14: .word ov96_0221D4B4
_02212B18:
	ldr r3, [sp, #0xc]
	add r6, r0, r2
	asr r0, r4, #1
	lsr r0, r0, #0x1e
	add r0, r4, r0
	asr r1, r0, #2
	mov r0, #0xc
	mul r0, r1
	mov r1, #2
	str r0, [sp, #0x30]
	add r0, r6, r0
	lsl r1, r1, #0xe
	add r2, r7, #0
	bl ov96_0221341C
	cmp r0, #0
	beq _02212B7C
	ldr r0, [sp, #0x30]
	add r1, r5, #0
	add r0, r6, r0
	add r1, #8
	add r2, sp, #0x3c
	bl VEC_Subtract
	add r0, sp, #0x3c
	add r1, r0, #0
	bl VEC_Normalize
	add r0, r5, #0
	add r0, #0x14
	add r1, sp, #0x3c
	bl VEC_DotProduct
	cmp r0, #0
	ble _02212B82
	add r2, r5, #0
	lsl r0, r0, #1
	add r2, #0x14
	neg r0, r0
	add r1, sp, #0x3c
	add r3, r2, #0
	bl VEC_MultAdd
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0x14
	add r1, #0x20
	bl VEC_Normalize
	b _02212B82
_02212B7C:
	add r4, r4, #1
	cmp r4, #8
	blt _02212AF2
_02212B82:
	ldr r0, [sp, #0x20]
	add r5, #0x4c
	add r0, r0, #1
	str r0, [sp, #0x20]
	cmp r0, #2
	bge _02212B90
	b _0221280A
_02212B90:
	add sp, #0x60
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_022127F4


	thumb_func_start ov96_02212B94
ov96_02212B94: ; 0x02212B94
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	bl PokeathlonCourse_GetHeapAllocPtr4
	mov r1, #0x6b
	add r5, r0, #0
	lsl r1, r1, #4
	ldrb r0, [r5, r1]
	cmp r0, #0
	bne _02212BC0
	add r0, r1, #0
	add r0, #0x88
	ldr r2, [r5, r0]
	mov r0, #0xe1
	lsl r0, r0, #2
	cmp r2, r0
	bgt _02212BC0
	mov r2, #3
	add r0, r1, #1
	strb r2, [r5, r0]
	mov r0, #1
	strb r0, [r5, r1]
_02212BC0:
	ldr r0, _02212EC4 ; =0x0000062C
	mov r7, #0
	add r4, r5, r0
_02212BC6:
	add r0, r4, #0
	add r0, #0x38
	ldrb r0, [r0]
	cmp r0, #0
	beq _02212CB4
	add r0, r4, #0
	add r0, #0x39
	ldrb r0, [r0]
	cmp r0, #3
	bne _02212C02
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x43
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x43
	ldrb r0, [r0]
	cmp r0, #8
	blo _02212CB4
	add r1, r4, #0
	add r1, #0x43
	mov r0, #0
	strb r0, [r1]
	add r1, r4, #0
	add r1, #0x39
	strb r0, [r1]
	b _02212E70
_02212C02:
	cmp r0, #1
	bne _02212CAC
	add r0, r4, #0
	add r0, #0x3a
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x3a
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #0
	bne _02212CB4
	add r0, r4, #0
	bl ov96_02213444
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_02213E60
	cmp r7, #0
	bne _02212CA2
	ldr r0, _02212EC8 ; =0x00000738
	mov r1, #0x4b
	ldr r0, [r5, r0]
	lsl r1, r1, #4
	cmp r0, r1
	blt _02212C40
	mov r6, #0
	b _02212C58
_02212C40:
	lsr r1, r1, #1
	cmp r0, r1
	blt _02212C4A
	mov r6, #5
	b _02212C58
_02212C4A:
	mov r1, #0x4b
	lsl r1, r1, #2
	cmp r0, r1
	blt _02212C56
	mov r6, #0xa
	b _02212C58
_02212C56:
	mov r6, #0x19
_02212C58:
	ldr r0, _02212ECC ; =0x00000743
	ldrb r0, [r5, r0]
	add r0, r6, r0
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #0x64
	bls _02212C68
	mov r6, #0x64
_02212C68:
	bl LCRandom
	mov r1, #0x64
	bl _s32_div_f
	cmp r1, r6
	bge _02212C86
	add r1, r4, #0
	add r1, #0x38
	mov r0, #2
	strb r0, [r1]
	ldr r0, _02212ECC ; =0x00000743
	mov r1, #0
	strb r1, [r5, r0]
	b _02212E70
_02212C86:
	add r1, r4, #0
	add r1, #0x38
	mov r0, #1
	strb r0, [r1]
	ldr r0, _02212ECC ; =0x00000743
	ldrb r0, [r5, r0]
	cmp r0, #0x64
	bhs _02212CB4
	ldr r0, _02212ECC ; =0x00000743
	ldrb r0, [r5, r0]
	add r1, r0, #1
	ldr r0, _02212ECC ; =0x00000743
	strb r1, [r5, r0]
	b _02212E70
_02212CA2:
	add r1, r4, #0
	add r1, #0x38
	mov r0, #1
	strb r0, [r1]
	b _02212E70
_02212CAC:
	cmp r0, #0
	beq _02212CB6
	cmp r0, #2
	beq _02212CB6
_02212CB4:
	b _02212E70
_02212CB6:
	add r0, r4, #0
	add r0, #0x40
	ldrb r0, [r0]
	lsl r6, r0, #0xc
	bne _02212CC2
	b _02212E56
_02212CC2:
	add r3, r4, #0
	add r3, #8
	ldmia r3!, {r0, r1}
	add r2, sp, #0x1c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r1, [r4, #8]
	ldr r0, [r4, #0x14]
	add r0, r1, r0
	str r0, [r4, #8]
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x18]
	add r0, r1, r0
	str r0, [r4, #0xc]
	add r0, r4, #0
	add r0, #0x46
	ldrh r1, [r0]
	ldr r0, _02212ED0 ; =ov96_0221D640
	ldrb r0, [r0, r1]
	lsl r0, r0, #0xc
	cmp r6, r0
	blt _02212D0E
	add r0, r4, #0
	add r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #2
	bne _02212D04
	add r1, r4, #0
	add r1, #0x39
	mov r0, #2
	strb r0, [r1]
	b _02212D1C
_02212D04:
	add r1, r4, #0
	add r1, #0x39
	mov r0, #0
	strb r0, [r1]
	b _02212D1C
_02212D0E:
	add r1, r4, #0
	add r1, #0x39
	mov r0, #0
	strb r0, [r1]
	add r1, r4, #0
	add r1, #0x45
	strb r0, [r1]
_02212D1C:
	mov r1, #0
	add r0, sp, #0x10
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	add r1, r4, #0
	add r1, #0x3e
	add r0, r4, #0
	add r0, #0x3c
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, #2
	bne _02212D48
	add r1, r4, #0
	add r1, #0x41
	ldrb r1, [r1]
	mov r2, #0x1e
	mul r2, r1
	ldr r1, _02212ED4 ; =ov96_0221D514
	add r1, r1, r2
	ldrb r1, [r0, r1]
	b _02212D64
_02212D48:
	cmp r1, #1
	bne _02212D5E
	add r1, r4, #0
	add r1, #0x41
	ldrb r1, [r1]
	mov r2, #0x1e
	mul r2, r1
	ldr r1, _02212ED8 ; =ov96_0221D5AA
	add r1, r1, r2
	ldrb r1, [r0, r1]
	b _02212D64
_02212D5E:
	bl GF_AssertFail
	mov r1, #0
_02212D64:
	add r0, r4, #0
	add r0, #0x40
	strb r1, [r0]
	add r2, r4, #0
	add r0, r5, #0
	add r1, r4, #0
	add r2, #0x20
	bl ov96_022134D4
	add r0, r4, #0
	add r0, #0x3c
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0x3c
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x3c
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x3d
	ldrb r0, [r0]
	cmp r1, r0
	blo _02212DB8
	mov r0, #0
	str r0, [r4, #0x14]
	add r2, r4, #0
	add r3, sp, #0x10
	str r0, [r4, #0x18]
	ldmia r3!, {r0, r1}
	add r2, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, r4, #0
	str r0, [r2]
	add r1, #0x3e
	mov r0, #0
	strb r0, [r1]
	add r1, r4, #0
	add r1, #0x40
	strb r0, [r1]
	b _02212DE4
_02212DB8:
	add r0, r4, #0
	add r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _02212DE4
	add r3, sp, #0x10
	add r2, r4, #0
	ldmia r3!, {r0, r1}
	add r2, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, r4, #0
	str r0, [r2]
	add r1, #0x3c
	mov r0, #0
	strb r0, [r1]
	add r1, r4, #0
	add r1, #0x3d
	strb r0, [r1]
	add r1, r4, #0
	add r1, #0x3e
	strb r0, [r1]
_02212DE4:
	mov r0, #0
	str r0, [r4, #0x48]
	add r0, sp, #4
	str r0, [sp]
	add r0, r4, #0
	add r0, #8
	add r1, sp, #0x1c
	mov r2, #8
	mov r3, #0
	bl ov96_02213728
	add r3, r0, #0
	beq _02212E10
	add r6, sp, #4
	add r2, r4, #0
	ldmia r6!, {r0, r1}
	add r2, #8
	stmia r2!, {r0, r1}
	ldr r0, [r6]
	str r0, [r2]
	mov r0, #1
	str r0, [r4, #0x48]
_02212E10:
	cmp r3, #4
	bhi _02212E70
	add r0, r3, r3
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02212E20: ; jump table
	.short _02212E70 - _02212E20 - 2 ; case 0
	.short _02212E40 - _02212E20 - 2 ; case 1
	.short _02212E40 - _02212E20 - 2 ; case 2
	.short _02212E2A - _02212E20 - 2 ; case 3
	.short _02212E2A - _02212E20 - 2 ; case 4
_02212E2A:
	mov r0, #0
	ldr r1, [r4, #0x24]
	mvn r0, r0
	mul r0, r1
	str r0, [r4, #0x24]
	mov r0, #0
	ldr r1, [r4, #0x18]
	mvn r0, r0
	mul r0, r1
	str r0, [r4, #0x18]
	b _02212E70
_02212E40:
	mov r0, #0
	ldr r1, [r4, #0x20]
	mvn r0, r0
	mul r0, r1
	str r0, [r4, #0x20]
	mov r0, #0
	ldr r1, [r4, #0x14]
	mvn r0, r0
	mul r0, r1
	str r0, [r4, #0x14]
	b _02212E70
_02212E56:
	add r1, r4, #0
	add r1, #0x39
	mov r0, #0
	strb r0, [r1]
	add r1, r4, #0
	add r1, #0x45
	strb r0, [r1]
	add r1, r4, #0
	add r1, #0x46
	strh r0, [r1]
	add r1, r4, #0
	add r1, #0x3e
	strb r0, [r1]
_02212E70:
	add r7, r7, #1
	add r4, #0x4c
	cmp r7, #2
	bge _02212E7A
	b _02212BC6
_02212E7A:
	ldr r4, _02212EDC ; =0x00000664
	ldrb r0, [r5, r4]
	cmp r0, #0
	beq _02212F06
	add r0, r4, #0
	add r0, #0x4c
	ldrb r0, [r5, r0]
	cmp r0, #0
	beq _02212F06
	add r6, r4, #0
	sub r6, #0x38
	add r0, r5, r6
	add r0, #0x39
	ldrb r0, [r0]
	add r4, #0x14
	cmp r0, #1
	beq _02212F06
	cmp r0, #3
	beq _02212F06
	add r0, r5, r4
	add r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	beq _02212F06
	cmp r0, #3
	beq _02212F06
	add r0, r5, r6
	add r0, #0x38
	ldrb r0, [r0]
	cmp r0, #1
	bne _02212EBC
	mov r1, #8
	b _02212EE8
_02212EBC:
	cmp r0, #2
	bne _02212EE0
	mov r1, #0xc
	b _02212EE8
	.balign 4, 0
_02212EC4: .word 0x0000062C
_02212EC8: .word 0x00000738
_02212ECC: .word 0x00000743
_02212ED0: .word ov96_0221D640
_02212ED4: .word ov96_0221D514
_02212ED8: .word ov96_0221D5AA
_02212EDC: .word 0x00000664
_02212EE0:
	bl GF_AssertFail
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
_02212EE8:
	add r0, r5, r6
	add r2, r5, r4
	mov r3, #2
	add r0, #8
	lsl r1, r1, #0xc
	add r2, #8
	lsl r3, r3, #0xe
	bl ov96_0221341C
	cmp r0, #0
	beq _02212F06
	add r0, r5, r6
	add r1, r5, r4
	bl ov96_02212F0C
_02212F06:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02212B94


	thumb_func_start ov96_02212F0C
ov96_02212F0C: ; 0x02212F0C
	push {r4, r5, lr}
	sub sp, #0x4c
	add r2, r0, #0
	add r5, r2, #0
	add r5, #0x14
	add r4, r1, #0
	ldmia r5!, {r0, r1}
	add r3, sp, #0x14
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r5, r2, #0
	str r0, [r3]
	add r5, #0x20
	ldmia r5!, {r0, r1}
	add r3, sp, #0x20
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, sp, #0x20
	str r0, [r3]
	add r0, r2, #0
	add r0, #0x39
	ldrb r0, [r0]
	add r5, r2, #0
	add r5, #8
	strb r0, [r1, #0x19]
	add r0, r2, #0
	add r0, #0x3b
	ldrb r0, [r0]
	add r3, sp, #8
	strb r0, [r1, #0x1b]
	add r0, r2, #0
	add r0, #0x3c
	ldrb r0, [r0]
	strb r0, [r1, #0x1c]
	add r0, r2, #0
	add r0, #0x3d
	ldrb r0, [r0]
	strb r0, [r1, #0x1d]
	add r0, r2, #0
	add r0, #0x3e
	ldrb r0, [r0]
	strb r0, [r1, #0x1e]
	add r0, r2, #0
	add r0, #0x40
	ldrb r0, [r0]
	add r1, sp, #0x40
	strb r0, [r1]
	add r0, r2, #0
	add r0, #0x41
	ldrb r0, [r0]
	strb r0, [r1, #1]
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r4, #0
	str r0, [r3]
	add r0, r2, #0
	mov r2, #0
	bl ov96_02212F94
	add r0, r4, #0
	add r1, sp, #0
	mov r2, #1
	bl ov96_02212F94
	add sp, #0x4c
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02212F0C


	thumb_func_start ov96_02212F94
ov96_02212F94: ; 0x02212F94
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	add r4, r1, #0
	str r2, [sp]
	add r1, sp, #0x1c
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r1, r5, #0
	add r1, #0x40
	ldrb r1, [r1]
	cmp r1, #3
	bhi _02213032
	add r1, r4, #0
	add r1, #0x40
	ldrb r1, [r1]
	cmp r1, #3
	bls _02213006
	add r0, r4, #0
	add r0, #0x39
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x39
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x3c
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x3c
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x3d
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x3d
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x3e
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x3e
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x40
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x40
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x41
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x41
	strb r1, [r0]
	b _0221305C
_02213006:
	add r1, r5, #0
	add r1, #0x39
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x3c
	strb r0, [r1]
	add r1, r5, #0
	mov r2, #0x1e
	add r1, #0x3d
	strb r2, [r1]
	add r1, r5, #0
	mov r2, #1
	add r1, #0x3e
	strb r2, [r1]
	add r1, r5, #0
	mov r2, #3
	add r1, #0x40
	strb r2, [r1]
	add r1, r5, #0
	add r1, #0x41
	strb r0, [r1]
	b _0221305C
_02213032:
	add r1, r5, #0
	add r1, #0x39
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x3c
	strb r0, [r1]
	add r1, r5, #0
	mov r2, #0x1e
	add r1, #0x3d
	strb r2, [r1]
	add r1, r5, #0
	mov r2, #1
	add r1, #0x3e
	strb r2, [r1]
	add r1, r5, #0
	mov r2, #3
	add r1, #0x40
	strb r2, [r1]
	add r1, r5, #0
	add r1, #0x41
	strb r0, [r1]
_0221305C:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r5, #0
	add r0, #8
	add r1, #8
	add r2, #0x20
	bl VEC_Subtract
	add r0, r5, #0
	add r0, #0x20
	bl VEC_Mag
	cmp r0, #0
	bne _022130B4
	ldr r3, _022130E4 ; =ov96_0221D268
	add r2, sp, #0x10
	ldmia r3!, {r0, r1}
	add r6, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _022130E8 ; =ov96_0221D280
	str r0, [r2]
	add r7, sp, #4
	ldmia r3!, {r0, r1}
	add r2, r7, #0
	stmia r7!, {r0, r1}
	ldr r0, [r3]
	str r0, [r7]
	ldr r0, [sp]
	cmp r0, #0
	bne _022130A8
	add r2, r5, #0
	ldmia r6!, {r0, r1}
	add r2, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r6]
	str r0, [r2]
	b _022130B4
_022130A8:
	add r3, r5, #0
	ldmia r2!, {r0, r1}
	add r3, #0x20
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
_022130B4:
	add r0, r5, #0
	add r0, #0x20
	add r1, r0, #0
	bl VEC_Normalize
	add r0, r5, #0
	add r0, #0x40
	ldrb r0, [r0]
	add r1, r5, #0
	add r3, r5, #0
	lsl r0, r0, #0xc
	add r1, #0x20
	add r2, sp, #0x1c
	add r3, #0x14
	bl VEC_MultAdd
	add r4, #0x3b
	ldrb r0, [r4]
	cmp r0, #0xc
	bhs _022130E0
	add r5, #0x3b
	strb r0, [r5]
_022130E0:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022130E4: .word ov96_0221D268
_022130E8: .word ov96_0221D280
	thumb_func_end ov96_02212F94


	thumb_func_start ov96_022130EC
ov96_022130EC: ; 0x022130EC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	str r0, [sp, #4]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	ldr r1, _022132F0 ; =0x0000062C
	str r0, [sp, #0x14]
	add r5, r0, r1
	add r0, #0x5c
	str r0, [sp, #0x14]
_02213108:
	add r0, r5, #0
	add r0, #0x38
	ldrb r0, [r0]
	cmp r0, #0
	beq _02213172
	add r0, r5, #0
	add r0, #0x39
	ldrb r0, [r0]
	cmp r0, #0
	beq _02213120
	cmp r0, #2
	bne _02213172
_02213120:
	ldr r1, [r5, #8]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x18]
	ldr r1, [r5, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x1c]
	add r0, r5, #0
	bl ov96_022143DC
	ldr r1, _022132F4 ; =ov96_0221D474
	lsl r2, r0, #4
	str r0, [sp, #8]
	ldr r0, _022132F4 ; =ov96_0221D474
	add r1, r1, r2
	add r0, r0, r2
	add r1, #8
	add r2, sp, #0x18
	bl sub_02020E80
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _02213172
	add r1, r5, #0
	add r1, #0x39
	mov r0, #1
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x3a
	mov r0, #0xa
	strb r0, [r1]
	add r0, r5, #0
	add r0, #0x3b
	ldrb r4, [r0]
	cmp r4, #0xc
	bne _02213174
_02213172:
	b _022132DC
_02213174:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x5d
	lsl r0, r0, #2
	add r2, r7, #0
	mul r2, r0
	ldr r0, [sp, #0x14]
	add r6, r1, #0
	add r4, r0, r2
	mov r0, #0x7c
	mul r6, r0
	ldr r0, [sp, #8]
	cmp r0, r7
	bne _02213238
	add r0, r4, r6
	add r0, #0x5e
	ldrh r0, [r0]
	cmp r0, #0
	beq _022131B6
	add r0, r4, r6
	add r0, #0x5e
	ldrh r0, [r0]
	sub r1, r0, #1
	add r0, r4, r6
	add r0, #0x5e
	strh r1, [r0]
_022131B6:
	add r0, r5, #0
	add r0, #0x3b
	ldrb r0, [r0]
	mov r1, #3
	bl _s32_div_f
	lsl r1, r0, #2
	ldr r0, [sp, #0xc]
	add r0, r0, r1
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	cmp r1, #0
	beq _022131DA
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	sub r2, r1, #1
	ldr r1, _022132F8 ; =0x000006F4
	str r2, [r0, r1]
_022131DA:
	add r0, r5, #0
	add r0, #0x3b
	ldrb r6, [r0]
	mov r1, #3
	add r0, r6, #0
	bl _s32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r4, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #8
	bl ov96_021E8228
	add r0, r5, #0
	add r0, #0x3b
	ldrb r6, [r0]
	mov r1, #3
	add r0, r6, #0
	bl _s32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r4, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #1
	bl ov96_021E8228
	b _022132DC
_02213238:
	add r0, r5, #0
	add r0, #0x38
	ldrb r0, [r0]
	mov r7, #0
	cmp r0, #1
	bne _02213248
	mov r7, #1
	b _02213254
_02213248:
	cmp r0, #2
	bne _02213250
	mov r7, #2
	b _02213254
_02213250:
	bl GF_AssertFail
_02213254:
	add r0, r4, r6
	add r0, #0x5e
	ldrh r0, [r0]
	add r0, r0, r7
	cmp r0, #0x63
	bgt _0221326E
	add r0, r4, r6
	add r0, #0x5e
	ldrh r0, [r0]
	add r1, r0, r7
	add r0, r4, r6
	add r0, #0x5e
	strh r1, [r0]
_0221326E:
	add r0, r5, #0
	add r0, #0x3b
	ldrb r0, [r0]
	mov r1, #3
	bl _s32_div_f
	lsl r1, r0, #2
	ldr r0, [sp, #0xc]
	add r0, r0, r1
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	add r1, r7, r1
	cmp r1, #0x63
	bgt _02213294
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	add r2, r1, r7
	ldr r1, _022132F8 ; =0x000006F4
	str r2, [r0, r1]
_02213294:
	ldr r0, [sp, #8]
	lsl r1, r0, #2
	ldr r0, [sp, #0xc]
	add r0, r0, r1
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	cmp r1, #0
	beq _022132AE
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	sub r2, r1, #1
	ldr r1, _022132F8 ; =0x000006F4
	str r2, [r0, r1]
_022132AE:
	add r0, r5, #0
	add r0, #0x3b
	ldrb r6, [r0]
	mov r1, #3
	add r0, r6, #0
	bl _s32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r4, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #3
	bl ov96_021E8228
_022132DC:
	ldr r0, [sp, #0x10]
	add r5, #0x4c
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #2
	bge _022132EA
	b _02213108
_022132EA:
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022132F0: .word 0x0000062C
_022132F4: .word ov96_0221D474
_022132F8: .word 0x000006F4
	thumb_func_end ov96_022130EC

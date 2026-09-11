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
	.public ov96_0221341C
	.public ov96_02213514
	.public ov96_02213534
	.public ov96_02213558
	.public ov96_022141F8
	.public ov96_02214234
	.public ov96_022143FC
	.public ov96_02214490
	.public ov96_0221454C
	.public ov96_02214618
	.public ov96_02214690
	.public ov96_022148E8


	thumb_func_start ov96_0221359C
ov96_0221359C: ; 0x0221359C
	push {r4, r5, r6, lr}
	add r6, r1, #0
	add r1, r2, #0
	add r2, r3, #0
	ldr r5, [sp, #0x10]
	bl ov96_021E60D8
	add r4, r0, #0
	ldrb r0, [r4, #4]
	lsl r0, r0, #2
	ldr r1, [r6, r0]
	add r0, r5, #0
	add r0, #0x6c
	strh r1, [r0]
	ldrb r0, [r4, #4]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r1, [r0, #0x14]
	add r0, r5, #0
	add r0, #0x6e
	strh r1, [r0]
	ldrb r0, [r4, #3]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r1, [r0, #0x28]
	add r0, r5, #0
	add r0, #0x70
	strb r1, [r0]
	ldrb r0, [r4, #3]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r1, [r0, #0x28]
	add r0, r5, #0
	add r0, #0x71
	strb r1, [r0]
	ldrb r0, [r4, #1]
	mov r1, #0xa
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r0, [r0, #0x3c]
	lsl r0, r0, #0xc
	bl _s32_div_f
	str r0, [r5, #0x64]
	ldrb r0, [r4, #1]
	mov r1, #0xa
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r0, [r0, #0x50]
	lsl r0, r0, #0xc
	bl _s32_div_f
	str r0, [r5, #0x68]
	ldrb r0, [r4]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r1, [r0, #0x64]
	add r0, r5, #0
	add r0, #0x72
	strb r1, [r0]
	add r0, r5, #0
	ldrb r1, [r4, #4]
	add r0, #0x73
	strb r1, [r0]
	add r0, r5, #0
	ldrb r1, [r4]
	add r0, #0x75
	add r5, #0x74
	strb r1, [r0]
	ldrb r0, [r4, #3]
	strb r0, [r5]
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_0221359C




	thumb_func_start ov96_0221362C
ov96_0221362C: ; 0x0221362C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	add r1, r7, #0
	ldr r0, [r7, #4]
	ldr r2, _0221369C ; =ov96_0221D1F8
	add r1, #8
	bl AddWindow
	add r5, r7, #0
	ldr r4, _022136A0 ; =ov96_0221D360
	mov r6, #0
	add r5, #0x18
_02213646:
	ldr r0, [r7, #4]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r6, r6, #1
	add r4, #8
	add r5, #0x10
	cmp r6, #4
	blt _02213646
	mov r2, #0
	str r2, [sp]
	ldr r0, [r7, #4]
	mov r1, #3
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0
	str r1, [sp]
	ldr r0, [r7, #4]
	add r2, r1, #0
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r7, #0x58]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r7, #0x58]
	mov r1, #0x13
	str r0, [sp, #4]
	mov r0, #0xec
	add r3, r0, #0
	mov r2, #0
	add r3, #0xd4
	bl GfGfxLoader_GXLoadPal
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221369C: .word ov96_0221D1F8
_022136A0: .word ov96_0221D360
	thumb_func_end ov96_0221362C




	thumb_func_start ov96_022136A4
ov96_022136A4: ; 0x022136A4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	add r0, #8
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r2, _02213720 ; =0x00000135
	ldr r3, [r5, #0x58]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	add r4, r0, #0
	ldr r0, [r5, #0x58]
	bl MessageFormat_New
	mov r1, #0
	str r1, [sp]
	mov r2, #1
	str r2, [sp, #4]
	add r2, r7, #0
	mov r3, #3
	add r6, r0, #0
	bl BufferIntegerAsString
	ldr r3, [r5, #0x58]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0xa5
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02213724 ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #8
	add r2, r7, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl MessageFormat_Delete
	add r0, r4, #0
	bl DestroyMsgData
	add r5, #8
	add r0, r5, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02213720: .word 0x00000135
_02213724: .word 0x000F0E00
	thumb_func_end ov96_022136A4




	thumb_func_start ov96_02213728
ov96_02213728: ; 0x02213728
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xb8
	add r7, r0, #0
	str r2, [sp, #4]
	add r0, sp, #0xac
	mov r2, #0
	str r2, [r0]
	str r2, [r0, #4]
	str r2, [r0, #8]
	add r0, sp, #0xa0
	str r2, [r0]
	str r2, [r0, #4]
	str r2, [r0, #8]
	add r0, sp, #0x7c
	str r2, [r0]
	str r2, [r0, #4]
	str r2, [r0, #8]
	add r0, sp, #0x70
	str r3, [sp, #8]
	str r2, [r0]
	str r2, [r0, #4]
	ldr r3, _02213928 ; =ov96_0221D214
	add r5, r1, #0
	str r2, [r0, #8]
	ldmia r3!, {r0, r1}
	add r6, sp, #0x64
	stmia r6!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _0221392C ; =ov96_0221D274
	str r0, [r6]
	ldmia r3!, {r0, r1}
	add r6, sp, #0x58
	stmia r6!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _02213930 ; =ov96_0221D244
	str r0, [r6]
	ldmia r3!, {r0, r1}
	add r6, sp, #0x4c
	stmia r6!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _02213934 ; =ov96_0221D22C
	str r0, [r6]
	ldmia r3!, {r0, r1}
	add r6, sp, #0x40
	stmia r6!, {r0, r1}
	ldr r0, [r3]
	ldr r4, [sp, #0xd0]
	str r0, [r6]
	str r2, [r4]
	str r2, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r5]
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	str r0, [sp, #0x28]
	ldr r0, [r5, #4]
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	str r0, [sp, #0x2c]
	ldr r0, [r7]
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	str r0, [sp, #0x20]
	ldr r0, [r7, #4]
	asr r1, r0, #0xb
	lsr r1, r1, #0x14
	add r1, r0, r1
	asr r0, r1, #0xc
	str r0, [sp, #0x24]
	mov r0, #7
	ldr r1, [r7, #4]
	lsl r0, r0, #0x10
	cmp r1, r0
	ldr r1, [r7]
	bge _022137D6
	mov r0, #2
	lsl r0, r0, #0x12
	cmp r1, r0
	blt _022137E4
	mov r2, #1
	b _022137E4
_022137D6:
	mov r0, #2
	lsl r0, r0, #0x12
	cmp r1, r0
	bge _022137E2
	mov r2, #2
	b _022137E4
_022137E2:
	mov r2, #3
_022137E4:
	mov r6, #0
	ldr r0, [sp, #8]
	str r6, [sp, #0x14]
	str r6, [sp, #0x10]
	cmp r0, #0
	bne _022137F2
	b _02213942
_022137F2:
	cmp r2, #3
	bhi _0221388E
	add r0, r2, r2
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02213802: ; jump table
	.short _0221380A - _02213802 - 2 ; case 0
	.short _0221382A - _02213802 - 2 ; case 1
	.short _0221384C - _02213802 - 2 ; case 2
	.short _0221386A - _02213802 - 2 ; case 3
_0221380A:
	mov r0, #7
	lsl r0, r0, #0x10
	ldr r1, _02213938 ; =0xFFFE0000
	str r0, [sp, #0x80]
	mov r0, #6
	lsl r0, r0, #0x10
	str r0, [sp, #0x70]
	asr r0, r1, #1
	str r1, [sp, #0x7c]
	str r0, [sp, #0x74]
	add r0, sp, #0x64
	add r1, sp, #0x88
	bl VEC_Normalize
	mov r6, #5
	b _02213892
_0221382A:
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r0, [sp, #0x7c]
	ldr r0, _0221393C ; =0xFFFF0000
	add r1, sp, #0x88
	str r0, [sp, #0x80]
	mov r0, #0x12
	lsl r0, r0, #0x10
	str r0, [sp, #0x70]
	mov r0, #7
	lsl r0, r0, #0x10
	str r0, [sp, #0x74]
	add r0, sp, #0x58
	bl VEC_Normalize
	mov r6, #6
	b _02213892
_0221384C:
	mov r0, #0xe
	lsl r0, r0, #0x10
	mov r1, #6
	lsl r1, r1, #0x10
	str r0, [sp, #0x80]
	ldr r0, _02213938 ; =0xFFFE0000
	str r1, [sp, #0x7c]
	str r0, [sp, #0x70]
	str r1, [sp, #0x74]
	add r0, sp, #0x4c
	add r1, sp, #0x88
	bl VEC_Normalize
	mov r6, #7
	b _02213892
_0221386A:
	mov r0, #0x12
	lsl r0, r0, #0x10
	str r0, [sp, #0x7c]
	mov r0, #6
	lsl r0, r0, #0x10
	str r0, [sp, #0x80]
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r0, [sp, #0x70]
	mov r0, #0xe
	lsl r0, r0, #0x10
	str r0, [sp, #0x74]
	add r0, sp, #0x40
	add r1, sp, #0x88
	bl VEC_Normalize
	mov r6, #8
	b _02213892
_0221388E:
	bl GF_AssertFail
_02213892:
	cmp r6, #0
	beq _02213942
	ldr r0, [sp, #4]
	add r2, sp, #0x7c
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	add r1, sp, #0x88
	add r3, r2, #0
	bl VEC_MultAdd
	add r2, sp, #0x70
	ldr r0, [sp, #0xc]
	add r1, sp, #0x88
	add r3, r2, #0
	bl VEC_MultAdd
	ldr r1, [sp, #0x7c]
	add r2, sp, #0x28
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [sp, #0x80]
	str r0, [sp, #0x38]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [sp, #0x70]
	str r0, [sp, #0x3c]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	ldr r1, [sp, #0x74]
	str r0, [sp, #0x30]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x34]
	add r0, sp, #0x18
	str r0, [sp]
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r3, sp, #0x20
	bl sub_02020F4C
	cmp r0, #0
	beq _02213940
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x18
	bl sub_02020E80
	cmp r0, #0
	bne _02213916
	add r2, r5, #0
	ldmia r2!, {r0, r1}
	add r3, r4, #0
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
	mov r0, #1
	str r0, [sp, #0x14]
	b _02213922
_02213916:
	ldr r0, [sp, #0x18]
	lsl r0, r0, #0xc
	str r0, [r4]
	ldr r0, [sp, #0x1c]
	lsl r0, r0, #0xc
	str r0, [r4, #4]
_02213922:
	mov r0, #1
	str r0, [sp, #0x10]
	b _02213942
	.balign 4, 0
_02213928: .word ov96_0221D214
_0221392C: .word ov96_0221D274
_02213930: .word ov96_0221D244
_02213934: .word ov96_0221D22C
_02213938: .word 0xFFFE0000
_0221393C: .word 0xFFFF0000
_02213940:
	mov r6, #0
_02213942:
	mov r1, #7
	ldr r0, [r7, #4]
	lsl r1, r1, #0x10
	cmp r0, r1
	blt _0221394E
	b _02213B28
_0221394E:
	ldr r1, [sp, #4]
	add r1, #0x10
	lsl r2, r1, #0xc
	cmp r0, r2
	bge _02213974
	ldr r0, [sp, #4]
	mov r1, #0x10
	sub r0, r1, r0
	ldr r3, [r5, #4]
	lsl r0, r0, #0xc
	cmp r3, r0
	bne _02213974
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_02213974:
	mov r0, #2
	lsl r0, r0, #0xe
	str r0, [sp, #0xac]
	mov r0, #0xf7
	lsl r0, r0, #0xc
	str r0, [sp, #0xa0]
	str r2, [sp, #0xb0]
	str r2, [sp, #0xa4]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _022139EC
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _022139A4
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_022139A4:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _022139B8
	ldr r1, [r4, #4]
	ldr r0, [sp, #0x98]
	cmp r1, r0
	blt _022139B8
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_022139B8:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _022139DC
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _022139DC
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_022139DC:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_022139EC:
	mov r1, #2
	ldr r0, [r7]
	lsl r1, r1, #0x12
	cmp r0, r1
	bge _02213A8E
	ldr r1, [sp, #4]
	add r1, #8
	str r1, [sp, #4]
	lsl r1, r1, #0xc
	cmp r0, r1
	bge _02213A16
	ldr r0, [r5]
	cmp r0, r1
	bne _02213A16
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213A16:
	mov r0, #0xb7
	lsl r0, r0, #0xc
	str r0, [sp, #0xb0]
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0xa4]
	str r1, [sp, #0xac]
	str r1, [sp, #0xa0]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _02213AD2
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213A46
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213A46:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213A5A
	ldr r1, [r4]
	ldr r0, [sp, #0x94]
	cmp r1, r0
	blt _02213A5A
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213A5A:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213A7E
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213A7E
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213A7E:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213A8E:
	ldr r1, [sp, #4]
	mov r2, #0xf7
	sub r1, r2, r1
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _02213AAE
	ldr r0, [r5]
	cmp r0, r1
	bne _02213AAE
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213AAE:
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0xb0]
	mov r0, #0xb7
	lsl r0, r0, #0xc
	str r0, [sp, #0xa4]
	str r1, [sp, #0xac]
	str r1, [sp, #0xa0]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	bne _02213AD4
_02213AD2:
	b _02213CFA
_02213AD4:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213AE0
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213AE0:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213AF4
	ldr r1, [r4]
	ldr r0, [sp, #0x94]
	cmp r1, r0
	bgt _02213AF4
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213AF4:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213B18
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213B18
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213B18:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213B28:
	ldr r1, [sp, #4]
	mov r2, #0xb7
	sub r1, r2, r1
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _02213B48
	ldr r0, [r5, #4]
	cmp r0, r1
	bne _02213B48
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_02213B48:
	mov r0, #0xf7
	lsl r0, r0, #0xc
	str r0, [sp, #0xac]
	mov r0, #2
	lsl r0, r0, #0xe
	str r0, [sp, #0xa0]
	str r1, [sp, #0xb0]
	str r1, [sp, #0xa4]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _02213BC0
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213B78
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213B78:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213B8C
	ldr r1, [r4, #4]
	ldr r0, [sp, #0x98]
	cmp r1, r0
	bgt _02213B8C
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213B8C:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213BB0
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213BB0
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_02213BB0:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_02213BC0:
	mov r1, #2
	ldr r0, [r7]
	lsl r1, r1, #0x12
	cmp r0, r1
	bge _02213C62
	ldr r1, [sp, #4]
	add r1, #8
	str r1, [sp, #4]
	lsl r1, r1, #0xc
	cmp r0, r1
	bge _02213BEA
	ldr r0, [r5]
	cmp r0, r1
	bne _02213BEA
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213BEA:
	mov r0, #0xb7
	lsl r0, r0, #0xc
	str r0, [sp, #0xb0]
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0xa4]
	str r1, [sp, #0xac]
	str r1, [sp, #0xa0]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _02213CFA
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213C1A
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213C1A:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213C2E
	ldr r1, [r4]
	ldr r0, [sp, #0x94]
	cmp r1, r0
	blt _02213C2E
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213C2E:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213C52
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213C52
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213C52:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213C62:
	ldr r1, [sp, #4]
	mov r2, #0xf7
	sub r1, r2, r1
	lsl r1, r1, #0xc
	cmp r0, r1
	ble _02213C82
	ldr r0, [r5]
	cmp r0, r1
	bne _02213C82
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213C82:
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0xb0]
	mov r0, #0xb7
	lsl r0, r0, #0xc
	str r0, [sp, #0xa4]
	str r1, [sp, #0xac]
	str r1, [sp, #0xa0]
	add r0, sp, #0x94
	str r0, [sp]
	add r0, sp, #0xac
	add r1, sp, #0xa0
	add r2, r5, #0
	add r3, r7, #0
	bl ov96_02213D2C
	cmp r0, #0
	beq _02213CFA
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02213CB2
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213CB2:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02213CC6
	ldr r1, [r4]
	ldr r0, [sp, #0x94]
	cmp r1, r0
	bgt _02213CC6
	add sp, #0xb8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213CC6:
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _02213CEA
	add r0, sp, #0x38
	add r1, sp, #0x30
	add r2, sp, #0x28
	add r3, sp, #0x94
	bl ov96_02213D00
	cmp r0, #0
	beq _02213CEA
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213CEA:
	add r2, sp, #0x94
	ldmia r2!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r2]
	add sp, #0xb8
	str r0, [r4]
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_02213CFA:
	add r0, r6, #0
	add sp, #0xb8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02213728




	thumb_func_start ov96_02213D00
ov96_02213D00: ; 0x02213D00
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r5, [r3]
	asr r4, r5, #0xb
	lsr r4, r4, #0x14
	add r4, r5, r4
	asr r4, r4, #0xc
	str r4, [sp, #0xc]
	ldr r4, [r3, #4]
	asr r3, r4, #0xb
	lsr r3, r3, #0x14
	add r3, r4, r3
	asr r3, r3, #0xc
	str r3, [sp, #0x10]
	add r3, sp, #4
	str r3, [sp]
	add r3, sp, #0xc
	bl sub_02020F4C
	add sp, #0x14
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02213D00




	thumb_func_start ov96_02213D2C
ov96_02213D2C: ; 0x02213D2C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	add r5, r0, #0
	add r6, r1, #0
	add r1, sp, #0x2c
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r1, [r5]
	add r4, r2, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x18]
	ldr r1, [r5, #4]
	add r7, r3, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x1c]
	ldr r1, [r6]
	add r2, sp, #8
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x10]
	ldr r1, [r6, #4]
	add r3, sp, #0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x14]
	ldr r1, [r4]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #8]
	ldr r1, [r4, #4]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0xc]
	ldr r1, [r7]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp]
	ldr r1, [r7, #4]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #4]
	add r0, sp, #0x18
	add r1, sp, #0x10
	bl sub_02020EB0
	cmp r0, #0
	bne _02213DB8
	add sp, #0x38
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213DB8:
	add r0, r6, #0
	add r1, r5, #0
	add r2, sp, #0x20
	bl VEC_Subtract
	add r0, sp, #0x20
	add r1, r0, #0
	bl VEC_Normalize
	ldr r1, [r5, #4]
	ldr r0, [r6, #4]
	cmp r1, r0
	bne _02213E10
	ldr r0, [r4, #4]
	sub r0, r1, r0
	bpl _02213DDE
	mov r2, #0
	mvn r2, r2
	mul r0, r2
_02213DDE:
	ldr r2, [r7, #4]
	sub r3, r1, r2
	bpl _02213DEA
	mov r2, #0
	mvn r2, r2
	mul r3, r2
_02213DEA:
	cmp r3, #0
	bne _02213DF4
	add sp, #0x38
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213DF4:
	ldr r2, [r4]
	str r1, [sp, #0x30]
	add r1, r0, r3
	str r2, [sp, #0x2c]
	bl FX_Div
	ldr r3, [sp, #0x50]
	add r1, sp, #0x20
	add r2, sp, #0x2c
	bl VEC_MultAdd
	add sp, #0x38
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213E10:
	ldr r1, [r5]
	ldr r0, [r6]
	cmp r1, r0
	bne _02213E56
	ldr r0, [r4]
	sub r0, r1, r0
	bpl _02213E24
	mov r2, #0
	mvn r2, r2
	mul r0, r2
_02213E24:
	ldr r2, [r7]
	sub r3, r1, r2
	bpl _02213E30
	mov r2, #0
	mvn r2, r2
	mul r3, r2
_02213E30:
	cmp r3, #0
	bne _02213E3A
	add sp, #0x38
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02213E3A:
	str r1, [sp, #0x2c]
	ldr r1, [r4, #4]
	str r1, [sp, #0x30]
	add r1, r0, r3
	bl FX_Div
	ldr r3, [sp, #0x50]
	add r1, sp, #0x20
	add r2, sp, #0x2c
	bl VEC_MultAdd
	add sp, #0x38
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02213E56:
	bl GF_AssertFail
	mov r0, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02213D2C




	thumb_func_start ov96_02213E60
ov96_02213E60: ; 0x02213E60
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r1, #0
	ldr r1, _02213EB8 ; =0x0000066E
	mov r4, #0
	ldrb r6, [r0, r1]
	add r3, r4, #0
	add r2, sp, #0
	add r1, #0x4c
_02213E72:
	cmp r6, r3
	beq _02213E86
	ldrb r5, [r0, r1]
	cmp r5, r3
	beq _02213E86
	add r5, r4, #0
	add r4, r4, #1
	lsl r4, r4, #0x18
	lsr r4, r4, #0x18
	strb r3, [r2, r5]
_02213E86:
	add r3, r3, #1
	cmp r3, #0xf
	blt _02213E72
	bl LCRandom
	add r1, r4, #0
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	add r0, sp, #0
	ldrb r0, [r0, r1]
	ldr r1, _02213EBC ; =ov96_0221D438
	lsl r2, r0, #2
	ldrsh r1, [r1, r2]
	lsl r1, r1, #0xc
	str r1, [r7, #8]
	ldr r1, _02213EC0 ; =ov96_0221D43A
	ldrsh r1, [r1, r2]
	lsl r1, r1, #0xc
	str r1, [r7, #0xc]
	add r7, #0x42
	strb r0, [r7]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02213EB8: .word 0x0000066E
_02213EBC: .word ov96_0221D438
_02213EC0: .word ov96_0221D43A
	thumb_func_end ov96_02213E60




	thumb_func_start ov96_02213EC4
ov96_02213EC4: ; 0x02213EC4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r1, r5, #0
	add r1, #0x39
	ldrb r1, [r1]
	cmp r1, #3
	bne _02213F14
	mov r0, #0x16
	ldr r1, [r5, #0xc]
	lsl r0, r0, #0xe
	cmp r1, r0
	bne _02213EE4
	add r5, #0x43
	ldrb r0, [r5]
	add r0, #0xc0
	b _02213F56
_02213EE4:
	mov r0, #0x1a
	lsl r0, r0, #0xe
	cmp r1, r0
	bne _02213EF4
	add r5, #0x43
	ldrb r0, [r5]
	add r0, #0xc8
	b _02213F56
_02213EF4:
	mov r0, #0x1e
	lsl r0, r0, #0xe
	cmp r1, r0
	bne _02213F04
	add r5, #0x43
	ldrb r0, [r5]
	add r0, #0xd0
	b _02213F56
_02213F04:
	bl GF_AssertFail
	ldr r1, [r5, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	b _02213F56
_02213F14:
	cmp r1, #1
	bne _02213F4C
	add r1, r5, #0
	add r1, #0x3b
	ldrb r1, [r1]
	cmp r1, #0xc
	bne _02213F2E
	ldr r1, [r5, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	b _02213F56
_02213F2E:
	bl ov96_022143DC
	add r5, #0x3b
	add r4, r0, #0
	ldrb r0, [r5]
	mov r1, #3
	bl _s32_div_f
	add r1, r0, #0
	lsl r1, r1, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl ov96_02214394
	b _02213F56
_02213F4C:
	ldr r1, [r5, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
_02213F56:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02213EC4




	thumb_func_start ov96_02213F5C
ov96_02213F5C: ; 0x02213F5C
	push {r4, lr}
	add r4, r0, #0
	cmp r4, #0xc0
	bge _02213F68
	lsl r0, r4, #0xc
	pop {r4, pc}
_02213F68:
	cmp r4, #0xd8
	bge _02213FA0
	sub r4, #0xc0
	lsr r2, r4, #0x1f
	lsl r1, r4, #0x1d
	sub r1, r1, r2
	mov r0, #0x1d
	ror r1, r0
	add r0, r2, r1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	cmp r4, #8
	bge _02213F8A
	ldr r0, _02213FB0 ; =ov96_0221DC80
	ldrb r0, [r0, r1]
	add r0, #0x58
	b _02213F9C
_02213F8A:
	cmp r4, #0x10
	bge _02213F96
	ldr r0, _02213FB0 ; =ov96_0221DC80
	ldrb r0, [r0, r1]
	add r0, #0x68
	b _02213F9C
_02213F96:
	ldr r0, _02213FB0 ; =ov96_0221DC80
	ldrb r0, [r0, r1]
	add r0, #0x78
_02213F9C:
	lsl r0, r0, #0xc
	pop {r4, pc}
_02213FA0:
	cmp r4, #0xe8
	bge _02213FA8
	lsl r0, r4, #0xc
	pop {r4, pc}
_02213FA8:
	bl GF_AssertFail
	lsl r0, r4, #0xc
	pop {r4, pc}
	.balign 4, 0
_02213FB0: .word ov96_0221DC80
	thumb_func_end ov96_02213F5C




	thumb_func_start ov96_02213FB4
ov96_02213FB4: ; 0x02213FB4
	add r1, r0, #0
	add r1, #0x5c
	ldrh r1, [r1]
	cmp r1, #4
	bhi _02213FF2
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02213FCA: ; jump table
	.short _02213FF2 - _02213FCA - 2 ; case 0
	.short _02213FD4 - _02213FCA - 2 ; case 1
	.short _02213FE4 - _02213FCA - 2 ; case 2
	.short _02213FEC - _02213FCA - 2 ; case 3
	.short _02213FDC - _02213FCA - 2 ; case 4
_02213FD4:
	mov r1, #4
	add r0, #0x5c
	strh r1, [r0]
	bx lr
_02213FDC:
	mov r1, #2
	add r0, #0x5c
	strh r1, [r0]
	bx lr
_02213FE4:
	mov r1, #3
	add r0, #0x5c
	strh r1, [r0]
	bx lr
_02213FEC:
	mov r1, #1
	add r0, #0x5c
	strh r1, [r0]
_02213FF2:
	bx lr
	thumb_func_end ov96_02213FB4




	thumb_func_start ov96_02213FF4
ov96_02213FF4: ; 0x02213FF4
	push {r3, lr}
	cmp r3, #0xc0
	bge _02214004
	add r1, r0, r1
	ldr r0, _02214038 ; =0x000007B4
	mov r2, #0
	strb r2, [r1, r0]
	pop {r3, pc}
_02214004:
	cmp r3, #0xd8
	bge _0221402E
	ldr r3, _02214038 ; =0x000007B4
	add r3, r0, r3
	ldrb r0, [r3, r1]
	cmp r0, #0
	bne _02214036
	mov r0, #1
	strb r0, [r3, r1]
	cmp r1, #0
	bne _02214026
	cmp r2, #0
	beq _02214026
	ldr r0, _0221403C ; =0x000008CA
	bl PlaySE
	pop {r3, pc}
_02214026:
	ldr r0, _02214040 ; =0x000008C9
	bl PlaySE
	pop {r3, pc}
_0221402E:
	add r1, r0, r1
	ldr r0, _02214038 ; =0x000007B4
	mov r2, #0
	strb r2, [r1, r0]
_02214036:
	pop {r3, pc}
	.balign 4, 0
_02214038: .word 0x000007B4
_0221403C: .word 0x000008CA
_02214040: .word 0x000008C9
	thumb_func_end ov96_02213FF4




	thumb_func_start ov96_02214044
ov96_02214044: ; 0x02214044
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r1, [sp, #0x10]
	add r5, r0, #0
	ldr r0, [sp, #0x10]
	add r4, r5, #0
	add r4, #0x18
	lsl r7, r0, #4
	add r0, r4, r7
	mov r1, #0
	add r6, r2, #0
	bl FillWindowPixelBuffer
	cmp r6, #0
	beq _022140A2
	cmp r6, #2
	bne _0221406C
	ldr r0, _022140E0 ; =0x000007B8
	ldr r2, [r5, r0]
	b _0221408A
_0221406C:
	cmp r6, #1
	bne _02214076
	ldr r0, _022140E4 ; =0x000007BC
	ldr r2, [r5, r0]
	b _0221408A
_02214076:
	cmp r6, #3
	bne _02214082
	mov r0, #0x1f
	lsl r0, r0, #6
	ldr r2, [r5, r0]
	b _0221408A
_02214082:
	bl GF_AssertFail
	ldr r0, _022140E0 ; =0x000007B8
	ldr r2, [r5, r0]
_0221408A:
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _022140E8 ; =0x00010200
	mov r1, #4
	str r0, [sp, #8]
	add r0, r4, r7
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	b _022140D4
_022140A2:
	ldr r0, [sp, #0x10]
	add r1, r5, r0
	ldr r0, _022140EC ; =0x00000818
	ldrb r0, [r1, r0]
	cmp r0, #0
	beq _022140B4
	mov r1, #0xc1
	lsl r1, r1, #0xa
	b _022140B6
_022140B4:
	ldr r1, _022140E8 ; =0x00010200
_022140B6:
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	ldr r2, [sp, #0x10]
	add r0, r4, r7
	lsl r2, r2, #2
	add r5, r5, r2
	ldr r2, _022140F0 ; =0x000007C4
	mov r1, #4
	ldr r2, [r5, r2]
	bl AddTextPrinterParameterizedWithColor
_022140D4:
	add r0, r4, r7
	bl CopyWindowToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_022140E0: .word 0x000007B8
_022140E4: .word 0x000007BC
_022140E8: .word 0x00010200
_022140EC: .word 0x00000818
_022140F0: .word 0x000007C4
	thumb_func_end ov96_02214044




	thumb_func_start ov96_022140F4
ov96_022140F4: ; 0x022140F4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r5, r0, #0
	ldr r2, _02214198 ; =0x00000135
	ldr r3, [r5, #0x58]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x58]
	bl MessageFormat_New
	add r7, r0, #0
	ldr r0, [sp, #0xc]
	ldr r1, _0221419C ; =0x00000133
	bl NewString_ReadMsgData
	ldr r1, _022141A0 ; =0x000007B8
	str r0, [r5, r1]
	mov r1, #0x4d
	ldr r0, [sp, #0xc]
	lsl r1, r1, #2
	bl NewString_ReadMsgData
	ldr r1, _022141A4 ; =0x000007BC
	str r0, [r5, r1]
	ldr r0, [sp, #0xc]
	ldr r1, _02214198 ; =0x00000135
	bl NewString_ReadMsgData
	mov r1, #0x1f
	lsl r1, r1, #6
	str r0, [r5, r1]
	mov r4, #0
_02214140:
	ldr r0, [sp, #8]
	add r1, r4, #0
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r5, #0x58]
	bl PlayerProfile_GetPlayerName_NewString
	add r6, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r0, r7, #0
	mov r1, #0
	add r2, r6, #0
	mov r3, #2
	bl BufferString
	ldr r1, [sp, #0xc]
	ldr r2, _022141A8 ; =0x00000132
	ldr r3, [r5, #0x58]
	add r0, r7, #0
	bl ReadMsgData_ExpandPlaceholders
	lsl r1, r4, #2
	add r2, r5, r1
	ldr r1, _022141AC ; =0x000007C4
	str r0, [r2, r1]
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _02214140
	add r0, r7, #0
	bl MessageFormat_Delete
	ldr r0, [sp, #0xc]
	bl DestroyMsgData
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02214198: .word 0x00000135
_0221419C: .word 0x00000133
_022141A0: .word 0x000007B8
_022141A4: .word 0x000007BC
_022141A8: .word 0x00000132
_022141AC: .word 0x000007C4
	thumb_func_end ov96_022140F4




	thumb_func_start ov96_022141B0
ov96_022141B0: ; 0x022141B0
	push {r4, r5, r6, lr}
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r5, r0, #0
	ldr r0, _022141EC ; =0x000007B8
	ldr r0, [r5, r0]
	bl String_Delete
	ldr r0, _022141F0 ; =0x000007BC
	ldr r0, [r5, r0]
	bl String_Delete
	mov r0, #0x1f
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl String_Delete
	ldr r6, _022141F4 ; =0x000007C4
	mov r4, #0
_022141D6:
	lsl r0, r4, #2
	add r0, r5, r0
	ldr r0, [r0, r6]
	bl String_Delete
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _022141D6
	pop {r4, r5, r6, pc}
	.balign 4, 0
_022141EC: .word 0x000007B8
_022141F0: .word 0x000007BC
_022141F4: .word 0x000007C4
	thumb_func_end ov96_022141B0



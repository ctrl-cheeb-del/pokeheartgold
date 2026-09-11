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

	thumb_func_start ov96_02203CE4
ov96_02203CE4: ; 0x02203CE4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, #0x70
	ldrb r0, [r0]
	cmp r0, #0
	beq _02203D4C
	add r0, r5, #0
	add r0, #0x71
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r5, #0
	add r0, #0x71
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x71
	ldrb r0, [r0]
	mov r1, #0x1f
	lsr r3, r0, #0x1f
	lsl r2, r0, #0x1f
	sub r2, r2, r3
	ror r2, r1
	add r1, r3, r2
	lsl r1, r1, #3
	neg r4, r1
	cmp r0, #0xa
	blo _02203D26
	add r0, r5, #0
	mov r4, #0
	add r0, #0x70
	strb r4, [r0]
	add r0, r5, #0
	add r0, #0x71
	strb r4, [r0]
_02203D26:
	ldr r0, [r5, #8]
	mov r1, #4
	mov r2, #3
	add r3, r4, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #8]
	mov r1, #5
	mov r2, #3
	add r3, r4, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #8]
	mov r1, #6
	mov r2, #3
	add r3, r4, #0
	bl ScheduleSetBgPosText
	pop {r3, r4, r5, pc}
_02203D4C:
	ldr r0, [r5, #8]
	mov r1, #4
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #8]
	mov r1, #5
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	ldr r0, [r5, #8]
	mov r1, #6
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02203CE4


	thumb_func_start ov96_02203D74
ov96_02203D74: ; 0x02203D74
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r7, r0, #0
	add r5, sp, #0x18
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	mov r6, #0
	add r4, r7, #0
	str r5, [sp, #0x14]
_02203D86:
	ldr r0, [r4, #0x54]
	bl ov96_021EB594
	ldr r1, [r0]
	ldr r3, [sp, #0xc]
	asr r2, r1, #0xb
	lsr r2, r2, #0x14
	add r2, r1, r2
	asr r1, r2, #0xc
	strh r1, [r5]
	ldr r1, [r0, #4]
	ldr r2, [sp, #0x10]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	strh r0, [r5, #2]
	mov r0, #2
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [sp, #0x14]
	mov r1, #0
	str r0, [sp, #8]
	ldr r0, [r7, #4]
	bl ov96_021E634C
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r6, #3
	blt _02203D86
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02203D74


	thumb_func_start ov96_02203DCC
ov96_02203DCC: ; 0x02203DCC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r6, r0, #0
	mov r0, #0
	add r5, r1, #0
	str r0, [sp, #0xc]
	add r4, r6, #0
	add r7, sp, #0x10
_02203DDC:
	ldrb r0, [r5, #6]
	mov r3, #0
	str r0, [sp]
	ldrh r0, [r5, #2]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	str r0, [sp, #8]
	ldrh r1, [r5]
	ldrb r2, [r5, #7]
	add r0, sp, #0x10
	bl GetMonSpriteCharAndPlttNarcIdsEx
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	ldrh r0, [r7]
	ldrh r1, [r7, #2]
	ldr r2, [r6]
	ldr r3, [r5, #0xc]
	bl sub_0201457C
	str r0, [r4, #0x24]
	ldrh r0, [r7]
	ldrh r1, [r7, #4]
	ldr r2, [r6]
	bl sub_02014450
	str r0, [r4, #0x28]
	ldr r0, [sp, #0xc]
	add r5, #0x10
	add r0, r0, #1
	add r4, #8
	str r0, [sp, #0xc]
	cmp r0, #3
	blt _02203DDC
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02203DCC


	thumb_func_start ov96_02203E30
ov96_02203E30: ; 0x02203E30
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r7, r0, #0
	str r1, [sp, #4]
	str r2, [sp, #8]
	mov r4, #0
	mov r5, #2
	mov r6, #3
_02203E40:
	add r0, r7, #0
	add r1, r6, #0
	add r2, r5, #0
	mov r3, #0x65
	str r5, [sp]
	bl ov96_021EB408
	add r4, r4, #1
	cmp r4, #3
	blt _02203E40
	mov r0, #0x10
	ldr r6, [sp, #8]
	ldr r4, [sp, #4]
	mov r5, #0
	str r0, [sp, #0xc]
_02203E5E:
	add r0, r7, #0
	mov r1, #0x65
	mov r2, #2
	bl ov96_021EB4F4
	str r0, [r4, #0x54]
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [sp, #0xc]
	mov r2, #0
	lsl r0, r0, #0xc
	str r0, [sp, #0x10]
	ldr r0, [r6, #0xc]
	str r0, [sp]
	ldrh r3, [r6, #2]
	ldrh r0, [r6]
	ldrb r1, [r6, #7]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl GetMonPicHeightBySpeciesGenderForm
	mov r1, #0x5e
	lsl r1, r1, #2
	add r0, r0, r1
	lsl r0, r0, #0xc
	str r0, [sp, #0x14]
	ldr r0, [r4, #0x54]
	add r1, sp, #0x10
	bl ov96_021EB588
	ldr r0, [r4, #0x54]
	add r1, r5, #1
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r4, #0x54]
	add r2, r1, #0
	bl ov96_021EB52C
	mov r1, #0x13
	ldr r0, [r4, #0x54]
	sub r1, r1, r5
	bl ov96_021EB630
	add r0, r7, #0
	mov r1, #0x65
	mov r2, #5
	bl ov96_021EB4F4
	str r0, [r4, #0x60]
	mov r1, #0
	bl ov96_021EB564
	mov r0, #1
	ldr r1, [sp, #0x14]
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x14]
	ldr r0, [r4, #0x60]
	add r1, sp, #0x10
	bl ov96_021EB588
	ldr r0, [r4, #0x60]
	mov r1, #4
	bl ov96_021EB630
	ldr r0, [sp, #0xc]
	add r5, r5, #1
	add r0, #0x32
	add r6, #0x10
	add r4, r4, #4
	str r0, [sp, #0xc]
	cmp r5, #3
	blt _02203E5E
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	bl ov96_02203DCC
	ldr r1, [sp, #4]
	add r0, r7, #0
	bl ov96_02203F50
	ldr r0, [sp, #4]
	bl ov96_02203F0C
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_02203E30


	thumb_func_start ov96_02203F0C
ov96_02203F0C: ; 0x02203F0C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r4, #0
_02203F12:
	lsl r0, r4, #3
	add r5, r6, r0
	mov r1, #0x32
	ldr r0, [r5, #0x24]
	lsl r1, r1, #6
	bl DC_FlushRange
	lsl r0, r4, #2
	add r7, r6, r0
	mov r2, #0x32
	ldr r0, [r5, #0x24]
	ldr r1, [r7, #0x3c]
	lsl r2, r2, #6
	bl GXS_LoadOBJ
	ldr r0, [r5, #0x28]
	mov r1, #0x20
	bl DC_FlushRange
	ldr r0, [r5, #0x28]
	ldr r1, [r7, #0x48]
	mov r2, #0x20
	bl GXS_LoadOBJPltt
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _02203F12
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02203F0C


	thumb_func_start ov96_02203F50
ov96_02203F50: ; 0x02203F50
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	mov r1, #0x65
	mov r2, #0
	add r5, r0, #0
	bl ov96_021EB5EC
	ldr r4, [r0]
	add r0, r5, #0
	mov r1, #0x65
	mov r2, #1
	bl ov96_021EB5EC
	ldr r5, [r0]
	add r0, r4, #0
	bl SpriteTransfer_GetCharProxy
	add r7, r0, #0
	add r0, r5, #0
	add r1, r7, #0
	bl SpriteTransfer_GetPaletteProxy
	str r0, [sp]
	mov r4, #0
_02203F80:
	lsl r0, r4, #2
	add r5, r6, r0
	add r0, r7, #0
	mov r1, #2
	bl NNS_G2dGetImageLocation
	mov r1, #0xd
	lsl r1, r1, #8
	add r2, r4, #0
	mul r2, r1
	mov r1, #3
	lsl r1, r1, #8
	add r1, r2, r1
	add r0, r1, r0
	str r0, [r5, #0x3c]
	ldr r0, [sp]
	mov r1, #2
	bl NNS_G2dGetImagePaletteLocation
	lsl r1, r4, #5
	add r1, #0x20
	add r0, r1, r0
	str r0, [r5, #0x48]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _02203F80
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02203F50


	thumb_func_start ov96_02203FBC
ov96_02203FBC: ; 0x02203FBC
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r1, r4, #0
	ldr r0, [r4, #8]
	ldr r2, _02203FF8 ; =ov96_0221CA28
	add r1, #0xc
	bl AddWindow
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #8]
	mov r1, #4
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r4]
	mov r0, #4
	lsl r1, r1, #4
	bl LoadFontPal0
	add r4, #0xc
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add sp, #4
	pop {r3, r4, pc}
	nop
_02203FF8: .word ov96_0221CA28
	thumb_func_end ov96_02203FBC


	thumb_func_start ov96_02203FFC
ov96_02203FFC: ; 0x02203FFC
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #4]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [r5, #4]
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r5]
	bl PlayerProfile_GetPlayerName_NewString
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02204048 ; =0x000F0E00
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0xc
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add r5, #0xc
	add r0, r5, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_02204048: .word 0x000F0E00
	thumb_func_end ov96_02203FFC


	thumb_func_start ov96_0220404C
ov96_0220404C: ; 0x0220404C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r6, r1, #0
	add r5, r2, #0
	add r4, r3, #0
	bl _fflt
	str r0, [sp, #0x10]
	add r0, r6, #0
	bl _fflt
	add r6, r0, #0
	bl _f2d
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _02204104 ; =0x40140000
	mov r0, #0
	bl _dmul
	ldr r3, _02204108 ; =0x404A0000
	mov r2, #0
	bl _ddiv
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _0220410C ; =0x9D89D89E
	ldr r1, _02204110 ; =0x403689D8
	bl _dadd
	bl _d2f
	add r7, r0, #0
	ldr r0, [sp, #0x10]
	bl _f2d
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _02204114 ; =0xCCCCCCCD
	ldr r1, _02204118 ; =0x3FC8CCCC
	bl _dmul
	str r0, [sp, #0x14]
	add r0, r6, #0
	str r1, [sp, #4]
	bl _f2d
	ldr r3, _0220411C ; =0x40200000
	mov r2, #0
	bl _ddiv
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #4]
	bl _dadd
	ldr r3, _02204120 ; =0x402F0000
	mov r2, #0
	bl _dsub
	ldr r3, _02204124 ; =0x40240000
	mov r2, #0
	bl _dsub
	str r0, [sp, #0x18]
	add r0, r6, #0
	str r1, [sp, #0xc]
	bl _f2d
	ldr r3, _02204128 ; =0x40800000
	mov r2, #0
	bl _ddiv
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _0220412C ; =0xF4DE9BD3
	ldr r1, _02204130 ; =0x3FD937A6
	bl _dadd
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0xc]
	bl _ddiv
	bl _d2f
	str r7, [r4]
	str r0, [r5]
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02204104: .word 0x40140000
_02204108: .word 0x404A0000
_0220410C: .word 0x9D89D89E
_02204110: .word 0x403689D8
_02204114: .word 0xCCCCCCCD
_02204118: .word 0x3FC8CCCC
_0220411C: .word 0x40200000
_02204120: .word 0x402F0000
_02204124: .word 0x40240000
_02204128: .word 0x40800000
_0220412C: .word 0xF4DE9BD3
_02204130: .word 0x3FD937A6
	thumb_func_end ov96_0220404C


	thumb_func_start ov96_02204134
ov96_02204134: ; 0x02204134
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #0
	str r2, [sp]
	add r6, r3, #0
	bl _f2d
	ldr r3, _022042E8 ; =0x404C8000
	mov r2, #0
	bl _dsub
	str r0, [sp, #0x1c]
	add r0, r4, #0
	add r7, r1, #0
	bl _f2d
	ldr r3, _022042E8 ; =0x404C8000
	mov r2, #0
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x1c]
	add r1, r7, #0
	bl _dmul
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _022042EC ; =0x3FF00000
	mov r0, #0
	bl _dadd
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _022042F0 ; =0x40100000
	mov r0, #0
	bl _ddiv
	str r0, [sp, #0x20]
	str r1, [sp, #0x18]
	add r0, r4, #0
	add r1, r4, #0
	bl _fmul
	add r1, r0, #0
	add r0, r4, #0
	bl _fmul
	bl _f2d
	ldr r3, _022042F4 ; =0x40BDB000
	mov r2, #0
	bl _ddiv
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _022042F8 ; =0x40260000
	mov r0, #0
	bl _dadd
	str r0, [sp, #0x24]
	str r1, [sp, #0x10]
	add r0, r4, #0
	bl _f2d
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _022042FC ; =0x40380000
	mov r0, #0
	bl _dsub
	str r0, [sp, #0x28]
	add r0, r4, #0
	str r1, [sp, #8]
	bl _f2d
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _022042FC ; =0x40380000
	mov r0, #0
	bl _dsub
	str r0, [sp, #0x2c]
	add r0, r4, #0
	add r7, r1, #0
	bl _f2d
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _022042FC ; =0x40380000
	mov r0, #0
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x2c]
	add r1, r7, #0
	bl _dmul
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #8]
	bl _dmul
	ldr r3, _02204300 ; =0x40B13000
	mov r2, #0
	bl _ddiv
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x10]
	bl _dsub
	ldr r3, _022042EC ; =0x3FF00000
	mov r2, #0
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x18]
	bl _dadd
	bl _d2f
	bl _f2d
	ldr r3, _02204304 ; =0x40200000
	mov r2, #0
	bl _dmul
	bl _d2f
	add r4, r0, #0
	bl _ffix
	str r0, [r6]
	add r0, r5, #0
	bl _f2d
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _02204308 ; =0x590B2164
	ldr r1, _0220430C ; =0x3FD642C8
	bl _dmul
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _02204310 ; =0x40240000
	mov r0, #0
	bl _dadd
	str r0, [sp, #0x30]
	add r0, r4, #0
	add r7, r1, #0
	bl _f2d
	ldr r3, _02204304 ; =0x40200000
	mov r2, #0
	bl _ddiv
	ldr r3, _02204310 ; =0x40240000
	mov r2, #0
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _02204314 ; =0x4A5294A5
	ldr r1, _02204318 ; =0x3FE4A529
	bl _dmul
	add r6, r0, #0
	add r0, r5, #0
	add r4, r1, #0
	bl _f2d
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _0220431C ; =0x40500000
	mov r0, #0
	bl _dsub
	add r2, r0, #0
	add r3, r1, #0
	add r0, r6, #0
	add r1, r4, #0
	bl _dmul
	ldr r3, _0220431C ; =0x40500000
	mov r2, #0
	bl _ddiv
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, [sp, #0x30]
	add r1, r7, #0
	bl _dsub
	bl _d2f
	bl _f2d
	ldr r3, _02204304 ; =0x40200000
	mov r2, #0
	bl _dmul
	bl _d2f
	bl _ffix
	ldr r1, [sp]
	str r0, [r1]
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022042E8: .word 0x404C8000
_022042EC: .word 0x3FF00000
_022042F0: .word 0x40100000
_022042F4: .word 0x40BDB000
_022042F8: .word 0x40260000
_022042FC: .word 0x40380000
_02204300: .word 0x40B13000
_02204304: .word 0x40200000
_02204308: .word 0x590B2164
_0220430C: .word 0x3FD642C8
_02204310: .word 0x40240000
_02204314: .word 0x4A5294A5
_02204318: .word 0x3FE4A529
_0220431C: .word 0x40500000
	thumb_func_end ov96_02204134


	thumb_func_start ov96_02204320
ov96_02204320: ; 0x02204320
	push {r3, r4, r5, lr}
	sub sp, #0x30
	add r5, r0, #0
	add r4, r1, #0
	bl LCRandom
	lsl r1, r5, #1
	bl _s32_div_f
	sub r1, r5, r1
	mov r0, #0xb6
	mul r0, r1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r2, r0, #1
	lsl r1, r2, #1
	ldr r3, _02204360 ; =FX_SinCosTable_
	add r2, r2, #1
	lsl r2, r2, #1
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	add r0, sp, #0
	bl MTX_RotY43_
	add r0, r4, #0
	add r1, sp, #0
	add r2, r4, #0
	bl MTX_MultVec43
	add sp, #0x30
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02204360: .word FX_SinCosTable_
	thumb_func_end ov96_02204320


	thumb_func_start ov96_02204364
ov96_02204364: ; 0x02204364
	push {r3, r4, r5, lr}
	add r5, r1, #0
	mov r1, #0xcc
	bl Heap_Alloc
	add r4, r0, #0
	mov r1, #0
	mov r2, #0xcc
	bl MI_CpuFill8
	add r0, r4, #0
	add r0, #0xc4
	strb r5, [r0]
	mov r0, #4
	sub r1, r0, r5
	add r0, r4, #0
	add r0, #0xc9
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0xc9
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0xc8
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #0x28
	add r0, #0xc7
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0xc7
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0xc6
	strb r1, [r0]
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02204364

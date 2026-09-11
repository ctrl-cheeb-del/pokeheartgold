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

	thumb_func_start ov96_022104D8
ov96_022104D8: ; 0x022104D8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r6, _02210534 ; =ov96_0221D17C
	add r7, r2, #0
	str r3, [sp]
	add r5, r0, #0
	add r4, r1, #0
	add r3, sp, #4
	mov r2, #6
_022104EA:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _022104EA
	ldr r0, [r6]
	cmp r5, #0
	str r0, [r3]
	bne _022104FE
	bl GF_AssertFail
_022104FE:
	cmp r4, #0
	bne _02210506
	bl GF_AssertFail
_02210506:
	add r1, sp, #4
	strh r7, [r1]
	ldr r0, [sp]
	mov r3, #0x1e
	strh r0, [r1, #2]
	add r0, sp, #0x40
	ldrh r2, [r0, #0x10]
	lsl r3, r3, #0x10
	strh r2, [r1, #6]
	ldrh r0, [r0, #0x14]
	add r1, r4, #0
	add r2, sp, #4
	str r0, [sp, #0xc]
	add r0, r5, #0
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	add r4, r0, #0
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02210534: .word ov96_0221D17C
	thumb_func_end ov96_022104D8


	thumb_func_start ov96_02210538
ov96_02210538: ; 0x02210538
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bne _02210542
	bl GF_AssertFail
_02210542:
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _0221054C
	bl GF_AssertFail
_0221054C:
	add r6, r5, #0
	ldr r7, _02210588 ; =ov96_0221D15C
	mov r4, #0
	add r6, #0x28
_02210554:
	lsl r1, r4, #4
	lsl r2, r4, #3
	ldr r0, [r5, #0x10]
	add r1, r6, r1
	add r2, r7, r2
	bl AddWindow
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _02210554
	mov r2, #0
	str r2, [sp]
	ldr r0, [r5, #0x10]
	mov r1, #7
	mov r3, #1
	bl BG_FillCharDataRange
	mov r1, #0x1e
	ldr r2, [r5, #4]
	mov r0, #4
	lsl r1, r1, #4
	bl LoadFontPal0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02210588: .word ov96_0221D15C
	thumb_func_end ov96_02210538


	thumb_func_start ov96_0221058C
ov96_0221058C: ; 0x0221058C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r6, r1, #0
	add r5, r0, #0
	add r0, r6, #0
	mov r1, #0x64
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
	mov r0, #0x64
	mul r0, r4
	sub r0, r6, r0
	mov r1, #0xa
	bl _s32_div_f
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
	add r0, r6, #0
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
	mov r6, #4
	mov r7, #8
_02210616:
	str r6, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x24]
	lsl r2, r4, #0x1a
	add r0, #0xc
	str r0, [sp, #8]
	add r0, sp, #0x1c
	add r0, #3
	ldrb r0, [r0, r4]
	mov r1, #6
	lsr r2, r2, #0x18
	str r0, [sp, #0xc]
	add r0, sp, #0x1c
	ldrb r0, [r0, r4]
	mov r3, #0
	str r0, [sp, #0x10]
	mov r0, #0x14
	str r0, [sp, #0x14]
	mov r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x10]
	bl CopyRectToBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _02210616
	ldr r0, [r5, #0x10]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221058C


	thumb_func_start ov96_0221065C
ov96_0221065C: ; 0x0221065C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	mov r6, #0
	mov r4, #0xe6
	add r5, r7, #0
_02210668:
	add r0, r6, #0
	add r0, #9
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	lsl r2, r4, #0x10
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	asr r2, r2, #0x10
	mov r3, #0x4c
	bl ov96_022104D8
	mov r1, #1
	str r0, [r5, #0x6c]
	bl ManagedSprite_SetPaletteOverride
	add r6, r6, #1
	add r4, #0x10
	add r5, r5, #4
	cmp r6, #2
	blt _02210668
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221065C


	thumb_func_start ov96_0221069C
ov96_0221069C: ; 0x0221069C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	ldr r0, _02210750 ; =0x00000000
	str r0, [sp, #0x1c]
	bne _022106AC
	bl GF_AssertFail
_022106AC:
	add r6, r5, #0
	mov r4, #0
	str r5, [sp, #0x10]
	add r6, #0x28
_022106B4:
	ldrb r0, [r5, #0x1c]
	cmp r4, r0
	bne _022106C6
	mov r0, #8
	str r0, [sp, #0x18]
	mov r0, #0x48
	mov r7, #0
	str r0, [sp, #0x14]
	b _022106E4
_022106C6:
	ldr r0, [sp, #0x1c]
	ldr r1, _02210754 ; =ov96_0221D14C
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x1c]
	ldr r2, _02210754 ; =ov96_0221D14C
	lsl r0, r0, #2
	add r1, r1, r0
	ldrsh r0, [r2, r0]
	str r0, [sp, #0x18]
	mov r0, #2
	ldrsh r0, [r1, r0]
	str r0, [sp, #0x14]
	str r7, [sp, #0x1c]
_022106E4:
	ldr r0, [r5]
	add r1, r4, #0
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r5, #4]
	bl PlayerProfile_GetPlayerName_NewString
	lsl r7, r7, #4
	str r0, [sp, #0x20]
	add r0, r6, r7
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02210758 ; =0x000F0E00
	mov r1, #0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r2, [sp, #0x20]
	add r0, r6, r7
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, r7
	bl CopyWindowToVram
	ldr r0, [sp, #0x20]
	bl String_Delete
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #0x41
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x14]
	bl ov96_022104D8
	ldr r1, [sp, #0x10]
	add r4, r4, #1
	str r0, [r1, #0x74]
	add r0, r1, #0
	add r0, r0, #4
	str r0, [sp, #0x10]
	cmp r4, #4
	blt _022106B4
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02210750: .word 0x00000000
_02210754: .word ov96_0221D14C
_02210758: .word 0x000F0E00
	thumb_func_end ov96_0221069C


	thumb_func_start ov96_0221075C
ov96_0221075C: ; 0x0221075C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	mov r0, #0
	str r0, [sp, #0x10]
	mov r0, #8
	mov r7, #7
	str r0, [sp, #0xc]
_0221076C:
	ldr r0, [sp, #0x10]
	mov r4, #0
	add r0, r0, #4
	lsl r0, r0, #3
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp, #0x14]
_0221077E:
	add r0, r4, r7
	cmp r4, #0
	bne _02210788
	mov r2, #1
	b _0221078C
_02210788:
	mov r2, #0
	mvn r2, r2
_0221078C:
	ldr r1, [sp, #8]
	lsl r0, r0, #2
	mul r2, r1
	mov r1, #0x80
	add r6, r5, r0
	mov r0, #0x14
	add r1, r1, r2
	str r0, [sp]
	mov r0, #0x40
	lsl r1, r1, #0x10
	str r0, [sp, #4]
	asr r2, r1, #0x10
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r3, [sp, #0x14]
	bl ov96_022104D8
	mov r1, #3
	str r0, [r6, #0x68]
	bl ManagedSprite_SetPriority
	add r4, r4, #1
	cmp r4, #2
	blt _0221077E
	ldr r0, [sp, #0xc]
	add r7, r7, #2
	add r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #0xc
	blt _0221076C
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221075C


	thumb_func_start ov96_022107D4
ov96_022107D4: ; 0x022107D4
	push {r4, r5, r6, lr}
	mov r4, #0
	add r5, r0, #0
	add r6, r4, #0
_022107DC:
	ldr r0, [r5, #0x68]
	add r1, r6, #0
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0x1f
	blt _022107DC
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_022107D4


	thumb_func_start ov96_022107F0
ov96_022107F0: ; 0x022107F0
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	str r0, [sp]
	bl PokeathlonCourse_GetParticipantCount
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0xc0
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0xc0
	add r7, r0, #0
	bl MI_CpuFill8
	str r4, [r7]
	ldr r0, [sp]
	mov r4, #0
	str r0, [r7, #4]
	mov r0, #4
	sub r1, r0, r5
	add r0, r7, #0
	add r0, #0xbc
	strb r1, [r0]
	add r0, r7, #0
	add r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	ble _0221084A
	add r6, r7, #0
	add r6, #8
_0221082E:
	lsl r1, r5, #0x18
	ldr r2, [sp]
	add r0, r6, #0
	lsr r1, r1, #0x18
	bl ov96_022108BC
	add r0, r7, #0
	add r0, #0xbc
	ldrb r0, [r0]
	add r4, r4, #1
	add r5, r5, #1
	add r6, #0x3c
	cmp r4, r0
	blt _0221082E
_0221084A:
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_022107F0

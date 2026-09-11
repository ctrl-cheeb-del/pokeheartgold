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

	thumb_func_start ov96_022193F8
ov96_022193F8: ; 0x022193F8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r1, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r5, [r4, #0x10]
	ldr r6, [r4, #0x14]
	add r0, #0x20
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, r7, #0
	mov r3, #3
	bl BufferIntegerAsString
	ldr r3, [r4]
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #0xa3
	bl ReadMsgData_ExpandPlaceholders
	add r5, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0221945C ; =0x000F0E00
	mov r1, #4
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #0x20
	add r2, r5, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl String_Delete
	add r4, #0x20
	add r0, r4, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221945C: .word 0x000F0E00
	thumb_func_end ov96_022193F8


	thumb_func_start ov96_02219460
ov96_02219460: ; 0x02219460
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	ldr r1, [r0, #4]
	add r4, r0, #0
	ldr r1, [r1, #8]
	add r7, r2, #0
	asr r1, r1, #0xc
	add r4, #0x5f
	cmp r1, #0x1e
	bge _02219478
	mov r5, #1
	b _0221947A
_02219478:
	mov r5, #0
_0221947A:
	bl ov96_0221862C
	cmp r0, #0
	beq _0221948E
	cmp r5, #0
	beq _0221948A
	mov r0, #1
	b _02219490
_0221948A:
	mov r0, #0
	b _02219490
_0221948E:
	mov r0, #3
_02219490:
	cmp r7, #0
	bne _02219498
	strb r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_02219498:
	ldr r1, [r6]
	lsl r2, r1, #0x11
	lsr r2, r2, #0x1f
	beq _022194BA
	cmp r0, #1
	bhi _022194AA
	mov r0, #2
	strb r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_022194AA:
	cmp r0, #3
	bne _022194B4
	mov r0, #4
	strb r0, [r4]
	pop {r3, r4, r5, r6, r7, pc}
_022194B4:
	bl GF_AssertFail
	pop {r3, r4, r5, r6, r7, pc}
_022194BA:
	lsl r1, r1, #0x10
	lsr r1, r1, #0x1f
	bne _022194C2
	strb r0, [r4]
_022194C2:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02219460


	thumb_func_start ov96_022194C4
ov96_022194C4: ; 0x022194C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #0x10]
	cmp r5, #0
	bne _022194D8
	bl GF_AssertFail
_022194D8:
	cmp r6, #0
	bne _022194E0
	bl GF_AssertFail
_022194E0:
	cmp r7, #0
	bne _022194E8
	bl GF_AssertFail
_022194E8:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	bne _022194F2
	bl GF_AssertFail
_022194F2:
	ldr r0, [sp, #0x28]
	cmp r0, #0
	bne _022194FC
	bl GF_AssertFail
_022194FC:
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	bne _02219506
	bl GF_AssertFail
_02219506:
	ldr r0, [sp, #0x34]
	mov r1, #0xc8
	bl Heap_Alloc
	add r4, r0, #0
	mov r1, #0
	mov r2, #0xc8
	bl MI_CpuFill8
	str r5, [r4, #8]
	str r6, [r4, #0xc]
	str r7, [r4, #0x10]
	add r0, sp, #0x18
	ldrb r1, [r0, #0x18]
	add r0, r4, #0
	add r0, #0x22
	strb r1, [r0]
	ldr r0, [sp, #0x34]
	str r0, [r4, #4]
	ldr r0, [sp, #0x10]
	str r0, [r4, #0x14]
	ldr r0, [sp, #0x28]
	str r0, [r4, #0x18]
	ldr r0, [sp, #0x2c]
	str r0, [r4, #0x1c]
	ldr r0, [sp, #0x38]
	str r0, [r4]
	ldr r1, [r4, #4]
	mov r0, #0x14
	bl NARC_New
	str r0, [r4, #0x24]
	ldr r0, [r4, #4]
	add r3, r4, #0
	str r0, [sp]
	mov r0, #0xf2
	mov r1, #7
	mov r2, #1
	add r3, #0x2c
	bl GfGfxLoader_GetScrnData
	str r0, [r4, #0x28]
	bl sub_02074490
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, _022195C4 ; =0x00002714
	add r1, r6, #0
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r2, #0x14
	bl SpriteSystem_LoadPlttResObj
	strh r0, [r4, #0x20]
	ldr r0, [sp, #0x38]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp, #0x38]
	bl PokeathlonCourse_GetParticipantUnk04
	add r6, r0, #0
	mov r7, #0
	add r5, r4, #0
_02219590:
	ldr r1, [r4, #4]
	mov r0, #0xb
	bl String_New
	add r1, r5, #0
	add r1, #0xb0
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xb0
	add r1, r6, #0
	ldr r0, [r0]
	add r1, #0x12
	bl CopyU16ArrayToString
	add r7, r7, #1
	add r5, r5, #4
	add r6, #0x28
	cmp r7, #3
	blt _02219590
	add r0, r4, #0
	bl ov96_02219A08
	add r0, r4, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_022195C4: .word 0x00002714
	thumb_func_end ov96_022194C4


	thumb_func_start ov96_022195C8
ov96_022195C8: ; 0x022195C8
	push {r4, lr}
	add r4, r0, #0
	bl ov96_02219C30
	add r0, r4, #0
	mov r1, #0x3c
	bl ov96_022196E4
	add r0, r4, #0
	mov r1, #0
	bl ov96_02219A5C
	add r0, r4, #0
	bl ov96_02219B30
	pop {r4, pc}
	thumb_func_end ov96_022195C8


	thumb_func_start ov96_022195E8
ov96_022195E8: ; 0x022195E8
	push {r4, r5, r6, lr}
	add r6, r0, #0
	bne _022195F2
	bl GF_AssertFail
_022195F2:
	ldr r0, [r6, #0x24]
	bl NARC_Delete
	mov r4, #0
	add r5, r6, #0
_022195FC:
	add r0, r5, #0
	add r0, #0xb0
	ldr r0, [r0]
	bl String_Delete
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _022195FC
	ldr r0, [r6, #0x28]
	bl Heap_Free
	add r4, r6, #0
	mov r5, #0
	add r4, #0x30
_0221961A:
	add r0, r4, #0
	bl RemoveWindow
	add r5, r5, #1
	add r4, #0x10
	cmp r5, #3
	blt _0221961A
	mov r5, #0
	add r4, r6, #0
_0221962C:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	bne _02219636
	bl GF_AssertFail
_02219636:
	ldr r0, [r4, #0x60]
	bl Sprite_DeleteAndFreeResources
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #0x12
	blt _0221962C
	add r0, r6, #0
	bl Heap_Free
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_022195E8


	thumb_func_start ov96_0221964C
ov96_0221964C: ; 0x0221964C
	push {r4, r5, r6, lr}
	mov r4, #0
	add r5, r0, #0
	add r6, r4, #0
_02219654:
	add r0, r5, #0
	add r0, #0xa0
	ldr r0, [r0]
	add r1, r6, #0
	bl ManagedSprite_SetAnimateFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _02219654
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_0221964C


	thumb_func_start ov96_0221966C
ov96_0221966C: ; 0x0221966C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r1, [sp]
	add r6, r0, #0
	add r5, r3, #0
	str r2, [sp, #4]
	cmp r6, #0
	bne _02219680
	bl GF_AssertFail
_02219680:
	ldr r0, [sp]
	cmp r0, #4
	blo _0221968A
	bl GF_AssertFail
_0221968A:
	mov r7, #0
	add r4, r7, #0
_0221968E:
	ldrb r0, [r5, #1]
	add r1, r7, #6
	lsl r0, r0, #2
	add r0, r6, r0
	add r0, #0x88
	ldr r0, [r0]
	bl ManagedSprite_SetAnimNoRestart
	cmp r4, #3
	beq _022196AC
	ldrb r1, [r5]
	ldrb r0, [r5, #2]
	cmp r1, r0
	beq _022196AC
	add r7, r4, #1
_022196AC:
	add r4, r4, #1
	add r5, r5, #2
	cmp r4, #4
	blt _0221968E
	ldr r0, [r6]
	bl ov96_021E5F24
	ldr r1, [sp]
	cmp r1, r0
	bne _022196DE
	add r0, r6, #0
	add r0, #0xc2
	ldrh r1, [r0]
	ldr r0, [sp, #4]
	cmp r0, r1
	beq _022196DE
	ldr r1, [sp, #4]
	add r0, r6, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02219A5C
	ldr r0, [sp, #4]
	add r6, #0xc2
	strh r0, [r6]
_022196DE:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221966C


	thumb_func_start ov96_022196E4
ov96_022196E4: ; 0x022196E4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r1, #0
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #0x64
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r5, r0, #0x18
	add r0, r5, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	cmp r4, #0xa
	blt _0221971C
	cmp r4, #0x37
	ble _02219720
_0221971C:
	mov r1, #1
	b _02219722
_02219720:
	mov r1, #0
_02219722:
	add r0, r6, #0
	add r0, #0xc4
	str r1, [r0]
	mov r4, #0
	add r5, r6, #0
	mov r7, #1
_0221972E:
	add r0, r6, #0
	add r0, #0xc4
	ldr r0, [r0]
	cmp r0, #0
	bne _0221973C
	add r1, r7, #0
	b _0221973E
_0221973C:
	mov r1, #0
_0221973E:
	add r0, r5, #0
	add r0, #0x88
	ldr r0, [r0]
	bl ManagedSprite_SetDrawFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0221972E
	add r0, r6, #0
	add r0, #0xa8
	ldr r1, [sp, #4]
	ldr r0, [r0]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r6, #0xac
	ldr r1, [sp]
	ldr r0, [r6]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_022196E4


	thumb_func_start ov96_02219770
ov96_02219770: ; 0x02219770
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, #0xa0
	ldr r0, [r0]
	add r4, r2, #0
	bl ManagedSprite_SetDrawFlag
	add r5, #0xa4
	ldr r0, [r5]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_02219770

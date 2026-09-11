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

	thumb_func_start ov96_02200BD8
ov96_02200BD8: ; 0x02200BD8
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r5, r1, #0
	add r0, #0xc
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #1
	lsl r2, r5, #2
	add r5, r4, r2
	mov r2, #0x17
	str r0, [sp]
	mov r3, #2
	str r3, [sp, #4]
	lsl r2, r2, #4
	ldr r0, [r4, #0x30]
	ldr r2, [r5, r2]
	mov r1, #0
	bl BufferString
	ldr r0, [r4, #0x30]
	ldr r1, [r4, #0x2c]
	ldr r3, [r4]
	mov r2, #0x9a
	bl ReadMsgData_ExpandPlaceholders
	mov r1, #0
	add r5, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02200C3C ; =0x000F0E00
	add r2, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #0xc
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl String_Delete
	add r4, #0xc
	add r0, r4, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02200C3C: .word 0x000F0E00
	thumb_func_end ov96_02200BD8


	thumb_func_start ov96_02200C40
ov96_02200C40: ; 0x02200C40
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r0, #0x1c
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r5, #0x2c]
	ldr r1, _02200C84 ; =0x00000131
	bl NewString_ReadMsgData
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _02200C88 ; =0x000F0E00
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x1c
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add r5, #0x1c
	add r0, r5, #0
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02200C84: .word 0x00000131
_02200C88: .word 0x000F0E00
	thumb_func_end ov96_02200C40


	thumb_func_start ov96_02200C8C
ov96_02200C8C: ; 0x02200C8C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #4]
	ldr r0, _02200D78 ; =ov96_0221C728
	str r1, [sp, #8]
	ldr r2, [r0]
	ldr r1, [r0, #4]
	str r2, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, [r0, #8]
	ldr r0, [r0, #0xc]
	add r5, sp, #0x14
	add r4, sp, #0xc
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r6, #0
	mov r7, #3
_02200CAE:
	ldr r0, [r4]
	add r1, r7, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r3, [r5]
	ldr r0, [sp, #4]
	lsl r3, r3, #0x18
	mov r2, #2
	lsr r3, r3, #0x18
	bl ov96_021EB408
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r6, #2
	blt _02200CAE
	ldr r4, [sp, #8]
	mov r5, #0
	add r7, sp, #0xc
	add r6, sp, #0x14
_02200CD8:
	ldr r1, [r6]
	ldr r2, [r7]
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_021EB4F4
	mov r1, #0x15
	lsl r1, r1, #4
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	bl ov96_021EB5B8
	mov r1, #0
	str r1, [sp, #0x24]
	mov r1, #0xa
	lsl r1, r1, #0xe
	str r1, [sp, #0x1c]
	mov r1, #1
	sub r2, r1, r5
	mov r1, #0x58
	mul r1, r2
	add r1, #0x30
	lsl r2, r1, #0xc
	mov r1, #2
	lsl r1, r1, #0x14
	add r1, r2, r1
	str r1, [sp, #0x20]
	add r1, sp, #0x1c
	bl Sprite_SetMatrix
	mov r0, #0x15
	lsl r0, r0, #4
	mov r1, #1
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [sp, #4]
	mov r1, #0x65
	mov r2, #0x10
	bl ov96_021EB4F4
	mov r1, #0x56
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	mov r1, #8
	bl ov96_021EB564
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x1c
	bl ov96_021EB588
	mov r0, #0x56
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	add r5, r5, #1
	add r7, r7, #4
	add r6, r6, #4
	add r4, r4, #4
	cmp r5, #2
	blt _02200CD8
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	bl ov96_02200D7C
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02200D78: .word ov96_0221C728
	thumb_func_end ov96_02200C8C


	thumb_func_start ov96_02200D7C
ov96_02200D7C: ; 0x02200D7C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r7, r0, #0
	ldr r0, _02200DF4 ; =ov96_0221C728
	str r1, [sp]
	ldr r1, [r0, #0x18]
	ldr r0, [r0, #0x1c]
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r4, #0
_02200D90:
	lsl r0, r4, #2
	add r1, sp, #0xc
	ldr r5, [r1, r0]
	str r0, [sp, #4]
	add r0, r7, #0
	add r1, r5, #0
	mov r2, #0
	bl ov96_021EB5EC
	ldr r6, [r0]
	add r0, r7, #0
	add r1, r5, #0
	mov r2, #1
	bl ov96_021EB5EC
	ldr r5, [r0]
	add r0, r6, #0
	bl SpriteTransfer_GetCharProxy
	add r6, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	bl SpriteTransfer_GetPaletteProxy
	str r0, [sp, #8]
	ldr r1, [sp]
	ldr r0, [sp, #4]
	add r5, r1, r0
	add r0, r6, #0
	mov r1, #2
	bl NNS_G2dGetImageLocation
	mov r1, #5
	lsl r1, r1, #6
	str r0, [r5, r1]
	ldr r0, [sp, #8]
	mov r1, #2
	bl NNS_G2dGetImagePaletteLocation
	mov r1, #0x52
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _02200D90
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_02200DF4: .word ov96_0221C728
	thumb_func_end ov96_02200D7C


	thumb_func_start ov96_02200DF8
ov96_02200DF8: ; 0x02200DF8
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r1, r4, #0
	ldr r0, [r4, #8]
	ldr r2, _02200E34 ; =ov96_0221C760
	add r1, #0xc
	bl AddWindow
	add r1, r4, #0
	ldr r0, [r4, #8]
	ldr r2, _02200E38 ; =ov96_0221C768
	add r1, #0x1c
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
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02200E34: .word ov96_0221C760
_02200E38: .word ov96_0221C768
	thumb_func_end ov96_02200DF8


	thumb_func_start ov96_02200E3C
ov96_02200E3C: ; 0x02200E3C
	push {r3, r4, r5, lr}
	add r5, r1, #0
	mov r1, #0xfa
	lsl r1, r1, #2
	bl Heap_Alloc
	mov r2, #0xfa
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x3e
	lsl r0, r0, #4
	mov r1, #4
	sub r2, r1, r5
	strb r5, [r4, r0]
	add r1, r0, #5
	strb r2, [r4, r1]
	ldrb r2, [r4, r1]
	add r1, r0, #4
	strb r2, [r4, r1]
	add r1, r0, #3
	mov r2, #0xa
	strb r2, [r4, r1]
	ldrb r1, [r4, r1]
	add r0, r0, #2
	strb r1, [r4, r0]
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02200E3C

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

	thumb_func_start ov96_021F480C
ov96_021F480C: ; 0x021F480C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #1
	add r7, r1, #0
	add r1, r0, #0
	bl GfGfx_EngineBTogglePlanes
	mov r4, #0
	mov r6, #1
_021F4820:
	lsl r0, r4, #2
	add r0, r5, r0
	add r0, #0xbc
	ldr r0, [r0]
	add r1, r6, #0
	add r2, r6, #0
	bl ov96_021EB52C
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _021F4820
	mov r4, #0
	mov r6, #1
_021F483E:
	lsl r0, r4, #2
	add r0, r5, r0
	add r0, #0xc8
	ldr r0, [r0]
	add r1, r6, #0
	add r2, r6, #0
	bl ov96_021EB52C
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021F483E
	add r0, r5, #0
	add r0, #0xa4
	ldr r3, [r0]
	add r0, r7, #0
	add r2, r3, #0
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	add r0, r5, #0
	add r1, r7, #0
	bl ov96_021F4EF8
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #3
	mov r2, #0
	str r0, [sp, #8]
	add r0, r7, #0
	mov r1, #6
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	add r0, r7, #0
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _021F48A4 ; =ov96_021F4A9C
	str r0, [r5, #0x14]
	mov r0, #1
	str r0, [r5, #0x1c]
	str r0, [r5]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021F48A4: .word ov96_021F4A9C
	thumb_func_end ov96_021F480C
	thumb_func_start ov96_021F48A8
ov96_021F48A8: ; 0x021F48A8
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r1, #0
	add r5, r0, #0
	add r1, r2, #0
	bl ov96_021F4E5C
	add r0, r5, #0
	add r0, #0xac
	ldr r3, [r0]
	add r0, r4, #0
	add r2, r3, #0
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	mov r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #3
	mov r2, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #6
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	add r0, r4, #0
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _021F48F8 ; =ov96_021F4AE0
	str r0, [r5, #0x14]
	mov r0, #2
	str r0, [r5, #0x1c]
	mov r0, #1
	str r0, [r5]
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_021F48F8: .word ov96_021F4AE0
	thumb_func_end ov96_021F48A8
	thumb_func_start ov96_021F48FC
ov96_021F48FC: ; 0x021F48FC
	push {r4, r5, lr}
	sub sp, #0x1c
	add r5, r0, #0
	add r4, r1, #0
	bl ov96_021F4CAC
	mov r0, #0
	mov r1, #1
	lsl r1, r1, #0xc
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	bl OS_WaitVBlankIntr
	mov r0, #0x60
	str r0, [sp]
	add r0, r4, #0
	mov r1, #7
	add r2, sp, #0xc
	mov r3, #0x80
	bl SetBgAffine
	add r0, r5, #0
	add r0, #0xa8
	ldr r3, [r0]
	add r0, r4, #0
	add r2, r3, #0
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #3
	mov r2, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #6
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	add r0, r4, #0
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	add r0, #0x9c
	ldr r3, [r0]
	add r0, r4, #0
	add r2, r3, #0
	ldr r3, [r3, #8]
	mov r1, #7
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	add r0, r4, #0
	mov r1, #7
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _021F498C ; =ov96_021F4B34
	str r0, [r5, #0x14]
	mov r0, #3
	str r0, [r5, #0x1c]
	mov r0, #1
	str r0, [r5]
	add sp, #0x1c
	pop {r4, r5, pc}
	nop
_021F498C: .word ov96_021F4B34
	thumb_func_end ov96_021F48FC
	thumb_func_start ov96_021F4990
ov96_021F4990: ; 0x021F4990
	push {r3, r4, r5, lr}
	sub sp, #0x28
	add r5, r0, #0
	add r4, r1, #0
	add r1, sp, #0x1c
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	mov r0, #0xe
	lsl r0, r0, #0xe
	str r0, [sp, #0x1c]
	mov r0, #0x29
	lsl r0, r0, #0x10
	str r0, [sp, #0x20]
	add r0, r5, #0
	add r0, #0xc4
	ldr r0, [r0]
	bl ov96_021EB5B8
	add r1, sp, #0x1c
	bl Sprite_SetMatrix
	add r3, r5, #0
	add r2, r5, #0
	add r3, #0xa8
	add r2, #0xa0
	ldr r3, [r3]
	ldr r2, [r2]
	ldr r3, [r3, #8]
	add r0, r4, #0
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #3
	mov r2, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #6
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	add r0, r4, #0
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	add r0, #0x98
	ldr r3, [r0]
	add r0, r4, #0
	add r2, r3, #0
	ldr r3, [r3, #8]
	mov r1, #7
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	add r0, r4, #0
	mov r1, #7
	bl ScheduleBgTilemapBufferTransfer
	ldr r1, _021F4A54 ; =0x3CCCCCCD
	ldr r0, _021F4A58 ; =0x45800000
	bl _fmul
	bl _ffix
	mov r1, #0
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	bl OS_WaitVBlankIntr
	mov r0, #0x60
	str r0, [sp]
	add r0, r4, #0
	mov r1, #7
	add r2, sp, #0xc
	mov r3, #0x80
	bl SetBgAffine
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, _021F4A5C ; =ov96_021F4BB4
	str r0, [r5, #0x14]
	mov r0, #4
	str r0, [r5, #0x1c]
	mov r0, #1
	str r0, [r5]
	add sp, #0x28
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021F4A54: .word 0x3CCCCCCD
_021F4A58: .word 0x45800000
_021F4A5C: .word ov96_021F4BB4
	thumb_func_end ov96_021F4990

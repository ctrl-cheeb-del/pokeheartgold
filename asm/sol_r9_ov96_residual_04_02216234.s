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




	thumb_func_start ov96_02216234
ov96_02216234: ; 0x02216234
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	add r0, r6, #0
	bl PokeathlonCourse_GetDataCopyArea
	add r7, r0, #0
	bl ov96_021E8A20
	add r7, #0xf0
	add r5, r0, #0
	add r0, r7, #0
	bl ov96_021E8A20
	ldr r0, [r0, #0x20]
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _02216282
	ldr r0, _022162E0 ; =0x0000043C
	add r0, r4, r0
	bl ov96_02217820
	ldr r0, [r4, #0x1c]
	mov r1, #1
	bl ov96_021EB144
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl ov96_0221964C
	ldr r1, _022162E4 ; =ov96_02216200
	add r0, r6, #0
	bl ov96_021E8324
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02216282:
	bl System_GetTouchNew
	cmp r0, #0
	beq _022162A4
	add r0, r6, #0
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	lsl r1, r1, #0x18
	str r0, [sp]
	add r0, r6, #0
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl ov96_021E8228
_022162A4:
	bl System_GetTouchHeld
	cmp r0, #0
	beq _022162D4
	ldr r2, [r5]
	mov r0, #0xff
	ldr r1, _022162E8 ; =gSystem + 0x40
	bic r2, r0
	ldrh r0, [r1, #0x20]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	orr r2, r0
	ldr r0, _022162EC ; =0xFFFF00FF
	str r2, [r5]
	and r2, r0
	ldrh r0, [r1, #0x22]
	add r1, r2, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x10
	orr r1, r0
	mov r0, #1
	lsl r0, r0, #0x10
	orr r0, r1
	b _022162DA
_022162D4:
	ldr r1, [r5]
	ldr r0, _022162F0 ; =0xFFFEFFFF
	and r0, r1
_022162DA:
	str r0, [r5]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022162E0: .word 0x0000043C
_022162E4: .word ov96_02216200
_022162E8: .word gSystem + 0x40
_022162EC: .word 0xFFFF00FF
_022162F0: .word 0xFFFEFFFF
	thumb_func_end ov96_02216234



	thumb_func_start ov96_022162F4
ov96_022162F4: ; 0x022162F4
	push {r3, r4, lr}
	sub sp, #0x4c
	ldr r3, _02216380 ; =ov96_0221D720
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x34
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _02216384 ; =ov96_0221D754
	add r2, sp, #0x14
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _02216388 ; =ov96_0221D6F4
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	mov r0, #0x80
	str r0, [sp]
	ldr r0, [r4]
	bl SpriteSystem_Alloc
	str r0, [r4, #8]
	bl SpriteManager_New
	str r0, [r4, #0xc]
	ldr r0, [r4, #8]
	add r1, sp, #0x14
	add r2, sp, #0
	mov r3, #0x20
	bl SpriteSystem_Init
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	mov r2, #0x80
	bl SpriteSystem_InitSprites
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	add r2, sp, #0x34
	bl SpriteSystem_InitManagerWithCapacities
	ldr r0, [r4, #8]
	bl SpriteSystem_GetRenderer
	mov r2, #0x1e
	mov r1, #0
	lsl r2, r2, #0x10
	bl G2dRenderer_SetSubSurfaceCoords
	ldr r0, [r4]
	ldr r1, _0221638C ; =0x000002E7
	mov r2, #1
	bl ov96_021E9A78
	str r0, [r4, #0x18]
	add sp, #0x4c
	pop {r3, r4, pc}
	.balign 4, 0
_02216380: .word ov96_0221D720
_02216384: .word ov96_0221D754
_02216388: .word ov96_0221D6F4
_0221638C: .word 0x000002E7
	thumb_func_end ov96_022162F4

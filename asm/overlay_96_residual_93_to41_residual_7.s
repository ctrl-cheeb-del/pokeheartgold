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


	thumb_func_start ov96_0220A298
ov96_0220A298: ; 0x0220A298
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x4c]
	add r6, r1, #0
	bl ov96_0220B730
	mov r4, #0x99
	lsl r4, r4, #2
	bl System_GetTouchNew
	cmp r0, #0
	beq _0220A322
	add r0, sp, #0xc
	add r1, sp, #8
	bl System_GetTouchNewCoords
	mov r1, #0
	ldr r0, [sp, #0xc]
	add r2, r1, #0
	add r3, r1, #0
	cmp r0, #0x60
	blo _0220A2CC
	cmp r0, #0xb0
	bhi _0220A2CC
	mov r3, #1
_0220A2CC:
	cmp r3, #0
	beq _0220A2D8
	ldr r0, [sp, #8]
	cmp r0, #0x48
	blo _0220A2D8
	mov r2, #1
_0220A2D8:
	cmp r2, #0
	beq _0220A2E4
	ldr r0, [sp, #8]
	cmp r0, #0x98
	bhi _0220A2E4
	mov r1, #1
_0220A2E4:
	cmp r6, #0
	bne _0220A2EC
	cmp r1, #0
	beq _0220A3A2
_0220A2EC:
	ldr r1, [r5, r4]
	ldr r0, _0220A40C ; =0xFFFF00FF
	and r1, r0
	ldr r0, [sp, #8]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x10
	orr r0, r1
	str r0, [r5, r4]
	ldr r1, [r5, r4]
	ldr r0, _0220A410 ; =0xFF00FFFF
	and r1, r0
	ldr r0, [sp, #8]
	lsl r0, r0, #0x18
	lsr r0, r0, #8
	orr r0, r1
	str r0, [r5, r4]
	ldr r1, [r5, r4]
	mov r0, #0xff
	bic r1, r0
	mov r0, #1
	orr r1, r0
	str r1, [r5, r4]
	ldr r1, [r5, r4]
	lsl r0, r0, #0x18
	orr r0, r1
	str r0, [r5, r4]
	b _0220A3A2
_0220A322:
	ldr r0, [r5, r4]
	lsl r0, r0, #7
	lsr r0, r0, #0x1f
	beq _0220A35C
	bl System_GetTouchHeld
	cmp r0, #0
	bne _0220A35C
	ldr r0, [r5, r4]
	lsl r1, r0, #0x10
	lsl r0, r0, #8
	lsr r1, r1, #0x18
	lsr r0, r0, #0x18
	sub r0, r1, r0
	cmp r0, #0x20
	blt _0220A352
	ldr r0, [r5, #0x4c]
	bl ov96_0220B744
	cmp r0, #0
	beq _0220A352
	ldr r0, [r5, #0x4c]
	bl ov96_0220B6EC
_0220A352:
	ldr r1, [r5, r4]
	ldr r0, _0220A414 ; =0xFEFFFFFF
	and r0, r1
	str r0, [r5, r4]
	b _0220A3A2
_0220A35C:
	ldr r0, [r5, r4]
	lsl r0, r0, #7
	lsr r0, r0, #0x1f
	beq _0220A3A2
	add r0, sp, #4
	add r1, sp, #0
	bl System_GetTouchHeldCoords
	ldr r1, [r5, r4]
	ldr r0, _0220A410 ; =0xFF00FFFF
	and r1, r0
	ldr r0, [sp]
	lsl r0, r0, #0x18
	lsr r0, r0, #8
	orr r0, r1
	str r0, [r5, r4]
	ldr r2, [r5, r4]
	mov r1, #0xff
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	orr r0, r1
	str r0, [r5, r4]
	ldr r1, [r5, r4]
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	cmp r0, #0xa
	blo _0220A3A2
	ldr r0, _0220A414 ; =0xFEFFFFFF
	and r0, r1
	str r0, [r5, r4]
_0220A3A2:
	bl System_GetTouchNew
	cmp r0, #0
	bne _0220A3B2
	bl System_GetTouchHeld
	cmp r0, #0
	bgt _0220A408
_0220A3B2:
	ldr r0, _0220A418 ; =ov96_0221CC04
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	ldr r0, [r5, #0x4c]
	beq _0220A3E4
	bl ov96_0220B744
	cmp r0, #0
	beq _0220A3DA
	ldr r0, _0220A41C ; =0x0000089B
	mov r4, #0x14
	bl PlaySE
	ldr r0, [r5, #0x4c]
	bl ov96_0220B6EC
	b _0220A400
_0220A3DA:
	ldr r0, _0220A420 ; =0x0000089C
	mov r4, #0x16
	bl PlaySE
	b _0220A400
_0220A3E4:
	bl ov96_0220B744
	cmp r0, #0
	bne _0220A3F0
	mov r4, #0x15
	b _0220A400
_0220A3F0:
	ldr r0, [r5, #0x4c]
	bl ov96_0220B788
	cmp r0, #0
	beq _0220A3FE
	mov r4, #0x17
	b _0220A400
_0220A3FE:
	mov r4, #0x13
_0220A400:
	ldr r0, [r5, #0x28]
	add r1, r4, #0
	bl ManagedSprite_SetAnimNoRestart
_0220A408:
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0220A40C: .word 0xFFFF00FF
_0220A410: .word 0xFF00FFFF
_0220A414: .word 0xFEFFFFFF
_0220A418: .word ov96_0221CC04
_0220A41C: .word 0x0000089B
_0220A420: .word 0x0000089C
	thumb_func_end ov96_0220A298




	thumb_func_start ov96_0220A424
ov96_0220A424: ; 0x0220A424
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	add r0, r5, #0
	bl PokeathlonCourse_GetDataCopyArea
	bl ov96_021E8A20
	add r5, r0, #0
	ldr r0, [r4, #0x4c]
	bl ov96_0220B758
	add r6, r0, #0
	ldr r0, [r4, #0x4c]
	bl ov96_0220B730
	add r7, r0, #0
	ldr r0, [r4, #0x40]
	bl ov96_0220AD4C
	lsl r0, r0, #0x18
	ldr r1, [r5]
	mov r2, #0xff
	bic r1, r2
	lsr r0, r0, #0x18
	orr r1, r0
	ldr r0, _0220A4C8 ; =0xFFFF00FF
	str r1, [r5]
	and r0, r1
	ldr r1, [r6]
	lsl r1, r1, #6
	lsr r1, r1, #0x18
	lsl r1, r1, #0x18
	lsr r1, r1, #0x10
	orr r0, r1
	str r0, [r5]
	ldr r0, [r4, #0x4c]
	bl ov96_0220B79C
	lsl r0, r0, #0x18
	ldr r2, [r5]
	ldr r1, _0220A4CC ; =0xFF00FFFF
	lsr r0, r0, #8
	and r1, r2
	orr r0, r1
	str r0, [r5]
	ldr r0, [r4, #0x4c]
	bl ov96_0220B774
	lsl r0, r0, #0x1f
	ldr r2, [r5]
	ldr r1, _0220A4D0 ; =0xFBFFFFFF
	lsr r0, r0, #5
	and r1, r2
	orr r0, r1
	str r0, [r5]
	cmp r7, #3
	bne _0220A4A0
	mov r2, #1
	b _0220A4A2
_0220A4A0:
	mov r2, #0
_0220A4A2:
	ldr r1, [r5]
	ldr r0, _0220A4D4 ; =0xEFFFFFFF
	and r1, r0
	lsl r0, r2, #0x1f
	lsr r0, r0, #3
	orr r0, r1
	str r0, [r5]
	ldr r0, [r4, #0x4c]
	bl ov96_0220B7B4
	lsl r0, r0, #0x1e
	ldr r2, [r5]
	ldr r1, _0220A4D8 ; =0xFCFFFFFF
	lsr r0, r0, #6
	and r1, r2
	orr r0, r1
	str r0, [r5]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220A4C8: .word 0xFFFF00FF
_0220A4CC: .word 0xFF00FFFF
_0220A4D0: .word 0xFBFFFFFF
_0220A4D4: .word 0xEFFFFFFF
_0220A4D8: .word 0xFCFFFFFF
	thumb_func_end ov96_0220A424




	thumb_func_start ov96_0220A4DC
ov96_0220A4DC: ; 0x0220A4DC
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	bl ov96_021E5F24
	add r6, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r5, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r4, r0, #0
	cmp r5, #0
	bne _0220A4FE
	bl GF_AssertFail
_0220A4FE:
	ldr r0, [r5, #0x4c]
	cmp r0, #0
	bne _0220A508
	bl GF_AssertFail
_0220A508:
	ldr r0, [r5, #0x40]
	cmp r0, #0
	bne _0220A512
	bl GF_AssertFail
_0220A512:
	cmp r6, #0
	bne _0220A5C0
	add r0, r4, #0
	add r0, #0x28
	bl ov96_021E8A20
	add r5, r0, #0
	add r0, r4, #0
	add r0, #0x50
	bl ov96_021E8A20
	add r6, r0, #0
	add r0, r4, #0
	bl ov96_021E8A20
	add r3, r0, #0
	mov r2, #4
_0220A534:
	ldmia r3!, {r0, r1}
	stmia r6!, {r0, r1}
	sub r2, r2, #1
	bne _0220A534
	ldr r0, [r3]
	add r4, #0x50
	str r0, [r6]
	mov r6, #0
	mov r7, #0xff
_0220A546:
	add r0, r4, #0
	bl ov96_021E8A20
	ldr r2, [r0]
	ldr r1, [r5]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	lsl r2, r2, #0x18
	bic r1, r7
	lsr r2, r2, #0x18
	orr r2, r1
	ldr r1, _0220A5C8 ; =0xFFFF00FF
	str r2, [r5]
	and r1, r2
	ldr r2, [r0]
	add r6, r6, #1
	lsl r2, r2, #0x10
	lsr r2, r2, #0x18
	lsl r2, r2, #0x18
	lsr r2, r2, #0x10
	orr r2, r1
	ldr r1, _0220A5CC ; =0xFF00FFFF
	str r2, [r5]
	and r1, r2
	ldr r2, [r0]
	add r4, #0x28
	lsl r2, r2, #8
	lsr r2, r2, #0x18
	lsl r2, r2, #0x18
	lsr r2, r2, #8
	orr r2, r1
	ldr r1, _0220A5D0 ; =0xFCFFFFFF
	str r2, [r5]
	and r1, r2
	ldr r2, [r0]
	lsl r2, r2, #6
	lsr r2, r2, #0x1e
	lsl r2, r2, #0x1e
	lsr r2, r2, #6
	orr r2, r1
	ldr r1, _0220A5D4 ; =0xFBFFFFFF
	str r2, [r5]
	and r1, r2
	ldr r2, [r0]
	lsl r2, r2, #5
	lsr r2, r2, #0x1f
	lsl r2, r2, #0x1f
	lsr r2, r2, #5
	orr r2, r1
	str r2, [r5]
	ldr r0, [r0]
	ldr r1, _0220A5D8 ; =0xF7FFFFFF
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	lsl r0, r0, #0x1f
	and r1, r2
	lsr r0, r0, #4
	orr r0, r1
	stmia r5!, {r0}
	cmp r6, #4
	blt _0220A546
_0220A5C0:
	ldr r0, [sp]
	bl ov96_0220A424
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220A5C8: .word 0xFFFF00FF
_0220A5CC: .word 0xFF00FFFF
_0220A5D0: .word 0xFCFFFFFF
_0220A5D4: .word 0xFBFFFFFF
_0220A5D8: .word 0xF7FFFFFF
	thumb_func_end ov96_0220A4DC

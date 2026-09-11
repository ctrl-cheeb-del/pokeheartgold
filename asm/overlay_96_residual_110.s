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

	thumb_func_start ov96_0221490C
ov96_0221490C: ; 0x0221490C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0xe1
	lsl r0, r0, #2
	cmp r1, r0
	bgt _02214944
	ldr r0, [r5, #8]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r5, #0xc]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r5, #0x4c]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	ldr r0, [r5, #0x48]
	cmp r0, #0
	bne _0221497A
	add r0, r5, #0
	bl ov96_02214854
	mov r0, #1
	str r0, [r5, #0x48]
	pop {r3, r4, r5, pc}
_02214944:
	add r0, r1, #0
	mov r1, #0x1e
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r1, r0, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, #8]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r0, [r5, #0xc]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
_0221497A:
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_0221490C


	thumb_func_start ov96_0221497C
ov96_0221497C: ; 0x0221497C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r6, r1, #0
	add r5, r0, #0
	add r0, r6, #0
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r1, #2
	add r0, sp, #0x1c
	strb r1, [r0, #2]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0]
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
	strb r1, [r0, #3]
	add r0, r4, #0
	mov r1, #5
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, sp, #0x1c
	strb r1, [r0, #1]
	mov r4, #0
	mov r6, #4
	mov r7, #8
_022149DA:
	str r6, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x3c]
	lsl r2, r4, #2
	add r0, #0xc
	str r0, [sp, #8]
	add r0, sp, #0x1c
	add r0, #2
	ldrb r0, [r0, r4]
	add r2, r2, #6
	lsl r2, r2, #0x18
	str r0, [sp, #0xc]
	add r0, sp, #0x1c
	ldrb r0, [r0, r4]
	mov r1, #6
	lsr r2, r2, #0x18
	str r0, [sp, #0x10]
	mov r0, #0x14
	str r0, [sp, #0x14]
	mov r0, #0x10
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x10]
	mov r3, #0xa
	bl CopyRectToBgTilemapRect
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #2
	blo _022149DA
	ldr r0, [r5, #0x10]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221497C


	thumb_func_start ov96_02214A24
ov96_02214A24: ; 0x02214A24
	push {r3, r4, r5, lr}
	add r5, r1, #0
	mov r1, #0xa0
	bl Heap_Alloc
	add r4, r0, #0
	mov r1, #0
	mov r2, #0xa0
	bl MI_CpuFill8
	add r0, r4, #0
	add r0, #0x98
	strb r5, [r0]
	mov r0, #4
	sub r1, r0, r5
	add r0, r4, #0
	add r0, #0x9e
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x9e
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x9d
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #3
	add r0, #0x9b
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x9b
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x9a
	strb r1, [r0]
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02214A24


	thumb_func_start ov96_02214A6C
ov96_02214A6C: ; 0x02214A6C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #3
	add r6, r2, #0
	bl _s32_div_f
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	lsl r0, r7, #0x18
	lsr r2, r0, #0x18
	mov r0, #0x24
	mul r0, r2
	add r2, r5, r0
	lsl r0, r1, #0x18
	lsr r0, r0, #0x16
	add r0, r2, r0
	str r6, [r0, #0x18]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02214A6C


	thumb_func_start ov96_02214A9C
ov96_02214A9C: ; 0x02214A9C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r4, #0
	mov r6, #0x24
_02214AA4:
	add r0, r4, #0
	mul r0, r6
	add r0, r5, r0
	bl ov96_02214ABC
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _02214AA4
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_02214A9C


	thumb_func_start ov96_02214ABC
ov96_02214ABC: ; 0x02214ABC
	push {r3, r4, r5, r6}
	sub sp, #8
	add r1, sp, #0
	add r5, r0, #0
	mov r4, #0
	add r1, #3
	add r0, sp, #0
_02214ACA:
	lsl r2, r4, #2
	add r2, r5, r2
	ldr r3, [r2, #0x18]
	add r2, r3, #0
	add r6, r3, #0
	add r2, #0x73
	add r6, #0x70
	ldrb r2, [r2]
	ldrb r6, [r6]
	add r3, #0x75
	add r6, r2, r6
	strb r6, [r1, r4]
	ldrb r3, [r3]
	add r2, r2, r3
	strb r2, [r0, r4]
	add r2, r4, #1
	lsl r2, r2, #0x18
	lsr r4, r2, #0x18
	cmp r4, #3
	blo _02214ACA
	add r3, sp, #0
	mov r0, #0
	mov r4, #1
	add r3, #3
_02214AFA:
	add r1, r3, r4
	sub r1, r1, #1
	ldrb r2, [r1]
	ldrb r1, [r3, r4]
	cmp r2, r1
	bhs _02214B08
	add r0, r4, #0
_02214B08:
	add r1, r4, #1
	lsl r1, r1, #0x18
	lsr r4, r1, #0x18
	cmp r4, #3
	blo _02214AFA
	cmp r0, #0
	add r1, sp, #0
	bne _02214B2C
	ldrb r2, [r1, #1]
	ldrb r1, [r1, #2]
	cmp r2, r1
	blo _02214B26
	mov r2, #1
	mov r1, #2
	b _02214B56
_02214B26:
	mov r2, #2
	mov r1, #1
	b _02214B56
_02214B2C:
	cmp r0, #1
	bne _02214B44
	ldrb r2, [r1]
	ldrb r1, [r1, #2]
	cmp r2, r1
	blo _02214B3E
	mov r2, #0
	mov r1, #2
	b _02214B56
_02214B3E:
	mov r2, #2
	mov r1, #0
	b _02214B56
_02214B44:
	ldrb r2, [r1]
	ldrb r1, [r1, #1]
	cmp r2, r1
	blo _02214B52
	mov r2, #0
	mov r1, #1
	b _02214B56
_02214B52:
	mov r2, #1
	mov r1, #0
_02214B56:
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x18]
	str r0, [r5, #4]
	lsl r0, r2, #2
	add r0, r5, r0
	ldr r0, [r0, #0x18]
	str r0, [r5, #0xc]
	lsl r0, r1, #2
	add r0, r5, r0
	ldr r0, [r0, #0x18]
	str r0, [r5, #0x14]
	add sp, #8
	pop {r3, r4, r5, r6}
	bx lr
	thumb_func_end ov96_02214ABC

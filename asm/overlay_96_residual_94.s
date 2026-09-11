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

	thumb_func_start ov96_0220AD64
ov96_0220AD64: ; 0x0220AD64
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #6
	lsl r0, r0, #6
	ldr r1, [r5, r0]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	cmp r1, #0xa
	blo _0220ADAC
	add r7, r0, #0
	mov r6, #0
	add r4, r5, #0
	sub r7, #0x2c
_0220AD7E:
	ldr r0, [r4, r7]
	bl ov96_0220B164
	cmp r0, #1
	beq _0220AD90
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #0xa
	blt _0220AD7E
_0220AD90:
	cmp r6, #0xa
	bne _0220AE06
	ldr r0, _0220AE1C ; =0x000008BD
	bl PlaySE
	mov r1, #6
	lsl r1, r1, #6
	ldr r2, [r5, r1]
	mov r0, #0xf
	bic r2, r0
	mov r0, #2
	orr r0, r2
	str r0, [r5, r1]
	b _0220AE06
_0220ADAC:
	sub r1, r0, #4
	ldr r1, [r5, r1]
	sub r3, r0, #4
	lsl r1, r1, #0x10
	lsr r2, r1, #0x10
	add r1, r3, #0
	add r6, r2, #1
	lsl r6, r6, #0x10
	ldr r1, [r5, r1]
	ldr r4, _0220AE20 ; =0xFFFF0000
	lsr r6, r6, #0x10
	and r1, r4
	orr r6, r1
	add r1, r3, #0
	str r6, [r5, r1]
	cmp r2, #2
	blo _0220AE06
	ldr r1, [r5, r3]
	and r1, r4
	str r1, [r5, r3]
	ldr r1, [r5, r0]
	sub r0, #0x2c
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	lsl r1, r1, #2
	add r1, r5, r1
	ldr r0, [r1, r0]
	bl ov96_0220AED4
	ldr r0, _0220AE24 ; =0x000008C1
	bl PlaySE
	mov r2, #6
	lsl r2, r2, #6
	ldr r3, [r5, r2]
	mov r1, #0xf0
	add r0, r3, #0
	bic r0, r1
	lsl r1, r3, #0x18
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x18
	orr r0, r1
	str r0, [r5, r2]
_0220AE06:
	mov r6, #0x55
	mov r4, #0
	lsl r6, r6, #2
_0220AE0C:
	ldr r0, [r5, r6]
	bl ov96_0220AF64
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0xa
	blt _0220AE0C
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220AE1C: .word 0x000008BD
_0220AE20: .word 0xFFFF0000
_0220AE24: .word 0x000008C1
	thumb_func_end ov96_0220AD64


	thumb_func_start ov96_0220AE28
ov96_0220AE28: ; 0x0220AE28
	mov r2, #6
	lsl r2, r2, #6
	ldr r3, [r0, r2]
	lsl r1, r3, #0x18
	lsr r1, r1, #0x1c
	bne _0220AE3E
	mov r1, #0xf
	bic r3, r1
	mov r1, #1
	orr r1, r3
	str r1, [r0, r2]
_0220AE3E:
	bx lr
	thumb_func_end ov96_0220AE28


	thumb_func_start ov96_0220AE40
ov96_0220AE40: ; 0x0220AE40
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r1, #0
	add r4, r0, #0
	add r7, r2, #0
	add r5, r3, #0
	cmp r6, #0
	bne _0220AE54
	bl GF_AssertFail
_0220AE54:
	cmp r7, #0
	bne _0220AE5C
	bl GF_AssertFail
_0220AE5C:
	add r0, r4, #0
	mov r1, #0x14
	bl Heap_Alloc
	add r4, r0, #0
	mov r1, #0
	mov r2, #0x14
	bl MI_CpuFill8
	mov r2, #0
	ldr r1, [r4, #0x10]
	ldr r0, _0220AED0 ; =0xF80FFFFF
	add r3, r2, #0
	and r1, r0
	lsl r0, r5, #0x19
	lsr r0, r0, #5
	orr r0, r1
	str r0, [r4, #0x10]
	lsl r1, r5, #1
	mov r0, #0x16
	sub r0, r0, r1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	mov r0, #4
	str r0, [sp]
	add r0, r6, #0
	add r1, r7, #0
	str r5, [sp, #4]
	bl ov96_0220D13C
	mov r1, #0
	str r0, [r4, #4]
	bl ManagedSprite_SetDrawFlag
	mov r0, #1
	str r0, [sp]
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r7, #0
	mov r2, #0x78
	mov r3, #0
	bl ov96_0220D13C
	str r0, [r4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4]
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220AED0: .word 0xF80FFFFF
	thumb_func_end ov96_0220AE40


	thumb_func_start ov96_0220AED4
ov96_0220AED4: ; 0x0220AED4
	push {r4, lr}
	add r4, r0, #0
	bne _0220AEDE
	bl GF_AssertFail
_0220AEDE:
	mov r0, #0x64
	strh r0, [r4, #8]
	ldr r1, [r4, #0x10]
	ldr r0, _0220AF28 ; =0xFFFFF00F
	and r1, r0
	ldr r0, _0220AF2C ; =0xFFF00FFF
	and r1, r0
	mov r0, #1
	lsl r0, r0, #0xc
	orr r1, r0
	lsl r0, r0, #0xf
	orr r0, r1
	str r0, [r4, #0x10]
	ldr r0, [r4]
	mov r1, #1
	bl ManagedSprite_SetAnim
	ldr r0, [r4]
	mov r1, #0x78
	mov r2, #0
	bl ManagedSprite_SetPositionXY
	ldr r0, [r4]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r0, r4, #0
	bl ov96_0220AFF8
	add r0, r4, #0
	bl ov96_0220B068
	ldr r0, [r4, #4]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	pop {r4, pc}
	.balign 4, 0
_0220AF28: .word 0xFFFFF00F
_0220AF2C: .word 0xFFF00FFF
	thumb_func_end ov96_0220AED4


	thumb_func_start ov96_0220AF30
ov96_0220AF30: ; 0x0220AF30
	push {r4, lr}
	add r4, r0, #0
	bne _0220AF3A
	bl GF_AssertFail
_0220AF3A:
	ldr r0, [r4]
	cmp r0, #0
	bne _0220AF44
	bl GF_AssertFail
_0220AF44:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _0220AF4E
	bl GF_AssertFail
_0220AF4E:
	ldr r0, [r4]
	bl Sprite_DeleteAndFreeResources
	ldr r0, [r4, #4]
	bl Sprite_DeleteAndFreeResources
	add r0, r4, #0
	bl Heap_Free
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220AF30


	thumb_func_start ov96_0220AF64
ov96_0220AF64: ; 0x0220AF64
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r1, [r5, #0x10]
	lsl r0, r1, #0xc
	lsr r0, r0, #0x18
	cmp r0, #1
	bne _0220AFEE
	lsl r0, r1, #5
	lsr r0, r0, #0x19
	lsl r2, r0, #2
	mov r0, #0xa8
	sub r4, r0, r2
	ldr r0, _0220AFF0 ; =0xFFFFF00F
	and r0, r1
	lsl r1, r1, #0x14
	lsr r1, r1, #0x18
	add r1, #0x14
	lsl r1, r1, #0x18
	lsr r1, r1, #0x14
	add r2, r0, #0
	orr r2, r1
	str r2, [r5, #0x10]
	lsl r2, r2, #0x14
	ldr r0, [r5]
	mov r1, #0
	lsr r2, r2, #0x18
	bl ManagedSprite_OffsetPositionXY
	ldr r2, [r5, #0x10]
	ldr r0, [r5, #4]
	lsl r2, r2, #0x14
	mov r1, #0
	lsr r2, r2, #0x18
	bl ManagedSprite_OffsetPositionXY
	add r1, sp, #0
	ldr r0, [r5, #4]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	add r1, sp, #0
	ldr r0, [r5]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	add r3, sp, #0
	mov r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, r4
	blo _0220AFEE
	strh r4, [r3]
	mov r1, #2
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	ldr r0, [r5]
	bl ManagedSprite_SetPositionXY
	add r0, r5, #0
	bl ov96_0220B068
	ldr r1, [r5, #0x10]
	ldr r0, _0220AFF4 ; =0xFFF00FFF
	and r1, r0
	mov r0, #2
	lsl r0, r0, #0xc
	orr r0, r1
	str r0, [r5, #0x10]
_0220AFEE:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0220AFF0: .word 0xFFFFF00F
_0220AFF4: .word 0xFFF00FFF
	thumb_func_end ov96_0220AF64


	thumb_func_start ov96_0220AFF8
ov96_0220AFF8: ; 0x0220AFF8
	push {r4, lr}
	add r4, r0, #0
	bne _0220B002
	bl GF_AssertFail
_0220B002:
	bl MTRandom
	mov r1, #3
	bl _u32_div_f
	lsl r0, r1, #0x18
	ldr r1, [r4, #0x10]
	lsr r0, r0, #0x18
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	cmp r0, r1
	blo _0220B020
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
_0220B020:
	ldr r2, [r4, #0x10]
	mov r1, #0xf
	bic r2, r1
	mov r1, #0xf
	and r0, r1
	orr r0, r2
	str r0, [r4, #0x10]
	bl MTRandom
	ldr r1, [r4, #0x10]
	lsl r1, r1, #0x1c
	lsr r2, r1, #0x1a
	ldr r1, _0220B060 ; =ov96_0221CDC8
	ldrsh r2, [r1, r2]
	mov r1, #0xf
	and r0, r1
	add r0, r2, r0
	strh r0, [r4, #0xa]
	bl MTRandom
	mov r1, #0xc
	bl _u32_div_f
	ldr r0, [r4, #0x10]
	lsl r0, r0, #0x1c
	lsr r2, r0, #0x1a
	ldr r0, _0220B064 ; =ov96_0221CDCA
	ldrsh r0, [r0, r2]
	add r0, r0, r1
	strh r0, [r4, #0xc]
	pop {r4, pc}
	nop
_0220B060: .word ov96_0221CDC8
_0220B064: .word ov96_0221CDCA
	thumb_func_end ov96_0220AFF8


	thumb_func_start ov96_0220B068
ov96_0220B068: ; 0x0220B068
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bne _0220B072
	bl GF_AssertFail
_0220B072:
	add r1, sp, #0
	add r0, r4, #0
	add r1, #2
	add r2, sp, #0
	bl ov96_0220B148
	mov r0, #0xa
	add r2, sp, #0
	mov r1, #2
	ldrsh r3, [r2, r1]
	ldrsh r0, [r4, r0]
	add r0, r3, r0
	strh r0, [r2, #2]
	mov r3, #0
	mov r0, #0xc
	ldrsh r5, [r2, r3]
	ldrsh r0, [r4, r0]
	add r0, r5, r0
	strh r0, [r2]
	ldrsh r1, [r2, r1]
	ldrsh r2, [r2, r3]
	ldr r0, [r4, #4]
	bl ManagedSprite_SetPositionXY
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_0220B068


	thumb_func_start ov96_0220B0A4
ov96_0220B0A4: ; 0x0220B0A4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r6, r0, #0
	add r5, r1, #0
	mov r0, #0
	add r1, sp, #4
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	strb r0, [r1, #3]
	strb r0, [r1, #4]
	strb r0, [r1, #5]
	strb r0, [r1, #6]
	strb r0, [r1, #7]
	strb r0, [r1, #8]
	strb r0, [r1, #9]
	strb r0, [r1, #0xa]
	strb r0, [r1, #0xb]
	cmp r5, #3
	blt _0220B0D0
	bl GF_AssertFail
_0220B0D0:
	ldr r0, _0220B140 ; =ov96_0221DC68
	lsl r1, r5, #2
	ldr r4, [r0, r1]
	ldr r0, _0220B144 ; =ov96_0221CDA0
	add r1, sp, #0
	ldrb r0, [r0, r5]
	add r1, #2
	add r2, sp, #0
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	ldr r0, [r6, #4]
	bl ManagedSprite_GetPositionXY
	mov r0, #0
	cmp r5, #0
	ble _0220B11E
	add r6, sp, #0
	mov r3, #2
	ldrsh r2, [r6, r0]
	ldrsh r3, [r6, r3]
	add r1, sp, #4
_0220B0FC:
	ldrb r6, [r4]
	add r0, r0, #1
	add r6, r2, r6
	strb r6, [r1]
	ldrb r6, [r4, #1]
	add r6, r2, r6
	strb r6, [r1, #1]
	ldrb r6, [r4, #2]
	add r6, r3, r6
	strb r6, [r1, #2]
	ldrb r6, [r4, #3]
	add r4, r4, #4
	add r6, r3, r6
	strb r6, [r1, #3]
	add r1, r1, #4
	cmp r0, r5
	blt _0220B0FC
_0220B11E:
	mov r2, #0xff
	lsl r1, r5, #2
	add r0, sp, #4
	strb r2, [r0, r1]
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0220B138
	add sp, #0x10
	mov r0, #1
	pop {r4, r5, r6, pc}
_0220B138:
	mov r0, #0
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_0220B140: .word ov96_0221DC68
_0220B144: .word ov96_0221CDA0
	thumb_func_end ov96_0220B0A4


	thumb_func_start ov96_0220B148
ov96_0220B148: ; 0x0220B148
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	cmp r5, #0
	bne _0220B158
	bl GF_AssertFail
_0220B158:
	ldr r0, [r5]
	add r1, r4, #0
	add r2, r6, #0
	bl ManagedSprite_GetPositionXY
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_0220B148


	thumb_func_start ov96_0220B164
ov96_0220B164: ; 0x0220B164
	push {r4, lr}
	add r4, r0, #0
	bne _0220B16E
	bl GF_AssertFail
_0220B16E:
	ldr r0, [r4, #0x10]
	lsl r0, r0, #0xc
	lsr r0, r0, #0x18
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B164


	thumb_func_start ov96_0220B178
ov96_0220B178: ; 0x0220B178
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	mov r4, #0
_0220B184:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r1, #0x1c
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #1
	mov r2, #0
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r7, #0
	add r3, r2, #0
	bl ov96_0220D13C
	mov r1, #0
	str r0, [r5]
	bl ManagedSprite_SetDrawFlag
	add r4, r4, #1
	add r5, #0x14
	cmp r4, #0x10
	blt _0220B184
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220B178


	thumb_func_start ov96_0220B1B8
ov96_0220B1B8: ; 0x0220B1B8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r4, #0
_0220B1BE:
	ldr r0, [r5]
	cmp r0, #0
	bne _0220B1C8
	bl GF_AssertFail
_0220B1C8:
	ldr r0, [r5]
	bl Sprite_DeleteAndFreeResources
	add r4, r4, #1
	add r5, #0x14
	cmp r4, #0x10
	blt _0220B1BE
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_0220B1B8


	thumb_func_start ov96_0220B1D8
ov96_0220B1D8: ; 0x0220B1D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r1, [sp]
	mov r4, #0
	add r5, r0, #0
	add r7, r2, #0
	str r3, [sp, #4]
	add r6, r4, #0
_0220B1E8:
	ldr r0, [r5, #4]
	cmp r0, #0
	bne _0220B2C0
	mov r0, #1
	str r0, [r5, #4]
	strh r7, [r5, #0x10]
	ldr r0, [sp, #4]
	strh r0, [r5, #0x12]
	bl MTRandom
	mov r1, #7
	and r0, r1
	add r0, r0, #4
	beq _0220B220
	bl MTRandom
	mov r1, #7
	and r0, r1
	add r0, r0, #4
	lsl r0, r0, #0xc
	bl _ffltu
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0220B238
_0220B220:
	bl MTRandom
	mov r1, #7
	and r0, r1
	add r0, r0, #4
	lsl r0, r0, #0xc
	bl _ffltu
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0220B238:
	lsr r2, r6, #0x1f
	lsl r1, r6, #0x1f
	add r3, r0, #0
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	bne _0220B24E
	mov r0, #1
	str r0, [sp, #8]
	b _0220B254
_0220B24E:
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #8]
_0220B254:
	add r0, r3, #0
	bl _ffix
	ldr r1, [sp, #8]
	mul r0, r1
	str r0, [r5, #8]
	bl MTRandom
	mov r1, #7
	and r0, r1
	add r0, #8
	beq _0220B288
	bl MTRandom
	mov r1, #7
	and r0, r1
	add r0, #8
	lsl r0, r0, #0xc
	bl _ffltu
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0220B2A0
_0220B288:
	bl MTRandom
	mov r1, #7
	and r0, r1
	add r0, #8
	lsl r0, r0, #0xc
	bl _ffltu
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0220B2A0:
	bl _ffix
	str r0, [r5, #0xc]
	ldr r0, [r5]
	ldr r2, [sp, #4]
	add r1, r7, #0
	bl ManagedSprite_SetPositionXY
	ldr r0, [r5]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r0, [r5]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r4, r4, #1
_0220B2C0:
	ldr r0, [sp]
	cmp r4, r0
	bge _0220B2CE
	add r6, r6, #1
	add r5, #0x14
	cmp r6, #0x10
	blt _0220B1E8
_0220B2CE:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B1D8


	thumb_func_start ov96_0220B2D4
ov96_0220B2D4: ; 0x0220B2D4
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x10
	ldrsh r1, [r4, r0]
	ldr r0, [r4, #8]
	asr r0, r0, #0xc
	add r0, r1, r0
	strh r0, [r4, #0x10]
	ldr r0, [r4, #8]
	mov r1, #3
	lsl r0, r0, #2
	bl _s32_div_f
	str r0, [r4, #8]
	mov r2, #0x12
	ldr r0, [r4, #0xc]
	ldrsh r1, [r4, r2]
	asr r0, r0, #0xc
	sub r0, r1, r0
	strh r0, [r4, #0x12]
	ldr r0, [r4, #0xc]
	mov r1, #0x10
	sub r0, r0, #4
	str r0, [r4, #0xc]
	ldrsh r1, [r4, r1]
	ldrsh r2, [r4, r2]
	ldr r0, [r4]
	bl ManagedSprite_SetPositionXY
	mov r0, #0x10
	ldrsh r1, [r4, r0]
	cmp r1, #0
	blt _0220B31C
	add r0, #0xf0
	cmp r1, r0
	ble _0220B320
_0220B31C:
	mov r0, #1
	pop {r4, pc}
_0220B320:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov96_0220B2D4


	thumb_func_start ov96_0220B324
ov96_0220B324: ; 0x0220B324
	push {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	add r5, r0, #0
	add r7, r4, #0
	add r6, r4, #0
_0220B32E:
	ldr r0, [r5, #4]
	cmp r0, #1
	bne _0220B348
	add r0, r5, #0
	bl ov96_0220B2D4
	cmp r0, #0
	beq _0220B348
	ldr r0, [r5]
	add r1, r7, #0
	bl ManagedSprite_SetDrawFlag
	str r6, [r5, #4]
_0220B348:
	add r4, r4, #1
	add r5, #0x14
	cmp r4, #0x10
	blt _0220B32E
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B324


	thumb_func_start ov96_0220B354
ov96_0220B354: ; 0x0220B354
	push {r4, r5, r6, lr}
	mov r4, #0
	add r5, r0, #0
	add r6, r4, #0
_0220B35C:
	ldr r0, [r5, #4]
	cmp r0, #1
	bne _0220B36A
	ldr r0, [r5]
	add r1, r6, #0
	bl ManagedSprite_SetAnimateFlag
_0220B36A:
	add r4, r4, #1
	add r5, #0x14
	cmp r4, #0x10
	blt _0220B35C
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_0220B354


	thumb_func_start ov96_0220B374
ov96_0220B374: ; 0x0220B374
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r0, #0
	add r0, r3, #0
	add r5, r1, #0
	add r6, r2, #0
	str r3, [sp, #8]
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	add r0, r7, #0
	mov r1, #0x48
	bl Heap_Alloc
	add r4, r0, #0
	mov r1, #0
	mov r2, #0x48
	bl MI_CpuFill8
	str r7, [r4]
	str r5, [r4, #4]
	ldr r0, [sp, #8]
	str r6, [r4, #8]
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x44]
	mov r0, #0xff
	bic r1, r0
	str r1, [r4, #0x44]
	add r0, r4, #0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #8]
	add r0, #0x34
	bl ov96_0220D200
	add r0, r4, #0
	ldr r1, [r4, #4]
	ldr r2, [r4, #8]
	add r0, #0x10
	bl ov96_0220C490
	add r1, sp, #0x14
	mov r3, #1
	ldr r0, [r4, #0x24]
	add r1, #2
	add r2, sp, #0x14
	lsl r3, r3, #0x14
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r3, sp, #0x10
	mov r7, #4
	ldrsh r0, [r3, r7]
	mov r2, #6
	add r1, r6, #0
	sub r0, #0x18
	strh r0, [r3, #4]
	mov r0, #0x11
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldrsh r2, [r3, r2]
	ldrsh r3, [r3, r7]
	add r0, r5, #0
	bl ov96_0220D1A0
	str r0, [r4, #0x2c]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r1, sp, #0x14
	ldr r0, [r4, #0x28]
	add r1, #2
	add r2, sp, #0x14
	lsl r3, r7, #0x12
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r3, sp, #0x10
	ldrsh r0, [r3, r7]
	mov r2, #6
	add r1, r6, #0
	sub r0, #0x18
	strh r0, [r3, #4]
	mov r0, #0x11
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldrsh r2, [r3, r2]
	ldrsh r3, [r3, r7]
	add r0, r5, #0
	bl ov96_0220D1A0
	str r0, [r4, #0x30]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r1, sp, #0x10
	ldr r0, [r4, #0x10]
	add r1, #2
	add r2, sp, #0x10
	bl ManagedSprite_GetPositionXY
	mov r0, #0x11
	str r0, [sp]
	mov r0, #0x1a
	str r0, [sp, #4]
	add r7, sp, #0x10
	mov r2, #2
	mov r3, #0
	ldrsh r2, [r7, r2]
	ldrsh r3, [r7, r3]
	add r0, r5, #0
	add r1, r6, #0
	bl ov96_0220D13C
	mov r1, #0
	str r0, [r4, #0x14]
	bl ManagedSprite_SetDrawFlag
	mov r0, #0xf
	str r0, [sp]
	mov r0, #0x17
	str r0, [sp, #4]
	mov r2, #2
	mov r3, #0
	ldrsh r2, [r7, r2]
	ldrsh r3, [r7, r3]
	add r0, r5, #0
	add r1, r6, #0
	bl ov96_0220D13C
	mov r1, #0
	str r0, [r4, #0x1c]
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x1b
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r2, #2
	mov r3, #0
	ldrsh r2, [r7, r2]
	ldrsh r3, [r7, r3]
	add r0, r5, #0
	add r1, r6, #0
	bl ov96_0220D13C
	mov r1, #0
	str r0, [r4, #0x20]
	bl ManagedSprite_SetDrawFlag
	add r3, r7, #0
	mov r7, #0
	ldrsh r0, [r3, r7]
	mov r2, #2
	add r1, r6, #0
	sub r0, #0x18
	strh r0, [r3]
	mov r0, #0x18
	str r0, [sp]
	mov r0, #0x19
	str r0, [sp, #4]
	ldrsh r2, [r3, r2]
	ldrsh r3, [r3, r7]
	add r0, r5, #0
	bl ov96_0220D13C
	add r1, r7, #0
	str r0, [r4, #0x18]
	bl ManagedSprite_SetDrawFlag
	mov r0, #1
	str r0, [sp]
	add r1, r7, #0
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	add r3, r1, #0
	bl ov96_0220C54C
	add r0, r7, #0
	str r0, [sp]
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	mov r1, #5
	mov r3, #2
	bl ov96_0220C54C
	add r0, r7, #0
	str r0, [sp]
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	mov r1, #6
	mov r3, #1
	bl ov96_0220C54C
	add r0, r4, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0220B374


	thumb_func_start ov96_0220B500
ov96_0220B500: ; 0x0220B500
	push {r4, r5, r6, lr}
	add r6, r0, #0
	bne _0220B50A
	bl GF_AssertFail
_0220B50A:
	mov r4, #0
	add r5, r6, #0
_0220B50E:
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0220B518
	bl Sprite_DeleteAndFreeResources
_0220B518:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #9
	blt _0220B50E
	add r0, r6, #0
	bl Heap_Free
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_0220B500


	thumb_func_start ov96_0220B528
ov96_0220B528: ; 0x0220B528
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r4, r0, #0
	add r5, r1, #0
	cmp r4, #0
	bne _0220B538
	bl GF_AssertFail
_0220B538:
	ldr r0, [r4, #0x40]
	lsl r0, r0, #0x16
	lsr r0, r0, #0x18
	cmp r0, #3
	bhi _0220B578
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0220B54E: ; jump table
	.short _0220B556 - _0220B54E - 2 ; case 0
	.short _0220B560 - _0220B54E - 2 ; case 1
	.short _0220B568 - _0220B54E - 2 ; case 2
	.short _0220B570 - _0220B54E - 2 ; case 3
_0220B556:
	add r0, r4, #0
	add r1, r5, #0
	bl ov96_0220B940
	b _0220B57C
_0220B560:
	add r0, r4, #0
	bl ov96_0220B95C
	b _0220B57C
_0220B568:
	add r0, r4, #0
	bl ov96_0220B988
	b _0220B57C
_0220B570:
	add r0, r4, #0
	bl ov96_0220B9A8
	b _0220B57C
_0220B578:
	bl GF_AssertFail
_0220B57C:
	ldr r0, _0220B62C ; =ov96_0221E5A4
	ldr r1, [r0]
	add r1, r1, #1
	str r1, [r0]
	cmp r5, #0
	bne _0220B58E
	add r0, r4, #0
	bl ov96_0220C680
_0220B58E:
	add r0, r4, #0
	bl ov96_0220BD38
	ldr r2, [r4, #0x40]
	add r0, r4, #0
	lsl r1, r2, #0xb
	lsl r2, r2, #0x1e
	lsr r2, r2, #0x1e
	lsl r2, r2, #0x18
	add r0, #0x34
	lsr r1, r1, #0x15
	lsr r2, r2, #0x18
	bl ov96_0220D2AC
	ldr r1, [r4, #0x40]
	ldr r0, _0220B630 ; =0xFFE003FF
	and r0, r1
	lsl r1, r1, #0xb
	lsr r1, r1, #0x15
	add r1, r1, #1
	lsl r1, r1, #0x15
	lsr r1, r1, #0xb
	orr r0, r1
	str r0, [r4, #0x40]
	ldr r0, [r4, #0x10]
	bl ManagedSprite_IsAnimated
	cmp r0, #0
	beq _0220B628
	ldr r0, [r4, #0x10]
	ldr r0, [r0]
	bl Sprite_GetCellAnim
	add r6, r0, #0
	bl NNS_G2dGetAnimCtrlCurrentElement
	add r5, r0, #0
	ldr r0, [r6, #0xc]
	cmp r0, #0
	bne _0220B5E2
	bl GF_AssertFail
_0220B5E2:
	add r1, sp, #0
	ldr r0, [r4, #0x10]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	mov r0, #4
	add r3, sp, #0
	mov r1, #2
	ldrsh r2, [r3, r1]
	ldrsh r0, [r5, r0]
	mov r6, #6
	add r0, r2, r0
	strh r0, [r3, #2]
	mov r2, #0
	ldrsh r0, [r3, r2]
	ldrsh r5, [r5, r6]
	add r0, r0, r5
	strh r0, [r3]
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	ldr r0, [r4, #0x14]
	bl ManagedSprite_SetPositionXY
	add r3, sp, #0
	mov r2, #0
	ldrsh r0, [r3, r2]
	mov r1, #2
	sub r0, #0x18
	strh r0, [r3]
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	ldr r0, [r4, #0x18]
	bl ManagedSprite_SetPositionXY
_0220B628:
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0220B62C: .word ov96_0221E5A4
_0220B630: .word 0xFFE003FF
	thumb_func_end ov96_0220B528


	thumb_func_start ov96_0220B634
ov96_0220B634: ; 0x0220B634
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r7, r1, #0
	ldr r0, _0220B6E4 ; =ov96_0221E5A4
	str r2, [sp, #4]
	mov r1, #0
	str r1, [r0]
	ldr r0, [r5, #0x40]
	lsl r0, r0, #0x16
	lsr r0, r0, #0x18
	cmp r0, #2
	bne _0220B652
	bl GF_AssertFail
_0220B652:
	ldr r0, [r5, #0x40]
	lsl r1, r0, #0x16
	lsr r1, r1, #0x18
	cmp r1, #1
	bne _0220B69C
	lsl r0, r0, #0x1e
	add r4, r5, #0
	lsr r0, r0, #0x1e
	ldr r1, [r5, #0x44]
	add r4, #0x34
	lsl r6, r0, #2
	ldr r0, [r4, r6]
	lsl r1, r1, #8
	lsr r1, r1, #0x18
	lsl r0, r0, #6
	lsl r1, r1, #0x10
	lsr r0, r0, #0x18
	lsr r1, r1, #0x10
	bl ov96_0220D33C
	lsl r0, r0, #0x18
	ldr r2, [r4, r6]
	ldr r1, _0220B6E8 ; =0xFC03FFFF
	lsr r0, r0, #6
	and r1, r2
	orr r0, r1
	str r0, [r4, r6]
	ldr r0, [r4, r6]
	lsl r0, r0, #6
	lsr r0, r0, #0x18
	bne _0220B69C
	add r0, r5, #0
	mov r1, #2
	bl ov96_0220C578
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_0220B69C:
	ldr r0, [r5, #0x44]
	lsl r0, r0, #0x17
	lsr r0, r0, #0x1f
	bne _0220B6AE
	ldr r2, [sp, #4]
	add r0, r5, #0
	add r1, r7, #0
	bl ov96_0220C714
_0220B6AE:
	ldr r0, [r5, #0x10]
	mov r1, #2
	bl ManagedSprite_SetAnim
	ldr r0, [r5, #0xc]
	bl ov96_021E5F24
	add r1, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r2, [r5, #0x40]
	lsl r1, r1, #0x18
	lsl r2, r2, #0x1e
	lsr r2, r2, #0x1e
	lsl r2, r2, #0x18
	ldr r0, [r5, #0xc]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #4
	bl ov96_021E8228
	add r0, r5, #0
	mov r1, #1
	bl ov96_0220C578
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220B6E4: .word ov96_0221E5A4
_0220B6E8: .word 0xFC03FFFF
	thumb_func_end ov96_0220B634


	thumb_func_start ov96_0220B6EC
ov96_0220B6EC: ; 0x0220B6EC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x40]
	lsl r0, r0, #0x16
	lsr r0, r0, #0x18
	cmp r0, #3
	bne _0220B6FE
	bl GF_AssertFail
_0220B6FE:
	add r0, r4, #0
	mov r1, #3
	bl ov96_0220C578
	pop {r4, pc}
	thumb_func_end ov96_0220B6EC


	thumb_func_start ov96_0220B708
ov96_0220B708: ; 0x0220B708
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	cmp r5, #0
	bne _0220B716
	bl GF_AssertFail
_0220B716:
	mov r4, #0
_0220B718:
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0220B724
	add r1, r6, #0
	bl ManagedSprite_SetAnimateFlag
_0220B724:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #9
	blt _0220B718
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_0220B708

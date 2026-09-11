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

	thumb_func_start ov96_02210858
ov96_02210858: ; 0x02210858
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	ldr r0, [r0, #4]
	bl PokeathlonCourse_GetHeapAllocPtr4
	mov r7, #0
	add r6, r0, #0
	add r4, r7, #0
_02210868:
	lsl r1, r4, #0x18
	add r0, r6, #0
	lsr r1, r1, #0x18
	bl ov96_0220E850
	add r4, r4, #1
	add r7, r7, r0
	cmp r4, #4
	blt _02210868
	ldr r0, [sp]
	mov r5, #0
	add r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	ble _022108BA
	asr r0, r7, #1
	lsr r0, r0, #0x1e
	ldr r4, [sp]
	add r0, r7, r0
	lsl r0, r0, #0xe
	add r4, #8
	lsr r7, r0, #0x10
_02210894:
	lsl r1, r5, #0x18
	add r0, r6, #0
	lsr r1, r1, #0x18
	bl ov96_0220E850
	add r2, r0, #0
	lsl r2, r2, #0x10
	add r0, r4, #0
	add r1, r7, #0
	lsr r2, r2, #0x10
	bl ov96_022108EC
	ldr r0, [sp]
	add r5, r5, #1
	add r0, #0xbc
	ldrb r0, [r0]
	add r4, #0x3c
	cmp r5, r0
	blt _02210894
_022108BA:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_02210858


	thumb_func_start ov96_022108BC
ov96_022108BC: ; 0x022108BC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r7, r2, #0
	mov r1, #0
	mov r2, #0x3c
	add r5, r0, #0
	bl MI_CpuFill8
	lsl r0, r4, #1
	mov r6, #0
	add r4, r4, r0
_022108D2:
	lsl r2, r4, #0x18
	add r0, r5, #0
	add r1, r7, #0
	lsr r2, r2, #0x18
	bl ov96_02210980
	add r6, r6, #1
	add r4, r4, #1
	add r5, #0x14
	cmp r6, #3
	blt _022108D2
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_022108BC


	thumb_func_start ov96_022108EC
ov96_022108EC: ; 0x022108EC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	mov r4, #0
_022108F6:
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	bl ov96_02210AE0
	add r4, r4, #1
	add r5, #0x14
	cmp r4, #3
	blt _022108F6
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_022108EC


	thumb_func_start ov96_0221090C
ov96_0221090C: ; 0x0221090C
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x19
	lsr r0, r0, #0x1e
	lsl r5, r0, #1
	bl MTRandom
	ldr r1, _02210970 ; =ov96_0221D1B1
	ldrb r1, [r1, r5]
	bl _u32_div_f
	ldr r0, _02210974 ; =ov96_0221D1B0
	ldrb r0, [r0, r5]
	add r0, r0, r1
	strh r0, [r4, #6]
	mov r0, #6
	ldrsh r0, [r4, r0]
	lsl r0, r0, #3
	strh r0, [r4, #6]
	ldr r1, [r4, #0xc]
	lsl r0, r1, #0x1b
	lsr r2, r0, #0x1e
	mov r0, #0xc
	mul r0, r2
	ldr r2, _02210978 ; =ov96_0221D1C4
	lsl r1, r1, #0x19
	lsr r1, r1, #0x1e
	lsl r1, r1, #2
	add r0, r2, r0
	ldrsh r0, [r1, r0]
	strh r0, [r4, #8]
	bl MTRandom
	mov r1, #5
	bl _u32_div_f
	mov r0, #8
	ldrsh r2, [r4, r0]
	sub r0, r1, #2
	lsl r0, r0, #3
	add r0, r2, r0
	strh r0, [r4, #8]
	ldr r1, [r4, #0xc]
	mov r0, #1
	bic r1, r0
	ldr r0, _0221097C ; =0xFFFFF87F
	and r0, r1
	str r0, [r4, #0xc]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02210970: .word ov96_0221D1B1
_02210974: .word ov96_0221D1B0
_02210978: .word ov96_0221D1C4
_0221097C: .word 0xFFFFF87F
	thumb_func_end ov96_0221090C


	thumb_func_start ov96_02210980
ov96_02210980: ; 0x02210980
	push {r3, r4, r5, r6, r7, lr}
	add r7, r2, #0
	add r5, r0, #0
	add r6, r1, #0
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	str r6, [r5]
	ldr r2, [r5, #0xc]
	mov r1, #0x18
	bic r2, r1
	lsl r1, r4, #0x1e
	lsr r1, r1, #0x1b
	orr r2, r1
	mov r1, #0x60
	lsr r0, r0, #0x18
	bic r2, r1
	lsl r1, r0, #0x1e
	lsr r1, r1, #0x19
	orr r1, r2
	lsl r2, r4, #1
	lsl r0, r0, #3
	add r0, r2, r0
	ldr r2, _022109D4 ; =0xFFF807FF
	and r2, r1
	lsl r1, r0, #0x18
	lsr r1, r1, #0xd
	orr r1, r2
	str r1, [r5, #0xc]
	strb r0, [r5, #0x10]
	add r0, r5, #0
	bl ov96_0221090C
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022109D4: .word 0xFFF807FF
	thumb_func_end ov96_02210980


	thumb_func_start ov96_022109D8
ov96_022109D8: ; 0x022109D8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	ldr r0, [r6]
	bl PokeathlonCourse_GetHeapAllocPtr4
	ldr r1, [r6, #0xc]
	add r7, r0, #0
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	ldr r0, [r6]
	lsr r1, r1, #0x18
	bl ov96_0220E7BC
	ldr r0, [r6, #0xc]
	lsl r1, r0, #0x15
	lsr r1, r1, #0x1c
	beq _02210A04
	cmp r1, #1
	beq _02210A68
	b _02210ABA
_02210A04:
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _02210A0E
	bl GF_AssertFail
_02210A0E:
	mov r0, #8
	ldrsh r0, [r6, r0]
	add r4, r6, #0
	mov r5, #0
	strh r0, [r6, #4]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #1
	add r4, #0xc
	str r0, [sp]
_02210A22:
	lsl r1, r5, #0x18
	add r0, r7, #0
	lsr r1, r1, #0x18
	bl ov96_0220E74C
	ldr r0, [r0, #4]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1f
	beq _02210A60
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #0x38
	bl ov96_02210BD0
	cmp r0, #0
	beq _02210A60
	ldr r0, [r4]
	ldr r1, [sp, #4]
	bic r0, r1
	lsl r1, r5, #0x1e
	lsr r1, r1, #0x1d
	orr r1, r0
	ldr r0, [sp]
	bic r1, r0
	mov r0, #1
	orr r1, r0
	ldr r0, _02210ADC ; =0xFFFFF87F
	and r1, r0
	mov r0, #0x80
	orr r0, r1
	str r0, [r4]
_02210A60:
	add r5, r5, #1
	cmp r5, #2
	blt _02210A22
	b _02210ABE
_02210A68:
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r0, #1
	beq _02210A74
	bl GF_AssertFail
_02210A74:
	ldr r1, [r6, #0xc]
	lsl r0, r1, #0x1f
	lsr r0, r0, #0x1f
	beq _02210ABE
	lsl r1, r1, #0x1d
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	add r0, r7, #0
	lsr r1, r1, #0x18
	bl ov96_0220E74C
	add r1, r0, #0
	ldr r0, [r1, #4]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1f
	beq _02210AAC
	mov r0, #6
	ldrsh r2, [r6, r0]
	mov r0, #0x12
	lsl r0, r0, #4
	add r0, r2, r0
	lsl r0, r0, #0x10
	ldrb r1, [r1, #9]
	asr r0, r0, #0x10
	bl ov96_0220E6DC
	strh r0, [r6, #4]
	b _02210ABE
_02210AAC:
	ldr r1, [r6, #0xc]
	mov r0, #1
	bic r1, r0
	ldr r0, _02210ADC ; =0xFFFFF87F
	and r0, r1
	str r0, [r6, #0xc]
	b _02210ABE
_02210ABA:
	bl GF_AssertFail
_02210ABE:
	ldr r3, [r6, #0xc]
	add r0, r7, #0
	lsl r2, r3, #0x1b
	lsl r3, r3, #0x19
	lsr r2, r2, #0x1e
	lsr r3, r3, #0x1e
	lsl r2, r2, #0x18
	lsl r3, r3, #0x18
	add r1, r6, #4
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl ov96_0220E818
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02210ADC: .word 0xFFFFF87F
	thumb_func_end ov96_022109D8


	thumb_func_start ov96_02210AE0
ov96_02210AE0: ; 0x02210AE0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	add r6, r2, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	ldr r2, [r5, #0xc]
	str r0, [sp, #4]
	lsl r1, r2, #0x1b
	lsl r2, r2, #0x19
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_0220E70C
	cmp r0, #0
	beq _02210BC4
	ldrb r0, [r5, #0x10]
	sub r0, r0, #1
	strb r0, [r5, #0x10]
	ldrb r0, [r5, #0x10]
	cmp r0, #0
	bne _02210B22
	add r0, r5, #0
	bl ov96_0221090C
	mov r0, #0x5a
	strb r0, [r5, #0x10]
_02210B22:
	ldr r1, [r5, #0xc]
	ldr r0, _02210BC8 ; =0xFFF807FF
	and r0, r1
	lsl r1, r1, #0xd
	lsr r1, r1, #0x18
	sub r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0xd
	orr r0, r1
	str r0, [r5, #0xc]
	lsl r0, r0, #0xd
	lsr r0, r0, #0x18
	bne _02210B50
	add r0, r5, #0
	bl ov96_022109D8
	ldr r1, [r5, #0xc]
	ldr r0, _02210BC8 ; =0xFFF807FF
	and r1, r0
	mov r0, #0xa
	lsl r0, r0, #0xc
	orr r0, r1
	str r0, [r5, #0xc]
_02210B50:
	ldr r1, [r5, #0xc]
	lsl r0, r1, #0x1f
	lsr r0, r0, #0x1f
	beq _02210BC4
	lsl r1, r1, #0x1d
	add r0, r5, #0
	lsr r1, r1, #0x1e
	mov r2, #0x10
	bl ov96_02210BD0
	cmp r0, #0
	beq _02210BC4
	bl MTRandom
	mov r1, #0x64
	bl _u32_div_f
	add r0, sp, #8
	str r0, [sp]
	ldr r2, [r5, #0xc]
	add r7, r1, #0
	lsl r1, r2, #0x1b
	lsl r2, r2, #0x19
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	add r3, sp, #0xc
	bl ov96_0220E770
	add r4, #0x14
	cmp r4, r6
	bge _02210B9C
	mov r0, #0
	b _02210BA8
_02210B9C:
	ldr r0, [r5, #0xc]
	lsl r0, r0, #0x19
	lsr r0, r0, #0x1e
	lsl r1, r0, #2
	ldr r0, _02210BCC ; =ov96_0221D1B8
	ldr r0, [r0, r1]
_02210BA8:
	cmp r7, r0
	bge _02210BC4
	ldr r2, [r5, #0xc]
	ldr r0, [sp, #4]
	lsl r1, r2, #0x1b
	lsl r2, r2, #0x19
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_0220E834
_02210BC4:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02210BC8: .word 0xFFF807FF
_02210BCC: .word ov96_0221D1B8
	thumb_func_end ov96_02210AE0


	thumb_func_start ov96_02210BD0
ov96_02210BD0: ; 0x02210BD0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r0, [r4]
	add r5, r1, #0
	add r6, r2, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	lsl r1, r5, #0x18
	lsr r1, r1, #0x18
	add r7, r0, #0
	bl ov96_0220E74C
	add r5, r0, #0
	mov r0, #2
	ldrsh r1, [r5, r0]
	mov r0, #0x12
	lsl r0, r0, #4
	cmp r1, r0
	bge _02210BFE
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02210BFE:
	add r0, sp, #8
	str r0, [sp]
	ldr r2, [r4, #0xc]
	add r0, r7, #0
	lsl r1, r2, #0x1b
	lsl r2, r2, #0x19
	lsr r1, r1, #0x1e
	lsr r2, r2, #0x1e
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	add r3, sp, #0xc
	bl ov96_0220E770
	mov r0, #2
	ldrsh r1, [r5, r0]
	mov r0, #0x12
	lsl r0, r0, #4
	sub r0, r1, r0
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	mov r3, #0
	add r2, sp, #8
	mov r0, #4
	mov r1, #6
	ldrsh r0, [r2, r0]
	ldrsh r1, [r2, r1]
	ldrsh r3, [r5, r3]
	ldr r2, [sp, #8]
	bl ov96_02210C48
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02210BD0


	thumb_func_start ov96_02210C48
ov96_02210C48: ; 0x02210C48
	push {r4, r5}
	ldr r5, _02210C94 ; =0xFFFFFFF8
	mov r4, #0x10
	add r5, sp
	ldrsh r4, [r5, r4]
	sub r4, r1, r4
	bpl _02210C5A
	neg r1, r4
	b _02210C5C
_02210C5A:
	add r1, r4, #0
_02210C5C:
	cmp r4, #0
	bge _02210C62
	neg r4, r4
_02210C62:
	sub r3, r0, r3
	bpl _02210C6A
	neg r0, r3
	b _02210C6C
_02210C6A:
	add r0, r3, #0
_02210C6C:
	cmp r3, #0
	bge _02210C72
	neg r3, r3
_02210C72:
	ldr r5, [sp, #0xc]
	add r2, r2, r5
	add r5, r2, #0
	mul r5, r2
	add r2, r3, #0
	mul r2, r0
	add r0, r4, #0
	mul r0, r1
	add r0, r2, r0
	cmp r5, r0
	blt _02210C8E
	mov r0, #1
	pop {r4, r5}
	bx lr
_02210C8E:
	mov r0, #0
	pop {r4, r5}
	bx lr
	.balign 4, 0
_02210C94: .word 0xFFFFFFF8
	thumb_func_end ov96_02210C48


	thumb_func_start ov96_02210C98
ov96_02210C98: ; 0x02210C98
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x98
	str r0, [sp, #0x14]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r4, r0, #0
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetField1ED
	cmp r0, #5
	bls _02210CB4
	bl _02211626
_02210CB4:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02210CC0: ; jump table
	.short _02210CCC - _02210CC0 - 2 ; case 0
	.short _02210DCE - _02210CC0 - 2 ; case 1
	.short _02210E1A - _02210CC0 - 2 ; case 2
	.short _022111D4 - _02210CC0 - 2 ; case 3
	.short _0221123C - _02210CC0 - 2 ; case 4
	.short _02211616 - _02210CC0 - 2 ; case 5
_02210CCC:
	mov r2, #5
	mov r0, #0x5c
	mov r1, #0x93
	lsl r2, r2, #0x10
	bl Heap_Create
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0
	add r1, r0, #0
	bl Main_SetHBlankIntrCB
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _02211078 ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _0221107C ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	bl ov96_022117CC
	mov r1, #0x82
	ldr r0, [sp, #0x14]
	lsl r1, r1, #4
	bl PokeathlonCourse_AllocPtr4FromHeap
	mov r2, #0x82
	mov r1, #0
	lsl r2, r2, #4
	add r5, r0, #0
	bl MI_CpuFill8
	mov r0, #0x93
	mov r1, #0x28
	bl Heap_Alloc
	ldr r1, _02211080 ; =0x0000081C
	mov r2, #0x28
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	mov r1, #0
	bl MI_CpuFill8
	mov r0, #0x93
	bl BgConfig_Alloc
	str r0, [r5, #4]
	ldr r0, [sp, #0x14]
	mov r1, #8
	bl ov96_021E6670
	mov r0, #0x85
	str r0, [sp, #0x108]
	mov r0, #1
	lsl r0, r0, #0x12
	str r0, [sp, #0x10c]
	lsr r0, r0, #4
	mov r2, #0x93
	str r0, [sp, #0x110]
	ldr r3, _02211084 ; =0x00300010
	str r2, [sp, #0x114]
	mov r1, #0x10
	add r0, sp, #0x108
	str r1, [sp]
	bl ov96_021E92B0
	bl NNS_G2dInitOamManagerModule
	mov r0, #1
	str r0, [sp]
	mov r1, #0x7e
	str r1, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x93
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	mov r1, #0x93
	str r1, [r5, #0x58]
	mov r0, #4
	bl FontID_Alloc
	ldr r0, [r5, #4]
	bl ov96_022118C4
	add r0, r5, #0
	bl ov96_0221362C
	ldr r0, [sp, #0x14]
	bl ov96_022140F4
	mov r4, #0
	add r6, r4, #0
_02210DA0:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov96_02214044
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _02210DA0
	add r0, r5, #0
	bl ov96_022141F8
	ldr r0, _02211088 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	bl _02211626
_02210DCE:
	ldr r0, [r4, #0x58]
	ldr r1, [r4, #4]
	ldr r2, [sp, #0x14]
	bl ov96_0221464C
	mov r1, #0x75
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetParticipantCount
	add r5, r0, #0
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetMode
	add r2, r0, #0
	mov r1, #4
	ldr r0, [r4, #0x58]
	sub r1, r1, r5
	bl ov96_02214A24
	ldr r1, _0221108C ; =0x0000074C
	mov r2, #1
	str r0, [r4, r1]
	ldr r0, [r4, #0x58]
	ldr r1, _02211090 ; =0x00000AAF
	bl ov96_021E9A78
	ldr r1, _02211094 ; =0x00000744
	str r0, [r4, r1]
	ldr r0, [sp, #0x14]
	bl ov96_021E64B8
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	bl _02211626
_02210E1A:
	ldr r5, _02211098 ; =ov96_0221D238
	add r3, sp, #0xfc
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [r3]
	ldr r0, [r4, #0x58]
	bl ov96_021EB180
	mov r1, #0
	str r0, [r4]
	mov r0, #2
	lsl r0, r0, #0x14
	str r0, [sp]
	ldr r0, [r4]
	add r2, r1, #0
	add r3, r1, #0
	bl ov96_021EB5C8
	ldr r0, [r4]
	bl ov96_021EB5E8
	str r0, [sp]
	ldr r3, _02211094 ; =0x00000744
	ldr r0, [r4, #0x58]
	ldr r3, [r4, r3]
	mov r1, #0xc
	mov r2, #8
	bl ov96_021EA854
	ldr r1, _0221109C ; =0x00000748
	mov r2, #0x65
	str r0, [r4, r1]
	ldr r0, [r4]
	mov r1, #0
	bl ov96_021EB29C
	ldr r0, [r4]
	mov r1, #1
	mov r2, #0x66
	bl ov96_021EB29C
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #0xec
	mov r2, #0x12
	mov r3, #0x65
	bl ov96_021EB2BC
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0xec
	mov r2, #0xf
	mov r3, #0x65
	bl ov96_021EB2F4
	ldr r0, [r4]
	mov r1, #0xec
	mov r2, #0x11
	mov r3, #0x65
	bl ov96_021EB334
	ldr r0, [r4]
	mov r1, #0xec
	mov r2, #0x10
	mov r3, #0x65
	bl ov96_021EB36C
	mov r0, #2
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #0xec
	mov r2, #0xe
	mov r3, #0x66
	bl ov96_021EB2BC
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0xec
	mov r2, #0xb
	mov r3, #0x66
	bl ov96_021EB2F4
	ldr r0, [r4]
	mov r1, #0xec
	mov r2, #0xd
	mov r3, #0x66
	bl ov96_021EB334
	ldr r0, [r4]
	mov r1, #0xec
	mov r2, #0xc
	mov r3, #0x66
	bl ov96_021EB36C
	ldr r0, [r4]
	bl ov96_021EB3A4
	mov r0, #0
	str r0, [sp, #0x54]
	mov r7, #7
_02210EF6:
	ldr r0, [sp, #0x54]
	mov r1, #3
	bl _s32_div_f
	add r5, r0, #0
	ldr r0, [sp, #0x54]
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x5d
	lsl r0, r0, #2
	mul r0, r5
	add r2, r4, r0
	mov r0, #0x7c
	mul r0, r1
	add r5, r2, r0
	mov r0, #2
	str r0, [sp]
	mov r1, #1
	ldr r0, [r4]
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	mov r1, #5
	str r0, [r5, #0x60]
	bl ov96_021EB630
	mov r6, #0
_02210F30:
	str r7, [sp]
	mov r1, #1
	ldr r0, [r4]
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	mov r1, #0x2f
	str r0, [r5, #0x64]
	bl ov96_021EB630
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #3
	blt _02210F30
	ldr r0, [sp, #0x54]
	add r0, r0, #1
	str r0, [sp, #0x54]
	cmp r0, #0xc
	blt _02210EF6
	ldr r0, _022110A0 ; =0x0000062C
	mov r6, #0
	add r5, r4, r0
	add r7, sp, #0xf0
_02210F60:
	mov r0, #0
	str r0, [r7]
	str r0, [r7, #4]
	str r0, [r7, #8]
	mov r0, #3
	str r0, [sp]
	mov r1, #1
	ldr r0, [r4]
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	str r0, [r5]
	mov r0, #8
	str r0, [sp]
	mov r1, #1
	ldr r0, [r4]
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	str r0, [r5, #4]
	ldr r0, [r5]
	mov r1, #0xa
	bl ov96_021EB564
	ldr r0, [r5, #4]
	mov r1, #0xd
	bl ov96_021EB564
	ldr r0, [r5]
	mov r1, #0x2e
	bl ov96_021EB630
	ldr r0, [r5, #4]
	mov r1, #0x2d
	bl ov96_021EB630
	add r0, r5, #0
	bl ov96_02213444
	add r1, r5, #0
	add r1, #0x39
	mov r0, #0
	strb r0, [r1]
	mov r0, #2
	lsl r0, r0, #0x12
	str r0, [sp, #0xf0]
	mov r0, #0x1a
	lsl r0, r0, #0xe
	str r0, [sp, #0xf4]
	ldr r0, [r5]
	add r1, r7, #0
	bl ov96_021EB588
	ldr r0, [r5, #4]
	add r1, r7, #0
	bl ov96_021EB588
	add r3, sp, #0xf0
	add r2, r5, #0
	ldmia r3!, {r0, r1}
	add r2, #8
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, r5, #0
	str r0, [r2]
	add r1, #0x42
	mov r0, #7
	strb r0, [r1]
	cmp r6, #0
	bne _02211002
	mov r1, #1
	ldr r0, [r5]
	add r2, r1, #0
	bl ov96_021EB52C
	add r1, r5, #0
	add r1, #0x38
	mov r0, #1
	strb r0, [r1]
_02211002:
	add r6, r6, #1
	add r5, #0x4c
	cmp r6, #2
	blt _02210F60
	ldr r1, _022110A4 ; =ov96_0221D1F4
	add r0, sp, #0x68
	ldrh r2, [r1, #0xc]
	ldr r5, _022110A8 ; =ov96_0221D3D8
	add r3, sp, #0xc0
	strh r2, [r0, #8]
	ldrh r2, [r1, #0xe]
	strh r2, [r0, #0xa]
	ldrh r2, [r1, #0x10]
	ldrh r1, [r1, #0x12]
	strh r2, [r0, #0xc]
	strh r1, [r0, #0xe]
	mov r2, #6
_02211024:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02211024
	mov r0, #0
	str r0, [sp, #0x20]
	add r0, sp, #0xc0
	str r0, [sp, #0x38]
	add r0, sp, #0x70
	str r0, [sp, #0x34]
	mov r0, #2
	str r0, [sp, #0x30]
	ldr r0, _022110AC ; =ov96_0221D4B4
	str r4, [sp, #0x3c]
	str r0, [sp, #0x2c]
	ldr r0, _022110B0 ; =ov96_0221D3A8
	str r0, [sp, #0x28]
_02211046:
	mov r0, #5
	str r0, [sp]
	mov r1, #1
	ldr r0, [r4]
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	ldr r2, _022110B4 ; =0x000006C4
	ldr r1, [sp, #0x3c]
	str r0, [r1, r2]
	add r0, r1, #0
	ldr r0, [r0, r2]
	mov r1, #1
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r1, _022110B4 ; =0x000006C4
	ldr r0, [sp, #0x3c]
	ldr r0, [r0, r1]
	mov r1, #1
	bl ov96_021EB564
	ldr r1, _022110B4 ; =0x000006C4
	b _022110B8
	.balign 4, 0
_02211078: .word 0xFFFFE0FF
_0221107C: .word 0x04001000
_02211080: .word 0x0000081C
_02211084: .word 0x00300010
_02211088: .word gSystem + 0x60
_0221108C: .word 0x0000074C
_02211090: .word 0x00000AAF
_02211094: .word 0x00000744
_02211098: .word ov96_0221D238
_0221109C: .word 0x00000748
_022110A0: .word 0x0000062C
_022110A4: .word ov96_0221D1F4
_022110A8: .word ov96_0221D3D8
_022110AC: .word ov96_0221D4B4
_022110B0: .word ov96_0221D3A8
_022110B4: .word 0x000006C4
_022110B8:
	ldr r0, [sp, #0x3c]
	ldr r0, [r0, r1]
	ldr r1, [sp, #0x38]
	bl ov96_021EB588
	ldr r1, _02211428 ; =0x000006C4
	ldr r0, [sp, #0x3c]
	mov r2, #1
	ldr r0, [r0, r1]
	ldr r1, [sp, #0x34]
	ldrh r1, [r1]
	bl ov96_021EB5AC
	ldr r1, _02211428 ; =0x000006C4
	ldr r0, [sp, #0x3c]
	ldr r0, [r0, r1]
	mov r1, #3
	bl ov96_021EB630
	ldr r7, [sp, #0x2c]
	mov r6, #0
_022110E2:
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	ldr r0, [r4]
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	mov r1, #1
	add r2, r1, #0
	add r5, r0, #0
	bl ov96_021EB52C
	ldr r1, [sp, #0x30]
	add r0, r5, #0
	add r1, r6, r1
	bl ov96_021EB564
	add r0, r5, #0
	add r1, r7, #0
	bl ov96_021EB588
	add r0, r5, #0
	mov r1, #0x67
	bl ov96_021EB630
	add r6, r6, #1
	add r7, #0xc
	cmp r6, #2
	blt _022110E2
	mov r0, #0xb
	str r0, [sp]
	mov r1, #1
	ldr r0, [r4]
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	ldr r2, _0221142C ; =0x000006D4
	ldr r1, [sp, #0x3c]
	str r0, [r1, r2]
	add r0, r1, #0
	ldr r0, [r0, r2]
	ldr r1, [sp, #0x28]
	bl ov96_021EB588
	ldr r1, _0221142C ; =0x000006D4
	ldr r0, [sp, #0x3c]
	ldr r0, [r0, r1]
	mov r1, #2
	bl ov96_021EB630
	mov r0, #0xc
	str r0, [sp]
	mov r1, #1
	ldr r0, [r4]
	add r2, r1, #0
	mov r3, #0x65
	bl ov96_021EB3E4
	ldr r2, _02211430 ; =0x000006E4
	ldr r1, [sp, #0x3c]
	str r0, [r1, r2]
	add r0, r1, #0
	ldr r0, [r0, r2]
	ldr r1, [sp, #0x38]
	bl ov96_021EB588
	ldr r1, _02211430 ; =0x000006E4
	ldr r0, [sp, #0x3c]
	ldr r0, [r0, r1]
	mov r1, #0x66
	bl ov96_021EB630
	ldr r0, [sp, #0x3c]
	add r0, r0, #4
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x38]
	add r0, #0xc
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x34]
	add r0, r0, #2
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x30]
	add r0, r0, #2
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x2c]
	add r0, #0x18
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x28]
	add r0, #0xc
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x20]
	add r0, r0, #1
	str r0, [sp, #0x20]
	cmp r0, #4
	bge _022111A6
	b _02211046
_022111A6:
	ldr r2, _02211434 ; =0x00000744
	ldr r0, [sp, #0x14]
	ldr r2, [r4, r2]
	ldr r3, [r4]
	mov r1, #0
	bl ov96_021E6290
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_SetDrawPriority
	mov r2, #0x75
	lsl r2, r2, #4
	ldr r1, [r4, r2]
	sub r2, #0xc
	ldr r0, [r4]
	ldr r2, [r4, r2]
	bl ov96_02214718
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	b _02211626
_022111D4:
	mov r5, #0
	add r7, sp, #0x1d4
	add r6, sp, #0x190
_022111DA:
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	str r1, [sp, #0x1c]
	add r0, r5, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x58]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x58]
	ldr r2, [sp, #0x1c]
	add r3, r7, #0
	bl ov96_021E6168
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x58]
	ldr r2, [sp, #0x1c]
	bl ov96_021E60C0
	bl ov96_021E6108
	str r0, [r6, #0x14]
	add r5, r5, #1
	add r7, #0x10
	add r6, r6, #4
	cmp r5, #0xc
	blt _022111DA
	mov r0, #1
	mov r1, #0
	str r1, [sp, #0x190]
	str r0, [sp, #0x194]
	str r1, [sp, #0x198]
	str r0, [sp, #0x19c]
	str r0, [sp, #0x1a0]
	str r1, [sp]
	str r1, [sp, #4]
	ldr r0, _02211438 ; =0x00000748
	mov r1, #0xc
	ldr r0, [r4, r0]
	add r2, sp, #0x1d4
	add r3, sp, #0x190
	bl ov96_021EA8A8
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	b _02211626
_0221123C:
	ldr r0, _02211438 ; =0x00000748
	ldr r0, [r4, r0]
	bl ov96_021EAA00
	cmp r0, #0
	bne _0221124A
	b _02211626
_0221124A:
	ldr r0, [sp, #0x14]
	bl ov96_021E5F24
	str r0, [sp, #0x50]
	ldr r0, [r4, #4]
	bl PokeathlonCourse_SetVBlankIntrCB
	ldr r0, [sp, #0x14]
	mov r1, #1
	bl PokeathlonCourse_SetField1F4
	add r0, sp, #0x9c
	mov r1, #0xaa
	mov r2, #0xb
	bl ReadWholeNarcMemberByIdPair
	add r0, r4, #0
	str r0, [sp, #0x60]
	add r0, #0x5c
	mov r7, #0
	str r0, [sp, #0x60]
_02211274:
	ldr r0, _02211438 ; =0x00000748
	lsl r1, r7, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	mov r1, #1
	add r5, r0, #0
	bl ov96_021EAB38
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	add r6, r0, #0
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	ldr r0, [sp, #0x14]
	add r1, r6, #0
	bl ov96_021E60C0
	bl ov96_021E6138
	lsl r1, r0, #3
	add r0, sp, #0x9c
	add r2, r0, r1
	add r1, r2, #0
	sub r1, #8
	sub r2, r2, #4
	ldr r1, [r1]
	ldr r2, [r2]
	add r0, r5, #0
	bl ov96_021EAF70
	ldr r0, _02211438 ; =0x00000748
	lsl r1, r7, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r5, r0, #0
	bl ov96_021EAA20
	str r0, [sp, #0x5c]
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	str r1, [sp, #0x18]
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	mov r1, #0x5d
	lsl r1, r1, #2
	str r0, [sp, #0x24]
	mul r1, r0
	ldr r0, [sp, #0x60]
	ldr r2, [sp, #0x18]
	add r0, r0, r1
	mov r1, #0x7c
	mul r1, r2
	add r6, r0, r1
	str r5, [r0, r1]
	add r0, r5, #0
	bl ov96_021EAF8C
	str r0, [r6, #0x20]
	mov r0, #0
	str r0, [r6, #0x78]
	ldr r0, [sp, #0x5c]
	bl ov96_021E90FC
	ldr r1, [sp, #0x24]
	mov r0, #0xc
	add r2, r1, #0
	mul r2, r0
	ldr r0, _0221143C ; =ov96_0221D408
	ldr r1, [sp, #0x18]
	add r0, r0, r2
	lsl r2, r1, #2
	add r1, r0, r2
	ldrh r0, [r0, r2]
	str r0, [sp, #0x4c]
	ldrh r0, [r1, #2]
	str r0, [sp, #0x48]
	add r1, r6, #0
	add r1, #0x5c
	mov r0, #2
	strh r0, [r1]
	add r0, r5, #0
	mov r1, #2
	bl ov96_021EAC0C
	ldr r1, [sp, #0x4c]
	ldr r2, [sp, #0x48]
	add r0, r5, #0
	bl ov96_021EAF94
	bl ov96_021E6104
	add r1, r0, #0
	add r0, r5, #0
	bl ov96_021EAF6C
	add r0, sp, #0x68
	str r0, [sp]
	ldr r1, [sp, #0x4c]
	ldr r2, [sp, #0x48]
	add r0, r5, #0
	add r3, sp, #0x6c
	bl ov96_021EB0A4
	ldr r0, [sp, #0x6c]
	lsl r0, r0, #0xc
	str r0, [r6, #0x14]
	ldr r0, [sp, #0x68]
	lsl r0, r0, #0xc
	str r0, [r6, #0x18]
	ldr r0, [sp, #0x6c]
	lsl r0, r0, #0xc
	str r0, [r6, #0x30]
	ldr r0, [sp, #0x68]
	lsl r0, r0, #0xc
	str r0, [r6, #0x34]
	ldr r0, [sp, #0x6c]
	lsl r0, r0, #0xc
	str r0, [r6, #0x24]
	ldr r0, [sp, #0x68]
	lsl r0, r0, #0xc
	str r0, [r6, #0x28]
	ldr r0, [sp, #0x14]
	bl ov96_021E5F24
	ldr r1, [sp, #0x24]
	cmp r1, r0
	bne _02211396
	add r0, r5, #0
	mov r1, #8
	bl ov96_021EABA8
	b _0221139E
_02211396:
	add r0, r5, #0
	mov r1, #0x10
	bl ov96_021EABA8
_0221139E:
	add r0, r5, #0
	mov r1, #0x14
	bl ov96_021EABDC
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x50]
	cmp r1, r0
	bne _022113D8
	ldr r0, [sp, #0x18]
	ldr r3, [sp, #0x6c]
	lsl r0, r0, #2
	add r1, sp, #0xb4
	add r2, sp, #0xb4
	add r1, r1, r0
	strh r3, [r2, r0]
	ldr r0, [sp, #0x68]
	strh r0, [r1, #2]
	ldr r0, [r4]
	bl ov96_021EB5E8
	add r3, r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r2, _02211434 ; =0x00000744
	ldr r0, [sp, #0x14]
	ldr r2, [r4, r2]
	add r1, r5, #0
	bl ov96_021E64F8
_022113D8:
	add r7, r7, #1
	cmp r7, #0xc
	bge _022113E0
	b _02211274
_022113E0:
	mov r0, #1
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	add r0, sp, #0xb4
	str r0, [sp, #8]
	ldr r2, _02211434 ; =0x00000744
	ldr r0, [sp, #0x14]
	ldr r2, [r4, r2]
	ldr r3, [r4]
	mov r1, #0
	bl ov96_021E634C
	ldr r0, [sp, #0x14]
	bl ov96_021E5F24
	cmp r0, #0
	beq _02211406
	b _022115A0
_02211406:
	add r0, sp, #0x118
	mov r1, #0xaa
	mov r2, #8
	bl ReadWholeNarcMemberByIdPair
	mov r0, #0
	str r0, [sp, #0x44]
	add r0, r4, #0
	str r0, [sp, #0x40]
	add r0, #0x5c
	ldr r7, [sp, #0x44]
	str r0, [sp, #0x40]
_0221141E:
	ldr r0, [sp, #0x44]
	mov r1, #0xc
	add r2, r4, r0
	ldr r0, _02211440 ; =0x00000734
	b _02211444
	.balign 4, 0
_02211428: .word 0x000006C4
_0221142C: .word 0x000006D4
_02211430: .word 0x000006E4
_02211434: .word 0x00000744
_02211438: .word 0x00000748
_0221143C: .word ov96_0221D408
_02211440: .word 0x00000734
_02211444:
	ldr r6, [sp, #0x40]
	strb r1, [r2, r0]
	ldr r0, [sp, #0x44]
	mov r5, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x64]
_02211452:
	lsl r3, r5, #0x18
	ldr r0, [sp, #0x14]
	ldr r2, [sp, #0x64]
	add r1, sp, #0x118
	lsr r3, r3, #0x18
	str r6, [sp]
	bl ov96_0221359C
	ldr r0, _02211630 ; =0x0000074C
	add r1, r5, r7
	lsl r1, r1, #0x18
	ldr r0, [r4, r0]
	lsr r1, r1, #0x18
	add r2, r6, #0
	bl ov96_02214A6C
	add r5, r5, #1
	add r6, #0x7c
	cmp r5, #3
	blt _02211452
	mov r0, #0x5d
	ldr r1, [sp, #0x40]
	lsl r0, r0, #2
	add r0, r1, r0
	str r0, [sp, #0x40]
	ldr r0, [sp, #0x44]
	add r7, r7, #3
	add r0, r0, #1
	str r0, [sp, #0x44]
	cmp r0, #4
	blt _0221141E
	ldr r0, _02211630 ; =0x0000074C
	ldr r1, _02211634 ; =0x0000062C
	ldr r0, [r4, r0]
	add r1, r4, r1
	bl ov96_02214B74
	ldr r0, _02211630 ; =0x0000074C
	ldr r0, [r4, r0]
	bl ov96_02214A9C
	ldr r5, _02211638 ; =ov96_0221D220
	add r3, sp, #0x90
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [r3]
	add r0, r2, #0
	bl VEC_Normalize
	ldr r3, _0221163C ; =ov96_0221D250
	add r2, sp, #0x84
	add r6, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r7, #0
	str r0, [r2]
	add r5, r6, #0
	ldr r2, _02211640 ; =0x00000754
	ldmia r5!, {r0, r1}
	add r3, r4, r2
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mvn r7, r7
	str r0, [r3]
	add r0, r2, #0
	add r0, #0xc
	add r5, r4, r0
	ldmia r6!, {r0, r1}
	add r3, r5, #0
	stmia r5!, {r0, r1}
	ldr r0, [r6]
	str r0, [r5]
	ldr r0, [r3]
	ldr r5, _02211644 ; =ov96_0221D208
	add r1, r0, #0
	mul r1, r7
	str r1, [r3]
	add r3, sp, #0x78
	ldmia r5!, {r0, r1}
	add r6, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r5, r6, #0
	str r0, [r3]
	add r0, r2, #0
	add r0, #0x18
	add r3, r4, r0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r5, sp, #0x90
	str r0, [r3]
	add r0, r2, #0
	add r0, #0x24
	add r3, r4, r0
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	add r6, sp, #0x90
	str r0, [r3]
	add r0, r2, #0
	add r0, #0x28
	ldr r0, [r4, r0]
	add r1, r0, #0
	add r0, r2, #0
	mul r1, r7
	add r0, #0x28
	str r1, [r4, r0]
	add r0, r2, #0
	add r0, #0x30
	add r3, r4, r0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	str r0, [r3]
	add r0, r2, #0
	add r0, #0x3c
	add r5, r4, r0
	ldmia r6!, {r0, r1}
	add r3, r5, #0
	stmia r5!, {r0, r1}
	ldr r0, [r6]
	str r0, [r5]
	ldr r0, [r3]
	add r5, sp, #0x90
	add r1, r0, #0
	add r0, r2, #0
	mul r1, r7
	add r0, #0x48
	str r1, [r3]
	add r3, r4, r0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	str r0, [r3]
	add r0, r2, #0
	add r0, #0x4c
	ldr r0, [r4, r0]
	add r1, r0, #0
	add r0, r2, #0
	mul r1, r7
	add r0, #0x4c
	str r1, [r4, r0]
	add r0, r2, #0
	add r0, #0x54
	add r5, r4, r0
	add r6, sp, #0x90
	ldmia r6!, {r0, r1}
	add r3, r5, #0
	stmia r5!, {r0, r1}
	ldr r0, [r6]
	str r0, [r5]
	ldr r0, [r3]
	add r1, r0, #0
	add r0, r2, #0
	mul r1, r7
	str r1, [r3]
	add r0, #0x58
	ldr r0, [r4, r0]
	add r2, #0x58
	add r1, r0, #0
	mul r1, r7
	str r1, [r4, r2]
_022115A0:
	ldr r0, [sp, #0x14]
	bl ov96_021E5F24
	cmp r0, #0
	bne _022115BE
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0x28
	bl ov96_021E8A20
	add r1, r0, #0
	add r0, r4, #0
	bl ov96_02211DE4
_022115BE:
	add r0, r4, #0
	bl ov96_02211A24
	mov r0, #0x75
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ov96_022147FC
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, _02211648 ; =0x00000A8C
	ldr r1, _0221164C ; =0x00000738
	str r0, [r4, r1]
	add r0, r1, #0
	add r0, #0x18
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	bl ov96_0221490C
	mov r0, #2
	bl sub_0203A994
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4, #0x58]
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	ldr r0, [sp, #0x14]
	bl PokeathlonCourse_IncrementField1ED
	b _02211626
_02211616:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02211626
	add sp, #0x1fc
	add sp, #0x98
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02211626:
	mov r0, #0
	add sp, #0x1fc
	add sp, #0x98
	pop {r4, r5, r6, r7, pc}
	nop
_02211630: .word 0x0000074C
_02211634: .word 0x0000062C
_02211638: .word ov96_0221D220
_0221163C: .word ov96_0221D250
_02211640: .word 0x00000754
_02211644: .word ov96_0221D208
_02211648: .word 0x00000A8C
_0221164C: .word 0x00000738
	thumb_func_end ov96_02210C98

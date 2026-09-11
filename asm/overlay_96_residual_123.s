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

	thumb_func_start ov96_02219FE4
ov96_02219FE4: ; 0x02219FE4
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r0, #0x2c
	ldrb r0, [r0]
	mov r4, #0
	cmp r0, #0
	ble _0221A00A
	add r5, r6, #0
	add r5, #8
_02219FF6:
	add r0, r5, #0
	bl ov96_0221A400
	add r0, r6, #0
	add r0, #0x2c
	ldrb r0, [r0]
	add r4, r4, #1
	add r5, #0xc
	cmp r4, r0
	blt _02219FF6
_0221A00A:
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_02219FE4


	thumb_func_start ov96_0221A00C
ov96_0221A00C: ; 0x0221A00C
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r6, r2, #0
	add r5, r0, #0
	mov r1, #0
	mov r2, #0xc
	bl MI_CpuFill8
	str r6, [r5]
	ldr r1, [r5, #8]
	mov r0, #3
	bic r1, r0
	mov r0, #3
	and r0, r4
	orr r1, r0
	mov r0, #0xc
	bic r1, r0
	str r1, [r5, #8]
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_0221A00C


	thumb_func_start ov96_0221A034
ov96_0221A034: ; 0x0221A034
	push {r3, r4, lr}
	sub sp, #0xc
	add r3, r0, #0
	add r4, r2, #0
	add r0, r1, #0
	add r1, r3, #0
	add r2, sp, #0
	bl VEC_Subtract
	add r0, sp, #0
	bl VEC_Mag
	cmp r0, r4
	bgt _0221A056
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_0221A056:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	thumb_func_end ov96_0221A034


	thumb_func_start ov96_0221A05C
ov96_0221A05C: ; 0x0221A05C
	push {r3, r4, lr}
	sub sp, #0xc
	add r3, r0, #0
	add r4, r2, #0
	add r0, r1, #0
	add r1, r3, #0
	add r2, sp, #0
	bl VEC_Subtract
	add r0, sp, #0
	add r1, r0, #0
	bl VEC_Normalize
	add r0, sp, #0
	bl ov96_02215FA0
	cmp r4, r0
	bne _0221A086
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_0221A086:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	thumb_func_end ov96_0221A05C


	thumb_func_start ov96_0221A08C
ov96_0221A08C: ; 0x0221A08C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r5, r0, #0
	mov r0, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r1, sp, #0x28
	strb r0, [r1]
	ldr r0, [sp, #0x10]
	strb r0, [r1, #1]
	ldr r0, [sp, #0x10]
	strb r0, [r1, #2]
	ldr r0, [sp, #0x10]
	strb r0, [r1, #3]
	ldr r1, [r5, #8]
	ldr r0, [r5]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215DD4
	ldr r1, [r5, #8]
	add r6, r0, #0
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	ldr r0, [r5]
	lsr r1, r1, #0x18
	bl ov96_02215E2C
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r7, #0
	add r4, sp, #0x28
	str r0, [sp, #0x18]
_0221A0D6:
	ldr r0, [r5, #8]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	cmp r7, r0
	beq _0221A14A
	lsl r1, r7, #0x18
	ldr r0, [r5]
	lsr r1, r1, #0x18
	bl ov96_02215DD4
	str r0, [sp, #0x14]
	mov r2, #2
	ldr r1, [sp, #0x14]
	add r0, r6, #0
	lsl r2, r2, #0x10
	bl ov96_0221A034
	cmp r0, #0
	beq _0221A11E
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	add r0, r6, #0
	bl ov96_0221A05C
	cmp r0, #0
	beq _0221A10E
	mov r0, #3
	b _0221A110
_0221A10E:
	mov r0, #1
_0221A110:
	strb r0, [r4]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	b _0221A14A
_0221A11E:
	mov r2, #3
	ldr r1, [sp, #0x14]
	add r0, r6, #0
	lsl r2, r2, #0x10
	bl ov96_0221A034
	cmp r0, #0
	beq _0221A14A
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	add r0, r6, #0
	bl ov96_0221A05C
	cmp r0, #0
	beq _0221A140
	mov r0, #2
	strb r0, [r4]
_0221A140:
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
_0221A14A:
	add r7, r7, #1
	add r4, r4, #1
	cmp r7, #4
	blt _0221A0D6
	mov r4, #0
	add r0, sp, #0x24
	strb r4, [r0]
	strb r4, [r0, #1]
	strb r4, [r0, #2]
	strb r4, [r0, #3]
	add r1, r4, #0
	add r0, sp, #0x28
	add r2, sp, #0x1c
_0221A164:
	ldr r3, [r5, #8]
	lsl r3, r3, #0x1e
	lsr r3, r3, #0x1e
	cmp r1, r3
	beq _0221A17C
	ldrb r6, [r2, #9]
	ldrb r3, [r0]
	cmp r6, r3
	bhs _0221A17C
	strb r1, [r2, #8]
	ldrb r3, [r0]
	strb r3, [r2, #9]
_0221A17C:
	add r1, r1, #1
	add r0, r0, #1
	cmp r1, #4
	blt _0221A164
	bl MTRandom
	mov r1, #0x64
	bl _u32_div_f
	add r2, sp, #0x1c
	ldrb r3, [r2, #9]
	ldr r0, _0221A308 ; =ov96_0221D97C
	ldrb r0, [r0, r3]
	add r0, r4, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r1, r0
	bge _0221A1D0
	ldrb r1, [r2, #8]
	ldr r0, [r5]
	bl ov96_02215DD4
	ldr r1, [r0]
	asr r2, r1, #0xc
	add r1, sp, #0x1c
	strh r2, [r1, #4]
	ldr r0, [r0, #4]
	add r2, sp, #0x20
	asr r0, r0, #0xc
	strh r0, [r1, #6]
	ldr r1, [r5, #8]
	ldr r0, [r5]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215EE8
	mov r0, #0x10
	add sp, #0x2c
	strb r0, [r5, #4]
	pop {r4, r5, r6, r7, pc}
_0221A1D0:
	bl MTRandom
	mov r1, #0x64
	bl _u32_div_f
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _0221A1E6
	add r0, r4, #5
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_0221A1E6:
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq _0221A1F8
	sub r2, r0, #1
	ldr r0, _0221A30C ; =ov96_0221D978
	ldrb r0, [r0, r2]
	add r0, r4, r0
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_0221A1F8:
	cmp r1, r4
	bge _0221A214
	ldr r1, [r5, #8]
	ldr r0, [r5]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215F2C
	mov r0, #0x14
	add sp, #0x2c
	strb r0, [r5, #4]
	pop {r4, r5, r6, r7, pc}
_0221A214:
	bl MTRandom
	mov r1, #0x64
	bl _u32_div_f
	cmp r1, #0x3c
	bge _0221A2BC
	bl MTRandom
	mov r1, #0x64
	bl _u32_div_f
	ldr r0, [r5, #8]
	str r1, [sp]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1f
	bne _0221A302
	mov r7, #0
	mvn r7, r7
	ldr r0, _0221A310 ; =0x000003E7
	str r7, [sp, #8]
	str r0, [sp, #4]
	mov r4, #0
_0221A242:
	lsl r1, r4, #0x18
	ldr r0, [r5]
	lsr r1, r1, #0x18
	bl ov96_02215E48
	add r6, r0, #0
	lsl r1, r4, #0x18
	ldr r0, [r5]
	lsr r1, r1, #0x18
	bl ov96_02215DBC
	ldr r1, [r5, #8]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	cmp r4, r1
	beq _0221A284
	cmp r0, #3
	beq _0221A284
	cmp r0, #4
	beq _0221A284
	ldrb r1, [r5, #7]
	ldr r0, [r5]
	bl ov96_02215E94
	cmp r0, #0
	bne _0221A284
	ldr r0, [sp, #4]
	cmp r0, r6
	ble _0221A284
	str r7, [sp, #8]
	lsl r0, r4, #0x18
	asr r7, r0, #0x18
	str r6, [sp, #4]
_0221A284:
	add r4, r4, #1
	cmp r4, #4
	blt _0221A242
	ldr r0, [sp]
	cmp r0, #0x3c
	bge _0221A294
	strb r7, [r5, #7]
	b _0221A2A2
_0221A294:
	cmp r0, #0x64
	bge _0221A29E
	ldr r0, [sp, #8]
	strb r0, [r5, #7]
	b _0221A2A2
_0221A29E:
	bl GF_AssertFail
_0221A2A2:
	mov r0, #7
	ldrsb r1, [r5, r0]
	sub r0, #8
	cmp r1, r0
	beq _0221A302
	ldr r1, [r5, #8]
	mov r0, #0x20
	orr r0, r1
	str r0, [r5, #8]
	mov r0, #0
	add sp, #0x2c
	strb r0, [r5, #4]
	pop {r4, r5, r6, r7, pc}
_0221A2BC:
	cmp r1, #0x50
	bge _0221A2C8
	mov r0, #0xa
	add sp, #0x2c
	strb r0, [r5, #4]
	pop {r4, r5, r6, r7, pc}
_0221A2C8:
	cmp r1, #0x64
	bge _0221A302
	bl MTRandom
	mov r1, #0x91
	bl _u32_div_f
	add r1, #0x38
	add r0, sp, #0x1c
	strh r1, [r0]
	bl MTRandom
	mov r1, #0x50
	bl _u32_div_f
	add r1, #0x48
	add r0, sp, #0x1c
	strh r1, [r0, #2]
	ldr r1, [r5, #8]
	ldr r0, [r5]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r2, sp, #0x1c
	bl ov96_02215F80
	mov r0, #0xa
	strb r0, [r5, #4]
_0221A302:
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	nop
_0221A308: .word ov96_0221D97C
_0221A30C: .word ov96_0221D978
_0221A310: .word 0x000003E7
	thumb_func_end ov96_0221A08C


	thumb_func_start ov96_0221A314
ov96_0221A314: ; 0x0221A314
	push {r4, r5, r6, lr}
	sub sp, #0x18
	add r5, r0, #0
	ldr r0, [r5, #8]
	add r2, sp, #0xc
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	lsl r4, r0, #2
	mov r1, #0
	add r0, sp, #0
	str r1, [r2]
	str r1, [r0]
	str r1, [r2, #4]
	str r1, [r0, #4]
	str r1, [r2, #8]
	str r1, [r0, #8]
	ldr r1, [r5, #8]
	ldr r0, [r5]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	ldr r6, _0221A3A4 ; =ov96_0221D98C
	bl ov96_02215DEC
	ldr r0, [r5, #8]
	add r2, r6, r4
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	lsl r1, r0, #2
	add r0, r6, #0
	ldrsh r0, [r0, r1]
	lsl r0, r0, #0xc
	str r0, [sp]
	ldr r0, [r5, #8]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1e
	lsl r1, r0, #2
	ldr r0, _0221A3A8 ; =ov96_0221D98E
	ldrsh r0, [r0, r1]
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	ldr r1, [r5, #8]
	ldr r0, [r5]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215F80
	mov r2, #1
	add r0, sp, #0xc
	add r1, sp, #0
	lsl r2, r2, #0x12
	bl ov96_0221A034
	cmp r0, #0
	beq _0221A3A0
	ldr r1, [r5, #8]
	ldr r0, [r5]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215F64
	ldr r1, [r5, #8]
	mov r0, #0x10
	bic r1, r0
	str r1, [r5, #8]
_0221A3A0:
	add sp, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0221A3A4: .word ov96_0221D98C
_0221A3A8: .word ov96_0221D98E
	thumb_func_end ov96_0221A314


	thumb_func_start ov96_0221A3AC
ov96_0221A3AC: ; 0x0221A3AC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl MTRandom
	mov r1, #0x64
	bl _u32_div_f
	add r6, r1, #0
	ldr r1, [r5, #8]
	ldr r0, [r5]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	mov r4, #0
	bl ov96_02215E68
	cmp r0, #0xa
	bhs _0221A3D6
	mov r4, #0x64
	b _0221A3F4
_0221A3D6:
	cmp r0, #0x14
	bhs _0221A3DE
	mov r4, #0x46
	b _0221A3F4
_0221A3DE:
	cmp r0, #0x1e
	bhs _0221A3E6
	mov r4, #0x32
	b _0221A3F4
_0221A3E6:
	cmp r0, #0x28
	bhs _0221A3EE
	mov r4, #0x1e
	b _0221A3F4
_0221A3EE:
	cmp r0, #0x32
	bhs _0221A3F4
	mov r4, #0xa
_0221A3F4:
	cmp r6, r4
	bge _0221A3FC
	mov r0, #1
	pop {r4, r5, r6, pc}
_0221A3FC:
	mov r0, #0
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_0221A3AC


	thumb_func_start ov96_0221A400
ov96_0221A400: ; 0x0221A400
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r1, [r4, #8]
	ldr r0, [r4]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215E94
	cmp r0, #0
	beq _0221A41A
	b _0221A568
_0221A41A:
	ldr r1, [r4, #8]
	lsl r0, r1, #0x1a
	lsr r0, r0, #0x1f
	beq _0221A4C4
	lsl r0, r1, #0x1b
	lsr r0, r0, #0x1f
	bne _0221A4C4
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	ldr r0, [r4]
	lsr r1, r1, #0x18
	bl ov96_02215DBC
	ldrb r1, [r4, #7]
	ldr r0, [r4]
	bl ov96_02215DBC
	cmp r0, #3
	beq _0221A462
	ldrb r1, [r4, #7]
	ldr r0, [r4]
	bl ov96_02215E94
	cmp r0, #0
	bne _0221A462
	ldr r1, [r4, #8]
	ldr r0, [r4]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215EB0
	cmp r0, #0
	beq _0221A49C
_0221A462:
	ldr r1, [r4, #8]
	ldr r0, [r4]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215DD4
	ldr r1, [r0]
	asr r2, r1, #0xc
	add r1, sp, #0
	strh r2, [r1]
	ldr r0, [r0, #4]
	add r2, sp, #0
	asr r0, r0, #0xc
	strh r0, [r1, #2]
	ldr r1, [r4, #8]
	ldr r0, [r4]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215F80
	ldr r1, [r4, #8]
	mov r0, #0x20
	bic r1, r0
	str r1, [r4, #8]
	b _0221A4C4
_0221A49C:
	ldrb r1, [r4, #7]
	ldr r0, [r4]
	bl ov96_02215DD4
	ldr r1, [r0]
	asr r2, r1, #0xc
	add r1, sp, #0
	strh r2, [r1]
	ldr r0, [r0, #4]
	add r2, sp, #0
	asr r0, r0, #0xc
	strh r0, [r1, #2]
	ldr r1, [r4, #8]
	ldr r0, [r4]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215F80
_0221A4C4:
	ldr r1, [r4, #8]
	lsl r0, r1, #0x1b
	lsr r0, r0, #0x1f
	beq _0221A504
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	ldr r0, [r4]
	lsr r1, r1, #0x18
	bl ov96_02215ECC
	cmp r0, #0
	beq _0221A568
	ldr r1, [r4, #8]
	ldr r0, [r4]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215DBC
	add r5, r0, #0
	add r0, r4, #0
	bl ov96_0221A314
	cmp r5, #3
	bne _0221A568
	ldr r1, [r4, #8]
	mov r0, #0x10
	bic r1, r0
	str r1, [r4, #8]
	pop {r3, r4, r5, pc}
_0221A504:
	mov r0, #4
	ldrsb r1, [r4, r0]
	sub r1, r1, #1
	strb r1, [r4, #4]
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bgt _0221A568
	bge _0221A518
	mov r0, #0
	strb r0, [r4, #4]
_0221A518:
	mov r0, #6
	ldrsb r1, [r4, r0]
	sub r1, r1, #1
	strb r1, [r4, #6]
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bgt _0221A568
	mov r0, #3
	strb r0, [r4, #6]
	ldr r1, [r4, #8]
	ldr r0, [r4]
	lsl r1, r1, #0x1e
	lsr r1, r1, #0x1e
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02215ECC
	cmp r0, #0
	beq _0221A568
	add r0, r4, #0
	bl ov96_0221A08C
	mov r0, #5
	ldrsb r1, [r4, r0]
	sub r1, r1, #1
	strb r1, [r4, #5]
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bgt _0221A568
	add r0, r4, #0
	bl ov96_0221A3AC
	cmp r0, #0
	beq _0221A564
	ldr r1, [r4, #8]
	mov r0, #0x10
	orr r0, r1
	str r0, [r4, #8]
_0221A564:
	mov r0, #0
	strb r0, [r4, #5]
_0221A568:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_0221A400


	thumb_func_start ov96_0221A56C
ov96_0221A56C: ; 0x0221A56C
	push {r3, lr}
	ldr r2, _0221A578 ; =ov96_0221D9A0
	lsl r3, r1, #2
	ldr r2, [r2, r3]
	blx r2
	pop {r3, pc}
	.balign 4, 0
_0221A578: .word ov96_0221D9A0
	thumb_func_end ov96_0221A56C


	thumb_func_start ov96_0221A57C
ov96_0221A57C: ; 0x0221A57C
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r0, _0221A5B4 ; =ov96_0221D9C8
	lsl r1, r1, #2
	ldr r6, [r0, r1]
	cmp r6, #0
	beq _0221A5AC
	mov r5, #0
_0221A58C:
	add r0, r7, #0
	add r1, r5, #0
	bl ov96_021E94EC
	add r4, r0, #0
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	blx r6
	strh r0, [r4, #0xa]
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #4
	blo _0221A58C
	pop {r3, r4, r5, r6, r7, pc}
_0221A5AC:
	bl GF_AssertFail
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221A5B4: .word ov96_0221D9C8
	thumb_func_end ov96_0221A57C


	thumb_func_start ov96_0221A5B8
ov96_0221A5B8: ; 0x0221A5B8
	push {r3, lr}
	lsl r2, r1, #2
	ldr r1, _0221A5D0 ; =ov96_0221D9C8
	ldr r1, [r1, r2]
	cmp r1, #0
	bne _0221A5CA
	bl ov96_0221A730
	pop {r3, pc}
_0221A5CA:
	bl GF_AssertFail
	pop {r3, pc}
	.balign 4, 0
_0221A5D0: .word ov96_0221D9C8
	thumb_func_end ov96_0221A5B8


	thumb_func_start ov96_0221A5D4
ov96_0221A5D4: ; 0x0221A5D4
	push {r4, lr}
	add r4, r1, #0
	bl _ffltu
	add r1, r4, #0
	bl _fmul
	bl _f2d
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _0221A610 ; =0x3FF00000
	mov r0, #0
	bl _dadd
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _0221A614 ; =0x405E0000
	mov r0, #0
	bl _ddiv
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _0221A618 ; =0x4062C000
	mov r0, #0
	bl _dsub
	bl _d2f
	pop {r4, pc}
	.balign 4, 0
_0221A610: .word 0x3FF00000
_0221A614: .word 0x405E0000
_0221A618: .word 0x4062C000
	thumb_func_end ov96_0221A5D4


	thumb_func_start ov96_0221A61C
ov96_0221A61C: ; 0x0221A61C
	push {r4, lr}
	bl _ffixu
	add r4, r0, #0
	bl _dfltu
	ldr r3, _0221A63C ; =0x40690000
	mov r2, #0
	bl _dgr
	bls _0221A634
	mov r4, #0xc8
_0221A634:
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	pop {r4, pc}
	nop
_0221A63C: .word 0x40690000
	thumb_func_end ov96_0221A61C


	thumb_func_start ov96_0221A640
ov96_0221A640: ; 0x0221A640
	push {r3, lr}
	bl _ffltu
	ldr r1, _0221A668 ; =0x41F00000
	bl _fdiv
	bl _f2d
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _0221A66C ; =0x40C67600
	mov r0, #0
	bl _ddiv
	bl _d2f
	bl ov96_0221A61C
	pop {r3, pc}
	nop
_0221A668: .word 0x41F00000
_0221A66C: .word 0x40C67600
	thumb_func_end ov96_0221A640

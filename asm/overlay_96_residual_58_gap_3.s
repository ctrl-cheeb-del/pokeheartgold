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

	thumb_func_start ov96_021F4B34
ov96_021F4B34: ; 0x021F4B34
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r4, #0x68
	ldrh r0, [r4, #0x1a]
	add r0, r0, #1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x1a]
	cmp r0, #0x32
	bls _021F4B4E
	add r0, r4, #0
	bl ov96_021F4724
	pop {r3, r4, r5, pc}
_021F4B4E:
	cmp r0, #5
	bne _021F4B5C
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	b _021F4B82
_021F4B5C:
	cmp r0, #0xf
	bls _021F4B82
	sub r0, #0xf
	cmp r0, #4
	bgt _021F4B82
	lsl r1, r0, #4
	asr r0, r1, #1
	lsr r0, r0, #0x1e
	add r0, r1, r0
	lsl r0, r0, #0xe
	lsr r5, r0, #0x10
	mov r3, #0x10
	ldr r0, _021F4BA8 ; =0x04001050
	mov r1, #8
	mov r2, #0x34
	sub r3, r3, r5
	str r5, [sp]
	bl G2x_SetBlendAlpha_
_021F4B82:
	ldrh r0, [r4, #0x1a]
	add r2, r4, #0
	add r2, #0x90
	lsl r0, r0, #0x18
	ldr r1, _021F4BAC ; =ov96_0221C050
	ldr r2, [r2]
	lsr r0, r0, #0x18
	bl ov96_021F4DAC
	ldrh r0, [r4, #0x1a]
	add r4, #0x94
	ldr r1, _021F4BB0 ; =ov96_0221C080
	lsl r0, r0, #0x18
	ldr r2, [r4]
	lsr r0, r0, #0x18
	bl ov96_021F4DAC
	pop {r3, r4, r5, pc}
	nop
_021F4BA8: .word 0x04001050
_021F4BAC: .word ov96_0221C050
_021F4BB0: .word ov96_0221C080
	thumb_func_end ov96_021F4B34
	thumb_func_start ov96_021F4BB4
ov96_021F4BB4: ; 0x021F4BB4
	push {r3, r4, r5, lr}
	sub sp, #0x20
	add r5, r0, #0
	add r4, r5, #0
	add r4, #0x68
	ldrh r0, [r4, #0x1a]
	add r0, r0, #1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x1a]
	cmp r0, #0x50
	bls _021F4BD4
	add r0, r4, #0
	bl ov96_021F4724
	add sp, #0x20
	pop {r3, r4, r5, pc}
_021F4BD4:
	cmp r0, #0x29
	bne _021F4BE8
	add r0, r4, #0
	add r0, #0xc4
	mov r1, #1
	ldr r0, [r0]
	add r2, r1, #0
	bl ov96_021EB52C
	b _021F4BFA
_021F4BE8:
	cmp r0, #0x3d
	bne _021F4BFA
	add r0, r4, #0
	add r0, #0xc4
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
_021F4BFA:
	ldrh r0, [r4, #0x1a]
	cmp r0, #0x28
	bhi _021F4C38
	bl _ffltu
	ldr r1, _021F4CA0 ; =0x42200000
	bl _fdiv
	add r1, r0, #0
	ldr r0, _021F4CA4 ; =0x45800000
	bl _fmul
	bl _ffix
	mov r1, #0
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	bl OS_WaitVBlankIntr
	mov r0, #0x60
	str r0, [sp]
	ldr r0, [r5, #8]
	mov r1, #7
	add r2, sp, #0x10
	mov r3, #0x80
	bl SetBgAffine
	add sp, #0x20
	pop {r3, r4, r5, pc}
_021F4C38:
	bls _021F4C6E
	cmp r0, #0x3c
	bhi _021F4C6E
	mov r1, #0
	str r1, [sp, #0xc]
	sub r0, #0x28
	mov r1, #0x90
	mul r1, r0
	add r0, r1, #0
	mov r1, #0x14
	bl _s32_div_f
	add r0, #0x38
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	mov r0, #0x29
	lsl r0, r0, #0x10
	add r4, #0xc4
	str r0, [sp, #8]
	ldr r0, [r4]
	bl ov96_021EB5B8
	add r1, sp, #4
	bl Sprite_SetMatrix
	add sp, #0x20
	pop {r3, r4, r5, pc}
_021F4C6E:
	add r0, r4, #0
	add r0, #0xc4
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	ldrh r0, [r4, #0x1a]
	mov r1, #0x14
	sub r0, #0x3c
	lsl r0, r0, #4
	bl _s32_div_f
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	mov r3, #0x10
	ldr r0, _021F4CA8 ; =0x04001050
	mov r1, #8
	mov r2, #0x24
	sub r3, r3, r4
	str r4, [sp]
	bl G2x_SetBlendAlpha_
	add sp, #0x20
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021F4CA0: .word 0x42200000
_021F4CA4: .word 0x45800000
_021F4CA8: .word 0x04001050
	thumb_func_end ov96_021F4BB4
	thumb_func_start ov96_021F4CAC
ov96_021F4CAC: ; 0x021F4CAC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	bl LCRandom
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r5, r2, r1
	mov r4, #0
_021F4CC4:
	bl LCRandom
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r6, r2, r1
	cmp r5, r6
	bne _021F4CE2
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #0xa
	blo _021F4CC4
_021F4CE2:
	cmp r4, #0xa
	bne _021F4CF4
	add r0, r5, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r6, r2, r1
_021F4CF4:
	bl LCRandom
	mov r1, #3
	bl _s32_div_f
	lsl r0, r5, #1
	add r0, r5, r0
	add r5, r0, r1
	bl LCRandom
	mov r1, #3
	bl _s32_div_f
	lsl r0, r6, #1
	add r0, r6, r0
	add r4, r0, r1
	lsl r2, r5, #0x18
	add r0, r7, #0
	mov r1, #0
	lsr r2, r2, #0x18
	bl ov96_021F4504
	lsl r2, r4, #0x18
	add r0, r7, #0
	mov r1, #1
	lsr r2, r2, #0x18
	bl ov96_021F4504
	add r0, r7, #0
	add r0, #0x90
	ldr r0, [r0]
	bl ov96_021EB5B8
	add r4, sp, #0
	ldr r5, _021F4DA4 ; =ov96_0221C050
	add r3, r0, #0
	ldmia r5!, {r0, r1}
	add r2, r4, #0
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	str r0, [r4]
	mov r0, #2
	ldr r1, [sp, #4]
	lsl r0, r0, #0x14
	add r0, r1, r0
	str r0, [sp, #4]
	add r0, r3, #0
	add r1, r2, #0
	bl Sprite_SetMatrix
	add r0, r7, #0
	add r0, #0x94
	ldr r0, [r0]
	bl ov96_021EB5B8
	add r4, sp, #0
	ldr r5, _021F4DA8 ; =ov96_0221C080
	add r3, r0, #0
	ldmia r5!, {r0, r1}
	add r2, r4, #0
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	str r0, [r4]
	mov r0, #2
	ldr r1, [sp, #4]
	lsl r0, r0, #0x14
	add r0, r1, r0
	str r0, [sp, #4]
	add r0, r3, #0
	add r1, r2, #0
	bl Sprite_SetMatrix
	add r0, r7, #0
	add r0, #0x90
	mov r1, #1
	ldr r0, [r0]
	add r2, r1, #0
	bl ov96_021EB52C
	add r7, #0x94
	mov r1, #1
	ldr r0, [r7]
	add r2, r1, #0
	bl ov96_021EB52C
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021F4DA4: .word ov96_0221C050
_021F4DA8: .word ov96_0221C080
	thumb_func_end ov96_021F4CAC
	thumb_func_start ov96_021F4DAC
ov96_021F4DAC: ; 0x021F4DAC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r4, r1, #0
	str r2, [sp]
	cmp r5, #5
	bhi _021F4DE0
	ldr r7, [r4]
	ldr r0, [r4, #0xc]
	ldr r6, [r4, #4]
	sub r1, r0, r7
	add r0, r1, #0
	mul r0, r5
	mov r1, #5
	bl _s32_div_f
	add r7, r7, r0
	ldr r0, [r4, #0x10]
	sub r1, r0, r6
	add r0, r1, #0
	mul r0, r5
	mov r1, #5
	bl _s32_div_f
	add r4, r6, r0
	b _021F4E3C
_021F4DE0:
	bls _021F4E12
	cmp r5, #0x2d
	bhi _021F4E12
	sub r0, r5, #5
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	ldr r7, [r4, #0xc]
	ldr r0, [r4, #0x18]
	ldr r6, [r4, #0x10]
	sub r1, r0, r7
	add r0, r1, #0
	mul r0, r5
	mov r1, #0x28
	bl _s32_div_f
	add r7, r7, r0
	ldr r0, [r4, #0x1c]
	sub r1, r0, r6
	add r0, r1, #0
	mul r0, r5
	mov r1, #0x28
	bl _s32_div_f
	add r4, r6, r0
	b _021F4E3C
_021F4E12:
	sub r5, #0x2d
	lsl r0, r5, #0x18
	lsr r5, r0, #0x18
	ldr r7, [r4, #0x18]
	ldr r0, [r4, #0x24]
	ldr r6, [r4, #0x1c]
	sub r1, r0, r7
	add r0, r1, #0
	mul r0, r5
	mov r1, #5
	bl _s32_div_f
	add r7, r7, r0
	ldr r0, [r4, #0x28]
	sub r1, r0, r6
	add r0, r1, #0
	mul r0, r5
	mov r1, #5
	bl _s32_div_f
	add r4, r6, r0
_021F4E3C:
	ldr r0, [sp]
	bl ov96_021EB5B8
	mov r1, #2
	lsl r1, r1, #0x14
	add r1, r4, r1
	str r1, [sp, #8]
	mov r1, #0
	str r1, [sp, #0xc]
	add r1, sp, #4
	str r7, [sp, #4]
	bl Sprite_SetMatrix
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021F4DAC

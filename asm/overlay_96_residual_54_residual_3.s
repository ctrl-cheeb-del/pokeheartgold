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
	.public ov96_021F2814
	.public ov96_021F2AA4
	.public ov96_021F2D68
	.public ov96_021F2E2C
	.public ov96_021F2E4C
	.public ov96_021F2FBC
	.public ov96_021F30A4


	thumb_func_start ov96_021F2B24
ov96_021F2B24: ; 0x021F2B24
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r1, r2, #0
	add r2, r3, #0
	ldr r4, [sp, #0x10]
	bl ov96_021E60D8
	ldrb r1, [r0]
	lsl r1, r1, #2
	ldr r2, [r5, r1]
	add r1, r4, #0
	add r1, #0x8a
	strh r2, [r1]
	ldrb r1, [r0, #3]
	lsl r1, r1, #2
	add r1, r5, r1
	ldr r2, [r1, #0x14]
	add r1, r4, #0
	add r1, #0x8c
	strh r2, [r1]
	ldrb r1, [r0, #3]
	lsl r1, r1, #2
	add r1, r5, r1
	ldr r2, [r1, #0x14]
	add r1, r4, #0
	add r1, #0x8e
	strh r2, [r1]
	ldrb r0, [r0, #1]
	add r4, #0x89
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x28]
	strb r0, [r4]
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021F2B24




	thumb_func_start ov96_021F2B68
ov96_021F2B68: ; 0x021F2B68
	push {r3, r4, r5, lr}
	add r4, r0, #0
	strh r1, [r4, #0x1c]
	strh r2, [r4, #0x1e]
	mov r2, #0
	ldr r0, _021F2BA4 ; =ov96_021F2BB4
	strb r2, [r4]
	add r1, r4, #0
	add r5, r3, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #4]
	ldr r0, _021F2BA8 ; =ov96_021F2C04
	add r1, r4, #0
	mov r2, #1
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #0xc]
	mov r1, #2
	ldr r0, _021F2BAC ; =0x04000018
	str r5, [r4, #0x30]
	lsl r1, r1, #0x16
	str r1, [r0]
	ldr r0, _021F2BB0 ; =ov96_021F2CD0
	add r1, r4, #0
	mov r2, #2
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #8]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021F2BA4: .word ov96_021F2BB4
_021F2BA8: .word ov96_021F2C04
_021F2BAC: .word 0x04000018
_021F2BB0: .word ov96_021F2CD0
	thumb_func_end ov96_021F2B68




	thumb_func_start ov96_021F2BB4
ov96_021F2BB4: ; 0x021F2BB4
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _021F2BC6
	cmp r0, #1
	beq _021F2BDE
	pop {r3, r4, r5, pc}
_021F2BC6:
	ldr r0, [r4, #8]
	cmp r0, #0
	bne _021F2BFE
	ldr r0, _021F2C00 ; =ov96_021F2D68
	mov r2, #3
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #0x10]
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	pop {r3, r4, r5, pc}
_021F2BDE:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _021F2BFE
	mov r0, #0
	str r0, [r4, #4]
	strb r0, [r4]
	ldr r0, [r4, #0x30]
	bl PokeathlonCourse_GetDataCopyArea
	bl ov96_021E8A20
	mov r1, #1
	strb r1, [r0, #8]
	add r0, r5, #0
	bl SysTask_Destroy
_021F2BFE:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021F2C00: .word ov96_021F2D68
	thumb_func_end ov96_021F2BB4




	thumb_func_start ov96_021F2C04
ov96_021F2C04: ; 0x021F2C04
	push {r3, r4, lr}
	sub sp, #4
	add r4, r1, #0
	ldrb r1, [r4, #1]
	cmp r1, #0
	beq _021F2C1C
	cmp r1, #1
	beq _021F2C5A
	cmp r1, #2
	beq _021F2C86
	add sp, #4
	pop {r3, r4, pc}
_021F2C1C:
	ldrh r0, [r4, #0x18]
	add r0, r0, #1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x18]
	cmp r0, #5
	bhi _021F2C50
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	mov r0, #0xc
	mul r0, r1
	mov r1, #5
	bl _s32_div_f
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	add r0, r4, #4
	str r0, [sp]
	mov r3, #0xc
	ldr r0, _021F2CC8 ; =0x04000050
	mov r1, #0
	mov r2, #1
	sub r3, r3, r4
	bl G2x_SetBlendAlpha_
	add sp, #4
	pop {r3, r4, pc}
_021F2C50:
	ldrb r0, [r4, #1]
	add sp, #4
	add r0, r0, #1
	strb r0, [r4, #1]
	pop {r3, r4, pc}
_021F2C5A:
	ldrh r1, [r4, #0x1e]
	ldr r0, [r4, #0x20]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021F31F0
	ldrh r1, [r4, #0x1c]
	ldr r0, [r4, #0x20]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_021F3298
	mov r0, #0
	strh r0, [r4, #0x18]
	ldrb r0, [r4, #1]
	add r0, r0, #1
	strb r0, [r4, #1]
	ldr r0, _021F2CCC ; =0x0000089F
	bl PlaySE
	add sp, #4
	pop {r3, r4, pc}
_021F2C86:
	ldrh r1, [r4, #0x18]
	add r1, r1, #1
	strh r1, [r4, #0x18]
	ldrh r1, [r4, #0x18]
	cmp r1, #5
	bhi _021F2CB8
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	mov r0, #0xc
	mul r0, r1
	mov r1, #5
	bl _s32_div_f
	lsl r0, r0, #0x10
	lsr r3, r0, #0x10
	mov r0, #0x10
	sub r0, r0, r3
	str r0, [sp]
	ldr r0, _021F2CC8 ; =0x04000050
	mov r1, #0
	mov r2, #1
	bl G2x_SetBlendAlpha_
	add sp, #4
	pop {r3, r4, pc}
_021F2CB8:
	mov r1, #0
	str r1, [r4, #0xc]
	strh r1, [r4, #0x18]
	strb r1, [r4, #1]
	bl SysTask_Destroy
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_021F2CC8: .word 0x04000050
_021F2CCC: .word 0x0000089F
	thumb_func_end ov96_021F2C04




	thumb_func_start ov96_021F2CD0
ov96_021F2CD0: ; 0x021F2CD0
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _021F2CE6
	cmp r0, #1
	beq _021F2D16
	cmp r0, #2
	beq _021F2D2E
	pop {r3, r4, r5, pc}
_021F2CE6:
	ldrh r0, [r4, #0x1a]
	mov r1, #5
	add r0, r0, #1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x1a]
	lsl r0, r0, #7
	bl _s32_div_f
	mov r1, #0x80
	sub r0, r1, r0
	lsl r1, r0, #0x10
	ldr r0, _021F2D60 ; =0x01FF0000
	and r1, r0
	ldr r0, _021F2D64 ; =0x04000018
	str r1, [r0]
	ldrh r0, [r4, #0x1a]
	cmp r0, #5
	blo _021F2D5E
	mov r0, #0
	strh r0, [r4, #0x1a]
	ldrb r0, [r4, #2]
	add r0, r0, #1
	strb r0, [r4, #2]
	pop {r3, r4, r5, pc}
_021F2D16:
	ldrh r0, [r4, #0x1a]
	add r0, r0, #1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x1a]
	cmp r0, #0x14
	blo _021F2D5E
	mov r0, #0
	strh r0, [r4, #0x1a]
	ldrb r0, [r4, #2]
	add r0, r0, #1
	strb r0, [r4, #2]
	pop {r3, r4, r5, pc}
_021F2D2E:
	ldrh r0, [r4, #0x1a]
	mov r1, #5
	add r0, r0, #1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x1a]
	lsl r0, r0, #7
	neg r0, r0
	bl _s32_div_f
	lsl r1, r0, #0x10
	ldr r0, _021F2D60 ; =0x01FF0000
	and r1, r0
	ldr r0, _021F2D64 ; =0x04000018
	str r1, [r0]
	ldrh r0, [r4, #0x1a]
	cmp r0, #5
	blo _021F2D5E
	mov r0, #0
	strh r0, [r4, #0x1a]
	str r0, [r4, #8]
	strb r0, [r4, #2]
	add r0, r5, #0
	bl SysTask_Destroy
_021F2D5E:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021F2D60: .word 0x01FF0000
_021F2D64: .word 0x04000018
	thumb_func_end ov96_021F2CD0



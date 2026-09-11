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

	thumb_func_start ov96_0220FF68
ov96_0220FF68: ; 0x0220FF68
	ldr r3, _0220FF84 ; =ov96_0221CF1C
	mov r2, #0
_0220FF6C:
	ldr r1, [r3]
	cmp r1, r0
	bhi _0220FF76
	add r0, r2, #0
	bx lr
_0220FF76:
	add r2, r2, #1
	add r3, r3, #4
	cmp r2, #4
	blt _0220FF6C
	mov r0, #0
	mvn r0, r0
	bx lr
	.balign 4, 0
_0220FF84: .word ov96_0221CF1C
	thumb_func_end ov96_0220FF68


	thumb_func_start ov96_0220FF88
ov96_0220FF88: ; 0x0220FF88
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, r1, #0
	mov r4, #1
	bl ov96_0220FF68
	lsl r0, r0, #0x1c
	add r2, r5, #0
	ldr r3, [r5, #0x1c]
	ldr r1, _0221002C ; =0xFFFFF0FF
	lsr r0, r0, #0x14
	and r1, r3
	orr r0, r1
	str r0, [r5, #0x1c]
	lsl r0, r0, #0x14
	lsr r0, r0, #0x1c
	add r2, #0x1c
	cmp r0, #3
	bhi _0220FFD8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0220FFBA: ; jump table
	.short _0220FFC2 - _0220FFBA - 2 ; case 0
	.short _0220FFD0 - _0220FFBA - 2 ; case 1
	.short _0220FFC2 - _0220FFBA - 2 ; case 2
	.short _0220FFD0 - _0220FFBA - 2 ; case 3
_0220FFC2:
	ldr r1, [r2]
	mov r0, #0xff
	bic r1, r0
	mov r0, #0x1e
	orr r0, r1
	str r0, [r2]
	b _0220FFD8
_0220FFD0:
	ldr r1, [r2]
	mov r0, #0xff
	bic r1, r0
	str r1, [r2]
_0220FFD8:
	ldr r0, [r5, #0x1c]
	lsl r0, r0, #0x14
	lsr r0, r0, #0x1c
	cmp r0, #3
	bhs _0220FFE6
	mov r1, #4
	b _0220FFF4
_0220FFE6:
	bl MTRandom
	mov r1, #1
	and r0, r1
	add r0, r0, #1
	lsl r0, r0, #0x1a
	lsr r1, r0, #0x18
_0220FFF4:
	ldr r0, [r5, #0x1c]
	lsl r0, r0, #0x14
	lsr r0, r0, #0x1c
	beq _0220FFFE
	mov r4, #2
_0220FFFE:
	mov r2, #0
	cmp r4, #0
	ble _0221002A
	add r0, r5, #0
	add r0, #8
_02210008:
	ldr r3, [r0]
	lsl r3, r3, #0x1a
	lsr r3, r3, #0x1f
	bne _02210022
	mov r0, #0xc
	mul r0, r2
	add r3, r5, #4
	lsl r2, r2, #0x18
	add r0, r3, r0
	lsr r2, r2, #0x18
	bl ov96_0220FB98
	pop {r3, r4, r5, pc}
_02210022:
	add r2, r2, #1
	add r0, #0xc
	cmp r2, r4
	blt _02210008
_0221002A:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0221002C: .word 0xFFFFF0FF
	thumb_func_end ov96_0220FF88


	thumb_func_start ov96_02210030
ov96_02210030: ; 0x02210030
	push {r3, r4, r5, r6, r7, lr}
	add r1, #0x28
	add r7, r0, #0
	add r0, r1, #0
	add r5, r2, #0
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [r7, #0x1c]
	lsl r1, r0, #0x18
	lsr r2, r1, #0x18
	bne _02210052
	add r0, r7, #0
	add r1, r5, #0
	bl ov96_0220FF88
	b _02210060
_02210052:
	mov r1, #0xff
	bic r0, r1
	sub r1, r2, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	orr r0, r1
	str r0, [r7, #0x1c]
_02210060:
	mov r6, #0
	add r5, r7, #4
_02210064:
	ldr r2, [r7]
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_0220FE38
	add r6, r6, #1
	add r4, r4, #2
	add r5, #0xc
	cmp r6, #2
	blt _02210064
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02210030


	thumb_func_start ov96_0221007C
ov96_0221007C: ; 0x0221007C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r0, [sp, #0xc]
	add r7, r1, #0
	str r2, [sp, #0x10]
	str r3, [r0]
	mov r5, #0
	add r4, r0, #0
	mov r6, #5
_0221008E:
	mov r2, #0
	str r6, [sp]
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	add r3, r2, #0
	str r6, [sp, #4]
	bl ov96_0220ED34
	str r0, [r4, #0x3c]
	add r5, r5, #1
	add r4, #0x1c
	cmp r5, #0xc
	blt _0221008E
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [sp, #0xc]
	add r0, r0, #4
	str r0, [sp, #0x18]
_022100B2:
	ldr r4, [sp, #0x18]
	mov r6, #0
_022100B6:
	cmp r6, #1
	bne _022100BE
	mov r5, #1
	b _022100C0
_022100BE:
	mov r5, #0
_022100C0:
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r2, #0
	ldr r1, [sp, #0x10]
	str r5, [sp, #8]
	add r0, r7, #0
	add r3, r2, #0
	bl ov96_0220ECA4
	str r0, [r4]
	mov r0, #2
	str r0, [sp]
	mov r0, #0x14
	str r0, [sp, #4]
	mov r2, #0
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	add r3, r2, #0
	str r5, [sp, #8]
	bl ov96_0220ECA4
	str r0, [r4, #8]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #2
	blt _022100B6
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	mov r2, #0
	str r0, [sp, #4]
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	add r3, r2, #0
	bl ov96_0220ED34
	ldr r1, [sp, #0x18]
	mov r2, #0
	str r0, [r1, #0x10]
	mov r0, #4
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r1, [sp, #0x10]
	add r0, r7, #0
	add r3, r2, #0
	bl ov96_0220ED34
	ldr r1, [sp, #0x18]
	str r0, [r1, #0x14]
	add r0, r1, #0
	add r0, #0x1c
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #2
	blt _022100B2
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov96_0221007C


	thumb_func_start ov96_0221013C
ov96_0221013C: ; 0x0221013C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r0, r1, #0
	str r1, [sp]
	bl PokeathlonCourse_GetDataCopyArea
	add r0, #0xf0
	bl ov96_021E8A20
	add r4, r0, #0
	ldr r0, [sp]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #4]
	ldr r2, [sp]
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_0220DC7C
	ldr r2, [sp]
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_0220DEAC
	ldr r0, [r4, #0x1c]
	lsr r0, r0, #0x1e
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x63
	lsl r0, r0, #2
	add r6, r5, r0
	ldr r0, [r4, #0x20]
	lsl r7, r1, #1
	lsl r0, r0, #0x19
	lsr r2, r0, #0x19
	ldrh r0, [r6, r7]
	cmp r2, r0
	beq _02210194
	lsl r2, r2, #0x10
	ldr r0, [r5]
	lsr r2, r2, #0x10
	bl ov96_02210390
_02210194:
	ldr r0, [r4, #0x20]
	lsl r0, r0, #0x19
	lsr r0, r0, #0x19
	strh r0, [r6, r7]
	ldr r0, [r4, #0x1c]
	lsl r0, r0, #2
	lsr r0, r0, #0x1a
	sub r1, r0, #1
	cmp r1, #0
	bgt _022101AA
	mov r1, #0
_022101AA:
	cmp r1, #0
	bgt _022101B0
	mov r1, #0
_022101B0:
	ldr r0, [sp, #4]
	add r0, #0xc4
	str r0, [sp, #4]
	ldr r0, [r0]
	bl ov96_0221040C
	ldr r1, [r4, #0x1c]
	ldr r0, [sp]
	lsl r1, r1, #2
	lsr r2, r1, #0x1a
	mov r1, #0x1e
	mul r1, r2
	bl ov96_021E6454
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_0221013C


	thumb_func_start ov96_022101D0
ov96_022101D0: ; 0x022101D0
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r4, #0
	add r5, r6, #0
_022101D8:
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _022101E2
	bl GF_AssertFail
_022101E2:
	ldr r0, [r5, #0x3c]
	bl Sprite_DeleteAndFreeResources
	ldr r0, [r5, #0x44]
	cmp r0, #0
	beq _022101F2
	bl SysTask_Destroy
_022101F2:
	add r4, r4, #1
	add r5, #0x1c
	cmp r4, #0xc
	blt _022101D8
	mov r7, #0
	add r6, r6, #4
_022101FE:
	mov r4, #0
	add r5, r6, #0
_02210202:
	ldr r0, [r5]
	bl Sprite_DeleteAndFreeResources
	ldr r0, [r5, #8]
	bl Sprite_DeleteAndFreeResources
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _02210202
	ldr r0, [r6, #0x10]
	bl Sprite_DeleteAndFreeResources
	ldr r0, [r6, #0x14]
	bl Sprite_DeleteAndFreeResources
	add r7, r7, #1
	add r6, #0x1c
	cmp r7, #2
	blt _022101FE
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_022101D0

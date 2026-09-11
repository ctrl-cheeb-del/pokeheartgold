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

	thumb_func_start ov96_021FC0FC
ov96_021FC0FC: ; 0x021FC0FC
	push {r4, r5, r6, lr}
	add r3, r2, #0
	asr r2, r1, #2
	lsr r2, r2, #0x1d
	add r2, r1, r2
	asr r4, r2, #3
	beq _021FC13A
	lsl r2, r4, #3
	sub r2, r1, r2
	sub r1, r4, #1
	mov r4, #2
	lsl r4, r4, #8
	cmp r1, r4
	bge _021FC13A
	lsl r4, r3, #9
	add r4, r0, r4
	add r5, r4, r1
	ldr r4, _021FC13C ; =0x00000618
	ldrb r4, [r5, r4]
	cmp r4, #0
	beq _021FC13A
	ldr r4, _021FC140 ; =0x00000C18
	lsl r5, r3, #2
	add r6, r0, r4
	ldr r4, [r6, r5]
	cmp r4, r1
	bge _021FC13A
	str r1, [r6, r5]
	add r1, r3, #0
	bl ov96_021FBF90
_021FC13A:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021FC13C: .word 0x00000618
_021FC140: .word 0x00000C18
	thumb_func_end ov96_021FC0FC


	thumb_func_start ov96_021FC144
ov96_021FC144: ; 0x021FC144
	push {r4, lr}
	add r4, r0, #0
	bl LCRandom
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #0x18
	add r4, #0x18
	lsr r2, r0, #0x18
	add r0, r4, #0
	mov r1, #0xe4
	bl ReadWholeNarcMemberByIdPair
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_021FC144


	thumb_func_start ov96_021FC164
ov96_021FC164: ; 0x021FC164
	asr r3, r2, #2
	lsr r3, r3, #0x1d
	add r3, r2, r3
	lsl r1, r1, #9
	asr r2, r3, #3
	add r0, r0, r1
	add r1, r0, r2
	ldr r0, _021FC184 ; =0x00000618
	ldrb r0, [r1, r0]
	cmp r0, #0
	bne _021FC17E
	mov r2, #0
	mvn r2, r2
_021FC17E:
	add r0, r2, #0
	bx lr
	nop
_021FC184: .word 0x00000618
	thumb_func_end ov96_021FC164


	thumb_func_start ov96_021FC188
ov96_021FC188: ; 0x021FC188
	push {r3, r4, r5, lr}
	mov r1, #0x91
	lsl r1, r1, #2
	add r5, r0, #0
	bl Heap_Alloc
	add r4, r0, #0
	mov r2, #0x91
	mov r0, #0
	add r1, r4, #0
	lsl r2, r2, #2
	bl MIi_CpuClearFast
	str r5, [r4]
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021FC188


	thumb_func_start ov96_021FC1A8
ov96_021FC1A8: ; 0x021FC1A8
	push {r3, r4, r5, r6, r7, lr}
	mov r7, #0x62
	lsl r7, r7, #2
	str r0, [sp]
	mov r4, #0
	add r5, r0, #0
	add r6, r7, #4
_021FC1B6:
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Sprite_Delete
	ldr r0, [r5, r7]
	bl Sprite_Delete
	ldr r0, [r5, r6]
	bl Sprite_Delete
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #0xc
	blt _021FC1B6
	mov r1, #0x52
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl SpriteTransfer_DeleteCharTransferTask
	mov r1, #0x53
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r6, #0x13
	ldr r4, [sp]
	mov r5, #0
	lsl r6, r6, #4
_021FC1F4:
	ldr r0, [r4, r6]
	bl Destroy2DGfxResObjMan
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #6
	blt _021FC1F4
	ldr r0, [sp]
	ldr r0, [r0, #4]
	bl SpriteList_Delete
	ldr r0, [sp]
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021FC1A8


	thumb_func_start ov96_021FC214
ov96_021FC214: ; 0x021FC214
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl ov96_021FC320
	add r0, r5, #0
	bl ov96_021FC404
	add r0, r5, #0
	add r1, r4, #0
	bl ov96_021FC450
	add r0, r5, #0
	mov r1, #0
	add r0, #8
	add r2, r1, #0
	bl G2dRenderer_SetSubSurfaceCoords
	add r5, #8
	mov r2, #3
	add r0, r5, #0
	mov r1, #0
	lsl r2, r2, #0x12
	bl G2dRenderer_SetMainSurfaceCoords
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_021FC214


	thumb_func_start ov96_021FC248
ov96_021FC248: ; 0x021FC248
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0
	str r0, [sp, #8]
	lsl r0, r2, #0xc
	str r0, [sp]
	mov r0, #0xe
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	lsl r4, r1, #4
	mov r0, #0x61
	add r1, r5, r4
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r1, sp, #0
	bl Sprite_SetMatrix
	mov r0, #0x62
	add r1, r5, r4
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r1, sp, #0
	bl Sprite_SetMatrix
	mov r0, #0x63
	add r1, r5, r4
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r1, sp, #0
	bl Sprite_SetMatrix
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end ov96_021FC248


	thumb_func_start ov96_021FC28C
ov96_021FC28C: ; 0x021FC28C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r4, r2, #0
	beq _021FC29A
	cmp r4, #8
	bls _021FC29E
_021FC29A:
	bl GF_AssertFail
_021FC29E:
	lsl r0, r6, #4
	add r1, r5, r0
	mov r0, #0x63
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r4, #0xf
	add r1, r4, #0
	bl Sprite_SetAnimCtrlSeq
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_021FC28C


	thumb_func_start ov96_021FC2B4
ov96_021FC2B4: ; 0x021FC2B4
	push {r3, r4, r5, r6, r7, lr}
	mov r7, #0x62
	add r5, r0, #0
	add r4, r1, #0
	mov r6, #0
	lsl r7, r7, #2
_021FC2C0:
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r5, r7]
	add r1, r4, #0
	bl Sprite_SetDrawFlag
	add r6, r6, #1
	add r5, #0x10
	cmp r6, #0xc
	blt _021FC2C0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021FC2B4


	thumb_func_start ov96_021FC2E0
ov96_021FC2E0: ; 0x021FC2E0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	lsl r4, r1, #4
	mov r0, #0x61
	add r1, r5, r4
	lsl r0, r0, #2
	add r6, r2, #0
	ldr r0, [r1, r0]
	add r1, r6, #0
	bl Sprite_SetDrawFlag
	mov r0, #0x62
	add r1, r5, r4
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r1, r6, #0
	bl Sprite_SetDrawFlag
	mov r0, #0x63
	add r1, r5, r4
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r1, r6, #0
	bl Sprite_SetDrawFlag
	pop {r4, r5, r6, pc}
	thumb_func_end ov96_021FC2E0

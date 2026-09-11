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

	thumb_func_start ov96_0220D428
ov96_0220D428: ; 0x0220D428
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #4]
	add r4, r1, #0
	add r6, r2, #0
	cmp r0, #0
	bne _0220D43A
	bl GF_AssertFail
_0220D43A:
	ldr r0, [r5]
	cmp r0, #0
	bne _0220D444
	bl GF_AssertFail
_0220D444:
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _0220D44E
	bl SysTask_Destroy
_0220D44E:
	mov r0, #0
	str r0, [r5, #0x10]
	strb r4, [r5, #0xc]
	ldr r0, _0220D464 ; =ov96_0220D360
	add r1, r5, #0
	mov r2, #2
	strb r6, [r5, #0xd]
	bl SysTask_CreateOnMainQueue
	str r0, [r5, #8]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0220D464: .word ov96_0220D360
	thumb_func_end ov96_0220D428


	thumb_func_start ov96_0220D468
ov96_0220D468: ; 0x0220D468
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	beq _0220D47A
	cmp r0, #1
	beq _0220D4C4
	b _0220D51A
_0220D47A:
	ldrh r0, [r4, #0xc]
	bl _dfltu
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _0220D520 ; =0x33333333
	ldr r1, _0220D524 ; =0x3FD33333
	bl _dmul
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _0220D528 ; =0x3FF00000
	mov r0, #0
	bl _dsub
	bl _d2f
	str r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	cmp r0, #1
	bls _0220D4B0
	mov r0, #0
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	add r0, r0, #1
	strh r0, [r4, #0xe]
	pop {r3, r4, r5, pc}
_0220D4B0:
	mov r1, #0xfe
	ldr r0, [r4]
	ldr r2, [r4, #8]
	lsl r1, r1, #0x16
	bl ov96_021EB10C
	ldrh r0, [r4, #0xc]
	add r0, r0, #1
	strh r0, [r4, #0xc]
	pop {r3, r4, r5, pc}
_0220D4C4:
	ldrh r0, [r4, #0xc]
	bl _dfltu
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _0220D520 ; =0x33333333
	ldr r1, _0220D524 ; =0x3FD33333
	bl _dmul
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _0220D528 ; =0x3FF00000
	mov r0, #0
	bl _dadd
	bl _d2f
	str r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	cmp r0, #1
	bls _0220D506
	mov r0, #0
	mov r1, #0xfe
	str r0, [r4, #4]
	lsl r1, r1, #0x16
	ldr r0, [r4]
	add r2, r1, #0
	bl ov96_021EB10C
	add r0, r5, #0
	bl SysTask_Destroy
	pop {r3, r4, r5, pc}
_0220D506:
	mov r1, #0xfe
	ldr r0, [r4]
	ldr r2, [r4, #8]
	lsl r1, r1, #0x16
	bl ov96_021EB10C
	ldrh r0, [r4, #0xc]
	add r0, r0, #1
	strh r0, [r4, #0xc]
	pop {r3, r4, r5, pc}
_0220D51A:
	bl GF_AssertFail
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0220D520: .word 0x33333333
_0220D524: .word 0x3FD33333
_0220D528: .word 0x3FF00000
	thumb_func_end ov96_0220D468


	thumb_func_start ov96_0220D52C
ov96_0220D52C: ; 0x0220D52C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5, #4]
	add r4, r1, #0
	cmp r0, #0
	beq _0220D53C
	bl SysTask_Destroy
_0220D53C:
	str r4, [r5]
	mov r2, #0
	strh r2, [r5, #0xc]
	ldr r0, _0220D550 ; =ov96_0220D468
	add r1, r5, #0
	strh r2, [r5, #0xe]
	bl SysTask_CreateOnMainQueue
	str r0, [r5, #4]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0220D550: .word ov96_0220D468
	thumb_func_end ov96_0220D52C


	thumb_func_start ov96_0220D554
ov96_0220D554: ; 0x0220D554
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r0, #0
	add r7, r1, #0
	bl ov96_021EAA20
	add r5, r0, #0
	bl ov96_021E90FC
	add r4, r0, #0
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r0, r5, #0
	bl ov96_021E8BB0
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _0220D58A
	add r0, r6, #0
	mov r1, #1
	mov r5, #0x40
	bl ov96_021EABE0
	b _0220D594
_0220D58A:
	add r0, r6, #0
	mov r1, #2
	mov r5, #0x20
	bl ov96_021EABE0
_0220D594:
	cmp r7, #0
	beq _0220D5B2
	lsr r0, r5, #0x1f
	add r0, r5, r0
	asr r0, r0, #1
	lsl r0, r0, #0xc
	sub r1, r5, r4
	str r0, [sp]
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	add r0, r4, r0
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	b _0220D5C2
_0220D5B2:
	lsr r0, r5, #0x1f
	add r0, r5, r0
	asr r0, r0, #1
	lsl r0, r0, #0xc
	str r0, [sp]
	sub r0, r5, #1
	lsl r0, r0, #0xc
	str r0, [sp, #4]
_0220D5C2:
	add r0, r6, #0
	add r1, sp, #0
	bl ov96_021EABF4
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220D554


	thumb_func_start ov96_0220D5D0
ov96_0220D5D0: ; 0x0220D5D0
	push {r3, r4, lr}
	sub sp, #0x34
	add r2, r0, #0
	add r0, sp, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	add r4, r1, #0
	ldr r0, [r2, #4]
	ldr r1, [r2, #0x1c]
	ldr r2, [r2, #0x20]
	add r3, sp, #0x1c
	bl ov96_021EAF78
	add r0, sp, #0x14
	str r0, [sp]
	add r0, sp, #8
	str r0, [sp, #4]
	ldr r0, [r4, #4]
	ldr r1, [r4, #0x1c]
	ldr r2, [r4, #0x20]
	add r3, sp, #0x10
	bl ov96_021EAF78
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #8]
	add r2, sp, #0x28
	add r0, r1, r0
	lsl r4, r0, #0xc
	mov r0, #0
	str r0, [sp, #0x24]
	str r0, [sp, #0x18]
	add r0, sp, #0x1c
	add r1, sp, #0x10
	bl VEC_Subtract
	add r0, sp, #0x28
	bl VEC_Mag
	cmp r0, r4
	bgt _0220D628
	add sp, #0x34
	mov r0, #1
	pop {r3, r4, pc}
_0220D628:
	mov r0, #0
	add sp, #0x34
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220D5D0


	thumb_func_start ov96_0220D630
ov96_0220D630: ; 0x0220D630
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r1, r4, #0
	add r2, r4, #0
	add r1, #0x45
	add r2, #0x46
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [r4]
	bl ov96_0220F378
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _0220D67E
	mov r0, #1
	add r1, r4, #0
	add r2, r4, #0
	str r0, [sp]
	add r1, #0x45
	add r2, #0x46
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [r4]
	mov r3, #2
	bl ov96_021E8228
	ldr r0, [r4, #8]
	bl ov96_0220F3B4
	lsl r0, r0, #0x18
	ldr r2, [r4, #0x40]
	mov r1, #0xff
	bic r2, r1
	lsr r0, r0, #0x18
	orr r0, r2
	str r0, [r4, #0x40]
	mov r0, #1
	str r0, [r4, #0xc]
_0220D67E:
	ldr r1, [r4, #0x40]
	ldr r0, _0220D690 ; =0xFFFF00FF
	and r1, r0
	mov r0, #0xa
	lsl r0, r0, #8
	orr r0, r1
	str r0, [r4, #0x40]
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_0220D690: .word 0xFFFF00FF
	thumb_func_end ov96_0220D630


	thumb_func_start ov96_0220D694
ov96_0220D694: ; 0x0220D694
	push {r4, lr}
	add r4, r0, #0
	bne _0220D69E
	bl GF_AssertFail
_0220D69E:
	ldr r1, [r4, #0xc]
	mov r0, #1
	cmp r1, #2
	beq _0220D6AC
	cmp r1, #1
	beq _0220D6AC
	mov r0, #0
_0220D6AC:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov96_0220D694


	thumb_func_start ov96_0220D6B0
ov96_0220D6B0: ; 0x0220D6B0
	mov r2, #0
	ldrsh r2, [r1, r2]
	lsl r2, r2, #0xc
	str r2, [r0, #0x10]
	mov r2, #2
	ldrsh r1, [r1, r2]
	lsl r1, r1, #0xc
	str r1, [r0, #0x14]
	mov r1, #2
	ldr r2, [r0, #0x40]
	lsl r1, r1, #0x1a
	orr r1, r2
	str r1, [r0, #0x40]
	bx lr
	thumb_func_end ov96_0220D6B0


	thumb_func_start ov96_0220D6CC
ov96_0220D6CC: ; 0x0220D6CC
	push {r3, r4, r5, lr}
	sub sp, #0x18
	ldr r5, _0220D740 ; =ov96_0221CF00
	add r3, r0, #0
	ldmia r5!, {r0, r1}
	add r4, sp, #0xc
	add r2, r4, #0
	stmia r4!, {r0, r1}
	ldr r0, [r5]
	add r1, sp, #0
	str r0, [r4]
	mov r4, #0
	str r4, [r1]
	str r4, [r1, #4]
	str r4, [r1, #8]
	ldr r0, [r3, #4]
	str r0, [sp]
	ldr r0, [r3]
	str r0, [sp, #8]
	add r0, r2, #0
	str r4, [sp, #4]
	bl CalcAngleBetweenVecs
	mov r2, #2
	lsl r2, r2, #0xc
	cmp r0, r2
	bls _0220D70A
	mov r1, #0xe
	lsl r1, r1, #0xc
	cmp r0, r1
	blo _0220D710
_0220D70A:
	add sp, #0x18
	mov r0, #4
	pop {r3, r4, r5, pc}
_0220D710:
	cmp r0, r2
	bls _0220D722
	mov r1, #6
	lsl r1, r1, #0xc
	cmp r0, r1
	bhs _0220D722
	add sp, #0x18
	mov r0, #2
	pop {r3, r4, r5, pc}
_0220D722:
	mov r1, #6
	lsl r1, r1, #0xc
	cmp r0, r1
	blo _0220D738
	mov r1, #0xa
	lsl r1, r1, #0xc
	cmp r0, r1
	bhi _0220D738
	add sp, #0x18
	mov r0, #3
	pop {r3, r4, r5, pc}
_0220D738:
	mov r0, #1
	add sp, #0x18
	pop {r3, r4, r5, pc}
	nop
_0220D740: .word ov96_0221CF00
	thumb_func_end ov96_0220D6CC


	thumb_func_start ov96_0220D744
ov96_0220D744: ; 0x0220D744
	push {r4, r5, r6, lr}
	sub sp, #0x60
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne _0220D752
	b _0220D8B0
_0220D752:
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0x10
	add r1, #0x1c
	add r2, sp, #0x54
	bl VEC_Subtract
	add r0, sp, #0x54
	bl VEC_Mag
	add r4, r0, #0
	cmp r4, #0
	ble _0220D770
	mov r2, #1
	b _0220D772
_0220D770:
	mov r2, #0
_0220D772:
	ldr r1, [r5, #0x40]
	ldr r0, _0220D8B4 ; =0xEFFFFFFF
	and r1, r0
	lsl r0, r2, #0x1f
	lsr r0, r0, #3
	orr r0, r1
	str r0, [r5, #0x40]
	lsl r0, r0, #5
	lsr r0, r0, #0x1f
	beq _0220D844
	mov r2, #0
	add r0, sp, #0x24
	str r2, [r0]
	add r1, sp, #0x30
	str r2, [r0, #4]
	str r2, [r1]
	str r2, [r0, #8]
	add r0, r5, #0
	str r2, [r1, #4]
	add r0, #0x34
	str r2, [r1, #8]
	bl VEC_Normalize
	ldr r0, _0220D8B8 ; =0x00000CCD
	add r1, sp, #0x30
	add r2, sp, #0x24
	add r3, sp, #0x18
	bl VEC_MultAdd
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bge _0220D7B4
	neg r0, r0
_0220D7B4:
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	bge _0220D7BE
	neg r0, r0
_0220D7BE:
	str r0, [sp, #0x1c]
	ldr r0, [r5, #0x40]
	lsl r0, r0, #4
	lsr r0, r0, #0x1f
	beq _0220D806
	ldr r0, [r5, #8]
	mov r1, #0x64
	ldr r0, [r0, #4]
	bl _s32_div_f
	add r6, r0, #0
	add r0, sp, #0x54
	add r1, sp, #0x48
	bl VEC_Normalize
	add r1, r5, #0
	add r0, r6, #0
	add r1, #0x28
	add r2, sp, #0x24
	add r3, sp, #0xc
	bl VEC_MultAdd
	ldr r1, [sp, #0xc]
	cmp r1, #0
	bge _0220D7F2
	neg r1, r1
_0220D7F2:
	ldr r0, [sp, #0x18]
	add r0, r0, r1
	ldr r1, [sp, #0x10]
	str r0, [sp, #0x18]
	cmp r1, #0
	bge _0220D800
	neg r1, r1
_0220D800:
	ldr r0, [sp, #0x1c]
	add r0, r0, r1
	str r0, [sp, #0x1c]
_0220D806:
	add r0, r5, #0
	ldr r1, [sp, #0x18]
	ldr r2, [sp, #0x1c]
	add r0, #0x34
	bl ov96_0220E960
	add r0, r5, #0
	add r0, #0x1c
	add r1, r5, #0
	add r1, #0x34
	add r2, r0, #0
	bl VEC_Add
	add r3, r5, #0
	add r3, #0x1c
	add r2, r5, #0
	ldmia r3!, {r0, r1}
	add r2, #0x10
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r5, #0x34]
	cmp r0, #0
	bne _0220D8B0
	ldr r0, [r5, #0x38]
	cmp r0, #0
	bne _0220D8B0
	ldr r1, [r5, #0x40]
	ldr r0, _0220D8BC ; =0xFBFFFFFF
	and r0, r1
	str r0, [r5, #0x40]
_0220D844:
	ldr r0, [r5, #0x40]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	beq _0220D8B0
	add r0, sp, #0x54
	add r1, sp, #0x48
	bl VEC_Normalize
	ldr r0, [r5, #0x40]
	lsl r0, r0, #5
	lsr r0, r0, #0x1f
	bne _0220D870
	add r0, sp, #0x48
	bl ov96_0220D6CC
	lsl r0, r0, #0x1c
	ldr r2, [r5, #0x40]
	ldr r1, _0220D8C0 ; =0xFF0FFFFF
	lsr r0, r0, #8
	and r1, r2
	orr r0, r1
	str r0, [r5, #0x40]
_0220D870:
	ldr r0, [r5, #8]
	ldr r0, [r0, #8]
	cmp r4, r0
	bgt _0220D886
	add r3, sp, #0x54
	ldmia r3!, {r0, r1}
	add r2, sp, #0x3c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	b _0220D898
_0220D886:
	add r2, sp, #0
	mov r1, #0
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [r2, #8]
	add r1, sp, #0x48
	add r3, sp, #0x3c
	bl VEC_MultAdd
_0220D898:
	add r0, r5, #0
	add r0, #0x1c
	add r1, sp, #0x3c
	add r2, r0, #0
	bl VEC_Add
	add r2, sp, #0x48
	ldmia r2!, {r0, r1}
	add r5, #0x28
	stmia r5!, {r0, r1}
	ldr r0, [r2]
	str r0, [r5]
_0220D8B0:
	add sp, #0x60
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0220D8B4: .word 0xEFFFFFFF
_0220D8B8: .word 0x00000CCD
_0220D8BC: .word 0xFBFFFFFF
_0220D8C0: .word 0xFF0FFFFF
	thumb_func_end ov96_0220D744


	thumb_func_start ov96_0220D8C4
ov96_0220D8C4: ; 0x0220D8C4
	push {lr}
	sub sp, #0xc
	add r3, sp, #4
	str r3, [sp]
	ldr r0, [r0, #4]
	asr r1, r1, #0xc
	asr r2, r2, #0xc
	add r3, sp, #8
	bl ov96_021EB06C
	ldr r1, [sp, #8]
	cmp r1, #0
	ble _0220D8EC
	ldr r0, [sp, #4]
	cmp r0, #0
	ble _0220D8EC
	cmp r1, #0xff
	bge _0220D8EC
	cmp r0, #0xff
	blt _0220D8F2
_0220D8EC:
	add sp, #0xc
	mov r0, #1
	pop {pc}
_0220D8F2:
	cmp r1, #8
	blt _0220D902
	cmp r1, #0xf8
	bge _0220D902
	cmp r0, #8
	blt _0220D902
	cmp r0, #0xb4
	blt _0220D908
_0220D902:
	add sp, #0xc
	mov r0, #1
	pop {pc}
_0220D908:
	mov r0, #0
	add sp, #0xc
	pop {pc}
	.balign 4, 0
	thumb_func_end ov96_0220D8C4


	thumb_func_start ov96_0220D910
ov96_0220D910: ; 0x0220D910
	push {r4, r5, r6, lr}
	sub sp, #0x18
	add r5, r0, #0
	ldr r0, [r5, #0x40]
	mov r1, #3
	lsl r0, r0, #0xc
	lsr r0, r0, #0x1c
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r6, #0
	bl _s32_div_f
	lsl r4, r1, #2
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r0, #0
	mov r1, #0xc
	mul r2, r1
	ldr r1, _0220D994 ; =ov96_0221CFBC
	add r0, sp, #4
	add r1, r1, r2
	ldr r3, _0220D998 ; =ov96_0221CFBE
	str r0, [sp]
	add r2, r3, r2
	ldrsh r1, [r4, r1]
	ldrsh r2, [r4, r2]
	ldr r0, [r5, #4]
	add r3, sp, #8
	bl ov96_021EB0A4
	ldr r0, [sp, #8]
	add r2, r5, #0
	lsl r0, r0, #0xc
	str r0, [r5, #0x1c]
	ldr r0, [sp, #4]
	add r3, sp, #0xc
	lsl r0, r0, #0xc
	str r0, [r5, #0x20]
	ldr r0, [sp, #8]
	add r2, #0x34
	lsl r0, r0, #0xc
	str r0, [r5, #0x10]
	ldr r0, [sp, #4]
	lsl r0, r0, #0xc
	str r0, [r5, #0x14]
	mov r0, #0
	str r0, [r3]
	str r0, [r3, #4]
	str r0, [r3, #8]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r1, [r5, #0x40]
	ldr r0, _0220D99C ; =0xFF0FFFFF
	and r1, r0
	mov r0, #2
	lsl r0, r0, #0x14
	orr r1, r0
	ldr r0, _0220D9A0 ; =0xFBFFFFFF
	and r0, r1
	str r0, [r5, #0x40]
	add sp, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0220D994: .word ov96_0221CFBC
_0220D998: .word ov96_0221CFBE
_0220D99C: .word 0xFF0FFFFF
_0220D9A0: .word 0xFBFFFFFF
	thumb_func_end ov96_0220D910


	thumb_func_start ov96_0220D9A4
ov96_0220D9A4: ; 0x0220D9A4
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r2, [r4, #0xc]
	cmp r2, #4
	bhi _0220DA94
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_0220D9BC: ; jump table
	.short _0220DA94 - _0220D9BC - 2 ; case 0
	.short _0220DA6A - _0220D9BC - 2 ; case 1
	.short _0220D9F2 - _0220D9BC - 2 ; case 2
	.short _0220D9CE - _0220D9BC - 2 ; case 3
	.short _0220D9C6 - _0220D9BC - 2 ; case 4
_0220D9C6:
	mov r0, #2
	add sp, #4
	str r0, [r4, #0xc]
	pop {r3, r4, pc}
_0220D9CE:
	add r1, r4, #0
	add r1, #0x44
	ldrb r1, [r1]
	sub r2, r1, #1
	add r1, r4, #0
	add r1, #0x44
	strb r2, [r1]
	add r1, r4, #0
	add r1, #0x44
	ldrb r1, [r1]
	cmp r1, #0
	bne _0220DA98
	bl ov96_0220D910
	mov r0, #4
	add sp, #4
	str r0, [r4, #0xc]
	pop {r3, r4, pc}
_0220D9F2:
	bl ov96_0220D744
	ldr r1, [r4, #0x1c]
	ldr r2, [r4, #0x20]
	add r0, r4, #0
	bl ov96_0220D8C4
	cmp r0, #0
	beq _0220DA98
	mov r3, #1
	add r1, r4, #0
	add r2, r4, #0
	str r3, [sp]
	add r1, #0x45
	add r2, #0x46
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [r4]
	bl ov96_021E8228
	mov r0, #1
	add r1, r4, #0
	add r2, r4, #0
	str r0, [sp]
	add r1, #0x45
	add r2, #0x46
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [r4]
	mov r3, #5
	bl ov96_021E8228
	ldr r0, [r4, #0x40]
	lsl r0, r0, #2
	lsr r0, r0, #0x1f
	beq _0220DA52
	mov r0, #1
	add r1, r4, #0
	add r2, r4, #0
	str r0, [sp]
	add r1, #0x45
	add r2, #0x46
	ldrb r1, [r1]
	ldrb r2, [r2]
	ldr r0, [r4]
	mov r3, #8
	bl ov96_021E8228
_0220DA52:
	ldr r1, [r4, #0x40]
	ldr r0, _0220DA9C ; =0xDFFFFFFF
	add sp, #4
	and r0, r1
	str r0, [r4, #0x40]
	add r0, r4, #0
	mov r1, #0x5a
	add r0, #0x44
	strb r1, [r0]
	mov r0, #3
	str r0, [r4, #0xc]
	pop {r3, r4, pc}
_0220DA6A:
	ldr r3, [r4, #0x40]
	mov r2, #0xff
	add r0, r3, #0
	bic r0, r2
	lsl r2, r3, #0x18
	lsr r2, r2, #0x18
	sub r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	orr r0, r2
	str r0, [r4, #0x40]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bne _0220DA8A
	mov r0, #2
	str r0, [r4, #0xc]
_0220DA8A:
	add r0, r4, #0
	bl ov96_0220D744
	add sp, #4
	pop {r3, r4, pc}
_0220DA94:
	bl GF_AssertFail
_0220DA98:
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_0220DA9C: .word 0xDFFFFFFF
	thumb_func_end ov96_0220D9A4


	thumb_func_start ov96_0220DAA0
ov96_0220DAA0: ; 0x0220DAA0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	ldr r3, _0220DB38 ; =ov96_0221CEF4
	add r5, r0, #0
	mov r0, #0xc
	str r1, [sp, #4]
	str r0, [sp, #0x14]
	str r2, [sp, #8]
	add r2, sp, #0x24
	ldmia r3!, {r0, r1}
	add r4, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r7, #1
	str r0, [r2]
	ldr r0, [sp, #4]
	lsl r7, r7, #0x14
	lsl r0, r0, #0xc
	str r0, [sp, #0x10]
	ldr r0, [sp, #8]
	mov r6, #0
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
_0220DACE:
	ldr r0, [sp, #8]
	str r0, [sp]
	ldr r0, [r5, #4]
	ldr r1, [r5, #0x1c]
	ldr r2, [r5, #0x20]
	ldr r3, [sp, #4]
	bl ov96_021EB0CC
	cmp r0, #0
	beq _0220DB0C
	mov r1, #0
	add r0, sp, #0x18
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldr r1, [r5, #0x1c]
	ldr r0, [sp, #0x10]
	sub r0, r0, r1
	bpl _0220DAF6
	neg r0, r0
_0220DAF6:
	str r0, [sp, #0x18]
	ldr r1, [r5, #0x20]
	ldr r0, [sp, #0xc]
	sub r0, r0, r1
	bpl _0220DB02
	neg r0, r0
_0220DB02:
	str r0, [sp, #0x1c]
	add r0, sp, #0x18
	bl VEC_Mag
	str r0, [r4]
_0220DB0C:
	add r6, r6, #1
	add r5, #0x48
	add r4, r4, #4
	cmp r6, #3
	blt _0220DACE
	mov r2, #0
	add r1, sp, #0x24
_0220DB1A:
	ldr r0, [r1]
	cmp r0, r7
	bge _0220DB24
	add r7, r0, #0
	str r2, [sp, #0x14]
_0220DB24:
	add r2, r2, #1
	add r1, r1, #4
	cmp r2, #3
	blt _0220DB1A
	ldr r0, [sp, #0x14]
	lsl r0, r0, #0x18
	asr r0, r0, #0x18
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220DB38: .word ov96_0221CEF4
	thumb_func_end ov96_0220DAA0


	thumb_func_start ov96_0220DB3C
ov96_0220DB3C: ; 0x0220DB3C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r2, #0
	cmp r1, #0
	beq _0220DB50
	cmp r1, #1
	beq _0220DB7C
	cmp r1, #2
	beq _0220DBA8
	pop {r4, r5, r6, pc}
_0220DB50:
	ldr r0, [r5]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	cmp r4, #0
	bne _0220DB60
	mov r6, #1
	b _0220DB62
_0220DB60:
	mov r6, #0
_0220DB62:
	ldr r0, [r5, #4]
	add r1, r6, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #8]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0xc]
	add r1, r6, #0
	bl ManagedSprite_SetDrawFlag
	pop {r4, r5, r6, pc}
_0220DB7C:
	cmp r4, #0
	bne _0220DB84
	mov r6, #1
	b _0220DB86
_0220DB84:
	mov r6, #0
_0220DB86:
	ldr r0, [r5]
	add r1, r6, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #4]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #8]
	add r1, r6, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0xc]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	pop {r4, r5, r6, pc}
_0220DBA8:
	ldr r0, [r5]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #4]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #8]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0xc]
	add r1, r4, #0
	bl ManagedSprite_SetDrawFlag
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov96_0220DB3C


	thumb_func_start ov96_0220DBCC
ov96_0220DBCC: ; 0x0220DBCC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r0, [r5]
	add r2, r4, #0
	bl ManagedSprite_SetAffineScale
	ldr r0, [r5, #4]
	add r1, r4, #0
	add r2, r4, #0
	bl ManagedSprite_SetAffineScale
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov96_0220DBCC


	thumb_func_start ov96_0220DBE8
ov96_0220DBE8: ; 0x0220DBE8
	push {r3, r4, r5, r6, r7, lr}
	sub r7, r1, #3
	add r5, r0, #0
	add r4, r2, #0
	add r6, r3, #0
	cmp r7, #4
	blt _0220DBFA
	bl GF_AssertFail
_0220DBFA:
	mov r3, #0x1e
	ldr r0, [r5, #0x10]
	add r1, r4, #0
	add r2, r6, #0
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	mov r3, #0x1e
	ldr r0, [r5, #0x14]
	add r1, r4, #0
	add r2, r6, #0
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r5, #0x10]
	add r1, r7, #0
	bl ManagedSprite_SetAnim
	ldr r0, [r5, #0x14]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	ldr r0, [r5, #0x10]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x14]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0220DBE8


	thumb_func_start ov96_0220DC38
ov96_0220DC38: ; 0x0220DC38
	push {r4, lr}
	cmp r0, #6
	bhi _0220DC68
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0220DC4A: ; jump table
	.short _0220DC68 - _0220DC4A - 2 ; case 0
	.short _0220DC68 - _0220DC4A - 2 ; case 1
	.short _0220DC68 - _0220DC4A - 2 ; case 2
	.short _0220DC58 - _0220DC4A - 2 ; case 3
	.short _0220DC5C - _0220DC4A - 2 ; case 4
	.short _0220DC60 - _0220DC4A - 2 ; case 5
	.short _0220DC64 - _0220DC4A - 2 ; case 6
_0220DC58:
	mov r4, #0
	b _0220DC6C
_0220DC5C:
	mov r4, #0x80
	b _0220DC6C
_0220DC60:
	mov r4, #0
	b _0220DC6C
_0220DC64:
	mov r4, #0xc0
	b _0220DC6C
_0220DC68:
	bl GF_AssertFail
_0220DC6C:
	ldr r0, _0220DC78 ; =0x0000088D
	add r1, r4, #0
	bl PlaySE_SetPitch
	pop {r4, pc}
	nop
_0220DC78: .word 0x0000088D
	thumb_func_end ov96_0220DC38


	thumb_func_start ov96_0220DC7C
ov96_0220DC7C: ; 0x0220DC7C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r2, #0
	add r4, r0, #0
	add r0, r6, #0
	add r5, r1, #0
	bl ov96_021E5F24
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	add r0, r6, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #8]
	add r4, r4, #4
_0220DCA0:
	ldrh r1, [r5]
	lsl r0, r1, #0x19
	lsr r2, r0, #0x16
	lsr r0, r2, #0x1f
	add r0, r2, r0
	lsl r1, r1, #0x12
	lsl r0, r0, #0xf
	lsr r1, r1, #0x1d
	asr r0, r0, #0x10
	cmp r1, #2
	bne _0220DCC0
	mov r1, #0x1e
	lsl r1, r1, #4
	add r0, r0, r1
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
_0220DCC0:
	mov r1, #0x12
	lsl r1, r1, #4
	add r7, r0, #0
	cmp r0, r1
	blt _0220DCCE
	mov r6, #1
	b _0220DCD0
_0220DCCE:
	mov r6, #0
_0220DCD0:
	cmp r6, #0
	beq _0220DCDE
	mov r1, #0x12
	lsl r1, r1, #4
	sub r1, r7, r1
	lsl r1, r1, #0x10
	asr r7, r1, #0x10
_0220DCDE:
	ldrh r1, [r5]
	lsl r1, r1, #0x15
	lsr r1, r1, #0x1c
	bl ov96_0220E6DC
	str r0, [sp, #4]
	ldrh r0, [r5]
	lsl r0, r0, #0x12
	lsr r0, r0, #0x1d
	bne _0220DD0E
	add r0, r4, #0
	mov r1, #2
	mov r2, #0
	bl ov96_0220DB3C
	ldr r0, [r4, #0x10]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x14]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _0220DD90
_0220DD0E:
	cmp r0, #3
	blo _0220DD72
	ldr r1, [r4, #0x18]
	lsl r1, r1, #8
	lsr r1, r1, #0x18
	cmp r1, #3
	bhs _0220DD72
	add r0, r4, #0
	mov r1, #2
	mov r2, #0
	bl ov96_0220DB3C
	ldrh r1, [r5]
	add r3, r7, #0
	sub r3, #0x28
	lsl r1, r1, #0x12
	lsl r3, r3, #0x10
	ldr r2, [sp, #4]
	add r0, r4, #0
	lsr r1, r1, #0x1d
	asr r3, r3, #0x10
	bl ov96_0220DBE8
	ldrh r0, [r5]
	lsl r0, r0, #0x10
	lsr r1, r0, #0x1e
	ldr r0, [sp]
	cmp r1, r0
	bne _0220DD62
	ldr r1, [sp, #0xc]
	ldr r0, _0220DE70 ; =0x000006A8
	add r0, r1, r0
	mov r1, #4
	add r2, r1, #0
	bl ov96_0220D428
	ldrh r0, [r5]
	lsl r0, r0, #0x12
	lsr r0, r0, #0x1d
	bl ov96_0220DC38
	b _0220DD6A
_0220DD62:
	ldr r0, [r4, #0x10]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_0220DD6A:
	ldr r0, _0220DE74 ; =0x000008C4
	bl PlaySE
	b _0220DD90
_0220DD72:
	cmp r0, #1
	bne _0220DD90
	add r0, r4, #0
	add r1, r6, #0
	mov r2, #1
	bl ov96_0220DB3C
	ldr r0, [r4, #0x10]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x14]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_0220DD90:
	ldr r0, [r4, #0x18]
	lsl r1, r0, #8
	lsr r1, r1, #0x18
	bne _0220DDB6
	ldrh r1, [r5]
	lsl r1, r1, #0x12
	lsr r1, r1, #0x1d
	cmp r1, #1
	bne _0220DDB6
	ldr r1, _0220DE78 ; =0xFFFF0000
	and r0, r1
	str r0, [r4, #0x18]
	ldr r1, _0220DE7C ; =0x3F99999A
	add r0, r4, #0
	bl ov96_0220DBCC
	ldr r0, _0220DE80 ; =0x000008C3
	bl PlaySE
_0220DDB6:
	ldrh r0, [r5]
	lsl r0, r0, #0x12
	lsr r1, r0, #0x1d
	ldr r0, _0220DE84 ; =0x0000FFFF
	add r0, r1, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	cmp r0, #1
	bhi _0220DE46
	cmp r6, #0
	beq _0220DDDE
	ldr r0, [sp, #4]
	cmp r0, #0x10
	ble _0220DDDE
	lsl r0, r6, #2
	add r0, r4, r0
	ldr r0, [r0, #8]
	mov r1, #1
	bl ManagedSprite_SetAnimNoRestart
_0220DDDE:
	ldr r0, [r4, #0x18]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_SinDeg
	mov r1, #0x12
	bl _s32_div_f
	bl _fflt
	ldr r1, _0220DE88 ; =0x45800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, _0220DE7C ; =0x3F99999A
	bl _fadd
	add r1, r0, #0
	ldr r0, [r4, #0x18]
	ldr r2, _0220DE78 ; =0xFFFF0000
	and r2, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	add r0, #0xa
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	orr r0, r2
	str r0, [r4, #0x18]
	add r0, r4, #0
	bl ov96_0220DBCC
	add r2, r7, #0
	lsl r0, r6, #2
	sub r2, #0x28
	add r6, r4, r0
	lsl r2, r2, #0x10
	mov r3, #0x1e
	ldr r0, [r4, r0]
	ldr r1, [sp, #4]
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	mov r3, #0x1e
	ldr r0, [r6, #8]
	ldr r1, [sp, #4]
	add r2, r7, #0
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
_0220DE46:
	ldr r1, [r4, #0x18]
	ldr r0, _0220DE8C ; =0xFF00FFFF
	and r0, r1
	ldrh r1, [r5]
	add r5, r5, #2
	lsl r1, r1, #0x12
	lsr r1, r1, #0x1d
	lsl r1, r1, #0x18
	lsr r1, r1, #8
	orr r0, r1
	str r0, [r4, #0x18]
	ldr r0, [sp, #8]
	add r4, #0x1c
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #2
	bge _0220DE6A
	b _0220DCA0
_0220DE6A:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0220DE70: .word 0x000006A8
_0220DE74: .word 0x000008C4
_0220DE78: .word 0xFFFF0000
_0220DE7C: .word 0x3F99999A
_0220DE80: .word 0x000008C3
_0220DE84: .word 0x0000FFFF
_0220DE88: .word 0x45800000
_0220DE8C: .word 0xFF00FFFF
	thumb_func_end ov96_0220DC7C


	thumb_func_start ov96_0220DE90
ov96_0220DE90: ; 0x0220DE90
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r0, r1
	bne _0220DE9C
	mov r0, #0
	bx lr
_0220DE9C:
	cmp r0, r1
	bhs _0220DEA4
	mov r0, #1
	bx lr
_0220DEA4:
	mov r0, #0
	mvn r0, r0
	bx lr
	.balign 4, 0
	thumb_func_end ov96_0220DE90


	thumb_func_start ov96_0220DEAC
ov96_0220DEAC: ; 0x0220DEAC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xa0
	add r5, r0, #0
	str r2, [sp, #8]
	mov r0, #0
	str r1, [sp, #4]
	add r3, sp, #0x40
	add r1, r0, #0
	mov r2, #6
_0220DEBE:
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220DEBE
	ldr r0, [sp, #8]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0x1c]
	add r0, sp, #0x40
	mov r6, #0
	str r0, [sp, #0x14]
	mov r0, #0xff
	add r5, #0x3c
	str r6, [sp, #0x10]
	str r0, [sp, #0x28]
	str r0, [sp, #0x24]
_0220DEDE:
	ldr r0, [sp, #0x1c]
	lsl r1, r6, #0x18
	ldr r0, [r0, #0x20]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	add r4, r0, #0
	cmp r5, #0
	bne _0220DEF4
	bl GF_AssertFail
_0220DEF4:
	cmp r4, #0
	bne _0220DEFC
	bl GF_AssertFail
_0220DEFC:
	ldr r0, [sp, #4]
	add r3, sp, #0x3c
	add r0, r0, r6
	ldrb r7, [r0, #0x10]
	str r0, [sp, #0xc]
	add r0, sp, #0x38
	str r0, [sp]
	ldr r1, [sp, #0xc]
	add r0, r4, #0
	ldrb r1, [r1, #4]
	add r2, r7, #0
	bl ov96_021EB0A4
	ldr r0, [sp, #0x14]
	strb r7, [r0]
	str r4, [r0, #4]
	ldr r0, [sp, #4]
	ldr r0, [r0, #0x20]
	lsl r0, r0, #0xd
	lsr r0, r0, #0x14
	add r1, r0, #0
	lsr r1, r6
	mov r0, #1
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	cmp r0, #1
	bne _0220DF68
	ldr r0, [r5, #0x18]
	lsl r0, r0, #0xc
	lsr r0, r0, #0x1f
	bne _0220DF68
	add r0, r4, #0
	mov r1, #1
	bl ov96_0220D554
	mov r0, #1
	ldr r1, [r5, #0x18]
	lsl r0, r0, #0x12
	orr r1, r0
	ldr r0, _0220E1FC ; =0xFFFF00FF
	and r1, r0
	mov r0, #6
	lsl r0, r0, #8
	orr r0, r1
	str r0, [r5, #0x18]
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [r5, #0x14]
	ldr r0, _0220E200 ; =0x0000089E
	bl PlaySE
	b _0220DFC6
_0220DF68:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _0220DFC6
	ldr r0, [r5, #0x18]
	lsl r0, r0, #0xc
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0220DFC6
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x38]
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	mov r3, #0x1e
	ldr r0, [r5]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r5]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5]
	bl ManagedSprite_ResetSpriteAnimCtrlState
	add r0, r4, #0
	mov r1, #0
	bl ov96_0220D554
	mov r1, #0xfe
	lsl r1, r1, #0x16
	add r0, r4, #0
	add r2, r1, #0
	bl ov96_021EB10C
	add r0, r4, #0
	mov r1, #1
	bl ov96_021EAB38
	ldr r1, [r5, #0x18]
	ldr r0, _0220E204 ; =0xFFFBFFFF
	and r0, r1
	str r0, [r5, #0x18]
	ldr r0, _0220E208 ; =0x000008B6
	bl PlaySE
_0220DFC6:
	ldr r2, [r5, #0x18]
	ldr r1, _0220E20C ; =0xFFF7FFFF
	add r0, r5, #0
	and r1, r2
	ldr r2, [sp, #0x18]
	add r0, #0x18
	lsl r2, r2, #0x1f
	lsr r2, r2, #0xc
	orr r1, r2
	str r1, [r5, #0x18]
	lsl r1, r1, #0xd
	lsr r1, r1, #0x1f
	beq _0220E058
	ldr r1, [r0]
	ldr r2, _0220E1FC ; =0xFFFF00FF
	and r2, r1
	lsl r1, r1, #0x10
	lsr r1, r1, #0x18
	sub r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x10
	orr r1, r2
	str r1, [r0]
	ldr r0, [r5, #0x18]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x18
	bne _0220E006
	add r0, r4, #0
	mov r1, #0
	bl ov96_021EAB38
	b _0220E1B4
_0220E006:
	ldr r1, [r5, #0x14]
	ldr r0, _0220E210 ; =0x0000019A
	sub r0, r1, r0
	str r0, [r5, #0x14]
	bl _fflt
	ldr r1, _0220E214 ; =0x45800000
	bl _fdiv
	add r1, r0, #0
	add r0, r4, #0
	add r2, r1, #0
	bl ov96_021EB10C
	add r0, sp, #0x30
	str r0, [sp]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0xc]
	ldrb r1, [r1, #4]
	ldrb r2, [r2, #0x10]
	add r0, r4, #0
	add r3, sp, #0x34
	bl ov96_021EB06C
	ldr r0, [sp, #0x30]
	cmp r0, #0xb4
	bge _0220E03E
	b _0220E1B4
_0220E03E:
	ldr r0, [r5, #0x18]
	mov r3, #1
	lsl r0, r0, #0x10
	lsr r1, r0, #0x18
	mov r0, #6
	sub r0, r0, r1
	lsl r2, r0, #2
	ldr r1, [sp, #0x3c]
	add r0, r4, #0
	add r2, r7, r2
	bl ov96_021EB01C
	b _0220E1B4
_0220E058:
	ldr r0, [sp, #4]
	ldr r2, [sp, #0x38]
	ldr r0, [r0, #0x1c]
	mov r3, #1
	lsl r0, r0, #8
	lsr r1, r0, #8
	ldr r0, [sp, #0x10]
	lsr r1, r0
	mov r0, #3
	and r0, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r1, [sp, #0x3c]
	add r0, r4, #0
	bl ov96_021EB01C
	add r0, r4, #0
	add r1, r7, #1
	bl ov96_021EAC0C
	ldr r0, [sp, #4]
	ldr r0, [r0, #0x20]
	lsl r0, r0, #1
	lsr r0, r0, #0x14
	add r1, r0, #0
	lsr r1, r6
	mov r0, #1
	tst r0, r1
	beq _0220E10C
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	str r0, [sp, #0x20]
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	ldr r1, [sp, #0x20]
	lsl r2, r2, #0x18
	lsl r1, r1, #0x18
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_0220F378
	add r7, r0, #0
	ldr r0, [sp, #8]
	bl ov96_021E5F24
	ldr r1, [sp, #0x20]
	cmp r1, r0
	bne _0220E0E6
	ldr r0, [r5, #0x18]
	lsl r1, r0, #0xf
	lsr r1, r1, #0x1f
	bne _0220E0E6
	lsl r0, r0, #0xe
	lsr r0, r0, #0x1f
	bne _0220E0E6
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _0220E0E0
	ldr r0, _0220E218 ; =0x000005F3
	bl PlaySE
	b _0220E0E6
_0220E0E0:
	ldr r0, _0220E21C ; =0x000008C5
	bl PlaySE
_0220E0E6:
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _0220E100
	add r0, r5, #4
	add r1, r4, #0
	bl ov96_0220D52C
	mov r0, #2
	ldr r1, [r5, #0x18]
	lsl r0, r0, #0x10
	orr r0, r1
	str r0, [r5, #0x18]
	b _0220E114
_0220E100:
	mov r0, #1
	ldr r1, [r5, #0x18]
	lsl r0, r0, #0x10
	orr r0, r1
	str r0, [r5, #0x18]
	b _0220E114
_0220E10C:
	ldr r1, [r5, #0x18]
	ldr r0, _0220E220 ; =0xFFFDFFFF
	and r0, r1
	str r0, [r5, #0x18]
_0220E114:
	ldr r0, [r5, #0x18]
	lsl r0, r0, #0xf
	lsr r0, r0, #0x1f
	beq _0220E1B4
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	lsl r1, r7, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #8]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	bl ov96_0220F378
	ldr r1, [r5, #0x18]
	add r2, sp, #0x2c
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r7, r0, #0
	bl ov96_0220E8C0
	add r3, r0, #0
	ldr r2, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	add r2, r2, r3
	add r0, r4, #0
	mov r3, #0
	bl ov96_021EB01C
	ldr r1, [sp, #0x2c]
	add r0, r4, #0
	add r2, r1, #0
	bl ov96_021EB10C
	add r0, r7, #0
	bl ov96_0220F3B4
	ldr r7, [r5, #0x18]
	add r3, r0, #0
	add r2, r5, #0
	ldr r0, [sp, #0x24]
	add r1, r7, #0
	bic r1, r0
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	orr r0, r1
	str r0, [r5, #0x18]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r2, #0x18
	cmp r0, r3
	bls _0220E1B4
	ldr r1, [r2]
	ldr r0, _0220E224 ; =0xFFFEFFFF
	mov r3, #0
	and r1, r0
	ldr r0, [sp, #0x28]
	bic r1, r0
	str r1, [r2]
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x38]
	add r0, r4, #0
	bl ov96_021EB01C
	mov r1, #0xfe
	lsl r1, r1, #0x16
	add r0, r4, #0
	add r2, r1, #0
	bl ov96_021EB10C
_0220E1B4:
	ldr r0, [sp, #0x14]
	add r6, r6, #1
	add r0, #8
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r5, #0x1c
	add r0, r0, #2
	str r0, [sp, #0x10]
	cmp r6, #0xc
	bge _0220E1CA
	b _0220DEDE
_0220E1CA:
	mov r0, #0
	str r0, [sp]
	ldr r3, _0220E228 ; =ov96_0220DE90
	add r0, sp, #0x40
	mov r1, #0xc
	mov r2, #8
	bl MATH_QSort
	mov r5, #0
	add r4, sp, #0x40
_0220E1DE:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _0220E1E8
	bl GF_AssertFail
_0220E1E8:
	ldr r0, [r4, #4]
	add r1, r5, #7
	bl ov96_021EABA8
	add r5, r5, #1
	add r4, #8
	cmp r5, #0xc
	blt _0220E1DE
	add sp, #0xa0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0220E1FC: .word 0xFFFF00FF
_0220E200: .word 0x0000089E
_0220E204: .word 0xFFFBFFFF
_0220E208: .word 0x000008B6
_0220E20C: .word 0xFFF7FFFF
_0220E210: .word 0x0000019A
_0220E214: .word 0x45800000
_0220E218: .word 0x000005F3
_0220E21C: .word 0x000008C5
_0220E220: .word 0xFFFDFFFF
_0220E224: .word 0xFFFEFFFF
_0220E228: .word ov96_0220DE90
	thumb_func_end ov96_0220DEAC

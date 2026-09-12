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

	thumb_func_start ov96_02212F94
ov96_02212F94: ; 0x02212F94
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	add r4, r1, #0
	str r2, [sp]
	add r1, sp, #0x1c
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r1, r5, #0
	add r1, #0x40
	ldrb r1, [r1]
	cmp r1, #3
	bhi _02213032
	add r1, r4, #0
	add r1, #0x40
	ldrb r1, [r1]
	cmp r1, #3
	bls _02213006
	add r0, r4, #0
	add r0, #0x39
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x39
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x3c
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x3c
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x3d
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x3d
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x3e
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x3e
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x40
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x40
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x41
	ldrb r1, [r0]
	add r0, r5, #0
	add r0, #0x41
	strb r1, [r0]
	b _0221305C
_02213006:
	add r1, r5, #0
	add r1, #0x39
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x3c
	strb r0, [r1]
	add r1, r5, #0
	mov r2, #0x1e
	add r1, #0x3d
	strb r2, [r1]
	add r1, r5, #0
	mov r2, #1
	add r1, #0x3e
	strb r2, [r1]
	add r1, r5, #0
	mov r2, #3
	add r1, #0x40
	strb r2, [r1]
	add r1, r5, #0
	add r1, #0x41
	strb r0, [r1]
	b _0221305C
_02213032:
	add r1, r5, #0
	add r1, #0x39
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x3c
	strb r0, [r1]
	add r1, r5, #0
	mov r2, #0x1e
	add r1, #0x3d
	strb r2, [r1]
	add r1, r5, #0
	mov r2, #1
	add r1, #0x3e
	strb r2, [r1]
	add r1, r5, #0
	mov r2, #3
	add r1, #0x40
	strb r2, [r1]
	add r1, r5, #0
	add r1, #0x41
	strb r0, [r1]
_0221305C:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r5, #0
	add r0, #8
	add r1, #8
	add r2, #0x20
	bl VEC_Subtract
	add r0, r5, #0
	add r0, #0x20
	bl VEC_Mag
	cmp r0, #0
	bne _022130B4
	ldr r3, _022130E4 ; =ov96_0221D268
	add r2, sp, #0x10
	ldmia r3!, {r0, r1}
	add r6, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r3, _022130E8 ; =ov96_0221D280
	str r0, [r2]
	add r7, sp, #4
	ldmia r3!, {r0, r1}
	add r2, r7, #0
	stmia r7!, {r0, r1}
	ldr r0, [r3]
	str r0, [r7]
	ldr r0, [sp]
	cmp r0, #0
	bne _022130A8
	add r2, r5, #0
	ldmia r6!, {r0, r1}
	add r2, #0x20
	stmia r2!, {r0, r1}
	ldr r0, [r6]
	str r0, [r2]
	b _022130B4
_022130A8:
	add r3, r5, #0
	ldmia r2!, {r0, r1}
	add r3, #0x20
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	str r0, [r3]
_022130B4:
	add r0, r5, #0
	add r0, #0x20
	add r1, r0, #0
	bl VEC_Normalize
	add r0, r5, #0
	add r0, #0x40
	ldrb r0, [r0]
	add r1, r5, #0
	add r3, r5, #0
	lsl r0, r0, #0xc
	add r1, #0x20
	add r2, sp, #0x1c
	add r3, #0x14
	bl VEC_MultAdd
	add r4, #0x3b
	ldrb r0, [r4]
	cmp r0, #0xc
	bhs _022130E0
	add r5, #0x3b
	strb r0, [r5]
_022130E0:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022130E4: .word ov96_0221D268
_022130E8: .word ov96_0221D280
	thumb_func_end ov96_02212F94


	thumb_func_start ov96_022130EC
ov96_022130EC: ; 0x022130EC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	str r0, [sp, #4]
	bl PokeathlonCourse_GetHeapAllocPtr4
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	ldr r1, _022132F0 ; =0x0000062C
	str r0, [sp, #0x14]
	add r5, r0, r1
	add r0, #0x5c
	str r0, [sp, #0x14]
_02213108:
	add r0, r5, #0
	add r0, #0x38
	ldrb r0, [r0]
	cmp r0, #0
	beq _02213172
	add r0, r5, #0
	add r0, #0x39
	ldrb r0, [r0]
	cmp r0, #0
	beq _02213120
	cmp r0, #2
	bne _02213172
_02213120:
	ldr r1, [r5, #8]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x18]
	ldr r1, [r5, #0xc]
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	str r0, [sp, #0x1c]
	add r0, r5, #0
	bl ov96_022143DC
	ldr r1, _022132F4 ; =ov96_0221D474
	lsl r2, r0, #4
	str r0, [sp, #8]
	ldr r0, _022132F4 ; =ov96_0221D474
	add r1, r1, r2
	add r0, r0, r2
	add r1, #8
	add r2, sp, #0x18
	bl sub_02020E80
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	beq _02213172
	add r1, r5, #0
	add r1, #0x39
	mov r0, #1
	strb r0, [r1]
	add r1, r5, #0
	add r1, #0x3a
	mov r0, #0xa
	strb r0, [r1]
	add r0, r5, #0
	add r0, #0x3b
	ldrb r4, [r0]
	cmp r4, #0xc
	bne _02213174
_02213172:
	b _022132DC
_02213174:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x5d
	lsl r0, r0, #2
	add r2, r7, #0
	mul r2, r0
	ldr r0, [sp, #0x14]
	add r6, r1, #0
	add r4, r0, r2
	mov r0, #0x7c
	mul r6, r0
	ldr r0, [sp, #8]
	cmp r0, r7
	bne _02213238
	add r0, r4, r6
	add r0, #0x5e
	ldrh r0, [r0]
	cmp r0, #0
	beq _022131B6
	add r0, r4, r6
	add r0, #0x5e
	ldrh r0, [r0]
	sub r1, r0, #1
	add r0, r4, r6
	add r0, #0x5e
	strh r1, [r0]
_022131B6:
	add r0, r5, #0
	add r0, #0x3b
	ldrb r0, [r0]
	mov r1, #3
	bl _s32_div_f
	lsl r1, r0, #2
	ldr r0, [sp, #0xc]
	add r0, r0, r1
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	cmp r1, #0
	beq _022131DA
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	sub r2, r1, #1
	ldr r1, _022132F8 ; =0x000006F4
	str r2, [r0, r1]
_022131DA:
	add r0, r5, #0
	add r0, #0x3b
	ldrb r6, [r0]
	mov r1, #3
	add r0, r6, #0
	bl _s32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r4, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #8
	bl ov96_021E8228
	add r0, r5, #0
	add r0, #0x3b
	ldrb r6, [r0]
	mov r1, #3
	add r0, r6, #0
	bl _s32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r4, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #1
	bl ov96_021E8228
	b _022132DC
_02213238:
	add r0, r5, #0
	add r0, #0x38
	ldrb r0, [r0]
	mov r7, #0
	cmp r0, #1
	bne _02213248
	mov r7, #1
	b _02213254
_02213248:
	cmp r0, #2
	bne _02213250
	mov r7, #2
	b _02213254
_02213250:
	bl GF_AssertFail
_02213254:
	add r0, r4, r6
	add r0, #0x5e
	ldrh r0, [r0]
	add r0, r0, r7
	cmp r0, #0x63
	bgt _0221326E
	add r0, r4, r6
	add r0, #0x5e
	ldrh r0, [r0]
	add r1, r0, r7
	add r0, r4, r6
	add r0, #0x5e
	strh r1, [r0]
_0221326E:
	add r0, r5, #0
	add r0, #0x3b
	ldrb r0, [r0]
	mov r1, #3
	bl _s32_div_f
	lsl r1, r0, #2
	ldr r0, [sp, #0xc]
	add r0, r0, r1
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	add r1, r7, r1
	cmp r1, #0x63
	bgt _02213294
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	add r2, r1, r7
	ldr r1, _022132F8 ; =0x000006F4
	str r2, [r0, r1]
_02213294:
	ldr r0, [sp, #8]
	lsl r1, r0, #2
	ldr r0, [sp, #0xc]
	add r0, r0, r1
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	cmp r1, #0
	beq _022132AE
	ldr r1, _022132F8 ; =0x000006F4
	ldr r1, [r0, r1]
	sub r2, r1, #1
	ldr r1, _022132F8 ; =0x000006F4
	str r2, [r0, r1]
_022132AE:
	add r0, r5, #0
	add r0, #0x3b
	ldrb r6, [r0]
	mov r1, #3
	add r0, r6, #0
	bl _s32_div_f
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r1, #0
	mov r0, #1
	str r0, [sp]
	lsl r1, r4, #0x18
	lsl r2, r2, #0x18
	ldr r0, [sp, #4]
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	mov r3, #3
	bl ov96_021E8228
_022132DC:
	ldr r0, [sp, #0x10]
	add r5, #0x4c
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #2
	bge _022132EA
	b _02213108
_022132EA:
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022132F0: .word 0x0000062C
_022132F4: .word ov96_0221D474
_022132F8: .word 0x000006F4
	thumb_func_end ov96_022130EC

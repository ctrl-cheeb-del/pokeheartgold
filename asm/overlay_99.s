	.include "asm/macros.inc"
	.include "overlay_99.inc"
	.include "global.inc"

	.text
	.public PokeathlonCourseRecord_Exit
	.public PokeathlonCourseRecord_Init
	.public PokeathlonCourseRecord_Main
	.public PokeathlonEventRecord_Exit
	.public PokeathlonEventRecord_Init
	.public PokeathlonEventRecord_Main
	.public PokeathlonMedals_Exit
	.public PokeathlonMedals_Init
	.public PokeathlonMedals_Main
	.public _021E954C
	.public _021EA5C0
	.public _021EA5CC
	.public _021EA5D8
	.public _021EA5E4
	.public ov99_021E5B90
	.public ov99_021E5BB4
	.public ov99_021E5BD8
	.public ov99_021E5C20
	.public ov99_021E5C4C
	.public ov99_021E5C88
	.public ov99_021E5D2C
	.public ov99_021E5D58
	.public ov99_021E5EB4
	.public ov99_021E5F74
	.public ov99_021E5FE8
	.public ov99_021E6018
	.public ov99_021E6050
	.public ov99_021E607C
	.public ov99_021E6144
	.public ov99_021E6188
	.public ov99_021E6218
	.public ov99_021E6250
	.public ov99_021E6274
	.public ov99_021E6400
	.public ov99_021E6438
	.public ov99_021E64E0
	.public ov99_021E6530
	.public ov99_021E6638
	.public ov99_021E677C
	.public ov99_021E6840
	.public ov99_021E6888
	.public ov99_021E6938
	.public ov99_021E695C
	.public ov99_021E69D8
	.public ov99_021E6A70
	.public ov99_021E6A9C
	.public ov99_021E6C30
	.public ov99_021E6CF4
	.public ov99_021E6D14
	.public ov99_021E6D34
	.public ov99_021E6F70
	.public ov99_021E6FA0
	.public ov99_021E6FD0
	.public ov99_021E7100
	.public ov99_021E7124
	.public ov99_021E7158
	.public ov99_021E71B0
	.public ov99_021E71E4
	.public ov99_021E7208
	.public ov99_021E7258
	.public ov99_021E728C
	.public ov99_021E72C0
	.public ov99_021E738C
	.public ov99_021E73E0
	.public ov99_021E7428
	.public ov99_021E7450
	.public ov99_021E7508
	.public ov99_021E7598
	.public ov99_021E76D8
	.public ov99_021E7758
	.public ov99_021E7794
	.public ov99_021E77D8
	.public ov99_021E7A54
	.public ov99_021E7A78
	.public ov99_021E7AB8
	.public ov99_021E7AD4
	.public ov99_021E7BC8
	.public ov99_021E7C58
	.public ov99_021E7CE4
	.public ov99_021E7D30
	.public ov99_021E7DA4
	.public ov99_021E7EBC
	.public ov99_021E7EF0
	.public ov99_021E7F64
	.public ov99_021E7F90
	.public ov99_021E80D0
	.public ov99_021E810C
	.public ov99_021E8198
	.public ov99_021E8224
	.public ov99_021E82E4
	.public ov99_021E84EC
	.public ov99_021E8518
	.public ov99_021E8544
	.public ov99_021E856C
	.public ov99_021E8590
	.public ov99_021E860C
	.public ov99_021E86D4
	.public ov99_021E875C
	.public ov99_021E8788
	.public ov99_021E87D0
	.public ov99_021E8828
	.public ov99_021E88EC
	.public ov99_021E89A4
	.public ov99_021E89EC
	.public ov99_021E8C04
	.public ov99_021E8C50
	.public ov99_021E8C88
	.public ov99_021E8D5C
	.public ov99_021E8D88
	.public ov99_021E8EBC
	.public ov99_021E8F50
	.public ov99_021E8FEC
	.public ov99_021E9038
	.public ov99_021E90F4
	.public ov99_021E92EC
	.public ov99_021E93DC
	.public ov99_021E9430
	.public ov99_021E9464
	.public ov99_021E94CC
	.public ov99_021E9518
	.public ov99_021E9554
	.public ov99_021E9564
	.public ov99_021E9574
	.public ov99_021E9576
	.public ov99_021E958C
	.public ov99_021E95A4
	.public ov99_021E95BC
	.public ov99_021E95D8
	.public ov99_021E95DC
	.public ov99_021E9600
	.public ov99_021E9628
	.public ov99_021E9650
	.public ov99_021E9690
	.public ov99_021E96D8
	.public ov99_021E9760
	.public ov99_021E9840
	.public ov99_021E9D88
	.public ov99_021E9D8C
	.public ov99_021E9D9C
	.public ov99_021E9DAC
	.public ov99_021E9DBC
	.public ov99_021E9DD4
	.public ov99_021E9DEC
	.public ov99_021E9E04
	.public ov99_021E9E2C
	.public ov99_021E9E60
	.public ov99_021E9ED0
	.public ov99_021E9F4C
	.public ov99_021E9F54
	.public ov99_021E9F60
	.public ov99_021E9F70
	.public ov99_021E9F80
	.public ov99_021E9F90
	.public ov99_021E9FA0
	.public ov99_021E9FB0
	.public ov99_021E9FC4
	.public ov99_021E9FDC
	.public ov99_021EA03C
	.public ov99_021EA0BC
	.public ov99_021EA180
	.public ov99_021EA250
	.public ov99_021EA348
	.public ov99_021EA350
	.public ov99_021EA35A
	.public ov99_021EA364
	.public ov99_021EA374
	.public ov99_021EA384
	.public ov99_021EA38C
	.public ov99_021EA394
	.public ov99_021EA3AC
	.public ov99_021EA3C4
	.public ov99_021EA3F4
	.public ov99_021EA45C
	.public ov99_021EA4F4
	.public ov99_021EA59C

	.public ov99_021E5B54
	.public ov99_021E5B70
	.public ov99_021E5B74
	.public ov99_021E5B7C
	.public ov99_021E6C14
	.public ov99_021E7060
	.public ov99_021E7068
	.public ov99_021E7078
	.public ov99_021E7088
	.public ov99_021E7098
	.public ov99_021E70A8
	.public ov99_021E70B8
	.public ov99_021E70C8
	.public ov99_021E70D8
	.public ov99_021E70E8
	.public ov99_021E714C
	.public ov99_021E7150
	.public ov99_021E7180
	.public ov99_021E718C
	.public ov99_021E7198
	.public ov99_021E71DC
	.public ov99_021E723C
	.public ov99_021E724C
	.public ov99_021E7CA8
	.public ov99_021E7CC8
	.public ov99_021E7CCC
	.public ov99_021E7CD8
	.public ov99_021E8818
	.public ov99_021E88D4
	.public ov99_021E9020
	.public ov99_021E9418
	.public ov99_021E945C
	.public ov99_021E94FC
	.public ov99_021E9508

	thumb_func_start PokeathlonCourseRecord_Init
PokeathlonCourseRecord_Init: ; 0x021E5900
	push {r4, r5, lr}
	sub sp, #0x1c
	add r4, r0, #0
	ldr r0, _021E59F0 ; =FS_OVERLAY_ID(OVY_98)
	mov r1, #2
	bl HandleLoadOverlay
	add r0, r4, #0
	bl OverlayManager_GetArgs
	add r5, r0, #0
	bne _021E591C
	bl GF_AssertFail
_021E591C:
	mov r0, #3
	mov r1, #0x84
	lsl r2, r0, #0x10
	bl Heap_Create
	add r0, r4, #0
	mov r1, #0x94
	mov r2, #0x84
	bl OverlayManager_CreateAndGetData
	mov r1, #0
	mov r2, #0x94
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x84
	str r0, [r4, #0xc]
	add r0, r4, #0
	mov r1, #0
	add r0, #0x8c
	str r1, [r0]
	add r0, r4, #0
	mov r1, #1
	add r0, #0x90
	str r1, [r0]
	add r0, r4, #0
	add r0, #0x84
	str r1, [r0]
	add r0, r4, #0
	add r1, r5, #0
	bl ov99_021E5B54
	bl ov98_0221F090
	add r0, r4, #0
	bl ov99_021E5C88
	add r0, r4, #0
	bl ov99_021E5D58
	ldr r0, _021E59F4 ; =0x0000013A
	ldr r3, _021E59F8 ; =ov99_021E96D8
	str r0, [sp]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #4]
	mov r2, #0x11
	bl ov98_0221EABC
	add r3, sp, #4
	ldr r5, _021E59FC ; =ov99_021E95A4
	str r0, [r4, #0x10]
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r1, r2, #0
	ldr r0, [r4, #0xc]
	mov r2, #0x1a
	bl ov98_0221E5E0
	str r0, [r4, #0x14]
	add r0, r4, #0
	bl ov99_021E6274
	add r0, r4, #0
	bl ov99_021E6438
	add r0, r4, #0
	mov r1, #0
	bl ov99_021E64E0
	add r0, r4, #0
	mov r1, #0
	bl ov99_021E5FE8
	add r0, r4, #0
	mov r1, #0
	bl ov99_021E6050
	add r0, r4, #0
	mov r1, #0
	bl ov99_021E6530
	add r0, r4, #0
	bl ov99_021E6018
	mov r0, #2
	mov r1, #4
	bl SetKeyRepeatTimers
	mov r0, #0
	bl ResetVisibleHardwareWindows
	mov r0, #1
	bl ResetVisibleHardwareWindows
	ldr r0, _021E5A00 ; =ov99_021E6250
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #1
	add sp, #0x1c
	pop {r4, r5, pc}
	.balign 4, 0
_021E59F0: .word FS_OVERLAY_ID(OVY_98)
_021E59F4: .word 0x0000013A
_021E59F8: .word ov99_021E96D8
_021E59FC: .word ov99_021E95A4
_021E5A00: .word ov99_021E6250
	thumb_func_end PokeathlonCourseRecord_Init


	thumb_func_start PokeathlonCourseRecord_Exit
PokeathlonCourseRecord_Exit: ; 0x021E5A04
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	ldr r0, [r4]
	bl ov99_021E5B74
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x84
	bl Heap_Destroy
	ldr r0, _021E5A34 ; =FS_OVERLAY_ID(OVY_98)
	bl UnloadOverlayByID
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_021E5A34: .word FS_OVERLAY_ID(OVY_98)
	thumb_func_end PokeathlonCourseRecord_Exit


	thumb_func_start PokeathlonCourseRecord_Main
PokeathlonCourseRecord_Main: ; 0x021E5A38
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	bl ov99_021E5F74
	add r0, r4, #0
	add r0, #0x90
	ldr r0, [r0]
	cmp r0, #1
	bne _021E5A86
	add r1, r4, #0
	add r1, #0x88
	ldr r1, [r1]
	add r0, r4, #0
	bl ov99_021E5FE8
	add r1, r4, #0
	add r1, #0x88
	ldr r1, [r1]
	add r0, r4, #0
	bl ov99_021E6050
	add r1, r4, #0
	add r1, #0x88
	ldr r1, [r1]
	add r0, r4, #0
	bl ov99_021E6530
	add r0, r4, #0
	mov r1, #0
	add r0, #0x90
	str r1, [r0]
	add r0, r4, #0
	mov r1, #1
	add r0, #0x8c
	str r1, [r0]
_021E5A86:
	ldr r0, [r5]
	cmp r0, #4
	bhi _021E5B36
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E5A98: ; jump table
	.short _021E5AA2 - _021E5A98 - 2 ; case 0
	.short _021E5ABE - _021E5A98 - 2 ; case 1
	.short _021E5ACC - _021E5A98 - 2 ; case 2
	.short _021E5B04 - _021E5A98 - 2 ; case 3
	.short _021E5B12 - _021E5A98 - 2 ; case 4
_021E5AA2:
	mov r0, #6
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r4, #0xc]
	add r2, r1, #0
	str r0, [sp, #8]
	mov r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #1
	str r0, [r5]
	b _021E5B40
_021E5ABE:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5B40
	mov r0, #2
	str r0, [r5]
	b _021E5B40
_021E5ACC:
	add r0, r4, #0
	bl ov99_021E6638
	cmp r0, #0
	beq _021E5B40
	add r0, r4, #0
	add r0, #0x8c
	ldr r0, [r0]
	cmp r0, #0
	bne _021E5B40
	ldr r0, _021E5B4C ; =0x000005DC
	bl PlaySE
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r4, #0xc]
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #3
	str r0, [r5]
	b _021E5B40
_021E5B04:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021E5B40
	mov r0, #4
	str r0, [r5]
	b _021E5B40
_021E5B12:
	ldr r0, [r4, #0x10]
	mov r1, #0x11
	bl ov98_0221EB84
	add r0, r4, #0
	bl ov99_021E5D2C
	ldr r0, [r4, #0x14]
	add r4, #0x18
	add r1, r4, #0
	mov r2, #0x1a
	bl ov98_0221E684
	bl ov98_0221F0EC
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_021E5B36:
	ldr r0, _021E5B50 ; =_021EA5C0
	cmp r0, #0
	beq _021E5B40
	bl GF_AssertFail
_021E5B40:
	ldr r0, [r4, #0x14]
	bl ov98_0221E6CC
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_021E5B4C: .word 0x000005DC
_021E5B50: .word _021EA5C0
	thumb_func_end PokeathlonCourseRecord_Main

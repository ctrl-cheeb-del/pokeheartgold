	.include "asm/macros.inc"
	.include "overlay_47.inc"
	.include "global.inc"
	.include "overlay47_exact_bank.inc"

	.text
	.public ov47_02258A14
	.public ov47_02258A1C
	.public ov47_02258A60
	.public ov47_02258A80
	.public ov47_02258A8C
	.public ov47_02258B8C
	.public ov47_02258C44
	.public ov47_02258CC0
	.public ov47_02258CEC
	.public ov47_02258D18
	.public ov47_02258D44
	.public ov47_02258D78
	.public ov47_02258DA8
	.public ov47_02258DB4
	.public ov47_022591F8
	.public ov47_0225921C
	.public ov47_02259228
	.public ov47_02259278
	.public ov47_022592B4
	.public ov47_02259318
	.public ov47_02259384
	.public ov47_022593A0
	.public ov47_022593B4
	.public ov47_022593CC
	.public ov47_02259404
	.public ov47_02259430
	.public ov47_02259448
	.public ov47_0225945C
	.public ov47_0225946C
	.public ov47_02259968
	.public ov47_0225999C
	.public ov47_02259B30
	.public ov47_02259D24
	.public ov47_02259D40
	.public ov47_02259D58
	.public ov47_02259DA4
	.public ov47_02259DCC

	thumb_func_start ov47_02258800
ov47_02258800: ; 0x02258800
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r4, r0, #0
	bl OverlayManager_GetArgs
	mov r2, #5
	add r5, r0, #0
	mov r0, #3
	mov r1, #0x81
	lsl r2, r2, #0x10
	bl Heap_Create
	mov r1, #0xa3
	add r0, r4, #0
	lsl r1, r1, #2
	mov r2, #0x81
	bl OverlayManager_CreateAndGetData
	mov r2, #0xa3
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl memset
	ldr r1, [r5]
	add r0, r4, #0
	mov r2, #0x81
	bl ov47_02258A1C
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r1, [r5, #4]
	add r0, r4, r0
	mov r2, #0x81
	bl ov47_02258C70
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r2, [r5]
	add r0, r4, r0
	add r1, r4, #0
	mov r3, #0x81
	bl ov47_02259228
	ldr r0, [r5, #8]
	cmp r0, #2
	blt _02258862
	bl GF_AssertFail
_02258862:
	mov r1, #0x81
	str r1, [sp]
	add r3, r5, #0
	ldr r5, [r5, #8]
	add r0, r1, #0
	lsl r6, r5, #2
	ldr r5, _02258890 ; =ov47_02259FB0
	add r0, #0xf7
	add r1, #0xc3
	ldr r5, [r5, r6]
	add r0, r4, r0
	add r1, r4, r1
	add r2, r4, #0
	blx r5
	ldr r0, _02258894 ; =ov47_02258A14
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	mov r0, #1
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_02258890: .word ov47_02259FB0
_02258894: .word ov47_02258A14
	thumb_func_end ov47_02258800


	thumb_func_start ov47_02258898
ov47_02258898: ; 0x02258898
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	add r4, r1, #0
	bl OverlayManager_GetData
	add r7, r0, #0
	add r0, r5, #0
	bl OverlayManager_GetArgs
	add r5, r0, #0
	ldr r0, [r4]
	cmp r0, #4
	bhi _02258996
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022588C0: ; jump table
	.short _022588CA - _022588C0 - 2 ; case 0
	.short _022588F0 - _022588C0 - 2 ; case 1
	.short _02258900 - _022588C0 - 2 ; case 2
	.short _0225895E - _022588C0 - 2 ; case 3
	.short _0225897E - _022588C0 - 2 ; case 4
_022588CA:
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x81
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r5, #4]
	mov r1, #1
	bl ov45_0222A520
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258996
_022588F0:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _02258996
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258996
_02258900:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _02258930
	ldr r0, [r5, #4]
	bl ov45_0222A330
	cmp r0, #1
	bne _02258920
	ldr r0, [r5, #4]
	bl ov45_0222A4A8
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258996
_02258920:
	bl ov45_0222D844
	cmp r0, #1
	bne _02258930
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258996
_02258930:
	mov r1, #0x81
	str r5, [sp]
	str r1, [sp, #4]
	ldr r5, [r5, #8]
	add r0, r1, #0
	lsl r6, r5, #2
	ldr r5, _022589A4 ; =ov47_02259FA8
	mov r3, #0x9a
	add r0, #0xf7
	add r1, #0xc3
	lsl r3, r3, #2
	ldr r5, [r5, r6]
	add r0, r7, r0
	add r1, r7, r1
	add r2, r7, #0
	add r3, r7, r3
	blx r5
	cmp r0, #1
	bne _02258996
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258996
_0225895E:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x81
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258996
_0225897E:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _02258996
	mov r0, #0x9a
	lsl r0, r0, #2
	add r0, r7, r0
	bl ov47_022593A0
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02258996:
	add r0, r7, #0
	bl ov47_02258A80
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_022589A4: .word ov47_02259FA8
	thumb_func_end ov47_02258898


	thumb_func_start ov47_022589A8
ov47_022589A8: ; 0x022589A8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, r5, #0
	bl OverlayManager_GetArgs
	add r6, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	ldr r3, [r6, #8]
	mov r1, #0x5e
	lsl r6, r3, #2
	ldr r3, _02258A10 ; =_02259FA0
	lsl r1, r1, #2
	add r0, r4, r1
	sub r1, #0x34
	ldr r3, [r3, r6]
	add r1, r4, r1
	add r2, r4, #0
	blx r3
	mov r0, #0x9a
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0x81
	bl ov47_02259278
	mov r0, #0x51
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov47_02258CC0
	add r0, r4, #0
	bl ov47_02258A60
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x81
	bl Heap_Destroy
	mov r0, #0
	bl sub_0200616C
	mov r0, #1
	pop {r4, r5, r6, pc}
	nop
_02258A10: .word _02259FA0
	thumb_func_end ov47_022589A8

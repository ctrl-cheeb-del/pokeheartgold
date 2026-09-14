	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public GF_CosDeg
	.public GF_SinDeg
	.public ManagedSprite_GetPositionXY
	.public ManagedSprite_SetAffineOverwriteMode
	.public ManagedSprite_SetAffineScale
	.public ManagedSprite_SetAnim
	.public ManagedSprite_SetDrawFlag
	.public ManagedSprite_SetPaletteOverride
	.public ManagedSprite_SetPositionXY
	.public ManagedSprite_SetPositonFxXY
	.public ManagedSprite_TickFrame
	.public PaletteData_GetFadedBuf
	.public PaletteData_SetAutoTransparent
	.public Save_VarsFlags_Get
	.public Save_VarsFlags_GetBattleArcadePrintProgress
	.public Save_VarsFlags_GetBattleCastlePrintProgress
	.public Save_VarsFlags_GetBattleFactoryPrintProgress
	.public Save_VarsFlags_GetBattleHallPrintProgress
	.public Save_VarsFlags_GetBattleTowerPrintProgress
	.public SpriteManager_UnloadAnimObjById
	.public SpriteManager_UnloadCellObjById
	.public SpriteManager_UnloadCharObjById
	.public SpriteManager_UnloadPlttObjById
	.public SpriteSystem_NewSprite
	.public Sprite_DeleteAndFreeResources
	.public _fadd
	.public _fsub
	.public _s32_div_f
	.public ov40_0222D288
	.public ov40_0222DA00
	.public ov40_022334F8
	.public ov40_02233550
	.public ov40_022335F4
	.public ov40_022338D0
	.public ov40_022339CC
	.public ov40_02233AEC
	.public ov40_02245174
	.public ov40_022451B0
	.text

	thumb_func_start ov40_02233550
ov40_02233550: ; 0x02233550
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	str r0, [sp]
	ldr r0, [r0, #0x28]
	mov r1, #0x83
	str r0, [sp, #4]
	ldr r0, [sp]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	bl Save_VarsFlags_Get
	add r4, r0, #0
	bl Save_VarsFlags_GetBattleTowerPrintProgress
	str r0, [sp, #0x30]
	add r0, r4, #0
	bl Save_VarsFlags_GetBattleFactoryPrintProgress
	str r0, [sp, #0x34]
	add r0, r4, #0
	bl Save_VarsFlags_GetBattleArcadePrintProgress
	str r0, [sp, #0x38]
	add r0, r4, #0
	bl Save_VarsFlags_GetBattleCastlePrintProgress
	str r0, [sp, #0x3c]
	add r0, r4, #0
	bl Save_VarsFlags_GetBattleHallPrintProgress
	ldr r3, _022335F0 ; =ov40_02245174
	str r0, [sp, #0x40]
	ldmia r3!, {r0, r1}
	add r2, sp, #8
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r7, #0
	add r4, sp, #0x30
	add r5, sp, #0x1c
	str r0, [r2]
_022335A4:
	ldr r6, [r4]
	cmp r6, #0
	beq _022335D8
	add r3, sp, #8
	ldmia r3!, {r0, r1}
	add r2, sp, #0x1c
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	sub r0, r6, #2
	cmp r0, #1
	bhi _022335D8
	ldr r0, [sp]
	mov r1, #2
	ldr r0, [r0, #0x28]
	bl PaletteData_GetFadedBuf
	ldr r1, [r5]
	mov r2, #0x10
	add r1, r1, #4
	lsl r1, r1, #0x14
	lsr r1, r1, #0x10
	bl ov40_022334F8
_022335D8:
	add r7, r7, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r7, #5
	blt _022335A4
	ldr r0, [sp, #4]
	mov r1, #1
	bl PaletteData_SetAutoTransparent
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_022335F0: .word ov40_02245174
	thumb_func_end ov40_02233550


	thumb_func_start ov40_022335F4
ov40_022335F4: ; 0x022335F4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xa4
	add r7, r0, #0
	mov r0, #0
	str r0, [sp, #0x1c]
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r6, [r7, r0]
	ldr r0, [sp, #0x1c]
	add r1, sp, #0x20
	strh r0, [r1, #0x28]
	mov r0, #1
	lsl r0, r0, #8
	strh r0, [r1, #0x2a]
	ldr r0, [sp, #0x1c]
	ldr r5, [sp, #0x1c]
	strh r0, [r1, #0x2c]
	strh r0, [r1, #0x2e]
	mov r0, #0xa
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x1c]
	mov r1, #1
	str r0, [sp, #0x54]
	str r0, [sp, #0x74]
	str r0, [sp, #0x78]
	sub r0, r1, #2
	str r0, [sp, #0x6c]
	str r0, [sp, #0x70]
	ldr r0, _022338B8 ; =0x0002869F
	str r1, [sp, #0x58]
	str r0, [sp, #0x5c]
	str r0, [sp, #0x60]
	str r0, [sp, #0x64]
	str r0, [sp, #0x68]
	add r4, r6, #0
_0223363A:
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	add r2, sp, #0x48
	bl SpriteSystem_NewSprite
	str r0, [r4, #0x40]
	mov r1, #1
	bl ManagedSprite_SetAnim
	ldr r0, [r4, #0x40]
	bl ManagedSprite_TickFrame
	ldr r1, [r4, #4]
	ldr r0, [r4, #0x40]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #5
	blt _0223363A
	mov r5, #0
	add r4, r6, #0
_02233668:
	ldr r0, _022338BC ; =0x00004705
	add r0, r5, r0
	str r0, [sp, #0x5c]
	str r0, [sp, #0x60]
	cmp r5, #3
	bne _0223367C
	ldr r0, _022338C0 ; =0x00004706
	str r0, [sp, #0x64]
	str r0, [sp, #0x68]
	b _02233682
_0223367C:
	ldr r0, _022338BC ; =0x00004705
	str r0, [sp, #0x64]
	str r0, [sp, #0x68]
_02233682:
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	add r2, sp, #0x48
	bl SpriteSystem_NewSprite
	str r0, [r4, #0x54]
	cmp r5, #3
	ldr r0, [r4, #0x54]
	bne _0223369C
	mov r1, #0
	bl ManagedSprite_SetAnim
	b _022336A2
_0223369C:
	mov r1, #1
	bl ManagedSprite_SetAnim
_022336A2:
	ldr r0, [r4, #0x54]
	bl ManagedSprite_TickFrame
	ldr r1, [r4, #4]
	ldr r0, [r4, #0x54]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	add r1, r5, #0
	ldr r0, [r4, #0x54]
	add r1, #0xa
	bl ManagedSprite_SetPaletteOverride
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #5
	blt _02233668
	ldr r0, _022338C4 ; =0x00006E7A
	str r0, [sp, #0x5c]
	str r0, [sp, #0x60]
	str r0, [sp, #0x64]
	str r0, [sp, #0x68]
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x6c]
	str r0, [sp, #0x70]
	mov r0, #0x14
	str r0, [sp, #0x50]
	mov r0, #0x83
	lsl r0, r0, #4
	ldr r0, [r7, r0]
	bl Save_VarsFlags_Get
	add r4, r0, #0
	bl Save_VarsFlags_GetBattleTowerPrintProgress
	str r0, [sp, #0x7c]
	add r0, r4, #0
	bl Save_VarsFlags_GetBattleFactoryPrintProgress
	str r0, [sp, #0x80]
	add r0, r4, #0
	bl Save_VarsFlags_GetBattleArcadePrintProgress
	str r0, [sp, #0x84]
	add r0, r4, #0
	bl Save_VarsFlags_GetBattleCastlePrintProgress
	str r0, [sp, #0x88]
	add r0, r4, #0
	bl Save_VarsFlags_GetBattleHallPrintProgress
	str r0, [sp, #0x8c]
	mov r0, #0
	str r0, [sp, #4]
	add r0, sp, #0x7c
	ldr r2, _022338C8 ; =ov40_022451B0
	str r0, [sp, #0x10]
	ldmia r2!, {r0, r1}
	add r3, sp, #0x20
	stmia r3!, {r0, r1}
	ldmia r2!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r2]
	add r4, r6, #0
	add r5, sp, #0x34
	str r0, [r3]
_02233728:
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	add r2, sp, #0x48
	bl SpriteSystem_NewSprite
	str r0, [r4, #0x68]
	ldr r0, [sp, #0x10]
	ldr r0, [r0]
	cmp r0, #1
	bhi _0223375E
	ldr r0, [r4, #0x68]
	mov r1, #5
	bl ManagedSprite_SetAnim
	ldr r0, [r4, #0x68]
	mov r1, #9
	bl ManagedSprite_SetPaletteOverride
	ldr r0, [r4, #0x54]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x40]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	b _02233780
_0223375E:
	add r3, sp, #0x20
	ldmia r3!, {r0, r1}
	add r2, sp, #0x34
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r4, #0x68]
	ldr r1, [r5]
	bl ManagedSprite_SetAnim
	ldr r1, [r5]
	ldr r0, [r4, #0x68]
	add r1, r1, #4
	bl ManagedSprite_SetPaletteOverride
_02233780:
	ldr r0, [r4, #0x68]
	bl ManagedSprite_TickFrame
	ldr r1, [r4, #4]
	ldr r0, [r4, #0x68]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	ldr r0, [sp, #0x10]
	add r4, r4, #4
	add r0, r0, #4
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #5
	blt _02233728
	ldr r0, _022338CC ; =0x0000726C
	mov r4, #0xfa
	str r0, [sp, #0x5c]
	str r0, [sp, #0x60]
	str r0, [sp, #0x64]
	str r0, [sp, #0x68]
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x6c]
	str r0, [sp, #0x70]
	mov r0, #2
	str r0, [sp, #0x58]
	mov r0, #0
	str r0, [sp, #0x18]
	str r0, [sp, #0x50]
	add r0, r6, #0
	add r0, #0x90
	ldr r0, [r0]
	lsl r4, r4, #2
	str r0, [sp]
	ldr r0, [sp, #0x18]
	add r5, sp, #0x90
	str r0, [sp, #8]
_022337D2:
	ldr r0, [sp]
	add r1, r4, #0
	bl _s32_div_f
	str r0, [r5]
	ldr r0, [sp]
	add r1, r4, #0
	bl _s32_div_f
	str r1, [sp]
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r4, r0, #0
	ldr r0, [r5]
	cmp r0, #0
	bne _02233804
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _02233804
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	b _02233808
_02233804:
	mov r0, #1
	str r0, [sp, #0x18]
_02233808:
	ldr r0, [sp, #8]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #4
	blt _022337D2
	mov r0, #0xa
	str r0, [sp, #0xa0]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r0, #0x58
	add r4, r6, #0
	add r5, sp, #0x90
	str r0, [sp, #0x14]
_02233824:
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x1c]
	add r2, sp, #0x48
	bl SpriteSystem_NewSprite
	str r0, [r4, #0x7c]
	ldr r0, [r5]
	cmp r0, #0
	bne _02233846
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #0x1c]
	cmp r1, r0
	bge _02233846
	ldr r0, [r4, #0x7c]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_02233846:
	ldr r0, [r4, #0x7c]
	ldr r1, [r5]
	bl ManagedSprite_SetAnim
	ldr r1, [sp, #0x14]
	ldr r0, [r4, #0x7c]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	mov r2, #0x48
	bl ov40_0222D288
	ldr r0, [r4, #0x7c]
	bl ManagedSprite_TickFrame
	ldr r0, [sp, #0x14]
	add r4, r4, #4
	add r0, #0x10
	str r0, [sp, #0x14]
	ldr r0, [sp, #0xc]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #5
	blt _02233824
	add r0, r6, #0
	add r0, #0x88
	ldr r0, [r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r0, r6, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	mov r5, #2
	mov r4, #0
	add r7, r5, #0
_02233894:
	ldr r0, [r6, #0x40]
	add r1, r5, #0
	bl ManagedSprite_SetAffineOverwriteMode
	ldr r0, [r6, #0x54]
	add r1, r7, #0
	bl ManagedSprite_SetAffineOverwriteMode
	ldr r0, [r6, #0x68]
	mov r1, #2
	bl ManagedSprite_SetAffineOverwriteMode
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #5
	blt _02233894
	add sp, #0xa4
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022338B8: .word 0x0002869F
_022338BC: .word 0x00004705
_022338C0: .word 0x00004706
_022338C4: .word 0x00006E7A
_022338C8: .word ov40_022451B0
_022338CC: .word 0x0000726C
	thumb_func_end ov40_022335F4

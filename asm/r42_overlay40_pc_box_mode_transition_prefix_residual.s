	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public BgClearTilemapBufferAndCommit
	.public GfGfx_EngineATogglePlanes
	.public GfGfx_EngineBTogglePlanes
	.public Heap_Free
	.public Main_SetVBlankIntrCB
	.public PaletteData_BlendPalettes
	.public PaletteData_LoadPaletteSlotFromHardware
	.public PlaySE
	.public RequestSwap3DBuffers
	.public SetBgPriority
	.public StopSE
	.public System_GetTouchNew
	.public Thunk_G3X_Reset
	.public TouchHitboxController_Create
	.public TouchHitboxController_Destroy
	.public TouchHitboxController_IsTriggered
	.public TouchscreenHitbox_TouchNewIsIn
	.public UnloadOverlayByID
	.public _s32_div_f
	.public ov39_02227080
	.public ov39_022271C0
	.public ov39_022273F8
	.public ov39_02227D44
	.public ov40_0222BC54
	.public ov40_0222BD04
	.public ov40_0222BF64
	.public ov40_0222BF80
	.public ov40_0222D88C
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222DAA8
	.public ov40_0222DD08
	.public ov40_0222DED0
	.public ov40_0222DFB0
	.public ov40_0222E79C
	.public ov40_0222E7B8
	.public ov40_0222E7DC
	.public ov40_0222E9B8
	.public ov40_0222F38C
	.public ov40_0222F6D0
	.public ov40_0222F720
	.public ov40_0222F734
	.public ov40_0222F740
	.public ov40_0222F920
	.public ov40_0222F9D4
	.public ov40_0222FA24
	.public ov40_0222FA5C
	.public ov40_0222FA88
	.public ov40_0222FB90
	.public ov40_0222FBB4
	.public ov40_0223077C
	.public ov40_022307DC
	.public ov40_02230944
	.public ov40_02230964
	.public ov40_02230CDC
	.public ov40_02234A38
	.public ov40_02234BBC
	.public ov40_02234D94
	.public ov40_02234F98
	.public ov40_0223512C
	.public ov40_0223527C
	.public ov40_0223534C
	.public ov40_02235434
	.public ov40_02235644
	.public ov40_0223584C
	.public ov40_02235868
	.public ov40_022358C0
	.public ov40_02235900
	.public ov40_02235940
	.public ov40_02235994
	.public ov40_022359B4
	.public ov40_02235B10
	.public ov40_02235C7C
	.public ov40_02235FA0
	.public ov40_02235FD0
	.public ov40_02235FFC
	.public ov40_0223610C
	.public ov40_02236130
	.public ov40_0223D540
	.public ov40_0223D5CC
	.public ov40_022451C4
	.public ov40_022451D0
	.public ov40_022451D4
	.public ov40_022451D8
	.public ov40_022451F4
	.public ov40_02245708
	.public ov41_0224B530
	.public ov41_0224B554
	.public ov41_0224B57C
	.public ov41_0224B5D0
	.public sub_020314BC
	.public sub_020879E0
	.public sub_02087A08
	.text

	thumb_func_start ov40_02234A38
ov40_02234A38: ; 0x02234A38
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r5, [r4, r1]
	ldr r1, [r4, #8]
	cmp r1, #4
	bls _02234A4A
	b _02234B90
_02234A4A:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02234A56: ; jump table
	.short _02234A60 - _02234A56 - 2 ; case 0
	.short _02234AA6 - _02234A56 - 2 ; case 1
	.short _02234AEE - _02234A56 - 2 ; case 2
	.short _02234B1A - _02234A56 - 2 ; case 3
	.short _02234B34 - _02234A56 - 2 ; case 4
_02234A60:
	mov r1, #0x3c
	mov r2, #7
	bl ov40_022307DC
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x6d
	str r0, [sp]
	ldr r0, _02234BB0 ; =ov40_02245708
	ldr r2, _02234BB4 ; =ov40_02235FD0
	mov r1, #9
	add r3, r4, #0
	bl TouchHitboxController_Create
	mov r1, #0x1d
	lsl r1, r1, #4
	str r0, [r5, r1]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02234BAC
_02234AA6:
	add r0, r5, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	mov r2, #0
	add r0, r5, #0
	add r1, r5, #4
	add r3, r2, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _02234AD4
	add r0, r4, #0
	mov r1, #0x72
	bl ov40_0222DED0
	add r0, r4, #0
	bl ov40_02235FFC
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_02234AD4:
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02234BAC
_02234AEE:
	mov r0, #0x1d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl TouchHitboxController_IsTriggered
	ldr r0, _02234BB8 ; =ov40_022451C4
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	bne _02234B0C
	mov r0, #0x79
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _02234BAC
_02234B0C:
	add r0, r4, #0
	bl ov40_02230944
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02234BAC
_02234B1A:
	bl ov40_0223610C
	mov r0, #0x1d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl TouchHitboxController_Destroy
	add r0, r4, #0
	bl ov40_0222DFB0
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_02234B34:
	mov r0, #0x79
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _02234B56
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #1
	mov r3, #2
	bl ov40_0222DA00
	cmp r0, #0
	beq _02234BAC
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02234BAC
_02234B56:
	add r0, r5, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #1
	mov r3, #2
	bl ov40_0222DA00
	cmp r0, #0
	beq _02234B76
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_02234B76:
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02234BAC
_02234B90:
	mov r0, #0x79
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _02234BA4
	add r0, r4, #0
	mov r1, #4
	bl ov40_0222BF80
	b _02234BAC
_02234BA4:
	add r0, r4, #0
	mov r1, #5
	bl ov40_0222BF80
_02234BAC:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02234BB0: .word ov40_02245708
_02234BB4: .word ov40_02235FD0
_02234BB8: .word ov40_022451C4
	thumb_func_end ov40_02234A38


	thumb_func_start ov40_02234BBC
ov40_02234BBC: ; 0x02234BBC
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	mov r1, #0x86
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r5, [r4, r1]
	ldr r1, [r4, #8]
	cmp r1, #4
	bls _02234BD0
	b _02234D5A
_02234BD0:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02234BDC: ; jump table
	.short _02234BE6 - _02234BDC - 2 ; case 0
	.short _02234BFE - _02234BDC - 2 ; case 1
	.short _02234CA0 - _02234BDC - 2 ; case 2
	.short _02234CEC - _02234BDC - 2 ; case 3
	.short _02234D20 - _02234BDC - 2 ; case 4
_02234BE6:
	mov r1, #1
	bl ov40_022359B4
	add r0, r4, #0
	mov r1, #0x3a
	mov r2, #7
	bl ov40_022307DC
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02234D7C
_02234BFE:
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #0
	mov r3, #2
	bl ov40_0222DA00
	cmp r0, #0
	bne _02234C10
	b _02234D7C
_02234C10:
	add r0, r4, #0
	mov r1, #0x72
	bl ov40_0222DED0
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	ldr r0, _02234D84 ; =0x0000047C
	add r1, r4, #0
	add r0, r4, r0
	bl ov40_0222F9D4
	mov r0, #0x7b
	lsl r0, r0, #2
	ldr r3, _02234D88 ; =ov40_022451F4
	add r2, r5, r0
	mov r6, #5
_02234C34:
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	sub r6, r6, #1
	bne _02234C34
	ldr r0, [r3]
	mov r1, #0x7a
	lsl r1, r1, #2
	str r0, [r2]
	ldr r2, [r5, r1]
	add r0, r1, #4
	str r2, [r5, r0]
	add r0, r1, #0
	sub r0, #0x14
	ldr r0, [r5, r0]
	add r1, #8
	str r0, [r5, r1]
	ldr r0, _02234D8C ; =0x0000049C
	add r0, r4, r0
	bl ov40_0222F734
	mov r3, #0x1e
	ldr r0, _02234D8C ; =0x0000049C
	lsl r3, r3, #4
	ldr r2, [r5, r3]
	add r3, #0xc
	add r0, r4, r0
	add r1, r4, #0
	add r3, r5, r3
	bl ov40_0222E9B8
	ldr r1, _02234D84 ; =0x0000047C
	add r0, r4, r1
	add r1, #0x20
	add r1, r4, r1
	bl ov40_0222FA5C
	ldr r0, _02234D8C ; =0x0000049C
	add r1, r4, #0
	add r0, r4, r0
	mov r2, #2
	bl ov40_0222F740
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	mov r0, #0x2e
	mov r1, #0
	lsl r0, r0, #4
	str r1, [r5, r0]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02234D7C
_02234CA0:
	ldr r0, _02234D84 ; =0x0000047C
	add r0, r4, r0
	bl ov40_0222FA88
	ldr r1, _02234D8C ; =0x0000049C
	add r0, r4, r1
	sub r1, #0x10
	ldrsh r1, [r4, r1]
	bl ov40_0222F6D0
	ldr r0, _02234D8C ; =0x0000049C
	add r1, r4, #0
	add r0, r4, r0
	bl ov40_0222F38C
	cmp r0, #0
	beq _02234CD4
	mov r1, #0x2e
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r4, #0
	bl ov40_02230944
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_02234CD4:
	ldr r0, _02234D90 ; =ov40_022451C4
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _02234D7C
	add r0, r4, #0
	bl ov40_02230944
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02234D7C
_02234CEC:
	bl ov40_0222DFB0
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	ldr r0, _02234D84 ; =0x0000047C
	add r0, r4, r0
	bl ov40_0222FA24
	ldr r0, _02234D8C ; =0x0000049C
	add r0, r4, r0
	bl ov40_0222F720
	ldr r0, _02234D8C ; =0x0000049C
	add r1, r4, #0
	add r0, r4, r0
	bl ov40_0222F920
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_02234D20:
	add r0, r5, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #1
	mov r3, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _02234D40
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_02234D40:
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02234D7C
_02234D5A:
	add r0, r4, #0
	bl ov40_02235FA0
	mov r0, #0x2e
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02234D74
	add r0, r4, #0
	mov r1, #6
	bl ov40_0222BF80
	b _02234D7C
_02234D74:
	add r0, r4, #0
	mov r1, #3
	bl ov40_0222BF80
_02234D7C:
	mov r0, #0
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_02234D84: .word 0x0000047C
_02234D88: .word ov40_022451F4
_02234D8C: .word 0x0000049C
_02234D90: .word ov40_022451C4
	thumb_func_end ov40_02234BBC

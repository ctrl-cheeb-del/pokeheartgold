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


	thumb_func_start ov40_02234D94
ov40_02234D94: ; 0x02234D94
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _02234DAE
	cmp r1, #1
	beq _02234E1A
	cmp r1, #2
	beq _02234E7A
	b _02234EC8
_02234DAE:
	mov r0, #0
	mov r1, #1
	bl SetBgPriority
	mov r0, #1
	mov r1, #3
	bl SetBgPriority
	mov r0, #2
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #3
	mov r1, #1
	bl SetBgPriority
	mov r0, #4
	mov r1, #1
	bl SetBgPriority
	mov r0, #5
	mov r1, #3
	bl SetBgPriority
	mov r0, #6
	mov r1, #2
	bl SetBgPriority
	mov r0, #7
	mov r1, #1
	bl SetBgPriority
	mov r0, #0x8e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Heap_Free
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl sub_020314BC
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02234F8A
_02234E1A:
	add r0, r4, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	add r0, r4, #0
	add r1, r4, #4
	mov r2, #1
	mov r3, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _02234E60
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_02235B10
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_02234E60:
	ldr r0, [r5, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02234F8A
_02234E7A:
	add r4, #8
	add r0, r4, #0
	bl ov40_0222DAA8
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0222D88C
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	add r0, r5, #0
	mov r1, #1
	bl ov40_0222FB90
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02234F8A
_02234EC8:
	bl ov40_0222FBB4
	cmp r0, #0
	beq _02234F8A
	add r0, r4, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	cmp r0, #0
	beq _02234F5A
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02234F06
	bl ov41_0224B57C
	add r0, r5, #0
	bl ov40_0222BC54
	mov r0, #2
	mov r1, #0
	bl SetBgPriority
	bl ov40_02235994
_02234F06:
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0222DD08
	add r0, r4, #0
	add r0, #8
	bl ov40_0222DAA8
	ldr r0, [r5, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r5, #0x28]
	mov r2, #0xc
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	mov r1, #1
	ldr r3, [r5, #0x10]
	add r0, r5, #0
	add r2, r1, #0
	bl ov40_0222BF64
	add r0, r5, #0
	mov r1, #5
	bl ov40_0222BF80
	add r0, r4, #0
	bl Heap_Free
	ldr r0, _02234F90 ; =FS_OVERLAY_ID(OVY_41)
	bl UnloadOverlayByID
	ldr r0, _02234F94 ; =ov40_0222BD04
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	b _02234F8A
_02234F5A:
	ldr r0, [r5, #0x58]
	mov r1, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r5, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
_02234F8A:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02234F90: .word FS_OVERLAY_ID(OVY_41)
_02234F94: .word ov40_0222BD04
	thumb_func_end ov40_02234D94


	thumb_func_start ov40_02234F98
ov40_02234F98: ; 0x02234F98
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r5, [r4, r1]
	bl ov40_0223D5CC
	cmp r0, #0
	bne _02234FAE
	mov r0, #0
	pop {r3, r4, r5, pc}
_02234FAE:
	ldr r0, [r4, #8]
	cmp r0, #4
	bls _02234FB6
	b _022350F4
_02234FB6:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234FC2: ; jump table
	.short _02234FCC - _02234FC2 - 2 ; case 0
	.short _0223500C - _02234FC2 - 2 ; case 1
	.short _02235028 - _02234FC2 - 2 ; case 2
	.short _02235086 - _02234FC2 - 2 ; case 3
	.short _022350C0 - _02234FC2 - 2 ; case 4
_02234FCC:
	mov r1, #0x6f
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	add r0, r4, #0
	mov r2, #0x80
	mov r3, #0x60
	bl ov40_0223077C
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl sub_020879E0
	mov r0, #0x6f
	lsl r0, r0, #4
	mov r1, #0x18
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl sub_02087A08
	ldr r1, _0223511C ; =0x0000011F
	add r0, r4, #0
	bl ov40_0222DED0
	ldr r0, _02235120 ; =0x0000057D
	bl PlaySE
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02235118
_0223500C:
	add r0, r4, #0
	bl ov40_0223D540
	mov r1, #0x2e
	lsl r1, r1, #4
	ldr r1, [r5, r1]
	bl ov39_022273F8
	cmp r0, #1
	bne _02235118
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02235118
_02235028:
	add r0, r4, #0
	bl ov40_0222DFB0
	add r0, r4, #0
	bl ov40_0223D540
	add r1, sp, #0
	bl ov39_02227D44
	cmp r0, #1
	ldr r0, _02235120 ; =0x0000057D
	bne _02235072
	mov r1, #0
	bl StopSE
	ldr r3, [sp]
	add r0, r4, #0
	ldr r2, [r3, #0xc]
	ldr r3, [r3, #4]
	mov r1, #1
	bl ov40_02230CDC
	mov r0, #0xb9
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r5, r0]
	mov r0, #0x6f
	str r1, [r4, #0xc]
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl sub_020879E0
	add r0, r4, #0
	mov r1, #3
	bl ov40_0222BF80
	b _02235118
_02235072:
	mov r1, #0
	bl StopSE
	ldr r0, _02235124 ; =0x00000577
	bl PlaySE
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02235118
_02235086:
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl sub_020879E0
	mov r0, #0x6f
	lsl r0, r0, #4
	mov r1, #0
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl sub_02087A08
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02235118
_022350C0:
	mov r1, #0xb9
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	cmp r0, #0
	beq _022350E0
	add r0, r1, #0
	mov r2, #0
	sub r0, #0xb0
	str r2, [r5, r0]
	sub r1, #0xb4
	str r2, [r5, r1]
	add r0, r4, #0
	mov r1, #7
	bl ov40_0222BF80
	b _02235118
_022350E0:
	ldr r1, _02235128 ; =0x00000125
	add r0, r4, #0
	bl ov40_0222DED0
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	mov r0, #0
	str r0, [r4, #0xc]
	b _02235118
_022350F4:
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	cmp r0, #0x3c
	bge _02235106
	bl System_GetTouchNew
	cmp r0, #1
	bne _02235118
_02235106:
	mov r0, #0
	str r0, [r4, #0xc]
	add r0, r4, #0
	bl ov40_0222DFB0
	add r0, r4, #0
	mov r1, #3
	bl ov40_0222BF80
_02235118:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0223511C: .word 0x0000011F
_02235120: .word 0x0000057D
_02235124: .word 0x00000577
_02235128: .word 0x00000125
	thumb_func_end ov40_02234F98


	thumb_func_start ov40_0223512C
ov40_0223512C: ; 0x0223512C
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _02235146
	cmp r1, #1
	beq _022351D0
	cmp r1, #2
	beq _022351E6
	b _0223524E
_02235146:
	mov r1, #0x8d
	mov r0, #0
	lsl r1, r1, #2
	str r0, [r4, #0xc]
	ldr r0, [r4, r1]
	lsl r0, r0, #2
	add r2, r4, r0
	add r0, r1, #0
	add r0, #8
	ldr r0, [r2, r0]
	add r1, r1, #4
	ldr r1, [r4, r1]
	add r0, #0x80
	bl ov39_02227080
	mov r1, #0x86
	lsl r1, r1, #2
	add r0, r4, r1
	add r1, #0x20
	ldr r1, [r4, r1]
	bl ov41_0224B530
	mov r1, #0x8a
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0
	bl ov41_0224B5D0
	bl ov40_02235940
	add r0, r5, #0
	mov r1, #0x23
	mov r2, #3
	bl ov40_022307DC
	add r0, r5, #0
	mov r1, #0x24
	mov r2, #7
	bl ov40_022307DC
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, _02235278 ; =ov40_02235900
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02235254
_022351D0:
	mov r1, #0
	mov r3, #2
	ldr r0, [r5, #0x28]
	add r2, r1, #0
	lsl r3, r3, #8
	bl PaletteData_LoadPaletteSlotFromHardware
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02235254
_022351E6:
	add r0, r4, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	mov r2, #0
	add r0, r4, #0
	add r1, r4, #4
	add r3, r2, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _02235234
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov41_0224B5D0
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r5, #0
	bl ov40_02235C7C
	add r0, r5, #0
	bl ov40_022358C0
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_02235234:
	ldr r0, [r5, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02235254
_0223524E:
	mov r1, #8
	bl ov40_0222BF80
_02235254:
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02235274
	bl Thunk_G3X_Reset
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov41_0224B554
	mov r0, #0
	add r1, r0, #0
	bl RequestSwap3DBuffers
_02235274:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02235278: .word ov40_02235900
	thumb_func_end ov40_0223512C


	thumb_func_start ov40_0223527C
ov40_0223527C: ; 0x0223527C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r4, [r5, r0]
	ldr r0, _0223533C ; =ov40_022451C4
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _0223529E
	add r0, r5, #0
	bl ov40_02230944
	add r0, r5, #0
	mov r1, #9
	bl ov40_0222BF80
_0223529E:
	ldr r0, _02235340 ; =ov40_022451D0
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _022352B6
	add r0, r5, #0
	bl ov40_02230944
	add r0, r5, #0
	mov r1, #0xa
	bl ov40_0222BF80
_022352B6:
	ldr r0, _02235344 ; =ov40_022451D4
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _022352E4
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	cmp r0, #0
	beq _022352CC
	b _022352D2
_022352CC:
	add r0, r1, #0
	add r0, #0xb0
	ldr r0, [r4, r0]
_022352D2:
	sub r0, r0, #1
	str r0, [r4, r1]
	add r0, r5, #0
	bl ov40_02230944
	add r0, r5, #0
	mov r1, #0xb
	bl ov40_0222BF80
_022352E4:
	ldr r0, _02235348 ; =ov40_022451D8
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _02235316
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r0, r0, #1
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	add r1, #0xb0
	ldr r1, [r4, r1]
	bl _s32_div_f
	mov r0, #0x8d
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r5, #0
	bl ov40_02230944
	add r0, r5, #0
	mov r1, #0xb
	bl ov40_0222BF80
_02235316:
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02235336
	bl Thunk_G3X_Reset
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov41_0224B554
	mov r0, #0
	add r1, r0, #0
	bl RequestSwap3DBuffers
_02235336:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0223533C: .word ov40_022451C4
_02235340: .word ov40_022451D0
_02235344: .word ov40_022451D4
_02235348: .word ov40_022451D8
	thumb_func_end ov40_0223527C


	thumb_func_start ov40_0223534C
ov40_0223534C: ; 0x0223534C
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _02235362
	cmp r1, #1
	beq _022353A8
	b _0223542A
_02235362:
	ldr r1, [r4, #0xc]
	cmp r1, #0
	bne _02235380
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	add r0, r5, #0
	bl ov40_02236130
	b _0223539A
_02235380:
	mov r1, #1
	bl ov40_02230964
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0222E7B8
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
_0223539A:
	add r0, r5, #0
	bl ov40_0223584C
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02235430
_022353A8:
	add r0, r4, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	add r0, r4, #0
	add r1, r4, #4
	mov r2, #1
	mov r3, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _02235410
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _022353EA
	bl ov41_0224B57C
	add r0, r5, #0
	bl ov40_0222BC54
	mov r0, #2
	mov r1, #0
	bl SetBgPriority
	mov r0, #0x8a
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	bl ov40_02235994
_022353EA:
	ldr r0, [r5, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_02235410:
	ldr r0, [r5, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02235430
_0223542A:
	mov r1, #3
	bl ov40_0222BF80
_02235430:
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov40_0223534C


	thumb_func_start ov40_02235434
ov40_02235434: ; 0x02235434
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #4
	bls _02235446
	b _02235626
_02235446:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02235452: ; jump table
	.short _0223545C - _02235452 - 2 ; case 0
	.short _02235492 - _02235452 - 2 ; case 1
	.short _022354F2 - _02235452 - 2 ; case 2
	.short _022355AE - _02235452 - 2 ; case 3
	.short _022355CA - _02235452 - 2 ; case 4
_0223545C:
	ldr r1, [r4, #0xc]
	cmp r1, #0
	bne _02235470
	bl ov40_02236130
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	b _0223548A
_02235470:
	mov r1, #1
	bl ov40_02230964
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0222E7B8
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
_0223548A:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223563E
_02235492:
	mov r2, #1
	add r0, r4, #0
	add r1, r4, #4
	add r3, r2, #0
	bl ov40_0222DA00
	cmp r0, #0
	bne _022354A4
	b _0223563E
_022354A4:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne _022354EA
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _022354D2
	bl ov41_0224B57C
	add r0, r5, #0
	bl ov40_0222BC54
	mov r0, #2
	mov r1, #0
	bl SetBgPriority
	mov r0, #0x8a
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	bl ov40_02235994
_022354D2:
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
_022354EA:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223563E
_022354F2:
	ldr r1, [r4, #0xc]
	cmp r1, #0
	bne _02235542
	mov r1, #1
	bl ov40_02230964
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	lsl r0, r0, #2
	add r2, r4, r0
	add r0, r1, #0
	add r0, #8
	add r1, #0x1c
	ldr r0, [r2, r0]
	ldr r1, [r4, r1]
	bl ov39_022271C0
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0222E79C
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #0
	bl ov40_0222E7DC
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r5, #0
	mov r1, #0x50
	mov r2, #3
	bl ov40_022307DC
	b _022355A6
_02235542:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	lsl r0, r0, #2
	add r2, r4, r0
	add r0, r1, #0
	add r0, #8
	ldr r0, [r2, r0]
	add r1, r1, #4
	ldr r1, [r4, r1]
	add r0, #0x80
	bl ov39_02227080
	mov r1, #0x86
	lsl r1, r1, #2
	add r0, r4, r1
	add r1, #0x20
	ldr r1, [r4, r1]
	bl ov41_0224B530
	mov r1, #0x8a
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0
	bl ov41_0224B5D0
	bl ov40_02235940
	add r0, r5, #0
	mov r1, #0x23
	mov r2, #3
	bl ov40_022307DC
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
_022355A6:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223563E
_022355AE:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _022355C2
	mov r1, #0
	mov r3, #2
	ldr r0, [r5, #0x28]
	add r2, r1, #0
	lsl r3, r3, #8
	bl PaletteData_LoadPaletteSlotFromHardware
_022355C2:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223563E
_022355CA:
	add r0, r4, #0
	add r1, r4, #4
	mov r2, #0
	mov r3, #1
	bl ov40_0222DA00
	cmp r0, #0
	beq _0223563E
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne _022355F6
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #1
	bl ov40_0222E7DC
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	b _0223561E
_022355F6:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r5, #0
	bl ov40_02235C7C
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov41_0224B5D0
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
_0223561E:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223563E
_02235626:
	ldr r1, [r4, #0xc]
	mov r0, #1
	eor r1, r0
	str r1, [r4, #0xc]
	add r0, r5, #0
	add r1, #0x79
	bl ov40_02235868
	add r0, r5, #0
	mov r1, #8
	bl ov40_0222BF80
_0223563E:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov40_02235434


	thumb_func_start ov40_02235644
ov40_02235644: ; 0x02235644
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #4
	bls _02235656
	b _0223583E
_02235656:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02235662: ; jump table
	.short _0223566C - _02235662 - 2 ; case 0
	.short _022356A2 - _02235662 - 2 ; case 1
	.short _02235702 - _02235662 - 2 ; case 2
	.short _022357C6 - _02235662 - 2 ; case 3
	.short _022357E2 - _02235662 - 2 ; case 4
_0223566C:
	ldr r1, [r4, #0xc]
	cmp r1, #0
	bne _02235680
	bl ov40_02236130
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	b _0223569A
_02235680:
	mov r1, #1
	bl ov40_02230964
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0222E7B8
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
_0223569A:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02235846
_022356A2:
	mov r2, #1
	add r0, r4, #0
	add r1, r4, #4
	add r3, r2, #0
	bl ov40_0222DA00
	cmp r0, #0
	bne _022356B4
	b _02235846
_022356B4:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne _022356FA
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _022356E2
	bl ov41_0224B57C
	add r0, r5, #0
	bl ov40_0222BC54
	mov r0, #2
	mov r1, #0
	bl SetBgPriority
	mov r0, #0x8a
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	bl ov40_02235994
_022356E2:
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
_022356FA:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02235846
_02235702:
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne _02235774
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	lsl r0, r0, #2
	add r2, r4, r0
	add r0, r1, #0
	add r0, #8
	ldr r0, [r2, r0]
	add r1, r1, #4
	ldr r1, [r4, r1]
	add r0, #0x80
	bl ov39_02227080
	mov r1, #0x86
	lsl r1, r1, #2
	add r0, r4, r1
	add r1, #0x20
	ldr r1, [r4, r1]
	bl ov41_0224B530
	mov r1, #0x8a
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0
	bl ov41_0224B5D0
	bl ov40_02235940
	add r0, r5, #0
	mov r1, #0x23
	mov r2, #3
	bl ov40_022307DC
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	b _022357B6
_02235774:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	lsl r0, r0, #2
	add r2, r4, r0
	add r0, r1, #0
	add r0, #8
	add r1, #0x1c
	ldr r0, [r2, r0]
	ldr r1, [r4, r1]
	bl ov39_022271C0
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0222E79C
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #0
	bl ov40_0222E7DC
	add r0, r5, #0
	mov r1, #0x50
	mov r2, #3
	bl ov40_022307DC
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
_022357B6:
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02235846
_022357C6:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne _022357DA
	mov r1, #0
	mov r3, #2
	ldr r0, [r5, #0x28]
	add r2, r1, #0
	lsl r3, r3, #8
	bl PaletteData_LoadPaletteSlotFromHardware
_022357DA:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02235846
_022357E2:
	add r0, r4, #0
	add r1, r4, #4
	mov r2, #0
	mov r3, #1
	bl ov40_0222DA00
	cmp r0, #0
	beq _02235846
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne _02235822
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r5, #0
	bl ov40_02235C7C
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov41_0224B5D0
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	b _02235836
_02235822:
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #1
	bl ov40_0222E7DC
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
_02235836:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02235846
_0223583E:
	add r0, r5, #0
	mov r1, #8
	bl ov40_0222BF80
_02235846:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov40_02235644

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

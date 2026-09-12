	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public AddTextPrinterParameterizedWithColor
	.public AddWindowParameterized
	.public BgClearTilemapBufferAndCommit
	.public ClearWindowTilemapAndCopyToVram
	.public FillWindowPixelBuffer
	.public FontID_String_GetWidthMultiline
	.public GF_AssertFail
	.public GfGfxLoader_LoadCharDataFromOpenNarc
	.public GfGfx_EngineATogglePlanes
	.public GfGfx_EngineBTogglePlanes
	.public Heap_Alloc
	.public Heap_Free
	.public InitWindow
	.public ManagedSprite_SetAnim
	.public ManagedSprite_SetDrawFlag
	.public ManagedSprite_SetPositionXY
	.public NewString_ReadMsgData
	.public PaletteData_BlendPalettes
	.public PlaySE
	.public RemoveWindow
	.public ScheduleWindowCopyToVram
	.public SetBgPriority
	.public StopSE
	.public String_Delete
	.public TextOBJ_SetSpritesDrawFlag
	.public TouchHitboxController_Create
	.public TouchscreenHitbox_TouchNewIsIn
	.public memset
	.public ov39_022275E8
	.public ov39_02227648
	.public ov39_022276A4
	.public ov39_022276E0
	.public ov39_02227D44
	.public ov40_0222BF64
	.public ov40_0222BF80
	.public ov40_0222C4DC
	.public ov40_0222D66C
	.public ov40_0222D874
	.public ov40_0222D88C
	.public ov40_0222D9E8
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222DAA8
	.public ov40_0222DD08
	.public ov40_0222DED0
	.public ov40_0222DFB0
	.public ov40_0222E9B8
	.public ov40_0222F488
	.public ov40_0222F5EC
	.public ov40_0222F720
	.public ov40_0222F734
	.public ov40_0222F740
	.public ov40_0222F858
	.public ov40_0222F920
	.public ov40_0222F9D4
	.public ov40_0222FA18
	.public ov40_0222FA24
	.public ov40_0222FA5C
	.public ov40_0222FA88
	.public ov40_0222FB90
	.public ov40_0222FBB4
	.public ov40_0222FE00
	.public ov40_0222FE68
	.public ov40_0222FE8C
	.public ov40_0222FE98
	.public ov40_02230410
	.public ov40_02230638
	.public ov40_022306A0
	.public ov40_0223077C
	.public ov40_022307DC
	.public ov40_02230944
	.public ov40_02230964
	.public ov40_02230CDC
	.public ov40_0223A430
	.public ov40_0223B480
	.public ov40_0223B4BC
	.public ov40_0223B538
	.public ov40_0223B574
	.public ov40_0223B5B0
	.public ov40_0223B62C
	.public ov40_0223B75C
	.public ov40_0223BA70
	.public ov40_0223BB74
	.public ov40_0223BD98
	.public ov40_0223BF88
	.public ov40_0223C0D8
	.public ov40_0223CD14
	.public ov40_0223CE64
	.public ov40_0223CF00
	.public ov40_0223CF70
	.public ov40_0223CFA8
	.public ov40_0223D008
	.public ov40_0223D1AC
	.public ov40_0223D1F0
	.public ov40_0223D244
	.public ov40_0223D540
	.public ov40_0223D5CC
	.public ov40_02245494
	.public ov40_02245498
	.public ov40_0224549C
	.public ov40_022454A4
	.public ov40_022454B0
	.public ov40_022454E0
	.public ov40_022454F0
	.public sub_020136B4
	.public sub_0202FC24
	.public sub_0202FC48
	.public sub_0203A948
	.public sub_020878EC
	.public sub_020879E0
	.public sub_02087A08
	.public sub_02087E1C
	.text

	thumb_func_start ov40_0223B4BC
ov40_0223B4BC: ; 0x0223B4BC
	push {r4, lr}
	mov r2, #0x86
	lsl r2, r2, #4
	ldr r4, [r0, r2]
	cmp r1, #0
	bne _0223B4F0
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x4e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x20
	mov r2, #0xe8
	bl ManagedSprite_SetPositionXY
	b _0223B516
_0223B4F0:
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x4e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl TextOBJ_SetSpritesDrawFlag
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x50
	mov r2, #0xe8
	bl ManagedSprite_SetPositionXY
_0223B516:
	mov r0, #0x47
	lsl r0, r0, #2
	mov r1, #0x24
	add r2, r1, #0
	ldr r0, [r4, r0]
	sub r2, #0x2c
	bl sub_020136B4
	mov r0, #0x4e
	lsl r0, r0, #2
	mov r1, #0x24
	add r2, r1, #0
	ldr r0, [r4, r0]
	sub r2, #0x2c
	bl sub_020136B4
	pop {r4, pc}
	thumb_func_end ov40_0223B4BC


	thumb_func_start ov40_0223B538
ov40_0223B538: ; 0x0223B538
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0x86
	lsl r1, r1, #4
	ldr r6, [r0, r1]
	ldr r0, _0223B570 ; =0x00002030
	mov r4, #0
	ldr r0, [r6, r0]
	cmp r0, #0
	ble _0223B566
	add r5, r6, #0
	ldr r7, _0223B570 ; =0x00002030
	add r5, #0x14
_0223B550:
	add r0, r5, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	bl RemoveWindow
	ldr r0, [r6, r7]
	add r4, r4, #1
	add r5, #0x10
	cmp r4, r0
	blt _0223B550
_0223B566:
	ldr r0, _0223B570 ; =0x00002030
	mov r1, #0
	str r1, [r6, r0]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223B570: .word 0x00002030
	thumb_func_end ov40_0223B538


	thumb_func_start ov40_0223B574
ov40_0223B574: ; 0x0223B574
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0x86
	lsl r1, r1, #4
	ldr r6, [r0, r1]
	ldr r0, _0223B5AC ; =0x0000202C
	mov r4, #0
	ldr r0, [r6, r0]
	cmp r0, #0
	ble _0223B5A2
	add r5, r6, #0
	ldr r7, _0223B5AC ; =0x0000202C
	add r5, #0x94
_0223B58C:
	add r0, r5, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	bl RemoveWindow
	ldr r0, [r6, r7]
	add r4, r4, #1
	add r5, #0x10
	cmp r4, r0
	blt _0223B58C
_0223B5A2:
	ldr r0, _0223B5AC ; =0x0000202C
	mov r1, #0
	str r1, [r6, r0]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223B5AC: .word 0x0000202C
	thumb_func_end ov40_0223B574


	thumb_func_start ov40_0223B5B0
ov40_0223B5B0: ; 0x0223B5B0
	push {r3, r4, r5, lr}
	ldr r1, _0223B628 ; =0x0000217C
	add r5, r0, #0
	mov r0, #0x6d
	bl Heap_Alloc
	ldr r2, _0223B628 ; =0x0000217C
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x86
	lsl r0, r0, #4
	str r4, [r5, r0]
	add r0, #0xc
	ldr r1, [r5, r0]
	mov r0, #0x4b
	lsl r0, r0, #2
	cmp r1, r0
	bne _0223B5DE
	mov r0, #0
	str r0, [r4, #0xc]
	b _0223B5F2
_0223B5DE:
	add r0, r0, #1
	cmp r1, r0
	bne _0223B5EA
	mov r0, #1
	str r0, [r4, #0xc]
	b _0223B5F2
_0223B5EA:
	cmp r1, #0xc8
	bne _0223B5F2
	mov r0, #2
	str r0, [r4, #0xc]
_0223B5F2:
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	add r1, r4, #4
	mov r2, #0
	bl ov40_0222D9E8
	add r0, r5, #0
	mov r1, #1
	bl ov40_0222BF80
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0223B628: .word 0x0000217C
	thumb_func_end ov40_0223B5B0


	thumb_func_start ov40_0223B62C
ov40_0223B62C: ; 0x0223B62C
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _0223B646
	cmp r1, #1
	beq _0223B6A4
	cmp r1, #2
	beq _0223B700
	b _0223B73C
_0223B646:
	add r0, r4, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	cmp r0, #0
	beq _0223B65A
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_0223B65A:
	ldr r0, [r5, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
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
	b _0223B756
_0223B6A4:
	mov r0, #0
	mov r1, #1
	bl SetBgPriority
	mov r0, #1
	mov r1, #3
	bl SetBgPriority
	mov r0, #2
	mov r1, #0
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
	mov r1, #0
	bl SetBgPriority
	mov r0, #7
	mov r1, #2
	bl SetBgPriority
	add r0, r5, #0
	mov r1, #0
	bl ov40_0222FB90
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl sub_020879E0
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223B756
_0223B700:
	bl ov40_0222FBB4
	cmp r0, #0
	beq _0223B756
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0222D874
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0223A430
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223B756
_0223B73C:
	bl ov40_0222C4DC
	cmp r0, #1
	bne _0223B74E
	add r0, r5, #0
	mov r1, #0x13
	bl ov40_0222BF80
	b _0223B756
_0223B74E:
	add r0, r5, #0
	mov r1, #2
	bl ov40_0222BF80
_0223B756:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov40_0223B62C


	thumb_func_start ov40_0223B75C
ov40_0223B75C: ; 0x0223B75C
	push {r3, r4, r5, lr}
	sub sp, #8
	mov r1, #0x86
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r5, [r4, r1]
	bl ov40_0223D5CC
	cmp r0, #0
	bne _0223B776
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223B776:
	ldr r0, [r4, #8]
	cmp r0, #6
	bls _0223B77E
	b _0223BA36
_0223B77E:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223B78A: ; jump table
	.short _0223B798 - _0223B78A - 2 ; case 0
	.short _0223B7F0 - _0223B78A - 2 ; case 1
	.short _0223B87C - _0223B78A - 2 ; case 2
	.short _0223B8FE - _0223B78A - 2 ; case 3
	.short _0223B920 - _0223B78A - 2 ; case 4
	.short _0223B95A - _0223B78A - 2 ; case 5
	.short _0223B98E - _0223B78A - 2 ; case 6
_0223B798:
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
	ldr r0, _0223BA60 ; =0x0000086C
	mov r1, #0x4b
	ldr r0, [r4, r0]
	lsl r1, r1, #2
	sub r0, r0, r1
	cmp r0, #1
	bhi _0223B7DA
	add r0, r4, #0
	sub r1, #0x15
	bl ov40_0222DED0
	b _0223B7E2
_0223B7DA:
	add r0, r4, #0
	sub r1, #8
	bl ov40_0222DED0
_0223B7E2:
	ldr r0, _0223BA64 ; =0x0000057D
	bl PlaySE
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223BA58
_0223B7F0:
	ldr r0, _0223BA60 ; =0x0000086C
	ldr r1, [r4, r0]
	mov r0, #0x4b
	lsl r0, r0, #2
	cmp r1, r0
	bne _0223B816
	mov r0, #0
	str r0, [r5, #0xc]
	add r0, r4, #0
	bl ov40_0223D540
	bl ov39_022276A4
	cmp r0, #1
	bne _0223B86C
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223BA58
_0223B816:
	add r0, r0, #1
	cmp r1, r0
	bne _0223B836
	mov r0, #1
	str r0, [r5, #0xc]
	add r0, r4, #0
	bl ov40_0223D540
	bl ov39_022276E0
	cmp r0, #1
	bne _0223B86C
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223BA58
_0223B836:
	cmp r1, #0xc8
	bne _0223B876
	mov r0, #2
	str r0, [r5, #0xc]
	add r0, r4, #0
	bl sub_02087E1C
	cmp r0, #1
	bne _0223B85E
	add r0, r4, #0
	bl ov40_0223D540
	bl ov39_02227648
	cmp r0, #1
	bne _0223B86C
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223BA58
_0223B85E:
	add r0, r4, #0
	bl ov40_0223D540
	bl ov39_022275E8
	cmp r0, #1
	beq _0223B86E
_0223B86C:
	b _0223BA58
_0223B86E:
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223BA58
_0223B876:
	bl GF_AssertFail
	b _0223BA58
_0223B87C:
	add r0, r4, #0
	bl ov40_0222DFB0
	add r0, r4, #0
	bl ov40_0223D540
	add r1, sp, #4
	bl ov39_02227D44
	cmp r0, #1
	ldr r0, _0223BA64 ; =0x0000057D
	bne _0223B8B0
	mov r1, #0
	bl StopSE
	ldr r3, [sp, #4]
	add r0, r4, #0
	ldr r2, [r3, #0xc]
	ldr r3, [r3, #4]
	mov r1, #7
	bl ov40_02230CDC
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223BA58
_0223B8B0:
	mov r1, #0
	bl StopSE
	ldr r0, _0223BA68 ; =0x00000577
	bl PlaySE
	ldr r0, _0223BA6C ; =0x00004138
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0223B8F8
	mov r2, #0
	add r0, r4, #0
	mov r1, #5
	add r3, r2, #0
	bl ov40_02230CDC
	ldr r0, [r5, #0xc]
	cmp r0, #2
	bne _0223B8DA
	mov r1, #0x76
	b _0223B8DE
_0223B8DA:
	mov r1, #0x4b
	lsl r1, r1, #2
_0223B8DE:
	mov r0, #0x51
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl sub_020879E0
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223BA58
_0223B8F8:
	mov r0, #0xff
	str r0, [r4, #8]
	b _0223BA58
_0223B8FE:
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
	b _0223BA58
_0223B920:
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
	beq _0223B940
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223B940:
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
	b _0223BA58
_0223B95A:
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0223B480
	add r0, r4, #0
	bl ov40_0222D88C
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	mov r0, #1
	mov r1, #0x6d
	bl sub_0203A948
	add r0, r4, #0
	mov r1, #1
	bl ov40_0222FB90
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223BA58
_0223B98E:
	add r0, r4, #0
	bl ov40_0222FBB4
	cmp r0, #0
	beq _0223BA58
	add r0, r5, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	cmp r0, #0
	beq _0223BA04
	add r0, r4, #0
	bl ov40_0222DD08
	add r0, r5, #0
	add r0, #8
	bl ov40_0222DAA8
	ldr r0, [r4, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r4, #0x28]
	mov r2, #0xc
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	mov r1, #1
	ldr r3, [r4, #0x10]
	add r0, r4, #0
	add r2, r1, #0
	bl ov40_0222BF64
	add r0, r4, #0
	mov r1, #5
	bl ov40_0222BF80
	ldr r0, [r4, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	add r0, r5, #0
	bl Heap_Free
	b _0223BA58
_0223BA04:
	ldr r0, [r4, #0x58]
	mov r1, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
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
	b _0223BA58
_0223BA36:
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
	add r0, r4, #0
	mov r1, #3
	bl ov40_0222BF80
_0223BA58:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_0223BA60: .word 0x0000086C
_0223BA64: .word 0x0000057D
_0223BA68: .word 0x00000577
_0223BA6C: .word 0x00004138
	thumb_func_end ov40_0223B75C


	thumb_func_start ov40_0223BA70
ov40_0223BA70: ; 0x0223BA70
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r4, [r5, r0]
	ldr r3, _0223BB68 ; =ov40_022454A4
	add r6, r4, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x14
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r6, #0x14
	str r0, [r2]
	add r0, r6, #0
	bl InitWindow
	mov r3, #3
	str r3, [sp]
	mov r0, #0x14
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xe
	str r0, [sp, #0xc]
	mov r0, #0x20
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x24]
	add r1, r6, #0
	mov r2, #2
	bl AddWindowParameterized
	add r0, r6, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r1, [r4, #0xc]
	ldr r0, [r5, #0x48]
	lsl r2, r1, #2
	add r1, sp, #0x14
	ldr r1, [r1, r2]
	bl NewString_ReadMsgData
	mov r1, #0
	add r7, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0223BB6C ; =0x000F0D00
	add r2, r7, #0
	str r0, [sp, #8]
	add r0, r6, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl ScheduleWindowCopyToVram
	add r0, r7, #0
	bl String_Delete
	add r6, r4, #0
	add r6, #0x94
	add r0, r6, #0
	bl InitWindow
	mov r2, #6
	str r2, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xe
	str r0, [sp, #0xc]
	add r0, #0xf2
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x24]
	add r1, r6, #0
	mov r3, #0xb
	bl AddWindowParameterized
	add r0, r6, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r5, #0x48]
	mov r1, #0x5f
	bl NewString_ReadMsgData
	add r5, r0, #0
	mov r0, #0
	add r1, r5, #0
	add r2, r0, #0
	bl FontID_String_GetWidthMultiline
	mov r1, #0x50
	sub r0, r1, r0
	mov r1, #0
	lsr r3, r0, #1
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0223BB6C ; =0x000F0D00
	add r2, r5, #0
	str r0, [sp, #8]
	add r0, r6, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	bl String_Delete
	ldr r0, _0223BB70 ; =0x0000202C
	mov r1, #1
	str r1, [r4, r0]
	add r0, r0, #4
	str r1, [r4, r0]
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223BB68: .word ov40_022454A4
_0223BB6C: .word 0x000F0D00
_0223BB70: .word 0x0000202C
	thumb_func_end ov40_0223BA70


	thumb_func_start ov40_0223BB74
ov40_0223BB74: ; 0x0223BB74
	push {r4, r5, r6, lr}
	sub sp, #0x10
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _0223BB8E
	cmp r1, #1
	bne _0223BB8C
	b _0223BCCE
_0223BB8C:
	b _0223BD6E
_0223BB8E:
	bl sub_0202FC48
	cmp r0, #0
	beq _0223BB9A
	bl sub_0202FC24
_0223BB9A:
	ldr r0, _0223BD7C ; =0x00002054
	ldr r3, _0223BD80 ; =ov40_022454F0
	add r2, r4, r0
	mov r6, #5
_0223BBA2:
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	sub r6, r6, #1
	bne _0223BBA2
	ldr r0, [r3]
	mov r1, #0
	str r0, [r2]
	ldr r0, _0223BD7C ; =0x00002054
	str r1, [r4, r0]
	ldr r1, _0223BD84 ; =0x00004138
	add r0, r0, #4
	ldr r1, [r5, r1]
	str r1, [r4, r0]
	add r0, r5, #0
	bl ov40_0222FE00
	mov r0, #0x6d
	bl ov40_0222FE8C
	mov r1, #0x82
	lsl r1, r1, #6
	str r0, [r4, r1]
	mov r0, #0x7d
	lsl r0, r0, #2
	add r1, #8
	str r0, [r4, r1]
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x14]
	ldr r2, [r5, #0x24]
	mov r1, #0x3e
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x14]
	ldr r2, [r5, #0x24]
	mov r1, #0x3e
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	add r0, r5, #0
	mov r1, #4
	mov r2, #3
	bl ov40_022307DC
	mov r1, #7
	add r0, r5, #0
	add r2, r1, #0
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
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	add r0, r5, #0
	mov r1, #1
	bl ov40_0223B4BC
	add r0, r5, #0
	bl ov40_0223BA70
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	ldr r0, _0223BD88 ; =0x0000047C
	add r1, r5, #0
	add r0, r5, r0
	bl ov40_0222F9D4
	ldr r0, _0223BD8C ; =0x0000049C
	ldr r3, _0223BD7C ; =0x00002054
	add r0, r5, r0
	add r1, r5, #0
	mov r2, #0
	add r3, r4, r3
	bl ov40_0222E9B8
	ldr r1, _0223BD90 ; =0x000004E4
	mov r0, #1
	str r0, [r5, r1]
	add r0, r1, #0
	sub r0, #0x68
	sub r1, #0x48
	add r0, r5, r0
	add r1, r5, r1
	bl ov40_0222FA5C
	ldr r0, _0223BD8C ; =0x0000049C
	add r1, r5, #0
	add r0, r5, r0
	mov r2, #1
	bl ov40_0222F740
	ldr r0, _0223BD8C ; =0x0000049C
	mov r1, #0x40
	add r0, r5, r0
	mov r2, #0xb8
	bl ov40_0222F858
	ldr r0, _0223BD8C ; =0x0000049C
	add r1, r5, #0
	add r0, r5, r0
	bl ov40_0222F488
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0223D008
	add r0, r5, #0
	mov r1, #0
	bl ov40_0223D1AC
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223BD74
_0223BCCE:
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
	beq _0223BD3C
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add r0, r5, #0
	mov r1, #1
	bl ov40_0223D1AC
	ldr r3, _0223BD94 ; =0x000004D8
	mov r1, #0x6f
	ldr r6, [r5, r3]
	mov r3, #0x18
	mul r3, r6
	lsl r1, r1, #4
	add r3, #0x4c
	lsl r3, r3, #0x10
	ldr r1, [r5, r1]
	add r0, r5, #0
	mov r2, #0x10
	asr r3, r3, #0x10
	bl ov40_0223077C
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #1
	bl sub_020879E0
	mov r0, #0x6f
	lsl r0, r0, #4
	mov r1, #0xc
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl sub_02087A08
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_0223BD3C:
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
	ldr r0, [r5, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _0223BD74
_0223BD6E:
	mov r1, #4
	bl ov40_0222BF80
_0223BD74:
	mov r0, #0
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_0223BD7C: .word 0x00002054
_0223BD80: .word ov40_022454F0
_0223BD84: .word 0x00004138
_0223BD88: .word 0x0000047C
_0223BD8C: .word 0x0000049C
_0223BD90: .word 0x000004E4
_0223BD94: .word 0x000004D8
	thumb_func_end ov40_0223BB74


	thumb_func_start ov40_0223BD98
ov40_0223BD98: ; 0x0223BD98
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _0223BDB4
	cmp r1, #1
	beq _0223BE42
	cmp r1, #2
	bne _0223BDB2
	b _0223BEBC
_0223BDB2:
	b _0223BF56
_0223BDB4:
	ldr r0, _0223BF64 ; =0x0000047C
	add r0, r5, r0
	bl ov40_0222FA88
	ldr r1, _0223BF68 ; =0x0000049C
	add r0, r5, r1
	sub r1, #0x10
	ldrsh r1, [r5, r1]
	bl ov40_0222F5EC
	ldr r0, _0223BF68 ; =0x0000049C
	add r1, r5, #0
	add r0, r5, r0
	bl ov40_0222F488
	ldr r2, _0223BF6C ; =0x000004D8
	mov r0, #0x6f
	ldr r3, [r5, r2]
	mov r2, #0x18
	mul r2, r3
	lsl r0, r0, #4
	add r2, #0x4c
	lsl r2, r2, #0x10
	ldr r0, [r5, r0]
	mov r1, #0x10
	asr r2, r2, #0x10
	bl sub_020878EC
	add r0, r5, #0
	bl ov40_0223D244
	ldr r0, _0223BF70 ; =ov40_02245494
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _0223BE22
	add r0, r5, #0
	bl ov40_02230944
	ldr r0, _0223BF74 ; =0x000004D4
	ldr r0, [r5, r0]
	lsl r0, r0, #2
	add r1, r5, r0
	ldr r0, _0223BF78 ; =0x00002608
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _0223BE22
	ldr r0, _0223BF7C ; =0x00002034
	mov r1, #6
	str r1, [r4, r0]
	mov r0, #0
	str r0, [r4, #0x10]
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_0223BE22:
	ldr r0, _0223BF80 ; =ov40_02245498
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	bne _0223BE2E
	b _0223BF5E
_0223BE2E:
	add r0, r5, #0
	bl ov40_02230944
	ldr r0, _0223BF7C ; =0x00002034
	mov r1, #5
	str r1, [r4, r0]
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223BF5E
_0223BE42:
	ldr r0, _0223BF64 ; =0x0000047C
	add r0, r5, r0
	bl ov40_0222FA24
	ldr r0, _0223BF68 ; =0x0000049C
	add r0, r5, r0
	bl ov40_0222F720
	ldr r0, _0223BF68 ; =0x0000049C
	add r1, r5, #0
	add r0, r5, r0
	bl ov40_0222F920
	mov r0, #0x82
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl ov40_0222FE98
	add r0, r5, #0
	bl ov40_0223D1F0
	add r0, r5, #0
	bl ov40_0222FE68
	add r0, r5, #0
	bl ov40_0223B538
	add r0, r5, #0
	bl ov40_0223B574
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl sub_020879E0
	mov r0, #0x6f
	lsl r0, r0, #4
	mov r1, #0
	ldr r0, [r5, r0]
	add r2, r1, #0
	bl sub_02087A08
	ldr r0, _0223BF7C ; =0x00002034
	ldr r0, [r4, r0]
	cmp r0, #5
	bne _0223BEB6
	ldr r0, _0223BF64 ; =0x0000047C
	add r0, r5, r0
	bl ov40_0222FA18
	ldr r0, _0223BF68 ; =0x0000049C
	add r0, r5, r0
	bl ov40_0222F734
	ldr r0, _0223BF84 ; =0x00002084
	mov r1, #0
	str r1, [r4, r0]
_0223BEB6:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_0223BEBC:
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
	beq _0223BF24
	add r0, r5, #0
	mov r1, #0
	bl ov40_0223B4BC
	ldr r0, _0223BF7C ; =0x00002034
	ldr r0, [r4, r0]
	cmp r0, #6
	bne _0223BF1E
	mov r0, #0x45
	lsl r0, r0, #2
	add r1, r5, #0
	add r0, r4, r0
	add r1, #0x14
	mov r2, #3
	bl ov40_0222D66C
	mov r0, #0x13
	lsl r0, r0, #4
	add r1, r5, #0
	add r0, r4, r0
	add r1, #0x14
	mov r2, #0x5e
	bl ov40_0222D66C
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #3
	bl ManagedSprite_SetAnim
_0223BF1E:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_0223BF24:
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
	ldr r0, [r5, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _0223BF5E
_0223BF56:
	ldr r1, _0223BF7C ; =0x00002034
	ldr r1, [r4, r1]
	bl ov40_0222BF80
_0223BF5E:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0223BF64: .word 0x0000047C
_0223BF68: .word 0x0000049C
_0223BF6C: .word 0x000004D8
_0223BF70: .word ov40_02245494
_0223BF74: .word 0x000004D4
_0223BF78: .word 0x00002608
_0223BF7C: .word 0x00002034
_0223BF80: .word ov40_02245498
_0223BF84: .word 0x00002084
	thumb_func_end ov40_0223BD98


	thumb_func_start ov40_0223BF88
ov40_0223BF88: ; 0x0223BF88
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _0223BFA2
	cmp r1, #1
	beq _0223BFBA
	cmp r1, #2
	beq _0223C00A
	b _0223C030
_0223BFA2:
	bl ov40_0223B538
	add r0, r5, #0
	bl ov40_0223B574
	add r0, r5, #0
	bl ov40_0222DFB0
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223C0D4
_0223BFBA:
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
	beq _0223BFF0
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0223B480
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_0223BFF0:
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
	b _0223C0D4
_0223C00A:
	add r4, #8
	add r0, r4, #0
	bl ov40_0222DAA8
	add r0, r5, #0
	bl ov40_0222D88C
	mov r0, #1
	mov r1, #0x6d
	bl sub_0203A948
	add r0, r5, #0
	mov r1, #1
	bl ov40_0222FB90
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223C0D4
_0223C030:
	bl ov40_0222FBB4
	cmp r0, #0
	beq _0223C0D4
	add r0, r4, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	cmp r0, #0
	beq _0223C0A4
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
	add r0, r4, #0
	bl Heap_Free
	b _0223C0D4
_0223C0A4:
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
_0223C0D4:
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov40_0223BF88


	thumb_func_start ov40_0223C0D8
ov40_0223C0D8: ; 0x0223C0D8
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r5, [r4, r1]
	ldr r1, [r4, #8]
	cmp r1, #3
	bls _0223C0EA
	b _0223C21A
_0223C0EA:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0223C0F6: ; jump table
	.short _0223C0FE - _0223C0F6 - 2 ; case 0
	.short _0223C10E - _0223C0F6 - 2 ; case 1
	.short _0223C15C - _0223C0F6 - 2 ; case 2
	.short _0223C1BE - _0223C0F6 - 2 ; case 3
_0223C0FE:
	mov r1, #6
	mov r2, #7
	bl ov40_022307DC
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223C222
_0223C10E:
	bl ov40_0223CFA8
	mov r0, #0x6d
	str r0, [sp]
	ldr r0, _0223C228 ; =ov40_022454E0
	ldr r2, _0223C22C ; =ov40_0223CE64
	mov r1, #4
	add r3, r4, #0
	bl TouchHitboxController_Create
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0x6d
	str r0, [sp]
	ldr r0, _0223C230 ; =ov40_022454B0
	ldr r2, _0223C234 ; =ov40_0223CF00
	mov r1, #4
	add r3, r4, #0
	bl TouchHitboxController_Create
	mov r1, #0x63
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0x6d
	str r0, [sp]
	ldr r0, _0223C238 ; =ov40_0224549C
	ldr r2, _0223C23C ; =ov40_0223CF70
	mov r1, #2
	add r3, r4, #0
	bl TouchHitboxController_Create
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [r5, r1]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223C222
_0223C15C:
	mov r1, #1
	bl ov40_02230964
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	add r1, r4, #0
	bl ov40_02230638
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	bl ov40_02230410
	add r1, r0, #0
	add r0, r4, #0
	mov r2, #3
	bl ov40_022307DC
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	mov r1, #0
	bl ov40_022306A0
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223C222
_0223C1BE:
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
	beq _0223C200
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	mov r1, #1
	bl ov40_022306A0
	add r0, r4, #0
	bl ov40_0223CD14
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223C200:
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
	b _0223C222
_0223C21A:
	add r0, r4, #0
	mov r1, #7
	bl ov40_0222BF80
_0223C222:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0223C228: .word ov40_022454E0
_0223C22C: .word ov40_0223CE64
_0223C230: .word ov40_022454B0
_0223C234: .word ov40_0223CF00
_0223C238: .word ov40_0224549C
_0223C23C: .word ov40_0223CF70
	thumb_func_end ov40_0223C0D8

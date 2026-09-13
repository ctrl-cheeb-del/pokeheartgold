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
	.extern ov40_0223B4BC
	.extern ov40_0223B538
	.extern ov40_0223B574
	.extern ov40_0223B5B0
	.extern ov40_0223B62C
	.extern ov40_0223BA70
	.extern ov40_0223BB74
	.extern ov40_0223BD98
	.extern ov40_0223BF88
	.extern ov40_0223C0D8


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

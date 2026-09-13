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
	.extern ov40_0223B5B0
	.extern ov40_0223B62C
	.extern ov40_0223B75C
	.extern ov40_0223BA70
	.extern ov40_0223BB74
	.extern ov40_0223BD98
	.extern ov40_0223BF88
	.extern ov40_0223C0D8


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

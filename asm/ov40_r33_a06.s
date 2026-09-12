	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public AddTextPrinterParameterizedWithColor
	.public AddWindowParameterized
	.public BeginNormalPaletteFade
	.public BgClearTilemapBufferAndCommit
	.public BufferString
	.public FillWindowPixelBuffer
	.public GfGfxLoader_LoadCharDataFromOpenNarc
	.public GfGfxLoader_LoadScrnDataFromOpenNarc
	.public GfGfx_EngineATogglePlanes
	.public GfGfx_EngineBTogglePlanes
	.public Heap_Free
	.public InitWindow
	.public IsPaletteFadeFinished
	.public ManagedSprite_SetAnim
	.public MessageFormat_Delete
	.public NewString_ReadMsgData
	.public PaletteData_BlendPalettes
	.public ScheduleWindowCopyToVram
	.public StringExpandPlaceholders
	.public String_Delete
	.public String_New
	.public System_GetTouchNew
	.public TouchHitboxController_Create
	.public TouchHitboxController_Destroy
	.public ov40_0222BF80
	.public ov40_0222C4B8
	.public ov40_0222C4E8
	.public ov40_0222C6C8
	.public ov40_0222D66C
	.public ov40_0222D8C8
	.public ov40_0222D9E8
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222DAB0
	.public ov40_0222DED0
	.public ov40_0222DFB0
	.public ov40_0222E79C
	.public ov40_0222E7B8
	.public ov40_0222E7DC
	.public ov40_02230410
	.public ov40_02230638
	.public ov40_0223064C
	.public ov40_022306A0
	.public ov40_02230738
	.public ov40_022307DC
	.public ov40_02230964
	.public ov40_02230D94
	.public ov40_02230DCC
	.public ov40_0223A430
	.public ov40_0223A83C
	.public ov40_0223B374
	.public ov40_0223B44C
	.public ov40_0223C258
	.public ov40_0223C3A4
	.public ov40_0223C498
	.public ov40_0223C710
	.public ov40_0223C80C
	.public ov40_0223CCA0
	.public ov40_0223CCBC
	.public ov40_0223CD14
	.public ov40_0223CE64
	.public ov40_0223CF00
	.public ov40_0223CF70
	.public ov40_0223CFA8
	.public ov40_0223D504
	.public ov40_0224549C
	.public ov40_022454B0
	.public ov40_022454E0
	.public sub_020307F8
	.public sub_0203088C
	.public sub_020315B8
	.public sub_02087A84
	.text

	thumb_func_start ov40_0223C258
ov40_0223C258: ; 0x0223C258
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #3
	bls _0223C26A
	b _0223C388
_0223C26A:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0223C276: ; jump table
	.short _0223C27E - _0223C276 - 2 ; case 0
	.short _0223C2BC - _0223C276 - 2 ; case 1
	.short _0223C2D4 - _0223C276 - 2 ; case 2
	.short _0223C340 - _0223C276 - 2 ; case 3
_0223C27E:
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _0223C298
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0223064C
	b _0223C2A4
_0223C298:
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0222E7B8
_0223C2A4:
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223C3A0
_0223C2BC:
	mov r2, #1
	add r0, r4, #0
	add r1, r4, #4
	add r3, r2, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _0223C3A0
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223C3A0
_0223C2D4:
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _0223C304
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0222E79C
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl ov40_0222E7DC
	add r0, r5, #0
	mov r1, #0x50
	mov r2, #3
	bl ov40_022307DC
	b _0223C330
_0223C304:
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_02230638
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #0
	bl ov40_022306A0
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r4, r0
	bl ov40_02230410
	add r1, r0, #0
	add r0, r5, #0
	mov r2, #3
	bl ov40_022307DC
_0223C330:
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223C3A0
_0223C340:
	add r0, r4, #0
	add r1, r4, #4
	mov r2, #0
	mov r3, #1
	bl ov40_0222DA00
	cmp r0, #0
	beq _0223C3A0
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _0223C364
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #1
	bl ov40_0222E7DC
	b _0223C370
_0223C364:
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r4, r0
	mov r1, #1
	bl ov40_022306A0
_0223C370:
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223C3A0
_0223C388:
	ldr r1, [r4, #0x10]
	mov r0, #1
	eor r1, r0
	str r1, [r4, #0x10]
	add r0, r5, #0
	add r1, #0x79
	bl ov40_0223CCBC
	add r0, r5, #0
	mov r1, #7
	bl ov40_0222BF80
_0223C3A0:
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov40_0223C258


	thumb_func_start ov40_0223C3A4
ov40_0223C3A4: ; 0x0223C3A4
	push {r4, r5, lr}
	sub sp, #0xc
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _0223C3C0
	cmp r1, #1
	beq _0223C3E0
	cmp r1, #2
	beq _0223C3F0
	b _0223C482
_0223C3C0:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x6d
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223C48E
_0223C3E0:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0223C48E
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223C48E
_0223C3F0:
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _0223C40A
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0223064C
	b _0223C416
_0223C40A:
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r5, #0
	bl ov40_0222E7B8
_0223C416:
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl TouchHitboxController_Destroy
	mov r0, #0x63
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl TouchHitboxController_Destroy
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl TouchHitboxController_Destroy
	add r0, r5, #0
	bl ov40_0223A83C
	add r0, r5, #0
	bl ov40_0223CCA0
	add r0, r5, #0
	bl ov40_0223D504
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0222D8C8
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r1, [r5, #0x10]
	add r0, r5, #0
	ldr r1, [r1]
	bl ov40_0222C4E8
	ldr r0, _0223C494 ; =0x00000868
	mov r1, #1
	ldr r0, [r5, r0]
	mov r2, #0
	bl sub_02087A84
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223C48E
_0223C482:
	add r0, r4, #0
	bl Heap_Free
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, pc}
_0223C48E:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_0223C494: .word 0x00000868
	thumb_func_end ov40_0223C3A4


	thumb_func_start ov40_0223C498
ov40_0223C498: ; 0x0223C498
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov r1, #0x86
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r5, [r4, r1]
	ldr r1, [r4, #8]
	cmp r1, #5
	bls _0223C4AC
	b _0223C6CC
_0223C4AC:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0223C4B8: ; jump table
	.short _0223C4C4 - _0223C4B8 - 2 ; case 0
	.short _0223C592 - _0223C4B8 - 2 ; case 1
	.short _0223C5E0 - _0223C4B8 - 2 ; case 2
	.short _0223C642 - _0223C4B8 - 2 ; case 3
	.short _0223C69E - _0223C4B8 - 2 ; case 4
	.short _0223C6BC - _0223C4B8 - 2 ; case 5
_0223C4C4:
	bl ov40_02230738
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #0
	bl ov40_0222D9E8
	ldr r0, _0223C6E8 ; =0x00004138
	mov r2, #0
	ldr r0, [r4, r0]
	cmp r0, #0
	ble _0223C4F8
	mov r0, #0x9a
	lsl r0, r0, #6
	add r7, r0, #0
	add r3, r4, r0
	ldr r0, _0223C6E8 ; =0x00004138
	add r6, r4, #0
	sub r7, #0x78
_0223C4EA:
	str r3, [r6, r7]
	ldr r1, [r4, r0]
	add r2, r2, #1
	add r3, #0xe4
	add r6, r6, #4
	cmp r2, r1
	blt _0223C4EA
_0223C4F8:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x3e
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x3e
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	add r0, r4, #0
	mov r1, #6
	mov r2, #7
	bl ov40_022307DC
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x45
	lsl r0, r0, #2
	add r1, r4, #0
	add r0, r5, r0
	add r1, #0x14
	mov r2, #3
	bl ov40_0222D66C
	mov r0, #0x13
	lsl r0, r0, #4
	add r1, r4, #0
	add r0, r5, r0
	add r1, #0x14
	mov r2, #0x5e
	bl ov40_0222D66C
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl ManagedSprite_SetAnim
	mov r1, #0x7d
	ldr r0, _0223C6EC ; =0x00002088
	lsl r1, r1, #2
	str r1, [r5, r0]
	ldr r1, _0223C6F0 ; =0x000004A4
	sub r0, r0, #4
	ldrsh r1, [r4, r1]
	str r1, [r5, r0]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223C6E2
_0223C592:
	bl ov40_0223CFA8
	mov r0, #0x6d
	str r0, [sp]
	ldr r0, _0223C6F4 ; =ov40_022454E0
	ldr r2, _0223C6F8 ; =ov40_0223CE64
	mov r1, #4
	add r3, r4, #0
	bl TouchHitboxController_Create
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0x6d
	str r0, [sp]
	ldr r0, _0223C6FC ; =ov40_022454B0
	ldr r2, _0223C700 ; =ov40_0223CF00
	mov r1, #4
	add r3, r4, #0
	bl TouchHitboxController_Create
	mov r1, #0x63
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0x6d
	str r0, [sp]
	ldr r0, _0223C704 ; =ov40_0224549C
	ldr r2, _0223C708 ; =ov40_0223CF70
	mov r1, #2
	add r3, r4, #0
	bl TouchHitboxController_Create
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [r5, r1]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223C6E2
_0223C5E0:
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
	b _0223C6E2
_0223C642:
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
	beq _0223C684
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
_0223C684:
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
	b _0223C6E2
_0223C69E:
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x6d
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223C6E2
_0223C6BC:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0223C6E2
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223C6E2
_0223C6CC:
	ldr r0, _0223C70C ; =0x000006D8
	ldr r1, [r4, r0]
	add r1, r1, #1
	str r1, [r4, r0]
	add r0, r4, #0
	bl ov40_0222C4B8
	add r0, r4, #0
	mov r1, #7
	bl ov40_0222BF80
_0223C6E2:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0223C6E8: .word 0x00004138
_0223C6EC: .word 0x00002088
_0223C6F0: .word 0x000004A4
_0223C6F4: .word ov40_022454E0
_0223C6F8: .word ov40_0223CE64
_0223C6FC: .word ov40_022454B0
_0223C700: .word ov40_0223CF00
_0223C704: .word ov40_0224549C
_0223C708: .word ov40_0223CF70
_0223C70C: .word 0x000006D8
	thumb_func_end ov40_0223C498


	thumb_func_start ov40_0223C710
ov40_0223C710: ; 0x0223C710
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r4, r1, #0
	ldr r1, _0223C804 ; =0x000008A4
	add r5, r0, #0
	sub r1, #0x44
	ldr r6, [r5, r1]
	mov r1, #2
	bl ov40_0222C6C8
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, _0223C804 ; =0x000008A4
	add r0, r5, r0
	bl InitWindow
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1e
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xe
	str r0, [sp, #0xc]
	mov r0, #0x4b
	lsl r0, r0, #2
	ldr r1, _0223C804 ; =0x000008A4
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x24]
	add r1, r5, r1
	mov r2, #2
	mov r3, #1
	bl AddWindowParameterized
	cmp r4, #0x64
	bne _0223C7C4
	mov r0, #0x65
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	str r0, [sp, #0x14]
	mov r0, #0x6d
	bl ov40_0222DAB0
	add r7, r0, #0
	mov r0, #0xff
	mov r1, #0x6d
	bl String_New
	add r6, r0, #0
	ldr r0, [sp, #0x14]
	mov r1, #0x6d
	bl sub_020315B8
	str r0, [sp, #0x18]
	ldr r1, [sp, #0x18]
	add r0, r5, #0
	bl ov40_02230DCC
	ldr r0, [r5, #0x48]
	add r1, r4, #0
	bl NewString_ReadMsgData
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	mov r1, #0
	str r0, [sp, #4]
	ldr r2, [sp, #0x18]
	add r0, r7, #0
	add r3, r1, #0
	bl BufferString
	add r0, r7, #0
	add r1, r6, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x18]
	bl String_Delete
	add r0, r4, #0
	bl String_Delete
	add r0, r7, #0
	bl MessageFormat_Delete
	b _0223C7CE
_0223C7C4:
	ldr r0, [r5, #0x48]
	add r1, r4, #0
	bl NewString_ReadMsgData
	add r6, r0, #0
_0223C7CE:
	ldr r0, _0223C804 ; =0x000008A4
	mov r1, #0xcc
	add r0, r5, r0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0223C808 ; =0x000F0D0C
	add r2, r6, #0
	str r0, [sp, #8]
	ldr r0, _0223C804 ; =0x000008A4
	add r3, r1, #0
	add r0, r5, r0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _0223C804 ; =0x000008A4
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	add r0, r6, #0
	bl String_Delete
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0223C804: .word 0x000008A4
_0223C808: .word 0x000F0D0C
	thumb_func_end ov40_0223C710


	thumb_func_start ov40_0223C80C
ov40_0223C80C: ; 0x0223C80C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r5, [r4, r0]
	bl sub_020307F8
	mov r1, #4
	mov r2, #0
	bl sub_0203088C
	add r3, r0, #0
	add r2, r1, #0
	add r0, r4, #0
	add r1, r3, #0
	bl ov40_02230D94
	cmp r0, #0
	ldr r0, [r4, #8]
	bne _0223C838
	b _0223CB6C
_0223C838:
	cmp r0, #6
	bls _0223C83E
	b _0223CB3E
_0223C83E:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223C84A: ; jump table
	.short _0223C858 - _0223C84A - 2 ; case 0
	.short _0223C8BC - _0223C84A - 2 ; case 1
	.short _0223C91C - _0223C84A - 2 ; case 2
	.short _0223C92C - _0223C84A - 2 ; case 3
	.short _0223C964 - _0223C84A - 2 ; case 4
	.short _0223C9B4 - _0223C84A - 2 ; case 5
	.short _0223CAD4 - _0223C84A - 2 ; case 6
_0223C858:
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _0223C874
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	add r1, r4, #0
	bl ov40_0223064C
	b _0223C880
_0223C874:
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, r4, #0
	bl ov40_0222E7B8
_0223C880:
	add r0, r4, #0
	bl ov40_0223CCA0
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0223D504
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223CC98
_0223C8BC:
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
	beq _0223C902
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0223B374
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r4, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223C902:
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
	b _0223CC98
_0223C91C:
	ldr r1, _0223CC40 ; =0x00000115
	add r0, r4, #0
	bl ov40_0222DED0
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223CC98
_0223C92C:
	bl System_GetTouchNew
	cmp r0, #0
	bne _0223C936
	b _0223CC98
_0223C936:
	add r0, r4, #0
	bl ov40_0222DFB0
	ldr r0, [r4, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223CC98
_0223C964:
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
	beq _0223C99A
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0223B44C
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223C99A:
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
	b _0223CC98
_0223C9B4:
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0223A430
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, _0223CC44 ; =0x0000086C
	ldr r0, [r4, r0]
	cmp r0, #0xd2
	bne _0223CA0A
	mov r0, #0x45
	lsl r0, r0, #2
	add r1, r4, #0
	add r0, r5, r0
	add r1, #0x14
	mov r2, #3
	bl ov40_0222D66C
	mov r0, #0x13
	lsl r0, r0, #4
	add r1, r4, #0
	add r0, r5, r0
	add r1, #0x14
	mov r2, #0x5e
	bl ov40_0222D66C
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl ManagedSprite_SetAnim
_0223CA0A:
	add r0, r4, #0
	bl ov40_0223CD14
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x3e
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x3e
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _0223CA7C
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	add r1, r4, #0
	bl ov40_02230638
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	mov r1, #0
	bl ov40_022306A0
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	bl ov40_02230410
	add r1, r0, #0
	add r0, r4, #0
	mov r2, #3
	bl ov40_022307DC
	b _0223CAAC
_0223CA7C:
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, r4, #0
	bl ov40_0222E79C
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl ov40_0222E7DC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x50
	mov r3, #3
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
_0223CAAC:
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #6
	mov r3, #7
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223CC98
_0223CAD4:
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
	beq _0223CB24
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _0223CB02
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	mov r1, #1
	bl ov40_022306A0
	b _0223CB0E
_0223CB02:
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #1
	bl ov40_0222E7DC
_0223CB0E:
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223CB24:
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
	b _0223CC98
_0223CB3E:
	ldr r1, _0223CC48 ; =0x00004138
	mov r0, #0
	ldr r1, [r4, r1]
	cmp r1, #0
	ble _0223CB62
	mov r1, #0x9a
	lsl r1, r1, #6
	add r5, r4, r1
	ldr r2, _0223CC48 ; =0x00004138
	add r6, r4, #0
	sub r1, #0x78
_0223CB54:
	str r5, [r6, r1]
	ldr r3, [r4, r2]
	add r0, r0, #1
	add r5, #0xe4
	add r6, r6, #4
	cmp r0, r3
	blt _0223CB54
_0223CB62:
	add r0, r4, #0
	mov r1, #7
	bl ov40_0222BF80
	b _0223CC98
_0223CB6C:
	cmp r0, #0
	beq _0223CB7A
	cmp r0, #1
	beq _0223CBDE
	cmp r0, #2
	beq _0223CC4C
	b _0223CC90
_0223CB7A:
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _0223CB96
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	add r1, r4, #0
	bl ov40_0223064C
	b _0223CBA2
_0223CB96:
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, r4, #0
	bl ov40_0222E7B8
_0223CBA2:
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0223D504
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0223CCA0
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223CC98
_0223CBDE:
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
	beq _0223CC24
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0223B374
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r4, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223CC24:
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
	b _0223CC98
	nop
_0223CC40: .word 0x00000115
_0223CC44: .word 0x0000086C
_0223CC48: .word 0x00004138
_0223CC4C:
	add r0, r5, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #0
	mov r3, #1
	bl ov40_0222DA00
	cmp r0, #0
	beq _0223CC76
	add r0, r4, #0
	mov r1, #0x64
	mov r2, #0
	bl ov40_0223C710
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223CC76:
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
	b _0223CC98
_0223CC90:
	add r0, r4, #0
	mov r1, #0xc
	bl ov40_0222BF80
_0223CC98:
	mov r0, #0
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov40_0223C80C

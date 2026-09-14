	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public AddTextPrinterParameterizedWithColor
	.public AddTextWindowTopLeftCorner
	.public BgClearTilemapBufferAndCommit
	.public BufferString
	.public GfGfxLoader_LoadCharDataFromOpenNarc
	.public GfGfxLoader_LoadScrnDataFromOpenNarc
	.public GfGfx_EngineATogglePlanes
	.public GfGfx_EngineBTogglePlanes
	.public InitWindow
	.public ManagedSprite_SetAnim
	.public ManagedSprite_SetPositionXY
	.public MessageFormat_Delete
	.public NewString_ReadMsgData
	.public PaletteData_BlendPalettes
	.public RemoveWindow
	.public Sprite_DeleteAndFreeResources
	.public StringExpandPlaceholders
	.public String_Delete
	.public String_New
	.public TextOBJ_CopyFromBGWindow
	.public TextOBJ_SetSpritesDrawFlag
	.public TouchHitboxController_Destroy
	.public ov40_0222BF80
	.public ov40_0222D5AC
	.public ov40_0222D66C
	.public ov40_0222D6D0
	.public ov40_0222D78C
	.public ov40_0222D7DC
	.public ov40_0222D800
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222DAB0
	.public ov40_0222E79C
	.public ov40_0222E7B8
	.public ov40_0222E7DC
	.public ov40_02230410
	.public ov40_02230638
	.public ov40_0223064C
	.public ov40_022306A0
	.public ov40_022307DC
	.public ov40_02230964
	.public ov40_02230DCC
	.public ov40_0223A430
	.public ov40_0223A83C
	.public ov40_0223AF3C
	.public ov40_0223B190
	.public ov40_0223B29C
	.public ov40_0223B374
	.public ov40_0223B44C
	.public ov40_0223B4BC
	.public ov40_0223CCA0
	.public ov40_0223CD14
	.public ov40_022454C0
	.public ov40_022454D0
	.public sub_020136B4
	.public sub_020315B8
	.text
	thumb_func_start ov40_0223B29C
ov40_0223B29C: ; 0x0223B29C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r1, #0
	ldr r1, _0223B36C ; =0x0000088C
	lsl r6, r2, #2
	add r4, r5, r1
	ldr r1, [r4, r6]
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x48]
	cmp r1, #0
	bne _0223B2BC
	mov r1, #8
	bl NewString_ReadMsgData
	add r4, r0, #0
	b _0223B31A
_0223B2BC:
	mov r0, #0x6d
	bl ov40_0222DAB0
	add r7, r0, #0
	ldr r0, [r5, #0x48]
	mov r1, #7
	bl NewString_ReadMsgData
	str r0, [sp, #0x14]
	ldr r0, [r4, r6]
	mov r1, #0x6d
	bl sub_020315B8
	add r6, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	bl ov40_02230DCC
	mov r0, #0xff
	mov r1, #0x6d
	bl String_New
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	mov r1, #0
	str r0, [sp, #4]
	add r0, r7, #0
	add r2, r6, #0
	add r3, r1, #0
	bl BufferString
	ldr r2, [sp, #0x14]
	add r0, r7, #0
	add r1, r4, #0
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x14]
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r0, r7, #0
	bl MessageFormat_Delete
_0223B31A:
	add r0, sp, #0x18
	bl InitWindow
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	add r1, sp, #0x18
	mov r2, #0x14
	mov r3, #2
	bl AddTextWindowTopLeftCorner
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0223B370 ; =0x000E0D00
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, sp, #0x18
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x10]
	ldr r0, [r0, #8]
	ldr r1, [r1, #0xc]
	add r2, sp, #0x18
	mov r3, #0x6d
	bl TextOBJ_CopyFromBGWindow
	add r0, r4, #0
	bl String_Delete
	add r0, sp, #0x18
	bl RemoveWindow
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223B36C: .word 0x0000088C
_0223B370: .word 0x000E0D00
	thumb_func_end ov40_0223B29C


	thumb_func_start ov40_0223B374
ov40_0223B374: ; 0x0223B374
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	mov r1, #0x86
	lsl r1, r1, #4
	ldr r3, _0223B444 ; =ov40_022454C0
	ldr r4, [r0, r1]
	str r0, [sp]
	add r2, sp, #0x20
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _0223B448 ; =ov40_022454D0
	add r2, sp, #0x10
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [sp]
	mov r1, #2
	bl ov40_0222D78C
	mov r0, #0x45
	lsl r0, r0, #2
	add r5, r4, r0
	add r0, sp, #0x20
	str r0, [sp, #8]
	mov r0, #0x69
	str r0, [sp, #4]
	ldr r0, [sp]
	mov r6, #0
	str r0, [sp, #0xc]
	add r0, #0x14
	add r7, sp, #0x10
	str r0, [sp, #0xc]
_0223B3BA:
	ldr r0, [sp]
	mov r1, #2
	bl ov40_0222D800
	mov r1, #0x46
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r1, [sp, #0xc]
	add r0, r5, #0
	mov r2, #2
	bl ov40_0222D5AC
	ldr r2, [sp, #8]
	ldr r1, [sp, #0xc]
	ldr r2, [r2]
	add r0, r5, #0
	bl ov40_0222D66C
	cmp r6, #3
	beq _0223B3EC
	ldr r1, [sp]
	add r0, r5, #0
	add r2, r6, #1
	bl ov40_0223B29C
_0223B3EC:
	mov r0, #0x46
	ldr r2, [sp, #4]
	lsl r0, r0, #2
	lsl r2, r2, #0x10
	ldr r0, [r4, r0]
	mov r1, #0x32
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, [r7]
	bl ManagedSprite_SetAnim
	mov r0, #0x47
	lsl r0, r0, #2
	mov r1, #0x24
	add r2, r1, #0
	ldr r0, [r4, r0]
	sub r2, #0x2c
	bl sub_020136B4
	mov r0, #0x47
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	ldr r0, [sp, #8]
	add r6, r6, #1
	add r0, r0, #4
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r4, #0x1c
	add r0, #0x24
	add r5, #0x1c
	add r7, r7, #4
	str r0, [sp, #4]
	cmp r6, #4
	blt _0223B3BA
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223B444: .word ov40_022454C0
_0223B448: .word ov40_022454D0
	thumb_func_end ov40_0223B374


	thumb_func_start ov40_0223B44C
ov40_0223B44C: ; 0x0223B44C
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0x86
	lsl r1, r1, #4
	str r0, [sp]
	ldr r5, [r0, r1]
	mov r0, #0x45
	lsl r0, r0, #2
	mov r6, #0
	add r4, r5, r0
	add r7, r0, #4
_0223B460:
	add r0, r4, #0
	bl ov40_0222D6D0
	ldr r0, [r5, r7]
	bl Sprite_DeleteAndFreeResources
	add r6, r6, #1
	add r4, #0x1c
	add r5, #0x1c
	cmp r6, #4
	blt _0223B460
	ldr r0, [sp]
	bl ov40_0222D7DC
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov40_0223B44C

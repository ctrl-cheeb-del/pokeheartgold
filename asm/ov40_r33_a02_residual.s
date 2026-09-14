	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public AddTextPrinterParameterizedWithColor
	.public BgClearTilemapBufferAndCommit
	.public BufferString
	.public FillWindowPixelBuffer
	.public MI_CpuCopy8
	.public ManagedSprite_SetAnim
	.public ManagedSprite_SetPositionXY
	.public MessageFormat_Delete
	.public NewString_ReadMsgData
	.public PaletteData_BlendPalettes
	.public PlaySE
	.public ScheduleWindowCopyToVram
	.public StopSE
	.public StringExpandPlaceholders
	.public String_Delete
	.public String_New
	.public TextOBJ_SetSpritesDrawFlag
	.public ov39_02227720
	.public ov39_02227D44
	.public ov40_0222BF80
	.public ov40_0222D5AC
	.public ov40_0222D66C
	.public ov40_0222D6EC
	.public ov40_0222D800
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222DAB0
	.public ov40_0222DED0
	.public ov40_0222DFB0
	.public ov40_0222E7DC
	.public ov40_0222FC40
	.public ov40_022306A0
	.public ov40_0223077C
	.public ov40_02230CDC
	.public ov40_02230DCC
	.public ov40_0223A3BC
	.public ov40_0223A430
	.public ov40_0223A510
	.public ov40_0223A640
	.public ov40_0223B4BC
	.public ov40_0223D540
	.public ov40_0223D5CC
	.public ov40_0224557C
	.public sub_020136B4
	.public sub_020315B8
	.public sub_020879E0
	.public sub_02087A08
	.text

	thumb_func_start ov40_0223A3BC
ov40_0223A3BC: ; 0x0223A3BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x84
	ldr r4, _0223A428 ; =ov40_0224557C
	add r3, sp, #0xc
	mov r2, #0x3c
_0223A3C6:
	ldrh r1, [r4]
	add r4, r4, #2
	strh r1, [r3]
	add r3, r3, #2
	sub r2, r2, #1
	bne _0223A3C6
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #0x86
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	ldr r7, _0223A42C ; =0x00002090
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	str r0, [sp]
_0223A3E4:
	ldr r0, [sp]
	ldr r4, [sp, #4]
	lsl r1, r0, #2
	add r0, sp, #0xc
	mov r6, #0
	add r5, r0, r1
_0223A3F0:
	ldr r0, [r4, r7]
	cmp r0, #0
	beq _0223A402
	mov r1, #0
	mov r2, #2
	ldrsh r1, [r5, r1]
	ldrsh r2, [r5, r2]
	bl ManagedSprite_SetPositionXY
_0223A402:
	add r6, r6, #1
	add r4, #8
	add r5, r5, #4
	cmp r6, #6
	blt _0223A3F0
	ldr r0, [sp, #4]
	add r0, #0x30
	str r0, [sp, #4]
	ldr r0, [sp]
	add r0, r0, #6
	str r0, [sp]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #5
	blt _0223A3E4
	add sp, #0x84
	pop {r4, r5, r6, r7, pc}
	nop
_0223A428: .word ov40_0224557C
_0223A42C: .word 0x00002090
	thumb_func_end ov40_0223A3BC

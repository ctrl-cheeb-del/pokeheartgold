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


	thumb_func_start ov40_0223A430
ov40_0223A430: ; 0x0223A430
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	mov r1, #2
	bl ov40_0222D6EC
	add r0, r5, #0
	mov r1, #2
	bl ov40_0222D800
	mov r1, #0x46
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r5, #0
	mov r1, #2
	bl ov40_0222D800
	mov r1, #0x4d
	lsl r1, r1, #2
	str r0, [r4, r1]
	sub r1, #0x20
	add r0, r4, r1
	add r1, r5, #0
	add r1, #0x14
	mov r2, #2
	bl ov40_0222D5AC
	mov r0, #0x13
	lsl r0, r0, #4
	add r1, r5, #0
	add r0, r4, r0
	add r1, #0x14
	mov r2, #2
	bl ov40_0222D5AC
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
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x20
	mov r2, #0xe8
	bl ManagedSprite_SetPositionXY
	mov r0, #0x4d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x80
	mov r2, #0xe8
	bl ManagedSprite_SetPositionXY
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
	mov r0, #0x47
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	mov r0, #0x4e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	add r0, r5, #0
	mov r1, #0
	bl ov40_0223B4BC
	pop {r3, r4, r5, pc}
	thumb_func_end ov40_0223A430


	thumb_func_start ov40_0223A510
ov40_0223A510: ; 0x0223A510
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	ldr r0, _0223A638 ; =0x000008A4
	add r4, r1, #0
	sub r0, #0x44
	ldr r3, [r5, r0]
	cmp r4, #0x64
	bne _0223A58A
	mov r0, #0x65
	lsl r0, r0, #2
	ldr r0, [r3, r0]
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
	b _0223A602
_0223A58A:
	cmp r4, #0x66
	bne _0223A5FA
	lsl r0, r2, #2
	add r1, r5, r0
	ldr r0, _0223A638 ; =0x000008A4
	sub r0, #0x18
	ldr r0, [r1, r0]
	str r0, [sp, #0x10]
	mov r0, #0x6d
	bl ov40_0222DAB0
	add r7, r0, #0
	mov r0, #0xff
	mov r1, #0x6d
	bl String_New
	add r6, r0, #0
	ldr r0, [sp, #0x10]
	mov r1, #0x6d
	bl sub_020315B8
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x1c]
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
	ldr r2, [sp, #0x1c]
	add r0, r7, #0
	add r3, r1, #0
	bl BufferString
	add r0, r7, #0
	add r1, r6, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x1c]
	bl String_Delete
	add r0, r4, #0
	bl String_Delete
	add r0, r7, #0
	bl MessageFormat_Delete
	b _0223A602
_0223A5FA:
	ldr r0, [r5, #0x48]
	bl NewString_ReadMsgData
	add r6, r0, #0
_0223A602:
	ldr r0, _0223A638 ; =0x000008A4
	mov r1, #0xcc
	add r0, r5, r0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0223A63C ; =0x000F0D0C
	add r2, r6, #0
	str r0, [sp, #8]
	ldr r0, _0223A638 ; =0x000008A4
	add r3, r1, #0
	add r0, r5, r0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _0223A638 ; =0x000008A4
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	add r0, r6, #0
	bl String_Delete
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0223A638: .word 0x000008A4
_0223A63C: .word 0x000F0D0C
	thumb_func_end ov40_0223A510


	thumb_func_start ov40_0223A640
ov40_0223A640: ; 0x0223A640
	push {r3, r4, r5, lr}
	sub sp, #8
	mov r1, #0x86
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r5, [r4, r1]
	bl ov40_0223D5CC
	cmp r0, #0
	bne _0223A65A
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223A65A:
	ldr r0, [r4, #8]
	cmp r0, #4
	bls _0223A662
	b _0223A7E8
_0223A662:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223A66E: ; jump table
	.short _0223A678 - _0223A66E - 2 ; case 0
	.short _0223A6AE - _0223A66E - 2 ; case 1
	.short _0223A6E8 - _0223A66E - 2 ; case 2
	.short _0223A72E - _0223A66E - 2 ; case 3
	.short _0223A75A - _0223A66E - 2 ; case 4
_0223A678:
	ldr r0, [r4, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _0223A69C
	mov r0, #0x22
	lsl r0, r0, #4
	add r0, r5, r0
	mov r1, #0
	bl ov40_022306A0
	b _0223A6A8
_0223A69C:
	mov r0, #0x65
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl ov40_0222E7DC
_0223A6A8:
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223A6AE:
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
	beq _0223A6CE
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223A6CE:
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
	b _0223A812
_0223A6E8:
	add r0, r4, #0
	mov r1, #0x75
	bl ov40_0222DED0
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
	ldr r0, _0223A818 ; =0x00002038
	mov r1, #0
	str r1, [r5, r0]
	ldr r0, _0223A81C ; =0x0000057D
	bl PlaySE
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223A812
_0223A72E:
	add r0, r4, #0
	bl ov40_0223D540
	ldr r1, _0223A820 ; =0x000004D4
	ldr r1, [r4, r1]
	lsl r1, r1, #2
	add r2, r4, r1
	ldr r1, _0223A824 ; =0x00002608
	ldr r2, [r2, r1]
	add r1, r2, #0
	add r1, #0xd8
	add r2, #0xdc
	ldr r1, [r1]
	ldr r2, [r2]
	bl ov39_02227720
	cmp r0, #1
	bne _0223A812
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _0223A812
_0223A75A:
	add r0, r4, #0
	bl ov40_0222DFB0
	add r0, r4, #0
	bl ov40_0223D540
	add r1, sp, #4
	bl ov39_02227D44
	cmp r0, #1
	ldr r0, _0223A81C ; =0x0000057D
	bne _0223A794
	mov r1, #0
	bl StopSE
	ldr r3, [sp, #4]
	add r0, r4, #0
	ldr r2, [r3, #0xc]
	ldr r3, [r3, #4]
	mov r1, #8
	bl ov40_02230CDC
	ldr r0, [r4, #8]
	mov r1, #0
	add r0, r0, #1
	str r0, [r4, #8]
	ldr r0, _0223A818 ; =0x00002038
	str r1, [r5, r0]
	b _0223A7CC
_0223A794:
	mov r1, #0
	bl StopSE
	mov r0, #0xff
	ldr r1, _0223A818 ; =0x00002038
	str r0, [r4, #8]
	mov r2, #1
	str r2, [r5, r1]
	ldr r1, _0223A828 ; =0x0000413C
	add r2, r4, r1
	ldr r1, _0223A820 ; =0x000004D4
	ldr r1, [r4, r1]
	add r1, r2, r1
	ldr r2, _0223A82C ; =0x00000878
	str r1, [r4, r2]
	add r1, r2, #0
	add r1, #0x3c
	ldr r3, [r4, r1]
	add r1, r0, #0
	add r1, #0x85
	str r3, [r5, r1]
	add r0, #0x85
	add r2, #0x40
	add r1, r4, r2
	ldr r0, [r5, r0]
	ldr r2, _0223A830 ; =0x00001D4C
	bl MI_CpuCopy8
_0223A7CC:
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
	b _0223A812
_0223A7E8:
	ldr r0, _0223A818 ; =0x00002038
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0223A80A
	ldr r0, _0223A834 ; =0x00000577
	bl PlaySE
	ldr r1, _0223A838 ; =0x00002034
	add r0, r4, #0
	ldr r1, [r5, r1]
	bl ov40_0222BF80
	add r0, r4, #0
	mov r1, #1
	bl ov40_0222FC40
	b _0223A812
_0223A80A:
	add r0, r4, #0
	mov r1, #0x14
	bl ov40_0222BF80
_0223A812:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0223A818: .word 0x00002038
_0223A81C: .word 0x0000057D
_0223A820: .word 0x000004D4
_0223A824: .word 0x00002608
_0223A828: .word 0x0000413C
_0223A82C: .word 0x00000878
_0223A830: .word 0x00001D4C
_0223A834: .word 0x00000577
_0223A838: .word 0x00002034
	thumb_func_end ov40_0223A640

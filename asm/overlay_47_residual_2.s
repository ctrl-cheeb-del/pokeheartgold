	.include "asm/macros.inc"
	.include "overlay_47.inc"
	.include "global.inc"
	.include "overlay47_exact_bank.inc"

	.text
	.public ov47_02258A14
	.public ov47_02258A1C
	.public ov47_02258A60
	.public ov47_02258A80
	.public ov47_02258A8C
	.public ov47_02258B8C
	.public ov47_02258C44
	.public ov47_02258CC0
	.public ov47_02258CEC
	.public ov47_02258D18
	.public ov47_02258D44
	.public ov47_02258D78
	.public ov47_02258DA8
	.public ov47_02258DB4
	.public ov47_022591F8
	.public ov47_0225921C
	.public ov47_02259228
	.public ov47_02259278
	.public ov47_022592B4
	.public ov47_02259318
	.public ov47_02259384
	.public ov47_022593A0
	.public ov47_022593B4
	.public ov47_022593CC
	.public ov47_02259404
	.public ov47_02259430
	.public ov47_02259448
	.public ov47_0225945C
	.public ov47_0225946C
	.public ov47_02259968
	.public ov47_0225999C
	.public ov47_02259B30
	.public ov47_02259D24
	.public ov47_02259D40
	.public ov47_02259D58
	.public ov47_02259DA4
	.public ov47_02259DCC

	thumb_func_start ov47_02258AA0
ov47_02258AA0: ; 0x02258AA0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	ldr r0, _02258B7C ; =ov47_02259E48
	add r7, r2, #0
	str r1, [sp, #0x10]
	bl SetBothScreensModesAndDisable
	add r0, r7, #0
	bl BgConfig_Alloc
	str r0, [r5]
	ldr r0, _02258B80 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #0
	ldr r6, _02258B84 ; =ov47_02259F18
	ldr r4, _02258B88 ; =ov47_02259E68
	str r0, [sp, #0x14]
_02258ACA:
	ldr r1, [r4]
	ldr r0, [r5]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r2, r6, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r4]
	mov r1, #0x20
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r2, #0
	add r3, r7, #0
	bl BG_ClearCharDataRange
	ldr r1, [r4]
	ldr r0, [r5]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl BgClearTilemapBufferAndCommit
	ldr r0, [sp, #0x14]
	add r6, #0x1c
	add r0, r0, #1
	add r4, r4, #4
	str r0, [sp, #0x14]
	cmp r0, #4
	blt _02258ACA
	mov r0, #0
	mov r1, #0x80
	add r2, r7, #0
	bl LoadFontPal1
	ldr r0, [sp, #0x10]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	str r7, [sp, #4]
	mov r1, #1
	ldr r0, [r5]
	add r2, r1, #0
	mov r3, #5
	bl LoadUserFrameGfx2
	mov r0, #0
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [r5]
	mov r1, #1
	mov r2, #0x1f
	mov r3, #6
	bl LoadUserFrameGfx1
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	ldr r2, [r5]
	mov r0, #0xc6
	mov r1, #2
	mov r3, #4
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	ldr r2, [r5]
	mov r0, #0xc6
	mov r1, #6
	mov r3, #4
	bl GfGfxLoader_LoadScrnData
	mov r1, #0
	str r1, [sp]
	mov r0, #0xc6
	mov r2, #4
	add r3, r1, #0
	str r7, [sp, #4]
	bl GfGfxLoader_GXLoadPal
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02258B7C: .word ov47_02259E48
_02258B80: .word gSystem + 0x60
_02258B84: .word ov47_02259F18
_02258B88: .word ov47_02259E68
	thumb_func_end ov47_02258AA0

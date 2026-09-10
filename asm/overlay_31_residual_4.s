	.include "asm/macros.inc"
	.include "overlay_31.inc"
	.include "global.inc"

	.text
	.public _0225EE40
	.public _0225EF40
	.public ov31_0225D520
	.public ov31_0225D684
	.public ov31_0225D7A0
	.public ov31_0225D83C
	.public ov31_0225D9D4
	.public ov31_0225DAC4
	.public ov31_0225DB38
	.public ov31_0225DBD4
	.public ov31_0225DCA8
	.public ov31_0225DD14
	.public ov31_0225DE24
	.public ov31_0225DE84
	.public ov31_0225DF98
	.public ov31_0225E060
	.public ov31_0225E184
	.public ov31_0225E20C
	.public ov31_0225E2D4
	.public ov31_0225E54C
	.public ov31_0225E5FC
	.public ov31_0225E700
	.public ov31_0225E7D4
	.public ov31_0225EA08
	.public ov31_0225EA9C
	.public ov31_0225EB30
	.public ov31_0225EBC4
	.public ov31_0225EC58
	.public ov31_0225EE44
	.public ov31_0225EE60
	.public ov31_0225EE88
	.public ov31_0225EED0
	.public ov31_0225EEEC
	.public ov31_0225EF08
	.public ov31_0225EF48
	.public ov31_0225D60C
	.public ov31_0225D654
	.public ov31_0225D710
	.public ov31_0225D758
	.public ov31_0225D75C
	.public ov31_0225DAA4
	.public ov31_0225DBA0
	.public ov31_0225DCF4
	.public ov31_0225DE00
	.public ov31_0225E0E4
	.public ov31_0225E12C
	.public ov31_0225E474
	.public ov31_0225E4BC
	.public ov31_0225E4EC
	.public ov31_0225E51C
	.public ov31_0225E774
	.public ov31_0225E948
	.public ov31_0225E95C
	.public ov31_0225E9CC
	.public ov31_0225EDA0

	thumb_func_start ov31_0225DAC4
ov31_0225DAC4: ; 0x0225DAC4
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0
	bl GXS_SetGraphicsMode
	mov r0, #0x80
	bl GX_SetBankForSubBG
	mov r0, #1
	lsl r0, r0, #8
	bl GX_SetBankForSubOBJ
	ldr r2, _0225DB24 ; =0x04001000
	ldr r0, _0225DB28 ; =0xFFCFFFEF
	ldr r1, [r2]
	mov r3, #0
	and r1, r0
	mov r0, #0x10
	orr r0, r1
	str r0, [r2]
	ldr r0, [r4, #4]
	ldr r2, _0225DB2C ; =ov31_0225EED0
	mov r1, #4
	bl InitBgFromTemplate
	ldr r0, [r4, #4]
	ldr r2, _0225DB30 ; =ov31_0225EEEC
	mov r1, #5
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r4, #4]
	ldr r2, _0225DB34 ; =ov31_0225EF08
	mov r1, #6
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #6
	mov r1, #0x20
	mov r2, #0
	mov r3, #4
	bl BG_ClearCharDataRange
	ldr r0, [r4, #4]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	pop {r4, pc}
	.balign 4, 0
_0225DB24: .word 0x04001000
_0225DB28: .word 0xFFCFFFEF
_0225DB2C: .word ov31_0225EED0
_0225DB30: .word ov31_0225EEEC
_0225DB34: .word ov31_0225EF08
	thumb_func_end ov31_0225DAC4


	thumb_func_start ov31_0225DB38
ov31_0225DB38: ; 0x0225DB38
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r0, _0225DB9C ; =0x04001050
	mov r3, #0
	strh r3, [r0]
	str r3, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #0x3c
	mov r1, #0xf
	mov r2, #4
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0x3c
	mov r1, #0x10
	mov r3, #5
	bl GfGfxLoader_LoadCharData
	add r0, r4, #0
	mov r1, #0
	bl ov31_0225D9D4
	mov r1, #0x16
	mov r0, #4
	lsl r1, r1, #4
	mov r2, #8
	bl LoadFontPal1
	mov r1, #6
	mov r0, #4
	lsl r1, r1, #6
	mov r2, #8
	bl LoadFontPal0
	add r0, r4, #0
	bl ov31_0225DBD4
	add r0, r4, #0
	bl ov31_0225DCA8
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_0225DB9C: .word 0x04001050
	thumb_func_end ov31_0225DB38

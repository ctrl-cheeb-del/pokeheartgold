#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021F99A4
	.public ov15_021F9A8C
	.public ov15_021F9AE4
	.public ov15_021F9CBC
	.public ov15_021F9D28
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021FB680
	.extern ov15_021FBC6C
	.extern ov15_021FBC8C
	.extern ov15_021FBCAC
	.extern ov15_021FC224
	.extern ov15_021FC37C
	.extern ov15_021FC3E0
	.extern ov15_021FC3EC
	.extern ov15_021FD3C0
	.extern ov15_021FD3F0
	.extern ov15_021FE17C
	.extern ov15_021FE1D0
	.extern ov15_021FE204
	.extern ov15_021FE3E0
	.extern ov15_021FE584
	.extern ov15_021FE5A4
	.extern ov15_021FE5C4
	.extern ov15_021FE620

	.public Bag_Exit
	.public Bag_Init
	.public Bag_Main
	.public ov15_021F9C78
	.public ov15_021FB680
	.public ov15_021FBC6C
	.public ov15_021FBC8C
	.public ov15_021FBCAC
	.public ov15_021FC224
	.public ov15_021FC37C
	.public ov15_021FC3E0
	.public ov15_021FC3EC
	.public ov15_021FD3C0
	.public ov15_021FD3F0
	.public ov15_021FE17C
	.public ov15_021FE1D0
	.public ov15_021FE204
	.public ov15_021FE3E0
	.public ov15_021FE584
	.public ov15_021FE5A4
	.public ov15_021FE5C4
	.public ov15_021FE620
	.extern _022004EC
	.extern _02201300
	.extern _02201480
	.extern ov15_021FEA5C
	.extern ov15_021FEB64
	.extern ov15_021FEB84
	.extern ov15_021FECA0
	.extern ov15_021FECC4
	.extern ov15_021FECD8
	.extern ov15_021FED24
	.extern ov15_021FED3C
	.extern ov15_021FED58
	.extern ov15_021FED60
	.extern ov15_021FEDEC
	.extern ov15_021FEEA4
	.extern ov15_021FEF48
	.extern ov15_021FF004
	.extern ov15_021FF058
	.extern ov15_021FF068
	.extern ov15_021FF0FC
	.extern ov15_021FF1E0
	.extern ov15_021FF29C
	.extern ov15_021FF364
	.extern ov15_021FF4EC
	.extern ov15_021FF560
	.extern ov15_021FF6BC
	.extern ov15_021FF758
	.extern ov15_021FF7AC
	.extern ov15_021FF7C4
	.extern ov15_021FF7FC
	.extern ov15_021FF834
	.extern ov15_021FF844
	.extern ov15_021FF850
	.extern ov15_021FF894
	.extern ov15_021FF8D4
	.extern ov15_021FF950
	.extern ov15_021FF964
	.extern ov15_021FFECC
	.extern ov15_021FFF24
	.extern ov15_021FFF34
	.extern ov15_021FFFDC
	.extern ov15_02200030
	.extern ov15_0220005C
	.extern ov15_02200140
	.extern ov15_022001C4
	.extern ov15_0220023C
	.extern ov15_02200294
	.extern ov15_022002B4
	.extern ov15_022002EC
	.extern ov15_02200300
	.extern ov15_02200428
	.extern ov15_02200458
	.extern ov15_022004DC
	.extern ov15_022004F4
	.extern ov15_02200500
	.extern ov15_0220050C
	.extern ov15_02200518
	.extern ov15_02200528
	.extern ov15_02200529
	.extern ov15_0220052A
	.extern ov15_0220052B
	.extern ov15_0220053C
	.extern ov15_02200584
	.extern ov15_02200585
	.extern ov15_02200586
	.extern ov15_02200587
	.extern ov15_022005CC
	.extern ov15_02200618
	.extern ov15_02200640
	.extern ov15_02200641
	.extern ov15_02200642
	.extern ov15_02200643
	.extern ov15_022006CC
	.extern ov15_022006E8
	.extern ov15_02200704
	.extern ov15_02200720
	.extern ov15_0220073C
	.extern ov15_02200758
	.extern ov15_02200774
	.extern ov15_02200790
	.extern ov15_022008B0
	.extern ov15_022008D0
	.extern ov15_022008E8
	.extern ov15_02200908
	.extern ov15_02201304
	.extern ov15_02201314
	.extern ov15_02201328
	.extern ov15_02201340
	.extern ov15_02201368
	.extern ov15_022013A8
	.extern ov15_02201468

	thumb_func_start ov15_021F99A4
ov15_021F99A4: ; 0x021F99A4
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r5, _021F9A68 ; =ov15_02200518
	add r3, sp, #4
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r2, _021F9A6C ; =ov15_022006CC
	add r0, r4, #0
	mov r1, #1
	mov r3, #0
	bl InitBgFromTemplate
	ldr r2, _021F9A70 ; =ov15_022006E8
	add r0, r4, #0
	mov r1, #2
	mov r3, #0
	bl InitBgFromTemplate
	ldr r2, _021F9A74 ; =ov15_02200704
	add r0, r4, #0
	mov r1, #3
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	mov r0, #1
	mov r1, #0x20
	mov r2, #0
	mov r3, #6
	bl BG_ClearCharDataRange
	ldr r2, _021F9A78 ; =ov15_02200720
	add r0, r4, #0
	mov r1, #4
	mov r3, #0
	bl InitBgFromTemplate
	ldr r2, _021F9A7C ; =ov15_0220073C
	add r0, r4, #0
	mov r1, #5
	mov r3, #0
	bl InitBgFromTemplate
	ldr r2, _021F9A80 ; =ov15_02200758
	add r0, r4, #0
	mov r1, #6
	mov r3, #0
	bl InitBgFromTemplate
	ldr r2, _021F9A84 ; =ov15_02200774
	add r0, r4, #0
	mov r1, #7
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	mov r3, #6
	bl BG_ClearCharDataRange
	mov r0, #7
	mov r1, #0x20
	mov r2, #0
	mov r3, #6
	bl BG_ClearCharDataRange
	mov r1, #0
	ldr r0, _021F9A88 ; =0x04000050
	mov r2, #8
	add r3, r1, #0
	str r1, [sp]
	bl G2x_SetBlendAlpha_
	add sp, #0x14
	pop {r4, r5, pc}
	.balign 4, 0
_021F9A68: .word ov15_02200518
_021F9A6C: .word ov15_022006CC
_021F9A70: .word ov15_022006E8
_021F9A74: .word ov15_02200704
_021F9A78: .word ov15_02200720
_021F9A7C: .word ov15_0220073C
_021F9A80: .word ov15_02200758
_021F9A84: .word ov15_02200774
_021F9A88: .word 0x04000050
	thumb_func_end ov15_021F99A4


	thumb_func_start ov15_021F9A8C
ov15_021F9A8C: ; 0x021F9A8C
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x1f
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x1b
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	add r0, r4, #0
	mov r1, #7
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #6
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #5
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #4
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #3
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #2
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #1
	bl FreeBgTilemapBuffer
	mov r0, #6
	add r1, r4, #0
	bl Heap_FreeExplicit
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov15_021F9A8C


	thumb_func_start ov15_021F9AE4
ov15_021F9AE4: ; 0x021F9AE4
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0xf
	mov r1, #6
	bl NARC_New
	mov r1, #0x91
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #6
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xf
	mov r1, #7
	mov r3, #2
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #6
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xf
	mov r1, #0x36
	mov r3, #2
	bl GfGfxLoader_LoadScrnData
	ldr r0, _021F9C60 ; =0x00000615
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _021F9B4A
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #6
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xf
	mov r1, #0x5e
	mov r3, #3
	bl GfGfxLoader_LoadScrnData
	b _021F9B62
_021F9B4A:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #6
	str r0, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xf
	mov r1, #0x5d
	mov r3, #3
	bl GfGfxLoader_LoadScrnData
_021F9B62:
	mov r2, #0
	str r2, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #0xf
	mov r1, #8
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPal
	mov r0, #0x20
	str r0, [sp]
	mov r0, #6
	mov r3, #0x1a
	str r0, [sp, #4]
	mov r0, #0xf
	mov r1, #0x11
	mov r2, #0
	lsl r3, r3, #4
	bl GfGfxLoader_GXLoadPal
	mov r1, #0x16
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #6
	bl LoadFontPal1
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	ldr r0, [r4]
	ldr r2, _021F9C64 ; =0x000003F7
	mov r1, #1
	mov r3, #0xe
	bl LoadUserFrameGfx1
	mov r0, #9
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	ldr r0, [r4]
	ldr r2, _021F9C68 ; =0x000003D9
	mov r1, #1
	mov r3, #0xc
	bl LoadUserFrameGfx2
	mov r3, #0
	str r3, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #0xf
	mov r1, #0x26
	mov r2, #4
	bl GfGfxLoader_GXLoadPal
	mov r1, #0x16
	mov r0, #4
	lsl r1, r1, #4
	mov r2, #6
	bl LoadFontPal1
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r3, #6
	str r3, [sp, #0xc]
	ldr r2, [r4]
	mov r0, #0xf
	mov r1, #0x2e
	bl GfGfxLoader_LoadCharData
	ldr r2, _021F9C6C ; =0x00000694
	mov r0, #0xf
	mov r1, #0x28
	add r2, r4, r2
	mov r3, #6
	bl GfGfxLoader_GetPlttData
	ldr r2, _021F9C70 ; =0x0000068C
	mov r1, #0x29
	str r0, [r4, r2]
	add r2, #0xc
	mov r0, #0xf
	add r2, r4, r2
	mov r3, #6
	bl GfGfxLoader_GetPlttData
	mov r1, #0x69
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #0x80
	mov r2, #4
	str r0, [sp]
	mov r0, #6
	add r3, r2, #0
	str r0, [sp, #4]
	mov r0, #0xf
	mov r1, #8
	add r3, #0xfc
	bl GfGfxLoader_GXLoadPal
	mov r0, #9
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	ldr r0, [r4]
	ldr r2, _021F9C74 ; =0x000003E2
	mov r1, #4
	mov r3, #0xc
	bl LoadUserFrameGfx2
	add sp, #0x10
	pop {r4, pc}
	nop
_021F9C60: .word 0x00000615
_021F9C64: .word 0x000003F7
_021F9C68: .word 0x000003D9
_021F9C6C: .word 0x00000694
_021F9C70: .word 0x0000068C
_021F9C74: .word 0x000003E2
	thumb_func_end ov15_021F9AE4


	thumb_func_start ov15_021F9C78
ov15_021F9C78: ; 0x021F9C78
	push {r3, lr}
	sub sp, #0x10
	add r2, r0, #0
	cmp r1, #1
	bne _021F9C9E
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #6
	str r0, [sp, #0xc]
	ldr r2, [r2]
	mov r0, #0xf
	mov r1, #0x36
	mov r3, #2
	bl GfGfxLoader_LoadScrnData
	add sp, #0x10
	pop {r3, pc}
_021F9C9E:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #6
	str r0, [sp, #0xc]
	ldr r2, [r2]
	mov r0, #0xf
	mov r1, #9
	mov r3, #2
	bl GfGfxLoader_LoadScrnData
	add sp, #0x10
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov15_021F9C78


	thumb_func_start ov15_021F9CBC
ov15_021F9CBC: ; 0x021F9CBC
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xa
	mov r3, #6
	bl NewMsgDataFromNarc
	mov r1, #0x2f
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #1
	mov r1, #2
	mov r2, #0
	mov r3, #6
	bl MessagePrinter_New
	mov r1, #0xbb
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #6
	bl MessageFormat_New
	mov r1, #0xbd
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xde
	mov r3, #6
	bl NewMsgDataFromNarc
	mov r2, #0xbe
	lsl r2, r2, #2
	str r0, [r4, r2]
	mov r0, #0
	mov r1, #0x1b
	sub r2, #0xa
	mov r3, #6
	bl NewMsgDataFromNarc
	mov r1, #0xbf
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #1
	lsl r0, r0, #8
	mov r1, #6
	bl String_New
	ldr r1, _021F9D24 ; =0x000005E4
	str r0, [r4, r1]
	pop {r4, pc}
	.balign 4, 0
_021F9D24: .word 0x000005E4
	thumb_func_end ov15_021F9CBC


	thumb_func_start ov15_021F9D28
ov15_021F9D28: ; 0x021F9D28
	push {r3, r4, r5, r6}
	ldr r2, _021F9D5C ; =0x00000614
	mov r1, #0
	strb r1, [r0, r2]
	add r4, r2, #0
	mov r2, #0x8d
	lsl r2, r2, #2
	mov r3, #0xc
_021F9D38:
	add r5, r1, #0
	ldr r6, [r0, r2]
	mul r5, r3
	add r5, r6, r5
	ldr r5, [r5, #4]
	cmp r5, #0
	beq _021F9D4C
	ldrb r5, [r0, r4]
	add r5, r5, #1
	strb r5, [r0, r4]
_021F9D4C:
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, #8
	blo _021F9D38
	pop {r3, r4, r5, r6}
	bx lr
	nop
_021F9D5C: .word 0x00000614
	thumb_func_end ov15_021F9D28


	thumb_func_start ov15_021F9D60
ov15_021F9D60: ; 0x021F9D60
	push {r3, r4}
	mov r3, #0x8d
	lsl r3, r3, #2
	ldr r0, [r0, r3]
	add r4, r0, #4
	add r0, #0x64
	ldrb r3, [r0]
	mov r0, #0xc
	mul r0, r3
	cmp r2, #0
	ldr r2, [r4, r0]
	bne _021F9D80
	lsl r0, r1, #2
	ldrh r0, [r2, r0]
	pop {r3, r4}
	bx lr
_021F9D80:
	lsl r0, r1, #2
	add r0, r2, r0
	ldrh r0, [r0, #2]
	pop {r3, r4}
	bx lr
	.balign 4, 0
	thumb_func_end ov15_021F9D60

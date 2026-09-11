	.include "asm/macros.inc"
	.public GeonetGlobe_Init
	.public GeonetGlobe_Main
	.public GeonetGlobe_Exit
	.public ov69_021E60F8
	.public ov69_021E6118
	.public ov69_021E6138
	.public ov69_021E623C
	.public ov69_021E62B0
	.public ov69_021E6300
	.public ov69_021E6308
	.public ov69_021E645C
	.public ov69_021E64CC
	.public ov69_021E67B8
	.public ov69_021E6810
	.public ov69_021E68D8
	.public ov69_021E68EC
	.public ov69_021E6994
	.public ov69_021E6A54
	.public ov69_021E6A8C
	.public ov69_021E6B5C
	.public ov69_021E6C14
	.public ov69_021E6C30
	.public ov69_021E6D5C
	.public ov69_021E6E88
	.public ov69_021E6F48
	.public ov69_021E6F8C
	.public ov69_021E6FE8
	.public ov69_021E706C
	.public ov69_021E70A8
	.public ov69_021E7120
	.public ov69_021E7198
	.public ov69_021E737C
	.public ov69_021E7408
	.public ov69_021E7520
	.public ov69_021E758C
	.public ov69_021E75A0
	.public ov69_021E75F8
	.public _021E7644
	.public ov69_021E764C
	.public ov69_021E7654
	.public ov69_021E765C
	.public ov69_021E7664
	.public ov69_021E766C
	.public ov69_021E7674
	.public ov69_021E767C
	.public ov69_021E7688
	.public ov69_021E7698
	.public ov69_021E76B0
	.public ov69_021E76CC
	.public ov69_021E76E8
	.public ov69_021E7708
	.public ov69_021E7728
	.public ov69_021E774C
	.public ov69_021E7770
	.public ov69_021E7794
	.public ov69_021E77B8
	.include "overlay_69.inc"
	.include "global.inc"

	.text
	.public GeonetGlobe_Exit
	.public ov69_021E6300
	.public ov69_021E67B8
	.public ov69_021E68D8
	.public ov69_021E6A54
	.public ov69_021E6C14
	.public ov69_021E6F48
	.public ov69_021E6F8C
	.public ov69_021E706C
	.public ov69_021E758C
	.public ov69_021E75F8
	.public ov69_021E6308
	.public ov69_021E645C


	thumb_func_start ov69_021E64CC
ov69_021E64CC: ; 0x021E64CC
	push {r3, r4, r5, lr}
	sub sp, #0x18
	add r4, r0, #0
	ldr r0, _021E676C ; =0x0000C010
	ldr r2, _021E6770 ; =ov69_021E76B0
	add r5, r1, #0
	ldr r0, [r4, r0]
	mov r1, #6
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, _021E676C ; =0x0000C010
	mov r1, #6
	ldr r0, [r4, r0]
	bl BgClearTilemapBufferAndCommit
	ldr r0, _021E676C ; =0x0000C010
	ldr r2, _021E6774 ; =ov69_021E76CC
	ldr r0, [r4, r0]
	mov r1, #7
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	ldr r2, _021E676C ; =0x0000C010
	str r0, [sp, #0xc]
	ldr r2, [r4, r2]
	add r0, r5, #0
	mov r1, #5
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x80
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #6
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #7
	str r0, [sp, #0xc]
	ldr r2, _021E676C ; =0x0000C010
	add r0, r5, #0
	ldr r2, [r4, r2]
	add r3, r1, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r0, [r4, #8]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #6
	str r0, [sp, #4]
	ldr r0, _021E676C ; =0x0000C010
	ldr r2, _021E6778 ; =0x000001E2
	ldr r0, [r4, r0]
	add r3, r1, #0
	bl LoadUserFrameGfx2
	mov r0, #0
	str r0, [sp]
	ldr r0, [r4]
	ldr r2, _021E677C ; =0x000001D9
	str r0, [sp, #4]
	ldr r0, _021E676C ; =0x0000C010
	mov r1, #6
	ldr r0, [r4, r0]
	mov r3, #7
	bl LoadUserFrameGfx1
	ldr r2, [r4]
	mov r0, #4
	mov r1, #0x80
	bl LoadFontPal0
	ldr r3, [r4]
	mov r0, #6
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	ldr r1, _021E6780 ; =0x00004753
	mov r0, #6
	bl BG_SetMaskColor
	ldr r1, _021E676C ; =0x0000C010
	ldr r2, _021E6784 ; =ov69_021E766C
	ldr r0, [r4, r1]
	add r1, r1, #4
	add r1, r4, r1
	bl AddWindow
	mov r0, #0xd8
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, _021E6788 ; =0x0000C014
	mov r2, #0
	add r0, r4, r0
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	ldr r0, _021E6788 ; =0x0000C014
	ldr r2, _021E6778 ; =0x000001E2
	add r0, r4, r0
	mov r1, #0
	mov r3, #6
	bl DrawFrameAndWindow2
	ldr r0, _021E678C ; =0x0000C074
	mov r3, #0
	str r3, [r4, r0]
	sub r0, #0x64
	ldr r0, [r4, r0]
	ldr r2, _021E6770 ; =ov69_021E76B0
	mov r1, #2
	bl InitBgFromTemplate
	ldr r0, _021E676C ; =0x0000C010
	mov r1, #2
	ldr r0, [r4, r0]
	bl BgClearTilemapBufferAndCommit
	ldr r0, _021E676C ; =0x0000C010
	ldr r2, _021E6774 ; =ov69_021E76CC
	ldr r0, [r4, r0]
	mov r1, #3
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	ldr r2, _021E676C ; =0x0000C010
	str r0, [sp, #0xc]
	ldr r2, [r4, r2]
	add r0, r5, #0
	mov r1, #5
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x80
	str r0, [sp]
	ldr r0, [r4]
	mov r2, #0
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #6
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4]
	ldr r2, _021E676C ; =0x0000C010
	str r0, [sp, #0xc]
	ldr r2, [r4, r2]
	add r0, r5, #0
	mov r1, #7
	mov r3, #3
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, [r4]
	ldr r2, _021E677C ; =0x000001D9
	str r0, [sp, #4]
	ldr r0, _021E676C ; =0x0000C010
	mov r1, #2
	ldr r0, [r4, r0]
	mov r3, #7
	bl LoadUserFrameGfx1
	ldr r2, [r4]
	mov r0, #0
	mov r1, #0x80
	bl LoadFontPal0
	mov r1, #0x1e
	ldr r2, [r4]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	ldr r3, [r4]
	mov r0, #2
	mov r1, #0x20
	mov r2, #0
	bl BG_ClearCharDataRange
	mov r0, #2
	mov r1, #0
	bl BG_SetMaskColor
	ldr r1, [r4]
	mov r0, #0x10
	bl String_New
	add r5, r0, #0
	ldr r1, [r4]
	mov r0, #4
	bl FontID_Alloc
	ldr r2, _021E6790 ; =0x00007FFF
	add r0, sp, #0x10
	ldr r1, _021E6794 ; =0x00001CE7
	strh r2, [r0, #6]
	strh r1, [r0, #4]
	ldr r1, _021E6798 ; =0x00004E72
	ldr r3, _021E6778 ; =0x000001E2
	strh r1, [r0, #2]
	strh r2, [r0]
	mov r0, #2
	add r1, sp, #0x14
	add r1, #2
	add r2, r0, #0
	bl BG_LoadPlttData
	mov r0, #2
	mov r3, #0x79
	add r1, sp, #0x14
	add r2, r0, #0
	lsl r3, r3, #2
	bl BG_LoadPlttData
	mov r0, #2
	add r1, sp, #0x10
	ldr r3, _021E679C ; =0x000001E6
	add r1, #2
	add r2, r0, #0
	bl BG_LoadPlttData
	mov r0, #2
	ldr r3, _021E67A0 ; =0x000001FE
	add r1, sp, #0x10
	add r2, r0, #0
	bl BG_LoadPlttData
	ldr r1, _021E676C ; =0x0000C010
	ldr r2, _021E67A4 ; =ov69_021E765C
	ldr r0, [r4, r1]
	add r1, #0x24
	add r1, r4, r1
	bl AddWindow
	mov r0, #0xd8
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, _021E67A8 ; =0x0000C034
	mov r2, #0
	add r0, r4, r0
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	ldr r0, _021E67AC ; =0x0000C070
	mov r1, #0x10
	ldr r0, [r4, r0]
	add r2, r5, #0
	bl ReadMsgDataIntoString
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E67A8 ; =0x0000C034
	mov r1, #4
	add r0, r4, r0
	add r2, r5, #0
	str r3, [sp, #8]
	bl AddTextPrinterParameterized
	ldr r1, _021E676C ; =0x0000C010
	ldr r2, _021E67B0 ; =ov69_021E7654
	ldr r0, [r4, r1]
	add r1, #0x34
	add r1, r4, r1
	bl AddWindow
	mov r0, #0xd8
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, _021E67B4 ; =0x0000C044
	mov r2, #0
	add r0, r4, r0
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	ldr r0, _021E67AC ; =0x0000C070
	mov r1, #0xd
	ldr r0, [r4, r0]
	add r2, r5, #0
	bl ReadMsgDataIntoString
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E67B4 ; =0x0000C044
	mov r1, #4
	add r0, r4, r0
	add r2, r5, #0
	str r3, [sp, #8]
	bl AddTextPrinterParameterized
	add r0, r5, #0
	bl String_Delete
	mov r0, #4
	bl FontID_Release
	add sp, #0x18
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E676C: .word 0x0000C010
_021E6770: .word ov69_021E76B0
_021E6774: .word ov69_021E76CC
_021E6778: .word 0x000001E2
_021E677C: .word 0x000001D9
_021E6780: .word 0x00004753
_021E6784: .word ov69_021E766C
_021E6788: .word 0x0000C014
_021E678C: .word 0x0000C074
_021E6790: .word 0x00007FFF
_021E6794: .word 0x00001CE7
_021E6798: .word 0x00004E72
_021E679C: .word 0x000001E6
_021E67A0: .word 0x000001FE
_021E67A4: .word ov69_021E765C
_021E67A8: .word 0x0000C034
_021E67AC: .word 0x0000C070
_021E67B0: .word ov69_021E7654
_021E67B4: .word 0x0000C044
	thumb_func_end ov69_021E64CC

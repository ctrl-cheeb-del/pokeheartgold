	.include "asm/macros.inc"
	.include "overlay_108.inc"
	.include "global.inc"

	.text
	.extern SafariDecoration_Init
	.extern SafariDecoration_Exit
	.extern SafariDecoration_Main
	.extern ov108_021E8968
	.extern ov108_021E8A88
	.extern ov108_021E8AD4
	.extern ov108_021E8B24
	.extern ov108_021E8B68
	.extern ov108_021E8BC0
	.extern ov108_021E8C18
	.extern ov108_021E8C64
	.extern ov108_021E8CD4
	.extern ov108_021E8E10
	.extern ov108_021E8E60
	.extern ov108_021E8EA4
	.extern ov108_021E8ED8
	.extern ov108_021E8F00
	.extern ov108_021E90C4
	.extern ov108_021E9144
	.extern ov108_021E9198
	.extern ov108_021E91D4
	.extern ov108_021E91F8
	.extern ov108_021E9204
	.extern ov108_021E9210
	.extern ov108_021E9230
	.extern ov108_021E929C
	.extern ov108_021E9304
	.extern ov108_021E9388
	.extern ov108_021E93A8
	.extern ov108_021E940C
	.extern ov108_021E9488
	.extern ov108_021E94E8
	.extern ov108_021E9528
	.extern ov108_021E95AC
	.extern ov108_021E96FC
	.extern ov108_021E979C
	.extern ov108_021E9830
	.extern ov108_021E9850
	.extern ov108_021E9A08
	.extern ov108_021E9BD4
	.extern ov108_021E9C14
	.extern ov108_021E9C2C
	.extern ov108_021E9C3C
	.extern ov108_021E9CD0
	.extern ov108_021E9D30
	.extern ov108_021E9DE0
	.extern ov108_021E9E10
	.extern ov108_021E9E80
	.extern ov108_021E9EB8
	.extern ov108_021E9F04
	.extern ov108_021E9F20
	.extern ov108_021E9F94
	.extern ov108_021EA040
	.extern ov108_021EA260
	.extern ov108_021EA2EC
	.extern ov108_021EA334
	.extern ov108_021EA418
	.extern ov108_021EA47C
	.extern ov108_021EA50C
	.extern ov108_021EA52C
	.extern ov108_021EA584
	.extern ov108_021EA5E4
	.extern ov108_021EA624
	.extern ov108_021EA63C
	.extern ov108_021EA700
	.extern ov108_021EA9C4
	.extern ov108_021EA9D8
	.extern ov108_021EA9E4
	.extern ov108_021EAAA4
	.extern ov108_021EAAB0
	.extern ov108_021EAAC0
	.extern ov108_021EAAD0
	.extern ov108_021EAAE4
	.extern ov108_021EAB00
	.extern ov108_021EAB1C
	.extern ov108_021EAB38
	.extern ov108_021EAB54
	.extern ov108_021EAB70
	.extern ov108_021EAB8C
	.extern ov108_021EABA8
	.extern ov108_021EABC8
	.extern ov108_021EABF0
	.extern ov108_021EAC18
	.extern ov108_021EAC48
	.extern ov108_021EACE8
	.extern ov108_021EACF0
	.extern ov108_021EACF8
	.extern ov108_021EAD00
	.extern ov108_021EAD08
	.extern ov108_021EAD28


	thumb_func_start ov108_021E9A60
ov108_021E9A60: ; 0x021E9A60
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0xe1
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	ldr r1, [r5]
	ldr r2, _021E9BC0 ; =0x00000438
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	mov r1, #1
	mov r3, #3
	add r4, r0, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5]
	ldr r2, _021E9BC0 ; =0x00000438
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r4, #0
	mov r1, #5
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r1, #0
	str r1, [sp]
	ldr r0, [r5]
	add r2, r1, #0
	str r0, [sp, #4]
	add r0, r4, #0
	add r3, r1, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5]
	mov r1, #4
	str r0, [sp, #4]
	add r0, r4, #0
	add r2, r1, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r1, #0x1a
	ldr r2, [r5]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal1
	mov r1, #0x1a
	ldr r2, [r5]
	mov r0, #4
	lsl r1, r1, #4
	bl LoadFontPal1
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5]
	ldr r2, _021E9BC0 ; =0x00000438
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r4, #0
	mov r1, #2
	mov r3, #3
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5]
	ldr r2, _021E9BC0 ; =0x00000438
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r4, #0
	mov r1, #3
	mov r3, #2
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5]
	ldr r2, _021E9BC0 ; =0x00000438
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r4, #0
	mov r1, #6
	mov r3, #7
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r0, [r5]
	ldr r3, _021E9BC4 ; =0x0000051C
	str r0, [sp]
	add r0, r4, #0
	mov r1, #8
	mov r2, #0
	add r3, r5, r3
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	ldr r3, _021E9BC8 ; =0x00000518
	mov r1, #6
	str r0, [r5, r3]
	ldr r0, [r5]
	add r3, #0xc
	str r0, [sp]
	add r0, r4, #0
	mov r2, #0
	add r3, r5, r3
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	mov r3, #0x52
	lsl r3, r3, #4
	str r0, [r5, r3]
	ldr r0, [r5]
	add r3, #0xc
	str r0, [sp]
	add r0, r4, #0
	mov r1, #7
	mov r2, #0
	add r3, r5, r3
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	ldr r1, _021E9BCC ; =0x00000528
	str r0, [r5, r1]
	add r0, r4, #0
	bl NARC_Delete
	ldrb r0, [r5, #0x19]
	ldr r2, _021E9BC0 ; =0x00000438
	mov r1, #4
	str r0, [sp]
	ldr r0, [r5]
	mov r3, #0xc
	str r0, [sp, #4]
	ldr r0, [r5, r2]
	sub r2, #0x56
	bl LoadUserFrameGfx2
	mov r1, #0x1a
	ldr r2, [r5]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal1
	ldr r0, _021E9BC0 ; =0x00000438
	mov r1, #7
	ldr r0, [r5, r0]
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _021E9BC0 ; =0x00000438
	mov r1, #3
	ldr r0, [r5, r0]
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #4
	str r0, [sp]
	ldr r0, _021E9BD0 ; =0x04000050
	mov r1, #1
	mov r2, #0x1e
	mov r3, #0x1c
	bl G2x_SetBlendAlpha_
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E9BC0: .word 0x00000438
_021E9BC4: .word 0x0000051C
_021E9BC8: .word 0x00000518
_021E9BCC: .word 0x00000528
_021E9BD0: .word 0x04000050
	thumb_func_end ov108_021E9A60

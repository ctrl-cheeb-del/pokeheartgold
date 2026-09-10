	.include "asm/macros.inc"
	.include "overlay_108.inc"
	.include "global.inc"

	.text
	.public _021EA720
	.public ov108_021E5C54
	.public ov108_021E5D0C
	.public ov108_021E5DB8
	.public ov108_021E5E68
	.public ov108_021E5F38
	.public ov108_021E6090
	.public ov108_021E62B4
	.public ov108_021E63B8
	.public ov108_021E6450
	.public ov108_021E64C0
	.public ov108_021E66AC
	.public ov108_021E6894
	.public ov108_021E69A0
	.public ov108_021E6A58
	.public ov108_021E6B00
	.public ov108_021E6BA0
	.public ov108_021E6C68
	.public ov108_021E6D24
	.public ov108_021E6D80
	.public ov108_021E6F74
	.public ov108_021E7014
	.public ov108_021E7080
	.public ov108_021E7224
	.public ov108_021E733C
	.public ov108_021E756C
	.public ov108_021E767C
	.public ov108_021E7700
	.public ov108_021E77D4
	.public ov108_021E78F4
	.public ov108_021E79A8
	.public ov108_021E7ADC
	.public ov108_021E7B74
	.public ov108_021E7BB4
	.public ov108_021E7C5C
	.public ov108_021E7CD8
	.public ov108_021E7EB0
	.public ov108_021E7F7C
	.public ov108_021E80F4
	.public ov108_021E81A8
	.public ov108_021E8270
	.public ov108_021E82E0
	.public ov108_021E84F8
	.public ov108_021E8540
	.public ov108_021E867C
	.public ov108_021E8758
	.public ov108_021EA724
	.public ov108_021EA738
	.public ov108_021EA748
	.public ov108_021EA74A
	.public ov108_021EA760
	.public ov108_021EA780
	.public ov108_021EA7A8
	.public ov108_021EA7D0
	.public ov108_021EA7F8
	.public ov108_021EA820
	.public ov108_021EA848
	.public ov108_021EA870
	.public ov108_021EA898
	.public ov108_021EA978
	.public ov108_021EA97C
	.public ov108_021EA98C
	.public ov108_021EA9A0

	.public SafariAreaCustomizer_Exit
	.public SafariAreaCustomizer_Init
	.public SafariAreaCustomizer_Main
	.public ov108_021E59E4
	.public ov108_021E5A48
	.public ov108_021E5A78
	.public ov108_021E5A8C
	.public ov108_021E5AA0
	.public ov108_021E5AF0
	.public ov108_021E5B48
	.public ov108_021E5B98
	.public ov108_021E5BFC
	.public ov108_021E5D90
	.public ov108_021E5F10
	.public ov108_021E6010
	.public ov108_021E6068
	.public ov108_021E61E8
	.public ov108_021E6238
	.public ov108_021E6240
	.public ov108_021E6804
	.public ov108_021E6850
	.public ov108_021E6C48
	.public ov108_021E6F58
	.public ov108_021E71EC
	.public ov108_021E72A4
	.public ov108_021E72CC
	.public ov108_021E730C
	.public ov108_021E7510
	.public ov108_021E7650
	.public ov108_021E78C0
	.public ov108_021E7BFC
	.public ov108_021E838C
	.public ov108_021E83C8
	.public ov108_021E83F0
	.public ov108_021E844C
	.public ov108_021E846C
	.public ov108_021E8490
	.public ov108_021E84A4
	.public ov108_021E84DC
	.public ov108_021E852C
	.public ov108_021E853C
	.public ov108_021E8674
	.public ov108_021E8718

	thumb_func_start ov108_021E6C68
ov108_021E6C68: ; 0x021E6C68
	push {r4, r5, r6, r7, lr}
	sub sp, #0xf4
	add r5, r0, #0
	bl ov108_021E6C48
	ldr r2, _021E6D0C ; =0x04000304
	ldr r0, _021E6D10 ; =0xFFFF7FFF
	ldrh r1, [r2]
	and r0, r1
	strh r0, [r2]
	ldr r0, [r5]
	bl BgConfig_Alloc
	mov r1, #0xd
	lsl r1, r1, #6
	add r3, sp, #4
	ldr r4, _021E6D14 ; =ov108_021EA738
	str r0, [r5, r1]
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _021E6D18 ; =ov108_021EA898
	add r3, sp, #0x14
	mov r2, #0x1c
_021E6CA2:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E6CA2
	mov r4, #0
	add r7, r4, #0
	add r6, sp, #0x14
_021E6CB0:
	mov r0, #0xd
	lsl r0, r0, #6
	lsl r1, r4, #0x18
	ldr r0, [r5, r0]
	lsr r1, r1, #0x18
	add r2, r6, #0
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #0xd
	lsl r0, r0, #6
	lsl r1, r4, #0x18
	ldr r0, [r5, r0]
	lsr r1, r1, #0x18
	bl BgClearTilemapBufferAndCommit
	lsl r0, r4, #0x18
	ldr r3, [r5]
	lsr r0, r0, #0x18
	mov r1, #0x40
	mov r2, #0
	bl BG_ClearCharDataRange
	add r7, r7, #1
	add r4, r4, #1
	add r6, #0x1c
	cmp r7, #8
	blt _021E6CB0
	mov r0, #4
	str r0, [sp]
	mov r2, #0x1c
	ldr r0, _021E6D1C ; =0x04000050
	mov r1, #2
	add r3, r2, #0
	bl G2x_SetBlendAlpha_
	mov r0, #4
	str r0, [sp]
	ldr r0, _021E6D20 ; =0x04001050
	mov r1, #1
	mov r2, #0x1e
	mov r3, #0x1c
	bl G2x_SetBlendAlpha_
	add sp, #0xf4
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6D0C: .word 0x04000304
_021E6D10: .word 0xFFFF7FFF
_021E6D14: .word ov108_021EA738
_021E6D18: .word ov108_021EA898
_021E6D1C: .word 0x04000050
_021E6D20: .word 0x04001050
	thumb_func_end ov108_021E6C68


	thumb_func_start ov108_021E6D24
ov108_021E6D24: ; 0x021E6D24
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	mov r1, #0
	add r5, r0, #0
	ldr r0, _021E6D74 ; =0x04000050
	add r2, r1, #0
	mov r3, #0x1f
	str r1, [sp]
	bl G2x_SetBlendAlpha_
	mov r1, #0
	ldr r0, _021E6D78 ; =0x04001050
	add r2, r1, #0
	mov r3, #0x1f
	str r1, [sp]
	bl G2x_SetBlendAlpha_
	mov r6, #0xd
	mov r4, #0
	lsl r6, r6, #6
_021E6D4C:
	lsl r1, r4, #0x18
	ldr r0, [r5, r6]
	lsr r1, r1, #0x18
	bl FreeBgTilemapBuffer
	add r4, r4, #1
	cmp r4, #8
	blt _021E6D4C
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl Heap_Free
	ldr r2, _021E6D7C ; =0x04000304
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021E6D74: .word 0x04000050
_021E6D78: .word 0x04001050
_021E6D7C: .word 0x04000304
	thumb_func_end ov108_021E6D24


	thumb_func_start ov108_021E6D80
ov108_021E6D80: ; 0x021E6D80
	push {r4, r5, lr}
	sub sp, #0x14
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0xa6
	bl NARC_New
	add r4, r0, #0
	mov r0, #6
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5]
	add r2, r4, #0
	mov r3, #0xa6
	bl BgConfig_LoadAssetFromOpenNarc
	mov r0, #6
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5]
	add r2, r4, #0
	mov r3, #0xa6
	bl BgConfig_LoadAssetFromOpenNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5]
	add r2, r4, #0
	mov r3, #0xa6
	bl BgConfig_LoadAssetFromOpenNarc
	mov r0, #5
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5]
	add r2, r4, #0
	mov r3, #0xa6
	bl BgConfig_LoadAssetFromOpenNarc
	mov r1, #0
	str r1, [sp]
	mov r0, #7
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, #0xd
	str r1, [sp, #0x10]
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5]
	add r2, r4, #0
	mov r3, #0xa6
	bl BgConfig_LoadAssetFromOpenNarc
	mov r0, #0xa
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5]
	add r2, r4, #0
	mov r3, #0xa6
	bl BgConfig_LoadAssetFromOpenNarc
	mov r0, #7
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5]
	add r2, r4, #0
	mov r3, #0xa6
	bl BgConfig_LoadAssetFromOpenNarc
	mov r0, #4
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5]
	add r2, r4, #0
	mov r3, #0xa6
	bl BgConfig_LoadAssetFromOpenNarc
	ldr r0, _021E6F4C ; =0x000184E3
	ldrb r0, [r5, r0]
	cmp r0, #0
	bne _021E6EA4
	mov r0, #1
	b _021E6EA6
_021E6EA4:
	mov r0, #0
_021E6EA6:
	add r0, r0, #2
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5]
	add r2, r4, #0
	mov r3, #0xa6
	bl BgConfig_LoadAssetFromOpenNarc
	ldr r0, [r5]
	ldr r3, _021E6F50 ; =0x000004D8
	str r0, [sp]
	add r0, r4, #0
	mov r1, #8
	mov r2, #0
	add r3, r5, r3
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	mov r3, #0x4d
	lsl r3, r3, #4
	str r0, [r5, r3]
	ldr r0, [r5]
	add r3, r3, #4
	str r0, [sp]
	add r0, r4, #0
	mov r1, #9
	mov r2, #0
	add r3, r5, r3
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	ldr r1, _021E6F54 ; =0x000004CC
	str r0, [r5, r1]
	add r0, r4, #0
	bl NARC_Delete
	add r0, r5, #0
	bl ov108_021E7ADC
	add r0, r5, #0
	mov r1, #0xff
	mov r2, #0
	bl ov108_021E7BB4
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #7
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x14
	pop {r4, r5, pc}
	.balign 4, 0
_021E6F4C: .word 0x000184E3
_021E6F50: .word 0x000004D8
_021E6F54: .word 0x000004CC
	thumb_func_end ov108_021E6D80

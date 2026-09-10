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

	thumb_func_start ov108_021E78F4
ov108_021E78F4: ; 0x021E78F4
	push {r3, r4, r5, r6, r7, lr}
	add r7, r2, #0
	add r5, r0, #0
	add r4, r1, #0
	mov r6, #0
	cmp r7, #6
	blo _021E790C
	mov r0, #0xe0
	str r0, [sp]
	mov r2, #0xb4
	mov r6, #1
	b _021E7984
_021E790C:
	cmp r4, #1
	beq _021E795E
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x48
	mul r0, r1
	add r0, #0x38
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp]
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	mov r1, #0x48
	mul r1, r0
	add r1, #0x38
	lsl r0, r1, #0x10
	asr r2, r0, #0x10
	cmp r4, #2
	bne _021E7942
	add r2, #0xc0
	lsl r0, r2, #0x10
	asr r2, r0, #0x10
	b _021E7984
_021E7942:
	cmp r4, #3
	bne _021E794A
	mov r6, #2
	b _021E7984
_021E794A:
	cmp r4, #0
	bne _021E7984
	ldr r0, _021E79A4 ; =0x000184E2
	ldrb r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1b
	cmp r0, #2
	bne _021E7984
	mov r6, #3
	b _021E7984
_021E795E:
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0x50
	mul r0, r1
	add r0, #0x30
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp]
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	mov r1, #0x48
	mul r1, r0
	add r1, #0x38
	lsl r0, r1, #0x10
	asr r2, r0, #0x10
_021E7984:
	lsl r0, r4, #2
	add r1, r5, r0
	mov r0, #0xd5
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r1, [sp]
	bl Sprite_SetPositionXY
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	mov r3, #1
	bl ov108_021E78C0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E79A4: .word 0x000184E2
	thumb_func_end ov108_021E78F4


	thumb_func_start ov108_021E79A8
ov108_021E79A8: ; 0x021E79A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	add r4, r1, #0
	add r7, r2, #0
	cmp r3, #0
	bne _021E79D0
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl BgClearTilemapBufferAndCommit
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
_021E79D0:
	ldr r0, _021E7AD4 ; =0x000004D4
	mov r2, #0x20
	ldr r0, [r5, r0]
	mov r6, #0x18
	str r2, [sp]
	add r2, r0, #0
	str r6, [sp, #4]
	add r2, #0xc
	str r2, [sp, #8]
	mov r3, #0
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	ldrh r2, [r0]
	lsl r2, r2, #0x15
	lsr r2, r2, #0x18
	str r2, [sp, #0x14]
	ldrh r0, [r0, #2]
	add r2, r3, #0
	ldr r3, _021E7AD8 ; =0x000184E2
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldrb r3, [r5, r3]
	mov r0, #0xd
	lsl r0, r0, #6
	lsl r3, r3, #0x18
	lsr r3, r3, #0x1b
	mul r6, r3
	lsl r3, r6, #0x18
	ldr r0, [r5, r0]
	lsr r3, r3, #0x18
	bl CopyToBgTilemapRect
	ldr r0, _021E7AD8 ; =0x000184E2
	ldrb r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1b
	bne _021E7A80
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #3
	add r0, r1, r0
	add r0, r0, #3
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x1c]
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, r0, r1
	add r0, r0, #3
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r4, #4
	bne _021E7AA6
	ldr r0, _021E7AD4 ; =0x000004D4
	mov r1, #0x20
	ldr r0, [r5, r0]
	mov r2, #0
	str r1, [sp]
	mov r1, #3
	str r1, [sp, #4]
	add r1, r0, #0
	add r1, #0xc
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	mov r1, #0x18
	str r1, [sp, #0x10]
	ldrh r1, [r0]
	mov r3, #0x15
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	add r1, r4, #0
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl CopyToBgTilemapRect
	b _021E7AA6
_021E7A80:
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	mov r0, #0xa
	mul r0, r1
	add r0, r0, #2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x1c]
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, r0, r1
	add r0, #0x1b
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
_021E7AA6:
	str r6, [sp]
	mov r0, #8
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x11
	str r0, [sp, #0xc]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r3, [sp, #0x1c]
	add r1, r4, #0
	mov r2, #0
	bl FillBgTilemapRect
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7AD4: .word 0x000004D4
_021E7AD8: .word 0x000184E2
	thumb_func_end ov108_021E79A8


	thumb_func_start ov108_021E7ADC
ov108_021E7ADC: ; 0x021E7ADC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	str r0, [sp, #0x10]
	mov r0, #0
	mov r5, #1
	str r0, [sp, #0x1c]
_021E7AE8:
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	mov r1, #3
	bl _s32_div_f
	lsl r1, r0, #3
	add r0, r0, r1
	add r0, r0, #3
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x1c]
	mov r1, #3
	bl _s32_div_f
	lsl r0, r1, #3
	add r0, r1, r0
	add r0, r0, #3
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
_021E7B12:
	ldr r0, [sp, #0x14]
	mov r4, #0
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
_021E7B1A:
	str r6, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x11
	lsl r2, r5, #0x10
	str r0, [sp, #0xc]
	mov r0, #0xd
	add r3, r7, r4
	lsl r3, r3, #0x18
	ldr r1, [sp, #0x10]
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	mov r1, #5
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	add r5, r5, #1
	bl FillBgTilemapRect
	add r4, r4, #1
	cmp r4, #8
	blt _021E7B1A
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #8
	blt _021E7B12
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #6
	blt _021E7AE8
	mov r1, #0xd
	ldr r0, [sp, #0x10]
	lsl r1, r1, #6
	ldr r0, [r0, r1]
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov108_021E7ADC


	thumb_func_start ov108_021E7B74
ov108_021E7B74: ; 0x021E7B74
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5]
	add r3, #0x12
	add r4, r2, #0
	str r0, [sp]
	add r0, r1, #0
	add r1, r3, #0
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetCharDataFromOpenNarc
	add r6, r0, #0
	lsl r0, r4, #6
	add r0, r0, #1
	str r0, [sp]
	mov r0, #0xd
	ldr r2, [sp, #4]
	lsl r0, r0, #6
	mov r3, #1
	ldr r0, [r5, r0]
	ldr r2, [r2, #0x14]
	mov r1, #5
	lsl r3, r3, #0xc
	bl BG_LoadCharTilesData
	add r0, r6, #0
	bl Heap_Free
	add sp, #8
	pop {r4, r5, r6, pc}
	thumb_func_end ov108_021E7B74


	thumb_func_start ov108_021E7BB4
ov108_021E7BB4: ; 0x021E7BB4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r4, r1, #0
	ldr r1, [r6]
	mov r0, #0xa6
	add r5, r2, #0
	bl NARC_New
	add r7, r0, #0
	cmp r4, #6
	blo _021E7BE6
	mov r4, #0
	add r5, r6, #0
_021E7BCE:
	ldrb r3, [r5, #0x1c]
	lsl r2, r4, #0x18
	add r0, r6, #0
	add r1, r7, #0
	lsr r2, r2, #0x18
	bl ov108_021E7B74
	add r4, r4, #1
	add r5, #0x7a
	cmp r4, #6
	blt _021E7BCE
	b _021E7BF2
_021E7BE6:
	add r0, r6, #0
	add r1, r7, #0
	add r2, r4, #0
	add r3, r5, #0
	bl ov108_021E7B74
_021E7BF2:
	add r0, r7, #0
	bl NARC_Delete
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov108_021E7BB4

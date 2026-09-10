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

	thumb_func_start ov108_021E733C
ov108_021E733C: ; 0x021E733C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	mov r4, #0
	add r7, r5, #0
	add r6, r5, #0
_021E7348:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	str r1, [sp, #0x10]
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r3, r0, #0
	mov r0, #0x80
	str r0, [sp]
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldrb r0, [r7, #0x1c]
	ldr r2, [sp, #0x10]
	mov r1, #0x48
	mul r1, r2
	str r0, [sp, #8]
	mov r0, #1
	mov r2, #0x48
	mul r2, r3
	str r0, [sp, #0xc]
	mov r0, #0xd2
	lsl r0, r0, #2
	add r1, #0x38
	add r2, #0x38
	lsl r1, r1, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r5, r0]
	lsr r1, r1, #0x10
	lsr r2, r2, #0x10
	mov r3, #2
	bl ov108_021E8540
	mov r1, #0xdb
	lsl r1, r1, #2
	str r0, [r6, r1]
	add r4, r4, #1
	add r7, #0x7a
	add r6, r6, #4
	cmp r4, #6
	blt _021E7348
	mov r4, #0
	add r6, r5, #0
_021E73A4:
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r7, r1, #0
	add r0, r4, #0
	mov r1, #3
	bl _s32_div_f
	add r2, r0, #0
	mov r0, #0x80
	str r0, [sp]
	add r0, r4, #6
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, _021E74FC ; =0x000184DE
	mov r3, #0x48
	ldrb r1, [r5, r0]
	mov r0, #6
	mul r3, r2
	mul r0, r1
	add r0, r4, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #1
	mov r1, #0x50
	str r0, [sp, #0xc]
	mov r0, #0xd2
	mul r1, r7
	lsl r0, r0, #2
	add r1, #0x30
	add r3, #0x38
	lsl r2, r3, #0x10
	lsl r1, r1, #0x10
	ldr r0, [r5, r0]
	lsr r1, r1, #0x10
	lsr r2, r2, #0x10
	mov r3, #3
	bl ov108_021E8540
	mov r1, #0xe1
	lsl r1, r1, #2
	str r0, [r6, r1]
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #6
	blt _021E73A4
	sub r1, #0x38
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r2, _021E7500 ; =ov108_021EA7F8
	bl SpriteSystem_CreateSpriteFromResourceHeader
	mov r1, #0xd5
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	sub r0, #8
	sub r1, r1, #4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, _021E7500 ; =ov108_021EA7F8
	bl SpriteSystem_CreateSpriteFromResourceHeader
	mov r1, #0xd6
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	sub r0, #0xc
	sub r1, #8
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, _021E7500 ; =ov108_021EA7F8
	bl SpriteSystem_CreateSpriteFromResourceHeader
	mov r1, #0x36
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	sub r0, #0x14
	sub r1, #0x10
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, _021E7504 ; =ov108_021EA820
	bl SpriteSystem_CreateSpriteFromResourceHeader
	mov r1, #0xd7
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	sub r0, #0x10
	sub r1, #0xc
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, _021E7508 ; =ov108_021EA848
	bl SpriteSystem_CreateSpriteFromResourceHeader
	mov r1, #0xd9
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	sub r0, #0x18
	sub r1, #0x14
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, _021E750C ; =ov108_021EA870
	bl SpriteSystem_CreateSpriteFromResourceHeader
	mov r1, #0xda
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0x10
	ldr r0, [r5, r1]
	mov r1, #3
	bl thunk_Sprite_SetPriority
	mov r0, #0xd9
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl thunk_Sprite_SetPriority
	mov r0, #0xda
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl thunk_Sprite_SetPriority
	mov r0, #0x36
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl thunk_Sprite_SetPriority
	mov r0, #0x36
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #5
	bl thunk_Sprite_SetDrawPriority
	mov r0, #0xd5
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl thunk_Sprite_SetDrawFlag
	mov r0, #0xd6
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl thunk_Sprite_SetDrawFlag
	mov r0, #0x36
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl thunk_Sprite_SetDrawFlag
	mov r0, #0xd7
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl thunk_Sprite_SetDrawFlag
	add r0, r5, #0
	bl ov108_021E756C
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E74FC: .word 0x000184DE
_021E7500: .word ov108_021EA7F8
_021E7504: .word ov108_021EA820
_021E7508: .word ov108_021EA848
_021E750C: .word ov108_021EA870
	thumb_func_end ov108_021E733C

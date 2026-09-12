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

	thumb_func_start ov108_021E8270
ov108_021E8270: ; 0x021E8270
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r0, _021E82D8 ; =0x000184E2
	ldrb r0, [r7, r0]
	lsl r0, r0, #0x1e
	lsr r0, r0, #0x1f
	bne _021E8284
	mov r0, #0x1f
	mvn r0, r0
	b _021E8286
_021E8284:
	mov r0, #0x20
_021E8286:
	lsl r0, r0, #0x10
	mov r4, #0
	add r5, r7, #0
	asr r6, r0, #0x10
_021E828E:
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	mov r2, #0
	bl ManagedSprite_OffsetPositionXY
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0xc
	blt _021E828E
	ldr r2, _021E82DC ; =0x000184E1
	ldrb r0, [r7, r2]
	add r0, r0, #1
	strb r0, [r7, r2]
	ldrb r0, [r7, r2]
	cmp r0, #8
	blo _021E82D2
	mov r0, #0
	strb r0, [r7, r2]
	sub r2, r2, #1
	ldrb r2, [r7, r2]
	add r0, r7, #0
	mov r1, #1
	bl ov108_021E78F4
	add r0, r7, #0
	bl ov108_021E7EB0
	add r0, r7, #0
	bl ov108_021E77D4
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E82D2:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E82D8: .word 0x000184E2
_021E82DC: .word 0x000184E1
	thumb_func_end ov108_021E8270


	thumb_func_start ov108_021E82E0
ov108_021E82E0: ; 0x021E82E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r1, [sp]
	ldr r1, _021E837C ; =0x000184E2
	add r6, r0, #0
	ldrb r0, [r6, r1]
	add r3, sp, #8
	lsl r0, r0, #0x1d
	lsr r2, r0, #0x1f
	mov r0, #6
	mul r0, r2
	sub r2, r1, #3
	ldrb r2, [r6, r2]
	add r2, r2, r0
	strb r2, [r3, #2]
	sub r2, r1, #2
	ldrb r2, [r6, r2]
	add r0, r2, r0
	strb r0, [r3, #3]
	sub r0, r1, #3
	ldrb r0, [r6, r0]
	mov r1, #3
	bl _s32_div_f
	add r1, sp, #8
	strb r0, [r1]
	ldr r0, _021E8380 ; =0x000184E0
	mov r1, #3
	ldrb r0, [r6, r0]
	bl _s32_div_f
	add r1, sp, #8
	strb r0, [r1, #1]
	ldr r0, [sp]
	add r5, sp, #8
	ldr r1, _021E8384 ; =_021EA720
	lsl r0, r0, #1
	add r0, r1, r0
	mov r7, #0
	add r4, sp, #8
	add r5, #2
	str r0, [sp, #4]
_021E8334:
	ldrb r3, [r4]
	ldrb r0, [r5]
	ldr r2, [sp, #4]
	ldrsb r3, [r2, r3]
	lsl r0, r0, #2
	add r1, r6, r0
	mov r0, #0xdb
	mov r2, #0xc
	lsl r0, r0, #2
	mul r2, r3
	ldr r0, [r1, r0]
	lsl r2, r2, #0x10
	mov r1, #0
	asr r2, r2, #0x10
	bl ManagedSprite_OffsetPositionXY
	add r7, r7, #1
	add r4, r4, #1
	add r5, r5, #1
	cmp r7, #2
	blt _021E8334
	ldr r0, _021E8388 ; =0x000184E1
	ldrb r1, [r6, r0]
	add r1, r1, #1
	strb r1, [r6, r0]
	ldrb r1, [r6, r0]
	cmp r1, #8
	blo _021E8376
	mov r1, #0
	strb r1, [r6, r0]
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_021E8376:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E837C: .word 0x000184E2
_021E8380: .word 0x000184E0
_021E8384: .word _021EA720
_021E8388: .word 0x000184E1
	thumb_func_end ov108_021E82E0

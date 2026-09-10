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

	thumb_func_start ov108_021E5DB8
ov108_021E5DB8: ; 0x021E5DB8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _021E5E5C ; =0x000004BC
	ldr r0, [r5, r0]
	bl TouchscreenListMenu_HandleInput
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	bne _021E5DD2
	mov r0, #1
	pop {r4, r5, r6, pc}
_021E5DD2:
	ldr r0, _021E5E5C ; =0x000004BC
	ldr r0, [r5, r0]
	add r1, r0, #0
	add r1, #0x27
	ldrb r1, [r1]
	lsl r1, r1, #0x18
	lsr r4, r1, #0x19
	bl TouchscreenListMenu_Destroy
	ldr r0, [r5, #0x10]
	cmp r4, r0
	beq _021E5DFC
	cmp r4, #0
	bne _021E5DF6
	add r0, r5, #0
	bl ov108_021E61E8
	b _021E5DFC
_021E5DF6:
	add r0, r5, #0
	bl ov108_021E6238
_021E5DFC:
	str r4, [r5, #0x10]
	cmp r6, #0
	beq _021E5E0A
	cmp r6, #1
	beq _021E5E14
	cmp r6, #2
	b _021E5E40
_021E5E0A:
	ldr r0, _021E5E60 ; =0x000184E0
	mov r1, #0
	strb r1, [r5, r0]
	mov r0, #2
	pop {r4, r5, r6, pc}
_021E5E14:
	mov r2, #0
	add r0, r5, #0
	mov r1, #1
	add r3, r2, #0
	bl ov108_021E79A8
	mov r2, #0
	add r0, r5, #0
	mov r1, #4
	add r3, r2, #0
	bl ov108_021E79A8
	ldr r0, _021E5E64 ; =0x000184DF
	ldrb r1, [r5, r0]
	add r0, r0, #1
	strb r1, [r5, r0]
	add r0, r5, #0
	bl ov108_021E6804
	mov r0, #4
	str r0, [r5, #0xc]
	pop {r4, r5, r6, pc}
_021E5E40:
	mov r2, #0
	add r0, r5, #0
	mov r1, #1
	add r3, r2, #0
	bl ov108_021E79A8
	mov r2, #0
	add r0, r5, #0
	mov r1, #4
	add r3, r2, #0
	bl ov108_021E79A8
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E5E5C: .word 0x000004BC
_021E5E60: .word 0x000184E0
_021E5E64: .word 0x000184DF
	thumb_func_end ov108_021E5DB8


	thumb_func_start ov108_021E5E68
ov108_021E5E68: ; 0x021E5E68
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _021E5E78
	cmp r1, #1
	beq _021E5E84
	b _021E5E94
_021E5E78:
	bl ov108_021E7F7C
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _021E5EF6
_021E5E84:
	bl ov108_021E80F4
	cmp r0, #0
	beq _021E5EF6
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _021E5EF6
_021E5E94:
	ldr r3, _021E5EFC ; =0x04001000
	ldr r1, _021E5F00 ; =0xFFFF1FFF
	ldr r2, [r3]
	and r1, r2
	str r1, [r3]
	ldr r2, _021E5F04 ; =0x000184E1
	mov r1, #0
	strb r1, [r4, r2]
	str r1, [r4, #8]
	add r2, r2, #1
	ldrb r2, [r4, r2]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x1b
	bne _021E5ED2
	mov r2, #3
	str r2, [r4, #0xc]
	mov r2, #1
	add r3, r2, #0
	bl ov108_021E7700
	add r0, r4, #0
	bl ov108_021E7EB0
	ldr r1, _021E5F08 ; =0x000184E2
	mov r0, #0xf8
	ldrb r2, [r4, r1]
	bic r2, r0
	mov r0, #8
	orr r0, r2
	strb r0, [r4, r1]
	b _021E5EF2
_021E5ED2:
	mov r2, #2
	str r2, [r4, #0xc]
	add r2, r1, #0
	mov r3, #1
	bl ov108_021E7700
	ldr r1, _021E5F0C ; =0x000184DF
	add r0, r4, #0
	ldrb r1, [r4, r1]
	bl ov108_021E7CD8
	ldr r1, _021E5F08 ; =0x000184E2
	mov r0, #0xf8
	ldrb r2, [r4, r1]
	bic r2, r0
	strb r2, [r4, r1]
_021E5EF2:
	mov r0, #4
	pop {r4, pc}
_021E5EF6:
	mov r0, #2
	pop {r4, pc}
	nop
_021E5EFC: .word 0x04001000
_021E5F00: .word 0xFFFF1FFF
_021E5F04: .word 0x000184E1
_021E5F08: .word 0x000184E2
_021E5F0C: .word 0x000184DF
	thumb_func_end ov108_021E5E68

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

	thumb_func_start ov108_021E5F38
ov108_021E5F38: ; 0x021E5F38
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #0x13
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _021E5F50
	cmp r0, #2
	beq _021E5F88
	b _021E5F9E
_021E5F50:
	ldr r1, _021E6008 ; =0x000184E0
	mov r4, #1
	sub r2, r1, #2
	ldrb r3, [r5, r2]
	ldrb r0, [r5, r1]
	mov r2, #6
	mul r2, r3
	add r0, r0, r2
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	sub r0, r1, #1
	ldrb r3, [r5, r0]
	mov r0, #0x7a
	mul r0, r3
	add r0, r5, r0
	ldrb r0, [r0, #0x1c]
	cmp r2, r0
	beq _021E5FA2
	add r0, r1, #0
	add r0, #8
	str r4, [r5, r0]
	sub r1, r1, #1
	add r0, r5, #0
	ldrb r1, [r5, r1]
	add r0, #0x1c
	bl SafariZone_InitAreaInSet
	b _021E5FA2
_021E5F88:
	ldr r0, _021E600C ; =0x000184DF
	mov r2, #0x7a
	ldrb r1, [r5, r0]
	add r0, r5, #0
	mul r2, r1
	add r2, r5, r2
	ldrb r2, [r2, #0x1c]
	bl ov108_021E7BB4
	mov r4, #0
	b _021E5FA2
_021E5F9E:
	mov r0, #1
	pop {r4, r5, r6, pc}
_021E5FA2:
	mov r0, #0x13
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl YesNoPrompt_IsInTouchMode
	add r6, r0, #0
	ldr r0, [r5, #0x10]
	cmp r6, r0
	beq _021E5FC6
	cmp r6, #0
	bne _021E5FC0
	add r0, r5, #0
	bl ov108_021E61E8
	b _021E5FC6
_021E5FC0:
	add r0, r5, #0
	bl ov108_021E6238
_021E5FC6:
	mov r0, #0x13
	str r6, [r5, #0x10]
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl YesNoPrompt_Reset
	mov r0, #0xf1
	lsl r0, r0, #2
	add r0, r5, r0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	mov r1, #0
	bl ov108_021E767C
	mov r2, #1
	add r0, r5, #0
	mov r1, #0
	add r3, r2, #0
	bl ov108_021E7700
	mov r2, #0
	add r0, r5, #0
	mov r1, #1
	add r3, r2, #0
	bl ov108_021E79A8
	cmp r4, #0
	beq _021E6004
	mov r0, #2
	pop {r4, r5, r6, pc}
_021E6004:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E6008: .word 0x000184E0
_021E600C: .word 0x000184DF
	thumb_func_end ov108_021E5F38

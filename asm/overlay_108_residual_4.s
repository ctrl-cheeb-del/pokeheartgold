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

	thumb_func_start ov108_021E6090
ov108_021E6090: ; 0x021E6090
	push {r3, r4, r5, lr}
	ldr r2, _021E61D8 ; =0x000184E2
	add r5, r0, #0
	ldrb r1, [r5, r2]
	lsl r1, r1, #0x1d
	lsr r3, r1, #0x1f
	mov r1, #6
	add r4, r3, #0
	mul r4, r1
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _021E60B2
	cmp r1, #1
	beq _021E60EE
	cmp r1, #2
	beq _021E6174
	b _021E61BA
_021E60B2:
	sub r0, r2, #3
	ldrb r0, [r5, r0]
	add r0, r0, r4
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetPriority
	ldr r0, _021E61DC ; =0x000184E0
	ldrb r0, [r5, r0]
	add r0, r0, r4
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetPriority
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _021E61D2
_021E60EE:
	mov r1, #0
	bl ov108_021E82E0
	cmp r0, #0
	beq _021E61D2
	ldr r2, _021E61E0 ; =0x000184E8
	mov r0, #1
	add r1, r2, #0
	str r0, [r5, r2]
	sub r1, #9
	sub r2, #8
	add r0, r5, #0
	ldrb r1, [r5, r1]
	ldrb r2, [r5, r2]
	add r0, #0x1c
	bl SafariZone_SwapAreasInSet
	ldr r0, _021E61E4 ; =0x000184DF
	mov r3, #0x7a
	ldrb r2, [r5, r0]
	mov r0, #0xd2
	lsl r0, r0, #2
	add r1, r2, r4
	mul r3, r2
	add r2, r5, r3
	lsl r1, r1, #0x18
	ldrb r2, [r2, #0x1c]
	ldr r0, [r5, r0]
	lsr r1, r1, #0x18
	bl ov108_021E84F8
	ldr r0, _021E61E4 ; =0x000184DF
	mov r2, #0x7a
	ldrb r1, [r5, r0]
	add r0, r5, #0
	mul r2, r1
	add r2, r5, r2
	ldrb r2, [r2, #0x1c]
	bl ov108_021E7BB4
	ldr r0, _021E61DC ; =0x000184E0
	mov r3, #0x7a
	ldrb r2, [r5, r0]
	mov r0, #0xd2
	lsl r0, r0, #2
	add r1, r2, r4
	mul r3, r2
	add r2, r5, r3
	lsl r1, r1, #0x18
	ldrb r2, [r2, #0x1c]
	ldr r0, [r5, r0]
	lsr r1, r1, #0x18
	bl ov108_021E84F8
	ldr r0, _021E61DC ; =0x000184E0
	mov r2, #0x7a
	ldrb r1, [r5, r0]
	add r0, r5, #0
	mul r2, r1
	add r2, r5, r2
	ldrb r2, [r2, #0x1c]
	bl ov108_021E7BB4
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _021E61D2
_021E6174:
	mov r1, #1
	bl ov108_021E82E0
	cmp r0, #0
	beq _021E61D2
	ldr r0, _021E61E4 ; =0x000184DF
	ldrb r0, [r5, r0]
	add r0, r0, r4
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #2
	bl ManagedSprite_SetPriority
	ldr r0, _021E61DC ; =0x000184E0
	ldrb r0, [r5, r0]
	add r0, r0, r4
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0xdb
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #2
	bl ManagedSprite_SetPriority
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _021E61D2
_021E61BA:
	sub r1, r2, #2
	ldrb r3, [r5, r1]
	sub r1, r2, #3
	strb r3, [r5, r1]
	bl ov108_021E6850
	mov r0, #0
	str r0, [r5, #8]
	mov r0, #2
	str r0, [r5, #0xc]
	mov r0, #4
	pop {r3, r4, r5, pc}
_021E61D2:
	mov r0, #3
	pop {r3, r4, r5, pc}
	nop
_021E61D8: .word 0x000184E2
_021E61DC: .word 0x000184E0
_021E61E0: .word 0x000184E8
_021E61E4: .word 0x000184DF
	thumb_func_end ov108_021E6090

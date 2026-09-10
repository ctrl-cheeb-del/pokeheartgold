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

	thumb_func_start ov108_021E7224
ov108_021E7224: ; 0x021E7224
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4]
	mov r0, #3
	bl ListMenuItems_New
	ldr r1, _021E729C ; =0x000004B4
	str r0, [r4, r1]
	ldr r1, [r4]
	mov r0, #2
	bl ListMenuItems_New
	ldr r1, _021E72A0 ; =0x000004B8
	mov r2, #7
	str r0, [r4, r1]
	sub r0, r1, #4
	mov r1, #0xc1
	lsl r1, r1, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	mov r3, #0
	bl ListMenuItems_AppendFromMsgData
	ldr r0, _021E729C ; =0x000004B4
	mov r1, #0xc1
	lsl r1, r1, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	mov r2, #8
	mov r3, #1
	bl ListMenuItems_AppendFromMsgData
	ldr r0, _021E729C ; =0x000004B4
	mov r1, #0xc1
	lsl r1, r1, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	mov r2, #6
	mov r3, #2
	bl ListMenuItems_AppendFromMsgData
	ldr r0, _021E72A0 ; =0x000004B8
	mov r1, #0xc1
	lsl r1, r1, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	mov r2, #5
	mov r3, #0
	bl ListMenuItems_AppendFromMsgData
	ldr r0, _021E72A0 ; =0x000004B8
	mov r1, #0xc1
	lsl r1, r1, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	mov r2, #6
	mov r3, #1
	bl ListMenuItems_AppendFromMsgData
	pop {r4, pc}
	.balign 4, 0
_021E729C: .word 0x000004B4
_021E72A0: .word 0x000004B8
	thumb_func_end ov108_021E7224

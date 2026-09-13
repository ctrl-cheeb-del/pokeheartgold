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

	thumb_func_start ov108_021E6A58
ov108_021E6A58: ; 0x021E6A58
	push {r4, r5, lr}
	sub sp, #0x24
	add r4, r0, #0
	add r0, sp, #0xc
	mov r1, #0
	mov r2, #0x18
	bl MI_CpuFill8
	ldr r0, _021E6AE8 ; =_021EA720
	add r2, sp, #0xc
	ldrh r3, [r0, #0xc]
	ldr r5, _021E6AEC ; =ov108_021EA748
	add r1, sp, #0xc
	strh r3, [r2]
	ldrh r3, [r0, #0xe]
	strh r3, [r2, #2]
	ldrh r3, [r0, #0x10]
	strh r3, [r2, #4]
	ldrh r3, [r0, #0x12]
	strh r3, [r2, #6]
	ldrh r3, [r0, #0x14]
	ldrh r0, [r0, #0x16]
	strh r3, [r2, #8]
	strh r0, [r2, #0xa]
	ldr r0, _021E6AF0 ; =0x000004B4
	ldr r0, [r4, r0]
	str r0, [sp, #0x18]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r3, [r4, r0]
	add r0, r0, #4
	str r3, [sp, #0x1c]
	mov r3, #3
	strb r3, [r2, #0x14]
	ldr r2, _021E6AF4 ; =0x000184DF
	ldrb r2, [r4, r2]
	lsl r3, r2, #2
	ldr r2, _021E6AF8 ; =ov108_021EA74A
	ldrh r2, [r2, r3]
	ldrh r3, [r5, r3]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	str r2, [sp]
	mov r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	ldr r2, [r4, #0x10]
	lsl r3, r3, #0x18
	lsl r2, r2, #0x18
	ldr r0, [r4, r0]
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl TouchscreenListMenu_Create
	ldr r1, _021E6AFC ; =0x000004BC
	ldr r2, _021E6AF4 ; =0x000184DF
	str r0, [r4, r1]
	mov r1, #1
	ldrb r2, [r4, r2]
	add r0, r4, #0
	add r3, r1, #0
	bl ov108_021E79A8
	ldr r2, _021E6AF4 ; =0x000184DF
	add r0, r4, #0
	ldrb r2, [r4, r2]
	mov r1, #4
	mov r3, #1
	bl ov108_021E79A8
	add sp, #0x24
	pop {r4, r5, pc}
	.balign 4, 0
_021E6AE8: .word _021EA720
_021E6AEC: .word ov108_021EA748
_021E6AF0: .word 0x000004B4
_021E6AF4: .word 0x000184DF
_021E6AF8: .word ov108_021EA74A
_021E6AFC: .word 0x000004BC
	thumb_func_end ov108_021E6A58

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

	thumb_func_start ov108_021E6F74
ov108_021E6F74: ; 0x021E6F74
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #4
	bl FontID_Alloc
	ldr r2, _021E7010 ; =0x000001AD
	ldr r3, [r5]
	mov r0, #0
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	mov r1, #0xc1
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r2, [r5]
	mov r0, #1
	mov r1, #0x11
	bl MessageFormat_New_Custom
	mov r1, #0xc2
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r1, [r5]
	mov r0, #0x51
	bl String_New
	mov r1, #0xc3
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #8
	ldr r0, [r5, r1]
	mov r1, #9
	bl NewString_ReadMsgData
	mov r1, #0xcd
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0x30
	ldr r0, [r5, r1]
	mov r1, #0xf
	bl NewString_ReadMsgData
	mov r1, #0xce
	lsl r1, r1, #2
	add r7, r1, #0
	str r0, [r5, r1]
	mov r4, #0
	add r6, r5, #0
	sub r7, #0x28
_021E6FD8:
	mov r0, #0xc1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #4
	bl NewString_ReadMsgData
	str r0, [r6, r7]
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #5
	blt _021E6FD8
	mov r7, #0xc9
	mov r4, #0
	add r6, r5, #0
	lsl r7, r7, #2
_021E6FF6:
	mov r0, #0xc1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl NewString_ReadMsgData
	str r0, [r6, r7]
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #4
	blt _021E6FF6
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7010: .word 0x000001AD
	thumb_func_end ov108_021E6F74


	thumb_func_start ov108_021E7014
ov108_021E7014: ; 0x021E7014
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r7, #0xc9
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_021E7020:
	ldr r0, [r5, r7]
	bl String_Delete
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _021E7020
	mov r7, #0x31
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #4
_021E7036:
	ldr r0, [r4, r7]
	bl String_Delete
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #5
	blt _021E7036
	mov r0, #0xce
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl String_Delete
	mov r0, #0xcd
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl String_Delete
	mov r0, #0xc3
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl String_Delete
	mov r0, #0xc2
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl MessageFormat_Delete
	mov r0, #0xc1
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl DestroyMsgData
	mov r0, #4
	bl FontID_Release
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov108_021E7014


	thumb_func_start ov108_021E7080
ov108_021E7080: ; 0x021E7080
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r7, r0, #0
	mov r0, #0xed
	lsl r0, r0, #2
	ldr r4, _021E71D8 ; =ov108_021EA7A8
	mov r6, #0
	add r5, r7, r0
_021E7090:
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r7, r0]
	add r1, r5, #0
	add r2, r4, #0
	bl AddWindow
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r6, r6, #1
	add r4, #8
	add r5, #0x10
	cmp r6, #4
	ble _021E7090
	mov r0, #5
	str r0, [sp, #0x24]
	mov r0, #1
	ldr r4, _021E71DC ; =0x000003A6
	str r0, [sp, #0x20]
	add r0, r4, #0
	add r0, #0xe
	mov r5, #0
	add r6, r7, r0
_021E70C2:
	ldr r0, [sp, #0x20]
	mov r2, #7
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x28]
	asr r0, r5, #1
	lsr r0, r0, #0x1e
	add r0, r5, r0
	asr r1, r0, #2
	mov r0, #1
	eor r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	lsl r0, r0, #1
	add r0, r0, #2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov r1, #0x16
	mul r1, r0
	str r1, [sp, #0x1c]
	sub r4, r4, r1
	ldr r1, [sp, #0x24]
	mov r3, #1
	lsl r1, r1, #4
	str r1, [sp, #0x2c]
	ldr r1, [sp, #0x28]
	str r1, [sp]
	mov r1, #0x16
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #5
	str r0, [sp, #0xc]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r1, [sp, #0x2c]
	ldr r0, [r7, r0]
	add r1, r6, r1
	bl AddWindowParameterized
	lsr r2, r5, #0x1f
	lsl r1, r5, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	lsl r1, r0, #2
	ldr r0, _021E71E0 ; =ov108_021EA724
	ldr r0, [r0, r1]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x14]
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x2c]
	lsl r1, r1, #0x18
	add r0, r6, r0
	lsr r1, r1, #0x18
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x28]
	sub r4, r4, r0
	ldr r0, [sp, #0x24]
	mov r2, #7
	add r0, r0, #1
	lsl r0, r0, #4
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x18]
	mov r3, #0x1a
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #5
	str r0, [sp, #0xc]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r1, [sp, #0x30]
	ldr r0, [r7, r0]
	add r1, r6, r1
	bl AddWindowParameterized
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x30]
	lsl r1, r1, #0x18
	add r0, r6, r0
	lsr r1, r1, #0x18
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x24]
	add r5, r5, #1
	add r0, r0, #2
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x20]
	sub r4, #0xa
	add r0, r0, #4
	str r0, [sp, #0x20]
	cmp r5, #5
	blt _021E70C2
	ldr r0, _021E71E4 ; =0x000004A4
	add r0, r7, r0
	bl InitWindow
	ldr r1, _021E71E8 ; =0x000002E1
	mov r0, #0
	str r1, [sp]
	add r1, #0x5f
	str r0, [sp, #4]
	ldr r0, [r7, r1]
	ldr r1, _021E71E4 ; =0x000004A4
	mov r2, #6
	add r1, r7, r1
	mov r3, #2
	bl AddTextWindowTopLeftCorner
	ldr r0, _021E71E4 ; =0x000004A4
	mov r1, #0
	add r0, r7, r0
	bl FillWindowPixelBufferText_AssumeTileSize32
	ldr r0, [r7]
	bl YesNoPrompt_Create
	mov r1, #0x13
	lsl r1, r1, #6
	str r0, [r7, r1]
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	nop
_021E71D8: .word ov108_021EA7A8
_021E71DC: .word 0x000003A6
_021E71E0: .word ov108_021EA724
_021E71E4: .word 0x000004A4
_021E71E8: .word 0x000002E1
	thumb_func_end ov108_021E7080

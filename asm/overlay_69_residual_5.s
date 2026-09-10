	.include "asm/macros.inc"
	.public GeonetGlobe_Init
	.public GeonetGlobe_Main
	.public GeonetGlobe_Exit
	.public ov69_021E60F8
	.public ov69_021E6118
	.public ov69_021E6138
	.public ov69_021E623C
	.public ov69_021E62B0
	.public ov69_021E6300
	.public ov69_021E6308
	.public ov69_021E645C
	.public ov69_021E64CC
	.public ov69_021E67B8
	.public ov69_021E6810
	.public ov69_021E68D8
	.public ov69_021E68EC
	.public ov69_021E6994
	.public ov69_021E6A54
	.public ov69_021E6A8C
	.public ov69_021E6B5C
	.public ov69_021E6C14
	.public ov69_021E6C30
	.public ov69_021E6D5C
	.public ov69_021E6E88
	.public ov69_021E6F48
	.public ov69_021E6F8C
	.public ov69_021E6FE8
	.public ov69_021E706C
	.public ov69_021E70A8
	.public ov69_021E7120
	.public ov69_021E7198
	.public ov69_021E737C
	.public ov69_021E7408
	.public ov69_021E7520
	.public ov69_021E758C
	.public ov69_021E75A0
	.public ov69_021E75F8
	.public _021E7644
	.public ov69_021E764C
	.public ov69_021E7654
	.public ov69_021E765C
	.public ov69_021E7664
	.public ov69_021E766C
	.public ov69_021E7674
	.public ov69_021E767C
	.public ov69_021E7688
	.public ov69_021E7698
	.public ov69_021E76B0
	.public ov69_021E76CC
	.public ov69_021E76E8
	.public ov69_021E7708
	.public ov69_021E7728
	.public ov69_021E774C
	.public ov69_021E7770
	.public ov69_021E7794
	.public ov69_021E77B8
	.include "overlay_69.inc"
	.include "global.inc"

	.text
	.public GeonetGlobe_Exit
	.public ov69_021E6300
	.public ov69_021E67B8
	.public ov69_021E68D8
	.public ov69_021E6A54
	.public ov69_021E6C14
	.public ov69_021E6F48
	.public ov69_021E6F8C
	.public ov69_021E706C
	.public ov69_021E758C
	.public ov69_021E75F8

	thumb_func_start ov69_021E68EC
ov69_021E68EC: ; 0x021E68EC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	ldr r0, _021E697C ; =0x0000C010
	add r6, r3, #0
	ldr r0, [r5, r0]
	str r1, [sp]
	bl AddWindow
	ldrh r0, [r6, #0x10]
	ldr r1, [r5]
	bl ListMenuItems_New
	ldr r1, _021E6980 ; =0x0000C068
	mov r7, #0
	str r0, [r5, r1]
	ldrh r0, [r6, #0x10]
	cmp r0, #0
	ble _021E692E
	ldr r4, [sp, #0x38]
_021E6914:
	ldr r0, _021E6980 ; =0x0000C068
	ldr r1, _021E6984 ; =0x0000C070
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [r4]
	ldr r3, [r4, #4]
	bl ListMenuItems_AppendFromMsgData
	ldrh r0, [r6, #0x10]
	add r7, r7, #1
	add r4, #8
	cmp r7, r0
	blt _021E6914
_021E692E:
	add r3, sp, #4
	add r2, r3, #0
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, _021E6980 ; =0x0000C068
	mov r1, #0
	ldr r0, [r5, r0]
	str r0, [sp, #4]
	ldr r0, [sp]
	str r0, [sp, #0x10]
	ldr r0, _021E6988 ; =ov69_021E68D8
	str r0, [sp, #8]
	ldr r3, [r5]
	add r0, r2, #0
	lsl r3, r3, #0x18
	add r2, r1, #0
	lsr r3, r3, #0x18
	bl ListMenuInit
	ldr r1, _021E698C ; =0x0000C064
	ldr r2, _021E6990 ; =0x000001D9
	str r0, [r5, r1]
	ldr r0, [sp, #0x10]
	mov r1, #1
	mov r3, #7
	bl DrawFrameAndWindow1
	ldr r0, [sp]
	bl CopyWindowToVram
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_021E697C: .word 0x0000C010
_021E6980: .word 0x0000C068
_021E6984: .word 0x0000C070
_021E6988: .word ov69_021E68D8
_021E698C: .word 0x0000C064
_021E6990: .word 0x000001D9
	thumb_func_end ov69_021E68EC


	thumb_func_start ov69_021E6994
ov69_021E6994: ; 0x021E6994
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r5, r0, #0
	ldr r0, _021E6A40 ; =0x0000C010
	str r1, [sp]
	ldr r0, [r5, r0]
	str r3, [sp, #4]
	ldr r7, [sp, #0x44]
	ldr r6, [sp, #0x48]
	bl AddWindow
	ldr r2, [sp, #0x40]
	ldr r3, [r5]
	mov r0, #0
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	str r0, [sp, #8]
	ldr r1, [r5]
	add r0, r6, #0
	bl ListMenuItems_New
	ldr r1, _021E6A44 ; =0x0000C068
	mov r4, #0
	str r0, [r5, r1]
	cmp r6, #0
	bls _021E69DE
_021E69CA:
	ldr r0, _021E6A44 ; =0x0000C068
	ldrb r2, [r7, r4]
	ldr r0, [r5, r0]
	ldr r1, [sp, #8]
	add r3, r4, #0
	bl ListMenuItems_AppendFromMsgData
	add r4, r4, #1
	cmp r4, r6
	blo _021E69CA
_021E69DE:
	ldr r0, [sp, #8]
	bl DestroyMsgData
	ldr r4, [sp, #4]
	add r3, sp, #0xc
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	str r4, [sp, #4]
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	str r4, [sp, #4]
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	str r4, [sp, #4]
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, _021E6A44 ; =0x0000C068
	mov r1, #0
	ldr r0, [r5, r0]
	str r4, [sp, #4]
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	strh r6, [r0, #0x10]
	ldr r0, [sp]
	str r0, [sp, #0x18]
	ldr r0, _021E6A48 ; =ov69_021E68D8
	str r0, [sp, #0x10]
	ldr r3, [r5]
	add r0, r2, #0
	lsl r3, r3, #0x18
	add r2, r1, #0
	lsr r3, r3, #0x18
	bl ListMenuInit
	ldr r1, _021E6A4C ; =0x0000C064
	ldr r2, _021E6A50 ; =0x000001D9
	str r0, [r5, r1]
	ldr r0, [sp, #0x18]
	mov r1, #1
	mov r3, #7
	bl DrawFrameAndWindow1
	ldr r0, [sp]
	bl CopyWindowToVram
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	nop
_021E6A40: .word 0x0000C010
_021E6A44: .word 0x0000C068
_021E6A48: .word ov69_021E68D8
_021E6A4C: .word 0x0000C064
_021E6A50: .word 0x000001D9
	thumb_func_end ov69_021E6994

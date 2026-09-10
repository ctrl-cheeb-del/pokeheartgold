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

	thumb_func_start ov69_021E6810
ov69_021E6810: ; 0x021E6810
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, _021E68C4 ; =0x0000C074
	add r6, r1, #0
	ldr r1, [r5, r0]
	mov r4, #0
	cmp r1, #0
	beq _021E682C
	cmp r1, #1
	beq _021E6886
	cmp r1, #2
	beq _021E68A6
	b _021E68BC
_021E682C:
	mov r1, #0xd8
	str r1, [sp]
	mov r1, #0x20
	sub r0, #0x60
	str r1, [sp, #4]
	add r0, r5, r0
	mov r1, #0xf
	add r2, r4, #0
	add r3, r4, #0
	bl FillWindowPixelRect
	mov r0, #1
	ldr r1, [r5]
	lsl r0, r0, #0xa
	bl String_New
	ldr r2, _021E68C8 ; =0x0000C07C
	add r1, r6, #0
	str r0, [r5, r2]
	add r0, r2, #0
	sub r0, #0xc
	ldr r0, [r5, r0]
	ldr r2, [r5, r2]
	bl ReadMsgDataIntoString
	ldr r0, [r5, #8]
	bl Options_GetTextFrameDelay
	add r3, r4, #0
	str r3, [sp]
	str r0, [sp, #4]
	ldr r2, _021E68CC ; =0x0000C014
	str r3, [sp, #8]
	add r0, r5, r2
	add r2, #0x68
	ldr r2, [r5, r2]
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _021E68D0 ; =0x0000C078
	mov r2, #1
	str r0, [r5, r1]
	sub r0, r1, #4
	str r2, [r5, r0]
	b _021E68BC
_021E6886:
	add r0, r0, #4
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _021E68BC
	ldr r0, _021E68C8 ; =0x0000C07C
	ldr r0, [r5, r0]
	bl String_Delete
	ldr r0, _021E68C4 ; =0x0000C074
	mov r1, #2
	str r1, [r5, r0]
	b _021E68BC
_021E68A6:
	cmp r2, #0
	bne _021E68B4
	ldr r0, _021E68D4 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _021E68BC
_021E68B4:
	ldr r0, _021E68C4 ; =0x0000C074
	mov r1, #0
	str r1, [r5, r0]
	mov r4, #1
_021E68BC:
	add r0, r4, #0
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	nop
_021E68C4: .word 0x0000C074
_021E68C8: .word 0x0000C07C
_021E68CC: .word 0x0000C014
_021E68D0: .word 0x0000C078
_021E68D4: .word gSystem
	thumb_func_end ov69_021E6810

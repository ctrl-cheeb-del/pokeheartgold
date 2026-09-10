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

	thumb_func_start ov69_021E75A0
ov69_021E75A0: ; 0x021E75A0
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0
	blt _021E75B4
	ldr r1, _021E75F4 ; =0x0000FFFF
	bl _s32_div_f
	str r1, [r4]
	b _021E75CA
_021E75B4:
	bge _021E75B8
	neg r0, r0
_021E75B8:
	ldr r1, _021E75F4 ; =0x0000FFFF
	bl _s32_div_f
	add r1, r0, #1
	ldr r0, _021E75F4 ; =0x0000FFFF
	ldr r2, [r4]
	mul r0, r1
	add r0, r2, r0
	str r0, [r4]
_021E75CA:
	ldr r0, [r4, #4]
	cmp r0, #0
	blt _021E75DA
	ldr r1, _021E75F4 ; =0x0000FFFF
	bl _s32_div_f
	str r1, [r4, #4]
	pop {r4, pc}
_021E75DA:
	bge _021E75DE
	neg r0, r0
_021E75DE:
	ldr r1, _021E75F4 ; =0x0000FFFF
	bl _s32_div_f
	add r1, r0, #1
	ldr r0, _021E75F4 ; =0x0000FFFF
	ldr r2, [r4, #4]
	mul r0, r1
	add r0, r2, r0
	str r0, [r4, #4]
	pop {r4, pc}
	nop
_021E75F4: .word 0x0000FFFF
	thumb_func_end ov69_021E75A0

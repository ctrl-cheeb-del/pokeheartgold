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

	thumb_func_start ov69_021E6FE8
ov69_021E6FE8: ; 0x021E6FE8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	ldr r6, _021E705C ; =ov69_021E767C
	add r4, r0, #0
	ldmia r6!, {r0, r1}
	add r5, sp, #8
	add r2, r5, #0
	stmia r5!, {r0, r1}
	ldr r0, [r6]
	add r1, r2, #0
	str r0, [r5]
	add r7, sp, #0x14
	mov r3, #0
	str r3, [r7]
	str r3, [r7, #4]
	str r3, [r7, #8]
	ldr r0, _021E7060 ; =0x0000C2DC
	str r3, [sp]
	ldr r0, [r4, r0]
	ldr r2, _021E7064 ; =0x000005C1
	str r0, [sp, #4]
	add r0, r7, #0
	bl Camera_Init_FromTargetAndPos
	ldr r2, _021E7060 ; =0x0000C2DC
	mov r1, #0x19
	ldr r2, [r4, r2]
	mov r0, #0
	lsl r1, r1, #0xe
	bl Camera_SetPerspectiveClippingPlane
	ldr r1, _021E7060 ; =0x0000C2DC
	mov r0, #0
	ldr r1, [r4, r1]
	bl Camera_ApplyPerspectiveType
	ldr r0, _021E7060 ; =0x0000C2DC
	ldr r0, [r4, r0]
	bl Camera_SetStaticPtr
	ldr r0, _021E7068 ; =0x0000C304
	ldrh r1, [r4, r0]
	cmp r1, #0
	bne _021E7048
	mov r1, #1
	sub r0, #0x1c
	strh r1, [r4, r0]
	b _021E704E
_021E7048:
	mov r1, #0
	sub r0, #0x1c
	strh r1, [r4, r0]
_021E704E:
	add r0, r4, #0
	bl ov69_021E737C
	cmp r0, #1
	bne _021E704E
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E705C: .word ov69_021E767C
_021E7060: .word 0x0000C2DC
_021E7064: .word 0x000005C1
_021E7068: .word 0x0000C304
	thumb_func_end ov69_021E6FE8

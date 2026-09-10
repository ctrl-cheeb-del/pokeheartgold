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

	thumb_func_start ov69_021E6C30
ov69_021E6C30: ; 0x021E6C30
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r6, r0, #0
	mov r0, #0
	str r0, [sp, #0x20]
	ldr r0, _021E6D54 ; =0x0000C2C4
	str r1, [sp]
	ldr r1, [r6, r0]
	mov r7, #1
	add r2, r1, #0
	sub r2, #0x80
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	str r2, [sp, #0x1c]
	add r2, r1, #0
	add r2, #0x80
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	str r2, [sp, #0x18]
	add r2, r0, #4
	ldr r3, [r6, r2]
	add r0, r0, #4
	add r2, r3, #0
	sub r2, #0x80
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add r3, #0x80
	str r2, [sp, #0x14]
	lsl r2, r3, #0x10
	asr r2, r2, #0x10
	str r2, [sp, #0x10]
	ldr r2, [r6, #0xc]
	lsl r7, r7, #8
	str r1, [sp, #0x2c]
	ldr r0, [r6, r0]
	str r2, [sp, #4]
	str r0, [sp, #0x30]
	add r0, sp, #0x2c
	bl ov69_021E75A0
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	sub r0, r1, r0
	bpl _021E6C8A
	neg r0, r0
_021E6C8A:
	mov r1, #1
	lsl r1, r1, #8
	cmp r0, r1
	ble _021E6CCE
	ldr r0, _021E6D58 ; =0x0000C2C8
	ldr r0, [r6, r0]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	str r0, [sp, #0xc]
	str r0, [sp, #8]
	cmp r0, #0
	ble _021E6CAC
	lsl r1, r1, #8
	sub r0, r0, r1
	str r0, [sp, #0x14]
	str r0, [sp, #0x10]
	b _021E6CB4
_021E6CAC:
	lsl r1, r1, #8
	add r0, r0, r1
	str r0, [sp, #0x14]
	str r0, [sp, #0x10]
_021E6CB4:
	ldr r0, [sp, #0xc]
	sub r0, #0x80
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r0, #0x80
	str r0, [sp, #8]
	ldr r0, [sp, #0x14]
	sub r0, #0x80
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, #0x80
	str r0, [sp, #0x10]
	b _021E6CD6
_021E6CCE:
	ldr r0, [sp, #0x14]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	str r0, [sp, #8]
_021E6CD6:
	ldr r0, [r6, #0xc]
	mov r4, #0
	cmp r0, #0
	bls _021E6D3A
	add r5, r6, #0
_021E6CE0:
	mov r0, #0x10
	ldrsh r0, [r5, r0]
	ldr r1, [sp, #0x1c]
	cmp r0, r1
	ble _021E6D30
	ldr r1, [sp, #0x18]
	cmp r0, r1
	bge _021E6D30
	mov r1, #0x12
	ldrsh r1, [r5, r1]
	ldr r2, [sp, #0x14]
	cmp r1, r2
	ble _021E6D00
	ldr r2, [sp, #0x10]
	cmp r1, r2
	blt _021E6D0C
_021E6D00:
	ldr r2, [sp, #0xc]
	cmp r1, r2
	ble _021E6D30
	ldr r2, [sp, #8]
	cmp r1, r2
	bge _021E6D30
_021E6D0C:
	ldrh r1, [r5, #0x38]
	cmp r1, #0
	beq _021E6D30
	str r0, [sp, #0x24]
	mov r0, #0x12
	ldrsh r0, [r5, r0]
	str r0, [sp, #0x28]
	add r0, sp, #0x24
	bl ov69_021E75A0
	add r0, sp, #0x2c
	add r1, sp, #0x24
	bl ov69_021E75F8
	cmp r0, r7
	bhs _021E6D30
	add r7, r0, #0
	str r4, [sp, #4]
_021E6D30:
	ldr r0, [r6, #0xc]
	add r4, r4, #1
	add r5, #0x30
	cmp r4, r0
	blo _021E6CE0
_021E6D3A:
	ldr r1, [sp, #4]
	ldr r0, [sp]
	str r1, [r0]
	ldr r1, [r6, #0xc]
	ldr r0, [sp, #4]
	cmp r0, r1
	beq _021E6D4C
	mov r0, #1
	str r0, [sp, #0x20]
_021E6D4C:
	ldr r0, [sp, #0x20]
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	nop
_021E6D54: .word 0x0000C2C4
_021E6D58: .word 0x0000C2C8
	thumb_func_end ov69_021E6C30


	thumb_func_start ov69_021E6D5C
ov69_021E6D5C: ; 0x021E6D5C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r1, _021E6E78 ; =0x0000C338
	add r5, r0, #0
	ldr r1, [r5, r1]
	cmp r1, #0
	bne _021E6DB6
	mov r0, #1
	ldr r1, [r5]
	lsl r0, r0, #0xa
	bl String_New
	add r4, r0, #0
	mov r0, #0xd8
	str r0, [sp]
	mov r0, #0x30
	str r0, [sp, #4]
	ldr r0, _021E6E7C ; =0x0000C014
	mov r2, #0
	add r0, r5, r0
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	ldr r0, _021E6E80 ; =0x0000C070
	mov r1, #0xf
	ldr r0, [r5, r0]
	add r2, r4, #0
	bl ReadMsgDataIntoString
	mov r3, #0
	ldr r0, _021E6E7C ; =0x0000C014
	str r3, [sp]
	str r3, [sp, #4]
	add r0, r5, r0
	mov r1, #1
	add r2, r4, #0
	str r3, [sp, #8]
	bl AddTextPrinterParameterized
	add r0, r4, #0
	bl String_Delete
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021E6DB6:
	add r1, sp, #0xc
	bl ov69_021E6C30
	cmp r0, #0
	beq _021E6E6E
	ldr r1, [r5]
	mov r0, #0x40
	bl String_New
	add r6, r0, #0
	ldr r1, [r5]
	mov r0, #0x40
	bl String_New
	add r4, r0, #0
	mov r0, #0xd8
	str r0, [sp]
	mov r0, #0x30
	str r0, [sp, #4]
	ldr r0, _021E6E7C ; =0x0000C014
	mov r2, #0
	add r0, r5, r0
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	ldr r1, [sp, #0xc]
	mov r0, #0x30
	add r2, r1, #0
	mul r2, r0
	ldr r0, [r5]
	add r1, r5, r2
	str r0, [sp]
	ldrh r0, [r1, #0x3a]
	ldrh r1, [r1, #0x3c]
	add r2, r6, #0
	add r3, r4, #0
	bl ov69_021E7520
	ldr r1, [sp, #0xc]
	mov r0, #0x30
	mul r0, r1
	add r0, r5, r0
	ldrh r0, [r0, #0x3c]
	cmp r0, #0
	beq _021E6E2A
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E6E7C ; =0x0000C014
	mov r3, #0
	add r0, r5, r0
	mov r1, #1
	add r2, r4, #0
	str r3, [sp, #8]
	bl AddTextPrinterParameterized
_021E6E2A:
	mov r3, #0
	ldr r0, _021E6E7C ; =0x0000C014
	str r3, [sp]
	str r3, [sp, #4]
	add r0, r5, r0
	mov r1, #1
	add r2, r6, #0
	str r3, [sp, #8]
	bl AddTextPrinterParameterized
	add r0, r4, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	ldr r0, [sp, #0xc]
	mov r1, #0x30
	add r2, r0, #0
	mul r2, r1
	add r2, r5, r2
	mov r0, #0x10
	ldrsh r2, [r2, r0]
	ldr r0, _021E6E84 ; =0x0000C2C4
	str r2, [r5, r0]
	ldr r2, [sp, #0xc]
	add r0, r0, #4
	mul r1, r2
	add r2, r5, r1
	mov r1, #0x12
	ldrsh r1, [r2, r1]
	add sp, #0x10
	str r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021E6E6E:
	ldr r0, _021E6E78 ; =0x0000C338
	mov r1, #0
	str r1, [r5, r0]
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E6E78: .word 0x0000C338
_021E6E7C: .word 0x0000C014
_021E6E80: .word 0x0000C070
_021E6E84: .word 0x0000C2C4
	thumb_func_end ov69_021E6D5C


	thumb_func_start ov69_021E6E88
ov69_021E6E88: ; 0x021E6E88
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #0
	bl NARC_AllocAndReadWholeMember
	ldr r2, _021E6F2C ; =0x0000C0DC
	str r0, [r5, r2]
	add r0, r2, #0
	sub r1, r2, #4
	sub r0, #0x58
	add r0, r5, r0
	add r1, r5, r1
	add r2, r5, r2
	bl GF3dRender_InitObjFromHeader
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #1
	bl NARC_AllocAndReadWholeMember
	ldr r2, _021E6F30 ; =0x0000C2A4
	str r0, [r5, r2]
	add r0, r2, #0
	add r1, r2, #0
	sub r0, #0xc8
	sub r1, #0x14
	add r0, r5, r0
	add r1, r5, r1
	add r2, r5, r2
	bl GF3dRender_InitObjFromHeader
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #2
	bl NARC_AllocAndReadWholeMember
	ldr r2, _021E6F34 ; =0x0000C2A8
	str r0, [r5, r2]
	add r0, r2, #0
	add r1, r2, #0
	sub r0, #0x78
	sub r1, #0x14
	add r0, r5, r0
	add r1, r5, r1
	add r2, r5, r2
	bl GF3dRender_InitObjFromHeader
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #3
	bl NARC_AllocAndReadWholeMember
	ldr r2, _021E6F38 ; =0x0000C29C
	str r0, [r5, r2]
	add r1, r2, #0
	ldr r0, _021E6F3C ; =0x0000C134
	sub r1, #0x14
	add r0, r5, r0
	add r1, r5, r1
	add r2, r5, r2
	bl GF3dRender_InitObjFromHeader
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #4
	bl NARC_AllocAndReadWholeMember
	ldr r2, _021E6F40 ; =0x0000C2A0
	str r0, [r5, r2]
	add r1, r2, #0
	ldr r0, _021E6F44 ; =0x0000C188
	sub r1, #0x14
	add r0, r5, r0
	add r1, r5, r1
	add r2, r5, r2
	bl GF3dRender_InitObjFromHeader
	pop {r3, r4, r5, pc}
	nop
_021E6F2C: .word 0x0000C0DC
_021E6F30: .word 0x0000C2A4
_021E6F34: .word 0x0000C2A8
_021E6F38: .word 0x0000C29C
_021E6F3C: .word 0x0000C134
_021E6F40: .word 0x0000C2A0
_021E6F44: .word 0x0000C188
	thumb_func_end ov69_021E6E88

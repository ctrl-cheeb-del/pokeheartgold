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

	thumb_func_start ov69_021E60F8
ov69_021E60F8: ; 0x021E60F8
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _021E6114 ; =ov69_021E77B8
	add r3, sp, #0
	mov r2, #5
_021E6102:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E6102
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_021E6114: .word ov69_021E77B8
	thumb_func_end ov69_021E60F8


	thumb_func_start ov69_021E6118
ov69_021E6118: ; 0x021E6118
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _021E6134 ; =ov69_021E7688
	add r3, sp, #0
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_021E6134: .word ov69_021E7688
	thumb_func_end ov69_021E6118


	thumb_func_start ov69_021E6138
ov69_021E6138: ; 0x021E6138
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #8]
	ldr r1, [sp, #8]
	mov r0, #0x62
	ldr r1, [r1]
	bl NARC_New
	ldr r1, [sp, #8]
	mov r2, #0
	str r2, [r1, #0xc]
	str r2, [sp]
	add r1, sp, #0x24
	str r1, [sp, #4]
	ldr r3, [sp, #8]
	mov r1, #0x12
	ldr r3, [r3]
	str r0, [sp, #0x1c]
	bl GfGfxLoader_LoadFromOpenNarc_GetSizeOut
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x24]
	mov r1, #6
	bl _u32_div_f
	add r7, r0, #0
	ldr r0, [sp, #0x18]
	mov r5, #1
	add r4, r0, #6
	cmp r7, #1
	ble _021E61AA
	ldr r6, [sp, #8]
	add r6, #0xc
_021E617A:
	ldrh r0, [r4]
	cmp r0, #2
	beq _021E61A2
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	mov r2, #2
	mov r3, #4
	add r1, r0, #0
	ldrsh r2, [r4, r2]
	ldrsh r3, [r4, r3]
	ldr r1, [r1, #0xc]
	bl ov69_021E623C
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
_021E61A2:
	add r5, r5, #1
	add r4, r4, #6
	cmp r5, r7
	blt _021E617A
_021E61AA:
	ldr r0, [sp, #0x18]
	bl Heap_Free
	mov r7, #1
	bl LocationGmmDatCountGet
	str r0, [sp, #0x10]
	cmp r0, #1
	ble _021E6232
	ldr r6, [sp, #8]
	add r6, #0xc
_021E61C0:
	add r0, r7, #0
	bl LocationGmmDatGetEarthPlaceDatId
	add r1, r0, #0
	mov r0, #0
	str r0, [sp]
	add r0, sp, #0x20
	str r0, [sp, #4]
	ldr r3, [sp, #8]
	ldr r0, [sp, #0x1c]
	ldr r3, [r3]
	mov r2, #0
	bl GfGfxLoader_LoadFromOpenNarc_GetSizeOut
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x20]
	mov r5, #1
	lsr r0, r0, #2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	add r4, r0, #4
	ldr r0, [sp, #0xc]
	cmp r0, #1
	ble _021E6224
_021E61F0:
	add r0, r7, #0
	bl LocationGmmDatGetCountryMsgNo
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	mov r2, #0
	mov r3, #2
	add r1, r0, #0
	ldrsh r2, [r4, r2]
	ldrsh r3, [r4, r3]
	ldr r1, [r1, #0xc]
	bl ov69_021E623C
	ldr r0, [r6]
	add r5, r5, #1
	add r0, r0, #1
	str r0, [r6]
	ldr r0, [sp, #0xc]
	add r4, r4, #4
	cmp r5, r0
	blt _021E61F0
_021E6224:
	ldr r0, [sp, #0x14]
	bl Heap_Free
	ldr r0, [sp, #0x10]
	add r7, r7, #1
	cmp r7, r0
	blt _021E61C0
_021E6232:
	ldr r0, [sp, #0x1c]
	bl NARC_Delete
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov69_021E6138


	thumb_func_start ov69_021E623C
ov69_021E623C: ; 0x021E623C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	ldr r5, _021E62AC ; =ov69_021E7770
	add r7, r2, #0
	add r6, r3, #0
	add r4, r0, #0
	mov ip, r1
	add r3, sp, #0xc
	mov r2, #4
_021E624E:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E624E
	ldr r0, [r5]
	mov r1, #0x30
	str r0, [r3]
	mov r0, ip
	add r5, r0, #0
	mul r5, r1
	add r0, r4, r5
	strh r7, [r0, #0x10]
	strh r6, [r0, #0x12]
	mov r0, #0
	str r0, [sp, #8]
	add r0, sp, #0xc
	add r1, sp, #0
	str r7, [sp]
	str r6, [sp, #4]
	bl ov69_021E7120
	add r3, r4, r5
	add r6, sp, #0xc
	add r3, #0x14
	mov r2, #4
_021E6280:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E6280
	ldr r0, [r6]
	add r2, sp, #0x38
	str r0, [r3]
	ldrh r1, [r2, #0x10]
	ldrh r2, [r2, #0x14]
	ldr r0, [r4, #4]
	bl WiFiHistory_GetLocationSeenState
	add r2, r4, r5
	strh r0, [r2, #0x38]
	add r0, sp, #0x38
	ldrh r1, [r0, #0x10]
	strh r1, [r2, #0x3a]
	ldrh r0, [r0, #0x14]
	strh r0, [r2, #0x3c]
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E62AC: .word ov69_021E7770
	thumb_func_end ov69_021E623C


	thumb_func_start ov69_021E62B0
ov69_021E62B0: ; 0x021E62B0
	push {r4, r5, r6, r7}
	ldr r1, [r0, #0xc]
	mov r4, #0
	cmp r1, #0
	bls _021E62EE
	ldr r1, _021E62F4 ; =0x0000C328
	add r5, r0, #0
	mov r3, #3
	sub r2, r1, #4
_021E62C2:
	ldrh r6, [r5, #0x3a]
	ldr r7, [r0, r2]
	cmp r7, r6
	bne _021E62E4
	ldrh r6, [r5, #0x3c]
	ldr r7, [r0, r1]
	cmp r7, r6
	bne _021E62E4
	strh r3, [r5, #0x38]
	mov r6, #0x10
	ldrsh r7, [r5, r6]
	ldr r6, _021E62F8 ; =0x0000C2C4
	str r7, [r0, r6]
	mov r6, #0x12
	ldrsh r7, [r5, r6]
	ldr r6, _021E62FC ; =0x0000C2C8
	str r7, [r0, r6]
_021E62E4:
	ldr r6, [r0, #0xc]
	add r4, r4, #1
	add r5, #0x30
	cmp r4, r6
	blo _021E62C2
_021E62EE:
	pop {r4, r5, r6, r7}
	bx lr
	nop
_021E62F4: .word 0x0000C328
_021E62F8: .word 0x0000C2C4
_021E62FC: .word 0x0000C2C8
	thumb_func_end ov69_021E62B0

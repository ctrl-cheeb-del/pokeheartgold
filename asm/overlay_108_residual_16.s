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

	thumb_func_start ov108_021E8540
ov108_021E8540: ; 0x021E8540
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x60
	add r5, r0, #0
	str r3, [sp, #0x2c]
	add r6, r1, #0
	ldr r0, [r5]
	mov r1, #0x10
	add r7, r2, #0
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x10
	add r4, r0, #0
	bl MI_CpuFill8
	ldr r0, [r5]
	mov r1, #8
	bl Heap_Alloc
	str r0, [r4, #8]
	ldr r0, [r5]
	mov r1, #0x24
	bl Heap_Alloc
	ldr r1, [r4, #8]
	mov r3, #0xe
	str r0, [r1]
	ldr r0, [r4, #8]
	lsl r3, r3, #0xc
	ldr r0, [r0]
	mov r1, #0
	str r0, [r4, #4]
	mov r0, #0
	str r3, [sp]
	mvn r0, r0
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x10]
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r2, [r5, r0]
	str r2, [sp, #0x14]
	add r2, r0, #4
	ldr r2, [r5, r2]
	str r2, [sp, #0x18]
	add r2, r0, #0
	add r2, #8
	ldr r2, [r5, r2]
	add r0, #0xc
	str r2, [sp, #0x1c]
	ldr r0, [r5, r0]
	add r2, r3, #0
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	add r1, sp, #0x68
	ldrb r1, [r1, #0x14]
	ldr r0, [r4, #4]
	add r1, r1, r3
	bl CreateSpriteResourcesHeader
	ldr r0, [r5, #0x14]
	cmp r0, #0
	beq _021E85C8
	str r0, [sp, #0x30]
	b _021E85CC
_021E85C8:
	ldr r0, [r5, #0x10]
	str r0, [sp, #0x30]
_021E85CC:
	ldr r0, [r4, #4]
	cmp r6, #0
	str r0, [sp, #0x34]
	beq _021E85E6
	lsl r0, r6, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _021E85F4
_021E85E6:
	lsl r0, r6, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_021E85F4:
	bl _ffix
	str r0, [sp, #0x38]
	cmp r7, #0
	beq _021E8610
	lsl r0, r7, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _021E861E
_021E8610:
	lsl r0, r7, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_021E861E:
	bl _ffix
	mov r1, #0
	str r1, [sp, #0x40]
	ldr r1, [sp, #0x84]
	str r0, [sp, #0x3c]
	cmp r1, #2
	bne _021E8636
	mov r1, #3
	lsl r1, r1, #0x12
	add r0, r0, r1
	str r0, [sp, #0x3c]
_021E8636:
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #0x44]
	str r0, [sp, #0x48]
	str r0, [sp, #0x4c]
	mov r1, #0
	add r0, sp, #0x30
	add r2, sp, #0x68
	strh r1, [r0, #0x20]
	ldrb r0, [r2, #0x10]
	str r0, [sp, #0x54]
	ldr r0, [sp, #0x84]
	str r0, [sp, #0x58]
	ldr r0, [r5]
	str r0, [sp, #0x5c]
	ldrb r1, [r2, #0x14]
	ldrb r2, [r2, #0x18]
	add r0, r5, #0
	bl ov108_021E84F8
	add r0, sp, #0x30
	bl Sprite_CreateAffine
	str r0, [r4]
	cmp r0, #0
	bne _021E866E
	bl GF_AssertFail
_021E866E:
	add r0, r4, #0
	add sp, #0x60
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov108_021E8540

	.include "asm/macros.inc"
	.include "overlay_37.inc"
	.include "global.inc"

	.text
	.public _021E7968
	.public ov37_021E5900
	.public ov37_021E5A84
	.public ov37_021E5B94
	.public ov37_021E5CC8
	.public ov37_021E5CF0
	.public ov37_021E5D10
	.public ov37_021E5E30
	.public ov37_021E5F98
	.public ov37_021E6090
	.public ov37_021E60C0
	.public ov37_021E6244
	.public ov37_021E6418
	.public ov37_021E657C
	.public ov37_021E65EC
	.public ov37_021E69DC
	.public ov37_021E6B64
	.public ov37_021E6D14
	.public ov37_021E6F5C
	.public ov37_021E6FC8
	.public ov37_021E70BC
	.public ov37_021E713C
	.public ov37_021E72B4
	.public ov37_021E72E8
	.public ov37_021E73B4
	.public ov37_021E741C
	.public ov37_021E7478
	.public ov37_021E755C
	.public ov37_021E762C
	.public ov37_021E76F0
	.public ov37_021E78E0
	.public ov37_021E7970
	.public ov37_021E7978
	.public ov37_021E7988
	.public ov37_021E7998
	.public ov37_021E79B4
	.public ov37_021E79D0
	.public ov37_021E79EC
	.public ov37_021E7A08
	.public ov37_021E7A24
	.public ov37_021E7A4C
	.public ov37_021E7A80
	.public ov37_021E7AC8
	.public ov37_021E7D20

	.public ov37_021E5F20
	.public ov37_021E5F5C
	.public ov37_021E6540
	.public ov37_021E6818
	.public ov37_021E6848
	.public ov37_021E6860
	.public ov37_021E68AC
	.public ov37_021E68D0
	.public ov37_021E6928
	.public ov37_021E694C
	.public ov37_021E6980
	.public ov37_021E6B40
	.public ov37_021E6BFC
	.public ov37_021E6C38
	.public ov37_021E6C58
	.public ov37_021E6C84
	.public ov37_021E6CC0
	.public ov37_021E6DD0
	.public ov37_021E6E04
	.public ov37_021E6E2C
	.public ov37_021E6E6C
	.public ov37_021E6E70
	.public ov37_021E6E90
	.public ov37_021E6EB4
	.public ov37_021E6F14
	.public ov37_021E745C
	.public ov37_021E75C4
	.public ov37_021E75E0
	.public ov37_021E75E8
	.public ov37_021E76A0
	.public ov37_021E76C0
	.public ov37_021E76D0
	.public ov37_021E7844
	.public ov37_021E784C
	.public ov37_021E7880
	.public ov37_021E78A4
	.public ov37_021E78C4

	thumb_func_start ov37_021E7478
ov37_021E7478: ; 0x021E7478
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r7, r3, #0
	add r5, r0, #0
	str r2, [sp, #0x10]
	bl sub_0203769C
	str r0, [sp, #0x14]
	add r0, r7, #0
	bl ov37_021E75E8
	cmp r0, #0
	beq _021E7552
	mov r0, #0
	str r0, [sp, #0x18]
	add r6, r7, #0
	add r4, r7, #0
_021E749A:
	mov r0, #0xcd
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	cmp r0, #0
	bne _021E74B2
	mov r0, #0x21
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _021E74BE
_021E74B2:
	mov r0, #0x21
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
_021E74BE:
	ldr r0, [sp, #0x18]
	add r6, #8
	add r0, r0, #1
	add r4, r4, #4
	str r0, [sp, #0x18]
	cmp r0, #5
	blt _021E749A
	mov r6, #0
	add r4, r5, #0
_021E74D0:
	mov r0, #0x50
	mov r1, #0
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	add r0, r4, #0
	add r2, r1, #0
	add r3, r1, #0
	bl FillWindowPixelRect
	add r6, r6, #1
	add r4, #0x10
	cmp r6, #5
	blt _021E74D0
	mov r6, #0
	add r4, r7, #0
_021E74F0:
	mov r0, #0xcd
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	cmp r0, #0
	beq _021E7540
	ldr r1, [r4, #0x14]
	bl PlayerName_FlatToString
	ldr r0, [sp, #0x14]
	cmp r0, r6
	bne _021E7524
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021E7558 ; =0x0003040F
	mov r1, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x14]
	add r0, r5, #0
	mov r3, #0
	bl AddTextPrinterParameterizedWithColor
	b _021E7540
_021E7524:
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	mov r1, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x14]
	add r0, r5, #0
	mov r3, #0
	bl AddTextPrinterParameterizedWithColor
_021E7540:
	add r0, r5, #0
	bl CopyWindowToVram
	add r6, r6, #1
	add r7, #8
	add r4, r4, #4
	add r5, #0x10
	cmp r6, #5
	blt _021E74F0
_021E7552:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_021E7558: .word 0x0003040F
	thumb_func_end ov37_021E7478


	thumb_func_start ov37_021E755C
ov37_021E755C: ; 0x021E755C
	push {r4, lr}
	add r4, r0, #0
	bl sub_0203769C
	cmp r0, #0
	bne _021E759C
	bl sub_0203783C
	cmp r0, #0
	beq _021E75B0
	ldr r1, _021E75B4 ; =0x000093F4
	ldr r0, _021E75B8 ; =0x00004381
	ldr r2, [r4, r1]
	sub r1, #0x37
	strb r2, [r4, r0]
	sub r0, #9
	add r2, r4, r1
	add r3, r4, r0
	mov r1, #0xa
_021E7582:
	ldrb r0, [r3]
	add r3, r3, #1
	strb r0, [r2]
	add r2, r2, #1
	sub r1, r1, #1
	bne _021E7582
	ldr r1, _021E75BC ; =0x000093BD
	mov r0, #0x78
	add r1, r4, r1
	mov r2, #0x32
	bl sub_02037108
	pop {r4, pc}
_021E759C:
	bl sub_02037854
	cmp r0, #0
	beq _021E75B0
	ldr r1, _021E75C0 ; =0x00004378
	mov r0, #0x77
	add r1, r4, r1
	mov r2, #0xa
	bl sub_02037030
_021E75B0:
	pop {r4, pc}
	nop
_021E75B4: .word 0x000093F4
_021E75B8: .word 0x00004381
_021E75BC: .word 0x000093BD
_021E75C0: .word 0x00004378
	thumb_func_end ov37_021E755C

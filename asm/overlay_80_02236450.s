	.include "asm/macros.inc"
	.public _022364D0
	.public _022364DE
	.public _022364E2
	.public _02236516
	.public _0223653C
	.public _02236554
	.public _02236562
	.public _02236566
	.public _02236576
	.public _02236594
	.public _022365A0
	.public _022365AE
	.public _022365C0
	.public _022365CA
	.public _022365D2
	.public _022365DE
	.public _022365E8
	.public _022365EE
	.public _02236614
	.public _02236620
	.public _0223665C
	.public _02236668
	.public _02236674
	.public _022366C6
	.public _0223670C
	.public _02236728
	.public _0223672C
	.public _02236730
	.public _0223678E
	.public _02236790
	.public _0223679E
	.public _022367AA
	.public _022367BE
	.public _022367F0
	.public _022367F2
	.public _02236832
	.public _02236842
	.public _02236856
	.public _0223685C
	.public _0223686E
	.public _0223689E
	.public _022368B2
	.public _022368C4
	.public _022368E4
	.public _022368E8
	.public _022368EC
	.public _022368F0
	.public _022368F4
	.public _022368F8
	.public _022368FC
	.public _02236900
	.public _02236904
	.public _02236908
	.public _02236964
	.public _022369A6
	.public _022369B8
	.public _022369DC
	.public _022369F6
	.public _02236A18
	.public _02236A2C
	.public _02236A62
	.public _02236A7E
	.public _02236A98
	.public _02236AA6
	.public _02236AAA
	.public _02236AAE
	.public _02236AB2
	.public _02236AB6
	.public _02236AD4
	.public _02236AE6
	.public _02236AEA
	.public _02236AFE
	.public _02236B12
	.public _02236B26
	.public _02236B2C
	.public _02236B3A
	.public _02236B48
	.public _02236B56
	.public _02236B6C
	.public _02236B70
	.public _02236B74
	.public ov80_02236450
	.public ov80_022364A4
	.public ov80_02236698
	.public ov80_022366D4
	.public ov80_02236734
	.public ov80_0223690C
	.public ov80_02236A34
	.public ov80_02236A88
	.public ov80_02236ABC
	.public ov80_02236AD8
	.public ov80_02236AF0
	.public ov80_02236B04
	.public ov80_02236B18
	.public ov80_02236B30
	.include "overlay_80_02236450.inc"
	.include "global.inc"

    .text
	.public ov80_02236450
	.public ov80_02236698
	.public ov80_022366D4
	.public ov80_02236734
	.public ov80_0223690C
	.public ov80_02236A34
	.public ov80_02236A88
	.public ov80_02236ABC
	.public ov80_02236AD8
	.public ov80_02236AF0
	.public ov80_02236B04
	.public ov80_02236B18
	.public ov80_02236B30

	thumb_func_start ov80_022364A4
ov80_022364A4: ; 0x022364A4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x84
	add r7, r0, #0
	ldr r0, [sp, #0x9c]
	str r2, [sp, #0x18]
	str r0, [sp, #0x9c]
	ldr r0, [sp, #0xa0]
	str r1, [sp, #0x14]
	str r0, [sp, #0xa0]
	ldr r0, [sp, #0xa4]
	str r3, [sp, #0x1c]
	str r0, [sp, #0xa4]
	ldr r0, [sp, #0xa8]
	str r0, [sp, #0xa8]
	mov r0, #0
	str r0, [sp, #0x2c]
	add r0, sp, #0x88
	ldrb r0, [r0, #0x10]
	cmp r0, #4
	bls _022364D0
	bl GF_AssertFail
_022364D0:
	add r0, sp, #0x88
	ldrb r6, [r0, #0x10]
	mov r4, #0
	str r4, [sp, #0x30]
	cmp r6, #0
	bne _022364DE
	b _022365EE
_022364DE:
	add r0, sp, #0x74
	str r0, [sp, #0x24]
_022364E2:
	add r0, r7, #0
	bl FrontierFieldSystem_0204B510
	ldr r1, [sp, #0x14]
	ldrh r1, [r1, #2]
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x17
	ldr r0, [sp, #0x14]
	add r0, r0, r1
	ldrh r0, [r0, #4]
	str r0, [sp, #0x34]
	ldrb r0, [r7, #0xf]
	bl ov80_02236AF0
	add r2, r0, #0
	ldr r1, [sp, #0x34]
	add r0, sp, #0x44
	bl ov80_02229EF4
	mov r0, #0
	str r0, [sp, #0x40]
	cmp r4, #0
	ble _0223653C
	add r5, sp, #0x74
_02236516:
	ldrb r0, [r7, #0xf]
	bl ov80_02236AF0
	add r2, r0, #0
	ldr r1, [r5]
	add r0, sp, #0x54
	bl ov80_02229EF4
	add r0, sp, #0x44
	ldrh r1, [r0, #0x10]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0223653C
	ldr r0, [sp, #0x40]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #0x40]
	cmp r0, r4
	blt _02236516
_0223653C:
	ldr r0, [sp, #0x40]
	cmp r0, r4
	bne _022365E8
	ldr r0, [sp, #0x9c]
	cmp r0, #0
	beq _02236566
	mov r0, #0
	cmp r6, #0
	ble _02236562
	add r1, sp, #0x44
	ldrh r3, [r1]
	ldr r2, [sp, #0x9c]
_02236554:
	ldrh r1, [r2]
	cmp r3, r1
	beq _02236562
	add r0, r0, #1
	add r2, r2, #2
	cmp r0, r6
	blt _02236554
_02236562:
	cmp r0, r6
	bne _022365E8
_02236566:
	ldr r0, [sp, #0x30]
	cmp r0, #0x32
	bge _022365DE
	mov r0, #0
	str r0, [sp, #0x20]
	cmp r4, #0
	ble _022365A0
	add r5, sp, #0x74
_02236576:
	ldrb r0, [r7, #0xf]
	bl ov80_02236AF0
	add r2, r0, #0
	ldr r1, [r5]
	add r0, sp, #0x54
	bl ov80_02229EF4
	add r0, sp, #0x44
	ldrh r1, [r0, #0x1c]
	cmp r1, #0
	beq _02236594
	ldrh r0, [r0, #0xc]
	cmp r1, r0
	beq _022365A0
_02236594:
	ldr r0, [sp, #0x20]
	add r5, r5, #4
	add r0, r0, #1
	str r0, [sp, #0x20]
	cmp r0, r4
	blt _02236576
_022365A0:
	ldr r0, [sp, #0x20]
	cmp r0, r4
	beq _022365AE
	ldr r0, [sp, #0x30]
	add r0, r0, #1
	str r0, [sp, #0x30]
	b _022365E8
_022365AE:
	ldr r0, [sp, #0xa0]
	cmp r0, #0
	beq _022365DE
	mov r0, #0
	cmp r6, #0
	ble _022365D2
	add r1, sp, #0x44
	ldrh r3, [r1, #0xc]
	ldr r2, [sp, #0xa0]
_022365C0:
	ldrh r1, [r2]
	cmp r3, r1
	bne _022365CA
	cmp r1, #0
	bne _022365D2
_022365CA:
	add r0, r0, #1
	add r2, r2, #2
	cmp r0, r6
	blt _022365C0
_022365D2:
	cmp r0, r6
	beq _022365DE
	ldr r0, [sp, #0x30]
	add r0, r0, #1
	str r0, [sp, #0x30]
	b _022365E8
_022365DE:
	ldr r1, [sp, #0x34]
	ldr r0, [sp, #0x24]
	add r4, r4, #1
	stmia r0!, {r1}
	str r0, [sp, #0x24]
_022365E8:
	cmp r4, r6
	beq _022365EE
	b _022364E2
_022365EE:
	ldr r0, [sp, #0x18]
	bl GetFrontierTrainerIVs
	str r0, [sp, #0x3c]
	add r0, r7, #0
	bl FrontierFieldSystem_0204B510
	add r5, r0, #0
	add r0, r7, #0
	bl FrontierFieldSystem_0204B510
	lsl r0, r0, #0x10
	orr r0, r5
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x30]
	cmp r0, #0x32
	blt _02236614
	mov r0, #1
	str r0, [sp, #0x2c]
_02236614:
	mov r5, #0
	cmp r4, #0
	ble _0223665C
	add r0, sp, #0x74
	str r0, [sp, #0x28]
	add r6, sp, #0x64
_02236620:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x3c]
	ldr r2, [sp, #0x28]
	str r0, [sp, #4]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x1c]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0xa8]
	ldr r3, [sp, #0x38]
	str r0, [sp, #0x10]
	ldr r2, [r2]
	add r0, r7, #0
	lsl r2, r2, #0x10
	lsr r2, r2, #0x10
	bl ov80_02236734
	stmia r6!, {r0}
	ldr r0, [sp, #0x28]
	add r5, r5, #1
	add r0, r0, #4
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x1c]
	add r0, #0x38
	str r0, [sp, #0x1c]
	cmp r5, r4
	blt _02236620
_0223665C:
	ldr r0, [sp, #0xa4]
	cmp r0, #0
	bne _02236668
	ldr r0, [sp, #0x2c]
	add sp, #0x84
	pop {r4, r5, r6, r7, pc}
_02236668:
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0xa4]
	str r1, [r0]
	mov r3, #0
	add r0, sp, #0x74
	add r1, sp, #0x64
_02236674:
	ldr r5, [r0]
	ldr r4, [sp, #0xa4]
	add r3, r3, #1
	strh r5, [r4, #4]
	ldr r4, [r1]
	add r0, r0, #4
	str r4, [r2, #8]
	ldr r4, [sp, #0xa4]
	add r1, r1, #4
	add r4, r4, #2
	add r2, r2, #4
	str r4, [sp, #0xa4]
	cmp r3, #2
	blt _02236674
	ldr r0, [sp, #0x2c]
	add sp, #0x84
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_022364A4

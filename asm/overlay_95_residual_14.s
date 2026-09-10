	.include "asm/macros.inc"
	.include "overlay_95.inc"
	.include "global.inc"
	.public HatchEggApp_Exit
	.public HatchEggApp_Init
	.public HatchEggApp_Main
	.public ov95_021E5954
	.public ov95_021E5974
	.public ov95_021E59F8
	.public ov95_021E5A38
	.public ov95_021E5BBC
	.public ov95_021E5C44
	.public ov95_021E5CAC
	.public ov95_021E5D44
	.public ov95_021E5D98
	.public ov95_021E5DB4
	.public ov95_021E5DD0
	.public ov95_021E5E18
	.public ov95_021E5E90
	.public ov95_021E5EC0
	.public ov95_021E5EF8
	.public ov95_021E6000
	.public ov95_021E60A4
	.public ov95_021E619C
	.public ov95_021E623C
	.public ov95_021E62A4
	.public ov95_021E6314
	.public ov95_021E65A0
	.public ov95_021E6838
	.public ov95_021E68A8
	.public ov95_021E6900
	.public ov95_021E6964
	.public ov95_021E6B74
	.public ov95_021E7020
	.public ov95_021E70BC
	.public ov95_021E7258
	.public ov95_021E7308
	.public ov95_021E7328
	.public ov95_021E7388
	.public ov95_021E7410
	.public ov95_021E7450
	.public ov95_021E7538
	.public ov95_021E7548
	.public ov95_021E755C
	.public ov95_021E7574
	.public ov95_021E7594
	.public ov95_021E75B4
	.public ov95_021E75DC
	.public ov95_021E762C
	.public ov95_021E767C
	.public ov95_021E76D0
	.public ov95_021E7770
	.public ov95_021E7810
	.public ov95_021E7818
	.public ov95_021E7820
	.public ov95_021E782C
	.public ov95_021E7860


	.text
	.public ov95_021E5900
	.public ov95_021E5928
	.public ov95_021E5B24
	.public ov95_021E5B58
	.public ov95_021E5B7C
	.public ov95_021E5B9C
	.public ov95_021E5D34
	.public ov95_021E5E40
	.public ov95_021E5E58
	.public ov95_021E5EDC
	.public ov95_021E5EF0
	.public ov95_021E6150
	.public ov95_021E6184
	.public ov95_021E6228
	.public ov95_021E62E4
	.public ov95_021E62F0
	.public ov95_021E6300
	.public ov95_021E67F0
	.public ov95_021E6FC4
	.public ov95_021E7078
	.public ov95_021E7208
	.public ov95_021E72B8
	.public ov95_021E7404
	.public ov95_021E7514

	thumb_func_start ov95_021E7410
ov95_021E7410: ; 0x021E7410
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _021E741E
	bl GF_AssertFail
_021E741E:
	ldrb r0, [r5, #0x19]
	cmp r0, #1
	beq _021E742A
	cmp r0, #2
	beq _021E742E
	b _021E7432
_021E742A:
	mov r4, #0
	b _021E7436
_021E742E:
	mov r4, #1
	b _021E7436
_021E7432:
	bl GF_AssertFail
_021E7436:
	ldr r1, _021E7448 ; =ov95_021E7818
	lsl r3, r4, #2
	ldr r2, _021E744C ; =ov95_021E7818 + 2
	ldrsh r1, [r1, r3]
	ldrsh r2, [r2, r3]
	ldr r0, [r5, #0x10]
	bl ManagedSprite_SetPositionXY
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E7448: .word ov95_021E7818
_021E744C: .word ov95_021E7818 + 2
	thumb_func_end ov95_021E7410


	thumb_func_start ov95_021E7450
ov95_021E7450: ; 0x021E7450
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _021E7508 ; =ov95_021E7820
	mov r4, #0
	bl TouchscreenHitbox_FindRectAtTouchNew
	add r6, r0, #0
	sub r0, r4, #1
	cmp r6, r0
	beq _021E7488
	ldr r0, _021E750C ; =0x000005DC
	bl PlaySE
	cmp r6, #0
	beq _021E7474
	cmp r6, #1
	beq _021E747A
	b _021E7482
_021E7474:
	mov r4, #1
	strb r4, [r5, #0x19]
	b _021E74EC
_021E747A:
	mov r0, #2
	strb r0, [r5, #0x19]
	mov r4, #1
	b _021E74EC
_021E7482:
	bl GF_AssertFail
	b _021E74EC
_021E7488:
	ldr r0, _021E7510 ; =gSystem
	mov r1, #0x40
	ldr r0, [r0, #0x48]
	tst r1, r0
	beq _021E74AA
	ldrb r0, [r5, #0x19]
	cmp r0, #1
	beq _021E74EC
	mov r0, #1
	strb r0, [r5, #0x19]
	add r0, r5, #0
	bl ov95_021E7410
	ldr r0, _021E750C ; =0x000005DC
	bl PlaySE
	b _021E74EC
_021E74AA:
	mov r1, #0x80
	tst r1, r0
	beq _021E74C8
	ldrb r0, [r5, #0x19]
	cmp r0, #2
	beq _021E74EC
	mov r0, #2
	strb r0, [r5, #0x19]
	add r0, r5, #0
	bl ov95_021E7410
	ldr r0, _021E750C ; =0x000005DC
	bl PlaySE
	b _021E74EC
_021E74C8:
	mov r1, #1
	add r2, r0, #0
	tst r2, r1
	beq _021E74E2
	ldrb r0, [r5, #0x19]
	cmp r0, #0
	bne _021E74DE
	bl GF_AssertFail
	mov r0, #2
	strb r0, [r5, #0x19]
_021E74DE:
	mov r4, #1
	b _021E74EC
_021E74E2:
	mov r2, #2
	tst r0, r2
	beq _021E74EC
	strb r2, [r5, #0x19]
	add r4, r1, #0
_021E74EC:
	cmp r4, #0
	beq _021E7504
	add r0, r5, #0
	bl ov95_021E7410
	ldr r0, [r5, #0x10]
	mov r1, #3
	bl ManagedSprite_SetAnim
	ldr r0, _021E750C ; =0x000005DC
	bl PlaySE
_021E7504:
	add r0, r4, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E7508: .word ov95_021E7820
_021E750C: .word 0x000005DC
_021E7510: .word gSystem
	thumb_func_end ov95_021E7450

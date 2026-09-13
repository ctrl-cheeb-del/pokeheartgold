	.include "asm/macros.inc"
	.include "overlay_108.inc"
	.include "global.inc"

	.text
	.extern SafariDecoration_Init
	.extern SafariDecoration_Exit
	.extern SafariDecoration_Main
	.extern ov108_021E8968
	.extern ov108_021E8A88
	.extern ov108_021E8AD4
	.extern ov108_021E8B24
	.extern ov108_021E8B68
	.extern ov108_021E8BC0
	.extern ov108_021E8C18
	.extern ov108_021E8C64
	.extern ov108_021E8CD4
	.extern ov108_021E8E10
	.extern ov108_021E8E60
	.extern ov108_021E8EA4
	.extern ov108_021E8ED8
	.extern ov108_021E8F00
	.extern ov108_021E90C4
	.extern ov108_021E9144
	.extern ov108_021E9198
	.extern ov108_021E91D4
	.extern ov108_021E91F8
	.extern ov108_021E9204
	.extern ov108_021E9210
	.extern ov108_021E9230
	.extern ov108_021E929C
	.extern ov108_021E9304
	.extern ov108_021E9388
	.extern ov108_021E93A8
	.extern ov108_021E940C
	.extern ov108_021E9488
	.extern ov108_021E94E8
	.extern ov108_021E9830
	.extern ov108_021E9850
	.extern ov108_021E9A08
	.extern ov108_021E9A60
	.extern ov108_021E9BD4
	.extern ov108_021E9C14
	.extern ov108_021E9C2C
	.extern ov108_021E9C3C
	.extern ov108_021E9CD0
	.extern ov108_021E9D30
	.extern ov108_021E9DE0
	.extern ov108_021E9E10
	.extern ov108_021E9E80
	.extern ov108_021E9EB8
	.extern ov108_021E9F04
	.extern ov108_021E9F20
	.extern ov108_021E9F94
	.extern ov108_021EA040
	.extern ov108_021EA260
	.extern ov108_021EA2EC
	.extern ov108_021EA334
	.extern ov108_021EA418
	.extern ov108_021EA47C
	.extern ov108_021EA50C
	.extern ov108_021EA52C
	.extern ov108_021EA584
	.extern ov108_021EA5E4
	.extern ov108_021EA624
	.extern ov108_021EA63C
	.extern ov108_021EA700
	.extern ov108_021EA9C4
	.extern ov108_021EA9D8
	.extern ov108_021EA9E4
	.extern ov108_021EAAA4
	.extern ov108_021EAAB0
	.extern ov108_021EAAC0
	.extern ov108_021EAAD0
	.extern ov108_021EAAE4
	.extern ov108_021EAB00
	.extern ov108_021EAB1C
	.extern ov108_021EAB38
	.extern ov108_021EAB54
	.extern ov108_021EAB70
	.extern ov108_021EAB8C
	.extern ov108_021EABA8
	.extern ov108_021EABC8
	.extern ov108_021EABF0
	.extern ov108_021EAC18
	.extern ov108_021EAC48
	.extern ov108_021EACE8
	.extern ov108_021EACF0
	.extern ov108_021EACF8
	.extern ov108_021EAD00
	.extern ov108_021EAD08
	.extern ov108_021EAD28


	thumb_func_start ov108_021E9528
ov108_021E9528: ; 0x021E9528
	push {r3, r4, r5, lr}
	add r4, r0, #0
	cmp r1, #6
	blo _021E9544
	ldr r0, _021E95A0 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	mov r1, #1
	bl ov108_021E9F20
	mov r0, #3
	str r0, [r4, #0xc]
	pop {r3, r4, r5, pc}
_021E9544:
	ldr r2, _021E95A4 ; =0x00000431
	sub r3, r2, #1
	ldrb r5, [r4, r3]
	ldrb r1, [r4, r2]
	mov r3, #6
	mul r3, r5
	add r3, r1, r3
	add r1, r2, #1
	strb r3, [r4, r1]
	sub r2, r2, #4
	ldrb r1, [r4, r1]
	ldrb r2, [r4, r2]
	cmp r1, r2
	blo _021E9564
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E9564:
	bl ov108_021EA52C
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	beq _021E9580
	ldr r0, _021E95A8 ; =0x000005F3
	bl PlaySE
	add r0, r4, #0
	sub r1, r5, #1
	bl ov108_021EA418
	mov r0, #2
	pop {r3, r4, r5, pc}
_021E9580:
	ldr r0, _021E95A0 ; =0x000005DC
	bl PlaySE
	mov r1, #0xcd
	lsl r1, r1, #2
	add r0, r1, #0
	add r0, #0xfe
	ldrb r2, [r4, r0]
	ldr r3, [r4, r1]
	add r1, #0xff
	lsl r0, r2, #2
	add r0, r2, r0
	ldrb r0, [r3, r0]
	strb r0, [r4, r1]
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E95A0: .word 0x000005DC
_021E95A4: .word 0x00000431
_021E95A8: .word 0x000005F3
	thumb_func_end ov108_021E9528

	thumb_func_start ov108_021E95AC
ov108_021E95AC: ; 0x021E95AC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	ldr r0, _021E96EC ; =gSystem
	mov r1, #0
	ldr r2, [r0, #0x48]
	ldr r0, _021E96F0 ; =0x00000CF3
	tst r0, r2
	beq _021E95BE
	str r1, [r4, #0x10]
_021E95BE:
	ldr r0, _021E96EC ; =gSystem
	ldr r6, [r0, #0x48]
	mov r0, #2
	tst r0, r6
	beq _021E95D2
	add r0, r4, #0
	mov r1, #6
	bl ov108_021E9528
	pop {r3, r4, r5, r6, r7, pc}
_021E95D2:
	mov r0, #1
	tst r0, r6
	beq _021E95E4
	ldr r1, _021E96F4 ; =0x00000431
	add r0, r4, #0
	ldrb r1, [r4, r1]
	bl ov108_021E9528
	pop {r3, r4, r5, r6, r7, pc}
_021E95E4:
	mov r0, #0xf0
	tst r0, r6
	bne _021E95EE
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E95EE:
	ldr r0, _021E96F4 ; =0x00000431
	mov r2, #0x1f
	ldrb r5, [r4, r0]
	lsr r3, r5, #0x1f
	lsl r7, r5, #0x1f
	sub r7, r7, r3
	ror r7, r2
	add r2, r3, r7
	lsl r3, r5, #0x17
	lsl r2, r2, #0x18
	mov r5, #0x10
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	tst r5, r6
	beq _021E9644
	cmp r3, #3
	bne _021E9614
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E9614:
	cmp r2, #1
	bne _021E963C
	sub r5, r0, #3
	sub r1, r0, #1
	ldrb r5, [r4, r5]
	ldrb r1, [r4, r1]
	sub r5, r5, #1
	cmp r1, r5
	bge _021E9638
	cmp r3, #3
	bhs _021E9638
	sub r1, r0, #1
	ldrb r1, [r4, r1]
	sub r0, r0, #1
	add r1, r1, #1
	strb r1, [r4, r0]
	mov r1, #2
	b _021E96AE
_021E9638:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E963C:
	add r0, r2, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	b _021E96AE
_021E9644:
	mov r5, #0x20
	tst r5, r6
	beq _021E967C
	cmp r3, #3
	bne _021E9652
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E9652:
	cmp r2, #0
	bne _021E9674
	sub r1, r0, #1
	ldrb r1, [r4, r1]
	cmp r1, #0
	beq _021E9670
	cmp r3, #3
	bhs _021E9670
	sub r1, r0, #1
	ldrb r1, [r4, r1]
	sub r0, r0, #1
	sub r1, r1, #1
	strb r1, [r4, r0]
	mov r1, #1
	b _021E96AE
_021E9670:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E9674:
	sub r0, r2, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	b _021E96AE
_021E967C:
	mov r0, #0x40
	tst r0, r6
	beq _021E9696
	add r0, r3, #3
	lsr r5, r0, #0x1f
	lsl r3, r0, #0x1e
	sub r3, r3, r5
	mov r0, #0x1e
	ror r3, r0
	add r0, r5, r3
	lsl r0, r0, #0x18
	lsr r3, r0, #0x18
	b _021E96AE
_021E9696:
	mov r0, #0x80
	tst r0, r6
	beq _021E96AE
	add r0, r3, #1
	lsr r5, r0, #0x1f
	lsl r3, r0, #0x1e
	sub r3, r3, r5
	mov r0, #0x1e
	ror r3, r0
	add r0, r5, r3
	lsl r0, r0, #0x18
	lsr r3, r0, #0x18
_021E96AE:
	lsl r0, r3, #1
	add r2, r2, r0
	ldr r0, _021E96F4 ; =0x00000431
	cmp r1, #0
	strb r2, [r4, r0]
	beq _021E96D0
	sub r1, r1, #1
	add r0, r4, #0
	lsl r1, r1, #0x18
	add r4, #0x14
	lsr r1, r1, #0x18
	add r2, r4, #0
	mov r3, #0
	bl ov108_021EA584
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_021E96D0:
	ldr r0, _021E96F8 ; =0x000005E5
	bl PlaySE
	ldr r1, _021E96F4 ; =0x00000431
	add r0, r4, #0
	ldrb r1, [r4, r1]
	bl ov108_021EA2EC
	add r0, r4, #0
	bl ov108_021EA47C
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E96EC: .word gSystem
_021E96F0: .word 0x00000CF3
_021E96F4: .word 0x00000431
_021E96F8: .word 0x000005E5
	thumb_func_end ov108_021E95AC

	thumb_func_start ov108_021E96FC
ov108_021E96FC: ; 0x021E96FC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021E9794 ; =ov108_021EABF0
	add r4, r1, #0
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _021E9716
	mov r0, #0
	str r0, [r4]
	pop {r3, r4, r5, pc}
_021E9716:
	cmp r0, #7
	bne _021E973E
	mov r0, #0x43
	lsl r0, r0, #4
	ldrb r1, [r5, r0]
	cmp r1, #0
	beq _021E973A
	sub r1, r1, #1
	strb r1, [r5, r0]
	add r0, r5, #0
	mov r1, #0
	add r5, #0x14
	add r2, r5, #0
	add r3, r1, #0
	bl ov108_021EA584
	mov r0, #1
	str r0, [r4]
_021E973A:
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E973E:
	cmp r0, #8
	bne _021E976C
	mov r0, #0x43
	lsl r0, r0, #4
	sub r1, r0, #2
	ldrb r1, [r5, r1]
	ldrb r2, [r5, r0]
	sub r1, r1, #1
	cmp r2, r1
	bge _021E9768
	add r1, r2, #1
	strb r1, [r5, r0]
	add r0, r5, #0
	add r5, #0x14
	mov r1, #1
	add r2, r5, #0
	mov r3, #0
	bl ov108_021EA584
	mov r0, #1
	str r0, [r4]
_021E9768:
	mov r0, #0
	pop {r3, r4, r5, pc}
_021E976C:
	ldr r1, _021E9798 ; =0x00000431
	ldrb r2, [r5, r1]
	cmp r0, r2
	beq _021E9784
	strb r0, [r5, r1]
	ldrb r1, [r5, r1]
	add r0, r5, #0
	bl ov108_021EA2EC
	add r0, r5, #0
	bl ov108_021EA47C
_021E9784:
	mov r0, #1
	str r0, [r4]
	ldr r1, _021E9798 ; =0x00000431
	add r0, r5, #0
	ldrb r1, [r5, r1]
	bl ov108_021E9528
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E9794: .word ov108_021EABF0
_021E9798: .word 0x00000431
	thumb_func_end ov108_021E96FC

	thumb_func_start ov108_021E979C
ov108_021E979C: ; 0x021E979C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _021E981C ; =0x00000434
	ldrb r1, [r4, r0]
	cmp r1, #0
	beq _021E97F4
	sub r2, r0, #4
	sub r1, r0, #3
	ldrb r3, [r4, r2]
	mov r2, #6
	ldrb r1, [r4, r1]
	mul r2, r3
	add r2, r1, r2
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	cmp r1, #6
	bhs _021E97C6
	sub r0, r0, #7
	ldrb r0, [r4, r0]
	cmp r2, r0
	blo _021E97D6
_021E97C6:
	mov r0, #0xce
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0x18
	mov r2, #0
	bl ov108_021E8EA4
	b _021E97EE
_021E97D6:
	mov r0, #0xcd
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	lsl r3, r2, #2
	add r3, r2, r3
	add r2, r1, r3
	add r0, r0, #4
	ldrb r1, [r1, r3]
	add r0, r4, r0
	add r2, r2, #2
	bl ov108_021E8EA4
_021E97EE:
	ldr r0, _021E981C ; =0x00000434
	mov r1, #0
	strb r1, [r4, r0]
_021E97F4:
	ldr r0, _021E9820 ; =0x0000043C
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E9800
	bl SpriteSystem_TransferOam
_021E9800:
	bl GF_RunVramTransferTasks
	ldr r0, _021E9824 ; =0x00000438
	ldr r0, [r4, r0]
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E9828 ; =0x027E0000
	ldr r1, _021E982C ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	nop
_021E981C: .word 0x00000434
_021E9820: .word 0x0000043C
_021E9824: .word 0x00000438
_021E9828: .word 0x027E0000
_021E982C: .word 0x00003FF8
	thumb_func_end ov108_021E979C

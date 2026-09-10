	.include "asm/macros.inc"
	.include "overlay_93_thumb_2.inc"
	.include "global.inc"

	.text
	.public _02262C6C
	.public ov93_0225FBF0
	.public ov93_0225FCA4
	.public ov93_0225FD8C
	.public ov93_0225FE08
	.public ov93_0225FEC4
	.public ov93_0225FF1C
	.public ov93_0225FFF8
	.public ov93_02260080
	.public ov93_0226027C
	.public ov93_02260314
	.public ov93_02260608
	.public ov93_02260660
	.public ov93_02260908
	.public ov93_02260984
	.public ov93_02260A8C
	.public ov93_02260AD8
	.public ov93_02260BB0
	.public ov93_02260BF0
	.public ov93_02260CF8
	.public ov93_02260E1C
	.public ov93_02260F3C
	.public ov93_02260FB8
	.public ov93_022610B0
	.public ov93_02261164
	.public ov93_02261310
	.public ov93_02261354
	.public ov93_02261554
	.public ov93_02261744
	.public ov93_022618C4
	.public ov93_02261BBC
	.public ov93_02261C58
	.public ov93_02261D3C
	.public ov93_02261EB8
	.public ov93_02261FC8
	.public ov93_02262034
	.public ov93_02262098
	.public ov93_022620D4
	.public ov93_02262130
	.public ov93_02262250
	.public ov93_02262374
	.public ov93_0226249C
	.public ov93_02262540
	.public ov93_022625BC
	.public ov93_02262760
	.public ov93_022627C0
	.public ov93_02262C72
	.public ov93_02262C7A
	.public ov93_02262C82
	.public ov93_02262C8A
	.public ov93_02262C94
	.public ov93_02262CA4
	.public ov93_02262CB4
	.public ov93_02262CB6
	.public ov93_02262CC4
	.public ov93_02262CC5
	.public ov93_02262CC6
	.public ov93_02262CD8
	.public ov93_02262CEC
	.public ov93_02262CEE
	.public ov93_02262CF0
	.public ov93_02262D04
	.public ov93_02262D2C
	.public ov93_02262D54
	.public ov93_02262D7C
	.public ov93_02262DA4
	.public ov93_02262DCC
	.public ov93_02262E00
	.public ov93_02262E34
	.public ov93_02262E68
	.public ov93_02262E9C
	.public ov93_02262ED0
	.public ov93_02262F04
	.public ov93_02262F38
	.public ov93_02262F6C
	.public ov93_02262FA0
	.public ov93_02262FD4
	.public ov93_02263010
	.public ov93_022630D8
	.public ov93_022630E4
	.public ov93_02263114
	.public ov93_0225FC8C
	.public ov93_0225FDF4
	.public ov93_0225FE5C
	.public ov93_0225FE80
	.public ov93_0225FEAC
	.public ov93_022602E4
	.public ov93_022609E0
	.public ov93_02260A14
	.public ov93_02260A30
	.public ov93_02260A58
	.public ov93_02260B70
	.public ov93_02260B84
	.public ov93_02260F14
	.public ov93_02260F84
	.public ov93_0226114C
	.public ov93_022612E0
	.public ov93_022614F4
	.public ov93_02261528
	.public ov93_02261538
	.public ov93_0226154C
	.public ov93_02261C3C
	.public ov93_02261D1C
	.public ov93_02261FB0
	.public ov93_02262108
	.public ov93_02262230
	.public ov93_02262310
	.public ov93_02262338
	.public ov93_02262344
	.public ov93_02262368
	.public ov93_02262444
	.public ov93_02262484
	.public ov93_02262598
	.public ov93_022626E8
	.public ov93_022626FC
	.public ov93_02262710
	.public ov93_02262714
	.public ov93_02262718
	.public ov93_02262724
	.public ov93_0226273C
	.public ov93_02262748
	.public ov93_022627A4
	.public ov93_022627E8
	.public ov93_02262814
	.public ov93_02262830
	.public ov93_02262860
	.public ov93_02262884
	.public ov93_022628B8
	.public ov93_022628F4
	.public ov93_02262920
	.public ov93_02262934
	.public ov93_02262960
	.public ov93_0226297C
	.public ov93_022629A8
	.public ov93_022629B8
	.public ov93_022629E4

	thumb_func_start ov93_0226249C
ov93_0226249C: ; 0x0226249C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, [r1]
	add r1, sp, #4
	mov r3, #0x16
	str r2, [sp]
	add r1, #2
	add r2, sp, #4
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	ldr r5, [sp]
	mov r4, #0
	add r6, sp, #4
	mov r7, #1
_022624BA:
	mov r2, #0
	ldrsh r2, [r6, r2]
	mov r1, #2
	mov r3, #0x16
	add r2, #0x1c
	lsl r2, r2, #0x10
	ldrsh r1, [r6, r1]
	ldr r0, [r5]
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r5]
	mov r1, #0x1b
	bl ManagedSprite_SetAnim
	ldr r0, [r5]
	mov r1, #1
	bl ManagedSprite_SetOamMode
	ldr r0, [r5]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	bl LCRandom
	lsr r1, r0, #0x1f
	lsl r2, r0, #0x14
	sub r2, r2, r1
	mov r0, #0x14
	ror r2, r0
	mov r0, #1
	add r1, r1, r2
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [r5, #8]
	bl LCRandom
	lsr r1, r0, #0x1f
	lsl r2, r0, #0x16
	sub r2, r2, r1
	mov r0, #0x16
	ror r2, r0
	mov r0, #1
	add r1, r1, r2
	lsl r0, r0, #0xa
	add r0, r1, r0
	str r0, [r5, #0x10]
	add r0, r4, #0
	tst r0, r7
	beq _0226252A
	mov r0, #0
	ldr r1, [r5, #8]
	mvn r0, r0
	mul r0, r1
	str r0, [r5, #8]
_0226252A:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _022624BA
	ldr r0, [sp]
	mov r1, #0
	strb r1, [r0, #0x19]
	mov r1, #1
	strb r1, [r0, #0x18]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov93_0226249C


	thumb_func_start ov93_02262540
ov93_02262540: ; 0x02262540
	push {r3, r4, r5, r6, r7, lr}
	add r6, r2, #0
	ldrb r0, [r6, #0x18]
	cmp r0, #0
	beq _02262594
	cmp r0, #1
	bne _02262594
	mov r4, #0
	add r5, r6, #0
_02262552:
	ldr r2, [r5, #0x10]
	ldr r0, [r5]
	ldr r1, [r5, #8]
	neg r2, r2
	bl ManagedSprite_AddSpritePrecisePositionXY
	ldr r0, [r5]
	ldr r0, [r0]
	bl Sprite_TickFrame
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _02262552
	ldrb r0, [r6, #0x19]
	add r0, r0, #1
	strb r0, [r6, #0x19]
	ldrb r0, [r6, #0x19]
	cmp r0, #8
	bls _02262594
	mov r5, #0
	add r4, r6, #0
	add r7, r5, #0
_02262580:
	ldr r0, [r4]
	add r1, r7, #0
	bl ManagedSprite_SetDrawFlag
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #2
	blt _02262580
	mov r0, #0
	strb r0, [r6, #0x18]
_02262594:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov93_02262540

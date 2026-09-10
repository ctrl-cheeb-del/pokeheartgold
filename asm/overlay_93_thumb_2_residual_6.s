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

	thumb_func_start ov93_02260A8C
ov93_02260A8C: ; 0x02260A8C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldrb r0, [r5, #6]
	mov r3, #0x16
	add r2, sp, #0
	lsl r1, r0, #4
	mov r0, #0x48
	sub r0, r0, r1
	lsl r0, r0, #0x10
	asr r4, r0, #0x10
	add r1, sp, #0
	ldr r0, [r5]
	add r1, #2
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #0
	mov r0, #2
	ldrsh r2, [r1, r0]
	cmp r4, r2
	ble _02260AD6
	add r2, r2, #2
	strh r2, [r1, #2]
	ldrsh r0, [r1, r0]
	cmp r0, r4
	ble _02260AC2
	strh r4, [r1, #2]
_02260AC2:
	add r3, sp, #0
	mov r1, #2
	mov r2, #0
	ldrsh r1, [r3, r1]
	ldrsh r2, [r3, r2]
	mov r3, #0x16
	ldr r0, [r5]
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
_02260AD6:
	pop {r3, r4, r5, pc}
	thumb_func_end ov93_02260A8C


	thumb_func_start ov93_02260AD8
ov93_02260AD8: ; 0x02260AD8
	push {r3, r4, r5, lr}
	add r4, r1, #0
	ldrb r1, [r4, #6]
	add r5, r0, #0
	cmp r1, #0
	bne _02260B66
	ldrb r1, [r4, #5]
	cmp r1, #1
	beq _02260B44
	cmp r1, #3
	bne _02260B66
	ldr r0, [r4]
	bl ManagedSprite_IsAnimated
	cmp r0, #0
	bne _02260B66
	mov r0, #8
	ldrsh r1, [r4, r0]
	add r1, r1, #5
	strh r1, [r4, #8]
	ldrsh r0, [r4, r0]
	bl ov93_02260B70
	strb r0, [r4, #4]
	mov r0, #1
	strb r0, [r4, #5]
	ldrb r1, [r4, #4]
	ldr r0, [r4]
	bl ManagedSprite_SetAnim
	mov r1, #7
	mov r3, #0x16
	ldr r0, [r4]
	mvn r1, r1
	mov r2, #0x20
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, _02260B68 ; =0x0000380C
	mov r2, #0
	add r3, r5, r0
	mov r1, #4
_02260B2C:
	ldrb r0, [r3, #6]
	cmp r0, #0
	bne _02260B36
	strb r1, [r3, #6]
	b _02260B3A
_02260B36:
	sub r0, r0, #1
	strb r0, [r3, #6]
_02260B3A:
	add r2, r2, #1
	add r3, #0xc
	cmp r2, #5
	blt _02260B2C
	pop {r3, r4, r5, pc}
_02260B44:
	bl ov93_0225FEAC
	ldrb r1, [r4, #5]
	cmp r1, #1
	bne _02260B66
	cmp r0, #0x4b
	ble _02260B66
	mov r0, #2
	strb r0, [r4, #5]
	ldrb r1, [r4, #4]
	ldr r0, [r4]
	add r1, r1, #3
	bl ManagedSprite_SetAnim
	ldr r0, _02260B6C ; =0x00000596
	bl PlaySE
_02260B66:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02260B68: .word 0x0000380C
_02260B6C: .word 0x00000596
	thumb_func_end ov93_02260AD8

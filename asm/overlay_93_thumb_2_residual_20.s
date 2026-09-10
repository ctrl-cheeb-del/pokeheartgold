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

	thumb_func_start ov93_022625BC
ov93_022625BC: ; 0x022625BC
	push {r3, r4, r5, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, [r4]
	add r1, r0, #0
	add r1, #0x3d
	ldrb r1, [r1]
	cmp r1, #1
	bne _02262642
	add r1, r0, #0
	add r1, #0x3e
	ldrb r1, [r1]
	cmp r1, #0
	beq _022625E4
	cmp r1, #1
	beq _02262606
	cmp r1, #2
	b _0226261E
_022625E4:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _022625F0
	bl sub_0200FB70
_022625F0:
	mov r0, #0
	bl sub_0200FC20
	ldr r1, [r4]
	add r0, r1, #0
	add r0, #0x3e
	ldrb r0, [r0]
	add r1, #0x3e
	add r0, r0, #1
	strb r0, [r1]
	b _0226263E
_02262606:
	bl ov90_02258B98
	cmp r0, #1
	bne _0226263E
	ldr r1, [r4]
	add r0, r1, #0
	add r0, #0x3e
	ldrb r0, [r0]
	add r1, #0x3e
	add r0, r0, #1
	strb r0, [r1]
	b _0226263E
_0226261E:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _0226262C
	bl ov90_02258938
	mov r0, #0
	str r0, [r4, #4]
_0226262C:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0226263A
	bl ov90_02258A04
	mov r0, #0
	str r0, [r4, #8]
_0226263A:
	mov r0, #1
	pop {r3, r4, r5, pc}
_0226263E:
	mov r0, #0
	pop {r3, r4, r5, pc}
_02262642:
	ldr r1, [r5]
	cmp r1, #5
	bhi _022626E0
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02262654: ; jump table
	.short _02262660 - _02262654 - 2 ; case 0
	.short _02262674 - _02262654 - 2 ; case 1
	.short _02262684 - _02262654 - 2 ; case 2
	.short _022626A8 - _02262654 - 2 ; case 3
	.short _022626BC - _02262654 - 2 ; case 4
	.short _022626E0 - _02262654 - 2 ; case 5
_02262660:
	add r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0226266E
	mov r0, #1
	str r0, [r5]
	b _022626E4
_0226266E:
	mov r0, #3
	str r0, [r5]
	b _022626E4
_02262674:
	mov r1, #0x75
	bl ov90_0225892C
	str r0, [r4, #4]
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _022626E4
_02262684:
	ldr r0, [r4, #4]
	bl ov90_022589BC
	cmp r0, #1
	bne _022626E4
	ldr r0, [r4, #4]
	bl ov90_022589CC
	ldr r1, [r4]
	str r0, [r1, #0x34]
	ldr r0, [r4, #4]
	bl ov90_02258938
	mov r0, #0
	str r0, [r4, #4]
	mov r0, #5
	str r0, [r5]
	b _022626E4
_022626A8:
	add r1, r0, #0
	add r1, #0x10
	mov r2, #0x75
	bl ov90_022589F8
	str r0, [r4, #8]
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _022626E4
_022626BC:
	ldr r0, [r4, #8]
	bl ov90_02258AA0
	cmp r0, #1
	bne _022626E4
	ldr r0, [r4, #8]
	bl ov90_02258AA4
	ldr r1, [r4]
	str r0, [r1, #0x38]
	ldr r0, [r4, #8]
	bl ov90_02258A04
	mov r0, #0
	str r0, [r4, #8]
	mov r0, #5
	str r0, [r5]
	b _022626E4
_022626E0:
	mov r0, #1
	pop {r3, r4, r5, pc}
_022626E4:
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov93_022625BC

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

	thumb_func_start ov93_0225FCA4
ov93_0225FCA4: ; 0x0225FCA4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r1, #0
	str r0, [sp, #4]
	ldr r0, [r5]
	cmp r0, #0
	beq _0225FD86
	add r0, sp, #0xc
	str r0, [sp]
	add r0, r2, #0
	ldr r1, [r5, #4]
	ldr r2, [r5, #8]
	add r3, sp, #0x10
	bl ov93_0225FD8C
	mov r0, #1
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0xc
	cmp r1, r0
	bne _0225FCD0
	mov r7, #0
	b _0225FCF0
_0225FCD0:
	bge _0225FCE2
	lsl r1, r1, #7
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r0, #0xc
	mov r0, #0x80
	sub r7, r0, r1
	b _0225FCF0
_0225FCE2:
	sub r0, r1, r0
	lsl r1, r0, #7
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	neg r7, r0
_0225FCF0:
	mov r0, #1
	ldr r1, [sp, #0xc]
	lsl r0, r0, #0xc
	cmp r1, r0
	bne _0225FCFE
	mov r6, #0
	b _0225FD1E
_0225FCFE:
	bge _0225FD10
	lsl r1, r1, #7
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r1, r0, #0xc
	mov r0, #0x80
	sub r6, r0, r1
	b _0225FD1E
_0225FD10:
	sub r0, r1, r0
	lsl r1, r0, #7
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r0, r0, #0xc
	neg r6, r0
_0225FD1E:
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _0225FD28
	mov r4, #0
	b _0225FD44
_0225FD28:
	bl LCRandom
	mov r1, #7
	and r0, r1
	add r4, r0, #1
	ldr r1, [r5, #0x28]
	mov r0, #1
	tst r0, r1
	beq _0225FD3C
	neg r4, r4
_0225FD3C:
	ldr r1, [r5, #0x28]
	mov r0, #1
	eor r0, r1
	str r0, [r5, #0x28]
_0225FD44:
	ldr r0, [sp, #0x10]
	bl FX_Inv
	add r5, r0, #0
	ldr r0, [sp, #0xc]
	bl FX_Inv
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	mov r1, #7
	mov r2, #3
	add r3, r5, #0
	bl ScheduleSetBgAffineScale
	ldr r0, [sp, #4]
	ldr r3, [sp, #8]
	mov r1, #7
	mov r2, #6
	bl ScheduleSetBgAffineScale
	ldr r0, [sp, #4]
	mov r1, #7
	mov r2, #0
	sub r3, r4, r7
	bl ScheduleSetBgPosText
	mov r3, #0x27
	ldr r0, [sp, #4]
	mov r1, #7
	mov r2, #3
	sub r3, r3, r6
	bl ScheduleSetBgPosText
_0225FD86:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov93_0225FCA4


	thumb_func_start ov93_0225FD8C
ov93_0225FD8C: ; 0x0225FD8C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r3, #0
	ldr r0, _0225FDE8 ; =ov93_02262CF0
	lsl r3, r1, #3
	ldr r0, [r0, r3]
	add r6, r5, #0
	mul r0, r2
	mov r2, #0xc
	mul r6, r2
	ldr r3, _0225FDEC ; =ov93_02262FD4
	lsl r2, r1, #2
	add r1, r3, r6
	ldr r1, [r2, r1]
	bl _s32_div_f
	mov r1, #3
	lsl r1, r1, #8
	add r2, r0, r1
	ldr r1, [sp, #0x10]
	str r2, [r4]
	str r2, [r1]
	mov r1, #1
	lsl r1, r1, #0xc
	cmp r2, r1
	ble _0225FDE6
	mov r1, #0xd
	lsl r1, r1, #8
	sub r0, r0, r1
	ldr r2, _0225FDF0 ; =0x0000119A
	asr r1, r0, #0x1f
	mov r3, #0
	bl _ll_mul
	mov r3, #2
	mov r5, #0
	lsl r3, r3, #0xa
	add r3, r0, r3
	adc r1, r5
	lsl r0, r1, #0x14
	lsr r1, r3, #0xc
	ldr r2, [r4]
	orr r1, r0
	add r0, r2, r1
	str r0, [r4]
_0225FDE6:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0225FDE8: .word ov93_02262CF0
_0225FDEC: .word ov93_02262FD4
_0225FDF0: .word 0x0000119A
	thumb_func_end ov93_0225FD8C

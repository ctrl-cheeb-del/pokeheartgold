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
	.public ov93_02260608
	.public ov93_02260908
	.public ov93_02260984


	thumb_func_start ov93_02260660
ov93_02260660: ; 0x02260660
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	ldr r1, _022608FC ; =0x0000339C
	mov r4, #0
	add r0, r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r0]
	cmp r0, #0
	bne _02260678
	add sp, #0x34
	add r0, r4, #0
	pop {r4, r5, r6, r7, pc}
_02260678:
	ldr r0, [sp, #0x18]
	str r4, [sp, #0x14]
	add r5, r0, #4
_0226067E:
	ldr r0, [r5]
	cmp r0, #0
	beq _0226073A
	mov r1, #0x14
	ldrsh r1, [r5, r1]
	cmp r1, #0
	bne _02260696
	bl Sprite_DeleteAndFreeResources
	mov r0, #0
	str r0, [r5]
	b _0226073A
_02260696:
	ldr r1, [r5, #0xc]
	ldr r0, [r5, #0x10]
	add r0, r1, r0
	str r0, [r5, #0xc]
	ldr r1, [r5, #4]
	ldr r0, [r5, #8]
	add r1, r1, r0
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r1, [r5, #4]
	cmp r1, r0
	blt _022606B0
	str r0, [r5, #4]
_022606B0:
	ldr r0, [r5, #0xc]
	ldr r6, [r5, #4]
	bl GF_SinDegFX32
	add r7, r0, #0
	ldr r0, [r5, #4]
	str r0, [sp, #0x10]
	ldr r0, [r5, #0xc]
	bl GF_CosDegFX32
	str r0, [sp, #0x1c]
	asr r1, r7, #0x1f
	add r0, r7, #0
	asr r3, r6, #0x1f
	add r2, r6, #0
	bl _ll_mul
	str r0, [sp, #0x28]
	ldr r2, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	add r6, r1, #0
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	add r2, r1, #0
	mov r3, #2
	add r7, r0, #0
	ldr r1, [sp, #0x28]
	lsl r3, r3, #0xa
	add r3, r1, r3
	ldr r1, _02260900 ; =0
	ldr r0, [r5]
	adc r6, r1
	lsl r1, r6, #0x14
	lsr r3, r3, #0xc
	orr r3, r1
	asr r1, r3, #0xb
	lsr r1, r1, #0x14
	add r1, r3, r1
	asr r1, r1, #0xc
	add r1, #0x80
	mov r3, #2
	lsl r1, r1, #0x10
	ldr r6, _02260900 ; =0
	lsl r3, r3, #0xa
	asr r1, r1, #0x10
	add r3, r7, r3
	adc r2, r6
	lsl r2, r2, #0x14
	lsr r3, r3, #0xc
	orr r3, r2
	neg r3, r3
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r2, r2, #0xc
	add r2, #0x60
	lsl r2, r2, #0x10
	mov r3, #0x16
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	mov r0, #0x14
	ldrsh r0, [r5, r0]
	add r4, r4, #1
	sub r0, r0, #1
	strh r0, [r5, #0x14]
_0226073A:
	ldr r0, [sp, #0x14]
	add r5, #0x18
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #0x24
	blt _0226067E
	mov r0, #0
	str r0, [sp]
	mov r1, #0xd9
	ldr r0, [sp, #0x18]
	lsl r1, r1, #2
	add r5, r0, r1
_02260752:
	ldr r0, [r5]
	cmp r0, #0
	beq _0226080E
	mov r1, #0x14
	ldrsh r1, [r5, r1]
	cmp r1, #0
	bne _0226076A
	bl Sprite_DeleteAndFreeResources
	mov r0, #0
	str r0, [r5]
	b _0226080E
_0226076A:
	ldr r1, [r5, #0xc]
	ldr r0, [r5, #0x10]
	add r0, r1, r0
	str r0, [r5, #0xc]
	ldr r1, [r5, #4]
	ldr r0, [r5, #8]
	add r1, r1, r0
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r1, [r5, #4]
	cmp r1, r0
	blt _02260784
	str r0, [r5, #4]
_02260784:
	ldr r0, [r5, #0xc]
	ldr r6, [r5, #4]
	bl GF_SinDegFX32
	add r7, r0, #0
	ldr r0, [r5, #4]
	str r0, [sp, #0xc]
	ldr r0, [r5, #0xc]
	bl GF_CosDegFX32
	str r0, [sp, #0x20]
	asr r1, r7, #0x1f
	add r0, r7, #0
	asr r3, r6, #0x1f
	add r2, r6, #0
	bl _ll_mul
	str r0, [sp, #0x2c]
	ldr r2, [sp, #0xc]
	ldr r0, [sp, #0x20]
	add r6, r1, #0
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	add r2, r1, #0
	mov r3, #2
	add r7, r0, #0
	ldr r1, [sp, #0x2c]
	lsl r3, r3, #0xa
	add r3, r1, r3
	ldr r1, _02260900 ; =0
	ldr r0, [r5]
	adc r6, r1
	lsl r1, r6, #0x14
	lsr r3, r3, #0xc
	orr r3, r1
	asr r1, r3, #0xb
	lsr r1, r1, #0x14
	add r1, r3, r1
	asr r1, r1, #0xc
	add r1, #0x80
	mov r3, #2
	lsl r1, r1, #0x10
	ldr r6, _02260900 ; =0
	lsl r3, r3, #0xa
	asr r1, r1, #0x10
	add r3, r7, r3
	adc r2, r6
	lsl r2, r2, #0x14
	lsr r3, r3, #0xc
	orr r3, r2
	neg r3, r3
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r2, r2, #0xc
	add r2, #0x60
	lsl r2, r2, #0x10
	mov r3, #0x16
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	mov r0, #0x14
	ldrsh r0, [r5, r0]
	add r4, r4, #1
	sub r0, r0, #1
	strh r0, [r5, #0x14]
_0226080E:
	ldr r0, [sp]
	add r5, #0x18
	add r0, r0, #1
	str r0, [sp]
	cmp r0, #8
	blt _02260752
	mov r0, #0
	str r0, [sp, #4]
	ldr r1, _02260904 ; =0x00000424
	ldr r0, [sp, #0x18]
	add r5, r0, r1
_02260824:
	ldr r0, [r5]
	cmp r0, #0
	beq _022608E0
	mov r1, #0x14
	ldrsh r1, [r5, r1]
	cmp r1, #0
	bne _0226083C
	bl Sprite_DeleteAndFreeResources
	mov r0, #0
	str r0, [r5]
	b _022608E0
_0226083C:
	ldr r1, [r5, #0xc]
	ldr r0, [r5, #0x10]
	add r0, r1, r0
	str r0, [r5, #0xc]
	ldr r1, [r5, #4]
	ldr r0, [r5, #8]
	add r1, r1, r0
	mov r0, #0xa
	lsl r0, r0, #0x10
	str r1, [r5, #4]
	cmp r1, r0
	blt _02260856
	str r0, [r5, #4]
_02260856:
	ldr r0, [r5, #0xc]
	ldr r6, [r5, #4]
	bl GF_SinDegFX32
	add r7, r0, #0
	ldr r0, [r5, #4]
	str r0, [sp, #8]
	ldr r0, [r5, #0xc]
	bl GF_CosDegFX32
	str r0, [sp, #0x24]
	asr r1, r7, #0x1f
	add r0, r7, #0
	asr r3, r6, #0x1f
	add r2, r6, #0
	bl _ll_mul
	str r0, [sp, #0x30]
	ldr r2, [sp, #8]
	ldr r0, [sp, #0x24]
	add r6, r1, #0
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	add r2, r1, #0
	mov r3, #2
	add r7, r0, #0
	ldr r1, [sp, #0x30]
	lsl r3, r3, #0xa
	add r3, r1, r3
	ldr r1, _02260900 ; =0
	ldr r0, [r5]
	adc r6, r1
	lsl r1, r6, #0x14
	lsr r3, r3, #0xc
	orr r3, r1
	asr r1, r3, #0xb
	lsr r1, r1, #0x14
	add r1, r3, r1
	asr r1, r1, #0xc
	add r1, #0x80
	mov r3, #2
	lsl r1, r1, #0x10
	ldr r6, _02260900 ; =0
	lsl r3, r3, #0xa
	asr r1, r1, #0x10
	add r3, r7, r3
	adc r2, r6
	lsl r2, r2, #0x14
	lsr r3, r3, #0xc
	orr r3, r2
	neg r3, r3
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	asr r2, r2, #0xc
	add r2, #0x60
	lsl r2, r2, #0x10
	mov r3, #0x16
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	mov r0, #0x14
	ldrsh r0, [r5, r0]
	add r4, r4, #1
	sub r0, r0, #1
	strh r0, [r5, #0x14]
_022608E0:
	ldr r0, [sp, #4]
	add r5, #0x18
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #3
	blt _02260824
	cmp r4, #0
	bne _022608F6
	ldr r0, [sp, #0x18]
	mov r1, #0
	str r1, [r0]
_022608F6:
	mov r0, #1
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022608FC: .word 0x0000339C
_02260900: .word 0
_02260904: .word 0x00000424
	thumb_func_end ov93_02260660

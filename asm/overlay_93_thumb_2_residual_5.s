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

	thumb_func_start ov93_02260314
ov93_02260314: ; 0x02260314
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x68
	ldr r5, _022605F8 ; =ov93_02262E00
	str r2, [sp, #4]
	add r7, r0, #0
	str r1, [sp]
	mov r4, #0
	add r3, sp, #0x34
	mov r2, #6
_02260326:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02260326
	ldr r0, [r5]
	str r0, [r3]
	ldr r0, [sp, #4]
	ldr r0, [r0, #8]
	str r0, [sp, #0x14]
	ldr r0, [sp, #4]
	ldr r0, [r0, #0x10]
	str r0, [sp, #0x18]
	mov r0, #0
	str r0, [sp, #0xc]
	b _0226044C
_02260344:
	ldr r2, [r7]
	ldr r1, [sp, #0xc]
	add r0, r7, #0
	add r1, r2, r1
	add r1, #0x2c
	ldrb r1, [r1]
	bl ov93_0225E3C4
	add r5, r0, #0
	ldr r0, [sp, #4]
	lsl r1, r5, #2
	add r0, r0, r1
	ldr r1, [r0, #0x18]
	mov r0, #0x24
	mul r0, r1
	ldr r2, [sp, #0x14]
	ldr r1, [sp, #0x18]
	add r1, r2, r1
	bl _s32_div_f
	ldr r1, [sp, #0xc]
	lsl r5, r5, #1
	lsl r2, r1, #2
	add r1, sp, #0x24
	str r0, [r1, r2]
	ldr r0, [r7]
	add r0, #0x30
	ldrb r0, [r0]
	lsl r3, r0, #3
	ldr r0, _022605FC ; =ov93_02262D7C
	add r0, r0, r3
	ldrh r0, [r5, r0]
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp]
	add r0, r0, #4
	str r0, [sp, #0x1c]
	ldr r0, [r1, r2]
	str r0, [sp, #0x20]
	b _0226043E
_02260396:
	mov r0, #0x18
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #0x1c]
	add r2, sp, #0x34
	add r5, r0, r1
	ldr r0, [r7, #0x24]
	ldr r1, [r7, #0x28]
	bl SpriteSystem_NewSprite
	add r6, r0, #0
	beq _02260446
	mov r3, #0x16
	mov r1, #0x80
	mov r2, #0x60
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r1, [sp, #0x10]
	add r0, r6, #0
	bl ManagedSprite_SetAnim
	ldr r0, [r6]
	bl Sprite_TickFrame
	bl LCRandom
	lsr r1, r0, #0x1f
	lsl r2, r0, #0x13
	sub r2, r2, r1
	mov r0, #0x13
	ror r2, r0
	mov r0, #2
	add r1, r1, r2
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [r5, #4]
	bl LCRandom
	lsr r1, r0, #0x1f
	lsl r2, r0, #0x12
	sub r2, r2, r1
	mov r0, #0x12
	ror r2, r0
	mov r0, #2
	add r1, r1, r2
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [r5, #8]
	bl LCRandom
	mov r1, #0x5a
	lsl r1, r1, #2
	bl _s32_div_f
	lsl r0, r1, #0xc
	str r0, [r5, #0xc]
	bl LCRandom
	mov r1, #5
	lsl r1, r1, #0xe
	bl _s32_div_f
	mov r0, #0xa
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [r5, #0x10]
	bl LCRandom
	mov r1, #0xf
	bl _s32_div_f
	add r1, #0x14
	strh r1, [r5, #0x14]
	add r1, r4, #0
	mov r0, #0x18
	mul r1, r0
	ldr r0, [sp]
	add r4, r4, #1
	add r0, r0, r1
	str r6, [r0, #4]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
_0226043E:
	ldr r1, [sp, #8]
	ldr r0, [sp, #0x20]
	cmp r1, r0
	blt _02260396
_02260446:
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
_0226044C:
	ldr r0, [r7]
	add r0, #0x30
	ldrb r1, [r0]
	ldr r0, [sp, #0xc]
	cmp r0, r1
	bge _0226045A
	b _02260344
_0226045A:
	mov r0, #0xe
	str r0, [sp, #0x3c]
	mov r0, #0
	mov r1, #0xd9
	str r0, [sp, #0xc]
	str r0, [sp, #0x40]
	ldr r0, [sp]
	lsl r1, r1, #2
	add r6, r0, r1
	b _02260522
_0226046E:
	ldr r1, [sp, #0xc]
	mov r0, #0x18
	mul r0, r1
	add r4, r6, r0
	ldr r0, [r7, #0x24]
	ldr r1, [r7, #0x28]
	add r2, sp, #0x34
	bl SpriteSystem_NewSprite
	add r5, r0, #0
	beq _02260528
	mov r3, #0x16
	mov r1, #0x80
	mov r2, #0x60
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	bl LCRandom
	mov r1, #3
	bl _s32_div_f
	add r0, r5, #0
	add r1, #0x1c
	bl ManagedSprite_SetAnim
	ldr r0, [r5]
	bl Sprite_TickFrame
	bl LCRandom
	lsr r1, r0, #0x1f
	lsl r2, r0, #0x13
	sub r2, r2, r1
	mov r0, #0x13
	ror r2, r0
	mov r0, #2
	add r1, r1, r2
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [r4, #4]
	bl LCRandom
	lsr r1, r0, #0x1f
	lsl r2, r0, #0x12
	sub r2, r2, r1
	mov r0, #0x12
	ror r2, r0
	mov r0, #2
	add r1, r1, r2
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [r4, #8]
	bl LCRandom
	mov r1, #0x5a
	lsl r1, r1, #2
	bl _s32_div_f
	lsl r0, r1, #0xc
	str r0, [r4, #0xc]
	bl LCRandom
	mov r1, #5
	lsl r1, r1, #0xe
	bl _s32_div_f
	mov r0, #1
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [r4, #0x10]
	bl LCRandom
	mov r1, #0xf
	bl _s32_div_f
	add r1, #0x14
	strh r1, [r4, #0x14]
	ldr r1, [sp, #0xc]
	mov r0, #0x18
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp]
	add r1, r0, r2
	mov r0, #0xd9
	lsl r0, r0, #2
	str r5, [r1, r0]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
_02260522:
	ldr r0, [sp, #0xc]
	cmp r0, #8
	blt _0226046E
_02260528:
	mov r0, #0xd
	str r0, [sp, #0x3c]
	ldr r0, [sp, #4]
	ldr r0, [r0, #4]
	lsl r1, r0, #1
	ldr r0, _02260600 ; =_02262C6C
	ldrh r0, [r0, r1]
	ldr r1, _02260604 ; =0x00000424
	str r0, [sp, #0x40]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp]
	add r6, r0, r1
	b _022605EC
_02260544:
	ldr r1, [sp, #0xc]
	mov r0, #0x18
	mul r0, r1
	add r4, r6, r0
	ldr r0, [r7, #0x24]
	ldr r1, [r7, #0x28]
	add r2, sp, #0x34
	bl SpriteSystem_NewSprite
	add r5, r0, #0
	beq _022605F2
	mov r3, #0x16
	mov r1, #0x80
	mov r2, #0x60
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add r0, r5, #0
	mov r1, #0xb
	bl ManagedSprite_SetAnim
	ldr r0, [r5]
	bl Sprite_TickFrame
	bl LCRandom
	lsr r1, r0, #0x1f
	lsl r2, r0, #0x13
	sub r2, r2, r1
	mov r0, #0x13
	ror r2, r0
	mov r0, #2
	add r1, r1, r2
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [r4, #4]
	bl LCRandom
	lsr r1, r0, #0x1f
	lsl r2, r0, #0x12
	sub r2, r2, r1
	mov r0, #0x12
	ror r2, r0
	mov r0, #2
	add r1, r1, r2
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [r4, #8]
	bl LCRandom
	mov r1, #0x5a
	lsl r1, r1, #2
	bl _s32_div_f
	lsl r0, r1, #0xc
	str r0, [r4, #0xc]
	bl LCRandom
	mov r1, #5
	lsl r1, r1, #0xe
	bl _s32_div_f
	mov r0, #1
	lsl r0, r0, #0x10
	add r0, r1, r0
	str r0, [r4, #0x10]
	bl LCRandom
	mov r1, #0xf
	bl _s32_div_f
	add r1, #0x14
	strh r1, [r4, #0x14]
	ldr r1, [sp, #0xc]
	mov r0, #0x18
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp]
	add r1, r0, r2
	ldr r0, _02260604 ; =0x00000424
	str r5, [r1, r0]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
_022605EC:
	ldr r0, [sp, #0xc]
	cmp r0, #3
	blt _02260544
_022605F2:
	add sp, #0x68
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022605F8: .word ov93_02262E00
_022605FC: .word ov93_02262D7C
_02260600: .word _02262C6C
_02260604: .word 0x00000424
	thumb_func_end ov93_02260314


	thumb_func_start ov93_02260608
ov93_02260608: ; 0x02260608
	push {r4, r5, r6, lr}
	add r6, r0, #0
	ldr r0, _0226065C ; =0x000033A0
	mov r4, #0
	add r5, r6, r0
_02260612:
	ldr r0, [r5]
	cmp r0, #0
	beq _0226061C
	bl Sprite_DeleteAndFreeResources
_0226061C:
	add r4, r4, #1
	add r5, #0x18
	cmp r4, #0x24
	blt _02260612
	mov r0, #0x37
	lsl r0, r0, #8
	mov r5, #0
	add r4, r6, r0
_0226062C:
	ldr r0, [r4]
	cmp r0, #0
	beq _02260636
	bl Sprite_DeleteAndFreeResources
_02260636:
	add r5, r5, #1
	add r4, #0x18
	cmp r5, #8
	blt _0226062C
	mov r0, #0xdf
	lsl r0, r0, #6
	mov r4, #0
	add r5, r6, r0
_02260646:
	ldr r0, [r5]
	cmp r0, #0
	beq _02260650
	bl Sprite_DeleteAndFreeResources
_02260650:
	add r4, r4, #1
	add r5, #0x18
	cmp r4, #3
	blt _02260646
	pop {r4, r5, r6, pc}
	nop
_0226065C: .word 0x000033A0
	thumb_func_end ov93_02260608


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


	thumb_func_start ov93_02260908
ov93_02260908: ; 0x02260908
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _02260970 ; =0x0000339C
	add r4, r5, r0
	ldr r0, [r4]
	cmp r0, #1
	bne _0226091A
	mov r0, #0
	pop {r3, r4, r5, pc}
_0226091A:
	mov r2, #0x47
	add r0, r4, #0
	mov r1, #0
	lsl r2, r2, #4
	bl MI_CpuFill8
	ldr r1, _02260970 ; =0x0000339C
	ldr r2, _02260974 ; =0x00001428
	add r0, r5, #0
	add r1, r5, r1
	add r2, r5, r2
	bl ov93_02260314
	ldr r1, _02260974 ; =0x00001428
	ldr r0, [r5, #0x2c]
	add r1, r5, r1
	bl ov93_0225FC8C
	add r0, r5, #0
	bl ov93_02260B84
	mov r2, #0
	ldr r0, _02260978 ; =0x00002FCC
	add r1, r2, #0
	str r2, [r5, r0]
	ldr r0, _0226097C ; =0x00001430
	str r2, [r5, r0]
	add r0, #8
	str r2, [r5, r0]
	mov r0, #0x51
	lsl r0, r0, #6
_02260958:
	add r2, r2, #1
	str r1, [r5, r0]
	add r5, r5, #4
	cmp r2, #4
	blt _02260958
	ldr r0, _02260980 ; =0x00000594
	bl PlaySE
	mov r0, #1
	str r0, [r4]
	pop {r3, r4, r5, pc}
	nop
_02260970: .word 0x0000339C
_02260974: .word 0x00001428
_02260978: .word 0x00002FCC
_0226097C: .word 0x00001430
_02260980: .word 0x00000594
	thumb_func_end ov93_02260908


	thumb_func_start ov93_02260984
ov93_02260984: ; 0x02260984
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	ldr r6, _022609DC ; =ov93_02262E34
	add r4, r2, #0
	add r3, r0, #0
	add r7, r1, #0
	add r5, sp, #0
	mov r2, #6
_02260994:
	ldmia r6!, {r0, r1}
	stmia r5!, {r0, r1}
	sub r2, r2, #1
	bne _02260994
	ldr r0, [r6]
	add r2, sp, #0
	str r0, [r5]
	ldr r0, [r3, #0x24]
	ldr r1, [r3, #0x28]
	bl SpriteSystem_NewSprite
	mov r3, #0x16
	lsl r2, r4, #4
	mov r1, #0x48
	sub r1, r1, r2
	lsl r1, r1, #0x10
	add r5, r0, #0
	asr r1, r1, #0x10
	mov r2, #0x20
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add r0, r5, #0
	add r1, r7, #0
	bl ManagedSprite_SetAnim
	ldr r0, [r5]
	bl Sprite_TickFrame
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
	add r0, r5, #0
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022609DC: .word ov93_02262E34
	thumb_func_end ov93_02260984

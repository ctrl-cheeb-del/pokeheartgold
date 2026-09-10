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

	thumb_func_start ov93_02261554
ov93_02261554: ; 0x02261554
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r5, r2, #0
	mov r0, #0x1c
	ldrsh r0, [r5, r0]
	add r1, sp, #0
	strh r0, [r1, #2]
	mov r0, #0x1e
	ldrsh r0, [r5, r0]
	strh r0, [r1]
	ldrb r0, [r5, #0x11]
	cmp r0, #0
	beq _02261574
	cmp r0, #1
	beq _022615A8
	b _02261732
_02261574:
	ldr r0, [r5]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #8]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r1, sp, #0
	mov r3, #0x16
	ldr r0, [r5]
	add r1, #2
	add r2, sp, #0
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #0
	mov r0, #2
	ldrsh r0, [r1, r0]
	strh r0, [r5, #0x1c]
	mov r0, #0
	ldrsh r0, [r1, r0]
	strh r0, [r5, #0x1e]
	ldrb r0, [r5, #0x11]
	add r0, r0, #1
	strb r0, [r5, #0x11]
_022615A8:
	mov r1, #0x5a
	ldr r2, [r5, #0xc]
	lsl r1, r1, #0xc
	cmp r2, r1
	bgt _022615BA
	bge _022615EC
	cmp r2, #0
	beq _022615CC
	b _02261654
_022615BA:
	lsl r0, r1, #1
	cmp r2, r0
	bgt _022615C4
	beq _02261614
	b _02261654
_022615C4:
	ldr r0, _0226173C ; =0x0010E000
	cmp r2, r0
	beq _02261634
	b _02261654
_022615CC:
	mov r0, #0x1e
	ldrsh r0, [r5, r0]
	ldrb r1, [r5, #0x12]
	add r0, #0x20
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	mul r0, r1
	mov r1, #0xf
	bl _s32_div_f
	lsl r0, r0, #0x10
	asr r1, r0, #0x10
	sub r1, #0x20
	add r0, sp, #0
	strh r1, [r0]
	b _02261658
_022615EC:
	mov r0, #0x1c
	ldrsh r2, [r5, r0]
	mov r0, #0x12
	lsl r0, r0, #4
	sub r0, r2, r0
	lsl r0, r0, #0x10
	ldrb r1, [r5, #0x12]
	asr r0, r0, #0x10
	mul r0, r1
	mov r1, #0xf
	bl _s32_div_f
	lsl r0, r0, #0x10
	asr r1, r0, #0x10
	mov r0, #0x12
	lsl r0, r0, #4
	add r1, r1, r0
	add r0, sp, #0
	strh r1, [r0, #2]
	b _02261658
_02261614:
	mov r0, #0x1e
	ldrsh r0, [r5, r0]
	ldrb r1, [r5, #0x12]
	sub r0, #0xe4
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	mul r0, r1
	mov r1, #0xf
	bl _s32_div_f
	lsl r0, r0, #0x10
	asr r1, r0, #0x10
	add r1, #0xe4
	add r0, sp, #0
	strh r1, [r0]
	b _02261658
_02261634:
	mov r0, #0x1c
	ldrsh r0, [r5, r0]
	ldrb r1, [r5, #0x12]
	add r0, #0x20
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	mul r0, r1
	mov r1, #0xf
	bl _s32_div_f
	lsl r0, r0, #0x10
	asr r1, r0, #0x10
	sub r1, #0x20
	add r0, sp, #0
	strh r1, [r0, #2]
	b _02261658
_02261654:
	bl GF_AssertFail
_02261658:
	ldrb r1, [r5, #0x12]
	cmp r1, #0xf
	blo _022616A0
	mov r1, #0x1c
	mov r2, #0x1e
	mov r3, #0x16
	ldrsh r1, [r5, r1]
	ldrsh r2, [r5, r2]
	ldr r0, [r5]
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	mov r2, #0x1e
	ldrsh r2, [r5, r2]
	mov r1, #0x1c
	mov r3, #0x16
	add r2, #0x18
	lsl r2, r2, #0x10
	ldrsh r1, [r5, r1]
	ldr r0, [r5, #8]
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add r0, r5, #0
	mov r1, #2
	bl ov93_02261528
	add r1, r5, #0
	add r5, #0x30
	add r0, r4, #0
	add r2, r5, #0
	bl ov93_0226249C
	mov r0, #1
	pop {r3, r4, r5, pc}
_022616A0:
	mov r0, #0xb4
	mul r0, r1
	lsl r0, r0, #0xc
	mov r1, #0xf
	bl _s32_div_f
	bl GF_SinDegFX32
	mov r2, #6
	asr r1, r0, #0x1f
	lsl r2, r2, #0xe
	mov r3, #0
	bl _ll_mul
	mov r3, #2
	mov r2, #0
	lsl r3, r3, #0xa
	add r3, r0, r3
	adc r1, r2
	lsl r0, r1, #0x14
	lsr r1, r3, #0xc
	orr r1, r0
	neg r1, r1
	asr r0, r1, #0xb
	add r3, sp, #0
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r4, r0, #0xc
	ldrsh r2, [r3, r2]
	mov r1, #2
	ldrsh r1, [r3, r1]
	add r2, r2, r4
	lsl r2, r2, #0x10
	mov r3, #0x16
	ldr r0, [r5]
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	add r3, sp, #0
	mov r2, #0
	ldrsh r2, [r3, r2]
	mov r1, #2
	ldrsh r1, [r3, r1]
	add r2, #0x18
	lsl r2, r2, #0x10
	mov r3, #0x16
	ldr r0, [r5, #8]
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	neg r0, r4
	mov r1, #3
	bl _s32_div_f
	lsl r0, r0, #0xc
	mov r1, #0x18
	bl _s32_div_f
	mov r1, #1
	lsl r1, r1, #0xc
	sub r0, r1, r0
	bl _fflt
	ldr r1, _02261740 ; =0x45800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, [r5, #8]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
_02261732:
	ldrb r0, [r5, #0x12]
	add r0, r0, #1
	strb r0, [r5, #0x12]
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0226173C: .word 0x0010E000
_02261740: .word 0x45800000
	thumb_func_end ov93_02261554


	thumb_func_start ov93_02261744
ov93_02261744: ; 0x02261744
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	str r0, [sp]
	add r0, r5, #0
	add r0, #0xf3
	ldrb r0, [r0]
	add r4, r2, #0
	cmp r0, #0
	beq _02261774
	add r1, #0xf4
	ldrb r1, [r1]
	mov r0, #0xb
	lsl r0, r0, #0xe
	lsl r2, r1, #2
	ldr r1, _022618BC ; =ov93_02262CC4
	ldrb r1, [r1, r2]
	bl _s32_div_f
	add r1, r0, #0
	ldr r0, [r4]
	bl ManagedSprite_TickNFrames
	b _0226177C
_02261774:
	ldr r0, [r4]
	mov r1, #0
	bl ManagedSprite_SetAnimationFrame
_0226177C:
	add r0, r5, #0
	add r0, #0xf3
	ldrb r1, [r0]
	mov r0, #0xb4
	mul r0, r1
	add r1, r5, #0
	add r1, #0xf4
	ldrb r1, [r1]
	lsl r0, r0, #0xc
	lsl r2, r1, #2
	ldr r1, _022618BC ; =ov93_02262CC4
	ldrb r1, [r1, r2]
	bl _s32_div_f
	bl GF_SinDegFX32
	mov r2, #3
	asr r1, r0, #0x1f
	lsl r2, r2, #0xe
	mov r3, #0
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r1, r2, #0xc
	orr r1, r0
	neg r1, r1
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	asr r7, r0, #0xc
	add r0, r5, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, [r4, #0xc]
	add r0, r1, r0
	bl GF_SinDegFX32
	asr r1, r0, #0x1f
	mov r2, #0x4c
	mov r3, #0
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r6, r2, #0xc
	orr r6, r0
	add r0, r5, #0
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, [r4, #0xc]
	add r6, #0x80
	add r0, r1, r0
	bl GF_CosDegFX32
	asr r1, r0, #0x1f
	mov r2, #0x44
	mov r3, #0
	bl _ll_mul
	add r2, r0, #0
	mov r0, #2
	mov r3, #0
	lsl r0, r0, #0xa
	add r0, r2, r0
	adc r1, r3
	lsr r2, r0, #0xc
	lsl r1, r1, #0x14
	orr r2, r1
	mov r0, #0x62
	sub r0, r0, r2
	str r0, [sp, #4]
	ldr r2, [sp, #4]
	lsl r1, r6, #0x10
	sub r2, #0x18
	add r2, r2, r7
	lsl r2, r2, #0x10
	mov r3, #0x16
	ldr r0, [r4]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r2, [sp, #4]
	lsl r1, r6, #0x10
	lsl r2, r2, #0x10
	mov r3, #0x16
	ldr r0, [r4, #8]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	neg r0, r7
	mov r1, #3
	bl _s32_div_f
	lsl r0, r0, #0xc
	mov r1, #0xc
	bl _s32_div_f
	mov r1, #1
	lsl r1, r1, #0xc
	sub r0, r1, r0
	bl _fflt
	ldr r1, _022618C0 ; =0x45800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, [r4, #8]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	add r1, r5, #0
	add r1, #0xf4
	ldrb r1, [r1]
	add r0, r5, #0
	add r0, #0xf3
	lsl r2, r1, #2
	ldr r1, _022618BC ; =ov93_02262CC4
	ldrb r0, [r0]
	ldrb r1, [r1, r2]
	sub r1, r1, #1
	cmp r0, r1
	bne _02261896
	add r2, r4, #0
	ldr r0, [sp]
	add r1, r4, #0
	add r2, #0x30
	bl ov93_0226249C
_02261896:
	add r5, #0xe4
	ldr r1, [r5]
	ldr r0, [r4, #0xc]
	add r0, r1, r0
	mov r1, #0x5a
	asr r0, r0, #0xc
	lsl r1, r1, #2
	bl _s32_div_f
	cmp r1, #0xb4
	bne _022618B0
	mov r0, #1
	b _022618B2
_022618B0:
	mov r0, #0
_022618B2:
	strb r0, [r4, #0x15]
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022618BC: .word ov93_02262CC4
_022618C0: .word 0x45800000
	thumb_func_end ov93_02261744


	thumb_func_start ov93_022618C4
ov93_022618C4: ; 0x022618C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r2, #0
	ldrb r0, [r4, #0x11]
	add r5, r1, #0
	cmp r0, #3
	bls _022618D4
	b _02261BA2
_022618D4:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022618E0: ; jump table
	.short _022618E8 - _022618E0 - 2 ; case 0
	.short _0226195A - _022618E0 - 2 ; case 1
	.short _022619AE - _022618E0 - 2 ; case 2
	.short _02261ACA - _022618E0 - 2 ; case 3
_022618E8:
	ldr r0, _02261BA8 ; =0x00000593
	bl PlaySE
	add r1, sp, #8
	mov r3, #0x16
	ldr r0, [r4]
	add r1, #2
	add r2, sp, #8
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r3, sp, #4
	mov r2, #4
	ldrsh r2, [r3, r2]
	mov r1, #6
	ldrsh r1, [r3, r1]
	sub r2, #0x20
	lsl r2, r2, #0x10
	mov r3, #0x16
	ldr r0, [r4, #4]
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r4, #4]
	mov r1, #0x21
	bl ManagedSprite_SetAnim
	ldr r0, [r4, #4]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	ldrb r1, [r4, #0x14]
	ldr r0, [r4]
	lsl r2, r1, #1
	ldr r1, _02261BAC ; =ov93_02262C7A
	ldrh r1, [r1, r2]
	add r1, r1, #2
	bl ManagedSprite_SetAnim
	add r0, r5, #0
	add r0, #0xf4
	ldrb r0, [r0]
	ldr r1, _02261BB0 ; =ov93_02262CC6
	add r5, #0xf4
	lsl r0, r0, #2
	ldrb r0, [r1, r0]
	strb r0, [r4, #0x12]
	ldrb r0, [r5]
	lsl r0, r0, #2
	ldrb r0, [r1, r0]
	lsr r0, r0, #1
	strb r0, [r4, #0x13]
	ldrb r0, [r4, #0x11]
	add r0, r0, #1
	strb r0, [r4, #0x11]
	b _02261BA2
_0226195A:
	ldrb r1, [r4, #0x12]
	ldrb r0, [r4, #0x13]
	cmp r1, r0
	bne _02261984
	ldrb r1, [r4, #0x14]
	ldr r0, [r4]
	lsl r2, r1, #1
	ldr r1, _02261BAC ; =ov93_02262C7A
	ldrh r1, [r1, r2]
	add r1, r1, #1
	bl ManagedSprite_SetAnim
	ldr r0, [r4, #4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r1, #1
	ldr r0, [r4, #4]
	lsl r1, r1, #0xe
	bl ManagedSprite_TickNFrames
_02261984:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _022619A8
	ldr r0, [r4, #4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldrb r1, [r4, #0x14]
	ldr r0, [r4]
	lsl r2, r1, #1
	ldr r1, _02261BAC ; =ov93_02262C7A
	ldrh r1, [r1, r2]
	bl ManagedSprite_SetAnim
	ldrb r0, [r4, #0x11]
	add r0, r0, #1
	strb r0, [r4, #0x11]
	b _02261BA2
_022619A8:
	sub r0, r0, #1
	strb r0, [r4, #0x12]
	b _02261BA2
_022619AE:
	add r0, r5, #0
	add r0, #0xf2
	ldrb r0, [r0]
	mov r2, #0
	cmp r0, #0
	bne _022619E0
	add r0, r5, #0
	add r0, #0xf4
	ldrb r0, [r0]
	add r3, r5, #0
	add r3, #0xf3
	lsl r1, r0, #2
	ldr r0, _02261BB4 ; =ov93_02262CC4
	ldrb r3, [r3]
	ldrb r0, [r0, r1]
	add r5, #0xf0
	sub r3, r0, r3
	add r3, r2, r3
	ldr r2, _02261BB8 ; =ov93_02262CC5
	ldrb r1, [r2, r1]
	add r1, r3, r1
	add r6, r1, r0
	ldrb r0, [r5]
	add r5, r0, #2
	b _02261A0C
_022619E0:
	add r1, r2, r0
	add r0, r5, #0
	add r0, #0xf0
	ldrb r0, [r0]
	cmp r0, #0xc
	blo _022619FE
	add r5, #0xf4
	ldrb r0, [r5]
	mov r5, #1
	add r0, r0, #1
	lsl r2, r0, #2
	ldr r0, _02261BB4 ; =ov93_02262CC4
	ldrb r0, [r0, r2]
	add r6, r1, r0
	b _02261A0C
_022619FE:
	add r5, #0xf4
	ldrb r2, [r5]
	add r5, r0, #1
	lsl r3, r2, #2
	ldr r2, _02261BB4 ; =ov93_02262CC4
	ldrb r2, [r2, r3]
	add r6, r1, r2
_02261A0C:
	mov r1, #0x1e
	ldr r0, [r4, #0xc]
	lsl r1, r1, #0xc
	bl _s32_div_f
	add r0, r5, r0
	mov r1, #0xc
	bl _s32_div_f
	add r5, r1, #0
	mov r0, #0x1e
	lsl r0, r0, #0xc
	add r7, r5, #0
	mul r7, r0
	add r0, r7, #0
	bl GF_SinDegFX32
	add r5, r0, #0
	add r0, r7, #0
	bl GF_CosDegFX32
	str r0, [sp]
	add r1, sp, #4
	mov r3, #0x16
	ldr r0, [r4]
	add r1, #2
	add r2, sp, #4
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #4
	mov r3, #0
	ldrsh r0, [r1, r3]
	mov r2, #0x4c
	add r0, #0x18
	strh r0, [r1]
	mov r0, #2
	ldrsh r7, [r1, r0]
	asr r1, r5, #0x1f
	add r0, r5, #0
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r1, r2, #0xc
	orr r1, r0
	add r1, #0x80
	lsl r0, r1, #0x10
	asr r0, r0, #0x10
	sub r0, r0, r7
	lsl r0, r0, #0xc
	add r1, r6, #0
	bl _s32_div_f
	str r0, [r4, #0x20]
	add r0, sp, #4
	mov r3, #0
	ldrsh r5, [r0, r3]
	ldr r0, [sp]
	mov r2, #0x44
	asr r1, r0, #0x1f
	bl _ll_mul
	add r2, r0, #0
	mov r0, #2
	mov r3, #0
	lsl r0, r0, #0xa
	add r0, r2, r0
	adc r1, r3
	lsr r2, r0, #0xc
	lsl r1, r1, #0x14
	orr r2, r1
	mov r0, #0x62
	sub r0, r0, r2
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	sub r0, r0, r5
	lsl r0, r0, #0xc
	add r1, r6, #0
	bl _s32_div_f
	str r0, [r4, #0x24]
	lsl r0, r7, #0xc
	str r0, [r4, #0x28]
	lsl r0, r5, #0xc
	str r0, [r4, #0x2c]
	strb r6, [r4, #0x12]
	str r6, [r4, #0x18]
	ldrb r0, [r4, #0x11]
	add r0, r0, #1
	strb r0, [r4, #0x11]
_02261ACA:
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x20]
	add r0, r1, r0
	str r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x24]
	add r0, r1, r0
	str r0, [r4, #0x2c]
	ldrb r1, [r4, #0x12]
	mov r0, #0xb4
	mul r0, r1
	ldr r1, [r4, #0x18]
	lsl r0, r0, #0xc
	bl _s32_div_f
	bl GF_SinDegFX32
	mov r2, #3
	asr r1, r0, #0x1f
	lsl r2, r2, #0xe
	mov r3, #0
	bl _ll_mul
	add r5, r0, #0
	ldr r2, [r4, #0x28]
	add r6, r1, #0
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	ldr r2, [r4, #0x2c]
	lsl r1, r1, #4
	asr r3, r2, #0xb
	lsr r3, r3, #0x14
	add r3, r2, r3
	mov r2, #2
	asr r3, r3, #0xc
	mov r7, #0
	lsl r2, r2, #0xa
	asr r1, r1, #0x10
	sub r3, #0x18
	add r2, r5, r2
	adc r6, r7
	lsl r5, r6, #0x14
	lsr r2, r2, #0xc
	orr r2, r5
	neg r5, r2
	asr r2, r5, #0xb
	lsr r2, r2, #0x14
	add r2, r5, r2
	asr r2, r2, #0xc
	add r2, r3, r2
	lsl r2, r2, #0x10
	mov r3, #0x16
	ldr r0, [r4]
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	mov r0, #0xb
	ldr r1, [r4, #0x18]
	lsl r0, r0, #0xe
	bl _s32_div_f
	add r1, r0, #0
	ldr r0, [r4]
	bl ManagedSprite_TickNFrames
	ldr r2, [r4, #0x28]
	ldr r3, [r4, #0x2c]
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	lsl r1, r1, #4
	lsl r2, r2, #4
	mov r3, #0x16
	ldr r0, [r4, #8]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldrb r0, [r4, #0x12]
	sub r0, r0, #1
	strb r0, [r4, #0x12]
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _02261BA2
	ldrb r1, [r4, #0x14]
	ldr r0, [r4]
	lsl r2, r1, #1
	ldr r1, _02261BAC ; =ov93_02262C7A
	ldrh r1, [r1, r2]
	bl ManagedSprite_SetAnim
	ldr r0, [r4]
	add r1, r7, #0
	bl ManagedSprite_SetAnimationFrame
	add r0, r4, #0
	mov r1, #2
	bl ov93_02261528
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02261BA2:
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02261BA8: .word 0x00000593
_02261BAC: .word ov93_02262C7A
_02261BB0: .word ov93_02262CC6
_02261BB4: .word ov93_02262CC4
_02261BB8: .word ov93_02262CC5
	thumb_func_end ov93_022618C4


	thumb_func_start ov93_02261BBC
ov93_02261BBC: ; 0x02261BBC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	ldr r6, _02261C34 ; =ov93_02262E9C
	add r5, r0, #0
	add r4, r1, #0
	add r3, sp, #0
	mov r2, #6
_02261BCA:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02261BCA
	ldr r0, [r6]
	mov r7, #0x16
	str r0, [r3]
	mov r6, #0
	lsl r7, r7, #0x10
_02261BDC:
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	add r2, sp, #0
	bl SpriteSystem_NewSprite
	mov r1, #0
	str r0, [r4]
	add r2, r1, #0
	add r3, r7, #0
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	ldr r2, _02261C38 ; =ov93_02262ED0
	bl SpriteSystem_NewSprite
	mov r1, #0
	str r0, [r4, #4]
	add r2, r1, #0
	add r3, r7, #0
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r4, #4]
	mov r1, #0x21
	bl ManagedSprite_SetAnim
	ldr r0, [r4, #4]
	ldr r0, [r0]
	bl Sprite_TickFrame
	ldr r0, [r4, #4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r6, r6, #1
	add r4, #0x18
	cmp r6, #3
	blt _02261BDC
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02261C34: .word ov93_02262E9C
_02261C38: .word ov93_02262ED0
	thumb_func_end ov93_02261BBC

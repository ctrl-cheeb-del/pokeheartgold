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

	thumb_func_start ov93_02261164
ov93_02261164: ; 0x02261164
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	ldr r4, _022612CC ; =ov93_02262E9C
	add r5, r0, #0
	str r1, [sp]
	add r3, sp, #0xc
	mov r2, #6
_02261172:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02261172
	ldr r0, [r4]
	ldr r4, [sp]
	str r0, [r3]
	mov r0, #0
	ldr r7, _022612D0 ; =ov93_02262C7A
	str r0, [sp, #8]
_02261186:
	ldr r0, [sp]
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
	lsl r2, r2, #0xa
	add r2, r0, r2
	ldr r0, _022612D4 ; =0
	adc r1, r0
	lsl r0, r1, #0x14
	lsr r6, r2, #0xc
	orr r6, r0
	ldr r0, [sp]
	add r6, #0x80
	add r0, #0xe4
	ldr r1, [r0]
	ldr r0, [r4, #0xc]
	add r0, r1, r0
	bl GF_CosDegFX32
	asr r1, r0, #0x1f
	mov r2, #0x44
	mov r3, #0
	bl _ll_mul
	mov r2, #2
	lsl r2, r2, #0xa
	add r0, r0, r2
	ldr r2, _022612D4 ; =0
	adc r1, r2
	lsr r2, r0, #0xc
	lsl r1, r1, #0x14
	orr r2, r1
	mov r0, #0x62
	sub r0, r0, r2
	str r0, [sp, #4]
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	add r2, sp, #0xc
	bl SpriteSystem_NewSprite
	ldr r2, [sp, #4]
	lsl r1, r6, #0x10
	sub r2, #0x18
	lsl r2, r2, #0x10
	mov r3, #0x16
	str r0, [r4]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldrh r1, [r7, #2]
	ldr r0, [r4]
	bl ManagedSprite_SetAnim
	ldr r0, [r4]
	ldr r0, [r0]
	bl Sprite_TickFrame
	ldr r0, [r4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	ldr r2, _022612D8 ; =ov93_02262ED0
	bl SpriteSystem_NewSprite
	mov r1, #0
	mov r3, #0x16
	add r2, r1, #0
	lsl r3, r3, #0x10
	str r0, [r4, #4]
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
	ldr r0, [r5, #0x24]
	ldr r1, [r5, #0x28]
	ldr r2, _022612DC ; =ov93_02262F04
	bl SpriteSystem_NewSprite
	ldr r2, [sp, #4]
	lsl r1, r6, #0x10
	lsl r2, r2, #0x10
	mov r3, #0x16
	str r0, [r4, #8]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r4, #8]
	mov r1, #1
	bl ManagedSprite_SetOamMode
	ldr r0, [r4, #8]
	mov r1, #1
	bl ManagedSprite_SetAffineOverwriteMode
	mov r1, #0xfe
	lsl r1, r1, #0x16
	ldr r0, [r4, #8]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	ldr r1, [sp, #8]
	ldr r0, [r4, #8]
	add r1, #0x22
	bl ManagedSprite_SetAnim
	ldr r0, [r4, #8]
	ldr r0, [r0]
	bl Sprite_TickFrame
	ldr r0, [r4, #8]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x30
	bl ov93_02262444
	ldr r0, [sp, #8]
	add r4, #0x4c
	add r0, r0, #1
	add r7, r7, #2
	str r0, [sp, #8]
	cmp r0, #3
	bge _022612B4
	b _02261186
_022612B4:
	ldr r0, [sp]
	mov r1, #1
	ldr r0, [r0]
	bl ManagedSprite_SetDrawFlag
	ldr r0, [sp]
	mov r1, #1
	ldr r0, [r0, #8]
	bl ManagedSprite_SetDrawFlag
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022612CC: .word ov93_02262E9C
_022612D0: .word ov93_02262C7A
_022612D4: .word 0
_022612D8: .word ov93_02262ED0
_022612DC: .word ov93_02262F04
	thumb_func_end ov93_02261164

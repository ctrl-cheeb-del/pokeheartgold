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

	thumb_func_start ov95_021E6314
ov95_021E6314: ; 0x021E6314
	push {r3, r4, r5, r6, lr}
	sub sp, #0x1c
	add r4, r0, #0
	ldr r1, [r4, #0x60]
	mov r5, #1
	cmp r1, #0x11
	bls _021E6324
	b _021E6562
_021E6324:
	add r2, r1, r1
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021E6330: ; jump table
	.short _021E6354 - _021E6330 - 2 ; case 0
	.short _021E63D2 - _021E6330 - 2 ; case 1
	.short _021E63DC - _021E6330 - 2 ; case 2
	.short _021E63FA - _021E6330 - 2 ; case 3
	.short _021E640A - _021E6330 - 2 ; case 4
	.short _021E641C - _021E6330 - 2 ; case 5
	.short _021E642C - _021E6330 - 2 ; case 6
	.short _021E643C - _021E6330 - 2 ; case 7
	.short _021E648C - _021E6330 - 2 ; case 8
	.short _021E64A0 - _021E6330 - 2 ; case 9
	.short _021E64AE - _021E6330 - 2 ; case 10
	.short _021E64D4 - _021E6330 - 2 ; case 11
	.short _021E650E - _021E6330 - 2 ; case 12
	.short _021E653C - _021E6330 - 2 ; case 13
	.short _021E6542 - _021E6330 - 2 ; case 14
	.short _021E6548 - _021E6330 - 2 ; case 15
	.short _021E6552 - _021E6330 - 2 ; case 16
	.short _021E6562 - _021E6330 - 2 ; case 17
_021E6354:
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	bl ov95_021E5D44
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0x14]
	bl ov95_021E5BBC
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0x3b
	str r0, [sp, #0xc]
	mov r0, #0xe
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x18
	add r2, r5, #0
	mov r3, #2
	bl ov95_021E5C44
	add r0, r4, #0
	bl ov95_021E5EF8
	add r0, r4, #0
	bl ov95_021E6000
	ldr r3, _021E6594 ; =0x0000520A
	str r3, [sp]
	add r0, r3, #1
	str r0, [sp, #4]
	add r0, r4, #0
	add r0, #0x88
	sub r2, r3, #2
	ldr r0, [r0]
	ldr r1, [r4, #8]
	sub r3, r3, #1
	bl ov95_021E70BC
	add r0, r4, #0
	bl ov95_021E623C
	add r0, r4, #0
	add r1, r5, #0
	bl ov95_021E62F0
	mov r0, #0x46
	str r0, [sp, #0x14]
	mov r0, #0
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	bl ov95_021E5E90
	str r0, [r4, #0x44]
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E63D2:
	bl ov95_021E5B7C
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E63DC:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E6412
	bl Sound_Stop
	ldr r1, _021E6598 ; =0x000003F3
	mov r0, #0xd
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E63FA:
	bl ov95_021E67F0
	cmp r0, #0
	bne _021E6412
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E640A:
	bl ov95_021E6838
	cmp r0, #0
	beq _021E6414
_021E6412:
	b _021E6586
_021E6414:
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E641C:
	bl ov95_021E68A8
	cmp r0, #0
	bne _021E651E
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E642C:
	bl ov95_021E6900
	cmp r0, #0
	bne _021E651E
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E643C:
	bl ov95_021E6964
	cmp r0, #0
	bne _021E651E
	add r0, r4, #0
	bl ov95_021E62A4
	ldr r0, [r4]
	mov r1, #5
	ldr r0, [r0, #0xc]
	mov r2, #0
	bl GetMonData
	add r6, r0, #0
	ldr r0, [r4]
	mov r1, #0x70
	ldr r0, [r0, #0xc]
	mov r2, #0
	bl GetMonData
	add r1, r0, #0
	lsl r0, r6, #0x10
	lsl r1, r1, #0x18
	lsr r0, r0, #0x10
	lsr r1, r1, #0x18
	bl PlayCry
	ldr r2, [r4]
	add r0, r4, #0
	ldr r2, [r2, #0xc]
	ldr r3, [r4, #0x10]
	add r0, #0x18
	mov r1, #0
	bl ov95_021E5CAC
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E648C:
	bl IsCryFinished
	cmp r0, #0
	bne _021E6586
	ldr r0, _021E659C ; =0x000004A4
	bl PlayFanfare
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E64A0:
	bl IsFanfarePlaying
	cmp r0, #0
	bne _021E6586
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E64AE:
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _021E6586
	ldr r2, [r4]
	add r0, r4, #0
	ldr r2, [r2, #0xc]
	ldr r3, [r4, #0x10]
	add r0, #0x18
	mov r1, #1
	bl ov95_021E5CAC
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E64D4:
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _021E6586
	ldr r0, [r4, #0x58]
	mov r1, #0
	bl sub_02017068
	cmp r0, #1
	bne _021E6586
	ldr r0, [r4, #0x70]
	bl Pokepic_IsAnimFinished
	cmp r0, #0
	bne _021E6586
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	mov r1, #2
	mov r2, #3
	bl ov95_021E7208
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E650E:
	add r0, #0x88
	ldr r0, [r0]
	bl ov95_021E7258
	cmp r0, #1
	beq _021E6520
	cmp r0, #2
	beq _021E652E
_021E651E:
	b _021E6586
_021E6520:
	ldr r0, [r4]
	add r1, r5, #0
	str r1, [r0, #4]
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E652E:
	ldr r0, [r4]
	mov r1, #0
	str r1, [r0, #4]
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E653C:
	add r0, r1, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E6542:
	add r0, r1, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E6548:
	bl ov95_021E5B9C
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E6552:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E6586
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E6586
_021E6562:
	add r0, r4, #0
	bl ov95_021E62E4
	add r0, r4, #0
	bl ov95_021E6184
	add r0, r4, #0
	add r0, #0x18
	bl ov95_021E5D34
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0xc]
	bl ov95_021E5E40
	ldr r0, [r4, #0x44]
	bl ov95_021E5EF0
	mov r5, #0
_021E6586:
	ldr r0, [r4, #0x50]
	bl SpriteSystem_DrawSprites
	add r0, r5, #0
	add sp, #0x1c
	pop {r3, r4, r5, r6, pc}
	nop
_021E6594: .word 0x0000520A
_021E6598: .word 0x000003F3
_021E659C: .word 0x000004A4
	thumb_func_end ov95_021E6314


	thumb_func_start ov95_021E65A0
ov95_021E65A0: ; 0x021E65A0
	push {r3, r4, r5, r6, lr}
	sub sp, #0x1c
	add r4, r0, #0
	ldr r1, [r4, #0x60]
	mov r5, #1
	cmp r1, #0x11
	bls _021E65B0
	b _021E67B4
_021E65B0:
	add r2, r1, r1
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021E65BC: ; jump table
	.short _021E65E0 - _021E65BC - 2 ; case 0
	.short _021E6666 - _021E65BC - 2 ; case 1
	.short _021E6670 - _021E65BC - 2 ; case 2
	.short _021E668A - _021E65BC - 2 ; case 3
	.short _021E66D8 - _021E65BC - 2 ; case 4
	.short _021E66D8 - _021E65BC - 2 ; case 5
	.short _021E66D8 - _021E65BC - 2 ; case 6
	.short _021E66D8 - _021E65BC - 2 ; case 7
	.short _021E66DE - _021E65BC - 2 ; case 8
	.short _021E66F2 - _021E65BC - 2 ; case 9
	.short _021E6700 - _021E65BC - 2 ; case 10
	.short _021E6726 - _021E65BC - 2 ; case 11
	.short _021E6760 - _021E65BC - 2 ; case 12
	.short _021E678E - _021E65BC - 2 ; case 13
	.short _021E6794 - _021E65BC - 2 ; case 14
	.short _021E679A - _021E65BC - 2 ; case 15
	.short _021E67A4 - _021E65BC - 2 ; case 16
	.short _021E67B4 - _021E65BC - 2 ; case 17
_021E65E0:
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	bl ov95_021E5D44
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0x14]
	bl ov95_021E5BBC
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0x3b
	str r0, [sp, #0xc]
	mov r0, #0xe
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x18
	add r2, r5, #0
	mov r3, #2
	bl ov95_021E5C44
	add r0, r4, #0
	bl ov95_021E5EF8
	add r0, r4, #0
	bl ov95_021E6000
	ldr r0, [r4, #0x74]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r3, _021E67E4 ; =0x0000520A
	str r3, [sp]
	add r0, r3, #1
	str r0, [sp, #4]
	add r0, r4, #0
	add r0, #0x88
	sub r2, r3, #2
	ldr r0, [r0]
	ldr r1, [r4, #8]
	sub r3, r3, #1
	bl ov95_021E70BC
	add r0, r4, #0
	bl ov95_021E623C
	add r0, r4, #0
	add r1, r5, #0
	bl ov95_021E62F0
	mov r0, #0x46
	str r0, [sp, #0x14]
	add r0, r5, #0
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	bl ov95_021E5E90
	str r0, [r4, #0x44]
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E67D8
_021E6666:
	bl ov95_021E5B7C
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E6670:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E6770
	ldr r1, _021E67E8 ; =0x000003F3
	mov r0, #0xd
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E67D8
_021E668A:
	bl ov95_021E6B74
	cmp r0, #0
	bne _021E6770
	add r0, r4, #0
	bl ov95_021E62A4
	ldr r0, [r4]
	mov r1, #5
	ldr r0, [r0, #0xc]
	mov r2, #0
	bl GetMonData
	add r6, r0, #0
	ldr r0, [r4]
	mov r1, #0x70
	ldr r0, [r0, #0xc]
	mov r2, #0
	bl GetMonData
	add r1, r0, #0
	lsl r0, r6, #0x10
	lsl r1, r1, #0x18
	lsr r0, r0, #0x10
	lsr r1, r1, #0x18
	bl PlayCry
	ldr r2, [r4]
	add r0, r4, #0
	ldr r2, [r2, #0xc]
	ldr r3, [r4, #0x10]
	add r0, #0x18
	mov r1, #0
	bl ov95_021E5CAC
	str r0, [r4, #0xc]
	mov r0, #8
	str r0, [r4, #0x60]
	b _021E67D8
_021E66D8:
	bl GF_AssertFail
	b _021E67D8
_021E66DE:
	bl IsCryFinished
	cmp r0, #0
	bne _021E67D8
	ldr r0, _021E67EC ; =0x000004A4
	bl PlayFanfare
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E66F2:
	bl IsFanfarePlaying
	cmp r0, #0
	bne _021E67D8
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E6700:
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _021E67D8
	ldr r2, [r4]
	add r0, r4, #0
	ldr r2, [r2, #0xc]
	ldr r3, [r4, #0x10]
	add r0, #0x18
	mov r1, #1
	bl ov95_021E5CAC
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E6726:
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _021E67D8
	ldr r0, [r4, #0x58]
	mov r1, #0
	bl sub_02017068
	cmp r0, #1
	bne _021E67D8
	ldr r0, [r4, #0x70]
	bl Pokepic_IsAnimFinished
	cmp r0, #0
	bne _021E67D8
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	mov r1, #2
	mov r2, #3
	bl ov95_021E7208
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E67D8
_021E6760:
	add r0, #0x88
	ldr r0, [r0]
	bl ov95_021E7258
	cmp r0, #1
	beq _021E6772
	cmp r0, #2
	beq _021E6780
_021E6770:
	b _021E67D8
_021E6772:
	ldr r0, [r4]
	add r1, r5, #0
	str r1, [r0, #4]
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E67D8
_021E6780:
	ldr r0, [r4]
	mov r1, #0
	str r1, [r0, #4]
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E67D8
_021E678E:
	add r0, r1, #1
	str r0, [r4, #0x60]
	b _021E67D8
_021E6794:
	add r0, r1, #1
	str r0, [r4, #0x60]
	b _021E67D8
_021E679A:
	bl ov95_021E5B9C
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
_021E67A4:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E67D8
	ldr r0, [r4, #0x60]
	add r0, r0, #1
	str r0, [r4, #0x60]
	b _021E67D8
_021E67B4:
	add r0, r4, #0
	bl ov95_021E62E4
	add r0, r4, #0
	bl ov95_021E6184
	add r0, r4, #0
	add r0, #0x18
	bl ov95_021E5D34
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0xc]
	bl ov95_021E5E40
	ldr r0, [r4, #0x44]
	bl ov95_021E5EF0
	mov r5, #0
_021E67D8:
	ldr r0, [r4, #0x50]
	bl SpriteSystem_DrawSprites
	add r0, r5, #0
	add sp, #0x1c
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021E67E4: .word 0x0000520A
_021E67E8: .word 0x000003F3
_021E67EC: .word 0x000004A4
	thumb_func_end ov95_021E65A0

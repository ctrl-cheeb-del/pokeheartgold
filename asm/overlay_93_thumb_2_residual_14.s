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

	thumb_func_start ov93_02261D3C
ov93_02261D3C: ; 0x02261D3C
	push {r3, r4, lr}
	sub sp, #4
	add r4, r1, #0
	ldrb r0, [r4, #0x13]
	cmp r0, #4
	bls _02261D4A
	b _02261E88
_02261D4A:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02261D56: ; jump table
	.short _02261D60 - _02261D56 - 2 ; case 0
	.short _02261D88 - _02261D56 - 2 ; case 1
	.short _02261DC4 - _02261D56 - 2 ; case 2
	.short _02261E20 - _02261D56 - 2 ; case 3
	.short _02261E5A - _02261D56 - 2 ; case 4
_02261D60:
	add r1, sp, #0
	mov r3, #0x16
	ldr r0, [r4]
	add r1, #2
	add r2, sp, #0
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #0
	mov r0, #2
	ldrsh r0, [r1, r0]
	lsl r0, r0, #0xc
	str r0, [r4, #8]
	mov r0, #0
	ldrsh r0, [r1, r0]
	lsl r0, r0, #0xc
	str r0, [r4, #0xc]
	ldrb r0, [r4, #0x13]
	add r0, r0, #1
	strb r0, [r4, #0x13]
_02261D88:
	mov r0, #0x16
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _02261D96
	sub r0, r0, #1
	strh r0, [r4, #0x16]
	b _02261E88
_02261D96:
	ldr r0, [r4]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	mov r0, #2
	ldr r1, [r4, #0xc]
	lsl r0, r0, #0xe
	add r2, r1, r0
	str r2, [r4, #0xc]
	mov r0, #0x10
	ldrsh r1, [r4, r0]
	asr r0, r2, #0xb
	lsr r0, r0, #0x14
	add r0, r2, r0
	asr r0, r0, #0xc
	cmp r0, r1
	blt _02261E88
	lsl r0, r1, #0xc
	str r0, [r4, #0xc]
	ldrb r0, [r4, #0x13]
	add r0, r0, #1
	strb r0, [r4, #0x13]
	b _02261E88
_02261DC4:
	add r1, sp, #0
	mov r3, #0x16
	ldr r0, [r4]
	add r1, #2
	add r2, sp, #0
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r3, sp, #0
	mov r2, #0
	ldrsh r2, [r3, r2]
	mov r1, #2
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
	ldr r0, _02261EB0 ; =0x00000593
	bl PlaySE
	ldrb r1, [r4, #0x12]
	ldr r0, [r4]
	lsl r2, r1, #1
	ldr r1, _02261EB4 ; =ov93_02262C7A
	ldrh r1, [r1, r2]
	add r1, r1, #2
	bl ManagedSprite_SetAnim
	mov r0, #8
	strb r0, [r4, #0x14]
	ldrb r0, [r4, #0x13]
	add r0, r0, #1
	strb r0, [r4, #0x13]
	b _02261E88
_02261E20:
	ldrb r0, [r4, #0x14]
	sub r0, r0, #1
	strb r0, [r4, #0x14]
	ldrb r0, [r4, #0x14]
	cmp r0, #3
	bne _02261E36
	mov r1, #1
	ldr r0, [r4, #4]
	lsl r1, r1, #0xe
	bl ManagedSprite_TickNFrames
_02261E36:
	ldrb r0, [r4, #0x14]
	cmp r0, #0
	bne _02261E88
	ldr r0, [r4, #4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldrb r1, [r4, #0x12]
	ldr r0, [r4]
	lsl r2, r1, #1
	ldr r1, _02261EB4 ; =ov93_02262C7A
	ldrh r1, [r1, r2]
	bl ManagedSprite_SetAnim
	ldrb r0, [r4, #0x13]
	add r0, r0, #1
	strb r0, [r4, #0x13]
	b _02261E88
_02261E5A:
	mov r0, #2
	ldr r1, [r4, #0xc]
	lsl r0, r0, #0xe
	sub r1, r1, r0
	asr r0, r1, #0xb
	lsr r0, r0, #0x14
	add r0, r1, r0
	str r1, [r4, #0xc]
	asr r1, r0, #0xc
	mov r0, #0x10
	ldrsh r0, [r4, r0]
	sub r0, #0x60
	cmp r1, r0
	bgt _02261E88
	ldr r0, [r4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0
	strb r0, [r4, #0x13]
	add sp, #4
	strb r0, [r4, #0x15]
	pop {r3, r4, pc}
_02261E88:
	ldr r2, [r4, #8]
	ldr r3, [r4, #0xc]
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	asr r2, r3, #0xb
	lsr r2, r2, #0x14
	add r2, r3, r2
	lsl r1, r1, #4
	lsl r2, r2, #4
	mov r3, #0x16
	ldr r0, [r4]
	asr r1, r1, #0x10
	asr r2, r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	mov r0, #1
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02261EB0: .word 0x00000593
_02261EB4: .word ov93_02262C7A
	thumb_func_end ov93_02261D3C


	thumb_func_start ov93_02261EB8
ov93_02261EB8: ; 0x02261EB8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x70
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r2, [sp, #0x20]
	ldr r0, [sp, #0x8c]
	ldr r1, [sp, #0x88]
	mov r2, #0
	add r5, r3, #0
	ldr r4, [sp, #0x9c]
	bl FontID_String_GetWidthMultiline
	add r7, r0, #0
	asr r1, r7, #2
	lsr r1, r1, #0x1d
	add r1, r7, r1
	asr r6, r1, #3
	mov r1, #8
	bl FX_ModS32
	cmp r0, #0
	beq _02261EE6
	add r6, r6, #1
_02261EE6:
	add r0, sp, #0x30
	bl InitWindow
	mov r0, #0
	ldr r3, [sp, #0xb0]
	str r0, [sp]
	str r0, [sp, #4]
	lsl r2, r6, #0x18
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x18]
	add r1, sp, #0x30
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl AddTextWindowTopLeftCorner
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x90]
	ldr r1, [sp, #0x8c]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r2, [sp, #0x88]
	add r0, sp, #0x30
	str r3, [sp, #0x14]
	bl AddTextPrinterParameterizedWithColorAndSpacing
	add r0, sp, #0x30
	mov r1, #1
	mov r2, #0x75
	bl sub_02013688
	mov r1, #1
	add r2, r1, #0
	add r3, sp, #0x24
	bl sub_02021AC8
	ldr r0, [sp, #0xa4]
	cmp r0, #1
	bne _02261F42
	lsr r0, r7, #0x1f
	add r0, r7, r0
	asr r0, r0, #1
	sub r4, r4, r0
_02261F42:
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x40]
	add r0, sp, #0x30
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x1c]
	bl SpriteManager_GetSpriteList
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x98]
	bl SpriteManager_FindPlttResourceProxy
	str r0, [sp, #0x4c]
	mov r0, #0
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x28]
	str r4, [sp, #0x58]
	str r0, [sp, #0x54]
	ldr r0, [sp, #0xa0]
	str r0, [sp, #0x5c]
	ldr r0, [sp, #0xa8]
	str r0, [sp, #0x60]
	ldr r0, [sp, #0xac]
	str r0, [sp, #0x64]
	mov r0, #1
	str r0, [sp, #0x68]
	mov r0, #0x75
	str r0, [sp, #0x6c]
	add r0, sp, #0x40
	bl sub_020135D8
	ldr r1, [sp, #0x94]
	add r6, r0, #0
	cmp r1, #0
	beq _02261F8C
	bl sub_020138B0
_02261F8C:
	ldr r2, [sp, #0xa0]
	add r0, r6, #0
	add r1, r4, #0
	bl sub_020136B4
	add r0, sp, #0x30
	bl RemoveWindow
	str r6, [r5]
	add r3, sp, #0x24
	ldmia r3!, {r0, r1}
	add r2, r5, #4
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	strh r7, [r5, #0x10]
	add sp, #0x70
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov93_02261EB8

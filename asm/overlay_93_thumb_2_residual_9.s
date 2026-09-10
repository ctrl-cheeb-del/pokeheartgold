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

	thumb_func_start ov93_02260FB8
ov93_02260FB8: ; 0x02260FB8
	push {r3, r4, r5, r6, r7, lr}
	add r2, r0, #0
	ldr r0, _022610A4 ; =0x00002FB0
	add r7, r1, #0
	ldr r5, [r2, r0]
	sub r0, r0, #4
	ldr r0, [r2, r0]
	mov r4, #0
	cmp r0, r5
	beq _02260FD0
	cmp r7, #0
	bne _02260FD4
_02260FD0:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02260FD4:
	lsr r3, r0, #0x1f
	lsl r1, r0, #0x1d
	sub r1, r1, r3
	mov r0, #0x1d
	ror r1, r0
	add r1, r3, r1
	lsr r3, r5, #0x1f
	lsl r5, r5, #0x1d
	sub r5, r5, r3
	ror r5, r0
	add r0, r3, r5
	cmp r1, r0
	bge _02261012
	cmp r1, r0
	bge _0226105A
	lsl r3, r1, #4
	add r6, r2, r3
	ldr r3, _022610A8 ; =0x00002F38
_02260FF8:
	ldrb r5, [r6, r3]
	cmp r5, #0
	bne _02261008
	ldr r0, _022610AC ; =0x00002F2C
	add r2, r2, r0
	lsl r0, r1, #4
	add r4, r2, r0
	b _0226105A
_02261008:
	add r1, r1, #1
	add r6, #0x10
	cmp r1, r0
	blt _02260FF8
	b _0226105A
_02261012:
	cmp r1, #8
	bge _02261034
	lsl r3, r1, #4
	add r6, r2, r3
	ldr r3, _022610A8 ; =0x00002F38
_0226101C:
	ldrb r5, [r6, r3]
	cmp r5, #0
	bne _0226102C
	ldr r3, _022610AC ; =0x00002F2C
	lsl r1, r1, #4
	add r3, r2, r3
	add r4, r3, r1
	b _02261034
_0226102C:
	add r1, r1, #1
	add r6, #0x10
	cmp r1, #8
	blt _0226101C
_02261034:
	cmp r4, #0
	bne _0226105A
	mov r6, #0
	cmp r0, #0
	ble _0226105A
	ldr r1, _022610A8 ; =0x00002F38
	add r5, r2, #0
_02261042:
	ldrb r3, [r5, r1]
	cmp r3, #0
	bne _02261052
	ldr r0, _022610AC ; =0x00002F2C
	add r1, r2, r0
	lsl r0, r6, #4
	add r4, r1, r0
	b _0226105A
_02261052:
	add r6, r6, #1
	add r5, #0x10
	cmp r6, r0
	blt _02261042
_0226105A:
	cmp r4, #0
	bne _02261066
	bl GF_AssertFail
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02261066:
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _02261070
	bl GF_AssertFail
_02261070:
	mov r0, #1
	strb r7, [r4, #1]
	strb r0, [r4, #0xc]
	cmp r7, #1
	beq _02261084
	cmp r7, #2
	beq _0226108C
	cmp r7, #3
	beq _02261098
	b _022610A0
_02261084:
	ldr r0, [r4, #4]
	lsl r0, r0, #1
	str r0, [r4, #8]
	b _022610A0
_0226108C:
	ldr r1, [r4, #4]
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	str r0, [r4, #8]
	b _022610A0
_02261098:
	ldr r1, [r4, #4]
	lsl r0, r1, #1
	add r0, r1, r0
	str r0, [r4, #8]
_022610A0:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022610A4: .word 0x00002FB0
_022610A8: .word 0x00002F38
_022610AC: .word 0x00002F2C
	thumb_func_end ov93_02260FB8


	thumb_func_start ov93_022610B0
ov93_022610B0: ; 0x022610B0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r4, _02261144 ; =ov93_02262E68
	add r7, r0, #0
	str r1, [sp]
	add r3, sp, #4
	mov r2, #6
_022610BE:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _022610BE
	ldr r0, [r4]
	ldr r4, [sp]
	ldr r5, _02261148 ; =ov93_02262CB4
	str r0, [r3]
	mov r6, #0
_022610D0:
	ldr r0, [r7, #0x24]
	ldr r1, [r7, #0x28]
	add r2, sp, #4
	bl SpriteSystem_NewSprite
	mov r3, #0x16
	str r0, [r4]
	mov r1, #0
	mov r2, #2
	ldrsh r1, [r5, r1]
	ldrsh r2, [r5, r2]
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	lsr r1, r6, #0x1f
	add r1, r6, r1
	asr r1, r1, #1
	ldr r0, [r4]
	add r1, #0x1f
	bl ManagedSprite_SetAnim
	ldr r0, [r4]
	ldr r0, [r0]
	bl Sprite_TickFrame
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r6, #4
	blt _022610D0
	ldr r0, [r7]
	add r0, #0x30
	ldrb r0, [r0]
	cmp r0, #2
	beq _0226111E
	cmp r0, #3
	beq _02261136
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
_0226111E:
	ldr r0, [sp]
	mov r1, #0
	ldr r0, [r0, #8]
	bl ManagedSprite_SetDrawFlag
	ldr r0, [sp]
	mov r1, #0
	ldr r0, [r0, #0xc]
	bl ManagedSprite_SetDrawFlag
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
_02261136:
	ldr r0, [sp]
	mov r1, #0
	ldr r0, [r0, #4]
	bl ManagedSprite_SetDrawFlag
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02261144: .word ov93_02262E68
_02261148: .word ov93_02262CB4
	thumb_func_end ov93_022610B0

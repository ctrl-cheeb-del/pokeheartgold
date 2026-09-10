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

	thumb_func_start ov93_02262374
ov93_02262374: ; 0x02262374
	push {r4, lr}
	add r4, r1, #0
	mov r0, #4
	ldrsh r1, [r4, r0]
	cmp r1, #0xa
	bhi _0226243E
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0226238C: ; jump table
	.short _022623A2 - _0226238C - 2 ; case 0
	.short _022623C2 - _0226238C - 2 ; case 1
	.short _022623EA - _0226238C - 2 ; case 2
	.short _0226240C - _0226238C - 2 ; case 3
	.short _0226241E - _0226238C - 2 ; case 4
	.short _022623A2 - _0226238C - 2 ; case 5
	.short _022623C2 - _0226238C - 2 ; case 6
	.short _022623EA - _0226238C - 2 ; case 7
	.short _0226240C - _0226238C - 2 ; case 8
	.short _0226241E - _0226238C - 2 ; case 9
	.short _0226243A - _0226238C - 2 ; case 10
_022623A2:
	mov r3, #0x16
	ldr r0, [r4]
	mov r1, #0x80
	mov r2, #0x10
	lsl r3, r3, #0x10
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldr r0, [r4]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	mov r0, #4
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4, #4]
	b _0226243E
_022623C2:
	mov r1, #6
	ldrsh r2, [r4, r1]
	add r2, r2, #1
	strh r2, [r4, #6]
	ldrsh r1, [r4, r1]
	cmp r1, #0xf
	ble _0226243E
	mov r1, #0
	strh r1, [r4, #6]
	mov r1, #1
	str r1, [r4, #0x14]
	str r1, [r4, #0x18]
	mov r1, #0x80
	str r1, [r4, #0xc]
	mov r1, #0x20
	str r1, [r4, #0x10]
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4, #4]
	b _0226243E
_022623EA:
	mov r1, #0
	str r1, [r4, #0x18]
	ldr r0, [r4, #0x10]
	mov r2, #6
	add r0, r0, #6
	str r0, [r4, #0x10]
	ldr r0, [r4]
	bl ManagedSprite_OffsetPositionXY
	ldr r0, [r4, #0x10]
	cmp r0, #0x60
	ble _0226243E
	mov r0, #4
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4, #4]
	b _0226243E
_0226240C:
	mov r1, #0
	str r1, [r4, #0x14]
	ldr r0, [r4]
	bl ManagedSprite_SetDrawFlag
	mov r0, #4
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4, #4]
_0226241E:
	mov r0, #6
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, #6]
	ldrsh r0, [r4, r0]
	cmp r0, #0x1e
	ble _0226243E
	mov r0, #0
	strh r0, [r4, #6]
	mov r0, #4
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4, #4]
	b _0226243E
_0226243A:
	mov r0, #1
	pop {r4, pc}
_0226243E:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov93_02262374

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

	thumb_func_start ov93_02260BB0
ov93_02260BB0: ; 0x02260BB0
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldr r0, [r4]
	add r0, #0x30
	ldrb r0, [r0]
	cmp r0, #3
	bne _02260BEC
	mov r0, #0xc
	str r0, [sp]
	mov r1, #4
	str r1, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	ldr r0, [r4, #0x2c]
	mov r2, #0
	mov r3, #0xd
	bl BgTilemapRectChangePalette
	mov r0, #0xc
	str r0, [sp]
	mov r1, #4
	str r1, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [r4, #0x2c]
	mov r2, #0x14
	mov r3, #0xd
	bl BgTilemapRectChangePalette
_02260BEC:
	add sp, #0xc
	pop {r3, r4, pc}
	thumb_func_end ov93_02260BB0


	thumb_func_start ov93_02260BF0
ov93_02260BF0: ; 0x02260BF0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r6, r0, #0
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [r6]
	add r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	ble _02260C50
	ldr r0, _02260CF0 ; =ov93_02262C72
	str r0, [sp, #4]
	add r0, sp, #0x10
	str r0, [sp]
_02260C0C:
	ldr r0, [sp, #4]
	ldr r5, [sp]
	ldrh r7, [r0]
	mov r4, #0
_02260C14:
	add r0, r6, #0
	add r0, #0x8c
	add r3, r7, r4
	mov r1, #1
	lsl r3, r3, #0x10
	ldr r0, [r0]
	add r2, r1, #0
	lsr r3, r3, #0x10
	bl PaletteData_GetBufferColorAtIndex
	strh r0, [r5]
	add r4, r4, #1
	add r5, r5, #2
	cmp r4, #3
	blt _02260C14
	ldr r0, [sp, #4]
	add r0, r0, #2
	str r0, [sp, #4]
	ldr r0, [sp]
	add r0, r0, #6
	str r0, [sp]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	ldr r0, [r6]
	add r0, #0x30
	ldrb r1, [r0]
	ldr r0, [sp, #0xc]
	cmp r0, r1
	blt _02260C0C
_02260C50:
	bl sub_0203769C
	ldr r3, [r6]
	mov r2, #0
	add r1, r3, #0
	add r1, #0x30
	ldrb r4, [r1]
	cmp r4, #0
	ble _02260C74
_02260C62:
	add r1, r3, #0
	add r1, #0x2c
	ldrb r1, [r1]
	cmp r0, r1
	beq _02260C74
	add r2, r2, #1
	add r3, r3, #1
	cmp r2, r4
	blt _02260C62
_02260C74:
	add r0, r6, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #1
	bl PaletteData_GetUnfadedBuf
	str r0, [sp, #8]
	add r0, r6, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #1
	bl PaletteData_GetFadedBuf
	ldr r1, [r6]
	add r7, r0, #0
	add r0, r1, #0
	add r0, #0x30
	ldrb r5, [r0]
	mov r4, #0
	cmp r5, #0
	ble _02260CEA
_02260C9E:
	add r1, r1, r4
	add r1, #0x2c
	ldrb r1, [r1]
	add r0, r6, #0
	bl ov93_0225E3C4
	lsl r1, r0, #1
	ldr r0, _02260CF4 ; =ov93_02262DA4
	lsl r2, r5, #3
	add r0, r0, r2
	ldrh r2, [r1, r0]
	mov r1, #6
	add r3, r4, #0
	mul r3, r1
	add r1, sp, #0x10
	add r1, r1, r3
	lsl r3, r2, #1
	ldr r2, [sp, #8]
	mov r0, #0
	add r2, r2, r3
	add r3, r7, r3
_02260CC8:
	ldrh r5, [r1]
	add r0, r0, #1
	strh r5, [r2]
	ldrh r5, [r1]
	add r1, r1, #2
	add r2, r2, #2
	strh r5, [r3]
	add r3, r3, #2
	cmp r0, #3
	blt _02260CC8
	ldr r1, [r6]
	add r4, r4, #1
	add r0, r1, #0
	add r0, #0x30
	ldrb r5, [r0]
	cmp r4, r5
	blt _02260C9E
_02260CEA:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02260CF0: .word ov93_02262C72
_02260CF4: .word ov93_02262DA4
	thumb_func_end ov93_02260BF0


	thumb_func_start ov93_02260CF8
ov93_02260CF8: ; 0x02260CF8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x9c
	add r7, r0, #0
	ldr r0, [r7, #0x28]
	ldr r1, _02260E10 ; =0x00002716
	mov r2, #2
	bl SpriteManager_FindPlttResourceOffset
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [r7]
	add r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	ble _02260D6E
	ldr r0, _02260E14 ; =ov93_02262C8A
	str r0, [sp, #8]
	add r0, sp, #0x1c
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	lsl r0, r0, #4
	str r0, [sp]
_02260D26:
	ldr r0, [sp, #8]
	ldr r5, [sp, #4]
	ldrh r1, [r0]
	ldr r0, [sp]
	mov r6, #0
	add r4, r1, r0
_02260D32:
	add r0, r7, #0
	add r0, #0x8c
	lsl r3, r4, #0x10
	ldr r0, [r0]
	mov r1, #3
	mov r2, #1
	lsr r3, r3, #0x10
	bl PaletteData_GetBufferColorAtIndex
	strh r0, [r5]
	add r6, r6, #1
	add r4, r4, #1
	add r5, r5, #2
	cmp r6, #0x10
	blt _02260D32
	ldr r0, [sp, #8]
	add r0, r0, #2
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r0, #0x20
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
	ldr r0, [r7]
	add r0, #0x30
	ldrb r1, [r0]
	ldr r0, [sp, #0x18]
	cmp r0, r1
	blt _02260D26
_02260D6E:
	bl sub_0203769C
	ldr r3, [r7]
	mov r2, #0
	add r1, r3, #0
	add r1, #0x30
	ldrb r4, [r1]
	cmp r4, #0
	ble _02260D92
_02260D80:
	add r1, r3, #0
	add r1, #0x2c
	ldrb r1, [r1]
	cmp r0, r1
	beq _02260D92
	add r2, r2, #1
	add r3, r3, #1
	cmp r2, r4
	blt _02260D80
_02260D92:
	add r0, r7, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #3
	bl PaletteData_GetUnfadedBuf
	str r0, [sp, #0x14]
	add r0, r7, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #3
	bl PaletteData_GetFadedBuf
	ldr r1, [r7]
	str r0, [sp, #0x10]
	add r0, r1, #0
	add r0, #0x30
	ldrb r5, [r0]
	mov r4, #0
	cmp r5, #0
	ble _02260E0C
	ldr r0, [sp, #0xc]
	lsl r6, r0, #4
_02260DC0:
	add r1, r1, r4
	add r1, #0x2c
	ldrb r1, [r1]
	add r0, r7, #0
	bl ov93_0225E3C4
	lsl r1, r0, #1
	ldr r0, _02260E18 ; =ov93_02262D04
	lsl r2, r5, #3
	add r0, r0, r2
	ldrh r0, [r1, r0]
	lsl r3, r4, #5
	add r1, sp, #0x1c
	add r2, r6, r0
	add r1, r1, r3
	lsl r5, r2, #1
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0x10]
	mov r0, #0
	add r2, r2, r5
	add r3, r3, r5
_02260DEA:
	ldrh r5, [r1]
	add r0, r0, #1
	strh r5, [r2]
	ldrh r5, [r1]
	add r1, r1, #2
	add r2, r2, #2
	strh r5, [r3]
	add r3, r3, #2
	cmp r0, #0x10
	blt _02260DEA
	ldr r1, [r7]
	add r4, r4, #1
	add r0, r1, #0
	add r0, #0x30
	ldrb r5, [r0]
	cmp r4, r5
	blt _02260DC0
_02260E0C:
	add sp, #0x9c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02260E10: .word 0x00002716
_02260E14: .word ov93_02262C8A
_02260E18: .word ov93_02262D04
	thumb_func_end ov93_02260CF8


	thumb_func_start ov93_02260E1C
ov93_02260E1C: ; 0x02260E1C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	ldr r0, [r5, #0x28]
	ldr r1, _02260F08 ; =0x00002716
	mov r2, #2
	bl SpriteManager_FindPlttResourceOffset
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [r5]
	add r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	ble _02260E76
	ldr r0, [sp, #4]
	ldr r7, _02260F0C ; =ov93_02262C82
	lsl r0, r0, #4
	add r4, sp, #0x14
	str r0, [sp]
_02260E46:
	ldrh r6, [r7]
	ldr r3, [sp]
	add r0, r5, #0
	add r0, #0x8c
	add r3, r6, r3
	lsl r3, r3, #0x10
	ldr r0, [r0]
	mov r1, #3
	mov r2, #1
	lsr r3, r3, #0x10
	bl PaletteData_GetBufferColorAtIndex
	strh r0, [r4]
	ldr r0, [sp, #0x10]
	add r7, r7, #2
	add r0, r0, #1
	str r0, [sp, #0x10]
	ldr r0, [r5]
	add r4, r4, #2
	add r0, #0x30
	ldrb r1, [r0]
	ldr r0, [sp, #0x10]
	cmp r0, r1
	blt _02260E46
_02260E76:
	bl sub_0203769C
	ldr r3, [r5]
	mov r2, #0
	add r1, r3, #0
	add r1, #0x30
	ldrb r4, [r1]
	cmp r4, #0
	ble _02260E9A
_02260E88:
	add r1, r3, #0
	add r1, #0x2c
	ldrb r1, [r1]
	cmp r0, r1
	beq _02260E9A
	add r2, r2, #1
	add r3, r3, #1
	cmp r2, r4
	blt _02260E88
_02260E9A:
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #3
	bl PaletteData_GetUnfadedBuf
	str r0, [sp, #0xc]
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	mov r1, #3
	bl PaletteData_GetFadedBuf
	ldr r1, [r5]
	str r0, [sp, #8]
	add r0, r1, #0
	add r0, #0x30
	ldrb r6, [r0]
	mov r4, #0
	cmp r6, #0
	ble _02260F02
	ldr r0, [sp, #4]
	lsl r7, r0, #4
_02260EC8:
	add r1, r1, r4
	add r1, #0x2c
	ldrb r1, [r1]
	add r0, r5, #0
	bl ov93_0225E3C4
	lsl r1, r0, #1
	ldr r0, _02260F10 ; =ov93_02262D54
	lsl r2, r6, #3
	add r0, r0, r2
	ldrh r0, [r1, r0]
	lsl r1, r4, #1
	add r2, sp, #0x14
	ldrh r3, [r2, r1]
	add r0, r7, r0
	ldr r2, [sp, #0xc]
	lsl r0, r0, #1
	strh r3, [r2, r0]
	add r2, sp, #0x14
	ldrh r2, [r2, r1]
	ldr r1, [sp, #8]
	add r4, r4, #1
	strh r2, [r1, r0]
	ldr r1, [r5]
	add r0, r1, #0
	add r0, #0x30
	ldrb r6, [r0]
	cmp r4, r6
	blt _02260EC8
_02260F02:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_02260F08: .word 0x00002716
_02260F0C: .word ov93_02262C82
_02260F10: .word ov93_02262D54
	thumb_func_end ov93_02260E1C

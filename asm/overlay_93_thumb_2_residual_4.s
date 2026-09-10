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

	thumb_func_start ov93_0225FEC4
ov93_0225FEC4: ; 0x0225FEC4
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	ldr r0, _0225FF14 ; =0x00002FDC
	add r4, r1, #0
	mov r3, #0
	add r2, r5, #0
_0225FED2:
	ldr r1, [r2, r0]
	cmp r1, #0
	bne _0225FF00
	ldr r2, _0225FF14 ; =0x00002FDC
	mov r6, #0x18
	add r2, r5, r2
	mul r6, r3
	add r0, r5, #0
	add r1, r4, #0
	add r2, r2, r6
	bl ov93_0225FF1C
	str r0, [sp]
	ldr r1, _0225FF18 ; =0x00001560
	ldrb r2, [r4, #1]
	ldrb r3, [r4]
	add r0, r5, #0
	add r1, r5, r1
	bl ov93_02261C58
	add sp, #4
	mov r0, #1
	pop {r3, r4, r5, r6, pc}
_0225FF00:
	add r3, r3, #1
	add r2, #0x18
	cmp r3, #0x28
	blt _0225FED2
	bl GF_AssertFail
	mov r0, #0
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_0225FF14: .word 0x00002FDC
_0225FF18: .word 0x00001560
	thumb_func_end ov93_0225FEC4


	thumb_func_start ov93_0225FF1C
ov93_0225FF1C: ; 0x0225FF1C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r2, #0
	add r7, r0, #0
	ldr r0, [r4]
	add r5, r1, #0
	cmp r0, #0
	beq _0225FF2E
	bl GF_AssertFail
_0225FF2E:
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x18
	bl MI_CpuFill8
	ldrb r1, [r5]
	add r0, r7, #0
	bl ov93_0225E3C4
	ldr r1, [r7]
	ldr r3, _0225FFF4 ; =ov93_02263010
	add r1, #0x30
	ldrb r2, [r1]
	mov r1, #0x28
	mul r1, r2
	mov r2, #0xa
	mul r2, r0
	ldrb r0, [r5]
	add r1, r3, r1
	add r6, r1, r2
	strh r0, [r4, #4]
	ldrh r0, [r5, #2]
	add r1, r6, #0
	strh r0, [r4, #6]
	ldr r0, [r5, #8]
	str r0, [r4, #8]
	str r6, [r4, #0x14]
	ldrb r0, [r5, #1]
	strb r0, [r4, #0xe]
	add r0, r7, #0
	bl ov93_0226027C
	str r0, [r4, #0x10]
	bl sub_0203769C
	ldrb r1, [r5]
	cmp r1, r0
	bne _0225FF8E
	ldr r1, [r5, #4]
	add r0, r7, #0
	bl ov93_0225DF38
	mov r0, #0x19
	strh r0, [r4, #0xc]
	ldr r0, [r4, #0x10]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_0225FF8E:
	mov r0, #1
	str r0, [r4]
	add r1, sp, #0
	mov r3, #0x16
	ldr r0, [r4, #0x10]
	add r1, #2
	add r2, sp, #0
	lsl r3, r3, #0x10
	mov r5, #0
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	ldrb r0, [r6, #7]
	cmp r0, #3
	bhi _0225FFE8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225FFB6: ; jump table
	.short _0225FFBE - _0225FFB6 - 2 ; case 0
	.short _0225FFCA - _0225FFB6 - 2 ; case 1
	.short _0225FFD4 - _0225FFB6 - 2 ; case 2
	.short _0225FFDE - _0225FFB6 - 2 ; case 3
_0225FFBE:
	add r1, sp, #0
	add r0, r5, #0
	ldrsh r1, [r1, r0]
	mov r0, #0x1c
	sub r5, r0, r1
	b _0225FFE8
_0225FFCA:
	add r1, sp, #0
	mov r0, #2
	ldrsh r5, [r1, r0]
	sub r5, #0xcc
	b _0225FFE8
_0225FFD4:
	add r1, sp, #0
	add r0, r5, #0
	ldrsh r5, [r1, r0]
	sub r5, #0xa4
	b _0225FFE8
_0225FFDE:
	add r1, sp, #0
	mov r0, #2
	ldrsh r1, [r1, r0]
	mov r0, #0x34
	sub r5, r0, r1
_0225FFE8:
	mov r1, #5
	lsl r0, r5, #0xc
	lsl r1, r1, #0xc
	bl _s32_div_f
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225FFF4: .word ov93_02263010
	thumb_func_end ov93_0225FF1C


	thumb_func_start ov93_0225FFF8
ov93_0225FFF8: ; 0x0225FFF8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _02260070 ; =0x00002FDC
	mov r6, #0
	add r4, r5, r0
	add r7, r6, #0
_02260004:
	ldr r0, [r4]
	cmp r0, #1
	bne _02260064
	mov r0, #0xc
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _0226002C
	mov r0, #0xc
	ldrsh r0, [r4, r0]
	sub r0, r0, #1
	strh r0, [r4, #0xc]
	mov r0, #0xc
	ldrsh r0, [r4, r0]
	cmp r0, #0
	bne _02260064
	ldr r0, [r4, #0x10]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	b _02260064
_0226002C:
	add r0, r5, #0
	add r1, r4, #0
	bl ov93_02260080
	cmp r0, #1
	bne _02260064
	ldr r0, _02260074 ; =0x00002FCC
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _0226005C
	ldr r0, _02260078 ; =0x00002FBC
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _0226005C
	ldrb r0, [r4, #0xe]
	ldr r1, _0226007C ; =0x00001428
	mov r3, #4
	str r0, [sp]
	ldrsh r3, [r4, r3]
	ldr r2, [r4, #8]
	add r0, r5, #0
	add r1, r5, r1
	bl ov93_0225FE08
_0226005C:
	ldr r0, [r4, #0x10]
	bl Sprite_DeleteAndFreeResources
	str r7, [r4]
_02260064:
	add r6, r6, #1
	add r4, #0x18
	cmp r6, #0x28
	blt _02260004
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02260070: .word 0x00002FDC
_02260074: .word 0x00002FCC
_02260078: .word 0x00002FBC
_0226007C: .word 0x00001428
	thumb_func_end ov93_0225FFF8


	thumb_func_start ov93_02260080
ov93_02260080: ; 0x02260080
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	str r0, [sp]
	add r1, sp, #4
	mov r3, #0x16
	ldr r0, [r4, #0x10]
	add r1, #2
	add r2, sp, #4
	lsl r3, r3, #0x10
	mov r7, #0
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	ldr r0, [r4, #0x14]
	ldrb r0, [r0, #7]
	cmp r0, #3
	bhi _02260188
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022600AE: ; jump table
	.short _022600B6 - _022600AE - 2 ; case 0
	.short _022600EC - _022600AE - 2 ; case 1
	.short _02260120 - _022600AE - 2 ; case 2
	.short _02260152 - _022600AE - 2 ; case 3
_022600B6:
	add r0, sp, #4
	add r1, r7, #0
	ldrsh r2, [r0, r1]
	mov r0, #0x1c
	sub r6, r0, r2
	mov r2, #5
	ldr r0, [r4, #0x10]
	lsl r2, r2, #0xc
	bl ManagedSprite_AddSpritePrecisePositionXY
	add r1, sp, #8
	mov r3, #0x16
	ldr r0, [r4, #0x10]
	add r1, #2
	add r2, sp, #8
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #4
	mov r0, #4
	ldrsh r1, [r1, r0]
	mov r0, #0x1c
	sub r5, r0, r1
	cmp r1, #0x4a
	ble _02260188
	mov r7, #1
	b _02260188
_022600EC:
	add r1, sp, #4
	mov r0, #2
	ldrsh r6, [r1, r0]
	ldr r0, [r4, #0x10]
	ldr r1, _02260270 ; =0xFFFFB000
	add r2, r7, #0
	sub r6, #0xcc
	bl ManagedSprite_AddSpritePrecisePositionXY
	add r1, sp, #8
	mov r3, #0x16
	ldr r0, [r4, #0x10]
	add r1, #2
	add r2, sp, #8
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #4
	mov r0, #6
	ldrsh r0, [r1, r0]
	add r5, r0, #0
	sub r5, #0xcc
	cmp r0, #0x98
	bge _02260188
	mov r7, #1
	b _02260188
_02260120:
	add r0, sp, #4
	add r1, r7, #0
	ldrsh r6, [r0, r1]
	ldr r0, [r4, #0x10]
	ldr r2, _02260270 ; =0xFFFFB000
	sub r6, #0xa4
	bl ManagedSprite_AddSpritePrecisePositionXY
	add r1, sp, #8
	mov r3, #0x16
	ldr r0, [r4, #0x10]
	add r1, #2
	add r2, sp, #8
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #4
	mov r0, #4
	ldrsh r0, [r1, r0]
	add r5, r0, #0
	sub r5, #0xa4
	cmp r0, #0x72
	bge _02260188
	mov r7, #1
	b _02260188
_02260152:
	add r1, sp, #4
	mov r0, #2
	ldrsh r1, [r1, r0]
	mov r0, #0x34
	add r2, r7, #0
	sub r6, r0, r1
	mov r1, #5
	ldr r0, [r4, #0x10]
	lsl r1, r1, #0xc
	bl ManagedSprite_AddSpritePrecisePositionXY
	add r1, sp, #8
	mov r3, #0x16
	ldr r0, [r4, #0x10]
	add r1, #2
	add r2, sp, #8
	lsl r3, r3, #0x10
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r1, sp, #4
	mov r0, #6
	ldrsh r1, [r1, r0]
	mov r0, #0x34
	sub r5, r0, r1
	cmp r1, #0x68
	ble _02260188
	mov r7, #1
_02260188:
	cmp r5, #0
	blt _022601B8
	cmp r5, #0xe
	bge _022601F0
	lsl r0, r5, #0xc
	mov r1, #0xe
	bl _s32_div_f
	mov r1, #1
	lsl r1, r1, #0xa
	cmp r0, r1
	bge _022601A2
	add r0, r1, #0
_022601A2:
	bl _fflt
	ldr r1, _02260274 ; =0x45800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, [r4, #0x10]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	b _022601F0
_022601B8:
	mov r0, #0xd
	mvn r0, r0
	cmp r5, r0
	ble _022601F0
	ldrb r0, [r4, #0xe]
	neg r1, r5
	lsl r2, r0, #2
	ldr r0, _02260278 ; =ov93_02262CA4
	ldr r0, [r0, r2]
	mul r0, r1
	mov r1, #0xe
	bl _s32_div_f
	mov r1, #1
	lsl r1, r1, #0xa
	cmp r0, r1
	bge _022601DC
	add r0, r1, #0
_022601DC:
	bl _fflt
	ldr r1, _02260274 ; =0x45800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, [r4, #0x10]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
_022601F0:
	bl sub_0203769C
	mov r1, #4
	ldrsh r1, [r4, r1]
	cmp r1, r0
	bne _02260260
	cmp r6, #0
	blt _02260260
	cmp r5, #0
	bgt _02260260
	ldr r0, [sp]
	add r1, sp, #0xc
	bl ov93_022614F4
	strb r0, [r4, #0xe]
	ldrb r0, [r4, #0xe]
	cmp r0, #1
	beq _0226021E
	cmp r0, #2
	beq _02260226
	cmp r0, #3
	beq _02260232
	b _0226023A
_0226021E:
	ldr r0, [r4, #8]
	lsl r0, r0, #1
	str r0, [r4, #8]
	b _0226023A
_02260226:
	ldr r1, [r4, #8]
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	str r0, [r4, #8]
	b _0226023A
_02260232:
	ldr r1, [r4, #8]
	lsl r0, r1, #1
	add r0, r1, r0
	str r0, [r4, #8]
_0226023A:
	ldrb r1, [r4, #0xe]
	ldr r0, [sp]
	bl ov93_02260FB8
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _02260250
	ldr r0, [sp, #0xc]
	mov r1, #3
	bl ov93_02261528
_02260250:
	ldr r0, [sp]
	bl ov93_02260F84
	add r1, r0, #0
	beq _02260260
	ldr r0, [sp]
	bl ov93_022627E8
_02260260:
	cmp r7, #1
	bne _0226026A
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0226026A:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02260270: .word 0xFFFFB000
_02260274: .word 0x45800000
_02260278: .word ov93_02262CA4
	thumb_func_end ov93_02260080


	thumb_func_start ov93_0226027C
ov93_0226027C: ; 0x0226027C
	push {r3, r4, r5, r6, lr}
	sub sp, #0x34
	ldr r6, _022602E0 ; =ov93_02262DCC
	add r2, r0, #0
	add r5, r1, #0
	add r4, sp, #0
	mov r3, #6
_0226028A:
	ldmia r6!, {r0, r1}
	stmia r4!, {r0, r1}
	sub r3, r3, #1
	bne _0226028A
	ldr r0, [r6]
	add r1, sp, #0
	str r0, [r4]
	mov r0, #0
	ldrsh r0, [r5, r0]
	strh r0, [r1]
	mov r0, #2
	ldrsh r0, [r5, r0]
	strh r0, [r1, #2]
	ldrb r0, [r5, #6]
	str r0, [sp, #0xc]
	ldr r0, [r2, #0x24]
	ldr r1, [r2, #0x28]
	add r2, sp, #0
	bl SpriteSystem_NewSprite
	mov r1, #0
	mov r2, #2
	mov r3, #0x16
	ldrsh r1, [r5, r1]
	ldrsh r2, [r5, r2]
	lsl r3, r3, #0x10
	add r4, r0, #0
	bl ManagedSprite_SetPositionXYWithSubscreenOffset
	ldrh r1, [r5, #4]
	add r0, r4, #0
	bl ManagedSprite_SetAnim
	add r0, r4, #0
	mov r1, #2
	bl ManagedSprite_SetAffineOverwriteMode
	ldr r0, [r4]
	bl Sprite_TickFrame
	add r0, r4, #0
	add sp, #0x34
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_022602E0: .word ov93_02262DCC
	thumb_func_end ov93_0226027C

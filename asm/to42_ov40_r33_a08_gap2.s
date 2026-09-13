	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public MI_CpuCopy8
	.public ManagedSprite_SetDrawFlag
	.public ManagedSprite_SetDrawPriority
	.public SpriteManager_UnloadCharObjById
	.public ov39_022271C0
	.public ov40_0222BF80
	.public ov40_0222DEAC
	.public ov40_0222FEA0
	.public ov40_0222FF48
	.public ov40_0222FF64
	.public ov40_022303B8
	.public ov40_02230944
	.public ov40_02230964
	.public ov40_0223A3BC
	.public ov40_0223CE38
	.public ov40_0223CE64
	.public ov40_0223CF00
	.public ov40_0223CF70
	.public ov40_0223CFA8
	.public ov40_0223D008
	.public ov40_0223D1AC
	.public ov40_0223D1F0
	.public ov40_0223D244
	.public ov40_0224551C
	.public ov40_0224554C
	.public sub_0202FC48
	.public sub_02030920
	.public sub_020314A4
	.text


	thumb_func_start ov40_0223D244
ov40_0223D244: ; 0x0223D244
	push {r4, r5, r6, r7, lr}
	sub sp, #0xa4
	mov r1, #0
	str r1, [sp, #0x20]
	ldr r2, [sp, #0x20]
	add r1, sp, #0x8c
	str r2, [r1]
	str r2, [r1, #4]
	str r2, [r1, #8]
	str r2, [r1, #0xc]
	str r2, [r1, #0x10]
	str r2, [r1, #0x14]
	mov r2, #0x86
	lsl r2, r2, #4
	add r1, r0, #0
	ldr r1, [r1, r2]
	ldr r2, _0223D4E0 ; =0x00002084
	str r1, [sp, #0x1c]
	ldr r3, [r1, r2]
	ldr r2, _0223D4E4 ; =0x000004A4
	add r1, r0, #0
	ldrsh r1, [r1, r2]
	str r0, [sp, #8]
	cmp r3, r1
	bne _0223D278
	b _0223D4DA
_0223D278:
	mov r1, #1
	bl ov40_02230964
	ldr r1, _0223D4E0 ; =0x00002084
	ldr r0, [sp, #0x1c]
	ldr r2, [r0, r1]
	ldr r1, _0223D4E4 ; =0x000004A4
	ldr r0, [sp, #8]
	ldrsh r0, [r0, r1]
	cmp r2, r0
	ble _0223D292
	mov r0, #4
	str r0, [sp, #0x20]
_0223D292:
	ldr r0, [sp, #0x20]
	mov r1, #0x30
	mul r1, r0
	ldr r0, [sp, #0x1c]
	mov r6, #0
	add r4, r0, r1
	add r5, sp, #0x8c
	add r7, r6, #0
_0223D2A2:
	ldr r0, _0223D4E8 ; =0x00002090
	ldr r2, [r4, r0]
	cmp r2, #0
	beq _0223D2BE
	ldr r1, _0223D4EC ; =0x0000208C
	ldr r0, [sp, #8]
	ldr r1, [r4, r1]
	bl ov40_0222FF64
	ldr r0, _0223D4EC ; =0x0000208C
	ldr r0, [r4, r0]
	str r0, [r5]
	ldr r0, _0223D4E8 ; =0x00002090
	str r7, [r4, r0]
_0223D2BE:
	add r6, r6, #1
	add r4, #8
	add r5, r5, #4
	cmp r6, #6
	blt _0223D2A2
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _0223D308
	ldr r2, _0223D4F0 ; =0x00002060
	ldr r7, [sp, #0x1c]
	mov r0, #4
	add r3, r2, #0
	add r5, r2, #0
	str r0, [sp, #0xc]
	add r7, #0xc0
	add r3, #0x30
	sub r4, r2, #4
	add r5, #0x2c
_0223D2E2:
	mov r0, #0
	add r1, r7, #0
_0223D2E6:
	ldr r6, [r1, r2]
	add r0, r0, #1
	str r6, [r1, r3]
	ldr r6, [r1, r4]
	str r6, [r1, r5]
	add r1, #8
	cmp r0, #6
	blt _0223D2E6
	ldr r0, [sp, #0xc]
	sub r7, #0x30
	sub r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #1
	bge _0223D2E2
	mov r0, #0
	str r0, [sp, #0x10]
	b _0223D340
_0223D308:
	ldr r6, _0223D4E8 ; =0x00002090
	ldr r7, [sp, #0x1c]
	mov r0, #1
	add r2, r6, #0
	add r4, r6, #0
	mov ip, r0
	add r7, #0x30
	sub r2, #0x30
	sub r3, r6, #4
	sub r4, #0x34
_0223D31C:
	mov r1, #0
	add r0, r7, #0
_0223D320:
	ldr r5, [r0, r6]
	add r1, r1, #1
	str r5, [r0, r2]
	ldr r5, [r0, r3]
	str r5, [r0, r4]
	add r0, #8
	cmp r1, #6
	blt _0223D320
	mov r0, ip
	add r0, r0, #1
	add r7, #0x30
	mov ip, r0
	cmp r0, #5
	blt _0223D31C
	mov r0, #4
	str r0, [sp, #0x10]
_0223D340:
	ldr r1, _0223D4E4 ; =0x000004A4
	ldr r0, [sp, #8]
	ldr r5, _0223D4F4 ; =ov40_0224551C
	ldrsh r1, [r0, r1]
	ldr r0, [sp, #0x10]
	add r4, sp, #0x5c
	add r2, r1, r0
	mov r3, #6
_0223D350:
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	sub r3, r3, #1
	bne _0223D350
	add r0, sp, #0x44
	mov r4, #0
	str r4, [r0]
	str r4, [r0, #4]
	str r4, [r0, #8]
	str r4, [r0, #0xc]
	str r4, [r0, #0x10]
	str r4, [r0, #0x14]
	add r0, sp, #0x2c
	str r4, [r0]
	str r4, [r0, #4]
	str r4, [r0, #8]
	str r4, [r0, #0xc]
	str r4, [r0, #0x10]
	str r4, [r0, #0x14]
	lsl r0, r2, #2
	str r0, [sp, #0x14]
	ldr r1, _0223D4F8 ; =0x00002608
	ldr r0, [sp, #8]
	add r1, r0, r1
	ldr r0, [sp, #0x14]
	str r1, [sp, #0x24]
	ldr r0, [r1, r0]
	add r0, #0x80
	bl ov40_022303B8
	cmp r0, #0
	beq _0223D392
	mov r4, #1
_0223D392:
	mov r0, #0
	str r0, [sp, #0x18]
	add r1, sp, #0x44
	add r2, sp, #0x2c
	add r6, r0, #0
_0223D39C:
	stmia r1!, {r6}
	add r0, r0, #1
	stmia r2!, {r6}
	cmp r0, #6
	blt _0223D39C
	mov r0, #0x18
	mul r0, r4
	add r1, sp, #0x5c
	add r2, r1, r0
	str r0, [sp, #0x28]
	ldr r1, [sp, #8]
	ldr r0, [sp, #0x14]
	add r3, sp, #0x44
	add r5, sp, #0x2c
	add r4, r1, r0
_0223D3BA:
	ldr r0, _0223D4F8 ; =0x00002608
	ldr r7, [r2]
	ldr r1, [r4, r0]
	lsl r0, r7, #1
	add r0, r1, r0
	add r0, #0x80
	ldrh r0, [r0]
	cmp r0, #0
	beq _0223D3E0
	stmia r3!, {r0}
	ldr r0, _0223D4F8 ; =0x00002608
	ldr r0, [r4, r0]
	add r0, r0, r7
	add r0, #0x98
	ldrb r0, [r0]
	stmia r5!, {r0}
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
_0223D3E0:
	add r6, r6, #1
	add r2, r2, #4
	cmp r6, #3
	blt _0223D3BA
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x14]
	ldr r0, [r1, r0]
	add r0, #0x80
	bl ov40_022303B8
	cmp r0, #0
	beq _0223D3FC
	mov r0, #3
	str r0, [sp, #0x18]
_0223D3FC:
	ldr r0, [sp, #0x28]
	add r1, sp, #0x5c
	add r2, r1, r0
	ldr r0, [sp, #0x18]
	mov r6, #3
	lsl r1, r0, #2
	add r0, sp, #0x44
	add r3, r0, r1
	add r0, sp, #0x2c
	add r2, #0xc
	add r5, r0, r1
_0223D412:
	ldr r0, _0223D4F8 ; =0x00002608
	ldr r7, [r2]
	ldr r1, [r4, r0]
	lsl r0, r7, #1
	add r0, r1, r0
	add r0, #0x80
	ldrh r0, [r0]
	cmp r0, #0
	beq _0223D438
	stmia r3!, {r0}
	ldr r0, _0223D4F8 ; =0x00002608
	ldr r0, [r4, r0]
	add r0, r0, r7
	add r0, #0x98
	ldrb r0, [r0]
	stmia r5!, {r0}
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
_0223D438:
	add r6, r6, #1
	add r2, r2, #4
	cmp r6, #6
	blt _0223D412
	ldr r0, [sp, #0x10]
	mov r1, #0x30
	mul r1, r0
	ldr r0, [sp, #0x1c]
	mov r5, #0
	add r7, sp, #0x44
	add r6, sp, #0x2c
	add r4, r0, r1
_0223D450:
	ldr r2, [sp, #0x1c]
	ldr r1, _0223D4FC ; =0x00002088
	ldr r3, [r7]
	ldr r2, [r2, r1]
	ldr r0, [r6]
	add r1, r1, #4
	str r2, [r4, r1]
	str r0, [sp]
	mov r0, #0
	mov r1, #0x82
	str r0, [sp, #4]
	ldr r2, [sp, #0x1c]
	lsl r1, r1, #6
	ldr r1, [r2, r1]
	ldr r2, _0223D4EC ; =0x0000208C
	ldr r0, [sp, #8]
	ldr r2, [r4, r2]
	bl ov40_0222FEA0
	ldr r1, _0223D4E8 ; =0x00002090
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0223D48A
	mov r1, #6
	sub r1, r1, r5
	bl ManagedSprite_SetDrawPriority
_0223D48A:
	ldr r1, [sp, #0x1c]
	ldr r0, _0223D4FC ; =0x00002088
	add r5, r5, #1
	ldr r0, [r1, r0]
	add r7, r7, #4
	add r2, r0, #1
	ldr r0, _0223D4FC ; =0x00002088
	add r6, r6, #4
	add r4, #8
	str r2, [r1, r0]
	cmp r5, #6
	blt _0223D450
	ldr r0, [sp, #8]
	bl ov40_0223A3BC
	ldr r1, _0223D4E4 ; =0x000004A4
	ldr r0, [sp, #8]
	ldr r6, _0223D500 ; =0x000186A0
	ldrsh r2, [r0, r1]
	ldr r1, _0223D4E0 ; =0x00002084
	ldr r0, [sp, #0x1c]
	mov r5, #0
	str r2, [r0, r1]
	add r4, sp, #0x8c
_0223D4BA:
	ldr r1, [r4]
	cmp r1, #0
	beq _0223D4CA
	ldr r0, [sp, #8]
	add r1, r1, r6
	ldr r0, [r0, #0x1c]
	bl SpriteManager_UnloadCharObjById
_0223D4CA:
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #6
	blt _0223D4BA
	ldr r0, [sp, #8]
	mov r1, #0
	bl ov40_02230964
_0223D4DA:
	add sp, #0xa4
	pop {r4, r5, r6, r7, pc}
	nop
_0223D4E0: .word 0x00002084
_0223D4E4: .word 0x000004A4
_0223D4E8: .word 0x00002090
_0223D4EC: .word 0x0000208C
_0223D4F0: .word 0x00002060
_0223D4F4: .word ov40_0224551C
_0223D4F8: .word 0x00002608
_0223D4FC: .word 0x00002088
_0223D500: .word 0x000186A0
	thumb_func_end ov40_0223D244

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

	thumb_func_start ov40_0223CE64
ov40_0223CE64: ; 0x0223CE64
	push {r3, r4, r5, lr}
	add r4, r2, #0
	mov r2, #0x86
	lsl r2, r2, #4
	ldr r5, [r4, r2]
	cmp r1, #0
	bne _0223CEF8
	cmp r0, #3
	bhi _0223CEF8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223CE82: ; jump table
	.short _0223CE8A - _0223CE82 - 2 ; case 0
	.short _0223CE9A - _0223CE82 - 2 ; case 1
	.short _0223CEC2 - _0223CE82 - 2 ; case 2
	.short _0223CEEA - _0223CE82 - 2 ; case 3
_0223CE8A:
	add r0, r4, #0
	bl ov40_02230944
	add r0, r4, #0
	mov r1, #8
	bl ov40_0222BF80
	pop {r3, r4, r5, pc}
_0223CE9A:
	add r0, r4, #0
	bl ov40_02230944
	bl sub_0202FC48
	cmp r0, #0
	beq _0223CEB2
	add r0, r4, #0
	mov r1, #9
	bl ov40_0222BF80
	pop {r3, r4, r5, pc}
_0223CEB2:
	ldr r0, _0223CEFC ; =0x00002034
	mov r1, #9
	str r1, [r5, r0]
	add r0, r4, #0
	mov r1, #0x12
	bl ov40_0222BF80
	pop {r3, r4, r5, pc}
_0223CEC2:
	add r0, r4, #0
	bl ov40_02230944
	bl sub_0202FC48
	cmp r0, #0
	beq _0223CEDA
	add r0, r4, #0
	mov r1, #0xb
	bl ov40_0222BF80
	pop {r3, r4, r5, pc}
_0223CEDA:
	ldr r0, _0223CEFC ; =0x00002034
	mov r1, #0xb
	str r1, [r5, r0]
	add r0, r4, #0
	mov r1, #0x12
	bl ov40_0222BF80
	pop {r3, r4, r5, pc}
_0223CEEA:
	add r0, r4, #0
	bl ov40_02230944
	add r0, r4, #0
	mov r1, #0xa
	bl ov40_0222BF80
_0223CEF8:
	pop {r3, r4, r5, pc}
	nop
_0223CEFC: .word 0x00002034
	thumb_func_end ov40_0223CE64


	thumb_func_start ov40_0223CF00
ov40_0223CF00: ; 0x0223CF00
	push {r4, lr}
	add r4, r2, #0
	mov r2, #0x86
	lsl r2, r2, #4
	ldr r3, [r4, r2]
	cmp r1, #0
	bne _0223CF68
	cmp r0, #3
	bhi _0223CF68
	add r1, r0, r0
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0223CF1E: ; jump table
	.short _0223CF26 - _0223CF1E - 2 ; case 0
	.short _0223CF26 - _0223CF1E - 2 ; case 1
	.short _0223CF26 - _0223CF1E - 2 ; case 2
	.short _0223CF54 - _0223CF1E - 2 ; case 3
_0223CF26:
	add r1, r0, #1
	ldr r0, _0223CF6C ; =0x00002028
	add r2, #0x2c
	str r1, [r3, r0]
	ldr r0, [r3, r0]
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, r2]
	cmp r0, #0
	beq _0223CF44
	add r0, r4, #0
	mov r1, #0xe
	bl ov40_0222BF80
	b _0223CF4C
_0223CF44:
	add r0, r4, #0
	mov r1, #0x11
	bl ov40_0222BF80
_0223CF4C:
	add r0, r4, #0
	bl ov40_02230944
	pop {r4, pc}
_0223CF54:
	add r0, r4, #0
	bl ov40_02230944
	add r0, r4, #0
	bl ov40_0222DEAC
	add r0, r4, #0
	mov r1, #0xd
	bl ov40_0222BF80
_0223CF68:
	pop {r4, pc}
	nop
_0223CF6C: .word 0x00002028
	thumb_func_end ov40_0223CF00


	thumb_func_start ov40_0223CF70
ov40_0223CF70: ; 0x0223CF70
	push {r4, lr}
	add r4, r2, #0
	cmp r1, #0
	bne _0223CFA6
	cmp r0, #0
	beq _0223CF82
	cmp r0, #1
	beq _0223CF98
	pop {r4, pc}
_0223CF82:
	add r0, r4, #0
	bl ov40_02230944
	add r0, r4, #0
	bl ov40_0223CE38
	add r0, r4, #0
	mov r1, #0x11
	bl ov40_0222BF80
	pop {r4, pc}
_0223CF98:
	add r0, r4, #0
	bl ov40_02230944
	add r0, r4, #0
	mov r1, #0x10
	bl ov40_0222BF80
_0223CFA6:
	pop {r4, pc}
	thumb_func_end ov40_0223CF70


	thumb_func_start ov40_0223CFA8
ov40_0223CFA8: ; 0x0223CFA8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r4, [r5, r0]
	mov r0, #0x6d
	bl sub_020314A4
	mov r1, #0x65
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, _0223D000 ; =0x000004D4
	ldr r1, [r4, r1]
	ldr r0, [r5, r0]
	lsl r0, r0, #2
	add r2, r5, r0
	ldr r0, _0223D004 ; =0x00002608
	ldr r0, [r2, r0]
	bl ov39_022271C0
	mov r0, #0x65
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	add r0, #0x8c
	str r1, [r4, r0]
	mov r0, #0x6d
	bl sub_02030920
	mov r1, #0x89
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, _0223D000 ; =0x000004D4
	ldr r1, [r4, r1]
	ldr r0, [r5, r0]
	lsl r0, r0, #2
	add r2, r5, r0
	ldr r0, _0223D004 ; =0x00002608
	ldr r0, [r2, r0]
	mov r2, #0x64
	add r0, #0x80
	bl MI_CpuCopy8
	pop {r3, r4, r5, pc}
	nop
_0223D000: .word 0x000004D4
_0223D004: .word 0x00002608
	thumb_func_end ov40_0223CFA8


	thumb_func_start ov40_0223D008
ov40_0223D008: ; 0x0223D008
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x80
	mov r1, #0x86
	lsl r1, r1, #4
	str r0, [sp, #8]
	ldr r0, [r0, r1]
	ldr r1, _0223D194 ; =0x000004A4
	str r0, [sp, #0x14]
	ldr r0, [sp, #8]
	ldr r5, _0223D198 ; =ov40_0224554C
	ldrsh r2, [r0, r1]
	add r4, sp, #0x50
	mov r3, #6
_0223D022:
	ldmia r5!, {r0, r1}
	stmia r4!, {r0, r1}
	sub r3, r3, #1
	bne _0223D022
	mov r1, #0
	add r0, sp, #0x38
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	str r1, [r0, #0xc]
	str r1, [r0, #0x10]
	str r1, [r0, #0x14]
	add r0, sp, #0x20
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	str r1, [r0, #0xc]
	str r1, [r0, #0x10]
	str r1, [r0, #0x14]
	str r1, [sp, #0x18]
	ldr r0, [sp, #8]
	lsl r1, r2, #2
	add r0, r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0xc]
_0223D056:
	ldr r1, _0223D19C ; =0x00002608
	ldr r0, [sp, #0x10]
	ldr r0, [r0, r1]
	cmp r0, #0
	bne _0223D062
	b _0223D170
_0223D062:
	add r0, #0x80
	bl ov40_022303B8
	cmp r0, #0
	beq _0223D070
	mov r0, #1
	b _0223D072
_0223D070:
	mov r0, #0
_0223D072:
	mov r7, #0
	add r1, r7, #0
	add r2, sp, #0x38
	add r4, sp, #0x20
	add r3, r7, #0
_0223D07C:
	stmia r2!, {r3}
	add r1, r1, #1
	stmia r4!, {r3}
	cmp r1, #6
	blt _0223D07C
	mov r1, #0x18
	mul r1, r0
	add r0, sp, #0x50
	str r1, [sp, #0x1c]
	add r0, r0, r1
	add r1, sp, #0x38
	add r2, sp, #0x20
_0223D094:
	ldr r5, [sp, #0x10]
	ldr r4, _0223D19C ; =0x00002608
	ldr r6, [r0]
	ldr r5, [r5, r4]
	lsl r4, r6, #1
	add r4, r5, r4
	add r4, #0x80
	ldrh r4, [r4]
	cmp r4, #0
	beq _0223D0BA
	stmia r1!, {r4}
	ldr r5, [sp, #0x10]
	ldr r4, _0223D19C ; =0x00002608
	add r7, r7, #1
	ldr r4, [r5, r4]
	add r4, r4, r6
	add r4, #0x98
	ldrb r4, [r4]
	stmia r2!, {r4}
_0223D0BA:
	add r3, r3, #1
	add r0, r0, #4
	cmp r3, #3
	blt _0223D094
	ldr r1, _0223D19C ; =0x00002608
	ldr r0, [sp, #0x10]
	ldr r0, [r0, r1]
	add r0, #0x80
	bl ov40_022303B8
	cmp r0, #0
	beq _0223D0D4
	mov r7, #3
_0223D0D4:
	ldr r0, [sp, #0x1c]
	add r1, sp, #0x50
	add r0, r1, r0
	lsl r4, r7, #2
	add r1, sp, #0x38
	add r2, sp, #0x20
	mov r3, #3
	add r0, #0xc
	add r1, r1, r4
	add r2, r2, r4
_0223D0E8:
	ldr r5, [sp, #0x10]
	ldr r4, _0223D19C ; =0x00002608
	ldr r6, [r0]
	ldr r5, [r5, r4]
	lsl r4, r6, #1
	add r4, r5, r4
	add r4, #0x80
	ldrh r4, [r4]
	cmp r4, #0
	beq _0223D10E
	stmia r1!, {r4}
	ldr r5, [sp, #0x10]
	ldr r4, _0223D19C ; =0x00002608
	add r7, r7, #1
	ldr r4, [r5, r4]
	add r4, r4, r6
	add r4, #0x98
	ldrb r4, [r4]
	stmia r2!, {r4}
_0223D10E:
	add r3, r3, #1
	add r0, r0, #4
	cmp r3, #6
	blt _0223D0E8
	ldr r5, [sp, #0xc]
	mov r7, #0
	add r6, sp, #0x38
	add r4, sp, #0x20
_0223D11E:
	ldr r2, [sp, #0x14]
	ldr r1, _0223D1A0 ; =0x00002088
	ldr r3, [r6]
	ldr r2, [r2, r1]
	ldr r0, [r4]
	add r1, r1, #4
	str r2, [r5, r1]
	str r0, [sp]
	mov r0, #0
	mov r1, #0x82
	str r0, [sp, #4]
	ldr r2, [sp, #0x14]
	lsl r1, r1, #6
	ldr r1, [r2, r1]
	ldr r2, _0223D1A4 ; =0x0000208C
	ldr r0, [sp, #8]
	ldr r2, [r5, r2]
	bl ov40_0222FEA0
	ldr r1, _0223D1A8 ; =0x00002090
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0223D158
	mov r1, #6
	sub r1, r1, r7
	bl ManagedSprite_SetDrawPriority
_0223D158:
	ldr r1, [sp, #0x14]
	ldr r0, _0223D1A0 ; =0x00002088
	add r7, r7, #1
	ldr r0, [r1, r0]
	add r6, r6, #4
	add r2, r0, #1
	ldr r0, _0223D1A0 ; =0x00002088
	add r4, r4, #4
	add r5, #8
	str r2, [r1, r0]
	cmp r7, #6
	blt _0223D11E
_0223D170:
	ldr r0, [sp, #0x10]
	add r0, r0, #4
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #5
	bge _0223D188
	b _0223D056
_0223D188:
	ldr r0, [sp, #8]
	bl ov40_0223A3BC
	add sp, #0x80
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223D194: .word 0x000004A4
_0223D198: .word ov40_0224554C
_0223D19C: .word 0x00002608
_0223D1A0: .word 0x00002088
_0223D1A4: .word 0x0000208C
_0223D1A8: .word 0x00002090
	thumb_func_end ov40_0223D008


	thumb_func_start ov40_0223D1AC
ov40_0223D1AC: ; 0x0223D1AC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r1, #0
	mov r1, #0
	str r1, [sp, #4]
	mov r1, #0x86
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	ldr r7, _0223D1EC ; =0x00002090
	str r0, [sp]
_0223D1C0:
	ldr r5, [sp]
	mov r4, #0
_0223D1C4:
	ldr r0, [r5, r7]
	cmp r0, #0
	beq _0223D1D0
	add r1, r6, #0
	bl ManagedSprite_SetDrawFlag
_0223D1D0:
	add r4, r4, #1
	add r5, #8
	cmp r4, #6
	blt _0223D1C4
	ldr r0, [sp]
	add r0, #0x30
	str r0, [sp]
	ldr r0, [sp, #4]
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #5
	blt _0223D1C0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0223D1EC: .word 0x00002090
	thumb_func_end ov40_0223D1AC


	thumb_func_start ov40_0223D1F0
ov40_0223D1F0: ; 0x0223D1F0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r7, #0
	str r0, [sp]
_0223D204:
	ldr r5, [sp]
	mov r4, #0
_0223D208:
	ldr r0, _0223D23C ; =0x00002090
	ldr r2, [r5, r0]
	cmp r2, #0
	beq _0223D21E
	ldr r1, _0223D240 ; =0x0000208C
	add r0, r6, #0
	ldr r1, [r5, r1]
	bl ov40_0222FF48
	ldr r0, _0223D23C ; =0x00002090
	str r7, [r5, r0]
_0223D21E:
	add r4, r4, #1
	add r5, #8
	cmp r4, #6
	blt _0223D208
	ldr r0, [sp]
	add r0, #0x30
	str r0, [sp]
	ldr r0, [sp, #4]
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #5
	blt _0223D204
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223D23C: .word 0x00002090
_0223D240: .word 0x0000208C
	thumb_func_end ov40_0223D1F0


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

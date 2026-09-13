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

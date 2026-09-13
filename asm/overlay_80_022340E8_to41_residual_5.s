	.include "asm/macros.inc"
	.include "overlay_80_022340E8.inc"
	.include "global.inc"

    .text

	thumb_func_start ov80_02234A74
ov80_02234A74: ; 0x02234A74
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp, #4]
	ldrb r0, [r0, #0x10]
	str r1, [sp, #8]
	mov r1, #1
	add r4, r2, #0
	bl BattleArcade_GetMonCount
	add r7, r0, #0
	ldr r0, [sp, #4]
	mov r1, #1
	ldrb r0, [r0, #0x10]
	bl BattleArcade_GetOpponentMonCount
	str r0, [sp, #0xc]
	cmp r4, #0
	bne _02234AD8
	mov r4, #0
	cmp r7, #0
	ble _02234B18
	ldr r5, _02234B1C ; =ov80_0223BEB8
	ldr r6, [sp, #4]
_02234AA2:
	ldr r0, [sp, #4]
	add r1, r4, #0
	ldr r0, [r0, #0x70]
	bl Party_GetMonByIndex
	add r1, r0, #0
	mov r0, #2
	ldrsh r0, [r5, r0]
	mov r3, #0
	add r2, r4, #0
	str r0, [sp]
	ldrsh r3, [r5, r3]
	ldr r0, [sp, #8]
	bl ov80_0222F29C
	str r0, [r6, #0x30]
	ldr r0, [r0]
	mov r1, #0
	bl Sprite_SetAnimActiveFlag
	add r4, r4, #1
	add r5, r5, #4
	add r6, r6, #4
	cmp r4, r7
	blt _02234AA2
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_02234AD8:
	mov r6, #0
	cmp r0, #0
	ble _02234B18
	ldr r4, _02234B20 ; =ov80_0223BEC8
	ldr r5, [sp, #4]
_02234AE2:
	ldr r0, [sp, #4]
	add r1, r6, #0
	ldr r0, [r0, #0x74]
	bl Party_GetMonByIndex
	add r1, r0, #0
	mov r0, #2
	ldrsh r0, [r4, r0]
	mov r3, #0
	add r2, r7, #0
	str r0, [sp]
	ldrsh r3, [r4, r3]
	ldr r0, [sp, #8]
	bl ov80_0222F29C
	str r0, [r5, #0x40]
	ldr r0, [r0]
	mov r1, #0
	bl Sprite_SetAnimActiveFlag
	ldr r0, [sp, #0xc]
	add r6, r6, #1
	add r4, r4, #4
	add r7, r7, #1
	add r5, r5, #4
	cmp r6, r0
	blt _02234AE2
_02234B18:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02234B1C: .word ov80_0223BEB8
_02234B20: .word ov80_0223BEC8
	thumb_func_end ov80_02234A74

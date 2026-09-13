	.include "asm/macros.inc"
	.include "overlay_80_022340E8.inc"
	.include "global.inc"

    .text

	thumb_func_start ov80_02234BEC
ov80_02234BEC: ; 0x02234BEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	ldrb r0, [r7, #0x10]
	str r1, [sp]
	mov r1, #1
	add r4, r2, #0
	bl BattleArcade_GetMonCount
	str r0, [sp, #8]
	ldrb r0, [r7, #0x10]
	mov r1, #1
	bl BattleArcade_GetOpponentMonCount
	str r0, [sp, #4]
	cmp r4, #0
	bne _02234C5C
	ldr r0, [sp, #8]
	mov r6, #0
	cmp r0, #0
	ble _02234CA4
	ldr r4, _02234CA8 ; =ov80_0223BEB8
	add r5, r7, #0
_02234C1A:
	mov r1, #0
	mov r2, #2
	ldrsh r1, [r4, r1]
	ldrsh r2, [r4, r2]
	ldr r0, [sp]
	add r1, #8
	add r2, r2, #4
	bl ov80_0222F3FC
	str r0, [r5, #0x50]
	ldr r0, [r7, #0x70]
	add r1, r6, #0
	bl Party_GetMonByIndex
	mov r1, #6
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02234C4C
	ldr r0, [r5, #0x50]
	mov r1, #0
	ldr r0, [r0]
	bl Sprite_SetDrawFlag
_02234C4C:
	ldr r0, [sp, #8]
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r6, r0
	blt _02234C1A
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_02234C5C:
	mov r6, #0
	cmp r0, #0
	ble _02234CA4
	ldr r4, _02234CAC ; =ov80_0223BEC8
	add r5, r7, #0
_02234C66:
	mov r1, #0
	mov r2, #2
	ldrsh r1, [r4, r1]
	ldrsh r2, [r4, r2]
	ldr r0, [sp]
	add r1, #8
	add r2, r2, #4
	bl ov80_0222F3FC
	str r0, [r5, #0x60]
	ldr r0, [r7, #0x74]
	add r1, r6, #0
	bl Party_GetMonByIndex
	mov r1, #6
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02234C98
	ldr r0, [r5, #0x60]
	mov r1, #0
	ldr r0, [r0]
	bl Sprite_SetDrawFlag
_02234C98:
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r6, r0
	blt _02234C66
_02234CA4:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02234CA8: .word ov80_0223BEB8
_02234CAC: .word ov80_0223BEC8
	thumb_func_end ov80_02234BEC

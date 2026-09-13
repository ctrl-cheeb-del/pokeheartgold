	.include "asm/macros.inc"
	.include "overlay_80_022340E8.inc"
	.include "global.inc"

    .text

	thumb_func_start ov80_02234588
ov80_02234588: ; 0x02234588
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	ldr r0, [r5, #4]
	add r4, r1, #0
	bl sub_02030FA0
	str r0, [sp, #4]
	ldrb r0, [r5, #0x10]
	mov r1, #1
	bl BattleArcade_GetOpponentMonCount
	ldrb r1, [r5, #0x10]
	add r0, sp, #8
	strb r1, [r0, #8]
	mov r1, #0
	add r0, sp, #0x10
	str r0, [sp]
	ldr r0, [r5, #8]
	add r2, r1, #0
	add r3, r1, #0
	bl sub_02030EB4
	ldr r0, [r5, #8]
	mov r1, #1
	bl sub_02030EA0
	mov r2, #0
	ldrb r1, [r5, #0x11]
	add r0, sp, #8
	add r3, r2, #0
	strb r1, [r0, #8]
	add r0, sp, #0x10
	str r0, [sp]
	ldr r0, [r5, #8]
	mov r1, #2
	bl sub_02030EB4
	mov r2, #0
	ldrb r1, [r5, #0x1c]
	add r0, sp, #8
	add r3, r2, #0
	strb r1, [r0, #8]
	add r0, sp, #0x10
	str r0, [sp]
	ldr r0, [r5, #8]
	mov r1, #3
	bl sub_02030EB4
	mov r2, #0
	ldrb r1, [r5, #0x12]
	add r0, sp, #8
	add r3, r2, #0
	strb r1, [r0, #8]
	add r0, sp, #0x10
	str r0, [sp]
	ldr r0, [r5, #8]
	mov r1, #1
	bl sub_02030EB4
	ldr r0, [r5, #4]
	bl Save_Frontier_GetStatic
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C2C0
	add r7, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C2C0
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #0x18]
	add r0, r6, #0
	add r1, r7, #0
	bl sub_02031108
	cmp r4, #2
	beq _0223468E
	ldr r0, [r5, #4]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C2E8
	add r6, r0, #0
	ldrb r0, [r5, #0x10]
	bl sub_0205C2E8
	bl sub_0205C268
	add r2, r0, #0
	ldrh r3, [r5, #0x18]
	add r0, r4, #0
	add r1, r6, #0
	bl sub_0203126C
	add r0, r5, #0
	add r0, #0x2f
	ldrb r1, [r0]
	add r0, sp, #8
	mov r3, #0
	strb r1, [r0, #8]
	add r0, sp, #0x10
	str r0, [sp]
	ldrb r2, [r5, #0x10]
	ldr r0, [sp, #4]
	mov r1, #8
	bl sub_02030FB0
	ldrb r0, [r5, #0x10]
	cmp r0, #3
	bne _0223468E
	ldr r0, [r5, #4]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	mov r0, #0x6e
	bl sub_0205C268
	add r3, r5, #0
	add r3, #0x2f
	add r2, r0, #0
	ldrb r3, [r3]
	add r0, r4, #0
	mov r1, #0x6e
	bl sub_02031108
_0223468E:
	mov r4, #0
	add r6, sp, #8
	add r7, sp, #8
_02234694:
	lsl r0, r4, #1
	add r0, r5, r0
	add r0, #0x78
	ldrh r0, [r0]
	lsl r2, r4, #0x18
	mov r1, #5
	strh r0, [r7]
	str r6, [sp]
	ldr r0, [r5, #8]
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030EB4
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0xe
	blo _02234694
	mov r4, #0
	add r6, sp, #0x10
	add r7, sp, #8
_022346BE:
	add r0, r5, r4
	add r0, #0x2c
	ldrb r0, [r0]
	lsl r2, r4, #0x18
	mov r1, #6
	strb r0, [r7, #8]
	str r6, [sp]
	ldr r0, [r5, #8]
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030EB4
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #3
	blo _022346BE
	ldr r0, [r5, #0x70]
	bl Party_GetCount
	add r6, r0, #0
	ldr r4, _02234760 ; =0x00000000
	beq _0223471C
	add r7, sp, #8
_022346EE:
	ldr r0, [r5, #0x70]
	add r1, r4, #0
	bl Party_GetMonByIndex
	mov r1, #6
	mov r2, #0
	bl GetMonData
	add r1, sp, #8
	strh r0, [r1]
	str r7, [sp]
	lsl r2, r4, #0x18
	ldr r0, [r5, #8]
	mov r1, #4
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030EB4
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, r6
	blo _022346EE
_0223471C:
	ldr r0, [r5, #0x74]
	bl Party_GetCount
	add r6, r0, #0
	ldr r4, _02234760 ; =0x00000000
	beq _0223475A
	add r7, sp, #8
_0223472A:
	ldr r0, [r5, #0x74]
	add r1, r4, #0
	bl Party_GetMonByIndex
	lsl r0, r4, #1
	add r1, r5, r0
	mov r0, #0xc5
	lsl r0, r0, #2
	ldrh r1, [r1, r0]
	add r0, sp, #8
	lsl r2, r4, #0x18
	strh r1, [r0]
	str r7, [sp]
	ldr r0, [r5, #8]
	mov r1, #7
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030EB4
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, r6
	blo _0223472A
_0223475A:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_02234760: .word 0x00000000
	thumb_func_end ov80_02234588

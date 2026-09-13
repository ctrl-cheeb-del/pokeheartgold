	.include "asm/macros.inc"
	.include "overlay_80_022340E8.inc"
	.include "global.inc"

    .text

	thumb_func_start ov80_02234894
ov80_02234894: ; 0x02234894
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r3, [sp, #0xc]
	str r0, [sp]
	mov r4, #0
	ldr r0, [sp, #0xc]
	str r1, [sp, #4]
	str r2, [sp, #8]
	add r5, r4, #0
	add r6, r4, #0
	cmp r0, #0
	ble _022348F2
_022348AC:
	ldr r0, [sp, #4]
	add r1, r6, #0
	bl Party_GetMonByIndex
	mov r1, #0xac
	mov r2, #0
	add r7, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _022348EA
	add r0, r7, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022348D6
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_022348D6:
	add r0, r7, #0
	mov r1, #0xa0
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _022348EA
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
_022348EA:
	ldr r0, [sp, #0xc]
	add r6, r6, #1
	cmp r6, r0
	blt _022348AC
_022348F2:
	ldr r0, [sp]
	ldrb r0, [r0, #0x10]
	bl BattleArcade_MultiplayerCheck
	cmp r0, #1
	bne _0223494C
	ldr r0, [sp, #0xc]
	mov r6, #0
	cmp r0, #0
	ble _0223494C
_02234906:
	ldr r0, [sp, #8]
	add r1, r6, #0
	bl Party_GetMonByIndex
	mov r1, #0xac
	mov r2, #0
	add r7, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _02234944
	add r0, r7, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02234930
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_02234930:
	add r0, r7, #0
	mov r1, #0xa0
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _02234944
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
_02234944:
	ldr r0, [sp, #0xc]
	add r6, r6, #1
	cmp r6, r0
	blt _02234906
_0223494C:
	ldr r0, _02234960 ; =ov80_0223BE90
	ldrb r1, [r0, r5]
	mov r0, #0
	add r1, r0, r1
	ldr r0, _02234964 ; =ov80_0223BE88
	ldrb r0, [r0, r4]
	add r0, r1, r0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02234960: .word ov80_0223BE90
_02234964: .word ov80_0223BE88
	thumb_func_end ov80_02234894

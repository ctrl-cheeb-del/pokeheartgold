#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222F7B4
	.extern ov45_02254EF0
	.extern ov45_0222F74C

thumb_func_start ov45_0222F7B4
ov45_0222F7B4: ; 0x0222F7B4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp, #4]
	ldr r0, [r0, #8]
	bl WifiHistory_GetPlayerCountry
	add r4, r0, #0
	ldr r0, [sp, #4]
	ldr r0, [r0, #8]
	bl WiFiHistory_GetPlayerRegion
	cmp r4, #0
	bne _0222F7D4
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222F7D4:
	ldr r7, _0222F840 ; =0x00000136
	ldr r2, [sp, #4]
	mov r1, #0
	sub r3, r7, #2
	add r5, r7, #1
_0222F7DE:
	ldrb r6, [r2, r5]
	cmp r6, #0
	beq _0222F7FE
	ldrh r6, [r2, r3]
	cmp r4, r6
	bne _0222F7F6
	ldrb r6, [r2, r7]
	cmp r0, r6
	bne _0222F7F6
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222F7F6:
	add r1, r1, #1
	add r2, r2, #4
	cmp r1, #0x14
	blt _0222F7DE
_0222F7FE:
	cmp r1, #0x14
	blt _0222F80C
	bl GF_AssertFail
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222F80C:
	lsl r2, r1, #2
	ldr r1, [sp, #4]
	mov r3, #0x4d
	add r2, r1, r2
	lsl r3, r3, #2
	strh r4, [r2, r3]
	add r1, r3, #2
	strb r0, [r2, r1]
	mov r1, #1
	add r0, r3, #3
	strb r1, [r2, r0]
	mov r0, #0x50
	str r0, [sp]
	ldr r2, _0222F844 ; =ov45_02254EF0
	ldr r4, [sp, #4]
	ldr r2, [r2]
	sub r0, #0x51
	mov r1, #0
	add r3, r4, r3
	bl ov45_022322A4
	bl ov45_0222F74C
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222F840: .word 0x00000136
_0222F844: .word ov45_02254EF0
	thumb_func_end ov45_0222F7B4

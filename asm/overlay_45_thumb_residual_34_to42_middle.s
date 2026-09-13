#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222FA40
	.public ov45_0222FA74
	.public ov45_0222FAF8
	.public ov45_0222FB24
	.public ov45_0222FB5C

thumb_func_start ov45_0222FA40
ov45_0222FA40: ; 0x0222FA40
	push {r3, r4, r5, r6}
	lsl r2, r1, #3
	add r0, r0, r2
	mov r2, #0x47
	mov r1, #0
	lsl r2, r2, #2
	strh r1, [r0, r2]
	add r2, r2, #2
	ldrh r2, [r0, r2]
	cmp r2, #0
	ble _0222FA6E
	mov r2, #0x12
	lsl r2, r2, #4
	add r6, r1, #0
	sub r5, r1, #1
	sub r3, r2, #2
_0222FA60:
	ldr r4, [r0, r2]
	add r1, r1, #1
	str r5, [r4, r6]
	ldrh r4, [r0, r3]
	add r6, r6, #4
	cmp r1, r4
	blt _0222FA60
_0222FA6E:
	pop {r3, r4, r5, r6}
	bx lr
	.balign 4, 0
	thumb_func_end ov45_0222FA40

thumb_func_start ov45_0222FA74
ov45_0222FA74: ; 0x0222FA74
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	str r1, [sp]
	add r4, r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _0222FAF0
	ldr r0, _0222FAF4 ; =0x0000011E
	lsl r4, r4, #3
	add r5, r7, r0
	sub r0, r0, #2
	add r1, r7, r0
	add r0, r1, r4
	str r0, [sp, #4]
	ldrsh r1, [r1, r4]
	ldrh r0, [r5, r4]
	cmp r1, r0
	blt _0222FAA4
	bl GF_AssertFail
_0222FAA4:
	ldr r1, [sp, #4]
	mov r0, #0
	ldrh r2, [r5, r4]
	ldrsh r1, [r1, r0]
	cmp r1, r2
	bge _0222FAF0
	cmp r2, #0
	ble _0222FAD4
	mov r1, #0x12
	add r2, r7, r4
	lsl r1, r1, #4
	ldr r1, [r2, r1]
	ldr r3, _0222FAF4 ; =0x0000011E
	sub r5, r0, #1
_0222FAC0:
	ldr r6, [r1]
	cmp r6, r5
	bne _0222FACA
	str r0, [sp, #8]
	b _0222FAD4
_0222FACA:
	ldrh r6, [r2, r3]
	add r0, r0, #1
	add r1, r1, #4
	cmp r0, r6
	blt _0222FAC0
_0222FAD4:
	mov r0, #0x12
	add r1, r7, r4
	lsl r0, r0, #4
	ldr r2, [r1, r0]
	ldr r0, [sp, #8]
	lsl r1, r0, #2
	ldr r0, [sp]
	str r0, [r2, r1]
	ldr r0, [sp, #4]
	mov r1, #0
	ldrsh r0, [r0, r1]
	add r1, r0, #1
	ldr r0, [sp, #4]
	strh r1, [r0]
_0222FAF0:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222FAF4: .word 0x0000011E
	thumb_func_end ov45_0222FA74

thumb_func_start ov45_0222FAF8
ov45_0222FAF8: ; 0x0222FAF8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FB22
	lsl r2, r4, #3
	mov r3, #0x12
	add r4, r5, r2
	lsl r3, r3, #4
	ldr r4, [r4, r3]
	lsl r0, r0, #2
	str r1, [r4, r0]
	sub r0, r3, #4
	add r1, r5, r0
	ldrsh r0, [r1, r2]
	sub r0, r0, #1
	strh r0, [r1, r2]
_0222FB22:
	pop {r3, r4, r5, pc}
	thumb_func_end ov45_0222FAF8

thumb_func_start ov45_0222FB24
ov45_0222FB24: ; 0x0222FB24
	push {r4, r5}
	lsl r2, r2, #3
	add r0, r0, r2
	ldr r2, _0222FB58 ; =0x0000011E
	mov r3, #0
	ldrh r4, [r0, r2]
	cmp r4, #0
	ble _0222FB50
	add r2, r2, #2
	ldr r5, [r0, r2]
	ldr r2, _0222FB58 ; =0x0000011E
_0222FB3A:
	ldr r4, [r5]
	cmp r1, r4
	bne _0222FB46
	add r0, r3, #0
	pop {r4, r5}
	bx lr
_0222FB46:
	ldrh r4, [r0, r2]
	add r3, r3, #1
	add r5, r5, #4
	cmp r3, r4
	blt _0222FB3A
_0222FB50:
	mov r0, #0
	mvn r0, r0
	pop {r4, r5}
	bx lr
	.balign 4, 0
_0222FB58: .word 0x0000011E
	thumb_func_end ov45_0222FB24

thumb_func_start ov45_0222FB5C
ov45_0222FB5C: ; 0x0222FB5C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	lsl r6, r2, #3
	add r4, r1, #0
	ldr r0, _0222FB80 ; =0x0000011E
	add r1, r5, r6
	ldrh r0, [r1, r0]
	cmp r4, r0
	blt _0222FB72
	bl GF_AssertFail
_0222FB72:
	mov r0, #0x12
	add r1, r5, r6
	lsl r0, r0, #4
	ldr r1, [r1, r0]
	lsl r0, r4, #2
	ldr r0, [r1, r0]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222FB80: .word 0x0000011E
	thumb_func_end ov45_0222FB5C

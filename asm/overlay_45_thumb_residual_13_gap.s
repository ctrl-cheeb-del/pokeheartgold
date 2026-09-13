#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222A578
	.public ov45_0222A920
	.public ov45_0222AE74
	.public ov45_0222AED8
	.public ov45_0222BE00
	.public ov45_0222BE28
	.public ov45_0222BE48
	.public ov45_0222EC90
	.public ov45_0222EF4C

	thumb_func_start ov45_0222AE74
ov45_0222AE74: ; 0x0222AE74
	push {r3, r4, r5, lr}
	ldr r2, _0222AED4 ; =0x000001CA
	add r5, r0, #0
	ldrb r2, [r5, r2]
	add r4, r1, #0
	cmp r2, #0
	beq _0222AE86
	mov r0, #0
	pop {r3, r4, r5, pc}
_0222AE86:
	bl ov45_0222A578
	bl ov45_0222A920
	cmp r0, #1
	beq _0222AE96
	mov r0, #0
	pop {r3, r4, r5, pc}
_0222AE96:
	mov r0, #0x71
	lsl r0, r0, #2
	strh r4, [r5, r0]
	mov r2, #1
	add r1, r0, #2
	strb r2, [r5, r1]
	add r1, r0, #6
	sub r0, r0, #4
	strb r2, [r5, r1]
	add r0, r5, r0
	mov r1, #0
	bl ov45_0222BE00
	add r0, r4, #0
	bl ov45_0222EC90
	mov r2, #0x1e
	lsl r2, r2, #4
	add r1, r0, #0
	mov r0, #0
	add r2, r5, r2
	mov r3, #4
	bl ov45_0222EF4C
	mov r0, #7
	lsl r0, r0, #6
	add r0, r5, r0
	bl ov45_0222BE48
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222AED4: .word 0x000001CA
	thumb_func_end ov45_0222AE74

	thumb_func_start ov45_0222AED8
ov45_0222AED8: ; 0x0222AED8
	push {r4, lr}
	ldr r3, _0222AF78 ; =0x000001CA
	add r4, r0, #0
	ldrb r2, [r4, r3]
	mov r0, #0
	cmp r2, #1
	bne _0222AEF2
	sub r3, r3, #4
	ldrb r3, [r4, r3]
	cmp r3, #2
	beq _0222AF00
	mov r0, #1
	b _0222AF00
_0222AEF2:
	cmp r2, #2
	bne _0222AF00
	sub r3, r3, #4
	ldrb r3, [r4, r3]
	cmp r3, #3
	beq _0222AF00
	mov r0, #1
_0222AF00:
	cmp r0, #0
	beq _0222AF18
	mov r0, #0x71
	lsl r0, r0, #2
	ldrh r0, [r4, r0]
	bl ov45_0222EC90
	add r1, r0, #0
	add r0, r4, #0
	bl ov45_0222BE28
	pop {r4, pc}
_0222AF18:
	cmp r2, #1
	beq _0222AF22
	cmp r2, #2
	beq _0222AF2A
	b _0222AF32
_0222AF22:
	ldr r0, _0222AF7C ; =0x000001C6
	mov r2, #3
	strb r2, [r4, r0]
	b _0222AF46
_0222AF2A:
	ldr r0, _0222AF7C ; =0x000001C6
	mov r2, #2
	strb r2, [r4, r0]
	b _0222AF46
_0222AF32:
	mov r0, #0x71
	lsl r0, r0, #2
	ldrh r0, [r4, r0]
	bl ov45_0222EC90
	add r1, r0, #0
	add r0, r4, #0
	bl ov45_0222BE28
	pop {r4, pc}
_0222AF46:
	mov r0, #7
	lsl r0, r0, #6
	add r0, r4, r0
	bl ov45_0222BE00
	mov r0, #0x71
	lsl r0, r0, #2
	ldrh r0, [r4, r0]
	bl ov45_0222EC90
	mov r2, #0x1e
	lsl r2, r2, #4
	add r1, r0, #0
	mov r0, #2
	add r2, r4, r2
	mov r3, #4
	bl ov45_0222EF4C
	mov r0, #7
	lsl r0, r0, #6
	add r0, r4, r0
	bl ov45_0222BE48
	pop {r4, pc}
	nop
_0222AF78: .word 0x000001CA
_0222AF7C: .word 0x000001C6
	thumb_func_end ov45_0222AED8

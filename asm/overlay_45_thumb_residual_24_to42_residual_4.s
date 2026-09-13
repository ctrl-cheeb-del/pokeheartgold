#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222C688
	.public ov45_0222C73C
	.public ov45_0222EC68
	.public ov45_0222BADC
	.public ov45_0222A920
	.public ov45_0222AFF8
	.public ov45_0222B048
	.public ov45_0222BE08
	.public ov45_0222BD74
	.public ov45_0222BE48
	.public ov45_0222BD4C
	.public ov45_0222BE54

thumb_func_start ov45_0222C688
ov45_0222C688: ; 0x0222C688
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	str r1, [sp]
	add r5, r3, #0
	bl ov45_0222EC68
	add r6, r0, #0
	mov r0, #0x42
	lsl r0, r0, #2
	ldr r1, [r5]
	add r0, r5, r0
	bl ov45_0222BADC
	cmp r0, #0
	bne _0222C6AC
	ldr r0, _0222C734 ; =0x0000052C
	mov r1, #1
	str r1, [r5, r0]
_0222C6AC:
	mov r0, #0x4a
	lsl r0, r0, #2
	add r0, r5, r0
	bl ov45_0222A920
	add r4, r0, #0
	add r0, r5, #0
	bl ov45_0222AFF8
	cmp r4, #1
	bne _0222C6E2
	mov r1, #0
	mvn r1, r1
	cmp r6, r1
	beq _0222C6E2
	ldr r1, [sp]
	ldrh r1, [r1, #2]
	cmp r1, #1
	bne _0222C6E2
	cmp r0, #1
	beq _0222C6E2
	add r0, r5, #0
	add r1, r6, #0
	bl ov45_0222B048
	cmp r0, #0
	bne _0222C6EE
_0222C6E2:
	add r0, r5, #0
	add r1, r7, #0
	mov r2, #0
	bl ov45_0222BE08
	pop {r3, r4, r5, r6, r7, pc}
_0222C6EE:
	add r0, r5, #0
	add r1, r7, #0
	mov r2, #1
	bl ov45_0222BE08
	mov r0, #7
	lsl r0, r0, #6
	add r0, r5, r0
	add r1, r6, #0
	bl ov45_0222BD74
	cmp r0, #0
	bne _0222C70C
	mov r1, #1
	b _0222C70E
_0222C70C:
	mov r1, #0
_0222C70E:
	ldr r0, _0222C738 ; =0x000001CB
	mov r2, #2
	strb r1, [r5, r0]
	mov r0, #0x71
	lsl r0, r0, #2
	strh r6, [r5, r0]
	add r1, r0, #2
	strb r2, [r5, r1]
	add r1, r0, #6
	strb r2, [r5, r1]
	add r1, r0, #3
	sub r0, r0, #4
	mov r2, #0
	add r0, r5, r0
	strb r2, [r5, r1]
	bl ov45_0222BE48
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222C734: .word 0x0000052C
_0222C738: .word 0x000001CB
	thumb_func_end ov45_0222C688

thumb_func_start ov45_0222C73C
ov45_0222C73C: ; 0x0222C73C
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r4, r3, #0
	bl ov45_0222EC68
	ldr r2, _0222C790 ; =0x000001CA
	add r1, r0, #0
	ldrb r0, [r4, r2]
	cmp r0, #0
	beq _0222C78E
	sub r0, r2, #6
	ldrh r0, [r4, r0]
	cmp r0, r1
	bne _0222C78E
	ldrh r0, [r5]
	cmp r0, #1
	bne _0222C77C
	sub r2, #0xa
	add r0, r4, r2
	bl ov45_0222BD74
	cmp r0, #0
	bne _0222C76E
	mov r1, #1
	b _0222C770
_0222C76E:
	mov r1, #0
_0222C770:
	ldr r0, _0222C794 ; =0x000001CB
	strb r1, [r4, r0]
	ldr r0, _0222C798 ; =0x000001C6
	mov r1, #2
	strb r1, [r4, r0]
	b _0222C784
_0222C77C:
	sub r2, #0xa
	add r0, r4, r2
	bl ov45_0222BD4C
_0222C784:
	mov r0, #7
	lsl r0, r0, #6
	add r0, r4, r0
	bl ov45_0222BE54
_0222C78E:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222C790: .word 0x000001CA
_0222C794: .word 0x000001CB
_0222C798: .word 0x000001C6
	thumb_func_end ov45_0222C73C

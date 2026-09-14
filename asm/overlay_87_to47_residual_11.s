	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E7A44
	.extern ov87_021E829C
	.public ov87_021E74F4

	.text

thumb_func_start ov87_021E74F4
ov87_021E74F4: ; 0x021E74F4
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	mov r0, #0xee
	lsl r0, r0, #2
	ldrh r0, [r7, r0]
	mov r6, #0
	cmp r0, #0
	ble _021E7544
	ldr r2, _021E7548 ; =ov87_021E829C
	lsl r0, r1, #2
	add r5, r2, r0
	ldrb r0, [r5, #2]
	add r4, r7, #0
	str r0, [sp]
_021E7510:
	ldr r0, _021E754C ; =0x000003BA
	ldrh r1, [r4, r0]
	add r0, r0, #2
	ldrh r2, [r4, r0]
	ldr r0, [sp]
	cmp r0, r1
	bgt _021E7536
	ldrb r0, [r5, #3]
	cmp r1, r0
	bgt _021E7536
	ldrb r0, [r5]
	cmp r0, r2
	bgt _021E7536
	ldrb r0, [r5, #1]
	cmp r2, r0
	bgt _021E7536
	add r0, r7, #0
	bl ov87_021E7A44
_021E7536:
	mov r0, #0xee
	lsl r0, r0, #2
	ldrh r0, [r7, r0]
	add r6, r6, #1
	add r4, #8
	cmp r6, r0
	blt _021E7510
_021E7544:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7548: .word ov87_021E829C
_021E754C: .word 0x000003BA
	thumb_func_end ov87_021E74F4

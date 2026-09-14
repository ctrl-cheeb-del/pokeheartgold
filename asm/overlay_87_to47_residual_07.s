	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E7FD4
	.extern ov87_021E803C
	.extern ov87_021E8084
	.public ov87_021E70D0

	.text

thumb_func_start ov87_021E70D0
ov87_021E70D0: ; 0x021E70D0
	push {r3, r4, r5, r6, r7, lr}
	mov r7, #0x35
	add r5, r0, #0
	mov r4, #0
	lsl r7, r7, #4
_021E70DA:
	ldr r1, _021E712C ; =0x000003A2
	add r2, r5, r4
	ldrb r1, [r2, r1]
	lsl r0, r4, #2
	add r6, r5, r0
	add r2, r5, r1
	mov r1, #0x36
	mov r0, #0x35
	lsl r1, r1, #4
	lsl r0, r0, #4
	ldrb r1, [r2, r1]
	ldr r0, [r6, r0]
	bl ov87_021E803C
	ldr r0, [r6, r7]
	mov r1, #1
	bl ov87_021E7FD4
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _021E70DA
	mov r0, #0xd7
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl ov87_021E7FD4
	mov r0, #0xd7
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl ov87_021E8084
	ldr r0, _021E7130 ; =0x00000561
	bl PlaySE
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E712C: .word 0x000003A2
_021E7130: .word 0x00000561
	thumb_func_end ov87_021E70D0

	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.public ov87_021E7294

	.text

thumb_func_start ov87_021E7294
ov87_021E7294: ; 0x021E7294
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl LCRandom
	mov r7, #0
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r4, r7, #0
_021E72B0:
	bl LCRandom
	mov r1, #9
	bl _s32_div_f
	mov r0, #0x36
	add r2, r5, r1
	lsl r0, r0, #4
	ldrb r1, [r2, r0]
	cmp r1, #0xb0
	bne _021E72E4
	mov r7, #0
	strb r6, [r2, r0]
	cmp r4, #2
	beq _021E72D6
	cmp r4, #4
	beq _021E72D6
	cmp r4, #6
	bne _021E731C
_021E72D6:
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #4
	bne _021E731C
	mov r6, #0
	b _021E731C
_021E72E4:
	add r7, r7, #1
	cmp r7, #0x1e
	blt _021E72B0
	mov r7, #0
	add r3, r7, #0
_021E72EE:
	add r2, r5, r3
	ldrb r1, [r2, r0]
	cmp r1, #0xb0
	bne _021E7316
	mov r0, #0x36
	lsl r0, r0, #4
	strb r6, [r2, r0]
	cmp r4, #2
	beq _021E7308
	cmp r4, #4
	beq _021E7308
	cmp r4, #6
	bne _021E731C
_021E7308:
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #4
	bne _021E731C
	mov r6, #0
	b _021E731C
_021E7316:
	add r3, r3, #1
	cmp r3, #9
	blt _021E72EE
_021E731C:
	add r4, r4, #1
	cmp r4, #9
	blt _021E72B0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov87_021E7294

	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E7FEC
	.extern ov87_021E8014
	.extern ov87_021E827C
	.extern ov87_021E8358
	.extern ov87_021E838C
	.public ov87_021E734C
	.public ov87_021E73E0

	.text

thumb_func_start ov87_021E734C
ov87_021E734C: ; 0x021E734C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	mov r1, #0
	add r2, sp, #8
	mov r0, #0xff
_021E7358:
	add r1, r1, #1
	strh r0, [r2]
	add r2, r2, #2
	cmp r1, #4
	blt _021E7358
	bl LCRandom
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	add r4, sp, #8
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	mov r5, #0
	add r6, r4, #0
	mov r7, #0x17
_021E7380:
	ldr r0, [sp, #4]
	cmp r5, r0
	bne _021E7390
	ldr r1, [sp]
	ldr r0, _021E73D8 ; =0x0000036A
	mov r2, #0x5c
	strh r2, [r1, r0]
	b _021E73C6
_021E7390:
	bl LCRandom
	add r1, r7, #0
	bl _u32_div_f
	strh r1, [r4]
	mov r1, #0
	cmp r5, #0
	ble _021E73B4
	ldrh r3, [r4]
	add r2, r6, #0
_021E73A6:
	ldrh r0, [r2]
	cmp r0, r3
	beq _021E73B4
	add r1, r1, #1
	add r2, r2, #2
	cmp r1, r5
	blt _021E73A6
_021E73B4:
	cmp r1, r5
	bne _021E7390
	ldrh r0, [r4]
	lsl r1, r0, #1
	ldr r0, _021E73DC ; =ov87_021E8358
	ldrh r2, [r0, r1]
	ldr r1, [sp]
	ldr r0, _021E73D8 ; =0x0000036A
	strh r2, [r1, r0]
_021E73C6:
	ldr r0, [sp]
	add r5, r5, #1
	add r0, r0, #2
	add r4, r4, #2
	str r0, [sp]
	cmp r5, #4
	blt _021E7380
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E73D8: .word 0x0000036A
_021E73DC: .word ov87_021E8358
	thumb_func_end ov87_021E734C

	thumb_func_start ov87_021E73E0
ov87_021E73E0: ; 0x021E73E0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0x3a
	lsl r0, r0, #4
	add r4, r1, #0
	ldrb r1, [r5, r0]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x19
	cmp r1, #8
	blo _021E73FC
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E73FC:
	sub r0, #0x74
	add r0, r5, r0
	str r0, [sp]
	ldr r1, [sp]
	lsl r0, r4, #2
	str r0, [sp, #4]
	ldr r0, [r1, r0]
	add r1, sp, #0xc
	add r2, sp, #8
	bl ov87_021E8014
	mov r0, #0x3a
	lsl r0, r0, #4
	ldrb r0, [r5, r0]
	lsl r2, r4, #3
	ldr r4, _021E7458 ; =ov87_021E838C
	lsl r1, r0, #0x18
	lsr r6, r1, #0x19
	ldrsb r7, [r4, r6]
	mov r4, #0xfe
	bic r0, r4
	add r4, r6, #1
	lsl r4, r4, #0x18
	lsr r4, r4, #0x18
	ldr r1, _021E745C ; =ov87_021E827C
	lsl r4, r4, #0x19
	add r1, r1, r2
	lsr r4, r4, #0x18
	ldr r2, [sp, #8]
	orr r4, r0
	mov r0, #0x3a
	ldr r3, [sp, #0xc]
	lsl r0, r0, #4
	strb r4, [r5, r0]
	ldrsb r1, [r6, r1]
	ldr r4, [sp]
	ldr r0, [sp, #4]
	add r1, r3, r1
	ldr r0, [r4, r0]
	add r2, r2, r7
	bl ov87_021E7FEC
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E7458: .word ov87_021E838C
_021E745C: .word ov87_021E827C
	thumb_func_end ov87_021E73E0

	.include "asm/macros.inc"
	.include "overlay_49.inc"
	.include "global.inc"

	.text
	.public ov49_022589D8
	.public ov49_022593C0
	.public ov42_022280B8
	.public ov45_0223070C
	.public ov49_02258EEC
	.public ov49_02269678

	thumb_func_start ov49_022591D8
ov49_022591D8: ; 0x022591D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	mov r0, #0
	ldr r4, _02259278 ; =ov49_02269678
	str r0, [sp, #8]
_022591E4:
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp]
	ldrb r1, [r4]
	add r2, sp, #0xc
	ldr r0, [r5, #0x14]
	add r2, #2
	add r3, sp, #0xc
	bl ov49_022589D8
	cmp r0, #1
	bne _02259266
	add r7, sp, #0xc
_022591FE:
	add r0, r5, #0
	bl ov49_022593C0
	add r6, r0, #0
	ldrh r0, [r7, #2]
	add r1, sp, #0x10
	lsl r0, r0, #4
	strh r0, [r7, #4]
	ldrh r0, [r7]
	lsl r0, r0, #4
	strh r0, [r7, #6]
	ldrb r0, [r4, #4]
	strh r0, [r7, #8]
	mov r0, #0
	strh r0, [r7, #0xa]
	ldrb r0, [r4, #1]
	strh r0, [r7, #0xc]
	ldrh r0, [r4, #2]
	strh r0, [r7, #0xe]
	ldr r0, [r5]
	bl ov42_022280B8
	add r1, r0, #0
	str r1, [r6]
	ldr r0, [r5, #4]
	bl ov45_0223070C
	str r0, [r6, #4]
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #0
	bl ov49_02258EEC
	ldrb r0, [r4]
	cmp r0, #0x61
	bne _02259248
	str r6, [r5, #0x24]
_02259248:
	ldr r0, [sp, #4]
	add r2, sp, #0xc
	add r0, r0, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	str r0, [sp]
	ldrb r1, [r4]
	ldr r0, [r5, #0x14]
	add r2, #2
	add r3, sp, #0xc
	bl ov49_022589D8
	cmp r0, #1
	beq _022591FE
_02259266:
	ldr r0, [sp, #8]
	add r4, #8
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #4
	blo _022591E4
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_02259278: .word ov49_02269678
	thumb_func_end ov49_022591D8

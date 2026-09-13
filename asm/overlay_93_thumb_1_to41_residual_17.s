	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225E584
	.public ov93_0225E61C
	.extern ov93_0225E3B8
	.extern ov93_0225E548

	thumb_func_start ov93_0225E584
ov93_0225E584: ; 0x0225E584
	push {r4, lr}
	add r4, r1, #0
	ldr r1, [r4, #0xc]
	cmp r1, #5
	bhi _0225E616
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0225E59A: ; jump table
	.short _0225E5A6 - _0225E59A - 2 ; case 0
	.short _0225E5B6 - _0225E59A - 2 ; case 1
	.short _0225E5CE - _0225E59A - 2 ; case 2
	.short _0225E5DC - _0225E59A - 2 ; case 3
	.short _0225E5F4 - _0225E59A - 2 ; case 4
	.short _0225E602 - _0225E59A - 2 ; case 5
_0225E5A6:
	ldrb r2, [r4, #0x18]
	mov r1, #1
	bl ov93_0226297C
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	b _0225E616
_0225E5B6:
	ldrb r1, [r4, #0x18]
	bl ov93_0225E548
	cmp r0, #1
	bne _0225E616
	ldrb r0, [r4, #0x18]
	add r0, r0, #1
	strb r0, [r4, #0x18]
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	b _0225E616
_0225E5CE:
	ldrb r1, [r4, #0x18]
	bl ov93_022629B8
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	b _0225E616
_0225E5DC:
	ldrb r1, [r4, #0x18]
	bl ov93_0225E548
	cmp r0, #1
	bne _0225E616
	ldrb r0, [r4, #0x18]
	add r0, r0, #1
	strb r0, [r4, #0x18]
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	b _0225E616
_0225E5F4:
	ldrb r1, [r4, #0x18]
	bl ov93_022628F4
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	b _0225E616
_0225E602:
	ldrb r1, [r4, #0x18]
	bl ov93_0225E548
	cmp r0, #1
	bne _0225E616
	ldrb r0, [r4, #0x18]
	add r0, r0, #1
	strb r0, [r4, #0x18]
	mov r0, #1
	pop {r4, pc}
_0225E616:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov93_0225E584


	thumb_func_start ov93_0225E61C
ov93_0225E61C: ; 0x0225E61C
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldr r1, _0225E6E8 ; =0x00002FB4
	ldr r0, _0225E6EC ; =0x00000516
	ldr r2, [r5, r1]
	cmp r2, r0
	bls _0225E64C
	add r0, r1, #0
	add r0, #0x20
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _0225E64C
	add r0, r1, #0
	sub r0, #0xd8
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _0225E64C
	sub r1, #0xc4
	ldr r0, [r5, r1]
	cmp r0, #0
	bne _0225E64C
	mov r0, #1
	pop {r3, r4, r5, pc}
_0225E64C:
	ldr r0, [r4, #0xc]
	cmp r0, #3
	bhi _0225E6E4
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225E65E: ; jump table
	.short _0225E666 - _0225E65E - 2 ; case 0
	.short _0225E684 - _0225E65E - 2 ; case 1
	.short _0225E69E - _0225E65E - 2 ; case 2
	.short _0225E6CE - _0225E65E - 2 ; case 3
_0225E666:
	ldr r0, _0225E6F0 ; =0x00002FC8
	ldr r0, [r5, r0]
	bl ov93_0225FDF4
	ldr r1, _0225E6F0 ; =0x00002FC8
	add r2, r0, #0
	ldrb r3, [r4, #0x18]
	ldr r1, [r5, r1]
	add r0, r5, #0
	bl ov93_02262884
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	b _0225E6E4
_0225E684:
	ldrb r1, [r4, #0x18]
	add r0, r5, #0
	bl ov93_0225E548
	cmp r0, #1
	bne _0225E6E4
	ldrb r0, [r4, #0x18]
	add r0, r0, #1
	strb r0, [r4, #0x18]
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	b _0225E6E4
_0225E69E:
	ldr r0, _0225E6F4 ; =0x00001434
	ldr r1, [r5, r0]
	cmp r1, #0
	beq _0225E6E4
	sub r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, r1
	blt _0225E6E4
	ldr r0, _0225E6F0 ; =0x00002FC8
	ldr r1, [r5, r0]
	add r1, r1, #1
	str r1, [r5, r0]
	add r0, r5, #0
	bl ov93_0225E3B8
	add r1, r0, #0
	ldrb r2, [r4, #0x18]
	add r0, r5, #0
	bl ov93_02262830
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	b _0225E6E4
_0225E6CE:
	ldrb r1, [r4, #0x18]
	add r0, r5, #0
	bl ov93_0225E548
	cmp r0, #1
	bne _0225E6E4
	ldrb r0, [r4, #0x18]
	add r0, r0, #1
	strb r0, [r4, #0x18]
	mov r0, #0
	str r0, [r4, #0xc]
_0225E6E4:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0225E6E8: .word 0x00002FB4
_0225E6EC: .word 0x00000516
_0225E6F0: .word 0x00002FC8
_0225E6F4: .word 0x00001434
	thumb_func_end ov93_0225E61C

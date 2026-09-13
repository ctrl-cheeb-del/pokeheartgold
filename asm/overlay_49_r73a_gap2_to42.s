	.include "asm/macros.inc"
	.include "overlay_49.inc"
	.include "global.inc"

	.text
	.public ov49_022670D4
	.extern ov49_02258DAC
	.extern ov49_02258E60
	.extern ov49_02259130
	.extern ov49_02259148
	.extern ov49_02259154
	.extern ov49_02259160
	.extern ov49_0225919C
	.extern ov49_0225CC40
	.extern ov49_02265434
	.extern ov49_022655E0
	.extern ov49_02265628
	.extern ov49_02265660
	.extern ov49_02265668
	.extern ov49_0226786C
	.extern ov49_0226789C
	.extern ov49_02258DAC
	.extern ov49_02259130
	.extern ov49_02259148
	.extern ov49_02259154
	.extern ov49_02259160
	.extern ov49_0225919C
	.extern ov49_0225CC40
	.extern ov49_022655E0
	.extern ov49_02265660

	thumb_func_start ov49_022670D4
ov49_022670D4: ; 0x022670D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	add r4, r1, #0
	ldr r1, _02267300 ; =0x00000954
	add r6, r0, #0
	ldrsb r0, [r4, r1]
	cmp r0, #4
	bhi _0226710A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022670F0: ; jump table
	.short _022670FA - _022670F0 - 2 ; case 0
	.short _02267112 - _022670F0 - 2 ; case 1
	.short _02267128 - _022670F0 - 2 ; case 2
	.short _0226715E - _022670F0 - 2 ; case 3
	.short _022671B6 - _022670F0 - 2 ; case 4
_022670FA:
	add r0, r1, #2
	ldrsh r0, [r4, r0]
	add r2, r0, #1
	add r0, r1, #2
	strh r2, [r4, r0]
	ldrsh r0, [r4, r0]
	cmp r0, #8
	bge _0226710C
_0226710A:
	b _02267230
_0226710C:
	mov r0, #1
	strb r0, [r4, r1]
	b _02267230
_02267112:
	ldr r0, [r4, #8]
	mov r1, #1
	bl ov49_0225919C
	ldr r0, _02267304 ; =0x00000956
	mov r1, #0x10
	strh r1, [r4, r0]
	mov r1, #2
	sub r0, r0, #2
	strb r1, [r4, r0]
	b _02267230
_02267128:
	add r0, r1, #2
	ldrsh r0, [r4, r0]
	sub r2, r0, #1
	add r0, r1, #2
	strh r2, [r4, r0]
	ldrsh r0, [r4, r0]
	cmp r0, #0
	bgt _02267230
	ldr r0, [r4, #8]
	mov r1, #0
	bl ov49_0225919C
	ldr r0, _02267300 ; =0x00000954
	mov r1, #3
	strb r1, [r4, r0]
	mov r1, #0
	add r0, r0, #2
	strh r1, [r4, r0]
	ldr r0, [r4, #8]
	mov r1, #6
	bl ov49_02258E60
	add r1, r0, #0
	ldr r0, [r4, #8]
	bl ov49_02259160
	b _02267230
_0226715E:
	add r0, r1, #0
	add r1, r1, #2
	add r0, #0xb0
	ldrsh r1, [r4, r1]
	add r0, r4, r0
	bl ov49_02265434
	add r5, r0, #0
	ldr r0, _02267304 ; =0x00000956
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	ldr r0, [r4, #8]
	add r1, sp, #0x30
	bl ov49_02259154
	ldr r0, _02267308 ; =0x00000A04
	add r1, sp, #0x30
	add r0, r4, r0
	add r2, sp, #0x34
	add r3, sp, #0x38
	bl ov49_022655E0
	ldr r0, [r4, #8]
	add r1, sp, #0x30
	bl ov49_02259148
	cmp r5, #1
	bne _02267230
	ldr r0, _02267300 ; =0x00000954
	mov r1, #4
	strb r1, [r4, r0]
	add r1, r0, #2
	mov r2, #0
	strh r2, [r4, r1]
	ldr r1, [sp, #0x34]
	add r0, r0, #4
	str r1, [r4, r0]
	ldr r2, _0226730C ; =0x000005C2
	add r0, r6, #0
	add r1, r4, #0
	bl ov49_02265668
	b _02267230
_022671B6:
	add r0, r1, #2
	ldrsh r1, [r4, r0]
	ldr r0, _02267310 ; =0x00007FFF
	mul r0, r1
	mov r1, #0xa
	bl _s32_div_f
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	asr r0, r0, #4
	lsl r1, r0, #2
	ldr r0, _02267314 ; =FX_SinCosTable_
	ldrsh r2, [r0, r1]
	asr r0, r2, #0x1f
	lsr r1, r2, #0x11
	lsl r0, r0, #0xf
	orr r0, r1
	mov r1, #2
	lsl r3, r2, #0xf
	mov r2, #0
	lsl r1, r1, #0xa
	add r1, r3, r1
	adc r0, r2
	lsr r5, r1, #0xc
	lsl r0, r0, #0x14
	orr r5, r0
	ldr r0, [r4, #8]
	add r1, sp, #0x24
	bl ov49_02259154
	ldr r0, _02267318 ; =0x00000958
	add r1, sp, #0x24
	ldr r0, [r4, r0]
	add r0, r0, r5
	str r0, [sp, #0x28]
	ldr r0, [r4, #8]
	bl ov49_02259148
	ldr r0, _02267304 ; =0x00000956
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	cmp r1, #0xa
	ble _0226722E
	ldr r0, [r4, #8]
	mov r1, #1
	bl ov49_02259130
	ldr r0, [r6, #4]
	ldr r4, [r4, #8]
	bl ov49_02258DAC
	cmp r4, r0
	bne _02267228
	ldr r0, [r6, #8]
	add r1, r4, #0
	bl ov49_0225CC40
_02267228:
	add sp, #0x3c
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0226722E:
	strh r1, [r4, r0]
_02267230:
	ldr r1, _0226731C ; =0x00000964
	mov r5, #0
	ldrb r0, [r4, r1]
	add r0, r0, #1
	strb r0, [r4, r1]
	add r0, r1, #0
	sub r0, #0xf
	ldrsb r0, [r4, r0]
	cmp r0, #0
	ble _022672F8
	add r0, r1, #0
	add r0, #0x28
	add r7, r4, r0
	add r0, r1, #4
	add r0, r4, r0
	str r0, [sp, #0x10]
	add r0, r4, #0
	str r0, [sp, #0xc]
	add r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	str r7, [sp, #8]
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	str r0, [sp]
_02267262:
	ldr r1, _0226731C ; =0x00000964
	add r0, r7, #0
	ldrb r1, [r4, r1]
	bl ov49_02265434
	cmp r0, #0
	bne _022672AA
	ldr r0, [sp, #0x10]
	bl ov49_02265628
	ldr r0, [sp, #0xc]
	add r1, sp, #0x18
	add r2, sp, #0x1c
	add r3, sp, #0x20
	bl sub_020182B0
	ldr r0, [sp, #8]
	add r1, sp, #0x18
	add r2, sp, #0x1c
	add r3, sp, #0x20
	bl ov49_022655E0
	ldr r0, [sp, #4]
	add r1, sp, #0x14
	bl ov49_02265660
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x14]
	ldr r2, [sp, #0x1c]
	add r1, r1, r0
	ldr r0, [sp]
	ldr r3, [sp, #0x20]
	str r1, [sp, #0x18]
	bl sub_020182A8
	b _022672C4
_022672AA:
	add r0, r6, #0
	add r1, r4, #0
	add r2, r5, #0
	mov r3, #4
	bl ov49_0226786C
	cmp r0, #1
	bne _022672C4
	ldr r2, _02267320 ; =0x000005A8
	add r0, r6, #0
	add r1, r4, #0
	bl ov49_02265668
_022672C4:
	add r0, r6, #0
	add r1, r4, #0
	add r2, r5, #0
	bl ov49_0226789C
	ldr r0, [sp, #0x10]
	add r5, r5, #1
	add r0, #0xc
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r7, #0x28
	add r0, #0x78
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r0, #0x28
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r0, #0xc
	str r0, [sp, #4]
	ldr r0, [sp]
	add r0, #0x78
	str r0, [sp]
	ldr r0, _02267324 ; =0x00000955
	ldrsb r0, [r4, r0]
	cmp r5, r0
	blt _02267262
_022672F8:
	mov r0, #0
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	nop
_02267300: .word 0x00000954
_02267304: .word 0x00000956
_02267308: .word 0x00000A04
_0226730C: .word 0x000005C2
_02267310: .word 0x00007FFF
_02267314: .word FX_SinCosTable_
_02267318: .word 0x00000958
_0226731C: .word 0x00000964
_02267320: .word 0x000005A8
_02267324: .word 0x00000955
	thumb_func_end ov49_022670D4

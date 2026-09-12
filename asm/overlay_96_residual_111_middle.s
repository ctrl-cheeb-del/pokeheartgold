	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text
	.public ov96_02215478
	.public ov96_022155A0

	thumb_func_start ov96_02215478
ov96_02215478: ; 0x02215478
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r0, [sp]
	str r2, [sp, #8]
	mov r0, #0
	add r7, sp, #0x10
	str r0, [sp, #0xc]
	strb r0, [r7]
	ldr r0, [sp, #0xc]
	str r1, [sp, #4]
	strb r0, [r7, #1]
	ldr r0, [sp, #0xc]
	strb r0, [r7, #2]
	ldr r0, [sp, #0xc]
	strb r0, [r7, #3]
_02215496:
	ldr r1, [sp, #0xc]
	mov r0, #0x24
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #4]
	mov r4, #0
	add r6, r0, r2
_022154A4:
	lsl r0, r4, #3
	add r0, r6, r0
	ldr r3, [r0, #4]
	mov r0, #0x80
	ldr r2, [r3, #0x30]
	ldr r3, [r3, #0x34]
	asr r5, r2, #0xb
	lsr r5, r5, #0x14
	add r5, r2, r5
	asr r2, r5, #0xc
	asr r5, r3, #0xb
	lsr r5, r5, #0x14
	add r5, r3, r5
	mov r1, #0x60
	asr r3, r5, #0xc
	bl ov96_02215614
	cmp r0, #4
	beq _022154D0
	ldrb r1, [r7, r0]
	add r1, r1, #1
	strb r1, [r7, r0]
_022154D0:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #3
	blo _022154A4
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	cmp r0, #4
	blo _02215496
	mov r4, #0
	mov r1, #1
	add r0, sp, #0x10
_022154EE:
	add r2, r0, r1
	sub r2, r2, #1
	ldrb r3, [r2]
	ldrb r2, [r0, r1]
	cmp r3, r2
	bls _02215502
	ldr r2, [sp, #8]
	cmp r1, r2
	beq _02215502
	add r4, r1, #0
_02215502:
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, #4
	blo _022154EE
	bl LCRandom
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1a
	sub r1, r1, r2
	mov r0, #0x1a
	ror r1, r0
	add r5, r2, r1
	bl LCRandom
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1b
	sub r1, r1, r2
	mov r0, #0x1b
	ror r1, r0
	add r0, r2, r1
	cmp r4, #3
	bhi _02215594
	add r1, r4, r4
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0221553C: ; jump table
	.short _02215544 - _0221553C - 2 ; case 0
	.short _0221555A - _0221553C - 2 ; case 1
	.short _0221556E - _0221553C - 2 ; case 2
	.short _02215582 - _0221553C - 2 ; case 3
_02215544:
	mov r1, #0x80
	sub r1, r1, r5
	lsl r2, r1, #0xc
	ldr r1, [sp]
	str r2, [r1, #0x24]
	mov r1, #0x60
	sub r0, r1, r0
	lsl r1, r0, #0xc
	ldr r0, [sp]
	str r1, [r0, #0x28]
	b _02215598
_0221555A:
	add r5, #0x80
	ldr r1, [sp]
	lsl r2, r5, #0xc
	str r2, [r1, #0x24]
	mov r1, #0x60
	sub r0, r1, r0
	lsl r1, r0, #0xc
	ldr r0, [sp]
	str r1, [r0, #0x28]
	b _02215598
_0221556E:
	mov r1, #0x80
	sub r1, r1, r5
	lsl r2, r1, #0xc
	ldr r1, [sp]
	add r0, #0x60
	str r2, [r1, #0x24]
	lsl r1, r0, #0xc
	ldr r0, [sp]
	str r1, [r0, #0x28]
	b _02215598
_02215582:
	add r5, #0x80
	ldr r1, [sp]
	lsl r2, r5, #0xc
	add r0, #0x60
	str r2, [r1, #0x24]
	lsl r1, r0, #0xc
	ldr r0, [sp]
	str r1, [r0, #0x28]
	b _02215598
_02215594:
	bl GF_AssertFail
_02215598:
	mov r0, #0xa
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_02215478


	thumb_func_start ov96_022155A0
ov96_022155A0: ; 0x022155A0
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r2, #0
	add r2, r1, #0
	add r2, #0x9d
	ldrb r3, [r2]
	add r2, r1, #0
	add r2, #0x99
	ldrb r2, [r2]
	add r2, r3, r2
	lsl r2, r2, #0x18
	lsr r3, r2, #0x18
	add r2, r1, #0
	add r2, #0x9c
	ldrb r2, [r2]
	cmp r2, #0
	beq _022155CC
	cmp r2, #1
	beq _022155E0
	cmp r2, #2
	beq _022155F4
	b _0221560C
_022155CC:
	add r1, #0x90
	ldr r1, [r1]
	str r1, [sp]
	add r1, r3, #0
	ldr r3, [r4, #4]
	bl ov96_02214EB4
	add sp, #8
	str r0, [r4]
	pop {r3, r4, r5, pc}
_022155E0:
	add r1, #0x90
	ldr r1, [r1]
	str r1, [sp]
	add r1, r3, #0
	ldr r3, [r4, #4]
	bl ov96_02214C3C
	add sp, #8
	str r0, [r4]
	pop {r3, r4, r5, pc}
_022155F4:
	add r5, r1, #0
	add r5, #0x90
	ldr r5, [r5]
	str r5, [sp]
	str r1, [sp, #4]
	add r1, r3, #0
	ldr r3, [r4, #4]
	bl ov96_02215184
	add sp, #8
	str r0, [r4]
	pop {r3, r4, r5, pc}
_0221560C:
	bl GF_AssertFail
	add sp, #8
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_022155A0

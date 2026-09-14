	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.public Heap_Alloc
	.public MI_CpuFill8
	.public PokeathlonCourse_GetParticipantCount
	.public ov96_022108BC
	.text

	thumb_func_start ov96_022107F0
ov96_022107F0: ; 0x022107F0
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	str r0, [sp]
	bl PokeathlonCourse_GetParticipantCount
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #0xc0
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0xc0
	add r7, r0, #0
	bl MI_CpuFill8
	str r4, [r7]
	ldr r0, [sp]
	mov r4, #0
	str r0, [r7, #4]
	mov r0, #4
	sub r1, r0, r5
	add r0, r7, #0
	add r0, #0xbc
	strb r1, [r0]
	add r0, r7, #0
	add r0, #0xbc
	ldrb r0, [r0]
	cmp r0, #0
	ble _0221084A
	add r6, r7, #0
	add r6, #8
_0221082E:
	lsl r1, r5, #0x18
	ldr r2, [sp]
	add r0, r6, #0
	lsr r1, r1, #0x18
	bl ov96_022108BC
	add r0, r7, #0
	add r0, #0xbc
	ldrb r0, [r0]
	add r4, r4, #1
	add r5, r5, #1
	add r6, #0x3c
	cmp r4, r0
	blt _0221082E
_0221084A:
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_022107F0

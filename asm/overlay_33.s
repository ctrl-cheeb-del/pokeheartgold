	.include "asm/macros.inc"
	.include "overlay_33.inc"
	.include "global.inc"

	.text
	.public ov33_0225D520
	.public ov33_0225D5A8
	.public ov33_0225D5CC
	.public ov33_0225D5D0
	.public ov33_0225D6F8
	.public ov33_0225D720
	.public ov33_0225D7B8
	.public ov33_0225D7D4
	.public ov33_0225D820
	.public ov33_0225D84C
	.public ov33_0225D9D4
	.public ov33_0225DA24
	.public ov33_0225DA2C
	.public ov33_0225DA34
	.public ov33_0225DA40
	.public ov33_0225DA68
	.public ov33_0225DA84
	.public ov33_0225DAA0
	.public ov33_0225DA50
	.public ov33_0225D8D4

	thumb_func_start ov33_0225D520
ov33_0225D520: ; 0x0225D520
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	str r1, [sp]
	mov r0, #3
	str r2, [sp, #4]
	mov r1, #8
	lsl r2, r0, #0xf
	add r5, r3, #0
	bl Heap_Create
	ldr r0, _0225D598 ; =0x04001050
	mov r1, #0
	strh r1, [r0]
	mov r1, #7
	ldr r0, _0225D59C ; =ov33_0225D5D0
	lsl r1, r1, #6
	mov r2, #0xa
	mov r3, #8
	bl CreateSysTaskAndEnvironment
	add r7, r0, #0
	bl SysTask_GetData
	add r4, r0, #0
	ldr r0, [sp]
	str r6, [r4]
	str r0, [r4, #4]
	ldr r0, [sp, #4]
	str r0, [r4, #8]
	str r5, [r4, #0xc]
	str r7, [r4, #0x14]
	str r5, [r4, #0x10]
	ldrb r1, [r5, #4]
	ldr r0, _0225D5A0 ; =0x000001BA
	strh r1, [r4, r0]
	ldr r1, _0225D5A4 ; =0x0000FFFF
	ldr r0, [r4, #0x10]
	strh r1, [r0, #6]
	ldr r0, [r4, #0x10]
	mov r1, #0
	strb r1, [r0, #5]
	bl ov33_0225D6F8
	add r0, r6, #0
	bl ov33_0225D720
	add r0, r4, #0
	bl ov33_0225D7D4
	add r0, r4, #0
	bl ov33_0225D84C
	add r0, r4, #0
	bl ov33_0225D8D4
	add r0, r7, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225D598: .word 0x04001050
_0225D59C: .word ov33_0225D5D0
_0225D5A0: .word 0x000001BA
_0225D5A4: .word 0x0000FFFF
	thumb_func_end ov33_0225D520

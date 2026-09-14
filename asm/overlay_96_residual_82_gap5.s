	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	thumb_func_start ov96_02201EF0
ov96_02201EF0: ; 0x02201EF0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x5c
	add r6, r0, #0
	mov r0, #0
	add r4, r1, #0
	str r2, [sp, #4]
	str r0, [sp, #0x10]
	add r5, r6, #0
	add r7, r0, #0
_02201F02:
	add r0, r4, #0
	bl ov96_021EB5E8
	add r1, r0, #0
	ldr r0, _02202148 ; =0x000005D4
	ldr r3, [r6, #0x44]
	ldr r0, [r6, r0]
	mov r2, #3
	bl ov96_021EA374
	mov r1, #1
	str r0, [r5, #0x50]
	bl Sprite_SetDrawFlag
	mov r0, #6
	lsl r1, r7, #0xc
	lsl r0, r0, #0xe
	add r0, r1, r0
	str r0, [sp, #0x50]
	mov r0, #2
	lsl r0, r0, #0xe
	str r0, [sp, #0x54]
	mov r0, #0
	str r0, [sp, #0x58]
	ldr r0, [r5, #0x50]
	add r1, sp, #0x50
	bl Sprite_SetMatrix
	ldr r0, [r5, #0x50]
	mov r1, #2
	bl Sprite_SetDrawPriority
	ldr r0, [sp, #0x10]
	add r5, r5, #4
	add r0, r0, #1
	add r7, #0x10
	str r0, [sp, #0x10]
	cmp r0, #2
	blt _02201F02
	add r0, r6, #0
	mov r1, #0x3c
	bl ov96_022038A0
	mov r7, #0
	add r5, r6, #0
_02201F5C:
	add r0, r5, #0
	add r0, #0xf9
	strb r7, [r0]
	mov r0, #3
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	add r1, r5, #0
	add r1, #0xb8
	str r0, [r1]
	mov r0, #4
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	add r1, r5, #0
	add r1, #0xbc
	str r0, [r1]
	mov r0, #6
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	add r1, r5, #0
	add r1, #0xc0
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xbc
	ldr r0, [r0]
	mov r1, #1
	bl ov96_021EB564
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	mov r1, #0x14
	bl ov96_021EB630
	add r0, r5, #0
	add r0, #0xbc
	mov r1, #0xfa
	ldr r0, [r0]
	lsl r1, r1, #2
	bl ov96_021EB630
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #5
	bl ov96_021EB630
	add r7, r7, #1
	add r5, #0x48
	cmp r7, #0xc
	blt _02201F5C
	mov r7, #0
	add r5, r6, #0
_02201FE2:
	mov r0, #9
	mov r1, #3
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0x6a
	bl ov96_021EB3E4
	ldr r1, _0220214C ; =0x00000418
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #2
	bl ov96_021EB564
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #0x44]
	str r0, [sp, #0x48]
	mov r0, #0
	str r0, [sp, #0x4c]
	ldr r0, _0220214C ; =0x00000418
	add r1, sp, #0x44
	ldr r0, [r5, r0]
	bl ov96_021EB588
	ldr r0, _0220214C ; =0x00000418
	mov r1, #4
	ldr r0, [r5, r0]
	bl ov96_021EB630
	add r7, r7, #1
	add r5, #0x20
	cmp r7, #0xc
	blt _02201FE2
	mov r7, #0
	add r5, r6, #0
_0220202C:
	mov r0, #0xb
	str r0, [sp]
	add r0, r4, #0
	mov r1, #2
	mov r2, #1
	mov r3, #0x69
	bl ov96_021EB3E4
	str r0, [r5, #0x64]
	mov r1, #6
	bl ov96_021EB564
	ldr r0, [r5, #0x64]
	mov r1, #2
	bl ov96_021EB630
	add r7, r7, #1
	add r5, r5, #4
	cmp r7, #3
	blt _0220202C
	mov r0, #7
	str r0, [sp]
	add r0, r4, #0
	mov r1, #3
	mov r2, #1
	mov r3, #0x69
	bl ov96_021EB3E4
	str r0, [r6, #0x4c]
	mov r0, #2
	lsl r0, r0, #0xe
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
	mov r0, #0
	str r0, [sp, #0x40]
	ldr r0, [r6, #0x4c]
	add r1, sp, #0x38
	bl ov96_021EB588
	ldr r0, [r6, #0x4c]
	mov r1, #5
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r6, #0x4c]
	add r2, r1, #0
	bl ov96_021EB52C
	ldr r0, [r6, #0x4c]
	mov r1, #2
	bl ov96_021EB630
	ldr r5, _02202150 ; =ov96_0221C910
	add r3, sp, #0x14
	mov r2, #4
_0220209A:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0220209A
	ldr r0, [r5]
	add r5, r6, #0
	str r0, [r3]
	ldr r0, [sp, #4]
	add r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	mov r0, #0
	str r0, [sp, #8]
	add r0, sp, #0x14
	str r0, [sp, #0xc]
_022020C4:
	mov r0, #8
	str r0, [sp]
	add r0, r4, #0
	mov r1, #3
	mov r2, #1
	mov r3, #0x69
	bl ov96_021EB3E4
	ldr r1, [sp, #0xc]
	str r0, [r5, #0x58]
	bl ov96_021EB588
	ldr r0, [r5, #0x58]
	add r1, r7, #1
	bl ov96_021EB564
	mov r1, #1
	ldr r0, [r5, #0x58]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r7, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [r5, #0x58]
	mov r1, #3
	bl ov96_021EB630
	ldr r0, [sp, #0xc]
	add r5, r5, #4
	add r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #3
	blt _022020C4
	mov r5, #0
	mov r7, #0xa
_0220211E:
	str r7, [sp]
	add r0, r4, #0
	mov r1, #3
	mov r2, #1
	mov r3, #0x69
	bl ov96_021EB3E4
	str r0, [r6, #0x70]
	mov r1, #0
	bl ov96_021EB564
	ldr r0, [r6, #0x70]
	mov r1, #4
	bl ov96_021EB630
	add r5, r5, #1
	add r6, r6, #4
	cmp r5, #9
	blt _0220211E
	add sp, #0x5c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02202148: .word 0x000005D4
_0220214C: .word 0x00000418
_02202150: .word ov96_0221C910
	thumb_func_end ov96_02201EF0

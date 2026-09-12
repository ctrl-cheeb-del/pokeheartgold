.include "asm/macros.inc"
	.public ov45_0222B840
	.public ov45_0222BB58
	.public ov45_0222BB60
	.public ov45_0222BCB8
	.public ov45_0222BD30
	.public ov45_0222BE5C
	.public ov45_0222C3B0
	.public ov45_0222CAA0
	.public ov45_0222CCDC
	.public ov45_0222D500
	.public ov45_0222D8A4
	.public ov45_0222ECB8

	.text

	thumb_func_start ov45_0222A15C
ov45_0222A15C: ; 0x0222A15C
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	ldr r0, [r4, #4]
	bl ov45_0222D8A4
	add r0, sp, #0
	bl ov45_0222ECB8
	add r1, sp, #0
	add r0, r1, #0
	ldmia r0!, {r2, r3}
	add r0, r4, #0
	add r0, #0xd8
	stmia r0!, {r2, r3}
	add r0, r4, #0
	add r0, #0xd4
	bl ov45_0222D500
	add r0, r4, #0
	bl ov45_0222B840
	mov r0, #7
	lsl r0, r0, #6
	add r0, r4, r0
	bl ov45_0222BE5C
	mov r0, #0x7a
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222BD30
	add r0, r4, #0
	add r0, #0xf8
	bl ov45_0222BB58
	mov r2, #0x7f
	lsl r2, r2, #2
	ldr r3, _0222A1EC ; =0x0000049C
	add r0, r4, r2
	add r1, r4, #0
	add r2, #0x10
	add r1, #0xf8
	add r2, r4, r2
	add r3, r4, r3
	bl ov45_0222BB60
	mov r0, #0x3a
	lsl r0, r0, #4
	add r0, r4, r0
	bl ov45_0222BCB8
	mov r0, #0x83
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov45_0222C3B0
	ldr r0, _0222A1EC ; =0x0000049C
	add r0, r4, r0
	bl ov45_0222CAA0
	ldr r0, _0222A1F0 ; =0x000004BC
	add r0, r4, r0
	bl ov45_0222CCDC
	cmp r0, #1
	bne _0222A1E8
	ldr r0, _0222A1F4 ; =0x0000052C
	mov r1, #1
	str r1, [r4, r0]
_0222A1E8:
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
_0222A1EC: .word 0x0000049C
_0222A1F0: .word 0x000004BC
_0222A1F4: .word 0x0000052C
	thumb_func_end ov45_0222A15C

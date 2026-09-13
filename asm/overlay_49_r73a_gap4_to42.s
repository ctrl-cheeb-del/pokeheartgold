	.include "asm/macros.inc"
	.include "overlay_49.inc"
	.include "global.inc"

	.text
	.public ov49_02267A1C
	.extern ov49_02265434
	.extern ov49_022655E0
	.extern ov49_02265B14
	.extern ov49_022655E0

	thumb_func_start ov49_02267A1C
ov49_02267A1C: ; 0x02267A1C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r2, #0
	ldr r2, _02267A7C ; =0x00000958
	add r5, r1, #0
	add r1, r5, r2
	add r7, r0, #0
	ldrsb r0, [r1, r4]
	add r6, r4, #0
	add r2, #0x10
	add r0, r0, #1
	strb r0, [r1, r4]
	mov r0, #0x28
	mul r6, r0
	add r0, r5, r2
	ldrsb r1, [r1, r4]
	add r0, r0, r6
	bl ov49_02265434
	str r0, [sp]
	ldr r0, _02267A80 ; =0x00000968
	add r1, sp, #4
	add r0, r5, r0
	add r0, r0, r6
	add r2, sp, #8
	add r3, sp, #0xc
	bl ov49_022655E0
	add r1, r5, #0
	mov r0, #0x78
	add r1, #0xc
	mul r0, r4
	add r0, r1, r0
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	bl sub_020182A8
	add r0, r7, #0
	add r1, r5, #0
	add r2, r4, #0
	mov r3, #0
	bl ov49_02265B14
	ldr r0, [sp]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02267A7C: .word 0x00000958
_02267A80: .word 0x00000968
	thumb_func_end ov49_02267A1C

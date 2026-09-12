	.include "asm/macros.inc"
	.public sub_020181A4

	.text

	thumb_func_start ov49_02265B94
ov49_02265B94: ; 0x02265B94
	push {r4, r5, r6, lr}
	add r5, r1, #0
	ldr r1, _02265BDC ; =0x000106DC
	add r4, r2, #0
	add r0, r0, r1
	lsl r1, r4, #2
	add r2, r5, r1
	ldr r1, _02265BE0 ; =0x0000087C
	add r6, r3, #0
	ldr r1, [r2, r1]
	add r1, r1, r6
	ldrb r2, [r1, #2]
	mov r1, #0x14
	mul r1, r2
	add r0, r0, r1
	bl sub_020181A4
	ldr r3, _02265BE4 ; =0x000008C4
	lsl r1, r4, #3
	add r2, r5, r3
	add r2, r2, r1
	lsl r1, r6, #2
	ldr r5, [sp, #0x10]
	ldr r4, [r2, r1]
	add r4, r5, r4
	cmp r4, r0
	bge _02265BD0
	str r4, [r2, r1]
	mov r0, #0
	pop {r4, r5, r6, pc}
_02265BD0:
	sub r3, #0xc4
	sub r0, r0, r3
	str r0, [r2, r1]
	mov r0, #1
	pop {r4, r5, r6, pc}
	nop
_02265BDC: .word 0x000106DC
_02265BE0: .word 0x0000087C
_02265BE4: .word 0x000008C4
	thumb_func_end ov49_02265B94

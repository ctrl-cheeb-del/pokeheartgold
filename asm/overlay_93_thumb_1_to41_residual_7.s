	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text

	thumb_func_start ov93_0225D700
ov93_0225D700: ; 0x0225D700
	push {r3, lr}
	add r3, r0, #0
	cmp r1, #0
	beq _0225D712
	cmp r1, #1
	beq _0225D720
	cmp r1, #2
	beq _0225D72E
	b _0225D73C
_0225D712:
	add r0, #0xa4
	mov r1, #0
	ldr r0, [r0]
	add r2, r1, #0
	bl sub_02015494
	pop {r3, pc}
_0225D720:
	add r0, #0xa4
	ldr r0, [r0]
	mov r1, #1
	mov r2, #0
	bl sub_02015494
	pop {r3, pc}
_0225D72E:
	add r0, #0xa4
	ldr r0, [r0]
	mov r1, #2
	mov r2, #0
	bl sub_02015494
	pop {r3, pc}
_0225D73C:
	bl GF_AssertFail
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov93_0225D700

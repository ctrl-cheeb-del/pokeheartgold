	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public ov40_02230D94
	.public sub_0203088C
	.text

	thumb_func_start ov40_02230D94
ov40_02230D94: ; 0x02230D94
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	add r7, r2, #0
	mov r4, #1
	add r5, r0, #4
_02230D9E:
	ldr r0, _02230DC8 ; =0x0000087C
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02230DBA
	mov r1, #4
	mov r2, #0
	bl sub_0203088C
	eor r1, r7
	eor r0, r6
	orr r0, r1
	bne _02230DBA
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02230DBA:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _02230D9E
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02230DC8: .word 0x0000087C
	thumb_func_end ov40_02230D94

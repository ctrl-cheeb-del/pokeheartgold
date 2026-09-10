	.include "asm/macros.inc"
	.include "unk_02054648.inc"
	.include "global.inc"
	.text
	thumb_func_start GetMetatileBehavior
GetMetatileBehavior: ; 0x02054918
	push {r3, r4, lr}
	sub sp, #4
	ldr r4, [r0, #0x60]
	add r3, sp, #0
	ldr r4, [r4, #4]
	blx r4
	cmp r0, #0
	beq _02054938
	add r0, sp, #0
	ldrh r0, [r0]
	add sp, #4
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	pop {r3, r4, pc}
_02054938:
	mov r0, #0xff
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end GetMetatileBehavior

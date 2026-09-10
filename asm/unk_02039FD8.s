	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02039FD8
sub_02039FD8: ; 0x02039FD8
	push {r3, r4, r5, lr}
	mov r1, #0x72
	lsl r1, r1, #4
	bl Heap_Alloc
	add r4, r0, #0
	add r0, #0x1f
	mov r1, #0x1f
	bic r0, r1
	bl DWC_Init
	add r5, r0, #0
	add r0, r4, #0
	bl Heap_Free
	add r0, r5, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_02039FD8

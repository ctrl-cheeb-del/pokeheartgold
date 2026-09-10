#include "constants/items.h"
#include "constants/moves.h"
	.include "asm/macros.inc"
	.include "unk_02074E5C.inc"
	.include "global.inc"


	.text
	thumb_func_start sub_0207527C
sub_0207527C: ; 0x0207527C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl sub_02037190
	mov r1, #0x42
	lsl r1, r1, #2
	cmp r0, r1
	beq _02075290
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02075290:
	ldr r4, [r5]
	mov r0, #0x80
	ldr r1, [r4]
	tst r0, r1
	beq _020752A2
	bl sub_0203769C
	lsl r0, r0, #3
	b _020752A8
_020752A2:
	bl sub_0203769C
	lsl r0, r0, #2
_020752A8:
	add r0, r4, r0
	mov r1, #0x52
	add r0, #0xf8
	lsl r1, r1, #2
	add r2, r5, #0
	ldr r0, [r0]
	ldr r1, [r4, r1]
	add r2, #0x20
	bl sub_02075554
	mov r4, #0
	mov r6, #5
	mov r7, #0x88
_020752C2:
	add r0, r6, #0
	add r1, r7, #0
	bl Heap_Alloc
	str r0, [r5, #0x10]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _020752C2
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0207527C

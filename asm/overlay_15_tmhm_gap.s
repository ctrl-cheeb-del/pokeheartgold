#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text

	.public ov15_021FE914
	.extern ov15_021FE8C4
	.extern ov15_021FE9B0


	thumb_func_start ov15_021FE914
ov15_021FE914: ; 0x021FE914
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r2, #0
	add r6, r1, #0
	add r5, r0, #0
	mov r0, #0x69
	ldrh r1, [r7]
	lsl r0, r0, #2
	add r4, r3, #0
	cmp r1, r0
	bhs _021FE95E
	sub r0, #0x5d
	sub r0, r1, r0
	mov r1, #2
	lsl r0, r0, #0x10
	str r1, [sp]
	lsr r2, r0, #0x10
	str r6, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	add r0, r4, #5
	str r0, [sp, #0xc]
	mov r0, #0xbb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r3, r1, #0
	bl sub_0200CE7C
	lsl r2, r4, #0x10
	ldrh r1, [r7, #2]
	ldr r3, _021FE98C ; =0x00010200
	add r0, r5, #0
	lsr r2, r2, #0x10
	bl ov15_021FE8C4
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_021FE95E:
	sub r0, r0, #1
	sub r0, r1, r0
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	str r6, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	add r0, r4, #5
	str r0, [sp, #8]
	mov r0, #0xbb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r2, #2
	mov r3, #1
	bl PrintUIntOnWindow
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #0x10
	bl ov15_021FE9B0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FE98C: .word 0x00010200
	thumb_func_end ov15_021FE914

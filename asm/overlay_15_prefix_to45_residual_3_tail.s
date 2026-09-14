#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"
	.text
	.public ov15_021F9D60
	thumb_func_start ov15_021F9D60
ov15_021F9D60: ; 0x021F9D60
	push {r3, r4}
	mov r3, #0x8d
	lsl r3, r3, #2
	ldr r0, [r0, r3]
	add r4, r0, #4
	add r0, #0x64
	ldrb r3, [r0]
	mov r0, #0xc
	mul r0, r3
	cmp r2, #0
	ldr r2, [r4, r0]
	bne _021F9D80
	lsl r0, r1, #2
	ldrh r0, [r2, r0]
	pop {r3, r4}
	bx lr
_021F9D80:
	lsl r0, r1, #2
	add r0, r2, r0
	ldrh r0, [r0, #2]
	pop {r3, r4}
	bx lr
	.balign 4, 0
	thumb_func_end ov15_021F9D60

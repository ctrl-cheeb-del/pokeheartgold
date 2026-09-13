#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222C828
	.public ov45_02254A60

thumb_func_start ov45_0222C828
ov45_0222C828: ; 0x0222C828
	push {r3, lr}
	ldrb r2, [r1, #0x11]
	add r0, r3, #0
	lsl r3, r2, #2
	ldr r2, _0222C838 ; =ov45_02254A60
	ldr r2, [r2, r3]
	blx r2
	pop {r3, pc}
	.balign 4, 0
_0222C838: .word ov45_02254A60
	thumb_func_end ov45_0222C828

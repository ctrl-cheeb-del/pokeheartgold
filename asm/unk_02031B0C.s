#include "constants/items.h"
	.include "asm/macros.inc"
	.include "unk_02031B0C.inc"
	.include "global.inc"

	.rodata

	.public _020F68D0
_020F68D0:
	.short ITEM_LEVEL_BALL
	.short ITEM_MOON_BALL
	.short ITEM_LURE_BALL
	.short ITEM_FRIEND_BALL
	.short ITEM_LOVE_BALL
	.short ITEM_FAST_BALL
	.short ITEM_HEAVY_BALL
	.public _020F68DE
_020F68DE:
	.byte  4, -2,  0,  0
	.byte  0,  0,  4, -2
	.byte  0,  0,  0,  0
	.byte  4, -2,  0,  0
	.byte  0,  0,  4, -2
	.byte -2,  0,  0,  0
	.byte  4, -2, -2, -2
	.byte -2, -2,  2,  2
	.byte  2,  2,  2,  0
	.public _020F6902
_020F6902:
	.byte 0x00, 0x00, 0x74, 0x16, 0x0A, 0x00, 0x00, 0x00
	.byte 0x96, 0x00, 0x78, 0x00, 0x14, 0x0E
	.byte 0x00, 0x00, 0x1C, 0x02, 0x7D, 0x00, 0x00, 0x1C
	.byte 0x14, 0x00, 0xC8, 0x00, 0x88, 0x00, 0x00, 0x00
	.byte 0x18, 0x0E, 0x96, 0x00, 0x68, 0x0C, 0x00, 0x00, 0x00, 0x14

	.text

	thumb_func_start sub_02031C08
sub_02031C08: ; 0x02031C08
	push {r3, r4}
	ldrh r4, [r0, #0xa]
	mov r3, #0
	add r2, r3, #0
	mov r1, #7
_02031C12:
	add r0, r4, #0
	tst r0, r1
	beq _02031C1E
	add r0, r3, #1
	lsl r0, r0, #0x18
	lsr r3, r0, #0x18
_02031C1E:
	lsl r0, r4, #0xd
	add r2, r2, #1
	lsr r4, r0, #0x10
	cmp r2, #5
	blt _02031C12
	add r0, r3, #0
	pop {r3, r4}
	bx lr
	.balign 4, 0
	thumb_func_end sub_02031C08

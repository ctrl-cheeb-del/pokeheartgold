#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "unk_020957B0.inc"
	.include "global.inc"

	.text
	.public sub_02095BF0
	.rodata

	; File boundary
_0210841C:
	.byte 0x06, 0x01, 0x06, 0x06
_02108420:
	.byte 0x01, 0x03, 0x03, 0x04
_02108424:
	.byte 0x01, 0x01, 0x01, 0x05
_02108428:
	.byte 0x01, 0x03, 0x03, 0x03
_0210842C:
	.byte 0x01, 0x01, 0x01, 0x01
_02108430:
	.byte 0x06, 0x05, 0x1E, 0x02
	.public _02108434
_02108434:
	.word _02108430, sub_020957B0, sub_02095838
	.word _0210842C, sub_020958C0, sub_02095920
	.word _02108428, sub_0209592C, sub_020959D8
	.word _02108420, sub_02095A34, sub_02095A78
	.word _02108424, sub_02095A7C, sub_02095AF8
	.word _0210841C, sub_02095B04, sub_02095B88

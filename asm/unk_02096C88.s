#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "unk_02096C88.inc"
	.include "global.inc"

	.rodata

	; File boundary
	.public _02108804
_02108804:
	.word sub_02096ED0
	.word sub_02096DE4
	.word sub_02096DF4
	.word sub_02096EF0
	.word sub_02096F0C
	.word sub_02096DBC
	.word sub_02096DB4
	.word sub_02096DA8
	.word sub_02096F2C
	.word sub_02096F3C
	.word sub_02096F70
	.word sub_02096F80
	.word sub_02096F50
	.word sub_02096F60
	.word sub_02096F9C
	.word sub_02096FAC
	.word sub_02096FBC
	.word sub_02096FD0
	.public _0210884C
_0210884C:
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02091570, sub_020342C0, 0
	.word sub_02096D60, sub_02096FE4, 0
	.word sub_02096D80, sub_02096FE8, sub_02096FF0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0
	.word 0, 0, 0


#include "constants/pokemon.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/sprites.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/std_script.h"
	.include "asm/macros.inc"
	.include "unk_0206979C.inc"
	.include "global.inc"

	.public NNS_G3dGlb

	.rodata

	.public _020FE8A4
_020FE8A4:
	.word 0x00001000
	.word 0x00001000
	.word 0x00001000
	.public _020FE8B0
_020FE8B0:
	.word 0x00001000, 0x00000000, 0x00000000
	.word 0x00000000, 0x00001000, 0x00000000
	.word 0x00000000, 0x00000000, 0x00001000

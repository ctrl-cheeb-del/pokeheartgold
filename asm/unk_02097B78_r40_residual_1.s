#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "unk_02097B78.inc"
	.include "global.inc"

	.text
	.public LegendaryCinematic_Exit
	.public LegendaryCinematic_Init
	.public LegendaryCinematic_Main
	.rodata

	.balign 4, 0
_02108F38:
	.word ScriptCinematic_HoOh
	.word ScriptCinematic_Lugia
	.word ScriptCinematic_Arceus

#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "unk_020915B0.inc"
	.include "global.inc"

	.text
	.public LoadDwcOverlay
	.public LoadOVY13
	.public LoadOVY38
	.public UnloadDwcOverlay
	.public UnloadOVY13
	.public UnloadOVY38
	.public sub_020915F0
	.public sub_02091634
	.rodata

	.public gApp_MainMenu_SelectOption_NintendoWFCSetup
gApp_MainMenu_SelectOption_NintendoWFCSetup:
	.word sub_02091634, 0, 0, 0xFFFFFFFF

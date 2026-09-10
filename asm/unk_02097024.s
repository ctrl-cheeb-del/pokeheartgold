#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "unk_02097024.inc"
	.include "global.inc"

	.rodata

	.public _02108EA0
_02108EA0:
	.word ov85_021E88AC, ov85_021E8A08, ov85_021E8B08, FS_OVERLAY_ID(OVY_85)
	.public _02108EB0
_02108EB0:
	.word ov85_021E5900, ov85_021E5AAC, ov85_021E5A34, FS_OVERLAY_ID(OVY_85)
	.public _02108EC0
_02108EC0:
	.word sub_020970E4
	.word sub_02097108
	.word sub_02097148
	.word sub_020971AC
	.word sub_020971D4
	.word sub_020971EC

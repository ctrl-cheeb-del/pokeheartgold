#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_0208FB64.inc"
	.include "global.inc"

	.public gOverlayTemplate_Battle
	.public gNatureStatMods

	.text


	.rodata

	.public _021059DC
_021059DC:
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_0208FCFC, sub_0208FD80, 0
	.word sub_0208FD00, sub_0208FD80, 0
	.word sub_0208FCDC, sub_0208FD80, 0
	.word sub_0208FBE0, sub_0208FD7C, 0
	.word sub_0208FBF0, sub_0208FD84, 0
	.word sub_0208FD04, sub_0208FD7C, 0
	.word sub_0208FD1C, sub_0208FD7C, 0
	.word sub_0208FB98, sub_0208FD7C, 0
	.word sub_0208FB78, sub_02091590, sub_0208FD88
	.word sub_0208FB88, sub_0208FD80, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0
	.word sub_02091570, sub_0208FD7C, 0

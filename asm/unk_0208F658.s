#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_0208F658.inc"
	.include "global.inc"

	.public gOverlayTemplate_Battle
	.public gNatureStatMods

	.text


	.rodata

	.public _02105430
_02105430:
	.word sub_0208F680, sub_0208F7F8, sub_0208F800
	.word sub_0208F6F4, sub_020342C4, 0
	.word sub_0208F714, sub_020342C4, 0
	.word sub_0208F724, sub_020342C4, 0
	.word sub_0208F728, sub_020342C4, 0
	.word sub_0208F72C, sub_020342C4, 0
	.word sub_0208F77C, sub_0208F7F4, sub_0208F800
	.word sub_0208F7A8, sub_0208F7E8, sub_0208F800
	.word sub_0208F738, sub_020342C0, 0
	.word sub_0208F73C, sub_020342C4, 0
	.word sub_0208F74C, sub_0208F7F0, 0

#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_02087A78.inc"
	.include "global.inc"
	.include "field_transition_finish.inc"

	.public gOverlayTemplate_Battle
	.public _021028B4
	.public _021028C4
	.public gNatureStatMods

	.text
	.public sub_02087C38
	.rodata

	.public _02102830
	.public _02102830
_02102830:
	.word sub_02087B10, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102840
_02102840:
	.word sub_02087B58, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102850
_02102850:
	.word sub_02087B4C, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102860
_02102860:
	.word sub_02087B40, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102870
_02102870:
	.word sub_02087B34, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102880
_02102880:
	.word sub_02087B28, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102890
_02102890:
	.word sub_02087B1C, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _021028A0
_021028A0:
	.word 0x61
	.word 0x63
	.word 0x64
	.word 0x65
	.word 0x66

	.data

	.public _02110594
_02110594:
	.word _02102830
	.word _02102890
	.word _02102880
	.word _02102870
	.word _02102860
	.word _02102850
	.word _02102840

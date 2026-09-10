	.public _0210125C
	.public _02101260
	.public _02101270
	.public _02101280
	.public _02101290
	.public _021012A0
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_02078834.inc"
	.include "global.inc"

	.public gOverlayTemplate_Battle
	.public gNatureStatMods

	.text
	.public sub_02078834
	.public sub_02078B2C
	.public sub_02078B58
	.public sub_02078B78
	.public sub_02078B9C
	.public sub_02078BD8
	.public sub_02078C18
	.public sub_02078C60
	.public sub_02078C74
	.public sub_02078CB4
	.public sub_02078CC8
	.public sub_02078D10
	.public sub_02078D24
	.rodata

_0210125C:
	.byte 0x03, 0x04, 0x04, 0x04
_02101260:
	.word ov91_0225C540, ov91_0225C58C, ov91_0225C9EC, FS_OVERLAY_ID(OVY_91)
_02101270:
	.word ov92_0225CAB4, ov92_0225CDF4, ov92_0225D36C, FS_OVERLAY_ID(OVY_92)
_02101280:
	.word ov44_02232EA8, ov44_02232F64, ov44_022330A8, FS_OVERLAY_ID(OVY_44)
_02101290:
	.word ov44_0222A4B4, ov44_0222A60C, ov44_0222A758, FS_OVERLAY_ID(OVY_44)
_021012A0:
	.word ov93_0225C540, ov93_0225C574, ov93_0225C6C0, FS_OVERLAY_ID(OVY_93)

#include "constants/sndseq.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/pokemon.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/std_script.h"
#include "fielddata/script/scr_seq/event_D24R0204.h"
#include "constants/field_move_response.h"
	.include "asm/macros.inc"
	.include "unk_0205CB48.inc"
	.include "global.inc"

	.text
	.public PlayerAvatar_MoveControl
	.public sub_0205CBE4
	.public sub_0205CBEC
	.rodata

	.public _020FCB7C
_020FCB7C:
	.word sub_0205D09C
	.word sub_0205D0A8
	.word sub_0205D190
	.public _020FCB88
_020FCB88:
	.word MetatileBehavior_IsIce, 1
	.word 0, 3
	.public _020FCB98
_020FCB98:
	.short SEQ_SE_GS_ASHIOTO_A_WALK, 0
	.short SEQ_SE_GS_ASHIOTO_A, 0
	.short SEQ_SE_GS_OCHIBA, 0
	.short SEQ_SE_GS_EDAPAKI, 0
	.short SEQ_SE_GS_KUSA2, 0
	.short SEQ_SE_GS_ASHIOTO_B, 1
	.short SEQ_SE_GS_ASHIOTO_D, 1
	.short SEQ_SE_GS_ASHIOTO_D_2, 0
	.short SEQ_SE_GS_ASHIOTO_E, 0
	.short SEQ_SE_GS_ASHIOTO_B, 1
	.short SEQ_SE_GS_ASHIOTO_F, 1
	.short SEQ_SE_GS_ASHIOTO_D, 0
	.short SEQ_SE_GS_ASHIOTO_H, 0
	.short SEQ_SE_GS_ASHIOTO_G, 0
	.short SEQ_SE_DP_BOX02, 0
	.short SEQ_SE_DP_BOX01, 0

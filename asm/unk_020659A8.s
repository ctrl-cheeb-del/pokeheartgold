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
	.include "unk_020658D4.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020659A8
sub_020659A8: ; 0x020659A8
	push {r3, lr}
	bl sub_0205F394
	ldrh r0, [r0, #0xa]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1e
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end sub_020659A8

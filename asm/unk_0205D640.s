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
	thumb_func_start sub_0205D640
sub_0205D640: ; 0x0205D640
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, sp, #8
	ldrh r5, [r4, #0x10]
	str r5, [sp]
	ldrh r4, [r4, #0x14]
	str r4, [sp, #4]
	bl sub_0205D6E8
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0205D640

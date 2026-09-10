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
	.include "unk_02062108.inc"
	.include "global.inc"
	.text
	thumb_func_start MapObjectMovementCmd076_Step1
MapObjectMovementCmd076_Step1: ; 0x0206308C
	push {r3, lr}
	ldr r1, _020630A0 ; =_020FDA50
	bl sub_02062FEC
	cmp r0, #1
	bne _0206309C
	mov r0, #1
	pop {r3, pc}
_0206309C:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_020630A0: .word _020FDA50
	thumb_func_end MapObjectMovementCmd076_Step1

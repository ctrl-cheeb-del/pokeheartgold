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
	thumb_func_start MapObjectMovementCmd098_Step1
MapObjectMovementCmd098_Step1: ; 0x0206313C
	push {r3, lr}
	ldr r1, _02063150 ; =_020FDA68
	bl sub_02062FEC
	cmp r0, #1
	bne _0206314C
	mov r0, #1
	pop {r3, pc}
_0206314C:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_02063150: .word _020FDA68
	thumb_func_end MapObjectMovementCmd098_Step1

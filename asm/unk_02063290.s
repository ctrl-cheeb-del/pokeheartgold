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
	thumb_func_start MapObjectMovementCmd102_Step1
MapObjectMovementCmd102_Step1: ; 0x02063290
	push {r4, lr}
	add r4, r0, #0
	bl sub_0205F3E4
	ldr r1, [r0]
	add r1, r1, #1
	str r1, [r0]
	cmp r1, #0x15
	bhs _020632A6
	mov r0, #0
	pop {r4, pc}
_020632A6:
	add r0, r4, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	pop {r4, pc}
	thumb_func_end MapObjectMovementCmd102_Step1

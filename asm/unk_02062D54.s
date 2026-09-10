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
	thumb_func_start sub_02062D54
sub_02062D54: ; 0x02062D54
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #4
	bl sub_0205F3C0
	str r4, [r0]
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_02062D54
	thumb_func_start MapObjectMovementCmd064_Step1
MapObjectMovementCmd064_Step1: ; 0x02062D6C
	push {r4, lr}
	add r4, r0, #0
	bl sub_0205F3E4
	ldr r1, [r0]
	cmp r1, #0
	beq _02062D82
	sub r1, r1, #1
	str r1, [r0]
	mov r0, #0
	pop {r4, pc}
_02062D82:
	add r0, r4, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	pop {r4, pc}
	thumb_func_end MapObjectMovementCmd064_Step1

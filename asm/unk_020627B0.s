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
	thumb_func_start sub_020627B0
sub_020627B0: ; 0x020627B0
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	add r6, r2, #0
	add r4, r3, #0
	mov r1, #0xc
	add r5, r0, #0
	bl sub_0205F3C0
	strh r4, [r0]
	add r1, r6, #1
	strh r1, [r0, #2]
	add r0, r5, #0
	add r1, r7, #0
	bl MapObject_SetFacingDirection
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0205F328
	add r0, r5, #0
	bl sub_02060F78
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_020627B0
	thumb_func_start MapObjectMovementCmd040_Step1
MapObjectMovementCmd040_Step1: ; 0x020627E4
	push {r4, lr}
	add r4, r0, #0
	bl sub_0205F3E4
	mov r1, #2
	ldrsh r2, [r0, r1]
	sub r2, r2, #1
	strh r2, [r0, #2]
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _020627FE
	mov r0, #0
	pop {r4, pc}
_020627FE:
	add r0, r4, #0
	mov r1, #0x20
	bl MapObject_SetFlagsBits
	add r0, r4, #0
	mov r1, #0
	bl sub_0205F328
	add r0, r4, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	pop {r4, pc}
	thumb_func_end MapObjectMovementCmd040_Step1

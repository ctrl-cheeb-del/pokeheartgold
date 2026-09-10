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
	thumb_func_start sub_0206633C
sub_0206633C: ; 0x0206633C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl sub_0205F394
	ldr r6, _0206635C ; =_020FE3CC
	add r4, r0, #0
_02066348:
	ldrb r2, [r4]
	add r0, r5, #0
	add r1, r4, #0
	lsl r2, r2, #2
	ldr r2, [r6, r2]
	blx r2
	cmp r0, #1
	beq _02066348
	pop {r4, r5, r6, pc}
	nop
_0206635C: .word _020FE3CC
	thumb_func_end sub_0206633C

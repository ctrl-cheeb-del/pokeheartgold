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
	thumb_func_start sub_0205D450
sub_0205D450: ; 0x0205D450
	push {r3, r4, r5, lr}
	add r4, r1, #0
	mov r1, #0
	mvn r1, r1
	add r5, r0, #0
	cmp r4, r1
	bne _0205D468
	mov r1, #0
	bl PlayerAvatar_SetMoveState
	mov r0, #0
	pop {r3, r4, r5, pc}
_0205D468:
	bl PlayerAvatar_GetFacingDirection
	cmp r0, r4
	beq _0205D486
	add r0, r5, #0
	bl PlayerAvatar_GetMoveState
	cmp r0, #1
	beq _0205D486
	add r0, r5, #0
	mov r1, #2
	bl PlayerAvatar_SetMoveState
	mov r0, #2
	pop {r3, r4, r5, pc}
_0205D486:
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetMoveState
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0205D450

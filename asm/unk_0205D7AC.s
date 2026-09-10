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
	thumb_func_start sub_0205D7AC
sub_0205D7AC: ; 0x0205D7AC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl PlayerAvatar_GetUnk24
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _0205D7DC
	cmp r6, #2
	bge _0205D7D0
	add r0, r5, #0
	mov r1, #0
	bl PlayerAvatar_SetMoveState
	mov r0, #0
	pop {r4, r5, r6, pc}
_0205D7D0:
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetMoveState
	mov r0, #3
	pop {r4, r5, r6, pc}
_0205D7DC:
	add r0, r5, #0
	bl PlayerAvatar_GetFacingDirection
	cmp r0, r4
	beq _0205D80C
	add r0, r5, #0
	bl PlayerAvatar_GetMoveState
	cmp r0, #1
	beq _0205D80C
	cmp r6, #2
	bge _0205D800
	add r0, r5, #0
	mov r1, #2
	bl PlayerAvatar_SetMoveState
	mov r0, #2
	pop {r4, r5, r6, pc}
_0205D800:
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetMoveState
	mov r0, #3
	pop {r4, r5, r6, pc}
_0205D80C:
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetMoveState
	mov r0, #1
	pop {r4, r5, r6, pc}
	thumb_func_end sub_0205D7AC

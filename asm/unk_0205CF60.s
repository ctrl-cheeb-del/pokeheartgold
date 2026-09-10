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
	thumb_func_start sub_0205CF60
sub_0205CF60: ; 0x0205CF60
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl PlayerAvatar_GetMoveState
	add r4, r0, #0
	add r0, r5, #0
	bl PlayerAvatar_GetPlayerMoveState
	cmp r4, #0
	bne _0205CF78
	mov r0, #1
	pop {r3, r4, r5, pc}
_0205CF78:
	cmp r4, #2
	bne _0205CF80
	mov r0, #1
	pop {r3, r4, r5, pc}
_0205CF80:
	cmp r4, #1
	bne _0205CFB6
	cmp r0, #0
	beq _0205CF8C
	cmp r0, #3
	bne _0205CF90
_0205CF8C:
	mov r0, #1
	pop {r3, r4, r5, pc}
_0205CF90:
	add r0, r5, #0
	bl PlayerAvatar_GetMapObject
	add r4, r0, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _0205CFA4
	mov r0, #1
	pop {r3, r4, r5, pc}
_0205CFA4:
	add r0, r4, #0
	bl MapObject_GetMovementCommand
	bl sub_0205DE64
	cmp r0, #1
	bne _0205CFB6
	mov r0, #1
	pop {r3, r4, r5, pc}
_0205CFB6:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0205CF60

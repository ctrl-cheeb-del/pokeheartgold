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
	thumb_func_start sub_0205DCFC
sub_0205DCFC: ; 0x0205DCFC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	mov r1, #0
	add r4, r2, #0
	mvn r1, r1
	cmp r4, r1
	beq _0205DD8E
	bl PlayerAvatar_GetState
	cmp r0, #1
	bne _0205DD8E
	add r0, r5, #0
	bl MapObject_GetFieldSystem
	str r0, [sp]
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r6, r0, #0
	add r0, r4, #0
	bl GetDeltaXByFacingDirection
	add r7, r0, #0
	add r0, r5, #0
	bl MapObject_GetZCoord
	str r0, [sp, #4]
	add r0, r4, #0
	bl GetDeltaYByFacingDirection
	add r3, r0, #0
	ldr r2, [sp, #4]
	ldr r0, [sp]
	add r1, r6, r7
	add r2, r2, r3
	bl GetMetatileBehavior
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060E54
	cmp r0, #0
	beq _0205DD5C
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DD5C:
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060EBC
	cmp r0, #0
	beq _0205DD6E
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DD6E:
	add r0, r4, #0
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #0
	beq _0205DD7E
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DD7E:
	add r0, r4, #0
	bl MetatileBehavior_IsMud
	cmp r0, #0
	beq _0205DD8E
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DD8E:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0205DCFC

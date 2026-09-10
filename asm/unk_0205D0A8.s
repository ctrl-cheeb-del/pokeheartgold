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
	thumb_func_start sub_0205D0A8
sub_0205D0A8: ; 0x0205D0A8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl PlayerAvatar_GetMapObject
	add r4, r0, #0
	bl MapObject_GetNextFacingDirection
	add r6, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	bl sub_0205D240
	str r0, [sp]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl sub_0205DA34
	add r7, r0, #0
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetForcedMovement
	cmp r7, #0
	beq _0205D10A
	add r0, r4, #0
	bl MapObject_GetFieldSystem
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetFlag1
	add r0, r5, #0
	mov r1, #0
	bl PlayerAvatar_SetMoveState
	add r0, r4, #0
	bl sub_0206D494
	cmp r0, #0
	bne _0205D106
	add r0, r5, #0
	bl sub_0205D1FC
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0205D106:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205D10A:
	ldr r1, [sp]
	add r0, r5, #0
	bl sub_0205D2A0
	cmp r0, #0
	bne _0205D170
	add r0, r5, #0
	bl sub_0205D1FC
	add r0, r6, #0
	bl sub_020611F4
	add r6, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl sub_0205DA34
	cmp r0, #0
	beq _0205D136
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0205D136:
	mov r1, #6
	add r0, r4, #0
	lsl r1, r1, #6
	bl MapObject_SetFlagsBits
	add r0, r6, #0
	mov r1, #8
	bl sub_0206234C
	add r2, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0205DA1C
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetFlag1
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetForcedMovement
	mov r1, #0
	mvn r1, r1
	add r0, r5, #0
	add r2, r1, #0
	bl PlayerAvatar_SetUnk28Unk2C
	b _0205D182
_0205D170:
	mov r1, #6
	add r0, r4, #0
	lsl r1, r1, #6
	bl MapObject_SetFlagsBits
	add r0, r5, #0
	add r1, r6, #0
	bl sub_0205D2D0
_0205D182:
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetMoveState
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0205D0A8
	thumb_func_start sub_0205D190
sub_0205D190: ; 0x0205D190
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl PlayerAvatar_GetMapObject
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #1
	bl sub_0205DA34
	cmp r0, #0
	bne _0205D1CE
	mov r0, #1
	mov r1, #0x14
	bl sub_0206234C
	add r2, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0205DA1C
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetMoveState
	add r0, r5, #0
	mov r1, #3
	bl PlayerAvatar_SetUnk24
	mov r0, #1
	pop {r3, r4, r5, pc}
_0205D1CE:
	mov r0, #1
	add r1, r0, #0
	bl sub_0206234C
	add r2, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0205DA1C
	add r0, r5, #0
	bl PlayerAvatar_ClearUnk24ClearFlag2
	add r0, r5, #0
	mov r1, #0
	bl PlayerAvatar_SetMoveState
	add r0, r5, #0
	mov r1, #0
	bl PlayerAvatar_SetFlag2
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0205D190

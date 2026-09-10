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
	.include "unk_0205FD20.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02061070
sub_02061070: ; 0x02061070
	push {r3, r4, r5, lr}
	sub sp, #0x18
	add r1, sp, #0xc
	add r5, r0, #0
	bl MapObject_CopyPositionVector
	add r3, sp, #0xc
	ldmia r3!, {r0, r1}
	add r2, sp, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	add r0, r5, #0
	bl MapObject_CheckIgnoreHeights
	cmp r0, #1
	bne _020610A2
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0xc
	bl MapObject_ClearFlagsBits
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, pc}
_020610A2:
	add r0, r5, #0
	bl MapObject_CheckFlag29
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_GetFieldSystem
	add r1, sp, #0
	add r2, r4, #0
	bl sub_02061248
	add r4, r0, #0
	cmp r4, #1
	bne _020610F6
	ldr r0, [sp, #4]
	add r1, sp, #0xc
	str r0, [sp, #0x10]
	add r0, r5, #0
	bl MapObject_SetPositionVector
	add r0, r5, #0
	bl MapObject_GetYCoord
	add r1, r0, #0
	add r0, r5, #0
	bl MapObject_SetPreviousY
	ldr r1, [sp, #0x10]
	add r0, r5, #0
	asr r2, r1, #3
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	asr r1, r1, #0xc
	bl MapObject_SetCurrentY
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0xc
	bl MapObject_ClearFlagsBits
	b _02061100
_020610F6:
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0xc
	bl MapObject_SetFlagsBits
_02061100:
	add r0, r4, #0
	add sp, #0x18
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_02061070

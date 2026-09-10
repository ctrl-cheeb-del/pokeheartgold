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
	thumb_func_start sub_0205D01C
sub_0205D01C: ; 0x0205D01C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	mov r4, #0
	bl PlayerAvatar_GetMapObject
	bl sub_0205F504
	add r7, r0, #0
	add r0, r5, #0
	add r1, r7, #0
	add r2, r6, #0
	bl sub_0205E078
	cmp r0, #1
	bne _0205D040
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_0205D040:
	add r0, r5, #0
	bl PlayerAvatar_CheckFlag1
	cmp r0, #1
	bne _0205D04E
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
_0205D04E:
	lsl r0, r7, #0x18
	ldr r5, _0205D074 ; =_020FCB88
	lsr r6, r0, #0x18
_0205D054:
	ldr r1, [r5]
	add r0, r6, #0
	blx r1
	cmp r0, #1
	bne _0205D066
	ldr r0, _0205D078 ; =_020FCB88 + 4
	lsl r1, r4, #3
	ldr r0, [r0, r1]
	pop {r3, r4, r5, r6, r7, pc}
_0205D066:
	add r5, #8
	ldr r0, [r5]
	add r4, r4, #1
	cmp r0, #0
	bne _0205D054
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0205D074: .word _020FCB88
_0205D078: .word _020FCB88 + 4
	thumb_func_end sub_0205D01C

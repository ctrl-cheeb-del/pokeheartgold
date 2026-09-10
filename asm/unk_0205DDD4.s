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
	thumb_func_start sub_0205DDD4
sub_0205DDD4: ; 0x0205DDD4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r2, #0
	add r6, r0, #0
	add r0, r5, #0
	bl sub_0205DD9C
	add r4, r0, #0
	add r0, r5, #0
	bl sub_0205DDB8
	mov r1, #0
	mvn r1, r1
	add r5, r0, #0
	cmp r4, r1
	beq _0205DE34
	cmp r5, r1
	bne _0205DDFA
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
_0205DDFA:
	add r0, r6, #0
	bl PlayerAvatar_GetNextFacingDirection
	add r7, r0, #0
	add r0, r6, #0
	bl PlayerAvatar_GetUnk28
	str r0, [sp]
	add r0, r6, #0
	bl PlayerAvatar_GetUnk2C
	mov r1, #0
	mvn r1, r1
	cmp r7, r1
	beq _0205DE32
	ldr r1, [sp]
	cmp r4, r1
	bne _0205DE26
	cmp r5, r0
	bne _0205DE26
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
_0205DE26:
	cmp r5, r0
	beq _0205DE2E
	add r0, r5, #0
	pop {r3, r4, r5, r6, r7, pc}
_0205DE2E:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
_0205DE32:
	add r0, r5, #0
_0205DE34:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0205DDD4

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
	thumb_func_start sub_0205DF0C
sub_0205DF0C: ; 0x0205DF0C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r2, #0
	add r6, r3, #0
	bl sub_0205DDD4
	str r0, [sp]
	ldr r1, [sp]
	add r0, r5, #0
	bl sub_0205DEC0
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl PlayerAvatar_SetMoveState
	cmp r4, #0
	bne _0205DF3E
	add r0, r5, #0
	bl PlayerAvatar_GetFacingDirection
	mov r1, #0
	bl sub_0206234C
	pop {r3, r4, r5, r6, r7, pc}
_0205DF3E:
	cmp r4, #2
	bne _0205DF4C
	ldr r0, [sp]
	mov r1, #0x28
	bl sub_0206234C
	pop {r3, r4, r5, r6, r7, pc}
_0205DF4C:
	add r0, r5, #0
	bl PlayerAvatar_GetMapObject
	ldr r0, [sp, #0x1c]
	mov r4, #4
	add r1, r0, #0
	tst r1, r4
	beq _0205DF60
	mov r4, #0x38
	b _0205DFBE
_0205DF60:
	cmp r0, #0
	beq _0205DF76
	mov r1, #8
	mov r4, #0x1c
	tst r0, r1
	bne _0205DFBE
	mov r0, #SEQ_SE_DP_WALL_HIT>>8
	lsl r0, r0, #8
	bl PlaySE
	b _0205DFBE
_0205DF76:
	cmp r6, #5
	bhi _0205DFA8
	add r0, r6, r6
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0205DF86: ; jump table
	.short _0205DF92 - _0205DF86 - 2 ; case 0
	.short _0205DF94 - _0205DF86 - 2 ; case 1
	.short _0205DF98 - _0205DF86 - 2 ; case 2
	.short _0205DF9C - _0205DF86 - 2 ; case 3
	.short _0205DFA0 - _0205DF86 - 2 ; case 4
	.short _0205DFA4 - _0205DF86 - 2 ; case 5
_0205DF92:
	b _0205DFAA
_0205DF94:
	mov r4, #8
	b _0205DFAA
_0205DF98:
	mov r4, #0xc
	b _0205DFAA
_0205DF9C:
	mov r4, #0x4c
	b _0205DFAA
_0205DFA0:
	mov r4, #0x10
	b _0205DFAA
_0205DFA4:
	mov r4, #0x14
	b _0205DFAA
_0205DFA8:
	mov r4, #4
_0205DFAA:
	ldr r0, [sp, #0x18]
	cmp r0, #1
	bne _0205DFBE
	add r0, r5, #0
	add r1, r7, #0
	bl sub_0205DE88
	cmp r0, #1
	bne _0205DFBE
	mov r4, #0x58
_0205DFBE:
	ldr r0, [sp]
	add r1, r4, #0
	bl sub_0206234C
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0205DF0C

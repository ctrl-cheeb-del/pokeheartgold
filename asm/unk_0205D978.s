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
	thumb_func_start sub_0205D978
sub_0205D978: ; 0x0205D978
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r7, r1, #0
	bl sub_0205D6B4
	str r0, [sp]
	add r0, r5, #0
	bl PlayerAvatar_GetNextFacingDirection
	add r6, r0, #0
	add r0, r5, #0
	add r1, r7, #0
	add r2, r6, #0
	bl sub_0205DA34
	add r4, r0, #0
	mov r0, #4
	tst r0, r4
	beq _0205D9AC
	add r0, r6, #0
	mov r1, #0x38
	bl sub_0206234C
	str r0, [sp, #4]
	b _0205D9FE
_0205D9AC:
	mov r0, #0x40
	tst r0, r4
	beq _0205D9C4
	add r0, r6, #0
	mov r1, #0
	bl sub_0206234C
	str r0, [sp, #4]
	add r0, r5, #0
	bl PlayerAvatar_ClearUnk24ClearFlag2
	b _0205D9FE
_0205D9C4:
	cmp r4, #0
	beq _0205D9F4
	mov r0, #0
	str r0, [sp]
	add r0, r6, #0
	mov r1, #0x1c
	bl sub_0206234C
	str r0, [sp, #4]
	mov r0, #8
	tst r0, r4
	bne _0205D9E4
	mov r0, #SEQ_SE_DP_WALL_HIT>>8
	lsl r0, r0, #8
	bl PlaySE
_0205D9E4:
	add r0, r7, #0
	add r1, r6, #0
	bl MapObject_SetNextFacingDirection
	add r0, r5, #0
	bl PlayerAvatar_ClearUnk24ClearFlag2
	b _0205D9FE
_0205D9F4:
	add r0, r5, #0
	add r1, r6, #0
	bl sub_0205D658
	str r0, [sp, #4]
_0205D9FE:
	ldr r0, [sp]
	cmp r0, #0
	bne _0205DA0C
	add r0, r5, #0
	mov r1, #0
	bl PlayerAvatar_SetFlag2
_0205DA0C:
	ldr r2, [sp, #4]
	add r0, r5, #0
	add r1, r7, #0
	bl sub_0205DA1C
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0205D978

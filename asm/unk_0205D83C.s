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
	thumb_func_start sub_0205D83C
sub_0205D83C: ; 0x0205D83C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r1, #0
	add r6, r2, #0
	bl sub_0205DA34
	add r4, r0, #0
	mov r0, #4
	tst r0, r4
	beq _0205D86E
	add r0, r6, #0
	mov r1, #0x38
	bl sub_0206234C
	str r0, [sp]
	add r0, r5, #0
	bl sub_0205D684
	add r0, r5, #0
	bl sub_0205E048
	add r0, r5, #0
	bl PlayerAvatar_SetFlag6
	b _0205D93A
_0205D86E:
	mov r0, #0x10
	tst r0, r4
	beq _0205D8C0
	add r0, r5, #0
	bl PlayerAvatar_GetUnk24
	cmp r0, #3
	blt _0205D898
	add r0, r5, #0
	add r1, r6, #0
	bl sub_0205D658
	str r0, [sp]
	add r0, r5, #0
	bl PlayerAvatar_SetFlag6
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetForcedMovement
	b _0205D93A
_0205D898:
	add r0, r6, #0
	mov r1, #0x1c
	bl sub_0206234C
	str r0, [sp]
	mov r0, #8
	tst r0, r4
	bne _0205D8B0
	mov r0, #SEQ_SE_DP_WALL_HIT>>8
	lsl r0, r0, #8
	bl PlaySE
_0205D8B0:
	add r0, r7, #0
	add r1, r6, #0
	bl MapObject_SetNextFacingDirection
	add r0, r5, #0
	bl PlayerAvatar_ClearUnk24ClearFlag2
	b _0205D93A
_0205D8C0:
	mov r0, #0x40
	tst r0, r4
	beq _0205D8F2
	add r0, r7, #0
	bl MapObject_GetNextFacingDirection
	add r4, r0, #0
	mov r1, #0
	bl sub_0206234C
	str r0, [sp]
	add r0, r7, #0
	add r1, r4, #0
	bl MapObject_SetNextFacingDirection
	add r0, r5, #0
	bl PlayerAvatar_ClearUnk24ClearFlag2
	mov r1, #0
	mvn r1, r1
	add r0, r5, #0
	add r2, r1, #0
	bl PlayerAvatar_SetUnk28Unk2C
	b _0205D93A
_0205D8F2:
	cmp r4, #0
	beq _0205D91E
	add r0, r6, #0
	mov r1, #0x1c
	bl sub_0206234C
	str r0, [sp]
	mov r0, #8
	tst r0, r4
	bne _0205D90E
	mov r0, #SEQ_SE_DP_WALL_HIT>>8
	lsl r0, r0, #8
	bl PlaySE
_0205D90E:
	add r0, r7, #0
	add r1, r6, #0
	bl MapObject_SetNextFacingDirection
	add r0, r5, #0
	bl PlayerAvatar_ClearUnk24ClearFlag2
	b _0205D93A
_0205D91E:
	add r0, r5, #0
	add r1, r6, #0
	bl sub_0205D658
	str r0, [sp]
	add r0, r5, #0
	bl sub_0205D684
	add r0, r5, #0
	bl sub_0205E048
	add r0, r5, #0
	bl PlayerAvatar_SetFlag6
_0205D93A:
	ldr r2, [sp]
	add r0, r5, #0
	add r1, r7, #0
	bl sub_0205DA1C
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0205D83C

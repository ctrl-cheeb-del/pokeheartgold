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
	.include "unk_020632B0.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020642C4
sub_020642C4: ; 0x020642C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r4, r1, #0
	str r2, [sp, #8]
	bl sub_02064298
	cmp r0, #1
	bne _02064332
	add r0, r4, #0
	bl PlayerAvatar_GetXCoord
	add r7, r0, #0
	add r0, r4, #0
	bl PlayerAvatar_GetZCoord
	add r6, r0, #0
	add r0, r5, #0
	bl MapObject_GetFacingDirection
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl MapObject_GetParam
	add r2, r0, #0
	str r6, [sp]
	mov r0, #0
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, r4, #0
	add r3, r7, #0
	bl sub_0206439C
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _0206432A
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl sub_02064468
	cmp r0, #0
	bne _0206432A
	ldr r0, [sp, #8]
	add sp, #0x14
	str r4, [r0]
	add r0, r6, #0
	pop {r4, r5, r6, r7, pc}
_0206432A:
	mov r0, #0
	add sp, #0x14
	mvn r0, r0
	pop {r4, r5, r6, r7, pc}
_02064332:
	cmp r0, #2
	bne _02064394
	add r0, r4, #0
	bl PlayerAvatar_GetXCoord
	str r0, [sp, #0x10]
	add r0, r4, #0
	bl PlayerAvatar_GetZCoord
	add r7, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl MapObject_GetParam
	str r0, [sp, #0xc]
	mov r4, #0
_02064352:
	str r7, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r2, [sp, #0xc]
	ldr r3, [sp, #0x10]
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0206439C
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _02064386
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl sub_02064468
	cmp r0, #0
	bne _02064386
	ldr r0, [sp, #8]
	add sp, #0x14
	str r4, [r0]
	add r0, r6, #0
	pop {r4, r5, r6, r7, pc}
_02064386:
	add r4, r4, #1
	cmp r4, #4
	blt _02064352
	mov r0, #0
	add sp, #0x14
	mvn r0, r0
	pop {r4, r5, r6, r7, pc}
_02064394:
	mov r0, #0
	mvn r0, r0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_020642C4

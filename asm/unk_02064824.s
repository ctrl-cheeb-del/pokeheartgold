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
	thumb_func_start sub_02064824
sub_02064824: ; 0x02064824
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x28]
	bl PlayerAvatar_GetMapObject
	add r4, r0, #0
	bl MapObject_GetXCoord
	add r6, r0, #0
	add r0, r4, #0
	bl MapObject_GetZCoord
	add r7, r0, #0
	ldr r0, [r5, #0x24]
	bl MapObject_GetXCoord
	str r0, [sp]
	ldr r0, [r5, #0x24]
	bl MapObject_GetZCoord
	add r3, r0, #0
	ldr r2, [sp]
	add r0, r6, #0
	add r1, r7, #0
	bl sub_02061200
	add r6, r0, #0
	ldr r0, [r5, #0x28]
	bl PlayerAvatar_GetFacingDirection
	cmp r6, r0
	beq _02064898
	ldr r0, [r5, #0x18]
	cmp r0, #0
	beq _02064870
	ldr r0, [r5, #0x14]
	cmp r0, #2
	bne _02064898
_02064870:
	add r0, r4, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _0206489C
	add r0, r4, #0
	mov r1, #0x80
	bl MapObject_ClearFlagsBits
	add r0, r6, #0
	mov r1, #0
	bl sub_0206234C
	add r1, r0, #0
	add r0, r4, #0
	bl MapObject_SetHeldMovement
	mov r0, #0xf
	str r0, [r5]
	b _0206489C
_02064898:
	mov r0, #0x10
	str r0, [r5]
_0206489C:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02064824

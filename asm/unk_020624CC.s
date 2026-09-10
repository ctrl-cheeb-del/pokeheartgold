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
	.include "unk_02062108.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020624CC
sub_020624CC: ; 0x020624CC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	mov r1, #0xc
	add r5, r0, #0
	add r6, r2, #0
	add r7, r3, #0
	bl sub_0205F3C0
	add r1, sp, #8
	ldrh r1, [r1, #0x10]
	strh r1, [r0]
	strh r7, [r0, #2]
	str r4, [r0, #4]
	str r6, [r0, #8]
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060F24
	add r0, r5, #0
	add r1, r4, #0
	bl MapObject_SetOrQueueFacing
	add r1, sp, #8
	ldrh r1, [r1, #0x10]
	add r0, r5, #0
	bl sub_0205F328
	add r0, r5, #0
	mov r1, #4
	bl MapObject_SetFlagsBits
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020624CC
	thumb_func_start MapObjectMovementCmd090_Step1
MapObjectMovementCmd090_Step1: ; 0x02062514
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl sub_0205F3E4
	add r4, r0, #0
	ldr r1, [r4, #4]
	ldr r2, [r4, #8]
	add r0, r5, #0
	bl sub_0206101C
	add r0, r5, #0
	bl sub_02061070
	mov r0, #2
	ldrsh r1, [r4, r0]
	sub r1, r1, #1
	strh r1, [r4, #2]
	ldrsh r0, [r4, r0]
	cmp r0, #0
	ble _02062540
	mov r0, #0
	pop {r3, r4, r5, pc}
_02062540:
	add r0, r5, #0
	mov r1, #0x28
	bl MapObject_SetFlagsBits
	add r0, r5, #0
	bl sub_02060F78
	add r0, r5, #0
	bl sub_0205F484
	add r0, r5, #0
	mov r1, #0
	bl sub_0205F328
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end MapObjectMovementCmd090_Step1

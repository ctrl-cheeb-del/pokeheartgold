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
	thumb_func_start sub_02062F48
sub_02062F48: ; 0x02062F48
	push {r4, r5, r6, lr}
	add r6, r1, #0
	mov r1, #8
	add r5, r0, #0
	bl sub_0205F3C0
	add r4, r0, #0
	str r6, [r4]
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #1
	bl ov01_02200540
	str r0, [r4, #4]
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02062F48
	thumb_func_start MapObjectMovementCmd075_Step1
MapObjectMovementCmd075_Step1: ; 0x02062F6C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl sub_0205F3E4
	add r4, r0, #0
	ldr r0, [r4, #4]
	bl ov01_022003F4
	cmp r0, #1
	bne _02062F90
	ldr r0, [r4, #4]
	bl sub_02068B48
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	pop {r3, r4, r5, pc}
_02062F90:
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end MapObjectMovementCmd075_Step1
	thumb_func_start MapObjectMovementCmd075_Step0
MapObjectMovementCmd075_Step0: ; 0x02062F94
	push {r3, lr}
	mov r1, #0
	bl sub_02062F48
	mov r0, #0
	pop {r3, pc}
	thumb_func_end MapObjectMovementCmd075_Step0
	thumb_func_start MapObjectMovementCmd103_Step0
MapObjectMovementCmd103_Step0: ; 0x02062FA0
	push {r3, lr}
	mov r1, #1
	bl sub_02062F48
	mov r0, #0
	pop {r3, pc}
	thumb_func_end MapObjectMovementCmd103_Step0
	thumb_func_start sub_02062FAC
sub_02062FAC: ; 0x02062FAC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	mov r1, #8
	add r5, r0, #0
	add r7, r2, #0
	add r6, r3, #0
	bl sub_0205F3C0
	strh r4, [r0]
	strh r6, [r0, #2]
	strh r7, [r0, #4]
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02060F24
	add r0, r5, #0
	add r1, r4, #0
	bl MapObject_SetOrQueueFacing
	add r0, r5, #0
	add r1, r6, #0
	bl sub_0205F328
	add r0, r5, #0
	mov r1, #4
	bl MapObject_SetFlagsBits
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02062FAC
	thumb_func_start sub_02062FEC
sub_02062FEC: ; 0x02062FEC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	bl sub_0205F3E4
	add r4, r0, #0
	mov r2, #6
	ldrsh r2, [r4, r2]
	mov r1, #0
	ldrsh r1, [r4, r1]
	lsl r2, r2, #2
	ldr r2, [r6, r2]
	add r0, r5, #0
	bl sub_0206101C
	add r0, r5, #0
	bl sub_02061070
	mov r0, #6
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, #6]
	ldrsh r1, [r4, r0]
	mov r0, #4
	ldrsh r0, [r4, r0]
	cmp r1, r0
	bge _02063026
	mov r0, #0
	pop {r4, r5, r6, pc}
_02063026:
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
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02062FEC

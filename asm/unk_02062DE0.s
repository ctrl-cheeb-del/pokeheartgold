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
	thumb_func_start MapObjectMovementCmd067_Step0
MapObjectMovementCmd067_Step0: ; 0x02062DE0
	push {r4, lr}
	mov r1, #8
	add r4, r0, #0
	bl sub_0205F3C0
	mov r1, #1
	lsl r1, r1, #0x10
	str r1, [r0, #4]
	add r0, r4, #0
	mov r1, #0
	bl sub_0205F328
	add r0, r4, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end MapObjectMovementCmd067_Step0
	thumb_func_start MapObjectMovementCmd067_Step1
MapObjectMovementCmd067_Step1: ; 0x02062E04
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	bl sub_0205F3E4
	add r4, r0, #0
	ldr r1, [r4]
	ldr r0, [r4, #4]
	add r0, r1, r0
	str r0, [r4]
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [r4]
	str r0, [sp, #4]
	add r0, r5, #0
	bl MapObject_SetFacingVector
	ldr r1, [r4]
	asr r0, r1, #0xe
	lsr r0, r0, #0x11
	add r0, r1, r0
	asr r0, r0, #0xf
	cmp r0, #0x28
	bge _02062E40
	add sp, #0xc
	mov r0, #0
	pop {r4, r5, pc}
_02062E40:
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end MapObjectMovementCmd067_Step1
	thumb_func_start MapObjectMovementCmd068_Step0
MapObjectMovementCmd068_Step0: ; 0x02062E4C
	push {r4, lr}
	mov r1, #8
	add r4, r0, #0
	bl sub_0205F3C0
	mov r1, #5
	lsl r1, r1, #0x12
	str r1, [r0]
	ldr r1, _02062E74 ; =0xFFFF0000
	str r1, [r0, #4]
	add r0, r4, #0
	mov r1, #0
	bl sub_0205F328
	add r0, r4, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	pop {r4, pc}
	nop
_02062E74: .word 0xFFFF0000
	thumb_func_end MapObjectMovementCmd068_Step0
	thumb_func_start MapObjectMovementCmd068_Step1
MapObjectMovementCmd068_Step1: ; 0x02062E78
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	bl sub_0205F3E4
	add r4, r0, #0
	ldr r1, [r4]
	ldr r0, [r4, #4]
	add r0, r1, r0
	str r0, [r4]
	bpl _02062E92
	mov r0, #0
	str r0, [r4]
_02062E92:
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [r4]
	str r0, [sp, #4]
	add r0, r5, #0
	bl MapObject_SetFacingVector
	ldr r0, [r4]
	cmp r0, #0
	ble _02062EB2
	add sp, #0xc
	mov r0, #0
	pop {r4, r5, pc}
_02062EB2:
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end MapObjectMovementCmd068_Step1

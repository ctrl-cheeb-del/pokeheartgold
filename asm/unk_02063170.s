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
	thumb_func_start MapObjectMovementCmd100_Step1
MapObjectMovementCmd100_Step1: ; 0x02063170
	push {r4, lr}
	add r4, r0, #0
	bl sub_0205F3E4
	ldr r1, [r0]
	add r1, r1, #1
	str r1, [r0]
	cmp r1, #8
	blt _02063198
	add r0, r4, #0
	mov r1, #1
	bl MapObject_SetFacingDirection
	add r0, r4, #0
	mov r1, #0
	bl sub_0205F328
	add r0, r4, #0
	bl MapObject_IncrementMovementStep
_02063198:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end MapObjectMovementCmd100_Step1
	thumb_func_start MapObjectMovementCmd101_Step0
MapObjectMovementCmd101_Step0: ; 0x0206319C
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	mov r1, #4
	bl sub_0205F3C0
	add r0, r4, #0
	bl sub_0206642C
	cmp r0, #0
	beq _020631B6
	bl sub_02068B48
_020631B6:
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r0, r4, #0
	bl MapObject_SetFacingVector
	add r0, r4, #0
	bl ov01_022000DC
	ldr r1, _020631EC ; =0x00010004
	add r0, r4, #0
	bl MapObject_SetFlagsBits
	mov r1, #1
	add r0, r4, #0
	lsl r1, r1, #0x14
	bl MapObject_ClearFlagsBits
	add r0, r4, #0
	bl MapObject_IncrementMovementStep
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	nop
_020631EC: .word 0x00010004
	thumb_func_end MapObjectMovementCmd101_Step0
	thumb_func_start MapObjectMovementCmd101_Step1
MapObjectMovementCmd101_Step1: ; 0x020631F0
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	bl sub_0205F3E4
	add r4, r0, #0
	ldr r0, _02063250 ; =_0210FACC
	add r1, sp, #0
	ldr r2, [r0]
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	ldr r0, [r4]
	lsl r0, r0, #2
	ldr r0, [r2, r0]
	str r0, [sp, #4]
	add r0, r5, #0
	bl MapObject_SetFacingVector
	ldr r0, [r4]
	add r0, r0, #2
	str r0, [r4]
	cmp r0, #0x10
	bhs _02063228
	add sp, #0xc
	mov r0, #0
	pop {r4, r5, pc}
_02063228:
	mov r0, #0
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, sp, #0
	bl MapObject_SetFacingVector
	ldr r1, _02063254 ; =0x00020028
	add r0, r5, #0
	bl MapObject_SetFlagsBits
	add r0, r5, #0
	bl sub_02066438
	add r0, r5, #0
	bl MapObject_IncrementMovementStep
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_02063250: .word _0210FACC
_02063254: .word 0x00020028
	thumb_func_end MapObjectMovementCmd101_Step1

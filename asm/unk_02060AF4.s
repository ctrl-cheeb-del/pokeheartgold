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
	.include "unk_0205FD20.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02060AF4
sub_02060AF4: ; 0x02060AF4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r7, [sp, #0x28]
	add r5, r2, #0
	str r1, [sp, #4]
	str r3, [sp, #8]
	add r2, r3, #0
	add r1, r5, #0
	add r3, r7, #0
	add r6, r0, #0
	mov r4, #0
	bl sub_02060D94
	cmp r0, #1
	bne _02060B16
	mov r0, #1
	orr r4, r0
_02060B16:
	add r0, r6, #0
	bl MapObject_GetFieldSystem
	add r1, sp, #0xc
	str r1, [sp]
	ldr r1, [sp, #4]
	add r2, r5, #0
	add r3, r7, #0
	bl sub_020549A8
	cmp r0, #1
	bne _02060B40
	mov r0, #2
	orr r4, r0
	add r1, sp, #0xc
	mov r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _02060B40
	mov r0, #8
	orr r4, r0
_02060B40:
	ldr r3, [sp, #0x2c]
	add r0, r6, #0
	add r1, r5, #0
	add r2, r7, #0
	bl sub_02060DEC
	cmp r0, #1
	bne _02060B54
	mov r0, #2
	orr r4, r0
_02060B54:
	bl sub_0203993C
	bl sub_0203401C
	cmp r0, #0
	beq _02060B76
	ldr r2, [sp, #8]
	add r0, r6, #0
	add r1, r5, #0
	add r3, r7, #0
	bl sub_02060BFC
	cmp r0, #1
	bne _02060B8A
	mov r0, #4
	orr r4, r0
	b _02060B8A
_02060B76:
	ldr r2, [sp, #8]
	add r0, r6, #0
	add r1, r5, #0
	add r3, r7, #0
	bl sub_02060CA8
	cmp r0, #1
	bne _02060B8A
	mov r0, #4
	orr r4, r0
_02060B8A:
	add r0, r4, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02060AF4

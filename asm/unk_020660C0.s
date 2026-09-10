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
	.include "unk_020658D4.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020660C0
sub_020660C0: ; 0x020660C0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov r1, #0
	add r4, r0, #0
	str r1, [sp, #8]
	bl MapObject_GetType
	str r0, [sp]
	add r0, r4, #0
	bl MapObject_GetMapID
	add r6, r0, #0
	add r0, r4, #0
	bl sub_02064518
	add r5, r0, #0
	add r0, r4, #0
	bl MapObject_GetManager
	ldr r1, [sp]
	add r7, r0, #0
	cmp r1, #8
	bhi _02066148
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_020660FA: ; jump table
	.short _02066148 - _020660FA - 2 ; case 0
	.short _0206610C - _020660FA - 2 ; case 1
	.short _0206610C - _020660FA - 2 ; case 2
	.short _0206610C - _020660FA - 2 ; case 3
	.short _0206610C - _020660FA - 2 ; case 4
	.short _0206610C - _020660FA - 2 ; case 5
	.short _0206610C - _020660FA - 2 ; case 6
	.short _0206610C - _020660FA - 2 ; case 7
	.short _0206610C - _020660FA - 2 ; case 8
_0206610C:
	add r1, sp, #4
	add r2, sp, #8
	mov r3, #1
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	bne _02066148
_0206611A:
	ldr r0, [sp, #4]
	cmp r4, r0
	beq _02066138
	bl MapObject_GetMapID
	cmp r6, r0
	bne _02066138
	ldr r0, [sp, #4]
	bl sub_02064518
	cmp r5, r0
	bne _02066138
	ldr r0, [sp, #4]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_02066138:
	add r0, r7, #0
	add r1, sp, #4
	add r2, sp, #8
	mov r3, #1
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	beq _0206611A
_02066148:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020660C0
	thumb_func_start sub_02066150
sub_02066150: ; 0x02066150
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	str r1, [sp]
	bl MapObject_GetManager
	add r4, r0, #0
	mov r0, #0
	str r0, [sp, #8]
	add r0, r5, #0
	bl MapObject_GetMapID
	add r7, r0, #0
	add r0, r5, #0
	bl sub_02064518
	add r6, r0, #0
	add r0, r4, #0
	add r1, sp, #4
	add r2, sp, #8
	mov r3, #1
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	bne _020661C2
_02066182:
	ldr r0, [sp, #4]
	cmp r5, r0
	beq _020661B2
	bl MapObject_GetMapID
	cmp r7, r0
	bne _020661B2
	ldr r0, [sp, #4]
	bl sub_02064518
	cmp r6, r0
	bne _020661B2
	ldr r0, [sp]
	ldrb r0, [r0, #1]
	cmp r0, #0
	bne _020661AC
	ldr r1, [sp]
	ldr r2, [sp, #4]
	add r0, r5, #0
	bl sub_020661CC
_020661AC:
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_020661B2:
	add r0, r4, #0
	add r1, sp, #4
	add r2, sp, #8
	mov r3, #1
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #1
	beq _02066182
_020661C2:
	ldr r1, [sp]
	mov r0, #0
	strb r0, [r1, #1]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_02066150

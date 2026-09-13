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
	.public sub_02062958
	thumb_func_start MapObjectMovementCmd092_Step1
MapObjectMovementCmd092_Step1: ; 0x020629CC
	push {r3, r4, r5, lr}
	sub sp, #0x18
	add r5, r0, #0
	bl sub_0205F3E4
	add r4, r0, #0
	ldr r2, [r4]
	cmp r2, #0
	beq _02062A1C
	mov r1, #0xc
	ldrsb r1, [r4, r1]
	add r0, r5, #0
	bl sub_0206101C
	add r0, r5, #0
	bl sub_02061070
	mov r0, #1
	ldr r1, [r4, #4]
	lsl r0, r0, #0x10
	cmp r1, r0
	blt _02062A0E
	mov r0, #0
	str r0, [r4, #4]
	mov r1, #0xc
	ldrsb r1, [r4, r1]
	add r0, r5, #0
	bl sub_02060F24
	add r0, r5, #0
	mov r1, #4
	bl MapObject_SetFlagsBits
_02062A0E:
	ldr r1, [r4]
	cmp r1, #0
	bge _02062A16
	neg r1, r1
_02062A16:
	ldr r0, [r4, #4]
	add r0, r0, r1
	str r0, [r4, #4]
_02062A1C:
	ldrh r1, [r4, #0xa]
	ldrh r0, [r4, #8]
	add r0, r1, r0
	strh r0, [r4, #0xa]
	mov r0, #0xf
	ldrh r1, [r4, #0xa]
	lsl r0, r0, #8
	cmp r1, r0
	bls _02062A30
	strh r0, [r4, #0xa]
_02062A30:
	mov r1, #0xf
	ldrsb r1, [r4, r1]
	ldrh r0, [r4, #0xa]
	lsl r2, r1, #2
	ldr r1, _02062AB0 ; =_0210FACC
	lsr r0, r0, #8
	lsl r0, r0, #0x10
	ldr r2, [r1, r2]
	mov r1, #0
	str r1, [sp, #0xc]
	lsr r0, r0, #0xe
	ldr r0, [r2, r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r0, r5, #0
	add r1, sp, #0xc
	bl MapObject_SetFacingVector
	mov r0, #0xd
	ldrsb r1, [r4, r0]
	sub r1, r1, #1
	strb r1, [r4, #0xd]
	ldrsb r0, [r4, r0]
	cmp r0, #0
	ble _02062A68
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, pc}
_02062A68:
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	add r0, r5, #0
	bl MapObject_SetFacingVector
	ldr r1, _02062AB4 ; =0x00020028
	add r0, r5, #0
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
	add r0, r5, #0
	bl MapObject_CheckVisible
	cmp r0, #0
	bne _02062AAA
	ldr r0, _02062AB8 ; =SEQ_SE_DP_SUTYA2
	bl PlaySE
_02062AAA:
	mov r0, #1
	add sp, #0x18
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02062AB0: .word _0210FACC
_02062AB4: .word 0x00020028
_02062AB8: .word SEQ_SE_DP_SUTYA2
	thumb_func_end MapObjectMovementCmd092_Step1

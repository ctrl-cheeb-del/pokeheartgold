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

	thumb_func_start PlayerAvatar_MoveControl
PlayerAvatar_MoveControl: ; 0x0205CB48
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	mov r1, #0
	add r4, r2, #0
	mvn r1, r1
	add r5, r0, #0
	add r6, r3, #0
	cmp r4, r1
	bne _0205CB66
	add r2, sp, #8
	ldrh r2, [r2, #0x10]
	add r1, r6, #0
	bl sub_0205DDD4
	add r4, r0, #0
_0205CB66:
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0205CBEC
	cmp r0, #0
	beq _0205CBE2
	add r3, sp, #8
	ldrh r3, [r3, #0x10]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl sub_0205CC4C
	add r0, r5, #0
	bl Field_PlayerAvatar_ApplyTransitionFlags
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0205D004
	cmp r0, #1
	bne _0205CB9A
	add r0, r5, #0
	bl ov01_021F2F24
	pop {r3, r4, r5, r6, r7, pc}
_0205CB9A:
	add r0, r5, #0
	bl PlayerAvatar_GetState
	cmp r0, #0
	bne _0205CBC4
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0205D40C
	cmp r0, #0
	beq _0205CBB8
	add r0, r5, #0
	bl ov01_021F2F24
	b _0205CBC4
_0205CBB8:
	ldr r0, [sp, #0x1c]
	cmp r0, #1
	bne _0205CBC4
	add r0, r5, #0
	bl ov01_021F2EDC
_0205CBC4:
	add r0, sp, #8
	ldrh r0, [r0, #0x10]
	add r1, r7, #0
	add r2, r4, #0
	str r0, [sp]
	add r0, r5, #0
	add r3, r6, #0
	bl sub_0205D340
	add r0, r5, #0
	bl sub_0205CC74
	add r0, r5, #0
	bl sub_0205CC94
_0205CBE2:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end PlayerAvatar_MoveControl
	thumb_func_start sub_0205CBE4
sub_0205CBE4: ; 0x0205CBE4
	ldr r3, _0205CBE8 ; =sub_0205CBEC
	bx r3
	.balign 4, 0
_0205CBE8: .word sub_0205CBEC
	thumb_func_end sub_0205CBE4
	thumb_func_start sub_0205CBEC
sub_0205CBEC: ; 0x0205CBEC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl PlayerAvatar_GetMapObject
	add r6, r0, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _0205CC04
	mov r0, #1
	pop {r4, r5, r6, pc}
_0205CC04:
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _0205CC10
	mov r0, #0
	pop {r4, r5, r6, pc}
_0205CC10:
	add r0, r6, #0
	bl MapObject_GetMovementCommand
	bl sub_0205DE64
	cmp r0, #1
	bne _0205CC46
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	bl sub_0205DA34
	cmp r0, #0
	bne _0205CC30
	mov r0, #1
	pop {r4, r5, r6, pc}
_0205CC30:
	cmp r0, #0x20
	bne _0205CC42
	add r0, r5, #0
	bl PlayerAvatar_GetState
	cmp r0, #2
	bne _0205CC42
	mov r0, #1
	pop {r4, r5, r6, pc}
_0205CC42:
	mov r0, #0
	pop {r4, r5, r6, pc}
_0205CC46:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_0205CBEC

	.rodata

	.public _020FCB7C
_020FCB7C:
	.word sub_0205D09C
	.word sub_0205D0A8
	.word sub_0205D190
	.public _020FCB88
_020FCB88:
	.word MetatileBehavior_IsIce, 1
	.word 0, 3
	.public _020FCB98
_020FCB98:
	.short SEQ_SE_GS_ASHIOTO_A_WALK, 0
	.short SEQ_SE_GS_ASHIOTO_A, 0
	.short SEQ_SE_GS_OCHIBA, 0
	.short SEQ_SE_GS_EDAPAKI, 0
	.short SEQ_SE_GS_KUSA2, 0
	.short SEQ_SE_GS_ASHIOTO_B, 1
	.short SEQ_SE_GS_ASHIOTO_D, 1
	.short SEQ_SE_GS_ASHIOTO_D_2, 0
	.short SEQ_SE_GS_ASHIOTO_E, 0
	.short SEQ_SE_GS_ASHIOTO_B, 1
	.short SEQ_SE_GS_ASHIOTO_F, 1
	.short SEQ_SE_GS_ASHIOTO_D, 0
	.short SEQ_SE_GS_ASHIOTO_H, 0
	.short SEQ_SE_GS_ASHIOTO_G, 0
	.short SEQ_SE_DP_BOX02, 0
	.short SEQ_SE_DP_BOX01, 0

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

	thumb_func_start sub_0205FEDC
sub_0205FEDC: ; 0x0205FEDC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl sub_02061108
	add r0, r5, #0
	bl sub_0205F73C
	cmp r0, #1
	bne _0205FF6A
	add r0, r5, #0
	bl sub_0205F504
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r5, #0
	bl sub_0205F514
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r5, #0
	bl ov01_021F9318
	add r7, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060AB8
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020601BC
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_0206039C
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020603DC
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020601A4
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060698
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060700
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020607D8
_0205FF6A:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0205FEDC
	thumb_func_start sub_0205FF6C
sub_0205FF6C: ; 0x0205FF6C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl sub_02061108
	add r0, r5, #0
	bl sub_0205F73C
	cmp r0, #1
	bne _0206001E
	add r0, r5, #0
	bl sub_0205F504
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r5, #0
	bl sub_0205F514
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r5, #0
	bl ov01_021F9318
	add r7, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060AB8
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060274
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060328
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_0206039C
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020603F8
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020606CC
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060704
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060708
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060770
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020607D8
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060AF0
_0206001E:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0205FF6C

	.rodata

	; File boundary
	.public _020FD49C
_020FD49C:
	.word -1
	.word  1
	.word  0
	.word  0
	.public _020FD4AC
_020FD4AC:
	.word  0
	.word  0
	.word -1
	.word  1
	.public _020FD4BC
_020FD4BC:
	.word sub_0205B918
	.word sub_0205B8F4
	.word sub_0205B960
	.word sub_0205B93C
	.public _020FD4CC
_020FD4CC:
	.word sub_0205B8F4
	.word sub_0205B918
	.word sub_0205B93C
	.word sub_0205B960
	.public _020FD4DC
_020FD4DC:
	.word 1
	.word 0
	.word 3
	.word 2

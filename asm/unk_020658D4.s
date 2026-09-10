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

	thumb_func_start sub_02065900
sub_02065900: ; 0x02065900
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl sub_0205F394
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02065CD0
	cmp r0, #0
	beq _02065930
	add r0, r5, #0
	mov r1, #0
	bl MapObject_ClearFlag18
	ldr r6, _02065934 ; =_020FE404
_02065920:
	ldrb r2, [r4]
	add r0, r5, #0
	add r1, r4, #0
	lsl r2, r2, #2
	ldr r2, [r6, r2]
	blx r2
	cmp r0, #1
	beq _02065920
_02065930:
	pop {r4, r5, r6, pc}
	nop
_02065934: .word _020FE404
	thumb_func_end sub_02065900
	thumb_func_start sub_02065938
sub_02065938: ; 0x02065938
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl sub_0205F394
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02065CD0
	cmp r0, #0
	beq _02065960
	ldr r6, _02065964 ; =_020FE414
_02065950:
	ldrb r2, [r4]
	add r0, r5, #0
	add r1, r4, #0
	lsl r2, r2, #2
	ldr r2, [r6, r2]
	blx r2
	cmp r0, #1
	beq _02065950
_02065960:
	pop {r4, r5, r6, pc}
	nop
_02065964: .word _020FE414
	thumb_func_end sub_02065938
	thumb_func_start sub_02065968
sub_02065968: ; 0x02065968
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl sub_0205F394
	add r4, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02065CD0
	cmp r0, #0
	beq _02065990
	ldr r6, _02065994 ; =_020FE424
_02065980:
	ldrb r2, [r4]
	add r0, r5, #0
	add r1, r4, #0
	lsl r2, r2, #2
	ldr r2, [r6, r2]
	blx r2
	cmp r0, #1
	beq _02065980
_02065990:
	pop {r4, r5, r6, pc}
	nop
_02065994: .word _020FE424
	thumb_func_end sub_02065968

	.rodata

	.public _020FE3CC
_020FE3CC:
	.word sub_020663B4
	.word sub_020663E4
	.public _020FE3D4
_020FE3D4:
	.word sub_02066064
	.word sub_020660A0
	.public _020FE3DC
_020FE3DC:
	.word 0, -0x20000, 0 ; VecFx32
	.public _020FE3E8
_020FE3E8:
	.word 0, -0x20000, 0 ; VecFx32
	.public _020FE3F4
_020FE3F4:
	.word 12, 13, 14, 15
	.public _020FE404
_020FE404:
	.word sub_02065A4C
	.word sub_02065C2C
	.word sub_02065C48
	.word sub_02065C90
	.public _020FE414
_020FE414:
	.word sub_02065B70
	.word sub_02065C2C
	.word sub_02065C48
	.word sub_02065C90
	.public _020FE424
_020FE424:
	.word sub_02065BE8
	.word sub_02065C2C
	.word sub_02065C48
	.word sub_02065C90
	.public _020FE434
_020FE434:
	.word 16, 17, 18, 19
	.public _020FE444
_020FE444:
	.word 20, 21, 22, 23

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
	thumb_func_start sub_02066370
sub_02066370: ; 0x02066370
	push {r4, r5, lr}
	sub sp, #0xc
	add r4, r0, #0
	bl sub_0205F394
	add r5, r0, #0
	mov r1, #0
	strb r1, [r5]
	add r0, r4, #0
	bl sub_02066420
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _020663AC
	ldr r5, _020663B0 ; =_020FE3E8
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	add r1, r2, #0
	str r0, [r3]
	add r0, r4, #0
	bl MapObject_SetFacingVector
	mov r1, #1
	add r0, r4, #0
	lsl r1, r1, #0x14
	bl MapObject_SetFlagsBits
_020663AC:
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_020663B0: .word _020FE3E8
	thumb_func_end sub_02066370

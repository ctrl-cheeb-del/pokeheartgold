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
	.include "unk_020632B0.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02063A14
sub_02063A14: ; 0x02063A14
	ldr r3, _02063A18 ; =sub_02063A40
	bx r3
	.balign 4, 0
_02063A18: .word sub_02063A40
	thumb_func_end sub_02063A14
	thumb_func_start sub_02063A1C
sub_02063A1C: ; 0x02063A1C
	push {r4, lr}
	add r4, r0, #0
	bl sub_02063A5C
	cmp r0, #0
	bne _02063A2C
	mov r0, #0
	pop {r4, pc}
_02063A2C:
	add r0, r4, #0
	bl sub_02063A78
	cmp r0, #0
	beq _02063A3A
	mov r0, #1
	pop {r4, pc}
_02063A3A:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02063A1C
	thumb_func_start sub_02063A40
sub_02063A40: ; 0x02063A40
	push {r4, lr}
	add r4, r0, #0
	bl MapObject_GetType
	add r1, r0, #0
	lsl r2, r1, #2
	ldr r1, _02063A58 ; =_020FE104
	add r0, r4, #0
	ldr r1, [r1, r2]
	blx r1
	pop {r4, pc}
	nop
_02063A58: .word _020FE104
	thumb_func_end sub_02063A40
	thumb_func_start sub_02063A5C
sub_02063A5C: ; 0x02063A5C
	push {r4, lr}
	add r4, r0, #0
	bl MapObject_GetType
	add r1, r0, #0
	lsl r2, r1, #2
	ldr r1, _02063A74 ; =_020FE134
	add r0, r4, #0
	ldr r1, [r1, r2]
	blx r1
	pop {r4, pc}
	nop
_02063A74: .word _020FE134
	thumb_func_end sub_02063A5C
	thumb_func_start sub_02063A78
sub_02063A78: ; 0x02063A78
	push {r4, lr}
	add r4, r0, #0
	bl MapObject_GetType
	add r1, r0, #0
	lsl r2, r1, #2
	ldr r1, _02063A90 ; =_020FE164
	add r0, r4, #0
	ldr r1, [r1, r2]
	blx r1
	pop {r4, pc}
	nop
_02063A90: .word _020FE164
	thumb_func_end sub_02063A78

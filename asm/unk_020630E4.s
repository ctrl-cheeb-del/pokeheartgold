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
	thumb_func_start MapObjectMovementCmd082_Step1
MapObjectMovementCmd082_Step1: ; 0x020630E4
	push {r3, lr}
	ldr r1, _020630F8 ; =_020FDA1C
	bl sub_02062FEC
	cmp r0, #1
	bne _020630F4
	mov r0, #1
	pop {r3, pc}
_020630F4:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_020630F8: .word _020FDA1C
	thumb_func_end MapObjectMovementCmd082_Step1

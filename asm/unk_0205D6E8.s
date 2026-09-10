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
	thumb_func_start sub_0205D6E8
sub_0205D6E8: ; 0x0205D6E8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r1, #0
	add r1, r3, #0
	add r6, r0, #0
	str r3, [sp, #4]
	ldr r5, [sp, #0x20]
	ldr r4, [sp, #0x24]
	bl sub_0205D75C
	cmp r0, #3
	bhi _0205D758
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0205D70C: ; jump table
	.short _0205D714 - _0205D70C - 2 ; case 0
	.short _0205D726 - _0205D70C - 2 ; case 1
	.short _0205D738 - _0205D70C - 2 ; case 2
	.short _0205D74A - _0205D70C - 2 ; case 3
_0205D714:
	ldr r2, [sp, #4]
	add r0, r6, #0
	add r1, r7, #0
	add r3, r5, #0
	str r4, [sp]
	bl sub_0205D818
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_0205D726:
	ldr r2, [sp, #4]
	add r0, r6, #0
	add r1, r7, #0
	add r3, r5, #0
	str r4, [sp]
	bl sub_0205D83C
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_0205D738:
	ldr r2, [sp, #4]
	add r0, r6, #0
	add r1, r7, #0
	add r3, r5, #0
	str r4, [sp]
	bl sub_0205D948
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_0205D74A:
	ldr r2, [sp, #4]
	add r0, r6, #0
	add r1, r7, #0
	add r3, r5, #0
	str r4, [sp]
	bl sub_0205D978
_0205D758:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0205D6E8

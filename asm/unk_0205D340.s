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
	thumb_func_start sub_0205D340
sub_0205D340: ; 0x0205D340
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r0, #0
	add r7, r1, #0
	str r2, [sp, #8]
	add r4, r3, #0
	bl PlayerAvatar_GetState
	add r5, r0, #0
	add r0, r6, #0
	bl PlayerAvatar_GetMapObject
	add r1, r0, #0
	cmp r5, #3
	bhi _0205D39E
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0205D36A: ; jump table
	.short _0205D372 - _0205D36A - 2 ; case 0
	.short _0205D388 - _0205D36A - 2 ; case 1
	.short _0205D372 - _0205D36A - 2 ; case 2
	.short _0205D372 - _0205D36A - 2 ; case 3
_0205D372:
	str r4, [sp]
	add r0, sp, #0x10
	ldrh r0, [r0, #0x10]
	ldr r3, [sp, #8]
	add r2, r7, #0
	str r0, [sp, #4]
	add r0, r6, #0
	bl sub_0205D3A8
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0205D388:
	str r4, [sp]
	add r0, sp, #0x10
	ldrh r0, [r0, #0x10]
	ldr r3, [sp, #8]
	add r2, r7, #0
	str r0, [sp, #4]
	add r0, r6, #0
	bl sub_0205D640
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_0205D39E:
	bl GF_AssertFail
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0205D340
	thumb_func_start sub_0205D3A8
sub_0205D3A8: ; 0x0205D3A8
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r6, r3, #0
	add r4, r1, #0
	add r1, r6, #0
	add r5, r0, #0
	bl sub_0205D40C
	cmp r0, #0
	beq _0205D3C8
	cmp r0, #1
	beq _0205D3DE
	cmp r0, #2
	beq _0205D3F4
	add sp, #4
	pop {r3, r4, r5, r6, pc}
_0205D3C8:
	add r3, sp, #8
	ldrh r0, [r3, #0x14]
	add r1, r4, #0
	add r2, r6, #0
	str r0, [sp]
	ldrh r3, [r3, #0x10]
	add r0, r5, #0
	bl sub_0205D494
	add sp, #4
	pop {r3, r4, r5, r6, pc}
_0205D3DE:
	add r3, sp, #8
	ldrh r0, [r3, #0x14]
	add r1, r4, #0
	add r2, r6, #0
	str r0, [sp]
	ldrh r3, [r3, #0x10]
	add r0, r5, #0
	bl sub_0205D4B4
	add sp, #4
	pop {r3, r4, r5, r6, pc}
_0205D3F4:
	add r3, sp, #8
	ldrh r0, [r3, #0x14]
	add r1, r4, #0
	add r2, r6, #0
	str r0, [sp]
	ldrh r3, [r3, #0x10]
	add r0, r5, #0
	bl sub_0205D610
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_0205D3A8

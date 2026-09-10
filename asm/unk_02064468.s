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
	thumb_func_start sub_02064468
sub_02064468: ; 0x02064468
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r1, #0
	str r0, [sp, #4]
	str r2, [sp, #8]
	cmp r2, #0
	bne _0206447C
	add sp, #0x18
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0206447C:
	bl MapObject_GetXCoord
	add r4, r0, #0
	ldr r0, [sp, #4]
	bl MapObject_GetZCoord
	add r7, r0, #0
	ldr r0, [sp, #4]
	bl MapObject_GetYCoord
	str r0, [sp, #0xc]
	add r0, r5, #0
	bl GetDeltaXByFacingDirection
	add r6, r4, r0
	add r0, r5, #0
	bl GetDeltaYByFacingDirection
	add r4, r7, r0
	ldr r0, [sp, #8]
	mov r7, #0
	sub r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #0
	ble _020644E4
	mov r0, #1
	str r0, [sp, #0x14]
_020644B2:
	ldr r0, [sp, #4]
	ldr r2, [sp, #0xc]
	add r1, r6, #0
	add r3, r4, #0
	str r5, [sp]
	bl sub_02060B90
	ldr r1, [sp, #0x14]
	bic r0, r1
	beq _020644CC
	add sp, #0x18
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_020644CC:
	add r0, r5, #0
	bl GetDeltaXByFacingDirection
	add r6, r6, r0
	add r0, r5, #0
	bl GetDeltaYByFacingDirection
	add r4, r4, r0
	ldr r0, [sp, #0x10]
	add r7, r7, #1
	cmp r7, r0
	blt _020644B2
_020644E4:
	ldr r0, [sp, #4]
	ldr r2, [sp, #0xc]
	add r1, r6, #0
	add r3, r4, #0
	str r5, [sp]
	bl sub_02060B90
	mov r1, #1
	bic r0, r1
	cmp r0, #4
	bne _02064500
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02064500:
	mov r0, #1
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02064468

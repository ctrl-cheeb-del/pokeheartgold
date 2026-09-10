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
	.include "unk_02066EDC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0206759C
sub_0206759C: ; 0x0206759C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	str r1, [sp]
	cmp r1, #0
	ble _02067606
	bl Save_TrainerCard_Get
	bl TrainerCard_GetBadgeShininessArr
	add r4, r0, #0
	add r0, r5, #0
	bl Save_PlayerData_GetProfile
	add r7, r0, #0
	ldr r0, [sp]
	mov r1, #0xa
	add r6, r0, #0
	mov r5, #0
	mul r6, r1
_020675C2:
	add r0, r7, #0
	add r1, r5, #0
	bl PlayerProfile_TestBadgeFlag
	cmp r0, #0
	beq _020675FC
	add r0, r5, #0
	add r1, r4, #0
	bl GetShininessOfBadgeI
	add r1, r0, #0
	cmp r1, #0
	ble _020675E4
	cmp r1, #0xc8
	bge _020675E4
	sub r1, r1, r6
	b _020675EE
_020675E4:
	cmp r1, #0xc8
	blt _020675EC
	bl GF_AssertFail
_020675EC:
	mov r1, #0
_020675EE:
	cmp r1, #0
	bge _020675F4
	mov r1, #0
_020675F4:
	add r0, r5, #0
	add r2, r4, #0
	bl SetShininessOfBadgeI
_020675FC:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #8
	blo _020675C2
_02067606:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0206759C

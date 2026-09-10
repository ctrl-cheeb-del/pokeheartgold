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
	thumb_func_start sub_0205D4B4
sub_0205D4B4: ; 0x0205D4B4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	mov r3, #0
	add r6, r0, #0
	add r5, r1, #0
	add r7, r2, #0
	str r3, [sp, #4]
	bl sub_0205DA34
	add r4, r0, #0
	add r0, r6, #0
	bl PlayerAvatar_GetState
	cmp r0, #2
	beq _0205D588
	mov r0, #4
	tst r0, r4
	beq _0205D4DE
	mov r0, #0x38
	str r0, [sp]
	b _0205D5CE
_0205D4DE:
	cmp r4, #0
	beq _0205D544
	mov r0, #0x1c
	str r0, [sp]
	mov r0, #8
	tst r0, r4
	bne _0205D536
	add r0, r5, #0
	bl MapObject_GetFieldSystem
	mov r1, #7
	str r0, [sp, #8]
	bl FieldSystem_IsSaveGymmickTypeEqualTo
	cmp r0, #0
	beq _0205D52E
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r4, r0, #0
	add r0, r7, #0
	bl GetDeltaXByFacingDirection
	str r0, [sp, #0xc]
	add r0, r5, #0
	bl MapObject_GetZCoord
	str r0, [sp, #0x10]
	add r0, r7, #0
	bl GetDeltaYByFacingDirection
	ldr r1, [sp, #0xc]
	add r2, r0, #0
	ldr r3, [sp, #0x10]
	ldr r0, [sp, #8]
	add r1, r4, r1
	add r2, r3, r2
	bl ov04_022566EC
	b _0205D536
_0205D52E:
	mov r0, #SEQ_SE_DP_WALL_HIT>>8
	lsl r0, r0, #8
	bl PlaySE
_0205D536:
	add r0, r5, #0
	add r1, r7, #0
	bl MapObject_SetNextFacingDirection
	mov r0, #1
	str r0, [sp, #4]
	b _0205D5CE
_0205D544:
	add r0, r6, #0
	mov r4, #0xc
	bl PlayerAvatar_GetPlayerSaveData
	bl PlayerSaveData_CheckRunningShoes
	cmp r0, #1
	bne _0205D564
	add r1, sp, #0x18
	ldrh r1, [r1, #0x10]
	add r0, r6, #0
	bl sub_0205DE88
	cmp r0, #1
	bne _0205D564
	mov r4, #0x58
_0205D564:
	add r0, r5, #0
	bl sub_0205F504
	add r1, r0, #0
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r2, r4, #0
	bl sub_0205D44C
	str r0, [sp]
	add r0, r6, #0
	bl sub_0205E048
	add r0, r6, #0
	bl PlayerAvatar_SetFlag6
	b _0205D5CE
_0205D588:
	cmp r4, #0
	beq _0205D590
	cmp r4, #0x20
	bne _0205D5B4
_0205D590:
	add r0, r5, #0
	bl sub_0205F504
	add r1, r0, #0
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #0x10
	bl sub_0205D44C
	str r0, [sp]
	add r0, r6, #0
	bl sub_0205E048
	add r0, r6, #0
	bl PlayerAvatar_SetFlag6
	b _0205D5CE
_0205D5B4:
	mov r0, #0x1c
	str r0, [sp]
	mov r0, #8
	tst r0, r4
	bne _0205D5C6
	mov r0, #SEQ_SE_DP_WALL_HIT>>8
	lsl r0, r0, #8
	bl PlaySE
_0205D5C6:
	add r0, r5, #0
	add r1, r7, #0
	bl MapObject_SetNextFacingDirection
_0205D5CE:
	ldr r1, [sp]
	add r0, r7, #0
	bl sub_0206234C
	add r7, r0, #0
	add r0, r6, #0
	add r1, r5, #0
	add r2, r7, #0
	bl sub_0205DA1C
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0205D60C
	add r0, r5, #0
	bl MapObject_GetFieldSystem
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_GetPreviousXCoord
	add r6, r0, #0
	add r0, r5, #0
	bl MapObject_GetPreviousZCoord
	add r4, #0xe4
	add r2, r0, #0
	add r0, r7, #0
	add r1, r6, #0
	add r3, r4, #0
	bl ov01_02205990
_0205D60C:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_0205D4B4

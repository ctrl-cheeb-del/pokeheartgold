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
	thumb_func_start sub_02065DF4
sub_02065DF4: ; 0x02065DF4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r4, r1, #0
	bl MapObject_GetFieldSystem
	bl FieldSystem_GetPlayerAvatar
	add r7, r0, #0
	add r0, r5, #0
	bl MapObject_GetXCoord
	str r0, [sp, #8]
	add r0, r5, #0
	bl MapObject_GetZCoord
	str r0, [sp, #4]
	add r0, r7, #0
	bl PlayerAvatar_GetPreviousXCoord
	str r0, [sp]
	add r0, r7, #0
	bl PlayerAvatar_GetPreviousZCoord
	add r6, r0, #0
	ldr r1, [sp, #8]
	ldr r0, [sp]
	cmp r1, r0
	bne _02065E36
	ldr r0, [sp, #4]
	cmp r0, r6
	bne _02065E36
	b _02065F3C
_02065E36:
	add r0, r5, #0
	bl sub_02065D78
	str r0, [sp, #0x10]
	ldr r0, [sp, #8]
	ldr r1, [sp, #4]
	ldr r2, [sp]
	add r3, r6, #0
	bl sub_02061200
	str r0, [sp, #0x14]
	add r0, r5, #0
	bl sub_02069EC0
	add r6, r0, #0
	ldr r0, [sp, #0x10]
	bl sub_020623C8
	mov r1, #1
	str r1, [sp, #0xc]
	cmp r6, #0
	beq _02065F00
	cmp r0, #0
	beq _02065EB4
	add r0, r6, #0
	bl sub_020623D8
	add r1, r0, #0
	add r0, r6, #0
	bl ov01_0220542C
	add r6, r0, #0
	bl sub_02066444
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	lsl r0, r0, #0x1e
	ldrh r1, [r4, #0xa]
	mov r2, #6
	lsr r0, r0, #0x1d
	bic r1, r2
	orr r0, r1
	lsl r1, r6, #0x18
	strh r0, [r4, #0xa]
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl sub_02069E50
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	add r0, r7, #0
	bl PlayerAvatar_GetFacingDirection
	add r1, r0, #0
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl sub_02069E28
	b _02065F2A
_02065EB4:
	add r0, r7, #0
	bl PlayerAvatar_CheckFlag6
	cmp r0, #0
	bne _02065EC4
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02065EC4:
	ldr r1, [sp, #0x10]
	add r0, r6, #0
	bl ov01_0220542C
	add r6, r0, #0
	bl sub_02066444
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	lsl r0, r0, #0x1e
	ldrh r1, [r4, #0xa]
	mov r2, #6
	lsr r0, r0, #0x1d
	bic r1, r2
	orr r0, r1
	lsl r1, r6, #0x18
	strh r0, [r4, #0xa]
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl sub_02069E50
	mov r0, #2
	str r0, [sp, #0xc]
	mov r1, #0
	strb r1, [r4, #2]
	add r0, r5, #0
	strb r1, [r4, #3]
	bl sub_02069E28
	b _02065F2A
_02065F00:
	cmp r0, #0
	beq _02065F20
	ldr r0, [sp, #0x14]
	bl sub_020623D8
	add r6, r0, #0
	add r0, r7, #0
	bl PlayerAvatar_GetFacingDirection
	add r1, r0, #0
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl sub_02069E28
	b _02065F2A
_02065F20:
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x10]
	bl sub_0206234C
	add r6, r0, #0
_02065F2A:
	add r0, r5, #0
	add r1, r6, #0
	bl MapObject_ForceSetHeldMovement
	ldr r0, [sp, #0xc]
	add sp, #0x18
	strb r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02065F3C:
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02065DF4
	thumb_func_start sub_02065F44
sub_02065F44: ; 0x02065F44
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	bl MapObject_GetFieldSystem
	bl FieldSystem_GetPlayerAvatar
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_GetXCoord
	str r0, [sp]
	add r0, r5, #0
	bl MapObject_GetZCoord
	add r7, r0, #0
	add r0, r4, #0
	bl PlayerAvatar_GetPreviousXCoord
	add r6, r0, #0
	add r0, r4, #0
	bl PlayerAvatar_GetPreviousZCoord
	add r4, r0, #0
	ldr r0, [sp]
	cmp r0, r6
	bne _02065F7E
	cmp r7, r4
	beq _02065FB4
_02065F7E:
	add r0, r5, #0
	bl sub_02065DB4
	str r0, [sp, #4]
	ldr r0, [sp]
	add r1, r7, #0
	add r2, r6, #0
	add r3, r4, #0
	bl sub_02061200
	ldr r1, [sp, #4]
	cmp r1, #0xff
	bne _02065FA2
	bl GF_AssertFail
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02065FA2:
	bl sub_0206234C
	add r1, r0, #0
	add r0, r5, #0
	bl MapObject_ForceSetHeldMovement
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02065FB4:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02065F44
	thumb_func_start sub_02065FBC
sub_02065FBC: ; 0x02065FBC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl MapObject_GetFieldSystem
	bl FieldSystem_GetPlayerAvatar
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r0, r5, #0
	bl MapObject_GetZCoord
	add r0, r4, #0
	bl PlayerAvatar_GetPreviousXCoord
	add r0, r4, #0
	bl PlayerAvatar_GetPreviousZCoord
	add r0, r5, #0
	bl sub_02065DB4
	add r1, r0, #0
	cmp r1, #0xff
	bne _02065FF2
	mov r0, #0
	pop {r3, r4, r5, pc}
_02065FF2:
	add r0, r5, #0
	bl MapObject_ForceSetHeldMovement
	mov r0, #1
	pop {r3, r4, r5, pc}
	thumb_func_end sub_02065FBC

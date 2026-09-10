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
	thumb_func_start sub_020659CC
sub_020659CC: ; 0x020659CC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl MapObject_GetFieldSystem
	add r4, r0, #0
	add r0, r5, #0
	bl sub_0205F394
	add r6, r0, #0
	add r0, r5, #0
	bl MapObject_ClearSingleMovement
	add r0, r5, #0
	bl MapObject_ClearEndMovement
	add r0, r5, #0
	mov r1, #0x20
	bl MapObject_ClearFlagsBits
	add r0, r5, #0
	mov r1, #0xff
	bl MapObject_SetMovementCommand
	add r0, r5, #0
	mov r1, #0
	bl MapObject_SetMovementStep
	mov r1, #0
	add r0, r4, #0
	strb r1, [r6]
	add r0, #0xe8 ; ->followMon.effectTimer
	str r1, [r0]
	mov r0, #1
	lsl r0, r0, #8 ; ->followMon.fieldSystem
	str r1, [r4, r0]
	add r0, r4, #0
	add r0, #0xec ; ->followMon.duration
	str r1, [r0]
	add r4, #0xf0 ; ->followMon.parentData
	add r0, r5, #0
	str r1, [r4]
	bl MapObject_GetXCoord
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_GetYCoord
	add r6, r0, #0
	add r0, r5, #0
	bl MapObject_GetZCoord
	add r7, r0, #0
	add r0, r5, #0
	bl MapObject_GetFacingDirection
	str r0, [sp]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	add r3, r7, #0
	bl MapObject_SetPositionFromXYZAndDirection
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020659CC
	thumb_func_start sub_02065A4C
sub_02065A4C: ; 0x02065A4C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	bl MapObject_GetFieldSystem
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_ClearSingleMovement
	add r0, r5, #0
	bl MapObject_ClearEndMovement
	mov r0, #1
	lsl r0, r0, #8
	ldr r1, [r4, r0]
	cmp r1, #1
	bne _02065A76
	mov r1, #2
	str r1, [r4, r0]
	mov r0, #0
	pop {r4, r5, r6, pc}
_02065A76:
	cmp r1, #2
	bne _02065B64
	add r0, r5, #0
	add r1, r6, #0
	bl sub_02065D58
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r1, r4, #0
	add r1, #0xec
	ldr r1, [r1]
	cmp r1, r0
	bne _02065B12
	add r0, r5, #0
	bl MapObject_GetZCoord
	add r1, r4, #0
	add r1, #0xf0
	ldr r1, [r1]
	cmp r1, r0
	bne _02065B12
	mov r0, #1
	mov r1, #0
	lsl r0, r0, #8
	str r1, [r4, r0]
	mov r0, #3
	strb r0, [r6]
	add r0, r5, #0
	bl sub_02069E14
	cmp r0, #0
	beq _02065AEA
	ldrh r0, [r6, #0xa]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	bne _02065AEA
	add r0, r5, #0
	bl sub_02069EAC
	cmp r0, #0
	beq _02065ADC
	add r0, r5, #0
	mov r1, #0
	bl ov01_0220329C
	add r0, r5, #0
	mov r1, #0
	bl sub_02069E84
	b _02065AE4
_02065ADC:
	add r0, r5, #0
	mov r1, #0
	bl sub_02069DC8
_02065AE4:
	add r0, r5, #0
	bl sub_020664D8
_02065AEA:
	add r0, r5, #0
	bl sub_02065D78
	bl sub_020623C8
	cmp r0, #0
	beq _02065B0E
	add r0, r4, #0
	bl FieldSystem_GetPlayerAvatar
	bl PlayerAvatar_GetFacingDirection
	add r1, r0, #0
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl sub_02069E28
_02065B0E:
	mov r0, #1
	pop {r4, r5, r6, pc}
_02065B12:
	add r0, r5, #0
	add r1, r6, #0
	bl sub_02065DF4
	cmp r0, #1
	bne _02065B6C
	add r0, r5, #0
	bl sub_02069E14
	cmp r0, #0
	beq _02065B52
	add r0, r5, #0
	bl sub_02069EAC
	cmp r0, #0
	beq _02065B44
	add r0, r5, #0
	mov r1, #0
	bl ov01_0220329C
	add r0, r5, #0
	mov r1, #0
	bl sub_02069E84
	b _02065B4C
_02065B44:
	add r0, r5, #0
	mov r1, #0
	bl sub_02069DC8
_02065B4C:
	add r0, r5, #0
	bl sub_020664D8
_02065B52:
	add r0, r5, #0
	bl MapObject_SetSingleMovement
	mov r1, #3
	add r0, r1, #0
	add r0, #0xfd
	str r1, [r4, r0]
	mov r0, #1
	pop {r4, r5, r6, pc}
_02065B64:
	cmp r1, #3
	bne _02065B6C
	mov r1, #0
	str r1, [r4, r0]
_02065B6C:
	mov r0, #0
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02065A4C
	thumb_func_start sub_02065B70
sub_02065B70: ; 0x02065B70
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl MapObject_ClearSingleMovement
	add r0, r5, #0
	bl MapObject_ClearEndMovement
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02065D24
	cmp r0, #1
	bne _02065BE2
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02065D58
	add r0, r5, #0
	bl sub_02069E14
	cmp r0, #0
	beq _02065BC8
	add r0, r5, #0
	bl sub_02069EAC
	cmp r0, #0
	beq _02065BBA
	add r0, r5, #0
	mov r1, #0
	bl ov01_0220329C
	add r0, r5, #0
	mov r1, #0
	bl sub_02069E84
	b _02065BC2
_02065BBA:
	add r0, r5, #0
	mov r1, #0
	bl sub_02069DC8
_02065BC2:
	add r0, r5, #0
	bl sub_020664D8
_02065BC8:
	add r0, r5, #0
	bl sub_02065F44
	cmp r0, #1
	bne _02065BE2
	add r0, r5, #0
	bl MapObject_SetSingleMovement
	ldrb r0, [r4]
	add r0, r0, #1
	strb r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, pc}
_02065BE2:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_02065B70

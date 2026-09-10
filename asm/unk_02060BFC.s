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
	.include "unk_0205FD20.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02060BFC
sub_02060BFC: ; 0x02060BFC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	add r4, r1, #0
	add r6, r2, #0
	add r7, r3, #0
	bl MapObject_GetManager
	add r5, r0, #0
	bl MapObjectManager_GetObjects2
	str r0, [sp, #8]
	add r0, r5, #0
	bl MapObjectManager_GetObjectCount
	str r0, [sp, #4]
_02060C1C:
	ldr r0, [sp, #8]
	ldr r1, [sp]
	cmp r0, r1
	beq _02060C94
	mov r1, #1
	bl MapObject_GetFlagsBitsMask
	cmp r0, #0
	beq _02060C94
	mov r1, #1
	ldr r0, [sp, #8]
	lsl r1, r1, #0x12
	bl MapObject_GetFlagsBitsMask
	cmp r0, #0
	bne _02060C94
	ldr r0, [sp, #8]
	bl MapObject_GetXCoord
	add r5, r0, #0
	ldr r0, [sp, #8]
	bl MapObject_GetZCoord
	cmp r5, r4
	bne _02060C68
	cmp r0, r7
	bne _02060C68
	ldr r0, [sp, #8]
	bl MapObject_GetYCoord
	sub r0, r0, r6
	bpl _02060C5E
	neg r0, r0
_02060C5E:
	cmp r0, #2
	bge _02060C68
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02060C68:
	ldr r0, [sp, #8]
	bl MapObject_GetPreviousXCoord
	add r5, r0, #0
	ldr r0, [sp, #8]
	bl MapObject_GetPreviousZCoord
	cmp r5, r4
	bne _02060C94
	cmp r0, r7
	bne _02060C94
	ldr r0, [sp, #8]
	bl MapObject_GetYCoord
	sub r0, r0, r6
	bpl _02060C8A
	neg r0, r0
_02060C8A:
	cmp r0, #2
	bge _02060C94
	add sp, #0xc
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02060C94:
	add r0, sp, #8
	bl MapObjectArray_NextObject
	ldr r0, [sp, #4]
	sub r0, r0, #1
	str r0, [sp, #4]
	bne _02060C1C
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_02060BFC
	thumb_func_start sub_02060CA8
sub_02060CA8: ; 0x02060CA8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	add r5, r1, #0
	add r4, r2, #0
	add r6, r3, #0
	bl MapObject_GetManager
	add r7, r0, #0
	bl MapObjectManager_GetObjects2
	str r0, [sp, #4]
	add r0, r7, #0
	bl MapObjectManager_GetObjectCount
	add r7, r0, #0
_02060CC8:
	ldr r0, [sp, #4]
	ldr r1, [sp]
	cmp r0, r1
	beq _02060D84
	mov r1, #1
	bl MapObject_GetFlagsBitsMask
	cmp r0, #0
	beq _02060D84
	ldr r0, [sp, #4]
	bl MapObject_GetXCoord
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	bl MapObject_GetZCoord
	ldr r1, [sp, #0xc]
	str r0, [sp, #8]
	cmp r1, r5
	bne _02060D0A
	cmp r0, r6
	bne _02060D0A
	ldr r0, [sp, #4]
	bl MapObject_GetYCoord
	sub r0, r0, r4
	bpl _02060D00
	neg r0, r0
_02060D00:
	cmp r0, #2
	bge _02060D0A
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02060D0A:
	ldr r0, [sp, #4]
	bl MapObject_GetPreviousXCoord
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	bl MapObject_GetPreviousZCoord
	ldr r1, [sp, #0xc]
	str r0, [sp, #8]
	cmp r1, r5
	bne _02060D3A
	cmp r0, r6
	bne _02060D3A
	ldr r0, [sp, #4]
	bl MapObject_GetYCoord
	sub r0, r0, r4
	bpl _02060D30
	neg r0, r0
_02060D30:
	cmp r0, #2
	bge _02060D3A
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02060D3A:
	ldr r0, [sp, #4]
	bl MapObject_GetID
	cmp r0, #0xfd
	bne _02060D84
	ldr r0, [sp, #4]
	bl ov01_022055DC
	cmp r0, #0
	beq _02060D84
	ldr r0, [sp, #4]
	bl MapObject_CheckVisible
	cmp r0, #0
	bne _02060D84
	ldr r0, [sp, #4]
	add r1, sp, #0xc
	add r2, sp, #8
	bl ov01_02205664
	ldr r0, [sp, #0xc]
	cmp r0, r5
	bne _02060D84
	ldr r0, [sp, #8]
	cmp r0, r6
	bne _02060D84
	ldr r0, [sp, #4]
	bl MapObject_GetYCoord
	sub r0, r0, r4
	bpl _02060D7A
	neg r0, r0
_02060D7A:
	cmp r0, #2
	bge _02060D84
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02060D84:
	add r0, sp, #4
	bl MapObjectArray_NextObject
	sub r7, r7, #1
	bne _02060CC8
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02060CA8
	thumb_func_start sub_02060D94
sub_02060D94: ; 0x02060D94
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r5, r1, #0
	add r4, r3, #0
	bl MapObject_GetInitialX
	add r7, r0, #0
	add r0, r6, #0
	bl MapObject_GetXRange
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _02060DC0
	add r1, r7, r0
	sub r0, r7, r0
	cmp r0, r5
	bgt _02060DBC
	cmp r1, r5
	bge _02060DC0
_02060DBC:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02060DC0:
	add r0, r6, #0
	bl MapObject_GetInitialZ
	add r5, r0, #0
	add r0, r6, #0
	bl MapObject_GetYRange
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _02060DE6
	add r1, r5, r0
	sub r0, r5, r0
	cmp r0, r4
	bgt _02060DE2
	cmp r1, r4
	bge _02060DE6
_02060DE2:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02060DE6:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02060D94
	thumb_func_start sub_02060DEC
sub_02060DEC: ; 0x02060DEC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	add r5, r3, #0
	bl sub_0205F8D0
	cmp r0, #0
	bne _02060E46
	add r0, r4, #0
	bl MapObject_GetFieldSystem
	str r0, [sp]
	add r0, r4, #0
	bl sub_0205F504
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, [sp]
	add r1, r6, #0
	add r2, r7, #0
	bl GetMetatileBehavior
	add r6, r0, #0
	bl GetMetatileBehavior_None
	cmp r6, r0
	bne _02060E28
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02060E28:
	ldr r1, _02060E4C ; =_020FD4CC
	lsl r5, r5, #2
	ldr r1, [r1, r5]
	add r0, r4, #0
	blx r1
	cmp r0, #1
	beq _02060E42
	ldr r1, _02060E50 ; =_020FD4BC
	add r0, r6, #0
	ldr r1, [r1, r5]
	blx r1
	cmp r0, #1
	bne _02060E46
_02060E42:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02060E46:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02060E4C: .word _020FD4CC
_02060E50: .word _020FD4BC
	thumb_func_end sub_02060DEC

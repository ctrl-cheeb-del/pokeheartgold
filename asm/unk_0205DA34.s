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
	thumb_func_start sub_0205DA34
sub_0205DA34: ; 0x0205DA34
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	mov r4, #0
	bl sub_0205DAA8
	mov r1, #0xa
	str r0, [sp]
	tst r0, r1
	beq _0205DA60
	mov r0, #1
	orr r4, r0
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	bl sub_0205DBF4
	cmp r0, #0
	beq _0205DA60
	mov r0, #8
	orr r4, r0
_0205DA60:
	ldr r0, [sp]
	mov r1, #4
	tst r0, r1
	beq _0205DA6C
	mov r0, #2
	orr r4, r0
_0205DA6C:
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	bl sub_0205DB68
	cmp r0, #0
	beq _0205DA7E
	mov r0, #4
	orr r4, r0
_0205DA7E:
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	bl sub_0205DCA0
	cmp r0, #1
	bne _0205DA90
	mov r0, #0x20
	orr r4, r0
_0205DA90:
	add r0, r5, #0
	add r1, r6, #0
	add r2, r7, #0
	bl sub_0205DCFC
	cmp r0, #1
	bne _0205DAA2
	mov r0, #1
	orr r4, r0
_0205DAA2:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0205DA34
	thumb_func_start sub_0205DAA8
sub_0205DAA8: ; 0x0205DAA8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r1, #0
	str r2, [sp, #4]
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r7, r0, #0
	ldr r0, [sp, #4]
	bl GetDeltaXByFacingDirection
	str r0, [sp, #0x14]
	add r0, r5, #0
	bl MapObject_GetYCoord
	str r0, [sp, #8]
	add r0, r5, #0
	bl MapObject_GetZCoord
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	bl GetDeltaYByFacingDirection
	str r0, [sp, #0x10]
	add r0, r5, #0
	add r1, sp, #0x1c
	bl MapObject_CopyPositionVector
	ldr r1, [sp, #0x14]
	ldr r6, [sp, #0xc]
	ldr r3, [sp, #0x10]
	ldr r2, [sp, #8]
	add r0, r5, #0
	add r1, r7, r1
	add r3, r6, r3
	mov r4, #0
	bl sub_02060D94
	cmp r0, #1
	bne _0205DAFC
	mov r0, #1
	orr r4, r0
_0205DAFC:
	add r0, r5, #0
	bl MapObject_GetFieldSystem
	ldr r2, [sp, #0x14]
	add r1, sp, #0x18
	str r1, [sp]
	ldr r6, [sp, #0xc]
	ldr r3, [sp, #0x10]
	add r1, sp, #0x1c
	add r2, r7, r2
	add r3, r6, r3
	bl sub_020549F4
	cmp r0, #1
	bne _0205DB2C
	mov r0, #2
	orr r4, r0
	add r1, sp, #0x18
	mov r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _0205DB2C
	mov r0, #8
	orr r4, r0
_0205DB2C:
	ldr r3, [sp, #0xc]
	ldr r2, [sp, #0x10]
	ldr r1, [sp, #0x14]
	add r2, r3, r2
	ldr r3, [sp, #4]
	add r0, r5, #0
	add r1, r7, r1
	bl sub_02060DEC
	cmp r0, #1
	bne _0205DB46
	mov r0, #2
	orr r4, r0
_0205DB46:
	add r0, r5, #0
	ldr r1, [sp, #0x14]
	ldr r5, [sp, #0xc]
	ldr r3, [sp, #0x10]
	ldr r2, [sp, #8]
	add r1, r7, r1
	add r3, r5, r3
	bl sub_02060BFC
	cmp r0, #1
	bne _0205DB60
	mov r0, #4
	orr r4, r0
_0205DB60:
	add r0, r4, #0
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0205DAA8
	thumb_func_start sub_0205DB68
sub_0205DB68: ; 0x0205DB68
	push {r3, r4, r5, r6, r7, lr}
	mov r0, #0
	add r4, r2, #0
	mvn r0, r0
	add r5, r1, #0
	cmp r4, r0
	beq _0205DBF0
	add r0, r5, #0
	bl MapObject_GetFieldSystem
	str r0, [sp]
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r6, r0, #0
	add r0, r4, #0
	bl GetDeltaXByFacingDirection
	add r7, r0, #0
	add r0, r5, #0
	bl MapObject_GetZCoord
	add r5, r0, #0
	add r0, r4, #0
	bl GetDeltaYByFacingDirection
	add r2, r0, #0
	ldr r0, [sp]
	add r1, r6, r7
	add r2, r5, r2
	bl GetMetatileBehavior
	cmp r4, #3
	bhi _0205DBF0
	add r1, r4, r4
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0205DBB8: ; jump table
	.short _0205DBC0 - _0205DBB8 - 2 ; case 0
	.short _0205DBCC - _0205DBB8 - 2 ; case 1
	.short _0205DBD8 - _0205DBB8 - 2 ; case 2
	.short _0205DBE4 - _0205DBB8 - 2 ; case 3
_0205DBC0:
	bl MetatileBehavior_IsJumpNorth
	cmp r0, #1
	bne _0205DBF0
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DBCC:
	bl MetatileBehavior_IsJumpSouth
	cmp r0, #1
	bne _0205DBF0
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DBD8:
	bl MetatileBehavior_IsJumpWest
	cmp r0, #1
	bne _0205DBF0
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DBE4:
	bl MetatileBehavior_IsJumpEast
	cmp r0, #1
	bne _0205DBF0
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DBF0:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0205DB68
	thumb_func_start sub_0205DBF4
sub_0205DBF4: ; 0x0205DBF4
	push {r3, r4, r5, r6, r7, lr}
	mov r0, #0
	add r4, r2, #0
	mvn r0, r0
	add r5, r1, #0
	cmp r4, r0
	beq _0205DC9C
	add r0, r5, #0
	bl MapObject_GetFieldSystem
	add r7, r0, #0
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r6, r0, #0
	add r0, r5, #0
	bl MapObject_GetZCoord
	str r0, [sp]
	ldr r2, [sp]
	add r0, r7, #0
	add r1, r6, #0
	bl GetMetatileBehavior
	add r5, r0, #0
	cmp r4, #3
	bhi _0205DC74
	add r1, r4, r4
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0205DC36: ; jump table
	.short _0205DC3E - _0205DC36 - 2 ; case 0
	.short _0205DC4A - _0205DC36 - 2 ; case 1
	.short _0205DC58 - _0205DC36 - 2 ; case 2
	.short _0205DC66 - _0205DC36 - 2 ; case 3
_0205DC3E:
	bl MetatileBehavior_IsWarpEntranceNorth
	cmp r0, #1
	bne _0205DC4A
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DC4A:
	add r0, r5, #0
	bl MetatileBehavior_IsWarpEntranceSouth
	cmp r0, #1
	bne _0205DC58
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DC58:
	add r0, r5, #0
	bl MetatileBehavior_IsWarpEntranceWest
	cmp r0, #1
	bne _0205DC66
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DC66:
	add r0, r5, #0
	bl MetatileBehavior_IsWarpEntranceEast
	cmp r0, #1
	bne _0205DC74
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DC74:
	add r0, r4, #0
	bl GetDeltaXByFacingDirection
	add r5, r0, #0
	add r0, r4, #0
	bl GetDeltaYByFacingDirection
	add r3, r0, #0
	ldr r2, [sp]
	add r0, r7, #0
	add r1, r6, r5
	add r2, r2, r3
	bl GetMetatileBehavior
	bl MetatileBehavior_IsDoor
	cmp r0, #1
	bne _0205DC9C
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0205DC9C:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0205DBF4

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
	thumb_func_start sub_0205CC94
sub_0205CC94: ; 0x0205CC94
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl PlayerAvatar_GetMoveState
	cmp r0, #1
	bne _0205CD5E
	add r0, r6, #0
	bl PlayerAvatar_GetMapObject
	add r4, r0, #0
	bl sub_0205F504
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	add r0, r4, #0
	bl MapObject_GetMovementCommand
	bl sub_02062390
	add r1, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	bne _0205CCC8
	add r7, r5, #0
	b _0205CCD2
_0205CCC8:
	add r0, r4, #0
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
_0205CCD2:
	add r0, r5, #0
	bl MetatileBehavior_IsPuddle
	cmp r0, #1
	bne _0205CCE4
	mov r0, #SEQ_SE_DP_FOOT3_0>>6
	lsl r0, r0, #6
	bl PlaySE
_0205CCE4:
	add r0, r5, #0
	bl MetatileBehavior_IsShallowWater
	cmp r0, #1
	bne _0205CCF4
	ldr r0, _0205CD60 ; =SEQ_SE_DP_FOOT3_1
	bl PlaySE
_0205CCF4:
	add r0, r5, #0
	bl MetatileBehavior_IsSand
	add r0, r5, #0
	bl MetatileBehavior_IsMud
	cmp r0, #1
	bne _0205CD0A
	ldr r0, _0205CD64 ; =SEQ_SE_DP_MARSH_WALK
	bl PlaySE
_0205CD0A:
	add r0, r4, #0
	bl MapObject_GetMovementCommand
	str r0, [sp]
	add r0, r6, #0
	bl PlayerAvatar_GetState
	ldr r0, [sp]
	bl sub_0205DE64
	cmp r0, #0
	bne _0205CD56
	add r0, r5, #0
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	beq _0205CD36
	add r0, r7, #0
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #1
	bne _0205CD3C
_0205CD36:
	ldr r0, _0205CD68 ; =SEQ_SE_DP_KUSA
	bl PlaySE
_0205CD3C:
	add r0, r5, #0
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	beq _0205CD50
	add r0, r7, #0
	bl MetatileBehavior_IsTallGrass
	cmp r0, #1
	bne _0205CD56
_0205CD50:
	ldr r0, _0205CD6C ; =SEQ_SE_GS_KUSA2
	bl PlaySE
_0205CD56:
	add r0, r4, #0
	add r1, r6, #0
	bl sub_0205CD70
_0205CD5E:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0205CD60: .word SEQ_SE_DP_FOOT3_1
_0205CD64: .word SEQ_SE_DP_MARSH_WALK
_0205CD68: .word SEQ_SE_DP_KUSA
_0205CD6C: .word SEQ_SE_GS_KUSA2
	thumb_func_end sub_0205CC94
	thumb_func_start sub_0205CD70
sub_0205CD70: ; 0x0205CD70
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r5, r1, #0
	bl MapObject_GetMovementCommand
	bl sub_02062390
	str r0, [sp]
	add r0, r6, #0
	bl sub_0205F504
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r6, #0
	bl sub_0205F504
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	add r0, r7, #0
	bl MetatileBehavior_IsVeryTallGrass
	cmp r0, #0
	bne _0205CE58
	add r0, r7, #0
	bl MetatileBehavior_IsPuddle
	cmp r0, #1
	beq _0205CE58
	add r0, r7, #0
	bl MetatileBehavior_IsShallowWater
	cmp r0, #1
	beq _0205CE58
	add r0, r7, #0
	bl MetatileBehavior_IsTallGrass
	cmp r0, #0
	bne _0205CE58
	mov r1, #0
	ldr r0, [sp]
	mvn r1, r1
	cmp r0, r1
	beq _0205CDD2
	ldr r1, [sp]
	add r0, r6, #0
	bl sub_02060FE0
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_0205CDD2:
	ldr r0, _0205CE5C ; =_020FCB98
	lsl r1, r4, #2
	ldrh r1, [r0, r1]
	ldr r0, _0205CE60 ; =SEQ_SE_GS_EDAPAKI
	cmp r1, r0
	bne _0205CDE6
	add r0, r5, #0
	bl PlayerAvatar_ResetUnkC
	b _0205CDFE
_0205CDE6:
	add r0, r5, #0
	bl PlayerAvatar_GetPlayerMoveState
	cmp r0, #0
	bne _0205CDF8
	add r0, r5, #0
	bl PlayerAvatar_ResetUnkC
	b _0205CDFE
_0205CDF8:
	add r0, r5, #0
	bl PlayerAvatar_ToggleUnkC
_0205CDFE:
	add r0, r5, #0
	bl PlayerAvatar_GetUnkC
	cmp r0, #0
	bne _0205CE58
	add r0, r5, #0
	bl PlayerAvatar_GetState
	cmp r0, #1
	beq _0205CE58
	cmp r0, #2
	beq _0205CE58
	cmp r4, #0x10
	bhs _0205CE52
	cmp r4, #0
	bne _0205CE2A
	add r0, r5, #0
	bl sub_0205DE98
	cmp r0, #1
	bne _0205CE2A
	mov r4, #1
_0205CE2A:
	ldr r0, _0205CE64 ; =_020FCB98 + 2
	lsl r1, r4, #2
	ldrh r0, [r0, r1]
	cmp r0, #1
	bne _0205CE40
	ldr r0, _0205CE5C ; =_020FCB98
	ldrh r4, [r0, r1]
	add r0, r4, #0
	bl sub_02006088
	b _0205CE4A
_0205CE40:
	ldr r0, _0205CE5C ; =_020FCB98
	ldrh r4, [r0, r1]
	add r0, r4, #0
	bl PlaySE
_0205CE4A:
	add r0, r4, #0
	bl sub_02005BA8
	pop {r3, r4, r5, r6, r7, pc}
_0205CE52:
	blo _0205CE58
	bl GF_AssertFail
_0205CE58:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0205CE5C: .word _020FCB98
_0205CE60: .word SEQ_SE_GS_EDAPAKI
_0205CE64: .word _020FCB98 + 2
	thumb_func_end sub_0205CD70
	thumb_func_start PlayerAvatar_UpdateMovement
PlayerAvatar_UpdateMovement: ; 0x0205CE68
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl PlayerAvatar_GetMoveState
	add r6, r0, #0
	add r0, r5, #0
	bl PlayerAvatar_GetPlayerMoveState
	add r4, r0, #0
	add r0, r5, #0
	bl PlayerAvatar_GetMapObject
	add r7, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl PlayerAvatar_SetPlayerMoveState
	mov r1, #0
	add r0, r5, #0
	mvn r1, r1
	bl sub_0205D01C
	cmp r0, #0
	beq _0205CEA6
	cmp r0, #2
	beq _0205CEA6
	add r0, r5, #0
	mov r1, #2
	bl PlayerAvatar_SetPlayerMoveState
	pop {r3, r4, r5, r6, r7, pc}
_0205CEA6:
	add r0, r7, #0
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #0
	bne _0205CEF2
	cmp r6, #0
	beq _0205CF40
	cmp r6, #1
	beq _0205CEBE
	cmp r6, #2
	beq _0205CEE8
	pop {r3, r4, r5, r6, r7, pc}
_0205CEBE:
	add r0, r7, #0
	bl MapObject_GetMovementCommand
	bl sub_0205DE64
	cmp r0, #1
	beq _0205CF40
	cmp r4, #0
	beq _0205CED4
	cmp r4, #3
	bne _0205CEDE
_0205CED4:
	add r0, r5, #0
	mov r1, #1
	bl PlayerAvatar_SetPlayerMoveState
	pop {r3, r4, r5, r6, r7, pc}
_0205CEDE:
	add r0, r5, #0
	mov r1, #2
	bl PlayerAvatar_SetPlayerMoveState
	pop {r3, r4, r5, r6, r7, pc}
_0205CEE8:
	add r0, r5, #0
	mov r1, #2
	bl PlayerAvatar_SetPlayerMoveState
	pop {r3, r4, r5, r6, r7, pc}
_0205CEF2:
	add r0, r7, #0
	bl MapObject_IsMovementPaused
	cmp r0, #1
	bne _0205CF40
	cmp r6, #0
	beq _0205CF40
	cmp r6, #1
	beq _0205CF0A
	cmp r6, #2
	beq _0205CF26
	pop {r3, r4, r5, r6, r7, pc}
_0205CF0A:
	cmp r4, #0
	beq _0205CF40
	cmp r4, #3
	bne _0205CF1C
	add r0, r5, #0
	mov r1, #0
	bl PlayerAvatar_SetPlayerMoveState
	pop {r3, r4, r5, r6, r7, pc}
_0205CF1C:
	add r0, r5, #0
	mov r1, #3
	bl PlayerAvatar_SetPlayerMoveState
	pop {r3, r4, r5, r6, r7, pc}
_0205CF26:
	cmp r4, #0
	beq _0205CF40
	cmp r4, #3
	bne _0205CF38
	add r0, r5, #0
	mov r1, #0
	bl PlayerAvatar_SetPlayerMoveState
	pop {r3, r4, r5, r6, r7, pc}
_0205CF38:
	add r0, r5, #0
	mov r1, #3
	bl PlayerAvatar_SetPlayerMoveState
_0205CF40:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end PlayerAvatar_UpdateMovement

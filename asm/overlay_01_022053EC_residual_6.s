#include "constants/sndseq.h"
#include "constants/moves.h"
#include "constants/std_script.h"
#include "constants/species.h"
#include "constants/sprites.h"
#include "constants/maps.h"
#include "constants/mmodel.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0096_D31R0201.h"
#include "msgdata/msg/msg_0066_D23R0102.h"
	.include "asm/macros.inc"
	.public ov01_022054E0
	.public ov01_022057DC
	.public ov01_0220589C
	.public ov01_02205B14
	.public ov01_02205DB4
	.public ov01_02205F00
	.public ov01_0220610C
	.public ov01_02206268
	.public ov01_022096E0
	.public ov01_022096F0
	.public ov01_022096F8
	.public ov01_02209704
	.public ov01_02209710
	.public ov01_02209720
	.public ov01_02209730
	.public ov01_02209740
	.public ov01_02209750
	.include "overlay_01_022053EC.inc"
	.include "global.inc"

	.text
	.public ScrCmd_808
	.public ov01_02205424
	.public ov01_0220542C
	.public ov01_0220553C
	.public ov01_02205564
	.public ov01_02205584
	.public ov01_022055B0
	.public ov01_022055DC
	.public ov01_02205604
	.public ov01_02205664
	.public ov01_022056C4
	.public ov01_02205720
	.public ov01_02205784
	.public ov01_02205790
	.public ov01_022057C4
	.public ov01_022057D0
	.public ov01_02205808
	.public ov01_02205870
	.public ov01_0220596C
	.public ov01_02205990
	.public ov01_022059AC
	.public ov01_02205A34
	.public ov01_02205A60
	.public ov01_02205AEC
	.public ov01_02205CF0
	.public ov01_02205D68
	.public ov01_02205EE0
	.public ov01_02206028
	.public ov01_02206088
	.public ov01_0220609C
	.public ov01_022060B8
	.public ov01_022062CC

	thumb_func_start ov01_02205F00
ov01_02205F00: ; 0x02205F00
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl TaskManager_GetFieldSystem
	add r4, r0, #0
	add r0, r5, #0
	bl TaskManager_GetEnvironment
	add r6, r0, #0
	add r0, r5, #0
	bl TaskManager_GetStatePtr
	add r5, r0, #0
	ldr r0, [r5]
	cmp r0, #6
	bls _02205F22
	b _02206024
_02205F22:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02205F2E: ; jump table
	.short _02205F3C - _02205F2E - 2 ; case 0
	.short _02205F56 - _02205F2E - 2 ; case 1
	.short _02205F7A - _02205F2E - 2 ; case 2
	.short _02205FA4 - _02205F2E - 2 ; case 3
	.short _02205FB6 - _02205F2E - 2 ; case 4
	.short _02205FF2 - _02205F2E - 2 ; case 5
	.short _0220601A - _02205F2E - 2 ; case 6
_02205F3C:
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	bl sub_020659CC
	add r4, #0xe4
	ldr r0, [r4]
	bl sub_0205F484
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _02206024
_02205F56:
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _02206024
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetMapObject
	add r4, #0xe4
	ldr r1, [r4]
	bl ov01_02206028
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _02206024
_02205F7A:
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _02206024
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetMapObject
	bl MapObject_GetFacingDirection
	add r4, #0xe4
	add r1, r0, #0
	ldr r0, [r4]
	bl MapObject_SetFacingDirection
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _02206024
_02205FA4:
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	cmp r0, #0xa
	ble _02206024
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _02206024
_02205FB6:
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _02206024
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	mov r1, #0
	bl sub_0206A040
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetMapObject
	bl MapObject_GetFacingDirection
	mov r1, #0x34
	bl sub_0206234C
	add r4, #0xe4
	add r1, r0, #0
	ldr r0, [r4]
	bl MapObject_SetHeldMovement
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _02206024
_02205FF2:
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	bl MapObject_AreBitsSetForMovementScriptInit
	cmp r0, #1
	bne _02206024
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	mov r1, #2
	bl ov01_0220329C
	add r0, r4, #0
	bl sub_0206A054
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _02206024
_0220601A:
	add r0, r6, #0
	bl Heap_Free
	mov r0, #1
	pop {r4, r5, r6, pc}
_02206024:
	mov r0, #0
	pop {r4, r5, r6, pc}
	thumb_func_end ov01_02205F00

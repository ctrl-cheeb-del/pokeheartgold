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

	thumb_func_start ov01_02205DB4
ov01_02205DB4: ; 0x02205DB4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r4, r0, #0
	bl TaskManager_GetFieldSystem
	add r5, r0, #0
	add r0, r4, #0
	bl TaskManager_GetEnvironment
	add r6, r0, #0
	add r0, r4, #0
	bl TaskManager_GetStatePtr
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #4
	bhi _02205ED2
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02205DE2: ; jump table
	.short _02205DEC - _02205DE2 - 2 ; case 0
	.short _02205DFC - _02205DE2 - 2 ; case 1
	.short _02205E12 - _02205DE2 - 2 ; case 2
	.short _02205E5A - _02205DE2 - 2 ; case 3
	.short _02205EC6 - _02205DE2 - 2 ; case 4
_02205DEC:
	add r0, r5, #0
	bl FollowMon_GetMapObject
	bl MapObject_UnpauseMovement
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
_02205DFC:
	add r0, r5, #0
	bl FollowMon_GetMapObject
	bl MapObject_IsMovementPaused
	cmp r0, #0
	beq _02205ED2
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02205ED2
_02205E12:
	add r0, r5, #0
	bl FollowMon_GetMapObject
	str r0, [sp]
	bl MapObject_GetSpriteID
	bl ov01_02206088
	add r7, r0, #0
	ldr r0, [r5, #0x3c]
	bl MapObjectManager_GetMapModelNarc
	add r1, r7, #0
	mov r2, #0xb
	bl NARC_AllocAndReadWholeMember
	add r5, r0, #0
	bl NNS_G3dGetTex
	ldr r1, [r0, #0x38]
	mov r2, #0x40
	add r0, r0, r1
	add r1, r6, #4
	bl MIi_CpuCopy16
	add r0, r5, #0
	bl Heap_Free
	ldr r0, [sp]
	mov r1, #1
	bl ov01_0220329C
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02205ED2
_02205E5A:
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	cmp r0, #0x14
	blt _02205ED2
	add r0, r5, #0
	mov r1, #0
	bl ov01_02205790
	ldr r3, _02205ED8 ; =ov01_022096F8
	add r2, sp, #8
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r5, #0x3c]
	bl ov01_021F771C
	add r7, r0, #0
	add r1, sp, #8
	bl sub_02023E78
	add r0, r7, #0
	bl sub_02023FB0
	str r0, [sp, #4]
	add r0, r7, #0
	bl sub_02023FB0
	add r1, r0, #0
	add r2, r6, #4
	lsl r1, r1, #0x10
	ldr r6, _02205EDC ; =0xFFFF0000
	ldr r3, [sp, #4]
	mov r0, #1
	and r3, r6
	lsr r3, r3, #0x10
	lsr r1, r1, #0xd
	lsl r3, r3, #3
	bl GF_CreateNewVramTransferTask
	add r0, r5, #0
	bl sub_0206A054
	add r0, r5, #0
	bl FollowMon_GetMapObject
	mov r1, #0
	bl sub_02069E28
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02205ED2
_02205EC6:
	add r0, r6, #0
	bl Heap_Free
	add sp, #0x14
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02205ED2:
	mov r0, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02205ED8: .word ov01_022096F8
_02205EDC: .word 0xFFFF0000
	thumb_func_end ov01_02205DB4

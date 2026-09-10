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

	thumb_func_start ov01_0220610C
ov01_0220610C: ; 0x0220610C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl TaskManager_GetFieldSystem
	add r6, r0, #0
	add r0, r5, #0
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	add r0, r5, #0
	bl TaskManager_GetStatePtr
	add r5, r0, #0
	ldr r0, [r5]
	cmp r0, #3
	bls _0220612E
	b _0220625A
_0220612E:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0220613A: ; jump table
	.short _02206142 - _0220613A - 2 ; case 0
	.short _02206180 - _0220613A - 2 ; case 1
	.short _022061EA - _0220613A - 2 ; case 2
	.short _02206250 - _0220613A - 2 ; case 3
_02206142:
	add r0, r6, #0
	bl FollowMon_GetMapObject
	bl MapObject_GetSpriteID
	bl ov01_02206088
	add r7, r0, #0
	ldr r0, [r6, #0x3c]
	bl MapObjectManager_GetMapModelNarc
	add r1, r7, #0
	mov r2, #0xb
	bl NARC_AllocAndReadWholeMember
	add r6, r0, #0
	bl NNS_G3dGetTex
	ldr r1, [r0, #0x38]
	mov r2, #0x40
	add r0, r0, r1
	add r1, r4, #4
	bl MIi_CpuCopy16
	add r0, r6, #0
	bl Heap_Free
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _0220625A
_02206180:
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _0220618C
	sub r0, r0, #1
	strb r0, [r4, #2]
	b _0220625A
_0220618C:
	mov r0, #0
	ldrsb r2, [r4, r0]
	ldrb r1, [r4, #1]
	add r1, r2, r1
	strb r1, [r4]
	ldrsb r0, [r4, r0]
	cmp r0, #0x10
	blt _022061A6
	mov r0, #0x10
	strb r0, [r4]
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
_022061A6:
	ldr r0, _02206260 ; =0x0000FFFF
	add r1, r4, #0
	str r0, [sp]
	ldrb r3, [r4]
	add r0, r4, #4
	add r1, #0x44
	mov r2, #0x20
	bl BlendPalette
	ldr r0, [r6, #0x3c]
	bl ov01_021F771C
	add r6, r0, #0
	bl sub_02023FB0
	add r5, r0, #0
	add r0, r6, #0
	bl sub_02023FB0
	add r1, r0, #0
	ldr r3, _02206264 ; =0xFFFF0000
	lsl r1, r1, #0x10
	and r3, r5
	add r2, r4, #0
	lsr r3, r3, #0x10
	mov r0, #1
	lsr r1, r1, #0xd
	add r2, #0x44
	lsl r3, r3, #3
	bl GF_CreateNewVramTransferTask
	ldrb r0, [r4, #3]
	strb r0, [r4, #2]
	b _0220625A
_022061EA:
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _022061F6
	sub r0, r0, #1
	strb r0, [r4, #2]
	b _0220625A
_022061F6:
	mov r0, #0
	ldrsb r2, [r4, r0]
	ldrb r1, [r4, #1]
	sub r1, r2, r1
	strb r1, [r4]
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bgt _0220620C
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
_0220620C:
	ldr r0, _02206260 ; =0x0000FFFF
	add r1, r4, #0
	str r0, [sp]
	ldrb r3, [r4]
	add r0, r4, #4
	add r1, #0x44
	mov r2, #0x20
	bl BlendPalette
	ldr r0, [r6, #0x3c]
	bl ov01_021F771C
	add r6, r0, #0
	bl sub_02023FB0
	add r5, r0, #0
	add r0, r6, #0
	bl sub_02023FB0
	add r1, r0, #0
	ldr r3, _02206264 ; =0xFFFF0000
	lsl r1, r1, #0x10
	and r3, r5
	add r2, r4, #0
	lsr r3, r3, #0x10
	mov r0, #1
	lsr r1, r1, #0xd
	add r2, #0x44
	lsl r3, r3, #3
	bl GF_CreateNewVramTransferTask
	ldrb r0, [r4, #3]
	strb r0, [r4, #2]
	b _0220625A
_02206250:
	add r0, r4, #0
	bl Heap_Free
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0220625A:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02206260: .word 0x0000FFFF
_02206264: .word 0xFFFF0000
	thumb_func_end ov01_0220610C


	thumb_func_start ov01_02206268
ov01_02206268: ; 0x02206268
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl FollowMon_IsVisible
	cmp r0, #0
	bne _02206278
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02206278:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	add r5, #0xe4
	add r4, r0, #0
	ldr r7, [r5]
	bl MapObject_GetXCoord
	add r5, r0, #0
	add r0, r4, #0
	bl MapObject_GetZCoord
	add r4, r0, #0
	add r0, r7, #0
	bl MapObject_GetXCoord
	add r6, r0, #0
	add r0, r7, #0
	bl MapObject_GetZCoord
	cmp r5, r6
	bne _022062B4
	add r1, r4, #1
	cmp r1, r0
	beq _022062B0
	sub r1, r4, #1
	cmp r1, r0
	bne _022062C8
_022062B0:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_022062B4:
	cmp r4, r0
	bne _022062C8
	add r0, r5, #1
	cmp r0, r6
	beq _022062C4
	sub r0, r5, #1
	cmp r0, r6
	bne _022062C8
_022062C4:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_022062C8:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov01_02206268

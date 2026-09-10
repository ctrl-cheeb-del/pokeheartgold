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

	thumb_func_start ov01_0220589C
ov01_0220589C: ; 0x0220589C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	mov r0, #0xb
	mov r1, #0x28
	add r5, r2, #0
	bl Heap_AllocAtEnd
	mov r1, #0
	mov r2, #4
	add r4, r0, #0
	bl MI_CpuFill8
	add r0, r6, #0
	mov r1, #2
	bl MapObject_GetParam
	lsl r0, r0, #0xf
	lsr r0, r0, #0x10
	bl ov01_02206088
	add r7, r0, #0
	add r0, r6, #0
	bl MapObject_GetManager
	bl MapObjectManager_GetMapModelNarc
	add r1, r7, #0
	mov r2, #0xb
	bl NARC_AllocAndReadWholeMember
	str r0, [r4]
	bl NNS_G3dGetTex
	add r6, r0, #0
	mov r1, #0
	bl sub_02020888
	add r7, r0, #0
	add r0, r6, #0
	mov r1, #0
	bl sub_02020838
	add r1, r4, #0
	str r0, [r4, #4]
	add r0, r7, #0
	add r1, #8
	mov r2, #0x20
	bl MIi_CpuCopy16
	add r0, r4, #0
	add r0, #8
	mov r1, #0x10
	bl TintPalette_GrayScale
	mov r0, #0
	mov r1, #0x10
	str r0, [sp]
	add r0, r4, #0
	add r2, r1, #0
	add r0, #8
	add r2, #0xf0
	mov r3, #0xb4
	bl TintPalette_CustomTone
	add r0, r5, #0
	bl sub_02023FB0
	add r1, r0, #0
	lsl r1, r1, #0x10
	add r2, r4, #0
	mov r0, #1
	lsr r1, r1, #0xd
	add r2, #8
	mov r3, #0x20
	bl GF_CreateNewVramTransferTask
	add r0, r5, #0
	bl sub_02023FA0
	add r6, r0, #0
	add r0, r5, #0
	bl sub_02023FA0
	add r1, r0, #0
	ldr r3, _02205964 ; =0x7FFF0000
	lsl r1, r1, #0x10
	and r3, r6
	lsr r3, r3, #0x10
	ldr r2, [r4, #4]
	mov r0, #0
	lsr r1, r1, #0xd
	lsl r3, r3, #4
	bl GF_CreateNewVramTransferTask
	ldr r0, _02205968 ; =ov01_0220596C
	add r1, r4, #0
	mov r2, #0
	bl SysTask_CreateOnVWaitQueue
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02205964: .word 0x7FFF0000
_02205968: .word ov01_0220596C
	thumb_func_end ov01_0220589C

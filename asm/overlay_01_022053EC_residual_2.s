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

	thumb_func_start ov01_022057DC
ov01_022057DC: ; 0x022057DC
	push {r3, lr}
	bl sub_0205F1A0
	add r0, #0xfc
	ldr r0, [r0]
	mov r1, #0x16
	bl ov01_021FC5A4
	ldr r2, [r0]
	add r1, r0, #4
	lsl r0, r2, #1
	add r0, r1, r0
	add r3, r0, r2
	mov r1, #0
	cmp r2, #0
	ble _02205806
	mov r0, #1
_022057FE:
	strb r0, [r3, r1]
	add r1, r1, #1
	cmp r1, r2
	blt _022057FE
_02205806:
	pop {r3, pc}
	thumb_func_end ov01_022057DC

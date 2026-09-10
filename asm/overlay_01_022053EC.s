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

	thumb_func_start ov01_022054E0
ov01_022054E0: ; 0x022054E0
	push {r3, r4, r5, lr}
	sub sp, #0xc0
	ldr r5, _02205538 ; =ov01_02209750
	add r4, r0, #0
	add r3, sp, #0
	mov r2, #0x18
_022054EC:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _022054EC
	add r0, r4, #0
	bl ov01_02205584
	cmp r0, #0
	beq _02205504
	add sp, #0xc0
	mov r0, #0
	pop {r3, r4, r5, pc}
_02205504:
	add r0, r4, #0
	bl sub_020659A8
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	bne _02205516
	add sp, #0xc0
	mov r0, #0
	pop {r3, r4, r5, pc}
_02205516:
	add r0, r4, #0
	bl sub_0206599C
	add r4, r0, #0
	cmp r4, #0x10
	blt _02205526
	bl GF_AssertFail
_02205526:
	sub r0, r5, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x12
	add r0, sp, #0
	lsl r1, r4, #2
	add r0, r0, r2
	ldr r0, [r1, r0]
	add sp, #0xc0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02205538: .word ov01_02209750
	thumb_func_end ov01_022054E0

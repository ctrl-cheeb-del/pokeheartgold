.public ov01_021EDAFC
.public ov01_021EDC28
.public ov01_021EDC7C
.public ov01_021EDC84
.public ov01_021EDD68
.public ov01_021EDDD8
.public ov01_021EDE18
.public ov01_021EDE8C
.public ov01_021EDF00
.public ov01_021EDF38
.public ov01_021EDF78
.public MoveTutorMenu_SetListItem
.public ov01_021EDFA4
.public ov01_021EE014
.public ov01_021EE01C
.public ov01_021EE0EC
.public MoveTutorMenu_SetListItem_Internal
.public ov01_021EE2E4
.public ov01_021EE324
.public ov01_021EE434
.public ov01_021EE458
.public ov01_021EE49C
.public ov01_021EE568
.public ov01_021EE5D0
.public ov01_021EE634
.public PrintCurFloorInNewWindow
.public ov01_021EE754
.public ov01_021EE7B8
.public MapNumToFloorNo
.public ov01_021EE934
.public ov01_021EE974
.public ov01_021EEA44
.public FieldSystem_ShowMoneyBox
.public MoneyBoxSys_Delete
.public MoneyBoxSys_Update
.public ov01_021EEC00
.public ov01_021EEC68
.public ov01_021EEC7C
.public ov01_021EED60
.public ov01_021EEE30
.public ov01_021EEE44
.public ov01_021EEF58
.public ov01_021EEF60
.public ov01_021EEF68
.public ov01_021EEF88
.public ov01_021EEF9C
.public ov01_021EF00C
.public ov01_021EF018
.public ov01_021EF034
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
	.include "overlay_01_021EDAFC.inc"
	.include "global.inc"

	.text
	.public MoneyBoxSys_Delete
	.public MoveTutorMenu_SetListItem
	.public MoveTutorMenu_SetListItem_Internal
	.public ov01_021EDAFC
	.public ov01_021EDC28
	.public ov01_021EDC7C
	.public ov01_021EDC84
	.public ov01_021EDD68
	.public ov01_021EDDD8
	.public ov01_021EDE18
	.public ov01_021EDF00
	.public ov01_021EDF38
	.public ov01_021EDF78
	.public ov01_021EE014
	.public ov01_021EE01C
	.public ov01_021EE2E4
	.public ov01_021EE324
	.public ov01_021EE434
	.public ov01_021EE458
	.public ov01_021EE568
	.public ov01_021EE5D0
	.public ov01_021EE634
	.public ov01_021EE7B8
	.public ov01_021EE934
	.public ov01_021EEC68
	.public ov01_021EEE30
	.public ov01_021EEF58
	.public ov01_021EEF60
	.public ov01_021EEF68
	.public ov01_021EEF88
	.public ov01_021EEF9C
	.public ov01_021EF00C

	thumb_func_start ov01_021EE49C
ov01_021EE49C: ; 0x021EE49C
	push {r4, r5, r6, lr}
	add r5, r1, #0
	add r0, r5, #0
	add r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _021EE4B8
	add r0, r5, #0
	add r0, #0x94
	ldrb r0, [r0]
	add r5, #0x94
	sub r0, r0, #1
	strb r0, [r5]
	pop {r4, r5, r6, pc}
_021EE4B8:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021EE55A
	mov r0, #0x6f
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl ListMenu_ProcessInput
	add r4, r0, #0
	mov r0, #0x6f
	mov r1, #0xb7
	lsl r0, r0, #2
	lsl r1, r1, #2
	ldrh r6, [r5, r1]
	ldr r0, [r5, r0]
	add r1, r5, r1
	bl ListMenuGetCurrentItemArrayId
	mov r0, #0xb7
	lsl r0, r0, #2
	ldrh r0, [r5, r0]
	cmp r6, r0
	beq _021EE4EE
	ldr r0, _021EE55C ; =SEQ_SE_DP_SELECT
	bl PlaySE
_021EE4EE:
	ldr r0, _021EE560 ; =gSystem
	mov r1, #0x40
	ldr r0, [r0, #0x4c]
	tst r1, r0
	bne _021EE50A
	mov r1, #0x80
	tst r1, r0
	bne _021EE50A
	mov r1, #0x20
	tst r1, r0
	bne _021EE50A
	mov r1, #0x10
	tst r0, r1
	beq _021EE510
_021EE50A:
	add r0, r5, #0
	bl ov01_021EE634
_021EE510:
	mov r0, #1
	mvn r0, r0
	cmp r4, r0
	beq _021EE520
	add r0, r0, #1
	cmp r4, r0
	beq _021EE55A
	b _021EE546
_021EE520:
	add r0, r5, #0
	add r0, #0x97
	ldrb r0, [r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _021EE55A
	ldr r0, _021EE55C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	add r0, r5, #0
	add r0, #0xa0
	ldr r1, _021EE564 ; =0x0000FFFE
	ldr r0, [r0]
	strh r1, [r0]
	add r0, r5, #0
	bl ov01_021EE568
	pop {r4, r5, r6, pc}
_021EE546:
	ldr r0, _021EE55C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	add r0, r5, #0
	add r0, #0xa0
	ldr r0, [r0]
	strh r4, [r0]
	add r0, r5, #0
	bl ov01_021EE568
_021EE55A:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021EE55C: .word SEQ_SE_DP_SELECT
_021EE560: .word gSystem
_021EE564: .word 0x0000FFFE
	thumb_func_end ov01_021EE49C

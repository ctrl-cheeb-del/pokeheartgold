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

	thumb_func_start ov01_021EDE8C
ov01_021EDE8C: ; 0x021EDE8C
	push {r4, lr}
	add r4, r1, #0
	add r0, r4, #0
	add r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _021EDEA8
	add r0, r4, #0
	add r0, #0x94
	ldrb r0, [r0]
	add r4, #0x94
	sub r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_021EDEA8:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021EDEF8
	add r0, r4, #0
	add r0, #0xb8
	ldr r0, [r0]
	bl Handle2dMenuInput
	mov r1, #1
	mvn r1, r1
	cmp r0, r1
	beq _021EDECA
	add r1, r1, #1
	cmp r0, r1
	beq _021EDEF8
	b _021EDEEA
_021EDECA:
	add r0, r4, #0
	add r0, #0x97
	ldrb r0, [r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _021EDEF8
	add r0, r4, #0
	add r0, #0xa0
	ldr r1, _021EDEFC ; =0x0000FFFE
	ldr r0, [r0]
	strh r1, [r0]
	add r0, r4, #0
	bl ov01_021EDF38
	pop {r4, pc}
_021EDEEA:
	add r1, r4, #0
	add r1, #0xa0
	ldr r1, [r1]
	strh r0, [r1]
	add r0, r4, #0
	bl ov01_021EDF38
_021EDEF8:
	pop {r4, pc}
	nop
_021EDEFC: .word 0x0000FFFE
	thumb_func_end ov01_021EDE8C

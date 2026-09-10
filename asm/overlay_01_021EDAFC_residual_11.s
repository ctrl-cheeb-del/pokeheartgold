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

	thumb_func_start ov01_021EF018
ov01_021EF018: ; 0x021EF018
	add r2, r0, #0
	add r2, #0x97
	ldrb r3, [r2]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	mov r2, #0x40
	lsl r1, r1, #0x1f
	bic r3, r2
	lsr r1, r1, #0x19
	orr r1, r3
	add r0, #0x97
	strb r1, [r0]
	bx lr
	.balign 4, 0
	thumb_func_end ov01_021EF018


	thumb_func_start ov01_021EF034
ov01_021EF034: ; 0x021EF034
	add r2, r0, #0
	add r2, #0x97
	ldrb r3, [r2]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	mov r2, #0x80
	lsl r1, r1, #0x1f
	bic r3, r2
	lsr r1, r1, #0x18
	orr r1, r3
	add r0, #0x97
	strb r1, [r0]
	bx lr
	.balign 4, 0
	thumb_func_end ov01_021EF034

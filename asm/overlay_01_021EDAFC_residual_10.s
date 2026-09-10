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

	thumb_func_start ov01_021EEE44
ov01_021EEE44: ; 0x021EEE44
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	mov r3, #0x80
	add r7, r0, #0
	add r5, r1, #0
	str r3, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #0xf
	mov r2, #0
	bl FillWindowPixelRect
	mov r0, #0x80
	str r0, [sp]
	mov r0, #0x10
	mov r3, #6
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #0xf
	mov r2, #0
	lsl r3, r3, #6
	bl FillWindowPixelRect
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xbf
	mov r3, #4
	bl NewMsgDataFromNarc
	str r0, [sp, #0xc]
	mov r0, #4
	bl MessageFormat_New
	add r6, r0, #0
	mov r0, #0x10
	mov r1, #4
	bl String_New
	add r4, r0, #0
	mov r1, #0x53
	ldr r0, [sp, #0xc]
	lsl r1, r1, #2
	bl NewString_ReadMsgData
	str r0, [sp, #0x10]
	ldr r0, [r7, #0xc]
	bl SaveData_GetPhoneCallPersistentState
	mov r1, #0
	add r2, r1, #0
	bl PhoneCallPersistentState_MomSavings_BalanceAction
	mov r1, #0
	add r2, r0, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r6, #0
	mov r3, #6
	bl BufferIntegerAsString
	ldr r2, [sp, #0x10]
	add r0, r6, #0
	add r1, r4, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r4, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0x80
	sub r3, r1, r0
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r1, #0
	add r0, r5, #0
	add r2, r4, #0
	str r1, [sp, #8]
	bl AddTextPrinterParameterized
	ldr r0, [r7, #0xc]
	bl Save_PlayerData_GetProfile
	bl PlayerProfile_GetMoney
	mov r1, #0
	add r2, r0, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r6, #0
	mov r3, #6
	bl BufferIntegerAsString
	ldr r2, [sp, #0x10]
	add r0, r6, #0
	add r1, r4, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r4, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0x80
	sub r3, r1, r0
	mov r0, #0x30
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r1, #0
	add r0, r5, #0
	add r2, r4, #0
	str r1, [sp, #8]
	bl AddTextPrinterParameterized
	ldr r0, [sp, #0x10]
	bl String_Delete
	add r0, r4, #0
	bl String_Delete
	add r0, r6, #0
	bl MessageFormat_Delete
	ldr r0, [sp, #0xc]
	bl DestroyMsgData
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov01_021EEE44

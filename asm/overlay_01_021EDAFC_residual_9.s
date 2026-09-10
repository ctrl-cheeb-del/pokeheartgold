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

	thumb_func_start ov01_021EEC7C
ov01_021EEC7C: ; 0x021EEC7C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	str r1, [sp, #0xc]
	add r0, r1, #0
	mov r1, #0xf
	add r4, r2, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xbf
	mov r3, #4
	bl NewMsgDataFromNarc
	add r7, r0, #0
	mov r0, #4
	bl MessageFormat_New
	str r0, [sp, #0x10]
	mov r0, #0x10
	mov r1, #4
	bl String_New
	add r6, r0, #0
	cmp r4, #0
	beq _021EECBA
	cmp r4, #1
	beq _021EECD2
	cmp r4, #2
	b _021EECEE
_021EECBA:
	add r0, r7, #0
	mov r1, #0xc1
	bl NewString_ReadMsgData
	add r4, r0, #0
	ldr r0, [r5, #0xc]
	bl Save_PlayerData_GetCoinsAddr
	bl Coins_GetValue
	add r2, r0, #0
	b _021EED04
_021EECD2:
	add r0, r7, #0
	mov r1, #0xdc
	bl NewString_ReadMsgData
	add r4, r0, #0
	ldr r0, [r5, #0xc]
	bl Save_FrontierData_Get
	mov r1, #0
	add r2, r1, #0
	bl FrontierData_BattlePointAction
	add r2, r0, #0
	b _021EED04
_021EECEE:
	add r0, r7, #0
	mov r1, #0xdf
	bl NewString_ReadMsgData
	add r4, r0, #0
	ldr r0, [r5, #0xc]
	bl Save_Pokeathlon_Get
	bl PokeathlonSave_GetAthletePoints
	add r2, r0, #0
_021EED04:
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	mov r1, #0
	mov r3, #5
	bl BufferIntegerAsString
	ldr r0, [sp, #0x10]
	add r1, r6, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	mov r0, #0
	add r1, r6, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	mov r1, #0x50
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	add r2, r6, #0
	str r1, [sp, #8]
	bl AddTextPrinterParameterized
	add r0, r4, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	ldr r0, [sp, #0x10]
	bl MessageFormat_Delete
	add r0, r7, #0
	bl DestroyMsgData
	ldr r0, [sp, #0xc]
	bl ScheduleWindowCopyToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov01_021EEC7C


	thumb_func_start ov01_021EED60
ov01_021EED60: ; 0x021EED60
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r7, r1, #0
	add r6, r2, #0
	mov r0, #4
	mov r1, #1
	bl AllocWindows
	add r4, r0, #0
	str r6, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	ldr r0, [r5, #8]
	add r1, r4, #0
	mov r2, #3
	add r3, r7, #0
	bl AddWindowParameterized
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r2, _021EEE24 ; =0x000003D9
	mov r1, #3
	mov r3, #0xb
	bl LoadUserFrameGfx1
	ldr r2, _021EEE24 ; =0x000003D9
	add r0, r4, #0
	mov r1, #1
	mov r3, #0xb
	bl DrawFrameAndWindow1
	add r0, r4, #0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xbf
	mov r3, #4
	bl NewMsgDataFromNarc
	ldr r1, _021EEE28 ; =0x0000014A
	add r7, r0, #0
	bl NewString_ReadMsgData
	mov r1, #0
	add r6, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	add r0, r4, #0
	add r2, r6, #0
	add r3, r1, #0
	str r1, [sp, #8]
	bl AddTextPrinterParameterized
	add r0, r6, #0
	bl String_Delete
	ldr r1, _021EEE2C ; =0x0000014B
	add r0, r7, #0
	bl NewString_ReadMsgData
	add r6, r0, #0
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0xff
	mov r1, #0
	str r0, [sp, #4]
	add r0, r4, #0
	add r2, r6, #0
	add r3, r1, #0
	str r1, [sp, #8]
	bl AddTextPrinterParameterized
	add r0, r6, #0
	bl String_Delete
	add r0, r7, #0
	bl DestroyMsgData
	add r0, r5, #0
	add r1, r4, #0
	bl ov01_021EEE44
	add r0, r4, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021EEE24: .word 0x000003D9
_021EEE28: .word 0x0000014A
_021EEE2C: .word 0x0000014B
	thumb_func_end ov01_021EED60

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

	thumb_func_start PrintCurFloorInNewWindow
PrintCurFloorInNewWindow: ; 0x021EE664
	push {r4, r5, r6, lr}
	sub sp, #0x18
	mov r4, #0
	str r4, [sp]
	str r3, [sp, #4]
	ldr r3, [sp, #0x28]
	add r6, r0, #0
	str r3, [sp, #8]
	str r4, [sp, #0xc]
	add r3, r4, #0
	str r4, [sp, #0x10]
	bl ov01_021EDC28
	add r5, r0, #0
	add r0, r4, #0
	add r1, r0, #0
	bl GetFontAttribute
	lsl r1, r0, #3
	mov r0, #7
	tst r0, r1
	bne _021EE694
	lsr r4, r1, #3
	b _021EE698
_021EE694:
	lsr r0, r1, #3
	add r4, r0, #1
_021EE698:
	add r0, r5, #0
	add r0, #0x99
	ldrb r0, [r0]
	add r3, r5, #0
	add r1, r5, #0
	str r0, [sp]
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0xdd
	str r0, [sp, #0x10]
	ldr r0, [r5]
	add r3, #0x98
	ldrb r3, [r3]
	ldr r0, [r0, #8]
	add r1, #8
	mov r2, #3
	bl AddWindowParameterized
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, [r5]
	ldr r2, _021EE74C ; =0x000003D9
	ldr r0, [r0, #8]
	mov r1, #3
	mov r3, #0xb
	bl LoadUserFrameGfx1
	add r0, r5, #0
	ldr r2, _021EE74C ; =0x000003D9
	add r0, #8
	mov r1, #1
	mov r3, #0xb
	bl DrawFrameAndWindow1
	lsl r0, r4, #0x13
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #0
	add r0, #8
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	mov r2, #0
	add r0, r5, #0
	mov r1, #0x10
	add r3, r2, #0
	bl ov01_021EE754
	ldr r0, [r6, #0x20]
	add r1, sp, #0x18
	ldrh r1, [r1, #0x14]
	ldr r0, [r0]
	add r2, sp, #0x14
	bl ov01_021EE934
	add r1, r0, #0
	add r2, sp, #0x14
	lsl r1, r1, #0x10
	ldrb r2, [r2]
	add r0, r5, #0
	lsr r1, r1, #0x10
	mov r3, #0x10
	bl ov01_021EE754
	add r0, r5, #0
	add r1, r5, #0
	add r0, #8
	add r1, #0xb0
	str r0, [r1]
	bl CopyWindowToVram
	ldr r0, _021EE750 ; =ov01_021EE7B8
	add r1, r5, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r5, #4]
	add sp, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021EE74C: .word 0x000003D9
_021EE750: .word ov01_021EE7B8
	thumb_func_end PrintCurFloorInNewWindow


	thumb_func_start ov01_021EE754
ov01_021EE754: ; 0x021EE754
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r1, [sp, #0xc]
	add r5, r0, #0
	mov r0, #0x5a
	mov r1, #4
	str r2, [sp, #0x10]
	add r7, r3, #0
	bl String_New
	add r4, r0, #0
	mov r0, #0x5a
	mov r1, #4
	bl String_New
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0x8c
	ldr r0, [r0]
	ldr r1, [sp, #0xc]
	add r2, r4, #0
	bl ReadMsgDataIntoString
	add r0, r5, #0
	add r0, #0x90
	ldr r0, [r0]
	add r1, r6, #0
	add r2, r4, #0
	bl StringExpandPlaceholders
	str r7, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	add r5, #8
	ldr r3, [sp, #0x10]
	add r0, r5, #0
	add r2, r6, #0
	bl AddTextPrinterParameterized
	add r0, r4, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov01_021EE754

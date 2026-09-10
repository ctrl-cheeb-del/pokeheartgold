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

	thumb_func_start ov01_021EE974
ov01_021EE974: ; 0x021EE974
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r6, r1, #0
	bl ov01_021EDDD8
	mov r1, #7
	tst r1, r0
	bne _021EE98A
	lsr r7, r0, #3
	b _021EE98E
_021EE98A:
	lsr r0, r0, #3
	add r7, r0, #1
_021EE98E:
	add r0, r5, #0
	add r0, #0x9b
	ldrb r0, [r0]
	add r1, r6, #0
	str r0, [sp, #0x14]
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, [sp, #0x14]
	add r1, r6, #0
	bl _s32_div_f
	cmp r1, #0
	beq _021EE9B2
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_021EE9B2:
	add r0, r5, #0
	add r0, #0x99
	ldrb r0, [r0]
	add r3, r5, #0
	add r1, r5, #0
	str r0, [sp]
	add r0, r7, #0
	mul r0, r6
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	lsl r0, r4, #0x19
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x3d
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
	ldr r2, _021EEA3C ; =0x000003D9
	ldr r0, [r0, #8]
	mov r1, #3
	mov r3, #0xb
	bl LoadUserFrameGfx1
	add r0, r5, #0
	ldr r2, _021EEA3C ; =0x000003D9
	add r0, #8
	mov r1, #1
	mov r3, #0xb
	bl DrawFrameAndWindow1
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	bl ov01_021EEA44
	add r1, r5, #0
	add r1, #0x96
	add r0, r5, #0
	ldrb r1, [r1]
	add r0, #0xac
	mov r2, #4
	bl Create2dMenu
	add r1, r5, #0
	add r1, #0xb8
	str r0, [r1]
	ldr r0, _021EEA40 ; =ov01_021EDE8C
	add r1, r5, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r5, #4]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021EEA3C: .word 0x000003D9
_021EEA40: .word ov01_021EDE8C
	thumb_func_end ov01_021EE974


	thumb_func_start ov01_021EEA44
ov01_021EEA44: ; 0x021EEA44
	push {r3, r4}
	add r4, r0, #0
	add r3, r0, #0
	add r4, #0xbc
	add r3, #0xac
	str r4, [r3]
	add r4, r0, #0
	add r3, r0, #0
	add r4, #8
	add r3, #0xb0
	str r4, [r3]
	add r3, r0, #0
	mov r4, #0
	add r3, #0xb4
	strb r4, [r3]
	add r3, r0, #0
	add r3, #0xb5
	strb r1, [r3]
	add r1, r0, #0
	add r1, #0xb6
	strb r2, [r1]
	add r1, r0, #0
	add r1, #0xb7
	ldrb r2, [r1]
	mov r1, #0xf
	bic r2, r1
	add r1, r0, #0
	add r1, #0xb7
	strb r2, [r1]
	add r1, r0, #0
	add r1, #0xb7
	ldrb r2, [r1]
	mov r1, #0x30
	add r0, #0xb7
	bic r2, r1
	strb r2, [r0]
	pop {r3, r4}
	bx lr
	thumb_func_end ov01_021EEA44


	thumb_func_start FieldSystem_ShowMoneyBox
FieldSystem_ShowMoneyBox: ; 0x021EEA90
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
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #4
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
	ldr r2, _021EEB30 ; =0x000003D9
	mov r1, #3
	mov r3, #0xb
	bl LoadUserFrameGfx1
	ldr r2, _021EEB30 ; =0x000003D9
	add r0, r4, #0
	mov r1, #1
	mov r3, #0xb
	bl DrawFrameAndWindow1
	add r0, r4, #0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	ldr r2, _021EEB34 ; =0x000001B3
	mov r0, #0
	mov r1, #0x1b
	mov r3, #4
	bl NewMsgDataFromNarc
	mov r1, #0x1e
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
	add r0, r7, #0
	bl DestroyMsgData
	add r0, r6, #0
	bl String_Delete
	add r0, r5, #0
	add r1, r4, #0
	bl MoneyBoxSys_Update
	add r0, r4, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_021EEB30: .word 0x000003D9
_021EEB34: .word 0x000001B3
	thumb_func_end FieldSystem_ShowMoneyBox

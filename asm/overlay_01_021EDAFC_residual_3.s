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

	thumb_func_start ov01_021EE0EC
ov01_021EE0EC: ; 0x021EE0EC
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	bl ov01_021EE2E4
	mov r1, #7
	tst r1, r0
	bne _021EE104
	lsr r1, r0, #3
	b _021EE108
_021EE104:
	lsr r0, r0, #3
	add r1, r0, #1
_021EE108:
	add r0, r5, #0
	add r0, #0x97
	ldrb r0, [r0]
	lsl r0, r0, #0x19
	lsr r0, r0, #0x1f
	beq _021EE122
	add r0, r5, #0
	add r0, #0x98
	ldrb r0, [r0]
	sub r2, r0, r1
	add r0, r5, #0
	add r0, #0x98
	strb r2, [r0]
_021EE122:
	add r0, r5, #0
	add r0, #0x97
	ldrb r0, [r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1f
	beq _021EE158
	add r0, r5, #0
	add r0, #0x9b
	ldrb r3, [r0]
	cmp r3, #8
	bls _021EE148
	add r0, r5, #0
	add r0, #0x99
	ldrb r2, [r0]
	add r0, r5, #0
	add r0, #0x99
	sub r2, #0x10
	strb r2, [r0]
	b _021EE158
_021EE148:
	add r0, r5, #0
	add r0, #0x99
	ldrb r2, [r0]
	lsl r0, r3, #1
	sub r2, r2, r0
	add r0, r5, #0
	add r0, #0x99
	strb r2, [r0]
_021EE158:
	add r0, r5, #0
	add r0, #0x9b
	ldrb r0, [r0]
	cmp r0, #8
	bls _021EE192
	add r0, r5, #0
	add r0, #0x99
	ldrb r0, [r0]
	add r3, r5, #0
	add r3, #0x98
	str r0, [sp]
	lsl r0, r1, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #0x10
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x3d
	str r0, [sp, #0x10]
	ldr r0, [r5]
	add r1, r5, #0
	ldrb r3, [r3]
	ldr r0, [r0, #8]
	add r1, #8
	mov r2, #3
	bl AddWindowParameterized
	b _021EE1C2
_021EE192:
	add r2, r5, #0
	add r2, #0x99
	ldrb r2, [r2]
	lsl r1, r1, #0x18
	lsl r0, r0, #0x19
	str r2, [sp]
	lsr r1, r1, #0x18
	str r1, [sp, #4]
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x3d
	add r3, r5, #0
	str r0, [sp, #0x10]
	ldr r0, [r5]
	add r3, #0x98
	add r1, r5, #0
	ldrb r3, [r3]
	ldr r0, [r0, #8]
	add r1, #8
	mov r2, #3
	bl AddWindowParameterized
_021EE1C2:
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, [r5]
	ldr r2, _021EE23C ; =0x000003D9
	ldr r0, [r0, #8]
	mov r1, #3
	mov r3, #0xb
	bl LoadUserFrameGfx1
	add r0, r5, #0
	ldr r2, _021EE23C ; =0x000003D9
	add r0, #8
	mov r1, #1
	mov r3, #0xb
	bl DrawFrameAndWindow1
	add r0, r5, #0
	bl ov01_021EE324
	add r0, r5, #0
	add r0, #0xa4
	str r4, [r0]
	add r0, r5, #0
	add r0, #0xa8
	str r6, [r0]
	add r0, r5, #0
	add r0, #0xa4
	ldr r0, [r0]
	mov r3, #4
	ldrh r1, [r0]
	add r0, r5, #0
	add r0, #0xa8
	ldr r0, [r0]
	ldrh r0, [r0]
	add r1, r1, r0
	mov r0, #0xb7
	lsl r0, r0, #2
	strh r1, [r5, r0]
	mov r0, #0x67
	lsl r0, r0, #2
	ldrh r1, [r4]
	ldrh r2, [r6]
	add r0, r5, r0
	bl ListMenuInit
	mov r1, #0x6f
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r5, #0
	bl ov01_021EE634
	ldr r0, _021EE240 ; =ov01_021EE49C
	add r1, r5, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r5, #4]
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021EE23C: .word 0x000003D9
_021EE240: .word ov01_021EE49C
	thumb_func_end ov01_021EE0EC

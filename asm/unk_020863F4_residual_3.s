#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_020863F4.inc"
	.include "global.inc"

	.public gOverlayTemplate_Battle
	.public gNatureStatMods

	.text
	.public _021027C8
	.public _021027DC
	.public _021027F4
	.public sub_020863F4
	.public sub_02086490
	.public sub_020866CC
	.public sub_02086758
	.public sub_020868A0
	.public sub_020869BC
	.public sub_02086AB4
	.public sub_02086AE4
	.public sub_02086B2C
	.public sub_02086B6C
	.public sub_02086BB4
	.public sub_02086C80
	.public sub_02086C8C
	.public sub_02086D98
	.public sub_02086DA4
	.public sub_02086DE4
	.public sub_02086F44
	.public sub_02086FCC
	.public sub_02086FE8
	.public sub_02087028
	.public sub_02087064
	.public sub_02087090
	.public sub_020871C4
	.public sub_02087230

	thumb_func_start sub_02086DE4
sub_02086DE4: ; 0x02086DE4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r1, [sp, #4]
	mov r1, #0xb5
	lsl r1, r1, #2
	str r0, [sp]
	ldr r0, [r0, r1]
	mov r4, #0
	lsl r2, r0, #1
	ldr r0, [sp]
	str r4, [sp, #8]
	add r2, r0, r2
	add r0, r1, #0
	sub r0, #0x34
	ldrsh r5, [r2, r0]
	ldr r0, [sp]
	sub r1, r1, #4
	ldr r0, [r0, r1]
	cmp r0, #0
	bgt _02086E0E
	b _02086F3E
_02086E0E:
	ldr r7, [sp]
	add r6, r7, #0
_02086E12:
	mov r0, #0xb7
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	cmp r4, r0
	blt _02086E3E
	add r2, r1, #0
	mov r1, #0x2e
	lsl r1, r1, #4
	ldr r1, [r2, r1]
	cmp r4, r1
	bge _02086E3E
	cmp r4, r0
	bne _02086E36
	add r5, #0x14
	lsl r0, r5, #0x10
	asr r5, r0, #0x10
	b _02086E50
_02086E36:
	add r5, #0x20
	lsl r0, r5, #0x10
	asr r5, r0, #0x10
	b _02086E50
_02086E3E:
	cmp r4, #0
	bne _02086E4A
	add r5, #0x14
	lsl r0, r5, #0x10
	asr r5, r0, #0x10
	b _02086E50
_02086E4A:
	add r5, #8
	lsl r0, r5, #0x10
	asr r5, r0, #0x10
_02086E50:
	add r1, sp, #0xc
	ldr r0, [r7, #0xc]
	add r1, #2
	add r2, sp, #0xc
	bl ManagedSprite_GetPositionXY
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _02086E72
	add r3, sp, #0xc
	mov r2, #0
	ldrsh r2, [r3, r2]
	ldr r0, [r7, #0xc]
	add r1, r5, #0
	bl ManagedSprite_SetPositionXY
	b _02086E8E
_02086E72:
	add r1, sp, #0xc
	mov r0, #2
	ldrsh r0, [r1, r0]
	sub r1, r5, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	strh r0, [r7, #0x14]
	mov r0, #0
	strh r0, [r7, #0x16]
	mov r0, #2
	strb r0, [r7, #0x18]
	mov r0, #0
	strb r0, [r7, #0x19]
_02086E8E:
	mov r0, #7
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	cmp r4, r0
	bne _02086F2C
	mov r0, #0xfb
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r1, [r1, r0]
	ldr r0, [sp, #8]
	cmp r0, r1
	beq _02086F2C
	mov r0, #0x73
	lsl r0, r0, #2
	add r1, sp, #0xc
	ldr r0, [r6, r0]
	add r1, #2
	add r2, sp, #0xc
	bl ManagedSprite_GetPositionXY
	ldr r1, [sp]
	mov r0, #0x2e
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	add r2, r1, #0
	mov r1, #0xb7
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	cmp r1, r0
	bne _02086ED2
	add r5, #8
	lsl r0, r5, #0x10
	asr r5, r0, #0x10
	b _02086EE8
_02086ED2:
	cmp r4, r1
	ble _02086EE2
	cmp r4, r0
	bge _02086EE2
	add r5, #0x14
	lsl r0, r5, #0x10
	asr r5, r0, #0x10
	b _02086EE8
_02086EE2:
	add r5, #8
	lsl r0, r5, #0x10
	asr r5, r0, #0x10
_02086EE8:
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _02086F02
	mov r0, #0x73
	lsl r0, r0, #2
	add r3, sp, #0xc
	mov r2, #0
	ldrsh r2, [r3, r2]
	ldr r0, [r6, r0]
	add r1, r5, #0
	bl ManagedSprite_SetPositionXY
	b _02086F24
_02086F02:
	add r1, sp, #0xc
	mov r0, #2
	ldrsh r0, [r1, r0]
	sub r1, r5, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r1, r0, #1
	mov r0, #0x75
	lsl r0, r0, #2
	strh r1, [r6, r0]
	mov r1, #0
	add r0, r0, #2
	strh r1, [r6, r0]
	mov r0, #0x76
	mov r1, #2
	lsl r0, r0, #2
	strb r1, [r6, r0]
_02086F24:
	ldr r0, [sp, #8]
	add r6, #0x1c
	add r0, r0, #1
	str r0, [sp, #8]
_02086F2C:
	mov r0, #0x2d
	ldr r1, [sp]
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	add r4, r4, #1
	add r7, #0x1c
	cmp r4, r0
	bge _02086F3E
	b _02086E12
_02086F3E:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02086DE4

#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_0208B1AC.inc"
	.include "global.inc"

	.public gOverlayTemplate_Battle
	.public gNatureStatMods

	.text
	.public _02103A2C
	.public _02103A3C
	.public _02103A50
	.public _02103A70
	.public _02104C68
	.public _021105B0
	.public sub_0208B1AC
	.public sub_0208B258
	.public sub_0208B278
	.public sub_0208B2C0
	.public sub_0208B400
	.public sub_0208B448
	.public sub_0208B48C
	.public sub_0208B4EC
	.public sub_0208B55C
	.public sub_0208B5A8
	.public sub_0208B714
	.public sub_0208B74C
	.public sub_0208B780
	.public sub_0208B85C
	.public sub_0208B89C
	.public sub_0208B9C8
	.public sub_0208BA60
	.public sub_0208BA88
	.public sub_0208BAD8
	.public sub_0208BB24
	.public sub_0208BB8C
	.public sub_0208BBDC
	.public sub_0208BC78
	.public sub_0208BCB4
	.public sub_0208BCD4
	.public sub_0208BD38
	.public sub_0208BDC8
	.public sub_0208BE00
	.public sub_0208BE70
	.public sub_0208BECC
	.public sub_0208BF9C
	.public sub_0208BFD0
	.public sub_0208C068
	.public sub_0208C0A4
	.public sub_0208C0E8
	.public sub_0208C208
	.public sub_0208C250
	.public sub_0208C2A0
	.public sub_0208C320
	.public sub_0208C380
	.public sub_0208C3C0

	thumb_func_start sub_0208B780
sub_0208B780: ; 0x0208B780
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, r0, #0
	ldr r0, [sp, #0x2c]
	add r5, r1, #0
	add r1, r2, #0
	add r2, r3, #0
	str r0, [sp]
	ldr r3, [sp, #0x28]
	add r0, sp, #8
	bl sub_0208B85C
	str r0, [sp, #4]
	lsl r0, r5, #2
	mov r6, #0
	add r4, sp, #8
	add r5, r7, r0
_0208B7A2:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0208B7B2
	ldr r0, [r5]
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _0208B808
_0208B7B2:
	cmp r0, #1
	bne _0208B7C8
	ldr r0, [r5]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [r5]
	mov r1, #3
	bl Sprite_SetAnimCtrlSeq
	b _0208B808
_0208B7C8:
	cmp r0, #2
	bne _0208B7DE
	ldr r0, [r5]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [r5]
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	b _0208B808
_0208B7DE:
	cmp r0, #3
	bne _0208B7F4
	ldr r0, [r5]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [r5]
	mov r1, #1
	bl Sprite_SetAnimCtrlSeq
	b _0208B808
_0208B7F4:
	cmp r0, #4
	bne _0208B808
	ldr r0, [r5]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [r5]
	mov r1, #2
	bl Sprite_SetAnimCtrlSeq
_0208B808:
	add r6, r6, #1
	add r4, r4, #1
	add r5, r5, #4
	cmp r6, #5
	blt _0208B7A2
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _0208B828
	ldr r0, [sp, #0x30]
	mov r1, #0
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	bl Sprite_SetDrawFlag
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0208B828:
	ble _0208B842
	ldr r0, [sp, #0x30]
	mov r1, #1
	lsl r4, r0, #2
	ldr r0, [r7, r4]
	bl Sprite_SetDrawFlag
	ldr r0, [r7, r4]
	mov r1, #4
	bl Sprite_SetAnimCtrlSeq
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0208B842:
	bge _0208B858
	ldr r0, [sp, #0x30]
	mov r1, #1
	lsl r4, r0, #2
	ldr r0, [r7, r4]
	bl Sprite_SetDrawFlag
	ldr r0, [r7, r4]
	mov r1, #5
	bl Sprite_SetAnimCtrlSeq
_0208B858:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0208B780

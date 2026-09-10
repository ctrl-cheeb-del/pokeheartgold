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

	thumb_func_start sub_0208BBDC
sub_0208BBDC: ; 0x0208BBDC
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0208BC70 ; =0x000007BD
	ldrb r0, [r4, r0]
	lsl r0, r0, #0x1c
	lsr r2, r0, #0x1c
	cmp r2, #4
	beq _0208BBF2
	cmp r2, #5
	beq _0208BC2E
	b _0208BC52
_0208BBF2:
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #2
	ldr r0, _0208BC74 ; =0x00000428
	bne _0208BC12
	lsl r2, r2, #5
	add r2, #0x28
	lsl r2, r2, #0x10
	ldr r0, [r4, r0]
	mov r1, #0x44
	asr r2, r2, #0x10
	bl Sprite_SetPositionXY
	b _0208BC22
_0208BC12:
	lsl r2, r2, #5
	add r2, #0x18
	lsl r2, r2, #0x10
	ldr r0, [r4, r0]
	mov r1, #0x44
	asr r2, r2, #0x10
	bl Sprite_SetPositionXY
_0208BC22:
	ldr r0, _0208BC74 ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	pop {r4, pc}
_0208BC2E:
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #2
	bne _0208BC6E
	ldr r0, _0208BC74 ; =0x00000428
	mov r1, #0xdc
	ldr r0, [r4, r0]
	mov r2, #0xb0
	bl Sprite_SetPositionXY
	ldr r0, _0208BC74 ; =0x00000428
	mov r1, #3
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	pop {r4, pc}
_0208BC52:
	ldr r0, _0208BC74 ; =0x00000428
	lsl r2, r2, #5
	add r2, #0x18
	lsl r2, r2, #0x10
	ldr r0, [r4, r0]
	mov r1, #0x44
	asr r2, r2, #0x10
	bl Sprite_SetPositionXY
	ldr r0, _0208BC74 ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
_0208BC6E:
	pop {r4, pc}
	.balign 4, 0
_0208BC70: .word 0x000007BD
_0208BC74: .word 0x00000428
	thumb_func_end sub_0208BBDC

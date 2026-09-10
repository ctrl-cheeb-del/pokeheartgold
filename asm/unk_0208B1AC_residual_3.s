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

	thumb_func_start sub_0208B4EC
sub_0208B4EC: ; 0x0208B4EC
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0xa
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	lsl r0, r0, #4
	lsr r0, r0, #4
	cmp r0, #7
	bne _0208B514
	ldr r0, _0208B554 ; =0x00000454
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208B558 ; =0x00000524
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	pop {r4, pc}
_0208B514:
	cmp r0, #0
	ldr r0, _0208B558 ; =0x00000524
	beq _0208B540
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0208B554 ; =0x00000454
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	mov r1, #0xa
	lsl r1, r1, #6
	ldr r0, _0208B554 ; =0x00000454
	ldr r1, [r4, r1]
	ldr r0, [r4, r0]
	lsl r1, r1, #4
	lsr r1, r1, #4
	bl Sprite_SetAnimCtrlSeq
	pop {r4, pc}
_0208B540:
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, _0208B554 ; =0x00000454
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	pop {r4, pc}
	.balign 4, 0
_0208B554: .word 0x00000454
_0208B558: .word 0x00000524
	thumb_func_end sub_0208B4EC

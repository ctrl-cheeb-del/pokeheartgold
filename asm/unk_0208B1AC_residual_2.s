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

	thumb_func_start sub_0208B2C0
sub_0208B2C0: ; 0x0208B2C0
	push {r3, r4, r5, r6, r7, lr}
	ldr r6, _0208B3C4 ; =_02103A70
	ldr r7, _0208B3C8 ; =0x00000404
	add r5, r0, #0
	mov r4, #0
_0208B2CA:
	mov r0, #0xff
	mov r1, #1
	lsl r0, r0, #2
	lsl r1, r1, #0xa
	mov r2, #0x28
	mul r2, r4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, r2
	bl SpriteSystem_CreateSpriteFromResourceHeader
	lsl r1, r4, #2
	add r1, r5, r1
	str r0, [r1, r7]
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0x73
	blo _0208B2CA
	add r0, r5, #0
	bl sub_0208B55C
	ldr r0, _0208B3CC ; =0x0000042C
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3D0 ; =0x000004A8
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3D4 ; =0x000004AC
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	mov r0, #0x4b
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3D8 ; =0x000004B4
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3DC ; =0x000004B8
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3E0 ; =0x000004BC
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	mov r0, #0x13
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3E4 ; =0x000004C4
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3E8 ; =0x000004C8
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3EC ; =0x000004CC
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	mov r0, #0x4d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0x51
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3F0 ; =0x00000514
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3F4 ; =0x00000518
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0208B3F8 ; =0x0000051C
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	mov r0, #0x52
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r5, #0
	bl sub_0208B714
	add r0, r5, #0
	bl sub_0208B74C
	ldr r0, _0208B3FC ; =0x00000524
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0208B3C4: .word _02103A70
_0208B3C8: .word 0x00000404
_0208B3CC: .word 0x0000042C
_0208B3D0: .word 0x000004A8
_0208B3D4: .word 0x000004AC
_0208B3D8: .word 0x000004B4
_0208B3DC: .word 0x000004B8
_0208B3E0: .word 0x000004BC
_0208B3E4: .word 0x000004C4
_0208B3E8: .word 0x000004C8
_0208B3EC: .word 0x000004CC
_0208B3F0: .word 0x00000514
_0208B3F4: .word 0x00000518
_0208B3F8: .word 0x0000051C
_0208B3FC: .word 0x00000524
	thumb_func_end sub_0208B2C0


	thumb_func_start sub_0208B400
sub_0208B400: ; 0x0208B400
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	ldrb r0, [r1, #0x11]
	cmp r0, #2
	beq _0208B430
	ldrb r0, [r1, #0x14]
	ldr r1, _0208B43C ; =_021105B0
	ldr r2, _0208B440 ; =_021105B0 + 1
	lsl r3, r0, #1
	ldr r0, _0208B444 ; =0x00000428
	ldrb r1, [r1, r3]
	ldrb r2, [r2, r3]
	ldr r0, [r4, r0]
	bl Sprite_SetPositionXY
	ldr r0, _0208B444 ; =0x00000428
	mov r1, #2
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	pop {r4, pc}
_0208B430:
	ldr r0, _0208B444 ; =0x00000428
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	pop {r4, pc}
	.balign 4, 0
_0208B43C: .word _021105B0
_0208B440: .word _021105B0 + 1
_0208B444: .word 0x00000428
	thumb_func_end sub_0208B400

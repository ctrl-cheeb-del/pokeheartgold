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

	thumb_func_start sub_0208B5A8
sub_0208B5A8: ; 0x0208B5A8
	push {r3, r4, r5, r6, r7, lr}
	ldr r6, _0208B6FC ; =0x00000404
	add r5, r0, #0
	mov r4, #0xb
	mov r7, #0
_0208B5B2:
	lsl r0, r4, #2
	add r0, r5, r0
	ldr r0, [r0, r6]
	add r1, r7, #0
	bl thunk_Sprite_SetDrawFlag
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #0x13
	bls _0208B5B2
	mov r0, #0xa
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	beq _0208B5D6
	b _0208B6F8
_0208B5D6:
	ldr r0, _0208B700 ; =0x000007BC
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _0208B5E4
	cmp r0, #1
	beq _0208B634
	pop {r3, r4, r5, r6, r7, pc}
_0208B5E4:
	mov r0, #0x43
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #1
	bl thunk_Sprite_SetDrawFlag
	mov r0, #9
	lsl r0, r0, #6
	ldrb r1, [r5, r0]
	add r0, r0, #1
	ldrb r0, [r5, r0]
	cmp r1, r0
	bne _0208B60E
	mov r0, #0x43
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x6c
	mov r2, #0x30
	bl Sprite_SetPositionXY
	pop {r3, r4, r5, r6, r7, pc}
_0208B60E:
	mov r0, #0x43
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x5b
	mov r2, #0x30
	bl Sprite_SetPositionXY
	ldr r0, _0208B704 ; =0x00000434
	mov r1, #1
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetDrawFlag
	ldr r0, _0208B704 ; =0x00000434
	mov r1, #0x7d
	ldr r0, [r5, r0]
	mov r2, #0x30
	bl Sprite_SetPositionXY
	pop {r3, r4, r5, r6, r7, pc}
_0208B634:
	mov r7, #0x99
	mov r4, #0
	lsl r7, r7, #2
_0208B63A:
	lsl r0, r4, #1
	add r0, r5, r0
	ldrh r0, [r0, r7]
	cmp r0, #0
	beq _0208B684
	mov r1, #3
	bl GetMoveAttr
	add r3, r0, #0
	add r1, r4, #0
	add r1, #0xd
	add r2, r4, #5
	lsl r1, r1, #0x18
	lsl r2, r2, #0x18
	lsl r3, r3, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl sub_0208BA88
	lsl r0, r4, #2
	add r6, r5, r0
	ldr r0, _0208B708 ; =0x00000438
	mov r1, #1
	ldr r0, [r6, r0]
	bl thunk_Sprite_SetDrawFlag
	ldr r0, _0208B708 ; =0x00000438
	lsl r2, r4, #5
	add r2, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r6, r0]
	mov r1, #0x18
	asr r2, r2, #0x10
	bl Sprite_SetPositionXY
_0208B684:
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #4
	blo _0208B63A
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrh r0, [r0, #0x18]
	cmp r0, #0
	beq _0208B6C8
	mov r1, #3
	bl GetMoveAttr
	add r3, r0, #0
	lsl r3, r3, #0x18
	add r0, r5, #0
	mov r1, #0x11
	mov r2, #9
	lsr r3, r3, #0x18
	bl sub_0208BA88
	ldr r0, _0208B70C ; =0x00000448
	mov r1, #1
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetDrawFlag
	ldr r0, _0208B70C ; =0x00000448
	mov r1, #0x18
	ldr r0, [r5, r0]
	mov r2, #0xa0
	bl Sprite_SetPositionXY
	b _0208B6D2
_0208B6C8:
	ldr r0, _0208B70C ; =0x00000448
	mov r1, #0
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetDrawFlag
_0208B6D2:
	mov r0, #0x43
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0xc8
	mov r2, #0x18
	bl Sprite_SetPositionXY
	ldr r0, _0208B704 ; =0x00000434
	mov r1, #0xea
	ldr r0, [r5, r0]
	mov r2, #0x18
	bl Sprite_SetPositionXY
	ldr r0, _0208B710 ; =0x0000044C
	mov r1, #0xe8
	ldr r0, [r5, r0]
	mov r2, #0x28
	bl Sprite_SetPositionXY
_0208B6F8:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0208B6FC: .word 0x00000404
_0208B700: .word 0x000007BC
_0208B704: .word 0x00000434
_0208B708: .word 0x00000438
_0208B70C: .word 0x00000448
_0208B710: .word 0x0000044C
	thumb_func_end sub_0208B5A8

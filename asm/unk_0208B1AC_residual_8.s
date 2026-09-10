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

	thumb_func_start sub_0208BCD4
sub_0208BCD4: ; 0x0208BCD4
	push {r3, r4, r5, r6, r7, lr}
	mov r2, #0x1f
	lsl r2, r2, #6
	mov r1, #0
	strb r1, [r0, r2]
	add r3, r2, #3
	strb r1, [r0, r3]
	add r3, r2, #2
	strb r1, [r0, r3]
	ldr r3, _0208BD30 ; =0x0000027A
	ldrb r3, [r0, r3]
	cmp r3, #0
	bne _0208BCF4
	add r2, r2, #1
	strb r1, [r0, r2]
	b _0208BD0A
_0208BCF4:
	cmp r3, #0xff
	bne _0208BD00
	mov r3, #0xc
	add r1, r2, #1
	strb r3, [r0, r1]
	b _0208BD0A
_0208BD00:
	mov r1, #0xc
	mul r1, r3
	asr r3, r1, #8
	add r1, r2, #1
	strb r3, [r0, r1]
_0208BD0A:
	ldr r7, _0208BD34 ; =0x00000404
	add r5, r0, #0
	mov r4, #0x1d
	add r5, #0x74
	add r6, r7, #0
_0208BD14:
	ldr r0, [r5, r7]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r5, r6]
	mov r1, #0
	bl Sprite_SetAnimationFrame
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0x28
	bls _0208BD14
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0208BD30: .word 0x0000027A
_0208BD34: .word 0x00000404
	thumb_func_end sub_0208BCD4


	thumb_func_start sub_0208BD38
sub_0208BD38: ; 0x0208BD38
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r4, #0
	add r5, r6, #0
	mov r7, #1
_0208BD42:
	mov r0, #0x9f
	lsl r0, r0, #2
	ldrh r1, [r6, r0]
	add r0, r7, #0
	lsl r0, r4
	tst r0, r1
	beq _0208BD5E
	mov r0, #0x46
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r7, #0
	bl Sprite_SetAnimCtrlSeq
	b _0208BD6A
_0208BD5E:
	mov r0, #0x46
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
_0208BD6A:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blo _0208BD42
	mov r0, #0xa
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	lsl r1, r0, #2
	lsr r1, r1, #0x1f
	cmp r1, #1
	bne _0208BD92
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	bne _0208BD92
	ldr r0, _0208BDC0 ; =0x000004D4
	mov r1, #1
	ldr r0, [r6, r0]
	bl thunk_Sprite_SetDrawFlag
	b _0208BD9C
_0208BD92:
	ldr r0, _0208BDC0 ; =0x000004D4
	mov r1, #0
	ldr r0, [r6, r0]
	bl thunk_Sprite_SetDrawFlag
_0208BD9C:
	mov r0, #0xa
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	lsr r0, r0, #0x1e
	cmp r0, #2
	ldr r0, _0208BDC4 ; =0x000004D8
	bne _0208BDB4
	ldr r0, [r6, r0]
	mov r1, #1
	bl thunk_Sprite_SetDrawFlag
	pop {r3, r4, r5, r6, r7, pc}
_0208BDB4:
	ldr r0, [r6, r0]
	mov r1, #0
	bl thunk_Sprite_SetDrawFlag
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0208BDC0: .word 0x000004D4
_0208BDC4: .word 0x000004D8
	thumb_func_end sub_0208BD38

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

	thumb_func_start sub_0208BECC
sub_0208BECC: ; 0x0208BECC
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl sub_0208A520
	add r7, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r1, [r6, r0]
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	beq _0208BEEC
	cmp r0, #1
	beq _0208BEF8
	cmp r0, #2
	beq _0208BEF2
	b _0208BEFC
_0208BEEC:
	mov r0, #1
	str r0, [sp]
	b _0208BEFC
_0208BEF2:
	mov r0, #0
	str r0, [sp]
	b _0208BEFC
_0208BEF8:
	ldrb r0, [r1, #0x13]
	str r0, [sp]
_0208BEFC:
	ldr r0, [sp]
	mov r4, #0
	cmp r0, #0
	ble _0208BF7A
	add r5, r6, #0
_0208BF06:
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r1, [r6, r0]
	ldrb r0, [r1, #0x11]
	cmp r0, #0
	beq _0208BF1C
	cmp r0, #1
	beq _0208BF4A
	cmp r0, #2
	beq _0208BF36
	b _0208BF64
_0208BF1C:
	add r0, r6, #0
	bl sub_0208A520
	add r7, r0, #0
	bl Pokemon_GetIconPalette
	add r1, r0, #0
	ldr r0, _0208BF98 ; =0x00000528
	add r1, #0xc
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetPaletteOverride
	b _0208BF64
_0208BF36:
	add r0, r7, #0
	bl Boxmon_GetIconPalette
	add r1, r0, #0
	ldr r0, _0208BF98 ; =0x00000528
	add r1, #0xc
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetPaletteOverride
	b _0208BF64
_0208BF4A:
	ldr r0, [r1]
	add r1, r4, #0
	bl Party_GetMonByIndex
	add r7, r0, #0
	bl Pokemon_GetIconPalette
	add r1, r0, #0
	ldr r0, _0208BF98 ; =0x00000528
	add r1, #0xc
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetPaletteOverride
_0208BF64:
	add r2, r4, #0
	add r0, r6, #0
	add r1, r7, #0
	add r2, #0x49
	bl sub_0208BE00
	ldr r0, [sp]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r0
	blt _0208BF06
_0208BF7A:
	cmp r4, #6
	bge _0208BF96
	lsl r0, r4, #2
	add r5, r6, r0
	ldr r6, _0208BF98 ; =0x00000528
	mov r7, #0
_0208BF86:
	ldr r0, [r5, r6]
	add r1, r7, #0
	bl thunk_Sprite_SetDrawFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blt _0208BF86
_0208BF96:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0208BF98: .word 0x00000528
	thumb_func_end sub_0208BECC

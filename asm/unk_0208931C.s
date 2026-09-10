#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_02088288.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0208931C
sub_0208931C: ; 0x0208931C
	push {r3, r4, r5, lr}
	ldr r3, _02089418 ; =gSystem
	mov r1, #0x20
	ldr r2, [r3, #0x4c]
	add r4, r0, #0
	add r5, r2, #0
	tst r5, r1
	beq _02089336
	sub r1, #0x21
	bl sub_0208AB58
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_02089336:
	mov r1, #0x10
	tst r1, r2
	beq _02089346
	mov r1, #1
	bl sub_0208AB58
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_02089346:
	mov r1, #0x40
	add r5, r2, #0
	tst r5, r1
	beq _02089358
	sub r1, #0x43
	bl sub_0208AB58
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_02089358:
	mov r1, #0x80
	tst r1, r2
	beq _02089368
	mov r1, #3
	bl sub_0208AB58
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_02089368:
	ldr r2, [r3, #0x48]
	mov r1, #3
	tst r1, r2
	beq _02089382
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	add r0, r4, #0
	mov r1, #0xb
	bl sub_0208B0F4
	pop {r3, r4, r5, pc}
_02089382:
	bl sub_0208AEC4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bgt _02089392
	beq _02089414
	b _020893F8
_02089392:
	cmp r0, #0xb
	bgt _020893F8
	cmp r0, #9
	blt _020893F8
	beq _020893A6
	cmp r0, #0xa
	beq _020893C6
	cmp r0, #0xb
	beq _020893E6
	b _020893F8
_020893A6:
	ldr r0, _0208941C ; =0x00000504
	ldr r0, [r4, r0]
	bl Sprite_GetDrawFlag
	cmp r0, #1
	bne _02089414
	ldr r0, _02089420 ; =0x000005DC
	bl PlaySE
	ldr r0, _0208941C ; =0x00000504
	mov r1, #2
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0xd
	pop {r3, r4, r5, pc}
_020893C6:
	ldr r0, _02089424 ; =0x00000508
	ldr r0, [r4, r0]
	bl Sprite_GetDrawFlag
	cmp r0, #1
	bne _02089414
	ldr r0, _02089420 ; =0x000005DC
	bl PlaySE
	ldr r0, _02089424 ; =0x00000508
	mov r1, #3
	ldr r0, [r4, r0]
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0xe
	pop {r3, r4, r5, pc}
_020893E6:
	mov r0, #0x25
	lsl r0, r0, #6
	bl PlaySE
	add r0, r4, #0
	mov r1, #0xb
	bl sub_0208B0F4
	pop {r3, r4, r5, pc}
_020893F8:
	ldr r1, _02089428 ; =0x000007C4
	ldrb r2, [r4, r1]
	cmp r2, r0
	beq _02089410
	strb r0, [r4, r1]
	ldr r0, _02089420 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	mov r1, #0
	bl sub_0208AB58
_02089410:
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_02089414:
	mov r0, #0xc
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02089418: .word gSystem
_0208941C: .word 0x00000504
_02089420: .word 0x000005DC
_02089424: .word 0x00000508
_02089428: .word 0x000007C4
	thumb_func_end sub_0208931C

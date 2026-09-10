#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_02088288.inc"
	.include "global.inc"
	.public _0208A404
	.public _0208A41A
	.public _0208A420
	.public _0208A456
	.public _0208A46C
	.public _0208A480
	.public _0208A486
	.public _0208A4B4
	.public _0208A4C8
	.public _0208A4DE
	.public _0208A4E4
	.public _0208A51A
	.public _0208A538
	.public _0208A546
	.public _0208A550
	.public _0208A55E
	.public _0208A57A
	.public _0208A5B6
	.public _0208A5D6
	.public _0208A5E2
	.public _0208A616
	.public _0208A62A
	.public _0208A630
	.public _0208A634
	.public _0208A638
	.public _0208A652
	.public _0208A69C
	.public _0208A6BC
	.public _0208A6C8
	.public _0208A706
	.public _0208A70C
	.public _0208A710
	.public _0208A714
	.public _0208A718
	.public _0208A742
	.public _0208A746
	.public _0208A748
	.public _0208A74E
	.public _0208A75A
	.public _0208A760
	.public _0208A772
	.public _0208A790
	.public _0208A798
	.public _0208A7C4
	.public _0208A7D0
	.public _0208A7E0
	.public _0208A7F4
	.public _0208A816
	.public _0208A830
	.public _0208A85A
	.public _0208A868
	.public _0208A8F0
	.public _0208A93A
	.public _0208A948
	.public _0208A94C
	.public _0208A996
	.public _0208A9A4
	.public _0208A9BC
	.public _0208A9C0
	.public _0208A9DA
	.public _0208AA32
	.public _0208AA52
	.public _0208AA5E
	.public _0208AA86
	.public _0208AA8C
	.public _0208AA90
	.public _0208AA94
	.public _0208AA98
	.public _0208AAB2
	.public _0208AAE2
	.public _0208AB02
	.public _0208AB0E
	.public _0208AB4A
	.public _0208AB50
	.public _0208AB54
	.public _0208AB80
	.public _0208AB94
	.public _0208AB96
	.public _0208ABA0
	.public _0208ABCE
	.public _0208ABD4
	.public _0208ABFC
	.public _0208AC02
	.public _0208AC20
	.public _0208AC34
	.public _0208AC44
	.public _0208AC56
	.public _0208AC78
	.public _0208AC92
	.public _0208AC9A
	.public _0208ACB8
	.public _0208ACC0
	.public _0208ACC4
	.public _0208ACC8
	.public _0208ACCC
	.public _0208ACD0
	.public _0208ACD4
	.public _0208ACD8
	.public _0208ACF6
	.public _0208AD18
	.public _0208AD1E
	.public _0208AD30
	.public sub_0208A3F4
	.public sub_0208A45C
	.public sub_0208A4B8
	.public sub_0208A520
	.public sub_0208A564
	.public sub_0208A63C
	.public sub_0208A71C
	.public sub_0208A79C
	.public sub_0208A7F8
	.public sub_0208A834
	.public sub_0208A8F4
	.public sub_0208A950
	.public sub_0208A9C4
	.public sub_0208AA9C
	.public sub_0208AB58
	.public sub_0208ACDC
	.text
	.public sub_0208A3F4
	.public sub_0208A45C
	.public sub_0208A4B8
	.public sub_0208A520
	.public sub_0208A564
	.public sub_0208A63C
	.public sub_0208A79C
	.public sub_0208A8F4
	.public sub_0208A950
	.public sub_0208A9C4
	.public sub_0208AA9C
	.public sub_0208ACDC
	thumb_func_start sub_0208A7F8
sub_0208A7F8: ; 0x0208A7F8
	push {r3, r4, r5, lr}
	mov r2, #0
	add r4, r1, #0
	mvn r2, r2
	add r5, r0, #0
	cmp r4, r2
	bne _0208A816
	bl sub_0208DAD4
	ldr r0, _0208A830 ; =0x0000044C
	mov r1, #0
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetDrawFlag
	pop {r3, r4, r5, pc}
_0208A816:
	bl sub_0208D9A0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0208BB8C
	ldr r0, _0208A830 ; =0x0000044C
	mov r1, #1
	ldr r0, [r5, r0]
	bl thunk_Sprite_SetDrawFlag
	pop {r3, r4, r5, pc}
	nop
_0208A830: .word 0x0000044C
	thumb_func_end sub_0208A7F8
	thumb_func_start sub_0208A834
sub_0208A834: ; 0x0208A834
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	bl sub_0208A520
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	ldrb r1, [r1, #0x11]
	cmp r1, #2
	ldr r1, _0208A8F0 ; =0x000007BD
	bne _0208A85A
	ldrb r2, [r4, r1]
	lsl r1, r2, #0x1c
	lsl r2, r2, #0x18
	lsr r1, r1, #0x1c
	lsr r2, r2, #0x1c
	bl BoxMonSwapMoves
	b _0208A868
_0208A85A:
	ldrb r2, [r4, r1]
	lsl r1, r2, #0x1c
	lsl r2, r2, #0x18
	lsr r1, r1, #0x1c
	lsr r2, r2, #0x1c
	bl MonSwapMoves
_0208A868:
	ldr r0, _0208A8F0 ; =0x000007BD
	mov r1, #0x99
	ldrb r6, [r4, r0]
	lsl r1, r1, #2
	add r5, r4, r1
	lsl r2, r6, #0x1c
	lsl r6, r6, #0x18
	lsr r6, r6, #0x1c
	lsl r6, r6, #1
	lsr r3, r2, #0x1b
	add r6, r4, r6
	ldrh r2, [r5, r3]
	ldrh r6, [r6, r1]
	strh r6, [r5, r3]
	ldrb r3, [r4, r0]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x1c
	lsl r3, r3, #1
	add r3, r4, r3
	strh r2, [r3, r1]
	add r2, r1, #0
	add r2, #8
	ldrb r6, [r4, r0]
	add r5, r4, r2
	lsl r2, r6, #0x1c
	lsl r6, r6, #0x18
	lsr r6, r6, #0x1c
	add r7, r4, r6
	add r6, r1, #0
	lsr r3, r2, #0x1c
	add r6, #8
	ldrb r2, [r5, r3]
	ldrb r6, [r7, r6]
	strb r6, [r5, r3]
	ldrb r3, [r4, r0]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x1c
	add r5, r4, r3
	add r3, r1, #0
	add r3, #8
	strb r2, [r5, r3]
	add r2, r1, #0
	add r2, #0xc
	ldrb r6, [r4, r0]
	add r5, r4, r2
	lsl r2, r6, #0x1c
	lsl r6, r6, #0x18
	lsr r6, r6, #0x1c
	add r7, r4, r6
	add r6, r1, #0
	lsr r3, r2, #0x1c
	add r6, #0xc
	ldrb r2, [r5, r3]
	ldrb r6, [r7, r6]
	strb r6, [r5, r3]
	ldrb r0, [r4, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	add r3, r4, r0
	add r0, r1, #0
	add r0, #0xc
	strb r2, [r3, r0]
	sub r1, #0x38
	ldr r0, [r4, r1]
	mov r2, #1
	str r2, [r0, #0x38]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0208A8F0: .word 0x000007BD
	thumb_func_end sub_0208A834

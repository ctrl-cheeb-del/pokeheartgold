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
	thumb_func_start sub_0208A71C
sub_0208A71C: ; 0x0208A71C
	push {r4, r5, r6, r7}
	add r5, r0, #0
	ldr r0, _0208A798 ; =0x000007BD
	ldrb r0, [r5, r0]
	lsl r0, r0, #0x1c
	lsr r4, r0, #0x1c
	lsl r0, r4, #0x18
	asr r2, r0, #0x18
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r3, [r5, r0]
	ldrb r0, [r3, #0x12]
	cmp r0, #2
	bne _0208A746
	ldrh r0, [r3, #0x18]
	cmp r0, #0
	beq _0208A742
	mov r3, #4
	b _0208A748
_0208A742:
	mov r3, #3
	b _0208A748
_0208A746:
	mov r3, #3
_0208A748:
	mov r6, #0x99
	mov r0, #0
	lsl r6, r6, #2
_0208A74E:
	add r2, r2, r1
	lsl r2, r2, #0x18
	asr r2, r2, #0x18
	bpl _0208A75A
	add r2, r3, #0
	b _0208A760
_0208A75A:
	cmp r2, r3
	ble _0208A760
	add r2, r0, #0
_0208A760:
	cmp r2, #4
	beq _0208A772
	lsl r7, r2, #1
	add r7, r5, r7
	ldrh r7, [r7, r6]
	cmp r7, #0
	bne _0208A772
	cmp r2, r4
	bne _0208A74E
_0208A772:
	cmp r2, r4
	beq _0208A790
	ldr r3, _0208A798 ; =0x000007BD
	mov r1, #0xf
	ldrb r0, [r5, r3]
	bic r0, r1
	lsl r1, r2, #0x18
	lsr r2, r1, #0x18
	mov r1, #0xf
	and r1, r2
	orr r0, r1
	strb r0, [r5, r3]
	mov r0, #1
	pop {r4, r5, r6, r7}
	bx lr
_0208A790:
	mov r0, #0
	pop {r4, r5, r6, r7}
	bx lr
	nop
_0208A798: .word 0x000007BD
	thumb_func_end sub_0208A71C

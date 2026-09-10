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
	thumb_func_start sub_0208AB58
sub_0208AB58: ; 0x0208AB58
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _0208ACC4 ; =0x000007C4
	add r4, r1, #0
	add r1, r0, #1
	ldrb r7, [r5, r0]
	ldrb r6, [r5, r1]
	cmp r4, #1
	bne _0208AB80
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	cmp r1, #2
	beq _0208AB94
	ldr r0, _0208ACC4 ; =0x000007C4
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
	b _0208AC34
_0208AB80:
	mov r2, #0
	mvn r2, r2
	cmp r4, r2
	bne _0208ABA0
	add r0, r7, #0
	mov r1, #3
	bl _s32_div_f
	cmp r1, #0
	bne _0208AB96
_0208AB94:
	b _0208ACC0
_0208AB96:
	ldr r0, _0208ACC4 ; =0x000007C4
	ldrb r1, [r5, r0]
	sub r1, r1, #1
	strb r1, [r5, r0]
	b _0208AC34
_0208ABA0:
	cmp r4, #3
	bne _0208ABD4
	cmp r7, #6
	blo _0208ABCE
	add r2, r6, #1
	lsl r1, r2, #3
	add r1, r2, r1
	add r2, r0, #2
	ldrb r2, [r5, r2]
	cmp r1, r2
	bge _0208AC34
	add r1, r0, #1
	ldrb r1, [r5, r1]
	add r2, r1, #1
	add r1, r0, #1
	strb r2, [r5, r1]
	ldrb r0, [r5, r0]
	mov r1, #3
	bl _s32_div_f
	ldr r0, _0208ACC4 ; =0x000007C4
	strb r1, [r5, r0]
	b _0208AC34
_0208ABCE:
	add r1, r7, #3
	strb r1, [r5, r0]
	b _0208AC34
_0208ABD4:
	sub r1, r2, #2
	cmp r4, r1
	bne _0208AC02
	cmp r7, #2
	bhi _0208ABFC
	cmp r6, #0
	beq _0208AC34
	add r1, r0, #1
	ldrb r1, [r5, r1]
	sub r2, r1, #1
	add r1, r0, #1
	strb r2, [r5, r1]
	ldrb r0, [r5, r0]
	mov r1, #3
	bl _s32_div_f
	ldr r0, _0208ACC4 ; =0x000007C4
	add r1, r1, #6
	strb r1, [r5, r0]
	b _0208AC34
_0208ABFC:
	sub r1, r7, #3
	strb r1, [r5, r0]
	b _0208AC34
_0208AC02:
	cmp r4, #9
	bne _0208AC20
	add r2, r6, #1
	lsl r1, r2, #3
	add r1, r2, r1
	add r2, r0, #2
	ldrb r2, [r5, r2]
	cmp r1, r2
	bge _0208AC34
	add r1, r0, #1
	ldrb r1, [r5, r1]
	add r0, r0, #1
	add r1, r1, #1
	strb r1, [r5, r0]
	b _0208AC34
_0208AC20:
	sub r2, #8
	cmp r4, r2
	bne _0208AC34
	cmp r6, #0
	beq _0208AC34
	add r1, r0, #1
	ldrb r1, [r5, r1]
	add r0, r0, #1
	sub r1, r1, #1
	strb r1, [r5, r0]
_0208AC34:
	ldr r0, _0208ACC4 ; =0x000007C4
	ldrb r1, [r5, r0]
	cmp r7, r1
	bne _0208AC44
	add r0, r0, #1
	ldrb r0, [r5, r0]
	cmp r6, r0
	beq _0208AC56
_0208AC44:
	cmp r4, #9
	beq _0208AC56
	mov r0, #8
	mvn r0, r0
	cmp r4, r0
	beq _0208AC56
	ldr r0, _0208ACC8 ; =0x000005DC
	bl PlaySE
_0208AC56:
	ldr r1, _0208ACC4 ; =0x000007C4
	add r0, r5, #0
	ldrb r1, [r5, r1]
	bl sub_0208ACDC
	ldr r1, _0208ACCC ; =0x000007C7
	strb r0, [r5, r1]
	add r0, r5, #0
	bl sub_0208C380
	ldr r0, _0208ACD0 ; =0x000007C5
	ldrb r0, [r5, r0]
	cmp r6, r0
	beq _0208AC78
	add r0, r5, #0
	bl sub_0208C320
_0208AC78:
	add r0, r5, #0
	bl sub_0208D7C4
	ldr r0, _0208ACD0 ; =0x000007C5
	ldrb r0, [r5, r0]
	cmp r0, #0
	ldr r0, _0208ACD4 ; =0x00000504
	beq _0208AC92
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	b _0208AC9A
_0208AC92:
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0208AC9A:
	ldr r0, _0208ACD0 ; =0x000007C5
	ldrb r1, [r5, r0]
	add r0, r0, #1
	ldrb r0, [r5, r0]
	add r2, r1, #1
	lsl r1, r2, #3
	add r1, r2, r1
	cmp r1, r0
	ldr r0, _0208ACD8 ; =0x00000508
	bge _0208ACB8
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	pop {r3, r4, r5, r6, r7, pc}
_0208ACB8:
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0208ACC0:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0208ACC4: .word 0x000007C4
_0208ACC8: .word 0x000005DC
_0208ACCC: .word 0x000007C7
_0208ACD0: .word 0x000007C5
_0208ACD4: .word 0x00000504
_0208ACD8: .word 0x00000508
	thumb_func_end sub_0208AB58

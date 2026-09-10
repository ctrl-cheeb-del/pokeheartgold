#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_02085604.inc"
	.include "global.inc"

	.public gOverlayTemplate_Battle
	.public gNatureStatMods

	.public _02085656
	.public _02085684
	.public _020856A4
	.public _020856D6
	.public _020856F0
	.public _0208571C
	.public _02085770
	.public _02085788
	.public _02085790
	.public _020857AA
	.public _020857BE
	.public _020857EE
	.public _02085800
	.public _02085804
	.public _020858B8
	.public _020858F2
	.public _02085916
	.public _0208592A
	.public _02085930
	.public _0208595A
	.public _0208596E
	.public _02085988
	.public _0208598A
	.public _020859A2
	.public _020859E4
	.public _02085A0E
	.public _02085A1C
	.public _02085A2E
	.public _02085A56
	.public _02085A64
	.public _02085A82
	.public _02085AA2
	.public _02085ABA
	.public _02085ADA
	.public _02085AE4
	.public _02085AF0
	.public _02085B06
	.public _02085B1E
	.public _02085B2C
	.public _02085B42
	.public _02085B5A
	.public _02085B68
	.public _02085B84
	.public _02085BA6
	.public _02085BB8
	.public _02085BCC
	.public _02085BDA
	.public _02085BE0
	.public _02085BE4
	.public _02085BE8
	.public _02085C1C
	.public _02085C2C
	.public _02085C80
	.public _02085C82
	.public _02085CAA
	.public _02085CBC
	.public _02085CD4
	.public _02085CD6
	.public _02085CDE
	.public _02085CFE
	.public _02085D0E
	.public _02085D16
	.public _02085D28
	.public _02085D2C
	.public _02085D3C
	.public _02085D44
	.public _02085D4E
	.public _02085D52
	.public _02085D56
	.public _02085D72
	.public _02085D84
	.public _02085D8C
	.public _02085D8E
	.public _02085E0E
	.public _02085E28
	.public _02085E34
	.public _02085E3C
	.public _02085E52
	.public _02085E6E
	.public _02085E74
	.public _02085E9A
	.public _02085EAC
	.public _02085EB6
	.public _02085ED4
	.public _02085EDC
	.public _02085F00
	.public _02085F04
	.public _02085F08
	.public _02085F0C
	.public _02085F10
	.public _02085F14
	.public _02085F22
	.public _02085F2A
	.public _02085F6A
	.public _02085F78
	.public _02085F7C
	.public _02085FA8
	.public _02085FC0
	.public _02085FEC
	.public _02086044
	.public _020860A8
	.public _020860B6
	.public _020860CA
	.public _020860DC
	.public _02086100
	.public _0208614A
	.public _0208616C
	.public _02086170
	.public _02086174
	.public _02086178
	.public _0208617C
	.public _020861A0
	.public _020861A6
	.public _020861B4
	.public _020861B6
	.public _020861D0
	.public _020861DE
	.public _020861E6
	.public _02086200
	.public _0208621A
	.public _0208623E
	.public _020862D8
	.public _020862FA
	.public _02086308
	.public _02086314
	.public _0208631A
	.public _0208631C
	.public _02086320
	.public _02086324
	.public _02086346
	.public _0208634A
	.public _02086372
	.public _02086380
	.public _020863A6
	.public _020863B2
	.public _020863BA
	.public _020863D2
	.public _020863DC
	.public _020863E6
	.public _020863EE
	.public _0210271C
	.public _0210272C
	.public _02102768
	.public _0211055C
	.public _02110578
	.public sub_02085604
	.public sub_02085688
	.public sub_02085808
	.public sub_02085820
	.public sub_020858DC
	.public sub_02085938
	.public sub_02085974
	.public sub_02085BEC
	.public sub_02085C20
	.public sub_02085F80
	.public sub_02085FFC
	.public sub_020860B8
	.public sub_02086180
	.public sub_02086328
	.public sub_02086384
	.public sub_02086398
	.public sub_020863C0
	.text
	.public sub_02085604
	.public sub_02085808
	.public sub_02085820
	.public sub_020858DC
	.public sub_02085938
	.public sub_02085BEC
	.public sub_02085F80
	.public sub_02086328
	.public sub_02086384

	thumb_func_start sub_02086398
sub_02086398: ; 0x02086398
	push {r3, r4}
	mov r2, #0x2d
	lsl r2, r2, #4
	ldr r4, [r0, r2]
	mov r3, #0
	cmp r4, #0
	ble _020863BA
_020863A6:
	ldr r2, [r0, #4]
	cmp r1, r2
	bne _020863B2
	add r0, r3, #0
	pop {r3, r4}
	bx lr
_020863B2:
	add r3, r3, #1
	add r0, #0x1c
	cmp r3, r4
	blt _020863A6
_020863BA:
	mov r0, #0
	pop {r3, r4}
	bx lr
	thumb_func_end sub_02086398


	thumb_func_start sub_020863C0
sub_020863C0: ; 0x020863C0
	push {r3, r4, r5, r6}
	mov r2, #0x2d
	lsl r2, r2, #4
	ldr r6, [r0, r2]
	mov r5, #0
	add r4, r5, #0
	cmp r6, #0
	ble _020863EE
	mov r2, #1
_020863D2:
	ldr r3, [r0, #4]
	cmp r1, r3
	bne _020863DC
	add r5, r2, #0
	b _020863E6
_020863DC:
	cmp r5, #1
	bne _020863E6
	sub r0, r4, #1
	pop {r3, r4, r5, r6}
	bx lr
_020863E6:
	add r4, r4, #1
	add r0, #0x1c
	cmp r4, r6
	blt _020863D2
_020863EE:
	sub r0, r6, #1
	pop {r3, r4, r5, r6}
	bx lr
	thumb_func_end sub_020863C0

	.rodata

_0210271C:
	.word sub_02085820
	.word sub_02085938
	.word sub_02085974
	.word sub_020858DC
_0210272C:
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
	.byte 0x09, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x0B, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00
_02102768:
	.short 0x0020, 0x0050, 0x0014, 0x0014
	.short 0x0050, 0x0050, 0x0014, 0x0014
	.short 0x0080, 0x0050, 0x0014, 0x0014
	.short 0x00B0, 0x0050, 0x0014, 0x0014
	.short 0x00E0, 0x0050, 0x0014, 0x0014
	.short 0x0020, 0x0080, 0x0014, 0x0014
	.short 0x0050, 0x0080, 0x0014, 0x0014
	.short 0x0080, 0x0080, 0x0014, 0x0014
	.short 0x00B0, 0x0080, 0x0014, 0x0014
	.short 0x00E0, 0x0080, 0x0014, 0x0014
	.short 0x0040, 0x00B0, 0x003C, 0x000C
	.short 0x00C0, 0x00B0, 0x003C, 0x000C

	; File boundary

	.data

_0211055C:
	.byte 0x00, 0x00, 0x00, 0x3F
	.byte 0xCD, 0xCC, 0x4C, 0x3E, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x80, 0x3F, 0x9A, 0x99, 0x99, 0x3F
	.byte 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F
_02110578:
	.byte 0xCD, 0xCC, 0x4C, 0x3F, 0x9A, 0x99, 0x19, 0x3F
	.byte 0xCD, 0xCC, 0xCC, 0x3E, 0xCD, 0xCC, 0x4C, 0x3E, 0xCD, 0xCC, 0x4C, 0x3F, 0x00, 0x00, 0x80, 0x3F
	.byte 0x00, 0x00, 0x80, 0x3F

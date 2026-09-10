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

	thumb_func_start sub_02085688
sub_02085688: ; 0x02085688
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	mov r0, #0xdd
	lsl r0, r0, #2
	mov r1, #1
	str r1, [r4, r0]
	add r7, r0, #0
	mov r5, #0
	mov r1, #0xab
	add r3, r5, #0
	add r6, r4, #0
	sub r7, #0xca
	add r0, #0x48
	lsl r1, r1, #2
_020856A4:
	strh r5, [r6, r7]
	ldr r2, [r6, r0]
	add r3, r3, #1
	add r2, r5, r2
	lsl r2, r2, #0x10
	lsr r5, r2, #0x10
	strh r5, [r6, r1]
	add r6, r6, #4
	cmp r3, #5
	blt _020856A4
	mov r1, #0xf7
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	add r1, r1, #1
	bl sub_02085604
	mov r1, #0xfb
	lsl r1, r1, #2
	mov r0, #0x2d
	add r7, r1, #0
	mov r6, #0
	add r5, r4, #0
	lsl r0, r0, #4
	sub r7, #0x30
_020856D6:
	ldr r3, [r5, r7]
	cmp r3, #0
	beq _020856F0
	ldr r2, [r4, r0]
	add r6, r6, #1
	add r2, r2, r3
	str r2, [r4, r0]
	ldr r2, [r4, r1]
	add r5, r5, #4
	add r2, r2, #1
	str r2, [r4, r1]
	cmp r6, #4
	blt _020856D6
_020856F0:
	mov r0, #0xfb
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	ldr r7, _02085804 ; =0x000002A2
	sub r1, r1, #1
	str r1, [r4, r0]
	mov r1, #0x2d
	lsl r1, r1, #4
	ldr r2, [r4, r1]
	ldr r0, [r4, r0]
	sub r1, #0x30
	add r0, r2, r0
	lsl r2, r0, #3
	lsr r0, r2, #0x1f
	add r0, r2, r0
	asr r2, r0, #1
	mov r0, #0x70
	sub r0, r0, r2
	strh r0, [r4, r1]
	mov r6, #0
	add r3, r4, #0
	add r5, r4, #0
_0208571C:
	mov r0, #0xef
	lsl r0, r0, #2
	ldr r2, [r3, r0]
	add r0, #0x30
	ldr r0, [r4, r0]
	add r6, r6, #1
	lsl r1, r0, #3
	mov r0, #0x2d
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r3, r3, #4
	sub r0, r0, r2
	lsl r0, r0, #3
	lsl r2, r2, #5
	add r0, r0, r2
	add r1, r1, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r1, r0, #1
	mov r0, #0x70
	sub r0, r0, r1
	strh r0, [r5, r7]
	add r5, r5, #2
	cmp r6, #4
	blt _0208571C
	ldr r0, _02085804 ; =0x000002A2
	ldrsh r1, [r4, r0]
	add r1, #0xc
	strh r1, [r4, r0]
	mov r1, #0xfb
	lsl r1, r1, #2
	mov r0, #0
	ldr r1, [r4, r1]
	add r3, r0, #0
	cmp r1, #0
	ble _02085788
	mov r7, #7
	mov r6, #0xfb
	add r1, r4, #0
	add r2, r4, #0
	lsl r7, r7, #6
	lsl r6, r6, #2
_02085770:
	mov r5, #0xef
	lsl r5, r5, #2
	ldr r5, [r1, r5]
	add r3, r3, #1
	add r0, r0, r5
	sub r5, r0, #1
	str r5, [r2, r7]
	ldr r5, [r4, r6]
	add r1, r1, #4
	add r2, #0x1c
	cmp r3, r5
	blt _02085770
_02085788:
	mov r3, #0
	mov ip, r3
	str r4, [sp]
	add r2, r4, #0
_02085790:
	mov r1, #0xef
	ldr r5, [sp]
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r0, #0
	cmp r1, #0
	ble _020857BE
	mov r5, ip
	lsl r5, r5, #2
	add r7, r4, r5
	mov r5, ip
	add r1, r2, #0
	add r6, r5, #1
_020857AA:
	mov r5, #0xef
	str r6, [r1, #4]
	lsl r5, r5, #2
	ldr r5, [r7, r5]
	add r0, r0, #1
	add r1, #0x1c
	add r2, #0x1c
	add r3, r3, #1
	cmp r0, r5
	blt _020857AA
_020857BE:
	ldr r0, [sp]
	add r0, r0, #4
	str r0, [sp]
	mov r0, ip
	add r0, r0, #1
	mov ip, r0
	mov r0, #0x2d
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	cmp r3, r0
	blt _02085790
	mov r0, #0xf7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	cmp r0, #0
	ble _02085800
	mov r5, #0x3f
	lsl r5, r5, #4
	add r2, r5, #0
	add r3, r5, #0
	add r0, r4, #0
	sub r2, #0x34
	sub r3, #0x14
_020857EE:
	ldr r6, [r0, r2]
	ldr r7, [r4, r5]
	add r1, r1, #1
	add r6, r7, r6
	str r6, [r4, r5]
	ldr r6, [r4, r3]
	add r0, r0, #4
	cmp r1, r6
	blt _020857EE
_02085800:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02085804: .word 0x000002A2
	thumb_func_end sub_02085688

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

	thumb_func_start sub_02085974
sub_02085974: ; 0x02085974
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0xb2
	add r5, r0, #0
	lsl r1, r1, #2
	ldr r2, [r5, r1]
	cmp r2, #0
	beq _0208598A
	cmp r2, #1
	bne _02085988
	b _02085AF0
_02085988:
	b _02085B84
_0208598A:
	mov r1, #0
	add r2, r1, #0
	bl sub_02086AB4
	mov r0, #0x2d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r6, #0
	cmp r0, #0
	ble _02085A1C
	ldr r7, _02085BE0 ; =_0211055C
	add r4, r5, #0
_020859A2:
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _02085A0E
	mov r1, #0x14
	mov r2, #0x16
	ldrsh r1, [r4, r1]
	ldrsh r2, [r4, r2]
	ldr r0, [r4, #0xc]
	bl ManagedSprite_OffsetPositionXY
	ldrb r0, [r4, #0x18]
	sub r0, r0, #1
	strb r0, [r4, #0x18]
	mov r0, #0xb7
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r6, r0
	blt _020859E4
	mov r0, #0x2e
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r6, r0
	bge _020859E4
	ldrb r0, [r4, #0x19]
	lsl r1, r0, #2
	ldr r1, [r7, r1]
	ldr r0, [r4, #0xc]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	ldrb r0, [r4, #0x19]
	add r0, r0, #1
	strb r0, [r4, #0x19]
_020859E4:
	mov r0, #0xb9
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r6, r0
	blt _02085A0E
	mov r0, #0xba
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r6, r0
	bge _02085A0E
	ldrb r0, [r4, #0x19]
	ldr r1, _02085BE4 ; =_02110578
	lsl r2, r0, #2
	ldr r1, [r1, r2]
	ldr r0, [r4, #0xc]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	ldrb r0, [r4, #0x19]
	add r0, r0, #1
	strb r0, [r4, #0x19]
_02085A0E:
	mov r0, #0x2d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r6, r6, #1
	add r4, #0x1c
	cmp r6, r0
	blt _020859A2
_02085A1C:
	mov r0, #0xfb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r6, #0
	cmp r0, #0
	ble _02085A64
	mov r7, #0x76
	add r4, r5, #0
	lsl r7, r7, #2
_02085A2E:
	ldrb r0, [r4, r7]
	cmp r0, #0
	beq _02085A56
	mov r1, #0x75
	ldr r2, _02085BE8 ; =0x000001D6
	mov r0, #0x73
	lsl r1, r1, #2
	lsl r0, r0, #2
	ldrsh r1, [r4, r1]
	ldrsh r2, [r4, r2]
	ldr r0, [r4, r0]
	bl ManagedSprite_OffsetPositionXY
	mov r0, #0x76
	lsl r0, r0, #2
	ldrb r0, [r4, r0]
	sub r1, r0, #1
	mov r0, #0x76
	lsl r0, r0, #2
	strb r1, [r4, r0]
_02085A56:
	mov r0, #0xfb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r6, r6, #1
	add r4, #0x1c
	cmp r6, r0
	blt _02085A2E
_02085A64:
	ldrb r0, [r5, #0x18]
	cmp r0, #0
	bne _02085AE4
	mov r0, #0xb7
	lsl r0, r0, #2
	ldr r6, [r5, r0]
	add r0, r0, #4
	ldr r0, [r5, r0]
	cmp r6, r0
	bge _02085AA2
	mov r0, #0x1c
	mul r0, r6
	mov r7, #0x2e
	add r4, r5, r0
	lsl r7, r7, #4
_02085A82:
	ldr r0, [r4]
	ldr r1, [r4, #8]
	bl sub_02086D98
	add r1, r0, #0
	ldr r0, [r4, #0xc]
	bl ManagedSprite_SetAnim
	ldr r0, [r4, #0xc]
	bl ManagedSprite_TickFrame
	ldr r0, [r5, r7]
	add r6, r6, #1
	add r4, #0x1c
	cmp r6, r0
	blt _02085A82
_02085AA2:
	mov r0, #0xb9
	lsl r0, r0, #2
	ldr r6, [r5, r0]
	add r0, r0, #4
	ldr r0, [r5, r0]
	cmp r6, r0
	bge _02085ADA
	mov r0, #0x1c
	mul r0, r6
	mov r7, #0xba
	add r4, r5, r0
	lsl r7, r7, #2
_02085ABA:
	ldr r0, [r4]
	ldr r1, [r4, #8]
	bl sub_02086D98
	add r1, r0, #0
	ldr r0, [r4, #0xc]
	bl ManagedSprite_SetAnim
	ldr r0, [r4, #0xc]
	bl ManagedSprite_TickFrame
	ldr r0, [r5, r7]
	add r6, r6, #1
	add r4, #0x1c
	cmp r6, r0
	blt _02085ABA
_02085ADA:
	mov r0, #0xb2
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	add r1, r1, #1
	str r1, [r5, r0]
_02085AE4:
	mov r0, #0xb3
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	add r1, r1, #1
	str r1, [r5, r0]
	b _02085BDA
_02085AF0:
	add r0, r1, #0
	add r0, #0x14
	add r1, #0x18
	ldr r6, [r5, r0]
	ldr r0, [r5, r1]
	cmp r6, r0
	bge _02085B2C
	mov r0, #0x1c
	mul r0, r6
	ldr r7, _02085BE0 ; =_0211055C
	add r4, r5, r0
_02085B06:
	ldrb r0, [r4, #0x19]
	cmp r0, #6
	beq _02085B1E
	lsl r1, r0, #2
	ldr r1, [r7, r1]
	ldr r0, [r4, #0xc]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	ldrb r0, [r4, #0x19]
	add r0, r0, #1
	strb r0, [r4, #0x19]
_02085B1E:
	mov r0, #0x2e
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r6, r6, #1
	add r4, #0x1c
	cmp r6, r0
	blt _02085B06
_02085B2C:
	mov r0, #0xb9
	lsl r0, r0, #2
	ldr r6, [r5, r0]
	add r0, r0, #4
	ldr r0, [r5, r0]
	cmp r6, r0
	bge _02085B68
	mov r0, #0x1c
	mul r0, r6
	ldr r7, _02085BE4 ; =_02110578
	add r4, r5, r0
_02085B42:
	ldrb r0, [r4, #0x19]
	cmp r0, #6
	beq _02085B5A
	lsl r1, r0, #2
	ldr r1, [r7, r1]
	ldr r0, [r4, #0xc]
	add r2, r1, #0
	bl ManagedSprite_SetAffineScale
	ldrb r0, [r4, #0x19]
	add r0, r0, #1
	strb r0, [r4, #0x19]
_02085B5A:
	mov r0, #0xba
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r6, r6, #1
	add r4, #0x1c
	cmp r6, r0
	blt _02085B42
_02085B68:
	mov r1, #0xb3
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	add r0, r0, #1
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	cmp r0, #6
	bne _02085BDA
	sub r0, r1, #4
	ldr r0, [r5, r0]
	add r2, r0, #1
	sub r0, r1, #4
	str r2, [r5, r0]
	b _02085BDA
_02085B84:
	bl sub_02086F44
	mov r1, #0xed
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	cmp r0, #0
	bne _02085BA6
	sub r1, r1, #4
	ldr r1, [r5, r1]
	add r0, r5, #0
	bl sub_02086398
	add r1, r0, #0
	add r0, r5, #0
	bl sub_02086AE4
	b _02085BB8
_02085BA6:
	sub r1, r1, #4
	ldr r1, [r5, r1]
	add r0, r5, #0
	bl sub_020863C0
	add r1, r0, #0
	add r0, r5, #0
	bl sub_02086AE4
_02085BB8:
	mov r0, #0xb5
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02085BCC
	add r0, r5, #0
	mov r1, #0
	mov r2, #1
	bl sub_02086AB4
_02085BCC:
	add r0, r5, #0
	bl sub_02086384
	add r0, r5, #0
	mov r1, #1
	bl sub_02085808
_02085BDA:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02085BE0: .word _0211055C
_02085BE4: .word _02110578
_02085BE8: .word 0x000001D6
	thumb_func_end sub_02085974

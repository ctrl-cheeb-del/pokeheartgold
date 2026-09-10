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

	thumb_func_start sub_02085FFC
sub_02085FFC: ; 0x02085FFC
	push {r3, r4, r5, r6, r7, lr}
	mov r2, #0x9a
	lsl r2, r2, #2
	add r5, r0, #0
	mov r1, #1
	add r3, r2, #0
	str r1, [r5, r2]
	mov r0, #0
	add r3, #0x18
	strb r0, [r5, r3]
	add r3, r2, #0
	add r3, #0x6c
	ldr r3, [r5, r3]
	cmp r3, #0
	bne _02086044
	add r0, r2, #0
	add r0, #0x68
	ldr r0, [r5, r0]
	sub r3, r0, #1
	add r0, r2, #0
	sub r0, #0x54
	str r3, [r5, r0]
	sub r2, #0x54
	ldr r2, [r5, r2]
	mov r0, #0x1c
	mul r0, r2
	add r0, r5, r0
	mov r2, #0xeb
	ldr r3, [r0, #4]
	lsl r2, r2, #2
	str r1, [r5, r2]
	add r0, r2, #4
	str r3, [r5, r0]
	add r2, #8
	str r1, [r5, r2]
	pop {r3, r4, r5, r6, r7, pc}
_02086044:
	sub r2, #0x54
	ldr r6, [r5, r2]
	mov r1, #0x1c
	add r4, r6, #0
	mul r4, r1
	str r0, [r5, r4]
	add r1, r5, r4
	ldr r0, [r5, r4]
	ldr r1, [r1, #8]
	bl sub_02086D98
	add r1, r0, #0
	add r0, r5, r4
	ldr r0, [r0, #0xc]
	bl ManagedSprite_SetAnim
	add r0, r5, r4
	ldr r7, [r0, #4]
	mov r0, #0x3f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r6, r0
	ble _020860B6
	sub r1, r6, #1
	mov r0, #0x1c
	add r4, r1, #0
	mul r4, r0
	add r1, r5, r4
	ldr r0, [r5, r4]
	ldr r1, [r1, #8]
	bl sub_02086D98
	add r1, r0, #0
	add r0, r5, r4
	ldr r0, [r0, #0xc]
	bl ManagedSprite_SetAnim
	add r0, r5, r4
	ldr r3, [r0, #4]
	cmp r7, r3
	beq _020860A8
	mov r1, #0xeb
	lsl r1, r1, #2
	mov r2, #1
	str r2, [r5, r1]
	add r0, r1, #4
	str r3, [r5, r0]
	add r1, #8
	str r2, [r5, r1]
	pop {r3, r4, r5, r6, r7, pc}
_020860A8:
	mov r0, #0xeb
	mov r1, #2
	lsl r0, r0, #2
	str r1, [r5, r0]
	sub r1, r6, #1
	add r0, r0, #4
	str r1, [r5, r0]
_020860B6:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02085FFC


	thumb_func_start sub_020860B8
sub_020860B8: ; 0x020860B8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x68
	str r0, [sp, #4]
	mov r2, #0xc1
	ldr r1, [sp, #4]
	lsl r2, r2, #2
	add r1, r1, r2
	ldr r2, [sp, #4]
	mov r0, #0
_020860CA:
	add r0, r0, #1
	str r1, [r2, #0x10]
	add r1, r1, #4
	add r2, #0x1c
	cmp r0, #0x10
	blt _020860CA
	ldr r4, _0208616C ; =_02102768
	add r3, sp, #8
	mov r2, #0x30
_020860DC:
	ldrh r1, [r4]
	add r4, r4, #2
	strh r1, [r3]
	add r3, r3, #2
	sub r2, r2, #1
	bne _020860DC
	cmp r0, #0x1c
	bge _0208614A
	add r2, sp, #8
	lsl r1, r0, #3
	add r1, r2, r1
	mov r7, #0x7f
	ldr r2, [sp, #4]
	lsl r3, r0, #2
	mvn r7, r7
	add r2, r2, r3
	ldr r4, _02086170 ; =0x00000307
	add r3, r7, #4
_02086100:
	mov r5, #0x7d
	mov r6, #0x79
	mvn r5, r5
	mvn r6, r6
	ldrsh r5, [r1, r5]
	ldrsh r6, [r1, r6]
	add r0, r0, #1
	sub r6, r5, r6
	mov r5, #0xc1
	lsl r5, r5, #2
	strb r6, [r2, r5]
	mov r5, #0x7f
	mov r6, #0x7b
	mvn r5, r5
	mvn r6, r6
	ldrsh r5, [r1, r5]
	ldrsh r6, [r1, r6]
	sub r6, r5, r6
	ldr r5, _02086174 ; =0x00000306
	strb r6, [r2, r5]
	mov r5, #0x7d
	mov r6, #0x79
	mvn r5, r5
	mvn r6, r6
	ldrsh r5, [r1, r5]
	ldrsh r6, [r1, r6]
	add r6, r5, r6
	ldr r5, _02086178 ; =0x00000305
	strb r6, [r2, r5]
	ldrsh r6, [r1, r7]
	ldrsh r5, [r1, r3]
	add r1, #8
	add r5, r6, r5
	strb r5, [r2, r4]
	add r2, r2, #4
	cmp r0, #0x1c
	blt _02086100
_0208614A:
	mov r0, #0x6c
	str r0, [sp]
	mov r1, #0xc1
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	add r0, r0, r1
	ldr r2, _0208617C ; =sub_02086180
	ldr r3, [sp, #4]
	mov r1, #0x1c
	bl TouchHitboxController_Create
	mov r2, #3
	ldr r1, [sp, #4]
	lsl r2, r2, #8
	str r0, [r1, r2]
	add sp, #0x68
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0208616C: .word _02102768
_02086170: .word 0x00000307
_02086174: .word 0x00000306
_02086178: .word 0x00000305
_0208617C: .word sub_02086180
	thumb_func_end sub_020860B8


	thumb_func_start sub_02086180
sub_02086180: ; 0x02086180
	push {r3, r4, r5, r6, r7, lr}
	add r4, r2, #0
	mov r2, #0xb
	lsl r2, r2, #6
	add r5, r0, #0
	ldr r0, [r4, r2]
	cmp r0, #1
	bne _020861B4
	add r0, r2, #0
	add r0, #0xb4
	ldr r0, [r4, r0]
	cmp r0, #1
	beq _020861A0
	mov r0, #1
	add r2, #0xb4
	str r0, [r4, r2]
_020861A0:
	cmp r1, #0
	beq _020861A6
	b _0208631A
_020861A6:
	cmp r5, #0x10
	bhs _020861E6
	mov r1, #0x3f
	lsl r1, r1, #4
	ldr r0, [r4, r1]
	cmp r5, r0
	bhs _020861B6
_020861B4:
	b _0208631A
_020861B6:
	mov r0, #0x1c
	mul r0, r5
	add r3, r4, r0
	ldr r0, [r3, #8]
	cmp r0, #1
	bne _020861D0
	add r0, r1, #0
	mov r2, #2
	sub r0, #0x44
	str r2, [r4, r0]
	sub r1, #0x40
	str r5, [r4, r1]
	b _020861DE
_020861D0:
	add r0, r1, #0
	mov r2, #1
	sub r0, #0x44
	str r2, [r4, r0]
	ldr r0, [r3, #4]
	sub r1, #0x40
	str r0, [r4, r1]
_020861DE:
	ldr r0, _0208631C ; =0x000005E5
	bl PlaySE
	pop {r3, r4, r5, r6, r7, pc}
_020861E6:
	cmp r5, #0x1a
	bne _02086200
	mov r0, #0x91
	mov r1, #0
	lsl r0, r0, #2
	strh r1, [r4, r0]
	mov r1, #2
	add r0, r0, #2
	strh r1, [r4, r0]
	ldr r0, _0208631C ; =0x000005E5
	bl PlaySE
	b _0208623E
_02086200:
	cmp r5, #0x1b
	bne _0208621A
	mov r0, #0x91
	mov r1, #3
	lsl r0, r0, #2
	strh r1, [r4, r0]
	mov r1, #2
	add r0, r0, #2
	strh r1, [r4, r0]
	ldr r0, _02086320 ; =0x000005E2
	bl PlaySE
	b _0208623E
_0208621A:
	add r0, r5, #0
	sub r0, #0x10
	mov r1, #5
	bl _u32_div_f
	mov r0, #0x91
	lsl r0, r0, #2
	strh r1, [r4, r0]
	add r0, r5, #0
	sub r0, #0x10
	mov r1, #5
	bl _u32_div_f
	ldr r1, _02086324 ; =0x00000246
	strh r0, [r4, r1]
	ldr r0, _0208631C ; =0x000005E5
	bl PlaySE
_0208623E:
	cmp r5, #0x10
	blo _02086308
	cmp r5, #0x19
	bhi _02086308
	mov r0, #0xb5
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	cmp r1, #0
	beq _0208631A
	sub r0, #0xc0
	ldr r7, [r4, r0]
	mov r0, #0x1c
	add r6, r7, #0
	mul r6, r0
	add r0, r5, #0
	sub r0, #0xf
	str r0, [r4, r6]
	add r1, r4, r6
	ldr r0, [r4, r6]
	ldr r1, [r1, #8]
	bl sub_02086D98
	add r1, r0, #0
	add r0, r4, r6
	ldr r0, [r0, #0xc]
	bl ManagedSprite_SetAnim
	mov r1, #1
	add r0, r4, #0
	add r2, r1, #0
	bl sub_02086AB4
	sub r5, #0x10
	add r0, r4, #0
	add r1, r5, #0
	bl sub_02086B2C
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl sub_02086AB4
	add r0, r4, #0
	mov r1, #2
	mov r2, #1
	bl sub_02086AB4
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #2
	bl sub_02086B6C
	mov r0, #0x96
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #3
	bl ManagedSprite_SetAnim
	add r0, r4, r6
	ldr r2, [r0, #4]
	mov r0, #0x2d
	lsl r0, r0, #4
	ldr r3, [r4, r0]
	add r1, r7, #1
	cmp r1, r3
	bne _020862D8
	add r1, r0, #0
	mov r2, #1
	add r1, #0xdc
	str r2, [r4, r1]
	add r1, r0, #0
	mov r2, #0
	add r1, #0xe0
	str r2, [r4, r1]
	add r0, #0xe4
	str r2, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_020862D8:
	mov r3, #0x1c
	mul r3, r1
	add r3, r4, r3
	ldr r3, [r3, #4]
	cmp r2, r3
	beq _020862FA
	add r1, r0, #0
	mov r2, #1
	add r1, #0xdc
	str r2, [r4, r1]
	add r1, r0, #0
	add r1, #0xe0
	str r3, [r4, r1]
	mov r1, #0
	add r0, #0xe4
	str r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_020862FA:
	add r2, r0, #0
	mov r3, #2
	add r2, #0xdc
	str r3, [r4, r2]
	add r0, #0xe0
	str r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_02086308:
	cmp r5, #0x1a
	bne _02086314
	add r0, r4, #0
	bl sub_02085FFC
	pop {r3, r4, r5, r6, r7, pc}
_02086314:
	add r0, r4, #0
	bl sub_02085F80
_0208631A:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0208631C: .word 0x000005E5
_02086320: .word 0x000005E2
_02086324: .word 0x00000246
	thumb_func_end sub_02086180

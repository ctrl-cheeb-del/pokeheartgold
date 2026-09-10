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

	thumb_func_start sub_02085C20
sub_02085C20: ; 0x02085C20
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	ldr r5, _02085F00 ; =_0210272C
	add r4, r0, #0
	add r3, sp, #4
	mov r2, #7
_02085C2C:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02085C2C
	ldr r0, [r5]
	mov r1, #0x14
	str r0, [r3]
	mov r3, #0x91
	lsl r3, r3, #2
	add r0, r3, #2
	ldrsh r0, [r4, r0]
	ldrsh r7, [r4, r3]
	mov r6, #0
	mov ip, r0
	mul r1, r0
	add r0, sp, #4
	lsl r2, r7, #2
	add r0, r0, r1
	ldr r5, [r2, r0]
	add r0, r3, #0
	add r0, #0x7c
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _02085C80
	mov r2, #0xeb
	lsl r2, r2, #2
	ldr r0, [r4, r2]
	cmp r0, #1
	beq _02085C80
	add r0, r2, #0
	sub r0, #0x38
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _02085CBC
	ldr r0, _02085F04 ; =gSystem
	ldr r0, [r0, #0x48]
	cmp r0, #0
	beq _02085C80
	bl System_GetTouchHeld
	cmp r0, #0
	beq _02085C82
_02085C80:
	b _02085F78
_02085C82:
	mov r0, #0xdd
	add r1, r6, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r4, #0
	add r1, r5, #0
	bl sub_02086B2C
	sub r5, #0xa
	cmp r5, #1
	bhi _02085CAA
	mov r0, #0x23
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	cmp r1, #2
	beq _02085D8C
	mov r1, #2
	add sp, #0x40
	str r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_02085CAA:
	mov r0, #0x23
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	cmp r1, #1
	beq _02085D8C
	mov r1, #1
	add sp, #0x40
	str r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_02085CBC:
	ldr r0, _02085F04 ; =gSystem
	mov r1, #0x40
	ldr r0, [r0, #0x4c]
	tst r1, r0
	beq _02085CDE
	mov r0, ip
	cmp r0, #0
	ble _02085CD4
	add r0, r3, #2
	ldrsh r0, [r4, r0]
	sub r1, r0, #1
	b _02085CD6
_02085CD4:
	mov r1, #2
_02085CD6:
	add r0, r3, #2
	strh r1, [r4, r0]
	mov r6, #1
	b _02085F2A
_02085CDE:
	mov r1, #0x80
	tst r1, r0
	beq _02085CFE
	add r0, r3, #2
	ldrsh r0, [r4, r0]
	add r1, r0, #1
	add r0, r3, #2
	strh r1, [r4, r0]
	ldrsh r0, [r4, r0]
	mov r1, #3
	bl _s32_div_f
	ldr r0, _02085F08 ; =0x00000246
	mov r6, #1
	strh r1, [r4, r0]
	b _02085F2A
_02085CFE:
	mov r1, #0x10
	tst r1, r0
	beq _02085D2C
	cmp r5, #0xa
	bne _02085D0E
	mov r0, #3
	strh r0, [r4, r3]
	b _02085D28
_02085D0E:
	cmp r5, #0xb
	bne _02085D16
	strh r6, [r4, r3]
	b _02085D28
_02085D16:
	add r0, r7, #1
	strh r0, [r4, r3]
	ldrsh r0, [r4, r3]
	mov r1, #5
	bl _s32_div_f
	mov r0, #0x91
	lsl r0, r0, #2
	strh r1, [r4, r0]
_02085D28:
	mov r6, #1
	b _02085F2A
_02085D2C:
	mov r1, #0x20
	tst r1, r0
	beq _02085D56
	cmp r5, #0xa
	bne _02085D3C
	mov r0, #3
	strh r0, [r4, r3]
	b _02085D52
_02085D3C:
	cmp r5, #0xb
	bne _02085D44
	strh r6, [r4, r3]
	b _02085D52
_02085D44:
	cmp r7, #0
	ble _02085D4E
	sub r0, r7, #1
	strh r0, [r4, r3]
	b _02085D52
_02085D4E:
	mov r0, #4
	strh r0, [r4, r3]
_02085D52:
	mov r6, #1
	b _02085F2A
_02085D56:
	ldr r1, _02085F04 ; =gSystem
	ldr r7, [r1, #0x48]
	mov r1, #1
	tst r1, r7
	beq _02085E3C
	cmp r5, #0xa
	bne _02085D72
	add r0, r4, #0
	bl sub_02085FFC
	ldr r0, _02085F0C ; =0x000005E5
	bl PlaySE
	b _02085F2A
_02085D72:
	cmp r5, #0xb
	bne _02085D84
	add r0, r4, #0
	bl sub_02085F80
	ldr r0, _02085F10 ; =0x000005E2
	bl PlaySE
	b _02085F2A
_02085D84:
	sub r2, #0xd8
	ldr r0, [r4, r2]
	cmp r0, #0
	bne _02085D8E
_02085D8C:
	b _02085F78
_02085D8E:
	sub r3, #0x30
	ldr r0, [r4, r3]
	mov r1, #0x1c
	add r7, r0, #0
	str r0, [sp]
	mul r7, r1
	add r0, r5, #1
	str r0, [r4, r7]
	add r0, r4, #0
	mov r1, #1
	add r2, r6, #0
	bl sub_02086AB4
	add r0, r4, #0
	mov r1, #2
	mov r2, #1
	bl sub_02086AB4
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #2
	bl sub_02086B6C
	add r1, r4, r7
	ldr r0, [r4, r7]
	ldr r1, [r1, #8]
	bl sub_02086D98
	add r1, r0, #0
	add r0, r4, r7
	ldr r0, [r0, #0xc]
	bl ManagedSprite_SetAnim
	mov r0, #0x96
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #3
	bl ManagedSprite_SetAnim
	add r0, r4, r7
	ldr r3, [r0, #4]
	ldr r0, [sp]
	add r2, r0, #1
	mov r0, #0x2d
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	cmp r2, r1
	bne _02085E0E
	add r1, r0, #0
	mov r6, #1
	add r1, #0xdc
	str r6, [r4, r1]
	add r1, r0, #0
	mov r2, #0
	add r1, #0xe0
	str r2, [r4, r1]
	add r1, r0, #0
	mov r2, #3
	sub r1, #0x8c
	strh r2, [r4, r1]
	mov r1, #2
	sub r0, #0x8a
	strh r1, [r4, r0]
	b _02085F2A
_02085E0E:
	mov r1, #0x1c
	mul r1, r2
	add r1, r4, r1
	ldr r1, [r1, #4]
	cmp r3, r1
	beq _02085E28
	add r2, r0, #0
	mov r3, #1
	add r2, #0xdc
	str r3, [r4, r2]
	add r0, #0xe0
	str r1, [r4, r0]
	b _02085E34
_02085E28:
	add r1, r0, #0
	mov r3, #2
	add r1, #0xdc
	str r3, [r4, r1]
	add r0, #0xe0
	str r2, [r4, r0]
_02085E34:
	ldr r0, _02085F0C ; =0x000005E5
	bl PlaySE
	b _02085F2A
_02085E3C:
	mov r1, #2
	add r5, r7, #0
	tst r5, r1
	beq _02085E52
	add r0, r4, #0
	bl sub_02085FFC
	ldr r0, _02085F0C ; =0x000005E5
	bl PlaySE
	b _02085F2A
_02085E52:
	lsl r5, r1, #8
	tst r5, r0
	beq _02085EB6
	add r0, r3, #0
	sub r0, #0x30
	ldr r1, [r4, r0]
	add r0, r2, #0
	add r0, #0x44
	ldr r0, [r4, r0]
	cmp r1, r0
	bne _02085E6E
	sub r2, #0xdc
	ldr r0, [r4, r2]
	b _02085E74
_02085E6E:
	add r0, r3, #0
	sub r0, #0x30
	ldr r0, [r4, r0]
_02085E74:
	sub r0, r0, #1
	sub r3, #0x30
	str r0, [r4, r3]
	mov r0, #0x85
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x1c
	mul r1, r0
	add r2, r4, r1
	ldr r1, [r2, #8]
	cmp r1, #1
	bne _02085E9A
	mov r1, #0xeb
	mov r2, #2
	lsl r1, r1, #2
	str r2, [r4, r1]
	add r1, r1, #4
	str r0, [r4, r1]
	b _02085EAC
_02085E9A:
	mov r1, #0xeb
	lsl r1, r1, #2
	mov r3, #1
	str r3, [r4, r1]
	add r0, r1, #4
	ldr r2, [r2, #4]
	add r1, #8
	str r2, [r4, r0]
	str r3, [r4, r1]
_02085EAC:
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
	b _02085F2A
_02085EB6:
	add r1, #0xfe
	tst r0, r1
	beq _02085F2A
	add r1, r2, #0
	add r0, r3, #0
	sub r1, #0xdc
	sub r0, #0x30
	ldr r1, [r4, r1]
	ldr r0, [r4, r0]
	sub r1, r1, #1
	cmp r0, r1
	bne _02085ED4
	add r2, #0x44
	ldr r0, [r4, r2]
	b _02085EDC
_02085ED4:
	add r0, r3, #0
	sub r0, #0x30
	ldr r0, [r4, r0]
	add r0, r0, #1
_02085EDC:
	sub r3, #0x30
	str r0, [r4, r3]
	mov r0, #0x85
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x1c
	mul r1, r0
	add r2, r4, r1
	ldr r1, [r2, #8]
	cmp r1, #1
	bne _02085F14
	mov r1, #0xeb
	mov r2, #2
	lsl r1, r1, #2
	str r2, [r4, r1]
	add r1, r1, #4
	str r0, [r4, r1]
	b _02085F22
	.balign 4, 0
_02085F00: .word _0210272C
_02085F04: .word gSystem
_02085F08: .word 0x00000246
_02085F0C: .word 0x000005E5
_02085F10: .word 0x000005E2
_02085F14:
	mov r0, #0xeb
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r4, r0]
	ldr r1, [r2, #4]
	add r0, r0, #4
	str r1, [r4, r0]
_02085F22:
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
_02085F2A:
	cmp r6, #1
	bne _02085F78
	mov r0, #0x5e
	lsl r0, r0, #4
	bl PlaySE
	ldr r1, _02085F7C ; =0x00000246
	mov r0, #0x14
	ldrsh r2, [r4, r1]
	sub r1, r1, #2
	ldrsh r1, [r4, r1]
	mul r0, r2
	add r2, sp, #4
	lsl r1, r1, #2
	add r0, r2, r0
	ldr r5, [r1, r0]
	add r0, r4, #0
	add r1, r5, #0
	bl sub_02086B2C
	sub r5, #0xa
	cmp r5, #1
	bhi _02085F6A
	mov r0, #0x23
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	cmp r1, #2
	beq _02085F78
	mov r1, #2
	add sp, #0x40
	str r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_02085F6A:
	mov r0, #0x23
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	cmp r1, #1
	beq _02085F78
	mov r1, #1
	str r1, [r4, r0]
_02085F78:
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02085F7C: .word 0x00000246
	thumb_func_end sub_02085C20

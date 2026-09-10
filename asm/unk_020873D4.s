#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_02087284.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020873D4
sub_020873D4: ; 0x020873D4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x50
	add r6, r1, #0
	add r0, r6, #0
	add r0, #0xf0
	ldr r0, [r0]
	cmp r0, #0
	bne _020873E6
	b _02087632
_020873E6:
	ldr r0, [r6, #0x10]
	mov r4, #0
	str r4, [sp, #0x1c]
	cmp r0, #0
	bgt _020873F2
	b _02087632
_020873F2:
	add r0, r6, #0
	mov r7, #0x3f
	str r0, [sp, #0x30]
	add r0, #0xec
	add r5, r6, #0
	lsl r7, r7, #0x18
	str r0, [sp, #0x30]
_02087400:
	cmp r4, #0
	beq _02087410
	mov r0, #0x18
	ldrsh r0, [r5, r0]
	strh r0, [r5, #0x28]
	mov r0, #0x1a
	ldrsh r0, [r5, r0]
	strh r0, [r5, #0x2a]
_02087410:
	ldr r0, [r5, #0x24]
	ldr r3, [r6, #0x20]
	add r1, sp, #0x4c
	add r2, sp, #0x48
	bl ManagedSprite_GetPositionFxXYWithSubscreenOffset
	ldr r0, [sp, #0x4c]
	bl _fflt
	ldr r1, _02087638 ; =0x45800000
	bl _fdiv
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x48]
	bl _fflt
	ldr r1, _02087638 ; =0x45800000
	bl _fdiv
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x1c]
	sub r0, r4, r0
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fmul
	add r1, r0, #0
	mov r0, #0x41
	lsl r0, r0, #0x18
	bl _fsub
	mov r1, #1
	lsl r1, r1, #0x1e
	bl _fdiv
	add r1, sp, #0x44
	str r1, [sp]
	add r1, sp, #0x40
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	mov r0, #0x28
	mov r1, #0x2a
	ldrsh r0, [r5, r0]
	ldrsh r1, [r5, r1]
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl sub_020872DC
	cmp r0, #0
	beq _020874EE
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	bne _020874EE
	ldr r0, [sp, #0x40]
	mov r1, #0
	bl _fgr
	ldr r0, _02087638 ; =0x45800000
	bls _020874A0
	ldr r1, [sp, #0x40]
	bl _fmul
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	str r0, [sp, #0x14]
	b _020874AE
_020874A0:
	ldr r1, [sp, #0x40]
	bl _fmul
	add r1, r7, #0
	bl _fsub
	str r0, [sp, #0x14]
_020874AE:
	ldr r0, [sp, #0x44]
	mov r1, #0
	bl _fgr
	ldr r0, _02087638 ; =0x45800000
	bls _020874CA
	ldr r1, [sp, #0x44]
	bl _fmul
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _020874D6
_020874CA:
	ldr r1, [sp, #0x44]
	bl _fmul
	add r1, r7, #0
	bl _fsub
_020874D6:
	bl _ffix
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x14]
	bl _ffix
	add r2, r0, #0
	ldr r0, [r5, #0x24]
	ldr r1, [sp, #0x28]
	bl ManagedSprite_AddSpritePrecisePositionXY
	b _02087626
_020874EE:
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	beq _020874FA
	cmp r0, #1
	beq _020875CA
	b _02087620
_020874FA:
	add r1, sp, #0x3c
	ldr r0, [r5, #0x24]
	ldr r3, [r6, #0x20]
	add r1, #2
	add r2, sp, #0x3c
	bl ManagedSprite_GetPositionXYWithSubscreenOffset
	add r0, r6, #0
	add r0, #0xe8
	ldr r0, [r0]
	str r0, [sp, #0x18]
	cmp r0, #0xff
	bne _0208758E
	add r0, r6, #0
	add r0, #0xe8
	str r4, [r0]
	mov r0, #0x28
	add r2, sp, #0x3c
	mov r1, #2
	ldrsh r0, [r6, r0]
	ldrsh r1, [r2, r1]
	sub r0, r0, r1
	cmp r0, #0
	ble _0208753C
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	str r0, [sp, #0x10]
	b _0208754A
_0208753C:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
	str r0, [sp, #0x10]
_0208754A:
	mov r0, #0x2a
	add r2, sp, #0x3c
	mov r1, #0
	ldrsh r0, [r6, r0]
	ldrsh r1, [r2, r1]
	sub r0, r0, r1
	cmp r0, #0
	ble _0208756A
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	add r0, r7, #0
	bl _fadd
	b _02087576
_0208756A:
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r7, #0
	bl _fsub
_02087576:
	bl _ffix
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x10]
	bl _ffix
	add r1, r0, #0
	ldr r0, [sp, #0x2c]
	bl FX_Atan2Idx
	str r0, [r5, #0x30]
	b _020875AC
_0208758E:
	mov r0, #0x2d
	ldr r1, [r6, #0x10]
	lsl r0, r0, #4
	bl _s32_div_f
	ldr r1, [sp, #0x18]
	add r2, r6, #0
	lsl r1, r1, #4
	add r2, #0xec
	add r1, r6, r1
	ldr r2, [r2]
	ldr r1, [r1, #0x30]
	mul r2, r0
	sub r0, r1, r2
	str r0, [r5, #0x30]
_020875AC:
	mov r1, #0x2d
	ldr r0, [r5, #0x30]
	lsl r1, r1, #4
	bl _s32_div_f
	ldr r0, [sp, #0x30]
	str r1, [r5, #0x30]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x30]
	str r1, [r0]
	ldr r0, [r5, #0x2c]
	add r0, r0, #1
	str r0, [r5, #0x2c]
	b _02087620
_020875CA:
	ldr r0, [r5, #0x30]
	mov r1, #0x2d
	add r0, r0, #4
	lsl r1, r1, #4
	str r0, [r5, #0x30]
	bl _s32_div_f
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
	str r1, [r5, #0x30]
	bl GF_SinDeg
	mov r1, #0x28
	ldrsh r1, [r6, r1]
	lsl r1, r1, #0xc
	str r1, [sp, #0x34]
	add r1, r6, #0
	add r1, #0xfc
	ldr r1, [r1]
	mul r0, r1
	str r0, [sp, #0x38]
	ldr r0, [r5, #0x30]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_CosDeg
	mov r1, #0x2a
	ldrsh r1, [r6, r1]
	ldr r2, [sp, #0x34]
	lsl r3, r1, #0xc
	mov r1, #1
	lsl r1, r1, #8
	ldr r1, [r6, r1]
	mul r0, r1
	ldr r1, [sp, #0x38]
	mov ip, r0
	add r1, r2, r1
	mov r2, ip
	add r2, r3, r2
	ldr r0, [r5, #0x24]
	ldr r3, [r6, #0x20]
	bl ManagedSprite_SetPositionFxXYWithSubscreenOffset
_02087620:
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
_02087626:
	ldr r0, [r6, #0x10]
	add r4, r4, #1
	add r5, #0x10
	cmp r4, r0
	bge _02087632
	b _02087400
_02087632:
	add sp, #0x50
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02087638: .word 0x45800000
	thumb_func_end sub_020873D4

#include "config.h"
	.include "asm/macros.inc"
	.include "unk_02030A98.inc"
	.include "global.inc"

	.bss

	.public _021D2AFC
_021D2AFC:
	.space 0x1628

	.text

	thumb_func_start sub_0203164C
sub_0203164C: ; 0x0203164C
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	ldrb r0, [r5, #0x1e]
	add r4, r1, #0
	mov r6, #0
	cmp r0, #0
	bne _020316CE
	ldrh r0, [r5, #0x20]
	strh r0, [r4]
	ldrh r0, [r5, #0x22]
	strh r0, [r4, #2]
	ldrh r0, [r5, #0x24]
	strh r0, [r4, #4]
	ldrh r0, [r5, #0x26]
	strh r0, [r4, #6]
	ldrh r0, [r4]
	cmp r0, #5
	blo _02031676
	add r6, r6, #1
	b _020316AA
_02031676:
	ldrh r0, [r4, #2]
	cmp r0, #0x13
	bls _02031680
	add r6, r6, #1
	b _020316AA
_02031680:
	ldrh r0, [r4, #4]
	ldr r1, _020316E8 ; =0x0000FFFF
	cmp r0, r1
	beq _02031694
	add r1, sp, #4
	add r2, sp, #0
	bl GetCategoryAndMsgNoByECWordIdx
	cmp r0, #0
	beq _020316A8
_02031694:
	ldrh r0, [r4, #6]
	ldr r1, _020316E8 ; =0x0000FFFF
	cmp r0, r1
	beq _020316AA
	add r1, sp, #4
	add r2, sp, #0
	bl GetCategoryAndMsgNoByECWordIdx
	cmp r0, #0
	bne _020316AA
_020316A8:
	add r6, r6, #1
_020316AA:
	cmp r6, #0
	ble _020316C8
	add r0, r4, #0
	mov r1, #4
	bl MailMsg_Init_WithBank
	mov r0, #0
	strh r0, [r4, #2]
	ldr r0, _020316EC ; =0x0000011F
	mov r1, #0x63
	bl GetECWordIndexByPair
	strh r0, [r4, #4]
	ldr r0, _020316E8 ; =0x0000FFFF
	strh r0, [r4, #6]
_020316C8:
	add sp, #8
	mov r0, #0
	pop {r4, r5, r6, pc}
_020316CE:
	mov r0, #0x28
	add r1, r2, #0
	bl String_New
	add r5, #0x20
	add r1, r5, #0
	mov r2, #0x28
	add r4, r0, #0
	bl CopyU16ArrayToStringN
	add r0, r4, #0
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
_020316E8: .word 0x0000FFFF
_020316EC: .word 0x0000011F
	thumb_func_end sub_0203164C

	thumb_func_start sub_020316F0
sub_020316F0: ; 0x020316F0
	ldrb r0, [r0, #0x15]
	cmp r0, #1
	blo _020316FA
	cmp r0, #0xc
	bls _020316FC
_020316FA:
	mov r0, #1
_020316FC:
	bx lr
	.balign 4, 0
	thumb_func_end sub_020316F0

	thumb_func_start sub_02031700
sub_02031700: ; 0x02031700
	ldrb r0, [r0, #0x16]
	cmp r0, #0xf
	bls _02031708
	mov r0, #0
_02031708:
	bx lr
	.balign 4, 0
	thumb_func_end sub_02031700

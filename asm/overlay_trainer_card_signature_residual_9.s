#include "msgdata/msg/msg_0252.h"
	.include "asm/macros.inc"
	.include "overlay_trainer_card_signature.inc"
	.include "global.inc"

	.text
	.public TrainerCardSignature_Exit
	.public TrainerCardSignature_Init
	.public TrainerCardSignature_Main
	.public _021E94AC
	.public ov52_021E83C4
	.public ov52_021E84CC
	.public ov52_021E85DC
	.public ov52_021E870C
	.public ov52_021E888C
	.public ov52_021E8994
	.public ov52_021E89D4
	.public ov52_021E8BDC
	.public ov52_021E8DC4
	.public ov52_021E8E64
	.public ov52_021E8F2C
	.public ov52_021E8FAC
	.public ov52_021E9124
	.public ov52_021E9158
	.public ov52_021E9260
	.public ov52_021E927C
	.public ov52_021E9300
	.public ov52_021E9364
	.public ov52_021E94B2
	.public ov52_021E94BA
	.public ov52_021E94CC
	.public ov52_021E94DC
	.public ov52_021E94EC
	.public ov52_021E9508
	.public ov52_021E9524
	.public ov52_021E9540
	.public ov52_021E955C
	.public ov52_021E9578
	.public ov52_021E95A0
	.public ov52_021E96C0
	.public ov52_021E837C
	.public ov52_021E83A4
	.public ov52_021E8568
	.public ov52_021E85A0
	.public ov52_021E86DC
	.public ov52_021E8B94
	.public ov52_021E8BD8
	.public ov52_021E8CBC
	.public ov52_021E8CDC
	.public ov52_021E8CF4
	.public ov52_021E8D3C
	.public ov52_021E8D64
	.public ov52_021E8D8C
	.public ov52_021E8EDC
	.public ov52_021E8EFC
	.public ov52_021E9218
	.public ov52_021E921C
	.public ov52_021E925C
	.public ov52_021E92E8
	.public ov52_021E9424
	.public ov52_021E9488

	thumb_func_start ov52_021E9300
ov52_021E9300: ; 0x021E9300
	push {r3, r4, r5, r6, r7, lr}
	mov r7, #0
	add r5, r0, #0
	str r1, [sp]
	add r4, r7, #0
	strb r7, [r5]
	add r6, r7, #0
_021E930E:
	ldr r0, [sp]
	ldrb r1, [r0, r6]
	mov r0, #0xf
	and r0, r1
	cmp r0, #1
	bne _021E9324
	mov r0, #1
	ldrb r1, [r5]
	lsl r0, r4
	orr r0, r1
	strb r0, [r5]
_021E9324:
	ldr r0, [sp]
	ldrb r0, [r0, r6]
	asr r0, r0, #4
	cmp r0, #1
	bne _021E933A
	ldrb r0, [r5]
	add r2, r4, #1
	mov r1, #1
	lsl r1, r2
	orr r0, r1
	strb r0, [r5]
_021E933A:
	add r4, r4, #2
	cmp r4, #8
	bne _021E934A
	mov r0, #0
	add r5, r5, #1
	add r7, r7, #1
	strb r0, [r5]
	add r4, r0, #0
_021E934A:
	mov r0, #6
	lsl r0, r0, #0xa
	cmp r7, r0
	blt _021E9356
	bl GF_AssertFail
_021E9356:
	mov r0, #6
	add r6, r6, #1
	lsl r0, r0, #0xa
	cmp r6, r0
	blt _021E930E
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov52_021E9300


	thumb_func_start ov52_021E9364
ov52_021E9364: ; 0x021E9364
	push {r3, r4, r5, lr}
	ldr r1, _021E9410 ; =gSystem + 0x40
	add r4, r0, #0
	ldrh r0, [r1, #0x20]
	ldr r3, _021E9414 ; =0x0000FFFF
	cmp r0, r3
	beq _021E93FE
	ldrh r1, [r1, #0x22]
	cmp r1, r3
	beq _021E93FE
	ldr r2, _021E9418 ; =0x00005CA8
	ldr r5, [r4, r2]
	cmp r5, r3
	beq _021E93FE
	add r1, r2, #4
	ldr r1, [r4, r1]
	cmp r1, r3
	beq _021E93FE
	cmp r5, r0
	ble _021E9394
	mov r1, #0
	sub r3, r5, r0
	mvn r1, r1
	b _021E9398
_021E9394:
	sub r3, r0, r5
	mov r1, #1
_021E9398:
	sub r0, r2, #6
	strb r1, [r4, r0]
	cmp r3, #3
	blt _021E93CE
	cmp r3, #0x28
	bgt _021E93CE
	ldr r0, _021E9410 ; =gSystem + 0x40
	ldrh r2, [r0, #0x22]
	ldr r0, _021E941C ; =0x00005CAC
	ldr r1, [r4, r0]
	cmp r1, r2
	ble _021E93B8
	sub r2, r1, r2
	mov r1, #0
	mvn r1, r1
	b _021E93BC
_021E93B8:
	sub r2, r2, r1
	mov r1, #1
_021E93BC:
	sub r0, #9
	strb r1, [r4, r0]
	cmp r2, #0x28
	bgt _021E93FE
	ldr r0, _021E9420 ; =0x00005CA0
	add r0, r4, r0
	bl ov52_021E9424
	b _021E93FE
_021E93CE:
	cmp r3, #0x28
	bgt _021E93FE
	ldr r0, _021E9410 ; =gSystem + 0x40
	ldrh r2, [r0, #0x22]
	ldr r0, _021E941C ; =0x00005CAC
	ldr r1, [r4, r0]
	cmp r1, r2
	ble _021E93E6
	sub r2, r1, r2
	mov r1, #0
	mvn r1, r1
	b _021E93EA
_021E93E6:
	sub r2, r2, r1
	mov r1, #1
_021E93EA:
	sub r0, #9
	strb r1, [r4, r0]
	cmp r2, #3
	blt _021E93FE
	cmp r2, #0x28
	bgt _021E93FE
	ldr r0, _021E9420 ; =0x00005CA0
	add r0, r4, r0
	bl ov52_021E9424
_021E93FE:
	ldr r1, _021E9410 ; =gSystem + 0x40
	ldr r0, _021E9418 ; =0x00005CA8
	ldrh r2, [r1, #0x20]
	str r2, [r4, r0]
	ldrh r1, [r1, #0x22]
	add r0, r0, #4
	str r1, [r4, r0]
	pop {r3, r4, r5, pc}
	nop
_021E9410: .word gSystem + 0x40
_021E9414: .word 0x0000FFFF
_021E9418: .word 0x00005CA8
_021E941C: .word 0x00005CAC
_021E9420: .word 0x00005CA0
	thumb_func_end ov52_021E9364

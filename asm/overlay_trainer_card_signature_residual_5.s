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

	thumb_func_start ov52_021E8BDC
ov52_021E8BDC: ; 0x021E8BDC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r4, r0, #0
	ldr r0, _021E8CA4 ; =ov52_021E94BA
	bl TouchscreenHitbox_FindRectAtTouchNew
	add r1, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	beq _021E8C30
	cmp r1, #0
	bne _021E8C22
	mov r0, #0xc3
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _021E8C30
	add r0, r4, #0
	mov r1, #msg_0252_00010 ; Is this OK?
	bl ov52_021E927C
	mov r0, #0xc3
	mov r1, #2
	lsl r0, r0, #2
	str r1, [r4, r0]
	sub r0, #0xbc
	add r0, r4, r0
	mov r1, #1
	bl ov52_021E8CDC
	ldr r0, _021E8CA8 ; =0x000005DD
	bl PlaySE
	b _021E8C30
_021E8C22:
	ldr r0, _021E8CAC ; =0x0000431A
	strb r1, [r4, r0]
	mov r0, #0x25
	lsl r0, r0, #4
	add r0, r4, r0
	bl ov52_021E8CBC
_021E8C30:
	ldr r0, _021E8CB0 ; =ov52_021E94B2
	bl TouchscreenHitbox_FindRectAtTouchHeld
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _021E8C44
	add r0, r4, #0
	bl ov52_021E9364
_021E8C44:
	add r0, sp, #0
	mov r1, #4
	mov r2, #1
	bl sub_02021280
	cmp r0, #1
	bne _021E8CA0
	add r7, sp, #0
	ldrh r3, [r7]
	mov r1, #0
	cmp r3, #0
	ble _021E8C78
	ldr r5, _021E8CB4 ; =0x0000431C
	add r2, sp, #0
	add r6, r5, #0
	add r6, #8
_021E8C64:
	ldrh r3, [r2, #2]
	add r0, r4, r1
	add r1, r1, #1
	strb r3, [r0, r5]
	ldrh r3, [r2, #4]
	add r2, #8
	strb r3, [r0, r6]
	ldrh r3, [r7]
	cmp r1, r3
	blt _021E8C64
_021E8C78:
	ldr r0, _021E8CB8 ; =0x0000432C
	mov r2, #0xf0
	ldrb r1, [r4, r0]
	bic r1, r2
	lsl r2, r3, #0x18
	lsr r2, r2, #0x18
	lsl r2, r2, #0x1c
	lsr r2, r2, #0x18
	orr r1, r2
	strb r1, [r4, r0]
	ldrb r3, [r4, r0]
	mov r1, #0xf
	bic r3, r1
	add r1, r0, #0
	sub r1, #0x12
	ldrb r2, [r4, r1]
	mov r1, #0xf
	and r1, r2
	orr r1, r3
	strb r1, [r4, r0]
_021E8CA0:
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E8CA4: .word ov52_021E94BA
_021E8CA8: .word 0x000005DD
_021E8CAC: .word 0x0000431A
_021E8CB0: .word ov52_021E94B2
_021E8CB4: .word 0x0000431C
_021E8CB8: .word 0x0000432C
	thumb_func_end ov52_021E8BDC

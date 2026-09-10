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

	thumb_func_start ov52_021E8F2C
ov52_021E8F2C: ; 0x021E8F2C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	ldr r4, [sp, #0x38]
	mov ip, r1
	add r6, r2, #0
	add r7, r3, #0
	str r0, [sp, #0x18]
	ldr r3, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	ldr r1, [sp, #0x44]
	cmp r4, #0
	bge _021E8F58
	neg r0, r4
	cmp r0, r2
	ble _021E8F4C
	add r0, r2, #0
_021E8F4C:
	ldr r5, [sp, #0x30]
	mov r4, #0
	sub r5, r5, r0
	add r6, r6, r0
	str r5, [sp, #0x30]
	sub r2, r2, r0
_021E8F58:
	cmp r3, #0
	bge _021E8F70
	neg r0, r3
	cmp r0, r1
	ble _021E8F64
	add r0, r1, #0
_021E8F64:
	ldr r5, [sp, #0x34]
	mov r3, #0
	sub r5, r5, r0
	add r7, r7, r0
	str r5, [sp, #0x34]
	sub r1, r1, r0
_021E8F70:
	ldr r0, [sp, #0x30]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [sp, #0x34]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #8]
	lsl r0, r3, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0xc]
	lsl r0, r2, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x14]
	lsl r2, r6, #0x10
	lsl r3, r7, #0x10
	ldr r0, [sp, #0x18]
	mov r1, ip
	lsr r2, r2, #0x10
	lsr r3, r3, #0x10
	bl BlitBitmapRectToWindow
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov52_021E8F2C


	thumb_func_start ov52_021E8FAC
ov52_021E8FAC: ; 0x021E8FAC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x50]
	str r1, [sp, #0x1c]
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x54]
	str r2, [sp, #0x20]
	str r0, [sp, #0x54]
	ldr r0, [sp, #0x50]
	str r3, [sp, #0x24]
	ldr r4, [r0]
	ldr r0, [sp, #0x54]
	ldr r5, [r0]
	add r0, r2, #0
	str r0, [sp, #0x38]
	add r0, r3, #0
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x58]
	cmp r0, #0
	bne _021E8FEC
	ldr r0, [sp, #0x5c]
	cmp r0, #0
	bne _021E8FEC
	ldr r0, [sp, #0x50]
	add r1, r2, #0
	str r1, [r0]
	ldr r0, [sp, #0x54]
	add r1, r3, #0
	str r1, [r0]
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
_021E8FEC:
	ldr r0, [sp, #0x20]
	sub r0, r0, r4
	str r0, [sp, #0x34]
	bpl _021E8FF8
	neg r0, r0
	str r0, [sp, #0x34]
_021E8FF8:
	ldr r0, [sp, #0x24]
	sub r7, r0, r5
	bpl _021E9000
	neg r7, r7
_021E9000:
	ldr r0, [sp, #0x34]
	cmp r0, r7
	ble _021E908E
	ldr r0, [sp, #0x20]
	cmp r4, r0
	ble _021E9026
	ldr r0, [sp, #0x24]
	cmp r5, r0
	ble _021E9018
	mov r0, #1
	str r0, [sp, #0x2c]
	b _021E901E
_021E9018:
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x2c]
_021E901E:
	str r4, [sp, #0x38]
	ldr r4, [sp, #0x20]
	ldr r5, [sp, #0x24]
	b _021E9038
_021E9026:
	ldr r0, [sp, #0x24]
	cmp r5, r0
	bge _021E9032
	mov r0, #1
	str r0, [sp, #0x2c]
	b _021E9038
_021E9032:
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x2c]
_021E9038:
	mov r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r2, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r3, r2, #0
	bl ov52_021E8F2C
	ldr r0, [sp, #0x34]
	add r4, r4, #1
	asr r6, r0, #1
	ldr r0, [sp, #0x38]
	cmp r4, r0
	bgt _021E9112
_021E905E:
	sub r6, r6, r7
	bpl _021E906A
	ldr r0, [sp, #0x34]
	add r6, r6, r0
	ldr r0, [sp, #0x2c]
	add r5, r5, r0
_021E906A:
	mov r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r2, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r3, r2, #0
	bl ov52_021E8F2C
	ldr r0, [sp, #0x38]
	add r4, r4, #1
	cmp r4, r0
	ble _021E905E
	b _021E9112
_021E908E:
	ldr r0, [sp, #0x24]
	cmp r5, r0
	ble _021E90AE
	ldr r0, [sp, #0x20]
	cmp r4, r0
	ble _021E90A0
	mov r0, #1
	str r0, [sp, #0x28]
	b _021E90A6
_021E90A0:
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x28]
_021E90A6:
	str r5, [sp, #0x30]
	ldr r5, [sp, #0x24]
	ldr r4, [sp, #0x20]
	b _021E90C0
_021E90AE:
	ldr r0, [sp, #0x20]
	cmp r4, r0
	bge _021E90BA
	mov r0, #1
	str r0, [sp, #0x28]
	b _021E90C0
_021E90BA:
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x28]
_021E90C0:
	mov r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r2, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r3, r2, #0
	bl ov52_021E8F2C
	ldr r0, [sp, #0x30]
	add r5, r5, #1
	asr r6, r7, #1
	cmp r5, r0
	bgt _021E9112
_021E90E4:
	ldr r0, [sp, #0x34]
	sub r6, r6, r0
	bpl _021E90F0
	ldr r0, [sp, #0x28]
	add r6, r6, r7
	add r4, r4, r0
_021E90F0:
	mov r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r2, #0
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	add r3, r2, #0
	bl ov52_021E8F2C
	ldr r0, [sp, #0x30]
	add r5, r5, #1
	cmp r5, r0
	ble _021E90E4
_021E9112:
	ldr r1, [sp, #0x20]
	ldr r0, [sp, #0x50]
	str r1, [r0]
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x54]
	str r1, [r0]
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov52_021E8FAC


	thumb_func_start ov52_021E9124
ov52_021E9124: ; 0x021E9124
	mov r2, #0
_021E9126:
	ldrb r3, [r0, #0x10]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x1c
	strh r3, [r1, #2]
	ldrb r3, [r0, #0x10]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x1c
	beq _021E914A
	add r3, r0, r3
	sub r3, r3, #1
	ldrb r3, [r3]
	strb r3, [r1]
	ldrb r3, [r0, #0x10]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x1c
	add r3, r0, r3
	ldrb r3, [r3, #7]
	strb r3, [r1, #1]
_021E914A:
	add r2, r2, #1
	add r0, #0x11
	add r1, r1, #4
	cmp r2, #5
	blt _021E9126
	bx lr
	.balign 4, 0
	thumb_func_end ov52_021E9124


	thumb_func_start ov52_021E9158
ov52_021E9158: ; 0x021E9158
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r7, r0, #0
	mov r0, #0
	str r1, [sp, #0x10]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	add r5, r1, #0
	add r6, r2, #0
_021E916E:
	ldrb r0, [r5, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	beq _021E91D2
	ldrh r0, [r6, #2]
	cmp r0, #0
	beq _021E9188
	ldrb r0, [r6]
	sub r0, #0x20
	str r0, [sp, #0x28]
	ldrb r0, [r6, #1]
	sub r0, #0x48
	str r0, [sp, #0x24]
_021E9188:
	ldrb r0, [r5, #0x10]
	mov r4, #0
	lsl r0, r0, #0x18
	lsr r1, r0, #0x1c
	cmp r1, #0
	ble _021E91D2
	mov r0, #1
	str r0, [sp, #0x1c]
	cmp r1, #0
	ble _021E91D2
_021E919C:
	add r0, sp, #0x28
	str r0, [sp]
	add r0, sp, #0x24
	str r0, [sp, #4]
	str r4, [sp, #8]
	ldrh r0, [r6, #2]
	add r3, r5, r4
	str r0, [sp, #0xc]
	ldrb r1, [r5, #0x10]
	ldrb r3, [r3, #8]
	add r0, r7, #0
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	lsl r2, r1, #4
	ldr r1, _021E9214 ; =ov52_021E95A0
	sub r3, #0x48
	add r1, r1, r2
	ldrb r2, [r5, r4]
	sub r2, #0x20
	bl ov52_021E8FAC
	ldrb r0, [r5, #0x10]
	add r4, r4, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	cmp r4, r0
	blt _021E919C
_021E91D2:
	ldr r0, [sp, #0x20]
	add r5, #0x11
	add r0, r0, #1
	add r6, r6, #4
	str r0, [sp, #0x20]
	cmp r0, #5
	blt _021E916E
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _021E91F2
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _021E91F2
	add r0, r7, #0
	bl CopyWindowToVram
_021E91F2:
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl ov52_021E9124
	mov r3, #0
	mov r1, #0xf0
_021E91FE:
	ldr r0, [sp, #0x10]
	add r3, r3, #1
	ldrb r2, [r0, #0x10]
	bic r2, r1
	strb r2, [r0, #0x10]
	add r0, #0x11
	str r0, [sp, #0x10]
	cmp r3, #5
	blt _021E91FE
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E9214: .word ov52_021E95A0
	thumb_func_end ov52_021E9158

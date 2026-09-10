	.include "asm/macros.inc"
	.include "unk_020192D0.inc"
	.include "global.inc"

	.text
	thumb_func_start sub_020199F4
sub_020199F4: ; 0x020199F4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r2, [sp]
	ldr r2, [r0, #4]
	lsl r0, r1, #4
	add r1, r2, r0
	ldr r0, [r2, r0]
	add r7, r3, #0
	mov ip, r0
	ldrh r0, [r1, #4]
	add r1, sp, #0x10
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1a
	mov lr, r0
	ldrb r0, [r1, #0x14]
	add r0, r7, r0
	str r0, [sp, #4]
	cmp r7, r0
	bge _02019A58
	ldrb r0, [r1, #0x18]
	ldrb r1, [r1, #0x10]
	ldr r6, _02019A5C ; =0x00000FFF
	lsl r5, r0, #0xc
	ldr r0, [sp]
	add r2, r0, r1
_02019A26:
	ldr r1, [sp]
	add r0, r1, #0
	cmp r0, r2
	bge _02019A4C
	mov r0, lr
	mul r0, r7
	lsl r3, r0, #1
	mov r0, ip
	add r3, r0, r3
_02019A38:
	lsl r0, r1, #1
	ldrh r4, [r3, r0]
	and r4, r6
	orr r4, r5
	strh r4, [r3, r0]
	add r0, r1, #1
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	cmp r1, r2
	blt _02019A38
_02019A4C:
	add r0, r7, #1
	lsl r0, r0, #0x10
	lsr r7, r0, #0x10
	ldr r0, [sp, #4]
	cmp r7, r0
	blt _02019A26
_02019A58:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02019A5C: .word 0x00000FFF
	thumb_func_end sub_020199F4
	thumb_func_start sub_02019A60
sub_02019A60: ; 0x02019A60
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	lsl r0, r1, #4
	str r0, [sp, #0xc]
	ldr r0, [sp]
	mov r6, #0
	ldr r1, [r0, #4]
	ldr r0, [sp, #0xc]
	add r3, r1, r0
	ldr r0, [r1, r0]
	mov ip, r0
	ldrh r0, [r3, #4]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1a
	mov lr, r0
	ldrh r0, [r2, #0xa]
	lsl r0, r0, #0x11
	lsr r7, r0, #0x11
	ldrb r0, [r2, #9]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x10
	str r0, [sp, #8]
	ldrb r0, [r2, #8]
	cmp r0, #0
	ble _02019B04
_02019A94:
	ldrb r0, [r2, #6]
	add r3, r0, r6
	ldr r0, [sp]
	ldr r1, [r0, #4]
	ldr r0, [sp, #0xc]
	add r0, r1, r0
	ldrh r0, [r0, #4]
	lsl r0, r0, #0x14
	lsr r0, r0, #0x1a
	cmp r3, r0
	bge _02019B04
	ldrb r0, [r2, #7]
	mov r1, #0
	str r0, [sp, #4]
	cmp r0, #0
	ble _02019AF0
_02019AB4:
	ldr r0, [sp]
	ldrb r5, [r2, #5]
	ldr r3, [r0, #4]
	ldr r0, [sp, #0xc]
	add r4, r5, r1
	add r0, r3, r0
	ldrh r0, [r0, #4]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1a
	cmp r4, r0
	bge _02019AF0
	ldr r0, [sp, #8]
	add r3, r7, r1
	add r0, r0, r3
	ldrb r3, [r2, #6]
	add r4, r3, r6
	mov r3, lr
	mul r4, r3
	add r3, r5, r4
	add r3, r1, r3
	lsl r4, r3, #1
	mov r3, ip
	strh r0, [r3, r4]
	add r0, r1, #1
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	ldrb r0, [r2, #7]
	str r0, [sp, #4]
	cmp r1, r0
	blt _02019AB4
_02019AF0:
	ldr r0, [sp, #4]
	add r0, r7, r0
	lsl r0, r0, #0x10
	lsr r7, r0, #0x10
	add r0, r6, #1
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	ldrb r0, [r2, #8]
	cmp r6, r0
	blt _02019A94
_02019B04:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02019A60

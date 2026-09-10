	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02010F34
sub_02010F34: ; 0x02010F34
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r1, #0
	add r4, r2, #0
	cmp r0, #0
	bne _02010F4C
	add r0, r5, #0
	mov r1, #0
	bl sub_02013424
	add sp, #0xc
	pop {r4, r5, pc}
_02010F4C:
	add r0, r5, #0
	mov r1, #1
	bl sub_02013424
	mov r2, #0
	add r0, r5, #0
	mov r1, #0x3f
	add r3, r2, #0
	str r4, [sp]
	bl sub_02013440
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	add r0, r5, #0
	add r2, r1, #0
	add r3, r1, #0
	str r4, [sp, #8]
	bl sub_02013488
	add r0, r5, #0
	mov r1, #0x20
	mov r2, #0
	add r3, r4, #0
	bl sub_02013468
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end sub_02010F34
	thumb_func_start sub_02010F84
sub_02010F84: ; 0x02010F84
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r2, #0
	ldr r2, [sp, #0x34]
	add r6, r0, #0
	add r5, r3, #0
	ldr r4, [sp, #0x20]
	cmp r2, #0
	bne _02010FC0
	add r0, r1, #0
	mov r1, #0
	add r2, r5, #0
	add r3, r4, #0
	bl sub_02013220
	add r0, r7, #0
	mov r1, #0
	add r2, r4, #0
	bl sub_020132A8
	str r5, [sp]
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x28]
	ldr r2, [sp, #0x2c]
	ldr r3, [sp, #0x30]
	str r4, [sp, #4]
	bl sub_02013364
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_02010FC0:
	mov r2, #0
	str r4, [sp]
	bl sub_02013440
	add r0, r6, #0
	add r1, r7, #0
	mov r2, #0
	add r3, r4, #0
	bl sub_02013468
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x24]
	str r0, [sp]
	str r5, [sp, #4]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	add r0, r6, #0
	str r4, [sp, #8]
	bl sub_02013488
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_02010F84
	thumb_func_start sub_02010FEC
sub_02010FEC: ; 0x02010FEC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	add r4, r2, #0
	add r6, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	add r7, r3, #0
	bl sub_020132E8
	add r1, sp, #4
	strb r0, [r1, #1]
	ldrb r0, [r1, #1]
	strb r0, [r1, #3]
	add r0, r4, #0
	bl sub_0201333C
	add r1, sp, #4
	strb r0, [r1]
	ldrb r0, [r1]
	cmp r7, #0
	strb r0, [r1, #2]
	bne _0201103E
	ldrb r0, [r1, #2]
	mov r1, #0
	add r2, r5, #0
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1b
	add r3, r4, #0
	bl sub_02013220
	add r0, sp, #4
	ldrb r0, [r0, #3]
	mov r1, #0
	add r2, r4, #0
	lsl r0, r0, #0x1b
	lsr r0, r0, #0x1b
	bl sub_020132A8
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_0201103E:
	str r4, [sp]
	ldrb r1, [r1, #2]
	add r0, r6, #0
	mov r2, #0
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x1b
	add r3, r5, #0
	bl sub_02013440
	add r1, sp, #4
	ldrb r1, [r1, #3]
	add r0, r6, #0
	mov r2, #0
	lsl r1, r1, #0x1b
	lsr r1, r1, #0x1b
	add r3, r4, #0
	bl sub_02013468
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02010FEC

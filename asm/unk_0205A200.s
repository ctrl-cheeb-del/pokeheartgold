	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205A200
sub_0205A200: ; 0x0205A200
	push {r4, r5, r6, lr}
	add r5, r1, #0
	add r4, r0, #0
	sub r0, r5, #1
	bl sub_02035798
	add r6, r0, #0
	add r0, r4, #0
	bl sub_0205ABB0
	cmp r6, #0
	bne _0205A21C
	mov r0, #5
	pop {r4, r5, r6, pc}
_0205A21C:
	sub r0, r5, #1
	lsl r0, r0, #2
	add r1, r4, r0
	mov r0, #0x11
	lsl r0, r0, #4
	ldr r1, [r1, r0]
	cmp r1, #0
	bne _0205A230
	mov r0, #5
	pop {r4, r5, r6, pc}
_0205A230:
	add r1, #0x50
	ldr r0, _0205A280 ; =_021D41CC
	add r1, #0x30
	str r1, [r0, #4]
	ldrb r0, [r1, #0x1c]
	cmp r0, #0xd
	bhi _0205A27A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0205A24A: ; jump table
	.short _0205A266 - _0205A24A - 2 ; case 0
	.short _0205A26A - _0205A24A - 2 ; case 1
	.short _0205A26E - _0205A24A - 2 ; case 2
	.short _0205A272 - _0205A24A - 2 ; case 3
	.short _0205A276 - _0205A24A - 2 ; case 4
	.short _0205A276 - _0205A24A - 2 ; case 5
	.short _0205A276 - _0205A24A - 2 ; case 6
	.short _0205A276 - _0205A24A - 2 ; case 7
	.short _0205A276 - _0205A24A - 2 ; case 8
	.short _0205A27A - _0205A24A - 2 ; case 9
	.short _0205A27A - _0205A24A - 2 ; case 10
	.short _0205A276 - _0205A24A - 2 ; case 11
	.short _0205A27A - _0205A24A - 2 ; case 12
	.short _0205A272 - _0205A24A - 2 ; case 13
_0205A266:
	mov r0, #1
	pop {r4, r5, r6, pc}
_0205A26A:
	mov r0, #2
	pop {r4, r5, r6, pc}
_0205A26E:
	mov r0, #3
	pop {r4, r5, r6, pc}
_0205A272:
	mov r0, #4
	pop {r4, r5, r6, pc}
_0205A276:
	mov r0, #5
	pop {r4, r5, r6, pc}
_0205A27A:
	mov r0, #5
	pop {r4, r5, r6, pc}
	nop
_0205A280: .word _021D41CC
	thumb_func_end sub_0205A200
	thumb_func_start sub_0205A284
sub_0205A284: ; 0x0205A284
	push {r3, r4}
	sub r1, r1, #1
	lsl r3, r1, #2
	add r4, r0, r3
	mov r3, #0x11
	lsl r3, r3, #4
	ldr r4, [r4, r3]
	cmp r4, #0
	bne _0205A29C
	mov r0, #5
	pop {r3, r4}
	bx lr
_0205A29C:
	add r4, #0x50
	ldr r3, _0205A354 ; =_021D41CC
	add r4, #0x30
	str r4, [r3, #4]
	ldrb r3, [r4, #0x1c]
	cmp r3, #0xd
	bhi _0205A34E
	add r3, r3, r3
	add r3, pc
	ldrh r3, [r3, #6]
	lsl r3, r3, #0x10
	asr r3, r3, #0x10
	add pc, r3
_0205A2B6: ; jump table
	.short _0205A2F2 - _0205A2B6 - 2 ; case 0
	.short _0205A30E - _0205A2B6 - 2 ; case 1
	.short _0205A2D2 - _0205A2B6 - 2 ; case 2
	.short _0205A32A - _0205A2B6 - 2 ; case 3
	.short _0205A348 - _0205A2B6 - 2 ; case 4
	.short _0205A348 - _0205A2B6 - 2 ; case 5
	.short _0205A348 - _0205A2B6 - 2 ; case 6
	.short _0205A348 - _0205A2B6 - 2 ; case 7
	.short _0205A348 - _0205A2B6 - 2 ; case 8
	.short _0205A34E - _0205A2B6 - 2 ; case 9
	.short _0205A34E - _0205A2B6 - 2 ; case 10
	.short _0205A348 - _0205A2B6 - 2 ; case 11
	.short _0205A34E - _0205A2B6 - 2 ; case 12
	.short _0205A32A - _0205A2B6 - 2 ; case 13
_0205A2D2:
	cmp r2, #3
	beq _0205A2DC
	mov r0, #5
	pop {r3, r4}
	bx lr
_0205A2DC:
	mov r2, #5
	str r2, [r0, #0x30]
	str r1, [r0, #0x18]
	mov r2, #1
	str r2, [r0, #0x20]
	mov r1, #0
	str r1, [r0, #0x24]
	str r1, [r0, #0x1c]
	add r0, r2, #0
	pop {r3, r4}
	bx lr
_0205A2F2:
	cmp r2, #1
	beq _0205A2FC
	mov r0, #5
	pop {r3, r4}
	bx lr
_0205A2FC:
	str r1, [r0, #0x18]
	mov r2, #1
	str r2, [r0, #0x20]
	mov r1, #0
	str r1, [r0, #0x24]
	str r1, [r0, #0x1c]
	add r0, r2, #0
	pop {r3, r4}
	bx lr
_0205A30E:
	cmp r2, #2
	beq _0205A318
	mov r0, #5
	pop {r3, r4}
	bx lr
_0205A318:
	str r1, [r0, #0x18]
	mov r1, #2
	str r1, [r0, #0x20]
	mov r1, #0
	str r1, [r0, #0x24]
	str r1, [r0, #0x1c]
	mov r0, #1
	pop {r3, r4}
	bx lr
_0205A32A:
	cmp r2, #4
	beq _0205A334
	mov r0, #5
	pop {r3, r4}
	bx lr
_0205A334:
	mov r2, #6
	str r2, [r0, #0x30]
	str r1, [r0, #0x18]
	mov r2, #1
	str r2, [r0, #0x20]
	mov r1, #0
	str r1, [r0, #0x1c]
	add r0, r2, #0
	pop {r3, r4}
	bx lr
_0205A348:
	mov r0, #5
	pop {r3, r4}
	bx lr
_0205A34E:
	mov r0, #5
	pop {r3, r4}
	bx lr
	.balign 4, 0
_0205A354: .word _021D41CC
	thumb_func_end sub_0205A284

	.include "asm/macros.inc"
	.include "unk_02032844.inc"
	.include "global.inc"

	.text
	thumb_func_start sub_020332C0
sub_020332C0: ; 0x020332C0
	push {r3, r4, r5, lr}
	sub sp, #8
	add r0, sp, #0
	bl OS_GetMacAddress
	ldr r0, _02033348 ; =0x027FFC3C
	ldr r3, [r0]
	add r0, sp, #0
	ldrh r2, [r0, #4]
	ldrh r1, [r0, #2]
	ldrh r0, [r0]
	add r0, r0, r3
	add r0, r1, r0
	add r1, r2, r0
	ldr r3, _0203334C ; =_021D4124
	ldr r2, _02033350 ; =0x00001338
	ldr r0, [r3, #4]
	str r1, [r0, r2]
	ldr r0, [r3, #4]
	ldr r1, _02033354 ; =0x00010DCD
	ldr r4, [r0, r2]
	add r5, r4, #0
	mul r5, r1
	ldr r1, _02033358 ; =0x00003039
	mov r4, #0
	add r1, r5, r1
	str r1, [r0, r2]
	ldr r1, [r3, #4]
	add r0, r2, #4
	strh r4, [r1, r0]
	ldr r1, [r3, #4]
	mov r4, #0x65
	add r0, r2, #6
	strh r4, [r1, r0]
	mov r0, #3
	bl sub_02032844
	mov r0, #1
	bl sub_0203335C
	cmp r0, #0x18
	bne _0203332C
	mov r0, #0x18
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	mov r0, #1
	bl sub_02039AD8
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, pc}
_0203332C:
	cmp r0, #2
	beq _02033340
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, pc}
_02033340:
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_02033348: .word 0x027FFC3C
_0203334C: .word _021D4124
_02033350: .word 0x00001338
_02033354: .word 0x00010DCD
_02033358: .word 0x00003039
	thumb_func_end sub_020332C0
	thumb_func_start sub_0203335C
sub_0203335C: ; 0x0203335C
	push {r4, lr}
	add r4, r0, #0
	bl WM_GetAllowedChannel
	mov r1, #2
	lsl r1, r1, #0xe
	cmp r0, r1
	bne _02033382
	mov r0, #3
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	mov r0, #1
	bl sub_02039AD8
	mov r0, #3
	pop {r4, pc}
_02033382:
	cmp r0, #0
	bne _0203339C
	mov r0, #0x16
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	mov r0, #1
	bl sub_02039AD8
	mov r0, #0x18
	pop {r4, pc}
_0203339C:
	mov r2, #1
	sub r1, r4, #1
	lsl r2, r1
	add r1, r2, #0
	tst r1, r0
	bne _020333C4
	mov r2, #1
_020333AA:
	add r1, r4, #1
	lsl r1, r1, #0x10
	lsr r4, r1, #0x10
	cmp r4, #0x10
	bls _020333B8
	mov r0, #0x18
	pop {r4, pc}
_020333B8:
	sub r1, r4, #1
	add r3, r2, #0
	lsl r3, r1
	add r1, r3, #0
	tst r1, r0
	beq _020333AA
_020333C4:
	ldr r0, _020333D4 ; =sub_020333D8
	add r1, r4, #0
	bl sub_02033454
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	pop {r4, pc}
	nop
_020333D4: .word sub_020333D8
	thumb_func_end sub_0203335C
	thumb_func_start sub_020333D8
sub_020333D8: ; 0x020333D8
	push {r3, r4, r5, lr}
	ldrh r1, [r0, #2]
	cmp r1, #0
	beq _020333F4
	add r0, r1, #0
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	mov r0, #1
	bl sub_02039AD8
	pop {r3, r4, r5, pc}
_020333F4:
	ldr r2, _0203344C ; =_021D4124
	ldrh r1, [r0, #8]
	ldrh r5, [r0, #0xa]
	ldr r0, [r2, #4]
	ldr r3, _02033450 ; =0x0000133E
	ldrh r4, [r0, r3]
	cmp r4, r5
	bls _02033414
	strh r5, [r0, r3]
	mov r4, #1
	sub r0, r1, #1
	lsl r4, r0
	ldr r2, [r2, #4]
	add r0, r3, #2
	strh r4, [r2, r0]
	b _02033428
_02033414:
	cmp r4, r5
	bne _02033428
	add r2, r3, #2
	ldrh r5, [r0, r2]
	mov r4, #1
	sub r2, r1, #1
	lsl r4, r2
	orr r4, r5
	add r2, r3, #2
	strh r4, [r0, r2]
_02033428:
	add r0, r1, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_0203335C
	cmp r0, #0x18
	bne _0203343E
	mov r0, #7
	bl sub_02032844
	pop {r3, r4, r5, pc}
_0203343E:
	cmp r0, #2
	beq _02033448
	mov r0, #9
	bl sub_02032844
_02033448:
	pop {r3, r4, r5, pc}
	nop
_0203344C: .word _021D4124
_02033450: .word 0x0000133E
	thumb_func_end sub_020333D8
	thumb_func_start sub_02033454
sub_02033454: ; 0x02033454
	push {r3, lr}
	add r3, r1, #0
	mov r1, #0x1e
	str r1, [sp]
	mov r1, #3
	mov r2, #0x11
	bl WM_MeasureChannel
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end sub_02033454
	thumb_func_start sub_02033468
sub_02033468: ; 0x02033468
	push {r3, lr}
	mov r0, #1
	bl sub_02032844
	ldr r0, _0203348C ; =_021D4124
	ldr r1, [r0, #4]
	mov r0, #0x4d
	lsl r0, r0, #6
	ldrh r0, [r1, r0]
	bl sub_02033494
	ldr r2, _0203348C ; =_021D4124
	ldr r1, _02033490 ; =0x0000133C
	ldr r3, [r2, #4]
	strh r0, [r3, r1]
	ldr r0, [r2, #4]
	ldrh r0, [r0, r1]
	pop {r3, pc}
	.balign 4, 0
_0203348C: .word _021D4124
_02033490: .word 0x0000133C
	thumb_func_end sub_02033468
	thumb_func_start sub_02033494
sub_02033494: ; 0x02033494
	push {r4, r5, r6, r7}
	add r4, r0, #0
	mov r0, #0
	add r3, r0, #0
	add r2, r0, #0
	mov r1, #1
_020334A0:
	add r5, r1, #0
	lsl r5, r2
	tst r5, r4
	beq _020334B4
	add r0, r2, #1
	add r3, r3, #1
	lsl r0, r0, #0x10
	lsl r3, r3, #0x10
	asr r0, r0, #0x10
	lsr r3, r3, #0x10
_020334B4:
	add r2, r2, #1
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	cmp r2, #0x10
	blt _020334A0
	cmp r3, #1
	bls _02033512
	ldr r5, _02033518 ; =_021D4124
	ldr r2, _0203351C ; =0x00001338
	ldr r0, [r5, #4]
	ldr r1, _02033520 ; =0x00010DCD
	ldr r6, [r0, r2]
	add r7, r6, #0
	mul r7, r1
	ldr r1, _02033524 ; =0x00003039
	add r1, r7, r1
	str r1, [r0, r2]
	ldr r0, [r5, #4]
	mov r1, #1
	ldr r0, [r0, r2]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mul r0, r3
	lsl r0, r0, #8
	lsr r2, r0, #0x10
	mov r3, #0
_020334E8:
	add r0, r4, #0
	tst r0, r1
	beq _02033502
	cmp r2, #0
	bne _020334FC
	add r0, r3, #1
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	pop {r4, r5, r6, r7}
	bx lr
_020334FC:
	sub r0, r2, #1
	lsl r0, r0, #0x10
	lsr r2, r0, #0x10
_02033502:
	lsl r0, r4, #0xf
	lsr r4, r0, #0x10
	add r0, r3, #1
	lsl r0, r0, #0x10
	asr r3, r0, #0x10
	cmp r3, #0x10
	blt _020334E8
	mov r0, #0
_02033512:
	pop {r4, r5, r6, r7}
	bx lr
	nop
_02033518: .word _021D4124
_0203351C: .word 0x00001338
_02033520: .word 0x00010DCD
_02033524: .word 0x00003039
	thumb_func_end sub_02033494
	thumb_func_start sub_02033528
sub_02033528: ; 0x02033528
	push {r4, r5, r6, lr}
	lsl r2, r0, #0x1b
	lsr r3, r2, #0x1b
	beq _02033536
	mov r2, #0x20
	sub r2, r2, r3
	add r0, r0, r2
_02033536:
	ldr r3, _020335AC ; =_021D4124
	ldr r2, _020335B0 ; =0x00001308
	str r0, [r3, #4]
	mov r4, #0
	str r4, [r0, r2]
	ldr r5, [r3, #4]
	sub r0, r2, #4
	str r4, [r5, r0]
	add r0, r2, #0
	ldr r5, [r3, #4]
	add r0, #0x10
	str r4, [r5, r0]
	add r0, r2, #0
	ldr r5, [r3, #4]
	add r0, #0x24
	strh r4, [r5, r0]
	add r0, r2, #0
	ldr r5, [r3, #4]
	mov r6, #1
	add r0, #0x26
	strh r6, [r5, r0]
	add r0, r2, #0
	ldr r5, [r3, #4]
	add r0, #0x28
	str r4, [r5, r0]
	add r0, r2, #0
	ldr r5, [r3, #4]
	add r0, #8
	str r4, [r5, r0]
	ldr r0, [r3, #4]
	mov r6, #8
	str r4, [r0]
	ldr r0, [r3, #4]
	strh r4, [r0, #4]
	add r0, r2, #0
	ldr r5, [r3, #4]
	add r0, #0x14
	str r4, [r5, r0]
	add r0, r2, #0
	ldr r5, [r3, #4]
	add r0, #0x2c
	strb r6, [r5, r0]
	add r0, r2, #0
	ldr r5, [r3, #4]
	add r0, #0x2d
	strb r4, [r5, r0]
	ldr r0, [r3, #4]
	add r2, #0x3a
	strb r4, [r0, r2]
	add r0, r1, #0
	bl sub_020335D4
	cmp r0, #0
	bne _020335A6
	add r0, r4, #0
	pop {r4, r5, r6, pc}
_020335A6:
	mov r0, #1
	pop {r4, r5, r6, pc}
	nop
_020335AC: .word _021D4124
_020335B0: .word 0x00001308
	thumb_func_end sub_02033528

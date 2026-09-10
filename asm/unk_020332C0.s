	.include "asm/macros.inc"
	.include "unk_02032844.inc"
	.include "global.inc"

	.text
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

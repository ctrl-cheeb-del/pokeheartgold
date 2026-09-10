	.include "asm/macros.inc"
	.include "unk_02054648.inc"
	.include "global.inc"

	.rodata

	.public _020FC5FC
_020FC5FC:
	.short 0x00D0
	.short 0x00D2
	.short 0x00D3
	.short 0x0000
	.public _020FC604
_020FC604:
	.word sub_02054774
	.word sub_020547D8
	.public _020FC60C
_020FC60C:
	.short 0x00D0
	.short 0x00D1
	.short 0x00D2
	.short 0x00D3
	.public _020FC614
_020FC614:
	.word sub_020547A4
	.word sub_02054824

	.text

	thumb_func_start sub_02054654
sub_02054654: ; 0x02054654
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	add r5, r0, #0
	add r6, r3, #0
	mov r4, #0
	ldr r0, [sp, #0x50]
	str r6, [sp, #0x30]
	str r4, [sp, #0x34]
	str r0, [sp, #0x38]
	ldr r0, [r5, #0x2c]
	str r1, [sp, #8]
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x30]
	str r2, [sp, #0xc]
	bl MapMatrix_GetWidth
	str r0, [sp, #0x28]
	lsl r0, r0, #5
	str r0, [sp, #0x14]
	asr r0, r6, #0xf
	lsr r0, r0, #0x10
	add r0, r6, r0
	add r2, r5, #0
	add r2, #0x98
	ldr r1, [sp, #0x50]
	asr r7, r0, #0x10
	asr r0, r1, #0xf
	lsr r0, r0, #0x10
	add r0, r1, r0
	asr r0, r0, #0x10
	str r0, [sp, #0x20]
	ldr r1, [sp, #0x20]
	ldr r2, [r2]
	add r0, r7, #0
	add r3, sp, #0x2c
	bl ov01_021FB42C
	str r0, [sp, #0x24]
	lsr r0, r7, #5
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x50]
	lsr r0, r0, #5
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	lsl r0, r0, #5
	add r0, #0x10
	lsl r0, r0, #0x10
	sub r0, r6, r0
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x18]
	lsl r0, r0, #5
	add r0, #0x10
	lsl r0, r0, #0x10
	sub r0, r1, r0
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x20]
	ldr r0, [sp, #0x14]
	mul r0, r1
	ldr r1, [sp, #0x14]
	add r0, r7, r0
	bl ov01_021F6328
	ldr r2, [sp, #0x18]
	add r1, r0, #0
	add r3, r2, #0
	ldr r0, [sp, #0x28]
	ldr r2, [sp, #0x10]
	mul r3, r0
	ldr r0, [sp, #0x1c]
	add r0, r0, r3
	bl ov01_021F635C
	add r1, r0, #0
	cmp r1, #3
	bls _020546F0
	add r6, r4, #0
	b _0205470E
_020546F0:
	lsl r1, r1, #0x18
	ldr r0, [sp, #0x10]
	lsr r1, r1, #0x18
	bl ov01_021F65D0
	str r0, [sp]
	add r0, sp, #0x34
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x30]
	ldr r3, [sp, #0x38]
	bl ov01_021FAE50
	add r6, r0, #0
_0205470E:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _02054758
	add r0, sp, #0x2c
	add r5, #0x98
	ldrb r0, [r0]
	ldr r1, [r5]
	bl ov01_021FB474
	add r5, r0, #0
	cmp r6, #0
	beq _02054752
	ldr r4, [sp, #0x34]
	cmp r5, r4
	bgt _02054730
	mov r1, #1
	b _02054764
_02054730:
	ldr r1, [sp, #0xc]
	add r0, r4, #0
	bl sub_02054648
	add r4, r0, #0
	ldr r1, [sp, #0xc]
	add r0, r5, #0
	bl sub_02054648
	cmp r4, r0
	bgt _0205474C
	ldr r4, [sp, #0x34]
	mov r1, #1
	b _02054764
_0205474C:
	add r4, r5, #0
	mov r1, #2
	b _02054764
_02054752:
	mov r1, #2
	add r4, r5, #0
	b _02054764
_02054758:
	cmp r6, #0
	beq _02054762
	mov r1, #1
	ldr r4, [sp, #0x34]
	b _02054764
_02054762:
	mov r1, #0
_02054764:
	ldr r0, [sp, #0x54]
	cmp r0, #0
	beq _0205476C
	strb r1, [r0]
_0205476C:
	add r0, r4, #0
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02054654

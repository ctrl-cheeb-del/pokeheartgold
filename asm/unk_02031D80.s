	.include "asm/macros.inc"
	.include "unk_02031B0C.inc"
	.include "global.inc"

	.text

	thumb_func_start sub_02031DA0
sub_02031DA0: ; 0x02031DA0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r1, #0
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #0
	mov r2, #0xe
	bl MI_CpuFill8
	add r0, sp, #4
	add r0, #2
	mov r1, #0
	mov r2, #0xa
	bl MI_CpuFill8
	mov r0, #0
	add r1, sp, #4
	str r0, [sp]
	add r1, #2
_02031DC6:
	add r2, r4, r0
	ldrb r2, [r2, #3]
	strb r0, [r1]
	strb r2, [r1, #1]
	cmp r2, #0
	beq _02031DDC
	ldr r2, [sp]
	add r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	str r2, [sp]
_02031DDC:
	add r0, r0, #1
	add r1, r1, #2
	cmp r0, #5
	blt _02031DC6
	ldr r0, [sp]
	cmp r0, #0
	beq _02031E3C
	add r0, sp, #4
	add r0, #2
	mov r7, #0
	mov ip, r0
_02031DF2:
	add r5, r7, #1
	cmp r5, #5
	bge _02031E34
	lsl r2, r5, #1
	mov r1, ip
	add r1, r1, r2
	add r2, sp, #4
_02031E00:
	ldrb r4, [r1, #1]
	ldrb r3, [r0, #1]
	cmp r3, r4
	bhi _02031E2C
	cmp r3, r4
	bne _02031E14
	ldrb r4, [r0]
	ldrb r3, [r1]
	cmp r4, r3
	blo _02031E2C
_02031E14:
	ldrb r3, [r0]
	strb r3, [r2]
	ldrb r3, [r0, #1]
	strb r3, [r2, #1]
	ldrb r3, [r1]
	strb r3, [r0]
	ldrb r3, [r1, #1]
	strb r3, [r0, #1]
	ldrb r3, [r2]
	strb r3, [r1]
	ldrb r3, [r2, #1]
	strb r3, [r1, #1]
_02031E2C:
	add r5, r5, #1
	add r1, r1, #2
	cmp r5, #5
	blt _02031E00
_02031E34:
	add r7, r7, #1
	add r0, r0, #2
	cmp r7, #5
	blt _02031DF2
_02031E3C:
	add r0, sp, #4
	ldrb r5, [r0, #0xb]
	add r3, sp, #4
	add r0, r6, #0
	mov r4, #0
	add r3, #2
	add r0, #0xb
_02031E4A:
	ldrb r2, [r3]
	add r1, r6, r4
	strb r2, [r1, #6]
	ldrb r1, [r3, #1]
	cmp r5, r1
	bne _02031E5C
	ldrb r1, [r0]
	add r1, r1, #1
	strb r1, [r0]
_02031E5C:
	add r4, r4, #1
	add r3, r3, #2
	cmp r4, #5
	blt _02031E4A
	ldr r0, [sp]
	strb r0, [r6, #0xc]
	ldr r0, [sp]
	cmp r0, #5
	bls _02031E70
	b _02031FDC
_02031E70:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02031E7C: ; jump table
	.short _02031E88 - _02031E7C - 2 ; case 0
	.short _02031E98 - _02031E7C - 2 ; case 1
	.short _02031EB2 - _02031E7C - 2 ; case 2
	.short _02031ED6 - _02031E7C - 2 ; case 3
	.short _02031EFA - _02031E7C - 2 ; case 4
	.short _02031EFA - _02031E7C - 2 ; case 5
_02031E88:
	ldrh r1, [r6]
	mov r0, #0xf
	add sp, #0x10
	bic r1, r0
	mov r0, #6
	orr r0, r1
	strh r0, [r6]
	pop {r3, r4, r5, r6, r7, pc}
_02031E98:
	add r1, sp, #4
	add r0, r6, #0
	add r1, #2
	mov r2, #0
	bl sub_02032588
	ldrh r1, [r6, #2]
	mov r0, #0xf
	bic r1, r0
	mov r0, #6
	orr r0, r1
	strh r0, [r6, #2]
	b _02031FDC
_02031EB2:
	add r1, sp, #4
	add r0, r6, #0
	add r1, #2
	mov r2, #0
	bl sub_02032588
	add r0, r6, #2
	add r1, sp, #8
	mov r2, #1
	bl sub_02032588
	ldrh r1, [r6, #4]
	mov r0, #0xf
	bic r1, r0
	mov r0, #6
	orr r0, r1
	strh r0, [r6, #4]
	b _02031FDC
_02031ED6:
	add r1, sp, #4
	add r0, r6, #0
	add r1, #2
	mov r2, #0
	bl sub_02032588
	add r0, r6, #2
	add r1, sp, #8
	mov r2, #1
	bl sub_02032588
	add r1, sp, #8
	add r0, r6, #4
	add r1, #2
	mov r2, #2
	bl sub_02032588
	b _02031FDC
_02031EFA:
	add r0, sp, #4
	ldrb r2, [r0, #3]
	ldrb r1, [r0, #9]
	sub r1, r2, r1
	cmp r1, #0xc
	bgt _02031F88
	ldrh r3, [r6]
	mov r2, #0xf
	mov r1, #5
	bic r3, r2
	orr r1, r3
	strh r1, [r6]
	ldrb r3, [r0, #3]
	ldrh r1, [r6]
	ldr r4, _02031FE4 ; =0xFFFF00FF
	lsl r3, r3, #0x18
	and r1, r4
	lsr r3, r3, #0x10
	orr r1, r3
	strh r1, [r6]
	ldrh r1, [r6, #2]
	mov r3, #6
	bic r1, r2
	orr r1, r3
	strh r1, [r6, #2]
	ldrb r5, [r0, #5]
	ldrh r1, [r6, #2]
	lsl r5, r5, #0x18
	and r1, r4
	lsr r5, r5, #0x10
	orr r1, r5
	strh r1, [r6, #2]
	ldrh r1, [r6, #4]
	bic r1, r2
	orr r1, r3
	strh r1, [r6, #4]
	ldrh r1, [r6, #4]
	add r2, r1, #0
	ldrb r1, [r0, #7]
	and r2, r4
	lsl r1, r1, #0x18
	lsr r1, r1, #0x10
	orr r1, r2
	strh r1, [r6, #4]
	mov r1, #1
	strb r1, [r6, #0xc]
	ldrb r0, [r0, #3]
	cmp r0, #0x14
	bls _02031F6A
	ldrh r1, [r6]
	mov r0, #0xf0
	bic r1, r0
	mov r0, #0x30
	orr r0, r1
	strh r0, [r6]
	b _02031FDC
_02031F6A:
	cmp r0, #7
	ldrh r1, [r6]
	bls _02031F7C
	mov r0, #0xf0
	bic r1, r0
	mov r0, #0x20
	orr r0, r1
	strh r0, [r6]
	b _02031FDC
_02031F7C:
	mov r0, #0xf0
	bic r1, r0
	mov r0, #0x10
	orr r0, r1
	strh r0, [r6]
	b _02031FDC
_02031F88:
	add r1, sp, #4
	add r0, r6, #0
	add r1, #2
	mov r2, #0
	bl sub_02032588
	add r0, r6, #2
	add r1, sp, #8
	mov r2, #1
	bl sub_02032588
	ldr r0, [sp]
	cmp r0, #4
	bne _02031FB2
	add r1, sp, #0xc
	add r0, r6, #4
	add r1, #2
	mov r2, #2
	bl sub_02032588
	b _02031FDC
_02031FB2:
	ldrh r1, [r6, #4]
	mov r0, #0xf
	bic r1, r0
	mov r0, #5
	orr r0, r1
	strh r0, [r6, #4]
	ldrh r1, [r6, #4]
	mov r0, #0xf0
	bic r1, r0
	mov r0, #0x10
	orr r0, r1
	strh r0, [r6, #4]
	ldrh r1, [r6, #4]
	ldr r0, _02031FE4 ; =0xFFFF00FF
	and r1, r0
	add r0, sp, #4
	ldrb r0, [r0, #7]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x10
	orr r0, r1
	strh r0, [r6, #4]
_02031FDC:
	ldr r0, [sp]
	strb r0, [r6, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02031FE4: .word 0xFFFF00FF
	thumb_func_end sub_02031DA0

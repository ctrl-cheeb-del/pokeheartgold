	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0203778C
sub_0203778C: ; 0x0203778C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r4, r0, #0
	add r0, sp, #0x10
	add r1, sp, #4
	bl GF_RTC_CopyDateTime
	ldr r0, _02037810 ; =gSystem
	ldr r6, [sp, #0x10]
	mov r5, #0
	lsr r7, r6, #0x1c
	lsl r5, r5, #4
	ldr r1, [sp, #0xc]
	ldr r0, [r0, #0x2c]
	lsl r6, r6, #4
	add r3, r1, r0
	ldr r0, [sp, #0x18]
	orr r5, r7
	str r0, [sp]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #4]
	add r6, r0, r6
	ldr r0, _02037814 ; =0x00000000
	ldr r2, [sp, #8]
	adc r0, r5
	lsr r5, r6, #0x1b
	lsl r0, r0, #5
	orr r0, r5
	ldr r5, [sp]
	lsl r6, r6, #5
	add r6, r5, r6
	ldr r5, _02037814 ; =0x00000000
	adc r5, r0
	lsr r0, r6, #0x1b
	lsl r5, r5, #5
	orr r5, r0
	lsl r0, r6, #5
	add r6, r1, r0
	ldr r1, _02037814 ; =0x00000000
	adc r1, r5
	lsr r0, r6, #0x1a
	lsl r1, r1, #6
	orr r1, r0
	lsl r0, r6, #6
	add r5, r2, r0
	ldr r2, _02037814 ; =0x00000000
	adc r2, r1
	lsr r0, r5, #0x1a
	lsl r1, r2, #6
	orr r1, r0
	lsl r0, r5, #6
	add r2, r3, r0
	ldr r0, _02037814 ; =0x00000000
	str r2, [r4]
	adc r0, r1
	str r0, [r4, #4]
	ldr r1, _02037818 ; =0x6C078965
	ldr r0, _0203781C ; =0x5D588B65
	str r1, [r4, #8]
	str r0, [r4, #0xc]
	ldr r0, _02037820 ; =0x00269EC3
	str r0, [r4, #0x10]
	mov r0, #0
	str r0, [r4, #0x14]
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02037810: .word gSystem
_02037814: .word 0x00000000
_02037818: .word 0x6C078965
_0203781C: .word 0x5D588B65
_02037820: .word 0x00269EC3
	thumb_func_end sub_0203778C

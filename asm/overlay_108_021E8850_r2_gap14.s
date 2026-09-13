	.include "asm/macros.inc"
	.include "overlay_108.inc"
	.include "global.inc"

	.text
	.extern SafariDecoration_Init
	.extern SafariDecoration_Exit
	.extern SafariDecoration_Main
	.extern ov108_021E8968
	.extern ov108_021E8A88
	.extern ov108_021E8AD4
	.extern ov108_021E8B24
	.extern ov108_021E8B68
	.extern ov108_021E8BC0
	.extern ov108_021E8C18
	.extern ov108_021E8C64
	.extern ov108_021E8CD4
	.extern ov108_021E8E10
	.extern ov108_021E8E60
	.extern ov108_021E8EA4
	.extern ov108_021E8ED8
	.extern ov108_021E8F00
	.extern ov108_021E90C4
	.extern ov108_021E9144
	.extern ov108_021E9198
	.extern ov108_021E91D4
	.extern ov108_021E91F8
	.extern ov108_021E9204
	.extern ov108_021E9210
	.extern ov108_021E9230
	.extern ov108_021E929C
	.extern ov108_021E9304
	.extern ov108_021E9388
	.extern ov108_021E93A8
	.extern ov108_021E940C
	.extern ov108_021E9488
	.extern ov108_021E94E8
	.extern ov108_021E9528
	.extern ov108_021E95AC
	.extern ov108_021E96FC
	.extern ov108_021E979C
	.extern ov108_021E9830
	.extern ov108_021E9850
	.extern ov108_021E9A08
	.extern ov108_021E9A60
	.extern ov108_021E9BD4
	.extern ov108_021E9C14
	.extern ov108_021E9C2C
	.extern ov108_021E9C3C
	.extern ov108_021E9CD0
	.extern ov108_021E9D30
	.extern ov108_021E9DE0
	.extern ov108_021E9E10
	.extern ov108_021E9E80
	.extern ov108_021E9EB8
	.extern ov108_021E9F04
	.extern ov108_021E9F20
	.extern ov108_021E9F94
	.extern ov108_021EA040
	.extern ov108_021EA260
	.extern ov108_021EA2EC
	.extern ov108_021EA334
	.extern ov108_021EA418
	.extern ov108_021EA47C
	.extern ov108_021EA50C
	.extern ov108_021EA52C
	.extern ov108_021EA584
	.extern ov108_021EA5E4
	.extern ov108_021EA624
	.extern ov108_021EA700
	.extern ov108_021EA9C4
	.extern ov108_021EA9D8
	.extern ov108_021EA9E4
	.extern ov108_021EAAA4
	.extern ov108_021EAAB0
	.extern ov108_021EAAC0
	.extern ov108_021EAAD0
	.extern ov108_021EAAE4
	.extern ov108_021EAB00
	.extern ov108_021EAB1C
	.extern ov108_021EAB38
	.extern ov108_021EAB54
	.extern ov108_021EAB70
	.extern ov108_021EAB8C
	.extern ov108_021EABA8
	.extern ov108_021EABC8
	.extern ov108_021EABF0
	.extern ov108_021EAC18
	.extern ov108_021EAC48
	.extern ov108_021EACE8
	.extern ov108_021EACF0
	.extern ov108_021EACF8
	.extern ov108_021EAD00
	.extern ov108_021EAD08
	.extern ov108_021EAD28


	thumb_func_start ov108_021EA63C
ov108_021EA63C: ; 0x021EA63C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r1, [sp]
	mov r6, #0
	mov r1, #0xa
	str r2, [sp, #4]
	str r3, [sp, #8]
	add r4, r6, #0
	bl _u32_div_f
	ldr r2, _021EA6F8 ; =ov108_021EAD28
	lsl r0, r1, #2
	add r0, r2, r0
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov ip, r0
	ldr r0, [sp]
	cmp r0, #0
	ble _021EA69C
	mov r7, #1
_021EA664:
	ldr r1, [sp, #0xc]
	mov r0, ip
	ldrb r0, [r1, r0]
	mov r2, #0
	lsl r1, r0, #3
	ldr r0, _021EA6FC ; =ov108_021EAD08
	ldrb r5, [r0, r1]
	add r3, r0, r1
	cmp r5, #0
	ble _021EA690
	ldr r3, [r3, #4]
_021EA67A:
	ldrb r0, [r3]
	add r1, r7, #0
	add r2, r2, #1
	lsl r1, r0
	add r0, r6, #1
	lsl r0, r0, #0x18
	orr r4, r1
	lsr r6, r0, #0x18
	add r3, r3, #1
	cmp r2, r5
	blt _021EA67A
_021EA690:
	mov r0, ip
	add r1, r0, #1
	ldr r0, [sp]
	mov ip, r1
	cmp r1, r0
	blt _021EA664
_021EA69C:
	lsl r5, r6, #2
	ldr r0, [sp, #0x28]
	add r1, r6, r5
	bl Heap_Alloc
	mov r1, #0
	add r2, r6, r5
	str r0, [sp, #0x10]
	bl MI_CpuFill8
	mov r7, #0
	add r6, r7, #0
_021EA6B4:
	mov r0, #1
	tst r0, r4
	beq _021EA6E4
	lsl r0, r7, #2
	add r1, r7, r0
	ldr r0, [sp, #0x10]
	strb r6, [r0, r1]
	add r5, r0, r1
	ldr r2, [sp, #4]
	add r0, r5, #2
	add r1, r6, #0
	bl GetSafariObjectConfig
	ldrb r1, [r5, #3]
	lsl r0, r1, #0x1c
	lsl r1, r1, #0x19
	lsr r0, r0, #0x1d
	lsr r1, r1, #0x1d
	bl ov108_021EA700
	strb r0, [r5, #1]
	add r0, r7, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
_021EA6E4:
	add r6, r6, #1
	lsr r4, r4, #1
	cmp r6, #0x18
	blt _021EA6B4
	ldr r0, [sp, #8]
	strb r7, [r0]
	ldr r0, [sp, #0x10]
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_021EA6F8: .word ov108_021EAD28
_021EA6FC: .word ov108_021EAD08
	thumb_func_end ov108_021EA63C

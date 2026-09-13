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
	.extern ov108_021EA5E4
	.extern ov108_021EA624
	.extern ov108_021EA63C
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


	thumb_func_start ov108_021EA52C
ov108_021EA52C: ; 0x021EA52C
	push {r3, r4}
	ldr r2, _021EA580 ; =0x00000435
	ldrb r2, [r0, r2]
	cmp r2, #0
	bne _021EA53C
	mov r0, #4
	pop {r3, r4}
	bx lr
_021EA53C:
	lsl r2, r1, #2
	add r4, r1, r2
	mov r1, #0xcd
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	ldr r3, [r0, #0x1c]
	add r1, r1, r4
	ldrb r0, [r1, #3]
	ldrb r2, [r3, #0x18]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r2, r0
	beq _021EA566
	cmp r2, #0
	bne _021EA560
	mov r0, #2
	pop {r3, r4}
	bx lr
_021EA560:
	mov r0, #3
	pop {r3, r4}
	bx lr
_021EA566:
	ldrb r0, [r1, #1]
	lsl r0, r0, #2
	add r0, r3, r0
	ldrb r0, [r0, #8]
	cmp r0, #0
	bne _021EA578
	mov r0, #1
	pop {r3, r4}
	bx lr
_021EA578:
	mov r0, #0
	pop {r3, r4}
	bx lr
	nop
_021EA580: .word 0x00000435
	thumb_func_end ov108_021EA52C

	thumb_func_start ov108_021EA584
ov108_021EA584: ; 0x021EA584
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	str r3, [sp]
	add r6, r1, #0
	ldr r0, [r5]
	mov r1, #0x14
	add r7, r2, #0
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x14
	add r4, r0, #0
	bl MI_CpuFill8
	add r0, r6, #2
	str r5, [r4, #4]
	lsl r0, r0, #2
	str r7, [r4]
	add r1, r5, r0
	ldr r0, _021EA5D8 ; =0x00000444
	strb r6, [r4, #8]
	ldr r0, [r1, r0]
	lsl r1, r6, #1
	add r1, r6, r1
	add r1, r1, #6
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _021EA5DC ; =0x000005E1
	bl PlaySE
	ldr r1, [r4]
	cmp r1, #0
	beq _021EA5CC
	ldr r0, [r1]
	add r0, r0, #1
	str r0, [r1]
_021EA5CC:
	ldr r0, _021EA5E0 ; =ov108_021EA5E4
	ldr r2, [sp]
	add r1, r4, #0
	bl SysTask_CreateOnMainQueue
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021EA5D8: .word 0x00000444
_021EA5DC: .word 0x000005E1
_021EA5E0: .word ov108_021EA5E4
	thumb_func_end ov108_021EA584

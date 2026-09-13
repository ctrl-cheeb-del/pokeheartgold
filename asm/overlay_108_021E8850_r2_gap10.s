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


	thumb_func_start ov108_021E9D30
ov108_021E9D30: ; 0x021E9D30
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r7, r0, #0
	ldr r0, _021E9DCC ; =0x00000454
	ldr r4, _021E9DD0 ; =ov108_021EAC18
	mov r6, #0
	add r5, r7, r0
_021E9D3E:
	ldr r0, _021E9DD4 ; =0x00000438
	add r1, r5, #0
	ldr r0, [r7, r0]
	add r2, r4, #0
	bl AddWindow
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r6, r6, #1
	add r4, #8
	add r5, #0x10
	cmp r6, #5
	ble _021E9D3E
	ldr r0, _021E9DCC ; =0x00000454
	ldr r6, _021E9DD8 ; =0x000002E2
	add r0, r7, r0
	mov r4, #0
	str r0, [sp, #0x14]
_021E9D66:
	lsr r0, r4, #0x1f
	add r0, r4, r0
	asr r1, r0, #1
	lsl r0, r1, #2
	add r0, r1, r0
	lsr r3, r4, #0x1f
	str r3, [sp, #0x18]
	add r0, r0, #6
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xe
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	add r1, r4, #6
	lsl r2, r1, #4
	ldr r1, [sp, #0x14]
	ldr r5, [sp, #0x18]
	lsl r3, r4, #0x1f
	sub r3, r3, r5
	mov r5, #0x1f
	ror r3, r5
	ldr r5, [sp, #0x18]
	add r1, r1, r2
	add r3, r5, r3
	lsl r3, r3, #4
	add r3, r3, #1
	lsl r3, r3, #0x18
	ldr r0, _021E9DD4 ; =0x00000438
	str r6, [sp, #0x10]
	ldr r0, [r7, r0]
	mov r2, #5
	lsr r3, r3, #0x18
	bl AddWindowParameterized
	sub r6, #0x1c
	lsl r0, r6, #0x10
	add r4, r4, #1
	lsr r6, r0, #0x10
	cmp r4, #6
	blt _021E9D66
	ldr r0, [r7]
	bl YesNoPrompt_Create
	ldr r1, _021E9DDC ; =0x00000514
	str r0, [r7, r1]
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E9DCC: .word 0x00000454
_021E9DD0: .word ov108_021EAC18
_021E9DD4: .word 0x00000438
_021E9DD8: .word 0x000002E2
_021E9DDC: .word 0x00000514
	thumb_func_end ov108_021E9D30

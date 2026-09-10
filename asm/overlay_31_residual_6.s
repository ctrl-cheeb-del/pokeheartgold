	.include "asm/macros.inc"
	.include "overlay_31.inc"
	.include "global.inc"

	.text
	.public _0225EE40
	.public _0225EF40
	.public ov31_0225D520
	.public ov31_0225D684
	.public ov31_0225D7A0
	.public ov31_0225D83C
	.public ov31_0225D9D4
	.public ov31_0225DAC4
	.public ov31_0225DB38
	.public ov31_0225DBD4
	.public ov31_0225DCA8
	.public ov31_0225DD14
	.public ov31_0225DE24
	.public ov31_0225DE84
	.public ov31_0225DF98
	.public ov31_0225E060
	.public ov31_0225E184
	.public ov31_0225E20C
	.public ov31_0225E2D4
	.public ov31_0225E54C
	.public ov31_0225E5FC
	.public ov31_0225E700
	.public ov31_0225E7D4
	.public ov31_0225EA08
	.public ov31_0225EA9C
	.public ov31_0225EB30
	.public ov31_0225EBC4
	.public ov31_0225EC58
	.public ov31_0225EE44
	.public ov31_0225EE60
	.public ov31_0225EE88
	.public ov31_0225EED0
	.public ov31_0225EEEC
	.public ov31_0225EF08
	.public ov31_0225EF48
	.public ov31_0225D60C
	.public ov31_0225D654
	.public ov31_0225D710
	.public ov31_0225D758
	.public ov31_0225D75C
	.public ov31_0225DAA4
	.public ov31_0225DBA0
	.public ov31_0225DCF4
	.public ov31_0225DE00
	.public ov31_0225E0E4
	.public ov31_0225E12C
	.public ov31_0225E474
	.public ov31_0225E4BC
	.public ov31_0225E4EC
	.public ov31_0225E51C
	.public ov31_0225E774
	.public ov31_0225E948
	.public ov31_0225E95C
	.public ov31_0225E9CC
	.public ov31_0225EDA0

	thumb_func_start ov31_0225DD14
ov31_0225DD14: ; 0x0225DD14
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	mov r6, #0
	add r4, r5, #0
	add r4, #0x84
	add r7, r6, #0
_0225DD22:
	add r0, r4, #0
	add r1, r7, #0
	bl FillWindowPixelBuffer
	add r6, r6, #1
	add r4, #0x10
	cmp r6, #6
	blt _0225DD22
	mov r0, #0x27
	ldr r2, [r5, #0x14]
	lsl r0, r0, #4
	ldrb r1, [r2, r0]
	add r0, r0, #1
	ldrb r0, [r2, r0]
	sub r0, r1, r0
	str r0, [sp, #4]
	cmp r0, #6
	ble _0225DD4C
	mov r0, #6
	str r0, [sp, #4]
	b _0225DD54
_0225DD4C:
	cmp r0, #0
	bge _0225DD54
	mov r0, #0
	str r0, [sp, #4]
_0225DD54:
	ldr r0, [sp, #4]
	mov r4, #0
	cmp r0, #0
	ble _0225DDD6
	add r6, r5, #0
	add r6, #0x84
_0225DD60:
	ldr r0, [r5, #0x14]
	ldr r1, _0225DDF8 ; =0x00000271
	ldrb r1, [r0, r1]
	add r1, r4, r1
	str r1, [sp, #0xc]
	mov r1, #0x9a
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	ldr r0, [sp, #0xc]
	lsl r0, r0, #1
	ldrh r7, [r1, r0]
	mov r0, #0x57
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r7, #0
	bl NewString_ReadMsgData
	str r0, [sp, #0x10]
	ldr r2, [sp, #0x10]
	add r0, r5, #0
	add r1, r6, #0
	add r3, r4, #0
	bl ov31_0225DE00
	ldr r0, [sp, #0x10]
	bl String_Delete
	ldr r0, [r5, #0x14]
	ldr r1, [sp, #0xc]
	add r2, r7, #0
	bl ov31_0225E12C
	cmp r0, #0
	beq _0225DDCC
	ldr r0, [r5, #0x14]
	lsl r1, r7, #0x10
	str r0, [sp, #8]
	lsr r1, r1, #0x10
	bl ov03_02258120
	add r3, r0, #0
	ldr r1, [sp, #8]
	ldr r0, _0225DDFC ; =0x00000283
	add r2, r6, #0
	ldrb r0, [r1, r0]
	mov r1, #0x56
	lsl r1, r1, #2
	str r0, [sp]
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	bl ov31_0225DE24
_0225DDCC:
	ldr r0, [sp, #4]
	add r4, r4, #1
	add r6, #0x10
	cmp r4, r0
	blt _0225DD60
_0225DDD6:
	add r4, r5, #0
	mov r6, #0
	add r4, #0x84
_0225DDDC:
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add r6, r6, #1
	add r4, #0x10
	cmp r6, #6
	blt _0225DDDC
	ldr r1, [sp, #4]
	add r0, r5, #0
	bl ov31_0225E0E4
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_0225DDF8: .word 0x00000271
_0225DDFC: .word 0x00000283
	thumb_func_end ov31_0225DD14

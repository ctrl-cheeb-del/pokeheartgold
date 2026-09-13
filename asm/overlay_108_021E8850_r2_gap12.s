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


	thumb_func_start ov108_021EA334
ov108_021EA334: ; 0x021EA334
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, _021EA40C ; =0x00000454
	mov r6, #0
	add r4, r1, #0
	add r0, r5, r0
	add r1, r6, #0
	bl FillWindowPixelBuffer
	cmp r4, #0
	beq _021EA352
	cmp r4, #2
	beq _021EA382
	b _021EA3A4
_021EA352:
	ldr r1, _021EA410 ; =0x00000433
	mov r2, #0xc3
	lsl r2, r2, #2
	ldrb r1, [r5, r1]
	ldr r0, [r5, r2]
	add r2, #8
	ldr r2, [r5, r2]
	add r1, #0xe
	bl ReadMsgDataIntoString
	add r1, r6, #0
	mov r2, #0x31
	str r1, [sp]
	mov r0, #2
	lsl r2, r2, #4
	str r0, [sp, #4]
	ldr r0, [r5, r2]
	add r2, r2, #4
	ldr r2, [r5, r2]
	mov r3, #1
	bl BufferString
	mov r6, #1
	b _021EA3A4
_021EA382:
	ldr r0, _021EA414 ; =0x00000435
	ldrb r2, [r5, r0]
	cmp r2, #0
	bne _021EA38E
	mov r4, #3
	b _021EA3A4
_021EA38E:
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x31
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r6, #0
	mov r3, #2
	bl BufferIntegerAsString
	mov r6, #1
_021EA3A4:
	cmp r6, #0
	beq _021EA3CE
	mov r2, #0xc3
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	add r2, #8
	ldr r2, [r5, r2]
	add r1, r4, #0
	bl ReadMsgDataIntoString
	mov r2, #0x31
	lsl r2, r2, #4
	add r1, r2, #0
	ldr r0, [r5, r2]
	add r1, #8
	add r2, r2, #4
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl StringExpandPlaceholders
	b _021EA3DE
_021EA3CE:
	mov r2, #0xc3
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	add r2, #0xc
	ldr r2, [r5, r2]
	add r1, r4, #0
	bl ReadMsgDataIntoString
_021EA3DE:
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0xc1
	lsl r0, r0, #0xa
	str r0, [sp, #8]
	mov r2, #0xc6
	ldr r0, _021EA40C ; =0x00000454
	str r1, [sp, #0xc]
	lsl r2, r2, #2
	ldr r2, [r5, r2]
	add r0, r5, r0
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _021EA40C ; =0x00000454
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_021EA40C: .word 0x00000454
_021EA410: .word 0x00000433
_021EA414: .word 0x00000435
	thumb_func_end ov108_021EA334

	thumb_func_start ov108_021EA418
ov108_021EA418: ; 0x021EA418
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, _021EA474 ; =0x00000464
	add r4, r1, #0
	add r0, r5, r0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	mov r2, #0xc3
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	add r2, #0xc
	ldr r2, [r5, r2]
	add r1, r4, #4
	bl ReadMsgDataIntoString
	ldr r2, _021EA474 ; =0x00000464
	mov r1, #1
	add r0, r5, r2
	sub r2, #0x82
	mov r3, #0xc
	bl DrawFrameAndWindow2
	mov r3, #0
	mov r2, #0xc6
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021EA478 ; =0x0001020F
	lsl r2, r2, #2
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _021EA474 ; =0x00000464
	ldr r2, [r5, r2]
	add r0, r5, r0
	mov r1, #1
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _021EA474 ; =0x00000464
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_021EA474: .word 0x00000464
_021EA478: .word 0x0001020F
	thumb_func_end ov108_021EA418

	thumb_func_start ov108_021EA47C
ov108_021EA47C: ; 0x021EA47C
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	bl ov108_021EA624
	ldr r0, _021EA500 ; =0x000004A4
	mov r1, #0
	add r0, r4, r0
	bl FillWindowPixelBuffer
	ldr r2, _021EA504 ; =0x00000431
	sub r1, r2, #1
	ldrb r3, [r4, r1]
	mov r1, #6
	ldrb r0, [r4, r2]
	mul r1, r3
	add r1, r0, r1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r0, #6
	bhs _021EA4AE
	sub r0, r2, #4
	ldrb r0, [r4, r0]
	cmp r1, r0
	blo _021EA4BA
_021EA4AE:
	ldr r0, _021EA500 ; =0x000004A4
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
_021EA4BA:
	mov r3, #0xc3
	lsl r3, r3, #2
	add r2, r3, #0
	add r2, #0x28
	ldr r5, [r4, r2]
	lsl r2, r1, #2
	add r1, r1, r2
	ldrb r1, [r5, r1]
	ldr r0, [r4, r3]
	add r3, #0xc
	ldr r2, [r4, r3]
	add r1, #0x26
	bl ReadMsgDataIntoString
	mov r1, #0
	mov r2, #0xc6
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021EA508 ; =0x00010200
	lsl r2, r2, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, _021EA500 ; =0x000004A4
	ldr r2, [r4, r2]
	add r0, r4, r0
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _021EA500 ; =0x000004A4
	add r0, r4, r0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021EA500: .word 0x000004A4
_021EA504: .word 0x00000431
_021EA508: .word 0x00010200
	thumb_func_end ov108_021EA47C

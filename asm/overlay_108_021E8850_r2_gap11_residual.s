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

	thumb_func_start ov108_021EA040
ov108_021EA040: ; 0x021EA040
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	mov r0, #5
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xe
	str r0, [sp, #8]
	mov r0, #0x11
	str r0, [sp, #0xc]
	ldr r0, _021EA244 ; =0x00000438
	mov r2, #0
	ldr r0, [r5, r0]
	mov r1, #6
	add r3, r2, #0
	bl FillBgTilemapRect
	ldr r0, _021EA248 ; =0x00000454
	mov r4, #0
	add r7, r5, r0
_021EA06A:
	mov r0, #0x43
	lsl r0, r0, #4
	ldrb r1, [r5, r0]
	mov r0, #6
	mul r0, r1
	add r0, r4, r0
	str r0, [sp, #0x1c]
	add r0, r4, #6
	lsl r0, r0, #4
	str r0, [sp, #0x20]
	add r0, r7, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, _021EA24C ; =0x0000042D
	ldrb r1, [r5, r0]
	ldr r0, [sp, #0x1c]
	cmp r0, r1
	blt _021EA09A
	ldr r0, [sp, #0x20]
	add r0, r7, r0
	bl ScheduleWindowCopyToVram
	b _021EA168
_021EA09A:
	ldr r1, [sp, #0x1c]
	add r0, r5, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov108_021EA52C
	cmp r0, #0
	ble _021EA0AE
	mov r0, #1
	b _021EA0B0
_021EA0AE:
	mov r0, #0
_021EA0B0:
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, _021EA250 ; =0x0000051C
	lsl r1, r1, #0x1c
	ldr r0, [r5, r0]
	mov r2, #0x10
	str r2, [sp]
	mov r2, #4
	str r2, [sp, #4]
	add r2, r0, #0
	add r2, #0xc
	str r2, [sp, #8]
	lsr r1, r1, #0x18
	str r1, [sp, #0xc]
	mov r1, #0
	str r1, [sp, #0x10]
	ldrh r1, [r0]
	lsr r3, r4, #0x1f
	lsl r6, r4, #0x1f
	lsl r1, r1, #0x15
	lsr r1, r1, #0x18
	str r1, [sp, #0x14]
	ldrh r0, [r0, #2]
	sub r6, r6, r3
	mov r2, #0x1f
	ror r6, r2
	add r2, r3, r6
	add r3, r4, r3
	lsl r0, r0, #0x15
	asr r3, r3, #1
	lsr r0, r0, #0x18
	add r6, r3, #1
	str r0, [sp, #0x18]
	ldr r0, _021EA244 ; =0x00000438
	lsl r3, r6, #2
	add r3, r6, r3
	lsl r2, r2, #0x1c
	lsl r3, r3, #0x18
	ldr r0, [r5, r0]
	mov r1, #6
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl CopyToBgTilemapRect
	mov r1, #0xcd
	ldr r2, [sp, #0x1c]
	lsl r1, r1, #2
	lsl r3, r2, #2
	mov r0, #0xc3
	lsl r0, r0, #2
	ldr r1, [r5, r1]
	add r2, r2, r3
	ldrb r1, [r1, r2]
	mov r2, #0xc6
	lsl r2, r2, #2
	ldr r0, [r5, r0]
	ldr r2, [r5, r2]
	add r1, #0xe
	bl ReadMsgDataIntoString
	mov r1, #0xc6
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r0, #4
	mov r2, #0
	bl FontID_String_GetWidth
	mov r1, #0x70
	sub r3, r1, r0
	mov r0, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021EA254 ; =0x00010200
	mov r2, #0xc6
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x20]
	lsl r2, r2, #2
	lsr r6, r3, #0x1f
	add r6, r3, r6
	ldr r2, [r5, r2]
	add r0, r7, r0
	mov r1, #4
	asr r3, r6, #1
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x20]
	add r0, r7, r0
	bl ScheduleWindowCopyToVram
_021EA168:
	add r4, r4, #1
	cmp r4, #6
	bge _021EA170
	b _021EA06A
_021EA170:
	ldr r0, _021EA258 ; =0x00000484
	mov r1, #0
	add r0, r5, r0
	bl FillWindowPixelBuffer
	mov r3, #1
	str r3, [sp]
	mov r2, #0x43
	mov r0, #0x31
	str r3, [sp, #4]
	lsl r2, r2, #4
	ldrb r2, [r5, r2]
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	add r2, r2, #1
	bl BufferIntegerAsString
	mov r1, #1
	str r1, [sp]
	mov r0, #0x31
	ldr r2, _021EA25C ; =0x0000042E
	str r1, [sp, #4]
	lsl r0, r0, #4
	ldrb r2, [r5, r2]
	ldr r0, [r5, r0]
	add r3, r1, #0
	bl BufferIntegerAsString
	mov r2, #0x31
	lsl r2, r2, #4
	add r1, r2, #4
	ldr r0, [r5, r2]
	add r2, #0x1c
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl StringExpandPlaceholders
	mov r1, #0
	mov r2, #0xc5
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0xc1
	lsl r0, r0, #0xa
	str r0, [sp, #8]
	ldr r0, _021EA258 ; =0x00000484
	str r1, [sp, #0xc]
	lsl r2, r2, #2
	ldr r2, [r5, r2]
	add r0, r5, r0
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _021EA258 ; =0x00000484
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	ldr r0, _021EA244 ; =0x00000438
	mov r1, #5
	ldr r0, [r5, r0]
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _021EA244 ; =0x00000438
	mov r1, #6
	ldr r0, [r5, r0]
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0x43
	lsl r0, r0, #4
	ldrb r1, [r5, r0]
	cmp r1, #0
	bne _021EA20E
	add r0, #0x1c
	ldr r0, [r5, r0]
	mov r1, #7
	bl Sprite_SetAnimCtrlSeq
	b _021EA218
_021EA20E:
	add r0, #0x1c
	ldr r0, [r5, r0]
	mov r1, #5
	bl Sprite_SetAnimCtrlSeq
_021EA218:
	mov r0, #0x43
	lsl r0, r0, #4
	sub r1, r0, #2
	ldrb r1, [r5, r1]
	ldrb r2, [r5, r0]
	sub r1, r1, #1
	cmp r2, r1
	bne _021EA236
	add r0, #0x20
	ldr r0, [r5, r0]
	mov r1, #0xa
	bl Sprite_SetAnimCtrlSeq
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
_021EA236:
	add r0, #0x20
	ldr r0, [r5, r0]
	mov r1, #8
	bl Sprite_SetAnimCtrlSeq
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021EA244: .word 0x00000438
_021EA248: .word 0x00000454
_021EA24C: .word 0x0000042D
_021EA250: .word 0x0000051C
_021EA254: .word 0x00010200
_021EA258: .word 0x00000484
_021EA25C: .word 0x0000042E
	thumb_func_end ov108_021EA040

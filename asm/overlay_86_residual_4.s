	.include "asm/macros.inc"
	.public _021E7E98
	.public ov86_021E5900
	.public ov86_021E5A40
	.public ov86_021E5AA4
	.public ov86_021E5B38
	.public ov86_021E5BA0
	.public ov86_021E5C94
	.public ov86_021E5CDC
	.public ov86_021E5D10
	.public ov86_021E5D30
	.public ov86_021E5E0C
	.public ov86_021E5E54
	.public ov86_021E5E90
	.public ov86_021E5E98
	.public ov86_021E5ECC
	.public ov86_021E5F58
	.public ov86_021E5FBC
	.public ov86_021E5FD8
	.public ov86_021E6024
	.public ov86_021E6064
	.public ov86_021E60B8
	.public ov86_021E6114
	.public ov86_021E62F4
	.public ov86_021E6484
	.public ov86_021E64E0
	.public ov86_021E668C
	.public ov86_021E66D0
	.public ov86_021E68B8
	.public ov86_021E690C
	.public ov86_021E6A34
	.public ov86_021E6A88
	.public ov86_021E6BA8
	.public ov86_021E6DD8
	.public ov86_021E6E30
	.public ov86_021E6E98
	.public ov86_021E6FF4
	.public ov86_021E703C
	.public ov86_021E705C
	.public ov86_021E707C
	.public ov86_021E7094
	.public ov86_021E71C0
	.public ov86_021E71FC
	.public ov86_021E720C
	.public ov86_021E723C
	.public ov86_021E7258
	.public ov86_021E7344
	.public ov86_021E73CC
	.public ov86_021E73E8
	.public ov86_021E73EC
	.public ov86_021E7418
	.public ov86_021E74D0
	.public ov86_021E74F0
	.public ov86_021E752C
	.public ov86_021E757C
	.public ov86_021E7598
	.public ov86_021E75EC
	.public ov86_021E7630
	.public ov86_021E7678
	.public ov86_021E7680
	.public ov86_021E7688
	.public ov86_021E7710
	.public ov86_021E77BC
	.public ov86_021E781C
	.public ov86_021E7860
	.public ov86_021E78A8
	.public ov86_021E78B0
	.public ov86_021E78B8
	.public ov86_021E792C
	.public ov86_021E7984
	.public ov86_021E7B54
	.public ov86_021E7B68
	.public ov86_021E7C70
	.public ov86_021E7CA0
	.public ov86_021E7CF8
	.public ov86_021E7D8C
	.public ov86_021E7DA8
	.public ov86_021E7DD4
	.public ov86_021E7DF8
	.public ov86_021E7E40
	.public ov86_021E7E68
	.public ov86_021E7E90
	.public ov86_021E7E9C
	.public ov86_021E7EA8
	.public ov86_021E7EB8
	.public ov86_021E7EC8
	.public ov86_021E7ED8
	.public ov86_021E7EEC
	.public ov86_021E7F04
	.public ov86_021E7F20
	.public ov86_021E7F3C
	.public ov86_021E7F58
	.public ov86_021E7F74
	.public ov86_021E7F94
	.public ov86_021E7FBC
	.public ov86_021E7FE4
	.public ov86_021E802C
	.public ov86_021E8094
	.public ov86_021E8104
	.public ov86_021E81DC
	.public ov86_021E81F8
	.public ov86_021E8210
	.public ov86_021E8230
	.public ov86_021E8258
	.public ov86_021E8290
	.public ov86_021E82D8
	.include "overlay_86.inc"
	.include "global.inc"

	.text
	.public ov86_021E5D10
	.public ov86_021E5E54
	.public ov86_021E5E90
	.public ov86_021E5FBC
	.public ov86_021E668C
	.public ov86_021E703C
	.public ov86_021E705C
	.public ov86_021E707C
	.public ov86_021E71FC
	.public ov86_021E720C
	.public ov86_021E723C
	.public ov86_021E73CC
	.public ov86_021E73E8
	.public ov86_021E74D0
	.public ov86_021E74F0
	.public ov86_021E757C
	.public ov86_021E75EC
	.public ov86_021E7678
	.public ov86_021E7680
	.public ov86_021E781C
	.public ov86_021E78A8
	.public ov86_021E78B0
	.public ov86_021E7B54
	.public ov86_021E7C70
	.public ov86_021E7D8C
	.public ov86_021E7DD4
	.public ov86_021E7E40
	.public ov86_021E7E68
	.public ov86_021E7E90

	thumb_func_start ov86_021E5FD8
ov86_021E5FD8: ; 0x021E5FD8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r0, #0
	ldr r0, [sp, #0x30]
	add r7, r1, #0
	add r5, r2, #0
	add r4, r3, #0
	cmp r0, #1
	bne _021E5FF6
	ldr r0, [sp, #0x28]
	mov r2, #0
	bl FontID_String_GetWidth
	sub r5, r5, r0
	b _021E6006
_021E5FF6:
	cmp r0, #2
	bne _021E6006
	ldr r0, [sp, #0x28]
	mov r2, #0
	bl FontID_String_GetWidth
	lsr r0, r0, #1
	sub r5, r5, r0
_021E6006:
	str r4, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x28]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r6, #0
	add r2, r7, #0
	add r3, r5, #0
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov86_021E5FD8


	thumb_func_start ov86_021E6024
ov86_021E6024: ; 0x021E6024
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0x21
	lsl r0, r0, #4
	add r4, r1, #0
	ldr r0, [r5, r0]
	add r1, r2, #0
	add r7, r3, #0
	bl NewString_ReadMsgData
	add r6, r0, #0
	ldr r0, [sp, #0x24]
	add r5, #0x10
	str r0, [sp]
	ldr r0, [sp, #0x28]
	ldr r3, [sp, #0x20]
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	add r1, r6, #0
	str r0, [sp, #8]
	lsl r0, r4, #4
	add r0, r5, r0
	add r2, r7, #0
	bl ov86_021E5FD8
	add r0, r6, #0
	bl String_Delete
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov86_021E6024


	thumb_func_start ov86_021E6064
ov86_021E6064: ; 0x021E6064
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0x21
	lsl r0, r0, #4
	add r4, r1, #0
	ldr r0, [r5, r0]
	add r1, r2, #0
	add r7, r3, #0
	bl NewString_ReadMsgData
	mov r1, #0x85
	add r6, r0, #0
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x24]
	add r1, r5, #0
	str r0, [sp]
	ldr r0, [sp, #0x28]
	add r1, #0x10
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	ldr r3, [sp, #0x20]
	str r0, [sp, #8]
	lsl r0, r4, #4
	add r0, r1, r0
	mov r1, #0x86
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r2, r7, #0
	bl ov86_021E5FD8
	add r0, r6, #0
	bl String_Delete
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov86_021E6064


	thumb_func_start ov86_021E60B8
ov86_021E60B8: ; 0x021E60B8
	push {r4, lr}
	add r4, r0, #0
	ldrb r1, [r4, #7]
	cmp r1, #6
	bhi _021E610C
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E60CE: ; jump table
	.short _021E610C - _021E60CE - 2 ; case 0
	.short _021E60FA - _021E60CE - 2 ; case 1
	.short _021E60DC - _021E60CE - 2 ; case 2
	.short _021E60DC - _021E60CE - 2 ; case 3
	.short _021E60EE - _021E60CE - 2 ; case 4
	.short _021E60E8 - _021E60CE - 2 ; case 5
	.short _021E60F4 - _021E60CE - 2 ; case 6
_021E60DC:
	bl ov86_021E6114
	add r0, r4, #0
	bl ov86_021E62F4
	pop {r4, pc}
_021E60E8:
	bl ov86_021E64E0
	pop {r4, pc}
_021E60EE:
	bl ov86_021E66D0
	pop {r4, pc}
_021E60F4:
	bl ov86_021E690C
	pop {r4, pc}
_021E60FA:
	ldrb r1, [r4, #6]
	cmp r1, #1
	bhi _021E6106
	bl ov86_021E6A88
	pop {r4, pc}
_021E6106:
	bl ov86_021E6BA8
	pop {r4, pc}
_021E610C:
	add r0, r4, #0
	bl ov86_021E690C
	pop {r4, pc}
	thumb_func_end ov86_021E60B8


	thumb_func_start ov86_021E6114
ov86_021E6114: ; 0x021E6114
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r0, #0x10
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x20
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x30
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x40
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E62EC ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x16
	add r3, r1, #0
	bl ov86_021E6024
	ldrb r0, [r4, #6]
	cmp r0, #0
	bne _021E6160
	mov r2, #0x1a
	b _021E616A
_021E6160:
	cmp r0, #1
	bne _021E6168
	mov r2, #0x1b
	b _021E616A
_021E6168:
	mov r2, #0x1c
_021E616A:
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E62EC ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r3, #0xe0
	bl ov86_021E6024
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E62F0 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x2e
	str r3, [sp, #0xc]
	bl ov86_021E6024
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E62F0 ; =0x00010200
	mov r1, #1
	str r0, [sp, #8]
	add r0, r4, #0
	mov r2, #0x30
	mov r3, #0xe0
	str r1, [sp, #0xc]
	bl ov86_021E6024
	add r0, r4, #0
	mov r1, #0
	bl ov86_021E6484
	mov r3, #0
	add r2, r0, #0
	str r3, [sp]
	ldr r0, _021E62F0 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #2
	bl ov86_021E6024
	ldrb r1, [r4, #6]
	mov r0, #0
	bl sub_0205BFF0
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E62F0 ; =0x00010200
	mov r1, #2
	str r0, [sp, #8]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	str r1, [sp, #0xc]
	bl ov86_021E6064
	ldrb r1, [r4, #6]
	mov r0, #0
	bl sub_0205C048
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E62F0 ; =0x00010200
	mov r1, #2
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x34
	mov r3, #0xe0
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E62F0 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #3
	mov r2, #0x2b
	bl ov86_021E6024
	ldrb r1, [r4, #6]
	mov r0, #0
	bl sub_0205C01C
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E62F0 ; =0x00010200
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	bl ov86_021E6064
	ldrb r1, [r4, #6]
	mov r0, #0
	bl sub_0205C074
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E62F0 ; =0x00010200
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x34
	mov r3, #0xe0
	bl ov86_021E6064
	add r0, r4, #0
	add r0, #0x10
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x20
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x30
	bl ScheduleWindowCopyToVram
	add r4, #0x40
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_021E62EC: .word 0x000F0200
_021E62F0: .word 0x00010200
	thumb_func_end ov86_021E6114


	thumb_func_start ov86_021E62F4
ov86_021E62F4: ; 0x021E62F4
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r0, #0x50
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x60
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x70
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6480 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #4
	mov r2, #0x2f
	str r3, [sp, #0xc]
	bl ov86_021E6024
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6480 ; =0x00010200
	mov r1, #4
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x30
	mov r3, #0xe0
	bl ov86_021E6024
	add r0, r4, #0
	mov r1, #1
	bl ov86_021E6484
	mov r3, #0
	add r2, r0, #0
	str r3, [sp]
	ldr r0, _021E6480 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #5
	bl ov86_021E6024
	ldrb r1, [r4, #6]
	mov r0, #1
	bl sub_0205BFF0
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6480 ; =0x00010200
	mov r1, #5
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	bl ov86_021E6064
	ldrb r1, [r4, #6]
	mov r0, #1
	bl sub_0205C048
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6480 ; =0x00010200
	mov r1, #5
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x34
	mov r3, #0xe0
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6480 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #6
	mov r2, #0x2b
	bl ov86_021E6024
	ldrb r1, [r4, #6]
	mov r0, #1
	bl sub_0205C01C
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6480 ; =0x00010200
	mov r1, #6
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	bl ov86_021E6064
	ldrb r1, [r4, #6]
	mov r0, #1
	bl sub_0205C074
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6480 ; =0x00010200
	mov r1, #6
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x34
	mov r3, #0xe0
	bl ov86_021E6064
	add r0, r4, #0
	add r0, #0x50
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x60
	bl ScheduleWindowCopyToVram
	add r4, #0x70
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r4, pc}
	nop
_021E6480: .word 0x00010200
	thumb_func_end ov86_021E62F4


	thumb_func_start ov86_021E6484
ov86_021E6484: ; 0x021E6484
	push {r4, r5, r6, lr}
	add r6, r1, #0
	bne _021E648E
	mov r5, #0x66
	b _021E6490
_021E648E:
	mov r5, #0x68
_021E6490:
	ldrb r4, [r0, #6]
	cmp r4, #3
	bne _021E64B4
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	add r0, r5, #0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	bl FrontierSave_GetStat
	b _021E64CE
_021E64B4:
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl sub_02030AE8
	lsl r2, r6, #2
	add r2, r4, r2
	lsl r2, r2, #0x18
	mov r1, #0xa
	lsr r2, r2, #0x18
	mov r3, #0
	bl sub_02030AD4
_021E64CE:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bne _021E64DA
	mov r0, #0x1e
	pop {r4, r5, r6, pc}
_021E64DA:
	mov r0, #0x1d
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov86_021E6484


	thumb_func_start ov86_021E64E0
ov86_021E64E0: ; 0x021E64E0
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r0, #0x10
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x20
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x30
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x40
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E6684 ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r5, #0
	mov r2, #0x18
	add r3, r1, #0
	bl ov86_021E6024
	ldrb r0, [r5, #6]
	cmp r0, #0
	bne _021E652C
	mov r2, #0x1a
	b _021E6536
_021E652C:
	cmp r0, #1
	bne _021E6534
	mov r2, #0x1b
	b _021E6536
_021E6534:
	mov r2, #0x1c
_021E6536:
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E6684 ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r3, #0xe0
	bl ov86_021E6024
	ldrh r1, [r5, #8]
	add r0, r5, #0
	bl ov86_021E668C
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6688 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #1
	mov r2, #0x33
	str r3, [sp, #0xc]
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6688 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #2
	mov r2, #0x1d
	str r3, [sp, #0xc]
	bl ov86_021E6024
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldrb r0, [r5, #6]
	bl sub_0205C11C
	add r6, r0, #0
	ldrb r0, [r5, #6]
	bl sub_0205C11C
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	ldrh r1, [r5, #8]
	cmp r1, r0
	beq _021E65B2
	mov r2, #0
	b _021E65C8
_021E65B2:
	ldrb r0, [r5, #6]
	bl sub_0205C0CC
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
_021E65C8:
	add r0, r5, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6688 ; =0x00010200
	mov r1, #2
	str r0, [sp, #8]
	add r0, r5, #0
	mov r2, #0x32
	mov r3, #0x70
	str r1, [sp, #0xc]
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6688 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #3
	mov r2, #0x2b
	str r3, [sp, #0xc]
	bl ov86_021E6024
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0xb
	add r2, sp, #0x10
	bl sub_020312C4
	add r4, r0, #0
	ldr r0, [sp, #0x10]
	cmp r0, #1
	beq _021E6618
	mov r6, #0
	b _021E6630
_021E6618:
	ldrb r0, [r5, #6]
	bl sub_0205C144
	add r2, r0, #0
	mov r0, #0x89
	lsl r0, r0, #2
	ldrh r3, [r5, #8]
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl sub_020312E0
	add r6, r0, #0
_021E6630:
	cmp r4, #0
	beq _021E663A
	add r0, r4, #0
	bl Heap_Free
_021E663A:
	add r0, r5, #0
	mov r1, #0
	add r2, r6, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6688 ; =0x00010200
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r2, #0x32
	mov r3, #0x70
	bl ov86_021E6064
	add r0, r5, #0
	add r0, #0x10
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #0x20
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #0x30
	bl ScheduleWindowCopyToVram
	add r5, #0x40
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	nop
_021E6684: .word 0x000F0200
_021E6688: .word 0x00010200
	thumb_func_end ov86_021E64E0

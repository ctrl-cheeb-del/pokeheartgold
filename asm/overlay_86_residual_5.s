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

	thumb_func_start ov86_021E66D0
ov86_021E66D0: ; 0x021E66D0
	push {r4, r5, r6, lr}
	sub sp, #0x10
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
	ldr r0, _021E68B0 ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r5, #0
	mov r2, #0x17
	add r3, r1, #0
	bl ov86_021E6024
	ldrb r0, [r5, #6]
	cmp r0, #0
	bne _021E671C
	mov r2, #0x1a
	b _021E6726
_021E671C:
	cmp r0, #1
	bne _021E6724
	mov r2, #0x1b
	b _021E6726
_021E6724:
	mov r2, #0x1c
_021E6726:
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E68B0 ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r3, #0xe0
	bl ov86_021E6024
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E68B4 ; =0x00010200
	mov r1, #1
	str r0, [sp, #8]
	add r0, r5, #0
	mov r2, #0x31
	mov r3, #0x70
	str r1, [sp, #0xc]
	bl ov86_021E6024
	add r0, r5, #0
	bl ov86_021E68B8
	mov r3, #0
	add r2, r0, #0
	str r3, [sp]
	ldr r0, _021E68B4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r5, #0
	mov r1, #2
	bl ov86_021E6024
	ldrb r0, [r5, #6]
	bl sub_0205C1A0
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E68B4 ; =0x00010200
	mov r1, #2
	str r0, [sp, #8]
	add r0, r5, #0
	mov r2, #0x36
	mov r3, #0x70
	str r1, [sp, #0xc]
	bl ov86_021E6064
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldrb r0, [r5, #6]
	bl sub_0205C1F0
	add r6, r0, #0
	ldrb r0, [r5, #6]
	bl sub_0205C1F0
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E68B4 ; =0x00010200
	mov r1, #2
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r2, #0x35
	mov r3, #0xe0
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E68B4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r5, #0
	mov r1, #3
	mov r2, #0x2b
	bl ov86_021E6024
	ldrb r0, [r5, #6]
	bl sub_0205C1C8
	add r1, r0, #0
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r2, #0xff
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E68B4 ; =0x00010200
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r2, #0x36
	mov r3, #0x70
	bl ov86_021E6064
	mov r0, #0x89
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	ldrb r0, [r5, #6]
	bl sub_0205C240
	add r6, r0, #0
	ldrb r0, [r5, #6]
	bl sub_0205C240
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl FrontierSave_GetStat
	add r2, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl ov86_021E5FBC
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E68B4 ; =0x00010200
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r2, #0x35
	mov r3, #0xe0
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
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E68B0: .word 0x000F0200
_021E68B4: .word 0x00010200
	thumb_func_end ov86_021E66D0


	thumb_func_start ov86_021E68B8
ov86_021E68B8: ; 0x021E68B8
	push {r3, r4, lr}
	sub sp, #4
	ldrb r4, [r0, #6]
	cmp r4, #3
	bne _021E68E0
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	mov r0, #0x6c
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0x6c
	bl FrontierSave_GetStat
	b _021E68F6
_021E68E0:
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl sub_02030E08
	mov r3, #0
	mov r1, #9
	add r2, r4, #0
	str r3, [sp]
	bl sub_02030E58
_021E68F6:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bne _021E6904
	add sp, #4
	mov r0, #0x1e
	pop {r3, r4, pc}
_021E6904:
	mov r0, #0x1d
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov86_021E68B8


	thumb_func_start ov86_021E690C
ov86_021E690C: ; 0x021E690C
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
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E6A2C ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x19
	add r3, r1, #0
	bl ov86_021E6024
	ldrb r0, [r4, #6]
	cmp r0, #0
	bne _021E694E
	mov r2, #0x1a
	b _021E6958
_021E694E:
	cmp r0, #1
	bne _021E6956
	mov r2, #0x1b
	b _021E6958
_021E6956:
	mov r2, #0x1c
_021E6958:
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E6A2C ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r3, #0xe0
	bl ov86_021E6024
	add r0, r4, #0
	bl ov86_021E6A34
	mov r3, #0
	add r2, r0, #0
	str r3, [sp]
	ldr r0, _021E6A30 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #1
	bl ov86_021E6024
	ldrb r0, [r4, #6]
	bl sub_0205C2C0
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
	ldr r0, _021E6A30 ; =0x00010200
	mov r1, #1
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x37
	mov r3, #0x70
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6A30 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #2
	mov r2, #0x2b
	bl ov86_021E6024
	ldrb r0, [r4, #6]
	bl sub_0205C2E8
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
	ldr r0, _021E6A30 ; =0x00010200
	mov r1, #2
	str r0, [sp, #8]
	add r0, r4, #0
	mov r2, #0x37
	mov r3, #0x70
	str r1, [sp, #0xc]
	bl ov86_021E6064
	add r0, r4, #0
	add r0, #0x10
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x20
	bl ScheduleWindowCopyToVram
	add r4, #0x30
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r4, pc}
	nop
_021E6A2C: .word 0x000F0200
_021E6A30: .word 0x00010200
	thumb_func_end ov86_021E690C


	thumb_func_start ov86_021E6A34
ov86_021E6A34: ; 0x021E6A34
	push {r3, r4, lr}
	sub sp, #4
	ldrb r4, [r0, #6]
	cmp r4, #3
	bne _021E6A5C
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl Save_Frontier_GetStatic
	add r4, r0, #0
	mov r0, #0x6e
	bl sub_0205C268
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #0x6e
	bl FrontierSave_GetStat
	b _021E6A72
_021E6A5C:
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl sub_02030FA0
	mov r3, #0
	mov r1, #8
	add r2, r4, #0
	str r3, [sp]
	bl sub_02030FE4
_021E6A72:
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bne _021E6A80
	add sp, #4
	mov r0, #0x1e
	pop {r3, r4, pc}
_021E6A80:
	mov r0, #0x1d
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov86_021E6A34


	thumb_func_start ov86_021E6A88
ov86_021E6A88: ; 0x021E6A88
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r0, #0x10
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
	ldr r0, _021E6BA0 ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x15
	add r3, r1, #0
	bl ov86_021E6024
	ldrb r0, [r4, #6]
	cmp r0, #0
	bne _021E6ACA
	mov r2, #0x1a
	b _021E6ACC
_021E6ACA:
	mov r2, #0x1b
_021E6ACC:
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E6BA0 ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r3, #0xe0
	bl ov86_021E6024
	ldrb r1, [r4, #6]
	add r0, r4, #0
	bl ov86_021E6DD8
	mov r3, #0
	add r2, r0, #0
	str r3, [sp]
	ldr r0, _021E6BA4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #2
	bl ov86_021E6024
	ldrb r0, [r4, #6]
	bl sub_0205C310
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
	ldr r0, _021E6BA4 ; =0x00010200
	mov r1, #2
	str r0, [sp, #8]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	str r1, [sp, #0xc]
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6BA4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #3
	mov r2, #0x2b
	bl ov86_021E6024
	ldrb r0, [r4, #6]
	bl sub_0205C350
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
	ldr r0, _021E6BA4 ; =0x00010200
	mov r1, #3
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	bl ov86_021E6064
	add r0, r4, #0
	add r0, #0x10
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
_021E6BA0: .word 0x000F0200
_021E6BA4: .word 0x00010200
	thumb_func_end ov86_021E6A88


	thumb_func_start ov86_021E6BA8
ov86_021E6BA8: ; 0x021E6BA8
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
	add r0, r4, #0
	add r0, #0x80
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r4, #0
	add r0, #0x90
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E6DD0 ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	mov r2, #0x15
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl ov86_021E6024
	mov r1, #0
	str r1, [sp]
	ldr r0, _021E6DD0 ; =0x000F0200
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x1c
	mov r3, #0xe0
	bl ov86_021E6024
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6DD4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x2c
	bl ov86_021E6024
	ldrb r1, [r4, #6]
	add r0, r4, #0
	bl ov86_021E6DD8
	mov r3, #0
	add r2, r0, #0
	str r3, [sp]
	ldr r0, _021E6DD4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #4
	str r3, [sp, #0xc]
	bl ov86_021E6024
	ldrb r0, [r4, #6]
	bl sub_0205C310
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
	ldr r0, _021E6DD4 ; =0x00010200
	mov r1, #4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6DD4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r4, #0
	mov r1, #5
	mov r2, #0x2b
	bl ov86_021E6024
	ldrb r0, [r4, #6]
	bl sub_0205C350
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
	ldr r0, _021E6DD4 ; =0x00010200
	mov r1, #5
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6DD4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #6
	mov r2, #0x2d
	str r3, [sp, #0xc]
	bl ov86_021E6024
	add r0, r4, #0
	mov r1, #3
	bl ov86_021E6DD8
	mov r3, #0
	add r2, r0, #0
	str r3, [sp]
	ldr r0, _021E6DD4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #7
	str r3, [sp, #0xc]
	bl ov86_021E6024
	mov r0, #3
	bl sub_0205C310
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
	ldr r0, _021E6DD4 ; =0x00010200
	mov r1, #7
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	bl ov86_021E6064
	mov r3, #0
	str r3, [sp]
	ldr r0, _021E6DD4 ; =0x00010200
	str r3, [sp, #4]
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #8
	mov r2, #0x2b
	str r3, [sp, #0xc]
	bl ov86_021E6024
	mov r0, #3
	bl sub_0205C350
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
	ldr r0, _021E6DD4 ; =0x00010200
	mov r1, #8
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r2, #0x32
	mov r3, #0x70
	bl ov86_021E6064
	add r0, r4, #0
	add r0, #0x10
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x20
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x50
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x60
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x70
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x80
	bl ScheduleWindowCopyToVram
	add r4, #0x90
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_021E6DD0: .word 0x000F0200
_021E6DD4: .word 0x00010200
	thumb_func_end ov86_021E6BA8


	thumb_func_start ov86_021E6DD8
ov86_021E6DD8: ; 0x021E6DD8
	push {r4, lr}
	add r4, r1, #0
	mov r1, #0x89
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl Save_FrontierData_Get
	cmp r4, #6
	bhi _021E6E1C
	add r1, r4, r4
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E6DF6: ; jump table
	.short _021E6E04 - _021E6DF6 - 2 ; case 0
	.short _021E6E08 - _021E6DF6 - 2 ; case 1
	.short _021E6E0C - _021E6DF6 - 2 ; case 2
	.short _021E6E10 - _021E6DF6 - 2 ; case 3
	.short _021E6E14 - _021E6DF6 - 2 ; case 4
	.short _021E6E1C - _021E6DF6 - 2 ; case 5
	.short _021E6E18 - _021E6DF6 - 2 ; case 6
_021E6E04:
	mov r1, #8
	b _021E6E1E
_021E6E08:
	mov r1, #9
	b _021E6E1E
_021E6E0C:
	mov r1, #0xa
	b _021E6E1E
_021E6E10:
	mov r1, #0xb
	b _021E6E1E
_021E6E14:
	mov r1, #0xc
	b _021E6E1E
_021E6E18:
	mov r1, #0xf
	b _021E6E1E
_021E6E1C:
	mov r1, #8
_021E6E1E:
	mov r2, #0
	bl sub_0202D5DC
	cmp r0, #1
	bne _021E6E2C
	mov r0, #0x1e
	pop {r4, pc}
_021E6E2C:
	mov r0, #0x1d
	pop {r4, pc}
	thumb_func_end ov86_021E6DD8


	thumb_func_start ov86_021E6E30
ov86_021E6E30: ; 0x021E6E30
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0x21
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x27
	bl NewString_ReadMsgData
	add r4, r0, #0
	mov r0, #0x8f
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x8f
	lsl r0, r0, #2
	add r0, r5, r0
	bl GetWindowWidth
	add r2, r0, #0
	mov r0, #4
	str r0, [sp]
	ldr r0, _021E6E94 ; =0x000F0100
	lsl r3, r2, #3
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0x8f
	lsr r2, r3, #0x1f
	add r2, r3, r2
	lsl r0, r0, #2
	add r0, r5, r0
	add r1, r4, #0
	asr r2, r2, #1
	mov r3, #0
	bl ov86_021E5FD8
	mov r0, #0x8f
	lsl r0, r0, #2
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	bl String_Delete
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_021E6E94: .word 0x000F0100
	thumb_func_end ov86_021E6E30


	thumb_func_start ov86_021E6E98
ov86_021E6E98: ; 0x021E6E98
	push {r4, r5, r6, r7, lr}
	sub sp, #0x5c
	add r5, r0, #0
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0x79
	bl SpriteSystem_Alloc
	mov r1, #0x8b
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	bl SpriteManager_New
	mov r7, #0x23
	lsl r7, r7, #4
	add r2, sp, #0x3c
	ldr r3, _021E6FE0 ; =ov86_021E7F74
	str r0, [r5, r7]
	ldmia r3!, {r0, r1}
	add r6, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	ldr r4, _021E6FE4 ; =ov86_021E7ED8
	stmia r2!, {r0, r1}
	add r3, sp, #0x28
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	add r1, r6, #0
	str r0, [r3]
	sub r0, r7, #4
	ldr r0, [r5, r0]
	mov r3, #0x20
	bl SpriteSystem_Init
	ldr r3, _021E6FE8 ; =ov86_021E7EEC
	add r2, sp, #0x10
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	sub r1, r7, #4
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #2
	bl SpriteSystem_InitSprites
	sub r1, r7, #4
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, sp, #0x10
	bl SpriteSystem_InitManagerWithCapacities
	sub r0, r7, #4
	ldr r0, [r5, r0]
	bl SpriteSystem_GetRenderer
	mov r2, #2
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	mov r0, #0xb8
	mov r1, #0x79
	bl NARC_New
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6FEC ; =0x0000D8CC
	sub r1, r7, #4
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x33
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _021E6FEC ; =0x0000D8CC
	sub r1, r7, #4
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x40
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E6FEC ; =0x0000D8CC
	sub r1, r7, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x31
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E6FEC ; =0x0000D8CC
	sub r1, r7, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x32
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	ldr r6, _021E6FF0 ; =ov86_021E802C
	mov r7, #0
	add r4, r5, #0
_021E6FB8:
	mov r0, #0x8b
	mov r1, #0x23
	lsl r0, r0, #2
	lsl r1, r1, #4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl SpriteSystem_NewSprite
	mov r1, #0x8d
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r7, r7, #1
	add r6, #0x34
	add r4, r4, #4
	cmp r7, #2
	blo _021E6FB8
	add sp, #0x5c
	pop {r4, r5, r6, r7, pc}
	nop
_021E6FE0: .word ov86_021E7F74
_021E6FE4: .word ov86_021E7ED8
_021E6FE8: .word ov86_021E7EEC
_021E6FEC: .word 0x0000D8CC
_021E6FF0: .word ov86_021E802C
	thumb_func_end ov86_021E6E98


	thumb_func_start ov86_021E6FF4
ov86_021E6FF4: ; 0x021E6FF4
	push {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	mov r7, #0x8d
	str r0, [sp]
	add r5, r0, #0
	add r6, r4, #0
	lsl r7, r7, #2
_021E7002:
	ldr r0, [r5, r7]
	cmp r0, #0
	beq _021E7012
	bl Sprite_DeleteAndFreeResources
	mov r0, #0x8d
	lsl r0, r0, #2
	str r6, [r5, r0]
_021E7012:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blo _021E7002
	mov r1, #0x8b
	lsl r1, r1, #2
	ldr r0, [sp]
	add r2, r1, #4
	ldr r0, [r0, r1]
	ldr r1, [sp]
	ldr r1, [r1, r2]
	bl SpriteSystem_FreeResourcesAndManager
	mov r1, #0x8b
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	bl SpriteSystem_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov86_021E6FF4

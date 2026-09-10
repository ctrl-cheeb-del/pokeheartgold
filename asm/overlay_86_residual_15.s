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

	thumb_func_start ov86_021E7B68
ov86_021E7B68: ; 0x021E7B68
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r4, r0, #0
	ldr r0, _021E7C5C ; =0x0000025E
	ldrh r0, [r4, r0]
	cmp r0, #0
	bne _021E7B7C
	mov r0, #5
	str r0, [sp, #0x10]
	b _021E7B80
_021E7B7C:
	mov r0, #0xd
	str r0, [sp, #0x10]
_021E7B80:
	mov r0, #0x97
	lsl r0, r0, #2
	ldrsb r0, [r4, r0]
	add r7, r4, #0
	mov r6, #0
	lsl r0, r0, #0x13
	lsr r0, r0, #0x10
	str r0, [sp, #0x18]
	lsl r0, r0, #1
	str r0, [sp, #0x14]
	add r7, #0x10
_021E7B96:
	ldr r0, [sp, #0x10]
	mov r1, #0
	add r0, r0, r6
	lsl r0, r0, #4
	str r0, [sp, #0x20]
	add r0, r7, r0
	bl FillWindowPixelBuffer
	mov r0, #0x96
	lsl r0, r0, #2
	ldrh r0, [r4, r0]
	lsl r0, r0, #3
	add r1, r4, r0
	mov r0, #0x99
	lsl r0, r0, #2
	ldr r2, [r1, r0]
	ldr r0, [sp, #0x18]
	add r0, r0, r6
	cmp r2, r0
	bls _021E7C06
	mov r2, #0x26
	lsl r2, r2, #4
	ldr r3, [r1, r2]
	ldr r1, [sp, #0x14]
	lsl r2, r6, #1
	add r1, r1, r3
	ldrh r1, [r2, r1]
	add r0, r4, #0
	bl ov86_021E668C
	ldr r0, [sp, #0x20]
	add r0, r7, r0
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _021E7C60 ; =0x000F0100
	lsl r5, r3, #3
	ldr r1, [sp, #0x10]
	lsr r3, r5, #0x1f
	str r0, [sp, #8]
	mov r0, #2
	add r3, r5, r3
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r1, r1, r6
	mov r2, #0x13
	asr r3, r3, #1
	bl ov86_021E6064
	mov r0, #0
	str r0, [sp, #0x1c]
	b _021E7C0A
_021E7C06:
	mov r0, #1
	str r0, [sp, #0x1c]
_021E7C0A:
	ldr r0, [sp, #0x20]
	add r0, r7, r0
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r1, r6, #0
	bl ov86_021E78B8
	ldr r0, _021E7C64 ; =0x00000252
	mov r2, #0x25
	ldrb r0, [r4, r0]
	ldr r3, _021E7C68 ; =0x00000251
	lsl r2, r2, #4
	str r0, [sp]
	ldr r0, _021E7C6C ; =0x00000253
	mov r1, #2
	ldrb r0, [r4, r0]
	str r0, [sp, #4]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #8]
	ldrb r2, [r4, r2]
	ldrb r3, [r4, r3]
	ldr r0, [r4, #0xc]
	bl BgTilemapRectChangePalette
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #8
	blo _021E7B96
	ldr r0, [r4, #0xc]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	ldr r1, _021E7C5C ; =0x0000025E
	mov r0, #1
	ldrh r2, [r4, r1]
	eor r0, r2
	strh r0, [r4, r1]
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E7C5C: .word 0x0000025E
_021E7C60: .word 0x000F0100
_021E7C64: .word 0x00000252
_021E7C68: .word 0x00000251
_021E7C6C: .word 0x00000253
	thumb_func_end ov86_021E7B68

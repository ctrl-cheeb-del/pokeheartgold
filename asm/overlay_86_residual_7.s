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

	thumb_func_start ov86_021E7258
ov86_021E7258: ; 0x021E7258
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #0
	beq _021E726A
	cmp r1, #1
	beq _021E72A2
	cmp r1, #2
	beq _021E72E4
	b _021E7338
_021E726A:
	mov r2, #0
	ldr r0, [r4, #0xc]
	mov r1, #2
	add r3, r2, #0
	bl ScheduleSetBgPosText
	ldr r0, [r4, #0xc]
	mov r1, #2
	mov r2, #3
	mov r3, #0
	bl ScheduleSetBgPosText
	add r0, r4, #0
	bl ov86_021E7C70
	add r0, r4, #0
	bl ov86_021E73CC
	add r0, r4, #0
	bl ov86_021E7D8C
	add r0, r4, #0
	bl ov86_021E7DA8
	add r0, r4, #0
	bl ov86_021E757C
	b _021E7338
_021E72A2:
	mov r2, #0
	ldr r0, [r4, #0xc]
	mov r1, #2
	add r3, r2, #0
	bl ScheduleSetBgPosText
	mov r2, #3
	add r3, r2, #0
	ldr r0, [r4, #0xc]
	mov r1, #2
	add r3, #0xfd
	bl ScheduleSetBgPosText
	add r0, r4, #0
	bl ov86_021E7C70
	add r0, r4, #0
	add r0, #0x50
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	bl ov86_021E73CC
	add r0, r4, #0
	bl ov86_021E7630
	add r0, r4, #0
	bl ov86_021E77BC
	add r0, r4, #0
	bl ov86_021E752C
	b _021E7338
_021E72E4:
	mov r1, #2
	add r3, r1, #0
	ldr r0, [r4, #0xc]
	mov r2, #0
	add r3, #0xfe
	bl ScheduleSetBgPosText
	mov r2, #3
	add r3, r2, #0
	ldr r0, [r4, #0xc]
	mov r1, #2
	add r3, #0xfd
	bl ScheduleSetBgPosText
	add r0, r4, #0
	add r0, #0x50
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	bl ov86_021E7DD4
	add r0, r4, #0
	bl ov86_021E7B68
	add r0, r4, #0
	bl ov86_021E7CF8
	add r0, r4, #0
	bl ov86_021E7344
	add r0, r4, #0
	bl ov86_021E7CA0
	add r0, r4, #0
	bl ov86_021E73CC
	add r0, r4, #0
	bl ov86_021E7860
	add r0, r4, #0
	bl ov86_021E752C
_021E7338:
	ldr r0, [r4, #0xc]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov86_021E7258


	thumb_func_start ov86_021E7344
ov86_021E7344: ; 0x021E7344
	push {r3, r4, lr}
	sub sp, #0xc
	ldr r2, _021E73C8 ; =0x0000025D
	add r4, r0, #0
	ldrsb r0, [r4, r2]
	cmp r0, #0
	bne _021E7388
	mov r0, #0x34
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r2, #0xdd
	str r0, [sp, #8]
	lsl r2, r2, #2
	ldr r0, [r4, #0xc]
	mov r1, #2
	add r2, r4, r2
	mov r3, #0x22
	bl LoadRectToBgTilemapRect
	mov r0, #0x34
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r2, #0xdd
	str r0, [sp, #8]
	lsl r2, r2, #2
	ldr r0, [r4, #0xc]
	mov r1, #2
	add r2, r4, r2
	mov r3, #0x26
	bl LoadRectToBgTilemapRect
	b _021E73BA
_021E7388:
	mov r0, #0x34
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r2, #0xd7
	ldr r0, [r4, #0xc]
	mov r1, #2
	add r2, r4, r2
	mov r3, #0x22
	bl LoadRectToBgTilemapRect
	mov r0, #0x34
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r2, #0xd5
	str r0, [sp, #8]
	lsl r2, r2, #2
	ldr r0, [r4, #0xc]
	mov r1, #2
	add r2, r4, r2
	mov r3, #0x26
	bl LoadRectToBgTilemapRect
_021E73BA:
	ldr r0, [r4, #0xc]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0xc
	pop {r3, r4, pc}
	nop
_021E73C8: .word 0x0000025D
	thumb_func_end ov86_021E7344

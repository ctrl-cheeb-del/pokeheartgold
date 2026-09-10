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

	thumb_func_start ov86_021E7688
ov86_021E7688: ; 0x021E7688
	push {r3, r4, r5, lr}
	add r4, r1, #0
	mov r1, #0x93
	add r5, r0, #0
	lsl r1, r1, #2
	ldrb r2, [r5, r1]
	mov r0, #1
	bic r2, r0
	mov r0, #1
	orr r0, r2
	strb r0, [r5, r1]
	ldrb r2, [r5, r1]
	mov r0, #0xfe
	bic r2, r0
	mov r0, #4
	orr r0, r2
	strb r0, [r5, r1]
	add r0, r1, #1
	ldrb r2, [r5, r0]
	mov r0, #0xf
	bic r2, r0
	mov r0, #2
	orr r2, r0
	add r0, r1, #1
	strb r2, [r5, r0]
	ldrb r2, [r5, r0]
	mov r0, #0xf0
	bic r2, r0
	add r0, r1, #1
	strb r2, [r5, r0]
	ldr r0, _021E7708 ; =ov86_021E81DC
	mov r1, #7
	ldrb r4, [r0, r4]
	add r0, r4, #0
	bl _u32_div_f
	lsl r0, r1, #5
	add r0, #0x18
	lsr r1, r0, #3
	mov r0, #0x25
	lsl r0, r0, #4
	strb r1, [r5, r0]
	add r0, r4, #0
	mov r1, #7
	bl _u32_div_f
	lsl r0, r0, #5
	add r0, #0x28
	lsr r1, r0, #3
	ldr r0, _021E770C ; =0x00000251
	add r1, #0x20
	strb r1, [r5, r0]
	mov r2, #2
	add r1, r0, #1
	strb r2, [r5, r1]
	add r1, r0, #2
	strb r2, [r5, r1]
	sub r1, r0, #3
	mov r2, #0
	strb r2, [r5, r1]
	sub r0, r0, #2
	strb r2, [r5, r0]
	pop {r3, r4, r5, pc}
	nop
_021E7708: .word ov86_021E81DC
_021E770C: .word 0x00000251
	thumb_func_end ov86_021E7688


	thumb_func_start ov86_021E7710
ov86_021E7710: ; 0x021E7710
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	mov r0, #0x95
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl GridInputHandler_HandleInput_NoHold
	add r5, r0, #0
	cmp r5, #0x1a
	bhi _021E7728
	beq _021E7742
	b _021E7764
_021E7728:
	add r0, r5, #4
	cmp r0, #3
	bhi _021E7764
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E773A: ; jump table
	.short _021E77AA - _021E773A - 2 ; case 0
	.short _021E775C - _021E773A - 2 ; case 1
	.short _021E7742 - _021E773A - 2 ; case 2
	.short _021E77AA - _021E773A - 2 ; case 3
_021E7742:
	ldr r0, _021E77B0 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	bl ov86_021E71C0
	add r0, r4, #0
	bl ov86_021E723C
	mov r0, #0xa
	strb r0, [r4, #5]
	mov r0, #9
	pop {r3, r4, r5, r6, r7, pc}
_021E775C:
	ldr r0, _021E77B4 ; =0x000005DC
	bl PlaySE
	b _021E77AA
_021E7764:
	mov r0, #0x99
	lsl r0, r0, #2
	add r6, r4, r0
	lsl r7, r5, #3
	ldr r0, [r6, r7]
	cmp r0, #0
	bne _021E777A
	ldr r0, _021E77B8 ; =0x000005F2
	bl PlaySE
	b _021E77AA
_021E777A:
	ldr r0, _021E77B0 ; =0x000005DD
	bl PlaySE
	mov r1, #0x96
	lsl r1, r1, #2
	strh r5, [r4, r1]
	mov r2, #0
	add r0, r1, #2
	strh r2, [r4, r0]
	add r0, r1, #4
	strb r2, [r4, r0]
	ldr r0, [r6, r7]
	sub r0, r0, #1
	lsr r2, r0, #3
	add r0, r1, #5
	strb r2, [r4, r0]
	ldrh r1, [r4, r1]
	add r0, r4, #0
	bl ov86_021E7688
	mov r0, #4
	strb r0, [r4, #5]
	mov r0, #9
	pop {r3, r4, r5, r6, r7, pc}
_021E77AA:
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E77B0: .word 0x000005DD
_021E77B4: .word 0x000005DC
_021E77B8: .word 0x000005F2
	thumb_func_end ov86_021E7710


	thumb_func_start ov86_021E77BC
ov86_021E77BC: ; 0x021E77BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r6, #0
	add r4, r5, #0
	mov r7, #1
_021E77C8:
	mov r0, #0x99
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _021E77FA
	add r0, r5, #0
	add r1, r6, #0
	bl ov86_021E7688
	ldr r0, _021E7810 ; =0x00000252
	mov r2, #0x25
	ldrb r0, [r5, r0]
	ldr r3, _021E7814 ; =0x00000251
	lsl r2, r2, #4
	str r0, [sp]
	ldr r0, _021E7818 ; =0x00000253
	mov r1, #2
	ldrb r0, [r5, r0]
	str r0, [sp, #4]
	str r7, [sp, #8]
	ldrb r2, [r5, r2]
	ldrb r3, [r5, r3]
	ldr r0, [r5, #0xc]
	bl BgTilemapRectChangePalette
_021E77FA:
	add r6, r6, #1
	add r4, #8
	cmp r6, #0x1a
	blo _021E77C8
	ldr r0, [r5, #0xc]
	mov r1, #2
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021E7810: .word 0x00000252
_021E7814: .word 0x00000251
_021E7818: .word 0x00000253
	thumb_func_end ov86_021E77BC

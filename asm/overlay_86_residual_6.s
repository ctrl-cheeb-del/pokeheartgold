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

	thumb_func_start ov86_021E7094
ov86_021E7094: ; 0x021E7094
	push {r3, r4, lr}
	sub sp, #0xc
	ldr r3, _021E71B8 ; =0x0000024E
	add r4, r0, #0
	ldrb r0, [r4, r3]
	cmp r0, #0
	beq _021E70AC
	cmp r0, #1
	beq _021E7118
	cmp r0, #2
	beq _021E719C
	b _021E71B2
_021E70AC:
	sub r0, r3, #2
	ldrb r0, [r4, r0]
	lsl r1, r0, #0x1f
	lsr r1, r1, #0x1f
	bne _021E70D2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x19
	lsl r0, r0, #2
	add r1, r4, r0
	add r0, r3, #0
	sub r0, #0x1a
	ldr r0, [r1, r0]
	sub r1, r3, #1
	ldrb r1, [r4, r1]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	bl ManagedSprite_SetPaletteOverride
	b _021E710E
_021E70D2:
	add r0, r3, #4
	ldrb r0, [r4, r0]
	sub r1, r3, #2
	add r2, r3, #2
	str r0, [sp]
	add r0, r3, #5
	ldrb r0, [r4, r0]
	str r0, [sp, #4]
	sub r0, r3, #1
	ldrb r0, [r4, r0]
	add r3, r3, #3
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	str r0, [sp, #8]
	ldrb r1, [r4, r1]
	ldrb r2, [r4, r2]
	ldrb r3, [r4, r3]
	lsl r1, r1, #0x18
	ldr r0, [r4, #0xc]
	lsr r1, r1, #0x19
	bl BgTilemapRectChangePalette
	mov r1, #0x93
	lsl r1, r1, #2
	ldrb r1, [r4, r1]
	ldr r0, [r4, #0xc]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x19
	bl ScheduleBgTilemapBufferTransfer
_021E710E:
	ldr r0, _021E71B8 ; =0x0000024E
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E71B2
_021E7118:
	add r0, r3, #1
	ldrb r0, [r4, r0]
	add r1, r0, #1
	add r0, r3, #1
	strb r1, [r4, r0]
	ldrb r0, [r4, r0]
	cmp r0, #4
	bne _021E71B2
	sub r0, r3, #2
	ldrb r0, [r4, r0]
	lsl r1, r0, #0x1f
	lsr r1, r1, #0x1f
	bne _021E714E
	lsl r0, r0, #0x18
	lsr r0, r0, #0x19
	lsl r0, r0, #2
	add r1, r4, r0
	add r0, r3, #0
	sub r0, #0x1a
	ldr r0, [r1, r0]
	sub r1, r3, #1
	ldrb r1, [r4, r1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	bl ManagedSprite_SetPaletteOverride
	b _021E718A
_021E714E:
	add r0, r3, #4
	ldrb r0, [r4, r0]
	sub r1, r3, #2
	add r2, r3, #2
	str r0, [sp]
	add r0, r3, #5
	ldrb r0, [r4, r0]
	str r0, [sp, #4]
	sub r0, r3, #1
	ldrb r0, [r4, r0]
	add r3, r3, #3
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	str r0, [sp, #8]
	ldrb r1, [r4, r1]
	ldrb r2, [r4, r2]
	ldrb r3, [r4, r3]
	lsl r1, r1, #0x18
	ldr r0, [r4, #0xc]
	lsr r1, r1, #0x19
	bl BgTilemapRectChangePalette
	mov r1, #0x93
	lsl r1, r1, #2
	ldrb r1, [r4, r1]
	ldr r0, [r4, #0xc]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x19
	bl ScheduleBgTilemapBufferTransfer
_021E718A:
	ldr r0, _021E71BC ; =0x0000024F
	mov r1, #0
	strb r1, [r4, r0]
	sub r1, r0, #1
	ldrb r1, [r4, r1]
	sub r0, r0, #1
	add r1, r1, #1
	strb r1, [r4, r0]
	b _021E71B2
_021E719C:
	add r0, r3, #1
	ldrb r0, [r4, r0]
	add r1, r0, #1
	add r0, r3, #1
	strb r1, [r4, r0]
	ldrb r0, [r4, r0]
	cmp r0, #2
	bne _021E71B2
	add sp, #0xc
	mov r0, #0
	pop {r3, r4, pc}
_021E71B2:
	mov r0, #1
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_021E71B8: .word 0x0000024E
_021E71BC: .word 0x0000024F
	thumb_func_end ov86_021E7094


	thumb_func_start ov86_021E71C0
ov86_021E71C0: ; 0x021E71C0
	mov r2, #0x93
	lsl r2, r2, #2
	ldrb r3, [r0, r2]
	mov r1, #1
	bic r3, r1
	strb r3, [r0, r2]
	ldrb r3, [r0, r2]
	mov r1, #0xfe
	bic r3, r1
	add r1, r2, #1
	strb r3, [r0, r2]
	ldrb r3, [r0, r1]
	mov r1, #0xf
	bic r3, r1
	mov r1, #1
	orr r3, r1
	add r1, r2, #1
	strb r3, [r0, r1]
	ldrb r3, [r0, r1]
	mov r1, #0xf0
	bic r3, r1
	add r1, r2, #1
	strb r3, [r0, r1]
	mov r3, #0
	add r1, r2, #2
	strb r3, [r0, r1]
	add r1, r2, #3
	strb r3, [r0, r1]
	bx lr
	.balign 4, 0
	thumb_func_end ov86_021E71C0

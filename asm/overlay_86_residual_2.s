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

	thumb_func_start ov86_021E5D30
ov86_021E5D30: ; 0x021E5D30
	push {r3, r4, r5, lr}
	sub sp, #0x80
	ldr r5, _021E5DF8 ; =ov86_021E7EC8
	add r3, sp, #0x70
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _021E5DFC ; =ov86_021E7F04
	add r3, sp, #0x54
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0
	str r0, [r3]
	add r0, r4, #0
	add r3, r1, #0
	bl InitBgFromTemplate
	mov r0, #0
	mov r1, #0x20
	add r2, r0, #0
	mov r3, #0x79
	bl BG_ClearCharDataRange
	add r0, r4, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E5E00 ; =ov86_021E7F20
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #2
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldr r5, _021E5E04 ; =ov86_021E7F3C
	add r3, sp, #0x1c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #4
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x79
	bl BG_ClearCharDataRange
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r5, _021E5E08 ; =ov86_021E7F58
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #6
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add sp, #0x80
	pop {r3, r4, r5, pc}
	nop
_021E5DF8: .word ov86_021E7EC8
_021E5DFC: .word ov86_021E7F04
_021E5E00: .word ov86_021E7F20
_021E5E04: .word ov86_021E7F3C
_021E5E08: .word ov86_021E7F58
	thumb_func_end ov86_021E5D30


	thumb_func_start ov86_021E5E0C
ov86_021E5E0C: ; 0x021E5E0C
	push {r4, lr}
	add r4, r0, #0
	bl ov86_021E5D10
	ldr r0, [r4, #0xc]
	bl ov86_021E5D30
	mov r0, #0x79
	bl PaletteData_Init
	mov r1, #0x87
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #2
	lsl r2, r1, #8
	mov r3, #0x79
	bl PaletteData_AllocBuffers
	mov r2, #0x87
	lsl r2, r2, #2
	ldr r0, [r4, r2]
	mov r1, #0
	sub r2, #0x1c
	mov r3, #0x79
	bl PaletteData_AllocBuffers
	add r0, r4, #0
	mov r1, #2
	bl ov86_021E5ECC
	add r0, r4, #0
	mov r1, #6
	bl ov86_021E5F58
	pop {r4, pc}
	thumb_func_end ov86_021E5E0C

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

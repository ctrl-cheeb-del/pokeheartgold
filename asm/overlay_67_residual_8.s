	.include "asm/macros.inc"
	.include "overlay_67.inc"
	.include "global.inc"

	.public ov67_021E6D50
	.public ov67_021E6D5C
	.public ov67_021E6D6C
	.public ov67_021E6D7C
	.public ov67_021E6D90
	.public ov67_021E6DA8
	.public ov67_021E6DC4
	.public ov67_021E6DE0
	.public ov67_021E6DFC
	.public ov67_021E6E18
	.public ov67_021E6E38
	.public ov67_021E6E60
	.public ov67_021E6E98
	.public ov67_021E6EE8
	.public ov67_021E6F50
	.public ov67_021E7020

	.public _021E6D4C

	.text
	.public ov67_021E5900
	.public ov67_021E5968
	.public ov67_021E5984
	.public ov67_021E5A6C
	.public ov67_021E5B44
	.public ov67_021E5BC0
	.public ov67_021E5BE0
	.public ov67_021E5C04
	.public ov67_021E5C44
	.public ov67_021E5DA0
	.public ov67_021E5E84
	.public ov67_021E5EB0
	.public ov67_021E6008
	.public ov67_021E6080
	.public ov67_021E60B4
	.public ov67_021E60F4
	.public ov67_021E6118
	.public ov67_021E6164
	.public ov67_021E61A0
	.public ov67_021E61E8
	.public ov67_021E6220
	.public ov67_021E63E8
	.public ov67_021E6474
	.public ov67_021E6490
	.public ov67_021E6530
	.public ov67_021E65C0
	.public ov67_021E6688
	.public ov67_021E681C
	.public ov67_021E6820
	.public ov67_021E6990
	.public ov67_021E69D8
	.public ov67_021E6A00
	.public ov67_021E6A08
	.public ov67_021E6A28
	.public ov67_021E6A40
	.public ov67_021E6B6C
	.public ov67_021E6BB8
	.public ov67_021E6BC4
	.public ov67_021E6C04
	.public ov67_021E6C14
	.public ov67_021E6C5C
	.public ov67_021E6C60
	.public ov67_021E6D20
	thumb_func_start ov67_021E6820
ov67_021E6820: ; 0x021E6820
	push {r4, r5, r6, r7, lr}
	sub sp, #0x5c
	add r5, r0, #0
	ldr r0, [r5]
	bl SpriteSystem_Alloc
	ldr r1, _021E6974 ; =0x0000047C
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	bl SpriteManager_New
	mov r7, #0x12
	lsl r7, r7, #6
	add r2, sp, #0x3c
	ldr r3, _021E6978 ; =ov67_021E6E18
	str r0, [r5, r7]
	ldmia r3!, {r0, r1}
	add r6, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	ldr r4, _021E697C ; =ov67_021E6D7C
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
	sub r1, r7, #4
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #4
	bl SpriteSystem_InitSprites
	ldr r4, _021E6980 ; =ov67_021E6D90
	add r3, sp, #0x10
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r1, r7, #4
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	bl SpriteSystem_InitManagerWithCapacities
	sub r0, r7, #4
	ldr r0, [r5, r0]
	bl SpriteSystem_GetRenderer
	mov r2, #2
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	ldr r1, [r5]
	mov r0, #0x76
	bl NARC_New
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E6984 ; =0x0000D158
	sub r1, r7, #4
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _021E6984 ; =0x0000D158
	sub r1, r7, #4
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #3
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	mov r3, #1
	ldr r0, _021E6984 ; =0x0000D158
	str r3, [sp]
	sub r1, r7, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E6984 ; =0x0000D158
	sub r1, r7, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #2
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	ldr r6, _021E6988 ; =ov67_021E6F50
	mov r7, #0
	add r4, r5, #0
_021E692C:
	ldr r0, _021E6974 ; =0x0000047C
	mov r1, #0x12
	lsl r1, r1, #6
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl SpriteSystem_NewSprite
	ldr r1, _021E698C ; =0x00000484
	add r7, r7, #1
	str r0, [r4, r1]
	add r6, #0x34
	add r4, r4, #4
	cmp r7, #4
	blo _021E692C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _021E6968
	add r0, r1, #0
	add r0, #8
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x49
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_021E6968:
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add sp, #0x5c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6974: .word 0x0000047C
_021E6978: .word ov67_021E6E18
_021E697C: .word ov67_021E6D7C
_021E6980: .word ov67_021E6D90
_021E6984: .word 0x0000D158
_021E6988: .word ov67_021E6F50
_021E698C: .word 0x00000484
	thumb_func_end ov67_021E6820


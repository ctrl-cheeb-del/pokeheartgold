	.include "asm/macros.inc"
	.include "overlay_95.inc"
	.include "global.inc"
	.public HatchEggApp_Exit
	.public HatchEggApp_Init
	.public HatchEggApp_Main
	.public ov95_021E5954
	.public ov95_021E5974
	.public ov95_021E59F8
	.public ov95_021E5A38
	.public ov95_021E5BBC
	.public ov95_021E5C44
	.public ov95_021E5CAC
	.public ov95_021E5D44
	.public ov95_021E5D98
	.public ov95_021E5DB4
	.public ov95_021E5DD0
	.public ov95_021E5E18
	.public ov95_021E5E90
	.public ov95_021E5EC0
	.public ov95_021E5EF8
	.public ov95_021E6000
	.public ov95_021E60A4
	.public ov95_021E619C
	.public ov95_021E623C
	.public ov95_021E62A4
	.public ov95_021E6314
	.public ov95_021E65A0
	.public ov95_021E6838
	.public ov95_021E68A8
	.public ov95_021E6900
	.public ov95_021E6964
	.public ov95_021E6B74
	.public ov95_021E7020
	.public ov95_021E70BC
	.public ov95_021E7258
	.public ov95_021E7308
	.public ov95_021E7328
	.public ov95_021E7388
	.public ov95_021E7410
	.public ov95_021E7450
	.public ov95_021E7538
	.public ov95_021E7548
	.public ov95_021E755C
	.public ov95_021E7574
	.public ov95_021E7594
	.public ov95_021E75B4
	.public ov95_021E75DC
	.public ov95_021E762C
	.public ov95_021E767C
	.public ov95_021E76D0
	.public ov95_021E7770
	.public ov95_021E7810
	.public ov95_021E7818
	.public ov95_021E7820
	.public ov95_021E782C
	.public ov95_021E7860


	.text
	.public ov95_021E5900
	.public ov95_021E5928
	.public ov95_021E5B24
	.public ov95_021E5B58
	.public ov95_021E5B7C
	.public ov95_021E5B9C
	.public ov95_021E5D34
	.public ov95_021E5E40
	.public ov95_021E5E58
	.public ov95_021E5EDC
	.public ov95_021E5EF0
	.public ov95_021E6150
	.public ov95_021E6184
	.public ov95_021E6228
	.public ov95_021E62E4
	.public ov95_021E62F0
	.public ov95_021E6300
	.public ov95_021E67F0
	.public ov95_021E6FC4
	.public ov95_021E7078
	.public ov95_021E7208
	.public ov95_021E72B8
	.public ov95_021E7404
	.public ov95_021E7514

	thumb_func_start ov95_021E5EF8
ov95_021E5EF8: ; 0x021E5EF8
	push {r4, r5, r6, lr}
	sub sp, #0x38
	ldr r3, _021E5FDC ; =ov95_021E7594
	add r2, sp, #0x18
	add r6, r0, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r5, [r6, #0x50]
	ldr r4, [r6, #0x54]
	ldr r6, [r6, #8]
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E5FE0 ; =0x00004E20
	add r1, r5, #0
	str r0, [sp, #8]
	ldr r3, [sp, #0x18]
	add r0, r4, #0
	mov r2, #0x73
	bl SpriteSystem_LoadCharResObj
	mov r0, #0x73
	str r0, [sp]
	ldr r0, [sp, #0x1c]
	mov r1, #2
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _021E5FE4 ; =0x00004E21
	add r2, r4, #0
	str r0, [sp, #0x14]
	add r0, r6, #0
	add r3, r5, #0
	bl SpriteSystem_LoadPaletteBuffer
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E5FE8 ; =0x00004E22
	add r1, r5, #0
	str r0, [sp, #4]
	ldr r3, [sp, #0x20]
	add r0, r4, #0
	mov r2, #0x73
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E5FEC ; =0x00004E23
	add r1, r5, #0
	str r0, [sp, #4]
	ldr r3, [sp, #0x24]
	add r0, r4, #0
	mov r2, #0x73
	bl SpriteSystem_LoadAnimResObj
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _021E5FF0 ; =0x000061A8
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r2, #0x73
	mov r3, #7
	bl SpriteSystem_LoadCharResObj
	mov r0, #0x73
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, _021E5FF4 ; =0x000061A9
	mov r1, #2
	str r0, [sp, #0x14]
	add r0, r6, #0
	add r2, r4, #0
	add r3, r5, #0
	bl SpriteSystem_LoadPaletteBuffer
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E5FF8 ; =0x000061AA
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0x73
	mov r3, #6
	bl SpriteSystem_LoadCellResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _021E5FFC ; =0x000061AB
	add r1, r5, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0x73
	mov r3, #5
	bl SpriteSystem_LoadAnimResObj
	add sp, #0x38
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E5FDC: .word ov95_021E7594
_021E5FE0: .word 0x00004E20
_021E5FE4: .word 0x00004E21
_021E5FE8: .word 0x00004E22
_021E5FEC: .word 0x00004E23
_021E5FF0: .word 0x000061A8
_021E5FF4: .word 0x000061A9
_021E5FF8: .word 0x000061AA
_021E5FFC: .word 0x000061AB
	thumb_func_end ov95_021E5EF8


	thumb_func_start ov95_021E6000
ov95_021E6000: ; 0x021E6000
	push {r3, r4, lr}
	sub sp, #0x34
	add r4, r0, #0
	mov r1, #0x80
	add r0, sp, #0
	strh r1, [r0]
	mov r1, #0x78
	strh r1, [r0, #2]
	mov r1, #0
	strh r1, [r0, #4]
	strh r1, [r0, #6]
	mov r0, #1
	mov r2, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [sp, #0x30]
	ldr r1, _021E609C ; =0x00004E20
	str r0, [sp, #0x10]
	add r0, r1, #1
	str r0, [sp, #0x18]
	add r0, r1, #2
	str r0, [sp, #0x1c]
	add r0, r1, #3
	str r0, [sp, #0x20]
	sub r0, r2, #3
	str r2, [sp, #0x2c]
	str r1, [sp, #0x14]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x50]
	add r2, sp, #0
	bl SpriteSystem_NewSprite
	str r0, [r4, #0x74]
	bl ManagedSprite_TickFrame
	ldr r0, [r4, #0x74]
	mov r1, #2
	bl ManagedSprite_SetAffineOverwriteMode
	mov r2, #0
	add r0, sp, #0
	add r1, r2, #0
	strh r2, [r0]
	sub r1, #0x10
	strh r1, [r0, #2]
	ldr r1, _021E60A0 ; =0x000061A8
	str r2, [sp, #0x2c]
	add r0, r1, #1
	str r0, [sp, #0x18]
	add r0, r1, #2
	str r0, [sp, #0x1c]
	add r0, r1, #3
	str r1, [sp, #0x14]
	str r0, [sp, #0x20]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x50]
	add r2, sp, #0
	bl SpriteSystem_NewSprite
	str r0, [r4, #0x78]
	bl ManagedSprite_TickFrame
	mov r1, #0x90
	add r0, sp, #0
	strh r1, [r0, #2]
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x50]
	add r2, sp, #0
	bl SpriteSystem_NewSprite
	str r0, [r4, #0x7c]
	bl ManagedSprite_TickFrame
	add sp, #0x34
	pop {r3, r4, pc}
	nop
_021E609C: .word 0x00004E20
_021E60A0: .word 0x000061A8
	thumb_func_end ov95_021E6000


	thumb_func_start ov95_021E60A4
ov95_021E60A4: ; 0x021E60A4
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	str r0, [sp]
	add r0, #0x80
	add r3, r1, #0
	ldr r1, [r0]
	add r4, #0x80
	cmp r1, #0
	bne _021E6132
	ldr r0, [r4, #4]
	cmp r0, #0xa
	blt _021E60C6
	add r0, r1, #1
	str r0, [r4]
	mov r0, #0
	str r0, [r4, #4]
	b _021E6132
_021E60C6:
	mov r1, #0x14
	add r7, r3, #0
	mul r7, r1
	ldr r1, _021E6140 ; =ov95_021E75DC
	ldr r2, _021E6144 ; =ov95_021E762C
	lsl r6, r0, #1
	add r1, r1, r7
	add r2, r2, r7
	ldrsh r1, [r6, r1]
	ldrsh r2, [r6, r2]
	lsl r6, r0, #2
	mov r0, #0x28
	mul r0, r3
	ldr r3, _021E6148 ; =ov95_021E76D0
	mov r5, #0
	add r3, r3, r0
	ldr r7, [r6, r3]
	ldr r3, _021E614C ; =ov95_021E7770
	add r0, r3, r0
	ldr r6, [r6, r0]
	cmp r1, #0xff
	bne _021E60F6
	add r1, r5, #0
	add r5, r5, #1
_021E60F6:
	cmp r2, #0xff
	bne _021E60FE
	mov r2, #0
	add r5, r5, #1
_021E60FE:
	ldr r0, [sp]
	ldr r0, [r0, #0x74]
	bl ManagedSprite_OffsetPositionXY
	mov r0, #0
	add r1, r7, #0
	bl _fneq
	beq _021E611E
	ldr r0, [sp]
	add r1, r7, #0
	ldr r0, [r0, #0x74]
	add r2, r6, #0
	bl ManagedSprite_SetAffineScale
	b _021E6120
_021E611E:
	add r5, r5, #1
_021E6120:
	cmp r5, #3
	beq _021E612C
	ldr r0, [r4, #4]
	add r0, r0, #1
	str r0, [r4, #4]
	b _021E613A
_021E612C:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
_021E6132:
	mov r0, #0
	str r0, [r4]
	str r0, [r4, #4]
	pop {r3, r4, r5, r6, r7, pc}
_021E613A:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6140: .word ov95_021E75DC
_021E6144: .word ov95_021E762C
_021E6148: .word ov95_021E76D0
_021E614C: .word ov95_021E7770
	thumb_func_end ov95_021E60A4

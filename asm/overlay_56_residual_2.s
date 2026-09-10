	.include "asm/macros.inc"
	.public ov56_021E5C20
	.public ov56_021E5C9C
	.public ov56_021E5CB4
	.public ov56_021E5CE0
	.public ov56_021E5D08
	.public ov56_021E5D34
	.public ov56_021E5D40
	.public ov56_021E5D44
	.public ov56_021E5DA4
	.public ov56_021E5DDC
	.public ov56_021E5EFC
	.public ov56_021E5FB4
	.public ov56_021E5FDC
	.public ov56_021E609C
	.public ov56_021E60F4
	.public ov56_021E614C
	.public ov56_021E6228
	.public ov56_021E63C0
	.public ov56_021E63FC
	.public ov56_021E647C
	.public ov56_021E64C8
	.public ov56_021E64F4
	.public ov56_021E6514
	.public ov56_021E660C
	.public ov56_021E6650
	.public ov56_021E692C
	.public ov56_021E696C
	.public ov56_021E6A7C
	.public ov56_021E6AA4
	.public ov56_021E6BB4
	.public ov56_021E6D90
	.public _021E6DD4
	.public ov56_021E6DE4
	.public ov56_021E6DF4
	.public ov56_021E6E08
	.public ov56_021E6E20
	.public ov56_021E6E38
	.public ov56_021E6E58
	.public ov56_021E6E80
	.include "overlay_56.inc"
	.include "global.inc"

	.text

	thumb_func_start ov56_021E6BB4
ov56_021E6BB4: ; 0x021E6BB4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x94
	add r5, r0, #0
	bl sub_0203A964
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bne _021E6BC6
	b _021E6D7C
_021E6BC6:
	ldr r1, [r5]
	mov r0, #0x20
	bl GF_CreateVramTransferManager
	ldr r0, [r5]
	bl SpriteSystem_Alloc
	add r1, r5, #0
	add r1, #0xb0
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xb0
	ldr r0, [r0]
	bl SpriteManager_New
	add r1, r5, #0
	add r1, #0xb4
	add r2, sp, #0x40
	ldr r4, _021E6D80 ; =ov56_021E6E38
	str r0, [r1]
	ldmia r4!, {r0, r1}
	add r3, r2, #0
	stmia r2!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r4!, {r0, r1}
	ldr r6, _021E6D84 ; =ov56_021E6DF4
	stmia r2!, {r0, r1}
	add r4, sp, #0x2c
	ldmia r6!, {r0, r1}
	add r2, r4, #0
	stmia r4!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r4!, {r0, r1}
	ldr r0, [r6]
	ldr r6, _021E6D88 ; =ov56_021E6E08
	str r0, [r4]
	add r4, sp, #0x14
	ldmia r6!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r4!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r4!, {r0, r1}
	add r0, r5, #0
	add r0, #0xb0
	add r1, r3, #0
	ldr r0, [r0]
	mov r3, #0x20
	bl SpriteSystem_Init
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xb0
	add r1, #0xb4
	ldr r0, [r0]
	ldr r1, [r1]
	mov r2, #3
	bl SpriteSystem_InitSprites
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xb0
	add r1, #0xb4
	ldr r0, [r0]
	ldr r1, [r1]
	add r2, sp, #0x14
	bl SpriteSystem_InitManagerWithCapacities
	ldr r0, [r5]
	bl thunk_ClearMainOAM
	bl sub_02074490
	mov r1, #0
	add r3, r0, #0
	str r1, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xb0
	add r1, #0xb4
	ldr r0, [r0]
	ldr r1, [r1]
	mov r2, #0x14
	bl SpriteSystem_LoadPlttResObj
	bl sub_02074494
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xb0
	add r1, #0xb4
	ldr r0, [r0]
	ldr r1, [r1]
	mov r2, #0x14
	bl SpriteSystem_LoadCellResObj
	bl sub_020744A0
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xb0
	add r1, #0xb4
	ldr r0, [r0]
	ldr r1, [r1]
	mov r2, #0x14
	bl SpriteSystem_LoadAnimResObj
	mov r6, #0
	add r4, r6, #0
	str r6, [sp, #0x10]
	add r7, r5, #0
_021E6CC4:
	ldr r0, [r5, #0x1c]
	add r3, r0, r4
	ldrh r1, [r3, #0x18]
	ldr r0, _021E6D8C ; =0x0000FFFF
	cmp r1, r0
	beq _021E6D7C
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	ldrh r3, [r3, #0x18]
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xb0
	add r1, #0xb4
	lsl r3, r3, #0x14
	ldr r0, [r0]
	ldr r1, [r1]
	mov r2, #0x14
	lsr r3, r3, #0x14
	bl SpriteSystem_LoadCharResObjWithHardwareMappingType
	add r0, sp, #0x60
	mov r1, #0
	mov r2, #0x34
	bl MI_CpuFill8
	ldr r0, [sp, #0x10]
	mov r1, #0x80
	sub r1, r1, r0
	add r0, sp, #0x60
	strh r1, [r0]
	mov r1, #0xa0
	strh r1, [r0, #2]
	mov r1, #0
	strh r1, [r0, #4]
	strh r1, [r0, #6]
	mov r0, #2
	str r0, [sp, #0x8c]
	ldr r0, [r5, #0x1c]
	add r2, sp, #0x60
	add r0, r0, r4
	ldrh r0, [r0, #0x18]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x1c
	str r0, [sp, #0x6c]
	add r0, r1, #0
	str r0, [sp, #0x90]
	mov r0, #1
	str r0, [sp, #0x70]
	add r0, r1, #0
	str r0, [sp, #0x78]
	str r0, [sp, #0x7c]
	str r0, [sp, #0x80]
	sub r0, r1, #1
	str r0, [sp, #0x84]
	sub r0, r1, #1
	str r0, [sp, #0x88]
	add r0, r5, #0
	add r1, r5, #0
	str r6, [sp, #0x74]
	add r0, #0xb0
	add r1, #0xb4
	ldr r0, [r0]
	ldr r1, [r1]
	bl SpriteSystem_NewSprite
	add r1, r7, #0
	add r1, #0xb8
	str r0, [r1]
	ldr r0, [r5, #0x1c]
	add r0, r0, r4
	ldrh r0, [r0, #0x18]
	lsl r0, r0, #0x14
	lsr r0, r0, #0x14
	cmp r0, #7
	bne _021E6D6C
	add r0, r7, #0
	add r0, #0xb8
	ldr r0, [r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_021E6D6C:
	ldr r0, [sp, #0x10]
	add r6, r6, #1
	add r0, #0x28
	add r4, r4, #2
	add r7, r7, #4
	str r0, [sp, #0x10]
	cmp r6, #3
	blt _021E6CC4
_021E6D7C:
	add sp, #0x94
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6D80: .word ov56_021E6E38
_021E6D84: .word ov56_021E6DF4
_021E6D88: .word ov56_021E6E08
_021E6D8C: .word 0x0000FFFF
	thumb_func_end ov56_021E6BB4

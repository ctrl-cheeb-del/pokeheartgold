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

	thumb_func_start ov95_021E6838
ov95_021E6838: ; 0x021E6838
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _021E6848
	cmp r1, #1
	beq _021E6862
	b _021E6886
_021E6848:
	ldr r0, [r4, #0x44]
	bl ov95_021E5EDC
	cmp r0, #1
	beq _021E68A0
	ldr r0, [r4, #0x74]
	mov r1, #1
	bl ManagedSprite_SetAnimationFrame
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E68A0
_021E6862:
	mov r1, #0
	bl ov95_021E6150
	cmp r0, #2
	bne _021E68A0
	ldr r0, _021E68A4 ; =0x00000714
	bl PlaySE
	ldr r0, [r4, #0x74]
	mov r1, #2
	bl ManagedSprite_SetAnimationFrame
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	mov r0, #0
	str r0, [r4, #0x64]
	b _021E68A0
_021E6886:
	mov r1, #0
	bl ov95_021E6150
	cmp r0, #2
	bne _021E68A0
	ldr r0, [r4, #0x74]
	mov r1, #2
	bl ManagedSprite_SetAnimationFrame
	mov r0, #0
	str r0, [r4, #0x68]
	str r0, [r4, #0x64]
	pop {r4, pc}
_021E68A0:
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
_021E68A4: .word 0x00000714
	thumb_func_end ov95_021E6838


	thumb_func_start ov95_021E68A8
ov95_021E68A8: ; 0x021E68A8
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _021E68B8
	cmp r1, #1
	beq _021E68BE
	b _021E68F0
_021E68B8:
	add r0, r1, #1
	str r0, [r4, #0x68]
	b _021E68F8
_021E68BE:
	mov r1, #1
	bl ov95_021E6150
	add r5, r0, #0
	cmp r5, #1
	bne _021E68E0
	ldr r0, _021E68FC ; =0x00000714
	bl PlaySE
	ldr r0, [r4, #0x74]
	mov r1, #3
	bl ManagedSprite_SetAnimationFrame
	ldr r0, [r4, #0x44]
	mov r1, #0
	bl ov95_021E5EC0
_021E68E0:
	cmp r5, #2
	bne _021E68F8
	mov r0, #0
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E68F8
_021E68F0:
	mov r0, #0
	str r0, [r4, #0x68]
	str r0, [r4, #0x64]
	pop {r3, r4, r5, pc}
_021E68F8:
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E68FC: .word 0x00000714
	thumb_func_end ov95_021E68A8


	thumb_func_start ov95_021E6900
ov95_021E6900: ; 0x021E6900
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x68]
	cmp r1, #0
	beq _021E6910
	cmp r1, #1
	beq _021E6922
	b _021E6954
_021E6910:
	ldr r0, [r4, #0x44]
	bl ov95_021E5EDC
	cmp r0, #1
	beq _021E695C
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E695C
_021E6922:
	mov r1, #2
	bl ov95_021E6150
	add r5, r0, #0
	cmp r5, #1
	bne _021E6944
	ldr r0, _021E6960 ; =0x00000714
	bl PlaySE
	ldr r0, [r4, #0x74]
	mov r1, #4
	bl ManagedSprite_SetAnimationFrame
	ldr r0, [r4, #0x44]
	mov r1, #1
	bl ov95_021E5EC0
_021E6944:
	cmp r5, #2
	bne _021E695C
	mov r0, #0
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E695C
_021E6954:
	mov r0, #0
	str r0, [r4, #0x68]
	str r0, [r4, #0x64]
	pop {r3, r4, r5, pc}
_021E695C:
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E6960: .word 0x00000714
	thumb_func_end ov95_021E6900


	thumb_func_start ov95_021E6964
ov95_021E6964: ; 0x021E6964
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r1, [r4, #0x68]
	cmp r1, #5
	bls _021E6972
	b _021E6B50
_021E6972:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E697E: ; jump table
	.short _021E698A - _021E697E - 2 ; case 0
	.short _021E69AC - _021E697E - 2 ; case 1
	.short _021E69EE - _021E697E - 2 ; case 2
	.short _021E6A56 - _021E697E - 2 ; case 3
	.short _021E6AE8 - _021E697E - 2 ; case 4
	.short _021E6B34 - _021E697E - 2 ; case 5
_021E698A:
	ldr r0, [r4, #0x44]
	bl ov95_021E5EDC
	cmp r0, #1
	beq _021E69F8
	ldr r0, [r4, #0x74]
	mov r1, #4
	bl ManagedSprite_SetAnimationFrame
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6B64
_021E69AC:
	mov r1, #3
	bl ov95_021E6150
	add r5, r0, #0
	cmp r5, #1
	bne _021E69D6
	ldr r0, [r4, #0x74]
	mov r1, #5
	bl ManagedSprite_SetAnimationFrame
	ldr r0, _021E6B6C ; =0x00000707
	bl PlaySE
	ldr r0, [r4, #0x44]
	mov r1, #2
	bl ov95_021E5EC0
	ldr r0, [r4, #0x44]
	mov r1, #3
	bl ov95_021E5EC0
_021E69D6:
	cmp r5, #2
	bne _021E69F8
	ldr r0, [r4, #0x74]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6B64
_021E69EE:
	ldr r0, [r4, #0x64]
	add r0, r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0xa
	bge _021E69FA
_021E69F8:
	b _021E6B64
_021E69FA:
	mov r3, #0
	str r3, [r4, #0x64]
	str r3, [sp]
	mov r0, #0x10
	ldr r2, _021E6B70 ; =0x0000FFFF
	str r0, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r4, #8]
	mov r1, #1
	bl PaletteData_BeginPaletteFade
	ldr r0, [r4, #0x78]
	ldr r0, [r0]
	bl Sprite_GetPaletteProxy
	mov r1, #1
	bl ObjPlttTransfer_GetPaletteVramOffset
	add r5, r0, #0
	mov r3, #0
	mov r6, #1
	str r3, [sp]
	mov r0, #0x10
	ldr r2, _021E6B70 ; =0x0000FFFF
	str r0, [sp, #4]
	str r2, [sp, #8]
	lsl r6, r5
	eor r2, r6
	lsl r2, r2, #0x10
	ldr r0, [r4, #8]
	mov r1, #4
	lsr r2, r2, #0x10
	bl PaletteData_BeginPaletteFade
	ldr r0, _021E6B70 ; =0x0000FFFF
	mov r1, #0
	str r0, [sp]
	ldr r0, [r4, #0x70]
	mov r2, #0x10
	add r3, r1, #0
	bl Pokepic_StartPaletteFade
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6B64
_021E6A56:
	add r1, sp, #0xc
	ldr r0, [r4, #0x78]
	mov r5, #0
	add r1, #2
	add r2, sp, #0xc
	bl ManagedSprite_GetPositionXY
	add r0, sp, #0xc
	add r1, r5, #0
	ldrsh r2, [r0, r1]
	add r0, r1, #0
	sub r0, #0x30
	cmp r2, r0
	ble _021E6A7C
	ldr r0, [r4, #0x78]
	sub r2, r1, #4
	bl ManagedSprite_OffsetPositionXY
	b _021E6A7E
_021E6A7C:
	add r5, r5, #1
_021E6A7E:
	add r1, sp, #0xc
	ldr r0, [r4, #0x7c]
	add r1, #2
	add r2, sp, #0xc
	bl ManagedSprite_GetPositionXY
	add r0, sp, #0xc
	mov r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xc0
	bge _021E6A9E
	ldr r0, [r4, #0x7c]
	mov r2, #4
	bl ManagedSprite_OffsetPositionXY
	b _021E6AA0
_021E6A9E:
	add r5, r5, #1
_021E6AA0:
	ldr r0, [r4, #8]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _021E6B64
	cmp r5, #2
	bne _021E6B64
	ldr r0, [r4, #0x70]
	bl Pokepic_ResumePaletteFade
	cmp r0, #0
	bne _021E6B64
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add r0, r4, #0
	mov r1, #0
	bl ov95_021E62F0
	ldr r0, [r4, #0x74]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x78]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x7c]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6B64
_021E6AE8:
	ldr r0, [r4, #0x64]
	add r0, r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0x19
	blt _021E6B64
	mov r2, #0
	ldr r0, _021E6B70 ; =0x0000FFFF
	str r2, [r4, #0x64]
	str r0, [sp]
	ldr r0, [r4, #0x70]
	mov r1, #0x10
	add r3, r2, #0
	bl Pokepic_StartPaletteFade
	mov r0, #0x10
	str r0, [sp]
	mov r3, #0
	ldr r2, _021E6B70 ; =0x0000FFFF
	str r3, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r4, #8]
	mov r1, #1
	bl PaletteData_BeginPaletteFade
	mov r0, #0x10
	str r0, [sp]
	mov r3, #0
	ldr r2, _021E6B70 ; =0x0000FFFF
	str r3, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r4, #8]
	mov r1, #4
	bl PaletteData_BeginPaletteFade
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6B64
_021E6B34:
	ldr r0, [r4, #8]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _021E6B64
	ldr r0, [r4, #0x70]
	bl Pokepic_ResumePaletteFade
	cmp r0, #0
	bne _021E6B64
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6B64
_021E6B50:
	ldr r0, [r4, #0x44]
	bl ov95_021E5EDC
	cmp r0, #1
	beq _021E6B64
	mov r0, #0
	str r0, [r4, #0x68]
	add sp, #0x10
	str r0, [r4, #0x64]
	pop {r4, r5, r6, pc}
_021E6B64:
	mov r0, #1
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_021E6B6C: .word 0x00000707
_021E6B70: .word 0x0000FFFF
	thumb_func_end ov95_021E6964


	thumb_func_start ov95_021E6B74
ov95_021E6B74: ; 0x021E6B74
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r0, [r4, #0x68]
	cmp r0, #4
	bls _021E6B82
	b _021E6D50
_021E6B82:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E6B8E: ; jump table
	.short _021E6B98 - _021E6B8E - 2 ; case 0
	.short _021E6BC8 - _021E6B8E - 2 ; case 1
	.short _021E6C56 - _021E6B8E - 2 ; case 2
	.short _021E6CE8 - _021E6B8E - 2 ; case 3
	.short _021E6D34 - _021E6B8E - 2 ; case 4
_021E6B98:
	ldr r0, [r4, #0x44]
	mov r1, #0
	bl ov95_021E5EC0
	ldr r0, [r4, #0x44]
	mov r1, #1
	bl ov95_021E5EC0
	ldr r0, [r4, #0x44]
	mov r1, #2
	bl ov95_021E5EC0
	ldr r0, [r4, #0x44]
	mov r1, #3
	bl ov95_021E5EC0
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6D5A
_021E6BC8:
	ldr r0, [r4, #0x64]
	cmp r0, #0x19
	beq _021E6BD8
	cmp r0, #0x50
	beq _021E6BE0
	cmp r0, #0x8e
	beq _021E6BE8
	b _021E6BEE
_021E6BD8:
	ldr r0, _021E6D60 ; =0x00000806
	bl PlaySE
	b _021E6BEE
_021E6BE0:
	ldr r0, _021E6D64 ; =0x000007AA
	bl PlaySE
	b _021E6BEE
_021E6BE8:
	ldr r0, _021E6D68 ; =0x00000815
	bl PlaySE
_021E6BEE:
	ldr r0, [r4, #0x64]
	add r0, r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0xa0
	bge _021E6BFA
	b _021E6D5A
_021E6BFA:
	mov r3, #0
	str r3, [r4, #0x64]
	str r3, [sp]
	mov r0, #0x10
	ldr r2, _021E6D6C ; =0x0000FFFF
	str r0, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r4, #8]
	mov r1, #1
	bl PaletteData_BeginPaletteFade
	ldr r0, [r4, #0x78]
	ldr r0, [r0]
	bl Sprite_GetPaletteProxy
	mov r1, #1
	bl ObjPlttTransfer_GetPaletteVramOffset
	add r5, r0, #0
	mov r3, #0
	mov r6, #1
	str r3, [sp]
	mov r0, #0x10
	ldr r2, _021E6D6C ; =0x0000FFFF
	str r0, [sp, #4]
	str r2, [sp, #8]
	lsl r6, r5
	eor r2, r6
	lsl r2, r2, #0x10
	ldr r0, [r4, #8]
	mov r1, #4
	lsr r2, r2, #0x10
	bl PaletteData_BeginPaletteFade
	ldr r0, _021E6D6C ; =0x0000FFFF
	mov r1, #0
	str r0, [sp]
	ldr r0, [r4, #0x70]
	mov r2, #0x10
	add r3, r1, #0
	bl Pokepic_StartPaletteFade
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6D5A
_021E6C56:
	add r1, sp, #0xc
	ldr r0, [r4, #0x78]
	mov r5, #0
	add r1, #2
	add r2, sp, #0xc
	bl ManagedSprite_GetPositionXY
	add r0, sp, #0xc
	add r1, r5, #0
	ldrsh r2, [r0, r1]
	add r0, r1, #0
	sub r0, #0x30
	cmp r2, r0
	ble _021E6C7C
	ldr r0, [r4, #0x78]
	sub r2, r1, #4
	bl ManagedSprite_OffsetPositionXY
	b _021E6C7E
_021E6C7C:
	add r5, r5, #1
_021E6C7E:
	add r1, sp, #0xc
	ldr r0, [r4, #0x7c]
	add r1, #2
	add r2, sp, #0xc
	bl ManagedSprite_GetPositionXY
	add r0, sp, #0xc
	mov r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xc0
	bge _021E6C9E
	ldr r0, [r4, #0x7c]
	mov r2, #4
	bl ManagedSprite_OffsetPositionXY
	b _021E6CA0
_021E6C9E:
	add r5, r5, #1
_021E6CA0:
	ldr r0, [r4, #8]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _021E6D5A
	cmp r5, #2
	bne _021E6D5A
	ldr r0, [r4, #0x70]
	bl Pokepic_ResumePaletteFade
	cmp r0, #0
	bne _021E6D5A
	add r0, r4, #0
	mov r1, #0
	bl ov95_021E62F0
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r4, #0x74]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x78]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x7c]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6D5A
_021E6CE8:
	ldr r0, [r4, #0x64]
	add r0, r0, #1
	str r0, [r4, #0x64]
	cmp r0, #0x19
	blt _021E6D5A
	mov r2, #0
	ldr r0, _021E6D6C ; =0x0000FFFF
	str r2, [r4, #0x64]
	str r0, [sp]
	ldr r0, [r4, #0x70]
	mov r1, #0x10
	add r3, r2, #0
	bl Pokepic_StartPaletteFade
	mov r0, #0x10
	str r0, [sp]
	mov r3, #0
	ldr r2, _021E6D6C ; =0x0000FFFF
	str r3, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r4, #8]
	mov r1, #1
	bl PaletteData_BeginPaletteFade
	mov r0, #0x10
	str r0, [sp]
	mov r3, #0
	ldr r2, _021E6D6C ; =0x0000FFFF
	str r3, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r4, #8]
	mov r1, #4
	bl PaletteData_BeginPaletteFade
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6D5A
_021E6D34:
	ldr r0, [r4, #8]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _021E6D5A
	ldr r0, [r4, #0x70]
	bl Pokepic_ResumePaletteFade
	cmp r0, #0
	bne _021E6D5A
	ldr r0, [r4, #0x68]
	add r0, r0, #1
	str r0, [r4, #0x68]
	b _021E6D5A
_021E6D50:
	mov r0, #0
	str r0, [r4, #0x68]
	add sp, #0x10
	str r0, [r4, #0x64]
	pop {r4, r5, r6, pc}
_021E6D5A:
	mov r0, #1
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E6D60: .word 0x00000806
_021E6D64: .word 0x000007AA
_021E6D68: .word 0x00000815
_021E6D6C: .word 0x0000FFFF
	thumb_func_end ov95_021E6B74


	thumb_func_start HatchEggApp_Init
HatchEggApp_Init: ; 0x021E6D70
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	mov r2, #1
	mov r0, #3
	mov r1, #0x46
	lsl r2, r2, #0x12
	bl Heap_Create
	add r0, r5, #0
	mov r1, #0x8c
	mov r2, #0x46
	bl OverlayManager_CreateAndGetData
	mov r1, #0
	mov r2, #0x8c
	add r4, r0, #0
	bl memset
	add r0, r5, #0
	bl OverlayManager_GetArgs
	str r0, [r4]
	ldr r0, [r0, #0x10]
	bl Options_GetTextFrameDelay
	str r0, [r4, #0x10]
	ldr r0, [r4]
	ldr r0, [r0, #0x10]
	bl Options_GetFrame
	str r0, [r4, #0x14]
	bl ov95_021E5954
	str r0, [r4, #0x38]
	mov r0, #0x46
	bl PokepicManager_Create
	str r0, [r4, #0x3c]
	mov r0, #0xb4
	mov r1, #0x46
	bl NARC_New
	str r0, [r4, #0x40]
	mov r0, #0x46
	bl BgConfig_Alloc
	str r0, [r4, #4]
	mov r0, #0x40
	mov r1, #0x46
	bl GF_CreateVramTransferManager
	mov r0, #0x46
	mov r1, #1
	mov r2, #0
	bl sub_02016EDC
	str r0, [r4, #0x58]
	mov r0, #0x46
	bl PaletteData_Init
	mov r1, #1
	str r0, [r4, #8]
	bl PaletteData_SetAutoTransparent
	mov r2, #2
	ldr r0, [r4, #8]
	mov r1, #0
	lsl r2, r2, #8
	mov r3, #0x46
	bl PaletteData_AllocBuffers
	mov r1, #2
	ldr r0, [r4, #8]
	lsl r2, r1, #8
	mov r3, #0x46
	bl PaletteData_AllocBuffers
	mov r1, #1
	ldr r0, [r4, #8]
	lsl r2, r1, #9
	mov r3, #0x46
	bl PaletteData_AllocBuffers
	mov r0, #1
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xf0
	str r0, [sp, #8]
	ldr r0, [r4, #8]
	mov r1, #0x10
	mov r2, #9
	mov r3, #0x46
	bl PaletteData_LoadNarc
	bl ov95_021E5900
	bl ov95_021E5928
	bl ov95_021E59F8
	ldr r0, [r4, #4]
	bl ov95_021E5A38
	ldr r0, [r4, #4]
	bl ov95_021E6FC4
	add r0, r4, #4
	bl ov95_021E619C
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, [r4, #4]
	ldr r1, [r4, #0x54]
	ldr r2, [r4, #0x50]
	mov r3, #0x46
	bl ov95_021E7020
	add r1, r4, #0
	add r1, #0x88
	str r0, [r1]
	bl Sound_Stop
	ldr r0, _021E6E84 ; =ov95_021E5B24
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_021E6E84: .word ov95_021E5B24
	thumb_func_end HatchEggApp_Init


	thumb_func_start HatchEggApp_Main
HatchEggApp_Main: ; 0x021E6E88
	push {r3, r4, r5, lr}
	add r4, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r4]
	add r5, r0, #0
	cmp r1, #0
	beq _021E6E9E
	cmp r1, #1
	beq _021E6EDC
	b _021E6EF8
_021E6E9E:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E6EAC
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
_021E6EAC:
	ldr r0, [r5]
	mov r1, #5
	ldr r0, [r0, #0xc]
	mov r2, #0
	bl GetMonData
	add r4, r0, #0
	add r1, r5, #0
	lsl r2, r4, #0x10
	ldr r0, [r5, #0x40]
	add r1, #0x6c
	lsr r2, r2, #0x10
	mov r3, #1
	bl sub_020729A4
	ldr r0, _021E6F08 ; =0x000001EA
	cmp r4, r0
	bne _021E6ED6
	mov r0, #1
	str r0, [r5, #0x5c]
	b _021E6F04
_021E6ED6:
	mov r0, #0
	str r0, [r5, #0x5c]
	b _021E6F04
_021E6EDC:
	bl ov95_021E6300
	cmp r0, #0
	bne _021E6EEC
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _021E6F04
_021E6EEC:
	ldr r0, [r5, #0x3c]
	bl PokepicManager_DrawAll
	bl ov95_021E5B58
	b _021E6F04
_021E6EF8:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E6F04
	mov r0, #1
	pop {r3, r4, r5, pc}
_021E6F04:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E6F08: .word 0x000001EA
	thumb_func_end HatchEggApp_Main


	thumb_func_start HatchEggApp_Exit
HatchEggApp_Exit: ; 0x021E6F0C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, #0x88
	ldr r0, [r0]
	bl ov95_021E7078
	ldr r0, [r4, #0x38]
	bl GF_3DVramMan_Delete
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #3
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #8]
	mov r1, #0
	bl PaletteData_FreeBuffers
	ldr r0, [r4, #8]
	mov r1, #2
	bl PaletteData_FreeBuffers
	ldr r0, [r4, #8]
	mov r1, #1
	bl PaletteData_FreeBuffers
	ldr r0, [r4, #8]
	bl PaletteData_Free
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, [r4, #4]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #2
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #3
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	bl Heap_Free
	bl GF_DestroyVramTransferManager
	ldr r0, [r4, #0x3c]
	bl PokepicManager_Delete
	ldr r0, [r4, #0x58]
	bl sub_02016F2C
	ldr r0, [r4, #0x40]
	bl NARC_Delete
	add r0, r4, #4
	bl ov95_021E6228
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x46
	bl Heap_Destroy
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl Field_SetEnvironmentSoundState_None_Unk2
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end HatchEggApp_Exit

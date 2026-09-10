	.include "asm/macros.inc"
	.public ov98_0221E5C0
	.public ov98_0221E5D0
	.public ov98_0221E5E0
	.public ov98_0221E684
	.public ov98_0221E6CC
	.public ov98_0221E6E0
	.public ov98_0221E6F0
	.public ov98_0221E784
	.public ov98_0221E7E8
	.public ov98_0221E8A8
	.public ov98_0221E970
	.public ov98_0221E9FC
	.public ov98_0221EA4C
	.public ov98_0221EAA8
	.public ov98_0221EABC
	.public ov98_0221EB84
	.public ov98_0221EBD8
	.public ov98_0221EBEC
	.public ov98_0221EC08
	.public ov98_0221EC24
	.public ov98_0221EC3C
	.public ov98_0221ECD0
	.public ov98_0221ED3C
	.public ov98_0221ED48
	.public ov98_0221EDA4
	.public ov98_0221EDC4
	.public ov98_0221EE28
	.public ov98_0221EE84
	.public ov98_0221EE9C
	.public ov98_0221EEDC
	.public ov98_0221EEEC
	.public ov98_0221EEFC
	.public ov98_0221EF14
	.public ov98_0221EF24
	.public ov98_0221EF64
	.public ov98_0221EF80
	.public ov98_0221EFA4
	.public ov98_0221EFB4
	.public ov98_0221EFE8
	.public ov98_0221F01C
	.public ov98_0221F024
	.public ov98_0221F058
	.public ov98_0221F090
	.public ov98_0221F0EC
	.public ov98_0221F120
	.public ov98_0221F150
	.public ov98_0221F174
	.public _0221F194
	.public ov98_0221F19C
	.public ov98_0221F1AC
	.public ov98_0221F1C0
	.public ov98_0221F1E0
	.public ov98_0221F1E4
	.public ov98_0221F1F8
	.public ov98_0221F220
	.public ov98_0221F248
	.include "overlay_98.inc"
	.include "global.inc"

	.text

	thumb_func_start ov98_0221E7E8
ov98_0221E7E8: ; 0x0221E7E8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	add r4, r1, #0
	str r2, [sp, #0x14]
	ldr r2, [r4]
	add r5, r0, #0
	lsl r1, r2, #0x17
	add r6, r3, #0
	lsr r1, r1, #0x17
	bne _0221E806
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
_0221E806:
	lsl r0, r2, #0xf
	lsr r0, r0, #0x1f
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r4]
	lsl r1, r1, #0x10
	lsl r0, r0, #0x12
	lsr r0, r0, #0x1b
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r4, #4]
	lsr r1, r1, #0x10
	str r0, [sp, #8]
	ldr r2, [r4]
	add r0, sp, #0x28
	lsl r2, r2, #0x10
	lsr r2, r2, #0x1e
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	mov r3, #2
	bl GetMonSpriteCharAndPlttNarcIdsEx
	ldr r3, _0221E8A4 ; =ov98_0221F19C
	add r2, sp, #0x18
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r1, #0x32
	ldr r0, [sp, #0x50]
	lsl r1, r1, #6
	bl Heap_AllocAtEnd
	add r7, r0, #0
	str r7, [sp]
	ldr r0, [r4, #4]
	add r1, sp, #0x18
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	ldr r0, [r4]
	ldr r2, [sp, #0x50]
	lsl r0, r0, #0x17
	lsr r0, r0, #0x17
	str r0, [sp, #0x10]
	ldrh r0, [r1, #0x10]
	ldrh r1, [r1, #0x12]
	add r3, sp, #0x18
	bl sub_02014510
	mov r2, #0x32
	add r0, r5, #0
	add r1, r7, #0
	lsl r2, r2, #6
	bl ov98_0221E9FC
	ldr r0, [sp, #0x50]
	str r6, [sp]
	str r0, [sp, #4]
	add r2, sp, #0x18
	ldrh r1, [r2, #0x10]
	ldrh r2, [r2, #0x14]
	ldr r3, [sp, #0x14]
	add r0, r5, #0
	bl ov98_0221EA4C
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r0, r7, #0
	bl Heap_Free
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E8A4: .word ov98_0221F19C
	thumb_func_end ov98_0221E7E8


	thumb_func_start ov98_0221E8A8
ov98_0221E8A8: ; 0x0221E8A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	str r0, [sp, #0x10]
	ldr r7, [r0, #4]
	ldr r6, [r0, #8]
	ldr r0, [sp, #0x40]
	add r5, r1, #0
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	cmp r0, #0
	beq _0221E8C4
	mov r0, #0x1c
	str r0, [sp, #0x1c]
	b _0221E8C8
_0221E8C4:
	mov r0, #0x1d
	str r0, [sp, #0x1c]
_0221E8C8:
	bl sub_0207449C
	str r0, [sp, #0x28]
	bl sub_020744A8
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x14]
	mov r4, #0
	cmp r0, #0
	ble _0221E908
	ldr r0, [sp, #0x18]
	lsl r1, r0, #2
	ldr r0, _0221E96C ; =_0221F194
	ldr r0, [r0, r1]
	str r0, [sp, #0x20]
_0221E8E6:
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #0x20]
	ldr r3, [sp, #0x1c]
	str r0, [sp, #4]
	ldr r0, [r5]
	add r1, r6, #0
	add r0, r0, r4
	str r0, [sp, #8]
	add r0, r7, #0
	mov r2, #0xb1
	bl SpriteSystem_LoadCharResObj
	ldr r0, [sp, #0x14]
	add r4, r4, #1
	cmp r4, r0
	blt _0221E8E6
_0221E908:
	mov r0, #0
	str r0, [sp]
	ldr r0, [r5, #8]
	ldr r3, [sp, #0x28]
	str r0, [sp, #4]
	add r0, r7, #0
	add r1, r6, #0
	mov r2, #0x14
	bl SpriteSystem_LoadCellResObj
	mov r0, #0
	str r0, [sp]
	ldr r0, [r5, #0xc]
	ldr r3, [sp, #0x24]
	str r0, [sp, #4]
	add r0, r7, #0
	add r1, r6, #0
	mov r2, #0x14
	bl SpriteSystem_LoadAnimResObj
	ldr r0, [sp, #0x10]
	mov r1, #0x14
	ldrsb r0, [r0, r1]
	sub r1, #0x15
	cmp r0, r1
	bne _0221E966
	bl sub_02074490
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	mov r2, #0x14
	lsl r1, r0, #2
	ldr r0, _0221E96C ; =_0221F194
	ldr r0, [r0, r1]
	add r1, r6, #0
	str r0, [sp, #8]
	ldr r0, [r5, #4]
	str r0, [sp, #0xc]
	add r0, r7, #0
	bl SpriteSystem_LoadPlttResObj
	ldr r1, [sp, #0x10]
	strb r0, [r1, #0x14]
_0221E966:
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	nop
_0221E96C: .word _0221F194
	thumb_func_end ov98_0221E8A8


	thumb_func_start ov98_0221E970
ov98_0221E970: ; 0x0221E970
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r0, #0
	mov r4, #2
	ldr r0, [sp, #0x20]
	add r5, r1, #0
	lsl r4, r4, #8
	cmp r0, #0
	beq _0221E984
	lsl r4, r4, #1
_0221E984:
	ldr r0, [r2]
	lsl r1, r0, #0x17
	lsl r0, r0, #0x12
	lsr r0, r0, #0x1b
	str r0, [sp]
	lsr r7, r1, #0x17
	ldr r2, [sp]
	add r0, r7, #0
	mov r1, #0
	bl GetMonIconNaixEx
	add r1, r0, #0
	add r0, r6, #0
	add r2, sp, #8
	bl ov98_0221EAA8
	ldr r1, [sp, #8]
	str r0, [sp, #4]
	ldr r1, [r1, #0x14]
	add r0, r5, #0
	add r2, r4, #0
	bl ov98_0221E9FC
	ldr r0, [sp, #4]
	bl Heap_Free
	add r0, r5, #0
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r1, [sp]
	add r0, r7, #0
	mov r2, #0
	bl GetMonIconPaletteEx
	mov r1, #0x14
	add r2, r0, #0
	ldrsb r1, [r6, r1]
	add r0, r5, #0
	add r1, r2, r1
	bl ManagedSprite_SetPaletteOverride
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq _0221E9F8
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetAnim
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0xc
	bl ManagedSprite_SetAnimSpeed
	add r0, r5, #0
	mov r1, #1
	bl ManagedSprite_SetAnimateFlag
_0221E9F8:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov98_0221E970

	.include "asm/macros.inc"
	.public _02265E6E
	.public _02265E82
	.public _02265F1C
	.public _02265F20
	.public _02265F24
	.public _02265F28
	.public _02265F2C
	.public _02265F30
	.public _02265F64
	.public _02265F7A
	.public _02265F92
	.public _02265F94
	.public _02265FB8
	.public _02265FBC
	.public _02265FC0
	.public _02265FD0
	.public _02265FFA
	.public ov12_02265E28
	.public ov12_0226E0A0
	.public ov12_02265F34
	.public ov12_02265F68
	.public ov12_02265F7C
	.public ov12_02265FC4
	.public ov12_02265FD4
	.public ov12_02266008
	.public ov12_0226E0D0
	.public ov12_0226E100
	.public ov12_0226E168
	.include "overlay_12_02265E28.inc"
	.include "global.inc"

	.text
	.public ov12_02265F34
	.public ov12_02265F68
	.public ov12_02265F7C
	.public ov12_02265FC4
	.public ov12_02265FD4
	.public ov12_02266008

    thumb_func_start ov12_02265E28
ov12_02265E28: ; 0x02265E28
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	mov r0, #8
	mov r1, #5
	bl NARC_New
	add r4, r0, #0
	ldr r0, [r5, #4]
	bl BattleSystem_GetSpriteSystem
	str r0, [sp, #0x24]
	ldr r0, [r5, #4]
	bl BattleSystem_GetSpriteManager
	str r0, [sp, #0x20]
	ldr r0, [r5, #4]
	bl ov12_0223B52C
	add r7, r0, #0
	ldrb r0, [r5, #8]
	cmp r0, #0
	ldrb r0, [r5, #9]
	bne _02265E6E
	lsl r1, r0, #1
	ldr r0, _02265F1C ; =ov12_0226E0D0
	ldrh r3, [r0, r1]
	ldr r0, _02265F20 ; =0x00004E2D
	mov r1, #0x80
	str r1, [sp, #0x1c]
	add r6, r0, #0
	mov r1, #0x81
	sub r6, #8
	str r1, [sp, #0x18]
	b _02265E82
_02265E6E:
	lsl r1, r0, #1
	ldr r0, _02265F24 ; =ov12_0226E0A0
	ldrh r3, [r0, r1]
	ldr r0, _02265F28 ; =0x00004E2E
	mov r1, #0x83
	str r1, [sp, #0x1c]
	add r6, r0, #0
	mov r1, #0x84
	sub r6, #8
	str r1, [sp, #0x18]
_02265E82:
	mov r1, #1
	str r1, [sp]
	str r1, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x20]
	add r2, r4, #0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r0, [r5, #4]
	bl BattleSystem_GetPaletteData
	str r4, [sp]
	ldrb r1, [r5, #9]
	mov r2, #6
	add r3, r1, #0
	mul r3, r2
	ldr r2, _02265F2C ; =ov12_0226E168
	lsl r1, r7, #1
	add r2, r2, r3
	ldrh r1, [r1, r2]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x20]
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #1
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r1, _02265F30 ; =0x00004E29
	str r1, [sp, #0x14]
	mov r1, #2
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	ldr r0, [r5, #4]
	bl BattleSystem_GetPaletteData
	mov r1, #0
	str r1, [sp]
	mov r1, #0x20
	str r1, [sp, #4]
	mov r1, #0x70
	str r1, [sp, #8]
	ldrb r2, [r5, #9]
	mov r3, #6
	lsl r5, r7, #1
	mul r3, r2
	ldr r2, _02265F2C ; =ov12_0226E168
	mov r1, #8
	add r2, r2, r3
	ldrh r2, [r5, r2]
	mov r3, #5
	bl PaletteData_LoadNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x20]
	ldr r3, [sp, #0x1c]
	add r2, r4, #0
	str r6, [sp, #4]
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x20]
	ldr r3, [sp, #0x18]
	add r2, r4, #0
	str r6, [sp, #4]
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02265F1C: .word ov12_0226E0D0
_02265F20: .word 0x00004E2D
_02265F24: .word ov12_0226E0A0
_02265F28: .word 0x00004E2E
_02265F2C: .word ov12_0226E168
_02265F30: .word 0x00004E29
	thumb_func_end ov12_02265E28

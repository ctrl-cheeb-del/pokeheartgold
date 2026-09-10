	.include "asm/macros.inc"
	.include "overlay_68.inc"
	.include "global.inc"

	.text
	.public MoveRelearner_Exit
	.public MoveRelearner_Init
	.public MoveRelearner_Main
	.public _021E7BE8
	.public ov68_021E5A58
	.public ov68_021E5BA0
	.public ov68_021E5BC0
	.public ov68_021E5D24
	.public ov68_021E5E48
	.public ov68_021E5F68
	.public ov68_021E6078
	.public ov68_021E60D8
	.public ov68_021E614C
	.public ov68_021E61B8
	.public ov68_021E6234
	.public ov68_021E62D4
	.public ov68_021E6320
	.public ov68_021E66A0
	.public ov68_021E66F0
	.public ov68_021E67E0
	.public ov68_021E6820
	.public ov68_021E68D4
	.public ov68_021E6A2C
	.public ov68_021E6C14
	.public ov68_021E6DDC
	.public ov68_021E6EB8
	.public ov68_021E7028
	.public ov68_021E70BC
	.public ov68_021E7124
	.public ov68_021E7178
	.public ov68_021E71C4
	.public ov68_021E7224
	.public ov68_021E7288
	.public ov68_021E734C
	.public ov68_021E73A4
	.public ov68_021E7424
	.public ov68_021E74D8
	.public ov68_021E7568
	.public ov68_021E75C0
	.public ov68_021E7618
	.public ov68_021E773C
	.public ov68_021E7898
	.public ov68_021E7910
	.public ov68_021E797C
	.public ov68_021E7A18
	.public ov68_021E7AD8
	.public ov68_021E7BC8
	.public ov68_021E7BEC
	.public ov68_021E7BF8
	.public ov68_021E7C08
	.public ov68_021E7C18
	.public ov68_021E7C2C
	.public ov68_021E7C44
	.public ov68_021E7C60
	.public ov68_021E7C7C
	.public ov68_021E7C98
	.public ov68_021E7CB4
	.public ov68_021E7CD0
	.public ov68_021E7CF0
	.public ov68_021E7D14
	.public ov68_021E7D3C
	.public ov68_021E7D40
	.public ov68_021E7D64
	.public ov68_021E7DA4
	.public ov68_021E7DFC
	.public ov68_021E7E74
	.public ov68_021E5B14
	.public ov68_021E5B6C
	.public ov68_021E5CD8
	.public ov68_021E5E38
	.public ov68_021E5E94
	.public ov68_021E5EBC
	.public ov68_021E5F18
	.public ov68_021E5F50
	.public ov68_021E6058
	.public ov68_021E61A0
	.public ov68_021E61EC
	.public ov68_021E6204
	.public ov68_021E6678
	.public ov68_021E68C4
	.public ov68_021E6BEC
	.public ov68_021E6BFC
	.public ov68_021E6C74
	.public ov68_021E6C8C
	.public ov68_021E6CD8
	.public ov68_021E6D00
	.public ov68_021E6D20
	.public ov68_021E6D40
	.public ov68_021E6D4C
	.public ov68_021E6D58
	.public ov68_021E6D64
	.public ov68_021E6D80
	.public ov68_021E6D9C
	.public ov68_021E6DB8
	.public ov68_021E6DD0
	.public ov68_021E6E84
	.public ov68_021E7388
	.public ov68_021E74C0
	.public ov68_021E7604
	.public ov68_021E7614
	.public ov68_021E7A90
	.public ov68_021E7AB4
	.public ov68_021E7B6C
	.public ov68_021E7B8C
	.public ov68_021E7B94

	thumb_func_start ov68_021E73A4
ov68_021E73A4: ; 0x021E73A4
	push {r3, r4, r5, lr}
	add r3, r1, #0
	add r4, r0, #0
	add r5, r2, #0
	cmp r3, #4
	bhs _021E73D2
	mov r0, #0x4b
	lsl r2, r3, #5
	lsl r0, r0, #2
	add r2, #0x20
	lsl r2, r2, #0x10
	ldr r0, [r4, r0]
	mov r1, #0
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	mov r0, #0x4b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetAnimationFrame
	b _021E7414
_021E73D2:
	cmp r3, #6
	bhs _021E73FA
	mov r0, #0x4b
	lsl r0, r0, #2
	sub r2, r3, #4
	mov r1, #0x28
	mul r1, r2
	lsl r1, r1, #0x10
	ldr r0, [r4, r0]
	asr r1, r1, #0x10
	mov r2, #0xa8
	bl ManagedSprite_SetPositionXY
	mov r0, #0x4b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ManagedSprite_SetAnimationFrame
	b _021E7414
_021E73FA:
	mov r0, #0x4b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xc0
	mov r2, #0xa0
	bl ManagedSprite_SetPositionXY
	mov r0, #0x4b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	bl ManagedSprite_SetAnimationFrame
_021E7414:
	mov r0, #0x4b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, r5, #0
	bl ManagedSprite_SetPaletteOverride
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov68_021E73A4


	thumb_func_start ov68_021E7424
ov68_021E7424: ; 0x021E7424
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	add r5, r0, #0
	add r7, r2, #0
	cmp r6, #0
	bne _021E7442
	cmp r7, #0
	beq _021E7442
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r4, #1
	bl ManagedSprite_ResetSpriteAnimCtrlState
	b _021E7444
_021E7442:
	mov r4, #0
_021E7444:
	ldr r0, [r5]
	ldrh r0, [r0, #0x16]
	add r2, r0, #4
	mov r0, #0x6e
	lsl r0, r0, #2
	ldrb r1, [r5, r0]
	cmp r2, r1
	bge _021E7460
	sub r0, #0x94
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ManagedSprite_SetAnim
	b _021E746A
_021E7460:
	sub r0, #0x94
	ldr r0, [r5, r0]
	add r1, r4, #2
	bl ManagedSprite_SetAnim
_021E746A:
	mov r0, #0x49
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ManagedSprite_SetAnimateFlag
	cmp r6, #1
	bne _021E748C
	cmp r7, #0
	beq _021E748C
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r4, #1
	bl ManagedSprite_ResetSpriteAnimCtrlState
	b _021E748E
_021E748C:
	mov r4, #0
_021E748E:
	ldr r0, [r5]
	ldrh r0, [r0, #0x16]
	cmp r0, #0
	beq _021E74A4
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #4
	bl ManagedSprite_SetAnim
	b _021E74B0
_021E74A4:
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #6
	bl ManagedSprite_SetAnim
_021E74B0:
	mov r0, #0x4a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ManagedSprite_SetAnimateFlag
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov68_021E7424

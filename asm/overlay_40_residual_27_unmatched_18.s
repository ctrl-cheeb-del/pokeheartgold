	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public ManagedSprite_SetAnim
	.public ManagedSprite_SetPositionXY
	.public TextOBJ_SetSpritesDrawFlag
	.public ov40_0222D5AC
	.public ov40_0222D66C
	.public ov40_0222D6EC
	.public ov40_0222D800
	.public ov40_022359B4
	.public ov40_02235A30
	.public sub_020136B4
	.text

	thumb_func_start ov40_02235A30
ov40_02235A30: ; 0x02235A30
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	mov r1, #2
	bl ov40_0222D6EC
	add r0, r5, #0
	mov r1, #2
	bl ov40_0222D800
	mov r1, #0x67
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r5, #0
	mov r1, #2
	bl ov40_0222D800
	mov r1, #0x6e
	lsl r1, r1, #2
	str r0, [r4, r1]
	sub r1, #0x20
	add r0, r4, r1
	add r1, r5, #0
	add r1, #0x14
	mov r2, #2
	bl ov40_0222D5AC
	mov r0, #0x6d
	lsl r0, r0, #2
	add r1, r5, #0
	add r0, r4, r0
	add r1, #0x14
	mov r2, #2
	bl ov40_0222D5AC
	mov r0, #0x66
	lsl r0, r0, #2
	add r1, r5, #0
	add r0, r4, r0
	add r1, #0x14
	mov r2, #3
	bl ov40_0222D66C
	mov r0, #0x6d
	lsl r0, r0, #2
	add r1, r5, #0
	add r0, r4, r0
	add r1, #0x14
	mov r2, #0x35
	bl ov40_0222D66C
	mov r0, #0x67
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
	mov r0, #0x6e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #4
	bl ManagedSprite_SetAnim
	mov r0, #0x67
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x20
	mov r2, #0xe8
	bl ManagedSprite_SetPositionXY
	mov r0, #0x6e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x80
	mov r2, #0xe8
	bl ManagedSprite_SetPositionXY
	mov r0, #0x1a
	lsl r0, r0, #4
	mov r1, #0x24
	add r2, r1, #0
	ldr r0, [r4, r0]
	sub r2, #0x2c
	bl sub_020136B4
	mov r0, #0x6f
	lsl r0, r0, #2
	mov r1, #0x24
	add r2, r1, #0
	ldr r0, [r4, r0]
	sub r2, #0x2c
	bl sub_020136B4
	mov r0, #0x1a
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	mov r0, #0x6f
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	add r0, r5, #0
	mov r1, #0
	bl ov40_022359B4
	pop {r3, r4, r5, pc}
	thumb_func_end ov40_02235A30

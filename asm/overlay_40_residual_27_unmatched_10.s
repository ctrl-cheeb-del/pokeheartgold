	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public ManagedSprite_SetAnim
	.public ManagedSprite_SetDrawFlag
	.public ManagedSprite_SetPositionXY
	.public TextOBJ_SetSpritesDrawFlag
	.public ov40_0222D5AC
	.public ov40_0222D66C
	.public ov40_0222D800
	.public ov40_022330E0
	.public ov40_0223311C
	.public ov40_0223316C
	.public sub_020136B4
	.text

	thumb_func_start ov40_0223316C
ov40_0223316C: ; 0x0223316C
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	mov r1, #2
	bl ov40_0223311C
	add r0, r5, #0
	mov r1, #2
	bl ov40_0222D800
	add r1, r4, #0
	add r1, #0xbc
	str r0, [r1]
	add r0, r4, #0
	add r1, r5, #0
	add r0, #0xb8
	add r1, #0x14
	mov r2, #2
	bl ov40_0222D5AC
	add r0, r4, #0
	add r1, r5, #0
	add r0, #0xb8
	add r1, #0x14
	mov r2, #3
	bl ov40_0222D66C
	add r0, r4, #0
	add r0, #0xbc
	ldr r0, [r0]
	mov r1, #0x80
	mov r2, #0xe8
	bl ManagedSprite_SetPositionXY
	add r0, r4, #0
	add r0, #0xc0
	mov r1, #0x24
	add r2, r1, #0
	ldr r0, [r0]
	sub r2, #0x2c
	bl sub_020136B4
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	add r0, r5, #0
	mov r1, #2
	bl ov40_0222D800
	add r1, r4, #0
	add r1, #0x98
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x98
	ldr r0, [r0]
	mov r1, #0xdc
	mov r2, #0xe0
	bl ManagedSprite_SetPositionXY
	add r0, r4, #0
	add r0, #0x98
	ldr r0, [r0]
	mov r1, #2
	bl ManagedSprite_SetAnim
	add r4, #0x98
	ldr r0, [r4]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r0, r5, #0
	mov r1, #1
	bl ov40_022330E0
	pop {r3, r4, r5, pc}
	thumb_func_end ov40_0223316C

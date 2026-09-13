	.include "asm/macros.inc"
	.include "overlay_33.inc"
	.include "global.inc"

	.text
	.public ov33_0225D520
	.public ov33_0225D5A8
	.public ov33_0225D5CC
	.public ov33_0225D5D0
	.public ov33_0225D6F8
	.public ov33_0225D720
	.public ov33_0225D7B8
	.public ov33_0225D7D4
	.public ov33_0225D820
	.public ov33_0225D84C
	.public ov33_0225D9D4
	.public ov33_0225DA24
	.public ov33_0225DA2C
	.public ov33_0225DA34
	.public ov33_0225DA40
	.public ov33_0225DA68
	.public ov33_0225DA84
	.public ov33_0225DAA0
	.public ov33_0225DA50
	.public ov33_0225D8D4

	thumb_func_start ov33_0225D9D4
ov33_0225D9D4: ; 0x0225D9D4
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	ldr r3, _0225DA1C ; =0x000001BA
	add r4, r0, #0
	ldrh r2, [r4, r3]
	ldr r0, _0225DA20 ; =ov33_0225DA50
	add r3, r3, #2
	sub r5, r2, #1
	mov r2, #0xc
	mul r2, r5
	add r5, r0, r2
	mov r0, #0x20
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrb r2, [r5, #8]
	ldrb r6, [r5, #9]
	ldrh r5, [r5, #0xa]
	ldr r3, [r4, r3]
	ldr r0, [r4]
	add r5, r5, #6
	mul r3, r5
	add r3, r6, r3
	lsl r3, r3, #0x18
	mov r1, #5
	lsr r3, r3, #0x18
	bl BgTilemapRectChangePalette
	ldr r0, [r4]
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	nop
_0225DA1C: .word 0x000001BA
_0225DA20: .word ov33_0225DA50
	thumb_func_end ov33_0225D9D4

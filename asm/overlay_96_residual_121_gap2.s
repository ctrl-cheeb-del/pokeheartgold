	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	thumb_func_start ov96_0221966C
ov96_0221966C: ; 0x0221966C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r1, [sp]
	add r6, r0, #0
	add r5, r3, #0
	str r2, [sp, #4]
	cmp r6, #0
	bne _02219680
	bl GF_AssertFail
_02219680:
	ldr r0, [sp]
	cmp r0, #4
	blo _0221968A
	bl GF_AssertFail
_0221968A:
	mov r7, #0
	add r4, r7, #0
_0221968E:
	ldrb r0, [r5, #1]
	add r1, r7, #6
	lsl r0, r0, #2
	add r0, r6, r0
	add r0, #0x88
	ldr r0, [r0]
	bl ManagedSprite_SetAnimNoRestart
	cmp r4, #3
	beq _022196AC
	ldrb r1, [r5]
	ldrb r0, [r5, #2]
	cmp r1, r0
	beq _022196AC
	add r7, r4, #1
_022196AC:
	add r4, r4, #1
	add r5, r5, #2
	cmp r4, #4
	blt _0221968E
	ldr r0, [r6]
	bl ov96_021E5F24
	ldr r1, [sp]
	cmp r1, r0
	bne _022196DE
	add r0, r6, #0
	add r0, #0xc2
	ldrh r1, [r0]
	ldr r0, [sp, #4]
	cmp r0, r1
	beq _022196DE
	ldr r1, [sp, #4]
	add r0, r6, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl ov96_02219A5C
	ldr r0, [sp, #4]
	add r6, #0xc2
	strh r0, [r6]
_022196DE:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_0221966C



	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.public GF_AssertFail
	.public ManagedSprite_SetAnimateFlag
	.public SpriteSystem_NewSpriteWithYOffset
	.text

	thumb_func_start ov96_022104D8
ov96_022104D8: ; 0x022104D8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r6, _02210534 ; =ov96_0221D17C
	add r7, r2, #0
	str r3, [sp]
	add r5, r0, #0
	add r4, r1, #0
	add r3, sp, #4
	mov r2, #6
_022104EA:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _022104EA
	ldr r0, [r6]
	cmp r5, #0
	str r0, [r3]
	bne _022104FE
	bl GF_AssertFail
_022104FE:
	cmp r4, #0
	bne _02210506
	bl GF_AssertFail
_02210506:
	add r1, sp, #4
	strh r7, [r1]
	ldr r0, [sp]
	mov r3, #0x1e
	strh r0, [r1, #2]
	add r0, sp, #0x40
	ldrh r2, [r0, #0x10]
	lsl r3, r3, #0x10
	strh r2, [r1, #6]
	ldrh r0, [r0, #0x14]
	add r1, r4, #0
	add r2, sp, #4
	str r0, [sp, #0xc]
	add r0, r5, #0
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #1
	add r4, r0, #0
	bl ManagedSprite_SetAnimateFlag
	add r0, r4, #0
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02210534: .word ov96_0221D17C
	thumb_func_end ov96_022104D8

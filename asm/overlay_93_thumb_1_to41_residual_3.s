	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text

	thumb_func_start ov93_0225CF34
ov93_0225CF34: ; 0x0225CF34
	push {r3, lr}
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, _0225CFA0 ; =0x04000008
	mov r1, #3
	ldrh r2, [r0]
	bic r2, r1
	mov r1, #1
	orr r1, r2
	strh r1, [r0]
	add r0, #0x58
	ldrh r2, [r0]
	ldr r1, _0225CFA4 ; =0xFFFFCFFD
	and r2, r1
	strh r2, [r0]
	add r2, r1, #2
	ldrh r3, [r0]
	add r1, r1, #2
	and r3, r2
	mov r2, #0x10
	orr r2, r3
	strh r2, [r0]
	ldrh r3, [r0]
	ldr r2, _0225CFA8 ; =0x0000CFFB
	and r3, r2
	strh r3, [r0]
	ldrh r3, [r0]
	sub r2, #0x1c
	and r3, r1
	mov r1, #8
	orr r1, r3
	strh r1, [r0]
	ldrh r1, [r0]
	and r1, r2
	strh r1, [r0]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl G3X_SetFog
	mov r0, #0
	ldr r2, _0225CFAC ; =0x00007FFF
	add r1, r0, #0
	mov r3, #0x3f
	str r0, [sp]
	bl G3X_SetClearColor
	ldr r1, _0225CFB0 ; =0xBFFF0000
	ldr r0, _0225CFB4 ; =0x04000580
	str r1, [r0]
	pop {r3, pc}
	.balign 4, 0
_0225CFA0: .word 0x04000008
_0225CFA4: .word 0xFFFFCFFD
_0225CFA8: .word 0x0000CFFB
_0225CFAC: .word 0x00007FFF
_0225CFB0: .word 0xBFFF0000
_0225CFB4: .word 0x04000580
	thumb_func_end ov93_0225CF34

	.include "asm/macros.inc"
	.include "overlay_47.inc"
	.include "global.inc"
	.include "overlay47_exact_bank.inc"

	.text
	.public ov47_02258A14
	.public ov47_02258A1C
	.public ov47_02258A60
	.public ov47_02258A80
	.public ov47_02258A8C
	.public ov47_02258B8C
	.public ov47_02258C44
	.public ov47_02258CC0
	.public ov47_02258CEC
	.public ov47_02258D18
	.public ov47_02258D44
	.public ov47_02258D78
	.public ov47_02258DA8
	.public ov47_02258DB4
	.public ov47_022591F8
	.public ov47_0225921C
	.public ov47_02259228
	.public ov47_02259278
	.public ov47_022592B4
	.public ov47_02259318
	.public ov47_02259384
	.public ov47_022593A0
	.public ov47_022593B4
	.public ov47_022593CC
	.public ov47_02259404
	.public ov47_02259430
	.public ov47_02259448
	.public ov47_0225945C
	.public ov47_0225946C
	.public ov47_02259968
	.public ov47_0225999C
	.public ov47_02259B30
	.public ov47_02259D24
	.public ov47_02259D40
	.public ov47_02259D58
	.public ov47_02259DA4
	.public ov47_02259DCC

	thumb_func_start ov47_02259D74
ov47_02259D74: ; 0x02259D74
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r6, #0
	str r6, [r5, #0xc]
	add r4, r5, #0
	str r6, [r5, #0x10]
	add r4, #0xc
	add r7, r6, #0
_02259D84:
	add r0, r6, #0
	add r0, #8
	bl ov45_0222F544
	str r0, [r5]
	ldr r1, [r4]
	ldr r2, [r4, #4]
	add r0, r1, r0
	adc r2, r7
	str r0, [r4]
	add r6, r6, #1
	add r5, r5, #4
	str r2, [r4, #4]
	cmp r6, #3
	blt _02259D84
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov47_02259D74

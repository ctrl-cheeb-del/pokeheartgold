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

	thumb_func_start ov47_02258C70
ov47_02258C70: ; 0x02258C70
	push {r3, r4, r5, r6, r7, lr}
	ldr r4, _02258CBC ; =ov47_02259E9C
	str r0, [sp]
	add r7, r2, #0
	str r1, [r0, #0x30]
	mov r6, #0
	add r5, r0, #0
_02258C7E:
	ldr r2, [r4]
	mov r0, #0
	mov r1, #0x1b
	add r3, r7, #0
	bl NewMsgDataFromNarc
	add r6, r6, #1
	add r4, r4, #4
	stmia r5!, {r0}
	cmp r6, #9
	blt _02258C7E
	add r0, r7, #0
	bl MessageFormat_New
	ldr r1, [sp]
	str r0, [r1, #0x24]
	mov r0, #1
	lsl r0, r0, #8
	add r1, r7, #0
	bl String_New
	ldr r1, [sp]
	str r0, [r1, #0x28]
	mov r0, #1
	lsl r0, r0, #8
	add r1, r7, #0
	bl String_New
	ldr r1, [sp]
	str r0, [r1, #0x2c]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02258CBC: .word ov47_02259E9C
	thumb_func_end ov47_02258C70

	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225DD2C
	.extern ov93_0225E45C
	.extern ov93_02262AF0
	.extern ov93_02262AF4
	.extern ov93_02262AF8
	.extern ov93_02262AFC
	.extern ov93_02262B00

	thumb_func_start ov93_0225DD2C
ov93_0225DD2C: ; 0x0225DD2C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp, #8]
	str r0, [sp, #0x10]
	add r0, #0xd8
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r7, #0
	bl sub_0203769C
	add r1, r0, #0
	ldr r0, [sp, #8]
	bl ov93_0225E45C
	add r4, r0, #0
	mov r1, #0x14
	mul r4, r1
	ldr r2, _0225DEB4 ; =ov93_02262AF0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0xc]
	ldr r2, [r2, r4]
	mov r3, #0x75
	bl sub_02018030
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x10]
	add r0, #0x10
	bl sub_020181B0
	ldr r0, [sp, #0x10]
	add r1, r7, #0
	ldr r2, _0225DEB8 ; =0xFFFE7000
	add r0, #0x10
	add r3, r1, #0
	bl sub_020182A8
	ldr r0, [sp, #0x10]
	mov r1, #1
	lsl r1, r1, #0xc
	add r0, #0x10
	add r2, r1, #0
	add r3, r1, #0
	bl sub_020182C4
	ldr r0, [sp, #0x10]
	mov r1, #1
	add r0, #0x10
	bl sub_020182A0
	ldr r2, _0225DEBC ; =ov93_02262AF4
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0xc]
	ldr r2, [r2, r4]
	add r0, #0x88
	mov r3, #0x75
	bl sub_02018030
	ldr r2, _0225DEC0 ; =ov93_02262AF8
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0xc]
	ldr r2, [r2, r4]
	add r0, #0x98
	mov r3, #0x75
	bl sub_02018030
	ldr r2, _0225DEC4 ; =ov93_02262AFC
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0xc]
	ldr r2, [r2, r4]
	add r0, #0xa8
	mov r3, #0x75
	bl sub_02018030
	ldr r2, _0225DEC8 ; =ov93_02262B00
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0xc]
	ldr r2, [r2, r4]
	add r0, #0xb8
	mov r3, #0x75
	bl sub_02018030
	add r0, r7, #0
	str r0, [sp, #0x1c]
	mov r1, #0x51
	ldr r0, [sp, #0x10]
	lsl r1, r1, #2
	add r0, r0, r1
	str r0, [sp, #0x14]
	ldr r0, [sp, #8]
	str r0, [sp, #0x24]
	add r0, #0xa8
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x20]
	add r0, #0x88
	str r0, [sp, #0x20]
_0225DDEC:
	mov r0, #0
	ldr r4, [sp, #0x20]
	ldr r5, [sp, #0x14]
	ldr r6, [sp, #0x10]
	str r0, [sp, #0x18]
_0225DDF6:
	cmp r7, #0
	bne _0225DE18
	mov r0, #0x75
	str r0, [sp]
	ldr r0, [sp, #0x24]
	ldr r3, [sp, #0x18]
	str r0, [sp, #4]
	ldr r2, [sp, #0xc]
	add r0, r5, #0
	add r1, r4, #0
	add r3, #0x23
	bl sub_020180BC
	mov r0, #0x51
	lsl r0, r0, #2
	ldr r7, [r6, r0]
	b _0225DE24
_0225DE18:
	ldr r3, [sp, #0x24]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r7, #0
	bl sub_020180E8
_0225DE24:
	add r0, r5, #0
	mov r1, #0
	bl sub_02018198
	ldr r0, [sp, #0x18]
	add r4, #0x10
	add r0, r0, #1
	add r5, #0x90
	add r6, #0x90
	str r0, [sp, #0x18]
	cmp r0, #4
	blt _0225DDF6
	mov r0, #9
	ldr r1, [sp, #0x14]
	lsl r0, r0, #6
	add r0, r1, r0
	str r0, [sp, #0x14]
	mov r0, #9
	ldr r1, [sp, #0x10]
	lsl r0, r0, #6
	add r0, r1, r0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #8
	blt _0225DDEC
	ldr r1, [sp, #8]
	ldr r0, _0225DECC ; =0x000013A0
	mov r2, #0x1e
	add r0, r1, r0
	ldr r1, [sp, #0xc]
	mov r3, #0x75
	bl sub_02018030
	ldr r1, [sp, #8]
	ldr r0, _0225DECC ; =0x000013A0
	add r2, r1, #0
	add r0, r1, r0
	ldr r1, _0225DECC ; =0x000013A0
	add r0, #0x10
	add r1, r2, r1
	bl sub_020181B0
	ldr r1, [sp, #8]
	ldr r0, _0225DECC ; =0x000013A0
	ldr r2, _0225DEB8 ; =0xFFFE7000
	add r0, r1, r0
	mov r1, #0
	add r0, #0x10
	add r3, r1, #0
	bl sub_020182A8
	ldr r1, [sp, #8]
	ldr r0, _0225DECC ; =0x000013A0
	add r0, r1, r0
	mov r1, #1
	lsl r1, r1, #0xc
	add r0, #0x10
	add r2, r1, #0
	add r3, r1, #0
	bl sub_020182C4
	ldr r1, [sp, #8]
	ldr r0, _0225DECC ; =0x000013A0
	add r0, r1, r0
	add r0, #0x10
	mov r1, #1
	bl sub_020182A0
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225DEB4: .word ov93_02262AF0
_0225DEB8: .word 0xFFFE7000
_0225DEBC: .word ov93_02262AF4
_0225DEC0: .word ov93_02262AF8
_0225DEC4: .word ov93_02262AFC
_0225DEC8: .word ov93_02262B00
_0225DECC: .word 0x000013A0
	thumb_func_end ov93_0225DD2C

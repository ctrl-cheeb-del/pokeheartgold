	.include "asm/macros.inc"
	.include "overlay_67.inc"
	.include "global.inc"

	.public ov67_021E6D50
	.public ov67_021E6D5C
	.public ov67_021E6D6C
	.public ov67_021E6D7C
	.public ov67_021E6D90
	.public ov67_021E6DA8
	.public ov67_021E6DC4
	.public ov67_021E6DE0
	.public ov67_021E6DFC
	.public ov67_021E6E18
	.public ov67_021E6E38
	.public ov67_021E6E60
	.public ov67_021E6E98
	.public ov67_021E6EE8
	.public ov67_021E6F50
	.public ov67_021E7020

	.public _021E6D4C

	.text
	.public ov67_021E5900
	.public ov67_021E5968
	.public ov67_021E5984
	.public ov67_021E5A6C
	.public ov67_021E5B44
	.public ov67_021E5BC0
	.public ov67_021E5BE0
	.public ov67_021E5C04
	.public ov67_021E5C44
	.public ov67_021E5DA0
	.public ov67_021E5E84
	.public ov67_021E5EB0
	.public ov67_021E6008
	.public ov67_021E6080
	.public ov67_021E60B4
	.public ov67_021E60F4
	.public ov67_021E6118
	.public ov67_021E6164
	.public ov67_021E61A0
	.public ov67_021E61E8
	.public ov67_021E6220
	.public ov67_021E63E8
	.public ov67_021E6474
	.public ov67_021E6490
	.public ov67_021E6530
	.public ov67_021E65C0
	.public ov67_021E6688
	.public ov67_021E681C
	.public ov67_021E6820
	.public ov67_021E6990
	.public ov67_021E69D8
	.public ov67_021E6A00
	.public ov67_021E6A08
	.public ov67_021E6A28
	.public ov67_021E6A40
	.public ov67_021E6B6C
	.public ov67_021E6BB8
	.public ov67_021E6BC4
	.public ov67_021E6C04
	.public ov67_021E6C14
	.public ov67_021E6C5C
	.public ov67_021E6C60
	.public ov67_021E6D20
	thumb_func_start ov67_021E5BE0
ov67_021E5BE0: ; 0x021E5BE0
	push {r4, lr}
	add r4, r0, #0
	bl ov67_021E6A00
	ldr r0, [r4, #0x10]
	bl DoScheduledBgGpuUpdates
	ldr r3, _021E5BFC ; =0x027E0000
	ldr r1, _021E5C00 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_021E5BFC: .word 0x027E0000
_021E5C00: .word 0x00003FF8
	thumb_func_end ov67_021E5BE0


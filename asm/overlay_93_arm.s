	.include "asm/macros.inc"
	.public _0225EEA8
	.public _0225EF20
	.public _0225EF70
	.public _0225EFD4
	.public _0225F264
	.public _0225F2C8
	.public _0225F2DC
	.public _0225F2EC
	.public _0225F300
	.public _0225F314
	.public _0225F32C
	.public _0225F340
	.public _0225F358
	.public _0225F36C
	.public _0225F3E4
	.public _0225F3EC
	.public _0225F43C
	.public _0225F440
	.public _0225F444
	.public _0225F448
	.public _0225F4BC
	.public _0225F4E8
	.public _0225F4F4
	.public _0225F51C
	.public _0225F540
	.public _0225F544
	.public _0225F5A0
	.public _0225F5B4
	.public _0225F5E0
	.public _0225F608
	.public _0225F680
	.public _0225F69C
	.public _0225F6C0
	.public _0225F6E0
	.public _0225F700
	.public _0225F724
	.public _0225F7D0
	.public _0225F7E4
	.public _0225F8A4
	.public _0225F8A8
	.public _0225F948
	.public _0225FAB4
	.public _0225FAB8
	.public _0225FAF8
	.public _0225FAFC
	.public _0225FB68
	.public _0225FB94
	.public _0225FBE0
	.public _0225FBEC
	.public _02262C04
	.public ov93_0225EE98
	.public ov93_0225EF0C
	.public ov93_0225EF5C
	.public ov93_0225EFAC
	.public ov93_0225F268
	.public ov93_0225F370
	.public ov93_0225F44C
	.public ov93_0225F548
	.public ov93_0225F8AC
	.public ov93_0225F8E4
	.public ov93_0225F94C
	.public ov93_0225F9AC
	.public ov93_0225F9D8
	.public ov93_0225FABC
	.public ov93_0225FB00
	.public ov93_0225FB6C
	.public ov93_0225FBE4
	.public ov93_02262C05
	.public ov93_02262C06
	.public ov93_02262C07
	.public ov93_02262C08
	.public ov93_02262C38
	.include "overlay_93_arm.inc"
	.include "global.inc"

	.text
	.public ov93_0225EE98
	.public ov93_0225EF0C
	.public ov93_0225EF5C
	.public ov93_0225F8AC
	.public ov93_0225F94C
	.public ov93_0225F9AC
	.public ov93_0225F9D8
	.public ov93_0225FABC
	.public ov93_0225FB00
	.public ov93_0225FB6C
	.public ov93_0225FBE4
	.public ov93_0225F268

	arm_func_start ov93_0225EFAC
ov93_0225EFAC: ; 0x0225EFAC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x48
	mov sb, #0
	ldr r6, _0225F264 ; =0x1FF00000
	mov sl, r0
	mov r4, sb
	add r8, sp, #2
	add r7, sp, #0
	mov fp, sb
	mov r5, sb
_0225EFD4:
	mov r0, #1
	str r0, [sp, #0x44]
	mov r0, #0x40
	add r1, sp, #0x44
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	add r1, sl, sb, lsl #5
	ldr r0, [r1, #0xc]
	ldr r1, [r1, #0x10]
	mov r2, r8
	mov r3, r7
	bl ov93_0225F268
	add r1, sl, sb, lsl #5
	ldr r0, [r1, #0x10c]
	ldr r1, [r1, #0x110]
	mov r0, r0, lsl #8
	mov r1, r1, lsl #8
	mov r1, r1, asr #0x10
	mov r1, r1, lsl #0x10
	mov r0, r0, asr #0x10
	mov r1, r1, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r1, r1, lsl #0x10
	orr r0, r1, r0, lsr #16
	str r0, [sp, #0x40]
	mov r0, #0x22
	add r1, sp, #0x40
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	mov r0, #0x21
	add r1, sp, #0x3c
	mov r2, #1
	str r6, [sp, #0x3c]
	bl NNS_G3dGeBufferOP_N
	ldrh r3, [sp, #2]
	ldrh r2, [sp]
	mov r0, #0x23
	add r1, sp, #0x34
	orr r2, r3, r2, lsl #16
	str r2, [sp, #0x34]
	mov r2, #2
	str r5, [sp, #0x38]
	bl NNS_G3dGeBufferOP_N
	add r1, sl, sb, lsl #5
	ldr r0, [r1, #0x14]
	ldr r1, [r1, #0x18]
	mov r2, r8
	mov r3, r7
	bl ov93_0225F268
	add r1, sl, sb, lsl #5
	ldr r0, [r1, #0x114]
	ldr r1, [r1, #0x118]
	mov r0, r0, lsl #8
	mov r1, r1, lsl #8
	mov r1, r1, asr #0x10
	mov r1, r1, lsl #0x10
	mov r0, r0, asr #0x10
	mov r1, r1, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r1, r1, lsl #0x10
	orr r0, r1, r0, lsr #16
	str r0, [sp, #0x30]
	mov r0, #0x22
	add r1, sp, #0x30
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	mov r0, #0x21
	add r1, sp, #0x2c
	mov r2, #1
	str r6, [sp, #0x2c]
	bl NNS_G3dGeBufferOP_N
	ldrh r3, [sp, #2]
	ldrh r2, [sp]
	mov r0, #0x23
	add r1, sp, #0x24
	orr r2, r3, r2, lsl #16
	str r2, [sp, #0x24]
	mov r2, #2
	str r4, [sp, #0x28]
	bl NNS_G3dGeBufferOP_N
	add r1, sl, sb, lsl #5
	ldr r0, [r1, #0x24]
	ldr r1, [r1, #0x28]
	mov r2, r8
	mov r3, r7
	bl ov93_0225F268
	add r1, sl, sb, lsl #5
	ldr r0, [r1, #0x124]
	ldr r1, [r1, #0x128]
	mov r0, r0, lsl #8
	mov r1, r1, lsl #8
	mov r1, r1, asr #0x10
	mov r1, r1, lsl #0x10
	mov r0, r0, asr #0x10
	mov r1, r1, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r1, r1, lsl #0x10
	orr r0, r1, r0, lsr #16
	str r0, [sp, #0x20]
	mov r0, #0x22
	add r1, sp, #0x20
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	mov r0, #0x21
	add r1, sp, #0x1c
	mov r2, #1
	str r6, [sp, #0x1c]
	bl NNS_G3dGeBufferOP_N
	ldrh r3, [sp, #2]
	ldrh r2, [sp]
	mov r0, #0x23
	add r1, sp, #0x14
	orr r2, r3, r2, lsl #16
	str r2, [sp, #0x14]
	mov r2, #2
	str fp, [sp, #0x18]
	bl NNS_G3dGeBufferOP_N
	add r1, sl, sb, lsl #5
	ldr r0, [r1, #0x1c]
	ldr r1, [r1, #0x20]
	mov r2, r8
	mov r3, r7
	bl ov93_0225F268
	add r1, sl, sb, lsl #5
	ldr r0, [r1, #0x11c]
	ldr r1, [r1, #0x120]
	mov r0, r0, lsl #8
	mov r1, r1, lsl #8
	mov r1, r1, asr #0x10
	mov r1, r1, lsl #0x10
	mov r0, r0, asr #0x10
	mov r1, r1, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r1, r1, lsl #0x10
	orr r0, r1, r0, lsr #16
	str r0, [sp, #0x10]
	mov r0, #0x22
	add r1, sp, #0x10
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	mov r0, #0x21
	add r1, sp, #0xc
	mov r2, #1
	str r6, [sp, #0xc]
	bl NNS_G3dGeBufferOP_N
	mov r0, #0
	str r0, [sp, #8]
	ldrh r3, [sp, #2]
	ldrh r2, [sp]
	mov r0, #0x23
	add r1, sp, #4
	orr r2, r3, r2, lsl #16
	str r2, [sp, #4]
	mov r2, #2
	bl NNS_G3dGeBufferOP_N
	mov r1, #0
	mov r0, #0x41
	mov r2, r1
	bl NNS_G3dGeBufferOP_N
	add sb, sb, #1
	cmp sb, #8
	blt _0225EFD4
	add sp, sp, #0x48
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.balign 4, 0
_0225F264: .word 0x1FF00000
	arm_func_end ov93_0225EFAC

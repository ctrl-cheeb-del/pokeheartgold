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


	arm_func_start ov93_0225F268
ov93_0225F268: ; 0x0225F268
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, r0, asr #0x1f
	mov r5, r1
	mov r1, r4, lsl #0xc
	mov r7, r2
	mov r6, r3
	orr r1, r1, r0, lsr #20
	mov r0, r0, lsl #0xc
	mov r2, #0x80000
	mov r3, #0
	bl _ll_sdiv
	mov r1, r5, asr #0x1f
	mov r1, r1, lsl #0xc
	mov r4, r0
	orr r1, r1, r5, lsr #20
	mov r0, r5, lsl #0xc
	mov r2, #0x80000
	mov r3, #0
	bl _ll_sdiv
	mov r5, r0
	ldr r0, _0225F36C ; =0x00007FFF
	cmp r4, r0
	ble _0225F2C8
	bl GF_AssertFail
_0225F2C8:
	mov r0, #0x8000
	rsb r0, r0, #0
	cmp r4, r0
	bge _0225F2DC
	bl GF_AssertFail
_0225F2DC:
	ldr r0, _0225F36C ; =0x00007FFF
	cmp r5, r0
	ble _0225F2EC
	bl GF_AssertFail
_0225F2EC:
	mov r0, #0x8000
	rsb r0, r0, #0
	cmp r5, r0
	bge _0225F300
	bl GF_AssertFail
_0225F300:
	ldr r0, _0225F36C ; =0x00007FFF
	sub r1, r4, #0x800
	cmp r1, r0
	ble _0225F314
	bl GF_AssertFail
_0225F314:
	mov r0, #0x8000
	sub r1, r4, #0x800
	rsb r0, r0, #0
	cmp r1, r0
	bge _0225F32C
	bl GF_AssertFail
_0225F32C:
	ldr r0, _0225F36C ; =0x00007FFF
	add r1, r5, #0x800
	cmp r1, r0
	ble _0225F340
	bl GF_AssertFail
_0225F340:
	mov r0, #0x8000
	add r1, r5, #0x800
	rsb r0, r0, #0
	cmp r1, r0
	bge _0225F358
	bl GF_AssertFail
_0225F358:
	sub r0, r4, #0x800
	strh r0, [r7]
	add r0, r5, #0x800
	strh r0, [r6]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225F36C: .word 0x00007FFF
	arm_func_end ov93_0225F268


	arm_func_start ov93_0225F370
ov93_0225F370: ; 0x0225F370
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r1, [r4, #0x238]
	cmp r1, #1
	ldrne r1, [r4, #0x218]
	cmpne r1, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r2, [r4, #0x270]
	ldr r3, _0225F43C ; =ov93_02262C07
	ldr r1, _0225F440 ; =ov93_02262C05
	ldrb lr, [r3, r2, lsl #2]
	ldr r5, [r4, #0x230]
	ldrb r3, [r1, r2, lsl #2]
	ldr ip, [r4, #0x20c]
	add r1, lr, r5, asr #12
	cmp ip, r3
	blt _0225F3E4
	ldr r3, _0225F444 ; =ov93_02262C06
	ldrb r3, [r3, r2, lsl #2]
	cmp ip, r3
	bgt _0225F3E4
	ldr ip, [r4, #0x210]
	cmp ip, r1
	blt _0225F3E4
	ldr r3, _0225F448 ; =ov93_02262C08
	ldrb r2, [r3, r2, lsl #2]
	cmp ip, r2
	ble _0225F3EC
_0225F3E4:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_0225F3EC:
	mov r2, #1
	str r2, [r4, #0x238]
	ldr r2, [r4, #0x20c]
	str r2, [r4, #0x224]
	ldr r2, [r4, #0x210]
	str r2, [r4, #0x228]
	ldr r2, [r4, #0x210]
	sub r1, r2, r1
	str r1, [r4, #0x22c]
	ldr r2, [r4, #0x20]
	ldr r1, [r4, #0x10]
	sub r1, r1, r2
	add r1, r1, r1, lsr #31
	add r1, r2, r1, asr #1
	rsb r1, r1, #0
	str r1, [r4, #0x230]
	bl ov93_0225F9AC
	str r0, [r4, #0x240]
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
	.balign 4, 0
_0225F43C: .word ov93_02262C07
_0225F440: .word ov93_02262C05
_0225F444: .word ov93_02262C06
_0225F448: .word ov93_02262C08
	arm_func_end ov93_0225F370


	arm_func_start ov93_0225F44C
ov93_0225F44C: ; 0x0225F44C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x238]
	mov r4, #0
	cmp r0, #1
	bne _0225F4E8
	ldr r2, [r5, #0x23c]
	ldr r1, [r5, #0x210]
	cmp r1, r2
	movlt r0, r4
	strltb r4, [r5, #0x274]
	ldmltia sp!, {r3, r4, r5, pc}
	streqb r4, [r5, #0x274]
	moveq r0, #1
	ldmeqia sp!, {r3, r4, r5, pc}
	sub r0, r4, #1
	cmp r2, r0
	beq _0225F4BC
	cmp r1, r2
	ble _0225F4BC
	ldr r0, _0225F540 ; =0x0000058F
	bl IsSEPlaying
	cmp r0, #0
	bne _0225F4BC
	ldr r0, _0225F540 ; =0x0000058F
	bl PlaySE
	mov r0, #1
	strb r0, [r5, #0x274]
_0225F4BC:
	ldr r1, [r5, #0x270]
	ldr r0, _0225F544 ; =ov93_02262C07
	ldr ip, [r5, #0x210]
	ldr r3, [r5, #0x22c]
	ldr r2, [r5, #0x230]
	ldrb r0, [r0, r1, lsl #2]
	sub r1, ip, r3
	str ip, [r5, #0x23c]
	add r0, r2, r0, lsl #12
	rsb r2, r0, r1, lsl #12
	b _0225F4F4
_0225F4E8:
	ldr r0, [r5, #0x248]
	mov r4, #1
	rsb r2, r0, #0
_0225F4F4:
	mov r0, r5
	mov r1, r4
	bl ov93_0225F548
	cmp r0, #0
	beq _0225F51C
	cmp r0, #1
	cmpne r0, #2
	bne _0225F51C
	mov r0, r5
	bl ov93_0225EB38
_0225F51C:
	ldr r2, [r5, #0x20]
	ldr r1, [r5, #0x10]
	mov r0, #1
	sub r1, r1, r2
	add r1, r1, r1, lsr #31
	add r1, r2, r1, asr #1
	rsb r1, r1, #0
	str r1, [r5, #0x230]
	ldmia sp!, {r3, r4, r5, pc}
	.balign 4, 0
_0225F540: .word 0x0000058F
_0225F544: .word ov93_02262C07
	arm_func_end ov93_0225F44C


	arm_func_start ov93_0225F548
ov93_0225F548: ; 0x0225F548
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x14
	mov r4, r0
	ldr r5, [r4, #0x10]
	ldr r3, [r4, #0x20]
	rsb r6, r5, #0
	rsb r7, r3, #0
	sub r3, r6, r7
	add r3, r3, r3, lsr #31
	mov r5, r2
	mov r2, #0
	mov sb, r1
	add r8, r7, r3, asr #1
	str r2, [sp, #8]
	bl ov93_0225F8AC
	cmp r0, #0
	beq _0225F5A0
	cmp r0, #1
	beq _0225F5B4
	cmp r0, #2
	beq _0225F5E0
	b _0225F608
_0225F5A0:
	add r1, r6, r5
	add r0, r7, r5
	str r1, [sp, #0x10]
	str r0, [sp, #0xc]
	b _0225F608
_0225F5B4:
	add r0, sp, #0x10
	str r0, [sp]
	add sl, sp, #0xc
	mov r0, r4
	mov r1, r5
	mov r2, r6
	mov r3, r7
	str sl, [sp, #4]
	bl ov93_0225F8E4
	str r0, [sp, #8]
	b _0225F608
_0225F5E0:
	add r0, sp, #0xc
	str r0, [sp]
	add sl, sp, #0x10
	mov r0, r4
	mov r1, r5
	mov r2, r7
	mov r3, r6
	str sl, [sp, #4]
	bl ov93_0225F8E4
	str r0, [sp, #8]
_0225F608:
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	sub r0, r2, r1
	add r0, r0, r0, lsr #31
	add r5, r1, r0, asr #1
	cmp r8, r5
	cmpeq r6, r2
	cmpeq r7, r1
	addeq sp, sp, #0x14
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	cmp r5, #0
	movlt r5, #0
	cmp r2, #0
	movlt r0, #0
	strlt r0, [sp, #0x10]
	cmp r1, #0
	movlt r0, #0
	strlt r0, [sp, #0xc]
	cmp r5, #0x64000
	movgt r0, #1
	strgt r0, [sp, #8]
	ldr r0, [sp, #0x10]
	movgt r5, #0x64000
	cmp r0, #0x64000
	ble _0225F680
	mov r0, #0x64000
	str r0, [sp, #0x10]
	mov r0, #1
	str r0, [sp, #8]
_0225F680:
	ldr r0, [sp, #0xc]
	cmp r0, #0x64000
	ble _0225F69C
	mov r0, #0x64000
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #8]
_0225F69C:
	mov r0, r4
	mov r1, sb
	bl ov93_0225F8AC
	cmp r0, #0
	beq _0225F6C0
	cmp r0, #1
	beq _0225F700
	cmp r0, #2
	beq _0225F6E0
_0225F6C0:
	ldr r0, [sp, #0xc]
	mov r1, #0x40000
	sub r0, r0, r5
	bl FX_Atan2Idx
	add r1, r0, #0x8000
	mov r1, r1, lsl #0x10
	mov fp, r1, lsr #0x10
	b _0225F724
_0225F6E0:
	ldr r0, [sp, #0xc]
	mov r1, #0x40000
	sub r0, r0, r5
	bl FX_Atan2Idx
	add r1, r0, #0x8000
	mov r1, r1, lsl #0x10
	mov fp, r1, lsr #0x10
	b _0225F724
_0225F700:
	ldr r0, [sp, #0x10]
	mov r1, #0x40000
	sub r0, r0, r5
	rsb r1, r1, #0
	bl FX_Atan2Idx
	mov fp, r0
	add r0, fp, #0x8000
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
_0225F724:
	mov r1, fp, asr #4
	mov r7, r1, lsl #1
	add r2, r7, #1
	ldr r1, _0225F8A4 ; =FX_SinCosTable_
	mov r2, r2, lsl #1
	ldrsh r3, [r1, r2]
	mov r2, r0, asr #4
	mov r6, r2, lsl #1
	mov r2, r3, lsl #6
	add r2, r2, #0x40000
	str r2, [r4, #0xc]
	mov r2, r7, lsl #1
	ldrsh r7, [r1, r2]
	add r2, r6, #1
	mov r2, r2, lsl #1
	add r7, r5, r7, lsl #6
	rsb r7, r7, #0
	str r7, [r4, #0x10]
	ldrsh r7, [r1, r2]
	ldr r2, _0225F8A8 ; =0x92492493
	rsb r3, r5, #0x70000
	mov r7, r7, lsl #6
	add r7, r7, #0x40000
	mov r6, r6, lsl #1
	str r7, [r4, #0x1c]
	ldrsh r6, [r1, r6]
	smull r1, lr, r2, r3
	add r1, r5, r6, lsl #6
	rsb r6, r1, #0
	add lr, r3, lr
	mov r1, r3, lsr #0x1f
	str r6, [r4, #0x20]
	cmp r0, #0x8000
	add lr, r1, lr, asr #2
	smullls r1, r6, r2, r0
	addls r6, r0, r6
	movls r1, r0, lsr #0x1f
	bls _0225F7D0
	rsb r1, r0, #0x10000
	rsb r3, r1, #0
	smull r1, r6, r2, r3
	add r6, r3, r6
	mov r1, r3, lsr #0x1f
_0225F7D0:
	add r6, r1, r6, asr #2
	ldr r3, _0225F8A4 ; =FX_SinCosTable_
	mov r7, r6
	mov r8, lr
	mov ip, #1
_0225F7E4:
	sub r1, fp, r7
	mov r1, r1, asr #4
	mov r1, r1, lsl #1
	add r2, r3, r1, lsl #1
	ldrsh sb, [r2, #2]
	sub r2, r0, r7
	mov r1, r1, lsl #1
	mov sb, sb, lsl #6
	add sl, sb, #0x40000
	mov r2, r2, asr #4
	mov sb, r2, lsl #1
	add r2, r4, ip, lsl #5
	str sl, [r2, #0xc]
	ldrsh r1, [r3, r1]
	mov sl, sb, lsl #1
	add sb, r3, sb, lsl #1
	add r1, r5, r1, lsl #6
	add r1, r8, r1
	rsb r1, r1, #0
	str r1, [r2, #0x10]
	ldrsh r1, [sb, #2]
	add r7, r7, r6
	add ip, ip, #1
	mov r1, r1, lsl #6
	add r1, r1, #0x40000
	str r1, [r2, #0x1c]
	ldrsh r1, [r3, sl]
	cmp ip, #7
	add r1, r5, r1, lsl #6
	add r1, r8, r1
	rsb r1, r1, #0
	str r1, [r2, #0x20]
	ldr r1, [r2, #0xc]
	add r8, r8, lr
	str r1, [r2, #-0xc]
	ldr r1, [r2, #0x10]
	str r1, [r2, #-8]
	ldr r1, [r2, #0x1c]
	str r1, [r2, #4]
	ldr r1, [r2, #0x20]
	str r1, [r2, #8]
	blt _0225F7E4
	ldr r0, [sp, #8]
	cmp r0, #1
	moveq r0, #2
	movne r0, #0
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.balign 4, 0
_0225F8A4: .word FX_SinCosTable_
_0225F8A8: .word 0x92492493
	arm_func_end ov93_0225F548

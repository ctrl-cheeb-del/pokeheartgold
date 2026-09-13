	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225CFC0
	.extern ov93_02262A18
	.extern ov93_02262A38

	thumb_func_start ov93_0225CFC0
ov93_0225CFC0: ; 0x0225CFC0
	push {r4, lr}
	sub sp, #0x18
	ldr r3, _0225D058 ; =ov93_02262A38
	add r4, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0xc
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	mov r0, #0x75
	bl Camera_New
	add r1, r4, #0
	add r1, #0x9c
	str r0, [r1]
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	mov r1, #0x7b
	str r0, [sp, #8]
	ldr r2, _0225D05C ; =ov93_02262A18
	ldr r3, _0225D060 ; =0x00000FA4
	add r0, sp, #0xc
	lsl r1, r1, #0xc
	bl Camera_Init_FromTargetDistanceAndAngle
	add r2, r4, #0
	add r2, #0x9c
	mov r0, #1
	mov r1, #0xe1
	ldr r2, [r2]
	lsl r0, r0, #0xc
	lsl r1, r1, #0xe
	bl Camera_SetPerspectiveClippingPlane
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	bl Camera_SetStaticPtr
	mov r0, #0x75
	bl Camera_New
	add r1, r4, #0
	add r1, #0xa0
	str r0, [r1]
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	add r0, r4, #0
	add r0, #0xa0
	ldr r0, [r0]
	mov r1, #5
	str r0, [sp, #8]
	ldr r2, _0225D05C ; =ov93_02262A18
	ldr r3, _0225D060 ; =0x00000FA4
	add r0, sp, #0xc
	lsl r1, r1, #0x10
	bl Camera_Init_FromTargetDistanceAndAngle
	add r4, #0xa0
	mov r0, #1
	mov r1, #0xe1
	ldr r2, [r4]
	lsl r0, r0, #0xc
	lsl r1, r1, #0xe
	bl Camera_SetPerspectiveClippingPlane
	add sp, #0x18
	pop {r4, pc}
	nop
_0225D058: .word ov93_02262A38
_0225D05C: .word ov93_02262A18
_0225D060: .word 0x00000FA4
	thumb_func_end ov93_0225CFC0

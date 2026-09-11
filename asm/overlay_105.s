	.include "asm/macros.inc"
	.include "overlay_105.inc"
	.include "global.inc"

	.text
	.public ov105_021E5900
	.public ov105_021E5B14
	.public ov105_021E5B68
	.public ov105_021E5C84
	.public ov105_021E5BCC
	.public ov105_021E5CA4
	.public ov105_021E5DD4
	.public ov105_021E5E08
	.public ov105_021E59DC

	thumb_func_start ov105_021E5900
ov105_021E5900: ; 0x021E5900
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov r2, #0x31
	add r5, r0, #0
	mov r0, #3
	mov r1, #0x97
	lsl r2, r2, #0xc
	bl Heap_Create
	add r0, r5, #0
	mov r1, #0xa8
	mov r2, #0x97
	bl OverlayManager_CreateAndGetData
	mov r1, #0
	mov r2, #0xa8
	add r4, r0, #0
	bl memset
	add r0, r5, #0
	bl OverlayManager_GetArgs
	add r5, r0, #0
	add r0, r4, #0
	ldrb r1, [r5]
	add r0, #0x9c
	strb r1, [r0]
	add r0, r4, #0
	ldrb r1, [r5, #1]
	add r0, #0x9d
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #0
	add r0, #0x9e
	strb r1, [r0]
	mov r0, #0x97
	bl Camera_New
	str r0, [r4]
	bl ov105_021E5B68
	add r0, r4, #0
	bl ov105_021E5CA4
	add r0, r4, #0
	bl ov105_021E5BCC
	mov r4, #0
	mov r7, #2
	mov r6, #4
_021E5964:
	ldr r2, [r5, #4]
	mov r0, #6
	add r1, r4, #0
	mul r1, r0
	add r3, r2, r1
	ldrsh r1, [r2, r1]
	ldrsh r2, [r3, r7]
	ldrsh r3, [r3, r6]
	add r0, r4, #0
	bl NNS_G3dGlbLightVector
	ldr r2, [r5, #4]
	lsl r1, r4, #1
	add r1, r2, r1
	ldrh r1, [r1, #0x18]
	add r0, r4, #0
	bl NNS_G3dGlbLightColor
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _021E5964
	ldr r2, [r5, #4]
	ldrh r0, [r2, #0x20]
	ldrh r1, [r2, #0x22]
	ldr r2, [r2, #0x28]
	bl NNS_G3dGlbMaterialColorDiffAmb
	ldr r2, [r5, #4]
	ldrh r0, [r2, #0x24]
	ldrh r1, [r2, #0x26]
	ldr r2, [r2, #0x2c]
	bl NNS_G3dGlbMaterialColorSpecEmi
	ldr r3, [r5, #4]
	ldr r0, [r3, #0x40]
	str r0, [sp]
	ldr r0, [r3, #0x44]
	str r0, [sp, #4]
	ldr r0, [r3, #0x30]
	ldr r1, [r3, #0x34]
	ldr r2, [r3, #0x38]
	ldr r3, [r3, #0x3c]
	bl NNS_G3dGlbPolygonAttr
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x97
	str r0, [sp, #8]
	mov r0, #3
	add r2, r1, #0
	mov r3, #0
	bl BeginNormalPaletteFade
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov105_021E5900

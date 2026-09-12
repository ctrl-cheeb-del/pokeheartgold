	.include "asm/macros.inc"
	.public Thunk_G3X_Reset
	.public sub_0201543C
	.public NNS_G2dSetupSoftwareSpriteCamera
	.public Camera_PushLookAtToNNSGlb
	.public NNS_G3dGlbFlushP
	.public PokepicManager_DrawAll
	.public sub_02015460
	.text

	thumb_func_start ov59_0223C304
ov59_0223C304: ; 0x0223C304
	push {r4, lr}
	add r4, r0, #0
	bl Thunk_G3X_Reset
	bl sub_0201543C
	bl Thunk_G3X_Reset
	bl NNS_G2dSetupSoftwareSpriteCamera
	bl Camera_PushLookAtToNNSGlb
	ldr r2, _0223C348 ; =0x04000440
	mov r3, #0
	add r1, r2, #0
	str r3, [r2]
	add r1, #0x14
	str r3, [r1]
	mov r0, #2
	str r0, [r2]
	str r3, [r1]
	bl NNS_G3dGlbFlushP
	bl NNS_G2dSetupSoftwareSpriteCamera
	ldr r0, [r4, #0xc]
	bl PokepicManager_DrawAll
	bl sub_02015460
	ldr r0, _0223C34C ; =0x04000540
	mov r1, #1
	str r1, [r0]
	pop {r4, pc}
	.balign 4, 0
_0223C348: .word 0x04000440
_0223C34C: .word 0x04000540
	thumb_func_end ov59_0223C304

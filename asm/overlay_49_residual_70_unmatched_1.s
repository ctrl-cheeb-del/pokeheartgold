	.include "asm/macros.inc"
	.public GF_AssertFail
	.public sub_020182A4
	.public NNS_G3dGetTex
	.public NNS_G3dForceBindMdlTex
	.public NNS_G3dForceBindMdlPltt
	.public sub_020181D4
	.public sub_02018198
	.public NNS_G3dMdlSetMdlPolygonIDAll
	.public sub_020181EC
	.public sub_020181E0
	.public NNS_G3dReleaseMdlTex
	.public NNS_G3dReleaseMdlPltt

	.text

	thumb_func_start ov49_022659D0
ov49_022659D0: ; 0x022659D0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r2, #0
	str r0, [sp]
	lsl r7, r5, #2
	add r0, r1, #0
	str r1, [sp, #4]
	add r1, r0, r7
	ldr r0, _02265B04 ; =0x0000087C
	ldr r0, [r1, r0]
	cmp r0, #0
	bne _022659EC
	bl GF_AssertFail
_022659EC:
	mov r0, #0x78
	add r6, r5, #0
	mul r6, r0
	ldr r0, [sp, #4]
	add r0, #0xc
	add r0, r0, r6
	bl sub_020182A4
	cmp r0, #0
	beq _02265AFE
	ldr r0, [sp, #4]
	add r1, r0, r7
	ldr r0, _02265B04 ; =0x0000087C
	ldr r2, [r1, r0]
	ldr r0, _02265B08 ; =0x00010550
	ldrb r3, [r2]
	ldr r1, [sp]
	add r1, r1, r0
	lsl r3, r3, #4
	add r1, r1, r3
	str r1, [sp, #0xc]
	ldrb r1, [r2, #1]
	add r0, #0xf0
	lsl r2, r1, #2
	ldr r1, [sp]
	add r1, r1, r2
	ldr r0, [r1, r0]
	bl NNS_G3dGetTex
	ldr r1, [sp, #0xc]
	mov r2, #0
	str r0, [r1, #0xc]
	add r0, r1, #0
	ldr r0, [r0, #8]
	ldr r1, [r1, #0xc]
	add r3, r2, #0
	bl NNS_G3dForceBindMdlTex
	cmp r0, #0
	bne _02265A40
	bl GF_AssertFail
_02265A40:
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0xc]
	mov r2, #0
	ldr r0, [r0, #8]
	ldr r1, [r1, #0xc]
	add r3, r2, #0
	bl NNS_G3dForceBindMdlPltt
	cmp r0, #0
	bne _02265A58
	bl GF_AssertFail
_02265A58:
	ldr r0, [sp, #4]
	lsl r1, r5, #3
	add r5, r0, r1
	add r0, r0, r7
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	ldr r1, _02265B0C ; =0x000106DC
	str r0, [sp, #0x10]
	add r0, #0xc
	str r0, [sp, #0x10]
	ldr r0, [sp]
	mov r4, #0
	add r7, r0, r1
_02265A72:
	ldr r1, [sp, #8]
	ldr r0, _02265B04 ; =0x0000087C
	ldr r0, [r1, r0]
	add r0, r0, r4
	ldrb r1, [r0, #2]
	cmp r1, #0x11
	beq _02265AA6
	mov r0, #0x14
	mul r0, r1
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	add r0, r0, r6
	add r1, r7, r1
	bl sub_020181D4
	ldr r1, _02265B10 ; =0x000008C4
	ldr r0, [sp, #0x14]
	ldr r1, [r5, r1]
	add r0, r7, r0
	bl sub_02018198
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _02265A72
_02265AA6:
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #4]
	ldr r0, [r0, #8]
	ldr r1, [r1, #4]
	bl NNS_G3dMdlSetMdlPolygonIDAll
	ldr r0, [sp, #4]
	add r0, #0xc
	str r0, [sp, #4]
	add r0, r0, r6
	bl sub_020181EC
	ldr r1, _02265B0C ; =0x000106DC
	ldr r0, [sp]
	ldr r7, _02265B04 ; =0x0000087C
	mov r4, #0
	add r5, r0, r1
_02265AC8:
	ldr r0, [sp, #8]
	ldr r0, [r0, r7]
	add r0, r0, r4
	ldrb r1, [r0, #2]
	cmp r1, #0x11
	beq _02265AE8
	ldr r0, [sp, #4]
	mov r2, #0x14
	mul r2, r1
	add r0, r0, r6
	add r1, r5, r2
	bl sub_020181E0
	add r4, r4, #1
	cmp r4, #2
	blt _02265AC8
_02265AE8:
	ldr r0, [sp, #0xc]
	ldr r0, [r0, #8]
	bl NNS_G3dReleaseMdlTex
	ldr r0, [sp, #0xc]
	ldr r0, [r0, #8]
	bl NNS_G3dReleaseMdlPltt
	ldr r0, [sp, #0xc]
	mov r1, #0
	str r1, [r0, #0xc]
_02265AFE:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02265B04: .word 0x0000087C
_02265B08: .word 0x00010550
_02265B0C: .word 0x000106DC
_02265B10: .word 0x000008C4
	thumb_func_end ov49_022659D0

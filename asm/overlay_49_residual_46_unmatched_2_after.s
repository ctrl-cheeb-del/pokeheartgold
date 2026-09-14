	.include "asm/macros.inc"
	.public ov49_022588A0
	.public GF_AssertFail
	.public NNS_G3dGetTex
	.public NNS_G3dBindMdlSet
	.public sub_020181D4
	.public sub_02018198
	.public sub_020181EC
	.public sub_020181E0
	.public NNS_G3dReleaseMdlSet

	.text

	thumb_func_start ov49_0225DAFC
ov49_0225DAFC:
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldrb r0, [r5]
	str r1, [sp]
	cmp r0, #0
	beq _0225DBF2
	ldrb r0, [r5, #2]
	lsl r1, r0, #4
	ldr r0, [sp]
	add r0, r0, r1
	add r1, r5, #4
	bl ov49_022588A0
	cmp r0, #0
	beq _0225DBF2
	ldrb r0, [r5, #1]
	cmp r0, #3
	blo _0225DB26
	bl GF_AssertFail
_0225DB26:
	ldrb r0, [r5, #2]
	cmp r0, #2
	blo _0225DB30
	bl GF_AssertFail
_0225DB30:
	ldrb r1, [r5, #2]
	mov r0, #0xc
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp]
	add r1, r0, r2
	ldrb r0, [r5, #1]
	lsl r0, r0, #2
	add r0, r1, r0
	ldr r0, [r0, #0x20]
	bl NNS_G3dGetTex
	ldrb r1, [r5, #2]
	lsl r2, r1, #4
	ldr r1, [sp]
	add r1, r1, r2
	str r0, [r1, #0xc]
	ldrb r0, [r5, #2]
	lsl r1, r0, #4
	ldr r0, [sp]
	add r1, r0, r1
	ldr r0, [r1, #4]
	ldr r1, [r1, #0xc]
	bl NNS_G3dBindMdlSet
	cmp r0, #0
	bne _0225DB6A
	bl GF_AssertFail
_0225DB6A:
	ldr r7, [sp]
	mov r0, #0
	str r0, [sp, #4]
	add r6, r5, #0
	add r4, r0, #0
	add r7, #0x38
_0225DB76:
	ldr r0, [r6, #0x7c]
	cmp r0, #0
	beq _0225DBA0
	ldrb r2, [r5, #2]
	mov r1, #0x50
	add r0, r5, #4
	mul r1, r2
	add r1, r7, r1
	add r1, r1, r4
	bl sub_020181D4
	ldrb r1, [r5, #2]
	mov r0, #0x50
	mul r0, r1
	add r1, r6, #0
	add r1, #0x8c
	add r0, r7, r0
	ldr r1, [r1]
	add r0, r0, r4
	bl sub_02018198
_0225DBA0:
	ldr r0, [sp, #4]
	add r6, r6, #4
	add r0, r0, #1
	add r4, #0x14
	str r0, [sp, #4]
	cmp r0, #4
	blt _0225DB76
	add r0, r5, #4
	bl sub_020181EC
	ldr r0, [sp]
	mov r7, #0
	str r0, [sp, #8]
	add r0, #0x38
	add r6, r5, #0
	add r4, r7, #0
	str r0, [sp, #8]
_0225DBC2:
	ldr r0, [r6, #0x7c]
	cmp r0, #0
	beq _0225DBDA
	ldrb r1, [r5, #2]
	mov r2, #0x50
	add r0, r5, #4
	mul r2, r1
	ldr r1, [sp, #8]
	add r1, r1, r2
	add r1, r1, r4
	bl sub_020181E0
_0225DBDA:
	add r7, r7, #1
	add r6, r6, #4
	add r4, #0x14
	cmp r7, #4
	blt _0225DBC2
	ldrb r0, [r5, #2]
	lsl r1, r0, #4
	ldr r0, [sp]
	add r0, r0, r1
	ldr r0, [r0, #4]
	bl NNS_G3dReleaseMdlSet
_0225DBF2:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov49_0225DAFC

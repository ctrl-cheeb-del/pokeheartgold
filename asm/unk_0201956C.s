	.include "asm/macros.inc"
	.include "unk_020192D0.inc"
	.include "global.inc"

    .rodata

	.public _020F6298
_020F6298:
	.word sub_02019BA0, BgCommitTilemapBufferToVram, ScheduleBgTilemapBufferTransfer

	.text
	thumb_func_start sub_020196E8
sub_020196E8: ; 0x020196E8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	str r0, [sp, #0x1c]
	add r0, r2, #0
	ldr r2, [sp, #0x1c]
	lsl r1, r1, #4
	ldr r2, [r2, #4]
	add r4, r2, r1
	strb r0, [r4, #6]
	strb r3, [r4, #7]
	mov r1, #0xd
	ldrsb r1, [r4, r1]
	str r1, [sp, #0x28]
	cmp r0, r1
	bge _020197E6
	mov r1, #0xf
	ldrsb r1, [r4, r1]
	str r1, [sp, #0x20]
	cmp r3, r1
	bge _020197E6
	ldrh r1, [r4, #4]
	lsl r2, r1, #0x1a
	lsr r2, r2, #0x1a
	str r2, [sp, #0x2c]
	add r7, r0, r2
	mov r2, #0xc
	ldrsb r2, [r4, r2]
	mov ip, r2
	cmp r7, r2
	blt _020197E6
	lsl r1, r1, #0x14
	lsr r1, r1, #0x1a
	str r1, [sp, #0x24]
	add r6, r3, r1
	mov r1, #0xe
	ldrsb r2, [r4, r1]
	cmp r6, r2
	blt _020197E6
	lsl r1, r0, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #0x34]
	ldr r1, [sp, #0x2c]
	mov r5, #0
	lsl r1, r1, #0x18
	str r5, [sp, #0x30]
	mov r5, ip
	lsr r1, r1, #0x18
	cmp r0, r5
	bge _02019762
	mov r5, ip
	lsl r5, r5, #0x18
	lsr r5, r5, #0x18
	str r5, [sp, #0x34]
	mov r5, ip
	sub r0, r5, r0
	sub r1, r1, r0
	lsl r0, r0, #0x18
	lsl r1, r1, #0x18
	lsr r0, r0, #0x18
	lsr r1, r1, #0x18
	str r0, [sp, #0x30]
_02019762:
	ldr r0, [sp, #0x28]
	cmp r7, r0
	blt _02019770
	sub r0, r7, r0
	sub r0, r1, r0
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
_02019770:
	lsl r0, r3, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0x24]
	mov r5, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r3, r2
	bge _02019790
	lsl r5, r2, #0x18
	sub r2, r2, r3
	sub r0, r0, r2
	lsl r0, r0, #0x18
	lsl r2, r2, #0x18
	lsr r7, r5, #0x18
	lsr r0, r0, #0x18
	lsr r5, r2, #0x18
_02019790:
	ldr r2, [sp, #0x20]
	cmp r6, r2
	blt _0201979E
	sub r2, r6, r2
	sub r0, r0, r2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
_0201979E:
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [r4]
	add r3, r7, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xc]
	str r5, [sp, #0x10]
	ldr r0, [sp, #0x2c]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x24]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x1c]
	ldrb r1, [r4, #0xa]
	ldr r0, [r0]
	ldr r2, [sp, #0x34]
	bl CopyToBgTilemapRect
	ldr r2, [sp, #0x1c]
	ldr r0, [sp, #0x1c]
	ldrh r2, [r2, #0xa]
	ldrb r1, [r4, #0xa]
	ldr r0, [r0]
	lsl r2, r2, #0x11
	lsr r3, r2, #0xf
	ldr r2, _020197EC ; =_020F6298
	ldr r2, [r2, r3]
	blx r2
	ldrh r1, [r4, #4]
	ldr r0, _020197F0 ; =0xFFFFEFFF
	and r0, r1
	strh r0, [r4, #4]
_020197E6:
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	nop
_020197EC: .word _020F6298
_020197F0: .word 0xFFFFEFFF
	thumb_func_end sub_020196E8
	thumb_func_start sub_020197F4
sub_020197F4: ; 0x020197F4
	push {r4, lr}
	ldr r2, [r0, #4]
	lsl r3, r1, #4
	add r4, r2, r3
	mov r2, #6
	mov r3, #7
	ldrsb r2, [r4, r2]
	ldrsb r3, [r4, r3]
	bl sub_020196E8
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_020197F4
	thumb_func_start sub_0201980C
sub_0201980C: ; 0x0201980C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	ldr r2, [r0, #4]
	str r0, [sp, #0x10]
	lsl r0, r1, #4
	add r4, r2, r0
	mov r0, #1
	ldrh r1, [r4, #4]
	lsl r0, r0, #0xc
	orr r0, r1
	strh r0, [r4, #4]
	mov r0, #0xd
	ldrsb r6, [r4, r0]
	mov r0, #6
	ldrsb r0, [r4, r0]
	cmp r0, r6
	bge _020198F4
	mov r1, #0xf
	ldrsb r1, [r4, r1]
	str r1, [sp, #0x28]
	mov r1, #7
	ldrsb r3, [r4, r1]
	ldr r1, [sp, #0x28]
	cmp r3, r1
	bge _020198F4
	ldrh r2, [r4, #4]
	lsl r1, r2, #0x1a
	lsr r1, r1, #0x1a
	str r1, [sp, #0x24]
	add r7, r0, r1
	mov r1, #0xc
	ldrsb r1, [r4, r1]
	mov ip, r1
	cmp r7, r1
	blt _020198F4
	lsl r1, r2, #0x14
	lsr r1, r1, #0x1a
	str r1, [sp, #0x1c]
	ldr r1, [sp, #0x1c]
	str r3, [sp, #0x18]
	add r2, r3, r1
	mov r1, #0xe
	ldrsb r1, [r4, r1]
	str r1, [sp, #0x14]
	cmp r2, r1
	blt _020198F4
	ldr r1, [sp, #0x24]
	mov r5, ip
	lsl r1, r1, #0x18
	str r0, [sp, #0x20]
	asr r1, r1, #0x18
	cmp r0, r5
	bge _02019884
	mov r5, ip
	str r5, [sp, #0x20]
	mov r5, ip
	sub r0, r5, r0
	sub r0, r1, r0
	lsl r0, r0, #0x18
	asr r1, r0, #0x18
_02019884:
	cmp r7, r6
	blt _02019890
	sub r0, r7, r6
	sub r0, r1, r0
	lsl r0, r0, #0x18
	asr r1, r0, #0x18
_02019890:
	ldr r0, [sp, #0x1c]
	ldr r5, [sp, #0x14]
	lsl r0, r0, #0x18
	asr r0, r0, #0x18
	cmp r3, r5
	bge _020198AA
	add r3, r5, #0
	add r6, r5, #0
	ldr r5, [sp, #0x18]
	sub r5, r6, r5
	sub r0, r0, r5
	lsl r0, r0, #0x18
	asr r0, r0, #0x18
_020198AA:
	ldr r5, [sp, #0x28]
	cmp r2, r5
	blt _020198B8
	sub r2, r2, r5
	sub r0, r0, r2
	lsl r0, r0, #0x18
	asr r0, r0, #0x18
_020198B8:
	lsl r2, r3, #0x18
	lsr r2, r2, #0x18
	lsl r1, r1, #0x18
	str r2, [sp]
	lsr r1, r1, #0x18
	lsl r0, r0, #0x18
	str r1, [sp, #4]
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r3, [sp, #0x20]
	ldrb r1, [r4, #0xa]
	lsl r3, r3, #0x18
	ldr r0, [r0]
	mov r2, #0
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r2, [sp, #0x10]
	ldr r0, [sp, #0x10]
	ldrh r2, [r2, #0xa]
	ldrb r1, [r4, #0xa]
	ldr r0, [r0]
	lsl r2, r2, #0x11
	lsr r3, r2, #0xf
	ldr r2, _020198F8 ; =_020F6298
	ldr r2, [r2, r3]
	blx r2
_020198F4:
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_020198F8: .word _020F6298
	thumb_func_end sub_0201980C

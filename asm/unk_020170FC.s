	.include "asm/macros.inc"
	.include "unk_02016EDC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020170FC
sub_020170FC: ; 0x020170FC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r6, #0
	str r6, [r5, #0x18]
	add r7, r5, #0
	str r6, [r5, #0x44]
	add r4, r6, #0
	add r7, #0x7c
_0201710C:
	mov r0, #0x54
	add r1, r4, #0
	mul r1, r0
	add r0, r7, r1
	ldr r1, [r7, r1]
	cmp r1, #0
	beq _0201713A
	add r1, r0, #0
	add r1, #0x2d
	ldrb r1, [r1]
	cmp r1, #0
	bne _0201712C
	ldr r2, [r0, #0x50]
	add r1, r5, #0
	blx r2
	b _02017140
_0201712C:
	add r1, r0, #0
	add r1, #0x2d
	ldrb r1, [r1]
	add r0, #0x2d
	sub r1, r1, #1
	strb r1, [r0]
	b _02017140
_0201713A:
	add r0, r6, #1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
_02017140:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	cmp r4, #4
	blo _0201710C
	cmp r6, #4
	bne _02017154
	ldr r0, _020171E8 ; =0x000001CD
	mov r1, #0
	strb r1, [r5, r0]
_02017154:
	ldr r0, _020171E8 ; =0x000001CD
	ldrb r1, [r5, r0]
	cmp r1, #0
	beq _0201716A
	add r0, r5, #0
	bl sub_020179D4
	add r0, r5, #0
	bl sub_02017A1C
	pop {r3, r4, r5, r6, r7, pc}
_0201716A:
	add r0, r0, #2
	ldrb r0, [r5, r0]
	cmp r0, #0
	beq _02017182
	ldr r0, [r5]
	bl Pokepic_ResumePaletteFade
	cmp r0, #0
	bne _020171E4
	ldr r0, _020171EC ; =0x000001CF
	mov r1, #0
	strb r1, [r5, r0]
_02017182:
	add r6, r5, #0
	add r4, r5, #0
	ldr r7, _020171F0 ; =_020F61F8
	add r6, #0xc
	add r4, #0x44
_0201718C:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	ldr r0, [r5, #0xc]
	ldr r0, [r0]
	cmp r0, #0x22
	blo _0201719E
	bl GF_AssertFail
_0201719E:
	ldr r1, [r5, #0xc]
	add r0, r5, #0
	ldr r1, [r1]
	lsl r1, r1, #2
	ldr r1, [r7, r1]
	blx r1
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	bne _020171E4
	ldr r0, [r6]
	add r0, r0, #4
	str r0, [r6]
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _020171E4
	ldr r0, _020171E8 ; =0x000001CD
	ldrb r0, [r5, r0]
	cmp r0, #0
	beq _020171D2
	add r0, r5, #0
	bl sub_020179D4
	add r0, r5, #0
	bl sub_02017A1C
	pop {r3, r4, r5, r6, r7, pc}
_020171D2:
	mov r0, #1
	ldr r1, [r5, #0x44]
	lsl r0, r0, #8
	cmp r1, r0
	blt _0201718C
	bl GF_AssertFail
	mov r0, #1
	str r0, [r5, #0x1c]
_020171E4:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_020171E8: .word 0x000001CD
_020171EC: .word 0x000001CF
_020171F0: .word _020F61F8
	thumb_func_end sub_020170FC

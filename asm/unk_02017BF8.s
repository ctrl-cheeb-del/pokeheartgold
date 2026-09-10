	.include "asm/macros.inc"
	.include "unk_02016EDC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02017BF8
sub_02017BF8: ; 0x02017BF8
	push {r3, lr}
	sub r0, #0x23
	cmp r0, #4
	bhi _02017C70
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02017C0C: ; jump table
	.short _02017C16 - _02017C0C - 2 ; case 0
	.short _02017C28 - _02017C0C - 2 ; case 1
	.short _02017C3A - _02017C0C - 2 ; case 2
	.short _02017C4C - _02017C0C - 2 ; case 3
	.short _02017C5E - _02017C0C - 2 ; case 4
_02017C16:
	add r0, r1, #0
	add r0, #0x3c
	str r0, [r1, #0x24]
	add r0, r2, #0
	add r0, #0x68
	str r0, [r1, #0x28]
	ldr r0, [r2, #0x68]
	str r0, [r1, #0x30]
	pop {r3, pc}
_02017C28:
	add r0, r1, #0
	add r0, #0x40
	str r0, [r1, #0x24]
	add r0, r2, #0
	add r0, #0x6c
	str r0, [r1, #0x28]
	ldr r0, [r2, #0x6c]
	str r0, [r1, #0x30]
	pop {r3, pc}
_02017C3A:
	add r0, r1, #0
	add r0, #0x44
	str r0, [r1, #0x24]
	add r0, r2, #0
	add r0, #0x70
	str r0, [r1, #0x28]
	ldr r0, [r2, #0x70]
	str r0, [r1, #0x30]
	pop {r3, pc}
_02017C4C:
	add r0, r1, #0
	add r0, #0x48
	str r0, [r1, #0x24]
	add r0, r2, #0
	add r0, #0x74
	str r0, [r1, #0x28]
	ldr r0, [r2, #0x74]
	str r0, [r1, #0x30]
	pop {r3, pc}
_02017C5E:
	add r0, r1, #0
	add r0, #0x4c
	str r0, [r1, #0x24]
	add r0, r2, #0
	add r0, #0x78
	str r0, [r1, #0x28]
	ldr r0, [r2, #0x78]
	str r0, [r1, #0x30]
	pop {r3, pc}
_02017C70:
	bl GF_AssertFail
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end sub_02017BF8
	thumb_func_start sub_02017C78
sub_02017C78: ; 0x02017C78
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r1, #0
	lsl r1, r6, #0x18
	lsr r1, r1, #0x18
	add r5, r0, #0
	bl sub_02017220
	str r0, [sp, #4]
	ldr r1, [sp, #4]
	add r0, r5, #0
	add r1, #0x2c
	bl sub_02017280
	ldr r1, [sp, #4]
	add r0, r5, #0
	add r1, #0x2d
	bl sub_02017280
	mov r0, #0xc
	mul r0, r6
	ldr r1, _02017D14 ; =_020F61C0
	str r0, [sp]
	ldr r0, [r1, r0]
	mov r4, #0
	cmp r0, #0
	ble _02017CCE
	ldr r1, _02017D18 ; =_020F61BC
	ldr r0, [sp]
	add r6, r1, r0
	ldr r0, [sp, #4]
	add r7, r0, #4
_02017CB8:
	lsl r1, r4, #2
	add r0, r5, #0
	add r1, r7, r1
	bl sub_0201726C
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, [r6, #4]
	cmp r4, r0
	blt _02017CB8
_02017CCE:
	ldr r1, _02017D1C ; =_020F61C4
	ldr r0, [sp]
	add r2, r5, #0
	ldr r0, [r1, r0]
	lsl r1, r0, #2
	ldr r0, [sp, #4]
	add r0, r0, r1
	ldr r0, [r0, #4]
	ldr r1, [sp, #4]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl sub_02017BF8
	ldr r0, [sp, #4]
	add r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	bne _02017D00
	ldr r0, [sp, #4]
	add r1, r5, #0
	add r2, r0, #0
	ldr r2, [r2, #0x50]
	blx r2
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_02017D00:
	ldr r0, [sp, #4]
	add r0, #0x2d
	ldrb r0, [r0]
	sub r1, r0, #1
	ldr r0, [sp, #4]
	add r0, #0x2d
	str r0, [sp, #4]
	strb r1, [r0]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02017D14: .word _020F61C0
_02017D18: .word _020F61BC
_02017D1C: .word _020F61C4
	thumb_func_end sub_02017C78
	thumb_func_start sub_02017D20
sub_02017D20: ; 0x02017D20
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x10]
	add r0, r0, #1
	ldr r2, [r4, #0x14]
	mul r0, r1
	add r0, r2, r0
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	ldr r0, [r4, #4]
	sub r0, #0x1e
	cmp r0, #3
	bhi _02017DAC
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02017D48: ; jump table
	.short _02017D50 - _02017D48 - 2 ; case 0
	.short _02017D64 - _02017D48 - 2 ; case 1
	.short _02017D7C - _02017D48 - 2 ; case 2
	.short _02017D92 - _02017D48 - 2 ; case 3
_02017D50:
	asr r0, r1, #4
	lsl r1, r0, #2
	ldr r0, _02017DD4 ; =FX_SinCosTable_
	ldr r2, [r4, #0xc]
	ldrsh r0, [r0, r1]
	mul r0, r2
	asr r1, r0, #0xc
	ldr r0, [r4, #0x24]
	str r1, [r0]
	b _02017DB0
_02017D64:
	asr r1, r1, #4
	lsl r1, r1, #1
	add r1, r1, #1
	lsl r2, r1, #1
	ldr r1, _02017DD4 ; =FX_SinCosTable_
	ldr r0, [r4, #0xc]
	ldrsh r1, [r1, r2]
	mul r1, r0
	ldr r0, [r4, #0x24]
	asr r1, r1, #0xc
	str r1, [r0]
	b _02017DB0
_02017D7C:
	asr r0, r1, #4
	lsl r1, r0, #2
	ldr r0, _02017DD4 ; =FX_SinCosTable_
	ldr r2, [r4, #0xc]
	ldrsh r0, [r0, r1]
	mul r0, r2
	asr r0, r0, #0xc
	neg r1, r0
	ldr r0, [r4, #0x24]
	str r1, [r0]
	b _02017DB0
_02017D92:
	asr r1, r1, #4
	lsl r1, r1, #1
	add r1, r1, #1
	lsl r2, r1, #1
	ldr r1, _02017DD4 ; =FX_SinCosTable_
	ldr r0, [r4, #0xc]
	ldrsh r1, [r1, r2]
	mul r1, r0
	asr r0, r1, #0xc
	neg r1, r0
	ldr r0, [r4, #0x24]
	str r1, [r0]
	b _02017DB0
_02017DAC:
	bl GF_AssertFail
_02017DB0:
	add r0, r4, #0
	add r0, #0x2c
	ldrb r0, [r0]
	add r1, r4, #0
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	add r1, #0x30
	bl sub_02017BC8
	ldr r0, [r4, #0x1c]
	add r1, r0, #1
	str r1, [r4, #0x1c]
	ldr r0, [r4, #0x18]
	cmp r1, r0
	blt _02017DD2
	mov r0, #0
	str r0, [r4]
_02017DD2:
	pop {r4, pc}
	.balign 4, 0
_02017DD4: .word FX_SinCosTable_
	thumb_func_end sub_02017D20
	thumb_func_start sub_02017DD8
sub_02017DD8: ; 0x02017DD8
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x10]
	add r0, r0, #1
	mul r0, r1
	ldr r1, [r4, #0x18]
	bl _s32_div_f
	ldr r1, [r4, #0x14]
	add r0, r1, r0
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	ldr r0, [r4, #4]
	sub r0, #0x1e
	cmp r0, #3
	bhi _02017E6A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02017E06: ; jump table
	.short _02017E0E - _02017E06 - 2 ; case 0
	.short _02017E22 - _02017E06 - 2 ; case 1
	.short _02017E3A - _02017E06 - 2 ; case 2
	.short _02017E50 - _02017E06 - 2 ; case 3
_02017E0E:
	asr r0, r1, #4
	lsl r1, r0, #2
	ldr r0, _02017E94 ; =FX_SinCosTable_
	ldr r2, [r4, #0xc]
	ldrsh r0, [r0, r1]
	mul r0, r2
	asr r1, r0, #0xc
	ldr r0, [r4, #0x24]
	str r1, [r0]
	b _02017E6E
_02017E22:
	asr r1, r1, #4
	lsl r1, r1, #1
	add r1, r1, #1
	lsl r2, r1, #1
	ldr r1, _02017E94 ; =FX_SinCosTable_
	ldr r0, [r4, #0xc]
	ldrsh r1, [r1, r2]
	mul r1, r0
	ldr r0, [r4, #0x24]
	asr r1, r1, #0xc
	str r1, [r0]
	b _02017E6E
_02017E3A:
	asr r0, r1, #4
	lsl r1, r0, #2
	ldr r0, _02017E94 ; =FX_SinCosTable_
	ldr r2, [r4, #0xc]
	ldrsh r0, [r0, r1]
	mul r0, r2
	asr r0, r0, #0xc
	neg r1, r0
	ldr r0, [r4, #0x24]
	str r1, [r0]
	b _02017E6E
_02017E50:
	asr r1, r1, #4
	lsl r1, r1, #1
	add r1, r1, #1
	lsl r2, r1, #1
	ldr r1, _02017E94 ; =FX_SinCosTable_
	ldr r0, [r4, #0xc]
	ldrsh r1, [r1, r2]
	mul r1, r0
	asr r0, r1, #0xc
	neg r1, r0
	ldr r0, [r4, #0x24]
	str r1, [r0]
	b _02017E6E
_02017E6A:
	bl GF_AssertFail
_02017E6E:
	add r0, r4, #0
	add r0, #0x2c
	ldrb r0, [r0]
	add r1, r4, #0
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	add r1, #0x30
	bl sub_02017BC8
	ldr r0, [r4, #0x1c]
	add r1, r0, #1
	str r1, [r4, #0x1c]
	ldr r0, [r4, #0x18]
	cmp r1, r0
	blt _02017E90
	mov r0, #0
	str r0, [r4]
_02017E90:
	pop {r4, pc}
	nop
_02017E94: .word FX_SinCosTable_
	thumb_func_end sub_02017DD8
	thumb_func_start sub_02017E98
sub_02017E98: ; 0x02017E98
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x24]
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x14]
	ldr r5, [r4, #8]
	mul r2, r3
	ldr r0, [r1]
	add r2, r5, r2
	add r0, r0, r2
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x2c
	add r1, r4, #0
	ldrb r0, [r0]
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	add r1, #0x30
	bl sub_02017BC8
	ldr r0, [r4, #0x14]
	add r1, r0, #1
	str r1, [r4, #0x14]
	ldr r0, [r4, #0x10]
	cmp r1, r0
	blt _02017ED0
	mov r0, #0
	str r0, [r4]
_02017ED0:
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_02017E98
	thumb_func_start sub_02017ED4
sub_02017ED4: ; 0x02017ED4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x10]
	add r1, r0, #1
	ldr r0, [r4, #8]
	mul r0, r1
	ldr r1, [r4, #0xc]
	bl _s32_div_f
	ldr r1, [r4, #0x24]
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x2c
	add r1, r4, #0
	ldrb r0, [r0]
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	add r1, #0x30
	bl sub_02017BC8
	ldr r0, [r4, #0x10]
	add r1, r0, #1
	str r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	cmp r1, r0
	blt _02017F0C
	mov r0, #0
	str r0, [r4]
_02017F0C:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02017ED4
	thumb_func_start sub_02017F10
sub_02017F10: ; 0x02017F10
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #8]
	mul r0, r1
	ldr r1, [r4, #0x24]
	add r2, r2, r0
	ldr r0, [r1]
	add r0, r0, r2
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _02017F34
	cmp r0, #0x1a
	bne _02017F5A
_02017F34:
	cmp r2, #0
	ldr r2, [r4, #0x10]
	bge _02017F4A
	ldr r1, [r4, #0x24]
	ldr r0, [r1]
	cmp r0, r2
	bgt _02017F90
	str r2, [r1]
	mov r0, #0
	str r0, [r4]
	b _02017F90
_02017F4A:
	ldr r1, [r4, #0x24]
	ldr r0, [r1]
	cmp r0, r2
	blt _02017F90
	str r2, [r1]
	mov r0, #0
	str r0, [r4]
	b _02017F90
_02017F5A:
	cmp r0, #0x19
	bne _02017F8C
	ldr r1, [r4, #0x24]
	ldr r3, [r4, #0x30]
	ldr r0, [r1]
	add r3, r3, r0
	cmp r2, #0
	ldr r2, [r4, #0x10]
	bge _02017F7C
	cmp r3, r2
	bgt _02017F90
	sub r2, r2, r3
	add r0, r0, r2
	str r0, [r1]
	mov r0, #0
	str r0, [r4]
	b _02017F90
_02017F7C:
	cmp r3, r2
	blt _02017F90
	sub r2, r3, r2
	sub r0, r0, r2
	str r0, [r1]
	mov r0, #0
	str r0, [r4]
	b _02017F90
_02017F8C:
	bl GF_AssertFail
_02017F90:
	add r0, r4, #0
	add r0, #0x2c
	ldrb r0, [r0]
	add r1, r4, #0
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	add r1, #0x30
	bl sub_02017BC8
	ldr r0, [r4, #0x14]
	add r0, r0, #1
	str r0, [r4, #0x14]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02017F10

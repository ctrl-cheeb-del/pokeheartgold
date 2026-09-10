	.include "asm/macros.inc"
	.include "unk_02016EDC.inc"
	.include "global.inc"
	.text
	.public sub_02017808
	.public sub_0201783C
	.public sub_02017874
	.public sub_020178BC
	.public sub_0201790C
	.public sub_020179D4
	.public sub_02017A1C
	.public sub_02017A84
	.public sub_02017AD8
	.public sub_02017AEC
	.public sub_02017B2C
	thumb_func_start sub_02017808
sub_02017808: ; 0x02017808
	push {r3, r4, lr}
	sub sp, #0xc
	add r1, sp, #0
	add r2, sp, #8
	add r3, sp, #4
	add r4, r0, #0
	bl sub_020173C8
	ldr r0, [sp, #8]
	ldr r2, [sp, #4]
	asr r0, r0, #4
	lsl r1, r0, #2
	ldr r0, _02017838 ; =FX_SinCosTable_
	ldrsh r0, [r0, r1]
	mul r0, r2
	asr r1, r0, #0xc
	add r0, sp, #0
	ldrb r0, [r0]
	lsl r0, r0, #2
	add r0, r4, r0
	str r1, [r0, #0x24]
	add sp, #0xc
	pop {r3, r4, pc}
	nop
_02017838: .word FX_SinCosTable_
	thumb_func_end sub_02017808
	thumb_func_start sub_0201783C
sub_0201783C: ; 0x0201783C
	push {r3, r4, lr}
	sub sp, #0xc
	add r1, sp, #0
	add r2, sp, #8
	add r3, sp, #4
	add r4, r0, #0
	bl sub_020173C8
	ldr r1, [sp, #8]
	ldr r0, [sp, #4]
	asr r1, r1, #4
	lsl r1, r1, #1
	add r1, r1, #1
	lsl r2, r1, #1
	ldr r1, _02017870 ; =FX_SinCosTable_
	ldrsh r1, [r1, r2]
	mul r1, r0
	add r0, sp, #0
	ldrb r0, [r0]
	asr r1, r1, #0xc
	lsl r0, r0, #2
	add r0, r4, r0
	str r1, [r0, #0x24]
	add sp, #0xc
	pop {r3, r4, pc}
	nop
_02017870: .word FX_SinCosTable_
	thumb_func_end sub_0201783C
	thumb_func_start sub_02017874
sub_02017874: ; 0x02017874
	push {r3, r4, lr}
	sub sp, #4
	add r1, sp, #0
	add r4, r0, #0
	add r1, #1
	bl sub_02017294
	add r0, r4, #0
	add r1, sp, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r1, [r0]
	cmp r1, #8
	bne _020178A0
	ldrb r0, [r0, #1]
	add sp, #4
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #0x24]
	str r0, [r4, #0x60]
	pop {r3, r4, pc}
_020178A0:
	cmp r1, #9
	bne _020178B2
	ldrb r0, [r0, #1]
	add sp, #4
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #0x24]
	str r0, [r4, #0x64]
	pop {r3, r4, pc}
_020178B2:
	bl GF_AssertFail
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end sub_02017874
	thumb_func_start sub_020178BC
sub_020178BC: ; 0x020178BC
	push {r3, r4, lr}
	sub sp, #4
	add r1, sp, #0
	add r4, r0, #0
	add r1, #1
	bl sub_02017294
	add r0, r4, #0
	add r1, sp, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r1, [r0]
	cmp r1, #8
	bne _020178EC
	ldrb r0, [r0, #1]
	ldr r1, [r4, #0x60]
	add sp, #4
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #0x24]
	add r0, r1, r0
	str r0, [r4, #0x60]
	pop {r3, r4, pc}
_020178EC:
	cmp r1, #9
	bne _02017902
	ldrb r0, [r0, #1]
	ldr r1, [r4, #0x64]
	add sp, #4
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #0x24]
	add r0, r1, r0
	str r0, [r4, #0x64]
	pop {r3, r4, pc}
_02017902:
	bl GF_AssertFail
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end sub_020178BC
	thumb_func_start sub_0201790C
sub_0201790C: ; 0x0201790C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r1, sp, #0
	add r1, #3
	add r5, r0, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0, #3]
	cmp r0, #8
	bne _02017928
	add r4, r5, #0
	add r4, #0x60
	b _02017968
_02017928:
	cmp r0, #9
	bne _02017932
	add r4, r5, #0
	add r4, #0x64
	b _02017968
_02017932:
	cmp r0, #0xa
	bne _0201793C
	add r4, r5, #0
	add r4, #0x68
	b _02017968
_0201793C:
	cmp r0, #0xb
	bne _02017946
	add r4, r5, #0
	add r4, #0x6c
	b _02017968
_02017946:
	cmp r0, #0xc
	bne _02017950
	add r4, r5, #0
	add r4, #0x70
	b _02017968
_02017950:
	cmp r0, #0xd
	bne _0201795A
	add r4, r5, #0
	add r4, #0x74
	b _02017968
_0201795A:
	cmp r0, #0xe
	bne _02017964
	add r4, r5, #0
	add r4, #0x78
	b _02017968
_02017964:
	bl GF_AssertFail
_02017968:
	add r1, sp, #0
	add r0, r5, #0
	add r1, #1
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0, #1]
	cmp r0, #0x14
	bne _02017984
	add r0, r5, #0
	add r1, sp, #4
	bl sub_0201726C
	b _020179A4
_02017984:
	cmp r0, #0x15
	bne _020179A0
	add r1, sp, #0
	add r0, r5, #0
	add r1, #2
	bl sub_02017294
	add r0, sp, #0
	ldrb r0, [r0, #2]
	lsl r0, r0, #2
	add r0, r5, r0
	ldr r0, [r0, #0x24]
	str r0, [sp, #4]
	b _020179A4
_020179A0:
	bl GF_AssertFail
_020179A4:
	add r0, r5, #0
	add r1, sp, #0
	bl sub_02017280
	add r0, sp, #0
	ldrb r0, [r0]
	cmp r0, #0x16
	bne _020179BC
	ldr r0, [sp, #4]
	add sp, #8
	str r0, [r4]
	pop {r3, r4, r5, pc}
_020179BC:
	cmp r0, #0x17
	bne _020179CC
	ldr r0, [sp, #4]
	ldr r1, [r4]
	add sp, #8
	add r0, r1, r0
	str r0, [r4]
	pop {r3, r4, r5, pc}
_020179CC:
	bl GF_AssertFail
	add sp, #8
	pop {r3, r4, r5, pc}
	thumb_func_end sub_0201790C
	thumb_func_start sub_020179D4
sub_020179D4: ; 0x020179D4
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r0, #0x73
	lsl r0, r0, #2
	ldrb r0, [r4, r0]
	cmp r0, #0
	ldr r0, [r4]
	beq _020179F6
	ldr r3, [r4, #0x60]
	ldr r2, [r4, #0x68]
	ldr r5, [r4, #0x58]
	add r2, r3, r2
	mov r1, #0
	sub r2, r5, r2
	bl Pokepic_SetAttr
	b _02017A06
_020179F6:
	ldr r3, [r4, #0x58]
	ldr r2, [r4, #0x60]
	ldr r5, [r4, #0x68]
	add r2, r3, r2
	mov r1, #0
	add r2, r5, r2
	bl Pokepic_SetAttr
_02017A06:
	ldr r3, [r4, #0x5c]
	ldr r2, [r4, #0x64]
	ldr r5, [r4, #0x6c]
	add r2, r3, r2
	ldr r0, [r4]
	mov r1, #1
	add r2, r5, r2
	bl Pokepic_SetAttr
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_020179D4
	thumb_func_start sub_02017A1C
sub_02017A1C: ; 0x02017A1C
	push {r4, lr}
	add r4, r0, #0
	mov r1, #0xc
	add r2, r1, #0
	ldr r3, [r4, #0x70]
	add r2, #0xf4
	ldr r0, [r4]
	add r2, r3, r2
	bl Pokepic_SetAttr
	mov r1, #0xd
	add r2, r1, #0
	ldr r3, [r4, #0x74]
	add r2, #0xf3
	ldr r0, [r4]
	add r2, r3, r2
	bl Pokepic_SetAttr
	ldr r2, [r4, #0x78]
	ldr r0, [r4]
	lsl r2, r2, #0x10
	mov r1, #9
	lsr r2, r2, #0x10
	bl Pokepic_SetAttr
	ldr r0, _02017A80 ; =0x000001CE
	ldrb r0, [r4, r0]
	cmp r0, #0x1b
	bne _02017A64
	ldr r0, [r4, #0x74]
	cmp r0, #0
	bge _02017A7E
	add r0, r4, #0
	bl sub_02017488
	pop {r4, pc}
_02017A64:
	cmp r0, #0x1d
	bne _02017A76
	ldr r0, [r4, #0x74]
	cmp r0, #0
	beq _02017A7E
	add r0, r4, #0
	bl sub_02017488
	pop {r4, pc}
_02017A76:
	cmp r0, #0x1c
	beq _02017A7E
	bl GF_AssertFail
_02017A7E:
	pop {r4, pc}
	.balign 4, 0
_02017A80: .word 0x000001CE
	thumb_func_end sub_02017A1C
	thumb_func_start sub_02017A84
sub_02017A84: ; 0x02017A84
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	add r1, sp, #0
	bl sub_02017294
	ldr r0, [r4, #0xc]
	add r0, r0, #4
	str r0, [r4, #0xc]
	bl sub_02017214
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #8
	beq _02017AA6
	cmp r0, #0xa
	bne _02017AB6
_02017AA6:
	add r0, sp, #0
	ldrb r0, [r0]
	add sp, #4
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #0x24]
	str r0, [r4, #0x68]
	pop {r3, r4, pc}
_02017AB6:
	cmp r0, #9
	beq _02017ABE
	cmp r0, #0xb
	bne _02017ACE
_02017ABE:
	add r0, sp, #0
	ldrb r0, [r0]
	add sp, #4
	lsl r0, r0, #2
	add r0, r4, r0
	ldr r0, [r0, #0x24]
	str r0, [r4, #0x6c]
	pop {r3, r4, pc}
_02017ACE:
	bl GF_AssertFail
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end sub_02017A84
	thumb_func_start sub_02017AD8
sub_02017AD8: ; 0x02017AD8
	push {r4, lr}
	add r4, r0, #0
	add r1, r4, #0
	add r1, #0x54
	bl sub_0201726C
	mov r0, #1
	str r0, [r4, #0x18]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02017AD8
	thumb_func_start sub_02017AEC
sub_02017AEC: ; 0x02017AEC
	push {r3, r4, lr}
	sub sp, #0xc
	add r1, sp, #4
	add r1, #2
	add r4, r0, #0
	bl sub_02017280
	add r1, sp, #4
	add r0, r4, #0
	add r1, #1
	bl sub_02017280
	add r0, r4, #0
	add r1, sp, #4
	bl sub_02017280
	add r0, r4, #0
	add r1, sp, #8
	bl sub_0201726C
	ldr r0, [sp, #8]
	add r3, sp, #4
	str r0, [sp]
	ldrb r1, [r3, #2]
	ldrb r2, [r3, #1]
	ldrb r3, [r3]
	ldr r0, [r4]
	bl Pokepic_StartPaletteFade
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end sub_02017AEC
	thumb_func_start sub_02017B2C
sub_02017B2C: ; 0x02017B2C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	bl Pokepic_ResumePaletteFade
	cmp r0, #0
	beq _02017B42
	ldr r0, _02017B44 ; =0x000001CF
	mov r1, #1
	strb r1, [r4, r0]
	str r1, [r4, #0x18]
_02017B42:
	pop {r4, pc}
	.balign 4, 0
_02017B44: .word 0x000001CF
	thumb_func_end sub_02017B2C

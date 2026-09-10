	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02059EBC
sub_02059EBC: ; 0x02059EBC
	push {r4, lr}
	add r4, r0, #0
	bl sub_02037FCC
	cmp r0, #0
	beq _02059ED8
	ldr r0, _02059F24 ; =_021D41CC
	mov r2, #0
	str r2, [r0]
	ldr r1, _02059F28 ; =sub_02059F78
	add r0, r4, #0
	bl sub_0205A034
	pop {r4, pc}
_02059ED8:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _02059F22
	mov r0, #2
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x20]
	cmp r0, #1
	bne _02059F08
	ldr r0, [r4, #0x30]
	cmp r0, #5
	bne _02059EF6
	ldr r0, [r4, #0x18]
	bl sub_0203894C
	b _02059F18
_02059EF6:
	cmp r0, #6
	ldr r0, [r4, #0x18]
	bne _02059F02
	bl sub_0203898C
	b _02059F18
_02059F02:
	bl sub_02037F64
	b _02059F18
_02059F08:
	cmp r0, #2
	bne _02059F18
	mov r0, #0
	bl sub_0208F814
	ldr r0, [r4, #0x18]
	bl sub_02038918
_02059F18:
	ldr r1, _02059F2C ; =sub_0205A0B4
	add r0, r4, #0
	mov r2, #0xc
	bl sub_0205A034
_02059F22:
	pop {r4, pc}
	.balign 4, 0
_02059F24: .word _021D41CC
_02059F28: .word sub_02059F78
_02059F2C: .word sub_0205A0B4
	thumb_func_end sub_02059EBC

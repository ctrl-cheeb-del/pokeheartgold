	.include "asm/macros.inc"
	.include "unk_02056D7C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205779C
sub_0205779C: ; 0x0205779C
	push {r3, r4, r5, lr}
	ldrb r1, [r2]
	mov r0, #0xf
	add r3, r1, #0
	and r3, r0
	ldr r0, _02057814 ; =_021D41C4
	ldr r1, [r0]
	cmp r1, #0
	beq _02057810
	ldrb r4, [r2, #2]
	add r1, #0x74
	lsl r0, r3, #3
	add r1, r1, r0
	mov r0, #0x80
	tst r0, r4
	beq _020577C0
	mov r0, #1
	b _020577C2
_020577C0:
	mov r0, #0
_020577C2:
	strb r0, [r1, #7]
	mov r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	ldrh r4, [r1]
	ldrb r0, [r2, #1]
	add r0, r4, r0
	strh r0, [r1]
	ldrb r4, [r2, #2]
	ldrh r0, [r1]
	lsl r5, r4, #8
	mov r4, #1
	lsl r4, r4, #8
	and r5, r4
	add r0, r0, r5
	strh r0, [r1]
	ldrh r5, [r1, #2]
	ldrb r0, [r2, #3]
	add r0, r5, r0
	strh r0, [r1, #2]
	ldrb r5, [r2, #2]
	ldrh r0, [r1, #2]
	lsl r5, r5, #7
	and r4, r5
	add r0, r0, r4
	strh r0, [r1, #2]
	ldrb r0, [r2]
	asr r4, r0, #4
	mov r0, #3
	and r4, r0
	strb r4, [r1, #4]
	ldrb r2, [r2]
	asr r2, r2, #6
	and r0, r2
	strb r0, [r1, #5]
	lsl r0, r3, #0x18
	lsr r0, r0, #0x18
	bl sub_02057184
_02057810:
	pop {r3, r4, r5, pc}
	nop
_02057814: .word _021D41C4
	thumb_func_end sub_0205779C
	thumb_func_start sub_02057818
sub_02057818: ; 0x02057818
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	ldr r0, _02057A00 ; =_021D41C4
	lsl r1, r5, #3
	ldr r0, [r0]
	add r2, r0, #0
	add r2, #0x74
	add r6, r2, r1
	add r2, r0, #0
	add r2, #0xdc
	ldrb r1, [r2, r5]
	cmp r1, #0
	beq _0205783C
	sub r0, r1, #1
	add sp, #0x1c
	strb r0, [r2, r5]
	pop {r4, r5, r6, r7, pc}
_0205783C:
	ldrh r2, [r6]
	ldr r1, _02057A04 ; =0x0000FFFF
	cmp r2, r1
	beq _02057866
	ldrh r2, [r6, #2]
	cmp r2, r1
	beq _02057866
	add r0, #0xee
	ldrb r0, [r0]
	cmp r0, #0
	bne _02057866
	bl sub_0203769C
	cmp r5, r0
	bne _02057868
	ldr r0, _02057A00 ; =_021D41C4
	ldr r0, [r0]
	add r0, #0xf1
	ldrb r0, [r0]
	cmp r0, #0
	bne _02057868
_02057866:
	b _020579FC
_02057868:
	ldr r0, _02057A00 ; =_021D41C4
	ldr r1, [r0]
	lsl r0, r5, #2
	add r0, r1, r0
	ldr r0, [r0, #4]
	str r0, [sp, #0x18]
	cmp r0, #0
	bne _0205787A
	b _020579FC
_0205787A:
	bl PlayerAvatar_GetXCoord
	ldrh r1, [r6]
	sub r0, r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x18]
	bl PlayerAvatar_GetZCoord
	ldrh r1, [r6, #2]
	sub r7, r0, r1
	ldr r0, [sp, #0x18]
	bl PlayerAvatar_GetFacingDirection
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	cmp r0, #0
	bne _020578A4
	cmp r7, #0
	bne _020578A4
	mov r4, #0
	b _020578CE
_020578A4:
	ldr r0, [sp, #0x10]
	bl abs
	add r4, r0, #0
	add r0, r7, #0
	bl abs
	cmp r4, r0
	ble _020578C4
	ldr r0, [sp, #0x10]
	cmp r0, #0
	ble _020578C0
	mov r4, #0x20
	b _020578CE
_020578C0:
	mov r4, #0x10
	b _020578CE
_020578C4:
	cmp r7, #0
	ble _020578CC
	mov r4, #0x40
	b _020578CE
_020578CC:
	mov r4, #0x80
_020578CE:
	add r0, r7, #0
	bl abs
	ldr r0, [sp, #0x10]
	bl abs
	ldrb r0, [r6, #5]
	mov r7, #0xff
	str r0, [sp, #0x14]
	cmp r0, #3
	bhi _02057916
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_020578F0: ; jump table
	.short _020578F8 - _020578F0 - 2 ; case 0
	.short _020578FE - _020578F0 - 2 ; case 1
	.short _0205790C - _020578F0 - 2 ; case 2
	.short _02057912 - _020578F0 - 2 ; case 3
_020578F8:
	mov r0, #5
	str r0, [sp, #8]
	b _02057916
_020578FE:
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #2
	orr r0, r4
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	b _02057916
_0205790C:
	mov r0, #2
	str r0, [sp, #8]
	b _02057916
_02057912:
	mov r0, #1
	str r0, [sp, #8]
_02057916:
	ldr r0, _02057A00 ; =_021D41C4
	ldr r0, [r0]
	add r0, #0xf0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0205793C
	bl sub_0203769C
	cmp r5, r0
	bne _0205793C
	ldr r0, _02057A00 ; =_021D41C4
	ldr r1, [r0]
	add r0, r1, #0
	add r0, #0xf0
	ldrb r0, [r0]
	add r1, #0xf0
	sub r0, r0, #1
	strb r0, [r1]
	b _020579A8
_0205793C:
	mov r0, #2
	add r1, r4, #0
	bic r1, r0
	bne _0205797A
	ldrb r0, [r6, #7]
	cmp r0, #0
	beq _0205797A
	mov r0, #3
	str r0, [sp, #0x14]
	mov r0, #4
	ldrsb r0, [r6, r0]
	cmp r0, #3
	bhi _0205796E
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02057962: ; jump table
	.short _0205796A - _02057962 - 2 ; case 0
	.short _0205796E - _02057962 - 2 ; case 1
	.short _02057972 - _02057962 - 2 ; case 2
	.short _02057976 - _02057962 - 2 ; case 3
_0205796A:
	mov r7, #0x1c
	b _020579A8
_0205796E:
	mov r7, #0x1d
	b _020579A8
_02057972:
	mov r7, #0x1e
	b _020579A8
_02057976:
	mov r7, #0x1f
	b _020579A8
_0205797A:
	cmp r1, #0
	bne _02057992
	mov r0, #4
	ldrsb r0, [r6, r0]
	ldr r1, [sp, #0xc]
	cmp r0, r1
	beq _02057992
	mov r1, #0x24
	bl sub_0206234C
	add r7, r0, #0
	b _020579A8
_02057992:
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	ldr r3, [sp, #8]
	add r1, r4, #0
	add r2, r4, #0
	bl sub_0205DF0C
	add r7, r0, #0
_020579A8:
	ldr r0, [sp, #0x18]
	bl sub_0205DFC8
	cmp r0, #0
	bne _020579BC
	ldr r0, [sp, #0x18]
	bl sub_0205DE38
	cmp r0, #0
	beq _020579FC
_020579BC:
	cmp r7, #0xff
	beq _020579FC
	ldr r0, [sp, #0x18]
	add r1, r7, #0
	bl sub_0205DFD4
	mov r0, #2
	bic r4, r0
	beq _020579FC
	ldr r0, _02057A00 ; =_021D41C4
	ldr r0, [r0]
	add r0, r0, r5
	add r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _020579EC
	ldr r0, [sp, #0x14]
	bl sub_02057524
	ldr r1, _02057A00 ; =_021D41C4
	ldr r1, [r1]
	add r1, r1, r5
	add r1, #0xdc
	strb r0, [r1]
_020579EC:
	ldr r0, _02057A00 ; =_021D41C4
	ldr r1, [r0]
	add r1, #0xdc
	ldrb r0, [r1, r5]
	cmp r0, #0
	beq _020579FC
	sub r0, r0, #1
	strb r0, [r1, r5]
_020579FC:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02057A00: .word _021D41C4
_02057A04: .word 0x0000FFFF
	thumb_func_end sub_02057818

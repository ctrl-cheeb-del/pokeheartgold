	.include "asm/macros.inc"
	.include "unk_02034B0C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0203540C
sub_0203540C: ; 0x0203540C
	push {r4, r5, r6, lr}
	sub sp, #8
	add r4, r0, #0
	bl sub_02033298
	add r5, r0, #0
	bl sub_020347CC
	add r6, r0, #0
	bl sub_020353B8
	bl sub_020338F4
	cmp r0, #0
	bne _0203544A
	bl sub_0203567C
	cmp r0, #0
	bne _0203544A
	ldr r0, _020355AC ; =_021D4134
	ldr r3, _020355B0 ; =0x00000D95
	ldr r1, [r0, #8]
	ldrb r0, [r1, r3]
	lsl r2, r0, #0x1d
	lsr r2, r2, #0x1f
	beq _0203544A
	mov r2, #1
	bic r0, r2
	mov r2, #1
	orr r0, r2
	strb r0, [r1, r3]
_0203544A:
	ldr r0, _020355AC ; =_021D4134
	ldr r3, _020355B4 ; =0x00000D8E
	ldr r2, [r0, #8]
	ldr r0, _020355B8 ; =0x0000FFFF
	ldrh r1, [r2, r3]
	cmp r1, r0
	bne _0203545A
	strh r4, [r2, r3]
_0203545A:
	ldr r0, _020355AC ; =_021D4134
	ldr r3, _020355B0 ; =0x00000D95
	ldr r1, [r0, #8]
	ldrb r0, [r1, r3]
	lsl r2, r0, #0x1e
	lsr r2, r2, #0x1f
	beq _02035490
	sub r2, r3, #7
	ldrh r2, [r1, r2]
	cmp r2, r4
	bls _0203547A
	mov r2, #1
	bic r0, r2
	mov r2, #1
	orr r0, r2
	strb r0, [r1, r3]
_0203547A:
	cmp r6, #0
	beq _02035490
	ldr r0, _020355AC ; =_021D4134
	ldr r2, _020355B0 ; =0x00000D95
	ldr r0, [r0, #8]
	mov r1, #1
	ldrb r3, [r0, r2]
	bic r3, r1
	mov r1, #1
	orr r1, r3
	strb r1, [r0, r2]
_02035490:
	bl sub_020332AC
	cmp r0, #0x19
	bne _0203549E
	mov r0, #0
	bl sub_020399DC
_0203549E:
	cmp r5, #9
	bls _020354A4
	b _020355A6
_020354A4:
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_020354B0: ; jump table
	.short _020354C4 - _020354B0 - 2 ; case 0
	.short _020354E4 - _020354B0 - 2 ; case 1
	.short _020355A6 - _020354B0 - 2 ; case 2
	.short _020355A6 - _020354B0 - 2 ; case 3
	.short _020355A6 - _020354B0 - 2 ; case 4
	.short _020355A6 - _020354B0 - 2 ; case 5
	.short _020355A6 - _020354B0 - 2 ; case 6
	.short _02035528 - _020354B0 - 2 ; case 7
	.short _0203550E - _020354B0 - 2 ; case 8
	.short _0203550E - _020354B0 - 2 ; case 9
_020354C4:
	ldr r0, _020355AC ; =_021D4134
	ldr r2, [r0, #8]
	ldr r0, _020355BC ; =0x00000D92
	ldrb r1, [r2, r0]
	cmp r1, #1
	bne _020354D8
	bl sub_020350D4
	add sp, #8
	pop {r4, r5, r6, pc}
_020354D8:
	cmp r1, #2
	bne _020355A6
	mov r1, #3
	strb r1, [r2, r0]
	add sp, #8
	pop {r4, r5, r6, pc}
_020354E4:
	ldr r0, _020355AC ; =_021D4134
	ldr r1, [r0, #8]
	ldr r0, _020355BC ; =0x00000D92
	ldrb r0, [r1, r0]
	cmp r0, #1
	bne _020354F8
	bl sub_020338D0
	cmp r0, #0
	bne _020355A6
_020354F8:
	ldr r0, _020355AC ; =_021D4134
	ldr r1, [r0, #8]
	ldr r0, _020355BC ; =0x00000D92
	ldrb r0, [r1, r0]
	cmp r0, #2
	bne _020355A6
	bl sub_020338D0
	add sp, #8
	cmp r0, #0
	pop {r4, r5, r6, pc}
_0203550E:
	ldr r0, _020355AC ; =_021D4134
	ldr r3, [r0, #8]
	cmp r3, #0
	beq _020355A6
	ldr r1, _020355B0 ; =0x00000D95
	mov r0, #1
	ldrb r2, [r3, r1]
	add sp, #8
	bic r2, r0
	mov r0, #1
	orr r0, r2
	strb r0, [r3, r1]
	pop {r4, r5, r6, pc}
_02035528:
	bl sub_02033468
	ldr r3, _020355AC ; =_021D4134
	ldr r2, _020355C0 ; =0x00000D91
	ldr r4, [r3, #8]
	ldrb r1, [r4, r2]
	cmp r1, #0
	bne _02035544
	sub r1, r2, #5
	strh r0, [r4, r1]
	ldr r0, [r3, #8]
	mov r1, #5
	strb r1, [r0, r2]
	b _02035548
_02035544:
	sub r0, r1, #1
	strb r0, [r4, r2]
_02035548:
	ldr r0, _020355AC ; =_021D4134
	ldr r1, [r0, #8]
	ldr r0, _020355C4 ; =0x00000D8C
	ldrh r5, [r1, r0]
	add r0, #9
	ldrb r0, [r1, r0]
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1f
	beq _02035562
	bl WM_GetNextTgid
	ldr r1, _020355AC ; =_021D4134
	strh r0, [r1]
_02035562:
	bl sub_020352D8
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r4, r0, #0
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02035724
	str r0, [sp]
	ldr r1, _020355AC ; =_021D4134
	ldr r0, _020355B0 ; =0x00000D95
	ldr r2, [r1, #8]
	add r3, r4, #0
	ldrb r0, [r2, r0]
	add r2, r5, #0
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1f
	str r0, [sp, #4]
	ldrh r1, [r1]
	mov r0, #0
	bl sub_02033668
	ldr r0, _020355AC ; =_021D4134
	ldr r1, [r0, #8]
	mov r0, #0xd9
	lsl r0, r0, #4
	strb r5, [r1, r0]
_020355A6:
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_020355AC: .word _021D4134
_020355B0: .word 0x00000D95
_020355B4: .word 0x00000D8E
_020355B8: .word 0x0000FFFF
_020355BC: .word 0x00000D92
_020355C0: .word 0x00000D91
_020355C4: .word 0x00000D8C
	thumb_func_end sub_0203540C

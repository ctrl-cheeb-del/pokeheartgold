#include "config.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_12_022378C0.inc"
	.include "global.inc"

	.text
	.public _0226BFD8
	.public ov12_02237D00
	.public ov12_02237ED0
	.public ov12_02237F18
	.public ov12_02238358
	.public ov12_0223843C
	.public ov12_022387AC
	.public ov12_022389B8
	.public ov12_02238A68
	.public ov12_02239664
	.public ov12_02239730
	.public ov12_022397E4
	.public ov12_02239854
	.public ov12_022399D4
	.public ov12_02239C28
	.public ov12_0223A0D4
	.public ov12_0223A260
	.public ov12_0223A3F0
	.public ov12_0223A664
	.public ov12_0226BFDC
	.public ov12_0226BFE0
	.public ov12_0226BFE8
	.public ov12_0226BFF8
	.public ov12_0226C008
	.public ov12_0226C018
	.public ov12_0226C02C
	.public ov12_0226C044
	.public ov12_0226C060
	.public ov12_0226C080
	.public ov12_0226C0A8
	.public ov12_0226C0D0
	.public ov12_0226C0F8
	.public ov12_0226C120
	.public ov12_0226C174
	.public ov12_0226C1C8
	.public ov12_0226C2DC

	.public ov12_02238A30
	.public ov12_02238A64
	.public ov12_022395BC
	.public ov12_02239644
	.public ov12_022396E8
	.public ov12_022396F0
	.public ov12_02239810
	.public ov12_0223998C
	.public ov12_022399BC
	.public ov12_0223A088
	.public ov12_0223A218
	.public ov12_0223A3A8
	.public ov12_0223A5E4
	.public ov12_0223A620
	.public ov12_0223A7A0

	thumb_func_start ov12_0223A664
ov12_0223A664: ; 0x0223A664
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	ldr r2, _0223A798 ; =0x0000240C
	str r0, [sp]
	ldr r3, [r0, r2]
	mov r0, #0x10
	tst r0, r3
	beq _0223A680
	ldr r0, [sp]
	mov r1, #1
	sub r2, #0x10
	strb r1, [r0, r2]
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
_0223A680:
	mov r0, #0x5f
	mov r3, #0
	add r4, sp, #0x30
	add r5, sp, #0x20
	lsl r0, r0, #2
_0223A68A:
	stmia r4!, {r3}
	ldr r2, [r1, r0]
	add r3, r3, #1
	add r1, r1, #4
	stmia r5!, {r2}
	cmp r3, #4
	blt _0223A68A
	bl sub_0203769C
	str r0, [sp, #0x10]
	bl sub_02037454
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	sub r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #0
	ble _0223A70A
	add r0, sp, #0x30
	add r2, sp, #0x20
	str r0, [sp, #8]
	str r2, [sp, #0x18]
	mov ip, r0
_0223A6BC:
	ldr r0, [sp, #4]
	add r5, r0, #1
	ldr r0, [sp, #0xc]
	cmp r5, r0
	bge _0223A6F6
	ldr r1, [sp, #0x18]
	lsl r0, r5, #2
	add r3, r1, r0
	mov r1, ip
	add r4, r1, r0
_0223A6D0:
	ldr r0, [r3]
	ldr r7, [r2]
	str r0, [sp, #0x1c]
	cmp r7, r0
	bge _0223A6EA
	ldr r0, [sp, #8]
	ldr r1, [r4]
	ldr r6, [r0]
	str r1, [r0]
	ldr r0, [sp, #0x1c]
	str r6, [r4]
	str r0, [r2]
	str r7, [r3]
_0223A6EA:
	ldr r0, [sp, #0xc]
	add r5, r5, #1
	add r3, r3, #4
	add r4, r4, #4
	cmp r5, r0
	blt _0223A6D0
_0223A6F6:
	ldr r0, [sp, #8]
	add r2, r2, #4
	add r0, r0, #4
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r1, r0, #1
	ldr r0, [sp, #0x14]
	str r1, [sp, #4]
	cmp r1, r0
	blt _0223A6BC
_0223A70A:
	ldr r1, [sp, #0x30]
	ldr r0, [sp, #0x10]
	cmp r1, r0
	bne _0223A71E
	ldr r0, [sp]
	ldr r1, _0223A79C ; =0x000023FC
	mov r2, #1
	strb r2, [r0, r1]
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
_0223A71E:
	ldr r0, [sp]
	ldr r1, [r0, #0x2c]
	mov r0, #0x80
	tst r0, r1
	bne _0223A792
	mov r0, #8
	tst r0, r1
	beq _0223A784
	ldr r0, [sp, #0x10]
	bl sub_020378AC
	add r4, r0, #0
	ldr r0, [sp, #0x30]
	bl sub_020378AC
	cmp r0, #3
	bhi _0223A792
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223A74C: ; jump table
	.short _0223A754 - _0223A74C - 2 ; case 0
	.short _0223A76C - _0223A74C - 2 ; case 1
	.short _0223A754 - _0223A74C - 2 ; case 2
	.short _0223A76C - _0223A74C - 2 ; case 3
_0223A754:
	mov r0, #1
	tst r0, r4
	beq _0223A792
	ldr r1, _0223A798 ; =0x0000240C
	ldr r0, [sp]
	ldr r2, [r0, r1]
	mov r0, #0x20
	orr r2, r0
	ldr r0, [sp]
	add sp, #0x40
	str r2, [r0, r1]
	pop {r3, r4, r5, r6, r7, pc}
_0223A76C:
	mov r0, #1
	tst r0, r4
	bne _0223A792
	ldr r1, _0223A798 ; =0x0000240C
	ldr r0, [sp]
	ldr r2, [r0, r1]
	mov r0, #0x20
	orr r2, r0
	ldr r0, [sp]
	add sp, #0x40
	str r2, [r0, r1]
	pop {r3, r4, r5, r6, r7, pc}
_0223A784:
	ldr r1, _0223A798 ; =0x0000240C
	ldr r0, [sp]
	ldr r2, [r0, r1]
	mov r0, #0x20
	orr r2, r0
	ldr r0, [sp]
	str r2, [r0, r1]
_0223A792:
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223A798: .word 0x0000240C
_0223A79C: .word 0x000023FC
	thumb_func_end ov12_0223A664

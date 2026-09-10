#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_39_thumb.inc"
	.include "global.inc"

	.text
	.public _0222AB80
	.public ov39_02227088
	.public ov39_022271CC
	.public ov39_02227208
	.public ov39_022272EC
	.public ov39_022273B0
	.public ov39_02227420
	.public ov39_022274D4
	.public ov39_02227534
	.public ov39_02227590
	.public ov39_022275E8
	.public ov39_02227648
	.public ov39_02227778
	.public ov39_022278D4
	.public ov39_02227A5C
	.public ov39_02227B24
	.public ov39_02227B5C
	.public ov39_02227D5C
	.public ov39_02227DE4
	.public ov39_02227DEC
	.public ov39_02227E8C
	.public ov39_02227F14
	.public ov39_02227FEC
	.public ov39_0222801C
	.public ov39_022280D4
	.public ov39_02228140
	.public ov39_02228308
	.public ov39_02228370
	.public ov39_02228418
	.public ov39_02228440
	.public ov39_022285CC
	.public ov39_022287F8
	.public ov39_022288A0
	.public ov39_02228964
	.public ov39_0222899C
	.public ov39_022289D0
	.public ov39_02228A34
	.public ov39_02228AC0
	.public ov39_02228B04
	.public ov39_02228BAC
	.public ov39_02228C78
	.public ov39_02228D0C
	.public ov39_02228DA0
	.public ov39_02228E54
	.public ov39_02228EC8
	.public ov39_02228F18
	.public ov39_02228F54
	.public ov39_02228FC8
	.public ov39_022290A4
	.public ov39_0222915C
	.public ov39_02229224
	.public ov39_0222A8B0
	.public ov39_0222A8B4
	.public ov39_0222A8C0
	.public ov39_0222A8D4
	.public ov39_0222A8E4
	.public ov39_0222A90C
	.public ov39_0222A944
	.public ov39_0222AA20
	.public ov39_02227060
	.public ov39_02227080
	.public ov39_02227188
	.public ov39_022271A4
	.public ov39_022271C0
	.public ov39_02227334
	.public ov39_02227348
	.public ov39_02227364
	.public ov39_0222738C
	.public ov39_022273F8
	.public ov39_0222748C
	.public ov39_022274B4
	.public ov39_022276A4
	.public ov39_022276E0
	.public ov39_02227720
	.public ov39_0222774C
	.public ov39_02227B1C
	.public ov39_02227B20
	.public ov39_02227B50
	.public ov39_02227B54
	.public ov39_02227B58
	.public ov39_02227D44
	.public ov39_02227D50
	.public ov39_02227DB8
	.public ov39_02227E3C
	.public ov39_02227E48
	.public ov39_02227E6C
	.public ov39_02227ECC
	.public ov39_02227EF4
	.public ov39_02227F60
	.public ov39_02227F74
	.public ov39_02227F84
	.public ov39_02227FA8
	.public ov39_02227FC4
	.public ov39_02227FFC
	.public ov39_022280B4
	.public ov39_02228120
	.public ov39_022285A8
	.public ov39_02228948
	.public ov39_02228A70
	.public ov39_02228A8C
	.public ov39_02228AA8
	.public ov39_02228B6C
	.public ov39_02228B74
	.public ov39_02228D90
	.public ov39_02228EA4
	.public ov39_0222908C

	thumb_func_start ov39_0222801C
ov39_0222801C: ; 0x0222801C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r2, [sp, #8]
	str r0, [sp]
	str r1, [sp, #4]
	bl ov39_0222A2B4
	ldr r1, [r0, #4]
	add r4, r0, #4
	ldr r0, [sp, #8]
	str r1, [sp, #0xc]
	cmp r1, r0
	ble _0222803C
	str r0, [sp, #0xc]
	bl GF_AssertFail
_0222803C:
	ldr r0, [sp, #0xc]
	add r5, r4, #4
	mov r6, #0
	cmp r0, #0
	ble _02228096
	ldr r4, [sp, #4]
_02228048:
	add r2, r5, #0
	add r2, #0xc
	add r3, r2, #0
	str r2, [r4]
	add r3, #0xd8
	ldr r3, [r3]
	ldr r0, [r5, #8]
	mov ip, r3
	add r3, r2, #0
	add r3, #0xdc
	ldr r3, [r3]
	add r7, r0, #0
	eor r7, r3
	ldr r1, [r5, #4]
	mov r3, ip
	eor r3, r1
	orr r3, r7
	beq _0222808A
	add r3, r2, #0
	add r3, #0xd8
	str r1, [r3]
	add r2, #0xdc
	str r0, [r2]
	ldr r0, [sp]
	ldr r1, [r4]
	ldr r0, [r0]
	add r1, #0x80
	mov r2, #0x58
	bl SaveArray_CalcCRC16
	ldr r1, [r4]
	add r1, #0xe0
	strh r0, [r1]
_0222808A:
	ldr r0, [sp, #0xc]
	add r6, r6, #1
	add r5, #0xf0
	add r4, r4, #4
	cmp r6, r0
	blt _02228048
_02228096:
	ldr r0, [sp, #8]
	cmp r6, r0
	bge _022280AE
	ldr r0, [sp, #4]
	lsl r1, r6, #2
	add r2, r0, r1
	mov r1, #0
_022280A4:
	ldr r0, [sp, #8]
	add r6, r6, #1
	stmia r2!, {r1}
	cmp r6, r0
	blt _022280A4
_022280AE:
	ldr r0, [sp, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov39_0222801C

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

	thumb_func_start ov39_022280D4
ov39_022280D4: ; 0x022280D4
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r5, r1, #0
	bl ov39_0222A2B4
	add r4, r0, #0
	add r0, r4, #4
	add r0, #0xc
	str r0, [r5]
	add r0, r4, #4
	add r0, #0xe4
	ldr r1, [r0]
	add r0, r4, #4
	add r0, #0xe8
	ldr r3, [r4, #8]
	ldr r2, [r4, #0xc]
	ldr r0, [r0]
	eor r1, r3
	eor r0, r2
	orr r0, r1
	beq _0222811C
	add r0, r4, #4
	add r0, #0xe4
	str r3, [r0]
	add r0, r4, #4
	add r0, #0xe8
	str r2, [r0]
	ldr r1, [r5]
	ldr r0, [r6]
	add r1, #0x80
	mov r2, #0x58
	bl SaveArray_CalcCRC16
	ldr r1, [r5]
	add r1, #0xe0
	strh r0, [r1]
_0222811C:
	ldr r0, [r4, #8]
	pop {r4, r5, r6, pc}
	thumb_func_end ov39_022280D4
